import sys
import json
from deriva.core import ErmrestCatalog, AttrDict, get_credential, DEFAULT_CREDENTIAL_FILE, tag, urlquote, DerivaServer, get_credential, BaseCLI
from deriva.core.ermrest_model import builtin_types, Schema, Table, Column, Key, ForeignKey, DomainType, ArrayType
#from __builtin__ import False

# ========================================================
# utility

# rename a key
# the key parameter is provided as as a name
# usage example: rename_key(model, 'PDB', 'ihm_model_group', 'ihm_model_group_RID_id_key', 'ihm_model_group_combo1_key')
def rename_key_if_exist(model, schema_name, table_name, old_key_name, new_key_name):
    schema = model.schemas[schema_name]
    table = schema.tables[table_name]
    
    if (schema, old_key_name) in table.keys.elements:
        table.keys[(schema, old_key_name)].alter(constraint_name=new_key_name)
        print("Rename key %s.%s key:%s -> %s" % (schema_name, table_name, old_key_name, new_key_name))

# ---------------------------------------
# check if a key is defined in a table based on column name.
# The main function is Table.key_by_columns(columns, raise_nomatch=True) takes a list (iterable) of Column instances or column name strings and returns the Key instance.
# The option flag changes whether it raises KeyError or returns None if no key is found for those columns.
def exist_key_by_columns(model, schema_name, table_name, key_column_names):
    table = model.schemas[schema_name].tables[table_name]
    return table.key_by_columns(key_column_names, raise_nomatch=False) is not None

# ---------------------------------------
def exist_key_by_name(model, schema_name, table_name, key_name):
    schema = model.schemas[schema_name]
    table = schema.tables[table_name]
    return (schema, key_name) in table.keys.elements

# ---------------------------------------
def exist_fkey_by_name(model, schema_name, table_name, fkey_name):
    schema = model.schemas[schema_name]
    table = schema.tables[table_name]
    return (schema, fkey_name) in table.foreign_keys.elements    


# ---------------------------------------
# check if a foreign key is defined or not in a table
# the key parameter is provided as a list of columns names
# WARNING: HT: This function doesn't do a proper fk checking. DON'T USE
def exist_foreign_key_in_table(model, schema_name, table_name, key):
    if schema_name in model.schemas.keys():
        schema = model.schemas[schema_name]
        if table_name in schema.tables:
            key = sorted(key)
            table = model.schemas[schema_name].tables[table_name]
            for fk in table.foreign_keys:
                foreign_key_columns_names = []
                for col in fk.foreign_key_columns:
                    foreign_key_columns_names.append(col.name)
                if key == sorted(foreign_key_columns_names):
                    return True
    return False

# ---------------------------------------
# drop a table together with the associated reference keys
# WARNING: ONLY USE THIS FUNCTION FOR NEWLY CREATED TABLE
def drop_table(catalog, schema_name, table_name):
    model = catalog.getCatalogModel()
    if schema_name in model.schemas.keys():
        schema = model.schemas[schema_name]
        if table_name in schema.tables:
            ready = False
            while ready == False:
                model = catalog.getCatalogModel()
                table = model.schemas[schema_name].tables[table_name]
                if len(table.referenced_by) == 0:
                    ready = True
                else:
                    for foreign_key in table.referenced_by:
                        foreign_key.drop()
            model = catalog.getCatalogModel()
            table = model.schemas[schema_name].tables[table_name]
            table.drop()

# ---------------------------------------
# create a vocabulary table if it does not exixt
def create_vocabulary_table_if_not_exist(model, schema_name, table_name, comment):
    schema = model.schemas[schema_name]
    if table_name not in schema.tables:
        schema.create_table(Table.define_vocabulary(table_name, 'PDB:{RID}', comment=comment))

# ---------------------------------------
# add table if not exist or update if exist
def create_table_if_not_exist(model, schema_name, tdoc):
    schema = model.schemas[schema_name]
    if tdoc["table_name"] not in schema.tables:
        schema.create_table(tdoc)

# ---------------------------------------
# remove a column if it exists
# if schema_name and table_name are not in the model, throw an error.
def drop_column_if_exist(model, schema_name, table_name, column_name):
    schema = model.schemas[schema_name]
    table = schema.tables[table_name]

    try:
        table.columns[column_name].drop()
        print("Dropped column %s.%s column:%s" % (schema_name, table_name, column_name))        
    except KeyError:
        pass

    # these approach doesn't validate the schema and table names
    #if table_name in model.schemas[schema_name].tables:
    #    table = model.schemas[schema_name].tables[table_name]
    #    if column_name in table.columns.elements:
    #        table.column_definitions[column_name].drop()
    #        print("Dropped column %s.%s.%s" % (schema_name, table_name, column_name))

# ----------------------------------------
# drop fkey if exist
# if schema_name and table_name are not in the model, throw an error.
def drop_fkey_if_exist(model, schema_name, table_name, fkey_name):

    schema = model.schemas[schema_name]
    table = schema.tables[table_name]
    try:
        table.foreign_keys[(schema, fkey_name)].drop()
        print("Dropped fkey %s.%s fkey:%s" % (schema_name, table_name, fkey_name))
    except KeyError:
        pass

# ----------------------------------------
# drop fkey if exist
def drop_key_if_exist(model, schema_name, table_name, key_name):

    schema = model.schemas[schema_name]
    table = schema.tables[table_name]
    try:
        table.keys[(schema, key_name)].drop()
        print("Dropped fkey %s.%s key:%s" % (schema_name, table_name, key_name))
    except KeyError:
        pass


# ---------------------------------------
# define a vocabulary table (with specific structure)
def define_Vocab_table(table_name, table_comment):
    column_defs = [
        Column.define(
            "ID",
            builtin_types.ermrest_curie,
            comment='The preferred Compact URI (CURIE) for this term.',                        
            nullok=False,
            default="PDB:{RID}"
        ),
        Column.define(
            "URI",
            builtin_types.ermrest_uri,            
            nullok=False,
            default="/id/{RID}",
            comment="The preferred URI for this term."
        ),
        Column.define(
            "Name",
            builtin_types.text,
            nullok=False
        ),
        Column.define(
            "Description",
            builtin_types.markdown,
            nullok=False
        ),
        Column.define(
            "Synonyms",
            builtin_types["text[]"],
            nullok=True,
            comment="Alternate human-readable names for this term."
        ),
        Column.define(
            "Owner",
            builtin_types.text,
            comment='Group that can update the record.',                        
            nullok=True
        )
    ]
    
    key_defs = [
        Key.define(["URI"],
                   constraint_names=[["Vocab", '{}_URI_key'.format(table_name)]]
        ),
        Key.define(["Name"],
                   constraint_names=[["Vocab", '{}_Name_key'.format(table_name)]]
        ),
        Key.define(["ID"],
                   constraint_names=[["Vocab", '{}_ID_key'.format(table_name)]]
        ),
        Key.define(["RID"],
                   constraint_names=[["Vocab", '{}_RID_key'.format(table_name)]]
        )
    ]

    fkey_defs = [
        ForeignKey.define(["RCB"], "public", "ERMrest_Client", ["ID"],
                          constraint_names=[["Vocab", '{}_RCB_fkey'.format(table_name)]],
                          on_update="NO ACTION",
                          on_delete="NO ACTION"   
        ),
        ForeignKey.define(["RMB"], "public", "ERMrest_Client", ["ID"],
                          constraint_names=[["Vocab", '{}_RMB_fkey'.format(table_name)]],
                          on_update="NO ACTION",
                          on_delete="NO ACTION"   
        ),
        ForeignKey.define(["Owner"], "public", "Catalog_Group", ["ID"],
                          constraint_names=[["Vocab", '{}_Owner_fkey'.format(table_name)]],
                          on_update="NO ACTION",
                          on_delete="NO ACTION"   
        )
    ]

    table_def = Table.define(
        table_name,
        column_defs,
        key_defs=key_defs,
        fkey_defs=fkey_defs,
        comment=table_comment,
        provide_system=True
    )
    
    return table_def

"""
set the table acl_bindings
"""
def set_table_acl_bindings(catalog, schema_name, table_name, acl_bindings):
    model = catalog.getCatalogModel()
    schema = model.schemas[schema_name]
    table = model.schemas[schema_name].tables[table_name]
    table.acl_bindings = acl_bindings
    model.apply()

"""
set the table acls
"""
def set_table_acls(catalog, schema_name, table_name, acls):
    model = catalog.getCatalogModel()
    schema = model.schemas[schema_name]
    table = model.schemas[schema_name].tables[table_name]
    table.acls = acls
    model.apply()

"""
set the foreign key acls
"""
def set_foreign_key_acls(catalog, schema_name, table_name, constraint_name, acls):
    model = catalog.getCatalogModel()
    schema = model.schemas[schema_name]
    table = model.schemas[schema_name].tables[table_name]
    fk = table.foreign_keys.__getitem__((schema, constraint_name))
    fk.acls = acls
    model.apply()

