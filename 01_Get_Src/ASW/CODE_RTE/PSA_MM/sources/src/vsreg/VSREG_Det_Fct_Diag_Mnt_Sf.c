/*
* File: VSREG_Det_Fct_Diag_Mnt_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSREG_Det_Fct_Diag_Mnt_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Wed Nov 16 14:07:22 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Wed Nov 16 14:07:23 2011
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
*        AUT_EC_m_min_opt SFunction version: 3.0, TLC version: 3.0
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
*        element \ldcr_tools\... SWC_CHECK_CALIBRATION_2_00
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
*        element \blois_esoft\... \main\main_tcb\LATES
*        element \blois_esoft\... \main\0 -mkbranch main_tcb
*        element \ldcr_doc\... /main/LATEST
*        element doc\... \main\LATEST
*        element Doc\... \main\LATEST
*
* Block list with autocode bypass option activated:
*        No bypassed blocks into this model
*
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Det_Fct_Diag_Mnt_Sf.c
* Version int :/main/L02_01/1 Date: 5/1/2012 11 h 24 m User:esnault 
*    TWK_model:VSREG_Det_Fct_Diag_Mnt_Sf_L02_010_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_halouane_vsreg_euro6\1 Date: 4/1/2012 15 h 39 m User:halouane 
*    TWK_model:VSREG_Det_Fct_Diag_Mnt_Sf_L02_010_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 16/11/2011 15 h 20 m User:demezil
*    TWK_model:VSREG_Det_Fct_Diag_Mnt_Sf_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 16/11/2011 14 h 46 m User:demezil
*    TWK_model:VSREG_Det_Fct_Diag_Mnt_Sf_L02_010_IMPL1
*    comments :for VSReg 12.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_RVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_RVV ;Afts_bRst_stDeacVSRegReq1;Afts_bRst_stDeacVSRegReq2;VSCtl_bEnaDeacVSRegReq_no2;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_RVV ;VSCtl_bRec_stDeacVSRegReq;VSCtl_stRec_stDeacVSRegReq1;VSCtl_stRec_stDeacVSRegReq2;VSCtl_tiHld_stDeacVSRegReq1;VSCtl_tiHld_stDeacVSRegReq2; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Capture_Maintenance_RVV */

/* TAG_START_OF_STATEFLOW_FUNCTION: Diagnostic_Fonctionnel_Vehicule */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Diagnostic_Fonctionnel_Vehicule ;VSCtl_bAccVehMaxVSReg;VSCtl_bAccVehMinVSReg;VSCtl_bAccVehVSReg;VSCtl_bDeceVehVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Diagnostic_Fonctionnel_Vehicule ;VSCtl_bDgoVSRegVeh;VSCtl_bMonRunVSRegVeh; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Diagnostic_Fonctionnel_Vehicule */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_fonctionnement */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_fonctionnement ;Ext_stAcvRegVSCtlReq;Ext_stModRegVSCtlReq;VSCtl_bDrvOvrdVSReg_aVeh_no2;VSCtl_bDrvOvrdVSReg_spdVeh;VSCtl_bInhVSRegReq;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_fonctionnement ;VSCtl_stVSRegExtd; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_fonctionnement */

/* TAG_START_OF_SUB_FUNCTION: F2141_Determiner_Diagnostic_Fonctionnel_Habitacle */
/* TAG_INPUT_OF_SUB_FUNCTION: F2141_Determiner_Diagnostic_Fonctionnel_Habitacle ;Ext_spdVehVSRegReq;Ext_stAcvRegVSCtlReq;Ext_stModRegVSCtlReq;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2141_Determiner_Diagnostic_Fonctionnel_Habitacle ;VSCtl_bDeacVSRegHab;VSCtl_bDgoVSRegBody;VSCtl_bMonRunVSRegBody; */
/* TAG_END_OF_SUB_FUNCTION: F2141_Determiner_Diagnostic_Fonctionnel_Habitacle */

/* TAG_START_OF_SUB_FUNCTION: F2151_Determiner_Conditions_Maintenance_RVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F2151_Determiner_Conditions_Maintenance_RVV ;VSCtl_bDeacVSRegHab;VSCtl_bRec_stDeacVSRegReq;VSCtl_stDeacVSCtlInfo;VSCtl_stDeacVSRegReq_Brk;VSCtl_stDeacVSRegReq_Fct;VSCtl_stDeacVSRegReq_Ini;VSCtl_stDeacVSRegReq_Veh;VSCtl_stDeacVSRegReq_pt; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2151_Determiner_Conditions_Maintenance_RVV ;VSCtl_bEnaDeacVSRegReq_no2;VSCtl_stDeacVSRegReqHi_no1;VSCtl_stDeacVSRegReqHi_no2;VSCtl_stDeacVSRegReqLo_no1;VSCtl_stDeacVSRegReqLo_no2; */
/* TAG_END_OF_SUB_FUNCTION: F2151_Determiner_Conditions_Maintenance_RVV */

/* TAG_START_OF_SUB_FUNCTION: F2153_Determiner_Contexte_Maintenance_RVV */
/* TAG_INPUT_OF_SUB_FUNCTION: F2153_Determiner_Contexte_Maintenance_RVV ;AccP_rAccP;CoPt_noEgdGearCordIt;CoPt_posnLev;Ext_dstVehTotMes;Ext_spdVehVSRegReq;VSCtl_aVeh;VSCtl_aVehVSRegReq;VSCtl_bRec_stDeacVSRegReq;VSCtl_jrkVeh;VSCtl_jrkVehVSRegReq;VSCtl_rSlop;VSCtl_spdVeh;VSCtl_stVSRegExtd; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2153_Determiner_Contexte_Maintenance_RVV ;VSCtl_aVehVSRegReq_DeacVSReg;VSCtl_aVeh_DeacVSReg;VSCtl_dstVehTotMes_DeacVSReg;VSCtl_jrkVehReqDeacVSReg;VSCtl_jrkVeh_DeacVSReg;VSCtl_noGearEgd_DeacVSReg;VSCtl_posnGBxDeacVSReg;VSCtl_rAccP_DeacVSReg;VSCtl_rSlop_DeacVSReg;VSCtl_spdVehReqDeacVSReg;VSCtl_spdVeh_DeacVSReg;VSCtl_stVSRegPrev_DeacVSReg;VSCtl_stVSReg_DeacVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F2153_Determiner_Contexte_Maintenance_RVV */

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

#define EXT_STACVREGVSCTLREQ_REGUL_RVV_DEMANDEE (1)
#define EXT_STMODREGVSCTLREQ_RVV_SELECT         (1)
#define VSCTL_STREC_STDEACVSREGREQ1_ATTENTE     (0)
#define VSCTL_STREC_STDEACVSREGREQ1_CAPTURE     (1)
#define VSCTL_STREC_STDEACVSREGREQ1_RESET       (2)
#define VSCTL_STREC_STDEACVSREGREQ2_ATTENTE     (0)
#define VSCTL_STREC_STDEACVSREGREQ2_CAPTURE     (1)
#define VSCTL_STREC_STDEACVSREGREQ2_RESET       (2)
#define VSCTL_STVSREGEXTD_AE                    (5)
#define VSCTL_STVSREGEXTD_ANE                   (4)
#define VSCTL_STVSREGEXTD_ARRET                 (0)
#define VSCTL_STVSREGEXTD_ATTENTE               (3)
#define VSCTL_STVSREGEXTD_DEFAUT                (7)
#define VSCTL_STVSREGEXTD_INHIBEE               (2)
#define VSCTL_STVSREGEXTD_INITIALISATION        (1)
#define VSCTL_STVSREGEXTD_REPRISE               (6)

/* Named constants for block: /Etat_fonctionnement' */
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_EFFECTIVE (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_INHIBEE (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_NON_REPRISE (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_DEFAUT (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_DISPONIBLE (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ETAT_FONCTIONNEMENT (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_INITIALISATION (3)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTION_PRESENTE (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_REPRISE (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_NON_EFFECTIVE (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_VRAI (1U)
#define VSREG_Det_Fct_Diag_Mnt_Sf_FAUX (0U)

/* Named constants for block: /Condition_Capture_Maintenance_RVV' */
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD_d (0)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_CAPTURE (3)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_j (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_RESET (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_CONDITION_CAPTURE_MAINTENANCE_RVV (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_o (1U)
#define VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_p (0U)

/* Named constants for block: /Diagnostic_Fonctionnel_Vehicule' */
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD_f (0)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_DIAGNOSTIC_FONCTIONNEL_VEHICULE (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_VRAI (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_MARCHE (2)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_FAUX (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET_c (1)
#define VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n (1U)
#define VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a (0U)

/* Definition for custom storage class: Define */
#define VSREG_DET_FCT_DIAG_MNT_S_CONST_0 0


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bEnaDeacVSRegReq_no2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSReg_aVeh_no2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDeceVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAccVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAccVehMinVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAccVehMaxVSReg;
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
VAR(UInt8, AUTOMATIC) VSCtl_bRec_stDeacVSRegReq;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt8 vsr_Keep_Global_Data_From_Input;
} BlockIO_VSREG_Det_Fct_Diag_Mnt_Sf;


typedef struct {
  UInt32 is_CONDITION_CAPTURE_MAINTENANCE_RVV_no1 : 2;
  UInt32 is_FONCTIONNEMENT : 2;
  UInt32 is_CONDITION_CAPTURE_MAINTENANCE_RVV_no2 : 2;
  UInt32 is_FONCTIONNEMENT_h : 2;
  UInt32 is_DIAGNOSTIC_FONCTIONNEL_VEHICULE : 2;
  UInt32 is_MARCHE : 2;
  UInt32 is_NON_REPRISE : 2;
  UInt32 is_ACTIVE : 2;
  UInt32 is_DISPONIBLE : 2;
  UInt32 is_ETAT_FONCTIONNEMENT : 2;
  UInt32 is_INDISPONIBLE : 2;
  UInt32 is_FONCTION_PRESENTE : 2;
  UInt32 is_active_c84_VSREG_Det_Fct_Diag_Mnt_Sf : 1;
  UInt32 is_c84_VSREG_Det_Fct_Diag_Mnt_Sf : 1;
  UInt32 is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no1 : 1;
  UInt32 is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no2 : 1;
  UInt32 is_active_CONDITION_CAPTURE_MAINTENANCE_RVV : 1;
  UInt32 is_active_c83_VSREG_Det_Fct_Diag_Mnt_Sf : 1;
  UInt32 is_c83_VSREG_Det_Fct_Diag_Mnt_Sf : 1;
  UInt32 is_active_c80_VSREG_Det_Fct_Diag_Mnt_Sf : 1;
  UInt32 is_c80_VSREG_Det_Fct_Diag_Mnt_Sf : 1;
} D_Work_VSREG_Det_Fct_Diag_Mnt_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSRegReq1;            /*BIN0*/
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSRegReq2;            /*BIN0*/
/* Static Visible area end */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 32BIT-bits variable definition */
#define VSREG_START_SEC_VAR_32BIT
#include "VSReg_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsreg_vsctl_dstvehtotmes_deacvsreg_cpy;                  /*BIN0*/
STATIC VAR(UInt32, AUTOMATIC) vsreg_vsctl_stdeacvsregreqhi_no1_cpy;                    /*BIN0*/
STATIC VAR(UInt32, AUTOMATIC) vsreg_vsctl_stdeacvsregreqhi_no2_cpy;                    /*BIN0*/
STATIC VAR(UInt32, AUTOMATIC) vsreg_vsctl_stdeacvsregreqlo_no1_cpy;                    /*BIN0*/
STATIC VAR(UInt32, AUTOMATIC) vsreg_vsctl_stdeacvsregreqlo_no2_cpy;                    /*BIN0*/
#define VSREG_STOP_SEC_VAR_32BIT
#include "VSReg_MemMap.h"


/* 16BIT-bits variable definition */
#define VSREG_START_SEC_VAR_16BIT
#include "VSReg_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_avehvsregreq_deacvsreg_cpy;                  /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_aveh_deacvsreg_cpy;                          /*BIN10*/
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_jrkvehreqdeacvsreg_cpy;                      /*BIN7*/
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_jrkveh_deacvsreg_cpy;                        /*BIN7*/
STATIC VAR(SInt16, AUTOMATIC) vsreg_vsctl_rslop_deacvsreg_cpy;                         /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsreg_vsctl_raccp_deacvsreg_cpy;                         /*BIN7*/
STATIC VAR(UInt16, AUTOMATIC) vsreg_vsctl_spdveh_deacvsreg_cpy;                        /*BIN7*/
#define VSREG_STOP_SEC_VAR_16BIT
#include "VSReg_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSREG_START_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"
STATIC VAR(D_Work_VSREG_Det_Fct_Diag_Mnt_Sf, AUTOMATIC) vsreg_det_fct_diag_mnt_sf_dwork;
#define VSREG_STOP_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"


/* 8BIT-bits variable definition */
#define VSREG_START_SEC_VAR_8BIT
#include "VSReg_MemMap.h"
/* Static Not Visible area end */
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_spdvehreqdeacvsreg_cpy;                       /*BIN0*/
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_bdgovsregbody_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_bdgovsregveh_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_bmonrunvsregbody_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_bmonrunvsregveh_cpy;
STATIC VAR(SInt8, AUTOMATIC) vsreg_vsctl_nogearegd_deacvsreg_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_posngbxdeacvsreg_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_strec_stdeacvsregreq1_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_strec_stdeacvsregreq2_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_stvsregextd_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_stvsregprev_deacvsreg_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_stvsreg_deacvsreg_cpy;
#define VSREG_STOP_SEC_VAR_8BIT
#include "VSReg_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 16BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSRegReq1_C = (CONST(UInt16, AUTOMATIC))(0U); /*BIN0*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSRegReq2_C = (CONST(UInt16, AUTOMATIC))(0U); /*BIN0*/
/* \<AUT_POST> : Task Memory Ordering */
#define VSREG_STOP_SEC_CALIB_16BIT
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

FUNC(void, AUTOMATIC) VSREG_Det_Fct_Diag_Mnt_Sf(UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                               UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                          /*BIN0*/
                               UInt8 Ext_stModRegVSCtlReq_swc_in,
                               UInt8 Ext_spdVehVSRegReq_swc_in,                            /*BIN0*/
                               SInt16 VSCtl_aVeh_swc_in,                                   /*BIN10*/
                               SInt16 VSCtl_jrkVeh_swc_in,                                 /*BIN7*/
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 VSCtl_stDeacVSCtlInfo_swc_in,
                               UInt32 Ext_dstVehTotMes_swc_in,                             /*BIN0*/
                               SInt16 VSCtl_rSlop_swc_in,                                  /*BIN7*/
                               UInt8 Afts_bRst_stDeacVSRegReq1_swc_in,
                               UInt8 Afts_bRst_stDeacVSRegReq2_swc_in,
                               UInt8 CoPt_posnLev_swc_in,
                               SInt16 VSCtl_aVehVSRegReq_swc_in,                           /*BIN10*/
                               UInt16 AccP_rAccP_swc_in,                                   /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSReg_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSReg_swc_out,                 /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegBody_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSReg_swc_out,                      /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSReg_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_DeacVSReg_swc_out,                 /*BIN10*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSReg_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSReg_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegBody_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no2_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegVeh_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq1_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no2_swc_out)                   /*BIN0*/
{

  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F213_Determiner_Etat_Fonctionnement*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.52.3  */

  if (vsreg_det_fct_diag_mnt_sf_dwork.is_active_c80_VSREG_Det_Fct_Diag_Mnt_Sf ==
      0)
  {
    vsreg_det_fct_diag_mnt_sf_dwork.is_active_c80_VSREG_Det_Fct_Diag_Mnt_Sf = 1U;
    vsreg_det_fct_diag_mnt_sf_dwork.is_c80_VSREG_Det_Fct_Diag_Mnt_Sf = (UInt8)
      VSREG_Det_Fct_Diag_Mnt_Sf_IN_ETAT_FONCTIONNEMENT;
    vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
      VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE;
    vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
      VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET;
    vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_ARRET;

  }
  else
  {
    switch (vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT) {
     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_DISPONIBLE:
      if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_ARRET)
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET;
        vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_ARRET;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_INIT) ||
                 (VSCtl_stMonVSReg == VSCTL_STMONVSREG_VERIF))
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTION_PRESENTE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_INITIALISATION;
        vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_INITIALISATION;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
                 (VSCtl_bInhVSRegReq == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI))
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTION_PRESENTE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_INHIBEE;
        vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_INHIBEE;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_DEFAUT_REV) ||
                 (VSCtl_stMonVSReg == VSCTL_STMONVSREG_DEFAUT_IRREV))
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTION_PRESENTE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_DEFAUT;
        vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_DEFAUT;

      }
      else
      {
        switch (vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE) {
         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE:
          if ((Ext_stModRegVSCtlReq_swc_in != EXT_STMODREGVSCTLREQ_RVV_SELECT)
          ||
              (Ext_stAcvRegVSCtlReq_swc_in != EXT_STACVREGVSCTLREQ_REGUL_RVV_DEMANDEE))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE;
            vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_ATTENTE;

          }
          else
          {
            switch (vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE) {
             case VSREG_Det_Fct_Diag_Mnt_Sf_IN_NON_REPRISE:
              if (VSCtl_bDrvOvrdVSReg_spdVeh_swc_in == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI)
              {
                vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
                  VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
                vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
                  VSREG_Det_Fct_Diag_Mnt_Sf_IN_REPRISE;
                vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_REPRISE;

              }
              else
              {
                switch (vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE) {
                 case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_EFFECTIVE:
                  if (VSCtl_bDrvOvrdVSReg_aVeh_no2 ==
                      VSREG_Det_Fct_Diag_Mnt_Sf_VRAI)
                  {
                    vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
                      VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_NON_EFFECTIVE;
                    vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_ANE;
                  }
                  break;

                 case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_NON_EFFECTIVE:
                  if (VSCtl_bDrvOvrdVSReg_aVeh_no2 ==
                      VSREG_Det_Fct_Diag_Mnt_Sf_FAUX)
                  {
                    vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
                      VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_EFFECTIVE;
                    vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_AE;
                  }
                  break;
                }
              }
              break;

             case VSREG_Det_Fct_Diag_Mnt_Sf_IN_REPRISE:
              if (VSCtl_bDrvOvrdVSReg_spdVeh_swc_in == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX)
              {
                vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
                  VSREG_Det_Fct_Diag_Mnt_Sf_IN_NON_REPRISE;
                vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
                  VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_EFFECTIVE;
                vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_AE;
              }
              break;
            }
          }
          break;

         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE:
          if ((Ext_stModRegVSCtlReq_swc_in == EXT_STMODREGVSCTLREQ_RVV_SELECT)
          &&
              (Ext_stAcvRegVSCtlReq_swc_in == EXT_STACVREGVSCTLREQ_REGUL_RVV_DEMANDEE))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE;
            vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_NON_REPRISE;
            vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_ACTIVE_EFFECTIVE;
            vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_AE;
          }
          break;
        }
      }
      break;

     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE:
      switch (vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE)
          {
       case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET:
        if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_ARRET)
        {
          vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
            VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTION_PRESENTE;
          vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
            VSREG_Det_Fct_Diag_Mnt_Sf_IN_INITIALISATION;
          vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_INITIALISATION;
        }
        break;

       case VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTION_PRESENTE:
        if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_ARRET)
        {
          vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
            VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
          vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
            VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET;
          vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_ARRET;

        }
        else
        {
          switch (vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE)
        {
           case VSREG_Det_Fct_Diag_Mnt_Sf_IN_DEFAUT:
            if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
            {
              vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_INHIBEE;
              vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_INHIBEE;
            }
            break;

           case VSREG_Det_Fct_Diag_Mnt_Sf_IN_INHIBEE:
            if (((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
                 (Ext_stAcvRegVSCtlReq_swc_in !=
                  EXT_STACVREGVSCTLREQ_REGUL_RVV_DEMANDEE)) &&
                (VSCtl_bInhVSRegReq == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX))
            {
              vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
              vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD;
              vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_DISPONIBLE;
              vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE;
              vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_ATTENTE;

            }
            else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_DEFAUT_REV)
            ||
                       (VSCtl_stMonVSReg == VSCTL_STMONVSREG_DEFAUT_IRREV))
            {
              vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_DEFAUT;
              vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_DEFAUT;
            }
            break;

           case VSREG_Det_Fct_Diag_Mnt_Sf_IN_INITIALISATION:
            if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_DEFAUT_REV) ||
                (VSCtl_stMonVSReg == VSCTL_STMONVSREG_DEFAUT_IRREV))
            {
              vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_DEFAUT;
              vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_DEFAUT;

            }
            else if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
            {
              vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = (UInt8)
                VSREG_Det_Fct_Diag_Mnt_Sf_IN_INHIBEE;
              vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_INHIBEE;
            }
            break;
          }
        }
        break;
      }
      break;

     default:
      vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = (UInt8)
        VSREG_Det_Fct_Diag_Mnt_Sf_IN_INDISPONIBLE;
      vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = (UInt8)
        VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET;
      vsreg_vsctl_stvsregextd_cpy = VSCTL_STVSREGEXTD_ARRET;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F213_Determiner_Etat_Fonctionnement*/

    VSREG_F2141_Determiner_Diagnostic_Fonctionnel_Habitacle(Ext_spdVehVSRegReq_swc_in,
                                                        Ext_stAcvRegVSCtlReq_swc_in,
                                                        Ext_stModRegVSCtlReq_swc_in,
                                                        &vsreg_vsctl_bdgovsregbody_cpy,
                                                        &vsreg_vsctl_bmonrunvsregbody_cpy);

    VSREG_F2151_Determiner_Conditions_Maintenance_Rvv(VSCtl_stDeacVSCtlInfo_swc_in,
                                             &vsreg_vsctl_stdeacvsregreqhi_no1_cpy, /* BIN0 */
                                             &vsreg_vsctl_stdeacvsregreqhi_no2_cpy, /* BIN0 */
                                             &vsreg_vsctl_stdeacvsregreqlo_no1_cpy, /* BIN0 */
                                             &vsreg_vsctl_stdeacvsregreqlo_no2_cpy /* BIN0 */);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F2152_Determiner_Conditions_Capture_Maintenance_RVV*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.121.0  */

  if (vsreg_det_fct_diag_mnt_sf_dwork.is_active_c84_VSREG_Det_Fct_Diag_Mnt_Sf ==
      0)
  {
    vsreg_det_fct_diag_mnt_sf_dwork.is_active_c84_VSREG_Det_Fct_Diag_Mnt_Sf = 1U;
    vsreg_det_fct_diag_mnt_sf_dwork.is_c84_VSREG_Det_Fct_Diag_Mnt_Sf = (UInt8)
      VSREG_Det_Fct_Diag_Mnt_Sf_IN_CONDITION_CAPTURE_MAINTENANCE_RVV;
    vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no1
      = 1U;
    vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no1 =
      (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT;
    vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = (UInt8)
      VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
    vsreg_strec_stdeacvsregreq1_cpy = VSCTL_STREC_STDEACVSREGREQ1_ATTENTE;
    VSCtl_tiHld_stDeacVSRegReq1 = VSCtl_tiHld_stDeacVSRegReq1_C;
    vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no2
      = 1U;
    vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no2 =
      (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT;
    vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = (UInt8)
      VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
    vsreg_strec_stdeacvsregreq2_cpy = VSCTL_STREC_STDEACVSREGREQ2_ATTENTE;
    VSCtl_tiHld_stDeacVSRegReq2 = VSCtl_tiHld_stDeacVSRegReq2_C;
    vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV =
      1U;

  }
  else
  {
    switch
      (vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no1)
    {
     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT:
      if (Afts_bRst_stDeacVSRegReq1_swc_in == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_o)
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD_d;
        vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no1
          = (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_RESET;
        vsreg_strec_stdeacvsregreq1_cpy = VSCTL_STREC_STDEACVSREGREQ1_RESET;

      }
      else
      {
        switch (vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT)
            {
         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_j:
          if ((((vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_INHIBEE) ||
                (vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_DEFAUT)) ||
               (vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_ARRET)) ||
              (vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_INITIALISATION))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_CAPTURE;
            vsreg_strec_stdeacvsregreq1_cpy = VSCTL_STREC_STDEACVSREGREQ1_CAPTURE;
          }
          break;

         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION:
          if (((vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_AE)
          || (vsreg_vsctl_stvsregextd_cpy
                == VSCTL_STVSREGEXTD_ANE)) || (vsreg_vsctl_stvsregextd_cpy ==
               VSCTL_STVSREGEXTD_REPRISE))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_j;
            vsreg_strec_stdeacvsregreq1_cpy = VSCTL_STREC_STDEACVSREGREQ1_ATTENTE;
          }
          break;

         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_CAPTURE:
          if (VSCtl_tiHld_stDeacVSRegReq1 == 0)
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
            vsreg_strec_stdeacvsregreq1_cpy = VSCTL_STREC_STDEACVSREGREQ1_ATTENTE;
            VSCtl_tiHld_stDeacVSRegReq1 = VSCtl_tiHld_stDeacVSRegReq1_C;

          }
          else
          {
            VSCtl_tiHld_stDeacVSRegReq1 = (UInt16)DDS_M_MAX
              (VSCtl_tiHld_stDeacVSRegReq1 - 1, 0);
          }
          break;
        }
      }
      break;

     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_RESET:
      if (Afts_bRst_stDeacVSRegReq1_swc_in == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_p)
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no1
          = (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT;
        vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
        vsreg_strec_stdeacvsregreq1_cpy = VSCTL_STREC_STDEACVSREGREQ1_ATTENTE;
        VSCtl_tiHld_stDeacVSRegReq1 = VSCtl_tiHld_stDeacVSRegReq1_C;
      }
      break;

     default:
      vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no1 =
        (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT;
      vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = (UInt8)
        VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
      vsreg_strec_stdeacvsregreq1_cpy = VSCTL_STREC_STDEACVSREGREQ1_ATTENTE;
      VSCtl_tiHld_stDeacVSRegReq1 = VSCtl_tiHld_stDeacVSRegReq1_C;
      break;
    }

    switch
      (vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no2)
    {
     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT:
      if (Afts_bRst_stDeacVSRegReq2_swc_in == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_o)
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD_d;
        vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no2
          = (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_RESET;
        vsreg_strec_stdeacvsregreq2_cpy = VSCTL_STREC_STDEACVSREGREQ2_RESET;

      }
      else
      {
        switch (vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h)
      {
         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_j:
          if (((((vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_INHIBEE) ||
                 (vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_DEFAUT)) ||
                (vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_ARRET)) ||
               (vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_INITIALISATION))
               &&
              (VSCtl_bEnaDeacVSRegReq_no2 == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_o))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_CAPTURE;
            vsreg_strec_stdeacvsregreq2_cpy = VSCTL_STREC_STDEACVSREGREQ2_CAPTURE;
          }
          break;

         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION:
          if (((vsreg_vsctl_stvsregextd_cpy == VSCTL_STVSREGEXTD_AE)
          || (vsreg_vsctl_stvsregextd_cpy
                == VSCTL_STVSREGEXTD_ANE)) || (vsreg_vsctl_stvsregextd_cpy ==
               VSCTL_STVSREGEXTD_REPRISE))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_j;
            vsreg_strec_stdeacvsregreq2_cpy = VSCTL_STREC_STDEACVSREGREQ2_ATTENTE;
          }
          break;

         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_CAPTURE:
          if (VSCtl_tiHld_stDeacVSRegReq2 == 0)
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
            vsreg_strec_stdeacvsregreq2_cpy = VSCTL_STREC_STDEACVSREGREQ2_ATTENTE;
            VSCtl_tiHld_stDeacVSRegReq2 = VSCtl_tiHld_stDeacVSRegReq2_C;

          }
          else
          {
            VSCtl_tiHld_stDeacVSRegReq2 = (UInt16)DDS_M_MAX
              (VSCtl_tiHld_stDeacVSRegReq2 - 1, 0);
          }
          break;
        }
      }
      break;

     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_RESET:
      if (Afts_bRst_stDeacVSRegReq2_swc_in == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_p)
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no2
          = (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT;
        vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
        vsreg_strec_stdeacvsregreq2_cpy = VSCTL_STREC_STDEACVSREGREQ2_ATTENTE;
        VSCtl_tiHld_stDeacVSRegReq2 = VSCtl_tiHld_stDeacVSRegReq2_C;
      }
      break;

     default:
      vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no2 =
        (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_FONCTIONNEMENT;
      vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = (UInt8)
        VSREG_Det_Fct_Diag_Mnt_Sf_IN_ATTENTE_ACTIVATION;
      vsreg_strec_stdeacvsregreq2_cpy = VSCTL_STREC_STDEACVSREGREQ2_ATTENTE;
      VSCtl_tiHld_stDeacVSRegReq2 = VSCtl_tiHld_stDeacVSRegReq2_C;
      break;
    }

    VSCtl_bRec_stDeacVSRegReq = (vsreg_strec_stdeacvsregreq1_cpy ==
      VSCTL_STREC_STDEACVSREGREQ1_CAPTURE)
      || (vsreg_strec_stdeacvsregreq2_cpy ==
      VSCTL_STREC_STDEACVSREGREQ2_CAPTURE)?DDS_TRUE:DDS_FALSE;
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2152_Determiner_Conditions_Capture_Maintenance_RVV*/

  VSREG_F2153_Determiner_Contexte_Maintenance_Rvv(
                                             AccP_rAccP_swc_in, /* BIN7 */
                                             Ext_dstVehTotMes_swc_in, /* BIN0 */
                                             CoPt_noEgdGearCordIt_swc_in,
                                             CoPt_posnLev_swc_in,
                                             Ext_spdVehVSRegReq_swc_in, /* BIN0 */
                                             VSCtl_aVehVSRegReq_swc_in, /* BIN10 */
                                             VSCtl_aVeh_swc_in, /* BIN10 */
                                             VSCtl_jrkVeh_swc_in, /* BIN7 */
                                             VSCtl_rSlop_swc_in, /* BIN7 */
                                             VSCtl_spdVeh_swc_in, /* BIN7 */
                                             vsreg_vsctl_stvsregextd_cpy,
                                             &vsreg_vsctl_avehvsregreq_deacvsreg_cpy, /* bin10 */
                                             &vsreg_vsctl_aveh_deacvsreg_cpy, /* bin10 */
                                             &vsreg_vsctl_dstvehtotmes_deacvsreg_cpy, /* bin0 */
                                             &vsreg_vsctl_jrkvehreqdeacvsreg_cpy, /* bin7 */
                                             &vsreg_vsctl_jrkveh_deacvsreg_cpy, /* bin7 */
                                             &vsreg_vsctl_nogearegd_deacvsreg_cpy,
                                             &vsreg_vsctl_posngbxdeacvsreg_cpy,
                                             &vsreg_vsctl_raccp_deacvsreg_cpy, /* bin7 */
                                             &vsreg_vsctl_rslop_deacvsreg_cpy, /* bin7 */
                                             &vsreg_vsctl_spdvehreqdeacvsreg_cpy, /* bin0 */
                                             &vsreg_vsctl_spdveh_deacvsreg_cpy, /* bin7 */
                                             &vsreg_vsctl_stvsregprev_deacvsreg_cpy,
                                             &vsreg_vsctl_stvsreg_deacvsreg_cpy);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F2142_Determiner_Diagnostic_Fonctionnel_Vehicule*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.118.0  */

  if (vsreg_det_fct_diag_mnt_sf_dwork.is_active_c83_VSREG_Det_Fct_Diag_Mnt_Sf ==
      0)
  {
    vsreg_det_fct_diag_mnt_sf_dwork.is_active_c83_VSREG_Det_Fct_Diag_Mnt_Sf = 1U;
    vsreg_det_fct_diag_mnt_sf_dwork.is_c83_VSREG_Det_Fct_Diag_Mnt_Sf = (UInt8)
      VSREG_Det_Fct_Diag_Mnt_Sf_IN_DIAGNOSTIC_FONCTIONNEL_VEHICULE;
    vsreg_det_fct_diag_mnt_sf_dwork.is_DIAGNOSTIC_FONCTIONNEL_VEHICULE =
      (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET_c;
    vsreg_vsctl_bmonrunvsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;
    vsreg_vsctl_bdgovsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;

  }
  else
  {
    switch (vsreg_det_fct_diag_mnt_sf_dwork.is_DIAGNOSTIC_FONCTIONNEL_VEHICULE)
    {
     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET_c:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_ARRET)
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_DIAGNOSTIC_FONCTIONNEL_VEHICULE =
          (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_MARCHE;
        vsreg_det_fct_diag_mnt_sf_dwork.is_MARCHE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_FAUX;
        vsreg_vsctl_bmonrunvsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n;
        vsreg_vsctl_bdgovsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;
      }
      break;

     case VSREG_Det_Fct_Diag_Mnt_Sf_IN_MARCHE:
      if (VSCtl_stMonVSReg == VSCTL_STMONVSREG_ARRET)
      {
        vsreg_det_fct_diag_mnt_sf_dwork.is_MARCHE = (UInt8)
          VSREG_Det_Fct_Diag_Mnt_Sf_IN_NO_ACTIVE_CHILD_f;
        vsreg_det_fct_diag_mnt_sf_dwork.is_DIAGNOSTIC_FONCTIONNEL_VEHICULE =
          (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET_c;
        vsreg_vsctl_bmonrunvsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;
        vsreg_vsctl_bdgovsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;

      }
      else
      {
        switch (vsreg_det_fct_diag_mnt_sf_dwork.is_MARCHE)
      {
         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_FAUX:
          if ((((VSCtl_bAccVehMaxVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n)
          ||
                (VSCtl_bAccVehMinVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n))
                ||
               (VSCtl_bDeceVehVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n))
               ||
              (VSCtl_bAccVehVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_VRAI;
            vsreg_vsctl_bmonrunvsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n;
            vsreg_vsctl_bdgovsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n;
          }
          break;

         case VSREG_Det_Fct_Diag_Mnt_Sf_IN_VRAI:
          if ((((VSCtl_bAccVehMaxVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a)
          &&
                (VSCtl_bAccVehMinVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a))
                &&
               (VSCtl_bDeceVehVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a))
               &&
              (VSCtl_bAccVehVSReg == VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a))
          {
            vsreg_det_fct_diag_mnt_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Fct_Diag_Mnt_Sf_IN_FAUX;
            vsreg_vsctl_bmonrunvsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_VRAI_n;
            vsreg_vsctl_bdgovsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_fct_diag_mnt_sf_dwork.is_DIAGNOSTIC_FONCTIONNEL_VEHICULE =
        (UInt8)VSREG_Det_Fct_Diag_Mnt_Sf_IN_ARRET_c;
      vsreg_vsctl_bmonrunvsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;
      vsreg_vsctl_bdgovsregveh_cpy = VSREG_Det_Fct_Diag_Mnt_Sf_FAUX_a;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2142_Determiner_Diagnostic_Fonctionnel_Vehicule*/


  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_dstVehTotMes_DeacVSReg_swc_out = vsreg_vsctl_dstvehtotmes_deacvsreg_cpy;

  *VSCtl_stDeacVSRegReqHi_no1_swc_out = vsreg_vsctl_stdeacvsregreqhi_no1_cpy;

  *VSCtl_stDeacVSRegReqHi_no2_swc_out = vsreg_vsctl_stdeacvsregreqhi_no2_cpy;

  *VSCtl_stDeacVSRegReqLo_no1_swc_out = vsreg_vsctl_stdeacvsregreqlo_no1_cpy;

  *VSCtl_stDeacVSRegReqLo_no2_swc_out = vsreg_vsctl_stdeacvsregreqlo_no2_cpy;

  *VSCtl_aVehVSRegReq_DeacVSReg_swc_out = vsreg_vsctl_avehvsregreq_deacvsreg_cpy;

  *VSCtl_aVeh_DeacVSReg_swc_out = vsreg_vsctl_aveh_deacvsreg_cpy;

  *VSCtl_jrkVehReqDeacVSReg_swc_out = vsreg_vsctl_jrkvehreqdeacvsreg_cpy;

  *VSCtl_jrkVeh_DeacVSReg_swc_out = vsreg_vsctl_jrkveh_deacvsreg_cpy;

  *VSCtl_rSlop_DeacVSReg_swc_out = vsreg_vsctl_rslop_deacvsreg_cpy;

  *VSCtl_rAccP_DeacVSReg_swc_out = vsreg_vsctl_raccp_deacvsreg_cpy;

  *VSCtl_spdVeh_DeacVSReg_swc_out = vsreg_vsctl_spdveh_deacvsreg_cpy;

  *VSCtl_spdVehReqDeacVSReg_swc_out = vsreg_vsctl_spdvehreqdeacvsreg_cpy;

  *VSCtl_bDgoVSRegBody_swc_out = vsreg_vsctl_bdgovsregbody_cpy;

  *VSCtl_bDgoVSRegVeh_swc_out = vsreg_vsctl_bdgovsregveh_cpy;

  *VSCtl_bMonRunVSRegBody_swc_out = vsreg_vsctl_bmonrunvsregbody_cpy;

  *VSCtl_bMonRunVSRegVeh_swc_out = vsreg_vsctl_bmonrunvsregveh_cpy;

  *VSCtl_noGearEgd_DeacVSReg_swc_out = vsreg_vsctl_nogearegd_deacvsreg_cpy;

  *VSCtl_posnGBxDeacVSReg_swc_out = vsreg_vsctl_posngbxdeacvsreg_cpy;

  *VSCtl_stRec_stDeacVSRegReq1_swc_out = vsreg_strec_stdeacvsregreq1_cpy;

  *VSCtl_stRec_stDeacVSRegReq2_swc_out = vsreg_strec_stdeacvsregreq2_cpy;

  *VSCtl_stVSRegExtd_swc_out = vsreg_vsctl_stvsregextd_cpy;

  *VSCtl_stVSRegPrev_DeacVSReg_swc_out = vsreg_vsctl_stvsregprev_deacvsreg_cpy;

  *VSCtl_stVSReg_DeacVSReg_swc_out = vsreg_vsctl_stvsreg_deacvsreg_cpy;

}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSREG_Det_Fct_Diag_Mnt_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSReg_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSReg_swc_out,                 /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegBody_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSReg_swc_out,                      /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSReg_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_DeacVSReg_swc_out,                 /*BIN10*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSReg_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSReg_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegBody_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no2_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegVeh_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq1_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no2_swc_out)                   /*BIN0*/
{
    VSREG_Veh_Running_Cond_Sl_Init(
                                VSCtl_aVehVSRegReq_DeacVSReg_swc_out, /* BIN10 */
                                VSCtl_aVeh_DeacVSReg_swc_out, /* BIN10 */
                                VSCtl_bDgoVSRegBody_swc_out,
                                VSCtl_bMonRunVSRegBody_swc_out,
                                VSCtl_dstVehTotMes_DeacVSReg_swc_out, /* BIN0 */
                                VSCtl_jrkVehReqDeacVSReg_swc_out, /* BIN7 */
                                VSCtl_jrkVeh_DeacVSReg_swc_out, /* BIN7 */
                                VSCtl_noGearEgd_DeacVSReg_swc_out,
                                VSCtl_posnGBxDeacVSReg_swc_out,
                                VSCtl_rAccP_DeacVSReg_swc_out, /* BIN7 */
                                VSCtl_rSlop_DeacVSReg_swc_out, /* BIN7 */
                                VSCtl_spdVehReqDeacVSReg_swc_out, /* BIN0 */
                                VSCtl_spdVeh_DeacVSReg_swc_out, /* BIN7 */
                                VSCtl_stDeacVSRegReqHi_no1_swc_out, /* BIN0 */
                                VSCtl_stDeacVSRegReqHi_no2_swc_out, /* BIN0 */
                                VSCtl_stDeacVSRegReqLo_no1_swc_out, /* BIN0 */
                                VSCtl_stDeacVSRegReqLo_no2_swc_out, /* BIN0 */
                                VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                                VSCtl_stVSReg_DeacVSReg_swc_out);

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  vsreg_vsctl_bmonrunvsregbody_cpy = *VSCtl_bMonRunVSRegBody_swc_out;

  vsreg_vsctl_aveh_deacvsreg_cpy = *VSCtl_aVeh_DeacVSReg_swc_out;

  vsreg_vsctl_dstvehtotmes_deacvsreg_cpy = *VSCtl_dstVehTotMes_DeacVSReg_swc_out;

  vsreg_vsctl_bdgovsregbody_cpy = *VSCtl_bDgoVSRegBody_swc_out;

  vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no1=0;
  vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no2=0;
  vsreg_vsctl_jrkveh_deacvsreg_cpy = *VSCtl_jrkVeh_DeacVSReg_swc_out;

  vsreg_vsctl_spdveh_deacvsreg_cpy = *VSCtl_spdVeh_DeacVSReg_swc_out;

  vsreg_vsctl_rslop_deacvsreg_cpy = *VSCtl_rSlop_DeacVSReg_swc_out;

  vsreg_vsctl_jrkvehreqdeacvsreg_cpy = *VSCtl_jrkVehReqDeacVSReg_swc_out;

  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */


  vsreg_vsctl_stdeacvsregreqlo_no1_cpy = *VSCtl_stDeacVSRegReqLo_no1_swc_out;

  vsreg_vsctl_stdeacvsregreqlo_no2_cpy = *VSCtl_stDeacVSRegReqLo_no2_swc_out;

  vsreg_vsctl_stdeacvsregreqhi_no1_cpy = *VSCtl_stDeacVSRegReqHi_no1_swc_out;

  vsreg_vsctl_stdeacvsregreqhi_no2_cpy = *VSCtl_stDeacVSRegReqHi_no2_swc_out;

  VSCtl_tiHld_stDeacVSRegReq1 = VSCtl_tiHld_stDeacVSRegReq1_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiHld_stDeacVSRegReq2 = VSCtl_tiHld_stDeacVSRegReq2_C;  /* Replaced by Post task */     /* Init from Model */
  vsreg_vsctl_raccp_deacvsreg_cpy = *VSCtl_rAccP_DeacVSReg_swc_out;

  vsreg_vsctl_avehvsregreq_deacvsreg_cpy = *VSCtl_aVehVSRegReq_DeacVSReg_swc_out;

  vsreg_vsctl_stvsreg_deacvsreg_cpy = *VSCtl_stVSReg_DeacVSReg_swc_out;

  vsreg_vsctl_stvsregprev_deacvsreg_cpy = *VSCtl_stVSRegPrev_DeacVSReg_swc_out;

  vsreg_vsctl_posngbxdeacvsreg_cpy = *VSCtl_posnGBxDeacVSReg_swc_out;

  vsreg_vsctl_spdvehreqdeacvsreg_cpy = *VSCtl_spdVehReqDeacVSReg_swc_out;

  vsreg_vsctl_nogearegd_deacvsreg_cpy = *VSCtl_noGearEgd_DeacVSReg_swc_out;

  *VSCtl_stRec_stDeacVSRegReq1_swc_out = VSCTL_STREC_STDEACVSREGREQ1_ATTENTE;   /* Replaced by Post task */     /* Init from Model */
  vsreg_strec_stdeacvsregreq1_cpy = *VSCtl_stRec_stDeacVSRegReq1_swc_out;

  *VSCtl_stRec_stDeacVSRegReq2_swc_out = VSCTL_STREC_STDEACVSREGREQ2_ATTENTE;   /* Replaced by Post task */     /* Init from Model */
  vsreg_strec_stdeacvsregreq2_cpy = *VSCtl_stRec_stDeacVSRegReq2_swc_out;

  *VSCtl_stVSRegExtd_swc_out = VSCTL_STVSREGEXTD_ARRET; /* Replaced by Post task */     /* Init from Model */
  vsreg_vsctl_stvsregextd_cpy = *VSCtl_stVSRegExtd_swc_out;

  vsreg_det_fct_diag_mnt_sf_dwork.is_ETAT_FONCTIONNEMENT = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_DISPONIBLE = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_ACTIVE = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_NON_REPRISE = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_INDISPONIBLE = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTION_PRESENTE = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_active_c80_VSREG_Det_Fct_Diag_Mnt_Sf = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_c80_VSREG_Det_Fct_Diag_Mnt_Sf = 0U;


  vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV =
    0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no1
    = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no1 = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_active_CONDITION_CAPTURE_MAINTENANCE_RVV_no2
    = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_CONDITION_CAPTURE_MAINTENANCE_RVV_no2 = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_FONCTIONNEMENT_h = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_active_c84_VSREG_Det_Fct_Diag_Mnt_Sf = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_c84_VSREG_Det_Fct_Diag_Mnt_Sf = 0U;
  VSCtl_bRec_stDeacVSRegReq =DDS_FALSE;



  vsreg_det_fct_diag_mnt_sf_dwork.is_DIAGNOSTIC_FONCTIONNEL_VEHICULE = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_MARCHE = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_active_c83_VSREG_Det_Fct_Diag_Mnt_Sf = 0U;
  vsreg_det_fct_diag_mnt_sf_dwork.is_c83_VSREG_Det_Fct_Diag_Mnt_Sf = 0U;
  *VSCtl_bMonRunVSRegVeh_swc_out =DDS_FALSE;
  vsreg_vsctl_bmonrunvsregveh_cpy = *VSCtl_bMonRunVSRegVeh_swc_out;

  *VSCtl_bDgoVSRegVeh_swc_out =DDS_FALSE;
  vsreg_vsctl_bdgovsregveh_cpy = *VSCtl_bDgoVSRegVeh_swc_out;


}

/* \AUT_POST_TAG FUNCTIONS */

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

