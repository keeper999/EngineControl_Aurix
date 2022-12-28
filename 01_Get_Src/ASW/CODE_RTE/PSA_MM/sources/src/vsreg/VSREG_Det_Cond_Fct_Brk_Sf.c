/*
* File: VSREG_Det_Cond_Fct_Brk_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSREG_Det_Cond_Fct_Brk_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Mon Nov 21 11:35:39 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Mon Nov 21 11:35:40 2011
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
*        aut_types version 3.0                                         aut_unset_set_block_properties_of_subsytem version 8.0
*        aut_update_init_file_with_tag version 4.0                     sim_check_if_data_is_in_full_range version 2.0
*        sim_check_unlinked_blocks version 11.0                        sim_configure_simulation_mode version 9.0
*        sim_display_dd_settings version 5.0                           sim_format_hyperlink_message version 6.0
*        sim_function_stub version 3.0                                 sim_get_autorisation_for_limitation version 1.0
*        sim_get_library_references version 46.0                       sim_get_library_version version 3.0
*        sim_get_static_data_block version 3.0                         sim_load_libraries version 3.0
*        sim_manage_block_tab version 6.0                              sim_manage_config_set version 4.0
*        sim_manage_link_status_warning version 3.0                    sim_manage_structure_dd_display version 2.0
*        sim_manage_structure_signals version 5.0                      sim_prepare_limitation version 60.0
*        sim_restore_previous_tag_version version 2.0                  sim_set version 1.0
*        sim_set_ic version 1.0                                        sim_set_param version 3.0
*        sim_sf_get_param version 7.0                                  sim_switch_block_mode version 5.0
*        sim_update_block_display_status version 18.0                  sim_warning_control version 5.0
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
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Det_Cond_Fct_Brk_Sf.c
* Version int :/main/L01_02/1 Date: 5/1/2012 11 h 23 m User:esnault 
*    TWK_model:VSREG_Det_Cond_Fct_Brk_Sf_L01_020_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_halouane_vsreg_euro6\1 Date: 4/1/2012 15 h 46 m User:halouane 
*    TWK_model:VSREG_Det_Cond_Fct_Brk_Sf_L01_020_IMPL1
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 21/11/2011 11 h 45 m User:demezil
*    TWK_model:VSREG_Det_Cond_Fct_Brk_Sf_L01_020_IMPL1
*    comments :for VSReg 12.0 : change calibration of VSCtl_tiTol_ASRRegVSReg_C
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 21/11/2011 11 h 43 m User:demezil
*    TWK_model:VSREG_Det_Cond_Fct_Brk_Sf_L01_020_IMPL1
*    comments :for VSReg 12.0 : change calibration of VSCtl_tiTol_ASRRegVSReg_C
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Frein_LAS */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Frein_LAS ;VSCtl_bASRRegVSReg;VSCtl_bESPRegVSReg;VSCtl_bFastDeacVSRegReq_Brk;VSCtl_bTyreWarnVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Frein_LAS ;VSCtl_bInhVSRegReq_Brk; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Inhibition_Frein_LAS */

/* TAG_START_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Frein_LAS */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Frein_LAS ;VSCtl_bABSRegVSReg;VSCtl_bBrkAutoVSReg;VSCtl_bBrkDynVSReg;VSCtl_bBrkPedPrssVSReg;VSCtl_bPrkBrkVSReg;VSCtl_bWhlSlipVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Frein_LAS ;VSCtl_bFastDeacVSRegReq_Brk; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Demandes_Desactivation_Rapide_Frein_LAS */

/* TAG_START_OF_SUB_FUNCTION: F21221_Determiner_Condition_Appui_Pedale_Frein */
/* TAG_INPUT_OF_SUB_FUNCTION: F21221_Determiner_Condition_Appui_Pedale_Frein ;Ext_bBrkPedPrss;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F21221_Determiner_Condition_Appui_Pedale_Frein ;VSCtl_bBrkPedPrssVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F21221_Determiner_Condition_Appui_Pedale_Frein */

/* TAG_START_OF_SUB_FUNCTION: F21222_Determiner_Condition_Serrage_Frein_Main */
/* TAG_INPUT_OF_SUB_FUNCTION: F21222_Determiner_Condition_Serrage_Frein_Main ;Ext_bPrkBrk;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F21222_Determiner_Condition_Serrage_Frein_Main ;VSCtl_bPrkBrkVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F21222_Determiner_Condition_Serrage_Frein_Main */

/* TAG_START_OF_SUB_FUNCTION: F21223_Determiner_Condition_Freinage_Automatique */
/* TAG_INPUT_OF_SUB_FUNCTION: F21223_Determiner_Condition_Freinage_Automatique ;Brk_bBrkAuto;Ext_bBrkAutoCf;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F21223_Determiner_Condition_Freinage_Automatique ;VSCtl_bBrkAutoVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F21223_Determiner_Condition_Freinage_Automatique */

/* TAG_START_OF_SUB_FUNCTION: F21224_Determiner_Condition_Freinage_Dynamique */
/* TAG_INPUT_OF_SUB_FUNCTION: F21224_Determiner_Condition_Freinage_Dynamique ;Brk_bBrkDyn;Ext_bBrkDynCf;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F21224_Determiner_Condition_Freinage_Dynamique ;VSCtl_bBrkDynVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F21224_Determiner_Condition_Freinage_Dynamique */

/* TAG_START_OF_SUB_FUNCTION: F21229_Determiner_Condition_Alerte_Pneumatiques */
/* TAG_INPUT_OF_SUB_FUNCTION: F21229_Determiner_Condition_Alerte_Pneumatiques ;Ext_bTyreWarn;Ext_bTyreWarnCf;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F21229_Determiner_Condition_Alerte_Pneumatiques ;VSCtl_bTyreWarnVSReg; */
/* TAG_END_OF_SUB_FUNCTION: F21229_Determiner_Condition_Alerte_Pneumatiques */

/* TAG_START_OF_SUB_FUNCTION: F2122A_Determiner_Conditions_Maintenance_Frein_LAS */
/* TAG_INPUT_OF_SUB_FUNCTION: F2122A_Determiner_Conditions_Maintenance_Frein_LAS ;VSCtl_bABSRegVSReg;VSCtl_bASRRegVSReg;VSCtl_bBrkAutoVSReg;VSCtl_bBrkDynVSReg;VSCtl_bBrkPedPrssVSReg;VSCtl_bESPRegVSReg;VSCtl_bPrkBrkVSReg;VSCtl_bTyreWarnVSReg;VSCtl_bWhlSlipVSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2122A_Determiner_Conditions_Maintenance_Frein_LAS ;VSCtl_stDeacVSRegReq_Brk; */
/* TAG_END_OF_SUB_FUNCTION: F2122A_Determiner_Conditions_Maintenance_Frein_LAS */

/* TAG_START_OF_STATEFLOW_FUNCTION: Glissement_Relatif */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Glissement_Relatif ;Ext_bABSCf;Ext_bABSReg;Ext_bASRESPCf;Ext_bASRReg;Ext_bESPReg;VSCtl_rWhlSlip_no1;VSCtl_rWhlSlip_no2;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Glissement_Relatif ;VSCtl_bWhlSlipVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Glissement_Relatif */

/* TAG_START_OF_STATEFLOW_FUNCTION: Regulation_ABS */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Regulation_ABS ;Ext_bABSCf;Ext_bABSReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Regulation_ABS ;VSCtl_bABSRegVSReg;VSCtl_tiFilABSRegVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Regulation_ABS */

/* TAG_START_OF_STATEFLOW_FUNCTION: Regulation_ASR */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Regulation_ASR ;Ext_bASRESPCf;Ext_bASRReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Regulation_ASR ;VSCtl_bASRRegVSReg;VSCtl_tiFilASRRegVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Regulation_ASR */

/* TAG_START_OF_STATEFLOW_FUNCTION: Regulation_ESP */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Regulation_ESP ;Ext_bASRESPCf;Ext_bESPReg;VSCtl_stMonVSReg; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Regulation_ESP ;VSCtl_bESPRegVSReg;VSCtl_tiFilESPRegVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Regulation_ESP */

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
#define EXT_BASRESPCF_PRESENT                   (1)
#define EXT_BABSCF_PRESENT                      (1)

/* Named constants for block: /Glissement_Relatif' */
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_GLISSEMENT_RELATIF_AV_AR (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_FAUX (0U)
#define VSREG_Det_Cond_Fct_Brk_Sf_VRAI (1U)

/* Named constants for block: /Regulation_ESP' */
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_REGULATION_ESP (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_g (4)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT (3)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_c (3)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_ABSENT (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b (0U)
#define VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b (1U)

/* Named constants for block: /Regulation_ASR' */
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD_k (0)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_n (4)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_d (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_a (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_b (3)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_REGULATION_ASR (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ASR_ABSENT (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT_e (3)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_n (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k (0U)
#define VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o (1U)

/* Named constants for block: /Regulation_ABS' */
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD_i (0)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_c (4)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_g (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_k (3)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_PRESENT (3)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_p (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_ABSENT (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_REGULATION_ABS (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_k (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g (0U)
#define VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt (1U)

/* Named constants for block: /Demandes_Desactivation_Rapide_Frein_LAS' */
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_PAS_DEMANDEE (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_DESACTIVATION_RAPIDE_FREIN_LAS (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d (0U)
#define VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c (1U)

/* Named constants for block: /Demandes_Desactivation_Inhibition_Frein_LAS' */
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_PAS_DEMANDEE_d (2)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE_g (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDE_INHIBITION_FREIN_LAS (1)
#define VSREG_Det_Cond_Fct_Brk_Sf_FAUX_n (0U)
#define VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e (1U)


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bTyreWarnVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bPrkBrkVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bBrkPedPrssVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bBrkDynVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bBrkAutoVSReg;
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
VAR(UInt8, AUTOMATIC) VSCtl_bWhlSlipVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq_Brk;
VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq_Brk;
VAR(UInt8, AUTOMATIC) VSCtl_bESPRegVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bASRRegVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bABSRegVSReg;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt32 is_MARCHE_ABS_PRESENT : 3;
  UInt32 is_MARCHE_ESP_PRESENT : 3;
  UInt32 is_MARCHE_ESP_PRESENT_p : 3;
  UInt32 is_DEMANDE_INHIBITION_FREIN_LAS : 2;
  UInt32 is_DESACTIVATION_RAPIDE_FREIN_LAS : 2;
  UInt32 is_REGULATION_ABS : 2;
  UInt32 is_REGULATION_ASR : 2;
  UInt32 is_REGULATION_ESP : 2;
  UInt32 is_GLISSEMENT_RELATIF_AV_AR : 2;
  UInt32 is_active_c57_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_c57_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_active_c56_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_c56_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_active_c55_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_c55_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_active_c54_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_c54_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_active_c53_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_c53_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_active_c1_VSREG_Det_Cond_Fct_Brk_Sf : 1;
  UInt32 is_c1_VSREG_Det_Cond_Fct_Brk_Sf : 1;
} D_Work_VSREG_Det_Cond_Fct_Brk_Sf;


/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilABSRegVSReg;                  /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilASRRegVSReg;                  /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilESPRegVSReg;                  /*BIN0*/
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
STATIC VAR(D_Work_VSREG_Det_Cond_Fct_Brk_Sf, AUTOMATIC) vsreg_det_cond_fct_brk_sf_dwork;
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rWhlSlip1VSReg_HysHi_C = (CONST(UInt16, AUTOMATIC))(5120U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rWhlSlip1VSReg_HysLo_C = (CONST(UInt16, AUTOMATIC))(3840U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rWhlSlip2VSReg_HysHi_C = (CONST(UInt16, AUTOMATIC))(5120U); /*BIN7*/
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rWhlSlip2VSReg_HysLo_C = (CONST(UInt16, AUTOMATIC))(3840U); /*BIN7*/
#define VSREG_STOP_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"


/* 8BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiCfm_bABSRegVSReg_C = (CONST(UInt8, AUTOMATIC))(2U);     /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiCfm_bASRRegVSReg_C = (CONST(UInt8, AUTOMATIC))(2U);     /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiCfm_bESPRegVSReg_C = (CONST(UInt8, AUTOMATIC))(2U);     /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDiCfm_bABSRegVSReg_C = (CONST(UInt8, AUTOMATIC))(1U);   /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDiCfm_bASRRegVSReg_C = (CONST(UInt8, AUTOMATIC))(1U);   /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDiCfm_bESPRegVSReg_C = (CONST(UInt8, AUTOMATIC))(1U);   /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiTol_ABSRegVSReg_C = (CONST(UInt8, AUTOMATIC))(9U);      /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiTol_ASRRegVSReg_C = (CONST(UInt8, AUTOMATIC))(9U);      /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiTol_ESPRegVSReg_C = (CONST(UInt8, AUTOMATIC))(9U);      /*BIN0*/
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

FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Brk_Sf(UInt8 Ext_bABSCf_swc_in,
                               UInt8 Ext_bBrkPedPrss_swc_in,
                               UInt8 Ext_bBrkAutoCf_swc_in,
                               UInt8 Ext_bBrkDynCf_swc_in,
                               UInt8 Ext_bASRReg_swc_in,
                               UInt8 Ext_bABSReg_swc_in,
                               UInt8 Ext_bTyreWarnCf_swc_in,
                               UInt8 Ext_bESPReg_swc_in,
                               UInt8 Brk_bBrkAuto_swc_in,
                               UInt8 Ext_bASRESPCf_swc_in,
                               UInt8 Brk_bBrkDyn_swc_in,
                               UInt16 VSCtl_rWhlSlip_no1_swc_in,                    /*BIN7*/
                               UInt8 Ext_bTyreWarn_swc_in,
                               UInt8 Ext_bPrkBrk_swc_in,
                               UInt16 VSCtl_rWhlSlip_no2_swc_in)                    /*BIN7*/
{

  /* TAG_START_OF_MAIN_FUNCTION */
  VSREG_F21221_Determiner_Condition_Appui_Pedale_Frein(Ext_bBrkPedPrss_swc_in);


  VSREG_F21222_Determiner_Condition_Serrage_Frein_Main(Ext_bPrkBrk_swc_in);


  VSREG_F21223_Determiner_Condition_Freinage_Automatique(Brk_bBrkAuto_swc_in,
                                                         Ext_bBrkAutoCf_swc_in);


  VSREG_F21224_Determiner_Condition_Freinage_Dynamique(Brk_bBrkDyn_swc_in,
                                                       Ext_bBrkDynCf_swc_in);

  /* TAG_START_OF_STATEFLOW_FUNCTION: F21225_Determiner_Glissement_Relatif*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.97.0  */

  if (vsreg_det_cond_fct_brk_sf_dwork.is_active_c1_VSREG_Det_Cond_Fct_Brk_Sf ==
      0)
  {
    vsreg_det_cond_fct_brk_sf_dwork.is_active_c1_VSREG_Det_Cond_Fct_Brk_Sf = 1U;
    vsreg_det_cond_fct_brk_sf_dwork.is_c1_VSREG_Det_Cond_Fct_Brk_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_GLISSEMENT_RELATIF_AV_AR;
    vsreg_det_cond_fct_brk_sf_dwork.is_GLISSEMENT_RELATIF_AV_AR = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI;
    VSCtl_bWhlSlipVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI;

  }
  else
  {
    switch (vsreg_det_cond_fct_brk_sf_dwork.is_GLISSEMENT_RELATIF_AV_AR) {
     case VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX:
      if ((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
          (((((VSCtl_rWhlSlip_no1_swc_in >= VSCtl_rWhlSlip1VSReg_HysHi_C) ||
              (VSCtl_rWhlSlip_no2_swc_in >= VSCtl_rWhlSlip2VSReg_HysHi_C))
              &&
             ((Ext_bESPReg_swc_in != VSREG_Det_Cond_Fct_Brk_Sf_VRAI)
             || (Ext_bASRESPCf_swc_in
               != EXT_BASRESPCF_PRESENT))) && ((Ext_bASRReg_swc_in !=
              VSREG_Det_Cond_Fct_Brk_Sf_VRAI) || (Ext_bASRESPCf_swc_in !=
              EXT_BASRESPCF_PRESENT))) && ((Ext_bABSReg_swc_in !=
             VSREG_Det_Cond_Fct_Brk_Sf_VRAI) || (Ext_bABSCf_swc_in !=
             EXT_BABSCF_PRESENT))))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_GLISSEMENT_RELATIF_AV_AR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI;
        VSCtl_bWhlSlipVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
          (((((VSCtl_rWhlSlip_no1_swc_in < VSCtl_rWhlSlip1VSReg_HysLo_C) &&
              (VSCtl_rWhlSlip_no2_swc_in < VSCtl_rWhlSlip2VSReg_HysLo_C)) ||
             ((Ext_bESPReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_VRAI)
             && (Ext_bASRESPCf_swc_in ==
               EXT_BASRESPCF_PRESENT))) || ((Ext_bASRReg_swc_in ==
              VSREG_Det_Cond_Fct_Brk_Sf_VRAI) && (Ext_bASRESPCf_swc_in ==
              EXT_BASRESPCF_PRESENT))) || ((Ext_bABSReg_swc_in ==
             VSREG_Det_Cond_Fct_Brk_Sf_VRAI) && (Ext_bABSCf_swc_in ==
             EXT_BABSCF_PRESENT))))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_GLISSEMENT_RELATIF_AV_AR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX;
        VSCtl_bWhlSlipVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX;
      }
      break;

     default:
      vsreg_det_cond_fct_brk_sf_dwork.is_GLISSEMENT_RELATIF_AV_AR = (UInt8)
        VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI;
      VSCtl_bWhlSlipVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21225_Determiner_Glissement_Relatif*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F21226_Determiner_Condition_Regulation_ESP*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.98.0  */

  if (vsreg_det_cond_fct_brk_sf_dwork.is_active_c53_VSREG_Det_Cond_Fct_Brk_Sf ==
      0)
  {
    vsreg_det_cond_fct_brk_sf_dwork.is_active_c53_VSREG_Det_Cond_Fct_Brk_Sf = 1U;
    vsreg_det_cond_fct_brk_sf_dwork.is_c53_VSREG_Det_Cond_Fct_Brk_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_REGULATION_ESP;
    vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET;
    VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b;
    VSCtl_tiFilESPRegVSReg = VSCtl_tiTol_ESPRegVSReg_C;

  }
  else
  {
    switch (vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP)
      {
     case VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bASRESPCf_swc_in !=
           EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_ABSENT;
        VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b;
        VSCtl_tiFilESPRegVSReg = VSCtl_tiTol_ESPRegVSReg_C;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
                 (Ext_bASRESPCf_swc_in == EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT;
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_c;
        VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_ABSENT:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bASRESPCf_swc_in ==
           EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT;
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_c;
        VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b;

      }
      else if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET;
        VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b;
        VSCtl_tiFilESPRegVSReg = VSCtl_tiTol_ESPRegVSReg_C;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET;
        VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b;
        VSCtl_tiFilESPRegVSReg = VSCtl_tiTol_ESPRegVSReg_C;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
                 (Ext_bASRESPCf_swc_in != EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_ABSENT;
        VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b;
        VSCtl_tiFilESPRegVSReg = VSCtl_tiTol_ESPRegVSReg_C;

      }
      else
      {
        switch (vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p)
      {
         case VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF:
          if ((Ext_bESPReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b) &&
              (VSCtl_tiFilESPRegVSReg != 0))
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF;

          }
          else if (VSCtl_tiFilESPRegVSReg == 0)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_g;
            VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b;

          }
          else
          {
            VSCtl_tiFilESPRegVSReg = (UInt8)DDS_M_MAX(VSCtl_tiFilESPRegVSReg -
              VSCtl_tiCfm_bESPRegVSReg_C, 0);
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF:
          if ((Ext_bESPReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b) &&
              (VSCtl_tiFilESPRegVSReg == VSCtl_tiTol_ESPRegVSReg_C))
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_c;
            VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b;

          }
          else if (Ext_bESPReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF;

          }
          else
          {
            VSCtl_tiFilESPRegVSReg = (UInt8)((VSCtl_tiFilESPRegVSReg +
              VSCtl_tiDiCfm_bESPRegVSReg_C) < VSCtl_tiTol_ESPRegVSReg_C ?
              VSCtl_tiFilESPRegVSReg + VSCtl_tiDiCfm_bESPRegVSReg_C : (SInt32)
              VSCtl_tiTol_ESPRegVSReg_C);
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_c:
          if (Ext_bESPReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF;
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_g:
          if (Ext_bESPReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_b)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF;
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = (UInt8)
        VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET;
      VSCtl_bESPRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_b;
      VSCtl_tiFilESPRegVSReg = VSCtl_tiTol_ESPRegVSReg_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21226_Determiner_Condition_Regulation_ESP*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F21227_Determiner_Condition_Regulation_ASR*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.99.0 */

  if (vsreg_det_cond_fct_brk_sf_dwork.is_active_c54_VSREG_Det_Cond_Fct_Brk_Sf ==
      0)
  {
    vsreg_det_cond_fct_brk_sf_dwork.is_active_c54_VSREG_Det_Cond_Fct_Brk_Sf = 1U;
    vsreg_det_cond_fct_brk_sf_dwork.is_c54_VSREG_Det_Cond_Fct_Brk_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_REGULATION_ASR;
    vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_a;
    VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o;
    VSCtl_tiFilASRRegVSReg = VSCtl_tiTol_ASRRegVSReg_C;

  }
  else
  {
    switch (vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR)
          {
     case VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_a:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bASRESPCf_swc_in !=
           EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ASR_ABSENT;
        VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k;
        VSCtl_tiFilASRRegVSReg = VSCtl_tiTol_ASRRegVSReg_C;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
                 (Ext_bASRESPCf_swc_in == EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT_e;
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_b;
        VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ASR_ABSENT:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bASRESPCf_swc_in ==
           EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT_e;
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_b;
        VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k;

      }
      else if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_a;
        VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o;
        VSCtl_tiFilASRRegVSReg = VSCtl_tiTol_ASRRegVSReg_C;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ESP_PRESENT_e:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD_k;
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_a;
        VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o;
        VSCtl_tiFilASRRegVSReg = VSCtl_tiTol_ASRRegVSReg_C;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
                 (Ext_bASRESPCf_swc_in != EXT_BASRESPCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD_k;
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ASR_ABSENT;
        VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k;
        VSCtl_tiFilASRRegVSReg = VSCtl_tiTol_ASRRegVSReg_C;

      }
      else
      {
        switch (vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT)
      {
         case VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_d:
          if ((Ext_bASRReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k) &&
              (VSCtl_tiFilASRRegVSReg != 0))
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_n;

          }
          else if (VSCtl_tiFilASRRegVSReg == 0)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_n;
            VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o;

          }
          else
          {
            VSCtl_tiFilASRRegVSReg = (UInt8)DDS_M_MAX(VSCtl_tiFilASRRegVSReg -
              VSCtl_tiCfm_bASRRegVSReg_C, 0);
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_n:
          if ((Ext_bASRReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k) &&
              (VSCtl_tiFilASRRegVSReg == VSCtl_tiTol_ASRRegVSReg_C))
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_b;
            VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k;

          }
          else if (Ext_bASRReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_d;

          }
          else
          {
            VSCtl_tiFilASRRegVSReg = (UInt8)((VSCtl_tiFilASRRegVSReg +
              VSCtl_tiDiCfm_bASRRegVSReg_C) < VSCtl_tiTol_ASRRegVSReg_C ?
              VSCtl_tiFilASRRegVSReg + VSCtl_tiDiCfm_bASRRegVSReg_C : (SInt32)
              VSCtl_tiTol_ASRRegVSReg_C);
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_b:
          if (Ext_bASRReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_d;
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_n:
          if (Ext_bASRReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_k)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_n;
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = (UInt8)
        VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_a;
      VSCtl_bASRRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_o;
      VSCtl_tiFilASRRegVSReg = VSCtl_tiTol_ASRRegVSReg_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21227_Determiner_Condition_Regulation_ASR*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F21228_Determiner_Condition_Regulation_ABS*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.100.0  */

  if (vsreg_det_cond_fct_brk_sf_dwork.is_active_c55_VSREG_Det_Cond_Fct_Brk_Sf ==
      0)
  {
    vsreg_det_cond_fct_brk_sf_dwork.is_active_c55_VSREG_Det_Cond_Fct_Brk_Sf = 1U;
    vsreg_det_cond_fct_brk_sf_dwork.is_c55_VSREG_Det_Cond_Fct_Brk_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_REGULATION_ABS;
    vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_p;
    VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt;
    VSCtl_tiFilABSRegVSReg = VSCtl_tiTol_ABSRegVSReg_C;

  }
  else
  {
    switch (vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS)
          {
     case VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_p:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bABSCf_swc_in !=
           EXT_BABSCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_ABSENT;
        VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g;
        VSCtl_tiFilABSRegVSReg = VSCtl_tiTol_ABSRegVSReg_C;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bABSCf_swc_in ==
                  EXT_BABSCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_PRESENT;
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_k;
        VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_ABSENT:
      if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bABSCf_swc_in ==
           EXT_BABSCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_PRESENT;
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_k;
        VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g;

      }
      else if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_p;
        VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt;
        VSCtl_tiFilABSRegVSReg = VSCtl_tiTol_ABSRegVSReg_C;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_PRESENT:
      if (VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL)
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD_i;
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_p;
        VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt;
        VSCtl_tiFilABSRegVSReg = VSCtl_tiTol_ABSRegVSReg_C;

      }
      else if ((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL)
      && (Ext_bABSCf_swc_in
                  != EXT_BABSCF_PRESENT))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_NO_ACTIVE_CHILD_i;
        vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
          VSREG_Det_Cond_Fct_Brk_Sf_IN_MARCHE_ABS_ABSENT;
        VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g;
        VSCtl_tiFilABSRegVSReg = VSCtl_tiTol_ABSRegVSReg_C;

      }
      else
      {
        switch (vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT)
      {
         case VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_k:
          if ((Ext_bABSReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g) &&
              (VSCtl_tiFilABSRegVSReg != 0))
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_g;

          }
          else if (VSCtl_tiFilABSRegVSReg == 0)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_c;
            VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt;

          }
          else
          {
            VSCtl_tiFilABSRegVSReg = (UInt8)DDS_M_MAX(VSCtl_tiFilABSRegVSReg -
              VSCtl_tiCfm_bABSRegVSReg_C, 0);
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_g:
          if ((Ext_bABSReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g) &&
              (VSCtl_tiFilABSRegVSReg == VSCtl_tiTol_ABSRegVSReg_C))
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_k;
            VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g;

          }
          else if (Ext_bABSReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_k;

          }
          else
          {
            VSCtl_tiFilABSRegVSReg = (UInt8)((VSCtl_tiFilABSRegVSReg +
              VSCtl_tiDiCfm_bABSRegVSReg_C) < VSCtl_tiTol_ABSRegVSReg_C ?
              VSCtl_tiFilABSRegVSReg + VSCtl_tiDiCfm_bABSRegVSReg_C : (SInt32)
              VSCtl_tiTol_ABSRegVSReg_C);
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_FAUX_k:
          if (Ext_bABSReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_CONF_k;
          }
          break;

         case VSREG_Det_Cond_Fct_Brk_Sf_IN_VRAI_c:
          if (Ext_bABSReg_swc_in == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_g)
          {
            vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = (UInt8)
              VSREG_Det_Cond_Fct_Brk_Sf_IN_DECONF_g;
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = (UInt8)
        VSREG_Det_Cond_Fct_Brk_Sf_IN_ARRET_p;
      VSCtl_bABSRegVSReg = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_bt;
      VSCtl_tiFilABSRegVSReg = VSCtl_tiTol_ABSRegVSReg_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F21228_Determiner_Condition_Regulation_ABS*/

  VSREG_F21229_Determiner_Condition_Alerte_Pneumatiques(Ext_bTyreWarn_swc_in,
                                                      Ext_bTyreWarnCf_swc_in);

  VSREG_F2122a_Determiner_Conditions_Maintenance_Frein_Las();

  /* TAG_START_OF_STATEFLOW_FUNCTION: F2122B_Determiner_Demande_Desactivation_Rapide_Frein_LAS*/

  if (vsreg_det_cond_fct_brk_sf_dwork.is_active_c56_VSREG_Det_Cond_Fct_Brk_Sf ==
      0)
  {
    vsreg_det_cond_fct_brk_sf_dwork.is_active_c56_VSREG_Det_Cond_Fct_Brk_Sf = 1U;
    vsreg_det_cond_fct_brk_sf_dwork.is_c56_VSREG_Det_Cond_Fct_Brk_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_DESACTIVATION_RAPIDE_FREIN_LAS;
    vsreg_det_cond_fct_brk_sf_dwork.is_DESACTIVATION_RAPIDE_FREIN_LAS = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE;
    VSCtl_bFastDeacVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c;

  }
  else
  {
    switch (vsreg_det_cond_fct_brk_sf_dwork.is_DESACTIVATION_RAPIDE_FREIN_LAS)
          {
     case VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE:
      if (((((((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
               (VSCtl_bBrkPedPrssVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d))
               &&
              (VSCtl_bPrkBrkVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d))
              &&
             (VSCtl_bBrkAutoVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d))
             &&
            (VSCtl_bBrkDynVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d))
            &&
           (VSCtl_bWhlSlipVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d))
           &&
          (VSCtl_bABSRegVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_DESACTIVATION_RAPIDE_FREIN_LAS =
          (UInt8)VSREG_Det_Cond_Fct_Brk_Sf_IN_PAS_DEMANDEE;
        VSCtl_bFastDeacVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_d;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_PAS_DEMANDEE:
      if (((((((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
               (VSCtl_bBrkPedPrssVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c))
               ||
              (VSCtl_bPrkBrkVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c))
              ||
             (VSCtl_bBrkAutoVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c))
             ||
            (VSCtl_bBrkDynVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c))
            ||
           (VSCtl_bWhlSlipVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c))
           ||
          (VSCtl_bABSRegVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_DESACTIVATION_RAPIDE_FREIN_LAS =
          (UInt8)VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE;
        VSCtl_bFastDeacVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c;
      }
      break;

     default:
      vsreg_det_cond_fct_brk_sf_dwork.is_DESACTIVATION_RAPIDE_FREIN_LAS =
        (UInt8)VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE;
      VSCtl_bFastDeacVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_c;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2122B_Determiner_Demande_Desactivation_Rapide_Frein_LAS*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F2122C_Determiner_Demande_Inhibition_Frein_LAS*/

  if (vsreg_det_cond_fct_brk_sf_dwork.is_active_c57_VSREG_Det_Cond_Fct_Brk_Sf ==
      0)
  {
    vsreg_det_cond_fct_brk_sf_dwork.is_active_c57_VSREG_Det_Cond_Fct_Brk_Sf = 1U;
    vsreg_det_cond_fct_brk_sf_dwork.is_c57_VSREG_Det_Cond_Fct_Brk_Sf = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDE_INHIBITION_FREIN_LAS;
    vsreg_det_cond_fct_brk_sf_dwork.is_DEMANDE_INHIBITION_FREIN_LAS = (UInt8)
      VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE_g;
    VSCtl_bInhVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e;

  }
  else
  {
    switch (vsreg_det_cond_fct_brk_sf_dwork.is_DEMANDE_INHIBITION_FREIN_LAS)
      {
     case VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE_g:
      if (((((VSCtl_stMonVSReg == VSCTL_STMONVSREG_NOMINAL) &&
             (VSCtl_bFastDeacVSRegReq_Brk == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_n))
             &&
            (VSCtl_bESPRegVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_n))
            &&
           (VSCtl_bASRRegVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_n))
           &&
          (VSCtl_bTyreWarnVSReg == VSREG_Det_Cond_Fct_Brk_Sf_FAUX_n))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_DEMANDE_INHIBITION_FREIN_LAS =
          (UInt8)VSREG_Det_Cond_Fct_Brk_Sf_IN_PAS_DEMANDEE_d;
        VSCtl_bInhVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_FAUX_n;
      }
      break;

     case VSREG_Det_Cond_Fct_Brk_Sf_IN_PAS_DEMANDEE_d:
      if (((((VSCtl_stMonVSReg != VSCTL_STMONVSREG_NOMINAL) ||
             (VSCtl_bFastDeacVSRegReq_Brk == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e))
             ||
            (VSCtl_bESPRegVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e))
            ||
           (VSCtl_bASRRegVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e))
           ||
          (VSCtl_bTyreWarnVSReg == VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e))
      {
        vsreg_det_cond_fct_brk_sf_dwork.is_DEMANDE_INHIBITION_FREIN_LAS =
          (UInt8)VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE_g;
        VSCtl_bInhVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e;
      }
      break;

     default:
      vsreg_det_cond_fct_brk_sf_dwork.is_DEMANDE_INHIBITION_FREIN_LAS = (UInt8)
        VSREG_Det_Cond_Fct_Brk_Sf_IN_DEMANDEE_g;
      VSCtl_bInhVSRegReq_Brk = VSREG_Det_Cond_Fct_Brk_Sf_VRAI_e;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2122C_Determiner_Demande_Inhibition_Frein_LAS*/


  /* TAG_END_OF_MAIN_FUNCTION */
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Brk_Sf_Init(void)
{
    VSREG_Brake_Cond_Sl_Init();

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */

  VSCtl_tiFilABSRegVSReg = VSCtl_tiTol_ABSRegVSReg_C;   /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiFilASRRegVSReg = VSCtl_tiTol_ASRRegVSReg_C;   /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiFilESPRegVSReg = VSCtl_tiTol_ESPRegVSReg_C;   /* Replaced by Post task */     /* Init from Model */


  vsreg_det_cond_fct_brk_sf_dwork.is_GLISSEMENT_RELATIF_AV_AR = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_active_c1_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_c1_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  VSCtl_bWhlSlipVSReg =DDS_FALSE;



  vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ESP = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT_p = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_active_c53_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_c53_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  VSCtl_bESPRegVSReg =DDS_FALSE;



  vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ASR = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ESP_PRESENT = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_active_c54_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_c54_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  VSCtl_bASRRegVSReg =DDS_FALSE;



  vsreg_det_cond_fct_brk_sf_dwork.is_REGULATION_ABS = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_MARCHE_ABS_PRESENT = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_active_c55_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_c55_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  VSCtl_bABSRegVSReg =DDS_FALSE;



  vsreg_det_cond_fct_brk_sf_dwork.is_DESACTIVATION_RAPIDE_FREIN_LAS = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_active_c56_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_c56_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  VSCtl_bFastDeacVSRegReq_Brk =DDS_FALSE;



  vsreg_det_cond_fct_brk_sf_dwork.is_DEMANDE_INHIBITION_FREIN_LAS = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_active_c57_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  vsreg_det_cond_fct_brk_sf_dwork.is_c57_VSREG_Det_Cond_Fct_Brk_Sf = 0U;
  VSCtl_bInhVSRegReq_Brk =DDS_FALSE;

}

/* \AUT_POST_TAG FUNCTIONS */

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

