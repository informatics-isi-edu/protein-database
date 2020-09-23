from deriva.core import DerivaServer, get_credential, BaseCLI
from deriva.core.ermrest_model import Table, Column, Key, ForeignKey, builtin_types

def table_comments(model):
    #table = model.table("PDB", "software")
    #table.comment = "List of software used in the modeling"
    #table.column_definitions["Species_Tested_In"].comment = None

    model.table("PDB", "entry").comment = "List of user owned entries in PDB-Dev"
    model.table("PDB", "Entry_mmCIF_File").comment = "System generated mmCIF file based on all the data provided by the user"
    model.table("PDB", "struct").comment = "Description of the structure"
    model.table("PDB", "audit_author").comment = "Authors of the structure"
    model.table("PDB", "citation").comment = "Citation information for the primary publication as well as other relevant software and methodology"
    model.table("PDB", "citation_author").comment = "Authors associated with publications in the citation list"
    model.table("PDB", "software").comment = "List of software used in the modeling"
    model.table("PDB", "chem_comp").comment = "Chemical components present in the structure including monomers and ligands"
    model.table("PDB", "entity").comment = "Details of chemically distinct molecular entities present in the structure"
    model.table("PDB", "entity_name_com").comment = "Common names associated with the molecular entities"
    model.table("PDB", "entity_name_sys").comment = "Systematic names associated with the molecular entities"
    model.table("PDB", "entity_src_gen").comment = "Details of the source from which genetically manipulated entities are obtained"
    model.table("PDB", "entity_poly").comment = "Details of polymeric entities"
    model.table("PDB", "pdbx_entity_nonpoly").comment = "Details of non-polymeric entities"
    model.table("PDB", "entity_poly_seq").comment = "Sequence of monomers in polymeric entities"
    model.table("PDB", "atom_type").comment = "Types of atoms in the structure"
    model.table("PDB", "struct_asym").comment = "Instances of polymeric and non-polymeric entities present in the structure submitted"
    model.table("PDB", "ihm_dataset_list").comment = "List of all input datasets used in the integrative modeling study, including data from different types of experiments and starting models from different sources"
    model.table("PDB", "ihm_dataset_group").comment = "Groups or collections of input datasets used in different steps in the modeling protocol, post modeling analysis, or validation"
    model.table("PDB", "ihm_dataset_group_link").comment = "Table to link input datasets with the dataset groups"
    model.table("PDB", "ihm_related_datasets").comment = "Information about related datasets, where one is derived from the other"
    model.table("PDB", "ihm_dataset_related_db_reference").comment = "Details of input datasets archived in other repositories, including experimental data and starting structural models"
    model.table("PDB", "ihm_external_reference_info").comment = "Details of experimental data not available from an external repository, linked via a digital object identifier (DOI)"
    model.table("PDB", "ihm_external_files").comment = "External files associated with datasets linked via DOI"
    model.table("PDB", "ihm_dataset_external_reference").comment = "Table to connect external files linked via DOI to the input datasets used in the integrative modeling study"
    model.table("PDB", "ihm_entity_poly_segment").comment = "Segments of polymeric entities; specifies sequence ranges for use in other tables that describe structure assemblies, starting structural models, and model representations"
    model.table("PDB", "ihm_struct_assembly").comment = "List of structure assemblies in the models submitted"
    model.table("PDB", "ihm_struct_assembly_details").comment = "Details of structural assemblies in the models submitted"
    model.table("PDB", "ihm_struct_assembly_class").comment = "List of structural assembly classes; allows for defining hierarchical structural assemblies"
    model.table("PDB", "ihm_struct_assembly_class_link").comment = "Table to link structural assemblies to the assembly classes"
    model.table("PDB", "ihm_starting_model_details").comment = "Information regarding starting structural models used in the integrative modeling study"
    model.table("PDB", "ihm_starting_comparative_models").comment = "Additional information regarding comparative models used as starting structural models"
    model.table("PDB", "ihm_starting_computational_models").comment = "Generic information regarding all computational models used as starting structural models"
    model.table("PDB", "ihm_starting_model_seq_dif").comment = "Information regarding point mutations in the sequences of the starting models compared to the starting model in the reference database"
    model.table("PDB", "ihm_model_representation").comment = "List of model representations used"
    model.table("PDB", "ihm_model_representation_details").comment = "Details of model representations used; addresses representations of multi-scale models with atomic and coarse-grained representations"
    model.table("PDB", "ihm_modeling_protocol").comment = "List of modeling protocols used in the integrative modeling study"
    model.table("PDB", "ihm_modeling_protocol_details").comment = "Details of the different steps in the modeling protocols used in the integrative modeling study"
    model.table("PDB", "ihm_modeling_post_process").comment = "Post modeling analysis (clustering, validation) of the models resulting from the modeling protocols"
    model.table("PDB", "ihm_model_list").comment = "List of models submitted"
    model.table("PDB", "ihm_model_group").comment = "Collections or groups of models that can be used for defining clusters, multi-state models or ordered ensembles"
    model.table("PDB", "ihm_model_group_link").comment = "Table to assign models belonging to a model group"
    model.table("PDB", "ihm_model_representative").comment = "Representative model in a model group, ensemble or cluster"
    model.table("PDB", "ihm_residues_not_modeled").comment = "Residues present in the structure assembly but missing in the 3D model"
    model.table("PDB", "ihm_multi_state_modeling").comment = "Details of multi-state modeling"
    model.table("PDB", "ihm_multi_state_model_group_link").comment = "Table to link model groups to a model state"
    model.table("PDB", "ihm_ordered_ensemble").comment = "Details of model ensembles related by time or other order; model groups are represented as nodes with directed edges between them indicating the ordering"
    model.table("PDB", "ihm_ensemble_info").comment = "Details of model ensembles"
    model.table("PDB", "ihm_localization_density_files").comment = "Details of external files referenced via DOI that provide information regarding localization densities of ensembles"
    model.table("PDB", "ihm_2dem_class_average_restraint").comment = "2DEM images used as restraints in the modeling"
    model.table("PDB", "ihm_2dem_class_average_fitting").comment = "Fitting of output models to 2DEM images used as restraints in the modeling"
    model.table("PDB", "ihm_3dem_restraint").comment = "Details of 3DEM maps used as restraints in the modeling"
    model.table("PDB", "ihm_sas_restraint").comment = "Data from SAS experiments used as restraints in the modeling"
    model.table("PDB", "ihm_epr_restraint").comment = "Data from EPR experiments used as restraints in the modeling"
    model.table("PDB", "ihm_chemical_component_descriptor").comment = "Chemical descriptors (SMILES/INCHI) of molecular probes used in experiments (CX-MS, FRET, EPR etc.)"
    model.table("PDB", "ihm_probe_list").comment = "List of molecular probes used in experiments"
    model.table("PDB", "ihm_poly_probe_position").comment = "Specific residue positions in the polymeric entity where probes are covalently attached; can be uploaded as CSV/TSV file below in the 'Uploaded Restraint Files' table"
    model.table("PDB", "ihm_poly_probe_conjugate").comment = "Description of molecular probes that are covalently attached to residues in polymeric entities; can be uploaded as CSV/TSV file below in the 'Uploaded Restraint Files' table"
    model.table("PDB", "ihm_ligand_probe").comment = "Details of non-covalently interacting ligands used as molecular probes; can be uploaded as CSV/TSV file below in the 'Uploaded Restraint Files' table"
    model.table("PDB", "ihm_geometric_object_list").comment = "List of geometric objects used as part of restraints in the modeling, e.g., cellular envelope represented as a sphere or half-torus"
    model.table("PDB", "ihm_geometric_object_center").comment = "Centers of geometric objects"
    model.table("PDB", "ihm_geometric_object_transformation").comment = "Transformations applied to geometric objects"
    model.table("PDB", "ihm_geometric_object_sphere").comment = "Details of geometric objects that are spheres"
    model.table("PDB", "ihm_geometric_object_torus").comment = "Details of geometric objects that are shaped as a torus"
    model.table("PDB", "ihm_geometric_object_half_torus").comment = "Details of geometric objects that are shaped as a half-torus"
    model.table("PDB", "ihm_geometric_object_plane").comment = "Details of geometric objects that are planes"
    model.table("PDB", "ihm_geometric_object_axis").comment = "Details of geometric objects that are axes"
    model.table("PDB", "Entry_Related_File").comment = "Uploaded restraint data files (in csv/tsv format) related to the entry. Crosslinking restraints, predicted contacts, generic distance restraints etc. can be uploaded as CSV/TSV files in the correct format. The appropriate tables will be populated based on the uploaded data. Templates for the CSV files can be downloaded from https://pdb.isrd.isi.edu/chaise/recordset/#99/PDB:Entry_Related_File_Templates?pcid=navbar/record&ppid=2kcj1s7w2qrm1zyk1qju2ne7"
    model.table("PDB", "ihm_cross_link_list").comment = "List of distance restraints obtained from chemical crosslinking experiments; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_cross_link_restraint").comment = "Restraints derived from chemical crosslinking data applied in the integrative modeling study; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_cross_link_result").comment = "Results of crosslinking restraints used in integrative modeling; e.g., satisfied/violated crosslinks in models/ensembles submitted; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_cross_link_result_parameters").comment = "Parameters associated with the results of crosslinking restraints used in integrative modeling; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_predicted_contact_restraint").comment = "Restraints derived from predicted contacts from evolutionary data or other information; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_hydroxyl_radical_fp_restraint").comment = "Data from hydroxyl radical footprinting experiments used as restraint in the modeling; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_feature_list").comment = "List of molecular features (atoms, residues, residue ranges, non-polymeric entities, pseudo sites) used in generic distance restraints in the modeling; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_poly_atom_feature").comment = "Details of molecular features comprising of polymeric atoms; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_poly_residue_feature").comment = "Details of molecular features comprising of polymeric residues and residue ranges; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_non_poly_feature").comment = "Details of molecular features comprising of non-polymeric entities or ligands; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_interface_residue_feature").comment = "Details of molecular features comprising of residues at the binding interface identified from experiments; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_pseudo_site_feature").comment = "Details of pseudo site features used in generic distance restraints; can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_derived_distance_restraint").comment = "Details of generic distance restraints between molecular features (atoms, residues, residue ranges, non-polymeric entities, pseudo sites); can be uploaded as CSV/TSV file above"
    model.table("PDB", "ihm_geometric_object_distance_restraint").comment = "Generic distance restraints between geometric objects (spheres, torus, half-torus, plane, axis) and molecular features (atoms, residues, residue ranges, non-polymeric entities, pseudo sites); can be uploaded as CSV/TSV file above"
    model.table("PDB", "audit_conform").comment = "Dictionary versions against which the data items in the current data block are conformant"
    model.table("PDB", "chem_comp_atom").comment = "Details of atoms in chemical components"
    model.table("PDB", "pdbx_entity_poly_na_type").comment = "Details of nucleic acid polymeric entity types"
    model.table("PDB", "pdbx_entry_details").comment = "Additional details about the entry"
    model.table("PDB", "pdbx_inhibitor_info").comment = "Details of Inhibitors in the Entry"
    model.table("PDB", "pdbx_ion_info").comment = "Details of Ions in the Entry"
    model.table("PDB", "pdbx_protein_info").comment = "Details of Proteins in the Entry"

def column_comments(model):

    model.table("PDB", "software").column_definitions["citation_id"].comment = "Citation corresponding to the software; a reference to the citation id in the citation table"
    model.table("PDB", "Entry_Related_File").column_definitions["File_Type"].comment = "Restraint table corresponding to the uploaded file"
    model.table("PDB", "Entry_Related_File").column_definitions["File_Format"].comment = "CSV or TSV file format"
    model.table("PDB", "Entry_Related_File").column_definitions["File_URL"].comment = "URL of the uploaded file"
    model.table("PDB", "Entry_Related_File").column_definitions["Description"].comment = "Description of the file"
    model.table("PDB", "Entry_Related_File").column_definitions["Workflow_Status"].comment = "Workflow status corresponding to uploading restraint data files"
    model.table("PDB", "Entry_Related_File").column_definitions["Record_Status_Detail"].comment = "Captures error messages obtained while processing the uploaded restraint data files; remains empty if process is success"
    model.table("PDB", "Entry_Related_File").column_definitions["File_Bytes"].comment = "Size of the uploaded file in bytes"
    model.table("PDB", "Entry_Related_File").column_definitions["File_MD5"].comment = "MD5 value of the uploaded file"
    model.table("PDB", "Entry_Related_File").column_definitions["structure_id"].comment = "A reference to the entry.id identifier in the entry table"
    model.table("PDB", "entry").column_definitions["Image_File_URL"].comment = "URL of the uploaded image file"
    model.table("PDB", "entry").column_definitions["Image_File_Bytes"].comment = "Size of the uploaded image file in bytes"
    model.table("PDB", "entry").column_definitions["mmCIF_File_URL"].comment = "URL of the uploaded mmCIF file"
    model.table("PDB", "entry").column_definitions["mmCIF_File_Bytes"].comment = "Size of the uploaded mmCIF file in bytes"
    model.table("PDB", "entry").column_definitions["Workflow_Status"].comment = "Workflow status corresponding to the entry"
    model.table("PDB", "entry").column_definitions["accession_code"].comment = "Accession code issued by the archive after processing the entry"
    model.table("PDB", "entry").column_definitions["Record_Status_Detail"].comment = "Captures error messages obtained while processing the uploaded mmCIF files; remain empty if process is success"
    model.table("PDB", "entry").column_definitions["Generated_mmCIF_Processing_Status"].comment = "Indicates whether the status of processing the uploaded mmCIF file is success or failure"
    model.table("PDB", "Entry_mmCIF_File").column_definitions["File_URL"].comment = "URL of the system generated mmCIF file"
    model.table("PDB", "Entry_mmCIF_File").column_definitions["mmCIF_Schema_Version"].comment = "Schema version of mmCIF IHM extension dictionary"
    model.table("PDB", "Entry_mmCIF_File").column_definitions["Structure_Id"].comment = "A reference to the entry.id identifier in the entry table"
    model.table("PDB", "Entry_mmCIF_File").column_definitions["File_Bytes"].comment = "Size of the system generated mmCIF file in bytes"
    model.table("PDB", "Entry_mmCIF_File").column_definitions["File_MD5"].comment = "MD5 value of the system generated mmCIF file"

# ===================================================
# -- this function will be called from the update_schemas.py file

def set_comments(model):
    table_comments(model)
    column_comments(model)


# ===================================================    
def main(server_name, catalog_id, credentials):
    server = DerivaServer('https', server_name, credentials)
    catalog = server.connect_ermrest(catalog_id)
    catalog.dcctx['cid'] = "oneoff/model"
    model = catalog.getCatalogModel()

    set_comments(model)

    # let's the library deals with applying the difference
    model.apply()

# ===================================================    

if __name__ == '__main__':
    args = BaseCLI("ad-hoc table creation tool", None, 1).parse_cli()
    credentials = get_credential(args.host, args.credential_file)
#    if args.catalog is None:
#        catalog_id = 99

    main(args.host, 99, credentials)
    
    
