/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuInj                                                  */
/* !Description     : INJECTION MASS PER INJECTION                            */
/*                                                                            */
/* !Module          : mFuInj                                                  */
/*                                                                            */
/* !File            : mFuInj.c                                                */
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
/* !Reference       : PTS_DOC_5141464 / 04                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Jul 18 15:02:19 2013                              */
/*   Model name       : mFuInj_AUTOCODE.mdl                                   */
/*   Model version    : 1.302                                                 */
/*   Root subsystem   : /mFuInj                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUINJ/mFuInj.c_v         $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "mFuInj.h"
#include "mFuInj_private.h"

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
#define MFUINJ_START_SEC_VAR_UNSPECIFIED
#include "mFuInj_MemMap.h"

/* Block signals (auto storage) */
BlockIO_mFuInj mFuInj_B;

/* Block states (auto storage) */
D_Work_mFuInj mFuInj_DWork;

#define MFUINJ_STOP_SEC_VAR_UNSPECIFIED
#include "mFuInj_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define MFUINJ_START_SEC_CODE
#include "mFuInj_MemMap.h"

void mFuInj_ASYNC1(int controlPortIdx)
{
}

void mFuInj_ASYNC2(int controlPortIdx)
{
}

void mFuInj_ASYNC3(int controlPortIdx)
{
  mFuInj_F02_mFuInjCrkClcn();
  mFuInj_F03_mFuInj_SdlSync();
}

/* Output and update for function-call system: '<S5>/F02_mFuInjCrkClcn' */
void mFuInj_F02_mFuInjCrkClcn(void)
{
  Boolean localUnitDelay;
  Boolean localRelationalOperator;
  UInt32 localAdd;
  UInt32 localAdd_p;
  Float32 localDataTypeConversion3;
  UInt16 localSelector;
  UInt16 localSelector_h;
  UInt16 localSelector_l;
  UInt16 localSelector_hy;

  /* Outputs for enable SubSystem: '<S7>/F02_mFuInjCrkClcn' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/MFUINJ_u8Inhib'
   *  EnablePort: '<S17>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (MFUINJ_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET3 */
    VEMS_vidGET(Eng_stEru, mFuInj_B.VEMS_vidGET3_a);

    /* Outputs for enable SubSystem: '<S17>/F01_mFuInjCrkFct' incorporates:
     *  Constant: '<S17>/Ext_stRun_SC'
     *  EnablePort: '<S18>/Enable'
     *  RelationalOperator: '<S17>/Relational Operator4'
     */
    if (mFuInj_B.VEMS_vidGET3_a != Ext_stRun_SC) {
      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET2 */
      VEMS_vidGET(Eng_noInNxtCyl, mFuInj_B.VEMS_vidGET2_b);

      /* UnitDelay: '<S30>/Unit Delay' */
      localUnitDelay = mFuInj_DWork.UnitDelay_DSTATE_n;

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET1 */
      VEMS_vidGET(Eng_noInCyl, mFuInj_B.VEMS_vidGET1_m);

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET4 */
      VEMS_vidGET(InjSys_noInCylStopSTT, mFuInj_B.VEMS_vidGET4_f);

      /* RelationalOperator: '<S18>/Relational Operator' */
      localRelationalOperator = (mFuInj_B.VEMS_vidGET1_m !=
        mFuInj_B.VEMS_vidGET4_f);

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET9 */
      VEMS_vidGET(CoPTSt_stEng, mFuInj_B.VEMS_vidGET9_e);

      /* Logic: '<S24>/Logical Operator1' incorporates:
       *  Constant: '<S18>/Ext_stRun_SC1'
       *  Logic: '<S24>/Logical Operator'
       *  RelationalOperator: '<S18>/Relational Operator1'
       */
      InjSys_bInhSTTSync = !((!((localUnitDelay) || (localRelationalOperator))) ||
                             (mFuInj_B.VEMS_vidGET9_e == 6));

      /* Switch: '<S18>/Switch2' */
      if (InjSys_bInhSTTSync) {
        InjSys_noCylmFuInjCrk = mFuInj_B.VEMS_vidGET2_b;
      } else {
        InjSys_noCylmFuInjCrk = mFuInj_B.VEMS_vidGET4_f;
      }

      /* DataTypeConversion: '<S18>/Data Type Conversion' */
      localAdd = InjSys_noCylmFuInjCrk;

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET10 */
      VEMS_vidGET1DArray(InjSys_prm_rMFuReqLPFu, 6, mFuInj_B.VEMS_vidGET10);

      /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate'
       *
       * Regarding '<S22>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* Sum: '<S22>/Add' incorporates:
       *  Constant: '<S22>/Constant1'
       */
      localAdd_p = localAdd - 1U;

      /* Selector: '<S22>/Selector' incorporates:
       *  Constant: '<S22>/Constant'
       *  MinMax: '<S22>/MinMax'
       */
      localSelector = mFuInj_B.VEMS_vidGET10[rt_MIN(localAdd_p, 5U)];

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET8 */
      VEMS_vidGET1DArray(InjSys_prm_rInjS2ReqCyl, 6, mFuInj_B.VEMS_vidGET8_h);

      /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate'
       *
       * Regarding '<S23>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* Sum: '<S23>/Add' incorporates:
       *  Constant: '<S23>/Constant1'
       */
      localAdd_p = localAdd - 1U;

      /* Selector: '<S23>/Selector' incorporates:
       *  Constant: '<S23>/Constant'
       *  MinMax: '<S23>/MinMax'
       */
      localSelector_h = mFuInj_B.VEMS_vidGET8_h[rt_MIN(localAdd_p, 5U)];

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET6 */
      VEMS_vidGET(InjSys_mFuCrkSp, mFuInj_B.VEMS_vidGET6);

      /* DataTypeConversion: '<S18>/Data Type Conversion3' */
      localDataTypeConversion3 = ((Float32)mFuInj_B.VEMS_vidGET6) *
        7.450580597E-009F;

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET3 */
      VEMS_vidGET1DArray(InjSys_prm_rInjH1ReqCyl, 6, mFuInj_B.VEMS_vidGET3_o);

      /* DataTypeDuplicate Block: '<S19>/Data Type Duplicate'
       *
       * Regarding '<S19>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* Sum: '<S19>/Add' incorporates:
       *  Constant: '<S19>/Constant1'
       */
      localAdd_p = localAdd - 1U;

      /* Selector: '<S19>/Selector' incorporates:
       *  Constant: '<S19>/Constant'
       *  MinMax: '<S19>/MinMax'
       */
      localSelector_l = mFuInj_B.VEMS_vidGET3_o[rt_MIN(localAdd_p, 5U)];

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET5 */
      VEMS_vidGET1DArray(InjSys_prm_rInjH2ReqCyl, 6, mFuInj_B.VEMS_vidGET5_i);

      /* DataTypeDuplicate Block: '<S20>/Data Type Duplicate'
       *
       * Regarding '<S20>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* Sum: '<S20>/Add' incorporates:
       *  Constant: '<S20>/Constant1'
       */
      localAdd_p = localAdd - 1U;

      /* Selector: '<S20>/Selector' incorporates:
       *  Constant: '<S20>/Constant'
       *  MinMax: '<S20>/MinMax'
       */
      localSelector_hy = mFuInj_B.VEMS_vidGET5_i[rt_MIN(localAdd_p, 5U)];

      /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET7 */
      VEMS_vidGET1DArray(InjSys_prm_rInjS1ReqCyl, 6, mFuInj_B.VEMS_vidGET7_n);

      /* DataTypeDuplicate Block: '<S21>/Data Type Duplicate'
       *
       * Regarding '<S21>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* Sum: '<S21>/Add' incorporates:
       *  Constant: '<S21>/Constant1'
       */
      localAdd--;

      /* Product: '<S25>/Divide' incorporates:
       *  DataTypeConversion: '<S18>/Data Type Conversion1'
       */
      localDataTypeConversion3 *= ((Float32)localSelector) * 3.051757813E-005F;

      /* Product: '<S26>/Divide' incorporates:
       *  DataTypeConversion: '<S18>/Data Type Conversion7'
       */
      InjSys_mFuInjH1CrkReq = (((Float32)localSelector_l) * 3.051757813E-005F) *
        localDataTypeConversion3;

      /* Product: '<S27>/Divide' incorporates:
       *  DataTypeConversion: '<S18>/Data Type Conversion8'
       */
      InjSys_mFuInjH2CrkReq = (((Float32)localSelector_hy) * 3.051757813E-005F)
        * localDataTypeConversion3;

      /* Product: '<S28>/Divide' incorporates:
       *  Constant: '<S21>/Constant'
       *  DataTypeConversion: '<S18>/Data Type Conversion9'
       *  MinMax: '<S21>/MinMax'
       *  Selector: '<S21>/Selector'
       */
      InjSys_mFuInjS1CrkReq = (((Float32)mFuInj_B.VEMS_vidGET7_n[rt_MIN
        (localAdd, 5U)]) * 3.051757813E-005F) * localDataTypeConversion3;

      /* Product: '<S29>/Divide' incorporates:
       *  DataTypeConversion: '<S18>/Data Type Conversion10'
       */
      InjSys_mFuInjS2CrkReq = (((Float32)localSelector_h) * 3.051757813E-005F) *
        localDataTypeConversion3;

      /* Update for UnitDelay: '<S30>/Unit Delay' */
      mFuInj_DWork.UnitDelay_DSTATE_n = InjSys_bInhSTTSync;
    }

    /* end of Outputs for SubSystem: '<S17>/F01_mFuInjCrkFct' */
  }

  /* end of Outputs for SubSystem: '<S7>/F02_mFuInjCrkClcn' */
}

/* Output and update for function-call system: '<S8>/F03_mFuInj_SdlSync' */
void mFuInj_F03_mFuInj_SdlSync(void)
{
  UInt32 localAdd_o;
  UInt32 localAdd_i;
  UInt32 localAdd_e;
  UInt32 localAdd_pg;
  Boolean localRelationalOperator6;
  Boolean localLogicalOperator1;
  UInt32 localAdd_l;
  UInt16 localSwitch3[6];
  UInt16 localAssignment[6];
  UInt16 localAssignment_h[6];
  UInt16 localSwitch10[6];
  UInt16 localAssignment_p[6];
  UInt16 localSwitch12[6];
  UInt16 localAssignment_o[6];
  UInt16 localSwitch19[6];
  Boolean localRelationalOperator_0;
  SInt32 locali;
  UInt16 locallocalSwitch;
  UInt16 locallocalSwitch_0;
  Float32 localtmp;
  UInt16 locallocalOutDTConv_idx;
  UInt16 locallocalOutDTConv_idx_0;

  /* RelationalOperator: '<S33>/Relational Operator' incorporates:
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S33>/MFUINJ_u8Inhib'
   */
  localRelationalOperator_0 = (MFUINJ_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S33>/F03_mFuInj_SdlSync' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  if (localRelationalOperator_0) {
    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, mFuInj_B.VEMS_vidGET1_j);

    /* DataTypeConversion: '<S52>/Data Type Conversion1' */
    localAdd_o = mFuInj_B.VEMS_vidGET1_j;

    /* Sum: '<S53>/Add' incorporates:
     *  Constant: '<S53>/Constant1'
     */
    localAdd_pg = localAdd_o - 1U;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, mFuInj_B.VEMS_vidGET8);

    /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate'
     *
     * Regarding '<S61>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate1'
     *
     * Regarding '<S61>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S69>/Data Type Duplicate'
     *
     * Regarding '<S69>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S76>/OutDTConv' incorporates:
     *  Constant: '<S76>/offset'
     *  Constant: '<S76>/offset1'
     *  Constant: '<S76>/one_on_slope'
     *  Product: '<S76>/Product4'
     *  Sum: '<S76>/Add1'
     *  Sum: '<S76>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjH1Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjH1Req[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_idx_0 = MAX_uint16_T;
    }

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_noInNxtCyl, mFuInj_B.VEMS_vidGET2_k);

    /* DataTypeConversion: '<S52>/Data Type Conversion5' */
    localAdd_i = mFuInj_B.VEMS_vidGET2_k;

    /* Sum: '<S61>/Add' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    localAdd_e = localAdd_i - 1U;

    /* Assignment: '<S61>/Assignment' incorporates:
     *  Constant: '<S61>/Constant'
     *  MinMax: '<S61>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localSwitch3[locali] = mFuInj_B.VEMS_vidGET8[(locali)];
    }

    localSwitch3[(SInt32)rt_MIN(localAdd_e, 5U)] = locallocalOutDTConv_idx;

    /* Sum: '<S69>/Add' incorporates:
     *  Constant: '<S69>/Constant1'
     */
    localAdd_e = localAdd_o - 1U;

    /* Switch: '<S52>/Switch4' incorporates:
     *  Constant: '<S52>/Constant28'
     *  Constant: '<S52>/Constant4'
     *  Constant: '<S69>/Constant'
     *  MinMax: '<S69>/MinMax'
     *  RelationalOperator: '<S52>/Relational Operator'
     *  Selector: '<S69>/Selector'
     */
    if (mFuInj_B.VEMS_vidGET8[rt_MIN(localAdd_e, 5U)] == 0) {
      locallocalOutDTConv_idx_0 = 0U;
    }

    /* Assignment: '<S53>/Assignment' incorporates:
     *  Constant: '<S53>/Constant'
     *  MinMax: '<S53>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch3[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_pg, 5U)] =
      locallocalOutDTConv_idx_0;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, mFuInj_B.VEMS_vidGET_h);

    /* DataTypeConversion: '<S52>/Data Type Conversion2' */
    localAdd_e = mFuInj_B.VEMS_vidGET_h;

    /* Sum: '<S54>/Add' incorporates:
     *  Constant: '<S54>/Constant1'
     */
    localAdd_pg = localAdd_e - 1U;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_noInjPat, mFuInj_B.VEMS_vidGET4_l);

    /* Logic: '<S52>/Logical Operator8' incorporates:
     *  Constant: '<S52>/Constant29'
     *  RelationalOperator: '<S52>/Relational Operator12'
     *  UnitDelay: '<S81>/Unit Delay'
     */
    InjSys_bInjPatCond = ((mFuInj_B.VEMS_vidGET4_l !=
      mFuInj_DWork.UnitDelay_DSTATE) && InjSys_bAcvInjPatcond_C);

    /* Switch: '<S52>/Switch29' */
    for (locali = 0; locali < 6; locali++) {
      if (!InjSys_bInjPatCond) {
        localSwitch3[locali] = localAssignment[locali];
      }
    }

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET3 */
    VEMS_vidGET(Eng_stEru, mFuInj_B.VEMS_vidGET3_e);

    /* RelationalOperator: '<S52>/Relational Operator6' incorporates:
     *  Constant: '<S52>/Ext_stRun_SC1'
     */
    localRelationalOperator6 = (Ext_stRun_SC == mFuInj_B.VEMS_vidGET3_e);

    /* DataTypeConversion: '<S77>/OutDTConv' incorporates:
     *  Constant: '<S77>/offset'
     *  Constant: '<S77>/offset1'
     *  Constant: '<S77>/one_on_slope'
     *  Product: '<S77>/Product4'
     *  Sum: '<S77>/Add1'
     *  Sum: '<S77>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjH1CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    /* Switch: '<S52>/Switch9' */
    if (!localRelationalOperator6) {
      localSwitch3[0] = locallocalOutDTConv_idx;
      localSwitch3[1] = locallocalOutDTConv_idx;
      localSwitch3[2] = locallocalOutDTConv_idx;
      localSwitch3[3] = locallocalOutDTConv_idx;
      localSwitch3[4] = locallocalOutDTConv_idx;
      localSwitch3[5] = locallocalOutDTConv_idx;
    }

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_bInhFrstInjSTT, 2, mFuInj_B.VEMS_vidGET6_p);

    /* SignalConversion: '<S52>/Signal Conversion4' */
    InjSys_bInhFrstInjSTTInCyl = mFuInj_B.VEMS_vidGET6_p[0];

    /* Logic: '<S52>/Logical Operator3' */
    localLogicalOperator1 = !InjSys_bInhFrstInjSTTInCyl;

    /* Sum: '<S68>/Add' incorporates:
     *  Constant: '<S68>/Constant1'
     */
    localAdd_l = localAdd_o - 1U;

    /* Assignment: '<S68>/Assignment' incorporates:
     *  Constant: '<S52>/Constant17'
     *  Constant: '<S68>/Constant'
     *  MinMax: '<S68>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch3[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_l, 5U)] = 0U;

    /* Assignment: '<S54>/Assignment' incorporates:
     *  Constant: '<S52>/Constant18'
     *  Constant: '<S54>/Constant'
     *  MinMax: '<S54>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_idx = localSwitch3[locali];

      /* Switch: '<S52>/Switch15' */
      if (!localLogicalOperator1) {
        locallocalOutDTConv_idx = localAssignment[locali];
      }

      localAssignment_h[locali] = locallocalOutDTConv_idx;
      localSwitch3[locali] = locallocalOutDTConv_idx;
    }

    localAssignment_h[(SInt32)rt_MIN(localAdd_pg, 5U)] = 0U;

    /* Sum: '<S55>/Add' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    localAdd_l = localAdd_e - 1U;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, mFuInj_B.VEMS_vidGET9);

    /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate'
     *
     * Regarding '<S62>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate1'
     *
     * Regarding '<S62>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S70>/Data Type Duplicate'
     *
     * Regarding '<S70>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S75>/OutDTConv' incorporates:
     *  Constant: '<S75>/offset'
     *  Constant: '<S75>/offset1'
     *  Constant: '<S75>/one_on_slope'
     *  Product: '<S75>/Product4'
     *  Sum: '<S75>/Add1'
     *  Sum: '<S75>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjH2Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjH2Req[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_idx_0 = MAX_uint16_T;
    }

    /* Sum: '<S62>/Add' incorporates:
     *  Constant: '<S62>/Constant1'
     */
    localAdd_pg = localAdd_i - 1U;

    /* Assignment: '<S62>/Assignment' incorporates:
     *  Constant: '<S62>/Constant'
     *  MinMax: '<S62>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localSwitch10[locali] = mFuInj_B.VEMS_vidGET9[(locali)];
    }

    localSwitch10[(SInt32)rt_MIN(localAdd_pg, 5U)] = locallocalOutDTConv_idx;

    /* Sum: '<S70>/Add' incorporates:
     *  Constant: '<S70>/Constant1'
     */
    localAdd_pg = localAdd_o - 1U;

    /* Switch: '<S52>/Switch5' incorporates:
     *  Constant: '<S52>/Constant27'
     *  Constant: '<S52>/Constant5'
     *  Constant: '<S70>/Constant'
     *  MinMax: '<S70>/MinMax'
     *  RelationalOperator: '<S52>/Relational Operator1'
     *  Selector: '<S70>/Selector'
     */
    if (mFuInj_B.VEMS_vidGET9[rt_MIN(localAdd_pg, 5U)] == 0) {
      locallocalOutDTConv_idx_0 = 0U;
    }

    /* Sum: '<S63>/Add' incorporates:
     *  Constant: '<S63>/Constant1'
     */
    localAdd_pg = localAdd_o - 1U;

    /* Assignment: '<S63>/Assignment' incorporates:
     *  Constant: '<S63>/Constant'
     *  MinMax: '<S63>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch10[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_pg, 5U)] =
      locallocalOutDTConv_idx_0;

    /* Switch: '<S52>/Switch30' */
    for (locali = 0; locali < 6; locali++) {
      if (!InjSys_bInjPatCond) {
        localSwitch10[locali] = localAssignment[locali];
      }
    }

    /* DataTypeConversion: '<S78>/OutDTConv' incorporates:
     *  Constant: '<S78>/offset'
     *  Constant: '<S78>/offset1'
     *  Constant: '<S78>/one_on_slope'
     *  Product: '<S78>/Product4'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjH2CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    /* Switch: '<S52>/Switch17' */
    if (!localRelationalOperator6) {
      localSwitch10[0] = locallocalOutDTConv_idx;
      localSwitch10[1] = locallocalOutDTConv_idx;
      localSwitch10[2] = locallocalOutDTConv_idx;
      localSwitch10[3] = locallocalOutDTConv_idx;
      localSwitch10[4] = locallocalOutDTConv_idx;
      localSwitch10[5] = locallocalOutDTConv_idx;
    }

    /* Sum: '<S56>/Add' incorporates:
     *  Constant: '<S56>/Constant1'
     */
    localAdd_pg = localAdd_o - 1U;

    /* Assignment: '<S56>/Assignment' incorporates:
     *  Constant: '<S52>/Constant19'
     *  Constant: '<S56>/Constant'
     *  MinMax: '<S56>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch10[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_pg, 5U)] = 0U;

    /* Assignment: '<S55>/Assignment' incorporates:
     *  Constant: '<S52>/Constant20'
     *  Constant: '<S55>/Constant'
     *  MinMax: '<S55>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_idx = localSwitch10[locali];

      /* Switch: '<S52>/Switch23' */
      if (!localLogicalOperator1) {
        locallocalOutDTConv_idx = localAssignment[locali];
      }

      localAssignment_p[locali] = locallocalOutDTConv_idx;
      localSwitch10[locali] = locallocalOutDTConv_idx;
    }

    localAssignment_p[(SInt32)rt_MIN(localAdd_l, 5U)] = 0U;

    /* Sum: '<S57>/Add' incorporates:
     *  Constant: '<S57>/Constant1'
     */
    localAdd_l = localAdd_e - 1U;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, mFuInj_B.VEMS_vidGET11);

    /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate'
     *
     * Regarding '<S64>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate1'
     *
     * Regarding '<S64>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S71>/Data Type Duplicate'
     *
     * Regarding '<S71>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S73>/OutDTConv' incorporates:
     *  Constant: '<S73>/offset'
     *  Constant: '<S73>/offset1'
     *  Constant: '<S73>/one_on_slope'
     *  Product: '<S73>/Product4'
     *  Sum: '<S73>/Add1'
     *  Sum: '<S73>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjS1Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjS1Req[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_idx_0 = MAX_uint16_T;
    }

    /* Sum: '<S64>/Add' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    localAdd_pg = localAdd_i - 1U;

    /* Assignment: '<S64>/Assignment' incorporates:
     *  Constant: '<S64>/Constant'
     *  MinMax: '<S64>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localSwitch12[locali] = mFuInj_B.VEMS_vidGET11[(locali)];
    }

    localSwitch12[(SInt32)rt_MIN(localAdd_pg, 5U)] = locallocalOutDTConv_idx;

    /* Sum: '<S71>/Add' incorporates:
     *  Constant: '<S71>/Constant1'
     */
    localAdd_pg = localAdd_o - 1U;

    /* Switch: '<S52>/Switch6' incorporates:
     *  Constant: '<S52>/Constant26'
     *  Constant: '<S52>/Constant6'
     *  Constant: '<S71>/Constant'
     *  MinMax: '<S71>/MinMax'
     *  RelationalOperator: '<S52>/Relational Operator2'
     *  Selector: '<S71>/Selector'
     */
    if (mFuInj_B.VEMS_vidGET11[rt_MIN(localAdd_pg, 5U)] == 0) {
      locallocalOutDTConv_idx_0 = 0U;
    }

    /* Sum: '<S65>/Add' incorporates:
     *  Constant: '<S65>/Constant1'
     */
    localAdd_pg = localAdd_o - 1U;

    /* Assignment: '<S65>/Assignment' incorporates:
     *  Constant: '<S65>/Constant'
     *  MinMax: '<S65>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch12[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_pg, 5U)] =
      locallocalOutDTConv_idx_0;

    /* Switch: '<S52>/Switch31' */
    for (locali = 0; locali < 6; locali++) {
      if (!InjSys_bInjPatCond) {
        localSwitch12[locali] = localAssignment[locali];
      }
    }

    /* DataTypeConversion: '<S79>/OutDTConv' incorporates:
     *  Constant: '<S79>/offset'
     *  Constant: '<S79>/offset1'
     *  Constant: '<S79>/one_on_slope'
     *  Product: '<S79>/Product4'
     *  Sum: '<S79>/Add1'
     *  Sum: '<S79>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjS1CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    /* Switch: '<S52>/Switch18' */
    if (!localRelationalOperator6) {
      localSwitch12[0] = locallocalOutDTConv_idx;
      localSwitch12[1] = locallocalOutDTConv_idx;
      localSwitch12[2] = locallocalOutDTConv_idx;
      localSwitch12[3] = locallocalOutDTConv_idx;
      localSwitch12[4] = locallocalOutDTConv_idx;
      localSwitch12[5] = locallocalOutDTConv_idx;
    }

    /* Sum: '<S58>/Add' incorporates:
     *  Constant: '<S58>/Constant1'
     */
    localAdd_pg = localAdd_o - 1U;

    /* Assignment: '<S58>/Assignment' incorporates:
     *  Constant: '<S52>/Constant21'
     *  Constant: '<S58>/Constant'
     *  MinMax: '<S58>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch12[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_pg, 5U)] = 0U;

    /* Assignment: '<S57>/Assignment' incorporates:
     *  Constant: '<S52>/Constant22'
     *  Constant: '<S57>/Constant'
     *  MinMax: '<S57>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_idx = localSwitch12[locali];

      /* Switch: '<S52>/Switch25' */
      if (!localLogicalOperator1) {
        locallocalOutDTConv_idx = localAssignment[locali];
      }

      localAssignment_o[locali] = locallocalOutDTConv_idx;
      localSwitch12[locali] = locallocalOutDTConv_idx;
    }

    localAssignment_o[(SInt32)rt_MIN(localAdd_l, 5U)] = 0U;

    /* Sum: '<S59>/Add' incorporates:
     *  Constant: '<S59>/Constant1'
     */
    localAdd_e--;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, mFuInj_B.VEMS_vidGET12);

    /* DataTypeDuplicate Block: '<S66>/Data Type Duplicate'
     *
     * Regarding '<S66>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S66>/Data Type Duplicate1'
     *
     * Regarding '<S66>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S72>/Data Type Duplicate'
     *
     * Regarding '<S72>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S74>/OutDTConv' incorporates:
     *  Constant: '<S74>/offset'
     *  Constant: '<S74>/offset1'
     *  Constant: '<S74>/one_on_slope'
     *  Product: '<S74>/Product4'
     *  Sum: '<S74>/Add1'
     *  Sum: '<S74>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjS2Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjS2Req[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_idx_0 = MAX_uint16_T;
    }

    /* Sum: '<S66>/Add' incorporates:
     *  Constant: '<S66>/Constant1'
     */
    localAdd_i--;

    /* Assignment: '<S66>/Assignment' incorporates:
     *  Constant: '<S66>/Constant'
     *  MinMax: '<S66>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localSwitch19[locali] = mFuInj_B.VEMS_vidGET12[(locali)];
    }

    localSwitch19[(SInt32)rt_MIN(localAdd_i, 5U)] = locallocalOutDTConv_idx;

    /* Sum: '<S72>/Add' incorporates:
     *  Constant: '<S72>/Constant1'
     */
    localAdd_l = localAdd_o - 1U;

    /* Switch: '<S52>/Switch7' incorporates:
     *  Constant: '<S52>/Constant25'
     *  Constant: '<S52>/Constant7'
     *  Constant: '<S72>/Constant'
     *  MinMax: '<S72>/MinMax'
     *  RelationalOperator: '<S52>/Relational Operator3'
     *  Selector: '<S72>/Selector'
     */
    if (mFuInj_B.VEMS_vidGET12[rt_MIN(localAdd_l, 5U)] == 0) {
      locallocalOutDTConv_idx_0 = 0U;
    }

    /* Sum: '<S67>/Add' incorporates:
     *  Constant: '<S67>/Constant1'
     */
    localAdd_l = localAdd_o - 1U;

    /* Assignment: '<S67>/Assignment' incorporates:
     *  Constant: '<S67>/Constant'
     *  MinMax: '<S67>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch19[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_l, 5U)] = locallocalOutDTConv_idx_0;

    /* Switch: '<S52>/Switch32' */
    for (locali = 0; locali < 6; locali++) {
      if (!InjSys_bInjPatCond) {
        localSwitch19[locali] = localAssignment[locali];
      }
    }

    /* DataTypeConversion: '<S80>/OutDTConv' incorporates:
     *  Constant: '<S80>/offset'
     *  Constant: '<S80>/offset1'
     *  Constant: '<S80>/one_on_slope'
     *  Product: '<S80>/Product4'
     *  Sum: '<S80>/Add1'
     *  Sum: '<S80>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjS2CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    /* Switch: '<S52>/Switch21' */
    if (!localRelationalOperator6) {
      localSwitch19[0] = locallocalOutDTConv_idx;
      localSwitch19[1] = locallocalOutDTConv_idx;
      localSwitch19[2] = locallocalOutDTConv_idx;
      localSwitch19[3] = locallocalOutDTConv_idx;
      localSwitch19[4] = locallocalOutDTConv_idx;
      localSwitch19[5] = locallocalOutDTConv_idx;
    }

    /* Sum: '<S60>/Add' incorporates:
     *  Constant: '<S60>/Constant1'
     */
    localAdd_o--;

    /* Assignment: '<S60>/Assignment' incorporates:
     *  Constant: '<S52>/Constant23'
     *  Constant: '<S60>/Constant'
     *  MinMax: '<S60>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch19[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_o, 5U)] = 0U;

    /* Assignment: '<S59>/Assignment' incorporates:
     *  Constant: '<S52>/Constant24'
     *  Constant: '<S59>/Constant'
     *  MinMax: '<S59>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_idx = localSwitch19[locali];

      /* Switch: '<S52>/Switch27' */
      if (!localLogicalOperator1) {
        locallocalOutDTConv_idx = localAssignment[locali];
      }

      localSwitch19[locali] = locallocalOutDTConv_idx;
      localAssignment[locali] = locallocalOutDTConv_idx;
    }

    localAssignment[(SInt32)rt_MIN(localAdd_e, 5U)] = 0U;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET10 */
    VEMS_vidGET(Moteur_tournant, mFuInj_B.VEMS_vidGET10_j);

    /* Logic: '<S52>/Logical Operator' */
    InjSys_bEngStall = !mFuInj_B.VEMS_vidGET10_j;

    /* SignalConversion: '<S52>/Signal Conversion1' */
    InjSys_bInhFrstInjSTTCmprCyl = mFuInj_B.VEMS_vidGET6_p[1];

    /* Logic: '<S52>/Logical Operator1' */
    localLogicalOperator1 = !InjSys_bInhFrstInjSTTCmprCyl;

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_bCylCutOff, 6, mFuInj_B.VEMS_vidGET5_e);

    /* S-Function "vems_vidGET" Block: <S52>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_bInhInjHPstCyl, 6, mFuInj_B.VEMS_vidGET7_p);
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_idx = localSwitch10[locali];
      locallocalOutDTConv_idx_0 = localSwitch12[locali];
      locallocalSwitch_0 = localSwitch19[locali];
      locallocalSwitch = localSwitch3[locali];

      /* Switch: '<S52>/Switch24' */
      if (!localLogicalOperator1) {
        locallocalOutDTConv_idx = localAssignment_p[locali];
      }

      /* Switch: '<S52>/Switch16' incorporates:
       *  Constant: '<S52>/Constant12'
       */
      if (InjSys_bEngStall) {
        locallocalOutDTConv_idx = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S52>/Switch10' incorporates:
       *  Constant: '<S52>/Constant9'
       */
      if (mFuInj_B.VEMS_vidGET7_p[(locali)]) {
        locallocalOutDTConv_idx = 0U;
      }

      /* Switch: '<S52>/Switch1' incorporates:
       *  Constant: '<S52>/Constant1'
       */
      if (mFuInj_B.VEMS_vidGET5_e[(locali)]) {
        mFuInj_B.Switch1_m[(locali)] = 0U;
      } else {
        mFuInj_B.Switch1_m[(locali)] = locallocalOutDTConv_idx;
      }

      /* Switch: '<S52>/Switch26' */
      if (!localLogicalOperator1) {
        locallocalOutDTConv_idx_0 = localAssignment_o[locali];
      }

      /* Switch: '<S52>/Switch13' incorporates:
       *  Constant: '<S52>/Constant11'
       */
      if (InjSys_bEngStall) {
        locallocalOutDTConv_idx_0 = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S52>/Switch12' incorporates:
       *  Constant: '<S52>/Constant13'
       */
      if (mFuInj_B.VEMS_vidGET7_p[(locali)]) {
        locallocalOutDTConv_idx_0 = 0U;
      }

      /* Switch: '<S52>/Switch11' incorporates:
       *  Constant: '<S52>/Constant10'
       */
      if (mFuInj_B.VEMS_vidGET5_e[(locali)]) {
        mFuInj_B.Switch11_a[(locali)] = 0U;
      } else {
        mFuInj_B.Switch11_a[(locali)] = locallocalOutDTConv_idx_0;
      }

      /* Switch: '<S52>/Switch28' */
      if (!localLogicalOperator1) {
        locallocalSwitch_0 = localAssignment[locali];
      }

      /* Switch: '<S52>/Switch20' incorporates:
       *  Constant: '<S52>/Constant15'
       */
      if (InjSys_bEngStall) {
        locallocalSwitch_0 = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S52>/Switch19' incorporates:
       *  Constant: '<S52>/Constant16'
       */
      if (mFuInj_B.VEMS_vidGET7_p[(locali)]) {
        locallocalSwitch_0 = 0U;
      }

      /* Switch: '<S52>/Switch14' incorporates:
       *  Constant: '<S52>/Constant14'
       */
      if (mFuInj_B.VEMS_vidGET5_e[(locali)]) {
        mFuInj_B.Switch14_c[(locali)] = 0U;
      } else {
        mFuInj_B.Switch14_c[(locali)] = locallocalSwitch_0;
      }

      /* Switch: '<S52>/Switch22' */
      if (!localLogicalOperator1) {
        locallocalSwitch = localAssignment_h[locali];
      }

      /* Switch: '<S52>/Switch8' incorporates:
       *  Constant: '<S52>/Constant3'
       */
      if (InjSys_bEngStall) {
        locallocalSwitch = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S52>/Switch3' incorporates:
       *  Constant: '<S52>/Constant8'
       */
      if (mFuInj_B.VEMS_vidGET7_p[(locali)]) {
        locallocalSwitch = 0U;
      }

      /* Switch: '<S52>/Switch2' incorporates:
       *  Constant: '<S52>/Constant2'
       */
      if (mFuInj_B.VEMS_vidGET5_e[(locali)]) {
        mFuInj_B.Switch2_j[(locali)] = 0U;
      } else {
        mFuInj_B.Switch2_j[(locali)] = locallocalSwitch;
      }
    }

    /* S-Function "vems_vidSET" Block: <S52>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, mFuInj_B.Switch2_j);

    /* S-Function "vems_vidSET" Block: <S52>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, mFuInj_B.Switch1_m);

    /* S-Function "vems_vidSET" Block: <S52>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, mFuInj_B.Switch11_a);

    /* S-Function "vems_vidSET" Block: <S52>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, mFuInj_B.Switch14_c);
  }

  /* end of Outputs for SubSystem: '<S33>/F03_mFuInj_SdlSync' */

  /* Update for enable SubSystem: '<S33>/F03_mFuInj_SdlSync' incorporates:
   *  Update for EnablePort: '<S52>/Enable'
   */
  if (localRelationalOperator_0) {
    /* Update for UnitDelay: '<S81>/Unit Delay' */
    mFuInj_DWork.UnitDelay_DSTATE = mFuInj_B.VEMS_vidGET4_l;
  }

  /* end of Update for SubSystem: '<S33>/F03_mFuInj_SdlSync' */
}

/* Start for exported function: InjSys_EveCkSnNtAc_mFuInj */
void InjSys_EveCkSnNtAc_mFuInj_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S5>/mFuInj_fc_demux_1'
   */
}

/* Output and update for exported function: InjSys_EveCkSnNtAc_mFuInj */
void InjSys_EveCkSnNtAc_mFuInj(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S5>/mFuInj_fc_demux_1'
   */

  /* S-Function (fcncallgen): '<S10>/Function-Call Generator' */
  mFuInj_ASYNC3(0);
}

/* Output and update for function-call system: '<S8>/F02_mFuInj_EveSync' */
void mFuInj_F02_mFuInj_EveSync(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_ef;
  UInt32 localAdd_lf;
  UInt32 localAdd_k;
  Boolean localRelationalOperator6_k;
  Boolean localRelationalOperator7;
  SInt32 localmin;
  SInt32 localmin_0;
  UInt16 localAssignment_nm[6];
  UInt16 localAssignment_g[6];
  UInt16 localAssignment_i[6];
  UInt16 localAssignment_f[6];
  SInt32 locali;
  Float32 localtmp;
  UInt16 locallocalOutDTConv_l;
  UInt16 locallocalSelector_m;
  UInt16 locallocalSelector_o;
  UInt16 locallocalSelector_i;

  /* RelationalOperator: '<S32>/Relational Operator' incorporates:
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S32>/MFUINJ_u8Inhib'
   */
  localRelationalOperator_ef = (MFUINJ_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S32>/F02_mFuInj_EveSync' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  if (localRelationalOperator_ef) {
    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_noInNxtNxtCyl, mFuInj_B.VEMS_vidGET2_l);

    /* DataTypeConversion: '<S34>/Data Type Conversion3' */
    localAdd_lf = mFuInj_B.VEMS_vidGET2_l;

    /* Sum: '<S35>/Add' incorporates:
     *  Constant: '<S35>/Constant1'
     */
    localAdd_k = localAdd_lf - 1U;

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6,
                       InjSys_prm_mFuInjH1ReqCylPre);

    /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate'
     *
     * Regarding '<S35>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate1'
     *
     * Regarding '<S35>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S47>/OutDTConv' incorporates:
     *  Constant: '<S47>/offset'
     *  Constant: '<S47>/offset1'
     *  Constant: '<S47>/one_on_slope'
     *  Product: '<S47>/Product4'
     *  Sum: '<S47>/Add1'
     *  Sum: '<S47>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjH1Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_l = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_l = 0U;
      }
    } else {
      locallocalOutDTConv_l = MAX_uint16_T;
    }

    /* Assignment: '<S35>/Assignment' incorporates:
     *  Constant: '<S35>/Constant'
     *  MinMax: '<S35>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_nm[locali] = InjSys_prm_mFuInjH1ReqCylPre[(locali)];
    }

    localAssignment_nm[(SInt32)rt_MIN(localAdd_k, 5U)] = locallocalOutDTConv_l;

    /* Sum: '<S36>/Add' incorporates:
     *  Constant: '<S36>/Constant1'
     */
    localAdd_k = localAdd_lf - 1U;

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6,
                       InjSys_prm_mFuInjH2ReqCylPre);

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate'
     *
     * Regarding '<S36>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate1'
     *
     * Regarding '<S36>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S46>/OutDTConv' incorporates:
     *  Constant: '<S46>/offset'
     *  Constant: '<S46>/offset1'
     *  Constant: '<S46>/one_on_slope'
     *  Product: '<S46>/Product4'
     *  Sum: '<S46>/Add1'
     *  Sum: '<S46>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjH2Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalSelector_m = (UInt16)localtmp;
      } else {
        locallocalSelector_m = 0U;
      }
    } else {
      locallocalSelector_m = MAX_uint16_T;
    }

    /* Assignment: '<S36>/Assignment' incorporates:
     *  Constant: '<S36>/Constant'
     *  MinMax: '<S36>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_g[locali] = InjSys_prm_mFuInjH2ReqCylPre[(locali)];
    }

    localAssignment_g[(SInt32)rt_MIN(localAdd_k, 5U)] = locallocalSelector_m;

    /* Sum: '<S37>/Add' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    localAdd_k = localAdd_lf - 1U;

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6,
                       InjSys_prm_mFuInjS1ReqCylPre);

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate'
     *
     * Regarding '<S37>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate1'
     *
     * Regarding '<S37>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S45>/OutDTConv' incorporates:
     *  Constant: '<S45>/offset'
     *  Constant: '<S45>/offset1'
     *  Constant: '<S45>/one_on_slope'
     *  Product: '<S45>/Product4'
     *  Sum: '<S45>/Add1'
     *  Sum: '<S45>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjS1Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalSelector_o = (UInt16)localtmp;
      } else {
        locallocalSelector_o = 0U;
      }
    } else {
      locallocalSelector_o = MAX_uint16_T;
    }

    /* Assignment: '<S37>/Assignment' incorporates:
     *  Constant: '<S37>/Constant'
     *  MinMax: '<S37>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_i[locali] = InjSys_prm_mFuInjS1ReqCylPre[(locali)];
    }

    localAssignment_i[(SInt32)rt_MIN(localAdd_k, 5U)] = locallocalSelector_o;

    /* Sum: '<S38>/Add' incorporates:
     *  Constant: '<S38>/Constant1'
     */
    localAdd_lf--;

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6,
                       InjSys_prm_mFuInjS2ReqCylPre);

    /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate'
     *
     * Regarding '<S38>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate1'
     *
     * Regarding '<S38>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S43>/OutDTConv' incorporates:
     *  Constant: '<S43>/offset'
     *  Constant: '<S43>/offset1'
     *  Constant: '<S43>/one_on_slope'
     *  Product: '<S43>/Product4'
     *  Sum: '<S43>/Add1'
     *  Sum: '<S43>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuInjS2Req[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalSelector_i = (UInt16)localtmp;
      } else {
        locallocalSelector_i = 0U;
      }
    } else {
      locallocalSelector_i = MAX_uint16_T;
    }

    /* Assignment: '<S38>/Assignment' incorporates:
     *  Constant: '<S38>/Constant'
     *  MinMax: '<S38>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_f[locali] = InjSys_prm_mFuInjS2ReqCylPre[(locali)];
    }

    localAssignment_f[(SInt32)rt_MIN(localAdd_lf, 5U)] = locallocalSelector_i;

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, mFuInj_B.VEMS_vidGET1_o);

    /* DataTypeConversion: '<S34>/Data Type Conversion2' */
    localAdd_k = mFuInj_B.VEMS_vidGET1_o;

    /* RelationalOperator: '<S34>/Relational Operator1' incorporates:
     *  Constant: '<S34>/Constant4'
     */
    InjSys_bMFuH1SpNull = (0 == locallocalOutDTConv_l);

    /* RelationalOperator: '<S34>/Relational Operator2' incorporates:
     *  Constant: '<S34>/Constant5'
     */
    InjSys_bMFuH2SpNull = (0 == locallocalSelector_m);

    /* RelationalOperator: '<S34>/Relational Operator3' incorporates:
     *  Constant: '<S34>/Constant6'
     */
    InjSys_bMFuS1SpNull = (0 == locallocalSelector_o);

    /* RelationalOperator: '<S34>/Relational Operator12' incorporates:
     *  Constant: '<S34>/Constant7'
     */
    InjSys_bMFuS2SpNull = (0 == locallocalSelector_i);

    /* Logic: '<S34>/Logical Operator' */
    InjSys_bMufInjTotNull = (((InjSys_bMFuH1SpNull && InjSys_bMFuH2SpNull) &&
      InjSys_bMFuS1SpNull) && InjSys_bMFuS2SpNull);

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET3 */
    VEMS_vidGET(Eng_stEru, mFuInj_B.VEMS_vidGET3_k);

    /* RelationalOperator: '<S34>/Relational Operator6' incorporates:
     *  Constant: '<S34>/Ext_stRun_SC4'
     */
    localRelationalOperator6_k = (Ext_stRun_SC == mFuInj_B.VEMS_vidGET3_k);

    /* RelationalOperator: '<S34>/Relational Operator7' incorporates:
     *  Constant: '<S34>/Ext_stStall_SC1'
     */
    localRelationalOperator7 = (mFuInj_B.VEMS_vidGET3_k == Ext_stStall_SC);

    /* Sum: '<S39>/Add' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    localAdd_lf = localAdd_k - 1U;

    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S39>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_lf, 5U);

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_bCylCutOff, 6, mFuInj_B.VEMS_vidGET4_g);

    /* S-Function "vems_vidGET" Block: <S34>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_bInhInjHPstCyl, 6, mFuInj_B.VEMS_vidGET5_ip);

    /* Switch: '<S34>/Switch4' */
    for (locali = 0; locali < 6; locali++) {
      if (InjSys_bMufInjTotNull) {
        localAssignment_g[locali] = InjSys_prm_mFuInjH2ReqCylPre[(locali)];
      }
    }

    /* DataTypeConversion: '<S49>/OutDTConv' incorporates:
     *  Constant: '<S49>/offset'
     *  Constant: '<S49>/offset1'
     *  Constant: '<S49>/one_on_slope'
     *  Product: '<S49>/Product4'
     *  Sum: '<S49>/Add1'
     *  Sum: '<S49>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjH2CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_l = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_l = 0U;
      }
    } else {
      locallocalOutDTConv_l = MAX_uint16_T;
    }

    /* Switch: '<S34>/Switch17' */
    if (!localRelationalOperator6_k) {
      localAssignment_g[0] = locallocalOutDTConv_l;
      localAssignment_g[1] = locallocalOutDTConv_l;
      localAssignment_g[2] = locallocalOutDTConv_l;
      localAssignment_g[3] = locallocalOutDTConv_l;
      localAssignment_g[4] = locallocalOutDTConv_l;
      localAssignment_g[5] = locallocalOutDTConv_l;
    }

    /* Sum: '<S40>/Add' incorporates:
     *  Constant: '<S40>/Constant1'
     */
    localAdd_lf = localAdd_k - 1U;

    /* MinMax: '<S40>/MinMax' incorporates:
     *  Constant: '<S40>/Constant'
     */
    localmin_0 = (SInt32)rt_MIN(localAdd_lf, 5U);
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_l = localAssignment_g[locali];

      /* Switch: '<S34>/Switch16' incorporates:
       *  Constant: '<S34>/Constant12'
       */
      if (localRelationalOperator7) {
        locallocalOutDTConv_l = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S34>/Switch10' incorporates:
       *  Constant: '<S34>/Constant9'
       */
      if (mFuInj_B.VEMS_vidGET5_ip[(locali)]) {
        locallocalOutDTConv_l = 0U;
      }

      /* Switch: '<S34>/Switch1' incorporates:
       *  Constant: '<S34>/Constant1'
       */
      if (mFuInj_B.VEMS_vidGET4_g[(locali)]) {
        mFuInj_B.Switch1[(locali)] = 0U;
      } else {
        mFuInj_B.Switch1[(locali)] = locallocalOutDTConv_l;
      }

      /* Switch: '<S34>/Switch5' */
      if (InjSys_bMufInjTotNull) {
        locallocalOutDTConv_l = InjSys_prm_mFuInjS1ReqCylPre[(locali)];
      } else {
        locallocalOutDTConv_l = localAssignment_i[locali];
      }

      localAssignment_g[locali] = locallocalOutDTConv_l;
    }

    /* DataTypeConversion: '<S50>/OutDTConv' incorporates:
     *  Constant: '<S50>/offset'
     *  Constant: '<S50>/offset1'
     *  Constant: '<S50>/one_on_slope'
     *  Product: '<S50>/Product4'
     *  Sum: '<S50>/Add1'
     *  Sum: '<S50>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjS1CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_l = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_l = 0U;
      }
    } else {
      locallocalOutDTConv_l = MAX_uint16_T;
    }

    /* Switch: '<S34>/Switch18' */
    if (!localRelationalOperator6_k) {
      localAssignment_g[0] = locallocalOutDTConv_l;
      localAssignment_g[1] = locallocalOutDTConv_l;
      localAssignment_g[2] = locallocalOutDTConv_l;
      localAssignment_g[3] = locallocalOutDTConv_l;
      localAssignment_g[4] = locallocalOutDTConv_l;
      localAssignment_g[5] = locallocalOutDTConv_l;
    }

    /* Sum: '<S41>/Add' incorporates:
     *  Constant: '<S41>/Constant1'
     */
    localAdd_lf = localAdd_k - 1U;
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_l = localAssignment_g[locali];

      /* Switch: '<S34>/Switch13' incorporates:
       *  Constant: '<S34>/Constant11'
       */
      if (localRelationalOperator7) {
        locallocalOutDTConv_l = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S34>/Switch12' incorporates:
       *  Constant: '<S34>/Constant13'
       */
      if (mFuInj_B.VEMS_vidGET5_ip[(locali)]) {
        locallocalOutDTConv_l = 0U;
      }

      /* Switch: '<S34>/Switch11' incorporates:
       *  Constant: '<S34>/Constant10'
       */
      if (mFuInj_B.VEMS_vidGET4_g[(locali)]) {
        mFuInj_B.Switch11[(locali)] = 0U;
      } else {
        mFuInj_B.Switch11[(locali)] = locallocalOutDTConv_l;
      }

      /* Switch: '<S34>/Switch6' */
      if (InjSys_bMufInjTotNull) {
        locallocalOutDTConv_l = InjSys_prm_mFuInjS2ReqCylPre[(locali)];
      } else {
        locallocalOutDTConv_l = localAssignment_f[locali];
      }

      localAssignment_g[locali] = locallocalOutDTConv_l;
    }

    /* DataTypeConversion: '<S51>/OutDTConv' incorporates:
     *  Constant: '<S51>/offset'
     *  Constant: '<S51>/offset1'
     *  Constant: '<S51>/one_on_slope'
     *  Product: '<S51>/Product4'
     *  Sum: '<S51>/Add1'
     *  Sum: '<S51>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjS2CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_l = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_l = 0U;
      }
    } else {
      locallocalOutDTConv_l = MAX_uint16_T;
    }

    /* Switch: '<S34>/Switch21' */
    if (!localRelationalOperator6_k) {
      localAssignment_g[0] = locallocalOutDTConv_l;
      localAssignment_g[1] = locallocalOutDTConv_l;
      localAssignment_g[2] = locallocalOutDTConv_l;
      localAssignment_g[3] = locallocalOutDTConv_l;
      localAssignment_g[4] = locallocalOutDTConv_l;
      localAssignment_g[5] = locallocalOutDTConv_l;
    }

    /* Sum: '<S42>/Add' incorporates:
     *  Constant: '<S42>/Constant1'
     */
    localAdd_k--;
    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_l = localAssignment_g[locali];

      /* Switch: '<S34>/Switch20' incorporates:
       *  Constant: '<S34>/Constant15'
       */
      if (localRelationalOperator7) {
        locallocalOutDTConv_l = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S34>/Switch19' incorporates:
       *  Constant: '<S34>/Constant16'
       */
      if (mFuInj_B.VEMS_vidGET5_ip[(locali)]) {
        locallocalOutDTConv_l = 0U;
      }

      /* Switch: '<S34>/Switch14' incorporates:
       *  Constant: '<S34>/Constant14'
       */
      if (mFuInj_B.VEMS_vidGET4_g[(locali)]) {
        mFuInj_B.Switch14[(locali)] = 0U;
      } else {
        mFuInj_B.Switch14[(locali)] = locallocalOutDTConv_l;
      }

      /* Switch: '<S34>/Switch7' */
      if (InjSys_bMufInjTotNull) {
        locallocalOutDTConv_l = InjSys_prm_mFuInjH1ReqCylPre[(locali)];
      } else {
        locallocalOutDTConv_l = localAssignment_nm[locali];
      }

      localAssignment_g[locali] = locallocalOutDTConv_l;
    }

    /* DataTypeConversion: '<S48>/OutDTConv' incorporates:
     *  Constant: '<S48>/offset'
     *  Constant: '<S48>/offset1'
     *  Constant: '<S48>/one_on_slope'
     *  Product: '<S48>/Product4'
     *  Sum: '<S48>/Add1'
     *  Sum: '<S48>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_mFuInjH1CrkReq) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_l = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_l = 0U;
      }
    } else {
      locallocalOutDTConv_l = MAX_uint16_T;
    }

    /* Switch: '<S34>/Switch9' */
    if (!localRelationalOperator6_k) {
      localAssignment_g[0] = locallocalOutDTConv_l;
      localAssignment_g[1] = locallocalOutDTConv_l;
      localAssignment_g[2] = locallocalOutDTConv_l;
      localAssignment_g[3] = locallocalOutDTConv_l;
      localAssignment_g[4] = locallocalOutDTConv_l;
      localAssignment_g[5] = locallocalOutDTConv_l;
    }

    for (locali = 0; locali < 6; locali++) {
      locallocalOutDTConv_l = localAssignment_g[locali];

      /* Switch: '<S34>/Switch8' incorporates:
       *  Constant: '<S34>/Constant3'
       */
      if (localRelationalOperator7) {
        locallocalOutDTConv_l = mFuInj_ConstP.pooled7[(locali)];
      }

      /* Switch: '<S34>/Switch3' incorporates:
       *  Constant: '<S34>/Constant8'
       */
      if (mFuInj_B.VEMS_vidGET5_ip[(locali)]) {
        locallocalOutDTConv_l = 0U;
      }

      /* Switch: '<S34>/Switch2' incorporates:
       *  Constant: '<S34>/Constant2'
       */
      if (mFuInj_B.VEMS_vidGET4_g[(locali)]) {
        mFuInj_B.Switch2[(locali)] = 0U;
      } else {
        mFuInj_B.Switch2[(locali)] = locallocalOutDTConv_l;
      }
    }

    /* DataTypeConversion: '<S44>/OutDTConv' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S42>/Constant'
     *  Constant: '<S44>/offset'
     *  Constant: '<S44>/offset1'
     *  Constant: '<S44>/one_on_slope'
     *  MinMax: '<S41>/MinMax'
     *  MinMax: '<S42>/MinMax'
     *  Product: '<S44>/Product4'
     *  Selector: '<S39>/Selector'
     *  Selector: '<S40>/Selector'
     *  Selector: '<S41>/Selector'
     *  Selector: '<S42>/Selector'
     *  Sum: '<S34>/Sum'
     *  Sum: '<S44>/Add1'
     *  Sum: '<S44>/Add2'
     */
    mFuInj_B.OutDTConv = (UInt32)((((((((Float32)mFuInj_B.Switch2[rt_MIN
      (localAdd_k, 5U)]) * 7.450580597E-009F) + (((Float32)mFuInj_B.Switch1
      [(localmin)]) * 7.450580597E-009F)) + (((Float32)mFuInj_B.Switch11
      [(localmin_0)]) * 7.450580597E-009F)) + (((Float32)
      mFuInj_B.Switch14[rt_MIN(localAdd_lf, 5U)]) * 7.450580597E-009F)) *
      1.34217728E+008F) + 0.5F);

    /* S-Function "vems_vidSET" Block: <S34>/VEMS_vidSET */
    VEMS_vidSET(InjSys_mFuReq, mFuInj_B.OutDTConv);

    /* S-Function "vems_vidSET" Block: <S34>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, mFuInj_B.Switch2);

    /* S-Function "vems_vidSET" Block: <S34>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, mFuInj_B.Switch1);

    /* S-Function "vems_vidSET" Block: <S34>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, mFuInj_B.Switch11);

    /* S-Function "vems_vidSET" Block: <S34>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, mFuInj_B.Switch14);
  }

  /* end of Outputs for SubSystem: '<S32>/F02_mFuInj_EveSync' */
}

/* Output and update for exported function: InjSys_EveInj_mFuInj */
void InjSys_EveInj_mFuInj(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S8>/F02_mFuInj_EveSync'
   */
  mFuInj_F02_mFuInj_EveSync();
}

/* Output and update for function-call system: '<S8>/F01_Initialization' */
void mFuInj_F01_Initialization(void)
{
  /* S-Function "vems_vidSET" Block: <S31>/VEMS_vidSET */
  VEMS_vidSET(InjSys_mFuReq, 0U);

  /* S-Function "vems_vidSET" Block: <S31>/VEMS_vidSET1 */
  {
    UInt16 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_mFuInjH1ReqCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S31>/VEMS_vidSET2 */
  {
    UInt16 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_mFuInjH2ReqCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S31>/VEMS_vidSET3 */
  {
    UInt16 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_mFuInjS1ReqCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S31>/VEMS_vidSET4 */
  {
    UInt16 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_mFuInjS2ReqCyl, 6 , localArray );
  }
}

/* Output and update for exported function: InjSys_EveRst_mFuInj */
void InjSys_EveRst_mFuInj(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S8>/F01_Initialization'
   */
  mFuInj_F01_Initialization();
}

/* Output and update for function-call system: '<S5>/F01_mFuInjRunClcn' */
void mFuInj_F01_mFuInjRunClcn(void)
{
  Float32 localDataTypeConversion5[6];
  Float32 localDataTypeConversion6[6];
  Float32 localSelector5;
  Float32 localSelector6;
  UInt16 localSelector4;
  UInt16 localSelector7;
  UInt16 localSelector8;
  UInt16 localSelector9;
  UInt16 localSelector10;
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S6>/F01_mFuInjRunClcn' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/MFUINJ_u8Inhib'
   *  EnablePort: '<S11>/Enable'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if (MFUINJ_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_rInjH2ReqCyl, 6, mFuInj_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, mFuInj_B.VEMS_vidGET);

    /* Selector: '<S11>/Selector4' */
    localSelector4 = mFuInj_B.VEMS_vidGET4[mFuInj_B.VEMS_vidGET - 1];

    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_rInjS1ReqCyl, 6, mFuInj_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, mFuInj_B.VEMS_vidGET1);

    /* Selector: '<S11>/Selector7' */
    localSelector7 = mFuInj_B.VEMS_vidGET5[mFuInj_B.VEMS_vidGET1 - 1];

    /* Selector: '<S11>/Selector8' */
    localSelector8 = mFuInj_B.VEMS_vidGET5[mFuInj_B.VEMS_vidGET - 1];

    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_rInjS2ReqCyl, 6, mFuInj_B.VEMS_vidGET6_b);

    /* Selector: '<S11>/Selector9' */
    localSelector9 = mFuInj_B.VEMS_vidGET6_b[mFuInj_B.VEMS_vidGET1 - 1];

    /* Selector: '<S11>/Selector10' */
    localSelector10 = mFuInj_B.VEMS_vidGET6_b[mFuInj_B.VEMS_vidGET - 1];

    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(InjSys_prm_mFuSpCyl, 6, mFuInj_B.VEMS_vidGET2);

    /* DataTypeConversion: '<S11>/Data Type Conversion5' */
    for (locali = 0; locali < 6; locali++) {
      localDataTypeConversion5[locali] = ((Float32)mFuInj_B.VEMS_vidGET2
        [(locali)]) * 7.450580597E-009F;
    }

    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_rMFuReqLPFu, 6, mFuInj_B.VEMS_vidGET7);

    /* DataTypeConversion: '<S11>/Data Type Conversion6' */
    for (locali = 0; locali < 6; locali++) {
      localDataTypeConversion6[locali] = ((Float32)mFuInj_B.VEMS_vidGET7
        [(locali)]) * 3.051757813E-005F;
    }

    /* S-Function "vems_vidGET" Block: <S11>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(InjSys_prm_rInjH1ReqCyl, 6, mFuInj_B.VEMS_vidGET3);

    /* Product: '<S12>/Divide' */
    for (locali = 0; locali < 6; locali++) {
      localDataTypeConversion5[locali] *= localDataTypeConversion6[locali];
    }

    /* Selector: '<S11>/Selector5' */
    localSelector5 = localDataTypeConversion5[mFuInj_B.VEMS_vidGET1 - 1];

    /* Selector: '<S11>/Selector6' */
    localSelector6 = localDataTypeConversion5[mFuInj_B.VEMS_vidGET - 1];

    /* Product: '<S13>/Divide' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion7'
     *  DataTypeConversion: '<S11>/Data Type Conversion8'
     *  Selector: '<S11>/Selector1'
     *  Selector: '<S11>/Selector2'
     */
    InjSys_prm_mFuInjH1Req[0] = (((Float32)
      mFuInj_B.VEMS_vidGET3[mFuInj_B.VEMS_vidGET1 - 1]) * 3.051757813E-005F) *
      localSelector5;
    InjSys_prm_mFuInjH1Req[1] = (((Float32)
      mFuInj_B.VEMS_vidGET3[mFuInj_B.VEMS_vidGET - 1]) * 3.051757813E-005F) *
      localSelector6;

    /* Product: '<S14>/Divide' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion10'
     *  DataTypeConversion: '<S11>/Data Type Conversion9'
     *  Selector: '<S11>/Selector3'
     */
    InjSys_prm_mFuInjH2Req[0] = (((Float32)
      mFuInj_B.VEMS_vidGET4[mFuInj_B.VEMS_vidGET1 - 1]) * 3.051757813E-005F) *
      localSelector5;
    InjSys_prm_mFuInjH2Req[1] = (((Float32)localSelector4) * 3.051757813E-005F)
      * localSelector6;

    /* Product: '<S15>/Divide' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion11'
     *  DataTypeConversion: '<S11>/Data Type Conversion12'
     */
    InjSys_prm_mFuInjS1Req[0] = (((Float32)localSelector7) * 3.051757813E-005F)
      * localSelector5;
    InjSys_prm_mFuInjS1Req[1] = (((Float32)localSelector8) * 3.051757813E-005F)
      * localSelector6;

    /* Product: '<S16>/Divide' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion13'
     *  DataTypeConversion: '<S11>/Data Type Conversion14'
     */
    InjSys_prm_mFuInjS2Req[0] = (((Float32)localSelector9) * 3.051757813E-005F)
      * localSelector5;
    InjSys_prm_mFuInjS2Req[1] = (((Float32)localSelector10) * 3.051757813E-005F)
      * localSelector6;
  }

  /* end of Outputs for SubSystem: '<S6>/F01_mFuInjRunClcn' */
}

/* Start for exported function: InjSys_SdlFast_mFuInj */
void InjSys_SdlFast_mFuInj_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S5>/mFuInj_fc_demux'
   */

  /* Start for S-Function (fcncallgen): '<S9>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S5>/F01_mFuInjRunClcn'
   *  Start for SubSystem: '<S8>/F03_mFuInj_SdlSync'
   */
}

/* Output and update for exported function: InjSys_SdlFast_mFuInj */
void InjSys_SdlFast_mFuInj(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S5>/mFuInj_fc_demux'
   */

  /* S-Function (fcncallgen): '<S9>/Function-Call Generator' incorporates:
   *  SubSystem: '<S5>/F01_mFuInjRunClcn'
   */
  mFuInj_F01_mFuInjRunClcn();
  mFuInj_ASYNC3(1);
}

/* Model initialize function */
void mFuInj_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  InjSys_EveCkSnNtAc_mFuInj_Start();
  InjSys_SdlFast_mFuInj_Start();
}

#define MFUINJ_STOP_SEC_CODE
#include "mFuInj_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
