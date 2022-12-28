/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : DmpVlv_H                                                */
/* !Description     : DmpVlv_H Software Component                             */
/*                                                                            */
/* !Module          : DmpVlv_H                                                */
/* !Description     : DmpVlv_H Software Component                             */
/*                                                                            */
/* !File            : DmpVlv_H.c                                              */
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
/*   Model name       : DmpVlv_H_AUTOSAR.mdl                                  */
/*   Root subsystem   : /DmpVlv_H                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M12-DmpVlvH/5-SO$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "DmpVlv_H.h"
#include "DmpVlv_H_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define DmpVlv_H_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "DmpVlv_H_MemMap.h"

/* Block signals (auto storage) */
BlockIO_DmpVlv_H DmpVlv_H_B;

/* Block states (auto storage) */
D_Work_DmpVlv_H DmpVlv_H_DWork;

#define DmpVlv_H_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "DmpVlv_H_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define DMPVLV_H_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define DMPVLV_H_VEMSRTLIBT_MINOR_VERSION_REQ 12
#define DMPVLV_H_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define DMPVLV_H_VEMSRTLIBT_VERSION_REQ (DMPVLV_H_VEMSRTLIBT_PATCH_VERSION_REQ + DMPVLV_H_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + DMPVLV_H_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if DMPVLV_H_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define DmpVlv_H_START_SEC_CODE
#include "DmpVlv_H_MemMap.h"

void DmpVlv_H_ASYNC1(int controlPortIdx)
{
}

/* Start for exported function: RE_DmpVlv_H_001_MSE */
void RE_DmpVlv_H_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_DmpVlvIni'
   *
   * Block requirements for '<S1>/F01_DmpVlvIni':
   *  1. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_003.01 ;
   *  2. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_002.01 ;
   *  3. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_001.01 ;
   *  4. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_021.01 ;
   *  5. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_024.01 ;
   *  6. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_025.01 ;
   *  7. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_026.01 ;
   *  8. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_027.01 ;
   *  9. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_028.01 ;
   *  10. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_029.01 ;
   *  11. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_030.01 ;
   *  12. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_031.01 ;
   *  13. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_032.01 ;
   *  14. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_033.01 ;
   *  15. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_034.01 ;
   *  16. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_035.01 ;
   *  17. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_036.01 ;
   *  18. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_037.01 ;
   *  19. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_038.02 ;
   *  20. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_039.01 ;
   *  21. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_040.01 ;
   *  22. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_041.01 ;
   *  23. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_044.01 ;
   *  24. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_045.03 ;
   */
}

/* Output and update for exported function: RE_DmpVlv_H_001_MSE */
void RE_DmpVlv_H_001_MSE(void)
{
  Boolean localSwitch_h;
  UInt16 localSwitch;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_DmpVlvIni'
   *
   * Block requirements for '<S1>/F01_DmpVlvIni':
   *  1. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_003.01 ;
   *  2. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_002.01 ;
   *  3. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_001.01 ;
   *  4. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_021.01 ;
   *  5. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_024.01 ;
   *  6. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_025.01 ;
   *  7. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_026.01 ;
   *  8. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_027.01 ;
   *  9. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_028.01 ;
   *  10. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_029.01 ;
   *  11. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_030.01 ;
   *  12. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_031.01 ;
   *  13. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_032.01 ;
   *  14. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_033.01 ;
   *  15. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_034.01 ;
   *  16. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_035.01 ;
   *  17. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_036.01 ;
   *  18. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_037.01 ;
   *  19. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_038.02 ;
   *  20. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_039.01 ;
   *  21. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_040.01 ;
   *  22. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_041.01 ;
   *  23. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_044.01 ;
   *  24. SubSystem "F01_DmpVlvIni" !Trace_To : VEMS_R_11_01090_045.03 ;
   */

  /* user code (Output function Body for TID3) */
  Runnable_DmpVlv_H_Init();

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S4>/ConstVal'
   *  Constant: '<S8>/Byp_Fonction_SC'
   *  Constant: '<S8>/Int_BypC'
   */
  if (DMPVLV_H_ACTIVE_BYP_C) {
    localSwitch_h = DmpVlv_bAcvDmpVlv_B;
  } else {
    localSwitch_h = FALSE;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtDmpVlv_bAcvDmpVlvInport2' */
  Rte_Write_P_DmpVlv_bAcvDmpVlv_DmpVlv_bAcvDmpVlv(localSwitch_h);

  /* SignalConversion: '<S7>/copy' incorporates:
   *  Constant: '<S4>/ConstVal_1'
   */
  DmpVlv_tiDmpVlvAcvTmr_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S7>/autosar_testpoint1' */

  /* S-Function Block: <S7>/autosar_testpoint1 */

  /* SignalConversion: '<S4>/TmpSignal ConversionAtDmpVlv_tiDmpVlvAcvTmr_irvInport2' incorporates:
   *  Constant: '<S4>/ConstVal_1'
   *  SignalConversion: '<S4>/SignalConversion'
   */
  Rte_IrvWrite_RE_DmpVlv_H_001_MSE_DmpVlv_tiDmpVlvAcvTmr_irv(0U);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S4>/ConstVal1'
   *  Constant: '<S6>/Byp_Fonction_SC'
   *  Constant: '<S6>/Int_BypC'
   */
  if (DMPVLV_H_ACTIVE_BYP_C) {
    localSwitch = DmpVlv_rAirLdLimSurgeReq_B;
  } else {
    localSwitch = 0U;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtDmpVlv_rAirLdLimSurgeReqInport2' */
  Rte_Write_P_DmpVlv_rAirLdLimSurgeReq_DmpVlv_rAirLdLimSurgeReq(localSwitch);
}

/* Start for exported function: RE_DmpVlv_H_002_TEV */
void RE_DmpVlv_H_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_DmpVlvCtl'
   *
   * Block requirements for '<S1>/F02_DmpVlvCtl':
   *  1. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_004.01 ;
   *  2. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_002.01 ;
   *  3. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_001.01 ;
   *  4. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_016.01 ;
   *  5. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_017.01 ;
   *  6. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_018.01 ;
   *  7. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_019.01 ;
   *  8. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_020.01 ;
   *  9. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_021.01 ;
   *  10. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_041.01 ;
   *  11. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_042.01 ;
   *  12. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_043.01 ;
   *  13. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_046.03 ;
   */
}

/* Output and update for exported function: RE_DmpVlv_H_002_TEV */
void RE_DmpVlv_H_002_TEV(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator1_p;
  Boolean localLogic[2];
  Boolean localUnitDelay;
  Boolean localRelationalOperator1_j;
  Boolean localLogic_i[2];
  Boolean localAutosarServer;
  Boolean localSwitch2_l;
  Boolean localUnitDelay_h;
  Boolean localSwitch2_o;
  Boolean localNot;
  Float32 localDTC2;
  Boolean localNot_g;
  UInt8 localTmpSignalConversionAtEng_s;
  Float32 localSwitch_dv;
  Float32 localDivide_b;
  Float32 localSaturation01_o;
  Float32 localSwitch_k;
  Float32 localSwitch_p;
  SInt32 localrtmax;
  UInt16 localTmpSignalConversionAtUsT_f;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt16 localTmpSignalConversionAtUsT_o;
  SInt16 localTmpSignalConversionAtTqLim;
  SInt16 locallocalOutDTConv_b;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_DmpVlvCtl'
   *
   * Block requirements for '<S1>/F02_DmpVlvCtl':
   *  1. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_004.01 ;
   *  2. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_002.01 ;
   *  3. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_001.01 ;
   *  4. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_016.01 ;
   *  5. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_017.01 ;
   *  6. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_018.01 ;
   *  7. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_019.01 ;
   *  8. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_020.01 ;
   *  9. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_021.01 ;
   *  10. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_041.01 ;
   *  11. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_042.01 ;
   *  12. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_043.01 ;
   *  13. SubSystem "F02_DmpVlvCtl" !Trace_To : VEMS_R_11_01090_046.03 ;
   */

  /* S-Function (sfun_autosar_clientop): '<S16>/AutosarServer' */
  Rte_Call_R_FRM_bInhDmpVlvCtl_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S16>/Not' */
  localNot = !localAutosarServer;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_mfAirThrReq'
   */
  Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq
    (&DmpVlv_H_B.TmpSignalConversionAtAirSys_prm);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_tUsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tUsCmpr'
   */
  Rte_Read_R_UsThrM_tUsCmpr_UsThrM_tUsCmpr(&localTmpSignalConversionAtUsT_f);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_pUsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsCmpr'
   */
  Rte_Read_R_UsThrM_pUsCmpr_UsThrM_pUsCmpr(&localTmpSignalConversionAtUsThr);

  /* DataTypeConversion: '<S5>/DTC2' */
  localDTC2 = ((Float32)localTmpSignalConversionAtUsThr) * 8.0F;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_pDsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsCmpr'
   */
  Rte_Read_R_UsThrM_pDsCmpr_UsThrM_pDsCmpr(&localTmpSignalConversionAtUsT_o);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtDmpVlv_tiDmpVlvAcvTmrPrevOutport2' */
  DmpVlv_tiDmpVlvAcvTmrPrev =
    Rte_IrvRead_RE_DmpVlv_H_002_TEV_DmpVlv_tiDmpVlvAcvTmr_irv();

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&DmpVlv_H_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtTqLimEM_tqIdcLimEMOutport2' incorporates:
   *  Inport: '<Root>/TqLimEM_tqIdcLimEM'
   */
  Rte_Read_R_TqLimEM_tqIdcLimEM_TqLimEM_tqIdcLimEM
    (&localTmpSignalConversionAtTqLim);

  /* S-Function (sfun_autosar_clientop): '<S15>/AutosarServer' */
  Rte_Call_R_FRM_bAcvUsThrCtlDft_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S15>/Not' */
  localNot_g = !localAutosarServer;

  /* If: '<S5>/If1' incorporates:
   *  ActionPort: '<S12>/Action Port'
   *  ActionPort: '<S13>/Action Port'
   *  Constant: '<S5>/DmpVlv_bAcvDftMod_C'
   *  SubSystem: '<S5>/F01_DmpVlvCtlDeac'
   *  SubSystem: '<S5>/F02_DmpVlvCtlTestDeac'
   *
   * Block requirements for '<S5>/F01_DmpVlvCtlDeac':
   *  1. SubSystem "F01_DmpVlvCtlDeac" !Trace_To : VEMS_R_11_01090_005.01 ;
   *
   * Block requirements for '<S5>/F02_DmpVlvCtlTestDeac':
   *  1. SubSystem "F02_DmpVlvCtlTestDeac" !Trace_To : VEMS_R_11_01090_006.01 ;
   */
  if (DmpVlv_bAcvDftMod_C || (localNot)) {
    /* Constant: '<S12>/ConstVal' */
    DmpVlv_H_B.Merge1 = 0U;

    /* Constant: '<S12>/ConstVal_1' */
    localNot = FALSE;
  } else {
    /* If: '<S13>/If' incorporates:
     *  ActionPort: '<S18>/Action Port'
     *  ActionPort: '<S19>/Action Port'
     *  Constant: '<S13>/Ext_stRun_SC'
     *  RelationalOperator: '<S13>/Relational Operator'
     *  SubSystem: '<S13>/F01_DmpVlvCtlEngRun'
     *  SubSystem: '<S13>/F02_DmpVlvCtlEngNotRun'
     *
     * Block requirements for '<S13>/F01_DmpVlvCtlEngRun':
     *  1. SubSystem "F01_DmpVlvCtlEngRun" !Trace_To : VEMS_R_11_01090_007.01 ;
     *
     * Block requirements for '<S13>/F02_DmpVlvCtlEngNotRun':
     *  1. SubSystem "F02_DmpVlvCtlEngNotRun" !Trace_To : VEMS_R_11_01090_014.01 ;
     */
    if (localTmpSignalConversionAtEng_s == Ext_stRun_SC) {
      /* Outputs for atomic SubSystem: '<S18>/F04_Filtrage_debit_consigne' *
       * Block requirements for '<S18>/F04_Filtrage_debit_consigne':
       *  1. SubSystem "F01_DmpVlvPrmClcn" !Trace_To : VEMS_R_11_01090_008.01 ;
       */

      /* Outputs for atomic SubSystem: '<S23>/F01_Filtre_anticipateur' *
       * Block requirements for '<S23>/F01_Filtre_anticipateur':
       *  1. SubSystem "F01_DmpVlvPrmClcn" !Trace_To : VEMS_R_11_01090_008.01 ;
       */

      /* DataTypeConversion: '<S52>/DTC7' */
      DmpVlv_mfAirThrReq = ((Float32)
                            DmpVlv_H_B.TmpSignalConversionAtAirSys_prm[0]) *
        1.525878906E-005F;

      /* UnitDelay: '<S75>/Unit Delay' */
      localSwitch_dv = DmpVlv_H_DWork.UnitDelay_DSTATE;

      /* Switch: '<S62>/Switch' incorporates:
       *  UnitDelay: '<S74>/Unit Delay'
       */
      if (!DmpVlv_H_DWork.UnitDelay_DSTATE_e) {
        localSwitch_dv = DmpVlv_mfAirThrReq;
      }

      /* Sum: '<S52>/Add' */
      localSwitch_dv = DmpVlv_mfAirThrReq - localSwitch_dv;

      /* RelationalOperator: '<S52>/Relational Operator1' incorporates:
       *  Constant: '<S52>/DmpVlv_mfAirThrReqThd_C'
       *  DataTypeConversion: '<S52>/DTC1'
       */
      localNot = (localSwitch_dv >= ((((Float32)DmpVlv_mfAirThrReqThd_C) *
        1.525878906E-005F) - 1.0F));

      /* Outputs for enable SubSystem: '<S57>/Reset du filtre' incorporates:
       *  EnablePort: '<S71>/Enable'
       */
      if (localNot) {
        /* DataTypeConversion: '<S71>/Data Type Conversion' incorporates:
         *  Constant: '<S52>/ConstVal'
         */
        DmpVlv_H_B.DataTypeConversion = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S57>/Reset du filtre' */

      /* DataTypeConversion: '<S52>/DTC2' incorporates:
       *  Constant: '<S52>/DmpVlv_facFilMfAirThrReq_C'
       */
      localDivide_b = ((Float32)DmpVlv_facFilMfAirThrReq_C) * 1.000000047E-003F;

      /* Saturate: '<S73>/Saturation [0-1]' */
      localSaturation01_o = rt_SATURATE(localDivide_b, 0.0F, 1.0F);

      /* UnitDelay: '<S72>/UnitDelay' */
      localDivide_b = DmpVlv_H_DWork.UnitDelay_p;

      /* Switch: '<S72>/Switch' incorporates:
       *  Constant: '<S52>/ConstVal'
       *  UnitDelay: '<S72>/UnitDelay1'
       */
      if (!DmpVlv_H_DWork.UnitDelay_d) {
        localDivide_b = 0.0F;
      }

      /* Switch: '<S57>/Switch' incorporates:
       *  Product: '<S73>/Product'
       *  Sum: '<S73>/Sum'
       *  Sum: '<S73>/Sum1'
       */
      if (localNot) {
        localSaturation01_o = DmpVlv_H_B.DataTypeConversion;
      } else {
        localSaturation01_o = ((localSwitch_dv - localDivide_b) *
          localSaturation01_o) + localDivide_b;
      }

      /* Switch: '<S70>/Switch' incorporates:
       *  Constant: '<S52>/ConstVal'
       *  UnitDelay: '<S70>/UnitDelay'
       */
      if (DmpVlv_H_DWork.UnitDelay_DSTATE_d) {
        localSwitch_k = localSaturation01_o;
      } else {
        localSwitch_k = 0.0F;
      }

      /* Sum: '<S59>/Add2' incorporates:
       *  Constant: '<S59>/offset'
       *  Constant: '<S59>/offset1'
       *  Constant: '<S59>/one_on_slope'
       *  Product: '<S59>/Product4'
       *  Sum: '<S59>/Add1'
       */
      localDivide_b = (65536.0F * localSwitch_k) + 0.5F;

      /* DataTypeConversion: '<S59>/OutDTConv' */
      if (localDivide_b < 65536.0F) {
        if (localDivide_b >= 0.0F) {
          DmpVlv_mfDeltaAirReqFil_MP = (UInt16)localDivide_b;
        } else {
          DmpVlv_mfDeltaAirReqFil_MP = 0U;
        }
      } else {
        DmpVlv_mfDeltaAirReqFil_MP = MAX_uint16_T;
      }

      /* Product: '<S64>/Divide' incorporates:
       *  Constant: '<S52>/DmpVlv_facFilMfAirThrReq1_C'
       *  Constant: '<S52>/DmpVlv_facFilMfAirThrReq2_C'
       *  DataTypeConversion: '<S52>/DTC3'
       *  DataTypeConversion: '<S52>/DTC4'
       *  Lookup_n-D: '<S56>/Lookup Table (n-D)'
       *  Product: '<S63>/Divide'
       *  Product: '<S66>/Divide'
       *  Sum: '<S52>/Add1'
       *  UnitDelay: '<S60>/Unit Delay'
       */
      localDivide_b = (((((Float32)DmpVlv_facFilMfAirThrReq1_C) *
                         9.999999776E-003F) * localSwitch_k) + ((((Float32)
        DmpVlv_facFilMfAirThrReq2_C) * 9.999999776E-003F) *
        DmpVlv_H_DWork.UnitDelay_DSTATE_i)) * look2_iu16u16lftu16n5If_binlcns
        (DmpVlv_H_B.TmpSignalConversionAtExt_nEngOu, DmpVlv_mfDeltaAirReqFil_MP,
         (&(DmpVlv_nEng_A[0])), (&(DmpVlv_mfDeltaAirReqFil_A[0])),
         (&(DmpVlv_facFilMv_M[0])), &DmpVlv_H_ConstP.LookupTablenD_maxInde[0],
         8U);

      /* DataStoreWrite: '<S52>/MemoryStore3' incorporates:
       *  Constant: '<S58>/offset'
       *  Constant: '<S58>/offset1'
       *  Constant: '<S58>/one_on_slope'
       *  DataTypeConversion: '<S58>/OutDTConv'
       *  Product: '<S58>/Product4'
       *  Sum: '<S58>/Add1'
       *  Sum: '<S58>/Add2'
       */
      localSwitch_dv = (65536.0F * localDivide_b) + 0.5F;
      if (localSwitch_dv < 65536.0F) {
        if (localSwitch_dv >= 0.0F) {
          DmpVlv_mfAirThrReqOfs_MP = (UInt16)localSwitch_dv;
        } else {
          DmpVlv_mfAirThrReqOfs_MP = 0U;
        }
      } else {
        DmpVlv_mfAirThrReqOfs_MP = MAX_uint16_T;
      }

      /* Sum: '<S52>/Add2' */
      DmpVlv_mfAirThrReqAnt = DmpVlv_mfAirThrReq + localDivide_b;

      /* Product: '<S65>/Divide' incorporates:
       *  Constant: '<S52>/DmpVlv_facGainSat_C'
       *  DataTypeConversion: '<S52>/DTC5'
       */
      localDivide_b = (((Float32)DmpVlv_facGainSat_C) * 1.000000047E-003F) *
        DmpVlv_mfAirThrReq;

      /* DataTypeConversion: '<S52>/DTC6' incorporates:
       *  Constant: '<S52>/DmpVlv_mfAirThrSatMin_C'
       */
      localSwitch_dv = ((Float32)DmpVlv_mfAirThrSatMin_C) * 1.525878906E-005F;

      /* Switch: '<S69>/Switch' incorporates:
       *  RelationalOperator: '<S69>/UpperRelop'
       */
      if (!(DmpVlv_mfAirThrReqAnt < localSwitch_dv)) {
        localSwitch_dv = DmpVlv_mfAirThrReqAnt;
      }

      /* Switch: '<S69>/Switch2' incorporates:
       *  RelationalOperator: '<S69>/LowerRelop1'
       */
      if (DmpVlv_mfAirThrReqAnt > localDivide_b) {
        DmpVlv_mfAirThrReqAntSat = localDivide_b;
      } else {
        DmpVlv_mfAirThrReqAntSat = localSwitch_dv;
      }

      /* Update for UnitDelay: '<S75>/Unit Delay' */
      DmpVlv_H_DWork.UnitDelay_DSTATE = DmpVlv_mfAirThrReq;

      /* Update for UnitDelay: '<S74>/Unit Delay' incorporates:
       *  Constant: '<S62>/Constant3'
       */
      DmpVlv_H_DWork.UnitDelay_DSTATE_e = TRUE;

      /* Update for UnitDelay: '<S72>/UnitDelay' */
      DmpVlv_H_DWork.UnitDelay_p = localSaturation01_o;

      /* Update for UnitDelay: '<S72>/UnitDelay1' incorporates:
       *  Constant: '<S72>/Constant3'
       */
      DmpVlv_H_DWork.UnitDelay_d = TRUE;

      /* Update for UnitDelay: '<S70>/UnitDelay' incorporates:
       *  Constant: '<S70>/Constant3'
       */
      DmpVlv_H_DWork.UnitDelay_DSTATE_d = TRUE;

      /* Update for UnitDelay: '<S60>/Unit Delay' */
      DmpVlv_H_DWork.UnitDelay_DSTATE_i = localSwitch_k;

      /* end of Outputs for SubSystem: '<S23>/F01_Filtre_anticipateur' */

      /* Outputs for atomic SubSystem: '<S23>/F02_Detection_lacher_de_pied' *
       * Block requirements for '<S23>/F02_Detection_lacher_de_pied':
       *  1. SubSystem "F01_DmpVlvPrmClcn" !Trace_To : VEMS_R_11_01090_008.01 ;
       */

      /* Product: '<S80>/Product4' incorporates:
       *  Constant: '<S80>/offset'
       *  Constant: '<S80>/one_on_slope'
       *  Lookup_n-D: '<S76>/Lookup Table (n-D)'
       *  Sum: '<S80>/Add1'
       */
      localSwitch_dv = 16.0F * look1_iu16lfts16n4If_binlcns
        (DmpVlv_H_B.TmpSignalConversionAtExt_nEngOu, (&(DmpVlv_nEng_A[0])),
         (&(DmpVlv_tqLoThd_T[0])), 7U);

      /* Switch: '<S80>/Switch1' incorporates:
       *  Constant: '<S80>/offset2'
       *  Constant: '<S80>/offset3'
       *  Constant: '<S80>/offset4'
       *  RelationalOperator: '<S80>/Relational Operator'
       *  Sum: '<S80>/Add3'
       *  Sum: '<S80>/Add4'
       */
      if (localSwitch_dv >= 0.0F) {
        localSwitch_dv += 0.5F;
      } else {
        localSwitch_dv -= 0.5F;
      }

      /* DataTypeConversion: '<S80>/OutDTConv' */
      if (localSwitch_dv < 32768.0F) {
        if (localSwitch_dv >= -32768.0F) {
          locallocalOutDTConv_b = (SInt16)localSwitch_dv;
        } else {
          locallocalOutDTConv_b = MIN_int16_T;
        }
      } else {
        locallocalOutDTConv_b = MAX_int16_T;
      }

      /* DataTypeConversion: '<S53>/DTC1' incorporates:
       *  Constant: '<S53>/DmpVlv_facFilRateUpDown_C'
       */
      localSwitch_dv = ((Float32)DmpVlv_facFilRateUpDown_C) * 1.000000047E-003F;

      /* DataTypeConversion: '<S53>/DTC2' incorporates:
       *  Constant: '<S53>/DmpVlv_facFilRateDownUp_C'
       */
      localDivide_b = ((Float32)DmpVlv_facFilRateDownUp_C) * 1.000000047E-003F;

      /* Saturate: '<S84>/Saturation [0-1]' */
      localSwitch_k = rt_SATURATE(localDivide_b, 0.0F, 1.0F);

      /* RelationalOperator: '<S79>/Relational Operator1' */
      localRelationalOperator1_p = (locallocalOutDTConv_b >=
        localTmpSignalConversionAtTqLim);

      /* RelationalOperator: '<S79>/Relational Operator' incorporates:
       *  Constant: '<S53>/DmpVlv_tqOfsHiThd_C'
       *  Sum: '<S53>/Add'
       */
      localUnitDelay_h = (localTmpSignalConversionAtTqLim >=
                          (DmpVlv_tqOfsHiThd_C + locallocalOutDTConv_b));

      /* UnitDelay: '<S89>/UnitDelay' */
      localSwitch2_l = DmpVlv_H_DWork.UnitDelay_g;

      /* CombinatorialLogic: '<S89>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_p != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_h != 0);
        rowidx = (rowidx << 1) + (UInt32)(localSwitch2_l != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = DmpVlv_H_ConstP.pooled9[rowidx];
        localLogic[1] = DmpVlv_H_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S89>/UnitDelay1' */
      localSwitch2_l = DmpVlv_H_DWork.UnitDelay_c;

      /* Switch: '<S89>/Switch2' incorporates:
       *  Constant: '<S89>/NotCLR3'
       */
      if (localSwitch2_l) {
        DmpVlv_bDetTqThd = localLogic[0];
      } else {
        DmpVlv_bDetTqThd = FALSE;
      }

      /* Switch: '<S53>/Switch2' incorporates:
       *  Constant: '<S53>/DmpVlv_bAcvCdnTq_C'
       *  Constant: '<S53>/DmpVlv_bSelCdnTq_C'
       */
      if (DmpVlv_bSelCdnTq_C) {
        localSwitch2_l = DmpVlv_bDetTqThd;
      } else {
        localSwitch2_l = DmpVlv_bAcvCdnTq_C;
      }

      /* Switch: '<S53>/Switch1' incorporates:
       *  Constant: '<S53>/ConstVal_1'
       *  Constant: '<S53>/ConstVal_2'
       */
      if (localSwitch2_l) {
        localDivide_b = 1.0F;
      } else {
        localDivide_b = 0.0F;
      }

      /* UnitDelay: '<S83>/UnitDelay' */
      localSwitch_p = DmpVlv_H_DWork.UnitDelay;

      /* UnitDelay: '<S83>/UnitDelay1' */
      localUnitDelay_h = DmpVlv_H_DWork.UnitDelay_k;

      /* Switch: '<S83>/Switch' */
      if (!localUnitDelay_h) {
        localSwitch_p = localDivide_b;
      }

      /* Sum: '<S84>/Sum1' incorporates:
       *  Product: '<S84>/Product'
       *  Sum: '<S84>/Sum'
       */
      localSwitch_k = ((localDivide_b - localSwitch_p) * localSwitch_k) +
        localSwitch_p;

      /* UnitDelay: '<S81>/UnitDelay' */
      localUnitDelay_h = DmpVlv_H_DWork.UnitDelay_DSTATE_m;

      /* Switch: '<S81>/Switch' */
      if (localUnitDelay_h) {
        localSwitch_p = localSwitch_k;
      } else {
        localSwitch_p = localDivide_b;
      }

      /* Saturate: '<S88>/Saturation [0-1]' */
      localSaturation01_o = rt_SATURATE(localSwitch_dv, 0.0F, 1.0F);

      /* UnitDelay: '<S87>/UnitDelay' */
      localSwitch_dv = DmpVlv_H_DWork.UnitDelay_j;

      /* UnitDelay: '<S87>/UnitDelay1' */
      localUnitDelay_h = DmpVlv_H_DWork.UnitDelay_p2;

      /* Switch: '<S87>/Switch' */
      if (!localUnitDelay_h) {
        localSwitch_dv = localDivide_b;
      }

      /* Sum: '<S88>/Sum1' incorporates:
       *  Product: '<S88>/Product'
       *  Sum: '<S88>/Sum'
       */
      localSwitch_dv += (localDivide_b - localSwitch_dv) * localSaturation01_o;

      /* UnitDelay: '<S85>/UnitDelay' */
      localUnitDelay_h = DmpVlv_H_DWork.UnitDelay_DSTATE_h;

      /* Switch: '<S85>/Switch' */
      if (localUnitDelay_h) {
        localDivide_b = localSwitch_dv;
      }

      /* Switch: '<S53>/Switch3' */
      if (localSwitch2_l) {
        DmpVlv_facFilRate = localDivide_b;
      } else {
        DmpVlv_facFilRate = localSwitch_p;
      }

      /* Update for UnitDelay: '<S89>/UnitDelay' */
      DmpVlv_H_DWork.UnitDelay_g = DmpVlv_bDetTqThd;

      /* Update for UnitDelay: '<S89>/UnitDelay1' incorporates:
       *  Constant: '<S89>/NotCLR2'
       */
      DmpVlv_H_DWork.UnitDelay_c = TRUE;

      /* Update for UnitDelay: '<S83>/UnitDelay' */
      DmpVlv_H_DWork.UnitDelay = localSwitch_k;

      /* Update for UnitDelay: '<S83>/UnitDelay1' incorporates:
       *  Constant: '<S83>/Constant3'
       */
      DmpVlv_H_DWork.UnitDelay_k = TRUE;

      /* Update for UnitDelay: '<S81>/UnitDelay' incorporates:
       *  Constant: '<S81>/Constant3'
       */
      DmpVlv_H_DWork.UnitDelay_DSTATE_m = TRUE;

      /* Update for UnitDelay: '<S87>/UnitDelay' */
      DmpVlv_H_DWork.UnitDelay_j = localSwitch_dv;

      /* Update for UnitDelay: '<S87>/UnitDelay1' incorporates:
       *  Constant: '<S87>/Constant3'
       */
      DmpVlv_H_DWork.UnitDelay_p2 = TRUE;

      /* Update for UnitDelay: '<S85>/UnitDelay' incorporates:
       *  Constant: '<S85>/Constant3'
       */
      DmpVlv_H_DWork.UnitDelay_DSTATE_h = TRUE;

      /* end of Outputs for SubSystem: '<S23>/F02_Detection_lacher_de_pied' */

      /* Outputs for atomic SubSystem: '<S23>/F03_Application_TqLimEM_tqIdcLimEM du_filtre' *
       * Block requirements for '<S23>/F03_Application_TqLimEM_tqIdcLimEM du_filtre':
       *  1. SubSystem "F01_DmpVlvPrmClcn" !Trace_To : VEMS_R_11_01090_008.01 ;
       */

      /* Switch: '<S94>/Switch' incorporates:
       *  Constant: '<S90>/Constant1'
       *  RelationalOperator: '<S94>/UpperRelop'
       */
      if (DmpVlv_facFilRate < 0.0F) {
        localSaturation01_o = 0.0F;
      } else {
        localSaturation01_o = DmpVlv_facFilRate;
      }

      /* Switch: '<S94>/Switch2' incorporates:
       *  Constant: '<S90>/Constant'
       *  RelationalOperator: '<S94>/LowerRelop1'
       */
      if (DmpVlv_facFilRate > 1.0F) {
        localSaturation01_o = 1.0F;
      }

      /* Sum: '<S90>/Sum2' incorporates:
       *  Product: '<S90>/Divide'
       *  Sum: '<S90>/Sum3'
       */
      DmpVlv_mfAirThrReqFil = ((DmpVlv_mfAirThrReqAntSat - DmpVlv_mfAirThrReq) *
        localSaturation01_o) + DmpVlv_mfAirThrReq;

      /* end of Outputs for SubSystem: '<S23>/F03_Application_TqLimEM_tqIdcLimEM du_filtre' */

      /* end of Outputs for SubSystem: '<S18>/F04_Filtrage_debit_consigne' */

      /* Outputs for atomic SubSystem: '<S18>/F01_DmpVlvPrmClcn' *
       * Block requirements for '<S18>/F01_DmpVlvPrmClcn':
       *  1. SubSystem "F01_DmpVlvPrmClcn" !Trace_To : VEMS_R_11_01090_008.01 ;
       */

      /* DataTypeConversion: '<S25>/OutDTConv' incorporates:
       *  Constant: '<S20>/DmpVlv_tCmprRef_C'
       *  Constant: '<S25>/offset'
       *  Constant: '<S25>/offset1'
       *  Constant: '<S25>/one_on_slope'
       *  DataTypeConversion: '<S20>/SignalConversion1'
       *  DataTypeConversion: '<S5>/DTC3'
       *  Product: '<S25>/Product4'
       *  Product: '<S30>/Divide'
       *  Sum: '<S25>/Add1'
       *  Sum: '<S25>/Add2'
       */
      DmpVlv_rTCmprCor_MP = (UInt16)(((((((Float32)
        localTmpSignalConversionAtUsT_f) * 0.0078125F) + 223.0F) / ((((Float32)
        DmpVlv_tCmprRef_C) * 0.0078125F) + 223.0F)) * 8192.0F) + 0.5F);

      /* Lookup_n-D: '<S24>/Lookup Table (n-D)' */
      localSwitch_k = look1_iu16lfIf_binlcns__4(DmpVlv_rTCmprCor_MP,
        (&(DmpVlv_rTCmprCor_A[0])), (&(DmpVlv_rTCmprSqrt_T[0])), 15U);

      /* Product: '<S27>/Divide' incorporates:
       *  Constant: '<S20>/DmpVlv_pCmprRef_C'
       *  DataTypeConversion: '<S20>/DTC1'
       */
      localSwitch_dv = localDTC2 / (((Float32)DmpVlv_pCmprRef_C) * 8.0F);

      /* Outputs for atomic SubSystem: '<S27>/If Action Subsystem3' */

      /* Switch: '<S36>/Switch1' incorporates:
       *  Constant: '<S36>/Constant1'
       *  Constant: '<S36>/Constant2'
       *  Constant: '<S36>/Constant3'
       *  Logic: '<S36>/Logical Operator1'
       *  RelationalOperator: '<S36>/Relational Operator'
       *  RelationalOperator: '<S36>/Relational Operator1'
       *  RelationalOperator: '<S36>/Relational Operator3'
       */
      if (((localSwitch_dv != localSwitch_dv) || (localSwitch_dv >
            3.000000005E+038F)) || (-3.000000005E+038F > localSwitch_dv)) {
        localSwitch_dv = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S27>/If Action Subsystem3' */

      /* Product: '<S26>/Divide' incorporates:
       *  Product: '<S32>/Divide'
       */
      localSaturation01_o = (localSwitch_k * DmpVlv_mfAirThrReq) /
        localSwitch_dv;

      /* Outputs for atomic SubSystem: '<S26>/If Action Subsystem3' */

      /* Switch: '<S34>/Switch1' incorporates:
       *  Constant: '<S34>/Constant1'
       *  Constant: '<S34>/Constant2'
       *  Constant: '<S34>/Constant3'
       *  Logic: '<S34>/Logical Operator1'
       *  RelationalOperator: '<S34>/Relational Operator'
       *  RelationalOperator: '<S34>/Relational Operator1'
       *  RelationalOperator: '<S34>/Relational Operator3'
       */
      if (((localSaturation01_o != localSaturation01_o) || (localSaturation01_o >
            3.000000005E+038F)) || (-3.000000005E+038F > localSaturation01_o)) {
        DmpVlv_mfCmprCor = 0.0F;
      } else {
        DmpVlv_mfCmprCor = localSaturation01_o;
      }

      /* end of Outputs for SubSystem: '<S26>/If Action Subsystem3' */

      /* Product: '<S28>/Divide' incorporates:
       *  DataTypeConversion: '<S5>/DTC1'
       */
      localSaturation01_o = (((Float32)localTmpSignalConversionAtUsT_o) * 8.0F)
        / localDTC2;

      /* Outputs for atomic SubSystem: '<S28>/If Action Subsystem3' */

      /* Switch: '<S38>/Switch1' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       *  Constant: '<S38>/Constant3'
       *  Logic: '<S38>/Logical Operator1'
       *  RelationalOperator: '<S38>/Relational Operator'
       *  RelationalOperator: '<S38>/Relational Operator1'
       *  RelationalOperator: '<S38>/Relational Operator3'
       */
      if (((localSaturation01_o != localSaturation01_o) || (localSaturation01_o >
            3.000000005E+038F)) || (-3.000000005E+038F > localSaturation01_o)) {
        DmpVlv_rPresCmpr = 0.0F;
      } else {
        DmpVlv_rPresCmpr = localSaturation01_o;
      }

      /* end of Outputs for SubSystem: '<S28>/If Action Subsystem3' */

      /* Product: '<S29>/Divide' incorporates:
       *  Product: '<S31>/Divide'
       */
      localSaturation01_o = (localSwitch_k * DmpVlv_mfAirThrReqFil) /
        localSwitch_dv;

      /* Outputs for atomic SubSystem: '<S29>/If Action Subsystem3' */

      /* Switch: '<S40>/Switch1' incorporates:
       *  Constant: '<S40>/Constant1'
       *  Constant: '<S40>/Constant2'
       *  Constant: '<S40>/Constant3'
       *  Logic: '<S40>/Logical Operator1'
       *  RelationalOperator: '<S40>/Relational Operator'
       *  RelationalOperator: '<S40>/Relational Operator1'
       *  RelationalOperator: '<S40>/Relational Operator3'
       */
      if (((localSaturation01_o != localSaturation01_o) || (localSaturation01_o >
            3.000000005E+038F)) || (-3.000000005E+038F > localSaturation01_o)) {
        DmpVlv_mfCmprCorFil = 0.0F;
      } else {
        DmpVlv_mfCmprCorFil = localSaturation01_o;
      }

      /* end of Outputs for SubSystem: '<S29>/If Action Subsystem3' */

      /* end of Outputs for SubSystem: '<S18>/F01_DmpVlvPrmClcn' */

      /* Outputs for atomic SubSystem: '<S18>/F02_DmpVlvCmd' *
       * Block requirements for '<S18>/F02_DmpVlvCmd':
       *  1. SubSystem "F02_DmpVlvCmd" !Trace_To : VEMS_R_11_01090_009.01 ;
       */

      /* Outputs for atomic SubSystem: '<S21>/F01_Hysteresis' *
       * Block requirements for '<S21>/F01_Hysteresis':
       *  1. SubSystem "F01_Hysteresis" !Trace_To : VEMS_R_11_01090_010.01 ;
       */

      /* DataTypeConversion: '<S41>/DTC1' incorporates:
       *  Constant: '<S41>/DmpVlv_rPresCmprHysAnt_C'
       */
      localSaturation01_o = ((Float32)DmpVlv_rPresCmprHysAnt_C) *
        0.0001220703125F;

      /* Switch: '<S41>/Switch3' incorporates:
       *  Constant: '<S41>/DmpVlv_bSelMfCmprAnt_C'
       */
      if (DmpVlv_bSelMfCmprAnt_C) {
        localSwitch_k = DmpVlv_mfCmprCor;
      } else {
        localSwitch_k = DmpVlv_mfCmprCorFil;
      }

      /* Sum: '<S49>/Add2' incorporates:
       *  Constant: '<S49>/offset'
       *  Constant: '<S49>/offset1'
       *  Constant: '<S49>/one_on_slope'
       *  Product: '<S49>/Product4'
       *  Sum: '<S49>/Add1'
       */
      localSwitch_k = (65536.0F * localSwitch_k) + 0.5F;

      /* DataTypeConversion: '<S49>/OutDTConv' */
      if (localSwitch_k < 65536.0F) {
        if (localSwitch_k >= 0.0F) {
          localTmpSignalConversionAtUsT_f = (UInt16)localSwitch_k;
        } else {
          localTmpSignalConversionAtUsT_f = 0U;
        }
      } else {
        localTmpSignalConversionAtUsT_f = MAX_uint16_T;
      }

      /* Lookup_n-D: '<S44>/Lookup Table (n-D)' */
      localSwitch_k = look1_iu16lftu16n13If_binlcns__2
        (localTmpSignalConversionAtUsT_f, (&(DmpVlv_mfCmprCorAnt_A[0])),
         (&(DmpVlv_rPresCmprAnt_T[0])), 15U);

      /* Switch: '<S41>/Switch4' incorporates:
       *  Constant: '<S41>/DmpVlv_bSelMfCmpr_C'
       */
      if (DmpVlv_bSelMfCmpr_C) {
        localSwitch_dv = DmpVlv_mfCmprCor;
      } else {
        localSwitch_dv = DmpVlv_mfCmprCorFil;
      }

      /* Sum: '<S48>/Add2' incorporates:
       *  Constant: '<S48>/offset'
       *  Constant: '<S48>/offset1'
       *  Constant: '<S48>/one_on_slope'
       *  Product: '<S48>/Product4'
       *  Sum: '<S48>/Add1'
       */
      localSwitch_dv = (65536.0F * localSwitch_dv) + 0.5F;

      /* DataTypeConversion: '<S48>/OutDTConv' */
      if (localSwitch_dv < 65536.0F) {
        if (localSwitch_dv >= 0.0F) {
          localTmpSignalConversionAtUsT_f = (UInt16)localSwitch_dv;
        } else {
          localTmpSignalConversionAtUsT_f = 0U;
        }
      } else {
        localTmpSignalConversionAtUsT_f = MAX_uint16_T;
      }

      /* Lookup_n-D: '<S45>/Lookup Table (n-D)' */
      localSwitch_dv = look1_iu16lftu16n13If_binlcns__2
        (localTmpSignalConversionAtUsT_f, (&(DmpVlv_mfCmprCor_A[0])),
         (&(DmpVlv_rPresCmpr_T[0])), 15U);

      /* RelationalOperator: '<S46>/Relational Operator' incorporates:
       *  Constant: '<S41>/DmpVlv_rPresCmprHys_C'
       *  DataTypeConversion: '<S41>/DTC2'
       *  Sum: '<S41>/Sum1'
       */
      localUnitDelay = (DmpVlv_rPresCmpr >= ((((Float32)DmpVlv_rPresCmprHys_C) *
        0.0001220703125F) + localSwitch_dv));

      /* RelationalOperator: '<S46>/Relational Operator1' */
      localRelationalOperator1_j = (DmpVlv_rPresCmpr <= localSwitch_dv);

      /* UnitDelay: '<S50>/UnitDelay' */
      localSwitch2_o = DmpVlv_H_DWork.UnitDelay_o;

      /* CombinatorialLogic: '<S50>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_j != 0);
        rowidx = (rowidx << 1) + (UInt32)(localSwitch2_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_i[0] = DmpVlv_H_ConstP.pooled9[rowidx];
        localLogic_i[1] = DmpVlv_H_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S50>/UnitDelay1' */
      localSwitch2_o = DmpVlv_H_DWork.UnitDelay_kp;

      /* Switch: '<S50>/Switch2' incorporates:
       *  Constant: '<S50>/NotCLR3'
       */
      if (localSwitch2_o) {
        DmpVlv_bDetPmpAr_MP = localLogic_i[0];
      } else {
        DmpVlv_bDetPmpAr_MP = FALSE;
      }

      /* RelationalOperator: '<S47>/Relational Operator' incorporates:
       *  Sum: '<S41>/Sum2'
       */
      localSwitch2_o = (DmpVlv_rPresCmpr >= (localSaturation01_o + localSwitch_k));

      /* RelationalOperator: '<S47>/Relational Operator1' */
      localRelationalOperator1_j = (DmpVlv_rPresCmpr <= localSwitch_k);

      /* UnitDelay: '<S51>/UnitDelay' */
      localUnitDelay = DmpVlv_H_DWork.UnitDelay_gv;

      /* CombinatorialLogic: '<S51>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localSwitch2_o != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_j != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_i[0] = DmpVlv_H_ConstP.pooled9[rowidx];
        localLogic_i[1] = DmpVlv_H_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S51>/UnitDelay1' */
      localSwitch2_o = DmpVlv_H_DWork.UnitDelay_n;

      /* Switch: '<S51>/Switch2' incorporates:
       *  Constant: '<S51>/NotCLR3'
       */
      if (localSwitch2_o) {
        DmpVlv_bDetPmpArAnt_MP = localLogic_i[0];
      } else {
        DmpVlv_bDetPmpArAnt_MP = FALSE;
      }

      /* Switch: '<S41>/Switch2' incorporates:
       *  Constant: '<S41>/DmpVlv_bAcvDetPmp_C'
       *  Constant: '<S41>/DmpVlv_bSelDetPmp_C'
       */
      if (DmpVlv_bSelDetPmp_C) {
        localSwitch2_o = DmpVlv_bDetTqThd;
      } else {
        localSwitch2_o = DmpVlv_bAcvDetPmp_C;
      }

      /* Switch: '<S41>/Switch1' */
      if (localSwitch2_o) {
        DmpVlv_bDetPmpAr = DmpVlv_bDetPmpArAnt_MP;
      } else {
        DmpVlv_bDetPmpAr = DmpVlv_bDetPmpAr_MP;
      }

      /* Update for UnitDelay: '<S50>/UnitDelay' */
      DmpVlv_H_DWork.UnitDelay_o = DmpVlv_bDetPmpAr_MP;

      /* Update for UnitDelay: '<S50>/UnitDelay1' incorporates:
       *  Constant: '<S50>/NotCLR2'
       */
      DmpVlv_H_DWork.UnitDelay_kp = TRUE;

      /* Update for UnitDelay: '<S51>/UnitDelay' */
      DmpVlv_H_DWork.UnitDelay_gv = DmpVlv_bDetPmpArAnt_MP;

      /* Update for UnitDelay: '<S51>/UnitDelay1' incorporates:
       *  Constant: '<S51>/NotCLR2'
       */
      DmpVlv_H_DWork.UnitDelay_n = TRUE;

      /* end of Outputs for SubSystem: '<S21>/F01_Hysteresis' */

      /* Outputs for atomic SubSystem: '<S21>/F02_compteur' *
       * Block requirements for '<S21>/F02_compteur':
       *  1. SubSystem "F02_compteur" !Trace_To : VEMS_R_11_01090_011.01 ;
       */

      /* MinMax: '<S42>/MinMax' incorporates:
       *  Constant: '<S42>/ConstVal'
       *  Constant: '<S42>/DmpVlv_tiFastDly_SC'
       *  Sum: '<S42>/Sum2'
       */
      localrtmax = DmpVlv_tiDmpVlvAcvTmrPrev - DmpVlv_tiFastDly_SC;
      if (0 > localrtmax) {
        localrtmax = 0;
      }

      /* Switch: '<S42>/Switch1' incorporates:
       *  Constant: '<S42>/DmpVlv_tiDmpVlvTmrAnt_C'
       *  Constant: '<S42>/DmpVlv_tiDmpVlvTmr_C'
       */
      if (DmpVlv_bDetTqThd) {
        localTmpSignalConversionAtUsT_f = DmpVlv_tiDmpVlvTmrAnt_C;
      } else {
        localTmpSignalConversionAtUsT_f = DmpVlv_tiDmpVlvTmr_C;
      }

      /* Switch: '<S42>/Switch2' incorporates:
       *  DataTypeConversion: '<S42>/DTC3'
       */
      if (!DmpVlv_bDetPmpAr) {
        if (localrtmax <= 0) {
          localTmpSignalConversionAtUsT_f = 0U;
        } else {
          localTmpSignalConversionAtUsT_f = (UInt16)localrtmax;
        }
      }

      /* end of Outputs for SubSystem: '<S21>/F02_compteur' */

      /* Outputs for atomic SubSystem: '<S21>/F03_Activation' *
       * Block requirements for '<S21>/F03_Activation':
       *  1. SubSystem "F03_Activation" !Trace_To : VEMS_R_11_01090_012.01 ;
       */

      /* Logic: '<S43>/Logical Operator1' incorporates:
       *  Constant: '<S43>/ConstVal'
       *  RelationalOperator: '<S43>/Relational Operator1'
       */
      DmpVlv_bAcvDmpVlvRaw = (DmpVlv_bDetPmpAr ||
        (localTmpSignalConversionAtUsT_f > 0));

      /* end of Outputs for SubSystem: '<S21>/F03_Activation' */

      /* SignalConversion: '<S21>/Signal Conversion7' */
      DmpVlv_H_B.Merge1 = localTmpSignalConversionAtUsT_f;

      /* end of Outputs for SubSystem: '<S18>/F02_DmpVlvCmd' */

      /* Outputs for atomic SubSystem: '<S18>/F03_Arbitrage' *
       * Block requirements for '<S18>/F03_Arbitrage':
       *  1. SubSystem "F03_Arbitrage" !Trace_To : VEMS_R_11_01090_013.01 ;
       */

      /* Switch: '<S22>/Switch1' incorporates:
       *  Constant: '<S22>/DmpVlv_bDmpVlvDftMod_C'
       */
      if (localNot_g) {
        localNot = DmpVlv_bDmpVlvDftMod_C;
      } else {
        localNot = DmpVlv_bAcvDmpVlvRaw;
      }

      /* Switch: '<S22>/Switch2' incorporates:
       *  Constant: '<S22>/DmpVlv_bAcvDmpVlvTestMod_C'
       *  Constant: '<S22>/DmpVlv_bAcvTestMod_C'
       */
      if (DmpVlv_bAcvTestMod_C) {
        localNot = DmpVlv_bAcvDmpVlvTestMod_C;
      }

      /* end of Outputs for SubSystem: '<S18>/F03_Arbitrage' */
    } else {
      /* Constant: '<S19>/ConstVal' */
      localNot = FALSE;

      /* Constant: '<S19>/ConstVal_1' */
      DmpVlv_H_B.Merge1 = 0U;
    }
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S9>/autosar_testpoint1' */

  /* S-Function Block: <S9>/autosar_testpoint1 */
  DmpVlv_tiDmpVlvAcvTmr_IRV_MP = DmpVlv_H_B.Merge1;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngM_facMassFlowLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facMassFlowLdCor'
   */
  Rte_Read_R_EngM_facMassFlowLdCor_EngM_facMassFlowLdCor
    (&DmpVlv_H_B.TmpSignalConversionAtEngM_facMa);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtCoPt_tqIdcReqCord_nRegReqOutport2' incorporates:
   *  Inport: '<Root>/CoPt_tqIdcReqCord_nRegReq'
   */
  Rte_Read_R_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq
    (&DmpVlv_H_B.TmpSignalConversionAtCoPt_tqIdc);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_rMinIgEfcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rMinIgEfc'
   */
  Rte_Read_R_IgSys_rMinIgEfc_IgSys_rMinIgEfc
    (&DmpVlv_H_B.TmpSignalConversionAtIgSys_rMin);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_effAfrOutport2' incorporates:
   *  Inport: '<Root>/AirSys_effAfr'
   */
  Rte_Read_R_AirSys_effAfr_AirSys_effAfr
    (&DmpVlv_H_B.TmpSignalConversionAtAirSys_eff);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_rTarStatIgSpEffOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rTarStatIgSpEff'
   */
  Rte_Read_R_IgSys_rTarStatIgSpEff_IgSys_rTarStatIgSpEff
    (&DmpVlv_H_B.TmpSignalConversionAtIgSys_rTar);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_effCycOutport2' incorporates:
   *  Inport: '<Root>/AirSys_effCyc'
   */
  Rte_Read_R_AirSys_effCyc_AirSys_effCyc
    (&DmpVlv_H_B.TmpSignalConversionAtAirSys_e_k);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_effEGROutport2' incorporates:
   *  Inport: '<Root>/AirSys_effEGR'
   */
  Rte_Read_R_AirSys_effEGR_AirSys_effEGR
    (&DmpVlv_H_B.TmpSignalConversionAtAirSys_e_e);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngM_mAirEngCylMinOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirEngCylMin'
   */
  Rte_Read_R_EngM_mAirEngCylMin_EngM_mAirEngCylMin
    (&DmpVlv_H_B.TmpSignalConversionAtEngM_mAirE);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngM_mAirEngCylMaxOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirEngCylMax'
   */
  Rte_Read_R_EngM_mAirEngCylMax_EngM_mAirEngCylMax
    (&DmpVlv_H_B.TmpSignalConversionAtEngM_mAi_o);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtInjSys_noCylCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_noCylCutOff'
   */
  Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff
    (&DmpVlv_H_B.TmpSignalConversionAtInjSys_noC);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_noCylEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_noCylEng'
   */
  Rte_Read_R_Ext_noCylEng_Ext_noCylEng
    (&DmpVlv_H_B.TmpSignalConversionAtExt_noCylE);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_bActStraLimSurgeOutport2' incorporates:
   *  Inport: '<Root>/AirSys_bActStraLimSurge'
   */
  Rte_Read_R_AirSys_bActStraLimSurge_AirSys_bActStraLimSurge
    (&DmpVlv_H_B.TmpSignalConversionAtAirSys_bAc);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtInjSys_bTotCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bTotCutOff'
   */
  Rte_Read_R_InjSys_bTotCutOff_InjSys_bTotCutOff
    (&DmpVlv_H_B.TmpSignalConversionAtInjSys_bTo);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&DmpVlv_H_B.TmpSignalConversionAtUsThrM_pDs);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor
    (&DmpVlv_H_B.TmpSignalConversionAtUsThrM_pUs);

  /* S-Function (sfun_autosar_clientop): '<S17>/AutosarServer' */
  Rte_Call_R_FRM_bInhStraLimSurge_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S17>/Not' */
  DmpVlv_H_B.Not = !localAutosarServer;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Byp_Fonction_SC'
   *  Constant: '<S10>/Int_BypC'
   *  Constant: '<S14>/ConstVal'
   */
  if (DMPVLV_H_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_f = DmpVlv_rAirLdLimSurgeReq_B;
  } else {
    localTmpSignalConversionAtUsT_f = 0U;
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Byp_Fonction_SC'
   *  Constant: '<S11>/Int_BypC'
   */
  if (DMPVLV_H_ACTIVE_BYP_C) {
    localNot = DmpVlv_bAcvDmpVlv_B;
  }

  /* SignalConversion: '<S5>/SignalConversion' */
  localTmpSignalConversionAtUsThr = DmpVlv_H_B.Merge1;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtDmpVlv_bAcvDmpVlvInport2' */
  Rte_Write_P_DmpVlv_bAcvDmpVlv_DmpVlv_bAcvDmpVlv(localNot);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtDmpVlv_rAirLdLimSurgeReqInport2' */
  Rte_Write_P_DmpVlv_rAirLdLimSurgeReq_DmpVlv_rAirLdLimSurgeReq
    (localTmpSignalConversionAtUsT_f);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtDmpVlv_tiDmpVlvAcvTmr_irvInport2' */
  Rte_IrvWrite_RE_DmpVlv_H_002_TEV_DmpVlv_tiDmpVlvAcvTmr_irv
    (localTmpSignalConversionAtUsThr);
}

/* Model initialize function */
void Runnable_DmpVlv_H_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  RE_DmpVlv_H_001_MSE_Start();
  RE_DmpVlv_H_002_TEV_Start();
}

#define DmpVlv_H_STOP_SEC_CODE
#include "DmpVlv_H_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
