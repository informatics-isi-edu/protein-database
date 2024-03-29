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

table_name = 'ihm_2dem_class_average_fitting'

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
    'cross_correlation_coefficient': {},
    'id': {
        chaise_tags.generated: None
    },
    'model_id': {},
    'restraint_id': {},
    'rot_matrix_1_1': {},
    'rot_matrix_1_2': {},
    'rot_matrix_1_3': {},
    'rot_matrix_2_1': {},
    'rot_matrix_2_2': {},
    'rot_matrix_2_3': {},
    'rot_matrix_3_1': {},
    'rot_matrix_3_2': {},
    'rot_matrix_3_3': {},
    'tr_vector_1': {},
    'tr_vector_2': {},
    'tr_vector_3': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
    'cross_correlation_coefficient': 'type:float4\nThe cross correlation coefficient corresponding to the model to image fitting.',
    'id': 'type:int4\nA unique identifier for the 2dem class average fitting data.',
    'model_id': 'type:int4\nA unique identifier for the structural model being deposited.',
    'restraint_id': 'type:int4\nA unique identifier for the 2dem class average.',
    'rot_matrix_1_1': 'type:float4\nData item [1][1] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_1_2': 'type:float4\nData item [1][2] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_1_3': 'type:float4\nData item [1][3] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_2_1': 'type:float4\nData item [2][1] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_2_2': 'type:float4\nData item [2][2] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_2_3': 'type:float4\nData item [2][3] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_3_1': 'type:float4\nData item [3][1] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_3_2': 'type:float4\nData item [3][2] of the rotation matrix used in the fitting of the model to the image.',
    'rot_matrix_3_3': 'type:float4\nData item [3][3] of the rotation matrix used in the fitting of the model to the image.',
    'tr_vector_1': 'type:float4\nData item [1] of the tranlation vector used in the fitting of the model to the image.',
    'tr_vector_2': 'type:float4\nData item [2] of the tranlation vector used in the fitting of the model to the image.',
    'tr_vector_3': 'type:float4\nData item [3] of the tranlation vector used in the fitting of the model to the image.',
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
        'cross_correlation_coefficient',
        em.builtin_types['float4'],
        nullok=False,
        comment=column_comment['cross_correlation_coefficient'],
    ),
    em.Column.define(
        'id',
        em.builtin_types['int4'],
        nullok=False,
        annotations=column_annotations['id'],
        comment=column_comment['id'],
    ),
    em.Column.define(
        'model_id', em.builtin_types['int4'], nullok=False, comment=column_comment['model_id'],
    ),
    em.Column.define(
        'restraint_id',
        em.builtin_types['int4'],
        nullok=False,
        comment=column_comment['restraint_id'],
    ),
    em.Column.define(
        'rot_matrix_1_1', em.builtin_types['float4'], comment=column_comment['rot_matrix_1_1'],
    ),
    em.Column.define(
        'rot_matrix_1_2', em.builtin_types['float4'], comment=column_comment['rot_matrix_1_2'],
    ),
    em.Column.define(
        'rot_matrix_1_3', em.builtin_types['float4'], comment=column_comment['rot_matrix_1_3'],
    ),
    em.Column.define(
        'rot_matrix_2_1', em.builtin_types['float4'], comment=column_comment['rot_matrix_2_1'],
    ),
    em.Column.define(
        'rot_matrix_2_2', em.builtin_types['float4'], comment=column_comment['rot_matrix_2_2'],
    ),
    em.Column.define(
        'rot_matrix_2_3', em.builtin_types['float4'], comment=column_comment['rot_matrix_2_3'],
    ),
    em.Column.define(
        'rot_matrix_3_1', em.builtin_types['float4'], comment=column_comment['rot_matrix_3_1'],
    ),
    em.Column.define(
        'rot_matrix_3_2', em.builtin_types['float4'], comment=column_comment['rot_matrix_3_2'],
    ),
    em.Column.define(
        'rot_matrix_3_3', em.builtin_types['float4'], comment=column_comment['rot_matrix_3_3'],
    ),
    em.Column.define(
        'tr_vector_1', em.builtin_types['float4'], comment=column_comment['tr_vector_1'],
    ),
    em.Column.define(
        'tr_vector_2', em.builtin_types['float4'], comment=column_comment['tr_vector_2'],
    ),
    em.Column.define(
        'tr_vector_3', em.builtin_types['float4'], comment=column_comment['tr_vector_3'],
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
                    'outbound': ['PDB', 'ihm_2dem_class_average_fitting_structure_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        }, 'cross_correlation_coefficient', 'id',
        {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_2dem_class_average_fitting_model_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:int4\nA unique identifier for the structural model being deposited.',
            'markdown_name': 'model id'
        },
        {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_2dem_class_average_fitting_restraint_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:int4\nA unique identifier for the 2dem class average.',
            'markdown_name': 'restraint id'
        }, 'rot_matrix_1_1', 'rot_matrix_1_2', 'rot_matrix_1_3', 'rot_matrix_2_1', 'rot_matrix_2_2',
        'rot_matrix_2_3', 'rot_matrix_3_1', 'rot_matrix_3_2', 'rot_matrix_3_3', 'tr_vector_1',
        'tr_vector_2', 'tr_vector_3', ['PDB', 'ihm_2dem_class_average_fitting_RCB_fkey'],
        ['PDB', 'ihm_2dem_class_average_fitting_RMB_fkey'], 'RCT', 'RMT',
        ['PDB', 'ihm_2dem_class_average_fitting_Owner_fkey']
    ],
    'entry': [
        {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_2dem_class_average_fitting_structure_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        }, 'cross_correlation_coefficient', 'id',
        {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_2dem_class_average_fitting_model_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:int4\nA unique identifier for the structural model being deposited.',
            'markdown_name': 'model id'
        },
        {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_2dem_class_average_fitting_restraint_id_fkey']
                }, 'RID'
            ],
            'comment': 'type:int4\nA unique identifier for the 2dem class average.',
            'markdown_name': 'restraint id'
        }, 'rot_matrix_1_1', 'rot_matrix_1_2', 'rot_matrix_1_3', 'rot_matrix_2_1', 'rot_matrix_2_2',
        'rot_matrix_2_3', 'rot_matrix_3_1', 'rot_matrix_3_2', 'rot_matrix_3_3', 'tr_vector_1',
        'tr_vector_2', 'tr_vector_3'
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
    em.Key.define(['RID'], constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_RIDkey1')],
                  ),
    em.Key.define(
        ['structure_id', 'id'],
        constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_primary_key')],
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['Owner'],
        'public',
        'Catalog_Group', ['ID'],
        constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_Owner_fkey')],
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
        constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_RCB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_RMB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['structure_id'],
        'PDB',
        'entry', ['id'],
        constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_structure_id_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='SET NULL',
    ),
    em.ForeignKey.define(
        ['structure_id', 'model_id'],
        'PDB',
        'ihm_model_list', ['structure_id', 'model_id'],
        constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_model_id_fkey')],
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
    em.ForeignKey.define(
        ['structure_id', 'restraint_id'],
        'PDB',
        'ihm_2dem_class_average_restraint', ['structure_id', 'id'],
        constraint_names=[('PDB', 'ihm_2dem_class_average_fitting_restraint_id_fkey')],
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
    updater.update_table(mode, schema_name, table_def, replace=replace, really=really)


if __name__ == "__main__":
    host = 'pdb.isrd.isi.edu'
    catalog_id = 5
    mode, replace, host, catalog_id = parse_args(host, catalog_id, is_table=True)
    catalog = DerivaCatalog(host, catalog_id=catalog_id, validate=False)
    main(catalog, mode, replace)

