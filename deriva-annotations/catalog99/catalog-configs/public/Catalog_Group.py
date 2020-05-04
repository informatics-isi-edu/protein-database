import argparse
from deriva.core import ErmrestCatalog, AttrDict, get_credential
import deriva.core.ermrest_model as em
from deriva.core.ermrest_config import tag as chaise_tags
from deriva.utils.catalog.manage.update_catalog import CatalogUpdater, parse_args

groups = {
    'pdb-reader': 'https://auth.globus.org/8875a770-3c40-11e9-a8c8-0ee7d80087ee',
    'pdb-writer': 'https://auth.globus.org/c94a1e5c-3c40-11e9-a5d1-0aacc65bfe9a',
    'pdb-admin': 'https://auth.globus.org/0b98092c-3c41-11e9-a8c8-0ee7d80087ee',
    'pdb-curator': 'https://auth.globus.org/eef3e02a-3c40-11e9-9276-0edc9bdd56a6',
    'isrd-staff': 'https://auth.globus.org/176baec4-ed26-11e5-8e88-22000ab4b42b'
}

table_name = 'Catalog_Group'

schema_name = 'public'

column_annotations = {
    'RCT': {
        chaise_tags.display: {
            'name': 'Creation Time'
        },
        chaise_tags.generated: None,
        chaise_tags.immutable: None
    },
    'RMT': {
        chaise_tags.display: {
            'name': 'Last Modified Time'
        },
        chaise_tags.generated: None,
        chaise_tags.immutable: None
    },
    'RCB': {
        chaise_tags.display: {
            'name': 'Created By'
        },
        chaise_tags.generated: None,
        chaise_tags.immutable: None
    },
    'RMB': {
        chaise_tags.display: {
            'name': 'Modified By'
        },
        chaise_tags.generated: None,
        chaise_tags.immutable: None
    },
    'Display_Name': {
        chaise_tags.display: {
            'name': 'Display Name'
        }
    }
}

column_comment = {}

column_acls = {}

column_acl_bindings = {}

column_defs = [
    em.Column.define(
        'Display_Name', em.builtin_types['text'], annotations=column_annotations['Display_Name'],
    ),
    em.Column.define('URL', em.builtin_types['text'],
                     ),
    em.Column.define('Description', em.builtin_types['text'],
                     ),
    em.Column.define('ID', em.builtin_types['text'], nullok=False,
                     ),
]

table_annotations = {}

table_comment = None

table_acls = {
    'insert': [groups['pdb-writer'], groups['pdb-curator']],
    'select': [groups['pdb-reader']]
}

table_acl_bindings = {}

key_defs = [
    em.Key.define(['RID'], constraint_names=[['public', 'Catalog_Group_RIDkey1']],
                  ),
    em.Key.define(['ID'], constraint_names=[['public', 'Catalog_Group_ID_key']],
                  ),
    em.Key.define(
        ['Display_Name', 'Description', 'ID', 'URL'],
        constraint_names=[['public', 'Catalog_Group_ID_URL_Display_Name_Description_key']],
        comment='Key to ensure that group only is entered once.',
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['RCB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['public', 'Catalog_Group_RCB_fkey']],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['URL', 'Display_Name', 'ID', 'Description'],
        'public',
        'ERMrest_Group', ['URL', 'Display_Name', 'ID', 'Description'],
        constraint_names=[['public', 'Catalog_Group_ID1']],
        acls={
            'insert': [groups['pdb-curator']],
            'update': [groups['pdb-curator']]
        },
        acl_bindings={
            'set_owner': {
                'types': ['insert'],
                'projection': ['ID'],
                'projection_type': 'acl',
                'scope_acl': ['*']
            }
        },
        on_update='CASCADE',
    ),
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['public', 'Catalog_Group_RMB_fkey']],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
]

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
