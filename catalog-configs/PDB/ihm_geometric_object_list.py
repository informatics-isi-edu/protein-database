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

table_name = 'ihm_geometric_object_list'

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
    'object_description': {},
    'object_id': {
        chaise_tags.generated: None
    },
    'object_name': {},
    'object_type': {},
    'other_details': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
    'object_description': 'type:text\nBrief description of the geometric object.\nexamples:Half-torus representing the nuclear membrane',
    'object_id': 'type:int4\nA unique identifier for the geometric object.',
    'object_name': 'type:text\nUser-provided name for the object.\nexamples:Nuclear membrane',
    'object_type': 'type:text\nThe type of geomtric object.',
    'other_details': 'type:text\nAdditional details about the geometric object, especially if\n _ihm_geometric_object_list.object_type is "other".',
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
        'object_description',
        em.builtin_types['text'],
        comment=column_comment['object_description'],
    ),
    em.Column.define(
        'object_id',
        em.builtin_types['int4'],
        nullok=False,
        annotations=column_annotations['object_id'],
        comment=column_comment['object_id'],
    ),
    em.Column.define(
        'object_name', em.builtin_types['text'], comment=column_comment['object_name'],
    ),
    em.Column.define(
        'object_type',
        em.builtin_types['text'],
        nullok=False,
        comment=column_comment['object_type'],
    ),
    em.Column.define(
        'other_details', em.builtin_types['text'], comment=column_comment['other_details'],
    ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
]

visible_columns = {
    '*': [
        'RID',
        {
            'source': [{
                'outbound': ['PDB', 'ihm_geometric_object_list_structure_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        }, 'object_description', 'object_id', 'object_name',
        ['PDB', 'ihm_geometric_object_list_object_type_term_fkey'], 'other_details',
        ['PDB', 'ihm_geometric_object_list_RCB_fkey'],
        ['PDB', 'ihm_geometric_object_list_RMB_fkey'], 'RCT', 'RMT',
        ['PDB', 'ihm_geometric_object_list_Owner_fkey']
    ],
    'entry': [
        {
            'source': [{
                'outbound': ['PDB', 'ihm_geometric_object_list_structure_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        }, 'object_description', 'object_id', 'object_name',
        ['PDB', 'ihm_geometric_object_list_object_type_term_fkey'], 'other_details'
    ]
}

visible_foreign_keys = {
    'filter': 'detailed',
    'detailed': [
        ['PDB', 'ihm_geometric_object_sphere_object_id_fkey'],
        ['PDB', 'ihm_geometric_object_torus_object_id_fkey'],
        ['PDB', 'ihm_geometric_object_axis_object_id_fkey'],
        ['PDB', 'ihm_geometric_object_plane_object_id_fkey'],
        ['PDB', 'ihm_geometric_object_distance_restraint_object_id_fkey']
    ]
}

table_display = {'row_name': {'row_markdown_pattern': '{{{object_id}}}'}}

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
    em.Key.define(['RID'], constraint_names=[('PDB', 'ihm_geometric_object_list_RIDkey1')],
                  ),
    em.Key.define(
        ['structure_id', 'object_id'],
        constraint_names=[('PDB', 'ihm_geometric_object_list_primary_key')],
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[('PDB', 'ihm_geometric_object_list_RMB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['object_type'],
        'Vocab',
        'ihm_geometric_object_list_object_type_term', ['ID'],
        constraint_names=[('PDB', 'ihm_geometric_object_list_object_type_term_fkey')],
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
        constraint_names=[('PDB', 'ihm_geometric_object_list_Owner_fkey')],
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
        constraint_names=[('PDB', 'ihm_geometric_object_list_RCB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['structure_id'],
        'PDB',
        'entry', ['id'],
        constraint_names=[('PDB', 'ihm_geometric_object_list_structure_id_fkey')],
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
