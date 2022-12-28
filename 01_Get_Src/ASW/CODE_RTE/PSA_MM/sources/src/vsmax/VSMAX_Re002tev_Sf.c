/*
* File: VSMAX_Re002tev_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSMAX_Re002tev_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Fri Jan 06 16:25:38 2012
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Fri Jan 06 16:25:42 2012
*
* Post treatment done by tool Aut_Autocode_Post.pl version 11.78
*        with rules Aut_Rules_For_Autocode_Post.pm version 12.10
*        with stack reduction algorithm Aut_Stack_Analyzer.pm version 4.00
*
* Code generated from spec : R6512345_10_0
*
* LABEL USED: LIBRARY_R6510684_17_0_0
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
*
* Autocode Optimization options used by user mzjm1k:
*        AUTOCODE_OPTIMIZATION_NO_SNAPSHOT: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_BYPASS_ERROR_LST: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_FORCE_SNAPSHOT: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_SNAPSHOT_INTERRUPT_MODE: OPTION_NOT_USED
*        AUTOCODE_OPTIMIZATION_NO_RANGE_LIMITATION: OPTION_NOT_USED
*
* Libraries versions:
*        aut_ems_lib version 17.0
*
* Common dll version 3.0
*
* Blocks versions:
*        AUT_EC_Function_Stub_v1 SFunction version: 6.0, TLC version: 1.0
*        AUT_EC_m_min_opt SFunction version: 3.0, TLC version: 3.0
*        AUT_EC_m_limit_opt SFunction version: 4.0, TLC version: 12.2
*        AUT_EC_Keep_Global_Data_From_Input SFunction version: 8.0, TLC version: 12.2
*
* Scripts versions:
*        aut_add_io version 3.0                                        aut_array_size_list_manager version 1.0
*        aut_assign_const_parameter_to_table_init version 4.2          aut_autocode_optimization version 9.0
*        aut_calc_block_before_limiter version 8.0                     aut_cast_block_before_limiter version 4.0
*        aut_check_accuracy_loss version 5.0                           aut_check_blocks_fields_values version 3.0
*        aut_check_calc_blocks version 43.0                            aut_check_downcast version 5.0
*        aut_check_if_data_exists_into_workps version 4.0              aut_check_if_data_if_an_nvv_data_store version 3.0
*        aut_check_if_data_is_in_full_range version 2.0                aut_check_if_data_is_shared version 3.0
*        aut_check_if_globlal_T55_exist version 3.0                    aut_check_if_parameter_present_into_model version 3.0
*        aut_check_if_previous_block_equal_to_type version 4.0         aut_check_if_range_is_compatible_with_datatype version 5.0
*        aut_check_model_vs_workspace version 5.0                      aut_check_pointer_access version 3.0
*        aut_chk_lcs version 3.0                                       aut_create_alias_type version 3.0
*        aut_create_data version 25.1                                  aut_create_enum version 11.0
*        aut_create_hyperlink_command_from_block version 3.0           aut_create_intermediate_constants version 4.0
*        aut_create_sstg_architecture version 10.0                     aut_cross_check_T55_mdl_init version 4.0
*        aut_ec_maskinitialization_common_function version 2.0         aut_ec_sp_aut_unit_delay_memory_effect_callback version 1.0
*        aut_find_source_block_path version 6.0                        aut_fixed_point_toolbox_interface version 4.0
*        aut_format_cpv_initialization_line version 10.0               aut_free_up_unexpected_block version 4.0
*        aut_get_array_apv_according_calibration_mode version 5.0      aut_get_data_list_from_link_output_block version 3.0
*        aut_get_data_size version 3.0                                 aut_get_deeper_block_from_list version 3.0
*        aut_get_evaluated_value_from_constant version 4.0             aut_get_final_datatype version 3.0
*        aut_get_information_from_next_block version 16.0              aut_get_information_from_previous_block version 31.0
*        aut_get_key version 3.0                                       aut_get_sigtype_info version 3.0
*        aut_get_snapshot_under_critical_lst_tag version 1.0           aut_get_squeduling_list version 16.0
*        aut_get_src_handle_from_previous_block_and_port_index version 3.0aut_get_static_data_list version 4.0
*        aut_init_value_check version 4.0                              aut_key_alg version 3.0
*        aut_manage_autocode_model version 15.0                        aut_manage_compilation_mode version 4.0
*        aut_manage_doc_block version 7.0                              aut_manage_limiter version 11.0
*        aut_manage_model_workspace version 3.0                        aut_manage_simulink_to_post_task_exchange version 54.0
*        aut_manage_snapshot version 26.0                              aut_mode_switch version 69.0
*        aut_model_autocode version 25.0                               aut_model_configure version 7.0
*        aut_pre_autocode version 56.0                                 aut_prepare_t55_task version 28.0
*        aut_prepare_t55_task_for_tag version 9.0                      aut_process_mngt version 58.0
*        aut_project_settings version 22.0                             aut_signal_config version 13.0
*        aut_sstg_manage_signal_memory_location version 6.0            aut_stateflow_checks version 6.0
*        aut_step_ckecks version 4.0                                   aut_switch_cpv_initialization version 13.0
*        aut_tlc_check_if_min_requested_instead_of_limit version 3.0   aut_tlc_get_block_init_string version 8.0
*        aut_tlc_static_variable_name_calculation version 6.0          aut_types version 3.0
*        aut_unset_set_block_properties_of_subsytem version 8.0        aut_update_init_file_with_tag version 4.0
*        sim_attributes_format_string version 4.0                      sim_check_unlinked_blocks version 11.0
*        sim_configure_simulation_mode version 9.0                     sim_display_dd_settings version 5.0
*        sim_format_hyperlink_message version 7.0                      sim_function_stub version 3.0
*        sim_get_autorisation_for_limitation version 1.0               sim_get_library_references version 48.0
*        sim_get_library_version version 3.0                           sim_get_static_data_block version 3.0
*        sim_load_libraries version 3.0                                sim_manage_block_tab version 6.0
*        sim_manage_config_set version 4.0                             sim_manage_link_status_warning version 3.0
*        sim_manage_structure_dd_display version 2.0                   sim_manage_structure_signals version 5.0
*        sim_maskinitialization_common_function version 4.0            sim_prepare_limitation version 60.0
*        sim_restore_previous_tag_version version 3.0                  sim_set version 1.0
*        sim_set_ic version 1.0                                        sim_set_param version 3.0
*        sim_sf_get_param version 7.0                                  sim_switch_block_mode version 5.0
*        sim_unit_delay_callback version 2.0                           sim_update_block_display_status version 20.0
*        sim_warning_control version 5.0
*
* Config Spec:
*        element * CHECKEDOUT
*        element clearcase\... \main\LATEST
*        element livraison\... \main\LATEST
*        element tests\... \main\LATEST
*        element Appli\ /main/LATEST
*        element \DDS_E_Documents_Vob\...  /main/LATEST
*        element * LABEL_SSTG_AUTOCODING
*        element * LIBRARY_R6510684_17_0_0
*        element * ModelPrepare_V3_1_1
*        element Environnement\ \main\LATEST
*        element Environnement\Autosar\ \main\LATEST
*        element Environnement\exe\ \main\LATEST
*        element \ldcr_tools\... GEN_RTE_VERSION_3_1_2_A
*        element /ldcr_tools/... SWC_ARXML_EURO6_CDC_1_9
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
*        element \ldcr_tools\... SWC_AUTOCODING_PREPARE_0_10
*        element \ldcr_tools\... SWC_AUTOCODING_STATEFLOW_COMPARE_1_00
*        element \ldcr_tools\... SWC_CHECK_CALIBRATION_2_10
*        element \ldcr_tools\... SWC_CODE_CHECKER_EURO6_1_14
*        element \ldcr_tools\... SWC_DELIVERY_CHECKER_EURO6_1_01
*        element \ldcr_tools\... SWC_INCA_CSV_GENERATOR_0_20
*        element \ldcr_tools\... SWC_LAB_GENERATOR_1_01
*        element \ldcr_tools\... SWC_MAIN_CODE_GENERATOR_EURO6_1_01
*        element \ldcr_tools\... SWC_PREPA_VALID_4_1_0_227
*        element \ldcr_tools\... SWC_SCENARIO_INIT_BYPASS_GENERATOR_1_02
*        element \ldcr_tools\... SWC_STIL_TO_IO_LIST_GENERATOR_EURO6_0_11
*        element \ldcr_tools\... SWC_STUB_GENERATOR_EURO6_1_01
*        element \ldcr_tools\... SWC_TASK_CODE_GENERATOR_EURO6_0_11
*        element \ldcr_tools\... SWC_VALID_CHECK_SCENARIO_1_2
*        element \ldcr_tools\... SWC_VALID_GEN_REPORT_1_5
*        element arxml_swc_generator\... ARXML_SWC_GENERATOR_1_02
*        element asap2.pl \main\L01_01\9
*        element \ldcr_tools\... SWC_ARXML_INTEGRATION_CHECKER_EURO6_1_00
*        element swc_stix_arxml_checker\... SWC_STIX_ARXML_CHECKER_1_32
*        element \ldcr_tools\... /main/LATEST
*        element * 00PSASWC_L10AD01
*        element Appli\VSReg\ /main/LATEST
*        element Appli\VSReg\src\ /main/LATEST
*        element * LABEL_DEMEZIL_VSREG_VIEW
*        element * 00PSASWC_D310D02
*        element * 00PSAATS_B310D02
*        element -directory \blois_esoft\... \main\LATEST
*        element \blois_esoft\... \main\main_tcb\LATEST
*        element \ldcr_doc\... /main/LATEST
*        element doc\... \main\LATEST
*        element Doc\... \main\LATEST
*
* Block list with autocode bypass option activated:
*        No bypassed blocks into this model
*
* Ref X:\integration_view_00PSASWC_D620D02\blois_psa_sstg\Software\Appli\VSMax\src\VSMAX_Re002tev_Sf.c
* Version int :/main/L03_01/2 Date: 9/1/2012 10 h 1 m User:meme 
*    TWK_model:VSMAX_Re002tev_Sf_L03_010_IMPL1
*    comments :for VSMax 12.0
* Version dev :\main\branch_demezil_vsmax_view\2 Date: 6/1/2012 16 h 49 m User:demezil 
*    TWK_model:VSMAX_Re002tev_Sf_L03_010_IMPL1
*    comments :for VSMax 12.0
* Version dev :\main\branch_demezil_vsmax_view\1 Date: 6/1/2012 16 h 47 m User:demezil 
*    TWK_model:VSMAX_Re002tev_Sf_L03_010_IMPL1
*    comments :for VSMax 12.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_BVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_BVV ;Afts_bRst_stDeacVSMaxReq1;Afts_bRst_stDeacVSMaxReq2;VSCtl_bEnaDeacVSMaxReq_no2;VSCtl_stVSMaxExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_BVV ;VSCtl_bRec_stDeacVSMaxReq;VSCtl_stRec_stDeacVSMaxReq1;VSCtl_stRec_stDeacVSMaxReq2;VSCtl_stVSMaxPrev;VSCtl_tiHld_stDeacVSMaxReq1;VSCtl_tiHld_stDeacVSMaxReq2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_BVV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction ;ECU_bAuthVSCtlIni;Ext_bVSMaxfCf;Ext_bVSMaxpCf;Ext_bVSMaxsCf;VSCtl_stVSCtlInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction ;VSCtl_bCfVSMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVc */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVc ;FRM_bDeacRvVSMaxc;VSCtl_spdVehReqVSMaxc;VSCtl_stDVSRegExtd;VSCtl_stMonVSMax;VSCtl_stVSLimExtd;VSCtl_stVSRegExtd;Veh_spdVeh; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVc ;VSCtl_bAcvVSMaxc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVc */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVf */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVf ;Ext_bVSMaxfCf;FRM_bDeacRvVSMaxf;VSCtl_spdVehReqVSMaxf;VSCtl_stMonVSMax;Veh_spdVeh; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVf ;VSCtl_bAcvVSMaxf; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVf */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVp */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVp ;Ext_bVSMaxpCf;FRM_bDeacRvVSMaxp;VSCtl_spdVehReqVSMaxp;VSCtl_stMonVSMax;Veh_spdVeh; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVp ;VSCtl_bAcvVSMaxp; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVp */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVs */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVs ;Ext_bVSMaxsCf;FRM_bDeacRvVSMaxs;VSCtl_spdVehReqVSMaxs;VSCtl_stMonVSMax;Veh_spdVeh; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVs ;VSCtl_bAcvVSMaxs; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Activation_BVVs */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Inhibition */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Inhibition ;FRM_bInhVSMax;VSCtl_bInhVSMaxReq_Brk;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Inhibition ;VSCtl_bInhVSMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Inhibition */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP ;VSCtl_bTyreWarnVSMax;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP ;VSCtl_bInhVSMaxReq_Brk; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Determiner_Mode_Commande_Consigne_BVVc */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Determiner_Mode_Commande_Consigne_BVVc ;Ext_stGBxCf;VSCtl_aVehPTPotMaxCtla_no1;VSCtl_spdVeh;VSCtl_spdVehCrit;VSCtl_spdVehReqVSMaxc;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Determiner_Mode_Commande_Consigne_BVVc ;VSCtl_stSpdVehCritFilModClc;VSCtl_stSpdVehCritModClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Determiner_Mode_Commande_Consigne_BVVc */

/* TAG_START_OF_STATEFLOW_FUNCTION: Diagnostic_BVVp */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Diagnostic_BVVp ;Ext_spdVehVSMaxPrmaReq;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Diagnostic_BVVp ;VSCtl_bDeacVSMaxp;VSCtl_bDgoVSMaxp;VSCtl_bMonRunVSMaxp;VSCtl_spdVehVSMaxPrmaReqPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Diagnostic_BVVp */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Fonctionnement */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Fonctionnement ;VSCtl_bAcvVSMaxc;VSCtl_bAcvVSMaxf;VSCtl_bAcvVSMaxp;VSCtl_bAcvVSMaxs;VSCtl_bDrvOvrdVSMax_aVeh;VSCtl_bInhVSMax;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Fonctionnement ;VSCtl_stVSMaxExtd; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Fonctionnement */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Service_BVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Service_BVV ;ECU_bAuthVSCtlIni;Ext_bKeyOff;Ext_bVSMaxfCf;Ext_bVSMaxpCf;Ext_bVSMaxsCf;FRM_bDeacIrvVSMax;FRM_bDeacRvVSMax;VSCtl_stVSCtlInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Service_BVV ;VSCtl_bDgoVSMax;VSCtl_bMonRunVSMax;VSCtl_bctDefRevVSMax;VSCtl_ctDftRevVSMax;VSCtl_stMonVSMax;VSCtl_tiDftRvVSMax;VSCtl_tiIniVSMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Service_BVV */

/* TAG_START_OF_SUB_FUNCTION: F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite */
/* TAG_INPUT_OF_SUB_FUNCTION: F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite ;Ext_bKeyOff;FRM_bDeacIrvVSMax;FRM_bDeacRvVSMax;VSCtl_bCfVSMax;VSCtl_bctDefRevVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite ;VSCtl_stDeacVSMaxReq_Ini; */
/* TAG_END_OF_SUB_FUNCTION: F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite */

/* TAG_START_OF_SUB_FUNCTION: F51211_Determiner_Condition_Alerte_Pneumatiques */
/* TAG_INPUT_OF_SUB_FUNCTION: F51211_Determiner_Condition_Alerte_Pneumatiques ;Ext_bTyreWarn;Ext_bTyreWarnCf;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F51211_Determiner_Condition_Alerte_Pneumatiques ;VSCtl_bTyreWarnVSMax; */
/* TAG_END_OF_SUB_FUNCTION: F51211_Determiner_Condition_Alerte_Pneumatiques */

/* TAG_START_OF_SUB_FUNCTION: F51212_Determiner_Conditions_Maintenance_Frein_LAS */
/* TAG_INPUT_OF_SUB_FUNCTION: F51212_Determiner_Conditions_Maintenance_Frein_LAS ;VSCtl_bTyreWarnVSMax;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F51212_Determiner_Conditions_Maintenance_Frein_LAS ;VSCtl_stDeacVSMaxReq_Brk; */
/* TAG_END_OF_SUB_FUNCTION: F51212_Determiner_Conditions_Maintenance_Frein_LAS */

/* TAG_START_OF_SUB_FUNCTION: F51223_Determiner_Condition_Conditions_Maintenance_Fonction */
/* TAG_INPUT_OF_SUB_FUNCTION: F51223_Determiner_Condition_Conditions_Maintenance_Fonction ;FRM_bInhVSMax;VSCtl_stMonVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F51223_Determiner_Condition_Conditions_Maintenance_Fonction ;VSCtl_stDeacVSMaxReq_Fct; */
/* TAG_END_OF_SUB_FUNCTION: F51223_Determiner_Condition_Conditions_Maintenance_Fonction */

/* TAG_START_OF_SUB_FUNCTION: F5151_Determiner_Conditions_Maintenance_BVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F5151_Determiner_Conditions_Maintenance_BVV ;VSCtl_bDeacVSMaxp;VSCtl_bRec_stDeacVSMaxReq;VSCtl_stDeacVSCtlInfo;VSCtl_stDeacVSMaxReq_Brk;VSCtl_stDeacVSMaxReq_Fct;VSCtl_stDeacVSMaxReq_Ini; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5151_Determiner_Conditions_Maintenance_BVV ;VSCtl_bEnaDeacVSMaxReq_no2;VSCtl_stDeacVSMaxReq_no1;VSCtl_stDeacVSMaxReq_no2; */
/* TAG_END_OF_SUB_FUNCTION: F5151_Determiner_Conditions_Maintenance_BVV */

/* TAG_START_OF_SUB_FUNCTION: F5153_Determiner_Contexte_Maintenance_BVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F5153_Determiner_Contexte_Maintenance_BVV ;AccP_rAccP;CoPt_noEgdGearCordIt;CoPt_posnLev;Ext_dstVehTotMes;VSCtl_aVeh;VSCtl_aVehVSMaxReq;VSCtl_bRec_stDeacVSMaxReq;VSCtl_jrkVeh;VSCtl_jrkVehVSMaxReq;VSCtl_rSlop;VSCtl_spdVeh;VSCtl_spdVehVSMaxReq;VSCtl_stVSMaxExtd; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5153_Determiner_Contexte_Maintenance_BVV ;VSCtl_aVehVSMaxReq_DeacVSMax;VSCtl_aVeh_DeacVSMax;VSCtl_dstVehTotMes_DeacVSMax;VSCtl_jrkVehReqDeacVSMax;VSCtl_jrkVeh_DeacVSMax;VSCtl_noGearEgd_DeacVSMax;VSCtl_posnGBxDeacVSMax;VSCtl_rAccP_DeacVSMax;VSCtl_rSlop_DeacVSMax;VSCtl_spdVehReqDeacVSMax;VSCtl_spdVeh_DeacVSMax;VSCtl_stVSMaxPrev_DeacVSMax;VSCtl_stVSMax_DeacVSMax; */
/* TAG_END_OF_SUB_FUNCTION: F5153_Determiner_Contexte_Maintenance_BVV */

/* TAG_START_OF_SUB_FUNCTION: F5211_Determiner_Consigne_Vitesse_BVVf */
/* TAG_INPUT_OF_SUB_FUNCTION: F5211_Determiner_Consigne_Vitesse_BVVf ;Ext_bVSMaxfCf;FRM_bDeacRvVSMaxf; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5211_Determiner_Consigne_Vitesse_BVVf ;VSCtl_spdVehReqVSMaxf; */
/* TAG_END_OF_SUB_FUNCTION: F5211_Determiner_Consigne_Vitesse_BVVf */

/* TAG_START_OF_SUB_FUNCTION: F5212_Determiner_Consigne_Vitesse_BVVp */
/* TAG_INPUT_OF_SUB_FUNCTION: F5212_Determiner_Consigne_Vitesse_BVVp ;Ext_bVSMaxpCf;Ext_spdVehVSMaxPrmaReq;FRM_bDeacRvVSMaxp; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5212_Determiner_Consigne_Vitesse_BVVp ;VSCtl_spdVehReqVSMaxp; */
/* TAG_END_OF_SUB_FUNCTION: F5212_Determiner_Consigne_Vitesse_BVVp */

/* TAG_START_OF_SUB_FUNCTION: F5213_Determiner_Consigne_Vitesse_BVVs */
/* TAG_INPUT_OF_SUB_FUNCTION: F5213_Determiner_Consigne_Vitesse_BVVs ;Ext_bVSMaxsCf;FRM_bAcvVSMax_no1;FRM_bAcvVSMax_no2; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5213_Determiner_Consigne_Vitesse_BVVs ;VSCtl_spdVehReqVSMaxs; */
/* TAG_END_OF_SUB_FUNCTION: F5213_Determiner_Consigne_Vitesse_BVVs */

/* TAG_START_OF_SUB_FUNCTION: F52142_Determiner_Consigne_Vitesse_BVVc */
/* TAG_INPUT_OF_SUB_FUNCTION: F52142_Determiner_Consigne_Vitesse_BVVc ;VSCtl_spdVeh;VSCtl_stSpdVehCritFilModClc;VSCtl_stSpdVehCritModClc;VehEst_spdVehCrit; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F52142_Determiner_Consigne_Vitesse_BVVc ;VSCtl_spdVehCrit;VSCtl_spdVehReqVSMaxc; */
/* TAG_END_OF_SUB_FUNCTION: F52142_Determiner_Consigne_Vitesse_BVVc */

/* TAG_START_OF_SUB_FUNCTION: F5215_Determiner_Consigne_Vitesse_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F5215_Determiner_Consigne_Vitesse_Vehicule ;VSCtl_bAcvVSMaxc;VSCtl_bAcvVSMaxf;VSCtl_bAcvVSMaxp;VSCtl_bAcvVSMaxs;VSCtl_spdVeh;VSCtl_spdVehReqVSMaxc;VSCtl_spdVehReqVSMaxf;VSCtl_spdVehReqVSMaxp;VSCtl_spdVehReqVSMaxs;VSCtl_stVSMaxExtd; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5215_Determiner_Consigne_Vitesse_Vehicule ;VSCtl_spdVehErrVSMax;VSCtl_spdVehVSMaxReq;VSCtl_spdVehVSMaxReqInt; */
/* TAG_END_OF_SUB_FUNCTION: F5215_Determiner_Consigne_Vitesse_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F522221_Determiner_Saturations_Acceleration_Vehicule_Max */
/* TAG_INPUT_OF_SUB_FUNCTION: F522221_Determiner_Saturations_Acceleration_Vehicule_Max ;VSCtl_aVehPTMax;VSCtl_spdVehErrVSMax;VSCtl_spdVehVSMaxReqInt;VSCtl_stCtl_aVehVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F522221_Determiner_Saturations_Acceleration_Vehicule_Max ;VSCtl_aVehVSMaxReqSatMax;VSCtl_aVehVSMaxReqSatMaxAbs;VSCtl_aVehVSMaxReqSatMaxCft; */
/* TAG_END_OF_SUB_FUNCTION: F522221_Determiner_Saturations_Acceleration_Vehicule_Max */

/* TAG_START_OF_SUB_FUNCTION: F522222_Determiner_Saturations_Acceleration_Vehicule_Min */
/* TAG_INPUT_OF_SUB_FUNCTION: F522222_Determiner_Saturations_Acceleration_Vehicule_Min ;VSCtl_aVehPTMin;VSCtl_spdVehErrVSMax;VSCtl_spdVehVSMaxReqInt;VSCtl_stCtl_aVehVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F522222_Determiner_Saturations_Acceleration_Vehicule_Min ;VSCtl_aVehVSMaxReqSatMin;VSCtl_aVehVSMaxReqSatMinAbs;VSCtl_aVehVSMaxReqSatMinCft; */
/* TAG_END_OF_SUB_FUNCTION: F522222_Determiner_Saturations_Acceleration_Vehicule_Min */

/* TAG_START_OF_SUB_FUNCTION: F52223_Determiner_Saturations_Jerk_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F52223_Determiner_Saturations_Jerk_Vehicule ;VSCtl_aVehCordVSLimReq;VSCtl_aVehReq;VSCtl_aVehVSMaxReqSatMax;VSCtl_aVehVSMaxReqSatMin;VSCtl_rTqWhlPTDrvReq;VSCtl_spdVeh;VSCtl_stCtl_aVehVSMax;VSCtl_tiFilStCtlAVehVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F52223_Determiner_Saturations_Jerk_Vehicule ;VSCtl_jrkVehVSMaxSatMax;VSCtl_jrkVehVSMaxSatMax1Tran;VSCtl_jrkVehVSMaxSatMaxAbs;VSCtl_jrkVehVSMaxSatMaxCrit;VSCtl_jrkVehVSMaxSatMaxCvg;VSCtl_jrkVehVSMaxSatMin;VSCtl_jrkVehVSMaxSatMinAbs;VSCtl_jrkVehVSMaxSatMinCvg; */
/* TAG_END_OF_SUB_FUNCTION: F52223_Determiner_Saturations_Jerk_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F52224_Determiner_Gabarits_Acceleration_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F52224_Determiner_Gabarits_Acceleration_Vehicule ;VSCtl_aVehPTMax;VSCtl_aVehPTMin;VSCtl_aVehReq;VSCtl_aVehVSMaxReqSatMax;VSCtl_aVehVSMaxReqSatMin;VSCtl_jrkVehVSMaxSatMax;VSCtl_jrkVehVSMaxSatMin;VSCtl_stCtl_aVehVSMax;VSCtl_stSatAVehMinVSMax;VSCtl_stSatJrkVehMaxVSMax;VSCtl_stSatJrkVehMinVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F52224_Determiner_Gabarits_Acceleration_Vehicule ;VSCtl_aVehVSMaxReqMax;VSCtl_aVehVSMaxReqMin;VSCtl_aVehVSMaxReqSatMaxApl;VSCtl_aVehVSMaxReqSatMinApl; */
/* TAG_END_OF_SUB_FUNCTION: F52224_Determiner_Gabarits_Acceleration_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F52232_Determiner_Consigne_Acceleration_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F52232_Determiner_Consigne_Acceleration_Vehicule ;VSCtl_aVehPTMax;VSCtl_aVehVSMaxReqMax;VSCtl_aVehVSMaxReqMin;VSCtl_bAcvFil_aVehVSMax;VSCtl_rSpdVehCtlVSMaxDyn;VSCtl_spdVehErrVSMax;VSCtl_stCtl_aVehVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F52232_Determiner_Consigne_Acceleration_Vehicule ;VSCtl_aVehVSMaxReq;VSCtl_aVehVSMaxReqRaw;VSCtl_jrkVehVSMaxReq;VSCtl_spdCtlGain1VSMaxAVeh; */
/* TAG_END_OF_SUB_FUNCTION: F52232_Determiner_Consigne_Acceleration_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule ;VSCtl_aVehVSMaxReqSatMax;VSCtl_aVehVSMaxReqSatMin;VSCtl_bAcvFil_aVehPotVSMax;VSCtl_bCtl_aVehPotVSMax;VSCtl_spdVehErrVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule ;VSCtl_aVehPotVSMaxReq;VSCtl_jrkVehPotVSMaxReq; */
/* TAG_END_OF_SUB_FUNCTION: F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP ;VSCtl_bCtl_aVehPotVSMax;VSCtl_spdVehErrVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP ;VSCtl_rCtlTqWhlPTPotVSMax; */
/* TAG_END_OF_SUB_FUNCTION: F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP */

/* TAG_START_OF_SUB_FUNCTION: F5234_Determiner_Temps_Confirmation_Changement_Rapport */
/* TAG_INPUT_OF_SUB_FUNCTION: F5234_Determiner_Temps_Confirmation_Changement_Rapport ;VSCtl_aVehPotVSMaxReq;VSCtl_bAcvFil_aVehPotVSMax;VSCtl_bCtl_aVehPotVSMax;VSCtl_jrkVehPotVSMaxReq;VSCtl_spdVeh;VSCtl_spdVehErrVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F5234_Determiner_Temps_Confirmation_Changement_Rapport ;VSCtl_tiCfmSdwnVSMaxReq;VSCtl_tiCfmSdwnVSMaxReqRaw1;VSCtl_tiCfmSdwnVSMaxReqRaw2;VSCtl_tiCfmSdwnVSMaxReqRaw3;VSCtl_tiCfmSupVSMaxReq;VSCtl_tiCfmSupVSMaxReqRaw1;VSCtl_tiCfmSupVSMaxReqRaw2;VSCtl_tiCfmSupVSMaxReqRaw3; */
/* TAG_END_OF_SUB_FUNCTION: F5234_Determiner_Temps_Confirmation_Changement_Rapport */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule ;VSCtl_aVehReq;VSCtl_aVehVSMaxReqSatMax;VSCtl_aVehVSMaxReqSatMin;VSCtl_stCtl_aVehVSMax;VSCtl_stVSMaxExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule ;VSCtl_stSatAVehMinVSMax;VSCtl_stSatJrkVehMaxVSMax;VSCtl_stSatJrkVehMinVSMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration_Vehicule ;VSCtl_bEndTranVSMax;VSCtl_stVSCtlInfo;VSCtl_stVSMaxExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration_Vehicule ;VSCtl_bAcvFil_aVehVSMax;VSCtl_stCtl_aVehVSMax;VSCtl_tiFilStCtlAVehVSMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule ;Ext_stCtlCmdPTTqPotCf; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule ;vsctl_bacv_calcul; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Controle_Vitesse_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Vitesse_Vehicule ;VSCtl_spdVehErrVSMax;VSCtl_stCtl_aVehVSMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Vitesse_Vehicule ;VSCtl_bDynCtlSpdVehVSMax;VSCtl_rSpdVehCtlVSMaxDyn;VSCtl_tiFilSpdVehCtlVSMaxDyn; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Controle_Vitesse_Vehicule */

/* END OF SSTG FUNCTION INTERFACE AREA */

/* <AUT_POST> : Task Include managment */
/********************************************************************/
/*  Include Files                                                   */
/********************************************************************/
#include "dds_lib.h"
#include "VSMax.h"
/* \<AUT_POST> : Task Include managment */

/********************************************************************/
/*  Task Macro Definitions                                          */
/********************************************************************/

/* Named constants for block: /Etat_Service_BVV' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSMAX_Re002tev_Sf_IN_ETAT_SERVICE_BVV (1)
#define VSMAX_Re002tev_Sf_IN_ARRET     (1)
#define VSMAX_Re002tev_Sf_IN_MARCHE    (3)
#define VSMAX_Re002tev_Sf_IN_DEFAUT_REVESIBLE (1)
#define VSMAX_Re002tev_Sf_IN_VERIF     (2)
#define VSMAX_Re002tev_Sf_IN_PAS_DEFAUT (2)
#define VSMAX_Re002tev_Sf_IN_INIT      (1)
#define VSMAX_Re002tev_Sf_IN_NOMINAL   (2)
#define VSMAX_Re002tev_Sf_IN_DEFAUT_IRREVESIBLE (2)
#define VSMAX_Re002tev_Sf_IN_NON_VERIF (1)
#define VSMAX_Re002tev_Sf_VRAI_j       (1U)
#define VSMAX_Re002tev_Sf_FAUX_o       (0U)

/* Named constants for block: /Demande_Activation_BVVf' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g (0)
#define VSMAX_Re002tev_Sf_IN_VRAI_m    (2)
#define VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVf (1)
#define VSMAX_Re002tev_Sf_IN_ARRET_n   (1)
#define VSMAX_Re002tev_Sf_IN_DEFAUT    (1)
#define VSMAX_Re002tev_Sf_IN_MARCHE_c  (2)
#define VSMAX_Re002tev_Sf_VRAI_jr      (1U)
#define VSMAX_Re002tev_Sf_FAUX_h       (0U)

/* Named constants for block: /Demande_Activation_BVVp' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_b (0)
#define VSMAX_Re002tev_Sf_IN_MARCHE_i  (2)
#define VSMAX_Re002tev_Sf_IN_DEFAUT_a  (1)
#define VSMAX_Re002tev_Sf_IN_VRAI_g    (2)
#define VSMAX_Re002tev_Sf_IN_ARRET_h   (1)
#define VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVp (1)
#define VSMAX_Re002tev_Sf_VRAI_k       (1U)
#define VSMAX_Re002tev_Sf_FAUX_b       (0U)

/* Named constants for block: /Demande_Activation_BVVs' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d (0)
#define VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVs (1)
#define VSMAX_Re002tev_Sf_IN_ARRET_j   (1)
#define VSMAX_Re002tev_Sf_IN_MARCHE_k  (2)
#define VSMAX_Re002tev_Sf_IN_VRAI_n    (2)
#define VSMAX_Re002tev_Sf_IN_DEFAUT_f  (1)
#define VSMAX_Re002tev_Sf_VRAI_a       (1U)
#define VSMAX_Re002tev_Sf_FAUX_m       (0U)

/* Named constants for block: /Demande_Activation_BVVc' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n (0)
#define VSMAX_Re002tev_Sf_IN_DEFAUT_fa (1)
#define VSMAX_Re002tev_Sf_IN_ARRET_c   (1)
#define VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVc (1)
#define VSMAX_Re002tev_Sf_IN_VRAI_j    (2)
#define VSMAX_Re002tev_Sf_IN_MARCHE_h  (2)
#define VSMAX_Re002tev_Sf_VRAI_c       (1U)
#define VSMAX_Re002tev_Sf_FAUX_e       (0U)

/* Named constants for block: /Demandes_Desactivation_Inhibition_GMP' */
#define VSMAX_Re002tev_Sf_IN_PAS_DEMANDEE (2)
#define VSMAX_Re002tev_Sf_IN_DEMANDEE  (1)
#define VSMAX_Re002tev_Sf_IN_DEMANDE_INHIBITION (1)
#define VSMAX_Re002tev_Sf_FAUX_c       (0U)
#define VSMAX_Re002tev_Sf_VRAI_b       (1U)

/* Named constants for block: /Demande_Inhibition' */
#define VSMAX_Re002tev_Sf_IN_FAUX_k    (1)
#define VSMAX_Re002tev_Sf_IN_VRAI_a    (2)
#define VSMAX_Re002tev_Sf_IN_DEMANDE_INHIBITION_f (1)
#define VSMAX_Re002tev_Sf_VRAI_g       (1U)
#define VSMAX_Re002tev_Sf_FAUX_ho      (0U)

/* Named constants for block: /Etat_Fonctionnement' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l (0)
#define VSMAX_Re002tev_Sf_IN_ACTIVE_EFFECTIVE (1)
#define VSMAX_Re002tev_Sf_IN_INHIBEE   (2)
#define VSMAX_Re002tev_Sf_IN_ATTENTE   (2)
#define VSMAX_Re002tev_Sf_IN_ACTIVE_NON_EFFECTIVE (2)
#define VSMAX_Re002tev_Sf_IN_DEFAUT_b  (1)
#define VSMAX_Re002tev_Sf_IN_ACTIVATION_DEMANDEE (1)
#define VSMAX_Re002tev_Sf_IN_DISPONIBLE (1)
#define VSMAX_Re002tev_Sf_IN_ETAT_FONCTIONNEMENT (1)
#define VSMAX_Re002tev_Sf_IN_INDISPONIBLE (2)
#define VSMAX_Re002tev_Sf_IN_FONCTION_PRESENTE (2)
#define VSMAX_Re002tev_Sf_IN_INITIALISATION (3)
#define VSMAX_Re002tev_Sf_IN_ARRET_e   (1)
#define VSMAX_Re002tev_Sf_VRAI_h       (1U)
#define VSMAX_Re002tev_Sf_FAUX_p       (0U)

/* Named constants for block: /Determiner_Mode_Commande_Consigne_BVVc' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m (0)
#define VSMAX_Re002tev_Sf_IN_ARRET_i   (1)
#define VSMAX_Re002tev_Sf_IN_CONTROL   (1)
#define VSMAX_Re002tev_Sf_IN_EFFECTIF  (1)
#define VSMAX_Re002tev_Sf_IN_NON_EFFECTIF (2)
#define VSMAX_Re002tev_Sf_IN_MARCHE_o  (2)
#define VSMAX_Re002tev_Sf_IN_INIT_g    (2)
#define VSMAX_Re002tev_Sf_IN_BLOQUE    (1)
#define VSMAX_Re002tev_Sf_IN_MODE_COMMANDE_CONSIGNE_BVVc (1)
#define VSMAX_Re002tev_Sf_VRAI_bk      (1U)
#define VSMAX_Re002tev_Sf_FAUX_n       (0U)

/* Named constants for block: /Mode_Commande_Acceleration_Vehicule' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_md (0)
#define VSMAX_Re002tev_Sf_IN_MODE_COMMANDE_ACCELERATION_VEHICULE (1)
#define VSMAX_Re002tev_Sf_IN_TRANSITION (2)
#define VSMAX_Re002tev_Sf_IN_CONTROLE  (1)
#define VSMAX_Re002tev_Sf_IN_ARRET_g   (1)
#define VSMAX_Re002tev_Sf_IN_HORS_CONTROLE (2)
#define VSMAX_Re002tev_Sf_FAUX_mz      (0U)
#define VSMAX_Re002tev_Sf_VRAI_bv      (1U)

/* Named constants for block: /Mode_Controle_Vitesse_Vehicule' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_e (0)
#define VSMAX_Re002tev_Sf_IN_INIT_p    (1)
#define VSMAX_Re002tev_Sf_IN_NON_INIT  (2)
#define VSMAX_Re002tev_Sf_IN_BARYCENTRE_IN_1 (1)
#define VSMAX_Re002tev_Sf_IN_DECONF    (4)
#define VSMAX_Re002tev_Sf_IN_CONF      (3)
#define VSMAX_Re002tev_Sf_IN_BARYCENTRE_IN_2 (2)
#define VSMAX_Re002tev_Sf_IN_MODE_CONTROLE_VITESSE_VEHICULE (1)
#define VSMAX_Re002tev_Sf_IN_STABILISE (3)
#define VSMAX_Re002tev_Sf_IN_TRANSITOIRE (4)
#define VSMAX_Re002tev_Sf_IN_CONF____0 (1)
#define VSMAX_Re002tev_Sf_IN_DECONF____0 (2)

/* Named constants for block: /Mode_Calcul_Gabarits_Acceleration_Vehicule' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_ko (0)
#define VSMAX_Re002tev_Sf_IN_EFFECTIF_n (1)
#define VSMAX_Re002tev_Sf_IN_ARRET_p   (1)
#define VSMAX_Re002tev_Sf_IN_CONTROLE_p (2)
#define VSMAX_Re002tev_Sf_IN_NON_EFFECTIF_d (2)
#define VSMAX_Re002tev_Sf_IN_MODES_CALCUL_GABARITS_ACCELERATION_VEHICULE (1)
#define VSMAX_Re002tev_Sf_IN_NON_EFFECTIF____0 (4)
#define VSMAX_Re002tev_Sf_IN_EFFECTIF____0 (2)
#define VSMAX_Re002tev_Sf_IN_INIT_o    (3)
#define VSMAX_Re002tev_Sf_IN_ACTIVATION (1)
#define VSMAX_Re002tev_Sf_FAUX_h3      (0U)
#define VSMAX_Re002tev_Sf_VRAI_f       (1U)

/* Named constants for block: /Mode_Commande_Potentiel_Acceleration_Vehicule' */
#define VSMAX_Re002tev_Sf_IN_ENABLE_F523 (1)
#define VSMAX_Re002tev_Sf_IN_PRESENT   (2)
#define VSMAX_Re002tev_Sf_IN_ABSENT    (1)
#define VSMAX_Re002tev_Sf_VRAI_n       (1U)
#define VSMAX_Re002tev_Sf_FAUX_l       (0U)

/* Named constants for block: /Condition_Configuration_Fonction' */
#define VSMAX_Re002tev_Sf_IN_FAUX      (1)
#define VSMAX_Re002tev_Sf_IN_VRAI      (2)
#define VSMAX_Re002tev_Sf_IN_CONDITION_CONFIGURATION_FONCTION (1)
#define VSMAX_Re002tev_Sf_VRAI         (1U)
#define VSMAX_Re002tev_Sf_FAUX         (0U)

/* Named constants for block: /Diagnostic_BVVp' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_k (0)
#define VSMAX_Re002tev_Sf_IN_FAUX_b    (1)
#define VSMAX_Re002tev_Sf_IN_ARRET_k   (1)
#define VSMAX_Re002tev_Sf_IN_VRAI_i    (2)
#define VSMAX_Re002tev_Sf_IN_MARCHE_e  (2)
#define VSMAX_Re002tev_Sf_IN_DIAGNOSTIC_BVVp (1)
#define VSMAX_Re002tev_Sf_VRAI_au      (1U)
#define VSMAX_Re002tev_Sf_FAUX_j       (0U)

/* Named constants for block: /Condition_Capture_Maintenance_BVV' */
#define VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_i (0)
#define VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION (1)
#define VSMAX_Re002tev_Sf_IN_CAPTURE   (2)
#define VSMAX_Re002tev_Sf_IN_RESET     (2)
#define VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT (1)
#define VSMAX_Re002tev_Sf_IN_CONDITION_CAPTURE_MAINTENANCE_BVV (1)
#define VSMAX_Re002tev_Sf_VRAI_an      (1U)
#define VSMAX_Re002tev_Sf_FAUX_ma      (0U)

/* Named constants for block: /Mode_Commande_Potentiel_Acceleration_Vehicule' */
#define VSMAX_Re002tev_Sf_IN_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE (1)
#define VSMAX_Re002tev_Sf_IN_ARRET_d   (1)
#define VSMAX_Re002tev_Sf_IN_CONTROLE_m (2)
#define VSMAX_Re002tev_Sf_VRAI_fn      (1U)
#define VSMAX_Re002tev_Sf_FAUX_g       (0U)

/* Definition for custom storage class: Define */
#define VSCTL_RSPDVEHCTLVSMAXDYN_MAX   12800U
#define VSCTL_SPDVEHVSMAXPRMAREQPREV_MAX 32640U
#define VSMAX_RE002TEV_SF_CONST_1      32640U
#define VSMAX_RE002TEV_SF_CONST_2      (-10240)
#define VSMAX_RE002TEV_SF_CONST_3      10240

#define VSCTL_STSATAVEHMINVSMAXMOD_C_INCOMPLET (0)
#define VSCTL_STVSREGEXTD_AE    (5)
#define VSCTL_STVSLIMEXTD_AE    (5)
#define VSCTL_STDVSREGEXTD_AE   (5)
#define VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE    (0)
#define VSCTL_BDYNCTLSPDVEHVSMAX_STABILISE      (1)
#define VSCTL_STSATAVEHMINVSMAXMOD_C_COMPLET    (1)

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxs;       /*BIN7*/
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxp;       /*BIN7*/
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxf;       /*BIN7*/
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxc;       /*BIN7*/
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehCrit;       /*BIN7*/
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMin;       /*BIN10*/
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMax;       /*BIN10*/
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"


/* 8-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bTyreWarnVSMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bEnaDeacVSMaxReq_no2;
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_rSpdVehCtlVSMaxDyn;       /*BIN7*/
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"


/* 8-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_tiFilStCtlAVehVSMax;       /*BIN0*/
VAR(UInt8, AUTOMATIC) VSCtl_stVSMaxPrev;
VAR(UInt8, AUTOMATIC) VSCtl_stSpdVehCritModClc;
VAR(UInt8, AUTOMATIC) VSCtl_stSpdVehCritFilModClc;
VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMinVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMaxVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_stSatAVehMinVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_stMonVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_bctDefRevVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_bRec_stDeacVSMaxReq;
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSMaxReq_Brk;
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_bDynCtlSpdVehVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_bDeacVSMaxp;
VAR(UInt8, AUTOMATIC) VSCtl_bCfVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxs;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxp;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxf;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxc;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehPotVSMax;
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  SInt16 vsm_Keep_Global_Data_From_Input;
  UInt16 vsm_Keep_Global_Data_From_Input_p;
  UInt16 VSCtl_rSpdVehCtlVSMaxDyn_n;
  UInt16 VSCtl_spdVehVSMaxPrmaReqPrev_n;
  SInt16 vsm_Keep_Global_Data_From_Input_g;
  UInt8 vsm_Keep_Global_Data_From_Input_p2;
} BlockIO_VSMAX_Re002tev_Sf;


typedef struct {
  UInt32 is_NON_INIT : 3;
  UInt32 is_NON_INIT_n : 3;
  UInt32 is_CONTROLE : 3;
  UInt32 is_ENABLE_F523 : 2;
  UInt32 is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE : 2;
  UInt32 is_LISSAGE_CONTROLE_VITESSE : 2;
  UInt32 is_CONDITION_CHANGEMENT_DYNAMIQUE : 2;
  UInt32 is_CONTROLE_p : 2;
  UInt32 is_JERK_MIN : 2;
  UInt32 is_CONTROLE_p4 : 2;
  UInt32 is_JERK_MAX : 2;
  UInt32 is_ACCEL : 2;
  UInt32 is_MODE_COMMANDE_ACCELERATION_VEHICULE : 2;
  UInt32 is_HORS_CONTROLE : 2;
  UInt32 is_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE : 2;
  UInt32 is_CONTROL : 2;
  UInt32 is_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 : 2;
  UInt32 is_FONCTIONNEMENT : 2;
  UInt32 is_FONCTIONNEMENT_o : 2;
  UInt32 is_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 : 2;
  UInt32 is_DIAGNOSTIC : 2;
  UInt32 is_MARCHE_g : 2;
  UInt32 is_ACTIVATION_DEMANDEE : 2;
  UInt32 is_DISPONIBLE : 2;
  UInt32 is_ETAT_FONCTIONNEMENT : 2;
  UInt32 is_INDISPONIBLE : 2;
  UInt32 is_FONCTION_PRESENTE : 2;
  UInt32 is_DEMANDE_INHIBITION : 2;
  UInt32 is_DEMANDE_ACTIVATION_BVVc : 2;
  UInt32 is_MARCHE_n : 2;
  UInt32 is_DEMANDE_ACTIVATION_BVVs : 2;
  UInt32 is_MARCHE_l : 2;
  UInt32 is_MARCHE_a : 2;
  UInt32 is_DEMANDE_ACTIVATION_BVVp : 2;
  UInt32 is_DEMANDE_ACTIVATION_BVVf : 2;
  UInt32 is_MARCHE_d : 2;
  UInt32 is_DEMANDE_INHIBITION_b : 2;
  UInt32 is_ETAT_SERVICE_BVV : 2;
  UInt32 is_MARCHE_j : 2;
  UInt32 is_PAS_DEFAUT : 2;
  UInt32 is_NON_VERIF : 2;
  UInt32 is_CONDITION_CONFIGURATION_FONCTION : 2;
  UInt32 is_active_c1_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c1_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c63_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c63_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c217_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c217_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_LISSAGE_CONTROLE_VITESSE : 1;
  UInt32 is_active_CONDITION_CHANGEMENT_DYNAMIQUE : 1;
  UInt32 is_active_c216_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c216_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_JERK_MIN : 1;
  UInt32 is_active_JERK_MAX : 1;
  UInt32 is_active_ACCEL : 1;
  UInt32 is_active_c215_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c215_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c95_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c95_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE : 1;
  UInt32 is_MARCHE_k : 1;
  UInt32 is_active_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE : 1;
  UInt32 is_active_c44_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c44_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 : 1;
  UInt32 is_active_MEMOIRES : 1;
  UInt32 is_active_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 : 1;
  UInt32 is_active_CONDITION_CAPTURE_MAINTENANCE_BVV : 1;
  UInt32 is_active_c184_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c184_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_DIAGNOSTIC : 1;
  UInt32 is_active_MEMOIRE : 1;
  UInt32 is_active_c214_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c214_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c213_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c213_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c43_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c43_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c42_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c42_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c40_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c40_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c211_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c211_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c39_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c39_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c37_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c37_VSMAX_Re002tev_Sf : 1;
  UInt32 is_active_c33_VSMAX_Re002tev_Sf : 1;
  UInt32 is_c33_VSMAX_Re002tev_Sf : 1;
} D_Work_VSMAX_Re002tev_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
/* <PRQA_COMMENT><3229> this variable must be viewable according to the spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSMaxPrmaReqPrev;           /*BIN7*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSMaxReq1;            /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSMaxReq2;            /*BIN0*/
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"


/* 8-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_ctDftRevVSMax;                     /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiDftRvVSMax;                      /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilSpdVehCtlVSMaxDyn;            /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiIniVSMax;                        /*BIN0*/
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 32BIT-bits variable definition */
#define VSMAX_START_SEC_VAR_32BIT
#include "VSMax_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsmax_vsctl_dstvehtotmes_deacvsmax_cpy;                  /*BIN0*/
#define VSMAX_STOP_SEC_VAR_32BIT
#include "VSMax_MemMap.h"


/* 16BIT-bits variable definition */
#define VSMAX_START_SEC_VAR_16BIT
#include "VSMax_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsmax_re002tev_sf_delay_10;
STATIC VAR(SInt16, AUTOMATIC) vsmax_re002tev_sf_delay_6;
STATIC VAR(SInt16, AUTOMATIC) vsmax_re002tev_sf_delay_7;
STATIC VAR(UInt16, AUTOMATIC) vsmax_re002tev_sf_delay_0;
STATIC VAR(UInt16, AUTOMATIC) vsmax_re002tev_sf_delay_1;
STATIC VAR(UInt16, AUTOMATIC) vsmax_re002tev_sf_delay_2;
STATIC VAR(UInt16, AUTOMATIC) vsmax_re002tev_sf_delay_3;
STATIC VAR(UInt16, AUTOMATIC) vsmax_re002tev_sf_delay_4;
STATIC VAR(UInt16, AUTOMATIC) vsmax_re002tev_sf_delay_5;
STATIC VAR(UInt16, AUTOMATIC) vsmax_re002tev_sf_delay_9;
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_avehpotvsmaxreq_cpy;                         /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_avehvsmaxreq_cpy;                            /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_avehvsmaxreq_deacvsmax_cpy;                  /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_aveh_deacvsmax_cpy;                          /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_jrkvehreqdeacvsmax_cpy;                      /*BIN7*/
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_jrkveh_deacvsmax_cpy;                        /*BIN7*/
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_rslop_deacvsmax_cpy;                         /*BIN7*/
STATIC VAR(SInt16, AUTOMATIC) vsmax_vsctl_spdveherrvsmax_cpy;                          /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_raccp_deacvsmax_cpy;                         /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_rctltqwhlptpotvsmax_cpy;                     /*BIN4*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_spdvehreqdeacvsmax_cpy;                      /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_spdvehvsmaxreq_cpy;                          /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_spdveh_deacvsmax_cpy;                        /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_stdeacvsmaxreq_no1_cpy;                      /*BIN0*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_stdeacvsmaxreq_no2_cpy;                      /*BIN0*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_ticfmsdwnvsmaxreq_cpy;                       /*DEC2*/
STATIC VAR(UInt16, AUTOMATIC) vsmax_vsctl_ticfmsupvsmaxreq_cpy;                        /*DEC2*/
#define VSMAX_STOP_SEC_VAR_16BIT
#include "VSMax_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSMAX_START_SEC_VAR_UNSPECIFIED
#include "VSMax_MemMap.h"
STATIC VAR(BlockIO_VSMAX_Re002tev_Sf, AUTOMATIC) vsmax_re002tev_sf_b;
STATIC VAR(D_Work_VSMAX_Re002tev_Sf, AUTOMATIC) vsmax_re002tev_sf_dwork;
#define VSMAX_STOP_SEC_VAR_UNSPECIFIED
#include "VSMax_MemMap.h"


/* 8BIT-bits variable definition */
#define VSMAX_START_SEC_VAR_8BIT
#include "VSMax_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bacv_calcul;
/* Static Not Visible area end */
STATIC VAR(SInt8, AUTOMATIC) vsmax_vsctl_nogearegd_deacvsmax_cpy;                      /*BIN0*/
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_bctl_avehpotvsmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_bdgovsmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_bdgovsmaxp_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_bmonrunvsmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_bmonrunvsmaxp_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_posngbxdeacvsmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_stctl_avehvsmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_strec_stdeacvsmaxreq1_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_strec_stdeacvsmaxreq2_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_stvsmaxextd_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_stvsmaxprev_deacvsmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsmax_vsctl_stvsmax_deacvsmax_cpy;
#define VSMAX_STOP_SEC_VAR_8BIT
#include "VSMax_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSMAX_START_SEC_CALIB_16BIT
#include "VSMax_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehPTPotMaxCtla1_HysHi_C = (CONST(SInt16, AUTOMATIC))(0); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehPTPotMaxCtla1_HysLo_C = (CONST(SInt16, AUTOMATIC))(0); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEMaxAVehP_HysHiN_C = (CONST(SInt16, AUTOMATIC))(-1920); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEMaxAVehP_HysHiP_C = (CONST(SInt16, AUTOMATIC))(3200); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEMaxAVehP_HysLoN_C = (CONST(SInt16, AUTOMATIC))(-1280); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEMaxAVehP_HysLoP_C = (CONST(SInt16, AUTOMATIC))(2560); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErrVSMaxSDyn_HysHi_C = (CONST(SInt16, AUTOMATIC))(192); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErrVSMaxSDyn_HysLo_C = (CONST(SInt16, AUTOMATIC))(128); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehCrit_HysHi_C = (CONST(SInt16, AUTOMATIC))(32);      /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehCrit_HysLo_C = (CONST(SInt16, AUTOMATIC))(32);      /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxcAcvHi_C = (CONST(SInt16, AUTOMATIC))(3200); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxcAcvLo_C = (CONST(SInt16, AUTOMATIC))(2560); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxcErr_C = (CONST(SInt16, AUTOMATIC))(-256);  /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxfAcvHi_C = (CONST(SInt16, AUTOMATIC))(3200); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxfAcvLo_C = (CONST(SInt16, AUTOMATIC))(2560); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxfErr_C = (CONST(SInt16, AUTOMATIC))(-256);  /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxpAcvHi_C = (CONST(SInt16, AUTOMATIC))(3200); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxpAcvLo_C = (CONST(SInt16, AUTOMATIC))(2560); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxpErr_C = (CONST(SInt16, AUTOMATIC))(-256);  /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxsAcvHi_C = (CONST(SInt16, AUTOMATIC))(3200); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxsAcvLo_C = (CONST(SInt16, AUTOMATIC))(2560); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErrVSMaxsErr_C = (CONST(SInt16, AUTOMATIC))(-256);  /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfm_rSDynCtlVSMax_C = (CONST(UInt16, AUTOMATIC))(512U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiDiCfm_rCtlTDynVSMax_C = (CONST(UInt16, AUTOMATIC))(128U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSMaxReq1_C = (CONST(UInt16, AUTOMATIC))(0U); /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSMaxReq2_C = (CONST(UInt16, AUTOMATIC))(0U); /*BIN0*/
#define VSMAX_STOP_SEC_CALIB_16BIT
#include "VSMax_MemMap.h"


/* 8BIT-bits variable definition */
#define VSMAX_START_SEC_CALIB_8BIT
#include "VSMax_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_ctTolRvDftVSMax_C = (CONST(UInt8, AUTOMATIC))(255U);      /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiCfm_SDynCtlChgVSMax_C = (CONST(UInt8, AUTOMATIC))(1U);  /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDftRvVSMax_C = (CONST(UInt8, AUTOMATIC))(49U);          /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDiCfmSDynCtlChgVSMax_C = (CONST(UInt8, AUTOMATIC))(50U); /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_stCtlAVehVSMax_C = (CONST(UInt8, AUTOMATIC))(74U);  /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiTol_DynCtlVSMax_C = (CONST(UInt8, AUTOMATIC))(49U);     /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiVSMaxIni_C = (CONST(UInt8, AUTOMATIC))(2U);             /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSMaxNGear_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSMaxNGear_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSMaxPed_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSMaxPed_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSMaxTq_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSMaxTq_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxc_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacCdnAStSatMinVSMax_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stSatAVehMinVSMaxMod_C = VSCTL_STSATAVEHMINVSMAXMOD_C_COMPLET;
/* \<AUT_POST> : Task Memory Ordering */
#define VSMAX_STOP_SEC_CALIB_8BIT
#include "VSMax_MemMap.h"

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

#define VSMAX_START_SEC_CODE
#include "VSMax_MemMap.h"

FUNC(void, AUTOMATIC) VSMAX_Re002tev_Sf(UInt8 Ext_spdVehVSMaxPrmaReq_swc_in,                        /*BIN0*/
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                          /*BIN0*/
                               UInt8 FRM_bDeacRvVSMax_swc_in,
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               SInt16 VSCtl_aVeh_swc_in,                                   /*BIN10*/
                               UInt8 VSCtl_stDVSRegExtd_swc_in,
                               UInt8 VSCtl_stVSLimExtd_swc_in,
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt8 FRM_bInhVSMax_swc_in,
                               UInt8 Ext_bKeyOff_swc_in,
                               UInt8 VSCtl_stDeacVSCtlInfo_swc_in,                         /*BIN0*/
                               SInt16 VSCtl_aVehPTMin_swc_in,                              /*BIN10*/
                               SInt16 VSCtl_aVehPTMax_swc_in,                              /*BIN10*/
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt16 AccP_rAccP_swc_in,                                   /*BIN7*/
                               UInt8 Ext_stGBxCf_swc_in,
                               UInt8 Afts_bRst_stDeacVSMaxReq1_swc_in,
                               UInt8 Afts_bRst_stDeacVSMaxReq2_swc_in,
                               UInt16 VSCtl_rTqWhlPTDrvReq_swc_in,                         /*BIN7*/
                               UInt8 VSCtl_bDrvOvrdVSMax_aVeh_swc_in,
                               UInt8 VSCtl_bEndTranVSMax_swc_in,
                               UInt8 VSCtl_stVSCtlInfo_swc_in,
                               SInt16 VSCtl_aVehCordVSLimReq_swc_in,                       /*BIN10*/
                               UInt8 VehEst_spdVehCrit_swc_in,                             /*BIN0*/
                               UInt16 Veh_spdVeh_swc_in,                            /*BIN7*/
                               UInt8 FRM_bDeacRvVSMaxc_swc_in,
                               UInt8 Ext_bTyreWarn_swc_in,
                               UInt8 FRM_bDeacRvVSMaxf_swc_in,
                               UInt8 Ext_bVSMaxfCf_swc_in,
                               UInt8 FRM_bDeacIrvVSMax_swc_in,
                               SInt16 VSCtl_jrkVeh_swc_in,                                 /*BIN7*/
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 Ext_bTyreWarnCf_swc_in,
                               SInt16 VSCtl_aVehReq_swc_in,                                /*BIN10*/
                               UInt8 FRM_bDeacRvVSMaxp_swc_in,
                               UInt8 Ext_bVSMaxpCf_swc_in,
                               UInt32 Ext_dstVehTotMes_swc_in,                             /*BIN0*/
                               SInt16 VSCtl_rSlop_swc_in,                                  /*BIN7*/
                               UInt8 FRM_bAcvVSMax_no1_swc_in,
                               UInt8 CoPt_posnLev_swc_in,
                               UInt8 FRM_bAcvVSMax_no2_swc_in,
                               UInt8 Ext_bVSMaxsCf_swc_in,
                               SInt16 VSCtl_aVehPTPotMaxCtla_no1_swc_in,            /*BIN10*/
                               UInt8 FRM_bDeacRvVSMaxs_swc_in,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_DeacVSMax_swc_out,                 /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no1_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no2_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMaxp_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSMax_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMaxp_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehVSMaxReq_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSMaxReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSMax_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSMax_swc_out,                 /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSMaxReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSMax_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSMax_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxPrev_DeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSMaxReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMax_DeacVSMax_swc_out)

{
  SInt16 stack_data_s16_0;
  SInt16 stack_data_s16_1;
  UInt16 stack_data_u16_0;
  UInt16 stack_data_u16_1;


  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F5112_Determiner_Etat_Service*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.34.0 */

  if (vsmax_re002tev_sf_dwork.is_active_c37_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c37_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c37_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_ETAT_SERVICE_BVV;
    vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET;
    VSCtl_stMonVSMax = VSCTL_STMONVSMAX_ARRET;
    VSCtl_ctDftRevVSMax = VSCtl_ctTolRvDftVSMax_C;
    vsmax_vsctl_bdgovsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
    vsmax_vsctl_bmonrunvsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
    VSCtl_bctDefRevVSMax = VSMAX_Re002tev_Sf_FAUX_o;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV) {
     case VSMAX_Re002tev_Sf_IN_ARRET:
      if ((((((((Ext_bVSMaxfCf_swc_in == EXT_BVSMAXFCF_PRESENT)
      || (Ext_bVSMaxpCf_swc_in ==
                 EXT_BVSMAXPCF_PRESENT)) || (Ext_bVSMaxsCf_swc_in ==
                EXT_BVSMAXSCF_PRESENT)) || (VSCtl_bAcvVSMaxc_C ==
               VSMAX_Re002tev_Sf_VRAI_j)) && (Ext_bKeyOff_swc_in ==
              VSMAX_Re002tev_Sf_FAUX_o)) && (VSCtl_stVSCtlInfo_swc_in !=
             VSCTL_STVSCTLINFO_ARRET)) && (VSCtl_stVSCtlInfo_swc_in !=
            VSCTL_STVSCTLINFO_VERIF)) && (VSCtl_stVSCtlInfo_swc_in !=
           VSCTL_STVSCTLINFO_INIT))
      {
        vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE;
        vsmax_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
          VSMAX_Re002tev_Sf_IN_VERIF;
        VSCtl_stMonVSMax = VSCTL_STMONVSMAX_VERIF;
        vsmax_vsctl_bmonrunvsmax_cpy = VSMAX_Re002tev_Sf_VRAI_j;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_DEFAUT_IRREVESIBLE:
      if (((((Ext_bVSMaxfCf_swc_in != EXT_BVSMAXFCF_PRESENT)
      && (Ext_bVSMaxpCf_swc_in !=
              EXT_BVSMAXPCF_PRESENT))
              && (Ext_bVSMaxsCf_swc_in != EXT_BVSMAXSCF_PRESENT))

           && (VSCtl_bAcvVSMaxc_C != VSMAX_Re002tev_Sf_VRAI_j))
           || (Ext_bKeyOff_swc_in ==
           VSMAX_Re002tev_Sf_VRAI_j))
      {
        vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET;
        VSCtl_stMonVSMax = VSCTL_STMONVSMAX_ARRET;
        VSCtl_ctDftRevVSMax = VSCtl_ctTolRvDftVSMax_C;
        vsmax_vsctl_bdgovsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
        vsmax_vsctl_bmonrunvsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
        VSCtl_bctDefRevVSMax = VSMAX_Re002tev_Sf_FAUX_o;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE:
      if ((((((((Ext_bVSMaxfCf_swc_in != EXT_BVSMAXFCF_PRESENT)
      && (Ext_bVSMaxpCf_swc_in !=
                 EXT_BVSMAXPCF_PRESENT)) && (Ext_bVSMaxsCf_swc_in !=
                EXT_BVSMAXSCF_PRESENT)) && (VSCtl_bAcvVSMaxc_C !=
               VSMAX_Re002tev_Sf_VRAI_j)) || (Ext_bKeyOff_swc_in ==
              VSMAX_Re002tev_Sf_VRAI_j)) || (VSCtl_stVSCtlInfo_swc_in ==
             VSCTL_STVSCTLINFO_ARRET)) || (VSCtl_stVSCtlInfo_swc_in ==
            VSCTL_STVSCTLINFO_VERIF)) || (VSCtl_stVSCtlInfo_swc_in ==
           VSCTL_STVSCTLINFO_INIT))
      {
        vsmax_re002tev_sf_dwork.is_NON_VERIF = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsmax_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsmax_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET;
        VSCtl_stMonVSMax = VSCTL_STMONVSMAX_ARRET;
        VSCtl_ctDftRevVSMax = VSCtl_ctTolRvDftVSMax_C;
        vsmax_vsctl_bdgovsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
        vsmax_vsctl_bmonrunvsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
        VSCtl_bctDefRevVSMax = VSMAX_Re002tev_Sf_FAUX_o;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_MARCHE_j)
      {
         case VSMAX_Re002tev_Sf_IN_NON_VERIF:
          if (FRM_bDeacIrvVSMax_swc_in == VSMAX_Re002tev_Sf_VRAI_j)
          {
            vsmax_re002tev_sf_dwork.is_NON_VERIF = (UInt8)
              VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
            vsmax_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
            vsmax_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
              VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
            vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
              VSMAX_Re002tev_Sf_IN_DEFAUT_IRREVESIBLE;
            VSCtl_stMonVSMax = VSCTL_STMONVSMAX_DEFAUT_IRREV;

          }
          else
          {
            switch (vsmax_re002tev_sf_dwork.is_NON_VERIF)
      {
             case VSMAX_Re002tev_Sf_IN_DEFAUT_REVESIBLE:
              if (VSCtl_ctDftRevVSMax == 0)
              {
                vsmax_vsctl_bdgovsmax_cpy = VSMAX_Re002tev_Sf_VRAI_j;
                VSCtl_bctDefRevVSMax = VSMAX_Re002tev_Sf_VRAI_j;
                vsmax_re002tev_sf_dwork.is_NON_VERIF = (UInt8)
                  VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
                vsmax_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
                  VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
                vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
                  VSMAX_Re002tev_Sf_IN_DEFAUT_IRREVESIBLE;
                VSCtl_stMonVSMax = VSCTL_STMONVSMAX_DEFAUT_IRREV;

              }
              else if ((((FRM_bDeacRvVSMax_swc_in == VSMAX_Re002tev_Sf_FAUX_o)
              &&
                           (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL))
                           &&
                          (VSCtl_ctDftRevVSMax != 0))
                          && (VSCtl_tiDftRvVSMax ==
                          0))
              {
                vsmax_re002tev_sf_dwork.is_NON_VERIF = (UInt8)
                  VSMAX_Re002tev_Sf_IN_PAS_DEFAUT;
                vsmax_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSMAX_Re002tev_Sf_IN_INIT;
                VSCtl_stMonVSMax = VSCTL_STMONVSMAX_INIT;
                VSCtl_tiIniVSMax = VSCtl_tiVSMaxIni_C;

              }
              else
              {
                VSCtl_tiDftRvVSMax = (UInt8)DDS_M_MAX(VSCtl_tiDftRvVSMax - 1, 0);
              }
              break;

             case VSMAX_Re002tev_Sf_IN_PAS_DEFAUT:
              if ((FRM_bDeacRvVSMax_swc_in == VSMAX_Re002tev_Sf_VRAI_j) ||
                  (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_DEFAUT_20))
              {
                vsmax_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
                vsmax_re002tev_sf_dwork.is_NON_VERIF = (UInt8)
                  VSMAX_Re002tev_Sf_IN_DEFAUT_REVESIBLE;
                VSCtl_stMonVSMax = VSCTL_STMONVSMAX_DEFAUT_REV;
                VSCtl_tiDftRvVSMax = VSCtl_tiDftRvVSMax_C;
                VSCtl_ctDftRevVSMax = (UInt8)(VSCtl_ctDftRevVSMax - 1);

              }
              else
              {
                switch (vsmax_re002tev_sf_dwork.is_PAS_DEFAUT)
      {
                 case VSMAX_Re002tev_Sf_IN_INIT:
                  if (VSCtl_tiIniVSMax == 0)
                  {
                    vsmax_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                      VSMAX_Re002tev_Sf_IN_NOMINAL;
                    VSCtl_stMonVSMax = VSCTL_STMONVSMAX_NOMINAL;

                  }
                  else
                  {
                    VSCtl_tiIniVSMax = (UInt8)DDS_M_MAX(VSCtl_tiIniVSMax - 1, 0);
                  }
                  break;
                }
              }
              break;
            }
          }
          break;

         case VSMAX_Re002tev_Sf_IN_VERIF:
          if ((ECU_bAuthVSCtlIni_swc_in == VSMAX_Re002tev_Sf_VRAI_j) &&
              (FRM_bDeacIrvVSMax_swc_in == VSMAX_Re002tev_Sf_VRAI_j))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
              VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
            vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
              VSMAX_Re002tev_Sf_IN_DEFAUT_IRREVESIBLE;
            VSCtl_stMonVSMax = VSCTL_STMONVSMAX_DEFAUT_IRREV;

          }
          else if (((ECU_bAuthVSCtlIni_swc_in == VSMAX_Re002tev_Sf_VRAI_j)
          &&
                      ((FRM_bDeacRvVSMax_swc_in == VSMAX_Re002tev_Sf_VRAI_j)
                      ||
                       (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_DEFAUT_20)))
                       &&
                     (FRM_bDeacIrvVSMax_swc_in == VSMAX_Re002tev_Sf_FAUX_o))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
              VSMAX_Re002tev_Sf_IN_NON_VERIF;
            vsmax_re002tev_sf_dwork.is_NON_VERIF = (UInt8)
              VSMAX_Re002tev_Sf_IN_DEFAUT_REVESIBLE;
            VSCtl_stMonVSMax = VSCTL_STMONVSMAX_DEFAUT_REV;
            VSCtl_tiDftRvVSMax = VSCtl_tiDftRvVSMax_C;
            VSCtl_ctDftRevVSMax = (UInt8)(VSCtl_ctDftRevVSMax - 1);

          }
          else if ((((ECU_bAuthVSCtlIni_swc_in == VSMAX_Re002tev_Sf_VRAI_j)
          &&
                       (FRM_bDeacRvVSMax_swc_in == VSMAX_Re002tev_Sf_FAUX_o))
                       &&
                      (FRM_bDeacIrvVSMax_swc_in == VSMAX_Re002tev_Sf_FAUX_o))
                      &&
                     (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
              VSMAX_Re002tev_Sf_IN_NON_VERIF;
            vsmax_re002tev_sf_dwork.is_NON_VERIF = (UInt8)
              VSMAX_Re002tev_Sf_IN_PAS_DEFAUT;
            vsmax_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSMAX_Re002tev_Sf_IN_INIT;
            VSCtl_stMonVSMax = VSCTL_STMONVSMAX_INIT;
            VSCtl_tiIniVSMax = VSCtl_tiVSMaxIni_C;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET;
      VSCtl_stMonVSMax = VSCTL_STMONVSMAX_ARRET;
      VSCtl_ctDftRevVSMax = VSCtl_ctTolRvDftVSMax_C;
      vsmax_vsctl_bdgovsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
      vsmax_vsctl_bmonrunvsmax_cpy = VSMAX_Re002tev_Sf_FAUX_o;
      VSCtl_bctDefRevVSMax = VSMAX_Re002tev_Sf_FAUX_o;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F5112_Determiner_Etat_Service*/


  stack_data_u16_0 = vsmax_re002tev_sf_delay_0;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F512211_Determiner_Demande_Activation_BVVf*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.40.1 */

  if (vsmax_re002tev_sf_dwork.is_active_c211_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c211_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c211_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVf;
    vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVf = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_n;
    VSCtl_bAcvVSMaxf = VSMAX_Re002tev_Sf_FAUX_h;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVf)
          {
     case VSMAX_Re002tev_Sf_IN_ARRET_n:
      if (((Ext_bVSMaxfCf_swc_in == EXT_BVSMAXFCF_PRESENT)
      && (((VSCtl_stMonVSMax ==
              VSCTL_STMONVSMAX_DEFAUT_IRREV) || (VSCtl_stMonVSMax ==
              VSCTL_STMONVSMAX_DEFAUT_REV)) || (FRM_bDeacRvVSMaxf_swc_in ==
             VSMAX_Re002tev_Sf_VRAI_jr))) &&
          ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
           VSCtl_spdVehErrVSMaxfAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVf = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_c;
        vsmax_re002tev_sf_dwork.is_MARCHE_d = (UInt8)
          VSMAX_Re002tev_Sf_IN_DEFAUT;
        VSCtl_bAcvVSMaxf = VSMAX_Re002tev_Sf_FAUX_h;

      }
      else if ((((Ext_bVSMaxfCf_swc_in == EXT_BVSMAXFCF_PRESENT)
      && (VSCtl_stMonVSMax
        == VSCTL_STMONVSMAX_NOMINAL)) && (FRM_bDeacRvVSMaxf_swc_in ==
                   VSMAX_Re002tev_Sf_FAUX_h)) &&
                 ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                  VSCtl_spdVehErrVSMaxfAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVf = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_c;
        vsmax_re002tev_sf_dwork.is_MARCHE_d = (UInt8)
          VSMAX_Re002tev_Sf_IN_VRAI_m;
        VSCtl_bAcvVSMaxf = VSMAX_Re002tev_Sf_VRAI_jr;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE_c:
      if (((Ext_bVSMaxfCf_swc_in != EXT_BVSMAXFCF_PRESENT)
      || (VSCtl_stMonVSMax ==
            VSCTL_STMONVSMAX_ARRET))
            || ((stack_data_u16_0
            - Veh_spdVeh_swc_in) > VSCtl_spdVehErrVSMaxfAcvHi_C))
      {
        vsmax_re002tev_sf_dwork.is_MARCHE_d = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g;
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVf = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_n;
        VSCtl_bAcvVSMaxf = VSMAX_Re002tev_Sf_FAUX_h;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_MARCHE_d)
      {
         case VSMAX_Re002tev_Sf_IN_DEFAUT:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
               (FRM_bDeacRvVSMaxf_swc_in == VSMAX_Re002tev_Sf_FAUX_h)) &&
              (((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                VSCtl_spdVehErrVSMaxfAcvLo_C) &&
               ((stack_data_u16_0 - Veh_spdVeh_swc_in) >=
                VSCtl_spdVehErrVSMaxfErr_C)))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_d = (UInt8)
              VSMAX_Re002tev_Sf_IN_VRAI_m;
            VSCtl_bAcvVSMaxf = VSMAX_Re002tev_Sf_VRAI_jr;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_VRAI_m:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV) ||
               (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV)) ||
              (FRM_bDeacRvVSMaxf_swc_in == VSMAX_Re002tev_Sf_VRAI_jr))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_d = (UInt8)
              VSMAX_Re002tev_Sf_IN_DEFAUT;
            VSCtl_bAcvVSMaxf = VSMAX_Re002tev_Sf_FAUX_h;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVf = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_n;
      VSCtl_bAcvVSMaxf = VSMAX_Re002tev_Sf_FAUX_h;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F512211_Determiner_Demande_Activation_BVVf*/


  stack_data_u16_0 = vsmax_re002tev_sf_delay_1;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F512212_Determiner_Demande_Activation_BVVp*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.41.1 */

  if (vsmax_re002tev_sf_dwork.is_active_c40_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c40_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c40_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVp;
    vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVp = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_h;
    VSCtl_bAcvVSMaxp = VSMAX_Re002tev_Sf_FAUX_b;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVp)
          {
     case VSMAX_Re002tev_Sf_IN_ARRET_h:
      if (((Ext_bVSMaxpCf_swc_in == EXT_BVSMAXPCF_PRESENT)
      && (((VSCtl_stMonVSMax ==
              VSCTL_STMONVSMAX_DEFAUT_IRREV) || (VSCtl_stMonVSMax ==
              VSCTL_STMONVSMAX_DEFAUT_REV)) || (FRM_bDeacRvVSMaxp_swc_in ==
             VSMAX_Re002tev_Sf_VRAI_k))) &&
          ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
           VSCtl_spdVehErrVSMaxpAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVp = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_i;
        vsmax_re002tev_sf_dwork.is_MARCHE_a = (UInt8)
          VSMAX_Re002tev_Sf_IN_DEFAUT_a;
        VSCtl_bAcvVSMaxp = VSMAX_Re002tev_Sf_FAUX_b;

      }
      else if ((((Ext_bVSMaxpCf_swc_in == EXT_BVSMAXPCF_PRESENT)
      && (VSCtl_stMonVSMax
        == VSCTL_STMONVSMAX_NOMINAL)) && (FRM_bDeacRvVSMaxp_swc_in ==
                   VSMAX_Re002tev_Sf_FAUX_b)) &&
                 ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                  VSCtl_spdVehErrVSMaxpAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVp = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_i;
        vsmax_re002tev_sf_dwork.is_MARCHE_a = (UInt8)
          VSMAX_Re002tev_Sf_IN_VRAI_g;
        VSCtl_bAcvVSMaxp = VSMAX_Re002tev_Sf_VRAI_k;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE_i:
      if (((Ext_bVSMaxpCf_swc_in != EXT_BVSMAXPCF_PRESENT)
      || (VSCtl_stMonVSMax ==
            VSCTL_STMONVSMAX_ARRET)) ||
          ((stack_data_u16_0 - Veh_spdVeh_swc_in) >
           VSCtl_spdVehErrVSMaxpAcvHi_C))
      {
        vsmax_re002tev_sf_dwork.is_MARCHE_a = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_b;
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVp = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_h;
        VSCtl_bAcvVSMaxp = VSMAX_Re002tev_Sf_FAUX_b;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_MARCHE_a)
      {
         case VSMAX_Re002tev_Sf_IN_DEFAUT_a:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
               (FRM_bDeacRvVSMaxp_swc_in == VSMAX_Re002tev_Sf_FAUX_b)) &&
              (((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                VSCtl_spdVehErrVSMaxpAcvLo_C) &&
               ((stack_data_u16_0 - Veh_spdVeh_swc_in) >=
                VSCtl_spdVehErrVSMaxpErr_C)))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_a = (UInt8)
              VSMAX_Re002tev_Sf_IN_VRAI_g;
            VSCtl_bAcvVSMaxp = VSMAX_Re002tev_Sf_VRAI_k;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_VRAI_g:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV) ||
               (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV)) ||
              (FRM_bDeacRvVSMaxp_swc_in == VSMAX_Re002tev_Sf_VRAI_k))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_a = (UInt8)
              VSMAX_Re002tev_Sf_IN_DEFAUT_a;
            VSCtl_bAcvVSMaxp = VSMAX_Re002tev_Sf_FAUX_b;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVp = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_h;
      VSCtl_bAcvVSMaxp = VSMAX_Re002tev_Sf_FAUX_b;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F512212_Determiner_Demande_Activation_BVVp*/


  stack_data_u16_0 = vsmax_re002tev_sf_delay_2;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F512213_Determiner_Demande_Activation_BVVs*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.42.1 */

  if (vsmax_re002tev_sf_dwork.is_active_c42_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c42_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c42_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVs;
    vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVs = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_j;
    VSCtl_bAcvVSMaxs = VSMAX_Re002tev_Sf_FAUX_m;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVs)
          {
     case VSMAX_Re002tev_Sf_IN_ARRET_j:
      if (((Ext_bVSMaxsCf_swc_in == EXT_BVSMAXSCF_PRESENT)
      && (((VSCtl_stMonVSMax ==
              VSCTL_STMONVSMAX_DEFAUT_IRREV) || (VSCtl_stMonVSMax ==
              VSCTL_STMONVSMAX_DEFAUT_REV)) || (FRM_bDeacRvVSMaxs_swc_in ==
             VSMAX_Re002tev_Sf_VRAI_a))) &&
          ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
           VSCtl_spdVehErrVSMaxsAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVs = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_k;
        vsmax_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
          VSMAX_Re002tev_Sf_IN_DEFAUT_f;
        VSCtl_bAcvVSMaxs = VSMAX_Re002tev_Sf_FAUX_m;

      }
      else if ((((Ext_bVSMaxsCf_swc_in == EXT_BVSMAXSCF_PRESENT)
      && (VSCtl_stMonVSMax
        == VSCTL_STMONVSMAX_NOMINAL)) && (FRM_bDeacRvVSMaxs_swc_in ==
                   VSMAX_Re002tev_Sf_FAUX_m)) &&
                 ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                  VSCtl_spdVehErrVSMaxsAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVs = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_k;
        vsmax_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
          VSMAX_Re002tev_Sf_IN_VRAI_n;
        VSCtl_bAcvVSMaxs = VSMAX_Re002tev_Sf_VRAI_a;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE_k:
      if (((Ext_bVSMaxsCf_swc_in != EXT_BVSMAXSCF_PRESENT)
      || (VSCtl_stMonVSMax ==
            VSCTL_STMONVSMAX_ARRET)) ||
          ((stack_data_u16_0 - Veh_spdVeh_swc_in) >
           VSCtl_spdVehErrVSMaxsAcvHi_C))
      {
        vsmax_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d;
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVs = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_j;
        VSCtl_bAcvVSMaxs = VSMAX_Re002tev_Sf_FAUX_m;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_MARCHE_l)
      {
         case VSMAX_Re002tev_Sf_IN_DEFAUT_f:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
               (FRM_bDeacRvVSMaxs_swc_in == VSMAX_Re002tev_Sf_FAUX_m)) &&
              (((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                VSCtl_spdVehErrVSMaxsAcvLo_C) &&
               ((stack_data_u16_0 - Veh_spdVeh_swc_in) >=
                VSCtl_spdVehErrVSMaxsErr_C)))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
              VSMAX_Re002tev_Sf_IN_VRAI_n;
            VSCtl_bAcvVSMaxs = VSMAX_Re002tev_Sf_VRAI_a;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_VRAI_n:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV) ||
               (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV)) ||
              (FRM_bDeacRvVSMaxs_swc_in == VSMAX_Re002tev_Sf_VRAI_a))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
              VSMAX_Re002tev_Sf_IN_DEFAUT_f;
            VSCtl_bAcvVSMaxs = VSMAX_Re002tev_Sf_FAUX_m;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVs = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_j;
      VSCtl_bAcvVSMaxs = VSMAX_Re002tev_Sf_FAUX_m;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F512213_Determiner_Demande_Activation_BVVs*/


  stack_data_u16_0 = vsmax_re002tev_sf_delay_3;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F512214_Determiner_Demande_Activation_BVVc*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.43.2 */

  if (vsmax_re002tev_sf_dwork.is_active_c43_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c43_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c43_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_DEMANDE_ACTIVATION_BVVc;
    vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVc = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_c;
    VSCtl_bAcvVSMaxc = VSMAX_Re002tev_Sf_FAUX_e;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVc)
          {
     case VSMAX_Re002tev_Sf_IN_ARRET_c:
      if ((((VSCtl_bAcvVSMaxc_C == VSMAX_Re002tev_Sf_VRAI_c) &&
            (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV) ||
              (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV)) ||
             (FRM_bDeacRvVSMaxc_swc_in == VSMAX_Re002tev_Sf_VRAI_c))) &&
           (((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE)
           || (VSCtl_stVSLimExtd_swc_in ==
              VSCTL_STVSLIMEXTD_AE)) || (VSCtl_stDVSRegExtd_swc_in ==
             VSCTL_STDVSREGEXTD_AE))) &&
          ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
           VSCtl_spdVehErrVSMaxcAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVc = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_h;
        vsmax_re002tev_sf_dwork.is_MARCHE_n = (UInt8)
          VSMAX_Re002tev_Sf_IN_DEFAUT_fa;
        VSCtl_bAcvVSMaxc = VSMAX_Re002tev_Sf_FAUX_e;

      }
      else if (((((VSCtl_bAcvVSMaxc_C == VSMAX_Re002tev_Sf_VRAI_c)
      &&
                    (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL))
                    &&
                   (((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE) ||
                     (VSCtl_stVSLimExtd_swc_in == VSCTL_STVSLIMEXTD_AE)) ||
                    (VSCtl_stDVSRegExtd_swc_in == VSCTL_STDVSREGEXTD_AE)))
                    &&
                  (FRM_bDeacRvVSMaxc_swc_in == VSMAX_Re002tev_Sf_FAUX_e)) &&
                 ((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                  VSCtl_spdVehErrVSMaxcAcvLo_C))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVc = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_h;
        vsmax_re002tev_sf_dwork.is_MARCHE_n = (UInt8)
          VSMAX_Re002tev_Sf_IN_VRAI_j;
        VSCtl_bAcvVSMaxc = VSMAX_Re002tev_Sf_VRAI_c;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE_h:
      if ((((VSCtl_bAcvVSMaxc_C == VSMAX_Re002tev_Sf_FAUX_e) ||
            (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_ARRET)) ||
           (((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE)
           && (VSCtl_stVSLimExtd_swc_in
              != VSCTL_STVSLIMEXTD_AE)) && (VSCtl_stDVSRegExtd_swc_in !=
             VSCTL_STDVSREGEXTD_AE))) ||
          ((stack_data_u16_0 - Veh_spdVeh_swc_in) >
           VSCtl_spdVehErrVSMaxcAcvHi_C))
      {
        vsmax_re002tev_sf_dwork.is_MARCHE_n = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
        vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVc = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_c;
        VSCtl_bAcvVSMaxc = VSMAX_Re002tev_Sf_FAUX_e;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_MARCHE_n)
      {
         case VSMAX_Re002tev_Sf_IN_DEFAUT_fa:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
               (FRM_bDeacRvVSMaxc_swc_in == VSMAX_Re002tev_Sf_FAUX_e)) &&
              (((stack_data_u16_0 - Veh_spdVeh_swc_in) <=
                VSCtl_spdVehErrVSMaxcAcvLo_C) &&
               ((stack_data_u16_0 - Veh_spdVeh_swc_in) >=
                VSCtl_spdVehErrVSMaxcErr_C)))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_VRAI_j;
            VSCtl_bAcvVSMaxc = VSMAX_Re002tev_Sf_VRAI_c;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_VRAI_j:
          if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV) ||
               (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV)) ||
              (FRM_bDeacRvVSMaxc_swc_in == VSMAX_Re002tev_Sf_VRAI_c))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_DEFAUT_fa;
            VSCtl_bAcvVSMaxc = VSMAX_Re002tev_Sf_FAUX_e;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVc = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_c;
      VSCtl_bAcvVSMaxc = VSMAX_Re002tev_Sf_FAUX_e;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F512214_Determiner_Demande_Activation_BVVc*/

    VSMAX_F51211_Determiner_Condition_Alerte_Pneumatiques(Ext_bTyreWarn_swc_in,
                                                            Ext_bTyreWarnCf_swc_in);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F51213_Determiner_Demande_Inhibition_Frein_LAS*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.39.0 */

  if (vsmax_re002tev_sf_dwork.is_active_c39_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c39_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c39_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_DEMANDE_INHIBITION;
    vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION_b = (UInt8)
      VSMAX_Re002tev_Sf_IN_DEMANDEE;
    VSCtl_bInhVSMaxReq_Brk = VSMAX_Re002tev_Sf_VRAI_b;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION_b)
          {
     case VSMAX_Re002tev_Sf_IN_DEMANDEE:
      if ((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
          (VSCtl_bTyreWarnVSMax == VSMAX_Re002tev_Sf_FAUX_c))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION_b = (UInt8)
          VSMAX_Re002tev_Sf_IN_PAS_DEMANDEE;
        VSCtl_bInhVSMaxReq_Brk = VSMAX_Re002tev_Sf_FAUX_c;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_PAS_DEMANDEE:
      if ((VSCtl_stMonVSMax != VSCTL_STMONVSMAX_NOMINAL) ||
          (VSCtl_bTyreWarnVSMax == VSMAX_Re002tev_Sf_VRAI_b))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION_b = (UInt8)
          VSMAX_Re002tev_Sf_IN_DEMANDEE;
        VSCtl_bInhVSMaxReq_Brk = VSMAX_Re002tev_Sf_VRAI_b;
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION_b = (UInt8)
        VSMAX_Re002tev_Sf_IN_DEMANDEE;
      VSCtl_bInhVSMaxReq_Brk = VSMAX_Re002tev_Sf_VRAI_b;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F51213_Determiner_Demande_Inhibition_Frein_LAS*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F51222_Determiner_Demande_Inhibition*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.11.1 */

  if (vsmax_re002tev_sf_dwork.is_active_c213_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c213_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c213_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_DEMANDE_INHIBITION_f;
    vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
      VSMAX_Re002tev_Sf_IN_VRAI_a;
    VSCtl_bInhVSMax = VSMAX_Re002tev_Sf_VRAI_g;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION)
      {
     case VSMAX_Re002tev_Sf_IN_FAUX_k:
      if (((VSCtl_stMonVSMax != VSCTL_STMONVSMAX_NOMINAL) ||
           (VSCtl_bInhVSMaxReq_Brk == VSMAX_Re002tev_Sf_VRAI_g)) ||
          (FRM_bInhVSMax_swc_in == VSMAX_Re002tev_Sf_VRAI_g))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
          VSMAX_Re002tev_Sf_IN_VRAI_a;
        VSCtl_bInhVSMax = VSMAX_Re002tev_Sf_VRAI_g;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_VRAI_a:
      if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
           (VSCtl_bInhVSMaxReq_Brk == VSMAX_Re002tev_Sf_FAUX_ho)) &&
          (FRM_bInhVSMax_swc_in == VSMAX_Re002tev_Sf_FAUX_ho))
      {
        vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
          VSMAX_Re002tev_Sf_IN_FAUX_k;
        VSCtl_bInhVSMax = VSMAX_Re002tev_Sf_FAUX_ho;
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
        VSMAX_Re002tev_Sf_IN_VRAI_a;
      VSCtl_bInhVSMax = VSMAX_Re002tev_Sf_VRAI_g;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F51222_Determiner_Demande_Inhibition*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F513_Determiner_Etat_Fonctionnement*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.12.1 */

  if (vsmax_re002tev_sf_dwork.is_active_c214_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c214_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c214_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_ETAT_FONCTIONNEMENT;
    vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
      VSMAX_Re002tev_Sf_IN_INDISPONIBLE;
    vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_e;
    vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ARRET;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT)
      {
     case VSMAX_Re002tev_Sf_IN_DISPONIBLE:
      if (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_ARRET)
      {
        vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_DISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSMAX_Re002tev_Sf_IN_INDISPONIBLE;
        vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_e;
        vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ARRET;

      }
      else if ((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_INIT) ||
                 (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_VERIF))
      {
        vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_DISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSMAX_Re002tev_Sf_IN_INDISPONIBLE;
        vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_FONCTION_PRESENTE;
        vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
          VSMAX_Re002tev_Sf_IN_INITIALISATION;
        vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_INITIALISATION;

      }
      else if ((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
                 (VSCtl_bInhVSMax == VSMAX_Re002tev_Sf_VRAI_h))
      {
        vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_DISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSMAX_Re002tev_Sf_IN_INDISPONIBLE;
        vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_FONCTION_PRESENTE;
        vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
          VSMAX_Re002tev_Sf_IN_INHIBEE;
        vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_INHIBEE;

      }
      else if ((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV) ||
                 (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV))
      {
        vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_DISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
        vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSMAX_Re002tev_Sf_IN_INDISPONIBLE;
        vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_FONCTION_PRESENTE;
        vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
          VSMAX_Re002tev_Sf_IN_DEFAUT_b;
        vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_DEFAUT;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_DISPONIBLE)
      {
         case VSMAX_Re002tev_Sf_IN_ACTIVATION_DEMANDEE:
          if ((((VSCtl_bAcvVSMaxf == VSMAX_Re002tev_Sf_FAUX_p) &&
                (VSCtl_bAcvVSMaxp == VSMAX_Re002tev_Sf_FAUX_p)) &&
               (VSCtl_bAcvVSMaxs == VSMAX_Re002tev_Sf_FAUX_p)) &&
              (VSCtl_bAcvVSMaxc == VSMAX_Re002tev_Sf_FAUX_p))
          {
            vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
              VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
            vsmax_re002tev_sf_dwork.is_DISPONIBLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_ATTENTE;
            vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ATTENTE;

          }
          else
          {
            switch (vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE)
      {
             case VSMAX_Re002tev_Sf_IN_ACTIVE_EFFECTIVE:
              if (VSCtl_bDrvOvrdVSMax_aVeh_swc_in == VSMAX_Re002tev_Sf_VRAI_h)
              {
                vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
                  VSMAX_Re002tev_Sf_IN_ACTIVE_NON_EFFECTIVE;
                vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ANE;
              }
              break;

             case VSMAX_Re002tev_Sf_IN_ACTIVE_NON_EFFECTIVE:
              if (VSCtl_bDrvOvrdVSMax_aVeh_swc_in == VSMAX_Re002tev_Sf_FAUX_p)
              {
                vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
                  VSMAX_Re002tev_Sf_IN_ACTIVE_EFFECTIVE;
                vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_AE;
              }
              break;
            }
          }
          break;

         case VSMAX_Re002tev_Sf_IN_ATTENTE:
          if ((((VSCtl_bAcvVSMaxf == VSMAX_Re002tev_Sf_VRAI_h) ||
                (VSCtl_bAcvVSMaxp == VSMAX_Re002tev_Sf_VRAI_h)) ||
               (VSCtl_bAcvVSMaxs == VSMAX_Re002tev_Sf_VRAI_h)) ||
              (VSCtl_bAcvVSMaxc == VSMAX_Re002tev_Sf_VRAI_h))
          {
            vsmax_re002tev_sf_dwork.is_DISPONIBLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_ACTIVATION_DEMANDEE;
            vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = (UInt8)
              VSMAX_Re002tev_Sf_IN_ACTIVE_NON_EFFECTIVE;
            vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ANE;
          }
          break;
        }
      }
      break;

     case VSMAX_Re002tev_Sf_IN_INDISPONIBLE:
      switch (vsmax_re002tev_sf_dwork.is_INDISPONIBLE)
          {
       case VSMAX_Re002tev_Sf_IN_ARRET_e:
        if (VSCtl_stMonVSMax != VSCTL_STMONVSMAX_ARRET)
        {
          vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
            VSMAX_Re002tev_Sf_IN_FONCTION_PRESENTE;
          vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
            VSMAX_Re002tev_Sf_IN_INITIALISATION;
          vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_INITIALISATION;
        }
        break;

       case VSMAX_Re002tev_Sf_IN_FONCTION_PRESENTE:
        if (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_ARRET)
        {
          vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
            VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
          vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
            VSMAX_Re002tev_Sf_IN_ARRET_e;
          vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ARRET;

        }
        else
        {
          switch (vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE)
        {
           case VSMAX_Re002tev_Sf_IN_DEFAUT_b:
            if (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL)
            {
              vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSMAX_Re002tev_Sf_IN_INHIBEE;
              vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_INHIBEE;
            }
            break;

           case VSMAX_Re002tev_Sf_IN_INHIBEE:
            if ((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL) &&
                (VSCtl_bInhVSMax == VSMAX_Re002tev_Sf_FAUX_p))
            {
              vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
              vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
                VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_l;
              vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
                VSMAX_Re002tev_Sf_IN_DISPONIBLE;
              vsmax_re002tev_sf_dwork.is_DISPONIBLE = (UInt8)
                VSMAX_Re002tev_Sf_IN_ATTENTE;
              vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ATTENTE;

            }
            else if ((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV)
            ||
                       (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV))
            {
              vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSMAX_Re002tev_Sf_IN_DEFAUT_b;
              vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_DEFAUT;
            }
            break;

           case VSMAX_Re002tev_Sf_IN_INITIALISATION:
            if ((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_REV) ||
                (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_DEFAUT_IRREV))
            {
              vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSMAX_Re002tev_Sf_IN_DEFAUT_b;
              vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_DEFAUT;

            }
            else if (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL)
            {
              vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSMAX_Re002tev_Sf_IN_INHIBEE;
              vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_INHIBEE;
            }
            break;
          }
        }
        break;
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
        VSMAX_Re002tev_Sf_IN_INDISPONIBLE;
      vsmax_re002tev_sf_dwork.is_INDISPONIBLE = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_e;
      vsmax_vsctl_stvsmaxextd_cpy = VSCTL_STVSMAXEXTD_ARRET;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F513_Determiner_Etat_Fonctionnement*/

  VSMAX_F5211_Determiner_Consigne_Vitesse_Bvvf(Ext_bVSMaxfCf_swc_in,
                                                FRM_bDeacRvVSMaxf_swc_in);


  VSMAX_F5212_Determiner_Consigne_Vitesse_Bvvp(Ext_bVSMaxpCf_swc_in,
                                                Ext_spdVehVSMaxPrmaReq_swc_in,
                                                FRM_bDeacRvVSMaxp_swc_in);


  VSMAX_F5213_Determiner_Consigne_Vitesse_Bvvs(Ext_bVSMaxsCf_swc_in,
                                                FRM_bAcvVSMax_no1_swc_in,
                                                FRM_bAcvVSMax_no2_swc_in);

  stack_data_u16_0 = vsmax_re002tev_sf_delay_4;

  stack_data_u16_1 = vsmax_re002tev_sf_delay_5;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F52141_Determiner_Mode_Commande_Consigne_BVVc*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.55.0 */

  if (vsmax_re002tev_sf_dwork.is_active_c95_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c95_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c95_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_MODE_COMMANDE_CONSIGNE_BVVc;
    vsmax_re002tev_sf_dwork.is_active_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE = 1U;
    vsmax_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_i;
    VSCtl_stSpdVehCritModClc = VSCTL_STSPDVEHCRITMODCLC_ARRET;
    vsmax_re002tev_sf_dwork.is_active_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE =
      1U;
    vsmax_re002tev_sf_dwork.is_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE =
      (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_i;
    VSCtl_stSpdVehCritFilModClc = VSCTL_STSPDVEHCRITFILMODCLC_ARRET;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE)
            {
     case VSMAX_Re002tev_Sf_IN_ARRET_i:
      if (((VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL)
      && ((Ext_stGBxCf_swc_in ==
             EXT_STGBXCF_BVA)
             || (Ext_stGBxCf_swc_in == EXT_STGBXCF_BVMP)))
             &&
          (VSCtl_bAcvVSMaxc_C == VSMAX_Re002tev_Sf_VRAI_bk))
      {
        vsmax_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE =
          (UInt8)VSMAX_Re002tev_Sf_IN_MARCHE_o;
        vsmax_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
          VSMAX_Re002tev_Sf_IN_CONTROL;
        vsmax_re002tev_sf_dwork.is_CONTROL = (UInt8)
          VSMAX_Re002tev_Sf_IN_NON_EFFECTIF;
        VSCtl_stSpdVehCritModClc = VSCTL_STSPDVEHCRITMODCLC_NON_EFFECTIF_17;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE_o:
      if (((VSCtl_stMonVSMax != VSCTL_STMONVSMAX_NOMINAL)
      || ((Ext_stGBxCf_swc_in !=
             EXT_STGBXCF_BVA)
             && (Ext_stGBxCf_swc_in != EXT_STGBXCF_BVMP)))
             ||
          (VSCtl_bAcvVSMaxc_C == VSMAX_Re002tev_Sf_FAUX_n))
      {
        vsmax_re002tev_sf_dwork.is_CONTROL = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m;
        vsmax_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m;
        vsmax_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE =
          (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_i;
        VSCtl_stSpdVehCritModClc = VSCTL_STSPDVEHCRITMODCLC_ARRET;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_CONTROL)
      {
         case VSMAX_Re002tev_Sf_IN_EFFECTIF:
          if (VSCtl_aVehPTPotMaxCtla_no1_swc_in > VSCtl_aVehPTPotMaxCtla1_HysHi_C)
          {
            vsmax_re002tev_sf_dwork.is_CONTROL = (UInt8)
              VSMAX_Re002tev_Sf_IN_NON_EFFECTIF;
            VSCtl_stSpdVehCritModClc = VSCTL_STSPDVEHCRITMODCLC_NON_EFFECTIF_17;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_NON_EFFECTIF:
          if (VSCtl_aVehPTPotMaxCtla_no1_swc_in <= VSCtl_aVehPTPotMaxCtla1_HysLo_C)
          {
            vsmax_re002tev_sf_dwork.is_CONTROL = (UInt8)
              VSMAX_Re002tev_Sf_IN_EFFECTIF;
            VSCtl_stSpdVehCritModClc = VSCTL_STSPDVEHCRITMODCLC_EFFECTIF_17;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE =
        (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_i;
      VSCtl_stSpdVehCritModClc = VSCTL_STSPDVEHCRITMODCLC_ARRET;
      break;
    }

    switch (vsmax_re002tev_sf_dwork.is_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE)
    {
     case VSMAX_Re002tev_Sf_IN_ARRET_i:
      if (VSCtl_stSpdVehCritModClc == VSCTL_STSPDVEHCRITMODCLC_EFFECTIF_17)
      {
        vsmax_re002tev_sf_dwork.is_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE =
          (UInt8)VSMAX_Re002tev_Sf_IN_MARCHE_o;
        vsmax_re002tev_sf_dwork.is_MARCHE = (UInt8)VSMAX_Re002tev_Sf_IN_INIT_g;
        VSCtl_stSpdVehCritFilModClc = VSCTL_STSPDVEHCRITFILMODCLC_INIT_18;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE_o:
      if (VSCtl_stSpdVehCritModClc != VSCTL_STSPDVEHCRITMODCLC_EFFECTIF_17)
      {
        vsmax_re002tev_sf_dwork.is_MARCHE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m;
        vsmax_re002tev_sf_dwork.is_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE =
          (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_i;
        VSCtl_stSpdVehCritFilModClc = VSCTL_STSPDVEHCRITFILMODCLC_ARRET;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_MARCHE)
      {
         case VSMAX_Re002tev_Sf_IN_BLOQUE:
          if (((stack_data_u16_1 >
                stack_data_u16_0)
                && (VSCtl_spdVeh_swc_in >
                (stack_data_u16_0 +
                 VSCtl_spdVehCrit_HysHi_C))) ||
              ((stack_data_u16_1 <
                stack_data_u16_0)
                && (VSCtl_spdVeh_swc_in <
                (stack_data_u16_0 -
                 VSCtl_spdVehCrit_HysLo_C))))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSMAX_Re002tev_Sf_IN_INIT_g;
            VSCtl_stSpdVehCritFilModClc = VSCTL_STSPDVEHCRITFILMODCLC_INIT_18;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_INIT_g:
          vsmax_re002tev_sf_dwork.is_MARCHE = (UInt8)
            VSMAX_Re002tev_Sf_IN_BLOQUE;
          VSCtl_stSpdVehCritFilModClc = VSCTL_STSPDVEHCRITFILMODCLC_BLOQUE_18;
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE =
        (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_i;
      VSCtl_stSpdVehCritFilModClc = VSCTL_STSPDVEHCRITFILMODCLC_ARRET;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F52141_Determiner_Mode_Commande_Consigne_BVVc*/

  VSMAX_F52142_Determiner_Consigne_Vitesse_Bvvc(VehEst_spdVehCrit_swc_in, /* BIN0 */
                                                VSCtl_spdVeh_swc_in /* BIN7 */);


  VSMAX_F5215_Determiner_Consigne_Vitesse_Vehicule(VSCtl_spdVeh_swc_in, /* BIN7 */
                                                    vsmax_vsctl_stvsmaxextd_cpy, /* Enum */
                                                    &vsmax_vsctl_spdveherrvsmax_cpy, /* BIN7 */
                                                    &vsmax_vsctl_spdvehvsmaxreq_cpy /* BIN7 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F5221_Determiner_Mode_Commande_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.57.0 */

  if (vsmax_re002tev_sf_dwork.is_active_c215_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c215_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c215_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_MODE_COMMANDE_ACCELERATION_VEHICULE;
    vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_ACCELERATION_VEHICULE = (UInt8)
      VSMAX_Re002tev_Sf_IN_HORS_CONTROLE;
    vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_g;
    vsmax_vsctl_stctl_avehvsmax_cpy = VSCTL_STCTL_AVEHVSMAX_ARRET;
    VSCtl_tiFilStCtlAVehVSMax = VSCtl_tiFil_stCtlAVehVSMax_C;
    VSCtl_bAcvFil_aVehVSMax = VSMAX_Re002tev_Sf_FAUX_mz;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_ACCELERATION_VEHICULE)
          {
     case VSMAX_Re002tev_Sf_IN_CONTROLE:
      if (VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL)
      {
        vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_ACCELERATION_VEHICULE =
          (UInt8)VSMAX_Re002tev_Sf_IN_HORS_CONTROLE;
        vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_g;
        vsmax_vsctl_stctl_avehvsmax_cpy = VSCTL_STCTL_AVEHVSMAX_ARRET;
        VSCtl_tiFilStCtlAVehVSMax = VSCtl_tiFil_stCtlAVehVSMax_C;
        VSCtl_bAcvFil_aVehVSMax = VSMAX_Re002tev_Sf_FAUX_mz;

      }
      else if (((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
                  (vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE)) &&
                 (vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_ANE))
      {
        vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_ACCELERATION_VEHICULE =
          (UInt8)VSMAX_Re002tev_Sf_IN_HORS_CONTROLE;
        vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_TRANSITION;
        vsmax_vsctl_stctl_avehvsmax_cpy = VSCTL_STCTL_AVEHVSMAX_TRANSITION;
        VSCtl_bAcvFil_aVehVSMax = VSMAX_Re002tev_Sf_VRAI_bv;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_HORS_CONTROLE:
      if ((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
          ((vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_AE)
          || (vsmax_vsctl_stvsmaxextd_cpy ==
            VSCTL_STVSMAXEXTD_ANE)))
      {
        vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_md;
        vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_ACCELERATION_VEHICULE =
          (UInt8)VSMAX_Re002tev_Sf_IN_CONTROLE;
        vsmax_vsctl_stctl_avehvsmax_cpy = VSCTL_STCTL_AVEHVSMAX_CONTROLE;
        VSCtl_bAcvFil_aVehVSMax = VSMAX_Re002tev_Sf_VRAI_bv;
        VSCtl_tiFilStCtlAVehVSMax = VSCtl_tiFil_stCtlAVehVSMax_C;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_HORS_CONTROLE)
      {
         case VSMAX_Re002tev_Sf_IN_ARRET_g:
          break;

         case VSMAX_Re002tev_Sf_IN_TRANSITION:
          if ((VSCtl_bEndTranVSMax_swc_in == VSMAX_Re002tev_Sf_VRAI_bv) ||
              (VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL))
          {
            vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_ARRET_g;
            vsmax_vsctl_stctl_avehvsmax_cpy = VSCTL_STCTL_AVEHVSMAX_ARRET;
            VSCtl_tiFilStCtlAVehVSMax = VSCtl_tiFil_stCtlAVehVSMax_C;
            VSCtl_bAcvFil_aVehVSMax = VSMAX_Re002tev_Sf_FAUX_mz;

          }
          else
          {
            VSCtl_tiFilStCtlAVehVSMax = (UInt8)DDS_M_MAX
              (VSCtl_tiFilStCtlAVehVSMax - 1, 0);
          }
          break;

         default:
          vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = (UInt8)
            VSMAX_Re002tev_Sf_IN_ARRET_g;
          vsmax_vsctl_stctl_avehvsmax_cpy = VSCTL_STCTL_AVEHVSMAX_ARRET;
          VSCtl_tiFilStCtlAVehVSMax = VSCtl_tiFil_stCtlAVehVSMax_C;
          VSCtl_bAcvFil_aVehVSMax = VSMAX_Re002tev_Sf_FAUX_mz;
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_ACCELERATION_VEHICULE = (UInt8)
        VSMAX_Re002tev_Sf_IN_HORS_CONTROLE;
      vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_g;
      vsmax_vsctl_stctl_avehvsmax_cpy = VSCTL_STCTL_AVEHVSMAX_ARRET;
      VSCtl_tiFilStCtlAVehVSMax = VSCtl_tiFil_stCtlAVehVSMax_C;
      VSCtl_bAcvFil_aVehVSMax = VSMAX_Re002tev_Sf_FAUX_mz;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F5221_Determiner_Mode_Commande_Acceleration_Vehicule*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F52231_Determiner_Mode_Controle_Vitesse_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.25.1 */

  if (vsmax_re002tev_sf_dwork.is_active_c217_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c217_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c217_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_MODE_CONTROLE_VITESSE_VEHICULE;
    vsmax_re002tev_sf_dwork.is_active_CONDITION_CHANGEMENT_DYNAMIQUE = 1U;
    vsmax_re002tev_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
      VSMAX_Re002tev_Sf_IN_INIT_p;
    VSCtl_bDynCtlSpdVehVSMax = VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE;
    vsmax_re002tev_sf_dwork.is_active_LISSAGE_CONTROLE_VITESSE = 1U;
    vsmax_re002tev_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
      VSMAX_Re002tev_Sf_IN_INIT_p;
    vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = VSMAX_100_BIN7;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE)
      {
     case VSMAX_Re002tev_Sf_IN_INIT_p:
      if (vsmax_vsctl_stctl_avehvsmax_cpy == VSCTL_STCTL_AVEHVSMAX_CONTROLE)
      {
        vsmax_re002tev_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NON_INIT;
        vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
          VSMAX_Re002tev_Sf_IN_TRANSITOIRE;
        VSCtl_bDynCtlSpdVehVSMax = VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE;
        VSCtl_tiFilSpdVehCtlVSMaxDyn = VSCtl_tiTol_DynCtlVSMax_C;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_NON_INIT:
      if (vsmax_vsctl_stctl_avehvsmax_cpy != VSCTL_STCTL_AVEHVSMAX_CONTROLE)
      {
        vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_e;
        vsmax_re002tev_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
          VSMAX_Re002tev_Sf_IN_INIT_p;
        VSCtl_bDynCtlSpdVehVSMax = VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_NON_INIT_n)
      {
         case VSMAX_Re002tev_Sf_IN_CONF____0:
          if (((SInt16)DDS_M_ABS((SInt32)vsmax_vsctl_spdveherrvsmax_cpy)) >
              (VSCtl_spdErrVSMaxSDyn_HysHi_C > VSCtl_spdErrVSMaxSDyn_HysLo_C ?
               (SInt32)VSCtl_spdErrVSMaxSDyn_HysHi_C : (SInt32)
               VSCtl_spdErrVSMaxSDyn_HysLo_C))
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_DECONF____0;

          }
          else if ((((SInt16)DDS_M_ABS((SInt32)vsmax_vsctl_spdveherrvsmax_cpy)) <
                      (VSCtl_spdErrVSMaxSDyn_HysLo_C <
                       VSCtl_spdErrVSMaxSDyn_HysHi_C ? (SInt32)
                       VSCtl_spdErrVSMaxSDyn_HysLo_C : (SInt32)
                       VSCtl_spdErrVSMaxSDyn_HysHi_C)) &&
                     (VSCtl_tiFilSpdVehCtlVSMaxDyn <= 0))
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_STABILISE;
            VSCtl_bDynCtlSpdVehVSMax = VSCTL_BDYNCTLSPDVEHVSMAX_STABILISE;

          }
          else
          {
            VSCtl_tiFilSpdVehCtlVSMaxDyn = (UInt8)DDS_M_MAX
              (VSCtl_tiFilSpdVehCtlVSMaxDyn - VSCtl_tiCfm_SDynCtlChgVSMax_C, 0);
          }
          break;

         case VSMAX_Re002tev_Sf_IN_DECONF____0:
          if ((((SInt16)DDS_M_ABS((SInt32)vsmax_vsctl_spdveherrvsmax_cpy)) >
               VSCtl_spdErrVSMaxSDyn_HysHi_C)
               && (VSCtl_tiFilSpdVehCtlVSMaxDyn >=
               VSCtl_tiTol_DynCtlVSMax_C))
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_TRANSITOIRE;
            VSCtl_bDynCtlSpdVehVSMax = VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE;
            VSCtl_tiFilSpdVehCtlVSMaxDyn = VSCtl_tiTol_DynCtlVSMax_C;

          }
          else if (((SInt16)DDS_M_ABS((SInt32)vsmax_vsctl_spdveherrvsmax_cpy)) <
                     VSCtl_spdErrVSMaxSDyn_HysLo_C)
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_CONF____0;

          }
          else
          {
            VSCtl_tiFilSpdVehCtlVSMaxDyn = (UInt8)
              ((VSCtl_tiFilSpdVehCtlVSMaxDyn + VSCtl_tiDiCfmSDynCtlChgVSMax_C) <
               VSCtl_tiTol_DynCtlVSMax_C ? VSCtl_tiFilSpdVehCtlVSMaxDyn +
               VSCtl_tiDiCfmSDynCtlChgVSMax_C : (SInt32)
               VSCtl_tiTol_DynCtlVSMax_C);
          }
          break;

         case VSMAX_Re002tev_Sf_IN_STABILISE:
          if (((SInt16)DDS_M_ABS((SInt32)vsmax_vsctl_spdveherrvsmax_cpy)) >
              VSCtl_spdErrVSMaxSDyn_HysHi_C)
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_DECONF____0;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_TRANSITOIRE:
          if (((SInt16)DDS_M_ABS((SInt32)vsmax_vsctl_spdveherrvsmax_cpy)) <
              VSCtl_spdErrVSMaxSDyn_HysLo_C)
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT_n = (UInt8)
              VSMAX_Re002tev_Sf_IN_CONF____0;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
        VSMAX_Re002tev_Sf_IN_INIT_p;
      VSCtl_bDynCtlSpdVehVSMax = VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE;
      break;
    }

    switch (vsmax_re002tev_sf_dwork.is_LISSAGE_CONTROLE_VITESSE)
          {
     case VSMAX_Re002tev_Sf_IN_INIT_p:
      if (vsmax_vsctl_stctl_avehvsmax_cpy == VSCTL_STCTL_AVEHVSMAX_CONTROLE)
      {
        vsmax_re002tev_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NON_INIT;
        vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
          VSMAX_Re002tev_Sf_IN_BARYCENTRE_IN_1;
        vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = VSMAX_100_BIN7;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_NON_INIT:
      if (vsmax_vsctl_stctl_avehvsmax_cpy != VSCTL_STCTL_AVEHVSMAX_CONTROLE)
      {
        vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_e;
        vsmax_re002tev_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
          VSMAX_Re002tev_Sf_IN_INIT_p;
        vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = VSMAX_100_BIN7;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_NON_INIT)
      {
         case VSMAX_Re002tev_Sf_IN_BARYCENTRE_IN_1:
          if (VSCtl_bDynCtlSpdVehVSMax == VSCTL_BDYNCTLSPDVEHVSMAX_STABILISE)
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
              VSMAX_Re002tev_Sf_IN_CONF;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_BARYCENTRE_IN_2:
          if (VSCtl_bDynCtlSpdVehVSMax == VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE)
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
              VSMAX_Re002tev_Sf_IN_DECONF;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_CONF:
          if (VSCtl_bDynCtlSpdVehVSMax == VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE)
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
              VSMAX_Re002tev_Sf_IN_DECONF;

          }
          else if ((VSCtl_bDynCtlSpdVehVSMax ==
                      VSCTL_BDYNCTLSPDVEHVSMAX_STABILISE) &&
                     (vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n <= 0))
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
              VSMAX_Re002tev_Sf_IN_BARYCENTRE_IN_2;
            vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = 0U;

          }
          else
          {
            vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = (UInt16)DDS_M_MAX
              (vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n -
               VSCtl_tiCfm_rSDynCtlVSMax_C, 0);
          }
          break;

         case VSMAX_Re002tev_Sf_IN_DECONF:
          if ((VSCtl_bDynCtlSpdVehVSMax == VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE)
              && (vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n >=
                  VSMAX_100_BIN7))
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
              VSMAX_Re002tev_Sf_IN_BARYCENTRE_IN_1;
            vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = VSMAX_100_BIN7;

          }
          else if (VSCtl_bDynCtlSpdVehVSMax ==
                     VSCTL_BDYNCTLSPDVEHVSMAX_STABILISE)
          {
            vsmax_re002tev_sf_dwork.is_NON_INIT = (UInt8)
              VSMAX_Re002tev_Sf_IN_CONF;

          }
          else
          {
            vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = (UInt16)
              ((vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n +
                VSCtl_tiDiCfm_rCtlTDynVSMax_C) < VSMAX_100_BIN7 ?
               vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n +
               VSCtl_tiDiCfm_rCtlTDynVSMax_C : (SInt32)VSMAX_100_BIN7);
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
        VSMAX_Re002tev_Sf_IN_INIT_p;
      vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = VSMAX_100_BIN7;
      break;
    }
  }

  VSCtl_rSpdVehCtlVSMaxDyn = DDS_M_MIN(vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n,
    VSCTL_RSPDVEHCTLVSMAXDYN_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F52231_Determiner_Mode_Controle_Vitesse_Vehicule*/


  stack_data_s16_0 = vsmax_re002tev_sf_delay_6;

  stack_data_s16_1 = vsmax_re002tev_sf_delay_7;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F52221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.18.2 */

  if (vsmax_re002tev_sf_dwork.is_active_c216_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c216_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c216_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_MODES_CALCUL_GABARITS_ACCELERATION_VEHICULE;
    vsmax_re002tev_sf_dwork.is_active_ACCEL = 1U;
    vsmax_re002tev_sf_dwork.is_ACCEL = (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_p;
    VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_ARRET;
    vsmax_re002tev_sf_dwork.is_active_JERK_MAX = 1U;
    vsmax_re002tev_sf_dwork.is_JERK_MAX = (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_p;
    VSCtl_stSatJrkVehMaxVSMax = VSCTL_STSATJRKVEHMAXVSMAX_ARRET;
    vsmax_re002tev_sf_dwork.is_active_JERK_MIN = 1U;
    vsmax_re002tev_sf_dwork.is_JERK_MIN = (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_p;
    VSCtl_stSatJrkVehMinVSMax = VSCTL_STSATJRKVEHMINVSMAX_ARRET;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_ACCEL)
          {
     case VSMAX_Re002tev_Sf_IN_ARRET_p:
      if ((vsmax_vsctl_stctl_avehvsmax_cpy != VSCTL_STCTL_AVEHVSMAX_ARRET) &&
          (VSCtl_bDeacCdnAStSatMinVSMax_C == VSMAX_Re002tev_Sf_VRAI_f))
      {
        vsmax_re002tev_sf_dwork.is_ACCEL = (UInt8)
          VSMAX_Re002tev_Sf_IN_CONTROLE_p;
        vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_EFFECTIF____0;
        VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_EFFECTIF_30;

      }
      else if ((vsmax_vsctl_stctl_avehvsmax_cpy != VSCTL_STCTL_AVEHVSMAX_ARRET)
      &&
                 (VSCtl_bDeacCdnAStSatMinVSMax_C == VSMAX_Re002tev_Sf_FAUX_h3))
      {
        vsmax_re002tev_sf_dwork.is_ACCEL = (UInt8)
          VSMAX_Re002tev_Sf_IN_CONTROLE_p;
        vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_INIT_o;
        VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_INIT_30;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_CONTROLE_p:
      if (vsmax_vsctl_stctl_avehvsmax_cpy == VSCTL_STCTL_AVEHVSMAX_ARRET)
      {
        vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_ko;
        vsmax_re002tev_sf_dwork.is_ACCEL = (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_p;
        VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_ARRET;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_CONTROLE)
      {
         case VSMAX_Re002tev_Sf_IN_ACTIVATION:
          if ((VSCtl_stSatAVehMinVSMaxMod_C !=
               VSCTL_STSATAVEHMINVSMAXMOD_C_COMPLET)
               || (vsmax_vsctl_stvsmaxextd_cpy !=
               VSCTL_STVSMAXEXTD_AE))
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_NON_EFFECTIF____0;
            VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_NON_EFFECTIF_30;

          }
          else if (((VSCtl_aVehReq_swc_in <= stack_data_s16_0)
                      && (VSCtl_aVehReq_swc_in >=
                          stack_data_s16_1))
                          &&
                     (vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_AE))
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_EFFECTIF____0;
            VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_EFFECTIF_30;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_EFFECTIF____0:
          if (vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE)
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_NON_EFFECTIF____0;
            VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_NON_EFFECTIF_30;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_INIT_o:
          vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
            VSMAX_Re002tev_Sf_IN_NON_EFFECTIF____0;
          VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_NON_EFFECTIF_30;
          break;

         case VSMAX_Re002tev_Sf_IN_NON_EFFECTIF____0:
          if ((VSCtl_stSatAVehMinVSMaxMod_C ==
               VSCTL_STSATAVEHMINVSMAXMOD_C_COMPLET)
               && (vsmax_vsctl_stvsmaxextd_cpy ==
               VSCTL_STVSMAXEXTD_AE))
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_ACTIVATION;
            VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_ACTIVATION_30;

          }
          else if ((((VSCtl_stSatAVehMinVSMaxMod_C !=
                        VSCTL_STSATAVEHMINVSMAXMOD_C_COMPLET)
                        && (VSCtl_aVehReq_swc_in <=
            stack_data_s16_0))
            && (VSCtl_aVehReq_swc_in >=
                       stack_data_s16_1)) &&
                     (vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_AE))
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE = (UInt8)
              VSMAX_Re002tev_Sf_IN_EFFECTIF____0;
            VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_EFFECTIF_30;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_ACCEL = (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_p;
      VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_ARRET;
      break;
    }

    switch (vsmax_re002tev_sf_dwork.is_JERK_MAX)
          {
     case VSMAX_Re002tev_Sf_IN_ARRET_p:
      if (vsmax_vsctl_stctl_avehvsmax_cpy != VSCTL_STCTL_AVEHVSMAX_ARRET)
      {
        vsmax_re002tev_sf_dwork.is_JERK_MAX = (UInt8)
          VSMAX_Re002tev_Sf_IN_CONTROLE_p;
        vsmax_re002tev_sf_dwork.is_CONTROLE_p = (UInt8)
          VSMAX_Re002tev_Sf_IN_NON_EFFECTIF_d;
        VSCtl_stSatJrkVehMaxVSMax = VSCTL_STSATJRKVEHMAXVSMAX_NON_EFFECTIF;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_CONTROLE_p:
      if (vsmax_vsctl_stctl_avehvsmax_cpy == VSCTL_STCTL_AVEHVSMAX_ARRET)
      {
        vsmax_re002tev_sf_dwork.is_CONTROLE_p = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_ko;
        vsmax_re002tev_sf_dwork.is_JERK_MAX = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_p;
        VSCtl_stSatJrkVehMaxVSMax = VSCTL_STSATJRKVEHMAXVSMAX_ARRET;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_CONTROLE_p)
      {
         case VSMAX_Re002tev_Sf_IN_EFFECTIF_n:
          if (vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE)
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE_p = (UInt8)
              VSMAX_Re002tev_Sf_IN_NON_EFFECTIF_d;
            VSCtl_stSatJrkVehMaxVSMax = VSCTL_STSATJRKVEHMAXVSMAX_NON_EFFECTIF;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_NON_EFFECTIF_d:
          if (vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_AE)
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE_p = (UInt8)
              VSMAX_Re002tev_Sf_IN_EFFECTIF_n;
            VSCtl_stSatJrkVehMaxVSMax = VSCTL_STSATJRKVEHMAXVSMAX_EFFECTIF;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_JERK_MAX = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_p;
      VSCtl_stSatJrkVehMaxVSMax = VSCTL_STSATJRKVEHMAXVSMAX_ARRET;
      break;
    }

    switch (vsmax_re002tev_sf_dwork.is_JERK_MIN)
          {
     case VSMAX_Re002tev_Sf_IN_ARRET_p:
      if (vsmax_vsctl_stctl_avehvsmax_cpy != VSCTL_STCTL_AVEHVSMAX_ARRET)
      {
        vsmax_re002tev_sf_dwork.is_JERK_MIN = (UInt8)
          VSMAX_Re002tev_Sf_IN_CONTROLE_p;
        vsmax_re002tev_sf_dwork.is_CONTROLE_p4 = (UInt8)
          VSMAX_Re002tev_Sf_IN_EFFECTIF_n;
        VSCtl_stSatJrkVehMinVSMax = VSCTL_STSATJRKVEHMINVSMAX_EFFECTIF;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_CONTROLE_p:
      if (vsmax_vsctl_stctl_avehvsmax_cpy == VSCTL_STCTL_AVEHVSMAX_ARRET)
      {
        vsmax_re002tev_sf_dwork.is_CONTROLE_p4 = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_ko;
        vsmax_re002tev_sf_dwork.is_JERK_MIN = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_p;
        VSCtl_stSatJrkVehMinVSMax = VSCTL_STSATJRKVEHMINVSMAX_ARRET;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_CONTROLE_p4)
      {
         case VSMAX_Re002tev_Sf_IN_EFFECTIF_n:
          if (vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE)
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE_p4 = (UInt8)
              VSMAX_Re002tev_Sf_IN_NON_EFFECTIF_d;
            VSCtl_stSatJrkVehMinVSMax = VSCTL_STSATJRKVEHMINVSMAX_NON_EFFECTIF;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_NON_EFFECTIF_d:
          if (vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_AE)
          {
            vsmax_re002tev_sf_dwork.is_CONTROLE_p4 = (UInt8)
              VSMAX_Re002tev_Sf_IN_EFFECTIF_n;
            VSCtl_stSatJrkVehMinVSMax = VSCTL_STSATJRKVEHMINVSMAX_EFFECTIF;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_JERK_MIN = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_p;
      VSCtl_stSatJrkVehMinVSMax = VSCTL_STSATJRKVEHMINVSMAX_ARRET;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F52221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule*/

  VSMAX_F522221_Determiner_Saturations_Acceleration_Vehicule_Max(VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                                    vsmax_vsctl_spdveherrvsmax_cpy, /* BIN7 */
                                                                    vsmax_vsctl_stctl_avehvsmax_cpy /* Enum */);


  VSMAX_F522222_Determiner_Saturations_Acceleration_Vehicule_Min(VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                                    vsmax_vsctl_spdveherrvsmax_cpy, /* BIN7 */
                                                                    vsmax_vsctl_stctl_avehvsmax_cpy /* Enum */);


  VSMAX_F52223_Determiner_Saturations_Jerk_Vehicule(VSCtl_aVehCordVSLimReq_swc_in, /* BIN10 */
                                                    VSCtl_aVehReq_swc_in, /* BIN10 */
                                                    VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                                                    VSCtl_spdVeh_swc_in, /* BIN7 */
                                                    vsmax_vsctl_stctl_avehvsmax_cpy /* Enum */);


  VSMAX_F52224_Determiner_Gabarits_Acceleration_Vehicule(VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                            VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                            VSCtl_aVehReq_swc_in, /* BIN10 */
                                                            vsmax_vsctl_stctl_avehvsmax_cpy /* Enum */);

  VSMAX_F52232_Determiner_Consigne_Acceleration_Vehicule(VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                            vsmax_vsctl_spdveherrvsmax_cpy, /* BIN7 */
                                                            vsmax_vsctl_stctl_avehvsmax_cpy, /* Enum */
                                                            &vsmax_vsctl_avehvsmaxreq_cpy /* BIN10 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F524_autoriser_Consigne_Potentiel_Acceleration_Vehicule*/

  if (vsmax_re002tev_sf_dwork.is_active_c1_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c1_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c1_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_ENABLE_F523;
    vsmax_re002tev_sf_dwork.is_ENABLE_F523 = (UInt8)
      VSMAX_Re002tev_Sf_IN_PRESENT;
    vsctl_bacv_calcul = VSMAX_Re002tev_Sf_VRAI_n;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_ENABLE_F523)
          {
     case VSMAX_Re002tev_Sf_IN_ABSENT:
      if ((Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
      ||
          (VSCtl_bCtlCmdPTTqCf_SC == VSMAX_Re002tev_Sf_VRAI_n))
      {
        vsmax_re002tev_sf_dwork.is_ENABLE_F523 = (UInt8)
          VSMAX_Re002tev_Sf_IN_PRESENT;
        vsctl_bacv_calcul = VSMAX_Re002tev_Sf_VRAI_n;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_PRESENT:
      if ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
      &&
          (VSCtl_bCtlCmdPTTqCf_SC == VSMAX_Re002tev_Sf_FAUX_l))
      {
        vsmax_re002tev_sf_dwork.is_ENABLE_F523 = (UInt8)
          VSMAX_Re002tev_Sf_IN_ABSENT;
        vsctl_bacv_calcul = VSMAX_Re002tev_Sf_FAUX_l;
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_ENABLE_F523 = (UInt8)
        VSMAX_Re002tev_Sf_IN_PRESENT;
      vsctl_bacv_calcul = VSMAX_Re002tev_Sf_VRAI_n;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F524_autoriser_Consigne_Potentiel_Acceleration_Vehicule*/


  if (DDS_TRUE==vsctl_bacv_calcul)
  {

    /* TAG_START_OF_STATEFLOW_FUNCTION: F5231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.57.1 */

    if (vsmax_re002tev_sf_dwork.is_active_c63_VSMAX_Re002tev_Sf == 0)
    {
      vsmax_re002tev_sf_dwork.is_active_c63_VSMAX_Re002tev_Sf = 1U;
      vsmax_re002tev_sf_dwork.is_c63_VSMAX_Re002tev_Sf = (UInt8)
        VSMAX_Re002tev_Sf_IN_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE;
      vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE =
        (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_d;
      vsmax_vsctl_bctl_avehpotvsmax_cpy = VSCTL_BCTL_AVEHPOTVSMAX_ARRET;
      VSCtl_bAcvFil_aVehPotVSMax = VSMAX_Re002tev_Sf_FAUX_g;

    }
    else
    {
      switch
        (vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE)
      {
       case VSMAX_Re002tev_Sf_IN_ARRET_d:
        if (((((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
               (vsmax_vsctl_stctl_avehvsmax_cpy == VSCTL_STCTL_AVEHVSMAX_CONTROLE))
               &&
              (vsmax_vsctl_spdveherrvsmax_cpy < VSCtl_spdEMaxAVehP_HysLoP_C))
              &&
             (vsmax_vsctl_spdveherrvsmax_cpy > VSCtl_spdEMaxAVehP_HysLoN_C)) &&
            ((((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)
            &&
               (((vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_AE) &&
                 (VSCtl_bAcvPotVSMaxNGear_AE_C == VSMAX_Re002tev_Sf_VRAI_fn))
                 ||
                ((vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_ANE) &&
                 (VSCtl_bAcvPotVSMaxNGear_ANE_C == VSMAX_Re002tev_Sf_VRAI_fn))))

              || ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_COUPLE)
              &&
                  (((vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_AE) &&
                    (VSCtl_bAcvPotVSMaxTq_AE_C == VSMAX_Re002tev_Sf_VRAI_fn))
                    ||
                   ((vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_ANE) &&
                    (VSCtl_bAcvPotVSMaxTq_ANE_C == VSMAX_Re002tev_Sf_VRAI_fn)))))

             || ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
             &&
                 (((vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_ANE) &&
                   (VSCtl_bAcvPotVSMaxPed_AE_C == VSMAX_Re002tev_Sf_VRAI_fn))
                   ||
                  ((vsmax_vsctl_stvsmaxextd_cpy == VSCTL_STVSMAXEXTD_ANE) &&
                   (VSCtl_bAcvPotVSMaxPed_ANE_C == VSMAX_Re002tev_Sf_VRAI_fn))))))
        {
          vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE
            = (UInt8)VSMAX_Re002tev_Sf_IN_CONTROLE_m;
          vsmax_vsctl_bctl_avehpotvsmax_cpy = VSCTL_BCTL_AVEHPOTVSMAX_CONTROLE;
        }
        break;

       case VSMAX_Re002tev_Sf_IN_CONTROLE_m:
        if (((((VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL) ||
               (vsmax_vsctl_stctl_avehvsmax_cpy != VSCTL_STCTL_AVEHVSMAX_CONTROLE))
               ||
              (vsmax_vsctl_spdveherrvsmax_cpy > VSCtl_spdEMaxAVehP_HysHiP_C))
              ||
             (vsmax_vsctl_spdveherrvsmax_cpy < VSCtl_spdEMaxAVehP_HysHiN_C)) ||
            ((((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)
            &&
               (((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE) ||
                 (VSCtl_bAcvPotVSMaxNGear_AE_C == VSMAX_Re002tev_Sf_FAUX_g))
                 &&
                ((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_ANE) ||
                 (VSCtl_bAcvPotVSMaxNGear_ANE_C == VSMAX_Re002tev_Sf_FAUX_g))))
                 ||
              ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_COUPLE)
              &&
               (((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE) ||
                 (VSCtl_bAcvPotVSMaxTq_AE_C == VSMAX_Re002tev_Sf_FAUX_g))
                 &&
                ((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_ANE) ||
                 (VSCtl_bAcvPotVSMaxTq_ANE_C == VSMAX_Re002tev_Sf_FAUX_g)))))
                 ||
             ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
             &&
              (((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE) ||
                (VSCtl_bAcvPotVSMaxPed_AE_C == VSMAX_Re002tev_Sf_FAUX_g))
                &&
               ((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_ANE) ||
                (VSCtl_bAcvPotVSMaxPed_ANE_C == VSMAX_Re002tev_Sf_FAUX_g))))))
        {
          vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE
            = (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_d;
          vsmax_vsctl_bctl_avehpotvsmax_cpy = VSCTL_BCTL_AVEHPOTVSMAX_ARRET;
          VSCtl_bAcvFil_aVehPotVSMax = VSMAX_Re002tev_Sf_FAUX_g;

        }
        else
        {
          VSCtl_bAcvFil_aVehPotVSMax = VSMAX_Re002tev_Sf_VRAI_fn;
        }
        break;

       default:
        vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE
          = (UInt8)VSMAX_Re002tev_Sf_IN_ARRET_d;
        vsmax_vsctl_bctl_avehpotvsmax_cpy = VSCTL_BCTL_AVEHPOTVSMAX_ARRET;
        VSCtl_bAcvFil_aVehPotVSMax = VSMAX_Re002tev_Sf_FAUX_g;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F5231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule*/

  VSMAX_F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(vsmax_vsctl_bctl_avehpotvsmax_cpy, /* Enum */
                                                                    vsmax_vsctl_spdveherrvsmax_cpy, /* BIN7 */
                                                                    &vsmax_vsctl_avehpotvsmaxreq_cpy /* BIN4 */);


  VSMAX_F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp(vsmax_vsctl_bctl_avehpotvsmax_cpy, /* Enum */
                                                                    vsmax_vsctl_spdveherrvsmax_cpy, /* BIN7 */
                                                                    &vsmax_vsctl_rctltqwhlptpotvsmax_cpy /* BIN10 */);


  VSMAX_F5234_Determiner_Temps_Confirmation_Changement_Rapport(vsmax_vsctl_avehpotvsmaxreq_cpy, /* BIN10 */
                                                                vsmax_vsctl_bctl_avehpotvsmax_cpy, /* Enum */
                                                                VSCtl_spdVeh_swc_in, /* BIN7 */
                                                                vsmax_vsctl_spdveherrvsmax_cpy, /* BIN7 */
                                                                &vsmax_vsctl_ticfmsdwnvsmaxreq_cpy, /* DEC2 */
                                                                &vsmax_vsctl_ticfmsupvsmaxreq_cpy /* DEC2 */);

  }



  /* TAG_START_OF_STATEFLOW_FUNCTION: F5111_Determiner_Condition_Configuration_Fonction*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.33.0 */

  if (vsmax_re002tev_sf_dwork.is_active_c33_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c33_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c33_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_CONDITION_CONFIGURATION_FONCTION;
    vsmax_re002tev_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION = (UInt8)
      VSMAX_Re002tev_Sf_IN_VRAI;
    VSCtl_bCfVSMax = VSMAX_Re002tev_Sf_VRAI;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION)
        {
     case VSMAX_Re002tev_Sf_IN_FAUX:
      if ((VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL)
      || (((Ext_bVSMaxfCf_swc_in
             != EXT_BVSMAXFCF_PRESENT) && (Ext_bVSMaxpCf_swc_in !=
             EXT_BVSMAXPCF_PRESENT))
             && (Ext_bVSMaxsCf_swc_in != EXT_BVSMAXSCF_PRESENT)))
      {
        vsmax_re002tev_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION = (UInt8)
          VSMAX_Re002tev_Sf_IN_VRAI;
        VSCtl_bCfVSMax = VSMAX_Re002tev_Sf_VRAI;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_VRAI:
      if (((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
           (ECU_bAuthVSCtlIni_swc_in == VSMAX_Re002tev_Sf_VRAI))
           && (((Ext_bVSMaxfCf_swc_in ==
             EXT_BVSMAXFCF_PRESENT)
             || (Ext_bVSMaxpCf_swc_in == EXT_BVSMAXPCF_PRESENT))
           || (Ext_bVSMaxsCf_swc_in == EXT_BVSMAXSCF_PRESENT)))
      {
        vsmax_re002tev_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION = (UInt8)
          VSMAX_Re002tev_Sf_IN_FAUX;
        VSCtl_bCfVSMax = VSMAX_Re002tev_Sf_FAUX;
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION = (UInt8)
        VSMAX_Re002tev_Sf_IN_VRAI;
      VSCtl_bCfVSMax = VSMAX_Re002tev_Sf_VRAI;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F5111_Determiner_Condition_Configuration_Fonction*/

  VSMAX_F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite(Ext_bKeyOff_swc_in,
                                                                                    FRM_bDeacIrvVSMax_swc_in,
                                                                                    FRM_bDeacRvVSMax_swc_in);


  VSMAX_F51212_Determiner_Conditions_Maintenance_Frein_Las();


  VSMAX_F51223_Determiner_Condition_Conditions_Maintenance_Fonction(FRM_bInhVSMax_swc_in);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F5141_Determiner_Diagnostic_Fonctionnel_BVMp*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.46.0 */

  if (vsmax_re002tev_sf_dwork.is_active_c184_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c184_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c184_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_DIAGNOSTIC_BVVp;
    vsmax_re002tev_sf_dwork.is_active_DIAGNOSTIC = 1U;
    vsmax_re002tev_sf_dwork.is_DIAGNOSTIC = (UInt8)
      VSMAX_Re002tev_Sf_IN_ARRET_k;
    vsmax_vsctl_bmonrunvsmaxp_cpy = VSMAX_Re002tev_Sf_FAUX_j;
    vsmax_vsctl_bdgovsmaxp_cpy = VSMAX_Re002tev_Sf_FAUX_j;
    VSCtl_bDeacVSMaxp = VSMAX_Re002tev_Sf_FAUX_j;
    vsmax_re002tev_sf_dwork.is_active_MEMOIRE = 1U;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_DIAGNOSTIC)
      {
     case VSMAX_Re002tev_Sf_IN_ARRET_k:
      if (VSCtl_stMonVSMax == VSCTL_STMONVSMAX_NOMINAL)
      {
        vsmax_re002tev_sf_dwork.is_DIAGNOSTIC = (UInt8)
          VSMAX_Re002tev_Sf_IN_MARCHE_e;
        vsmax_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
          VSMAX_Re002tev_Sf_IN_FAUX_b;
        vsmax_vsctl_bmonrunvsmaxp_cpy = VSMAX_Re002tev_Sf_VRAI_au;
        vsmax_vsctl_bdgovsmaxp_cpy = VSMAX_Re002tev_Sf_FAUX_j;
        VSCtl_bDeacVSMaxp = VSMAX_Re002tev_Sf_FAUX_j;
      }
      break;

     case VSMAX_Re002tev_Sf_IN_MARCHE_e:
      if (VSCtl_stMonVSMax != VSCTL_STMONVSMAX_NOMINAL)
      {
        vsmax_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_k;
        vsmax_re002tev_sf_dwork.is_DIAGNOSTIC = (UInt8)
          VSMAX_Re002tev_Sf_IN_ARRET_k;
        vsmax_vsctl_bmonrunvsmaxp_cpy = VSMAX_Re002tev_Sf_FAUX_j;
        vsmax_vsctl_bdgovsmaxp_cpy = VSMAX_Re002tev_Sf_FAUX_j;
        VSCtl_bDeacVSMaxp = VSMAX_Re002tev_Sf_FAUX_j;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_MARCHE_g)
      {
         case VSMAX_Re002tev_Sf_IN_FAUX_b:
          if ((((UInt32)Ext_spdVehVSMaxPrmaReq_swc_in) << 7) != ((UInt32)
               vsmax_re002tev_sf_b.VSCtl_spdVehVSMaxPrmaReqPrev_n))
          {
            vsmax_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
              VSMAX_Re002tev_Sf_IN_VRAI_i;
            vsmax_vsctl_bmonrunvsmaxp_cpy = VSMAX_Re002tev_Sf_VRAI_au;
            vsmax_vsctl_bdgovsmaxp_cpy = VSMAX_Re002tev_Sf_VRAI_au;
            VSCtl_bDeacVSMaxp = VSMAX_Re002tev_Sf_VRAI_au;
          }
          break;
        }
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_DIAGNOSTIC = (UInt8)
        VSMAX_Re002tev_Sf_IN_ARRET_k;
      vsmax_vsctl_bmonrunvsmaxp_cpy = VSMAX_Re002tev_Sf_FAUX_j;
      vsmax_vsctl_bdgovsmaxp_cpy = VSMAX_Re002tev_Sf_FAUX_j;
      VSCtl_bDeacVSMaxp = VSMAX_Re002tev_Sf_FAUX_j;
      break;
    }

    vsmax_re002tev_sf_b.VSCtl_spdVehVSMaxPrmaReqPrev_n = (UInt16)
      (Ext_spdVehVSMaxPrmaReq_swc_in << 7);
  }

  VSCtl_spdVehVSMaxPrmaReqPrev = DDS_M_MIN
    (vsmax_re002tev_sf_b.VSCtl_spdVehVSMaxPrmaReqPrev_n,
     VSCTL_SPDVEHVSMAXPRMAREQPREV_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F5141_Determiner_Diagnostic_Fonctionnel_BVMp*/

  VSMAX_F5151_Determiner_Conditions_Maintenance_Bvv(VSCtl_stDeacVSCtlInfo_swc_in, /* BIN0 */
                                                    &vsmax_vsctl_stdeacvsmaxreq_no1_cpy, /* BIN0 */
                                                    &vsmax_vsctl_stdeacvsmaxreq_no2_cpy /* BIN0 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F5152_Determiner_Conditions_Capture_Maintenance_BVV*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2272.FR.49.0 */

  if (vsmax_re002tev_sf_dwork.is_active_c44_VSMAX_Re002tev_Sf == 0)
  {
    vsmax_re002tev_sf_dwork.is_active_c44_VSMAX_Re002tev_Sf = 1U;
    vsmax_re002tev_sf_dwork.is_c44_VSMAX_Re002tev_Sf = (UInt8)
      VSMAX_Re002tev_Sf_IN_CONDITION_CAPTURE_MAINTENANCE_BVV;
    vsmax_re002tev_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 = 1U;
    vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 = (UInt8)
      VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT;
    vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o = (UInt8)
      VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
    vsmax_strec_stdeacvsmaxreq1_cpy = VSCTL_STREC_STDEACVSMAXREQ1_ATTENTE;
    VSCtl_tiHld_stDeacVSMaxReq1 = VSCtl_tiHld_stDeacVSMaxReq1_C;
    vsmax_re002tev_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 = 1U;
    vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 = (UInt8)
      VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT;
    vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT = (UInt8)
      VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
    vsmax_strec_stdeacvsmaxreq2_cpy = VSCTL_STREC_STDEACVSMAXREQ2_ATTENTE;
    VSCtl_tiHld_stDeacVSMaxReq2 = VSCtl_tiHld_stDeacVSMaxReq2_C;
    vsmax_re002tev_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_BVV = 1U;
    vsmax_re002tev_sf_dwork.is_active_MEMOIRES = 1U;

  }
  else
  {
    switch (vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no1)
          {
     case VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT:
      if (Afts_bRst_stDeacVSMaxReq1_swc_in == VSMAX_Re002tev_Sf_VRAI_an)
      {
        vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_i;
        vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 =
          (UInt8)VSMAX_Re002tev_Sf_IN_RESET;
        vsmax_strec_stdeacvsmaxreq1_cpy = VSCTL_STREC_STDEACVSMAXREQ1_RESET;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o)
          {
         case VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION:
          if (((VSCtl_stVSMaxPrev == VSCTL_STVSMAXPREV_ANE) ||
               (VSCtl_stVSMaxPrev == VSCTL_STVSMAXPREV_AE)) &&
              ((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_ANE) &&
               (vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE)))
          {
            vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o = (UInt8)
              VSMAX_Re002tev_Sf_IN_CAPTURE;
            vsmax_strec_stdeacvsmaxreq1_cpy = VSCTL_STREC_STDEACVSMAXREQ1_CAPTURE;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_CAPTURE:
          if (VSCtl_tiHld_stDeacVSMaxReq1 == 0)
          {
            vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o = (UInt8)
              VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
            vsmax_strec_stdeacvsmaxreq1_cpy = VSCTL_STREC_STDEACVSMAXREQ1_ATTENTE;
            VSCtl_tiHld_stDeacVSMaxReq1 = VSCtl_tiHld_stDeacVSMaxReq1_C;

          }
          else
          {
            VSCtl_tiHld_stDeacVSMaxReq1 = (UInt16)DDS_M_MAX
              (VSCtl_tiHld_stDeacVSMaxReq1 - 1, 0);
          }
          break;
        }
      }
      break;

     case VSMAX_Re002tev_Sf_IN_RESET:
      if (Afts_bRst_stDeacVSMaxReq1_swc_in == VSMAX_Re002tev_Sf_FAUX_ma)
      {
        vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 =
          (UInt8)VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT;
        vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o = (UInt8)
          VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
        vsmax_strec_stdeacvsmaxreq1_cpy = VSCTL_STREC_STDEACVSMAXREQ1_ATTENTE;
        VSCtl_tiHld_stDeacVSMaxReq1 = VSCtl_tiHld_stDeacVSMaxReq1_C;
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 =
        (UInt8)VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT;
      vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o = (UInt8)
        VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
      vsmax_strec_stdeacvsmaxreq1_cpy = VSCTL_STREC_STDEACVSMAXREQ1_ATTENTE;
      VSCtl_tiHld_stDeacVSMaxReq1 = VSCtl_tiHld_stDeacVSMaxReq1_C;
      break;
    }

    switch (vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no2)
      {
     case VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT:
      if (Afts_bRst_stDeacVSMaxReq2_swc_in == VSMAX_Re002tev_Sf_VRAI_an)
      {
        vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT = (UInt8)
          VSMAX_Re002tev_Sf_IN_NO_ACTIVE_CHILD_i;
        vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 =
          (UInt8)VSMAX_Re002tev_Sf_IN_RESET;
        vsmax_strec_stdeacvsmaxreq2_cpy = VSCTL_STREC_STDEACVSMAXREQ2_RESET;

      }
      else
      {
        switch (vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT)
      {
         case VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION:
          if ((((VSCtl_stVSMaxPrev == VSCTL_STVSMAXPREV_ANE) ||
                (VSCtl_stVSMaxPrev == VSCTL_STVSMAXPREV_AE)) &&
               ((vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_ANE) &&
                (vsmax_vsctl_stvsmaxextd_cpy != VSCTL_STVSMAXEXTD_AE))) &&
              (VSCtl_bEnaDeacVSMaxReq_no2 == VSMAX_Re002tev_Sf_VRAI_an))
          {
            vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT = (UInt8)
              VSMAX_Re002tev_Sf_IN_CAPTURE;
            vsmax_strec_stdeacvsmaxreq2_cpy = VSCTL_STREC_STDEACVSMAXREQ2_CAPTURE;
          }
          break;

         case VSMAX_Re002tev_Sf_IN_CAPTURE:
          if (VSCtl_tiHld_stDeacVSMaxReq2 == 0)
          {
            vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT = (UInt8)
              VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
            vsmax_strec_stdeacvsmaxreq2_cpy = VSCTL_STREC_STDEACVSMAXREQ2_ATTENTE;
            VSCtl_tiHld_stDeacVSMaxReq2 = VSCtl_tiHld_stDeacVSMaxReq2_C;

          }
          else
          {
            VSCtl_tiHld_stDeacVSMaxReq2 = (UInt16)DDS_M_MAX
              (VSCtl_tiHld_stDeacVSMaxReq2 - 1, 0);
          }
          break;
        }
      }
      break;

     case VSMAX_Re002tev_Sf_IN_RESET:
      if (Afts_bRst_stDeacVSMaxReq2_swc_in == VSMAX_Re002tev_Sf_FAUX_ma)
      {
        vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 =
          (UInt8)VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT;
        vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT = (UInt8)
          VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
        vsmax_strec_stdeacvsmaxreq2_cpy = VSCTL_STREC_STDEACVSMAXREQ2_ATTENTE;
        VSCtl_tiHld_stDeacVSMaxReq2 = VSCtl_tiHld_stDeacVSMaxReq2_C;
      }
      break;

     default:
      vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 =
        (UInt8)VSMAX_Re002tev_Sf_IN_FONCTIONNEMENT;
      vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT = (UInt8)
        VSMAX_Re002tev_Sf_IN_ATTENTE_ACTIVATION;
      vsmax_strec_stdeacvsmaxreq2_cpy = VSCTL_STREC_STDEACVSMAXREQ2_ATTENTE;
      VSCtl_tiHld_stDeacVSMaxReq2 = VSCtl_tiHld_stDeacVSMaxReq2_C;
      break;
    }

    VSCtl_bRec_stDeacVSMaxReq = (vsmax_strec_stdeacvsmaxreq1_cpy ==
      VSCTL_STREC_STDEACVSMAXREQ1_CAPTURE)
      || (vsmax_strec_stdeacvsmaxreq2_cpy ==
      VSCTL_STREC_STDEACVSMAXREQ2_CAPTURE)?DDS_TRUE:DDS_FALSE;
    VSCtl_stVSMaxPrev = vsmax_vsctl_stvsmaxextd_cpy;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F5152_Determiner_Conditions_Capture_Maintenance_BVV*/


  vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input_p =
    vsmax_re002tev_sf_delay_9;

  vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input_g =
    vsmax_re002tev_sf_delay_10;

VSMAX_F5153_Determiner_Contexte_Maintenance_Bvv(AccP_rAccP_swc_in, /* BIN7 */
                                                    Ext_dstVehTotMes_swc_in, /* BIN0 */
                                                    CoPt_noEgdGearCordIt_swc_in, /* Enum */
                                                    CoPt_posnLev_swc_in, /* Enum */
                                                    VSCtl_aVeh_swc_in, /* BIN10 */
                                                    vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input_g, /* BIN10 */
                                                    VSCtl_jrkVeh_swc_in, /* BIN7 */
                                                    VSCtl_rSlop_swc_in, /* BIN7 */
                                                    VSCtl_spdVeh_swc_in, /* BIN7 */
                                                    vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input_p, /* BIN7 */
                                                    vsmax_vsctl_stvsmaxextd_cpy, /* Enum */
                                                    &vsmax_vsctl_avehvsmaxreq_deacvsmax_cpy, /* BIN10 */
                                                    &vsmax_vsctl_aveh_deacvsmax_cpy, /* BIN10 */
                                                    &vsmax_vsctl_dstvehtotmes_deacvsmax_cpy, /* BIN0 */
                                                    &vsmax_vsctl_jrkvehreqdeacvsmax_cpy, /* BIN7 */
                                                    &vsmax_vsctl_jrkveh_deacvsmax_cpy, /* BIN7 */
                                                    &vsmax_vsctl_nogearegd_deacvsmax_cpy, /* Enum */
                                                    &vsmax_vsctl_posngbxdeacvsmax_cpy, /* Enum */
                                                    &vsmax_vsctl_raccp_deacvsmax_cpy, /* BIN7 */
                                                    &vsmax_vsctl_rslop_deacvsmax_cpy, /* BIN7 */
                                                    &vsmax_vsctl_spdvehreqdeacvsmax_cpy, /* BIN7 */
                                                    &vsmax_vsctl_spdveh_deacvsmax_cpy, /* BIN7 */
                                                    &vsmax_vsctl_stvsmaxprev_deacvsmax_cpy, /* Enum */
                                                    &vsmax_vsctl_stvsmax_deacvsmax_cpy /* Enum */);

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_dstVehTotMes_DeacVSMax_swc_out = vsmax_vsctl_dstvehtotmes_deacvsmax_cpy;

  *VSCtl_aVehPotVSMaxReq_swc_out = vsmax_vsctl_avehpotvsmaxreq_cpy;

  *VSCtl_aVehVSMaxReq_swc_out = vsmax_vsctl_avehvsmaxreq_cpy;

  *VSCtl_aVehVSMaxReq_DeacVSMax_swc_out = vsmax_vsctl_avehvsmaxreq_deacvsmax_cpy;

  *VSCtl_aVeh_DeacVSMax_swc_out = vsmax_vsctl_aveh_deacvsmax_cpy;

  *VSCtl_jrkVehReqDeacVSMax_swc_out = vsmax_vsctl_jrkvehreqdeacvsmax_cpy;

  *VSCtl_jrkVeh_DeacVSMax_swc_out = vsmax_vsctl_jrkveh_deacvsmax_cpy;

  *VSCtl_rSlop_DeacVSMax_swc_out = vsmax_vsctl_rslop_deacvsmax_cpy;

  *VSCtl_spdVehErrVSMax_swc_out = vsmax_vsctl_spdveherrvsmax_cpy;

  *VSCtl_rAccP_DeacVSMax_swc_out = vsmax_vsctl_raccp_deacvsmax_cpy;

  *VSCtl_rCtlTqWhlPTPotVSMax_swc_out = vsmax_vsctl_rctltqwhlptpotvsmax_cpy;

  *VSCtl_spdVehReqDeacVSMax_swc_out = vsmax_vsctl_spdvehreqdeacvsmax_cpy;

  *VSCtl_spdVehVSMaxReq_swc_out = vsmax_vsctl_spdvehvsmaxreq_cpy;

  *VSCtl_spdVeh_DeacVSMax_swc_out = vsmax_vsctl_spdveh_deacvsmax_cpy;

  *VSCtl_stDeacVSMaxReq_no1_swc_out = vsmax_vsctl_stdeacvsmaxreq_no1_cpy;

  *VSCtl_stDeacVSMaxReq_no2_swc_out = vsmax_vsctl_stdeacvsmaxreq_no2_cpy;

  *VSCtl_tiCfmSdwnVSMaxReq_swc_out = vsmax_vsctl_ticfmsdwnvsmaxreq_cpy;

  *VSCtl_tiCfmSupVSMaxReq_swc_out = vsmax_vsctl_ticfmsupvsmaxreq_cpy;

  *VSCtl_noGearEgd_DeacVSMax_swc_out = vsmax_vsctl_nogearegd_deacvsmax_cpy;

  *VSCtl_bCtl_aVehPotVSMax_swc_out = vsmax_vsctl_bctl_avehpotvsmax_cpy;

  *VSCtl_bDgoVSMax_swc_out = vsmax_vsctl_bdgovsmax_cpy;

  *VSCtl_bDgoVSMaxp_swc_out = vsmax_vsctl_bdgovsmaxp_cpy;

  *VSCtl_bMonRunVSMax_swc_out = vsmax_vsctl_bmonrunvsmax_cpy;

  *VSCtl_bMonRunVSMaxp_swc_out = vsmax_vsctl_bmonrunvsmaxp_cpy;

  *VSCtl_posnGBxDeacVSMax_swc_out = vsmax_vsctl_posngbxdeacvsmax_cpy;

  *VSCtl_stCtl_aVehVSMax_swc_out = vsmax_vsctl_stctl_avehvsmax_cpy;

  *VSCtl_stRec_stDeacVSMaxReq1_swc_out = vsmax_strec_stdeacvsmaxreq1_cpy;

  *VSCtl_stRec_stDeacVSMaxReq2_swc_out = vsmax_strec_stdeacvsmaxreq2_cpy;

  *VSCtl_stVSMaxExtd_swc_out = vsmax_vsctl_stvsmaxextd_cpy;

  *VSCtl_stVSMaxPrev_DeacVSMax_swc_out = vsmax_vsctl_stvsmaxprev_deacvsmax_cpy;

  *VSCtl_stVSMax_DeacVSMax_swc_out = vsmax_vsctl_stvsmax_deacvsmax_cpy;


  vsmax_re002tev_sf_delay_0 = VSCtl_spdVehReqVSMaxf;

  vsmax_re002tev_sf_delay_1 = VSCtl_spdVehReqVSMaxp;

  vsmax_re002tev_sf_delay_2 = VSCtl_spdVehReqVSMaxs;

  vsmax_re002tev_sf_delay_3 = VSCtl_spdVehReqVSMaxc;

  vsmax_re002tev_sf_delay_4 = VSCtl_spdVehReqVSMaxc;

  vsmax_re002tev_sf_delay_5 = VSCtl_spdVehCrit;

  vsmax_re002tev_sf_delay_6 = VSCtl_aVehVSMaxReqSatMax;

  vsmax_re002tev_sf_delay_7 = VSCtl_aVehVSMaxReqSatMin;

  vsmax_re002tev_sf_delay_9 = vsmax_vsctl_spdvehvsmaxreq_cpy;

  vsmax_re002tev_sf_delay_10 = vsmax_vsctl_avehvsmaxreq_cpy;
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSMAX_Re002tev_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_DeacVSMax_swc_out,                 /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no1_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no2_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMaxp_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSMax_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMaxp_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehVSMaxReq_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSMaxReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSMax_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSMax_swc_out,                 /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSMaxReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSMax_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSMax_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxPrev_DeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSMaxReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMax_DeacVSMax_swc_out)

{
    VSMAX_Veh_Spd_Ctrl_Sl_Init(VSCtl_spdVehVSMaxReq_swc_out,
                                 VSCtl_spdVehErrVSMax_swc_out);

    VSMAX_Veh_Acc_Ctrl_Sl_Init(VSCtl_aVehPotVSMaxReq_swc_out, /* BIN10 */
                                 VSCtl_aVehVSMaxReq_swc_out, /* BIN10 */
                                 VSCtl_rCtlTqWhlPTPotVSMax_swc_out, /* BIN4 */
                                 VSCtl_tiCfmSdwnVSMaxReq_swc_out, /* DEC2 */
                                 VSCtl_tiCfmSupVSMaxReq_swc_out /* DEC2 */);

    VSMAX_Fct_Mode_Sl_Init(
                            VSCtl_aVehVSMaxReq_DeacVSMax_swc_out, /* BIN10 */
                            VSCtl_aVeh_DeacVSMax_swc_out, /* BIN10 */
                            VSCtl_dstVehTotMes_DeacVSMax_swc_out, /* BIN0 */
                            VSCtl_jrkVehReqDeacVSMax_swc_out, /* NBIN6 */
                            VSCtl_jrkVeh_DeacVSMax_swc_out, /* NBIN6 */
                            VSCtl_noGearEgd_DeacVSMax_swc_out,
                            VSCtl_posnGBxDeacVSMax_swc_out,
                            VSCtl_rAccP_DeacVSMax_swc_out, /* BIN7 */
                            VSCtl_rSlop_DeacVSMax_swc_out, /* BIN7 */
                            VSCtl_spdVehReqDeacVSMax_swc_out, /* BIN7 */
                            VSCtl_spdVeh_DeacVSMax_swc_out, /* BIN7 */
                            VSCtl_stDeacVSMaxReq_no1_swc_out, /* BIN0 */
                            VSCtl_stDeacVSMaxReq_no2_swc_out, /* BIN0 */
                            VSCtl_stVSMaxPrev_DeacVSMax_swc_out,
                            VSCtl_stVSMax_DeacVSMax_swc_out);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  vsmax_vsctl_dstvehtotmes_deacvsmax_cpy = *VSCtl_dstVehTotMes_DeacVSMax_swc_out;

  vsmax_vsctl_rctltqwhlptpotvsmax_cpy = *VSCtl_rCtlTqWhlPTPotVSMax_swc_out;

  vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input=0;
  vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input_p=0;
  vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input_g=0;
  vsmax_re002tev_sf_b.vsm_Keep_Global_Data_From_Input_p2=DDS_FALSE;
  vsmax_vsctl_aveh_deacvsmax_cpy = *VSCtl_aVeh_DeacVSMax_swc_out;

  vsmax_vsctl_spdveh_deacvsmax_cpy = *VSCtl_spdVeh_DeacVSMax_swc_out;

  vsmax_vsctl_jrkveh_deacvsmax_cpy = *VSCtl_jrkVeh_DeacVSMax_swc_out;

  vsmax_vsctl_nogearegd_deacvsmax_cpy = *VSCtl_noGearEgd_DeacVSMax_swc_out;

  vsmax_vsctl_ticfmsdwnvsmaxreq_cpy = *VSCtl_tiCfmSdwnVSMaxReq_swc_out;

  vsmax_vsctl_rslop_deacvsmax_cpy = *VSCtl_rSlop_DeacVSMax_swc_out;

  vsmax_vsctl_jrkvehreqdeacvsmax_cpy = *VSCtl_jrkVehReqDeacVSMax_swc_out;

  vsmax_vsctl_spdvehreqdeacvsmax_cpy = *VSCtl_spdVehReqDeacVSMax_swc_out;

  vsmax_vsctl_spdveherrvsmax_cpy = *VSCtl_spdVehErrVSMax_swc_out;

  vsmax_vsctl_ticfmsupvsmaxreq_cpy = *VSCtl_tiCfmSupVSMaxReq_swc_out;

  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiHld_stDeacVSMaxReq1 = VSCtl_tiHld_stDeacVSMaxReq1_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiHld_stDeacVSMaxReq2 = VSCtl_tiHld_stDeacVSMaxReq2_C;  /* Replaced by Post task */     /* Init from Model */
  vsmax_vsctl_stdeacvsmaxreq_no1_cpy = *VSCtl_stDeacVSMaxReq_no1_swc_out;

  vsmax_vsctl_stdeacvsmaxreq_no2_cpy = *VSCtl_stDeacVSMaxReq_no2_swc_out;

  VSCtl_rSpdVehCtlVSMaxDyn = 12800U;
  vsmax_vsctl_spdvehvsmaxreq_cpy = *VSCtl_spdVehVSMaxReq_swc_out;

  vsmax_vsctl_raccp_deacvsmax_cpy = *VSCtl_rAccP_DeacVSMax_swc_out;

  VSCtl_spdVehVSMaxPrmaReqPrev = 32640U;
  vsmax_vsctl_avehpotvsmaxreq_cpy = *VSCtl_aVehPotVSMaxReq_swc_out;

  vsmax_vsctl_avehvsmaxreq_cpy = *VSCtl_aVehVSMaxReq_swc_out;

  vsmax_vsctl_avehvsmaxreq_deacvsmax_cpy = *VSCtl_aVehVSMaxReq_DeacVSMax_swc_out;

  *VSCtl_bCtl_aVehPotVSMax_swc_out = VSCTL_BCTL_AVEHPOTVSMAX_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsmax_vsctl_bctl_avehpotvsmax_cpy = *VSCtl_bCtl_aVehPotVSMax_swc_out;

  VSCtl_tiFilSpdVehCtlVSMaxDyn = VSCtl_tiTol_DynCtlVSMax_C; /* Replaced by Post task */     /* Init from Model */
  VSCtl_bDynCtlSpdVehVSMax = VSCTL_BDYNCTLSPDVEHVSMAX_TRANSITOIRE;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSatJrkVehMaxVSMax = VSCTL_STSATJRKVEHMAXVSMAX_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSatJrkVehMinVSMax = VSCTL_STSATJRKVEHMINVSMAX_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSatAVehMinVSMax = VSCTL_STSATAVEHMINVSMAX_ARRET;  /* Replaced by Post task */     /* Init from Model */
  *VSCtl_stCtl_aVehVSMax_swc_out = VSCTL_STCTL_AVEHVSMAX_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsmax_vsctl_stctl_avehvsmax_cpy = *VSCtl_stCtl_aVehVSMax_swc_out;

  VSCtl_tiFilStCtlAVehVSMax = VSCtl_tiFil_stCtlAVehVSMax_C; /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSpdVehCritModClc = VSCTL_STSPDVEHCRITMODCLC_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSpdVehCritFilModClc = VSCTL_STSPDVEHCRITFILMODCLC_ARRET;  /* Replaced by Post task */     /* Init from Model */
  vsmax_vsctl_stvsmax_deacvsmax_cpy = *VSCtl_stVSMax_DeacVSMax_swc_out;

  vsmax_vsctl_stvsmaxprev_deacvsmax_cpy = *VSCtl_stVSMaxPrev_DeacVSMax_swc_out;

  vsmax_vsctl_posngbxdeacvsmax_cpy = *VSCtl_posnGBxDeacVSMax_swc_out;

  *VSCtl_stRec_stDeacVSMaxReq1_swc_out = VSCTL_STREC_STDEACVSMAXREQ1_ATTENTE;   /* Replaced by Post task */     /* Init from Model */
  vsmax_strec_stdeacvsmaxreq1_cpy = *VSCtl_stRec_stDeacVSMaxReq1_swc_out;

  *VSCtl_stRec_stDeacVSMaxReq2_swc_out = VSCTL_STREC_STDEACVSMAXREQ2_ATTENTE;   /* Replaced by Post task */     /* Init from Model */
  vsmax_strec_stdeacvsmaxreq2_cpy = *VSCtl_stRec_stDeacVSMaxReq2_swc_out;

  VSCtl_stVSMaxPrev = VSCTL_STVSMAXPREV_ARRET;  /* Replaced by Post task */     /* Init from Model */
  *VSCtl_stVSMaxExtd_swc_out = VSCTL_STVSMAXEXTD_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsmax_vsctl_stvsmaxextd_cpy = *VSCtl_stVSMaxExtd_swc_out;

  VSCtl_stMonVSMax = VSCTL_STMONVSMAX_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIniVSMax = VSCtl_tiVSMaxIni_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiDftRvVSMax = VSCtl_tiDftRvVSMax_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_ctDftRevVSMax = VSCtl_ctTolRvDftVSMax_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_bInhVSMax = DDS_TRUE;



  vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE = 0U;
  vsmax_re002tev_sf_dwork.is_active_c63_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c63_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bAcvFil_aVehPotVSMax =DDS_FALSE;





  vsmax_re002tev_sf_dwork.is_ETAT_SERVICE_BVV = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE_j = 0U;
  vsmax_re002tev_sf_dwork.is_NON_VERIF = 0U;
  vsmax_re002tev_sf_dwork.is_PAS_DEFAUT = 0U;
  vsmax_re002tev_sf_dwork.is_active_c37_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c37_VSMAX_Re002tev_Sf = 0U;
  *VSCtl_bDgoVSMax_swc_out =DDS_FALSE;
  vsmax_vsctl_bdgovsmax_cpy = *VSCtl_bDgoVSMax_swc_out;

  *VSCtl_bMonRunVSMax_swc_out =DDS_FALSE;
  vsmax_vsctl_bmonrunvsmax_cpy = *VSCtl_bMonRunVSMax_swc_out;

  VSCtl_bctDefRevVSMax =DDS_TRUE;


  vsmax_re002tev_sf_delay_0 = VSMAX_RE002TEV_SF_CONST_1;


  vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVf = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE_d = 0U;
  vsmax_re002tev_sf_dwork.is_active_c211_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c211_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bAcvVSMaxf =DDS_FALSE;


  vsmax_re002tev_sf_delay_1 = VSMAX_RE002TEV_SF_CONST_1;


  vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVp = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE_a = 0U;
  vsmax_re002tev_sf_dwork.is_active_c40_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c40_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bAcvVSMaxp =DDS_FALSE;


  vsmax_re002tev_sf_delay_2 = VSMAX_RE002TEV_SF_CONST_1;


  vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVs = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE_l = 0U;
  vsmax_re002tev_sf_dwork.is_active_c42_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c42_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bAcvVSMaxs =DDS_FALSE;


  vsmax_re002tev_sf_delay_3 = VSMAX_RE002TEV_SF_CONST_1;


  vsmax_re002tev_sf_dwork.is_DEMANDE_ACTIVATION_BVVc = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE_n = 0U;
  vsmax_re002tev_sf_dwork.is_active_c43_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c43_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bAcvVSMaxc =DDS_FALSE;



  vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION_b = 0U;
  vsmax_re002tev_sf_dwork.is_active_c39_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c39_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bInhVSMaxReq_Brk =DDS_TRUE;



  vsmax_re002tev_sf_dwork.is_DEMANDE_INHIBITION = 0U;
  vsmax_re002tev_sf_dwork.is_active_c213_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c213_VSMAX_Re002tev_Sf = 0U;



  vsmax_re002tev_sf_dwork.is_ETAT_FONCTIONNEMENT = 0U;
  vsmax_re002tev_sf_dwork.is_DISPONIBLE = 0U;
  vsmax_re002tev_sf_dwork.is_ACTIVATION_DEMANDEE = 0U;
  vsmax_re002tev_sf_dwork.is_INDISPONIBLE = 0U;
  vsmax_re002tev_sf_dwork.is_FONCTION_PRESENTE = 0U;
  vsmax_re002tev_sf_dwork.is_active_c214_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c214_VSMAX_Re002tev_Sf = 0U;


  vsmax_re002tev_sf_delay_4 = VSMAX_RE002TEV_SF_CONST_1;

  vsmax_re002tev_sf_delay_5 = VSMAX_RE002TEV_SF_CONST_1;


  vsmax_re002tev_sf_dwork.is_active_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE = 0U;
  vsmax_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_CRITIQUE = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE_k = 0U;
  vsmax_re002tev_sf_dwork.is_CONTROL = 0U;
  vsmax_re002tev_sf_dwork.is_active_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE = 0U;
  vsmax_re002tev_sf_dwork.is_MODE_FILTRAGE_VITESSE_VEHICULE_CRITIQUE = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE = 0U;
  vsmax_re002tev_sf_dwork.is_active_c95_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c95_VSMAX_Re002tev_Sf = 0U;



  vsmax_re002tev_sf_dwork.is_MODE_COMMANDE_ACCELERATION_VEHICULE = 0U;
  vsmax_re002tev_sf_dwork.is_HORS_CONTROLE = 0U;
  vsmax_re002tev_sf_dwork.is_active_c215_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c215_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bAcvFil_aVehVSMax =DDS_FALSE;



  vsmax_re002tev_sf_dwork.is_active_CONDITION_CHANGEMENT_DYNAMIQUE = 0U;
  vsmax_re002tev_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = 0U;
  vsmax_re002tev_sf_dwork.is_NON_INIT_n = 0U;
  vsmax_re002tev_sf_dwork.is_active_LISSAGE_CONTROLE_VITESSE = 0U;
  vsmax_re002tev_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = 0U;
  vsmax_re002tev_sf_dwork.is_NON_INIT = 0U;
  vsmax_re002tev_sf_dwork.is_active_c217_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c217_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_b.VSCtl_rSpdVehCtlVSMaxDyn_n = 0U;


  vsmax_re002tev_sf_delay_6 = VSMAX_RE002TEV_SF_CONST_3;

  vsmax_re002tev_sf_delay_7 = VSMAX_RE002TEV_SF_CONST_2;


  vsmax_re002tev_sf_dwork.is_active_ACCEL = 0U;
  vsmax_re002tev_sf_dwork.is_ACCEL = 0U;
  vsmax_re002tev_sf_dwork.is_CONTROLE = 0U;
  vsmax_re002tev_sf_dwork.is_active_JERK_MAX = 0U;
  vsmax_re002tev_sf_dwork.is_JERK_MAX = 0U;
  vsmax_re002tev_sf_dwork.is_CONTROLE_p = 0U;
  vsmax_re002tev_sf_dwork.is_active_JERK_MIN = 0U;
  vsmax_re002tev_sf_dwork.is_JERK_MIN = 0U;
  vsmax_re002tev_sf_dwork.is_CONTROLE_p4 = 0U;
  vsmax_re002tev_sf_dwork.is_active_c216_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c216_VSMAX_Re002tev_Sf = 0U;



  vsmax_re002tev_sf_dwork.is_ENABLE_F523 = 0U;
  vsmax_re002tev_sf_dwork.is_active_c1_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c1_VSMAX_Re002tev_Sf = 0U;
  vsctl_bacv_calcul =DDS_TRUE;



  vsmax_re002tev_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION = 0U;
  vsmax_re002tev_sf_dwork.is_active_c33_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c33_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bCfVSMax =DDS_TRUE;



  vsmax_re002tev_sf_dwork.is_active_DIAGNOSTIC = 0U;
  vsmax_re002tev_sf_dwork.is_DIAGNOSTIC = 0U;
  vsmax_re002tev_sf_dwork.is_MARCHE_g = 0U;
  vsmax_re002tev_sf_dwork.is_active_MEMOIRE = 0U;
  vsmax_re002tev_sf_dwork.is_active_c184_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c184_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bDeacVSMaxp =DDS_TRUE;
  *VSCtl_bDgoVSMaxp_swc_out =DDS_FALSE;
  vsmax_vsctl_bdgovsmaxp_cpy = *VSCtl_bDgoVSMaxp_swc_out;

  *VSCtl_bMonRunVSMaxp_swc_out =DDS_FALSE;
  vsmax_vsctl_bmonrunvsmaxp_cpy = *VSCtl_bMonRunVSMaxp_swc_out;

  vsmax_re002tev_sf_b.VSCtl_spdVehVSMaxPrmaReqPrev_n = 0U;


  vsmax_re002tev_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_BVV = 0U;
  vsmax_re002tev_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 = 0U;
  vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no1 = 0U;
  vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT_o = 0U;
  vsmax_re002tev_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 = 0U;
  vsmax_re002tev_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_BVV_no2 = 0U;
  vsmax_re002tev_sf_dwork.is_FONCTIONNEMENT = 0U;
  vsmax_re002tev_sf_dwork.is_active_MEMOIRES = 0U;
  vsmax_re002tev_sf_dwork.is_active_c44_VSMAX_Re002tev_Sf = 0U;
  vsmax_re002tev_sf_dwork.is_c44_VSMAX_Re002tev_Sf = 0U;
  VSCtl_bRec_stDeacVSMaxReq =DDS_FALSE;


  vsmax_re002tev_sf_delay_9 = VSMAX_RE002TEV_SF_CONST_1;

  vsmax_re002tev_sf_delay_10 = VSMAX_RE002TEV_SF_CONST_3;
}

/* \AUT_POST_TAG FUNCTIONS */

#define VSMAX_STOP_SEC_CODE
#include "VSMax_MemMap.h"

