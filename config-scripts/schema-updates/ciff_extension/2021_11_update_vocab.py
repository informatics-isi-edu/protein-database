import sys
import json
from deriva.core import get_credential, DerivaServer, BaseCLI
from deriva.core.ermrest_model import Key
import utils

# add scripts for updating vocabs that has nothing to do with mmcif model changes.

cross_link_partner_rows =[
    {'Name': '1', 'Description': 'The first partner in the crosslink as identified in the ihm_cross_link_restraint table'},
    {'Name': '2', 'Description': 'The second partner in the crosslink as identified in the ihm_cross_link_restraint table'}
]

sub_sample_flag_rows =[
    {'Name': 'Yes', 'Description': 'Ensemble consists of sub samples'},
    {'Name': 'No', 'Description': 'Ensemble does not consist of sub samples'}
]

sub_sampling_type_rows =[
    {'Name': 'random', 'Description': 'sub samples generated by randomly partitioning all structures in the group'},
    {'Name': 'independent', 'Description': 'each sub sample generated in the same fashion but in independent simulations'},
    {'Name': 'other', 'Description': 'other type of sub sampling'}
]

pseudo_site_flag_rows =[
    {'Name': 'Yes', 'Description': 'Crosslink involves a pseudo site'},
    {'Name': 'No', 'Description': 'Crosslink does not involve a pseudo site'}
]

ihm_derived_angle_restraint_group_conditionality_rows =[
    {'Name': 'ALL', 'Description': 'All angles in the group are required to be satisfied'},
    {'Name': 'ANY', 'Description': 'Any one of the angles in the group could be satisfied'}
]

ihm_derived_angle_restraint_restraint_type_rows =[
    {'Name': 'lower bound', 'Description': 'lower bound'},
    {'Name': 'upper bound', 'Description': 'upper bound'},
    {'Name': 'lower and upper bound', 'Description': 'lower and upper bound'},
    {'Name': 'harmonic', 'Description': 'harmonic'}
]

ihm_derived_dihedral_restraint_group_conditionality_rows =[
    {'Name': 'ALL', 'Description': 'All dihedrals in the group are required to be satisfied'},
    {'Name': 'ANY', 'Description': 'Any one of the dihedrals in the group could be satisfied'}
]

ihm_derived_dihedral_restraint_restraint_type_rows =[
    {'Name': 'lower bound', 'Description': 'lower bound'},
    {'Name': 'upper bound', 'Description': 'upper bound'},
    {'Name': 'lower and upper bound', 'Description': 'lower and upper bound'},
    {'Name': 'harmonic', 'Description': 'harmonic'}
]

def main(server_name, catalog_id, credentials):
    server = DerivaServer('https', server_name, credentials)
    catalog = server.connect_ermrest(catalog_id)
    catalog.dcctx['cid'] = "oneoff/model"
    model = catalog.getCatalogModel()
    
    """
    Create the new vocabulary tables
    """
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('cross_link_partner', 'Identity of the crosslink partner'))
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('sub_sample_flag', 'Flag for ensembles consisting of sub samples'))
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('sub_sampling_type', 'Types of sub samples in ensembles'))
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('pseudo_site_flag', 'Flag for crosslinks involving pseudo sites'))
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('ihm_derived_angle_restraint_group_conditionality', 'Conditionality of a group of angles restrained together'))
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('ihm_derived_angle_restraint_restraint_type', 'The type of angle restraint'))
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('ihm_derived_dihedral_restraint_group_conditionality', 'Conditionality of a group of dihedrals restrained together'))
    utils.create_table_if_not_exist(model, 'Vocab', utils.define_Vocab_table('ihm_derived_dihedral_restraint_restraint_type', 'The type of dihedral restraint'))

    """
    Load data into the new vocabulary tables
    """
    utils.add_rows_to_vocab_table(catalog, 'cross_link_partner', cross_link_partner_rows)
    utils.add_rows_to_vocab_table(catalog, 'sub_sample_flag', sub_sample_flag_rows)
    utils.add_rows_to_vocab_table(catalog, 'sub_sampling_type', sub_sampling_type_rows)
    utils.add_rows_to_vocab_table(catalog, 'pseudo_site_flag', pseudo_site_flag_rows)
    utils.add_rows_to_vocab_table(catalog, 'ihm_derived_angle_restraint_group_conditionality', ihm_derived_angle_restraint_group_conditionality_rows)
    utils.add_rows_to_vocab_table(catalog, 'ihm_derived_angle_restraint_restraint_type', ihm_derived_angle_restraint_restraint_type_rows)
    utils.add_rows_to_vocab_table(catalog, 'ihm_derived_dihedral_restraint_group_conditionality', ihm_derived_dihedral_restraint_group_conditionality_rows)
    utils.add_rows_to_vocab_table(catalog, 'ihm_derived_dihedral_restraint_restraint_type', ihm_derived_dihedral_restraint_restraint_type_rows)

if __name__ == '__main__':
    args = BaseCLI("ad-hoc table creation tool", None, 1).parse_cli()
    credentials = get_credential(args.host, args.credential_file)

    main(args.host, 99, credentials)
    
