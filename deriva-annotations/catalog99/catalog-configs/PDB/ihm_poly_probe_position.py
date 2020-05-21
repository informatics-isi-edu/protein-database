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

table_name = 'ihm_poly_probe_position'

schema_name = 'PDB'

column_annotations = {
    'structure_id': {},
    'comp_id': {},
    'description': {},
    'entity_description': {},
    'entity_id': {},
    'id': {},
    'mod_res_chem_comp_descriptor_id': {},
    'modification_flag': {},
    'mut_res_chem_comp_id': {},
    'mutation_flag': {},
    'seq_id': {},
    'Owner': {}
}

column_comment = {
    'structure_id': 'A reference to table entry.id.',
    'comp_id': 'A reference to table chem_comp.id.',
    'description': 'type:text\nAn author provided description for the residue position in the polymer.',
    'entity_description': 'type:text\nDescription of the entity.',
    'entity_id': 'A reference to table entity.id.',
    'id': 'type:int4\nA unique identifier for the category.',
    'mod_res_chem_comp_descriptor_id': 'A reference to table ihm_chemical_component_descriptor.id.',
    'modification_flag': 'type:text\nA flag to indicate whether the residue is chemically modified or not.',
    'mut_res_chem_comp_id': 'A reference to table chem_comp.id.',
    'mutation_flag': 'type:text\nA flag to indicate whether the residue has an engineered mutation or not.',
    'seq_id': 'A reference to table entity_poly_seq.num.',
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
        'comp_id', em.builtin_types['text'], nullok=False, comment=column_comment['comp_id'],
    ),
    em.Column.define(
        'description', em.builtin_types['text'], comment=column_comment['description'],
    ),
    em.Column.define(
        'entity_description',
        em.builtin_types['text'],
        comment=column_comment['entity_description'],
    ),
    em.Column.define(
        'entity_id', em.builtin_types['text'], nullok=False, comment=column_comment['entity_id'],
    ),
    em.Column.define('id', em.builtin_types['int4'], nullok=False, comment=column_comment['id'],
                     ),
    em.Column.define(
        'mod_res_chem_comp_descriptor_id',
        em.builtin_types['int4'],
        comment=column_comment['mod_res_chem_comp_descriptor_id'],
    ),
    em.Column.define(
        'modification_flag',
        em.builtin_types['text'],
        nullok=False,
        comment=column_comment['modification_flag'],
    ),
    em.Column.define(
        'mut_res_chem_comp_id',
        em.builtin_types['text'],
        comment=column_comment['mut_res_chem_comp_id'],
    ),
    em.Column.define(
        'mutation_flag',
        em.builtin_types['text'],
        nullok=False,
        comment=column_comment['mutation_flag'],
    ),
    em.Column.define(
        'seq_id', em.builtin_types['int4'], nullok=False, comment=column_comment['seq_id'],
    ),
    em.Column.define('Owner', em.builtin_types['text'], comment=column_comment['Owner'],
                     ),
    em.Column.define('Entry_Related_File', em.builtin_types['text'],
                     ),
]

visible_columns = {
    '*': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_poly_probe_position_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'id', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'entity_id'
            ],
            'comment': 'A reference to table entity.id.',
            'markdown_name': 'entity id'
        }, 'entity_description', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'num'
            ],
            'comment': 'A reference to table entity_poly_seq.num.',
            'markdown_name': 'seq id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'mon_id'
            ],
            'comment': 'A reference to table entity_poly_seq.mon_id.',
            'markdown_name': 'comp id'
        }, ['PDB', 'ihm_poly_probe_position_mutation_flag_fkey'], {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mut_res_chem_comp_id_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table chem_comp.id.',
            'markdown_name': 'mut res chem comp id'
        }, ['PDB', 'ihm_poly_probe_position_modification_flag_fkey'], {
            'source': [
                {
                    'outbound': [
                        'PDB', 'ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey'
                    ]
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_chemical_component_descriptor.id.',
            'markdown_name': 'mod res chem comp descriptor id'
        }, 'description', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to the polymeric residue composite key',
            'markdown_name': 'polymeric residue'
        }, ['PDB', 'ihm_poly_probe_position_Entry_Related_File_fkey']
    ],
    'entry': [
        {
            'source': [{
                'outbound': ['PDB', 'ihm_poly_probe_position_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'id', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'entity_id'
            ],
            'comment': 'A reference to table entity.id.',
            'markdown_name': 'entity id'
        }, 'entity_description', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'num'
            ],
            'comment': 'A reference to table entity_poly_seq.num.',
            'markdown_name': 'seq id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'mon_id'
            ],
            'comment': 'A reference to table entity_poly_seq.mon_id.',
            'markdown_name': 'comp id'
        }, ['PDB', 'ihm_poly_probe_position_mutation_flag_fkey'], {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mut_res_chem_comp_id_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table chem_comp.id.',
            'markdown_name': 'mut res chem comp id'
        }, ['PDB', 'ihm_poly_probe_position_modification_flag_fkey'], {
            'source': [
                {
                    'outbound': [
                        'PDB', 'ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey'
                    ]
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_chemical_component_descriptor.id.',
            'markdown_name': 'mod res chem comp descriptor id'
        }, 'description', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to the polymeric residue composite key',
            'markdown_name': 'polymeric residue'
        }
    ],
    'detailed': [
        'RID', {
            'source': [{
                'outbound': ['PDB', 'ihm_poly_probe_position_structure_id_fkey']
            }, 'RID'],
            'comment': 'A reference to table entry.id.',
            'markdown_name': 'structure id'
        }, 'id', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'entity_id'
            ],
            'comment': 'A reference to table entity.id.',
            'markdown_name': 'entity id'
        }, 'entity_description', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'num'
            ],
            'comment': 'A reference to table entity_poly_seq.num.',
            'markdown_name': 'seq id'
        }, {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'mon_id'
            ],
            'comment': 'A reference to table entity_poly_seq.mon_id.',
            'markdown_name': 'comp id'
        }, ['PDB', 'ihm_poly_probe_position_mutation_flag_fkey'], {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mut_res_chem_comp_id_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to table chem_comp.id.',
            'markdown_name': 'mut res chem comp id'
        }, ['PDB', 'ihm_poly_probe_position_modification_flag_fkey'], {
            'source': [
                {
                    'outbound': [
                        'PDB', 'ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey'
                    ]
                }, 'RID'
            ],
            'comment': 'A reference to table ihm_chemical_component_descriptor.id.',
            'markdown_name': 'mod res chem comp descriptor id'
        }, 'description', {
            'source': [
                {
                    'outbound': ['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']
                }, 'RID'
            ],
            'comment': 'A reference to the polymeric residue composite key',
            'markdown_name': 'polymeric residue'
        }, ['PDB', 'ihm_poly_probe_position_Entry_Related_File_fkey'],
        ['PDB', 'ihm_poly_probe_position_RCB_fkey'], ['PDB', 'ihm_poly_probe_position_RMB_fkey'],
        'RCT', 'RMT', ['PDB', 'ihm_poly_probe_position_Owner_fkey']
    ]
}

visible_foreign_keys = {
    'filter': 'detailed',
    'detailed': [['PDB', 'ihm_poly_probe_conjugate_position_id_fkey']]
}

table_annotations = {
    chaise_tags.visible_columns: visible_columns,
    chaise_tags.visible_foreign_keys: visible_foreign_keys,
}

table_comment = 'Specific residue positions in the polymeric entity where probes are covalently attached'

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
        'projection': [
            {
                'outbound': ['PDB', 'ihm_poly_probe_position_structure_id_fkey']
            }, {
                'outbound': ['PDB', 'entry_workflow_status_fkey']
            }, {
                'filter': 'Name',
                'operand': 'REL',
                'operator': '='
            }, 'RID'
        ],
        'projection_type': 'nonnull'
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
                'outbound': ['PDB', 'ihm_poly_probe_position_structure_id_fkey']
            }, {
                'outbound': ['PDB', 'entry_workflow_status_fkey']
            }, {
                'or': [
                    {
                        'filter': 'Name',
                        'operand': 'DRAFT',
                        'operator': '='
                    }, {
                        'filter': 'Name',
                        'operand': 'DEPO',
                        'operator': '='
                    }
                ]
            }, 'RCB'
        ],
        'projection_type': 'acl'
    }
}

key_defs = [
    em.Key.define(
        ['structure_id', 'id'], constraint_names=[['PDB', 'ihm_poly_probe_position_primary_key']],
    ),
    em.Key.define(['RID'], constraint_names=[['PDB', 'ihm_poly_probe_position_RIDkey1']],
                  ),
]

fkey_defs = [
    em.ForeignKey.define(
        ['RMB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_RMB_fkey']],
    ),
    em.ForeignKey.define(
        ['RCB'],
        'public',
        'ERMrest_Client', ['ID'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_RCB_fkey']],
    ),
    em.ForeignKey.define(
        ['modification_flag'],
        'Vocab',
        'ihm_poly_probe_position_modification_flag', ['ID'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_modification_flag_fkey']],
    ),
    em.ForeignKey.define(
        ['mutation_flag'],
        'Vocab',
        'ihm_poly_probe_position_mutation_flag', ['ID'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_mutation_flag_fkey']],
    ),
    em.ForeignKey.define(
        ['Entry_Related_File'],
        'PDB',
        'Entry_Related_File', ['RID'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_Entry_Related_File_fkey']],
        on_delete='CASCADE',
    ),
    em.ForeignKey.define(
        ['structure_id', 'mut_res_chem_comp_id'],
        'PDB',
        'chem_comp', ['structure_id', 'id'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_mut_res_chem_comp_id_fkey']],
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
        ['mod_res_chem_comp_descriptor_id', 'structure_id'],
        'PDB',
        'ihm_chemical_component_descriptor', ['id', 'structure_id'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey']],
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
        ['structure_id'],
        'PDB',
        'entry', ['id'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_structure_id_fkey']],
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
        constraint_names=[['PDB', 'ihm_poly_probe_position_Owner_fkey']],
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
        ['comp_id', 'entity_id', 'structure_id', 'seq_id'],
        'PDB',
        'entity_poly_seq', ['mon_id', 'entity_id', 'structure_id', 'num'],
        constraint_names=[['PDB', 'ihm_poly_probe_position_mm_poly_res_label_fkey']],
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
    catalog_id = 99
    mode, replace, host, catalog_id = parse_args(host, catalog_id, is_table=True)
    catalog = ErmrestCatalog('https', host, catalog_id=catalog_id, credentials=get_credential(host))
    main(catalog, mode, replace)
