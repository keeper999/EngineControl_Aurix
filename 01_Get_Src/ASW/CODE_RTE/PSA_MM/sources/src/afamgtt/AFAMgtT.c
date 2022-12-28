/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software Component                              */
/*                                                                            */
/* !File            : AFAMgtT.c                                               */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AFAMgtT_SWC.mdl                                       */
/*   Root subsystem   : /AFAMgtT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   22 Aug 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT.h"
#include "AFAMgtT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAMgtT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAMgtT_MemMap.h"


/* Exported block signals */
UInt32 AFAMgt_tiCntStabRatOpEGR_IRV_MP;
UInt32 AFAMgt_tiCntNotDynCorPres_IRV_MP;
UInt32 AFAMgt_tiCntStabEgdGear_IRV_MP;
UInt32 AFAMgt_tiCntStabEOM_IRV_MP;   
UInt32 AFAMgt_tiCntStabFacStrt_IRV_MP;
UInt32 AFAMgt_tiCntStabAirLd_IRV_MP; 
UInt32 AFAMgt_tiCntStabFuMod_IRV_MP; 
UInt32 AFAMgt_tiCntStabAirMod_IRV_MP;
UInt32 AFAMgt_tiDlyLstObsThd_IRV_MP; 

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAMgtT_MemMap.h"

UInt16 AFAMgt_rAirLdMax_IRV_MP;      
UInt16 AFAMgt_rAirLdMin_IRV_MP;      

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_INTERNAL_VAR_8BIT
#include "AFAMgtT_MemMap.h"

UInt8 AFAMgt_noEgdGearCordHld_IRV_MP;
UInt8 AFAMgt_rEGRMin_IRV_MP;         
UInt8 AFAMgt_rEGRMax_IRV_MP;         

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"

Boolean AFAMgt_bIdcNotDynCorPres_IRV_MP;
Boolean AFAMgt_bIdcStabRatOpEGR_IRV_MP;
Boolean AFAMgt_bIdcInhChk;           
Boolean AFAMgt_bTranModHld_IRV_MP;   
Boolean AFAMgt_bStabAirLdCor_IRV_MP; 
Boolean AFAMgt_bStabEgdGear_IRV_MP;  
Boolean AFAMgt_bStabEOM_IRV_MP;      
Boolean AFAMgt_bStabFacStrtCor_IRV_MP;
Boolean AFAMgt_bIdcStabAirMod_IRV_MP;
Boolean AFAMgt_bIdcStabFuMod_IRV_MP; 
Boolean AFAMgt_bEveRstStabChk_IRV_MP;
Boolean AFAMgt_bInhAirModTmp_IRV_MP; 
Boolean AFAMgt_bInhAdpEfc;           
Boolean AFAMgt_bAcvAdpRstDiagRaw;    

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"


/* Block signals (auto storage) */
BlockIO_AFAMgtT AFAMgtT_B;

/* Block states (auto storage) */
D_Work_AFAMgtT AFAMgtT_DWork;


#define AFAMgtT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define AFAMGTT_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define AFAMGTT_VEMSRTLIBT_MINOR_VERSION_REQ 13
#define AFAMGTT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define AFAMGTT_VEMSRTLIBT_VERSION_REQ (AFAMGTT_VEMSRTLIBT_PATCH_VERSION_REQ + AFAMGTT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + AFAMGTT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if AFAMGTT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

void AFAMgtT_ASYNC1(int controlPortIdx)
{
}

void AFAMgtT_ASYNC2(int controlPortIdx)
{
}

void AFAMgtT_ASYNC3(int controlPortIdx)
{
}

void AFAMgtT_ASYNC4(int controlPortIdx)
{
}

void AFAMgtT_ASYNC5(int controlPortIdx)
{
}

/* Start for exported function: RE_AFAMgtT_002_MSE */
void RE_AFAMgtT_002_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/Runnable_3'
   *
   * Block requirements for '<S1>/Runnable_3':
   *  1. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_112.01 ;
   *  2. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_144.01 ;
   *  3. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_111.01 ;
   *  4. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_110.01 ;
   *  5. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_137.02 ;
   *  6. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_131.02 ;
   *  7. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_130.02 ;
   */
}

/* Output and update for exported function: RE_AFAMgtT_002_MSE */
void RE_AFAMgtT_002_MSE(void)
{
  /* local block i/o variables */
  UInt32 localAFAMgtT_F01_init_adaptatio;
  Boolean localNot;
  Boolean localNot_f;
  Boolean localAFAMgtT_F01_init_adaptat_i;
  Boolean localAFAMgtT_F01_init_adaptat_j;
  Boolean localRte_Call_R_FRM_bAcvAdpClcS;
  Boolean localSwitch;
  UInt32 localSignalConversion;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/Runnable_3'
   *
   * Block requirements for '<S1>/Runnable_3':
   *  1. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_112.01 ;
   *  2. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_144.01 ;
   *  3. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_111.01 ;
   *  4. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_110.01 ;
   *  5. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_137.02 ;
   *  6. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_131.02 ;
   *  7. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_130.02 ;
   */

  /* S-Function (sfun_autosar_clientop): '<S71>/Rte_Call_R_FRM_bAcvAdpValRstReq_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bAcvAdpValRstReq_GetFunctionPermission
    (&localRte_Call_R_FRM_bAcvAdpClcS);

  /* Logic: '<S71>/Not' */
  localNot = !localRte_Call_R_FRM_bAcvAdpClcS;

  /* S-Function (NvRamReadAccess): '<S10>/EepromReadAccess' */
  AFAMgtT_B.EepromReadAccess =
    AFAMgtT_sNV_Z1_CONST_8BIT.AFAMgt_bAcvAdpRstDiag_NV;

  /* S-Function (sfun_autosar_clientop): '<S70>/Rte_Call_R_FRM_bAcvAdpClcStRstReq_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bAcvAdpClcStRstReq_GetFunctionPermission
    (&localRte_Call_R_FRM_bAcvAdpClcS);

  /* Logic: '<S70>/Not' */
  localNot_f = !localRte_Call_R_FRM_bAcvAdpClcS;

  /* Outputs for atomic SubSystem: '<S10>/F01_init_adaptation_manager' *
   * Block requirements for '<S10>/F01_init_adaptation_manager':
   *  1. SubSystem "F01_init_adaptation_manager" !Trace_To : VEMS_R_11 _04434_048.01 ;
   */

  /* ModelReference: '<S69>/AFAMgtT_F01_init_adaptation_manager' */
  mr_AFAMgtT_F01_init_adaptation_(&localNot, &AFAMgtT_B.EepromReadAccess,
    &localNot_f, &localAFAMgtT_F01_init_adaptat_i,
    &localAFAMgtT_F01_init_adaptatio, &AFAMgtT_B.AFAMgtT_F01_init_adaptation_man,
    &localAFAMgtT_F01_init_adaptat_j);

  /* DataTypeConversion Block: '<S73>/Data Type Conversion'
   *
   * Regarding '<S73>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S74>/Data Type Conversion'
   *
   * Regarding '<S74>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S75>/Data Type Conversion'
   *
   * Regarding '<S75>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* end of Outputs for SubSystem: '<S10>/F01_init_adaptation_manager' */

  /* S-Function (NvRamWriteAccess): '<S10>/EepromWriteAccess' */
  AFAMgtT_sNV_Z1_CONST_8BIT.AFAMgt_bAcvAdpRstDiag_NV =
    AFAMgtT_B.AFAMgtT_F01_init_adaptation_man;

  /* SignalConversion: '<S72>/copy' */
  AFAMgt_tiDlyLstObsThd_IRV_MP = localAFAMgtT_F01_init_adaptatio;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S72>/autosar_testpoint1' */

  /* S-Function Block: <S72>/autosar_testpoint1 */

  /* SignalConversion: '<S10>/Signal Conversion' */
  localSignalConversion = localAFAMgtT_F01_init_adaptatio;

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S73>/Byp_Fonction_SC'
   *  Constant: '<S73>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch = AFAMgt_bAcvAdpRstDiag_B;
  } else {
    localSwitch = AFAMgtT_B.AFAMgtT_F01_init_adaptation_man;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFAMgt_bAcvAdpRstDiagInport2' */
  Rte_Write_P_AFAMgt_bAcvAdpRstDiag_AFAMgt_bAcvAdpRstDiag(localSwitch);

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S74>/Byp_Fonction_SC'
   *  Constant: '<S74>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch = AFAMgt_bAdpClcRstReq_B;
  } else {
    localSwitch = localAFAMgtT_F01_init_adaptat_j;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFAMgt_bAdpClcRstReqInport2' */
  Rte_Write_P_AFAMgt_bAdpClcRstReq_AFAMgt_bAdpClcRstReq(localSwitch);

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S75>/Byp_Fonction_SC'
   *  Constant: '<S75>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch = AFAMgt_bAdpOfsRstReq_B;
  } else {
    localSwitch = localAFAMgtT_F01_init_adaptat_i;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFAMgt_bAdpOfsRstReqInport2' */
  Rte_Write_P_AFAMgt_bAdpOfsRstReq_AFAMgt_bAdpOfsRstReq(localSwitch);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFAMgt_tiDlyLstObsThd_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_002_MSE_AFAMgt_tiDlyLstObsThd_irv
    (localSignalConversion);
}

/* Initial conditions for exported function: RE_AFAMgtT_003_TEV */
void RE_AFAMgtT_003_TEV_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Runnable_4'
   *
   * Block requirements for '<S1>/Runnable_4':
   *  1. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  2. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  3. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_085.01 ;
   *  4. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  5. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_093.01 ;
   *  6. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_099.01 ;
   *  7. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_100.01 ;
   *  8. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_072.01 ;
   *  9. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_073.01 ;
   *  10. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_071.01 ;
   *  11. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_123.02 ;
   *  12. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_122.02 ;
   *  13. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_119.02 ;
   *  14. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_124.02 ;
   *  15. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  16. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  17. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_108.01 ;
   *  18. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_144.01 ;
   *  19. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_103.01 ;
   *  20. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_096.02 ;
   *  21. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_102.01 ;
   *  22. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_104.01 ;
   *  23. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_106.01 ;
   *  24. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_105.01 ;
   *  25. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_107.01 ;
   *  26. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_094.01 ;
   *  27. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_095.01 ;
   *  28. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_109.01 ;
   *  29. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_125.02 ;
   *  30. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_089.02 ;
   *  31. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_090.01 ;
   *  32. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_091.01 ;
   *  33. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_092.01 ;
   *  34. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_126.02 ;
   *  35. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_088.01 ;
   *  36. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_101.01 ;
   *  37. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_075.01 ;
   *  38. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_110.01 ;
   *  39. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_111.01 ;
   *  40. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_118.01 ;
   *  41. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_117.01 ;
   *  42. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_115.01 ;
   *  43. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_116.01 ;
   *  44. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_114.01 ;
   *  45. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_113.01 ;
   *  46. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  47. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_155.01 ;
   *  48. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  49. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  50. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  51. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  52. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_138.02 ;
   *  53. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_128.02 ;
   *  54. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_129.02 ;
   *  55. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_130.02 ;
   *  56. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_133.02 ;
   *  57. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_134.02 ;
   *  58. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_135.02 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S11>/F02_supervise_adaptation_manager' *
   * Block requirements for '<S11>/F02_supervise_adaptation_manager':
   *  1. SubSystem "F02_supervise_adaptation_manager" !Trace_To : VEMS_R_11 _04434_049.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S79>/F02_supervise_adaptation_manager_chart' *
   * Block requirements for '<S79>/F02_supervise_adaptation_manager_chart':
   *  1. SubSystem "F02_supervise_adaptation_manager_chart" !Trace_To : VEMS_R_11 _04434_051.01 ;
   */

  /* InitializeConditions for Stateflow: '<S106>/F01_supervise_adaptation_manager_chart' incorporates:
   *  InitializeConditions for SubSystem: '<S11>/F01_AFAAdpCndChk'
   *  InitializeConditions for SubSystem: '<S11>/F01_adaptation_observations_delay'
   *  InitializeConditions for SubSystem: '<S11>/F02_command_observation'
   *  InitializeConditions for SubSystem: '<S11>/F03_check_air_mode_stability'
   *  InitializeConditions for SubSystem: '<S11>/F03_check_air_mode_stability1'
   *  InitializeConditions for SubSystem: '<S11>/F04_check_petrol_mode_stability'
   *  InitializeConditions for SubSystem: '<S11>/F04_check_petrol_mode_stability1'
   *
   * Block requirements for '<S11>/F01_AFAAdpCndChk':
   *  1. SubSystem "F01_AFAAdpCndChk" !Trace_To : VEMS_R_11 _04434_053.01 ;
   *
   * Block requirements for '<S11>/F01_adaptation_observations_delay':
   *  1. SubSystem "F01_adaptation_observations_delay" !Trace_To : VEMS_R_11 _04434_056.01 ;
   *
   * Block requirements for '<S11>/F02_command_observation':
   *  1. SubSystem "F02_command_observation" !Trace_To : VEMS_R_11 _04434_057.01 ;
   *
   * Block requirements for '<S11>/F03_check_air_mode_stability':
   *  1. SubSystem "F03_check_air_mode_stability" !Trace_To : VEMS_R_11 _04434_036.01 ;
   *
   * Block requirements for '<S11>/F03_check_air_mode_stability1':
   *  1. SubSystem "F03_check_air_mode_stability1" !Trace_To : VEMS_R_11 _04434_036.01 ;
   *
   * Block requirements for '<S11>/F04_check_petrol_mode_stability':
   *  1. SubSystem "F04_check_petrol_mode_stability" !Trace_To : VEMS_R_11 _04434_041.01 ;
   *
   * Block requirements for '<S11>/F04_check_petrol_mode_stability1':
   *  1. SubSystem "F04_check_petrol_mode_stability1" !Trace_To : VEMS_R_11 _04434_041.01 ;
   */
  /* InitializeConditions for ModelReference: '<S78>/AFAMgtT_F02_command_observation' */
  mr_AFAMgtT_F02_command_obs_Init(&AFAMgtT_B.AFAMgtT_F02_command_observati_p,
    &AFAMgtT_B.AFAMgtT_F02_command_observati_o);

  /* end of InitializeConditions for SubSystem: '<S79>/F02_supervise_adaptation_manager_chart' */

  /* end of InitializeConditions for SubSystem: '<S11>/F02_supervise_adaptation_manager' */
}

/* Start for exported function: RE_AFAMgtT_003_TEV */
void RE_AFAMgtT_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/Runnable_4'
   *
   * Block requirements for '<S1>/Runnable_4':
   *  1. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  2. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  3. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_085.01 ;
   *  4. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  5. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_093.01 ;
   *  6. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_099.01 ;
   *  7. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_100.01 ;
   *  8. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_072.01 ;
   *  9. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_073.01 ;
   *  10. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_071.01 ;
   *  11. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_123.02 ;
   *  12. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_122.02 ;
   *  13. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_119.02 ;
   *  14. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_124.02 ;
   *  15. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  16. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  17. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_108.01 ;
   *  18. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_144.01 ;
   *  19. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_103.01 ;
   *  20. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_096.02 ;
   *  21. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_102.01 ;
   *  22. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_104.01 ;
   *  23. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_106.01 ;
   *  24. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_105.01 ;
   *  25. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_107.01 ;
   *  26. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_094.01 ;
   *  27. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_095.01 ;
   *  28. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_109.01 ;
   *  29. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_125.02 ;
   *  30. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_089.02 ;
   *  31. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_090.01 ;
   *  32. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_091.01 ;
   *  33. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_092.01 ;
   *  34. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_126.02 ;
   *  35. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_088.01 ;
   *  36. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_101.01 ;
   *  37. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_075.01 ;
   *  38. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_110.01 ;
   *  39. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_111.01 ;
   *  40. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_118.01 ;
   *  41. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_117.01 ;
   *  42. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_115.01 ;
   *  43. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_116.01 ;
   *  44. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_114.01 ;
   *  45. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_113.01 ;
   *  46. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  47. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_155.01 ;
   *  48. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  49. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  50. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  51. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  52. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_138.02 ;
   *  53. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_128.02 ;
   *  54. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_129.02 ;
   *  55. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_130.02 ;
   *  56. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_133.02 ;
   *  57. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_134.02 ;
   *  58. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_135.02 ;
   */

  /* Start for atomic SubSystem: '<S11>/F02_supervise_adaptation_manager' *
   * Block requirements for '<S11>/F02_supervise_adaptation_manager':
   *  1. SubSystem "F02_supervise_adaptation_manager" !Trace_To : VEMS_R_11 _04434_049.01 ;
   */

  /* Start for Constant: '<S79>/AFAMgt_bInhAdpEfc_C' */
  AFAMgt_bInhAdpEfc = AFAMgt_bInhAdpEfc_C;

  /* end of Start for SubSystem: '<S11>/F02_supervise_adaptation_manager' */
}

/* Output and update for exported function: RE_AFAMgtT_003_TEV */
void RE_AFAMgtT_003_TEV(void)
{
  /* local block i/o variables */
  Boolean localRte_Call_R_FRM_bInhAFAObsA;
  Boolean localNot_d;
  Boolean localNot_n;
  Boolean localNot_c;
  Boolean localSignalConversion6;
  Boolean localTmpSignalConversionAtAfts_;
  Boolean localAFAMgt_bInhAFA;
  UInt32 localSignalConversion2;
  UInt32 localSignalConversion4;
  UInt32 localSignalConversion5;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/Runnable_4'
   *
   * Block requirements for '<S1>/Runnable_4':
   *  1. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  2. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  3. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_085.01 ;
   *  4. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  5. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_093.01 ;
   *  6. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_099.01 ;
   *  7. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_100.01 ;
   *  8. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_072.01 ;
   *  9. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_073.01 ;
   *  10. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_071.01 ;
   *  11. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_123.02 ;
   *  12. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_122.02 ;
   *  13. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_119.02 ;
   *  14. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_124.02 ;
   *  15. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  16. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  17. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_108.01 ;
   *  18. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_144.01 ;
   *  19. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_103.01 ;
   *  20. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_096.02 ;
   *  21. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_102.01 ;
   *  22. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_104.01 ;
   *  23. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_106.01 ;
   *  24. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_105.01 ;
   *  25. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_107.01 ;
   *  26. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_094.01 ;
   *  27. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_095.01 ;
   *  28. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_109.01 ;
   *  29. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_125.02 ;
   *  30. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_089.02 ;
   *  31. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_090.01 ;
   *  32. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_091.01 ;
   *  33. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_092.01 ;
   *  34. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_126.02 ;
   *  35. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_088.01 ;
   *  36. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_101.01 ;
   *  37. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_075.01 ;
   *  38. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_110.01 ;
   *  39. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_111.01 ;
   *  40. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_118.01 ;
   *  41. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_117.01 ;
   *  42. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_115.01 ;
   *  43. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_116.01 ;
   *  44. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_114.01 ;
   *  45. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_113.01 ;
   *  46. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  47. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_155.01 ;
   *  48. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  49. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  50. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  51. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  52. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_138.02 ;
   *  53. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_128.02 ;
   *  54. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_129.02 ;
   *  55. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_130.02 ;
   *  56. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_133.02 ;
   *  57. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_134.02 ;
   *  58. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_135.02 ;
   */

  /* S-Function (sfun_autosar_clientop): '<S88>/Rte_Call_R_FRM_bInhAFA_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bInhAFA_GetFunctionPermission(&localRte_Call_R_FRM_bInhAFAObsA);

  /* Logic: '<S88>/Not' */
  localNot_d = !localRte_Call_R_FRM_bInhAFAObsA;

  /* S-Function (sfun_autosar_clientop): '<S85>/Rte_Call_R_FRM_bActAFAAdpRst_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bActAFAAdpRst_GetFunctionPermission
    (&localRte_Call_R_FRM_bInhAFAObsA);

  /* Logic: '<S85>/Not' */
  localNot_n = !localRte_Call_R_FRM_bInhAFAObsA;

  /* S-Function (sfun_autosar_clientop): '<S86>/Rte_Call_R_FRM_bActAFAInjGainRst_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bActAFAInjGainRst_GetFunctionPermission
    (&localRte_Call_R_FRM_bInhAFAObsA);

  /* Logic: '<S86>/Not' */
  localNot_c = !localRte_Call_R_FRM_bInhAFAObsA;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bInhAFA_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bInhAFA_INPUT'
   */
  Rte_Read_R_AFAMgt_bInhAFA_AFAMgt_bInhAFA
    (&AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_h);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAfts_bAcvRstAFAOutport2' incorporates:
   *  Inport: '<Root>/Afts_bAcvRstAFA'
   */
  Rte_Read_R_Afts_bAcvRstAFA_Afts_bAcvRstAFA(&localTmpSignalConversionAtAfts_);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjSys_bAcvFuCllOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bAcvFuCll'
   */
  Rte_Read_R_InjSys_bAcvFuCll_InjSys_bAcvFuCll
    (&AFAMgtT_B.TmpSignalConversionAtInjSys_b_k);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_tiCntStabFuModPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt__lf =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_tiCntStabFuMod_irv();

  /* S-Function (sfun_autosar_clientop): '<S89>/Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission
    (&localRte_Call_R_FRM_bInhAFAObsA);

  /* Logic: '<S89>/Not' */
  AFAMgtT_B.Not_m = !localRte_Call_R_FRM_bInhAFAObsA;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_tiCntStabAirModPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt__me =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_tiCntStabAirMod_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bInhAirModPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_j =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bInhAirModTmp_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bStabAirLdCorOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_bSt =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bStabAirLdCor_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcStabRatOpEGROutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_bId =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bIdcStabRatOpEGR_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcNotDynCorPresOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_c =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bIdcNotDynCorPres_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bStabEgdGearOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_m =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bStabEgdGear_irv();

  /* SignalConversion: '<S11>/Signal Conversion9' incorporates:
   *  SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcStabAirModPrevOutport2'
   */
  AFAMgtT_B.Merge7_b = Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bIdcStabAirMod_irv();

  /* SignalConversion: '<S11>/Signal Conversion8' incorporates:
   *  SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcStabFuModPrevOutport2'
   */
  AFAMgtT_B.Merge8_p = Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bIdcStabFuMod_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtGSM_bAcvAFAAdpOutport2' incorporates:
   *  Inport: '<Root>/GSM_bAcvAFAAdp'
   */
  Rte_Read_R_GSM_bAcvAFAAdp_GSM_bAcvAFAAdp
    (&AFAMgtT_B.TmpSignalConversionAtGSM_bAcvAF);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_tiDlyLstObsThdPrevOutport2' */
  AFAMgtT_B.Merge6 = Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_tiDlyLstObsThd_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&AFAMgtT_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_tiDlyLstObsOutport2' incorporates:
   *  Inport: '<Root>/AFA_tiDlyLstObs'
   */
  Rte_Read_R_AFA_tiDlyLstObs_AFA_tiDlyLstObs
    (&AFAMgtT_B.TmpSignalConversionAtAFA_tiDlyL);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_rTotLdExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rTotLdExCor'
   */
  Rte_Read_R_EngM_rTotLdExCor_EngM_rTotLdExCor
    (&AFAMgtT_B.TmpSignalConversionAtEngM_rTotL);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_pDsThrMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pDsThrMesSI'
   */
  Rte_Read_R_Ext_pDsThrMesSI_Ext_pDsThrMesSI
    (&AFAMgtT_B.TmpSignalConversionAtExt_pDsThr);

  /* S-Function (sfun_autosar_clientop): '<S87>/Rte_Call_R_FRM_bInhAFAObsAdp_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bInhAFAObsAdp_GetFunctionPermission
    (&localRte_Call_R_FRM_bInhAFAObsA);

  /* Logic: '<S87>/Not' */
  AFAMgtT_B.Not_p = !localRte_Call_R_FRM_bInhAFAObsA;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_tDsThrMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tDsThrMes'
   */
  Rte_Read_R_Ext_tDsThrMes_Ext_tDsThrMes
    (&AFAMgtT_B.TmpSignalConversionAtExt_tDsThr);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&AFAMgtT_B.TmpSignalConversionAtExt_tCoMes);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_bAuthClsCanPurgOutport2' incorporates:
   *  Inport: '<Root>/AFA_bAuthClsCanPurg'
   */
  Rte_Read_R_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg
    (&AFAMgtT_B.TmpSignalConversionAtAFA_bAuthC);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp
    (&AFAMgtT_B.TmpSignalConversionAtFARSp_rMix);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_nEngLstObsOutport2' incorporates:
   *  Inport: '<Root>/AFA_nEngLstObs'
   */
  Rte_Read_R_AFA_nEngLstObs_AFA_nEngLstObs
    (&AFAMgtT_B.TmpSignalConversionAtAFA_nEngLs);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_rTotLdCorLstObsOutport2' incorporates:
   *  Inport: '<Root>/AFA_rTotLdCorLstObs'
   */
  Rte_Read_R_AFA_rTotLdCorLstObs_AFA_rTotLdCorLstObs
    (&AFAMgtT_B.TmpSignalConversionAtAFA_rTotLd);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&AFAMgtT_B.TmpSignalConversionAtUsThrM_pAi);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bStabEOMOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt__j2 =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bStabEOM_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_rDeltaLdInjPhaOutport2' incorporates:
   *  Inport: '<Root>/EngM_rDeltaLdInjPha'
   */
  Rte_Read_R_EngM_rDeltaLdInjPha_EngM_rDeltaLdInjPha
    (&AFAMgtT_B.TmpSignalConversionAtEngM_rDelt);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjrM_prm_facCorGainLnrOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_facCorGainLnr'
   */
  Rte_Read_R_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr
    (&AFAMgtT_B.TmpSignalConversionAtInjrM_prm_);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjrM_prm_pDifInjrOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_pDifInjr'
   */
  Rte_Read_R_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr
    (&AFAMgtT_B.TmpSignalConversionAtInjrM_pr_o);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjrSys_prm_tiInjOutport2' incorporates:
   *  Inport: '<Root>/InjrSys_prm_tiInj'
   */
  Rte_Read_R_InjrSys_prm_tiInj_InjrSys_prm_tiInj
    (&AFAMgtT_B.TmpSignalConversionAtInjrSys_pr);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bStabFacStrtCorOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_g =
    Rte_IrvRead_RE_AFAMgtT_003_TEV_AFAMgt_bStabFacStrtCor_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtBlby_bIdcWoutBlbyCndOutport2' incorporates:
   *  Inport: '<Root>/Blby_bIdcWoutBlbyCnd'
   */
  Rte_Read_R_Blby_bIdcWoutBlbyCnd_Blby_bIdcWoutBlbyCnd
    (&AFAMgtT_B.TmpSignalConversionAtBlby_bIdcW);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_rltMassAirScvCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rltMassAirScvCor'
   */
  Rte_Read_R_EngM_rltMassAirScvCor_EngM_rltMassAirScvCor
    (&AFAMgtT_B.TmpSignalConversionAtEngM_rltMa);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCanPurg_concFuStmErrOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_concFuStmErr'
   */
  Rte_Read_R_CanPurg_concFuStmErr_CanPurg_concFuStmErr
    (&AFAMgtT_B.TmpSignalConversionAtCanPurg_co);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCanPurg_concFuStmEstimOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_concFuStmEstim'
   */
  Rte_Read_R_CanPurg_concFuStmEstim_CanPurg_concFuStmEstim
    (&AFAMgtT_B.TmpSignalConversionAtCanPurg__h);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_noAdpEfcOutport2' incorporates:
   *  Inport: '<Root>/AFA_noAdpEfc'
   */
  Rte_Read_R_AFA_noAdpEfc_AFA_noAdpEfc
    (&AFAMgtT_B.TmpSignalConversionAtAFA_noAdpE);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_noObsDoneOutport2' incorporates:
   *  Inport: '<Root>/AFA_noObsDone'
   */
  Rte_Read_R_AFA_noObsDone_AFA_noObsDone
    (&AFAMgtT_B.TmpSignalConversionAtAFA_noObsD);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_bIdcCohLstObsOutport2' incorporates:
   *  Inport: '<Root>/AFA_bIdcCohLstObs'
   */
  Rte_Read_R_AFA_bIdcCohLstObs_AFA_bIdcCohLstObs
    (&AFAMgtT_B.TmpSignalConversionAtAFA_bIdcCo);

  /* Outputs for atomic SubSystem: '<S11>/F02_supervise_adaptation_manager' *
   * Block requirements for '<S11>/F02_supervise_adaptation_manager':
   *  1. SubSystem "F02_supervise_adaptation_manager" !Trace_To : VEMS_R_11 _04434_049.01 ;
   */

  /* Constant: '<S79>/AFAMgt_bInhAdpEfc_C' */
  AFAMgt_bInhAdpEfc = AFAMgt_bInhAdpEfc_C;

  /* Outputs for atomic SubSystem: '<S79>/F01_Inhibition_management' *
   * Block requirements for '<S79>/F01_Inhibition_management':
   *  1. SubSystem "F01_Inhibition_management" !Trace_To : VEMS_R_11 _04434_050.01 ;
   */

  /* Logic: '<S105>/Logical Operator' incorporates:
   *  Constant: '<S105>/AFAMgt_bInhAFA_C'
   */
  localAFAMgt_bInhAFA = ((localNot_d) || AFAMgt_bInhAFA_C);

  /* end of Outputs for SubSystem: '<S79>/F01_Inhibition_management' */

  /* Outputs for atomic SubSystem: '<S79>/F02_supervise_adaptation_manager_chart' *
   * Block requirements for '<S79>/F02_supervise_adaptation_manager_chart':
   *  1. SubSystem "F02_supervise_adaptation_manager_chart" !Trace_To : VEMS_R_11 _04434_051.01 ;
   */

  /* Stateflow: '<S106>/F01_supervise_adaptation_manager_chart' incorporates:
   *  SubSystem: '<S11>/F01_AFAAdpCndChk'
   *  SubSystem: '<S11>/F01_adaptation_observations_delay'
   *  SubSystem: '<S11>/F02_command_observation'
   *  SubSystem: '<S11>/F03_check_air_mode_stability'
   *  SubSystem: '<S11>/F03_check_air_mode_stability1'
   *  SubSystem: '<S11>/F04_check_petrol_mode_stability'
   *  SubSystem: '<S11>/F04_check_petrol_mode_stability1'
   *
   * Block requirements for '<S11>/F01_AFAAdpCndChk':
   *  1. SubSystem "F01_AFAAdpCndChk" !Trace_To : VEMS_R_11 _04434_053.01 ;
   *
   * Block requirements for '<S11>/F01_adaptation_observations_delay':
   *  1. SubSystem "F01_adaptation_observations_delay" !Trace_To : VEMS_R_11 _04434_056.01 ;
   *
   * Block requirements for '<S11>/F02_command_observation':
   *  1. SubSystem "F02_command_observation" !Trace_To : VEMS_R_11 _04434_057.01 ;
   *
   * Block requirements for '<S11>/F03_check_air_mode_stability':
   *  1. SubSystem "F03_check_air_mode_stability" !Trace_To : VEMS_R_11 _04434_036.01 ;
   *
   * Block requirements for '<S11>/F03_check_air_mode_stability1':
   *  1. SubSystem "F03_check_air_mode_stability1" !Trace_To : VEMS_R_11 _04434_036.01 ;
   *
   * Block requirements for '<S11>/F04_check_petrol_mode_stability':
   *  1. SubSystem "F04_check_petrol_mode_stability" !Trace_To : VEMS_R_11 _04434_041.01 ;
   *
   * Block requirements for '<S11>/F04_check_petrol_mode_stability1':
   *  1. SubSystem "F04_check_petrol_mode_stability1" !Trace_To : VEMS_R_11 _04434_041.01 ;
   */
  /* Gateway: AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F02_supervise_adaptation_manager_chart/F01_supervise_adaptation_manager_chart */
  /* During: AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F02_supervise_adaptation_manager_chart/F01_supervise_adaptation_manager_chart */
  /* Transition: '<S108>:8' */
  if (((SInt32)localAFAMgt_bInhAFA) == 0) {
    /* Transition: '<S108>:15' */
    /* Event: '<S108>:36' */

    /* ModelReference: '<S80>/AFAMgtT_F03_check_air_mode_stability' */
    mr_AFAMgtT_F03_check_air_mode_s(&AFAMgtT_B.Not_m, &AFAMgtT_B.Merge4_p,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_h,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt__me,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_j, &AFAMgtT_B.Merge7_b,
      &AFAMgtT_B.Merge1, &AFAMgtT_B.Merge2_c);

    /* Event: '<S108>:37' */

    /* ModelReference: '<S82>/AFAMgtT_F04_check_petrol_mode_stability' */
    mr_AFAMgtT_F04_check_petrol_mod(&AFAMgtT_B.TmpSignalConversionAtInjSys_b_k,
      &AFAMgtT_B.Merge4_p, &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_h,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt__lf, &AFAMgtT_B.Merge8_p,
      &AFAMgtT_B.Merge4_p, &AFAMgtT_B.Merge5);

    /* Event: '<S108>:38' */

    /* ModelReference: '<S77>/AFAMgtT_F01_adaptation_observations_delay' */
    mr_AFAMgtT_F01_adaptation_obser(&AFAMgtT_B.TmpSignalConversionAtAFA_bAuthC,
      &AFAMgtT_B.TmpSignalConversionAtCanPurg_co,
      &AFAMgtT_B.TmpSignalConversionAtCanPurg__h, &AFAMgtT_B.Merge6);

    /* Event: '<S108>:39' */

    /* ModelReference: '<S78>/AFAMgtT_F02_command_observation' */
    mr_AFAMgtT_F02_command_observat(&AFAMgtT_B.TmpSignalConversionAtAFAMgt_bSt,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt_bId,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_c,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_m, &AFAMgtT_B.Merge7_b,
      &AFAMgtT_B.Merge8_p, &AFAMgtT_B.TmpSignalConversionAtGSM_bAcvAF,
      &AFAMgtT_B.Merge6, &AFAMgtT_B.TmpSignalConversionAtExt_nEngOu,
      &AFAMgtT_B.TmpSignalConversionAtAFA_tiDlyL,
      &AFAMgtT_B.TmpSignalConversionAtEngM_rTotL,
      &AFAMgtT_B.TmpSignalConversionAtExt_pDsThr, &AFAMgtT_B.Not_p,
      &AFAMgtT_B.TmpSignalConversionAtExt_tDsThr,
      &AFAMgtT_B.TmpSignalConversionAtExt_tCoMes,
      &AFAMgtT_B.TmpSignalConversionAtAFA_bAuthC,
      &AFAMgtT_B.TmpSignalConversionAtFARSp_rMix,
      &AFAMgtT_B.TmpSignalConversionAtAFA_nEngLs,
      &AFAMgtT_B.TmpSignalConversionAtAFA_rTotLd,
      &AFAMgtT_B.TmpSignalConversionAtUsThrM_pAi,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt__j2,
      &AFAMgtT_B.TmpSignalConversionAtEngM_rDelt,
      AFAMgtT_B.TmpSignalConversionAtInjrM_prm_,
      AFAMgtT_B.TmpSignalConversionAtInjrM_pr_o,
      AFAMgtT_B.TmpSignalConversionAtInjrSys_pr,
      &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_g,
      &AFAMgtT_B.TmpSignalConversionAtBlby_bIdcW,
      &AFAMgtT_B.TmpSignalConversionAtEngM_rltMa,
      &AFAMgtT_B.AFAMgtT_F02_command_observati_i,
      &AFAMgtT_B.AFAMgtT_F02_command_observati_k,
      &AFAMgtT_B.AFAMgtT_F02_command_observati_p,
      &AFAMgtT_B.AFAMgtT_F02_command_observati_o,
      &AFAMgtT_B.AFAMgtT_F02_command_observat_k4,
      &AFAMgtT_B.AFAMgtT_F02_command_observati_g);

    /* DataTypeConversion Block: '<S101>/Data Type Conversion'
     *
     * Regarding '<S101>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S102>/Data Type Conversion'
     *
     * Regarding '<S102>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S103>/Data Type Conversion'
     *
     * Regarding '<S103>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S104>/Data Type Conversion'
     *
     * Regarding '<S104>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */
    if (((SInt32)AFAMgtT_DWork.AFAMgt_bActAFAAdpRstPrev) == 0) {
      /* Transition: '<S108>:7' */
      AFAMgtT_B.AFAMgt_bAdpClcRstReq = localNot_n;
      if ((((SInt32)localNot_n) == 1) || (((SInt32)localNot_c) == 1)) {
        /* Transition: '<S108>:5' */
        AFAMgt_bAcvAdpRstDiagRaw = TRUE;

        /* Transition: '<S108>:6' */
      } else {
        /* Transition: '<S108>:14' */
      }
    } else {
      /* Transition: '<S108>:9' */
      if ((((SInt32)localNot_n) == 0) && (((SInt32)localNot_c) == 0)) {
        /* Transition: '<S108>:1' */
        AFAMgt_bAcvAdpRstDiagRaw = FALSE;

        /* Transition: '<S108>:10' */
      } else {
        /* Transition: '<S108>:12' */
      }
    }

    /* Transition: '<S108>:4' */
    AFAMgtT_DWork.AFAMgt_bActAFAAdpRstPrev = ((((SInt32)localNot_n) | ((SInt32)
      localNot_c)) != 0);
    if (((SInt32)AFAMgt_bInhAdpEfc) == 0) {
      /* Transition: '<S108>:3' */
      /* Event: '<S108>:40' */

      /* ModelReference: '<S76>/AFAMgtT_F01_AFAAdpCndChk' */
      mr_AFAMgtT_F01_AFAAdpCndChk(&AFAMgtT_B.TmpSignalConversionAtAFA_noAdpE,
        &AFAMgtT_B.TmpSignalConversionAtAFA_noObsD,
        &AFAMgtT_B.TmpSignalConversionAtAFA_bIdcCo,
        &AFAMgtT_B.AFAMgtT_F01_AFAAdpCndChk_h);

      /* DataTypeConversion Block: '<S100>/Data Type Conversion'
       *
       * Regarding '<S100>/Data Type Conversion':
       *   Eliminate redundant data type conversion
       */

      /* Transition: '<S108>:11' */
    } else {
      /* Transition: '<S108>:13' */
    }

    /* Transition: '<S108>:2' */
  } else {
    if (1 != ((SInt32)AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_h)) {
      /* Transition: '<S108>:16' */
      /* Event: '<S108>:41' */

      /* ModelReference: '<S81>/AFAMgtT_F03_check_air_mode_stability' */
      mr_AFAMgtT_F03_check_air_mode_s(&AFAMgtT_B.Not_m, &AFAMgtT_B.Merge4_p,
        &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_h,
        &AFAMgtT_B.TmpSignalConversionAtAFAMgt__me,
        &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_j, &AFAMgtT_B.Merge7_b,
        &AFAMgtT_B.Merge1, &AFAMgtT_B.Merge2_c);

      /* Event: '<S108>:42' */

      /* ModelReference: '<S83>/AFAMgtT_F04_check_petrol_mode_stability' */
      mr_AFAMgtT_F04_check_petrol_mod(&AFAMgtT_B.TmpSignalConversionAtInjSys_b_k,
        &AFAMgtT_B.Merge4_p, &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_h,
        &AFAMgtT_B.TmpSignalConversionAtAFAMgt__lf, &AFAMgtT_B.Merge8_p,
        &AFAMgtT_B.Merge4_p, &AFAMgtT_B.Merge5);
    }
  }

  /* end of Outputs for SubSystem: '<S79>/F02_supervise_adaptation_manager_chart' */

  /* If: '<S107>/If' incorporates:
   *  ActionPort: '<S109>/Action Port'
   *  ActionPort: '<S110>/Action Port'
   *  SubSystem: '<S107>/F01_After_sale_action'
   *  SubSystem: '<S107>/F02_No_after_sale_action'
   */
  if (localTmpSignalConversionAtAfts_) {
    /* Constant: '<S109>/Constant' */
    AFAMgtT_B.Merge_m = TRUE;
  } else {
    /* SignalConversion: '<S110>/Signal Conversion' */
    AFAMgtT_B.Merge_m = AFAMgt_bAcvAdpRstDiagRaw;
  }

  /* end of Outputs for SubSystem: '<S11>/F02_supervise_adaptation_manager' */

  /* S-Function (NvRamWriteAccess): '<S11>/EepromWriteAccess' */
  AFAMgtT_sNV_Z1_CONST_8BIT.AFAMgt_bAcvAdpRstDiag_NV = AFAMgtT_B.Merge_m;

  /* If: '<S84>/If' incorporates:
   *  ActionPort: '<S111>/Action Port'
   *  Constant: '<S11>/AFAMGTT_ACTIVE_BYP_C'
   *  SubSystem: '<S84>/If_s'
   */
  if (!AFAMGTT_ACTIVE_BYP_C) {
    /* If: '<S111>/If' incorporates:
     *  ActionPort: '<S112>/Action Port'
     *  ActionPort: '<S113>/Action Port'
     *  SubSystem: '<S111>/if_s1'
     *  SubSystem: '<S111>/if_s2'
     */
    if (AFAMgtT_B.AFAMgtT_F02_command_observati_o) {
      /* If: '<S112>/If' incorporates:
       *  ActionPort: '<S114>/Action Port'
       *  ActionPort: '<S115>/Action Port'
       *  SubSystem: '<S112>/if_s1'
       *  SubSystem: '<S112>/if_s2'
       */
      if (AFAMgtT_B.AFAMgtT_F02_command_observati_p) {
        /* S-Function (sfun_autosar_clientop): '<S114>/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus_sf' incorporates:
         *  Constant: '<S114>/Constant1'
         */
        Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
      } else {
        /* S-Function (sfun_autosar_clientop): '<S115>/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus_sf' incorporates:
         *  Constant: '<S115>/Constant2'
         */
        Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
      }
    } else {
      /* If: '<S113>/If' incorporates:
       *  ActionPort: '<S116>/Action Port'
       *  Memory: '<S111>/Memory'
       *  SubSystem: '<S113>/If Action Subsystem'
       */
      if (AFAMgtT_DWork.Memory_PreviousInput) {
        /* S-Function (sfun_autosar_clientop): '<S116>/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus_sf' incorporates:
         *  Constant: '<S116>/Constant3'
         */
        Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus(DEM_EVENT_STATUS_INIT);
      }
    }

    /* Update for Memory: '<S111>/Memory' */
    AFAMgtT_DWork.Memory_PreviousInput =
      AFAMgtT_B.AFAMgtT_F02_command_observati_o;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S90>/autosar_testpoint1' */

  /* S-Function Block: <S90>/autosar_testpoint1 */
  AFAMgt_tiDlyLstObsThd_IRV_MP = AFAMgtT_B.Merge6;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S91>/autosar_testpoint1' */

  /* S-Function Block: <S91>/autosar_testpoint1 */
  AFAMgt_bIdcStabAirMod_IRV_MP = AFAMgtT_B.Merge7_b;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S92>/autosar_testpoint1' */

  /* S-Function Block: <S92>/autosar_testpoint1 */
  AFAMgt_bIdcStabFuMod_IRV_MP = AFAMgtT_B.Merge8_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S93>/autosar_testpoint1' */

  /* S-Function Block: <S93>/autosar_testpoint1 */
  AFAMgt_bEveRstStabChk_IRV_MP = AFAMgtT_B.Merge4_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S94>/autosar_testpoint1' */

  /* S-Function Block: <S94>/autosar_testpoint1 */
  AFAMgt_tiCntStabFuMod_IRV_MP = AFAMgtT_B.Merge5;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S95>/autosar_testpoint1' */

  /* S-Function Block: <S95>/autosar_testpoint1 */
  AFAMgt_tiCntStabAirMod_IRV_MP = AFAMgtT_B.Merge1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S96>/autosar_testpoint1' */

  /* S-Function Block: <S96>/autosar_testpoint1 */
  AFAMgt_bInhAirModTmp_IRV_MP = AFAMgtT_B.Merge2_c;

  /* SignalConversion: '<S11>/Signal Conversion1' */
  localNot_c = AFAMgtT_B.Merge8_p;

  /* SignalConversion: '<S11>/Signal Conversion2' */
  localSignalConversion2 = AFAMgtT_B.Merge6;

  /* SignalConversion: '<S11>/Signal Conversion3' */
  localNot_n = AFAMgtT_B.Merge4_p;

  /* SignalConversion: '<S11>/Signal Conversion4' */
  localSignalConversion4 = AFAMgtT_B.Merge5;

  /* SignalConversion: '<S11>/Signal Conversion5' */
  localSignalConversion5 = AFAMgtT_B.Merge1;

  /* SignalConversion: '<S11>/Signal Conversion6' */
  localSignalConversion6 = AFAMgtT_B.Merge2_c;

  /* SignalConversion: '<S11>/Signal Conversion7' */
  localTmpSignalConversionAtAfts_ = AFAMgtT_B.Merge7_b;

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/Byp_Fonction_SC'
   *  Constant: '<S97>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localNot_d = AFAMgt_bAcvAdpRstDiag_B;
  } else {
    localNot_d = AFAMgtT_B.Merge_m;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bAcvAdpRstDiagInport2' */
  Rte_Write_P_AFAMgt_bAcvAdpRstDiag_AFAMgt_bAcvAdpRstDiag(localNot_d);

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S98>/Byp_Fonction_SC'
   *  Constant: '<S98>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localNot_d = AFAMgt_bAdpClcRstReq_B;
  } else {
    localNot_d = AFAMgtT_B.AFAMgt_bAdpClcRstReq;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bAdpClcRstReqInport2' */
  Rte_Write_P_AFAMgt_bAdpClcRstReq_AFAMgt_bAdpClcRstReq(localNot_d);

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S100>/Byp_Fonction_SC'
   *  Constant: '<S100>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localNot_d = AFAMgt_bAdpEfcReq_B;
  } else {
    localNot_d = AFAMgtT_B.AFAMgtT_F01_AFAAdpCndChk_h;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bAdpEfcReqInport2' */
  Rte_Write_P_AFAMgt_bAdpEfcReq_AFAMgt_bAdpEfcReq(localNot_d);

  /* Switch: '<S102>/Switch' incorporates:
   *  Constant: '<S102>/Byp_Fonction_SC'
   *  Constant: '<S102>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localNot_d = AFAMgt_bAdpObsReq_B;
  } else {
    localNot_d = AFAMgtT_B.AFAMgtT_F02_command_observati_g;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bAdpObsReqInport2' */
  Rte_Write_P_AFAMgt_bAdpObsReq_AFAMgt_bAdpObsReq(localNot_d);

  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S101>/Byp_Fonction_SC'
   *  Constant: '<S101>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localNot_d = AFAMgt_bAuthAdpReq_B;
  } else {
    localNot_d = AFAMgtT_B.AFAMgtT_F02_command_observat_k4;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bAuthAdpReqInport2' */
  Rte_Write_P_AFAMgt_bAuthAdpReq_AFAMgt_bAuthAdpReq(localNot_d);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bEveRstStabChk_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_003_TEV_AFAMgt_bEveRstStabChk_irv(localNot_n);

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S103>/Byp_Fonction_SC'
   *  Constant: '<S103>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localNot_d = AFAMgt_bIdcInjrMdlCnd_B;
  } else {
    localNot_d = AFAMgtT_B.AFAMgtT_F02_command_observati_k;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcInjrMdlCndInport2' */
  Rte_Write_P_AFAMgt_bIdcInjrMdlCnd_AFAMgt_bIdcInjrMdlCnd(localNot_d);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcStabAirMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_003_TEV_AFAMgt_bIdcStabAirMod_irv
    (localTmpSignalConversionAtAfts_);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcStabFuMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_003_TEV_AFAMgt_bIdcStabFuMod_irv(localNot_c);

  /* Switch: '<S104>/Switch' incorporates:
   *  Constant: '<S104>/Byp_Fonction_SC'
   *  Constant: '<S104>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localNot_d = AFAMgt_bIdcTmpObsCnd_B;
  } else {
    localNot_d = AFAMgtT_B.AFAMgtT_F02_command_observati_i;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bIdcTmpObsCndInport2' */
  Rte_Write_P_AFAMgt_bIdcTmpObsCnd_AFAMgt_bIdcTmpObsCnd(localNot_d);

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Byp_Fonction_SC'
   *  Constant: '<S99>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localAFAMgt_bInhAFA = AFAMgt_bInhAFA_B;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bInhAFAInport2' */
  Rte_Write_P_AFAMgt_bInhAFA_AFAMgt_bInhAFA(localAFAMgt_bInhAFA);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_bInhAirModTmp_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_003_TEV_AFAMgt_bInhAirModTmp_irv
    (localSignalConversion6);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_tiCntStabAirMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_003_TEV_AFAMgt_tiCntStabAirMod_irv
    (localSignalConversion5);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_tiCntStabFuMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_003_TEV_AFAMgt_tiCntStabFuMod_irv
    (localSignalConversion4);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFAMgt_tiDlyLstObsThd_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_003_TEV_AFAMgt_tiDlyLstObsThd_irv
    (localSignalConversion2);
}

/* Start for exported function: RE_AFAMgtT_004_MSE */
void RE_AFAMgtT_004_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/Runnable_2'
   *
   * Block requirements for '<S1>/Runnable_2':
   *  1. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  2. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  3. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_085.01 ;
   *  4. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  5. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_083.01 ;
   *  6. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_082.01 ;
   *  7. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_081.01 ;
   *  8. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_087.01 ;
   *  9. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_080.01 ;
   *  10. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_084.01 ;
   *  11. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_086.01 ;
   *  12. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_075.01 ;
   *  13. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_145.01 ;
   *  14. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_146.01 ;
   *  15. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_147.01 ;
   *  16. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_148.01 ;
   *  17. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_159.01 ;
   *  18. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_149.01 ;
   *  19. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_160.01 ;
   *  20. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_150.01 ;
   *  21. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_151.01 ;
   *  22. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_152.01 ;
   *  23. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_153.01 ;
   *  24. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_154.01 ;
   *  25. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  26. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  27. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_155.01 ;
   *  28. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  29. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_123.02 ;
   *  30. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_122.02 ;
   *  31. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_119.02 ;
   *  32. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_124.02 ;
   *  33. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_125.02 ;
   *  34. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_126.02 ;
   *  35. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_139.02 ;
   *  36. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_135.02 ;
   */

  /* Start for atomic SubSystem: '<S9>/F01_InitStabChk' *
   * Block requirements for '<S9>/F01_InitStabChk':
   *  1. SubSystem "F01_InitStabChk" !Trace_To : VEMS_R_11 _04434_003.01 ;
   */

  /* Start for Embedded MATLAB: '<S38>/Task_sceduler' incorporates:
   *  Start for SubSystem: '<S9>/F02_check_stability_SdlMid'
   *  Start for SubSystem: '<S9>/F03_check_air_mode_stability'
   *  Start for SubSystem: '<S9>/F04_check_petrol_mode_stability'
   *
   * Block requirements for '<S9>/F02_check_stability_SdlMid':
   *  1. SubSystem "F02_check_stability_SdlMid" !Trace_To : VEMS_R_11 _04434_004.01 ;
   *
   * Block requirements for '<S9>/F03_check_air_mode_stability':
   *  1. SubSystem "F03_check_air_mode_stability" !Trace_To : VEMS_R_11 _04434_036.01 ;
   *
   * Block requirements for '<S9>/F04_check_petrol_mode_stability':
   *  1. SubSystem "F04_check_petrol_mode_stability" !Trace_To : VEMS_R_11 _04434_041.01 ;
   */

  /* end of Start for SubSystem: '<S9>/F01_InitStabChk' */

  /* Constant: '<S9>/Constant1' */
  AFAMgtT_B.Merge = TRUE;
}

/* Output and update for exported function: RE_AFAMgtT_004_MSE */
void RE_AFAMgtT_004_MSE(void)
{
  /* local block i/o variables */
  Boolean localLogicalOperator;
  Boolean localRte_Call_R_FRM_bInhInMNomM;
  Boolean localSignalConversion_n;
  Boolean localSignalConversion1_o;
  UInt8 localSignalConversion16;
  Boolean localSignalConversion17;
  Boolean localSignalConversion2_c;
  Boolean localSignalConversion23;
  Boolean localSignalConversion3_h;
  Boolean localSignalConversion4_d;
  Boolean localSignalConversion5_e;
  Boolean localSignalConversion6_d;
  Boolean localSignalConversion7_h;
  UInt32 localSignalConversion10;
  UInt8 localSignalConversion11;
  UInt8 localSignalConversion12;
  UInt32 localSignalConversion13;
  UInt32 localSignalConversion14;
  UInt32 localSignalConversion15;
  UInt32 localSignalConversion18;
  UInt32 localSignalConversion19;
  UInt32 localSignalConversion21;
  UInt32 localSignalConversion22;
  UInt16 localSignalConversion8;
  UInt16 localSignalConversion9;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/Runnable_2'
   *
   * Block requirements for '<S1>/Runnable_2':
   *  1. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_157.01 ;
   *  2. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_158.01 ;
   *  3. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_085.01 ;
   *  4. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  5. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_083.01 ;
   *  6. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_082.01 ;
   *  7. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_081.01 ;
   *  8. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_087.01 ;
   *  9. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_080.01 ;
   *  10. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_084.01 ;
   *  11. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_086.01 ;
   *  12. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_075.01 ;
   *  13. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_145.01 ;
   *  14. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_146.01 ;
   *  15. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_147.01 ;
   *  16. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_148.01 ;
   *  17. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_159.01 ;
   *  18. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_149.01 ;
   *  19. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_160.01 ;
   *  20. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_150.01 ;
   *  21. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_151.01 ;
   *  22. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_152.01 ;
   *  23. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_153.01 ;
   *  24. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_154.01 ;
   *  25. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_120.01 ;
   *  26. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_121.01 ;
   *  27. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_155.01 ;
   *  28. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_156.01 ;
   *  29. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_123.02 ;
   *  30. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_122.02 ;
   *  31. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_119.02 ;
   *  32. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_124.02 ;
   *  33. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_125.02 ;
   *  34. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_126.02 ;
   *  35. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_139.02 ;
   *  36. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_135.02 ;
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor
    (&AFAMgtT_B.TmpSignalConversionAtEngM_rAirL);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEGRVlv_stEGRModOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_stEGRMod'
   */
  Rte_Read_R_EGRVlv_stEGRMod_EGRVlv_stEGRMod
    (&AFAMgtT_B.TmpSignalConversionAtEGRVlv_stE);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEGRSys_rEGRReqOutport2' incorporates:
   *  Inport: '<Root>/EGRSys_rEGRReq'
   */
  Rte_Read_R_EGRSys_rEGRReq_EGRSys_rEGRReq
    (&AFAMgtT_B.TmpSignalConversionAtEGRSys_rEG);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInM_pDynCorPresOutport2' incorporates:
   *  Inport: '<Root>/InM_pDynCorPres'
   */
  Rte_Read_R_InM_pDynCorPres_InM_pDynCorPres
    (&AFAMgtT_B.TmpSignalConversionAtInM_pDynCo);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtCoPt_noEgdGearCordOutport2' incorporates:
   *  Inport: '<Root>/CoPt_noEgdGearCord'
   */
  Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord
    (&AFAMgtT_B.TmpSignalConversionAtCoPt_noEgd);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEOM_bTranModOutport2' incorporates:
   *  Inport: '<Root>/EOM_bTranMod'
   */
  Rte_Read_R_EOM_bTranMod_EOM_bTranMod
    (&AFAMgtT_B.TmpSignalConversionAtEOM_bTranM);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInjSys_prm_facStrtCorCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_facStrtCorCyl'
   */
  Rte_Read_R_InjSys_prm_facStrtCorCyl_InjSys_prm_facStrtCorCyl
    (&AFAMgtT_B.TmpSignalConversionAtInjSys_prm);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bInhAFAOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bInhAFA_INPUT'
   */
  Rte_Read_R_AFAMgt_bInhAFA_AFAMgt_bInhAFA
    (&AFAMgtT_B.TmpSignalConversionAtAFAMgt_bIn);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rAirLdMaxPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_rAi =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_rAirLdMax_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rAirLdMinPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_r_j =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_rAirLdMin_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabAirLdPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_tiC =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabAirLd_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rEGRMaxPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_rEG =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_rEGRMax_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rEGRMinPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_r_f =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_rEGRMin_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabRatOpEGRPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_h =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabRatOpEGR_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntNotDynCorPresPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_l =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntNotDynCorPres_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabEgdGearPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_k =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabEgdGear_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_noEgdGearCordPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_noE =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_noEgdGearCordHld_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bTranModPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_bTr =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_bTranModHld_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabEOMPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_b =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabEOM_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabFacStrtPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_m =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabFacStrt_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInjSys_bAcvFuCllOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bAcvFuCll'
   */
  Rte_Read_R_InjSys_bAcvFuCll_InjSys_bAcvFuCll
    (&AFAMgtT_B.TmpSignalConversionAtInjSys_bAc);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabFuModPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_f =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabFuMod_irv();

  /* S-Function (sfun_autosar_clientop): '<S42>/Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission
    (&localRte_Call_R_FRM_bInhInMNomM);

  /* Logic: '<S42>/Not' */
  AFAMgtT_B.Not = !localRte_Call_R_FRM_bInhInMNomM;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabAirModPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_a =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabAirMod_irv();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bInhAirModPrevOutport2' */
  AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_p =
    Rte_IrvRead_RE_AFAMgtT_004_MSE_AFAMgt_bInhAirModTmp_irv();

  /* Outputs for atomic SubSystem: '<S9>/F01_InitStabChk' *
   * Block requirements for '<S9>/F01_InitStabChk':
   *  1. SubSystem "F01_InitStabChk" !Trace_To : VEMS_R_11 _04434_003.01 ;
   */

  /* Embedded MATLAB: '<S38>/Task_sceduler' incorporates:
   *  SubSystem: '<S9>/F02_check_stability_SdlMid'
   *  SubSystem: '<S9>/F03_check_air_mode_stability'
   *  SubSystem: '<S9>/F04_check_petrol_mode_stability'
   *
   * Block requirements for '<S9>/F02_check_stability_SdlMid':
   *  1. SubSystem "F02_check_stability_SdlMid" !Trace_To : VEMS_R_11 _04434_004.01 ;
   *
   * Block requirements for '<S9>/F03_check_air_mode_stability':
   *  1. SubSystem "F03_check_air_mode_stability" !Trace_To : VEMS_R_11 _04434_036.01 ;
   *
   * Block requirements for '<S9>/F04_check_petrol_mode_stability':
   *  1. SubSystem "F04_check_petrol_mode_stability" !Trace_To : VEMS_R_11 _04434_041.01 ;
   */
  /* Embedded MATLAB Function 'AFAMgtT/Runnable_2/F01_InitStabChk/Task_sceduler': '<S67>:1' */
  /* '<S67>:1:3' */

  /* Logic: '<S39>/Logical Operator' */
  localLogicalOperator = (AFAMgtT_B.TmpSignalConversionAtAFAMgt_bIn ||
    AFAMgtT_B.Merge);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S68>/autosar_testpoint1' */

  /* S-Function Block: <S68>/autosar_testpoint1 */
  AFAMgt_bIdcInhChk = localLogicalOperator;

  /* ModelReference: '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  mr_AFAMgtT_F02_check_stability_(&AFAMgtT_B.TmpSignalConversionAtEngM_rAirL,
    &AFAMgtT_B.TmpSignalConversionAtEGRVlv_stE,
    &AFAMgtT_B.TmpSignalConversionAtEGRSys_rEG,
    &AFAMgtT_B.TmpSignalConversionAtInM_pDynCo,
    &AFAMgtT_B.TmpSignalConversionAtCoPt_noEgd,
    &AFAMgtT_B.TmpSignalConversionAtEOM_bTranM,
    AFAMgtT_B.TmpSignalConversionAtInjSys_prm, &localLogicalOperator,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_rAi,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_r_j,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_tiC,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_rEG,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_r_f,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_h,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_l,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_k,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_noE,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_bTr,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_b,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_m,
    &AFAMgtT_B.AFAMgtT_F02_check_stability__gh,
    &AFAMgtT_B.AFAMgtT_F02_check_stability__ng,
    &AFAMgtT_B.AFAMgtT_F02_check_stability__f1,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_j,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_a,
    &AFAMgtT_B.AFAMgtT_F02_check_stability__c2,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_c,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_o,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_Sdl,
    &AFAMgtT_B.AFAMgtT_F02_check_stability__d0,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_h,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_n,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_b,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_g,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_l,
    &AFAMgtT_B.AFAMgtT_F02_check_stability__n1,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_d,
    &AFAMgtT_B.AFAMgtT_F02_check_stability_S_f);

  /* SignalConversion Block: '<S43>/copy'
   *
   * Regarding '<S43>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S45>/copy'
   *
   * Regarding '<S45>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S46>/copy'
   *
   * Regarding '<S46>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S47>/copy'
   *
   * Regarding '<S47>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S48>/copy'
   *
   * Regarding '<S48>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S49>/copy'
   *
   * Regarding '<S49>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S50>/copy'
   *
   * Regarding '<S50>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S51>/copy'
   *
   * Regarding '<S51>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S52>/copy'
   *
   * Regarding '<S52>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S53>/copy'
   *
   * Regarding '<S53>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S54>/copy'
   *
   * Regarding '<S54>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S60>/copy'
   *
   * Regarding '<S60>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S61>/copy'
   *
   * Regarding '<S61>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S62>/copy'
   *
   * Regarding '<S62>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S63>/copy'
   *
   * Regarding '<S63>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S64>/copy'
   *
   * Regarding '<S64>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S65>/copy'
   *
   * Regarding '<S65>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S66>/copy'
   *
   * Regarding '<S66>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* '<S67>:1:5' */

  /* ModelReference: '<S40>/AFAMgtT_F03_check_air_mode_stability' */
  mr_AFAMgtT_F03_check_air_mode_s(&AFAMgtT_B.Not, &AFAMgtT_B.Merge,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_bIn,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_a,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_b_p,
    &AFAMgtT_B.AFAMgtT_F03_check_air_mode_st_e,
    &AFAMgtT_B.AFAMgtT_F03_check_air_mode_stab,
    &AFAMgtT_B.AFAMgtT_F03_check_air_mode_st_p);

  /* '<S67>:1:7' */

  /* ModelReference: '<S41>/AFAMgtT_F04_check_petrol_mode_stability' */
  mr_AFAMgtT_F04_check_petrol_mod(&AFAMgtT_B.TmpSignalConversionAtInjSys_bAc,
    &AFAMgtT_B.Merge, &AFAMgtT_B.TmpSignalConversionAtAFAMgt_bIn,
    &AFAMgtT_B.TmpSignalConversionAtAFAMgt_t_f,
    &AFAMgtT_B.AFAMgtT_F04_check_petrol_mode_d, &AFAMgtT_B.Merge,
    &AFAMgtT_B.AFAMgtT_F04_check_petrol_mode_s);

  /* end of Outputs for SubSystem: '<S9>/F01_InitStabChk' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S43>/autosar_testpoint1' */

  /* S-Function Block: <S43>/autosar_testpoint1 */
  AFAMgt_bIdcNotDynCorPres_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability__f1;

  /* SignalConversion: '<S44>/copy' */
  AFAMgt_bIdcStabAirMod_IRV_MP = AFAMgtT_B.AFAMgtT_F03_check_air_mode_st_e;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S44>/autosar_testpoint1' */

  /* S-Function Block: <S44>/autosar_testpoint1 */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S45>/autosar_testpoint1' */

  /* S-Function Block: <S45>/autosar_testpoint1 */
  AFAMgt_tiCntStabAirLd_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_Sdl;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S46>/autosar_testpoint1' */

  /* S-Function Block: <S46>/autosar_testpoint1 */
  AFAMgt_rEGRMax_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability__d0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S47>/autosar_testpoint1' */

  /* S-Function Block: <S47>/autosar_testpoint1 */
  AFAMgt_rEGRMin_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S48>/autosar_testpoint1' */

  /* S-Function Block: <S48>/autosar_testpoint1 */
  AFAMgt_tiCntStabRatOpEGR_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_n;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S49>/autosar_testpoint1' */

  /* S-Function Block: <S49>/autosar_testpoint1 */
  AFAMgt_tiCntNotDynCorPres_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_b;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S50>/autosar_testpoint1' */

  /* S-Function Block: <S50>/autosar_testpoint1 */
  AFAMgt_tiCntStabEgdGear_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_g;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S51>/autosar_testpoint1' */

  /* S-Function Block: <S51>/autosar_testpoint1 */
  AFAMgt_noEgdGearCordHld_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_l;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S52>/autosar_testpoint1' */

  /* S-Function Block: <S52>/autosar_testpoint1 */
  AFAMgt_bTranModHld_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability__n1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S53>/autosar_testpoint1' */

  /* S-Function Block: <S53>/autosar_testpoint1 */
  AFAMgt_tiCntStabEOM_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S54>/autosar_testpoint1' */

  /* S-Function Block: <S54>/autosar_testpoint1 */
  AFAMgt_tiCntStabFacStrt_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_f;

  /* SignalConversion: '<S55>/copy' */
  AFAMgt_bIdcStabFuMod_IRV_MP = AFAMgtT_B.AFAMgtT_F04_check_petrol_mode_d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S55>/autosar_testpoint1' */

  /* S-Function Block: <S55>/autosar_testpoint1 */

  /* SignalConversion: '<S56>/copy' */
  AFAMgt_bEveRstStabChk_IRV_MP = AFAMgtT_B.Merge;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S56>/autosar_testpoint1' */

  /* S-Function Block: <S56>/autosar_testpoint1 */

  /* SignalConversion: '<S57>/copy' */
  AFAMgt_tiCntStabFuMod_IRV_MP = AFAMgtT_B.AFAMgtT_F04_check_petrol_mode_s;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S57>/autosar_testpoint1' */

  /* S-Function Block: <S57>/autosar_testpoint1 */

  /* SignalConversion: '<S58>/copy' */
  AFAMgt_tiCntStabAirMod_IRV_MP = AFAMgtT_B.AFAMgtT_F03_check_air_mode_stab;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S58>/autosar_testpoint1' */

  /* S-Function Block: <S58>/autosar_testpoint1 */

  /* SignalConversion: '<S59>/copy' */
  AFAMgt_bInhAirModTmp_IRV_MP = AFAMgtT_B.AFAMgtT_F03_check_air_mode_st_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S59>/autosar_testpoint1' */

  /* S-Function Block: <S59>/autosar_testpoint1 */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S60>/autosar_testpoint1' */

  /* S-Function Block: <S60>/autosar_testpoint1 */
  AFAMgt_bIdcStabRatOpEGR_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability__ng;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S61>/autosar_testpoint1' */

  /* S-Function Block: <S61>/autosar_testpoint1 */
  AFAMgt_bStabAirLdCor_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability__gh;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S62>/autosar_testpoint1' */

  /* S-Function Block: <S62>/autosar_testpoint1 */
  AFAMgt_bStabEgdGear_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_j;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S63>/autosar_testpoint1' */

  /* S-Function Block: <S63>/autosar_testpoint1 */
  AFAMgt_bStabEOM_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_a;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S64>/autosar_testpoint1' */

  /* S-Function Block: <S64>/autosar_testpoint1 */
  AFAMgt_bStabFacStrtCor_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability__c2;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S65>/autosar_testpoint1' */

  /* S-Function Block: <S65>/autosar_testpoint1 */
  AFAMgt_rAirLdMax_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_c;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S66>/autosar_testpoint1' */

  /* S-Function Block: <S66>/autosar_testpoint1 */
  AFAMgt_rAirLdMin_IRV_MP = AFAMgtT_B.AFAMgtT_F02_check_stability_S_o;

  /* SignalConversion: '<S9>/Signal Conversion' */
  localSignalConversion_n = AFAMgtT_B.AFAMgtT_F02_check_stability__f1;

  /* SignalConversion: '<S9>/Signal Conversion1' */
  localSignalConversion1_o = AFAMgtT_B.AFAMgtT_F03_check_air_mode_st_e;

  /* SignalConversion: '<S9>/Signal Conversion10' */
  localSignalConversion10 = AFAMgtT_B.AFAMgtT_F02_check_stability_Sdl;

  /* SignalConversion: '<S9>/Signal Conversion11' */
  localSignalConversion11 = AFAMgtT_B.AFAMgtT_F02_check_stability__d0;

  /* SignalConversion: '<S9>/Signal Conversion12' */
  localSignalConversion12 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_h;

  /* SignalConversion: '<S9>/Signal Conversion13' */
  localSignalConversion13 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_n;

  /* SignalConversion: '<S9>/Signal Conversion14' */
  localSignalConversion14 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_b;

  /* SignalConversion: '<S9>/Signal Conversion15' */
  localSignalConversion15 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_g;

  /* SignalConversion: '<S9>/Signal Conversion16' */
  localSignalConversion16 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_l;

  /* SignalConversion: '<S9>/Signal Conversion17' */
  localSignalConversion17 = AFAMgtT_B.AFAMgtT_F02_check_stability__n1;

  /* SignalConversion: '<S9>/Signal Conversion18' */
  localSignalConversion18 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_d;

  /* SignalConversion: '<S9>/Signal Conversion19' */
  localSignalConversion19 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_f;

  /* SignalConversion: '<S9>/Signal Conversion2' */
  localSignalConversion2_c = AFAMgtT_B.AFAMgtT_F04_check_petrol_mode_d;

  /* SignalConversion: '<S9>/Signal Conversion21' */
  localSignalConversion21 = AFAMgtT_B.AFAMgtT_F04_check_petrol_mode_s;

  /* SignalConversion: '<S9>/Signal Conversion22' */
  localSignalConversion22 = AFAMgtT_B.AFAMgtT_F03_check_air_mode_stab;

  /* SignalConversion: '<S9>/Signal Conversion23' */
  localSignalConversion23 = AFAMgtT_B.AFAMgtT_F03_check_air_mode_st_p;

  /* SignalConversion: '<S9>/Signal Conversion3' */
  localSignalConversion3_h = AFAMgtT_B.AFAMgtT_F02_check_stability__ng;

  /* SignalConversion: '<S9>/Signal Conversion4' */
  localSignalConversion4_d = AFAMgtT_B.AFAMgtT_F02_check_stability__gh;

  /* SignalConversion: '<S9>/Signal Conversion5' */
  localSignalConversion5_e = AFAMgtT_B.AFAMgtT_F02_check_stability_S_j;

  /* SignalConversion: '<S9>/Signal Conversion6' */
  localSignalConversion6_d = AFAMgtT_B.AFAMgtT_F02_check_stability_S_a;

  /* SignalConversion: '<S9>/Signal Conversion7' */
  localSignalConversion7_h = AFAMgtT_B.AFAMgtT_F02_check_stability__c2;

  /* SignalConversion: '<S9>/Signal Conversion8' */
  localSignalConversion8 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_c;

  /* SignalConversion: '<S9>/Signal Conversion9' */
  localSignalConversion9 = AFAMgtT_B.AFAMgtT_F02_check_stability_S_o;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bEveRstStabChk_irvInport2' incorporates:
   *  SignalConversion: '<S9>/Signal Conversion20'
   */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bEveRstStabChk_irv(AFAMgtT_B.Merge);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bIdcNotDynCorPres_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bIdcNotDynCorPres_irv
    (localSignalConversion_n);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bIdcStabAirMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bIdcStabAirMod_irv
    (localSignalConversion1_o);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bIdcStabFuMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bIdcStabFuMod_irv
    (localSignalConversion2_c);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bIdcStabRatOpEGR_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bIdcStabRatOpEGR_irv
    (localSignalConversion3_h);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bInhAirModTmp_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bInhAirModTmp_irv
    (localSignalConversion23);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bStabAirLdCor_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bStabAirLdCor_irv
    (localSignalConversion4_d);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bStabEOM_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bStabEOM_irv(localSignalConversion6_d);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bStabEgdGear_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bStabEgdGear_irv
    (localSignalConversion5_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bStabFacStrtCor_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bStabFacStrtCor_irv
    (localSignalConversion7_h);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bTranModHld_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_bTranModHld_irv(localSignalConversion17);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_noEgdGearCordHld_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_noEgdGearCordHld_irv
    (localSignalConversion16);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rAirLdMax_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_rAirLdMax_irv(localSignalConversion8);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rAirLdMin_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_rAirLdMin_irv(localSignalConversion9);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rEGRMax_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_rEGRMax_irv(localSignalConversion11);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_rEGRMin_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_rEGRMin_irv(localSignalConversion12);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntNotDynCorPres_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntNotDynCorPres_irv
    (localSignalConversion14);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabAirLd_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabAirLd_irv
    (localSignalConversion10);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabAirMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabAirMod_irv
    (localSignalConversion22);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabEOM_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabEOM_irv
    (localSignalConversion18);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabEgdGear_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabEgdGear_irv
    (localSignalConversion15);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabFacStrt_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabFacStrt_irv
    (localSignalConversion19);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabFuMod_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabFuMod_irv
    (localSignalConversion21);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_tiCntStabRatOpEGR_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_004_MSE_AFAMgt_tiCntStabRatOpEGR_irv
    (localSignalConversion13);
}

/* Start for exported function: RE_AFAMgtT_007_TEV */
void RE_AFAMgtT_007_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/Runnable_1'
   *
   * Block requirements for '<S1>/Runnable_1':
   *  1. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_083.01 ;
   *  2. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_082.01 ;
   *  3. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_081.01 ;
   *  4. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_087.01 ;
   *  5. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_080.01 ;
   *  6. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_084.01 ;
   *  7. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_086.01 ;
   *  8. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_145.01 ;
   *  9. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_146.01 ;
   *  10. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_147.01 ;
   *  11. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_148.01 ;
   *  12. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_159.01 ;
   *  13. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_149.01 ;
   *  14. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_160.01 ;
   *  15. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_150.01 ;
   *  16. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_151.01 ;
   *  17. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_152.01 ;
   *  18. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_153.01 ;
   *  19. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_154.01 ;
   *  20. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_155.01 ;
   *  21. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_075.01 ;
   *  22. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_126.02 ;
   *  23. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_125.02 ;
   *  24. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_124.02 ;
   *  25. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_119.02 ;
   *  26. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_122.02 ;
   *  27. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_123.02 ;
   *  28. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_140.02 ;
   */
}

/* Output and update for exported function: RE_AFAMgtT_007_TEV */
void RE_AFAMgtT_007_TEV(void)
{
  /* local block i/o variables */
  UInt32 localTmpSignalConversionAtAF_mp;
  UInt32 localTmpSignalConversionAtAFA_k;
  UInt32 localTmpSignalConversionAtAFA_o;
  UInt32 localTmpSignalConversionAtAF_me;
  UInt32 localTmpSignalConversionAtAFA_f;
  UInt32 localTmpSignalConversionAtAF_km;
  UInt32 localAFAMgtT_F02_check_stabilit;
  UInt32 localAFAMgtT_F02_check_stabil_i;
  UInt32 localAFAMgtT_F02_check_stabil_f;
  UInt32 localAFAMgtT_F02_check_stabi_ij;
  UInt32 localAFAMgtT_F02_check_stabil_b;
  UInt32 localAFAMgtT_F02_check_stabil_h;
  UInt16 localTmpSignalConversionAtEGRSy;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt16 localTmpSignalConversionAtAFA_h;
  UInt16 localTmpSignalConversionAtAFA_l;
  UInt16 localAFAMgtT_F02_check_stabil_p;
  UInt16 localAFAMgtT_F02_check_stabil_e;
  UInt16 localTmpSignalConversionAtInjSy[6];
  SInt16 localTmpSignalConversionAtInM_p;
  UInt8 localTmpSignalConversionAtEGRVl;
  UInt8 localTmpSignalConversionAtCoPt_;
  UInt8 localTmpSignalConversionAtAFA_a;
  UInt8 localAFAMgtT_F02_check_stabil_c;
  Boolean localTmpSignalConversionAtEOM_b;
  Boolean localLogicalOperator_d;
  Boolean localTmpSignalConversionAtAFA_p;
  Boolean localAFAMgtT_F02_check_stabil_j;
  Boolean localAFAMgtT_F02_check_stabi_ch;
  Boolean localAFAMgtT_F02_check_stabi_f1;
  Boolean localAFAMgtT_F02_check_stabi_pz;
  Boolean localAFAMgtT_F02_check_stabil_o;
  Boolean localAFAMgtT_F02_check_stabi_bo;
  Boolean localAFAMgtT_F02_check_stabi_oj;
  UInt8 localTmpSignalConversionAtAF_m5;
  UInt8 localTmpSignalConversionAtAFA_e;
  UInt8 localAFAMgtT_F02_check_stabi_p3;
  UInt8 localAFAMgtT_F02_check_stabil_a;
  Boolean localTmpSignalConversionAtAF_ft;
  UInt8 localSignalConversion14_e;
  Boolean localSignalConversion15_p;
  Boolean localSignalConversion2_l;
  Boolean localSignalConversion3_m;
  Boolean localSignalConversion4_n;
  Boolean localSignalConversion5_g;
  UInt8 localSignalConversion10_l;
  UInt32 localSignalConversion11_d;
  UInt32 localSignalConversion12_j;
  UInt32 localSignalConversion13_o;
  UInt32 localSignalConversion16_d;
  UInt32 localSignalConversion17_e;
  UInt16 localSignalConversion6_i;
  UInt16 localSignalConversion7_o;
  UInt32 localSignalConversion8_m;
  UInt8 localSignalConversion9_d;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/Runnable_1'
   *
   * Block requirements for '<S1>/Runnable_1':
   *  1. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_083.01 ;
   *  2. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_082.01 ;
   *  3. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_081.01 ;
   *  4. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_087.01 ;
   *  5. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_080.01 ;
   *  6. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_084.01 ;
   *  7. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_086.01 ;
   *  8. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_145.01 ;
   *  9. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_146.01 ;
   *  10. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_147.01 ;
   *  11. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_148.01 ;
   *  12. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_159.01 ;
   *  13. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_149.01 ;
   *  14. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_160.01 ;
   *  15. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_150.01 ;
   *  16. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_151.01 ;
   *  17. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_152.01 ;
   *  18. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_153.01 ;
   *  19. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_154.01 ;
   *  20. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_155.01 ;
   *  21. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_075.01 ;
   *  22. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_126.02 ;
   *  23. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_125.02 ;
   *  24. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_124.02 ;
   *  25. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_119.02 ;
   *  26. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_122.02 ;
   *  27. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_123.02 ;
   *  28. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_140.02 ;
   */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEGRVlv_stEGRModOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_stEGRMod'
   */
  Rte_Read_R_EGRVlv_stEGRMod_EGRVlv_stEGRMod(&localTmpSignalConversionAtEGRVl);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEGRSys_rEGRReqOutport2' incorporates:
   *  Inport: '<Root>/EGRSys_rEGRReq'
   */
  Rte_Read_R_EGRSys_rEGRReq_EGRSys_rEGRReq(&localTmpSignalConversionAtEGRSy);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtInM_pDynCorPresOutport2' incorporates:
   *  Inport: '<Root>/InM_pDynCorPres'
   */
  Rte_Read_R_InM_pDynCorPres_InM_pDynCorPres(&localTmpSignalConversionAtInM_p);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtCoPt_noEgdGearCordOutport2' incorporates:
   *  Inport: '<Root>/CoPt_noEgdGearCord'
   */
  Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord
    (&localTmpSignalConversionAtCoPt_);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEOM_bTranModOutport2' incorporates:
   *  Inport: '<Root>/EOM_bTranMod'
   */
  Rte_Read_R_EOM_bTranMod_EOM_bTranMod(&localTmpSignalConversionAtEOM_b);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtInjSys_prm_facStrtCorCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_facStrtCorCyl'
   */
  Rte_Read_R_InjSys_prm_facStrtCorCyl_InjSys_prm_facStrtCorCyl
    (&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bInhAFAOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bInhAFA_INPUT'
   */
  Rte_Read_R_AFAMgt_bInhAFA_AFAMgt_bInhAFA(&localTmpSignalConversionAtAF_ft);

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bEveRstStabChkOutport2'
   */
  localLogicalOperator_d = ((localTmpSignalConversionAtAF_ft) ||
    (Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_bEveRstStabChk_irv()));

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rAirLdMaxPrevOutport2' */
  localTmpSignalConversionAtAFA_h =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_rAirLdMax_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rAirLdMinPrevOutport2' */
  localTmpSignalConversionAtAFA_l =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_rAirLdMin_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabAirLdPrevOutport2' */
  localTmpSignalConversionAtAF_mp =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabAirLd_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rEGRMaxPrevOutport2' */
  localTmpSignalConversionAtAF_m5 =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_rEGRMax_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rEGRMinPrevOutport2' */
  localTmpSignalConversionAtAFA_e =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_rEGRMin_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabRatOpEGRPrevOutport2' */
  localTmpSignalConversionAtAFA_k =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabRatOpEGR_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntNotDynCorPresPrevOutport2' */
  localTmpSignalConversionAtAFA_o =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_tiCntNotDynCorPres_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabEgdGearPrevOutport2' */
  localTmpSignalConversionAtAF_me =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabEgdGear_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_noEgdGearCordPrevOutport2' */
  localTmpSignalConversionAtAFA_a =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_noEgdGearCordHld_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bTranModPrevOutport2' */
  localTmpSignalConversionAtAFA_p =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_bTranModHld_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabEOMPrevOutport2' */
  localTmpSignalConversionAtAFA_f =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabEOM_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabFacStrtPrevOutport2' */
  localTmpSignalConversionAtAF_km =
    Rte_IrvRead_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabFacStrt_irv();

  /* Outputs for atomic SubSystem: '<S8>/F02_check_stability_SdlMid' *
   * Block requirements for '<S8>/F02_check_stability_SdlMid':
   *  1. SubSystem "F02_check_stability_SdlMid" !Trace_To : VEMS_R_11 _04434_004.01 ;
   */

  /* ModelReference: '<S18>/AFAMgtT_F02_check_stability_SdlMid' */
  mr_AFAMgtT_F02_check_stability_(&localTmpSignalConversionAtEngM_,
    &localTmpSignalConversionAtEGRVl, &localTmpSignalConversionAtEGRSy,
    &localTmpSignalConversionAtInM_p, &localTmpSignalConversionAtCoPt_,
    &localTmpSignalConversionAtEOM_b, localTmpSignalConversionAtInjSy,
    &localLogicalOperator_d, &localTmpSignalConversionAtAFA_h,
    &localTmpSignalConversionAtAFA_l, &localTmpSignalConversionAtAF_mp,
    &localTmpSignalConversionAtAF_m5, &localTmpSignalConversionAtAFA_e,
    &localTmpSignalConversionAtAFA_k, &localTmpSignalConversionAtAFA_o,
    &localTmpSignalConversionAtAF_me, &localTmpSignalConversionAtAFA_a,
    &localTmpSignalConversionAtAFA_p, &localTmpSignalConversionAtAFA_f,
    &localTmpSignalConversionAtAF_km, &localAFAMgtT_F02_check_stabil_j,
    &localAFAMgtT_F02_check_stabi_ch, &localAFAMgtT_F02_check_stabi_f1,
    &localAFAMgtT_F02_check_stabi_pz, &localAFAMgtT_F02_check_stabil_o,
    &localAFAMgtT_F02_check_stabi_bo, &localAFAMgtT_F02_check_stabil_p,
    &localAFAMgtT_F02_check_stabil_e, &localAFAMgtT_F02_check_stabilit,
    &localAFAMgtT_F02_check_stabi_p3, &localAFAMgtT_F02_check_stabil_a,
    &localAFAMgtT_F02_check_stabil_i, &localAFAMgtT_F02_check_stabil_f,
    &localAFAMgtT_F02_check_stabi_ij, &localAFAMgtT_F02_check_stabil_c,
    &localAFAMgtT_F02_check_stabi_oj, &localAFAMgtT_F02_check_stabil_b,
    &localAFAMgtT_F02_check_stabil_h);

  /* end of Outputs for SubSystem: '<S8>/F02_check_stability_SdlMid' */

  /* SignalConversion: '<S19>/copy' */
  AFAMgt_bIdcNotDynCorPres_IRV_MP = localAFAMgtT_F02_check_stabi_f1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S19>/autosar_testpoint1' */

  /* S-Function Block: <S19>/autosar_testpoint1 */

  /* SignalConversion: '<S20>/copy' */
  AFAMgt_bIdcStabRatOpEGR_IRV_MP = localAFAMgtT_F02_check_stabi_ch;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S20>/autosar_testpoint1' */

  /* S-Function Block: <S20>/autosar_testpoint1 */

  /* SignalConversion: '<S21>/copy' */
  AFAMgt_tiCntStabRatOpEGR_IRV_MP = localAFAMgtT_F02_check_stabil_i;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S21>/autosar_testpoint1' */

  /* S-Function Block: <S21>/autosar_testpoint1 */

  /* SignalConversion: '<S22>/copy' */
  AFAMgt_bIdcInhChk = localLogicalOperator_d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S22>/autosar_testpoint1' */

  /* S-Function Block: <S22>/autosar_testpoint1 */

  /* SignalConversion: '<S23>/copy' */
  AFAMgt_rEGRMin_IRV_MP = localAFAMgtT_F02_check_stabil_a;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S23>/autosar_testpoint1' */

  /* S-Function Block: <S23>/autosar_testpoint1 */

  /* SignalConversion: '<S24>/copy' */
  AFAMgt_tiCntNotDynCorPres_IRV_MP = localAFAMgtT_F02_check_stabil_f;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S24>/autosar_testpoint1' */

  /* S-Function Block: <S24>/autosar_testpoint1 */

  /* SignalConversion: '<S25>/copy' */
  AFAMgt_tiCntStabEgdGear_IRV_MP = localAFAMgtT_F02_check_stabi_ij;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S25>/autosar_testpoint1' */

  /* S-Function Block: <S25>/autosar_testpoint1 */

  /* SignalConversion: '<S26>/copy' */
  AFAMgt_noEgdGearCordHld_IRV_MP = localAFAMgtT_F02_check_stabil_c;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S26>/autosar_testpoint1' */

  /* S-Function Block: <S26>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/copy' */
  AFAMgt_bTranModHld_IRV_MP = localAFAMgtT_F02_check_stabi_oj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S27>/autosar_testpoint1' */

  /* S-Function Block: <S27>/autosar_testpoint1 */

  /* SignalConversion: '<S28>/copy' */
  AFAMgt_tiCntStabEOM_IRV_MP = localAFAMgtT_F02_check_stabil_b;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S28>/autosar_testpoint1' */

  /* S-Function Block: <S28>/autosar_testpoint1 */

  /* SignalConversion: '<S29>/copy' */
  AFAMgt_tiCntStabFacStrt_IRV_MP = localAFAMgtT_F02_check_stabil_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S29>/autosar_testpoint1' */

  /* S-Function Block: <S29>/autosar_testpoint1 */

  /* SignalConversion: '<S30>/copy' */
  AFAMgt_bStabAirLdCor_IRV_MP = localAFAMgtT_F02_check_stabil_j;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S30>/autosar_testpoint1' */

  /* S-Function Block: <S30>/autosar_testpoint1 */

  /* SignalConversion: '<S31>/copy' */
  AFAMgt_bStabEgdGear_IRV_MP = localAFAMgtT_F02_check_stabi_pz;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S31>/autosar_testpoint1' */

  /* S-Function Block: <S31>/autosar_testpoint1 */

  /* SignalConversion: '<S32>/copy' */
  AFAMgt_bStabEOM_IRV_MP = localAFAMgtT_F02_check_stabil_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S32>/autosar_testpoint1' */

  /* S-Function Block: <S32>/autosar_testpoint1 */

  /* SignalConversion: '<S33>/copy' */
  AFAMgt_bStabFacStrtCor_IRV_MP = localAFAMgtT_F02_check_stabi_bo;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S33>/autosar_testpoint1' */

  /* S-Function Block: <S33>/autosar_testpoint1 */

  /* SignalConversion: '<S34>/copy' */
  AFAMgt_rAirLdMax_IRV_MP = localAFAMgtT_F02_check_stabil_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S34>/autosar_testpoint1' */

  /* S-Function Block: <S34>/autosar_testpoint1 */

  /* SignalConversion: '<S35>/copy' */
  AFAMgt_rAirLdMin_IRV_MP = localAFAMgtT_F02_check_stabil_e;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S35>/autosar_testpoint1' */

  /* S-Function Block: <S35>/autosar_testpoint1 */

  /* SignalConversion: '<S36>/copy' */
  AFAMgt_tiCntStabAirLd_IRV_MP = localAFAMgtT_F02_check_stabilit;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S36>/autosar_testpoint1' */

  /* S-Function Block: <S36>/autosar_testpoint1 */

  /* SignalConversion: '<S37>/copy' */
  AFAMgt_rEGRMax_IRV_MP = localAFAMgtT_F02_check_stabi_p3;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S37>/autosar_testpoint1' */

  /* S-Function Block: <S37>/autosar_testpoint1 */

  /* SignalConversion: '<S8>/Signal Conversion1' */
  localTmpSignalConversionAtAF_ft = localAFAMgtT_F02_check_stabi_ch;

  /* SignalConversion: '<S8>/Signal Conversion10' */
  localSignalConversion10_l = localAFAMgtT_F02_check_stabil_a;

  /* SignalConversion: '<S8>/Signal Conversion11' */
  localSignalConversion11_d = localAFAMgtT_F02_check_stabil_i;

  /* SignalConversion: '<S8>/Signal Conversion12' */
  localSignalConversion12_j = localAFAMgtT_F02_check_stabil_f;

  /* SignalConversion: '<S8>/Signal Conversion13' */
  localSignalConversion13_o = localAFAMgtT_F02_check_stabi_ij;

  /* SignalConversion: '<S8>/Signal Conversion14' */
  localSignalConversion14_e = localAFAMgtT_F02_check_stabil_c;

  /* SignalConversion: '<S8>/Signal Conversion15' */
  localSignalConversion15_p = localAFAMgtT_F02_check_stabi_oj;

  /* SignalConversion: '<S8>/Signal Conversion16' */
  localSignalConversion16_d = localAFAMgtT_F02_check_stabil_b;

  /* SignalConversion: '<S8>/Signal Conversion17' */
  localSignalConversion17_e = localAFAMgtT_F02_check_stabil_h;

  /* SignalConversion: '<S8>/Signal Conversion2' */
  localSignalConversion2_l = localAFAMgtT_F02_check_stabil_j;

  /* SignalConversion: '<S8>/Signal Conversion3' */
  localSignalConversion3_m = localAFAMgtT_F02_check_stabi_pz;

  /* SignalConversion: '<S8>/Signal Conversion4' */
  localSignalConversion4_n = localAFAMgtT_F02_check_stabil_o;

  /* SignalConversion: '<S8>/Signal Conversion5' */
  localSignalConversion5_g = localAFAMgtT_F02_check_stabi_bo;

  /* SignalConversion: '<S8>/Signal Conversion6' */
  localSignalConversion6_i = localAFAMgtT_F02_check_stabil_p;

  /* SignalConversion: '<S8>/Signal Conversion7' */
  localSignalConversion7_o = localAFAMgtT_F02_check_stabil_e;

  /* SignalConversion: '<S8>/Signal Conversion8' */
  localSignalConversion8_m = localAFAMgtT_F02_check_stabilit;

  /* SignalConversion: '<S8>/Signal Conversion9' */
  localSignalConversion9_d = localAFAMgtT_F02_check_stabi_p3;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bIdcNotDynCorPres_irvInport2' incorporates:
   *  SignalConversion: '<S8>/Signal Conversion'
   */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_bIdcNotDynCorPres_irv
    (localAFAMgtT_F02_check_stabi_f1);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bIdcStabRatOpEGR_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_bIdcStabRatOpEGR_irv
    (localTmpSignalConversionAtAF_ft);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bStabAirLdCor_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_bStabAirLdCor_irv
    (localSignalConversion2_l);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bStabEOM_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_bStabEOM_irv(localSignalConversion4_n);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bStabEgdGear_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_bStabEgdGear_irv
    (localSignalConversion3_m);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bStabFacStrtCor_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_bStabFacStrtCor_irv
    (localSignalConversion5_g);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_bTranModHld_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_bTranModHld_irv
    (localSignalConversion15_p);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_noEgdGearCordHld_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_noEgdGearCordHld_irv
    (localSignalConversion14_e);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rAirLdMax_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_rAirLdMax_irv(localSignalConversion6_i);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rAirLdMin_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_rAirLdMin_irv(localSignalConversion7_o);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rEGRMax_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_rEGRMax_irv(localSignalConversion9_d);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_rEGRMin_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_rEGRMin_irv(localSignalConversion10_l);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntNotDynCorPres_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_tiCntNotDynCorPres_irv
    (localSignalConversion12_j);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabAirLd_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabAirLd_irv
    (localSignalConversion8_m);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabEOM_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabEOM_irv
    (localSignalConversion16_d);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabEgdGear_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabEgdGear_irv
    (localSignalConversion13_o);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabFacStrt_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabFacStrt_irv
    (localSignalConversion17_e);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFAMgt_tiCntStabRatOpEGR_irvInport2' */
  Rte_IrvWrite_RE_AFAMgtT_007_TEV_AFAMgt_tiCntStabRatOpEGR_irv
    (localSignalConversion11_d);
}

/* Start for exported function: RE_AFAMgtT_001_MSE */
void RE_AFAMgtT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/Runnable_0'
   *
   * Block requirements for '<S1>/Runnable_0':
   *  1. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_113.01 ;
   *  2. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_114.01 ;
   *  3. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_116.01 ;
   *  4. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_115.01 ;
   *  5. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_117.01 ;
   *  6. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_118.01 ;
   *  7. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_144.01 ;
   *  8. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_136.02 ;
   */
}

/* Output and update for exported function: RE_AFAMgtT_001_MSE */
void RE_AFAMgtT_001_MSE(void)
{
  /* local block i/o variables */
  Boolean localAFAMgtT_Init_o1;
  Boolean localAFAMgtT_Init_o2;
  Boolean localAFAMgtT_Init_o3;
  Boolean localAFAMgtT_Init_o4;
  Boolean localAFAMgtT_Init_o5;
  Boolean localAFAMgtT_Init_o6;
  Boolean localSwitch_f;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/Runnable_0'
   *
   * Block requirements for '<S1>/Runnable_0':
   *  1. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_113.01 ;
   *  2. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_114.01 ;
   *  3. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_116.01 ;
   *  4. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_115.01 ;
   *  5. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_117.01 ;
   *  6. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_118.01 ;
   *  7. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_144.01 ;
   *  8. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_136.02 ;
   */

  /* user code (Output function Body for TID6) */
  RE_AFAMgtT_Init();

  /* ModelReference: '<S7>/AFAMgtT_Init' */
  mr_AFAMgtT_Init(&localAFAMgtT_Init_o1, &localAFAMgtT_Init_o2,
                  &localAFAMgtT_Init_o3, &localAFAMgtT_Init_o4,
                  &localAFAMgtT_Init_o5, &localAFAMgtT_Init_o6);

  /* DataTypeConversion Block: '<S12>/Data Type Conversion'
   *
   * Regarding '<S12>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S13>/Data Type Conversion'
   *
   * Regarding '<S13>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S14>/Data Type Conversion'
   *
   * Regarding '<S14>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S15>/Data Type Conversion'
   *
   * Regarding '<S15>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S16>/Data Type Conversion'
   *
   * Regarding '<S16>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S17>/Data Type Conversion'
   *
   * Regarding '<S17>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Byp_Fonction_SC'
   *  Constant: '<S13>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch_f = AFAMgt_bAdpEfcReq_B;
  } else {
    localSwitch_f = localAFAMgtT_Init_o2;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAFAMgt_bAdpEfcReqInport2' */
  Rte_Write_P_AFAMgt_bAdpEfcReq_AFAMgt_bAdpEfcReq(localSwitch_f);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch_f = AFAMgt_bAdpObsReq_B;
  } else {
    localSwitch_f = localAFAMgtT_Init_o4;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAFAMgt_bAdpObsReqInport2' */
  Rte_Write_P_AFAMgt_bAdpObsReq_AFAMgt_bAdpObsReq(localSwitch_f);

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Byp_Fonction_SC'
   *  Constant: '<S14>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch_f = AFAMgt_bAuthAdpReq_B;
  } else {
    localSwitch_f = localAFAMgtT_Init_o3;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAFAMgt_bAuthAdpReqInport2' */
  Rte_Write_P_AFAMgt_bAuthAdpReq_AFAMgt_bAuthAdpReq(localSwitch_f);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch_f = AFAMgt_bIdcInjrMdlCnd_B;
  } else {
    localSwitch_f = localAFAMgtT_Init_o5;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAFAMgt_bIdcInjrMdlCndInport2' */
  Rte_Write_P_AFAMgt_bIdcInjrMdlCnd_AFAMgt_bIdcInjrMdlCnd(localSwitch_f);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch_f = AFAMgt_bIdcTmpObsCnd_B;
  } else {
    localSwitch_f = localAFAMgtT_Init_o6;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAFAMgt_bIdcTmpObsCndInport2' */
  Rte_Write_P_AFAMgt_bIdcTmpObsCnd_AFAMgt_bIdcTmpObsCnd(localSwitch_f);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Byp_Fonction_SC'
   *  Constant: '<S12>/Int_BypC'
   */
  if (AFAMGTT_ACTIVE_BYP_C) {
    localSwitch_f = AFAMgt_bInhAFA_B;
  } else {
    localSwitch_f = localAFAMgtT_Init_o1;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAFAMgt_bInhAFAInport2' */
  Rte_Write_P_AFAMgt_bInhAFA_AFAMgt_bInhAFA(localSwitch_f);
}

/* Model initialize function */
void RE_AFAMgtT_Init(void)
{
  /* Model Initialize fcn for ModelReference Block: '<S7>/AFAMgtT_Init' */
  mr_AFAMgtT_Init_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S18>/AFAMgtT_F02_check_stability_SdlMid' */
  mr_AFAMgtT_F02_check_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  mr_AFAMgtT_F02_check_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S40>/AFAMgtT_F03_check_air_mode_stability' */
  mr_AFAMgtT_F03_check_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S41>/AFAMgtT_F04_check_petrol_mode_stability' */
  mr_AFAMgtT_F04_check_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S69>/AFAMgtT_F01_init_adaptation_manager' */
  mr_AFAMgtT_F01_init__initialize();

  /* Model Initialize fcn for ModelReference Block: '<S76>/AFAMgtT_F01_AFAAdpCndChk' */
  mr_AFAMgtT_F01_AFAAd_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S77>/AFAMgtT_F01_adaptation_observations_delay' */
  mr_AFAMgtT_F01_adapt_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S78>/AFAMgtT_F02_command_observation' */
  mr_AFAMgtT_F02_comma_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S80>/AFAMgtT_F03_check_air_mode_stability' */
  mr_AFAMgtT_F03_check_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S81>/AFAMgtT_F03_check_air_mode_stability' */
  mr_AFAMgtT_F03_check_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S82>/AFAMgtT_F04_check_petrol_mode_stability' */
  mr_AFAMgtT_F04_check_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S83>/AFAMgtT_F04_check_petrol_mode_stability' */
  mr_AFAMgtT_F04_check_initialize();

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  RE_AFAMgtT_002_MSE_Start();
  RE_AFAMgtT_003_TEV_Start();
  RE_AFAMgtT_004_MSE_Start();
  RE_AFAMgtT_007_TEV_Start();
  RE_AFAMgtT_001_MSE_Start();

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__3'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__4'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__5'
   */
  RE_AFAMgtT_003_TEV_Init();
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
