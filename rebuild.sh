#!/bin/bash

# Place in the BASE_DIR directory the following files:
#	pdb_cif.py
#	pdb_load_data.py
#	create_catalog.py
#	create_schema.py
#	local_configure_catalog.py
#	drop_all_tables.py
#	rebuild.sh (this script)
#	annotation_config.json
#	json-schema-full-ihm_dev_full.json
#	PDBDEV_00000001.json
#	PDBDEV_00000020.json
#
# Place in the BASE_DIR/.deriva directory the credential.json with the cookie to be used by ermrest
# It has a content like:
#
#{
#  "pdb.isrd.isi.edu": {
#    "cookie": "webauthn=..."
#  }
#}
#
# Examples of usage from building the catalog from scratch on pdb.isrd.isi.edu
#
#	1. Create a new catalog by running:
#
#		$BASE_DIR/create_catalog.py pdb.isrd.isi.edu
#
#		The script will print the CATALOG_NUMBER which will be used in the further commands
#
#	2. Configure the catalog with the defaults by running:
#
#		$BASE_DIR/local_configure_catalog.py  pdb.isrd.isi.edu catalog --catalog $CATALOG_NUMBER
#
#	3. Create the two schemas by running:
#
#		$BASE_DIR/create_schema.py  pdb.isrd.isi.edu $CATALOG_NUMBER PDB
#		$BASE_DIR/create_schema.py  pdb.isrd.isi.edu $CATALOG_NUMBER Vocab
#
#	4. Run the rebuild.sh script:
#
#		$BASE_DIR/rebuild.sh $BASE_DIR pdb.isrd.isi.edu $CATALOG_NUMBER PDB Vocab json-schema-full-ihm_dev_full.json
#
#		The script will:
#
#			4.1 Create the Vocab tables
#			4.2 Create the PDB tables
#			4.3 Load the data into the tables
#			4.4 Create the Foreign Keys
#			4.5 Create annotations for the PDB schema
#			4.6 Create annotations for the Vocab schema
#			4.7 Annotate visible columns for the PDB tables
#			4.7 Annotate visible columns for the Vocab tables
#			4.8 Annotate the row_name for the PDB tables
#			4.9 Create composite Foreign Keys
#
#
# If you want just to refresh the catalog, drop first all the tables by running:
#
#	$BASE_DIR/drop_all_tables.py pdb.isrd.isi.edu $CATALOG_NUMBER PDB Vocab
#
# and then run the step 4.

BASE_DIR=$1
HOSTNAME=$2
CATALOG_NUMBER=$3
SCHEMA_NAME=$4
TERM_SCHEMA_NAME=$5
FILENAME=$6

PDB_CIF="pdb_cif.py"
LOAD_DATA="pdb_load_data.py"
DERIVA_ANNOTATIONS="deriva-annotation-config"
CREDENTIAL_FILE="$BASE_DIR/.deriva/credential.json"
ANNOTATIONS_FILE="$BASE_DIR/annotation_config.json"

echo "`date +"%Y-%m-%d %T"`: Creating the $TERM_SCHEMA_NAME tables..."

#echo "$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateVocab > $BASE_DIR/CreateVocab.log"

$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateVocab > $BASE_DIR/CreateVocab.log

if [ $? != 0 ]
  then
    echo "Can not create the $TERM_SCHEMA_NAME tables."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Creating the $SCHEMA_NAME tables..."

#echo "$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateTable > $BASE_DIR/CreateTable.log"

$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateTable > $BASE_DIR/CreateTable.log

if [ $? != 0 ]
  then
    echo "Can not create the $SCHEMA_NAME tables."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Loading the Data..."

#echo "$BASE_DIR/$LOAD_DATA $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME > $BASE_DIR/load_data.log"

$BASE_DIR/$LOAD_DATA $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME > $BASE_DIR/load_data.log

if [ $? != 0 ]
  then
    echo "Can not load the data."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Creating the FK..."

#echo "$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateFkeys > $BASE_DIR/CreateFkeys.log"

$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateFkeys > $BASE_DIR/CreateFkeys.log

if [ $? != 0 ]
  then
    echo "Can not create the FK."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Configure the annotations for the $SCHEMA_NAME schema..."

#echo "$DERIVA_ANNOTATIONS --host  $HOSTNAME --credential-file $CREDENTIAL_FILE --config-file $ANNOTATIONS_FILE -s $SCHEMA_NAME $CATALOG_NUMBER"

$DERIVA_ANNOTATIONS --host  $HOSTNAME --credential-file $CREDENTIAL_FILE --config-file $ANNOTATIONS_FILE -s $SCHEMA_NAME $CATALOG_NUMBER

if [ $? != 0 ]
  then
    echo "Can not configure the $SCHEMA_NAME schema."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Configure the annotations for the $TERM_SCHEMA_NAME schema..."

#echo "$DERIVA_ANNOTATIONS --host  $HOSTNAME --credential-file $CREDENTIAL_FILE --config-file $ANNOTATIONS_FILE -s $TERM_SCHEMA_NAME $CATALOG_NUMBER"

$DERIVA_ANNOTATIONS --host  $HOSTNAME --credential-file $CREDENTIAL_FILE --config-file $ANNOTATIONS_FILE -s $TERM_SCHEMA_NAME $CATALOG_NUMBER

if [ $? != 0 ]
  then
    echo "Can not configure the $TERM_SCHEMA_NAM schema."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Annotating $SCHEMA_NAME tables visible columns..."

#echo "$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME AnnotateTable_VisibleColumn > $BASE_DIR/AnnotateTable_VisibleColumn.log"

$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME AnnotateTable_VisibleColumn > $BASE_DIR/AnnotateTable_VisibleColumn.log

if [ $? != 0 ]
  then
    echo "Can not annotate the $SCHEMA_NAME visible columns."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Annotating $TERM_SCHEMA_NAME visible columns..."

#echo "$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME VocabTable_VisibleColumn > $BASE_DIR/VocabTable_VisibleColumn.log"

$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME VocabTable_VisibleColumn > $BASE_DIR/VocabTable_VisibleColumn.log

if [ $? != 0 ]
  then
    echo "Can not annotate the $TERM_SCHEMA_NAME visible columns."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Annotating Row Name tables..."

#echo "$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME AnnotateTable_RowName > $BASE_DIR/AnnotateTable_RowName.log"

$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME AnnotateTable_RowName > $BASE_DIR/AnnotateTable_RowName.log

if [ $? != 0 ]
  then
    echo "Can not annotate the RowName tables."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Creating composite FK..."

#echo "$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateCompositeFkeys > $BASE_DIR/CreateCompositeFkeys.log"

$BASE_DIR/$PDB_CIF $HOSTNAME $CATALOG_NUMBER $SCHEMA_NAME $TERM_SCHEMA_NAME $BASE_DIR/$FILENAME CreateCompositeFkeys > $BASE_DIR/CreateCompositeFkeys.log

if [ $? != 0 ]
  then
    echo "Can not create the composite FK."
    exit 1
  fi
  
echo "`date +"%Y-%m-%d %T"`: Ended..."

