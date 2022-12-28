/*
* File: VSREG_Det_Cond_Fct_Veh_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSREG_Det_Cond_Fct_Veh_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Mon Nov 21 12:06:15 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Mon Nov 21 12:06:16 2011
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
*        AUT_EC_m_limit_opt SFunction version: 3.0, TLC version: 12.2
*        AUT_EC_Function_Stub_v1 SFunction version: 6.0, TLC version: 1.0
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
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Det_Cond_Fct_Veh_Sf.c
* Version int :/main/L01_02/1 Date: 5/1/2012 11 h 24 m User:esnault 
*    TWK_model:VSREG_Det_Cond_Fct_Veh_Sf_L01_020_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_halouane_vsreg_euro6\1 Date: 4/1/2012 15 h 41 m User:halouane 
*    TWK_model:VSREG_Det_Cond_Fct_Veh_Sf_L01_020_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 21/11/2011 12 h 12 m User:demezil
*    TWK_model:VSREG_Det_Cond_Fct_Veh_Sf_L01_020_IMPL1
*    comments :for VSReg 12.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Activation_Surveillance_Accelerations_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Activation_Surveillance_Accelerations_Vehicule ;VSCtl_bAvlTqWhlPT_no3;VSCtl_bCtlaTqPT;VSCtl_bDrvOvrdVSReg_aVeh;VSCtl_bDrvOvrdVSReg_spdVeh;VSCtl_stMonVSReg;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Activation_Surveillance_Accelerations_Vehicule ;VSCtl_bAcvMonAVehVSReg;VSCtl_bCtlaTqPTPrevVSReg;VSCtl_tiFilMonAVehVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Activation_Surveillance_Accelerations_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule ;VSCtl_aVeh;VSCtl_bAcvMonAVehVSReg;VSCtl_jrkVeh;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule ;VSCtl_aVehAccRefVSReg;VSCtl_bAccVehVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Max ;VSCtl_aVeh;VSCtl_aVehPTMax;VSCtl_bAcvMonAVehVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Max ;VSCtl_bAccVehMaxVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Min ;VSCtl_aVeh;VSCtl_aVehPTMin;VSCtl_bAcvMonAVehVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Min ;VSCtl_bAccVehMinVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Acceleration_Vehicule_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Alerte_Choc_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Alerte_Choc_Vehicule ;Ext_bVehCollWarn;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Alerte_Choc_Vehicule ;VSCtl_bVehCollWarnVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Alerte_Choc_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Deceleration_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Deceleration_Vehicule ;VSCtl_aVeh;VSCtl_bAcvMonAVehVSReg;VSCtl_jrkVeh;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Deceleration_Vehicule ;VSCtl_aVehDeceRefVSReg;VSCtl_bDeceVehVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Deceleration_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Reprise_Vitesse_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Reprise_Vitesse_Vehicule ;Ext_spdVehVSRegReq;VSCtl_stMonVSReg;VSCtl_stVSRegExtd;Veh_spdVeh; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Reprise_Vitesse_Vehicule ;VSCtl_bSpdVehDrvOvrdVSReg;VSCtl_tiFilDrvOvrdVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Reprise_Vitesse_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Max */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Max ;VSCtl_stMonVSReg;Veh_spdVeh; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Max ;VSCtl_bSpdVehMaxVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Max */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Min */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Min ;VSCtl_stMonVSReg;VSCtl_stVSRegExtd;Veh_spdVeh; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Min ;VSCtl_bSpdVehMinVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Vitesse_Vehicule_Min */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Vehicule ;VSCtl_bFastDeacVSRegReq_Veh;VSCtl_bSpdVehDrvOvrdVSReg;VSCtl_bSpdVehMaxVSReg;VSCtl_bSpdVehMinVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Vehicule ;VSCtl_bInhVSRegReq_Veh; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Vehicule ;VSCtl_bAccVehMaxVSReg;VSCtl_bAccVehMinVSReg;VSCtl_bAccVehVSReg;VSCtl_bDeceVehVSReg;VSCtl_bVehCollWarnVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Vehicule ;VSCtl_bFastDeacVSRegReq_Veh; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Vehicule */

/* TAG_START_OF_SUB_FUNCTION: F21234_Determiner_Condition_Conditions_Maintenance_Vehicule */
/* TAG_INPUT_OF_SUB_FUNCTION: F21234_Determiner_Condition_Conditions_Maintenance_Vehicule ;VSCtl_bAccVehMaxVSReg;VSCtl_bAccVehMinVSReg;VSCtl_bAccVehVSReg;VSCtl_bDeceVehVSReg;VSCtl_bSpdVehDrvOvrdVSReg;VSCtl_bSpdVehMaxVSReg;VSCtl_bSpdVehMinVSReg;VSCtl_bVehCollWarnVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F21234_Determiner_Condition_Conditions_Maintenance_Vehicule ;VSCtl_stDeacVSRegReq_Veh; */
/* TAG_END_OF_SUB_FUNCTION: F21234_Determiner_Condition_Conditions_Maintenance_Vehicule */

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
/*VSCtl_stVSRegExtd */
#define VSCTL_STVSREGEXTD_ARRET                 (0)
#define VSCTL_STVSREGEXTD_INITIALISATION        (1)
#define VSCTL_STVSREGEXTD_INHIBEE               (2)
#define VSCTL_STVSREGEXTD_ATTENTE               (3)
#define VSCTL_STVSREGEXTD_ANE                   (4)
#define VSCTL_STVSREGEXTD_AE                    (5)
#define VSCTL_STVSREGEXTD_REPRISE               (6)
#define VSCTL_STVSREGEXTD_DEFAUT                (7)

/* Named constants for block: /Activation_Surveillance_Accelerations_Vehicule' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_j (0)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_TEMPO (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_i (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_f (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ACTIF (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ACTIVATION_SURVEILLANCE_ACCELERATIONS_VEHICULE (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_f (1U)

/* Named constants for block: /Condition_Acceleration_Vehicule_Max' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_js (0)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ACCELERATION_MAX (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_p (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_k (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_m (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_n (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_jl (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_l (1U)

/* Named constants for block: /Condition_Acceleration_Vehicule_Min' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_c (0)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_f3 (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_d (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_pw (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ACCELERATION_MIN (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_p (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_h (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_p (1U)

/* Named constants for block: /Condition_Deceleration_Vehicule' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_h (0)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_l (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_b (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_hg (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NON_INIT (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_DECELERATION (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_d (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_e (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_d (1U)

/* Named constants for block: /Condition_Acceleration_Vehicule' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_m (0)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_j (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_a (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NON_INIT_a (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT_h (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_d (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_h (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ACCELERATION (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_o (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h3 (1U)

/* Named constants for block: /Condition_Alerte_Choc_Vehicule' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ALERTE_CHOC_VEHICULE (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_jw (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_o (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_c (1U)

/* Named constants for block: /Demandes_Desactivation_Rapide_Vehicule' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_PAS_DEMANDEE (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_DESACTIVATION_RAPIDE_VEHICULE (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht (1U)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_n (0U)

/* Named constants for block: /Condition_Vitesse_Vehicule_Max' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_VITESSE_VEHICULE_MAX (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI (1U)

/* Named constants for block: /Condition_Vitesse_Vehicule_Min' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_VITESSE_VEHICULE_MIN (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_b (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_h (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_i (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_i (1U)

/* Named constants for block: /Condition_Reprise_Vitesse_Vehicule' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_i (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_REPRISE_VITESSE_VEHICULE (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1_CONFIRMATION (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_ATTENTE (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1 (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE2 (3)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1_CONFIRME (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_j (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h (1U)

/* Named constants for block: /Demandes_Desactivation_Inhibition_Vehicule' */
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_PAS_DEMANDEE_k (2)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE_p (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDE_INHIBITION_VEHICULE (1)
#define VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k1 (0U)
#define VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m (1U)

/* Definition for custom storage class: Define */
#define VSCTL_AVEHACCREFVSREG_MAX      10240
#define VSCTL_AVEHACCREFVSREG_MIN      (-10240)
#define VSCTL_AVEHDECEREFVSREG_MAX     10240
#define VSCTL_AVEHDECEREFVSREG_MIN     (-10240)


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
VAR(UInt8, AUTOMATIC) VSCtl_bVehCollWarnVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bSpdVehMinVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bSpdVehMaxVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bSpdVehDrvOvrdVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq_Veh;
VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq_Veh;
VAR(UInt8, AUTOMATIC) VSCtl_bDeceVehVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAccVehVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAccVehMinVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bAccVehMaxVSReg;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  SInt16 VSCtl_aVehAccRefVSReg_b;
  SInt16 VSCtl_aVehDeceRefVSReg_i;
} BlockIO_VSREG_Det_Cond_Fct_Veh_Sf;


typedef struct {
  UInt32 is_DEMANDE_INHIBITION_VEHICULE : 2;
  UInt32 is_DESACTIVATION_RAPIDE_VEHICULE : 2;
  UInt32 is_CONDITION_ALERTE_CHOC_VEHICULE : 2;
  UInt32 is_NON_INIT : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_CONDITION_ACCELERATION : 2;
  UInt32 is_MARCHE_h : 2;
  UInt32 is_NON_INIT_d : 2;
  UInt32 is_CONDITION_DECELERATION : 2;
  UInt32 is_MARCHE_k : 2;
  UInt32 is_CONDITION_ACCELERATION_MIN : 2;
  UInt32 is_CONDITION_ACCELERATION_MAX : 2;
  UInt32 is_MARCHE_c : 2;
  UInt32 is_MARCHE_i : 2;
  UInt32 is_ACTIVATION : 2;
  UInt32 is_REPRISE : 2;
  UInt32 is_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE : 2;
  UInt32 is_MARCHE_f : 2;
  UInt32 is_REPRISE_SURVITESSE1 : 2;
  UInt32 is_CONDITION_VITESSE_VEHICULE_MIN : 2;
  UInt32 is_CONDITION_VITESSE_VEHICULE_MAX : 2;
  UInt32 is_active_c73_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c73_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c72_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c72_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c71_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c71_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c69_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c69_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c68_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c68_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c63_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c63_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c62_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c62_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c61_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c61_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_ACTIVATION : 1;
  UInt32 is_active_MEMOIRES : 1;
  UInt32 is_active_c60_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c60_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE : 1;
  UInt32 is_active_c59_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c59_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_active_c58_VSREG_Det_Cond_Fct_Veh_Sf : 1;
  UInt32 is_c58_VSREG_Det_Cond_Fct_Veh_Sf : 1;
} D_Work_VSREG_Det_Cond_Fct_Veh_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehAccRefVSReg;                  /*BIN10*/
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehDeceRefVSReg;                 /*BIN10*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFilDrvOvrdVSReg;                /*BIN0*/
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"


/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilMonAVehVSReg;                 /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvMonAVehVSReg;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlaTqPTPrevVSReg;
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
STATIC VAR(BlockIO_VSREG_Det_Cond_Fct_Veh_Sf, AUTOMATIC) vsreg_det_cond_fct_veh_sf_b;
STATIC VAR(D_Work_VSREG_Det_Cond_Fct_Veh_Sf, AUTOMATIC) vsreg_det_cond_fct_veh_sf_dwork;
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
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehErrMaxAccMonVSReg_C = (CONST(SInt16, AUTOMATIC))(10240); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehErrMaxDeceMonVSReg_C = (CONST(SInt16, AUTOMATIC))(-10240); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMax1MonVSReg_HysHi_C = (CONST(SInt16, AUTOMATIC))(10240); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMax1MonVSReg_HysLo_C = (CONST(SInt16, AUTOMATIC))(10240); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMax2MonVSReg_HysHi_C = (CONST(SInt16, AUTOMATIC))(2560); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMax2MonVSReg_HysLo_C = (CONST(SInt16, AUTOMATIC))(2458); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMin1MonVSReg_HysHi_C = (CONST(SInt16, AUTOMATIC))(-10240); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMin1MonVSReg_HysLo_C = (CONST(SInt16, AUTOMATIC))(-10240); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMin2MonVSReg_HysHi_C = (CONST(SInt16, AUTOMATIC))(-2048); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehMin2MonVSReg_HysLo_C = (CONST(SInt16, AUTOMATIC))(-2560); /*BIN10*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jVehMaxAccVSReg_HysHi_C = (CONST(SInt16, AUTOMATIC))(12800); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jVehMaxAccVSReg_HysLo_C = (CONST(SInt16, AUTOMATIC))(12800); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jVehMinDeceVSReg_HysHi_C = (CONST(SInt16, AUTOMATIC))(-12800); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jVehMinDeceVSReg_HysLo_C = (CONST(SInt16, AUTOMATIC))(-12800); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErrOvrdVSReg_Hi1_C = (CONST(SInt16, AUTOMATIC))(32640); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErrOvrdVSReg_Lo1_C = (CONST(SInt16, AUTOMATIC))(32640); /*BIN7*/
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErrOvrdVSReg_Thd2_C = (CONST(SInt16, AUTOMATIC))(32640); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehMaxVSReg_HysHi_C = (CONST(UInt16, AUTOMATIC))(29440U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehMaxVSReg_HysLo_C = (CONST(UInt16, AUTOMATIC))(28160U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehMin1VSReg_HysLo_C = (CONST(UInt16, AUTOMATIC))(3712U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehMin2VSReg_HysLo_C = (CONST(UInt16, AUTOMATIC))(3200U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehMinVSReg_HysHi_C = (CONST(UInt16, AUTOMATIC))(4992U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_bDrvOvrdVSReg_C = (CONST(UInt16, AUTOMATIC))(65000U); /*BIN0*/
#define VSREG_STOP_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"


/* 8BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiAcv_MonVSReg_C = (CONST(UInt8, AUTOMATIC))(24U);        /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvMonAVehVSReg_C = DDS_TRUE;
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

FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Veh_Sf(UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                               SInt16 VSCtl_jrkVeh_swc_in,                          /*BIN7*/
                               UInt8 Ext_bVehCollWarn_swc_in,
                               SInt16 VSCtl_aVehPTMin_swc_in,                       /*BIN10*/
                               SInt16 VSCtl_aVehPTMax_swc_in,                       /*BIN10*/
                               UInt8 Ext_spdVehVSRegReq_swc_in,                     /*BIN0*/
                               UInt8 VSCtl_bCtlaTqPT_swc_in,
                               UInt16 Veh_spdVeh_swc_in,                            /*BIN7*/
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               UInt8 VSCtl_bDrvOvrdVSReg_aVeh_swc_in,
                               SInt16 VSCtl_aVeh_swc_in)                            /*BIN10*/
{

  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F212321_Determiner_Activation_Surveillance_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.44.4  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c61_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c61_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c61_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_ACTIVATION_SURVEILLANCE_ACCELERATIONS_VEHICULE;
    vsreg_det_cond_fct_veh_sf_dwork.is_active_ACTIVATION = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_ACTIVATION = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_i;
    VSCtl_bAcvMonAVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f;
    VSCtl_tiFilMonAVehVSReg = VSCtl_tiAcv_MonVSReg_C;
    vsreg_det_cond_fct_veh_sf_dwork.is_active_MEMOIRES = 1U;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_ACTIVATION) {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_i:
      if ((VSCtl_bAcvMonAVehVSReg_C == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_f)
      &&
          (((((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
              (VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_AE)) &&
             (VSCtl_bDrvOvrdVSReg_aVeh_swc_in == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f))
             &&
            (VSCtl_bDrvOvrdVSReg_spdVeh_swc_in == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f))
            &&
           (VSCtl_bAvlTqWhlPT_no3_swc_in == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_f)))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_ACTIVATION = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_f;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_i = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_TEMPO;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_f:
      if ((VSCtl_bAcvMonAVehVSReg_C == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f)
      ||
          ((((((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
               (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE)) ||
              (VSCtl_bDrvOvrdVSReg_aVeh_swc_in == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_f))
              ||
             (VSCtl_bDrvOvrdVSReg_spdVeh_swc_in == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_f))
             ||
            (VSCtl_bCtlaTqPT_swc_in != VSCtl_bCtlaTqPTPrevVSReg)) ||
           (VSCtl_bAvlTqWhlPT_no3_swc_in == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f)))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_i = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_j;
        vsreg_det_cond_fct_veh_sf_dwork.is_ACTIVATION = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_i;
        VSCtl_bAcvMonAVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f;
        VSCtl_tiFilMonAVehVSReg = VSCtl_tiAcv_MonVSReg_C;

      }
      else
      {
        switch (vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_i)
      {
         case VSREG_Det_Cond_Fct_Veh_Sf_IN_TEMPO:
          if (VSCtl_tiFilMonAVehVSReg == 0)
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_i = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_ACTIF;
            VSCtl_bAcvMonAVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_f;
            VSCtl_tiFilMonAVehVSReg = VSCtl_tiAcv_MonVSReg_C;

          }
          else
          {
            VSCtl_tiFilMonAVehVSReg = (UInt8)DDS_M_MAX(VSCtl_tiFilMonAVehVSReg -
              1, 0);
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_ACTIVATION = (UInt8)
        VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_i;
      VSCtl_bAcvMonAVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_f;
      VSCtl_tiFilMonAVehVSReg = VSCtl_tiAcv_MonVSReg_C;
      break;
    }

    VSCtl_bCtlaTqPTPrevVSReg = VSCtl_bCtlaTqPT_swc_in;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212321_Determiner_Activation_Surveillance_Acceleration_Vehicule*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F212322_Determiner_Condition_Acceleration_Vehicule_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.45.3  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c62_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c62_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c62_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ACCELERATION_MAX;
    vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MAX = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_n;
    VSCtl_bAccVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_l;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MAX)
      {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_n:
      if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MAX = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_m;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_c = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_k;
        VSCtl_bAccVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_jl;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_m:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_c = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_js;
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MAX = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_n;
        VSCtl_bAccVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_l;

      }
      else
      {
        switch (vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_c)
      {
         case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_k:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_l)
          &&
              ((VSCtl_aVeh_swc_in > VSCtl_aVehMax2MonVSReg_HysHi_C)
              || (VSCtl_aVeh_swc_in >
                (VSCtl_aVehPTMax_swc_in + VSCtl_aVehMax1MonVSReg_HysHi_C))))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_c = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_p;
            VSCtl_bAccVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_l;
          }
          break;

         case VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_p:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_jl)
          ||
              ((VSCtl_aVeh_swc_in <= VSCtl_aVehMax2MonVSReg_HysLo_C)
              && (VSCtl_aVeh_swc_in <=
                (VSCtl_aVehPTMax_swc_in + VSCtl_aVehMax1MonVSReg_HysLo_C))))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_c = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_k;
            VSCtl_bAccVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_jl;
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MAX = (UInt8)
        VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_n;
      VSCtl_bAccVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_l;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212322_Determiner_Condition_Acceleration_Vehicule_Max*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F212323_Determiner_Condition_Acceleration_Vehicule_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.46.3  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c63_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c63_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c63_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ACCELERATION_MIN;
    vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MIN = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_p;
    VSCtl_bAccVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_p;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MIN)
          {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_p:
      if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MIN = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_f3;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_k = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_d;
        VSCtl_bAccVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_h;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_f3:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_k = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_c;
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MIN = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_p;
        VSCtl_bAccVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_p;

      }
      else
      {
        switch (vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_k)
      {
         case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_d:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_p)
          &&
              ((VSCtl_aVeh_swc_in < VSCtl_aVehMin2MonVSReg_HysLo_C)
              || (VSCtl_aVeh_swc_in <
                (VSCtl_aVehPTMin_swc_in + VSCtl_aVehMin1MonVSReg_HysLo_C))))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_k = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_pw;
            VSCtl_bAccVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_p;
          }
          break;

         case VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_pw:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_h)
          ||
              ((VSCtl_aVeh_swc_in >= VSCtl_aVehMin2MonVSReg_HysHi_C)
              && (VSCtl_aVeh_swc_in >=
                (VSCtl_aVehPTMin_swc_in + VSCtl_aVehMin1MonVSReg_HysHi_C))))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_k = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_d;
            VSCtl_bAccVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_h;
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MIN = (UInt8)
        VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_p;
      VSCtl_bAccVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_p;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212323_Determiner_Condition_Acceleration_Vehicule_Min*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F212324_Determiner_Condition_Deceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.47.3  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c68_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c68_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c68_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_DECELERATION;
    vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_DECELERATION = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_b;
    VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_d;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_DECELERATION)
          {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_b:
      if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_DECELERATION = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_l;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_h = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT;
        VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_e;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_l:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT_d = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_h;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_h = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_h;
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_DECELERATION = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_b;
        VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_d;

      }
      else
      {
        switch (vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_h)
      {
         case VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_d)
          &&
              (VSCtl_jrkVeh_swc_in < VSCtl_jVehMinDeceVSReg_HysLo_C))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_h = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_NON_INIT;
            vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT_d = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_hg;
            VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_e;
            vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehDeceRefVSReg_i = VSCtl_aVeh_swc_in;
          }
          break;

         case VSREG_Det_Cond_Fct_Veh_Sf_IN_NON_INIT:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_e)
          ||
              (VSCtl_jrkVeh_swc_in >= VSCtl_jVehMinDeceVSReg_HysHi_C))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT_d = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_h;
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_h = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT;
            VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_e;

          }
          else
          {
            switch (vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT_d)
          {
             case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_hg:
              if (VSCtl_aVeh_swc_in <
                  (vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehDeceRefVSReg_i -
                   VSCtl_aVehErrMaxDeceMonVSReg_C))
              {
                vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT_d = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_d;
                VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_d;
              }
              break;

             case VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_d:
              if (VSCtl_aVeh_swc_in >
                  vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehDeceRefVSReg_i)
              {
                vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT_d = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_h;
                vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_h = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT;
                VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_e;
              }
              break;
            }
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_DECELERATION = (UInt8)
        VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_b;
      VSCtl_bDeceVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_d;
      break;
    }
  }

  VSCtl_aVehDeceRefVSReg = DDS_M_LIMIT
    (vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehDeceRefVSReg_i,
     VSCTL_AVEHDECEREFVSREG_MIN,
     VSCTL_AVEHDECEREFVSREG_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212324_Determiner_Condition_Deceleration_Vehicule*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F212325_Determiner_Condition_Acceleration_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.106.0  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c69_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c69_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c69_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ACCELERATION;
    vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_h;
    VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h3;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION)
              {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_h:
      if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_d;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT_h;
        VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_o;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE_d:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_m;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_m;
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_h;
        VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h3;

      }
      else
      {
        switch (vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE)
      {
         case VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT_h:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h3)
          &&
              (VSCtl_jrkVeh_swc_in > VSCtl_jVehMaxAccVSReg_HysHi_C))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_NON_INIT_a;
            vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_a;
            VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_o;
            vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehAccRefVSReg_b = VSCtl_aVeh_swc_in;
          }
          break;

         case VSREG_Det_Cond_Fct_Veh_Sf_IN_NON_INIT_a:
          if ((VSCtl_bAcvMonAVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_o)
          ||
              (VSCtl_jrkVeh_swc_in <= VSCtl_jVehMaxAccVSReg_HysLo_C))
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_m;
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT_h;
            VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_o;

          }
          else
          {
            switch (vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT)
          {
             case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_a:
              if (VSCtl_aVeh_swc_in >
                  (vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehAccRefVSReg_b +
                   VSCtl_aVehErrMaxAccMonVSReg_C))
              {
                vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_j;
                VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h3;
              }
              break;

             case VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_j:
              if (VSCtl_aVeh_swc_in <
                  vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehAccRefVSReg_b)
              {
                vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD_m;
                vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_INIT_h;
                VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_o;
              }
              break;
            }
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION = (UInt8)
        VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET_h;
      VSCtl_bAccVehVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h3;
      break;
    }
  }

  VSCtl_aVehAccRefVSReg = DDS_M_LIMIT
    (vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehAccRefVSReg_b,
     VSCTL_AVEHACCREFVSREG_MIN,
     VSCTL_AVEHACCREFVSREG_MAX);

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212325_Determiner_Condition_Acceleration_Vehicule*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F21233_Determiner_Condition_Alerte_Choc_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.107.0  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c71_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c71_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c71_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_ALERTE_CHOC_VEHICULE;
    vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ALERTE_CHOC_VEHICULE = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_jw;
    VSCtl_bVehCollWarnVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_c;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ALERTE_CHOC_VEHICULE)
              {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_o:
      if ((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      || (Ext_bVehCollWarn_swc_in ==
           VSREG_Det_Cond_Fct_Veh_Sf_VRAI_c))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ALERTE_CHOC_VEHICULE =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_jw;
        VSCtl_bVehCollWarnVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_c;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_jw:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bVehCollWarn_swc_in ==
           VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ALERTE_CHOC_VEHICULE =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_o;
        VSCtl_bVehCollWarnVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k;
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ALERTE_CHOC_VEHICULE =
        (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_jw;
      VSCtl_bVehCollWarnVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_c;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21233_Determiner_Condition_Alerte_Choc_Vehicule*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F21235_Determiner_Condition_Desactivation_Rapide_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.109.0 */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c72_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c72_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c72_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_DESACTIVATION_RAPIDE_VEHICULE;
    vsreg_det_cond_fct_veh_sf_dwork.is_DESACTIVATION_RAPIDE_VEHICULE = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE;
    VSCtl_bFastDeacVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_DESACTIVATION_RAPIDE_VEHICULE)
      {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE:
      if ((((((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
              (VSCtl_bAccVehMaxVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_n))
              &&
             (VSCtl_bAccVehMinVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_n))
             &&
            (VSCtl_bDeceVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_n))
            &&
           (VSCtl_bAccVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_n))
           &&
          (VSCtl_bVehCollWarnVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_n))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_DESACTIVATION_RAPIDE_VEHICULE =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_PAS_DEMANDEE;
        VSCtl_bFastDeacVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_n;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_PAS_DEMANDEE:
      if ((((((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
              (VSCtl_bAccVehMaxVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht))
              ||
             (VSCtl_bAccVehMinVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht))
             ||
            (VSCtl_bDeceVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht))
            ||
           (VSCtl_bAccVehVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht))
           ||
          (VSCtl_bVehCollWarnVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_DESACTIVATION_RAPIDE_VEHICULE =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE;
        VSCtl_bFastDeacVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht;
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_DESACTIVATION_RAPIDE_VEHICULE =
        (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE;
      VSCtl_bFastDeacVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_ht;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21235_Determiner_Condition_Desactivation_Rapide_Vehicule*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F212311_Determiner_Condition_Vitesse_Vehicule_Max*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.41.4  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c58_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c58_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c58_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_VITESSE_VEHICULE_MAX;
    vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MAX = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI;
    VSCtl_bSpdVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MAX)
      {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX:
      if ((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      || (Veh_spdVeh_swc_in >=
           VSCtl_spdVehMaxVSReg_HysHi_C))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MAX =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI;
        VSCtl_bSpdVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Veh_spdVeh_swc_in <
           VSCtl_spdVehMaxVSReg_HysLo_C))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MAX =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX;
        VSCtl_bSpdVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX;
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MAX =
        (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI;
      VSCtl_bSpdVehMaxVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212311_Determiner_Condition_Vitesse_Vehicule_Max*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F212312_Determiner_Condition_Vitesse_Vehicule_Min*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.42.4  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c59_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c59_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c59_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_VITESSE_VEHICULE_MIN;
    vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MIN = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_b;
    VSCtl_bSpdVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_i;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MIN)
      {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_h:
      if (((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
           ((((VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_AE)
           && (VSCtl_stVSRegExtd_swc_in
               != VSCTL_STVSREGEXTD_ANE)) && (VSCtl_stVSRegExtd_swc_in !=
              VSCTL_STVSREGEXTD_REPRISE)) && (Veh_spdVeh_swc_in <=
             VSCtl_spdVehMin1VSReg_HysLo_C)))
             || ((((VSCtl_stVSRegExtd_swc_in ==
              VSCTL_STVSREGEXTD_AE) || (VSCtl_stVSRegExtd_swc_in ==
              VSCTL_STVSREGEXTD_ANE)) || (VSCtl_stVSRegExtd_swc_in ==
             VSCTL_STVSREGEXTD_REPRISE)) && (Veh_spdVeh_swc_in <=
            VSCtl_spdVehMin2VSReg_HysLo_C)))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MIN =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_b;
        VSCtl_bSpdVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_i;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_b:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Veh_spdVeh_swc_in >
           VSCtl_spdVehMinVSReg_HysHi_C))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MIN =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_h;
        VSCtl_bSpdVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_i;
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MIN =
        (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_VRAI_b;
      VSCtl_bSpdVehMinVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_i;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212312_Determiner_Condition_Vitesse_Vehicule_Min*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F212313_Determiner_Condition_Reprise_Vitesse*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.105.0  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c60_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c60_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c60_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_CONDITION_REPRISE_VITESSE_VEHICULE;
    vsreg_det_cond_fct_veh_sf_dwork.is_active_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE
      = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE
      = (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET;
    VSCtl_bSpdVehDrvOvrdVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h;
    VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;

  }
  else
  {
    switch
      (vsreg_det_cond_fct_veh_sf_dwork.is_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE)
    {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET:
      if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE
          = (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE;
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_f = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_i;
        VSCtl_bSpdVehDrvOvrdVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_j;
        VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_MARCHE:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_f = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1 = (UInt8)
          VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_cond_fct_veh_sf_dwork.is_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE
          = (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET;
        VSCtl_bSpdVehDrvOvrdVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h;
        VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;

      }
      else
      {
        switch (vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_f)
      {
         case VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_i:
          if (VSCtl_stVSRegExtd_swc_in == VSCTL_STVSREGEXTD_REPRISE)
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_f = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE;
            vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_ATTENTE;
            VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;
          }
          break;

         case VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE:
          if (VSCtl_stVSRegExtd_swc_in != VSCTL_STVSREGEXTD_REPRISE)
          {
            vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1 = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_f = (UInt8)
              VSREG_Det_Cond_Fct_Veh_Sf_IN_FAUX_i;
            VSCtl_bSpdVehDrvOvrdVSReg = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_j;
            VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;

          }
          else
          {
            switch (vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE)
          {
             case VSREG_Det_Cond_Fct_Veh_Sf_IN_ATTENTE:
              if (Veh_spdVeh_swc_in > ((Ext_spdVehVSRegReq_swc_in << 7) +
                                VSCtl_spdErrOvrdVSReg_Hi1_C))
              {
                vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1;
                vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1 =
                  (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1_CONFIRMATION;
              }
              break;

             case VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1:
              if (Veh_spdVeh_swc_in < ((Ext_spdVehVSRegReq_swc_in << 7) +
                                VSCtl_spdErrOvrdVSReg_Lo1_C))
              {
                vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1 =
                  (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD;
                vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_ATTENTE;
                VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;

              }
              else if (Veh_spdVeh_swc_in > ((Ext_spdVehVSRegReq_swc_in << 7) +
                          VSCtl_spdErrOvrdVSReg_Thd2_C))
              {
                vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1 =
                  (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_NO_ACTIVE_CHILD;
                vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE = (UInt8)
                  VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE2;
                VSCtl_bSpdVehDrvOvrdVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h;

              }
              else
              {
                switch (vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1)
                {
                 case
                    VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1_CONFIRMATION:
                  if (VSCtl_tiFilDrvOvrdVSReg == 0)
                  {
                    vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1 =
                      (UInt8)
                      VSREG_Det_Cond_Fct_Veh_Sf_IN_REPRISE_SURVITESSE1_CONFIRME;
                    VSCtl_bSpdVehDrvOvrdVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h;

                  }
                  else
                  {
                    VSCtl_tiFilDrvOvrdVSReg = (UInt16)DDS_M_MAX
                      (VSCtl_tiFilDrvOvrdVSReg - 1, 0);
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE
        = (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_ARRET;
      VSCtl_bSpdVehDrvOvrdVSReg = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_h;
      VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F212313_Determiner_Condition_Reprise_Vitesse*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F21236_Determiner_Condition_Inhibition_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.110.0  */

  if (vsreg_det_cond_fct_veh_sf_dwork.is_active_c73_VSREG_Det_Cond_Fct_Veh_Sf ==
      0)
  {
    vsreg_det_cond_fct_veh_sf_dwork.is_active_c73_VSREG_Det_Cond_Fct_Veh_Sf = 1U;
    vsreg_det_cond_fct_veh_sf_dwork.is_c73_VSREG_Det_Cond_Fct_Veh_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDE_INHIBITION_VEHICULE;
    vsreg_det_cond_fct_veh_sf_dwork.is_DEMANDE_INHIBITION_VEHICULE = (UInt8)
      VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE_p;
    VSCtl_bInhVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m;

  }
  else
  {
    switch (vsreg_det_cond_fct_veh_sf_dwork.is_DEMANDE_INHIBITION_VEHICULE)
              {
     case VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE_p:
      if (((((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
             (VSCtl_bFastDeacVSRegReq_Veh == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k1))

            && (VSCtl_bSpdVehMaxVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k1))
            &&
           (VSCtl_bSpdVehMinVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k1))
           &&
          (VSCtl_bSpdVehDrvOvrdVSReg == VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k1))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_DEMANDE_INHIBITION_VEHICULE =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_PAS_DEMANDEE_k;
        VSCtl_bInhVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_FAUX_k1;
      }
      break;

     case VSREG_Det_Cond_Fct_Veh_Sf_IN_PAS_DEMANDEE_k:
      if (((((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
             (VSCtl_bFastDeacVSRegReq_Veh == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m))
             ||
            (VSCtl_bSpdVehMaxVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m))
            ||
           (VSCtl_bSpdVehMinVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m))
           ||
          (VSCtl_bSpdVehDrvOvrdVSReg == VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m))
      {
        vsreg_det_cond_fct_veh_sf_dwork.is_DEMANDE_INHIBITION_VEHICULE =
          (UInt8)VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE_p;
        VSCtl_bInhVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m;
      }
      break;

     default:
      vsreg_det_cond_fct_veh_sf_dwork.is_DEMANDE_INHIBITION_VEHICULE = (UInt8)
        VSREG_Det_Cond_Fct_Veh_Sf_IN_DEMANDEE_p;
      VSCtl_bInhVSRegReq_Veh = VSREG_Det_Cond_Fct_Veh_Sf_VRAI_m;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21236_Determiner_Condition_Inhibition_Vehicule*/

  VSREG_F21234_Determiner_Condition_Conditions_Maintenance_Vehicule();

  /* TAG_END_OF_MAIN_FUNCTION */
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Veh_Sf_Init(void)
{
     SInt16 vsctl_avehvsregreq_deacvsreg_swc_out; /* BIN10 */
     SInt16 vsctl_aveh_deacvsreg_swc_out; /* bin10 */
     UInt8  vsctl_bdgovsregbody_swc_out;
     UInt8  vsctl_bmonrunvsregbody_swc_out;
     UInt32 vsctl_dstvehtotmes_deacvsreg_swc_out; /* BIN0 */
     SInt16 vsctl_jrkvehreqdeacvsreg_swc_out; /* BIN7 */
     SInt16 vsctl_jrkveh_deacvsreg_swc_out; /* bIN7 */
     SInt8  vsctl_nogearegd_deacvsreg_swc_out;
     UInt8  vsctl_posngbxdeacvsreg_swc_out;
     UInt16 vsctl_raccp_deacvsreg_swc_out; /* biN7 */
     SInt16 vsctl_rslop_deacvsreg_swc_out; /* biN7 */
     UInt8  vsctl_spdvehreqdeacvsreg_swc_out; /* BIN0 */
     UInt16 vsctl_spdveh_deacvsreg_swc_out; /* bIN7 */
     UInt32 vsctl_stdeacvsregreqhi_no1_swc_out; /* BIN0 */
     UInt32 vsctl_stdeacvsregreqhi_no2_swc_out; /* BIN0 */
     UInt32 vsctl_stdeacvsregreqlo_no1_swc_out; /* BIN0 */
     UInt32 vsctl_stdeacvsregreqlo_no2_swc_out; /* BIN0 */
     UInt8  vsctl_stvsregprev_deacvsreg_swc_out;
     UInt8  vsctl_stvsreg_deacvsreg_swc_out;

    VSREG_Veh_Running_Cond_Sl_Init(
              &vsctl_avehvsregreq_deacvsreg_swc_out, /* BIN10 */
              &vsctl_aveh_deacvsreg_swc_out, /* bin10 */
              &vsctl_bdgovsregbody_swc_out,
              &vsctl_bmonrunvsregbody_swc_out,
              &vsctl_dstvehtotmes_deacvsreg_swc_out, /* BIN0 */
              &vsctl_jrkvehreqdeacvsreg_swc_out, /* biN7 */
              &vsctl_jrkveh_deacvsreg_swc_out, /* bin7 */
              &vsctl_nogearegd_deacvsreg_swc_out,
              &vsctl_posngbxdeacvsreg_swc_out,
              &vsctl_raccp_deacvsreg_swc_out, /* bin7 */
              &vsctl_rslop_deacvsreg_swc_out, /* bin7 */
              &vsctl_spdvehreqdeacvsreg_swc_out, /* biN0 */
              &vsctl_spdveh_deacvsreg_swc_out, /* bin7 */
              &vsctl_stdeacvsregreqhi_no1_swc_out, /* BIN0 */
              &vsctl_stdeacvsregreqhi_no2_swc_out, /* BIN0 */
              &vsctl_stdeacvsregreqlo_no1_swc_out, /* BIN0 */
              &vsctl_stdeacvsregreqlo_no2_swc_out, /* BIN0 */
              &vsctl_stvsregprev_deacvsreg_swc_out,
              &vsctl_stvsreg_deacvsreg_swc_out);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  vsreg_det_cond_fct_veh_sf_dwork.is_active_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE=0;
  VSCtl_aVehDeceRefVSReg=0;
  VSCtl_aVehAccRefVSReg=0;
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  VSCtl_tiFilDrvOvrdVSReg = VSCtl_tiTol_bDrvOvrdVSReg_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiFilMonAVehVSReg = VSCtl_tiAcv_MonVSReg_C; /* Replaced by Post task */     /* Init from Model */


  vsreg_det_cond_fct_veh_sf_dwork.is_active_ACTIVATION = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_ACTIVATION = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_i = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_MEMOIRES = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c61_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c61_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bAcvMonAVehVSReg =DDS_FALSE;
  VSCtl_bCtlaTqPTPrevVSReg =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MAX = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_c = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c62_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c62_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bAccVehMaxVSReg =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION_MIN = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_k = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c63_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c63_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bAccVehMinVSReg =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_DECELERATION = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_h = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT_d = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c68_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c68_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bDeceVehVSReg =DDS_FALSE;
  vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehDeceRefVSReg_i = 0;



  vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ACCELERATION = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_NON_INIT = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c69_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c69_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bAccVehVSReg =DDS_FALSE;
  vsreg_det_cond_fct_veh_sf_b.VSCtl_aVehAccRefVSReg_b = 0;



  vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_ALERTE_CHOC_VEHICULE = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c71_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c71_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bVehCollWarnVSReg =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_DESACTIVATION_RAPIDE_VEHICULE = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c72_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c72_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bFastDeacVSRegReq_Veh =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MAX = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c58_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c58_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bSpdVehMaxVSReg =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_CONDITION_VITESSE_VEHICULE_MIN = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c59_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c59_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bSpdVehMinVSReg =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_active_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE
    = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_CALCUL_CONDITION_REPRISE_VITESSE_VEHICULE =
    0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_MARCHE_f = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_REPRISE_SURVITESSE1 = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c60_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c60_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bSpdVehDrvOvrdVSReg =DDS_FALSE;



  vsreg_det_cond_fct_veh_sf_dwork.is_DEMANDE_INHIBITION_VEHICULE = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_active_c73_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  vsreg_det_cond_fct_veh_sf_dwork.is_c73_VSREG_Det_Cond_Fct_Veh_Sf = 0U;
  VSCtl_bInhVSRegReq_Veh =DDS_FALSE;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

