#!/usr/bin/python3

import json
import python_jsonschema_objects as pjs
import deriva.core.ermrest_model as em
from collections import namedtuple
from deriva.core import ErmrestCatalog, get_credential, DerivaServer
from deriva.utils.catalog.components.configure_catalog import DerivaCatalogConfigure, DerivaTableConfigure
import deriva.utils.catalog.components.model_elements as model_elements
from deriva.core.ermrest_config import tag as chaise_tags
from requests import HTTPError
import csv
import pickle
import argparse
import sys
import traceback

parser = argparse.ArgumentParser()
parser.add_argument('hostname')
parser.add_argument('catalog_number')
parser.add_argument('schema_name')
parser.add_argument('term_schema_name')
parser.add_argument('filename')
parser.add_argument('pickle_file')
parser.add_argument('actions')
args = parser.parse_args()

filename = args.filename
hostname = args.hostname
schema_name = args.schema_name
term_schema_name = args.term_schema_name
catalog_number = args.catalog_number
pickle_file = args.pickle_file

print ('hostname: {}'.format(hostname))
print ('catalog_number: {}'.format(catalog_number))
print ('schema_name: {}'.format(schema_name))
print ('term_schema_name: {}'.format(term_schema_name))
print ('filename: {}'.format(filename))
print ('pickle_file: {}'.format(pickle_file))
print ('actions: {}'.format(args.actions))

# Read JSON data into the datastore variable
with open(filename, 'r') as f:
    pdb = json.load(f)

flag_CreateVocab = False
flag_CreateTable = False
flag_CreateFkeys = False
flag_CreateCompositeFkeys = False
flag_AnnotateTable_VisibleColumn = False
flag_Annotations_Config = False
flag_AnnotateTable_RowName = False
flag_VocabTable_VisibleColumn = False
skip_ExistTable = False
skip_PickleVob = False

actions = args.actions.split(',')

if 'CreateVocab' in actions:
	flag_CreateVocab = True
if 'CreateTable' in actions:
	flag_CreateTable = True
if 'CreateFkeys' in actions:
	flag_CreateFkeys = True
if 'CreateCompositeFkeys' in actions:
	flag_CreateCompositeFkeys = True
if 'AnnotateTable_VisibleColumn' in actions:
    flag_AnnotateTable_VisibleColumn = True
if 'AnnotationsConfig' in actions:
    flag_Annotations_Config = True
if 'VocabTable_VisibleColumn' in actions:
	flag_VocabTable_VisibleColumn = True
if 'AnnotateTable_RowName' in actions:
	flag_AnnotateTable_RowName = True
if 'ExistTable' in actions:
	skip_ExistTable = True
if 'PickleVob' in actions:
	skip_PickleVob = True

"""
print('flag_CreateVocab: %s' % flag_CreateVocab)
print('flag_CreateTable: %s' % flag_CreateTable)
print('flag_CreateFkeys: %s' % flag_CreateFkeys)
print('flag_CreateCompositeFkeys: %s' % flag_CreateCompositeFkeys)
print('flag_AnnotateTable_VisibleColumn: %s' % flag_AnnotateTable_VisibleColumn)
print('flag_Annotations_Config: %s' % flag_Annotations_Config)
print('flag_VocabTable_VisibleColumn: %s' % flag_VocabTable_VisibleColumn)
print('flag_AnnotateTable_RowName: %s' % flag_AnnotateTable_RowName)
print('skip_ExistTable: %s' % skip_ExistTable)
print('skip_PickleVob: %s' % skip_PickleVob)
"""

row_name_list = [
    ('entry', 'id'),
    ('ihm_model_list', 'model_id'),
    ('struct_asym', 'id'),
    ('chem_comp', 'id'),
    ('entity', 'id'),
    ('atom_type', 'symbol'),
    ('citation', 'id'),
    ('entity_poly', 'entity_id'),
    ('ihm_2dem_class_average_restraint', 'id'),
    ('ihm_dataset_list', 'id'),
    ('ihm_struct_assembly', 'id'),
    ('ihm_cross_link_list', 'id'),
    ('ihm_ensemble_info', 'ensemble_id'),
    ('ihm_cross_link_restraint', 'id'),
    ('ihm_external_files', 'id'),
    ('ihm_dataset_group', 'id'),
    ('ihm_feature_list', 'feature_id'),
    ('ihm_model_group', 'id'),
    ('ihm_modeling_post_process', 'id'),
    ('ihm_external_reference_info', 'reference_id'),
    ('ihm_geometric_object_list', 'object_id'),
    ('ihm_geometric_object_transformation', 'id'),
    ('ihm_geometric_object_torus', 'object_id'),
    ('ihm_geometric_object_center', 'id'),
    ('software', 'pdbx_ordinal'),
    ('ihm_entity_poly_segment', 'id'),
    ('ihm_modeling_protocol', 'id'),
    ('ihm_model_representation', 'id'),
    ('ihm_starting_model_details', 'starting_model_id'),
    ('ihm_multi_state_modeling', 'state_id'),
    ('ihm_struct_assembly_class', 'id')
]

def table_schema(v):
    # A table will be represented as a array whose single item must be an object whose properties are the columns.
    return v['type'] == 'array' or v['type'] == 'object'
    # return v['type'] == 'array' and v["minItems"] == 1 and v["uniqueItems"] == True


FKey = namedtuple('fkey', ['column', 'reftable', 'refcolumn'])


def maptype(t):
    m = {'string': 'text',
         'integer': 'int4',
         'number': 'float4'
         }
    return m[t]


def nullOK(t):
    if t['type'] == 'object':
        return t['required']
    elif t['type'] == 'array':
        return t['items']['required']


def refertype(v):
    refer_column = v.get('$ref', '')
    if not refer_column or refer_column[0] != '#' or '/' not in refer_column:
        return None
    else:
        pair = refer_column[1:].split('/')
        refer_tab = pair[0]
        refer_col = pair[1]

        if pdb['properties'][refer_tab]['type'] == 'object':
            parent_col = pdb['properties'][refer_tab]['properties'][refer_col]
        elif pdb['properties'][refer_tab]['type'] == 'array':
            parent_col = pdb['properties'][refer_tab]['items']['properties'][refer_col]

        if '$ref' in parent_col.keys():
            return refertype(parent_col)
        return maptype(parent_col['type'])

def referRootColumn(table_name,col_name,v,column_desc_dict):
    if '$ref' not in v.keys():
        return (table_name, col_name)
    refer_column = v.get('$ref', '')
    if refer_column[0] != '#' or '/' not in refer_column:
        return None
    else:
        pair = refer_column[1:].split('/')
        refer_tab = pair[0]
        refer_col = pair[1]

        if pdb['properties'][refer_tab]['type'] == 'object':
            parent_col = pdb['properties'][refer_tab]['properties'][refer_col]
        elif pdb['properties'][refer_tab]['type'] == 'array':
            parent_col = pdb['properties'][refer_tab]['items']['properties'][refer_col]

        return referRootColumn(refer_tab,refer_col,parent_col,column_desc_dict)




def referTable(v):
    refer_column = v.get('$ref', '')
    if not refer_column or refer_column[0] != '#' or '/' not in refer_column:
        return None, None
    else:
        pair = refer_column[1:].split('/')
        refer_tab = pair[0]
        refer_col = pair[1]
        return refer_tab, refer_col


def createKey(catalog_ermrest, schema_name, tname, col_list, kname):
    model = catalog_ermrest.getCatalogModel()
    key = em.Key.define(
        col_list,
        constraint_names=[[schema_name, kname]],
        annotations={},
    )
    table = model.table(schema_name, tname)
    table.create_key(catalog_ermrest, key)


def getFkeyColumn(catalog_ermrest, schema_name, table_name, column_name, fkey_name):
    model_root = catalog_ermrest.getCatalogModel()
    comment = ''
    try:
    	comment = model_root.column(schema_name, table_name, column_name).comment
    except:
    	pass

    res = dict()
    res.update(
    {"markdown_name": column_name.replace('_',' '),
     "comment": comment,
     "source": [
        {
            "outbound": [
                schema_name,
                fkey_name
            ]
        },
        "RID"
             ]
           })
    return res

def getColumnDesc():
    if not pdb:
        return None
    res = {}
    for tname, t in pdb['properties'].items():
        if tname in ['_entry_id', '_schema_version']:
            continue
        elif t['type'] == 'object':
            columns = t['properties']
        elif t['type'] == 'array':
            columns = t['items']['properties']

        for k, v in columns.items():
            if 'description' in v.keys():
                res[(tname,k)] = v['description']
    return res




class Table():
    def __init__(self, name, dict):
        self.columns = []
        self.fkeys = []
        self.pkey_columns = []
        self.vocab = {}

        # A table will be represented as a array whose single item must be an object whose properties are the columns.
        self.name = name

        assert (dict['type'] == 'array' or dict['type'] == 'object')
        # assert (dict['items']['type'] == 'object')

        if dict['type'] == 'object':
            columns = dict['properties']
        elif dict['type'] == 'array':
            columns = dict['items']['properties']

        for k, v in columns.items():
            try:
                column_type = maptype(v['type']) if 'type' in v.keys() else refertype(v)
            except:
                print ('k={}, v={}'.format(k,v))
                print ('v.keys(): {}'.format(v.keys()))
                et, ev, tb = sys.exc_info()
                print('got exception "%s"' % str(ev))
                print('%s' % str(traceback.format_exception(et, ev, tb)))
                sys.exit(1)
                
            if 'examples' in v.keys():
                example_info = ','.join(v['examples'])
            else:
                example_info = ''

            hasDescription = False
            if 'description' in v.keys():
                comment_str = v['description']
                hasDescription = True
            else:
                tab_col_key = referRootColumn(name,k,v,column_des_dict)
                if tab_col_key:
                    #comment_str = column_des_dict.get(tab_col_key,'')
                    table_name, col_name = tab_col_key
                    comment_str = 'A reference to table %s.%s.' % (table_name, col_name)
                else:
                    comment_str = ''
            if not comment_str or comment_str == '':
                print('missing description {}:{}'.format(name,k))
            elif hasDescription == True:
                comment_str = 'type:{}\n{}'.format(column_type,comment_str)

            if example_info:
                comment_str = '{}\nexamples:{}'.format(comment_str, example_info)

            #comment_str = comment_str.replace('\n', '</br>')
            self.columns.append(
                {
                    'name': k,
                    'type': column_type,
                    'nullok': k not in nullOK(dict),
                    'comment': comment_str,
                }
            )
            if 'enum' in v:
                self.vocab[(self.name, k)] = set(v['enum'])
                vocab_table_name = '{}_{}_term'.format(self.name, k)
                # limit of 63,
                vocab_table_name = vocab_table_name[-50:]
                if v['type'] == 'integer':
                    # if enum is integer type, skip it for now
                    pass
                else:
                    self.fkeys.append(FKey(k, vocab_table_name, 'ID'))
            if '_primary_key' in v:
                self.pkey_columns.extend([k])

        if 'structure_id' not in columns.keys():
            print('Table %s has not the column structure_id as a key.' % self.name)
            self.columns.append(
                {
                    'name': 'structure_id',
                    'type': 'text',
                    'nullok': False,
                    'comment': 'unique id for each entry in database',
                }
            )


column_des_dict = getColumnDesc()
tables = {k: Table(k, v) for k, v in pdb['properties'].items() if table_schema(v)}
print ('The Table class was created successfully')

def getVocabTables():
    vocab_tables = 0

    for tname, t in tables.items():
        if tname in ['_entry_id', '_schema_version']:
            continue
        elif t.vocab:
            for vocab_k, vocab_v in t.vocab.items():
                vocab_tables = vocab_tables + 1
    return vocab_tables

def getColumns():
    columns_number = 0

    for tname, t in tables.items():
        if tname in ['_entry_id', '_schema_version']:
            continue
        elif not t.vocab:
            columns_number = columns_number + len(t.columns)
    return columns_number

def getVocabTerms():
    vocab_terms = 0

    for tname, t in tables.items():
        if tname in ['_entry_id', '_schema_version']:
            continue
        elif t.vocab:
            for vocab_k, vocab_v in t.vocab.items():
                vocab_terms = vocab_terms + len(vocab_v)
    return vocab_terms

print('Total number of tables: %d' % (len(tables)))
print('Total number of columns: %d' % (getColumns()))
print('Total number of vocabulary tables: %d' % (getVocabTables()))
print('Total number of vocabulary terms: %d' % (getVocabTerms()))

if not skip_PickleVob:
    vocab_list = []
    for tname, t in tables.items():
        if t.vocab:
            vocab_list.append(t.vocab)
    with open(pickle_file, 'wb') as f:
        pickle.dump(vocab_list, f)
else:
    print ('Skipping generating the pickle')

credential = get_credential(hostname)
catalog_ermrest = ErmrestCatalog('https', hostname, catalog_number, credentials=credential)

catalog = model_elements.DerivaCatalog(catalog_ermrest)
pb = catalog.getPathBuilder()

if schema_name not in catalog.model.schemas.keys():
    schema = catalog.create_schema(schema_name, comment=pdb['title'])
else:
    schema = catalog.model.schemas[schema_name]

model = catalog_ermrest.getCatalogModel()

if flag_AnnotateTable_RowName:
    # row_name_list = [('chem_comp', 'id')]

    model_root = catalog_ermrest.getCatalogModel()
    for p_table, p_column in row_name_list:
        print(p_table)
        tab = model_root.schemas[schema_name].tables[p_table]
        tab.annotations.update({
            chaise_tags.table_display: {'row_name': {"row_markdown_pattern": "{{{" + p_column + "}}}"}}
        })
        #tab.apply(catalog_ermrest)
        model_root.apply(catalog_ermrest)


 #1. configure domain_filter_pattern
# 2. run flag_AnnotateTable_VisibleColumn
# 3. run flag_AnnotateTable_RowName
# 4. run configure_table.py
if flag_AnnotateTable_VisibleColumn:
    for tname, t in pdb['properties'].items():
        # these table has wrong foreign key definitions, skip them for now
        if tname in ['_entry_id', '_schema_version', 'pdbx_nonpoly_scheme', 'pdbx_unobs_or_zero_occ_atoms',
                     'pdbx_unobs_or_zero_occ_residues']:
            continue
        elif tname in ['ihm_cross_link_list','ihm_cross_link_restraint','ihm_entity_poly_segment']:
            continue
        # elif tname not in ['entity_poly_seq']:
        #     continue
        # elif tname <'ihm_feature_list':
        #     continue
        elif t['type'] == 'object':
            columns = t['properties']
        elif t['type'] == 'array':
            columns = t['items']['properties']

        visible_columns_entry = []
        visible_columns_other = []
        print(tname)

        # the single column fkey case
        for k, v in columns.items():
            if k == 'structure_id' or '$ref' in v.keys():
                # visible_columns_entry.append([schema_name, "{}_{}_fkey".format(tname, k)])
                visible_columns_entry.append(getFkeyColumn(catalog_ermrest,schema_name,tname,k, "{}_{}_fkey".format(tname, k)))
            elif 'enum' in v.keys():
                # handling length limit
                fk_name = "{}_{}_term".format(tname, k)[-50:]
                fk_name = "{}_fkey".format(fk_name)[-63:]
                visible_columns_entry.append([schema_name, fk_name])
            else:
                visible_columns_entry.append(k)

        visible_columns_other = [c for c in visible_columns_entry]
        visible_columns_other.insert(0, 'RID')
        visible_columns_other.append([schema_name, "{}_RCB_fkey".format(tname)])
        visible_columns_other.append([schema_name, "{}_RMB_fkey".format(tname)])
        visible_columns_other.append("RCT")
        visible_columns_other.append("RMT")
        visible_columns_other.append([schema_name, "{}_Owner_fkey".format(tname)])


        model_root = catalog_ermrest.getCatalogModel()
        tab = model_root.schemas[schema_name].tables[tname]
        # tt = tab.annotations[chaise_tags.visible_columns]['*']
        tab.annotations.update({
            chaise_tags.visible_columns: {'entry': visible_columns_entry, '*': visible_columns_other}
        })

        #tab.apply(catalog_ermrest)
        model_root.apply(catalog_ermrest)

if flag_Annotations_Config:
    annotation_config = []
    for tname, t in pdb['properties'].items():
        # these table has wrong foreign key definitions, skip them for now
        if tname in ['_entry_id', '_schema_version', 'pdbx_nonpoly_scheme', 'pdbx_unobs_or_zero_occ_atoms',
                     'pdbx_unobs_or_zero_occ_residues']:
            continue
        elif tname in ['ihm_cross_link_list','ihm_cross_link_restraint','ihm_entity_poly_segment']:
            continue
        # elif tname not in ['entity_poly_seq']:
        #     continue
        # elif tname <'ihm_feature_list':
        #     continue
        elif t['type'] == 'object':
            columns = t['properties']
        elif t['type'] == 'array':
            columns = t['items']['properties']

        visible_columns_entry = []
        visible_columns_other = []
        print(tname)

        # the single column fkey case
        for k, v in columns.items():
            if k == 'structure_id' or '$ref' in v.keys():
                # visible_columns_entry.append([schema_name, "{}_{}_fkey".format(tname, k)])
                visible_column = getFkeyColumn(catalog_ermrest,schema_name,tname,k, "{}_{}_fkey".format(tname, k))
                del visible_column['comment']
                visible_columns_entry.append(visible_column)
            elif 'enum' in v.keys():
                # handling length limit
                fk_name = "{}_{}_term".format(tname, k)[-50:]
                fk_name = "{}_fkey".format(fk_name)[-63:]
                visible_columns_entry.append([schema_name, fk_name])
            else:
                visible_columns_entry.append({'source': k})

        visible_columns_other = [c for c in visible_columns_entry]
        visible_columns_other.insert(0, {'source': 'RID'})
        #visible_columns_other.append([schema_name, "{}_RCB_fkey".format(tname)])
        #visible_columns_other.append([schema_name, "{}_RMB_fkey".format(tname)])
        #visible_columns_other.append({'source': 'RCT'})
        #visible_columns_other.append({'source': 'RMT'})
        visible_columns_other.append([schema_name, "{}_Owner_fkey".format(tname)])

        annotation_config.append({'schema': '%s' % schema_name,
                                    'table': '%s' % tname,
                                    'uri' : 'tag:isrd.isi.edu,2016:visible-columns',
                                    'value' : {'entry': visible_columns_entry, 
                                               '*': visible_columns_other
                                               }
                                    })
    model_root = catalog_ermrest.getCatalogModel()
    for tname in model_root.schemas[term_schema_name].tables:
        visible_columns_other = [{'source': 'RID'},{'source': 'Name'},{'source': 'Description'},{'source': 'ID'},{'source': 'URI'}]
        #visible_columns_other.append([term_schema_name, "{}_RCB_fkey".format(tname)])
        #visible_columns_other.append([term_schema_name, "{}_RMB_fkey".format(tname)])
        #visible_columns_other.append({'source': 'RCT'})
        #visible_columns_other.append({'source': 'RMT'})
        visible_columns_other.append([term_schema_name, "{}_Owner_fkey".format(tname)])
        annotation_config.append({'schema': '%s' % term_schema_name,
                                    'table': '%s' % tname,
                                    'uri' : 'tag:isrd.isi.edu,2016:visible-columns',
                                    'value' : {'*': visible_columns_other
                                               }
                                    })
    for p_table, p_column in row_name_list:
        annotation_config.append({'schema': '%s' % schema_name,
                                    'table': '%s' % p_table,
                                    'uri' : 'tag:isrd.isi.edu,2016:table-display',
                                    'value' : {'row_name': {"row_markdown_pattern": "{{{" + p_column + "}}}"}}
                                    })
        
    fp = open('visible_columns.json', 'w')
    json.dump(annotation_config, fp, indent=4)
    fp.close()

if flag_CreateVocab:
    for tname, t in tables.items():
        if tname in ['_entry_id', '_schema_version']:
            continue
        elif t.vocab:
            for vocab_k, vocab_v in t.vocab.items():
                vocab_table_name = '{}_{}_term'.format(vocab_k[0], vocab_k[1])
                vocab_table_name = vocab_table_name[-50:]
                if vocab_table_name not in pb.schemas[term_schema_name].tables:
                    model.schemas[term_schema_name].create_table(catalog_ermrest,
                                                                 em.Table.define_vocabulary(vocab_table_name,
                                                                                            'PDB:{RID}'))
                    print('{} created'.format(vocab_table_name))
                    catalog_ermrest = ErmrestCatalog('https', hostname, catalog_number, credentials=credential)
                    catalog = model_elements.DerivaCatalog(catalog_ermrest)
                    term_table = DerivaTableConfigure(catalog, term_schema_name, vocab_table_name)
                    term_table.configure_table_defaults()
                else:
                    print('{} already exist'.format(vocab_table_name))
                    pass
                pb = catalog.getPathBuilder()
                vocab_Table = pb.schemas[term_schema_name].tables[vocab_table_name]
                entities = vocab_Table.path.entities()
                if len(entities) > 0:
                    vocab_Table.path.delete()
                entities = []
                for term_item in vocab_v:
                    entities.append(
                        {'Name': term_item, "ID": "PDB:{RID}", "URI": "/id/{RID}", "Description": term_item})
                try:
                    vocab_Table.insert(entities)
                except HTTPError as e:
                    print(e)
                    print(e.response.text)
                    exit(1)
        else:
            pass

if flag_CreateTable:
    for tname, t in tables.items():
        if tname in ['_entry_id', '_schema_version']:
            continue
        # elif tname not in ['chem_comp']:
        #     continue
        elif tname in pb.schemas[schema_name].tables and skip_ExistTable:
            continue
        elif tname in pb.schemas[schema_name].tables and not skip_ExistTable:
            model_root = catalog_ermrest.getCatalogModel()
            tab = model_root.schemas[schema_name].tables[tname]
            tab.delete(catalog_ermrest)
            print('table deleted:', tab)

        print(t.fkeys)
        catalog = model_elements.DerivaCatalog(catalog_ermrest)
        schema = catalog.model.schemas[schema_name]

        table = schema.create_table(catalog_ermrest, em.Table.define(tname,
                                                                     [em.Column.define(c['name'],
                                                                                       em.builtin_types[c['type']],
                                                                                       nullok=c['nullok'],
                                                                                       comment=c['comment']
                                                                                       ) for c in t.columns],
                                                                     key_defs=[em.Key.define(t.pkey_columns,
                                                                                             constraint_names=[
                                                                                                 [schema_name,
                                                                                                  "{}_primary_key".format(
                                                                                                      tname)]])],
                                                                     fkey_defs=[
                                                                         em.ForeignKey.define(
                                                                             [fk.column],
                                                                             term_schema_name,
                                                                             fk.reftable,
                                                                             [fk.refcolumn],
                                                                             on_update='CASCADE',
                                                                             on_delete='SET NULL',
                                                                             constraint_names=[[schema_name,
                                                                                                "{}_fkey".format(
                                                                                                    fk.reftable)[
                                                                                                -63:]]],
                                                                         ) for fk in t.fkeys
                                                                     ]
                                                                     ))
        print(" table {} created.".format(tname))

        table = DerivaTableConfigure(catalog, schema_name, tname)
        table.configure_table_defaults()
    createKey(catalog_ermrest, schema_name, 'entry', ["id"], 'entry_id_unique_key')

if flag_CreateFkeys:
    # Create FKs
    for tname, t in pdb['properties'].items():
        print(tname)
        if tname in ['_entry_id', '_schema_version', 'pdbx_nonpoly_scheme', 'pdbx_unobs_or_zero_occ_atoms',
                     'pdbx_unobs_or_zero_occ_residues']:
            continue
        elif t['type'] == 'object':
            columns = t['properties']
        elif t['type'] == 'array':
            columns = t['items']['properties']

        # the single column fkey case
        for k, v in columns.items():
            print(tname, k, v)
            if 'type' in v.keys():
                print('type in v.keys()')
                continue
            elif '$ref' in v.keys():
                parent_table, parent_column = referTable(v)
                # key_name = "{}_{}_key".format(parent_table, parent_column)
                if parent_table in ['entity_poly_seq']:  # not the composite fkey case
                    continue
                table = model.table(schema_name, tname)
                fk_name = "{}_{}_fkey".format(tname, k)

                if (schema_name, fk_name) in table.foreign_keys.elements.keys():
                    continue
                model = catalog_ermrest.getCatalogModel()
                if k == 'structure_id':
                    fk = em.ForeignKey.define([k]
                                              , schema_name
                                              , parent_table
                                              , [parent_column]
                                              , on_update='CASCADE',
                                              on_delete='SET NULL',
                                              constraint_names=[
                                                  [schema_name, fk_name]],
                                              )
                else:
                    fk = em.ForeignKey.define(['structure_id', k]
                                              , schema_name
                                              , parent_table
                                              , ['structure_id', parent_column]
                                              , on_update='CASCADE',
                                              on_delete='SET NULL',
                                              constraint_names=[
                                                  [schema_name, fk_name]],
                                              )
                model = catalog_ermrest.getCatalogModel()
                table.create_fkey(catalog_ermrest, fk)

        continue

        # the composite fkey case
        composite_fkey_children = {}
        composite_fkey_parent = {}
        if tname in ['ihm_gaussian_obj_ensemble', 'ihm_gaussian_obj_site', 'ihm_sphere_obj_site',
                     'ihm_starting_model_coord']:
            continue
        for k, v in columns.items():
            if 'type' in v.keys():
                continue
            elif '$ref' in v.keys():
                parent_table, parent_column = referTable(v)
                # key_name = "{}_{}_key".format(parent_table, parent_column)
                if parent_table not in ['entity_poly_seq']:  # the composite fkey case
                    continue
                elif '_attribute_groups' not in v.keys():
                    composite_fkey_children['composite'] = composite_fkey_children.get(
                        'composite', ['structure_id']) + [k]
                    composite_fkey_parent['composite'] = composite_fkey_parent.get(
                        'composite', ['structure_id']) + [parent_column]
                elif '_attribute_groups' in v.keys():
                    for attribute in v['_attribute_groups']:
                        if 'label' in attribute.keys():
                            composite_fkey_children[attribute['label']] = composite_fkey_children.get(
                                attribute['label'], ['structure_id']) + [k]
                            composite_fkey_parent[attribute['label']] = composite_fkey_parent.get(
                                attribute['label'], ['structure_id']) + [parent_column]
                        else:
                            composite_fkey_children[attribute['id']] = composite_fkey_children.get(attribute['id'],
                                                                                                   ['structure_id']) + [
                                                                           k]
                            composite_fkey_parent[attribute['id']] = composite_fkey_parent.get(attribute['id'],
                                                                                               ['structure_id']) + [
                                                                         parent_column]

        if composite_fkey_children and composite_fkey_parent:
            table = model.table(schema_name, tname)
            for k1, v1 in composite_fkey_parent.items():
                fk_name = "{}_{}_fkey".format(tname, k1)
                if (schema_name, fk_name) in table.foreign_keys.elements.keys():
                    continue
                model = catalog_ermrest.getCatalogModel()
                fk = em.ForeignKey.define(composite_fkey_children[k1]
                                          , schema_name
                                          , 'entity_poly_seq'
                                          , composite_fkey_parent[k1]
                                          , on_update='CASCADE',
                                          on_delete='SET NULL',
                                          constraint_names=[
                                              [schema_name, fk_name]],
                                          )

                model = catalog_ermrest.getCatalogModel()
                table.create_fkey(catalog_ermrest, fk)



if flag_CreateCompositeFkeys:
    # Create Composite FKs
    for tname, t in pdb['properties'].items():
        print(tname)
        if tname in ['_entry_id', '_schema_version', 'pdbx_nonpoly_scheme', 'pdbx_unobs_or_zero_occ_atoms',
                     'pdbx_unobs_or_zero_occ_residues']:
            continue
        elif t['type'] == 'object':
            columns = t['properties']
        elif t['type'] == 'array':
            columns = t['items']['properties']

        # the composite fkey case
        composite_fkey_children = {}
        composite_fkey_parent = {}
        if tname in ['ihm_gaussian_obj_ensemble', 'ihm_gaussian_obj_site', 'ihm_sphere_obj_site',
                     'ihm_starting_model_coord']:
            continue
        for k, v in columns.items():
            if 'type' in v.keys():
                continue
            elif '$ref' in v.keys():
                parent_table, parent_column = referTable(v)
                # key_name = "{}_{}_key".format(parent_table, parent_column)
                if parent_table not in ['entity_poly_seq']:  # the composite fkey case
                    continue
                elif '_attribute_groups' not in v.keys():
                    composite_fkey_children['composite'] = composite_fkey_children.get(
                        'composite', ['structure_id']) + [k]
                    composite_fkey_parent['composite'] = composite_fkey_parent.get(
                        'composite', ['structure_id']) + [parent_column]
                elif '_attribute_groups' in v.keys():
                    for attribute in v['_attribute_groups']:
                        if 'label' in attribute.keys():
                            composite_fkey_children[attribute['label']] = composite_fkey_children.get(
                                attribute['label'], ['structure_id']) + [k]
                            composite_fkey_parent[attribute['label']] = composite_fkey_parent.get(
                                attribute['label'], ['structure_id']) + [parent_column]
                        else:
                            composite_fkey_children[attribute['id']] = composite_fkey_children.get(attribute['id'],
                                                                                                   ['structure_id']) + [
                                                                           k]
                            composite_fkey_parent[attribute['id']] = composite_fkey_parent.get(attribute['id'],
                                                                                               ['structure_id']) + [
                                                                         parent_column]

        if composite_fkey_children and composite_fkey_parent:
            table = model.table(schema_name, tname)
            for k1, v1 in composite_fkey_parent.items():
                fk_name = "{}_{}_fkey".format(tname, k1)
                if (schema_name, fk_name) in table.foreign_keys.elements.keys():
                    continue
                model = catalog_ermrest.getCatalogModel()
                fk = em.ForeignKey.define(composite_fkey_children[k1]
                                          , schema_name
                                          , 'entity_poly_seq'
                                          , composite_fkey_parent[k1]
                                          , on_update='CASCADE',
                                          on_delete='SET NULL',
                                          constraint_names=[
                                              [schema_name, fk_name]],
                                          )

                model = catalog_ermrest.getCatalogModel()
                table.create_fkey(catalog_ermrest, fk)


if flag_VocabTable_VisibleColumn:
	model_root = catalog_ermrest.getCatalogModel()
	for tname in model_root.schemas[term_schema_name].tables:
		tab = model_root.schemas[term_schema_name].tables[tname]
		visible_columns_other = ['RID','Name','Description','ID','URI']
		visible_columns_other.append([term_schema_name, "{}_RCB_fkey".format(tname)])
		visible_columns_other.append([term_schema_name, "{}_RMB_fkey".format(tname)])
		visible_columns_other.append("RCT")
		visible_columns_other.append("RMT")
		visible_columns_other.append([term_schema_name, "{}_Owner_fkey".format(tname)])
		tab.annotations.update({
		   chaise_tags.visible_columns: {'*': visible_columns_other}
		})       
        #tab.apply(catalog_ermrest)
        model_root.apply(catalog_ermrest)


