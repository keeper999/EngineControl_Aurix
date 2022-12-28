/*
* File: VSSP_Torque_Control_Gmp2_Sf.c
*
*                   Delphi Diesel Systems
*
*                   This document is the property of
*                   Delphi Diesel Systems
*                   It must not be copied (in whole or in part)
*                   or disclosed without prior written consent
*                   of the company. Any copies by any method
*                   must also include a copy of this legend.
*
* Real-Time Workshop code generated for Simulink model VSSP_Torque_Control_Gmp2_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Tue Apr 10 15:12:30 2012
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Tue Apr 10 15:12:32 2012
*
* Post task done by tool Aut_Autocode_Post.pl version 11.89
*        with rules Aut_Rules_For_Autocode_Post.pm version 12.10
*        with stack reduction algorithm Aut_Stack_Analyzer.pm version 4.00
*
* Code generated from spec : R6512345_10
*
* LABEL USED: LIBRARY_R6510684_19_0_1
*
* Options settings:
*        ALLOW_STANDARD_SIMULINK_BLOCK = 'DDS_FALSE'
*        DELETE_TEMPORARY_MODEL = 'DDS_TRUE'
*        GENERATE_A2L = 'DDS_FALSE'
*        MACRO_REVISION = 'DDS_TRUE'
*        NUMBER_OF_BITS_CHAR = 8
*        NUMBER_OF_BITS_SHORT =16
*        NUMBER_OF_BITS_INT =32
*        NUMBER_OF_BITS_LONG =32
*        NUMBER_OF_BITS_NATIVE_WORD_SIZE = 32
*        BYTE_ORDERING = 'BigEndian'
*        FIXED_POINT_ROUNDING_METHOD = 'Fix'
*        TIMER_1S='S_S_1S_U32_TIME'
*        TIMER_1MS='S_S_1MS_U32_TIME'
*        TIMER_100US='S_S_100US_U32_TIME'
*        TIMER_10US='S_S_10US_U32_TIME'
*        TIMER_1US='S_S_1US_U32_TIME'
*        ENABLE_POST_TASK = 'DDS_TRUE'
*        TASK_AND_DATA_CROSS_CHECK='DDS_TRUE'
*        DATA_NAMING_CONVENTION = 'DDS_TRUE'
*        ALLOW_NATIVE_SIMULINK_CONVERT_BLOCK = 'DDS_FALSE'
*        ENABLE_T55_CHECK = 'DDS_TRUE'
*        ENABLE_DDS_CAST = 'DDS_TRUE'
*        DDS_ADDITION = 'DDS_TRUE'
*        DDS_SUBSTRACTION = 'DDS_TRUE'
*        DDS_MULTIPLICATION = 'DDS_TRUE'
*        DDS_DIVIDE = 'DDS_TRUE'
*        DDS_CALC_VERBOSE_MODE='DDS_FALSE'
*        ENABLE_DDS_DIVIDE_ZPROT_PARAMETER = 'DDS_FALSE'
*        SITE_LOCATION='LIGHT_DUTY'
*        ARRAY_DECLARATION_METHOD = 'DDS_ARRAY_FORMAT'
*        ENABLE_SERVER_CAPABILITY = 'DDS_TRUE'
*        HOST_NAME ='DL11XW55J'
*        RETAIN_FILES_ON_SHARED_DIRECTORY='DDS_FALSE'
*        DRIVE_LETTER_USED_BY_SERVER = 'Z'
*        VIEW_USED_BY_SERVER='USER_VIEW'
*        VOB_NAME = 'blois_esys'
*        VIEW_SERVER_OPTION_IN_GUI='DDS_TRUE'
*        ALLOWED_INCLUDE_REGULAR='';
*        ENABLE_DD_IN_FILE = 'DDS_FALSE'
*        CALIBRATION_MNGT_MODE = 'INTO_C_FILE'
*        OUTPUT_RANGE_LIMITATION_MODE='INTO_SUB_SYSTEM'
*        UNIT_MEMORY_BLOCK_SELECTION_METHOD = 'DDS_BLOCK'
*        SWITCH_BLOCK_SELECTION_METHOD = 'SIMULINK_BLOCK'
*        SWITCH_OPTIMIZATION_ACTIVATED = 'DDS_FALSE'
*        CODE_FORMAT = 'DDS_SSTG'
*        ENABLE_EDITOR_CAPABILITY = 'DDS_TRUE'
*        EDITOR_PATH_1 ='C:\Program Files\TextPad 4\textpad.exe';
*        EDITOR_PATH_2 ='C:\Program Files\TextPad 5\textpad.exe';
*        EDITOR_PATH_3 ='C:\Program Files\Notepad++\notepad++.exe';
*        EDITOR_PATH_4 ='';
*        CALIBRATION_MNGT_MODE_WITH_CONSTANT = 'IN_EXTERNAL_FEATURE_FILE'
*        DATATYPE_MIN_SELECTION_NO_32BIT_OPT = 'NEG_DATATYPE_MAX'
*        DATATYPE_MIN_SELECTION_32BIT_OPT = 'NEG_DATATYPE_MAX'
*        SNAPSHOT_MODE = 'CRITICAL_SECTION_FOR_LINKED_INPUTS_ONLY'
*        CRITICAL_SECTION_START_NAME ='S_S_CRIT_SECT_SNAPSHOT_START'
*        CRITICAL_SECTION_END_NAME ='S_S_CRIT_SECT_SNAPSHOT_END'
*        INCLUDE_TO_CALL_FOR_INTERRUPTS = 's_s_os.h';
*        COMMENT_OPTION='REMOVE_BLOCKS_COMMENTS'
*        MODEL_COLOR_MNGT_MODE = 'MODEL_COLOR_CHANGE_ALLOWED'
*        DISPLAYING_MODE='SORTED_WRITING'
*        EXPAND_SORTED_DISCARDED_ERROR_LIST='NO'
*        EXPAND_SORTED_DISABLED_ERROR_LIST='NO'
*        EXPAND_SORTED_WARNING_LIST='NO'
*        EXPAND_SORTED_ERROR_LIST='YES'
*
* Autocode Optimization options used by user mzjm1k:
*        AUTOCODE_OPTIMIZATION_NO_SNAPSHOT: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_BYPASS_ERROR_LST: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_FORCE_SNAPSHOT: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_SNAPSHOT_INTERRUPT_MODE: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_NO_RANGE_LIMITATION: OPTION_NOT_USED
*
* Libraries versions:
*        aut_ems_lib version 19.0
*
* Common dll version 3.0
*
* Blocks versions:
*        AUT_EC_Function_Stub_v1 SFunction version: 7.0, TLC version: 2.0
*        AUT_EC_m_limit_opt SFunction version: 5.0, TLC version: 13.2
*        AUT_EC_m_min_opt SFunction version: 4.0, TLC version: 4.0
*        AUT_EC_Keep_Global_Data_From_Input SFunction version: 9.0, TLC version: 13.2
*
* Scripts versions:
*        aut_add_io version 3.0                                        aut_array_size_list_manager version 1.0
*        aut_assign_const_parameter_to_table_init version 4.2          aut_autocode_optimization version 10.0
*        aut_calc_block_before_limiter version 8.0                     aut_cast_block_before_limiter version 4.0
*        aut_check_accuracy_loss version 7.0                           aut_check_blocks_fields_values version 3.0
*        aut_check_calc_blocks version 44.0                            aut_check_downcast version 5.0
*        aut_check_if_data_exists_into_workps version 4.0              aut_check_if_data_if_an_nvv_data_store version 3.0
*        aut_check_if_data_is_in_full_range version 2.0                aut_check_if_data_is_shared version 3.0
*        aut_check_if_globlal_T55_exist version 3.0                    aut_check_if_parameter_present_into_model version 3.0
*        aut_check_if_previous_block_equal_to_type version 4.0         aut_check_if_range_is_compatible_with_datatype version 5.0
*        aut_check_model_vs_workspace version 6.0                      aut_check_pointer_access version 3.0
*        aut_chk_lcs version 3.0                                       aut_create_alias_type version 3.0
*        aut_create_data version 26.0                                  aut_create_enum version 13.0
*        aut_create_hyperlink_command_from_block version 3.0           aut_create_intermediate_constants version 4.0
*        aut_create_sstg_architecture version 10.0                     aut_cross_check_T55_mdl_init version 4.0
*        aut_detect_variable_type_or_name version 3.0                  aut_ec_maskinitialization_common_function version 2.0
*        aut_ec_sp_aut_unit_delay_memory_effect_callback version 1.0   aut_fault_display_manager version 1.0
*        aut_find_source_block_path version 8.0                        aut_fixed_point_toolbox_interface version 5.0
*        aut_format_cpv_initialization_line version 10.0               aut_free_up_unexpected_block version 4.0
*        aut_get_array_apv_according_calibration_mode version 5.0      aut_get_data_list_from_link_output_block version 3.0
*        aut_get_data_size version 3.0                                 aut_get_deeper_block_from_list version 3.0
*        aut_get_error_list version 1.0                                aut_get_evaluated_value_from_constant version 4.0
*        aut_get_filtered_error_list version 1.0                       aut_get_final_datatype version 3.0
*        aut_get_information_from_next_block version 17.0              aut_get_information_from_previous_block version 33.0
*        aut_get_key version 3.0                                       aut_get_sigtype_info version 3.0
*        aut_get_snapshot_under_critical_lst_tag version 1.0           aut_get_squeduling_list version 17.0
*        aut_get_src_handle_from_previous_block_and_port_index version 3.0aut_get_static_data_list version 4.0
*        aut_init_value_check version 5.0                              aut_key_alg version 3.0
*        aut_manage_autocode_model version 15.0                        aut_manage_compilation_mode version 4.0
*        aut_manage_doc_block version 7.0                              aut_manage_limiter version 12.0
*        aut_manage_model_workspace version 3.0                        aut_manage_simulink_to_post_task_exchange version 55.0
*        aut_manage_snapshot version 27.0                              aut_mode_switch version 70.0
*        aut_model_autocode version 26.0                               aut_model_configure version 7.0
*        aut_pre_autocode version 56.0                                 aut_prepare_t55_task version 29.0
*        aut_prepare_t55_task_for_tag version 9.0                      aut_process_mngt version 61.0
*        aut_project_settings version 24.0                             aut_signal_config version 14.0
*        aut_sstg_manage_signal_memory_location version 6.0            aut_stateflow_checks version 7.0
*        aut_step_ckecks version 4.0                                   aut_switch_cpv_initialization version 14.0
*        aut_tlc_check_if_min_requested_instead_of_limit version 3.0   aut_tlc_evaluate version 1.0
*        aut_tlc_get_block_init_string version 8.0                     aut_tlc_regexp version 1.0
*        aut_tlc_static_variable_name_calculation version 6.0          aut_types version 3.0
*        aut_unset_set_block_properties_of_subsytem version 8.0        aut_update_init_file_with_tag version 4.0
*        sim_attributes_format_string version 5.3                      sim_check_unlinked_blocks version 11.0
*        sim_configure_simulation_mode version 9.0                     sim_display_dd_settings version 5.0
*        sim_format_hyperlink_message version 11.0                     sim_function_stub version 3.0
*        sim_get_autorisation_for_limitation version 3.0               sim_get_library_references version 53.0
*        sim_get_library_version version 3.0                           sim_get_static_data_block version 3.0
*        sim_load_libraries version 3.0                                sim_manage_block_tab version 7.0
*        sim_manage_config_set version 4.0                             sim_manage_link_status_warning version 3.0
*        sim_manage_structure_dd_display version 2.0                   sim_manage_structure_signals version 5.0
*        sim_maskinitialization_common_function version 4.0            sim_migration_patch_requested version 1.0
*        sim_not_callback version 2.0                                  sim_prepare_limitation version 60.0
*        sim_restore_previous_tag_version version 3.0                  sim_set version 1.0
*        sim_set_hdl version 1.0                                       sim_set_ic version 1.0
*        sim_set_param version 3.0                                     sim_sf_get_param version 7.0
*        sim_switch_block_mode version 5.0                             sim_unit_delay_callback version 2.0
*        sim_update_block_display_status version 22.0                  sim_warning_control version 6.0
*
* Config Spec:
*        element * CHECKEDOUT
*        element clearcase\... \main\LATEST
*        element livraison\... \main\LATEST
*        element tests\... \main\LATEST
*        element Appli\ /main/LATEST
*        element \DDS_E_Documents_Vob\...  /main/LATEST
*        element * LABEL_SSTG_AUTOCODING
*        element * LIBRARY_R6510684_19_0_1
*        element * ModelPrepare_V3_1_1
*        element Environnement\ \main\LATEST
*        element Environnement\Autosar\ \main\LATEST
*        element Environnement\exe\ \main\LATEST
*        element \ldcr_tools\... GEN_RTE_VERSION_3_1_2_A
*        element /ldcr_tools/... SWC_ARXML_EURO6_CDC_1_9
*        element * 00PSASWC_L10AD01
*        element Appli\VSInfo\ /main/LATEST
*        element Appli\VSInfo\src\ /main/LATEST
*        element Environnement\ /main/LATEST
*        element Environnement\exe\ /main/LATEST
*        element * LABEL_DEMEZIL_VSINFO_VIEW
*        element Appli\SC\ /main/LATEST
*        element \ldcr_tools\Autosar_Tools /main/LATEST
*        element * INT2ULP_3_1_6
*        element * INTERNAL_FLASH_MAPPER_V07_45
*        element * TwkCheck32_V5.4
*        element \ldcr_tools \main\LATEST
*        element \ldcr_tools\... A2L_GNU_SH
*        element \ldcr_tools\... DIAB_5610_2
*        element \ldcr_tools\... GEN_RTE_VERSION_2_0_7
*        element \ldcr_tools\... GNUSH_401
*        element \ldcr_tools\... INTERNAL_FLASH_MAPPER_V07_40
*        element \ldcr_tools\... SWC_AUTOCODING_GET_ENUM_LABEL_0_11
*        element \ldcr_tools\... SWC_AUTOCODING_PREPARE_0_11
*        element \ldcr_tools\... SWC_AUTOCODING_STATEFLOW_COMPARE_1_00
*        element \ldcr_tools\... SWC_CHECK_CALIBRATION_2_10
*        element \ldcr_tools\... SWC_CODE_CHECKER_EURO6_1_14
*        element \ldcr_tools\... SWC_DELIVERY_REPORTER_EURO6_1_00
*        element \ldcr_tools\... SWC_DELIVERY_CHECKER_EURO6_2_01
*        element \ldcr_tools\... SWC_INCA_CSV_GENERATOR_0_20
*        element \ldcr_tools\... SWC_LAB_GENERATOR_1_01
*        element \ldcr_tools\... SWC_MAIN_CODE_GENERATOR_EURO6_1_01
*        element \ldcr_tools\... SWC_PREPA_VALID_4_1_1_228
*        element \ldcr_tools\... SWC_SCENARIO_INIT_BYPASS_GENERATOR_1_02
*        element \ldcr_tools\... SWC_STIL_TO_IO_LIST_GENERATOR_EURO6_0_11
*        element \ldcr_tools\... SWC_STUB_GENERATOR_EURO6_1_01
*        element \ldcr_tools\... SWC_TASK_CODE_GENERATOR_EURO6_0_11
*        element \ldcr_tools\... SWC_VALID_CHECK_SCENARIO_1_2
*        element \ldcr_tools\... SWC_VALID_GEN_REPORT_1_5
*        element arxml_swc_generator\... ARXML_SWC_GENERATOR_1_18
*        element \ldcr_tools\... SWC_ARXML_INTEGRATION_CHECKER_EURO6_1_00
*        element swc_stix_arxml_checker\... SWC_STIX_ARXML_CHECKER_1_33
*        element \ldcr_tools\... /main/LATEST
*        element * 00PSASWC_D220D01
*        element * 00PSAATS_B210D01
*        element \ldcr_tools \main\LATEST
*        element * INT2ULP_3_1_6
*        element \ldcr_tools\... DIAB_5610_2
*        element \ldcr_tools\... INTERNAL_FLASH_MAPPER_V07_40
*        element \ldcr_tools\... A2L_GNU_SH
*        element \ldcr_tools\... GNUSH_401
*        element \ldcr_tools\... GEN_RTE_VERSION_2_0_7
*        element \ldcr_tools\... /main/LATEST
*        element -directory \blois_esoft\... \main\LATEST
*        element \blois_esoft\... \main\main_tcb\LATEST
*        element \blois_esoft\... \main\0 -mkbranch main_tcb
*        element \ldcr_doc\... /main/LATEST
*        element doc\... \main\LATEST
*        element Doc\... \main\LATEST
*
* Block list with autocode bypass option activated:
*        No bypassed blocks into this model
*
* Ref X:\integration_view_00PSASWC_D821D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Torque_Control_Gmp2_Sf.c
* Version int :/main/L03_01/2 Date: 11/4/2012 15 h 13 m User:meme 
*    TWK_model:VSSP_Torque_Control_Gmp2_Sf_L03_010_IMPL1_D
*    comments :For VSSp_12_1_e6
* Version dev :\main\branch_halouane_vssp_euro6\1 Date: 11/4/2012 11 h 44 m User:halouane 
*    TWK_model:VSSP_Torque_Control_Gmp2_Sf_L03_010_IMPL1_D
*    comments :For VSSp_12_1_e6
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Autorisation_Recuperation_Energie */

/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Autorisation_Recuperation_Energie ;VSCtl_bCtlEfc_tqCkEfcMax;VSCtl_bCtlEfc_tqCkEfcMin;VSCtl_stCtl_tqCkEfcMax;VSCtl_stCtl_tqCkEfcMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Autorisation_Recuperation_Energie ;VSCtl_bInhRecup; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Autorisation_Recuperation_Energie */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Pilotage_Potentiel_Couple_Roue_GMP */

/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Pilotage_Potentiel_Couple_Roue_GMP ;Ext_stCtlCmdPTTqPotCf;VSCtl_stCtl_tqWhlPTPotMax;VSCtl_stCtl_tqWhlPTPotMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Pilotage_Potentiel_Couple_Roue_GMP ;VSCtl_stTqWhlPTPotCtlReq;VSCtl_tiHldWhlPotCtlReq; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Pilotage_Potentiel_Couple_Roue_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Max */

/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Max ;VSCtl_stCtl_tqCkEfcMax;VSCtl_tqCkEfcMaxReq;VSCtl_tqCkEfcMinReq;VSCtl_tqCkEfcPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Max ;VSCtl_bCtlEfc_tqCkEfcMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Min ;VSCtl_stCtl_tqCkEfcMin;VSCtl_tqCkEfcMinReq;VSCtl_tqCkEfcPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Min ;VSCtl_bCtlEfc_tqCkEfcMin; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Moteur_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max ;AccP_rAccP;VSCtl_rAccPEngMax;VSCtl_stCtl_tqCkEfcMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max ;VSCtl_bCtlEfc_rAccPMax_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min ;AccP_rAccP;VSCtl_rAccPEngMin;VSCtl_stCtl_tqCkEfcMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min ;VSCtl_bCtlEfc_rAccPMin_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV */

/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV ;VSCtl_bCtlEfc_rAccPMax_pt2;VSCtl_bCtlEfc_rAccPMin_pt2;VSCtl_bCtlEfc_tqCkEfcMax;VSCtl_bCtlEfc_tqCkEfcMin;VSCtl_stCtl_tqCkEfcMax;VSCtl_stCtl_tqCkEfcMin; */

/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV ;VSCtl_bCtlEfc_tqWhlPT_pt2;VSCtl_stTqPTMaxCtl_pt2;VSCtl_stTqPTMinCtl_pt2;VSCtl_st_rAccPCtl_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV */

/* TAG_START_OF_SUB_FUNCTION: F71312_Determiner_Consigne_Couple_Moteur_Min */

/* TAG_INPUT_OF_SUB_FUNCTION: F71312_Determiner_Consigne_Couple_Moteur_Min ;VSCtl_bAntTqWhlPTMinReq;VSCtl_rAnt_tqWhlPTMin;VSCtl_rConvTra;VSCtl_stCtl_tqCkEfcMin;VSCtl_stTqWhlPTCutOffReqPrev;VSCtl_tqCkEfcMax;VSCtl_tqCkEfcMaxNotCtla;VSCtl_tqCkEfcMin;VSCtl_tqCkEfcMinNotCtla;VSCtl_tqCkEfcPreCoVSCMinReq;VSCtl_tqCkEfcPreCoVSCtlReq;VSCtl_tqLossTra;VSCtl_tqWhlMinReq; */

/* TAG_OUTPUT_OF_SUB_FUNCTION: F71312_Determiner_Consigne_Couple_Moteur_Min ;VSCtl_tiFil_tqCkEfcMin;VSCtl_tiFil_tqCkEfcMinRaw1;VSCtl_tiFil_tqCkEfcMinRaw2;VSCtl_tiFil_tqCkEfcMinRaw3;VSCtl_tqCkEfcMinReq;VSCtl_tqCkEfcMinReqRaw1;VSCtl_tqCkEfcMinReqRaw2; */
/* TAG_END_OF_SUB_FUNCTION: F71312_Determiner_Consigne_Couple_Moteur_Min */

/* TAG_START_OF_SUB_FUNCTION: F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min */

/* TAG_INPUT_OF_SUB_FUNCTION: F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min ;VSCtl_bAcvFil_tqCkEfcMin;VSCtl_nEngFil;VSCtl_stCtl_tqCkEfcMin;VSCtl_tqCkEfcDrvMaxReq;VSCtl_tqCkEfcDrvMinReq;VSCtl_tqCkEfcMinReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min ;VSCtl_rAccPEngMin; */
/* TAG_END_OF_SUB_FUNCTION: F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min */

/* TAG_START_OF_SUB_FUNCTION: F71317_Determiner_Consigne_Couple_Moteur_Cible_Min */

/* TAG_INPUT_OF_SUB_FUNCTION: F71317_Determiner_Consigne_Couple_Moteur_Cible_Min ;CoPt_nPrimShaftTar;Ext_nFrntWhl;VSCtl_bAcvFil_tqEfcTarMin;VSCtl_stCtl_tqEfcTarMin;VSCtl_tiFilStCtlTqEfcTarMin;VSCtl_tqCkEfcMinReq;VSCtl_tqWhlMinReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71317_Determiner_Consigne_Couple_Moteur_Cible_Min ;VSCtl_tqEfcTarMin;VSCtl_tqEfcTarMinRaw;VSCtl_tqSIPTranMinSecu; */
/* TAG_END_OF_SUB_FUNCTION: F71317_Determiner_Consigne_Couple_Moteur_Cible_Min */

/* TAG_START_OF_SUB_FUNCTION: F71321_Determiner_Consigne_Couple_Moteur_Max_Init */
/* TAG_INPUT_OF_SUB_FUNCTION: F71321_Determiner_Consigne_Couple_Moteur_Max_Init ;VSCtl_tqCkEfcMaxReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71321_Determiner_Consigne_Couple_Moteur_Max_Init ;VSCtl_tqCkEfcMaxReqDly; */
/* TAG_END_OF_SUB_FUNCTION: F71321_Determiner_Consigne_Couple_Moteur_Max_Init */

/* TAG_START_OF_SUB_FUNCTION: F71323_Determiner_Consigne_Couple_Moteur_Max */

/* TAG_INPUT_OF_SUB_FUNCTION: F71323_Determiner_Consigne_Couple_Moteur_Max ;VSCtl_bAntTqWhlPTMaxReq;VSCtl_rAnt_tqWhlPTMax;VSCtl_rConvTra;VSCtl_stCtl_tqCkEfcMax;VSCtl_stTqWhlPTCutOffReqPrev;VSCtl_tiFiltqCkEfcMaxReq;VSCtl_tqCkEfcMax;VSCtl_tqCkEfcMaxNotCtla;VSCtl_tqCkEfcMaxReqDly;VSCtl_tqCkEfcMin;VSCtl_tqCkEfcMinNotCtla;VSCtl_tqCkEfcPreCoVSCMinReq;VSCtl_tqCkEfcPreCoVSCtlReq;VSCtl_tqLossTra;VSCtl_tqWhlMaxReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71323_Determiner_Consigne_Couple_Moteur_Max ;VSCtl_tqCkEfcMaxReq; */
/* TAG_END_OF_SUB_FUNCTION: F71323_Determiner_Consigne_Couple_Moteur_Max */

/* TAG_START_OF_SUB_FUNCTION: F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max */

/* TAG_INPUT_OF_SUB_FUNCTION: F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max ;VSCtl_bAcvFil_tqCkEfcMax;VSCtl_nEngFil;VSCtl_stCtl_tqCkEfcMax;VSCtl_tqCkEfcDrvMaxReq;VSCtl_tqCkEfcDrvMinReq;VSCtl_tqCkEfcMaxReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max ;VSCtl_rAccPEngMax; */
/* TAG_END_OF_SUB_FUNCTION: F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max */

/* TAG_START_OF_SUB_FUNCTION: F71328_Determiner_Consigne_Couple_Moteur_Cible_Max */

/* TAG_INPUT_OF_SUB_FUNCTION: F71328_Determiner_Consigne_Couple_Moteur_Cible_Max ;CoPt_nPrimShaftTar;Ext_nFrntWhl;VSCtl_bAcvFil_tqEfcTarMax;VSCtl_stCtl_tqEfcTarMax;VSCtl_tiFilStCtlTqEfcTarMax;VSCtl_tqCkEfcMaxReq;VSCtl_tqWhlMaxReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71328_Determiner_Consigne_Couple_Moteur_Cible_Max ;VSCtl_tqEfcTarMax;VSCtl_tqEfcTarMaxRaw;VSCtl_tqSIPTranMaxSecu; */
/* TAG_END_OF_SUB_FUNCTION: F71328_Determiner_Consigne_Couple_Moteur_Cible_Max */

/* TAG_START_OF_SUB_FUNCTION: F72112_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Min */

/* TAG_INPUT_OF_SUB_FUNCTION: F72112_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Min ;Ext_stCtlCmdPTTqPotCf;VSCtl_bAcvFil_tqWhlPTPotMin;VSCtl_stCtl_tqWhlPTPotMin;VSCtl_stCtl_tqWhlPotMin;VSCtl_tqWhlPTPotRawMax;VSCtl_tqWhlPTPotRawMin;VSCtl_tqWhlPTPreCoVSCMaxReq;VSCtl_tqWhlPTPreCoVSCMinReq;VSCtl_tqWhlPotMinReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72112_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Min ;VSCtl_tqWhlPTPotMinReq;VSCtl_tqWhlPotMinIntReq; */
/* TAG_END_OF_SUB_FUNCTION: F72112_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Min */

/* TAG_START_OF_SUB_FUNCTION: F72122_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Max */

/* TAG_INPUT_OF_SUB_FUNCTION: F72122_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Max ;Ext_stCtlCmdPTTqPotCf;VSCtl_bAcvFil_tqWhlPTPotMax;VSCtl_stCtl_tqWhlPTPotMax;VSCtl_stCtl_tqWhlPotMax;VSCtl_tqWhlPTPotRawMax;VSCtl_tqWhlPTPotRawMin;VSCtl_tqWhlPTPreCoVSCMaxReq;VSCtl_tqWhlPTPreCoVSCMinReq;VSCtl_tqWhlPotMaxReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72122_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Max ;VSCtl_tqWhlPTPotMaxReq;VSCtl_tqWhlPotMaxIntReq; */
/* TAG_END_OF_SUB_FUNCTION: F72122_Determiner_Consigne_Potentiel_Couple_Roue_GMP_Max */

/* TAG_START_OF_SUB_FUNCTION: F7214_Determiner_Temps_Confirmation_Changement_Rapport */

/* TAG_INPUT_OF_SUB_FUNCTION: F7214_Determiner_Temps_Confirmation_Changement_Rapport ;Ext_stCtlCmdPTTqPotCf;VSCtl_tiCfmSdwnTqMaxReq;VSCtl_tiCfmSdwnTqMinReq;VSCtl_tiCfmSupTqMaxReq;VSCtl_tiCfmSupTqMinReq; */

/* TAG_OUTPUT_OF_SUB_FUNCTION: F7214_Determiner_Temps_Confirmation_Changement_Rapport ;VSCtl_tiCfmSdwnIntReq;VSCtl_tiCfmSdwnReq;VSCtl_tiCfmSupIntReq;VSCtl_tiCfmSupReq; */
/* TAG_END_OF_SUB_FUNCTION: F7214_Determiner_Temps_Confirmation_Changement_Rapport */

/* TAG_START_OF_SUB_FUNCTION: F72152_Determiner_Consigne_Potentiel_Couple_Roue_GMP */

/* TAG_INPUT_OF_SUB_FUNCTION: F72152_Determiner_Consigne_Potentiel_Couple_Roue_GMP ;VSCtl_bAcvFil_tqWhlPTPot;VSCtl_stCtl_tqWhlPTPot;VSCtl_tqWhlPTPotRawMax;VSCtl_tqWhlPTPotRawMin;VSCtl_tqWhlPotReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72152_Determiner_Consigne_Potentiel_Couple_Roue_GMP ;VSCtl_dtqWhlPTPotReq;VSCtl_tqWhlPTPotReq; */
/* TAG_END_OF_SUB_FUNCTION: F72152_Determiner_Consigne_Potentiel_Couple_Roue_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Max ;Ext_stCtlCmdPTTqPotCf;VSCtl_stCtl_tqWhlPotMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Max ;VSCtl_bAcvFil_tqWhlPTPotMax;VSCtl_stCtl_tqWhlPTPotMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Min ;Ext_stCtlCmdPTTqPotCf;VSCtl_stCtl_tqWhlPotMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Min ;VSCtl_bAcvFil_tqWhlPTPotMin;VSCtl_stCtl_tqWhlPTPotMin; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Couple_Roue_GMP_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Max */

/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Max ;Ext_stTraTypCf;VSCtl_bAvlTqWhlPT_no3;VSCtl_stCtl_tqCkEfcMax;VSCtl_tqCkEfcMaxReq;VSCtl_tqEfcTarMax; */

/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Max ;VSCtl_bAcvFil_tqEfcTarMax;VSCtl_stCtl_tqEfcTarMax;VSCtl_tiFilStCtlTqEfcTarMax;VSCtl_tqCkEfcMaxReqPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Min */

/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Min ;Ext_stTraTypCf;VSCtl_bAvlTqWhlPT_no3;VSCtl_stCtl_tqCkEfcMin;VSCtl_tqCkEfcMinReq;VSCtl_tqEfcTarMin; */

/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Min ;VSCtl_bAcvFil_tqEfcTarMin;VSCtl_stCtl_tqEfcTarMin;VSCtl_tiFilStCtlTqEfcTarMin;VSCtl_tqCkEfcMinReqPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Cible_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Min ;VSCtl_bCtlCmdPTTqCf_SC;VSCtl_stCtl_tqWhlMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Min ;VSCtl_bAcvFil_tqCkEfcMin;VSCtl_stCtl_tqCkEfcMin; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Moteur_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Controle_Potentiel_Couple_Roue */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Potentiel_Couple_Roue ;Ext_stCtlCmdPTTqPotCf;VSCtl_bCtlCmdPTTqCf_SC;VSCtl_stCtl_tqWhlPot; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Potentiel_Couple_Roue ;VSCtl_bAcvFil_tqWhlPTPot;VSCtl_stCtl_tqWhlPTPot; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Controle_Potentiel_Couple_Roue */

/* TAG_START_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Moteur_Max */

/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Moteur_Max ;VSCtl_bCtlCmdPTTqCf_SC;VSCtl_bFastDeacVSLimReq;VSCtl_stCtl_tqWhlMax;VSCtl_tqCkEfcMaxReqDly;VSCtl_tqCkEfcPreCoVSCtlReq; */

/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Moteur_Max ;VSCtl_bAcvFil_tqCkEfcMax;VSCtl_bTranEnd_tqCkEfcMax;VSCtl_stCtl_tqCkEfcMax;VSCtl_tiFiltqCkEfcMaxReq; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Moteur_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: VSSP_enable_F721 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: VSSP_enable_F721 ;Ext_stCtlCmdPTTqPotCf; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: VSSP_enable_F721 ;vsctl_bacvf721; */
/* TAG_END_OF_STATEFLOW_FUNCTION: VSSP_enable_F721 */

/* END OF SSTG FUNCTION INTERFACE AREA */

/* <AUT_POST> : Task Include managment */
/********************************************************************/
/*  Include Files                                                   */
/********************************************************************/
#include "dds_lib.h"
#include "VSSp.h"
/* \<AUT_POST> : Task Include managment */

/********************************************************************/
/*  Task Macro Definitions                                          */
/********************************************************************/

#define VSCTL_STCTL_TQWHLMIN_ARRET                      (0)
#define VSCTL_STCTL_TQWHLMAX_ARRET                      (0)
#define VSCTL_STCTL_TQWHLPTPOTMIN_ARRET                 (0)
#define VSCTL_STCTL_TQWHLPTPOTMIN_CONTROLE              (1)

/* VSCtl_stCtl_tqWhlPotMin */
#define VSCTL_STCTL_TQWHLPOTMIN_ARRET                   (0)
#define VSCTL_STCTL_TQWHLPOTMIN_CONTROLE                (1)

/* VSCtl_stCtl_tqWhlPTPotMax */
#define VSCTL_STCTL_TQWHLPTPOTMAX_ARRET                 (0)
#define VSCTL_STCTL_TQWHLPTPOTMAX_CONTROLE              (1)

/* VSCtl_stCtl_tqWhlPotMax */
#define VSCTL_STCTL_TQWHLPOTMAX_ARRET                   (0)
#define VSCTL_STCTL_TQWHLPOTMAX_CONTROLE                (1)

/* VSCtl_stTqWhlPTPotCtlReq */
#define VSCTL_STTQWHLPTPOTCTLREQ_ARRET                  (0)
#define VSCTL_STTQWHLPTPOTCTLREQ_MODE_1                 (1)
#define VSCTL_STTQWHLPTPOTCTLREQ_MODE_2                 (2)
#define VSCTL_STTQWHLPTPOTCTLREQ_MODE_3                 (3)

/* Ext_stCtlCmdPTTqPotCf */
#define EXT_STCTLCMDPTTQPOTCF_RAPPORT                   (3)


/* VSCtl_stCtl_tqWhlPTPot */
#define VSCTL_STCTL_TQWHLPTPOT_CONTROLE                 (1)
#define VSCTL_STCTL_TQWHLPTPOT_ARRET                    (0)

/* VSCtl_stCtl_tqWhlPot */
#define VSCTL_STCTL_TQWHLPOT_CONTROLE                   (1)
#define VSCTL_STCTL_TQWHLPOT_ARRET                      (0)

/* VSCtl_stTqPTMinCtl_pt2 */
#define VSCTL_STTQPTMINCTL_PT2_INACTIF                  (0)
#define VSCTL_STTQPTMINCTL_PT2_AE                       (1)
#define VSCTL_STTQPTMINCTL_PT2_ANE                      (2)

/* VSCtl_stTqPTMaxCtl_pt2 */
#define VSCTL_STTQPTMAXCTL_PT2_INACTIF                  (0)
#define VSCTL_STTQPTMAXCTL_PT2_AE                       (1)
#define VSCTL_STTQPTMAXCTL_PT2_ANE                      (2)

/* VSCtl_st_rAccPCtl_pt2 */
#define VSCTL_ST_RACCPCTL_PT2_INACTIF                   (0)
#define VSCTL_ST_RACCPCTL_PT2_AE                        (1)
#define VSCTL_ST_RACCPCTL_PT2_ANE                       (2)
/************************************************************************/


/* Named constants for block: /VSSP_enable_F721' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_VSSP_enable_F721 (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_ao (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ACTIVE (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_m (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_am (1U)

/* Named constants for block: /Mode_Controle_Couple_Moteur_Min' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_CONTROLE_COUPLE_MOTEUR_MIN (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE (2)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI (1U)

/* Named constants for block: /Effectivite_Couple_Moteur_Min' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_COUPLE_MOTEUR_MIN (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_j (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_a (1U)

/* Named constants for block: /Effectivite_Position_Pedale_Accelerateur_Min' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_f (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_e (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_p (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_j (1U)

/* Named constants for block: /Mode_Controle_Couple_Moteur_Cible_Min' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_m (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_PENDANT_SIP (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_COUPLE_MOTEUR_CIBLE_MIN (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_HIGH (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_i (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP (3)
#define VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_LOW (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0 (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_a (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_c (1U)

/* Named constants for block: /Modes_Controle_Couple_Moteur_Max' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_b (0)
#define VSSP_Torque_Control_Gmp2_Sf_IN_REPRISE (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_LENTE (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_INIT (3)
#define VSSP_Torque_Control_Gmp2_Sf_IN_NON_REPRISE (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_CONTROLE_COUPLE_MOTEUR_MAX (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_a (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_j (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_RAPIDE (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_TRANSITION (4)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_e (1U)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_f (0U)

/* Named constants for block: /Effectivite_Couple_Moteur_Max' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_fr (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_b (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_COUPLE_MOTEUR_MAX (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_h (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_i (1U)

/* Named constants for block: /Effectivite_Position_Pedale_Accelerateur_Max' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_i (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_j (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_fx (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_jk (1U)

/* Named constants for block: /Mode_Controle_Couple_Moteur_Cible_Max' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_l (0)
#define VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_jd (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_PENDANT_SIP_d (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_COUPLE_MOTEUR_CIBLE_MAX (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_HIGH_h (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_k (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP_m (3)
#define VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_LOW_l (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0_o (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_b (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_n (1U)

/* Named constants for block: /Autorisation_Recuperation_Energie' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_AUTORISATION_RECUPERATION_ENERGIE (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_VRAI (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_FAUX (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_f0 (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_l (1U)

/* Named constants for block: /Effectivite_Processus_XVV' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_k (0)
#define VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_PROCESSUS_XVV (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_a (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_bc (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_fk (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_n1 (1U)

/* Named constants for block: /Mode_Commande_Potentiel_Couple_Roue_GMP_Min' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_m (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_i (2)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_k (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_a3 (1U)

/* Named constants for block: /Mode_Commande_Potentiel_Couple_Roue_GMP_Max' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_h (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_n (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_l (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_g (1U)

/* Named constants for block: /Demande_Pilotage_Potentiel_Couple_Roue_GMP' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_g (0)
#define VSSP_Torque_Control_Gmp2_Sf_IN_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_g (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_1 (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_2 (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MARCHE (2)

/* Named constants for block: /Mode_Controle_Potentiel_Couple_Roue' */
#define VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_l (2)
#define VSSP_Torque_Control_Gmp2_Sf_IN_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP (1)
#define VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_d (1)
#define VSSP_Torque_Control_Gmp2_Sf_FAUX_h2 (0U)
#define VSSP_Torque_Control_Gmp2_Sf_VRAI_k (1U)

/* Definition for custom storage class: Define */
#define VSCTL_TQCKEFCMAXREQPREV_MAX    32000
#define VSCTL_TQCKEFCMAXREQPREV_MIN    (-32000)
#define VSCTL_TQCKEFCMINREQPREV_MAX    32000
#define VSCTL_TQCKEFCMINREQPREV_MIN    (-32000)
#define VSSP_TORQUE_CONTROL_GMP2_CONST_0 (-32000)
#define VSSP_TORQUE_CONTROL_GMP2_CONST_1 32000
#define VSSP_TORQUE_CONTROL_GMP2_CONST_2 0


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxReqDly;       /*BIN4*/
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_tiFiltqCkEfcMaxReq;       /*BIN0*/
VAR(UInt16, AUTOMATIC) VSCtl_tiFilStCtlTqEfcTarMin;       /*BIN0*/
VAR(UInt16, AUTOMATIC) VSCtl_tiFilStCtlTqEfcTarMax;       /*BIN0*/
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTPotMin;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTPotMax;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTPot;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqEfcTarMin;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqEfcTarMax;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqCkEfcMin;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqCkEfcMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTPotMin;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTPotMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTPot;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqEfcTarMin;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqEfcTarMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqCkEfcMin;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqCkEfcMax;
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  SInt16 vss_Keep_Global_Data_From_Input;
  SInt16 VSCtl_tqCkEfcMaxReqPrev_d;
  SInt16 VSCtl_tqCkEfcMinReqPrev_l;
} BlockIO_VSSP_Torque_Control_Gmp2_Sf;


typedef struct {
  UInt32 is_ETAT_CONTROLE : 3;
  UInt32 is_VSSP_enable_F721 : 2;
  UInt32 is_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP : 2;
  UInt32 is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX : 2;
  UInt32 is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN : 2;
  UInt32 is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2 : 2;
  UInt32 is_ACTIF : 2;
  UInt32 is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2 : 2;
  UInt32 is_ACTIF_b : 2;
  UInt32 is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2 : 2;
  UInt32 is_ACTIF_j : 2;
  UInt32 is_EFFECTIVITE_COUPLE_ROUE_GMP2 : 2;
  UInt32 is_AUTORISATION_RECUPERATION_ENERGIE : 2;
  UInt32 is_CONTROLE : 2;
  UInt32 is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX : 2;
  UInt32 is_HORS_SIP : 2;
  UInt32 is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX : 2;
  UInt32 is_EFFECTIVITE_COUPLE_MOTEUR_MAX : 2;
  UInt32 is_FIN_TRANSITION : 2;
  UInt32 is_TRANSITION : 2;
  UInt32 is_CONTROLE_h : 2;
  UInt32 is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN : 2;
  UInt32 is_HORS_SIP_h : 2;
  UInt32 is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN : 2;
  UInt32 is_EFFECTIVITE_COUPLE_MOTEUR_MIN : 2;
  UInt32 is_MODE_CONTROLE_COUPLE_MOTEUR_MIN : 2;
  UInt32 is_active_c1_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c1_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c5_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c5_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c4_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c4_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c3_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c3_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c2_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c2_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c186_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c186_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2 : 1;
  UInt32 is_active_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2 : 1;
  UInt32 is_active_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2 : 1;
  UInt32 is_active_EFFECTIVITE_COUPLE_ROUE_GMP2 : 1;
  UInt32 is_active_c185_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c185_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c112_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c112_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_MEMOIRES : 1;
  UInt32 is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX : 1;
  UInt32 is_active_c351_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c351_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c350_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c350_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c349_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c349_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_FIN_TRANSITION : 1;
  UInt32 is_active_ETAT_CONTROLE : 1;
  UInt32 is_active_c111_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c111_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_MEMOIRES_l : 1;
  UInt32 is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN : 1;
  UInt32 is_active_c347_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c347_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c346_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c346_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_active_c345_VSSP_Torque_Control_Gmp2_Sf : 1;
  UInt32 is_c345_VSSP_Torque_Control_Gmp2_Sf : 1;
} D_Work_VSSP_Torque_Control_Gmp2_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxReqPrev;                /*BIN4*/
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinReqPrev;                /*BIN4*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHldWhlPotCtlReq;                /*BIN0*/
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_rAccPMax_pt2;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_rAccPMin_pt2;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bTranEnd_tqCkEfcMax;
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_st_rAccPCtl_pt2;
/* Static Visible area end */
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 16BIT-bits variable definition */
#define VSSP_START_SEC_VAR_16BIT
#include "VSSp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vssp_torque_control_gmp2_delay_0;
STATIC VAR(SInt16, AUTOMATIC) vssp_torque_control_gmp2_delay_1;
STATIC VAR(SInt16, AUTOMATIC) vssp_torque_control_gmp2_delay_2;
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqckefcmaxreq_cpy;                           /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqckefcminreq_cpy;                           /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqefctarmax_cpy;                             /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqefctarmin_cpy;                             /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqwhlptpotmaxreq_cpy;                        /*BIN1*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqwhlptpotminreq_cpy;                        /*BIN1*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqwhlptpotreq_cpy;                           /*BIN1*/
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_raccpengmax_cpy;                             /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_raccpengmin_cpy;                             /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_ticfmsdwnreq_cpy;                            /*DEC2*/
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_ticfmsupreq_cpy;                             /*DEC2*/
#define VSSP_STOP_SEC_VAR_16BIT
#include "VSSp_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(BlockIO_VSSP_Torque_Control_Gmp2_Sf, AUTOMATIC) vssp_torque_control_gmp2_sf_b;
STATIC VAR(D_Work_VSSP_Torque_Control_Gmp2_Sf, AUTOMATIC) vssp_torque_control_gmp2_sf_dwork;
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"


/* 8BIT-bits variable definition */
#define VSSP_START_SEC_VAR_8BIT
#include "VSSp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bacvf721;
/* Static Not Visible area end */
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_bctlefc_tqckefcmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_bctlefc_tqckefcmin_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_bctlefc_tqwhlpt_pt2_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_binhrecup_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_sttqptmaxctl_pt2_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_sttqptminctl_pt2_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_sttqwhlptpotctlreq_cpy;
#define VSSP_STOP_SEC_VAR_8BIT
#include "VSSp_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSSP_START_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfc_bCtlEfcMaxHys_C = (CONST(SInt16, AUTOMATIC))(160); /*BIN4*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfc_bCtlEfcMinHys_C = (CONST(SInt16, AUTOMATIC))(160); /*BIN4*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_stCtlTqEfcTarMax_C = (CONST(UInt16, AUTOMATIC))(100U); /*DEC0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_stCtlTqEfcTarMin_C = (CONST(UInt16, AUTOMATIC))(100U); /*DEC0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFiltqCkEfcMaxReq_C = (CONST(UInt16, AUTOMATIC))(300U);  /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHldWhlPotCtlReq_C = (CONST(UInt16, AUTOMATIC))(10U);    /*BIN0*/
/* \<AUT_POST> : Task Memory Ordering */
#define VSSP_STOP_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"

/* AUT_POST_TAG DECLARATIONS */
/* \AUT_POST_TAG DECLARATIONS */
/* AUT_POST_TAG FUNCTIONS */

/* Model step function */

/* <AUT_POST> : Task static function */
/********************************************************************/
/*  Task Local Function Prototypes                                  */
/********************************************************************/
/* NONE */
/* \<AUT_POST> : Task static function */

/********************************************************************/
/*  Local Task Function Definition                                  */
/********************************************************************/
/* NONE */

/********************************************************************/
/*  Main Task Function Definition                                   */
/********************************************************************/

#define VSSP_START_SEC_CODE
#include "VSSp_MemMap.h"

FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp2_Sf(SInt16 VSCtl_tqWhlPTPotRawMin_swc_in,                       /*BIN1*/
                               SInt16 VSCtl_tqWhlPTPotRawMax_swc_in,                       /*BIN1*/
                               UInt32 Ext_nFrntWhl_swc_in,                                 /*BIN7*/
                               SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in,                       /*BIN4*/
                               UInt8 Ext_stTraTypCf_swc_in,
                               SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in,                      /*BIN4*/
                               SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in,                       /*BIN4*/
                               UInt16 VSCtl_tiCfmSupTqMinReq_swc_in,                       /*DEC2*/
                               SInt16 VSCtl_tqWhlMinReq_swc_in,                            /*BIN1*/
                               SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in,                      /*BIN4*/
                               UInt8 VSCtl_stCtl_tqWhlMin_swc_in,
                               UInt16 VSCtl_tiCfmSupTqMaxReq_swc_in,                       /*DEC2*/
                               SInt16 VSCtl_tqWhlMaxReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlMax_swc_in,
                               UInt16 VSCtl_tiCfmSdwnTqMinReq_swc_in,                      /*DEC2*/
                               UInt16 VSCtl_tiCfmSdwnTqMaxReq_swc_in,                      /*DEC2*/
                               UInt32 VSCtl_nEngFil_swc_in,                                /*BIN0*/
                               SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in,                  /*BIN1*/
                               SInt16 VSCtl_tqCkEfcMin_swc_in,                             /*BIN4*/
                               SInt16 VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in,                  /*BIN1*/
                               SInt16 VSCtl_tqCkEfcMax_swc_in,                             /*BIN4*/
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               SInt16 VSCtl_tqWhlPotReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPot_swc_in,
                               UInt16 CoPt_nPrimShaftTar_swc_in,                           /*BIN0*/
                               SInt16 VSCtl_tqLossTra_swc_in,                              /*BIN4*/
                               SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in,                   /*BIN4*/
                               UInt16 VSCtl_rConvTra_swc_in,                               /*BIN7*/
                               SInt16 VSCtl_tqWhlPotMinReq_swc_in,                         /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in,
                               UInt8 VSCtl_bFastDeacVSLimReq_swc_in,
                               SInt16 VSCtl_tqWhlPotMaxReq_swc_in,                         /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                               SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in,                  /*BIN4*/
                               UInt16 AccP_rAccP_swc_in,                            /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMaxReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMin_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnReq_swc_out,                           /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTPotCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMin_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bInhRecup_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMax_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMin_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMinReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupReq_swc_out)                            /*DEC2*/
{
  SInt16 stack_data_s16_0;


  /* TAG_START_OF_MAIN_FUNCTION */
   /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.21.3 */
  /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.52.1 */

  if (DDS_FALSE==VSCtl_bCtlCmdPTTqCf_SC)
  {

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71311_Determiner_Mode_Commande_Couple_Moteur_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.53.1 */
    if (vssp_torque_control_gmp2_sf_dwork.is_active_c345_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c345_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c345_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_MODE_CONTROLE_COUPLE_MOTEUR_MIN;
      vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_COUPLE_MOTEUR_MIN =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET;
      VSCtl_stCtl_tqCkEfcMin = VSCTL_STCTL_TQCKEFCMIN_ARRET;
      VSCtl_bAcvFil_tqCkEfcMin = VSSP_Torque_Control_Gmp2_Sf_FAUX;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_COUPLE_MOTEUR_MIN)
  {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET:
        if ((VSCtl_bCtlCmdPTTqCf_SC == VSSP_Torque_Control_Gmp2_Sf_FAUX)
        &&
            (VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_COUPLE_MOTEUR_MIN =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE;
          VSCtl_stCtl_tqCkEfcMin = VSCTL_STCTL_TQCKEFCMIN_CONTROLE;
          VSCtl_bAcvFil_tqCkEfcMin = VSSP_Torque_Control_Gmp2_Sf_VRAI;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE:
        if ((VSCtl_bCtlCmdPTTqCf_SC != VSSP_Torque_Control_Gmp2_Sf_FAUX)
        ||
            (VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_COUPLE_MOTEUR_MIN =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET;
          VSCtl_stCtl_tqCkEfcMin = VSCTL_STCTL_TQCKEFCMIN_ARRET;
          VSCtl_bAcvFil_tqCkEfcMin = VSSP_Torque_Control_Gmp2_Sf_FAUX;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_COUPLE_MOTEUR_MIN =
          (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET;
        VSCtl_stCtl_tqCkEfcMin = VSCTL_STCTL_TQCKEFCMIN_ARRET;
        VSCtl_bAcvFil_tqCkEfcMin = VSSP_Torque_Control_Gmp2_Sf_FAUX;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71311_Determiner_Mode_Commande_Couple_Moteur_Min*/


  VSSP_F71312_Determiner_Consigne_Couple_Moteur_Min(VSCtl_rConvTra_swc_in, /* BIN7 */
                                                    VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                                    VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                                    VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                                    VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                                    VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                                    VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                                    VSCtl_tqLossTra_swc_in, /* BIN4 */
                                                    VSCtl_tqWhlMinReq_swc_in, /* BIN1 */
                                                    &vssp_vsctl_tqckefcminreq_cpy /* BIN4 */);



    /* TAG_START_OF_STATEFLOW_FUNCTION: F71313_Determiner_Effectivite_Couple_Moteur_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.55.1 */
    if (vssp_torque_control_gmp2_sf_dwork.is_active_c346_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c346_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c346_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_COUPLE_MOTEUR_MIN;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MIN =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF;
      vssp_vsctl_bctlefc_tqckefcmin_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_j;

    }
    else
    {
      switch (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MIN)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF:
        if ((VSCtl_stCtl_tqCkEfcMin == VSCTL_STCTL_TQCKEFCMIN_ARRET)
        ||
            (vssp_vsctl_tqckefcminreq_cpy <= VSCtl_tqCkEfcPreCoVSCtlReq_swc_in))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MIN =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF;
          vssp_vsctl_bctlefc_tqckefcmin_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_j;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF:
        if ((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        &&
            ((vssp_vsctl_tqckefcminreq_cpy + VSCtl_tqCkEfc_bCtlEfcMinHys_C) >
             VSCtl_tqCkEfcPreCoVSCtlReq_swc_in))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MIN =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF;
          vssp_vsctl_bctlefc_tqckefcmin_cpy = VSSP_Torque_Control_Gmp2_Sf_VRAI_a;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MIN =
          (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF;
        vssp_vsctl_bctlefc_tqckefcmin_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_j;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71313_Determiner_Effectivite_Couple_Moteur_Min*/

    VSSP_F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min(VSCtl_nEngFil_swc_in, /* BIN0 */
                                                                      vssp_vsctl_tqckefcminreq_cpy, /* BIN4 */
                                                                      VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                                      VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                                    &vssp_vsctl_raccpengmin_cpy /* BIN7 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71315_Determiner_Effectivite_Position_Pedale_Accelerateur_Moteur_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.57.0 */

    if (vssp_torque_control_gmp2_sf_dwork.is_active_c347_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c347_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c347_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_f;
      VSCtl_bCtlEfc_rAccPMin_pt2 = VSSP_Torque_Control_Gmp2_Sf_FAUX_p;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_e:
        if ((VSCtl_stCtl_tqCkEfcMin == VSCTL_STCTL_TQCKEFCMIN_ARRET)
        ||
            (vssp_vsctl_raccpengmin_cpy <= AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_f;
          VSCtl_bCtlEfc_rAccPMin_pt2 = VSSP_Torque_Control_Gmp2_Sf_FAUX_p;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_f:
        if ((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        &&
            (vssp_vsctl_raccpengmin_cpy > AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_e;
          VSCtl_bCtlEfc_rAccPMin_pt2 = VSSP_Torque_Control_Gmp2_Sf_VRAI_j;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_f;
        VSCtl_bCtlEfc_rAccPMin_pt2 = VSSP_Torque_Control_Gmp2_Sf_FAUX_p;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71315_Determiner_Effectivite_Position_Pedale_Accelerateur_Moteur_Min*/


    stack_data_s16_0 = vssp_torque_control_gmp2_delay_0;


    /* TAG_START_OF_STATEFLOW_FUNCTION: F71316_Determiner_Mode_Commande_Couple_Moteur_Cible_Min*/
			/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.138.0 */

    if (vssp_torque_control_gmp2_sf_dwork.is_active_c111_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c111_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c111_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_COUPLE_MOTEUR_CIBLE_MIN;
      vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_i;
      VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_ARRET;
      VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C;
      VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;
      vssp_torque_control_gmp2_sf_dwork.is_active_MEMOIRES_l = 1U;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_i:
        if ((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        &&
            (Ext_stTraTypCf_swc_in == EXT_STTRATYPCF_DCT))
        {
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_m;
          vssp_torque_control_gmp2_sf_dwork.is_CONTROLE_h = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0;
          vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP;
          VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_HORS_SIP;
          VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C;
          VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_m:
        if ((VSCtl_stCtl_tqCkEfcMin == VSCTL_STCTL_TQCKEFCMIN_ARRET)
        ||
            (Ext_stTraTypCf_swc_in != EXT_STTRATYPCF_DCT))
        {
          vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD;
          vssp_torque_control_gmp2_sf_dwork.is_CONTROLE_h = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD;
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_i;
          VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_ARRET;
          VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C;
          VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;

        }
        else
        {
          switch (vssp_torque_control_gmp2_sf_dwork.is_CONTROLE_h)
        {
           case VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0:
            if (VSCtl_bAvlTqWhlPT_no3_swc_in == VSSP_Torque_Control_Gmp2_Sf_FAUX_a)
            {
              vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD;
              vssp_torque_control_gmp2_sf_dwork.is_CONTROLE_h = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_PENDANT_SIP;
              VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_SIP;
              VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C;

            }
            else
            {
              switch (vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h)
        {
               case VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_HIGH:
                if ((VSCtl_tiFilStCtlTqEfcTarMin == 0) ||
                    (stack_data_s16_0 >=
                     vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMinReqPrev_l))
                {
                  vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = (UInt8)
                    VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP;
                  VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_HORS_SIP;
                  VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C;
                  VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;

                }
                else
                {
                  VSCtl_tiFilStCtlTqEfcTarMin = (UInt16)
                    (VSCtl_tiFilStCtlTqEfcTarMin - 1);
                }
                break;

               case VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_LOW:
                if ((VSCtl_tiFilStCtlTqEfcTarMin == 0) ||
                    (stack_data_s16_0 <=
                     vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMinReqPrev_l))
                {
                  vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = (UInt8)
                    VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP;
                  VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_HORS_SIP;
                  VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C;
                  VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;

                }
                else
                {
                  VSCtl_tiFilStCtlTqEfcTarMin = (UInt16)
                    (VSCtl_tiFilStCtlTqEfcTarMin - 1);
                }
                break;
              }
            }
            break;

           case VSSP_Torque_Control_Gmp2_Sf_IN_PENDANT_SIP:
            if ((VSCtl_bAvlTqWhlPT_no3_swc_in == VSSP_Torque_Control_Gmp2_Sf_VRAI_c)
            &&
                (stack_data_s16_0 >= vssp_vsctl_tqckefcminreq_cpy))
            {
              vssp_torque_control_gmp2_sf_dwork.is_CONTROLE_h = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0;
              vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_LOW;
              VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_FIN_SIP_LOW;
              VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;

            }
            else if ((VSCtl_bAvlTqWhlPT_no3_swc_in ==
                        VSSP_Torque_Control_Gmp2_Sf_VRAI_c) &&
                       (stack_data_s16_0 <
                        vssp_vsctl_tqckefcminreq_cpy))
            {
              vssp_torque_control_gmp2_sf_dwork.is_CONTROLE_h = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0;
              vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_HIGH;
              VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_FIN_SIP_HIGH;
              VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;

            }
            else
            {
              VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_VRAI_c;
            }
            break;
          }
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_i;
        VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_ARRET;
        VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C;
        VSCtl_bAcvFil_tqEfcTarMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_a;
        break;
      }

      vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMinReqPrev_l =
        vssp_vsctl_tqckefcminreq_cpy;
    }

    VSCtl_tqCkEfcMinReqPrev = DDS_M_LIMIT
      (vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMinReqPrev_l,
       VSCTL_TQCKEFCMINREQPREV_MIN,
       VSCTL_TQCKEFCMINREQPREV_MAX);

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71316_Determiner_Mode_Commande_Couple_Moteur_Cible_Min*/


    VSSP_F71317_Determiner_Consigne_Couple_Moteur_Cible_Min(CoPt_nPrimShaftTar_swc_in,   /* BIN0 */
                                                          Ext_nFrntWhl_swc_in,         /* BIN0 */
                                                          vssp_vsctl_tqckefcminreq_cpy,     /* BIN4 */
                                                          VSCtl_tqWhlMinReq_swc_in,    /* BIN1 */
                                                          &vssp_vsctl_tqefctarmin_cpy);     /* BIN4 */



    vssp_torque_control_gmp2_sf_b.vss_Keep_Global_Data_From_Input =
      vssp_torque_control_gmp2_delay_1;


    /* TAG_START_OF_STATEFLOW_FUNCTION: F71322_Determiner_Mode_Commande_Couple_Moteur_Max*/
		/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.60.0 */


    if (vssp_torque_control_gmp2_sf_dwork.is_active_c349_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c349_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c349_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_MODE_CONTROLE_COUPLE_MOTEUR_MAX;
      vssp_torque_control_gmp2_sf_dwork.is_active_FIN_TRANSITION = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_FIN_TRANSITION = (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_NON_REPRISE;
      VSCtl_bTranEnd_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_f;
      vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_INIT;
      VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_INIT;
      VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_f;
      VSCtl_tiFiltqCkEfcMaxReq = VSCtl_tiFiltqCkEfcMaxReq_C;

    }
    else
    {
      switch (vssp_torque_control_gmp2_sf_dwork.is_FIN_TRANSITION)
        {
       case VSSP_Torque_Control_Gmp2_Sf_IN_NON_REPRISE:
        if (vssp_torque_control_gmp2_sf_b.vss_Keep_Global_Data_From_Input >=
            VSCtl_tqCkEfcPreCoVSCtlReq_swc_in)
        {
          vssp_torque_control_gmp2_sf_dwork.is_FIN_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_REPRISE;
          VSCtl_bTranEnd_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_VRAI_e;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_REPRISE:
        if ((vssp_torque_control_gmp2_sf_b.vss_Keep_Global_Data_From_Input <
             VSCtl_tqCkEfcPreCoVSCtlReq_swc_in) && (VSCtl_stCtl_tqWhlMax_swc_in !=
             VSCTL_STCTL_TQWHLMAX_ARRET))
        {
          vssp_torque_control_gmp2_sf_dwork.is_FIN_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NON_REPRISE;
          VSCtl_bTranEnd_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_f;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_FIN_TRANSITION = (UInt8)
          VSSP_Torque_Control_Gmp2_Sf_IN_NON_REPRISE;
        VSCtl_bTranEnd_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_f;
        break;
      }

      switch (vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE)
        {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_a:
        if ((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET) &&
            (VSCtl_bCtlCmdPTTqCf_SC == VSSP_Torque_Control_Gmp2_Sf_FAUX_f))
        {
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_j;
          VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_CONTROLE;
          VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_VRAI_e;
          VSCtl_tiFiltqCkEfcMaxReq = VSCtl_tiFiltqCkEfcMaxReq_C;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_j:
        if ((VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET) ||
            (VSCtl_bCtlCmdPTTqCf_SC != VSSP_Torque_Control_Gmp2_Sf_FAUX_f))
        {
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_TRANSITION;
          vssp_torque_control_gmp2_sf_dwork.is_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_LENTE;
          VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_TRANS_L;
          VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_VRAI_e;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_INIT:
        if (VSCtl_bTranEnd_tqCkEfcMax == VSSP_Torque_Control_Gmp2_Sf_FAUX_f)
        {
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_TRANSITION;
          vssp_torque_control_gmp2_sf_dwork.is_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_LENTE;
          VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_TRANS_L;
          VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_VRAI_e;

        }
        else if (VSCtl_bTranEnd_tqCkEfcMax ==
                   VSSP_Torque_Control_Gmp2_Sf_VRAI_e)
        {
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_a;
          VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_ARRET;
          VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_f;
          VSCtl_tiFiltqCkEfcMaxReq = VSCtl_tiFiltqCkEfcMaxReq_C;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_TRANSITION:
        if (VSCtl_bTranEnd_tqCkEfcMax == VSSP_Torque_Control_Gmp2_Sf_VRAI_e)
        {
          vssp_torque_control_gmp2_sf_dwork.is_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_b;
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_a;
          VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_ARRET;
          VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_f;
          VSCtl_tiFiltqCkEfcMaxReq = VSCtl_tiFiltqCkEfcMaxReq_C;

        }
        else
        {
          switch (vssp_torque_control_gmp2_sf_dwork.is_TRANSITION)
        {
           case VSSP_Torque_Control_Gmp2_Sf_IN_LENTE:
            if (VSCtl_bFastDeacVSLimReq_swc_in == VSSP_Torque_Control_Gmp2_Sf_VRAI_e)
            {
              vssp_torque_control_gmp2_sf_dwork.is_TRANSITION = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_RAPIDE;
              VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_TRANS_R;
              VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_VRAI_e;

            }
            else
            {
              VSCtl_tiFiltqCkEfcMaxReq = (UInt16)DDS_M_MAX
                (VSCtl_tiFiltqCkEfcMaxReq - 1, 0);
            }
            break;

           case VSSP_Torque_Control_Gmp2_Sf_IN_RAPIDE:
            VSCtl_tiFiltqCkEfcMaxReq = (UInt16)DDS_M_MAX(VSCtl_tiFiltqCkEfcMaxReq
              - 1, 0);
            break;
          }
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = (UInt8)
          VSSP_Torque_Control_Gmp2_Sf_IN_INIT;
        VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_INIT;
        VSCtl_bAcvFil_tqCkEfcMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_f;
        VSCtl_tiFiltqCkEfcMaxReq = VSCtl_tiFiltqCkEfcMaxReq_C;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71322_Determiner_Mode_Commande_Couple_Moteur_Max*/


    VSSP_F71323_Determiner_Consigne_Couple_Moteur_Max(VSCtl_rConvTra_swc_in, /* BIN7 */
	                                                    VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
	                                                    VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
	                                                    VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
	                                                    VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
	                                                    VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
	                                                    VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
	                                                    VSCtl_tqLossTra_swc_in, /* BIN4 */
	                                                    VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
	                                                    &vssp_vsctl_tqckefcmaxreq_cpy /* BIN4 */);

		/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.58.1 */

	  VSSP_F71321_Determiner_Consigne_Couple_Moteur_Max_Init(vssp_vsctl_tqckefcmaxreq_cpy /* BIN4 */);

	    /* TAG_START_OF_STATEFLOW_FUNCTION: F71324_Determiner_Effectivite_Couple_Moteur_Max*/
		/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.62.2 */

    if (vssp_torque_control_gmp2_sf_dwork.is_active_c350_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c350_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c350_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_COUPLE_MOTEUR_MAX;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MAX =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_b;
      vssp_vsctl_bctlefc_tqckefcmax_cpy = VSSP_Torque_Control_Gmp2_Sf_VRAI_i;

    }
    else
    {
      switch (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MAX)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_b:
        if ((VSCtl_stCtl_tqCkEfcMax == VSCTL_STCTL_TQCKEFCMAX_ARRET)
        ||
            (vssp_vsctl_tqckefcmaxreq_cpy >= (VSCtl_tqCkEfcPreCoVSCtlReq_swc_in >
              vssp_vsctl_tqckefcminreq_cpy ? (SInt32)VSCtl_tqCkEfcPreCoVSCtlReq_swc_in :
              (SInt32)vssp_vsctl_tqckefcminreq_cpy)))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MAX =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_fr;
          vssp_vsctl_bctlefc_tqckefcmax_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_h;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_fr:
        if ((VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET)
        &&
            (vssp_vsctl_tqckefcmaxreq_cpy < ((VSCtl_tqCkEfcPreCoVSCtlReq_swc_in >
               vssp_vsctl_tqckefcminreq_cpy ? (SInt32)VSCtl_tqCkEfcPreCoVSCtlReq_swc_in :
               (SInt32)vssp_vsctl_tqckefcminreq_cpy) + VSCtl_tqCkEfc_bCtlEfcMaxHys_C)))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MAX =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_b;
          vssp_vsctl_bctlefc_tqckefcmax_cpy = VSSP_Torque_Control_Gmp2_Sf_VRAI_i;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MAX =
          (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_b;
        vssp_vsctl_bctlefc_tqckefcmax_cpy = VSSP_Torque_Control_Gmp2_Sf_VRAI_i;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71324_Determiner_Effectivite_Couple_Moteur_Max*/

	 VSSP_F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max(VSCtl_nEngFil_swc_in, /* BIN0 */
                                                                    vssp_vsctl_tqckefcmaxreq_cpy, /* BIN4 */
                                                                    VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                                    VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                                    &vssp_vsctl_raccpengmax_cpy /* BIN7 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71326_Determiner_Effectivite_Position_Pedale_Accelerateur_Moteur_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.64.0 */


    if (vssp_torque_control_gmp2_sf_dwork.is_active_c351_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c351_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c351_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_i;
      VSCtl_bCtlEfc_rAccPMax_pt2 = VSSP_Torque_Control_Gmp2_Sf_FAUX_fx;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_j:
        if ((VSCtl_stCtl_tqCkEfcMax == VSCTL_STCTL_TQCKEFCMAX_ARRET)
        ||
            (vssp_vsctl_raccpengmax_cpy >= AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_i;
          VSCtl_bCtlEfc_rAccPMax_pt2 = VSSP_Torque_Control_Gmp2_Sf_FAUX_fx;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_i:
        if ((VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET)
        &&
            (vssp_vsctl_raccpengmax_cpy < AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_j;
          VSCtl_bCtlEfc_rAccPMax_pt2 = VSSP_Torque_Control_Gmp2_Sf_VRAI_jk;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_i;
        VSCtl_bCtlEfc_rAccPMax_pt2 = VSSP_Torque_Control_Gmp2_Sf_FAUX_fx;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71326_Determiner_Effectivite_Position_Pedale_Accelerateur_Moteur_Max*/


    stack_data_s16_0 = vssp_torque_control_gmp2_delay_2;


    /* TAG_START_OF_STATEFLOW_FUNCTION: F71327_Determiner_Mode_Commande_Couple_Moteur_Cible_Max*/
			/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.140.0 */

    if (vssp_torque_control_gmp2_sf_dwork.is_active_c112_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c112_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c112_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_COUPLE_MOTEUR_CIBLE_MAX;
      vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_k;
      VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_ARRET;
      VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C;
      VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;
      vssp_torque_control_gmp2_sf_dwork.is_active_MEMOIRES = 1U;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_k:
        if ((VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET)
        &&
            (Ext_stTraTypCf_swc_in == EXT_STTRATYPCF_DCT))
        {
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_jd;
          vssp_torque_control_gmp2_sf_dwork.is_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0_o;
          vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP_m;
          VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_HORS_SIP;
          VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C;
          VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_jd:
        if ((VSCtl_stCtl_tqCkEfcMax == VSCTL_STCTL_TQCKEFCMAX_ARRET)
        ||
            (Ext_stTraTypCf_swc_in != EXT_STTRATYPCF_DCT))
        {
          vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_l;
          vssp_torque_control_gmp2_sf_dwork.is_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_l;
          vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_k;
          VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_ARRET;
          VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C;
          VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;

        }
        else
        {
          switch (vssp_torque_control_gmp2_sf_dwork.is_CONTROLE)
        {
           case VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0_o:
            if (VSCtl_bAvlTqWhlPT_no3_swc_in == VSSP_Torque_Control_Gmp2_Sf_FAUX_b)
            {
              vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_l;
              vssp_torque_control_gmp2_sf_dwork.is_CONTROLE = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_PENDANT_SIP_d;
              VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_SIP;
              VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C;

            }
            else
            {
              switch (vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP)
        {
               case VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_HIGH_h:
                if ((VSCtl_tiFilStCtlTqEfcTarMax == 0) ||
                    (stack_data_s16_0 >=
                     vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMaxReqPrev_d))
                {
                  vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = (UInt8)
                    VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP_m;
                  VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_HORS_SIP;
                  VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C;
                  VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;

                }
                else
                {
                  VSCtl_tiFilStCtlTqEfcTarMax = (UInt16)
                    (VSCtl_tiFilStCtlTqEfcTarMax - 1);
                }
                break;

               case VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_LOW_l:
                if ((VSCtl_tiFilStCtlTqEfcTarMax == 0) ||
                    (stack_data_s16_0 <=
                     vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMaxReqPrev_d))
                {
                  vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = (UInt8)
                    VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP_m;
                  VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_HORS_SIP;
                  VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C;
                  VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;

                }
                else
                {
                  VSCtl_tiFilStCtlTqEfcTarMax = (UInt16)
                    (VSCtl_tiFilStCtlTqEfcTarMax - 1);
                }
                break;
              }
            }
            break;

           case VSSP_Torque_Control_Gmp2_Sf_IN_PENDANT_SIP_d:
            if ((VSCtl_bAvlTqWhlPT_no3_swc_in == VSSP_Torque_Control_Gmp2_Sf_VRAI_n)
            &&
                (stack_data_s16_0 >= vssp_vsctl_tqckefcmaxreq_cpy))
            {
              vssp_torque_control_gmp2_sf_dwork.is_CONTROLE = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0_o;
              vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_LOW_l;
              VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_FIN_SIP_LOW;
              VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;

            }
            else if ((VSCtl_bAvlTqWhlPT_no3_swc_in ==
                        VSSP_Torque_Control_Gmp2_Sf_VRAI_n) &&
                       (stack_data_s16_0 <
                        vssp_vsctl_tqckefcmaxreq_cpy))
            {
              vssp_torque_control_gmp2_sf_dwork.is_CONTROLE = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_HORS_SIP____0_o;
              vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_FIN_SIP_HIGH_h;
              VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_FIN_SIP_HIGH;
              VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;

            }
            else
            {
              VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_VRAI_n;
            }
            break;
          }
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_k;
        VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_ARRET;
        VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C;
        VSCtl_bAcvFil_tqEfcTarMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_b;
        break;
      }

      vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMaxReqPrev_d =
        vssp_vsctl_tqckefcmaxreq_cpy;
    }

    VSCtl_tqCkEfcMaxReqPrev =  DDS_M_LIMIT
      (vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMaxReqPrev_d,
       VSCTL_TQCKEFCMAXREQPREV_MIN,
       VSCTL_TQCKEFCMAXREQPREV_MAX);

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71327_Determiner_Mode_Commande_Couple_Moteur_Cible_Max*/


     VSSP_F71328_Determiner_Consigne_Couple_Moteur_Cible_Max(CoPt_nPrimShaftTar_swc_in,   /* BIN0 */
                                                          Ext_nFrntWhl_swc_in,         /* BIN7 */
                                                          vssp_vsctl_tqckefcmaxreq_cpy,     /* BIN4 */
                                                          VSCtl_tqWhlMaxReq_swc_in,    /* BIN1 */
                                                          &vssp_vsctl_tqefctarmax_cpy);

       /* TAG_START_OF_STATEFLOW_FUNCTION: F7133_Determiner_Autorisation_Recuperation_Energie*/
   		/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.65.0 */


    if (vssp_torque_control_gmp2_sf_dwork.is_active_c185_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c185_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c185_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_AUTORISATION_RECUPERATION_ENERGIE;
      vssp_torque_control_gmp2_sf_dwork.is_AUTORISATION_RECUPERATION_ENERGIE =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_FAUX;
      vssp_vsctl_binhrecup_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_f0;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_AUTORISATION_RECUPERATION_ENERGIE)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_FAUX:
        if (((vssp_vsctl_bctlefc_tqckefcmax_cpy == VSSP_Torque_Control_Gmp2_Sf_VRAI_l)
        &&
             (VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET))
             ||
            ((vssp_vsctl_bctlefc_tqckefcmin_cpy == VSSP_Torque_Control_Gmp2_Sf_VRAI_l)
            &&
             (VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)))
        {
          vssp_torque_control_gmp2_sf_dwork.is_AUTORISATION_RECUPERATION_ENERGIE
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_VRAI;
          vssp_vsctl_binhrecup_cpy = VSSP_Torque_Control_Gmp2_Sf_VRAI_l;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_VRAI:
        if (((vssp_vsctl_bctlefc_tqckefcmax_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_f0)
        ||
             (VSCtl_stCtl_tqCkEfcMax == VSCTL_STCTL_TQCKEFCMAX_ARRET))
             &&
            ((vssp_vsctl_bctlefc_tqckefcmin_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_f0)
            ||
             (VSCtl_stCtl_tqCkEfcMin == VSCTL_STCTL_TQCKEFCMIN_ARRET)))
        {
          vssp_torque_control_gmp2_sf_dwork.is_AUTORISATION_RECUPERATION_ENERGIE
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_FAUX;
          vssp_vsctl_binhrecup_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_f0;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_AUTORISATION_RECUPERATION_ENERGIE =
          (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_FAUX;
        vssp_vsctl_binhrecup_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_f0;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F7133_Determiner_Autorisation_Recuperation_Energie*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F7134_Determiner_Effectivite_Processus_XVV*/
			/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.66.0 */
    if (vssp_torque_control_gmp2_sf_dwork.is_active_c186_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c186_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c186_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIVITE_PROCESSUS_XVV;
      vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2 =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
      vssp_vsctl_sttqptminctl_pt2_cpy = VSCTL_STTQPTMINCTL_PT2_INACTIF;
      vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2 =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
      vssp_vsctl_sttqptmaxctl_pt2_cpy = VSCTL_STTQPTMAXCTL_PT2_INACTIF;
      vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
      VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_INACTIF;
      vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_ROUE_GMP2 =
        1U;
      vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP2 =
        (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_a;
      vssp_vsctl_bctlefc_tqwhlpt_pt2_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_fk;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF:
        if (VSCtl_stCtl_tqCkEfcMin == VSCTL_STCTL_TQCKEFCMIN_ARRET)
        {
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_k;
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
          vssp_vsctl_sttqptminctl_pt2_cpy = VSCTL_STTQPTMINCTL_PT2_INACTIF;

        }
        else
        {
          switch (vssp_torque_control_gmp2_sf_dwork.is_ACTIF)
        {
           case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqckefcmin_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_fk)
            {
              vssp_torque_control_gmp2_sf_dwork.is_ACTIF = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF;
              vssp_vsctl_sttqptminctl_pt2_cpy = VSCTL_STTQPTMINCTL_PT2_ANE;
            }
            break;

           case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqckefcmin_cpy == VSSP_Torque_Control_Gmp2_Sf_VRAI_n1)
            {
              vssp_torque_control_gmp2_sf_dwork.is_ACTIF = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF;
              vssp_vsctl_sttqptminctl_pt2_cpy = VSCTL_STTQPTMINCTL_PT2_AE;
            }
            break;
          }
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF:
        if ((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        &&
            (vssp_vsctl_bctlefc_tqckefcmin_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_fk))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF;
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF;
          vssp_vsctl_sttqptminctl_pt2_cpy = VSCTL_STTQPTMINCTL_PT2_ANE;

        }
        else if ((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        &&
                   (vssp_vsctl_bctlefc_tqckefcmin_cpy ==
                    VSSP_Torque_Control_Gmp2_Sf_VRAI_n1))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF;
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF;
          vssp_vsctl_sttqptminctl_pt2_cpy = VSCTL_STTQPTMINCTL_PT2_AE;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
        vssp_vsctl_sttqptminctl_pt2_cpy = VSCTL_STTQPTMINCTL_PT2_INACTIF;
        break;
      }

      switch
        (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF:
        if (VSCtl_stCtl_tqCkEfcMax == VSCTL_STCTL_TQCKEFCMAX_ARRET)
        {
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF_b = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_k;
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
          vssp_vsctl_sttqptmaxctl_pt2_cpy = VSCTL_STTQPTMAXCTL_PT2_INACTIF;

        }
        else
        {
          switch (vssp_torque_control_gmp2_sf_dwork.is_ACTIF_b)
        {
           case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqckefcmax_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_fk)
            {
              vssp_torque_control_gmp2_sf_dwork.is_ACTIF_b = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF;
              vssp_vsctl_sttqptmaxctl_pt2_cpy = VSCTL_STTQPTMAXCTL_PT2_ANE;
            }
            break;

           case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqckefcmax_cpy == VSSP_Torque_Control_Gmp2_Sf_VRAI_n1)
            {
              vssp_torque_control_gmp2_sf_dwork.is_ACTIF_b = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF;
              vssp_vsctl_sttqptmaxctl_pt2_cpy = VSCTL_STTQPTMAXCTL_PT2_AE;
            }
            break;
          }
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF:
        if ((VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET)
        &&
            (vssp_vsctl_bctlefc_tqckefcmax_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_fk))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF;
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF_b = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF;
          vssp_vsctl_sttqptmaxctl_pt2_cpy = VSCTL_STTQPTMAXCTL_PT2_ANE;

        }
        else if ((VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET)
        &&
                   (vssp_vsctl_bctlefc_tqckefcmax_cpy ==
                    VSSP_Torque_Control_Gmp2_Sf_VRAI_n1))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF;
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF_b = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF;
          vssp_vsctl_sttqptmaxctl_pt2_cpy = VSCTL_STTQPTMAXCTL_PT2_AE;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
        vssp_vsctl_sttqptmaxctl_pt2_cpy = VSCTL_STTQPTMAXCTL_PT2_INACTIF;
        break;
      }

      switch
        (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF:
        if ((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        &&
            (VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET))
        {
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF_j = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_k;
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
          VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_INACTIF;

        }
        else
        {
          switch (vssp_torque_control_gmp2_sf_dwork.is_ACTIF_j)
        {
           case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF:
            if ((VSCtl_bCtlEfc_rAccPMin_pt2 !=
                 VSSP_Torque_Control_Gmp2_Sf_VRAI_n1) &&
                (VSCtl_bCtlEfc_rAccPMax_pt2 !=
                 VSSP_Torque_Control_Gmp2_Sf_VRAI_n1))
            {
              vssp_torque_control_gmp2_sf_dwork.is_ACTIF_j = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF;
              VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_ANE;
            }
            break;

           case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF:
            if ((VSCtl_bCtlEfc_rAccPMin_pt2 ==
                 VSSP_Torque_Control_Gmp2_Sf_VRAI_n1) ||
                (VSCtl_bCtlEfc_rAccPMax_pt2 ==
                 VSSP_Torque_Control_Gmp2_Sf_VRAI_n1))
            {
              vssp_torque_control_gmp2_sf_dwork.is_ACTIF_j = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF;
              VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_AE;
            }
            break;
          }
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF:
        if ((((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        ||
              (VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET))
              &&
             (VSCtl_bCtlEfc_rAccPMin_pt2 != VSSP_Torque_Control_Gmp2_Sf_VRAI_n1))
            && (VSCtl_bCtlEfc_rAccPMax_pt2 !=
                VSSP_Torque_Control_Gmp2_Sf_VRAI_n1))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF;
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF_j = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_NON_EFFECTIF;
          VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_ANE;

        }
        else if (((VSCtl_stCtl_tqCkEfcMin != VSCTL_STCTL_TQCKEFCMIN_ARRET)
        ||
                    (VSCtl_stCtl_tqCkEfcMax != VSCTL_STCTL_TQCKEFCMAX_ARRET))
                    &&
                   ((VSCtl_bCtlEfc_rAccPMin_pt2 ==
                     VSSP_Torque_Control_Gmp2_Sf_VRAI_n1) ||
                    (VSCtl_bCtlEfc_rAccPMax_pt2 ==
                     VSSP_Torque_Control_Gmp2_Sf_VRAI_n1)))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF;
          vssp_torque_control_gmp2_sf_dwork.is_ACTIF_j = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_ACTIF_EFFECTIF;
          VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_AE;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_INACTIF;
        VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_INACTIF;
        break;
      }

      switch (vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP2)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_bc:
        if ((vssp_vsctl_bctlefc_tqckefcmin_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_fk)
        &&
            (vssp_vsctl_bctlefc_tqckefcmax_cpy == VSSP_Torque_Control_Gmp2_Sf_FAUX_fk))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP2 =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_a;
          vssp_vsctl_bctlefc_tqwhlpt_pt2_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_fk;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_a:
        if ((vssp_vsctl_bctlefc_tqckefcmin_cpy == VSSP_Torque_Control_Gmp2_Sf_VRAI_n1)
        ||
            (vssp_vsctl_bctlefc_tqckefcmax_cpy == VSSP_Torque_Control_Gmp2_Sf_VRAI_n1))
        {
          vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP2 =
            (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_EFFECTIF_bc;
          vssp_vsctl_bctlefc_tqwhlpt_pt2_cpy = VSSP_Torque_Control_Gmp2_Sf_VRAI_n1;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP2 =
          (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_NON_EFFECTIF_a;
        vssp_vsctl_bctlefc_tqwhlpt_pt2_cpy = VSSP_Torque_Control_Gmp2_Sf_FAUX_fk;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F7134_Determiner_Effectivite_Processus_XVV*/


    vssp_torque_control_gmp2_delay_0 = vssp_vsctl_tqefctarmin_cpy;

    vssp_torque_control_gmp2_delay_1 = VSCtl_tqCkEfcMaxReqDly;

    vssp_torque_control_gmp2_delay_2 = vssp_vsctl_tqefctarmax_cpy;
  }

		/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.23.6 */

  /* TAG_START_OF_STATEFLOW_FUNCTION: VSSP_enable_F721*/

  if (vssp_torque_control_gmp2_sf_dwork.is_active_c1_VSSP_Torque_Control_Gmp2_Sf
      == 0)
  {
    vssp_torque_control_gmp2_sf_dwork.is_active_c1_VSSP_Torque_Control_Gmp2_Sf =
      1U;
    vssp_torque_control_gmp2_sf_dwork.is_c1_VSSP_Torque_Control_Gmp2_Sf =
      (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_VSSP_enable_F721;
    vssp_torque_control_gmp2_sf_dwork.is_VSSP_enable_F721 = (UInt8)
      VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_ao;
    vsctl_bacvf721 = VSSP_Torque_Control_Gmp2_Sf_FAUX_m;

  }
  else
  {
    switch (vssp_torque_control_gmp2_sf_dwork.is_VSSP_enable_F721)
        {
     case VSSP_Torque_Control_Gmp2_Sf_IN_ACTIVE:
      if (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
      {
        vssp_torque_control_gmp2_sf_dwork.is_VSSP_enable_F721 = (UInt8)
          VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_ao;
        vsctl_bacvf721 = VSSP_Torque_Control_Gmp2_Sf_FAUX_m;
      }
      break;

     case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_ao:
      if (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
      {
        vssp_torque_control_gmp2_sf_dwork.is_VSSP_enable_F721 = (UInt8)
          VSSP_Torque_Control_Gmp2_Sf_IN_ACTIVE;
        vsctl_bacvf721 = VSSP_Torque_Control_Gmp2_Sf_VRAI_am;
      }
      break;

     default:
      vssp_torque_control_gmp2_sf_dwork.is_VSSP_enable_F721 = (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_ao;
      vsctl_bacvf721 = VSSP_Torque_Control_Gmp2_Sf_FAUX_m;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: VSSP_enable_F721*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.67.0 */
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.28.2 */

  if (DDS_TRUE==vsctl_bacvf721)
  {

    /* TAG_START_OF_STATEFLOW_FUNCTION: F72111_Determiner_Mode_Commande_Potentiel_Couple_Roue_GMP_Min*/
			/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.68.0 */
    if (vssp_torque_control_gmp2_sf_dwork.is_active_c2_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c2_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c2_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN;
      vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_m;
      VSCtl_stCtl_tqWhlPTPotMin = VSCTL_STCTL_TQWHLPTPOTMIN_ARRET;
      VSCtl_bAcvFil_tqWhlPTPotMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_k;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_m:
        if ((VSCtl_stCtl_tqWhlPotMin_swc_in == VSCTL_STCTL_TQWHLPOTMIN_CONTROLE)
        &&
            (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_COUPLE))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_i;
          VSCtl_stCtl_tqWhlPTPotMin = VSCTL_STCTL_TQWHLPTPOTMIN_CONTROLE;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_i:
        if ((VSCtl_stCtl_tqWhlPotMin_swc_in == VSCTL_STCTL_TQWHLPOTMIN_ARRET)
        ||
            (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_COUPLE))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_m;
          VSCtl_stCtl_tqWhlPTPotMin = VSCTL_STCTL_TQWHLPTPOTMIN_ARRET;
          VSCtl_bAcvFil_tqWhlPTPotMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_k;

        }
        else
        {
          VSCtl_bAcvFil_tqWhlPTPotMin = VSSP_Torque_Control_Gmp2_Sf_VRAI_a3;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_m;
        VSCtl_stCtl_tqWhlPTPotMin = VSCTL_STCTL_TQWHLPTPOTMIN_ARRET;
        VSCtl_bAcvFil_tqWhlPTPotMin = VSSP_Torque_Control_Gmp2_Sf_FAUX_k;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F72111_Determiner_Mode_Commande_Potentiel_Couple_Roue_GMP_Min*/


 /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.31.2 */

   VSSP_F72112_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Min(Ext_stCtlCmdPTTqPotCf_swc_in,
                                                                 VSCtl_stCtl_tqWhlPotMin_swc_in,
                                                                 VSCtl_tqWhlPotMinReq_swc_in, /* BIN1 */
                                                                 VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                                                 VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                                                 VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                                                                 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                                 &vssp_vsctl_tqwhlptpotminreq_cpy /* BIN1 */);

     /* TAG_START_OF_STATEFLOW_FUNCTION: F72121_Determiner_Mode_Commande_Potentiel_Couple_Roue_GMP_Max*/
 	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.69.0 */

    if (vssp_torque_control_gmp2_sf_dwork.is_active_c3_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c3_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c3_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX;
      vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_n;
      VSCtl_stCtl_tqWhlPTPotMax = VSCTL_STCTL_TQWHLPTPOTMAX_ARRET;
      VSCtl_bAcvFil_tqWhlPTPotMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_l;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_n:
        if ((VSCtl_stCtl_tqWhlPotMax_swc_in == VSCTL_STCTL_TQWHLPOTMAX_CONTROLE)
        &&
            (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_COUPLE))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_h;
          VSCtl_stCtl_tqWhlPTPotMax = VSCTL_STCTL_TQWHLPTPOTMAX_CONTROLE;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_h:
        if ((VSCtl_stCtl_tqWhlPotMax_swc_in == VSCTL_STCTL_TQWHLPOTMAX_ARRET)
        ||
            (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_COUPLE))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_n;
          VSCtl_stCtl_tqWhlPTPotMax = VSCTL_STCTL_TQWHLPTPOTMAX_ARRET;
          VSCtl_bAcvFil_tqWhlPTPotMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_l;

        }
        else
        {
          VSCtl_bAcvFil_tqWhlPTPotMax = VSSP_Torque_Control_Gmp2_Sf_VRAI_g;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_n;
        VSCtl_stCtl_tqWhlPTPotMax = VSCTL_STCTL_TQWHLPTPOTMAX_ARRET;
        VSCtl_bAcvFil_tqWhlPTPotMax = VSSP_Torque_Control_Gmp2_Sf_FAUX_l;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F72121_Determiner_Mode_Commande_Potentiel_Couple_Roue_GMP_Max*/


   VSSP_F72122_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Max(Ext_stCtlCmdPTTqPotCf_swc_in,
                                                                  VSCtl_stCtl_tqWhlPotMax_swc_in,
                                                                  VSCtl_tqWhlPotMaxReq_swc_in, /* BIN1 */
                                                                  VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                                                  VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                                                  VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                                                                  VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                                  &vssp_vsctl_tqwhlptpotmaxreq_cpy /* BIN1 */);

      /* TAG_START_OF_STATEFLOW_FUNCTION: F7213_Determiner_Demande_Pilotage_Potentiel_Couple_Roue_GMP*/
  	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.70.0 */


    if (vssp_torque_control_gmp2_sf_dwork.is_active_c4_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c4_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c4_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP;
      vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_g;
      vssp_vsctl_sttqwhlptpotctlreq_cpy = VSCTL_STTQWHLPTPOTCTLREQ_ARRET;
      VSCtl_tiHldWhlPotCtlReq = VSCtl_tiHldWhlPotCtlReq_C;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_g:
        if (((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_COUPLE)
        ||
             (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT))
             &&
            ((VSCtl_stCtl_tqWhlPTPotMin != VSCTL_STCTL_TQWHLPTPOTMIN_ARRET)
            ||
             (VSCtl_stCtl_tqWhlPTPotMax != VSCTL_STCTL_TQWHLPTPOTMAX_ARRET)))
        {
          vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_MARCHE;
          vssp_torque_control_gmp2_sf_dwork.is_MARCHE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_MODE_1;
          vssp_vsctl_sttqwhlptpotctlreq_cpy = VSCTL_STTQWHLPTPOTCTLREQ_MODE_1;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_MARCHE:
        if ((Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_COUPLE)
        &&
            (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_RAPPORT))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MARCHE = (UInt8)
            VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_g;
          vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_g;
          vssp_vsctl_sttqwhlptpotctlreq_cpy = VSCTL_STTQWHLPTPOTCTLREQ_ARRET;
          VSCtl_tiHldWhlPotCtlReq = VSCtl_tiHldWhlPotCtlReq_C;

        }
        else
        {
          switch (vssp_torque_control_gmp2_sf_dwork.is_MARCHE)
        {
           case VSSP_Torque_Control_Gmp2_Sf_IN_MODE_1:
            if ((VSCtl_stCtl_tqWhlPTPotMin == VSCTL_STCTL_TQWHLPTPOTMIN_ARRET)
            &&
                (VSCtl_stCtl_tqWhlPTPotMax == VSCTL_STCTL_TQWHLPTPOTMAX_ARRET))
            {
              vssp_torque_control_gmp2_sf_dwork.is_MARCHE = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_MODE_2;
              vssp_vsctl_sttqwhlptpotctlreq_cpy = VSCTL_STTQWHLPTPOTCTLREQ_MODE_2;
              VSCtl_tiHldWhlPotCtlReq = VSCtl_tiHldWhlPotCtlReq_C;
            }
            break;

           case VSSP_Torque_Control_Gmp2_Sf_IN_MODE_2:
            if (((VSCtl_tiHldWhlPotCtlReq == 0)
            && (VSCtl_stCtl_tqWhlPTPotMin ==
                  VSCTL_STCTL_TQWHLPTPOTMIN_ARRET)) &&
                (VSCtl_stCtl_tqWhlPTPotMax == VSCTL_STCTL_TQWHLPTPOTMAX_ARRET))
            {
              vssp_torque_control_gmp2_sf_dwork.is_MARCHE = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_NO_ACTIVE_CHILD_g;
              vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP
                = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_g;
              vssp_vsctl_sttqwhlptpotctlreq_cpy = VSCTL_STTQWHLPTPOTCTLREQ_ARRET;
              VSCtl_tiHldWhlPotCtlReq = VSCtl_tiHldWhlPotCtlReq_C;

            }
            else if ((VSCtl_stCtl_tqWhlPTPotMin !=
                        VSCTL_STCTL_TQWHLPTPOTMIN_ARRET) ||
                       (VSCtl_stCtl_tqWhlPTPotMax !=
                        VSCTL_STCTL_TQWHLPTPOTMAX_ARRET))
            {
              vssp_torque_control_gmp2_sf_dwork.is_MARCHE = (UInt8)
                VSSP_Torque_Control_Gmp2_Sf_IN_MODE_1;
              vssp_vsctl_sttqwhlptpotctlreq_cpy = VSCTL_STTQWHLPTPOTCTLREQ_MODE_1;

            }
            else
            {
              VSCtl_tiHldWhlPotCtlReq = (UInt16)DDS_M_MAX(VSCtl_tiHldWhlPotCtlReq
                - 1, 0);
            }
            break;
          }
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_g;
        vssp_vsctl_sttqwhlptpotctlreq_cpy = VSCTL_STTQWHLPTPOTCTLREQ_ARRET;
        VSCtl_tiHldWhlPotCtlReq = VSCtl_tiHldWhlPotCtlReq_C;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F7213_Determiner_Demande_Pilotage_Potentiel_Couple_Roue_GMP*/

  VSSP_F7214_Determiner_Temps_Confirmation_Changement_Rapport(Ext_stCtlCmdPTTqPotCf_swc_in,
                                                                VSCtl_tiCfmSdwnTqMaxReq_swc_in, /* DEC2 */
                                                                VSCtl_tiCfmSdwnTqMinReq_swc_in, /* DEC2 */
                                                                VSCtl_tiCfmSupTqMaxReq_swc_in, /* DEC2 */
                                                                VSCtl_tiCfmSupTqMinReq_swc_in, /* DEC2 */
                                                                &vssp_vsctl_ticfmsupreq_cpy, /* DEC2 */
                                                                &vssp_vsctl_ticfmsdwnreq_cpy /* DEC2 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F72151_Determiner_Mode_Calcul_Consigne_Potentiel_Couple_Roue_GMP*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.71.0 */


    if (vssp_torque_control_gmp2_sf_dwork.is_active_c5_VSSP_Torque_Control_Gmp2_Sf
        == 0)
    {
      vssp_torque_control_gmp2_sf_dwork.is_active_c5_VSSP_Torque_Control_Gmp2_Sf
        = 1U;
      vssp_torque_control_gmp2_sf_dwork.is_c5_VSSP_Torque_Control_Gmp2_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp2_Sf_IN_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP;
      vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP
        = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_d;
      VSCtl_stCtl_tqWhlPTPot = VSCTL_STCTL_TQWHLPTPOT_ARRET;
      VSCtl_bAcvFil_tqWhlPTPot = VSSP_Torque_Control_Gmp2_Sf_FAUX_h2;

    }
    else
    {
      switch
        (vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP)
      {
       case VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_d:
        if (((VSCtl_stCtl_tqWhlPot_swc_in == VSCTL_STCTL_TQWHLPOT_CONTROLE)
        &&
             (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT))
             &&
            (VSCtl_bCtlCmdPTTqCf_SC == VSSP_Torque_Control_Gmp2_Sf_FAUX_h2))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_l;
          VSCtl_stCtl_tqWhlPTPot = VSCTL_STCTL_TQWHLPTPOT_CONTROLE;
        }
        break;

       case VSSP_Torque_Control_Gmp2_Sf_IN_CONTROLE_l:
        if (((VSCtl_stCtl_tqWhlPot_swc_in == VSCTL_STCTL_TQWHLPOT_ARRET) ||
             (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_RAPPORT))
             ||
            (VSCtl_bCtlCmdPTTqCf_SC != VSSP_Torque_Control_Gmp2_Sf_FAUX_h2))
        {
          vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP
            = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_d;
          VSCtl_stCtl_tqWhlPTPot = VSCTL_STCTL_TQWHLPTPOT_ARRET;
          VSCtl_bAcvFil_tqWhlPTPot = VSSP_Torque_Control_Gmp2_Sf_FAUX_h2;

        }
        else
        {
          VSCtl_bAcvFil_tqWhlPTPot = VSSP_Torque_Control_Gmp2_Sf_VRAI_k;
        }
        break;

       default:
        vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP
          = (UInt8)VSSP_Torque_Control_Gmp2_Sf_IN_ARRET_d;
        VSCtl_stCtl_tqWhlPTPot = VSCTL_STCTL_TQWHLPTPOT_ARRET;
        VSCtl_bAcvFil_tqWhlPTPot = VSSP_Torque_Control_Gmp2_Sf_FAUX_h2;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F72151_Determiner_Mode_Calcul_Consigne_Potentiel_Couple_Roue_GMP*/


      VSSP_F72152_Determiner_Consigne_Potentiel_Couple_Roue_Gmp(VSCtl_tqWhlPotReq_swc_in, /* BIN1 */
	                                                            VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
	                                                            VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
	                                                            &vssp_vsctl_tqwhlptpotreq_cpy /* BIN1 */);

  }

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_tqCkEfcMaxReq_swc_out = vssp_vsctl_tqckefcmaxreq_cpy;

  *VSCtl_tqCkEfcMinReq_swc_out = vssp_vsctl_tqckefcminreq_cpy;

  *VSCtl_tqEfcTarMax_swc_out = vssp_vsctl_tqefctarmax_cpy;

  *VSCtl_tqEfcTarMin_swc_out = vssp_vsctl_tqefctarmin_cpy;

  *VSCtl_tqWhlPTPotMaxReq_swc_out = vssp_vsctl_tqwhlptpotmaxreq_cpy;

  *VSCtl_tqWhlPTPotMinReq_swc_out = vssp_vsctl_tqwhlptpotminreq_cpy;

  *VSCtl_tqWhlPTPotReq_swc_out = vssp_vsctl_tqwhlptpotreq_cpy;

  *VSCtl_rAccPEngMax_swc_out = vssp_vsctl_raccpengmax_cpy;

  *VSCtl_rAccPEngMin_swc_out = vssp_vsctl_raccpengmin_cpy;

  *VSCtl_tiCfmSdwnReq_swc_out = vssp_vsctl_ticfmsdwnreq_cpy;

  *VSCtl_tiCfmSupReq_swc_out = vssp_vsctl_ticfmsupreq_cpy;

  *VSCtl_bCtlEfc_tqCkEfcMax_swc_out = vssp_vsctl_bctlefc_tqckefcmax_cpy;

  *VSCtl_bCtlEfc_tqCkEfcMin_swc_out = vssp_vsctl_bctlefc_tqckefcmin_cpy;

  *VSCtl_bCtlEfc_tqWhlPT_pt2_swc_out = vssp_vsctl_bctlefc_tqwhlpt_pt2_cpy;

  *VSCtl_bInhRecup_swc_out = vssp_vsctl_binhrecup_cpy;

  *VSCtl_stTqPTMaxCtl_pt2_swc_out = vssp_vsctl_sttqptmaxctl_pt2_cpy;

  *VSCtl_stTqPTMinCtl_pt2_swc_out = vssp_vsctl_sttqptminctl_pt2_cpy;

  *VSCtl_stTqWhlPTPotCtlReq_swc_out = vssp_vsctl_sttqwhlptpotctlreq_cpy;

}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp2_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMaxReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMin_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnReq_swc_out,                           /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTPotCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMin_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bInhRecup_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMax_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMin_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMinReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupReq_swc_out)                            /*DEC2*/
{

  VSSP_Control_Wheel_Gmp2_Sl_Init(VSCtl_rAccPEngMax_swc_out, /* BIN7 */
                                        VSCtl_rAccPEngMin_swc_out, /* BIN7 */
                                        VSCtl_tqCkEfcMaxReq_swc_out, /* BIN4 */
                                        VSCtl_tqCkEfcMinReq_swc_out, /* BIN4 */
                                        VSCtl_tqEfcTarMax_swc_out, /* BIN4 */
                                        VSCtl_tqEfcTarMin_swc_out);

      VSSP_Potential_Gmp_Sl_Init(VSCtl_tiCfmSdwnReq_swc_out, /* DEC2 */
                               VSCtl_tiCfmSupReq_swc_out, /* DEC2 */
                               VSCtl_tqWhlPTPotMaxReq_swc_out, /* BIN1 */
                               VSCtl_tqWhlPTPotMinReq_swc_out, /* BIN1 */
                               VSCtl_tqWhlPTPotReq_swc_out /* BIN1 */);

    /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
    vssp_vsctl_raccpengmin_cpy = *VSCtl_rAccPEngMin_swc_out;

    vssp_vsctl_ticfmsupreq_cpy = *VSCtl_tiCfmSupReq_swc_out;

    vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP=0;
    vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX=0;
    vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN=0;
    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2=0;
    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX=0;
    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN=0;
    vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2=0;
    vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2=0;
    vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2=0;
    vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX=0;
    vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN=0;
    vssp_vsctl_ticfmsdwnreq_cpy = *VSCtl_tiCfmSdwnReq_swc_out;

    vssp_torque_control_gmp2_sf_b.vss_Keep_Global_Data_From_Input=0;
    /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


    VSCtl_tiHldWhlPotCtlReq = VSCtl_tiHldWhlPotCtlReq_C;  /* Replaced by Post task */     /* Init from Model */
    VSCtl_tiFilStCtlTqEfcTarMax = VSCtl_tiFil_stCtlTqEfcTarMax_C; /* Replaced by Post task */     /* Init from Model */
    VSCtl_tiFiltqCkEfcMaxReq = VSCtl_tiFiltqCkEfcMaxReq_C;    /* Replaced by Post task */     /* Init from Model */
    VSCtl_tiFilStCtlTqEfcTarMin = VSCtl_tiFil_stCtlTqEfcTarMin_C; /* Replaced by Post task */     /* Init from Model */
    vssp_vsctl_tqefctarmax_cpy = *VSCtl_tqEfcTarMax_swc_out;

    VSCtl_tqCkEfcMaxReqPrev = 32000;
    vssp_vsctl_tqckefcmaxreq_cpy = *VSCtl_tqCkEfcMaxReq_swc_out;

    vssp_vsctl_tqefctarmin_cpy = *VSCtl_tqEfcTarMin_swc_out;

    VSCtl_tqCkEfcMinReqPrev = -32000;
    vssp_vsctl_tqckefcminreq_cpy = *VSCtl_tqCkEfcMinReq_swc_out;

    vssp_vsctl_raccpengmax_cpy = *VSCtl_rAccPEngMax_swc_out;

    vssp_vsctl_tqwhlptpotreq_cpy = *VSCtl_tqWhlPTPotReq_swc_out;

    vssp_vsctl_tqwhlptpotmaxreq_cpy = *VSCtl_tqWhlPTPotMaxReq_swc_out;

    vssp_vsctl_tqwhlptpotminreq_cpy = *VSCtl_tqWhlPTPotMinReq_swc_out;

    VSCtl_stCtl_tqWhlPTPot = VSCTL_STCTL_TQWHLPTPOT_ARRET;    /* Replaced by Post task */     /* Init from Model */
    *VSCtl_stTqWhlPTPotCtlReq_swc_out = VSCTL_STTQWHLPTPOTCTLREQ_ARRET;   /* Replaced by Post task */     /* Init from Model */
    vssp_vsctl_sttqwhlptpotctlreq_cpy = *VSCtl_stTqWhlPTPotCtlReq_swc_out;

    VSCtl_stCtl_tqWhlPTPotMax = VSCTL_STCTL_TQWHLPTPOTMAX_ARRET;  /* Replaced by Post task */     /* Init from Model */
    VSCtl_stCtl_tqWhlPTPotMin = VSCTL_STCTL_TQWHLPTPOTMIN_ARRET;  /* Replaced by Post task */     /* Init from Model */
    *VSCtl_stTqPTMinCtl_pt2_swc_out = VSCTL_STTQPTMINCTL_PT2_INACTIF; /* Replaced by Post task */     /* Init from Model */
    vssp_vsctl_sttqptminctl_pt2_cpy = *VSCtl_stTqPTMinCtl_pt2_swc_out;

    *VSCtl_stTqPTMaxCtl_pt2_swc_out = VSCTL_STTQPTMAXCTL_PT2_INACTIF; /* Replaced by Post task */     /* Init from Model */
    vssp_vsctl_sttqptmaxctl_pt2_cpy = *VSCtl_stTqPTMaxCtl_pt2_swc_out;

    VSCtl_st_rAccPCtl_pt2 = VSCTL_ST_RACCPCTL_PT2_INACTIF;    /* Replaced by Post task */     /* Init from Model */
    VSCtl_stCtl_tqEfcTarMax = VSCTL_STCTL_TQEFCTARMAX_ARRET;  /* Replaced by Post task */     /* Init from Model */
    VSCtl_stCtl_tqCkEfcMax = VSCTL_STCTL_TQCKEFCMAX_INIT; /* Replaced by Post task */     /* Init from Model */
    VSCtl_stCtl_tqEfcTarMin = VSCTL_STCTL_TQEFCTARMIN_ARRET;  /* Replaced by Post task */     /* Init from Model */
    VSCtl_stCtl_tqCkEfcMin = VSCTL_STCTL_TQCKEFCMIN_ARRET;    /* Replaced by Post task */     /* Init from Model */
    *VSCtl_bCtlEfc_tqCkEfcMax_swc_out = DDS_TRUE;
    vssp_vsctl_bctlefc_tqckefcmax_cpy = *VSCtl_bCtlEfc_tqCkEfcMax_swc_out;

    *VSCtl_bCtlEfc_tqCkEfcMin_swc_out = DDS_FALSE;
    vssp_vsctl_bctlefc_tqckefcmin_cpy = *VSCtl_bCtlEfc_tqCkEfcMin_swc_out;


    vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_COUPLE_MOTEUR_MIN = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c345_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c345_VSSP_Torque_Control_Gmp2_Sf = 0U;
    VSCtl_bAcvFil_tqCkEfcMin =DDS_FALSE;

    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MIN = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c346_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c346_VSSP_Torque_Control_Gmp2_Sf = 0U;


    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MIN
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c347_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c347_VSSP_Torque_Control_Gmp2_Sf = 0U;
    VSCtl_bCtlEfc_rAccPMin_pt2 =DDS_FALSE;

    vssp_torque_control_gmp2_delay_0 = VSSP_TORQUE_CONTROL_GMP2_CONST_0;

    vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIN =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_CONTROLE_h = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP_h = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_MEMOIRES_l = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c111_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c111_VSSP_Torque_Control_Gmp2_Sf = 0U;
    vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMinReqPrev_l = 0;
    VSCtl_bAcvFil_tqEfcTarMin =DDS_FALSE;

    vssp_torque_control_gmp2_delay_1 = VSSP_TORQUE_CONTROL_GMP2_CONST_2;

    vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_TRANSITION = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_FIN_TRANSITION = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_FIN_TRANSITION = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c349_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c349_VSSP_Torque_Control_Gmp2_Sf = 0U;
    VSCtl_bAcvFil_tqCkEfcMax =DDS_FALSE;
    VSCtl_bTranEnd_tqCkEfcMax =DDS_FALSE;


    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_MOTEUR_MAX = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c350_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c350_VSSP_Torque_Control_Gmp2_Sf = 0U;


    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_MOTEUR_MAX
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c351_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c351_VSSP_Torque_Control_Gmp2_Sf = 0U;
    VSCtl_bCtlEfc_rAccPMax_pt2 =DDS_FALSE;


    vssp_torque_control_gmp2_delay_2 = VSSP_TORQUE_CONTROL_GMP2_CONST_1;


    vssp_torque_control_gmp2_sf_dwork.is_active_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_ETAT_CONTROLE_COUPLE_MOTEUR_CIBLE_MIAX =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_CONTROLE = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_HORS_SIP = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_MEMOIRES = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c112_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c112_VSSP_Torque_Control_Gmp2_Sf = 0U;
    vssp_torque_control_gmp2_sf_b.VSCtl_tqCkEfcMaxReqPrev_d = 0;
    VSCtl_bAcvFil_tqEfcTarMax =DDS_FALSE;


    vssp_torque_control_gmp2_sf_dwork.is_AUTORISATION_RECUPERATION_ENERGIE = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c185_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c185_VSSP_Torque_Control_Gmp2_Sf = 0U;
    *VSCtl_bInhRecup_swc_out =DDS_FALSE;
    vssp_vsctl_binhrecup_cpy = *VSCtl_bInhRecup_swc_out;


    vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP2 = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_ACTIF_b = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP2 = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_ACTIF = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_COUPLE_ROUE_GMP2 = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP2 = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP2
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_ACTIF_j = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c186_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c186_VSSP_Torque_Control_Gmp2_Sf = 0U;
    *VSCtl_bCtlEfc_tqWhlPT_pt2_swc_out =DDS_FALSE;
    vssp_vsctl_bctlefc_tqwhlpt_pt2_cpy = *VSCtl_bCtlEfc_tqWhlPT_pt2_swc_out;


    vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MIN
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c2_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c2_VSSP_Torque_Control_Gmp2_Sf = 0U;
    VSCtl_bAcvFil_tqWhlPTPotMin =DDS_FALSE;



    vssp_torque_control_gmp2_sf_dwork.is_MODE_COMMANDE_POTENTIEL_COUPLE_ROUE_GMP_MAX
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c3_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c3_VSSP_Torque_Control_Gmp2_Sf = 0U;
    VSCtl_bAcvFil_tqWhlPTPotMax =DDS_FALSE;



    vssp_torque_control_gmp2_sf_dwork.is_DEMANDE_PILOTAGE_POTENTIEL_COUPLE_ROUE_GMP
      = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_MARCHE = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c4_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c4_VSSP_Torque_Control_Gmp2_Sf = 0U;



    vssp_torque_control_gmp2_sf_dwork.is_MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_GMP =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c5_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c5_VSSP_Torque_Control_Gmp2_Sf = 0U;
    VSCtl_bAcvFil_tqWhlPTPot =DDS_FALSE;

    vssp_torque_control_gmp2_sf_dwork.is_VSSP_enable_F721 = 0U;
    vssp_torque_control_gmp2_sf_dwork.is_active_c1_VSSP_Torque_Control_Gmp2_Sf =
      0U;
    vssp_torque_control_gmp2_sf_dwork.is_c1_VSSP_Torque_Control_Gmp2_Sf = 0U;
  vsctl_bacvf721 =DDS_FALSE;




}

/* \AUT_POST_TAG FUNCTIONS */

#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

