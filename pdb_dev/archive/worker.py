#!/usr/bin/python3
# 
# Copyright 2017 University of Southern California
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#    http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
"""
Worker for archiving mmCIF files.
"""

import os
import stat
import subprocess
import json
from urllib.parse import urlparse
import sys
import traceback
import time
import shutil
import hashlib
import smtplib
import zipfile
from email.mime.text import MIMEText
import socket
from socket import gaierror, EAI_AGAIN

from deriva.core import PollingErmrestCatalog, HatracStore, urlquote
from deriva.core.utils import hash_utils as hu
from deriva.core.utils.core_utils import DEFAULT_CHUNK_SIZE

import re
import math
import mimetypes
from datetime import datetime as dt, timedelta, timezone

mail_footer = 'Do not reply to this message.  This is an automated message generated by the system, which does not receive email messages.'

"""
https://dev-aws.pdb-dev.org/ermrest/catalog/99/attribute/Vocab:System_Generated_File_Type/!Archive_Category::null::/Archive_Category,Name
https://dev-aws.pdb-dev.org/ermrest/catalog/99/attribute/A:=PDB:entry/Workflow_Status=REL/B:=PDB:Entry_Generated_File/File_Type=mmCIF/C:=left(A:RID)=(PDB:Entry_Latest_Archive:Entry)/Entry::null::;!B:File_URL=mmCIF_URL/$A/RID
"""

class ArchiveClient (object):
    """
    Network client for archiving mmCIF files.
    """
    def __init__(self, kwargs):
        self.scheme = 'https'
        self.host = kwargs.get("hostname")
        self.catalog_id = kwargs.get("catalog_id")
        self.archive_parent = kwargs.get("archive_parent")
        self.released_entry_dir = kwargs.get("released_entry_dir")
        self.holding_dir = kwargs.get("holding_dir")
        self.data_scratch = kwargs.get("data_scratch")
        self.credentials = kwargs.get("credentials")
        self.accession_code_mode = kwargs['accession_code_mode']
        self.hatrac_namespace = kwargs.get("hatrac_namespace")
        self.holding_namespace = kwargs.get("holding_namespace")
        self.released_structures = {}
        self.current_holdings = {}
        self.PDB_Archive_RID = None
        self.store = HatracStore(
            self.scheme, 
            self.host,
            self.credentials
        )
        self.catalog = PollingErmrestCatalog(
            self.scheme, 
            self.host,
            self.catalog_id,
            self.credentials
        )
        self.catalog.dcctx['cid'] = 'pipeline/archive'
        self.email = kwargs.get("email")
        self.logger = kwargs.get("logger")
        self.logger.debug('Client initialized.')

    """
    Send email notification
    """
    def sendMail(self, subject, text):
        if self.email['server'] and self.email['sender']:
            if self.host in ['dev.pdb-dev.org', 'dev-aws.pdb-dev.org']:
                subject = 'DEV {}'.format(subject)
            retry = 0
            ready = False
            receivers = self.email['receivers']
            while not ready:
                try:
                    msg = MIMEText('%s\n\n%s' % (text, self.email['footer']), 'plain')
                    msg['Subject'] = subject
                    msg['From'] = self.email['sender']
                    msg['To'] = receivers
                    s = smtplib.SMTP_SSL(self.email['server'], self.email['port'])
                    s.login(self.email['user'], self.email['password'])
                    s.sendmail(self.email['sender'], receivers.split(','), msg.as_string())
                    s.quit()
                    self.logger.debug(f'Sent email notification to {receivers}.')
                    ready = True
                except socket.gaierror as e:
                    if e.errno == socket.EAI_AGAIN:
                        time.sleep(100)
                        retry = retry + 1
                        ready = retry > 10
                    else:
                        ready = True
                    if ready:
                        et, ev, tb = sys.exc_info()
                        self.logger.error('got exception "%s"' % str(ev))
                        self.logger.error('%s' % ''.join(traceback.format_exception(et, ev, tb)))
                except:
                    et, ev, tb = sys.exc_info()
                    self.logger.error('got exception "%s"' % str(ev))
                    self.logger.error('%s' % ''.join(traceback.format_exception(et, ev, tb)))
                    ready = True

    """
    Rollback the database 
    """
    def rollbackArchive(self):
        try:
            """
            Delete the self.PDB_Archive_RID record
            """
            if self.PDB_Archive_RID != None:
                url = f'/entity/PDB:Entry_Latest_Archive/Entry={urlquote(self.PDB_Archive_RID)}'
                resp = self.catalog.delete(
                    url
                )
                resp.raise_for_status()
                self.logger.debug('SUCCEEDED deleted the rows for the URL "%s".' % (url)) 
           
                url = f'/entity/PDB:PDB_Archive/RID={urlquote(self.PDB_Archive_RID)}'
                resp = self.catalog.delete(
                    url
                )
                resp.raise_for_status()
                self.logger.debug('SUCCEEDED deleted the rows for the URL "%s".' % (url)) 
        except:
            et, ev, tb = sys.exc_info()
            self.logger.error('got exception "%s"' % str(ev))
            self.logger.error('%s' % ''.join(traceback.format_exception(et, ev, tb)))
            subject = 'PDB-Dev Error archiving files.'
            self.sendMail(subject, '%s\n' % (''.join(traceback.format_exception(et, ev, tb))))

    """
    Process Archiving Files 
    """
    def processArchive(self):
        try:
            """
            Get the the file types with Archive_Category
            """
            url = f'/attribute/Vocab:System_Generated_File_Type/!Archive_Category::null::/Archive_Category,Name'
            self.logger.debug(f'Query for the the file types with Archive_Category: "{url}"') 
            
            resp = self.catalog.get(url)
            resp.raise_for_status()
            rows = resp.json()
            self.archive_category = {}
            for row in rows:
                self.archive_category[row['Name']] = row['Archive_Category']
                
            """
            Get the archive directories and the associated file types
            """
            self.archive_dirs = []
            self.archive_file_types = []
            for k,v in self.archive_category.items():
                if v not in self.archive_dirs:
                   self.archive_dirs.append(v) 
                if k not in self.archive_file_types:
                   self.archive_file_types.append(k) 

            """
            Archive files
            """
            return_code = self.archiveFiles()
            if return_code != 0:
                self.rollbackArchive()
            return return_code
        except:
            et, ev, tb = sys.exc_info()
            self.logger.error('got exception "%s"' % str(ev))
            self.logger.error('%s' % ''.join(traceback.format_exception(et, ev, tb)))
            subject = 'PDB-Dev Error archiving files.'
            self.sendMail(subject, '%s\n' % (''.join(traceback.format_exception(et, ev, tb))))
            self.rollbackArchive()
           
            return 1

    """
    Archive files 
    """
    def archiveFiles(self):
        """
        Get the new entries to be released:
         - not released
         - or modified
        """
        rel_warnings = []
        hold_warnings = []
        
        url = '/attribute/A:=PDB:entry/Workflow_Status=REL/B:=PDB:Entry_Generated_File/File_Type=mmCIF/C:=left(A:RID)=(PDB:Entry_Latest_Archive:Entry)/Entry::null::;!B:File_URL=mmCIF_URL/$A/RID,id,Deposit_Date,Accession_Code'
        self.logger.debug(f'Query for entries to be archived: "{url}"') 
        
        resp = self.catalog.get(url)
        resp.raise_for_status()
        rows = resp.json()
        if len(rows) == 0:
            """
            No new entries to archive
            """
            return 0
        
        """
        Clean up the release and holding directories
        """
        try:
            shutil.rmtree(f'{self.archive_parent}/{self.released_entry_dir}')
        except:
            pass
        
        try:
            shutil.rmtree(f'{self.archive_parent}/{self.holding_dir}')
        except:
            pass

        self.submission_date = self.getArchiveDate()
        self.logger.debug(f'Submission Date: {self.submission_date}') 
        
        """
        Create the new entry in the PDB_Archive table
        """
        insert_row = {'Submission_Time': self.submission_date
                      }
        default_columns = [
            'Submitted_Entries',
            'Current_File_Holdings_Name',
            'Current_File_Holdings_URL',
            'Current_File_Holdings_Bytes',
            'Current_File_Holdings_MD5',
            'Released_Structures_LMD_Name',
            'Released_Structures_LMD_URL',
            'Released_Structures_LMD_Bytes',
            'Released_Structures_LMD_MD5',
            'Unreleased_Entries_Name',
            'Unreleased_Entries_URL',
            'Unreleased_Entries_Bytes',
            'Unreleased_Entries_MD5'
        ]
        res = self.insert_rows([insert_row], 'PDB_Archive',defaults=','.join(default_columns))
        self.PDB_Archive_RID = res['RID']
        
        inserted_rows = []
        updated_rows = []
        self.no_validation_rids = []
        self.released_records = []

        """
        Get the new released files
        """
        for row in rows:
            structure_id = row['id']
            rid = row['RID']
            """
            Get the associated Accession_Code record
            """
            url = f'/entity/PDB:entry/RID={urlquote(rid)}/PDB:Accession_Code'
            self.logger.debug(f'Query for the associated Accession_Code: "{url}"') 
            resp = self.catalog.get(url)
            resp.raise_for_status()
            accesion_code_rows = resp.json()
            if len(accesion_code_rows) != 1:
                subject = f'PDB-Dev {rid} Can not get the accession code record.'
                self.sendMail(subject, f'Found {len(accession_codes)} records.')
                return 1
            
            accesion_code_row = accesion_code_rows[0]
            hash = self.get_hash(accesion_code_row)
            entry_id = self.get_entry_id(accesion_code_row)
            
            self.released_structures[entry_id] = {}
                
            """
            Get the Entry_Generated_File
            """
            url = f'/attribute/PDB:entry/RID={urlquote(rid)}/PDB:Entry_Generated_File/File_Name,File_URL,File_MD5,File_Type,RMT'
            self.logger.debug(f'Query for the associated Entry_Generated_File: "{url}"') 
            resp = self.catalog.get(url)
            resp.raise_for_status()
            files_generated = resp.json()
            if len(files_generated) < 3:
                """
                We are in the REL status but the report validation was not run
                """
                self.no_validation_rids.append({"Accession_Code": row['Accession_Code'], "Deposit_Date": row['Deposit_Date']})
                #continue
            
            submitted_files = {}
            self.current_holdings[entry_id] = {}
            for archive_dir in self.archive_dirs:
                submitted_files[archive_dir] = []
                self.current_holdings[entry_id][archive_dir] = []

            self.released_records.append(accesion_code_row)
            for file_generated in files_generated:
                file_type = file_generated['File_Type']
                if file_type not in self.archive_file_types:
                    continue
                filename = file_generated['File_Name']
                file_url = file_generated['File_URL']
                
                submitted_files[self.archive_category[file_type]].append(f'{filename}.gz')
                if file_type == 'mmCIF':
                    if filename == f'{structure_id}.cif':
                        rel_warnings.append(rid)
                    else:
                        self.released_structures[entry_id]['File_URL'] = file_generated['File_URL']
                
                if rid not in rel_warnings:
                    """
                    Extract the file from hatrac
                    """
                    file_path,error_message = self.getHatracFile(filename, file_url, self.data_scratch)
    
                    """
                    Zip the file
                    """
                    self.generateReleasedZip(filename, hash, entry_id, file_type)

            url = f'/attribute/PDB:entry/RID={urlquote(rid)}/PDB:Entry_Latest_Archive/RID'
            self.logger.debug(f'Query for detecting if the record exists or not in the Entry_Latest_Archive table: "{url}"') 
            resp = self.catalog.get(url)
            resp.raise_for_status()
            latest_archive_record = resp.json()
            
            """
            Insert or update the record in the Entry_Latest_Archive table
            """    
            if len(latest_archive_record) == 0:
                """
                New entry
                """
                if rid not in rel_warnings:
                    inserted_rows.append(
                        {
                            'Entry': rid,
                            'mmCIF_URL': self.released_structures[entry_id]['File_URL'],
                            'Submission_Time': self.submission_date,
                            'Archive': self.PDB_Archive_RID,
                            'Submitted_Files': submitted_files
                        }
                )
            elif len(latest_archive_record) == 1:
                """
                Entry that was updated
                """
                updated_rows.append(
                    {
                        'mmCIF_URL': self.released_structures[entry_id]['File_URL'],
                        'Submission_Time': self.submission_date,
                        'Archive': self.PDB_Archive_RID,
                        'RID': latest_archive_record[0]['RID']
                    }
                )
        
        self.insert_or_update_rows(inserted_rows, updated_rows, 'Entry_Latest_Archive')
        
        """
        Generate the manifest files
        """
        self.generate_released_structures_LMD()
        self.generate_current_holdings()
        self.generate_unreleased_entries()
         
        """
        Store in hatrac the manifest files
        """
        submission_datetime = dt.strptime(self.submission_date, '%Y-%m-%d %H:%M:%S%z')
        year = submission_datetime.year
        submission_date = f'{submission_datetime.date()}'
        hatrac_namespace = f'/{self.hatrac_namespace}/{self.holding_namespace}/{year}/{submission_date}'
        input_dir = f'{self.archive_parent}/{self.getHoldingSubDirectory()}'
        file_name = 'current_holdings.json.gz'
        
        Current_File_Holdings_URL, Current_File_Holdings_Name, Current_File_Holdings_Bytes, Current_File_Holdings_MD5 = self.storeFileInHatrac(hatrac_namespace, file_name, input_dir)
        if Current_File_Holdings_URL == None:
            return 1
 
        file_name = 'released_structures_last_modified_dates.json.gz'
        
        Released_Structures_LMD_URL, Released_Structures_LMD_Name, Released_Structures_LMD_Bytes, Released_Structures_LMD_MD5 = self.storeFileInHatrac(hatrac_namespace, file_name, input_dir)
        if Released_Structures_LMD_URL == None:
            return 1
 
        file_name = 'unreleased_entries.json.gz'
        
        Unreleased_Entries_URL, Unreleased_Entries_Name, Unreleased_Entries_Bytes, Unreleased_Entries_MD5 = self.storeFileInHatrac(hatrac_namespace, file_name, input_dir)
        if Unreleased_Entries_URL == None:
            return 1
 
        """
        Update the PDB_Archive table
        """
        columns = [
            'Submitted_Entries',
            'Current_File_Holdings_Name',
            'Current_File_Holdings_URL',
            'Current_File_Holdings_Bytes',
            'Current_File_Holdings_MD5',
            'Released_Structures_LMD_Name',
            'Released_Structures_LMD_URL',
            'Released_Structures_LMD_Bytes',
            'Released_Structures_LMD_MD5',
            'Unreleased_Entries_Name',
            'Unreleased_Entries_URL',
            'Unreleased_Entries_Bytes',
            'Unreleased_Entries_MD5'
        ]
        rows = [
            {
            'RID': self.PDB_Archive_RID,
            'Submitted_Entries': len(inserted_rows)+len(updated_rows),
            'Current_File_Holdings_Name': Current_File_Holdings_Name,
            'Current_File_Holdings_URL': Current_File_Holdings_URL,
            'Current_File_Holdings_Bytes': Current_File_Holdings_Bytes,
            'Current_File_Holdings_MD5': Current_File_Holdings_MD5,
            'Released_Structures_LMD_Name': Released_Structures_LMD_Name,
            'Released_Structures_LMD_URL': Released_Structures_LMD_URL,
            'Released_Structures_LMD_Bytes': Released_Structures_LMD_Bytes,
            'Released_Structures_LMD_MD5': Released_Structures_LMD_MD5,
            'Unreleased_Entries_Name': Unreleased_Entries_Name,
            'Unreleased_Entries_URL': Unreleased_Entries_URL,
            'Unreleased_Entries_Bytes': Unreleased_Entries_Bytes,
            'Unreleased_Entries_MD5': Unreleased_Entries_MD5
            }
        ]
        self.update_rows(columns, rows, 'PDB_Archive')
        
        url = '/attribute/A:=PDB:entry/Workflow_Status=HOLD/B:=left(A:id)=(PDB:Entry_Generated_File:Structure_Id)/Structure_Id::null::/$A/RID'
        self.logger.debug(f'Query for unreleased entries w/o a system mmCIF generated file: "{url}"') 
        
        resp = self.catalog.get(url)
        resp.raise_for_status()
        rows = resp.json()
        for row in rows:
            hold_warnings.append(row['RID'])
        
        total_warning = len(hold_warnings) + len(rel_warnings)
        if total_warning > 0:
            subject_rids = []
            for rel_warning in rel_warnings:
                subject_rids.append(rel_warning)
                if len(subject_rids) >= 3:
                    break
            if len(subject_rids) < 3:
                for hold_warning in hold_warnings:
                    subject_rids.append(hold_warning)
                    if len(subject_rids) >= 3:
                        break
                    
            subject = f'PDB-Dev weekly archive warnings: {", ".join(subject_rids)}'
            if total_warning > 3:
                subject= f'{subject}, ...'
                rids = []
                for rel_warning in rel_warnings:
                    rids.append(f'{rel_warning}: REL') 
                for hold_warning in hold_warnings:
                    rids.append(f'{hold_warning}: HOLD') 
            newline_char = "\n"
            rids = f'{newline_char.join(rids)}'
            message_body = f'The following entries were not archived due to inconsistent filenames or missing system generated files:\n\n{rids}'
            self.sendMail(subject, message_body)

        return 0

    """
    Get the archive directory 
    """
    def getArchiveDirectory(self):
        return self.archive_parent
        
    """
    Get the file archive subdirectory 
    """
    def getFileArchiveSubDirectory(self, hash, entry_id, archive_category):
        archive_category_dir_names = {
          "mmcif" : "structures",
          "validation_report": "validation_reports"
        }   
        entry_dir = f'{self.released_entry_dir}/{hash}/{entry_id}/'
        return f'{entry_dir}{archive_category_dir_names[archive_category]}'
        
    """
    Get the holding subdirectory 
    """
    def getHoldingSubDirectory(self):
        return self.holding_dir
        
    """
    Get the archive date 
    """
    def getArchiveDate(self):
        """
        Get the closed Thursday
        """
        now = dt.now(timezone.utc)
        closest_thursday = now + timedelta(days=(3 - now.weekday())%7)
        weekday = now.weekday()
        if weekday == 3:
            """
            It is Thursday. Check the time.
            """
            hour = now.hour
            if hour >= 16:
                """
                The UTC time has passed 4PM. Get the Thursday of next week
                """
                closest_thursday += timedelta(days=7)
        closest_thursday=closest_thursday.replace(hour=16,minute=0,second=0,microsecond=0)
        return f'{closest_thursday}'
                
    """
    Extract the file from hatrac
    """
    def getHatracFile(self, filename, file_url, input_dir):
        try:
            error_message = None
            hatracFile = '{}/{}'.format(input_dir, filename)
            self.store.get_obj(file_url, destfilename=hatracFile)
            self.logger.debug('File "%s", %d bytes.' % (hatracFile, os.stat(hatracFile).st_size)) 
            return (hatracFile, error_message)
        except:
            et, ev, tb = sys.exc_info()
            self.logger.error('got unexpected exception "%s"' % str(ev))
            self.logger.error('%s' % ''.join(traceback.format_exception(et, ev, tb)))
            subject = 'PDB-Dev Error archiving files.'
            self.sendMail(subject, '%s\n' % ''.join(traceback.format_exception(et, ev, tb)))
            error_message = 'ERROR getHatracFile: "%s"' % str(ev)
            return (None,error_message)
        
    """
    Get the archive file directory
    """
    def getFileArchiveDirectory(self, hash, entry_id, file_type):
        entry_dir = f'{self.archive_parent}/{self.released_entry_dir}/{hash}/{entry_id}/{self.archive_category[file_type]}'
    
        return entry_dir

    """
    Get the PDB_Accession_Code
    """
    def get_hash(self, accesion_code_row):
        if self.accession_code_mode == 'PDB':
            """
            try:
                r = re.search(r'^pdb_(\w{4})$', accesion_code_row['Accesssion_Code'])
                h = r.group(1)[1:3]
            except:
                h = accesion_code_row['PDB_Accession_Code'][1:3]
            """
            h = accesion_code_row['PDB_Accession_Code'][1:3]
        else:
            h = '000'
        return h

    """
    Get the primary accession code
    """
    def get_entry_id(self, accesion_code_row):
        return accesion_code_row['PDB_Accession_Code'][-4:]

    """
    Generate the released zip file and move it to the archive directory
    """
    def generateReleasedZip(self, filename, hash, entry_id, file_type):
        currentDirectory=os.getcwd()
        os.chdir(self.data_scratch)
        zipfile.ZipFile(f'{filename}.gz', mode='w', compression=zipfile.ZIP_DEFLATED).write(filename)
        
        """
        Move the file to the archive directory
        """
        archiveDirectory = self.getFileArchiveDirectory(hash, entry_id, file_type)
        os.makedirs(archiveDirectory, exist_ok=True)
        shutil.move(f'{filename}.gz', archiveDirectory)
        os.remove(filename)
        os.chdir(currentDirectory)
        
        holding_key = self.archive_category[file_type]
        file_path = archiveDirectory[len(self.archive_parent):]
        self.current_holdings[entry_id][holding_key].append(f'{file_path}/{filename}.gz')

    """
    Generate the holding zip file 
    """
    def generateHoldingZip(self, filename):
        currentDirectory=os.getcwd()
        os.chdir(f'{self.archive_parent}/{self.getHoldingSubDirectory()}')
        zipfile.ZipFile(f'{filename}.gz', mode='w', compression=zipfile.ZIP_DEFLATED).write(filename)
        os.remove(filename)
        os.chdir(currentDirectory)

    """
    Insert a record
    """
    def insert_rows(self, rows, table, schema='PDB', defaults=None):
       url = f'/entity/{schema}:{table}'
       if defaults != None:
           url = f'{url}?defaults={defaults}'
       resp = self.catalog.post(
           url,
           json=rows
       )
       resp.raise_for_status()
       self.logger.debug('SUCCEEDED created in the table "%s" the rows "%s".' % (url, json.dumps(rows, indent=4))) 
       return resp.json()[0]

    """
    Update a record
    """
    def update_rows(self, columns, rows, table, schema='PDB'):
        columns = ','.join([urlquote(col) for col in columns])
        url = f'/attributegroup/{schema}:{table}/RID;{columns}'
        resp = self.catalog.put(
            url,
            json=rows
        )
        resp.raise_for_status()

    """
    Insert or update a record
    """
    def insert_or_update_rows(self, inserted_rows, updated_rows, table, schema='PDB'):
        if len(inserted_rows) > 0:
            """
            The records does not exist
            """
            self.insert_rows(inserted_rows, table, schema)
        if len(updated_rows) > 0:
            """
            The records exist. Update them.
            """
            self.update_rows(columns, updated_rows, table, schema)

    """
    Generate the released_structures_LMD file
    """
    def generate_released_structures_LMD(self):
        released_structures_LMD = {}
        for row in self.released_records:
            released_structures_LMD[row['Accession_Code']] = f'{self.submission_date}T00:00:00+00:00'
        
        """
        Write the released_structures_LMD file
        """
        os.makedirs(f'{self.archive_parent}/{self.getHoldingSubDirectory()}', exist_ok=True)
        with open(f'{self.archive_parent}/{self.getHoldingSubDirectory()}/released_structures_last_modified_dates.json', 'w') as outfile:
            json.dump(released_structures_LMD, outfile, indent=4)

        """
        zip the JSON file
        """
        self.generateHoldingZip('released_structures_last_modified_dates.json')
                
    """
    Generate the current_holdings file
    """
    def generate_current_holdings(self):
        """
        Write the generate_current_holdings file
        """
        os.makedirs(f'{self.archive_parent}/{self.getHoldingSubDirectory()}', exist_ok=True)
        with open(f'{self.archive_parent}/{self.getHoldingSubDirectory()}/current_holdings.json', 'w') as outfile:
            json.dump(self.current_holdings, outfile, indent=4)

        """
        zip the JSON file
        """
        self.generateHoldingZip('current_holdings.json')

    """
    Generate the released_structures_LMD file
    """
    def generate_unreleased_entries(self):
        url = '/attribute/A:=PDB:entry/Workflow_Status=HOLD/B:=PDB:Entry_Generated_File/$A/Accession_Code,Deposit_Date'
        self.logger.debug(f'Query for unreleased entries: "{url}"') 
        
        resp = self.catalog.get(url)
        resp.raise_for_status()
        rows = resp.json()
        unreleased_entries = {}
        for row in rows:
            unreleased_entries[row['Accession_Code']] = {'status_code': 'HOLD',
                                                         'deposit_date': row['Deposit_Date'],
                                                         'prerelease_sequence_available_flag': 'N'}
        
        """
        for row in self.no_validation_rids:
            unreleased_entries[row['Accession_Code']] = {'status_code': 'REL',
                                                         'deposit_date': row['Deposit_Date'],
                                                         'prerelease_sequence_available_flag': 'N'}
        """
        
        """
        Write the unreleased_entries file
        """
        os.makedirs(f'{self.archive_parent}/{self.getHoldingSubDirectory()}', exist_ok=True)
        with open(f'{self.archive_parent}/{self.getHoldingSubDirectory()}/unreleased_entries.json', 'w') as outfile:
            json.dump(unreleased_entries, outfile, indent=4)

        """
        zip the JSON file
        """
        self.generateHoldingZip('unreleased_entries.json')
                
    """
    Store the validation error file into hatrac
    """
    def storeFileInHatrac(self, hatrac_namespace, file_name, file_path):
        try:
            newFile = '{}/{}'.format(file_path, file_name)
            file_size = os.path.getsize(newFile)
            hashes = hu.compute_file_hashes(newFile, hashes=['md5', 'sha256'])
            new_md5 = hashes['md5'][1]
            new_sha256 = hashes['sha256'][1]
            hexa_md5 = hashes['md5'][0]
            new_uri = '{}/{}'.format(hatrac_namespace, urlquote(file_name))
            chunked = True if file_size > DEFAULT_CHUNK_SIZE else False
            
            """
            Store the file in hatrac if it is not already
            """
            hatrac_URI = None
            try:
                outfile = '{}.hatrac'.format(newFile)
                r = self.store.get_obj(new_uri, destfilename=outfile)
                hatrac_URI = r.headers['Content-Location']
                hashes = hu.compute_file_hashes(outfile, hashes=['md5', 'sha256'])
                old_hexa_md5 = hashes['md5'][0]
                os.remove(outfile)
            except:
                old_hexa_md5 = None
            
            if hatrac_URI != None and hexa_md5 == old_hexa_md5:
                self.logger.info('Skipping the upload of the file "%s" as it already exists hatrac.' % file_name)
            else:
                if mimetypes.inited == False:
                    mimetypes.init()
                content_type,encoding = mimetypes.guess_type(newFile)
                if content_type == None:
                    content_type = 'application/octet-stream'
                try:
                    hatrac_URI = self.store.put_loc(new_uri,
                                                         newFile,
                                                         headers={'Content-Type': content_type},
                                                         content_disposition = "filename*=UTF-8''%s" % urlquote(file_name),
                                                         md5 = new_md5,
                                                         sha256 = new_sha256,
                                                         content_type = content_type,
                                                         chunked = chunked
                                                       )
                except:
                    et, ev, tb = sys.exc_info()
                    self.logger.error('Can not upload file "%s" in hatrac "%s". Error: "%s"' % (file_name, new_uri, str(ev)))
                    self.logger.error('%s' % ''.join(traceback.format_exception(et, ev, tb)))
                    subject = 'PDB-Dev Error archiving files.'
                    self.sendMail(subject, 'Can not upload file "{}" in hatrac at location "{}":\n{}\n'.format(file_name, new_uri, ''.join(traceback.format_exception(et, ev, tb))))
                    return (None, None, None, None)
            return (hatrac_URI, file_name, file_size, hexa_md5)

        except:
            et, ev, tb = sys.exc_info()
            self.logger.error('got unexpected exception "%s"' % str(ev))
            self.logger.error('%s' % ''.join(traceback.format_exception(et, ev, tb)))
            subject = 'PDB-Dev Error archiving files.'
            self.sendMail(subject, 'Can not upload file "{}" in hatrac at location "{}":\n{}\n'.format(file_name, new_uri, ''.join(traceback.format_exception(et, ev, tb))))
            return (None, None, None, None)

"""
Examples of the manifest files

released_structures_last_modified_dates.json
{
    "PDBDEV_00000001" : "2024-04-30T00:00:00+00:00",
    "PDBDEV_00000002" : "2024-04-30T00:00:00+00:00",
    "PDBDEV_00000003" : "2024-04-30T00:00:00+00:00",
    "PDBDEV_00000004" : "2024-04-30T00:00:00+00:00",
    "PDBDEV_00000005" : "2024-04-30T00:00:00+00:00"
}

current_holdings.json
{
"PDBDEV_00000001" : {
    "mmcif": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000001/structures/PDBDEV_00000001.cif"
    ],
    "validation_report": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000001/validation_reports/PDBDEV_00000001_full_validation.pdf",
        "/pdb_ihm/data/entries/000/PDBDEV_00000001/validation_reports/PDBDEV_00000001_summary_validation.pdf"
    ]
},
"PDBDEV_00000002" : {
    "mmcif": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000002/structures/PDBDEV_00000002.cif"
    ],
    "validation_report": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000002/validation_reports/PDBDEV_00000002_full_validation.pdf",
        "/pdb_ihm/data/entries/000/PDBDEV_00000002/validation_reports/PDBDEV_00000002_summary_validation.pdf"
    ]
},
"PDBDEV_00000003" : {
    "mmcif": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000003/structures/PDBDEV_00000003.cif"
    ],
    "validation_report": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000003/validation_reports/PDBDEV_00000003_full_validation.pdf",
        "/pdb_ihm/data/entries/000/PDBDEV_00000003/validation_reports/PDBDEV_00000003_summary_validation.pdf"
    ]
},
"PDBDEV_00000004" : {
    "mmcif": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000004/structures/PDBDEV_00000004.cif"
    ],
    "validation_report": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000004/validation_reports/PDBDEV_00000004_full_validation.pdf",
        "/pdb_ihm/data/entries/000/PDBDEV_00000004/validation_reports/PDBDEV_00000004_summary_validation.pdf"
    ]
},
"PDBDEV_00000005" : {
    "mmcif": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000005/structures/PDBDEV_00000005.cif"
    ],
    "validation_report": [
        "/pdb_ihm/data/entries/000/PDBDEV_00000005/validation_reports/PDBDEV_00000005_full_validation.pdf",
        "/pdb_ihm/data/entries/000/PDBDEV_00000005/validation_reports/PDBDEV_00000005_summary_validation.pdf"
    ]
}
}

unreleased_entries.json
{
"PDBDEV_00000367" : {
    "status_code" : "HOLD",
    "deposit_date" : "2024-01-22T00:00:00+00:00",
    "prerelease_sequence_available_flag" : "N"
},
"PDBDEV_00000368" : {
    "status_code" : "HOLD",
    "deposit_date" : "2024-02-05T00:00:00+00:00",
    "prerelease_sequence_available_flag" : "N"
},
"PDBDEV_00000377" : {
    "status_code" : "HOLD",
    "deposit_date" : "2024-03-12T00:00:00+00:00",
    "prerelease_sequence_available_flag" : "N"
},
"PDBDEV_00000378" : {
    "status_code" : "HOLD",
    "deposit_date" : "2024-02-02T00:00:00+00:00",
    "prerelease_sequence_available_flag" : "N"
},
"PDBDEV_00000379" : {
    "status_code" : "HOLD",
    "deposit_date" : "2024-02-02T00:00:00+00:00",
    "prerelease_sequence_available_flag" : "N"
}
}

"""
       