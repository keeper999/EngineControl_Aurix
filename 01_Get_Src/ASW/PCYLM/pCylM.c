/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pCylM                                                   */
/* !Description     : CYLINDER PRESSURE ESTIMATOR                             */
/*                                                                            */
/* !Module          : pCylM                                                   */
/*                                                                            */
/* !File            : pCylM.c                                                 */
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
/* !Reference       : V01NT1008118 / 01                                       */
/* !OtherRefs       : VEMS V02 ECU#059785                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Dec 06 14:44:34 2011                              */
/*   Model name       : pCylM_AUTOCODE.mdl                                    */
/*   Model version    : 1.181                                                 */
/*   Root subsystem   : /pCylM                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PCYLM/pCylM.c_v           $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "pCylM.h"
#include "pCylM_private.h"

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
#define PCYLM_START_SEC_VAR_UNSPECIFIED
#include "pCylM_MemMap.h"

/* Block signals (auto storage) */
BlockIO_pCylM pCylM_B;

#define PCYLM_STOP_SEC_VAR_UNSPECIFIED
#include "pCylM_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define PCYLM_START_SEC_CODE
#include "pCylM_MemMap.h"

void pCylM_ASYNC1(int controlPortIdx)
{
}

void pCylM_ASYNC2(int controlPortIdx)
{
  pCylM_F02_CylPMdl();
}

void pCylM_ASYNC3(int controlPortIdx)
{
  pCylM_F02_CylMInSyncSdlFast();
  pCylM_F03_CylMSyncEve();
}

/* Output and update for function-call system: '<S10>/F02_CylMInSyncSdlFast' */
void pCylM_F02_CylMInSyncSdlFast(void)
{
  Float localDataTypeConversion11;
  SInt32 localDataTypeConversion12;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET9 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, pCylM_B.VEMS_vidGET9_p);

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET2 */
  VEMS_vidGET(Eng_noInCyl, pCylM_B.VEMS_vidGET2_bq);

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  Selector: '<S14>/Selector7'
   */
  CylM_agEndInjH2ReqRef = ((Float)
    pCylM_B.VEMS_vidGET9_p[pCylM_B.VEMS_vidGET2_bq - 1]) * 0.0625F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET6 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, pCylM_B.VEMS_vidGET6_p);

  /* DataTypeConversion: '<S14>/Data Type Conversion10' incorporates:
   *  Selector: '<S14>/Selector3'
   */
  CylM_agEndInjH1ReqRef = ((Float)
    pCylM_B.VEMS_vidGET6_p[pCylM_B.VEMS_vidGET2_bq - 1]) * 0.0625F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET4 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, pCylM_B.VEMS_vidGET4_m);

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Selector: '<S14>/Selector6'
   */
  CylM_agBegInjH2ReqRef = ((Float)
    pCylM_B.VEMS_vidGET4_m[pCylM_B.VEMS_vidGET2_bq - 1]) * 0.0625F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET7 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, pCylM_B.VEMS_vidGET7_p);

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET1 */
  VEMS_vidGET(Eng_noCmprCyl, pCylM_B.VEMS_vidGET1_o0);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Selector: '<S14>/Selector4'
   */
  CylM_agBegInjS1ReqRef = ((Float)
    pCylM_B.VEMS_vidGET7_p[pCylM_B.VEMS_vidGET1_o0 - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET8 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, pCylM_B.VEMS_vidGET8_o);

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Selector: '<S14>/Selector5'
   */
  CylM_agEndInjS1ReqRef = ((Float)
    pCylM_B.VEMS_vidGET8_o[pCylM_B.VEMS_vidGET1_o0 - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET10 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, pCylM_B.VEMS_vidGET10_l);

  /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
   *  Selector: '<S14>/Selector8'
   */
  CylM_agBegInjS2ReqRef = ((Float)
    pCylM_B.VEMS_vidGET10_l[pCylM_B.VEMS_vidGET1_o0 - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET11 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, pCylM_B.VEMS_vidGET11_a);

  /* DataTypeConversion: '<S14>/Data Type Conversion6' incorporates:
   *  Selector: '<S14>/Selector9'
   */
  CylM_agEndInjS2ReqRef = ((Float)
    pCylM_B.VEMS_vidGET11_a[pCylM_B.VEMS_vidGET1_o0 - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET3 */
  VEMS_vidGET1DArray(InM_prm_pDsThrPredCyl, 6, pCylM_B.VEMS_vidGET3_b);

  /* DataTypeConversion: '<S14>/Data Type Conversion7' incorporates:
   *  Selector: '<S14>/Selector'
   */
  CylM_pDsThrPredRefIn = ((Float)
    pCylM_B.VEMS_vidGET3_b[pCylM_B.VEMS_vidGET2_bq - 1]) * 8.0F;

  /* DataTypeConversion: '<S14>/Data Type Conversion8' incorporates:
   *  Selector: '<S14>/Selector1'
   */
  CylM_pDsThrPredRefCmpr = ((Float)
    pCylM_B.VEMS_vidGET3_b[pCylM_B.VEMS_vidGET1_o0 - 1]) * 8.0F;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET5 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, pCylM_B.VEMS_vidGET5_m);

  /* DataTypeConversion: '<S14>/Data Type Conversion9' incorporates:
   *  Selector: '<S14>/Selector2'
   */
  CylM_agBegInjH1ReqRef = ((Float)
    pCylM_B.VEMS_vidGET5_m[pCylM_B.VEMS_vidGET2_bq - 1]) * 0.0625F;

  /* DataTypeConversion: '<S14>/Data Type Conversion11' incorporates:
   *  Constant: '<S14>/CylM_agOfsConvVlvRef_C'
   */
  localDataTypeConversion11 = ((Float)CylM_agOfsConvVlvRef_C) * 0.09375F;

  /* DataTypeConversion: '<S14>/Data Type Conversion12' incorporates:
   *  Constant: '<S14>/CylM_facConvVlvRef_C'
   */
  localDataTypeConversion12 = CylM_facConvVlvRef_C;

  /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET */
  VEMS_vidGET(EngM_agCkClsInVlvEstimRef1, pCylM_B.VEMS_vidGET_f);

  /* Sum: '<S14>/Sum' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion13'
   *  Product: '<S16>/Divide'
   */
  CylM_agCkClsInVlvEstimRef1 = (((((Float)pCylM_B.VEMS_vidGET_f) * 0.09375F)
    + 84.0F) * ((Float)localDataTypeConversion12)) +
    localDataTypeConversion11;
}

/* Output and update for function-call system: '<S11>/F02_CylPMdl' */
void pCylM_F02_CylPMdl(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion4[5];
  UInt16 localLookUpTable;
  UInt16 localLookUpTable_n[5];
  Float localDivide_b;
  Float localDivide_j;
  Float localDivide_o;
  Float localDivide_o3;
  Float localmin[8];
  Float localDataTypeConversion2[5];
  SInt32 locali;
  Float locallocalDivide_og;
  Float locallocalSwitch_idx;
  Float locallocalSwitch_idx_0;
  Float locallocalSwitch_idx_1;
  Float locallocalSwitch_idx_2;
  Float locallocalSwitch2_idx;
  Double localtmp;
  UInt16 locallocalDataTypeConversion3_i;

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET */
  VEMS_vidGET(Ext_nEng, pCylM_B.VEMS_vidGET);

  /* DataTypeConversion Block: '<S22>/Data Type Conversion'
   *
   * Regarding '<S22>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET1 */
  VEMS_vidGET(Ext_pDsThrMesSI, pCylM_B.VEMS_vidGET1);

  /* If: '<S18>/If' incorporates:
   *  ActionPort: '<S19>/Action Port'
   *  ActionPort: '<S20>/Action Port'
   *  Constant: '<S18>/CylM_bAcvETBCylPresEstim1_C'
   *  SubSystem: '<S18>/F01_pCylEstimTest'
   *  SubSystem: '<S18>/F02_pCylEstimnoTest'
   */
  if (CylM_bAcvETBCylPresEstim1_C) {
    /* SignalConversion: '<S19>/Signal Conversion' incorporates:
     *  Constant: '<S19>/CylM_pCylEstimInjH1ETB_C'
     */
    pCylM_B.Merge = CylM_pCylEstimInjH1ETB_C;

    /* SignalConversion: '<S19>/Signal Conversion3' incorporates:
     *  Constant: '<S19>/CylM_pCylEstimInjH2ETB_C'
     */
    pCylM_B.Merge3 = CylM_pCylEstimInjH2ETB_C;

    /* SignalConversion: '<S19>/Signal Conversion1' incorporates:
     *  Constant: '<S19>/CylM_pCylEstimInjS1ETB_C'
     */
    pCylM_B.Merge1 = CylM_pCylEstimInjS1ETB_C;

    /* SignalConversion: '<S19>/Signal Conversion2' incorporates:
     *  Constant: '<S19>/CylM_pCylEstimInjS2ETB_C'
     */
    pCylM_B.Merge2 = CylM_pCylEstimInjS2ETB_C;
  } else {
    /* Product: '<S28>/Divide' incorporates:
     *  MinMax: '<S20>/MinMax1'
     *  MinMax: '<S20>/MinMax5'
     *  Sum: '<S20>/Subtract12'
     *  Sum: '<S20>/Subtract2'
     */
    localDivide_b = (rt_MAXf(CylM_agCkClsInVlvEstimRef1, CylM_agBegInjH1ReqRef)
                     - rt_MAXf(CylM_agEndInjH1ReqRef, CylM_agCkClsInVlvEstimRef1))
      / (CylM_agBegInjH1ReqRef - CylM_agEndInjH1ReqRef);

    /* Outputs for atomic SubSystem: '<S28>/If Action Subsystem3' */

    /* Switch: '<S45>/Switch1' incorporates:
     *  Constant: '<S45>/Constant1'
     *  Constant: '<S45>/Constant2'
     *  Constant: '<S45>/Constant3'
     *  Logic: '<S45>/Logical Operator1'
     *  RelationalOperator: '<S45>/Relational Operator'
     *  RelationalOperator: '<S45>/Relational Operator1'
     *  RelationalOperator: '<S45>/Relational Operator3'
     */
    if (((localDivide_b != localDivide_b) || (localDivide_b > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_b)) {
      localDivide_b = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S28>/If Action Subsystem3' */

    /* Product: '<S25>/Divide' incorporates:
     *  MinMax: '<S20>/MinMax2'
     *  MinMax: '<S20>/MinMax6'
     *  Sum: '<S20>/Subtract3'
     *  Sum: '<S20>/Subtract4'
     */
    localDivide_j = (rt_MAXf(CylM_agCkClsInVlvEstimRef1, CylM_agBegInjH2ReqRef)
                     - rt_MAXf(CylM_agEndInjH2ReqRef, CylM_agCkClsInVlvEstimRef1))
      / (CylM_agBegInjH2ReqRef - CylM_agEndInjH2ReqRef);

    /* Outputs for atomic SubSystem: '<S25>/If Action Subsystem3' */

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant1'
     *  Constant: '<S39>/Constant2'
     *  Constant: '<S39>/Constant3'
     *  Logic: '<S39>/Logical Operator1'
     *  RelationalOperator: '<S39>/Relational Operator'
     *  RelationalOperator: '<S39>/Relational Operator1'
     *  RelationalOperator: '<S39>/Relational Operator3'
     */
    if (((localDivide_j != localDivide_j) || (localDivide_j > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_j)) {
      localDivide_j = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S25>/If Action Subsystem3' */

    /* Product: '<S26>/Divide' incorporates:
     *  MinMax: '<S20>/MinMax3'
     *  MinMax: '<S20>/MinMax7'
     *  Sum: '<S20>/Subtract8'
     *  Sum: '<S20>/Subtract9'
     */
    localDivide_o = (rt_MAXf(CylM_agCkClsInVlvEstimRef1, CylM_agBegInjS1ReqRef)
                     - rt_MAXf(CylM_agEndInjS1ReqRef, CylM_agCkClsInVlvEstimRef1))
      / (CylM_agBegInjS1ReqRef - CylM_agEndInjS1ReqRef);

    /* Outputs for atomic SubSystem: '<S26>/If Action Subsystem3' */

    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant1'
     *  Constant: '<S41>/Constant2'
     *  Constant: '<S41>/Constant3'
     *  Logic: '<S41>/Logical Operator1'
     *  RelationalOperator: '<S41>/Relational Operator'
     *  RelationalOperator: '<S41>/Relational Operator1'
     *  RelationalOperator: '<S41>/Relational Operator3'
     */
    if (((localDivide_o != localDivide_o) || (localDivide_o > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_o)) {
      localDivide_o = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S26>/If Action Subsystem3' */

    /* Product: '<S27>/Divide' incorporates:
     *  MinMax: '<S20>/MinMax4'
     *  MinMax: '<S20>/MinMax8'
     *  Sum: '<S20>/Subtract10'
     *  Sum: '<S20>/Subtract11'
     */
    localDivide_o3 = (rt_MAXf(CylM_agCkClsInVlvEstimRef1, CylM_agBegInjS2ReqRef)
                      - rt_MAXf(CylM_agEndInjS2ReqRef,
      CylM_agCkClsInVlvEstimRef1)) / (CylM_agBegInjS2ReqRef -
      CylM_agEndInjS2ReqRef);

    /* Outputs for atomic SubSystem: '<S27>/If Action Subsystem3' */

    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S43>/Constant3'
     *  Logic: '<S43>/Logical Operator1'
     *  RelationalOperator: '<S43>/Relational Operator'
     *  RelationalOperator: '<S43>/Relational Operator1'
     *  RelationalOperator: '<S43>/Relational Operator3'
     */
    if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
      localDivide_o3 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S27>/If Action Subsystem3' */

    /* Switch: '<S35>/Switch2' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S21>/Constant1'
     *  RelationalOperator: '<S35>/LowerRelop1'
     *  RelationalOperator: '<S35>/UpperRelop'
     *  Switch: '<S35>/Switch'
     */
    if (localDivide_b > 1.0F) {
      locallocalSwitch2_idx = 1.0F;
    } else if (localDivide_b < 0.0F) {
      locallocalSwitch2_idx = 0.0F;
    } else {
      locallocalSwitch2_idx = localDivide_b;
    }

    if (localDivide_j > 1.0F) {
      localDivide_j = 1.0F;
    } else {
      if (localDivide_j < 0.0F) {
        localDivide_j = 0.0F;
      }
    }

    if (localDivide_o > 1.0F) {
      localDivide_o = 1.0F;
    } else {
      if (localDivide_o < 0.0F) {
        localDivide_o = 0.0F;
      }
    }

    if (localDivide_o3 > 1.0F) {
      localDivide_o3 = 1.0F;
    } else {
      if (localDivide_o3 < 0.0F) {
        localDivide_o3 = 0.0F;
      }
    }

    /* DataTypeConversion: '<S20>/Data Type Conversion7' */
    locallocalSwitch_idx = ((Float)pCylM_B.VEMS_vidGET1) * 8.0F;
    locallocalSwitch_idx_0 = ((Float)pCylM_B.VEMS_vidGET1) * 8.0F;
    locallocalSwitch_idx_1 = ((Float)pCylM_B.VEMS_vidGET1) * 8.0F;
    locallocalSwitch_idx_2 = ((Float)pCylM_B.VEMS_vidGET1) * 8.0F;

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/CylM_bAcvETBCylPresEstim2_C'
     */
    if (!CylM_bAcvETBCylPresEstim2_C) {
      locallocalSwitch_idx = CylM_pDsThrPredRefIn;
      locallocalSwitch_idx_0 = CylM_pDsThrPredRefIn;
      locallocalSwitch_idx_1 = CylM_pDsThrPredRefCmpr;
      locallocalSwitch_idx_2 = CylM_pDsThrPredRefCmpr;
    }

    /* Lookup: '<S22>/Look-Up Table'
     * About '<S22>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(CylM_facCorPresCylNEng_T[0])),
                   pCylM_B.VEMS_vidGET, (&(CylM_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate1'
     *
     * Regarding '<S22>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
     *  Lookup: '<S22>/Look-Up Table'
     */
    localDivide_b = ((Float)localLookUpTable) * 3.051757813E-005F;

    /* MinMax: '<S20>/MinMax' */
    for (locali = 0; locali < 8; locali++) {
      localmin[locali] = CylM_agCkClsInVlvEstimRef1;
    }

    /* DataTypeConversion: '<S20>/Data Type Conversion4' incorporates:
     *  Constant: '<S20>/Constant2'
     *  Product: '<S29>/Divide'
     *  Sum: '<S20>/Subtract1'
     *  Sum: '<S20>/Subtract5'
     *  Sum: '<S20>/Subtract6'
     *  Sum: '<S20>/Subtract7'
     */
    localtmp = ((Double)CylM_agCkClsInVlvEstimRef1) / 0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        locallocalDataTypeConversion3_i = (UInt16)localtmp;
      } else {
        locallocalDataTypeConversion3_i = 0U;
      }
    } else {
      locallocalDataTypeConversion3_i = MAX_uint16_T;
    }

    localDataTypeConversion4[0] = locallocalDataTypeConversion3_i;
    localtmp = ((Double)((rt_MINf(localmin[0], CylM_agBegInjH1ReqRef) + rt_MINf
                          (localmin[1], CylM_agEndInjH1ReqRef)) / 2.0F)) /
      0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        locallocalDataTypeConversion3_i = (UInt16)localtmp;
      } else {
        locallocalDataTypeConversion3_i = 0U;
      }
    } else {
      locallocalDataTypeConversion3_i = MAX_uint16_T;
    }

    localDataTypeConversion4[1] = locallocalDataTypeConversion3_i;
    localtmp = ((Double)((rt_MINf(localmin[2], CylM_agBegInjH2ReqRef) + rt_MINf
                          (localmin[3], CylM_agEndInjH2ReqRef)) / 2.0F)) /
      0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        locallocalDataTypeConversion3_i = (UInt16)localtmp;
      } else {
        locallocalDataTypeConversion3_i = 0U;
      }
    } else {
      locallocalDataTypeConversion3_i = MAX_uint16_T;
    }

    localDataTypeConversion4[2] = locallocalDataTypeConversion3_i;
    localtmp = ((Double)((rt_MINf(localmin[4], CylM_agBegInjS1ReqRef) + rt_MINf
                          (localmin[5], CylM_agEndInjS1ReqRef)) / 2.0F)) /
      0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        locallocalDataTypeConversion3_i = (UInt16)localtmp;
      } else {
        locallocalDataTypeConversion3_i = 0U;
      }
    } else {
      locallocalDataTypeConversion3_i = MAX_uint16_T;
    }

    localDataTypeConversion4[3] = locallocalDataTypeConversion3_i;
    localtmp = ((Double)((rt_MINf(localmin[6], CylM_agBegInjS2ReqRef) + rt_MINf
                          (localmin[7], CylM_agEndInjS2ReqRef)) / 2.0F)) /
      0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        locallocalDataTypeConversion3_i = (UInt16)localtmp;
      } else {
        locallocalDataTypeConversion3_i = 0U;
      }
    } else {
      locallocalDataTypeConversion3_i = MAX_uint16_T;
    }

    localDataTypeConversion4[4] = locallocalDataTypeConversion3_i;

    /* Lookup: '<S23>/Look-Up Table'
     * About '<S23>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U16  2^-25  FSlope 1.024
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    {
      SInt32 i1;
      const UInt16 *u0 = localDataTypeConversion4;
      UInt16 *y0 = localLookUpTable_n;
      for (i1=0; i1 < 5; i1++) {
        LookUp_U16_U16( &(y0[i1]), (&(CylM_vCylInjPha_T[0])), u0[i1],
                       (&(CylM_agInjPha_A[0])), 15U);
      }
    }

    /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate1'
     *
     * Regarding '<S23>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S20>/Data Type Conversion2' incorporates:
     *  Lookup: '<S23>/Look-Up Table'
     */
    for (locali = 0; locali < 5; locali++) {
      localDataTypeConversion2[locali] = ((Float)localLookUpTable_n[(locali)])
        * 3.051757957E-008F;
    }

    /* Product: '<S24>/Divide' incorporates:
     *  Product: '<S30>/Divide'
     *  Product: '<S31>/Divide'
     */
    locallocalDivide_og = ((locallocalSwitch_idx * localDivide_b) *
      localDataTypeConversion2[0]) / localDataTypeConversion2[1];

    /* Outputs for atomic SubSystem: '<S24>/If Action Subsystem3' */

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant1'
     *  Constant: '<S37>/Constant2'
     *  Constant: '<S37>/Constant3'
     *  Logic: '<S37>/Logical Operator1'
     *  RelationalOperator: '<S37>/Relational Operator'
     *  RelationalOperator: '<S37>/Relational Operator1'
     *  RelationalOperator: '<S37>/Relational Operator3'
     */
    if (((locallocalDivide_og != locallocalDivide_og) || (locallocalDivide_og >
          3.000000005E+038F)) || (-3.000000005E+038F > locallocalDivide_og)) {
      locallocalDivide_og = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S24>/If Action Subsystem3' */

    /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
     *  Product: '<S21>/Divide'
     *  SignalConversion: '<S20>/Signal Conversion4'
     *  Sum: '<S21>/Sum2'
     *  Sum: '<S21>/Sum3'
     */
    localtmp = ((Double)(((locallocalSwitch_idx - locallocalDivide_og) *
                          locallocalSwitch2_idx) + locallocalDivide_og)) /
      781.25;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        pCylM_B.Merge = (UInt16)localtmp;
      } else {
        pCylM_B.Merge = 0U;
      }
    } else {
      pCylM_B.Merge = MAX_uint16_T;
    }

    /* Product: '<S24>/Divide' incorporates:
     *  Product: '<S30>/Divide'
     *  Product: '<S31>/Divide'
     */
    locallocalDivide_og = ((locallocalSwitch_idx_0 * localDivide_b) *
      localDataTypeConversion2[0]) / localDataTypeConversion2[2];

    /* Outputs for atomic SubSystem: '<S24>/If Action Subsystem3' */

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant1'
     *  Constant: '<S37>/Constant2'
     *  Constant: '<S37>/Constant3'
     *  Logic: '<S37>/Logical Operator1'
     *  RelationalOperator: '<S37>/Relational Operator'
     *  RelationalOperator: '<S37>/Relational Operator1'
     *  RelationalOperator: '<S37>/Relational Operator3'
     */
    if (((locallocalDivide_og != locallocalDivide_og) || (locallocalDivide_og >
          3.000000005E+038F)) || (-3.000000005E+038F > locallocalDivide_og)) {
      locallocalDivide_og = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S24>/If Action Subsystem3' */

    /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
     *  Product: '<S21>/Divide'
     *  SignalConversion: '<S20>/Signal Conversion2'
     *  Sum: '<S21>/Sum2'
     *  Sum: '<S21>/Sum3'
     */
    localtmp = ((Double)(((locallocalSwitch_idx_0 - locallocalDivide_og) *
                          localDivide_j) + locallocalDivide_og)) / 781.25;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        pCylM_B.Merge3 = (UInt16)localtmp;
      } else {
        pCylM_B.Merge3 = 0U;
      }
    } else {
      pCylM_B.Merge3 = MAX_uint16_T;
    }

    /* Product: '<S24>/Divide' incorporates:
     *  Product: '<S30>/Divide'
     *  Product: '<S31>/Divide'
     */
    locallocalDivide_og = ((locallocalSwitch_idx_1 * localDivide_b) *
      localDataTypeConversion2[0]) / localDataTypeConversion2[3];

    /* Outputs for atomic SubSystem: '<S24>/If Action Subsystem3' */

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant1'
     *  Constant: '<S37>/Constant2'
     *  Constant: '<S37>/Constant3'
     *  Logic: '<S37>/Logical Operator1'
     *  RelationalOperator: '<S37>/Relational Operator'
     *  RelationalOperator: '<S37>/Relational Operator1'
     *  RelationalOperator: '<S37>/Relational Operator3'
     */
    if (((locallocalDivide_og != locallocalDivide_og) || (locallocalDivide_og >
          3.000000005E+038F)) || (-3.000000005E+038F > locallocalDivide_og)) {
      locallocalDivide_og = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S24>/If Action Subsystem3' */

    /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
     *  Product: '<S21>/Divide'
     *  SignalConversion: '<S20>/Signal Conversion1'
     *  Sum: '<S21>/Sum2'
     *  Sum: '<S21>/Sum3'
     */
    localtmp = ((Double)(((locallocalSwitch_idx_1 - locallocalDivide_og) *
                          localDivide_o) + locallocalDivide_og)) / 781.25;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        pCylM_B.Merge1 = (UInt16)localtmp;
      } else {
        pCylM_B.Merge1 = 0U;
      }
    } else {
      pCylM_B.Merge1 = MAX_uint16_T;
    }

    /* Product: '<S24>/Divide' incorporates:
     *  Product: '<S30>/Divide'
     *  Product: '<S31>/Divide'
     */
    locallocalDivide_og = ((locallocalSwitch_idx_2 * localDivide_b) *
      localDataTypeConversion2[0]) / localDataTypeConversion2[4];

    /* Outputs for atomic SubSystem: '<S24>/If Action Subsystem3' */

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant1'
     *  Constant: '<S37>/Constant2'
     *  Constant: '<S37>/Constant3'
     *  Logic: '<S37>/Logical Operator1'
     *  RelationalOperator: '<S37>/Relational Operator'
     *  RelationalOperator: '<S37>/Relational Operator1'
     *  RelationalOperator: '<S37>/Relational Operator3'
     */
    if (((locallocalDivide_og != locallocalDivide_og) || (locallocalDivide_og >
          3.000000005E+038F)) || (-3.000000005E+038F > locallocalDivide_og)) {
      locallocalDivide_og = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S24>/If Action Subsystem3' */

    /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
     *  Product: '<S21>/Divide'
     *  SignalConversion: '<S20>/Signal Conversion3'
     *  Sum: '<S21>/Sum2'
     *  Sum: '<S21>/Sum3'
     */
    localtmp = ((Double)(((locallocalSwitch_idx_2 - locallocalDivide_og) *
                          localDivide_o3) + locallocalDivide_og)) / 781.25;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        pCylM_B.Merge2 = (UInt16)localtmp;
      } else {
        pCylM_B.Merge2 = 0U;
      }
    } else {
      pCylM_B.Merge2 = MAX_uint16_T;
    }
  }

  /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET */
  VEMS_vidSET(CylM_pCylEstimInjH1, pCylM_B.Merge);

  /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET1 */
  VEMS_vidSET(CylM_pCylEstimInjH2, pCylM_B.Merge3);

  /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET2 */
  VEMS_vidSET(CylM_pCylEstimInjS1, pCylM_B.Merge1);

  /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET3 */
  VEMS_vidSET(CylM_pCylEstimInjS2, pCylM_B.Merge2);
}

/* Output and update for function-call system: '<S12>/F03_CylMSyncEve' */
void pCylM_F03_CylMSyncEve(void)
{
  SInt32 locali;

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET9 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6, pCylM_B.VEMS_vidGET9_f);

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET3 */
  VEMS_vidGET(CylM_pCylEstimInjH2, pCylM_B.VEMS_vidGET3_bs);

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET1 */
  VEMS_vidGET(Eng_noInCyl, pCylM_B.VEMS_vidGET1_o);

  /* Assignment: '<S48>/Assignment1' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment1_k[(locali)] = pCylM_B.VEMS_vidGET9_f[(locali)];
  }

  pCylM_B.Assignment1_k[pCylM_B.VEMS_vidGET1_o - 1] = pCylM_B.VEMS_vidGET3_bs;

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET8 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6, pCylM_B.VEMS_vidGET8_e);

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET2 */
  VEMS_vidGET(CylM_pCylEstimInjH1, pCylM_B.VEMS_vidGET2_d);

  /* Assignment: '<S48>/Assignment8' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment8_i[(locali)] = pCylM_B.VEMS_vidGET8_e[(locali)];
  }

  pCylM_B.Assignment8_i[pCylM_B.VEMS_vidGET1_o - 1] = pCylM_B.VEMS_vidGET2_d;

  /* S-Function "vems_vidSET" Block: <S48>/VEMS_vidSET1 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6, pCylM_B.Assignment8_i);

  /* S-Function "vems_vidSET" Block: <S48>/VEMS_vidSET2 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6, pCylM_B.Assignment1_k);

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET6 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6, pCylM_B.VEMS_vidGET6_a);

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET4 */
  VEMS_vidGET(CylM_pCylEstimInjS1, pCylM_B.VEMS_vidGET4_n);

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET */
  VEMS_vidGET(Eng_noCmprCyl, pCylM_B.VEMS_vidGET_fq);

  /* Assignment: '<S48>/Assignment2' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment2_h[(locali)] = pCylM_B.VEMS_vidGET6_a[(locali)];
  }

  pCylM_B.Assignment2_h[pCylM_B.VEMS_vidGET_fq - 1] = pCylM_B.VEMS_vidGET4_n;

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET7 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6, pCylM_B.VEMS_vidGET7_a);

  /* S-Function "vems_vidGET" Block: <S48>/VEMS_vidGET5 */
  VEMS_vidGET(CylM_pCylEstimInjS2, pCylM_B.VEMS_vidGET5_c);

  /* Assignment: '<S48>/Assignment3' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment3_i[(locali)] = pCylM_B.VEMS_vidGET7_a[(locali)];
  }

  pCylM_B.Assignment3_i[pCylM_B.VEMS_vidGET_fq - 1] = pCylM_B.VEMS_vidGET5_c;

  /* S-Function "vems_vidSET" Block: <S48>/VEMS_vidSET */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6, pCylM_B.Assignment3_i);

  /* S-Function "vems_vidSET" Block: <S48>/VEMS_vidSET3 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6, pCylM_B.Assignment2_h);
}

/* Start for exported function: CylM_EveCkSnOn_pCylM */
void CylM_EveCkSnOn_pCylM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S5>/CylM_fc_demux2'
   */

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S10>/F02_CylMInSyncSdlFast'
   *  Start for SubSystem: '<S11>/F02_CylPMdl'
   *  Start for SubSystem: '<S12>/F03_CylMSyncEve'
   */
}

/* Output and update for exported function: CylM_EveCkSnOn_pCylM */
void CylM_EveCkSnOn_pCylM(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S5>/CylM_fc_demux2'
   */

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator' */
  pCylM_ASYNC3(0);
  pCylM_ASYNC2(0);
  pCylM_ASYNC3(0);
}

/* Output and update for function-call system: '<S10>/F01_CylMInSyncEve' */
void pCylM_F01_CylMInSyncEve(void)
{
  Float localDataTypeConversion10;
  SInt32 localDataTypeConversion11_o;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET4 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, pCylM_B.VEMS_vidGET4);

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET2 */
  VEMS_vidGET(Eng_noInNxtCyl, pCylM_B.VEMS_vidGET2_b);

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Selector: '<S13>/Selector2'
   */
  CylM_agBegInjH1ReqRef = ((Float)pCylM_B.VEMS_vidGET4[pCylM_B.VEMS_vidGET2_b
    - 1]) * 0.0625F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET5 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, pCylM_B.VEMS_vidGET5);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Selector: '<S13>/Selector3'
   */
  CylM_agEndInjH1ReqRef = ((Float)pCylM_B.VEMS_vidGET5[pCylM_B.VEMS_vidGET2_b
    - 1]) * 0.0625F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET6 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, pCylM_B.VEMS_vidGET6);

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  Selector: '<S13>/Selector4'
   */
  CylM_agBegInjH2ReqRef = ((Float)pCylM_B.VEMS_vidGET6[pCylM_B.VEMS_vidGET2_b
    - 1]) * 0.0625F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET9 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, pCylM_B.VEMS_vidGET9);

  /* DataTypeConversion: '<S13>/Data Type Conversion3' incorporates:
   *  Selector: '<S13>/Selector5'
   */
  CylM_agEndInjH2ReqRef = ((Float)pCylM_B.VEMS_vidGET9[pCylM_B.VEMS_vidGET2_b
    - 1]) * 0.0625F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET7 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, pCylM_B.VEMS_vidGET7);

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET1 */
  VEMS_vidGET(Eng_noInCyl, pCylM_B.VEMS_vidGET1_l);

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  Selector: '<S13>/Selector6'
   */
  CylM_agBegInjS1ReqRef = ((Float)pCylM_B.VEMS_vidGET7[pCylM_B.VEMS_vidGET1_l
    - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET8 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, pCylM_B.VEMS_vidGET8);

  /* DataTypeConversion: '<S13>/Data Type Conversion5' incorporates:
   *  Selector: '<S13>/Selector7'
   */
  CylM_agEndInjS1ReqRef = ((Float)pCylM_B.VEMS_vidGET8[pCylM_B.VEMS_vidGET1_l
    - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET10 */
  VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, pCylM_B.VEMS_vidGET10);

  /* DataTypeConversion: '<S13>/Data Type Conversion6' incorporates:
   *  Selector: '<S13>/Selector8'
   */
  CylM_agBegInjS2ReqRef = ((Float)
    pCylM_B.VEMS_vidGET10[pCylM_B.VEMS_vidGET1_l - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET11 */
  VEMS_vidGET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, pCylM_B.VEMS_vidGET11);

  /* DataTypeConversion: '<S13>/Data Type Conversion7' incorporates:
   *  Selector: '<S13>/Selector9'
   */
  CylM_agEndInjS2ReqRef = ((Float)
    pCylM_B.VEMS_vidGET11[pCylM_B.VEMS_vidGET1_l - 1]) * 0.09375F;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET3 */
  VEMS_vidGET1DArray(InM_prm_pDsThrPredCyl, 6, pCylM_B.VEMS_vidGET3);

  /* DataTypeConversion: '<S13>/Data Type Conversion8' incorporates:
   *  Selector: '<S13>/Selector'
   */
  CylM_pDsThrPredRefIn = ((Float)pCylM_B.VEMS_vidGET3[pCylM_B.VEMS_vidGET2_b
    - 1]) * 8.0F;

  /* DataTypeConversion: '<S13>/Data Type Conversion9' incorporates:
   *  Selector: '<S13>/Selector1'
   */
  CylM_pDsThrPredRefCmpr = ((Float)
    pCylM_B.VEMS_vidGET3[pCylM_B.VEMS_vidGET1_l - 1]) * 8.0F;

  /* DataTypeConversion: '<S13>/Data Type Conversion10' incorporates:
   *  Constant: '<S13>/CylM_agOfsConvVlvRef_C'
   */
  localDataTypeConversion10 = ((Float)CylM_agOfsConvVlvRef_C) * 0.09375F;

  /* DataTypeConversion: '<S13>/Data Type Conversion11' incorporates:
   *  Constant: '<S13>/CylM_facConvVlvRef_C'
   */
  localDataTypeConversion11_o = CylM_facConvVlvRef_C;

  /* S-Function "vems_vidGET" Block: <S13>/VEMS_vidGET */
  VEMS_vidGET(EngM_agCkClsInVlvEstimRef1, pCylM_B.VEMS_vidGET_n);

  /* Sum: '<S13>/Sum' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion12'
   *  Product: '<S15>/Divide'
   */
  CylM_agCkClsInVlvEstimRef1 = (((((Float)pCylM_B.VEMS_vidGET_n) * 0.09375F)
    + 84.0F) * ((Float)localDataTypeConversion11_o)) +
    localDataTypeConversion10;
}

/* Output and update for function-call system: '<S12>/F02_CylMSyncEveInj' */
void pCylM_F02_CylMSyncEveInj(void)
{
  SInt32 locali;

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET7 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6, CylM_prm_pCylEstimH1CylPrev);

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET2 */
  VEMS_vidGET(CylM_pCylEstimInjH1, pCylM_B.VEMS_vidGET2_m);

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET1 */
  VEMS_vidGET(Eng_noInNxtCyl, pCylM_B.VEMS_vidGET1_e);

  /* Assignment: '<S47>/Assignment1' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment1[(locali)] = CylM_prm_pCylEstimH1CylPrev[(locali)];
  }

  pCylM_B.Assignment1[pCylM_B.VEMS_vidGET1_e - 1] = pCylM_B.VEMS_vidGET2_m;

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET6 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6, CylM_prm_pCylEstimH2CylPrev);

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET3 */
  VEMS_vidGET(CylM_pCylEstimInjH2, pCylM_B.VEMS_vidGET3_a);

  /* Assignment: '<S47>/Assignment8' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment8[(locali)] = CylM_prm_pCylEstimH2CylPrev[(locali)];
  }

  pCylM_B.Assignment8[pCylM_B.VEMS_vidGET1_e - 1] = pCylM_B.VEMS_vidGET3_a;

  /* S-Function "vems_vidSET" Block: <S47>/VEMS_vidSET2 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6, pCylM_B.Assignment1);

  /* S-Function "vems_vidSET" Block: <S47>/VEMS_vidSET4 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6, pCylM_B.Assignment8);

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET9 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6, CylM_prm_pCylEstimS1CylPrev);

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET4 */
  VEMS_vidGET(CylM_pCylEstimInjS1, pCylM_B.VEMS_vidGET4_p);

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET */
  VEMS_vidGET(Eng_noInCyl, pCylM_B.VEMS_vidGET_g);

  /* Assignment: '<S47>/Assignment2' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment2[(locali)] = CylM_prm_pCylEstimS1CylPrev[(locali)];
  }

  pCylM_B.Assignment2[pCylM_B.VEMS_vidGET_g - 1] = pCylM_B.VEMS_vidGET4_p;

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET8 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6, CylM_prm_pCylEstimS2CylPrev);

  /* S-Function "vems_vidGET" Block: <S47>/VEMS_vidGET5 */
  VEMS_vidGET(CylM_pCylEstimInjS2, pCylM_B.VEMS_vidGET5_g);

  /* Assignment: '<S47>/Assignment3' */
  for (locali = 0; locali < 6; locali++) {
    pCylM_B.Assignment3[(locali)] = CylM_prm_pCylEstimS2CylPrev[(locali)];
  }

  pCylM_B.Assignment3[pCylM_B.VEMS_vidGET_g - 1] = pCylM_B.VEMS_vidGET5_g;

  /* S-Function "vems_vidSET" Block: <S47>/VEMS_vidSET1 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6, pCylM_B.Assignment3);

  /* S-Function "vems_vidSET" Block: <S47>/VEMS_vidSET3 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6, pCylM_B.Assignment2);
}

/* Start for exported function: CylM_EveInj_pCylM */
void CylM_EveInj_pCylM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S5>/CylM_fc_demux1'
   */

  /* Start for S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S10>/F01_CylMInSyncEve'
   *  Start for SubSystem: '<S12>/F02_CylMSyncEveInj'
   */
}

/* Output and update for exported function: CylM_EveInj_pCylM */
void CylM_EveInj_pCylM(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S5>/CylM_fc_demux1'
   */

  /* S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
   *  SubSystem: '<S10>/F01_CylMInSyncEve'
   *  SubSystem: '<S12>/F02_CylMSyncEveInj'
   */
  pCylM_F01_CylMInSyncEve();
  pCylM_ASYNC2(1);
  pCylM_F02_CylMSyncEveInj();
}

/* Output and update for function-call system: '<S11>/F01_CylPMdlIni' */
void pCylM_F01_CylPMdlIni(void)
{
  /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET */
  VEMS_vidGET(UsThrM_pAirExt, pCylM_B.VEMS_vidGET_m);

  /* DataTypeConversion: '<S17>/Data Type Conversion5' */
  pCylM_B.DataTypeConversion5 = (UInt16)((SInt32)(((UInt32)
    (pCylM_B.VEMS_vidGET_m * 21475)) >> 21));

  /* S-Function "vems_vidSET" Block: <S17>/VEMS_vidSET */
  VEMS_vidSET(CylM_pCylEstimInjH1, pCylM_B.DataTypeConversion5);

  /* S-Function "vems_vidSET" Block: <S17>/VEMS_vidSET1 */
  VEMS_vidSET(CylM_pCylEstimInjH2, pCylM_B.DataTypeConversion5);

  /* S-Function "vems_vidSET" Block: <S17>/VEMS_vidSET2 */
  VEMS_vidSET(CylM_pCylEstimInjS1, pCylM_B.DataTypeConversion5);

  /* S-Function "vems_vidSET" Block: <S17>/VEMS_vidSET3 */
  VEMS_vidSET(CylM_pCylEstimInjS2, pCylM_B.DataTypeConversion5);
}

/* Output and update for function-call system: '<S12>/F01_CylMSyncRst' */
void pCylM_F01_CylMSyncRst(void)
{
  /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET */
  VEMS_vidGET(CylM_pCylEstimInjH1, pCylM_B.VEMS_vidGET_c);

  /* SignalConversion: '<S46>/TmpSignal ConversionAtVEMS_vidSET2Inport1' */
  pCylM_B.TmpSignalConversionAtVEMS_vidSE[0] = pCylM_B.VEMS_vidGET_c;
  pCylM_B.TmpSignalConversionAtVEMS_vidSE[1] = pCylM_B.VEMS_vidGET_c;
  pCylM_B.TmpSignalConversionAtVEMS_vidSE[2] = pCylM_B.VEMS_vidGET_c;
  pCylM_B.TmpSignalConversionAtVEMS_vidSE[3] = pCylM_B.VEMS_vidGET_c;
  pCylM_B.TmpSignalConversionAtVEMS_vidSE[4] = pCylM_B.VEMS_vidGET_c;
  pCylM_B.TmpSignalConversionAtVEMS_vidSE[5] = pCylM_B.VEMS_vidGET_c;

  /* S-Function "vems_vidSET" Block: <S46>/VEMS_vidSET2 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6,
                     pCylM_B.TmpSignalConversionAtVEMS_vidSE);

  /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET1 */
  VEMS_vidGET(CylM_pCylEstimInjH2, pCylM_B.VEMS_vidGET1_d);

  /* SignalConversion: '<S46>/TmpSignal ConversionAtVEMS_vidSET4Inport1' */
  pCylM_B.TmpSignalConversionAtVEMS_vid_g[0] = pCylM_B.VEMS_vidGET1_d;
  pCylM_B.TmpSignalConversionAtVEMS_vid_g[1] = pCylM_B.VEMS_vidGET1_d;
  pCylM_B.TmpSignalConversionAtVEMS_vid_g[2] = pCylM_B.VEMS_vidGET1_d;
  pCylM_B.TmpSignalConversionAtVEMS_vid_g[3] = pCylM_B.VEMS_vidGET1_d;
  pCylM_B.TmpSignalConversionAtVEMS_vid_g[4] = pCylM_B.VEMS_vidGET1_d;
  pCylM_B.TmpSignalConversionAtVEMS_vid_g[5] = pCylM_B.VEMS_vidGET1_d;

  /* S-Function "vems_vidSET" Block: <S46>/VEMS_vidSET4 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6,
                     pCylM_B.TmpSignalConversionAtVEMS_vid_g);

  /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET2 */
  VEMS_vidGET(CylM_pCylEstimInjS1, pCylM_B.VEMS_vidGET2);

  /* SignalConversion: '<S46>/TmpSignal ConversionAtVEMS_vidSET3Inport1' */
  pCylM_B.TmpSignalConversionAtVEMS_vid_a[0] = pCylM_B.VEMS_vidGET2;
  pCylM_B.TmpSignalConversionAtVEMS_vid_a[1] = pCylM_B.VEMS_vidGET2;
  pCylM_B.TmpSignalConversionAtVEMS_vid_a[2] = pCylM_B.VEMS_vidGET2;
  pCylM_B.TmpSignalConversionAtVEMS_vid_a[3] = pCylM_B.VEMS_vidGET2;
  pCylM_B.TmpSignalConversionAtVEMS_vid_a[4] = pCylM_B.VEMS_vidGET2;
  pCylM_B.TmpSignalConversionAtVEMS_vid_a[5] = pCylM_B.VEMS_vidGET2;

  /* S-Function "vems_vidSET" Block: <S46>/VEMS_vidSET3 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6,
                     pCylM_B.TmpSignalConversionAtVEMS_vid_a);

  /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET3 */
  VEMS_vidGET(CylM_pCylEstimInjS2, pCylM_B.VEMS_vidGET3_bo);

  /* SignalConversion: '<S46>/TmpSignal ConversionAtVEMS_vidSET1Inport1' */
  pCylM_B.TmpSignalConversionAtVEMS_vid_n[0] = pCylM_B.VEMS_vidGET3_bo;
  pCylM_B.TmpSignalConversionAtVEMS_vid_n[1] = pCylM_B.VEMS_vidGET3_bo;
  pCylM_B.TmpSignalConversionAtVEMS_vid_n[2] = pCylM_B.VEMS_vidGET3_bo;
  pCylM_B.TmpSignalConversionAtVEMS_vid_n[3] = pCylM_B.VEMS_vidGET3_bo;
  pCylM_B.TmpSignalConversionAtVEMS_vid_n[4] = pCylM_B.VEMS_vidGET3_bo;
  pCylM_B.TmpSignalConversionAtVEMS_vid_n[5] = pCylM_B.VEMS_vidGET3_bo;

  /* S-Function "vems_vidSET" Block: <S46>/VEMS_vidSET1 */
  VEMS_vidSET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6,
                     pCylM_B.TmpSignalConversionAtVEMS_vid_n);
}

/* Start for exported function: CylM_EveRst_pCylM */
void CylM_EveRst_pCylM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S5>/CylM_fc_demux3'
   */

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S11>/F01_CylPMdlIni'
   *  Start for SubSystem: '<S12>/F01_CylMSyncRst'
   */
}

/* Output and update for exported function: CylM_EveRst_pCylM */
void CylM_EveRst_pCylM(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S5>/CylM_fc_demux3'
   */

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  SubSystem: '<S11>/F01_CylPMdlIni'
   *  SubSystem: '<S12>/F01_CylMSyncRst'
   */
  pCylM_F01_CylPMdlIni();
  pCylM_F01_CylMSyncRst();
}

/* Output and update for exported function: CylM_SdlFast_pCylM */
void CylM_SdlFast_pCylM(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S5>/CylM_fc_demux4'
   */

  /* S-Function (fcncallgen): '<S9>/Function-Call Generator' */
  pCylM_ASYNC3(1);
  pCylM_ASYNC2(2);
  pCylM_ASYNC3(1);
}

/* Model initialize function */
void pCylM_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  CylM_EveCkSnOn_pCylM_Start();
  CylM_EveInj_pCylM_Start();
  CylM_EveRst_pCylM_Start();
}

#define PCYLM_STOP_SEC_CODE
#include "pCylM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
