/*
* File: VSINFO_Ela_Gmp2_Re002tev_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSINFO_Ela_Gmp2_Re002tev_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Tue Jan 03 09:47:45 2012
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Tue Jan 03 09:47:47 2012
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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Ela_Gmp2_Re002tev_Sf.c
* Version int :/main/L03_01/1 Date: 4/1/2012 16 h 31 m User:esnault 
*    TWK_model:VSINFO_Ela_Gmp2_Re002tev_Sf_L03_010_IMPL1
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\4 Date: 4/1/2012 15 h 22 m User:demezil 
*    TWK_model:VSINFO_Ela_Gmp2_Re002tev_Sf_L03_010_IMPL1
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\3 Date: 3/1/2012 11 h 47 m User:demezil
*    TWK_model:VSINFO_Ela_Gmp2_Re002tev_Sf_L03_010_IMPL1
*    comments :for VSInfo 12.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Determiner_Changement_Rapport_Engage */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Determiner_Changement_Rapport_Engage ;CoPt_noEgdGearCordIt;FRM_bDeacVSCtlNoGearChgClc;VSCtl_stTraInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Determiner_Changement_Rapport_Engage ;VSCtl_bNbGearEgdChg;VSCtl_noGearEgdPrev;VSCtl_tiCfmGearChg_Ext; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Determiner_Changement_Rapport_Engage */

/* TAG_START_OF_STATEFLOW_FUNCTION: Determiner_Disponibilite_Couple_Roue_GMP */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Determiner_Disponibilite_Couple_Roue_GMP ;CoPt_bSIPCord;CoPt_noEgdGearCordIt;CoPt_posnLev;CoPt_stClu;Ext_bCluPedPrss;Ext_bPosnGBxCf;Ext_stGBxCf;VSCtl_stEngInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Determiner_Disponibilite_Couple_Roue_GMP ;VSCtl_bAvlTqWhlPt2_no1;VSCtl_bAvlTqWhlPt2_no2;VSCtl_bAvlTqWhlPt2_no3; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Determiner_Disponibilite_Couple_Roue_GMP */

/* TAG_START_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration ;VSCtl_stTraInfo;VSCtl_strConvTraExtModClc;VSCtl_strConvTraIntno1ModClc;VSCtl_strConvTraIntno2ModClc; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration ;VSCtl_bDgoRatConvTraClc;VSCtl_bMonRunRatConvTraClc;VSCtl_stDiagrConvTra; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_2 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_2 ;VSCtl_stEngInfo;VSCtl_stTraInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_2 ;VSCtl_stPTInfo_pt2;VSCtl_tiIniPTClc_pt2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_2 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Informations_Moteur */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Moteur ;CoPTSt_stEng;ECU_bAuthVSCtlIni;Ext_bVSLimCf;Ext_bVSMaxfCf;Ext_bVSMaxpCf;Ext_bVSMaxsCf;Ext_stDVSRegCf;Ext_stPTCf;FRM_bDeacVSCtlEngClc;VSCtl_bCtlEfc_tqCkEfcMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Moteur ;VSCtl_bAcvFilEngInfo;VSCtl_stEngInfo;VSCtl_tiIniEngClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Informations_Moteur */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Informations_Transmission */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Transmission ;FRM_bDeacVSCtlTraClc;VSCtl_stDiagrConvTra;VSCtl_stEngInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Transmission ;VSCtl_bAcvFilTraInfo;VSCtl_stTraInfo;VSCtl_tiIniTraClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Informations_Transmission */

/* TAG_START_OF_SUB_FUNCTION: F11212_Determiner_Couples_Moteur */
/* TAG_INPUT_OF_SUB_FUNCTION: F11212_Determiner_Couples_Moteur ;EngLim_tqEfcMaxStatVehSpdCtl;Ext_nFrntWhl;TqCmp_tqSumLossCmp;TqDem_tqCkEfc;TqDem_tqCkEfcMax;TqDem_tqCkEfcMin;TqSys_tqCkEfcMinFeas;TqSys_tqCkEfcReq;TqSys_tqCkEngReal;VSCtl_bAcvFilEngInfo;VSCtl_rConvTraVirt_no1;VSCtl_rConvTraVirt_no2;VSCtl_stEngInfo; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11212_Determiner_Couples_Moteur ;VSCtl_tqCkEfcAplReq;VSCtl_tqCkEfcDrvMaxReq;VSCtl_tqCkEfcDrvMinReq;VSCtl_tqCkEfcIni;VSCtl_tqCkEfcMax;VSCtl_tqCkEfcMaxNotCtla;VSCtl_tqCkEfcMaxVirt1;VSCtl_tqCkEfcMaxVirt2;VSCtl_tqCkEfcMin;VSCtl_tqCkEfcMinNotCtla;VSCtl_tqCkEfcMinVirt;VSCtl_tqCkEfcPreCoVSCMinReq;VSCtl_tqCkEfcPreCoVSCtlMxReq;VSCtl_tqCkEfcPreCoVSCtlReq;VSCtl_tqCkEfcReal; */
/* TAG_END_OF_SUB_FUNCTION: F11212_Determiner_Couples_Moteur */

/* TAG_START_OF_SUB_FUNCTION: F11213_Determiner_Regime_Moteur_Filtree */
/* TAG_INPUT_OF_SUB_FUNCTION: F11213_Determiner_Regime_Moteur_Filtree ;Ext_nEng;VSCtl_bAcvFilEngInfo;VSCtl_stEngInfo; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11213_Determiner_Regime_Moteur_Filtree ;VSCtl_nEngFil; */
/* TAG_END_OF_SUB_FUNCTION: F11213_Determiner_Regime_Moteur_Filtree */

/* TAG_START_OF_SUB_FUNCTION: F112222_Determiner_Taux_Conversion_Couple */
/* TAG_INPUT_OF_SUB_FUNCTION: F112222_Determiner_Taux_Conversion_Couple ;CoPt_rCnvTq;Ext_nEng;Ext_nFrntWhl;Ext_spdFrntWhl;VSCtl_bAcvFilTraInfo;VSCtl_bAcvFil_rConvTraExt;VSCtl_bAcvFil_rConvTraInt1;VSCtl_bAcvFil_rConvTraInt2;VSCtl_rdWhl;VSCtl_spdVeh;VSCtl_strConvTraExtModClc;VSCtl_strConvTraIntno1ModClc;VSCtl_strConvTraIntno2ModClc;VSCtl_strConvTraModClc;VSCtl_tirConvTra; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F112222_Determiner_Taux_Conversion_Couple ;VSCtl_grdRatConvTra;VSCtl_rConvTra;VSCtl_rConvTraVirt_no1;VSCtl_rConvTraVirt_no2;VSCtl_rFilrConvTra; */
/* TAG_END_OF_SUB_FUNCTION: F112222_Determiner_Taux_Conversion_Couple */

/* TAG_START_OF_SUB_FUNCTION: F11223_Determiner_Couple_Perte_BV */
/* TAG_INPUT_OF_SUB_FUNCTION: F11223_Determiner_Couple_Perte_BV ;TqCmp_tqCnvLoss;VSCtl_bAcvFilTraInfo;VSCtl_bAcvFil_rConvTraExt;VSCtl_rFilrConvTra;VSCtl_strConvTraExtModClc;VSCtl_strConvTraModClc; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11223_Determiner_Couple_Perte_BV ;VSCtl_tqLossTra; */
/* TAG_END_OF_SUB_FUNCTION: F11223_Determiner_Couple_Perte_BV */

/* TAG_START_OF_SUB_FUNCTION: F11233_Determiner_Couples_Roue_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F11233_Determiner_Couples_Roue_GMP ;VSCtl_rConvTra;VSCtl_stPTInfo_pt2;VSCtl_tqCkEfcAplReq;VSCtl_tqCkEfcDrvMaxReq;VSCtl_tqCkEfcDrvMinReq;VSCtl_tqCkEfcIni;VSCtl_tqCkEfcMax;VSCtl_tqCkEfcMaxNotCtla;VSCtl_tqCkEfcMin;VSCtl_tqCkEfcMinNotCtla;VSCtl_tqCkEfcPreCoVSCMinReq;VSCtl_tqCkEfcPreCoVSCtlMxReq;VSCtl_tqCkEfcPreCoVSCtlReq;VSCtl_tqCkEfcReal;VSCtl_tqLossTra; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11233_Determiner_Couples_Roue_GMP ;VSCtl_tqWhlPTAplReq_pt2;VSCtl_tqWhlPTDrvMaxReq_pt2;VSCtl_tqWhlPTDrvMinReq_pt2;VSCtl_tqWhlPTIni_pt2;VSCtl_tqWhlPTMaxNotCtla_pt2;VSCtl_tqWhlPTMax_pt2;VSCtl_tqWhlPTMinNotCtla_pt2;VSCtl_tqWhlPTMin_pt2;VSCtl_tqWhlPTPreCVSCtlMn_pt2;VSCtl_tqWhlPTPreCVSCtlMx_pt2;VSCtl_tqWhlPTPreCVSCtlRq_pt2;VSCtl_tqWhlPTReal_pt2; */
/* TAG_END_OF_SUB_FUNCTION: F11233_Determiner_Couples_Roue_GMP */

/* TAG_START_OF_SUB_FUNCTION: F11234_Determiner_Potentiels_Couple_Roue_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F11234_Determiner_Potentiels_Couple_Roue_GMP ;VSCtl_rConvTraVirt_no1;VSCtl_rConvTraVirt_no2;VSCtl_stPTInfo_pt2;VSCtl_tqCkEfcMaxVirt1;VSCtl_tqCkEfcMaxVirt2;VSCtl_tqCkEfcMinVirt;VSCtl_tqWhlPotMaxRsvHiThd;VSCtl_tqWhlPotMaxRsvLoThd;VSCtl_tqWhlPotMinRsvHiThd;VSCtl_tqWhlPotMinRsvLoThd; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11234_Determiner_Potentiels_Couple_Roue_GMP ;VSCtl_tqWhlPTPotMax_pt2;VSCtl_tqWhlPTPotMin_pt2;VSCtl_tqWhlPTPotMxCtla1_pt2;VSCtl_tqWhlPTPotRawMax_pt2;VSCtl_tqWhlPTPotRawMin_pt2; */
/* TAG_END_OF_SUB_FUNCTION: F11234_Determiner_Potentiels_Couple_Roue_GMP */

/* TAG_START_OF_SUB_FUNCTION: F11235_Determiner_Pilotabilite_Couple_Roue_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F11235_Determiner_Pilotabilite_Couple_Roue_GMP ;InjSys_bFuCutOff;VSCtl_stPTInfo_pt2; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11235_Determiner_Pilotabilite_Couple_Roue_GMP ;VSCtl_bCtlaTqPT_pt2; */
/* TAG_END_OF_SUB_FUNCTION: F11235_Determiner_Pilotabilite_Couple_Roue_GMP */

/* TAG_START_OF_SUB_FUNCTION: F11236_Determiner_Consigne_Couple_Roue_GMP_Normee */
/* TAG_INPUT_OF_SUB_FUNCTION: F11236_Determiner_Consigne_Couple_Roue_GMP_Normee ;VSCtl_stPTInfo_pt2;VSCtl_tqWhlPTAplReq_pt2;VSCtl_tqWhlPTDrvMaxReq_pt2;VSCtl_tqWhlPTDrvMinReq_pt2; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11236_Determiner_Consigne_Couple_Roue_GMP_Normee ;VSCtl_rTqWhlPTDrvReq_pt2; */
/* TAG_END_OF_SUB_FUNCTION: F11236_Determiner_Consigne_Couple_Roue_GMP_Normee */

/* TAG_START_OF_SUB_FUNCTION: F11237_Determiner_Taux_Repartition_Couple_Roue_GMP_AR */
/* TAG_INPUT_OF_SUB_FUNCTION: F11237_Determiner_Taux_Repartition_Couple_Roue_GMP_AR ; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F11237_Determiner_Taux_Repartition_Couple_Roue_GMP_AR ;VSCtl_rTqWhlPTRe_pt2; */
/* TAG_END_OF_SUB_FUNCTION: F11237_Determiner_Taux_Repartition_Couple_Roue_GMP_AR */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Externe */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Externe ;Ext_bRatConvTraCf;FRM_bRcvVSCtlrConvTra_Ext;VSCtl_stTraInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Externe ;VSCtl_bAcvFil_rConvTraExt;VSCtl_strConvTraExtModClc;VSCtl_tiIni_rConvTraExt; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Externe */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_1 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_1 ;Ext_bRotSpdFrntWhlCf;FRM_bRcvVSCtlrConvTra_Int1;VSCtl_stTraInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_1 ;VSCtl_bAcvFil_rConvTraInt1;VSCtl_strConvTraIntno1ModClc;VSCtl_tiIni_rConvTraIntno1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_1 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_2 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_2 ;Ext_bSpdFrntWhlCf;FRM_bRcvVSCtlrConvTra_Int2;VSCtl_stTraInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_2 ;VSCtl_bAcvFil_rConvTraInt2;VSCtl_strConvTraIntno2ModClc;VSCtl_tiIni_rConvTraIntno2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Interne_2 */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Reference */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Reference ;VSCtl_stDiagrConvTra;VSCtl_stTraInfo;VSCtl_strConvTraExtModClc;VSCtl_strConvTraIntno1ModClc;VSCtl_strConvTraIntno2ModClc; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Reference ;VSCtl_strConvTraModClc;VSCtl_tirConvTra; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_TCC_Reference */

/* END OF SSTG FUNCTION INTERFACE AREA */

/* <AUT_POST> : Task Include managment */
/********************************************************************/
/*  Include Files                                                   */
/********************************************************************/
#include "dds_lib.h"
#include "VSInfo.h"
/* \<AUT_POST> : Task Include managment */

/********************************************************************/
/*  Task Macro Definitions                                          */
/********************************************************************/
#define VSCTL_BRCONVTRACF_C_INTERNE                 (1)
#define EXT_STPTCF_TRACTION                         (0)
#define VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR        (0)
#define EXT_STDVSREGCF_ABSENT                       (0)
#define EXT_BRATCONVTRACF_PRESENT                   (1)
#define VSCTL_BRCONVTRACF_C_EXTERNE                 (0)
#define EXT_BROTSPDFRNTWHLCF_PRESENT                (1)
#define EXT_BPOSNGBXCF_PRESENT                      (1)
#define COPT_POSNLEV_N                              (2)
#define COPT_STCLU_OUVERT                           (0)

/* VSCtl_stEngInfo */
#define VSCTL_STENGINFO_ARRET                       (0)
#define VSCTL_STENGINFO_VERIF_2                     (1)
#define VSCTL_STENGINFO_INIT_2                      (2)
#define VSCTL_STENGINFO_NOMINAL_2                   (3)
#define VSCTL_STENGINFO_DEFAUT_2                    (4)

/* CoPTSt_stEng */
#define COPTST_STENG_MOTEUR_TOURNANT                (5)
#define COPTST_STENG_MOTEUR_ARRET                   (6)
#define COPTST_STENG_REDEM_ENTRAINE                 (7)
#define COPTST_STENG_REDEM_AUTONOME                 (8)

/* VSCtl_stTraInfo */
#define VSCTL_STTRAINFO_ARRET                       (0)
#define VSCTL_STTRAINFO_VERIF_3                     (1)
#define VSCTL_STTRAINFO_INIT_3                      (2)
#define VSCTL_STTRAINFO_NOMINAL_3                   (3)
#define VSCTL_STTRAINFO_DEFAUT_3                    (4)

/* VSCtl_stPTInfo_pt2 */
#define VSCTL_STPTINFO_PT2_ARRET                    (0)
#define VSCTL_STPTINFO_PT2_VERIF_9                  (1)
#define VSCTL_STPTINFO_PT2_INIT_9                   (2)
#define VSCTL_STPTINFO_PT2_NOMINAL_9                (3)
#define VSCTL_STPTINFO_PT2_DEFAUT_9                 (4)

/* VSCtl_strConvTraExtModClc */
#define VSCTL_STRCONVTRAEXTMODCLC_VERIF_4           (1)
#define VSCTL_STRCONVTRAEXTMODCLC_INIT_4            (2)
#define VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4         (3)
#define VSCTL_STRCONVTRAEXTMODCLC_DEFAUT_4          (4)

/* VSCtl_strConvTraIntno1ModClc */
#define VSCTL_STRCONVTRAINTNO1MODCLC_ARRET          (0)
#define VSCTL_STRCONVTRAINTNO1MODCLC_VERIF_5        (1)
#define VSCTL_STRCONVTRAINTNO1MODCLC_INIT_5         (2)
#define VSCTL_STRCONVTRAINTNO1MODCLC_NOMINAL_5      (3)
#define VSCTL_STRCONVTRAINTNO1MODCLC_DEFAUT_5       (4)

/* VSCtl_strConvTraModClc */
#define VSCTL_STRCONVTRAMODCLC_VERIF_8              (1)
#define VSCTL_STRCONVTRAMODCLC_INIT_8               (2)
#define VSCTL_STRCONVTRAMODCLC_EXTERNE_8            (3)
#define VSCTL_STRCONVTRAMODCLC_INTERNE1_8           (4)
#define VSCTL_STRCONVTRAMODCLC_INTERNE2_8           (5)
#define VSCTL_STRCONVTRAMODCLC_DEFAUT_8             (6)

/* VSCtl_strConvTraIntno2ModClc */
#define VSCTL_STRCONVTRAINTNO2MODCLC_ARRET          (0)
#define VSCTL_STRCONVTRAINTNO2MODCLC_VERIF_6        (1)
#define VSCTL_STRCONVTRAINTNO2MODCLC_INIT_6         (2)
#define VSCTL_STRCONVTRAINTNO2MODCLC_NOMINAL_6      (3)
#define VSCTL_STRCONVTRAINTNO2MODCLC_DEFAUT_6       (4)

/* VSCtl_stDiagrConvTra */
#define VSCTL_STDIAGRCONVTRA_ARRET                  (0)
#define VSCTL_STDIAGRCONVTRA_NOMINAL_34             (1)
#define VSCTL_STDIAGRCONVTRA_DEFAUT_34              (2)

/* Named constants for block: /Etat_Informations_Moteur' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ETAT_INFORMATIONS_MOTEUR (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI (1U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX (0U)

/* Named constants for block: /Etat_Informations_Transmission' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_k (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_c (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_p (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_h (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ETAT_INFORMATIONS_TRANSMISSION (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_g (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_e (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_j (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_f (1U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e (0U)

/* Named constants for block: /Etat_Informations_GMP_2' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_nf (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_o (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_p (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_h (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_n (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_a (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ETAT_INFORMATIONS_GMP_2 (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_b (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_VERIF (1)

/* Named constants for block: /Mode_Calcul_TCC_Externe' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_EXTERNE (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_o (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_l (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_i (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_n (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_p (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_d (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei (0U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_d (1U)

/* Named constants for block: /Mode_Calcul_TCC_Interne_1' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_INTERNE1 (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_f (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_e (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_a (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_c (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_p (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_hq (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_k (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m (0U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_n (1U)

/* Named constants for block: /Mode_Calcul_TCC_Interne_2' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_k (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_INTERNE2 (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_b (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_i (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_p (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_i (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c0 (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_i (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_k (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o (0U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dy (1U)

/* Named constants for block: /Diagnostiquer_Configuration_Reconfiguration' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_o (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_lz (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_l (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_e (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_p2 (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p (0U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_a (1U)

/* Named constants for block: /Mode_Calcul_TCC_Reference' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_c (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_f (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_po (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_h (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_REFERENCE (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_EXTERNE (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE1 (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE2 (4)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_if (DDS_TRUE==3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g (2)

/* Named constants for block: /Determiner_Disponibilite_Couple_Roue_GMP' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p (0)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_COUPLE_ROUE (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_i (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVA (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVMP (4)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVM (3)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1 (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2_ET_DISPONIBILITE_3 (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2 (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_3 (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr (1U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow (0U)

/* Named constants for block: /Determiner_Changement_Rapport_Engage' */
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CHANGEMENT_RAPPORT_ENGAGE (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_FAUX (1)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VRAI (2)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_l (0U)
#define VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_k (1U)

/* Definition for custom storage class: Define */
#define COPT_NOEGDGEARCORDIT_NEUTRE    0
#define VSCTL_NOGEAREGDPREV_MAX        8
#define VSCTL_NOGEAREGDPREV_MIN        (-1)
#define VSINFO_ELA_GMP2_RE002TEV_CONST_0 0U
#define VSINFO_ELA_GMP2_RE002TEV_CONST_1 2560U

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_PTInfo_C;         /*BIN0*/
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_tirConvTra;       /*BIN0*/
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_strConvTraModClc;
VAR(UInt8, AUTOMATIC) VSCtl_strConvTraIntno2ModClc;
VAR(UInt8, AUTOMATIC) VSCtl_strConvTraIntno1ModClc;
VAR(UInt8, AUTOMATIC) VSCtl_strConvTraExtModClc;
VAR(UInt8, AUTOMATIC) VSCtl_stPTInfo_pt2;
VAR(UInt8, AUTOMATIC) VSCtl_stEngInfo;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt2_no3;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt2_no2;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt2_no1;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rConvTraInt2;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rConvTraInt1;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rConvTraExt;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilTraInfo;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilEngInfo;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt16 vsi_Keep_Global_Data_From_Input;
  UInt16 vsi_Keep_Global_Data_From_Input_c;
  SInt8 VSCtl_noGearEgdPrev_c;
} BlockIO_VSINFO_Ela_Gmp2_Re002tev_Sf;


typedef struct {
  UInt32 is_DISPONIBILITE_COUPLE_ROUE : 3;
  UInt32 is_NOMINAL : 3;
  UInt32 is_CONFIG_BVA : 2;
  UInt32 is_CONFIG_BVMP : 2;
  UInt32 is_CONFIG_BVM : 2;
  UInt32 is_DISPONIBILITE_2_ET_DISPONIBILITE_3 : 2;
  UInt32 is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c : 2;
  UInt32 is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_ETAT_INFORMATIONS_GMP_2 : 2;
  UInt32 is_PAS_VERIF : 2;
  UInt32 is_CHANGEMENT_RAPPORT : 2;
  UInt32 is_MARCHE_o : 2;
  UInt32 is_MODE_CALCUL_TCC_REFERENCE : 2;
  UInt32 is_MARCHE_l : 2;
  UInt32 is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION : 2;
  UInt32 is_MODE_CALCUL_TCC_INTERNE2 : 2;
  UInt32 is_MARCHE_li : 2;
  UInt32 is_PAS_DEFAUT : 2;
  UInt32 is_MODE_CALCUL_TCC_INTERNE1 : 2;
  UInt32 is_MARCHE_m : 2;
  UInt32 is_PAS_DEFAUT_c : 2;
  UInt32 is_MODE_CALCUL_TCC_EXTERNE : 2;
  UInt32 is_MARCHE_f : 2;
  UInt32 is_PAS_DEFAUT_n : 2;
  UInt32 is_MARCHE_og : 2;
  UInt32 is_ETAT_INFORMATIONS_TRANSMISSION : 2;
  UInt32 is_PAS_DEFAUT_f : 2;
  UInt32 is_MARCHE_g : 2;
  UInt32 is_PAS_DEFAUT_g : 2;
  UInt32 is_ETAT_INFORMATIONS_MOTEUR : 2;
  UInt32 is_active_c169_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c169_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_c168_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c168_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_PAS_DEFAUT_e : 1;
  UInt32 is_active_c167_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c167_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_CHANGEMENT_RAPPORT : 1;
  UInt32 is_active_MEMOIRES : 1;
  UInt32 is_active_c166_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c166_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_c165_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c165_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_c164_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c164_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_c163_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c163_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_c162_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c162_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_c161_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c161_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_active_c160_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
  UInt32 is_c160_VSINFO_Ela_Gmp2_Re002tev_Sf : 1;
} D_Work_VSINFO_Ela_Gmp2_Re002tev_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmGearChg_Ext;                 /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniEngClc;                      /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniPTClc_pt2;                   /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniTraClc;                      /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIni_rConvTraExt;                /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIni_rConvTraIntno1;             /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIni_rConvTraIntno2;             /*BIN0*/
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) VSCtl_noGearEgdPrev;                     /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stDiagrConvTra;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stTraInfo;
/* Static Visible area end */
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 32BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsinfo_vsctl_nengfil_cpy;                                 /*BIN0*/
#define VSINFO_STOP_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"


/* 16BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_grdratconvtra_cpy;                           /*BIN1*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcdrvmaxreq_cpy;                        /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcdrvminreq_cpy;                        /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcmax_cpy;                              /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcmaxnotctla_cpy;                       /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcmin_cpy;                              /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcminnotctla_cpy;                       /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcprecovscminreq_cpy;                   /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqckefcprecovsctlreq_cpy;                    /*BIN4*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqlosstra_cpy;                               /*BIN4*/
STATIC VAR(UInt16, AUTOMATIC) vsinfo_vsctl_rconvtra_cpy;                                /*BIN7*/
#define VSINFO_STOP_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(BlockIO_VSINFO_Ela_Gmp2_Re002tev_Sf, AUTOMATIC) vsinfo_ela_gmp2_re002tev_sf_b;
STATIC VAR(D_Work_VSINFO_Ela_Gmp2_Re002tev_Sf, AUTOMATIC) vsinfo_ela_gmp2_re002tev_sf_dwork;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"


/* 8BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsinfo_ela_gmp2_re002tev_delay_0;
/* Static Not Visible area end */
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_bdgoratconvtraclc_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_bmonrunratconvtraclc_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_bnbgearegdchg_cpy;
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfm_bGearChgExt_C = (CONST(UInt16, AUTOMATIC))(10U);    /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_EngInfo_C = (CONST(UInt16, AUTOMATIC))(3U);         /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_TraInfo_C = (CONST(UInt16, AUTOMATIC))(3U);         /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_rConvTraExt_C = (CONST(UInt16, AUTOMATIC))(9U);     /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_rConvTraIntno1_C = (CONST(UInt16, AUTOMATIC))(9U);  /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_rConvTraIntno2_C = (CONST(UInt16, AUTOMATIC))(9U);  /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tirConvTra_C = (CONST(UInt16, AUTOMATIC))(100U);          /*BIN0*/
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/* 8BIT-bits variable definition */
#define VSINFO_START_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCluEnaAvlTqWhl_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_brConvTraCf_C = VSCTL_BRCONVTRACF_C_INTERNE;
/* \<AUT_POST> : Task Memory Ordering */
#define VSINFO_STOP_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"

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

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp2_Re002tev_Sf(SInt16 VSCtl_tqWhlPotMaxRsvHiThd_swc_in,                    /*BIN1*/
                               UInt8 VSCtl_bCtlEfc_tqCkEfcMax_swc_in,
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                   /*BIN0*/
                               SInt16 TqSys_tqCkEfcMinFeas_swc_in,                         /*BIN4*/
                               UInt8 FRM_bRcvVSCtlrConvTra_Int1_swc_in,
                               SInt16 VSCtl_tqWhlPotMinRsvLoThd_swc_in,                    /*BIN1*/
                               UInt8 FRM_bRcvVSCtlrConvTra_Int2_swc_in,
                               SInt16 VSCtl_tqWhlPotMaxRsvLoThd_swc_in,                    /*BIN1*/
                               UInt8 FRM_bDeacVSCtlEngClc_swc_in,
                               UInt8 Ext_stDVSRegCf_swc_in,
                               UInt8 CoPt_bSIPCord_swc_in,
                               UInt16 TqCmp_tqCnvLoss_swc_in,                              /*BIN4*/
                               UInt16 CoPt_rCnvTq_swc_in,                                  /*BIN7*/
                               SInt16 TqSys_tqCkEngReal_swc_in,                            /*BIN4*/
                               UInt16 Ext_spdFrntWhl_swc_in,                               /*BIN7*/
                               UInt8 FRM_bRcvVSCtlrConvTra_Ext_swc_in,
                               UInt8 Ext_bPosnGBxCf_swc_in,
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt8 CoPTSt_stEng_swc_in,
                               SInt16 TqDem_tqCkEfcMin_swc_in,                             /*BIN4*/
                               SInt16 TqCmp_tqSumLossCmp_swc_in,                           /*BIN4*/
                               UInt8 Ext_bRatConvTraCf_swc_in,
                               UInt8 CoPt_stClu_swc_in,
                               UInt8 Ext_stGBxCf_swc_in,
                               SInt16 TqDem_tqCkEfcMax_swc_in,                             /*BIN4*/
                               UInt8 InjSys_bFuCutOff_swc_in,
                               UInt32 Ext_nFrntWhl_swc_in,                                 /*BIN7*/
                               UInt8 Ext_stPTCf_swc_in,
                               UInt8 Ext_bVSLimCf_swc_in,
                               UInt8 Ext_bSpdFrntWhlCf_swc_in,
                               UInt16 VSCtl_rdWhl_swc_in,                                  /*BIN7*/
                               SInt16 TqSys_tqCkEfcReq_swc_in,                             /*BIN4*/
                               UInt8 Ext_bVSMaxfCf_swc_in,
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 Ext_bCluPedPrss_swc_in,
                               UInt16 Ext_nEng_swc_in,                                     /*BIN0*/
                               UInt8 FRM_bDeacVSCtlTraClc_swc_in,
                               UInt8 Ext_bVSMaxpCf_swc_in,
                               SInt16 TqDem_tqCkEfc_swc_in,                                /*BIN4*/
                               UInt8 CoPt_posnLev_swc_in,
                               UInt8 Ext_bRotSpdFrntWhlCf_swc_in,
                               UInt8 Ext_bVSMaxsCf_swc_in,
                               SInt16 EngLim_tqEfcMaxStatVehSpdCtl_swc_in,                 /*BIN4*/
                               SInt16 VSCtl_tqWhlPotMinRsvHiThd_swc_in,                    /*BIN1*/
                               UInt8 FRM_bDeacVSCtlNoGearChgClc_swc_in,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMin_swc_out,                             /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMax_swc_out,                             /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMinReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMaxReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqLossTra_swc_out,                              /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCtlReq_swc_out,                   /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rConvTra_swc_out,                               /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_grdRatConvTra_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCMinReq_swc_out,                  /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bNbGearEgdChg_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nEngFil_swc_out)                                /*BIN0*/
{
  UInt8 rtb_aut_ec_keep_global_data_from_input;


  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F11211_Determiner_Etat_Informations_Moteur*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.28.2 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c160_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c160_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c160_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ETAT_INFORMATIONS_MOTEUR;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_MOTEUR = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET;
    VSCtl_stEngInfo = VSCTL_STENGINFO_ARRET;
    VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX;
    VSCtl_tiIniEngClc = VSCtl_tiIni_EngInfo_C;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_MOTEUR) {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET:
      if ((((Ext_stPTCf_swc_in == EXT_STPTCF_TRACTION)
      && (VSCtl_bCtlCmdPTTqCf_SC ==
             VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR))
             && (CoPTSt_stEng_swc_in ==
            COPTST_STENG_MOTEUR_TOURNANT)) && ((((((Ext_stDVSRegCf_swc_in ==
                EXT_STDVSREGCF_RVV_PRESENT) || (Ext_stDVSRegCf_swc_in ==
                EXT_STDVSREGCF_ACC_PRESENT)) || (Ext_bVSLimCf_swc_in ==
               EXT_BVSLIMCF_PRESENT))
               || (Ext_bVSMaxfCf_swc_in == EXT_BVSMAXFCF_PRESENT))

            || (Ext_bVSMaxpCf_swc_in == EXT_BVSMAXPCF_PRESENT))
            || (Ext_bVSMaxsCf_swc_in ==
            EXT_BVSMAXSCF_PRESENT)))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_MOTEUR = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF;
        VSCtl_stEngInfo = VSCTL_STENGINFO_VERIF_2;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE:
      if ((((Ext_stPTCf_swc_in != EXT_STPTCF_TRACTION)
      || (VSCtl_bCtlCmdPTTqCf_SC !=
             VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR))
             || ((((CoPTSt_stEng_swc_in !=
               COPTST_STENG_MOTEUR_TOURNANT) && (CoPTSt_stEng_swc_in !=
               COPTST_STENG_MOTEUR_ARRET)) && (CoPTSt_stEng_swc_in !=
              COPTST_STENG_REDEM_ENTRAINE)) && (CoPTSt_stEng_swc_in !=
             COPTST_STENG_REDEM_AUTONOME))) || (((((Ext_stDVSRegCf_swc_in ==
               EXT_STDVSREGCF_ABSENT)
               && (Ext_bVSLimCf_swc_in == EXT_BVSLIMCF_ABSENT))
               &&
             (Ext_bVSMaxfCf_swc_in == EXT_BVSMAXFCF_ABSENT))
             && (Ext_bVSMaxpCf_swc_in ==
             EXT_BVSMAXPCF_ABSENT))
             && (Ext_bVSMaxsCf_swc_in == EXT_BVSMAXSCF_ABSENT)))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_g = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_MOTEUR = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET;
        VSCtl_stEngInfo = VSCTL_STENGINFO_ARRET;
        VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX;
        VSCtl_tiIniEngClc = VSCtl_tiIni_EngInfo_C;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT:
          if (FRM_bDeacVSCtlEngClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_g = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT;
            VSCtl_stEngInfo = VSCTL_STENGINFO_INIT_2;
            VSCtl_tiIniEngClc = VSCtl_tiIni_EngInfo_C;
            VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT:
          if (FRM_bDeacVSCtlEngClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_g = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT;
            VSCtl_stEngInfo = VSCTL_STENGINFO_DEFAUT_2;
            VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX;

          }
          else
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_g)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT:
              if ((VSCtl_tiIniEngClc == 0)
              && (VSCtl_bCtlEfc_tqCkEfcMax_swc_in ==
                   VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX))
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_g = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL;
                VSCtl_stEngInfo = VSCTL_STENGINFO_NOMINAL_2;
                VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI;

              }
              else
              {
                VSCtl_tiIniEngClc = (UInt16)DDS_M_MAX(VSCtl_tiIniEngClc - 1, 0);
                VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI;
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF:
          if ((ECU_bAuthVSCtlIni_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI)
          &&
              (FRM_bDeacVSCtlEngClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT;
            VSCtl_stEngInfo = VSCTL_STENGINFO_DEFAUT_2;
            VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX;

          }
          else if ((ECU_bAuthVSCtlIni_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI)
          &&
                     (FRM_bDeacVSCtlEngClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_g = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT;
            VSCtl_stEngInfo = VSCTL_STENGINFO_INIT_2;
            VSCtl_tiIniEngClc = VSCtl_tiIni_EngInfo_C;
            VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_MOTEUR = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET;
      VSCtl_stEngInfo = VSCTL_STENGINFO_ARRET;
      VSCtl_bAcvFilEngInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX;
      VSCtl_tiIniEngClc = VSCtl_tiIni_EngInfo_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F11211_Determiner_Etat_Informations_Moteur*/


  rtb_aut_ec_keep_global_data_from_input = vsinfo_ela_gmp2_re002tev_delay_0;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F11221_Determiner_Etat_Informations_Transmission*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.48.1 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c161_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c161_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c161_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ETAT_INFORMATIONS_TRANSMISSION;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_TRANSMISSION =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_g;
    VSCtl_stTraInfo = VSCTL_STTRAINFO_ARRET;
    VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e;
    VSCtl_tiIniTraClc = VSCtl_tiIni_TraInfo_C;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_TRANSMISSION)
    {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_g:
      if (VSCtl_stEngInfo != VSCTL_STENGINFO_ARRET)
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_TRANSMISSION =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_p;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_c;
        VSCtl_stTraInfo = VSCTL_STTRAINFO_VERIF_3;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_p:
      if (VSCtl_stEngInfo == VSCTL_STENGINFO_ARRET)
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_f = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_TRANSMISSION =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_g;
        VSCtl_stTraInfo = VSCTL_STTRAINFO_ARRET;
        VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e;
        VSCtl_tiIniTraClc = VSCtl_tiIni_TraInfo_C;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_e:
          if (((FRM_bDeacVSCtlTraClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e)
          &&
               (rtb_aut_ec_keep_global_data_from_input !=
                VSCTL_STDIAGRCONVTRA_DEFAUT_34))
                && (VSCtl_stEngInfo ==
               VSCTL_STENGINFO_NOMINAL_2))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_j;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_f = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_h;
            VSCtl_stTraInfo = VSCTL_STTRAINFO_INIT_3;
            VSCtl_tiIniTraClc = VSCtl_tiIni_TraInfo_C;
            VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_j:
          if (((FRM_bDeacVSCtlTraClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_f)
          ||
               (rtb_aut_ec_keep_global_data_from_input ==
                VSCTL_STDIAGRCONVTRA_DEFAUT_34))
                || (VSCtl_stEngInfo ==
               VSCTL_STENGINFO_DEFAUT_2))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_f = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_e;
            VSCtl_stTraInfo = VSCTL_STTRAINFO_DEFAUT_3;
            VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e;

          }
          else
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_f)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_h:
              if (VSCtl_tiIniTraClc == 0)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_f = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_k;
                VSCtl_stTraInfo = VSCTL_STTRAINFO_NOMINAL_3;
                VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_f;

              }
              else
              {
                VSCtl_tiIniTraClc = (UInt16)DDS_M_MAX(VSCtl_tiIniTraClc - 1, 0);
                VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_f;
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_c:
          if (((FRM_bDeacVSCtlTraClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e)
          &&
               (rtb_aut_ec_keep_global_data_from_input !=
                VSCTL_STDIAGRCONVTRA_DEFAUT_34))
                && (VSCtl_stEngInfo ==
               VSCTL_STENGINFO_NOMINAL_2))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_j;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_f = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_h;
            VSCtl_stTraInfo = VSCTL_STTRAINFO_INIT_3;
            VSCtl_tiIniTraClc = VSCtl_tiIni_TraInfo_C;
            VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e;

          }
          else if (((FRM_bDeacVSCtlTraClc_swc_in ==
                       VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_f) ||
                      (rtb_aut_ec_keep_global_data_from_input ==
                       VSCTL_STDIAGRCONVTRA_DEFAUT_34))
                       || (VSCtl_stEngInfo ==
                      VSCTL_STENGINFO_DEFAUT_2))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_e;
            VSCtl_stTraInfo = VSCTL_STTRAINFO_DEFAUT_3;
            VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_TRANSMISSION =
        (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_g;
      VSCtl_stTraInfo = VSCTL_STTRAINFO_ARRET;
      VSCtl_bAcvFilTraInfo = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_e;
      VSCtl_tiIniTraClc = VSCtl_tiIni_TraInfo_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F11221_Determiner_Etat_Informations_Transmission*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F11231_Determiner_Etat_Information_GMP*/

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c168_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c168_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c168_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ETAT_INFORMATIONS_GMP_2;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_2 = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_o;
    VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_ARRET;
    VSCtl_tiIniPTClc_pt2 = VSCtl_tiIni_PTInfo_C;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_2)
          {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_o:
      if ((VSCtl_stEngInfo != VSCTL_STENGINFO_ARRET)
      && (VSCtl_stTraInfo !=
           VSCTL_STTRAINFO_ARRET))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_2 = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_n;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_b;
        VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_VERIF_9;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_n:
      if ((VSCtl_stEngInfo == VSCTL_STENGINFO_ARRET)
      || (VSCtl_stTraInfo ==
           VSCTL_STTRAINFO_ARRET))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_VERIF = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_e = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_2 = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_o;
        VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_ARRET;
        VSCtl_tiIniPTClc_pt2 = VSCtl_tiIni_PTInfo_C;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_nf:
          if ((VSCtl_stEngInfo != VSCTL_STENGINFO_DEFAUT_2)
          && (VSCtl_stTraInfo
               != VSCTL_STTRAINFO_DEFAUT_3))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_b;
            VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_VERIF_9;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_a:
          if ((VSCtl_stEngInfo == VSCTL_STENGINFO_DEFAUT_2)
          || (VSCtl_stTraInfo ==
               VSCTL_STTRAINFO_DEFAUT_3))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_VERIF = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_e = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_nf;
            VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_DEFAUT_9;

          }
          else
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_VERIF)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_p:
              if (VSCtl_tiIniPTClc_pt2 == 0)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_VERIF = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_h;
                VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_NOMINAL_9;

              }
              else
              {
                VSCtl_tiIniPTClc_pt2 = (UInt16)DDS_M_MAX(VSCtl_tiIniPTClc_pt2 - 1,
                  0);
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_b:
          if ((VSCtl_stEngInfo == VSCTL_STENGINFO_DEFAUT_2)
          || (VSCtl_stTraInfo ==
               VSCTL_STTRAINFO_DEFAUT_3))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_nf;
            VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_DEFAUT_9;

          }
          else if ((VSCtl_stEngInfo == VSCTL_STENGINFO_NOMINAL_2)
          &&
                     (VSCtl_stTraInfo == VSCTL_STTRAINFO_NOMINAL_3))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_a;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_e = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_VERIF;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_VERIF = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_p;
            VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_INIT_9;
            VSCtl_tiIniPTClc_pt2 = VSCtl_tiIni_PTInfo_C;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_2 = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_o;
      VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_ARRET;
      VSCtl_tiIniPTClc_pt2 = VSCtl_tiIni_PTInfo_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F11231_Determiner_Etat_Information_GMP*/

  VSINFO_F11212_Determiner_Couples_Moteur(EngLim_tqEfcMaxStatVehSpdCtl_swc_in, /* BIN4 */
                                           Ext_nFrntWhl_swc_in, /* BIN7 */
                                           TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           TqDem_tqCkEfc_swc_in, /* BIN4 */
                                           TqDem_tqCkEfcMax_swc_in, /* BIN4 */
                                           TqDem_tqCkEfcMin_swc_in, /* BIN4 */
                                           TqSys_tqCkEfcMinFeas_swc_in, /* BIN4 */
                                           TqSys_tqCkEfcReq_swc_in, /* BIN4 */
                                           TqSys_tqCkEngReal_swc_in, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcdrvmaxreq_cpy, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcdrvminreq_cpy, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcmax_cpy, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcmaxnotctla_cpy, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcmin_cpy, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcminnotctla_cpy, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcprecovscminreq_cpy, /* BIN4 */
                                           &vsinfo_vsctl_tqckefcprecovsctlreq_cpy /* BIN4 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F1122211_Determiner_Mode_Calcul_Taux_Conversion_Couple_Externe*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.148.0 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c162_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c162_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c162_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_EXTERNE;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_EXTERNE = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_l;
    VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_ARRET;
    VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_EXTERNE)
          {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_l:
      if (((VSCtl_stTraInfo != VSCTL_STTRAINFO_ARRET)
      && (Ext_bRatConvTraCf_swc_in ==
            EXT_BRATCONVTRACF_PRESENT)) && (VSCtl_brConvTraCf_C ==
           VSCTL_BRCONVTRACF_C_EXTERNE))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_EXTERNE = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_o;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_p;
        VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_VERIF_4;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_o:
      if (((VSCtl_stTraInfo == VSCTL_STTRAINFO_ARRET)
      || (Ext_bRatConvTraCf_swc_in !=
            EXT_BRATCONVTRACF_PRESENT)) || (VSCtl_brConvTraCf_C !=
           VSCTL_BRCONVTRACF_C_EXTERNE))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_n = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_EXTERNE = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_l;
        VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_ARRET;
        VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_n:
          if (FRM_bRcvVSCtlrConvTra_Ext_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_n = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_d;
            VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_INIT_4;
            VSCtl_tiIni_rConvTraExt = VSCtl_tiIni_rConvTraExt_C;
            VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c:
          if (FRM_bRcvVSCtlrConvTra_Ext_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_d)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_n = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_n;
            VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_DEFAUT_4;
            VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei;

          }
          else
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_n)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_d:
              if (VSCtl_tiIni_rConvTraExt == 0)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_n = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_i;
                VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4;
                VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_d;

              }
              else
              {
                VSCtl_tiIni_rConvTraExt = (UInt16)DDS_M_MAX
                  (VSCtl_tiIni_rConvTraExt - 1, 0);
                VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_d;
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_p:
          if (FRM_bRcvVSCtlrConvTra_Ext_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_d)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_n;
            VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_DEFAUT_4;
            VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei;

          }
          else if (FRM_bRcvVSCtlrConvTra_Ext_swc_in ==
                     VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_n = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_d;
            VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_INIT_4;
            VSCtl_tiIni_rConvTraExt = VSCtl_tiIni_rConvTraExt_C;
            VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_EXTERNE = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_l;
      VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_ARRET;
      VSCtl_bAcvFil_rConvTraExt = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ei;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1122211_Determiner_Mode_Calcul_Taux_Conversion_Couple_Externe*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F1122212_Determiner_Mode_Calcul_Taux_Conversion_Couple_Interne_1*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.149.0 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c163_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c163_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c163_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_INTERNE1;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE1 = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_e;
    VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_ARRET;
    VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE1)
          {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_e:
      if ((VSCtl_stTraInfo != VSCTL_STTRAINFO_ARRET)
      && (Ext_bRotSpdFrntWhlCf_swc_in ==
           EXT_BROTSPDFRNTWHLCF_PRESENT))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE1 = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_f;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_a;
        VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_VERIF_5;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_f:
      if ((VSCtl_stTraInfo == VSCTL_STTRAINFO_ARRET)
      || (Ext_bRotSpdFrntWhlCf_swc_in !=
           EXT_BROTSPDFRNTWHLCF_PRESENT))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_c = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE1 = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_e;
        VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_ARRET;
        VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_p:
          if (FRM_bRcvVSCtlrConvTra_Int1_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_k;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_c = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_hq;
            VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_INIT_5;
            VSCtl_tiIni_rConvTraIntno1 = VSCtl_tiIni_rConvTraIntno1_C;
            VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_k:
          if (FRM_bRcvVSCtlrConvTra_Int1_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_n)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_c = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_p;
            VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_DEFAUT_5;
            VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m;

          }
          else
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_c)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_hq:
              if (VSCtl_tiIni_rConvTraIntno1 == 0)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_c = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_c;
                VSCtl_strConvTraIntno1ModClc =
                  VSCTL_STRCONVTRAINTNO1MODCLC_NOMINAL_5;
                VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_n;

              }
              else
              {
                VSCtl_tiIni_rConvTraIntno1 = (UInt16)DDS_M_MAX
                  (VSCtl_tiIni_rConvTraIntno1 - 1, 0);
                VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_n;
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_a:
          if (FRM_bRcvVSCtlrConvTra_Int1_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_n)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_p;
            VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_DEFAUT_5;
            VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m;

          }
          else if (FRM_bRcvVSCtlrConvTra_Int1_swc_in ==
                     VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_k;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_c = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_hq;
            VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_INIT_5;
            VSCtl_tiIni_rConvTraIntno1 = VSCtl_tiIni_rConvTraIntno1_C;
            VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE1 = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_e;
      VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_ARRET;
      VSCtl_bAcvFil_rConvTraInt1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_m;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1122212_Determiner_Mode_Calcul_Taux_Conversion_Couple_Interne_1*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F1122213_Determiner_Mode_Calcul_Taux_Conversion_Couple_Interne_2*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.150.0 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c164_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c164_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c164_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_INTERNE2;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE2 = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_b;
    VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_ARRET;
    VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE2)
          {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_b:
      if ((VSCtl_stTraInfo != VSCTL_STTRAINFO_ARRET)
      && (Ext_bSpdFrntWhlCf_swc_in ==
           VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dy))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE2 = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_i;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_i;
        VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_VERIF_6;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_i:
      if ((VSCtl_stTraInfo == VSCTL_STTRAINFO_ARRET)
      || (Ext_bSpdFrntWhlCf_swc_in ==
           VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_k;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_k;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE2 = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_b;
        VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_ARRET;
        VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_k:
          if (FRM_bRcvVSCtlrConvTra_Int2_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c0;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_i;
            VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_INIT_6;
            VSCtl_tiIni_rConvTraIntno2 = VSCtl_tiIni_rConvTraIntno2_C;
            VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c0:
          if (FRM_bRcvVSCtlrConvTra_Int2_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dy)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_k;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_k;
            VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_DEFAUT_6;
            VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o;

          }
          else
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_i:
              if (VSCtl_tiIni_rConvTraIntno2 == 0)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_p;
                VSCtl_strConvTraIntno2ModClc =
                  VSCTL_STRCONVTRAINTNO2MODCLC_NOMINAL_6;
                VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dy;

              }
              else
              {
                VSCtl_tiIni_rConvTraIntno2 = (UInt16)DDS_M_MAX
                  (VSCtl_tiIni_rConvTraIntno2 - 1, 0);
                VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dy;
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_i:
          if (FRM_bRcvVSCtlrConvTra_Int2_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dy)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_k;
            VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_DEFAUT_6;
            VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o;

          }
          else if (FRM_bRcvVSCtlrConvTra_Int2_swc_in ==
                     VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_PAS_DEFAUT_c0;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_i;
            VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_INIT_6;
            VSCtl_tiIni_rConvTraIntno2 = VSCtl_tiIni_rConvTraIntno2_C;
            VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE2 = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_b;
      VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_ARRET;
      VSCtl_bAcvFil_rConvTraInt2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_o;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1122213_Determiner_Mode_Calcul_Taux_Conversion_Couple_Interne_2*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F1122214_Diagnostiquer_Configuration_Reconfiguration*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.151.0 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c165_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c165_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c165_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
      = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_lz;
    VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_ARRET;
    vsinfo_vsctl_bdgoratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;
    vsinfo_vsctl_bmonrunratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;

  }
  else
  {
    switch
      (vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION)
    {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_lz:
      if ((((VSCtl_stTraInfo != VSCTL_STTRAINFO_ARRET) &&
            ((VSCtl_strConvTraExtModClc == VSCTL_STRCONVTRAEXTMODCLC_ARRET)
            ||
             (VSCtl_strConvTraExtModClc == VSCTL_STRCONVTRAEXTMODCLC_DEFAUT_4)))
           && ((VSCtl_strConvTraIntno1ModClc ==
                VSCTL_STRCONVTRAINTNO1MODCLC_ARRET) ||
               (VSCtl_strConvTraIntno1ModClc ==
                VSCTL_STRCONVTRAINTNO1MODCLC_DEFAUT_5))) &&
          ((VSCtl_strConvTraIntno2ModClc == VSCTL_STRCONVTRAINTNO2MODCLC_ARRET)
          ||
           (VSCtl_strConvTraIntno2ModClc ==
            VSCTL_STRCONVTRAINTNO2MODCLC_DEFAUT_6)))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
          = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_p2;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_l;
        VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_DEFAUT_34;
        vsinfo_vsctl_bdgoratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_a;
        vsinfo_vsctl_bmonrunratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_a;

      }
      else if ((((VSCtl_stTraInfo != VSCTL_STTRAINFO_ARRET) &&
                   ((VSCtl_strConvTraExtModClc !=
                     VSCTL_STRCONVTRAEXTMODCLC_ARRET) &&
                    (VSCtl_strConvTraExtModClc !=
                     VSCTL_STRCONVTRAEXTMODCLC_DEFAUT_4))) ||
                  ((VSCtl_strConvTraIntno1ModClc !=
                    VSCTL_STRCONVTRAINTNO1MODCLC_ARRET) &&
                   (VSCtl_strConvTraIntno1ModClc !=
                    VSCTL_STRCONVTRAINTNO1MODCLC_DEFAUT_5))) ||
                 ((VSCtl_strConvTraIntno2ModClc !=
                   VSCTL_STRCONVTRAINTNO2MODCLC_ARRET) &&
                  (VSCtl_strConvTraIntno2ModClc !=
                   VSCTL_STRCONVTRAINTNO2MODCLC_DEFAUT_6)))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
          = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_p2;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_e;
        VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_NOMINAL_34;
        vsinfo_vsctl_bdgoratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;
        vsinfo_vsctl_bmonrunratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_a;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_p2:
      if (VSCtl_stTraInfo == VSCTL_STTRAINFO_ARRET)
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_o;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
          = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_lz;
        VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_ARRET;
        vsinfo_vsctl_bdgoratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;
        vsinfo_vsctl_bmonrunratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_l)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_l:
          if ((((VSCtl_strConvTraExtModClc != VSCTL_STRCONVTRAEXTMODCLC_ARRET)
          &&
                (VSCtl_strConvTraExtModClc != VSCTL_STRCONVTRAEXTMODCLC_DEFAUT_4))
               || ((VSCtl_strConvTraIntno1ModClc !=
                    VSCTL_STRCONVTRAINTNO1MODCLC_ARRET) &&
                   (VSCtl_strConvTraIntno1ModClc !=
                    VSCTL_STRCONVTRAINTNO1MODCLC_DEFAUT_5))) ||
              ((VSCtl_strConvTraIntno2ModClc !=
                VSCTL_STRCONVTRAINTNO2MODCLC_ARRET) &&
               (VSCtl_strConvTraIntno2ModClc !=
                VSCTL_STRCONVTRAINTNO2MODCLC_DEFAUT_6)))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_e;
            VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_NOMINAL_34;
            vsinfo_vsctl_bdgoratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;
            vsinfo_vsctl_bmonrunratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_a;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_e:
          if ((((VSCtl_strConvTraExtModClc == VSCTL_STRCONVTRAEXTMODCLC_ARRET)
          ||
                (VSCtl_strConvTraExtModClc == VSCTL_STRCONVTRAEXTMODCLC_DEFAUT_4))
               && ((VSCtl_strConvTraIntno1ModClc ==
                    VSCTL_STRCONVTRAINTNO1MODCLC_ARRET) ||
                   (VSCtl_strConvTraIntno1ModClc ==
                    VSCTL_STRCONVTRAINTNO1MODCLC_DEFAUT_5))) &&
              ((VSCtl_strConvTraIntno2ModClc ==
                VSCTL_STRCONVTRAINTNO2MODCLC_ARRET) ||
               (VSCtl_strConvTraIntno2ModClc ==
                VSCTL_STRCONVTRAINTNO2MODCLC_DEFAUT_6)))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_l = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_l;
            VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_DEFAUT_34;
            vsinfo_vsctl_bdgoratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_a;
            vsinfo_vsctl_bmonrunratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_a;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
        = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_lz;
      VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_ARRET;
      vsinfo_vsctl_bdgoratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;
      vsinfo_vsctl_bmonrunratconvtraclc_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_p;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1122214_Diagnostiquer_Configuration_Reconfiguration*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F1122215_Determiner_Mode_Calcul_Taux_Conversion_Couple_Reference*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.152.0 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c166_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c166_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c166_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MODE_CALCUL_TCC_REFERENCE;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_REFERENCE = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_c;
    VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_ARRET;
    VSCtl_tirConvTra = 0U;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_REFERENCE)
          {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_c:
      if (VSCtl_stTraInfo != VSCTL_STTRAINFO_ARRET)
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_REFERENCE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_h;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_if;
        VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_VERIF_8;
        VSCtl_tirConvTra = 0U;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_MARCHE_h:
      if (VSCtl_stTraInfo == VSCTL_STTRAINFO_ARRET)
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_po:
          vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
            VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_f:
          switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL)
      {
           case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_EXTERNE:
            VSCtl_tirConvTra = VSCtl_tirConvTra_C;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
            break;

           case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g:
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
            break;

           case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE1:
            VSCtl_tirConvTra = VSCtl_tirConvTra_C;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
            break;

           case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE2:
            VSCtl_tirConvTra = VSCtl_tirConvTra_C;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
            break;

           default:
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
            break;
          }

          vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
            VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_if:
          vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
            VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
          break;

         default:
          vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
            VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
          break;
        }

        vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_REFERENCE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_c;
        VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_ARRET;
        VSCtl_tirConvTra = 0U;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_po:
          if ((VSCtl_stDiagrConvTra != VSCTL_STDIAGRCONVTRA_DEFAUT_34)
          &&
              (VSCtl_stTraInfo == VSCTL_STTRAINFO_NOMINAL_3))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_f;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g;
            VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_INIT_8;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_f:
          if ((VSCtl_stDiagrConvTra == VSCTL_STDIAGRCONVTRA_DEFAUT_34)
          ||
              (VSCtl_stTraInfo == VSCTL_STTRAINFO_DEFAUT_3))
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_EXTERNE:
              VSCtl_tirConvTra = VSCtl_tirConvTra_C;
              vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g:
              vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE1:
              VSCtl_tirConvTra = VSCtl_tirConvTra_C;
              vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE2:
              VSCtl_tirConvTra = VSCtl_tirConvTra_C;
              vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
              break;

             default:
              vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_dw;
              break;
            }

            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_po;
            VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_DEFAUT_8;
            VSCtl_tirConvTra = 0U;

          }
          else
          {
            switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL)
          {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_EXTERNE:
              if (VSCtl_strConvTraExtModClc !=
                  VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4)
              {
                VSCtl_tirConvTra = VSCtl_tirConvTra_C;
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g;
                VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_INIT_8;

              }
              else
              {
                VSCtl_tirConvTra = (UInt16)DDS_M_MAX(VSCtl_tirConvTra - 1, 0);
              }
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g:
              if (VSCtl_strConvTraExtModClc ==
                  VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_EXTERNE;
                VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_EXTERNE_8;

              }
              else if ((VSCtl_strConvTraIntno1ModClc ==
                          VSCTL_STRCONVTRAINTNO1MODCLC_NOMINAL_5) &&
                         (VSCtl_strConvTraExtModClc !=
                          VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4))
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE1;
                VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_INTERNE1_8;

              }
              else if (((VSCtl_strConvTraIntno2ModClc ==
                           VSCTL_STRCONVTRAINTNO2MODCLC_NOMINAL_6) &&
                          (VSCtl_strConvTraExtModClc !=
                           VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4)) &&
                         (VSCtl_strConvTraIntno1ModClc !=
                          VSCTL_STRCONVTRAINTNO1MODCLC_NOMINAL_5))
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE2;
                VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_INTERNE2_8;
              }
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE1:
              if ((VSCtl_strConvTraIntno1ModClc !=
                   VSCTL_STRCONVTRAINTNO1MODCLC_NOMINAL_5) ||
                  (VSCtl_strConvTraExtModClc ==
                   VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4))
              {
                VSCtl_tirConvTra = VSCtl_tirConvTra_C;
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g;
                VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_INIT_8;

              }
              else
              {
                VSCtl_tirConvTra = (UInt16)DDS_M_MAX(VSCtl_tirConvTra - 1, 0);
              }
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INTERNE2:
              if (((VSCtl_strConvTraIntno2ModClc !=
                    VSCTL_STRCONVTRAINTNO2MODCLC_NOMINAL_6) ||
                   (VSCtl_strConvTraExtModClc ==
                    VSCTL_STRCONVTRAEXTMODCLC_NOMINAL_4)) ||
                  (VSCtl_strConvTraIntno1ModClc ==
                   VSCTL_STRCONVTRAINTNO1MODCLC_NOMINAL_5))
              {
                VSCtl_tirConvTra = VSCtl_tirConvTra_C;
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g;
                VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_INIT_8;

              }
              else
              {
                VSCtl_tirConvTra = (UInt16)DDS_M_MAX(VSCtl_tirConvTra - 1, 0);
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VERIF_if:
          if ((VSCtl_stDiagrConvTra == VSCTL_STDIAGRCONVTRA_DEFAUT_34)
          ||
              (VSCtl_stTraInfo == VSCTL_STTRAINFO_DEFAUT_3))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DEFAUT_po;
            VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_DEFAUT_8;
            VSCtl_tirConvTra = 0U;

          }
          else if ((VSCtl_stDiagrConvTra != VSCTL_STDIAGRCONVTRA_DEFAUT_34)
          &&
                     (VSCtl_stTraInfo == VSCTL_STTRAINFO_NOMINAL_3))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NOMINAL_f;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_INIT_g;
            VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_INIT_8;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_REFERENCE = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_c;
      VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_ARRET;
      VSCtl_tirConvTra = 0U;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1122215_Determiner_Mode_Calcul_Taux_Conversion_Couple_Reference*/

  VSINFO_F112222_Determiner_Taux_Conversion_Couple(Ext_nEng_swc_in, /* BIN0 */
                                                    Ext_nFrntWhl_swc_in, /* BIN7 */
                                                    Ext_spdFrntWhl_swc_in, /* BIN7 */
                                                    CoPt_rCnvTq_swc_in, /* BIN7 */
                                                    VSCtl_rdWhl_swc_in, /* BIN7 */
                                                    VSCtl_spdVeh_swc_in, /* BIN7 */
                                                    &vsinfo_vsctl_grdratconvtra_cpy, /* BIN1 */
                                                    &vsinfo_vsctl_rconvtra_cpy /* BIN7 */);


  VSINFO_F11223_Determiner_Couple_Perte_BV(TqCmp_tqCnvLoss_swc_in, /* BIN4 */
                                           &vsinfo_vsctl_tqlosstra_cpy /* BIN4 */);


  VSINFO_F11233_Determiner_Couples_Roue_Gmp(vsinfo_vsctl_rconvtra_cpy, /* BIN7 */
                                            vsinfo_vsctl_tqckefcdrvmaxreq_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqckefcdrvminreq_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqckefcmaxnotctla_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqckefcmax_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqckefcminnotctla_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqckefcmin_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqckefcprecovscminreq_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqckefcprecovsctlreq_cpy, /* BIN4 */
                                            vsinfo_vsctl_tqlosstra_cpy /* BIN4 */);


  VSINFO_F11234_Determiner_Potentiels_Couple_Roue_Gmp(VSCtl_tqWhlPotMaxRsvHiThd_swc_in, /* BIN1 */
                                                    VSCtl_tqWhlPotMaxRsvLoThd_swc_in, /* BIN1 */
                                                    VSCtl_tqWhlPotMinRsvHiThd_swc_in, /* BIN1 */
                                                    VSCtl_tqWhlPotMinRsvLoThd_swc_in  /* BIN1 */);


  VSINFO_F11236_Determiner_Consigne_Couple_Roue_Gmp_Normee();

  /* TAG_START_OF_STATEFLOW_FUNCTION: F11232_Determiner_Disponibilite_Couple_Roue_GMP*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.184.3 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c169_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c169_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c169_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_COUPLE_ROUE;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_i;
    VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
    VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
    VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE)
          {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_i:
      if ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM) && (VSCtl_stEngInfo ==
           VSCTL_STENGINFO_NOMINAL_2))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVM;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVM = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1;
        VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
        VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

      }
      else if ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVMP)
      && (VSCtl_stEngInfo ==
                  VSCTL_STENGINFO_NOMINAL_2))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVMP;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVMP = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1;
        VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
        VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

      }
      else if ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVA)
      && (VSCtl_stEngInfo ==
                  VSCTL_STENGINFO_NOMINAL_2))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVA;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVA = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1;
        VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
        VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVA:
      if ((Ext_stGBxCf_swc_in != EXT_STGBXCF_BVA) || (VSCtl_stEngInfo !=
           VSCTL_STENGINFO_NOMINAL_2))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVA = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c
          = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_i;
        VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVA)
      {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1:
          if (((VSCtl_stEngInfo == VSCTL_STENGINFO_NOMINAL_2) &&
               (CoPt_noEgdGearCordIt_swc_in != COPT_NOEGDGEARCORDIT_NEUTRE))
               &&
              ((CoPt_posnLev_swc_in != COPT_POSNLEV_N) || (Ext_bPosnGBxCf_swc_in !=
                EXT_BPOSNGBXCF_PRESENT)))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVA = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2_ET_DISPONIBILITE_3;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c
              = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2;
            VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
            VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2_ET_DISPONIBILITE_3:
          if ((CoPt_noEgdGearCordIt_swc_in == COPT_NOEGDGEARCORDIT_NEUTRE)
          ||
              ((CoPt_posnLev_swc_in == COPT_POSNLEV_N) && (Ext_bPosnGBxCf_swc_in ==
                EXT_BPOSNGBXCF_PRESENT)))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c
              = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVA = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1;
            VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
            VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
            VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

          }
          else
          {
            switch
              (vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c)
            {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2:
              if (CoPt_bSIPCord_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c
                  = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_3;
                VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
              }
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_3:
              if (CoPt_bSIPCord_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c
                  = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2;
                VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
                VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
              }
              break;
            }
          }
          break;
        }
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVM:
      if ((Ext_stGBxCf_swc_in != EXT_STGBXCF_BVM) || (VSCtl_stEngInfo !=
           VSCTL_STENGINFO_NOMINAL_2))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVM = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3 =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_i;
        VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVM)
              {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1:
          if ((VSCtl_stEngInfo == VSCTL_STENGINFO_NOMINAL_2) &&
              (CoPt_noEgdGearCordIt_swc_in != COPT_NOEGDGEARCORDIT_NEUTRE))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVM = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2_ET_DISPONIBILITE_3;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3
              = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2;
            VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
            VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2_ET_DISPONIBILITE_3:
          if (CoPt_noEgdGearCordIt_swc_in == COPT_NOEGDGEARCORDIT_NEUTRE)
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3
              = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVM = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1;
            VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
            VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
            VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

          }
          else
          {
            switch
              (vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3)
            {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2:
              if (Ext_bCluPedPrss_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3
                  = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_3;
                VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
              }
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_3:
              if (Ext_bCluPedPrss_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3
                  = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2;
                VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
                VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
              }
              break;
            }
          }
          break;
        }
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CONFIG_BVMP:
      if ((Ext_stGBxCf_swc_in != EXT_STGBXCF_BVMP) || (VSCtl_stEngInfo !=
           VSCTL_STENGINFO_NOMINAL_2))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVMP = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck
          = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE =
          (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_i;
        VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
        VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

      }
      else
      {
        switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVMP)
              {
         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1:
          if ((((VSCtl_stEngInfo == VSCTL_STENGINFO_NOMINAL_2) &&
                (CoPt_noEgdGearCordIt_swc_in != COPT_NOEGDGEARCORDIT_NEUTRE))
                &&
               ((CoPt_posnLev_swc_in != COPT_POSNLEV_N)
               || (Ext_bPosnGBxCf_swc_in !=
                 EXT_BPOSNGBXCF_PRESENT)))
                 && (((VSCtl_bCluEnaAvlTqWhl_C ==
                 VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow)
                 || (CoPt_stClu_swc_in !=
                 COPT_STCLU_OUVERT)) || (CoPt_bSIPCord_swc_in ==
                VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr)))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVMP = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2_ET_DISPONIBILITE_3;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck
              = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2;
            VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
            VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
          }
          break;

         case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2_ET_DISPONIBILITE_3:
          if (((CoPt_noEgdGearCordIt_swc_in == COPT_NOEGDGEARCORDIT_NEUTRE)
          ||
               ((CoPt_posnLev_swc_in == COPT_POSNLEV_N)
               && (Ext_bPosnGBxCf_swc_in ==
                 EXT_BPOSNGBXCF_PRESENT)))
                 || (((VSCtl_bCluEnaAvlTqWhl_C ==
                 VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr)
                 && (CoPt_stClu_swc_in ==
                 COPT_STCLU_OUVERT)) && (CoPt_bSIPCord_swc_in ==
                VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow)))
          {
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck
              = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_NO_ACTIVE_CHILD_p;
            vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVMP = (UInt8)
              VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_1;
            VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
            VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
            VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;

          }
          else
          {
            switch
              (vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck)
            {
             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2:
              if (CoPt_bSIPCord_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck
                  = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_3;
                VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
              }
              break;

             case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_3:
              if (CoPt_bSIPCord_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr)
              {
                vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck
                  = (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_DISPONIBILITE_2;
                VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_dr;
                VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
              }
              break;
            }
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_ARRET_i;
      VSCtl_bAvlTqWhlPt2_no1 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
      VSCtl_bAvlTqWhlPt2_no2 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
      VSCtl_bAvlTqWhlPt2_no3 = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_ow;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F11232_Determiner_Disponibilite_Couple_Roue_GMP*/

  VSINFO_F11235_Determiner_Pilotabilite_Couple_Roue_Gmp(InjSys_bFuCutOff_swc_in);


  VSINFO_F11237_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar();

  /* TAG_START_OF_STATEFLOW_FUNCTION: F11224_Determiner_Changement_Rapport_Engage*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.153.1 */

  if (vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c167_VSINFO_Ela_Gmp2_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c167_VSINFO_Ela_Gmp2_Re002tev_Sf
      = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_c167_VSINFO_Ela_Gmp2_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp2_Re002tev_Sf_IN_CHANGEMENT_RAPPORT_ENGAGE;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_CHANGEMENT_RAPPORT = 1U;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
      VSINFO_Ela_Gmp2_Re002tev_Sf_IN_FAUX;
    vsinfo_vsctl_bnbgearegdchg_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_l;
    VSCtl_tiCfmGearChg_Ext = VSCtl_tiCfm_bGearChgExt_C;
    vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_MEMOIRES = 1U;

  }
  else
  {
    switch (vsinfo_ela_gmp2_re002tev_sf_dwork.is_CHANGEMENT_RAPPORT)
              {
     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_FAUX:
      if (((VSCtl_stTraInfo == VSCTL_STTRAINFO_NOMINAL_3) &&
           (FRM_bDeacVSCtlNoGearChgClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_l))
           &&
          ((CoPt_noEgdGearCordIt_swc_in == 0)
          || (((CoPt_noEgdGearCordIt_swc_in != 0)
          &&
             (vsinfo_ela_gmp2_re002tev_sf_b.VSCtl_noGearEgdPrev_c != 0))
             &&
            (CoPt_noEgdGearCordIt_swc_in !=
             vsinfo_ela_gmp2_re002tev_sf_b.VSCtl_noGearEgdPrev_c))))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VRAI;
        vsinfo_vsctl_bnbgearegdchg_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_k;
      }
      break;

     case VSINFO_Ela_Gmp2_Re002tev_Sf_IN_VRAI:
      if (((VSCtl_stTraInfo != VSCTL_STTRAINFO_NOMINAL_3) ||
           (FRM_bDeacVSCtlNoGearChgClc_swc_in == VSINFO_Ela_Gmp2_Re002tev_Sf_VRAI_k))
           ||
          ((VSCtl_tiCfmGearChg_Ext == 0)
          && (((CoPt_noEgdGearCordIt_swc_in != 0)
          &&
             (vsinfo_ela_gmp2_re002tev_sf_b.VSCtl_noGearEgdPrev_c == 0))
             ||
            ((CoPt_noEgdGearCordIt_swc_in != 0) && (CoPt_noEgdGearCordIt_swc_in ==
              vsinfo_ela_gmp2_re002tev_sf_b.VSCtl_noGearEgdPrev_c)))))
      {
        vsinfo_ela_gmp2_re002tev_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
          VSINFO_Ela_Gmp2_Re002tev_Sf_IN_FAUX;
        vsinfo_vsctl_bnbgearegdchg_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_l;
        VSCtl_tiCfmGearChg_Ext = VSCtl_tiCfm_bGearChgExt_C;

      }
      else
      {
        VSCtl_tiCfmGearChg_Ext = (UInt16)DDS_M_MAX(VSCtl_tiCfmGearChg_Ext - 1, 0);
      }
      break;

     default:
      vsinfo_ela_gmp2_re002tev_sf_dwork.is_CHANGEMENT_RAPPORT = (UInt8)
        VSINFO_Ela_Gmp2_Re002tev_Sf_IN_FAUX;
      vsinfo_vsctl_bnbgearegdchg_cpy = VSINFO_Ela_Gmp2_Re002tev_Sf_FAUX_l;
      VSCtl_tiCfmGearChg_Ext = VSCtl_tiCfm_bGearChgExt_C;
      break;
    }

    vsinfo_ela_gmp2_re002tev_sf_b.VSCtl_noGearEgdPrev_c = CoPt_noEgdGearCordIt_swc_in;
  }

  VSCtl_noGearEgdPrev = DDS_M_LIMIT
    (vsinfo_ela_gmp2_re002tev_sf_b.VSCtl_noGearEgdPrev_c,
     VSCTL_NOGEAREGDPREV_MIN,
     VSCTL_NOGEAREGDPREV_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F11224_Determiner_Changement_Rapport_Engage*/

  VSINFO_F11213_Determiner_Regime_Moteur_Filtree(Ext_nEng_swc_in, /* BIN0 */
                                                &vsinfo_vsctl_nengfil_cpy /* BIN0 */);

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_nEngFil_swc_out = vsinfo_vsctl_nengfil_cpy;

  *VSCtl_grdRatConvTra_swc_out = vsinfo_vsctl_grdratconvtra_cpy;

  *VSCtl_tqCkEfcDrvMaxReq_swc_out = vsinfo_vsctl_tqckefcdrvmaxreq_cpy;

  *VSCtl_tqCkEfcDrvMinReq_swc_out = vsinfo_vsctl_tqckefcdrvminreq_cpy;

  *VSCtl_tqCkEfcMax_swc_out = vsinfo_vsctl_tqckefcmax_cpy;

  *VSCtl_tqCkEfcMaxNotCtla_swc_out = vsinfo_vsctl_tqckefcmaxnotctla_cpy;

  *VSCtl_tqCkEfcMin_swc_out = vsinfo_vsctl_tqckefcmin_cpy;

  *VSCtl_tqCkEfcMinNotCtla_swc_out = vsinfo_vsctl_tqckefcminnotctla_cpy;

  *VSCtl_tqCkEfcPreCoVSCMinReq_swc_out = vsinfo_vsctl_tqckefcprecovscminreq_cpy;

  *VSCtl_tqCkEfcPreCoVSCtlReq_swc_out = vsinfo_vsctl_tqckefcprecovsctlreq_cpy;

  *VSCtl_tqLossTra_swc_out = vsinfo_vsctl_tqlosstra_cpy;

  *VSCtl_rConvTra_swc_out = vsinfo_vsctl_rconvtra_cpy;

  *VSCtl_bDgoRatConvTraClc_swc_out = vsinfo_vsctl_bdgoratconvtraclc_cpy;

  *VSCtl_bMonRunRatConvTraClc_swc_out = vsinfo_vsctl_bmonrunratconvtraclc_cpy;

  *VSCtl_bNbGearEgdChg_swc_out = vsinfo_vsctl_bnbgearegdchg_cpy;


  vsinfo_ela_gmp2_re002tev_delay_0 = VSCtl_stDiagrConvTra;
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp2_Re002tev_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMin_swc_out,                             /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMax_swc_out,                             /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMinReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMaxReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqLossTra_swc_out,                              /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCtlReq_swc_out,                   /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rConvTra_swc_out,                               /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_grdRatConvTra_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCMinReq_swc_out,                  /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bNbGearEgdChg_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nEngFil_swc_out)                                /*BIN0*/
{
    VSINFO_Elabor_Info_Gmp2_Sl_Init();

    VSINFO_Get_Info_Gmp2_Sl_Init(VSCtl_tqCkEfcDrvMaxReq_swc_out, /* BIN4 */
                                    VSCtl_tqCkEfcDrvMinReq_swc_out, /* BIN4 */
                                    VSCtl_tqCkEfcMax_swc_out, /* BIN4 */
                                    VSCtl_tqCkEfcMaxNotCtla_swc_out, /* BIN4 */
                                    VSCtl_tqCkEfcMin_swc_out, /* BIN4 */
                                    VSCtl_tqCkEfcMinNotCtla_swc_out, /* BIN4 */
                                    VSCtl_tqCkEfcPreCoVSCMinReq_swc_out, /* BIN4 */
                                    VSCtl_tqCkEfcPreCoVSCtlReq_swc_out, /* BIN4 */
                                    VSCtl_nEngFil_swc_out /* BIN0 */);

    VSINFO_Info_Transmission_Sl_Init(VSCtl_grdRatConvTra_swc_out, /* BIN1 */
                                        VSCtl_rConvTra_swc_out, /* BIN7 */
                                        VSCtl_tqLossTra_swc_out /* BIN4 */);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  vsinfo_vsctl_tqckefcmaxnotctla_cpy = *VSCtl_tqCkEfcMaxNotCtla_swc_out;

  vsinfo_ela_gmp2_re002tev_sf_b.vsi_Keep_Global_Data_From_Input=0;
  vsinfo_ela_gmp2_re002tev_sf_b.vsi_Keep_Global_Data_From_Input_c=0;
  vsinfo_vsctl_grdratconvtra_cpy = *VSCtl_grdRatConvTra_swc_out;

  vsinfo_vsctl_nengfil_cpy = *VSCtl_nEngFil_swc_out;

  vsinfo_vsctl_tqlosstra_cpy = *VSCtl_tqLossTra_swc_out;

  vsinfo_vsctl_tqckefcminnotctla_cpy = *VSCtl_tqCkEfcMinNotCtla_swc_out;

  vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION=0;
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiIniPTClc_pt2 = VSCtl_tiIni_PTInfo_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiCfmGearChg_Ext = VSCtl_tiCfm_bGearChgExt_C;   /* Replaced by Post task */     /* Init from Model */
  VSCtl_tirConvTra = ((UInt16)0U);
  VSCtl_tiIni_rConvTraIntno2 = VSCtl_tiIni_rConvTraIntno2_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIni_rConvTraIntno1 = VSCtl_tiIni_rConvTraIntno1_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIni_rConvTraExt = VSCtl_tiIni_rConvTraExt_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIniTraClc = VSCtl_tiIni_TraInfo_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIniEngClc = VSCtl_tiIni_EngInfo_C;    /* Replaced by Post task */     /* Init from Model */
  vsinfo_vsctl_tqckefcprecovscminreq_cpy = *VSCtl_tqCkEfcPreCoVSCMinReq_swc_out;

  vsinfo_vsctl_tqckefcmin_cpy = *VSCtl_tqCkEfcMin_swc_out;

  vsinfo_vsctl_tqckefcmax_cpy = *VSCtl_tqCkEfcMax_swc_out;

  vsinfo_vsctl_tqckefcprecovsctlreq_cpy = *VSCtl_tqCkEfcPreCoVSCtlReq_swc_out;

  vsinfo_vsctl_tqckefcdrvminreq_cpy = *VSCtl_tqCkEfcDrvMinReq_swc_out;

  vsinfo_vsctl_tqckefcdrvmaxreq_cpy = *VSCtl_tqCkEfcDrvMaxReq_swc_out;

  vsinfo_vsctl_rconvtra_cpy = *VSCtl_rConvTra_swc_out;

  VSCtl_stPTInfo_pt2 = VSCTL_STPTINFO_PT2_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_noGearEgdPrev = ((UInt8)0U);
  VSCtl_strConvTraModClc = VSCTL_STRCONVTRAMODCLC_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stDiagrConvTra = VSCTL_STDIAGRCONVTRA_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_strConvTraIntno2ModClc = VSCTL_STRCONVTRAINTNO2MODCLC_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_strConvTraIntno1ModClc = VSCTL_STRCONVTRAINTNO1MODCLC_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_strConvTraExtModClc = VSCTL_STRCONVTRAEXTMODCLC_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stTraInfo = VSCTL_STTRAINFO_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stEngInfo = VSCTL_STENGINFO_ARRET;  /* Replaced by Post task */     /* Init from Model */


  vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_MOTEUR = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_g = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_g = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c160_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c160_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  VSCtl_bAcvFilEngInfo =DDS_FALSE;


  vsinfo_ela_gmp2_re002tev_delay_0 = VSINFO_ELA_GMP2_RE002TEV_CONST_0;


  vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_TRANSMISSION = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_og = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_f = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c161_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c161_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  VSCtl_bAcvFilTraInfo =DDS_FALSE;



  vsinfo_ela_gmp2_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_2 = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_e = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_VERIF = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c168_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c168_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;

  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_EXTERNE = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_f = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_n = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c162_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c162_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  VSCtl_bAcvFil_rConvTraExt =DDS_FALSE;



  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE1 = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_m = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT_c = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c163_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c163_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  VSCtl_bAcvFil_rConvTraInt1 =DDS_FALSE;



  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_INTERNE2 = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_li = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_PAS_DEFAUT = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c164_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c164_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  VSCtl_bAcvFil_rConvTraInt2 =DDS_FALSE;



  vsinfo_ela_gmp2_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
    = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_l = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c165_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c165_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  *VSCtl_bDgoRatConvTraClc_swc_out =DDS_FALSE;
  vsinfo_vsctl_bdgoratconvtraclc_cpy = *VSCtl_bDgoRatConvTraClc_swc_out;

  *VSCtl_bMonRunRatConvTraClc_swc_out =DDS_FALSE;
  vsinfo_vsctl_bmonrunratconvtraclc_cpy = *VSCtl_bMonRunRatConvTraClc_swc_out;




  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MODE_CALCUL_TCC_REFERENCE = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_MARCHE_o = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_NOMINAL = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c166_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c166_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;



  vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_COUPLE_ROUE = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVA = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_c = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVM = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3 = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_CONFIG_BVMP = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_DISPONIBILITE_2_ET_DISPONIBILITE_3_ck =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c169_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c169_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  VSCtl_bAvlTqWhlPt2_no1 =DDS_FALSE;
  VSCtl_bAvlTqWhlPt2_no2 =DDS_FALSE;
  VSCtl_bAvlTqWhlPt2_no3 =DDS_FALSE;



  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_CHANGEMENT_RAPPORT = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_CHANGEMENT_RAPPORT = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_MEMOIRES = 0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_active_c167_VSINFO_Ela_Gmp2_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp2_re002tev_sf_dwork.is_c167_VSINFO_Ela_Gmp2_Re002tev_Sf = 0U;
  *VSCtl_bNbGearEgdChg_swc_out =DDS_FALSE;
  vsinfo_vsctl_bnbgearegdchg_cpy = *VSCtl_bNbGearEgdChg_swc_out;

  vsinfo_ela_gmp2_re002tev_sf_b.VSCtl_noGearEgdPrev_c = 0;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

