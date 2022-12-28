/*
* File: VSSP_Det_Gearbox_Pedal_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSSP_Det_Gearbox_Pedal_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Wed Nov 30 11:24:32 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Wed Nov 30 11:24:35 2011
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
*        AUT_EC_Function_Stub_v1 SFunction version: 6.0, TLC version: 1.0
*        AUT_EC_m_limit_opt SFunction version: 3.0, TLC version: 12.2
*        AUT_EC_m_min_opt SFunction version: 3.0, TLC version: 3.0
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
* Ref X:\integration_view_00PSASWC_D820D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Det_Gearbox_Pedal_Sf.c
* Version int :/main/L03_01/1 Date: 6/1/2012 11 h 11 m User:esnault 
*    TWK_model:VSSP_Det_Gearbox_Pedal_Sf_L03_010_IMPL1
*    comments :Update requirement
* Version dev :\main\branch_moisan_module_dev\1 Date: 3/1/2012 17 h 41 m User:moisan 
*    TWK_model:VSSP_Det_Gearbox_Pedal_Sf_L03_010_IMPL1
*    comments :Update requirement
* Version dev :\main\branch_demezil_vssp_view\2 Date: 30/11/2011 11 h 49 m User:demezil
*    TWK_model:VSSP_Det_Gearbox_Pedal_Sf_L03_010_IMPL1
*    comments :for VSSp 12.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Negatif_Filtree */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Negatif_Filtree ;CoPt_noTarGearCordIt;VSCtl_bCtlaTqPT;VSCtl_noGearMaxTqNegRaw;VSCtl_stCtl_noGearMax;VSCtl_tiCfmSdwnReqTqNeg;VSCtl_tiCfmSupReqTqNeg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Negatif_Filtree ;VSCtl_bAuthSdwn_noGearMaxTqN;VSCtl_bAuthSup_noGearMxTqNeg;VSCtl_noGearMaxTqNegFil;VSCtl_noGearMaxTqNegFilRaw;VSCtl_tiAuthSdwn_noGearMxTN2;VSCtl_tiAuthSdwn_noGearMxTqN;VSCtl_tiAuthSup_noGearMaxTqN; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Negatif_Filtree */

/* TAG_START_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Positif_Filtree */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Positif_Filtree ;CoPt_noTarGearCordIt;VSCtl_noGearMaxTqPosRaw;VSCtl_stCtl_noGearMax;VSCtl_tiCfmSdwnReqTqPos;VSCtl_tiCfmSupReqTqPos; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Positif_Filtree ;VSCtl_bAuthSdwn_noGearMaxTqP;VSCtl_bAuthSup_noGearMxTqPos;VSCtl_noGearMaxTqPosFil;VSCtl_tiAuthSdwn_noGearMxTqP;VSCtl_tiAuthSup_noGearMaxTqP; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Max_Couple_Roue_Positif_Filtree */

/* TAG_START_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Min_Couple_Roue_Positif_Filtree */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Min_Couple_Roue_Positif_Filtree ;CoPt_noTarGearCordIt;VSCtl_noGearMinTqPosRaw;VSCtl_stCtl_noGearMin;VSCtl_tiCfmSdwnReqTqPos;VSCtl_tiCfmSupReqTqPos; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Min_Couple_Roue_Positif_Filtree ;VSCtl_bAuthSdwn_noGearMin;VSCtl_bAuthSup_noGearMin;VSCtl_noGearMinTqPosFil;VSCtl_tiAuthSdwn_noGearMin;VSCtl_tiAuthSup_noGearMin; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Consigne_Rapport_Min_Couple_Roue_Positif_Filtree */

/* TAG_START_OF_SUB_FUNCTION: F7222_Coordonner_Consignes_Potentiel_Couple_Roue_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F7222_Coordonner_Consignes_Potentiel_Couple_Roue_GMP ;VSCtl_stCtl_noGear;VSCtl_stCtl_tqWhlPotMax;VSCtl_stCtl_tqWhlPotMin;VSCtl_tqWhlPotMaxIntReq;VSCtl_tqWhlPotMinIntReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F7222_Coordonner_Consignes_Potentiel_Couple_Roue_GMP ;VSCtl_tqWhlPotMaxIntNegReq;VSCtl_tqWhlPotMaxIntPosReq;VSCtl_tqWhlPotMinIntNegReq;VSCtl_tqWhlPotMinIntPosReq; */
/* TAG_END_OF_SUB_FUNCTION: F7222_Coordonner_Consignes_Potentiel_Couple_Roue_GMP */

/* TAG_START_OF_SUB_FUNCTION: F7223_Determiner_Plage_Rapport_Pilotable */
/* TAG_INPUT_OF_SUB_FUNCTION: F7223_Determiner_Plage_Rapport_Pilotable ;CoPt_noTarGearCordIt;Ext_stTraTypCf;VSCtl_nFrntWhlFil;VSCtl_stCtl_noGear; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F7223_Determiner_Plage_Rapport_Pilotable ;VSCtl_noGearMax;VSCtl_noGearTqNegMin;VSCtl_noGearTqPosMin; */
/* TAG_END_OF_SUB_FUNCTION: F7223_Determiner_Plage_Rapport_Pilotable */

/* TAG_START_OF_SUB_FUNCTION: F7224_Determiner_Seuils_Changement_Rapport */
/* TAG_INPUT_OF_SUB_FUNCTION: F7224_Determiner_Seuils_Changement_Rapport ;CoPt_noTarGearCordIt;VSCtl_nFrntWhlFil;VSCtl_stCtl_noGear; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F7224_Determiner_Seuils_Changement_Rapport ;VSCtl_tqWhlMaxGear2Thd;VSCtl_tqWhlMaxGear3Thd;VSCtl_tqWhlMaxGear4Thd;VSCtl_tqWhlMaxGear5Thd;VSCtl_tqWhlMaxGear6Thd;VSCtl_tqWhlMaxGear7Thd;VSCtl_tqWhlMaxGear8Thd;VSCtl_tqWhlMinGear2Thd;VSCtl_tqWhlMinGear3Thd;VSCtl_tqWhlMinGear4Thd;VSCtl_tqWhlMinGear5Thd;VSCtl_tqWhlMinGear6Thd;VSCtl_tqWhlMinGear7Thd;VSCtl_tqWhlMinGear8Thd; */
/* TAG_END_OF_SUB_FUNCTION: F7224_Determiner_Seuils_Changement_Rapport */

/* TAG_START_OF_SUB_FUNCTION: F7225_Determiner_Temps_Confirmation_Changement_Rapport */
/* TAG_INPUT_OF_SUB_FUNCTION: F7225_Determiner_Temps_Confirmation_Changement_Rapport ;VSCtl_dtqWhlPTPotReq;VSCtl_nEngFil;VSCtl_stCtl_noGear;VSCtl_tiCfmSdwnIntReq;VSCtl_tiCfmSupIntReq;VSCtl_tqWhlPTPotReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F7225_Determiner_Temps_Confirmation_Changement_Rapport ;VSCtl_tiCfmSdwnReqTqNeg;VSCtl_tiCfmSdwnReqTqPos;VSCtl_tiCfmSupReqTqNeg;VSCtl_tiCfmSupReqTqPos; */
/* TAG_END_OF_SUB_FUNCTION: F7225_Determiner_Temps_Confirmation_Changement_Rapport */

/* TAG_START_OF_SUB_FUNCTION: F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute */
/* TAG_INPUT_OF_SUB_FUNCTION: F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute ;VSCtl_noGearMax;VSCtl_noGearTqPosMin;VSCtl_stCtl_aVehVSMax;VSCtl_stCtl_noGearMax;VSCtl_tqWhlMaxGear2Thd;VSCtl_tqWhlMaxGear3Thd;VSCtl_tqWhlMaxGear4Thd;VSCtl_tqWhlMaxGear5Thd;VSCtl_tqWhlMaxGear6Thd;VSCtl_tqWhlMaxGear7Thd;VSCtl_tqWhlMaxGear8Thd;VSCtl_tqWhlPotMaxIntPosReq;VSCtl_tqWhlPotMinIntPosReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute ;VSCtl_noGearMaxTqPosRaw;VSCtl_tqWhlPotCoordPosReq; */
/* TAG_END_OF_SUB_FUNCTION: F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute */

/* TAG_START_OF_SUB_FUNCTION: F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute */
/* TAG_INPUT_OF_SUB_FUNCTION: F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute ;VSCtl_noGearMax;VSCtl_noGearTqNegMin;VSCtl_stCtl_noGearMax;VSCtl_tqWhlMinGear2Thd;VSCtl_tqWhlMinGear3Thd;VSCtl_tqWhlMinGear4Thd;VSCtl_tqWhlMinGear5Thd;VSCtl_tqWhlMinGear6Thd;VSCtl_tqWhlMinGear7Thd;VSCtl_tqWhlMinGear8Thd;VSCtl_tqWhlPotMaxIntNegReq;VSCtl_tqWhlPotMinIntNegReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute ;VSCtl_noGearMaxTqNegRaw; */
/* TAG_END_OF_SUB_FUNCTION: F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute */

/* TAG_START_OF_SUB_FUNCTION: F72264_Determiner_Consigne_Rapport_Max */
/* TAG_INPUT_OF_SUB_FUNCTION: F72264_Determiner_Consigne_Rapport_Max ;VSCtl_noGearMax;VSCtl_noGearMaxTqNegFil;VSCtl_noGearMaxTqPosFil;VSCtl_noGearTqNegMin;VSCtl_noGearTqPosMin;VSCtl_stCtl_noGearMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72264_Determiner_Consigne_Rapport_Max ;VSCtl_noGearReqMax; */
/* TAG_END_OF_SUB_FUNCTION: F72264_Determiner_Consigne_Rapport_Max */

/* TAG_START_OF_SUB_FUNCTION: F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute */
/* TAG_INPUT_OF_SUB_FUNCTION: F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute ;VSCtl_noGearMax;VSCtl_noGearTqPosMin;VSCtl_stCtl_noGearMin;VSCtl_tqWhlMaxGear2Thd;VSCtl_tqWhlMaxGear3Thd;VSCtl_tqWhlMaxGear4Thd;VSCtl_tqWhlMaxGear5Thd;VSCtl_tqWhlMaxGear6Thd;VSCtl_tqWhlMaxGear7Thd;VSCtl_tqWhlMaxGear8Thd;VSCtl_tqWhlPotMaxIntPosReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute ;VSCtl_noGearMinTqPosRaw; */
/* TAG_END_OF_SUB_FUNCTION: F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute */

/* TAG_START_OF_SUB_FUNCTION: F72273_Coordonner_Consigne_Rapport_Min */
/* TAG_INPUT_OF_SUB_FUNCTION: F72273_Coordonner_Consigne_Rapport_Min ;VSCtl_noGearMax;VSCtl_noGearMinTqPosFil;VSCtl_noGearReqMax;VSCtl_noGearTqPosMin;VSCtl_stCtl_noGearMax;VSCtl_stCtl_noGearMin; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72273_Coordonner_Consigne_Rapport_Min ;VSCtl_noGearReqMin; */
/* TAG_END_OF_SUB_FUNCTION: F72273_Coordonner_Consigne_Rapport_Min */

/* TAG_START_OF_SUB_FUNCTION: F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_RVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_RVV ;AccP_rAccP;VSCtl_bAcvFil_rAccPMaxVSReg;VSCtl_spdVeh;VSCtl_spdVehErrVSReg;VSCtl_stCtl_rAccPVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_RVV ;VSCtl_rAccPTraMaxVSReg;VSCtl_rAccPTraMinVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_RVV */

/* TAG_START_OF_SUB_FUNCTION: F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_ACC */
/* TAG_INPUT_OF_SUB_FUNCTION: F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_ACC ;VSCtl_aVehDVSRegReq;VSCtl_bAcvFil_rAccPMaxDVSReg;VSCtl_spdVeh;VSCtl_stCtl_rAccPDVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_ACC ;VSCtl_rAccPTraMaxDVSReg;VSCtl_rAccPTraMinDVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_ACC */

/* TAG_START_OF_SUB_FUNCTION: F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_LVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_LVV ;AccP_rAccP;VSCtl_bAcvFil_rAccPMaxVSLim;VSCtl_spdVeh;VSCtl_spdVehErrVSLim;VSCtl_stCtl_rAccPVSLim; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_LVV ;VSCtl_rAccPTraMaxVSLim;VSCtl_rAccPTraMinVSLim; */
/* TAG_END_OF_SUB_FUNCTION: F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_LVV */

/* TAG_START_OF_SUB_FUNCTION: F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV ;AccP_rAccP;VSCtl_bAcvFil_rAccPMaxVSMax;VSCtl_spdVeh;VSCtl_spdVehErrVSMax;VSCtl_stCtl_rAccPVSMax; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV ;VSCtl_rAccPTraMaxVSMax;VSCtl_rAccPTraMinVSMax; */
/* TAG_END_OF_SUB_FUNCTION: F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV */

/* TAG_START_OF_SUB_FUNCTION: F7236_Determiner_Position_Pedales_Tramsmission_XVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F7236_Determiner_Position_Pedales_Tramsmission_XVV ;VSCtl_rAccPTraMaxDVSReg;VSCtl_rAccPTraMaxVSLim;VSCtl_rAccPTraMaxVSMax;VSCtl_rAccPTraMaxVSReg;VSCtl_rAccPTraMinDVSReg;VSCtl_rAccPTraMinVSLim;VSCtl_rAccPTraMinVSMax;VSCtl_rAccPTraMinVSReg;VSCtl_stCtl_rAccPTra; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F7236_Determiner_Position_Pedales_Tramsmission_XVV ;VSCtl_rAccPTraMax;VSCtl_rAccPTraMin; */
/* TAG_END_OF_SUB_FUNCTION: F7236_Determiner_Position_Pedales_Tramsmission_XVV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission ;Ext_stCtlCmdPTTqPotCf;VSCtl_bCtlCmdPTTqCf_SC; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission ;VSCtl_bAcvFil_rAccPTra;VSCtl_stCtl_rAccPTra; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_ACC */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_ACC ;VSCtl_stCtl_aVehDVSReg;VSCtl_stCtl_rAccPTra; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_ACC ;VSCtl_bAcvFil_rAccPMaxDVSReg;VSCtl_stCtl_rAccPDVSReg;VSCtl_stCtl_rAccPDVSRegPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_ACC */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_BVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_BVV ;VSCtl_stCtl_aVehVSMax;VSCtl_stCtl_rAccPTra; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_BVV ;VSCtl_bAcvFil_rAccPMaxVSMax;VSCtl_stCtl_rAccPVSMax;VSCtl_stCtl_rAccPVSMaxPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_BVV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_LVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_LVV ;VSCtl_stCtl_aVehVSLim;VSCtl_stCtl_rAccPTra; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_LVV ;VSCtl_bAcvFil_rAccPMaxVSLim;VSCtl_stCtl_rAccPVSLim;VSCtl_stCtl_rAccPVSLimPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_LVV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_RVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_RVV ;VSCtl_rAccPEngMin;VSCtl_rAccPTraMaxVSReg;VSCtl_stCtl_aVehVSReg;VSCtl_stCtl_rAccPTra; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_RVV ;VSCtl_bAcvFil_rAccPMaxVSReg;VSCtl_stCtl_rAccPVSReg;VSCtl_stCtl_rAccPVSRegPrev; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Position_Pedale_Accelerateur_Transmission_RVV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Controle_Rapport */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Controle_Rapport ;Ext_stCtlCmdPTTqPotCf;FRM_bDeacVSCtlGearCtl;Tra_stGearCtl;VSCtl_stCtl_tqWhlPotMax;VSCtl_stCtl_tqWhlPotMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Controle_Rapport ;VSCtl_stCtl_noGear;VSCtl_tiFilStCtlnoGear; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Controle_Rapport */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Max ;VSCtl_stCtl_noGear;VSCtl_stCtl_tqWhlPotMax;VSCtl_stCtl_tqWhlPotMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Max ;VSCtl_stCtl_noGearMax; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Min ;VSCtl_stCtl_noGear;VSCtl_stCtl_tqWhlPotMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Min ;VSCtl_stCtl_noGearMin; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Rapport_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Controle_Rapport */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Rapport ;VSCtl_noGearReqMax;VSCtl_noGearReqMin;VSCtl_stCtl_noGearMax;VSCtl_stCtl_noGearMin; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Controle_Rapport ;VSCtl_stGearCtlReq; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Controle_Rapport */

/* TAG_START_OF_STATEFLOW_FUNCTION: VSSP_enable_F722 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: VSSP_enable_F722 ;Ext_stCtlCmdPTTqPotCf; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: VSSP_enable_F722 ;vsctl_bacvf722; */
/* TAG_END_OF_STATEFLOW_FUNCTION: VSSP_enable_F722 */

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
#define VSCTL_STCTL_RACCPVSREGPREV_CONTROLE             (1)
#define VSCTL_STCTL_RACCPVSREGPREV_ARRET                (0)
#define VSCTL_STCTL_AVEHDVSREG_CONTROLE                 (1)
#define VSCTL_STCTL_AVEHVSLIM_CONTROLE                  (1)
#define VSCTL_STCTL_AVEHVSMAX_CONTROLE                  (1)
#define VSCTL_NOGEARREQMIN_RAPPORT_DE_REPLI_BAS         (0)
#define VSCTL_NOGEARMINTQPOSFIL_RAPPORT_DE_REPLI_BAS    (0)
#define VSCTL_NOGEARREQMAX_RAPPORT_DE_REPLI_HAUT        (15)
#define VSCTL_NOGEARMAXTQNEGFIL_RAPPORT_DE_REPLI_HAUT   (15)
#define VSCTL_NOGEARMAXTQNEGFILRAW_RAPPORT_DE_REPLI_HAUT    (15)
#define VSCTL_NOGEARMAXTQPOSFIL_RAPPORT_DE_REPLI_HAUT   (15)

/* VSCtl_stCtl_tqWhlPotMin */
#define VSCTL_STCTL_TQWHLPOTMIN_ARRET                   (0)
#define VSCTL_STCTL_TQWHLPOTMIN_CONTROLE                (1)

/* VSCtl_stCtl_tqWhlPotMax */
#define VSCTL_STCTL_TQWHLPOTMAX_ARRET                   (0)
#define VSCTL_STCTL_TQWHLPOTMAX_CONTROLE                (1)

/* Ext_stCtlCmdPTTqPotCf */
#define EXT_STCTLCMDPTTQPOTCF_RAPPORT                   (3)

/* VSCtl_stCtl_rAccPTra */
#define VSCTL_STCTL_RACCPTRA_ACTIF                      (1)
#define VSCTL_STCTL_RACCPTRA_ARRET                      (0)

/* VSCtl_stCtl_rAccPVSReg */
#define VSCTL_STCTL_RACCPVSREG_ARRET                    (0)
#define VSCTL_STCTL_RACCPVSREG_CONTROLE                 (1)
#define VSCTL_STCTL_RACCPVSREG_TRANSITION               (2)

/* VSCtl_stCtl_aVehVSReg */
#define VSCTL_STCTL_AVEHVSREG_CONTROLE                  (1)

/* VSCtl_stCtl_rAccPDVSReg */
#define VSCTL_STCTL_RACCPDVSREG_CONTROLE                (1)
#define VSCTL_STCTL_RACCPDVSREG_ARRET                   (0)

/* VSCtl_stCtl_rAccPDVSRegPrev */
#define VSCTL_STCTL_RACCPDVSREGPREV_CONTROLE            (1)
#define VSCTL_STCTL_RACCPDVSREGPREV_ARRET               (0)

/* VSCtl_stCtl_rAccPVSLim */
#define VSCTL_STCTL_RACCPVSLIM_CONTROLE                 (1)
#define VSCTL_STCTL_RACCPVSLIM_ARRET                    (0)

/* VSCtl_stCtl_rAccPVSLimPrev */
#define VSCTL_STCTL_RACCPVSLIMPREV_CONTROLE             (1)
#define VSCTL_STCTL_RACCPVSLIMPREV_ARRET                (0)

/* VSCtl_stCtl_rAccPVSMax */
#define VSCTL_STCTL_RACCPVSMAX_CONTROLE                 (1)
#define VSCTL_STCTL_RACCPVSMAX_ARRET                    (0)

/* VSCtl_stCtl_rAccPVSMaxPrev */
#define VSCTL_STCTL_RACCPVSMAXPREV_CONTROLE             (1)
#define VSCTL_STCTL_RACCPVSMAXPREV_ARRET                (0)

/* VSCtl_stCtl_noGear */
#define VSCTL_STCTL_NOGEAR_ARRET                        (0)
#define VSCTL_STCTL_NOGEAR_CONTROLE_38                  (1)
#define VSCTL_STCTL_NOGEAR_DEFAUT_38                    (2)

/* Tra_stGearCtl */
#define TRA_STGEARCTL_INHIBE                            (2)
#define TRA_STGEARCTL_ATTENTE                           (3)
#define TRA_STGEARCTL_AE                                (4)
#define TRA_STGEARCTL_ANE                               (5)
#define TRA_STGEARCTL_DEFAUT                            (6)

/* VSCtl_stCtl_noGearMax */
#define VSCTL_STCTL_NOGEARMAX_MARCHE                    (1)
#define VSCTL_STCTL_NOGEARMAX_ARRET                     (0)

/* VSCtl_stCtl_noGearMin */
#define VSCTL_STCTL_NOGEARMIN_MARCHE                    (1)
#define VSCTL_STCTL_NOGEARMIN_ARRET                     (0)

/*VSCtl_stGearCtlReq */
#define VSCTL_STGEARCTLREQ_NON_DEMANDE                  (0)
#define VSCTL_STGEARCTLREQ_DEMANDE                      (1)
#define VSCTL_STGEARCTLREQ_FULL_PASS                    (2)
#define VSCTL_STGEARCTLREQ_RESERVE                      (3)

/************************************************************************/

/* Named constants for block: /VSSP_enable_F722' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ACTIVE (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_VSSP_ENABLE_F722 (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_k (2)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_i3 (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_a (1U)

/* Named constants for block: /Mode_Calcul_Position_Pedale_Accelerateur_Transmission' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_l (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ACTIF (1)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_jm (1U)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_m (0U)

/* Named constants for block: /Mode_Calcul_Position_Pedale_Accelerateur_Transmission_RVV' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_o (0)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_RVV (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_f (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_c (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE____0 (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_TRANSITION (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF (1)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_ik (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_b (1U)

/* Named constants for block: /Mode_Calcul_Position_Pedale_Accelerateur_Transmission_ACC' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_ACC (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_c (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_a (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_b (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_f (1)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_i4 (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_nd (1U)

/* Named constants for block: /Mode_Calcul_Position_Pedale_Accelerateur_Transmission_LVV' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_LVV (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_a (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_m (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_bv (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_h (1)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_a (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_mg (1U)

/* Named constants for block: /Mode_Calcul_Position_Pedale_Accelerateur_Transmission_BVV' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_BVV (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_e (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_h (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_n (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_c (1)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_g (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_nj (1U)

/* Named constants for block: /Mode_Commande_Controle_Rapport' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_COMMANDE_RAPPORT (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT_NON_CONFIRME (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT_CONFIRME (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT (3)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI (1U)

/* Named constants for block: /Mode_Commande_Rapport_Max' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_b (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_COMMANDE_RAPPORT_MAX (1)

/* Named constants for block: /Consigne_Rapport_Max_Couple_Roue_Positif_Filtree' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_b (0)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONSIGNE_RAPPORT_MAX_COUPLE_ROUE_POSIITF_FILTREE (1)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_c (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_m (1U)

/* Named constants for block: /Consigne_Rapport_Max_Couple_Roue_Negatif_Filtree' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g (0)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_i (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_h (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MAINTENIR_RAPPORT (3)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION_k (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME_e (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION_a (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_f (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_b (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_j (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_g (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_c (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_b (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME_b (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_i (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONSIGNE_RAPPORT_MAX_COUPLE_ROUE_NEGATIF_FILTREE (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_AUTORISER_UP (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_TEMPORISER_DOWN (4)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE_h (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_ARRET (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_AUTORISER_DOWN (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_GEL (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_CHANGEMENT (1)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_e (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_j (1U)

/* Named constants for block: /Mode_Commande_Rapport_Min' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_COMMANDE_RAPPORT_MIN (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_m (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE_m (2)

/* Named constants for block: /Consigne_Rapport_Min_Couple_Roue_Positif_Filtree' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_a (0)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_m (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_e (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE_p (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION_e (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME_h (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION_i (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_b (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_j (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_g (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_h (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_k (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_g (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME_a (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_k (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_CONSIGNE_RAPPORT_MIN_COUPLE_ROUE_POSIITF_FILTREE (1)
#define VSSP_Det_Gearbox_Pedal_Sf_FAUX_i (0U)
#define VSSP_Det_Gearbox_Pedal_Sf_VRAI_n (1U)

/* Named constants for block: /Mode_Controle_Rapport' */
#define VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_e (0)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CONTROLE_RAPPORT (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_i (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_DEMANDE (1)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_FULL_PASS (2)
#define VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE_e (2)

/* Definition for custom storage class: Define */
#define VSCTL_TIAUTHSDWN_NOGEARMIN_MAX 1600U
#define VSCTL_TIAUTHSDWN_NOGEARMXTN2_MAX 1600U
#define VSCTL_TIAUTHSDWN_NOGEARMXTQN_MAX 1600U
#define VSCTL_TIAUTHSDWN_NOGEARMXTQP_MAX 1600U
#define VSCTL_TIAUTHSUP_NOGEARMAXTQN_MAX 1600U
#define VSCTL_TIAUTHSUP_NOGEARMAXTQP_MAX 1600U
#define VSCTL_TIAUTHSUP_NOGEARMIN_MAX  1600U
#define VSSP_DET_GEARBOX_PEDAL_S_CONST_0 12800U
#define VSSP_F722622_INC               1U
#define VSSP_F722632_INC               1U
#define VSSP_F722722_INC               1U

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupReqTqPos;       /*DEC2*/
extern VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupReqTqNeg;       /*DEC2*/
extern VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnReqTqPos;       /*DEC2*/
extern VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnReqTqNeg;       /*DEC2*/
extern VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxVSReg;       /*BIN7*/
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearMinTqPosRaw;
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqPosRaw;
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqNegRaw;
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSLim;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPTra;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPDVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_noGearMin;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_noGearMax;
VAR(UInt8, AUTOMATIC) VSCtl_noGearMinTqPosFil;
VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqPosFil;
VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqNegFil;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPTra;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxVSMax;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxVSLim;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxDVSReg;
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt16 VSCtl_tiAuthSdwn_noGearMin_k;
  UInt16 VSCtl_tiAuthSup_noGearMin_e;
  UInt16 VSCtl_tiAuthSdwn_noGearMxTqN_n;
  UInt16 VSCtl_tiAuthSup_noGearMaxTqN_j;
  UInt16 VSCtl_tiAuthSdwn_noGearMxTN2_b;
  UInt16 VSCtl_tiAuthSdwn_noGearMxTqP_a;
  UInt16 VSCtl_tiAuthSup_noGearMaxTqP_d;
} BlockIO_VSSP_Det_Gearbox_Pedal_Sf;


typedef struct {
  UInt32 is_FILTRAGE_RAPPORT_MARCHE : 3;
  UInt32 is_VSSP_ENABLE_F722 : 2;
  UInt32 is_ETAT_POSITION_PEDALE_MAX_BVV : 2;
  UInt32 is_FILTRAGE_POSITION_PEDALE_BVV : 2;
  UInt32 is_ETAT_POSITION_PEDALE_MAX_LVV : 2;
  UInt32 is_FILTRAGE_POSITION_PEDALE_LVV : 2;
  UInt32 is_ETAT_POSITION_PEDALE_ACC : 2;
  UInt32 is_FILTRAGE_POSITION_PEDALE_ACC : 2;
  UInt32 is_ETAT_POSITION_PEDALE_RVV : 2;
  UInt32 is_CONTROLE : 2;
  UInt32 is_FILTRAGE_POSITION_PEDALE_RVV : 2;
  UInt32 is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION : 2;
  UInt32 is_MODE_CONTROLE_RAPPORT : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_MARCHE : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT : 2;
  UInt32 is_FILTRAGE_RAPPORT : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME : 2;
  UInt32 is_MODE_COMMANDE_RAPPORT_MIN : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_l : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_n : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_b : 2;
  UInt32 is_FILTRAGE_RAPPORT2 : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_MARCHE_l : 2;
  UInt32 is_FILTRAGE_RAPPORT1 : 2;
  UInt32 is_FILTRAGE_RAPPORT_MARCHE_g : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_MARCHE_n : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_m : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_e : 2;
  UInt32 is_FILTRAGE_RAPPORT_DESCENDANT_f : 2;
  UInt32 is_FILTRAGE_RAPPORT_a : 2;
  UInt32 is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p : 2;
  UInt32 is_MODE_COMMANDE_RAPPORT_MAX : 2;
  UInt32 is_MODE_COMMANDE_RAPPORT : 2;
  UInt32 is_DEFAUT : 2;
  UInt32 is_active_c1_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c1_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_c17_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c17_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_ETAT_POSITION_PEDALE_MAX_BVV : 1;
  UInt32 is_active_FILTRAGE_POSITION_PEDALE_BVV : 1;
  UInt32 is_active_MEMOIRES : 1;
  UInt32 is_active_c16_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c16_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_ETAT_POSITION_PEDALE_MAX_LVV : 1;
  UInt32 is_active_FILTRAGE_POSITION_PEDALE_LVV : 1;
  UInt32 is_active_MEMOIRES_l : 1;
  UInt32 is_active_c15_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c15_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_ETAT_POSITION_PEDALE_ACC : 1;
  UInt32 is_active_FILTRAGE_POSITION_PEDALE_ACC : 1;
  UInt32 is_active_MEMOIRES_k : 1;
  UInt32 is_active_c14_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c14_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_ETAT_POSITION_PEDALE_RVV : 1;
  UInt32 is_active_FILTRAGE_POSITION_PEDALE_RVV : 1;
  UInt32 is_active_MEMOIRES_m : 1;
  UInt32 is_active_c13_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c13_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_c365_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c365_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_c364_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c364_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_FILTRAGE_RAPPORT_MONTANT : 1;
  UInt32 is_active_FILTRAGE_RAPPORT_DESCENDANT : 1;
  UInt32 is_active_FILTRAGE_RAPPORT : 1;
  UInt32 is_active_c363_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c363_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_c362_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c362_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_FILTRAGE_RAPPORT_MONTANT_e : 1;
  UInt32 is_active_FILTRAGE_RAPPORT_DESCENDANT_l : 1;
  UInt32 is_active_FILTRAGE_RAPPORT2 : 1;
  UInt32 is_active_FILTRAGE_RAPPORT1 : 1;
  UInt32 is_active_c361_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c361_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_FILTRAGE_RAPPORT_MONTANT_f : 1;
  UInt32 is_active_FILTRAGE_RAPPORT_DESCENDANT_i : 1;
  UInt32 is_active_FILTRAGE_RAPPORT_o : 1;
  UInt32 is_active_c360_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c360_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_active_c359_VSSP_Det_Gearbox_Pedal_Sf : 1;
  UInt32 is_c359_VSSP_Det_Gearbox_Pedal_Sf : 1;
} D_Work_VSSP_Det_Gearbox_Pedal_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiAuthSdwn_noGearMin;             /*DEC2*/
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiAuthSdwn_noGearMxTN2;           /*DEC2*/
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiAuthSdwn_noGearMxTqN;           /*DEC2*/
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiAuthSdwn_noGearMxTqP;           /*DEC2*/
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiAuthSup_noGearMaxTqN;           /*DEC2*/
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiAuthSup_noGearMaxTqP;           /*DEC2*/
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiAuthSup_noGearMin;              /*DEC2*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFilStCtlnoGear;                 /*DEC0*/
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAuthSdwn_noGearMaxTqN;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAuthSdwn_noGearMaxTqP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAuthSdwn_noGearMin;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAuthSup_noGearMin;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAuthSup_noGearMxTqNeg;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAuthSup_noGearMxTqPos;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqNegFilRaw;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPDVSRegPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSLimPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSMaxPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSRegPrev;
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
STATIC VAR(UInt16, AUTOMATIC) vssp_det_gearbox_pedal_s_delay_0;
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_raccptramax_cpy;                             /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vssp_vsctl_raccptramin_cpy;                             /*BIN7*/
#define VSSP_STOP_SEC_VAR_16BIT
#include "VSSp_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(BlockIO_VSSP_Det_Gearbox_Pedal_Sf, AUTOMATIC) vssp_det_gearbox_pedal_sf_b;
STATIC VAR(D_Work_VSSP_Det_Gearbox_Pedal_Sf, AUTOMATIC) vssp_det_gearbox_pedal_sf_dwork;
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"


/* 8BIT-bits variable definition */
#define VSSP_START_SEC_VAR_8BIT
#include "VSSp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bacvf722;
/* Static Not Visible area end */
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_nogearreqmax_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_nogearreqmin_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_stctl_nogear_cpy;
STATIC VAR(UInt8, AUTOMATIC) vssp_vsctl_stgearctlreq_cpy;
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnTqNeg_C = (CONST(UInt16, AUTOMATIC))(0U);        /*DEC2*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_stCtlnoGear_C = (CONST(UInt16, AUTOMATIC))(20U);    /*DEC0*/
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

FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Pedal_Sf(UInt8 FRM_bDeacVSCtlGearCtl_swc_in,
                               SInt16 VSCtl_aVehDVSRegReq_swc_in,                          /*BIN10*/
                               UInt8 VSCtl_stCtl_aVehVSLim_swc_in,
                               UInt8 VSCtl_stCtl_aVehDVSReg_swc_in,
                               UInt8 Ext_stTraTypCf_swc_in,
                               SInt16 VSCtl_spdVehErrVSReg_swc_in,                         /*BIN7*/
                               UInt8 VSCtl_stCtl_aVehVSMax_swc_in,
                               SInt16 VSCtl_spdVehErrVSLim_swc_in,                         /*BIN7*/
                               SInt16 VSCtl_spdVehErrVSMax_swc_in,                         /*BIN7*/
                               UInt32 VSCtl_nEngFil_swc_in,                                /*BIN0*/
                               UInt8 Tra_stGearCtl_swc_in,
                               UInt16 VSCtl_rAccPEngMin_swc_in,                     /*BIN7*/
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt32 VSCtl_nFrntWhlFil_swc_in,                            /*BIN7*/
                               UInt8 VSCtl_bCtlaTqPT_swc_in,
                               SInt16 VSCtl_tqWhlPTPotReq_swc_in,                          /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in,
                               UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                               SInt8 CoPt_noTarGearCordIt_swc_in,                          /*BIN0*/
                               UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
                               UInt16 AccP_rAccP_swc_in,                                   /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_noGear_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGearCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMax_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMin_swc_out)                            /*BIN7*/
{
  UInt16 stack_data_u16_0;


  /* TAG_START_OF_MAIN_FUNCTION */

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.73.2 */
  /* TAG_START_OF_STATEFLOW_FUNCTION: VSSP_enable_F722*/

  if (vssp_det_gearbox_pedal_sf_dwork.is_active_c1_VSSP_Det_Gearbox_Pedal_Sf ==
      0)
  {
    vssp_det_gearbox_pedal_sf_dwork.is_active_c1_VSSP_Det_Gearbox_Pedal_Sf = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_c1_VSSP_Det_Gearbox_Pedal_Sf = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_VSSP_ENABLE_F722;
    vssp_det_gearbox_pedal_sf_dwork.is_VSSP_ENABLE_F722 = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_k;
    vsctl_bacvf722 = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i3;

  }
  else
  {
    switch (vssp_det_gearbox_pedal_sf_dwork.is_VSSP_ENABLE_F722) {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_ACTIVE:
      if (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
      {
        vssp_det_gearbox_pedal_sf_dwork.is_VSSP_ENABLE_F722 = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_k;
        vsctl_bacvf722 = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i3;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_k:
      if (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
      {
        vssp_det_gearbox_pedal_sf_dwork.is_VSSP_ENABLE_F722 = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ACTIVE;
        vsctl_bacvf722 = VSSP_Det_Gearbox_Pedal_Sf_VRAI_a;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_VSSP_ENABLE_F722 = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_k;
      vsctl_bacvf722 = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i3;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: VSSP_enable_F722*/


  if (DDS_TRUE==vsctl_bacvf722)
  {

    /* TAG_START_OF_STATEFLOW_FUNCTION: F7221_Determiner_Mode_Commande_Rapport*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.74.0 */

    if (vssp_det_gearbox_pedal_sf_dwork.is_active_c359_VSSP_Det_Gearbox_Pedal_Sf
        == 0)
    {
      vssp_det_gearbox_pedal_sf_dwork.is_active_c359_VSSP_Det_Gearbox_Pedal_Sf =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_c359_VSSP_Det_Gearbox_Pedal_Sf =
        (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_COMMANDE_RAPPORT;
      vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET;
      vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_ARRET;
      VSCtl_tiFilStCtlnoGear = VSCtl_tiFil_stCtlnoGear_C;

    }
    else
    {
      switch (vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT)
  {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET:
        if ((((Tra_stGearCtl_swc_in == TRA_STGEARCTL_ATTENTE) &&
              ((VSCtl_stCtl_tqWhlPotMax_swc_in == VSCTL_STCTL_TQWHLPOTMAX_CONTROLE)
              ||
               (VSCtl_stCtl_tqWhlPotMin_swc_in == VSCTL_STCTL_TQWHLPOTMIN_CONTROLE)))
               &&
             (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT))
             &&
            (FRM_bDeacVSCtlGearCtl_swc_in == VSSP_Det_Gearbox_Pedal_Sf_FAUX))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE;
          vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_CONTROLE_38;
          VSCtl_tiFilStCtlnoGear = VSCtl_tiFil_stCtlnoGear_C;

        }
        else if ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)
        &&
                   (FRM_bDeacVSCtlGearCtl_swc_in == VSSP_Det_Gearbox_Pedal_Sf_VRAI))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT;
          vssp_det_gearbox_pedal_sf_dwork.is_DEFAUT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT_CONFIRME;
          vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_DEFAUT_38;

        }
        else if ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)
        &&
                   (((Tra_stGearCtl_swc_in == TRA_STGEARCTL_AE)
                   || (Tra_stGearCtl_swc_in ==
                      TRA_STGEARCTL_ANE)) || (Tra_stGearCtl_swc_in ==
                     TRA_STGEARCTL_DEFAUT)))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT;
          vssp_det_gearbox_pedal_sf_dwork.is_DEFAUT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT_NON_CONFIRME;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE:
        if ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)
        &&
            ((Tra_stGearCtl_swc_in == TRA_STGEARCTL_DEFAUT)
            || (FRM_bDeacVSCtlGearCtl_swc_in ==
              VSSP_Det_Gearbox_Pedal_Sf_VRAI)))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT;
          vssp_det_gearbox_pedal_sf_dwork.is_DEFAUT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT_CONFIRME;
          vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_DEFAUT_38;

        }
        else if ((((VSCtl_stCtl_tqWhlPotMax_swc_in == VSCTL_STCTL_TQWHLPOTMAX_ARRET)
        &&
                     (VSCtl_stCtl_tqWhlPotMin_swc_in == VSCTL_STCTL_TQWHLPOTMIN_ARRET))

                    || (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_RAPPORT))
                   || (Tra_stGearCtl_swc_in == TRA_STGEARCTL_INHIBE))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET;
          vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_ARRET;
          VSCtl_tiFilStCtlnoGear = VSCtl_tiFil_stCtlnoGear_C;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT:
        if ((Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_RAPPORT)
        ||
            ((Tra_stGearCtl_swc_in == TRA_STGEARCTL_ATTENTE)
            && (FRM_bDeacVSCtlGearCtl_swc_in
              != VSSP_Det_Gearbox_Pedal_Sf_VRAI)))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_DEFAUT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD;
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET;
          vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_ARRET;
          VSCtl_tiFilStCtlnoGear = VSCtl_tiFil_stCtlnoGear_C;

        }
        else
        {
          switch (vssp_det_gearbox_pedal_sf_dwork.is_DEFAUT)
        {
           case VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT_NON_CONFIRME:
            if (VSCtl_tiFilStCtlnoGear == 0)
            {
              vssp_det_gearbox_pedal_sf_dwork.is_DEFAUT = (UInt8)
                VSSP_Det_Gearbox_Pedal_Sf_IN_DEFAUT_CONFIRME;
              vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_DEFAUT_38;

            }
            else
            {
              VSCtl_tiFilStCtlnoGear = (UInt16)(VSCtl_tiFilStCtlnoGear - 1);
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET;
        vssp_vsctl_stctl_nogear_cpy = VSCTL_STCTL_NOGEAR_ARRET;
        VSCtl_tiFilStCtlnoGear = VSCtl_tiFil_stCtlnoGear_C;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F7221_Determiner_Mode_Commande_Rapport*/

  VSSP_F7222_Coordonner_Consignes_Potentiel_Couple_Roue_Gmp(vssp_vsctl_stctl_nogear_cpy,
                                                            VSCtl_stCtl_tqWhlPotMax_swc_in,
                                                            VSCtl_stCtl_tqWhlPotMin_swc_in);

  VSSP_F7223_Determiner_Plage_Rapport_Pilotable(CoPt_noTarGearCordIt_swc_in,
                                                VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                                                vssp_vsctl_stctl_nogear_cpy,
                                                Ext_stTraTypCf_swc_in);

  VSSP_F7224_Determiner_Seuils_Changement_Rapport(CoPt_noTarGearCordIt_swc_in,
                                                    VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                                                    vssp_vsctl_stctl_nogear_cpy);

  VSSP_F7225_Determiner_Temps_Confirmation_Changement_Rapport(VSCtl_nEngFil_swc_in, /* BIN0 */
                                                                vssp_vsctl_stctl_nogear_cpy,
                                                                VSCtl_tqWhlPTPotReq_swc_in /* BIN1 */);

    /* TAG_START_OF_STATEFLOW_FUNCTION: F72261_Determiner_Mode_Commande_Rapport_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.94.0 */

    if (vssp_det_gearbox_pedal_sf_dwork.is_active_c360_VSSP_Det_Gearbox_Pedal_Sf
        == 0)
    {
      vssp_det_gearbox_pedal_sf_dwork.is_active_c360_VSSP_Det_Gearbox_Pedal_Sf =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_c360_VSSP_Det_Gearbox_Pedal_Sf =
        (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_COMMANDE_RAPPORT_MAX;
      vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MAX = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_b;
      VSCtl_stCtl_noGearMax = VSCTL_STCTL_NOGEARMAX_ARRET;

    }
    else
    {
      switch (vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MAX)
        {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_b:
        if ((vssp_vsctl_stctl_nogear_cpy == VSCTL_STCTL_NOGEAR_CONTROLE_38) &&
            ((VSCtl_stCtl_tqWhlPotMax_swc_in != VSCTL_STCTL_TQWHLPOTMAX_ARRET)
            ||
             (VSCtl_stCtl_tqWhlPotMin_swc_in != VSCTL_STCTL_TQWHLPOTMIN_ARRET)))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MAX =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE;
          VSCtl_stCtl_noGearMax = VSCTL_STCTL_NOGEARMAX_MARCHE;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE:
        if ((vssp_vsctl_stctl_nogear_cpy != VSCTL_STCTL_NOGEAR_CONTROLE_38) ||
            ((VSCtl_stCtl_tqWhlPotMax_swc_in == VSCTL_STCTL_TQWHLPOTMAX_ARRET)
            &&
             (VSCtl_stCtl_tqWhlPotMin_swc_in == VSCTL_STCTL_TQWHLPOTMIN_ARRET)))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MAX =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_b;
          VSCtl_stCtl_noGearMax = VSCTL_STCTL_NOGEARMAX_ARRET;
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MAX = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_b;
        VSCtl_stCtl_noGearMax = VSCTL_STCTL_NOGEARMAX_ARRET;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F72261_Determiner_Mode_Commande_Rapport_Max*/

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.93.2 */

  VSSP_F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute(VSCtl_stCtl_aVehVSMax_swc_in);

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.95.1 */

    /* TAG_START_OF_STATEFLOW_FUNCTION: F722622_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Filtree*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.97.1 */

    if (vssp_det_gearbox_pedal_sf_dwork.is_active_c361_VSSP_Det_Gearbox_Pedal_Sf
        == 0)
    {
      vssp_det_gearbox_pedal_sf_dwork.is_active_c361_VSSP_Det_Gearbox_Pedal_Sf =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_c361_VSSP_Det_Gearbox_Pedal_Sf =
        (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_CONSIGNE_RAPPORT_MAX_COUPLE_ROUE_POSIITF_FILTREE;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_MONTANT_f = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_m = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET;
      VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
      vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_DESCENDANT_i =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_f =
        (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET;
      VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
      vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_o = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_a = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET;
      VSCtl_noGearMaxTqPosFil = VSCtl_noGearMaxTqPosRaw;

    }
    else
    {
      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_m)
        {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET:
        if (VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_m =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_n =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT;
          VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE:
        if (VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_n =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_b;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_b;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_m =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET;
          VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;

        }
        else
        {
          switch
            (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_n)
          {
           case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_n
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME;
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT;
            VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;
            break;

           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME:
            switch
              (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p)
            {
             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION:
              if (((VSCtl_noGearMaxTqPosRaw > VSCtl_noGearMaxTqPosFil)
              &&
                   (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d >=
                    VSCtl_tiCfmSupReqTqPos))
                    || (VSCtl_noGearMaxTqPosRaw <=
                   CoPt_noTarGearCordIt_swc_in))
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p
                  = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_b;
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_n
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME;
                VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;

              }
              else if (VSCtl_noGearMaxTqPosRaw <= VSCtl_noGearMaxTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT;
                VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;

              }
              else
              {
                VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d =
                  (UInt16)
                  ((vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d +
                    VSSP_F722622_INC) < VSCtl_tiCfmSupReqTqPos ?
                   vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d +
                   VSSP_F722622_INC : (SInt32)VSCtl_tiCfmSupReqTqPos);
              }
              break;

             case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT:
              if (VSCtl_noGearMaxTqPosRaw > VSCtl_noGearMaxTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION;
              }
              break;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_m = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET;
        VSCtl_bAuthSup_noGearMxTqPos = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
        vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;
        break;
      }

      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_f)
  {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET:
        if (VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_f =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_e
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT;
          VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE:
        if (VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_e
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_b;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_b;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_f =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET;
          VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;

        }
        else
        {
          switch
            (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_e)
          {
           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_e
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME;
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT;
            VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;
            break;

           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME:
            switch
              (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m)
            {
             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION:
              if (((VSCtl_noGearMaxTqPosRaw < VSCtl_noGearMaxTqPosFil)
              &&
                   (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a >=
                    VSCtl_tiCfmSdwnReqTqPos))
                    || (VSCtl_noGearMaxTqPosRaw >=
                   CoPt_noTarGearCordIt_swc_in))
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m
                  = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_b;
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_e
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME;
                VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;

              }
              else if (VSCtl_noGearMaxTqPosRaw >= VSCtl_noGearMaxTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT;
                VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;

              }
              else
              {
                VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_FAUX_c;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a =
                  (UInt16)
                  ((vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a +
                    VSSP_F722622_INC) < VSCtl_tiCfmSdwnReqTqPos ?
                   vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a +
                   VSSP_F722622_INC : (SInt32)VSCtl_tiCfmSdwnReqTqPos);
              }
              break;

             case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT:
              if (VSCtl_noGearMaxTqPosRaw < VSCtl_noGearMaxTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION;
              }
              break;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_f =
          (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET;
        VSCtl_bAuthSdwn_noGearMaxTqP = VSSP_Det_Gearbox_Pedal_Sf_VRAI_m;
        vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;
        break;
      }

      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_a)
              {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET:
        if (((VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
        &&
             (VSCtl_bAuthSdwn_noGearMaxTqP == VSSP_Det_Gearbox_Pedal_Sf_FAUX_c))

            && (VSCtl_bAuthSup_noGearMxTqPos == VSSP_Det_Gearbox_Pedal_Sf_FAUX_c))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_a = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE;

        }
        else
        {
          VSCtl_noGearMaxTqPosFil = VSCtl_noGearMaxTqPosRaw;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE:
        if (((VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET)
        ||
             (VSCtl_bAuthSdwn_noGearMaxTqP == VSSP_Det_Gearbox_Pedal_Sf_VRAI_m))

            || (VSCtl_bAuthSup_noGearMxTqPos == VSSP_Det_Gearbox_Pedal_Sf_VRAI_m))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_a = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET;
          VSCtl_noGearMaxTqPosFil = VSCtl_noGearMaxTqPosRaw;
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_a = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET;
        VSCtl_noGearMaxTqPosFil = VSCtl_noGearMaxTqPosRaw;
        break;
      }
    }

    VSCtl_tiAuthSdwn_noGearMxTqP = DDS_M_MIN
      (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a,
       VSCTL_TIAUTHSDWN_NOGEARMXTQP_MAX);

    VSCtl_tiAuthSup_noGearMaxTqP = DDS_M_MIN
      (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d,
       VSCTL_TIAUTHSUP_NOGEARMAXTQP_MAX);

    /* TAG_END_OF_STATEFLOW_FUNCTION: F722622_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Filtree*/

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.98.2 */

  VSSP_F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute();

    /* TAG_START_OF_STATEFLOW_FUNCTION: F722632_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Filtree*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.100.2 */

    if (vssp_det_gearbox_pedal_sf_dwork.is_active_c362_VSSP_Det_Gearbox_Pedal_Sf
        == 0)
    {
      vssp_det_gearbox_pedal_sf_dwork.is_active_c362_VSSP_Det_Gearbox_Pedal_Sf =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_c362_VSSP_Det_Gearbox_Pedal_Sf =
        (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_CONSIGNE_RAPPORT_MAX_COUPLE_ROUE_NEGATIF_FILTREE;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_MONTANT_e = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_l = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_i;
      VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
      vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_DESCENDANT_l =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_b =
        (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_g;
      VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
      vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT1 = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT1 = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_ARRET;
      VSCtl_noGearMaxTqNegFilRaw = VSCtl_noGearMaxTqNegRaw;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT2 = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT2 = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_c;
      VSCtl_noGearMaxTqNegFil = VSCtl_noGearMaxTqNegFilRaw;

    }
    else
    {
      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_l)
        {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_i:
        if (VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_l =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE_h;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_l =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_i;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_h;
          VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE_h:
        if (VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_l =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_l =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_i;
          VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;

        }
        else
        {
          switch
            (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_l)
          {
           case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME_e:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_l
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_i;
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_h;
            VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;
            break;

           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_i:
            switch
              (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d)
            {
             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION_k:
              if (((VSCtl_noGearMaxTqNegRaw > VSCtl_noGearMaxTqNegFilRaw)
              &&
                   (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j >=
                    VSCtl_tiCfmSupReqTqNeg))
                    || (VSCtl_noGearMaxTqNegRaw <=
                   CoPt_noTarGearCordIt_swc_in))
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d
                  = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_l
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME_e;
                VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;

              }
              else if (VSCtl_noGearMaxTqNegRaw <= VSCtl_noGearMaxTqNegFilRaw)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_h;
                VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;

              }
              else
              {
                VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j =
                  (UInt16)
                  ((vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j +
                    VSSP_F722632_INC) < VSCtl_tiCfmSupReqTqNeg ?
                   vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j +
                   VSSP_F722632_INC : (SInt32)VSCtl_tiCfmSupReqTqNeg);
              }
              break;

             case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_h:
              if (VSCtl_noGearMaxTqNegRaw > VSCtl_noGearMaxTqNegFilRaw)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION_k;
              }
              break;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_l = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_i;
        VSCtl_bAuthSup_noGearMxTqNeg = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
        vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;
        break;
      }

      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_b)
  {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_g:
        if (VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_b =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_j;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_n
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_b;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_f;
          VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_j:
        if (VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_n
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_b =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_g;
          VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;

        }
        else
        {
          switch
            (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_n)
          {
           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME_b:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_n
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_b;
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_f;
            VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;
            break;

           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_b:
            switch
              (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d)
            {
             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION_a:
              if (((VSCtl_noGearMaxTqNegRaw < VSCtl_noGearMaxTqNegFilRaw)
              &&
                   (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n >=
                    VSCtl_tiCfmSdwnReqTqNeg))
                    || (VSCtl_noGearMaxTqNegRaw >=
                   CoPt_noTarGearCordIt_swc_in))
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d
                  = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_n
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME_b;
                VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;

              }
              else if (VSCtl_noGearMaxTqNegRaw >= VSCtl_noGearMaxTqNegFilRaw)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_f;
                VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;

              }
              else
              {
                VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_FAUX_e;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n =
                  (UInt16)
                  ((vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n +
                    VSSP_F722632_INC) < VSCtl_tiCfmSdwnReqTqNeg ?
                   vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n +
                   VSSP_F722632_INC : (SInt32)VSCtl_tiCfmSdwnReqTqNeg);
              }
              break;

             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_f:
              if (VSCtl_noGearMaxTqNegRaw < VSCtl_noGearMaxTqNegFilRaw)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION_a;
              }
              break;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_b =
          (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_g;
        VSCtl_bAuthSdwn_noGearMaxTqN = VSSP_Det_Gearbox_Pedal_Sf_VRAI_j;
        vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;
        break;
      }

      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT1)
              {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_ARRET:
        if (VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          VSCtl_noGearMaxTqNegFilRaw = (UInt8)CoPt_noTarGearCordIt_swc_in;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT1 = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_b;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE_g =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_GEL;

        }
        else
        {
          VSCtl_noGearMaxTqNegFilRaw = VSCtl_noGearMaxTqNegRaw;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_b:
        if (VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE_g =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT1 = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_ARRET;
          VSCtl_noGearMaxTqNegFilRaw = VSCtl_noGearMaxTqNegRaw;

        }
        else
        {
          switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE_g)
          {
           case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_CHANGEMENT:
            if (((VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
            &&
                 (VSCtl_bAuthSdwn_noGearMaxTqN ==
                  VSSP_Det_Gearbox_Pedal_Sf_FAUX_e)) &&
                (VSCtl_bAuthSup_noGearMxTqNeg ==
                 VSSP_Det_Gearbox_Pedal_Sf_FAUX_e))
            {
              vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE_g =
                (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_GEL;
            }
            break;

           case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_GEL:
            if ((VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
            &&
                ((VSCtl_bAuthSdwn_noGearMaxTqN ==
                  VSSP_Det_Gearbox_Pedal_Sf_VRAI_j) ||
                 (VSCtl_bAuthSup_noGearMxTqNeg ==
                  VSSP_Det_Gearbox_Pedal_Sf_VRAI_j)))
            {
              vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE_g =
                (UInt8)
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_CHANGEMENT;
              VSCtl_noGearMaxTqNegFilRaw = VSCtl_noGearMaxTqNegRaw;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT1 = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT1_ARRET;
        VSCtl_noGearMaxTqNegFilRaw = VSCtl_noGearMaxTqNegRaw;
        break;
      }

      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT2)
            {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_c:
        if (VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          VSCtl_noGearMaxTqNegFil = (UInt8)CoPt_noTarGearCordIt_swc_in;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT2 = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_b;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_MAINTENIR_RAPPORT;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b =
            VSCtl_tiCfmSdwnTqNeg_C;

        }
        else
        {
          VSCtl_noGearMaxTqNegFil = VSCtl_noGearMaxTqNegFilRaw;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_b:
        if (VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_g;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT2 = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_c;
          VSCtl_noGearMaxTqNegFil = VSCtl_noGearMaxTqNegFilRaw;

        }
        else
        {
          switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE)
            {
           case VSSP_Det_Gearbox_Pedal_Sf_IN_AUTORISER_DOWN:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE =
              (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MAINTENIR_RAPPORT;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b =
              VSCtl_tiCfmSdwnTqNeg_C;
            break;

           case VSSP_Det_Gearbox_Pedal_Sf_IN_AUTORISER_UP:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE =
              (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MAINTENIR_RAPPORT;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b =
              VSCtl_tiCfmSdwnTqNeg_C;
            break;

           case VSSP_Det_Gearbox_Pedal_Sf_IN_MAINTENIR_RAPPORT:
            if ((VSCtl_noGearMaxTqNegFilRaw < VSCtl_noGearMaxTqNegFil)
            &&
                (VSCtl_bCtlaTqPT_swc_in == VSSP_Det_Gearbox_Pedal_Sf_FAUX_e))
            {
              vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE =
                (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_TEMPORISER_DOWN;

            }
            else if (VSCtl_noGearMaxTqNegFilRaw > VSCtl_noGearMaxTqNegFil)
            {
              vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE =
                (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_AUTORISER_UP;
              VSCtl_noGearMaxTqNegFil = VSCtl_noGearMaxTqNegFilRaw;
            }
            break;

           case VSSP_Det_Gearbox_Pedal_Sf_IN_TEMPORISER_DOWN:
            if ((VSCtl_noGearMaxTqNegFilRaw >= VSCtl_noGearMaxTqNegFil)
            ||
                (VSCtl_bCtlaTqPT_swc_in == VSSP_Det_Gearbox_Pedal_Sf_VRAI_j))
            {
              vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE =
                (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MAINTENIR_RAPPORT;
              vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b =
                VSCtl_tiCfmSdwnTqNeg_C;

            }
            else if (((VSCtl_noGearMaxTqNegFilRaw < VSCtl_noGearMaxTqNegFil)
            &&
                        (VSCtl_bCtlaTqPT_swc_in == VSSP_Det_Gearbox_Pedal_Sf_FAUX_e))
                        &&
                       (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b
                        == 0))
            {
              vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE =
                (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_AUTORISER_DOWN;
              VSCtl_noGearMaxTqNegFil = (UInt8)DDS_M_MAX(VSCtl_noGearMaxTqNegFil
                - 1, 1);

            }
            else
            {
              vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b =
                (UInt16)DDS_M_MAX
                (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b -
                 VSSP_F722632_INC, 0);
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT2 = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_c;
        VSCtl_noGearMaxTqNegFil = VSCtl_noGearMaxTqNegFilRaw;
        break;
      }
    }

    VSCtl_tiAuthSdwn_noGearMxTN2 = DDS_M_MIN
      (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b,
       VSCTL_TIAUTHSDWN_NOGEARMXTN2_MAX);

    VSCtl_tiAuthSdwn_noGearMxTqN = DDS_M_MIN
      (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n,
       VSCTL_TIAUTHSDWN_NOGEARMXTQN_MAX);

    VSCtl_tiAuthSup_noGearMaxTqN = DDS_M_MIN
      (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j,
       VSCTL_TIAUTHSUP_NOGEARMAXTQN_MAX);

    /* TAG_END_OF_STATEFLOW_FUNCTION: F722632_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Filtree*/

  VSSP_F72264_Determiner_Consigne_Rapport_Max(&vssp_vsctl_nogearreqmax_cpy);

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.102.1 */

    /* TAG_START_OF_STATEFLOW_FUNCTION: F72271_Determiner_Mode_Commande_Rapport_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.103.0 */

    if (vssp_det_gearbox_pedal_sf_dwork.is_active_c363_VSSP_Det_Gearbox_Pedal_Sf
        == 0)
    {
      vssp_det_gearbox_pedal_sf_dwork.is_active_c363_VSSP_Det_Gearbox_Pedal_Sf =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_c363_VSSP_Det_Gearbox_Pedal_Sf =
        (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_COMMANDE_RAPPORT_MIN;
      vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MIN = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_m;
      VSCtl_stCtl_noGearMin = VSCTL_STCTL_NOGEARMIN_ARRET;

    }
    else
    {
      switch (vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MIN)
            {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_m:
        if ((vssp_vsctl_stctl_nogear_cpy == VSCTL_STCTL_NOGEAR_CONTROLE_38) &&
            (VSCtl_stCtl_tqWhlPotMax_swc_in != VSCTL_STCTL_TQWHLPOTMAX_ARRET))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MIN =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE_m;
          VSCtl_stCtl_noGearMin = VSCTL_STCTL_NOGEARMIN_MARCHE;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE_m:
        if ((vssp_vsctl_stctl_nogear_cpy != VSCTL_STCTL_NOGEAR_CONTROLE_38) ||
            (VSCtl_stCtl_tqWhlPotMax_swc_in == VSCTL_STCTL_TQWHLPOTMAX_ARRET))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MIN =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_m;
          VSCtl_stCtl_noGearMin = VSCTL_STCTL_NOGEARMIN_ARRET;
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MIN = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_m;
        VSCtl_stCtl_noGearMin = VSCTL_STCTL_NOGEARMIN_ARRET;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F72271_Determiner_Mode_Commande_Rapport_Min*/

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.104.1 */

  VSSP_F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute();

    /* TAG_START_OF_STATEFLOW_FUNCTION: F722722_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Filtree*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.106.1 */

    if (vssp_det_gearbox_pedal_sf_dwork.is_active_c364_VSSP_Det_Gearbox_Pedal_Sf
        == 0)
    {
      vssp_det_gearbox_pedal_sf_dwork.is_active_c364_VSSP_Det_Gearbox_Pedal_Sf =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_c364_VSSP_Det_Gearbox_Pedal_Sf =
        (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_CONSIGNE_RAPPORT_MIN_COUPLE_ROUE_POSIITF_FILTREE;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_MONTANT = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_m;
      VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
      vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_DESCENDANT = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_h;
      VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
      vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;
      vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT = 1U;
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_k;
      VSCtl_noGearMinTqPosFil = VSCtl_noGearMinTqPosRaw;

    }
    else
    {
      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT)
        {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_m:
        if (VSCtl_stCtl_noGearMin != VSCTL_STCTL_NOGEARMIN_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE_p;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_k;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_e;
          VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_MARCHE_p:
        if (VSCtl_stCtl_noGearMin == VSCTL_STCTL_NOGEARMIN_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_a;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_a;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_m;
          VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;

        }
        else
        {
          switch
            (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE)
          {
           case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME_h:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE =
              (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_k;
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_e;
            VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;
            break;

           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_k:
            switch
              (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME)
            {
             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION_e:
              if (((VSCtl_noGearMinTqPosRaw > VSCtl_noGearMinTqPosFil)
              &&
                   (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e >=
                    VSCtl_tiCfmSupReqTqPos))
                    || (VSCtl_noGearMinTqPosRaw <=
                   CoPt_noTarGearCordIt_swc_in))
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME
                  = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_a;
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRME_h;
                VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;

              }
              else if (VSCtl_noGearMinTqPosRaw <= VSCtl_noGearMinTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_e;
                VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;

              }
              else
              {
                VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e =
                  (UInt16)
                  ((vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e +
                    VSSP_F722722_INC) < VSCtl_tiCfmSupReqTqPos ?
                   vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e +
                   VSSP_F722722_INC : (SInt32)VSCtl_tiCfmSupReqTqPos);
              }
              break;

             case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_INIT_e:
              if (VSCtl_noGearMinTqPosRaw > VSCtl_noGearMinTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_CONFIRMATION_e;
              }
              break;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MONTANT_ARRET_m;
        VSCtl_bAuthSup_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
        vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;
        break;
      }

      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT)
              {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_h:
        if (VSCtl_stCtl_noGearMin != VSCTL_STCTL_NOGEARMIN_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_g;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_j;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME
            = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_b;
          VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_g:
        if (VSCtl_stCtl_noGearMin == VSCTL_STCTL_NOGEARMIN_ARRET)
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE =
            (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_a;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME
            = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_a;
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT =
            (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_h;
          VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
          vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;

        }
        else
        {
          switch
            (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE)
          {
           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME_a:
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_j;
            vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME
              = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_b;
            VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
            vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;
            break;

           case
              VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_j:
            switch
              (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME)
            {
             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION_i:
              if (((VSCtl_noGearMinTqPosRaw < VSCtl_noGearMinTqPosFil)
              &&
                   (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k >=
                    VSCtl_tiCfmSdwnReqTqPos))
                    || (VSCtl_noGearMinTqPosRaw >=
                   CoPt_noTarGearCordIt_swc_in))
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME
                  = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_a;
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRME_a;
                VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;

              }
              else if (VSCtl_noGearMinTqPosRaw >= VSCtl_noGearMinTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_b;
                VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;

              }
              else
              {
                VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i;
                vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k =
                  (UInt16)
                  ((vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k +
                    VSSP_F722722_INC) < VSCtl_tiCfmSdwnReqTqPos ?
                   vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k +
                   VSSP_F722722_INC : (SInt32)VSCtl_tiCfmSdwnReqTqPos);
              }
              break;

             case
                VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_INIT_b:
              if (VSCtl_noGearMinTqPosRaw < VSCtl_noGearMinTqPosFil)
              {
                vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME
                  = (UInt8)
                  VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_CONFIRMATION_i;
              }
              break;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT =
          (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_DESCENDANT_ARRET_h;
        VSCtl_bAuthSdwn_noGearMin = VSSP_Det_Gearbox_Pedal_Sf_VRAI_n;
        vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;
        break;
      }

      switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT)
              {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_k:
        if (((VSCtl_stCtl_noGearMin != VSCTL_STCTL_NOGEARMIN_ARRET)
        &&
             (VSCtl_bAuthSdwn_noGearMin == VSSP_Det_Gearbox_Pedal_Sf_FAUX_i))
             &&
            (VSCtl_bAuthSup_noGearMin == VSSP_Det_Gearbox_Pedal_Sf_FAUX_i))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_g;

        }
        else
        {
          VSCtl_noGearMinTqPosFil = VSCtl_noGearMinTqPosRaw;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_MARCHE_g:
        if (((VSCtl_stCtl_noGearMin == VSCTL_STCTL_NOGEARMIN_ARRET)
        ||
             (VSCtl_bAuthSdwn_noGearMin == VSSP_Det_Gearbox_Pedal_Sf_VRAI_n))
             ||
            (VSCtl_bAuthSup_noGearMin == VSSP_Det_Gearbox_Pedal_Sf_VRAI_n))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_k;
          VSCtl_noGearMinTqPosFil = VSCtl_noGearMinTqPosRaw;
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_RAPPORT_ARRET_k;
        VSCtl_noGearMinTqPosFil = VSCtl_noGearMinTqPosRaw;
        break;
      }
    }

    VSCtl_tiAuthSdwn_noGearMin = DDS_M_MIN
      (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k,
       VSCTL_TIAUTHSDWN_NOGEARMIN_MAX);

    VSCtl_tiAuthSup_noGearMin = DDS_M_MIN
      (vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e,
       VSCTL_TIAUTHSUP_NOGEARMIN_MAX);

    /* TAG_END_OF_STATEFLOW_FUNCTION: F722722_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Filtree*/

  VSSP_F72273_Coordonner_Consigne_Rapport_Min(vssp_vsctl_nogearreqmax_cpy,
                                                &vssp_vsctl_nogearreqmin_cpy );

    /* TAG_START_OF_STATEFLOW_FUNCTION: F7228_Determiner_Demande_Pilotage_Controle_Rapport*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.108.0 */

    if (vssp_det_gearbox_pedal_sf_dwork.is_active_c365_VSSP_Det_Gearbox_Pedal_Sf
        == 0)
    {
      vssp_det_gearbox_pedal_sf_dwork.is_active_c365_VSSP_Det_Gearbox_Pedal_Sf =
        1U;
      vssp_det_gearbox_pedal_sf_dwork.is_c365_VSSP_Det_Gearbox_Pedal_Sf =
        (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CONTROLE_RAPPORT;
      vssp_det_gearbox_pedal_sf_dwork.is_MODE_CONTROLE_RAPPORT = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_i;
      vssp_vsctl_stgearctlreq_cpy = VSCTL_STGEARCTLREQ_NON_DEMANDE;

    }
    else
    {
      switch (vssp_det_gearbox_pedal_sf_dwork.is_MODE_CONTROLE_RAPPORT)
        {
       case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_i:
        if ((VSCtl_stCtl_noGearMin != VSCTL_STCTL_NOGEARMIN_ARRET) ||
            (VSCtl_stCtl_noGearMax != VSCTL_STCTL_NOGEARMAX_ARRET))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_CONTROLE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE_e;
          vssp_det_gearbox_pedal_sf_dwork.is_MARCHE = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_DEMANDE;
          vssp_vsctl_stgearctlreq_cpy = VSCTL_STGEARCTLREQ_DEMANDE;
        }
        break;

       case VSSP_Det_Gearbox_Pedal_Sf_IN_MARCHE_e:
        if ((VSCtl_stCtl_noGearMin == VSCTL_STCTL_NOGEARMIN_ARRET) &&
            (VSCtl_stCtl_noGearMax == VSCTL_STCTL_NOGEARMAX_ARRET))
        {
          vssp_det_gearbox_pedal_sf_dwork.is_MARCHE = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_e;
          vssp_det_gearbox_pedal_sf_dwork.is_MODE_CONTROLE_RAPPORT = (UInt8)
            VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_i;
          vssp_vsctl_stgearctlreq_cpy = VSCTL_STGEARCTLREQ_NON_DEMANDE;

        }
        else
        {
          switch (vssp_det_gearbox_pedal_sf_dwork.is_MARCHE)
        {
           case VSSP_Det_Gearbox_Pedal_Sf_IN_DEMANDE:
            if (vssp_vsctl_nogearreqmin_cpy >= vssp_vsctl_nogearreqmax_cpy)
            {
              vssp_det_gearbox_pedal_sf_dwork.is_MARCHE = (UInt8)
                VSSP_Det_Gearbox_Pedal_Sf_IN_FULL_PASS;
              vssp_vsctl_stgearctlreq_cpy = VSCTL_STGEARCTLREQ_FULL_PASS;
            }
            break;

           case VSSP_Det_Gearbox_Pedal_Sf_IN_FULL_PASS:
            if (vssp_vsctl_nogearreqmin_cpy < vssp_vsctl_nogearreqmax_cpy)
            {
              vssp_det_gearbox_pedal_sf_dwork.is_MARCHE = (UInt8)
                VSSP_Det_Gearbox_Pedal_Sf_IN_DEMANDE;
              vssp_vsctl_stgearctlreq_cpy = VSCTL_STGEARCTLREQ_DEMANDE;
            }
            break;
          }
        }
        break;

       default:
        vssp_det_gearbox_pedal_sf_dwork.is_MODE_CONTROLE_RAPPORT = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_i;
        vssp_vsctl_stgearctlreq_cpy = VSCTL_STGEARCTLREQ_NON_DEMANDE;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F7228_Determiner_Demande_Pilotage_Controle_Rapport*/

  }

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.109.1 */

  /* TAG_START_OF_STATEFLOW_FUNCTION: F7231_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.110.0 */

  if (vssp_det_gearbox_pedal_sf_dwork.is_active_c13_VSSP_Det_Gearbox_Pedal_Sf ==
      0)
  {
    vssp_det_gearbox_pedal_sf_dwork.is_active_c13_VSSP_Det_Gearbox_Pedal_Sf = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_c13_VSSP_Det_Gearbox_Pedal_Sf = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION;
    vssp_det_gearbox_pedal_sf_dwork.is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION
      = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_l;
    VSCtl_stCtl_rAccPTra = VSCTL_STCTL_RACCPTRA_ARRET;
    VSCtl_bAcvFil_rAccPTra = VSSP_Det_Gearbox_Pedal_Sf_FAUX_m;

  }
  else
  {
    switch
      (vssp_det_gearbox_pedal_sf_dwork.is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION)
    {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_ACTIF:
      if ((VSCtl_bCtlCmdPTTqCf_SC != VSSP_Det_Gearbox_Pedal_Sf_FAUX_m)
      ||
          ((Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
          &&
           (Ext_stCtlCmdPTTqPotCf_swc_in != EXT_STCTLCMDPTTQPOTCF_RAPPORT)))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION
          = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_l;
        VSCtl_stCtl_rAccPTra = VSCTL_STCTL_RACCPTRA_ARRET;
        VSCtl_bAcvFil_rAccPTra = VSSP_Det_Gearbox_Pedal_Sf_FAUX_m;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_l:
      if ((VSCtl_bCtlCmdPTTqCf_SC == VSSP_Det_Gearbox_Pedal_Sf_FAUX_m)
      &&
          ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
          ||
           (Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION
          = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ACTIF;
        VSCtl_stCtl_rAccPTra = VSCTL_STCTL_RACCPTRA_ACTIF;
        VSCtl_bAcvFil_rAccPTra = VSSP_Det_Gearbox_Pedal_Sf_VRAI_jm;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION
        = (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_l;
      VSCtl_stCtl_rAccPTra = VSCTL_STCTL_RACCPTRA_ARRET;
      VSCtl_bAcvFil_rAccPTra = VSSP_Det_Gearbox_Pedal_Sf_FAUX_m;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F7231_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission*/


  stack_data_u16_0 = vssp_det_gearbox_pedal_s_delay_0;

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.112.1 */

  /* TAG_START_OF_STATEFLOW_FUNCTION: F72321_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_RVV*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.113.0 */

  if (vssp_det_gearbox_pedal_sf_dwork.is_active_c14_VSSP_Det_Gearbox_Pedal_Sf ==
      0)
  {
    vssp_det_gearbox_pedal_sf_dwork.is_active_c14_VSSP_Det_Gearbox_Pedal_Sf = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_c14_VSSP_Det_Gearbox_Pedal_Sf = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_RVV;
    vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_RVV = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_RVV = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_f;
    VSCtl_stCtl_rAccPVSReg = VSCTL_STCTL_RACCPVSREG_ARRET;
    vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_RVV = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_RVV = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF;
    VSCtl_bAcvFil_rAccPMaxVSReg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_ik;
    vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES_m = 1U;

  }
  else
  {
    switch (vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_RVV)
      {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_f:
      if ((VSCtl_stCtl_rAccPTra == VSCTL_STCTL_RACCPTRA_ACTIF) &&
          (VSCtl_stCtl_aVehVSReg_swc_in == VSCTL_STCTL_AVEHVSREG_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_RVV = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_c;
        vssp_det_gearbox_pedal_sf_dwork.is_CONTROLE = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE____0;
        VSCtl_stCtl_rAccPVSReg = VSCTL_STCTL_RACCPVSREG_CONTROLE;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_c:
      if ((VSCtl_stCtl_rAccPTra != VSCTL_STCTL_RACCPTRA_ACTIF) ||
          ((VSCtl_stCtl_aVehVSReg_swc_in != VSCTL_STCTL_AVEHVSREG_CONTROLE)
          &&
           (VSCtl_rAccPEngMin_swc_in <= stack_data_u16_0)))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_CONTROLE = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_NO_ACTIVE_CHILD_o;
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_RVV = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_f;
        VSCtl_stCtl_rAccPVSReg = VSCTL_STCTL_RACCPVSREG_ARRET;

      }
      else
      {
        switch (vssp_det_gearbox_pedal_sf_dwork.is_CONTROLE)
      {
         case VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE____0:
          if (VSCtl_stCtl_aVehVSReg_swc_in != VSCTL_STCTL_AVEHVSREG_CONTROLE)
          {
            vssp_det_gearbox_pedal_sf_dwork.is_CONTROLE = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_TRANSITION;
            VSCtl_stCtl_rAccPVSReg = VSCTL_STCTL_RACCPVSREG_TRANSITION;
          }
          break;

         case VSSP_Det_Gearbox_Pedal_Sf_IN_TRANSITION:
          if (VSCtl_stCtl_aVehVSReg_swc_in == VSCTL_STCTL_AVEHVSREG_CONTROLE)
          {
            vssp_det_gearbox_pedal_sf_dwork.is_CONTROLE = (UInt8)
              VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE____0;
            VSCtl_stCtl_rAccPVSReg = VSCTL_STCTL_RACCPVSREG_CONTROLE;
          }
          break;
        }
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_RVV = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_f;
      VSCtl_stCtl_rAccPVSReg = VSCTL_STCTL_RACCPVSREG_ARRET;
      break;
    }

    switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_RVV)
          {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF:
      if (VSCtl_stCtl_rAccPVSReg != VSCTL_STCTL_RACCPVSREG_CONTROLE)
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_RVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF;
        VSCtl_bAcvFil_rAccPMaxVSReg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_ik;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF:
      if ((VSCtl_stCtl_rAccPVSReg == VSCTL_STCTL_RACCPVSREG_CONTROLE)
      &&
          (VSCtl_stCtl_rAccPVSRegPrev == VSCTL_STCTL_RACCPVSREGPREV_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_RVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF;
        VSCtl_bAcvFil_rAccPMaxVSReg = VSSP_Det_Gearbox_Pedal_Sf_VRAI_b;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_RVV = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF;
      VSCtl_bAcvFil_rAccPMaxVSReg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_ik;
      break;
    }

    VSCtl_stCtl_rAccPVSRegPrev = VSCtl_stCtl_rAccPVSReg;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F72321_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_RVV*/

    VSSP_F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_RVV(VSCtl_spdVehErrVSReg_swc_in,
                                                                                    AccP_rAccP_swc_in,
                                                                                    VSCtl_spdVeh_swc_in);

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.116.1 */

  /* TAG_START_OF_STATEFLOW_FUNCTION: F72331_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_ACC*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.117.0 */

  if (vssp_det_gearbox_pedal_sf_dwork.is_active_c15_VSSP_Det_Gearbox_Pedal_Sf ==
      0)
  {
    vssp_det_gearbox_pedal_sf_dwork.is_active_c15_VSSP_Det_Gearbox_Pedal_Sf = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_c15_VSSP_Det_Gearbox_Pedal_Sf = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_ACC;
    vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_ACC = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_ACC = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_c;
    VSCtl_stCtl_rAccPDVSReg = VSCTL_STCTL_RACCPDVSREG_ARRET;
    vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_ACC = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_ACC = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_b;
    VSCtl_bAcvFil_rAccPMaxDVSReg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i4;
    vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES_k = 1U;

  }
  else
  {
    switch (vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_ACC)
      {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_c:
      if ((VSCtl_stCtl_rAccPTra == VSCTL_STCTL_RACCPTRA_ACTIF) &&
          (VSCtl_stCtl_aVehDVSReg_swc_in == VSCTL_STCTL_AVEHDVSREG_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_ACC = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_a;
        VSCtl_stCtl_rAccPDVSReg = VSCTL_STCTL_RACCPDVSREG_CONTROLE;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_a:
      if ((VSCtl_stCtl_rAccPTra != VSCTL_STCTL_RACCPTRA_ACTIF) ||
          (VSCtl_stCtl_aVehDVSReg_swc_in != VSCTL_STCTL_AVEHDVSREG_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_ACC = (UInt8)
          VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_c;
        VSCtl_stCtl_rAccPDVSReg = VSCTL_STCTL_RACCPDVSREG_ARRET;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_ACC = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_c;
      VSCtl_stCtl_rAccPDVSReg = VSCTL_STCTL_RACCPDVSREG_ARRET;
      break;
    }

    switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_ACC)
      {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_f:
      if (VSCtl_stCtl_rAccPDVSReg != VSCTL_STCTL_RACCPDVSREG_CONTROLE)
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_ACC =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_b;
        VSCtl_bAcvFil_rAccPMaxDVSReg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i4;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_b:
      if ((VSCtl_stCtl_rAccPDVSReg == VSCTL_STCTL_RACCPDVSREG_CONTROLE)
      &&
          (VSCtl_stCtl_rAccPDVSRegPrev == VSCTL_STCTL_RACCPDVSREGPREV_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_ACC =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_f;
        VSCtl_bAcvFil_rAccPMaxDVSReg = VSSP_Det_Gearbox_Pedal_Sf_VRAI_nd;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_ACC = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_b;
      VSCtl_bAcvFil_rAccPMaxDVSReg = VSSP_Det_Gearbox_Pedal_Sf_FAUX_i4;
      break;
    }

    VSCtl_stCtl_rAccPDVSRegPrev = VSCtl_stCtl_rAccPDVSReg;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F72331_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_ACC*/

    VSSP_F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_ACC(VSCtl_aVehDVSRegReq_swc_in,
                                                VSCtl_spdVeh_swc_in);

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.120.1 */

  /* TAG_START_OF_STATEFLOW_FUNCTION: F72341_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_LVV*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.121.0 */

  if (vssp_det_gearbox_pedal_sf_dwork.is_active_c16_VSSP_Det_Gearbox_Pedal_Sf ==
      0)
  {
    vssp_det_gearbox_pedal_sf_dwork.is_active_c16_VSSP_Det_Gearbox_Pedal_Sf = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_c16_VSSP_Det_Gearbox_Pedal_Sf = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_LVV;
    vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_MAX_LVV = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_LVV = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_a;
    VSCtl_stCtl_rAccPVSLim = VSCTL_STCTL_RACCPVSLIM_ARRET;
    vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_LVV = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_LVV = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_bv;
    VSCtl_bAcvFil_rAccPMaxVSLim = VSSP_Det_Gearbox_Pedal_Sf_FAUX_a;
    vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES_l = 1U;

  }
  else
  {
    switch (vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_LVV)
      {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_a:
      if ((VSCtl_stCtl_rAccPTra == VSCTL_STCTL_RACCPTRA_ACTIF) &&
          (VSCtl_stCtl_aVehVSLim_swc_in == VSCTL_STCTL_AVEHVSLIM_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_LVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_m;
        VSCtl_stCtl_rAccPVSLim = VSCTL_STCTL_RACCPVSLIM_CONTROLE;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_m:
      if ((VSCtl_stCtl_rAccPTra != VSCTL_STCTL_RACCPTRA_ACTIF) ||
          (VSCtl_stCtl_aVehVSLim_swc_in != VSCTL_STCTL_AVEHVSLIM_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_LVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_a;
        VSCtl_stCtl_rAccPVSLim = VSCTL_STCTL_RACCPVSLIM_ARRET;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_LVV = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_a;
      VSCtl_stCtl_rAccPVSLim = VSCTL_STCTL_RACCPVSLIM_ARRET;
      break;
    }

    switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_LVV)
      {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_h:
      if (VSCtl_stCtl_rAccPVSLim != VSCTL_STCTL_RACCPVSLIM_CONTROLE)
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_LVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_bv;
        VSCtl_bAcvFil_rAccPMaxVSLim = VSSP_Det_Gearbox_Pedal_Sf_FAUX_a;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_bv:
      if ((VSCtl_stCtl_rAccPVSLim == VSCTL_STCTL_RACCPVSLIM_CONTROLE)
      &&
          (VSCtl_stCtl_rAccPVSLimPrev == VSCTL_STCTL_RACCPVSLIMPREV_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_LVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_h;
        VSCtl_bAcvFil_rAccPMaxVSLim = VSSP_Det_Gearbox_Pedal_Sf_VRAI_mg;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_LVV = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_bv;
      VSCtl_bAcvFil_rAccPMaxVSLim = VSSP_Det_Gearbox_Pedal_Sf_FAUX_a;
      break;
    }

    VSCtl_stCtl_rAccPVSLimPrev = VSCtl_stCtl_rAccPVSLim;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F72341_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_LVV*/

    VSSP_F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_LVV(VSCtl_spdVehErrVSLim_swc_in,
                                                AccP_rAccP_swc_in,
                                                VSCtl_spdVeh_swc_in);

	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.124.1 */

  /* TAG_START_OF_STATEFLOW_FUNCTION: F72351_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_BVV*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.125.0 */

  if (vssp_det_gearbox_pedal_sf_dwork.is_active_c17_VSSP_Det_Gearbox_Pedal_Sf ==
      0)
  {
    vssp_det_gearbox_pedal_sf_dwork.is_active_c17_VSSP_Det_Gearbox_Pedal_Sf = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_c17_VSSP_Det_Gearbox_Pedal_Sf = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION_BVV;
    vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_MAX_BVV = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_BVV = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_e;
    VSCtl_stCtl_rAccPVSMax = VSCTL_STCTL_RACCPVSMAX_ARRET;
    vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_BVV = 1U;
    vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_BVV = (UInt8)
      VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_n;
    VSCtl_bAcvFil_rAccPMaxVSMax = VSSP_Det_Gearbox_Pedal_Sf_FAUX_g;
    vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES = 1U;

  }
  else
  {
    switch (vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_BVV)
      {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_e:
      if ((VSCtl_stCtl_rAccPTra == VSCTL_STCTL_RACCPTRA_ACTIF) &&
          (VSCtl_stCtl_aVehVSMax_swc_in == VSCTL_STCTL_AVEHVSMAX_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_BVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_h;
        VSCtl_stCtl_rAccPVSMax = VSCTL_STCTL_RACCPVSMAX_CONTROLE;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_CONTROLE_h:
      if ((VSCtl_stCtl_rAccPTra != VSCTL_STCTL_RACCPTRA_ACTIF) ||
          (VSCtl_stCtl_aVehVSMax_swc_in != VSCTL_STCTL_AVEHVSMAX_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_BVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_e;
        VSCtl_stCtl_rAccPVSMax = VSCTL_STCTL_RACCPVSMAX_ARRET;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_BVV = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_ARRET_e;
      VSCtl_stCtl_rAccPVSMax = VSCTL_STCTL_RACCPVSMAX_ARRET;
      break;
    }

    switch (vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_BVV)
      {
     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_c:
      if (VSCtl_stCtl_rAccPVSMax != VSCTL_STCTL_RACCPVSMAX_CONTROLE)
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_BVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_n;
        VSCtl_bAcvFil_rAccPMaxVSMax = VSSP_Det_Gearbox_Pedal_Sf_FAUX_g;
      }
      break;

     case VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_n:
      if ((VSCtl_stCtl_rAccPVSMax == VSCTL_STCTL_RACCPVSMAX_CONTROLE)
      &&
          (VSCtl_stCtl_rAccPVSMaxPrev == VSCTL_STCTL_RACCPVSMAXPREV_CONTROLE))
      {
        vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_BVV =
          (UInt8)VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_ACTIF_c;
        VSCtl_bAcvFil_rAccPMaxVSMax = VSSP_Det_Gearbox_Pedal_Sf_VRAI_nj;
      }
      break;

     default:
      vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_BVV = (UInt8)
        VSSP_Det_Gearbox_Pedal_Sf_IN_FILTRAGE_INACTIF_n;
      VSCtl_bAcvFil_rAccPMaxVSMax = VSSP_Det_Gearbox_Pedal_Sf_FAUX_g;
      break;
    }

    VSCtl_stCtl_rAccPVSMaxPrev = VSCtl_stCtl_rAccPVSMax;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F72351_Determiner_Mode_Calcul_Position_Pedale_Accelerateur_Transmission_BVV*/

    VSSP_F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV(VSCtl_spdVehErrVSMax_swc_in,
                                                AccP_rAccP_swc_in,
                                                VSCtl_spdVeh_swc_in);

    VSSP_F7236_Determiner_Position_Pedales_Tramsmission_XVV(&vssp_vsctl_raccptramax_cpy,
                                                        &vssp_vsctl_raccptramin_cpy);

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_rAccPTraMax_swc_out = vssp_vsctl_raccptramax_cpy;

  *VSCtl_rAccPTraMin_swc_out = vssp_vsctl_raccptramin_cpy;

  *VSCtl_noGearReqMax_swc_out = vssp_vsctl_nogearreqmax_cpy;

  *VSCtl_noGearReqMin_swc_out = vssp_vsctl_nogearreqmin_cpy;

  *VSCtl_stCtl_noGear_swc_out = vssp_vsctl_stctl_nogear_cpy;

  *VSCtl_stGearCtlReq_swc_out = vssp_vsctl_stgearctlreq_cpy;


  vssp_det_gearbox_pedal_s_delay_0 = VSCtl_rAccPTraMaxVSReg;
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Pedal_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_noGear_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGearCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMax_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMin_swc_out)                            /*BIN7*/
{
    VSSP_Det_Gearbox_Speed_Sl_Init();

    VSSP_Det_Gearbox_Order_Sl_Init(VSCtl_noGearReqMax_swc_out,
                                    VSCtl_noGearReqMin_swc_out );

    VSSP_Position_Pedale_Sl_Init(VSCtl_rAccPTraMax_swc_out, /* BIN7 */
                                    VSCtl_rAccPTraMin_swc_out /* BIN7 */);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  VSCtl_tiAuthSdwn_noGearMxTqN=0;
  VSCtl_tiAuthSdwn_noGearMxTqP=0;
  VSCtl_tiAuthSup_noGearMin=0;
  vssp_det_gearbox_pedal_sf_dwork.is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION=0;
  vssp_vsctl_raccptramin_cpy = *VSCtl_rAccPTraMin_swc_out;

  VSCtl_tiAuthSdwn_noGearMin=0;
  VSCtl_tiAuthSup_noGearMaxTqN=0;
  VSCtl_tiAuthSup_noGearMaxTqP=0;
  VSCtl_tiAuthSdwn_noGearMxTN2=0;
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiFilStCtlnoGear = VSCtl_tiFil_stCtlnoGear_C;   /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_raccptramax_cpy = *VSCtl_rAccPTraMax_swc_out;

  VSCtl_stCtl_rAccPVSMax = VSCTL_STCTL_RACCPVSMAX_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPVSMaxPrev = VSCTL_STCTL_RACCPVSMAXPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPVSLim = VSCTL_STCTL_RACCPVSLIM_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPVSLimPrev = VSCTL_STCTL_RACCPVSLIMPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPDVSReg = VSCTL_STCTL_RACCPDVSREG_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPDVSRegPrev = VSCTL_STCTL_RACCPDVSREGPREV_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPVSReg = VSCTL_STCTL_RACCPVSREG_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPVSRegPrev = VSCTL_STCTL_RACCPVSREGPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_rAccPTra = VSCTL_STCTL_RACCPTRA_ARRET;    /* Replaced by Post task */     /* Init from Model */
  *VSCtl_stGearCtlReq_swc_out = VSCTL_STGEARCTLREQ_NON_DEMANDE; /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_stgearctlreq_cpy = *VSCtl_stGearCtlReq_swc_out;

  vssp_vsctl_nogearreqmin_cpy = *VSCtl_noGearReqMin_swc_out;

  VSCtl_noGearMinTqPosFil = VSCTL_NOGEARMINTQPOSFIL_RAPPORT_DE_REPLI_BAS;   /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_noGearMin = VSCTL_STCTL_NOGEARMIN_ARRET;  /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_nogearreqmax_cpy = *VSCtl_noGearReqMax_swc_out;

  VSCtl_noGearMaxTqNegFil = VSCTL_NOGEARMAXTQNEGFIL_RAPPORT_DE_REPLI_HAUT;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_noGearMaxTqNegFilRaw = VSCTL_NOGEARMAXTQNEGFILRAW_RAPPORT_DE_REPLI_HAUT;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_noGearMaxTqPosFil = VSCTL_NOGEARMAXTQPOSFIL_RAPPORT_DE_REPLI_HAUT;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtl_noGearMax = VSCTL_STCTL_NOGEARMAX_ARRET;  /* Replaced by Post task */     /* Init from Model */
  *VSCtl_stCtl_noGear_swc_out = VSCTL_STCTL_NOGEAR_ARRET;   /* Replaced by Post task */     /* Init from Model */
  vssp_vsctl_stctl_nogear_cpy = *VSCtl_stCtl_noGear_swc_out;




  vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_DEFAUT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c359_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c359_VSSP_Det_Gearbox_Pedal_Sf = 0U;



  vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MAX = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c360_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c360_VSSP_Det_Gearbox_Pedal_Sf = 0U;



  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_o = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_a = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_DESCENDANT_i = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_f = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_e = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_m =
    0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_MONTANT_f = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_m = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_n = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_p =
    0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c361_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c361_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAuthSdwn_noGearMaxTqP =DDS_FALSE;
  VSCtl_bAuthSup_noGearMxTqPos =DDS_FALSE;
  vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqP_a = 0U;
  vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqP_d = 0U;



  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT1 = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT1 = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE_g = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT2 = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT2 = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MARCHE = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_DESCENDANT_l = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_b = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE_n = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME_d =
    0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_MONTANT_e = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_l = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE_l = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME_d =
    0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c362_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c362_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAuthSdwn_noGearMaxTqN =DDS_FALSE;
  VSCtl_bAuthSup_noGearMxTqNeg =DDS_FALSE;
  vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTqN_n = 0U;
  vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMaxTqN_j = 0U;
  vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMxTN2_b = 0U;



  vssp_det_gearbox_pedal_sf_dwork.is_MODE_COMMANDE_RAPPORT_MIN = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c363_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c363_VSSP_Det_Gearbox_Pedal_Sf = 0U;



  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_DESCENDANT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_MARCHE = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_DESCENDANT_NON_CONFIRME =
    0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_RAPPORT_MONTANT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_MARCHE = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_RAPPORT_MONTANT_NON_CONFIRME = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c364_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c364_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAuthSdwn_noGearMin =DDS_FALSE;
  VSCtl_bAuthSup_noGearMin =DDS_FALSE;
  vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSdwn_noGearMin_k = 0U;
  vssp_det_gearbox_pedal_sf_b.VSCtl_tiAuthSup_noGearMin_e = 0U;



  vssp_det_gearbox_pedal_sf_dwork.is_MODE_CONTROLE_RAPPORT = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_MARCHE = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c365_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c365_VSSP_Det_Gearbox_Pedal_Sf = 0U;





  vssp_det_gearbox_pedal_sf_dwork.is_VSSP_ENABLE_F722 = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c1_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c1_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vsctl_bacvf722 =DDS_FALSE;



  vssp_det_gearbox_pedal_sf_dwork.is_MODE_CALCUL_POSITION_PEDALE_ACCELERATEUR_TRANSMISSION
    = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c13_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c13_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAcvFil_rAccPTra =DDS_FALSE;


  vssp_det_gearbox_pedal_s_delay_0 = VSSP_DET_GEARBOX_PEDAL_S_CONST_0;


  vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_RVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_RVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_CONTROLE = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_RVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_RVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES_m = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c14_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c14_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAcvFil_rAccPMaxVSReg =DDS_FALSE;



  vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_ACC = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_ACC = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_ACC = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_ACC = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES_k = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c15_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c15_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAcvFil_rAccPMaxDVSReg =DDS_FALSE;



  vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_MAX_LVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_LVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_LVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_LVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES_l = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c16_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c16_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAcvFil_rAccPMaxVSLim =DDS_FALSE;



  vssp_det_gearbox_pedal_sf_dwork.is_active_ETAT_POSITION_PEDALE_MAX_BVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_ETAT_POSITION_PEDALE_MAX_BVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_FILTRAGE_POSITION_PEDALE_BVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_FILTRAGE_POSITION_PEDALE_BVV = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_MEMOIRES = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_active_c17_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  vssp_det_gearbox_pedal_sf_dwork.is_c17_VSSP_Det_Gearbox_Pedal_Sf = 0U;
  VSCtl_bAcvFil_rAccPMaxVSMax =DDS_FALSE;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

