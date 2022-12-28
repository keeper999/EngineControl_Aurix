/*
* File: VSREG_Det_Cond_Fct_Gmp_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSREG_Det_Cond_Fct_Gmp_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Thu Jan 05 12:12:17 2012
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Thu Jan 05 12:12:20 2012
*
* Post treatment done by tool Aut_Autocode_Post.pl version 11.78
*        with rules Aut_Rules_For_Autocode_Post.pm version 12.10
*        with stack reduction algorithm Aut_Stack_Analyzer.pm version 4.00
*
* Code generated from spec : R6512345_10
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
*
* Scripts versions:
*        aut_add_io version 3.0                                        aut_autocode_optimization version 9.0
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
*        aut_create_hyperlink_command_from_block version 3.0           aut_create_sstg_architecture version 10.0
*        aut_cross_check_T55_mdl_init version 4.0                      aut_find_source_block_path version 6.0
*        aut_fixed_point_toolbox_interface version 4.0                 aut_format_cpv_initialization_line version 10.0
*        aut_free_up_unexpected_block version 4.0                      aut_get_array_apv_according_calibration_mode version 5.0
*        aut_get_data_list_from_link_output_block version 3.0          aut_get_data_size version 3.0
*        aut_get_deeper_block_from_list version 3.0                    aut_get_evaluated_value_from_constant version 4.0
*        aut_get_final_datatype version 3.0                            aut_get_information_from_next_block version 16.0
*        aut_get_information_from_previous_block version 31.0          aut_get_key version 3.0
*        aut_get_sigtype_info version 3.0                              aut_get_snapshot_under_critical_lst_tag version 1.0
*        aut_get_squeduling_list version 16.0                          aut_get_src_handle_from_previous_block_and_port_index version 3.0
*        aut_get_static_data_list version 4.0                          aut_init_value_check version 4.0
*        aut_key_alg version 3.0                                       aut_manage_autocode_model version 15.0
*        aut_manage_compilation_mode version 4.0                       aut_manage_doc_block version 7.0
*        aut_manage_limiter version 11.0                               aut_manage_model_workspace version 3.0
*        aut_manage_simulink_to_post_task_exchange version 54.0        aut_manage_snapshot version 26.0
*        aut_mode_switch version 69.0                                  aut_model_autocode version 25.0
*        aut_model_configure version 7.0                               aut_pre_autocode version 56.0
*        aut_prepare_t55_task version 28.0                             aut_prepare_t55_task_for_tag version 9.0
*        aut_process_mngt version 58.0                                 aut_project_settings version 22.0
*        aut_signal_config version 13.0                                aut_sstg_manage_signal_memory_location version 6.0
*        aut_stateflow_checks version 6.0                              aut_step_ckecks version 4.0
*        aut_switch_cpv_initialization version 13.0                    aut_types version 3.0
*        aut_unset_set_block_properties_of_subsytem version 8.0        aut_update_init_file_with_tag version 4.0
*        sim_attributes_format_string version 4.0                      sim_check_unlinked_blocks version 11.0
*        sim_configure_simulation_mode version 9.0                     sim_display_dd_settings version 5.0
*        sim_format_hyperlink_message version 7.0                      sim_function_stub version 3.0
*        sim_get_autorisation_for_limitation version 1.0               sim_get_library_references version 48.0
*        sim_get_library_version version 3.0                           sim_get_static_data_block version 3.0
*        sim_load_libraries version 3.0                                sim_manage_block_tab version 6.0
*        sim_manage_config_set version 4.0                             sim_manage_link_status_warning version 3.0
*        sim_manage_structure_dd_display version 2.0                   sim_manage_structure_signals version 5.0
*        sim_maskinitialization_common_function version 4.0            sim_not_callback version 2.0
*        sim_prepare_limitation version 60.0                           sim_restore_previous_tag_version version 3.0
*        sim_set version 1.0                                           sim_set_ic version 1.0
*        sim_set_param version 3.0                                     sim_sf_get_param version 7.0
*        sim_switch_block_mode version 5.0                             sim_update_block_display_status version 20.0
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
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Det_Cond_Fct_Gmp_Sf.c
* Version int :/main/L03_01/2 Date: 6/1/2012 9 h 15 m User:esnault 
*    TWK_model:VSREG_Det_Cond_Fct_Gmp_Sf_L03_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\3 Date: 5/1/2012 12 h 32 m User:demezil 
*    TWK_model:VSREG_Det_Cond_Fct_Gmp_Sf_L03_010_IMPL1
*    comments :for VSReg 12.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Appui_Pedale_Embrayage */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Appui_Pedale_Embrayage ;Ext_bCluPedPrss;Ext_stGBxCf;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Appui_Pedale_Embrayage ;VSCtl_bCluPedPrssVSReg_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Appui_Pedale_Embrayage */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Changement_Rapport */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Changement_Rapport ;Ext_stGBxCf;VSCtl_bNbGearEgdChg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Changement_Rapport ;VSCtl_bNoGearEgdChgVSReg_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Changement_Rapport */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Controle_Rapport */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Controle_Rapport ;Ext_stGBxCf;VSCtl_stCtl_noGear;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Controle_Rapport ;VSCtl_bGearCtlVSReg_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Controle_Rapport */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Etat_Moteur */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Etat_Moteur ;CoPTSt_stEng;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Etat_Moteur ;VSCtl_bStEngVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Etat_Moteur */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Plage_Regime_GMP */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Plage_Regime_GMP ;VSCtl_stMonVSReg;VehEst_bORng_nPT; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Plage_Regime_GMP ;VSCtl_bORng_nTqVSReg_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Plage_Regime_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Max ;VSCtl_nEngFil;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Max ;VSCtl_bNEngMaxVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_1 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_1 ;VSCtl_nEngFil;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_1 ;VSCtl_bNEngMinVSReg_no1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_1 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_2 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_2 ;TqSys_nTarIdl;VSCtl_nEngFil;VSCtl_stMonVSReg;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_2 ;VSCtl_bNEngMinVSReg_no2;VSCtl_tiNEngMinVSReg_no2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Regime_Moteur_Min_2 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV ;CoPt_posnLev;Ext_bPosnGBxCf;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV ;VSCtl_bPosnGBxLevVSReg_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV1 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV1 ;CoPt_posnLev;Ext_bPosnGBxCf;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV1 ;VSCtl_bPosnGBxLevVSReg_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Conditions_Position_Levier_BV1 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Conditions_Rapport_BV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Conditions_Rapport_BV ;CoPt_noEgdGearCordIt;CoPt_noTarGearCordIt;Ext_stGBxCf;VSCtl_grdRatConvTra;VSCtl_rConvTra;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Conditions_Rapport_BV ;VSCtl_bNoGearVSReg_pt2;VSCtl_tiFilNoGearVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Conditions_Rapport_BV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_1 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_1 ;VSCtl_bFastDeacVSRegReq_pt1;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_1 ;VSCtl_bInhVSRegReq_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_1 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_2 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_2 ;VSCtl_bFastDeacVSRegReq_pt2;VSCtl_bGearCtlVSReg_pt2;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_2 ;VSCtl_bInhVSRegReq_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_GMP_2 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_1 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_1 ;VSCtl_bAvlTqWhlPTVSReg1_pt1;VSCtl_bAvlTqWhlPTVSReg2_pt1;VSCtl_bAvlTqWhlPTVSReg3_pt1;VSCtl_bDirMoveVehVSReg_pt1;VSCtl_bORng_nTqVSReg_pt1;VSCtl_bPosnGBxLevVSReg_pt1;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_1 ;VSCtl_bFastDeacVSRegReq_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_1 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_2 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_2 ;VSCtl_bAvlTqWhlPTVSReg1_pt2;VSCtl_bAvlTqWhlPTVSReg2_pt2;VSCtl_bAvlTqWhlPTVSReg3_pt2;VSCtl_bCluPedPrssVSReg_pt2;VSCtl_bNEngMaxVSReg;VSCtl_bNEngMinVSReg_no1;VSCtl_bNEngMinVSReg_no2;VSCtl_bNoGearEgdChgVSReg_pt2;VSCtl_bNoGearVSReg_pt2;VSCtl_bPosnGBxLevVSReg_pt2;VSCtl_bStEngVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_2 ;VSCtl_bFastDeacVSRegReq_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_GMP_2 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Disponibilite_Couple_Roue_GMP */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Disponibilite_Couple_Roue_GMP ;Ext_stGBxCf;VSCtl_bAvlTqWhlPT_no1;VSCtl_bAvlTqWhlPT_no2;VSCtl_bAvlTqWhlPT_no3;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Disponibilite_Couple_Roue_GMP ;VSCtl_bAvlTqWhlPTVSReg1_pt2;VSCtl_bAvlTqWhlPTVSReg2_pt2;VSCtl_bAvlTqWhlPTVSReg3_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Disponibilite_Couple_Roue_GMP */

/* TAG_START_OF_SUB_FUNCTION: F212115_Determiner_Conditions_Maintenance_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F212115_Determiner_Conditions_Maintenance_GMP ;VSCtl_bAvlTqWhlPTVSReg1_pt1;VSCtl_bAvlTqWhlPTVSReg2_pt1;VSCtl_bAvlTqWhlPTVSReg3_pt1;VSCtl_bDirMoveVehVSReg_pt1;VSCtl_bORng_nTqVSReg_pt1;VSCtl_bPosnGBxLevVSReg_pt1;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F212115_Determiner_Conditions_Maintenance_GMP ;VSCtl_stDeacVSRegReq_pt1; */
/* TAG_END_OF_SUB_FUNCTION: F212115_Determiner_Conditions_Maintenance_GMP */

/* TAG_START_OF_SUB_FUNCTION: F2121231_Determiner_Conditions_Maintenance_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F2121231_Determiner_Conditions_Maintenance_GMP ;VSCtl_bAvlTqWhlPTVSReg1_pt2;VSCtl_bAvlTqWhlPTVSReg2_pt2;VSCtl_bAvlTqWhlPTVSReg3_pt2;VSCtl_bCluPedPrssVSReg_pt2;VSCtl_bGearCtlVSReg_pt2;VSCtl_bNEngMaxVSReg;VSCtl_bNEngMinVSReg_no1;VSCtl_bNEngMinVSReg_no2;VSCtl_bNoGearEgdChgVSReg_pt2;VSCtl_bNoGearVSReg_pt2;VSCtl_bPosnGBxLevVSReg_pt2;VSCtl_bStEngVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2121231_Determiner_Conditions_Maintenance_GMP ;VSCtl_stDeacVSRegReq_pt2; */
/* TAG_END_OF_SUB_FUNCTION: F2121231_Determiner_Conditions_Maintenance_GMP */

/* TAG_START_OF_SUB_FUNCTION: F21213_Determiner_Conditions_Fonctionnement_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F21213_Determiner_Conditions_Fonctionnement_GMP ;VSCtl_bFastDeacVSRegReq_pt1;VSCtl_bFastDeacVSRegReq_pt2;VSCtl_bInhVSRegReq_pt1;VSCtl_bInhVSRegReq_pt2;VSCtl_stDeacVSRegReq_pt1;VSCtl_stDeacVSRegReq_pt2; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F21213_Determiner_Conditions_Fonctionnement_GMP ;VSCtl_bFastDeacVSRegReq_pt;VSCtl_bInhVSRegReq_pt;VSCtl_stDeacVSRegReq_pt; */
/* TAG_END_OF_SUB_FUNCTION: F21213_Determiner_Conditions_Fonctionnement_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule ; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule ;vsctl_bacv_calcul; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Sens_Deplacement_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Sens_Deplacement_Vehicule ;Ext_stDirMoveVeh;Ext_stDirMoveVehCf;Ext_stDirMoveVehReq;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Sens_Deplacement_Vehicule ;VSCtl_bDirMoveVehVSReg_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Sens_Deplacement_Vehicule */

/* END OF SSTG FUNCTION INTERFACE AREA */

/* <AUT_POST> : Task Include managment */
/********************************************************************/
/*  Include Files                                                   */
/********************************************************************/
#include "dds_lib.h"
#include "VSReg.h"
/* \<AUT_POST> : Task Include managment */

/********************************************************************/
/*  Task Macro Definitions                                          */
/********************************************************************/
#define EXT_STDIRMOVEVEHREQ_AVANT               (1)
#define EXT_STDIRMOVEVEHCF_PRESENT              (1)
#define EXT_STDIRMOVEVEH_AVANT                  (1)
#define EXT_BPOSNGBXCF_DISPONIBLE               (1)
#define COPTST_STENG_MOTEUR_TOURNANT            (5)
#define VSCTL_STCTL_NOGEAR_DEFAUT_38            (2)

/*VSCtl_stVSRegExtd */
#define VSCTL_STVSREGEXTD_ARRET                 (0)
#define VSCTL_STVSREGEXTD_INITIALISATION        (1)
#define VSCTL_STVSREGEXTD_INHIBEE               (2)
#define VSCTL_STVSREGEXTD_ATTENTE               (3)
#define VSCTL_STVSREGEXTD_ANE                   (4)
#define VSCTL_STVSREGEXTD_AE                    (5)
#define VSCTL_STVSREGEXTD_REPRISE               (6)
#define VSCTL_STVSREGEXTD_DEFAUT                (7)

/* Ext_stGBxCf */
#define EXT_STGBXCF_BVM                         (0)
#define EXT_STGBXCF_BVA                         (1)
#define EXT_STGBXCF_BVMP                        (2)


/* CoPt_posnLev */
#define COPT_POSNLEV_DRIVE                      (3)
#define COPT_POSNLEV_MODE_MANUEL                (6)

/* Named constants for block: /Mode_Commande_Potentiel_Acceleration_Vehicule' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_ENABLE (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_MOTEUR (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_ROUE (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_m (1U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_ee (0U)

/* Named constants for block: /Disponibilite_Couple_Roue_GMP' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DISPONIBILITE_COUPLE_ROUE_GMP_1 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI (1U)

/* Named constants for block: /Sens_Deplacement_Vehicule' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_SENS_DEPLACEMENT_VEHICULE (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_l (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_g (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_j (1U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_g (0U)

/* Named constants for block: /Condition_Plage_Regime_GMP' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_PLAGE_REGIME_GMP_1 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_h (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_m (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_p (1U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_o (0U)

/* Named constants for block: /Conditions_Position_Levier_BV1' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_a (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_c (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_POSITION_LEVIER_BV_GMP_1 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_e (1U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_d (0U)

/* Named constants for block: /Demandes_Desactivation_Rapide_GMP_1' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DESACTIVATION_RAPIDE_GMP_1 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr (1U)

/* Named constants for block: /Demandes_Desactivation_Inhibition_GMP_1' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_a (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_g (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDE_INHIBITION (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_a (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_l (1U)

/* Named constants for block: /Condition_Etat_Moteur' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_ETAT_MOTEUR (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_f (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_p (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pm (1U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_m (0U)

/* Named constants for block: /Condition_Regime_Moteur_Max' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_f (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_REGIME_MAX (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_b (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_k (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pq (1U)

/* Named constants for block: /Condition_Regime_Moteur_Min_1' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_REGIME_MIN_1 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_j (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_n (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_l (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_h (1U)

/* Named constants for block: /Condition_Regime_Moteur_Min_2' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_REGIME_MIN_2 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_INIT (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_NON_INIT (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_TEMPO (4)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_e (3)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONF (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DECONF (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_ll (5)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_MARCHE (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_e (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_a (1U)

/* Named constants for block: /Disponibilite_Couple_Roue_GMP' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_nz (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DISPONIBILITE_COUPLE_ROUE_GMP_2 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd (1U)

/* Named constants for block: /Appui_Pedale_Embrayage' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_eh (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_ge (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_APPUI_PEDALE_EMBRAYAGE (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_l3 (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_n (1U)

/* Named constants for block: /Conditions_Position_Levier_BV' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_POSITION_LEVIER_BV_GMP_2 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_bs (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_hc (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_f (1U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_l0 (0U)

/* Named constants for block: /Conditions_Rapport_BV' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD_f (0)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITIONS_RAPPORT_BV (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET_b (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_MARCHE_k (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_CONFIRME (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_NON_CONFIRME (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_c (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_NON_CONFIRME (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_g5 (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k (1U)

/* Named constants for block: /Condition_Changement_Rapport' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_cs (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_j (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CHANGEMENT_RAPPORT (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_c (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_o (1U)

/* Named constants for block: /Condition_Controle_Rapport' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_mt (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_fy (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONTROLE_RAPPORT (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_ot (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_kp (1U)

/* Named constants for block: /Demandes_Desactivation_Rapide_GMP_2' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_l (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DESACTIVATION_RAPIDE_GMP_2 (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_l (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn (1U)

/* Named constants for block: /Demandes_Desactivation_Inhibition_GMP_2' */
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_i (2)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_c (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDE_INHIBITION_f (1)
#define VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_f (0U)
#define VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_i (1U)

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSReg;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bStEngVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bPosnGBxLevVSReg_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bPosnGBxLevVSReg_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bORng_nTqVSReg_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bNoGearVSReg_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bNoGearEgdChgVSReg_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bNEngMinVSReg_no2;
VAR(UInt8, AUTOMATIC) VSCtl_bNEngMinVSReg_no1;
VAR(UInt8, AUTOMATIC) VSCtl_bNEngMaxVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bGearCtlVSReg_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bDirMoveVehVSReg_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bCluPedPrssVSReg_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg3_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg3_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg2_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg2_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg1_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg1_pt1;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt32 is_NON_INIT : 3;
  UInt32 is_ENABLE : 2;
  UInt32 is_DEMANDE_INHIBITION : 2;
  UInt32 is_DESACTIVATION_RAPIDE_GMP_2 : 2;
  UInt32 is_CONTROLE_RAPPORT : 2;
  UInt32 is_CHANGEMENT_RAPPORT : 2;
  UInt32 is_CONDITIONS_RAPPORT_BV : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_NON_CONFIRME : 2;
  UInt32 is_CONDITION_POSITION_LEVIER_BV_GMP_2 : 2;
  UInt32 is_APPUI_PEDALE_EMBRAYAGE : 2;
  UInt32 is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 : 2;
  UInt32 is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 : 2;
  UInt32 is_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 : 2;
  UInt32 is_CONDITION_REGIME_MIN_2 : 2;
  UInt32 is_MARCHE_f : 2;
  UInt32 is_CONDITION_REGIME_MIN_1 : 2;
  UInt32 is_CONDITION_REGIME_MAX : 2;
  UInt32 is_CONDITION_ETAT_MOTEUR : 2;
  UInt32 is_DEMANDE_INHIBITION_f : 2;
  UInt32 is_DESACTIVATION_RAPIDE_GMP_1 : 2;
  UInt32 is_CONDITION_POSITION_LEVIER_BV_GMP_1 : 2;
  UInt32 is_CONDITION_PLAGE_REGIME_GMP_1 : 2;
  UInt32 is_SENS_DEPLACEMENT_VEHICULE : 2;
  UInt32 is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_c : 2;
  UInt32 is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_h : 2;
  UInt32 is_active_c1_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c1_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c51_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c51_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c50_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c50_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c49_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c49_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c48_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c48_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c47_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c47_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c46_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c46_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c45_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c45_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c44_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c44_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 : 1;
  UInt32 is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 : 1;
  UInt32 is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 : 1;
  UInt32 is_active_c43_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c43_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c42_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c42_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c41_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c41_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c40_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c40_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c39_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c39_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c38_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c38_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c2_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c2_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c36_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c36_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c35_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c35_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_c34_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_c34_VSREG_Det_Cond_Fct_Gmp_Sf : 1;
  UInt32 is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_h : 1;
  UInt32 is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_n : 1;
} D_Work_VSREG_Det_Cond_Fct_Gmp_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFilNoGearVSReg;                 /*BIN0*/
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"


/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiNEngMinVSReg_no2;                /*BIN0*/
/* Static Visible area end */
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* UNSPECIFIED-bits variable definition */
#define VSREG_START_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"
STATIC VAR(D_Work_VSREG_Det_Cond_Fct_Gmp_Sf, AUTOMATIC) vsreg_det_cond_fct_gmp_sf_dwork;
#define VSREG_STOP_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"


/* 8BIT-bits variable definition */
#define VSREG_START_SEC_VAR_8BIT
#include "VSReg_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bacv_calcul;
/* Static Not Visible area end */
#define VSREG_STOP_SEC_VAR_8BIT
#include "VSReg_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 32BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_32BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_nEngErrVSreg_HysHi_C = (CONST(SInt32, AUTOMATIC))(8960);  /*BIN7*/
STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_nEngErrVSreg_HysLo_C = (CONST(SInt32, AUTOMATIC))(-6400); /*BIN7*/
_DDS_STATIC_ volatile CONST(UInt32, AUTOMATIC) VSCtl_nEngMaxVSReg_HysHi_C = (CONST(UInt32, AUTOMATIC))(704000U); /*BIN7*/
_DDS_STATIC_ volatile CONST(UInt32, AUTOMATIC) VSCtl_nEngMaxVSReg_HysLo_C = (CONST(UInt32, AUTOMATIC))(697600U); /*BIN7*/
_DDS_STATIC_ volatile CONST(UInt32, AUTOMATIC) VSCtl_nEngMin1VSReg_HysHi_C = (CONST(UInt32, AUTOMATIC))(96000U); /*BIN7*/
_DDS_STATIC_ volatile CONST(UInt32, AUTOMATIC) VSCtl_nEngMin1VSReg_HysLo_C = (CONST(UInt32, AUTOMATIC))(89600U); /*BIN7*/
#define VSREG_STOP_SEC_CALIB_32BIT
#include "VSReg_MemMap.h"


/* 16BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_grdRatConvTraHiVSReg_C = (CONST(SInt16, AUTOMATIC))(10);  /*BIN1*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_grdRatConvTraLoVSReg_C = (CONST(SInt16, AUTOMATIC))(4);   /*BIN1*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraHiVSReg_C = (CONST(UInt16, AUTOMATIC))(2560U);    /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraLoVSReg_C = (CONST(UInt16, AUTOMATIC))(2304U);    /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilNoGearVSReg_C = (CONST(UInt16, AUTOMATIC))(30U);     /*BIN0*/
#define VSREG_STOP_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"


/* 8BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noAMTGearMaxVSReg_C = (CONST(UInt8, AUTOMATIC))(6U);      /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noAMTGearMinVSReg_C = (CONST(UInt8, AUTOMATIC))(2U);      /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noATGearMaxVSReg_C = (CONST(UInt8, AUTOMATIC))(6U);       /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noATGearMinVSReg_C = (CONST(UInt8, AUTOMATIC))(2U);       /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noMTGearMaxVSReg_C = (CONST(UInt8, AUTOMATIC))(6U);       /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noMTGearMinVSReg_C = (CONST(UInt8, AUTOMATIC))(4U);       /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiAcv_nEngMin2VSReg_C = (CONST(UInt8, AUTOMATIC))(65U);   /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiCfm_nEngMin2VSReg_C = (CONST(UInt8, AUTOMATIC))(1U);    /*DEC0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDiCfm_nEngMin2VSReg_C = (CONST(UInt8, AUTOMATIC))(1U);  /*DEC0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiTol_nEngMin2VSReg_C = (CONST(UInt8, AUTOMATIC))(10U);   /*BIN0*/
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacORng_nTqVSReg_pt1_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacbNoGVSRegrConvTra_C = DDS_TRUE;
/* \<AUT_POST> : Task Memory Ordering */
#define VSREG_STOP_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"

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

#define VSREG_START_SEC_CODE
#include "VSReg_MemMap.h"

FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Gmp_Sf(UInt8 Ext_stGBxCf_swc_in,
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                   /*BIN0*/
                               SInt16 VSCtl_grdRatConvTra_swc_in,                   /*BIN1*/
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               UInt32 VSCtl_nEngFil_swc_in,                         /*BIN0*/
                               UInt8 VSCtl_stCtl_noGear_swc_in,
                               UInt8 Ext_stDirMoveVeh_swc_in,
                               UInt16 TqSys_nTarIdl_swc_in,                         /*BIN2*/
                               UInt8 VSCtl_bAvlTqWhlPT_no1_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no2_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               UInt8 VehEst_bORng_nPT_swc_in,
                               UInt8 Ext_bCluPedPrss_swc_in,
                               UInt8 Ext_stDirMoveVehReq_swc_in,
                               UInt8 Ext_stDirMoveVehCf_swc_in,
                               UInt16 VSCtl_rConvTra_swc_in,                        /*BIN7*/
                               UInt8 CoPt_posnLev_swc_in,
                               UInt8 Ext_bPosnGBxCf_swc_in,
                               UInt8 CoPTSt_stEng_swc_in,
                               SInt8 CoPt_noTarGearCordIt_swc_in,                   /*BIN0*/
                               UInt8 VSCtl_bNbGearEgdChg_swc_in)

{

  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F21214_choisir_fonctionnement_gmp1_gmp2*/

  if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c1_VSREG_Det_Cond_Fct_Gmp_Sf ==
      0)
  {
    vsreg_det_cond_fct_gmp_sf_dwork.is_active_c1_VSREG_Det_Cond_Fct_Gmp_Sf = 1U;
    vsreg_det_cond_fct_gmp_sf_dwork.is_c1_VSREG_Det_Cond_Fct_Gmp_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Gmp_Sf_IN_ENABLE;
    vsreg_det_cond_fct_gmp_sf_dwork.is_ENABLE = (UInt8)
      VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_MOTEUR;
    vsctl_bacv_calcul = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_ee;

  }
  else
  {
    switch (vsreg_det_cond_fct_gmp_sf_dwork.is_ENABLE) {
     case VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_MOTEUR:
      if (VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
      {
        vsreg_det_cond_fct_gmp_sf_dwork.is_ENABLE = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_ROUE;
        vsctl_bacv_calcul = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_m;
      }
      break;

     case VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_ROUE:
      if (VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
      {
        vsreg_det_cond_fct_gmp_sf_dwork.is_ENABLE = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_MOTEUR;
        vsctl_bacv_calcul = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_ee;
      }
      break;

     default:
      vsreg_det_cond_fct_gmp_sf_dwork.is_ENABLE = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_COUPLE_MOTEUR;
      vsctl_bacv_calcul = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_ee;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21214_choisir_fonctionnement_gmp1_gmp2*/


  if (DDS_TRUE==vsctl_bacv_calcul)
  {

    /* TAG_START_OF_STATEFLOW_FUNCTION: F212111_Determiner_Disponibilites_Couple_Roue_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.07.2  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c34_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c34_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c34_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DISPONIBILITE_COUPLE_ROUE_GMP_1;
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_h
        = 1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_c =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI;
      VSCtl_bAvlTqWhlPTVSReg1_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_n
        = 1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_h =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI;
      VSCtl_bAvlTqWhlPTVSReg2_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
      VSCtl_bAvlTqWhlPTVSReg3_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;

    }
    else
    {
      switch
        (vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_c)
      {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
            (VSCtl_bAvlTqWhlPT_no1_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_c
            = (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI;
          VSCtl_bAvlTqWhlPTVSReg1_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
            (VSCtl_bAvlTqWhlPT_no1_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_c
            = (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX;
          VSCtl_bAvlTqWhlPTVSReg1_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_c =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI;
        VSCtl_bAvlTqWhlPTVSReg1_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
        break;
      }

      switch
        (vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_h)
      {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
            (VSCtl_bAvlTqWhlPT_no2_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_h
            = (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI;
          VSCtl_bAvlTqWhlPTVSReg2_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
          VSCtl_bAvlTqWhlPTVSReg3_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
            (VSCtl_bAvlTqWhlPT_no2_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_h
            = (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX;
          VSCtl_bAvlTqWhlPTVSReg2_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX;
          VSCtl_bAvlTqWhlPTVSReg3_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_h =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI;
        VSCtl_bAvlTqWhlPTVSReg2_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
        VSCtl_bAvlTqWhlPTVSReg3_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F212111_Determiner_Disponibilites_Couple_Roue_GMP*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F212112_Determiner_Condition_Sens_Deplacement_Vehicule*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.78.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c35_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c35_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c35_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_SENS_DEPLACEMENT_VEHICULE;
      vsreg_det_cond_fct_gmp_sf_dwork.is_SENS_DEPLACEMENT_VEHICULE = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_l;
      VSCtl_bDirMoveVehVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_j;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_SENS_DEPLACEMENT_VEHICULE)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_g:
        if ((((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        ||
              (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
             (Ext_stDirMoveVehReq_swc_in != EXT_STDIRMOVEVEHREQ_AVANT)) ||
            ((Ext_stDirMoveVehCf_swc_in == EXT_STDIRMOVEVEHCF_PRESENT) &&
             (Ext_stDirMoveVeh_swc_in != EXT_STDIRMOVEVEH_AVANT)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_SENS_DEPLACEMENT_VEHICULE =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_l;
          VSCtl_bDirMoveVehVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_j;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_l:
        if ((((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        &&
              (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
             (Ext_stDirMoveVehReq_swc_in == EXT_STDIRMOVEVEHREQ_AVANT)) &&
            ((Ext_stDirMoveVehCf_swc_in != EXT_STDIRMOVEVEHCF_PRESENT) ||
             (Ext_stDirMoveVeh_swc_in == EXT_STDIRMOVEVEH_AVANT)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_SENS_DEPLACEMENT_VEHICULE =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_g;
          VSCtl_bDirMoveVehVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_g;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_SENS_DEPLACEMENT_VEHICULE = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_l;
        VSCtl_bDirMoveVehVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_j;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F212112_Determiner_Condition_Sens_Deplacement_Vehicule*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F212113_Determiner_Condition_Plage_Regime_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.79.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c36_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c36_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c36_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_PLAGE_REGIME_GMP_1;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_PLAGE_REGIME_GMP_1 = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_m;
      VSCtl_bORng_nTqVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_p;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_PLAGE_REGIME_GMP_1)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_h:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
            ((VehEst_bORng_nPT_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_p)
            &&
             (VSCtl_bDeacORng_nTqVSReg_pt1_C == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_o)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_PLAGE_REGIME_GMP_1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_m;
          VSCtl_bORng_nTqVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_p;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_m:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
            ((VehEst_bORng_nPT_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_o)
            ||
             (VSCtl_bDeacORng_nTqVSReg_pt1_C == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_p)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_PLAGE_REGIME_GMP_1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_h;
          VSCtl_bORng_nTqVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_o;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_PLAGE_REGIME_GMP_1 =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_m;
        VSCtl_bORng_nTqVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_p;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F212113_Determiner_Condition_Plage_Regime_GMP*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F212114_Determiner_Conditions_Position_Levier_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.80.1  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c2_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c2_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c2_VSREG_Det_Cond_Fct_Gmp_Sf = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_POSITION_LEVIER_BV_GMP_1;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_1 =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_a;
      VSCtl_bPosnGBxLevVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_e;

    }
    else
    {
      switch
        (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_1)
  {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_c:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
            (((Ext_bPosnGBxCf_swc_in == EXT_BPOSNGBXCF_DISPONIBLE)
            && (CoPt_posnLev_swc_in !=
               COPT_POSNLEV_DRIVE))
               && (CoPt_posnLev_swc_in != COPT_POSNLEV_MODE_MANUEL)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_a;
          VSCtl_bPosnGBxLevVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_e;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_a:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
             && ((Ext_bPosnGBxCf_swc_in
              == EXT_BPOSNGBXCF_DISPONIBLE) && (((CoPt_posnLev_swc_in ==
                COPT_POSNLEV_DRIVE)
                || (CoPt_posnLev_swc_in == COPT_POSNLEV_MODE_MANUEL))
              || (Ext_bPosnGBxCf_swc_in != EXT_BPOSNGBXCF_DISPONIBLE))))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_c;
          VSCtl_bPosnGBxLevVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_d;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_1 =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_a;
        VSCtl_bPosnGBxLevVSReg_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_e;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F212114_Determiner_Conditions_Position_Levier_GMP*/

    VSREG_F212115_Determiner_Conditions_Maintenance_Gmp();

    /* TAG_START_OF_STATEFLOW_FUNCTION: F212116_Determiner_Demande_Desactivation_Rapide_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.82.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c38_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c38_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c38_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DESACTIVATION_RAPIDE_GMP_1;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_1 = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE;
      VSCtl_bFastDeacVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_1)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE:
        if (((((((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
                 (VSCtl_bAvlTqWhlPTVSReg1_pt1 ==
                  VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n)) &&
                (VSCtl_bAvlTqWhlPTVSReg2_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n))
               && (VSCtl_bAvlTqWhlPTVSReg3_pt1 ==
                   VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n)) &&
              (VSCtl_bORng_nTqVSReg_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n))
              &&
             (VSCtl_bDirMoveVehVSReg_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n))
             &&
            (VSCtl_bPosnGBxLevVSReg_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE;
          VSCtl_bFastDeacVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_n;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE:
        if (((((((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
                 (VSCtl_bAvlTqWhlPTVSReg1_pt1 ==
                  VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr)) ||
                (VSCtl_bAvlTqWhlPTVSReg2_pt1 ==
                 VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr)) ||
               (VSCtl_bAvlTqWhlPTVSReg3_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr))

              || (VSCtl_bORng_nTqVSReg_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr))

             || (VSCtl_bDirMoveVehVSReg_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr))

            || (VSCtl_bPosnGBxLevVSReg_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE;
          VSCtl_bFastDeacVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_1 = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE;
        VSCtl_bFastDeacVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jr;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F212116_Determiner_Demande_Desactivation_Rapide_GMP*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F212117_Determiner_Demande_Inhibition_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.83.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c39_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c39_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c39_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDE_INHIBITION;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION_f = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_g;
      VSCtl_bInhVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_l;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION_f)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_g:
        if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
            (VSCtl_bFastDeacVSRegReq_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_a))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION_f = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_a;
          VSCtl_bInhVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_a;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_a:
        if ((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
            (VSCtl_bFastDeacVSRegReq_pt1 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_l))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION_f = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_g;
          VSCtl_bInhVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_l;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION_f = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_g;
        VSCtl_bInhVSRegReq_pt1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_l;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F212117_Determiner_Demande_Inhibition_GMP*/

  }


  if (DDS_FALSE==vsctl_bacv_calcul)
  {

    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121211_Determiner_Condition_Etat_Moteur*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.13.3  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c40_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c40_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c40_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_ETAT_MOTEUR;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_ETAT_MOTEUR = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_f;
      VSCtl_bStEngVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pm;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_ETAT_MOTEUR)
  {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_p:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
             || (CoPTSt_stEng_swc_in !=
             COPTST_STENG_MOTEUR_TOURNANT))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_ETAT_MOTEUR = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_f;
          VSCtl_bStEngVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pm;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_f:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
             && (CoPTSt_stEng_swc_in ==
             COPTST_STENG_MOTEUR_TOURNANT))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_ETAT_MOTEUR = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_p;
          VSCtl_bStEngVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_m;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_ETAT_MOTEUR = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_f;
        VSCtl_bStEngVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pm;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121211_Determiner_Condition_Etat_Moteur*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F21212121_Determiner_Condition_Regime_Moteur_Max*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.15.3  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c41_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c41_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c41_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_REGIME_MAX;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MAX = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_b;
      VSCtl_bNEngMaxVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pq;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MAX)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_f:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
             || (VSCtl_nEngFil_swc_in >=
             (VSCtl_nEngMaxVSReg_HysHi_C >> 7)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MAX = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_b;
          VSCtl_bNEngMaxVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pq;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_b:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
             && (VSCtl_nEngFil_swc_in <
             (VSCtl_nEngMaxVSReg_HysLo_C >> 7)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MAX = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_f;
          VSCtl_bNEngMaxVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_k;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MAX = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_b;
        VSCtl_bNEngMaxVSReg = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pq;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F21212121_Determiner_Condition_Regime_Moteur_Max*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F21212122_Determiner_Condition_Regime_Moteur_Min_1*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.16.3  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c42_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c42_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c42_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_REGIME_MIN_1;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_1 = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_j;
      VSCtl_bNEngMinVSReg_no1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_h;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_1)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_n:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
             || (VSCtl_nEngFil_swc_in <=
             (VSCtl_nEngMin1VSReg_HysLo_C >> 7)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_1 = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_j;
          VSCtl_bNEngMinVSReg_no1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_h;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_j:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
             && (VSCtl_nEngFil_swc_in >
             (VSCtl_nEngMin1VSReg_HysHi_C >> 7)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_1 = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_n;
          VSCtl_bNEngMinVSReg_no1 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_l;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_1 = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_j;
        VSCtl_bNEngMinVSReg_no1 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_h;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F21212122_Determiner_Condition_Regime_Moteur_Min_1*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F21212123_Determiner_Condition_Regime_Moteur_Min_2*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.17.3  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c43_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c43_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c43_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_REGIME_MIN_2;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_2 = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET;
      VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_a;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_2)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET:
        if ((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
            (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_2 = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_MARCHE;
          vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE_f = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_INIT;
          VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_e;
          VSCtl_tiNEngMinVSReg_no2 = VSCtl_tiAcv_nEngMin2VSReg_C;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_MARCHE:
        if ((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
            (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE_f = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD;
          vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD;
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_2 = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET;
          VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_a;

        }
        else
        {
          switch (vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE_f)
        {
           case VSREG_Det_Cond_Fct_Gmp_Sf_IN_INIT:
            if (((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE) ||
                 (VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_ANE)) ||
                (VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE))
            {
              vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE_f = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_NON_INIT;
              vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_TEMPO;
            }
            break;

           case VSREG_Det_Cond_Fct_Gmp_Sf_IN_NON_INIT:
            if (((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE) &&
                 (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_ANE)) &&
                (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE))
            {
              vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD;
              vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE_f = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_INIT;
              VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_e;
              VSCtl_tiNEngMinVSReg_no2 = VSCtl_tiAcv_nEngMin2VSReg_C;

            }
            else
            {
              switch (vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT)
            {
               case VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONF:
                if ((VSCtl_nEngFil_swc_in >= ((UInt32)(((TqSys_nTarIdl_swc_in << 5) +
                        VSCtl_nEngErrVSreg_HysHi_C) >> 7))) &&
                    (VSCtl_tiNEngMinVSReg_no2 != 0))
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_DECONF;

                }
                else if (VSCtl_tiNEngMinVSReg_no2 == 0)
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_ll;
                  VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_a;

                }
                else
                {
                  VSCtl_tiNEngMinVSReg_no2 = (UInt8)DDS_M_MAX
                    (VSCtl_tiNEngMinVSReg_no2 - VSCtl_tiCfm_nEngMin2VSReg_C, 0);
                }
                break;

               case VSREG_Det_Cond_Fct_Gmp_Sf_IN_DECONF:
                if ((VSCtl_nEngFil_swc_in >= ((UInt32)(((TqSys_nTarIdl_swc_in << 5) +
                        VSCtl_nEngErrVSreg_HysHi_C) >> 7))) &&
                    (VSCtl_tiNEngMinVSReg_no2 == VSCtl_tiTol_nEngMin2VSReg_C))
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_e;
                  VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_e;
                  VSCtl_tiNEngMinVSReg_no2 = VSCtl_tiTol_nEngMin2VSReg_C;

                }
                else if (VSCtl_nEngFil_swc_in < ((UInt32)(((TqSys_nTarIdl_swc_in << 5) +
                              VSCtl_nEngErrVSreg_HysLo_C) >> 7)))
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONF;

                }
                else
                {
                  VSCtl_tiNEngMinVSReg_no2 = (UInt8)((VSCtl_tiNEngMinVSReg_no2
                    + VSCtl_tiDiCfm_nEngMin2VSReg_C) <
                    VSCtl_tiTol_nEngMin2VSReg_C ? VSCtl_tiNEngMinVSReg_no2 +
                    VSCtl_tiDiCfm_nEngMin2VSReg_C : (SInt32)
                    VSCtl_tiTol_nEngMin2VSReg_C);
                }
                break;

               case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_e:
                if (VSCtl_nEngFil_swc_in < ((UInt32)(((TqSys_nTarIdl_swc_in << 5) +
                       VSCtl_nEngErrVSreg_HysLo_C) >> 7)))
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONF;
                }
                break;

               case VSREG_Det_Cond_Fct_Gmp_Sf_IN_TEMPO:
                if (VSCtl_tiNEngMinVSReg_no2 == 0)
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_e;
                  VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_e;
                  VSCtl_tiNEngMinVSReg_no2 = VSCtl_tiTol_nEngMin2VSReg_C;

                }
                else
                {
                  VSCtl_tiNEngMinVSReg_no2 = (UInt8)DDS_M_MAX
                    (VSCtl_tiNEngMinVSReg_no2 - 1, 0);
                }
                break;
              }
            }
            break;
          }
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_2 = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET;
        VSCtl_bNEngMinVSReg_no2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_a;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F21212123_Determiner_Condition_Regime_Moteur_Min_2*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121221_Determiner_Conditions_Disponibilite_Couple_Roue_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.84.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c44_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c44_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c44_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DISPONIBILITE_COUPLE_ROUE_GMP_2;
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO1
        = 1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
      VSCtl_bAvlTqWhlPTVSReg1_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO2
        = 1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
      VSCtl_bAvlTqWhlPTVSReg2_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO3
        = 1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
      VSCtl_bAvlTqWhlPTVSReg3_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;

    }
    else
    {
      switch
        (vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1)
                {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_nz:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
            (VSCtl_bAvlTqWhlPT_no1_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
          VSCtl_bAvlTqWhlPTVSReg1_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
            (VSCtl_bAvlTqWhlPT_no1_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_nz;
          VSCtl_bAvlTqWhlPTVSReg1_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
        VSCtl_bAvlTqWhlPTVSReg1_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
        break;
      }

      switch
        (vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_nz:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
            (VSCtl_bAvlTqWhlPT_no2_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
          VSCtl_bAvlTqWhlPTVSReg2_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
            (VSCtl_bAvlTqWhlPT_no2_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_nz;
          VSCtl_bAvlTqWhlPTVSReg2_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
        VSCtl_bAvlTqWhlPTVSReg2_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
        break;
      }

      switch
        (vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO3)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_nz:
        if ((((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
              (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
             (VSCtl_bAvlTqWhlPT_no2_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i))
             ||
            ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)
            && (VSCtl_bAvlTqWhlPT_no3_swc_in ==
              VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
          VSCtl_bAvlTqWhlPTVSReg3_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e:
        if ((((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
              (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
             (VSCtl_bAvlTqWhlPT_no2_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd))
             &&
            (((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)
            && (VSCtl_bAvlTqWhlPT_no3_swc_in ==
               VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd)) || (Ext_stGBxCf_swc_in !=
              EXT_STGBXCF_BVM)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_nz;
          VSCtl_bAvlTqWhlPTVSReg3_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_i;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_e;
        VSCtl_bAvlTqWhlPTVSReg3_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_jd;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121221_Determiner_Conditions_Disponibilite_Couple_Roue_GMP*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121222_Determiner_Condition_Appui_Pedale_Embrayage*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.85.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c45_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c45_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c45_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_APPUI_PEDALE_EMBRAYAGE;
      vsreg_det_cond_fct_gmp_sf_dwork.is_APPUI_PEDALE_EMBRAYAGE = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_eh;
      VSCtl_bCluPedPrssVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_n;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_APPUI_PEDALE_EMBRAYAGE)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_ge:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
             || ((Ext_stGBxCf_swc_in ==
              EXT_STGBXCF_BVM) && (Ext_bCluPedPrss_swc_in ==
              VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_n)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_APPUI_PEDALE_EMBRAYAGE = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_eh;
          VSCtl_bCluPedPrssVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_n;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_eh:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
             && ((Ext_stGBxCf_swc_in !=
              EXT_STGBXCF_BVM)
              || ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)
              &&
              (Ext_bCluPedPrss_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_l3))))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_APPUI_PEDALE_EMBRAYAGE = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_ge;
          VSCtl_bCluPedPrssVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_l3;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_APPUI_PEDALE_EMBRAYAGE = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_eh;
        VSCtl_bCluPedPrssVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_n;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121222_Determiner_Condition_Appui_Pedale_Embrayage*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121223_Determiner_Conditions_Position_Levier_BV*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.20.4  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c46_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c46_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c46_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITION_POSITION_LEVIER_BV_GMP_2;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_2 =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_bs;
      VSCtl_bPosnGBxLevVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_f;

    }
    else
    {
      switch
        (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_2)
  {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_hc:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)) ||
            (((Ext_bPosnGBxCf_swc_in == EXT_BPOSNGBXCF_DISPONIBLE)
            && (CoPt_posnLev_swc_in !=
               COPT_POSNLEV_DRIVE))
               && (CoPt_posnLev_swc_in != COPT_POSNLEV_MODE_MANUEL)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_2 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_bs;
          VSCtl_bPosnGBxLevVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_f;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_bs:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)) &&
            (((Ext_bPosnGBxCf_swc_in == EXT_BPOSNGBXCF_DISPONIBLE)
            && ((CoPt_posnLev_swc_in ==
                COPT_POSNLEV_DRIVE)
                || (CoPt_posnLev_swc_in == COPT_POSNLEV_MODE_MANUEL)))
             || (Ext_bPosnGBxCf_swc_in != EXT_BPOSNGBXCF_DISPONIBLE)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_2 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_hc;
          VSCtl_bPosnGBxLevVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_l0;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_2 =
          (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_bs;
        VSCtl_bPosnGBxLevVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_f;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121223_Determiner_Conditions_Position_Levier_BV*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121224_Determiner_Conditions_Plage_Rapport_BV*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.86.1  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c47_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c47_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c47_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONDITIONS_RAPPORT_BV;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITIONS_RAPPORT_BV = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET_b;
      VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k;
      VSCtl_tiFilNoGearVSReg = VSCtl_tiFilNoGearVSReg_C;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITIONS_RAPPORT_BV)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET_b:
        if ((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
            (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITIONS_RAPPORT_BV = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_MARCHE_k;
          vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_NON_CONFIRME;
          vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_c;
          VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_MARCHE_k:
        if ((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
            (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD_f;
          vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD_f;
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITIONS_RAPPORT_BV = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET_b;
          VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k;
          VSCtl_tiFilNoGearVSReg = VSCtl_tiFilNoGearVSReg_C;

        }
        else
        {
          switch (vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE)
        {
           case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_CONFIRME:
            if ((((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)
            && ((CoPt_noEgdGearCordIt_swc_in <
                    VSCtl_noMTGearMinVSReg_C)
                    || (CoPt_noEgdGearCordIt_swc_in >
                    VSCtl_noMTGearMaxVSReg_C))) || ((Ext_stGBxCf_swc_in ==
                   EXT_STGBXCF_BVA) && ((CoPt_noTarGearCordIt_swc_in <
                    VSCtl_noATGearMinVSReg_C)
                    || (CoPt_noTarGearCordIt_swc_in >
                    VSCtl_noATGearMaxVSReg_C)))) || ((Ext_stGBxCf_swc_in ==
                  EXT_STGBXCF_BVMP) && ((CoPt_noTarGearCordIt_swc_in <
                   VSCtl_noAMTGearMinVSReg_C)
                   || (CoPt_noTarGearCordIt_swc_in >
                   VSCtl_noAMTGearMaxVSReg_C))))
            {
              vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_NON_CONFIRME;
              vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_c;
              VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k;
            }
            break;

           case VSREG_Det_Cond_Fct_Gmp_Sf_IN_NON_CONFIRME:
            if (((((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)
            && (CoPt_noEgdGearCordIt_swc_in >=
                    VSCtl_noMTGearMinVSReg_C))
                    && (CoPt_noEgdGearCordIt_swc_in <=
                   VSCtl_noMTGearMaxVSReg_C)) || (((Ext_stGBxCf_swc_in ==
                    EXT_STGBXCF_BVA) && (CoPt_noTarGearCordIt_swc_in >=
                    VSCtl_noATGearMinVSReg_C))
                    && (CoPt_noTarGearCordIt_swc_in <=
                   VSCtl_noATGearMaxVSReg_C))) || (((Ext_stGBxCf_swc_in ==
                   EXT_STGBXCF_BVMP) && (CoPt_noTarGearCordIt_swc_in >=
                   VSCtl_noAMTGearMinVSReg_C))
                   && (CoPt_noTarGearCordIt_swc_in <=
                  VSCtl_noAMTGearMaxVSReg_C)))
            {
              vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_NO_ACTIVE_CHILD_f;
              vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE = (UInt8)
                VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_CONFIRME;
              VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_g5;
              VSCtl_tiFilNoGearVSReg = VSCtl_tiFilNoGearVSReg_C;

            }
            else
            {
              switch (vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME)
            {
               case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_NON_CONFIRME:
                if (((((Ext_stGBxCf_swc_in != EXT_STGBXCF_BVM) ||
                       (VSCtl_bDeacbNoGVSRegrConvTra_C ==
                        VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k))
                        || (VSCtl_rConvTra_swc_in >
                       VSCtl_rConvTraHiVSReg_C))
                       || (VSCtl_grdRatConvTra_swc_in >
                      VSCtl_grdRatConvTraHiVSReg_C))
                      || (VSCtl_tiFilNoGearVSReg ==
                     0))
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_c;
                  VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k;

                }
                else
                {
                  VSCtl_tiFilNoGearVSReg = (UInt16)DDS_M_MAX
                    (VSCtl_tiFilNoGearVSReg - 1, 0);
                }
                break;

               case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_c:
                if (((((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM) &&
                       (VSCtl_bDeacbNoGVSRegrConvTra_C ==
                        VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_g5))
                        && (VSCtl_rConvTra_swc_in <
                       VSCtl_rConvTraLoVSReg_C))
                       && (VSCtl_grdRatConvTra_swc_in <
                      VSCtl_grdRatConvTraLoVSReg_C))
                      && (VSCtl_tiFilNoGearVSReg
                     != 0))
                {
                  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME = (UInt8)
                    VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_NON_CONFIRME;
                  VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_g5;
                }
                break;
              }
            }
            break;
          }
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITIONS_RAPPORT_BV = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_ARRET_b;
        VSCtl_bNoGearVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_k;
        VSCtl_tiFilNoGearVSReg = VSCtl_tiFilNoGearVSReg_C;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121224_Determiner_Conditions_Plage_Rapport_BV*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121225_Determiner_Condition_Changement_Rapport*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.87.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c48_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c48_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c48_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CHANGEMENT_RAPPORT;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_cs;
      VSCtl_bNoGearEgdChgVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_o;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CHANGEMENT_RAPPORT)
                {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_j:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
             || ((Ext_stGBxCf_swc_in ==
              EXT_STGBXCF_BVM) && (VSCtl_bNbGearEgdChg_swc_in ==
              VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_o)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_cs;
          VSCtl_bNoGearEgdChgVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_o;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_cs:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
             && ((Ext_stGBxCf_swc_in !=
              EXT_STGBXCF_BVM)
              || ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)
              &&
              (VSCtl_bNbGearEgdChg_swc_in == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_c))))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_j;
          VSCtl_bNoGearEgdChgVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_c;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_cs;
        VSCtl_bNoGearEgdChgVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_o;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121225_Determiner_Condition_Changement_Rapport*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121226_Determiner_Condition_Disponibilite_Controle_Rapport_BV*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.88.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c49_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c49_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c49_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_CONTROLE_RAPPORT;
      vsreg_det_cond_fct_gmp_sf_dwork.is_CONTROLE_RAPPORT = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_mt;
      VSCtl_bGearCtlVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_kp;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_CONTROLE_RAPPORT)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_fy:
        if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        ||
             (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL))
             || (((Ext_stGBxCf_swc_in ==
               EXT_STGBXCF_BVMP)
               || (Ext_stGBxCf_swc_in == EXT_STGBXCF_BVA))
               &&
             (VSCtl_stCtl_noGear_swc_in == VSCTL_STCTL_NOGEAR_DEFAUT_38)))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONTROLE_RAPPORT = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_mt;
          VSCtl_bGearCtlVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_kp;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_mt:
        if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR)
        &&
             (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL))
             && (((Ext_stGBxCf_swc_in ==
               EXT_STGBXCF_BVM)
               || ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVMP)
               &&
               (VSCtl_stCtl_noGear_swc_in != VSCTL_STCTL_NOGEAR_DEFAUT_38)))
               ||
             ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVA)
             && (VSCtl_stCtl_noGear_swc_in !=
               VSCTL_STCTL_NOGEAR_DEFAUT_38))))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_CONTROLE_RAPPORT = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_FAUX_fy;
          VSCtl_bGearCtlVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_ot;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_CONTROLE_RAPPORT = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_VRAI_mt;
        VSCtl_bGearCtlVSReg_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_kp;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121226_Determiner_Condition_Disponibilite_Controle_Rapport_BV*/

  VSREG_F2121231_Determiner_Conditions_Maintenance_Gmp();

    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121232_Determiner_Demande_Desactivation_Rapide_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.90.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c50_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c50_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c50_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DESACTIVATION_RAPIDE_GMP_2;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_2 = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_l;
      VSCtl_bFastDeacVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_2)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_l:
        if ((((((((((((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
        &&
                      (VSCtl_bStEngVSReg == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))
                      &&
                     (VSCtl_bNEngMaxVSReg == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))
                     &&
                    (VSCtl_bNEngMinVSReg_no1 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))
                   && (VSCtl_bNEngMinVSReg_no2 ==
                       VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j)) &&
                  (VSCtl_bAvlTqWhlPTVSReg1_pt2 ==
                   VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j)) &&
                 (VSCtl_bAvlTqWhlPTVSReg2_pt2 ==
                  VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j)) &&
                (VSCtl_bAvlTqWhlPTVSReg3_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))

               && (VSCtl_bNoGearVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))
               &&
              (VSCtl_bPosnGBxLevVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))
              &&
             (VSCtl_bCluPedPrssVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))
             &&
            (VSCtl_bNoGearEgdChgVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_2 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_l;
          VSCtl_bFastDeacVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_j;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_l:
        if ((((((((((((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
        ||
                      (VSCtl_bStEngVSReg == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn))
                      ||
                     (VSCtl_bNEngMaxVSReg == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn))
                    || (VSCtl_bNEngMinVSReg_no1 ==
                        VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn)) ||
                   (VSCtl_bNEngMinVSReg_no2 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn))
                  || (VSCtl_bAvlTqWhlPTVSReg1_pt2 ==
                      VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn)) ||
                 (VSCtl_bAvlTqWhlPTVSReg2_pt2 ==
                  VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn)) ||
                (VSCtl_bAvlTqWhlPTVSReg3_pt2 ==
                 VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn))
                 || (VSCtl_bNoGearVSReg_pt2 ==
                VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn)) ||
              (VSCtl_bPosnGBxLevVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn))

             || (VSCtl_bCluPedPrssVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn))
            || (VSCtl_bNoGearEgdChgVSReg_pt2 ==
                VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_2 =
            (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_l;
          VSCtl_bFastDeacVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_2 = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_l;
        VSCtl_bFastDeacVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_pn;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121232_Determiner_Demande_Desactivation_Rapide_GMP*/



    /* TAG_START_OF_STATEFLOW_FUNCTION: F2121233_Determiner_Demande_Inhibition_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.91.0  */

    if (vsreg_det_cond_fct_gmp_sf_dwork.is_active_c51_VSREG_Det_Cond_Fct_Gmp_Sf ==
        0)
    {
      vsreg_det_cond_fct_gmp_sf_dwork.is_active_c51_VSREG_Det_Cond_Fct_Gmp_Sf =
        1U;
      vsreg_det_cond_fct_gmp_sf_dwork.is_c51_VSREG_Det_Cond_Fct_Gmp_Sf =
        (UInt8)VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDE_INHIBITION_f;
      vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
        VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_c;
      VSCtl_bInhVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_i;

    }
    else
    {
      switch (vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION)
        {
       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_c:
        if (((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
             (VSCtl_bFastDeacVSRegReq_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_f))
             &&
            (VSCtl_bGearCtlVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_f))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_i;
          VSCtl_bInhVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_FAUX_f;
        }
        break;

       case VSREG_Det_Cond_Fct_Gmp_Sf_IN_PAS_DEMANDEE_i:
        if (((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
             (VSCtl_bFastDeacVSRegReq_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_i))
             ||
            (VSCtl_bGearCtlVSReg_pt2 == VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_i))
        {
          vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
            VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_c;
          VSCtl_bInhVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_i;
        }
        break;

       default:
        vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION = (UInt8)
          VSREG_Det_Cond_Fct_Gmp_Sf_IN_DEMANDEE_c;
        VSCtl_bInhVSRegReq_pt2 = VSREG_Det_Cond_Fct_Gmp_Sf_VRAI_i;
        break;
      }
    }

    /* TAG_END_OF_STATEFLOW_FUNCTION: F2121233_Determiner_Demande_Inhibition_GMP*/

  }

  VSREG_F21213_Determiner_Conditions_Fonctionnement_Gmp();

  /* TAG_END_OF_MAIN_FUNCTION */
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Gmp_Sf_Init(void)
{
    VSREG_Gmp_Cond_Calc_Sl_Init();

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiFilNoGearVSReg = VSCtl_tiFilNoGearVSReg_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiNEngMinVSReg_no2 = VSCtl_tiTol_nEngMin2VSReg_C;   /* Replaced by Post task */     /* Init from Model */
  VSCtl_bInhVSRegReq_pt2 = DDS_TRUE;
  VSCtl_bFastDeacVSRegReq_pt2 = DDS_TRUE;
  VSCtl_bInhVSRegReq_pt1 = DDS_TRUE;
  VSCtl_bFastDeacVSRegReq_pt1 = DDS_TRUE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_h =
    0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1_c = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_n =
    0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2_h = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c34_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c34_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bAvlTqWhlPTVSReg1_pt1 =DDS_FALSE;
  VSCtl_bAvlTqWhlPTVSReg2_pt1 =DDS_FALSE;
  VSCtl_bAvlTqWhlPTVSReg3_pt1 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_SENS_DEPLACEMENT_VEHICULE = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c35_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c35_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bDirMoveVehVSReg_pt1 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_PLAGE_REGIME_GMP_1 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c36_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c36_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bORng_nTqVSReg_pt1 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_1 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c2_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c2_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bPosnGBxLevVSReg_pt1 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_1 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c38_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c38_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;



  vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION_f = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c39_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c39_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;








  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_ETAT_MOTEUR = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c40_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c40_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bStEngVSReg =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MAX = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c41_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c41_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bNEngMaxVSReg =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_1 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c42_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c42_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bNEngMinVSReg_no1 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_REGIME_MIN_2 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE_f = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_INIT = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c43_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c43_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bNEngMinVSReg_no2 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 =
    0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO1 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 =
    0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO2 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 =
    0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE_GMP_NO3 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c44_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c44_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bAvlTqWhlPTVSReg1_pt2 =DDS_FALSE;
  VSCtl_bAvlTqWhlPTVSReg2_pt2 =DDS_FALSE;
  VSCtl_bAvlTqWhlPTVSReg3_pt2 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_APPUI_PEDALE_EMBRAYAGE = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c45_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c45_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bCluPedPrssVSReg_pt2 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITION_POSITION_LEVIER_BV_GMP_2 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c46_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c46_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bPosnGBxLevVSReg_pt2 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONDITIONS_RAPPORT_BV = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_MARCHE = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_NON_CONFIRME = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c47_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c47_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bNoGearVSReg_pt2 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CHANGEMENT_RAPPORT = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c48_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c48_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bNoGearEgdChgVSReg_pt2 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_CONTROLE_RAPPORT = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c49_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c49_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  VSCtl_bGearCtlVSReg_pt2 =DDS_FALSE;



  vsreg_det_cond_fct_gmp_sf_dwork.is_DESACTIVATION_RAPIDE_GMP_2 = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c50_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c50_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;



  vsreg_det_cond_fct_gmp_sf_dwork.is_DEMANDE_INHIBITION = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c51_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c51_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;







  vsreg_det_cond_fct_gmp_sf_dwork.is_ENABLE = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_active_c1_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsreg_det_cond_fct_gmp_sf_dwork.is_c1_VSREG_Det_Cond_Fct_Gmp_Sf = 0U;
  vsctl_bacv_calcul =DDS_FALSE;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

