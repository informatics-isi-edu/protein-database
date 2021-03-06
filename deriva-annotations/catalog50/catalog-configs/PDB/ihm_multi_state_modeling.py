import argparse
from deriva.core import ErmrestCatalog, AttrDict, get_credential
import deriva.core.ermrest_model as em
from deriva.core.ermrest_config import tag as chaise_tags
from deriva.utils.catalog.manage.update_catalog import CatalogUpdater, parse_args

groups = {}

table_name = 'ihm_multi_state_modeling'

schema_name = 'PDB'

column_annotations = {
    'structure_id': {},
    'details': {},
    'experiment_type': {},
    'population_fraction': {},
    'population_fraction_sd': {},
    'state_group_id': {},
    'state_id': {},
    'state_name': {},
    'state_type': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'A reference to table entry.id.',
    'details': 'type:text\nAdditional textual details of the multi-state modeling, if required.\nexamples:open state ensemble 1,closed state ensemble 2,bound to heme',
    'experiment_type': 'type:text\nThe type of multi-state modeling experiment carried out.',
    'population_fraction': 'type:float4\nA fraction representing the population of the particular state.',
    'population_fraction_sd': 'type:float4\nThe standard deviation of the population fraction.',
    'state_group_id': 'type:int4\nAn identifier for a collections of states in the multi-state modeling.\n This data item can be used when structural models belong to diffent\n multi-state modeling types.',
    'state_id': 'type:int4\nA unique identifier for a particular state in the multi-state modeling.',
    'state_name': 'type:text\nA descriptive name for the state.\nexamples:open,closed,bound,unbound,active,inactive,relaxed,tensed',
    'state_type': 'type:text\nThe type that the multiple states being modeled belong to.\nexamples:conformational change,ligand binding,complex formation,complex dissociation',
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
    em.Column.define('details', em.builtin_types['text'], comment=column_comment['details'],
                     ),
    em.Column.define(
        'experiment_type', em.builtin_types['text'], comment=column_comment['experiment_type'],
    ),
    em.Column.define(
        'population_fraction',
        em.builtin_types['float4'],
        comment=column_comment['population_fraction'],
    ),
    em.Column.define(
        'population_fraction_sd',
        em.builtin_types['float4'],
        comment=column_comment['population_fraction_sd'],
    ),
    em.Column.define(
        'state_group_id', em.builtin_types['int4'], comment=column_comment['state_group_id'],
    ),
    em.Column.define(
        'state_id', em.builtin_types['int4'], nullok=False, comment=column_comment['state_id'],
    ),
    em.Column.define(
        'state_name', em.builtin_types['text'], comment=column_comment['state_name'],
    ),
    em.Column.define(
        'state_type', em.builtin_types['text'], comment=column_comment['state_type'],
    ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
]

visible_columns = {
    '*': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_multi_state_modeling_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'state_id', 'state_group_id', 'state_type', 'state_name',
        ['PDB', 'ihm_multi_state_modeling_experiment_type_fkey'], 'population_fraction',
        'population_fraction_sd', 'details'
    ],
    'entry': [
        {
            'source': [{
                'outbound': ['PDB', 'ihm_multi_state_modeling_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'state_id', 'state_group_id', 'state_type', 'state_name',
        ['PDB', 'ihm_multi_state_modeling_experiment_type_fkey'], 'population_fraction',
        'population_fraction_sd', 'details'
    ],
    'detailed': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_multi_state_modeling_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'state_id', 'state_group_id', 'state_type', 'state_name',
        ['PDB', 'ihm_multi_state_modeling_experiment_type_fkey'], 'population_fraction',
        'population_fraction_sd', 'details', ['PDB', 'ihm_multi_state_modeling_RCB_fkey'],
        ['PDB', 'ihm_multi_state_modeling_RMB_fkey'], 'RCT', 'RMT',
        ['PDB', 'ihm_multi_state_modeling_Owner_fkey']
    ]
}

visible_foreign_keys = {
    'filter': 'detailed',
    'detailed': [['PDB', 'ihm_multi_state_model_group_link_state_id_fkey']]
}

table_display = {'row_name': {'row_markdown_pattern': '{{{state_id}}}'}}

table_annotations = {
    chaise_tags.table_display: table_display,
    chaise_tags.visible_columns: visible_columns,
    chaise_tags.visible_foreign_keys: visible_foreign_keys,
}

table_comment = 'Details of multi-state modeling'

table_acls = {}

table_acl_bindings = {}

key_defs = [
    em.Key.define(['RID'], constraint_names=[['PDB', 'ihm_multi_state_modeling_RIDkey1']],
                  ),
    em.Key.define(
        ['structure_id', 'state_id'],
        constraint_names=[['PDB', 'ihm_multi_state_modeling_primary_key']],
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['experiment_type'],
        'Vocab',
        'ihm_multi_state_modeling_experiment_type', ['Name'],
        constraint_names=[['PDB', 'ihm_multi_state_modeling_experiment_type_fkey']],
    ),
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_multi_state_modeling_RMB_fkey']],
    ),
    em.ForeignKey.define(
        ['RCB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_multi_state_modeling_RCB_fkey']],
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
    catalog_id = 50
    mode, replace, host, catalog_id = parse_args(host, catalog_id, is_table=True)
    catalog = ErmrestCatalog('https', host, catalog_id=catalog_id, credentials=get_credential(host))
    main(catalog, mode, replace)
