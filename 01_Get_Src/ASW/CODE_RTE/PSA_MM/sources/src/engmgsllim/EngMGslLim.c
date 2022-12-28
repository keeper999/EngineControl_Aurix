/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslLim                                              */
/* !Description     : EngMGslLim Software Component                           */
/*                                                                            */
/* !Module          : EngMGslLim                                              */
/* !Description     : EngMGslLim Software Component                           */
/*                                                                            */
/* !File            : EngMGslLim.c                                            */
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
/*   Model name       : EngMGslLim_AUTOSAR.mdl                                */
/*   Root subsystem   : /EngMGslLim                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M16-EngMGslLim/5$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   08 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngMGslLim.h"
#include "EngMGslLim_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S29>/F01_OvbMgr' */
#define IN_Attente_Requette_Overboost  (1U)
#define IN_Desactivation_Overboost_1   (2U)
#define IN_Desactivation_Overboost_2   (3U)
#define IN_Inhibition_de_l_overboost   (4U)
#define IN_OverBoost_Active            (5U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define EngMGslLim_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "EngMGslLim_MemMap.h"

/* Block signals (auto storage) */
BlockIO_EngMGslLim EngMGslLim_B;

/* Block states (auto storage) */
D_Work_EngMGslLim EngMGslLim_DWork;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "EngMGslLim_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define ENGMGSLLIM_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define ENGMGSLLIM_VEMSRTLIBT_MINOR_VERSION_REQ 7
#define ENGMGSLLIM_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ENGMGSLLIM_VEMSRTLIBT_VERSION_REQ (ENGMGSLLIM_VEMSRTLIBT_PATCH_VERSION_REQ + ENGMGSLLIM_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ENGMGSLLIM_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ENGMGSLLIM_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define EngMGslLim_START_SEC_CODE
#include "EngMGslLim_MemMap.h"

void EngMGslLim_ASYNC1(int controlPortIdx)
{
}

void EngMGslLim_ASYNC2(int controlPortIdx)
{
}

void EngMGslLim_ASYNC3(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/F01_Init' */
void EngMGslLim_F01_Init(void)
{
  /* local block i/o variables */
  UInt32 localDataTypeConversion3;
  UInt16 localTmpSignalConversionAtTPM_r;
  Boolean localSwitch_o;
  UInt16 localrr;

  /* user code (Output function Body for TID6) */
  Runnable_EngMGslLim_Init();

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S16>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/EngMTrb_facOvbAcvIni_C'
   */

  /* S-Function Block: <S16>/autosar_testpoint1 */
  EngMTrb_facOvbAcv_IRV_MP = EngMTrb_facOvbAcvIni_C;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_facOvbAcvInport2' incorporates:
   *  Constant: '<S5>/EngMTrb_facOvbAcvIni_C'
   *  SignalConversion: '<S5>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_facOvbAcv_irv
    (EngMTrb_facOvbAcvIni_C);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S17>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/EngMTrb_facOvbReqIni_C'
   */

  /* S-Function Block: <S17>/autosar_testpoint1 */
  EngMTrb_facOvbReq_IRV_MP = EngMTrb_facOvbReqIni_C;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_facOvbReqInport2' incorporates:
   *  Constant: '<S5>/EngMTrb_facOvbReqIni_C'
   *  SignalConversion: '<S5>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_facOvbReq_irv
    (EngMTrb_facOvbReqIni_C);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S8>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/OvbCtl_stOvbIni_C'
   */

  /* S-Function Block: <S8>/autosar_testpoint1 */
  OvbCtl_stOvb_IRV_MP = OvbCtl_stOvbIni_C;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtOvbCtl_stOvbInport2' incorporates:
   *  Constant: '<S5>/OvbCtl_stOvbIni_C'
   *  SignalConversion: '<S5>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_OvbCtl_stOvb_irv(OvbCtl_stOvbIni_C);

  /* SignalConversion: '<S13>/copy' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxLoRonIni_C'
   */
  EngMTrb_rLdMaxLoRonIni_IRV_MP = EngMTrb_rLdMaxLoRonIni_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S13>/autosar_testpoint1' */

  /* S-Function Block: <S13>/autosar_testpoint1 */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_rLdMaxLoRonIni_irvInport2' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxLoRonIni_C'
   *  SignalConversion: '<S5>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_rLdMaxLoRonIni_irv
    (EngMTrb_rLdMaxLoRonIni_C);

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Byp_Fonction_SC'
   *  Constant: '<S19>/Int_BypC'
   *  Constant: '<S5>/EngMTrb_rLdMaxOvbAcvIni_C'
   */
  if (ENGMGSLLIM_ACTIVE_BYP_C) {
    localrr = EngMTrb_rLdMaxOvbAcv_B;
  } else {
    localrr = EngMTrb_rLdMaxOvbAcvIni_C;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_rLdMaxOvbAcvInport2' */
  Rte_Write_P_EngMTrb_rLdMaxOvbAcv_EngMTrb_rLdMaxOvbAcv(localrr);

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Byp_Fonction_SC'
   *  Constant: '<S20>/Int_BypC'
   *  Constant: '<S5>/EngMTrb_rLdMaxIni_C'
   */
  if (ENGMGSLLIM_ACTIVE_BYP_C) {
    localrr = EngMTrb_rLdMax_B;
  } else {
    localrr = EngMTrb_rLdMaxIni_C;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_rLdMaxInport2' */
  Rte_Write_P_EngMTrb_rLdMax_EngMTrb_rLdMax(localrr);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S9>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxIrvRblIni_C'
   */

  /* S-Function Block: <S9>/autosar_testpoint1 */
  EngMTrb_prm_rLdMaxIrvRbl_001 = EngMTrb_rLdMaxIrvRblIni_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S14>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxIrvRblIni_C'
   */

  /* S-Function Block: <S14>/autosar_testpoint1 */
  EngMTrb_prm_rLdMaxIrvRbl_002 = EngMTrb_rLdMaxIrvRblIni_C;

  /* SignalConversion: '<S5>/Signal Conversion2' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxIrvRblIni_C'
   */
  localrr = EngMTrb_rLdMaxIrvRblIni_C;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxIrvRbl1Inport2' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxIrvRblIni_C'
   *  SignalConversion: '<S5>/Signal Conversion11'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_prm_rLdMaxIrvRbl_001_irv
    (EngMTrb_rLdMaxIrvRblIni_C);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxIrvRbl2Inport2' */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_prm_rLdMaxIrvRbl_002_irv(localrr);

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Byp_Fonction_SC'
   *  Constant: '<S18>/Int_BypC'
   *  Constant: '<S5>/EngMTrb_bAcvProtKnkIni_C'
   */
  if (ENGMGSLLIM_ACTIVE_BYP_C) {
    localSwitch_o = EngMTrb_bAcvProtKnk_B;
  } else {
    localSwitch_o = EngMTrb_bAcvProtKnkIni_C;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_bAcvProtKnkInport2' */
  Rte_Write_P_EngMTrb_bAcvProtKnk_EngMTrb_bAcvProtKnk(localSwitch_o);

  /* DataTypeConversion: '<S5>/Data Type Conversion3' incorporates:
   *  Constant: '<S5>/EngMTrb_facProtKnkIni_C'
   */
  localDataTypeConversion3 = (UInt32)(EngMTrb_facProtKnkIni_C << 2);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S12>/autosar_testpoint1' */

  /* S-Function Block: <S12>/autosar_testpoint1 */
  EngMTrb_facProtKnk_IRV_MP = localDataTypeConversion3;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_facProtKnkInport2' incorporates:
   *  SignalConversion: '<S5>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_facProtKnk_irv
    (localDataTypeConversion3);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S11>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxTotIni_C'
   */

  /* S-Function Block: <S11>/autosar_testpoint1 */
  EngMTrb_prm_rLdMaxTot_001 = EngMTrb_rLdMaxTotIni_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S15>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxTotIni_C'
   */

  /* S-Function Block: <S15>/autosar_testpoint1 */
  EngMTrb_prm_rLdMaxTot_002 = EngMTrb_rLdMaxTotIni_C;

  /* SignalConversion: '<S5>/Signal Conversion4' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxTotIni_C'
   */
  localrr = EngMTrb_rLdMaxTotIni_C;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxTot1Inport2' incorporates:
   *  Constant: '<S5>/EngMTrb_rLdMaxTotIni_C'
   *  SignalConversion: '<S5>/Signal Conversion10'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_prm_rLdMaxTot_001_irv
    (EngMTrb_rLdMaxTotIni_C);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxTot2Inport2' */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_prm_rLdMaxTot_002_irv(localrr);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTPM_rLdProtExThermoOutport2' incorporates:
   *  Inport: '<Root>/TPM_rLdProtExThermo'
   */
  Rte_Read_R_TPM_rLdProtExThermo_TPM_rLdProtExThermo
    (&localTmpSignalConversionAtTPM_r);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S10>/autosar_testpoint1' */

  /* S-Function Block: <S10>/autosar_testpoint1 */
  EngMTrb_rLdProtTPMFrz_IRV_MP = localTmpSignalConversionAtTPM_r;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngMTrb_rLdProtTPMFrz_irvInport2' incorporates:
   *  SignalConversion: '<S5>/Signal Conversion13'
   */
  Rte_IrvWrite_RE_EngMGslLim_001_MSE_EngMTrb_rLdProtTPMFrz_irv
    (localTmpSignalConversionAtTPM_r);
}

/* Output and update for exported function: RE_EngMGslLim_001_MSE */
void RE_EngMGslLim_001_MSE(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Init'
   *
   * Block requirements for '<S1>/F01_Init':
   *  1. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_034.01 ;
   *  2. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_035.01 ;
   *  3. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_036.01 ;
   *  4. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_037.01 ;
   *  5. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_038.01 ;
   *  6. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_039.01 ;
   *  7. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_040.01 ;
   *  8. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_041.01 ;
   *  9. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_042.01 ;
   *  10. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_043.01 ;
   *  11. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_044.01 ;
   *  12. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_045.01 ;
   *  13. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_047.01 ;
   *  14. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_046.01 ;
   *  15. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_031.01 ;
   *  16. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_032.01 ;
   *  17. SubSystem "F01_Init" !Trace_To : EMS_R_11_01002_048.01 ;
   *  18. SubSystem "F01_Init" !Trace_To : VEMS_R_11_01002_028.02 ;
   *  19. SubSystem "F01_Init" !Trace_To : VEMS_R_11_01002_011.02 ;
   *  20. SubSystem "F01_Init" !Trace_To : VEMS_R_11_01002_012.03 ;
   *  21. SubSystem "F01_Init" !Trace_To : VEMS_R_11_01002_030.02 ;
   *  22. SubSystem "F01_Init" !Trace_To : VEMS_R_11_01002_033.01 ;
   */
  EngMGslLim_F01_Init();
}

/* Output and update for function-call system: '<S1>/F02_Compute' */
void EngMGslLim_F02_Compute(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion1_o;
  UInt16 localDataTypeConversion;
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable;
  UInt16 localSwitch2_nl;
  Boolean localLogic[2];
  Boolean localAutosarServer;
  Boolean localLogicalOperator3;
  Boolean localUnitDelay;
  Boolean localR;
  UInt8 localTmpSignalConversionAtOvbCt;
  Boolean localNot;
  Float32 localDivide_f;
  Boolean localLowerRelop1_l;
  Float32 localSwitch_h;
  Float32 localSwitch2;
  Boolean localTmpSignalConversionAtTPM_b;
  Boolean localTmpSignalConversionAtEngMT;
  Boolean localTmpSignalConversionAtVlvAc;
  Boolean localTmpSignalConversionAtVlv_h;
  Boolean localTmpSignalConversionAtMPM_b;
  Boolean localTmpSignalConversionAtCoP_b;
  Boolean localTmpSignalConversionAtTrbAc;
  UInt16 localTmpSignalConversionAtCoPt_;
  UInt32 localSwitch_i;
  UInt32 localDataTypeConversion1_m;
  UInt16 localTmpSignalConversionAtMPM_f;
  SInt32 locallocalOutDTConv;
  SInt32 localq;
  SInt32 localqY;
  UInt32 localtmp;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&EngMGslLim_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes
    (&EngMGslLim_B.TmpSignalConversionAtUsThrM_tTh);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtMPM_facOvbReqOutport2' incorporates:
   *  Inport: '<Root>/MPM_facOvbReq'
   */
  Rte_Read_R_MPM_facOvbReq_MPM_facOvbReq(&localTmpSignalConversionAtMPM_f);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtCoPt_tiDeacPrfModOutport2' incorporates:
   *  Inport: '<Root>/CoPt_tiDeacPrfMod'
   */
  Rte_Read_R_CoPt_tiDeacPrfMod_CoPt_tiDeacPrfMod
    (&localTmpSignalConversionAtCoPt_);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtCoPt_bPrfModReqOutport2' incorporates:
   *  Inport: '<Root>/CoPt_bPrfModReq'
   */
  Rte_Read_R_CoPt_bPrfModReq_CoPt_bPrfModReq(&localTmpSignalConversionAtCoP_b);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtVlvAct_bAcvExServoOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_bAcvExServo'
   */
  Rte_Read_R_VlvAct_bAcvExServo_VlvAct_bAcvExServo
    (&localTmpSignalConversionAtVlvAc);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtVlvAct_bAcvInServoOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_bAcvInServo'
   */
  Rte_Read_R_VlvAct_bAcvInServo_VlvAct_bAcvInServo
    (&localTmpSignalConversionAtVlv_h);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&EngMGslLim_B.TmpSignalConversionAtExt_tCoMes);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTPM_bInhOvbReqOutport2' incorporates:
   *  Inport: '<Root>/TPM_bInhOvbReq'
   */
  Rte_Read_R_TPM_bInhOvbReq_TPM_bInhOvbReq(&localTmpSignalConversionAtTPM_b);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_bBoostPresClCtlAcvOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bBoostPresClCtlAcv'
   */
  Rte_Read_R_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv
    (&localTmpSignalConversionAtTrbAc);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtKnkMgt_bAcvTmpLdLimRblReqOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_bAcvTmpLdLimRblReq'
   */
  Rte_Read_R_KnkMgt_bAcvTmpLdLimRblReq_KnkMgt_bAcvTmpLdLimRblReq
    (&EngMGslLim_B.TmpSignalConversionAtKnkMgt_bAc);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtKnkMgt_bAcvTmpLdLimKnkReqOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_bAcvTmpLdLimKnkReq'
   */
  Rte_Read_R_KnkMgt_bAcvTmpLdLimKnkReq_KnkMgt_bAcvTmpLdLimKnkReq
    (&EngMGslLim_B.TmpSignalConversionAtKnkMgt_b_k);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtMPM_bOvbStopOutport2' incorporates:
   *  Inport: '<Root>/MPM_bOvbStop'
   */
  Rte_Read_R_MPM_bOvbStop_MPM_bOvbStop(&localTmpSignalConversionAtMPM_b);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtEngMTrb_bAcvProtKnkOutport2' incorporates:
   *  Inport: '<Root>/EngMTrb_bAcvProtKnk_INPUT'
   */
  Rte_Read_R_EngMTrb_bAcvProtKnk_EngMTrb_bAcvProtKnk
    (&localTmpSignalConversionAtEngMT);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtEngMTrb_facOvbReqPrevOutport2' */
  EngMGslLim_B.TmpSignalConversionAtEngMTrb_fa =
    Rte_IrvRead_RE_EngMGslLim_002_TEV_EngMTrb_facOvbReq_irv();

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOvbCtl_stOvbPrevOutport2' */
  localTmpSignalConversionAtOvbCt =
    Rte_IrvRead_RE_EngMGslLim_002_TEV_OvbCtl_stOvb_irv();

  /* SignalConversion: '<S6>/TmpSignal ConversionAtEngMTrb_facOvbAcvPrevOutport2' */
  EngMGslLim_B.TmpSignalConversionAtEngMTrb__m =
    Rte_IrvRead_RE_EngMGslLim_002_TEV_EngMTrb_facOvbAcv_irv();

  /* Outputs for enable SubSystem: '<S6>/F01_Compute' incorporates:
   *  Constant: '<S6>/OvbCtl_bAcvOvb_C'
   *  EnablePort: '<S21>/Enable'
   *  EnablePort: '<S22>/Enable'
   *  Logic: '<S6>/Logical Operator'
   *  SubSystem: '<S6>/F01_Compute_Inverse'
   *
   * Block requirements for '<S6>/F01_Compute':
   *  1. SubSystem "F01_Compute" !Trace_To : VEMS_R_11_01002_053.01 ;
   */
  if (OvbCtl_bAcvOvb_C) {
    /* Outputs for atomic SubSystem: '<S21>/F01_facOvbAcv' *
     * Block requirements for '<S21>/F01_facOvbAcv':
     *  1. SubSystem "F01_facOvbAcv" !Trace_To : VEMS_R_11_01002_005.01 ;
     */

    /* DataTypeConversion: '<S33>/Data Type Conversion' */
    localDataTypeConversion = EngMGslLim_B.TmpSignalConversionAtUsThrM_tTh;

    /* DataTypeConversion: '<S33>/Data Type Conversion1' */
    localDataTypeConversion1_o = EngMGslLim_B.TmpSignalConversionAtExt_nEngOu;

    /* Lookup2D: '<S33>/Look-Up Table (2-D)'
     * About '<S33>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-15  Bias 1.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D), (&(OvbCtl_facOvbBas_M[0])),
                       localDataTypeConversion, (&(OvbCtl_tThrMesX_A[0])), 3U,
                       localDataTypeConversion1_o, (&(OvbCtl_nEngY_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S33>/Data Type Duplicate2'
     *
     * Regarding '<S33>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S23>/EngMTrb_bMPMAcv_C'
     *  DataTypeConversion: '<S33>/Data Type Conversion'
     *  DataTypeConversion: '<S33>/Data Type Conversion1'
     *  Lookup2D: '<S33>/Look-Up Table (2-D)'
     */
    if (!EngMTrb_bMPMAcv_C) {
      localTmpSignalConversionAtMPM_f = localLookUpTable2D;
    }

    /* Switch: '<S23>/Switch2' incorporates:
     *  Constant: '<S23>/OvbCtl_stOvbStopReq_C'
     *  Constant: '<S23>/OvbCtl_stOvbStop_C'
     *  Logic: '<S23>/Logical Operator'
     *  RelationalOperator: '<S23>/Relational Operator2'
     *  RelationalOperator: '<S23>/Relational Operator3'
     */
    if ((localTmpSignalConversionAtOvbCt == OvbCtl_stOvbStopReq_C) ||
        (localTmpSignalConversionAtOvbCt == OvbCtl_stOvbStop_C)) {
      localTmpSignalConversionAtMPM_f =
        EngMGslLim_B.TmpSignalConversionAtEngMTrb__m;
    }

    /* end of Outputs for SubSystem: '<S21>/F01_facOvbAcv' */

    /* SignalConversion: '<S31>/copy' */
    EngMTrb_facOvbAcv_IRV_MP = localTmpSignalConversionAtMPM_f;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S31>/autosar_testpoint1' */

    /* S-Function Block: <S31>/autosar_testpoint1 */

    /* S-Function (sfun_autosar_clientop): '<S30>/AutosarServer' */
    Rte_Call_R_FRM_bRedLdMax_GetFunctionPermission(&localAutosarServer);

    /* Logic: '<S30>/Not' */
    localNot = !localAutosarServer;

    /* Outputs for atomic SubSystem: '<S21>/F02_Integrateur_Sortie_Ovb' *
     * Block requirements for '<S21>/F02_Integrateur_Sortie_Ovb':
     *  1. SubSystem "F02_Integrateur_Sortie_Ovb" !Trace_To : VEMS_R_11_01002_006.02 ;
     */

    /* Product: '<S36>/Divide' incorporates:
     *  Constant: '<S24>/Cste_1'
     *  Constant: '<S24>/OvbCtl_tiSampleFast_SC'
     *  DataTypeConversion: '<S24>/Data Type Conversion1'
     *  DataTypeConversion: '<S24>/Data Type Conversion2'
     *  DataTypeConversion: '<S24>/Data Type Conversion4'
     *  Product: '<S37>/Divide'
     *  Sum: '<S24>/Sum1'
     */
    localDivide_f = (1.0F - ((((Float32)
      EngMGslLim_B.TmpSignalConversionAtEngMTrb__m) * 3.051757813E-005F) + 1.0F))
      / ((((Float32)localTmpSignalConversionAtCoPt_) * 9.999999776E-003F) /
         (((Float32)OvbCtl_tiSampleFast_SC) * 1.000000047E-003F));

    /* Outputs for atomic SubSystem: '<S36>/If Action Subsystem3' */

    /* Switch: '<S42>/Switch1' incorporates:
     *  Constant: '<S42>/Constant1'
     *  Constant: '<S42>/Constant2'
     *  Constant: '<S42>/Constant3'
     *  Logic: '<S42>/Logical Operator1'
     *  RelationalOperator: '<S42>/Relational Operator'
     *  RelationalOperator: '<S42>/Relational Operator1'
     *  RelationalOperator: '<S42>/Relational Operator3'
     */
    if (((localDivide_f != localDivide_f) || (localDivide_f > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_f)) {
      localDivide_f = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S36>/If Action Subsystem3' */

    /* Product: '<S35>/Product4' incorporates:
     *  Constant: '<S35>/offset'
     *  Constant: '<S35>/one_on_slope'
     *  Sum: '<S35>/Add1'
     */
    localDivide_f *= 32768.0F;

    /* Switch: '<S35>/Switch1' incorporates:
     *  Constant: '<S35>/offset2'
     *  Constant: '<S35>/offset3'
     *  Constant: '<S35>/offset4'
     *  RelationalOperator: '<S35>/Relational Operator'
     *  Sum: '<S35>/Add3'
     *  Sum: '<S35>/Add4'
     */
    if (localDivide_f >= 0.0F) {
      localDivide_f += 0.5F;
    } else {
      localDivide_f -= 0.5F;
    }

    /* DataTypeConversion: '<S35>/OutDTConv' */
    if (localDivide_f < 2.147483648E+009F) {
      if (localDivide_f >= -2.147483648E+009F) {
        locallocalOutDTConv = (SInt32)localDivide_f;
      } else {
        locallocalOutDTConv = MIN_int32_T;
      }
    } else {
      locallocalOutDTConv = MAX_int32_T;
    }

    /* DataStoreWrite: '<S24>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     */
    if (locallocalOutDTConv > 32767) {
      OvbCtl_facOvbDec_MP = MAX_int16_T;
    } else if (locallocalOutDTConv <= -32768) {
      OvbCtl_facOvbDec_MP = MIN_int16_T;
    } else {
      OvbCtl_facOvbDec_MP = (SInt16)locallocalOutDTConv;
    }

    /* Sum: '<S24>/Sum2' */
    localq = EngMGslLim_B.TmpSignalConversionAtEngMTrb_fa;
    localqY = localq + locallocalOutDTConv;
    if ((localq > 0) && ((locallocalOutDTConv > 0) && (localqY <= 0))) {
      localqY = MAX_int32_T;
    }

    if (localqY <= 0) {
      localTmpSignalConversionAtCoPt_ = 0U;
    } else if (localqY > 65535) {
      localTmpSignalConversionAtCoPt_ = MAX_uint16_T;
    } else {
      localTmpSignalConversionAtCoPt_ = (UInt16)localqY;
    }

    /* Switch: '<S24>/Switch1' incorporates:
     *  Constant: '<S24>/OvbCtl_stOvbStopReq_C'
     *  Constant: '<S24>/OvbCtl_stOvbStop_C'
     *  Logic: '<S24>/Logical Operator'
     *  RelationalOperator: '<S24>/Relational Operator1'
     *  RelationalOperator: '<S24>/Relational Operator2'
     */
    if (!((localTmpSignalConversionAtOvbCt == OvbCtl_stOvbStopReq_C) ||
          (localTmpSignalConversionAtOvbCt == OvbCtl_stOvbStop_C))) {
      localTmpSignalConversionAtCoPt_ =
        EngMGslLim_B.TmpSignalConversionAtEngMTrb_fa;
    }

    /* Switch: '<S40>/Switch2' incorporates:
     *  Constant: '<S24>/OvbCtl_facOvbMax_C'
     *  RelationalOperator: '<S40>/LowerRelop1'
     */
    if (localTmpSignalConversionAtCoPt_ > OvbCtl_facOvbMax_C) {
      OvbCtl_facOvbStop = OvbCtl_facOvbMax_C;
    } else {
      OvbCtl_facOvbStop = localTmpSignalConversionAtCoPt_;
    }

    /* end of Outputs for SubSystem: '<S21>/F02_Integrateur_Sortie_Ovb' */

    /* Outputs for atomic SubSystem: '<S21>/F06_Conditions_Pilotage_VVT' *
     * Block requirements for '<S21>/F06_Conditions_Pilotage_VVT':
     *  1. SubSystem "F06_Conditions_Pilotage_VVT" !Trace_To : VEMS_R_11_01002_051.01 ;
     */

    /* Switch: '<S28>/Switch1' incorporates:
     *  Constant: '<S28>/Cste_1'
     *  Constant: '<S28>/OvbCtl_bPresInServo_C'
     */
    if (!OvbCtl_bPresInServo_C) {
      localTmpSignalConversionAtVlvAc = TRUE;
    }

    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S28>/Cste_1_1'
     *  Constant: '<S28>/OvbCtl_bPresExServo_C'
     */
    if (!OvbCtl_bPresExServo_C) {
      localTmpSignalConversionAtVlv_h = TRUE;
    }

    /* Logic: '<S28>/Logical Operator' */
    OvbCtl_bAcvVlvServo = ((localTmpSignalConversionAtVlvAc) &&
      (localTmpSignalConversionAtVlv_h));

    /* end of Outputs for SubSystem: '<S21>/F06_Conditions_Pilotage_VVT' */

    /* Outputs for atomic SubSystem: '<S21>/F03_Calcul_du_temps_de_guerison' *
     * Block requirements for '<S21>/F03_Calcul_du_temps_de_guerison':
     *  1. SubSystem "F03_Calcul_du_temps_de_guerison" !Trace_To : VEMS_R_11_01002_007.02 ;
     */

    /* RelationalOperator: '<S25>/Relational Operator2' incorporates:
     *  Constant: '<S25>/OvbCtl_stOvb_C'
     */
    localTmpSignalConversionAtVlv_h = (localTmpSignalConversionAtOvbCt ==
      OvbCtl_stOvb_C);

    /* DataTypeConversion: '<S54>/Conversion' incorporates:
     *  Constant: '<S45>/Constant4'
     */
    localSwitch_i = mul_u32_u32_u32_sat(MAX_uint32_T, 1000U);
    if (localSwitch_i > 65535U) {
      localLookUpTable = MAX_uint16_T;
    } else {
      localLookUpTable = (UInt16)localSwitch_i;
    }

    /* Switch: '<S56>/Switch' incorporates:
     *  Constant: '<S25>/OvbCtl_tiSampleFast_SC'
     *  Constant: '<S45>/Constant5'
     *  RelationalOperator: '<S56>/UpperRelop'
     */
    localSwitch2_nl = OvbCtl_tiSampleFast_SC;

    /* Switch: '<S56>/Switch2' incorporates:
     *  Constant: '<S25>/OvbCtl_tiSampleFast_SC'
     *  RelationalOperator: '<S56>/LowerRelop1'
     */
    if (!(OvbCtl_tiSampleFast_SC > localLookUpTable)) {
      localLookUpTable = localSwitch2_nl;
    }

    /* Sum: '<S45>/Sum1' incorporates:
     *  UnitDelay: '<S53>/Unit Delay'
     */
    locallocalOutDTConv = localLookUpTable;
    localDataTypeConversion1_m = ((UInt32)locallocalOutDTConv) +
      EngMGslLim_DWork.UnitDelay_DSTATE_ew;
    if (localDataTypeConversion1_m < ((UInt32)locallocalOutDTConv)) {
      localDataTypeConversion1_m = MAX_uint32_T;
    }

    /* RelationalOperator: '<S25>/Relational Operator1' incorporates:
     *  Constant: '<S25>/OvbCtl_stOvbAcv_C'
     */
    localLowerRelop1_l = (localTmpSignalConversionAtOvbCt == OvbCtl_stOvbAcv_C);

    /* Switch: '<S45>/Switch1' incorporates:
     *  UnitDelay: '<S53>/Unit Delay'
     */
    if (!localLowerRelop1_l) {
      localDataTypeConversion1_m = EngMGslLim_DWork.UnitDelay_DSTATE_ew;
    }

    /* Switch: '<S45>/Switch2' incorporates:
     *  Constant: '<S45>/Constant1'
     *  Logic: '<S52>/Logical Operator'
     *  Logic: '<S52>/Logical Operator1'
     *  UnitDelay: '<S60>/Unit Delay'
     */
    if ((localTmpSignalConversionAtVlv_h) &&
        (!EngMGslLim_DWork.UnitDelay_DSTATE_j4)) {
      localDataTypeConversion1_m = 0U;
    }

    /* Switch: '<S59>/Switch2' incorporates:
     *  Constant: '<S45>/Cnt_Max'
     *  RelationalOperator: '<S59>/LowerRelop1'
     */
    if (localDataTypeConversion1_m > 600000U) {
      localDataTypeConversion1_m = 600000U;
    }

    /* DataTypeConversion: '<S43>/Data Type Conversion' */
    localSwitch_i = mul_u32_u32_u32_sr37_sat(localDataTypeConversion1_m,
      2748779069U);
    if (localSwitch_i > 65535U) {
      localSwitch2_nl = MAX_uint16_T;
    } else {
      localSwitch2_nl = (UInt16)localSwitch_i;
    }

    /* Lookup: '<S43>/Look-Up Table'
     * About '<S43>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-5  FSlope 1.6
     * Output0 Data Type:  Fixed Point    U16  2^-5  FSlope 1.6
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(OvbCtl_tiDlyInh_T[0])),
                   localSwitch2_nl, (&(OvbCtl_ctTiOvbAcv_A[0])), 7U);

    /* DataTypeDuplicate Block: '<S43>/Data Type Duplicate1'
     *
     * Regarding '<S43>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S47>/Conversion' incorporates:
     *  Constant: '<S25>/OvbCtl_tiDlyMax_C'
     */
    localqY = OvbCtl_tiDlyMax_C;

    /* DataTypeConversion: '<S65>/Conversion' incorporates:
     *  Constant: '<S46>/Constant4'
     */
    localSwitch_i = mul_u32_u32_u32_sat(MAX_uint32_T, 1000U);
    if (localSwitch_i > 65535U) {
      localSwitch2_nl = MAX_uint16_T;
    } else {
      localSwitch2_nl = (UInt16)localSwitch_i;
    }

    /* Switch: '<S67>/Switch2' incorporates:
     *  Constant: '<S25>/OvbCtl_tiSampleFast_SC'
     *  Constant: '<S46>/Constant5'
     *  RelationalOperator: '<S67>/LowerRelop1'
     *  RelationalOperator: '<S67>/UpperRelop'
     *  Switch: '<S67>/Switch'
     */
    if (!(OvbCtl_tiSampleFast_SC > localSwitch2_nl)) {
      localSwitch2_nl = OvbCtl_tiSampleFast_SC;
    }

    /* Sum: '<S46>/Sum1' incorporates:
     *  UnitDelay: '<S64>/Unit Delay'
     */
    locallocalOutDTConv = localSwitch2_nl;
    localSwitch_i = ((UInt32)locallocalOutDTConv) +
      EngMGslLim_DWork.UnitDelay_DSTATE_ct;
    if (localSwitch_i < ((UInt32)locallocalOutDTConv)) {
      localSwitch_i = MAX_uint32_T;
    }

    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S25>/OvbCtl_stOvbInh_C'
     *  RelationalOperator: '<S25>/Relational Operator3'
     *  UnitDelay: '<S64>/Unit Delay'
     */
    if (localTmpSignalConversionAtOvbCt != OvbCtl_stOvbInh_C) {
      localSwitch_i = EngMGslLim_DWork.UnitDelay_DSTATE_ct;
    }

    /* Switch: '<S46>/Switch2' incorporates:
     *  Constant: '<S46>/Constant1'
     *  Logic: '<S63>/Logical Operator'
     *  Logic: '<S63>/Logical Operator1'
     *  UnitDelay: '<S71>/Unit Delay'
     */
    if ((localLowerRelop1_l) && (!EngMGslLim_DWork.UnitDelay_DSTATE_oa)) {
      localSwitch_i = 0U;
    }

    /* Switch: '<S70>/Switch2' incorporates:
     *  Constant: '<S46>/Cnt_Max'
     *  RelationalOperator: '<S70>/LowerRelop1'
     */
    if (localSwitch_i > 3600000U) {
      localSwitch_i = 3600000U;
    }

    /* Sum: '<S25>/Sum3' incorporates:
     *  DataTypeConversion: '<S25>/Data Type Conversion1'
     */
    locallocalOutDTConv = localLookUpTable;
    localtmp = mul_u32_u32_u32_sr37(localSwitch_i, 2748779069U);
    if (localtmp > 2147483647U) {
      localq = MAX_int32_T;
    } else {
      localq = (SInt32)localtmp;
    }

    locallocalOutDTConv -= localq;
    localq = locallocalOutDTConv;

    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S25>/OvbCtl_tiDlyMin_C'
     *  RelationalOperator: '<S49>/UpperRelop'
     */
    if (locallocalOutDTConv < 0) {
      localq = 0;
    }

    /* Switch: '<S49>/Switch2' incorporates:
     *  RelationalOperator: '<S49>/LowerRelop1'
     */
    if (!(locallocalOutDTConv > localqY)) {
      localqY = localq;
    }

    /* DataTypeConversion: '<S25>/Conversion' */
    if (localqY <= 0) {
      OvbCtl_tiDly = 0U;
    } else if (localqY > 65535) {
      OvbCtl_tiDly = MAX_uint16_T;
    } else {
      OvbCtl_tiDly = (UInt16)localqY;
    }

    /* Update for UnitDelay: '<S60>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_j4 = localTmpSignalConversionAtVlv_h;

    /* Update for UnitDelay: '<S53>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_ew = localDataTypeConversion1_m;

    /* Update for UnitDelay: '<S71>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_oa = localLowerRelop1_l;

    /* Update for UnitDelay: '<S64>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_ct = localSwitch_i;

    /* end of Outputs for SubSystem: '<S21>/F03_Calcul_du_temps_de_guerison' */

    /* Outputs for atomic SubSystem: '<S21>/F04_temps_max_ovb' *
     * Block requirements for '<S21>/F04_temps_max_ovb':
     *  1. SubSystem "F04_temps_max_ovb" !Trace_To : VEMS_R_11_01002_008.02 ;
     */

    /* DataTypeConversion: '<S26>/Conversion' incorporates:
     *  Constant: '<S26>/OvbCtl_tiSampleFast_SC'
     */
    localDivide_f = ((Float32)OvbCtl_tiSampleFast_SC) * 1.000000047E-003F;

    /* RelationalOperator: '<S26>/Relational Operator1' incorporates:
     *  Constant: '<S26>/OvbCtl_stOvbAcv_C'
     */
    localTmpSignalConversionAtVlvAc = (localTmpSignalConversionAtOvbCt ==
      OvbCtl_stOvbAcv_C);

    /* Logic: '<S72>/Logical Operator3' */
    localLogicalOperator3 = !localTmpSignalConversionAtVlvAc;

    /* UnitDelay: '<S76>/Unit Delay' */
    localUnitDelay = EngMGslLim_DWork.UnitDelay_DSTATE_efy;

    /* UnitDelay: '<S84>/Unit Delay' */
    localR = EngMGslLim_DWork.UnitDelay_DSTATE_j;

    /* Sum: '<S72>/Sum2' incorporates:
     *  Constant: '<S26>/OvbCtl_tiMaxAcv_C'
     *  Constant: '<S72>/Constant1'
     *  Constant: '<S72>/Constant6'
     *  MinMax: '<S72>/MinMax1'
     *  Product: '<S77>/Divide'
     */
    localSwitch2 = (((Float32)OvbCtl_tiMaxAcv_C) * 9.999999776E-003F) + (10.0F *
      localDivide_f);

    /* UnitDelay: '<S75>/Unit Delay' */
    localSwitch_h = EngMGslLim_DWork.UnitDelay_DSTATE_f;

    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S72>/Constant3'
     *  RelationalOperator: '<S82>/UpperRelop'
     */
    if (EngMGslLim_DWork.UnitDelay_DSTATE_f < 0.0F) {
      localSwitch_h = 0.0F;
    }

    /* Switch: '<S82>/Switch2' incorporates:
     *  RelationalOperator: '<S82>/LowerRelop1'
     */
    if (!(EngMGslLim_DWork.UnitDelay_DSTATE_f > localSwitch2)) {
      localSwitch2 = localSwitch_h;
    }

    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S72>/Constant4'
     *  Constant: '<S72>/Constant7'
     *  Logic: '<S72>/Logical Operator2'
     *  Logic: '<S78>/Logical Operator'
     *  Logic: '<S78>/Logical Operator1'
     *  Sum: '<S72>/Sum1'
     */
    if ((localUnitDelay) || ((localTmpSignalConversionAtVlvAc) && (!localR))) {
      localDivide_f = 0.0F;
    } else {
      localDivide_f = (localDivide_f + localSwitch2) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S72>/Relational Operator2' incorporates:
     *  MinMax: '<S72>/MinMax1'
     */
    localTmpSignalConversionAtVlv_h = (localDivide_f >= (((Float32)
      OvbCtl_tiMaxAcv_C) * 9.999999776E-003F));

    /* UnitDelay: '<S85>/Unit Delay' */
    localR = EngMGslLim_DWork.UnitDelay_DSTATE_ou;

    /* RelationalOperator: '<S72>/Relational Operator1' incorporates:
     *  Constant: '<S72>/Constant2'
     *  MinMax: '<S72>/MinMax1'
     */
    localLowerRelop1_l = (OvbCtl_tiMaxAcv_C == 0);

    /* Switch: '<S72>/Switch' incorporates:
     *  Constant: '<S72>/Constant5'
     *  Logic: '<S72>/Logical Operator1'
     *  Logic: '<S79>/Logical Operator'
     *  Logic: '<S79>/Logical Operator1'
     */
    if (!localLowerRelop1_l) {
      localR = ((localTmpSignalConversionAtVlv_h) && (!localR));
    } else {
      localR = TRUE;
    }

    /* UnitDelay: '<S83>/Unit Delay' */
    localUnitDelay = EngMGslLim_DWork.UnitDelay_DSTATE_il;

    /* CombinatorialLogic: '<S74>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = EngMGslLim_ConstP.pooled21[rowidx];
      localLogic[1] = EngMGslLim_ConstP.pooled21[rowidx + 8];
    }

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S26>/OvbCtl_bMPMOvbStop_C'
     */
    if (OvbCtl_bMPMOvbStop_C) {
      OvbCtl_bInhMaxTiThd = localTmpSignalConversionAtMPM_b;
    } else {
      OvbCtl_bInhMaxTiThd = localLogic[1];
    }

    /* Update for UnitDelay: '<S76>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_efy = localLowerRelop1_l;

    /* Update for UnitDelay: '<S84>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_j = localTmpSignalConversionAtVlvAc;

    /* Update for UnitDelay: '<S75>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_f = localDivide_f;

    /* Update for UnitDelay: '<S85>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_ou = localTmpSignalConversionAtVlv_h;

    /* Update for UnitDelay: '<S83>/Unit Delay' */
    EngMGslLim_DWork.UnitDelay_DSTATE_il = localLogic[0];

    /* end of Outputs for SubSystem: '<S21>/F04_temps_max_ovb' */

    /* Outputs for atomic SubSystem: '<S21>/F05_Conditions_Protections_moteur' *
     * Block requirements for '<S21>/F05_Conditions_Protections_moteur':
     *  1. SubSystem "F05_Conditions_Protections_moteur" !Trace_To : VEMS_R_11_01002_009.01 ;
     */

    /* Logic: '<S27>/Logical Operator' incorporates:
     *  Constant: '<S27>/OvbCtl_bAcvTPMMod_C'
     *  Logic: '<S27>/Logical Operator1'
     */
    OvbCtl_bAcvEngProt = ((((OvbCtl_bAcvTPMMod_C &&
      (localTmpSignalConversionAtTPM_b)) ||
      EngMGslLim_B.TmpSignalConversionAtKnkMgt_bAc) ||
      EngMGslLim_B.TmpSignalConversionAtKnkMgt_b_k) ||
                          (localTmpSignalConversionAtEngMT));

    /* end of Outputs for SubSystem: '<S21>/F05_Conditions_Protections_moteur' */

    /* Outputs for atomic SubSystem: '<S21>/F07_Manageur_Overboost' *
     * Block requirements for '<S21>/F07_Manageur_Overboost':
     *  1. SubSystem "F06_Manageur_Overboost" !Trace_To : VEMS_R_11_01002_010.02 ;
     */

    /* Stateflow: '<S29>/F01_OvbMgr' incorporates:
     *  Constant: '<S29>/OvbCtl_tCoThdAcvOvb_C'
     *  Constant: '<S29>/local_1 '
     */
    /* Gateway: EngMGslLim/F02_Compute/F01_Compute/F07_Manageur_Overboost/F01_OvbMgr */
    /* During: EngMGslLim/F02_Compute/F01_Compute/F07_Manageur_Overboost/F01_OvbMgr */
    if (EngMGslLim_DWork.is_active_c1_EngMGslLim == 0) {
      /* Entry: EngMGslLim/F02_Compute/F01_Compute/F07_Manageur_Overboost/F01_OvbMgr */
      EngMGslLim_DWork.is_active_c1_EngMGslLim = 1U;

      /* Transition: '<S86>:6' */
      /* Entry 'Attente_Requette_Overboost': '<S86>:1' */
      EngMGslLim_DWork.is_c1_EngMGslLim = IN_Attente_Requette_Overboost;
    } else {
      switch (EngMGslLim_DWork.is_c1_EngMGslLim) {
       case IN_Attente_Requette_Overboost:
        /* During 'Attente_Requette_Overboost': '<S86>:1' */
        if ((((((((SInt32)localTmpSignalConversionAtCoP_b) == 1) &&
                (EngMGslLim_B.TmpSignalConversionAtExt_tCoMes >=
                 OvbCtl_tCoThdAcvOvb_C)) && (((SInt32)OvbCtl_bAcvVlvServo) == 1))
              && (((SInt32)localNot) == 0)) && (((SInt32)OvbCtl_bAcvEngProt) ==
              0)) && (((SInt32)localTmpSignalConversionAtTrbAc) == 1)) {
          /* Transition: '<S86>:7' */
          /* Exit 'Attente_Requette_Overboost': '<S86>:1' */
          /* Entry 'OverBoost_Active': '<S86>:2' */
          EngMGslLim_DWork.is_c1_EngMGslLim = IN_OverBoost_Active;
        } else {
          EngMGslLim_B.OvbCtl_stOvb = 0U;
          EngMGslLim_B.EngMTrb_facOvbReq = 0U;
        }
        break;

       case IN_Desactivation_Overboost_1:
        /* During 'Desactivation_Overboost_1': '<S86>:3' */
        if (EngMGslLim_B.EngMTrb_facOvbReq == 0) {
          /* Transition: '<S86>:9' */
          /* Exit 'Desactivation_Overboost_1': '<S86>:3' */
          /* Entry 'Inhibition_de_l_overboost': '<S86>:4' */
          EngMGslLim_DWork.is_c1_EngMGslLim = IN_Inhibition_de_l_overboost;
          EngMGslLim_B.OvbCtl_stOvb = 4U;
          EngMGslLim_B.EngMTrb_facOvbReq = 0U;
        } else {
          EngMGslLim_B.OvbCtl_stOvb = 3U;
          EngMGslLim_B.EngMTrb_facOvbReq = OvbCtl_facOvbStop;
        }
        break;

       case IN_Desactivation_Overboost_2:
        /* During 'Desactivation_Overboost_2': '<S86>:5' */
        if (((((((OvbCtl_tiDly == 0) && (((SInt32)
                   localTmpSignalConversionAtCoP_b) == 1)) && (((SInt32)
                  OvbCtl_bAcvEngProt) == 0)) && (((SInt32)OvbCtl_bInhMaxTiThd) ==
                0)) && (((SInt32)OvbCtl_bAcvVlvServo) == 1)) && (((SInt32)
               localNot) == 0)) && (((SInt32)localTmpSignalConversionAtTrbAc) ==
             1)) {
          /* Transition: '<S86>:11' */
          /* Exit 'Desactivation_Overboost_2': '<S86>:5' */
          /* Entry 'OverBoost_Active': '<S86>:2' */
          EngMGslLim_DWork.is_c1_EngMGslLim = IN_OverBoost_Active;
        } else if (EngMGslLim_B.EngMTrb_facOvbReq == 0) {
          /* Transition: '<S86>:13' */
          /* Exit 'Desactivation_Overboost_2': '<S86>:5' */
          /* Entry 'Inhibition_de_l_overboost': '<S86>:4' */
          EngMGslLim_DWork.is_c1_EngMGslLim = IN_Inhibition_de_l_overboost;
          EngMGslLim_B.OvbCtl_stOvb = 4U;
          EngMGslLim_B.EngMTrb_facOvbReq = 0U;
        } else {
          EngMGslLim_B.OvbCtl_stOvb = 2U;
          EngMGslLim_B.EngMTrb_facOvbReq = OvbCtl_facOvbStop;
        }
        break;

       case IN_Inhibition_de_l_overboost:
        /* During 'Inhibition_de_l_overboost': '<S86>:4' */
        if (((OvbCtl_tiDly == 0) && (((SInt32)localTmpSignalConversionAtCoP_b) ==
              0)) && (((SInt32)OvbCtl_bInhMaxTiThd) == 0)) {
          /* Transition: '<S86>:10' */
          /* Exit 'Inhibition_de_l_overboost': '<S86>:4' */
          /* Entry 'Attente_Requette_Overboost': '<S86>:1' */
          EngMGslLim_DWork.is_c1_EngMGslLim = IN_Attente_Requette_Overboost;
        }
        break;

       case IN_OverBoost_Active:
        /* During 'OverBoost_Active': '<S86>:2' */
        if (((SInt32)localTmpSignalConversionAtCoP_b) == 0) {
          /* Transition: '<S86>:12' */
          /* Exit 'OverBoost_Active': '<S86>:2' */
          /* Entry 'Desactivation_Overboost_2': '<S86>:5' */
          EngMGslLim_DWork.is_c1_EngMGslLim = IN_Desactivation_Overboost_2;
        } else if ((((((SInt32)OvbCtl_bInhMaxTiThd) == 1) || (((SInt32)
            OvbCtl_bAcvVlvServo) == 0)) || (((SInt32)localNot) == 1)) ||
                   (((SInt32)OvbCtl_bAcvEngProt) == 1)) {
          /* Transition: '<S86>:8' */
          /* Exit 'OverBoost_Active': '<S86>:2' */
          /* Entry 'Desactivation_Overboost_1': '<S86>:3' */
          EngMGslLim_DWork.is_c1_EngMGslLim = IN_Desactivation_Overboost_1;
        } else {
          EngMGslLim_B.OvbCtl_stOvb = 1U;
          EngMGslLim_B.EngMTrb_facOvbReq = localTmpSignalConversionAtMPM_f;
        }
        break;

       default:
        /* Transition: '<S86>:6' */
        /* Entry 'Attente_Requette_Overboost': '<S86>:1' */
        EngMGslLim_DWork.is_c1_EngMGslLim = IN_Attente_Requette_Overboost;
        break;
      }
    }

    /* SignalConversion: '<S87>/copy' */
    OvbCtl_stOvb_IRV_MP = EngMGslLim_B.OvbCtl_stOvb;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S87>/autosar_testpoint1' */

    /* S-Function Block: <S87>/autosar_testpoint1 */

    /* SignalConversion: '<S29>/Signal Conversion1' */
    EngMGslLim_B.OvbCtl_stOvb_irv_c = EngMGslLim_B.OvbCtl_stOvb;

    /* end of Outputs for SubSystem: '<S21>/F07_Manageur_Overboost' */

    /* SignalConversion: '<S32>/copy' */
    EngMTrb_facOvbReq_IRV_MP = EngMGslLim_B.EngMTrb_facOvbReq;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S32>/autosar_testpoint1' */

    /* S-Function Block: <S32>/autosar_testpoint1 */

    /* SignalConversion: '<S21>/Signal Conversion2' */
    localTmpSignalConversionAtCoPt_ = EngMGslLim_B.EngMTrb_facOvbReq;
  } else {
    /* SignalConversion: '<S22>/Signal Conversion3' */
    EngMGslLim_B.OvbCtl_stOvb_irv_c = localTmpSignalConversionAtOvbCt;

    /* SignalConversion: '<S22>/Signal Conversion2' */
    localTmpSignalConversionAtCoPt_ =
      EngMGslLim_B.TmpSignalConversionAtEngMTrb_fa;

    /* SignalConversion: '<S22>/Signal Conversion5' */
    localTmpSignalConversionAtMPM_f =
      EngMGslLim_B.TmpSignalConversionAtEngMTrb__m;
  }

  /* end of Outputs for SubSystem: '<S6>/F01_Compute' */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtEngMTrb_facOvbAcvInport2' */
  Rte_IrvWrite_RE_EngMGslLim_002_TEV_EngMTrb_facOvbAcv_irv
    (localTmpSignalConversionAtMPM_f);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtEngMTrb_facOvbReqInport2' */
  Rte_IrvWrite_RE_EngMGslLim_002_TEV_EngMTrb_facOvbReq_irv
    (localTmpSignalConversionAtCoPt_);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOvbCtl_stOvbInport2' */
  Rte_IrvWrite_RE_EngMGslLim_002_TEV_OvbCtl_stOvb_irv
    (EngMGslLim_B.OvbCtl_stOvb_irv_c);
}

/* Output and update for exported function: RE_EngMGslLim_002_TEV */
void RE_EngMGslLim_002_TEV(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Compute'
   *
   * Block requirements for '<S1>/F02_Compute':
   *  1. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_001.01 ;
   *  2. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_002.01 ;
   *  3. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_003.01 ;
   *  4. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_034.01 ;
   *  5. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_035.01 ;
   *  6. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_036.01 ;
   *  7. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_037.01 ;
   *  8. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_038.01 ;
   *  9. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_039.01 ;
   *  10. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_040.01 ;
   *  11. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_041.01 ;
   *  12. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_042.01 ;
   *  13. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_043.01 ;
   *  14. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_044.01 ;
   *  15. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_045.01 ;
   *  16. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_047.01 ;
   *  17. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_046.01 ;
   *  18. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_031.01 ;
   *  19. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_001.01 ;
   *  20. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_002.01 ;
   *  21. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_003.01 ;
   *  22. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_013.02 ;
   *  23. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_029.02 ;
   *  24. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_076.01 ;
   *  25. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_011.02 ;
   *  26. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_012.03 ;
   *  27. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_032.02 ;
   *  28. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_048.02 ;
   *  29. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_004.02 ;
   *  30. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_050.01 ;
   *  31. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_030.02 ;
   *  32. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_033.01 ;
   *  33. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_004.02 ;
   *  34. SubSystem "F02_Compute" !Trace_To : VEMS_R_11_01002_050.01 ;
   */
  EngMGslLim_F02_Compute();
}

/*
 * Output and update for enable system:
 *    '<S128>/Subsystem1'
 *    '<S300>/Subsystem1'
 */
void EngMGslLim_Subsystem1(Boolean rtu_0, Boolean rtu_SelChg, Float32
  rtu_TrkTe, rtB_Subsystem1_EngMGslLim *localB)
{
  if (rtu_0) {
    /* Switch: '<S135>/Switch' incorporates:
     *  Constant: '<S135>/Constant1'
     */
    if (rtu_SelChg) {
      localB->Switch = 0.0F;
    } else {
      localB->Switch = rtu_TrkTe;
    }
  }
}

/*
 * Initial conditions for enable system:
 *    '<S126>/Subsystem'
 *    '<S298>/Subsystem'
 */
void EngMGslLim_Subsystem_Init(rtDW_Subsystem_EngMGslLim *localDW)
{
  /* InitializeConditions for UnitDelay: '<S150>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S149>/Unit Delay' */
  localDW->UnitDelay_DSTATE_i = FALSE;
}

/*
 * Disable for enable system:
 *    '<S126>/Subsystem'
 *    '<S298>/Subsystem'
 */
void EngMGslLim_Subsystem_Disable(rtDW_Subsystem_EngMGslLim *localDW)
{
  localDW->Subsystem_MODE = FALSE;
}

/*
 * Start for enable system:
 *    '<S126>/Subsystem'
 *    '<S298>/Subsystem'
 */
void EngMGslLim_Subsystem_Start(rtDW_Subsystem_EngMGslLim *localDW)
{
  EngMGslLim_Subsystem_Init(localDW);
}

/*
 * Output and update for enable system:
 *    '<S126>/Subsystem'
 *    '<S298>/Subsystem'
 */
void EngMGslLim_Subsystem(Boolean rtu_0, Float32 rtu_Ini, Float32 rtu_Inj,
  Float32 rtu_Te, Float32 rtu_TrkTe, rtB_Subsystem_EngMGslLim *localB,
  rtDW_Subsystem_EngMGslLim *localDW)
{
  Float32 localDivide_i;
  if (rtu_0) {
    if (!(((SInt32)localDW->Subsystem_MODE) != 0)) {
      EngMGslLim_Subsystem_Init(localDW);
      localDW->Subsystem_MODE = TRUE;
    }

    /* Switch: '<S146>/Switch' incorporates:
     *  UnitDelay: '<S149>/Unit Delay'
     *  UnitDelay: '<S150>/Unit Delay'
     */
    if (localDW->UnitDelay_DSTATE_i) {
      localB->Yk = localDW->UnitDelay_DSTATE;
    } else {
      localB->Yk = rtu_Ini;
    }

    /* Product: '<S145>/Divide' incorporates:
     *  Product: '<S130>/Product'
     *  Sum: '<S130>/Subtract2'
     */
    localDivide_i = ((rtu_Inj - localB->Yk) * rtu_Te) / rtu_TrkTe;

    /* Outputs for atomic SubSystem: '<S145>/If Action Subsystem3' */

    /* Switch: '<S148>/Switch1' incorporates:
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S148>/Constant3'
     *  Logic: '<S148>/Logical Operator1'
     *  RelationalOperator: '<S148>/Relational Operator'
     *  RelationalOperator: '<S148>/Relational Operator1'
     *  RelationalOperator: '<S148>/Relational Operator3'
     */
    if (((localDivide_i != localDivide_i) || (localDivide_i > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_i)) {
      localDivide_i = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S145>/If Action Subsystem3' */

    /* Update for UnitDelay: '<S150>/Unit Delay' incorporates:
     *  Sum: '<S130>/Subtract10'
     */
    localDW->UnitDelay_DSTATE = localB->Yk + localDivide_i;

    /* Update for UnitDelay: '<S149>/Unit Delay' incorporates:
     *  Constant: '<S146>/Constant3'
     */
    localDW->UnitDelay_DSTATE_i = TRUE;
  } else {
    if ((SInt32)localDW->Subsystem_MODE) {
      EngMGslLim_Subsystem_Disable(localDW);
    }
  }
}

/* Disable for function-call system: '<S1>/F02_Compute1' */
void EngMGslLim_F02_Compute1_Disable(void)
{
  /* Disable for atomic SubSystem: '<S7>/F01_rLdMaxRef' *
   * Block requirements for '<S7>/F01_rLdMaxRef':
   *  1. SubSystem "F01_rLdMaxRef" !Trace_To : VEMS_R_11_01002_014.01 ;
   */

  /* Disable for If: '<S88>/If' */
  EngMGslLim_DWork.If_ActiveSubsystem = -1;

  /* Disable for If: '<S107>/If1' */
  EngMGslLim_DWork.If1_ActiveSubsystem = -1;

  /* Disable for atomic SubSystem: '<S125>/MSW' */

  /* Disable for enable SubSystem: '<S126>/Subsystem' */
  EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem);

  /* end of Disable for SubSystem: '<S126>/Subsystem' */

  /* end of Disable for SubSystem: '<S125>/MSW' */

  /* Disable for ifaction SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */

  /* Disable for atomic SubSystem: '<S125>/MSW' */

  /* Disable for enable SubSystem: '<S126>/Subsystem' */
  EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem);

  /* end of Disable for SubSystem: '<S126>/Subsystem' */

  /* end of Disable for SubSystem: '<S125>/MSW' */

  /* end of Disable for SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */

  /* Disable for ifaction SubSystem: '<S88>/F02_Corrections_Flex'
   * Block description for '<S88>/F02_Corrections_Flex':
   *  01460_10_03518.FR.25.0
   */

  /* Disable for If: '<S107>/If1' */
  EngMGslLim_DWork.If1_ActiveSubsystem = -1;

  /* Disable for atomic SubSystem: '<S125>/MSW' */

  /* Disable for enable SubSystem: '<S126>/Subsystem' */
  EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem);

  /* end of Disable for SubSystem: '<S126>/Subsystem' */

  /* end of Disable for SubSystem: '<S125>/MSW' */

  /* Disable for ifaction SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */

  /* Disable for atomic SubSystem: '<S125>/MSW' */

  /* Disable for enable SubSystem: '<S126>/Subsystem' */
  EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem);

  /* end of Disable for SubSystem: '<S126>/Subsystem' */

  /* end of Disable for SubSystem: '<S125>/MSW' */

  /* end of Disable for SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */

  /* end of Disable for SubSystem: '<S88>/F02_Corrections_Flex' */

  /* end of Disable for SubSystem: '<S7>/F01_rLdMaxRef' */

  /* Disable for atomic SubSystem: '<S7>/F06_Limitations_Remplissage_Mx1' *
   * Block requirements for '<S7>/F06_Limitations_Remplissage_Mx1':
   *  1. SubSystem "F06_Limitations_Remplissage_Mx1" !Trace_To : VEMS_R_11_01002_021.02 ;
   */

  /* Disable for atomic SubSystem: '<S93>/F01_Freeze'
   * Block description for '<S93>/F01_Freeze':
   *  01460_10_03518_2.FR.19.0
   *
   * Block requirements for '<S93>/F01_Freeze':
   *  1. SubSystem "F01_Freeze" !Trace_To : VEMS_R_11_01002_052.01 ;
   */

  /* Disable for atomic SubSystem: '<S296>/MSW' */

  /* Disable for enable SubSystem: '<S298>/Subsystem' */
  EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem_o);

  /* end of Disable for SubSystem: '<S298>/Subsystem' */

  /* end of Disable for SubSystem: '<S296>/MSW' */

  /* end of Disable for SubSystem: '<S93>/F01_Freeze' */

  /* end of Disable for SubSystem: '<S7>/F06_Limitations_Remplissage_Mx1' */
}

/* Start for function-call system: '<S1>/F02_Compute1' */
void EngMGslLim_F02_Compute1_Start(void)
{
  /* Start for atomic SubSystem: '<S7>/F01_rLdMaxRef' *
   * Block requirements for '<S7>/F01_rLdMaxRef':
   *  1. SubSystem "F01_rLdMaxRef" !Trace_To : VEMS_R_11_01002_014.01 ;
   */

  /* Start for If: '<S88>/If' */
  EngMGslLim_DWork.If_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S88>/F02_Corrections_Flex'
   * Block description for '<S88>/F02_Corrections_Flex':
   *  01460_10_03518.FR.25.0
   */

  /* Start for If: '<S107>/If1' */
  EngMGslLim_DWork.If1_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */

  /* Start for atomic SubSystem: '<S125>/MSW' */

  /* Start for enable SubSystem: '<S126>/Subsystem' */
  EngMGslLim_Subsystem_Start(&EngMGslLim_DWork.Subsystem);

  /* end of Start for SubSystem: '<S126>/Subsystem' */

  /* end of Start for SubSystem: '<S125>/MSW' */

  /* end of Start for SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */

  /* end of Start for SubSystem: '<S88>/F02_Corrections_Flex' */

  /* end of Start for SubSystem: '<S7>/F01_rLdMaxRef' */

  /* Start for atomic SubSystem: '<S7>/F06_Limitations_Remplissage_Mx1' *
   * Block requirements for '<S7>/F06_Limitations_Remplissage_Mx1':
   *  1. SubSystem "F06_Limitations_Remplissage_Mx1" !Trace_To : VEMS_R_11_01002_021.02 ;
   */

  /* Start for atomic SubSystem: '<S93>/F01_Freeze'
   * Block description for '<S93>/F01_Freeze':
   *  01460_10_03518_2.FR.19.0
   *
   * Block requirements for '<S93>/F01_Freeze':
   *  1. SubSystem "F01_Freeze" !Trace_To : VEMS_R_11_01002_052.01 ;
   */

  /* Start for atomic SubSystem: '<S296>/MSW' */

  /* Start for enable SubSystem: '<S298>/Subsystem' */
  EngMGslLim_Subsystem_Start(&EngMGslLim_DWork.Subsystem_o);

  /* end of Start for SubSystem: '<S298>/Subsystem' */

  /* end of Start for SubSystem: '<S296>/MSW' */

  /* end of Start for SubSystem: '<S93>/F01_Freeze' */

  /* end of Start for SubSystem: '<S7>/F06_Limitations_Remplissage_Mx1' */
}

/* Output and update for function-call system: '<S1>/F02_Compute1' */
void EngMGslLim_F02_Compute1(void)
{
  /* local block i/o variables */
  Float32 localMS;
  Float32 localMS1;
  Float32 localDataTypeConversion3_i;
  Float32 localTrkTe;
  Float32 localSwitch2_f;
  Float32 localMS_p;
  Float32 localMS1_c;
  Float32 localDataTypeConversion1_c;
  Float32 localTrkTe_e;
  Float32 localSwitch2_l;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localLookUpTable_n;
  UInt16 localLookUpTable_f;
  UInt16 localLookUpTable2D_m;
  UInt16 localLookUpTable_nk;
  UInt16 localLookUpTable_n0;
  UInt16 localLookUpTable_b;
  UInt16 localMinMax1_p;
  UInt16 localMinMax1_g;
  UInt16 localLookUpTable_h;
  UInt16 localSwitch2_b2;
  UInt16 localTmpSignalConversionAtIgSys;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt16 localLookUpTable_p;
  UInt8 localMinMax_b;
  Boolean localTmpSignalConversionAtKnk_h;
  Boolean localTmpSignalConversionAtKnk_i;
  Boolean localTmpSignalConversionAtKnk_d;
  Boolean localLogic_i[2];
  Boolean localLogic_j[2];
  Boolean localRelationalOperator_d;
  Boolean localLogicalOperator3_j;
  Boolean localRelationalOperator_p;
  Boolean localLogicalOperator_f;
  Boolean localLogic_d[2];
  Boolean localLogic_o[2];
  Boolean localRelationalOperator_n;
  Boolean localLogicalOperator3_n;
  Boolean localRelationalOperator_fz;
  Boolean localUnitDelay_kd;
  Boolean localUnitDelay_d;
  Boolean localSwitch_do;
  Boolean localSwitch_bt;
  Boolean localAutosarServer_i;
  Boolean localUnitDelay_gg;
  Boolean localSwitch_fs;
  Boolean localNot_h;
  Boolean localNot_p;
  Boolean localNot_g;
  Boolean localNot_p4;
  Float32 localDataTypeConversion1_o3;
  Float32 localDataTypeConversion3_l;
  SInt8 localrtPrevAction;
  SInt8 localrtAction;
  Boolean localRO1;
  UInt8 localTmpSignalConversionAtExt_s;
  Boolean localRelationalOperator1_m4;
  Float32 localLookupTablenD;
  Boolean localLogicalOperator_l;
  Boolean localRelationalOperator1_a;
  Boolean localRelationalOperator2_d;
  Boolean localRelationalOperator1_o;
  Float32 localExt_nEng_EngMTrb_nEngLdRef;
  Float32 localfractionTmp_0d;
  UInt32 localExt_nEng_EngMTrb_nEngLdR_n;
  Float32 localfractionTmp_0d_0;
  UInt8 localSwitch_il;
  Float32 localExt_nEng_EngMTrb_nEng_A_9_;
  Float32 localfrac[2];
  Float32 localEngMTrb_rEth_EngMTrb_rEthR;
  UInt32 localExt_nEng_EngMTrb_nEng_A__c;
  UInt32 localbpIndex[2];
  UInt32 localEngMTrb_rEth_EngMTrb_rEt_p;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  SInt16 localTmpSignalConversionAtExt_t;
  Float32 localInterpolationUsingPreloo_j;
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Boolean localTmpSignalConversionAtAfuA_;
  Float32 localSwitch2_h;
  Float32 localSum3_h;
  UInt8 localTmpSignalConversionAtKnkMg[6];
  UInt16 localTmpSignalConversionAtUsT_i;
  UInt16 localTmpSignalConversionAtUsT_c;
  UInt16 localTmpSignalConversionAtEng_d;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt16 localTmpSignalConversionAtInM_c;
  UInt8 localTmpSignalConversionAtAfu_n;
  UInt16 localTmpSignalConversionAtFARSp;
  UInt16 localTmpSignalConversionAtTPM_k;
  UInt16 localTmpSignalConversionAtUsT_p;
  UInt16 localTmpSignalConversionAtInThM;
  UInt16 locallocalOutDTConv_h_idx;
  SInt32 localtmp;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtMPM_rLdMaxOutport2' incorporates:
   *  Inport: '<Root>/MPM_rLdMax'
   */
  Rte_Read_R_MPM_rLdMax_MPM_rLdMax(&locallocalOutDTConv_h_idx);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_stPwrLimCfOutport2' incorporates:
   *  Inport: '<Root>/Ext_stPwrLimCf'
   */
  Rte_Read_R_Ext_stPwrLimCf_Ext_stPwrLimCf(&localTmpSignalConversionAtExt_s);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&localTmpSignalConversionAtInThM);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAfuA_rEthWoutExctOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rEthWoutExct'
   */
  Rte_Read_R_AfuA_rEthWoutExct_AfuA_rEthWoutExct
    (&localTmpSignalConversionAtAfu_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAfuA_bInvldEthRatOutport2' incorporates:
   *  Inport: '<Root>/AfuA_bInvldEthRat'
   */
  Rte_Read_R_AfuA_bInvldEthRat_AfuA_bInvldEthRat
    (&localTmpSignalConversionAtAfuA_);

  /* Outputs for atomic SubSystem: '<S7>/F01_rLdMaxRef' *
   * Block requirements for '<S7>/F01_rLdMaxRef':
   *  1. SubSystem "F01_rLdMaxRef" !Trace_To : VEMS_R_11_01002_014.01 ;
   */

  /* DataTypeConversion: '<S88>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_facOvbReqOutport2'
   */
  localDataTypeConversion1_o3 = (((Float32)
    Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_facOvbReq_irv()) *
    3.051757813E-005F) + 1.0F;

  /* DataTypeConversion: '<S88>/Data Type Conversion3' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_facOvbAcvOutport2'
   */
  localDataTypeConversion3_l = (((Float32)
    Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_facOvbAcv_irv()) *
    3.051757813E-005F) + 1.0F;

  /* Outputs for atomic SubSystem: '<S88>/F01_rLdMax_Gsl' */

  /* PreLookup: '<S113>/Prelookup' */
  localExt_nEng_EngMTrb_nEngLdR_n = plook_u32u16f_binc
    (localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdRef_A[0])), 15U,
     &localExt_nEng_EngMTrb_nEngLdRef);

  /* Outputs for enable SubSystem: '<S106>/F01_rLdMaxRef_Configuration0' incorporates:
   *  Constant: '<S106>/OvbCtl_stOvbStop_C1'
   *  EnablePort: '<S110>/Enable'
   *  EnablePort: '<S111>/Enable'
   *  Logic: '<S106>/Logical Operator'
   *  RelationalOperator: '<S106>/Relational Operator1'
   *  SubSystem: '<S106>/F02_rLdMaxRef_Configuration1'
   */
  if (localTmpSignalConversionAtExt_s == 0) {
    /* Interpolation_n-D: '<S114>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_nEng_EngMTrb_nEngLdRef;
    EngMTrb_rLdMaxRefGsl = intrp1d_iu16n14ff_u32f_l_ns__1
      (localExt_nEng_EngMTrb_nEngLdR_n, localfractionTmp_0d,
       (&(EngMTrb_rLdMaxRef_T[0])));
  } else {
    /* Interpolation_n-D: '<S115>/Interpolation Using Prelookup3' */
    localfractionTmp_0d_0 = localExt_nEng_EngMTrb_nEngLdRef;
    EngMTrb_rLdMaxRefGsl = intrp1d_iu16n14ff_u32f_l_ns__1
      (localExt_nEng_EngMTrb_nEngLdR_n, localfractionTmp_0d_0,
       (&(EngMTrb_rLdMaxRef2_T[0])));
  }

  /* end of Outputs for SubSystem: '<S106>/F01_rLdMaxRef_Configuration0' */

  /* Outputs for atomic SubSystem: '<S106>/F03_rLdMaxRef_Sel' */

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S112>/EngMTrb_bMPMAcv_C'
   *  DataTypeConversion: '<S112>/Data Type Conversion'
   */
  if (EngMTrb_bMPMAcv_C) {
    EngMTrb_rLdMaxGsl = ((Float32)locallocalOutDTConv_h_idx) *
      6.103515625E-005F;
  } else {
    EngMTrb_rLdMaxGsl = EngMTrb_rLdMaxRefGsl;
  }

  /* end of Outputs for SubSystem: '<S106>/F03_rLdMaxRef_Sel' */

  /* end of Outputs for SubSystem: '<S88>/F01_rLdMax_Gsl' */

  /* If: '<S88>/If' incorporates:
   *  ActionPort: '<S107>/Action Port'
   *  ActionPort: '<S108>/Action Port'
   *  Constant: '<S88>/EngMTrb_bFlex_C'
   *  SubSystem: '<S88>/F02_Corrections_Flex'
   *  SubSystem: '<S88>/F03_No_corrections_Flex'
   *
   * Block description for '<S88>/F02_Corrections_Flex':
   *  01460_10_03518.FR.25.0
   *
   * Block description for '<S88>/F03_No_corrections_Flex':
   *  01460_10_03518.FR.32.0
   */
  localrtPrevAction = EngMGslLim_DWork.If_ActiveSubsystem;
  if (EngMTrb_bFlex_C) {
    localrtAction = 0;
  } else {
    localrtAction = 1;
  }

  EngMGslLim_DWork.If_ActiveSubsystem = localrtAction;
  if ((localrtPrevAction != localrtAction) && (localrtPrevAction == 0)) {
    /* Disable for If: '<S107>/If1' */
    EngMGslLim_DWork.If1_ActiveSubsystem = -1;

    /* Disable for atomic SubSystem: '<S125>/MSW' */

    /* Disable for enable SubSystem: '<S126>/Subsystem' */
    EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem);

    /* end of Disable for SubSystem: '<S126>/Subsystem' */

    /* end of Disable for SubSystem: '<S125>/MSW' */

    /* Disable for ifaction SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */

    /* Disable for atomic SubSystem: '<S125>/MSW' */

    /* Disable for enable SubSystem: '<S126>/Subsystem' */
    EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem);

    /* end of Disable for SubSystem: '<S126>/Subsystem' */

    /* end of Disable for SubSystem: '<S125>/MSW' */

    /* end of Disable for SubSystem: '<S107>/F01_EngMLim_Reconfiguration' */
  }

  switch (localrtAction) {
   case 0:
    /* DataTypeConversion: '<S107>/Data Type Conversion2' */
    localfractionTmp_0d_0 = ((Float32)localTmpSignalConversionAtAfu_n) *
      0.0078125F;

    /* If: '<S107>/If1' incorporates:
     *  ActionPort: '<S116>/Action Port'
     *  ActionPort: '<S117>/Action Port'
     *  Constant: '<S107>/EngMTrb_bRatEthRcvAcv_C'
     *  SubSystem: '<S107>/F01_EngMLim_Reconfiguration'
     *  SubSystem: '<S107>/F02_FNR_Reconfiguration'
     */
    localrtPrevAction = EngMGslLim_DWork.If1_ActiveSubsystem;
    if (EngMTrb_bRatEthRcvAcv_C) {
      localrtAction = 0;
    } else {
      localrtAction = 1;
    }

    EngMGslLim_DWork.If1_ActiveSubsystem = localrtAction;
    if ((localrtPrevAction != localrtAction) && (localrtPrevAction == 0)) {
      /* Disable for atomic SubSystem: '<S125>/MSW' */

      /* Disable for enable SubSystem: '<S126>/Subsystem' */
      EngMGslLim_Subsystem_Disable(&EngMGslLim_DWork.Subsystem);

      /* end of Disable for SubSystem: '<S126>/Subsystem' */

      /* end of Disable for SubSystem: '<S125>/MSW' */
    }

    switch (localrtAction) {
     case 0:
      /* Switch: '<S116>/Switch' incorporates:
       *  Constant: '<S116>/Constant'
       *  Constant: '<S116>/Constant1'
       */
      if (localTmpSignalConversionAtAfuA_) {
        localTmpSignalConversionAtExt_s = 2U;
      } else {
        localTmpSignalConversionAtExt_s = 1U;
      }

      /* Switch: '<S168>/Switch2' incorporates:
       *  Constant: '<S127>/Constant2'
       */
      localTmpSignalConversionAtAfu_n = localTmpSignalConversionAtExt_s;

      /* DataTypeConversion: '<S116>/Data Type Conversion3' incorporates:
       *  Constant: '<S116>/EngMTrb_rEthDft_C'
       */
      localfractionTmp_0d = ((Float32)EngMTrb_rEthDft_C) * 0.0078125F;

      /* MultiPortSwitch: '<S125>/MS' */
      if (localTmpSignalConversionAtExt_s == 1) {
        localMS_p = localfractionTmp_0d_0;
      } else {
        localMS_p = localfractionTmp_0d;
      }

      /* UnitDelay: '<S170>/Unit Delay' */
      localTmpSignalConversionAtExt_s = EngMGslLim_DWork.UnitDelay_DSTATE_dk;

      /* Switch: '<S164>/Switch' incorporates:
       *  UnitDelay: '<S169>/Unit Delay'
       */
      if (!EngMGslLim_DWork.UnitDelay_DSTATE_dp) {
        localTmpSignalConversionAtExt_s = localTmpSignalConversionAtAfu_n;
      }

      /* RelationalOperator: '<S127>/Relational Operator' */
      localRelationalOperator_n = (localTmpSignalConversionAtExt_s !=
        localTmpSignalConversionAtAfu_n);

      /* UnitDelay: '<S172>/Unit Delay' */
      localSwitch_il = EngMGslLim_DWork.UnitDelay_DSTATE_go;

      /* Switch: '<S165>/Switch' incorporates:
       *  UnitDelay: '<S171>/Unit Delay'
       */
      if (!EngMGslLim_DWork.UnitDelay_DSTATE_gbg) {
        localSwitch_il = localTmpSignalConversionAtAfu_n;
      }

      /* Switch: '<S127>/Switch' */
      if (localRelationalOperator_n) {
        localSwitch_il = localTmpSignalConversionAtExt_s;
      }

      /* MultiPortSwitch: '<S125>/MS1' */
      if (localSwitch_il == 1) {
        localMS1_c = localfractionTmp_0d_0;
      } else {
        localMS1_c = localfractionTmp_0d;
      }

      /* DataTypeConversion: '<S116>/Data Type Conversion2' incorporates:
       *  Constant: '<S116>/EngMTrb_tiEthDftTran_C'
       */
      localfractionTmp_0d_0 = ((Float32)EngMTrb_tiEthDftTran_C) *
        1.000000047E-003F;

      /* DataTypeConversion: '<S116>/Data Type Conversion1' incorporates:
       *  Constant: '<S116>/EngMTrb_tiSample_C'
       */
      localDataTypeConversion1_c = ((Float32)EngMTrb_tiSample_C) *
        1.000000047E-003F;

      /* Outputs for atomic SubSystem: '<S125>/MSW' */

      /* Switch: '<S144>/Switch' incorporates:
       *  RelationalOperator: '<S144>/UpperRelop'
       */
      if (localfractionTmp_0d_0 < localDataTypeConversion1_c) {
        localSwitch2_h = localDataTypeConversion1_c;
      } else {
        localSwitch2_h = localfractionTmp_0d_0;
      }

      /* Switch: '<S144>/Switch2' incorporates:
       *  Constant: '<S126>/Constant17'
       *  RelationalOperator: '<S144>/LowerRelop1'
       */
      localfractionTmp_0d_0 = localSwitch2_h;

      /* UnitDelay: '<S141>/Unit Delay' */
      localSwitch2_h = EngMGslLim_DWork.UnitDelay_DSTATE_om;

      /* Switch: '<S136>/Switch' incorporates:
       *  Constant: '<S128>/Constant4'
       *  UnitDelay: '<S140>/Unit Delay'
       */
      if (!EngMGslLim_DWork.UnitDelay_DSTATE_m2t) {
        localSwitch2_h = 0.0F;
      }

      /* UnitDelay: '<S162>/Unit Delay' */
      localfractionTmp_0d = EngMGslLim_DWork.UnitDelay_DSTATE_c;

      /* Switch: '<S133>/Switch' incorporates:
       *  UnitDelay: '<S161>/Unit Delay'
       */
      if (!EngMGslLim_DWork.UnitDelay_DSTATE_di) {
        localfractionTmp_0d = localfractionTmp_0d_0;
      }

      /* Sum: '<S128>/Subtract1' */
      localTrkTe_e = (localDataTypeConversion1_c - localSwitch2_h) +
        localfractionTmp_0d;

      /* UnitDelay: '<S160>/Unit Delay' */
      localTmpSignalConversionAtAfuA_ = EngMGslLim_DWork.UnitDelay_DSTATE_kq;

      /* Switch: '<S132>/Switch' incorporates:
       *  Constant: '<S126>/Constant5'
       *  UnitDelay: '<S159>/Unit Delay'
       */
      if (!EngMGslLim_DWork.UnitDelay_DSTATE_ge) {
        localTmpSignalConversionAtAfuA_ = FALSE;
      }

      /* Logic: '<S126>/Logical Operator3' incorporates:
       *  Logic: '<S126>/Logical Operator1'
       *  RelationalOperator: '<S126>/Relational Operator1'
       */
      localLogicalOperator3_n = ((localRelationalOperator_n) ||
        ((localTmpSignalConversionAtAfuA_) && (localfractionTmp_0d_0 !=
        localfractionTmp_0d)));

      /* Outputs for enable SubSystem: '<S128>/Subsystem1' incorporates:
       *  EnablePort: '<S135>/Enable'
       */
      EngMGslLim_Subsystem1(localLogicalOperator3_n, localRelationalOperator_n,
                            localTrkTe_e, &EngMGslLim_B.Subsystem1);

      /* end of Outputs for SubSystem: '<S128>/Subsystem1' */

      /* Sum: '<S128>/Subtract2' */
      localfractionTmp_0d = localfractionTmp_0d_0 -
        EngMGslLim_B.Subsystem1.Switch;

      /* RelationalOperator: '<S139>/LowerRelop1' incorporates:
       *  Constant: '<S128>/Constant5'
       */
      localTmpSignalConversionAtAfuA_ = (localfractionTmp_0d > 10000.0F);

      /* Switch: '<S139>/Switch' incorporates:
       *  Constant: '<S128>/Constant6'
       *  RelationalOperator: '<S139>/UpperRelop'
       */
      if (localfractionTmp_0d < 0.0F) {
        localfractionTmp_0d = 0.0F;
      }

      /* Switch: '<S139>/Switch2' incorporates:
       *  Constant: '<S128>/Constant5'
       */
      if (localTmpSignalConversionAtAfuA_) {
        localfractionTmp_0d = 10000.0F;
      }

      /* DataTypeConversion: '<S153>/Conversion' incorporates:
       *  Constant: '<S131>/Constant5'
       */
      localSwitch2_h = 10000.0F;

      /* Switch: '<S155>/Switch2' incorporates:
       *  RelationalOperator: '<S155>/LowerRelop1'
       *  RelationalOperator: '<S155>/UpperRelop'
       *  Switch: '<S155>/Switch'
       */
      if (!(localfractionTmp_0d > 10000.0F)) {
        localSwitch2_h = localfractionTmp_0d;
      }

      /* UnitDelay: '<S131>/Unit Delay' */
      localSum3_h = EngMGslLim_DWork.UnitDelay_DSTATE_d;

      /* Switch: '<S131>/Switch3' incorporates:
       *  Constant: '<S126>/Constant1'
       *  Logic: '<S131>/Logical Operator'
       *  Logic: '<S131>/Logical Operator1'
       *  Logic: '<S131>/Logical Operator2'
       *  Logic: '<S131>/Logical Operator3'
       *  Sum: '<S131>/Sum1'
       *  UnitDelay: '<S131>/Unit Delay1'
       */
      if ((localLogicalOperator3_n) && (!EngMGslLim_DWork.UnitDelay1_DSTATE_l))
      {
        localSum3_h = localDataTypeConversion1_c + localSwitch2_h;
      }

      /* Sum: '<S131>/Sum3' */
      localSum3_h -= localDataTypeConversion1_c;

      /* Switch: '<S158>/Switch' incorporates:
       *  Constant: '<S131>/Constant1'
       *  RelationalOperator: '<S158>/UpperRelop'
       */
      if (localSum3_h < 0.0F) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = localSum3_h;
      }

      /* Switch: '<S158>/Switch2' incorporates:
       *  RelationalOperator: '<S158>/LowerRelop1'
       */
      if (localSum3_h > localSwitch2_h) {
        localSwitch2_l = localSwitch2_h;
      } else {
        localSwitch2_l = localfractionTmp_0d;
      }

      /* RelationalOperator: '<S131>/Relational Operator' incorporates:
       *  Constant: '<S131>/Constant1'
       */
      localRelationalOperator_fz = (localSum3_h > 0.0F);

      /* Outputs for enable SubSystem: '<S126>/Subsystem' incorporates:
       *  EnablePort: '<S130>/Enable'
       */
      EngMGslLim_Subsystem(localRelationalOperator_fz, localMS1_c, localMS_p,
                           localDataTypeConversion1_c, localSwitch2_l,
                           &EngMGslLim_B.Subsystem, &EngMGslLim_DWork.Subsystem);

      /* end of Outputs for SubSystem: '<S126>/Subsystem' */

      /* Switch: '<S126>/Switch' */
      if (localRelationalOperator_fz) {
        EngMGslLim_B.Merge = EngMGslLim_B.Subsystem.Yk;
      } else {
        EngMGslLim_B.Merge = localMS_p;
      }

      /* Update for UnitDelay: '<S141>/Unit Delay' */
      EngMGslLim_DWork.UnitDelay_DSTATE_om = localSwitch2_l;

      /* Update for UnitDelay: '<S140>/Unit Delay' incorporates:
       *  Constant: '<S136>/Constant3'
       */
      EngMGslLim_DWork.UnitDelay_DSTATE_m2t = TRUE;

      /* Update for UnitDelay: '<S162>/Unit Delay' */
      EngMGslLim_DWork.UnitDelay_DSTATE_c = localfractionTmp_0d_0;

      /* Update for UnitDelay: '<S161>/Unit Delay' incorporates:
       *  Constant: '<S133>/Constant3'
       */
      EngMGslLim_DWork.UnitDelay_DSTATE_di = TRUE;

      /* Update for UnitDelay: '<S160>/Unit Delay' */
      EngMGslLim_DWork.UnitDelay_DSTATE_kq = localRelationalOperator_fz;

      /* Update for UnitDelay: '<S159>/Unit Delay' incorporates:
       *  Constant: '<S132>/Constant3'
       */
      EngMGslLim_DWork.UnitDelay_DSTATE_ge = TRUE;

      /* Update for UnitDelay: '<S131>/Unit Delay1' */
      EngMGslLim_DWork.UnitDelay1_DSTATE_l = localLogicalOperator3_n;

      /* Update for UnitDelay: '<S131>/Unit Delay' */
      EngMGslLim_DWork.UnitDelay_DSTATE_d = localSwitch2_l;

      /* end of Outputs for SubSystem: '<S125>/MSW' */

      /* Update for UnitDelay: '<S170>/Unit Delay' */
      EngMGslLim_DWork.UnitDelay_DSTATE_dk = localTmpSignalConversionAtAfu_n;

      /* Update for UnitDelay: '<S169>/Unit Delay' incorporates:
       *  Constant: '<S164>/Constant3'
       */
      EngMGslLim_DWork.UnitDelay_DSTATE_dp = TRUE;

      /* Update for UnitDelay: '<S172>/Unit Delay' */
      EngMGslLim_DWork.UnitDelay_DSTATE_go = localSwitch_il;

      /* Update for UnitDelay: '<S171>/Unit Delay' incorporates:
       *  Constant: '<S165>/Constant3'
       */
      EngMGslLim_DWork.UnitDelay_DSTATE_gbg = TRUE;
      break;

     case 1:
      /* SignalConversion: '<S117>/Signal Conversion1' */
      EngMGslLim_B.Merge = localfractionTmp_0d_0;
      break;
    }

    /* PreLookup: '<S122>/Prelookup' */
    localExt_nEng_EngMTrb_nEng_A__c = plook_u32u16f_binc
      (localTmpSignalConversionAtExt_n, (&(EngMTrb_nEng_A[0])), 8U,
       &localExt_nEng_EngMTrb_nEng_A_9_);

    /* DataTypeConversion: '<S124>/OutDTConv' incorporates:
     *  Constant: '<S124>/offset'
     *  Constant: '<S124>/offset1'
     *  Constant: '<S124>/one_on_slope'
     *  Product: '<S124>/Product4'
     *  Sum: '<S124>/Add1'
     *  Sum: '<S124>/Add2'
     */
    localSwitch2_h = (128.0F * EngMGslLim_B.Merge) + 0.5F;
    if (localSwitch2_h < 256.0F) {
      if (localSwitch2_h >= 0.0F) {
        localTmpSignalConversionAtExt_s = (UInt8)localSwitch2_h;
      } else {
        localTmpSignalConversionAtExt_s = 0U;
      }
    } else {
      localTmpSignalConversionAtExt_s = MAX_uint8_T;
    }

    /* PreLookup: '<S123>/Prelookup' */
    localEngMTrb_rEth_EngMTrb_rEt_p = plook_u32u8f_binc
      (localTmpSignalConversionAtExt_s, (&(EngMTrb_rEthRef_A[0])), 7U,
       &localEngMTrb_rEth_EngMTrb_rEthR);

    /* Outputs for atomic SubSystem: '<S107>/F03_Apply_corrections_Flex'
     * Block description for '<S107>/F03_Apply_corrections_Flex':
     *  01460_10_03518.FR.28.0
     */

    /* Interpolation_n-D: '<S173>/Interpolation Using Prelookup3' */
    localSum3_h = localExt_nEng_EngMTrb_nEng_A_9_;
    localfrac[0] = localSum3_h;
    localfractionTmp_0d_0 = localEngMTrb_rEth_EngMTrb_rEthR;
    localfrac[1] = localfractionTmp_0d_0;
    localbpIndex[0] = localExt_nEng_EngMTrb_nEng_A__c;
    localbpIndex[1] = localEngMTrb_rEth_EngMTrb_rEt_p;
    localSum3_h = intrp2d_iu8n7ff_u32f_l_ns(localbpIndex, localfrac,
      (&(EngMTrb_facCorLdMaxRef_M[0])), 9U);

    /* Interpolation_n-D: '<S174>/Interpolation Using Prelookup3' */
    localfractionTmp_0d_0 = localExt_nEng_EngMTrb_nEng_A_9_;
    localfrac_0[0] = localfractionTmp_0d_0;
    localfractionTmp_0d_0 = localEngMTrb_rEth_EngMTrb_rEthR;
    localfrac_0[1] = localfractionTmp_0d_0;
    localbpIndex_0[0] = localExt_nEng_EngMTrb_nEng_A__c;
    localbpIndex_0[1] = localEngMTrb_rEth_EngMTrb_rEt_p;
    localfractionTmp_0d = intrp2d_iu8n7ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(EngMTrb_facCorOvbReq_M[0])), 9U);

    /* Interpolation_n-D: '<S175>/Interpolation Using Prelookup3' */
    localfractionTmp_0d_0 = localExt_nEng_EngMTrb_nEng_A_9_;
    localfrac_1[0] = localfractionTmp_0d_0;
    localfractionTmp_0d_0 = localEngMTrb_rEth_EngMTrb_rEthR;
    localfrac_1[1] = localfractionTmp_0d_0;
    localbpIndex_1[0] = localExt_nEng_EngMTrb_nEng_A__c;
    localbpIndex_1[1] = localEngMTrb_rEth_EngMTrb_rEt_p;
    localfractionTmp_0d_0 = intrp2d_iu8n7ff_u32f_l_ns(localbpIndex_1,
      localfrac_1, (&(EngMTrb_facCorOvbAcv_M[0])), 9U);

    /* Product: '<S176>/Divide' */
    EngMTrb_facOvbReqFlex = localDataTypeConversion1_o3 * localfractionTmp_0d;

    /* Product: '<S177>/Divide' */
    EngMTrb_rLdMaxRefFlex = EngMTrb_rLdMaxGsl * localSum3_h;

    /* Product: '<S178>/Divide' */
    EngMTrb_facOvbAcvFlex = localDataTypeConversion3_l * localfractionTmp_0d_0;

    /* end of Outputs for SubSystem: '<S107>/F03_Apply_corrections_Flex' */

    /* Outputs for atomic SubSystem: '<S107>/F04_WarmupE100_Acv'
     * Block description for '<S107>/F04_WarmupE100_Acv':
     *  01460_10_03518.FR.29.0
     */

    /* Logic: '<S119>/Logical Operator' incorporates:
     *  Constant: '<S119>/EngMTrb_bWupFlexAcv_C'
     *  Constant: '<S119>/EngMTrb_rEthThd_C'
     *  Constant: '<S119>/EngMTrb_tCoThd_C'
     *  DataTypeConversion: '<S119>/Data Type Conversion3'
     *  RelationalOperator: '<S119>/Relational Operator1'
     *  RelationalOperator: '<S119>/Relational Operator3'
     */
    EngMTrb_bWupClcAcv = ((EngMTrb_bWupFlexAcv_C &&
      (localTmpSignalConversionAtExt_t <= EngMTrb_tCoThd_C)) &&
                          (EngMGslLim_B.Merge >= (((Float32)EngMTrb_rEthThd_C) *
      0.0078125F)));

    /* end of Outputs for SubSystem: '<S107>/F04_WarmupE100_Acv' */

    /* If: '<S107>/If' incorporates:
     *  ActionPort: '<S120>/Action Port'
     *  ActionPort: '<S121>/Action Port'
     *  SubSystem: '<S107>/F05_Apply_corrections_warmupE100'
     *  SubSystem: '<S107>/F06_Apply_no_corrections_warmupE100'
     *
     * Block description for '<S107>/F05_Apply_corrections_warmupE100':
     *  01460_10_03518.FR.30.0
     *
     * Block description for '<S107>/F06_Apply_no_corrections_warmupE100':
     *  01460_10_03518.FR.31.0
     */
    if (EngMTrb_bWupClcAcv) {
      /* PreLookup: '<S180>/Prelookup' */
      localExt_nEng_EngMTrb_nEng_A__c = plook_u32s16f_binc
        (localTmpSignalConversionAtExt_t, (&(EngMTrb_tCoRef_A[0])), 8U,
         &localInterpolationUsingPreloo_j);

      /* Interpolation_n-D: '<S179>/Interpolation Using Prelookup3' */
      localfractionTmp_0d_0 = localInterpolationUsingPreloo_j;
      localfrac_2[0] = localfractionTmp_0d_0;
      localfractionTmp_0d = localEngMTrb_rEth_EngMTrb_rEthR;
      localfrac_2[1] = localfractionTmp_0d;
      localbpIndex_2[0] = localExt_nEng_EngMTrb_nEng_A__c;
      localbpIndex_2[1] = localEngMTrb_rEth_EngMTrb_rEt_p;
      localInterpolationUsingPreloo_j = intrp2d_iu8n7ff_u32f_l_ns(localbpIndex_2,
        localfrac_2, (&(EngMTrb_facCorColdTCo_M[0])), 9U);

      /* Product: '<S181>/Divide' */
      EngMTrb_rLdMaxRefFlexCor = EngMTrb_rLdMaxRefFlex *
        localInterpolationUsingPreloo_j;
    } else {
      /* SignalConversion: '<S121>/Signal Conversion1' */
      EngMTrb_rLdMaxRefFlexCor = EngMTrb_rLdMaxRefFlex;
    }

    /* SignalConversion: '<S107>/Signal Conversion1' */
    EngMTrb_rEth = EngMGslLim_B.Merge;
    break;

   case 1:
    /* Constant: '<S108>/cste' */
    EngMTrb_rEth = 0.0F;

    /* SignalConversion: '<S108>/Signal Conversion3' */
    EngMTrb_facOvbAcvFlex = localDataTypeConversion3_l;

    /* SignalConversion: '<S108>/Signal Conversion2' */
    EngMTrb_facOvbReqFlex = localDataTypeConversion1_o3;

    /* SignalConversion: '<S108>/Signal Conversion1' */
    EngMTrb_rLdMaxRefFlexCor = EngMTrb_rLdMaxGsl;
    break;
  }

  /* Outputs for atomic SubSystem: '<S88>/F04_TIA_Overboost'
   * Block description for '<S88>/F04_TIA_Overboost':
   *  01460_10_03518_2.FR.5.2
   */

  /* Lookup_n-D: '<S182>/Lookup Table (n-D)' */
  localLookupTablenD = look1_iu16lftu16n14If_binlcns
    (localTmpSignalConversionAtInThM, (&(EngMTrb_tAirUsInVlv_A[0])),
     (&(EngMTrb_facCorTInVlv_T[0])), 7U);

  /* Product: '<S185>/Divide' incorporates:
   *  Product: '<S183>/Divide'
   *  Product: '<S184>/Divide'
   */
  EngMTrb_prm_rLdMaxRef[0] = (EngMTrb_rLdMaxRefFlexCor * EngMTrb_facOvbReqFlex) *
    localLookupTablenD;
  EngMTrb_prm_rLdMaxRef[1] = (EngMTrb_rLdMaxRefFlexCor * EngMTrb_facOvbAcvFlex) *
    localLookupTablenD;

  /* end of Outputs for SubSystem: '<S88>/F04_TIA_Overboost' */

  /* end of Outputs for SubSystem: '<S7>/F01_rLdMaxRef' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUsThr);

  /* Outputs for atomic SubSystem: '<S7>/F03_Remplissage_Max_Thermal_Stress' *
   * Block requirements for '<S7>/F03_Remplissage_Max_Thermal_Stress':
   *  1. SubSystem "F03_Remplissage_Max_Thermal_Stress" !Trace_To : VEMS_R_11_01002_016.01 ;
   */

  /* Lookup2D: '<S216>/Look-Up Table (2-D)'
   * About '<S216>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(EngMTrb_rLdMaxTAirLim), (&(EngMTrb_rLdMaxTAirLim_M[0])),
                     localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdTAirX_A[0])),
                     11U, localTmpSignalConversionAtUsThr,
                     (&(EngMTrb_tThrMesY_A[0])), 5U);

  /* DataTypeDuplicate Block: '<S216>/Data Type Duplicate2'
   *
   * Regarding '<S216>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* end of Outputs for SubSystem: '<S7>/F03_Remplissage_Max_Thermal_Stress' */

  /* S-Function (sfun_autosar_clientop): '<S96>/AutosarServer' */
  Rte_Call_R_FRM_bInhLdTrb_GetFunctionPermission(&localAutosarServer_i);

  /* Logic: '<S96>/Not' */
  localNot_h = !localAutosarServer_i;

  /* S-Function (sfun_autosar_clientop): '<S97>/AutosarServer' */
  Rte_Call_R_FRM_bRedLdMax_GetFunctionPermission(&localAutosarServer_i);

  /* Logic: '<S97>/Not' */
  localNot_p = !localAutosarServer_i;

  /* S-Function (sfun_autosar_clientop): '<S94>/AutosarServer' */
  Rte_Call_R_FRM_bAcvLimLd_GetFunctionPermission(&localAutosarServer_i);

  /* Logic: '<S94>/Not' */
  localNot_g = !localAutosarServer_i;

  /* S-Function (sfun_autosar_clientop): '<S95>/AutosarServer' */
  Rte_Call_R_FRM_bAcvLockVlvRbl_GetFunctionPermission(&localAutosarServer_i);

  /* Logic: '<S95>/Not' */
  localNot_p4 = !localAutosarServer_i;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_facSlopEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcCor'
   */
  Rte_Read_R_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (&localTmpSignalConversionAtEng_d);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_facOfsEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facOfsEfcCor'
   */
  Rte_Read_R_EngM_facOfsEfcCor_EngM_facOfsEfcCor
    (&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_pLossCACOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pLossCAC'
   */
  Rte_Read_R_UsThrM_pLossCAC_UsThrM_pLossCAC(&localTmpSignalConversionAtUsT_c);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_tUsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tUsCmpr'
   */
  Rte_Read_R_UsThrM_tUsCmpr_UsThrM_tUsCmpr(&localTmpSignalConversionAtUsT_p);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_pUsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsCmpr'
   */
  Rte_Read_R_UsThrM_pUsCmpr_UsThrM_pUsCmpr(&localTmpSignalConversionAtUsT_i);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInM_concAirCorOutport2' incorporates:
   *  Inport: '<Root>/InM_concAirCor'
   */
  Rte_Read_R_InM_concAirCor_InM_concAirCor(&localTmpSignalConversionAtInM_c);

  /* Outputs for atomic SubSystem: '<S7>/F04_Remplissage_Overspeed_Trb' *
   * Block requirements for '<S7>/F04_Remplissage_Overspeed_Trb':
   *  1. SubSystem "F04_Remplissage_Overspeed_Trb" !Trace_To : VEMS_R_11_01002_017.03 ;
   */

  /* DataTypeConversion: '<S91>/DTConv_Single_To_UFix_6' incorporates:
   *  Constant: '<S91>/EngMTrb_pDsCmprMax_C'
   */
  localfractionTmp_0d_0 = ((Float32)EngMTrb_pDsCmprMax_C) * 8.0F;

  /* Sum: '<S91>/Sum1' incorporates:
   *  DataTypeConversion: '<S91>/DTConv_Single_To_UFix_1'
   *  DataTypeConversion: '<S91>/DTConv_Single_To_UFix_2'
   *  Lookup_n-D: '<S217>/Lookup Table (n-D)'
   *  Product: '<S220>/Divide'
   */
  localSwitch2_h = ((((Float32)localTmpSignalConversionAtUsT_i) * 8.0F) *
                    look2_1fcv2bcvbcvbfbbr6xfbbnx
                    (localTmpSignalConversionAtUsT_p,
                     localTmpSignalConversionAtExt_n, (&(EngMTrb_tUsCmprX_A[0])),
                     (&(EngMTrb_nEngLdCmprOverSpdY_A[0])),
                     (&(EngMTrb_rCmprOverSpdLim_M[0])),
                     &EngMGslLim_ConstP.LookupTablenD_maxInde[0], 8U)) -
    (((Float32)localTmpSignalConversionAtUsT_c) * 8.0F);

  /* MinMax: '<S91>/MinMax' */
  localfractionTmp_0d_0 = rt_MINf(localfractionTmp_0d_0, localSwitch2_h);

  /* DataStoreWrite: '<S91>/Data Store Write1' incorporates:
   *  Constant: '<S219>/offset'
   *  Constant: '<S219>/offset1'
   *  Constant: '<S219>/one_on_slope'
   *  DataTypeConversion: '<S219>/OutDTConv'
   *  Product: '<S219>/Product4'
   *  Sum: '<S219>/Add1'
   *  Sum: '<S219>/Add2'
   */
  localDataTypeConversion1_o3 = (0.125F * localfractionTmp_0d_0) + 0.5F;
  if (localDataTypeConversion1_o3 < 65536.0F) {
    if (localDataTypeConversion1_o3 >= 0.0F) {
      EngMTrb_pDsCmprMax_MP = (UInt16)localDataTypeConversion1_o3;
    } else {
      EngMTrb_pDsCmprMax_MP = 0U;
    }
  } else {
    EngMTrb_pDsCmprMax_MP = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S91>/Data Store Write3' incorporates:
   *  Constant: '<S218>/offset'
   *  Constant: '<S218>/offset1'
   *  Constant: '<S218>/one_on_slope'
   *  DataTypeConversion: '<S218>/OutDTConv'
   *  Product: '<S218>/Product4'
   *  Sum: '<S218>/Add1'
   *  Sum: '<S218>/Add2'
   */
  localSwitch2_h = (0.125F * localSwitch2_h) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      EngMTrb_pCmprOverSp_MP = (UInt16)localSwitch2_h;
    } else {
      EngMTrb_pCmprOverSp_MP = 0U;
    }
  } else {
    EngMTrb_pCmprOverSp_MP = MAX_uint16_T;
  }

  /* Product: '<S222>/Divide' incorporates:
   *  DataTypeConversion: '<S91>/DTConv_Single_To_UFix_3'
   *  DataTypeConversion: '<S91>/DTConv_Single_To_UFix_4'
   *  DataTypeConversion: '<S91>/DTConv_Single_To_UFix_5'
   *  Product: '<S221>/Divide'
   *  Sum: '<S91>/Sum2'
   */
  EngMTrb_rLdMaxBas = (((((Float32)localTmpSignalConversionAtEng_d) *
    3.356933620E-010F) * localfractionTmp_0d_0) - (((Float32)
    localTmpSignalConversionAtEngM_) * 6.103515625E-005F)) * ((((Float32)
    localTmpSignalConversionAtInM_c) * 1.525878906E-005F) + 1.525878906E-005F);

  /* end of Outputs for SubSystem: '<S7>/F04_Remplissage_Overspeed_Trb' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtKnkMgt_bAcvTmpLdLimRblReqOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_bAcvTmpLdLimRblReq'
   */
  Rte_Read_R_KnkMgt_bAcvTmpLdLimRblReq_KnkMgt_bAcvTmpLdLimRblReq
    (&localTmpSignalConversionAtKnk_h);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtKnkMgt_bAcvIrvLdLimRblReqOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_bAcvIrvLdLimRblReq'
   */
  Rte_Read_R_KnkMgt_bAcvIrvLdLimRblReq_KnkMgt_bAcvIrvLdLimRblReq
    (&localTmpSignalConversionAtKnk_i);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtKnkMgt_prm_ctRblInjCutOffPtlOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_prm_ctRblInjCutOffPtl'
   */
  Rte_Read_R_KnkMgt_prm_ctRblInjCutOffPtl_KnkMgt_prm_ctRblInjCutOffPtl
    (&localTmpSignalConversionAtKnkMg);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInjSys_prm_facInjCmpCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_facInjCmpCyl'
   */
  Rte_Read_R_InjSys_prm_facInjCmpCyl_InjSys_prm_facInjCmpCyl
    (&EngMGslLim_B.TmpSignalConversionAtInjSys_prm);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* Outputs for atomic SubSystem: '<S7>/F02_rLdMax_temps_injection_max' *
   * Block requirements for '<S7>/F02_rLdMax_temps_injection_max':
   *  1. SubSystem "F02_rLdMax_temps_injection_max" !Trace_To : VEMS_R_11_01002_015.02 ;
   */

  /* If: '<S89>/If1' incorporates:
   *  ActionPort: '<S186>/Action Port'
   *  ActionPort: '<S187>/Action Port'
   *  Constant: '<S89>/EngMTrb_bFlex_C'
   *  SubSystem: '<S89>/F01_mFuMax_Flex'
   *  SubSystem: '<S89>/F02_mFuMax_Gsl'
   *
   * Block description for '<S89>/F01_mFuMax_Flex':
   *  01460_10_03518.FR.34.0
   *
   * Block description for '<S89>/F02_mFuMax_Gsl':
   *  01460_10_03518.FR.35.0
   */
  if (EngMTrb_bFlex_C) {
    /* Switch: '<S196>/Switch' incorporates:
     *  Constant: '<S192>/Constant1'
     *  RelationalOperator: '<S196>/UpperRelop'
     */
    if (EngMTrb_rEth < 0.0F) {
      localfractionTmp_0d_0 = 0.0F;
    } else {
      localfractionTmp_0d_0 = EngMTrb_rEth;
    }

    /* Switch: '<S196>/Switch2' incorporates:
     *  Constant: '<S192>/Constant'
     *  RelationalOperator: '<S196>/LowerRelop1'
     */
    if (EngMTrb_rEth > 1.0F) {
      localfractionTmp_0d_0 = 1.0F;
    }

    /* DataTypeConversion: '<S186>/Data Type Conversion1' incorporates:
     *  Constant: '<S186>/EngMTrb_mFuMax_C'
     */
    localfractionTmp_0d = ((Float32)EngMTrb_mFuMax_C) * 6.103515625E-005F;

    /* Sum: '<S192>/Sum2' incorporates:
     *  Constant: '<S186>/EngMTrb_mFuMaxEth_C'
     *  DataTypeConversion: '<S186>/Data Type Conversion'
     *  Product: '<S192>/Divide'
     *  Sum: '<S192>/Sum3'
     */
    EngMTrb_mFuMaxFlex = (((((Float32)EngMTrb_mFuMaxEth_C) * 6.103515625E-005F)
      - localfractionTmp_0d) * localfractionTmp_0d_0) + localfractionTmp_0d;
  } else {
    /* DataTypeConversion: '<S187>/Data Type Conversion2' incorporates:
     *  Constant: '<S187>/EngMTrb_mFuMax_C'
     */
    EngMTrb_mFuMaxFlex = ((Float32)EngMTrb_mFuMax_C) * 6.103515625E-005F;
  }

  /* If: '<S89>/If2' incorporates:
   *  ActionPort: '<S188>/Action Port'
   *  ActionPort: '<S189>/Action Port'
   *  Constant: '<S89>/EngMTrb_bFlex_C'
   *  SubSystem: '<S89>/F03_facStoich_Flex'
   *  SubSystem: '<S89>/F04_facStoich_Gsl'
   *
   * Block description for '<S89>/F03_facStoich_Flex':
   *  01460_10_03518.FR.36.0
   *
   * Block description for '<S89>/F04_facStoich_Gsl':
   *  01460_10_03518.FR.37.0
   */
  if (EngMTrb_bFlex_C) {
    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S197>/Constant1'
     *  RelationalOperator: '<S201>/UpperRelop'
     */
    if (EngMTrb_rEth < 0.0F) {
      localfractionTmp_0d_0 = 0.0F;
    } else {
      localfractionTmp_0d_0 = EngMTrb_rEth;
    }

    /* Switch: '<S201>/Switch2' incorporates:
     *  Constant: '<S197>/Constant'
     *  RelationalOperator: '<S201>/LowerRelop1'
     */
    if (EngMTrb_rEth > 1.0F) {
      localfractionTmp_0d_0 = 1.0F;
    }

    /* DataTypeConversion: '<S188>/Data Type Conversion1' incorporates:
     *  Constant: '<S188>/Eng_facStoich_C'
     */
    localfractionTmp_0d = ((Float32)Eng_facStoich_C) * 0.00048828125F;

    /* Sum: '<S197>/Sum2' incorporates:
     *  Constant: '<S188>/Eng_facStoichEth_C'
     *  DataTypeConversion: '<S188>/Data Type Conversion2'
     *  Product: '<S197>/Divide'
     *  Sum: '<S197>/Sum3'
     */
    EngMTrb_facStoichFlex = (((((Float32)Eng_facStoichEth_C) * 0.00048828125F)
      - localfractionTmp_0d) * localfractionTmp_0d_0) + localfractionTmp_0d;
  } else {
    /* DataTypeConversion: '<S189>/Data Type Conversion2' incorporates:
     *  Constant: '<S189>/Eng_facStoich_C'
     */
    EngMTrb_facStoichFlex = ((Float32)Eng_facStoich_C) * 0.00048828125F;
  }

  /* Outputs for atomic SubSystem: '<S89>/F05_rLdMaxTiInjMax'
   * Block description for '<S89>/F05_rLdMaxTiInjMax':
   *  01460_10_03518_2.FR.6.2
   */

  /* Product: '<S204>/Divide' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion1'
   */
  localfractionTmp_0d_0 = EngMTrb_mFuMaxFlex / (((Float32)
    localTmpSignalConversionAtFARSp) * 0.000244140625F);

  /* Outputs for atomic SubSystem: '<S204>/If Action Subsystem3' */

  /* Switch: '<S211>/Switch1' incorporates:
   *  Constant: '<S211>/Constant1'
   *  Constant: '<S211>/Constant2'
   *  Constant: '<S211>/Constant3'
   *  Logic: '<S211>/Logical Operator1'
   *  RelationalOperator: '<S211>/Relational Operator'
   *  RelationalOperator: '<S211>/Relational Operator1'
   *  RelationalOperator: '<S211>/Relational Operator3'
   */
  if (((localfractionTmp_0d_0 != localfractionTmp_0d_0) ||
       (localfractionTmp_0d_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
       localfractionTmp_0d_0)) {
    localfractionTmp_0d_0 = 1.0F;
  }

  /* end of Outputs for SubSystem: '<S204>/If Action Subsystem3' */

  /* Sum: '<S203>/Add2' incorporates:
   *  Constant: '<S203>/offset'
   *  Constant: '<S203>/offset1'
   *  Constant: '<S203>/one_on_slope'
   *  Product: '<S203>/Product4'
   *  Sum: '<S203>/Add1'
   */
  localfractionTmp_0d = (16384.0F * localfractionTmp_0d_0) + 0.5F;

  /* DataStoreWrite: '<S190>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S203>/OutDTConv'
   */
  if (localfractionTmp_0d < 4.294967296E+009F) {
    if (localfractionTmp_0d >= 0.0F) {
      EngMTrb_mFuMaxInter_MP = (UInt32)localfractionTmp_0d;
    } else {
      EngMTrb_mFuMaxInter_MP = 0U;
    }
  } else {
    EngMTrb_mFuMaxInter_MP = MAX_uint32_T;
  }

  /* Product: '<S205>/Divide' incorporates:
   *  Constant: '<S190>/Eng_mRef_C'
   *  DataTypeConversion: '<S190>/Data Type Conversion'
   *  Lookup_n-D: '<S202>/Lookup Table (n-D)'
   *  Product: '<S207>/Divide'
   *  Product: '<S208>/Divide'
   */
  localfractionTmp_0d_0 = ((localfractionTmp_0d_0 *
    look1_is16lftu16n14If_binlcns(localTmpSignalConversionAtExt_t,
    (&(EngMTrb_tCoMes_A[0])), (&(EngMTrb_facCorT_T[0])), 7U)) *
    EngMTrb_facStoichFlex) / (((Float32)Eng_mRef_C) * 1.192016583E-007F);

  /* Outputs for atomic SubSystem: '<S205>/If Action Subsystem3' */

  /* Switch: '<S213>/Switch1' incorporates:
   *  Constant: '<S213>/Constant1'
   *  Constant: '<S213>/Constant2'
   *  Constant: '<S213>/Constant3'
   *  Logic: '<S213>/Logical Operator1'
   *  RelationalOperator: '<S213>/Relational Operator'
   *  RelationalOperator: '<S213>/Relational Operator1'
   *  RelationalOperator: '<S213>/Relational Operator3'
   */
  if (((localfractionTmp_0d_0 != localfractionTmp_0d_0) ||
       (localfractionTmp_0d_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
       localfractionTmp_0d_0)) {
    localfractionTmp_0d_0 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S205>/If Action Subsystem3' */

  /* Product: '<S206>/Divide' incorporates:
   *  Constant: '<S190>/Cste_6'
   *  Product: '<S209>/Divide'
   */
  localfractionTmp_0d_0 /= ((Float32)localTmpSignalConversionAtExt_n) * 6.0F;

  /* Outputs for atomic SubSystem: '<S206>/If Action Subsystem3' */

  /* Switch: '<S215>/Switch1' incorporates:
   *  Constant: '<S215>/Constant1'
   *  Constant: '<S215>/Constant2'
   *  Constant: '<S215>/Constant3'
   *  Logic: '<S215>/Logical Operator1'
   *  RelationalOperator: '<S215>/Relational Operator'
   *  RelationalOperator: '<S215>/Relational Operator1'
   *  RelationalOperator: '<S215>/Relational Operator3'
   */
  if (((localfractionTmp_0d_0 != localfractionTmp_0d_0) ||
       (localfractionTmp_0d_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
       localfractionTmp_0d_0)) {
    localfractionTmp_0d_0 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S206>/If Action Subsystem3' */

  /* Switch: '<S190>/Switch3' incorporates:
   *  Constant: '<S190>/Cste_0'
   *  Constant: '<S190>/EngMTrb_rLdMaxTiInjEs_C'
   *  DataTypeConversion: '<S190>/Data Type Conversion2'
   *  RelationalOperator: '<S190>/Relational Operator'
   */
  if (localTmpSignalConversionAtExt_n == 0) {
    EngMTrb_rLdMaxTiInjMax = ((Float32)EngMTrb_rLdMaxTiInjEs_C) *
      6.103515625E-005F;
  } else {
    EngMTrb_rLdMaxTiInjMax = localfractionTmp_0d_0;
  }

  /* end of Outputs for SubSystem: '<S89>/F05_rLdMaxTiInjMax' */

  /* end of Outputs for SubSystem: '<S7>/F02_rLdMax_temps_injection_max' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtKnkMgt_bAcvTmpLdLimKnkReqOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_bAcvTmpLdLimKnkReq'
   */
  Rte_Read_R_KnkMgt_bAcvTmpLdLimKnkReq_KnkMgt_bAcvTmpLdLimKnkReq
    (&localTmpSignalConversionAtKnk_d);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_rMaxIgEfcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rMaxIgEfc'
   */
  Rte_Read_R_IgSys_rMaxIgEfc_IgSys_rMaxIgEfc(&localTmpSignalConversionAtIgSys);

  /* Outputs for atomic SubSystem: '<S7>/F05_KnkCtl' *
   * Block requirements for '<S7>/F05_KnkCtl':
   *  1. SubSystem "F05_KnkCtl" !Trace_To : VEMS_R_11_01002_018.01 ;
   */

  /* Outputs for atomic SubSystem: '<S92>/F01_LowRon' *
   * Block requirements for '<S92>/F01_LowRon':
   *  1. SubSystem "F01_LowRon" !Trace_To : VEMS_R_11_01002_019.03 ;
   */

  /* UnitDelay: '<S232>/Unit Delay' */
  localTmpSignalConversionAtAfuA_ = EngMGslLim_DWork.UnitDelay_DSTATE_pl;

  /* DataTypeConversion: '<S223>/Data Type Conversion3' incorporates:
   *  Constant: '<S223>/EngMTrb_tiSampleFast_SC'
   */
  localfractionTmp_0d_0 = ((Float32)EngMTrb_tiSampleFast_SC) *
    5.000000237E-004F;

  /* Lookup: '<S226>/Look-Up Table'
   * About '<S226>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_p), (&(EngMTrb_rFilGainLoRon_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngFilGain_A[0])),
                 5U);

  /* DataTypeDuplicate Block: '<S226>/Data Type Duplicate1'
   *
   * Regarding '<S226>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Product: '<S230>/Divide' incorporates:
   *  DataTypeConversion: '<S223>/Data Type Conversion2'
   *  Lookup: '<S226>/Look-Up Table'
   *  Sum: '<S225>/Sum3'
   */
  localfractionTmp_0d = localfractionTmp_0d_0 / ((((Float32)localLookUpTable_p)
    * 1.000000047E-003F) + localfractionTmp_0d_0);

  /* Lookup2D: '<S227>/Look-Up Table (2-D)'
   * About '<S227>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-10
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_m), (&(EngMTrb_rLdKnkLoRon_M[0])),
                     localTmpSignalConversionAtIgSys, (&(EngMTrb_rMaxIgEfcX_A[0])),
                     15U, localTmpSignalConversionAtExt_n,
                     (&(EngMTrb_nEngLdLoRonY_A[0])), 9U);

  /* DataTypeDuplicate Block: '<S227>/Data Type Duplicate2'
   *
   * Regarding '<S227>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* UnitDelay: '<S234>/Unit Delay' */
  localfractionTmp_0d_0 = EngMGslLim_DWork.UnitDelay_DSTATE_k;

  /* DataTypeConversion: '<S223>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_rLdMaxLoRonIniOutport2'
   */
  localSum3_h = ((Float32)
                 Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_rLdMaxLoRonIni_irv())
    * 6.103515625E-005F;

  /* Switch: '<S229>/Switch' incorporates:
   *  UnitDelay: '<S233>/Unit Delay'
   */
  if (!EngMGslLim_DWork.UnitDelay_DSTATE_b5) {
    localfractionTmp_0d_0 = localSum3_h;
  }

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S223>/Constant'
   *  DataTypeConversion: '<S223>/Data Type Conversion'
   *  Logic: '<S225>/Logical Operator'
   *  Lookup2D: '<S227>/Look-Up Table (2-D)'
   *  Product: '<S231>/Divide'
   *  Sum: '<S225>/Sum1'
   *  Sum: '<S225>/Sum2'
   */
  localfractionTmp_0d_0 -= (localfractionTmp_0d_0 - (((Float32)
    localLookUpTable2D_m) * 6.103515625E-005F)) * localfractionTmp_0d;

  /* Switch: '<S228>/Switch' */
  if (localTmpSignalConversionAtAfuA_) {
    EngMTrb_rLdMaxLoRon = localfractionTmp_0d_0;
  } else {
    EngMTrb_rLdMaxLoRon = localSum3_h;
  }

  /* Update for UnitDelay: '<S232>/Unit Delay' incorporates:
   *  Constant: '<S228>/Constant3'
   */
  EngMGslLim_DWork.UnitDelay_DSTATE_pl = TRUE;

  /* Update for UnitDelay: '<S234>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_k = localfractionTmp_0d_0;

  /* Update for UnitDelay: '<S233>/Unit Delay' incorporates:
   *  Constant: '<S229>/Constant3'
   */
  EngMGslLim_DWork.UnitDelay_DSTATE_b5 = TRUE;

  /* end of Outputs for SubSystem: '<S92>/F01_LowRon' */

  /* Outputs for atomic SubSystem: '<S92>/F02_Knock' *
   * Block requirements for '<S92>/F02_Knock':
   *  1. SubSystem "F02_Knock" !Trace_To : VEMS_R_11_01002_020.02 ;
   */

  /* Lookup: '<S235>/Look-Up Table'
   * About '<S235>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_b), (&(EngMTrb_rLdIncProtKnk_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdIncKnk_A[0])),
                 5U);

  /* DataTypeDuplicate Block: '<S235>/Data Type Duplicate1'
   *
   * Regarding '<S235>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Lookup: '<S236>/Look-Up Table'
   * About '<S236>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localSwitch2_b2), (&(EngMTrb_rRedStepProtKnk_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngRedStepKnk_A[0])),
                 5U);

  /* DataTypeDuplicate Block: '<S236>/Data Type Duplicate1'
   *
   * Regarding '<S236>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Lookup: '<S237>/Look-Up Table'
   * About '<S237>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-7  FSlope 1.28
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_n), (&(EngMTrb_tiRedLdKnkCtl_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngRedLdKnk_A[0])),
                 5U);

  /* DataTypeDuplicate Block: '<S237>/Data Type Duplicate1'
   *
   * Regarding '<S237>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S248>/Conversion' incorporates:
   *  Constant: '<S224>/EngMTrb_facProtKnkMin_C'
   */
  localExt_nEng_EngMTrb_nEngLdR_n = (UInt32)(EngMTrb_facProtKnkMin_C << 2);

  /* DataTypeConversion: '<S224>/Conversion1' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_facProtKnkPrevOutport2'
   */
  localfractionTmp_0d_0 = ((Float32)
    Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_facProtKnk_irv()) *
    1.525878906E-005F;

  /* Sum: '<S224>/Sum1' */
  localDataTypeConversion1_o3 = localfractionTmp_0d_0 - (((Float32)
    localSwitch2_b2) * 6.103515625E-005F);

  /* UnitDelay: '<S261>/Unit Delay' */
  localUnitDelay_gg = EngMGslLim_DWork.UnitDelay_DSTATE_px;

  /* Logic: '<S240>/Logical Operator' incorporates:
   *  Logic: '<S240>/Logical Operator1'
   */
  localLogicalOperator_l = ((!localTmpSignalConversionAtKnk_d) &&
    (localUnitDelay_gg));

  /* UnitDelay: '<S260>/Unit Delay' */
  localUnitDelay_gg = EngMGslLim_DWork.UnitDelay_DSTATE_ho;

  /* DataTypeConversion: '<S254>/Conversion' incorporates:
   *  Constant: '<S239>/Constant4'
   */
  localExt_nEng_EngMTrb_nEng_A__c = mul_u32_u32_u32_sat(MAX_uint32_T, 2000U);
  if (localExt_nEng_EngMTrb_nEng_A__c > 65535U) {
    localSwitch2_b2 = MAX_uint16_T;
  } else {
    localSwitch2_b2 = (UInt16)localExt_nEng_EngMTrb_nEng_A__c;
  }

  /* Switch: '<S256>/Switch2' incorporates:
   *  Constant: '<S224>/EngMTrb_tiSampleFast_SC1'
   *  Constant: '<S239>/Constant5'
   *  RelationalOperator: '<S256>/LowerRelop1'
   *  RelationalOperator: '<S256>/UpperRelop'
   *  Switch: '<S256>/Switch'
   */
  if (!(EngMTrb_tiSampleFast_SC > localSwitch2_b2)) {
    localSwitch2_b2 = EngMTrb_tiSampleFast_SC;
  }

  /* Sum: '<S239>/Sum1' incorporates:
   *  UnitDelay: '<S253>/Unit Delay'
   */
  localtmp = localSwitch2_b2;
  localExt_nEng_EngMTrb_nEng_A__c = ((UInt32)localtmp) +
    EngMGslLim_DWork.UnitDelay_DSTATE_kc;
  if (localExt_nEng_EngMTrb_nEng_A__c < ((UInt32)localtmp)) {
    localExt_nEng_EngMTrb_nEng_A__c = MAX_uint32_T;
  }

  /* Switch: '<S239>/Switch1' incorporates:
   *  UnitDelay: '<S253>/Unit Delay'
   */
  if (!localTmpSignalConversionAtKnk_d) {
    localExt_nEng_EngMTrb_nEng_A__c = EngMGslLim_DWork.UnitDelay_DSTATE_kc;
  }

  /* Switch: '<S239>/Switch2' incorporates:
   *  Constant: '<S239>/Constant1'
   *  Logic: '<S252>/Logical Operator'
   *  Logic: '<S252>/Logical Operator1'
   */
  if ((localLogicalOperator_l) && (!localUnitDelay_gg)) {
    localExt_nEng_EngMTrb_nEng_A__c = 0U;
  }

  /* Switch: '<S259>/Switch2' incorporates:
   *  Constant: '<S239>/Cnt_Max'
   *  RelationalOperator: '<S259>/LowerRelop1'
   */
  if (localExt_nEng_EngMTrb_nEng_A__c > 800000U) {
    localEngMTrb_rEth_EngMTrb_rEt_p = 800000U;
  } else {
    localEngMTrb_rEth_EngMTrb_rEt_p = localExt_nEng_EngMTrb_nEng_A__c;
  }

  /* RelationalOperator: '<S224>/Relational Operator2' incorporates:
   *  Constant: '<S224>/EngMTrb_tiSampleFast_SC1'
   *  Math: '<S241>/Math Function'
   *  Sum: '<S224>/Sum3'
   */
  localUnitDelay_gg = (rt_mod_uint32(localEngMTrb_rEth_EngMTrb_rEt_p, (UInt32)
                        ((localLookUpTable_n * 20) + EngMTrb_tiSampleFast_SC)) >=
                       ((UInt32)(localLookUpTable_n * 20)));

  /* UnitDelay: '<S265>/Unit Delay' */
  localSwitch_fs = EngMGslLim_DWork.UnitDelay_DSTATE_aq;

  /* Logic: '<S224>/Logical Operator' incorporates:
   *  Logic: '<S242>/Logical Operator'
   *  Logic: '<S242>/Logical Operator1'
   */
  localLogicalOperator_f = ((localUnitDelay_gg) ||
    ((localTmpSignalConversionAtKnk_d) && (!localSwitch_fs)));

  /* Switch: '<S224>/Switch' */
  if (!localLogicalOperator_f) {
    localDataTypeConversion1_o3 = localfractionTmp_0d_0;
  }

  /* UnitDelay: '<S269>/Unit Delay' */
  localSwitch_fs = EngMGslLim_DWork.UnitDelay_DSTATE_d0;

  /* UnitDelay: '<S276>/Unit Delay' */
  localUnitDelay_gg = EngMGslLim_DWork.UnitDelay_DSTATE_od;

  /* DataTypeConversion: '<S224>/Conversion5' incorporates:
   *  Constant: '<S224>/EngMTrb_tiSampleFast_SC1'
   */
  localfractionTmp_0d = ((Float32)EngMTrb_tiSampleFast_SC) * 5.000000237E-004F;

  /* MinMax: '<S244>/MinMax1' incorporates:
   *  Constant: '<S244>/Constant1'
   */
  localExt_nEng_EngMTrb_nEng_A__c = (UInt32)(localLookUpTable_n << 1);

  /* Sum: '<S244>/Sum2' incorporates:
   *  Constant: '<S244>/Constant6'
   *  Product: '<S244>/Product'
   */
  localDataTypeConversion3_l = (((Float32)localExt_nEng_EngMTrb_nEng_A__c) *
    4.999999888E-003F) + (10.0F * localfractionTmp_0d);

  /* UnitDelay: '<S268>/Unit Delay' */
  localSum3_h = EngMGslLim_DWork.UnitDelay_DSTATE_n;

  /* Switch: '<S274>/Switch' incorporates:
   *  Constant: '<S244>/Constant3'
   *  RelationalOperator: '<S274>/UpperRelop'
   */
  if (EngMGslLim_DWork.UnitDelay_DSTATE_n < 0.0F) {
    localSum3_h = 0.0F;
  }

  /* Switch: '<S274>/Switch2' incorporates:
   *  RelationalOperator: '<S274>/LowerRelop1'
   */
  if (!(EngMGslLim_DWork.UnitDelay_DSTATE_n > localDataTypeConversion3_l)) {
    localDataTypeConversion3_l = localSum3_h;
  }

  /* Switch: '<S244>/Switch1' incorporates:
   *  Constant: '<S244>/Constant4'
   *  Constant: '<S244>/Constant7'
   *  Logic: '<S244>/Logical Operator2'
   *  Logic: '<S270>/Logical Operator'
   *  Logic: '<S270>/Logical Operator1'
   *  Sum: '<S244>/Sum1'
   */
  if ((localSwitch_fs) || ((!localLogicalOperator_f) && (localUnitDelay_gg))) {
    localLookupTablenD = 0.0F;
  } else {
    localLookupTablenD = (localfractionTmp_0d + localDataTypeConversion3_l) +
      2.220446049E-016F;
  }

  /* RelationalOperator: '<S244>/Relational Operator2' */
  localRelationalOperator1_m4 = (localLookupTablenD >= (((Float32)
    localExt_nEng_EngMTrb_nEng_A__c) * 4.999999888E-003F));

  /* UnitDelay: '<S277>/Unit Delay' */
  localSwitch_fs = EngMGslLim_DWork.UnitDelay_DSTATE_omv;

  /* RelationalOperator: '<S244>/Relational Operator1' incorporates:
   *  Constant: '<S244>/Constant2'
   */
  localRelationalOperator1_a = (localExt_nEng_EngMTrb_nEng_A__c == 0U);

  /* Switch: '<S244>/Switch' incorporates:
   *  Constant: '<S244>/Constant5'
   *  Logic: '<S244>/Logical Operator1'
   *  Logic: '<S271>/Logical Operator'
   *  Logic: '<S271>/Logical Operator1'
   */
  if (!localRelationalOperator1_a) {
    localSwitch_fs = ((localRelationalOperator1_m4) && (!localSwitch_fs));
  } else {
    localSwitch_fs = TRUE;
  }

  /* UnitDelay: '<S275>/Unit Delay' */
  localUnitDelay_gg = EngMGslLim_DWork.UnitDelay_DSTATE_mf;

  /* CombinatorialLogic: '<S267>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator_f != 0);
    rowidx = (rowidx << 1) + (UInt32)(localSwitch_fs != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_gg != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_d[0] = EngMGslLim_ConstP.pooled21[rowidx];
    localLogic_d[1] = EngMGslLim_ConstP.pooled21[rowidx + 8];
  }

  /* Logic: '<S224>/Logical Operator1' */
  localTmpSignalConversionAtAfuA_ = ((localTmpSignalConversionAtKnk_d) ||
    (localLogic_d[0]));

  /* Sum: '<S224>/Sum2' incorporates:
   *  Product: '<S246>/Divide'
   */
  localSwitch2_h = ((((Float32)localLookUpTable_b) * 6.103515625E-005F) *
                    localfractionTmp_0d) + localfractionTmp_0d_0;

  /* UnitDelay: '<S281>/Unit Delay' */
  localSwitch_fs = EngMGslLim_DWork.UnitDelay_DSTATE_hk;

  /* UnitDelay: '<S288>/Unit Delay' */
  localUnitDelay_gg = EngMGslLim_DWork.UnitDelay_DSTATE_e5;

  /* Sum: '<S245>/Sum2' incorporates:
   *  Constant: '<S224>/EngMTrb_tiDlyEndProtKnk_C'
   *  Constant: '<S245>/Constant1'
   *  Constant: '<S245>/Constant6'
   *  MinMax: '<S245>/MinMax1'
   *  Product: '<S245>/Product'
   */
  localSum3_h = (((Float32)EngMTrb_tiDlyEndProtKnk_C) * 5.493164063E-002F) +
    (10.0F * localfractionTmp_0d);

  /* UnitDelay: '<S280>/Unit Delay' */
  localDataTypeConversion3_l = EngMGslLim_DWork.UnitDelay_DSTATE_gq;

  /* Switch: '<S286>/Switch' incorporates:
   *  Constant: '<S245>/Constant3'
   *  RelationalOperator: '<S286>/UpperRelop'
   */
  if (EngMGslLim_DWork.UnitDelay_DSTATE_gq < 0.0F) {
    localDataTypeConversion3_l = 0.0F;
  }

  /* Switch: '<S286>/Switch2' incorporates:
   *  RelationalOperator: '<S286>/LowerRelop1'
   */
  if (!(EngMGslLim_DWork.UnitDelay_DSTATE_gq > localSum3_h)) {
    localSum3_h = localDataTypeConversion3_l;
  }

  /* Switch: '<S245>/Switch1' incorporates:
   *  Constant: '<S245>/Constant4'
   *  Constant: '<S245>/Constant7'
   *  Logic: '<S245>/Logical Operator2'
   *  Logic: '<S282>/Logical Operator'
   *  Logic: '<S282>/Logical Operator1'
   *  Sum: '<S245>/Sum1'
   */
  if ((localSwitch_fs) || ((!localTmpSignalConversionAtKnk_d) &&
       (localUnitDelay_gg))) {
    localfractionTmp_0d_0 = 0.0F;
  } else {
    localfractionTmp_0d_0 = (localfractionTmp_0d + localSum3_h) +
      2.220446049E-016F;
  }

  /* RelationalOperator: '<S245>/Relational Operator2' incorporates:
   *  MinMax: '<S245>/MinMax1'
   */
  localRelationalOperator2_d = (localfractionTmp_0d_0 >= (((Float32)
    EngMTrb_tiDlyEndProtKnk_C) * 5.493164063E-002F));

  /* UnitDelay: '<S289>/Unit Delay' */
  localSwitch_fs = EngMGslLim_DWork.UnitDelay_DSTATE_ef;

  /* RelationalOperator: '<S245>/Relational Operator1' incorporates:
   *  Constant: '<S245>/Constant2'
   *  MinMax: '<S245>/MinMax1'
   */
  localRelationalOperator1_o = (EngMTrb_tiDlyEndProtKnk_C == 0);

  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S245>/Constant5'
   *  Logic: '<S245>/Logical Operator1'
   *  Logic: '<S283>/Logical Operator'
   *  Logic: '<S283>/Logical Operator1'
   */
  if (!localRelationalOperator1_o) {
    localSwitch_fs = ((localRelationalOperator2_d) && (!localSwitch_fs));
  } else {
    localSwitch_fs = TRUE;
  }

  /* UnitDelay: '<S287>/Unit Delay' */
  localUnitDelay_gg = EngMGslLim_DWork.UnitDelay_DSTATE_gb;

  /* CombinatorialLogic: '<S279>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localTmpSignalConversionAtKnk_d != 0);
    rowidx = (rowidx << 1) + (UInt32)(localSwitch_fs != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_gg != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_o[0] = EngMGslLim_ConstP.pooled21[rowidx];
    localLogic_o[1] = EngMGslLim_ConstP.pooled21[rowidx + 8];
  }

  /* Switch: '<S224>/Switch2' incorporates:
   *  Constant: '<S224>/EngMTrb_facProtKnkInh_C'
   *  DataTypeConversion: '<S224>/Conversion3'
   */
  if (localLogic_o[0]) {
    localDataTypeConversion3_l = localSwitch2_h;
  } else {
    localDataTypeConversion3_l = ((Float32)EngMTrb_facProtKnkInh_C) *
      6.103515625E-005F;
  }

  /* Switch: '<S224>/Switch1' */
  if (!localTmpSignalConversionAtAfuA_) {
    localDataTypeConversion1_o3 = localDataTypeConversion3_l;
  }

  /* DataTypeConversion: '<S243>/OutDTConv' incorporates:
   *  Constant: '<S243>/offset'
   *  Constant: '<S243>/offset1'
   *  Constant: '<S243>/one_on_slope'
   *  Product: '<S243>/Product4'
   *  Sum: '<S243>/Add1'
   *  Sum: '<S243>/Add2'
   */
  localSwitch2_h = (65536.0F * localDataTypeConversion1_o3) + 0.5F;
  if (localSwitch2_h < 4.294967296E+009F) {
    if (localSwitch2_h >= 0.0F) {
      localExt_nEng_EngMTrb_nEng_A__c = (UInt32)localSwitch2_h;
    } else {
      localExt_nEng_EngMTrb_nEng_A__c = 0U;
    }
  } else {
    localExt_nEng_EngMTrb_nEng_A__c = MAX_uint32_T;
  }

  /* Switch: '<S249>/Switch' incorporates:
   *  RelationalOperator: '<S249>/UpperRelop'
   */
  if (!(localExt_nEng_EngMTrb_nEng_A__c < localExt_nEng_EngMTrb_nEngLdR_n)) {
    localExt_nEng_EngMTrb_nEngLdR_n = localExt_nEng_EngMTrb_nEng_A__c;
  }

  /* Switch: '<S249>/Switch2' incorporates:
   *  Constant: '<S224>/Constant'
   *  RelationalOperator: '<S249>/LowerRelop1'
   */
  if (localExt_nEng_EngMTrb_nEng_A__c > 65536U) {
    localExt_nEng_EngMTrb_nEngLdR_n = 65536U;
  }

  /* RelationalOperator: '<S224>/RO1' incorporates:
   *  Constant: '<S224>/Constant'
   */
  localRO1 = (65536U > localExt_nEng_EngMTrb_nEngLdR_n);

  /* Update for UnitDelay: '<S261>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_px = localTmpSignalConversionAtKnk_d;

  /* Update for UnitDelay: '<S260>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_ho = localLogicalOperator_l;

  /* Update for UnitDelay: '<S253>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_kc = localEngMTrb_rEth_EngMTrb_rEt_p;

  /* Update for UnitDelay: '<S265>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_aq = localTmpSignalConversionAtKnk_d;

  /* Update for UnitDelay: '<S269>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_d0 = localRelationalOperator1_a;

  /* Update for UnitDelay: '<S276>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_od = localLogicalOperator_f;

  /* Update for UnitDelay: '<S268>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_n = localLookupTablenD;

  /* Update for UnitDelay: '<S277>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_omv = localRelationalOperator1_m4;

  /* Update for UnitDelay: '<S275>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_mf = localLogic_d[0];

  /* Update for UnitDelay: '<S281>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_hk = localRelationalOperator1_o;

  /* Update for UnitDelay: '<S288>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_e5 = localTmpSignalConversionAtKnk_d;

  /* Update for UnitDelay: '<S280>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_gq = localfractionTmp_0d_0;

  /* Update for UnitDelay: '<S289>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_ef = localRelationalOperator2_d;

  /* Update for UnitDelay: '<S287>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_gb = localLogic_o[0];

  /* end of Outputs for SubSystem: '<S92>/F02_Knock' */

  /* end of Outputs for SubSystem: '<S7>/F05_KnkCtl' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTPM_rLdProtExThermoOutport2' incorporates:
   *  Inport: '<Root>/TPM_rLdProtExThermo'
   */
  Rte_Read_R_TPM_rLdProtExThermo_TPM_rLdProtExThermo
    (&localTmpSignalConversionAtTPM_k);

  /* Outputs for atomic SubSystem: '<S7>/F06_Limitations_Remplissage_Mx1' *
   * Block requirements for '<S7>/F06_Limitations_Remplissage_Mx1':
   *  1. SubSystem "F06_Limitations_Remplissage_Mx1" !Trace_To : VEMS_R_11_01002_021.02 ;
   */

  /* Outputs for atomic SubSystem: '<S93>/F01_Freeze'
   * Block description for '<S93>/F01_Freeze':
   *  01460_10_03518_2.FR.19.0
   *
   * Block requirements for '<S93>/F01_Freeze':
   *  1. SubSystem "F01_Freeze" !Trace_To : VEMS_R_11_01002_052.01 ;
   */

  /* Switch: '<S290>/Switch3' incorporates:
   *  Constant: '<S290>/Cste_1'
   *  Constant: '<S290>/Cste_2'
   */
  if (localRO1) {
    localTmpSignalConversionAtExt_s = 2U;
  } else {
    localTmpSignalConversionAtExt_s = 1U;
  }

  /* Switch: '<S340>/Switch2' incorporates:
   *  Constant: '<S299>/Constant2'
   */
  localTmpSignalConversionAtAfu_n = localTmpSignalConversionAtExt_s;

  /* Switch: '<S290>/Switch' incorporates:
   *  Constant: '<S290>/Cste_3'
   *  Constant: '<S290>/EngMTrb_bAcvTPMMod_C'
   */
  if (EngMTrb_bAcvTPMMod_C) {
    EngMTrb_rLdProtTPM = localTmpSignalConversionAtTPM_k;
  } else {
    EngMTrb_rLdProtTPM = 49152U;
  }

  /* DataTypeConversion: '<S290>/Data Type Conversion1' */
  localfractionTmp_0d_0 = ((Float32)EngMTrb_rLdProtTPM) * 6.103515625E-005F;

  /* DataTypeConversion: '<S290>/Data Type Conversion4' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_rLdProtTPMFrzPrevOutport2'
   */
  localfractionTmp_0d = ((Float32)
    Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_rLdProtTPMFrz_irv()) *
    6.103515625E-005F;

  /* MultiPortSwitch: '<S296>/MS' */
  if (localTmpSignalConversionAtExt_s == 1) {
    localMS = localfractionTmp_0d_0;
  } else {
    localMS = localfractionTmp_0d;
  }

  /* UnitDelay: '<S342>/Unit Delay' */
  localTmpSignalConversionAtExt_s = EngMGslLim_DWork.UnitDelay_DSTATE_g1;

  /* Switch: '<S336>/Switch' incorporates:
   *  UnitDelay: '<S341>/Unit Delay'
   */
  if (!EngMGslLim_DWork.UnitDelay_DSTATE_i) {
    localTmpSignalConversionAtExt_s = localTmpSignalConversionAtAfu_n;
  }

  /* RelationalOperator: '<S299>/Relational Operator' */
  localRelationalOperator_d = (localTmpSignalConversionAtExt_s !=
    localTmpSignalConversionAtAfu_n);

  /* UnitDelay: '<S344>/Unit Delay' */
  localSwitch_il = EngMGslLim_DWork.UnitDelay_DSTATE_m;

  /* Switch: '<S337>/Switch' incorporates:
   *  UnitDelay: '<S343>/Unit Delay'
   */
  if (!EngMGslLim_DWork.UnitDelay_DSTATE_b) {
    localSwitch_il = localTmpSignalConversionAtAfu_n;
  }

  /* Switch: '<S299>/Switch' */
  if (localRelationalOperator_d) {
    localSwitch_il = localTmpSignalConversionAtExt_s;
  }

  /* MultiPortSwitch: '<S296>/MS1' */
  if (localSwitch_il == 1) {
    localMS1 = localfractionTmp_0d_0;
  } else {
    localMS1 = localfractionTmp_0d;
  }

  /* Switch: '<S290>/Switch1' incorporates:
   *  Constant: '<S290>/Cste_0'
   *  Constant: '<S290>/EngMTrb_tiSlopFrzTPM_C'
   */
  if (localRO1) {
    locallocalOutDTConv_h_idx = 0U;
  } else {
    locallocalOutDTConv_h_idx = EngMTrb_tiSlopFrzTPM_C;
  }

  /* DataTypeConversion: '<S290>/Data Type Conversion2' */
  localfractionTmp_0d_0 = ((Float32)locallocalOutDTConv_h_idx) *
    9.999999776E-003F;

  /* DataTypeConversion: '<S290>/Data Type Conversion3' incorporates:
   *  Constant: '<S290>/EngMTrb_tiSampleFast_SC'
   */
  localDataTypeConversion3_i = ((Float32)EngMTrb_tiSampleFast_SC) *
    5.000000237E-004F;

  /* Outputs for atomic SubSystem: '<S296>/MSW' */

  /* Switch: '<S316>/Switch' incorporates:
   *  RelationalOperator: '<S316>/UpperRelop'
   */
  if (localfractionTmp_0d_0 < localDataTypeConversion3_i) {
    localSum3_h = localDataTypeConversion3_i;
  } else {
    localSum3_h = localfractionTmp_0d_0;
  }

  /* Switch: '<S316>/Switch2' incorporates:
   *  Constant: '<S298>/Constant17'
   *  RelationalOperator: '<S316>/LowerRelop1'
   */
  if (localfractionTmp_0d_0 > 500.0F) {
    localSwitch2_h = 500.0F;
  } else {
    localSwitch2_h = localSum3_h;
  }

  /* UnitDelay: '<S313>/Unit Delay' */
  localSum3_h = EngMGslLim_DWork.UnitDelay_DSTATE_e;

  /* Switch: '<S308>/Switch' incorporates:
   *  Constant: '<S300>/Constant4'
   *  UnitDelay: '<S312>/Unit Delay'
   */
  if (!EngMGslLim_DWork.UnitDelay_DSTATE_a) {
    localSum3_h = 0.0F;
  }

  /* UnitDelay: '<S334>/Unit Delay' */
  localfractionTmp_0d_0 = EngMGslLim_DWork.UnitDelay_DSTATE_g;

  /* Switch: '<S305>/Switch' incorporates:
   *  UnitDelay: '<S333>/Unit Delay'
   */
  if (!EngMGslLim_DWork.UnitDelay_DSTATE_of) {
    localfractionTmp_0d_0 = localSwitch2_h;
  }

  /* Sum: '<S300>/Subtract1' */
  localTrkTe = (localDataTypeConversion3_i - localSum3_h) +
    localfractionTmp_0d_0;

  /* UnitDelay: '<S332>/Unit Delay' */
  localTmpSignalConversionAtAfuA_ = EngMGslLim_DWork.UnitDelay_DSTATE_p;

  /* Switch: '<S304>/Switch' incorporates:
   *  Constant: '<S298>/Constant5'
   *  UnitDelay: '<S331>/Unit Delay'
   */
  if (!EngMGslLim_DWork.UnitDelay_DSTATE_bz) {
    localTmpSignalConversionAtAfuA_ = FALSE;
  }

  /* Logic: '<S298>/Logical Operator3' incorporates:
   *  Logic: '<S298>/Logical Operator1'
   *  RelationalOperator: '<S298>/Relational Operator1'
   */
  localLogicalOperator3_j = ((localRelationalOperator_d) ||
    ((localTmpSignalConversionAtAfuA_) && (localSwitch2_h !=
    localfractionTmp_0d_0)));

  /* Outputs for enable SubSystem: '<S300>/Subsystem1' */
  EngMGslLim_Subsystem1(localLogicalOperator3_j, localRelationalOperator_d,
                        localTrkTe, &EngMGslLim_B.Subsystem1_p);

  /* end of Outputs for SubSystem: '<S300>/Subsystem1' */

  /* Sum: '<S300>/Subtract2' */
  localfractionTmp_0d_0 = localSwitch2_h - EngMGslLim_B.Subsystem1_p.Switch;

  /* RelationalOperator: '<S311>/LowerRelop1' incorporates:
   *  Constant: '<S300>/Constant5'
   */
  localTmpSignalConversionAtAfuA_ = (localfractionTmp_0d_0 > 500.0F);

  /* Switch: '<S311>/Switch' incorporates:
   *  Constant: '<S300>/Constant6'
   *  RelationalOperator: '<S311>/UpperRelop'
   */
  if (localfractionTmp_0d_0 < 0.0F) {
    localfractionTmp_0d_0 = 0.0F;
  }

  /* Switch: '<S311>/Switch2' incorporates:
   *  Constant: '<S300>/Constant5'
   */
  if (localTmpSignalConversionAtAfuA_) {
    localfractionTmp_0d_0 = 500.0F;
  }

  /* DataTypeConversion: '<S325>/Conversion' incorporates:
   *  Constant: '<S303>/Constant5'
   */
  localSum3_h = 10000.0F;

  /* Switch: '<S327>/Switch2' incorporates:
   *  RelationalOperator: '<S327>/LowerRelop1'
   *  RelationalOperator: '<S327>/UpperRelop'
   *  Switch: '<S327>/Switch'
   */
  if (!(localfractionTmp_0d_0 > 10000.0F)) {
    localSum3_h = localfractionTmp_0d_0;
  }

  /* UnitDelay: '<S303>/Unit Delay' */
  localfractionTmp_0d = EngMGslLim_DWork.UnitDelay_DSTATE_o;

  /* Switch: '<S303>/Switch3' incorporates:
   *  Constant: '<S298>/Constant1'
   *  Logic: '<S303>/Logical Operator'
   *  Logic: '<S303>/Logical Operator1'
   *  Logic: '<S303>/Logical Operator2'
   *  Logic: '<S303>/Logical Operator3'
   *  Sum: '<S303>/Sum1'
   *  UnitDelay: '<S303>/Unit Delay1'
   */
  if ((localLogicalOperator3_j) && (!EngMGslLim_DWork.UnitDelay1_DSTATE)) {
    localfractionTmp_0d = localDataTypeConversion3_i + localSum3_h;
  }

  /* Sum: '<S303>/Sum3' */
  localfractionTmp_0d -= localDataTypeConversion3_i;

  /* Switch: '<S330>/Switch' incorporates:
   *  Constant: '<S303>/Constant1'
   *  RelationalOperator: '<S330>/UpperRelop'
   */
  if (localfractionTmp_0d < 0.0F) {
    localfractionTmp_0d_0 = 0.0F;
  } else {
    localfractionTmp_0d_0 = localfractionTmp_0d;
  }

  /* Switch: '<S330>/Switch2' incorporates:
   *  RelationalOperator: '<S330>/LowerRelop1'
   */
  if (localfractionTmp_0d > localSum3_h) {
    localSwitch2_f = localSum3_h;
  } else {
    localSwitch2_f = localfractionTmp_0d_0;
  }

  /* RelationalOperator: '<S303>/Relational Operator' incorporates:
   *  Constant: '<S303>/Constant1'
   */
  localRelationalOperator_p = (localfractionTmp_0d > 0.0F);

  /* Outputs for enable SubSystem: '<S298>/Subsystem' */
  EngMGslLim_Subsystem(localRelationalOperator_p, localMS1, localMS,
                       localDataTypeConversion3_i, localSwitch2_f,
                       &EngMGslLim_B.Subsystem_o, &EngMGslLim_DWork.Subsystem_o);

  /* end of Outputs for SubSystem: '<S298>/Subsystem' */

  /* Switch: '<S298>/Switch' */
  if (localRelationalOperator_p) {
    localfractionTmp_0d_0 = EngMGslLim_B.Subsystem_o.Yk;
  } else {
    localfractionTmp_0d_0 = localMS;
  }

  /* Update for UnitDelay: '<S313>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_e = localSwitch2_f;

  /* Update for UnitDelay: '<S312>/Unit Delay' incorporates:
   *  Constant: '<S308>/Constant3'
   */
  EngMGslLim_DWork.UnitDelay_DSTATE_a = TRUE;

  /* Update for UnitDelay: '<S334>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_g = localSwitch2_h;

  /* Update for UnitDelay: '<S333>/Unit Delay' incorporates:
   *  Constant: '<S305>/Constant3'
   */
  EngMGslLim_DWork.UnitDelay_DSTATE_of = TRUE;

  /* Update for UnitDelay: '<S332>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_p = localRelationalOperator_p;

  /* Update for UnitDelay: '<S331>/Unit Delay' incorporates:
   *  Constant: '<S304>/Constant3'
   */
  EngMGslLim_DWork.UnitDelay_DSTATE_bz = TRUE;

  /* Update for UnitDelay: '<S303>/Unit Delay1' */
  EngMGslLim_DWork.UnitDelay1_DSTATE = localLogicalOperator3_j;

  /* Update for UnitDelay: '<S303>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_o = localSwitch2_f;

  /* end of Outputs for SubSystem: '<S296>/MSW' */

  /* DataTypeConversion: '<S297>/OutDTConv' incorporates:
   *  Constant: '<S297>/offset'
   *  Constant: '<S297>/offset1'
   *  Constant: '<S297>/one_on_slope'
   *  Product: '<S297>/Product4'
   *  Sum: '<S297>/Add1'
   *  Sum: '<S297>/Add2'
   */
  localSwitch2_h = (16384.0F * localfractionTmp_0d_0) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtUsT_c = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtUsT_c = 0U;
    }
  } else {
    localTmpSignalConversionAtUsT_c = MAX_uint16_T;
  }

  /* Update for UnitDelay: '<S342>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_g1 = localTmpSignalConversionAtAfu_n;

  /* Update for UnitDelay: '<S341>/Unit Delay' incorporates:
   *  Constant: '<S336>/Constant3'
   */
  EngMGslLim_DWork.UnitDelay_DSTATE_i = TRUE;

  /* Update for UnitDelay: '<S344>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_m = localSwitch_il;

  /* Update for UnitDelay: '<S343>/Unit Delay' incorporates:
   *  Constant: '<S337>/Constant3'
   */
  EngMGslLim_DWork.UnitDelay_DSTATE_b = TRUE;

  /* end of Outputs for SubSystem: '<S93>/F01_Freeze' */

  /* SignalConversion: '<S295>/copy' */
  EngMTrb_rLdProtTPMFrz_IRV_MP = localTmpSignalConversionAtUsT_c;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S295>/autosar_testpoint1' */

  /* S-Function Block: <S295>/autosar_testpoint1 */

  /* Outputs for atomic SubSystem: '<S93>/F02_Coordination' incorporates:
   *  MinMax: '<S291>/MinMax1'
   *
   * Block requirements for '<S93>/F02_Coordination':
   *  1. SubSystem "F01_Coordination" !Trace_To : VEMS_R_11_01002_022.02 ;
   */

  /* DataTypeConversion: '<S291>/Conversion1' */
  localfractionTmp_0d_0 = ((Float32)localTmpSignalConversionAtUsT_c) *
    6.103515625E-005F;

  /* DataTypeConversion: '<S291>/Conversion2' */
  localfractionTmp_0d = ((Float32)EngMTrb_rLdMaxTAirLim) * 6.103515625E-005F;

  /* MinMax: '<S291>/MinMax4' */
  localSwitch2_h = rt_MINf(localfractionTmp_0d_0, EngMTrb_prm_rLdMaxRef[0]);
  localSwitch2_h = rt_MINf(localSwitch2_h, EngMTrb_rLdMaxBas);
  localSwitch2_h = rt_MINf(localSwitch2_h, localfractionTmp_0d);
  localfrac_1[0] = rt_MINf(localSwitch2_h, EngMTrb_rLdMaxTiInjMax);
  localfrac[0] = localSwitch2_h;
  localSwitch2_h = rt_MINf(localfractionTmp_0d_0, EngMTrb_prm_rLdMaxRef[1]);
  localSwitch2_h = rt_MINf(localSwitch2_h, EngMTrb_rLdMaxBas);
  localSwitch2_h = rt_MINf(localSwitch2_h, localfractionTmp_0d);
  localfrac_1[1] = rt_MINf(localSwitch2_h, EngMTrb_rLdMaxTiInjMax);
  localfrac[1] = localSwitch2_h;

  /* Lookup: '<S346>/Look-Up Table'
   * About '<S346>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_f), (&(EngMTrb_rLdRedMax_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdRedMax_A[0])),
                 7U);

  /* DataTypeDuplicate Block: '<S346>/Data Type Duplicate1'
   *
   * Regarding '<S346>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Switch: '<S291>/Switch2' incorporates:
   *  Constant: '<S291>/Cste_1'
   *  Lookup: '<S346>/Look-Up Table'
   */
  if (localNot_p) {
    localLookUpTable_h = localLookUpTable_f;
  } else {
    localLookUpTable_h = 16384U;
  }

  /* MinMax: '<S291>/MinMax' */
  localExt_nEng_EngMTrb_nEng_A__c = localExt_nEng_EngMTrb_nEngLdR_n;
  localEngMTrb_rEth_EngMTrb_rEt_p = (UInt32)(localLookUpTable_h << 2);
  if (localEngMTrb_rEth_EngMTrb_rEt_p < localExt_nEng_EngMTrb_nEngLdR_n) {
    localExt_nEng_EngMTrb_nEng_A__c = localEngMTrb_rEth_EngMTrb_rEt_p;
  }

  /* Product: '<S350>/Divide' */
  localDataTypeConversion1_o3 = (Float32)(((Float32d)localfrac_1[0]) *
    ACTEMS_LdexpF((Float32d)localExt_nEng_EngMTrb_nEng_A__c, -16));
  localDataTypeConversion3_l = rt_MINf(localDataTypeConversion1_o3,
    EngMTrb_rLdMaxLoRon);
  localfractionTmp_0d = rt_MINf(localDataTypeConversion3_l, ((Float32)
    EngMTrb_rLdProtTPM) * 6.103515625E-005F);

  /* DataStoreWrite: '<S291>/Data Store Write1' incorporates:
   *  Constant: '<S349>/offset'
   *  Constant: '<S349>/offset1'
   *  Constant: '<S349>/one_on_slope'
   *  DataTypeConversion: '<S349>/OutDTConv'
   *  Product: '<S349>/Product4'
   *  Sum: '<S349>/Add1'
   *  Sum: '<S349>/Add2'
   */
  localSwitch2_h = (16384.0F * localfractionTmp_0d) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtInThM = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtInThM = 0U;
    }
  } else {
    localTmpSignalConversionAtInThM = MAX_uint16_T;
  }

  EngMTrb_prm_rLdMaxProt_MP[0] = localTmpSignalConversionAtInThM;
  localfrac_0[0] = localfractionTmp_0d;
  localfrac[0] = localDataTypeConversion3_l;
  localfrac_1[0] = localDataTypeConversion1_o3;

  /* Product: '<S350>/Divide' */
  localDataTypeConversion1_o3 = (Float32)(((Float32d)localfrac_1[1]) *
    ACTEMS_LdexpF((Float32d)localExt_nEng_EngMTrb_nEng_A__c, -16));
  localDataTypeConversion3_l = rt_MINf(localDataTypeConversion1_o3,
    EngMTrb_rLdMaxLoRon);
  localfractionTmp_0d = rt_MINf(localDataTypeConversion3_l, ((Float32)
    EngMTrb_rLdProtTPM) * 6.103515625E-005F);

  /* DataStoreWrite: '<S291>/Data Store Write1' incorporates:
   *  Constant: '<S349>/offset'
   *  Constant: '<S349>/offset1'
   *  Constant: '<S349>/one_on_slope'
   *  DataTypeConversion: '<S349>/OutDTConv'
   *  Product: '<S349>/Product4'
   *  Sum: '<S349>/Add1'
   *  Sum: '<S349>/Add2'
   */
  localSwitch2_h = (16384.0F * localfractionTmp_0d) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtInThM = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtInThM = 0U;
    }
  } else {
    localTmpSignalConversionAtInThM = MAX_uint16_T;
  }

  EngMTrb_prm_rLdMaxProt_MP[1] = localTmpSignalConversionAtInThM;
  localfrac_0[1] = localfractionTmp_0d;
  localfrac[1] = localDataTypeConversion3_l;
  localfrac_1[1] = localDataTypeConversion1_o3;

  /* DataTypeConversion: '<S291>/Data Type Conversion3' */
  localExt_nEng_EngMTrb_nEng_A__c >>= 1;
  if (localExt_nEng_EngMTrb_nEng_A__c > 65535U) {
    localLookUpTable_h = MAX_uint16_T;
  } else {
    localLookUpTable_h = (UInt16)localExt_nEng_EngMTrb_nEng_A__c;
  }

  /* DataStoreWrite: '<S291>/Data Store Write3' */
  EngMTrb_facProt_MP = localLookUpTable_h;

  /* Lookup: '<S345>/Look-Up Table'
   * About '<S345>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_h), (&(EngMTrb_rLdLostSenKnk_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdLostSenKnk_A
    [0])), 7U);

  /* DataTypeDuplicate Block: '<S345>/Data Type Duplicate1'
   *
   * Regarding '<S345>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Lookup: '<S347>/Look-Up Table'
   * About '<S347>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_nk), (&(EngMTrb_rLdInhTrb_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdInhTrb_A[0])),
                 5U);

  /* DataTypeDuplicate Block: '<S347>/Data Type Duplicate1'
   *
   * Regarding '<S347>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Lookup: '<S348>/Look-Up Table'
   * About '<S348>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_n0), (&(EngMTrb_rLdLockVlv_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdLockVlv_A[0])),
                 7U);

  /* DataTypeDuplicate Block: '<S348>/Data Type Duplicate1'
   *
   * Regarding '<S348>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* MinMax: '<S291>/MinMax2' */
  localSwitch2_h = ((Float32)localLookUpTable_nk) * 6.103515625E-005F;
  localfrac_1[0] = rt_MINf(localSwitch2_h, localfrac_0[0]);
  localfrac[0] = localSwitch2_h;
  localSwitch2_h = ((Float32)localLookUpTable_nk) * 6.103515625E-005F;
  localfrac_1[1] = rt_MINf(localSwitch2_h, localfrac_0[1]);
  localfrac[1] = localSwitch2_h;

  /* Switch: '<S291>/Switch1' */
  if (!localNot_h) {
    localfrac_1[0] = localfrac_0[0];
    localfrac_1[1] = localfrac_0[1];
  }

  /* MinMax: '<S291>/MinMax3' */
  localSwitch2_h = ((Float32)localLookUpTable_h) * 6.103515625E-005F;
  localfrac_0[0] = rt_MINf(localSwitch2_h, localfrac_1[0]);
  localfrac[0] = localSwitch2_h;
  localSwitch2_h = ((Float32)localLookUpTable_h) * 6.103515625E-005F;
  localfrac_0[1] = rt_MINf(localSwitch2_h, localfrac_1[1]);
  localfrac[1] = localSwitch2_h;

  /* Switch: '<S291>/Switch3' */
  if (!localNot_g) {
    localfrac_0[0] = localfrac_1[0];
    localfrac_0[1] = localfrac_1[1];
  }

  /* MinMax: '<S291>/MinMax5' */
  localfrac[0] = ((Float32)localLookUpTable_n0) * 6.103515625E-005F;
  localfrac[1] = ((Float32)localLookUpTable_n0) * 6.103515625E-005F;

  /* Switch: '<S291>/Switch4' */
  if (localNot_p4) {
    EngMTrb_prm_rLdMaxCord[0] = rt_MINf(localfrac[0], localfrac_0[0]);
    EngMTrb_prm_rLdMaxCord[1] = rt_MINf(localfrac[1], localfrac_0[1]);
  } else {
    EngMTrb_prm_rLdMaxCord[0] = localfrac_0[0];
    EngMTrb_prm_rLdMaxCord[1] = localfrac_0[1];
  }

  /* end of Outputs for SubSystem: '<S93>/F02_Coordination' */

  /* Outputs for atomic SubSystem: '<S93>/F03_Rumble' *
   * Block requirements for '<S93>/F03_Rumble':
   *  1. SubSystem "F02_Rumble" !Trace_To : VEMS_R_11_01002_023.01 ;
   */

  /* Outputs for atomic SubSystem: '<S292>/F02_Rumble_Irv' incorporates:
   *  MinMax: '<S352>/MinMax5'
   *
   * Block requirements for '<S292>/F02_Rumble_Irv':
   *  1. SubSystem "F02_Rumble_Irv" !Trace_To : VEMS_R_11_01002_027.02 ;
   */

  /* Lookup: '<S377>/Look-Up Table'
   * About '<S377>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localMinMax1_g), (&(EngMTrb_rLdIrvLimRbl_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdIrvRbl_A[0])),
                 7U);

  /* DataTypeDuplicate Block: '<S377>/Data Type Duplicate1'
   *
   * Regarding '<S377>/Data Type Duplicate1':
   *   Unused code path elimination
   */
  localDataTypeConversion1_o3 = ((Float32)localMinMax1_g) * 6.103515625E-005F;
  localDataTypeConversion3_l = rt_MINf(localDataTypeConversion1_o3,
    EngMTrb_prm_rLdMaxCord[0]);

  /* DataStoreWrite: '<S352>/Data Store Write3' incorporates:
   *  Constant: '<S379>/offset'
   *  Constant: '<S379>/offset1'
   *  Constant: '<S379>/one_on_slope'
   *  DataTypeConversion: '<S379>/OutDTConv'
   *  Product: '<S379>/Product4'
   *  Sum: '<S379>/Add1'
   *  Sum: '<S379>/Add2'
   */
  localSwitch2_h = (16384.0F * localDataTypeConversion3_l) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtInThM = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtInThM = 0U;
    }
  } else {
    localTmpSignalConversionAtInThM = MAX_uint16_T;
  }

  EngMTrb_prm_rLdRblIrv_MP[0] = localTmpSignalConversionAtInThM;
  localfrac_1[0] = localDataTypeConversion3_l;
  localfrac[0] = localDataTypeConversion1_o3;
  localDataTypeConversion1_o3 = ((Float32)localMinMax1_g) * 6.103515625E-005F;
  localDataTypeConversion3_l = rt_MINf(localDataTypeConversion1_o3,
    EngMTrb_prm_rLdMaxCord[1]);

  /* DataStoreWrite: '<S352>/Data Store Write3' incorporates:
   *  Constant: '<S379>/offset'
   *  Constant: '<S379>/offset1'
   *  Constant: '<S379>/one_on_slope'
   *  DataTypeConversion: '<S379>/OutDTConv'
   *  Product: '<S379>/Product4'
   *  Sum: '<S379>/Add1'
   *  Sum: '<S379>/Add2'
   */
  localSwitch2_h = (16384.0F * localDataTypeConversion3_l) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtInThM = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtInThM = 0U;
    }
  } else {
    localTmpSignalConversionAtInThM = MAX_uint16_T;
  }

  EngMTrb_prm_rLdRblIrv_MP[1] = localTmpSignalConversionAtInThM;
  localfrac_1[1] = localDataTypeConversion3_l;
  localfrac[1] = localDataTypeConversion1_o3;

  /* Lookup: '<S376>/Look-Up Table'
   * About '<S376>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localMinMax1_g), (&(EngMTrb_facSlopIncRblIrv_T[0])),
                 localTmpSignalConversionAtExt_n,
                 (&(EngMTrb_nEngSlopIncRblIrv_A[0])), 7U);

  /* DataTypeDuplicate Block: '<S376>/Data Type Duplicate1'
   *
   * Regarding '<S376>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S352>/Data Type Conversion2' incorporates:
   *  Constant: '<S352>/EngMTrb_tiSampleFast_SC'
   */
  localfractionTmp_0d_0 = ((Float32)EngMTrb_tiSampleFast_SC) *
    5.000000237E-004F;

  /* Product: '<S381>/Divide' */
  localfractionTmp_0d = (((Float32)localMinMax1_g) * 6.103515625E-005F) *
    localfractionTmp_0d_0;

  /* Sum: '<S352>/Sum' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxIrvRblPrev1Outport2'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxIrvRblPrev2Outport2'
   */
  localfrac[0] = (((Float32)
                   Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxIrvRbl_001_irv
                   ()) * 6.103515625E-005F) + localfractionTmp_0d;
  localfrac[1] = (((Float32)
                   Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxIrvRbl_002_irv
                   ()) * 6.103515625E-005F) + localfractionTmp_0d;

  /* UnitDelay: '<S388>/Unit Delay' */
  localUnitDelay_kd = EngMGslLim_DWork.UnitDelay_DSTATE_hn;

  /* UnitDelay: '<S395>/Unit Delay' */
  localSwitch_do = EngMGslLim_DWork.UnitDelay_DSTATE_ot;

  /* MinMax: '<S380>/MinMax1' incorporates:
   *  Constant: '<S352>/EngMTrb_tiDlyEndProtRblIrv_C'
   *  Constant: '<S380>/Constant1'
   */
  localMinMax1_g = EngMTrb_tiDlyEndProtRblIrv_C;

  /* Sum: '<S380>/Sum2' incorporates:
   *  Constant: '<S380>/Constant6'
   *  Product: '<S380>/Product'
   */
  localSum3_h = (((Float32)localMinMax1_g) * 5.493164063E-002F) + (10.0F *
    localfractionTmp_0d_0);

  /* UnitDelay: '<S387>/Unit Delay' */
  localfractionTmp_0d = EngMGslLim_DWork.UnitDelay_DSTATE;

  /* Switch: '<S393>/Switch' incorporates:
   *  Constant: '<S380>/Constant3'
   *  RelationalOperator: '<S393>/UpperRelop'
   */
  if (EngMGslLim_DWork.UnitDelay_DSTATE < 0.0F) {
    localfractionTmp_0d = 0.0F;
  }

  /* Switch: '<S393>/Switch2' incorporates:
   *  RelationalOperator: '<S393>/LowerRelop1'
   */
  if (!(EngMGslLim_DWork.UnitDelay_DSTATE > localSum3_h)) {
    localSum3_h = localfractionTmp_0d;
  }

  /* Switch: '<S380>/Switch1' incorporates:
   *  Constant: '<S380>/Constant4'
   *  Constant: '<S380>/Constant7'
   *  Logic: '<S380>/Logical Operator2'
   *  Logic: '<S389>/Logical Operator'
   *  Logic: '<S389>/Logical Operator1'
   *  Sum: '<S380>/Sum1'
   */
  if ((localUnitDelay_kd) || ((!localTmpSignalConversionAtKnk_i) &&
       (localSwitch_do))) {
    localfractionTmp_0d_0 = 0.0F;
  } else {
    localfractionTmp_0d_0 = (localfractionTmp_0d_0 + localSum3_h) +
      2.220446049E-016F;
  }

  /* RelationalOperator: '<S380>/Relational Operator2' */
  localTmpSignalConversionAtAfuA_ = (localfractionTmp_0d_0 >= (((Float32)
    localMinMax1_g) * 5.493164063E-002F));

  /* UnitDelay: '<S396>/Unit Delay' */
  localSwitch_do = EngMGslLim_DWork.UnitDelay_DSTATE_kcb;

  /* RelationalOperator: '<S380>/Relational Operator1' incorporates:
   *  Constant: '<S380>/Constant2'
   */
  localRelationalOperator1_m4 = (localMinMax1_g == 0);

  /* Switch: '<S380>/Switch' incorporates:
   *  Constant: '<S380>/Constant5'
   *  Logic: '<S380>/Logical Operator1'
   *  Logic: '<S390>/Logical Operator'
   *  Logic: '<S390>/Logical Operator1'
   */
  if (!localRelationalOperator1_m4) {
    localSwitch_do = ((localTmpSignalConversionAtAfuA_) && (!localSwitch_do));
  } else {
    localSwitch_do = TRUE;
  }

  /* UnitDelay: '<S394>/Unit Delay' */
  localUnitDelay_kd = EngMGslLim_DWork.UnitDelay_DSTATE_m2;

  /* CombinatorialLogic: '<S386>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localTmpSignalConversionAtKnk_i != 0);
    rowidx = (rowidx << 1) + (UInt32)(localSwitch_do != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_kd != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_i[0] = EngMGslLim_ConstP.pooled21[rowidx];
    localLogic_i[1] = EngMGslLim_ConstP.pooled21[rowidx + 8];
  }

  /* Switch: '<S352>/Switch1' */
  if (!localLogic_i[0]) {
    localfrac[0] = EngMTrb_prm_rLdMaxCord[0];
    localfrac[1] = EngMTrb_prm_rLdMaxCord[1];
  }

  /* Switch: '<S352>/Switch3' */
  if (!localTmpSignalConversionAtKnk_i) {
    localfrac_1[0] = localfrac[0];
    localfrac_1[1] = localfrac[1];
  }

  /* DataTypeConversion: '<S352>/Data Type Conversion1' incorporates:
   *  Constant: '<S352>/EngMTrb_rLdRblIrvMin_C'
   */
  localSum3_h = ((Float32)EngMTrb_rLdRblIrvMin_C) * 6.103515625E-005F;
  localSwitch2_h = localfrac_1[0];

  /* Switch: '<S384>/Switch' incorporates:
   *  RelationalOperator: '<S384>/UpperRelop'
   */
  if (localfrac_1[0] < localSum3_h) {
    localSwitch2_h = localSum3_h;
  }

  /* Switch: '<S384>/Switch2' incorporates:
   *  RelationalOperator: '<S384>/LowerRelop1'
   */
  if (localfrac_1[0] > EngMTrb_prm_rLdMaxCord[0]) {
    localSwitch2_h = EngMTrb_prm_rLdMaxCord[0];
  }

  localfrac_1[0] = localSwitch2_h;
  localSwitch2_h = localfrac_1[1];

  /* Switch: '<S384>/Switch' incorporates:
   *  RelationalOperator: '<S384>/UpperRelop'
   */
  if (localfrac_1[1] < localSum3_h) {
    localSwitch2_h = localSum3_h;
  }

  /* Switch: '<S384>/Switch2' incorporates:
   *  RelationalOperator: '<S384>/LowerRelop1'
   */
  if (localfrac_1[1] > EngMTrb_prm_rLdMaxCord[1]) {
    localSwitch2_h = EngMTrb_prm_rLdMaxCord[1];
  }

  localfrac_1[1] = localSwitch2_h;

  /* Update for UnitDelay: '<S388>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_hn = localRelationalOperator1_m4;

  /* Update for UnitDelay: '<S395>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_ot = localTmpSignalConversionAtKnk_i;

  /* Update for UnitDelay: '<S387>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE = localfractionTmp_0d_0;

  /* Update for UnitDelay: '<S396>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_kcb = localTmpSignalConversionAtAfuA_;

  /* Update for UnitDelay: '<S394>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_m2 = localLogic_i[0];

  /* end of Outputs for SubSystem: '<S292>/F02_Rumble_Irv' */

  /* Outputs for atomic SubSystem: '<S292>/F01_Rumble_Tmp' *
   * Block requirements for '<S292>/F01_Rumble_Tmp':
   *  1. SubSystem "F01_Rumble_Tmp" !Trace_To : VEMS_R_11_01002_024.02 ;
   */

  /* Outputs for atomic SubSystem: '<S351>/F01_rLdMax_Rumble_Tmp' *
   * Block requirements for '<S351>/F01_rLdMax_Rumble_Tmp':
   *  1. SubSystem "F01_rLdMax_Rumble_Tmp" !Trace_To : VEMS_R_11_01002_025.02 ;
   */

  /* MinMax: '<S353>/MinMax' */
  localTmpSignalConversionAtExt_s = (UInt8)rt_MAX
    (localTmpSignalConversionAtKnkMg[0], localTmpSignalConversionAtKnkMg[1]);
  localTmpSignalConversionAtExt_s = (UInt8)rt_MAX
    (localTmpSignalConversionAtExt_s, localTmpSignalConversionAtKnkMg[2]);
  localTmpSignalConversionAtExt_s = (UInt8)rt_MAX
    (localTmpSignalConversionAtExt_s, localTmpSignalConversionAtKnkMg[3]);
  localTmpSignalConversionAtExt_s = (UInt8)rt_MAX
    (localTmpSignalConversionAtExt_s, localTmpSignalConversionAtKnkMg[4]);
  localMinMax_b = (UInt8)rt_MAX(localTmpSignalConversionAtExt_s,
    localTmpSignalConversionAtKnkMg[5]);

  /* Lookup2D: '<S355>/Look-Up Table (2-D)'
   * About '<S355>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U8
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U8_U16( &(EngMTrb_rLdLimTmpRbl), (&(EngMTrb_rLdLimTmpRbl_M[0])),
                    localMinMax_b, (&(EngMTrb_ctInjCutOffPtlX_A[0])), 3U,
                    localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngLdTmpRblY_A
    [0])), 7U);

  /* DataTypeDuplicate Block: '<S355>/Data Type Duplicate2'
   *
   * Regarding '<S355>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* end of Outputs for SubSystem: '<S351>/F01_rLdMax_Rumble_Tmp' */

  /* Outputs for atomic SubSystem: '<S351>/F02_rLdReq' *
   * Block requirements for '<S351>/F02_rLdReq':
   *  1. SubSystem "F02_rLdReq" !Trace_To : VEMS_R_11_01002_026.02 ;
   */

  /* Lookup: '<S356>/Look-Up Table'
   * About '<S356>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localMinMax1_p), (&(EngMTrb_facSlopIncRbl_T[0])),
                 localTmpSignalConversionAtExt_n, (&(EngMTrb_nEngSlopIncRbl_A[0])),
                 7U);

  /* DataTypeDuplicate Block: '<S356>/Data Type Duplicate1'
   *
   * Regarding '<S356>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S354>/Data Type Conversion2' incorporates:
   *  Constant: '<S354>/EngMTrb_tiSampleFast_SC'
   */
  localfractionTmp_0d_0 = ((Float32)EngMTrb_tiSampleFast_SC) *
    5.000000237E-004F;

  /* Product: '<S360>/Divide' */
  localfractionTmp_0d = (((Float32)localMinMax1_p) * 6.103515625E-005F) *
    localfractionTmp_0d_0;

  /* Sum: '<S354>/Sum2' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxTot1PrevOutport2'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxTot2PrevOutport2'
   */
  localfrac_0[0] = (((Float32)
                     Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxTot_001_irv
                     ()) * 6.103515625E-005F) + localfractionTmp_0d;
  localfrac_0[1] = (((Float32)
                     Rte_IrvRead_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxTot_002_irv
                     ()) * 6.103515625E-005F) + localfractionTmp_0d;

  /* UnitDelay: '<S367>/Unit Delay' */
  localUnitDelay_d = EngMGslLim_DWork.UnitDelay_DSTATE_n4;

  /* UnitDelay: '<S374>/Unit Delay' */
  localSwitch_bt = EngMGslLim_DWork.UnitDelay_DSTATE_hl;

  /* MinMax: '<S359>/MinMax1' incorporates:
   *  Constant: '<S354>/EngMTrb_tiDlyEndProtRbl_C'
   *  Constant: '<S359>/Constant1'
   */
  localMinMax1_p = EngMTrb_tiDlyEndProtRbl_C;

  /* Sum: '<S359>/Sum2' incorporates:
   *  Constant: '<S359>/Constant6'
   *  Product: '<S359>/Product'
   */
  localSum3_h = (((Float32)localMinMax1_p) * 5.493164063E-002F) + (10.0F *
    localfractionTmp_0d_0);

  /* UnitDelay: '<S366>/Unit Delay' */
  localfractionTmp_0d = EngMGslLim_DWork.UnitDelay_DSTATE_h;

  /* Switch: '<S372>/Switch' incorporates:
   *  Constant: '<S359>/Constant3'
   *  RelationalOperator: '<S372>/UpperRelop'
   */
  if (EngMGslLim_DWork.UnitDelay_DSTATE_h < 0.0F) {
    localfractionTmp_0d = 0.0F;
  }

  /* Switch: '<S372>/Switch2' incorporates:
   *  RelationalOperator: '<S372>/LowerRelop1'
   */
  if (!(EngMGslLim_DWork.UnitDelay_DSTATE_h > localSum3_h)) {
    localSum3_h = localfractionTmp_0d;
  }

  /* Switch: '<S359>/Switch1' incorporates:
   *  Constant: '<S359>/Constant4'
   *  Constant: '<S359>/Constant7'
   *  Logic: '<S359>/Logical Operator2'
   *  Logic: '<S368>/Logical Operator'
   *  Logic: '<S368>/Logical Operator1'
   *  Sum: '<S359>/Sum1'
   */
  if ((localUnitDelay_d) || ((!localTmpSignalConversionAtKnk_h) &&
       (localSwitch_bt))) {
    localfractionTmp_0d_0 = 0.0F;
  } else {
    localfractionTmp_0d_0 = (localfractionTmp_0d_0 + localSum3_h) +
      2.220446049E-016F;
  }

  /* RelationalOperator: '<S359>/Relational Operator2' */
  localTmpSignalConversionAtAfuA_ = (localfractionTmp_0d_0 >= (((Float32)
    localMinMax1_p) * 5.493164063E-002F));

  /* UnitDelay: '<S375>/Unit Delay' */
  localSwitch_bt = EngMGslLim_DWork.UnitDelay_DSTATE_mc;

  /* RelationalOperator: '<S359>/Relational Operator1' incorporates:
   *  Constant: '<S359>/Constant2'
   */
  localRelationalOperator1_m4 = (localMinMax1_p == 0);

  /* Switch: '<S359>/Switch' incorporates:
   *  Constant: '<S359>/Constant5'
   *  Logic: '<S359>/Logical Operator1'
   *  Logic: '<S369>/Logical Operator'
   *  Logic: '<S369>/Logical Operator1'
   */
  if (!localRelationalOperator1_m4) {
    localSwitch_bt = ((localTmpSignalConversionAtAfuA_) && (!localSwitch_bt));
  } else {
    localSwitch_bt = TRUE;
  }

  /* UnitDelay: '<S373>/Unit Delay' */
  localUnitDelay_d = EngMGslLim_DWork.UnitDelay_DSTATE_hm;

  /* CombinatorialLogic: '<S365>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localTmpSignalConversionAtKnk_h != 0);
    rowidx = (rowidx << 1) + (UInt32)(localSwitch_bt != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_d != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_j[0] = EngMGslLim_ConstP.pooled21[rowidx];
    localLogic_j[1] = EngMGslLim_ConstP.pooled21[rowidx + 8];
  }

  /* Switch: '<S354>/Switch' */
  if (!localLogic_j[0]) {
    localfrac_0[0] = localfrac_1[0];
    localfrac_0[1] = localfrac_1[1];
  }

  /* MinMax: '<S354>/MinMax5' */

  /* DataStoreWrite: '<S354>/Data Store Write3' incorporates:
   *  Constant: '<S358>/offset'
   *  Constant: '<S358>/offset1'
   *  Constant: '<S358>/one_on_slope'
   *  DataTypeConversion: '<S358>/OutDTConv'
   *  Product: '<S358>/Product4'
   *  Sum: '<S358>/Add1'
   *  Sum: '<S358>/Add2'
   */
  localSwitch2_h = (16384.0F * localfrac_0[0]) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtInThM = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtInThM = 0U;
    }
  } else {
    localTmpSignalConversionAtInThM = MAX_uint16_T;
  }

  EngMTrb_prm_rLdRbl_MP[0] = localTmpSignalConversionAtInThM;
  localSwitch2_h = ((Float32)EngMTrb_rLdLimTmpRbl) * 6.103515625E-005F;
  localSwitch2_h = rt_MINf(localSwitch2_h, localfrac_1[0]);
  localfrac[0] = localSwitch2_h;

  /* DataStoreWrite: '<S354>/Data Store Write3' incorporates:
   *  Constant: '<S358>/offset'
   *  Constant: '<S358>/offset1'
   *  Constant: '<S358>/one_on_slope'
   *  DataTypeConversion: '<S358>/OutDTConv'
   *  Product: '<S358>/Product4'
   *  Sum: '<S358>/Add1'
   *  Sum: '<S358>/Add2'
   */
  localSwitch2_h = (16384.0F * localfrac_0[1]) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtInThM = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtInThM = 0U;
    }
  } else {
    localTmpSignalConversionAtInThM = MAX_uint16_T;
  }

  EngMTrb_prm_rLdRbl_MP[1] = localTmpSignalConversionAtInThM;
  localSwitch2_h = ((Float32)EngMTrb_rLdLimTmpRbl) * 6.103515625E-005F;
  localSwitch2_h = rt_MINf(localSwitch2_h, localfrac_1[1]);
  localfrac[1] = localSwitch2_h;

  /* Switch: '<S354>/Switch3' */
  if (!localTmpSignalConversionAtKnk_h) {
    localfrac[0] = localfrac_0[0];
    localfrac[1] = localfrac_0[1];
  }

  /* DataTypeConversion: '<S354>/Data Type Conversion1' incorporates:
   *  Constant: '<S354>/EngMTrb_rLdRblTmpMin_C'
   */
  localSum3_h = ((Float32)EngMTrb_rLdRblTmpMin_C) * 6.103515625E-005F;

  /* Update for UnitDelay: '<S367>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_n4 = localRelationalOperator1_m4;

  /* Update for UnitDelay: '<S374>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_hl = localTmpSignalConversionAtKnk_h;

  /* Update for UnitDelay: '<S366>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_h = localfractionTmp_0d_0;

  /* Update for UnitDelay: '<S375>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_mc = localTmpSignalConversionAtAfuA_;

  /* Update for UnitDelay: '<S373>/Unit Delay' */
  EngMGslLim_DWork.UnitDelay_DSTATE_hm = localLogic_j[0];

  /* end of Outputs for SubSystem: '<S351>/F02_rLdReq' */

  /* end of Outputs for SubSystem: '<S292>/F01_Rumble_Tmp' */

  /* end of Outputs for SubSystem: '<S93>/F03_Rumble' */
  localSwitch2_h = localfrac[0];

  /* Switch: '<S363>/Switch' incorporates:
   *  RelationalOperator: '<S363>/UpperRelop'
   */
  if (localfrac[0] < localSum3_h) {
    localSwitch2_h = localSum3_h;
  }

  /* DataTypeConversion: '<S293>/OutDTConv' incorporates:
   *  Constant: '<S293>/offset'
   *  Constant: '<S293>/offset1'
   *  Constant: '<S293>/one_on_slope'
   *  Product: '<S293>/Product4'
   *  RelationalOperator: '<S363>/LowerRelop1'
   *  Sum: '<S293>/Add1'
   *  Sum: '<S293>/Add2'
   *  Switch: '<S363>/Switch2'
   */
  if (localfrac[0] > localfrac_1[0]) {
    localSwitch2_h = localfrac_1[0];
  }

  localSwitch2_h = (16384.0F * localSwitch2_h) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      locallocalOutDTConv_h_idx = (UInt16)localSwitch2_h;
    } else {
      locallocalOutDTConv_h_idx = 0U;
    }
  } else {
    locallocalOutDTConv_h_idx = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S294>/OutDTConv' incorporates:
   *  Constant: '<S294>/offset'
   *  Constant: '<S294>/offset1'
   *  Constant: '<S294>/one_on_slope'
   *  Product: '<S294>/Product4'
   *  Sum: '<S294>/Add1'
   *  Sum: '<S294>/Add2'
   */
  localSwitch2_h = (16384.0F * localfrac_1[0]) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtInThM = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtInThM = 0U;
    }
  } else {
    localTmpSignalConversionAtInThM = MAX_uint16_T;
  }

  localSwitch2_h = localfrac[1];

  /* Switch: '<S363>/Switch' incorporates:
   *  RelationalOperator: '<S363>/UpperRelop'
   */
  if (localfrac[1] < localSum3_h) {
    localSwitch2_h = localSum3_h;
  }

  /* DataTypeConversion: '<S293>/OutDTConv' incorporates:
   *  Constant: '<S293>/offset'
   *  Constant: '<S293>/offset1'
   *  Constant: '<S293>/one_on_slope'
   *  Product: '<S293>/Product4'
   *  RelationalOperator: '<S363>/LowerRelop1'
   *  Sum: '<S293>/Add1'
   *  Sum: '<S293>/Add2'
   *  Switch: '<S363>/Switch2'
   */
  if (localfrac[1] > localfrac_1[1]) {
    localSwitch2_h = localfrac_1[1];
  }

  localSwitch2_h = (16384.0F * localSwitch2_h) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtEng_d = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtEng_d = 0U;
    }
  } else {
    localTmpSignalConversionAtEng_d = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S294>/OutDTConv' incorporates:
   *  Constant: '<S294>/offset'
   *  Constant: '<S294>/offset1'
   *  Constant: '<S294>/one_on_slope'
   *  Product: '<S294>/Product4'
   *  Sum: '<S294>/Add1'
   *  Sum: '<S294>/Add2'
   */
  localSwitch2_h = (16384.0F * localfrac_1[1]) + 0.5F;
  if (localSwitch2_h < 65536.0F) {
    if (localSwitch2_h >= 0.0F) {
      localTmpSignalConversionAtEngM_ = (UInt16)localSwitch2_h;
    } else {
      localTmpSignalConversionAtEngM_ = 0U;
    }
  } else {
    localTmpSignalConversionAtEngM_ = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S7>/F06_Limitations_Remplissage_Mx1' */

  /* SignalConversion: '<S98>/copy' */
  EngMTrb_prm_rLdMaxTot_002 = localTmpSignalConversionAtEng_d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S98>/autosar_testpoint1' */

  /* S-Function Block: <S98>/autosar_testpoint1 */

  /* SignalConversion: '<S99>/copy' */
  EngMTrb_prm_rLdMaxIrvRbl_002 = localTmpSignalConversionAtEngM_;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S99>/autosar_testpoint1' */

  /* S-Function Block: <S99>/autosar_testpoint1 */

  /* SignalConversion: '<S100>/copy' */
  EngMTrb_facProtKnk_IRV_MP = localExt_nEng_EngMTrb_nEngLdR_n;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S100>/autosar_testpoint1' */

  /* S-Function Block: <S100>/autosar_testpoint1 */

  /* SignalConversion: '<S101>/copy' */
  EngMTrb_prm_rLdMaxTot_001 = locallocalOutDTConv_h_idx;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S101>/autosar_testpoint1' */

  /* S-Function Block: <S101>/autosar_testpoint1 */

  /* SignalConversion: '<S102>/copy' */
  EngMTrb_prm_rLdMaxIrvRbl_001 = localTmpSignalConversionAtInThM;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S102>/autosar_testpoint1' */

  /* S-Function Block: <S102>/autosar_testpoint1 */

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S105>/Byp_Fonction_SC'
   *  Constant: '<S105>/Int_BypC'
   */
  if (ENGMGSLLIM_ACTIVE_BYP_C) {
    localRO1 = EngMTrb_bAcvProtKnk_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_bAcvProtKnkInport2' */
  Rte_Write_P_EngMTrb_bAcvProtKnk_EngMTrb_bAcvProtKnk(localRO1);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_facProtKnkInport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_EngMGslLim_003_TEV_EngMTrb_facProtKnk_irv
    (localExt_nEng_EngMTrb_nEngLdR_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxIrvRbl1Inport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxIrvRbl_001_irv
    (localTmpSignalConversionAtInThM);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxIrvRbl2Inport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxIrvRbl_002_irv
    (localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxTot1Inport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxTot_001_irv
    (locallocalOutDTConv_h_idx);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_prm_rLdMaxTot2Inport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_EngMGslLim_003_TEV_EngMTrb_prm_rLdMaxTot_002_irv
    (localTmpSignalConversionAtEng_d);

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S103>/Byp_Fonction_SC'
   *  Constant: '<S103>/Int_BypC'
   */
  if (ENGMGSLLIM_ACTIVE_BYP_C) {
    locallocalOutDTConv_h_idx = EngMTrb_rLdMax_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_rLdMaxInport2' */
  Rte_Write_P_EngMTrb_rLdMax_EngMTrb_rLdMax(locallocalOutDTConv_h_idx);

  /* Switch: '<S104>/Switch' incorporates:
   *  Constant: '<S104>/Byp_Fonction_SC'
   *  Constant: '<S104>/Int_BypC'
   */
  if (ENGMGSLLIM_ACTIVE_BYP_C) {
    locallocalOutDTConv_h_idx = EngMTrb_rLdMaxOvbAcv_B;
  } else {
    locallocalOutDTConv_h_idx = localTmpSignalConversionAtEng_d;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_rLdMaxOvbAcvInport2' */
  Rte_Write_P_EngMTrb_rLdMaxOvbAcv_EngMTrb_rLdMaxOvbAcv
    (locallocalOutDTConv_h_idx);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngMTrb_rLdProtTPMFrz_irvInport2' incorporates:
   *  SignalConversion: '<S93>/Signal Conversion12'
   */
  Rte_IrvWrite_RE_EngMGslLim_003_TEV_EngMTrb_rLdProtTPMFrz_irv
    (localTmpSignalConversionAtUsT_c);
}

/* Disable for exported function: RE_EngMGslLim_003_TEV */
void RE_EngMGslLim_003_TEV_Disable(void)
{
  /* Disable for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Disable for SubSystem: '<S1>/F02_Compute1'
   *
   * Block requirements for '<S1>/F02_Compute1':
   *  1. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_049.01 ;
   *  2. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_053.01 ;
   *  3. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_054.01 ;
   *  4. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_055.01 ;
   *  5. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_056.01 ;
   *  6. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_057.01 ;
   *  7. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_058.01 ;
   *  8. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_059.01 ;
   *  9. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_060.01 ;
   *  10. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_061.01 ;
   *  11. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_062.01 ;
   *  12. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_063.01 ;
   *  13. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_064.01 ;
   *  14. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_065.01 ;
   *  15. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_066.01 ;
   *  16. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_067.01 ;
   *  17. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_068.01 ;
   *  18. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_069.01 ;
   *  19. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_070.01 ;
   *  20. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_071.01 ;
   *  21. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_072.01 ;
   *  22. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_073.01 ;
   *  23. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_074.01 ;
   *  24. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_075.01 ;
   *  25. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_077.01 ;
   *  26. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_078.01 ;
   *  27. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_079.01 ;
   *  28. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_080.01 ;
   *  29. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_081.01 ;
   *  30. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_011.02 ;
   *  31. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_012.03 ;
   *  32. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_082.01 ;
   *  33. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_030.02 ;
   *  34. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_033.01 ;
   */
  EngMGslLim_F02_Compute1_Disable();
}

/* Start for exported function: RE_EngMGslLim_003_TEV */
void RE_EngMGslLim_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Compute1'
   *
   * Block requirements for '<S1>/F02_Compute1':
   *  1. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_049.01 ;
   *  2. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_053.01 ;
   *  3. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_054.01 ;
   *  4. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_055.01 ;
   *  5. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_056.01 ;
   *  6. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_057.01 ;
   *  7. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_058.01 ;
   *  8. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_059.01 ;
   *  9. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_060.01 ;
   *  10. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_061.01 ;
   *  11. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_062.01 ;
   *  12. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_063.01 ;
   *  13. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_064.01 ;
   *  14. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_065.01 ;
   *  15. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_066.01 ;
   *  16. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_067.01 ;
   *  17. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_068.01 ;
   *  18. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_069.01 ;
   *  19. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_070.01 ;
   *  20. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_071.01 ;
   *  21. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_072.01 ;
   *  22. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_073.01 ;
   *  23. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_074.01 ;
   *  24. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_075.01 ;
   *  25. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_077.01 ;
   *  26. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_078.01 ;
   *  27. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_079.01 ;
   *  28. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_080.01 ;
   *  29. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_081.01 ;
   *  30. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_011.02 ;
   *  31. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_012.03 ;
   *  32. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_082.01 ;
   *  33. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_030.02 ;
   *  34. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_033.01 ;
   */
  EngMGslLim_F02_Compute1_Start();
}

/* Output and update for exported function: RE_EngMGslLim_003_TEV */
void RE_EngMGslLim_003_TEV(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Compute1'
   *
   * Block requirements for '<S1>/F02_Compute1':
   *  1. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_049.01 ;
   *  2. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_053.01 ;
   *  3. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_054.01 ;
   *  4. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_055.01 ;
   *  5. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_056.01 ;
   *  6. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_057.01 ;
   *  7. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_058.01 ;
   *  8. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_059.01 ;
   *  9. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_060.01 ;
   *  10. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_061.01 ;
   *  11. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_062.01 ;
   *  12. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_063.01 ;
   *  13. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_064.01 ;
   *  14. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_065.01 ;
   *  15. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_066.01 ;
   *  16. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_067.01 ;
   *  17. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_068.01 ;
   *  18. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_069.01 ;
   *  19. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_070.01 ;
   *  20. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_071.01 ;
   *  21. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_072.01 ;
   *  22. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_073.01 ;
   *  23. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_074.01 ;
   *  24. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_075.01 ;
   *  25. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_077.01 ;
   *  26. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_078.01 ;
   *  27. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_079.01 ;
   *  28. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_080.01 ;
   *  29. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_081.01 ;
   *  30. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_011.02 ;
   *  31. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_012.03 ;
   *  32. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_082.01 ;
   *  33. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_030.02 ;
   *  34. SubSystem "F02_Compute1" !Trace_To : VEMS_R_11_01002_033.01 ;
   */
  EngMGslLim_F02_Compute1();
}

/* Model initialize function */
void Runnable_EngMGslLim_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  RE_EngMGslLim_003_TEV_Start();
}

#define EngMGslLim_STOP_SEC_CODE
#include "EngMGslLim_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
