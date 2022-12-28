/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActGsl                                               */
/* !Description     : TrbActGsl Software Component                            */
/*                                                                            */
/* !Module          : TrbActGsl                                               */
/* !Description     : TrbActGsl Software Component                            */
/*                                                                            */
/* !File            : TrbActGsl.c                                             */
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
/*   Model name       : TrbActGsl_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActGsl                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M15-TrbActGsl/5-$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   28 Feb 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TrbActGsl.h"
#include "TrbActGsl_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define TrbActGsl_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActGsl_MemMap.h"

/* Block signals (auto storage) */
BlockIO_TrbActGsl TrbActGsl_B;

/* Block states (auto storage) */
D_Work_TrbActGsl TrbActGsl_DWork;

#define TrbActGsl_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActGsl_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define TRBACTGSL_VEMSRTLIBT_MAJOR_VERSION_REQ 3
#define TRBACTGSL_VEMSRTLIBT_MINOR_VERSION_REQ 13
#define TRBACTGSL_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define TRBACTGSL_VEMSRTLIBT_VERSION_REQ (TRBACTGSL_VEMSRTLIBT_PATCH_VERSION_REQ + TRBACTGSL_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + TRBACTGSL_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if TRBACTGSL_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define TrbActGsl_START_SEC_CODE
#include "TrbActGsl_MemMap.h"

void TrbActGsl_ASYNC1(int controlPortIdx)
{
}

void TrbActGsl_ASYNC2(int controlPortIdx)
{
}

void TrbActGsl_ASYNC3(int controlPortIdx)
{
}

void TrbActGsl_ASYNC4(int controlPortIdx)
{
}

/* Start for exported function: RE_TrbActGsl_002_TEV */
void RE_TrbActGsl_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_RCOReqClcn'
   *
   * Block requirements for '<S1>/F01_RCOReqClcn':
   *  1. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_035.01 ;
   *  2. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_001.01 ;
   *  3. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_002.01 ;
   *  4. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_004.01 ;
   *  5. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_019.01 ;
   *  6. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_020.01 ;
   *  7. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_021.01 ;
   *  8. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_022.01 ;
   *  9. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_023.02 ;
   *  10. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_018.01 ;
   *  11. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_030.02 ;
   *  12. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_031.02 ;
   *  13. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_032.01 ;
   */
}

/* Output and update for exported function: RE_TrbActGsl_002_TEV */
void RE_TrbActGsl_002_TEV(void)
{
  /* local block i/o variables */
  SInt16 localSum2_g;
  Boolean localRelationalOperator_go;
  Boolean localRelationalOperator1;
  Boolean localLogic[2];
  Boolean localUnitDelay1;
  UInt32 locallupIdx;
  Float32 localSwitch1_k;
  Float32 localSaturation01;
  Float32 localLookupTablenD;
  Float32 localSum1;
  Boolean localLowerRelop1;
  SInt32 localSwitch1_c;
  SInt16 localSwitch_j;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt16 localTmpSignalConversionAtTrbAc;
  UInt16 localTmpSignalConversionAtExM_e;
  UInt16 localTmpSignalConversionAtExM_p;
  UInt16 localTmpSignalConversionAtUsT_m;
  SInt16 localSwitch2_m;
  SInt16 locallocalOutDTConv_o;
  SInt32 localqY;
  SInt16 locallocalDataTypeConversion3_e;
  SInt32 localqY_0;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_RCOReqClcn'
   *
   * Block requirements for '<S1>/F01_RCOReqClcn':
   *  1. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_035.01 ;
   *  2. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_001.01 ;
   *  3. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_002.01 ;
   *  4. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_004.01 ;
   *  5. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_019.01 ;
   *  6. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_020.01 ;
   *  7. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_021.01 ;
   *  8. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_022.01 ;
   *  9. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_023.02 ;
   *  10. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_018.01 ;
   *  11. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_030.02 ;
   *  12. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_031.02 ;
   *  13. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_032.01 ;
   */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_rOpTrbActReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpTrbActReq'
   */
  Rte_Read_R_TrbAct_rOpTrbActReq_TrbAct_rOpTrbActReq
    (&TrbActGsl_B.TmpSignalConversionAtTrbAct_rOp);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_pDsTrbEstimSIOutport2' incorporates:
   *  Inport: '<Root>/ExM_pDsTrbEstimSI'
   */
  Rte_Read_R_ExM_pDsTrbEstimSI_ExM_pDsTrbEstimSI
    (&localTmpSignalConversionAtExM_p);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_pExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_pExMnfEstim'
   */
  Rte_Read_R_ExM_pExMnfEstim_ExM_pExMnfEstim(&localTmpSignalConversionAtExM_e);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_pDsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsCmpr'
   */
  Rte_Read_R_UsThrM_pDsCmpr_UsThrM_pDsCmpr(&localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&TrbActGsl_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pExMnfReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pExMnfReq'
   */
  Rte_Read_R_TrbAct_pExMnfReq_TrbAct_pExMnfReq(&localTmpSignalConversionAtTrbAc);

  /* Outputs for atomic SubSystem: '<S7>/F01_TrbActPresDif' *
   * Block requirements for '<S7>/F01_TrbActPresDif':
   *  1. SubSystem "F01_TrbActPresDif" !Trace_To : VEMS_R_10_07022_005.01 ;
   */

  /* DataTypeConversion: '<S25>/Data Type Conversion1' incorporates:
   *  Constant: '<S25>/TrbAct_facFltPresDsCmpr_C'
   */
  localSwitch1_k = ((Float32)TrbAct_facFltPresDsCmpr_C) * 1.525878906E-005F;

  /* Saturate: '<S41>/Saturation [0-1]' */
  localSaturation01 = rt_SATURATE(localSwitch1_k, 0.0F, 1.0F);

  /* DataTypeConversion: '<S25>/Data Type Conversion4' */
  localSwitch1_k = ((Float32)localTmpSignalConversionAtUsThr) * 8.0F;

  /* UnitDelay: '<S40>/UnitDelay' */
  localLookupTablenD = TrbActGsl_DWork.UnitDelay_p;

  /* Switch: '<S40>/Switch' incorporates:
   *  UnitDelay: '<S40>/UnitDelay1'
   */
  if (!TrbActGsl_DWork.UnitDelay_g) {
    localLookupTablenD = localSwitch1_k;
  }

  /* Sum: '<S41>/Sum1' incorporates:
   *  Product: '<S41>/Product'
   *  Sum: '<S41>/Sum'
   */
  localSum1 = ((localSwitch1_k - localLookupTablenD) * localSaturation01) +
    localLookupTablenD;

  /* Switch: '<S38>/Switch' incorporates:
   *  UnitDelay: '<S38>/UnitDelay'
   */
  if (TrbActGsl_DWork.UnitDelay_DSTATE_j) {
    localSwitch1_k = localSum1;
  }

  /* Sum: '<S34>/Add2' incorporates:
   *  Constant: '<S34>/offset'
   *  Constant: '<S34>/offset1'
   *  Constant: '<S34>/one_on_slope'
   *  Product: '<S34>/Product4'
   *  Sum: '<S34>/Add1'
   */
  localLookupTablenD = (0.125F * localSwitch1_k) + 0.5F;

  /* DataTypeConversion: '<S34>/OutDTConv' */
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      UsThrM_pDsCmprFlt_MP = (UInt16)localLookupTablenD;
    } else {
      UsThrM_pDsCmprFlt_MP = 0U;
    }
  } else {
    UsThrM_pDsCmprFlt_MP = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S33>/Lookup Table (n-D)' */
  localLookupTablenD = look2_iu16u16lfts16p3If_binlcs
    (TrbActGsl_B.TmpSignalConversionAtExt_nEngOu, UsThrM_pDsCmprFlt_MP,
     (&(Ext_nEngRef2_A[0])), (&(TrbAct_pDsCmpr_A[0])),
     (&(TrbAct_pDifTrbActReqAdd_M[0])), &TrbActGsl_ConstP.LookupTablenD_maxInde
     [0], 9U);

  /* Product: '<S35>/Product4' incorporates:
   *  Constant: '<S35>/offset'
   *  Constant: '<S35>/one_on_slope'
   *  Sum: '<S35>/Add1'
   */
  localSwitch1_k = (localLookupTablenD - 4.0F) * 0.125F;

  /* Switch: '<S35>/Switch1' incorporates:
   *  Constant: '<S35>/offset2'
   *  Constant: '<S35>/offset3'
   *  Constant: '<S35>/offset4'
   *  RelationalOperator: '<S35>/Relational Operator'
   *  Sum: '<S35>/Add3'
   *  Sum: '<S35>/Add4'
   */
  if (localSwitch1_k >= 0.0F) {
    localSwitch1_k += 0.5F;
  } else {
    localSwitch1_k -= 0.5F;
  }

  /* DataStoreWrite: '<S25>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S35>/OutDTConv'
   */
  if (localSwitch1_k < 32768.0F) {
    if (localSwitch1_k >= -32768.0F) {
      TrbAct_pDifTrbActReqAdd_MP = (SInt16)localSwitch1_k;
    } else {
      TrbAct_pDifTrbActReqAdd_MP = MIN_int16_T;
    }
  } else {
    TrbAct_pDifTrbActReqAdd_MP = MAX_int16_T;
  }

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S25>/TrbAct_bExtMnfPresSel_C'
   *  DataTypeConversion: '<S25>/Data Type Conversion3'
   *  DataTypeConversion: '<S25>/Data Type Conversion5'
   */
  if (TrbAct_bExtMnfPresSel_C) {
    locallupIdx = (UInt32)(localTmpSignalConversionAtTrbAc << 1);
  } else {
    locallupIdx = localTmpSignalConversionAtExM_e;
  }

  /* Sum: '<S25>/Sum2' */
  localqY = ((SInt32)locallupIdx) - localTmpSignalConversionAtExM_p;
  if (localqY > 32767) {
    localSum2_g = MAX_int16_T;
  } else if (localqY <= -32768) {
    localSum2_g = MIN_int16_T;
  } else {
    localSum2_g = (SInt16)localqY;
  }

  /* Lookup_n-D: '<S32>/Lookup Table (n-D)' */
  localSwitch1_k = look2_is16u16lfts16p3If_binlcs(localSum2_g,
    TrbActGsl_B.TmpSignalConversionAtTrbAct_rOp, (&(TrbAct_pDifTrbEstim_A[0])),
    (&(TrbAct_rOpTrbActReq_A[0])), (&(TrbAct_pDifTrbActReq_M[0])),
    &TrbActGsl_ConstP.pooled12[0], 16U);

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant_61'
   *  Constant: '<S25>/TrbAct_bTrbActCf_SC'
   *  Product: '<S37>/Divide'
   */
  if (!TrbAct_bTrbActCf_SC) {
    localSwitch1_k = -localSwitch1_k;
  }

  /* Product: '<S36>/Product4' incorporates:
   *  Constant: '<S36>/offset'
   *  Constant: '<S36>/one_on_slope'
   *  Sum: '<S36>/Add1'
   */
  localSaturation01 = (localSwitch1_k - 4.0F) * 0.125F;

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S36>/offset2'
   *  Constant: '<S36>/offset3'
   *  Constant: '<S36>/offset4'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  Sum: '<S36>/Add3'
   *  Sum: '<S36>/Add4'
   */
  if (localSaturation01 >= 0.0F) {
    localSaturation01 += 0.5F;
  } else {
    localSaturation01 -= 0.5F;
  }

  /* DataStoreWrite: '<S25>/Data Store Write7' incorporates:
   *  DataTypeConversion: '<S36>/OutDTConv'
   */
  if (localSaturation01 < 32768.0F) {
    if (localSaturation01 >= -32768.0F) {
      TrbAct_pDifTrbActReqBas_MP = (SInt16)localSaturation01;
    } else {
      TrbAct_pDifTrbActReqBas_MP = MIN_int16_T;
    }
  } else {
    TrbAct_pDifTrbActReqBas_MP = MAX_int16_T;
  }

  /* Sum: '<S25>/Sum1' */
  localLookupTablenD += localSwitch1_k;

  /* Update for UnitDelay: '<S40>/UnitDelay' */
  TrbActGsl_DWork.UnitDelay_p = localSum1;

  /* Update for UnitDelay: '<S40>/UnitDelay1' incorporates:
   *  Constant: '<S40>/Constant3'
   */
  TrbActGsl_DWork.UnitDelay_g = TRUE;

  /* Update for UnitDelay: '<S38>/UnitDelay' incorporates:
   *  Constant: '<S38>/Constant3'
   */
  TrbActGsl_DWork.UnitDelay_DSTATE_j = TRUE;

  /* end of Outputs for SubSystem: '<S7>/F01_TrbActPresDif' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S22>/autosar_testpoint1' */

  /* S-Function Block: <S22>/autosar_testpoint1 */
  TrbAct_pDifTrbEstim_IRV_MP = localSum2_g;

  /* Product: '<S30>/Product4' incorporates:
   *  Constant: '<S30>/offset'
   *  Constant: '<S30>/one_on_slope'
   *  Sum: '<S30>/Add1'
   */
  localSaturation01 = (localLookupTablenD - 4.0F) * 0.125F;

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/offset2'
   *  Constant: '<S30>/offset3'
   *  Constant: '<S30>/offset4'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  Sum: '<S30>/Add3'
   *  Sum: '<S30>/Add4'
   */
  if (localSaturation01 >= 0.0F) {
    localSaturation01 += 0.5F;
  } else {
    localSaturation01 -= 0.5F;
  }

  /* DataTypeConversion: '<S30>/OutDTConv' */
  if (localSaturation01 < 32768.0F) {
    if (localSaturation01 >= -32768.0F) {
      locallocalOutDTConv_o = (SInt16)localSaturation01;
    } else {
      locallocalOutDTConv_o = MIN_int16_T;
    }
  } else {
    locallocalOutDTConv_o = MAX_int16_T;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsT_m);

  /* Outputs for atomic SubSystem: '<S7>/F02_PnmActMaxPresDif' *
   * Block requirements for '<S7>/F02_PnmActMaxPresDif':
   *  1. SubSystem "F02_PnmActMaxPresDif" !Trace_To : VEMS_R_10_07022_006.01 ;
   */

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<S26>/TrbAct_bTrbActCf_SC'
   *  Constant: '<S26>/TrbAct_pVacRef_C'
   *  Sum: '<S26>/Sum2'
   *  Sum: '<S26>/Sum3'
   */
  if (TrbAct_bTrbActCf_SC) {
    localSwitch1_c = localTmpSignalConversionAtUsT_m - TrbAct_pVacRef_C;
  } else {
    localSwitch1_c = localTmpSignalConversionAtUsThr -
      localTmpSignalConversionAtUsT_m;
  }

  /* end of Outputs for SubSystem: '<S7>/F02_PnmActMaxPresDif' */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  localSwitch1_k = ((Float32)localSwitch1_c) * 8.0F;

  /* Outputs for atomic SubSystem: '<S7>/F03_PnmActPresDif' *
   * Block requirements for '<S7>/F03_PnmActPresDif':
   *  1. SubSystem "F03_PnmActPresDif" !Trace_To : VEMS_R_10_07022_007.01 ;
   */

  /* Sum: '<S27>/Sum3' */
  localSaturation01 = localSwitch1_k + localLookupTablenD;

  /* RelationalOperator: '<S46>/LowerRelop1' */
  localLowerRelop1 = (localSaturation01 > localSwitch1_k);

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S27>/Cste_1'
   *  RelationalOperator: '<S46>/UpperRelop'
   */
  if (localSaturation01 < 0.0F) {
    localSaturation01 = 0.0F;
  }

  /* Switch: '<S46>/Switch2' */
  if (localLowerRelop1) {
    localSaturation01 = localSwitch1_k;
  }

  /* Product: '<S43>/Product4' incorporates:
   *  Constant: '<S43>/offset'
   *  Constant: '<S43>/one_on_slope'
   *  Sum: '<S43>/Add1'
   */
  localSaturation01 = (localSaturation01 - 4.0F) * 0.125F;

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S43>/offset2'
   *  Constant: '<S43>/offset3'
   *  Constant: '<S43>/offset4'
   *  RelationalOperator: '<S43>/Relational Operator'
   *  Sum: '<S43>/Add3'
   *  Sum: '<S43>/Add4'
   */
  if (localSaturation01 >= 0.0F) {
    localSaturation01 += 0.5F;
  } else {
    localSaturation01 -= 0.5F;
  }

  /* DataTypeConversion: '<S43>/OutDTConv' */
  if (localSaturation01 < 32768.0F) {
    if (localSaturation01 >= -32768.0F) {
      TrbAct_pDifPnmActReq = (SInt16)localSaturation01;
    } else {
      TrbAct_pDifPnmActReq = MIN_int16_T;
    }
  } else {
    TrbAct_pDifPnmActReq = MAX_int16_T;
  }

  /* end of Outputs for SubSystem: '<S7>/F03_PnmActPresDif' */

  /* DataTypeConversion: '<S7>/Data Type Conversion3' */
  if (localSwitch1_c > 32767) {
    locallocalDataTypeConversion3_e = MAX_int16_T;
  } else if (localSwitch1_c <= -32768) {
    locallocalDataTypeConversion3_e = MIN_int16_T;
  } else {
    locallocalDataTypeConversion3_e = (SInt16)localSwitch1_c;
  }

  /* Outputs for atomic SubSystem: '<S7>/F04_RCOReqClcn' *
   * Block requirements for '<S7>/F04_RCOReqClcn':
   *  1. SubSystem "F04_RCOReqClcn" !Trace_To : VEMS_R_10_07022_008.01 ;
   */

  /* Switch: '<S28>/Switch2' incorporates:
   *  Constant: '<S28>/TrbAct_bPresDifSel_C'
   */
  if (TrbAct_bPresDifSel_C) {
    localSwitch2_m = locallocalOutDTConv_o;
  } else {
    localSwitch2_m = TrbAct_pDifPnmActReq;
  }

  /* end of Outputs for SubSystem: '<S7>/F04_RCOReqClcn' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Byp_Fonction_SC'
   *  Constant: '<S20>/Int_BypC'
   *  Constant: '<S48>/offset'
   *  Constant: '<S48>/offset1'
   *  Constant: '<S48>/one_on_slope'
   *  DataTypeConversion: '<S48>/OutDTConv'
   *  Lookup_n-D: '<S47>/Lookup Table (n-D)'
   *  Product: '<S48>/Product4'
   *  Sum: '<S48>/Add1'
   *  Sum: '<S48>/Add2'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExM_p = TrbAct_rRCOReqRaw_B;
  } else {
    localSwitch1_k = (65536.0F * look2_is16lftu16n16If_binlcns(localSwitch2_m,
      locallocalDataTypeConversion3_e, (&(TrbAct_pDifPnmActReq_A[0])),
      (&(TrbAct_pDifMaxPnmActReq_A[0])), (&(TrbAct_rRCOReq_M[0])),
      &TrbActGsl_ConstP.LookupTablenD_maxIn_f[0], 16U)) + 0.5F;
    if (localSwitch1_k < 65536.0F) {
      if (localSwitch1_k >= 0.0F) {
        localTmpSignalConversionAtExM_p = (UInt16)localSwitch1_k;
      } else {
        localTmpSignalConversionAtExM_p = 0U;
      }
    } else {
      localTmpSignalConversionAtExM_p = MAX_uint16_T;
    }
  }

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Byp_Fonction_SC'
   *  Constant: '<S21>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_j = TrbAct_pDifTrbActReq_B;
  } else {
    localSwitch_j = locallocalOutDTConv_o;
  }

  /* Outputs for atomic SubSystem: '<S7>/F05_TrbActCtl' *
   * Block requirements for '<S7>/F05_TrbActCtl':
   *  1. SubSystem "F05_TrbActCtl" !Trace_To : VEMS_R_10_07022_009.01 ;
   */

  /* DataTypeConversion: '<S29>/Data Type Conversion1' */
  localqY = (locallocalOutDTConv_o << 1) + 1;
  localqY = (localqY >= 0) ? ((SInt32)(((UInt32)localqY) >> 1U)) :
    (~((SInt32)(((UInt32)(~localqY)) >> 1U)));

  /* Abs: '<S29>/Abs' */
  if (localqY < 0) {
    locallupIdx = (UInt32)(-localqY);
    if (locallupIdx > 2147483647U) {
      localqY = MAX_int32_T;
    } else {
      localqY = (SInt32)locallupIdx;
    }
  }

  /* RelationalOperator: '<S49>/Relational Operator' */
  localRelationalOperator_go = (localqY >= localSwitch1_c);

  /* RelationalOperator: '<S49>/Relational Operator1' incorporates:
   *  Constant: '<S29>/TrbAct_pDifPnmActHys_C'
   *  Sum: '<S29>/Sum1'
   */
  localqY_0 = localSwitch1_c - TrbAct_pDifPnmActHys_C;
  if ((localSwitch1_c < 0) && (localqY_0 >= 0)) {
    localqY_0 = MIN_int32_T;
  }

  localRelationalOperator1 = (localqY <= localqY_0);

  /* UnitDelay: '<S50>/UnitDelay' */
  localUnitDelay1 = TrbActGsl_DWork.UnitDelay_a;

  /* CombinatorialLogic: '<S50>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_go != 0);
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1 != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic[0] = TrbActGsl_ConstP.Logic_table[rowidx];
    localLogic[1] = TrbActGsl_ConstP.Logic_table[rowidx + 8];
  }

  /* UnitDelay: '<S50>/UnitDelay1' */
  localUnitDelay1 = TrbActGsl_DWork.UnitDelay_k;

  /* Switch: '<S50>/Switch2' incorporates:
   *  Constant: '<S50>/NotCLR3'
   */
  if (localUnitDelay1) {
    localLowerRelop1 = localLogic[0];
  } else {
    localLowerRelop1 = FALSE;
  }

  /* Update for UnitDelay: '<S50>/UnitDelay' */
  TrbActGsl_DWork.UnitDelay_a = localLowerRelop1;

  /* Update for UnitDelay: '<S50>/UnitDelay1' incorporates:
   *  Constant: '<S50>/NotCLR2'
   */
  TrbActGsl_DWork.UnitDelay_k = TRUE;

  /* end of Outputs for SubSystem: '<S7>/F05_TrbActCtl' */

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localLowerRelop1 = TrbAct_bInhTrbActCtl_B;
  }

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    locallocalDataTypeConversion3_e = TrbAct_pDifMaxPnmActReq_B;
  }

  /* SignalConversion: '<S7>/Signal Conversion1' */
  localSwitch2_m = localSum2_g;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_bInhTrbActCtlInport2' */
  Rte_Write_P_TrbAct_bInhTrbActCtl_TrbAct_bInhTrbActCtl(localLowerRelop1);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pDifMaxPnmActReqInport2' */
  Rte_Write_P_TrbAct_pDifMaxPnmActReq_TrbAct_pDifMaxPnmActReq
    (locallocalDataTypeConversion3_e);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pDifTrbActReqInport2' */
  Rte_Write_P_TrbAct_pDifTrbActReq_TrbAct_pDifTrbActReq(localSwitch_j);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pDifTrbEstimInport2' */
  Rte_IrvWrite_RE_TrbActGsl_002_TEV_TrbAct_pDifTrbEstim_irv(localSwitch2_m);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_rRCOReqRawInport2' */
  Rte_Write_P_TrbAct_rRCOReqRaw_TrbAct_rRCOReqRaw
    (localTmpSignalConversionAtExM_p);
}

/* Start for exported function: RE_TrbActGsl_003_TEV */
void RE_TrbActGsl_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_rRCO'
   *
   * Block requirements for '<S1>/F02_rRCO':
   *  1. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_036.02 ;
   *  2. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_010.01 ;
   *  3. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_011.01 ;
   *  4. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_013.01 ;
   *  5. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_024.01 ;
   *  6. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_025.01 ;
   *  7. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_026.01 ;
   *  8. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_032.01 ;
   *  9. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_039.01 ;
   */
}

/* Output and update for exported function: RE_TrbActGsl_003_TEV */
void RE_TrbActGsl_003_TEV(void)
{
  Float32 localSwitch2_f;
  Float32 localfractionTmp_0d;
  UInt32 localExt_nEng_Ext_nEngRef2_A_9_;
  Float32 localInterpolationUsingPrelooku;
  Float32 localSaturation01_g;
  Float32 localSwitch1_m;
  Float32 localSwitch_b;
  Float32 localSwitch2_o;
  Float32 localLookupTablenD_j;
  Float32 localSwitch2_of;
  Float32 localSwitch_c;
  Float32 localLookupTablenD_g;
  Float32 localAdd2_e;
  Boolean localUpperRelop_n;
  Boolean localTmpSignalConversionAtTrb_e;
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  UInt32 localTqSys_tqIdcAirReq_TrbAct_t;
  Float32 localSum1_ny;
  Float32 localSum1_gx;
  Boolean localTmpSignalConversionAtTrb_i;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localTmpSignalConversionAtTrb_a;
  UInt16 localTmpSignalConversionAtTrb_b;
  SInt16 localTmpSignalConversionAtTr_jf;
  SInt16 localTmpSignalConversionAtExt_r;
  SInt16 localTmpSignalConversionAtPnmAc;
  UInt16 localTmpSignalConversionAtTr_bj;
  UInt16 localTmpSignalConversionAtAirSy;
  SInt16 localTmpSignalConversionAtTr_bx;
  SInt16 localTmpSignalConversionAtExt_o;
  UInt16 localTmpSignalConversionAtTrb_j;
  SInt16 localTmpSignalConversionAtTqSys;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_rRCO'
   *
   * Block requirements for '<S1>/F02_rRCO':
   *  1. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_036.02 ;
   *  2. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_010.01 ;
   *  3. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_011.01 ;
   *  4. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_013.01 ;
   *  5. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_024.01 ;
   *  6. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_025.01 ;
   *  7. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_026.01 ;
   *  8. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_032.01 ;
   *  9. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_039.01 ;
   */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* PreLookup: '<S67>/Prelookup' */
  localExt_nEng_Ext_nEngRef2_A_9_ = plook_u32u16f_binc
    (localTmpSignalConversionAtExt_n, (&(Ext_nEngRef2_A[0])), 8U,
     &localSwitch2_f);

  /* Interpolation_n-D: '<S61>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localSwitch2_f;
  localInterpolationUsingPrelooku = intrp1d_iu16n16ff_u32f_l_ns
    (localExt_nEng_Ext_nEngRef2_A_9_, localfractionTmp_0d,
     (&(TrbAct_facFltRCOReqWoutAdp_T[0])));

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_rRCOPIDCorReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rRCOPIDCorReq'
   */
  Rte_Read_R_TrbAct_rRCOPIDCorReq_TrbAct_rRCOPIDCorReq
    (&localTmpSignalConversionAtTr_jf);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_rCtlTestModOutport2' incorporates:
   *  Inport: '<Root>/Ext_rCtlTestMod'
   */
  Rte_Read_R_Ext_rCtlTestMod_Ext_rCtlTestMod(&localTmpSignalConversionAtExt_r);

  /* Switch: '<S8>/Switch12' incorporates:
   *  Constant: '<S8>/TrbAct_bSelRCOCorReq_C'
   */
  if (TrbAct_bSelRCOCorReq_C) {
    localTmpSignalConversionAtExt_r = localTmpSignalConversionAtTr_jf;
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion8' */
  localfractionTmp_0d = ((Float32)localTmpSignalConversionAtExt_r) *
    3.051757813E-005F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtPnmAct_rRCOCorReqOutport2' incorporates:
   *  Inport: '<Root>/PnmAct_rRCOCorReq'
   */
  Rte_Read_R_PnmAct_rRCOCorReq_PnmAct_rRCOCorReq
    (&localTmpSignalConversionAtPnmAc);

  /* Switch: '<S8>/Switch11' incorporates:
   *  Constant: '<S8>/TrbAct_bAcvRCOModTest_C3'
   *  Constant: '<S8>/TrbAct_bRCOReqSel_C'
   */
  if (TrbAct_bRCOReqSel_C) {
    localTmpSignalConversionAtExt_r = localTmpSignalConversionAtPnmAc;
  } else {
    localTmpSignalConversionAtExt_r = 0;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_rRCOReqRawOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rRCOReqRaw_INPUT'
   */
  Rte_Read_R_TrbAct_rRCOReqRaw_TrbAct_rRCOReqRaw
    (&localTmpSignalConversionAtTrb_a);

  /* Sum: '<S8>/Sum9' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion10'
   *  DataTypeConversion: '<S8>/Data Type Conversion3'
   */
  localSwitch1_m = (((Float32)localTmpSignalConversionAtExt_r) *
                    3.051757813E-005F) + (((Float32)
    localTmpSignalConversionAtTrb_a) * 1.525878906E-005F);

  /* Switch: '<S8>/Switch9' incorporates:
   *  Constant: '<S8>/TrbAct_bAcvRCOModTest_C'
   *  Sum: '<S8>/Sum5'
   */
  if (TrbAct_bAcvRCOModTest_C) {
    localSwitch1_m += localfractionTmp_0d;
  }

  /* Switch: '<S106>/Switch' incorporates:
   *  UnitDelay: '<S106>/UnitDelay'
   *  UnitDelay: '<S106>/UnitDelay1'
   */
  if (TrbActGsl_DWork.UnitDelay_f) {
    localSwitch_b = TrbActGsl_DWork.UnitDelay;
  } else {
    localSwitch_b = localSwitch1_m;
  }

  /* Sum: '<S107>/Sum1' incorporates:
   *  Product: '<S107>/Product'
   *  Saturate: '<S107>/Saturation [0-1]'
   *  Sum: '<S107>/Sum'
   */
  localSum1_ny = ((localSwitch1_m - localSwitch_b) * rt_SATURATE
                  (localInterpolationUsingPrelooku, 0.0F, 1.0F)) + localSwitch_b;

  /* Switch: '<S104>/Switch' incorporates:
   *  UnitDelay: '<S104>/UnitDelay'
   */
  if (TrbActGsl_DWork.UnitDelay_DSTATE_f) {
    localSwitch_b = localSum1_ny;
  } else {
    localSwitch_b = localSwitch1_m;
  }

  /* Product: '<S70>/Product4' incorporates:
   *  Constant: '<S70>/offset'
   *  Constant: '<S70>/one_on_slope'
   *  Sum: '<S70>/Add1'
   */
  localSwitch2_o = 16384.0F * localSwitch_b;

  /* Switch: '<S70>/Switch1' incorporates:
   *  Constant: '<S70>/offset2'
   *  Constant: '<S70>/offset3'
   *  Constant: '<S70>/offset4'
   *  RelationalOperator: '<S70>/Relational Operator'
   *  Sum: '<S70>/Add3'
   *  Sum: '<S70>/Add4'
   */
  if (localSwitch2_o >= 0.0F) {
    localSwitch2_o += 0.5F;
  } else {
    localSwitch2_o -= 0.5F;
  }

  /* DataStoreWrite: '<S8>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S70>/OutDTConv'
   */
  if (localSwitch2_o < 32768.0F) {
    if (localSwitch2_o >= -32768.0F) {
      TrbAct_rRCOReqWoutAdpFlt_MP = (SInt16)localSwitch2_o;
    } else {
      TrbAct_rRCOReqWoutAdpFlt_MP = MIN_int16_T;
    }
  } else {
    TrbAct_rRCOReqWoutAdpFlt_MP = MAX_int16_T;
  }

  /* Interpolation_n-D: '<S62>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localSwitch2_f;
  localSwitch2_o = intrp1d_iu16n16ff_u32f_l_ns(localExt_nEng_Ext_nEngRef2_A_9_,
    localfractionTmp_0d, (&(TrbAct_facFltUsPresCorErr_T[0])));

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_pUsThrCorReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pUsThrCorReq'
   */
  Rte_Read_R_TrbAct_pUsThrCorReq_TrbAct_pUsThrCorReq
    (&localTmpSignalConversionAtTrb_b);

  /* DataTypeConversion: '<S8>/Data Type Conversion11' */
  localLookupTablenD_j = ((Float32)localTmpSignalConversionAtTrb_b) * 8.0F;

  /* Switch: '<S110>/Switch' incorporates:
   *  UnitDelay: '<S110>/UnitDelay'
   *  UnitDelay: '<S110>/UnitDelay1'
   */
  if (TrbActGsl_DWork.UnitDelay_n) {
    localSwitch2_of = TrbActGsl_DWork.UnitDelay_c;
  } else {
    localSwitch2_of = localLookupTablenD_j;
  }

  /* Sum: '<S111>/Sum1' incorporates:
   *  Product: '<S111>/Product'
   *  Saturate: '<S111>/Saturation [0-1]'
   *  Sum: '<S111>/Sum'
   */
  localSum1_gx = ((localLookupTablenD_j - localSwitch2_of) * rt_SATURATE
                  (localSwitch2_o, 0.0F, 1.0F)) + localSwitch2_of;

  /* Switch: '<S108>/Switch' incorporates:
   *  UnitDelay: '<S108>/UnitDelay'
   */
  if (TrbActGsl_DWork.UnitDelay_DSTATE_k) {
    localLookupTablenD_j = localSum1_gx;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_pUsThrFilOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pUsThrFil'
   */
  Rte_Read_R_TrbAct_pUsThrFil_TrbAct_pUsThrFil(&localTmpSignalConversionAtTr_bj);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_pUsThrReqFilOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReqFil'
   */
  Rte_Read_R_AirSys_pUsThrReqFil_AirSys_pUsThrReqFil
    (&localTmpSignalConversionAtAirSy);

  /* Switch: '<S8>/Switch14' incorporates:
   *  Constant: '<S8>/TrbAct_rCtlIntErrMin_C2'
   */
  if (TrbAct_bUpPresAdpSel_C) {
    localTmpSignalConversionAtAirSy = localTmpSignalConversionAtTr_bj;
  }

  /* Sum: '<S8>/Sum3' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   */
  localLookupTablenD_j -= ((Float32)localTmpSignalConversionAtAirSy) * 8.0F;

  /* DataTypeConversion: '<S8>/Data Type Conversion25' incorporates:
   *  Constant: '<S8>/TrbAct_pUsThrCorErrMax_C'
   */
  localSwitch2_of = ((Float32)TrbAct_pUsThrCorErrMax_C) * 8.0F;

  /* DataTypeConversion: '<S8>/Data Type Conversion24' incorporates:
   *  Constant: '<S8>/TrbAct_pUsThrCorErrMin_C'
   */
  localSwitch_c = (((Float32)TrbAct_pUsThrCorErrMin_C) * 8.0F) - 524280.0F;

  /* Switch: '<S94>/Switch' incorporates:
   *  RelationalOperator: '<S94>/UpperRelop'
   */
  if (!(localLookupTablenD_j < localSwitch_c)) {
    localSwitch_c = localLookupTablenD_j;
  }

  /* Switch: '<S94>/Switch2' incorporates:
   *  RelationalOperator: '<S94>/LowerRelop1'
   */
  if (!(localLookupTablenD_j > localSwitch2_of)) {
    localSwitch2_of = localSwitch_c;
  }

  /* Sum: '<S8>/Sum6' */
  localLookupTablenD_j -= localSwitch2_of;

  /* Product: '<S77>/Product4' incorporates:
   *  Constant: '<S77>/offset'
   *  Constant: '<S77>/one_on_slope'
   *  Sum: '<S77>/Add1'
   */
  localSwitch_c = 0.125F * localLookupTablenD_j;

  /* Switch: '<S77>/Switch1' incorporates:
   *  Constant: '<S77>/offset2'
   *  Constant: '<S77>/offset3'
   *  Constant: '<S77>/offset4'
   *  RelationalOperator: '<S77>/Relational Operator'
   *  Sum: '<S77>/Add3'
   *  Sum: '<S77>/Add4'
   */
  if (localSwitch_c >= 0.0F) {
    localSwitch_c += 0.5F;
  } else {
    localSwitch_c -= 0.5F;
  }

  /* DataTypeConversion: '<S77>/OutDTConv' */
  if (localSwitch_c < 32768.0F) {
    if (localSwitch_c >= -32768.0F) {
      localTmpSignalConversionAtTr_jf = (SInt16)localSwitch_c;
    } else {
      localTmpSignalConversionAtTr_jf = MIN_int16_T;
    }
  } else {
    localTmpSignalConversionAtTr_jf = MAX_int16_T;
  }

  /* Lookup_n-D: '<S64>/Lookup Table (n-D)' */
  localLookupTablenD_g = look1_is16lfts16n15If_binlcns
    (localTmpSignalConversionAtTr_jf, (&(TrbAct_pUsThrCorErrFil_A[0])),
     (&(TrbAct_rRCOReqFastAddCor_T[0])), 8U);

  /* Product: '<S73>/Product4' incorporates:
   *  Constant: '<S73>/offset'
   *  Constant: '<S73>/one_on_slope'
   *  Sum: '<S73>/Add1'
   */
  localSwitch_c = 32768.0F * localLookupTablenD_g;

  /* Switch: '<S73>/Switch1' incorporates:
   *  Constant: '<S73>/offset2'
   *  Constant: '<S73>/offset3'
   *  Constant: '<S73>/offset4'
   *  RelationalOperator: '<S73>/Relational Operator'
   *  Sum: '<S73>/Add3'
   *  Sum: '<S73>/Add4'
   */
  if (localSwitch_c >= 0.0F) {
    localSwitch_c += 0.5F;
  } else {
    localSwitch_c -= 0.5F;
  }

  /* DataStoreWrite: '<S8>/Data Store Write10' incorporates:
   *  DataTypeConversion: '<S73>/OutDTConv'
   */
  if (localSwitch_c < 32768.0F) {
    if (localSwitch_c >= -32768.0F) {
      TrbAct_rRCOFastAddCor_MP = (SInt16)localSwitch_c;
    } else {
      TrbAct_rRCOFastAddCor_MP = MIN_int16_T;
    }
  } else {
    TrbAct_rRCOFastAddCor_MP = MAX_int16_T;
  }

  /* DataStoreWrite: '<S8>/Data Store Write11' incorporates:
   *  Constant: '<S74>/offset'
   *  Constant: '<S74>/offset1'
   *  Constant: '<S74>/one_on_slope'
   *  DataTypeConversion: '<S74>/OutDTConv'
   *  Product: '<S74>/Product4'
   *  Sum: '<S74>/Add1'
   *  Sum: '<S74>/Add2'
   */
  localfractionTmp_0d = ((localSwitch2_o - 1.525878906E-005F) * 65536.0F) + 0.5F;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      TrbAct_facFltUsPresCorErr_MP = (UInt16)localfractionTmp_0d;
    } else {
      TrbAct_facFltUsPresCorErr_MP = 0U;
    }
  } else {
    TrbAct_facFltUsPresCorErr_MP = MAX_uint16_T;
  }

  /* Sum: '<S8>/Sum11' incorporates:
   *  UnitDelay: '<S83>/Unit Delay'
   */
  localSwitch_c = localLookupTablenD_g - TrbActGsl_DWork.UnitDelay_DSTATE;

  /* Product: '<S71>/Product4' incorporates:
   *  Constant: '<S71>/offset'
   *  Constant: '<S71>/one_on_slope'
   *  Sum: '<S71>/Add1'
   */
  localSwitch2_of = 32768.0F * localSwitch_c;

  /* Switch: '<S71>/Switch1' incorporates:
   *  Constant: '<S71>/offset2'
   *  Constant: '<S71>/offset3'
   *  Constant: '<S71>/offset4'
   *  RelationalOperator: '<S71>/Relational Operator'
   *  Sum: '<S71>/Add3'
   *  Sum: '<S71>/Add4'
   */
  if (localSwitch2_of >= 0.0F) {
    localSwitch2_of += 0.5F;
  } else {
    localSwitch2_of -= 0.5F;
  }

  /* DataStoreWrite: '<S8>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S71>/OutDTConv'
   */
  if (localSwitch2_of < 32768.0F) {
    if (localSwitch2_of >= -32768.0F) {
      TrbAct_rRCOReqFastAdpOfs_MP = (SInt16)localSwitch2_of;
    } else {
      TrbAct_rRCOReqFastAdpOfs_MP = MIN_int16_T;
    }
  } else {
    TrbAct_rRCOReqFastAdpOfs_MP = MAX_int16_T;
  }

  /* DataStoreWrite: '<S8>/Data Store Write3' */
  TrbAct_pUsThrCorErr_MP = localTmpSignalConversionAtTr_jf;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_rRCOICorReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rRCOICorReq'
   */
  Rte_Read_R_TrbAct_rRCOICorReq_TrbAct_rRCOICorReq
    (&localTmpSignalConversionAtTr_bx);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_rCtlIntTestModOutport2' incorporates:
   *  Inport: '<Root>/Ext_rCtlIntTestMod'
   */
  Rte_Read_R_Ext_rCtlIntTestMod_Ext_rCtlIntTestMod
    (&localTmpSignalConversionAtExt_o);

  /* Switch: '<S8>/Switch13' incorporates:
   *  Constant: '<S8>/TrbAct_bSelRCOCorReq_C1'
   */
  if (TrbAct_bSelRCOCorReq_C) {
    localTmpSignalConversionAtExt_o = localTmpSignalConversionAtTr_bx;
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion12' */
  localSwitch2_of = ((Float32)localTmpSignalConversionAtExt_o) *
    3.051757813E-005F;

  /* DataTypeConversion: '<S8>/Data Type Conversion23' incorporates:
   *  Constant: '<S8>/TrbAct_rCtlIntErrMax_C'
   */
  localSwitch2_o = ((Float32)TrbAct_rCtlIntErrMax_C) * 1.525878906E-005F;

  /* DataTypeConversion: '<S8>/Data Type Conversion20' incorporates:
   *  Constant: '<S8>/TrbAct_rCtlIntErrMin_C'
   */
  localAdd2_e = (((Float32)TrbAct_rCtlIntErrMin_C) * 1.525878906E-005F) -
    9.999847412E-001F;

  /* RelationalOperator: '<S91>/UpperRelop' */
  localUpperRelop_n = (localSwitch2_of < localAdd2_e);

  /* Switch: '<S91>/Switch' */
  if (!localUpperRelop_n) {
    localAdd2_e = localSwitch2_of;
  }

  /* Switch: '<S91>/Switch2' incorporates:
   *  RelationalOperator: '<S91>/LowerRelop1'
   */
  if (!(localSwitch2_of > localSwitch2_o)) {
    localSwitch2_o = localAdd2_e;
  }

  /* Sum: '<S8>/Sum4' */
  localSwitch2_of -= localSwitch2_o;

  /* Product: '<S76>/Product4' incorporates:
   *  Constant: '<S76>/offset'
   *  Constant: '<S76>/one_on_slope'
   *  Sum: '<S76>/Add1'
   */
  localAdd2_e = 32768.0F * localSwitch2_of;

  /* Sum: '<S76>/Add3' incorporates:
   *  Constant: '<S76>/offset3'
   */
  localfractionTmp_0d = localAdd2_e + 0.5F;

  /* RelationalOperator: '<S76>/Relational Operator' incorporates:
   *  Constant: '<S76>/offset2'
   */
  localUpperRelop_n = (localAdd2_e >= 0.0F);

  /* Sum: '<S76>/Add4' incorporates:
   *  Constant: '<S76>/offset4'
   */
  localSaturation01_g = localAdd2_e - 0.5F;

  /* Switch: '<S76>/Switch1' */
  if (localUpperRelop_n) {
    localAdd2_e = localfractionTmp_0d;
  } else {
    localAdd2_e = localSaturation01_g;
  }

  /* DataTypeConversion: '<S76>/OutDTConv' incorporates:
   *  DataStoreWrite: '<S8>/Data Store Write4'
   */
  localfractionTmp_0d = localAdd2_e;
  if (localfractionTmp_0d < 32768.0F) {
    if (localfractionTmp_0d >= -32768.0F) {
      TrbAct_rCtlIntErr_MP = (SInt16)localfractionTmp_0d;
    } else {
      TrbAct_rCtlIntErr_MP = MIN_int16_T;
    }
  } else {
    TrbAct_rCtlIntErr_MP = MAX_int16_T;
  }

  /* Switch: '<S8>/Switch10' incorporates:
   *  Constant: '<S8>/TrbAct_bUpPresAdpSel_C'
   *  Constant: '<S8>/TrbAct_facPresReqAdpOfs_C'
   *  Constant: '<S8>/TrbAct_facRCOReqAdpOfs_C'
   *  DataTypeConversion: '<S8>/Data Type Conversion13'
   *  DataTypeConversion: '<S8>/Data Type Conversion14'
   *  Product: '<S86>/Divide'
   *  Product: '<S87>/Divide'
   */
  if (TrbAct_bRCOAdpSel_C) {
    localAdd2_e = (((Float32)TrbAct_facRCOReqAdpOfs_C) * 1.525878906E-005F) *
      localSwitch2_of;
  } else {
    localAdd2_e = (((Float32)TrbAct_facPresReqAdpOfs_C) * 5.820766091E-011F) *
      localLookupTablenD_j;
  }

  /* Sum: '<S78>/Add1' incorporates:
   *  Constant: '<S78>/offset'
   */
  localfractionTmp_0d = localAdd2_e;

  /* Product: '<S78>/Product4' incorporates:
   *  Constant: '<S78>/one_on_slope'
   */
  localSwitch2_o = 2.147483648E+009F * localfractionTmp_0d;

  /* Switch: '<S78>/Switch1' incorporates:
   *  Constant: '<S78>/offset2'
   *  Constant: '<S78>/offset3'
   *  Constant: '<S78>/offset4'
   *  RelationalOperator: '<S78>/Relational Operator'
   *  Sum: '<S78>/Add3'
   *  Sum: '<S78>/Add4'
   */
  if (localSwitch2_o >= 0.0F) {
    localSwitch2_o += 0.5F;
  } else {
    localSwitch2_o -= 0.5F;
  }

  /* DataStoreWrite: '<S8>/Data Store Write5' incorporates:
   *  DataTypeConversion: '<S78>/OutDTConv'
   */
  if (localSwitch2_o < 2.147483648E+009F) {
    if (localSwitch2_o >= -2.147483648E+009F) {
      TrbAct_rRCOReqAdpOfsErr_MP = (SInt32)localSwitch2_o;
    } else {
      TrbAct_rRCOReqAdpOfsErr_MP = MIN_int32_T;
    }
  } else {
    TrbAct_rRCOReqAdpOfsErr_MP = MAX_int32_T;
  }

  /* Switch: '<S8>/Switch7' incorporates:
   *  Constant: '<S8>/TrbAct_bUpPresAdpSel_C'
   *  Constant: '<S8>/TrbAct_facPresReqAdpRate_C'
   *  Constant: '<S8>/TrbAct_facRCOReqAdpRate_C'
   *  DataTypeConversion: '<S8>/Data Type Conversion18'
   *  DataTypeConversion: '<S8>/Data Type Conversion19'
   *  Product: '<S84>/Divide'
   *  Product: '<S85>/Divide'
   */
  if (TrbAct_bRCOAdpSel_C) {
    localSwitch2_of *= ((Float32)TrbAct_facRCOReqAdpRate_C) * 1.525878906E-005F;
  } else {
    localSwitch2_of = (((Float32)TrbAct_facPresReqAdpRate_C) *
                       5.820766091E-011F) * localLookupTablenD_j;
  }

  /* Product: '<S79>/Product4' incorporates:
   *  Constant: '<S79>/offset'
   *  Constant: '<S79>/one_on_slope'
   *  Sum: '<S79>/Add1'
   */
  localLookupTablenD_j = 2.147483648E+009F * localSwitch2_of;

  /* Switch: '<S79>/Switch1' incorporates:
   *  Constant: '<S79>/offset2'
   *  Constant: '<S79>/offset3'
   *  Constant: '<S79>/offset4'
   *  RelationalOperator: '<S79>/Relational Operator'
   *  Sum: '<S79>/Add3'
   *  Sum: '<S79>/Add4'
   */
  if (localLookupTablenD_j >= 0.0F) {
    localLookupTablenD_j += 0.5F;
  } else {
    localLookupTablenD_j -= 0.5F;
  }

  /* DataStoreWrite: '<S8>/Data Store Write6' incorporates:
   *  DataTypeConversion: '<S79>/OutDTConv'
   */
  if (localLookupTablenD_j < 2.147483648E+009F) {
    if (localLookupTablenD_j >= -2.147483648E+009F) {
      TrbAct_rRCOReqAdpRateErr_MP = (SInt32)localLookupTablenD_j;
    } else {
      TrbAct_rRCOReqAdpRateErr_MP = MIN_int32_T;
    }
  } else {
    TrbAct_rRCOReqAdpRateErr_MP = MAX_int32_T;
  }

  /* DataStoreWrite: '<S8>/Data Store Write7' incorporates:
   *  Constant: '<S80>/offset'
   *  Constant: '<S80>/offset1'
   *  Constant: '<S80>/one_on_slope'
   *  DataTypeConversion: '<S80>/OutDTConv'
   *  Product: '<S80>/Product4'
   *  Sum: '<S80>/Add1'
   *  Sum: '<S80>/Add2'
   */
  localfractionTmp_0d = (65536.0F * localInterpolationUsingPrelooku) + 0.5F;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      TrbAct_facFltRCOReq_MP = (UInt16)localfractionTmp_0d;
    } else {
      TrbAct_facFltRCOReq_MP = 0U;
    }
  } else {
    TrbAct_facFltRCOReq_MP = MAX_uint16_T;
  }

  /* Product: '<S81>/Product4' incorporates:
   *  Constant: '<S81>/offset'
   *  Constant: '<S81>/one_on_slope'
   *  Sum: '<S81>/Add1'
   */
  localLookupTablenD_j = 16384.0F * localSwitch1_m;

  /* Switch: '<S81>/Switch1' incorporates:
   *  Constant: '<S81>/offset2'
   *  Constant: '<S81>/offset3'
   *  Constant: '<S81>/offset4'
   *  RelationalOperator: '<S81>/Relational Operator'
   *  Sum: '<S81>/Add3'
   *  Sum: '<S81>/Add4'
   */
  if (localLookupTablenD_j >= 0.0F) {
    localLookupTablenD_j += 0.5F;
  } else {
    localLookupTablenD_j -= 0.5F;
  }

  /* DataStoreWrite: '<S8>/Data Store Write8' incorporates:
   *  DataTypeConversion: '<S81>/OutDTConv'
   */
  if (localLookupTablenD_j < 32768.0F) {
    if (localLookupTablenD_j >= -32768.0F) {
      TrbAct_rRCOReqWoutAdpBas_MP = (SInt16)localLookupTablenD_j;
    } else {
      TrbAct_rRCOReqWoutAdpBas_MP = MIN_int16_T;
    }
  } else {
    TrbAct_rRCOReqWoutAdpBas_MP = MAX_int16_T;
  }

  /* Sum: '<S69>/Add2' incorporates:
   *  Constant: '<S69>/offset'
   *  Constant: '<S69>/offset1'
   *  Constant: '<S69>/one_on_slope'
   *  Product: '<S69>/Product4'
   *  Sum: '<S69>/Add1'
   *  Sum: '<S8>/Sum8'
   */
  localLookupTablenD_j = (((localSwitch1_m - localSwitch_b) - -9.999847412E-001F)
    * 32768.0F) + 0.5F;

  /* DataTypeConversion: '<S69>/OutDTConv' */
  if (localLookupTablenD_j < 65536.0F) {
    if (localLookupTablenD_j >= 0.0F) {
      TrbAct_rRCOReqAdd_MP = (UInt16)localLookupTablenD_j;
    } else {
      TrbAct_rRCOReqAdd_MP = 0U;
    }
  } else {
    TrbAct_rRCOReqAdd_MP = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S65>/Lookup Table (n-D)' */
  localLookupTablenD_j = look1_iu16lfIf_binlcns__2(TrbAct_rRCOReqAdd_MP,
    (&(TrbAct_rRCOReqAdd_A[0])), (&(TrbAct_rRCOReqAddCor_T[0])), 15U);

  /* DataStoreWrite: '<S8>/Data Store Write9' incorporates:
   *  Constant: '<S82>/offset'
   *  Constant: '<S82>/offset1'
   *  Constant: '<S82>/one_on_slope'
   *  DataTypeConversion: '<S82>/OutDTConv'
   *  Product: '<S82>/Product4'
   *  Sum: '<S82>/Add1'
   *  Sum: '<S82>/Add2'
   */
  localfractionTmp_0d = ((localLookupTablenD_j - -9.999847412E-001F) * 32768.0F)
    + 0.5F;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      TrbAct_rRCOReqAddCor_MP = (UInt16)localfractionTmp_0d;
    } else {
      TrbAct_rRCOReqAddCor_MP = 0U;
    }
  } else {
    TrbAct_rRCOReqAddCor_MP = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion6' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOReqAdpRateMax_C'
   */
  localSwitch2_o = (((Float32)TrbAct_rRCOReqAdpRateMax_C) * 1.525878906E-005F)
    + 1.0F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_bAcvTrbActAdpOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bAcvTrbActAdp'
   */
  Rte_Read_R_TrbAct_bAcvTrbActAdp_TrbAct_bAcvTrbActAdp
    (&localTmpSignalConversionAtTrb_e);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_rOpTrbActReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpTrbActReq'
   */
  Rte_Read_R_TrbAct_rOpTrbActReq_TrbAct_rOpTrbActReq
    (&localTmpSignalConversionAtTrb_j);

  /* Switch: '<S8>/Switch8' incorporates:
   *  Constant: '<S8>/TrbAct_bOpRCOAdpSel_C'
   */
  if (TrbAct_bOpRCOAdpSel_C) {
    localTmpSignalConversionAtAirSy = localTmpSignalConversionAtTrb_a;
  } else {
    localTmpSignalConversionAtAirSy = localTmpSignalConversionAtTrb_j;
  }

  /* Logic: '<S8>/Logical Operator3' incorporates:
   *  Constant: '<S8>/TrbAct_rOpRCOAdpRateThd1_C'
   *  Constant: '<S8>/TrbAct_rOpRCOAdpRateThd2_C'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S8>/Relational Operator3'
   *  RelationalOperator: '<S8>/Relational Operator4'
   */
  TrbAct_bAcvRateRCOAdp_MP = ((localTmpSignalConversionAtTrb_e) &&
    ((localTmpSignalConversionAtAirSy < TrbAct_rOpRCOAdpRateThd2_C) &&
     (localTmpSignalConversionAtAirSy > TrbAct_rOpRCOAdpRateThd1_C)));

  /* Switch: '<S8>/Switch5' incorporates:
   *  Constant: '<S8>/Rco_min_wg2'
   *  Constant: '<S8>/TrbAct_bAcvRCOAdp_C1'
   *  Logic: '<S8>/Logical Operator5'
   */
  if (!(TrbAct_bAcvRateRCOAdp_MP && TrbAct_bAcvRCOAdp_C)) {
    localSwitch2_of = 0.0F;
  }

  /* S-Function (NvRamReadAccess): '<S8>/EepromReadAccess1' */
  TrbActGsl_B.EepromReadAccess1_e =
    TrbActGsl_sNV_Z1_CONST_16BIT.TrbAct_rRCOReqAdpRate_NV;

  /* Sum: '<S8>/Sum1' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion17'
   */
  localSwitch2_of += ((Float32)TrbActGsl_B.EepromReadAccess1_e) *
    3.051757813E-005F;

  /* DataTypeConversion: '<S8>/Data Type Conversion16' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOReqAdpRateMin_C'
   */
  localSwitch_b = (((Float32)TrbAct_rRCOReqAdpRateMin_C) * 1.525878906E-005F) +
    1.525878906E-005F;

  /* Switch: '<S97>/Switch' incorporates:
   *  RelationalOperator: '<S97>/UpperRelop'
   */
  if (!(localSwitch2_of < localSwitch_b)) {
    localSwitch_b = localSwitch2_of;
  }

  /* Switch: '<S97>/Switch2' incorporates:
   *  RelationalOperator: '<S97>/LowerRelop1'
   */
  if (!(localSwitch2_of > localSwitch2_o)) {
    localSwitch2_o = localSwitch_b;
  }

  /* DataTypeConversion: '<S75>/OutDTConv' incorporates:
   *  Constant: '<S75>/offset'
   *  Constant: '<S75>/offset1'
   *  Constant: '<S75>/one_on_slope'
   *  Product: '<S75>/Product4'
   *  Sum: '<S75>/Add1'
   *  Sum: '<S75>/Add2'
   */
  localfractionTmp_0d = (32768.0F * localSwitch2_o) + 0.5F;
  if (localfractionTmp_0d < 65536.0F) {
    TrbActGsl_B.OutDTConv_l = (UInt16)localfractionTmp_0d;
  } else {
    TrbActGsl_B.OutDTConv_l = MAX_uint16_T;
  }

  /* S-Function (NvRamWriteAccess): '<S8>/EepromWriteAccess' */
  TrbActGsl_sNV_Z1_CONST_16BIT.TrbAct_rRCOReqAdpRate_NV =
    TrbActGsl_B.OutDTConv_l;

  /* DataTypeConversion: '<S8>/Data Type Conversion5' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOReqAdpOfsMax_C'
   */
  localSwitch2_of = ((Float32)TrbAct_rRCOReqAdpOfsMax_C) * 1.525878906E-005F;

  /* S-Function (NvRamReadAccess): '<S8>/EepromReadAccess' */
  TrbActGsl_B.EepromReadAccess_p =
    TrbActGsl_sNV_Z1_CONST_16BIT.TrbAct_rRCOReqAdpOfs_NV;

  /* Sum: '<S8>/Sum10' */
  localfractionTmp_0d = localSwitch_c + localAdd2_e;

  /* Logic: '<S8>/Logical Operator2' incorporates:
   *  Constant: '<S8>/TrbAct_rOpRCOAdpOfsThd1_C'
   *  Constant: '<S8>/TrbAct_rOpRCOAdpOfsThd2_C'
   *  Logic: '<S8>/Logical Operator6'
   *  RelationalOperator: '<S8>/Relational Operator1'
   *  RelationalOperator: '<S8>/Relational Operator2'
   */
  TrbAct_bAcvOfsRCOAdp_MP = (((localTmpSignalConversionAtAirSy <
    TrbAct_rOpRCOAdpOfsThd2_C) && (localTmpSignalConversionAtAirSy >
    TrbAct_rOpRCOAdpOfsThd1_C)) && (localTmpSignalConversionAtTrb_e));

  /* Switch: '<S8>/Switch4' incorporates:
   *  Constant: '<S8>/Rco_min_wg1'
   *  Constant: '<S8>/TrbAct_bAcvRCOAdp_C'
   *  Logic: '<S8>/Logical Operator4'
   */
  if (TrbAct_bAcvOfsRCOAdp_MP && TrbAct_bAcvRCOAdp_C) {
    localAdd2_e = localfractionTmp_0d;
  } else {
    localAdd2_e = 0.0F;
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   */
  localAdd2_e += ((Float32)TrbActGsl_B.EepromReadAccess_p) * 3.051757813E-005F;

  /* RelationalOperator: '<S100>/LowerRelop1' */
  localUpperRelop_n = (localAdd2_e > localSwitch2_of);

  /* DataTypeConversion: '<S8>/Data Type Conversion4' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOReqAdpOfsMin_C'
   */
  localSwitch_c = (((Float32)TrbAct_rRCOReqAdpOfsMin_C) * 1.525878906E-005F) -
    9.999847412E-001F;

  /* RelationalOperator: '<S100>/UpperRelop' */
  localTmpSignalConversionAtTrb_e = (localAdd2_e < localSwitch_c);

  /* Switch: '<S100>/Switch' */
  if (!localTmpSignalConversionAtTrb_e) {
    localSwitch_c = localAdd2_e;
  }

  /* Switch: '<S100>/Switch2' */
  if (!localUpperRelop_n) {
    localSwitch2_of = localSwitch_c;
  }

  /* Product: '<S68>/Product4' incorporates:
   *  Constant: '<S68>/offset'
   *  Constant: '<S68>/one_on_slope'
   *  Sum: '<S68>/Add1'
   */
  localAdd2_e = 32768.0F * localSwitch2_of;

  /* Sum: '<S68>/Add3' incorporates:
   *  Constant: '<S68>/offset3'
   */
  localfractionTmp_0d = localAdd2_e + 0.5F;

  /* RelationalOperator: '<S68>/Relational Operator' incorporates:
   *  Constant: '<S68>/offset2'
   */
  localUpperRelop_n = (localAdd2_e >= 0.0F);

  /* Sum: '<S68>/Add4' incorporates:
   *  Constant: '<S68>/offset4'
   */
  localSaturation01_g = localAdd2_e - 0.5F;

  /* Switch: '<S68>/Switch1' */
  if (localUpperRelop_n) {
    localAdd2_e = localfractionTmp_0d;
  } else {
    localAdd2_e = localSaturation01_g;
  }

  /* DataTypeConversion: '<S68>/OutDTConv' */
  localfractionTmp_0d = localAdd2_e;
  if (localfractionTmp_0d < 32768.0F) {
    if (localfractionTmp_0d >= -32768.0F) {
      TrbActGsl_B.OutDTConv = (SInt16)localfractionTmp_0d;
    } else {
      TrbActGsl_B.OutDTConv = MIN_int16_T;
    }
  } else {
    TrbActGsl_B.OutDTConv = MAX_int16_T;
  }

  /* S-Function (NvRamWriteAccess): '<S8>/EepromWriteAccess1' */
  TrbActGsl_sNV_Z1_CONST_16BIT.TrbAct_rRCOReqAdpOfs_NV = TrbActGsl_B.OutDTConv;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTqSys_tqIdcAirReqOutport2' incorporates:
   *  Inport: '<Root>/TqSys_tqIdcAirReq'
   */
  Rte_Read_R_TqSys_tqIdcAirReq_TqSys_tqIdcAirReq
    (&localTmpSignalConversionAtTqSys);

  /* PreLookup: '<S66>/Prelookup' */
  localTqSys_tqIdcAirReq_TrbAct_t = plook_u32s16f_binc
    (localTmpSignalConversionAtTqSys, (&(TrbAct_tqIdcAirReq_A[0])), 8U,
     &localAdd2_e);

  /* Interpolation_n-D: '<S63>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localSwitch2_f;
  localfrac[0] = localfractionTmp_0d;
  localfractionTmp_0d = localAdd2_e;
  localfrac[1] = localfractionTmp_0d;
  localbpIndex[0] = localExt_nEng_Ext_nEngRef2_A_9_;
  localbpIndex[1] = localTqSys_tqIdcAirReq_TrbAct_t;
  localSwitch2_f = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex, localfrac,
    (&(TrbAct_rRCOTestMod_M[0])), 9U);

  /* Sum: '<S8>/Sum7' */
  localSwitch1_m += localLookupTablenD_j;

  /* Switch: '<S8>/Switch6' incorporates:
   *  Constant: '<S8>/TrbAct_bAcvRCOAdp_C2'
   *  Product: '<S88>/Divide'
   *  Sum: '<S8>/Sum2'
   */
  if (TrbAct_bAcvRCOAdp_C) {
    localSwitch1_m = (localSwitch2_of + localSwitch1_m) * localSwitch2_o;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_bAcvTrbActCmdOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bAcvTrbActCmd'
   */
  Rte_Read_R_TrbAct_bAcvTrbActCmd_TrbAct_bAcvTrbActCmd
    (&localTmpSignalConversionAtTrb_i);

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOReq_C'
   *  DataTypeConversion: '<S8>/Data Type Conversion9'
   */
  if (!localTmpSignalConversionAtTrb_i) {
    localSwitch1_m = ((Float32)TrbAct_rRCOReq_C) * 1.525878906E-005F;
  }

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/TrbAct_bAcvRCOTestModRef1_C'
   */
  if (!TrbAct_bAcvRCOTestModRef1_C) {
    localSwitch2_f = localSwitch1_m;
  }

  /* Sum: '<S72>/Add1' incorporates:
   *  Constant: '<S72>/offset'
   */
  localfractionTmp_0d = localSwitch2_f;

  /* Sum: '<S72>/Add2' incorporates:
   *  Constant: '<S72>/offset1'
   *  Constant: '<S72>/one_on_slope'
   *  Product: '<S72>/Product4'
   */
  localAdd2_e = (65536.0F * localfractionTmp_0d) + 0.5F;

  /* DataTypeConversion: '<S72>/OutDTConv' */
  localfractionTmp_0d = localAdd2_e;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      localTmpSignalConversionAtAirSy = (UInt16)localfractionTmp_0d;
    } else {
      localTmpSignalConversionAtAirSy = 0U;
    }
  } else {
    localTmpSignalConversionAtAirSy = MAX_uint16_T;
  }

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S8>/TrbAct_bAcvRCOTestModRef2_C'
   *  Constant: '<S8>/TrbAct_rRCOTestMod_C'
   */
  if (TrbAct_bAcvRCOTestModRef2_C) {
    localTmpSignalConversionAtAirSy = TrbAct_rRCOTestMod_C;
  }

  /* RelationalOperator: '<S103>/LowerRelop1' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOMaxThd_C'
   */
  localUpperRelop_n = (localTmpSignalConversionAtAirSy > TrbAct_rRCOMaxThd_C);

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOMinThd_C'
   *  RelationalOperator: '<S103>/UpperRelop'
   */
  if (localTmpSignalConversionAtAirSy < TrbAct_rRCOMinThd_C) {
    localTmpSignalConversionAtAirSy = TrbAct_rRCOMinThd_C;
  }

  /* Switch: '<S103>/Switch2' incorporates:
   *  Constant: '<S8>/TrbAct_rRCOMaxThd_C'
   */
  if (localUpperRelop_n) {
    localTmpSignalConversionAtAirSy = TrbAct_rRCOMaxThd_C;
  }

  /* Switch: '<S56>/Switch' incorporates:
   *  Constant: '<S56>/Byp_Fonction_SC'
   *  Constant: '<S56>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAirSy = TrbAct_rRCOReq_B;
  }

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Byp_Fonction_SC'
   *  Constant: '<S57>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTr_jf = TrbAct_rRCOReqAdpOfs_B;
  } else {
    localTmpSignalConversionAtTr_jf = TrbActGsl_B.OutDTConv;
  }

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S58>/Byp_Fonction_SC'
   *  Constant: '<S58>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_n = TrbAct_rRCOReqAdpRate_B;
  } else {
    localTmpSignalConversionAtExt_n = TrbActGsl_B.OutDTConv_l;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_rRCOReqAdpOfsInport2' */
  Rte_Write_P_TrbAct_rRCOReqAdpOfs_TrbAct_rRCOReqAdpOfs
    (localTmpSignalConversionAtTr_jf);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_rRCOReqAdpRateInport2' */
  Rte_Write_P_TrbAct_rRCOReqAdpRate_TrbAct_rRCOReqAdpRate
    (localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_rRCOReqInport2' */
  Rte_Write_P_TrbAct_rRCOReq_TrbAct_rRCOReq(localTmpSignalConversionAtAirSy);

  /* Update for UnitDelay: '<S106>/UnitDelay' */
  TrbActGsl_DWork.UnitDelay = localSum1_ny;

  /* Update for UnitDelay: '<S106>/UnitDelay1' incorporates:
   *  Constant: '<S106>/Constant3'
   */
  TrbActGsl_DWork.UnitDelay_f = TRUE;

  /* Update for UnitDelay: '<S104>/UnitDelay' incorporates:
   *  Constant: '<S104>/Constant3'
   */
  TrbActGsl_DWork.UnitDelay_DSTATE_f = TRUE;

  /* Update for UnitDelay: '<S110>/UnitDelay' */
  TrbActGsl_DWork.UnitDelay_c = localSum1_gx;

  /* Update for UnitDelay: '<S110>/UnitDelay1' incorporates:
   *  Constant: '<S110>/Constant3'
   */
  TrbActGsl_DWork.UnitDelay_n = TRUE;

  /* Update for UnitDelay: '<S108>/UnitDelay' incorporates:
   *  Constant: '<S108>/Constant3'
   */
  TrbActGsl_DWork.UnitDelay_DSTATE_k = TRUE;

  /* Update for UnitDelay: '<S83>/Unit Delay' */
  TrbActGsl_DWork.UnitDelay_DSTATE = localLookupTablenD_g;
}

/* Output and update for exported function: RE_TrbActGsl_004_TEV */
void RE_TrbActGsl_004_TEV(void)
{
  Float32 localAdd2_a;
  Float32 localSaturation01_k;
  SInt16 localTmpSignalConversionAtT_mpy;
  UInt16 localTmpSignalConversionAtTr_mp;
  UInt16 localTmpSignalConversionAtPnm_g;
  UInt16 localTmpSignalConversionAtExt_l;
  UInt16 locallocalTmpSignalConversionAt;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_rOpTrbActEstim'
   *
   * Block requirements for '<S1>/F03_rOpTrbActEstim':
   *  1. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_037.02 ;
   *  2. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_014.01 ;
   *  3. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_015.01 ;
   *  4. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_017.01 ;
   *  5. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_029.01 ;
   *  6. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_030.02 ;
   *  7. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_031.02 ;
   *  8. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_028.01 ;
   *  9. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_038.01 ;
   *  10. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_027.01 ;
   *  11. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_040.01 ;
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_rRCOReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rRCOReq_INPUT'
   */
  Rte_Read_R_TrbAct_rRCOReq_TrbAct_rRCOReq(&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pDifMaxPnmActReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pDifMaxPnmActReq_INPUT'
   */
  Rte_Read_R_TrbAct_pDifMaxPnmActReq_TrbAct_pDifMaxPnmActReq
    (&localTmpSignalConversionAtT_mpy);

  /* Sum: '<S9>/Add' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  Lookup_n-D: '<S115>/Lookup Table (n-D)'
   */
  localAdd2_a = look2_iu16s16lfts16p3If_binlcs(locallocalTmpSignalConversionAt,
    localTmpSignalConversionAtT_mpy, (&(TrbAct_rRCOReq_A[0])),
    (&(TrbAct_pDifMaxPnmActReq_A[0])), (&(TrbAct_pDifPnmActEstim_M[0])),
    &TrbActGsl_ConstP.LookupTablenD_maxIn_l[0], 9U) - ((((Float32)
    localTmpSignalConversionAtT_mpy) * 8.0F) + 4.0F);

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S9>/Constant_63'
   *  Constant: '<S9>/TrbAct_bTrbActCf_SC'
   *  Product: '<S120>/Divide'
   */
  if (!TrbAct_bTrbActCf_SC) {
    localAdd2_a = -localAdd2_a;
  }

  /* Product: '<S117>/Product4' incorporates:
   *  Constant: '<S117>/offset'
   *  Constant: '<S117>/one_on_slope'
   *  Constant: '<S9>/Constant_62'
   *  Product: '<S119>/Divide'
   *  Sum: '<S117>/Add1'
   */
  localAdd2_a = ((-localAdd2_a) - 4.0F) * 0.125F;

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/offset2'
   *  Constant: '<S117>/offset3'
   *  Constant: '<S117>/offset4'
   *  RelationalOperator: '<S117>/Relational Operator'
   *  Sum: '<S117>/Add3'
   *  Sum: '<S117>/Add4'
   */
  if (localAdd2_a >= 0.0F) {
    localAdd2_a += 0.5F;
  } else {
    localAdd2_a -= 0.5F;
  }

  /* DataTypeConversion: '<S117>/OutDTConv' */
  if (localAdd2_a < 32768.0F) {
    if (localAdd2_a >= -32768.0F) {
      localTmpSignalConversionAtT_mpy = (SInt16)localAdd2_a;
    } else {
      localTmpSignalConversionAtT_mpy = MIN_int16_T;
    }
  } else {
    localTmpSignalConversionAtT_mpy = MAX_int16_T;
  }

  /* DataStoreWrite: '<S9>/Data Store Write8' */
  TrbAct_pDifTrbActEstim_MP = localTmpSignalConversionAtT_mpy;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  Constant: '<S9>/TrbAct_facFilGainTrbActPosn_C'
   */
  localAdd2_a = ((Float32)TrbAct_facFilGainTrbActPosn_C) * 1.525878906E-005F;

  /* Saturate: '<S123>/Saturation [0-1]' */
  localSaturation01_k = rt_SATURATE(localAdd2_a, 0.0F, 1.0F);

  /* Lookup_n-D: '<S116>/Lookup Table (n-D)' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pDifTrbEstimOutport2'
   */
  localAdd2_a = look2_1fw26bc2bcvbfbbr6dfbbnx
    (Rte_IrvRead_RE_TrbActGsl_004_TEV_TrbAct_pDifTrbEstim_irv(),
     localTmpSignalConversionAtT_mpy, (&(TrbAct_pDifTrbEstim_A[0])),
     (&(TrbAct_pDifTrbActEstim_A[0])), (&(TrbAct_rOpTrbActEstim_M[0])),
     &TrbActGsl_ConstP.pooled12[0], 16U);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_rOpTrbActEstim_INPUTOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpTrbActEstim_INPUT'
   */
  Rte_Read_R_TrbAct_rOpTrbActEstim_TrbAct_rOpTrbActEstim
    (&localTmpSignalConversionAtTr_mp);

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  TrbAct_rOpTrbActEstimPrev = ((Float32)localTmpSignalConversionAtTr_mp) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S118>/OutDTConv' incorporates:
   *  Constant: '<S118>/offset'
   *  Constant: '<S118>/offset1'
   *  Constant: '<S118>/one_on_slope'
   *  Product: '<S118>/Product4'
   *  Product: '<S123>/Product'
   *  Sum: '<S118>/Add1'
   *  Sum: '<S118>/Add2'
   *  Sum: '<S123>/Sum'
   *  Sum: '<S123>/Sum1'
   */
  localAdd2_a = ((((localAdd2_a - TrbAct_rOpTrbActEstimPrev) *
                   localSaturation01_k) + TrbAct_rOpTrbActEstimPrev) * 65536.0F)
    + 0.5F;
  if (localAdd2_a < 65536.0F) {
    if (localAdd2_a >= 0.0F) {
      locallocalTmpSignalConversionAt = (UInt16)localAdd2_a;
    } else {
      locallocalTmpSignalConversionAt = 0U;
    }
  } else {
    locallocalTmpSignalConversionAt = MAX_uint16_T;
  }

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S112>/Byp_Fonction_SC'
   *  Constant: '<S112>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTr_mp = TrbAct_rOpTrbActEstim_B;
  } else {
    localTmpSignalConversionAtTr_mp = locallocalTmpSignalConversionAt;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_rOpTrbActMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_rOpTrbActMesSI'
   */
  Rte_Read_R_Ext_rOpTrbActMesSI_Ext_rOpTrbActMesSI
    (&localTmpSignalConversionAtExt_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtPnmAct_rOpTrbActEstimOutport2' incorporates:
   *  Inport: '<Root>/PnmAct_rOpTrbActEstim'
   */
  Rte_Read_R_PnmAct_rOpTrbActEstim_PnmAct_rOpTrbActEstim
    (&localTmpSignalConversionAtPnm_g);

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S9>/TrbAct_bSelRatOpTrbAct_C'
   */
  if (TrbAct_bSelRatOpTrbAct_C) {
    locallocalTmpSignalConversionAt = localTmpSignalConversionAtPnm_g;
  }

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S9>/TrbAct_bPresSenTrbActCf_SC'
   */
  if (TrbAct_bPresSenTrbActCf_SC) {
    locallocalTmpSignalConversionAt = localTmpSignalConversionAtExt_l;
  }

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S113>/Byp_Fonction_SC'
   *  Constant: '<S113>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = TrbAct_rOpTrbAct_B;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_rOpTrbActEstimInport2' */
  Rte_Write_P_TrbAct_rOpTrbActEstim_TrbAct_rOpTrbActEstim
    (localTmpSignalConversionAtTr_mp);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_rOpTrbActInport2' */
  Rte_Write_P_TrbAct_rOpTrbAct_TrbAct_rOpTrbAct(locallocalTmpSignalConversionAt);
}

/* Start for exported function: RE_TrbActGsl_001_MSE */
void RE_TrbActGsl_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_TrbActGl_Rst'
   *
   * Block requirements for '<S1>/F00_TrbActGl_Rst':
   *  1. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_034.02 ;
   *  2. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_001.01 ;
   *  3. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_002.01 ;
   *  4. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_003.01 ;
   *  5. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_010.01 ;
   *  6. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_011.01 ;
   *  7. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_012.01 ;
   *  8. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_014.01 ;
   *  9. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_015.01 ;
   *  10. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_016.01 ;
   *  11. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_018.01 ;
   *  12. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_028.01 ;
   *  13. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_027.01 ;
   *  14. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_032.01 ;
   *  15. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_030.02 ;
   *  16. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_031.02 ;
   *  17. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_039.01 ;
   */
}

/* Output and update for exported function: RE_TrbActGsl_001_MSE */
void RE_TrbActGsl_001_MSE(void)
{
  Boolean localSwitch_e;
  UInt16 localSwitch_h;
  UInt16 localSwitch_ml;
  SInt16 localSwitch_ph;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_TrbActGl_Rst'
   *
   * Block requirements for '<S1>/F00_TrbActGl_Rst':
   *  1. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_034.02 ;
   *  2. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_001.01 ;
   *  3. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_002.01 ;
   *  4. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_003.01 ;
   *  5. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_010.01 ;
   *  6. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_011.01 ;
   *  7. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_012.01 ;
   *  8. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_014.01 ;
   *  9. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_015.01 ;
   *  10. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_016.01 ;
   *  11. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_018.01 ;
   *  12. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_028.01 ;
   *  13. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_027.01 ;
   *  14. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_032.01 ;
   *  15. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_030.02 ;
   *  16. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_031.02 ;
   *  17. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_039.01 ;
   */

  /* user code (Output function Body for TID5) */
  Runnable_TrbActGsl_Init();

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Byp_Fonction_SC'
   *  Constant: '<S14>/Int_BypC'
   *  Constant: '<S6>/TrbAct_bInhTrbActCtlIni_C'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_e = TrbAct_bInhTrbActCtl_B;
  } else {
    localSwitch_e = TrbAct_bInhTrbActCtlIni_C;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_bInhTrbActCtlInport2' */
  Rte_Write_P_TrbAct_bInhTrbActCtl_TrbAct_bInhTrbActCtl(localSwitch_e);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Byp_Fonction_SC'
   *  Constant: '<S10>/Int_BypC'
   *  Constant: '<S6>/TrbAct_rOpTrbActEstimIni_C'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_ml = TrbAct_rOpTrbAct_B;
  } else {
    localSwitch_ml = TrbAct_rOpTrbActEstimIni_C;
  }

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Byp_Fonction_SC'
   *  Constant: '<S12>/Int_BypC'
   *  Constant: '<S6>/TrbAct_rOpTrbActEstimIni_C'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_h = TrbAct_rOpTrbActEstim_B;
  } else {
    localSwitch_h = TrbAct_rOpTrbActEstimIni_C;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rOpTrbActEstimInport2' */
  Rte_Write_P_TrbAct_rOpTrbActEstim_TrbAct_rOpTrbActEstim(localSwitch_h);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rOpTrbActInport2' */
  Rte_Write_P_TrbAct_rOpTrbAct_TrbAct_rOpTrbAct(localSwitch_ml);

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Byp_Fonction_SC'
   *  Constant: '<S11>/Int_BypC'
   *  Constant: '<S6>/TrbAct_rOpTrbActEstimIni_C2'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_ml = TrbAct_rRCOReqRaw_B;
  } else {
    localSwitch_ml = 0U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rRCOReqRawInport2' */
  Rte_Write_P_TrbAct_rRCOReqRaw_TrbAct_rRCOReqRaw(localSwitch_ml);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   *  Constant: '<S6>/TrbAct_rOpTrbActEstimIni_C6'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_ph = TrbAct_pDifMaxPnmActReq_B;
  } else {
    localSwitch_ph = 0;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pDifMaxPnmActReqInport2' */
  Rte_Write_P_TrbAct_pDifMaxPnmActReq_TrbAct_pDifMaxPnmActReq(localSwitch_ph);

  /* SignalConversion: '<S18>/copy' incorporates:
   *  Constant: '<S6>/TrbAct_rOpTrbActEstimIni_C1'
   */
  TrbAct_pDifTrbEstim_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S18>/autosar_testpoint1' */

  /* S-Function Block: <S18>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pDifTrbEstimInport2' incorporates:
   *  Constant: '<S6>/TrbAct_rOpTrbActEstimIni_C1'
   *  SignalConversion: '<S6>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_TrbActGsl_001_MSE_TrbAct_pDifTrbEstim_irv(0);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Byp_Fonction_SC'
   *  Constant: '<S13>/Int_BypC'
   *  Constant: '<S6>/TrbAct_rRCOReqIni_C'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_ml = TrbAct_rRCOReq_B;
  } else {
    localSwitch_ml = TrbAct_rRCOReqIni_C;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rRCOReqInport2' */
  Rte_Write_P_TrbAct_rRCOReq_TrbAct_rRCOReq(localSwitch_ml);

  /* S-Function (NvRamReadAccess): '<S6>/EepromReadAccess' */
  TrbActGsl_B.EepromReadAccess =
    TrbActGsl_sNV_Z1_CONST_16BIT.TrbAct_rRCOReqAdpOfs_NV;

  /* DataTypeConversion Block: '<S17>/Data Type Conversion'
   *
   * Regarding '<S17>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_ph = TrbAct_rRCOReqAdpOfs_B;
  } else {
    localSwitch_ph = TrbActGsl_B.EepromReadAccess;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rRCOReqAdpOfsInport2' */
  Rte_Write_P_TrbAct_rRCOReqAdpOfs_TrbAct_rRCOReqAdpOfs(localSwitch_ph);

  /* S-Function (NvRamReadAccess): '<S6>/EepromReadAccess1' */
  TrbActGsl_B.EepromReadAccess1 =
    TrbActGsl_sNV_Z1_CONST_16BIT.TrbAct_rRCOReqAdpRate_NV;

  /* DataTypeConversion Block: '<S19>/Data Type Conversion'
   *
   * Regarding '<S19>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Byp_Fonction_SC'
   *  Constant: '<S19>/Int_BypC'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_ml = TrbAct_rRCOReqAdpRate_B;
  } else {
    localSwitch_ml = TrbActGsl_B.EepromReadAccess1;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rRCOReqAdpRateInport2' */
  Rte_Write_P_TrbAct_rRCOReqAdpRate_TrbAct_rRCOReqAdpRate(localSwitch_ml);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   *  Constant: '<S6>/TrbAct_rOpTrbActEstimIni_C3'
   */
  if (TRBACTGSL_ACTIVE_BYP_C) {
    localSwitch_ph = TrbAct_pDifTrbActReq_B;
  } else {
    localSwitch_ph = 0;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_pDifTrbActReqInport2' */
  Rte_Write_P_TrbAct_pDifTrbActReq_TrbAct_pDifTrbActReq(localSwitch_ph);
}

/* Model initialize function */
void Runnable_TrbActGsl_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  RE_TrbActGsl_002_TEV_Start();
  RE_TrbActGsl_003_TEV_Start();
  RE_TrbActGsl_001_MSE_Start();
}

#define TrbActGsl_STOP_SEC_CODE
#include "TrbActGsl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
