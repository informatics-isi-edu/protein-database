import argparse
from attrdict import AttrDict
from deriva.core import ErmrestCatalog, get_credential, DerivaPathError
from deriva.utils.catalog.components.deriva_model import DerivaCatalog
import deriva.core.ermrest_model as em
from deriva.core.ermrest_config import tag as chaise_tags
from deriva.utils.catalog.manage.update_catalog import CatalogUpdater, parse_args

groups = {
    'pdb-admin': 'https://auth.globus.org/0b98092c-3c41-11e9-a8c8-0ee7d80087ee',
    'pdb-reader': 'https://auth.globus.org/8875a770-3c40-11e9-a8c8-0ee7d80087ee',
    'pdb-writer': 'https://auth.globus.org/c94a1e5c-3c40-11e9-a5d1-0aacc65bfe9a',
    'pdb-curator': 'https://auth.globus.org/eef3e02a-3c40-11e9-9276-0edc9bdd56a6',
    'isrd-staff': 'https://auth.globus.org/176baec4-ed26-11e5-8e88-22000ab4b42b'
}

table_name = 'ihm_external_reference_info'

schema_name = 'PDB'

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
    'structure_id': {},
    'associated_url': {},
    'reference': {},
    'reference_id': {
        chaise_tags.generated: None
    },
    'reference_provider': {},
    'reference_type': {},
    'refers_to': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
    'associated_url': 'type:text\nThe Uniform Resource Locator (URL) corresponding to the external reference (DOI). \n This URL should link to the corresponding downloadable file or archive and is provided \n to enable automated software to download the referenced file or archive.',
    'reference': 'type:text\nThe external reference or the Digital Object Identifier (DOI).\n This field is not relevant for local files.\nexamples:10.5281/zenodo.46266',
    'reference_id': 'type:int4\nA unique identifier for the external reference.',
    'reference_provider': 'type:text\nThe name of the reference provider.\nexamples:Zenodo,Figshare,Crossref',
    'reference_type': 'type:text\nThe type of external reference. \n Currently, only Digital Object Identifiers (DOIs) and supplementary files \n stored locally are supported.',
    'refers_to': 'type:text\nThe type of object that the external reference points to, usually\n a single file or an archive.',
    'Owner': 'Group that can update the record.'
}

column_acls = {}

column_acl_bindings = {}

column_defs = [
    em.Column.define(
        'structure_id',
        em.builtin_types['text'],
        nullok=False,
        comment=column_comment['structure_id'],
    ),
    em.Column.define(
        'associated_url', em.builtin_types['text'], comment=column_comment['associated_url'],
    ),
    em.Column.define(
        'reference', em.builtin_types['text'], nullok=False, comment=column_comment['reference'],
    ),
    em.Column.define(
        'reference_id',
        em.builtin_types['int4'],
        nullok=False,
        annotations=column_annotations['reference_id'],
        comment=column_comment['reference_id'],
    ),
    em.Column.define(
        'reference_provider',
        em.builtin_types['text'],
        comment=column_comment['reference_provider'],
    ),
    em.Column.define(
        'reference_type',
        em.builtin_types['text'],
        nullok=False,
        comment=column_comment['reference_type'],
    ),
    em.Column.define(
        'refers_to', em.builtin_types['text'], nullok=False, comment=column_comment['refers_to'],
    ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
]

visible_columns = {
    '*': [
        'RID',
        {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_external_reference_info_structure_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        }, 'associated_url', 'reference', 'reference_id', 'reference_provider',
        ['PDB', 'ihm_external_reference_info_reference_type_term_fkey'],
        ['PDB', 'ihm_external_reference_info_refers_to_term_fkey'],
        ['PDB', 'ihm_external_reference_info_RCB_fkey'],
        ['PDB', 'ihm_external_reference_info_RMB_fkey'], 'RCT', 'RMT',
        ['PDB', 'ihm_external_reference_info_Owner_fkey']
    ],
    'entry': [
        {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_external_reference_info_structure_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        }, 'associated_url', 'reference', 'reference_id', 'reference_provider',
        ['PDB', 'ihm_external_reference_info_reference_type_term_fkey'],
        ['PDB', 'ihm_external_reference_info_refers_to_term_fkey']
    ]
}

visible_foreign_keys = {
    'filter': 'detailed',
    'detailed': [['PDB', 'ihm_external_files_reference_id_fkey']]
}

table_display = {'row_name': {'row_markdown_pattern': '{{{reference_id}}}'}}

table_annotations = {
    chaise_tags.table_display: table_display,
    chaise_tags.visible_columns: visible_columns,
    chaise_tags.visible_foreign_keys: visible_foreign_keys,
}

table_comment = None

table_acls = {}

table_acl_bindings = {
    'self_service_group': {
        'types': ['update', 'delete'],
        'scope_acl': ['*'],
        'projection': ['Owner'],
        'projection_type': 'acl'
    },
    'self_service_creator': {
        'types': ['update', 'delete'],
        'scope_acl': ['*'],
        'projection': ['RCB'],
        'projection_type': 'acl'
    }
}

key_defs = [
    em.Key.define(['RID'], constraint_names=[('PDB', 'ihm_external_reference_info_RIDkey1')],
                  ),
    em.Key.define(
        ['structure_id', 'reference_id'],
        constraint_names=[('PDB', 'ihm_external_reference_info_primary_key')],
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['reference_type'],
        'Vocab',
        'ihm_external_reference_info_reference_type_term', ['ID'],
        constraint_names=[('PDB', 'ihm_external_reference_info_reference_type_term_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='SET NULL',
    ),
    em.ForeignKey.define(
        ['refers_to'],
        'Vocab',
        'ihm_external_reference_info_refers_to_term', ['ID'],
        constraint_names=[('PDB', 'ihm_external_reference_info_refers_to_term_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='SET NULL',
    ),
    em.ForeignKey.define(
        ['Owner'],
        'public',
        'Catalog_Group', ['ID'],
        constraint_names=[('PDB', 'ihm_external_reference_info_Owner_fkey')],
        acls={
            'insert': [groups['pdb-curator']],
            'update': [groups['pdb-curator']]
        },
        acl_bindings={
            'set_owner': {
                'types': ['update', 'insert'],
                'scope_acl': ['*'],
                'projection': ['ID'],
                'projection_type': 'acl'
            }
        },
    ),
    em.ForeignKey.define(
        ['RCB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[('PDB', 'ihm_external_reference_info_RCB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[('PDB', 'ihm_external_reference_info_RMB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['structure_id'],
        'PDB',
        'entry', ['id'],
        constraint_names=[('PDB', 'ihm_external_reference_info_structure_id_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='SET NULL',
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
    updater.update_table(mode, schema_name, table_def, replace=replace, really=really)


if __name__ == "__main__":
    host = 'pdb.isrd.isi.edu'
    catalog_id = 5
    mode, replace, host, catalog_id = parse_args(host, catalog_id, is_table=True)
    catalog = DerivaCatalog(host, catalog_id=catalog_id, validate=False)
    main(catalog, mode, replace)

