/*
* File: VSREG_Ctrl_Spd_Veh_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSREG_Ctrl_Spd_Veh_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Mon Nov 21 11:12:04 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Mon Nov 21 11:12:05 2011
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
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Ctrl_Spd_Veh_Sf.c
* Version int :/main/L02_01/1 Date: 5/1/2012 11 h 23 m User:esnault 
*    TWK_model:VSREG_Ctrl_Spd_Veh_Sf_L02_010_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_halouane_vsreg_euro6\1 Date: 4/1/2012 15 h 47 m User:halouane 
*    TWK_model:VSREG_Ctrl_Spd_Veh_Sf_L02_010_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 21/11/2011 11 h 23 m User:demezil
*    TWK_model:VSREG_Ctrl_Spd_Veh_Sf_L02_010_IMPL1
*    comments :for VSReg 12.0 : rename Ext_noGearEgd in CoPt_noEgdGearCordIt
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_SUB_FUNCTION: F2212_Determiner_Consigne_Vitesse_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F2212_Determiner_Consigne_Vitesse_Vehicule ;CoPt_noEgdGearCordIt;Ext_spdVehVSRegReq;VSCtl_bAcvFilSpdVehVSReg;VSCtl_spdVeh;VSCtl_stFilSpdVehVSReg;VSCtl_stSatMaxSpdVehVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2212_Determiner_Consigne_Vitesse_Vehicule ;VSCtl_spdVehErrVSReg;VSCtl_spdVehErrVSRegRaw;VSCtl_spdVehVSRegReqFil;VSCtl_spdVehVSRegReqFilRaw; */
/* TAG_END_OF_SUB_FUNCTION: F2212_Determiner_Consigne_Vitesse_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F222221_Determiner_Saturation_Acceleration_Vehicule_Max */
/* TAG_INPUT_OF_SUB_FUNCTION: F222221_Determiner_Saturation_Acceleration_Vehicule_Max ;VSCtl_aVehPTMax;VSCtl_spdVehErrVSReg;VSCtl_spdVehVSRegReqFil;VSCtl_stCtl_aVehVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F222221_Determiner_Saturation_Acceleration_Vehicule_Max ;VSCtl_aVehVSRegReqSatMax;VSCtl_aVehVSRegReqSatMaxAbs;VSCtl_aVehVSRegReqSatMaxCft; */
/* TAG_END_OF_SUB_FUNCTION: F222221_Determiner_Saturation_Acceleration_Vehicule_Max */

/* TAG_START_OF_SUB_FUNCTION: F222222_Determiner_Saturation_Acceleration_Vehicule_Min */
/* TAG_INPUT_OF_SUB_FUNCTION: F222222_Determiner_Saturation_Acceleration_Vehicule_Min ;VSCtl_aVehPTMin;VSCtl_spdVehErrVSReg;VSCtl_spdVehVSRegReqFil;VSCtl_stCtl_aVehVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F222222_Determiner_Saturation_Acceleration_Vehicule_Min ;VSCtl_aVehVSRegReqSatMin;VSCtl_aVehVSRegReqSatMinAbs;VSCtl_aVehVSRegReqSatMinCft; */
/* TAG_END_OF_SUB_FUNCTION: F222222_Determiner_Saturation_Acceleration_Vehicule_Min */

/* TAG_START_OF_SUB_FUNCTION: F22223_Determiner_Saturations_Jerk_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F22223_Determiner_Saturations_Jerk_Vehicule ;VSCtl_aVehPreCoVSCtlReq;VSCtl_aVehReq;VSCtl_aVehVSRegReqSatMax;VSCtl_aVehVSRegReqSatMin;VSCtl_rTqWhlPTDrvReq;VSCtl_stCtl_aVehVSReg;VSCtl_stSatJrkVehMinVSReg;VSCtl_tiFilStCtlAVehVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F22223_Determiner_Saturations_Jerk_Vehicule ;VSCtl_jrkVehVSRegSatMax;VSCtl_jrkVehVSRegSatMaxAbs;VSCtl_jrkVehVSRegSatMaxCvg;VSCtl_jrkVehVSRegSatMin;VSCtl_jrkVehVSRegSatMinAbs;VSCtl_jrkVehVSRegSatMinCrit;VSCtl_jrkVehVSRegSatMinCvg;VSCtl_jrkVehVSRegSatMinTran; */
/* TAG_END_OF_SUB_FUNCTION: F22223_Determiner_Saturations_Jerk_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F22224_Determiner_Gabarits_Acceleration_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F22224_Determiner_Gabarits_Acceleration_Vehicule ;VSCtl_aVehPTIni;VSCtl_aVehPTMax;VSCtl_aVehPTMin;VSCtl_aVehReq;VSCtl_aVehVSRegReqSatMax;VSCtl_aVehVSRegReqSatMin;VSCtl_bAcvCtlAVehVSReg;VSCtl_jrkVehVSRegSatMax;VSCtl_jrkVehVSRegSatMin;VSCtl_stCtl_aVehVSReg;VSCtl_stSatAVehMinVSReg;VSCtl_stSatJrkVehMinVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F22224_Determiner_Gabarits_Acceleration_Vehicule ;VSCtl_aVehVSRegReqMax;VSCtl_aVehVSRegReqMin;VSCtl_aVehVSRegReqSatMaxApl;VSCtl_aVehVSRegReqSatMinApl; */
/* TAG_END_OF_SUB_FUNCTION: F22224_Determiner_Gabarits_Acceleration_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F22232_Determiner_Consigne_Acceleration_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F22232_Determiner_Consigne_Acceleration_Vehicule ;VSCtl_aVehVSRegReqMax;VSCtl_aVehVSRegReqMin;VSCtl_bAcvFil_aVehVSReg;VSCtl_rSpdVehCtlVSRegDyn;VSCtl_spdVehErrVSReg;VSCtl_stCtl_aVehVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F22232_Determiner_Consigne_Acceleration_Vehicule ;VSCtl_aVehVSRegReq;VSCtl_aVehVSRegReqRaw;VSCtl_jrkVehVSRegReq; */
/* TAG_END_OF_SUB_FUNCTION: F22232_Determiner_Consigne_Acceleration_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule ;VSCtl_aVehVSRegReqSatMax;VSCtl_aVehVSRegReqSatMin;VSCtl_bAcvFil_aVehPotVSReg;VSCtl_bCtl_aVehPotVSReg;VSCtl_spdVeh;VSCtl_spdVehErrVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule ;VSCtl_aVehPotVSRegReq;VSCtl_aVehPotVSRegReqOft;VSCtl_aVehPotVSRegReqRaw;VSCtl_jrkVehPotVSRegReq; */
/* TAG_END_OF_SUB_FUNCTION: F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP ;VSCtl_bCtl_aVehPotVSReg;VSCtl_spdVehErrVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP ;VSCtl_rCtlTqWhlPTPotVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP */

/* TAG_START_OF_SUB_FUNCTION: F2234_Determiner_Temps_Confirmation_Changement_Rapport */
/* TAG_INPUT_OF_SUB_FUNCTION: F2234_Determiner_Temps_Confirmation_Changement_Rapport ;VSCtl_aVehPotVSRegReq;VSCtl_bAcvFil_aVehPotVSReg;VSCtl_bCtl_aVehPotVSReg;VSCtl_bDynCtlSpdVehVSReg;VSCtl_jrkVehPotVSRegReq;VSCtl_spdVeh;VSCtl_spdVehErrVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2234_Determiner_Temps_Confirmation_Changement_Rapport ;VSCtl_tiCfmSdwnVSRegReq;VSCtl_tiCfmSdwnVSRegReqRaw1;VSCtl_tiCfmSdwnVSRegReqRaw2;VSCtl_tiCfmSdwnVSRegReqRaw3;VSCtl_tiCfmSupVSRegReq;VSCtl_tiCfmSupVSRegReqRaw1;VSCtl_tiCfmSupVSRegReqRaw2;VSCtl_tiCfmSupVSRegReqRaw3; */
/* TAG_END_OF_SUB_FUNCTION: F2234_Determiner_Temps_Confirmation_Changement_Rapport */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Vitesse_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Vitesse_Vehicule ;Ext_spdVehVSRegReq;Ext_stGBxCf;FRM_bDeacSatMaxSpdVehVSReg;VSCtl_spdVeh;VSCtl_spdVehVSRegReqFil;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Vitesse_Vehicule ;VSCtl_bAcvFilSpdVehVSReg;VSCtl_bInhFilSpdVehVSRegReq;VSCtl_spdVehVSRegReqPrev;VSCtl_stFilSpdVehVSReg;VSCtl_stSatMaxSpdVehVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Consigne_Vitesse_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule ;VSCtl_aVehReq;VSCtl_aVehVSRegReqSatMin;VSCtl_stCtl_aVehVSReg;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule ;VSCtl_stRegVSRegPrev_VSReg;VSCtl_stSatAVehMinVSReg;VSCtl_stSatJrkVehMinVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Gabarits_Acceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration ;VSCtl_bEndTranVSReg;VSCtl_bFastDeacVSRegReq;VSCtl_stVSCtlInfo;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration ;VSCtl_bAcvCtlAVehVSReg;VSCtl_bAcvFil_aVehVSReg;VSCtl_stCtlAVehVSRegPrev;VSCtl_stCtl_aVehVSReg;VSCtl_tiFilStCtlAVehVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Acceleration */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule ;Ext_stCtlCmdPTTqPotCf;VSCtl_spdVehErrVSReg;VSCtl_stCtl_aVehVSReg;VSCtl_stVSCtlInfo;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule ;VSCtl_bAcvFil_aVehPotVSReg;VSCtl_bCtl_aVehPotVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Commande_Potentiel_Acceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Modes_Controle_Vitesse_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Vitesse_Vehicule ;VSCtl_spdVehErrVSReg;VSCtl_stCtl_aVehVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Vitesse_Vehicule ;VSCtl_bDynCtlSpdVehVSReg;VSCtl_rSpdVehCtlVSRegDyn;VSCtl_tiFilSpdVehCtlVSRegDyn; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Modes_Controle_Vitesse_Vehicule */

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
#define VSCTL_STSATAVEHMINVSREGMOD_C_COMPLET    (1)
#define VSCTL_STCTLAVEHVSREGPREV_CONTROLE       (1)
#define VSCTL_STCTLAVEHVSREGPREV_ARRET          (0)
#define VSCTL_BCTL_AVEHPOTVSREG_ARRET           (0)
#define VSCTL_BCTL_AVEHPOTVSREG_CONTROLE        (1)
#define VSCTL_STREGVSREGPREV_VSREG_ARRET        (0)

/* Ext_stCtlCmdPTTqPotCf */
#define EXT_STCTLCMDPTTQPOTCF_RAPPORT           (3)
#define EXT_STCTLCMDPTTQPOTCF_COUPLE            (2)
#define EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED       (1)


/* VSCtl_bDynCtlSpdVehVSReg */
#define VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE    (0)
#define VSCTL_BDYNCTLSPDVEHVSREG_STABILISE      (1)

/* VSCtl_stSatMaxSpdVehVSReg */
#define VSCTL_STSATMAXSPDVEHVSREG_ARRET         (0)
#define VSCTL_STSATMAXSPDVEHVSREG_CONTROLE      (1)

/* VSCtl_stFilSpdVehVSReg */
#define VSCTL_STFILSPDVEHVSREG_ARRET            (0)
#define VSCTL_STFILSPDVEHVSREG_NON_FILTREE      (1)
#define VSCTL_STFILSPDVEHVSREG_FILTREE          (2)

/* VSCtl_stCtl_aVehVSReg */
#define VSCTL_STCTL_AVEHVSREG_ARRET             (0)
#define VSCTL_STCTL_AVEHVSREG_CONTROLE          (1)
#define VSCTL_STCTL_AVEHVSREG_TRANSITION        (2)

/*VSCtl_stVSRegExtd */
#define VSCTL_STVSREGEXTD_ANE                   (4)
#define VSCTL_STVSREGEXTD_AE                    (5)
#define VSCTL_STVSREGEXTD_REPRISE               (6)

/* Ext_stGBxCf */
#define EXT_STGBXCF_BVM                         (0)

/* VSCtl_stVSCtlInfo */
#define VSCTL_STVSCTLINFO_NOMINAL               (3)
/************************************************************/

/* Named constants for block: /Mode_Commande_Acceleration' */
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_d (0)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_k (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_TRANSITION (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_e (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_HORS_CONTROLE (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX_f (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_COMMANDE_ACCELERATION (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_VRAI_i (2)
#define VSREG_Ctrl_Spd_Veh_Sf_VRAI_k   (1U)
#define VSREG_Ctrl_Spd_Veh_Sf_FAUX_j   (0U)

/* Named constants for block: /Mode_Calcul_Consigne_Vitesse_Vehicule' */
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NON_FILTREE (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_CALCUL_CONSIGNE_VITESSE_VEHICULE (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_FILTREE (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX  (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_VRAI  (2)
#define VSREG_Ctrl_Spd_Veh_Sf_FAUX     (0U)
#define VSREG_Ctrl_Spd_Veh_Sf_VRAI     (1U)

/* Named constants for block: /Mode_Commande_Potentiel_Acceleration_Vehicule' */
#define VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_g (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_p (2)
#define VSREG_Ctrl_Spd_Veh_Sf_VRAI_n   (1U)
#define VSREG_Ctrl_Spd_Veh_Sf_FAUX_d   (0U)

/* Named constants for block: /Modes_Controle_Vitesse_Vehicule' */
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_h (0)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_INIT  (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NON_INIT (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_BARYCENTRE_IN_1 (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF (4)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_CONF  (3)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_BARYCENTRE_IN_2 (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_MODES_CONTROLE_VITESSE_VEHICULE (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_STABILISE (3)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_TRANSITOIRE (4)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_CONF____0 (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF____0 (2)

/* Named constants for block: /Mode_Calcul_Gabarits_Acceleration_Vehicule' */
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_l (0)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_ey (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_CALCUL_GABARITS_ACCELERATION_VEHICULE (1)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF____0 (3)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF____0 (2)
#define VSREG_Ctrl_Spd_Veh_Sf_IN_ACTIVATION (1)
#define VSREG_Ctrl_Spd_Veh_Sf_VRAI_m   (1U)
#define VSREG_Ctrl_Spd_Veh_Sf_FAUX_jg  (0U)

/* Definition for custom storage class: Define */
#define VSCTL_RSPDVEHCTLVSREGDYN_MAX   12800U
#define VSCTL_SPDVEHVSREGREQPREV_MAX   32640U
#define VSREG_100_BIN7                 12800U
#define VSREG_CTRL_SPD_VEH_SF_CONST_0  0U
#define VSREG_CTRL_SPD_VEH_SF_CONST_1  (-10240)

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 16-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSRegReqFil;       /*BIN7*/
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMin;       /*BIN10*/
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"


/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 16-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_rSpdVehCtlVSRegDyn;       /*BIN7*/
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"


/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_tiFilStCtlAVehVSReg;       /*BIN0*/
VAR(UInt8, AUTOMATIC) VSCtl_stSatMaxSpdVehVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMinVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_stSatAVehMinVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_stFilSpdVehVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bDynCtlSpdVehVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehPotVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilSpdVehVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvCtlAVehVSReg;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt16 VSCtl_rSpdVehCtlVSRegDyn_f;
  UInt16 VSCtl_spdVehVSRegReqPrev_p;
} BlockIO_VSREG_Ctrl_Spd_Veh_Sf;


typedef struct {
  UInt32 is_NON_INIT : 3;
  UInt32 is_NON_INIT_j : 3;
  UInt32 is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE : 2;
  UInt32 is_LISSAGE_CONTROLE_VITESSE : 2;
  UInt32 is_CONDITION_CHANGEMENT_DYNAMIQUE : 2;
  UInt32 is_CONTROLE : 2;
  UInt32 is_JERK_MIN : 2;
  UInt32 is_CONTROLE_i : 2;
  UInt32 is_ACCEL_MIN : 2;
  UInt32 is_ETAT_CONTROLE_ACCELERATION : 2;
  UInt32 is_HORS_CONTROLE : 2;
  UInt32 is_INITIALISATION_CONTROLE_ACCELERATION : 2;
  UInt32 is_MODES_FILTRAGE : 2;
  UInt32 is_CONTROLE_d : 2;
  UInt32 is_INHIBITION_FILTRAGE : 2;
  UInt32 is_MODES_SATURATION_CONSIGNE_VITESSE : 2;
  UInt32 is_active_c89_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_c89_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_active_c88_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_c88_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_active_LISSAGE_CONTROLE_VITESSE : 1;
  UInt32 is_active_CONDITION_CHANGEMENT_DYNAMIQUE : 1;
  UInt32 is_active_c87_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_c87_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_active_JERK_MIN : 1;
  UInt32 is_active_MEMOIRES : 1;
  UInt32 is_active_ACCEL_MIN : 1;
  UInt32 is_active_c86_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_c86_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_active_ETAT_CONTROLE_ACCELERATION : 1;
  UInt32 is_active_INITIALISATION_CONTROLE_ACCELERATION : 1;
  UInt32 is_active_MEMORISATION : 1;
  UInt32 is_active_c85_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_c85_VSREG_Ctrl_Spd_Veh_Sf : 1;
  UInt32 is_active_MODES_FILTRAGE : 1;
  UInt32 is_active_MEMOIRES_c : 1;
  UInt32 is_active_INHIBITION_FILTRAGE : 1;
  UInt32 is_active_MODES_SATURATION_CONSIGNE_VITESSE : 1;
} D_Work_VSREG_Ctrl_Spd_Veh_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSRegReqPrev;               /*BIN7*/
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"


/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilSpdVehCtlVSRegDyn;            /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bInhFilSpdVehVSRegReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtlAVehVSRegPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stRegVSRegPrev_VSReg;
/* Static Visible area end */
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 8BIT-bits variable definition */
#define VSREG_START_SEC_VAR_8BIT
#include "VSReg_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_bctl_avehpotvsreg_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_stctl_avehvsreg_cpy;
#define VSREG_STOP_SEC_VAR_8BIT
#include "VSReg_MemMap.h"


/* 16BIT-bits variable definition */
#define VSREG_START_SEC_VAR_16BIT
#include "VSReg_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsreg_ctrl_spd_veh_sf_delay_1;
STATIC VAR(UInt16, AUTOMATIC) vsreg_ctrl_spd_veh_sf_delay_0;
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_avehpotvsregreq_cpy;                         /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_avehvsregreq_cpy;                            /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_spdveherrvsreg_cpy;                          /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsreg_vsctl_rctltqwhlptpotvsreg_cpy;                     /*BIN4*/
STATIC VAR(UInt16, AUTOMATIC) vsreg_vsctl_ticfmsdwnvsregreq_cpy;                       /*DEC2*/
STATIC VAR(UInt16, AUTOMATIC) vsreg_vsctl_ticfmsupvsregreq_cpy;                        /*DEC2*/
#define VSREG_STOP_SEC_VAR_16BIT
#include "VSReg_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSREG_START_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"
STATIC VAR(BlockIO_VSREG_Ctrl_Spd_Veh_Sf, AUTOMATIC) vsreg_ctrl_spd_veh_sf_b;
STATIC VAR(D_Work_VSREG_Ctrl_Spd_Veh_Sf, AUTOMATIC) vsreg_ctrl_spd_veh_sf_dwork;
/* Static Not Visible area end */
#define VSREG_STOP_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdERegAVehP_HysHiN_C = (CONST(SInt16, AUTOMATIC))(-32640); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdERegAVehP_HysHiP_C = (CONST(SInt16, AUTOMATIC))(32640); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdERegAVehP_HysLoN_C = (CONST(SInt16, AUTOMATIC))(-32640); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdERegAVehP_HysLoP_C = (CONST(SInt16, AUTOMATIC))(32640); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdErrVSRegSDyn_HysHi_C = (CONST(UInt16, AUTOMATIC))(192U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdErrVSRegSDyn_HysLo_C = (CONST(UInt16, AUTOMATIC))(128U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegReqImp_C = (CONST(UInt16, AUTOMATIC))(192U);   /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfm_rSDynCtlVSReg_C = (CONST(UInt16, AUTOMATIC))(256U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiDiCfm_rCtlTDynVSReg_C = (CONST(UInt16, AUTOMATIC))(512U); /*BIN7*/
#define VSREG_STOP_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"


/* 8BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiCfm_SDynCtlChgVSReg_C = (CONST(UInt8, AUTOMATIC))(1U);  /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDiCfmSDynCtlChgVSReg_C = (CONST(UInt8, AUTOMATIC))(7U); /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_stCtlAVehVSReg_C = (CONST(UInt8, AUTOMATIC))(74U);  /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiTol_DynCtlVSReg_C = (CONST(UInt8, AUTOMATIC))(49U);     /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegNGear_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegNGear_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegNGear_REP_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegPed_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegPed_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegPed_REP_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegTq_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegTq_ANE_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSRegTq_REP_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacImpDetVSReg_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacSatMaxSpdVehVSReg_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacStSatAVehMinVSReg_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stSatAVehMinVSRegMod_C = VSCTL_STSATAVEHMINVSREGMOD_C_COMPLET;
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

FUNC(void, AUTOMATIC) VSREG_Ctrl_Spd_Veh_Sf(UInt8 VSCtl_bEndTranVSReg_swc_in,
                               UInt8 Ext_stGBxCf_swc_in,
                               UInt8 FRM_bDeacSatMaxSpdVehVSReg_swc_in,
                               SInt16 VSCtl_aVehPTIni_swc_in,                              /*BIN10*/
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt16 VSCtl_rTqWhlPTDrvReq_swc_in,                         /*BIN7*/
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                          /*BIN0*/
                               SInt16 VSCtl_aVehReq_swc_in,                                /*BIN10*/
                               SInt16 VSCtl_aVehPTMin_swc_in,                              /*BIN10*/
                               UInt8 Ext_spdVehVSRegReq_swc_in,                            /*BIN0*/
                               SInt16 VSCtl_aVehPTMax_swc_in,                              /*BIN10*/
                               UInt8 VSCtl_stVSCtlInfo_swc_in,
                               SInt16 VSCtl_rSlop_swc_in,                           /*BIN7*/
                               SInt16 VSCtl_aVehPreCoVSCtlReq_swc_in,                      /*BIN10*/
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSRegReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSRegReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSReg_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSRegReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSReg_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSReg_swc_out)

{
  SInt16 stack_data_s16_0;
  UInt16 stack_data_u16_0;


  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F2221_Determiner_Mode_Commande_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.123.0  */

  if (vsreg_ctrl_spd_veh_sf_dwork.is_active_c86_VSREG_Ctrl_Spd_Veh_Sf == 0)
  {
    vsreg_ctrl_spd_veh_sf_dwork.is_active_c86_VSREG_Ctrl_Spd_Veh_Sf = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_c86_VSREG_Ctrl_Spd_Veh_Sf = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_COMMANDE_ACCELERATION;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_ETAT_CONTROLE_ACCELERATION = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_ETAT_CONTROLE_ACCELERATION = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_HORS_CONTROLE;
    vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_k;
    vsreg_vsctl_stctl_avehvsreg_cpy = VSCTL_STCTL_AVEHVSREG_ARRET;
    VSCtl_tiFilStCtlAVehVSReg = VSCtl_tiFil_stCtlAVehVSReg_C;
    VSCtl_bAcvFil_aVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_INITIALISATION_CONTROLE_ACCELERATION =
      1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_INITIALISATION_CONTROLE_ACCELERATION =
      (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX_f;
    VSCtl_bAcvCtlAVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_MEMORISATION = 1U;

  }
  else
  {
    switch (vsreg_ctrl_spd_veh_sf_dwork.is_ETAT_CONTROLE_ACCELERATION) {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_e:
      if (((((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
             (VSCtl_bFastDeacVSRegReq == VSREG_Ctrl_Spd_Veh_Sf_FAUX_j))
             &&
            (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE))
            && (VSCtl_stVSRegExtd_swc_in
            != VSCTL_STVSREGEXTD_ANE)) && (VSCtl_stVSRegExtd_swc_in !=
           VSCTL_STVSREGEXTD_REPRISE))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_ETAT_CONTROLE_ACCELERATION = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_HORS_CONTROLE;
        vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_TRANSITION;
        vsreg_vsctl_stctl_avehvsreg_cpy = VSCTL_STCTL_AVEHVSREG_TRANSITION;
        VSCtl_bAcvFil_aVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_VRAI_k;

      }
      else if ((VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL) ||
                 (VSCtl_bFastDeacVSRegReq == VSREG_Ctrl_Spd_Veh_Sf_VRAI_k))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_ETAT_CONTROLE_ACCELERATION = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_HORS_CONTROLE;
        vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_k;
        vsreg_vsctl_stctl_avehvsreg_cpy = VSCTL_STCTL_AVEHVSREG_ARRET;
        VSCtl_tiFilStCtlAVehVSReg = VSCtl_tiFil_stCtlAVehVSReg_C;
        VSCtl_bAcvFil_aVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_HORS_CONTROLE:
      if ((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
          (((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE)
          || (VSCtl_stVSRegExtd_swc_in ==
             VSCTL_STVSREGEXTD_ANE)) || (VSCtl_stVSRegExtd_swc_in ==
            VSCTL_STVSREGEXTD_REPRISE)))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_d;
        vsreg_ctrl_spd_veh_sf_dwork.is_ETAT_CONTROLE_ACCELERATION = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_e;
        vsreg_vsctl_stctl_avehvsreg_cpy = VSCTL_STCTL_AVEHVSREG_CONTROLE;
        VSCtl_tiFilStCtlAVehVSReg = VSCtl_tiFil_stCtlAVehVSReg_C;
        VSCtl_bAcvFil_aVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_VRAI_k;

      }
      else
      {
        switch (vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE)
      {
         case VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_k:
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_TRANSITION:
          if ((((VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL) ||
                (VSCtl_bFastDeacVSRegReq == VSREG_Ctrl_Spd_Veh_Sf_VRAI_k))
                ||
               (VSCtl_bEndTranVSReg_swc_in == VSREG_Ctrl_Spd_Veh_Sf_VRAI_k))
               ||
              (VSCtl_tiFilStCtlAVehVSReg == 0))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_k;
            vsreg_vsctl_stctl_avehvsreg_cpy = VSCTL_STCTL_AVEHVSREG_ARRET;
            VSCtl_tiFilStCtlAVehVSReg = VSCtl_tiFil_stCtlAVehVSReg_C;
            VSCtl_bAcvFil_aVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;

          }
          else
          {
            VSCtl_tiFilStCtlAVehVSReg = (UInt8)(VSCtl_tiFilStCtlAVehVSReg - 1);
          }
          break;

         default:
          vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = (UInt8)
            VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_k;
          vsreg_vsctl_stctl_avehvsreg_cpy = VSCTL_STCTL_AVEHVSREG_ARRET;
          VSCtl_tiFilStCtlAVehVSReg = VSCtl_tiFil_stCtlAVehVSReg_C;
          VSCtl_bAcvFil_aVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;
          break;
        }
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_ETAT_CONTROLE_ACCELERATION = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_HORS_CONTROLE;
      vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_k;
      vsreg_vsctl_stctl_avehvsreg_cpy = VSCTL_STCTL_AVEHVSREG_ARRET;
      VSCtl_tiFilStCtlAVehVSReg = VSCtl_tiFil_stCtlAVehVSReg_C;
      VSCtl_bAcvFil_aVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;
      break;
    }

    switch (vsreg_ctrl_spd_veh_sf_dwork.is_INITIALISATION_CONTROLE_ACCELERATION)
    {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX_f:
      if ((vsreg_vsctl_stctl_avehvsreg_cpy == VSCTL_STCTL_AVEHVSREG_CONTROLE)
      &&
          (VSCtl_stCtlAVehVSRegPrev != VSCTL_STCTLAVEHVSREGPREV_CONTROLE))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_INITIALISATION_CONTROLE_ACCELERATION =
          (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_VRAI_i;
        VSCtl_bAcvCtlAVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_VRAI_k;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_VRAI_i:
      if ((vsreg_vsctl_stctl_avehvsreg_cpy != VSCTL_STCTL_AVEHVSREG_CONTROLE)
      ||
          (VSCtl_stCtlAVehVSRegPrev == VSCTL_STCTLAVEHVSREGPREV_CONTROLE))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_INITIALISATION_CONTROLE_ACCELERATION =
          (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX_f;
        VSCtl_bAcvCtlAVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_INITIALISATION_CONTROLE_ACCELERATION =
        (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX_f;
      VSCtl_bAcvCtlAVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_j;
      break;
    }

    VSCtl_stCtlAVehVSRegPrev = vsreg_vsctl_stctl_avehvsreg_cpy;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2221_Determiner_Mode_Commande_Acceleration_Vehicule*/


  stack_data_u16_0 = vsreg_ctrl_spd_veh_sf_delay_0;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F2211_Determiner_Mode_Calcul_Consigne_Vitesse_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.57.4  */

  if (vsreg_ctrl_spd_veh_sf_dwork.is_active_c85_VSREG_Ctrl_Spd_Veh_Sf == 0)
  {
    vsreg_ctrl_spd_veh_sf_dwork.is_active_c85_VSREG_Ctrl_Spd_Veh_Sf = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_c85_VSREG_Ctrl_Spd_Veh_Sf = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_CALCUL_CONSIGNE_VITESSE_VEHICULE;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_INHIBITION_FILTRAGE = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_INHIBITION_FILTRAGE = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX;
    VSCtl_bInhFilSpdVehVSRegReq = VSREG_Ctrl_Spd_Veh_Sf_FAUX;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_MODES_FILTRAGE = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_MODES_FILTRAGE = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET;
    VSCtl_stFilSpdVehVSReg = VSCTL_STFILSPDVEHVSREG_ARRET;
    VSCtl_bAcvFilSpdVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_MODES_SATURATION_CONSIGNE_VITESSE = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_MODES_SATURATION_CONSIGNE_VITESSE = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET;
    VSCtl_stSatMaxSpdVehVSReg = VSCTL_STSATMAXSPDVEHVSREG_ARRET;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_MEMOIRES_c = 1U;

  }
  else
  {
    switch (vsreg_ctrl_spd_veh_sf_dwork.is_INHIBITION_FILTRAGE)
      {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX:
      if ((((((((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE) ||
                (VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_ANE)) ||
               (VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE)) &&
              (stack_data_u16_0 ==
               vsreg_ctrl_spd_veh_sf_b.VSCtl_spdVehVSRegReqPrev_p))
               &&
             ((((UInt32)Ext_spdVehVSRegReq_swc_in) << 7) != ((UInt32)
               vsreg_ctrl_spd_veh_sf_b.VSCtl_spdVehVSRegReqPrev_p)))
               && (DDS_M_ABS
             ((Ext_spdVehVSRegReq_swc_in << 7) -
              vsreg_ctrl_spd_veh_sf_b.VSCtl_spdVehVSRegReqPrev_p) <
             VSCtl_spdVehVSRegReqImp_C))
             && (DDS_M_ABS((Ext_spdVehVSRegReq_swc_in << 7) -
             VSCtl_spdVeh_swc_in) < VSCtl_spdVehVSRegReqImp_C)) &&
          (VSCtl_bDeacImpDetVSReg_C == 0))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_INHIBITION_FILTRAGE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_VRAI;
        VSCtl_bInhFilSpdVehVSRegReq = VSREG_Ctrl_Spd_Veh_Sf_VRAI;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_VRAI:
      vsreg_ctrl_spd_veh_sf_dwork.is_INHIBITION_FILTRAGE = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX;
      VSCtl_bInhFilSpdVehVSRegReq = VSREG_Ctrl_Spd_Veh_Sf_FAUX;
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_INHIBITION_FILTRAGE = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_FAUX;
      VSCtl_bInhFilSpdVehVSRegReq = VSREG_Ctrl_Spd_Veh_Sf_FAUX;
      break;
    }

    switch (vsreg_ctrl_spd_veh_sf_dwork.is_MODES_FILTRAGE)
      {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET:
      if (((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE)
      || (VSCtl_stVSRegExtd_swc_in ==
            VSCTL_STVSREGEXTD_ANE)) || (VSCtl_stVSRegExtd_swc_in ==
           VSCTL_STVSREGEXTD_REPRISE))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_MODES_FILTRAGE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE;
        vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_d = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NON_FILTREE;
        VSCtl_stFilSpdVehVSReg = VSCTL_STFILSPDVEHVSREG_NON_FILTREE;
        VSCtl_bAcvFilSpdVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE:
      if (((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE)
      && (VSCtl_stVSRegExtd_swc_in !=
            VSCTL_STVSREGEXTD_ANE)) && (VSCtl_stVSRegExtd_swc_in !=
           VSCTL_STVSREGEXTD_REPRISE))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_d = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_ctrl_spd_veh_sf_dwork.is_MODES_FILTRAGE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET;
        VSCtl_stFilSpdVehVSReg = VSCTL_STFILSPDVEHVSREG_ARRET;
        VSCtl_bAcvFilSpdVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX;

      }
      else
      {
        switch (vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_d)
      {
         case VSREG_Ctrl_Spd_Veh_Sf_IN_FILTREE:
          if ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE) ||
              (VSCtl_bInhFilSpdVehVSRegReq == VSREG_Ctrl_Spd_Veh_Sf_VRAI))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_d = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_NON_FILTREE;
            VSCtl_stFilSpdVehVSReg = VSCTL_STFILSPDVEHVSREG_NON_FILTREE;
            VSCtl_bAcvFilSpdVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX;
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_NON_FILTREE:
          if ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE) &&
              (VSCtl_bInhFilSpdVehVSRegReq == VSREG_Ctrl_Spd_Veh_Sf_FAUX))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_d = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_FILTREE;
            VSCtl_stFilSpdVehVSReg = VSCTL_STFILSPDVEHVSREG_FILTREE;
            VSCtl_bAcvFilSpdVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_VRAI;
          }
          break;
        }
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_MODES_FILTRAGE = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET;
      VSCtl_stFilSpdVehVSReg = VSCTL_STFILSPDVEHVSREG_ARRET;
      VSCtl_bAcvFilSpdVehVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX;
      break;
    }

    switch (vsreg_ctrl_spd_veh_sf_dwork.is_MODES_SATURATION_CONSIGNE_VITESSE)
          {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET:
      if ((((((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE)
      || (VSCtl_stVSRegExtd_swc_in ==
               VSCTL_STVSREGEXTD_ANE)) || (VSCtl_stVSRegExtd_swc_in ==
              VSCTL_STVSREGEXTD_REPRISE))
              && (Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM))
              &&
           (VSCtl_bDeacSatMaxSpdVehVSReg_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX))
           &&
          (FRM_bDeacSatMaxSpdVehVSReg_swc_in == VSREG_Ctrl_Spd_Veh_Sf_FAUX))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_MODES_SATURATION_CONSIGNE_VITESSE =
          (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE;
        VSCtl_stSatMaxSpdVehVSReg = VSCTL_STSATMAXSPDVEHVSREG_CONTROLE;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE:
      if ((((((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE)
      && (VSCtl_stVSRegExtd_swc_in
               != VSCTL_STVSREGEXTD_ANE)) && (VSCtl_stVSRegExtd_swc_in !=
              VSCTL_STVSREGEXTD_REPRISE))
              || (Ext_stGBxCf_swc_in != EXT_STGBXCF_BVM))
              ||
           (VSCtl_bDeacSatMaxSpdVehVSReg_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI))
           ||
          (FRM_bDeacSatMaxSpdVehVSReg_swc_in == VSREG_Ctrl_Spd_Veh_Sf_VRAI))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_MODES_SATURATION_CONSIGNE_VITESSE =
          (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET;
        VSCtl_stSatMaxSpdVehVSReg = VSCTL_STSATMAXSPDVEHVSREG_ARRET;
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_MODES_SATURATION_CONSIGNE_VITESSE =
        (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET;
      VSCtl_stSatMaxSpdVehVSReg = VSCTL_STSATMAXSPDVEHVSREG_ARRET;
      break;
    }

    vsreg_ctrl_spd_veh_sf_b.VSCtl_spdVehVSRegReqPrev_p = (UInt16)
      (Ext_spdVehVSRegReq_swc_in << 7);
  }

  VSCtl_spdVehVSRegReqPrev = DDS_M_MIN
    (vsreg_ctrl_spd_veh_sf_b.VSCtl_spdVehVSRegReqPrev_p,
     VSCTL_SPDVEHVSREGREQPREV_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2211_Determiner_Mode_Calcul_Consigne_Vitesse_Vehicule*/

    VSREG_F2212_Determiner_Consigne_Vitesse_Vehicule(CoPt_noEgdGearCordIt_swc_in,
                                                     Ext_spdVehVSRegReq_swc_in, /* BIN0 */
                                                     VSCtl_spdVeh_swc_in, /* BIN7 */
                                                     &vsreg_vsctl_spdveherrvsreg_cpy /* BIN7 */);


  VSREG_F222221_Determiner_Saturation_Acceleration_Vehicule_Max(VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                 vsreg_vsctl_spdveherrvsreg_cpy, /* BIN7 */
                                                 vsreg_vsctl_stctl_avehvsreg_cpy);


  VSREG_F222222_Determiner_Saturation_Acceleration_Vehicule_Min(VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                 vsreg_vsctl_spdveherrvsreg_cpy, /* BIN7 */
                                                 vsreg_vsctl_stctl_avehvsreg_cpy);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F2231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.124.1 */

  if (vsreg_ctrl_spd_veh_sf_dwork.is_active_c89_VSREG_Ctrl_Spd_Veh_Sf == 0)
  {
    vsreg_ctrl_spd_veh_sf_dwork.is_active_c89_VSREG_Ctrl_Spd_Veh_Sf = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_c89_VSREG_Ctrl_Spd_Veh_Sf = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE;
    vsreg_ctrl_spd_veh_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE
      = (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_g;
    vsreg_vsctl_bctl_avehpotvsreg_cpy = VSCTL_BCTL_AVEHPOTVSREG_ARRET;
    VSCtl_bAcvFil_aVehPotVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_d;

  }
  else
  {
    switch
      (vsreg_ctrl_spd_veh_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE)
    {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_g:
      if (((((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
             (vsreg_vsctl_stctl_avehvsreg_cpy == VSCTL_STCTL_AVEHVSREG_CONTROLE))
             &&
            (vsreg_vsctl_spdveherrvsreg_cpy < VSCtl_spdERegAVehP_HysLoP_C)) &&
           (vsreg_vsctl_spdveherrvsreg_cpy > VSCtl_spdERegAVehP_HysLoN_C)) &&
          ((((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)
          &&
             ((((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE) &&
                (VSCtl_bAcvPotVSRegNGear_AE_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n))
                ||
               ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_ANE) &&
                (VSCtl_bAcvPotVSRegNGear_ANE_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n)))
              || ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE) &&
                  (VSCtl_bAcvPotVSRegNGear_REP_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n))))

            || ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_COUPLE)
            &&
                ((((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE) &&
                   (VSCtl_bAcvPotVSRegTq_AE_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n))
                   ||
                  ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_ANE) &&
                   (VSCtl_bAcvPotVSRegTq_ANE_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n)))

                 || ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE)
                 &&
                     (VSCtl_bAcvPotVSRegTq_REP_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n)))))

           || ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
           &&
               ((((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE) &&
                  (VSCtl_bAcvPotVSRegPed_AE_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n))
                  ||
                 ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_ANE) &&
                  (VSCtl_bAcvPotVSRegPed_ANE_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n)))

                || ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE)
                &&
                    (VSCtl_bAcvPotVSRegPed_REP_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_n))))))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE
          = (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_p;
        vsreg_vsctl_bctl_avehpotvsreg_cpy = VSCTL_BCTL_AVEHPOTVSREG_CONTROLE;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_p:
      if (((((VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL) ||
             (vsreg_vsctl_stctl_avehvsreg_cpy != VSCTL_STCTL_AVEHVSREG_CONTROLE))
             ||
            (vsreg_vsctl_spdveherrvsreg_cpy > VSCtl_spdERegAVehP_HysHiP_C)) ||
           (vsreg_vsctl_spdveherrvsreg_cpy < VSCtl_spdERegAVehP_HysHiN_C)) ||
          ((((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_RAPPORT)
          &&
             ((((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE) ||
                (VSCtl_bAcvPotVSRegNGear_AE_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d))
                &&
               ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_ANE) ||
                (VSCtl_bAcvPotVSRegNGear_ANE_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d)))
              && ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE) ||
                  (VSCtl_bAcvPotVSRegNGear_REP_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d))))

            || ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_COUPLE)
            &&
                ((((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE) ||
                   (VSCtl_bAcvPotVSRegTq_AE_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d))
                   &&
                  ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_ANE) ||
                   (VSCtl_bAcvPotVSRegTq_ANE_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d)))

                 && ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE)
                 ||
                     (VSCtl_bAcvPotVSRegTq_REP_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d)))))

           || ((Ext_stCtlCmdPTTqPotCf_swc_in == EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED)
           &&
               ((((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE) ||
                  (VSCtl_bAcvPotVSRegPed_AE_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d))
                  &&
                 ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_ANE) ||
                  (VSCtl_bAcvPotVSRegPed_ANE_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d)))

                && ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE)
                ||
                    (VSCtl_bAcvPotVSRegPed_REP_C == VSREG_Ctrl_Spd_Veh_Sf_FAUX_d))))))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE
          = (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_g;
        vsreg_vsctl_bctl_avehpotvsreg_cpy = VSCTL_BCTL_AVEHPOTVSREG_ARRET;
        VSCtl_bAcvFil_aVehPotVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_d;

      }
      else
      {
        VSCtl_bAcvFil_aVehPotVSReg = VSREG_Ctrl_Spd_Veh_Sf_VRAI_n;
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE
        = (UInt8)VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_g;
      vsreg_vsctl_bctl_avehpotvsreg_cpy = VSCTL_BCTL_AVEHPOTVSREG_ARRET;
      VSCtl_bAcvFil_aVehPotVSReg = VSREG_Ctrl_Spd_Veh_Sf_FAUX_d;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule*/

    VSREG_F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(vsreg_vsctl_bctl_avehpotvsreg_cpy,
                                                 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 vsreg_vsctl_spdveherrvsreg_cpy, /* BIN7 */
                                                 &vsreg_vsctl_avehpotvsregreq_cpy /* BIN10 */);


    VSREG_F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp(vsreg_vsctl_bctl_avehpotvsreg_cpy,
                                                 vsreg_vsctl_spdveherrvsreg_cpy, /* BIN7 */
                                                 &vsreg_vsctl_rctltqwhlptpotvsreg_cpy /* BIN4 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F22231_Determiner_Mode_Controle_Vitesse_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.67.3  */

  if (vsreg_ctrl_spd_veh_sf_dwork.is_active_c88_VSREG_Ctrl_Spd_Veh_Sf == 0)
  {
    vsreg_ctrl_spd_veh_sf_dwork.is_active_c88_VSREG_Ctrl_Spd_Veh_Sf = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_c88_VSREG_Ctrl_Spd_Veh_Sf = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_MODES_CONTROLE_VITESSE_VEHICULE;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_CONDITION_CHANGEMENT_DYNAMIQUE = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_INIT;
    VSCtl_bDynCtlSpdVehVSReg = VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_LISSAGE_CONTROLE_VITESSE = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_INIT;
    vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = VSREG_100_BIN7;

  }
  else
  {
    switch (vsreg_ctrl_spd_veh_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE)
      {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_INIT:
      if (vsreg_vsctl_stctl_avehvsreg_cpy == VSCTL_STCTL_AVEHVSREG_CONTROLE)
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NON_INIT;
        vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_TRANSITOIRE;
        VSCtl_bDynCtlSpdVehVSReg = VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE;
        VSCtl_tiFilSpdVehCtlVSRegDyn = VSCtl_tiTol_DynCtlVSReg_C;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_NON_INIT:
      if (vsreg_vsctl_stctl_avehvsreg_cpy != VSCTL_STCTL_AVEHVSREG_CONTROLE)
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_h;
        vsreg_ctrl_spd_veh_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_INIT;
        VSCtl_bDynCtlSpdVehVSReg = VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE;

      }
      else
      {
        switch (vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j)
      {
         case VSREG_Ctrl_Spd_Veh_Sf_IN_CONF____0:
          if (((SInt16)DDS_M_ABS((SInt32)vsreg_vsctl_spdveherrvsreg_cpy)) >
              VSCtl_spdErrVSRegSDyn_HysHi_C)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF____0;

          }
          else if ((((SInt16)DDS_M_ABS((SInt32)vsreg_vsctl_spdveherrvsreg_cpy)) <
                      VSCtl_spdErrVSRegSDyn_HysLo_C) &&
                     (VSCtl_tiFilSpdVehCtlVSRegDyn <= 0))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_STABILISE;
            VSCtl_bDynCtlSpdVehVSReg = VSCTL_BDYNCTLSPDVEHVSREG_STABILISE;

          }
          else
          {
            VSCtl_tiFilSpdVehCtlVSRegDyn = (UInt8)DDS_M_MAX
              (VSCtl_tiFilSpdVehCtlVSRegDyn - VSCtl_tiCfm_SDynCtlChgVSReg_C, 0);
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF____0:
          if ((((SInt16)DDS_M_ABS((SInt32)vsreg_vsctl_spdveherrvsreg_cpy)) >
               VSCtl_spdErrVSRegSDyn_HysHi_C)
               && (VSCtl_tiFilSpdVehCtlVSRegDyn >=
               VSCtl_tiTol_DynCtlVSReg_C))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_TRANSITOIRE;
            VSCtl_bDynCtlSpdVehVSReg = VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE;
            VSCtl_tiFilSpdVehCtlVSRegDyn = VSCtl_tiTol_DynCtlVSReg_C;

          }
          else if (((SInt16)DDS_M_ABS((SInt32)vsreg_vsctl_spdveherrvsreg_cpy)) <
                     VSCtl_spdErrVSRegSDyn_HysLo_C)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_CONF____0;

          }
          else
          {
            VSCtl_tiFilSpdVehCtlVSRegDyn = (UInt8)
              ((VSCtl_tiFilSpdVehCtlVSRegDyn + VSCtl_tiDiCfmSDynCtlChgVSReg_C) <
               VSCtl_tiTol_DynCtlVSReg_C ? VSCtl_tiFilSpdVehCtlVSRegDyn +
               VSCtl_tiDiCfmSDynCtlChgVSReg_C : (SInt32)
               VSCtl_tiTol_DynCtlVSReg_C);
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_STABILISE:
          if (((SInt16)DDS_M_ABS((SInt32)vsreg_vsctl_spdveherrvsreg_cpy)) >
              VSCtl_spdErrVSRegSDyn_HysHi_C)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF____0;
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_TRANSITOIRE:
          if (((SInt16)DDS_M_ABS((SInt32)vsreg_vsctl_spdveherrvsreg_cpy)) <
              VSCtl_spdErrVSRegSDyn_HysLo_C)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_CONF____0;
          }
          break;
        }
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_INIT;
      VSCtl_bDynCtlSpdVehVSReg = VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE;
      break;
    }

    switch (vsreg_ctrl_spd_veh_sf_dwork.is_LISSAGE_CONTROLE_VITESSE)
          {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_INIT:
      if (vsreg_vsctl_stctl_avehvsreg_cpy == VSCTL_STCTL_AVEHVSREG_CONTROLE)
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NON_INIT;
        vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_BARYCENTRE_IN_1;
        vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = VSREG_100_BIN7;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_NON_INIT:
      if (vsreg_vsctl_stctl_avehvsreg_cpy != VSCTL_STCTL_AVEHVSREG_CONTROLE)
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_h;
        vsreg_ctrl_spd_veh_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_INIT;
        vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = VSREG_100_BIN7;

      }
      else
      {
        switch (vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT)
      {
         case VSREG_Ctrl_Spd_Veh_Sf_IN_BARYCENTRE_IN_1:
          if (VSCtl_bDynCtlSpdVehVSReg == VSCTL_BDYNCTLSPDVEHVSREG_STABILISE)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_CONF;
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_BARYCENTRE_IN_2:
          if (VSCtl_bDynCtlSpdVehVSReg == VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF;
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_CONF:
          if (VSCtl_bDynCtlSpdVehVSReg == VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF;

          }
          else if ((VSCtl_bDynCtlSpdVehVSReg ==
                      VSCTL_BDYNCTLSPDVEHVSREG_STABILISE) &&
                     (vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f <= 0))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_BARYCENTRE_IN_2;
            vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = 0U;

          }
          else
          {
            vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = (UInt16)
              DDS_M_MAX(vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f -
                     VSCtl_tiCfm_rSDynCtlVSReg_C, 0);
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_DECONF:
          if ((VSCtl_bDynCtlSpdVehVSReg == VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE)

              && (vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f >=
                  VSREG_100_BIN7))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_BARYCENTRE_IN_1;
            vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = VSREG_100_BIN7;

          }
          else if (VSCtl_bDynCtlSpdVehVSReg ==
                     VSCTL_BDYNCTLSPDVEHVSREG_STABILISE)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_CONF;

          }
          else
          {
            vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = (UInt16)
              ((vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f +
                VSCtl_tiDiCfm_rCtlTDynVSReg_C) < VSREG_100_BIN7 ?
               vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f +
               VSCtl_tiDiCfm_rCtlTDynVSReg_C : (SInt32)VSREG_100_BIN7);
          }
          break;
        }
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_INIT;
      vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = VSREG_100_BIN7;
      break;
    }
  }

  VSCtl_rSpdVehCtlVSRegDyn = DDS_M_MIN
    (vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f,
     VSCTL_RSPDVEHCTLVSREGDYN_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F22231_Determiner_Mode_Controle_Vitesse_Vehicule*/

    VSREG_F2234_Determiner_Temps_Confirmation_Changement_Rapport(vsreg_vsctl_avehpotvsregreq_cpy, /* BIN10 */
                                                 vsreg_vsctl_bctl_avehpotvsreg_cpy,
                                                 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 vsreg_vsctl_spdveherrvsreg_cpy, /* BIN7 */
                                                 &vsreg_vsctl_ticfmsdwnvsregreq_cpy, /* DEC2 */
                                                 &vsreg_vsctl_ticfmsupvsregreq_cpy /* DEC2 */);

  stack_data_s16_0 = vsreg_ctrl_spd_veh_sf_delay_1;


  /* TAG_START_OF_STATEFLOW_FUNCTION: F22221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.60.4  */

  if (vsreg_ctrl_spd_veh_sf_dwork.is_active_c87_VSREG_Ctrl_Spd_Veh_Sf == 0)
  {
    vsreg_ctrl_spd_veh_sf_dwork.is_active_c87_VSREG_Ctrl_Spd_Veh_Sf = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_c87_VSREG_Ctrl_Spd_Veh_Sf = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_MODE_CALCUL_GABARITS_ACCELERATION_VEHICULE;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_ACCEL_MIN = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_ACCEL_MIN = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e;
    VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_ARRET;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_JERK_MIN = 1U;
    vsreg_ctrl_spd_veh_sf_dwork.is_JERK_MIN = (UInt8)
      VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e;
    VSCtl_stSatJrkVehMinVSReg = VSCTL_STSATJRKVEHMINVSREG_ARRET;
    vsreg_ctrl_spd_veh_sf_dwork.is_active_MEMOIRES = 1U;

  }
  else
  {
    switch (vsreg_ctrl_spd_veh_sf_dwork.is_ACCEL_MIN)
          {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e:
      if ((vsreg_vsctl_stctl_avehvsreg_cpy != VSCTL_STCTL_AVEHVSREG_ARRET) &&
          (VSCtl_bDeacStSatAVehMinVSReg_C == VSREG_Ctrl_Spd_Veh_Sf_VRAI_m))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_ACCEL_MIN = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_ey;
        vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF____0;
        VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_EFFECTIF_29;

      }
      else if ((vsreg_vsctl_stctl_avehvsreg_cpy != VSCTL_STCTL_AVEHVSREG_ARRET)
      &&
                 (VSCtl_bDeacStSatAVehMinVSReg_C ==
                  VSREG_Ctrl_Spd_Veh_Sf_FAUX_jg))
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_ACCEL_MIN = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_ey;
        vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF____0;
        VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_NON_EFFECTIF_29;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_ey:
      if (vsreg_vsctl_stctl_avehvsreg_cpy == VSCTL_STCTL_AVEHVSREG_ARRET)
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_l;
        vsreg_ctrl_spd_veh_sf_dwork.is_ACCEL_MIN = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e;
        VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_ARRET;

      }
      else
      {
        switch (vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE)
      {
         case VSREG_Ctrl_Spd_Veh_Sf_IN_ACTIVATION:
          if ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE) ||
              (VSCtl_stSatAVehMinVSRegMod_C !=
               VSCTL_STSATAVEHMINVSREGMOD_C_COMPLET))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF____0;
            VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_NON_EFFECTIF_29;

          }
          else if ((VSCtl_aVehReq_swc_in >= stack_data_s16_0)

                     && (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF____0;
            VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_EFFECTIF_29;
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF____0:
          if (VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF____0;
            VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_NON_EFFECTIF_29;
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF____0:
          if (((VSCtl_aVehReq_swc_in >= stack_data_s16_0)
          &&
               (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE)) &&
              (VSCtl_stSatAVehMinVSRegMod_C !=
               VSCTL_STSATAVEHMINVSREGMOD_C_COMPLET))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF____0;
            VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_EFFECTIF_29;

          }
          else if ((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE)
          &&
                     (VSCtl_stSatAVehMinVSRegMod_C ==
                      VSCTL_STSATAVEHMINVSREGMOD_C_COMPLET))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_ACTIVATION;
            VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_ACTIVATION_29;
          }
          break;
        }
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_ACCEL_MIN = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e;
      VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_ARRET;
      break;
    }

    switch (vsreg_ctrl_spd_veh_sf_dwork.is_JERK_MIN)
          {
     case VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e:
      if (vsreg_vsctl_stctl_avehvsreg_cpy != VSCTL_STCTL_AVEHVSREG_ARRET)
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_JERK_MIN = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_ey;
        vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_i = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF;
        VSCtl_stSatJrkVehMinVSReg = VSCTL_STSATJRKVEHMINVSREG_EFFECTIF;
      }
      break;

     case VSREG_Ctrl_Spd_Veh_Sf_IN_CONTROLE_ey:
      if (vsreg_vsctl_stctl_avehvsreg_cpy == VSCTL_STCTL_AVEHVSREG_ARRET)
      {
        vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_i = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_NO_ACTIVE_CHILD_l;
        vsreg_ctrl_spd_veh_sf_dwork.is_JERK_MIN = (UInt8)
          VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e;
        VSCtl_stSatJrkVehMinVSReg = VSCTL_STSATJRKVEHMINVSREG_ARRET;

      }
      else
      {
        switch (vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_i)
      {
         case VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF:
          if (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE)
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_i = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF;
            VSCtl_stSatJrkVehMinVSReg = VSCTL_STSATJRKVEHMINVSREG_NON_EFFECTIF;
          }
          break;

         case VSREG_Ctrl_Spd_Veh_Sf_IN_NON_EFFECTIF:
          if ((VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE) &&
              (VSCtl_stRegVSRegPrev_VSReg == VSCTL_STVSREGEXTD_AE))
          {
            vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_i = (UInt8)
              VSREG_Ctrl_Spd_Veh_Sf_IN_EFFECTIF;
            VSCtl_stSatJrkVehMinVSReg = VSCTL_STSATJRKVEHMINVSREG_EFFECTIF;
          }
          break;
        }
      }
      break;

     default:
      vsreg_ctrl_spd_veh_sf_dwork.is_JERK_MIN = (UInt8)
        VSREG_Ctrl_Spd_Veh_Sf_IN_ARRET_e;
      VSCtl_stSatJrkVehMinVSReg = VSCTL_STSATJRKVEHMINVSREG_ARRET;
      break;
    }

    VSCtl_stRegVSRegPrev_VSReg = VSCtl_stVSRegExtd_swc_in;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F22221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule*/

    VSREG_F22223_Determiner_Saturations_Jerk_Vehicule(VSCtl_aVehPreCoVSCtlReq_swc_in, /* BIN10 */
                                                 VSCtl_aVehReq_swc_in, /* BIN10 */
                                                 VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                                                 vsreg_vsctl_stctl_avehvsreg_cpy);


  VSREG_F22224_Determiner_Gabarits_Acceleration_Vehicule(VSCtl_aVehPTIni_swc_in, /* BIN10 */
                                                 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                 VSCtl_aVehReq_swc_in, /* BIN10 */
                                                 vsreg_vsctl_stctl_avehvsreg_cpy);

  VSREG_F22232_Determiner_Consigne_Acceleration_Vehicule(vsreg_vsctl_spdveherrvsreg_cpy, /* BIN7 */
                                                 vsreg_vsctl_stctl_avehvsreg_cpy,
                                                 &vsreg_vsctl_avehvsregreq_cpy /* BIN10 */);

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_aVehPotVSRegReq_swc_out = vsreg_vsctl_avehpotvsregreq_cpy;

  *VSCtl_aVehVSRegReq_swc_out = vsreg_vsctl_avehvsregreq_cpy;

  *VSCtl_spdVehErrVSReg_swc_out = vsreg_vsctl_spdveherrvsreg_cpy;

  *VSCtl_rCtlTqWhlPTPotVSReg_swc_out = vsreg_vsctl_rctltqwhlptpotvsreg_cpy;

  *VSCtl_tiCfmSdwnVSRegReq_swc_out = vsreg_vsctl_ticfmsdwnvsregreq_cpy;

  *VSCtl_tiCfmSupVSRegReq_swc_out = vsreg_vsctl_ticfmsupvsregreq_cpy;

  *VSCtl_bCtl_aVehPotVSReg_swc_out = vsreg_vsctl_bctl_avehpotvsreg_cpy;

  *VSCtl_stCtl_aVehVSReg_swc_out = vsreg_vsctl_stctl_avehvsreg_cpy;


  vsreg_ctrl_spd_veh_sf_delay_0 = VSCtl_spdVehVSRegReqFil;

  vsreg_ctrl_spd_veh_sf_delay_1 = VSCtl_aVehVSRegReqSatMin;
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSREG_Ctrl_Spd_Veh_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSRegReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSRegReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSReg_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSRegReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSReg_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSReg_swc_out)

{
    VSREG_Veh_Speed_Control_Sl_Init(VSCtl_spdVehErrVSReg_swc_out, /* BIN7 */
                                      VSCtl_aVehVSRegReq_swc_out, /* BIN10 */
                                      VSCtl_aVehPotVSRegReq_swc_out, /* BIN10 */
                                      VSCtl_rCtlTqWhlPTPotVSReg_swc_out, /* BIN4 */
                                      VSCtl_tiCfmSupVSRegReq_swc_out, /* DEC2 */
                                      VSCtl_tiCfmSdwnVSRegReq_swc_out /* DEC2 */);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  vsreg_vsctl_ticfmsupvsregreq_cpy = *VSCtl_tiCfmSupVSRegReq_swc_out;

  vsreg_vsctl_spdveherrvsreg_cpy = *VSCtl_spdVehErrVSReg_swc_out;

  vsreg_vsctl_ticfmsdwnvsregreq_cpy = *VSCtl_tiCfmSdwnVSRegReq_swc_out;

  vsreg_vsctl_rctltqwhlptpotvsreg_cpy = *VSCtl_rCtlTqWhlPTPotVSReg_swc_out;

  VSCtl_spdVehVSRegReqPrev=0;
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_rSpdVehCtlVSRegDyn = 12800U;
  vsreg_vsctl_avehpotvsregreq_cpy = *VSCtl_aVehPotVSRegReq_swc_out;

  vsreg_vsctl_avehvsregreq_cpy = *VSCtl_aVehVSRegReq_swc_out;

  *VSCtl_bCtl_aVehPotVSReg_swc_out = VSCTL_BCTL_AVEHPOTVSREG_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsreg_vsctl_bctl_avehpotvsreg_cpy = *VSCtl_bCtl_aVehPotVSReg_swc_out;

  VSCtl_tiFilSpdVehCtlVSRegDyn = VSCtl_tiTol_DynCtlVSReg_C; /* Replaced by Post task */     /* Init from Model */
  VSCtl_bDynCtlSpdVehVSReg = VSCTL_BDYNCTLSPDVEHVSREG_TRANSITOIRE;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSatJrkVehMinVSReg = VSCTL_STSATJRKVEHMINVSREG_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSatAVehMinVSReg = VSCTL_STSATAVEHMINVSREG_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stRegVSRegPrev_VSReg = VSCTL_STREGVSREGPREV_VSREG_ARRET;    /* Replaced by Post task */     /* Init from Model */
  *VSCtl_stCtl_aVehVSReg_swc_out = VSCTL_STCTL_AVEHVSREG_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsreg_vsctl_stctl_avehvsreg_cpy = *VSCtl_stCtl_aVehVSReg_swc_out;

  VSCtl_tiFilStCtlAVehVSReg = VSCtl_tiFil_stCtlAVehVSReg_C; /* Replaced by Post task */     /* Init from Model */
  VSCtl_stCtlAVehVSRegPrev = VSCTL_STCTLAVEHVSREGPREV_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stFilSpdVehVSReg = VSCTL_STFILSPDVEHVSREG_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stSatMaxSpdVehVSReg = VSCTL_STSATMAXSPDVEHVSREG_ARRET;  /* Replaced by Post task */     /* Init from Model */


  vsreg_ctrl_spd_veh_sf_dwork.is_active_ETAT_CONTROLE_ACCELERATION = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_ETAT_CONTROLE_ACCELERATION = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_HORS_CONTROLE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_INITIALISATION_CONTROLE_ACCELERATION =
    0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_INITIALISATION_CONTROLE_ACCELERATION = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_MEMORISATION = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_c86_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_c86_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  VSCtl_bAcvCtlAVehVSReg =DDS_FALSE;
  VSCtl_bAcvFil_aVehVSReg =DDS_FALSE;


  vsreg_ctrl_spd_veh_sf_delay_0 = VSREG_CTRL_SPD_VEH_SF_CONST_0;


  vsreg_ctrl_spd_veh_sf_dwork.is_active_INHIBITION_FILTRAGE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_INHIBITION_FILTRAGE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_MEMOIRES_c = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_MODES_FILTRAGE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_MODES_FILTRAGE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_d = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_MODES_SATURATION_CONSIGNE_VITESSE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_MODES_SATURATION_CONSIGNE_VITESSE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_c85_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_c85_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  VSCtl_bAcvFilSpdVehVSReg =DDS_FALSE;
  vsreg_ctrl_spd_veh_sf_b.VSCtl_spdVehVSRegReqPrev_p = 0U;
  VSCtl_bInhFilSpdVehVSRegReq =DDS_FALSE;



  vsreg_ctrl_spd_veh_sf_dwork.is_MODE_COMMANDE_POTENTIEL_ACCELERATION_VEHICULE =
    0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_c89_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_c89_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  VSCtl_bAcvFil_aVehPotVSReg =DDS_FALSE;



  vsreg_ctrl_spd_veh_sf_dwork.is_active_CONDITION_CHANGEMENT_DYNAMIQUE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_CONDITION_CHANGEMENT_DYNAMIQUE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT_j = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_LISSAGE_CONTROLE_VITESSE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_LISSAGE_CONTROLE_VITESSE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_NON_INIT = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_c88_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_c88_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  vsreg_ctrl_spd_veh_sf_b.VSCtl_rSpdVehCtlVSRegDyn_f = 0U;


  vsreg_ctrl_spd_veh_sf_delay_1 = VSREG_CTRL_SPD_VEH_SF_CONST_1;


  vsreg_ctrl_spd_veh_sf_dwork.is_active_ACCEL_MIN = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_ACCEL_MIN = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_JERK_MIN = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_JERK_MIN = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_CONTROLE_i = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_MEMOIRES = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_active_c87_VSREG_Ctrl_Spd_Veh_Sf = 0U;
  vsreg_ctrl_spd_veh_sf_dwork.is_c87_VSREG_Ctrl_Spd_Veh_Sf = 0U;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

