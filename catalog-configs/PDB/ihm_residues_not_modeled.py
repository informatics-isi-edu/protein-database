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

table_name = 'ihm_residues_not_modeled'

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
    'asym_id': {},
    'comp_id_begin': {},
    'comp_id_end': {},
    'details': {},
    'entity_description': {},
    'entity_id': {},
    'id': {
        chaise_tags.generated: None
    },
    'model_id': {},
    'reason': {},
    'seq_id_begin': {},
    'seq_id_end': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
    'asym_id': 'type:text\nThe value of _struct_asym.id must uniquely identify a record in\n the STRUCT_ASYM list.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
    'comp_id_begin': 'type:text\nThe value of _chem_comp.id must uniquely identify each item in\n the CHEM_COMP list.\n\n For protein polymer entities, this is the three-letter code for\n the amino acid.\n\n For nucleic acid polymer entities, this is the one-letter code\n for the base.',
    'comp_id_end': 'type:text\nThe value of _chem_comp.id must uniquely identify each item in\n the CHEM_COMP list.\n\n For protein polymer entities, this is the three-letter code for\n the amino acid.\n\n For nucleic acid polymer entities, this is the one-letter code\n for the base.',
    'details': 'type:text\nAdditional details regarding the missing segments.',
    'entity_description': 'type:text\nA text description of the molecular entity, whose residues are not modeled. \n This data item is a pointer to _entity.pdbx_description in the ENTITY category.',
    'entity_id': 'type:text\nThe value of _entity.id must uniquely identify a record in the\n ENTITY list.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
    'id': 'type:int4\nA unique identifier for the category.',
    'model_id': 'type:int4\nA unique identifier for the structural model being deposited.',
    'reason': 'type:text\nThe reason why the residues are missing in the structural model.',
    'seq_id_begin': 'type:int4\nThe value of _entity_poly_seq.num must uniquely and sequentially\n identify a record in the ENTITY_POLY_SEQ list.\n\n Note that this item must be a number and that the sequence\n numbers must progress in increasing numerical order.',
    'seq_id_end': 'type:int4\nThe value of _entity_poly_seq.num must uniquely and sequentially\n identify a record in the ENTITY_POLY_SEQ list.\n\n Note that this item must be a number and that the sequence\n numbers must progress in increasing numerical order.',
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
        'asym_id', em.builtin_types['text'], nullok=False, comment=column_comment['asym_id'],
    ),
    em.Column.define(
        'comp_id_begin',
        em.builtin_types['text'],
        nullok=False,
        comment=column_comment['comp_id_begin'],
    ),
    em.Column.define(
        'comp_id_end',
        em.builtin_types['text'],
        nullok=False,
        comment=column_comment['comp_id_end'],
    ),
    em.Column.define('details', em.builtin_types['text'], comment=column_comment['details'],
                     ),
    em.Column.define(
        'entity_description',
        em.builtin_types['text'],
        comment=column_comment['entity_description'],
    ),
    em.Column.define(
        'entity_id', em.builtin_types['text'], nullok=False, comment=column_comment['entity_id'],
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
    em.Column.define('reason', em.builtin_types['text'], comment=column_comment['reason'],
                     ),
    em.Column.define(
        'seq_id_begin',
        em.builtin_types['int4'],
        nullok=False,
        comment=column_comment['seq_id_begin'],
    ),
    em.Column.define(
        'seq_id_end',
        em.builtin_types['int4'],
        nullok=False,
        comment=column_comment['seq_id_end'],
    ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
]

visible_columns = {
    '*': [
        'RID',
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_structure_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_asym_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _struct_asym.id must uniquely identify a record in\n the STRUCT_ASYM list.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'asym id'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_comp_id_begin_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _chem_comp.id must uniquely identify each item in\n the CHEM_COMP list.\n\n For protein polymer entities, this is the three-letter code for\n the amino acid.\n\n For nucleic acid polymer entities, this is the one-letter code\n for the base.',
            'markdown_name': 'comp id begin'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_comp_id_end_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _chem_comp.id must uniquely identify each item in\n the CHEM_COMP list.\n\n For protein polymer entities, this is the three-letter code for\n the amino acid.\n\n For nucleic acid polymer entities, this is the one-letter code\n for the base.',
            'markdown_name': 'comp id end'
        }, 'details', 'entity_description',
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_entity_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _entity.id must uniquely identify a record in the\n ENTITY list.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'entity id'
        }, 'id',
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_model_id_fkey']
            }, 'RID'],
            'comment': 'type:int4\nA unique identifier for the structural model being deposited.',
            'markdown_name': 'model id'
        }, ['PDB', 'ihm_residues_not_modeled_reason_term_fkey'],
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_seq_id_begin_fkey']
            }, 'RID'],
            'comment': 'type:int4\nThe value of _entity_poly_seq.num must uniquely and sequentially\n identify a record in the ENTITY_POLY_SEQ list.\n\n Note that this item must be a number and that the sequence\n numbers must progress in increasing numerical order.',
            'markdown_name': 'seq id begin'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_seq_id_end_fkey']
            }, 'RID'],
            'comment': 'type:int4\nThe value of _entity_poly_seq.num must uniquely and sequentially\n identify a record in the ENTITY_POLY_SEQ list.\n\n Note that this item must be a number and that the sequence\n numbers must progress in increasing numerical order.',
            'markdown_name': 'seq id end'
        }, ['PDB', 'ihm_residues_not_modeled_RCB_fkey'],
        ['PDB', 'ihm_residues_not_modeled_RMB_fkey'], 'RCT', 'RMT',
        ['PDB', 'ihm_residues_not_modeled_Owner_fkey']
    ],
    'entry': [
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_structure_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _entry.id identifies the data block.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'structure id'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_asym_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _struct_asym.id must uniquely identify a record in\n the STRUCT_ASYM list.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'asym id'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_comp_id_begin_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _chem_comp.id must uniquely identify each item in\n the CHEM_COMP list.\n\n For protein polymer entities, this is the three-letter code for\n the amino acid.\n\n For nucleic acid polymer entities, this is the one-letter code\n for the base.',
            'markdown_name': 'comp id begin'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_comp_id_end_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _chem_comp.id must uniquely identify each item in\n the CHEM_COMP list.\n\n For protein polymer entities, this is the three-letter code for\n the amino acid.\n\n For nucleic acid polymer entities, this is the one-letter code\n for the base.',
            'markdown_name': 'comp id end'
        }, 'details', 'entity_description',
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_entity_id_fkey']
            }, 'RID'],
            'comment': 'type:text\nThe value of _entity.id must uniquely identify a record in the\n ENTITY list.\n\n Note that this item need not be a number; it can be any unique\n identifier.',
            'markdown_name': 'entity id'
        }, 'id',
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_model_id_fkey']
            }, 'RID'],
            'comment': 'type:int4\nA unique identifier for the structural model being deposited.',
            'markdown_name': 'model id'
        }, ['PDB', 'ihm_residues_not_modeled_reason_term_fkey'],
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_seq_id_begin_fkey']
            }, 'RID'],
            'comment': 'type:int4\nThe value of _entity_poly_seq.num must uniquely and sequentially\n identify a record in the ENTITY_POLY_SEQ list.\n\n Note that this item must be a number and that the sequence\n numbers must progress in increasing numerical order.',
            'markdown_name': 'seq id begin'
        },
        {
            'source': [{
                'outbound': ['PDB', 'ihm_residues_not_modeled_seq_id_end_fkey']
            }, 'RID'],
            'comment': 'type:int4\nThe value of _entity_poly_seq.num must uniquely and sequentially\n identify a record in the ENTITY_POLY_SEQ list.\n\n Note that this item must be a number and that the sequence\n numbers must progress in increasing numerical order.',
            'markdown_name': 'seq id end'
        }
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
    em.Key.define(['RID'], constraint_names=[('PDB', 'ihm_residues_not_modeled_RIDkey1')],
                  ),
    em.Key.define(
        ['structure_id', 'id'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_primary_key')],
    ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['RCB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_RCB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['reason'],
        'Vocab',
        'ihm_residues_not_modeled_reason_term', ['ID'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_reason_term_fkey')],
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
        constraint_names=[('PDB', 'ihm_residues_not_modeled_Owner_fkey')],
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
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_RMB_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
    ),
    em.ForeignKey.define(
        ['structure_id'],
        'PDB',
        'entry', ['id'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_structure_id_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='SET NULL',
    ),
    em.ForeignKey.define(
        ['structure_id', 'asym_id'],
        'PDB',
        'struct_asym', ['structure_id', 'id'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_asym_id_fkey')],
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
        ['structure_id', 'model_id'],
        'PDB',
        'ihm_model_list', ['structure_id', 'model_id'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_model_id_fkey')],
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
        ['structure_id', 'comp_id_begin', 'entity_id', 'seq_id_begin'],
        'PDB',
        'entity_poly_seq', ['structure_id', 'mon_id', 'entity_id', 'num'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_mm_poly_res_label_begin_fkey')],
        acls={
            'insert': ['*'],
            'update': ['*']
        },
        on_update='CASCADE',
        on_delete='SET NULL',
    ),
    em.ForeignKey.define(
        ['structure_id', 'comp_id_end', 'entity_id', 'seq_id_end'],
        'PDB',
        'entity_poly_seq', ['structure_id', 'mon_id', 'entity_id', 'num'],
        constraint_names=[('PDB', 'ihm_residues_not_modeled_mm_poly_res_label_end_fkey')],
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

