/*
* File: VSINFO_Inf_Mnt_Re002tev_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSINFO_Inf_Mnt_Re002tev_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Tue Nov 22 12:11:16 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Tue Nov 22 12:11:18 2011
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
*
* Scripts versions:
*        aut_add_io version 3.0                                        aut_autocode_optimization version 8.0
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
*        aut_create_sstg_architecture version 10.0                     aut_cross_check_T55_mdl_init version 4.0
*        aut_find_source_block_path version 6.0                        aut_fixed_point_toolbox_interface version 4.0
*        aut_format_cpv_initialization_line version 10.0               aut_free_up_unexpected_block version 4.0
*        aut_get_array_apv_according_calibration_mode version 5.0      aut_get_data_list_from_link_output_block version 3.0
*        aut_get_data_size version 3.0                                 aut_get_deeper_block_from_list version 3.0
*        aut_get_evaluated_value_from_constant version 4.0             aut_get_final_datatype version 3.0
*        aut_get_information_from_next_block version 16.0              aut_get_information_from_previous_block version 30.0
*        aut_get_key version 3.0                                       aut_get_sigtype_info version 3.0
*        aut_get_snapshot_under_critical_lst_tag version 1.0           aut_get_squeduling_list version 16.0
*        aut_get_src_handle_from_previous_block_and_port_index version 3.0aut_get_static_data_list version 4.0
*        aut_init_value_check version 4.0                              aut_key_alg version 3.0
*        aut_manage_autocode_model version 15.0                        aut_manage_compilation_mode version 4.0
*        aut_manage_doc_block version 7.0                              aut_manage_limiter version 11.0
*        aut_manage_model_workspace version 3.0                        aut_manage_simulink_to_post_task_exchange version 54.0
*        aut_manage_snapshot version 26.0                              aut_mode_switch version 68.0
*        aut_model_autocode version 25.0                               aut_model_configure version 7.0
*        aut_pre_autocode version 55.0                                 aut_prepare_t55_task version 28.0
*        aut_prepare_t55_task_for_tag version 9.0                      aut_process_mngt version 58.0
*        aut_project_settings version 22.0                             aut_signal_config version 13.0
*        aut_sstg_manage_signal_memory_location version 6.0            aut_stateflow_checks version 6.0
*        aut_step_ckecks version 4.0                                   aut_switch_cpv_initialization version 13.0
*        aut_tlc_check_if_min_requested_instead_of_limit version 3.0   aut_types version 3.0
*        aut_unset_set_block_properties_of_subsytem version 8.0        aut_update_init_file_with_tag version 4.0
*        sim_check_if_data_is_in_full_range version 2.0                sim_check_unlinked_blocks version 11.0
*        sim_configure_simulation_mode version 9.0                     sim_display_dd_settings version 5.0
*        sim_format_hyperlink_message version 6.0                      sim_function_stub version 3.0
*        sim_get_autorisation_for_limitation version 1.0               sim_get_library_references version 46.0
*        sim_get_library_version version 3.0                           sim_get_static_data_block version 3.0
*        sim_load_libraries version 3.0                                sim_manage_block_tab version 6.0
*        sim_manage_config_set version 4.0                             sim_manage_link_status_warning version 3.0
*        sim_manage_structure_dd_display version 2.0                   sim_manage_structure_signals version 5.0
*        sim_prepare_limitation version 60.0                           sim_restore_previous_tag_version version 2.0
*        sim_set version 1.0                                           sim_set_ic version 1.0
*        sim_set_param version 3.0                                     sim_sf_get_param version 7.0
*        sim_switch_block_mode version 5.0                             sim_update_block_display_status version 18.0
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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Inf_Mnt_Re002tev_Sf.c
* Version int :/main/L02_02/1 Date: 4/1/2012 16 h 30 m User:esnault 
*    TWK_model:VSINFO_Inf_Mnt_Re002tev_Sf_L02_020_IMPL1
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 4/1/2012 15 h 22 m User:demezil 
*    TWK_model:VSINFO_Inf_Mnt_Re002tev_Sf_L02_020_IMPL1
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 22/11/2011 14 h 3 m User:demezil
*    TWK_model:VSINFO_Inf_Mnt_Re002tev_Sf_L02_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Niveau_Adherence */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Niveau_Adherence ;Ext_bDetLoWhlGripCf;FRM_bDeacVSCtlLoWhlGripClc;VSCtl_stGrdLkInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Niveau_Adherence ;VSCtl_stDetLoWhlGripClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Niveau_Adherence */

/* TAG_START_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Regime_Roue_Avant */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Regime_Roue_Avant ;FRM_bDeacNFrntWhlClc;VSCtl_stGrdLkInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Regime_Roue_Avant ;VSCtl_bAcvFil_nFrntWhlClc;VSCtl_stnFrntWhlModClc;VSCtl_tiInistnFrntWhlModClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Determiner_Mode_Calcul_Regime_Roue_Avant */

/* TAG_START_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration ;Ext_bSpdFrntWhlCf;Ext_bSpdReWhlCf;Ext_stPTCf;VSCtl_stPTInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration ;VSCtl_bDgoSpdVehClc;VSCtl_bMonRunSpdVehClc;VSCtl_stDiagSpdVeh; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Diagnostiquer_Configuration_Reconfiguration */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Information_LAS */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Information_LAS ;FRM_bDeacVSCtlGrdLkClc;VSCtl_stDiagSpdVeh;VSCtl_stPTInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Information_LAS ;VSCtl_stGrdLkInfo;VSCtl_tiIniGrdLkClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Information_LAS */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Informations_Frein */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Frein ;FRM_bDeacVSCtlBrkClc;VSCtl_stPTInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Frein ;VSCtl_stBrkInfo;VSCtl_tiIniBrkClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Informations_Frein */

/* TAG_START_OF_SUB_FUNCTION: F122_Determiner_Couples_Roue_Frein */
/* TAG_INPUT_OF_SUB_FUNCTION: F122_Determiner_Couples_Roue_Frein ;Brk_tqWhlBrkEstim;Brk_tqWhlBrkReq;Ext_bTqWhlBrkCf;VSCtl_stBrkInfo; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F122_Determiner_Couples_Roue_Frein ;VSCtl_tqWhlBrkEstim;VSCtl_tqWhlBrkReq; */
/* TAG_END_OF_SUB_FUNCTION: F122_Determiner_Couples_Roue_Frein */

/* TAG_START_OF_SUB_FUNCTION: F1332_Determiner_Vitesse_Vehicule_Reference */
/* TAG_INPUT_OF_SUB_FUNCTION: F1332_Determiner_Vitesse_Vehicule_Reference ;Ext_spdFrntWhl;Ext_spdReWhl;FRM_bRcvVSCtlSpdFrntWhl;FRM_bRcvVSCtlSpdReWhl;VSCtl_rTqWhlPTRe;VSCtl_stVehSpdRefModClc;Veh_spdVeh; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F1332_Determiner_Vitesse_Vehicule_Reference ;VSCtl_spdVehRef; */
/* TAG_END_OF_SUB_FUNCTION: F1332_Determiner_Vitesse_Vehicule_Reference */

/* TAG_START_OF_SUB_FUNCTION: F1342_Determiner_Glissement_Relatif */
/* TAG_INPUT_OF_SUB_FUNCTION: F1342_Determiner_Glissement_Relatif ;Ext_spdFrntWhl;Ext_spdReWhl;VSCtl_bAcvFil_rWhlSlipClc;VSCtl_st_rWhlSlipModClc; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F1342_Determiner_Glissement_Relatif ;VSCtl_rWhlSlipRaw1;VSCtl_rWhlSlipRaw2;VSCtl_rWhlSlip_no1;VSCtl_rWhlSlip_no2; */
/* TAG_END_OF_SUB_FUNCTION: F1342_Determiner_Glissement_Relatif */

/* TAG_START_OF_SUB_FUNCTION: F1352_Determiner_Niveau_Adherence */
/* TAG_INPUT_OF_SUB_FUNCTION: F1352_Determiner_Niveau_Adherence ;Ext_bDetLoWhlGrip;VSCtl_stDetLoWhlGripClc; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F1352_Determiner_Niveau_Adherence ;VSCtl_bDetLoWhlGrip; */
/* TAG_END_OF_SUB_FUNCTION: F1352_Determiner_Niveau_Adherence */

/* TAG_START_OF_SUB_FUNCTION: F1362_Determiner_Regime_Roue_Avant */
/* TAG_INPUT_OF_SUB_FUNCTION: F1362_Determiner_Regime_Roue_Avant ;Ext_nFrntWhl;VSCtl_bAcvFil_nFrntWhlClc;VSCtl_stnFrntWhlModClc; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F1362_Determiner_Regime_Roue_Avant ;VSCtl_nFrntWhlFil; */
/* TAG_END_OF_SUB_FUNCTION: F1362_Determiner_Regime_Roue_Avant */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Glissement_Relatif */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Glissement_Relatif ;Ext_bSpdFrntWhlCf;Ext_bSpdReWhlCf;FRM_bDeacVSCtlWhlSlipClc;VSCtl_stGrdLkInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Glissement_Relatif ;VSCtl_bAcvFil_rWhlSlipClc;VSCtl_st_rWhlSlipModClc;VSCtl_tiIniRWhlSlipClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Glissement_Relatif */

/* TAG_START_OF_STATEFLOW_FUNCTION: Mode_Calcul_Vitesse_Vehicule_Reference */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Vitesse_Vehicule_Reference ;Ext_stPTCf;FRM_bDeacSpdVehClc;VSCtl_stGrdLkInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Mode_Calcul_Vitesse_Vehicule_Reference ;VSCtl_stVehSpdRefModClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Mode_Calcul_Vitesse_Vehicule_Reference */

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
#define EXT_STPTCF_TRACTION                         (0)
#define EXT_STPTCF_PROPULSION                       (1)
#define EXT_STPTCF_INTEGRAL                         (2)
#define EXT_BSPDFRNTWHLCF_ABSENT                    (0)
#define EXT_BSPDFRNTWHLCF_PRESENT                   (1)
#define EXT_BSPDREWHLCF_ABSENT                      (0)
#define EXT_BSPDREWHLCF_PRESENT                     (1)
#define EXT_BDETLOWHLGRIPCF_PRESENT                 (1)
#define VSCTL_STDEACVSCTLINFO_RESERVE_32            (32)

/* VSCtl_stDiagSpdVeh */
#define VSCTL_STDIAGSPDVEH_NOMINAL_36               (1)
#define VSCTL_STDIAGSPDVEH_DEFAUT_36                (2)

/* VSCtl_st_rWhlSlipModClc */
#define VSCTL_ST_RWHLSLIPMODCLC_ARRET               (0)
#define VSCTL_ST_RWHLSLIPMODCLC_VERIF_19            (1)
#define VSCTL_ST_RWHLSLIPMODCLC_INIT_19             (2)
#define VSCTL_ST_RWHLSLIPMODCLC_NOMINAL_19          (3)
#define VSCTL_ST_RWHLSLIPMODCLC_DEFAUT_19           (4)


/* VSCtl_stnFrntWhlModClc */
#define VSCTL_STNFRNTWHLMODCLC_ARRET                (0)
#define VSCTL_STNFRNTWHLMODCLC_VERIF_37             (1)
#define VSCTL_STNFRNTWHLMODCLC_INIT_37              (2)
#define VSCTL_STNFRNTWHLMODCLC_NOMINAL_37           (3)
#define VSCTL_STNFRNTWHLMODCLC_DEFAUT_37            (4)

/* VSCtl_stBrkInfo */
#define VSCTL_STBRKINFO_ARRET                       (0)
#define VSCTL_STBRKINFO_VERIF_11                    (1)
#define VSCTL_STBRKINFO_INIT_11                     (2)
#define VSCTL_STBRKINFO_NOMINAL_11                  (3)
#define VSCTL_STBRKINFO_DEFAUT_11                   (4)

/* VSCtl_stVehSpdRefModClc */
#define VSCTL_STVEHSPDREFMODCLC_ARRET               (0)
#define VSCTL_STVEHSPDREFMODCLC_VERIF_16            (1)
#define VSCTL_STVEHSPDREFMODCLC_INIT_16             (2)
#define VSCTL_STVEHSPDREFMODCLC_AVANT_16            (3)
#define VSCTL_STVEHSPDREFMODCLC_ARRIERE_16          (4)
#define VSCTL_STVEHSPDREFMODCLC_INTEGRAL_16         (5)
#define VSCTL_STVEHSPDREFMODCLC_DEFAUT_16           (6)

/* VSCtl_stDetLoWhlGripClc */
#define VSCTL_STDETLOWHLGRIPCLC_ARRET               (0)
#define VSCTL_STDETLOWHLGRIPCLC_VERIF_21            (1)
#define VSCTL_STDETLOWHLGRIPCLC_NOMINAL_21          (2)
#define VSCTL_STDETLOWHLGRIPCLC_DEFAUT_21           (3)
/***********************************************************/

/* Named constants for block: /Diagnostiquer_Configuration_Reconfiguration' */
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m (0)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_f (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_h (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_m (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_l (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i (0U)
#define VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_d (1U)

/* Named constants for block: /Etat_Information_LAS' */
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g (0)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ETAT_INFORMATIONS_LAS (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_n (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_l (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_f (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_b (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_d (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_c (3)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_a (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_e (0U)
#define VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_f (1U)

/* Named constants for block: /Mode_Calcul_Glissement_Relatif' */
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_f (0)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_GLISSEMENT_RELATIF (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_ht (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_i (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_b (3)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_k (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_p (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_g (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_p (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq (0U)
#define VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_i (1U)

/* Named constants for block: /Determiner_Mode_Calcul_Regime_Roue_Avant' */
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n (0)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_bg (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_REGIME_ROUE_AVANT (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_ll (3)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_f (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_h (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_ka (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_m (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_d (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_b (1U)
#define VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m (0U)

/* Named constants for block: /Etat_Informations_Frein' */
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ETAT_INFORMATIONS_FREIN (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF (3)
#define VSINFO_Inf_Mnt_Re002tev_Sf_VRAI (1U)
#define VSINFO_Inf_Mnt_Re002tev_Sf_FAUX (0U)

/* Named constants for block: /Mode_Calcul_Vitesse_Vehicule_Reference' */
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d (0)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_fi (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_m (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_j (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_l (3)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_AVANT (3)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_ARRIERE (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_INTEGRAL (4)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_m (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_j (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_h (0U)
#define VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_m (1U)

/* Named constants for block: /Determiner_Mode_Calcul_Niveau_Adherence' */
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_c (0)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_n (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_NIVEAU_ADHERENCE (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_a (3)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_hx (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_c (1)
#define VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_c (2)
#define VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_md (1U)
#define VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_c (0U)


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stnFrntWhlModClc;
VAR(UInt8, AUTOMATIC) VSCtl_st_rWhlSlipModClc;
VAR(UInt8, AUTOMATIC) VSCtl_stVehSpdRefModClc;
VAR(UInt8, AUTOMATIC) VSCtl_stDetLoWhlGripClc;
VAR(UInt8, AUTOMATIC) VSCtl_stBrkInfo;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rWhlSlipClc;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_nFrntWhlClc;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt32 is_PAS_DEFAUT : 3;
  UInt32 is_MODE_CALCUL_REGIME_ROUE_AVANT : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_PAS_DEFAUT_m : 2;
  UInt32 is_MODE_CALCUL_NIVEAU_ADHERENCE : 2;
  UInt32 is_MARCHE_o : 2;
  UInt32 is_MODE_CALCUL_GLISSEMENT_RELATIF : 2;
  UInt32 is_MARCHE_ok : 2;
  UInt32 is_PAS_DEFAUT_l : 2;
  UInt32 is_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE : 2;
  UInt32 is_MARCHE_c : 2;
  UInt32 is_ETAT_INFORMATIONS_LAS : 2;
  UInt32 is_PAS_DEFAUT_a : 2;
  UInt32 is_MARCHE_i : 2;
  UInt32 is_MARCHE_j : 2;
  UInt32 is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION : 2;
  UInt32 is_MARCHE_k : 2;
  UInt32 is_ETAT_INFORMATIONS_FREIN : 2;
  UInt32 is_PAS_DEFAUT_p : 2;
  UInt32 is_active_c176_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_c176_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_active_c175_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_c175_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_active_c174_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_c174_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_active_c173_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_c173_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_active_c172_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_c172_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_active_c171_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_c171_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_active_c170_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
  UInt32 is_c170_VSINFO_Inf_Mnt_Re002tev_Sf : 1;
} D_Work_VSINFO_Inf_Mnt_Re002tev_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniBrkClc;                      /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniGrdLkClc;                    /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniRWhlSlipClc;                 /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiInistnFrntWhlModClc;            /*BIN0*/
/* Static Visible area end */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 32BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsinfo_vsctl_nfrntwhlfil_cpy;                             /*BIN7*/
#define VSINFO_STOP_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"


/* 16BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqwhlbrkestim_cpy;                           /*BIN1*/
STATIC VAR(SInt16, AUTOMATIC) vsinfo_vsctl_tqwhlbrkreq_cpy;                             /*BIN1*/
STATIC VAR(UInt16, AUTOMATIC) vsinfo_vsctl_rwhlslip_no1_cpy;                            /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsinfo_vsctl_rwhlslip_no2_cpy;                            /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsinfo_vsctl_spdvehref_cpy;                               /*BIN7*/
#define VSINFO_STOP_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"


/* 8BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_bdgospdvehclc_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_bmonrunspdvehclc_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_stdiagspdveh_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_stgrdlkinfo_cpy;
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(D_Work_VSINFO_Inf_Mnt_Re002tev_Sf, AUTOMATIC) vsinfo_inf_mnt_re002tev_sf_dwork;
/* Static Not Visible area end */
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIniRWhlSlipClc_C = (CONST(UInt16, AUTOMATIC))(10U);     /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_BrkInfo_C = (CONST(UInt16, AUTOMATIC))(29U);        /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_GrdLkInfo_C = (CONST(UInt16, AUTOMATIC))(10U);      /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiInistnFrntWhlModClc_C = (CONST(UInt16, AUTOMATIC))(10U); /*BIN0*/
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/* 8BIT-bits variable definition */
#define VSINFO_START_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvDetLoWhlGrip_C = DDS_FALSE;
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

FUNC(void, AUTOMATIC) VSINFO_Inf_Mnt_Re002tev_Sf(UInt8 VSCtl_stPTInfo_swc_in,
                               UInt32 Ext_nFrntWhl_swc_in,                                 /*BIN7*/
                               UInt8 Ext_stPTCf_swc_in,
                               UInt8 Ext_bSpdReWhlCf_swc_in,
                               UInt8 FRM_bDeacVSCtlGrdLkClc_swc_in,
                               UInt8 FRM_bRcvVSCtlSpdReWhl_swc_in,
                               UInt8 Ext_bDetLoWhlGrip_swc_in,
                               UInt8 Ext_bSpdFrntWhlCf_swc_in,
                               UInt16 VSCtl_rTqWhlPTRe_swc_in,                             /*BIN7*/
                               UInt8 FRM_bRcvVSCtlSpdFrntWhl_swc_in,
                               UInt8 FRM_bDeacVSCtlLoWhlGripClc_swc_in,
                               UInt8 Ext_bTqWhlBrkCf_swc_in,
                               UInt16 Veh_spdVeh_swc_in,                                   /*BIN7*/
                               SInt16 Brk_tqWhlBrkEstim_swc_in,                            /*BIN1*/
                               UInt8 FRM_bDeacSpdVehClc_swc_in,
                               UInt8 Ext_bDetLoWhlGripCf_swc_in,
                               UInt8 FRM_bDeacVSCtlBrkClc_swc_in,
                               UInt8 FRM_bDeacVSCtlWhlSlipClc_swc_in,
                               SInt16 Brk_tqWhlBrkReq_swc_in,                              /*BIN1*/
                               UInt8 FRM_bDeacNFrntWhlClc_swc_in,
                               UInt16 Ext_spdReWhl_swc_in,                                 /*BIN7*/
                               UInt16 Ext_spdFrntWhl_swc_in,                               /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stDiagSpdVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGrdLkInfo_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehRef_swc_out,                              /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkReq_swc_out,                            /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoSpdVehClc_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunSpdVehClc_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nFrntWhlFil_swc_out,                            /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkEstim_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no1_swc_out,                           /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no2_swc_out)                           /*BIN7*/
{

  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F131_Diagnostiquer_Configuration_Reconfiguration*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.159.0 */

  if (vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c171_VSINFO_Inf_Mnt_Re002tev_Sf
      == 0)
  {
    vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c171_VSINFO_Inf_Mnt_Re002tev_Sf =
      1U;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_c171_VSINFO_Inf_Mnt_Re002tev_Sf =
      (UInt8)
      VSINFO_Inf_Mnt_Re002tev_Sf_IN_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
      = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_f;
    vsinfo_vsctl_stdiagspdveh_cpy = VSCTL_STDIAGSPDVEH_ARRET;
    vsinfo_vsctl_bdgospdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;
    vsinfo_vsctl_bmonrunspdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;

  }
  else
  {
    switch
      (vsinfo_inf_mnt_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION)
    {
     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_f:
      if ((VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_NOMINAL_7)
      && ((((Ext_stPTCf_swc_in ==
              EXT_STPTCF_TRACTION) && (Ext_bSpdFrntWhlCf_swc_in ==
              EXT_BSPDFRNTWHLCF_ABSENT)) || ((Ext_stPTCf_swc_in ==
              EXT_STPTCF_PROPULSION) && (Ext_bSpdReWhlCf_swc_in ==
              EXT_BSPDREWHLCF_ABSENT)))
              || ((Ext_stPTCf_swc_in == EXT_STPTCF_INTEGRAL)
              &&
            ((Ext_bSpdFrntWhlCf_swc_in == EXT_BSPDFRNTWHLCF_ABSENT)
            || (Ext_bSpdReWhlCf_swc_in
              == EXT_BSPDREWHLCF_ABSENT)))))
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
          = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_h;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_m;
        vsinfo_vsctl_stdiagspdveh_cpy = VSCTL_STDIAGSPDVEH_DEFAUT_36;
        vsinfo_vsctl_bdgospdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_d;
        vsinfo_vsctl_bmonrunspdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_d;

      }
      else if ((VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_NOMINAL_7)
      && ((((Ext_stPTCf_swc_in ==
        EXT_STPTCF_TRACTION)
        && (Ext_bSpdFrntWhlCf_swc_in == EXT_BSPDFRNTWHLCF_PRESENT))

        || ((Ext_stPTCf_swc_in == EXT_STPTCF_PROPULSION)
        && (Ext_bSpdReWhlCf_swc_in ==
          EXT_BSPDREWHLCF_PRESENT)))
          || (((Ext_stPTCf_swc_in == EXT_STPTCF_INTEGRAL)
          &&
                    (Ext_bSpdFrntWhlCf_swc_in == EXT_BSPDFRNTWHLCF_PRESENT))
                    &&
                   (Ext_bSpdReWhlCf_swc_in == EXT_BSPDREWHLCF_PRESENT))))
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
          = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_h;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_l;
        vsinfo_vsctl_stdiagspdveh_cpy = VSCTL_STDIAGSPDVEH_NOMINAL_36;
        vsinfo_vsctl_bdgospdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;
        vsinfo_vsctl_bmonrunspdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_d;
      }
      break;

     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_h:
      if (VSCtl_stPTInfo_swc_in != VSCTL_STPTINFO_NOMINAL_7)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_m;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
          = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_f;
        vsinfo_vsctl_stdiagspdveh_cpy = VSCTL_STDIAGSPDVEH_ARRET;
        vsinfo_vsctl_bdgospdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;
        vsinfo_vsctl_bmonrunspdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;

      }
      else
      {
        switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_j)
      {
         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_m:
          if ((((Ext_stPTCf_swc_in == EXT_STPTCF_TRACTION)
          && (Ext_bSpdFrntWhlCf_swc_in ==
                 EXT_BSPDFRNTWHLCF_PRESENT)) || ((Ext_stPTCf_swc_in ==
                 EXT_STPTCF_PROPULSION) && (Ext_bSpdReWhlCf_swc_in ==
                 EXT_BSPDREWHLCF_PRESENT))) || (((Ext_stPTCf_swc_in ==
                 EXT_STPTCF_INTEGRAL) && (Ext_bSpdFrntWhlCf_swc_in ==
                 EXT_BSPDFRNTWHLCF_PRESENT)) && (Ext_bSpdReWhlCf_swc_in ==
                EXT_BSPDREWHLCF_PRESENT)))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_l;
            vsinfo_vsctl_stdiagspdveh_cpy = VSCTL_STDIAGSPDVEH_NOMINAL_36;
            vsinfo_vsctl_bdgospdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;
            vsinfo_vsctl_bmonrunspdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_d;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_l:
          if ((((Ext_stPTCf_swc_in == EXT_STPTCF_TRACTION)
          && (Ext_bSpdFrntWhlCf_swc_in ==
                 EXT_BSPDFRNTWHLCF_ABSENT)) || ((Ext_stPTCf_swc_in ==
                 EXT_STPTCF_PROPULSION) && (Ext_bSpdReWhlCf_swc_in ==
                 EXT_BSPDREWHLCF_ABSENT))) || ((Ext_stPTCf_swc_in ==
                EXT_STPTCF_INTEGRAL) && ((Ext_bSpdFrntWhlCf_swc_in ==
                 EXT_BSPDFRNTWHLCF_ABSENT) || (Ext_bSpdReWhlCf_swc_in ==
                 EXT_BSPDREWHLCF_ABSENT))))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_j = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_m;
            vsinfo_vsctl_stdiagspdveh_cpy = VSCTL_STDIAGSPDVEH_DEFAUT_36;
            vsinfo_vsctl_bdgospdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_d;
            vsinfo_vsctl_bmonrunspdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_d;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_inf_mnt_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION
        = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_f;
      vsinfo_vsctl_stdiagspdveh_cpy = VSCTL_STDIAGSPDVEH_ARRET;
      vsinfo_vsctl_bdgospdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;
      vsinfo_vsctl_bmonrunspdvehclc_cpy = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_i;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F131_Diagnostiquer_Configuration_Reconfiguration*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F132_Determiner_Etat_Informations_LAS*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.160.0 */

  if (vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c172_VSINFO_Inf_Mnt_Re002tev_Sf
      == 0)
  {
    vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c172_VSINFO_Inf_Mnt_Re002tev_Sf =
      1U;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_c172_VSINFO_Inf_Mnt_Re002tev_Sf =
      (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ETAT_INFORMATIONS_LAS;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_LAS = (UInt8)
      VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_b;
    vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_ARRET;
    VSCtl_tiIniGrdLkClc = VSCtl_tiIni_GrdLkInfo_C;

  }
  else
  {
    switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_LAS)
          {
     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_b:
      if (VSCtl_stPTInfo_swc_in != VSCTL_STPTINFO_ARRET)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_LAS = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_d;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_c;
        vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_VERIF_35;
      }
      break;

     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_d:
      if (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_ARRET)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_a = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_LAS = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_b;
        vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_ARRET;
        VSCtl_tiIniGrdLkClc = VSCtl_tiIni_GrdLkInfo_C;

      }
      else
      {
        switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i)
      {
         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_n:
          if (((FRM_bDeacVSCtlGrdLkClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_e)
          &&
               (vsinfo_vsctl_stdiagspdveh_cpy == VSCTL_STDIAGSPDVEH_NOMINAL_36))
               &&
              (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_NOMINAL_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_f;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_a = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_l;
            vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_INIT_35;
            VSCtl_tiIniGrdLkClc = VSCtl_tiIni_GrdLkInfo_C;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_f:
          if (((FRM_bDeacVSCtlGrdLkClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_f)
          ||
               (vsinfo_vsctl_stdiagspdveh_cpy == VSCTL_STDIAGSPDVEH_DEFAUT_36))
               ||
              (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_DEFAUT_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_a = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_g;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_n;
            vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_DEFAUT_35;

          }
          else
          {
            switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_a)
          {
             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_l:
              if (VSCtl_tiIniGrdLkClc == 0)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_a = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_a;
                vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_NOMINAL_35;

              }
              else
              {
                VSCtl_tiIniGrdLkClc = (UInt16)DDS_M_MAX(VSCtl_tiIniGrdLkClc - 1,
                  0);
              }
              break;
            }
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_c:
          if (((FRM_bDeacVSCtlGrdLkClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_f)
          ||
               (vsinfo_vsctl_stdiagspdveh_cpy == VSCTL_STDIAGSPDVEH_DEFAUT_36))
               ||
              (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_DEFAUT_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_n;
            vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_DEFAUT_35;

          }
          else if (((FRM_bDeacVSCtlGrdLkClc_swc_in ==
                       VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_e)
                       && (vsinfo_vsctl_stdiagspdveh_cpy
            == VSCTL_STDIAGSPDVEH_NOMINAL_36)) && (VSCtl_stPTInfo_swc_in ==
                      VSCTL_STPTINFO_NOMINAL_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_f;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_a = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_l;
            vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_INIT_35;
            VSCtl_tiIniGrdLkClc = VSCtl_tiIni_GrdLkInfo_C;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_LAS = (UInt8)
        VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_b;
      vsinfo_vsctl_stgrdlkinfo_cpy = VSCTL_STGRDLKINFO_ARRET;
      VSCtl_tiIniGrdLkClc = VSCtl_tiIni_GrdLkInfo_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F132_Determiner_Etat_Informations_LAS*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F1341_Determiner_Mode_Calcul_Glissement_Relatif*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.165.0 */

  if (vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c174_VSINFO_Inf_Mnt_Re002tev_Sf
      == 0)
  {
    vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c174_VSINFO_Inf_Mnt_Re002tev_Sf =
      1U;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_c174_VSINFO_Inf_Mnt_Re002tev_Sf =
      (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_GLISSEMENT_RELATIF;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_GLISSEMENT_RELATIF =
      (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_i;
    VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_ARRET;
    VSCtl_bAcvFil_rWhlSlipClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq;

  }
  else
  {
    switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_GLISSEMENT_RELATIF)
    {
     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_i:
      if (((vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_NOMINAL_35) &&
           (Ext_bSpdFrntWhlCf_swc_in == EXT_BSPDFRNTWHLCF_PRESENT))
           && (Ext_bSpdReWhlCf_swc_in
           == EXT_BSPDREWHLCF_PRESENT))
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_GLISSEMENT_RELATIF =
          (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_ht;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_b;
        VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_VERIF_19;
      }
      break;

     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_ht:
      if (((vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_ARRET)
      || (Ext_bSpdFrntWhlCf_swc_in
            != EXT_BSPDFRNTWHLCF_PRESENT)) || (Ext_bSpdReWhlCf_swc_in !=
           EXT_BSPDREWHLCF_PRESENT))
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_f;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_l = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_f;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_GLISSEMENT_RELATIF =
          (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_i;
        VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_ARRET;
        VSCtl_bAcvFil_rWhlSlipClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq;

      }
      else
      {
        switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok)
      {
         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_p:
          if ((FRM_bDeacVSCtlWhlSlipClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq)
          &&
              (vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_NOMINAL_35))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_g;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_l = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_p;
            VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_INIT_19;
            VSCtl_tiIniRWhlSlipClc = VSCtl_tiIniRWhlSlipClc_C;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_g:
          if (FRM_bDeacVSCtlWhlSlipClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_i)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_l = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_f;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_p;
            VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_DEFAUT_19;
            VSCtl_bAcvFil_rWhlSlipClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq;

          }
          else
          {
            switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_l)
          {
             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_p:
              if (VSCtl_tiIniRWhlSlipClc == 0)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_l = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_k;
                VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_NOMINAL_19;
                VSCtl_bAcvFil_rWhlSlipClc = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_i;

              }
              else
              {
                VSCtl_tiIniRWhlSlipClc = (UInt16)DDS_M_MAX(VSCtl_tiIniRWhlSlipClc
                  - 1, 0);
              }
              break;
            }
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_b:
          if ((FRM_bDeacVSCtlWhlSlipClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_i)
          ||
              (vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_DEFAUT_35))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_p;
            VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_DEFAUT_19;
            VSCtl_bAcvFil_rWhlSlipClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq;

          }
          else if ((FRM_bDeacVSCtlWhlSlipClc_swc_in ==
                      VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq)
                      && (vsinfo_vsctl_stgrdlkinfo_cpy ==
                      VSCTL_STGRDLKINFO_NOMINAL_35))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_g;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_l = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_p;
            VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_INIT_19;
            VSCtl_tiIniRWhlSlipClc = VSCtl_tiIniRWhlSlipClc_C;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_GLISSEMENT_RELATIF =
        (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_i;
      VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_ARRET;
      VSCtl_bAcvFil_rWhlSlipClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_iq;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1341_Determiner_Mode_Calcul_Glissement_Relatif*/

  VSINFO_F1342_Determiner_Glissement_Relatif(Ext_spdFrntWhl_swc_in, /* BIN7 */
                                           Ext_spdReWhl_swc_in, /* BIN7 */
                                           &vsinfo_vsctl_rwhlslip_no1_cpy, /* BIN7 */
                                           &vsinfo_vsctl_rwhlslip_no2_cpy /* BIN7 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F1361_Determiner_Mode_Calcul_Regime_Roue_Avant*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.168.0 */

  if (vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c176_VSINFO_Inf_Mnt_Re002tev_Sf
      == 0)
  {
    vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c176_VSINFO_Inf_Mnt_Re002tev_Sf =
      1U;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_c176_VSINFO_Inf_Mnt_Re002tev_Sf =
      (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_REGIME_ROUE_AVANT;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_REGIME_ROUE_AVANT = (UInt8)
      VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_bg;
    VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_ARRET;
    VSCtl_bAcvFil_nFrntWhlClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m;

  }
  else
  {
    switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_REGIME_ROUE_AVANT)
          {
     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_bg:
      if (vsinfo_vsctl_stgrdlkinfo_cpy != VSCTL_STGRDLKINFO_ARRET)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_REGIME_ROUE_AVANT =
          (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_f;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_ll;
        VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_VERIF_37;
      }
      break;

     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_f:
      if (vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_ARRET)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_m = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_REGIME_ROUE_AVANT =
          (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_bg;
        VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_ARRET;
        VSCtl_bAcvFil_nFrntWhlClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m;

      }
      else
      {
        switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE)
      {
         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_h:
          if ((vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_NOMINAL_35) &&
              (FRM_bDeacNFrntWhlClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_m;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_m = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_d;
            VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_INIT_37;
            VSCtl_tiInistnFrntWhlModClc = VSCtl_tiInistnFrntWhlModClc_C;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_m:
          if ((vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_DEFAUT_35) ||
              (FRM_bDeacNFrntWhlClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_b))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_m = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_n;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_h;
            VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_DEFAUT_37;
            VSCtl_bAcvFil_nFrntWhlClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m;

          }
          else
          {
            switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_m)
          {
             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_d:
              if (VSCtl_tiInistnFrntWhlModClc == 0)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_m = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_ka;
                VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_NOMINAL_37;

              }
              else
              {
                VSCtl_tiInistnFrntWhlModClc = (UInt16)DDS_M_MAX
                  (VSCtl_tiInistnFrntWhlModClc - 1, 0);
              }
              break;

             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_ka:
              VSCtl_bAcvFil_nFrntWhlClc = VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_b;
              break;
            }
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_ll:
          if ((vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_DEFAUT_35) ||
              (FRM_bDeacNFrntWhlClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_b))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_h;
            VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_DEFAUT_37;
            VSCtl_bAcvFil_nFrntWhlClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m;

          }
          else if ((vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_NOMINAL_35)
          &&
                     (FRM_bDeacNFrntWhlClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_m;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_m = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_d;
            VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_INIT_37;
            VSCtl_tiInistnFrntWhlModClc = VSCtl_tiInistnFrntWhlModClc_C;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_REGIME_ROUE_AVANT =
        (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_bg;
      VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_ARRET;
      VSCtl_bAcvFil_nFrntWhlClc = VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_m;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1361_Determiner_Mode_Calcul_Regime_Roue_Avant*/

  VSINFO_F1362_Determiner_Regime_Roue_Avant(Ext_nFrntWhl_swc_in, /* BIN7 */
                                            &vsinfo_vsctl_nfrntwhlfil_cpy /* BIN7 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F121_Determiner_Etat_Informations_Frein*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.86.3 */

  if (vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c170_VSINFO_Inf_Mnt_Re002tev_Sf
      == 0)
  {
    vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c170_VSINFO_Inf_Mnt_Re002tev_Sf =
      1U;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_c170_VSINFO_Inf_Mnt_Re002tev_Sf =
      (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ETAT_INFORMATIONS_FREIN;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_FREIN = (UInt8)
      VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET;
    VSCtl_stBrkInfo = VSCTL_STBRKINFO_ARRET;
    VSCtl_tiIniBrkClc = VSCtl_tiIni_BrkInfo_C;

  }
  else
  {
    switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_FREIN)
          {
     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET:
      if (VSCtl_stPTInfo_swc_in != VSCTL_STPTINFO_ARRET)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_FREIN = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF;
        VSCtl_stBrkInfo = VSCTL_STBRKINFO_VERIF_11;
      }
      break;

     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE:
      if (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_ARRET)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_p = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_FREIN = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET;
        VSCtl_stBrkInfo = VSCTL_STBRKINFO_ARRET;
        VSCtl_tiIniBrkClc = VSCtl_tiIni_BrkInfo_C;

      }
      else
      {
        switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k)
      {
         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT:
          if ((FRM_bDeacVSCtlBrkClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX)
          &&
              (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_NOMINAL_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_p = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT;
            VSCtl_stBrkInfo = VSCTL_STBRKINFO_INIT_11;
            VSCtl_tiIniBrkClc = VSCtl_tiIni_BrkInfo_C;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT:
          if ((FRM_bDeacVSCtlBrkClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI)
          ||
              (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_DEFAUT_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_p = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT;
            VSCtl_stBrkInfo = VSCTL_STBRKINFO_DEFAUT_11;

          }
          else
          {
            switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_p)
          {
             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT:
              if (VSCtl_tiIniBrkClc == 0)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_p = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL;
                VSCtl_stBrkInfo = VSCTL_STBRKINFO_NOMINAL_11;

              }
              else
              {
                VSCtl_tiIniBrkClc = (UInt16)DDS_M_MAX(VSCtl_tiIniBrkClc - 1, 0);
              }
              break;
            }
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF:
          if ((FRM_bDeacVSCtlBrkClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI)
          ||
              (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_DEFAUT_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT;
            VSCtl_stBrkInfo = VSCTL_STBRKINFO_DEFAUT_11;

          }
          else if ((FRM_bDeacVSCtlBrkClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX)
          &&
                     (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_NOMINAL_7))
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_p = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT;
            VSCtl_stBrkInfo = VSCTL_STBRKINFO_INIT_11;
            VSCtl_tiIniBrkClc = VSCtl_tiIni_BrkInfo_C;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_FREIN = (UInt8)
        VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET;
      VSCtl_stBrkInfo = VSCTL_STBRKINFO_ARRET;
      VSCtl_tiIniBrkClc = VSCtl_tiIni_BrkInfo_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F121_Determiner_Etat_Informations_Frein*/

  VSINFO_F122_Determiner_Couples_Roue_Frein(Brk_tqWhlBrkEstim_swc_in, /* BIN1 */
                                            Brk_tqWhlBrkReq_swc_in, /* BIN1 */
                                            Ext_bTqWhlBrkCf_swc_in,
                                            &vsinfo_vsctl_tqwhlbrkestim_cpy,
                                            &vsinfo_vsctl_tqwhlbrkreq_cpy);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F1331_Determiner_Mode_Calcul_Vitesse_Vehicule_Reference*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.162.0 */

  if (vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c173_VSINFO_Inf_Mnt_Re002tev_Sf
      == 0)
  {
    vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c173_VSINFO_Inf_Mnt_Re002tev_Sf =
      1U;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_c173_VSINFO_Inf_Mnt_Re002tev_Sf =
      (UInt8)
      VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE =
      (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_fi;
    VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_ARRET;

  }
  else
  {
    switch
      (vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE)
    {
     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_fi:
      if (vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_NOMINAL_35)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE
          = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_m;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_l;
        VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_VERIF_16;
      }
      break;

     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_m:
      if (vsinfo_vsctl_stgrdlkinfo_cpy != VSCTL_STGRDLKINFO_NOMINAL_35)
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE
          = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_fi;
        VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_ARRET;

      }
      else
      {
        switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c)
      {
         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_j:
          if (FRM_bDeacSpdVehClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_h)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_j;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_m;
            VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_INIT_16;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_j:
          if (FRM_bDeacSpdVehClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_m)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_d;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_j;
            VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_DEFAUT_16;

          }
          else
          {
            switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT)
          {
             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_m:
              if (Ext_stPTCf_swc_in == EXT_STPTCF_TRACTION)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_AVANT;
                VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_AVANT_16;

              }
              else if (Ext_stPTCf_swc_in == EXT_STPTCF_PROPULSION)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_ARRIERE;
                VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_ARRIERE_16;

              }
              else if (Ext_stPTCf_swc_in == EXT_STPTCF_INTEGRAL)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_INTEGRAL;
                VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_INTEGRAL_16;
              }
              break;

             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_ARRIERE:
              if (Ext_stPTCf_swc_in != EXT_STPTCF_PROPULSION)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_m;
                VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_INIT_16;
              }
              break;

             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_AVANT:
              if (Ext_stPTCf_swc_in != EXT_STPTCF_TRACTION)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_m;
                VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_INIT_16;
              }
              break;

             case VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_INTEGRAL:
              if (Ext_stPTCf_swc_in != EXT_STPTCF_INTEGRAL)
              {
                vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_m;
                VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_INIT_16;
              }
              break;
            }
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_l:
          if (FRM_bDeacSpdVehClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_m)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_j;
            VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_DEFAUT_16;

          }
          else if (FRM_bDeacSpdVehClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_h)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_PAS_DEFAUT_j;
            vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_INIT_m;
            VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_INIT_16;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE
        = (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_fi;
      VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_ARRET;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1331_Determiner_Mode_Calcul_Vitesse_Vehicule_Reference*/

  VSINFO_F1332_Determiner_Vitesse_Vehicule_Reference(Ext_spdFrntWhl_swc_in, /* BIN7 */
                                                    Ext_spdReWhl_swc_in, /* BIN7 */
                                                    FRM_bRcvVSCtlSpdFrntWhl_swc_in,
                                                    FRM_bRcvVSCtlSpdReWhl_swc_in,
                                                    VSCtl_rTqWhlPTRe_swc_in, /* BIN7 */
                                                    Veh_spdVeh_swc_in, /* BIN7 */
                                                    &vsinfo_vsctl_spdvehref_cpy /* BIN7 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F1351_Determiner_Mode_Calcul_Niveau_Adherence*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.107.1 */

  if (vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c175_VSINFO_Inf_Mnt_Re002tev_Sf
      == 0)
  {
    vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c175_VSINFO_Inf_Mnt_Re002tev_Sf =
      1U;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_c175_VSINFO_Inf_Mnt_Re002tev_Sf =
      (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MODE_CALCUL_NIVEAU_ADHERENCE;
    vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_NIVEAU_ADHERENCE = (UInt8)
      VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_n;
    VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_ARRET;

  }
  else
  {
    switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_NIVEAU_ADHERENCE)
          {
     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_n:
      if (((vsinfo_vsctl_stgrdlkinfo_cpy == VSCTL_STGRDLKINFO_NOMINAL_35) &&
           (Ext_bDetLoWhlGripCf_swc_in == EXT_BDETLOWHLGRIPCF_PRESENT)) &&
          (VSCtl_bAcvDetLoWhlGrip_C == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_md))
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_NIVEAU_ADHERENCE =
          (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_hx;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_a;
        VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_VERIF_21;
      }
      break;

     case VSINFO_Inf_Mnt_Re002tev_Sf_IN_MARCHE_hx:
      if (((vsinfo_vsctl_stgrdlkinfo_cpy != VSCTL_STGRDLKINFO_NOMINAL_35) ||
           (Ext_bDetLoWhlGripCf_swc_in != EXT_BDETLOWHLGRIPCF_PRESENT)) ||
          (VSCtl_bAcvDetLoWhlGrip_C == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_c))
      {
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
          VSINFO_Inf_Mnt_Re002tev_Sf_IN_NO_ACTIVE_CHILD_c;
        vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_NIVEAU_ADHERENCE =
          (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_n;
        VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_ARRET;

      }
      else
      {
        switch (vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o)
      {
         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_c:
          if (FRM_bDeacVSCtlLoWhlGripClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_c)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_c;
            VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_NOMINAL_21;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_c:
          if (FRM_bDeacVSCtlLoWhlGripClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_md)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_c;
            VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_DEFAUT_21;
          }
          break;

         case VSINFO_Inf_Mnt_Re002tev_Sf_IN_VERIF_a:
          if (FRM_bDeacVSCtlLoWhlGripClc_swc_in == VSINFO_Inf_Mnt_Re002tev_Sf_VRAI_md)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_DEFAUT_c;
            VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_DEFAUT_21;

          }
          else if (FRM_bDeacVSCtlLoWhlGripClc_swc_in ==
                     VSINFO_Inf_Mnt_Re002tev_Sf_FAUX_c)
          {
            vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o = (UInt8)
              VSINFO_Inf_Mnt_Re002tev_Sf_IN_NOMINAL_c;
            VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_NOMINAL_21;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_NIVEAU_ADHERENCE =
        (UInt8)VSINFO_Inf_Mnt_Re002tev_Sf_IN_ARRET_n;
      VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_ARRET;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1351_Determiner_Mode_Calcul_Niveau_Adherence*/

  VSINFO_F1352_Determiner_Niveau_Adherence(Ext_bDetLoWhlGrip_swc_in);

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_nFrntWhlFil_swc_out = vsinfo_vsctl_nfrntwhlfil_cpy;

  *VSCtl_tqWhlBrkEstim_swc_out = vsinfo_vsctl_tqwhlbrkestim_cpy;

  *VSCtl_tqWhlBrkReq_swc_out = vsinfo_vsctl_tqwhlbrkreq_cpy;

  *VSCtl_rWhlSlip_no1_swc_out = vsinfo_vsctl_rwhlslip_no1_cpy;

  *VSCtl_rWhlSlip_no2_swc_out = vsinfo_vsctl_rwhlslip_no2_cpy;

  *VSCtl_spdVehRef_swc_out = vsinfo_vsctl_spdvehref_cpy;

  *VSCtl_bDgoSpdVehClc_swc_out = vsinfo_vsctl_bdgospdvehclc_cpy;

  *VSCtl_bMonRunSpdVehClc_swc_out = vsinfo_vsctl_bmonrunspdvehclc_cpy;

  *VSCtl_stDiagSpdVeh_swc_out = vsinfo_vsctl_stdiagspdveh_cpy;

  *VSCtl_stGrdLkInfo_swc_out = vsinfo_vsctl_stgrdlkinfo_cpy;

}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Inf_Mnt_Re002tev_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stDiagSpdVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGrdLkInfo_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehRef_swc_out,                              /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkReq_swc_out,                            /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoSpdVehClc_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunSpdVehClc_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nFrntWhlFil_swc_out,                            /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkEstim_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no1_swc_out,                           /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no2_swc_out)                           /*BIN7*/
{
    VSINFO_Elabor_Info_Brake_Sl_Init(VSCtl_tqWhlBrkEstim_swc_out,
                                        VSCtl_tqWhlBrkReq_swc_out);

    VSINFO_Elabor_Info_Las_Sl_Init(VSCtl_rWhlSlip_no1_swc_out, /* BIN7 */
                                    VSCtl_rWhlSlip_no2_swc_out, /* BIN7 */
                                    VSCtl_nFrntWhlFil_swc_out, /* BIN7 */
                                    VSCtl_spdVehRef_swc_out /* BIN7 */);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  vsinfo_vsctl_spdvehref_cpy = *VSCtl_spdVehRef_swc_out;

  vsinfo_vsctl_tqwhlbrkestim_cpy = *VSCtl_tqWhlBrkEstim_swc_out;

  vsinfo_vsctl_tqwhlbrkreq_cpy = *VSCtl_tqWhlBrkReq_swc_out;

  vsinfo_vsctl_rwhlslip_no1_cpy = *VSCtl_rWhlSlip_no1_swc_out;

  vsinfo_vsctl_rwhlslip_no2_cpy = *VSCtl_rWhlSlip_no2_swc_out;

  vsinfo_inf_mnt_re002tev_sf_dwork.is_DIAGNOSTIQUER_CONFIGURATION_RECONFIGURATION=0;
  vsinfo_vsctl_nfrntwhlfil_cpy = *VSCtl_nFrntWhlFil_swc_out;

  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiInistnFrntWhlModClc = VSCtl_tiInistnFrntWhlModClc_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIniRWhlSlipClc = VSCtl_tiIniRWhlSlipClc_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIniGrdLkClc = VSCtl_tiIni_GrdLkInfo_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiIniBrkClc = VSCtl_tiIni_BrkInfo_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stnFrntWhlModClc = VSCTL_STNFRNTWHLMODCLC_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_stDetLoWhlGripClc = VSCTL_STDETLOWHLGRIPCLC_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_st_rWhlSlipModClc = VSCTL_ST_RWHLSLIPMODCLC_ARRET;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stVehSpdRefModClc = VSCTL_STVEHSPDREFMODCLC_ARRET;  /* Replaced by Post task */     /* Init from Model */
  *VSCtl_stGrdLkInfo_swc_out = VSCTL_STGRDLKINFO_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsinfo_vsctl_stgrdlkinfo_cpy = *VSCtl_stGrdLkInfo_swc_out;

  *VSCtl_stDiagSpdVeh_swc_out = VSCTL_STDIAGSPDVEH_ARRET;   /* Replaced by Post task */     /* Init from Model */
  vsinfo_vsctl_stdiagspdveh_cpy = *VSCtl_stDiagSpdVeh_swc_out;

  VSCtl_stBrkInfo = VSCTL_STBRKINFO_ARRET;  /* Replaced by Post task */     /* Init from Model */


  vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_j = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c171_VSINFO_Inf_Mnt_Re002tev_Sf =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_c171_VSINFO_Inf_Mnt_Re002tev_Sf = 0U;
  *VSCtl_bDgoSpdVehClc_swc_out =DDS_FALSE;
  vsinfo_vsctl_bdgospdvehclc_cpy = *VSCtl_bDgoSpdVehClc_swc_out;

  *VSCtl_bMonRunSpdVehClc_swc_out =DDS_FALSE;
  vsinfo_vsctl_bmonrunspdvehclc_cpy = *VSCtl_bMonRunSpdVehClc_swc_out;




  vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_LAS = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_i = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_a = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c172_VSINFO_Inf_Mnt_Re002tev_Sf =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_c172_VSINFO_Inf_Mnt_Re002tev_Sf = 0U;



  vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_GLISSEMENT_RELATIF = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_ok = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_l = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c174_VSINFO_Inf_Mnt_Re002tev_Sf =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_c174_VSINFO_Inf_Mnt_Re002tev_Sf = 0U;
  VSCtl_bAcvFil_rWhlSlipClc =DDS_FALSE;



  vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_REGIME_ROUE_AVANT = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_m = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c176_VSINFO_Inf_Mnt_Re002tev_Sf =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_c176_VSINFO_Inf_Mnt_Re002tev_Sf = 0U;
  VSCtl_bAcvFil_nFrntWhlClc =DDS_FALSE;



  vsinfo_inf_mnt_re002tev_sf_dwork.is_ETAT_INFORMATIONS_FREIN = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_k = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT_p = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c170_VSINFO_Inf_Mnt_Re002tev_Sf =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_c170_VSINFO_Inf_Mnt_Re002tev_Sf = 0U;



  vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_VITESSE_VEHICULE_REFERENCE =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_c = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_PAS_DEFAUT = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c173_VSINFO_Inf_Mnt_Re002tev_Sf =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_c173_VSINFO_Inf_Mnt_Re002tev_Sf = 0U;



  vsinfo_inf_mnt_re002tev_sf_dwork.is_MODE_CALCUL_NIVEAU_ADHERENCE = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_MARCHE_o = 0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_active_c175_VSINFO_Inf_Mnt_Re002tev_Sf =
    0U;
  vsinfo_inf_mnt_re002tev_sf_dwork.is_c175_VSINFO_Inf_Mnt_Re002tev_Sf = 0U;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

