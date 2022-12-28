/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActMgt                                               */
/* !Description     : TrbActMgt Software Component                            */
/*                                                                            */
/* !Module          : TrbActMgt                                               */
/* !Description     : TrbActMgt Software Component                            */
/*                                                                            */
/* !File            : TrbActMgt.c                                             */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : TrbActMgt_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActMgt                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M13-TrbActMgt/5-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TrbActMgt.h"
#include "TrbActMgt_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define TrbActMgt_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActMgt_MemMap.h"

/* Block signals (auto storage) */
BlockIO_TrbActMgt TrbActMgt_B;

/* Block states (auto storage) */
D_Work_TrbActMgt TrbActMgt_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_TrbActMgt TrbActMgt_PrevZCSigState;

#define TrbActMgt_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActMgt_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define TRBACTMGT_VEMSRTLIBT_MAJOR_VERSION_REQ 3
#define TRBACTMGT_VEMSRTLIBT_MINOR_VERSION_REQ 11
#define TRBACTMGT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define TRBACTMGT_VEMSRTLIBT_VERSION_REQ (TRBACTMGT_VEMSRTLIBT_PATCH_VERSION_REQ + TRBACTMGT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + TRBACTMGT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if TRBACTMGT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define TrbActMgt_START_SEC_CODE
#include "TrbActMgt_MemMap.h"

void TrbActMgt_ASYNC1(int controlPortIdx)
{
}

void TrbActMgt_ASYNC2(int controlPortIdx)
{
}

/* Start for exported function: RE_TrbActMgt_001_MSE */
void RE_TrbActMgt_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_TrbActMgt_init'
   *
   * Block requirements for '<S1>/RE_TrbActMgt_init':
   *  1. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_001.03 ;
   *  2. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_002.03 ;
   *  3. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_003.01 ;
   *  4. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_043.01 ;
   *  5. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_024.01 ;
   *  6. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_025.01 ;
   *  7. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_037.01 ;
   *  8. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_026.01 ;
   *  9. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_027.02 ;
   *  10. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_038.01 ;
   *  11. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_058.02 ;
   *  12. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_056.02 ;
   *  13. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_048.03 ;
   */
}

/* Output and update for exported function: RE_TrbActMgt_001_MSE */
void RE_TrbActMgt_001_MSE(void)
{
  /* local block i/o variables */
  SInt16 localDataTypeConversion3;
  Boolean localTrbAct_bAcvTrbActCmd;
  UInt16 localTrbAct_facPresAltiCor;
  UInt16 localTmpSignalConversionAtUsThr;
  SInt16 localTrbAct_rRCOPIDCorReq;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_TrbActMgt_init'
   *
   * Block requirements for '<S1>/RE_TrbActMgt_init':
   *  1. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_001.03 ;
   *  2. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_002.03 ;
   *  3. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_003.01 ;
   *  4. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_043.01 ;
   *  5. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_024.01 ;
   *  6. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_025.01 ;
   *  7. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_037.01 ;
   *  8. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_026.01 ;
   *  9. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_027.02 ;
   *  10. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_038.01 ;
   *  11. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_058.02 ;
   *  12. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_056.02 ;
   *  13. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_048.03 ;
   */

  /* user code (Output function Body for TID5) */
  RE_TrbActMgt_Init();

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Byp_Fonction_SC'
   *  Constant: '<S149>/Int_BypC'
   *  Constant: '<S7>/ConstVal'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_bAcvTrbActCmd = TrbAct_bAcvTrbActCmd_B;
  } else {
    localTrbAct_bAcvTrbActCmd = FALSE;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_bAcvTrbActCmdInport2' */
  Rte_Write_P_TrbAct_bAcvTrbActCmd_TrbAct_bAcvTrbActCmd
    (localTrbAct_bAcvTrbActCmd);

  /* Switch: '<S141>/Switch' incorporates:
   *  Constant: '<S141>/Byp_Fonction_SC'
   *  Constant: '<S141>/Int_BypC'
   *  Constant: '<S7>/ConstVal_1'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_bAcvTrbActCmd = TrbAct_bBoostPresClCtlAcv_B;
  } else {
    localTrbAct_bAcvTrbActCmd = FALSE;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_bBoostPresClCtlAcvInport2' */
  Rte_Write_P_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv
    (localTrbAct_bAcvTrbActCmd);

  /* Switch: '<S143>/Switch' incorporates:
   *  Constant: '<S143>/Byp_Fonction_SC'
   *  Constant: '<S143>/Int_BypC'
   *  Constant: '<S7>/TrbAct_bAcvInhICor_C'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_bAcvTrbActCmd = TrbAct_bInhICor_B;
  } else {
    localTrbAct_bAcvTrbActCmd = TrbAct_bAcvInhICor_C;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_bInhICorInport2' */
  Rte_Write_P_TrbAct_bInhICor_TrbAct_bInhICor(localTrbAct_bAcvTrbActCmd);

  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S144>/Byp_Fonction_SC'
   *  Constant: '<S144>/Int_BypC'
   *  Constant: '<S7>/ConstVal_3'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_bAcvTrbActCmd = TrbAct_bPosnTrbActMod_B;
  } else {
    localTrbAct_bAcvTrbActCmd = FALSE;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_bPosnTrbActModInport2' */
  Rte_Write_P_TrbAct_bPosnTrbActMod_TrbAct_bPosnTrbActMod
    (localTrbAct_bAcvTrbActCmd);

  /* Switch: '<S145>/Switch' incorporates:
   *  Constant: '<S145>/Byp_Fonction_SC'
   *  Constant: '<S145>/Int_BypC'
   *  Constant: '<S7>/ConstVal_4'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_facPresAltiCor = TrbAct_facPresAltiCor_B;
  } else {
    localTrbAct_facPresAltiCor = 0U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_facPresAltiCorInport2' */
  Rte_Write_P_TrbAct_facPresAltiCor_TrbAct_facPresAltiCor
    (localTrbAct_facPresAltiCor);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsThr);

  /* DataTypeConversion: '<S7>/Data Type Conversion3' */
  if (localTmpSignalConversionAtUsThr > 32767) {
    localDataTypeConversion3 = MAX_int16_T;
  } else {
    localDataTypeConversion3 = (SInt16)localTmpSignalConversionAtUsThr;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S148>/autosar_testpoint1' */

  /* S-Function Block: <S148>/autosar_testpoint1 */
  TrbAct_pUsThrICorReq_IRV_MP = localDataTypeConversion3;

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/Byp_Fonction_SC'
   *  Constant: '<S146>/Int_BypC'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_facPresAltiCor = TrbAct_pUsThrCorReq_B;
  } else {
    localTrbAct_facPresAltiCor = localTmpSignalConversionAtUsThr;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pUsThrCorReqInport2' */
  Rte_Write_P_TrbAct_pUsThrCorReq_TrbAct_pUsThrCorReq(localTrbAct_facPresAltiCor);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pUsThrICorReq_irvInport2' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   */
  if (localTmpSignalConversionAtUsThr > 32767) {
    localTrbAct_rRCOPIDCorReq = MAX_int16_T;
  } else {
    localTrbAct_rRCOPIDCorReq = (SInt16)localTmpSignalConversionAtUsThr;
  }

  Rte_IrvWrite_RE_TrbActMgt_001_MSE_TrbAct_pUsThrICorReq_irv
    (localTrbAct_rRCOPIDCorReq);

  /* Switch: '<S147>/Switch' incorporates:
   *  Constant: '<S147>/Byp_Fonction_SC'
   *  Constant: '<S147>/Int_BypC'
   *  Constant: '<S7>/ConstVal_5'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_facPresAltiCor = TrbAct_pUsThrFil_B;
  } else {
    localTrbAct_facPresAltiCor = 0U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pUsThrFilInport2' */
  Rte_Write_P_TrbAct_pUsThrFil_TrbAct_pUsThrFil(localTrbAct_facPresAltiCor);

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Byp_Fonction_SC'
   *  Constant: '<S150>/Int_BypC'
   *  Constant: '<S7>/TrbAct_rRCOPIDCorReq_C'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_rRCOPIDCorReq = TrbAct_rRCOPIDCorReq_B;
  } else {
    localTrbAct_rRCOPIDCorReq = TrbAct_rRCOPIDCorReq_C;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_rRCOPIDCorReqInport2' */
  Rte_Write_P_TrbAct_rRCOPIDCorReq_TrbAct_rRCOPIDCorReq
    (localTrbAct_rRCOPIDCorReq);

  /* Switch: '<S142>/Switch' incorporates:
   *  Constant: '<S142>/Byp_Fonction_SC'
   *  Constant: '<S142>/Int_BypC'
   *  Constant: '<S7>/TrbAct_rRCOICorReq_C'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_rRCOPIDCorReq = TrbAct_rRCOICorReq_B;
  } else {
    localTrbAct_rRCOPIDCorReq = TrbAct_rRCOICorReq_C;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_rRCOICorReqInport2' */
  Rte_Write_P_TrbAct_rRCOICorReq_TrbAct_rRCOICorReq(localTrbAct_rRCOPIDCorReq);
}

/* Output and update for atomic system: '<S32>/F01_NatBoostPresRef' */
void TrbActMgt_F01_NatBoostPresRef(void)
{
  /* Interpolation_n-D: '<S55>/Interpolation Using Prelookup3' */
  TrbAct_pInMnfReqThd = intrp1d_iu16p3ff_u32f_l_s
    (TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_k,
     TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_f, (&(TrbAct_pInMnfReqThd_T[0])));
}

/* Output and update for action system: '<S32>/F03_NatEthBoostPres' */
void TrbActMgt_F03_NatEthBoostPres(void)
{
  Float32 localInterpolationUsingPrelooku;

  /* Interpolation_n-D: '<S56>/Interpolation Using Prelookup3' */
  localInterpolationUsingPrelooku = intrp1d_iu16p3ff_u32f_l_s
    (TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_k,
     TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_f, (&(TrbAct_pInMnfReqThdEth_T[0])));

  /* Sum: '<S54>/Sum2' incorporates:
   *  Lookup_n-D: '<S57>/Lookup Table (n-D)'
   *  Product: '<S58>/Divide'
   *  Sum: '<S54>/Sum1'
   */
  TrbAct_pInMnfReqThdEth = ((localInterpolationUsingPrelooku -
    TrbAct_pInMnfReqThd) * look1_iu8lfIf_binlcns__1
    (TrbActMgt_B.TmpSignalConversionAtAfuA_rEt_d, (&(TrbAct_rEthWoutExct_A[0])),
     (&(TrbAct_rEthWoutExctCor_T[0])), 7U)) + TrbAct_pInMnfReqThd;
}

/* Output and update for action system: '<S32>/F02_NatBoostPres' */
void TrbActMgt_F02_NatBoostPres(void)
{
  /* SignalConversion: '<S53>/Signal Conversion' */
  TrbAct_pInMnfReqThdEth = TrbAct_pInMnfReqThd;
}

/* Output and update for atomic system: '<S15>/F04_NatBoostPres' */
void TrbActMgt_F04_NatBoostPres(void)
{
  /* Outputs for atomic SubSystem: '<S32>/F01_NatBoostPresRef' *
   * Block requirements for '<S32>/F01_NatBoostPresRef':
   *  1. SubSystem "F01_NatBoostPresRef" !Trace_To : VEMS_R_10_07014_065.01 ;
   */
  TrbActMgt_F01_NatBoostPresRef();

  /* end of Outputs for SubSystem: '<S32>/F01_NatBoostPresRef' */

  /* If: '<S32>/If' incorporates:
   *  ActionPort: '<S53>/Action Port'
   *  ActionPort: '<S54>/Action Port'
   *  Constant: '<S32>/TrbAct_bAcvEth_C'
   *  SubSystem: '<S32>/F02_NatBoostPres'
   *  SubSystem: '<S32>/F03_NatEthBoostPres'
   *
   * Block requirements for '<S32>/F02_NatBoostPres':
   *  1. SubSystem "F02_NatBoostPres" !Trace_To : VEMS_R_10_07014_066.01 ;
   *
   * Block requirements for '<S32>/F03_NatEthBoostPres':
   *  1. SubSystem "F03_NatEthBoostPres" !Trace_To : VEMS_R_10_07014_067.01 ;
   */
  if (TrbAct_bAcvEth_C) {
    TrbActMgt_F03_NatEthBoostPres();
  } else {
    TrbActMgt_F02_NatBoostPres();
  }
}

/* Initial conditions for exported function: RE_TrbActMgt_002_TEV */
void RE_TrbActMgt_002_TEV_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/RE_02800_TrbActMgt_SdlFast_TrbActMgr'
   *
   * Block requirements for '<S1>/RE_02800_TrbActMgt_SdlFast_TrbActMgr':
   *  1. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_015.03 ;
   *  2. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_016.03 ;
   *  3. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_028.01 ;
   *  4. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_030.01 ;
   *  5. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_029.02 ;
   *  6. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_031.01 ;
   *  7. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_053.02 ;
   *  8. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_032.01 ;
   *  9. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_052.01 ;
   *  10. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_054.01 ;
   *  11. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_033.01 ;
   *  12. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_034.02 ;
   *  13. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_035.01 ;
   *  14. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_024.01 ;
   *  15. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_025.01 ;
   *  16. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_026.01 ;
   *  17. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_027.02 ;
   *  18. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_058.02 ;
   *  19. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_049.04 ;
   *  20. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_046.01 ;
   *  21. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_047.01 ;
   *  22. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_055.01 ;
   *  23. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_059.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S5>/F01_TransDet' *
   * Block requirements for '<S5>/F01_TransDet':
   *  1. SubSystem "F01_TransDet" !Trace_To : VEMS_R_10_07014_017.02 ;
   */

  /* InitializeConditions for UnitDelay: '<S27>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_a = TRUE;

  /* end of InitializeConditions for SubSystem: '<S5>/F01_TransDet' */

  /* InitializeConditions for atomic SubSystem: '<S5>/F03_TrbActCtlCdn' *
   * Block requirements for '<S5>/F03_TrbActCtlCdn':
   *  1. SubSystem "F03_TrbActCtlCdn" !Trace_To : VEMS_R_10_07014_019.03 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S15>/F01_PosnTrbActModCdn' *
   * Block requirements for '<S15>/F01_PosnTrbActModCdn':
   *  1. SubSystem "F01_PosnTrbActModCdn" !Trace_To : VEMS_R_10_07014_020.03 ;
   */

  /* InitializeConditions for UnitDelay: '<S41>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_h = TRUE;

  /* end of InitializeConditions for SubSystem: '<S15>/F01_PosnTrbActModCdn' */

  /* InitializeConditions for atomic SubSystem: '<S15>/F02_TrbActCmdCdn' *
   * Block requirements for '<S15>/F02_TrbActCmdCdn':
   *  1. SubSystem "F02_TrbActCmdCdn" !Trace_To : VEMS_R_10_07014_021.02 ;
   */

  /* InitializeConditions for UnitDelay: '<S48>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_d = TRUE;

  /* end of InitializeConditions for SubSystem: '<S15>/F02_TrbActCmdCdn' */

  /* end of InitializeConditions for SubSystem: '<S5>/F03_TrbActCtlCdn' */
}

/* Start for exported function: RE_TrbActMgt_002_TEV */
void RE_TrbActMgt_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_02800_TrbActMgt_SdlFast_TrbActMgr'
   *
   * Block requirements for '<S1>/RE_02800_TrbActMgt_SdlFast_TrbActMgr':
   *  1. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_015.03 ;
   *  2. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_016.03 ;
   *  3. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_028.01 ;
   *  4. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_030.01 ;
   *  5. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_029.02 ;
   *  6. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_031.01 ;
   *  7. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_053.02 ;
   *  8. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_032.01 ;
   *  9. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_052.01 ;
   *  10. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_054.01 ;
   *  11. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_033.01 ;
   *  12. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_034.02 ;
   *  13. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_035.01 ;
   *  14. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_024.01 ;
   *  15. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_025.01 ;
   *  16. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_026.01 ;
   *  17. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_027.02 ;
   *  18. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_058.02 ;
   *  19. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_049.04 ;
   *  20. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_046.01 ;
   *  21. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_047.01 ;
   *  22. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_055.01 ;
   *  23. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_059.01 ;
   */
}

/* Output and update for exported function: RE_TrbActMgt_002_TEV */
void RE_TrbActMgt_002_TEV(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_f;
  Boolean localRelationalOperator1;
  Boolean localLogic[2];
  Boolean localRelationalOperator_ft;
  Boolean localRelationalOperator1_l;
  Boolean localLogic_e[2];
  Boolean localRelationalOperator1_c;
  Boolean localLogic_j[2];
  Boolean localUnitDelay1_p;
  Boolean localUnitDelay1_d;
  Boolean localRelationalOperator_e;
  Boolean localUnitDelay1_b;
  Boolean localAutosarServer;
  Float32 localDataTypeConversion7;
  Boolean localNot;
  Boolean localNot_f;
  Boolean localNot_j;
  Float32 localLookupTablenD_k;
  Float32 localSum1_e;
  Float32 localAbs;
  Float32 localSaturation01;
  Boolean localTrbAct_bPosnTrbActMod_k;
  Boolean localSwitch2_k;
  Float32 localInterpolationUsingPreloo_g;
  UInt32 localExt_tCoMes_TrbAct_tCoMes_A;
  Float32 localfrac[2];
  Float32 localAdd2_e;
  UInt32 localbpIndex[2];
  UInt32 localTqCmp_tAir_TrbAct_tAir_A_9;
  Boolean localTmpSignalConversionAtAir_i;
  SInt16 localTmpSignalConversionAtExt_t;
  SInt8 localTmpSignalConversionAtTqCmp;
  UInt16 localTmpSignalConversionAtAirSy;
  UInt16 localTmpSignalConversionAtUsT_e;
  UInt16 localTmpSignalConversionAtAir_d[2];
  UInt16 localTmpSignalConversionAtExt_p;
  UInt16 localTmpSignalConversionAtExt_k;
  UInt16 localTmpSignalConversionAtUsT_p;
  Boolean localRelationalOperator_0;
  SInt32 localqY;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_02800_TrbActMgt_SdlFast_TrbActMgr'
   *
   * Block requirements for '<S1>/RE_02800_TrbActMgt_SdlFast_TrbActMgr':
   *  1. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_015.03 ;
   *  2. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_016.03 ;
   *  3. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_028.01 ;
   *  4. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_030.01 ;
   *  5. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_029.02 ;
   *  6. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_031.01 ;
   *  7. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_053.02 ;
   *  8. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_032.01 ;
   *  9. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_052.01 ;
   *  10. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_054.01 ;
   *  11. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_033.01 ;
   *  12. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_034.02 ;
   *  13. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_035.01 ;
   *  14. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_024.01 ;
   *  15. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_025.01 ;
   *  16. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_026.01 ;
   *  17. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_027.02 ;
   *  18. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_058.02 ;
   *  19. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_049.04 ;
   *  20. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_046.01 ;
   *  21. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_047.01 ;
   *  22. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_055.01 ;
   *  23. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_059.01 ;
   */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_pUsThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReq'
   */
  Rte_Read_R_AirSys_pUsThrReq_AirSys_pUsThrReq(&localTmpSignalConversionAtAirSy);

  /* DataTypeConversion: '<S5>/Data Type Conversion7' */
  localDataTypeConversion7 = ((Float32)localTmpSignalConversionAtAirSy) * 8.0F;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&TrbActMgt_B.TmpSignalConversionAtExt_nEng_g);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_pUsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrMesCor'
   */
  Rte_Read_R_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor
    (&localTmpSignalConversionAtUsT_e);

  /* Outputs for atomic SubSystem: '<S5>/F01_TransDet' *
   * Block requirements for '<S5>/F01_TransDet':
   *  1. SubSystem "F01_TransDet" !Trace_To : VEMS_R_10_07014_017.02 ;
   */

  /* Lookup_n-D: '<S22>/Lookup Table (n-D)' */
  localAbs = look1_iu16lftu16n16If_binlcns
    (TrbActMgt_B.TmpSignalConversionAtExt_nEng_g, (&(TrbAct_nEngRef2_A[0])),
     (&(TrbAct_facFilGainUsThrPresMes_T[0])), 8U);

  /* Saturate: '<S26>/Saturation [0-1]' */
  localSaturation01 = rt_SATURATE(localAbs, 0.0F, 1.0F);

  /* UnitDelay: '<S25>/UnitDelay' */
  localAbs = TrbActMgt_DWork.UnitDelay_o;

  /* UnitDelay: '<S25>/UnitDelay1' */
  localRelationalOperator_e = TrbActMgt_DWork.UnitDelay_i0;

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S13>/TrbAct_pDifUsThrPresHiThd_C1'
   */
  if (!localRelationalOperator_e) {
    localAbs = 101300.0F;
  }

  /* Sum: '<S26>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion8'
   *  Product: '<S26>/Product'
   *  Sum: '<S26>/Sum'
   */
  localSum1_e = (((((Float32)localTmpSignalConversionAtUsT_e) * 8.0F) -
                  localAbs) * localSaturation01) + localAbs;

  /* Abs: '<S13>/Abs' incorporates:
   *  Sum: '<S13>/Sum2'
   */
  localSaturation01 = ACTEMS_FabsF(localDataTypeConversion7 - localSum1_e);

  /* RelationalOperator: '<S23>/Relational Operator' incorporates:
   *  Constant: '<S13>/TrbAct_pDifUsThrPresHiThd_C'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  localRelationalOperator_e = (localSaturation01 >= (((Float32)
    TrbAct_pDifUsThrPresHiThd_C) * 8.0F));

  /* RelationalOperator: '<S23>/Relational Operator1' incorporates:
   *  Constant: '<S13>/TrbAct_pDifUsThrPresLoThd_C'
   *  DataTypeConversion: '<S13>/Data Type Conversion1'
   */
  localRelationalOperator1_c = (localSaturation01 <= (((Float32)
    TrbAct_pDifUsThrPresLoThd_C) * 8.0F));

  /* UnitDelay: '<S27>/UnitDelay' */
  localUnitDelay1_b = TrbActMgt_DWork.UnitDelay_a;

  /* CombinatorialLogic: '<S27>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_e != 0);
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_c != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_b != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_j[0] = TrbActMgt_ConstP.pooled9[rowidx];
    localLogic_j[1] = TrbActMgt_ConstP.pooled9[rowidx + 8];
  }

  /* UnitDelay: '<S27>/UnitDelay1' */
  localUnitDelay1_b = TrbActMgt_DWork.UnitDelay_fc;

  /* Switch: '<S27>/Switch2' incorporates:
   *  Constant: '<S27>/NotCLR3'
   */
  if (localUnitDelay1_b) {
    TrbAct_bDetTran = localLogic_j[0];
  } else {
    TrbAct_bDetTran = TRUE;
  }

  /* Update for UnitDelay: '<S25>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_o = localSum1_e;

  /* Update for UnitDelay: '<S25>/UnitDelay1' incorporates:
   *  Constant: '<S25>/Constant3'
   */
  TrbActMgt_DWork.UnitDelay_i0 = TRUE;

  /* Update for UnitDelay: '<S27>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_a = TrbAct_bDetTran;

  /* Update for UnitDelay: '<S27>/UnitDelay1' incorporates:
   *  Constant: '<S27>/NotCLR2'
   */
  TrbActMgt_DWork.UnitDelay_fc = TRUE;

  /* end of Outputs for SubSystem: '<S5>/F01_TransDet' */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_bAcvFrzModOutport2' incorporates:
   *  Inport: '<Root>/AirSys_bAcvFrzMod'
   */
  Rte_Read_R_AirSys_bAcvFrzMod_AirSys_bAcvFrzMod
    (&localTmpSignalConversionAtAir_i);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_prm_pInMnfReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_pInMnfReq'
   */
  Rte_Read_R_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq
    (&localTmpSignalConversionAtAir_d);

  /* DataTypeConversion: '<S5>/Data Type Conversion5' */
  TrbActMgt_B.DataTypeConversion5[0] = ((Float32)
    localTmpSignalConversionAtAir_d[0]) * 8.0F;
  TrbActMgt_B.DataTypeConversion5[1] = ((Float32)
    localTmpSignalConversionAtAir_d[1]) * 8.0F;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTrbAct_bInhTrbActCtlOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bInhTrbActCtl'
   */
  Rte_Read_R_TrbAct_bInhTrbActCtl_TrbAct_bInhTrbActCtl
    (&TrbActMgt_B.TmpSignalConversionAtTrbAct_bIn);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* S-Function (sfun_autosar_clientop): '<S16>/AutosarServer' */
  Rte_Call_R_FRM_bInhPosnTrbActMod_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S16>/Not' */
  localNot = !localAutosarServer;

  /* S-Function (sfun_autosar_clientop): '<S18>/AutosarServer' */
  Rte_Call_R_FRM_bInhTrbActCmd_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S18>/Not' */
  localNot_f = !localAutosarServer;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_tiStrtOutport2' incorporates:
   *  Inport: '<Root>/Ext_tiStrt'
   */
  Rte_Read_R_Ext_tiStrt_Ext_tiStrt(&localTmpSignalConversionAtExt_k);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_pOilMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pOilMesSI'
   */
  Rte_Read_R_Ext_pOilMesSI_Ext_pOilMesSI(&localTmpSignalConversionAtExt_p);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTqCmp_tAirOutport2' incorporates:
   *  Inport: '<Root>/TqCmp_tAir'
   */
  Rte_Read_R_TqCmp_tAir_TqCmp_tAir(&localTmpSignalConversionAtTqCmp);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_facPresAltiCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_facPresAltiCor'
   */
  Rte_Read_R_UsThrM_facPresAltiCor_UsThrM_facPresAltiCor
    (&localTmpSignalConversionAtUsT_p);

  /* Outputs for atomic SubSystem: '<S5>/F02_AltiCorSp' *
   * Block requirements for '<S5>/F02_AltiCorSp':
   *  1. SubSystem "F02_AltiCorSp" !Trace_To : VEMS_R_10_07014_018.01 ;
   */

  /* Lookup_n-D: '<S28>/Lookup Table (n-D)' */
  localLookupTablenD_k = look1_iu16lfIf_binlcns__1(localTmpSignalConversionAtUsT_p,
    (&(TrbAct_facPresAltiCor_A[0])), (&(TrbAct_facPresAltiCor_T[0])), 8U);

  /* end of Outputs for SubSystem: '<S5>/F02_AltiCorSp' */

  /* S-Function (sfun_autosar_clientop): '<S17>/AutosarServer' */
  Rte_Call_R_FRM_bInhSenCtl_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S17>/Not' */
  localNot_j = !localAutosarServer;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAfuA_rEthWoutExctOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rEthWoutExct'
   */
  Rte_Read_R_AfuA_rEthWoutExct_AfuA_rEthWoutExct
    (&TrbActMgt_B.TmpSignalConversionAtAfuA_rEt_d);

  /* Outputs for atomic SubSystem: '<S5>/F03_TrbActCtlCdn' *
   * Block requirements for '<S5>/F03_TrbActCtlCdn':
   *  1. SubSystem "F03_TrbActCtlCdn" !Trace_To : VEMS_R_10_07014_019.03 ;
   */

  /* PreLookup: '<S33>/Prelookup' */
  TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_k = plook_u32u16f_binc
    (TrbActMgt_B.TmpSignalConversionAtExt_nEng_g, (&(TrbAct_nEng_A[0])), 8U,
     &TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_f);

  /* Outputs for atomic SubSystem: '<S15>/F04_NatBoostPres' *
   * Block requirements for '<S15>/F04_NatBoostPres':
   *  1. SubSystem "F04_NatBoostPres" !Trace_To : VEMS_R_10_07014_064.01 ;
   */
  TrbActMgt_F04_NatBoostPres();

  /* end of Outputs for SubSystem: '<S15>/F04_NatBoostPres' */

  /* Outputs for atomic SubSystem: '<S15>/F01_PosnTrbActModCdn' *
   * Block requirements for '<S15>/F01_PosnTrbActModCdn':
   *  1. SubSystem "F01_PosnTrbActModCdn" !Trace_To : VEMS_R_10_07014_020.03 ;
   */

  /* S-Function (fcncallgen): '<S34>/Function-Call Generator' incorporates:
   *  SubSystem: '<S34>/Subsystem'
   */

  /* Sum: '<S39>/Add1' incorporates:
   *  Constant: '<S29>/TrbAct_tiSampleFast_SC'
   *  Inport: '<S39>/Timer_prev'
   */
  localqY = TrbActMgt_B.MinMax - ((SInt32)(((UInt32)(TrbAct_tiSampleFast_SC *
    16777)) >> 12));
  if ((TrbActMgt_B.MinMax < 0) && (localqY >= 0)) {
    localqY = MIN_int32_T;
  }

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S29>/TrbAct_tiDlyPosnTrbActMod_C'
   *  Logic: '<S40>/Logical Operator2'
   *  Logic: '<S40>/Logical Operator4'
   *  UnitDelay: '<S40>/Unit Delay1'
   */
  if ((!localTmpSignalConversionAtAir_i) && TrbActMgt_DWork.UnitDelay1_DSTATE) {
    localqY = TrbAct_tiDlyPosnTrbActMod_C;
  }

  /* MinMax: '<S39>/MinMax' incorporates:
   *  Constant: '<S39>/Constant'
   */
  if (0 > localqY) {
    localqY = 0;
  }

  TrbActMgt_B.MinMax = localqY;

  /* RelationalOperator: '<S39>/Relational Operator3' incorporates:
   *  RelationalOperator: '<S39>/Relational Operator'
   */
  localRelationalOperator_0 = ((TrbActMgt_B.MinMax <= 0) == ((SInt32)
    localTmpSignalConversionAtAir_i));

  /* Update for UnitDelay: '<S40>/Unit Delay1' */
  TrbActMgt_DWork.UnitDelay1_DSTATE = localTmpSignalConversionAtAir_i;

  /* Switch: '<S29>/Switch1' incorporates:
   *  UnitDelay: '<S37>/Unit Delay'
   */
  if (localTmpSignalConversionAtAir_i) {
    localSaturation01 = TrbActMgt_DWork.UnitDelay_DSTATE_a;
  } else {
    localSaturation01 = TrbActMgt_B.DataTypeConversion5[0];
  }

  /* Product: '<S38>/Divide' */
  localAbs = TrbAct_pInMnfReqThdEth * localLookupTablenD_k;

  /* RelationalOperator: '<S35>/Relational Operator' */
  localRelationalOperator_ft = (localSaturation01 >= localAbs);

  /* RelationalOperator: '<S35>/Relational Operator1' incorporates:
   *  Constant: '<S29>/TrbAct_pInMnfReqHys_C'
   *  DataTypeConversion: '<S29>/Data Type Conversion'
   *  Sum: '<S29>/Sum4'
   */
  localRelationalOperator1_l = (localSaturation01 <= (localAbs - (((Float32)
    TrbAct_pInMnfReqHys_C) * 8.0F)));

  /* UnitDelay: '<S41>/UnitDelay' */
  localUnitDelay1_d = TrbActMgt_DWork.UnitDelay_h;

  /* CombinatorialLogic: '<S41>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_ft != 0);
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_l != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_d != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_e[0] = TrbActMgt_ConstP.pooled9[rowidx];
    localLogic_e[1] = TrbActMgt_ConstP.pooled9[rowidx + 8];
  }

  /* UnitDelay: '<S41>/UnitDelay1' */
  localUnitDelay1_d = TrbActMgt_DWork.UnitDelay_f;

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S41>/NotCLR3'
   */
  if (localUnitDelay1_d) {
    localSwitch2_k = localLogic_e[0];
  } else {
    localSwitch2_k = TRUE;
  }

  /* Logic: '<S29>/Logical Operator2' incorporates:
   *  Logic: '<S29>/Logical Operator'
   *  Logic: '<S29>/Logical Operator1'
   */
  localTrbAct_bPosnTrbActMod_k = (((localSwitch2_k) ||
    (localRelationalOperator_0)) && (!localNot));

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  TrbActMgt_DWork.UnitDelay_DSTATE_a = localSaturation01;

  /* Update for UnitDelay: '<S41>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_h = localSwitch2_k;

  /* Update for UnitDelay: '<S41>/UnitDelay1' incorporates:
   *  Constant: '<S41>/NotCLR2'
   */
  TrbActMgt_DWork.UnitDelay_f = TRUE;

  /* end of Outputs for SubSystem: '<S15>/F01_PosnTrbActModCdn' */

  /* Outputs for atomic SubSystem: '<S15>/F02_TrbActCmdCdn' *
   * Block requirements for '<S15>/F02_TrbActCmdCdn':
   *  1. SubSystem "F02_TrbActCmdCdn" !Trace_To : VEMS_R_10_07014_021.02 ;
   */

  /* PreLookup: '<S45>/Prelookup' */
  localExt_tCoMes_TrbAct_tCoMes_A = plook_u32s16f_binc
    (localTmpSignalConversionAtExt_t, (&(TrbAct_tCoMes_A[0])), 8U,
     &localInterpolationUsingPreloo_g);

  /* Interpolation_n-D: '<S42>/Interpolation Using Prelookup3' */
  localSaturation01 = localInterpolationUsingPreloo_g;
  localAbs = intrp1d_iu16ff_u32f_l_s__1(localExt_tCoMes_TrbAct_tCoMes_A,
    localSaturation01, (&(TrbAct_tiStrtThd_T[0])));

  /* PreLookup: '<S46>/Prelookup' */
  localTqCmp_tAir_TrbAct_tAir_A_9 = plook_u32s8f_binc
    (localTmpSignalConversionAtTqCmp, (&(TrbAct_tAir_A[0])), 8U, &localAdd2_e);

  /* Interpolation_n-D: '<S43>/Interpolation Using Prelookup3' */
  localSaturation01 = localInterpolationUsingPreloo_g;
  localfrac[0] = localSaturation01;
  localSaturation01 = localAdd2_e;
  localfrac[1] = localSaturation01;
  localbpIndex[0] = localExt_tCoMes_TrbAct_tCoMes_A;
  localbpIndex[1] = localTqCmp_tAir_TrbAct_tAir_A_9;
  localInterpolationUsingPreloo_g = intrp2d_iu16ff_u32f_l_s__1(localbpIndex,
    localfrac, (&(TrbAct_tiStrtThd_M[0])), 9U);

  /* RelationalOperator: '<S44>/Relational Operator' incorporates:
   *  Constant: '<S30>/TrbAct_nEngTrbActCmdThd_C'
   */
  localRelationalOperator_f = (TrbActMgt_B.TmpSignalConversionAtExt_nEng_g >=
    TrbAct_nEngTrbActCmdThd_C);

  /* RelationalOperator: '<S44>/Relational Operator1' incorporates:
   *  Constant: '<S30>/TrbAct_nEngTrbActCmdHys_C'
   *  Constant: '<S30>/TrbAct_nEngTrbActCmdThd_C'
   *  Sum: '<S30>/Sum1'
   */
  localRelationalOperator1 = (TrbActMgt_B.TmpSignalConversionAtExt_nEng_g <=
    (TrbAct_nEngTrbActCmdThd_C - TrbAct_nEngTrbActCmdHys_C));

  /* UnitDelay: '<S48>/UnitDelay' */
  localUnitDelay1_p = TrbActMgt_DWork.UnitDelay_d;

  /* CombinatorialLogic: '<S48>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_f != 0);
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1 != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_p != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic[0] = TrbActMgt_ConstP.pooled9[rowidx];
    localLogic[1] = TrbActMgt_ConstP.pooled9[rowidx + 8];
  }

  /* UnitDelay: '<S48>/UnitDelay1' */
  localUnitDelay1_p = TrbActMgt_DWork.UnitDelay_i;

  /* Switch: '<S48>/Switch2' incorporates:
   *  Constant: '<S48>/NotCLR3'
   */
  if (localUnitDelay1_p) {
    localNot = localLogic[0];
  } else {
    localNot = TRUE;
  }

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/TrbAct_bAcvOilPresCtl_C'
   *  Constant: '<S30>/TrbAct_pOilMesThd_C'
   *  Logic: '<S30>/Logical Operator3'
   *  RelationalOperator: '<S30>/Relational Operator3'
   */
  if (!((localTmpSignalConversionAtExt_p >= TrbAct_pOilMesThd_C) &&
        TrbAct_bAcvOilPresCtl_C)) {
    localAbs = localInterpolationUsingPreloo_g;
  }

  /* Sum: '<S47>/Add2' incorporates:
   *  Constant: '<S47>/offset'
   *  Constant: '<S47>/offset1'
   *  Constant: '<S47>/one_on_slope'
   *  Product: '<S47>/Product4'
   *  Sum: '<S47>/Add1'
   */
  localAdd2_e = (0.9765625F * localAbs) + 0.5F;

  /* DataTypeConversion: '<S47>/OutDTConv' */
  localAbs = localAdd2_e;
  if (localAbs < 65536.0F) {
    if (localAbs >= 0.0F) {
      localTmpSignalConversionAtAirSy = (UInt16)localAbs;
    } else {
      localTmpSignalConversionAtAirSy = 0U;
    }
  } else {
    localTmpSignalConversionAtAirSy = MAX_uint16_T;
  }

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S30>/TrbAct_tiStrtThd_C'
   */
  if (localNot_j) {
    localTmpSignalConversionAtAirSy = TrbAct_tiStrtThd_C;
  }

  /* Logic: '<S30>/Logical Operator1' incorporates:
   *  Logic: '<S30>/Logical Operator2'
   *  RelationalOperator: '<S30>/Relational Operator2'
   */
  localRelationalOperator_0 = (((localNot) && (!localNot_f)) &&
    (localTmpSignalConversionAtExt_k >= localTmpSignalConversionAtAirSy));

  /* Update for UnitDelay: '<S48>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_d = localNot;

  /* Update for UnitDelay: '<S48>/UnitDelay1' incorporates:
   *  Constant: '<S48>/NotCLR2'
   */
  TrbActMgt_DWork.UnitDelay_i = TRUE;

  /* end of Outputs for SubSystem: '<S15>/F02_TrbActCmdCdn' */

  /* Outputs for atomic SubSystem: '<S15>/F03_BoostClCtlCdn' *
   * Block requirements for '<S15>/F03_BoostClCtlCdn':
   *  1. SubSystem "F03_BoostClCtlCdn" !Trace_To : VEMS_R_10_07014_022.01 ;
   */

  /* Interpolation_n-D: '<S49>/Interpolation Using Prelookup3' */
  localSaturation01 = TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_f;
  localSaturation01 = intrp1d_iu16p3ff_u32f_l_s
    (TrbActMgt_B.Ext_nEng_TrbAct_nEng_A_9_k, localSaturation01,
     (&(TrbAct_pUsThrCllAcvThd_T[0])));

  /* Switch: '<S31>/Switch' incorporates:
   *  UnitDelay: '<S50>/Unit Delay'
   */
  if (localTmpSignalConversionAtAir_i) {
    localDataTypeConversion7 = TrbActMgt_DWork.UnitDelay_DSTATE_f;
  }

  /* Update for UnitDelay: '<S50>/Unit Delay' */
  TrbActMgt_DWork.UnitDelay_DSTATE_f = localDataTypeConversion7;

  /* end of Outputs for SubSystem: '<S15>/F03_BoostClCtlCdn' */

  /* end of Outputs for SubSystem: '<S5>/F03_TrbActCtlCdn' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S31>/TrbAct_bInhCllCtl_C'
   *  Constant: '<S31>/TrbAct_bTrbActCf_SC'
   *  Constant: '<S8>/Byp_Fonction_SC'
   *  Constant: '<S8>/Int_BypC'
   *  Logic: '<S31>/Logical Operator1'
   *  Logic: '<S31>/Logical Operator2'
   *  Logic: '<S31>/Logical Operator3'
   *  Logic: '<S31>/Logical Operator5'
   *  Logic: '<S31>/Logical Operator6'
   *  Product: '<S51>/Divide'
   *  RelationalOperator: '<S31>/Relational Operator3'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localNot = TrbAct_bBoostPresClCtlAcv_B;
  } else {
    localNot = ((((((localRelationalOperator_0) && (localTrbAct_bPosnTrbActMod_k))
                   && ((localSaturation01 * localLookupTablenD_k) <
                       localDataTypeConversion7)) && ((!TrbAct_bDetTran) ||
      TrbAct_bTrbActCf_SC)) && (TrbAct_bTrbActCf_SC ||
      (!TrbActMgt_B.TmpSignalConversionAtTrbAct_bIn))) && TrbAct_bInhCllCtl_C);
  }

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Byp_Fonction_SC'
   *  Constant: '<S9>/Int_BypC'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_bPosnTrbActMod_k = TrbAct_bPosnTrbActMod_B;
  }

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Byp_Fonction_SC'
   *  Constant: '<S10>/Int_BypC'
   *  Constant: '<S19>/offset'
   *  Constant: '<S19>/offset1'
   *  Constant: '<S19>/one_on_slope'
   *  DataTypeConversion: '<S19>/OutDTConv'
   *  Product: '<S19>/Product4'
   *  Sum: '<S19>/Add1'
   *  Sum: '<S19>/Add2'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAirSy = TrbAct_facPresAltiCor_B;
  } else {
    localAbs = (32768.0F * localLookupTablenD_k) + 0.5F;
    if (localAbs < 65536.0F) {
      if (localAbs >= 0.0F) {
        localTmpSignalConversionAtAirSy = (UInt16)localAbs;
      } else {
        localTmpSignalConversionAtAirSy = 0U;
      }
    } else {
      localTmpSignalConversionAtAirSy = MAX_uint16_T;
    }
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Byp_Fonction_SC'
   *  Constant: '<S11>/Int_BypC'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localRelationalOperator_0 = TrbAct_bAcvTrbActCmd_B;
  }

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Byp_Fonction_SC'
   *  Constant: '<S12>/Int_BypC'
   *  Constant: '<S20>/offset'
   *  Constant: '<S20>/offset1'
   *  Constant: '<S20>/one_on_slope'
   *  DataTypeConversion: '<S20>/OutDTConv'
   *  Product: '<S20>/Product4'
   *  Sum: '<S20>/Add1'
   *  Sum: '<S20>/Add2'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_e = TrbAct_pUsThrFil_B;
  } else {
    localAbs = (0.125F * localSum1_e) + 0.5F;
    if (localAbs < 65536.0F) {
      if (localAbs >= 0.0F) {
        localTmpSignalConversionAtUsT_e = (UInt16)localAbs;
      } else {
        localTmpSignalConversionAtUsT_e = 0U;
      }
    } else {
      localTmpSignalConversionAtUsT_e = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTrbAct_bAcvTrbActCmdInport2' */
  Rte_Write_P_TrbAct_bAcvTrbActCmd_TrbAct_bAcvTrbActCmd
    (localRelationalOperator_0);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTrbAct_bBoostPresClCtlAcvInport2' */
  Rte_Write_P_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv(localNot);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTrbAct_bPosnTrbActModInport2' */
  Rte_Write_P_TrbAct_bPosnTrbActMod_TrbAct_bPosnTrbActMod
    (localTrbAct_bPosnTrbActMod_k);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTrbAct_facPresAltiCorInport2' */
  Rte_Write_P_TrbAct_facPresAltiCor_TrbAct_facPresAltiCor
    (localTmpSignalConversionAtAirSy);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTrbAct_pUsThrFilInport2' */
  Rte_Write_P_TrbAct_pUsThrFil_TrbAct_pUsThrFil(localTmpSignalConversionAtUsT_e);
}

/* Output and update for atomic system: '<S65>/F01_IndCtlGain' */
void TrbActMgt_F01_IndCtlGain(void)
{
  Float32 localSwitch_o;
  Float32 localSwitch1_p;
  Float32 localSaturation01_k;
  SInt16 localSwitch2_c;
  SInt16 locallocalDataTypeConversion7_f;

  /* Sum: '<S75>/Sum' incorporates:
   *  UnitDelay: '<S88>/Unit Delay'
   */
  localSwitch_o = TrbAct_pErrUsThr - TrbActMgt_DWork.UnitDelay_DSTATE_j;

  /* Product: '<S85>/Product4' incorporates:
   *  Constant: '<S85>/offset'
   *  Constant: '<S85>/one_on_slope'
   *  Sum: '<S85>/Add1'
   */
  localSwitch1_p = 0.125F * localSwitch_o;

  /* Switch: '<S85>/Switch1' incorporates:
   *  Constant: '<S85>/offset2'
   *  Constant: '<S85>/offset3'
   *  Constant: '<S85>/offset4'
   *  RelationalOperator: '<S85>/Relational Operator'
   *  Sum: '<S85>/Add3'
   *  Sum: '<S85>/Add4'
   */
  if (localSwitch1_p >= 0.0F) {
    localSwitch1_p += 0.5F;
  } else {
    localSwitch1_p -= 0.5F;
  }

  /* DataStoreWrite: '<S75>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S85>/OutDTConv'
   */
  if (localSwitch1_p < 32768.0F) {
    if (localSwitch1_p >= -32768.0F) {
      TrbActMgt_DWork.TrbAct_pErrGrd_MP = (SInt16)localSwitch1_p;
    } else {
      TrbActMgt_DWork.TrbAct_pErrGrd_MP = MIN_int16_T;
    }
  } else {
    TrbActMgt_DWork.TrbAct_pErrGrd_MP = MAX_int16_T;
  }

  /* DataTypeConversion: '<S75>/Data Type Conversion1' incorporates:
   *  Constant: '<S75>/TrbAct_facFltErrPres_C'
   */
  localSwitch1_p = (((Float32)TrbAct_facFltErrPres_C) * 1.525878906E-005F) +
    1.525878906E-005F;

  /* DataTypeConversion: '<S75>/Data Type Conversion2' */
  if (TrbActMgt_B.TmpSignalConversionAtAirSys_pUs > 32767) {
    localSwitch2_c = MAX_int16_T;
  } else {
    localSwitch2_c = (SInt16)TrbActMgt_B.TmpSignalConversionAtAirSys_pUs;
  }

  /* Saturate: '<S92>/Saturation [0-1]' */
  localSaturation01_k = rt_SATURATE(localSwitch1_p, 0.0F, 1.0F);

  /* UnitDelay: '<S91>/UnitDelay' */
  localSwitch1_p = TrbActMgt_DWork.UnitDelay;

  /* Switch: '<S91>/Switch' incorporates:
   *  UnitDelay: '<S91>/UnitDelay1'
   */
  if (!TrbActMgt_DWork.UnitDelay_lj) {
    localSwitch1_p = localSwitch_o;
  }

  /* Sum: '<S92>/Sum1' incorporates:
   *  Product: '<S92>/Product'
   *  Sum: '<S92>/Sum'
   */
  localSaturation01_k = ((localSwitch_o - localSwitch1_p) * localSaturation01_k)
    + localSwitch1_p;

  /* Switch: '<S89>/Switch' incorporates:
   *  UnitDelay: '<S89>/UnitDelay'
   */
  if (TrbActMgt_DWork.UnitDelay_DSTATE_d) {
    localSwitch_o = localSaturation01_k;
  }

  /* Product: '<S87>/Product4' incorporates:
   *  Constant: '<S87>/offset'
   *  Constant: '<S87>/one_on_slope'
   *  Sum: '<S87>/Add1'
   */
  localSwitch1_p = 0.125F * TrbAct_pErrUsThr;

  /* Switch: '<S87>/Switch1' incorporates:
   *  Constant: '<S87>/offset2'
   *  Constant: '<S87>/offset3'
   *  Constant: '<S87>/offset4'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  Sum: '<S87>/Add3'
   *  Sum: '<S87>/Add4'
   */
  if (localSwitch1_p >= 0.0F) {
    localSwitch1_p += 0.5F;
  } else {
    localSwitch1_p -= 0.5F;
  }

  /* DataTypeConversion: '<S87>/OutDTConv' */
  if (localSwitch1_p < 32768.0F) {
    if (localSwitch1_p >= -32768.0F) {
      locallocalDataTypeConversion7_f = (SInt16)localSwitch1_p;
    } else {
      locallocalDataTypeConversion7_f = MIN_int16_T;
    }
  } else {
    locallocalDataTypeConversion7_f = MAX_int16_T;
  }

  /* PreLookup: '<S81>/Prelookup' */
  TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l = plook_u32s16f_binc
    (locallocalDataTypeConversion7_f, (&(TrbAct_pErrUsThr_A[0])), 8U,
     &TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT);

  /* Switch: '<S75>/Switch2' incorporates:
   *  Constant: '<S75>/TrbAct_bSelPresErrReq_C'
   */
  if (!TrbAct_bSelPresErrReq_C) {
    localSwitch2_c = locallocalDataTypeConversion7_f;
  }

  /* PreLookup: '<S83>/Prelookup' */
  TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_k = plook_u32s16f_binc(localSwitch2_c,
    (&(TrbAct_pErrUsThr2_A[0])), 8U, &TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_f);

  /* Product: '<S86>/Product4' incorporates:
   *  Constant: '<S86>/offset'
   *  Constant: '<S86>/one_on_slope'
   *  Sum: '<S86>/Add1'
   */
  localSwitch1_p = 0.125F * localSwitch_o;

  /* Switch: '<S86>/Switch1' incorporates:
   *  Constant: '<S86>/offset2'
   *  Constant: '<S86>/offset3'
   *  Constant: '<S86>/offset4'
   *  RelationalOperator: '<S86>/Relational Operator'
   *  Sum: '<S86>/Add3'
   *  Sum: '<S86>/Add4'
   */
  if (localSwitch1_p >= 0.0F) {
    localSwitch1_p += 0.5F;
  } else {
    localSwitch1_p -= 0.5F;
  }

  /* DataTypeConversion: '<S86>/OutDTConv' */
  if (localSwitch1_p < 32768.0F) {
    if (localSwitch1_p >= -32768.0F) {
      TrbAct_pErrFltGrd_MP = (SInt16)localSwitch1_p;
    } else {
      TrbAct_pErrFltGrd_MP = MIN_int16_T;
    }
  } else {
    TrbAct_pErrFltGrd_MP = MAX_int16_T;
  }

  /* PreLookup: '<S84>/Prelookup' */
  TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_p_l = plook_u32s16f_binc
    (TrbAct_pErrFltGrd_MP, (&(TrbAct_pErrUsThrGrd_A[0])), 8U,
     &TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_pEr);

  /* PreLookup: '<S82>/Prelookup' */
  TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k = plook_u32u16f_binc
    (TrbActMgt_B.TmpSignalConversionAtExt_nEngOu, (&(TrbAct_nEngCtl_A[0])), 8U,
     &TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f);

  /* PreLookup: '<S80>/Prelookup' incorporates:
   *  DataTypeConversion: '<S75>/Data Type Conversion7'
   */
  TrbActMgt_B.Ext_nEngGrd_TrbAct_nEngGrd_A__h = plook_u32s16f_binc((SInt16)
    (TrbActMgt_B.TmpSignalConversionAtExt_nEngGr << 6), (&(TrbAct_nEngGrd_A[0])),
    8U, &TrbActMgt_B.Ext_nEngGrd_TrbAct_nEngGrd_A_9_);

  /* Update for UnitDelay: '<S88>/Unit Delay' */
  TrbActMgt_DWork.UnitDelay_DSTATE_j = TrbAct_pErrUsThr;

  /* Update for UnitDelay: '<S91>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay = localSaturation01_k;

  /* Update for UnitDelay: '<S91>/UnitDelay1' incorporates:
   *  Constant: '<S91>/Constant3'
   */
  TrbActMgt_DWork.UnitDelay_lj = TRUE;

  /* Update for UnitDelay: '<S89>/UnitDelay' incorporates:
   *  Constant: '<S89>/Constant3'
   */
  TrbActMgt_DWork.UnitDelay_DSTATE_d = TRUE;
}

/* Output and update for atomic system: '<S65>/F02_CtlGainRef' */
void TrbActMgt_F02_CtlGainRef(void)
{
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Float32 localfrac_3[2];
  UInt32 localbpIndex_3[2];
  Float32 localfrac_4[2];
  UInt32 localbpIndex_4[2];
  Float32 localfrac_5[2];
  UInt32 localbpIndex_5[2];
  Float32 localfrac_6[2];
  UInt32 localbpIndex_6[2];
  Float32 localfrac_7[2];
  UInt32 localbpIndex_7[2];
  Float32 localInterpolationUsingPreloo_h;
  Float32 localInterpolationUsingPrelo_i4;
  Float32 localInterpolationUsingPrelo_hr;
  Float32 localInterpolationUsingPreloo_l;
  Float32 localInterpolationUsingPreloo_i;
  Float32 localInterpolationUsingPreloo_p;
  Float32 localInterpolationUsingPrelo_gm;
  Float32 localInterpolationUsingPrelo_hh;

  /* Interpolation_n-D: '<S93>/Interpolation Using Prelookup3' */
  localfrac[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_pEr;
  localfrac[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localbpIndex[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_p_l;
  localbpIndex[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localInterpolationUsingPreloo_h = intrp2d_iu16n11ff_u32f_l_ns(localbpIndex,
    localfrac, (&(TrbAct_facpGain_M[0])), 9U);

  /* Interpolation_n-D: '<S94>/Interpolation Using Prelookup3' */
  localfrac_0[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_pEr;
  localfrac_0[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localbpIndex_0[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_p_l;
  localbpIndex_0[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localInterpolationUsingPrelo_hr = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex_0,
    localfrac_0, (&(TrbAct_faciGain_M[0])), 9U);

  /* Interpolation_n-D: '<S95>/Interpolation Using Prelookup3' */
  localfrac_1[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_pEr;
  localfrac_1[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localbpIndex_1[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_p_l;
  localbpIndex_1[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localInterpolationUsingPreloo_i = intrp2d_iu16n11ff_u32f_l_ns(localbpIndex_1,
    localfrac_1, (&(TrbAct_facdGain1_M[0])), 9U);

  /* Interpolation_n-D: '<S96>/Interpolation Using Prelookup3' */
  localfrac_2[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_pEr;
  localfrac_2[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localbpIndex_2[0] = TrbActMgt_B.TrbAct_pErrFltGrd_MP_TrbAct_p_l;
  localbpIndex_2[1] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localInterpolationUsingPrelo_gm = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex_2,
    localfrac_2, (&(TrbAct_facdGain2_M[0])), 9U);

  /* Interpolation_n-D: '<S97>/Interpolation Using Prelookup3' */
  localfrac_3[0] = TrbActMgt_B.Ext_nEngGrd_TrbAct_nEngGrd_A_9_;
  localfrac_3[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_3[0] = TrbActMgt_B.Ext_nEngGrd_TrbAct_nEngGrd_A__h;
  localbpIndex_3[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  TrbAct_facFfGain = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex_3, localfrac_3,
    (&(TrbAct_facFfGain_M[0])), 9U);

  /* Interpolation_n-D: '<S98>/Interpolation Using Prelookup3' */
  localfrac_4[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_f;
  localfrac_4[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_4[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_k;
  localbpIndex_4[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localInterpolationUsingPrelo_i4 = intrp2d_iu16n11ff_u32f_l_ns(localbpIndex_4,
    localfrac_4, (&(TrbAct_facpGainErrPres_M[0])), 9U);

  /* Interpolation_n-D: '<S99>/Interpolation Using Prelookup3' */
  localfrac_5[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_f;
  localfrac_5[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_5[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_k;
  localbpIndex_5[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localInterpolationUsingPreloo_l = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex_5,
    localfrac_5, (&(TrbAct_faciGainErrPres_M[0])), 9U);

  /* Interpolation_n-D: '<S100>/Interpolation Using Prelookup3' */
  localfrac_6[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_f;
  localfrac_6[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_6[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_k;
  localbpIndex_6[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localInterpolationUsingPreloo_p = intrp2d_iu16n11ff_u32f_l_ns(localbpIndex_6,
    localfrac_6, (&(TrbAct_facdGain1ErrPres_M[0])), 9U);

  /* Interpolation_n-D: '<S101>/Interpolation Using Prelookup3' */
  localfrac_7[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_f;
  localfrac_7[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_7[0] = TrbActMgt_B.NS_TrbAct_pErrUsThr2_A_9_k;
  localbpIndex_7[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localInterpolationUsingPrelo_hh = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex_7,
    localfrac_7, (&(TrbAct_facdGain2ErrPres_M[0])), 9U);

  /* Product: '<S102>/Divide' */
  TrbAct_facpGainRef = localInterpolationUsingPreloo_h *
    localInterpolationUsingPrelo_i4;

  /* Product: '<S103>/Divide' */
  TrbAct_faciGainRef = localInterpolationUsingPrelo_hr *
    localInterpolationUsingPreloo_l;

  /* Product: '<S104>/Divide' */
  TrbAct_facdGain1Ref = localInterpolationUsingPreloo_i *
    localInterpolationUsingPreloo_p;

  /* Product: '<S105>/Divide' */
  TrbAct_facdGain2Ref = localInterpolationUsingPrelo_gm *
    localInterpolationUsingPrelo_hh;
}

/* Output and update for action system: '<S65>/F04_EthCtlGain' */
void TrbActMgt_F04_EthCtlGain(void)
{
  Float32 localInterpolationUsingPrel_hh4;
  Float32 localfractionTmp_0d;
  UInt32 localAfuA_rEthWoutExct_TrbAct_r;
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Float32 localInterpolationUsingPrelo_lt;
  Float32 localInterpolationUsingPreloo_n;
  Float32 localInterpolationUsingPrelo_ls;
  Float32 localInterpolationUsingPrelo_ii;
  Float32 localInterpolationUsingPreloo_a;
  Float32 localInterpolationUsingPrelo_g0;

  /* PreLookup: '<S114>/Prelookup' */
  localAfuA_rEthWoutExct_TrbAct_r = plook_u32u8f_binc
    (TrbActMgt_B.TmpSignalConversionAtAfuA_rEthW, (&(TrbAct_rEthWoutExctCtl_A[0])),
     7U, &localInterpolationUsingPrel_hh4);

  /* Interpolation_n-D: '<S106>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localInterpolationUsingPrel_hh4;
  localInterpolationUsingPrelo_lt = intrp1d_iu8n7ff_u32f_l_ns
    (localAfuA_rEthWoutExct_TrbAct_r, localfractionTmp_0d,
     (&(TrbAct_rEthWoutExctProp_T[0])));

  /* Interpolation_n-D: '<S107>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localInterpolationUsingPrel_hh4;
  localInterpolationUsingPrelo_ls = intrp1d_iu8n7ff_u32f_l_ns
    (localAfuA_rEthWoutExct_TrbAct_r, localfractionTmp_0d,
     (&(TrbAct_rEthWoutExctInt_T[0])));

  /* Interpolation_n-D: '<S108>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localInterpolationUsingPrel_hh4;
  localInterpolationUsingPreloo_a = intrp1d_iu8n7ff_u32f_l_ns
    (localAfuA_rEthWoutExct_TrbAct_r, localfractionTmp_0d,
     (&(TrbAct_rEthWoutExctDftl1_T[0])));

  /* Interpolation_n-D: '<S109>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localInterpolationUsingPrel_hh4;
  localInterpolationUsingPrel_hh4 = intrp1d_iu8n7ff_u32f_l_ns
    (localAfuA_rEthWoutExct_TrbAct_r, localfractionTmp_0d,
     (&(TrbAct_rEthWoutExctDftl2_T[0])));

  /* Interpolation_n-D: '<S110>/Interpolation Using Prelookup3' */
  localfrac[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localfrac[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localbpIndex[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localfractionTmp_0d = intrp2d_iu16n11ff_u32f_l_ns(localbpIndex, localfrac,
    (&(TrbAct_facpGainErrPresEth_M[0])), 9U);

  /* Interpolation_n-D: '<S111>/Interpolation Using Prelookup3' */
  localfrac_0[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localfrac_0[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_0[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localbpIndex_0[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localInterpolationUsingPreloo_n = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex_0,
    localfrac_0, (&(TrbAct_faciGainErrPresEth_M[0])), 9U);

  /* Interpolation_n-D: '<S112>/Interpolation Using Prelookup3' */
  localfrac_1[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localfrac_1[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_1[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localbpIndex_1[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localInterpolationUsingPrelo_ii = intrp2d_iu16n11ff_u32f_l_ns(localbpIndex_1,
    localfrac_1, (&(TrbAct_facdGain1ErrPresEth_M[0])), 9U);

  /* Interpolation_n-D: '<S113>/Interpolation Using Prelookup3' */
  localfrac_2[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrUsT;
  localfrac_2[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_f;
  localbpIndex_2[0] = TrbActMgt_B.TrbAct_pErrUsThr_TrbAct_pErrU_l;
  localbpIndex_2[1] = TrbActMgt_B.Ext_nEng_TrbAct_nEngCtl_A_9_k;
  localInterpolationUsingPrelo_g0 = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex_2,
    localfrac_2, (&(TrbAct_facdGain2ErrPresEth_M[0])), 9U);

  /* Sum: '<S78>/Sum2' incorporates:
   *  Product: '<S118>/Divide'
   *  Sum: '<S78>/Sum1'
   */
  TrbAct_facpGain = ((localfractionTmp_0d - TrbAct_facpGainRef) *
                     localInterpolationUsingPrelo_lt) + TrbAct_facpGainRef;

  /* Sum: '<S78>/Sum4' incorporates:
   *  Product: '<S115>/Divide'
   *  Sum: '<S78>/Sum3'
   */
  TrbAct_faciGain = ((localInterpolationUsingPreloo_n - TrbAct_faciGainRef) *
                     localInterpolationUsingPrelo_ls) + TrbAct_faciGainRef;

  /* Sum: '<S78>/Sum6' incorporates:
   *  Product: '<S116>/Divide'
   *  Sum: '<S78>/Sum5'
   */
  TrbAct_facdGain1 = ((localInterpolationUsingPrelo_ii - TrbAct_facdGain1Ref) *
                      localInterpolationUsingPreloo_a) + TrbAct_facdGain1Ref;

  /* Product: '<S117>/Divide' incorporates:
   *  Sum: '<S78>/Sum7'
   */
  localfractionTmp_0d = (localInterpolationUsingPrelo_g0 - TrbAct_facdGain2Ref) *
    localInterpolationUsingPrel_hh4;

  /* Sum: '<S78>/Sum8' */
  TrbAct_facdGain2 = localfractionTmp_0d + TrbAct_facdGain2Ref;
}

/* Output and update for action system: '<S65>/F03_CtlGain' */
void TrbActMgt_F03_CtlGain(void)
{
  /* SignalConversion: '<S77>/Signal Conversion1' */
  TrbAct_facpGain = TrbAct_facpGainRef;

  /* SignalConversion: '<S77>/Signal Conversion2' */
  TrbAct_faciGain = TrbAct_faciGainRef;

  /* SignalConversion: '<S77>/Signal Conversion3' */
  TrbAct_facdGain1 = TrbAct_facdGain1Ref;

  /* SignalConversion: '<S77>/Signal Conversion4' */
  TrbAct_facdGain2 = TrbAct_facdGain2Ref;
}

/* Initial conditions for exported function: RE_TrbActMgt_003_TEV */
void RE_TrbActMgt_003_TEV_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/RE_02801_TrbActMgt_SdlFast_TrbActCtl'
   *
   * Block requirements for '<S1>/RE_02801_TrbActMgt_SdlFast_TrbActCtl':
   *  1. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_001.03 ;
   *  2. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_002.03 ;
   *  3. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_004.03 ;
   *  4. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_028.01 ;
   *  5. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_040.01 ;
   *  6. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_031.01 ;
   *  7. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_039.01 ;
   *  8. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_041.01 ;
   *  9. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_033.01 ;
   *  10. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_051.02 ;
   *  11. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_042.01 ;
   *  12. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_043.01 ;
   *  13. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_044.01 ;
   *  14. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_057.02 ;
   *  15. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_037.01 ;
   *  16. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_038.01 ;
   *  17. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_056.02 ;
   *  18. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_059.01 ;
   *  19. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_050.04 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S6>/F04_I' *
   * Block requirements for '<S6>/F04_I':
   *  1. SubSystem "F04_I" !Trace_To : VEMS_R_10_07014_008.01 ;
   */

  /* InitializeConditions for trigger SubSystem: '<S67>/F02_IParInit' *
   * Block requirements for '<S67>/F02_IParInit':
   *  1. SubSystem "F02_IParInit" !Trace_To : VEMS_R_10_07014_010.01 ;
   */

  /* InitializeConditions for UnitDelay: '<S127>/UnitDelay' */
  TrbActMgt_DWork.UnitDelay_l = TRUE;

  /* end of InitializeConditions for SubSystem: '<S67>/F02_IParInit' */

  /* end of InitializeConditions for SubSystem: '<S6>/F04_I' */
}

/* Start for exported function: RE_TrbActMgt_003_TEV */
void RE_TrbActMgt_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_02801_TrbActMgt_SdlFast_TrbActCtl'
   *
   * Block requirements for '<S1>/RE_02801_TrbActMgt_SdlFast_TrbActCtl':
   *  1. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_001.03 ;
   *  2. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_002.03 ;
   *  3. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_004.03 ;
   *  4. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_028.01 ;
   *  5. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_040.01 ;
   *  6. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_031.01 ;
   *  7. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_039.01 ;
   *  8. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_041.01 ;
   *  9. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_033.01 ;
   *  10. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_051.02 ;
   *  11. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_042.01 ;
   *  12. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_043.01 ;
   *  13. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_044.01 ;
   *  14. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_057.02 ;
   *  15. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_037.01 ;
   *  16. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_038.01 ;
   *  17. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_056.02 ;
   *  18. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_059.01 ;
   *  19. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_050.04 ;
   */
}

/* Output and update for exported function: RE_TrbActMgt_003_TEV */
void RE_TrbActMgt_003_TEV(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_e5;
  Boolean localRelationalOperator1_g;
  Boolean localUnitDelay_l1;
  Boolean localLogic_g[2];
  Float32 localDataTypeConversion1_p;
  Float32 localDataTypeConversion5;
  Boolean localTmpSignalConversionAtTrb_m;
  Boolean localTmpSignalConversionAtTrb_k;
  Float32 localDivide_gh;
  Boolean localSwitch2_oy;
  Float32 localAdd2_i;
  UInt16 localTmpSignalConversionAtTrbAc;
  UInt16 localTmpSignalConversionAtTrb_j;
  SInt16 localTrbAct_rRCOICorReq_d;
  SInt16 localTrbAct_rRCOPIDCorReq_n;
  UInt16 localTmpSignalConversionAtTrb_f;
  UInt16 localTmpSignalConversionAtTrb_e;
  SInt32 localSwitch_c;
  UInt16 localTmpSignalConversionAtUs_pd;
  SInt16 locallocalOutDTConv_p;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_02801_TrbActMgt_SdlFast_TrbActCtl'
   *
   * Block requirements for '<S1>/RE_02801_TrbActMgt_SdlFast_TrbActCtl':
   *  1. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_001.03 ;
   *  2. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_002.03 ;
   *  3. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_004.03 ;
   *  4. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_028.01 ;
   *  5. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_040.01 ;
   *  6. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_031.01 ;
   *  7. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_039.01 ;
   *  8. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_041.01 ;
   *  9. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_033.01 ;
   *  10. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_051.02 ;
   *  11. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_042.01 ;
   *  12. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_043.01 ;
   *  13. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_044.01 ;
   *  14. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_057.02 ;
   *  15. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_037.01 ;
   *  16. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_038.01 ;
   *  17. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_056.02 ;
   *  18. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_059.01 ;
   *  19. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_050.04 ;
   */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAirSys_pUsThrReqFilOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReqFil'
   */
  Rte_Read_R_AirSys_pUsThrReqFil_AirSys_pUsThrReqFil
    (&TrbActMgt_B.TmpSignalConversionAtAirSys_pUs);

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  localDataTypeConversion1_p = ((Float32)
    TrbActMgt_B.TmpSignalConversionAtAirSys_pUs) * 8.0F;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pUsThrFilOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pUsThrFil_INPUT'
   */
  Rte_Read_R_TrbAct_pUsThrFil_TrbAct_pUsThrFil(&localTmpSignalConversionAtTrbAc);

  /* DataTypeConversion: '<S6>/Data Type Conversion5' */
  localDataTypeConversion5 = ((Float32)localTmpSignalConversionAtTrbAc) * 8.0F;

  /* Outputs for atomic SubSystem: '<S6>/F01_ErrClcn' *
   * Block requirements for '<S6>/F01_ErrClcn':
   *  1. SubSystem "F01_ErrClcn" !Trace_To : VEMS_R_10_07014_005.01 ;
   */

  /* Sum: '<S64>/Sum2' */
  TrbAct_pErrUsThr = localDataTypeConversion1_p - localDataTypeConversion5;

  /* end of Outputs for SubSystem: '<S6>/F01_ErrClcn' */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rOpTrbActReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpTrbActReq'
   */
  Rte_Read_R_TrbAct_rOpTrbActReq_TrbAct_rOpTrbActReq
    (&localTmpSignalConversionAtTrb_e);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&TrbActMgt_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExt_nEngGrdOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEngGrd'
   */
  Rte_Read_R_Ext_nEngGrd_Ext_nEngGrd
    (&TrbActMgt_B.TmpSignalConversionAtExt_nEngGr);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAfuA_rEthWoutExctOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rEthWoutExct'
   */
  Rte_Read_R_AfuA_rEthWoutExct_AfuA_rEthWoutExct
    (&TrbActMgt_B.TmpSignalConversionAtAfuA_rEthW);

  /* Outputs for atomic SubSystem: '<S6>/F02_GainPIDAntiClcn' *
   * Block requirements for '<S6>/F02_GainPIDAntiClcn':
   *  1. SubSystem "F02_GainPIDAntiClcn" !Trace_To : VEMS_R_10_07014_006.03 ;
   */

  /* Outputs for atomic SubSystem: '<S65>/F01_IndCtlGain' *
   * Block requirements for '<S65>/F01_IndCtlGain':
   *  1. SubSystem "F01_IndCtlGain" !Trace_To : VEMS_R_10_07014_060.01 ;
   */
  TrbActMgt_F01_IndCtlGain();

  /* end of Outputs for SubSystem: '<S65>/F01_IndCtlGain' */

  /* Outputs for atomic SubSystem: '<S65>/F02_CtlGainRef' *
   * Block requirements for '<S65>/F02_CtlGainRef':
   *  1. SubSystem "F02_CtlGainRef" !Trace_To : VEMS_R_10_07014_061.01 ;
   */
  TrbActMgt_F02_CtlGainRef();

  /* end of Outputs for SubSystem: '<S65>/F02_CtlGainRef' */

  /* If: '<S65>/If' incorporates:
   *  ActionPort: '<S77>/Action Port'
   *  ActionPort: '<S78>/Action Port'
   *  Constant: '<S65>/TrbAct_bAcvCtlEth_C'
   *  SubSystem: '<S65>/F03_CtlGain'
   *  SubSystem: '<S65>/F04_EthCtlGain'
   *
   * Block requirements for '<S65>/F03_CtlGain':
   *  1. SubSystem "F03_CtlGain" !Trace_To : VEMS_R_10_07014_062.01 ;
   *
   * Block requirements for '<S65>/F04_EthCtlGain':
   *  1. SubSystem "F04_EthCtlGain" !Trace_To : VEMS_R_10_07014_063.01 ;
   */
  if (TrbAct_bAcvCtlEth_C) {
    TrbActMgt_F04_EthCtlGain();
  } else {
    TrbActMgt_F03_CtlGain();
  }

  /* end of Outputs for SubSystem: '<S6>/F02_GainPIDAntiClcn' */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAirSys_bAcvFrzModOutport2' incorporates:
   *  Inport: '<Root>/AirSys_bAcvFrzMod'
   */
  Rte_Read_R_AirSys_bAcvFrzMod_AirSys_bAcvFrzMod
    (&TrbActMgt_B.TmpSignalConversionAtAirSys_bAc);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_bBoostPresClCtlAcvOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bBoostPresClCtlAcv_INPUT'
   */
  Rte_Read_R_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv
    (&localTmpSignalConversionAtTrb_m);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&localTmpSignalConversionAtUs_pd);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&TrbActMgt_B.TmpSignalConversionAtUsThrM_pAi);

  /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
   *  SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pUsThrICorReqPrevOutport2'
   */
  TrbAct_pUsThrICorReqPrev = ((Float32)
    Rte_IrvRead_RE_TrbActMgt_003_TEV_TrbAct_pUsThrICorReq_irv()) * 8.0F;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pUsThrCorReq_INPUTOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pUsThrCorReq_INPUT'
   */
  Rte_Read_R_TrbAct_pUsThrCorReq_TrbAct_pUsThrCorReq
    (&localTmpSignalConversionAtTrb_j);

  /* DataTypeConversion: '<S6>/Data Type Conversion10' */
  TrbAct_pUsThrCorReqPrev = ((Float32)localTmpSignalConversionAtTrb_j) * 8.0F;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_bInhTrbActCtlOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bInhTrbActCtl'
   */
  Rte_Read_R_TrbAct_bInhTrbActCtl_TrbAct_bInhTrbActCtl
    (&localTmpSignalConversionAtTrb_k);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rRCOReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rRCOReq'
   */
  Rte_Read_R_TrbAct_rRCOReq_TrbAct_rRCOReq(&localTmpSignalConversionAtTrb_f);

  /* Outputs for atomic SubSystem: '<S6>/F04_I' *
   * Block requirements for '<S6>/F04_I':
   *  1. SubSystem "F04_I" !Trace_To : VEMS_R_10_07014_008.01 ;
   */

  /* Outputs for atomic SubSystem: '<S67>/F01_RstCond_FrzCond' *
   * Block requirements for '<S67>/F01_RstCond_FrzCond':
   *  1. SubSystem "F01_RstCond_FrzCond" !Trace_To : VEMS_R_10_07014_009.01 ;
   */

  /* Logic: '<S120>/Logical Operator6' incorporates:
   *  UnitDelay: '<S123>/Unit Delay'
   */
  TrbAct_bRstICor = ((localTmpSignalConversionAtTrb_m) &&
                     TrbActMgt_DWork.UnitDelay_DSTATE_b);

  /* Sum: '<S120>/Add2' incorporates:
   *  Constant: '<S120>/ConstVal1'
   */
  localSwitch_c = 65536 - localTmpSignalConversionAtTrb_f;

  /* Switch: '<S120>/Switch' incorporates:
   *  Constant: '<S120>/TrbAct_bSelInhICnd_C'
   *  DataTypeConversion: '<S120>/Data Type Conversion1'
   */
  if (!TrbAct_bSelInhICnd_C) {
    localSwitch_c = localTmpSignalConversionAtTrb_e;
  }

  /* Logic: '<S120>/Logical Operator11' incorporates:
   *  Constant: '<S120>/ConstVal'
   *  Constant: '<S120>/ConstVal_1'
   *  Constant: '<S120>/TrbAct_rOpTrbActHiThd_C'
   *  Constant: '<S120>/TrbAct_rOpTrbActLoThd_C'
   *  Logic: '<S120>/Logical Operator1'
   *  Logic: '<S120>/Logical Operator12'
   *  Logic: '<S120>/Logical Operator2'
   *  Logic: '<S120>/Logical Operator3'
   *  RelationalOperator: '<S120>/Relational Operator'
   *  RelationalOperator: '<S120>/Relational Operator1'
   *  RelationalOperator: '<S120>/Relational Operator2'
   *  RelationalOperator: '<S120>/Relational Operator3'
   */
  localTmpSignalConversionAtTrb_k = (((((TrbAct_pErrUsThr <= 0.0F) &&
    (TrbAct_rOpTrbActHiThd_C <= localSwitch_c)) || ((localSwitch_c <=
    TrbAct_rOpTrbActLoThd_C) && (TrbAct_pErrUsThr >= 0.0F))) ||
    (localTmpSignalConversionAtTrb_k)) ||
    TrbActMgt_B.TmpSignalConversionAtAirSys_bAc);

  /* Update for UnitDelay: '<S123>/Unit Delay' incorporates:
   *  Logic: '<S120>/Logical Operator5'
   */
  TrbActMgt_DWork.UnitDelay_DSTATE_b = !localTmpSignalConversionAtTrb_m;

  /* end of Outputs for SubSystem: '<S67>/F01_RstCond_FrzCond' */

  /* Outputs for trigger SubSystem: '<S67>/F02_IParInit' incorporates:
   *  TriggerPort: '<S121>/TrbAct_bRstICor'
   *
   * Block requirements for '<S67>/F02_IParInit':
   *  1. SubSystem "F02_IParInit" !Trace_To : VEMS_R_10_07014_010.01 ;
   */
  if (TrbAct_bRstICor && (TrbActMgt_PrevZCSigState.F02_IParInit_Trig_ZCE !=
                          POS_ZCSIG)) {
    /* Sum: '<S121>/Add2' incorporates:
     *  Product: '<S125>/Divide'
     */
    localAdd2_i = TrbAct_pUsThrCorReqPrev - (TrbAct_pUsThrCorReqPrev *
      TrbAct_facFfGain);

    /* Product: '<S126>/Divide' */
    localDivide_gh = TrbAct_facFfGain * localDataTypeConversion5;

    /* RelationalOperator: '<S124>/Relational Operator' incorporates:
     *  Constant: '<S121>/TrbAct_pAirExtHys_C'
     *  Sum: '<S121>/Add1'
     */
    localRelationalOperator_e5 = (((UInt32)localTmpSignalConversionAtUs_pd) >=
                                  ((UInt32)(TrbAct_pAirExtHys_C +
      TrbActMgt_B.TmpSignalConversionAtUsThrM_pAi)));

    /* RelationalOperator: '<S124>/Relational Operator1' */
    localRelationalOperator1_g = (localTmpSignalConversionAtUs_pd <=
      TrbActMgt_B.TmpSignalConversionAtUsThrM_pAi);

    /* UnitDelay: '<S127>/UnitDelay' */
    localUnitDelay_l1 = TrbActMgt_DWork.UnitDelay_l;

    /* CombinatorialLogic: '<S127>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_e5 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_g != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_l1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_g[0] = TrbActMgt_ConstP.pooled9[rowidx];
      localLogic_g[1] = TrbActMgt_ConstP.pooled9[rowidx + 8];
    }

    /* Switch: '<S127>/Switch2' incorporates:
     *  Constant: '<S127>/NotCLR3'
     *  UnitDelay: '<S127>/UnitDelay1'
     */
    if (TrbActMgt_DWork.UnitDelay_e) {
      localSwitch2_oy = localLogic_g[0];
    } else {
      localSwitch2_oy = TRUE;
    }

    /* Switch: '<S121>/Switch' incorporates:
     *  Sum: '<S121>/Add3'
     */
    if (localSwitch2_oy) {
      TrbAct_pUsThrICorReqIni = localAdd2_i;
    } else {
      TrbAct_pUsThrICorReqIni = localDataTypeConversion5 - localDivide_gh;
    }

    /* Update for UnitDelay: '<S127>/UnitDelay' */
    TrbActMgt_DWork.UnitDelay_l = localSwitch2_oy;

    /* Update for UnitDelay: '<S127>/UnitDelay1' incorporates:
     *  Constant: '<S127>/NotCLR2'
     */
    TrbActMgt_DWork.UnitDelay_e = TRUE;
  }

  TrbActMgt_PrevZCSigState.F02_IParInit_Trig_ZCE = (UInt8)(TrbAct_bRstICor ?
    ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

  /* end of Outputs for SubSystem: '<S67>/F02_IParInit' */

  /* Outputs for atomic SubSystem: '<S67>/F03_ICor' *
   * Block requirements for '<S67>/F03_ICor':
   *  1. SubSystem "F03_ICor" !Trace_To : VEMS_R_10_07014_011.02 ;
   */

  /* Switch: '<S122>/Switch1' */
  if (TrbAct_bRstICor) {
    localDataTypeConversion5 = TrbAct_pUsThrICorReqIni;
  } else {
    localDataTypeConversion5 = TrbAct_pUsThrICorReqPrev;
  }

  /* Switch: '<S122>/Switch2' incorporates:
   *  Constant: '<S122>/ConstVal'
   *  Product: '<S130>/Divide'
   *  UnitDelay: '<S129>/Unit Delay'
   */
  if (localTmpSignalConversionAtTrb_k) {
    localAdd2_i = 0.0F;
  } else {
    localAdd2_i = TrbActMgt_DWork.UnitDelay_DSTATE_l * TrbAct_faciGain;
  }

  /* Sum: '<S122>/Sum' */
  localDataTypeConversion5 += localAdd2_i;

  /* DataTypeConversion: '<S122>/Data Type Conversion' incorporates:
   *  Constant: '<S122>/TrbAct_pUsThrICorReqHiThd_C'
   */
  localAdd2_i = ((Float32)TrbAct_pUsThrICorReqHiThd_C) * 8.0F;

  /* DataTypeConversion: '<S122>/Data Type Conversion1' incorporates:
   *  Constant: '<S122>/TrbAct_pUsThrICorReqLoThd_C'
   */
  localDivide_gh = (((Float32)TrbAct_pUsThrICorReqLoThd_C) * 8.0F) - 524280.0F;

  /* Switch: '<S133>/Switch' incorporates:
   *  RelationalOperator: '<S133>/UpperRelop'
   */
  if (!(localDataTypeConversion5 < localDivide_gh)) {
    localDivide_gh = localDataTypeConversion5;
  }

  /* Switch: '<S133>/Switch2' incorporates:
   *  RelationalOperator: '<S133>/LowerRelop1'
   */
  if (localDataTypeConversion5 > localAdd2_i) {
    localDivide_gh = localAdd2_i;
  }

  /* Update for UnitDelay: '<S129>/Unit Delay' */
  TrbActMgt_DWork.UnitDelay_DSTATE_l = TrbAct_pErrUsThr;

  /* end of Outputs for SubSystem: '<S67>/F03_ICor' */

  /* end of Outputs for SubSystem: '<S6>/F04_I' */

  /* Product: '<S72>/Product4' incorporates:
   *  Constant: '<S72>/offset'
   *  Constant: '<S72>/one_on_slope'
   *  Sum: '<S72>/Add1'
   */
  localDataTypeConversion5 = 0.125F * localDivide_gh;

  /* Switch: '<S72>/Switch1' incorporates:
   *  Constant: '<S72>/offset2'
   *  Constant: '<S72>/offset3'
   *  Constant: '<S72>/offset4'
   *  RelationalOperator: '<S72>/Relational Operator'
   *  Sum: '<S72>/Add3'
   *  Sum: '<S72>/Add4'
   */
  if (localDataTypeConversion5 >= 0.0F) {
    localDataTypeConversion5 += 0.5F;
  } else {
    localDataTypeConversion5 -= 0.5F;
  }

  /* DataTypeConversion: '<S72>/OutDTConv' */
  if (localDataTypeConversion5 < 32768.0F) {
    if (localDataTypeConversion5 >= -32768.0F) {
      locallocalOutDTConv_p = (SInt16)localDataTypeConversion5;
    } else {
      locallocalOutDTConv_p = MIN_int16_T;
    }
  } else {
    locallocalOutDTConv_p = MAX_int16_T;
  }

  /* SignalConversion: '<S63>/copy' */
  TrbAct_pUsThrICorReq_IRV_MP = locallocalOutDTConv_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S63>/autosar_testpoint1' */

  /* S-Function Block: <S63>/autosar_testpoint1 */

  /* Outputs for atomic SubSystem: '<S6>/F03_P' *
   * Block requirements for '<S6>/F03_P':
   *  1. SubSystem "F03_P" !Trace_To : VEMS_R_10_07014_007.02 ;
   */

  /* Product: '<S119>/Divide' */
  TrbAct_pUsThrPCorReq = TrbAct_facpGain * TrbAct_pErrUsThr;

  /* end of Outputs for SubSystem: '<S6>/F03_P' */

  /* Outputs for atomic SubSystem: '<S6>/F05_D' *
   * Block requirements for '<S6>/F05_D':
   *  1. SubSystem "F05_D" !Trace_To : VEMS_R_10_07014_012.02 ;
   */

  /* Sum: '<S68>/Add2' incorporates:
   *  Product: '<S136>/Divide'
   *  Product: '<S137>/Divide'
   *  Sum: '<S68>/Add1'
   *  UnitDelay: '<S134>/Unit Delay'
   *  UnitDelay: '<S135>/Unit Delay'
   */
  TrbAct_pUsThrDCorReq = ((TrbAct_pErrUsThr - TrbActMgt_DWork.UnitDelay_DSTATE) *
    TrbAct_facdGain1) + (TrbAct_facdGain2 * TrbActMgt_DWork.UnitDelay_DSTATE_p);

  /* Update for UnitDelay: '<S134>/Unit Delay' */
  TrbActMgt_DWork.UnitDelay_DSTATE = TrbAct_pErrUsThr;

  /* Update for UnitDelay: '<S135>/Unit Delay' */
  TrbActMgt_DWork.UnitDelay_DSTATE_p = TrbAct_pUsThrDCorReq;

  /* end of Outputs for SubSystem: '<S6>/F05_D' */

  /* Outputs for atomic SubSystem: '<S6>/F06_Ant' *
   * Block requirements for '<S6>/F06_Ant':
   *  1. SubSystem "F06_Ant" !Trace_To : VEMS_R_10_07014_013.02 ;
   */

  /* Product: '<S138>/Divide' */
  TrbAct_pUsThrFfCorReq = localDataTypeConversion1_p * TrbAct_facFfGain;

  /* end of Outputs for SubSystem: '<S6>/F06_Ant' */

  /* Outputs for atomic SubSystem: '<S6>/F07_pUsThrCorSpClcn' *
   * Block requirements for '<S6>/F07_pUsThrCorSpClcn':
   *  1. SubSystem "F07_pUsThrCorSpClcn" !Trace_To : VEMS_R_10_07014_014.01 ;
   */

  /* DataTypeConversion: '<S70>/Data Type Conversion' incorporates:
   *  Constant: '<S70>/TrbAct_facPresRCOCnv_C'
   */
  localAdd2_i = ((Float32)TrbAct_facPresRCOCnv_C) * 5.820766091E-011F;

  /* Sum: '<S70>/Sum' */
  localDataTypeConversion5 = (TrbAct_pUsThrPCorReq + localDivide_gh) +
    TrbAct_pUsThrDCorReq;

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S70>/TrbAct_bInhUsReg_C'
   *  Logic: '<S70>/Logical Operator'
   *  Logic: '<S70>/Logical Operator1'
   *  Sum: '<S70>/Sum1'
   */
  if (!((!localTmpSignalConversionAtTrb_m) || TrbAct_bInhUsReg_C)) {
    localDataTypeConversion1_p = localDataTypeConversion5 +
      TrbAct_pUsThrFfCorReq;
  }

  /* Switch: '<S70>/Switch1' incorporates:
   *  Constant: '<S70>/TrbAct_bAcvUsThrPresCorTest_C'
   *  Constant: '<S70>/TrbAct_pUsThrCorReqTest_C'
   *  DataTypeConversion: '<S70>/Data Type Conversion5'
   */
  if (TrbAct_bAcvUsThrPresCorTest_C) {
    localDataTypeConversion1_p = ((Float32)TrbAct_pUsThrCorReqTest_C) * 8.0F;
  }

  /* end of Outputs for SubSystem: '<S6>/F07_pUsThrCorSpClcn' */

  /* Switch: '<S59>/Switch' incorporates:
   *  Constant: '<S59>/Byp_Fonction_SC'
   *  Constant: '<S59>/Int_BypC'
   *  Constant: '<S71>/offset'
   *  Constant: '<S71>/offset1'
   *  Constant: '<S71>/one_on_slope'
   *  DataTypeConversion: '<S71>/OutDTConv'
   *  Product: '<S71>/Product4'
   *  Sum: '<S71>/Add1'
   *  Sum: '<S71>/Add2'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTrbAc = TrbAct_pUsThrCorReq_B;
  } else {
    localDataTypeConversion1_p = (0.125F * localDataTypeConversion1_p) + 0.5F;
    if (localDataTypeConversion1_p < 65536.0F) {
      if (localDataTypeConversion1_p >= 0.0F) {
        localTmpSignalConversionAtTrbAc = (UInt16)localDataTypeConversion1_p;
      } else {
        localTmpSignalConversionAtTrbAc = 0U;
      }
    } else {
      localTmpSignalConversionAtTrbAc = MAX_uint16_T;
    }
  }

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/Byp_Fonction_SC'
   *  Constant: '<S60>/Int_BypC'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTrb_k = TrbAct_bInhICor_B;
  }

  /* Product: '<S73>/Product4' incorporates:
   *  Constant: '<S73>/offset'
   *  Constant: '<S73>/one_on_slope'
   *  Product: '<S139>/Divide'
   *  Sum: '<S73>/Add1'
   */
  localDataTypeConversion5 = (localAdd2_i * localDataTypeConversion5) * 32768.0F;

  /* Switch: '<S73>/Switch1' incorporates:
   *  Constant: '<S73>/offset2'
   *  Constant: '<S73>/offset3'
   *  Constant: '<S73>/offset4'
   *  RelationalOperator: '<S73>/Relational Operator'
   *  Sum: '<S73>/Add3'
   *  Sum: '<S73>/Add4'
   */
  if (localDataTypeConversion5 >= 0.0F) {
    localDataTypeConversion5 += 0.5F;
  } else {
    localDataTypeConversion5 -= 0.5F;
  }

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Byp_Fonction_SC'
   *  Constant: '<S61>/Int_BypC'
   *  DataTypeConversion: '<S73>/OutDTConv'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_rRCOPIDCorReq_n = TrbAct_rRCOPIDCorReq_B;
  } else if (localDataTypeConversion5 < 32768.0F) {
    if (localDataTypeConversion5 >= -32768.0F) {
      localTrbAct_rRCOPIDCorReq_n = (SInt16)localDataTypeConversion5;
    } else {
      localTrbAct_rRCOPIDCorReq_n = MIN_int16_T;
    }
  } else {
    localTrbAct_rRCOPIDCorReq_n = MAX_int16_T;
  }

  /* Product: '<S74>/Product4' incorporates:
   *  Constant: '<S74>/offset'
   *  Constant: '<S74>/one_on_slope'
   *  Product: '<S140>/Divide'
   *  Sum: '<S74>/Add1'
   */
  localDataTypeConversion5 = (localDivide_gh * localAdd2_i) * 32768.0F;

  /* Switch: '<S74>/Switch1' incorporates:
   *  Constant: '<S74>/offset2'
   *  Constant: '<S74>/offset3'
   *  Constant: '<S74>/offset4'
   *  RelationalOperator: '<S74>/Relational Operator'
   *  Sum: '<S74>/Add3'
   *  Sum: '<S74>/Add4'
   */
  if (localDataTypeConversion5 >= 0.0F) {
    localDataTypeConversion5 += 0.5F;
  } else {
    localDataTypeConversion5 -= 0.5F;
  }

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S62>/Byp_Fonction_SC'
   *  Constant: '<S62>/Int_BypC'
   *  DataTypeConversion: '<S74>/OutDTConv'
   */
  if (TRBACTMGT_ACTIVE_BYP_C) {
    localTrbAct_rRCOICorReq_d = TrbAct_rRCOICorReq_B;
  } else if (localDataTypeConversion5 < 32768.0F) {
    if (localDataTypeConversion5 >= -32768.0F) {
      localTrbAct_rRCOICorReq_d = (SInt16)localDataTypeConversion5;
    } else {
      localTrbAct_rRCOICorReq_d = MIN_int16_T;
    }
  } else {
    localTrbAct_rRCOICorReq_d = MAX_int16_T;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_bInhICorInport2' */
  Rte_Write_P_TrbAct_bInhICor_TrbAct_bInhICor(localTmpSignalConversionAtTrb_k);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pUsThrCorReqInport2' */
  Rte_Write_P_TrbAct_pUsThrCorReq_TrbAct_pUsThrCorReq
    (localTmpSignalConversionAtTrbAc);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pUsThrICorReq_irvInport2' incorporates:
   *  SignalConversion: '<S6>/Signal Conversion'
   */
  Rte_IrvWrite_RE_TrbActMgt_003_TEV_TrbAct_pUsThrICorReq_irv
    (locallocalOutDTConv_p);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rRCOICorReqInport2' */
  Rte_Write_P_TrbAct_rRCOICorReq_TrbAct_rRCOICorReq(localTrbAct_rRCOICorReq_d);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rRCOPIDCorReqInport2' */
  Rte_Write_P_TrbAct_rRCOPIDCorReq_TrbAct_rRCOPIDCorReq
    (localTrbAct_rRCOPIDCorReq_n);
}

/* Model initialize function */
void RE_TrbActMgt_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  RE_TrbActMgt_001_MSE_Start();
  RE_TrbActMgt_002_TEV_Start();
  RE_TrbActMgt_003_TEV_Start();
  TrbActMgt_PrevZCSigState.F02_IParInit_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__3'
   */
  RE_TrbActMgt_002_TEV_Init();
  RE_TrbActMgt_003_TEV_Init();
}

#define TrbActMgt_STOP_SEC_CODE
#include "TrbActMgt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
