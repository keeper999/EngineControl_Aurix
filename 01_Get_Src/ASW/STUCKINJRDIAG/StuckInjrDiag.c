/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : StuckInjrDiag                                           */
/* !Description     : Diagnosis of stuck injectors                            */
/*                                                                            */
/* !Module          : StuckInjrDiag                                           */
/*                                                                            */
/* !File            : StuckInjrDiag.c                                         */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : PTS_DOC_5060559 / 03                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon Oct 21 15:46:24 2013                              */
/*   Model name       : StuckInjrDiag_AUTOCODE.mdl                            */
/*   Model version    : 1.228                                                 */
/*   Root subsystem   : /StuckInjrDiag                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/STUCKINJRDIAG/StuckInjrDiag.c$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   28 Oct 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "StuckInjrDiag.h"
#include "StuckInjrDiag_private.h"

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
#define STUCKINJRDIAG_START_SEC_VAR_UNSPECIFIED
#include "StuckInjrDiag_MemMap.h"

/* Block signals (auto storage) */
BlockIO_StuckInjrDiag StuckInjrDiag_B;

/* Block states (auto storage) */
D_Work_StuckInjrDiag StuckInjrDiag_DWork;

#define STUCKINJRDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "StuckInjrDiag_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define STUCKINJRDIAG_START_SEC_CODE
#include "StuckInjrDiag_MemMap.h"

/* Output and update for function-call system: '<S1>/01_StuckOpenInjrDiag' */
void StuckInjrDi_u_StuckOpenInjrDiag(void)
{
  Boolean localOU12;
  Float32 localDataTypeConversion3;
  Float32 localDataTypeConversion2;
  Boolean localRelationalOperator2;
  Boolean localLogicalOperator2;
  Boolean localRelationalOperator3_d;
  UInt32 localSwitch3;
  UInt32 locallocalSum;
  UInt8 locallocalDataTypeConversion;

  /* Outputs for enable SubSystem: '<S3>/01_StuckOpenInjrDiag' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/STUCKINJRDIAG_u8Inhib'
   *  EnablePort: '<S9>/Enable'
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  if (STUCKINJRDIAG_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET */
    VEMS_vidGET(Ext_nEng, StuckInjrDiag_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET4 */
    VEMS_vidGET(PFuAcq_pFuRailSplMes, StuckInjrDiag_B.VEMS_vidGET4);

    /* DataTypeDuplicate Block: '<S14>/Data Type Duplicate2'
     *
     * Regarding '<S14>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET5 */
    VEMS_vidGET(PFuCtl_pFuRailDifIClCtl, StuckInjrDiag_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_pFuReq, StuckInjrDiag_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET2 */
    VEMS_vidGET(InjSys_mFuSp, StuckInjrDiag_B.VEMS_vidGET2);

    /* DataTypeDuplicate Block: '<S18>/Data Type Duplicate2'
     *
     * Regarding '<S18>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Outputs for atomic SubSystem: '<S9>/01_StuckOpInjrDiagAcv' */

    /* DataTypeConversion: '<S10>/Data Type Conversion3' */
    localDataTypeConversion3 = ((Float32)StuckInjrDiag_B.VEMS_vidGET4) *
      781.25F;

    /* DataTypeConversion: '<S10>/Data Type Conversion2' */
    localDataTypeConversion2 = ((Float32)StuckInjrDiag_B.VEMS_vidGET3) *
      781.25F;

    /* DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
     *  Constant: '<S10>/Fu_SampleTiFast_SC'
     */
    locallocalDataTypeConversion = (UInt8)((SInt32)(((UInt32)
      (Fu_SampleTiFast_SC * 205)) >> 12));

    /* Abs: '<S10>/Abs' incorporates:
     *  Sum: '<S10>/Sum'
     */
    Fu_pFuReqGrdStckOpInjr_irv = ACTEMS_FabsF(localDataTypeConversion2 -
      localDataTypeConversion3);

    /* RelationalOperator: '<S10>/Relational Operator2' incorporates:
     *  Constant: '<S10>/Fu_rFuReqGainThd_C'
     *  DataTypeConversion: '<S10>/Data Type Conversion4'
     *  Product: '<S17>/Divide'
     */
    localRelationalOperator2 = (Fu_pFuReqGrdStckOpInjr_irv > ((((Float32)
      Fu_rFuReqGainThd_C) * 1.000000047E-003F) * localDataTypeConversion2));

    /* Logic: '<S16>/Logical Operator2' incorporates:
     *  Logic: '<S16>/Logical Operator4'
     *  UnitDelay: '<S20>/Unit Delay'
     */
    localLogicalOperator2 = ((localRelationalOperator2) &&
      (!StuckInjrDiag_DWork.UnitDelay_DSTATE_o));

    /* UnitDelay: '<S22>/Unit Delay' */
    localSwitch3 = StuckInjrDiag_DWork.UnitDelay_DSTATE;

    /* Switch: '<S16>/Switch2' incorporates:
     *  Constant: '<S10>/Fu_tiPFuRailStabDly_C'
     *  Sum: '<S16>/Sum1'
     */
    if (localLogicalOperator2) {
      localSwitch3 = (UInt32)(Fu_tiPFuRailStabDly_C +
        locallocalDataTypeConversion);
    }

    /* Sum: '<S16>/Sum' */
    locallocalSum = localSwitch3 - ((UInt32)locallocalDataTypeConversion);
    if (locallocalSum > localSwitch3) {
      locallocalSum = 0U;
    }

    /* RelationalOperator: '<S16>/Relational Operator3' incorporates:
     *  Constant: '<S16>/Constant4'
     */
    localRelationalOperator3_d = (0U >= locallocalSum);

    /* Switch: '<S16>/Switch3' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    if (localRelationalOperator3_d) {
      localSwitch3 = 0U;
    } else {
      localSwitch3 = locallocalSum;
    }

    /* DataTypeConversion: '<S10>/Data Type Conversion1' */
    if (localSwitch3 > 65535U) {
      Fu_tiPFuRailStabDly = MAX_uint16_T;
    } else {
      Fu_tiPFuRailStabDly = (UInt16)localSwitch3;
    }

    /* Outputs for enable SubSystem: '<S10>/01_StckOpInjrDetect' incorporates:
     *  Constant: '<S10>/Fu_bInhPFuRailStabStckInjr_C1'
     *  EnablePort: '<S13>/Enable'
     *  RelationalOperator: '<S10>/Relational Operator3'
     */
    if (Fu_tiPFuRailStabDly > 0) {
      /* Sum: '<S13>/Sum2' incorporates:
       *  Lookup_n-D: '<S18>/Lookup Table (n-D)'
       */
      localDataTypeConversion3 -= look2_iu16u16lftu16p9If_binlcs
        (StuckInjrDiag_B.VEMS_vidGET, StuckInjrDiag_B.VEMS_vidGET2,
         (&(Fu_nEngStckOpInjrThd_A[0])), (&(Fu_mFuSpStckOpInjrFallp_A[0])),
         (&(Fu_pFuRailStckOpInjrFallp_M[0])), &StuckInjrDiag_ConstP.pooled3[0],
         9U);

      /* Logic: '<S13>/OU5' incorporates:
       *  Constant: '<S13>/Fu_bInhPFuRailStabStckInjr_C1'
       *  Constant: '<S13>/Fu_pFuReqGainMaxThd_C'
       *  Constant: '<S13>/Fu_pFuReqOfsMaxThd_C'
       *  DataTypeConversion: '<S13>/Data Type Conversion1'
       *  DataTypeConversion: '<S13>/Data Type Conversion2'
       *  Product: '<S19>/Divide'
       *  RelationalOperator: '<S13>/Relational Operator3'
       *  RelationalOperator: '<S13>/Relational Operator4'
       *  Sum: '<S13>/Sum1'
       */
      Fu_bFuRailStabStckInjr = (((((((Float32)Fu_pFuReqOfsMaxThd_C) * 781.25F)
        - 2.56E+007F) + ((((Float32)Fu_pFuReqGainMaxThd_C) * 1.000000047E-003F)
                         * localDataTypeConversion2)) > localDataTypeConversion3)
        || (localDataTypeConversion3 < 0.0F));
    }

    /* end of Outputs for SubSystem: '<S10>/01_StckOpInjrDetect' */

    /* Switch: '<S16>/Switch1' incorporates:
     *  UnitDelay: '<S21>/Unit Delay'
     */
    if (!localLogicalOperator2) {
      localLogicalOperator2 = StuckInjrDiag_DWork.UnitDelay_DSTATE_d;
    }

    /* Logic: '<S10>/OU1' incorporates:
     *  Logic: '<S16>/Logical Operator'
     */
    Fu_bPFuRailStab = (((localRelationalOperator2) && ((localLogicalOperator2) &&
                         (localRelationalOperator3_d))) &&
                       Fu_bFuRailStabStckInjr);

    /* Product: '<S15>/Product4' incorporates:
     *  Constant: '<S15>/offset'
     *  Constant: '<S15>/one_on_slope'
     *  Lookup_n-D: '<S14>/Lookup Table (n-D)'
     *  Sum: '<S15>/Add1'
     */
    localDataTypeConversion3 = 1.279999968E-003F *
      look2_iu16u16lftu16p9If_binlcs(StuckInjrDiag_B.VEMS_vidGET,
      StuckInjrDiag_B.VEMS_vidGET4, (&(Fu_nEngStckOpInjrThd_A[0])),
      (&(Fu_pFuRailStckOpInjrThd_A[0])), (&(Fu_pFuRailDifStckOpInjrThd_M[0])),
      &StuckInjrDiag_ConstP.pooled3[0], 9U);

    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/offset2'
     *  Constant: '<S15>/offset3'
     *  Constant: '<S15>/offset4'
     *  RelationalOperator: '<S15>/Relational Operator'
     *  Sum: '<S15>/Add3'
     *  Sum: '<S15>/Add4'
     */
    if (localDataTypeConversion3 >= 0.0F) {
      localDataTypeConversion3 += 0.5F;
    } else {
      localDataTypeConversion3 -= 0.5F;
    }

    /* DataTypeConversion: '<S15>/OutDTConv' */
    if (localDataTypeConversion3 < 32768.0F) {
      if (localDataTypeConversion3 >= -32768.0F) {
        Fu_pFuRailDifStckOpInjrThd_MP = (SInt16)localDataTypeConversion3;
      } else {
        Fu_pFuRailDifStckOpInjrThd_MP = MIN_int16_T;
      }
    } else {
      Fu_pFuRailDifStckOpInjrThd_MP = MAX_int16_T;
    }

    /* Logic: '<S10>/OU2' incorporates:
     *  Constant: '<S10>/Fu_bInhPFuRailStabStckInjr_C'
     *  Logic: '<S10>/OU3'
     *  RelationalOperator: '<S10>/Relational Operator1'
     */
    Fu_bAcvDiagStuckInjr = ((StuckInjrDiag_B.VEMS_vidGET5 >
      (Fu_pFuRailDifStckOpInjrThd_MP << 16)) && (Fu_bInhPFuRailStabStckInjr_C ||
      Fu_bPFuRailStab));

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    StuckInjrDiag_DWork.UnitDelay_DSTATE_o = localRelationalOperator2;

    /* Update for UnitDelay: '<S22>/Unit Delay' */
    StuckInjrDiag_DWork.UnitDelay_DSTATE = locallocalSum;

    /* Update for UnitDelay: '<S21>/Unit Delay' */
    StuckInjrDiag_DWork.UnitDelay_DSTATE_d = localLogicalOperator2;

    /* end of Outputs for SubSystem: '<S9>/01_StuckOpInjrDiagAcv' */

    /* Logic: '<S11>/OU1' incorporates:
     *  Constant: '<S11>/Fu_MinEngAuthDiagStuckInjr_C'
     *  RelationalOperator: '<S11>/Relational Operator1'
     */
    localRelationalOperator2 = (Fu_bAcvDiagStuckInjr &&
      (StuckInjrDiag_B.VEMS_vidGET > Fu_MinEngAuthDiagStuckInjr_C));

    /* Logic: '<S11>/OU10' incorporates:
     *  Inport: '<Root>/FRM_bInhStuckInjrCyl2Diag'
     */
    localLogicalOperator2 = !GDGAR_bGetFRM(FRM_FRM_INHSTUCKINJRCYL2DIAG);

    /* Logic: '<S11>/OU11' incorporates:
     *  Inport: '<Root>/FRM_bInhStuckInjrCyl3Diag'
     */
    localRelationalOperator3_d = !GDGAR_bGetFRM(FRM_FRM_INHSTUCKINJRCYL3DIAG);

    /* Logic: '<S11>/OU12' incorporates:
     *  Inport: '<Root>/FRM_bInhStuckInjrCyl4Diag'
     */
    localOU12 = !GDGAR_bGetFRM(FRM_FRM_INHSTUCKINJRCYL4DIAG);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_noCylEng, StuckInjrDiag_B.VEMS_vidGET1);

    /* Logic: '<S11>/OU4' incorporates:
     *  Constant: '<S11>/Constant3'
     *  RelationalOperator: '<S11>/Relational Operator3'
     */
    Fu_bMonRunStuckOp_InjrCyl4 = (((localRelationalOperator2) &&
      (StuckInjrDiag_B.VEMS_vidGET1 == 4)) && (localOU12));

    /* Logic: '<S11>/OU5' incorporates:
     *  Inport: '<Root>/FRM_bInhStuckInjrCyl1Diag'
     *  Logic: '<S11>/OU9'
     */
    Fu_bMonRunStuckOp_InjrCyl1 = ((localRelationalOperator2) && (!GDGAR_bGetFRM
      (FRM_FRM_INHSTUCKINJRCYL1DIAG)));

    /* Logic: '<S11>/OU6' */
    Fu_bMonRunStuckOp_InjrCyl2 = ((localRelationalOperator2) &&
      (localLogicalOperator2));

    /* Logic: '<S11>/OU7' */
    Fu_bMonRunStuckOp_InjrCyl3 = ((localRelationalOperator2) &&
      (localRelationalOperator3_d));

    /* Logic: '<S12>/OU1' incorporates:
     *  Inport: '<Root>/FRM_bAcvStuckInjrCyl1Diag'
     */
    Fu_bDgoStuckOp_InjrCyl1 = (Fu_bAcvDiagStuckInjr && GDGAR_bGetFRM
      (FRM_FRM_ACVSTUCKINJRCYL1DIAG));

    /* Logic: '<S12>/OU2' incorporates:
     *  Inport: '<Root>/FRM_bAcvStuckInjrCyl2Diag'
     */
    Fu_bDgoStuckOp_InjrCyl2 = (Fu_bAcvDiagStuckInjr && GDGAR_bGetFRM
      (FRM_FRM_ACVSTUCKINJRCYL2DIAG));

    /* Logic: '<S12>/OU3' incorporates:
     *  Inport: '<Root>/FRM_bAcvStuckInjrCyl3Diag'
     */
    Fu_bDgoStuckOp_InjrCyl3 = (Fu_bAcvDiagStuckInjr && GDGAR_bGetFRM
      (FRM_FRM_ACVSTUCKINJRCYL3DIAG));

    /* Logic: '<S12>/OU8' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Inport: '<Root>/FRM_bAcvStuckInjrCyl4Diag'
     *  RelationalOperator: '<S12>/Relational Operator4'
     */
    Fu_bDgoStuckOp_InjrCyl4 = ((Fu_bAcvDiagStuckInjr &&
      (StuckInjrDiag_B.VEMS_vidGET1 == 4)) && GDGAR_bGetFRM
      (FRM_FRM_ACVSTUCKINJRCYL4DIAG));
  }

  /* end of Outputs for SubSystem: '<S3>/01_StuckOpenInjrDiag' */
}

/* Start for exported function: Fu_SdlFast_StuckInjrDiag */
void Fu_SdlFast_StuckInjrDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */

  /* Start for S-Function (fcncallgen): '<S8>/gen' incorporates:
   *  Start for SubSystem: '<S1>/01_StuckOpenInjrDiag'
   *  Start for SubSystem: '<S1>/Function-Call Subsystem'
   *  Start for SubSystem: '<S1>/Function-Call Subsystem1'
   *  Start for SubSystem: '<S1>/Function-Call Subsystem2'
   *  Start for SubSystem: '<S1>/Function-Call Subsystem3'
   *
   * Block requirements for '<S1>/01_StuckOpenInjrDiag':
   *  1. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_001.01 ;
   *  2. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_002.01 ;
   *  3. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_003.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  Start for Stateflow: '<S26>/Chart'
   */

  /* Start for Stateflow: '<S26>/Chart' incorporates:
   *  Start for SubSystem: '<S7>/GDGAR_vidGdu_Subsystem'
   */
}

/* Output and update for exported function: Fu_SdlFast_StuckInjrDiag */
void Fu_SdlFast_StuckInjrDiag(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S8>/gen' incorporates:
   *  SubSystem: '<S1>/01_StuckOpenInjrDiag'
   *  SubSystem: '<S1>/Function-Call Subsystem'
   *  SubSystem: '<S1>/Function-Call Subsystem1'
   *  SubSystem: '<S1>/Function-Call Subsystem2'
   *  SubSystem: '<S1>/Function-Call Subsystem3'
   *
   * Block requirements for '<S1>/01_StuckOpenInjrDiag':
   *  1. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_001.01 ;
   *  2. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_002.01 ;
   *  3. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_003.01 ;
   */
  StuckInjrDi_u_StuckOpenInjrDiag();

  /* Outputs for atomic SubSystem: '<S4>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S23>/S-Function */
  GDGAR_vidGdu(GD_DFT_STUCKOP_INJRCYL1, Fu_bDgoStuckOp_InjrCyl1,
               Fu_bMonRunStuckOp_InjrCyl1, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S4>/GDGAR_vidGdu' */

  /* Outputs for atomic SubSystem: '<S5>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S24>/S-Function */
  GDGAR_vidGdu(GD_DFT_STUCKOP_INJRCYL2, Fu_bDgoStuckOp_InjrCyl2,
               Fu_bMonRunStuckOp_InjrCyl2, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S5>/GDGAR_vidGdu' */

  /* Outputs for atomic SubSystem: '<S6>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S25>/S-Function */
  GDGAR_vidGdu(GD_DFT_STUCKOP_INJRCYL3, Fu_bDgoStuckOp_InjrCyl3,
               Fu_bMonRunStuckOp_InjrCyl3, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S6>/GDGAR_vidGdu' */

  /* S-Function "vems_vidGET" Block: <S7>/S-Function4 */
  VEMS_vidGET(Ext_noCylEng, StuckInjrDiag_B.SFunction4);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  Stateflow: '<S26>/Chart'
   */

  /* Stateflow: '<S26>/Chart' incorporates:
   *  Constant: '<S7>/Constant3'
   *  RelationalOperator: '<S26>/Relational Operator3'
   *  SubSystem: '<S7>/GDGAR_vidGdu_Subsystem'
   */
  /* Gateway: StuckInjrDiag/Function-Call
     Subsystem3/Fun_Call_Gen_with_condition_Modified/Chart */
  /* During: StuckInjrDiag/Function-Call
     Subsystem3/Fun_Call_Gen_with_condition_Modified/Chart */
  if ((StuckInjrDiag_B.SFunction4 == 4) == 1) {
    /* Transition: '<S28>:2' */
    /* Event: '<S28>:5' */

    /* Outputs for atomic SubSystem: '<S27>/GDGAR_vidGdu' */
    /* S-Function "GDGAR_bGetFRM" Block: <S29>/S-Function */
    GDGAR_vidGdu(GD_DFT_STUCKOP_INJRCYL4, Fu_bDgoStuckOp_InjrCyl4,
                 Fu_bMonRunStuckOp_InjrCyl4, DIAG_DISPO);

    /* end of Outputs for SubSystem: '<S27>/GDGAR_vidGdu' */
  }
}

/* Model initialize function */
void StuckInjrDiag_initialize(void)
{
  /* Start for S-Function (fcncallgen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   */
  Fu_SdlFast_StuckInjrDiag_Start();
}

#define STUCKINJRDIAG_STOP_SEC_CODE
#include "StuckInjrDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
