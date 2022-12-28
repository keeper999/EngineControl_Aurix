/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : RblPvt                                                  */
/* !Description     : RUMBLE PREVENTION                                       */
/*                                                                            */
/* !Module          : RblPvt                                                  */
/*                                                                            */
/* !File            : RblPvt.c                                                */
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
/* !Reference       : V02NT1205315 / 01                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Dec 13 15:30:24 2012                              */
/*   Model name       : RblPvt_AUTOCODE.mdl                                   */
/*   Model version    : 1.23                                                  */
/*   Root subsystem   : /RblPvt                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/RblPvt/5-SOFT-LIV/RblPvt.c_v$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   adelvare                               $$Date::   28 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "RblPvt.h"
#include "RblPvt_private.h"

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
#define RBLPVT_START_SEC_VAR_UNSPECIFIED
#include "RblPvt_MemMap.h"

/* Block signals (auto storage) */
BlockIO_RblPvt RblPvt_B;

/* Block states (auto storage) */
D_Work_RblPvt RblPvt_DWork;

#define RBLPVT_STOP_SEC_VAR_UNSPECIFIED
#include "RblPvt_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define RBLPVT_START_SEC_CODE
#include "RblPvt_MemMap.h"

void RblPvt_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/01_RblPvt_init' */
void RblPvt_u_RblPvt_init(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(KnkMgt_bAcvIrvLdLimToilReq, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(KnkMgt_bAcvIrvLdLimRblPvtReq, FALSE);
}

/* Output and update for exported function: KnkTreat_EveRst_RblPvt */
void KnkTreat_EveRst_RblPvt(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/01_RblPvt_init'
   */
  RblPvt_u_RblPvt_init();
}

/*
 * Output and update for action system:
 *    '<S8>/If Action Subsystem'
 *    '<S9>/If Action Subsystem'
 */
void RblPvt_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S25>/Value 1' */
  (*rty_Out1) = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S8>/If Action Subsystem1'
 *    '<S9>/If Action Subsystem1'
 */
void RblPvt_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S26>/Value 2' */
  (*rty_Out1) = rtu_0;
}

/* Output and update for function-call system: '<S1>/02_RblPvt_calc' */
void RblPvt_u_RblPvt_calc(void)
{
  Float32 localSwitch2;
  Float32 localDivide;
  Float32 localSum1;
  Float32 localfrac[2];
  Float32 localInterpolationUsingPrelooku;
  UInt32 localExt_nEng_KnkMgt_nEng_A_9_k;
  UInt32 localbpIndex[2];
  UInt32 localExt_pDsThrMesSI_KnkMgt_pDs;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localAdd2;
  Boolean localRelationalOperator_n;
  Float32 localmax;
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  UInt16 locallocalDataTypeConversion;

  /* Outputs for enable SubSystem: '<S5>/02_RblPvt_calc' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/RBLPVT_u8Inhib'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (RBLPVT_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_tOilMes, RblPvt_B.VEMS_vidGET3);

    /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
     *  Constant: '<S6>/KnkMgt_tOilMesLo_C'
     */
    localSwitch2 = ((Float32)KnkMgt_tOilMesLo_C) * 1.000000015E-001F;

    /* Product: '<S18>/Divide' incorporates:
     *  Constant: '<S6>/KnkMgt_tOilMesHi_C'
     *  DataTypeConversion: '<S6>/Data Type Conversion1'
     *  DataTypeConversion: '<S6>/Data Type Conversion3'
     *  Sum: '<S6>/Sum2'
     *  Sum: '<S6>/Sum4'
     */
    localDivide = ((((Float32)RblPvt_B.VEMS_vidGET3) * 1.000000015E-001F) -
                   localSwitch2) / ((((Float32)KnkMgt_tOilMesHi_C) *
      1.000000015E-001F) - localSwitch2);

    /* Outputs for atomic SubSystem: '<S18>/If Action Subsystem3' */

    /* Switch: '<S30>/Switch1' incorporates:
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S30>/Constant2'
     *  Constant: '<S30>/Constant3'
     *  Logic: '<S30>/Logical Operator1'
     *  RelationalOperator: '<S30>/Relational Operator'
     *  RelationalOperator: '<S30>/Relational Operator1'
     *  RelationalOperator: '<S30>/Relational Operator3'
     */
    if (((localDivide != localDivide) || (localDivide > 3.000000005E+038F)) || (
         -3.000000005E+038F > localDivide)) {
      KnkMgt_facCtRblToil = 0.0F;
    } else {
      KnkMgt_facCtRblToil = localDivide;
    }

    /* end of Outputs for SubSystem: '<S18>/If Action Subsystem3' */

    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S7>/Constant1'
     *  RelationalOperator: '<S24>/UpperRelop'
     */
    if (KnkMgt_facCtRblToil < 0.0F) {
      localSwitch2 = 0.0F;
    } else {
      localSwitch2 = KnkMgt_facCtRblToil;
    }

    /* Switch: '<S24>/Switch2' incorporates:
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S24>/LowerRelop1'
     */
    if (KnkMgt_facCtRblToil > 1.0F) {
      localSwitch2 = 1.0F;
    }

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_nEng, RblPvt_B.VEMS_vidGET1);

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    if (RblPvt_B.VEMS_vidGET1 > 8191) {
      locallocalDataTypeConversion = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion = (UInt16)(RblPvt_B.VEMS_vidGET1 << 3);
    }

    /* PreLookup: '<S13>/Prelookup' */
    localExt_nEng_KnkMgt_nEng_A_9_k = plook_u32u16f_binc
      (locallocalDataTypeConversion, (&(KnkMgt_nEng_A[0])), 8U, &localSum1);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET(EngM_rTotLdExCor, RblPvt_B.VEMS_vidGET);

    /* PreLookup: '<S14>/Prelookup' */
    localExt_pDsThrMesSI_KnkMgt_pDs = plook_u32u16f_binc(RblPvt_B.VEMS_vidGET, (
      &(KnkMgt_rAirLd_A[0])), 8U, &localInterpolationUsingPrelooku);

    /* Interpolation_n-D: '<S11>/Interpolation Using Prelookup3' */
    localDivide = localSum1;
    localfrac[0] = localDivide;
    localDivide = localInterpolationUsingPrelooku;
    localfrac[1] = localDivide;
    localbpIndex[0] = localExt_nEng_KnkMgt_nEng_A_9_k;
    localbpIndex[1] = localExt_pDsThrMesSI_KnkMgt_pDs;
    localAdd2 = intrp2d_iu8ff_u32f_l_s__1(localbpIndex, localfrac,
      (&(KnkMgt_ctTotRblPvtToilL_M[0])), 9U);

    /* Interpolation_n-D: '<S10>/Interpolation Using Prelookup3' */
    localDivide = localSum1;
    localfrac_0[0] = localDivide;
    localDivide = localInterpolationUsingPrelooku;
    localfrac_0[1] = localDivide;
    localbpIndex_0[0] = localExt_nEng_KnkMgt_nEng_A_9_k;
    localbpIndex_0[1] = localExt_pDsThrMesSI_KnkMgt_pDs;
    localInterpolationUsingPrelooku = intrp2d_iu8ff_u32f_l_s__1(localbpIndex_0,
      localfrac_0, (&(KnkMgt_ctTotRblPvtToilH_M[0])), 9U);

    /* Sum: '<S7>/Sum3' */
    localDivide = localInterpolationUsingPrelooku - localAdd2;

    /* Sum: '<S7>/Sum2' incorporates:
     *  Product: '<S7>/Divide'
     */
    localAdd2 += localDivide * localSwitch2;

    /* UnitDelay: '<S20>/Unit Delay' */
    localSwitch2 = RblPvt_DWork.UnitDelay_DSTATE;

    /* Rounding: '<S6>/Rounding Function' */
    if (ACTEMS_FabsF(localAdd2) < 8.388608E+006F) {
      localDivide = (localAdd2 < 0.0F) ? (-((Float32)ACTEMS_FloorF(ACTEMS_FabsF
        (localAdd2) + 0.5F))) : ((Float32)ACTEMS_FloorF(ACTEMS_FabsF(localAdd2)
        + 0.5F));
    } else {
      localDivide = localAdd2;
    }

    localAdd2 = localDivide;

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET4 */
    VEMS_vidGET(InjrSys_mFuInjEstim, RblPvt_B.VEMS_vidGET4);

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/Constant3'
     */
    localRelationalOperator_n = (RblPvt_B.VEMS_vidGET4 > 0);

    /* MinMax: '<S6>/MinMax4' incorporates:
     *  Constant: '<S6>/Constant4'
     */
    localDivide = localAdd2;

    /* Switch: '<S6>/Switch1' */
    if (!localRelationalOperator_n) {
      localAdd2 = rt_MINf(localDivide, 0.0F);
    }

    /* Sum: '<S6>/Sum3' */
    localAdd2 += localSwitch2;

    /* MinMax: '<S6>/MinMax2' incorporates:
     *  Constant: '<S6>/Constant11'
     */
    localmax = rt_MAXf(0.0F, localAdd2);

    /* Sum: '<S16>/Add2' incorporates:
     *  Constant: '<S16>/offset'
     *  Constant: '<S16>/offset1'
     *  Constant: '<S16>/one_on_slope'
     *  Product: '<S16>/Product4'
     *  Sum: '<S16>/Add1'
     */
    localAdd2 = localmax + 0.5F;

    /* DataTypeConversion: '<S16>/OutDTConv' */
    localSwitch2 = localAdd2;
    if (localSwitch2 < 65536.0F) {
      if (localSwitch2 >= 0.0F) {
        KnkMgt_ctTotRblToil = (UInt16)localSwitch2;
      } else {
        KnkMgt_ctTotRblToil = 0U;
      }
    } else {
      KnkMgt_ctTotRblToil = MAX_uint16_T;
    }

    /* If: '<S8>/If' incorporates:
     *  ActionPort: '<S25>/Action Port'
     *  ActionPort: '<S26>/Action Port'
     *  Constant: '<S6>/KnkMgt_ctToilRblIrvLdLimHiThd_C'
     *  Constant: '<S6>/KnkMgt_ctToilRbllrvLdLimLoThd_C'
     *  RelationalOperator: '<S8>/Relational Operator'
     *  RelationalOperator: '<S8>/Relational Operator1'
     *  SubSystem: '<S8>/If Action Subsystem'
     *  SubSystem: '<S8>/If Action Subsystem1'
     */
    if (KnkMgt_ctToilRbllrvLdLimLoThd_C >= KnkMgt_ctTotRblToil) {
      RblPvt_IfActionSubsystem(FALSE, &RblPvt_B.Merge);
    } else {
      if (KnkMgt_ctTotRblToil >= KnkMgt_ctToilRblIrvLdLimHiThd_C) {
        RblPvt_IfActionSubsystem1(TRUE, &RblPvt_B.Merge);
      }
    }

    /* UnitDelay: '<S19>/Unit Delay' */
    localSwitch2 = RblPvt_DWork.UnitDelay_DSTATE_b;

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_pDsThrMesSI, RblPvt_B.VEMS_vidGET2);

    /* PreLookup: '<S15>/Prelookup' */
    localExt_pDsThrMesSI_KnkMgt_pDs = plook_u32u16f_binc(RblPvt_B.VEMS_vidGET2,
      (&(KnkMgt_pDsThrMes_A[0])), 8U, &localAdd2);

    /* Interpolation_n-D: '<S12>/Interpolation Using Prelookup3' */
    localDivide = localSum1;
    localfrac_1[0] = localDivide;
    localDivide = localAdd2;
    localfrac_1[1] = localDivide;
    localbpIndex_1[0] = localExt_nEng_KnkMgt_nEng_A_9_k;
    localbpIndex_1[1] = localExt_pDsThrMesSI_KnkMgt_pDs;
    localSum1 = intrp2d_iu8ff_u32f_l_s__1(localbpIndex_1, localfrac_1,
      (&(KnkMgt_ctTotRblPvtInc_M[0])), 9U);

    /* MinMax: '<S6>/MinMax1' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    localDivide = localSum1;

    /* Switch: '<S6>/Switch' */
    if (!localRelationalOperator_n) {
      localSum1 = rt_MINf(localDivide, 0.0F);
    }

    /* Sum: '<S6>/Sum1' */
    localSum1 += localSwitch2;

    /* MinMax: '<S6>/MinMax3' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    localDivide = rt_MAXf(0.0F, localSum1);

    /* Sum: '<S17>/Add2' incorporates:
     *  Constant: '<S17>/offset'
     *  Constant: '<S17>/offset1'
     *  Constant: '<S17>/one_on_slope'
     *  Product: '<S17>/Product4'
     *  Sum: '<S17>/Add1'
     */
    localAdd2 = localDivide + 0.5F;

    /* DataTypeConversion: '<S17>/OutDTConv' */
    localSwitch2 = localAdd2;
    if (localSwitch2 < 65536.0F) {
      if (localSwitch2 >= 0.0F) {
        KnkMgt_ctTotRblPvtInc = (UInt16)localSwitch2;
      } else {
        KnkMgt_ctTotRblPvtInc = 0U;
      }
    } else {
      KnkMgt_ctTotRblPvtInc = MAX_uint16_T;
    }

    /* If: '<S9>/If' incorporates:
     *  ActionPort: '<S27>/Action Port'
     *  ActionPort: '<S28>/Action Port'
     *  Constant: '<S6>/KnkMgt_ctRblIrvLdLimPvtHiThd_C'
     *  Constant: '<S6>/KnkMgt_ctRbllrvLdLimPvtLoThd_C'
     *  RelationalOperator: '<S9>/Relational Operator'
     *  RelationalOperator: '<S9>/Relational Operator1'
     *  SubSystem: '<S9>/If Action Subsystem'
     *  SubSystem: '<S9>/If Action Subsystem1'
     */
    if (KnkMgt_ctRbllrvLdLimPvtLoThd_C >= KnkMgt_ctTotRblPvtInc) {
      RblPvt_IfActionSubsystem(FALSE, &RblPvt_B.Merge_a);
    } else {
      if (KnkMgt_ctTotRblPvtInc >= KnkMgt_ctRblIrvLdLimPvtHiThd_C) {
        RblPvt_IfActionSubsystem1(TRUE, &RblPvt_B.Merge_a);
      }
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(KnkMgt_bAcvIrvLdLimRblPvtReq, RblPvt_B.Merge_a);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
    VEMS_vidSET(KnkMgt_bAcvIrvLdLimToilReq, RblPvt_B.Merge);

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    RblPvt_DWork.UnitDelay_DSTATE = localmax;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    RblPvt_DWork.UnitDelay_DSTATE_b = localDivide;
  }

  /* end of Outputs for SubSystem: '<S5>/02_RblPvt_calc' */
}

/* Output and update for exported function: KnkTreat_SdlSlow_RblPvt */
void KnkTreat_SdlSlow_RblPvt(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/02_RblPvt_calc'
   */
  RblPvt_u_RblPvt_calc();
}

/* Model initialize function */
void RblPvt_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
}

#define RBLPVT_STOP_SEC_CODE
#include "RblPvt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
