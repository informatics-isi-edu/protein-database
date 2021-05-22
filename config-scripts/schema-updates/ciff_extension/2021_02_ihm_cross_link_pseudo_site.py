import sys
import json
from deriva.core import ErmrestCatalog, AttrDict, get_credential, DEFAULT_CREDENTIAL_FILE, tag, urlquote, DerivaServer, get_credential, BaseCLI
from deriva.core.ermrest_model import builtin_types, Schema, Table, Column, Key, ForeignKey, DomainType, ArrayType
import utils


# ========================================================
# -- create a table that is not a Vocab structure
def define_tdoc_ihm_cross_link_pseudo_site():
    table_name='ihm_cross_link_pseudo_site'
    comment='Details of pseudo sites involved in crosslinks; can be uploaded as CSV/TSV file above; mmCIF category: ihm_cross_link_pseudo_site'

    column_defs = [
        Column.define(
            "id",
            builtin_types.int8,
            comment='An identifier for a pseudo site involved in a crosslink',
            nullok=False
        ),
        Column.define(
            "restraint_id",
            builtin_types.int8,
            comment='An identifier for the crosslink restraint between a pair of residues',
            nullok=False
        ),
        Column.define(
            "cross_link_partner",
            builtin_types.text,
            comment='The identity of the crosslink partner corresponding to the pseudo site',
            nullok=False
        ),
        Column.define(
            "pseudo_site_id",
            builtin_types.int8,
            comment='The pseudo site identifier corresponding to the crosslink partner',
            nullok=False
        ),
        Column.define(
            "model_id",
            builtin_types.int8,
            comment='Identifier to the model that the pseudo site corresponds to',
            nullok=True
        ),
        Column.define(
            "Entry_Related_File",
            builtin_types.text,
            comment='A reference to the uploaded restraint file in the table Entry_Related_File.id.',
            nullok=True
        ),
        Column.define(
            "structure_id",
            builtin_types.text,
            comment='Structure identifier',
            nullok=False
        ),
        # HT: to use for Chaise
        Column.define(
            "Model_RID",
            builtin_types.text,
            comment='Identifier to the model RID',
            nullok=True
        ),
        Column.define(
            "Pseudo_Site_RID",
            builtin_types.text,
            comment='Identifier to the pseudo site RID',
            nullok=False
        ),
        Column.define(
            "Restraint_RID",
            builtin_types.text,
            comment='Identifier to the restraint RID',
            nullok=False
        )
    ]
    #BV: This is a leaf table; so no combo1/combo2 keys required
    key_defs = [
        Key.define(["structure_id", "id"], constraint_names=[["PDB", "ihm_cross_link_pseudo_site_primary_key"]] ),
        Key.define(["RID"], constraint_names=[["PDB", "ihm_cross_link_pseudo_site_RID_key"]] ),
    ]

    # @brinda: add fk pseudo-definition
    fkey_defs = [
        # HT: it own fk to Entry table
        ForeignKey.define(["structure_id"], "PDB", "entry", ["id"],
                          constraint_names=[["PDB", "ihm_cross_link_pseudo_site_structure_id_fkey"]],
                          on_update="CASCADE",
                          on_delete="NO ACTION"
        ),
        # -- begin ihm_cross_link_restraint
        # HT: In annotation, apply domain_filter to filter the RID list by constraining structure_id        
        ForeignKey.define(["Restraint_RID", "structure_id", "restraint_id"], "PDB", "ihm_cross_link_restraint", ["RID", "structure_id", "id"],
                          constraint_names=[["PDB", "ihm_cross_link_pseudo_site_ihm_cross_link_restraint_combo1_fkey"]],
                          on_update="CASCADE",
                          on_delete="NO ACTION"
        ),
        # -- end ihm_cross_link_restraint         
        # -- begin ihm_model_list table
        # HT: This is for chaise optional foreign key --> check naming convention
        # HT: In annotation, apply domain_filter to filter the RID list by constraining structure_id
        # BV: Not required anymore based on the google doc with fkey conventions
        #ForeignKey.define(["Model_RID"], "PDB", "ihm_model_list", ["RID"],
        #                  constraint_names=[["PDB", "ihm_cross_link_pseudo_site_Model_RID_fkey"]],
        #                  on_update="CASCADE",
        #                  on_delete="NO ACTION"
        #),
        # HT: equivalent fk so that Chaise will automatically fill in automatically --> check constraint naming convention
        ForeignKey.define(["Model_RID", "model_id"], "PDB", "ihm_model_list", ["RID", "model_id"],
                          constraint_names=[["PDB", "ihm_cross_link_pseudo_site_ihm_model_list_combo2_fkey"]],
                          on_update="CASCADE",
                          on_delete="NO ACTION"
        ),
        # -- end ihm_model_list table
        ForeignKey.define(["Pseudo_Site_RID", "structure_id", "pseudo_site_id"], "PDB", "ihm_pseudo_site", ["RID", "structure_id", "id"],
                          constraint_names=[["PDB", "ihm_cross_link_pseudo_site_ihm_pseudo_site_combo1_fkey"]],
                          on_update="CASCADE",
                          on_delete="NO ACTION"
        ),
        ForeignKey.define(["cross_link_partner"], "Vocab", "cross_link_partner", ["Name"],
                          constraint_names=[ ["Vocab", "ihm_cross_link_pseudo_site_cross_link_partner_fkey"] ],
                          on_update="CASCADE",
                          on_delete="NO ACTION"
        ),
        ForeignKey.define(["Entry_Related_File"], "PDB", "Entry_Related_File", ["RID"],
                          constraint_names=[["PDB", "ihm_cross_link_pseudo_site_Entry_Related_File_fkey"]],
                          on_update="CASCADE",
                          on_delete="NO ACTION"
        )

    ]

    table_def = Table.define(
        table_name,
        column_defs,
        key_defs=key_defs,
        fkey_defs=fkey_defs,
        comment=comment,
        provide_system=True
    )

    return table_def


# ==========================================================================
# update existing table

# ---------------
def update_PDB_ihm_cross_link_restraint(model):
    #table = model("PDB", "ihm_cross_link_restraint")
    table = model.schemas['PDB'].tables['ihm_cross_link_restraint']
    
    # Add the PDB.ihm_cross_link_restraint.pseudo_site_flag column    
    #table.create_column(
    #    Column.define(
    #        "pseudo_site_flag",
    #        builtin_types.text,
    #        comment='A flag indicating if the cross link involves a pseudo site that is not part of the model representation',
    #        nullok=True
    #    )
    #)

    # Create the foreign key PDB.ihm_cross_link_restraint.pseudo_site_flag references Vocab.pseudo_site_flag.Name
    #table.create_fkey(
    #    ForeignKey.define(["pseudo_site_flag"], "Vocab", "pseudo_site_flag", ["Name"],
    #                      constraint_names=[ ["Vocab", "ihm_cross_link_restraint_pseudo_site_flag_fkey"] ],
    #                      on_update="CASCADE",
    #                      on_delete="NO ACTION")
    #)

    # Create combo1 key
    table.create_key(
        Key.define(["RID", "structure_id", "id"], constraint_names=[["PDB", "ihm_cross_link_restraint_combo1_key"]] )    
    )


# ==========================================================================
# upload vocab table

# add rows to Vocab.ihm_cross_link_list_linker_type table
def add_rows_to_Vocab_ihm_cross_link_list_linker_type(catalog):

    rows =[
        {'Name': 'CYS', 'Description': 'CYS'},
        {'Name': 'BMSO', 'Description': 'BMSO'},
        {'Name': 'DHSO', 'Description': 'DHSO'}
    ]
    
    pb = catalog.getPathBuilder()
    schema = pb.Vocab
    ihm_cross_link_list_linker_type = schema.ihm_cross_link_list_linker_type
    ihm_cross_link_list_linker_type.insert(rows, defaults=['ID', 'URI'])

# -----------------------------------
# add rows to Vocab.cross_link_partner
def add_rows_to_Vocab_cross_link_partner(catalog):    #@serban to review

    rows =[
        {'Name': '1', 'Description': 'The first partner in the crosslink as identified in the ihm_cross_link_restraint table'},
        {'Name': '2', 'Description': 'The second partner in the crosslink as identified in the ihm_cross_link_restraint table'}
    ]

    pb = catalog.getPathBuilder()
    schema = pb.Vocab
    cross_link_partner = schema.cross_link_partner
    cross_link_partner.insert(rows, defaults=['ID', 'URI'])


# ============================================================
def main(server_name, catalog_id, credentials):
    server = DerivaServer('https', server_name, credentials)
    catalog = server.connect_ermrest(catalog_id)
    catalog.dcctx['cid'] = "oneoff/model"
    model = catalog.getCatalogModel()
    
    #-- clean up
    if False:
        drop_table(catalog, 'PDB', 'ihm_cross_link_pseudo_site') 
    
    # new changes
    if True:
        model = catalog.getCatalogModel()    
    
        create_table_if_not_exist(model, "Vocab",  define_Vocab_table('cross_link_partner', 'Identity of the crosslink partner'))
        create_table_if_not_exist(model, "Vocab",  define_Vocab_table('pseudo_site_flag', 'Flag for crosslinks involving pseudo sites'))
        create_table_if_not_exist(model, "PDB",  define_tdoc_ihm_cross_link_pseudo_site())
        
        update_PDB_ihm_cross_link_restraint(model)
    
    # vocab
    if False:
        add_rows_to_Vocab_ihm_cross_link_list_linker_type(catalog)
        add_rows_to_Vocab_cross_link_partner(catalog)
    

# ===================================================    

if __name__ == '__main__':
    args = BaseCLI("ad-hoc table creation tool", None, 1).parse_cli()
    credentials = get_credential(args.host, args.credential_file)
#    if args.catalog is None:
#        catalog_id = 99

    main(args.host, 99, credentials)
    