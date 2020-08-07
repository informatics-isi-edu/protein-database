import argparse
from deriva.core import ErmrestCatalog, AttrDict, get_credential
import deriva.core.ermrest_model as em
from deriva.core.ermrest_config import tag as chaise_tags
from deriva.utils.catalog.manage.update_catalog import CatalogUpdater, parse_args

groups = {}

table_name = 'Entry_Related_File'

schema_name = 'PDB'

column_annotations = {
    'File_URL': {
        chaise_tags.asset: {
            'md5': 'File_MD5',
            'url_pattern': '/hatrac/pdb/entry_files/{{$moment.year}}/{{{File_MD5}}}',
            'filename_column': 'File_Name',
            'byte_count_column': 'File_Bytes'
        },
        'tag:isrd.isi.edu,2018:required': {}
    },
    'Owner': {}
}

column_comment = {'Owner': 'Group that can update the record.'}

column_acls = {}

column_acl_bindings = {}

column_defs = [
    em.Column.define('File_Type', em.builtin_types['text'], nullok=False,
                     ),
    em.Column.define('File_Format', em.builtin_types['text'], nullok=False,
                     ),
    em.Column.define(
        'File_URL', em.builtin_types['text'], annotations=column_annotations['File_URL'],
    ),
    em.Column.define('File_Name', em.builtin_types['text'],
                     ),
    em.Column.define('File_MD5', em.builtin_types['text'],
                     ),
    em.Column.define('File_Bytes', em.builtin_types['int8'],
                     ),
    em.Column.define(
        'Workflow_Status', em.builtin_types['text'], nullok=False, default='PDB:1-MSVE',
    ),
    em.Column.define('Process_Status', em.builtin_types['text'], default='New',
                     ),
    em.Column.define('Record_Status_Detail', em.builtin_types['text'],
                     ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
    em.Column.define('structure_id', em.builtin_types['text'], nullok=False,
                     ),
    em.Column.define('Description', em.builtin_types['text'],
                     ),
]

visible_columns = {
    '*': [
        'RID', ['PDB',
                'Entry_Related_File_entry_id_fkey'], ['PDB', 'Entry_Related_File_File_Type_fkey'],
        ['PDB', 'Entry_Related_File_File_Format_fkey'], 'File_URL', 'File_Bytes', 'File_MD5',
        'Description', ['PDB', 'Entry_Related_File_workflow_status_fkey'], 'Record_Status_Detail'
    ],
    'entry': [
        ['PDB', 'Entry_Related_File_entry_id_fkey'], ['PDB', 'Entry_Related_File_File_Type_fkey'],
        ['PDB', 'Entry_Related_File_File_Format_fkey'], 'File_Name', 'File_URL', 'File_Bytes',
        'File_MD5', 'Description', ['PDB', 'Entry_Related_File_workflow_status_fkey']
    ],
    'detailed': [
        'RID', ['PDB',
                'Entry_Related_File_entry_id_fkey'], ['PDB', 'Entry_Related_File_File_Type_fkey'],
        ['PDB', 'Entry_Related_File_File_Format_fkey'], 'File_URL', 'File_Bytes', 'File_MD5',
        'Description', ['PDB', 'Entry_Related_File_workflow_status_fkey'], 'Record_Status_Detail',
        ['PDB', 'Entry_Related_File_RCB_fkey'], ['PDB',
                                                 'Entry_Related_File_RMB_fkey'], 'RCT', 'RMT',
        ['PDB', 'Entry_Related_File_Owner_fkey']
    ]
}

table_annotations = {chaise_tags.visible_columns: visible_columns, }

table_comment = None

table_acls = {}

table_acl_bindings = {}

key_defs = []

fkey_defs = []

table_def = em.Table.define(
    table_name,
    column_defs=column_defs,
    key_defs=key_defs,
    fkey_defs=fkey_defs,
    annotations=table_annotations,
    acls=table_acls,
    acl_bindings=table_acl_bindings,
    comment=table_comment,
    provide_system=True
)


def main(catalog, mode, replace=False, really=False):
    updater = CatalogUpdater(catalog)
    table_def['column_annotations'] = column_annotations
    table_def['column_comment'] = column_comment
    updater.update_table(mode, schema_name, table_def, replace=replace, really=really)


if __name__ == "__main__":
    host = 'pdb.isrd.isi.edu'
    catalog_id = 99
    mode, replace, host, catalog_id = parse_args(host, catalog_id, is_table=True)
    catalog = ErmrestCatalog('https', host, catalog_id=catalog_id, credentials=get_credential(host))
    main(catalog, mode, replace)
