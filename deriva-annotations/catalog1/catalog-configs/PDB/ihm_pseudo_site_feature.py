import argparse
from deriva.core import ErmrestCatalog, AttrDict, get_credential, DerivaPathError
from deriva.utils.catalog.components.deriva_model import DerivaCatalog
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

table_name = 'ihm_pseudo_site_feature'

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
    'Cartn_x': {},
    'Cartn_y': {},
    'Cartn_z': {},
    'description': {},
    'feature_id': {},
    'radius': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'A reference to table entry.id.',
    'Cartn_x': 'type:float4\nThe Cartesian X component corresponding to this pseudo site.',
    'Cartn_y': 'type:float4\nThe Cartesian Y component corresponding to this pseudo site.',
    'Cartn_z': 'type:float4\nThe Cartesian Z component corresponding to this pseudo site.',
    'description': 'type:text\nTextual description of the pseudo site representing the specific feature.\nexamples:centroid of the feature',
    'feature_id': 'A reference to table ihm_feature_list.feature_id.',
    'radius': 'type:float4\nThe radius associated with the feature at this position, if applicable.',
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
        'Cartn_x', em.builtin_types['float4'], nullok=False, comment=column_comment['Cartn_x'],
    ),
    em.Column.define(
        'Cartn_y', em.builtin_types['float4'], nullok=False, comment=column_comment['Cartn_y'],
    ),
    em.Column.define(
        'Cartn_z', em.builtin_types['float4'], nullok=False, comment=column_comment['Cartn_z'],
    ),
    em.Column.define(
        'description', em.builtin_types['text'], comment=column_comment['description'],
    ),
    em.Column.define(
        'feature_id',
        em.builtin_types['int4'],
        nullok=False,
        comment=column_comment['feature_id'],
    ),
    em.Column.define('radius', em.builtin_types['float4'], comment=column_comment['radius'],
                     ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
]

visible_columns = {
    '*': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_pseudo_site_feature_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'Cartn_x', 'Cartn_y', 'Cartn_z', 'description', {
            'source': [{
                'outbound': ['PDB', 'ihm_pseudo_site_feature_feature_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_feature_list.feature_id.',
            'markdown_name': 'feature id'
        }, 'radius', ['PDB', 'ihm_pseudo_site_feature_RCB_fkey'],
        ['PDB', 'ihm_pseudo_site_feature_RMB_fkey'], 'RCT', 'RMT',
        ['PDB', 'ihm_pseudo_site_feature_Owner_fkey']
    ],
    'entry': [
        {
            'source': [{
                'outbound': ['PDB', 'ihm_pseudo_site_feature_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'Cartn_x', 'Cartn_y', 'Cartn_z', 'description', {
            'source': [{
                'outbound': ['PDB', 'ihm_pseudo_site_feature_feature_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_feature_list.feature_id.',
            'markdown_name': 'feature id'
        }, 'radius'
    ]
}

table_annotations = {chaise_tags.visible_columns: visible_columns, }

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
    em.Key.define(['RID'], constraint_names=[('PDB', 'ihm_pseudo_site_feature_RIDkey1')],
                  ),
    em.Key.define(
        ['structure_id', 'feature_id'],
        constraint_names=[('PDB', 'ihm_pseudo_site_feature_primary_key')],
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['Owner'],
        'public',
        'Catalog_Group', ['ID'],
        constraint_names=[('PDB', 'ihm_pseudo_site_feature_Owner_fkey')],
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
        constraint_names=[('PDB', 'ihm_pseudo_site_feature_RCB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[('PDB', 'ihm_pseudo_site_feature_RMB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['structure_id'],
        'PDB',
        'entry', ['id'],
        constraint_names=[('PDB', 'ihm_pseudo_site_feature_structure_id_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='SET NULL',
    ),
    em.ForeignKey.define(
        ['structure_id', 'feature_id'],
        'PDB',
        'ihm_feature_list', ['structure_id', 'feature_id'],
        constraint_names=[('PDB', 'ihm_pseudo_site_feature_feature_id_fkey')],
        annotations={
            chaise_tags.foreign_key: {
                'domain_filter_pattern': 'structure_id={{structure_id}}'
            }
        },
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
    table_def['column_annotations'] = column_annotations
    table_def['column_comment'] = column_comment
    updater.update_table(mode, schema_name, table_def, replace=replace, really=really)


if __name__ == "__main__":
    host = 'pdb.isrd.isi.edu'
    catalog_id = 1
    mode, replace, host, catalog_id = parse_args(host, catalog_id, is_table=True)
    catalog = DerivaCatalog(host, catalog_id=catalog_id, validate=False)
    main(catalog, mode, replace)
