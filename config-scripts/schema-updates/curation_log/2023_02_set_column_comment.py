import sys                
import json               
from deriva.core import ErmrestCatalog, AttrDict, get_credential, DEFAULT_CREDENTIAL_FILE, tag, urlquote, DerivaServer, get_credential, BaseCLI
from deriva.core.ermrest_model import builtin_types, Schema, Table, Column, Key, ForeignKey, DomainType, ArrayType
import utils
from utils import ApplicationClient


def update_PDB_entry(model):
    # Add the PDB.entry.Submitter_Flag and PDB.entry.Submitter_Flag_date columns  
    utils.set_column_comment_if_exist(model, 'PDB', 'entry', 'Submitter_Flag_Date', 'Date last communicated with the submitter. Waiting for response from submitter. This date can only be set when Submitter_Flag is True.')
    utils.set_column_comment_if_exist(model, 'PDB', 'entry', 'Submitter_Flag', 'This flag is set to "true" when the entry is waiting for input from user.')


# ============================================================
def main(server_name, catalog_id, credentials):
    server = DerivaServer('https', server_name, credentials)
    catalog = server.connect_ermrest(catalog_id)
    catalog.dcctx['cid'] = 'oneoff/model'
    model = catalog.getCatalogModel()

    """
    Update table
    """
    update_PDB_entry(model)

# ===================================================    

if __name__ == '__main__':
    args = ApplicationClient('ad-hoc table creation tool', None, 1).parse_cli()
    credentials = get_credential(args.host, args.credential_file)
    main(args.host, args.catalog_id, credentials)
    
