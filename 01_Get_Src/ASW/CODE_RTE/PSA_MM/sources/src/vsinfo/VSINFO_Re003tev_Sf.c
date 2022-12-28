/*
* File: VSINFO_Re003tev_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSINFO_Re003tev_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Tue Nov 22 12:26:06 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Tue Nov 22 12:26:08 2011
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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Re003tev_Sf.c
* Version int :/main/L02_02/1 Date: 4/1/2012 16 h 30 m User:esnault 
*    TWK_model:VSINFO_Re003tev_Sf_L02_020_IMPL1
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\3 Date: 4/1/2012 15 h 22 m User:demezil 
*    TWK_model:VSINFO_Re003tev_Sf_L02_020_IMPL1
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 22/11/2011 14 h 28 m User:demezil
*    TWK_model:VSINFO_Re003tev_Sf_L02_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value. ALTIS1698613/FDSA0203901
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 22/11/2011 14 h 3 m User:demezil
*    TWK_model:VSINFO_Re003tev_Sf_L02_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Antisaturation */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Antisaturation ;Brk_bBrkAuto;Brk_bBrkDyn;Ext_bBrkAutoCf;Ext_bBrkDynCf;Ext_bBrkPedPrss;Ext_bPrkBrk;Ext_stGBxCf;VSCtl_bAvlTqWhlPT_no3;VSCtl_stVehInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Antisaturation ;VSCtl_bBrkAuto;VSCtl_bBrkDyn;VSCtl_bBrkPedPrss;VSCtl_bObsAntiSatRaw;VSCtl_bPrkBrk;VSCtl_bSIPFil;VSCtl_tiBrkAuto;VSCtl_tiBrkDyn;VSCtl_tiBrkPedPrss;VSCtl_tiPrkBrk;VSCtl_tiSIP; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Antisaturation */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Informations_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Vehicule ;FRM_bDeacVSCtlVehClc;VSCtl_stGrdLkInfo;VSCtl_stPTInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_Vehicule ;VSCtl_bAcvFilVehInfo;VSCtl_stVehInfo;VSCtl_tiIniVehClc; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Informations_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F142_Determiner_Parametres_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F142_Determiner_Parametres_Vehicule ; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F142_Determiner_Parametres_Vehicule ;VSCtl_SCXVeh;VSCtl_mVeh;VSCtl_rdWhl; */
/* TAG_END_OF_SUB_FUNCTION: F142_Determiner_Parametres_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F143_Filtrer_Vitesse_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F143_Filtrer_Vitesse_Vehicule ;VSCtl_bAcvFilVehInfo;VSCtl_spdVehRef;VSCtl_stVehInfo; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F143_Filtrer_Vitesse_Vehicule ;VSCtl_spdVehFil; */
/* TAG_END_OF_SUB_FUNCTION: F143_Filtrer_Vitesse_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F144_Determiner_Accelerations_GMP */
/* TAG_INPUT_OF_SUB_FUNCTION: F144_Determiner_Accelerations_GMP ;VSCtl_mVeh;VSCtl_rdWhl;VSCtl_stVehInfo;VSCtl_tqWhlPTAplReq;VSCtl_tqWhlPTDrvMinReq;VSCtl_tqWhlPTDrvMinReqRaw;VSCtl_tqWhlPTIni;VSCtl_tqWhlPTLim;VSCtl_tqWhlPTMax;VSCtl_tqWhlPTMaxNotCtla;VSCtl_tqWhlPTMin;VSCtl_tqWhlPTMinNotCtla;VSCtl_tqWhlPTPotMax;VSCtl_tqWhlPTPotMaxCtla_no1;VSCtl_tqWhlPTPotMin;VSCtl_tqWhlPTPreCoVSCtlReq;VSCtl_tqWhlPTReal; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F144_Determiner_Accelerations_GMP ;VSCtl_aPTAplReq;VSCtl_aPTDrvMinReq;VSCtl_aPTDrvMinReqRaw;VSCtl_aPTIni;VSCtl_aPTLim;VSCtl_aPTMax;VSCtl_aPTMaxNotCtla;VSCtl_aPTMin;VSCtl_aPTMinNotCtla;VSCtl_aPTPotMax;VSCtl_aPTPotMaxCtla_no1;VSCtl_aPTPotMin;VSCtl_aPTPreCoVSCtlReq;VSCtl_aPTReal; */
/* TAG_END_OF_SUB_FUNCTION: F144_Determiner_Accelerations_GMP */

/* TAG_START_OF_SUB_FUNCTION: F145_Determiner_Acceleration_Frein */
/* TAG_INPUT_OF_SUB_FUNCTION: F145_Determiner_Acceleration_Frein ;VSCtl_mVeh;VSCtl_rdWhl;VSCtl_stVehInfo;VSCtl_tqWhlBrkEstim;VSCtl_tqWhlBrkReq; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F145_Determiner_Acceleration_Frein ;VSCtl_aBrkEstim;VSCtl_aBrkReq; */
/* TAG_END_OF_SUB_FUNCTION: F145_Determiner_Acceleration_Frein */

/* TAG_START_OF_SUB_FUNCTION: F1462_Determiner_Acceleration_GMP_Filtree */
/* TAG_INPUT_OF_SUB_FUNCTION: F1462_Determiner_Acceleration_GMP_Filtree ;VSCtl_aPTAplReq;VSCtl_aPTReal;VSCtl_bInh_aPT;VSCtl_rAccPT;VSCtl_spdVehFil;VSCtl_stVehInfo; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F1462_Determiner_Acceleration_GMP_Filtree ;VSCtl_aPT; */
/* TAG_END_OF_SUB_FUNCTION: F1462_Determiner_Acceleration_GMP_Filtree */

/* TAG_START_OF_SUB_FUNCTION: F1463_Determiner_Acceleration_Frein_Filtree */
/* TAG_INPUT_OF_SUB_FUNCTION: F1463_Determiner_Acceleration_Frein_Filtree ;VSCtl_aBrkEstim;VSCtl_aBrkReq;VSCtl_rAccPT;VSCtl_spdVehFil;VSCtl_stVehInfo; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F1463_Determiner_Acceleration_Frein_Filtree ;VSCtl_aBrk; */
/* TAG_END_OF_SUB_FUNCTION: F1463_Determiner_Acceleration_Frein_Filtree */

/* TAG_START_OF_STATEFLOW_FUNCTION: Filtrer_Conditions_Antisaturations */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Filtrer_Conditions_Antisaturations ;VSCtl_bObsAntiSatRaw;VSCtl_spdVehFil;VSCtl_stVehInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Filtrer_Conditions_Antisaturations ;VSCtl_bAuthObsAntiSat;VSCtl_bObsAntiSat;VSCtl_bObsAntiSatRaw2;VSCtl_bObsAntiSatRaw2Prev;VSCtl_tiObsAntiSat;VSCtl_tiObsAntiSatRaw; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Filtrer_Conditions_Antisaturations */

/* TAG_START_OF_STATEFLOW_FUNCTION: Modes_Controle_Acceleration */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Acceleration ;Ext_stGBxCf;VSCtl_bAvlTqWhlPT_no3;VSCtl_stVehInfo;VSCtl_tiLgtCtlDynChg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Acceleration ;VSCtl_bInh_aPT;VSCtl_rAccPT; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Modes_Controle_Acceleration */

/* TAG_START_OF_STATEFLOW_FUNCTION: Modes_Controle_Dynamique_Longitudinale */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Dynamique_Longitudinale ;VSCtl_aVehReq;VSCtl_stVehInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Modes_Controle_Dynamique_Longitudinale ;VSCtl_bLgtCtlDyn;VSCtl_tiLgtCtlDynChg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Modes_Controle_Dynamique_Longitudinale */

/* TAG_START_OF_STATEFLOW_FUNCTION: Modes_Estimation */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Modes_Estimation ;VSCtl_bLgtCtlDyn;VSCtl_bObsAntiSat;VSCtl_stVehInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Modes_Estimation ;VSCtl_stObsDyn;VSCtl_tiTranDynAntiSat; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Modes_Estimation */

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

/* Named constants for block: /Etat_Informations_Vehicule' */
#define VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSINFO_Re003tev_Sf_IN_ETAT_INFORMATIONS_VEHICULE (1)
#define VSINFO_Re003tev_Sf_IN_ARRET    (1)
#define VSINFO_Re003tev_Sf_IN_INIT     (1)
#define VSINFO_Re003tev_Sf_IN_NOMINAL  (2)
#define VSINFO_Re003tev_Sf_IN_MARCHE   (2)
#define VSINFO_Re003tev_Sf_IN_DEFAUT   (1)
#define VSINFO_Re003tev_Sf_IN_VERIF    (3)
#define VSINFO_Re003tev_Sf_IN_PAS_DEFAUT (2)
#define VSINFO_Re003tev_Sf_VRAI        (1U)
#define VSINFO_Re003tev_Sf_FAUX        (0U)

/* Named constants for block: /Modes_Controle_Dynamique_Longitudinale' */
#define VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_g (0)
#define VSINFO_Re003tev_Sf_IN_LENTE    (3)
#define VSINFO_Re003tev_Sf_IN_CONF     (1)
#define VSINFO_Re003tev_Sf_IN_DECONF   (2)
#define VSINFO_Re003tev_Sf_IN_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE (1)
#define VSINFO_Re003tev_Sf_IN_RAPIDE   (4)
#define VSINFO_Re003tev_Sf_IN_NON_INIT (2)
#define VSINFO_Re003tev_Sf_IN_INIT_o   (1)

/* Named constants for block: /Modes_Controle_Acceleration' */
#define VSINFO_Re003tev_Sf_IN_ARRET_o  (1)
#define VSINFO_Re003tev_Sf_IN_CONF_e   (2)
#define VSINFO_Re003tev_Sf_IN_FAUX     (1)
#define VSINFO_Re003tev_Sf_IN_VRAI     (2)
#define VSINFO_Re003tev_Sf_IN_MODES_CONTROLE_ACCELERATION (1)
#define VSINFO_Re003tev_Sf_FAUX_p      (0U)
#define VSINFO_Re003tev_Sf_VRAI_e      (1U)

/* Named constants for block: /Condition_Antisaturation' */
#define VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_p (0)
#define VSINFO_Re003tev_Sf_IN_INACTIF  (1)
#define VSINFO_Re003tev_Sf_IN_ACTIF    (1)
#define VSINFO_Re003tev_Sf_IN_NON_INACTIF (2)
#define VSINFO_Re003tev_Sf_IN_PERMANENT (2)
#define VSINFO_Re003tev_Sf_IN_CONDITIONS_ANTISATURATION (1)
#define VSINFO_Re003tev_Sf_IN_INACTIF____0 (2)
#define VSINFO_Re003tev_Sf_FAUX_p0     (0U)
#define VSINFO_Re003tev_Sf_VRAI_f      (1U)

/* Named constants for block: /Filtrer_Conditions_Antisaturations' */
#define VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_k (0)
#define VSINFO_Re003tev_Sf_IN_INIT_j   (1)
#define VSINFO_Re003tev_Sf_IN_ANTISAT  (1)
#define VSINFO_Re003tev_Sf_IN_NON_INIT_d (2)
#define VSINFO_Re003tev_Sf_IN_FILTRER_CONDITIONS_ANTISATURATIONS (1)
#define VSINFO_Re003tev_Sf_IN_NORMAL   (2)
#define VSINFO_Re003tev_Sf_IN_CONF_m   (1)
#define VSINFO_Re003tev_Sf_IN_NON_INACTIF_a (2)
#define VSINFO_Re003tev_Sf_IN_DECONF_g (2)
#define VSINFO_Re003tev_Sf_IN_REHAB    (3)
#define VSINFO_Re003tev_Sf_IN_INACTIF_a (1)
#define VSINFO_Re003tev_Sf_IN_ACTIF_f  (1)
#define VSINFO_Re003tev_Sf_IN_PERMANENT_c (2)
#define VSINFO_Re003tev_Sf_FAUX_e      (0U)
#define VSINFO_Re003tev_Sf_VRAI_n      (1U)

/* Named constants for block: /Modes_Estimation' */
#define VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_f (0)
#define VSINFO_Re003tev_Sf_IN_NOMINAL_h (2)
#define VSINFO_Re003tev_Sf_IN_ANTISATURATION (1)
#define VSINFO_Re003tev_Sf_IN_INIT_a   (1)
#define VSINFO_Re003tev_Sf_IN_MODES_ESTIMATION (1)
#define VSINFO_Re003tev_Sf_IN_NON_INIT_dn (2)
#define VSINFO_Re003tev_Sf_IN_STABILISE (1)
#define VSINFO_Re003tev_Sf_IN_TRANSITOIRE (2)
#define VSINFO_Re003tev_Sf_FAUX_f      (0U)
#define VSINFO_Re003tev_Sf_VRAI_d      (1U)

/* Definition for custom storage class: Define */
#define VSCTL_RACCPT_MAX               12800U
#define VSINFO_100_BIN7                12800

#define VSCTL_BLGTCTLDYN_TRANSITOIRE        (0)
#define VSCTL_BLGTCTLDYN_STABILISE          (1)
#define EXT_BBRKDYNCF_PRESENT               (1)
#define EXT_BBRKDYNCF_ABSENT                (0)
#define EXT_BBRKAUTOCF_PRESENT              (1)
#define EXT_BBRKAUTOCF_ABSENT               (0)

/* VSCtl_stObsDyn */
#define VSCTL_STOBSDYN_DYN_INIT             (0)
#define VSCTL_STOBSDYN_DYN_TRANSITOIRE      (1)
#define VSCTL_STOBSDYN_DYN_STABILISE        (2)
#define VSCTL_STOBSDYN_DYN_ANTISATURATION   (3)

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehFil;       /*BIN7*/
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_rAccPT;       /*BIN7*/
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stObsDyn;
VAR(UInt8, AUTOMATIC) VSCtl_bInh_aPT;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilVehInfo;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt16 VSCtl_rAccPT_h;
} BlockIO_VSINFO_Re003tev_Sf;


typedef struct {
  UInt32 is_NON_INIT : 3;
  UInt32 is_NOMINAL : 2;
  UInt32 is_MODES_ESTIMATION : 2;
  UInt32 is_NON_INIT_f : 2;
  UInt32 is_ANTISATURATION : 2;
  UInt32 is_NON_INIT_g : 2;
  UInt32 is_AUTORISATION_ANTISATURATION : 2;
  UInt32 is_NON_INACTIF : 2;
  UInt32 is_FILTRAGE_ANTISATURATION_PERMANENTE : 2;
  UInt32 is_NON_INACTIF_l : 2;
  UInt32 is_SERRAGE_FREIN_MANUEL : 2;
  UInt32 is_APPUI_PEDALE_FREIN : 2;
  UInt32 is_NON_INACTIF_p : 2;
  UInt32 is_NON_INACTIF_g : 2;
  UInt32 is_FREINAGE_DYNAMIQUE : 2;
  UInt32 is_NON_INACTIF_lw : 2;
  UInt32 is_FREINAGE_AUTOMATIQUE : 2;
  UInt32 is_CHANGEMENT_RAPPORT_PERMANENT : 2;
  UInt32 is_NON_INACTIF_px : 2;
  UInt32 is_ANTISATURATION_BRUTE : 2;
  UInt32 is_TAUX_LISSAGE_ACCELERATION : 2;
  UInt32 is_INHIBITION_ACCELERATION_GMP : 2;
  UInt32 is_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE : 2;
  UInt32 is_ETAT_INFORMATIONS_VEHICULE : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_PAS_DEFAUT : 2;
  UInt32 is_active_c182_VSINFO_Re003tev_Sf : 1;
  UInt32 is_c182_VSINFO_Re003tev_Sf : 1;
  UInt32 is_active_c181_VSINFO_Re003tev_Sf : 1;
  UInt32 is_c181_VSINFO_Re003tev_Sf : 1;
  UInt32 is_active_ANTISATURATION : 1;
  UInt32 is_active_AUTORISATION_ANTISATURATION : 1;
  UInt32 is_active_FILTRAGE_ANTISATURATION_PERMANENTE : 1;
  UInt32 is_active_c180_VSINFO_Re003tev_Sf : 1;
  UInt32 is_c180_VSINFO_Re003tev_Sf : 1;
  UInt32 is_active_SERRAGE_FREIN_MANUEL : 1;
  UInt32 is_active_APPUI_PEDALE_FREIN : 1;
  UInt32 is_active_FREINAGE_DYNAMIQUE : 1;
  UInt32 is_active_FREINAGE_AUTOMATIQUE : 1;
  UInt32 is_active_CHANGEMENT_RAPPORT_PERMANENT : 1;
  UInt32 is_active_ANTISATURATION_BRUTE : 1;
  UInt32 is_active_c179_VSINFO_Re003tev_Sf : 1;
  UInt32 is_c179_VSINFO_Re003tev_Sf : 1;
  UInt32 is_active_TAUX_LISSAGE_ACCELERATION : 1;
  UInt32 is_active_INHIBITION_ACCELERATION_GMP : 1;
  UInt32 is_active_c178_VSINFO_Re003tev_Sf : 1;
  UInt32 is_c178_VSINFO_Re003tev_Sf : 1;
  UInt32 is_active_c177_VSINFO_Re003tev_Sf : 1;
  UInt32 is_c177_VSINFO_Re003tev_Sf : 1;
} D_Work_VSINFO_Re003tev_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiBrkAuto;                        /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiBrkDyn;                         /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiBrkPedPrss;                     /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniVehClc;                      /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiLgtCtlDynChg;                   /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiObsAntiSat;                     /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiObsAntiSatRaw;                  /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiPrkBrk;                         /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiSIP;                            /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiTranDynAntiSat;                 /*BIN0*/
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAuthObsAntiSat;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bBrkAuto;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bBrkDyn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bBrkPedPrss;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bObsAntiSat;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bObsAntiSatRaw;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bObsAntiSatRaw2;
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bObsAntiSatRaw2Prev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bPrkBrk;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bSIPFil;
/* Static Visible area end */
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 16BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) vsinfo_vsctl_mveh_cpy;                                    /*BIN0*/
STATIC VAR(UInt16, AUTOMATIC) vsinfo_vsctl_rdwhl_cpy;                                   /*BIN7*/
#define VSINFO_STOP_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"


/* 8BIT-bits variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_blgtctldyn_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsinfo_vsctl_stvehinfo_cpy;
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(BlockIO_VSINFO_Re003tev_Sf, AUTOMATIC) vsinfo_re003tev_sf_b;
STATIC VAR(D_Work_VSINFO_Re003tev_Sf, AUTOMATIC) vsinfo_re003tev_sf_dwork;
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehErrLgtCtlDyn_HysHi_C = (CONST(UInt16, AUTOMATIC))(256U); /*BIN10*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehErrLgtCtlDyn_HysLo_C = (CONST(UInt16, AUTOMATIC))(128U); /*BIN10*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehAntiSatAresHysHi_C = (CONST(UInt16, AUTOMATIC))(4480U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehAntiSatAresHysLo_C = (CONST(UInt16, AUTOMATIC))(3840U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfm_LgtCtlDyn_C = (CONST(UInt16, AUTOMATIC))(1U);       /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiDecr_ObsAntiSat_C = (CONST(UInt16, AUTOMATIC))(1U);     /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiDiCfm_LgtCtlDyn_C = (CONST(UInt16, AUTOMATIC))(10U);    /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIncr_ObsAntiSat_C = (CONST(UInt16, AUTOMATIC))(1U);     /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_VehInfo_C = (CONST(UInt16, AUTOMATIC))(9U);         /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiObsAntiSatThldMax_C = (CONST(UInt16, AUTOMATIC))(74U);  /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_AntiSatAres1_C = (CONST(UInt16, AUTOMATIC))(74U);   /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_AntiSatAres2_C = (CONST(UInt16, AUTOMATIC))(74U);   /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_BrkAuto_C = (CONST(UInt16, AUTOMATIC))(74U);        /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_BrkDyn_C = (CONST(UInt16, AUTOMATIC))(74U);         /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_BrkPedPrss_C = (CONST(UInt16, AUTOMATIC))(74U);     /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_LgtCtlDyn_C = (CONST(UInt16, AUTOMATIC))(24U);      /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_PrkBrk_C = (CONST(UInt16, AUTOMATIC))(74U);         /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_SIP_C = (CONST(UInt16, AUTOMATIC))(49U);            /*BIN0*/
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/* 8BIT-bits variable definition */
#define VSINFO_START_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvSIPFilBVx_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeac_bInh_aPT_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeac_rAccPT_C = DDS_FALSE;
/* \<AUT_POST> : Task Memory Ordering */
#define VSINFO_STOP_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"

/* AUT_POST_TAG DECLARATIONS */
/* \AUT_POST_TAG DECLARATIONS */
/* AUT_POST_TAG FUNCTIONS */

/* Shared Utility Functions */
#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/* <AUT_POST> : Task static function */
/********************************************************************/
/*  Task Local Function Prototypes                                  */
/********************************************************************/
static SInt32 div_s32(SInt32 sf_numerator, SInt32 sf_denominator);
/* \<AUT_POST> : Task static function */

/********************************************************************/
/*  Local Task Function Definition                                  */
/********************************************************************/
static SInt32 div_s32(SInt32 sf_numerator, SInt32 sf_denominator)
{
  UInt32 sf_absnumerator;
  UInt32 sf_absdenominator;
  UInt32 sf_quotientneedsnegation;
  UInt32 sf_tempabsquotient;
  if (sf_denominator == 0)
  {
    return (SInt32)(sf_numerator >= 0 ? DDS_SINT32_MAX : DDS_SINT32_MIN);

  }
  else
  {
    sf_absnumerator = (UInt32)(sf_numerator >= 0 ? sf_numerator :
      -sf_numerator);
    sf_absdenominator = (UInt32)(sf_denominator >= 0 ? sf_denominator :
      -sf_denominator);
    sf_quotientneedsnegation = (UInt32)((sf_numerator < 0) != (sf_denominator <
      0));
    sf_tempabsquotient = (UInt32)(sf_absnumerator / sf_absdenominator);
    return (SInt32)(sf_quotientneedsnegation ? (SInt32)(-((SInt32)
      sf_tempabsquotient)) : (SInt32)sf_tempabsquotient);
  }
}

/* Model step function */

/********************************************************************/
/*  Main Task Function Definition                                   */
/********************************************************************/


FUNC(void, AUTOMATIC) VSINFO_Re003tev_Sf(SInt16 VSCtl_tqWhlPTLim_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in,                    /*BIN1*/
                               UInt8 Ext_stGBxCf_swc_in,
                               SInt16 VSCtl_tqWhlBrkReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stPTInfo_swc_in,
                               SInt16 VSCtl_tqWhlPTReal_swc_in,                            /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMin_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlPTAplReq_swc_in,                          /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMax_swc_in,                             /*BIN1*/
                               UInt8 Ext_bBrkDynCf_swc_in,
                               SInt16 VSCtl_tqWhlPTPotMaxCtla_no1_swc_in,                  /*BIN1*/
                               UInt8 Brk_bBrkDyn_swc_in,
                               SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in,                   /*BIN1*/
                               UInt16 VSCtl_spdVehRef_swc_in,                              /*BIN7*/
                               UInt8 Ext_bBrkPedPrss_swc_in,
                               UInt8 VSCtl_stGrdLkInfo_swc_in,
                               UInt8 Ext_bBrkAutoCf_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               UInt8 FRM_bDeacVSCtlVehClc_swc_in,
                               SInt16 VSCtl_tqWhlPTPotMin_swc_in,                          /*BIN1*/
                               SInt16 VSCtl_aVehReq_swc_in,                         /*BIN10*/
                               SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in,                       /*BIN1*/
                               SInt16 VSCtl_tqWhlPTPotMax_swc_in,                          /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in,                      /*BIN1*/
                               UInt8 Brk_bBrkAuto_swc_in,
                               SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in,                      /*BIN1*/
                               SInt16 VSCtl_tqWhlBrkEstim_swc_in,                          /*BIN1*/
                               UInt8 Ext_bPrkBrk_swc_in,
                               SInt16 VSCtl_tqWhlPTIni_swc_in,                             /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVehInfo_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bLgtCtlDyn_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_mVeh_swc_out,                                   /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rdWhl_swc_out)                                  /*BIN7*/
{

  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F141_Determiner_Etat_Informations_Vehicule*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.90.1 */

  if (vsinfo_re003tev_sf_dwork.is_active_c177_VSINFO_Re003tev_Sf == 0)
  {
    vsinfo_re003tev_sf_dwork.is_active_c177_VSINFO_Re003tev_Sf = 1U;
    vsinfo_re003tev_sf_dwork.is_c177_VSINFO_Re003tev_Sf = (UInt8)
      VSINFO_Re003tev_Sf_IN_ETAT_INFORMATIONS_VEHICULE;
    vsinfo_re003tev_sf_dwork.is_ETAT_INFORMATIONS_VEHICULE = (UInt8)
      VSINFO_Re003tev_Sf_IN_ARRET;
    vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_ARRET;
    VSCtl_bAcvFilVehInfo = VSINFO_Re003tev_Sf_FAUX;
    VSCtl_tiIniVehClc = VSCtl_tiIni_VehInfo_C;

  }
  else
  {
    switch (vsinfo_re003tev_sf_dwork.is_ETAT_INFORMATIONS_VEHICULE) {
     case VSINFO_Re003tev_Sf_IN_ARRET:
      if ((VSCtl_stPTInfo_swc_in != VSCTL_STPTINFO_ARRET)
      && (VSCtl_stGrdLkInfo_swc_in !=
           VSCTL_STGRDLKINFO_ARRET))
      {
        vsinfo_re003tev_sf_dwork.is_ETAT_INFORMATIONS_VEHICULE = (UInt8)
          VSINFO_Re003tev_Sf_IN_MARCHE;
        vsinfo_re003tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Re003tev_Sf_IN_VERIF;
        vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_VERIF_12;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_MARCHE:
      if ((VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_ARRET)
      || (VSCtl_stGrdLkInfo_swc_in ==
           VSCTL_STGRDLKINFO_ARRET))
      {
        vsinfo_re003tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_re003tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_re003tev_sf_dwork.is_ETAT_INFORMATIONS_VEHICULE = (UInt8)
          VSINFO_Re003tev_Sf_IN_ARRET;
        vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_ARRET;
        VSCtl_bAcvFilVehInfo = VSINFO_Re003tev_Sf_FAUX;
        VSCtl_tiIniVehClc = VSCtl_tiIni_VehInfo_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_MARCHE)
      {
         case VSINFO_Re003tev_Sf_IN_DEFAUT:
          if (((FRM_bDeacVSCtlVehClc_swc_in == VSINFO_Re003tev_Sf_FAUX) &&
               (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_NOMINAL_7)) &&
              (VSCtl_stGrdLkInfo_swc_in == VSCTL_STGRDLKINFO_NOMINAL_35))
          {
            vsinfo_re003tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Re003tev_Sf_IN_PAS_DEFAUT;
            vsinfo_re003tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Re003tev_Sf_IN_INIT;
            vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_INIT_12;
            VSCtl_tiIniVehClc = VSCtl_tiIni_VehInfo_C;
          }
          break;

         case VSINFO_Re003tev_Sf_IN_PAS_DEFAUT:
          if (((FRM_bDeacVSCtlVehClc_swc_in == VSINFO_Re003tev_Sf_VRAI) ||
               (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_DEFAUT_7)) ||
              (VSCtl_stGrdLkInfo_swc_in == VSCTL_STGRDLKINFO_DEFAUT_35))
          {
            vsinfo_re003tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD;
            vsinfo_re003tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Re003tev_Sf_IN_DEFAUT;
            vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_DEFAUT_12;
            VSCtl_bAcvFilVehInfo = VSINFO_Re003tev_Sf_FAUX;

          }
          else
          {
            switch (vsinfo_re003tev_sf_dwork.is_PAS_DEFAUT)
          {
             case VSINFO_Re003tev_Sf_IN_INIT:
              if (VSCtl_tiIniVehClc == 0)
              {
                vsinfo_re003tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Re003tev_Sf_IN_NOMINAL;
                vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_NOMINAL_12;
                VSCtl_bAcvFilVehInfo = VSINFO_Re003tev_Sf_VRAI;

              }
              else
              {
                VSCtl_tiIniVehClc = (UInt16)DDS_M_MAX(VSCtl_tiIniVehClc - 1, 0);
                VSCtl_bAcvFilVehInfo = VSINFO_Re003tev_Sf_VRAI;
              }
              break;
            }
          }
          break;

         case VSINFO_Re003tev_Sf_IN_VERIF:
          if (((FRM_bDeacVSCtlVehClc_swc_in == VSINFO_Re003tev_Sf_VRAI) ||
               (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_DEFAUT_7)) ||
              (VSCtl_stGrdLkInfo_swc_in == VSCTL_STGRDLKINFO_DEFAUT_35))
          {
            vsinfo_re003tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Re003tev_Sf_IN_DEFAUT;
            vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_DEFAUT_12;
            VSCtl_bAcvFilVehInfo = VSINFO_Re003tev_Sf_FAUX;

          }
          else if (((FRM_bDeacVSCtlVehClc_swc_in == VSINFO_Re003tev_Sf_FAUX)
          &&
                      (VSCtl_stPTInfo_swc_in == VSCTL_STPTINFO_NOMINAL_7))
                      &&
                     (VSCtl_stGrdLkInfo_swc_in == VSCTL_STGRDLKINFO_NOMINAL_35))
          {
            vsinfo_re003tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Re003tev_Sf_IN_PAS_DEFAUT;
            vsinfo_re003tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Re003tev_Sf_IN_INIT;
            vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_INIT_12;
            VSCtl_tiIniVehClc = VSCtl_tiIni_VehInfo_C;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_ETAT_INFORMATIONS_VEHICULE = (UInt8)
        VSINFO_Re003tev_Sf_IN_ARRET;
      vsinfo_vsctl_stvehinfo_cpy = VSCTL_STVEHINFO_ARRET;
      VSCtl_bAcvFilVehInfo = VSINFO_Re003tev_Sf_FAUX;
      VSCtl_tiIniVehClc = VSCtl_tiIni_VehInfo_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F141_Determiner_Etat_Informations_Vehicule*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F14611_Determiner_Mode_Dynamique_Longitudinale*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.171.0 */

  if (vsinfo_re003tev_sf_dwork.is_active_c178_VSINFO_Re003tev_Sf == 0)
  {
    vsinfo_re003tev_sf_dwork.is_active_c178_VSINFO_Re003tev_Sf = 1U;
    vsinfo_re003tev_sf_dwork.is_c178_VSINFO_Re003tev_Sf = (UInt8)
      VSINFO_Re003tev_Sf_IN_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE;
    vsinfo_re003tev_sf_dwork.is_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE =
      (UInt8)VSINFO_Re003tev_Sf_IN_INIT_o;
    vsinfo_vsctl_blgtctldyn_cpy = VSCTL_BLGTCTLDYN_TRANSITOIRE;
    VSCtl_tiLgtCtlDynChg = VSCtl_tiTol_LgtCtlDyn_C;

  }
  else
  {
    switch (vsinfo_re003tev_sf_dwork.is_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE)
    {
     case VSINFO_Re003tev_Sf_IN_INIT_o:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_INIT_12)
      || (vsinfo_vsctl_stvehinfo_cpy ==
           VSCTL_STVEHINFO_NOMINAL_12))
      {
        vsinfo_re003tev_sf_dwork.is_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE =
          (UInt8)VSINFO_Re003tev_Sf_IN_NON_INIT;
        vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
          VSINFO_Re003tev_Sf_IN_RAPIDE;
        vsinfo_vsctl_blgtctldyn_cpy = VSCTL_BLGTCTLDYN_TRANSITOIRE;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INIT:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_INIT_12)
      && (vsinfo_vsctl_stvehinfo_cpy !=
           VSCTL_STVEHINFO_NOMINAL_12))
      {
        vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_g;
        vsinfo_re003tev_sf_dwork.is_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE =
          (UInt8)VSINFO_Re003tev_Sf_IN_INIT_o;
        vsinfo_vsctl_blgtctldyn_cpy = VSCTL_BLGTCTLDYN_TRANSITOIRE;
        VSCtl_tiLgtCtlDynChg = VSCtl_tiTol_LgtCtlDyn_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INIT)
      {
         case VSINFO_Re003tev_Sf_IN_CONF:
          if ((((SInt16)DDS_M_ABS((SInt32)VSCtl_aVehReq_swc_in)) >
               VSCtl_aVehErrLgtCtlDyn_HysHi_C)
               && (VSCtl_tiLgtCtlDynChg > 0))
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
              VSINFO_Re003tev_Sf_IN_DECONF;

          }
          else if (VSCtl_tiLgtCtlDynChg <= 0)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
              VSINFO_Re003tev_Sf_IN_LENTE;
            vsinfo_vsctl_blgtctldyn_cpy = VSCTL_BLGTCTLDYN_STABILISE;

          }
          else
          {
            VSCtl_tiLgtCtlDynChg = (UInt16)DDS_M_MAX(VSCtl_tiLgtCtlDynChg -
              VSCtl_tiCfm_LgtCtlDyn_C, 0);
          }
          break;

         case VSINFO_Re003tev_Sf_IN_DECONF:
          if (((SInt16)DDS_M_ABS((SInt32)VSCtl_aVehReq_swc_in)) <=
              VSCtl_aVehErrLgtCtlDyn_HysLo_C)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
              VSINFO_Re003tev_Sf_IN_CONF;

          }
          else if ((((SInt16)DDS_M_ABS((SInt32)VSCtl_aVehReq_swc_in)) >
                      VSCtl_aVehErrLgtCtlDyn_HysHi_C)
                      && (VSCtl_tiLgtCtlDynChg >=
                      VSCtl_tiTol_LgtCtlDyn_C))
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
              VSINFO_Re003tev_Sf_IN_RAPIDE;
            vsinfo_vsctl_blgtctldyn_cpy = VSCTL_BLGTCTLDYN_TRANSITOIRE;

          }
          else
          {
            VSCtl_tiLgtCtlDynChg = (UInt16)((VSCtl_tiLgtCtlDynChg +
              VSCtl_tiDiCfm_LgtCtlDyn_C) < VSCtl_tiTol_LgtCtlDyn_C ?
              VSCtl_tiLgtCtlDynChg + VSCtl_tiDiCfm_LgtCtlDyn_C : (SInt32)
              VSCtl_tiTol_LgtCtlDyn_C);
          }
          break;

         case VSINFO_Re003tev_Sf_IN_LENTE:
          if (((SInt16)DDS_M_ABS((SInt32)VSCtl_aVehReq_swc_in)) >
              VSCtl_aVehErrLgtCtlDyn_HysHi_C)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
              VSINFO_Re003tev_Sf_IN_DECONF;
          }
          break;

         case VSINFO_Re003tev_Sf_IN_RAPIDE:
          if (((SInt16)DDS_M_ABS((SInt32)VSCtl_aVehReq_swc_in)) <=
              VSCtl_aVehErrLgtCtlDyn_HysLo_C)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT = (UInt8)
              VSINFO_Re003tev_Sf_IN_CONF;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE =
        (UInt8)VSINFO_Re003tev_Sf_IN_INIT_o;
      vsinfo_vsctl_blgtctldyn_cpy = VSCTL_BLGTCTLDYN_TRANSITOIRE;
      VSCtl_tiLgtCtlDynChg = VSCtl_tiTol_LgtCtlDyn_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F14611_Determiner_Mode_Dynamique_Longitudinale*/

  VSINFO_F142_Determiner_Parametres_Vehicule(&vsinfo_vsctl_mveh_cpy, /* BIN0 */
                                                &vsinfo_vsctl_rdwhl_cpy /* BIN7 */);


  VSINFO_F143_Filtrer_Vitesse_Vehicule(VSCtl_spdVehRef_swc_in, /* BIN7 */
                                        vsinfo_vsctl_stvehinfo_cpy);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F14612_Determiner_Mode_Filtrage_Acceleration*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.172.0 */

  if (vsinfo_re003tev_sf_dwork.is_active_c179_VSINFO_Re003tev_Sf == 0)
  {
    vsinfo_re003tev_sf_dwork.is_active_c179_VSINFO_Re003tev_Sf = 1U;
    vsinfo_re003tev_sf_dwork.is_c179_VSINFO_Re003tev_Sf = (UInt8)
      VSINFO_Re003tev_Sf_IN_MODES_CONTROLE_ACCELERATION;
    vsinfo_re003tev_sf_dwork.is_active_TAUX_LISSAGE_ACCELERATION = 1U;
    vsinfo_re003tev_sf_dwork.is_TAUX_LISSAGE_ACCELERATION = (UInt8)
      VSINFO_Re003tev_Sf_IN_ARRET_o;
    vsinfo_re003tev_sf_b.VSCtl_rAccPT_h = (UInt16)VSINFO_100_BIN7;
    vsinfo_re003tev_sf_dwork.is_active_INHIBITION_ACCELERATION_GMP = 1U;
    vsinfo_re003tev_sf_dwork.is_INHIBITION_ACCELERATION_GMP = (UInt8)
      VSINFO_Re003tev_Sf_IN_FAUX;
    VSCtl_bInh_aPT = VSINFO_Re003tev_Sf_FAUX_p;

  }
  else
  {
    switch (vsinfo_re003tev_sf_dwork.is_TAUX_LISSAGE_ACCELERATION)
          {
     case VSINFO_Re003tev_Sf_IN_ARRET_o:
      if ((VSCtl_bDeac_rAccPT_C == VSINFO_Re003tev_Sf_FAUX_p) &&
          (vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12))
      {
        vsinfo_re003tev_sf_dwork.is_TAUX_LISSAGE_ACCELERATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_CONF_e;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_CONF_e:
      if ((VSCtl_bDeac_rAccPT_C == VSINFO_Re003tev_Sf_VRAI_e) ||
          (vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12))
      {
        vsinfo_re003tev_sf_dwork.is_TAUX_LISSAGE_ACCELERATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_ARRET_o;
        vsinfo_re003tev_sf_b.VSCtl_rAccPT_h = (UInt16)VSINFO_100_BIN7;

      }
      else
      {
        vsinfo_re003tev_sf_b.VSCtl_rAccPT_h = (UInt16)DDS_M_MIN(DDS_M_MAX(div_s32
          (VSINFO_100_BIN7 * VSCtl_tiLgtCtlDynChg, (SInt32)
           VSCtl_tiTol_LgtCtlDyn_C), 0), VSINFO_100_BIN7);
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_TAUX_LISSAGE_ACCELERATION = (UInt8)
        VSINFO_Re003tev_Sf_IN_ARRET_o;
      vsinfo_re003tev_sf_b.VSCtl_rAccPT_h = (UInt16)VSINFO_100_BIN7;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_INHIBITION_ACCELERATION_GMP)
      {
     case VSINFO_Re003tev_Sf_IN_FAUX:
      if ((((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12)
      && ((Ext_stGBxCf_swc_in ==
              EXT_STGBXCF_BVMP)
              || (Ext_stGBxCf_swc_in == EXT_STGBXCF_BVA)))
              &&
           (VSCtl_bAvlTqWhlPT_no3_swc_in == VSINFO_Re003tev_Sf_FAUX_p)) &&
          (VSCtl_bDeac_bInh_aPT_C == VSINFO_Re003tev_Sf_FAUX_p))
      {
        vsinfo_re003tev_sf_dwork.is_INHIBITION_ACCELERATION_GMP = (UInt8)
          VSINFO_Re003tev_Sf_IN_VRAI;
        VSCtl_bInh_aPT = VSINFO_Re003tev_Sf_VRAI_e;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_VRAI:
      if ((((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12) ||
            (VSCtl_bDeac_bInh_aPT_C == VSINFO_Re003tev_Sf_VRAI_e)) ||
           (Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)) || (((Ext_stGBxCf_swc_in ==
             EXT_STGBXCF_BVMP)
             || (Ext_stGBxCf_swc_in == EXT_STGBXCF_BVA))
             &&
           (VSCtl_bAvlTqWhlPT_no3_swc_in == VSINFO_Re003tev_Sf_VRAI_e)))
      {
        vsinfo_re003tev_sf_dwork.is_INHIBITION_ACCELERATION_GMP = (UInt8)
          VSINFO_Re003tev_Sf_IN_FAUX;
        VSCtl_bInh_aPT = VSINFO_Re003tev_Sf_FAUX_p;
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_INHIBITION_ACCELERATION_GMP = (UInt8)
        VSINFO_Re003tev_Sf_IN_FAUX;
      VSCtl_bInh_aPT = VSINFO_Re003tev_Sf_FAUX_p;
      break;
    }
  }

  VSCtl_rAccPT = DDS_M_MIN(vsinfo_re003tev_sf_b.VSCtl_rAccPT_h,VSCTL_RACCPT_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F14612_Determiner_Mode_Filtrage_Acceleration*/

  VSINFO_F144_Determiner_Accelerations_Gmp(vsinfo_vsctl_mveh_cpy, /* BIN0 */
                                            vsinfo_vsctl_rdwhl_cpy, /* BIN7 */
                                            vsinfo_vsctl_stvehinfo_cpy,
                                            VSCtl_tqWhlPTAplReq_swc_in, /* BIN1 */
                                            VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTIni_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTLim_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTMax_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTMin_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTPotMax_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTPotMaxCtla_no1_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTPotMin_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1*/
                                            VSCtl_tqWhlPTReal_swc_in /* BIN1*/);


  VSINFO_F1462_Determiner_Acceleration_Gmp_Filtree(vsinfo_vsctl_stvehinfo_cpy);


  VSINFO_F145_Determiner_Acceleration_Frein(vsinfo_vsctl_mveh_cpy, /* BIN0 */
                                            vsinfo_vsctl_rdwhl_cpy, /* BIN7 */
                                            vsinfo_vsctl_stvehinfo_cpy,
                                            VSCtl_tqWhlBrkEstim_swc_in, /* BIN1 */
                                            VSCtl_tqWhlBrkReq_swc_in /* BIN1 */);


  VSINFO_F1463_Determiner_Acceleration_Frein_Filtree(vsinfo_vsctl_stvehinfo_cpy);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F146131_Determiner_Conditions_Antisaturation*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.114.2 */

  if (vsinfo_re003tev_sf_dwork.is_active_c180_VSINFO_Re003tev_Sf == 0)
  {
    vsinfo_re003tev_sf_dwork.is_active_c180_VSINFO_Re003tev_Sf = 1U;
    vsinfo_re003tev_sf_dwork.is_c180_VSINFO_Re003tev_Sf = (UInt8)
      VSINFO_Re003tev_Sf_IN_CONDITIONS_ANTISATURATION;
    vsinfo_re003tev_sf_dwork.is_active_APPUI_PEDALE_FREIN = 1U;
    vsinfo_re003tev_sf_dwork.is_APPUI_PEDALE_FREIN = (UInt8)
      VSINFO_Re003tev_Sf_IN_INACTIF;
    VSCtl_bBrkPedPrss = VSINFO_Re003tev_Sf_FAUX_p0;
    VSCtl_tiBrkPedPrss = VSCtl_tiTol_BrkPedPrss_C;
    vsinfo_re003tev_sf_dwork.is_active_SERRAGE_FREIN_MANUEL = 1U;
    vsinfo_re003tev_sf_dwork.is_SERRAGE_FREIN_MANUEL = (UInt8)
      VSINFO_Re003tev_Sf_IN_INACTIF;
    VSCtl_bPrkBrk = VSINFO_Re003tev_Sf_FAUX_p0;
    VSCtl_tiPrkBrk = VSCtl_tiTol_PrkBrk_C;
    vsinfo_re003tev_sf_dwork.is_active_FREINAGE_DYNAMIQUE = 1U;
    vsinfo_re003tev_sf_dwork.is_FREINAGE_DYNAMIQUE = (UInt8)
      VSINFO_Re003tev_Sf_IN_INACTIF;
    VSCtl_bBrkDyn = VSINFO_Re003tev_Sf_FAUX_p0;
    VSCtl_tiBrkDyn = VSCtl_tiTol_BrkDyn_C;
    vsinfo_re003tev_sf_dwork.is_active_FREINAGE_AUTOMATIQUE = 1U;
    vsinfo_re003tev_sf_dwork.is_FREINAGE_AUTOMATIQUE = (UInt8)
      VSINFO_Re003tev_Sf_IN_INACTIF;
    VSCtl_bBrkAuto = VSINFO_Re003tev_Sf_FAUX_p0;
    VSCtl_tiBrkAuto = VSCtl_tiTol_BrkAuto_C;
    vsinfo_re003tev_sf_dwork.is_active_CHANGEMENT_RAPPORT_PERMANENT = 1U;
    vsinfo_re003tev_sf_dwork.is_CHANGEMENT_RAPPORT_PERMANENT = (UInt8)
      VSINFO_Re003tev_Sf_IN_INACTIF;
    VSCtl_bSIPFil = VSINFO_Re003tev_Sf_FAUX_p0;
    VSCtl_tiSIP = VSCtl_tiTol_SIP_C;
    vsinfo_re003tev_sf_dwork.is_active_ANTISATURATION_BRUTE = 1U;
    vsinfo_re003tev_sf_dwork.is_ANTISATURATION_BRUTE = (UInt8)
      VSINFO_Re003tev_Sf_IN_INACTIF____0;
    VSCtl_bObsAntiSatRaw = VSINFO_Re003tev_Sf_FAUX_p0;

  }
  else
  {
    switch (vsinfo_re003tev_sf_dwork.is_APPUI_PEDALE_FREIN)
      {
     case VSINFO_Re003tev_Sf_IN_INACTIF:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12)
      && (Ext_bBrkPedPrss_swc_in ==
           VSINFO_Re003tev_Sf_VRAI_f))
      {
        vsinfo_re003tev_sf_dwork.is_APPUI_PEDALE_FREIN = (UInt8)
          VSINFO_Re003tev_Sf_IN_NON_INACTIF;
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_p = (UInt8)
          VSINFO_Re003tev_Sf_IN_ACTIF;
        VSCtl_bBrkPedPrss = VSINFO_Re003tev_Sf_VRAI_f;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INACTIF:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12)
      || (Ext_bBrkPedPrss_swc_in ==
           VSINFO_Re003tev_Sf_FAUX_p0))
      {
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_p = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_re003tev_sf_dwork.is_APPUI_PEDALE_FREIN = (UInt8)
          VSINFO_Re003tev_Sf_IN_INACTIF;
        VSCtl_bBrkPedPrss = VSINFO_Re003tev_Sf_FAUX_p0;
        VSCtl_tiBrkPedPrss = VSCtl_tiTol_BrkPedPrss_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INACTIF_p)
      {
         case VSINFO_Re003tev_Sf_IN_ACTIF:
          if (VSCtl_tiBrkPedPrss <= 0)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INACTIF_p = (UInt8)
              VSINFO_Re003tev_Sf_IN_PERMANENT;
            VSCtl_bBrkPedPrss = VSINFO_Re003tev_Sf_FAUX_p0;

          }
          else
          {
            VSCtl_tiBrkPedPrss = (UInt16)DDS_M_MAX(VSCtl_tiBrkPedPrss - 1, 0);
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_APPUI_PEDALE_FREIN = (UInt8)
        VSINFO_Re003tev_Sf_IN_INACTIF;
      VSCtl_bBrkPedPrss = VSINFO_Re003tev_Sf_FAUX_p0;
      VSCtl_tiBrkPedPrss = VSCtl_tiTol_BrkPedPrss_C;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_SERRAGE_FREIN_MANUEL)
      {
     case VSINFO_Re003tev_Sf_IN_INACTIF:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12)
      && (Ext_bPrkBrk_swc_in ==
           VSINFO_Re003tev_Sf_VRAI_f))
      {
        vsinfo_re003tev_sf_dwork.is_SERRAGE_FREIN_MANUEL = (UInt8)
          VSINFO_Re003tev_Sf_IN_NON_INACTIF;
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_l = (UInt8)
          VSINFO_Re003tev_Sf_IN_ACTIF;
        VSCtl_bPrkBrk = VSINFO_Re003tev_Sf_VRAI_f;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INACTIF:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12)
      || (Ext_bPrkBrk_swc_in ==
           VSINFO_Re003tev_Sf_FAUX_p0))
      {
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_l = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_re003tev_sf_dwork.is_SERRAGE_FREIN_MANUEL = (UInt8)
          VSINFO_Re003tev_Sf_IN_INACTIF;
        VSCtl_bPrkBrk = VSINFO_Re003tev_Sf_FAUX_p0;
        VSCtl_tiPrkBrk = VSCtl_tiTol_PrkBrk_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INACTIF_l)
      {
         case VSINFO_Re003tev_Sf_IN_ACTIF:
          if (VSCtl_tiPrkBrk <= 0)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INACTIF_l = (UInt8)
              VSINFO_Re003tev_Sf_IN_PERMANENT;
            VSCtl_bPrkBrk = VSINFO_Re003tev_Sf_FAUX_p0;

          }
          else
          {
            VSCtl_tiPrkBrk = (UInt16)DDS_M_MAX(VSCtl_tiPrkBrk - 1, 0);
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_SERRAGE_FREIN_MANUEL = (UInt8)
        VSINFO_Re003tev_Sf_IN_INACTIF;
      VSCtl_bPrkBrk = VSINFO_Re003tev_Sf_FAUX_p0;
      VSCtl_tiPrkBrk = VSCtl_tiTol_PrkBrk_C;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_FREINAGE_DYNAMIQUE)
      {
     case VSINFO_Re003tev_Sf_IN_INACTIF:
      if (((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12)
      && (Brk_bBrkDyn_swc_in ==
            VSINFO_Re003tev_Sf_VRAI_f)) && (Ext_bBrkDynCf_swc_in ==
           EXT_BBRKDYNCF_PRESENT))
      {
        vsinfo_re003tev_sf_dwork.is_FREINAGE_DYNAMIQUE = (UInt8)
          VSINFO_Re003tev_Sf_IN_NON_INACTIF;
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_g = (UInt8)
          VSINFO_Re003tev_Sf_IN_ACTIF;
        VSCtl_bBrkDyn = VSINFO_Re003tev_Sf_VRAI_f;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INACTIF:
      if (((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12)
      || (Brk_bBrkDyn_swc_in ==
            VSINFO_Re003tev_Sf_FAUX_p0)) || (Ext_bBrkDynCf_swc_in ==
           EXT_BBRKDYNCF_ABSENT))
      {
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_g = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_re003tev_sf_dwork.is_FREINAGE_DYNAMIQUE = (UInt8)
          VSINFO_Re003tev_Sf_IN_INACTIF;
        VSCtl_bBrkDyn = VSINFO_Re003tev_Sf_FAUX_p0;
        VSCtl_tiBrkDyn = VSCtl_tiTol_BrkDyn_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INACTIF_g)
      {
         case VSINFO_Re003tev_Sf_IN_ACTIF:
          if (VSCtl_tiBrkDyn <= 0)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INACTIF_g = (UInt8)
              VSINFO_Re003tev_Sf_IN_PERMANENT;
            VSCtl_bBrkDyn = VSINFO_Re003tev_Sf_FAUX_p0;

          }
          else
          {
            VSCtl_tiBrkDyn = (UInt16)DDS_M_MAX(VSCtl_tiBrkDyn - 1, 0);
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_FREINAGE_DYNAMIQUE = (UInt8)
        VSINFO_Re003tev_Sf_IN_INACTIF;
      VSCtl_bBrkDyn = VSINFO_Re003tev_Sf_FAUX_p0;
      VSCtl_tiBrkDyn = VSCtl_tiTol_BrkDyn_C;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_FREINAGE_AUTOMATIQUE)
      {
     case VSINFO_Re003tev_Sf_IN_INACTIF:
      if (((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12)
      && (Brk_bBrkAuto_swc_in ==
            VSINFO_Re003tev_Sf_VRAI_f)) && (Ext_bBrkAutoCf_swc_in ==
           EXT_BBRKAUTOCF_PRESENT))
      {
        vsinfo_re003tev_sf_dwork.is_FREINAGE_AUTOMATIQUE = (UInt8)
          VSINFO_Re003tev_Sf_IN_NON_INACTIF;
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_lw = (UInt8)
          VSINFO_Re003tev_Sf_IN_ACTIF;
        VSCtl_bBrkAuto = VSINFO_Re003tev_Sf_VRAI_f;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INACTIF:
      if (((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12)
      || (Brk_bBrkAuto_swc_in ==
            VSINFO_Re003tev_Sf_FAUX_p0)) || (Ext_bBrkAutoCf_swc_in ==
           EXT_BBRKAUTOCF_ABSENT))
      {
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_lw = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_re003tev_sf_dwork.is_FREINAGE_AUTOMATIQUE = (UInt8)
          VSINFO_Re003tev_Sf_IN_INACTIF;
        VSCtl_bBrkAuto = VSINFO_Re003tev_Sf_FAUX_p0;
        VSCtl_tiBrkAuto = VSCtl_tiTol_BrkAuto_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INACTIF_lw)
      {
         case VSINFO_Re003tev_Sf_IN_ACTIF:
          if (VSCtl_tiBrkAuto <= 0)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INACTIF_lw = (UInt8)
              VSINFO_Re003tev_Sf_IN_PERMANENT;
            VSCtl_bBrkAuto = VSINFO_Re003tev_Sf_FAUX_p0;

          }
          else
          {
            VSCtl_tiBrkAuto = (UInt16)DDS_M_MAX(VSCtl_tiBrkAuto - 1, 0);
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_FREINAGE_AUTOMATIQUE = (UInt8)
        VSINFO_Re003tev_Sf_IN_INACTIF;
      VSCtl_bBrkAuto = VSINFO_Re003tev_Sf_FAUX_p0;
      VSCtl_tiBrkAuto = VSCtl_tiTol_BrkAuto_C;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_CHANGEMENT_RAPPORT_PERMANENT)
      {
     case VSINFO_Re003tev_Sf_IN_INACTIF:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12) &&
          (VSCtl_bAvlTqWhlPT_no3_swc_in == VSINFO_Re003tev_Sf_FAUX_p0))
      {
        vsinfo_re003tev_sf_dwork.is_CHANGEMENT_RAPPORT_PERMANENT = (UInt8)
          VSINFO_Re003tev_Sf_IN_NON_INACTIF;
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_px = (UInt8)
          VSINFO_Re003tev_Sf_IN_ACTIF;
        VSCtl_bSIPFil = VSINFO_Re003tev_Sf_VRAI_f;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INACTIF:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12) ||
          (VSCtl_bAvlTqWhlPT_no3_swc_in == VSINFO_Re003tev_Sf_VRAI_f))
      {
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF_px = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_p;
        vsinfo_re003tev_sf_dwork.is_CHANGEMENT_RAPPORT_PERMANENT = (UInt8)
          VSINFO_Re003tev_Sf_IN_INACTIF;
        VSCtl_bSIPFil = VSINFO_Re003tev_Sf_FAUX_p0;
        VSCtl_tiSIP = VSCtl_tiTol_SIP_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INACTIF_px)
      {
         case VSINFO_Re003tev_Sf_IN_ACTIF:
          if ((VSCtl_tiSIP <= 0)
          && ((Ext_stGBxCf_swc_in == EXT_STGBXCF_BVM)
          ||
               (VSCtl_bAcvSIPFilBVx_C == VSINFO_Re003tev_Sf_VRAI_f)))
          {
            vsinfo_re003tev_sf_dwork.is_NON_INACTIF_px = (UInt8)
              VSINFO_Re003tev_Sf_IN_PERMANENT;
            VSCtl_bSIPFil = VSINFO_Re003tev_Sf_FAUX_p0;

          }
          else
          {
            VSCtl_tiSIP = (UInt16)DDS_M_MAX(VSCtl_tiSIP - 1, 0);
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_CHANGEMENT_RAPPORT_PERMANENT = (UInt8)
        VSINFO_Re003tev_Sf_IN_INACTIF;
      VSCtl_bSIPFil = VSINFO_Re003tev_Sf_FAUX_p0;
      VSCtl_tiSIP = VSCtl_tiTol_SIP_C;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_ANTISATURATION_BRUTE)
      {
     case VSINFO_Re003tev_Sf_IN_ACTIF:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12)
      || (((((VSCtl_bSIPFil ==
               VSINFO_Re003tev_Sf_FAUX_p0) && (VSCtl_bBrkPedPrss ==
               VSINFO_Re003tev_Sf_FAUX_p0)) && (VSCtl_bBrkDyn ==
              VSINFO_Re003tev_Sf_FAUX_p0)) && (VSCtl_bPrkBrk ==
             VSINFO_Re003tev_Sf_FAUX_p0)) && (VSCtl_bBrkAuto ==
            VSINFO_Re003tev_Sf_FAUX_p0)))
      {
        vsinfo_re003tev_sf_dwork.is_ANTISATURATION_BRUTE = (UInt8)
          VSINFO_Re003tev_Sf_IN_INACTIF____0;
        VSCtl_bObsAntiSatRaw = VSINFO_Re003tev_Sf_FAUX_p0;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_INACTIF____0:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12)
      && (((((VSCtl_bSIPFil ==
               VSINFO_Re003tev_Sf_VRAI_f) || (VSCtl_bBrkPedPrss ==
               VSINFO_Re003tev_Sf_VRAI_f)) || (VSCtl_bBrkDyn ==
              VSINFO_Re003tev_Sf_VRAI_f)) || (VSCtl_bPrkBrk ==
             VSINFO_Re003tev_Sf_VRAI_f)) || (VSCtl_bBrkAuto ==
            VSINFO_Re003tev_Sf_VRAI_f)))
      {
        vsinfo_re003tev_sf_dwork.is_ANTISATURATION_BRUTE = (UInt8)
          VSINFO_Re003tev_Sf_IN_ACTIF;
        VSCtl_bObsAntiSatRaw = VSINFO_Re003tev_Sf_VRAI_f;
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_ANTISATURATION_BRUTE = (UInt8)
        VSINFO_Re003tev_Sf_IN_INACTIF____0;
      VSCtl_bObsAntiSatRaw = VSINFO_Re003tev_Sf_FAUX_p0;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F146131_Determiner_Conditions_Antisaturation*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F146132_Filtrer_Conditions_Antisaturation*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.115.2 */

  if (vsinfo_re003tev_sf_dwork.is_active_c181_VSINFO_Re003tev_Sf == 0)
  {
    vsinfo_re003tev_sf_dwork.is_active_c181_VSINFO_Re003tev_Sf = 1U;
    vsinfo_re003tev_sf_dwork.is_c181_VSINFO_Re003tev_Sf = (UInt8)
      VSINFO_Re003tev_Sf_IN_FILTRER_CONDITIONS_ANTISATURATIONS;
    vsinfo_re003tev_sf_dwork.is_active_FILTRAGE_ANTISATURATION_PERMANENTE = 1U;
    vsinfo_re003tev_sf_dwork.is_FILTRAGE_ANTISATURATION_PERMANENTE = (UInt8)
      VSINFO_Re003tev_Sf_IN_INACTIF_a;
    VSCtl_bObsAntiSatRaw2 = VSINFO_Re003tev_Sf_FAUX_e;
    VSCtl_tiObsAntiSatRaw = VSCtl_tiTol_AntiSatAres2_C;
    vsinfo_re003tev_sf_dwork.is_active_AUTORISATION_ANTISATURATION = 1U;
    vsinfo_re003tev_sf_dwork.is_AUTORISATION_ANTISATURATION = (UInt8)
      VSINFO_Re003tev_Sf_IN_INIT_j;
    VSCtl_bAuthObsAntiSat = VSINFO_Re003tev_Sf_VRAI_n;
    VSCtl_tiObsAntiSat = 0U;
    vsinfo_re003tev_sf_dwork.is_active_ANTISATURATION = 1U;
    vsinfo_re003tev_sf_dwork.is_ANTISATURATION = (UInt8)
      VSINFO_Re003tev_Sf_IN_NORMAL;
    VSCtl_bObsAntiSat = VSINFO_Re003tev_Sf_FAUX_e;

  }
  else
  {
    switch (vsinfo_re003tev_sf_dwork.is_FILTRAGE_ANTISATURATION_PERMANENTE)
      {
     case VSINFO_Re003tev_Sf_IN_INACTIF_a:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12) &&
          (VSCtl_bObsAntiSatRaw == VSINFO_Re003tev_Sf_VRAI_n))
      {
        vsinfo_re003tev_sf_dwork.is_FILTRAGE_ANTISATURATION_PERMANENTE =
          (UInt8)VSINFO_Re003tev_Sf_IN_NON_INACTIF_a;
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF = (UInt8)
          VSINFO_Re003tev_Sf_IN_ACTIF_f;
        VSCtl_bObsAntiSatRaw2 = VSINFO_Re003tev_Sf_VRAI_n;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INACTIF_a:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12) ||
          (VSCtl_bObsAntiSatRaw == VSINFO_Re003tev_Sf_FAUX_e))
      {
        vsinfo_re003tev_sf_dwork.is_NON_INACTIF = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_k;
        vsinfo_re003tev_sf_dwork.is_FILTRAGE_ANTISATURATION_PERMANENTE =
          (UInt8)VSINFO_Re003tev_Sf_IN_INACTIF_a;
        VSCtl_bObsAntiSatRaw2 = VSINFO_Re003tev_Sf_FAUX_e;
        VSCtl_tiObsAntiSatRaw = VSCtl_tiTol_AntiSatAres2_C;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INACTIF)
      {
         case VSINFO_Re003tev_Sf_IN_ACTIF_f:
          if (VSCtl_tiObsAntiSatRaw <= 0)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INACTIF = (UInt8)
              VSINFO_Re003tev_Sf_IN_PERMANENT_c;
            VSCtl_bObsAntiSatRaw2 = VSINFO_Re003tev_Sf_FAUX_e;

          }
          else
          {
            VSCtl_tiObsAntiSatRaw = (UInt16)DDS_M_MAX(VSCtl_tiObsAntiSatRaw - 1,
              0);
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_FILTRAGE_ANTISATURATION_PERMANENTE = (UInt8)
        VSINFO_Re003tev_Sf_IN_INACTIF_a;
      VSCtl_bObsAntiSatRaw2 = VSINFO_Re003tev_Sf_FAUX_e;
      VSCtl_tiObsAntiSatRaw = VSCtl_tiTol_AntiSatAres2_C;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_AUTORISATION_ANTISATURATION)
      {
     case VSINFO_Re003tev_Sf_IN_INIT_j:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12)
      && (VSCtl_spdVehFil >
           VSCtl_spdVehAntiSatAresHysHi_C))
      {
        vsinfo_re003tev_sf_dwork.is_AUTORISATION_ANTISATURATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_NON_INIT_d;
        vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
          VSINFO_Re003tev_Sf_IN_DECONF_g;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INIT_d:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12)
      || (VSCtl_spdVehFil <=
           VSCtl_spdVehAntiSatAresHysLo_C))
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INIT_g)
      {
         case VSINFO_Re003tev_Sf_IN_CONF_m:
          vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
            VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_k;
          break;

         case VSINFO_Re003tev_Sf_IN_DECONF_g:
          vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
            VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_k;
          break;

         case VSINFO_Re003tev_Sf_IN_REHAB:
          VSCtl_bAuthObsAntiSat = VSINFO_Re003tev_Sf_VRAI_n;
          vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
            VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_k;
          break;

         default:
          vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
            VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_k;
          break;
        }

        vsinfo_re003tev_sf_dwork.is_AUTORISATION_ANTISATURATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_INIT_j;
        VSCtl_bAuthObsAntiSat = VSINFO_Re003tev_Sf_VRAI_n;
        VSCtl_tiObsAntiSat = 0U;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INIT_g)
      {
         case VSINFO_Re003tev_Sf_IN_CONF_m:
          if (VSCtl_bObsAntiSatRaw2 == VSINFO_Re003tev_Sf_FAUX_e)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
              VSINFO_Re003tev_Sf_IN_DECONF_g;

          }
          else if ((VSCtl_bObsAntiSatRaw2 == VSINFO_Re003tev_Sf_VRAI_n)
          &&
                     (VSCtl_tiObsAntiSat == 0))
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
              VSINFO_Re003tev_Sf_IN_REHAB;
            VSCtl_bAuthObsAntiSat = VSINFO_Re003tev_Sf_FAUX_e;

          }
          else
          {
            VSCtl_tiObsAntiSat = (UInt16)DDS_M_MAX(VSCtl_tiObsAntiSat -
              VSCtl_tiDecr_ObsAntiSat_C, 0);
          }
          break;

         case VSINFO_Re003tev_Sf_IN_DECONF_g:
          if (VSCtl_bObsAntiSatRaw2 == VSINFO_Re003tev_Sf_VRAI_n)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
              VSINFO_Re003tev_Sf_IN_CONF_m;

          }
          else
          {
            VSCtl_tiObsAntiSat = (UInt16)((VSCtl_tiObsAntiSat +
              VSCtl_tiIncr_ObsAntiSat_C) < VSCtl_tiObsAntiSatThldMax_C ?
              VSCtl_tiObsAntiSat + VSCtl_tiIncr_ObsAntiSat_C : (SInt32)
              VSCtl_tiObsAntiSatThldMax_C);
          }
          break;

         case VSINFO_Re003tev_Sf_IN_REHAB:
          if ((VSCtl_bObsAntiSatRaw2 == VSINFO_Re003tev_Sf_VRAI_n) &&
              (VSCtl_tiObsAntiSat >= VSCtl_tiObsAntiSatThldMax_C))
          {
            VSCtl_bAuthObsAntiSat = VSINFO_Re003tev_Sf_VRAI_n;
            vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
              VSINFO_Re003tev_Sf_IN_CONF_m;

          }
          else if (VSCtl_bObsAntiSatRaw2 == VSINFO_Re003tev_Sf_FAUX_e)
          {
            VSCtl_bAuthObsAntiSat = VSINFO_Re003tev_Sf_VRAI_n;
            vsinfo_re003tev_sf_dwork.is_NON_INIT_g = (UInt8)
              VSINFO_Re003tev_Sf_IN_DECONF_g;

          }
          else
          {
            VSCtl_tiObsAntiSat = (UInt16)((VSCtl_tiObsAntiSat +
              VSCtl_tiIncr_ObsAntiSat_C) < VSCtl_tiObsAntiSatThldMax_C ?
              VSCtl_tiObsAntiSat + VSCtl_tiIncr_ObsAntiSat_C : (SInt32)
              VSCtl_tiObsAntiSatThldMax_C);
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_AUTORISATION_ANTISATURATION = (UInt8)
        VSINFO_Re003tev_Sf_IN_INIT_j;
      VSCtl_bAuthObsAntiSat = VSINFO_Re003tev_Sf_VRAI_n;
      VSCtl_tiObsAntiSat = 0U;
      break;
    }

    switch (vsinfo_re003tev_sf_dwork.is_ANTISATURATION)
      {
     case VSINFO_Re003tev_Sf_IN_ANTISAT:
      if (((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_NOMINAL_12) ||
           (VSCtl_bObsAntiSatRaw2 == VSINFO_Re003tev_Sf_FAUX_e)) ||
          (VSCtl_bAuthObsAntiSat == VSINFO_Re003tev_Sf_FAUX_e))
      {
        vsinfo_re003tev_sf_dwork.is_ANTISATURATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_NORMAL;
        VSCtl_bObsAntiSat = VSINFO_Re003tev_Sf_FAUX_e;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NORMAL:
      if (((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_NOMINAL_12) &&
           (VSCtl_bObsAntiSatRaw2 == VSINFO_Re003tev_Sf_VRAI_n)) &&
          (VSCtl_bAuthObsAntiSat == VSINFO_Re003tev_Sf_VRAI_n))
      {
        vsinfo_re003tev_sf_dwork.is_ANTISATURATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_ANTISAT;
        VSCtl_bObsAntiSat = VSINFO_Re003tev_Sf_VRAI_n;
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_ANTISATURATION = (UInt8)
        VSINFO_Re003tev_Sf_IN_NORMAL;
      VSCtl_bObsAntiSat = VSINFO_Re003tev_Sf_FAUX_e;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F146132_Filtrer_Conditions_Antisaturation*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F146133_Determiner_Mode_Estimation*/
    /* SSTG_REQ_TAG: CSMT_CGMT08_2268.FR.183.0 */

  if (vsinfo_re003tev_sf_dwork.is_active_c182_VSINFO_Re003tev_Sf == 0)
  {
    vsinfo_re003tev_sf_dwork.is_active_c182_VSINFO_Re003tev_Sf = 1U;
    vsinfo_re003tev_sf_dwork.is_c182_VSINFO_Re003tev_Sf = (UInt8)
      VSINFO_Re003tev_Sf_IN_MODES_ESTIMATION;
    vsinfo_re003tev_sf_dwork.is_MODES_ESTIMATION = (UInt8)
      VSINFO_Re003tev_Sf_IN_INIT_a;
    VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_INIT;
    VSCtl_tiTranDynAntiSat = 0U;

  }
  else
  {
    switch (vsinfo_re003tev_sf_dwork.is_MODES_ESTIMATION)
      {
     case VSINFO_Re003tev_Sf_IN_INIT_a:
      if ((vsinfo_vsctl_stvehinfo_cpy == VSCTL_STVEHINFO_INIT_12)
      || (vsinfo_vsctl_stvehinfo_cpy ==
           VSCTL_STVEHINFO_NOMINAL_12))
      {
        vsinfo_re003tev_sf_dwork.is_MODES_ESTIMATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_NON_INIT_dn;
        vsinfo_re003tev_sf_dwork.is_NON_INIT_f = (UInt8)
          VSINFO_Re003tev_Sf_IN_NOMINAL_h;
        vsinfo_re003tev_sf_dwork.is_NOMINAL = (UInt8)
          VSINFO_Re003tev_Sf_IN_TRANSITOIRE;
        VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_TRANSITOIRE;
      }
      break;

     case VSINFO_Re003tev_Sf_IN_NON_INIT_dn:
      if ((vsinfo_vsctl_stvehinfo_cpy != VSCTL_STVEHINFO_INIT_12)
      && (vsinfo_vsctl_stvehinfo_cpy !=
           VSCTL_STVEHINFO_NOMINAL_12))
      {
        vsinfo_re003tev_sf_dwork.is_NOMINAL = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_f;
        vsinfo_re003tev_sf_dwork.is_NON_INIT_f = (UInt8)
          VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_f;
        vsinfo_re003tev_sf_dwork.is_MODES_ESTIMATION = (UInt8)
          VSINFO_Re003tev_Sf_IN_INIT_a;
        VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_INIT;
        VSCtl_tiTranDynAntiSat = 0U;

      }
      else
      {
        switch (vsinfo_re003tev_sf_dwork.is_NON_INIT_f)
      {
         case VSINFO_Re003tev_Sf_IN_ANTISATURATION:
          if (VSCtl_bObsAntiSat == VSINFO_Re003tev_Sf_FAUX_f)
          {
            vsinfo_re003tev_sf_dwork.is_NON_INIT_f = (UInt8)
              VSINFO_Re003tev_Sf_IN_NOMINAL_h;
            vsinfo_re003tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Re003tev_Sf_IN_TRANSITOIRE;
            VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_TRANSITOIRE;
          }
          break;

         case VSINFO_Re003tev_Sf_IN_NOMINAL_h:
          if (VSCtl_bObsAntiSat == VSINFO_Re003tev_Sf_VRAI_d)
          {
            vsinfo_re003tev_sf_dwork.is_NOMINAL = (UInt8)
              VSINFO_Re003tev_Sf_IN_NO_ACTIVE_CHILD_f;
            vsinfo_re003tev_sf_dwork.is_NON_INIT_f = (UInt8)
              VSINFO_Re003tev_Sf_IN_ANTISATURATION;
            VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_ANTISATURATION;
            VSCtl_tiTranDynAntiSat = VSCtl_tiTol_AntiSatAres1_C;

          }
          else
          {
            switch (vsinfo_re003tev_sf_dwork.is_NOMINAL)
          {
             case VSINFO_Re003tev_Sf_IN_STABILISE:
              if (vsinfo_vsctl_blgtctldyn_cpy == VSCTL_BLGTCTLDYN_TRANSITOIRE)
              {
                vsinfo_re003tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Re003tev_Sf_IN_TRANSITOIRE;
                VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_TRANSITOIRE;
              }
              break;

             case VSINFO_Re003tev_Sf_IN_TRANSITOIRE:
              if ((vsinfo_vsctl_blgtctldyn_cpy == VSCTL_BLGTCTLDYN_STABILISE) &&
                  (VSCtl_tiTranDynAntiSat <= 0))
              {
                vsinfo_re003tev_sf_dwork.is_NOMINAL = (UInt8)
                  VSINFO_Re003tev_Sf_IN_STABILISE;
                VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_STABILISE;

              }
              else
              {
                VSCtl_tiTranDynAntiSat = (UInt16)DDS_M_MAX(VSCtl_tiTranDynAntiSat
                  - 1, 0);
              }
              break;
            }
          }
          break;
        }
      }
      break;

     default:
      vsinfo_re003tev_sf_dwork.is_MODES_ESTIMATION = (UInt8)
        VSINFO_Re003tev_Sf_IN_INIT_a;
      VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_INIT;
      VSCtl_tiTranDynAntiSat = 0U;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F146133_Determiner_Mode_Estimation*/


  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_mVeh_swc_out = vsinfo_vsctl_mveh_cpy;

  *VSCtl_rdWhl_swc_out = vsinfo_vsctl_rdwhl_cpy;

  *VSCtl_bLgtCtlDyn_swc_out = vsinfo_vsctl_blgtctldyn_cpy;

  *VSCtl_stVehInfo_swc_out = vsinfo_vsctl_stvehinfo_cpy;

}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Re003tev_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVehInfo_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bLgtCtlDyn_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_mVeh_swc_out,                                   /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rdWhl_swc_out)                                  /*BIN7*/
{
    VSINFO_Elabor_Car_Info_Sl_Init(VSCtl_mVeh_swc_out, /* BIN0 */
                                    VSCtl_rdWhl_swc_out /* BIN7 */);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiTranDynAntiSat = ((UInt16)0U);
  VSCtl_tiObsAntiSat = ((UInt16)0U);
  VSCtl_tiObsAntiSatRaw = VSCtl_tiTol_AntiSatAres2_C;   /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiBrkPedPrss = VSCtl_tiTol_BrkPedPrss_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiBrkDyn = VSCtl_tiTol_BrkDyn_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiPrkBrk = VSCtl_tiTol_PrkBrk_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiBrkAuto = VSCtl_tiTol_BrkAuto_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiSIP = VSCtl_tiTol_SIP_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiLgtCtlDynChg = VSCtl_tiTol_LgtCtlDyn_C;   /* Replaced by Post task */     /* Init from Model */
  vsinfo_vsctl_mveh_cpy = *VSCtl_mVeh_swc_out;

  VSCtl_tiIniVehClc = VSCtl_tiIni_VehInfo_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_rAccPT = 12800U;
  vsinfo_vsctl_rdwhl_cpy = *VSCtl_rdWhl_swc_out;

  VSCtl_stObsDyn = VSCTL_STOBSDYN_DYN_INIT; /* Replaced by Post task */     /* Init from Model */
  *VSCtl_bLgtCtlDyn_swc_out = VSCTL_BLGTCTLDYN_TRANSITOIRE; /* Replaced by Post task */     /* Init from Model */
  vsinfo_vsctl_blgtctldyn_cpy = *VSCtl_bLgtCtlDyn_swc_out;

  *VSCtl_stVehInfo_swc_out = VSCTL_STVEHINFO_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsinfo_vsctl_stvehinfo_cpy = *VSCtl_stVehInfo_swc_out;



  vsinfo_re003tev_sf_dwork.is_ETAT_INFORMATIONS_VEHICULE = 0U;
  vsinfo_re003tev_sf_dwork.is_MARCHE = 0U;
  vsinfo_re003tev_sf_dwork.is_PAS_DEFAUT = 0U;
  vsinfo_re003tev_sf_dwork.is_active_c177_VSINFO_Re003tev_Sf = 0U;
  vsinfo_re003tev_sf_dwork.is_c177_VSINFO_Re003tev_Sf = 0U;
  VSCtl_bAcvFilVehInfo =DDS_FALSE;



  vsinfo_re003tev_sf_dwork.is_MODES_CONTROLE_DYNAMIQUE_LONGITUDINALE = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INIT = 0U;
  vsinfo_re003tev_sf_dwork.is_active_c178_VSINFO_Re003tev_Sf = 0U;
  vsinfo_re003tev_sf_dwork.is_c178_VSINFO_Re003tev_Sf = 0U;



  vsinfo_re003tev_sf_dwork.is_active_INHIBITION_ACCELERATION_GMP = 0U;
  vsinfo_re003tev_sf_dwork.is_INHIBITION_ACCELERATION_GMP = 0U;
  vsinfo_re003tev_sf_dwork.is_active_TAUX_LISSAGE_ACCELERATION = 0U;
  vsinfo_re003tev_sf_dwork.is_TAUX_LISSAGE_ACCELERATION = 0U;
  vsinfo_re003tev_sf_dwork.is_active_c179_VSINFO_Re003tev_Sf = 0U;
  vsinfo_re003tev_sf_dwork.is_c179_VSINFO_Re003tev_Sf = 0U;
  VSCtl_bInh_aPT =DDS_FALSE;
  vsinfo_re003tev_sf_b.VSCtl_rAccPT_h = 0U;



  vsinfo_re003tev_sf_dwork.is_active_ANTISATURATION_BRUTE = 0U;
  vsinfo_re003tev_sf_dwork.is_ANTISATURATION_BRUTE = 0U;
  vsinfo_re003tev_sf_dwork.is_active_APPUI_PEDALE_FREIN = 0U;
  vsinfo_re003tev_sf_dwork.is_APPUI_PEDALE_FREIN = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INACTIF_p = 0U;
  vsinfo_re003tev_sf_dwork.is_active_CHANGEMENT_RAPPORT_PERMANENT = 0U;
  vsinfo_re003tev_sf_dwork.is_CHANGEMENT_RAPPORT_PERMANENT = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INACTIF_px = 0U;
  vsinfo_re003tev_sf_dwork.is_active_FREINAGE_AUTOMATIQUE = 0U;
  vsinfo_re003tev_sf_dwork.is_FREINAGE_AUTOMATIQUE = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INACTIF_lw = 0U;
  vsinfo_re003tev_sf_dwork.is_active_FREINAGE_DYNAMIQUE = 0U;
  vsinfo_re003tev_sf_dwork.is_FREINAGE_DYNAMIQUE = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INACTIF_g = 0U;
  vsinfo_re003tev_sf_dwork.is_active_SERRAGE_FREIN_MANUEL = 0U;
  vsinfo_re003tev_sf_dwork.is_SERRAGE_FREIN_MANUEL = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INACTIF_l = 0U;
  vsinfo_re003tev_sf_dwork.is_active_c180_VSINFO_Re003tev_Sf = 0U;
  vsinfo_re003tev_sf_dwork.is_c180_VSINFO_Re003tev_Sf = 0U;
  VSCtl_bObsAntiSatRaw =DDS_FALSE;
  VSCtl_bBrkPedPrss =DDS_FALSE;
  VSCtl_bBrkDyn =DDS_FALSE;
  VSCtl_bPrkBrk =DDS_FALSE;
  VSCtl_bBrkAuto =DDS_FALSE;
  VSCtl_bSIPFil =DDS_FALSE;



  vsinfo_re003tev_sf_dwork.is_active_ANTISATURATION = 0U;
  vsinfo_re003tev_sf_dwork.is_ANTISATURATION = 0U;
  vsinfo_re003tev_sf_dwork.is_active_AUTORISATION_ANTISATURATION = 0U;
  vsinfo_re003tev_sf_dwork.is_AUTORISATION_ANTISATURATION = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INIT_g = 0U;
  vsinfo_re003tev_sf_dwork.is_active_FILTRAGE_ANTISATURATION_PERMANENTE = 0U;
  vsinfo_re003tev_sf_dwork.is_FILTRAGE_ANTISATURATION_PERMANENTE = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INACTIF = 0U;
  vsinfo_re003tev_sf_dwork.is_active_c181_VSINFO_Re003tev_Sf = 0U;
  vsinfo_re003tev_sf_dwork.is_c181_VSINFO_Re003tev_Sf = 0U;
  VSCtl_bObsAntiSat =DDS_FALSE;
  VSCtl_bAuthObsAntiSat =DDS_FALSE;
  VSCtl_bObsAntiSatRaw2 =DDS_FALSE;
  VSCtl_bObsAntiSatRaw2Prev =DDS_FALSE;



  vsinfo_re003tev_sf_dwork.is_MODES_ESTIMATION = 0U;
  vsinfo_re003tev_sf_dwork.is_NON_INIT_f = 0U;
  vsinfo_re003tev_sf_dwork.is_NOMINAL = 0U;
  vsinfo_re003tev_sf_dwork.is_active_c182_VSINFO_Re003tev_Sf = 0U;
  vsinfo_re003tev_sf_dwork.is_c182_VSINFO_Re003tev_Sf = 0U;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

