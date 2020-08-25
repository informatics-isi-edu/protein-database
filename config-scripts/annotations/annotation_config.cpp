{
    "known_attributes": {
        "ignore_all_unmanaged": false,
        "managed": [
            "tag:misd.isi.edu,2015:display",
            "tag:misd.isi.edu,2015:url",
            "tag:isrd.isi.edu,2016:column-display",
            "tag:isrd.isi.edu,2016:display",
            "tag:isrd.isi.edu,2016:foreign-key",
            "tag:isrd.isi.edu,2016:export",
            "tag:isrd.isi.edu,2016:generated",
            "tag:misd.isi.edu,2016:generated",
            "tag:isrd.isi.edu,2016:ignore",
            "tag:isrd.isi.edu,2016:immutable",
            "tag:isrd.isi.edu,2016:recordlink",
            "tag:isrd.isi.edu,2016:table-alternatives",
            "tag:isrd.isi.edu,2016:table-display",
            "tag:isrd.isi.edu,2016:visible-columns",
            "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "tag:isrd.isi.edu,2017:asset",
            "tag:isrd.isi.edu,2017:bulk-upload",
            "tag:isrd.isi.edu,2018:citation",
            "tag:isrd.isi.edu,2018:required",
            "tag:isrd.isi.edu,2019:export",
            "tag:isrd.isi.edu,2019:source-definitions",
            "comment",
            "description",
            "facetOrder"
        ]
    },
    "schema_annotations": [
        {
            "schema": "WWW",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name_style": {
                    "underline_space": true
                }
            }
        },
        {
            "schema": "PDB",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name_style": {
                    "title_case": true,
                    "underline_space": true
                }
            }
        },
        {
            "schema": "Vocab",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name_style": {
                    "title_case": false,
                    "underline_space": true
                }
            }
        }
    ],
    "column_annotations": [
        {
            "column": "id",
            "schema_pattern": "Vocab",
            "table_pattern": ".*",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "column": "uri",
            "schema_pattern": "Vocab",
            "table_pattern": ".*",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "column": "description",
            "schema_pattern": "Vocab",
            "table_pattern": ".*",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name": "Description"
            }
        },
        {
            "column": "name",
            "schema_pattern": "Vocab",
            "table_pattern": ".*",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name": "Name"
            }
        },
        {
            "column": "synonyms",
            "schema_pattern": "Vocab",
            "table_pattern": ".*",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name": "Synonyms"
            }
        },
        {
            "column": "Display_Name",
            "schema": "public",
            "table": "ERMrest_Client",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name": "Display Name"
            }
        },
        {
            "column": "Display_Name",
            "schema": "public",
            "table": "ERMrest_Group",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name": "Display Name"
            }
        },
        {
            "column": "Display_Name",
            "schema": "public",
            "table": "Catalog_Group",
            "uri": "tag:misd.isi.edu,2015:display",
            "value": {
                "name": "Display Name"
            }
        },
        {
            "column": "URL",
            "schema": "WWW",
            "table": "Page_Asset",
            "uri": "tag:isrd.isi.edu,2017:asset",
            "value": {
                "byte_count_column": "Length",
                "filename_column": "Filename",
                "md5": "MD5",
                "url_pattern": "/hatrac/WWW/Page_Asset/{{{MD5}}}.{{#encode}}{{{Filename}}}{{/encode}}"
            }
        },
        {
            "column": "File_URL",
            "schema": "PDB",
            "table": "Entry_Related_File",
            "uri": "tag:isrd.isi.edu,2017:asset",
            "value": {
                "byte_count_column": "File_Bytes",
                "filename_column": "File_Name",
                "md5": "File_MD5",
                "url_pattern": "/hatrac/pdb/entry_files/{{$moment.year}}/{{{File_MD5}}}"
            }
        },
        {
            "column": "File_URL",
            "schema": "PDB",
            "table": "Entry_Related_File",
            "uri": "tag:isrd.isi.edu,2018:required",
            "value": {}
        },
        {
            "column": "id",
            "schema": "PDB",
            "table": "entry",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "column": "Image_File_URL",
            "schema": "PDB",
            "table": "entry",
            "uri": "tag:isrd.isi.edu,2017:asset",
            "value": {
                "byte_count_column": "Image_File_Bytes",
                "filename_column": "Image_File_Name",
                "md5": "Image_File_MD5",
                "url_pattern": "/hatrac/pdb/image/{{$moment.year}}/{{{Image_File_MD5}}}"
            }
        },
        {
            "column": "mmCIF_File_URL",
            "schema": "PDB",
            "table": "entry",
            "uri": "tag:isrd.isi.edu,2017:asset",
            "value": {
                "byte_count_column": "mmCIF_File_Bytes",
                "filename_column": "mmCIF_File_Name",
                "md5": "mmCIF_File_MD5",
                "url_pattern": "/hatrac/pdb/mmCIF/{{$moment.year}}/{{{mmCIF_File_MD5}}}"
            }
        },
        {
            "column": "pdbx_database_id_DOI",
            "schema": "PDB",
            "table": "citation",
            "uri": "tag:isrd.isi.edu,2016:column-display",
            "value": {
                "*": {
                    "markdown_pattern": "{{#pdbx_database_id_DOI}}[{{_pdbx_database_id_DOI}}](https://doi.org/{{_pdbx_database_id_DOI}}){{/pdbx_database_id_DOI}}"
                }
            }
        },
        {
            "column": "pdbx_database_id_PubMed",
            "schema": "PDB",
            "table": "citation",
            "uri": "tag:isrd.isi.edu,2016:column-display",
            "value": {
                "*": {
                    "markdown_pattern": "{{_pdbx_database_id_PubMed}}"
                }
            }
        },
        {
            "column": "year",
            "schema": "PDB",
            "table": "citation",
            "uri": "tag:isrd.isi.edu,2016:column-display",
            "value": {
                "*": {
                    "markdown_pattern": "{{_year}}"
                }
            }
        },
        {
            "column": "mmCIF_File_URL",
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2017:asset",
            "value": {
                "byte_count_column": "mmCIF_File_Bytes",
                "filename_column": "mmCIF_File_Name",
                "md5": "mmCIF_File_MD5",
                "url_pattern": "/hatrac/pdb/mmCIF/{{$moment.year}}/{{{mmCIF_File_MD5}}}"
            }
        }
    ],
    "table_annotations": [
        {
            "schema": "Vocab",
            "table_pattern": ".*",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{Name}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_localization_density_files",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_ensemble_info.ensemble_id.",
                        "markdown_name": "ensemble id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_ensemble_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_ensemble_info.ensemble_id.",
                        "markdown_name": "ensemble id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_ensemble_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_localization_density_files_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_localization_density_files_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_localization_density_files_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_ensemble_info.ensemble_id.",
                        "markdown_name": "ensemble id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_ensemble_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_localization_density_files_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_representative",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_representative_selection_criteria_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_representative_selection_criteria_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representative_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representative_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_model_representative_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representative_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_representative_selection_criteria_fkey"
                    ]
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "chem_comp_atom",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "chem_comp_atom_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "chem_comp_atom_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "atom_id",
                    "type_symbol",
                    "pdbx_ordinal",
                    "alt_atom_id",
                    "charge",
                    "partial_charge",
                    "model_Cartn_x",
                    "model_Cartn_x_esd",
                    "model_Cartn_y",
                    "model_Cartn_y_esd",
                    "model_Cartn_z",
                    "model_Cartn_z_esd",
                    "pdbx_model_Cartn_x_ideal",
                    "pdbx_model_Cartn_y_ideal",
                    "pdbx_model_Cartn_z_ideal",
                    "pdbx_align",
                    "pdbx_alt_atom_id",
                    "pdbx_alt_comp_id",
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_aromatic_flag_fkey"
                    ],
                    "pdbx_component_atom_id",
                    "pdbx_component_comp_id",
                    "pdbx_component_entity_id",
                    "pdbx_component_id",
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_leaving_atom_flag_fkey"
                    ],
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_polymer_type_fkey"
                    ],
                    "pdbx_ref_id",
                    "pdbx_residue_numbering",
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_stereo_config_fkey"
                    ],
                    "pdbx_stnd_atom_id",
                    [
                        "PDB",
                        "chem_comp_atom_substruct_code_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "chem_comp_atom_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "chem_comp_atom_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "atom_id",
                    "type_symbol",
                    "pdbx_ordinal",
                    "alt_atom_id",
                    "charge",
                    "partial_charge",
                    "model_Cartn_x",
                    "model_Cartn_x_esd",
                    "model_Cartn_y",
                    "model_Cartn_y_esd",
                    "model_Cartn_z",
                    "model_Cartn_z_esd",
                    "pdbx_model_Cartn_x_ideal",
                    "pdbx_model_Cartn_y_ideal",
                    "pdbx_model_Cartn_z_ideal",
                    "pdbx_align",
                    "pdbx_alt_atom_id",
                    "pdbx_alt_comp_id",
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_aromatic_flag_fkey"
                    ],
                    "pdbx_component_atom_id",
                    "pdbx_component_comp_id",
                    "pdbx_component_entity_id",
                    "pdbx_component_id",
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_leaving_atom_flag_fkey"
                    ],
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_polymer_type_fkey"
                    ],
                    "pdbx_ref_id",
                    "pdbx_residue_numbering",
                    [
                        "PDB",
                        "chem_comp_atom_pdbx_stereo_config_fkey"
                    ],
                    "pdbx_stnd_atom_id",
                    [
                        "PDB",
                        "chem_comp_atom_substruct_code_fkey"
                    ]
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity_poly_seq",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "schema": "PDB",
            "table": "entity_poly_seq",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_seq_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_seq_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "mon id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_seq_mon_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "num",
                    [
                        "PDB",
                        "entity_poly_seq_hetero_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_seq_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_seq_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "mon id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_seq_mon_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "num",
                    [
                        "PDB",
                        "entity_poly_seq_hetero_fkey"
                    ]
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity_poly_seq",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_position_mm_poly_res_label_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "chem_comp",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "schema": "PDB",
            "table": "chem_comp",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "chem_comp",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "chem_comp_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "chem_comp_type_fkey"
                    ],
                    "formula",
                    "formula_weight",
                    [
                        "PDB",
                        "chem_comp_mon_nstd_flag_fkey"
                    ],
                    "pdbx_synonyms"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "chem_comp_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "chem_comp_type_fkey"
                    ],
                    "formula",
                    "formula_weight",
                    [
                        "PDB",
                        "chem_comp_mon_nstd_flag_fkey"
                    ],
                    "pdbx_synonyms"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "chem_comp",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "chem_comp_atom_comp_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_seq_mon_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entity_nonpoly_comp_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_non_poly_feature_comp_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_position_mut_res_chem_comp_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "citation_author",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "citation_author_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "citation_author_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal",
                    "name"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "citation_author_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "citation_author_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal",
                    "name"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_chemical_component_descriptor",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_chemical_component_descriptor_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "chemical_name",
                    "common_name",
                    "auth_name",
                    "smiles",
                    "smiles_canonical",
                    "inchi",
                    "inchi_key",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_chemical_component_descriptor_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "chemical_name",
                    "common_name",
                    "auth_name",
                    "smiles",
                    "smiles_canonical",
                    "inchi",
                    "inchi_key",
                    "details",
                    [
                        "PDB",
                        "ihm_chemical_component_descriptor_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_chemical_component_descriptor_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_chemical_component_descriptor_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_chemical_component_descriptor_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "chemical_name",
                    "common_name",
                    "auth_name",
                    "smiles",
                    "smiles_canonical",
                    "inchi",
                    "inchi_key",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_chemical_component_descriptor",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_cross_link_list_linker_chem_comp_descriptor_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_probe_list_probe_chem_comp_descriptor_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_probe_list_reactive_probe_chem_comp_descriptor_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_chem_comp_descriptor_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "pdbx_inhibitor_info",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_inhibitor_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "num_per_asym_unit"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_inhibitor_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "num_per_asym_unit",
                    [
                        "PDB",
                        "pdbx_inhibitor_info_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_inhibitor_info_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "pdbx_inhibitor_info_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_inhibitor_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "num_per_asym_unit"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_external_reference",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_dataset_external_reference_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_external_reference_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_dataset_external_reference_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_external_reference_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly_details",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "parent assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_parent_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "parent assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_parent_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_struct_assembly_details_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_details_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_struct_assembly_details_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "parent assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_parent_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity_src_gen",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_src_gen_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_src_gen_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_src_id",
                    [
                        "PDB",
                        "entity_src_gen_pdbx_alt_source_flag_fkey"
                    ],
                    "gene_src_common_name",
                    "gene_src_genus",
                    "pdbx_gene_src_scientific_name"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_src_gen_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_src_gen_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_src_id",
                    [
                        "PDB",
                        "entity_src_gen_pdbx_alt_source_flag_fkey"
                    ],
                    "gene_src_common_name",
                    "gene_src_genus",
                    "pdbx_gene_src_scientific_name"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity_name_com",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_com_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_com_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "name"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_com_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_com_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "name"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_list",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_list",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    {
                        "source": "RID"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description_1",
                    "entity_description_2",
                    {
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_list_linker_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id for the cross linker.",
                        "markdown_name": "linker chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_linker_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_cross_link_list_dataset_list_id_fkey"
                    ],
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_list_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    {
                        "source": "RID"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description_1",
                    "entity_description_2",
                    {
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_list_linker_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id for the cross linker.",
                        "markdown_name": "linker chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_linker_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_cross_link_list_dataset_list_id_fkey"
                    ],
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_list_Entry_Related_File_fkey"
                    ],
                    {
                        "source": "RCT"
                    },
                    {
                        "source": "RMT"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_RCB_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_RMB_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_Owner_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "entry": [
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description_1",
                    "entity_description_2",
                    {
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_list_linker_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id for the cross linker.",
                        "markdown_name": "linker chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_linker_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_cross_link_list_dataset_list_id_fkey"
                    ],
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_list_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_list",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_cross_link_restraint_group_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_probe_list",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "probe_id",
                    "probe_name",
                    [
                        "PDB",
                        "ihm_probe_list_reactive_probe_flag_fkey"
                    ],
                    "reactive_probe_name",
                    [
                        "PDB",
                        "ihm_probe_list_probe_origin_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_probe_list_probe_link_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "probe chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_probe_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "reactive probe chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_reactive_probe_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "probe_id",
                    "probe_name",
                    [
                        "PDB",
                        "ihm_probe_list_reactive_probe_flag_fkey"
                    ],
                    "reactive_probe_name",
                    [
                        "PDB",
                        "ihm_probe_list_probe_origin_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_probe_list_probe_link_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "probe chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_probe_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "reactive probe chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_reactive_probe_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_probe_list_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_probe_list_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_probe_list_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "probe_id",
                    "probe_name",
                    [
                        "PDB",
                        "ihm_probe_list_reactive_probe_flag_fkey"
                    ],
                    "reactive_probe_name",
                    [
                        "PDB",
                        "ihm_probe_list_probe_origin_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_probe_list_probe_link_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "probe chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_probe_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "reactive probe chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_probe_list_reactive_probe_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_probe_list",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_probe_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ligand_probe_probe_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "struct_asym",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "schema": "PDB",
            "table": "struct_asym",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "struct_asym",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "struct_asym_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "struct_asym_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_PDB_id",
                    "pdbx_alt_id",
                    [
                        "PDB",
                        "struct_asym_pdbx_blank_PDB_chainid_flag_fkey"
                    ],
                    "pdbx_modified",
                    "pdbx_order",
                    [
                        "PDB",
                        "struct_asym_pdbx_type_fkey"
                    ],
                    "details"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "struct_asym_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "struct_asym_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_PDB_id",
                    "pdbx_alt_id",
                    [
                        "PDB",
                        "struct_asym_pdbx_blank_PDB_chainid_flag_fkey"
                    ],
                    "pdbx_modified",
                    "pdbx_order",
                    [
                        "PDB",
                        "struct_asym_pdbx_type_fkey"
                    ],
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "struct_asym",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_model_representation_details_entity_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_details_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_details_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_seq_dif_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_restraint_asym_id_1_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_restraint_asym_id_2_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_asym_id_1_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_asym_id_2_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_atom_feature_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_non_poly_feature_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_interface_residue_feature_binding_partner_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_residues_not_modeled_asym_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_localization_density_files_asym_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_multi_state_model_group_link",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_multi_state_modeling.state_id.",
                        "markdown_name": "state id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_state_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_multi_state_modeling.state_id.",
                        "markdown_name": "state id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_state_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_multi_state_model_group_link_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_multi_state_model_group_link_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_multi_state_model_group_link_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_multi_state_modeling.state_id.",
                        "markdown_name": "state id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_state_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_model_group_link_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_epr_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "fitting_particle_type",
                    "fitting_method",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "fitting method citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_fitting_method_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_epr_restraint_fitting_state_fkey"
                    ],
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "fitting software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_fitting_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "chi_value",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "fitting_particle_type",
                    "fitting_method",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "fitting method citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_fitting_method_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_epr_restraint_fitting_state_fkey"
                    ],
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "fitting software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_fitting_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "chi_value",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_epr_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_epr_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_epr_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "fitting_particle_type",
                    "fitting_method",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "fitting method citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_fitting_method_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_epr_restraint_fitting_state_fkey"
                    ],
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "fitting software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_fitting_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "chi_value",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_epr_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_2dem_class_average_fitting",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_2dem_class_average_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "cross_correlation_coefficient",
                    "rot_matrix_1_1",
                    "rot_matrix_1_2",
                    "rot_matrix_1_3",
                    "rot_matrix_2_1",
                    "rot_matrix_2_2",
                    "rot_matrix_2_3",
                    "rot_matrix_3_1",
                    "rot_matrix_3_2",
                    "rot_matrix_3_3",
                    "tr_vector_1",
                    "tr_vector_2",
                    "tr_vector_3"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_2dem_class_average_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "cross_correlation_coefficient",
                    "rot_matrix_1_1",
                    "rot_matrix_1_2",
                    "rot_matrix_1_3",
                    "rot_matrix_2_1",
                    "rot_matrix_2_2",
                    "rot_matrix_2_3",
                    "rot_matrix_3_1",
                    "rot_matrix_3_2",
                    "rot_matrix_3_3",
                    "tr_vector_1",
                    "tr_vector_2",
                    "tr_vector_3",
                    [
                        "PDB",
                        "ihm_2dem_class_average_fitting_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_2dem_class_average_fitting_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_2dem_class_average_fitting_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_2dem_class_average_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_fitting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "cross_correlation_coefficient",
                    "rot_matrix_1_1",
                    "rot_matrix_1_2",
                    "rot_matrix_1_3",
                    "rot_matrix_2_1",
                    "rot_matrix_2_2",
                    "rot_matrix_2_3",
                    "rot_matrix_3_1",
                    "rot_matrix_3_2",
                    "rot_matrix_3_3",
                    "tr_vector_1",
                    "tr_vector_2",
                    "tr_vector_3"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "software",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{pdbx_ordinal}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "software",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "software_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_ordinal",
                    "name",
                    "classification",
                    [
                        "PDB",
                        "software_type_fkey"
                    ],
                    "version",
                    "location",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "software_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "software_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_ordinal",
                    "name",
                    "classification",
                    [
                        "PDB",
                        "software_type_fkey"
                    ],
                    "version",
                    "location",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "software_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "software",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_software_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_software_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_computational_models_software_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_epr_restraint_fitting_software_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_software_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_software_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_poly_probe_conjugate",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_probe_list.probe_id.",
                        "markdown_name": "probe id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_probe_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_poly_probe_position.id.",
                        "markdown_name": "position id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_position_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_ambiguous_stoichiometry_flag_fkey"
                    ],
                    "probe_stoichiometry",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_probe_list.probe_id.",
                        "markdown_name": "probe id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_probe_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_poly_probe_position.id.",
                        "markdown_name": "position id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_position_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_ambiguous_stoichiometry_flag_fkey"
                    ],
                    "probe_stoichiometry",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_probe_list.probe_id.",
                        "markdown_name": "probe id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_probe_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_poly_probe_position.id.",
                        "markdown_name": "position id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_position_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_ambiguous_stoichiometry_flag_fkey"
                    ],
                    "probe_stoichiometry",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_conjugate_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_representation",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_representation",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "details",
                    [
                        "PDB",
                        "ihm_model_representation_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_model_representation_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_representation",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_model_representation_details_representation_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_list_representation_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_list",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "schema": "PDB",
            "table": "ihm_model_list",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{model_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_list",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "model_id",
                    "model_name",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_representation.id.",
                        "markdown_name": "representation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_representation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "model_id",
                    "model_name",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_representation.id.",
                        "markdown_name": "representation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_representation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_list_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_list_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_model_list_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "model_id",
                    "model_name",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_representation.id.",
                        "markdown_name": "representation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_list_representation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_list",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_model_group_link_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representative_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_residues_not_modeled_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_2dem_class_average_fitting_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_3dem_restraint_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_sas_restraint_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_epr_restraint_model_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_feature_list",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{feature_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_feature_list",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_feature_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "feature_id",
                    [
                        "PDB",
                        "ihm_feature_list_feature_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_feature_list_entity_type_fkey"
                    ],
                    "details",
                    [
                        "PDB",
                        "ihm_feature_list_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_feature_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "feature_id",
                    [
                        "PDB",
                        "ihm_feature_list_feature_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_feature_list_entity_type_fkey"
                    ],
                    "details",
                    [
                        "PDB",
                        "ihm_feature_list_feature_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_feature_list_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_feature_list_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_feature_list_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_feature_list_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_feature_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "feature_id",
                    [
                        "PDB",
                        "ihm_feature_list_feature_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_feature_list_entity_type_fkey"
                    ],
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_feature_list",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_poly_atom_feature_feature_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_feature_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_non_poly_feature_feature_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_interface_residue_feature_feature_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_pseudo_site_feature_feature_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_feature_id_1_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_feature_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "pdbx_entity_poly_na_type",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_poly_na_type_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_poly_na_type_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_type_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_poly_na_type_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_poly_na_type_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_type_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_poly_na_type_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_poly_na_type_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_type_fkey"
                    ]
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_ordered_ensemble",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "process_id",
                    "process_description",
                    "edge_id",
                    "edge_description",
                    "step_id",
                    "step_description",
                    "ordered_by",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_model_group_id_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_model_group_id_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "process_id",
                    "process_description",
                    "edge_id",
                    "edge_description",
                    "step_id",
                    "step_description",
                    "ordered_by",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_model_group_id_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_model_group_id_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_ordered_ensemble_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ordered_ensemble_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_ordered_ensemble_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "process_id",
                    "process_description",
                    "edge_id",
                    "edge_description",
                    "step_id",
                    "step_description",
                    "ordered_by",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_model_group_id_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ordered_ensemble_model_group_id_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_list",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{object_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_list",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "object_id",
                    [
                        "PDB",
                        "ihm_geometric_object_list_object_type_fkey"
                    ],
                    "object_name",
                    "object_description"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "object_id",
                    [
                        "PDB",
                        "ihm_geometric_object_list_object_type_fkey"
                    ],
                    "object_name",
                    "object_description",
                    [
                        "PDB",
                        "ihm_geometric_object_list_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_list_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_list_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "object_id",
                    [
                        "PDB",
                        "ihm_geometric_object_list_object_type_fkey"
                    ],
                    "object_name",
                    "object_description"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_list",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_geometric_object_sphere_object_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_torus_object_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_axis_object_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_plane_object_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_object_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "pdbx_ion_info",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_ion_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "numb_per_asym_unit",
                    [
                        "PDB",
                        "pdbx_ion_info_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_ion_info_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "pdbx_ion_info_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_ion_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "numb_per_asym_unit"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "Entry_Related_File",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    [
                        "PDB",
                        "Entry_Related_File_entry_id_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_File_Type_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_File_Format_fkey"
                    ],
                    "File_URL",
                    "File_Bytes",
                    "File_MD5",
                    "Description",
                    [
                        "PDB",
                        "Entry_Related_File_workflow_status_fkey"
                    ],
                    "Record_Status_Detail"
                ],
                "detailed": [
                    "RID",
                    [
                        "PDB",
                        "Entry_Related_File_entry_id_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_File_Type_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_File_Format_fkey"
                    ],
                    "File_URL",
                    "File_Bytes",
                    "File_MD5",
                    "Description",
                    [
                        "PDB",
                        "Entry_Related_File_workflow_status_fkey"
                    ],
                    "Record_Status_Detail",
                    [
                        "PDB",
                        "Entry_Related_File_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "Entry_Related_File_Owner_fkey"
                    ]
                ],
                "entry": [
                    [
                        "PDB",
                        "Entry_Related_File_entry_id_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_File_Type_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_File_Format_fkey"
                    ],
                    "File_Name",
                    "File_URL",
                    "File_Bytes",
                    "File_MD5",
                    "Description",
                    [
                        "PDB",
                        "Entry_Related_File_workflow_status_fkey"
                    ]
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_sphere",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_center.id.",
                        "markdown_name": "center id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_center_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "radius_r"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_center.id.",
                        "markdown_name": "center id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_center_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "radius_r",
                    [
                        "PDB",
                        "ihm_geometric_object_sphere_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_sphere_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_sphere_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_center.id.",
                        "markdown_name": "center id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_center_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_sphere_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "radius_r"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_poly_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_residue_feature_rep_atom_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_residue_range_granularity_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_interface_residue_flag_fkey"
                    ],
                    {
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_residue_feature_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_residue_feature_rep_atom_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_residue_range_granularity_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_interface_residue_flag_fkey"
                    ],
                    {
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_residue_feature_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_poly_residue_feature_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_residue_feature_rep_atom_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_residue_range_granularity_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_interface_residue_flag_fkey"
                    ],
                    {
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_residue_feature_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "audit_conform",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "audit_conform_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "dict_name",
                    "dict_location",
                    "dict_version"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "audit_conform_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "dict_name",
                    "dict_location",
                    "dict_version",
                    [
                        "PDB",
                        "audit_conform_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "audit_conform_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "audit_conform_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "audit_conform_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "dict_name",
                    "dict_location",
                    "dict_version"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "pdbx_entry_details",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entry_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "entry id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entry_details_entry_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "sequence_details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entry_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "entry id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entry_details_entry_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "sequence_details",
                    [
                        "PDB",
                        "pdbx_entry_details_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entry_details_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "pdbx_entry_details_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entry_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "entry id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entry_details_entry_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "sequence_details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_related_datasets",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "derived dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_dataset_list_id_derived_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "primary dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_dataset_list_id_primary_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "derived dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_dataset_list_id_derived_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "primary dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_dataset_list_id_primary_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_related_datasets_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_related_datasets_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_related_datasets_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "derived dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_dataset_list_id_derived_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "primary dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_related_datasets_dataset_list_id_primary_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_group",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_group",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "details",
                    [
                        "PDB",
                        "ihm_model_group_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_group_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_model_group_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_group",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_model_group_link_group_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representative_model_group_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_multi_state_model_group_link_model_group_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ordered_ensemble_model_group_id_begin_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ordered_ensemble_model_group_id_end_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ensemble_info_model_group_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "description"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "description",
                    [
                        "PDB",
                        "ihm_struct_assembly_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_struct_assembly_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "description"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_struct_assembly_details_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_details_parent_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_class_link_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_struct_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_struct_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_list_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_struct_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_3dem_restraint_struct_assembly_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_sas_restraint_struct_assembly_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_multi_state_modeling",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{state_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_multi_state_modeling",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_modeling_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "state_id",
                    "state_group_id",
                    "state_type",
                    "state_name",
                    [
                        "PDB",
                        "ihm_multi_state_modeling_experiment_type_fkey"
                    ],
                    "population_fraction",
                    "population_fraction_sd",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_modeling_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "state_id",
                    "state_group_id",
                    "state_type",
                    "state_name",
                    [
                        "PDB",
                        "ihm_multi_state_modeling_experiment_type_fkey"
                    ],
                    "population_fraction",
                    "population_fraction_sd",
                    "details",
                    [
                        "PDB",
                        "ihm_multi_state_modeling_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_multi_state_modeling_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_multi_state_modeling_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_multi_state_modeling_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "state_id",
                    "state_group_id",
                    "state_type",
                    "state_name",
                    [
                        "PDB",
                        "ihm_multi_state_modeling_experiment_type_fkey"
                    ],
                    "population_fraction",
                    "population_fraction_sd",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_multi_state_modeling",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_multi_state_model_group_link_state_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_group",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_group",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "ihm_dataset_group_application_fkey"
                    ],
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "ihm_dataset_group_application_fkey"
                    ],
                    "details",
                    [
                        "PDB",
                        "ihm_dataset_group_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_group_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_dataset_group_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "ihm_dataset_group_application_fkey"
                    ],
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_group",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_dataset_group_link_group_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_dataset_group_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_dataset_group_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "entry",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "entry",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    "id",
                    "mmCIF_File_URL",
                    "Image_File_URL",
                    [
                        "PDB",
                        "entry_workflow_status_fkey"
                    ],
                    "Record_Status_Detail",
                    "accession_code",
                    [
                        "PDB",
                        "entry_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "entry_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "entry_Owner_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    "id",
                    "mmCIF_File_URL",
                    {
                        "markdown_name": "mmCIF File Size (Bytes)",
                        "source": "mmCIF_File_Bytes"
                    },
                    "Image_File_URL",
                    {
                        "markdown_name": "Image File Size (Bytes)",
                        "source": "Image_File_Bytes"
                    },
                    [
                        "PDB",
                        "entry_workflow_status_fkey"
                    ],
                    "Record_Status_Detail",
                    "accession_code",
                    [
                        "PDB",
                        "entry_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "entry_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "entry_Owner_fkey"
                    ]
                ],
                "entry": [
                    "mmCIF_File_URL",
                    "Image_File_URL",
                    [
                        "PDB",
                        "entry_workflow_status_fkey"
                    ],
                    "accession_code"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entry",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "struct_entry_id_fkey"
                    ],
                    [
                        "PDB",
                        "audit_author_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "citation_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "citation_author_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "software_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "chem_comp_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "chem_comp_atom_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_name_com_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_name_sys_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_src_gen_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entity_nonpoly_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_seq_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "atom_type_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "struct_asym_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_entity_poly_segment_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_details_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_details_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_class_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_class_link_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_list_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_group_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_group_link_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_external_reference_info_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_external_files_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_external_reference_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_related_datasets_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_details_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_comparative_models_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_computational_models_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_seq_dif_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_chemical_component_descriptor_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "Entry_Related_File_entry_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_probe_list_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_position_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ligand_probe_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_list_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_feature_list_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_atom_feature_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_residue_feature_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_non_poly_feature_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_interface_residue_feature_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_pseudo_site_feature_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_list_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_center_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_transformation_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_sphere_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_torus_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_axis_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_plane_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_list_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_group_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_group_link_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representative_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_residues_not_modeled_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_2dem_class_average_fitting_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_3dem_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_sas_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_epr_restraint_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_multi_state_modeling_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_multi_state_model_group_link_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ordered_ensemble_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ensemble_info_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_localization_density_files_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "audit_conform_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entry_details_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entry_details_entry_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_inhibitor_info_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_ion_info_structure_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_protein_info_structure_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "atom_type",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "schema": "PDB",
            "table": "atom_type",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{symbol}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "atom_type",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "atom_type_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "symbol"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "atom_type_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "symbol"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_interface_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "binding partner entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_binding_partner_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "binding partner asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_binding_partner_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_interface_residue_feature_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "binding partner entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_binding_partner_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "binding partner asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_binding_partner_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_interface_residue_feature_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_interface_residue_feature_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_interface_residue_feature_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_interface_residue_feature_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "binding partner entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_binding_partner_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "binding partner asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_binding_partner_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_interface_residue_feature_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_list",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_list",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    [
                        "PDB",
                        "ihm_dataset_list_data_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_list_database_hosted_fkey"
                    ],
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    [
                        "PDB",
                        "ihm_dataset_list_data_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_list_database_hosted_fkey"
                    ],
                    "details",
                    [
                        "PDB",
                        "ihm_dataset_list_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_list_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_dataset_list_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_list_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    [
                        "PDB",
                        "ihm_dataset_list_data_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_list_database_hosted_fkey"
                    ],
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_list",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_dataset_group_link_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_external_reference_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_related_datasets_dataset_list_id_derived_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_related_datasets_dataset_list_id_primary_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_details_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_comparative_models_template_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ligand_probe_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_list_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_3dem_restraint_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_sas_restraint_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_epr_restraint_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_interface_residue_feature_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_dataset_list_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_dataset_list_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "audit_author",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "audit_author_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_ordinal",
                    "name"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "audit_author_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_ordinal",
                    "name",
                    [
                        "PDB",
                        "audit_author_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "audit_author_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "audit_author_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "audit_author_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "pdbx_ordinal",
                    "name"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "entity",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    [
                        "PDB",
                        "entity_type_fkey"
                    ],
                    [
                        "PDB",
                        "entity_src_method_fkey"
                    ],
                    "pdbx_description",
                    "formula_weight",
                    "pdbx_number_of_molecules",
                    "details"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    [
                        "PDB",
                        "entity_type_fkey"
                    ],
                    [
                        "PDB",
                        "entity_src_method_fkey"
                    ],
                    "pdbx_description",
                    "formula_weight",
                    "pdbx_number_of_molecules",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "entity_name_com_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_name_sys_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_src_gen_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entity_nonpoly_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "struct_asym_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_details_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_details_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_details_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ligand_probe_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_non_poly_feature_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_interface_residue_feature_binding_partner_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_localization_density_files_entity_id_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_entity_poly_na_type_entity_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_plane",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_plane_plane_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_plane_plane_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_plane_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_plane_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_plane_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_plane_plane_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_plane_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_predicted_contact_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description_1",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_asym_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_rep_atom_1_fkey"
                    ],
                    "entity_description_2",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_asym_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_rep_atom_2_fkey"
                    ],
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "probability",
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_restraint_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_model_granularity_fkey"
                    ],
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description_1",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_asym_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_rep_atom_1_fkey"
                    ],
                    "entity_description_2",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_asym_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_rep_atom_2_fkey"
                    ],
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "probability",
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_restraint_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_model_granularity_fkey"
                    ],
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description_1",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_asym_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_rep_atom_1_fkey"
                    ],
                    "entity_description_2",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_asym_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_rep_atom_2_fkey"
                    ],
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "probability",
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_restraint_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_predicted_contact_restraint_model_granularity_fkey"
                    ],
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_3dem_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "fitting_method",
                    "number_of_gaussians",
                    [
                        "PDB",
                        "ihm_3dem_restraint_map_segment_flag_fkey"
                    ],
                    "cross_correlation_coefficient",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "fitting method citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_fitting_method_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "fitting_method",
                    "number_of_gaussians",
                    [
                        "PDB",
                        "ihm_3dem_restraint_map_segment_flag_fkey"
                    ],
                    "cross_correlation_coefficient",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "fitting method citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_fitting_method_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_3dem_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_3dem_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_3dem_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "fitting_method",
                    "number_of_gaussians",
                    [
                        "PDB",
                        "ihm_3dem_restraint_map_segment_flag_fkey"
                    ],
                    "cross_correlation_coefficient",
                    {
                        "comment": "A reference to table citation.id.",
                        "markdown_name": "fitting method citation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_fitting_method_citation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_3dem_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_derived_distance_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_feature_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_feature_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_group_conditionality_fkey"
                    ],
                    "random_exclusion_fraction",
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "distance_lower_limit_esd",
                    "distance_upper_limit_esd",
                    "probability",
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_restraint_type_fkey"
                    ],
                    "mic_value",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_feature_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_feature_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_group_conditionality_fkey"
                    ],
                    "random_exclusion_fraction",
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "distance_lower_limit_esd",
                    "distance_upper_limit_esd",
                    "probability",
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_restraint_type_fkey"
                    ],
                    "mic_value",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_feature_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_feature_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_group_conditionality_fkey"
                    ],
                    "random_exclusion_fraction",
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "distance_lower_limit_esd",
                    "distance_upper_limit_esd",
                    "probability",
                    [
                        "PDB",
                        "ihm_derived_distance_restraint_restraint_type_fkey"
                    ],
                    "mic_value",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_derived_distance_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_restraint",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    {
                        "source": "RID"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "markdown_name": "group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "asym id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_asym_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "asym id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_asym_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "source": "atom_id_1"
                    },
                    {
                        "source": "atom_id_2"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_restraint_type_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_restraint_conditional_crosslink_flag_fkey"
                    ],
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_model_granularity_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": "distance_threshold"
                    },
                    {
                        "source": "psi"
                    },
                    {
                        "source": "sigma_1"
                    },
                    {
                        "source": "sigma_2"
                    },
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_restraint_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    {
                        "source": "RID"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "markdown_name": "group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "asym id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_asym_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "asym id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_asym_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "source": "atom_id_1"
                    },
                    {
                        "source": "atom_id_2"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_restraint_type_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_restraint_conditional_crosslink_flag_fkey"
                    ],
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_model_granularity_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": "distance_threshold"
                    },
                    {
                        "source": "psi"
                    },
                    {
                        "source": "sigma_1"
                    },
                    {
                        "source": "sigma_2"
                    },
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_restraint_Entry_Related_File_fkey"
                    ],
                    {
                        "source": "RCT"
                    },
                    {
                        "source": "RMT"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_RCB_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_RMB_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_Owner_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "entry": [
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "markdown_name": "group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "entity id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "entity id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "asym id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_asym_id_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "asym id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_asym_id_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "comp id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "source": "atom_id_1"
                    },
                    {
                        "source": "atom_id_2"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_restraint_type_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_cross_link_restraint_conditional_crosslink_flag_fkey"
                    ],
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_model_granularity_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": "distance_threshold"
                    },
                    {
                        "source": "psi"
                    },
                    {
                        "source": "sigma_1"
                    },
                    {
                        "source": "sigma_2"
                    },
                    {
                        "markdown_name": "polymeric residue 1",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_1_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue 2",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_restraint_mm_poly_res_label_2_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_cross_link_result_restraint_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_restraint_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_group_link",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_group_link_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_group_link_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_model_group_link_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_group_link_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "citation",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "citation",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "citation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "title",
                    "year",
                    "journal_abbrev",
                    "journal_volume",
                    "journal_issue",
                    "page_first",
                    "page_last",
                    "pdbx_database_id_DOI",
                    "pdbx_database_id_PubMed",
                    "journal_id_ASTM",
                    "journal_id_CSD",
                    "journal_id_ISSN",
                    "country"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "citation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "title",
                    "year",
                    "journal_abbrev",
                    "journal_volume",
                    "journal_issue",
                    "page_first",
                    "page_last",
                    "pdbx_database_id_DOI",
                    "pdbx_database_id_PubMed",
                    "journal_id_ASTM",
                    "journal_id_CSD",
                    "journal_id_ISSN",
                    "country"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "citation",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "citation_author_citation_id_fkey"
                    ],
                    [
                        "PDB",
                        "software_citation_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_3dem_restraint_fitting_method_citation_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_epr_restraint_fitting_method_citation_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_poly_atom_feature",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    "atom_id",
                    {
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_atom_feature_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    "atom_id",
                    {
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_atom_feature_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_atom_feature_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_atom_feature_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_poly_atom_feature_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    "atom_id",
                    {
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_atom_feature_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_model_representation_details",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_representation.id.",
                        "markdown_name": "representation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_representation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "entity asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_representation_details_model_granularity_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_details_model_mode_fkey"
                    ],
                    "model_object_count",
                    [
                        "PDB",
                        "model_representation_details_model_object_primitive_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_representation.id.",
                        "markdown_name": "representation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_representation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "entity asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_representation_details_model_granularity_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_details_model_mode_fkey"
                    ],
                    "model_object_count",
                    [
                        "PDB",
                        "model_representation_details_model_object_primitive_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description",
                    [
                        "PDB",
                        "ihm_model_representation_details_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_details_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_model_representation_details_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_representation.id.",
                        "markdown_name": "representation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_representation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "entity asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_model_representation_details_model_granularity_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_details_model_mode_fkey"
                    ],
                    "model_object_count",
                    [
                        "PDB",
                        "model_representation_details_model_object_primitive_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_model_representation_details_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_sas_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_sas_restraint_profile_segment_flag_fkey"
                    ],
                    "fitting_atom_type",
                    "fitting_method",
                    [
                        "PDB",
                        "ihm_sas_restraint_fitting_state_fkey"
                    ],
                    "radius_of_gyration",
                    "chi_value",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_sas_restraint_profile_segment_flag_fkey"
                    ],
                    "fitting_atom_type",
                    "fitting_method",
                    [
                        "PDB",
                        "ihm_sas_restraint_fitting_state_fkey"
                    ],
                    "radius_of_gyration",
                    "chi_value",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_sas_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_sas_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_sas_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_sas_restraint_profile_segment_flag_fkey"
                    ],
                    "fitting_atom_type",
                    "fitting_method",
                    [
                        "PDB",
                        "ihm_sas_restraint_fitting_state_fkey"
                    ],
                    "radius_of_gyration",
                    "chi_value",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_sas_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_entity_poly_segment",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_entity_poly_segment",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    {
                        "source": "RID"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": "id"
                    },
                    {
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    {
                        "source": "RID"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": "id"
                    },
                    {
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": "RCT"
                    },
                    {
                        "source": "RMT"
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_RCB_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_RMB_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_Owner_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "entry": [
                    {
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "source": "id"
                    },
                    {
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_entity_poly_segment_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_entity_poly_segment",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_model_representation_details_entity_poly_segment_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_details_entity_poly_segment_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_details_entity_poly_segment_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_localization_density_files_entity_poly_segment_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_hydroxyl_radical_fp_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    "fp_rate",
                    "fp_rate_error",
                    "log_pf",
                    "log_pf_error",
                    "predicted_sasa",
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    "fp_rate",
                    "fp_rate_error",
                    "log_pf",
                    "log_pf_error",
                    "predicted_sasa",
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_hydroxyl_radical_fp_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "group_id",
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    "fp_rate",
                    "fp_rate_error",
                    "log_pf",
                    "log_pf_error",
                    "predicted_sasa",
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_hydroxyl_radical_fp_restraint_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_starting_model_seq_dif",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "db_asym_id",
                    "db_seq_id",
                    "db_comp_id",
                    "db_entity_id",
                    "details",
                    {
                        "comment": "A reference to the polymeric residue composite key",
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "db_asym_id",
                    "db_seq_id",
                    "db_comp_id",
                    "db_entity_id",
                    "details",
                    {
                        "comment": "A reference to the polymeric residue composite key",
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_starting_model_seq_dif_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_seq_dif_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_starting_model_seq_dif_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "db_asym_id",
                    "db_seq_id",
                    "db_comp_id",
                    "db_entity_id",
                    "details",
                    {
                        "comment": "A reference to the polymeric residue composite key",
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_seq_dif_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_distance_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "geometric_object_distance_restraint_object_character_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_restraint_type_fkey"
                    ],
                    "harmonic_force_constant",
                    [
                        "PDB",
                        "geometric_object_distance_restraint_group_condition_fkey"
                    ],
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "distance_lower_limit_esd",
                    "distance_upper_limit_esd",
                    "distance_probability",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "geometric_object_distance_restraint_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "geometric_object_distance_restraint_object_character_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_restraint_type_fkey"
                    ],
                    "harmonic_force_constant",
                    [
                        "PDB",
                        "geometric_object_distance_restraint_group_condition_fkey"
                    ],
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "distance_lower_limit_esd",
                    "distance_upper_limit_esd",
                    "distance_probability",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "geometric_object_distance_restraint_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "geometric_object_distance_restraint_object_character_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_distance_restraint_restraint_type_fkey"
                    ],
                    "harmonic_force_constant",
                    [
                        "PDB",
                        "geometric_object_distance_restraint_group_condition_fkey"
                    ],
                    "distance_lower_limit",
                    "distance_upper_limit",
                    "distance_lower_limit_esd",
                    "distance_upper_limit_esd",
                    "distance_probability",
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_distance_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_external_files",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_external_files",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_files_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_external_reference_info.reference_id.",
                        "markdown_name": "reference id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_files_reference_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "file_path",
                    [
                        "PDB",
                        "ihm_external_files_file_format_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_external_files_content_type_fkey"
                    ],
                    "file_size_bytes",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_files_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_external_reference_info.reference_id.",
                        "markdown_name": "reference id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_files_reference_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "file_path",
                    [
                        "PDB",
                        "ihm_external_files_file_format_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_external_files_content_type_fkey"
                    ],
                    "file_size_bytes",
                    "details",
                    [
                        "PDB",
                        "ihm_external_files_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_external_files_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_external_files_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_files_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_external_reference_info.reference_id.",
                        "markdown_name": "reference id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_files_reference_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "file_path",
                    [
                        "PDB",
                        "ihm_external_files_file_format_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_external_files_content_type_fkey"
                    ],
                    "file_size_bytes",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_external_files",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_dataset_external_reference_file_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_script_file_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_script_file_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_comparative_models_alignment_file_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_computational_models_script_file_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ensemble_info_ensemble_file_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_localization_density_files_file_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_external_reference_info",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{reference_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_external_reference_info",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_reference_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "reference_id",
                    "reference_provider",
                    [
                        "PDB",
                        "ihm_external_reference_info_reference_type_fkey"
                    ],
                    "reference",
                    [
                        "PDB",
                        "ihm_external_reference_info_refers_to_fkey"
                    ],
                    "associated_url",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_reference_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "reference_id",
                    "reference_provider",
                    [
                        "PDB",
                        "ihm_external_reference_info_reference_type_fkey"
                    ],
                    "reference",
                    [
                        "PDB",
                        "ihm_external_reference_info_refers_to_fkey"
                    ],
                    "associated_url",
                    "details",
                    [
                        "PDB",
                        "ihm_external_reference_info_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_external_reference_info_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_external_reference_info_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_external_reference_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "reference_id",
                    "reference_provider",
                    [
                        "PDB",
                        "ihm_external_reference_info_reference_type_fkey"
                    ],
                    "reference",
                    [
                        "PDB",
                        "ihm_external_reference_info_refers_to_fkey"
                    ],
                    "associated_url",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_external_reference_info",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_external_files_reference_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "analysis_id",
                    "step_id",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_dataset_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_modeling_post_process_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_feature_fkey"
                    ],
                    "feature_name",
                    "num_models_begin",
                    "num_models_end",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "analysis_id",
                    "step_id",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_dataset_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_modeling_post_process_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_feature_fkey"
                    ],
                    "feature_name",
                    "num_models_begin",
                    "num_models_end",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_modeling_post_process_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_modeling_post_process_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "analysis_id",
                    "step_id",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_dataset_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_modeling_post_process_type_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_feature_fkey"
                    ],
                    "feature_name",
                    "num_models_begin",
                    "num_models_end",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_post_process_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_ensemble_info_post_process_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_2dem_class_average_restraint",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_2dem_class_average_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "number_raw_micrographs",
                    "pixel_size_width",
                    "pixel_size_height",
                    "image_resolution",
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_image_segment_flag_fkey"
                    ],
                    "number_of_projections",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "number_raw_micrographs",
                    "pixel_size_width",
                    "pixel_size_height",
                    "image_resolution",
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_image_segment_flag_fkey"
                    ],
                    "number_of_projections",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "number_raw_micrographs",
                    "pixel_size_width",
                    "pixel_size_height",
                    "image_resolution",
                    [
                        "PDB",
                        "ihm_2dem_class_average_restraint_image_segment_flag_fkey"
                    ],
                    "number_of_projections",
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_2dem_class_average_restraint_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_2dem_class_average_restraint",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_2dem_class_average_fitting_restraint_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_result",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_cross_link_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_ensemble_info.ensemble_id.",
                        "markdown_name": "ensemble id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_ensemble_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "num_models",
                    "distance_threshold",
                    "median_distance",
                    "details",
                    [
                        "PDB",
                        "ihm_cross_link_result_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_cross_link_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_ensemble_info.ensemble_id.",
                        "markdown_name": "ensemble id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_ensemble_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "num_models",
                    "distance_threshold",
                    "median_distance",
                    "details",
                    [
                        "PDB",
                        "ihm_cross_link_result_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_cross_link_result_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_cross_link_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_ensemble_info.ensemble_id.",
                        "markdown_name": "ensemble id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_ensemble_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "num_models",
                    "distance_threshold",
                    "median_distance",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_starting_computational_models",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_starting_computational_models_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_computational_models_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_starting_computational_models_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_computational_models_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_residues_not_modeled",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_residues_not_modeled_reason_fkey"
                    ],
                    "details",
                    {
                        "comment": "Composite key to identify a polymeric residue",
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "Composite key to identify a polymeric residue",
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_residues_not_modeled_reason_fkey"
                    ],
                    "details",
                    {
                        "comment": "Composite key to identify a polymeric residue",
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "Composite key to identify a polymeric residue",
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_residues_not_modeled_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_residues_not_modeled_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_residues_not_modeled_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.entity_id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_residues_not_modeled_reason_fkey"
                    ],
                    "details",
                    {
                        "comment": "Composite key to identify a polymeric residue",
                        "markdown_name": "polymeric residue begin",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "Composite key to identify a polymeric residue",
                        "markdown_name": "polymeric residue end",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_residues_not_modeled_mm_poly_res_label_end_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly_class",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly_class",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "ihm_struct_assembly_class_type_fkey"
                    ],
                    "description"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "ihm_struct_assembly_class_type_fkey"
                    ],
                    "description",
                    [
                        "PDB",
                        "ihm_struct_assembly_class_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_class_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_struct_assembly_class_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    [
                        "PDB",
                        "ihm_struct_assembly_class_type_fkey"
                    ],
                    "description"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly_class",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_struct_assembly_class_link_class_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_related_db_reference",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_related_db_reference_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_related_db_reference_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_db_name_fkey"
                    ],
                    "accession_code",
                    "version",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_related_db_reference_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_related_db_reference_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_db_name_fkey"
                    ],
                    "accession_code",
                    "version",
                    "details",
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_related_db_reference_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_related_db_reference_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_dataset_related_db_reference_db_name_fkey"
                    ],
                    "accession_code",
                    "version",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_axis",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_axis_axis_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_axis_axis_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_axis_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_axis_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_axis_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_geometric_object_axis_axis_type_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_axis_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity_poly",
            "uri": "tag:isrd.isi.edu,2016:generated",
            "value": null
        },
        {
            "schema": "PDB",
            "table": "entity_poly",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{entity_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "entity_poly",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "entity_poly_type_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_nstd_monomer_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_nstd_linkage_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_nstd_chirality_fkey"
                    ],
                    "pdbx_strand_id",
                    [
                        "PDB",
                        "entity_poly_pdbx_sequence_evidence_code_fkey"
                    ],
                    "pdbx_seq_one_letter_code",
                    "pdbx_seq_one_letter_code_can"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_poly_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "entity_poly_type_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_nstd_monomer_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_nstd_linkage_fkey"
                    ],
                    [
                        "PDB",
                        "entity_poly_nstd_chirality_fkey"
                    ],
                    "pdbx_strand_id",
                    [
                        "PDB",
                        "entity_poly_pdbx_sequence_evidence_code_fkey"
                    ],
                    "pdbx_seq_one_letter_code",
                    "pdbx_seq_one_letter_code_can"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "entity_poly",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "entity_poly_seq_entity_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "entity_name_sys",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_sys_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_sys_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "name"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_sys_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "entity_name_sys_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "name"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_non_poly_feature",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "atom_id",
                    [
                        "PDB",
                        "ihm_non_poly_feature_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "atom_id",
                    [
                        "PDB",
                        "ihm_non_poly_feature_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_non_poly_feature_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_non_poly_feature_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_non_poly_feature_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ordinal_id",
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_non_poly_feature_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "atom_id"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_half_torus",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_half_torus_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_half_torus_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "thickness_th",
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_section_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_half_torus_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_half_torus_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "thickness_th",
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_section_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_half_torus_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_half_torus_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "thickness_th",
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_section_fkey"
                    ]
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "pdbx_protein_info",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_protein_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "num_per_asym_unit"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_protein_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "num_per_asym_unit",
                    [
                        "PDB",
                        "pdbx_protein_info_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "pdbx_protein_info_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "pdbx_protein_info_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_protein_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "name",
                    "num_per_asym_unit"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_torus",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{object_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_torus",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_center.id.",
                        "markdown_name": "center id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_center_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "major_radius_R",
                    "minor_radius_r"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_center.id.",
                        "markdown_name": "center id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_center_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "major_radius_R",
                    "minor_radius_r",
                    [
                        "PDB",
                        "ihm_geometric_object_torus_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_torus_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_torus_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_list.object_id.",
                        "markdown_name": "object id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_object_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_center.id.",
                        "markdown_name": "center id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_center_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_geometric_object_transformation.id.",
                        "markdown_name": "transformation id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_torus_transformation_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "major_radius_R",
                    "minor_radius_r"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_torus",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_geometric_object_half_torus_object_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_pseudo_site_feature",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_pseudo_site_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_pseudo_site_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "Cartn_x",
                    "Cartn_y",
                    "Cartn_z",
                    "radius",
                    "description",
                    [
                        "PDB",
                        "ihm_pseudo_site_feature_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_pseudo_site_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_pseudo_site_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "Cartn_x",
                    "Cartn_y",
                    "Cartn_z",
                    "radius",
                    "description",
                    [
                        "PDB",
                        "ihm_pseudo_site_feature_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_pseudo_site_feature_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_pseudo_site_feature_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_pseudo_site_feature_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_pseudo_site_feature_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_feature_list.feature_id.",
                        "markdown_name": "feature id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_pseudo_site_feature_feature_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "Cartn_x",
                    "Cartn_y",
                    "Cartn_z",
                    "radius",
                    "description"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "pdbx_entity_nonpoly",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_nonpoly_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_nonpoly_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_nonpoly_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "name"
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_nonpoly_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_nonpoly_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "pdbx_entity_nonpoly_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "name"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_cross_link_result_parameters",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_cross_link_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "psi",
                    "sigma_1",
                    "sigma_2",
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_cross_link_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "psi",
                    "sigma_1",
                    "sigma_2",
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_cross_link_result_parameters_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_cross_link_restraint.id.",
                        "markdown_name": "restraint id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_restraint_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_model_list.model_id.",
                        "markdown_name": "model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_cross_link_result_parameters_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "psi",
                    "sigma_1",
                    "sigma_2"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "struct",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "entry id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "struct_entry_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "title",
                    "pdbx_descriptor",
                    "pdbx_details",
                    "pdbx_model_details",
                    "pdbx_model_type_details",
                    [
                        "PDB",
                        "struct_pdbx_CASP_flag_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "entry id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "struct_entry_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "title",
                    "pdbx_descriptor",
                    "pdbx_details",
                    "pdbx_model_details",
                    "pdbx_model_type_details",
                    [
                        "PDB",
                        "struct_pdbx_CASP_flag_fkey"
                    ],
                    [
                        "PDB",
                        "struct_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "struct_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "struct_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "entry id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "struct_entry_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "title",
                    "pdbx_descriptor",
                    "pdbx_details",
                    "pdbx_model_details",
                    "pdbx_model_type_details",
                    [
                        "PDB",
                        "struct_pdbx_CASP_flag_fkey"
                    ]
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_modeling_protocol",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_modeling_protocol",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "num_steps",
                    "protocol_name",
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "num_steps",
                    "protocol_name",
                    "details",
                    [
                        "PDB",
                        "ihm_modeling_protocol_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_modeling_protocol_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "num_steps",
                    "protocol_name",
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_modeling_protocol",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_protocol_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_list_protocol_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_post_process_protocol_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_struct_assembly_class_link",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly_class.id.",
                        "markdown_name": "class id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_class_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly_class.id.",
                        "markdown_name": "class id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_class_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_struct_assembly_class_link_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_struct_assembly_class_link_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_struct_assembly_class_link_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly_class.id.",
                        "markdown_name": "class id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_struct_assembly_class_link_class_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_center",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_center",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_center_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "xcoord",
                    "ycoord",
                    "zcoord"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_center_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "xcoord",
                    "ycoord",
                    "zcoord",
                    [
                        "PDB",
                        "ihm_geometric_object_center_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_center_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_center_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_center_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "xcoord",
                    "ycoord",
                    "zcoord"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_center",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_geometric_object_sphere_center_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_torus_center_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_ensemble_info",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{ensemble_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_ensemble_info",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ensemble_id",
                    "ensemble_name",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_modeling_post_process.id.",
                        "markdown_name": "post process id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_post_process_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_ensemble_info_ensemble_clustering_method_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ensemble_info_ensemble_clustering_feature_fkey"
                    ],
                    "num_ensemble_models",
                    "num_ensemble_models_deposited",
                    "ensemble_precision_value",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "ensemble file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_ensemble_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ensemble_id",
                    "ensemble_name",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_modeling_post_process.id.",
                        "markdown_name": "post process id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_post_process_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_ensemble_info_ensemble_clustering_method_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ensemble_info_ensemble_clustering_feature_fkey"
                    ],
                    "num_ensemble_models",
                    "num_ensemble_models_deposited",
                    "ensemble_precision_value",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "ensemble file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_ensemble_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_ensemble_info_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ensemble_info_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_ensemble_info_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "ensemble_id",
                    "ensemble_name",
                    {
                        "comment": "A reference to table ihm_model_group.id.",
                        "markdown_name": "model group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_model_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_modeling_post_process.id.",
                        "markdown_name": "post process id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_post_process_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_ensemble_info_ensemble_clustering_method_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ensemble_info_ensemble_clustering_feature_fkey"
                    ],
                    "num_ensemble_models",
                    "num_ensemble_models_deposited",
                    "ensemble_precision_value",
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "ensemble file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ensemble_info_ensemble_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_ensemble_info",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_cross_link_result_ensemble_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_localization_density_files_ensemble_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_poly_probe_position",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_mutation_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "mut res chem comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mut_res_chem_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_modification_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "mod res chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description",
                    {
                        "comment": "A reference to the polymeric residue composite key",
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_mutation_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "mut res chem comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mut_res_chem_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_modification_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "mod res chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description",
                    {
                        "comment": "A reference to the polymeric residue composite key",
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_position_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_poly_probe_position_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_poly_probe_position_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "entity_id"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table entity_poly_seq.num.",
                        "markdown_name": "seq id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "num"
                        ]
                    },
                    {
                        "comment": "A reference to table entity_poly_seq.mon_id.",
                        "markdown_name": "comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "mon_id"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_mutation_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table chem_comp.id.",
                        "markdown_name": "mut res chem comp id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mut_res_chem_comp_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_poly_probe_position_modification_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_chemical_component_descriptor.id.",
                        "markdown_name": "mod res chem comp descriptor id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description",
                    {
                        "comment": "A reference to the polymeric residue composite key",
                        "markdown_name": "polymeric residue",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_poly_probe_position_mm_poly_res_label_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_poly_probe_position",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_poly_probe_conjugate_position_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_starting_comparative_models",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "starting_model_auth_asym_id",
                    "starting_model_seq_id_begin",
                    "starting_model_seq_id_end",
                    "template_auth_asym_id",
                    "template_seq_id_begin",
                    "template_seq_id_end",
                    "template_sequence_identity",
                    [
                        "PDB",
                        "starting_comparative_models_template_sequence_id_denom_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "template dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_template_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "alignment file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_alignment_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "starting_model_auth_asym_id",
                    "starting_model_seq_id_begin",
                    "starting_model_seq_id_end",
                    "template_auth_asym_id",
                    "template_seq_id_begin",
                    "template_seq_id_end",
                    "template_sequence_identity",
                    [
                        "PDB",
                        "starting_comparative_models_template_sequence_id_denom_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "template dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_template_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "alignment file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_alignment_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    [
                        "PDB",
                        "ihm_starting_comparative_models_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_comparative_models_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_starting_comparative_models_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_starting_model_details.starting_model_id.",
                        "markdown_name": "starting model id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_starting_model_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "starting_model_auth_asym_id",
                    "starting_model_seq_id_begin",
                    "starting_model_seq_id_end",
                    "template_auth_asym_id",
                    "template_seq_id_begin",
                    "template_seq_id_end",
                    "template_sequence_identity",
                    [
                        "PDB",
                        "starting_comparative_models_template_sequence_id_denom_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "template dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_template_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "alignment file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_comparative_models_alignment_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_modeling_protocol_details",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "step_id",
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_dataset_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "struct_assembly_description",
                    "step_name",
                    "step_method",
                    "num_models_begin",
                    "num_models_end",
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_multi_scale_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_multi_state_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_ordered_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_ensemble_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "step_id",
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_dataset_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "struct_assembly_description",
                    "step_name",
                    "step_method",
                    "num_models_begin",
                    "num_models_end",
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_multi_scale_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_multi_state_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_ordered_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_ensemble_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description",
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    {
                        "comment": "A reference to table ihm_modeling_protocol.id.",
                        "markdown_name": "protocol id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_protocol_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "step_id",
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_dataset_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_struct_assembly.id.",
                        "markdown_name": "struct assembly id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_struct_assembly_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "struct_assembly_description",
                    "step_name",
                    "step_method",
                    "num_models_begin",
                    "num_models_end",
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_multi_scale_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_multi_state_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_ordered_flag_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_modeling_protocol_details_ensemble_flag_fkey"
                    ],
                    {
                        "comment": "A reference to table ihm_external_files.id.",
                        "markdown_name": "script file id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_script_file_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table software.pdbx_ordinal.",
                        "markdown_name": "software id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_modeling_protocol_details_software_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "description"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_ligand_probe",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_probe_list.probe_id.",
                        "markdown_name": "probe id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_probe_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_ligand_probe_Entry_Related_File_fkey"
                    ]
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_probe_list.probe_id.",
                        "markdown_name": "probe id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_probe_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_ligand_probe_Entry_Related_File_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ligand_probe_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_ligand_probe_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_ligand_probe_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_probe_list.probe_id.",
                        "markdown_name": "probe id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_probe_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "details",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_ligand_probe_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_transformation",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_transformation",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_transformation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "rot_matrix_1_1",
                    "rot_matrix_1_2",
                    "rot_matrix_1_3",
                    "rot_matrix_2_1",
                    "rot_matrix_2_2",
                    "rot_matrix_2_3",
                    "rot_matrix_3_1",
                    "rot_matrix_3_2",
                    "rot_matrix_3_3",
                    "tr_vector_1",
                    "tr_vector_2",
                    "tr_vector_3"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_transformation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "rot_matrix_1_1",
                    "rot_matrix_1_2",
                    "rot_matrix_1_3",
                    "rot_matrix_2_1",
                    "rot_matrix_2_2",
                    "rot_matrix_2_3",
                    "rot_matrix_3_1",
                    "rot_matrix_3_2",
                    "rot_matrix_3_3",
                    "tr_vector_1",
                    "tr_vector_2",
                    "tr_vector_3",
                    [
                        "PDB",
                        "ihm_geometric_object_transformation_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_transformation_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_geometric_object_transformation_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_geometric_object_transformation_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "id",
                    "rot_matrix_1_1",
                    "rot_matrix_1_2",
                    "rot_matrix_1_3",
                    "rot_matrix_2_1",
                    "rot_matrix_2_2",
                    "rot_matrix_2_3",
                    "rot_matrix_3_1",
                    "rot_matrix_3_2",
                    "rot_matrix_3_3",
                    "tr_vector_1",
                    "tr_vector_2",
                    "tr_vector_3"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_geometric_object_transformation",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_geometric_object_sphere_transformation_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_torus_transformation_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_axis_transformation_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_geometric_object_plane_transformation_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_dataset_group_link",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_dataset_group_link_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_dataset_group_link_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_dataset_group_link_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_dataset_group.id.",
                        "markdown_name": "dataset group id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_dataset_group_link_group_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    }
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2016:table-display",
            "value": {
                "row_name": {
                    "row_markdown_pattern": "{{{starting_model_id}}}"
                }
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2016:visible-columns",
            "value": {
                "*": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "starting_model_id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_starting_model_details_starting_model_source_fkey"
                    ],
                    "starting_model_auth_asym_id",
                    "starting_model_sequence_offset",
                    "description",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "mmCIF_File_URL"
                ],
                "detailed": [
                    "RID",
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "starting_model_id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_starting_model_details_starting_model_source_fkey"
                    ],
                    "starting_model_auth_asym_id",
                    "starting_model_sequence_offset",
                    "description",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "mmCIF_File_URL",
                    {
                        "markdown_name": "mmCIF File Size (Bytes)",
                        "source": "mmCIF_File_Bytes"
                    },
                    [
                        "PDB",
                        "ihm_starting_model_details_RCB_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_details_RMB_fkey"
                    ],
                    "RCT",
                    "RMT",
                    [
                        "PDB",
                        "ihm_starting_model_details_Owner_fkey"
                    ]
                ],
                "entry": [
                    {
                        "comment": "A reference to table entry.id.",
                        "markdown_name": "structure id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_structure_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "starting_model_id",
                    {
                        "comment": "A reference to table entity.id.",
                        "markdown_name": "entity id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_entity_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "entity_description",
                    {
                        "comment": "A reference to table struct_asym.id.",
                        "markdown_name": "asym id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_asym_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    {
                        "comment": "A reference to table ihm_entity_poly_segment.id.",
                        "markdown_name": "entity poly segment id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_entity_poly_segment_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    [
                        "PDB",
                        "ihm_starting_model_details_starting_model_source_fkey"
                    ],
                    "starting_model_auth_asym_id",
                    "starting_model_sequence_offset",
                    "description",
                    {
                        "comment": "A reference to table ihm_dataset_list.id.",
                        "markdown_name": "dataset list id",
                        "source": [
                            {
                                "outbound": [
                                    "PDB",
                                    "ihm_starting_model_details_dataset_list_id_fkey"
                                ]
                            },
                            "RID"
                        ]
                    },
                    "mmCIF_File_URL"
                ]
            }
        },
        {
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2016:visible-foreign-keys",
            "value": {
                "detailed": [
                    [
                        "PDB",
                        "ihm_starting_comparative_models_starting_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_computational_models_starting_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_starting_model_seq_dif_starting_model_id_fkey"
                    ],
                    [
                        "PDB",
                        "ihm_model_representation_details_starting_model_id_fkey"
                    ]
                ],
                "filter": "detailed"
            }
        }
    ],
    "catalog_annotations": [
        {
            "uri": "tag:isrd.isi.edu,2017:bulk-upload",
            "value": {
                "asset_mappings": [
                    {
                        "asset_type": "table",
                        "default_columns": [
                            "RID",
                            "RCB",
                            "RMB",
                            "RCT",
                            "RMT"
                        ],
                        "ext_pattern": "^.*[.](?P<file_ext>json|csv)$",
                        "file_pattern": "^((?!/assets/).)*/records/(?P<schema>WWW?)/(?P<table>Page)[.]",
                        "target_table": [
                            "WWW",
                            "Page"
                        ]
                    },
                    {
                        "checksum_types": [
                            "md5"
                        ],
                        "column_map": {
                            "Filename": "{file_name}",
                            "Length": "{file_size}",
                            "MD5": "{md5}",
                            "Page": "{table_rid}",
                            "URL": "{URI}"
                        },
                        "dir_pattern": "^.*/(?P<schema>WWW)/(?P<table>Page)/(?P<key_column>.*)/",
                        "ext_pattern": "^.*[.](?P<file_ext>.*)$",
                        "file_pattern": ".*",
                        "hatrac_options": {
                            "versioned_uris": true
                        },
                        "hatrac_templates": {
                            "hatrac_uri": "/hatrac/{schema}/{table}/{md5}.{file_name}"
                        },
                        "metadata_query_templates": [
                            "/attribute/D:={schema}:{table}/RID={key_column}/table_rid:=D:RID"
                        ],
                        "record_query_template": "/entity/{schema}:{table}_Asset/{table}={table_rid}/MD5={md5}/URL={URI_urlencoded}",
                        "target_table": [
                            "WWW",
                            "Page_Asset"
                        ]
                    }
                ],
                "version_compatibility": [
                    [
                        ">=0.4.3",
                        "<1.0.0"
                    ]
                ],
                "version_update_url": "https://github.com/informatics-isi-edu/deriva-qt/releases"
            }
        }
    ],
    "foreign_key_annotations": [
        {
            "foreign_key": "ihm_localization_density_files_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_localization_density_files",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_localization_density_files_ensemble_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_localization_density_files",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_localization_density_files_entity_poly_segment_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_localization_density_files",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_localization_density_files_file_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_localization_density_files",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_localization_density_files_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_localization_density_files",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_representative_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_representative",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_representative_model_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_representative",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "chem_comp_atom_comp_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "chem_comp_atom",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "entity_poly_seq_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "entity_poly_seq",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "entity_poly_seq_mon_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "entity_poly_seq",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "citation_author_citation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "citation_author",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_dataset_external_reference_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_dataset_external_reference",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_dataset_external_reference_file_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_dataset_external_reference",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_struct_assembly_details_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_struct_assembly_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_struct_assembly_details_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_struct_assembly_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_struct_assembly_details_entity_poly_segment_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_struct_assembly_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_struct_assembly_details_parent_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_struct_assembly_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_struct_assembly_details_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_struct_assembly_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "entity_src_gen_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "entity_src_gen",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "entity_name_com_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "entity_name_com",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_list_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_list_linker_chem_comp_descriptor_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_list_mm_poly_res_label_1_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Cross Link List Label 1",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_cross_link_list_mm_poly_res_label_2_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Cross Link List Label 2",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_probe_list_probe_chem_comp_descriptor_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_probe_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_probe_list_reactive_probe_chem_comp_descriptor_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_probe_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "struct_asym_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "struct_asym",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_multi_state_model_group_link_model_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_multi_state_model_group_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_multi_state_model_group_link_state_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_multi_state_model_group_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_epr_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_epr_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_epr_restraint_fitting_software_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_epr_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_epr_restraint_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_epr_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_epr_restraint_fitting_method_citation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_epr_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_2dem_class_average_fitting_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_2dem_class_average_fitting",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_2dem_class_average_fitting_restraint_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_2dem_class_average_fitting",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "software_citation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "software",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_probe_conjugate_chem_comp_descriptor_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_probe_conjugate",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_probe_conjugate_position_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_probe_conjugate",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_probe_conjugate_probe_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_probe_conjugate",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_probe_conjugate_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_probe_conjugate",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_list_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_list_representation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_list_protocol_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_list",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "pdbx_entity_poly_na_type_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "pdbx_entity_poly_na_type",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_sphere_object_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_sphere",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_sphere_center_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_sphere",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_sphere_transformation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_sphere",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_residue_feature_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_residue_feature_mm_poly_res_label_end_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Poly Contact Residue Feature End",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_poly_residue_feature_feature_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_residue_feature_mm_poly_res_label_begin_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Poly Contact Residue Feature Begin",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_interface_residue_feature_binding_partner_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_interface_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_interface_residue_feature_feature_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_interface_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_interface_residue_feature_binding_partner_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_interface_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_interface_residue_feature_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_interface_residue_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_plane_transformation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_plane",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_plane_object_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_plane",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_predicted_contact_restraint_mm_poly_res_label_2_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_predicted_contact_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Predicted Contact Restraint Label 2",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_predicted_contact_restraint_software_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_predicted_contact_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_predicted_contact_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_predicted_contact_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_predicted_contact_restraint_mm_poly_res_label_1_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_predicted_contact_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Predicted Contact Restraint Label 1",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_3dem_restraint_struct_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_3dem_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_3dem_restraint_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_3dem_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_3dem_restraint_fitting_method_citation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_3dem_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_3dem_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_3dem_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_derived_distance_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_derived_distance_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_restraint_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_restraint_mm_poly_res_label_2_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Cross Link Restraint Label 2",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_cross_link_restraint_mm_poly_res_label_1_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Cross Link Restraint Label 1",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_model_group_link_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_group_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_group_link_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_group_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_atom_feature_feature_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_atom_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_atom_feature_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_atom_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_representation_details_representation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_representation_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_representation_details_starting_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_representation_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_representation_details_entity_poly_segment_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_representation_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_representation_details_entity_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_representation_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_model_representation_details_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_model_representation_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_sas_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_sas_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_sas_restraint_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_sas_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_sas_restraint_struct_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_sas_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_entity_poly_segment_mm_poly_res_label_begin_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_entity_poly_segment",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Entity Poly Segment Begin",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_entity_poly_segment_mm_poly_res_label_end_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_entity_poly_segment",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Entity Poly Segment End",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_hydroxyl_radical_fp_restraint_software_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_hydroxyl_radical_fp_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_hydroxyl_radical_fp_restraint_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_hydroxyl_radical_fp_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_hydroxyl_radical_fp_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_hydroxyl_radical_fp_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_model_seq_dif_starting_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_model_seq_dif",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_model_seq_dif_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_model_seq_dif",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_model_seq_dif_mm_poly_res_label_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_model_seq_dif",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Starting Model Seq Dif",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_distance_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_distance_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_distance_restraint_feature_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_distance_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_distance_restraint_object_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_distance_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_external_files_reference_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_external_files",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_post_process_protocol_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_post_process_struct_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_post_process_dataset_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_post_process_script_file_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_post_process_software_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_post_process",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_2dem_class_average_restraint_struct_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_2dem_class_average_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_2dem_class_average_restraint_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_2dem_class_average_restraint",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_result_ensemble_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_result",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_result_restraint_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_result",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_computational_models_script_file_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_computational_models",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_computational_models_starting_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_computational_models",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_computational_models_software_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_computational_models",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_residues_not_modeled_mm_poly_res_label_begin_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_residues_not_modeled",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Residues Not Modeled Begin",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_residues_not_modeled_mm_poly_res_label_end_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_residues_not_modeled",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "{{#if _structure_id}}structure_id={{{_structure_id}}}{{/if}}",
                "from_name": "Ihm Residues Not Modeled End",
                "template_engine": "handlebars"
            }
        },
        {
            "foreign_key": "ihm_residues_not_modeled_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_residues_not_modeled",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_residues_not_modeled_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_residues_not_modeled",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_dataset_related_db_reference_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_dataset_related_db_reference",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_axis_transformation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_axis",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_axis_object_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_axis",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "entity_poly_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "entity_poly",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "entity_name_sys_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "entity_name_sys",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_non_poly_feature_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_non_poly_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_non_poly_feature_feature_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_non_poly_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_non_poly_feature_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_non_poly_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_non_poly_feature_comp_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_non_poly_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_half_torus_object_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_half_torus",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_torus_transformation_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_torus",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_torus_object_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_torus",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_geometric_object_torus_center_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_geometric_object_torus",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_pseudo_site_feature_feature_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_pseudo_site_feature",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "pdbx_entity_nonpoly_comp_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "pdbx_entity_nonpoly",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "pdbx_entity_nonpoly_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "pdbx_entity_nonpoly",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_result_parameters_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_result_parameters",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_cross_link_result_parameters_restraint_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_cross_link_result_parameters",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_struct_assembly_class_link_class_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_struct_assembly_class_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_struct_assembly_class_link_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_struct_assembly_class_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_ensemble_info_post_process_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_ensemble_info",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_ensemble_info_ensemble_file_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_ensemble_info",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_ensemble_info_model_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_ensemble_info",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_probe_position_mut_res_chem_comp_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_probe_position",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_poly_probe_position_mod_res_chem_comp_descriptor_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_poly_probe_position",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_comparative_models_starting_model_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_comparative_models",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_comparative_models_alignment_file_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_comparative_models",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_comparative_models_template_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_comparative_models",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_protocol_details_software_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_protocol_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_protocol_details_struct_assembly_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_protocol_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_protocol_details_script_file_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_protocol_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_protocol_details_dataset_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_protocol_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_modeling_protocol_details_protocol_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_modeling_protocol_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_ligand_probe_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_ligand_probe",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_ligand_probe_probe_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_ligand_probe",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_ligand_probe_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_ligand_probe",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_dataset_group_link_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_dataset_group_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_dataset_group_link_group_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_dataset_group_link",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_model_details_asym_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_model_details_entity_poly_segment_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_model_details_dataset_list_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        },
        {
            "foreign_key": "ihm_starting_model_details_entity_id_fkey",
            "foreign_key_schema": "PDB",
            "schema": "PDB",
            "table": "ihm_starting_model_details",
            "uri": "tag:isrd.isi.edu,2016:foreign-key",
            "value": {
                "domain_filter_pattern": "structure_id={{structure_id}}"
            }
        }
    ]
}