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
    'isrd-staff': 'https://auth.globus.org/176baec4-ed26-11e5-8e88-22000ab4b42b',
    'pdb-submitter': 'https://auth.globus.org/99da042e-64a6-11ea-ad5f-0ef992ed7ca1'
}

table_name = 'ihm_related_datasets'

schema_name = 'PDB'

column_annotations = {
    'structure_id': {},
    'dataset_list_id_derived': {},
    'dataset_list_id_primary': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'A reference to table entry.id.',
    'dataset_list_id_derived': 'A reference to table ihm_dataset_list.id.',
    'dataset_list_id_primary': 'A reference to table ihm_dataset_list.id.',
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
        'dataset_list_id_derived',
        em.builtin_types['int4'],
        nullok=False,
        comment=column_comment['dataset_list_id_derived'],
    ),
    em.Column.define(
        'dataset_list_id_primary',
        em.builtin_types['int4'],
        nullok=False,
        comment=column_comment['dataset_list_id_primary'],
    ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
]

display = {'name': 'Datasets Derived from Another'}

visible_columns = {
    '*': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_related_datasets_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_related_datasets_dataset_list_id_derived_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_dataset_list.id.',
            'markdown_name': 'derived dataset list id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_related_datasets_dataset_list_id_primary_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_dataset_list.id.',
            'markdown_name': 'primary dataset list id'
        }
    ],
    'entry': [
        {
            'source': [{
                'outbound': ['PDB', 'ihm_related_datasets_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_related_datasets_dataset_list_id_derived_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_dataset_list.id.',
            'markdown_name': 'derived dataset list id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_related_datasets_dataset_list_id_primary_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_dataset_list.id.',
            'markdown_name': 'primary dataset list id'
        }
    ],
    'detailed': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_related_datasets_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_related_datasets_dataset_list_id_derived_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_dataset_list.id.',
            'markdown_name': 'derived dataset list id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_related_datasets_dataset_list_id_primary_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_dataset_list.id.',
            'markdown_name': 'primary dataset list id'
        }, ['PDB', 'ihm_related_datasets_RCB_fkey'], ['PDB', 'ihm_related_datasets_RMB_fkey'],
        'RCT', 'RMT', ['PDB', 'ihm_related_datasets_Owner_fkey']
    ]
}

table_annotations = {chaise_tags.display: display, chaise_tags.visible_columns: visible_columns, }

table_comment = 'Information about related datasets where one is derived from the other'

table_acls = {
    'owner': [groups['pdb-admin'], groups['isrd-staff']],
    'write': [],
    'delete': [groups['pdb-curator']],
    'insert': [groups['pdb-curator'], groups['pdb-writer'], groups['pdb-submitter']],
    'select': [groups['pdb-writer'], groups['pdb-reader']],
    'update': [groups['pdb-curator']],
    'enumerate': ['*']
}

table_acl_bindings = {
    'released_reader': {
        'types': ['select'],
        'scope_acl': [groups['pdb-submitter']],
        'projection': [{
            'outbound': ['PDB', 'ihm_related_datasets_structure_id_fkey']
        }, 'RCB'],
        'projection_type': 'acl'
    },
    'self_service_group': {
        'types': ['update', 'delete'],
        'scope_acl': ['*'],
        'projection': ['Owner'],
        'projection_type': 'acl'
    },
    'self_service_creator': {
        'types': ['update', 'delete'],
        'scope_acl': [groups['pdb-submitter']],
        'projection': [
            {
                'outbound': ['PDB', 'ihm_related_datasets_structure_id_fkey']
            }, {
                'or': [
                    {
                        'filter': 'Workflow_Status',
                        'operand': 'DRAFT',
                        'operator': '='
                    }, {
                        'filter': 'Workflow_Status',
                        'operand': 'DEPO',
                        'operator': '='
                    }, {
                        'filter': 'Workflow_Status',
                        'operand': 'RECORD READY',
                        'operator': '='
                    }, {
                        'filter': 'Workflow_Status',
                        'operand': 'ERROR',
                        'operator': '='
                    }
                ]
            }, 'RCB'
        ],
        'projection_type': 'acl'
    }
}

key_defs = [
    em.Key.define(['RID'], constraint_names=[['PDB', 'ihm_related_datasets_RIDkey1']],
                  ),
    em.Key.define(
        ['dataset_list_id_primary', 'dataset_list_id_derived', 'structure_id'],
        constraint_names=[['PDB', 'ihm_related_datasets_primary_key']],
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['RCB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_related_datasets_RCB_fkey']],
    ),
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_related_datasets_RMB_fkey']],
    ),
    em.ForeignKey.define(
        ['dataset_list_id_primary', 'structure_id'],
        'PDB',
        'ihm_dataset_list', ['id', 'structure_id'],
        constraint_names=[['PDB', 'ihm_related_datasets_dataset_list_id_primary_fkey']],
        annotations={
            chaise_tags.foreign_key: {
                'template_engine': 'handlebars',
                'domain_filter_pattern': '{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}'
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
        ['dataset_list_id_derived', 'structure_id'],
        'PDB',
        'ihm_dataset_list', ['id', 'structure_id'],
        constraint_names=[['PDB', 'ihm_related_datasets_dataset_list_id_derived_fkey']],
        annotations={
            chaise_tags.foreign_key: {
                'template_engine': 'handlebars',
                'domain_filter_pattern': '{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}'
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
        ['Owner'],
        'public',
        'Catalog_Group', ['ID'],
        constraint_names=[['PDB', 'ihm_related_datasets_Owner_fkey']],
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
        ['structure_id'],
        'PDB',
        'entry', ['id'],
        constraint_names=[['PDB', 'ihm_related_datasets_structure_id_fkey']],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='CASCADE',
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
