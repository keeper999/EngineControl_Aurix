/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpFctDiag                                            */
/* !Description     : HPPmpFctDiag– DIAGNOSTIC FONCTIONNEL DE LA REGULATION PRESSION RAIL*/
/*                                                                            */
/* !Module          : HPPmpFctDiag                                            */
/*                                                                            */
/* !File            : HPPmpFctDiag.c                                          */
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
/* !Reference       : PTS_DOC_5307784 / 07                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Jul 23 18:15:05 2014                              */
/*   Model name       : HPPmpFctDiag_AUTOCODE.mdl                             */
/*   Model version    : 1.358                                                 */
/*   Root subsystem   : /HPPmpFctDiag                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPFCTDIAG/HPPmpFctDiag$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   mbenfrad                               $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpFctDiag.h"
#include "HPPmpFctDiag_private.h"

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
#define HPPMPFCTDIAG_START_SEC_VAR_UNSPECIFIED
#include "HPPmpFctDiag_MemMap.h"

/* Block signals (auto storage) */
BlockIO_HPPmpFctDiag HPPmpFctDiag_B;

/* Block states (auto storage) */
D_Work_HPPmpFctDiag HPPmpFctDiag_DWork;

#define HPPMPFCTDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpFctDiag_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPFCTDIAG_START_SEC_CODE
#include "HPPmpFctDiag_MemMap.h"

/* Start for function-call system: '<S1>/HPPmpCtlFctDiag' */
void HPPmpFctD_HPPmpCtlFctDiag_Start(void)
{
  /* Start for enable SubSystem: '<S9>/HPPmpCtlFctDiag' */

  /* InitializeConditions for atomic SubSystem: '<S17>/F05_bMonRun_PFuCtl' */

  /* InitializeConditions for atomic SubSystem: '<S22>/F01_Transient_Condition' */

  /* InitializeConditions for UnitDelay: '<S55>/Unit Delay' */
  HPPmpFctDiag_DWork.UnitDelay_DSTATE_k = TRUE;

  /* InitializeConditions for UnitDelay: '<S58>/Unit Delay' */
  HPPmpFctDiag_DWork.UnitDelay_DSTATE_m = TRUE;

  /* end of InitializeConditions for SubSystem: '<S22>/F01_Transient_Condition' */

  /* end of InitializeConditions for SubSystem: '<S17>/F05_bMonRun_PFuCtl' */

  /* end of Start for SubSystem: '<S9>/HPPmpCtlFctDiag' */
}

/* Output and update for function-call system: '<S1>/HPPmpCtlFctDiag' */
void HPPmpFctDiag_HPPmpCtlFctDiag(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  UInt16 localLookUpTable_o;
  UInt16 localLookUpTable_c;
  UInt8 localDataTypeConversion1_f;
  Float32 localDataTypeConversion_g;
  Boolean localLogicalOperator2_c;
  Boolean localRelationalOperator3_c;
  Boolean localSwitch1_f;
  Float32 localInterpolationUsingPreloo_l;
  Float32 localfractionTmp_0d;
  UInt32 localSwitch2_m;
  Boolean localSwitch1_e;
  Float32 localSwitch;
  Boolean localRelationalOperator3_o;
  Boolean localSwitch1_o;
  UInt16 localSwitch_a;
  UInt32 locallocalSum_l;
  UInt32 locallocalSwitch2_m;
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S9>/HPPmpCtlFctDiag' incorporates:
   *  Constant: '<S9>/ConstVal'
   *  Constant: '<S9>/HPPMPFCTDIAG_u8Inhib'
   *  EnablePort: '<S17>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (HPPMPFCTDIAG_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_pFuRailSplMes, HPPmpFctDiag_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET6 */
    VEMS_vidGET(Ext_tiTDC, HPPmpFctDiag_B.VEMS_vidGET6);

    /* Outputs for atomic SubSystem: '<S17>/F06_tiHighPressure ' */

    /* NVRAM Read for EBDT Block <S23>/EepromReadAccess */
    VEMS_vidGET(PFuCtl_tiPrailOvrThd, PFuCtl_tiPrailOvrThd_prev);

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S23>/PFuCtl_pFuRailMesThd_C'
     *  RelationalOperator: '<S23>/Relational Operator1'
     *  Sum: '<S23>/Add1'
     */
    if (HPPmpFctDiag_B.VEMS_vidGET4 >= PFuCtl_pFuRailMesThd_C) {
      localtmp = HPPmpFctDiag_B.VEMS_vidGET6;
      locallocalSum_l = ((UInt32)localtmp) + PFuCtl_tiPrailOvrThd_prev;
      if (locallocalSum_l < ((UInt32)localtmp)) {
        locallocalSum_l = MAX_uint32_T;
      }

      HPPmpFctDiag_B.Switch = locallocalSum_l;
    } else {
      HPPmpFctDiag_B.Switch = PFuCtl_tiPrailOvrThd_prev;
    }

    /* NVRAM Write for EBDT Block <S23>/EepromWriteAccess */
    VEMS_vidSET(PFuCtl_tiPrailOvrThd, HPPmpFctDiag_B.Switch);

    /* end of Outputs for SubSystem: '<S17>/F06_tiHighPressure ' */
    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_tCoMes, HPPmpFctDiag_B.VEMS_vidGET5);

    /* DataTypeConversion: '<S17>/Data Type Conversion1' */
    localtmp = HPPmpFctDiag_B.VEMS_vidGET5 + 40;
    if (localtmp <= 0) {
      localDataTypeConversion1_f = 0U;
    } else if (localtmp > 255) {
      localDataTypeConversion1_f = MAX_uint8_T;
    } else {
      localDataTypeConversion1_f = (UInt8)localtmp;
    }

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET14 */
    VEMS_vidGET(PFuCtl_pFuRailDifIClCtl, HPPmpFctDiag_B.VEMS_vidGET14);

    /* Outputs for atomic SubSystem: '<S17>/F01_HPPmpCtlFctDiag' */

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    localDataTypeConversion_g = ((Float32)HPPmpFctDiag_B.VEMS_vidGET14) *
      1.192092896E-002F;

    /* Lookup: '<S25>/Look-Up Table'
     * About '<S25>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000  Bias -5.119921875E+007
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable), (&(PFuCtl_pFuRailINegThdDetDe_T[0])),
                  localDataTypeConversion1_f, (&(PFuCtl_tCoMes_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate1'
     *
     * Regarding '<S25>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* RelationalOperator: '<S18>/Relational Operator1' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion1'
     *  Lookup: '<S25>/Look-Up Table'
     */
    PFuCtl_bAcvDecCntDeICtlNeg = (localDataTypeConversion_g <= ((((Float32)
      localLookUpTable) * 781.25F) - 5.119922E+007F));

    /* Logic: '<S29>/Logical Operator2' incorporates:
     *  Logic: '<S29>/Logical Operator4'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    localLogicalOperator2_c = (PFuCtl_bAcvDecCntDeICtlNeg &&
      (!HPPmpFctDiag_DWork.UnitDelay_DSTATE_kf));

    /* Switch: '<S29>/Switch1' incorporates:
     *  UnitDelay: '<S34>/Unit Delay'
     */
    if (localLogicalOperator2_c) {
      localSwitch1_f = TRUE;
    } else {
      localSwitch1_f = HPPmpFctDiag_DWork.UnitDelay_DSTATE_g;
    }

    /* UnitDelay: '<S35>/Unit Delay' */
    localSwitch2_m = HPPmpFctDiag_DWork.UnitDelay_DSTATE_d;

    /* Switch: '<S29>/Switch2' incorporates:
     *  Constant: '<S18>/PFuCtl_tiThdDetDeICtl_C_1'
     *  Sum: '<S29>/Sum1'
     */
    if (localLogicalOperator2_c) {
      localSwitch2_m = PFuCtl_tiThdDetDeICtl_C + ((UInt32)
        HPPmpFctDiag_B.VEMS_vidGET6);
      if (localSwitch2_m < PFuCtl_tiThdDetDeICtl_C) {
        localSwitch2_m = MAX_uint32_T;
      }
    }

    /* Sum: '<S29>/Sum' */
    locallocalSum_l = localSwitch2_m - ((UInt32)HPPmpFctDiag_B.VEMS_vidGET6);
    if (locallocalSum_l > localSwitch2_m) {
      locallocalSum_l = 0U;
    }

    /* RelationalOperator: '<S29>/Relational Operator3' incorporates:
     *  Constant: '<S29>/Constant4'
     */
    localRelationalOperator3_c = (0U >= locallocalSum_l);

    /* Logic: '<S18>/Logical Operator1' incorporates:
     *  Logic: '<S29>/Logical Operator'
     */
    PFuCtl_bDgoORngNegDifI_PFuCtl = (PFuCtl_bAcvDecCntDeICtlNeg &&
      ((localSwitch1_f) && (localRelationalOperator3_c)));

    /* PreLookup: '<S27>/Prelookup' */
    localSwitch2_m = plook_u32u8f_binc(localDataTypeConversion1_f,
      (&(PFuCtl_tCoMes_A[0])), 8U, &localInterpolationUsingPreloo_l);

    /* Interpolation_n-D: '<S26>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    localInterpolationUsingPreloo_l = intrp1d_iu16p9ff_u32f_l_s(localSwitch2_m,
      localfractionTmp_0d, (&(PFuCtl_pFuRailIPosThdDetDe_T[0])));

    /* RelationalOperator: '<S18>/Relational Operator2' */
    PFuCtl_bAcvDecCntDeICtlPos = (localDataTypeConversion_g >=
      localInterpolationUsingPreloo_l);

    /* Logic: '<S28>/Logical Operator2' incorporates:
     *  Logic: '<S28>/Logical Operator4'
     *  UnitDelay: '<S30>/Unit Delay'
     */
    localLogicalOperator2_c = (PFuCtl_bAcvDecCntDeICtlPos &&
      (!HPPmpFctDiag_DWork.UnitDelay_DSTATE_e));

    /* Switch: '<S28>/Switch1' incorporates:
     *  UnitDelay: '<S31>/Unit Delay'
     */
    if (localLogicalOperator2_c) {
      localSwitch1_e = TRUE;
    } else {
      localSwitch1_e = HPPmpFctDiag_DWork.UnitDelay_DSTATE_n;
    }

    /* UnitDelay: '<S32>/Unit Delay' */
    localSwitch2_m = HPPmpFctDiag_DWork.UnitDelay_DSTATE_ol;

    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S18>/PFuCtl_tiThdDetDeICtl_C'
     *  Sum: '<S28>/Sum1'
     */
    if (localLogicalOperator2_c) {
      localSwitch2_m = PFuCtl_tiThdDetDeICtl_C + ((UInt32)
        HPPmpFctDiag_B.VEMS_vidGET6);
      if (localSwitch2_m < PFuCtl_tiThdDetDeICtl_C) {
        localSwitch2_m = MAX_uint32_T;
      }
    }

    /* Sum: '<S28>/Sum' */
    locallocalSwitch2_m = localSwitch2_m - ((UInt32)
      HPPmpFctDiag_B.VEMS_vidGET6);
    if (locallocalSwitch2_m > localSwitch2_m) {
      locallocalSwitch2_m = 0U;
    }

    /* RelationalOperator: '<S28>/Relational Operator3' incorporates:
     *  Constant: '<S28>/Constant4'
     */
    localLogicalOperator2_c = (0U >= locallocalSwitch2_m);

    /* Logic: '<S18>/Logical Operator6' incorporates:
     *  Logic: '<S28>/Logical Operator'
     */
    PFuCtl_bDgoORngPosDifI_PFuCtl = (PFuCtl_bAcvDecCntDeICtlPos &&
      ((localSwitch1_e) && (localLogicalOperator2_c)));

    /* Switch: '<S28>/Switch3' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    if (localLogicalOperator2_c) {
      PFuCtl_tiThdDetDeICtlDlyPos = 0U;
    } else {
      PFuCtl_tiThdDetDeICtlDlyPos = locallocalSwitch2_m;
    }

    /* Switch: '<S29>/Switch3' incorporates:
     *  Constant: '<S29>/Constant1'
     */
    if (localRelationalOperator3_c) {
      PFuCtl_tiThdDetDeICtlDlyNeg = 0U;
    } else {
      PFuCtl_tiThdDetDeICtlDlyNeg = locallocalSum_l;
    }

    /* Update for UnitDelay: '<S33>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_kf = PFuCtl_bAcvDecCntDeICtlNeg;

    /* Update for UnitDelay: '<S34>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_g = localSwitch1_f;

    /* Update for UnitDelay: '<S35>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_d = locallocalSum_l;

    /* Update for UnitDelay: '<S30>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_e = PFuCtl_bAcvDecCntDeICtlPos;

    /* Update for UnitDelay: '<S31>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_n = localSwitch1_e;

    /* Update for UnitDelay: '<S32>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_ol = locallocalSwitch2_m;

    /* end of Outputs for SubSystem: '<S17>/F01_HPPmpCtlFctDiag' */
    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET13 */
    VEMS_vidGET(PFuCtl_pFuRailDif, HPPmpFctDiag_B.VEMS_vidGET13);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_pFuReq, HPPmpFctDiag_B.VEMS_vidGET8);

    /* DataTypeConversion Block: '<S36>/Data Type Conversion'
     *
     * Regarding '<S36>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S37>/Data Type Conversion'
     *
     * Regarding '<S37>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Outputs for atomic SubSystem: '<S17>/F02_NegativeDiff' */

    /* Product: '<S38>/Divide' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion1'
     *  DataTypeConversion: '<S19>/Data Type Conversion2'
     */
    localDataTypeConversion_g = (((Float32)HPPmpFctDiag_B.VEMS_vidGET13) *
      781.25F) / (((Float32)HPPmpFctDiag_B.VEMS_vidGET8) * 781.25F);

    /* Outputs for atomic SubSystem: '<S38>/If Action Subsystem3' */

    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant1'
     *  Constant: '<S41>/Constant2'
     *  Constant: '<S41>/Constant3'
     *  Logic: '<S41>/Logical Operator1'
     *  RelationalOperator: '<S41>/Relational Operator'
     *  RelationalOperator: '<S41>/Relational Operator1'
     *  RelationalOperator: '<S41>/Relational Operator3'
     */
    if (((localDataTypeConversion_g != localDataTypeConversion_g) ||
         (localDataTypeConversion_g > 3.000000005E+038F)) || (-3.000000005E+038F
         > localDataTypeConversion_g)) {
      localDataTypeConversion_g = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S38>/If Action Subsystem3' */

    /* Product: '<S39>/Divide' incorporates:
     *  Constant: '<S19>/ConstVal'
     */
    PFuCtl_PrailLoopErr = 100.0F * localDataTypeConversion_g;

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/PFuCtl_tCoMesThd_C'
     *  Lookup: '<S36>/Look-Up Table'
     *  Lookup: '<S37>/Look-Up Table'
     *  RelationalOperator: '<S19>/Relational Operator1'
     */
    if (localDataTypeConversion1_f >= PFuCtl_tCoMesThd_C) {
      /* Lookup: '<S37>/Look-Up Table'
       * About '<S37>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
       * Output0 Data Type:  Fixed Point    U16  2^-7  FSlope 1.28  Bias -100.0
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_o), (&(PFuCtl_FuRailNegDifHotTcoThd_T[0])),
                     HPPmpFctDiag_B.VEMS_vidGET8, (&(PFuCtl_pFuReq_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate1'
       *
       * Regarding '<S37>/Data Type Duplicate1':
       *   Unused code path elimination
       */
      localSwitch_a = localLookUpTable_o;
    } else {
      /* Lookup: '<S36>/Look-Up Table'
       * About '<S36>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
       * Output0 Data Type:  Fixed Point    U16  2^-7  FSlope 1.28  Bias -100.0
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_c), (&(PFuCtl_FuRailNegDifColdTcoThd_T
        [0])), HPPmpFctDiag_B.VEMS_vidGET8, (&(PFuCtl_pFuReq_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate1'
       *
       * Regarding '<S36>/Data Type Duplicate1':
       *   Unused code path elimination
       */
      localSwitch_a = localLookUpTable_c;
    }

    /* RelationalOperator: '<S19>/Relational Operator' */
    PFuCtl_bDgoORngNeg_PFuCtl = (PFuCtl_PrailLoopErr <= ((((Float32)
      localSwitch_a) * 9.999999776E-003F) - 100.0F));

    /* end of Outputs for SubSystem: '<S17>/F02_NegativeDiff' */

    /* Outputs for atomic SubSystem: '<S17>/F03_PositiveDiff' */

    /* PreLookup: '<S44>/Prelookup' */
    locallocalSum_l = plook_u32u16f_binc(HPPmpFctDiag_B.VEMS_vidGET8,
      (&(PFuCtl_pFuReq_A[0])), 8U, &localSwitch);

    /* Interpolation_n-D: '<S42>/Interpolation Using Prelookup3' */
    localDataTypeConversion_g = localSwitch;
    localDataTypeConversion_g = intrp1d_iu16n7ff_u32f_l_ns(locallocalSum_l,
      localDataTypeConversion_g, (&(PFuCtl_FuRailPosDifColdTcoThd_T[0])));

    /* Interpolation_n-D: '<S43>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localSwitch;
    localSwitch = intrp1d_iu16n7ff_u32f_l_ns(locallocalSum_l,
      localfractionTmp_0d, (&(PFuCtl_FuRailPosDifHotTcoThd_T[0])));

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/PFuCtl_tCoMesThd_C'
     *  RelationalOperator: '<S20>/Relational Operator1'
     */
    if (!(localDataTypeConversion1_f >= PFuCtl_tCoMesThd_C)) {
      localSwitch = localDataTypeConversion_g;
    }

    /* RelationalOperator: '<S20>/Relational Operator2' */
    PFuCtl_bDgoORngPos_PFuCtl = (PFuCtl_PrailLoopErr >= localSwitch);

    /* end of Outputs for SubSystem: '<S17>/F03_PositiveDiff' */

    /* Outputs for atomic SubSystem: '<S17>/F04_ORngPFuRailMes' */

    /* RelationalOperator: '<S21>/Relational Operator' incorporates:
     *  Constant: '<S21>/PFuCtl_pFuReqMax_C'
     */
    localSwitch1_f = (HPPmpFctDiag_B.VEMS_vidGET4 > PFuCtl_pFuReqMax_C);

    /* Logic: '<S45>/Logical Operator2' incorporates:
     *  Logic: '<S45>/Logical Operator4'
     *  UnitDelay: '<S46>/Unit Delay'
     */
    localLogicalOperator2_c = ((localSwitch1_f) &&
      (!HPPmpFctDiag_DWork.UnitDelay_DSTATE_ar));

    /* Switch: '<S45>/Switch1' incorporates:
     *  UnitDelay: '<S47>/Unit Delay'
     */
    if (localLogicalOperator2_c) {
      localRelationalOperator3_c = TRUE;
    } else {
      localRelationalOperator3_c = HPPmpFctDiag_DWork.UnitDelay_DSTATE_l;
    }

    /* UnitDelay: '<S48>/Unit Delay' */
    localSwitch2_m = HPPmpFctDiag_DWork.UnitDelay_DSTATE_o;

    /* Switch: '<S45>/Switch2' incorporates:
     *  Constant: '<S21>/PFuCtl_tiPFuRailMes_C'
     *  Sum: '<S45>/Sum1'
     */
    if (localLogicalOperator2_c) {
      localSwitch2_m = PFuCtl_tiPFuRailMes_C + ((UInt32)
        HPPmpFctDiag_B.VEMS_vidGET6);
      if (localSwitch2_m < PFuCtl_tiPFuRailMes_C) {
        localSwitch2_m = MAX_uint32_T;
      }
    }

    /* Sum: '<S45>/Sum' */
    locallocalSum_l = localSwitch2_m - ((UInt32)HPPmpFctDiag_B.VEMS_vidGET6);
    if (locallocalSum_l > localSwitch2_m) {
      locallocalSum_l = 0U;
    }

    /* RelationalOperator: '<S45>/Relational Operator3' incorporates:
     *  Constant: '<S45>/Constant4'
     */
    localLogicalOperator2_c = (0U >= locallocalSum_l);

    /* Logic: '<S21>/Logical Operator1' incorporates:
     *  Logic: '<S45>/Logical Operator'
     */
    PFuCtl_bDgoORngMax_PFuCtl = ((localSwitch1_f) &&
      ((localRelationalOperator3_c) && (localLogicalOperator2_c)));

    /* Switch: '<S45>/Switch3' incorporates:
     *  Constant: '<S45>/Constant1'
     */
    if (localLogicalOperator2_c) {
      PFuCtl_tiPFuRailMesDly = 0U;
    } else {
      PFuCtl_tiPFuRailMesDly = locallocalSum_l;
    }

    /* Update for UnitDelay: '<S46>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_ar = localSwitch1_f;

    /* Update for UnitDelay: '<S47>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_l = localRelationalOperator3_c;

    /* Update for UnitDelay: '<S48>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_o = locallocalSum_l;

    /* end of Outputs for SubSystem: '<S17>/F04_ORngPFuRailMes' */
    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET */
    VEMS_vidGET(CoVSCtl_stAccP, HPPmpFctDiag_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET11 */
    VEMS_vidGET(PFuCtl_bAcvPFuCtl, HPPmpFctDiag_B.VEMS_vidGET11);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET9 */
    VEMS_vidGET(PFuCtl_bAcvETBPFuOplCtl, HPPmpFctDiag_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_bTotCutOff, HPPmpFctDiag_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET1 */
    VEMS_vidGET(EOM_tiEngRun, HPPmpFctDiag_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_nEng, HPPmpFctDiag_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_bFuTnkEmp, HPPmpFctDiag_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET15 */
    VEMS_vidGET(PFuCtl_bDiagAcvORngPos, HPPmpFctDiag_B.VEMS_vidGET15);

    /* Outputs for atomic SubSystem: '<S17>/F05_bMonRun_PFuCtl' */

    /* Outputs for atomic SubSystem: '<S22>/F01_Transient_Condition' */

    /* DataTypeConversion: '<S49>/Data Type Conversion3' */
    localDataTypeConversion_g = ((Float32)HPPmpFctDiag_B.VEMS_vidGET8) *
      781.25F;

    /* Abs: '<S49>/Abs1' incorporates:
     *  Sum: '<S49>/Add1'
     *  UnitDelay: '<S53>/Unit Delay'
     */
    PFuCtl_pFuReqDiff = ACTEMS_FabsF(localDataTypeConversion_g -
      HPPmpFctDiag_DWork.UnitDelay_DSTATE);

    /* Logic: '<S49>/Logical Operator1' */
    localSwitch1_f = !HPPmpFctDiag_B.VEMS_vidGET7;

    /* RelationalOperator: '<S49>/Relational Operator2' incorporates:
     *  Constant: '<S49>/PFuCtl_pPrailSpDiff_C'
     *  DataTypeConversion: '<S49>/Data Type Conversion'
     */
    localRelationalOperator3_c = (PFuCtl_pFuReqDiff >= (((Float32)
      PFuCtl_pPrailSpDiff_C) * 781.25F));

    /* Logic: '<S51>/Logical Operator2' incorporates:
     *  Logic: '<S51>/Logical Operator4'
     *  UnitDelay: '<S54>/Unit Delay'
     */
    localLogicalOperator2_c = ((localRelationalOperator3_c) &&
      (!HPPmpFctDiag_DWork.UnitDelay_DSTATE_i));

    /* Switch: '<S51>/Switch1' incorporates:
     *  UnitDelay: '<S55>/Unit Delay'
     */
    if (localLogicalOperator2_c) {
      localSwitch1_e = TRUE;
    } else {
      localSwitch1_e = HPPmpFctDiag_DWork.UnitDelay_DSTATE_k;
    }

    /* UnitDelay: '<S56>/Unit Delay' */
    localSwitch2_m = HPPmpFctDiag_DWork.UnitDelay_DSTATE_a;

    /* Switch: '<S51>/Switch2' incorporates:
     *  Constant: '<S49>/PFuCtl_tiTransPFuReq_C'
     *  Sum: '<S51>/Sum1'
     */
    if (localLogicalOperator2_c) {
      localSwitch2_m = PFuCtl_tiTransPFuReq_C + ((UInt32)
        HPPmpFctDiag_B.VEMS_vidGET6);
      if (localSwitch2_m < PFuCtl_tiTransPFuReq_C) {
        localSwitch2_m = MAX_uint32_T;
      }
    }

    /* Sum: '<S51>/Sum' */
    locallocalSum_l = localSwitch2_m - ((UInt32)HPPmpFctDiag_B.VEMS_vidGET6);
    if (locallocalSum_l > localSwitch2_m) {
      locallocalSum_l = 0U;
    }

    /* RelationalOperator: '<S51>/Relational Operator3' incorporates:
     *  Constant: '<S51>/Constant4'
     */
    localRelationalOperator3_o = (0U >= locallocalSum_l);

    /* Logic: '<S49>/Logical Operator7' incorporates:
     *  Logic: '<S49>/Logical Operator2'
     *  Logic: '<S51>/Logical Operator'
     */
    PFuCtl_bTransPFuReq = ((!localRelationalOperator3_c) && ((localSwitch1_e) &&
                            (localRelationalOperator3_o)));

    /* Logic: '<S52>/Logical Operator2' incorporates:
     *  Logic: '<S52>/Logical Operator4'
     *  UnitDelay: '<S57>/Unit Delay'
     */
    localLogicalOperator2_c = ((localSwitch1_f) &&
      (!HPPmpFctDiag_DWork.UnitDelay_DSTATE_al));

    /* Switch: '<S52>/Switch1' incorporates:
     *  UnitDelay: '<S58>/Unit Delay'
     */
    if (localLogicalOperator2_c) {
      localSwitch1_o = TRUE;
    } else {
      localSwitch1_o = HPPmpFctDiag_DWork.UnitDelay_DSTATE_m;
    }

    /* UnitDelay: '<S59>/Unit Delay' */
    localSwitch2_m = HPPmpFctDiag_DWork.UnitDelay_DSTATE_h;

    /* Switch: '<S52>/Switch2' incorporates:
     *  Constant: '<S49>/PFuCtl_tiAftrCutOff_C'
     *  Sum: '<S52>/Sum1'
     */
    if (localLogicalOperator2_c) {
      localSwitch2_m = PFuCtl_tiAftrCutOff_C + ((UInt32)
        HPPmpFctDiag_B.VEMS_vidGET6);
      if (localSwitch2_m < PFuCtl_tiAftrCutOff_C) {
        localSwitch2_m = MAX_uint32_T;
      }
    }

    /* Sum: '<S52>/Sum' */
    locallocalSwitch2_m = localSwitch2_m - ((UInt32)
      HPPmpFctDiag_B.VEMS_vidGET6);
    if (locallocalSwitch2_m > localSwitch2_m) {
      locallocalSwitch2_m = 0U;
    }

    /* RelationalOperator: '<S52>/Relational Operator3' incorporates:
     *  Constant: '<S52>/Constant4'
     */
    localLogicalOperator2_c = (0U >= locallocalSwitch2_m);

    /* Logic: '<S52>/Logical Operator' */
    PFuCtl_bDlyAftrCutOff = ((localSwitch1_o) && (localLogicalOperator2_c));

    /* Logic: '<S49>/Logical Operator5' incorporates:
     *  Constant: '<S49>/PFuCtl_nEngMin_C'
     *  Logic: '<S49>/Logical Operator10'
     *  Logic: '<S49>/Logical Operator8'
     *  RelationalOperator: '<S49>/Relational Operator1'
     */
    PFuCtl_bDiagAcvCond = (((HPPmpFctDiag_B.VEMS_vidGET11 &&
      (!HPPmpFctDiag_B.VEMS_vidGET7)) && (!HPPmpFctDiag_B.VEMS_vidGET9)) &&
      (HPPmpFctDiag_B.VEMS_vidGET3 > PFuCtl_nEngMin_C));

    /* Logic: '<S49>/Logical Operator3' incorporates:
     *  Constant: '<S49>/PFuCtl_pFuReqMin_C'
     *  RelationalOperator: '<S49>/Relational Operator3'
     */
    PFuCtl_bTransDiagAcvCond = ((((HPPmpFctDiag_B.VEMS_vidGET8 >
      PFuCtl_pFuReqMin_C) && PFuCtl_bTransPFuReq) && PFuCtl_bDlyAftrCutOff) &&
      PFuCtl_bDiagAcvCond);

    /* Switch: '<S51>/Switch3' incorporates:
     *  Constant: '<S51>/Constant1'
     */
    if (localRelationalOperator3_o) {
      PFuCtl_tiTransPFuReqDly = 0U;
    } else {
      PFuCtl_tiTransPFuReqDly = locallocalSum_l;
    }

    /* Switch: '<S52>/Switch3' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    if (localLogicalOperator2_c) {
      PFuCtl_tiAftrCutOffDly = 0U;
    } else {
      PFuCtl_tiAftrCutOffDly = locallocalSwitch2_m;
    }

    /* Update for UnitDelay: '<S53>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE = localDataTypeConversion_g;

    /* Update for UnitDelay: '<S54>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_i = localRelationalOperator3_c;

    /* Update for UnitDelay: '<S55>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_k = localSwitch1_e;

    /* Update for UnitDelay: '<S56>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_a = locallocalSum_l;

    /* Update for UnitDelay: '<S57>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_al = localSwitch1_f;

    /* Update for UnitDelay: '<S58>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_m = localSwitch1_o;

    /* Update for UnitDelay: '<S59>/Unit Delay' */
    HPPmpFctDiag_DWork.UnitDelay_DSTATE_h = locallocalSwitch2_m;

    /* end of Outputs for SubSystem: '<S22>/F01_Transient_Condition' */

    /* Outputs for atomic SubSystem: '<S22>/F02_Activation_Diag' */

    /* Logic: '<S50>/Logical Operator1' incorporates:
     *  Inport: '<Root>/FRM_bInhORngDifIHPPmpDiag'
     *  Logic: '<S50>/Logical Operator3'
     */
    PFuCtl_bMonRunORngDifI_PFuCtl = (PFuCtl_bTransDiagAcvCond && (!GDGAR_bGetFRM
                                      (FRM_FRM_INHORNGDIFIHPPMPDIAG)));

    /* Logic: '<S50>/Logical Operator6' incorporates:
     *  Inport: '<Root>/FRM_bInhORngNegHPPmpDiag'
     *  Logic: '<S50>/Logical Operator7'
     */
    PFuCtl_bMonRunORngNeg_PFuCtl = (PFuCtl_bTransDiagAcvCond && (!GDGAR_bGetFRM
      (FRM_FRM_INHORNGNEGHPPMPDIAG)));

    /* Logic: '<S50>/Logical Operator9' incorporates:
     *  Inport: '<Root>/FRM_bInhORngPosHPPmpDiag'
     *  Logic: '<S50>/Logical Operator12'
     *  Logic: '<S50>/Logical Operator5'
     */
    localLogicalOperator2_c = ((PFuCtl_bTransDiagAcvCond && (!GDGAR_bGetFRM
      (FRM_FRM_INHORNGPOSHPPMPDIAG))) && (!HPPmpFctDiag_B.VEMS_vidGET2));

    /* Logic: '<S50>/Logical Operator10' */
    PFuCtl_bMonRunORngIFrz_PFuCtl = (PFuCtl_bMonRunORngNeg_PFuCtl ||
      (localLogicalOperator2_c));

    /* Logic: '<S50>/Logical Operator11' */
    PFuCtl_bMonRunORngPos_PFuCtl = ((localLogicalOperator2_c) &&
      HPPmpFctDiag_B.VEMS_vidGET15);

    /* Logic: '<S50>/Logical Operator4' incorporates:
     *  Constant: '<S50>/ConstVal'
     *  Constant: '<S50>/PFuCtl_tiORngDly_C'
     *  DataTypeConversion: '<S50>/Data Type Conversion1'
     *  Inport: '<Root>/FRM_bInhORngMaxHPPmpDiag'
     *  Logic: '<S50>/Logical Operator2'
     *  Logic: '<S50>/Logical Operator8'
     *  RelationalOperator: '<S50>/Relational Operator1'
     *  RelationalOperator: '<S50>/Relational Operator2'
     */
    PFuCtl_bMonRunORngMax_PFuCtl = (((PFuCtl_bDiagAcvCond &&
      (!(HPPmpFctDiag_B.VEMS_vidGET == 0))) && (!GDGAR_bGetFRM
      (FRM_FRM_INHORNGMAXHPPMPDIAG))) && (mul_u32_u32_u32_sat
      (HPPmpFctDiag_B.VEMS_vidGET1, 1000U) > PFuCtl_tiORngDly_C));

    /* end of Outputs for SubSystem: '<S22>/F02_Activation_Diag' */

    /* end of Outputs for SubSystem: '<S17>/F05_bMonRun_PFuCtl' */
    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET10 */
    VEMS_vidGET(PFuCtl_bAcvIFrzPrailDif, HPPmpFctDiag_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET12 */
    VEMS_vidGET(PFuCtl_bDetAgWdPmpCmdLim, HPPmpFctDiag_B.VEMS_vidGET12);

    /* Outputs for atomic SubSystem: '<S17>/F07_IFrz' */

    /* Logic: '<S24>/Logical Operator2' incorporates:
     *  Logic: '<S24>/Logical Operator1'
     */
    PFuCtl_bDgoORngIFrz_PFuCtl = (HPPmpFctDiag_B.VEMS_vidGET10 &&
      (!HPPmpFctDiag_B.VEMS_vidGET12));

    /* end of Outputs for SubSystem: '<S17>/F07_IFrz' */
  }

  /* end of Outputs for SubSystem: '<S9>/HPPmpCtlFctDiag' */
}

/* Output and update for function-call system: '<S1>/GDGAR_vidGdu1' */
void HPPmpFctDiag_GDGAR_vidGdu1(void)
{
  /* Outputs for atomic SubSystem: '<S4>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S12>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGNEGDIFI_PFUCTL, PFuCtl_bDgoORngNegDifI_PFuCtl,
               PFuCtl_bMonRunORngDifI_PFuCtl, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S4>/GDGAR_vidGdu' */
}

/* Output and update for function-call system: '<S1>/GDGAR_vidGdu2' */
void HPPmpFctDiag_GDGAR_vidGdu2(void)
{
  /* Outputs for atomic SubSystem: '<S5>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S13>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGNEG_PFUCTL, PFuCtl_bDgoORngNeg_PFuCtl,
               PFuCtl_bMonRunORngNeg_PFuCtl, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S5>/GDGAR_vidGdu' */
}

/* Output and update for function-call system: '<S1>/GDGAR_vidGdu3' */
void HPPmpFctDiag_GDGAR_vidGdu3(void)
{
  /* Outputs for atomic SubSystem: '<S6>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S14>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGPOS_PFUCTL, PFuCtl_bDgoORngPos_PFuCtl,
               PFuCtl_bMonRunORngPos_PFuCtl, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S6>/GDGAR_vidGdu' */
}

/* Output and update for function-call system: '<S1>/GDGAR_vidGdu4' */
void HPPmpFctDiag_GDGAR_vidGdu4(void)
{
  /* Outputs for atomic SubSystem: '<S7>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S15>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGMAX_PFUCTL, PFuCtl_bDgoORngMax_PFuCtl,
               PFuCtl_bMonRunORngMax_PFuCtl, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S7>/GDGAR_vidGdu' */
}

/* Output and update for function-call system: '<S1>/GDGAR_vidGdu5' */
void HPPmpFctDiag_GDGAR_vidGdu5(void)
{
  /* Outputs for atomic SubSystem: '<S8>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S16>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGIFRZ_PFUCTL, PFuCtl_bDgoORngIFrz_PFuCtl,
               PFuCtl_bMonRunORngIFrz_PFuCtl, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S8>/GDGAR_vidGdu' */
}

/* Start for exported function: PFuCtl_EveSpl_HPPmpFctDiag */
void PFuCtl_EveSpl_HPPmpFctDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */

  /* Start for S-Function (fcncallgen): '<S10>/gen' incorporates:
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu1'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu2'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu3'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu4'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu5'
   *  Start for SubSystem: '<S1>/HPPmpCtlFctDiag'
   */
  HPPmpFctD_HPPmpCtlFctDiag_Start();
}

/* Output and update for exported function: PFuCtl_EveSpl_HPPmpFctDiag */
void PFuCtl_EveSpl_HPPmpFctDiag(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S10>/gen' incorporates:
   *  SubSystem: '<S1>/GDGAR_vidGdu'
   *  SubSystem: '<S1>/GDGAR_vidGdu1'
   *  SubSystem: '<S1>/GDGAR_vidGdu2'
   *  SubSystem: '<S1>/GDGAR_vidGdu3'
   *  SubSystem: '<S1>/GDGAR_vidGdu4'
   *  SubSystem: '<S1>/GDGAR_vidGdu5'
   *  SubSystem: '<S1>/HPPmpCtlFctDiag'
   */
  HPPmpFctDiag_HPPmpCtlFctDiag();

  /* Outputs for atomic SubSystem: '<S3>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S11>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGPOSDIFI_PFUCTL, PFuCtl_bDgoORngPosDifI_PFuCtl,
               PFuCtl_bMonRunORngDifI_PFuCtl, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S3>/GDGAR_vidGdu' */
  HPPmpFctDiag_GDGAR_vidGdu1();
  HPPmpFctDiag_GDGAR_vidGdu2();
  HPPmpFctDiag_GDGAR_vidGdu3();
  HPPmpFctDiag_GDGAR_vidGdu4();
  HPPmpFctDiag_GDGAR_vidGdu5();
}

/* Model initialize function */
void HPPmpFctDiag_initialize(void)
{
  /* Start for S-Function (fcncallgen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   */
  PFuCtl_EveSpl_HPPmpFctDiag_Start();
}

#define HPPMPFCTDIAG_STOP_SEC_CODE
#include "HPPmpFctDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
