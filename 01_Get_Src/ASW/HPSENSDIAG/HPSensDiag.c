/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPSensDiag                                              */
/* !Description     : Functional diagnosis of HP Sensor                       */
/*                                                                            */
/* !Module          : HPSensDiag                                              */
/*                                                                            */
/* !File            : HPSensDiag.c                                            */
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
/* !Reference       : PTS_DOC_5060514 / 05                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Oct 17 18:16:02 2013                              */
/*   Model name       : HPSensDiag_Autocode.mdl                               */
/*   Model version    : 1.418                                                 */
/*   Root subsystem   : /HPSensDiag                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/HPSENSDIAG/HPSensDiag.c_v    $*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   30 Oct 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPSensDiag.h"
#include "HPSensDiag_private.h"

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
#define HPSENSDIAG_START_SEC_VAR_UNSPECIFIED
#include "HPSensDiag_MemMap.h"

/* Block signals (auto storage) */
BlockIO_HPSensDiag HPSensDiag_B;

/* Block states (auto storage) */
D_Work_HPSensDiag HPSensDiag_DWork;

#define HPSENSDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "HPSensDiag_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define HPSENSDIAG_START_SEC_CODE
#include "HPSensDiag_MemMap.h"

/* Output and update for function-call system: '<S1>/F03_HPSensDiagInit' */
void HPSensDiag_F03_HPSensDiagInit(void)
{
  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET */
  VEMS_vidGET(InjSys_pFuReq, Fu_pFuReqPrevIni);
}

/* Output and update for exported function: Fu_EveRst_HPSensDiag */
void Fu_EveRst_HPSensDiag(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_HPSensDiagInit'
   */
  HPSensDiag_F03_HPSensDiagInit();
}

/* Start for function-call system: '<S1>/F01_HPSensDiag' */
void HPSensDiag_F01_HPSensDiag_Start(void)
{
  /* Start for enable SubSystem: '<S6>/F01_HPSensDiag' */

  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
  HPSensDiag_DWork.UnitDelay_DSTATE_lp = TRUE;

  /* end of Start for SubSystem: '<S6>/F01_HPSensDiag' */
}

/* Output and update for function-call system: '<S1>/F01_HPSensDiag' */
void HPSensDiag_F01_HPSensDiag(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator;
  Boolean localRelationalOperator10;
  Float32 localSwitch1;
  Boolean localLogicalOperator1;
  SInt32 localSum;
  SInt32 locallocalSum_m;
  SInt16 localtmp;
  UInt16 locallocalUnitDelay_j;

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/ConstVal'
   *  Constant: '<S6>/HPSENSDIAG_u8Inhib'
   */
  localRelationalOperator = (HPSENSDIAG_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S6>/F01_HPSensDiag' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (localRelationalOperator) {
    /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET */
    VEMS_vidGET(InjSys_pFuReq, HPSensDiag_B.VEMS_vidGET_g);

    /* Switch: '<S19>/FixPt Switch2' incorporates:
     *  UnitDelay: '<S40>/Unit Delay'
     *  UnitDelay: '<S41>/Unit Delay'
     */
    if (HPSensDiag_DWork.UnitDelay_DSTATE_lp) {
      Fu_pFuReqPrev = Fu_pFuReqPrevIni;
    } else {
      Fu_pFuReqPrev = HPSensDiag_DWork.UnitDelay_DSTATE_j;
    }

    /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET2 */
    VEMS_vidGET(PFuAcq_pFuRailMes, HPSensDiag_B.VEMS_vidGET2);

    /* UnitDelay: '<S17>/Unit Delay' */
    Fu_bPFuRailStabHPSensDiag_prev = HPSensDiag_DWork.UnitDelay_DSTATE_m;

    /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET1 */
    VEMS_vidGET(InjrSys_mFuInjEstim, HPSensDiag_B.VEMS_vidGET1_k);

    /* UnitDelay: '<S18>/Unit Delay' */
    Fu_bAcvStuck_HPSens_prev = HPSensDiag_DWork.UnitDelay_DSTATE_bx;

    /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_nEng, HPSensDiag_B.VEMS_vidGET3);

    /* Outputs for atomic SubSystem: '<S14>/F01_pFuRailReqCdn' */

    /* Sum: '<S15>/Sum' */
    localSum = HPSensDiag_B.VEMS_vidGET_g - Fu_pFuReqPrev;

    /* Abs: '<S15>/Abs' */
    if (localSum < 0) {
      Fu_pFuReqGrdHPSensDiag = (UInt16)(-localSum);
    } else {
      Fu_pFuReqGrdHPSensDiag = (UInt16)localSum;
    }

    /* DataTypeConversion: '<S15>/Data Type Conversion1' */
    if (localSum > 32767) {
      Fu_pFuReqGrdHPSensDiagRaw = MAX_int16_T;
    } else if (localSum <= -32768) {
      Fu_pFuReqGrdHPSensDiagRaw = MIN_int16_T;
    } else {
      Fu_pFuReqGrdHPSensDiagRaw = (SInt16)localSum;
    }

    /* Sum: '<S15>/Sum1' */
    localSum = HPSensDiag_B.VEMS_vidGET2 - Fu_pFuReqPrev;
    if (localSum > 32767) {
      Fu_pFuDifHPSensDiag = MAX_int16_T;
    } else if (localSum <= -32768) {
      Fu_pFuDifHPSensDiag = MIN_int16_T;
    } else {
      Fu_pFuDifHPSensDiag = (SInt16)localSum;
    }

    /* RelationalOperator: '<S15>/Relational Operator10' incorporates:
     *  Constant: '<S15>/ConstVal_3'
     */
    localRelationalOperator10 = (Fu_pFuReqGrdHPSensDiagRaw > 0);

    /* Product: '<S23>/Product4' incorporates:
     *  Constant: '<S15>/ConstVal_2'
     *  Constant: '<S15>/Fu_pFuDifHPSensDiagThd_C1'
     *  Constant: '<S23>/offset'
     *  Constant: '<S23>/one_on_slope'
     *  DataTypeConversion: '<S15>/Data Type Conversion2'
     *  Product: '<S24>/Divide'
     *  Sum: '<S23>/Add1'
     */
    localSwitch1 = ((((Float32)Fu_pFuDifHPSensDiagThd_C) * 781.25F) * -1.0F) *
      1.279999968E-003F;

    /* Switch: '<S23>/Switch1' incorporates:
     *  Constant: '<S23>/offset2'
     *  Constant: '<S23>/offset3'
     *  Constant: '<S23>/offset4'
     *  RelationalOperator: '<S23>/Relational Operator'
     *  Sum: '<S23>/Add3'
     *  Sum: '<S23>/Add4'
     */
    if (localSwitch1 >= 0.0F) {
      localSwitch1 = 0.5F;
    } else {
      localSwitch1 -= 0.5F;
    }

    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/Fu_pFuDifHPSensDiagThd_C'
     *  DataTypeConversion: '<S23>/OutDTConv'
     *  RelationalOperator: '<S15>/Relational Operator7'
     *  RelationalOperator: '<S15>/Relational Operator8'
     */
    if (localRelationalOperator10) {
      Fu_bAcvHPSensDiag_pFuRailCond = (Fu_pFuDifHPSensDiag <=
        Fu_pFuDifHPSensDiagThd_C);
    } else {
      if (localSwitch1 >= -32768.0F) {
        localtmp = (SInt16)localSwitch1;
      } else {
        localtmp = MIN_int16_T;
      }

      Fu_bAcvHPSensDiag_pFuRailCond = (Fu_pFuDifHPSensDiag > localtmp);
    }

    /* Logic: '<S22>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Fu_pFuReqGrdHPSensDiagThd_C'
     *  Logic: '<S15>/OU4'
     *  Logic: '<S15>/OU5'
     *  Logic: '<S20>/OU1'
     *  Logic: '<S20>/OU7'
     *  Logic: '<S21>/OU5'
     *  Logic: '<S21>/OU7'
     *  Logic: '<S22>/Logical Operator'
     *  RelationalOperator: '<S15>/Relational Operator2'
     *  UnitDelay: '<S25>/Unit Delay'
     *  UnitDelay: '<S26>/Unit Delay'
     *  UnitDelay: '<S27>/Unit Delay'
     */
    localLogicalOperator1 = !((!(HPSensDiag_DWork.UnitDelay_DSTATE_fi ||
      (Fu_bAcvHPSensDiag_pFuRailCond && (Fu_pFuReqGrdHPSensDiag >
      Fu_pFuReqGrdHPSensDiagThd_C)))) || ((Fu_bPFuRailStabHPSensDiag_prev &&
      (!HPSensDiag_DWork.UnitDelay_DSTATE_d)) || ((!Fu_bAcvStuck_HPSens_prev) &&
      HPSensDiag_DWork.UnitDelay_DSTATE_fv)));

    /* Logic: '<S15>/OU14' incorporates:
     *  Constant: '<S15>/Fu_mFuInjMinHPSensThd_C'
     *  Constant: '<S15>/Fu_pFuRailMaxHPSensThd_C'
     *  Constant: '<S15>/Fu_pFuRailMinHPSensThd_C'
     *  Constant: '<S15>/Fu_rFuEngMinHPSensThd_C'
     *  Inport: '<Root>/FRM_bInhHPSensDiag'
     *  Logic: '<S15>/OU1'
     *  Logic: '<S15>/OU2'
     *  Logic: '<S15>/OU3'
     *  RelationalOperator: '<S15>/Relational Operator1'
     *  RelationalOperator: '<S15>/Relational Operator3'
     *  RelationalOperator: '<S15>/Relational Operator4'
     *  RelationalOperator: '<S15>/Relational Operator9'
     */
    Fu_bCondDiag_HPSens = (((((localLogicalOperator1) &&
      ((HPSensDiag_B.VEMS_vidGET2 > Fu_pFuRailMinHPSensThd_C) &&
       (HPSensDiag_B.VEMS_vidGET2 < Fu_pFuRailMaxHPSensThd_C))) &&
      (!GDGAR_bGetFRM(FRM_FRM_INHHPSENSDIAG))) && ((HPSensDiag_B.VEMS_vidGET1_k >
      Fu_mFuInjMinHPSensThd_C) || (localRelationalOperator10))) &&
      (HPSensDiag_B.VEMS_vidGET3 > Fu_rFuEngMinHPSensThd_C));

    /* Update for UnitDelay: '<S25>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_fv = Fu_bAcvStuck_HPSens_prev;

    /* Update for UnitDelay: '<S27>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_fi = localLogicalOperator1;

    /* Update for UnitDelay: '<S26>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_d = Fu_bPFuRailStabHPSensDiag_prev;

    /* end of Outputs for SubSystem: '<S14>/F01_pFuRailReqCdn' */

    /* Outputs for atomic SubSystem: '<S14>/F02_pFuRailGrd' */

    /* Switch: '<S16>/Switch' incorporates:
     *  Logic: '<S30>/OU5'
     *  Logic: '<S30>/OU7'
     *  UnitDelay: '<S32>/Unit Delay'
     *  UnitDelay: '<S35>/Unit Delay'
     */
    if (Fu_bCondDiag_HPSens && (!HPSensDiag_DWork.UnitDelay_DSTATE_hs)) {
      Fu_pFuRailHPSensDiagMem = HPSensDiag_B.VEMS_vidGET2;
    } else {
      Fu_pFuRailHPSensDiagMem = HPSensDiag_DWork.UnitDelay_DSTATE_h;
    }

    /* Sum: '<S16>/Sum' */
    localSum = Fu_pFuRailHPSensDiagMem - HPSensDiag_B.VEMS_vidGET2;

    /* Abs: '<S16>/Abs' */
    if (localSum < 0) {
      Fu_pFuRailGrdHPSensDiag = (UInt16)(-localSum);
    } else {
      Fu_pFuRailGrdHPSensDiag = (UInt16)localSum;
    }

    /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
     *  Constant: '<S16>/Fu_SampleTiFast_SC'
     */
    localSum = Fu_SampleTiFast_SC * 205;
    locallocalUnitDelay_j = (UInt16)((((UInt32)(localSum & 2048)) != 0U) +
                                       ((SInt32)(((UInt32)localSum) >> 12)));

    /* Sum: '<S34>/Sum1' incorporates:
     *  Constant: '<S16>/Fu_tiPFuRailStabHPSensDiagDly_C'
     */
    localSum = (SInt32)((UInt32)(Fu_tiPFuRailStabHPSensDiagDly_C +
      locallocalUnitDelay_j));

    /* Logic: '<S34>/Logical Operator2' incorporates:
     *  Logic: '<S34>/Logical Operator4'
     *  UnitDelay: '<S37>/Unit Delay'
     */
    localRelationalOperator10 = (Fu_bCondDiag_HPSens &&
      (!HPSensDiag_DWork.UnitDelay_DSTATE_h3));

    /* Switch: '<S34>/Switch2' incorporates:
     *  UnitDelay: '<S39>/Unit Delay'
     */
    if (!localRelationalOperator10) {
      localSum = HPSensDiag_DWork.UnitDelay_DSTATE_l;
    }

    /* Sum: '<S34>/Sum' */
    locallocalSum_m = localSum - locallocalUnitDelay_j;
    if ((localSum < 0) && (locallocalSum_m >= 0)) {
      locallocalSum_m = MIN_int32_T;
    }

    /* RelationalOperator: '<S34>/Relational Operator3' incorporates:
     *  Constant: '<S34>/Constant4'
     */
    localLogicalOperator1 = (0 >= locallocalSum_m);

    /* Switch: '<S34>/Switch3' incorporates:
     *  Constant: '<S34>/Constant1'
     */
    if (localLogicalOperator1) {
      localSum = 0;
    } else {
      localSum = locallocalSum_m;
    }

    /* DataTypeConversion: '<S16>/Data Type Conversion2' */
    if (localSum <= 0) {
      Fu_tiPFuRailStabHPSensDiagDly = 0U;
    } else if (localSum > 65535) {
      Fu_tiPFuRailStabHPSensDiagDly = MAX_uint16_T;
    } else {
      Fu_tiPFuRailStabHPSensDiagDly = (UInt16)localSum;
    }

    /* RelationalOperator: '<S16>/Relational Operator2' incorporates:
     *  Constant: '<S16>/Fu_pFuRailGrdHPSensDiag_C'
     */
    Fu_bRawDgoStuck_HPSens = (Fu_pFuRailGrdHPSensDiag <
      Fu_pFuRailGrdHPSensDiag_C);

    /* Switch: '<S34>/Switch1' incorporates:
     *  UnitDelay: '<S38>/Unit Delay'
     */
    if (!localRelationalOperator10) {
      localRelationalOperator10 = HPSensDiag_DWork.UnitDelay_DSTATE_f;
    }

    /* Logic: '<S34>/Logical Operator' */
    Fu_bPFuRailStabHPSensDiag = ((localRelationalOperator10) &&
      (localLogicalOperator1));

    /* Switch: '<S16>/Switch1' incorporates:
     *  Logic: '<S31>/OU5'
     *  Logic: '<S31>/OU7'
     *  UnitDelay: '<S33>/Unit Delay'
     *  UnitDelay: '<S36>/Unit Delay'
     */
    if (Fu_bCondDiag_HPSens && (!HPSensDiag_DWork.UnitDelay_DSTATE_jk)) {
      Fu_pFuReqDiagMem = Fu_pFuReqPrev;
    } else {
      Fu_pFuReqDiagMem = HPSensDiag_DWork.UnitDelay_DSTATE_b;
    }

    /* Outputs for enable SubSystem: '<S16>/F02_bAcvStuckDiag' incorporates:
     *  Constant: '<S16>/ConstVal'
     *  EnablePort: '<S29>/Enable'
     *  RelationalOperator: '<S16>/Relational Operator1'
     */
    if (Fu_tiPFuRailStabHPSensDiagDly > 0) {
      /* Sum: '<S29>/Add' */
      localSum = Fu_pFuReqDiagMem - HPSensDiag_B.VEMS_vidGET_g;

      /* Abs: '<S29>/Abs1' */
      if (localSum < 0) {
        locallocalUnitDelay_j = (UInt16)(-localSum);
      } else {
        locallocalUnitDelay_j = (UInt16)localSum;
      }

      /* RelationalOperator: '<S29>/Relational Operator' incorporates:
       *  Constant: '<S29>/Fu_pFuReqThdBdVal_C'
       */
      Fu_bAcvStuck_HPSens = (locallocalUnitDelay_j > Fu_pFuReqThdBdVal_C);
    }

    /* end of Outputs for SubSystem: '<S16>/F02_bAcvStuckDiag' */

    /* Logic: '<S16>/OU14' */
    Fu_bMonRunStuck_HPSens = ((Fu_bCondDiag_HPSens && Fu_bPFuRailStabHPSensDiag)
      && Fu_bAcvStuck_HPSens);

    /* Outputs for enable SubSystem: '<S16>/F01_bDgoStuckClcn' incorporates:
     *  EnablePort: '<S28>/Fu_bMonRunStuck_HPSens'
     */
    if (Fu_bMonRunStuck_HPSens) {
      /* SignalConversion: '<S28>/Signal Conversion' */
      Fu_bDgoStuck_HPSens = Fu_bRawDgoStuck_HPSens;
    }

    /* end of Outputs for SubSystem: '<S16>/F01_bDgoStuckClcn' */

    /* Update for UnitDelay: '<S35>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_hs = Fu_bCondDiag_HPSens;

    /* Update for UnitDelay: '<S32>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_h = Fu_pFuRailHPSensDiagMem;

    /* Update for UnitDelay: '<S37>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_h3 = Fu_bCondDiag_HPSens;

    /* Update for UnitDelay: '<S39>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_l = locallocalSum_m;

    /* Update for UnitDelay: '<S38>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_f = localRelationalOperator10;

    /* Update for UnitDelay: '<S36>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_jk = Fu_bCondDiag_HPSens;

    /* Update for UnitDelay: '<S33>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_b = Fu_pFuReqDiagMem;

    /* end of Outputs for SubSystem: '<S14>/F02_pFuRailGrd' */
  }

  /* end of Outputs for SubSystem: '<S6>/F01_HPSensDiag' */

  /* Update for enable SubSystem: '<S6>/F01_HPSensDiag' incorporates:
   *  Update for EnablePort: '<S14>/Enable'
   */
  if (localRelationalOperator) {
    /* Update for UnitDelay: '<S41>/Unit Delay' incorporates:
     *  Constant: '<S19>/FixPt Constant'
     */
    HPSensDiag_DWork.UnitDelay_DSTATE_lp = FALSE;

    /* Update for UnitDelay: '<S40>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_j = HPSensDiag_B.VEMS_vidGET_g;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_m = Fu_bPFuRailStabHPSensDiag;

    /* Update for UnitDelay: '<S18>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_bx = Fu_bAcvStuck_HPSens;
  }

  /* end of Update for SubSystem: '<S6>/F01_HPSensDiag' */
}

/* Output and update for function-call system: '<S1>/GDGAR_vidGdu' */
void HPSensDiag_GDGAR_vidGdu(void)
{
  /* Outputs for atomic SubSystem: '<S9>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S50>/S-Function */
  GDGAR_vidGdu(GD_DFT_STUCK_HPSENS, Fu_bDgoStuck_HPSens, Fu_bMonRunStuck_HPSens,
               DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S9>/GDGAR_vidGdu' */
}

/* Start for function-call system: '<S1>/demux_fc1' */
void HPSensDiag_demux_fc1_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S12>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_HPSensDiag'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu'
   *
   * Block requirements for '<S1>/GDGAR_vidGdu':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_10_08248_029.01 ;
   */
  HPSensDiag_F01_HPSensDiag_Start();
}

/* Output and update for function-call system: '<S1>/demux_fc1' */
void HPSensDiag_demux_fc1(void)
{
  /* S-Function (fcncallgen): '<S12>/gen' incorporates:
   *  SubSystem: '<S1>/F01_HPSensDiag'
   *  SubSystem: '<S1>/GDGAR_vidGdu'
   *
   * Block requirements for '<S1>/GDGAR_vidGdu':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_10_08248_029.01 ;
   */
  HPSensDiag_F01_HPSensDiag();
  HPSensDiag_GDGAR_vidGdu();
}

/* Start for exported function: Fu_SdlFast_HPSensDiag */
void Fu_SdlFast_HPSensDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */
  HPSensDiag_demux_fc1_Start();
}

/* Output and update for exported function: Fu_SdlFast_HPSensDiag */
void Fu_SdlFast_HPSensDiag(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */
  HPSensDiag_demux_fc1();
}

/* Output and update for function-call system: '<S1>/F00_mFuBtwEveInj' */
void HPSensDiag_F00_mFuBtwEveInj(void)
{
  /* Outputs for enable SubSystem: '<S5>/F00_mFuBtwEveInj' incorporates:
   *  Constant: '<S5>/ConstVal'
   *  Constant: '<S5>/HPSENSDIAG_u8Inhib'
   *  EnablePort: '<S13>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (HPSENSDIAG_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET */
    VEMS_vidGET(InjrSys_mFuInjEstim, Fu_mFuInjBtwEveSpl);
  }

  /* end of Outputs for SubSystem: '<S5>/F00_mFuBtwEveInj' */
}

/* Output and update for function-call system: '<S1>/F02_CohTest' */
void HPSensDiag_F02_CohTest(void)
{
  /* local block i/o variables */
  UInt16 localUnitDelay_i;
  Float32 localSwitch1_p;
  UInt32 localAbs;
  SInt32 localSum1;
  SInt32 localq;

  /* Outputs for enable SubSystem: '<S7>/F02_CohTest' incorporates:
   *  Constant: '<S7>/ConstVal'
   *  Constant: '<S7>/HPSENSDIAG_u8Inhib'
   *  EnablePort: '<S42>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (HPSENSDIAG_u8Inhib != 90) {
    /* Sum: '<S42>/Sum' incorporates:
     *  UnitDelay: '<S44>/Unit Delay'
     *  UnitDelay: '<S45>/Unit Delay'
     */
    if (HPSensDiag_DWork.UnitDelay_DSTATE > 2147483647U) {
      localq = MAX_int32_T;
    } else {
      localq = (SInt32)HPSensDiag_DWork.UnitDelay_DSTATE;
    }

    Fu_mFuDifBtwSpl = localq - HPSensDiag_DWork.UnitDelay_DSTATE_k;

    /* Abs: '<S42>/Abs' */
    if (Fu_mFuDifBtwSpl < 0) {
      localAbs = (UInt32)(-Fu_mFuDifBtwSpl);
    } else {
      localAbs = (UInt32)Fu_mFuDifBtwSpl;
    }

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET */
    VEMS_vidGET(Ext_pFuRailSplMes, HPSensDiag_B.VEMS_vidGET);

    /* RelationalOperator: '<S42>/Relational Operator2' incorporates:
     *  Constant: '<S42>/Fu_mFuDifThdMin_C'
     */
    Fu_bAcvPFuRailSenDiag = (localAbs >= ((UInt32)Fu_mFuDifThdMin_C));

    /* Logic: '<S42>/Logical Operator3' incorporates:
     *  Constant: '<S42>/Fu_pFuRailThdMax_C'
     *  Constant: '<S42>/Fu_pFuRailThdMin_C'
     *  Inport: '<Root>/FRM_bInhPFuRailSenDiag'
     *  Logic: '<S42>/Logical Operator1'
     *  Logic: '<S42>/Logical Operator2'
     *  RelationalOperator: '<S42>/Relational Operator'
     *  RelationalOperator: '<S42>/Relational Operator1'
     */
    Fu_bMonRunCoh_HPSens = ((Fu_bAcvPFuRailSenDiag && (!GDGAR_bGetFRM
      (FRM_FRM_INHPFURAILSENDIAG))) && ((Fu_pFuRailThdMax_C >=
      HPSensDiag_B.VEMS_vidGET) && (HPSensDiag_B.VEMS_vidGET >=
      Fu_pFuRailThdMin_C)));

    /* Outputs for enable SubSystem: '<S42>/F01_DiagAcv' incorporates:
     *  EnablePort: '<S43>/Fu_bMonRunCoh_HPSens'
     */
    if (Fu_bMonRunCoh_HPSens) {
      /* Lookup: '<S46>/Look-Up Table'
       * About '<S46>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    S32  2^-27
       * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000  Bias -5.119921875E+007
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_S32( &(localUnitDelay_i), (&(Fu_pFuRailDifNegThd_T[0])),
                     Fu_mFuDifBtwSpl, (&(Fu_mFuDifBtwSpl_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S46>/Data Type Duplicate1'
       *
       * Regarding '<S46>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S43>/Data Type Conversion2' */
      localq = localUnitDelay_i + -65535;

      /* UnitDelay: '<S49>/Unit Delay' */
      localUnitDelay_i = HPSensDiag_DWork.UnitDelay_DSTATE_ly;

      /* Sum: '<S43>/Sum1' */
      localSum1 = HPSensDiag_B.VEMS_vidGET - localUnitDelay_i;

      /* Product: '<S48>/Product4' incorporates:
       *  Constant: '<S48>/offset'
       *  Constant: '<S48>/one_on_slope'
       *  Lookup_n-D: '<S47>/Lookup Table (n-D)'
       *  Sum: '<S48>/Add1'
       */
      localSwitch1_p = 1.279999968E-003F * look1_is32lftu16p9If_binlcs
        (Fu_mFuDifBtwSpl, (&(Fu_mFuDifBtwSpl_A[0])), (&(Fu_pFuRailDifPosThd_T[0])),
         8U);

      /* Switch: '<S48>/Switch1' incorporates:
       *  Constant: '<S48>/offset2'
       *  Constant: '<S48>/offset3'
       *  Constant: '<S48>/offset4'
       *  RelationalOperator: '<S48>/Relational Operator'
       *  Sum: '<S48>/Add3'
       *  Sum: '<S48>/Add4'
       */
      if (localSwitch1_p >= 0.0F) {
        localSwitch1_p += 0.5F;
      } else {
        localSwitch1_p -= 0.5F;
      }

      /* Switch: '<S43>/Switch' incorporates:
       *  Constant: '<S43>/ConstVal'
       *  DataTypeConversion: '<S48>/OutDTConv'
       *  RelationalOperator: '<S43>/Relational Operator1'
       *  RelationalOperator: '<S43>/Relational Operator2'
       *  RelationalOperator: '<S43>/Relational Operator3'
       */
      if (Fu_mFuDifBtwSpl < 0) {
        Fu_bDgoCoh_HPSens = (localSum1 > localq);
      } else {
        if (localSwitch1_p < 2.147483648E+009F) {
          if (localSwitch1_p >= -2.147483648E+009F) {
            localq = (SInt32)localSwitch1_p;
          } else {
            localq = MIN_int32_T;
          }
        } else {
          localq = MAX_int32_T;
        }

        Fu_bDgoCoh_HPSens = (localSum1 < localq);
      }

      /* Update for UnitDelay: '<S49>/Unit Delay' */
      HPSensDiag_DWork.UnitDelay_DSTATE_ly = HPSensDiag_B.VEMS_vidGET;
    }

    /* end of Outputs for SubSystem: '<S42>/F01_DiagAcv' */
    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET1 */
    VEMS_vidGET(PFuCtl_mFuPmpEstimRaw, HPSensDiag_B.VEMS_vidGET1);

    /* Update for UnitDelay: '<S45>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE = HPSensDiag_B.VEMS_vidGET1;

    /* Update for UnitDelay: '<S44>/Unit Delay' */
    HPSensDiag_DWork.UnitDelay_DSTATE_k = Fu_mFuInjBtwEveSpl;
  }

  /* end of Outputs for SubSystem: '<S7>/F02_CohTest' */
}

/* Output and update for function-call system: '<S1>/GDGAR_vidGdu1' */
void HPSensDiag_GDGAR_vidGdu1(void)
{
  /* Outputs for atomic SubSystem: '<S10>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S51>/S-Function */
  GDGAR_vidGdu(GD_DFT_COH_HPSENS, Fu_bDgoCoh_HPSens, Fu_bMonRunCoh_HPSens,
               DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S10>/GDGAR_vidGdu' */
}

/* Start for function-call system: '<S1>/demux_fc' */
void HPSensDiag_demux_fc_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F00_mFuBtwEveInj'
   *  Start for SubSystem: '<S1>/F02_CohTest'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu1'
   *
   * Block requirements for '<S1>/GDGAR_vidGdu1':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_10_08248_029.01 ;
   */
}

/* Output and update for function-call system: '<S1>/demux_fc' */
void HPSensDiag_demux_fc(void)
{
  /* S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  SubSystem: '<S1>/F00_mFuBtwEveInj'
   *  SubSystem: '<S1>/F02_CohTest'
   *  SubSystem: '<S1>/GDGAR_vidGdu1'
   *
   * Block requirements for '<S1>/GDGAR_vidGdu1':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_10_08248_029.01 ;
   */
  HPSensDiag_F00_mFuBtwEveInj();
  HPSensDiag_F02_CohTest();
  HPSensDiag_GDGAR_vidGdu1();
}

/* Start for exported function: Fu_EveSpl_HPSensDiag */
void Fu_EveSpl_HPSensDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc'
   */
  HPSensDiag_demux_fc_Start();
}

/* Output and update for exported function: Fu_EveSpl_HPSensDiag */
void Fu_EveSpl_HPSensDiag(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc'
   */
  HPSensDiag_demux_fc();
}

/* Model initialize function */
void HPSensDiag_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  Fu_SdlFast_HPSensDiag_Start();
  Fu_EveSpl_HPSensDiag_Start();
}

#define HPSENSDIAG_STOP_SEC_CODE
#include "HPSensDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
