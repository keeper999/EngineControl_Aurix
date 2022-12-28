/*
* File: VSSP_Torque_Control_Gmp1_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSSP_Torque_Control_Gmp1_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Tue Jan 03 12:06:55 2012
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Tue Jan 03 12:06:57 2012
*
* Post treatment done by tool Aut_Autocode_Post.pl version 11.75
*        with rules Aut_Rules_For_Autocode_Post.pm version 12.10
*
* Code generated from spec : R6512345_10
*
* LABEL USED: LIBRARY_R6510684_16_0_0
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
*        HOST_NAME ='DL6384B2J'
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
*        aut_ems_lib version 16.x
*
* Common dll version 3.0
*
* Blocks versions:
*        AUT_EC_m_min_opt SFunction version: 3.0, TLC version: 3.0
*        AUT_EC_Function_Stub_v1 SFunction version: 6.0, TLC version: 1.0
*        AUT_EC_m_limit_opt SFunction version: 3.0, TLC version: 12.2
*        AUT_EC_Keep_Global_Data_From_Input SFunction version: 8.0, TLC version: 12.2
*
* Scripts versions:
*        aut_add_io version 3.0                                        aut_array_size_list_manager version 1.0
*        aut_assign_const_parameter_to_table_init version 5.0          aut_autocode_optimization version 8.0
*        aut_calc_block_before_limiter version 8.0                     aut_cast_block_before_limiter version 4.0
*        aut_check_accuracy_loss version 5.0                           aut_check_blocks_fields_values version 3.0
*        aut_check_calc_blocks version 43.0                            aut_check_downcast version 5.0
*        aut_check_if_data_exists_into_workps version 4.0              aut_check_if_data_if_an_nvv_data_store version 3.0
*        aut_check_if_data_is_shared version 3.0                       aut_check_if_globlal_T55_exist version 3.0
*        aut_check_if_parameter_present_into_model version 3.0         aut_check_if_previous_block_equal_to_type version 4.0
*        aut_check_if_range_is_compatible_with_datatype version 5.0    aut_check_model_vs_workspace version 4.0
*        aut_check_pointer_access version 3.0                          aut_chk_lcs version 3.0
*        aut_create_alias_type version 3.0                             aut_create_data version 24.0
*        aut_create_enum version 11.0                                  aut_create_hyperlink_command_from_block version 3.0
*        aut_create_intermediate_constants version 4.0                 aut_create_sstg_architecture version 10.0
*        aut_cross_check_T55_mdl_init version 4.0                      aut_ec_maskinitialization_common_function version 2.0
*        aut_ec_sp_aut_unit_delay_memory_effect_callback version 1.0   aut_find_source_block_path version 6.0
*        aut_fixed_point_toolbox_interface version 4.0                 aut_format_cpv_initialization_line version 10.0
*        aut_free_up_unexpected_block version 4.0                      aut_get_array_apv_according_calibration_mode version 5.0
*        aut_get_data_list_from_link_output_block version 3.0          aut_get_data_size version 3.0
*        aut_get_deeper_block_from_list version 3.0                    aut_get_evaluated_value_from_constant version 4.0
*        aut_get_final_datatype version 3.0                            aut_get_information_from_next_block version 16.0
*        aut_get_information_from_previous_block version 30.0          aut_get_key version 3.0
*        aut_get_sigtype_info version 3.0                              aut_get_snapshot_under_critical_lst_tag version 1.0
*        aut_get_squeduling_list version 16.0                          aut_get_src_handle_from_previous_block_and_port_index version 3.0
*        aut_get_static_data_list version 4.0                          aut_init_value_check version 4.0
*        aut_key_alg version 3.0                                       aut_manage_autocode_model version 15.0
*        aut_manage_compilation_mode version 4.0                       aut_manage_doc_block version 7.0
*        aut_manage_limiter version 11.0                               aut_manage_model_workspace version 3.0
*        aut_manage_simulink_to_post_task_exchange version 54.0        aut_manage_snapshot version 26.0
*        aut_mode_switch version 68.0                                  aut_model_autocode version 25.0
*        aut_model_configure version 7.0                               aut_pre_autocode version 55.0
*        aut_prepare_t55_task version 28.0                             aut_prepare_t55_task_for_tag version 9.0
*        aut_process_mngt version 58.0                                 aut_project_settings version 22.0
*        aut_signal_config version 13.0                                aut_sstg_manage_signal_memory_location version 6.0
*        aut_stateflow_checks version 6.0                              aut_step_ckecks version 4.0
*        aut_switch_cpv_initialization version 13.0                    aut_tlc_check_if_min_requested_instead_of_limit version 3.0
*        aut_tlc_get_block_init_string version 7.0                     aut_tlc_static_variable_name_calculation version 6.0
*        aut_types version 3.0                                         aut_unset_set_block_properties_of_subsytem version 8.0
*        aut_update_init_file_with_tag version 4.0                     sim_attributes_format_string version 4.0
*        sim_check_if_data_is_in_full_range version 2.0                sim_check_unlinked_blocks version 11.0
*        sim_configure_simulation_mode version 9.0                     sim_display_dd_settings version 5.0
*        sim_format_hyperlink_message version 6.0                      sim_function_stub version 3.0
*        sim_get_autorisation_for_limitation version 1.0               sim_get_library_references version 46.0
*        sim_get_library_version version 3.0                           sim_get_static_data_block version 3.0
*        sim_load_libraries version 3.0                                sim_manage_block_tab version 6.0
*        sim_manage_config_set version 4.0                             sim_manage_link_status_warning version 3.0
*        sim_manage_structure_dd_display version 2.0                   sim_manage_structure_signals version 5.0
*        sim_maskinitialization_common_function version 4.0            sim_prepare_limitation version 60.0
*        sim_restore_previous_tag_version version 2.0                  sim_set version 1.0
*        sim_set_ic version 1.0                                        sim_set_param version 3.0
*        sim_sf_get_param version 7.0                                  sim_switch_block_mode version 5.0
*        sim_unit_delay_callback version 2.0                           sim_update_block_display_status version 18.0
*        sim_warning_control version 5.0
*
* Post task version 11.75
*
* Config Spec:
*        element * CHECKEDOUT
*        element clearcase\... \main\LATEST
*        element livraison\... \main\LATEST
*        element tests\... \main\LATEST
*        element Appli\ /main/LATEST
*        element \DDS_E_Documents_Vob\...  /main/LATEST
*        element * LABEL_SSTG_AUTOCODING
*        element * LIBRARY_R6510684_17_PRERELEASE_7
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
* Ref X:\integration_view_00PSASWC_D820D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Torque_Control_Gmp1_Sf.c
* Version int :/main/L02_02/1 Date: 6/1/2012 11 h 11 m User:esnault 
*    TWK_model:VSSP_Torque_Control_Gmp1_Sf_L02_020_IMPL1
*    comments :Update requirement
* Version dev :\main\branch_moisan_module_dev\1 Date: 3/1/2012 17 h 39 m User:moisan 
*    TWK_model:VSSP_Torque_Control_Gmp1_Sf_L02_020_IMPL1
*    comments :Update requirement
* Version dev :\main\branch_demezil_vssp_view\1 Date: 3/1/2012 14 h 34 m User:demezil
*    TWK_model:VSSP_Torque_Control_Gmp1_Sf_L02_020_IMPL1
*    comments :update for VSSp 12.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Max ;VSCtl_bAuthAntTqWhlMax;VSCtl_bLgtCtlDyn;VSCtl_stCtl_tqWhlMax;VSCtl_stTqWhlPTCutOffReqPrev; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Max ;VSCtl_bAntTqWhlPTMaxReq;VSCtl_rAnt_tqWhlPTMax;VSCtl_stCtl_tqWhlMaxPrev;VSCtl_stTqWhlPTCutOffMxRPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Min ;VSCtl_bAuthAntTqWhlMin;VSCtl_bLgtCtlDyn;VSCtl_stCtl_tqWhlMin;VSCtl_stTqWhlPTCutOffReqPrev; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Min ;VSCtl_bAntTqWhlPTMinReq;VSCtl_rAnt_tqWhlPTMin;VSCtl_stCtl_tqWhlMinPrev;VSCtl_stTqWhlPTCutOffMnRPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Anticipation_Couple_Roue_GMP_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demande_Coupure_Couple_Roue_GMP */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demande_Coupure_Couple_Roue_GMP ;VSCtl_bCtlaTqPT;VSCtl_stCtl_tqWhlMax;VSCtl_stCtl_tqWhlMin;VSCtl_tqWhlMaxReq;VSCtl_tqWhlMinReq;VSCtl_tqWhlPTMaxNotCtla;VSCtl_tqWhlPTMinNotCtla;VSCtl_tqWhlPTPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demande_Coupure_Couple_Roue_GMP ;VSCtl_stTqWhlPTCutOffReq;VSCtl_stTqWhlPTCutOffReqPrev;VSCtl_tiCutOffMinTqWhl;VSCtl_tiCutOnMinTqWhl;VSCtl_tiPerCutOffTqWhl; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demande_Coupure_Couple_Roue_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Max ;VSCtl_stCtl_tqWhlPTMax;VSCtl_tqWhlPTMaxReq;VSCtl_tqWhlPTMinReq;VSCtl_tqWhlPTPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Max ;VSCtl_bCtlEfc_tqWhlPTMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Min ;VSCtl_stCtl_tqWhlPTMin;VSCtl_tqWhlPTMinReq;VSCtl_tqWhlPTPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Min ;VSCtl_bCtlEfc_tqWhlPTMin; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Couple_Roue_GMP_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max ;AccP_rAccP;VSCtl_rAccPPTMax;VSCtl_stCtl_tqWhlPTMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max ;VSCtl_bCtlEfc_rAccPMax_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min ;AccP_rAccP;VSCtl_rAccPPTMin;VSCtl_stCtl_tqWhlPTMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min ;VSCtl_bCtlEfc_rAccPMin_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Position_Pedale_Accelerateur_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV ;VSCtl_bCtlEfc_rAccPMax_pt1;VSCtl_bCtlEfc_rAccPMin_pt1;VSCtl_bCtlEfc_tqWhlPTMax;VSCtl_bCtlEfc_tqWhlPTMin;VSCtl_stCtl_tqWhlPTMax;VSCtl_stCtl_tqWhlPTMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV ;VSCtl_bCtlEfc_tqWhlPT_pt1;VSCtl_stTqPTMaxCtl_pt1;VSCtl_stTqPTMinCtl_pt1;VSCtl_st_rAccPCtl_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Effectivite_Processus_XVV */

/* TAG_START_OF_SUB_FUNCTION: F71212_Determiner_Consigne_Couple_Roue_GMP_Min */
/* TAG_INPUT_OF_SUB_FUNCTION: F71212_Determiner_Consigne_Couple_Roue_GMP_Min ;VSCtl_bAntTqWhlPTMinReq;VSCtl_rAnt_tqWhlPTMin;VSCtl_stCtl_tqWhlPTMin;VSCtl_stTqWhlPTCutOffReqPrev;VSCtl_tqWhlMinReq;VSCtl_tqWhlPTMax;VSCtl_tqWhlPTMaxNotCtla;VSCtl_tqWhlPTMin;VSCtl_tqWhlPTMinNotCtla;VSCtl_tqWhlPTPreCoVSCMinReq;VSCtl_tqWhlPTPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71212_Determiner_Consigne_Couple_Roue_GMP_Min ;VSCtl_tiFil_tqWhlMin;VSCtl_tiFil_tqWhlMinRaw1;VSCtl_tiFil_tqWhlMinRaw2;VSCtl_tiFil_tqWhlMinRaw3;VSCtl_tqWhlPTMinReq;VSCtl_tqWhlPTMinReqRaw1;VSCtl_tqWhlPTMinReqRaw2; */
/* TAG_END_OF_SUB_FUNCTION: F71212_Determiner_Consigne_Couple_Roue_GMP_Min */

/* TAG_START_OF_SUB_FUNCTION: F71214_Determiner_Position_Pedale_Accelerateur_GMP_Min */
/* TAG_INPUT_OF_SUB_FUNCTION: F71214_Determiner_Position_Pedale_Accelerateur_GMP_Min ;VSCtl_bAcvFil_tqWhlPTMin;VSCtl_spdVeh;VSCtl_stCtl_tqWhlPTMin;VSCtl_tqWhlPTDrvMaxReq;VSCtl_tqWhlPTDrvMinReq;VSCtl_tqWhlPTMinReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71214_Determiner_Position_Pedale_Accelerateur_GMP_Min ;VSCtl_rAccPPTMin; */
/* TAG_END_OF_SUB_FUNCTION: F71214_Determiner_Position_Pedale_Accelerateur_GMP_Min */

/* TAG_START_OF_SUB_FUNCTION: F71221_Determiner_Consigne_Couple_Roue_GMP_Max_Init */
/* TAG_INPUT_OF_SUB_FUNCTION: F71221_Determiner_Consigne_Couple_Roue_GMP_Max_Init ;VSCtl_tqWhlPTMaxReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71221_Determiner_Consigne_Couple_Roue_GMP_Max_Init ;VSCtl_tqWhlPTMaxReqDly; */
/* TAG_END_OF_SUB_FUNCTION: F71221_Determiner_Consigne_Couple_Roue_GMP_Max_Init */

/* TAG_START_OF_SUB_FUNCTION: F71223_Determiner_Consigne_Couple_Roue_GMP_Max */
/* TAG_INPUT_OF_SUB_FUNCTION: F71223_Determiner_Consigne_Couple_Roue_GMP_Max ;VSCtl_bAntTqWhlPTMaxReq;VSCtl_rAnt_tqWhlPTMax;VSCtl_stCtl_tqWhlPTMax;VSCtl_stTqWhlPTCutOffReqPrev;VSCtl_tiFiltqWhlPTMaxReq;VSCtl_tqWhlMaxReq;VSCtl_tqWhlPTMax;VSCtl_tqWhlPTMaxNotCtla;VSCtl_tqWhlPTMaxReqDly;VSCtl_tqWhlPTMin;VSCtl_tqWhlPTMinNotCtla;VSCtl_tqWhlPTPreCoVSCMinReq;VSCtl_tqWhlPTPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71223_Determiner_Consigne_Couple_Roue_GMP_Max ;VSCtl_tqWhlPTMaxReq; */
/* TAG_END_OF_SUB_FUNCTION: F71223_Determiner_Consigne_Couple_Roue_GMP_Max */

/* TAG_START_OF_SUB_FUNCTION: F71225_Determiner_Position_Pedale_Accelerateur_GMP_Max */
/* TAG_INPUT_OF_SUB_FUNCTION: F71225_Determiner_Position_Pedale_Accelerateur_GMP_Max ;VSCtl_bAcvFil_tqWhlPTMax;VSCtl_spdVeh;VSCtl_stCtl_tqWhlPTMax;VSCtl_tqWhlPTDrvMaxReq;VSCtl_tqWhlPTDrvMinReq;VSCtl_tqWhlPTMaxReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71225_Determiner_Position_Pedale_Accelerateur_GMP_Max ;VSCtl_rAccPPTMax; */
/* TAG_END_OF_SUB_FUNCTION: F71225_Determiner_Position_Pedale_Accelerateur_GMP_Max */

/* TAG_START_OF_SUB_FUNCTION: F71232_Determiner_Consigne_Limitation_Couple_Roue_GMP_Min */
/* TAG_INPUT_OF_SUB_FUNCTION: F71232_Determiner_Consigne_Limitation_Couple_Roue_GMP_Min ;VSCtl_bAcvFilTqWhlPTMinSat;VSCtl_stTqWhlPTMinSat;VSCtl_tiTqWhlPTMinSatTraMax;VSCtl_tqWhlMinSat;VSCtl_tqWhlPTDrvMinReqRaw; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F71232_Determiner_Consigne_Limitation_Couple_Roue_GMP_Min ;VSCtl_tqWhlPTMinSat; */
/* TAG_END_OF_SUB_FUNCTION: F71232_Determiner_Consigne_Limitation_Couple_Roue_GMP_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Limitation_Couple_Roue_GMP */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Limitation_Couple_Roue_GMP ;VSCtl_bTqWhlMinSat;VSCtl_stCtl_tqWhlPTMax;VSCtl_stCtl_tqWhlPTMin;VSCtl_tqWhlPTDrvMinReq;VSCtl_tqWhlPTDrvMinReqRaw; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Limitation_Couple_Roue_GMP ;VSCtl_bAcvFilTqWhlPTMinSat;VSCtl_bAcvTqWhlPTMinSat;VSCtl_stTqWhlPTMinSat;VSCtl_tiTqWhlPTMinSatTraMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Limitation_Couple_Roue_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Roue_GMP_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Roue_GMP_Min ;VSCtl_bCtlCmdPTTqCf_SC;VSCtl_stCtl_tqWhlMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Roue_GMP_Min ;VSCtl_bAcvFil_tqWhlPTMin;VSCtl_stCtl_tqWhlPTMin; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Controle_Couple_Roue_GMP_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Roue_GMP_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Roue_GMP_Max ;VSCtl_bCtlCmdPTTqCf_SC;VSCtl_bFastDeacVSLimReq;VSCtl_stCtl_tqWhlMax;VSCtl_tqWhlPTMaxReqDly;VSCtl_tqWhlPTPreCoVSCtlReq; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Roue_GMP_Max ;VSCtl_bAcvFil_tqWhlPTMax;VSCtl_bTranEnd_tqWhlPTMax;VSCtl_stCtl_tqWhlPTMax;VSCtl_tiFiltqWhlPTMaxReq; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Modes_Controle_Couple_Roue_GMP_Max */

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
#define VSCTL_STCTL_TQWHLMINPREV_ARRET                  (0)
#define VSCTL_STTQWHLPTCUTOFFMNRPREV_ARRET              (0)
#define VSCTL_STCTL_TQWHLMAXPREV_ARRET                  (0)
#define VSCTL_STTQWHLPTCUTOFFMXRPREV_ARRET              (0)

/* VSCtl_stTqWhlPTCutOffReq */
#define VSCTL_STTQWHLPTCUTOFFREQ_ARRET                  (0)
#define VSCTL_STTQWHLPTCUTOFFREQ_PILOTABLE_H            (1)
#define VSCTL_STTQWHLPTCUTOFFREQ_PILOTABLE_B            (2)

/* VSCtl_stTqWhlPTCutOffReqDly */
#define VSCTL_STTQWHLPTCUTOFFREQPREV_ARRET              (0)
#define VSCTL_STTQWHLPTCUTOFFREQPREV_PILOTABLE_H        (1)
#define VSCTL_STTQWHLPTCUTOFFREQPREV_PILOTABLE_B        (2)

/* VSCtl_bLgtCtlDyn */
#define VSCTL_BLGTCTLDYN_TRANSITOIRE                    (0)
#define VSCTL_BLGTCTLDYN_STABILISE                      (1)

/* VSCtl_stCtl_tqWhlPTMax */
#define VSCTL_STCTL_TQWHLPTMAX_ARRET                    (0)
#define VSCTL_STCTL_TQWHLPTMAX_CONTROLE                 (1)
#define VSCTL_STCTL_TQWHLPTMAX_TRANS_L                  (2)
#define VSCTL_STCTL_TQWHLPTMAX_TRANS_R                  (3)
#define VSCTL_STCTL_TQWHLPTMAX_INIT                     (4)

/* VSCtl_stTqWhlPTMinSat */
#define VSCTL_STTQWHLPTMINSAT_ARRET                     (0)
#define VSCTL_STTQWHLPTMINSAT_CONTROLE_32               (1)
#define VSCTL_STTQWHLPTMINSAT_TRANSITION_32             (2)

/* VSCtl_stTqPTMinCtl_pt1 */
#define VSCTL_STTQPTMINCTL_PT1_INACTIF                  (0)
#define VSCTL_STTQPTMINCTL_PT1_AE                       (1)
#define VSCTL_STTQPTMINCTL_PT1_ANE                      (2)

/* VSCtl_stTqPTMaxCtl_pt1 */
#define VSCTL_STTQPTMAXCTL_PT1_INACTIF                  (0)
#define VSCTL_STTQPTMAXCTL_PT1_AE                       (1)
#define VSCTL_STTQPTMAXCTL_PT1_ANE                      (2)

/* VSCtl_st_rAccPCtl_pt1 */
#define VSCTL_ST_RACCPCTL_PT1_INACTIF                   (0)
#define VSCTL_ST_RACCPCTL_PT1_AE                        (1)
#define VSCTL_ST_RACCPCTL_PT1_ANE                       (2)

/* VSCtl_stCtl_tqWhlPTMin */
#define VSCTL_STCTL_TQWHLPTMIN_ARRET                    (0)
#define VSCTL_STCTL_TQWHLPTMIN_CONTROLE                 (1)
/************************************************************************/

/* Named constants for block: /Demande_Coupure_Couple_Roue_GMP' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_H (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ARRET (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_DEMANDE_COUPURE_COUPLE_ROUE_GMP (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_B (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE (2)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI (1U)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX (0U)

/* Named constants for block: /Demande_Anticipation_Couple_Roue_GMP_Min' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_e (0)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DEMANDEE (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DESACTIVEE (3)
#define VSSP_Torque_Control_Gmp1_Sf_IN_VRAI (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_FAUX (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION (4)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_NON_DEMANDEE (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_DEMANDE_ANTICIPATION_COUPLE_ROUE_GMP_MIN (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION (1)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_k (1U)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_b (0U)

/* Named constants for block: /Demande_Anticipation_Couple_Roue_GMP_Max' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_i (0)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_AUTORISEE (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DESACTIVEE_h (3)
#define VSSP_Torque_Control_Gmp1_Sf_IN_VRAI_a (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_FAUX_f (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION_o (4)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_INTERDITE (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_DEMANDE_ANTICIPATION_COUPLE_ROUE_GMP_MAX (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE_j (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION_h (1)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_j (1U)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_p (0U)

/* Named constants for block: /Mode_Controle_Couple_Roue_GMP_Min' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_n (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_g (2)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_m (0U)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_h (1U)

/* Named constants for block: /Effectivite_Couple_Roue_GMP_Min' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_COUPLE_ROUE_GMP_MIN (1)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_j (0U)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_jw (1U)

/* Named constants for block: /Effectivite_Position_Pedale_Accelerateur_Min' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_i (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_a (1)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_f (0U)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_i (1U)

/* Named constants for block: /Modes_Controle_Couple_Roue_GMP_Max' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_a (0)
#define VSSP_Torque_Control_Gmp1_Sf_IN_REPRISE (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_LENTE (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_INIT (3)
#define VSSP_Torque_Control_Gmp1_Sf_IN_NON_REPRISE (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_MODE_CONTROLE_COUPLE_ROUE_GMP_MAX (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_p (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_b (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_RAPIDE (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_TRANSITION (4)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_jv (1U)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_l (0U)

/* Named constants for block: /Effectivite_Couple_Roue_GMP_Max' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_p (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_f (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_COUPLE_ROUE_GMP_MAX (1)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_k (0U)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_kh (1U)

/* Named constants for block: /Effectivite_Position_Pedale_Accelerateur_Max' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_c (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_h (1)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_n (0U)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_j5 (1U)

/* Named constants for block: /Mode_Calcul_Consigne_Limitation_Couple_Roue_GMP' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_j (0)
#define VSSP_Torque_Control_Gmp1_Sf_IN_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_d (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_o (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_TRANSITION_g (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_MARCHE (2)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_np (0U)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_d (1U)

/* Named constants for block: /Effectivite_Processus_XVV' */
#define VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_c (0)
#define VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_PROCESSUS_XVV (1)
#define VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_l (2)
#define VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_m (1)
#define VSSP_Torque_Control_Gmp1_Sf_FAUX_lk (0U)
#define VSSP_Torque_Control_Gmp1_Sf_VRAI_l (1U)

/* Definition for custom storage class: Define */
#define VSCTL_RANT_TQWHLPTMAX_MAX      12800U
#define VSCTL_RANT_TQWHLPTMIN_MAX      12800U
#define VSSP_100_BIN7                  12800U
#define VSSP_1_BIN1                    2
#define VSSP_TORQUE_CONTROL_GMP1_CONST_0 0


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxReqDly;       /*BIN1*/
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
VAR(UInt16, AUTOMATIC) VSCtl_tiTqWhlPTMinSatTraMax;       /*BIN0*/
VAR(UInt16, AUTOMATIC) VSCtl_tiFiltqWhlPTMaxReq;       /*DEC0*/
VAR(UInt16, AUTOMATIC) VSCtl_rAnt_tqWhlPTMin;       /*BIN7*/
VAR(UInt16, AUTOMATIC) VSCtl_rAnt_tqWhlPTMax;       /*BIN7*/
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlPTMinSat;
VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlPTCutOffReqPrev;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTMin;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAntTqWhlPTMinReq;
VAR(UInt8, AUTOMATIC) VSCtl_bAntTqWhlPTMaxReq;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTMin;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilTqWhlPTMinSat;
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  SInt16 vss_Keep_Global_Data_From_Input;
  UInt16 VSCtl_rAnt_tqWhlPTMax_n;
  UInt16 VSCtl_rAnt_tqWhlPTMin_h;
} BlockIO_VSSP_Torque_Control_Gmp1_Sf;


typedef struct {
  UInt32 is_ETAT_CONTROLE : 3;
  UInt32 is_ANTICIPATION_AUTORISEE : 3;
  UInt32 is_ANTICIPATION_DEMANDEE : 3;
  UInt32 is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1 : 2;
  UInt32 is_ACTIF : 2;
  UInt32 is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1 : 2;
  UInt32 is_ACTIF_l : 2;
  UInt32 is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1 : 2;
  UInt32 is_ACTIF_i : 2;
  UInt32 is_EFFECTIVITE_COUPLE_ROUE_GMP1 : 2;
  UInt32 is_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX : 2;
  UInt32 is_EFFECTIVITE_COUPLE_ROUE_GMP_MAX : 2;
  UInt32 is_FIN_TRANSITION : 2;
  UInt32 is_TRANSITION : 2;
  UInt32 is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN : 2;
  UInt32 is_EFFECTIVITE_COUPLE_ROUE_GMP_MIN : 2;
  UInt32 is_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN : 2;
  UInt32 is_DEMANDE_ANTICIPATION : 2;
  UInt32 is_TAUX_ANTICIPATION : 2;
  UInt32 is_DEMANDE_ANTICIPATION_g : 2;
  UInt32 is_TAUX_ANTICIPATION_n : 2;
  UInt32 is_DEMANDE_COUPURE_COUPLE_ROUE_GMP : 2;
  UInt32 is_CONTROLE : 2;
  UInt32 is_active_c128_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c128_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1 : 1;
  UInt32 is_active_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1 : 1;
  UInt32 is_active_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1 : 1;
  UInt32 is_active_EFFECTIVITE_COUPLE_ROUE_GMP1 : 1;
  UInt32 is_active_c127_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c127_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_c126_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c126_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_c125_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c125_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_c124_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c124_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_FIN_TRANSITION : 1;
  UInt32 is_active_ETAT_CONTROLE : 1;
  UInt32 is_active_c123_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c123_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_c122_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c122_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_c121_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c121_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_c120_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c120_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_MEMOIRES : 1;
  UInt32 is_active_DEMANDE_ANTICIPATION : 1;
  UInt32 is_active_TAUX_ANTICIPATION : 1;
  UInt32 is_active_c117_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c117_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_active_MEMOIRES_k : 1;
  UInt32 is_active_DEMANDE_ANTICIPATION_c : 1;
  UInt32 is_active_TAUX_ANTICIPATION_c : 1;
  UInt32 is_active_c79_VSSP_Torque_Control_Gmp1_Sf : 1;
  UInt32 is_c79_VSSP_Torque_Control_Gmp1_Sf : 1;
} D_Work_VSSP_Torque_Control_Gmp1_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCutOffMinTqWhl;                 /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCutOnMinTqWhl;                  /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiPerCutOffTqWhl;                 /*BIN0*/
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_rAccPMax_pt1;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_rAccPMin_pt1;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bTranEnd_tqWhlPTMax;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlMaxPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlMinPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlPTCutOffMnRPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlPTCutOffMxRPrev;
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_st_rAccPCtl_pt1;
/* Static Visible area end */
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 8BIT-bits variable definition */
#define VSSP_START_SEC_VAR_8BIT
#include "VSSp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_bacvtqwhlptminsat_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_bctlefc_tqwhlptmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_bctlefc_tqwhlptmin_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_bctlefc_tqwhlpt_pt1_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_sttqptmaxctl_pt1_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_sttqptminctl_pt1_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_sttqwhlptcutoffreq_cpy;
#define VSSP_STOP_SEC_VAR_8BIT
#include "VSSp_MemMap.h"


/* 16BIT-bits variable definition */
#define VSSP_START_SEC_VAR_16BIT
#include "VSSp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vssp_torque_control_gmp1_delay_0;
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqwhlptmaxreq_cpy;                           /*BIN1*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqwhlptminreq_cpy;                           /*BIN1*/
STATIC VAR(SInt16, AUTOMATIC) vssp_vsctl_tqwhlptminsat_cpy;                           /*BIN1*/
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_raccpptmax_cpy;                              /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_raccpptmin_cpy;                              /*BIN7*/
#define VSSP_STOP_SEC_VAR_16BIT
#include "VSSp_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(BlockIO_VSSP_Torque_Control_Gmp1_Sf, AUTOMATIC) vssp_torque_control_gmp1_sf_b;
STATIC VAR(D_Work_VSSP_Torque_Control_Gmp1_Sf, AUTOMATIC) vssp_torque_control_gmp1_sf_dwork;
/* Static Not Visible area end */
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSSP_START_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlMaxReqOff_C = (CONST(SInt16, AUTOMATIC))(0);         /*BIN1*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlMinReqOff_C = (CONST(SInt16, AUTOMATIC))(0);         /*BIN1*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_ctDec_rAnt_tqWhlPTMax_C = (CONST(UInt16, AUTOMATIC))(320U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_ctDec_rAnt_tqWhlPTMin_C = (CONST(UInt16, AUTOMATIC))(320U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_ctInc_rAnt_tqWhlPTMax_C = (CONST(UInt16, AUTOMATIC))(320U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_ctInc_rAnt_tqWhlPTMin_C = (CONST(UInt16, AUTOMATIC))(320U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCutOffMinTqWhl_C = (CONST(UInt16, AUTOMATIC))(9U);      /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCutOnMinTqWhl_C = (CONST(UInt16, AUTOMATIC))(9U);       /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFiltqWhlPTMaxReq_C = (CONST(UInt16, AUTOMATIC))(300U);  /*DEC0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiPerCutOffTqWhl_C = (CONST(UInt16, AUTOMATIC))(49U);     /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTqWhlPTMinSatTraMax_C = (CONST(UInt16, AUTOMATIC))(299U); /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTNotCtlaWideHi_C = (CONST(UInt16, AUTOMATIC))(10U); /*BIN1*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTNotCtlaWideLo_C = (CONST(UInt16, AUTOMATIC))(0U);  /*BIN1*/
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

FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp1_Sf(SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in,                    /*BIN1*/
                               UInt8 VSCtl_bLgtCtlDyn_swc_in,
                               SInt16 VSCtl_tqWhlPTMin_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMax_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlMinSat_swc_in,                            /*BIN1*/
                               SInt16 VSCtl_tqWhlMinReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlMin_swc_in,
                               UInt8 VSCtl_bTqWhlMinSat_swc_in,
                               SInt16 VSCtl_tqWhlMaxReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlMax_swc_in,
                               SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in,                   /*BIN1*/
                               SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in,                  /*BIN1*/
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 VSCtl_bAuthAntTqWhlMin_swc_in,
                               SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in,                       /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in,                      /*BIN1*/
                               UInt8 VSCtl_bAuthAntTqWhlMax_swc_in,
                               SInt16 VSCtl_tqWhlPTDrvMaxReq_swc_in,                       /*BIN1*/
                               UInt8 VSCtl_bCtlaTqPT_swc_in,
                               SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in,                      /*BIN1*/
                               UInt8 VSCtl_bFastDeacVSLimReq_swc_in,
                               UInt16 AccP_rAccP_swc_in,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTCutOffReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bAcvTqWhlPTMinSat_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt1_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinSat_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMin_swc_out,                             /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMaxReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMax_swc_out)                             /*BIN7*/
{

  /* TAG_START_OF_MAIN_FUNCTION */

  /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.02.5 */
  /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.131.1 */

  /* TAG_START_OF_STATEFLOW_FUNCTION: F7111_Determiner_Demande_Coupure_Couple_Roue_GMP*/
  /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.20.3 */

  if (vssp_torque_control_gmp1_sf_dwork.is_active_c79_VSSP_Torque_Control_Gmp1_Sf
      == 0)
  {
    vssp_torque_control_gmp1_sf_dwork.is_active_c79_VSSP_Torque_Control_Gmp1_Sf =
      1U;
    vssp_torque_control_gmp1_sf_dwork.is_c79_VSSP_Torque_Control_Gmp1_Sf =
      (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_DEMANDE_COUPURE_COUPLE_ROUE_GMP;
    vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_COUPURE_COUPLE_ROUE_GMP =
      (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET;
    vssp_vsctl_sttqwhlptcutoffreq_cpy = VSCTL_STTQWHLPTCUTOFFREQ_ARRET;
    VSCtl_stTqWhlPTCutOffReqPrev = VSCTL_STTQWHLPTCUTOFFREQPREV_ARRET;
    VSCtl_tiCutOffMinTqWhl = VSCtl_tiCutOffMinTqWhl_C;
    VSCtl_tiPerCutOffTqWhl = 0U;
    VSCtl_tiCutOnMinTqWhl = VSCtl_tiCutOnMinTqWhl_C;

  }
  else
  {
    switch (vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_COUPURE_COUPLE_ROUE_GMP)
    {
     case VSSP_Torque_Control_Gmp1_Sf_IN_ARRET:
      if (((((((VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET)
      &&
               (VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET))
               &&
              ((VSCtl_tqWhlMinReq_swc_in >= VSCtl_tqWhlPTMaxNotCtla_swc_in) ||
               ((VSCtl_tqWhlMinReq_swc_in >= VSCtl_tqWhlPTMinNotCtla_swc_in) &&
                (VSCtl_bCtlaTqPT_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI))))
                ||
             (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET)
             &&
               (VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET))
               &&
              ((VSCtl_tqWhlMaxReq_swc_in >= VSCtl_tqWhlPTMaxNotCtla_swc_in) ||
               ((VSCtl_tqWhlMaxReq_swc_in >= VSCtl_tqWhlPTMinNotCtla_swc_in) &&
                (VSCtl_bCtlaTqPT_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI)))))
                ||
            (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET) &&
              (VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET))
              &&
             (((VSCtl_tqWhlMaxReq_swc_in < VSCtl_tqWhlMinReq_swc_in ? (SInt32)
                VSCtl_tqWhlMaxReq_swc_in : (SInt32)VSCtl_tqWhlMinReq_swc_in) >=
               VSCtl_tqWhlPTMaxNotCtla_swc_in) || (((VSCtl_tqWhlMaxReq_swc_in <
                 VSCtl_tqWhlMinReq_swc_in ? (SInt32)VSCtl_tqWhlMaxReq_swc_in : (SInt32)
                 VSCtl_tqWhlMinReq_swc_in) >= VSCtl_tqWhlPTMinNotCtla_swc_in) &&
               (VSCtl_bCtlaTqPT_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI)))))
               && (DDS_M_ABS
            (VSCtl_tqWhlPTMinNotCtla_swc_in - VSCtl_tqWhlPTMaxNotCtla_swc_in) >
            VSCtl_tqWhlPTNotCtlaWideHi_C))
            && ((VSCtl_tqWhlPTPreCoVSCtlReq_swc_in >=
            VSCtl_tqWhlMaxReq_swc_in) || (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in <=
            VSCtl_tqWhlMinReq_swc_in)))
      {
        VSCtl_stTqWhlPTCutOffReqPrev = VSCTL_STTQWHLPTCUTOFFREQPREV_PILOTABLE_H;
        vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_COUPURE_COUPLE_ROUE_GMP =
          (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE;
        vssp_torque_control_gmp1_sf_dwork.is_CONTROLE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_H;
        vssp_vsctl_sttqwhlptcutoffreq_cpy = VSCTL_STTQWHLPTCUTOFFREQ_PILOTABLE_H;
        VSCtl_tiCutOnMinTqWhl = VSCtl_tiCutOnMinTqWhl_C;

      }
      else if (((((((VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET)
      &&
                      (VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET))
                      &&
                     ((VSCtl_tqWhlMinReq_swc_in <= VSCtl_tqWhlPTMinNotCtla_swc_in)
                     ||
                      ((VSCtl_tqWhlMinReq_swc_in <= VSCtl_tqWhlPTMaxNotCtla_swc_in)
                      &&
                       (VSCtl_bCtlaTqPT_swc_in == VSSP_Torque_Control_Gmp1_Sf_FAUX))))
                       ||
                    (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET)
                    &&
                      (VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET))
                      &&
                     ((VSCtl_tqWhlMaxReq_swc_in <= VSCtl_tqWhlPTMinNotCtla_swc_in)
                     ||
                      ((VSCtl_tqWhlMaxReq_swc_in <= VSCtl_tqWhlPTMaxNotCtla_swc_in)
                      &&
                       (VSCtl_bCtlaTqPT_swc_in == VSSP_Torque_Control_Gmp1_Sf_FAUX)))))

                   || (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET)
                   &&
                        (VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET))
                        &&
                       (((VSCtl_tqWhlMaxReq_swc_in < VSCtl_tqWhlMinReq_swc_in ? (SInt32)
                          VSCtl_tqWhlMaxReq_swc_in : (SInt32)VSCtl_tqWhlMinReq_swc_in) <=
                         VSCtl_tqWhlPTMinNotCtla_swc_in)
                         || (((VSCtl_tqWhlMaxReq_swc_in <
          VSCtl_tqWhlMinReq_swc_in ? (SInt32)VSCtl_tqWhlMaxReq_swc_in : (SInt32)
          VSCtl_tqWhlMinReq_swc_in) <= VSCtl_tqWhlPTMaxNotCtla_swc_in)
          && (VSCtl_bCtlaTqPT_swc_in ==
          VSSP_Torque_Control_Gmp1_Sf_FAUX)))))
          && (DDS_M_ABS(VSCtl_tqWhlPTMinNotCtla_swc_in
                    - VSCtl_tqWhlPTMaxNotCtla_swc_in) > VSCtl_tqWhlPTNotCtlaWideHi_C))
                    &&
                 ((VSCtl_tqWhlPTPreCoVSCtlReq_swc_in >= VSCtl_tqWhlMaxReq_swc_in)
                 ||
                  (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in <= VSCtl_tqWhlMinReq_swc_in)))
      {
        VSCtl_stTqWhlPTCutOffReqPrev = VSCTL_STTQWHLPTCUTOFFREQPREV_PILOTABLE_B;
        vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_COUPURE_COUPLE_ROUE_GMP =
          (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE;
        vssp_torque_control_gmp1_sf_dwork.is_CONTROLE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_B;
        vssp_vsctl_sttqwhlptcutoffreq_cpy = VSCTL_STTQWHLPTCUTOFFREQ_PILOTABLE_B;
        VSCtl_tiCutOffMinTqWhl = VSCtl_tiCutOffMinTqWhl_C;
        VSCtl_tiPerCutOffTqWhl = VSCtl_tiPerCutOffTqWhl_C;
      }
      break;

     case VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE:
      if ((((VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET) &&
            (VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET))
            || (DDS_M_ABS
            (VSCtl_tqWhlPTMinNotCtla_swc_in - VSCtl_tqWhlPTMaxNotCtla_swc_in) <=
            VSCtl_tqWhlPTNotCtlaWideLo_C))
            || ((VSCtl_tqWhlPTPreCoVSCtlReq_swc_in <
            (VSCtl_tqWhlMaxReq_swc_in - VSCtl_tqWhlMaxReqOff_C)) &&
           (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in > (VSCtl_tqWhlMinReq_swc_in +
             VSCtl_tqWhlMinReqOff_C))))
      {
        vssp_torque_control_gmp1_sf_dwork.is_CONTROLE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD;
        vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_COUPURE_COUPLE_ROUE_GMP =
          (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET;
        vssp_vsctl_sttqwhlptcutoffreq_cpy = VSCTL_STTQWHLPTCUTOFFREQ_ARRET;
        VSCtl_stTqWhlPTCutOffReqPrev = VSCTL_STTQWHLPTCUTOFFREQPREV_ARRET;
        VSCtl_tiCutOffMinTqWhl = VSCtl_tiCutOffMinTqWhl_C;
        VSCtl_tiPerCutOffTqWhl = 0U;
        VSCtl_tiCutOnMinTqWhl = VSCtl_tiCutOnMinTqWhl_C;

      }
      else
      {
        switch (vssp_torque_control_gmp1_sf_dwork.is_CONTROLE)
      {
         case VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_B:
          if ((((((VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET)
          &&
                  (VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET))
                  &&
                 (VSCtl_tqWhlMinReq_swc_in >= VSCtl_tqWhlPTMaxNotCtla_swc_in)) ||
                (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET)
                &&
                  (VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET))
                  &&
                 (VSCtl_tqWhlMaxReq_swc_in >= VSCtl_tqWhlPTMaxNotCtla_swc_in))) ||
               (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET)
               &&
                 (VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET))
                 &&
                ((VSCtl_tqWhlMaxReq_swc_in < (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in >
                   VSCtl_tqWhlMinReq_swc_in ? (SInt32)VSCtl_tqWhlPTPreCoVSCtlReq_swc_in :
                   (SInt32)VSCtl_tqWhlMinReq_swc_in) ? (SInt32)VSCtl_tqWhlMaxReq_swc_in :
                  (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in > VSCtl_tqWhlMinReq_swc_in ? (SInt32)
                   VSCtl_tqWhlPTPreCoVSCtlReq_swc_in : (SInt32)VSCtl_tqWhlMinReq_swc_in)) >=
                 VSCtl_tqWhlPTMaxNotCtla_swc_in)))
                 && (VSCtl_tiCutOffMinTqWhl <= 0))
          {
            vssp_torque_control_gmp1_sf_dwork.is_CONTROLE = (UInt8)
              VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_H;
            vssp_vsctl_sttqwhlptcutoffreq_cpy = VSCTL_STTQWHLPTCUTOFFREQ_PILOTABLE_H;
            VSCtl_tiCutOnMinTqWhl = VSCtl_tiCutOnMinTqWhl_C;

          }
          else
          {
            VSCtl_tiCutOffMinTqWhl = (UInt16)DDS_M_MAX(0, VSCtl_tiCutOffMinTqWhl
              - 1);
            VSCtl_tiPerCutOffTqWhl = (UInt16)DDS_M_MAX(0, VSCtl_tiPerCutOffTqWhl
              - 1);
            VSCtl_stTqWhlPTCutOffReqPrev =
              VSCTL_STTQWHLPTCUTOFFREQPREV_PILOTABLE_B;
          }
          break;

         case VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_H:
          if (((((((VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET)
          &&
                   (VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET))
                   &&
                  (VSCtl_tqWhlMinReq_swc_in <= VSCtl_tqWhlPTMinNotCtla_swc_in)) ||
                 (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET)
                 &&
                   (VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET))
                   &&
                  (VSCtl_tqWhlMaxReq_swc_in <= VSCtl_tqWhlPTMinNotCtla_swc_in))) ||
                (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET)
                &&
                  (VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET))
                  &&
                 ((VSCtl_tqWhlMaxReq_swc_in < (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in >
                    VSCtl_tqWhlMinReq_swc_in ? (SInt32)VSCtl_tqWhlPTPreCoVSCtlReq_swc_in :
                    (SInt32)VSCtl_tqWhlMinReq_swc_in) ? (SInt32)VSCtl_tqWhlMaxReq_swc_in :
                   (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in > VSCtl_tqWhlMinReq_swc_in ? (SInt32)
                    VSCtl_tqWhlPTPreCoVSCtlReq_swc_in : (SInt32)VSCtl_tqWhlMinReq_swc_in)) <=
                  VSCtl_tqWhlPTMinNotCtla_swc_in)))
                  && (VSCtl_tiPerCutOffTqWhl <= 0))
                  &&
              (VSCtl_tiCutOnMinTqWhl <= 0))
          {
            vssp_torque_control_gmp1_sf_dwork.is_CONTROLE = (UInt8)
              VSSP_Torque_Control_Gmp1_Sf_IN_MODE_PILOTABLE_B;
            vssp_vsctl_sttqwhlptcutoffreq_cpy = VSCTL_STTQWHLPTCUTOFFREQ_PILOTABLE_B;
            VSCtl_tiCutOffMinTqWhl = VSCtl_tiCutOffMinTqWhl_C;
            VSCtl_tiPerCutOffTqWhl = VSCtl_tiPerCutOffTqWhl_C;

          }
          else
          {
            VSCtl_tiPerCutOffTqWhl = (UInt16)DDS_M_MAX(0, VSCtl_tiPerCutOffTqWhl
              - 1);
            VSCtl_tiCutOnMinTqWhl = (UInt16)DDS_M_MAX(0, VSCtl_tiCutOnMinTqWhl -
              1);
            VSCtl_stTqWhlPTCutOffReqPrev =
              VSCTL_STTQWHLPTCUTOFFREQPREV_PILOTABLE_H;
          }
          break;
        }
      }
      break;

     default:
      vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_COUPURE_COUPLE_ROUE_GMP =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET;
      vssp_vsctl_sttqwhlptcutoffreq_cpy = VSCTL_STTQWHLPTCUTOFFREQ_ARRET;
      VSCtl_stTqWhlPTCutOffReqPrev = VSCTL_STTQWHLPTCUTOFFREQPREV_ARRET;
      VSCtl_tiCutOffMinTqWhl = VSCtl_tiCutOffMinTqWhl_C;
      VSCtl_tiPerCutOffTqWhl = 0U;
      VSCtl_tiCutOnMinTqWhl = VSCtl_tiCutOnMinTqWhl_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F7111_Determiner_Demande_Coupure_Couple_Roue_GMP*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F7112_Determiner_Demande_Anticipation_Couple_Roue_GMP_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.06.2 */

  if (vssp_torque_control_gmp1_sf_dwork.is_active_c117_VSSP_Torque_Control_Gmp1_Sf
      == 0)
  {
    vssp_torque_control_gmp1_sf_dwork.is_active_c117_VSSP_Torque_Control_Gmp1_Sf
      = 1U;
    vssp_torque_control_gmp1_sf_dwork.is_c117_VSSP_Torque_Control_Gmp1_Sf =
      (UInt8)
      VSSP_Torque_Control_Gmp1_Sf_IN_DEMANDE_ANTICIPATION_COUPLE_ROUE_GMP_MIN;
    vssp_torque_control_gmp1_sf_dwork.is_active_DEMANDE_ANTICIPATION_c = 1U;
    vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION_g = (UInt8)
      VSSP_Torque_Control_Gmp1_Sf_IN_FAUX;
    VSCtl_bAntTqWhlPTMinReq = VSSP_Torque_Control_Gmp1_Sf_FAUX_b;
    vssp_torque_control_gmp1_sf_dwork.is_active_TAUX_ANTICIPATION_c = 1U;
    vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION_n = (UInt8)
      VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_NON_DEMANDEE;
    vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = 0U;
    vssp_torque_control_gmp1_sf_dwork.is_active_MEMOIRES_k = 1U;

  }
  else
  {
    switch (vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION_g)
      {
     case VSSP_Torque_Control_Gmp1_Sf_IN_FAUX:
      if (((VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET) &&
           (VSCtl_stCtl_tqWhlMinPrev != VSCTL_STCTL_TQWHLMINPREV_ARRET))
           &&
          (VSCtl_bAuthAntTqWhlMin_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI_k))
      {
        vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION_g = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_VRAI;
        VSCtl_bAntTqWhlPTMinReq = VSSP_Torque_Control_Gmp1_Sf_VRAI_k;
      }
      break;

     case VSSP_Torque_Control_Gmp1_Sf_IN_VRAI:
      if (((VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET) ||
           (VSCtl_bAuthAntTqWhlMin_swc_in == VSSP_Torque_Control_Gmp1_Sf_FAUX_b))
           ||
          ((VSCtl_stTqWhlPTCutOffReqPrev != VSCtl_stTqWhlPTCutOffMnRPrev)
          &&
           (VSCtl_stTqWhlPTCutOffMnRPrev != VSCTL_STTQWHLPTCUTOFFMNRPREV_ARRET)))
      {
        vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION_g = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_FAUX;
        VSCtl_bAntTqWhlPTMinReq = VSSP_Torque_Control_Gmp1_Sf_FAUX_b;
      }
      break;

     default:
      vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION_g = (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_FAUX;
      VSCtl_bAntTqWhlPTMinReq = VSSP_Torque_Control_Gmp1_Sf_FAUX_b;
      break;
    }

    switch (vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION_n)
      {
     case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DEMANDEE:
      if (VSCtl_bAntTqWhlPTMinReq == VSSP_Torque_Control_Gmp1_Sf_FAUX_b)
      {
        vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_e;
        vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION_n = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_NON_DEMANDEE;
        vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = 0U;

      }
      else
      {
        switch (vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE)
      {
         case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION:
          if ((VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_TRANSITOIRE) &&
              (vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h >=
               VSSP_100_BIN7))
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE;
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h =
              VSSP_100_BIN7;

          }
          else if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_STABILISE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION;

          }
          else
          {
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = (UInt16)
              ((vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h +
                VSCtl_ctInc_rAnt_tqWhlPTMin_C) < VSSP_100_BIN7 ?
               vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h +
               VSCtl_ctInc_rAnt_tqWhlPTMin_C : (SInt32)VSSP_100_BIN7);
          }
          break;

         case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE:
          if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_STABILISE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION;
          }
          break;

         case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DESACTIVEE:
          if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_TRANSITOIRE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION;
          }
          break;

         case VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION:
          if ((VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_STABILISE) &&
              (vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h <= 0))
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DESACTIVEE;
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = 0U;

          }
          else if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_TRANSITOIRE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION;

          }
          else
          {
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = (UInt16)
              DDS_M_MAX(vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h -
                     VSCtl_ctDec_rAnt_tqWhlPTMin_C, 0);
          }
          break;
        }
      }
      break;

     case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_NON_DEMANDEE:
      if (VSCtl_bAntTqWhlPTMinReq == VSSP_Torque_Control_Gmp1_Sf_VRAI_k)
      {
        vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION_n = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DEMANDEE;
        vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE;
        vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = VSSP_100_BIN7;
      }
      break;

     default:
      vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION_n = (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_NON_DEMANDEE;
      vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = 0U;
      break;
    }

    VSCtl_stCtl_tqWhlMinPrev = VSCtl_stCtl_tqWhlMin_swc_in;
    VSCtl_stTqWhlPTCutOffMnRPrev = VSCtl_stTqWhlPTCutOffReqPrev;
  }

  VSCtl_rAnt_tqWhlPTMin = DDS_M_MIN
    (vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h,
     VSCTL_RANT_TQWHLPTMIN_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F7112_Determiner_Demande_Anticipation_Couple_Roue_GMP_Min*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F7113_Determiner_Demande_Anticipation_Couple_Roue_GMP_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.13.2 */

  if (vssp_torque_control_gmp1_sf_dwork.is_active_c120_VSSP_Torque_Control_Gmp1_Sf
      == 0)
  {
    vssp_torque_control_gmp1_sf_dwork.is_active_c120_VSSP_Torque_Control_Gmp1_Sf
      = 1U;
    vssp_torque_control_gmp1_sf_dwork.is_c120_VSSP_Torque_Control_Gmp1_Sf =
      (UInt8)
      VSSP_Torque_Control_Gmp1_Sf_IN_DEMANDE_ANTICIPATION_COUPLE_ROUE_GMP_MAX;
    vssp_torque_control_gmp1_sf_dwork.is_active_DEMANDE_ANTICIPATION = 1U;
    vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION = (UInt8)
      VSSP_Torque_Control_Gmp1_Sf_IN_FAUX_f;
    VSCtl_bAntTqWhlPTMaxReq = VSSP_Torque_Control_Gmp1_Sf_FAUX_p;
    vssp_torque_control_gmp1_sf_dwork.is_active_TAUX_ANTICIPATION = 1U;
    vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION = (UInt8)
      VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_INTERDITE;
    vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = 0U;
    vssp_torque_control_gmp1_sf_dwork.is_active_MEMOIRES = 1U;

  }
  else
  {
    switch (vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION)
      {
     case VSSP_Torque_Control_Gmp1_Sf_IN_FAUX_f:
      if (((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET) &&
           (VSCtl_stCtl_tqWhlMaxPrev != VSCTL_STCTL_TQWHLMAXPREV_ARRET))
           &&
          (VSCtl_bAuthAntTqWhlMax_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI_j))
      {
        vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_VRAI_a;
        VSCtl_bAntTqWhlPTMaxReq = VSSP_Torque_Control_Gmp1_Sf_VRAI_j;
      }
      break;

     case VSSP_Torque_Control_Gmp1_Sf_IN_VRAI_a:
      if (((VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET) ||
           (VSCtl_bAuthAntTqWhlMax_swc_in == VSSP_Torque_Control_Gmp1_Sf_FAUX_p))
           ||
          ((VSCtl_stTqWhlPTCutOffReqPrev != VSCtl_stTqWhlPTCutOffMxRPrev)
          &&
           (VSCtl_stTqWhlPTCutOffMxRPrev != VSCTL_STTQWHLPTCUTOFFMXRPREV_ARRET)))
      {
        vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_FAUX_f;
        VSCtl_bAntTqWhlPTMaxReq = VSSP_Torque_Control_Gmp1_Sf_FAUX_p;
      }
      break;

     default:
      vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION = (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_FAUX_f;
      VSCtl_bAntTqWhlPTMaxReq = VSSP_Torque_Control_Gmp1_Sf_FAUX_p;
      break;
    }

    switch (vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION)
      {
     case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_AUTORISEE:
      if (VSCtl_bAntTqWhlPTMaxReq == VSSP_Torque_Control_Gmp1_Sf_FAUX_p)
      {
        vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_i;
        vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_INTERDITE;
        vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = 0U;

      }
      else
      {
        switch (vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE)
      {
         case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION_h:
          if ((VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_TRANSITOIRE) &&
              (vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n >=
               VSSP_100_BIN7))
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE_j;
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n =
              VSSP_100_BIN7;

          }
          else if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_STABILISE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION_o;

          }
          else
          {
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = (UInt16)
              ((vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n +
                VSCtl_ctInc_rAnt_tqWhlPTMax_C) < VSSP_100_BIN7 ?
               vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n +
               VSCtl_ctInc_rAnt_tqWhlPTMax_C : (SInt32)VSSP_100_BIN7);
          }
          break;

         case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE_j:
          if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_STABILISE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION_o;
          }
          break;

         case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DESACTIVEE_h:
          if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_TRANSITOIRE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION_h;
          }
          break;

         case VSSP_Torque_Control_Gmp1_Sf_IN_DESACTIVATION_o:
          if ((VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_STABILISE) &&
              (vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n <= 0))
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_DESACTIVEE_h;
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = 0U;

          }
          else if (VSCtl_bLgtCtlDyn_swc_in == VSCTL_BLGTCTLDYN_TRANSITOIRE)
          {
            vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE =
              (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIVATION_h;

          }
          else
          {
            vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = (UInt16)
              DDS_M_MAX(vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n -
                     VSCtl_ctDec_rAnt_tqWhlPTMax_C, 0);
          }
          break;
        }
      }
      break;

     case VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_INTERDITE:
      if (VSCtl_bAntTqWhlPTMaxReq == VSSP_Torque_Control_Gmp1_Sf_VRAI_j)
      {
        vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_AUTORISEE;
        vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_ACTIVEE_j;
        vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = VSSP_100_BIN7;
      }
      break;

     default:
      vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION = (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_ANTICIPATION_INTERDITE;
      vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = 0U;
      break;
    }

    VSCtl_stCtl_tqWhlMaxPrev = VSCtl_stCtl_tqWhlMax_swc_in;
    VSCtl_stTqWhlPTCutOffMxRPrev = VSCtl_stTqWhlPTCutOffReqPrev;
  }

  VSCtl_rAnt_tqWhlPTMax = DDS_M_MIN
    (vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n,
     VSCTL_RANT_TQWHLPTMAX_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F7113_Determiner_Demande_Anticipation_Couple_Roue_GMP_Max*/

  /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.03.3 */

/* <PRQA_COMMENT><2742> statement value change with VSCtl_bCtlCmdPTTqCf_SC </2742></PRQA_COMMENT> */
  if (DDS_TRUE==VSCtl_bCtlCmdPTTqCf_SC)
  {

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71211_Determiner_Mode_Commande_Couple_Roue_GMP_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.43.0 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c121_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c121_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c121_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN;
      vssp_torque_control_gmp1_sf_dwork.is_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_n;
      VSCtl_stCtl_tqWhlPTMin = VSCTL_STCTL_TQWHLPTMIN_ARRET;
      VSCtl_bAcvFil_tqWhlPTMin = VSSP_Torque_Control_Gmp1_Sf_FAUX_m;

    }
    else
    {
      switch
        (vssp_torque_control_gmp1_sf_dwork.is_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_n:
        if ((VSCtl_bCtlCmdPTTqCf_SC == VSSP_Torque_Control_Gmp1_Sf_VRAI_h)
        &&
            (VSCtl_stCtl_tqWhlMin_swc_in != VSCTL_STCTL_TQWHLMIN_ARRET))
        {
          vssp_torque_control_gmp1_sf_dwork.is_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_g;
          VSCtl_stCtl_tqWhlPTMin = VSCTL_STCTL_TQWHLPTMIN_CONTROLE;
          VSCtl_bAcvFil_tqWhlPTMin = VSSP_Torque_Control_Gmp1_Sf_VRAI_h;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_g:
        if ((VSCtl_bCtlCmdPTTqCf_SC != VSSP_Torque_Control_Gmp1_Sf_VRAI_h)
        ||
            (VSCtl_stCtl_tqWhlMin_swc_in == VSCTL_STCTL_TQWHLMIN_ARRET))
        {
          vssp_torque_control_gmp1_sf_dwork.is_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_n;
          VSCtl_stCtl_tqWhlPTMin = VSCTL_STCTL_TQWHLPTMIN_ARRET;
          VSCtl_bAcvFil_tqWhlPTMin = VSSP_Torque_Control_Gmp1_Sf_FAUX_m;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN =
          (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_n;
        VSCtl_stCtl_tqWhlPTMin = VSCTL_STCTL_TQWHLPTMIN_ARRET;
        VSCtl_bAcvFil_tqWhlPTMin = VSSP_Torque_Control_Gmp1_Sf_FAUX_m;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71211_Determiner_Mode_Commande_Couple_Roue_GMP_Min*/

    VSSP_F71212_Determiner_Consigne_Couple_Roue_Gmp_Min(VSCtl_tqWhlMinReq_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                                                        &vssp_vsctl_tqwhlptminreq_cpy /* BIN1 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71213_Determiner_Effectivite_Couple_Roue_GMP_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.09.1 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c122_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c122_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c122_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_COUPLE_ROUE_GMP_MIN;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MIN =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF;
      vssp_vsctl_bctlefc_tqwhlptmin_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_j;

    }
    else
    {
      switch
        (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MIN)
        {
       case VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF:
        if ((VSCtl_stCtl_tqWhlPTMin == VSCTL_STCTL_TQWHLMIN_ARRET) ||
            (vssp_vsctl_tqwhlptminreq_cpy <= VSCtl_tqWhlPTPreCoVSCtlReq_swc_in))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MIN =
            (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF;
          vssp_vsctl_bctlefc_tqwhlptmin_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_j;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF:
        if ((VSCtl_stCtl_tqWhlPTMin != VSCTL_STCTL_TQWHLMIN_ARRET) &&
            (vssp_vsctl_tqwhlptminreq_cpy > VSCtl_tqWhlPTPreCoVSCtlReq_swc_in))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MIN =
            (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF;
          vssp_vsctl_bctlefc_tqwhlptmin_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_jw;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MIN =
          (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF;
        vssp_vsctl_bctlefc_tqwhlptmin_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_j;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71213_Determiner_Effectivite_Couple_Roue_GMP_Min*/

  VSSP_F71214_Determiner_Position_Pedale_Accelerateur_Gmp_Min(VSCtl_spdVeh_swc_in, /* BIN7 */
                                                                VSCtl_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                                                                VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                                                                vssp_vsctl_tqwhlptminreq_cpy, /* BIN1 */
                                                                &vssp_vsctl_raccpptmin_cpy /* BIN7 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71215_Determiner_Effectivite_Position_Pedale_Accelerateur_GMP_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.44.0 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c123_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c123_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c123_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN
        = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_i;
      VSCtl_bCtlEfc_rAccPMin_pt1 = VSSP_Torque_Control_Gmp1_Sf_FAUX_f;

    }
    else
    {
      switch
        (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_a:
        if ((VSCtl_stCtl_tqWhlPTMin == VSCTL_STCTL_TQWHLMIN_ARRET) ||
            (vssp_vsctl_raccpptmin_cpy <= AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_i;
          VSCtl_bCtlEfc_rAccPMin_pt1 = VSSP_Torque_Control_Gmp1_Sf_FAUX_f;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_i:
        if ((VSCtl_stCtl_tqWhlPTMin != VSCTL_STCTL_TQWHLMIN_ARRET) &&
            (vssp_vsctl_raccpptmin_cpy > AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_a;
          VSCtl_bCtlEfc_rAccPMin_pt1 = VSSP_Torque_Control_Gmp1_Sf_VRAI_i;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN
          = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_i;
        VSCtl_bCtlEfc_rAccPMin_pt1 = VSSP_Torque_Control_Gmp1_Sf_FAUX_f;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71215_Determiner_Effectivite_Position_Pedale_Accelerateur_GMP_Min*/


	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.15.3 */

    vssp_torque_control_gmp1_sf_b.vss_Keep_Global_Data_From_Input =
      vssp_torque_control_gmp1_delay_0;


    /* TAG_START_OF_STATEFLOW_FUNCTION: F71222_Determiner_Mode_Commande_Couple_Roue_GMP_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.46.0 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c124_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c124_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c124_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_MODE_CONTROLE_COUPLE_ROUE_GMP_MAX;
      vssp_torque_control_gmp1_sf_dwork.is_active_FIN_TRANSITION = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_FIN_TRANSITION = (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_NON_REPRISE;
      VSCtl_bTranEnd_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_FAUX_l;
      vssp_torque_control_gmp1_sf_dwork.is_active_ETAT_CONTROLE = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_INIT;
      VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_INIT;
      VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_FAUX_l;
      VSCtl_tiFiltqWhlPTMaxReq = VSCtl_tiFiltqWhlPTMaxReq_C;

    }
    else
    {
      switch (vssp_torque_control_gmp1_sf_dwork.is_FIN_TRANSITION)
        {
       case VSSP_Torque_Control_Gmp1_Sf_IN_NON_REPRISE:
        if (vssp_torque_control_gmp1_sf_b.vss_Keep_Global_Data_From_Input >=
            VSCtl_tqWhlPTPreCoVSCtlReq_swc_in)
        {
          vssp_torque_control_gmp1_sf_dwork.is_FIN_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_REPRISE;
          VSCtl_bTranEnd_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_VRAI_jv;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_REPRISE:
        if ((vssp_torque_control_gmp1_sf_b.vss_Keep_Global_Data_From_Input <
             VSCtl_tqWhlPTPreCoVSCtlReq_swc_in) && (VSCtl_stCtl_tqWhlMax_swc_in !=
             VSCTL_STCTL_TQWHLMAX_ARRET))
        {
          vssp_torque_control_gmp1_sf_dwork.is_FIN_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_NON_REPRISE;
          VSCtl_bTranEnd_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_FAUX_l;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_FIN_TRANSITION = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_NON_REPRISE;
        VSCtl_bTranEnd_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_FAUX_l;
        break;
      }

      switch (vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE)
        {
       case VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_p:
        if ((VSCtl_stCtl_tqWhlMax_swc_in != VSCTL_STCTL_TQWHLMAX_ARRET) &&
            (VSCtl_bCtlCmdPTTqCf_SC == VSSP_Torque_Control_Gmp1_Sf_VRAI_jv))
        {
          vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_b;
          VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_CONTROLE;
          VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_VRAI_jv;
          VSCtl_tiFiltqWhlPTMaxReq = VSCtl_tiFiltqWhlPTMaxReq_C;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_b:
        if ((VSCtl_stCtl_tqWhlMax_swc_in == VSCTL_STCTL_TQWHLMAX_ARRET) ||
            (VSCtl_bCtlCmdPTTqCf_SC != VSSP_Torque_Control_Gmp1_Sf_VRAI_jv))
        {
          vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_TRANSITION;
          vssp_torque_control_gmp1_sf_dwork.is_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_LENTE;
          VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_TRANS_L;
          VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_VRAI_jv;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_INIT:
        if (VSCtl_bTranEnd_tqWhlPTMax == VSSP_Torque_Control_Gmp1_Sf_FAUX_l)
        {
          vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_TRANSITION;
          vssp_torque_control_gmp1_sf_dwork.is_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_LENTE;
          VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_TRANS_L;
          VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_VRAI_jv;

        }
        else if (VSCtl_bTranEnd_tqWhlPTMax ==
                   VSSP_Torque_Control_Gmp1_Sf_VRAI_jv)
        {
          vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_p;
          VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_ARRET;
          VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_FAUX_l;
          VSCtl_tiFiltqWhlPTMaxReq = VSCtl_tiFiltqWhlPTMaxReq_C;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_TRANSITION:
        if (VSCtl_bTranEnd_tqWhlPTMax == VSSP_Torque_Control_Gmp1_Sf_VRAI_jv)
        {
          vssp_torque_control_gmp1_sf_dwork.is_TRANSITION = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_a;
          vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_p;
          VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_ARRET;
          VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_FAUX_l;
          VSCtl_tiFiltqWhlPTMaxReq = VSCtl_tiFiltqWhlPTMaxReq_C;

        }
        else
        {
          switch (vssp_torque_control_gmp1_sf_dwork.is_TRANSITION)
        {
           case VSSP_Torque_Control_Gmp1_Sf_IN_LENTE:
            if (VSCtl_bFastDeacVSLimReq_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI_jv)
            {
              vssp_torque_control_gmp1_sf_dwork.is_TRANSITION = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_RAPIDE;
              VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_TRANS_R;
              VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_VRAI_jv;

            }
            else
            {
              VSCtl_tiFiltqWhlPTMaxReq = (UInt16)DDS_M_MAX
                (VSCtl_tiFiltqWhlPTMaxReq - 1, 0);
            }
            break;

           case VSSP_Torque_Control_Gmp1_Sf_IN_RAPIDE:
            VSCtl_tiFiltqWhlPTMaxReq = (UInt16)DDS_M_MAX(VSCtl_tiFiltqWhlPTMaxReq
              - 1, 0);
            break;
          }
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = (UInt8)
          VSSP_Torque_Control_Gmp1_Sf_IN_INIT;
        VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_INIT;
        VSCtl_bAcvFil_tqWhlPTMax = VSSP_Torque_Control_Gmp1_Sf_FAUX_l;
        VSCtl_tiFiltqWhlPTMaxReq = VSCtl_tiFiltqWhlPTMaxReq_C;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71222_Determiner_Mode_Commande_Couple_Roue_GMP_Max*/

    VSSP_F71223_Determiner_Consigne_Couple_Roue_Gmp_Max(VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                        VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                                                        &vssp_vsctl_tqwhlptmaxreq_cpy /* BIN1 */);

  VSSP_F71221_Determiner_Consigne_Couple_Roue_Gmp_Max_Init(vssp_vsctl_tqwhlptmaxreq_cpy /* BIN1 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71224_Determiner_Effectivite_Couple_Roue_GMP_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.18.2 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c125_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c125_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c125_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_COUPLE_ROUE_GMP_MAX;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MAX =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_f;
      vssp_vsctl_bctlefc_tqwhlptmax_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_kh;

    }
    else
    {
      switch
        (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MAX)
        {
       case VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_f:
        if ((VSCtl_stCtl_tqWhlPTMax == VSCTL_STCTL_TQWHLPTMAX_ARRET)
        ||
            (vssp_vsctl_tqwhlptmaxreq_cpy >= (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in >
              vssp_vsctl_tqwhlptminreq_cpy ? (SInt32)VSCtl_tqWhlPTPreCoVSCtlReq_swc_in :
              (SInt32)vssp_vsctl_tqwhlptminreq_cpy)))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MAX =
            (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_p;
          vssp_vsctl_bctlefc_tqwhlptmax_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_k;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_p:
        if ((VSCtl_stCtl_tqWhlPTMax != VSCTL_STCTL_TQWHLPTMAX_ARRET)
        &&
            (vssp_vsctl_tqwhlptmaxreq_cpy < (VSCtl_tqWhlPTPreCoVSCtlReq_swc_in >
              vssp_vsctl_tqwhlptminreq_cpy ? (SInt32)VSCtl_tqWhlPTPreCoVSCtlReq_swc_in :
              (SInt32)vssp_vsctl_tqwhlptminreq_cpy)))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MAX =
            (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_f;
          vssp_vsctl_bctlefc_tqwhlptmax_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_kh;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MAX =
          (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_f;
        vssp_vsctl_bctlefc_tqwhlptmax_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_kh;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71224_Determiner_Effectivite_Couple_Roue_GMP_Max*/

  VSSP_F71225_Determiner_Position_Pedale_Accelerateur_Gmp_Max(VSCtl_spdVeh_swc_in, /* BIN7 */
                                                                VSCtl_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                                                                VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                                                                vssp_vsctl_tqwhlptmaxreq_cpy, /* BIN1 */
                                                                &vssp_vsctl_raccpptmax_cpy /* BIN7 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71226_Determiner_Effectivite_Position_Pedale_Accelerateur_GMP_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.47.0 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c126_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c126_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c126_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX
        = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_c;
      VSCtl_bCtlEfc_rAccPMax_pt1 = VSSP_Torque_Control_Gmp1_Sf_FAUX_n;

    }
    else
    {
      switch
        (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_h:
        if ((VSCtl_stCtl_tqWhlPTMax == VSCTL_STCTL_TQWHLPTMAX_ARRET)
        ||
            (vssp_vsctl_raccpptmax_cpy >= AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_c;
          VSCtl_bCtlEfc_rAccPMax_pt1 = VSSP_Torque_Control_Gmp1_Sf_FAUX_n;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_c:
        if ((VSCtl_stCtl_tqWhlPTMax != VSCTL_STCTL_TQWHLPTMAX_ARRET)
        &&
            (vssp_vsctl_raccpptmax_cpy < AccP_rAccP_swc_in))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_h;
          VSCtl_bCtlEfc_rAccPMax_pt1 = VSSP_Torque_Control_Gmp1_Sf_VRAI_j5;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX
          = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_c;
        VSCtl_bCtlEfc_rAccPMax_pt1 = VSSP_Torque_Control_Gmp1_Sf_FAUX_n;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71226_Determiner_Effectivite_Position_Pedale_Accelerateur_GMP_Max*/

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.48.0 */

    /* TAG_START_OF_STATEFLOW_FUNCTION: F71231_Determiner_Mode_Commande_Limitation_Couple_Roue_GMP_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.49.0 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c127_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c127_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c127_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)
        VSSP_Torque_Control_Gmp1_Sf_IN_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP;
      vssp_torque_control_gmp1_sf_dwork.is_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP
        = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_o;
      VSCtl_stTqWhlPTMinSat = VSCTL_STTQWHLPTMINSAT_ARRET;
      vssp_vsctl_bacvtqwhlptminsat_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_np;
      VSCtl_bAcvFilTqWhlPTMinSat = VSSP_Torque_Control_Gmp1_Sf_FAUX_np;

    }
    else
    {
      switch
        (vssp_torque_control_gmp1_sf_dwork.is_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_o:
        if (((VSCtl_stCtl_tqWhlPTMin == VSCTL_STCTL_TQWHLPTMIN_CONTROLE)
        ||
             (VSCtl_stCtl_tqWhlPTMax == VSCTL_STCTL_TQWHLPTMAX_CONTROLE))
             &&
            (VSCtl_bTqWhlMinSat_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI_d))
        {
          vssp_torque_control_gmp1_sf_dwork.is_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_MARCHE;
          vssp_torque_control_gmp1_sf_dwork.is_MARCHE = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_d;
          VSCtl_stTqWhlPTMinSat = VSCTL_STTQWHLPTMINSAT_CONTROLE_32;
          vssp_vsctl_bacvtqwhlptminsat_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_d;
          VSCtl_bAcvFilTqWhlPTMinSat = VSSP_Torque_Control_Gmp1_Sf_VRAI_d;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_MARCHE:
        if ((VSCtl_bTqWhlMinSat_swc_in != VSSP_Torque_Control_Gmp1_Sf_VRAI_d)
        &&
            ((VSCtl_tqWhlPTDrvMinReqRaw_swc_in >= (VSCtl_tqWhlPTDrvMinReq_swc_in - VSSP_1_BIN1))
             || (VSCtl_tiTqWhlPTMinSatTraMax <= 0)))
        {
          vssp_torque_control_gmp1_sf_dwork.is_MARCHE = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_j;
          vssp_torque_control_gmp1_sf_dwork.is_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_o;
          VSCtl_stTqWhlPTMinSat = VSCTL_STTQWHLPTMINSAT_ARRET;
          vssp_vsctl_bacvtqwhlptminsat_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_np;
          VSCtl_bAcvFilTqWhlPTMinSat = VSSP_Torque_Control_Gmp1_Sf_FAUX_np;

        }
        else
        {
          switch (vssp_torque_control_gmp1_sf_dwork.is_MARCHE)
        {
           case VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_d:
            if (VSCtl_bTqWhlMinSat_swc_in != VSSP_Torque_Control_Gmp1_Sf_VRAI_d)
            {
              vssp_torque_control_gmp1_sf_dwork.is_MARCHE = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_TRANSITION_g;
              VSCtl_stTqWhlPTMinSat = VSCTL_STTQWHLPTMINSAT_TRANSITION_32;
              vssp_vsctl_bacvtqwhlptminsat_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_d;
              VSCtl_bAcvFilTqWhlPTMinSat = VSSP_Torque_Control_Gmp1_Sf_FAUX_np;
              VSCtl_tiTqWhlPTMinSatTraMax = VSCtl_tiTqWhlPTMinSatTraMax_C;
            }
            break;

           case VSSP_Torque_Control_Gmp1_Sf_IN_TRANSITION_g:
            if (((VSCtl_stCtl_tqWhlPTMin == VSCTL_STCTL_TQWHLPTMIN_CONTROLE)
            ||
                 (VSCtl_stCtl_tqWhlPTMax == VSCTL_STCTL_TQWHLPTMAX_CONTROLE))
                 &&
                (VSCtl_bTqWhlMinSat_swc_in == VSSP_Torque_Control_Gmp1_Sf_VRAI_d))
            {
              vssp_torque_control_gmp1_sf_dwork.is_MARCHE = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_CONTROLE_d;
              VSCtl_stTqWhlPTMinSat = VSCTL_STTQWHLPTMINSAT_CONTROLE_32;
              vssp_vsctl_bacvtqwhlptminsat_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_d;
              VSCtl_bAcvFilTqWhlPTMinSat = VSSP_Torque_Control_Gmp1_Sf_VRAI_d;

            }
            else
            {
              VSCtl_tiTqWhlPTMinSatTraMax = (UInt16)DDS_M_MAX(0,
                VSCtl_tiTqWhlPTMinSatTraMax - 1);
            }
            break;
          }
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP
          = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ARRET_o;
        VSCtl_stTqWhlPTMinSat = VSCTL_STTQWHLPTMINSAT_ARRET;
        vssp_vsctl_bacvtqwhlptminsat_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_np;
        VSCtl_bAcvFilTqWhlPTMinSat = VSSP_Torque_Control_Gmp1_Sf_FAUX_np;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F71231_Determiner_Mode_Commande_Limitation_Couple_Roue_GMP_Min*/

  VSSP_F71232_Determiner_Consigne_Limitation_Couple_Roue_Gmp_Min(VSCtl_tqWhlMinSat_swc_in, /* BIN1 */
                                                                    VSCtl_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1 */
                                                                    &vssp_vsctl_tqwhlptminsat_cpy /* BIN1 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F7124_Determiner_Effectivite_Processus_XVV*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.51.0 */

    if (vssp_torque_control_gmp1_sf_dwork.is_active_c128_VSSP_Torque_Control_Gmp1_Sf
        == 0)
    {
      vssp_torque_control_gmp1_sf_dwork.is_active_c128_VSSP_Torque_Control_Gmp1_Sf
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_c128_VSSP_Torque_Control_Gmp1_Sf =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIVITE_PROCESSUS_XVV;
      vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1 =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
      vssp_vsctl_sttqptminctl_pt1_cpy = VSCTL_STTQPTMINCTL_PT1_INACTIF;
      vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1 =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
      vssp_vsctl_sttqptmaxctl_pt1_cpy = VSCTL_STTQPTMAXCTL_PT1_INACTIF;
      vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
        = 1U;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
        = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
      VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_INACTIF;
      vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_COUPLE_ROUE_GMP1 =
        1U;
      vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP1 =
        (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_l;
      vssp_vsctl_bctlefc_tqwhlpt_pt1_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_lk;

    }
    else
    {
      switch
        (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF:
        if (VSCtl_stCtl_tqWhlPTMin == VSCTL_STCTL_TQWHLPTMIN_ARRET)
        {
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_c;
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
          vssp_vsctl_sttqptminctl_pt1_cpy = VSCTL_STTQPTMINCTL_PT1_INACTIF;

        }
        else
        {
          switch (vssp_torque_control_gmp1_sf_dwork.is_ACTIF)
            {
           case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqwhlptmin_cpy == VSSP_Torque_Control_Gmp1_Sf_FAUX_lk)
            {
              vssp_torque_control_gmp1_sf_dwork.is_ACTIF = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF;
              vssp_vsctl_sttqptminctl_pt1_cpy = VSCTL_STTQPTMINCTL_PT1_ANE;
            }
            break;

           case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqwhlptmin_cpy == VSSP_Torque_Control_Gmp1_Sf_VRAI_l)
            {
              vssp_torque_control_gmp1_sf_dwork.is_ACTIF = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF;
              vssp_vsctl_sttqptminctl_pt1_cpy = VSCTL_STTQPTMINCTL_PT1_AE;
            }
            break;
          }
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF:
        if ((VSCtl_stCtl_tqWhlPTMin != VSCTL_STCTL_TQWHLPTMIN_ARRET)
        &&
            (vssp_vsctl_bctlefc_tqwhlptmin_cpy == VSSP_Torque_Control_Gmp1_Sf_FAUX_lk))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF;
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF;
          vssp_vsctl_sttqptminctl_pt1_cpy = VSCTL_STTQPTMINCTL_PT1_ANE;

        }
        else if ((VSCtl_stCtl_tqWhlPTMin != VSCTL_STCTL_TQWHLPTMIN_ARRET)
        &&
                   (vssp_vsctl_bctlefc_tqwhlptmin_cpy ==
                    VSSP_Torque_Control_Gmp1_Sf_VRAI_l))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF;
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF;
          vssp_vsctl_sttqptminctl_pt1_cpy = VSCTL_STTQPTMINCTL_PT1_AE;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1
          = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
        vssp_vsctl_sttqptminctl_pt1_cpy = VSCTL_STTQPTMINCTL_PT1_INACTIF;
        break;
      }

      switch
        (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF:
        if (VSCtl_stCtl_tqWhlPTMax == VSCTL_STCTL_TQWHLPTMAX_ARRET)
        {
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF_l = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_c;
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
          vssp_vsctl_sttqptmaxctl_pt1_cpy = VSCTL_STTQPTMAXCTL_PT1_INACTIF;

        }
        else
        {
          switch (vssp_torque_control_gmp1_sf_dwork.is_ACTIF_l)
        {
           case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqwhlptmax_cpy == VSSP_Torque_Control_Gmp1_Sf_FAUX_lk)
            {
              vssp_torque_control_gmp1_sf_dwork.is_ACTIF_l = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF;
              vssp_vsctl_sttqptmaxctl_pt1_cpy = VSCTL_STTQPTMAXCTL_PT1_ANE;
            }
            break;

           case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF:
            if (vssp_vsctl_bctlefc_tqwhlptmax_cpy == VSSP_Torque_Control_Gmp1_Sf_VRAI_l)
            {
              vssp_torque_control_gmp1_sf_dwork.is_ACTIF_l = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF;
              vssp_vsctl_sttqptmaxctl_pt1_cpy = VSCTL_STTQPTMAXCTL_PT1_AE;
            }
            break;
          }
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF:
        if ((VSCtl_stCtl_tqWhlPTMax != VSCTL_STCTL_TQWHLPTMAX_ARRET)
        &&
            (vssp_vsctl_bctlefc_tqwhlptmax_cpy == VSSP_Torque_Control_Gmp1_Sf_FAUX_lk))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF;
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF_l = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF;
          vssp_vsctl_sttqptmaxctl_pt1_cpy = VSCTL_STTQPTMAXCTL_PT1_ANE;

        }
        else if ((VSCtl_stCtl_tqWhlPTMax != VSCTL_STCTL_TQWHLPTMAX_ARRET)
        &&
                   (vssp_vsctl_bctlefc_tqwhlptmax_cpy ==
                    VSSP_Torque_Control_Gmp1_Sf_VRAI_l))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF;
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF_l = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF;
          vssp_vsctl_sttqptmaxctl_pt1_cpy = VSCTL_STTQPTMAXCTL_PT1_AE;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1
          = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
        vssp_vsctl_sttqptmaxctl_pt1_cpy = VSCTL_STTQPTMAXCTL_PT1_INACTIF;
        break;
      }

      switch
        (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF:
        if ((VSCtl_stCtl_tqWhlPTMin != VSCTL_STCTL_TQWHLPTMIN_ARRET)
        &&
            (VSCtl_stCtl_tqWhlPTMax != VSCTL_STCTL_TQWHLPTMAX_ARRET))
        {
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF_i = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_NO_ACTIVE_CHILD_c;
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
          VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_INACTIF;

        }
        else
        {
          switch (vssp_torque_control_gmp1_sf_dwork.is_ACTIF_i)
        {
           case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF:
            if ((VSCtl_bCtlEfc_rAccPMin_pt1 !=
                 VSSP_Torque_Control_Gmp1_Sf_VRAI_l) &&
                (VSCtl_bCtlEfc_rAccPMax_pt1 !=
                 VSSP_Torque_Control_Gmp1_Sf_VRAI_l))
            {
              vssp_torque_control_gmp1_sf_dwork.is_ACTIF_i = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF;
              VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_ANE;
            }
            break;

           case VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF:
            if ((VSCtl_bCtlEfc_rAccPMin_pt1 ==
                 VSSP_Torque_Control_Gmp1_Sf_VRAI_l) ||
                (VSCtl_bCtlEfc_rAccPMax_pt1 ==
                 VSSP_Torque_Control_Gmp1_Sf_VRAI_l))
            {
              vssp_torque_control_gmp1_sf_dwork.is_ACTIF_i = (UInt8)
                VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF;
              VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_AE;
            }
            break;
          }
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF:
        if ((((VSCtl_stCtl_tqWhlPTMin != VSCTL_STCTL_TQWHLPTMIN_ARRET)
        ||
              (VSCtl_stCtl_tqWhlPTMax != VSCTL_STCTL_TQWHLPTMAX_ARRET))
              &&
             (VSCtl_bCtlEfc_rAccPMin_pt1 != VSSP_Torque_Control_Gmp1_Sf_VRAI_l))

            && (VSCtl_bCtlEfc_rAccPMax_pt1 != VSSP_Torque_Control_Gmp1_Sf_VRAI_l))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF;
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF_i = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_NON_EFFECTIF;
          VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_ANE;

        }
        else if (((VSCtl_stCtl_tqWhlPTMin != VSCTL_STCTL_TQWHLPTMIN_ARRET)
        ||
                    (VSCtl_stCtl_tqWhlPTMax != VSCTL_STCTL_TQWHLPTMAX_ARRET))
                    &&
                   ((VSCtl_bCtlEfc_rAccPMin_pt1 ==
                     VSSP_Torque_Control_Gmp1_Sf_VRAI_l) ||
                    (VSCtl_bCtlEfc_rAccPMax_pt1 ==
                     VSSP_Torque_Control_Gmp1_Sf_VRAI_l)))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
            = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF;
          vssp_torque_control_gmp1_sf_dwork.is_ACTIF_i = (UInt8)
            VSSP_Torque_Control_Gmp1_Sf_IN_ACTIF_EFFECTIF;
          VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_AE;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
          = (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_INACTIF;
        VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_INACTIF;
        break;
      }

      switch (vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP1)
      {
       case VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_m:
        if ((vssp_vsctl_bctlefc_tqwhlptmin_cpy == VSSP_Torque_Control_Gmp1_Sf_FAUX_lk)
        &&
            (vssp_vsctl_bctlefc_tqwhlptmax_cpy == VSSP_Torque_Control_Gmp1_Sf_FAUX_lk))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP1 =
            (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_l;
          vssp_vsctl_bctlefc_tqwhlpt_pt1_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_lk;
        }
        break;

       case VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_l:
        if ((vssp_vsctl_bctlefc_tqwhlptmin_cpy == VSSP_Torque_Control_Gmp1_Sf_VRAI_l)
        ||
            (vssp_vsctl_bctlefc_tqwhlptmax_cpy == VSSP_Torque_Control_Gmp1_Sf_VRAI_l))
        {
          vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP1 =
            (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_EFFECTIF_m;
          vssp_vsctl_bctlefc_tqwhlpt_pt1_cpy = VSSP_Torque_Control_Gmp1_Sf_VRAI_l;
        }
        break;

       default:
        vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP1 =
          (UInt8)VSSP_Torque_Control_Gmp1_Sf_IN_NON_EFFECTIF_l;
        vssp_vsctl_bctlefc_tqwhlpt_pt1_cpy = VSSP_Torque_Control_Gmp1_Sf_FAUX_lk;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F7124_Determiner_Effectivite_Processus_XVV*/


    vssp_torque_control_gmp1_delay_0 = VSCtl_tqWhlPTMaxReqDly;
  }

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_tqWhlPTMaxReq_swc_out = vssp_vsctl_tqwhlptmaxreq_cpy;

  *VSCtl_tqWhlPTMinReq_swc_out = vssp_vsctl_tqwhlptminreq_cpy;

  *VSCtl_tqWhlPTMinSat_swc_out = vssp_vsctl_tqwhlptminsat_cpy;

  *VSCtl_rAccPPTMax_swc_out = vssp_vsctl_raccpptmax_cpy;

  *VSCtl_rAccPPTMin_swc_out = vssp_vsctl_raccpptmin_cpy;

  *VSCtl_bAcvTqWhlPTMinSat_swc_out = vssp_vsctl_bacvtqwhlptminsat_cpy;

  *VSCtl_bCtlEfc_tqWhlPTMax_swc_out = vssp_vsctl_bctlefc_tqwhlptmax_cpy;

  *VSCtl_bCtlEfc_tqWhlPTMin_swc_out = vssp_vsctl_bctlefc_tqwhlptmin_cpy;

  *VSCtl_bCtlEfc_tqWhlPT_pt1_swc_out = vssp_vsctl_bctlefc_tqwhlpt_pt1_cpy;

  *VSCtl_stTqPTMaxCtl_pt1_swc_out = vssp_vsctl_sttqptmaxctl_pt1_cpy;

  *VSCtl_stTqPTMinCtl_pt1_swc_out = vssp_vsctl_sttqptminctl_pt1_cpy;

  *VSCtl_stTqWhlPTCutOffReq_swc_out = vssp_vsctl_sttqwhlptcutoffreq_cpy;

}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp1_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTCutOffReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bAcvTqWhlPTMinSat_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt1_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinSat_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMin_swc_out,                             /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMaxReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMax_swc_out)                             /*BIN7*/
{
    VSSP_Control_Wheel_Gmp1_Sl_Init(VSCtl_rAccPPTMax_swc_out, /* BIN7 */
                                    VSCtl_rAccPPTMin_swc_out, /* BIN7 */
                                    VSCtl_tqWhlPTMaxReq_swc_out, /* BIN1 */
                                    VSCtl_tqWhlPTMinReq_swc_out, /* BIN1 */
                                    VSCtl_tqWhlPTMinSat_swc_out /* BIN1 */);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  VSCtl_rAnt_tqWhlPTMin=0;
  vssp_torque_control_gmp1_sf_b.vss_Keep_Global_Data_From_Input=0;
  VSCtl_rAnt_tqWhlPTMax=0;
  vssp_vsctl_raccpptmin_cpy = *VSCtl_rAccPPTMin_swc_out;

  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiTqWhlPTMinSatTraMax = VSCtl_tiTqWhlPTMinSatTraMax_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiFiltqWhlPTMaxReq = VSCtl_tiFiltqWhlPTMaxReq_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiCutOffMinTqWhl = VSCtl_tiCutOffMinTqWhl_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiPerCutOffTqWhl = ((UInt16)0U);
  VSCtl_tiCutOnMinTqWhl = VSCtl_tiCutOnMinTqWhl_C;  /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_tqwhlptminsat_cpy = *VSCtl_tqWhlPTMinSat_swc_out;

  vssp_vsctl_tqwhlptmaxreq_cpy = *VSCtl_tqWhlPTMaxReq_swc_out;

  vssp_vsctl_tqwhlptminreq_cpy = *VSCtl_tqWhlPTMinReq_swc_out;

  vssp_vsctl_raccpptmax_cpy = *VSCtl_rAccPPTMax_swc_out;

  *VSCtl_stTqPTMinCtl_pt1_swc_out = VSCTL_STTQPTMINCTL_PT1_INACTIF; /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_sttqptminctl_pt1_cpy = *VSCtl_stTqPTMinCtl_pt1_swc_out;

  *VSCtl_stTqPTMaxCtl_pt1_swc_out = VSCTL_STTQPTMAXCTL_PT1_INACTIF; /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_sttqptmaxctl_pt1_cpy = *VSCtl_stTqPTMaxCtl_pt1_swc_out;

  VSCtl_st_rAccPCtl_pt1 = VSCTL_ST_RACCPCTL_PT1_INACTIF;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stTqWhlPTMinSat = VSCTL_STTQWHLPTMINSAT_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_tqWhlPTMax = VSCTL_STCTL_TQWHLPTMAX_INIT; /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_tqWhlPTMin = VSCTL_STCTL_TQWHLPTMIN_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_tqWhlMaxPrev = VSCTL_STCTL_TQWHLMAXPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stTqWhlPTCutOffMxRPrev = VSCTL_STTQWHLPTCUTOFFMXRPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_tqWhlMinPrev = VSCTL_STCTL_TQWHLMINPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stTqWhlPTCutOffMnRPrev = VSCTL_STTQWHLPTCUTOFFMNRPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  *VSCtl_stTqWhlPTCutOffReq_swc_out = VSCTL_STTQWHLPTCUTOFFREQ_ARRET;   /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_sttqwhlptcutoffreq_cpy = *VSCtl_stTqWhlPTCutOffReq_swc_out;

  VSCtl_stTqWhlPTCutOffReqPrev = VSCTL_STTQWHLPTCUTOFFREQPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  *VSCtl_bCtlEfc_tqWhlPTMax_swc_out = DDS_TRUE;
  vssp_vsctl_bctlefc_tqwhlptmax_cpy = *VSCtl_bCtlEfc_tqWhlPTMax_swc_out;




  vssp_torque_control_gmp1_sf_dwork.is_MODE_CONTROLE_COUPLE_ROUE_GMP_MIN = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c121_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c121_VSSP_Torque_Control_Gmp1_Sf = 0U;
  VSCtl_bAcvFil_tqWhlPTMin =DDS_FALSE;



  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MIN = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c122_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c122_VSSP_Torque_Control_Gmp1_Sf = 0U;
  *VSCtl_bCtlEfc_tqWhlPTMin_swc_out =DDS_FALSE;
  vssp_vsctl_bctlefc_tqwhlptmin_cpy = *VSCtl_bCtlEfc_tqWhlPTMin_swc_out;




  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MIN
    = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c123_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c123_VSSP_Torque_Control_Gmp1_Sf = 0U;
  VSCtl_bCtlEfc_rAccPMin_pt1 =DDS_FALSE;


  vssp_torque_control_gmp1_delay_0 = VSSP_TORQUE_CONTROL_GMP1_CONST_0;


  vssp_torque_control_gmp1_sf_dwork.is_active_ETAT_CONTROLE = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_ETAT_CONTROLE = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_TRANSITION = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_FIN_TRANSITION = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_FIN_TRANSITION = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c124_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c124_VSSP_Torque_Control_Gmp1_Sf = 0U;
  VSCtl_bAcvFil_tqWhlPTMax =DDS_FALSE;
  VSCtl_bTranEnd_tqWhlPTMax =DDS_FALSE;



  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP_MAX = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c125_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c125_VSSP_Torque_Control_Gmp1_Sf = 0U;



  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP_MAX
    = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c126_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c126_VSSP_Torque_Control_Gmp1_Sf = 0U;
  VSCtl_bCtlEfc_rAccPMax_pt1 =DDS_FALSE;



  vssp_torque_control_gmp1_sf_dwork.is_MODE_CALCUL_CONSIGNE_LIMITATION_COUPLE_ROUE_GMP
    = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_MARCHE = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c127_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c127_VSSP_Torque_Control_Gmp1_Sf = 0U;
  *VSCtl_bAcvTqWhlPTMinSat_swc_out =DDS_FALSE;
  vssp_vsctl_bacvtqwhlptminsat_cpy = *VSCtl_bAcvTqWhlPTMinSat_swc_out;

  VSCtl_bAcvFilTqWhlPTMinSat =DDS_FALSE;



  vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1
    = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MAX_GMP1 = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_ACTIF_l = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1
    = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_GMP_XVV_MIN_GMP1 = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_ACTIF = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_COUPLE_ROUE_GMP1 = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_COUPLE_ROUE_GMP1 = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
    = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_EFFECTIVITE_POSITION_PEDALE_ACCELERATEUR_GMP1
    = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_ACTIF_i = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c128_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c128_VSSP_Torque_Control_Gmp1_Sf = 0U;
  *VSCtl_bCtlEfc_tqWhlPT_pt1_swc_out =DDS_FALSE;
  vssp_vsctl_bctlefc_tqwhlpt_pt1_cpy = *VSCtl_bCtlEfc_tqWhlPT_pt1_swc_out;










  vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_COUPURE_COUPLE_ROUE_GMP = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_CONTROLE = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c79_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c79_VSSP_Torque_Control_Gmp1_Sf = 0U;



  vssp_torque_control_gmp1_sf_dwork.is_active_DEMANDE_ANTICIPATION_c = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION_g = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_MEMOIRES_k = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_TAUX_ANTICIPATION_c = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION_n = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_DEMANDEE = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c117_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c117_VSSP_Torque_Control_Gmp1_Sf = 0U;
  vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMin_h = 0U;
  VSCtl_bAntTqWhlPTMinReq =DDS_FALSE;



  vssp_torque_control_gmp1_sf_dwork.is_active_DEMANDE_ANTICIPATION = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_DEMANDE_ANTICIPATION = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_MEMOIRES = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_TAUX_ANTICIPATION = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_TAUX_ANTICIPATION = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_ANTICIPATION_AUTORISEE = 0U;
  vssp_torque_control_gmp1_sf_dwork.is_active_c120_VSSP_Torque_Control_Gmp1_Sf =
    0U;
  vssp_torque_control_gmp1_sf_dwork.is_c120_VSSP_Torque_Control_Gmp1_Sf = 0U;
  vssp_torque_control_gmp1_sf_b.VSCtl_rAnt_tqWhlPTMax_n = 0U;
  VSCtl_bAntTqWhlPTMaxReq =DDS_FALSE;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

