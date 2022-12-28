/*
* File: VSINFO_Ela_Gmp1_Re002tev_Sf.c
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
* Real-Time Workshop code generated for Simulink model VSINFO_Ela_Gmp1_Re002tev_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Wed Jul 13 10:34:17 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Wed Jul 13 10:34:18 2011
*
* Post treatment done by tool Aut_Autocode_Post.pl version 11.45
*        with rules Aut_Rules_For_Autocode_Post.pm version 12.00
*
* Code generated from spec : R6512345_10
*
* LABEL USED: LIBRARY_R6510684_14_0_0
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
*
* Libraries versions:
*        aut_ems_lib version 14.x
*
* Common dll version 3.0
*
* Blocks versions:
*
* Scripts versions:
*        aut_add_io version 1.0                                        aut_calc_block_before_limiter version 7.0
*        aut_cast_block_before_limiter version 3.0                     aut_check_accuracy_loss version 4.0
*        aut_check_blocks_fields_values version 2.0                    aut_check_calc_blocks version 41.0
*        aut_check_downcast version 3.0                                aut_check_if_data_exists_into_workps version 3.0
*        aut_check_if_data_if_an_nvv_data_store version 2.0            aut_check_if_data_is_shared version 2.0
*        aut_check_if_globlal_T55_exist version 2.0                    aut_check_if_parameter_present_into_model version 2.0
*        aut_check_if_previous_block_equal_to_type version 3.0         aut_check_if_range_is_compatible_with_datatype version 4.0
*        aut_check_model_vs_workswpace version 2.0                     aut_check_pointer_access version 3.0
*        aut_chk_lcs version 2.0                                       aut_create_alias_type version 2.0
*        aut_create_data version 22.0                                  aut_create_enum version 9.0
*        aut_create_hyperlink_command_from_block version 2.0           aut_create_sstg_architecture version 9.0
*        aut_cross_check_T55_mdl_init version 3.0                      aut_fixed_point_toolbox_interface version 3.0
*        aut_format_cpv_initialization_line version 9.0                aut_free_up_unexpected_block version 2.0
*        aut_get_array_apv_according_calibration_mode version 4.0      aut_get_data_list_from_link_output_block version 2.0
*        aut_get_data_size version 2.0                                 aut_get_deeper_block_from_list version 2.0
*        aut_get_evaluated_value_from_constant version 3.0             aut_get_final_datatype version 2.0
*        aut_get_information_from_next_block version 15.0              aut_get_key version 2.0
*        aut_get_sigtype_info version 2.0                              aut_get_squeduling_list version 15.0
*        aut_get_src_handle_from_previous_block_and_port_index version 2.0aut_get_static_data_list version 3.0
*        aut_init_value_check version 3.0                              aut_key_alg version 2.0
*        aut_manage_autocode_model version 14.0                        aut_manage_compilation_mode version 2.0
*        aut_manage_doc_block version 6.0                              aut_manage_limiter version 10.0
*        aut_manage_model_workspace version 2.0                        aut_manage_simulink_to_post_task_exchange version 48.0
*        aut_manage_snapshot version 25.0                              aut_mode_switch version 62.0
*        aut_model_autocode version 22.0                               aut_model_configure version 6.0
*        aut_pre_autocode version 53.0                                 aut_prepare_t55_task version 27.0
*        aut_prepare_t55_task_for_tag version 8.0                      aut_process_mngt version 52.0
*        aut_project_settings version 20.0                             aut_signal_config version 11.0
*        aut_sstg_manage_signal_memory_location version 5.0            aut_stateflow_checks version 6.0
*        aut_step_ckecks version 3.0                                   aut_switch_cpv_initialization version 11.0
*        aut_types version 2.0                                         aut_unset_set_block_properties_of_subsytem version 7.0
*        aut_update_init_file_with_tag version 3.0                     sim_check_if_data_is_in_full_range version 2.0
*        sim_check_unlinked_blocks version 11.0                        sim_configure_simulation_mode version 9.0
*        sim_display_dd_settings version 5.0                           sim_format_hyperlink_message version 4.0
*        sim_get_library_references version 42.0                       sim_get_library_version version 2.0
*        sim_get_static_data_block version 3.0                         sim_load_libraries version 2.0
*        sim_manage_block_tab version 4.0                              sim_manage_config_set version 4.0
*        sim_manage_link_status_warning version 3.0                    sim_manage_structure_dd_display version 2.0
*        sim_manage_structure_signals version 5.0                      sim_prepare_limitation version 58.0
*        sim_sf_get_param version 7.0                                  sim_switch_block_mode version 3.0
*        sim_update_block_display_status version 16.0                  sim_update_field_if_change version 2.0
*        sim_warning_control version 5.0
*
* Post task version 11.45
*
* Config Spec:
*        element * CHECKEDOUT
*        element ClearCase_Tools\...  /main/LATEST
*        element * R6514768_10.1_DRAFT
*        element * AUTOCODE_GEN2_REF_S_S_LIB
*        element * UNIT_TEST_LIB_1_3
*        element * ITG_INTEGRATION_TOOL_NEXT_INTEGRATION
*        element * 00601005_DELIV_1
*        element * LABEL_JONCHIERES_DEBUG_SSTG
*        element * 00601003_DELIV_1
*        element s_s_lib\... LABEL_BROU_LIB
*        element s_s_lib\... LABEL_JONCHIERES
*        element * NMA9T000_DELIV_1
*        element * LIBRARY_VALIDATION_R6510684_NEXT_INTEGRATION
*        element * LIBRARY_R6510684_NEXT_INTEGRATION
*        element * LIBRARY_R6515852_NEXT_INTEGRATION
*        element Validation\... /main/LATEST
*        element * MODEL_BLOCKS_TREE_NEXT_INTEGRATION
*        element * MODEL_BLOCKS_TREE_OFFICIAL_RELEASE
*        element * MODEL_COMPLEXITY_OFFICIAL_RELEASE
*        element * LIBRARY_R6515852_4_0_0
*        element ldcr_tools\...  /main/LATEST
*        element * /main/LATEST
*
* Block list with autocode bypass option activated:
*        No bypassed blocks into this model
*
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Ela_Gmp1_Re002tev_Sf.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 6 m User:meme 
*    TWK_model:VSINFO_Ela_Gmp1_Re002tev_Sf_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\4 Date: 1/8/2011 14 h 44 m User:demezil 
*    TWK_model:VSINFO_Ela_Gmp1_Re002tev_Sf_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\3 Date: 13/7/2011 14 h 52 m User:demezil
*    TWK_model:VSINFO_Ela_Gmp1_Re002tev_Sf_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 13/7/2011 11 h 14 m User:demezil
*    TWK_model:VSINFO_Ela_Gmp1_Re002tev_Sf_L02_010_IMPL1
*    comments :for VSInfo 11.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_1 */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_1 ;ECU_bAuthVSCtlIni;Ext_bAvlTqWhlPT_no1;Ext_bVSLimCf;Ext_bVSMaxfCf;Ext_bVSMaxpCf;Ext_bVSMaxsCf;Ext_stDVSRegCf;FRM_bDeacVSCtlPTClc;VSCtl_bCtlEfc_tqWhlPTMax; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_1 ;VSCtl_bAcvFilPTInfo_pt1;VSCtl_stPTInfo_pt1;VSCtl_tiIniPTClc_pt1; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Informations_GMP_1 */

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
#define VSCTL_STPTINFO_PT1_ARRET                    (0)
#define VSCTL_STPTINFO_PT1_VERIF_1                  (1)
#define VSCTL_STPTINFO_PT1_INIT_1                   (2)
#define VSCTL_STPTINFO_PT1_NOMINAL_1                (3)
#define VSCTL_STPTINFO_PT1_DEFAUT_1                 (4)

/* Named constants for block: /Etat_Informations_GMP_1' */
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_DEFAUT (1)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_ARRET (1)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_INIT (1)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_NOMINAL (2)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_MARCHE (2)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_PAS_DEFAUT (2)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_ETAT_INFORMATIONS_GMP_1 (1)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_IN_VERIF (3)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI (1U)
#define VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX (0U)

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/
/* \<AUT_POST> : Task Memory Ordering */

/* 16BIT-bits variable definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) VSCtl_tiIni_PTInfo_C;         /*BIN0*/
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"

/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stPTInfo_pt1;
VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilPTInfo_pt1;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt32 is_MARCHE : 2;                /* /Etat_Informations_GMP_1' */
  UInt32 is_PAS_DEFAUT : 2;            /* /Etat_Informations_GMP_1' */
  UInt32 is_ETAT_INFORMATIONS_GMP_1 : 2;/* /Etat_Informations_GMP_1' */
  UInt32 is_active_c1_VSINFO_Ela_Gmp1_Re002tev_Sf : 1;/* /Etat_Informations_GMP_1' */
  UInt32 is_c1_VSINFO_Ela_Gmp1_Re002tev_Sf : 1;/* /Etat_Informations_GMP_1' */
} D_Work_VSINFO_Ela_Gmp1_Re002tev_Sf;

/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiIniPTClc_pt1;                   /*BIN0*/
/* Static Visible area end */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* UNSPECIFIED-bits variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(D_Work_VSINFO_Ela_Gmp1_Re002tev_Sf, AUTOMATIC) vsinfo_ela_gmp1_re002tev_sf_dwork;
/* Static Not Visible area end */
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* <AUT_PRE> DECLARATIONS */
/* \<AUT_PRE> DECLARATIONS */
/* <AUT_PRE> FUNCTIONS */

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

FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp1_Re002tev_Sf(UInt8 Ext_bVSMaxfCf_swc_in,
                               UInt8 FRM_bDeacVSCtlPTClc_swc_in,
                               UInt8 Ext_bVSLimCf_swc_in,
                               UInt8 Ext_bAvlTqWhlPT_no1_swc_in,
                               UInt8 VSCtl_bCtlEfc_tqWhlPTMax_swc_in,
                               UInt8 Ext_bVSMaxpCf_swc_in,
                               UInt8 Ext_stDVSRegCf_swc_in,
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt8 Ext_bVSMaxsCf_swc_in)

{

  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F1111_Determiner_Etat_Informations_GMP*/

  if (vsinfo_ela_gmp1_re002tev_sf_dwork.is_active_c1_VSINFO_Ela_Gmp1_Re002tev_Sf
      == 0)
  {
    vsinfo_ela_gmp1_re002tev_sf_dwork.is_active_c1_VSINFO_Ela_Gmp1_Re002tev_Sf =
      1U;
    vsinfo_ela_gmp1_re002tev_sf_dwork.is_c1_VSINFO_Ela_Gmp1_Re002tev_Sf =
      (UInt8)VSINFO_Ela_Gmp1_Re002tev_Sf_IN_ETAT_INFORMATIONS_GMP_1;
    vsinfo_ela_gmp1_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_1 = (UInt8)
      VSINFO_Ela_Gmp1_Re002tev_Sf_IN_ARRET;
    VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_ARRET;
    VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX;
    VSCtl_tiIniPTClc_pt1 = VSCtl_tiIni_PTInfo_C;

  }
  else
  {
    switch (vsinfo_ela_gmp1_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_1) {
     case VSINFO_Ela_Gmp1_Re002tev_Sf_IN_ARRET:
      if (((VSCtl_bCtlCmdPTTqCf_SC == VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
/* <PRQA_COMMENT><3356> statement value change with VSCtl_bCtlCmdPTTqCf_SC </3356></PRQA_COMMENT> */
      &&
           (Ext_bAvlTqWhlPT_no1_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI))
           &&
          ((((((Ext_stDVSRegCf_swc_in == EXT_STDVSREGCF_RVV_PRESENT)
          || (Ext_stDVSRegCf_swc_in
                == EXT_STDVSREGCF_ACC_PRESENT)) || (Ext_bVSLimCf_swc_in ==
               EXT_BVSLIMCF_PRESENT))
               || (Ext_bVSMaxfCf_swc_in == EXT_BVSMAXFCF_PRESENT))

            || (Ext_bVSMaxpCf_swc_in == EXT_BVSMAXPCF_PRESENT))
            || (Ext_bVSMaxsCf_swc_in ==
            EXT_BVSMAXSCF_PRESENT)))
/* <PRQA_COMMENT><3201> statement reachable if VSCtl_bCtlCmdPTTqCf_SC = DDS_TRUE </3201></PRQA_COMMENT> */
      {
        vsinfo_ela_gmp1_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_1 = (UInt8)
          VSINFO_Ela_Gmp1_Re002tev_Sf_IN_MARCHE;
        vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Ela_Gmp1_Re002tev_Sf_IN_VERIF;
        VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_VERIF_1;
      }
      break;

     case VSINFO_Ela_Gmp1_Re002tev_Sf_IN_MARCHE:
      if (((VSCtl_bCtlCmdPTTqCf_SC != VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE)
/* <PRQA_COMMENT><3355> statement value change with VSCtl_bCtlCmdPTTqCf_SC </3355></PRQA_COMMENT> */
      ||
           (Ext_bAvlTqWhlPT_no1_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX))
           ||
          ((((((Ext_stDVSRegCf_swc_in != EXT_STDVSREGCF_RVV_PRESENT)
          && (Ext_stDVSRegCf_swc_in
                != EXT_STDVSREGCF_ACC_PRESENT)) && (Ext_bVSLimCf_swc_in ==
               EXT_BVSLIMCF_ABSENT))
               && (Ext_bVSMaxfCf_swc_in == EXT_BVSMAXFCF_ABSENT))

            && (Ext_bVSMaxpCf_swc_in == EXT_BVSMAXPCF_ABSENT))
            && (Ext_bVSMaxsCf_swc_in ==
            EXT_BVSMAXSCF_ABSENT)))
      {
        vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE = (UInt8)
          VSINFO_Ela_Gmp1_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_ela_gmp1_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
          VSINFO_Ela_Gmp1_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
        vsinfo_ela_gmp1_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_1 = (UInt8)
          VSINFO_Ela_Gmp1_Re002tev_Sf_IN_ARRET;
        VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_ARRET;
        VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX;
        VSCtl_tiIniPTClc_pt1 = VSCtl_tiIni_PTInfo_C;

      }
      else
/* <PRQA_COMMENT><3201> statement reachable if VSCtl_bCtlCmdPTTqCf_SC = DDS_TRUE </3201></PRQA_COMMENT> */
      {
        switch (vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE)
      {
         case VSINFO_Ela_Gmp1_Re002tev_Sf_IN_DEFAUT:
          if (FRM_bDeacVSCtlPTClc_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX)
          {
            vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp1_Re002tev_Sf_IN_PAS_DEFAUT;
            vsinfo_ela_gmp1_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Ela_Gmp1_Re002tev_Sf_IN_INIT;
            VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_INIT_1;
            VSCtl_tiIniPTClc_pt1 = VSCtl_tiIni_PTInfo_C;
            VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX;
          }
          break;

         case VSINFO_Ela_Gmp1_Re002tev_Sf_IN_PAS_DEFAUT:
          if (FRM_bDeacVSCtlPTClc_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI)
          {
            vsinfo_ela_gmp1_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Ela_Gmp1_Re002tev_Sf_IN_NO_ACTIVE_CHILD;
            vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp1_Re002tev_Sf_IN_DEFAUT;
            VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_DEFAUT_1;
            VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX;

          }
          else
          {
            switch (vsinfo_ela_gmp1_re002tev_sf_dwork.is_PAS_DEFAUT)
          {
             case VSINFO_Ela_Gmp1_Re002tev_Sf_IN_INIT:
              if ((VSCtl_tiIniPTClc_pt1 == 0)
              && (VSCtl_bCtlEfc_tqWhlPTMax_swc_in ==
                   VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX))
              {
                vsinfo_ela_gmp1_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSINFO_Ela_Gmp1_Re002tev_Sf_IN_NOMINAL;
                VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_NOMINAL_1;
                VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI;

              }
              else
              {
                VSCtl_tiIniPTClc_pt1 = (UInt16)DDS_M_MAX(VSCtl_tiIniPTClc_pt1 - 1,
                  0);
                VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI;
              }
              break;
            }
          }
          break;

         case VSINFO_Ela_Gmp1_Re002tev_Sf_IN_VERIF:
          if ((ECU_bAuthVSCtlIni_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI)
          &&
              (FRM_bDeacVSCtlPTClc_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI))
          {
            vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp1_Re002tev_Sf_IN_DEFAUT;
            VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_DEFAUT_1;
            VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX;

          }
          else if ((ECU_bAuthVSCtlIni_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_VRAI)
          &&
                     (FRM_bDeacVSCtlPTClc_swc_in == VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX))
          {
            vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE = (UInt8)
              VSINFO_Ela_Gmp1_Re002tev_Sf_IN_PAS_DEFAUT;
            vsinfo_ela_gmp1_re002tev_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSINFO_Ela_Gmp1_Re002tev_Sf_IN_INIT;
            VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_INIT_1;
            VSCtl_tiIniPTClc_pt1 = VSCtl_tiIni_PTInfo_C;
            VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX;
          }
          break;
        }
      }
      break;

     default:
      vsinfo_ela_gmp1_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_1 = (UInt8)
        VSINFO_Ela_Gmp1_Re002tev_Sf_IN_ARRET;
      VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_ARRET;
      VSCtl_bAcvFilPTInfo_pt1 = VSINFO_Ela_Gmp1_Re002tev_Sf_FAUX;
      VSCtl_tiIniPTClc_pt1 = VSCtl_tiIni_PTInfo_C;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F1111_Determiner_Etat_Informations_GMP*/


  /* TAG_END_OF_MAIN_FUNCTION */
}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp1_Re002tev_Sf_Init(void)
{


  VSCtl_tiIniPTClc_pt1 = VSCtl_tiIni_PTInfo_C;  /* Replaced by Post task */     /* Init from Model */
  VSCtl_stPTInfo_pt1 = VSCTL_STPTINFO_PT1_ARRET;    /* Replaced by Post task */     /* Init from Model */


  vsinfo_ela_gmp1_re002tev_sf_dwork.is_ETAT_INFORMATIONS_GMP_1 = 0U;
  vsinfo_ela_gmp1_re002tev_sf_dwork.is_MARCHE = 0U;
  vsinfo_ela_gmp1_re002tev_sf_dwork.is_PAS_DEFAUT = 0U;
  vsinfo_ela_gmp1_re002tev_sf_dwork.is_active_c1_VSINFO_Ela_Gmp1_Re002tev_Sf =
    0U;
  vsinfo_ela_gmp1_re002tev_sf_dwork.is_c1_VSINFO_Ela_Gmp1_Re002tev_Sf = 0U;
  VSCtl_bAcvFilPTInfo_pt1 =DDS_FALSE;

}

/* \<AUT_PRE> FUNCTIONS */

#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

