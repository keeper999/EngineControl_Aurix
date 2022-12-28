/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuRailCtlMgr                                            */
/* !Description     : FuRailCtlMgr- RAIL PRESSURE CONTROL MANAGER             */
/*                                                                            */
/* !Module          : FuRailCtlMgr                                            */
/*                                                                            */
/* !File            : FuRailCtlMgr.c                                          */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : V02NT1004153 / 06                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Dec 19 10:34:55 2012                              */
/*   Model name       : FuRailCtlMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.333                                                 */
/*   Root subsystem   : /FuRailCtlMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/FuRailCtlMgr/5-SOFT-LIV/FuRa$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   19 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "FuRailCtlMgr.h"
#include "FuRailCtlMgr_private.h"

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
#define FURAILCTLMGR_START_SEC_VAR_UNSPECIFIED
#include "FuRailCtlMgr_MemMap.h"

/* Block signals (auto storage) */
BlockIO_FuRailCtlMgr FuRailCtlMgr_B;

/* Block states (auto storage) */
D_Work_FuRailCtlMgr FuRailCtlMgr_DWork;

#define FURAILCTLMGR_STOP_SEC_VAR_UNSPECIFIED
#include "FuRailCtlMgr_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define FURAILCTLMGR_START_SEC_CODE
#include "FuRailCtlMgr_MemMap.h"

void FuRailCtlMgr_ASYNC1(int controlPortIdx)
{
}

void FuRailCtlMgr_ASYNC2(int controlPortIdx)
{
}

void FuRailCtlMgr_ASYNC3(int controlPortIdx)
{
  FuRailCt_F05_FuRailCtlMgr_conti();
}

void FuRailCtlMgr_ASYNC5(int controlPortIdx)
{
  FuRailCtl_F01_FuRailCtlMgr_init();
}

/*
 * Output and update for atomic system:
 *    '<S17>/F01_F00_FuRailCtlMgr_init'
 *    '<S8>/F01_F00_FuRailCtlMgr_init'
 */
void FuRai_F01_F00_FuRailCtlMgr_init(Boolean rtu_FRM_bInhPfuCtl,
  rtB_F01_F00_FuRailCtlMgr_init_F *localB)
{
  /* SignalConversion: '<S18>/Signal Conversion' incorporates:
   *  Constant: '<S18>/ConstVal'
   */
  localB->SignalConversion = FALSE;

  /* SignalConversion: '<S18>/Signal Conversion1' */
  localB->SignalConversion1 = rtu_FRM_bInhPfuCtl;
}

/* Output and update for function-call system: '<S1>/F01_FuRailCtlMgr_init' */
void FuRailCtl_F01_FuRailCtlMgr_init(void)
{
  /* Outputs for enable SubSystem: '<S7>/F01_F00_FuRailCtlMgr_init' incorporates:
   *  Constant: '<S7>/ConstVal'
   *  Constant: '<S7>/FURAILCTLMGR_u8Inhib'
   *  EnablePort: '<S17>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (FURAILCTLMGR_u8Inhib != 90) {
    /* Outputs for atomic SubSystem: '<S17>/F01_F00_FuRailCtlMgr_init' */
    FuRai_F01_F00_FuRailCtlMgr_init(GDGAR_bGetFRM(FRM_FRM_INHPFUCTL),
      &FuRailCtlMgr_B.F01_F00_FuRailCtlMgr_init_k);

    /* end of Outputs for SubSystem: '<S17>/F01_F00_FuRailCtlMgr_init' */

    /* S-Function "vems_vidSET" Block: <S17>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bAcvPFuCtl,
                FuRailCtlMgr_B.F01_F00_FuRailCtlMgr_init_k.SignalConversion);

    /* S-Function "vems_vidSET" Block: <S17>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_bInhPFuCtl,
                FuRailCtlMgr_B.F01_F00_FuRailCtlMgr_init_k.SignalConversion1);
  }

  /* end of Outputs for SubSystem: '<S7>/F01_F00_FuRailCtlMgr_init' */
}

/*
 * Output and update for atomic system:
 *    '<S38>/F04_FirstSplEveRst'
 *    '<S11>/F04_FirstSplEveRst'
 */
void FuRailCtlMgr_F04_FirstSplEveRst(rtB_F04_FirstSplEveRst_FuRailCt *localB)
{
  /* Constant: '<S39>/ConstVal' */
  localB->ConstVal = FALSE;

  /* Constant: '<S39>/ConstVal_1' */
  localB->ConstVal_1 = FALSE;
}

/* Output and update for function-call system: '<S1>/F04_FirstSplEveRst_inhibition' */
void F_F04_FirstSplEveRst_inhibition(void)
{
  /* Outputs for enable SubSystem: '<S12>/F04_F00_FirstSplEveRst' incorporates:
   *  Constant: '<S12>/ConstVal'
   *  Constant: '<S12>/FURAILCTLMGR_u8Inhib'
   *  EnablePort: '<S38>/Enable'
   *  RelationalOperator: '<S12>/Relational Operator'
   */
  if (FURAILCTLMGR_u8Inhib != 90) {
    /* Outputs for atomic SubSystem: '<S38>/F04_FirstSplEveRst' */
    FuRailCtlMgr_F04_FirstSplEveRst(&FuRailCtlMgr_B.F04_FirstSplEveRst_p);

    /* end of Outputs for SubSystem: '<S38>/F04_FirstSplEveRst' */

    /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bAcvCmdContnsReq,
                FuRailCtlMgr_B.F04_FirstSplEveRst_p.ConstVal_1);

    /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_bEveFirstSpl,
                FuRailCtlMgr_B.F04_FirstSplEveRst_p.ConstVal);
  }

  /* end of Outputs for SubSystem: '<S12>/F04_F00_FirstSplEveRst' */
}

/* Start for exported function: PFuCtl_EveRTSt_FuRailCtlMgr */
void PFuCtl_EveRTSt_FuRailCtlMgr_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */

  /* Start for S-Function (fcncallgen): '<S15>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_FuRailCtlMgr_init'
   *  Start for SubSystem: '<S1>/F04_FirstSplEveRst_inhibition'
   *
   * Block requirements for '<S1>/F01_FuRailCtlMgr_init':
   *  1. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F04_FirstSplEveRst_inhibition':
   *  1. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
}

/* Output and update for exported function: PFuCtl_EveRTSt_FuRailCtlMgr */
void PFuCtl_EveRTSt_FuRailCtlMgr(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S15>/gen' incorporates:
   *  SubSystem: '<S1>/F04_FirstSplEveRst_inhibition'
   *
   * Block requirements for '<S1>/F04_FirstSplEveRst_inhibition':
   *  1. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  FuRailCtlMgr_ASYNC5(0);
  F_F04_FirstSplEveRst_inhibition();
}

/* Output and update for function-call system: '<S1>/F01_FuRailCtlMgr_init_inhibition' */
void F01_FuRailCtlMgr_init_inhibitio(void)
{
  /* Outputs for atomic SubSystem: '<S8>/F01_F00_FuRailCtlMgr_init' */
  FuRai_F01_F00_FuRailCtlMgr_init(GDGAR_bGetFRM(FRM_FRM_INHPFUCTL),
    &FuRailCtlMgr_B.F01_F00_FuRailCtlMgr_init_a);

  /* end of Outputs for SubSystem: '<S8>/F01_F00_FuRailCtlMgr_init' */

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET */
  VEMS_vidSET(PFuCtl_bAcvPFuCtl,
              FuRailCtlMgr_B.F01_F00_FuRailCtlMgr_init_a.SignalConversion);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET1 */
  VEMS_vidSET(PFuCtl_bInhPFuCtl,
              FuRailCtlMgr_B.F01_F00_FuRailCtlMgr_init_a.SignalConversion1);
}

/* Output and update for function-call system: '<S1>/F04_FirstSplEveRst' */
void FuRailCtlM_F04_FirstSplEveRst_k(void)
{
  /* Outputs for atomic SubSystem: '<S11>/F04_FirstSplEveRst' */
  FuRailCtlMgr_F04_FirstSplEveRst(&FuRailCtlMgr_B.F04_FirstSplEveRst_l);

  /* end of Outputs for SubSystem: '<S11>/F04_FirstSplEveRst' */

  /* S-Function "vems_vidSET" Block: <S11>/VEMS_vidSET */
  VEMS_vidSET(PFuCtl_bAcvCmdContnsReq,
              FuRailCtlMgr_B.F04_FirstSplEveRst_l.ConstVal_1);

  /* S-Function "vems_vidSET" Block: <S11>/VEMS_vidSET1 */
  VEMS_vidSET(PFuCtl_bEveFirstSpl, FuRailCtlMgr_B.F04_FirstSplEveRst_l.ConstVal);
}

/* Start for exported function: PFuCtl_EveRst_FuRailCtlMgr */
void PFuCtl_EveRst_FuRailCtlMgr_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc'
   */

  /* Start for S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_FuRailCtlMgr_init_inhibition'
   *  Start for SubSystem: '<S1>/F04_FirstSplEveRst'
   *
   * Block requirements for '<S1>/F01_FuRailCtlMgr_init_inhibition':
   *  1. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F04_FirstSplEveRst':
   *  1. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
}

/* Output and update for exported function: PFuCtl_EveRst_FuRailCtlMgr */
void PFuCtl_EveRst_FuRailCtlMgr(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc'
   */

  /* S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  SubSystem: '<S1>/F01_FuRailCtlMgr_init_inhibition'
   *  SubSystem: '<S1>/F04_FirstSplEveRst'
   *
   * Block requirements for '<S1>/F01_FuRailCtlMgr_init_inhibition':
   *  1. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F04_FirstSplEveRst':
   *  1. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  F01_FuRailCtlMgr_init_inhibitio();
  FuRailCtlM_F04_FirstSplEveRst_k();
}

/* Output and update for function-call system: '<S1>/F03_FirstSplEveAcv' */
void FuRailCtlMgr_F03_FirstSplEveAcv(void)
{
  /* Outputs for enable SubSystem: '<S10>/F03_F00_FirstSplEveAcv' incorporates:
   *  Constant: '<S10>/ConstVal'
   *  Constant: '<S10>/FURAILCTLMGR_u8Inhib'
   *  EnablePort: '<S36>/Enable'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  if (FURAILCTLMGR_u8Inhib != 90) {
    /* S-Function "vems_vidSET" Block: <S36>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bEveFirstSpl, TRUE);
  }

  /* end of Outputs for SubSystem: '<S10>/F03_F00_FirstSplEveAcv' */
}

/* Output and update for function-call system: '<S1>/F02_FuRailCtlMgr_clcn' */
void FuRailCtl_F02_FuRailCtlMgr_clcn(void)
{
  Float32 localExt_tCoMes_Ext_tCoMes_A_16;
  UInt32 localExt_tCoMes_Ext_tCoMes_A__b;
  Boolean localLogicalOperator;
  Float32 localfractionTmp_0d;
  Float32 localSwitch2;
  Float32 localInterpolationUsingPrelooku;
  SInt32 localtmp;
  UInt8 locallocalDTC;

  /* Outputs for enable SubSystem: '<S9>/F02_F00_FuRailCtlMgr_clcn' incorporates:
   *  Constant: '<S9>/ConstVal'
   *  Constant: '<S9>/FURAILCTLMGR_u8Inhib'
   *  EnablePort: '<S20>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (FURAILCTLMGR_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_tCoMes, FuRailCtlMgr_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bAcvInjModSst, FuRailCtlMgr_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_bAcvInjModSplst, FuRailCtlMgr_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, FuRailCtlMgr_B.VEMS_vidGET_j);

    /* Outputs for atomic SubSystem: '<S20>/F01_pFuRailThd' */

    /* DataTypeConversion: '<S21>/DTC14' */
    localtmp = FuRailCtlMgr_B.VEMS_vidGET5 + 40;
    if (localtmp <= 0) {
      locallocalDTC = 0U;
    } else if (localtmp > 255) {
      locallocalDTC = MAX_uint8_T;
    } else {
      locallocalDTC = (UInt8)localtmp;
    }

    /* PreLookup: '<S23>/Prelookup' */
    localExt_tCoMes_Ext_tCoMes_A__b = plook_u32u8f_binc(locallocalDTC,
      (&(Ext_tCoMes_A[0])), 15U, &localExt_tCoMes_Ext_tCoMes_A_16);

    /* If: '<S21>/If3' incorporates:
     *  ActionPort: '<S24>/Action Port'
     *  ActionPort: '<S25>/Action Port'
     *  SubSystem: '<S21>/F01_pFuRailThdSTT'
     *  SubSystem: '<S21>/F02_pFuRailThd'
     */
    if (FuRailCtlMgr_B.VEMS_vidGET_j) {
      /* Logic: '<S24>/Logical Operator' */
      localLogicalOperator = !FuRailCtlMgr_B.VEMS_vidGET7;

      /* Interpolation_n-D: '<S27>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A_16;
      localInterpolationUsingPrelooku = intrp1d_iu16p9ff_u32f_l_s
        (localExt_tCoMes_Ext_tCoMes_A__b, localfractionTmp_0d,
         (&(PFuCtl_pFuRailThdAcvCtlModHSTT_T[0])));

      /* Interpolation_n-D: '<S28>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A_16;
      localSwitch2 = intrp1d_iu16p9ff_u32f_l_s(localExt_tCoMes_Ext_tCoMes_A__b,
        localfractionTmp_0d, (&(PFuCtl_pFuRailThdAcvCtlModSSTT_T[0])));

      /* Interpolation_n-D: '<S29>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A_16;
      localfractionTmp_0d = intrp1d_iu16p9ff_u32f_l_s
        (localExt_tCoMes_Ext_tCoMes_A__b, localfractionTmp_0d,
         (&(PFuCtl_pFuRailThdAcvCtlSplSTT_T[0])));

      /* Switch: '<S24>/Switch2' */
      if (!FuRailCtlMgr_B.VEMS_vidGET8) {
        localSwitch2 = localInterpolationUsingPrelooku;
      }

      /* Switch: '<S24>/Switch3' */
      if (localLogicalOperator) {
        localfractionTmp_0d = localSwitch2;
      }
    } else {
      /* Logic: '<S25>/Logical Operator' */
      localLogicalOperator = !FuRailCtlMgr_B.VEMS_vidGET7;

      /* Interpolation_n-D: '<S30>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A_16;
      localInterpolationUsingPrelooku = intrp1d_iu16p9ff_u32f_l_s
        (localExt_tCoMes_Ext_tCoMes_A__b, localfractionTmp_0d,
         (&(PFuCtl_pFuRailThdAcvCtlModH_T[0])));

      /* Interpolation_n-D: '<S31>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A_16;
      localSwitch2 = intrp1d_iu16p9ff_u32f_l_s(localExt_tCoMes_Ext_tCoMes_A__b,
        localfractionTmp_0d, (&(PFuCtl_pFuRailThdAcvCtlModS_T[0])));

      /* Interpolation_n-D: '<S32>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A_16;
      localfractionTmp_0d = intrp1d_iu16p9ff_u32f_l_s
        (localExt_tCoMes_Ext_tCoMes_A__b, localfractionTmp_0d,
         (&(PFuCtl_pFuRailThdAcvCtlModSpl_T[0])));

      /* Switch: '<S25>/Switch2' */
      if (!FuRailCtlMgr_B.VEMS_vidGET8) {
        localSwitch2 = localInterpolationUsingPrelooku;
      }

      /* Switch: '<S25>/Switch3' */
      if (localLogicalOperator) {
        localfractionTmp_0d = localSwitch2;
      }
    }

    /* DataTypeConversion: '<S26>/OutDTConv' incorporates:
     *  Constant: '<S26>/offset'
     *  Constant: '<S26>/offset1'
     *  Constant: '<S26>/one_on_slope'
     *  Product: '<S26>/Product4'
     *  Sum: '<S26>/Add1'
     *  Sum: '<S26>/Add2'
     */
    localfractionTmp_0d = (1.279999968E-003F * localfractionTmp_0d) + 0.5F;
    if (localfractionTmp_0d < 65536.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        PFuCtl_pFuRailHiThdAcvClCtl = (UInt16)localfractionTmp_0d;
      } else {
        PFuCtl_pFuRailHiThdAcvClCtl = 0U;
      }
    } else {
      PFuCtl_pFuRailHiThdAcvClCtl = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S20>/F01_pFuRailThd' */
    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_pFuRailSplMes, FuRailCtlMgr_B.VEMS_vidGET4_i);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bAcvHPst, FuRailCtlMgr_B.VEMS_vidGET6_n);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_stEru, FuRailCtlMgr_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_bRun, FuRailCtlMgr_B.VEMS_vidGET2_f);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_bStoHPPmpActCmd, FuRailCtlMgr_B.VEMS_vidGET3_p);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET10 */
    VEMS_vidGET(Srv_bAcvUnloadRail, FuRailCtlMgr_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S20>/VEMS_vidGET9 */
    VEMS_vidGET(InjSys_bHPPmpCutOff, FuRailCtlMgr_B.VEMS_vidGET9);

    /* Outputs for atomic SubSystem: '<S20>/F02_pFuRailClCtl' */

    /* If: '<S33>/If' incorporates:
     *  ActionPort: '<S34>/Action Port'
     *  ActionPort: '<S35>/Action Port'
     *  Constant: '<S22>/PFuCtl_pFuRailLoThdInhClCtl_C'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  RelationalOperator: '<S33>/Relational Operator1'
     *  SubSystem: '<S33>/If Action Subsystem'
     *  SubSystem: '<S33>/If Action Subsystem1'
     */
    if (PFuCtl_pFuRailLoThdInhClCtl_C >= FuRailCtlMgr_B.VEMS_vidGET4_i) {
      /* Inport: '<S34>/Value 1' incorporates:
       *  Constant: '<S22>/ConstVal_1'
       */
      FuRailCtlMgr_B.Merge_m = FALSE;
    } else {
      if (FuRailCtlMgr_B.VEMS_vidGET4_i >= PFuCtl_pFuRailHiThdAcvClCtl) {
        /* Inport: '<S35>/Value 2' incorporates:
         *  Constant: '<S22>/ConstVal'
         */
        FuRailCtlMgr_B.Merge_m = TRUE;
      }
    }

    /* Logic: '<S22>/Logical Operator8' incorporates:
     *  Constant: '<S22>/PFuCtl_bAcvHPPmpCutOff_C'
     *  Inport: '<Root>/FRM_bInhPfuCtl'
     *  Logic: '<S22>/Logical Operator11'
     *  Logic: '<S22>/Logical Operator13'
     */
    FuRailCtlMgr_B.LogicalOperator8 = (((GDGAR_bGetFRM(FRM_FRM_INHPFUCTL) ||
      (!FuRailCtlMgr_B.VEMS_vidGET3_p)) || FuRailCtlMgr_B.VEMS_vidGET10) ||
      (FuRailCtlMgr_B.VEMS_vidGET9 && PFuCtl_bAcvHPPmpCutOff_C));

    /* Logic: '<S22>/Logical Operator9' incorporates:
     *  Constant: '<S22>/Ext_stRun_SC'
     *  Constant: '<S22>/PFuCtl_bAcvPFuCtlCrk_C'
     *  Logic: '<S22>/Logical Operator1'
     *  Logic: '<S22>/Logical Operator10'
     *  Logic: '<S22>/Logical Operator2'
     *  Logic: '<S22>/Logical Operator3'
     *  Logic: '<S22>/Logical Operator5'
     *  Logic: '<S22>/Logical Operator6'
     *  Logic: '<S22>/Logical Operator7'
     *  RelationalOperator: '<S22>/Relational Operator4'
     */
    FuRailCtlMgr_B.LogicalOperator9 = ((!FuRailCtlMgr_B.LogicalOperator8) &&
                                       ((((FuRailCtlMgr_B.Merge_m &&
      PFuCtl_bAcvPFuCtlCrk_C) || (FuRailCtlMgr_B.VEMS_vidGET1 == Ext_stRun_SC)) &&
      FuRailCtlMgr_B.VEMS_vidGET6_n) || ((!FuRailCtlMgr_B.VEMS_vidGET6_n) &&
      FuRailCtlMgr_B.VEMS_vidGET2_f)));

    /* end of Outputs for SubSystem: '<S20>/F02_pFuRailClCtl' */
    /* S-Function "vems_vidSET" Block: <S20>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bAcvPFuCtl, FuRailCtlMgr_B.LogicalOperator9);

    /* S-Function "vems_vidSET" Block: <S20>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_bInhPFuCtl, FuRailCtlMgr_B.LogicalOperator8);
  }

  /* end of Outputs for SubSystem: '<S9>/F02_F00_FuRailCtlMgr_clcn' */
}

/* Enable for function-call system: '<S1>/F05_FuRailCtlMgr_conti' */
void F_F05_FuRailCtlMgr_conti_Enable(SInt32 controlPortIdx)
{
  FuRailCtlMgr_DWork.F05_FuRailCtlMgr_conti_MODE[(controlPortIdx)] = TRUE;
}

/* Disable for function-call system: '<S1>/F05_FuRailCtlMgr_conti' */
void F05_FuRailCtlMgr_conti_Disable(SInt32 controlPortIdx)
{
  Boolean localenableState;
  localenableState = FALSE;
  FuRailCtlMgr_DWork.F05_FuRailCtlMgr_conti_MODE[(controlPortIdx)] = FALSE;
  if ((SInt32)FuRailCtlMgr_DWork.F05_FuRailCtlMgr_conti_MODE[0]) {
    localenableState = TRUE;
  }

  if ((SInt32)FuRailCtlMgr_DWork.F05_FuRailCtlMgr_conti_MODE[1]) {
    localenableState = TRUE;
  }

  if (!localenableState) {
    /* Disable for enable SubSystem: '<S13>/F05_F00_FuRailCtlMgr_conti' */

    /* Disable for If: '<S40>/If' */
    FuRailCtlMgr_DWork.If_ActiveSubsystem = -1;

    /* Disable for ifaction SubSystem: '<S40>/F01_Activation' */

    /* Disable for Outport: '<S41>/PFuCtl_bAcvCmdContnsReq' */
    FuRailCtlMgr_B.Merge = FALSE;

    /* end of Disable for SubSystem: '<S40>/F01_Activation' */
    FuRailCtlMgr_DWork.F05_F00_FuRailCtlMgr_conti_MODE = FALSE;

    /* end of Disable for SubSystem: '<S13>/F05_F00_FuRailCtlMgr_conti' */
  }
}

/* Start for function-call system: '<S1>/F05_FuRailCtlMgr_conti' */
void Fu_F05_FuRailCtlMgr_conti_Start(void)
{
  /* Start for enable SubSystem: '<S13>/F05_F00_FuRailCtlMgr_conti' */

  /* Start for If: '<S40>/If' */
  FuRailCtlMgr_DWork.If_ActiveSubsystem = -1;

  /* end of Start for SubSystem: '<S13>/F05_F00_FuRailCtlMgr_conti' */
}

/* Output and update for function-call system: '<S1>/F05_FuRailCtlMgr_conti' */
void FuRailCt_F05_FuRailCtlMgr_conti(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_m;
  Boolean localRelationalOperator1_o;
  Boolean localLogic[2];
  Boolean localUnitDelay1;
  SInt8 localrtPrevAction;
  SInt8 localrtAction;
  Boolean localLogicalOperator5_l;
  Boolean localSwitch2_l;

  /* Outputs for enable SubSystem: '<S13>/F05_F00_FuRailCtlMgr_conti' incorporates:
   *  Constant: '<S13>/ConstVal'
   *  Constant: '<S13>/FURAILCTLMGR_u8Inhib'
   *  EnablePort: '<S40>/Enable'
   *  RelationalOperator: '<S13>/Relational Operator'
   */
  if (FURAILCTLMGR_u8Inhib != 90) {
    if (!(((SInt32)FuRailCtlMgr_DWork.F05_F00_FuRailCtlMgr_conti_MODE) != 0)) {
      FuRailCtlMgr_DWork.F05_F00_FuRailCtlMgr_conti_MODE = TRUE;
    }

    /* S-Function "vems_vidGET" Block: <S40>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_pFuRailSplMes, FuRailCtlMgr_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S40>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_pFuReq, FuRailCtlMgr_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S40>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_bAcvHPst, FuRailCtlMgr_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S40>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_pFuThdAcvInjHPst, FuRailCtlMgr_B.VEMS_vidGET5_l);

    /* S-Function "vems_vidGET" Block: <S40>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_bStaCmdFctSt, FuRailCtlMgr_B.VEMS_vidGET1_g);

    /* S-Function "vems_vidGET" Block: <S40>/VEMS_vidGET */
    VEMS_vidGET(Dml_cmd_cranking, FuRailCtlMgr_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S40>/VEMS_vidGET6 */
    VEMS_vidGET(PFuCtl_bEveFirstSpl, FuRailCtlMgr_B.VEMS_vidGET6);

    /* If: '<S40>/If' incorporates:
     *  ActionPort: '<S41>/Action Port'
     *  ActionPort: '<S42>/Action Port'
     *  Logic: '<S40>/Logical Operator3'
     *  SubSystem: '<S40>/F01_Activation'
     *  SubSystem: '<S40>/F02_Deactivation'
     */
    localrtPrevAction = FuRailCtlMgr_DWork.If_ActiveSubsystem;
    if (!FuRailCtlMgr_B.VEMS_vidGET6) {
      localrtAction = 0;
    } else {
      localrtAction = 1;
    }

    FuRailCtlMgr_DWork.If_ActiveSubsystem = localrtAction;
    if ((localrtPrevAction != localrtAction) && (localrtPrevAction == 0)) {
      /* Disable for Outport: '<S41>/PFuCtl_bAcvCmdContnsReq' */
      FuRailCtlMgr_B.Merge = FALSE;
    }

    switch (localrtAction) {
     case 0:
      /* Logic: '<S41>/Logical Operator5' incorporates:
       *  Inport: '<Root>/FRM_bInhPfuCtl'
       */
      localLogicalOperator5_l = !GDGAR_bGetFRM(FRM_FRM_INHPFUCTL);

      /* RelationalOperator: '<S43>/Relational Operator' */
      localRelationalOperator_m = (FuRailCtlMgr_B.VEMS_vidGET5_l >=
        FuRailCtlMgr_B.VEMS_vidGET2);

      /* RelationalOperator: '<S43>/Relational Operator1' */
      localRelationalOperator1_o = (FuRailCtlMgr_B.VEMS_vidGET2 >=
        FuRailCtlMgr_B.VEMS_vidGET4);

      /* UnitDelay: '<S44>/UnitDelay' */
      localUnitDelay1 = FuRailCtlMgr_DWork.UnitDelay;

      /* CombinatorialLogic: '<S44>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_o != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = FuRailCtlMgr_ConstP.Logic_table[rowidx];
        localLogic[1] = FuRailCtlMgr_ConstP.Logic_table[rowidx + 8];
      }

      /* UnitDelay: '<S44>/UnitDelay1' */
      localUnitDelay1 = FuRailCtlMgr_DWork.UnitDelay_m;

      /* Switch: '<S44>/Switch2' incorporates:
       *  Constant: '<S44>/NotCLR3'
       */
      if (localUnitDelay1) {
        localSwitch2_l = localLogic[0];
      } else {
        localSwitch2_l = FALSE;
      }

      /* Logic: '<S41>/Logical Operator1' incorporates:
       *  Constant: '<S41>/PFuCtl_bAcvLPCmdContns_C'
       *  Logic: '<S41>/Logical Operator2'
       *  Logic: '<S41>/Logical Operator4'
       *  Logic: '<S41>/Logical Operator6'
       */
      FuRailCtlMgr_B.Merge = ((((localLogicalOperator5_l) && (localSwitch2_l)) &&
                               (FuRailCtlMgr_B.VEMS_vidGET3 ||
        PFuCtl_bAcvLPCmdContns_C)) && ((!FuRailCtlMgr_B.VEMS_vidGET1_g) &&
        FuRailCtlMgr_B.VEMS_vidGET));

      /* Update for UnitDelay: '<S44>/UnitDelay' */
      FuRailCtlMgr_DWork.UnitDelay = localSwitch2_l;

      /* Update for UnitDelay: '<S44>/UnitDelay1' incorporates:
       *  Constant: '<S44>/NotCLR2'
       */
      FuRailCtlMgr_DWork.UnitDelay_m = TRUE;
      break;

     case 1:
      /* Constant: '<S42>/ConstVal' */
      FuRailCtlMgr_B.Merge = FALSE;
      break;
    }

    /* S-Function "vems_vidSET" Block: <S40>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bAcvCmdContnsReq, FuRailCtlMgr_B.Merge);
  } else {
    if ((SInt32)FuRailCtlMgr_DWork.F05_F00_FuRailCtlMgr_conti_MODE) {
      /* Disable for If: '<S40>/If' */
      FuRailCtlMgr_DWork.If_ActiveSubsystem = -1;

      /* Disable for ifaction SubSystem: '<S40>/F01_Activation' */

      /* Disable for Outport: '<S41>/PFuCtl_bAcvCmdContnsReq' */
      FuRailCtlMgr_B.Merge = FALSE;

      /* end of Disable for SubSystem: '<S40>/F01_Activation' */
      FuRailCtlMgr_DWork.F05_F00_FuRailCtlMgr_conti_MODE = FALSE;
    }
  }

  /* end of Outputs for SubSystem: '<S13>/F05_F00_FuRailCtlMgr_conti' */
}

/* Enable for exported function: PFuCtl_EveSpl_FuRailCtlMgr */
void PFuCtl_EveSpl_FuRailCtlMgr_Enable(void)
{
  /* Enable for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Enable for SubSystem: '<S1>/demux_fc3'
   */

  /* Enable for S-Function (fcncallgen): '<S16>/gen' incorporates:
   *  Enable for SubSystem: '<S1>/F02_FuRailCtlMgr_clcn'
   *  Enable for SubSystem: '<S1>/F03_FirstSplEveAcv'
   *  Enable for SubSystem: '<S1>/F05_FuRailCtlMgr_conti'
   *
   * Block requirements for '<S1>/F02_FuRailCtlMgr_clcn':
   *  1. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F03_FirstSplEveAcv':
   *  1. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F05_FuRailCtlMgr_conti':
   *  1. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  F_F05_FuRailCtlMgr_conti_Enable(1);
}

/* Disable for exported function: PFuCtl_EveSpl_FuRailCtlMgr */
void PFuCtl_EveSpl_FuRailCtlMgr_Disable(void)
{
  /* Disable for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Disable for SubSystem: '<S1>/demux_fc3'
   */

  /* Disable for S-Function (fcncallgen): '<S16>/gen' incorporates:
   *  Disable for SubSystem: '<S1>/F02_FuRailCtlMgr_clcn'
   *  Disable for SubSystem: '<S1>/F03_FirstSplEveAcv'
   *  Disable for SubSystem: '<S1>/F05_FuRailCtlMgr_conti'
   *
   * Block requirements for '<S1>/F02_FuRailCtlMgr_clcn':
   *  1. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F03_FirstSplEveAcv':
   *  1. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F05_FuRailCtlMgr_conti':
   *  1. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  F05_FuRailCtlMgr_conti_Disable(1);
}

/* Start for exported function: PFuCtl_EveSpl_FuRailCtlMgr */
void PFuCtl_EveSpl_FuRailCtlMgr_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc3'
   */

  /* Start for S-Function (fcncallgen): '<S16>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F02_FuRailCtlMgr_clcn'
   *  Start for SubSystem: '<S1>/F03_FirstSplEveAcv'
   *
   * Block requirements for '<S1>/F02_FuRailCtlMgr_clcn':
   *  1. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F03_FirstSplEveAcv':
   *  1. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
}

/* Output and update for exported function: PFuCtl_EveSpl_FuRailCtlMgr */
void PFuCtl_EveSpl_FuRailCtlMgr(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc3'
   */

  /* S-Function (fcncallgen): '<S16>/gen' incorporates:
   *  SubSystem: '<S1>/F02_FuRailCtlMgr_clcn'
   *  SubSystem: '<S1>/F03_FirstSplEveAcv'
   *
   * Block requirements for '<S1>/F02_FuRailCtlMgr_clcn':
   *  1. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_006.01 ;
   *
   * Block requirements for '<S1>/F03_FirstSplEveAcv':
   *  1. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  FuRailCtlMgr_F03_FirstSplEveAcv();
  FuRailCtl_F02_FuRailCtlMgr_clcn();
  FuRailCtlMgr_ASYNC3(1);
}

/* Output and update for exported function: PFuCtl_EveStTR_FuRailCtlMgr */
void PFuCtl_EveStTR_FuRailCtlMgr(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' */
  FuRailCtlMgr_ASYNC5(1);
}

/* Enable for exported function: PFuCtl_SdlFast_FuRailCtlMgr */
void PFuCtl_SdlFast_FuRailCtlMgr_Enable(void)
{
  /* Enable for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Enable for SubSystem: '<S1>/F05_FuRailCtlMgr_conti'
   *
   * Block requirements for '<S1>/F05_FuRailCtlMgr_conti':
   *  1. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  F_F05_FuRailCtlMgr_conti_Enable(0);
}

/* Disable for exported function: PFuCtl_SdlFast_FuRailCtlMgr */
void PFuCtl_SdlFast_FuRailCtlMgr_Disable(void)
{
  /* Disable for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Disable for SubSystem: '<S1>/F05_FuRailCtlMgr_conti'
   *
   * Block requirements for '<S1>/F05_FuRailCtlMgr_conti':
   *  1. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  F05_FuRailCtlMgr_conti_Disable(0);
}

/* Start for exported function: PFuCtl_SdlFast_FuRailCtlMgr */
void PFuCtl_SdlFast_FuRailCtlMgr_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F05_FuRailCtlMgr_conti'
   *
   * Block requirements for '<S1>/F05_FuRailCtlMgr_conti':
   *  1. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_002.01 ;
   *  2. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_001.01 ;
   *  3. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_003.01 ;
   *  4. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_004.01 ;
   *  5. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_005.01 ;
   *  6. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_006.01 ;
   */
  Fu_F05_FuRailCtlMgr_conti_Start();
}

/* Output and update for exported function: PFuCtl_SdlFast_FuRailCtlMgr */
void PFuCtl_SdlFast_FuRailCtlMgr(void)
{
  /* S-Function (fcncallgen): '<S6>/expFcn' */
  FuRailCtlMgr_ASYNC3(0);
}

/* Model initialize function */
void FuRailCtlMgr_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  PFuCtl_EveRTSt_FuRailCtlMgr_Start();
  PFuCtl_EveRst_FuRailCtlMgr_Start();
  PFuCtl_EveSpl_FuRailCtlMgr_Start();
  PFuCtl_SdlFast_FuRailCtlMgr_Start();
}

#define FURAILCTLMGR_STOP_SEC_CODE
#include "FuRailCtlMgr_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
