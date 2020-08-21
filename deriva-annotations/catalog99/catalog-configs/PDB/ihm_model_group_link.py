import argparse
from deriva.core import ErmrestCatalog, AttrDict, get_credential
import deriva.core.ermrest_model as em
from deriva.core.ermrest_config import tag as chaise_tags
from deriva.utils.catalog.manage.update_catalog import CatalogUpdater, parse_args

groups = {}

table_name = 'ihm_model_group_link'

schema_name = 'PDB'

column_annotations = {'structure_id': {}, 'group_id': {}, 'model_id': {}, 'Owner': {}}

column_comment = {
    'structure_id': 'A reference to table entry.id.',
    'group_id': 'A reference to table ihm_model_group.id.',
    'model_id': 'A reference to table ihm_model_list.model_id.',
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
        'group_id', em.builtin_types['int4'], nullok=False, comment=column_comment['group_id'],
    ),
    em.Column.define(
        'model_id', em.builtin_types['int4'], nullok=False, comment=column_comment['model_id'],
    ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
]

visible_columns = {
    '*': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_model_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_model_list.model_id.',
            'markdown_name': 'model id'
        }, {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_group_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_model_group.id.',
            'markdown_name': 'group id'
        }
    ],
    'entry': [
        {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_model_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_model_list.model_id.',
            'markdown_name': 'model id'
        }, {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_group_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_model_group.id.',
            'markdown_name': 'group id'
        }
    ],
    'detailed': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_model_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_model_list.model_id.',
            'markdown_name': 'model id'
        }, {
            'source': [{
                'outbound': ['PDB', 'ihm_model_group_link_group_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table ihm_model_group.id.',
            'markdown_name': 'group id'
        }, ['PDB', 'ihm_model_group_link_RCB_fkey'], ['PDB', 'ihm_model_group_link_RMB_fkey'],
        'RCT', 'RMT', ['PDB', 'ihm_model_group_link_Owner_fkey']
    ]
}

table_annotations = {chaise_tags.visible_columns: visible_columns, }

table_comment = 'List of models belonging to a model group'

table_acls = {}

table_acl_bindings = {}

key_defs = [
    em.Key.define(
        ['model_id', 'structure_id', 'group_id'],
        constraint_names=[['PDB', 'ihm_model_group_link_primary_key']],
    ),
    em.Key.define(['RID'], constraint_names=[['PDB', 'ihm_model_group_link_RIDkey1']],
                  ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_model_group_link_RMB_fkey']],
    ),
    em.ForeignKey.define(
        ['RCB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_model_group_link_RCB_fkey']],
    ),
    em.ForeignKey.define(
        ['model_id', 'structure_id'],
        'PDB',
        'ihm_model_list', ['model_id', 'structure_id'],
        constraint_names=[['PDB', 'ihm_model_group_link_model_id_fkey']],
        annotations={
            chaise_tags.foreign_key: {
                'domain_filter_pattern': 'structure_id={{structure_id}}'
            }
        },
        on_update='CASCADE',
        on_delete='SET NULL',
    ),
    em.ForeignKey.define(
        ['group_id', 'structure_id'],
        'PDB',
        'ihm_model_group', ['id', 'structure_id'],
        constraint_names=[['PDB', 'ihm_model_group_link_group_id_fkey']],
        annotations={
            chaise_tags.foreign_key: {
                'domain_filter_pattern': 'structure_id={{structure_id}}'
            }
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
    catalog_id = 99
    mode, replace, host, catalog_id = parse_args(host, catalog_id, is_table=True)
    catalog = ErmrestCatalog('https', host, catalog_id=catalog_id, credentials=get_credential(host))
    main(catalog, mode, replace)
