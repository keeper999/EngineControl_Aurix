/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpMdl                                                */
/* !Description     : HPPmpMdl - Modèle de la pompe haute pression            */
/*                                                                            */
/* !Module          : HPPmpMdl                                                */
/*                                                                            */
/* !File            : HPPmpMdl.c                                              */
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
/* !Reference       : PTS_DOC_5149850 / 03                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Apr 04 17:41:39 2013                              */
/*   Model name       : HPPmpMdl_AUTOCODE.mdl                                 */
/*   Model version    : 1.167                                                 */
/*   Root subsystem   : /HPPmpMdl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPMDL/HPPmpMdl.c_v    $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpMdl.h"
#include "HPPmpMdl_private.h"

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
#define HPPMPMDL_START_SEC_VAR_UNSPECIFIED
#include "HPPmpMdl_MemMap.h"

/* Block signals (auto storage) */
BlockIO_HPPmpMdl HPPmpMdl_B;

/* Block states (auto storage) */
D_Work_HPPmpMdl HPPmpMdl_DWork;

#define HPPMPMDL_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpMdl_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPMDL_START_SEC_CODE
#include "HPPmpMdl_MemMap.h"

void HPPmpMdl_ASYNC1(int controlPortIdx)
{
}

void HPPmpMdl_ASYNC2(int controlPortIdx)
{
}

/*
 * Output and update for atomic system:
 *    '<S6>/F01_HPPmpMdl_RTSt_inhib'
 *    '<S13>/F01_HPPmpMdl_RTSt_inhib'
 */
void HPPmpMd_F01_HPPmpMdl_RTSt_inhib(rtB_F01_HPPmpMdl_RTSt_inhib_HPP *localB)
{
  /* SignalConversion: '<S12>/Signal Conversion1' incorporates:
   *  Constant: '<S12>/Const'
   */
  localB->SignalConversion1 = FALSE;

  /* Constant: '<S12>/Const1' */
  localB->Const1 = 0U;
}

/* Output and update for function-call system: '<S1>/F01_HPPmpMdl_Ini' */
void HPPmpMdl_F01_HPPmpMdl_Ini(void)
{
  /* Outputs for atomic SubSystem: '<S6>/F01_HPPmpMdl_RTSt_inhib' */
  HPPmpMd_F01_HPPmpMdl_RTSt_inhib(&HPPmpMdl_B.F01_HPPmpMdl_RTSt_inhib);

  /* end of Outputs for SubSystem: '<S6>/F01_HPPmpMdl_RTSt_inhib' */

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
  VEMS_vidSET(PFuCtl_bDetAgWdPmpCmdLim,
              HPPmpMdl_B.F01_HPPmpMdl_RTSt_inhib.SignalConversion1);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
  VEMS_vidSET(PFuCtl_mFuPmpEstimRaw, HPPmpMdl_B.F01_HPPmpMdl_RTSt_inhib.Const1);
}

/* Output and update for exported function: PFuCtl_EveRst_HPPmpMdl */
void PFuCtl_EveRst_HPPmpMdl(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_HPPmpMdl_Ini'
   *
   * Block requirements for '<S1>/F01_HPPmpMdl_Ini':
   *  1. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_002.01 ;
   *  2. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_011.01 ;
   *  3. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_010.01 ;
   *  4. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_009.01 ;
   *  5. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_001.02 ;
   */
  HPPmpMdl_F01_HPPmpMdl_Ini();
}

/* Output and update for function-call system: '<S1>/F01_HPPmpMdl_RTSt' */
void HPPmpMdl_F01_HPPmpMdl_RTSt(void)
{
  /* Outputs for enable SubSystem: '<S7>/F01_HPPmpMdl_RTSt' incorporates:
   *  Constant: '<S7>/ConstVal'
   *  Constant: '<S7>/VLVINSPMGT_u8Inhib'
   *  EnablePort: '<S13>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (HPPMPMDL_u8Inhib != 90) {
    /* Outputs for atomic SubSystem: '<S13>/F01_HPPmpMdl_RTSt_inhib' */
    HPPmpMd_F01_HPPmpMdl_RTSt_inhib(&HPPmpMdl_B.F01_HPPmpMdl_RTSt_inhib_j);

    /* end of Outputs for SubSystem: '<S13>/F01_HPPmpMdl_RTSt_inhib' */

    /* S-Function "vems_vidSET" Block: <S13>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bDetAgWdPmpCmdLim,
                HPPmpMdl_B.F01_HPPmpMdl_RTSt_inhib_j.SignalConversion1);

    /* S-Function "vems_vidSET" Block: <S13>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_mFuPmpEstimRaw,
                HPPmpMdl_B.F01_HPPmpMdl_RTSt_inhib_j.Const1);
  }

  /* end of Outputs for SubSystem: '<S7>/F01_HPPmpMdl_RTSt' */
}

/* Output and update for exported function: PFuCtl_EveRTSt_HPPmpMdl */
void PFuCtl_EveRTSt_HPPmpMdl(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_HPPmpMdl_RTSt'
   *
   * Block requirements for '<S1>/F01_HPPmpMdl_RTSt':
   *  1. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_002.01 ;
   *  2. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_011.01 ;
   *  3. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_010.01 ;
   *  4. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_009.01 ;
   *  5. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_001.02 ;
   */
  HPPmpMdl_F01_HPPmpMdl_RTSt();
}

/* Output and update for function-call system: '<S1>/F02_HPPmpMdl_StTR' */
void HPPmpMdl_F02_HPPmpMdl_StTR(void)
{
  /* Outputs for enable SubSystem: '<S8>/F02_HPPmpMdl_StTR' incorporates:
   *  Constant: '<S8>/ConstVal'
   *  Constant: '<S8>/VLVINSPMGT_u8Inhib'
   *  EnablePort: '<S15>/Enable'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if (HPPMPMDL_u8Inhib != 90) {
    /* S-Function "vems_vidSET" Block: <S15>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_agPmpCmdReq, PFuCtl_agPmpCmdReqIni_C);

    /* S-Function "vems_vidSET" Block: <S15>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_tiPmpCmdReq, PFuCtl_tiPmpCmdReqIni_C);
  }

  /* end of Outputs for SubSystem: '<S8>/F02_HPPmpMdl_StTR' */
}

/* Output and update for exported function: PFuCtl_EveStTR_HPPmpMdl */
void PFuCtl_EveStTR_HPPmpMdl(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_HPPmpMdl_StTR'
   *
   * Block requirements for '<S1>/F02_HPPmpMdl_StTR':
   *  1. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_002.01 ;
   *  2. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_011.01 ;
   *  3. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_010.01 ;
   *  4. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_009.01 ;
   *  5. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_001.02 ;
   */
  HPPmpMdl_F02_HPPmpMdl_StTR();
}

/* Output and update for function-call system: '<S1>/F03_HPPmpMdl' */
void HPPmpMdl_F03_HPPmpMdl(void)
{
  /* local block i/o variables */
  UInt32 localLookUpTable;
  UInt32 localLookUpTable_p;
  UInt16 localLookUpTable_f;
  UInt16 localLookUpTable_a;
  UInt16 localLookUpTable_i;
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable2D_c;
  UInt16 localLookUpTable2D_a;
  UInt16 localLookUpTable2D_d;
  UInt16 localLookUpTable_ix;
  UInt16 localLookUpTable2D_g;
  UInt16 localLookUpTable_l;
  Boolean localRelationalOperator_k;
  Boolean localRelationalOperator1_k;
  Boolean localLogic[2];
  Boolean localUnitDelay1;
  Float32 localDataTypeConversion1;
  Boolean localSwitch2_i;
  Boolean localOR3;
  Float32 localAdd2_hi;
  Boolean localLogicalOperator2;
  SInt16 localSwitch4;
  UInt16 localSwitch2;
  SInt32 localAdd2_g;
  Float32 localtmp;
  UInt32 localtmp_0;

  /* Outputs for enable SubSystem: '<S9>/F03_HPPmpMdl' incorporates:
   *  Constant: '<S9>/ConstVal'
   *  Constant: '<S9>/VLVINSPMGT_u8Inhib'
   *  EnablePort: '<S16>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (HPPMPMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET12 */
    VEMS_vidGET(PFuCtl_mFuPmpReq, HPPmpMdl_B.VEMS_vidGET12);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET6 */
    VEMS_vidGET(FuSysM_tFuUsPmp, HPPmpMdl_B.VEMS_vidGET6);

    /* DataTypeConversion Block: '<S21>/Data Type Conversion'
     *
     * Regarding '<S21>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S22>/Data Type Conversion'
     *
     * Regarding '<S22>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S35>/Data Type Conversion'
     *
     * Regarding '<S35>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_nEng, HPPmpMdl_B.VEMS_vidGET3);

    /* DataTypeConversion Block: '<S23>/Data Type Conversion'
     *
     * Regarding '<S23>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S37>/Data Type Conversion'
     *
     * Regarding '<S37>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S38>/Data Type Conversion1'
     *
     * Regarding '<S38>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate1'
     *
     * Regarding '<S38>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S40>/Data Type Conversion1'
     *
     * Regarding '<S40>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S40>/Data Type Duplicate1'
     *
     * Regarding '<S40>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S41>/Data Type Conversion1'
     *
     * Regarding '<S41>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S41>/Data Type Duplicate1'
     *
     * Regarding '<S41>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_pFuRailSplMes, HPPmpMdl_B.VEMS_vidGET4);

    /* DataTypeConversion Block: '<S20>/Data Type Conversion'
     *
     * Regarding '<S20>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S23>/Data Type Conversion1'
     *
     * Regarding '<S23>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate1'
     *
     * Regarding '<S23>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Outputs for atomic SubSystem: '<S16>/F01_VolFuPmpClcn'
     * Block description for '<S16>/F01_VolFuPmpClcn':
     *  This module is executed at each spill event, at the same time as its parent module.  It calculates the fuel mass to be pumped to the rail at the next pump delivery. The fuel mass to be pumped is the sum of 2 terms:\NL
     *  - the fuel quantity to be injected for the next 2 combustions;\NL              - the fuel mass required to get the variation of rail pressure as requested by the PI controler and according to calibration table \var{KtFPRC_m_FuelMassVsPrssDlta} in g;\NL
     *
     * Block requirements for '<S16>/F01_VolFuPmpClcn':
     *  1. SubSystem "F01_VolFuPmpClcn" !Trace_To : VEMS_E_10_08013_003.021 ;
     */

    /* DataTypeConversion: '<S17>/Data Type Conversion1' */
    localDataTypeConversion1 = (((Float32)HPPmpMdl_B.VEMS_vidGET12) *
      7.450580597E-009F) - 0.0078125F;

    /* Lookup: '<S21>/Look-Up Table'
     * About '<S21>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias 233.0
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_ix), (&(PFuCtl_dens_T[0])),
                  HPPmpMdl_B.VEMS_vidGET6, (&(PFuCtl_tFuEstim_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S21>/Data Type Duplicate1'
     *
     * Regarding '<S21>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
     *  Lookup: '<S21>/Look-Up Table'
     */
    PFuCtl_densEstim = ((Float32)localLookUpTable_ix) * 3.051757813E-005F;

    /* Product: '<S26>/Divide' */
    localDataTypeConversion1 /= PFuCtl_densEstim;

    /* Outputs for atomic SubSystem: '<S26>/If Action Subsystem3' */

    /* Switch: '<S31>/Switch1' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant2'
     *  Constant: '<S31>/Constant3'
     *  Logic: '<S31>/Logical Operator1'
     *  RelationalOperator: '<S31>/Relational Operator'
     *  RelationalOperator: '<S31>/Relational Operator1'
     *  RelationalOperator: '<S31>/Relational Operator3'
     */
    if (((localDataTypeConversion1 != localDataTypeConversion1) ||
         (localDataTypeConversion1 > 3.000000005E+038F)) || (-3.000000005E+038F >
         localDataTypeConversion1)) {
      PFuCtl_volFuReq = 0.0F;
    } else {
      PFuCtl_volFuReq = localDataTypeConversion1;
    }

    /* end of Outputs for SubSystem: '<S26>/If Action Subsystem3' */

    /* Lookup2D: '<S23>/Look-Up Table (2-D)'
     * About '<S23>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_g), (&(PFuCtl_rVolEfcPmp_M[0])),
                       HPPmpMdl_B.VEMS_vidGET3, (&(PFuCtl_nEng_A[0])), 15U,
                       HPPmpMdl_B.VEMS_vidGET4, (&(PFuCtl_pFuRailSplMes_A[0])),
                       15U);

    /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate2'
     *
     * Regarding '<S23>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup: '<S22>/Look-Up Table'
     * About '<S22>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias 233.0
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_l), (&(PFuCtl_rVolEfcPmpCor_T[0])),
                  HPPmpMdl_B.VEMS_vidGET6, (&(PFuCtl_tFuEstim_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate1'
     *
     * Regarding '<S22>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S27>/Divide' */
    PFuCtl_rVolEfcPmp = (((Float32)localLookUpTable2D_g) * 3.051757813E-005F) *
      (((Float32)localLookUpTable_l) * 3.051757813E-005F);

    /* Product: '<S25>/Divide' */
    localDataTypeConversion1 = PFuCtl_volFuReq / PFuCtl_rVolEfcPmp;

    /* Outputs for atomic SubSystem: '<S25>/If Action Subsystem3' */

    /* Switch: '<S29>/Switch1' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S29>/Constant2'
     *  Constant: '<S29>/Constant3'
     *  Logic: '<S29>/Logical Operator1'
     *  RelationalOperator: '<S29>/Relational Operator'
     *  RelationalOperator: '<S29>/Relational Operator1'
     *  RelationalOperator: '<S29>/Relational Operator3'
     */
    if (((localDataTypeConversion1 != localDataTypeConversion1) ||
         (localDataTypeConversion1 > 3.000000005E+038F)) || (-3.000000005E+038F >
         localDataTypeConversion1)) {
      localDataTypeConversion1 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S25>/If Action Subsystem3' */

    /* Lookup: '<S20>/Look-Up Table'
     * About '<S20>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Output0 Data Type:  Fixed Point    U32  2^-27  Bias -0.015625
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U32_U16( &(localLookUpTable_p), (&(PFuCtl_OfsVolPmpCor_T[0])),
                   HPPmpMdl_B.VEMS_vidGET4, (&(PFuCtl_pFuRailSplMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S20>/Data Type Duplicate1'
     *
     * Regarding '<S20>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S17>/Data Type Conversion5' incorporates:
     *  Lookup: '<S20>/Look-Up Table'
     */
    PFuCtl_OfsVolPmpCor = (((Float32)localLookUpTable_p) * 7.450580597E-009F) -
      0.015625F;

    /* DataTypeConversion: '<S24>/OutDTConv' incorporates:
     *  Constant: '<S24>/offset'
     *  Constant: '<S24>/offset1'
     *  Constant: '<S24>/one_on_slope'
     *  Product: '<S24>/Product4'
     *  Sum: '<S17>/Add1'
     *  Sum: '<S24>/Add1'
     *  Sum: '<S24>/Add2'
     */
    localtmp = (((localDataTypeConversion1 + PFuCtl_OfsVolPmpCor) - -0.015625F) *
                1.34217728E+008F) + 0.5F;
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        PFuCtl_volFuReqEfc = (UInt32)localtmp;
      } else {
        PFuCtl_volFuReqEfc = 0U;
      }
    } else {
      PFuCtl_volFuReqEfc = MAX_uint32_T;
    }

    /* end of Outputs for SubSystem: '<S16>/F01_VolFuPmpClcn' */
    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET13 */
    VEMS_vidGET(Sync_bAcvSyncBUMCamShaft, HPPmpMdl_B.VEMS_vidGET13);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET8 */
    VEMS_vidGET(PFuCtl_NrProfCmd, HPPmpMdl_B.VEMS_vidGET8);

    /* DataTypeConversion Block: '<S39>/Data Type Conversion1'
     *
     * Regarding '<S39>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S39>/Data Type Duplicate1'
     *
     * Regarding '<S39>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET9 */
    VEMS_vidGET(PFuCtl_bAcvLrnInProgs, HPPmpMdl_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, HPPmpMdl_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_uBatt, HPPmpMdl_B.VEMS_vidGET5);

    /* DataTypeConversion Block: '<S39>/Data Type Conversion'
     *
     * Regarding '<S39>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S40>/Data Type Conversion'
     *
     * Regarding '<S40>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S41>/Data Type Conversion'
     *
     * Regarding '<S41>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET11 */
    VEMS_vidGET(PFuCtl_bInhPFuCtl, HPPmpMdl_B.VEMS_vidGET11);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET10 */
    VEMS_vidGET(PFuCtl_bAcvPFuCtl, HPPmpMdl_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET1 */
    VEMS_vidGET(ActrTstHPPmp_bActrTstInProgs, HPPmpMdl_B.VEMS_vidGET1_o);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET */
    VEMS_vidGET(ActrTstHPPmp_agWdPmpCmdReq, HPPmpMdl_B.VEMS_vidGET_c);

    /* Outputs for atomic SubSystem: '<S16>/F02_AgBegPmpAct'
     * Block description for '<S16>/F02_AgBegPmpAct':
     *  This module is executed at each spill event, at the same time as its parent module.  It calculates the spill valve pulse length (\var{VfFPPR_phi_SpillValvePlsLen}), the spill valve angle (\var{VfFPPR_phi_SpillVlvAngle}) which is the crankshaft angle separation between the spill event interrupt and the start of spill valve pulse and the flag \var{SbFPPR_PumpLmtRchd} indicating if upper or lower pump limit is reached.  For such a pump and spill valve configuration, the command pulse is just used to close the spill valve. This valve is naturally kept closed until the pump plunger reaches its top dead center.  The command pulse must be long enough to ensure the spill valve will get closed.  This duration is extracted from look up table \var{KtFPRC_t_SpillValvePlsLen} as a function of engine speed.  This duration is defined as a crankshaft angle.  If the lower pump limit is reached, no pulse ("0 ms pulse") is generated.\NL
     *  The fuel mass is first transformed into a volume \var{SfFPPR_V_FuelVolReqrd} using the calibrated fuel density \var{KfFPRC_rho_FuelDensity} in mm3 / g.  This volume is then corrected to the volumetric efficiency extracted from table \var{KtFPRC_PumpVolEfficiency} as a function of engine speed and it is used as input value in the look up table \var{KtFPRC_V_EffPumpVolume} giving finally the pumping angle. This angle is compared and possibly limited to the allowed pump angle range defined by calibration values \var{KfFPPR_phi_MnAnglFuelRailPmp} and \var{KfFPPR_phi_MxAnglFuelRailPmp}.  If required, the flag \var{SbFPPR_PumpLmtRchd} is raised indicating that the pump limit is reached.\NL
     *  The spill valve angle is the calibrated value \var{KfFPRC_phi_PumpTDC_Angle} which is the angle separation between spill event and pump TDC, from which we substract 3 angles:\NL
     *  - the pumping angle;\NL
     *  - the delay angle corresponding to the response time according to calibration table \var{KtFPRC_phi_SpillVlvRPMVoltCorr} which is function of engine speed and ignition voltage;\NL
     *  - the phaser position as the pump is driven by the camshaft which is possibly phased.\NL
     *
     * Block requirements for '<S16>/F02_AgBegPmpAct':
     *  1. SubSystem "F02_AgBegPmpAct" !Trace_To : VEMS_E_10_08013_004.01 ;
     */

    /* Outputs for atomic SubSystem: '<S18>/F01_agPmpCmdRaw' */

    /* Lookup: '<S35>/Look-Up Table'
     * About '<S35>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias 233.0
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_f), (&(PFuCtl_agWdPmpCmdReqOpl_T[0])),
                  HPPmpMdl_B.VEMS_vidGET6, (&(PFuCtl_tFuEstim_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate1'
     *
     * Regarding '<S35>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S36>/Look-Up Table'
     * About '<S36>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U32  2^-27  Bias -0.015625
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U32( &(localLookUpTable_a), (&(PFuCtl_agWdPmpCmdReq_T[0])),
                   PFuCtl_volFuReqEfc, (&(PFuCtl_volFuReqEfc_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate1'
     *
     * Regarding '<S36>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S37>/Look-Up Table'
     * About '<S37>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_i), (&(PFuCtl_tiPmpCmdReqRawBum_T[0])),
                   HPPmpMdl_B.VEMS_vidGET3, (&(PFuCtl_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate1'
     *
     * Regarding '<S37>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S38>/Look-Up Table (2-D)'
     * About '<S38>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U32  2^-27  Bias -0.015625
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U32_U16( &(localLookUpTable2D), (&(PFuCtl_tiOfsPmpCmdHyd_M[0])),
                       PFuCtl_volFuReqEfc, (&(PFuCtl_volFuReqEfc_A[0])), 15U,
                       HPPmpMdl_B.VEMS_vidGET3, (&(PFuCtl_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate2'
     *
     * Regarding '<S38>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S39>/Look-Up Table (2-D)'
     * About '<S39>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-6  FSlope 1.5104
     * Input1  Data Type:  Integer        U8
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U8( &(localLookUpTable2D_d), (&(PFuCtl_tiOfsPmpCmdN_M[0])),
                      HPPmpMdl_B.VEMS_vidGET5, (&(Ext_uBatt_A[0])), 8U,
                      HPPmpMdl_B.VEMS_vidGET8, (&(PFuCtl_NrProfCmd_A[0])), 24U);

    /* DataTypeDuplicate Block: '<S39>/Data Type Duplicate2'
     *
     * Regarding '<S39>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S40>/Look-Up Table (2-D)'
     * About '<S40>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-6  FSlope 1.5104
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_c), (&(PFuCtl_tiPmpCmdLo_M[0])),
                       HPPmpMdl_B.VEMS_vidGET5, (&(Ext_uBatt_A[0])), 8U,
                       HPPmpMdl_B.VEMS_vidGET3, (&(PFuCtl_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S40>/Data Type Duplicate2'
     *
     * Regarding '<S40>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S41>/Look-Up Table (2-D)'
     * About '<S41>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-6  FSlope 1.5104
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_a), (&(PFuCtl_tiPmpCmd_M[0])),
                       HPPmpMdl_B.VEMS_vidGET5, (&(Ext_uBatt_A[0])), 8U,
                       HPPmpMdl_B.VEMS_vidGET3, (&(PFuCtl_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S41>/Data Type Duplicate2'
     *
     * Regarding '<S41>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* RelationalOperator: '<S42>/Relational Operator' incorporates:
     *  Constant: '<S32>/PFuCtl_pHiThdPresTiPmpCmd_C'
     */
    localRelationalOperator_k = (HPPmpMdl_B.VEMS_vidGET4 >=
      PFuCtl_pHiThdPresTiPmpCmd_C);

    /* RelationalOperator: '<S42>/Relational Operator1' incorporates:
     *  Constant: '<S32>/PFuCtl_pLoThdPresTiPmpCmd_C'
     */
    localRelationalOperator1_k = (HPPmpMdl_B.VEMS_vidGET4 <=
      PFuCtl_pLoThdPresTiPmpCmd_C);

    /* UnitDelay: '<S45>/UnitDelay' */
    localUnitDelay1 = HPPmpMdl_DWork.UnitDelay_g;

    /* CombinatorialLogic: '<S45>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_k != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_k != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = HPPmpMdl_ConstP.pooled12[rowidx];
      localLogic[1] = HPPmpMdl_ConstP.pooled12[rowidx + 8];
    }

    /* UnitDelay: '<S45>/UnitDelay1' */
    localUnitDelay1 = HPPmpMdl_DWork.UnitDelay_dh;

    /* Switch: '<S45>/Switch2' incorporates:
     *  Constant: '<S45>/NotCLR3'
     */
    if (localUnitDelay1) {
      localSwitch2_i = localLogic[0];
    } else {
      localSwitch2_i = FALSE;
    }

    /* Switch: '<S32>/Switch1' incorporates:
     *  Lookup: '<S35>/Look-Up Table'
     *  Lookup: '<S36>/Look-Up Table'
     */
    if (HPPmpMdl_B.VEMS_vidGET10) {
      localSwitch2 = localLookUpTable_a;
    } else {
      localSwitch2 = localLookUpTable_f;
    }

    /* Switch: '<S32>/Switch3' */
    if (HPPmpMdl_B.VEMS_vidGET1_o) {
      localSwitch2 = HPPmpMdl_B.VEMS_vidGET_c;
    }

    /* Switch: '<S32>/Switch4' incorporates:
     *  Constant: '<S32>/PFuCtl_agWdPmpCmdReqRawBum_C'
     */
    if (HPPmpMdl_B.VEMS_vidGET13) {
      PFuCtl_agWdPmpCmdReqRaw = PFuCtl_agWdPmpCmdReqRawBum_C;
    } else {
      PFuCtl_agWdPmpCmdReqRaw = localSwitch2;
    }

    /* Sum: '<S32>/Sub1' incorporates:
     *  Constant: '<S32>/PFuCtl_agWdPmpCmdSpil_C'
     *  Sum: '<S32>/Sub3'
     */
    PFuCtl_agPmpCmdEfcReqRaw = ((((Float32)PFuCtl_agWdPmpCmdSpil_C) * 0.09375F)
      - (((Float32)PFuCtl_agWdPmpCmdReqRaw) * 0.09375F)) + (((Float32)
      HPPmpMdl_B.VEMS_vidGET2) * 0.09375F);

    /* Sum: '<S32>/Sub4' incorporates:
     *  Lookup2D: '<S38>/Look-Up Table (2-D)'
     */
    localtmp_0 = (UInt32)(localLookUpTable2D + localLookUpTable2D_d);
    if (localtmp_0 > 65535U) {
      PFuCtl_tiOfsPmpCmd = MAX_uint16_T;
    } else {
      PFuCtl_tiOfsPmpCmd = (UInt16)localtmp_0;
    }

    /* Product: '<S43>/Divide' incorporates:
     *  Constant: '<S32>/Constant7'
     *  Product: '<S44>/Divide'
     */
    PFuCtl_agOfsPmpCmdDly = (Float32)((((Float32d)PFuCtl_tiOfsPmpCmd) * 6.4E-006)
      * (((Float32d)HPPmpMdl_B.VEMS_vidGET3) * 6.0));

    /* Sum: '<S32>/Sub2' */
    PFuCtl_agPmpCmdReqRaw = PFuCtl_agPmpCmdEfcReqRaw - PFuCtl_agOfsPmpCmdDly;

    /* Switch: '<S32>/Switch2' incorporates:
     *  Lookup2D: '<S40>/Look-Up Table (2-D)'
     *  Lookup2D: '<S41>/Look-Up Table (2-D)'
     */
    if (localSwitch2_i) {
      localSwitch2 = localLookUpTable2D_a;
    } else {
      localSwitch2 = localLookUpTable2D_c;
    }

    /* Switch: '<S32>/Switch5' incorporates:
     *  Lookup: '<S37>/Look-Up Table'
     */
    if (HPPmpMdl_B.VEMS_vidGET13) {
      PFuCtl_tiPmpCmd = localLookUpTable_i;
    } else {
      PFuCtl_tiPmpCmd = localSwitch2;
    }

    /* Update for UnitDelay: '<S45>/UnitDelay' */
    HPPmpMdl_DWork.UnitDelay_g = localSwitch2_i;

    /* Update for UnitDelay: '<S45>/UnitDelay1' incorporates:
     *  Constant: '<S45>/NotCLR2'
     */
    HPPmpMdl_DWork.UnitDelay_dh = TRUE;

    /* end of Outputs for SubSystem: '<S18>/F01_agPmpCmdRaw' */

    /* Outputs for atomic SubSystem: '<S18>/F02_agWdPmpMinClcn' *
     * Block requirements for '<S18>/F02_agWdPmpMinClcn':
     *  1. SubSystem "F02_agWdPmpMinClcn" !Trace_To : VEMS_E_10_08013_005.02 ;
     *  2. SubSystem "F02_agWdPmpMinClcn" !Trace_To : VEMS_E_10_08013_006.01 ;
     */

    /* Switch: '<S33>/Switch5' incorporates:
     *  Constant: '<S33>/PFuCtl_bAcvPmpCmdEndTDC_C'
     *  Constant: '<S33>/PFuCtl_tiCmdEndTDCPmp_C'
     *  Constant: '<S33>/ZERO2'
     *  Constant: '<S33>/ZERO4'
     *  Product: '<S46>/Divide'
     *  Product: '<S47>/Divide'
     *  Sum: '<S33>/Sub3'
     *  Sum: '<S33>/Sub5'
     */
    if (PFuCtl_bAcvPmpCmdEndTDC_C) {
      localDataTypeConversion1 = (((((Float32)PFuCtl_tiPmpCmd) *
        6.400000075E-006F) + (((Float32)PFuCtl_tiCmdEndTDCPmp_C) *
        6.400000075E-006F)) * (((Float32)HPPmpMdl_B.VEMS_vidGET3) * 6.0F)) -
        PFuCtl_agOfsPmpCmdDly;
    } else {
      localDataTypeConversion1 = 0.0F;
    }

    /* MinMax: '<S33>/MinMax' incorporates:
     *  Constant: '<S33>/ZERO1'
     */
    PFuCtl_agWdPmpCmdMin = rt_MAXf(localDataTypeConversion1, 0.0F);

    /* RelationalOperator: '<S33>/Lower Or Equal6' incorporates:
     *  Constant: '<S33>/PFuCtl_agWdPmpCmdMin_C'
     */
    localSwitch2_i = (PFuCtl_agWdPmpCmdReqRaw <= PFuCtl_agWdPmpCmdMin_C);

    /* Logic: '<S33>/OR3' incorporates:
     *  Constant: '<S33>/PFuCtl_mFuPmpCtlMin_C'
     *  Logic: '<S33>/OR5'
     *  RelationalOperator: '<S33>/Lower Or Equal1'
     *  RelationalOperator: '<S33>/Lower Or Equal2'
     */
    localOR3 = (((((Float32)PFuCtl_agWdPmpCmdReqRaw) * 0.09375F) <=
                 PFuCtl_agWdPmpCmdMin) || (HPPmpMdl_B.VEMS_vidGET10 &&
      (HPPmpMdl_B.VEMS_vidGET12 <= ((UInt32)(((SInt32)((UInt32)
      (PFuCtl_mFuPmpCtlMin_C + 524288))) << 1)))));

    /* Logic: '<S33>/OR1' incorporates:
     *  Constant: '<S33>/PFuCtl_bAcvPmpMinFrzI_C'
     *  Logic: '<S33>/OR2'
     */
    PFuCtl_bDetAgWdPmpCmdMin = ((PFuCtl_bAcvPmpMinFrzI_C && (localOR3)) ||
      (localSwitch2_i));

    /* Logic: '<S33>/OR4' */
    PFuCtl_bInhPmpCmdMinDet = ((localOR3) || (localSwitch2_i));

    /* end of Outputs for SubSystem: '<S18>/F02_agWdPmpMinClcn' */

    /* Outputs for atomic SubSystem: '<S18>/F03_agPmpCmdCor' */

    /* DataTypeConversion: '<S53>/Conversion' incorporates:
     *  Constant: '<S34>/Cl7'
     */
    localDataTypeConversion1 = 720.0F;

    /* DataTypeConversion: '<S54>/Conversion' incorporates:
     *  Constant: '<S34>/Cl6'
     */
    localAdd2_hi = 0.0F;

    /* Switch: '<S55>/Switch' incorporates:
     *  RelationalOperator: '<S55>/UpperRelop'
     */
    if (!(PFuCtl_agPmpCmdReqRaw < 0.0F)) {
      localAdd2_hi = PFuCtl_agPmpCmdReqRaw;
    }

    /* Switch: '<S55>/Switch2' incorporates:
     *  RelationalOperator: '<S55>/LowerRelop1'
     */
    if (!(PFuCtl_agPmpCmdReqRaw > 720.0F)) {
      localDataTypeConversion1 = localAdd2_hi;
    }

    /* Sum: '<S34>/Sub4' incorporates:
     *  Constant: '<S34>/PFuCtl_agPmpCmdMin_C'
     *  DataTypeConversion: '<S34>/DTConv_Single_To_UFix_1'
     */
    localAdd2_hi = PFuCtl_agPmpCmdReqRaw - (((Float32)PFuCtl_agPmpCmdMin_C) *
      0.09375F);

    /* RelationalOperator: '<S34>/Lower Or Equal' incorporates:
     *  Constant: '<S34>/Cl3'
     */
    localSwitch2_i = (localAdd2_hi <= 0.0F);

    /* Logic: '<S34>/OR' incorporates:
     *  Constant: '<S34>/PFuCtl_agWdPmpCmdMax_C'
     *  RelationalOperator: '<S34>/Greater Or Equal'
     */
    PFuCtl_bDetAgWdPmpCmdMax = ((localSwitch2_i) || (PFuCtl_agWdPmpCmdReqRaw >=
      PFuCtl_agWdPmpCmdMax_C));

    /* Logic: '<S34>/OR1' */
    localOR3 = (HPPmpMdl_B.VEMS_vidGET11 || PFuCtl_bInhPmpCmdMinDet);

    /* Outputs for atomic SubSystem: '<S34>/TIMER2' */

    /* Sum: '<S52>/Sum1' incorporates:
     *  Constant: '<S34>/Cl8'
     *  Constant: '<S34>/PFuCtl_noSplInLrnCond_C'
     *  DataTypeConversion: '<S34>/DTConv_Single_To_UFix_2'
     */
    localSwitch4 = (SInt16)(PFuCtl_noSplInLrnCond_C + 1);

    /* Logic: '<S52>/Logical Operator2' incorporates:
     *  Logic: '<S52>/Logical Operator4'
     *  UnitDelay: '<S57>/Unit Delay'
     */
    localLogicalOperator2 = (HPPmpMdl_B.VEMS_vidGET9 &&
      (!HPPmpMdl_DWork.UnitDelay_DSTATE_i));

    /* Switch: '<S52>/Switch4' incorporates:
     *  UnitDelay: '<S56>/Unit Delay'
     */
    if (!localLogicalOperator2) {
      localSwitch4 = HPPmpMdl_DWork.UnitDelay_DSTATE_c;
    }

    /* Sum: '<S52>/Sum' incorporates:
     *  Constant: '<S34>/Cl8'
     */
    localAdd2_g = localSwitch4 - 1;
    if (localAdd2_g <= -32768) {
      localSwitch4 = MIN_int16_T;
    } else {
      localSwitch4 = (SInt16)localAdd2_g;
    }

    /* Switch: '<S52>/Switch1' incorporates:
     *  UnitDelay: '<S58>/Unit Delay'
     */
    if (!localLogicalOperator2) {
      localLogicalOperator2 = HPPmpMdl_DWork.UnitDelay_DSTATE_f;
    }

    /* Update for UnitDelay: '<S57>/Unit Delay' */
    HPPmpMdl_DWork.UnitDelay_DSTATE_i = HPPmpMdl_B.VEMS_vidGET9;

    /* Update for UnitDelay: '<S56>/Unit Delay' */
    HPPmpMdl_DWork.UnitDelay_DSTATE_c = localSwitch4;

    /* Update for UnitDelay: '<S58>/Unit Delay' */
    HPPmpMdl_DWork.UnitDelay_DSTATE_f = localLogicalOperator2;

    /* end of Outputs for SubSystem: '<S34>/TIMER2' */

    /* Logic: '<S34>/OR6' incorporates:
     *  Constant: '<S34>/PFuCtl_bAcvLrnCondPmpCmdLim_C'
     *  Constant: '<S52>/Constant4'
     *  DataTypeConversion: '<S52>/DTConv_Single_To_UFix_2'
     *  Logic: '<S52>/Logical Operator'
     *  RelationalOperator: '<S52>/Relational Operator3'
     */
    PFuCtl_bAcvLrnCondPmpCmdLim = ((HPPmpMdl_B.VEMS_vidGET9 &&
      PFuCtl_bAcvLrnCondPmpCmdLim_C) && ((localLogicalOperator2) &&
      (9.999999717E-010F >= ((Float32)localSwitch4))));

    /* Logic: '<S34>/OR3' incorporates:
     *  Logic: '<S34>/OR2'
     */
    HPPmpMdl_B.OR3 = ((PFuCtl_bDetAgWdPmpCmdMax || PFuCtl_bDetAgWdPmpCmdMin) ||
                      PFuCtl_bAcvLrnCondPmpCmdLim);

    /* Switch: '<S34>/Switch3' incorporates:
     *  Constant: '<S34>/Cl4'
     */
    if (localSwitch2_i) {
      PFuCtl_agPmpCmdOfs = localAdd2_hi;
    } else {
      PFuCtl_agPmpCmdOfs = 0.0F;
    }

    /* DataTypeConversion: '<S50>/OutDTConv' incorporates:
     *  Constant: '<S50>/offset'
     *  Constant: '<S50>/offset1'
     *  Constant: '<S50>/one_on_slope'
     *  Product: '<S50>/Product4'
     *  Sum: '<S34>/Sub3'
     *  Sum: '<S50>/Add1'
     *  Sum: '<S50>/Add2'
     */
    localtmp = ((PFuCtl_agPmpCmdEfcReqRaw - PFuCtl_agPmpCmdOfs) *
                1.066666698E+001F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        HPPmpMdl_B.OutDTConv_m = (UInt16)localtmp;
      } else {
        HPPmpMdl_B.OutDTConv_m = 0U;
      }
    } else {
      HPPmpMdl_B.OutDTConv_m = MAX_uint16_T;
    }

    /* Sum: '<S34>/Sub1' */
    localAdd2_hi = (((Float32)PFuCtl_agWdPmpCmdReqRaw) * 0.09375F) +
      PFuCtl_agPmpCmdOfs;

    /* Switch: '<S34>/Switch6' incorporates:
     *  Constant: '<S34>/Cl1'
     */
    if (localOR3) {
      localAdd2_hi = 0.0F;
    }

    /* DataTypeConversion: '<S51>/OutDTConv' incorporates:
     *  Constant: '<S51>/offset'
     *  Constant: '<S51>/offset1'
     *  Constant: '<S51>/one_on_slope'
     *  Product: '<S51>/Product4'
     *  Sum: '<S51>/Add1'
     *  Sum: '<S51>/Add2'
     */
    localtmp = (1.066666698E+001F * localAdd2_hi) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        HPPmpMdl_B.OutDTConv_b = (UInt16)localtmp;
      } else {
        HPPmpMdl_B.OutDTConv_b = 0U;
      }
    } else {
      HPPmpMdl_B.OutDTConv_b = MAX_uint16_T;
    }

    /* Switch: '<S34>/Switch2' incorporates:
     *  Constant: '<S34>/PFuCtl_agPmpCmdReqRawBum_C'
     *  Constant: '<S34>/PFuCtl_bChoCmdAg_C'
     *  Constant: '<S49>/offset'
     *  Constant: '<S49>/offset1'
     *  Constant: '<S49>/one_on_slope'
     *  DataTypeConversion: '<S49>/OutDTConv'
     *  Logic: '<S34>/OR5'
     *  Product: '<S49>/Product4'
     *  Sum: '<S49>/Add1'
     *  Sum: '<S49>/Add2'
     */
    if (HPPmpMdl_B.VEMS_vidGET13 && PFuCtl_bChoCmdAg_C) {
      HPPmpMdl_B.Switch2 = PFuCtl_agPmpCmdReqRawBum_C;
    } else {
      localtmp = (1.066666698E+001F * localDataTypeConversion1) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          HPPmpMdl_B.Switch2 = (UInt16)localtmp;
        } else {
          HPPmpMdl_B.Switch2 = 0U;
        }
      } else {
        HPPmpMdl_B.Switch2 = MAX_uint16_T;
      }
    }

    /* Switch: '<S34>/Switch4' incorporates:
     *  Constant: '<S34>/Cl2'
     *  Constant: '<S34>/Cl5'
     *  Logic: '<S34>/OR4'
     *  RelationalOperator: '<S34>/Relational Operator'
     */
    if ((PFuCtl_agWdPmpCmdReqRaw == 0) || (localOR3)) {
      PFuCtl_tiPmpCmdReqRaw = 0U;
    } else {
      PFuCtl_tiPmpCmdReqRaw = PFuCtl_tiPmpCmd;
    }

    /* end of Outputs for SubSystem: '<S18>/F03_agPmpCmdCor' */

    /* end of Outputs for SubSystem: '<S16>/F02_AgBegPmpAct' */
    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET14 */
    VEMS_vidGET(PFuCtl_tiPmpCmdReq, PFuCtl_tiPmpCmdReq_prev);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET7 */
    VEMS_vidGET(InjrSys_mFuInjEstim, HPPmpMdl_B.VEMS_vidGET7);

    /* Outputs for atomic SubSystem: '<S16>/F03_MFuPmpEstim' */

    /* Lookup: '<S59>/Look-Up Table'
     * About '<S59>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U32  2^-27  Bias -0.015625
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U32_U16( &(localLookUpTable), (&(PFuCtl_volFuReqEfc_T[0])),
                   HPPmpMdl_B.OutDTConv_b, (&(PFuCtl_agWdPmpCmdReq_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate1'
     *
     * Regarding '<S59>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S62>/Divide' incorporates:
     *  Lookup: '<S59>/Look-Up Table'
     *  Product: '<S63>/Divide'
     *  Sum: '<S19>/Add1'
     */
    localAdd2_hi = ((((((Float32)localLookUpTable) * 7.450580597E-009F) +
                      -0.015625F) - PFuCtl_OfsVolPmpCor) * PFuCtl_rVolEfcPmp) *
      PFuCtl_densEstim;

    /* Outputs for atomic SubSystem: '<S19>/F01_MFuPmpEstim' */

    /* Sum: '<S60>/Add2' incorporates:
     *  UnitDelay: '<S66>/Unit Delay'
     */
    localAdd2_g = HPPmpMdl_B.VEMS_vidGET4 - HPPmpMdl_DWork.UnitDelay_DSTATE_l;

    /* Abs: '<S60>/Abs1' */
    if (localAdd2_g < 0) {
      localAdd2_g = -localAdd2_g;
    }

    /* Sum: '<S60>/Add3' */
    PFuCtl_mFuPmpEstimErrRaw = (((Float32)HPPmpMdl_B.VEMS_vidGET7) *
      7.450580597E-009F) - localAdd2_hi;

    /* Outputs for atomic SubSystem: '<S60>/Mem' */

    /* Switch: '<S64>/Switch1' incorporates:
     *  Constant: '<S60>/PFuCtl_pPrailThdMFuPmpEstim_C'
     *  RelationalOperator: '<S60>/Relational Operator2'
     *  UnitDelay: '<S67>/Unit Delay'
     *  UnitDelay: '<S68>/Unit Delay'
     */
    if (((UInt32)localAdd2_g) >= ((UInt32)PFuCtl_pPrailThdMFuPmpEstim_C)) {
      localDataTypeConversion1 = HPPmpMdl_DWork.UnitDelay_DSTATE_d;
    } else {
      localDataTypeConversion1 = HPPmpMdl_DWork.UnitDelay_DSTATE;
    }

    /* Update for UnitDelay: '<S68>/Unit Delay' */
    HPPmpMdl_DWork.UnitDelay_DSTATE_d = localDataTypeConversion1;

    /* end of Outputs for SubSystem: '<S60>/Mem' */

    /* Switch: '<S60>/Switch1' incorporates:
     *  Constant: '<S60>/PFuCtl_bmFuPmpEstim_C'
     *  Sum: '<S60>/Add4'
     */
    if (PFuCtl_bmFuPmpEstim_C) {
      localDataTypeConversion1 = localAdd2_hi;
    } else {
      localDataTypeConversion1 += localAdd2_hi;
    }

    /* DataTypeConversion: '<S65>/OutDTConv' incorporates:
     *  Constant: '<S65>/offset'
     *  Constant: '<S65>/offset1'
     *  Constant: '<S65>/one_on_slope'
     *  Product: '<S65>/Product4'
     *  Sum: '<S65>/Add1'
     *  Sum: '<S65>/Add2'
     */
    localtmp = (1.34217728E+008F * localDataTypeConversion1) + 0.5F;
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        PFuCtl_mFuPmpEstimTmp = (UInt32)localtmp;
      } else {
        PFuCtl_mFuPmpEstimTmp = 0U;
      }
    } else {
      PFuCtl_mFuPmpEstimTmp = MAX_uint32_T;
    }

    /* Update for UnitDelay: '<S66>/Unit Delay' */
    HPPmpMdl_DWork.UnitDelay_DSTATE_l = HPPmpMdl_B.VEMS_vidGET4;

    /* Update for UnitDelay: '<S67>/Unit Delay' */
    HPPmpMdl_DWork.UnitDelay_DSTATE = PFuCtl_mFuPmpEstimErrRaw;

    /* end of Outputs for SubSystem: '<S19>/F01_MFuPmpEstim' */

    /* DataTypeConversion: '<S61>/OutDTConv' incorporates:
     *  Constant: '<S61>/offset'
     *  Constant: '<S61>/offset1'
     *  Constant: '<S61>/one_on_slope'
     *  Product: '<S61>/Product4'
     *  Sum: '<S61>/Add1'
     *  Sum: '<S61>/Add2'
     */
    localtmp = (1.34217728E+008F * localAdd2_hi) + 0.5F;
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        HPPmpMdl_B.OutDTConv = (UInt32)localtmp;
      } else {
        HPPmpMdl_B.OutDTConv = 0U;
      }
    } else {
      HPPmpMdl_B.OutDTConv = MAX_uint32_T;
    }

    /* Switch: '<S19>/Switch5' incorporates:
     *  Constant: '<S19>/ZERO1'
     *  Constant: '<S19>/ZERO2'
     *  Constant: '<S19>/ZERO3'
     *  Logic: '<S19>/OR1'
     *  RelationalOperator: '<S19>/Lower Or Equal1'
     *  RelationalOperator: '<S19>/Lower Or Equal2'
     */
    if ((PFuCtl_tiPmpCmdReq_prev == 0) || (HPPmpMdl_B.OutDTConv_b == 0)) {
      HPPmpMdl_B.Switch5 = 0U;
    } else {
      HPPmpMdl_B.Switch5 = PFuCtl_mFuPmpEstimTmp;
    }

    /* end of Outputs for SubSystem: '<S16>/F03_MFuPmpEstim' */

    /* SignalConversion: '<S16>/Signal Conversion1' */
    HPPmpMdl_B.SignalConversion1 = PFuCtl_tiPmpCmdReqRaw;

    /* S-Function "vems_vidSET" Block: <S16>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_agPmpCmdEfcReq, HPPmpMdl_B.OutDTConv_m);

    /* S-Function "vems_vidSET" Block: <S16>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_agPmpCmdReq, HPPmpMdl_B.Switch2);

    /* S-Function "vems_vidSET" Block: <S16>/VEMS_vidSET2 */
    VEMS_vidSET(PFuCtl_agWdPmpCmdReq, HPPmpMdl_B.OutDTConv_b);

    /* S-Function "vems_vidSET" Block: <S16>/VEMS_vidSET3 */
    VEMS_vidSET(PFuCtl_bDetAgWdPmpCmdLim, HPPmpMdl_B.OR3);

    /* S-Function "vems_vidSET" Block: <S16>/VEMS_vidSET4 */
    VEMS_vidSET(PFuCtl_mFuPmpEstim, HPPmpMdl_B.Switch5);

    /* S-Function "vems_vidSET" Block: <S16>/VEMS_vidSET5 */
    VEMS_vidSET(PFuCtl_mFuPmpEstimRaw, HPPmpMdl_B.OutDTConv);
  }

  /* end of Outputs for SubSystem: '<S9>/F03_HPPmpMdl' */
}

/* Output and update for function-call system: '<S1>/F04_HPPmpDecel' */
void HPPmpMdl_F04_HPPmpDecel(void)
{
  /* local block i/o variables */
  UInt16 localAdd1_m;
  UInt16 localLookUpTable_o;
  UInt16 localLookUpTable_af;
  Boolean localUnitDelay_a;
  Boolean localRelationalOperator1_if;
  Boolean localRelationalOperator_p;
  Boolean localLogic_o[2];
  Boolean localSwitch2_h;
  Boolean localSwitch2_g;
  Boolean localSwitch2_d;
  Boolean localSwitch2_c;
  UInt32 localDivide_m;
  Float32 localAdd2_e;
  SInt32 localAdd;
  SInt32 localtmp;
  SInt32 localtmp_0;
  UInt16 localtmp_1;

  /* Outputs for enable SubSystem: '<S10>/F04_HPPmpDecel' incorporates:
   *  Constant: '<S10>/ConstVal'
   *  Constant: '<S10>/VLVINSPMGT_u8Inhib'
   *  EnablePort: '<S69>/Enable'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  if (HPPMPMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_pDsThrMesSI, HPPmpMdl_B.VEMS_vidGET2_j);

    /* RelationalOperator: '<S73>/Relational Operator' incorporates:
     *  Constant: '<S70>/PFuCtl_pDsThrMesLoDecelThdHi_C'
     */
    localUnitDelay_a = (PFuCtl_pDsThrMesLoDecelThdHi_C >=
                        HPPmpMdl_B.VEMS_vidGET2_j);

    /* RelationalOperator: '<S73>/Relational Operator1' incorporates:
     *  Constant: '<S70>/PFuCtl_pDsThrMesHiDecelThdHi_C'
     */
    localRelationalOperator1_if = (HPPmpMdl_B.VEMS_vidGET2_j >=
      PFuCtl_pDsThrMesHiDecelThdHi_C);

    /* UnitDelay: '<S77>/UnitDelay' */
    localRelationalOperator_p = HPPmpMdl_DWork.UnitDelay;

    /* CombinatorialLogic: '<S77>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_a != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_if != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_p != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_o[0] = HPPmpMdl_ConstP.pooled12[rowidx];
      localLogic_o[1] = HPPmpMdl_ConstP.pooled12[rowidx + 8];
    }

    /* Switch: '<S77>/Switch2' incorporates:
     *  Constant: '<S77>/NotCLR3'
     *  UnitDelay: '<S77>/UnitDelay1'
     */
    if (HPPmpMdl_DWork.UnitDelay_p) {
      localSwitch2_h = localLogic_o[0];
    } else {
      localSwitch2_h = FALSE;
    }

    /* RelationalOperator: '<S76>/Relational Operator' incorporates:
     *  Constant: '<S70>/PFuCtl_pDsThrMesHiDecelThdLo_C'
     */
    localRelationalOperator_p = (HPPmpMdl_B.VEMS_vidGET2_j >=
      PFuCtl_pDsThrMesHiDecelThdLo_C);

    /* RelationalOperator: '<S76>/Relational Operator1' incorporates:
     *  Constant: '<S70>/PFuCtl_pDsThrMesLoDecelThdLo_C'
     */
    localRelationalOperator1_if = (HPPmpMdl_B.VEMS_vidGET2_j <=
      PFuCtl_pDsThrMesLoDecelThdLo_C);

    /* UnitDelay: '<S80>/UnitDelay' */
    localUnitDelay_a = HPPmpMdl_DWork.UnitDelay_e;

    /* CombinatorialLogic: '<S80>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_p != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_if != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_a != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_o[0] = HPPmpMdl_ConstP.pooled12[rowidx];
      localLogic_o[1] = HPPmpMdl_ConstP.pooled12[rowidx + 8];
    }

    /* Switch: '<S80>/Switch2' incorporates:
     *  Constant: '<S80>/NotCLR3'
     *  UnitDelay: '<S80>/UnitDelay1'
     */
    if (HPPmpMdl_DWork.UnitDelay_n) {
      localSwitch2_g = localLogic_o[0];
    } else {
      localSwitch2_g = FALSE;
    }

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_nEng, HPPmpMdl_B.VEMS_vidGET1);

    /* DataTypeConversion Block: '<S81>/Data Type Conversion'
     *
     * Regarding '<S81>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S82>/Data Type Conversion'
     *
     * Regarding '<S82>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S90>/Data Type Conversion'
     *
     * Regarding '<S90>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* RelationalOperator: '<S74>/Relational Operator' incorporates:
     *  Constant: '<S70>/PFuCtl_nEngLoDecelThdHi_C'
     */
    localRelationalOperator_p = (PFuCtl_nEngLoDecelThdHi_C >=
      HPPmpMdl_B.VEMS_vidGET1);

    /* RelationalOperator: '<S74>/Relational Operator1' incorporates:
     *  Constant: '<S70>/PFuCtl_nEngHiDecelThdHi_C'
     */
    localRelationalOperator1_if = (HPPmpMdl_B.VEMS_vidGET1 >=
      PFuCtl_nEngHiDecelThdHi_C);

    /* UnitDelay: '<S78>/UnitDelay' */
    localUnitDelay_a = HPPmpMdl_DWork.UnitDelay_et;

    /* CombinatorialLogic: '<S78>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_p != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_if != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_a != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_o[0] = HPPmpMdl_ConstP.pooled12[rowidx];
      localLogic_o[1] = HPPmpMdl_ConstP.pooled12[rowidx + 8];
    }

    /* Switch: '<S78>/Switch2' incorporates:
     *  Constant: '<S78>/NotCLR3'
     *  UnitDelay: '<S78>/UnitDelay1'
     */
    if (HPPmpMdl_DWork.UnitDelay_d) {
      localSwitch2_d = localLogic_o[0];
    } else {
      localSwitch2_d = FALSE;
    }

    /* RelationalOperator: '<S75>/Relational Operator' incorporates:
     *  Constant: '<S70>/PFuCtl_nEngHiDecelThdLo_C'
     */
    localRelationalOperator_p = (HPPmpMdl_B.VEMS_vidGET1 >=
      PFuCtl_nEngHiDecelThdLo_C);

    /* RelationalOperator: '<S75>/Relational Operator1' incorporates:
     *  Constant: '<S70>/PFuCtl_nEngLoDecelThdLo_C'
     */
    localRelationalOperator1_if = (HPPmpMdl_B.VEMS_vidGET1 <=
      PFuCtl_nEngLoDecelThdLo_C);

    /* UnitDelay: '<S79>/UnitDelay' */
    localUnitDelay_a = HPPmpMdl_DWork.UnitDelay_a;

    /* CombinatorialLogic: '<S79>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_p != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_if != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_a != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_o[0] = HPPmpMdl_ConstP.pooled12[rowidx];
      localLogic_o[1] = HPPmpMdl_ConstP.pooled12[rowidx + 8];
    }

    /* Switch: '<S79>/Switch2' incorporates:
     *  Constant: '<S79>/NotCLR3'
     *  UnitDelay: '<S79>/UnitDelay1'
     */
    if (HPPmpMdl_DWork.UnitDelay_f) {
      localSwitch2_c = localLogic_o[0];
    } else {
      localSwitch2_c = FALSE;
    }

    /* Logic: '<S70>/Logical Operator4' incorporates:
     *  Constant: '<S70>/PFuCtl_pDsThrMesHiDecelThdHi_C1'
     *  Logic: '<S70>/Logical Operator1'
     *  Logic: '<S70>/Logical Operator2'
     *  Logic: '<S70>/Logical Operator3'
     */
    PFuCtl_bPmpCmdDecelZone = ((((localSwitch2_d) && (localSwitch2_c)) &&
      ((localSwitch2_h) && (localSwitch2_g))) || PFuCtl_bForcAcvDecelZone_C);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET */
    VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, HPPmpMdl_B.VEMS_vidGET);

    /* Sum: '<S71>/Add' incorporates:
     *  Constant: '<S71>/PFuCtl_agWdPmpCmdSpil_C'
     */
    localAdd = PFuCtl_agWdPmpCmdSpil_C + HPPmpMdl_B.VEMS_vidGET;

    /* Lookup: '<S81>/Look-Up Table'
     * About '<S81>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localAdd1_m), (&(PFuCtl_agPmpCmdDecelReq_T[0])),
                   HPPmpMdl_B.VEMS_vidGET1, (&(PFuCtl_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S81>/Data Type Duplicate1'
     *
     * Regarding '<S81>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET5 */
    VEMS_vidGET(PFuCtl_agPmpCmdReq, HPPmpMdl_B.VEMS_vidGET5_l);

    /* Sum: '<S71>/Add2' */
    localtmp = localAdd1_m;
    localtmp_0 = localAdd + localtmp;
    if (((localAdd > 0) && (localtmp > 0)) && (localtmp_0 <= 0)) {
      localtmp_0 = MAX_int32_T;
    }

    localAdd = localtmp_0 - HPPmpMdl_B.VEMS_vidGET5_l;
    if ((localtmp_0 < 0) && (localAdd >= 0)) {
      localAdd = MIN_int32_T;
    }

    if (localAdd > 32767) {
      PFuCtl_agBeg2PulseDif = MAX_int16_T;
    } else if (localAdd <= -32768) {
      PFuCtl_agBeg2PulseDif = MIN_int16_T;
    } else {
      PFuCtl_agBeg2PulseDif = (SInt16)localAdd;
    }

    /* Lookup: '<S82>/Look-Up Table'
     * About '<S82>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_o), (&(PFuCtl_tiPmpCmdDecel_T[0])),
                   HPPmpMdl_B.VEMS_vidGET1, (&(PFuCtl_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S82>/Data Type Duplicate1'
     *
     * Regarding '<S82>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S84>/Divide' incorporates:
     *  Constant: '<S71>/Constant2'
     */
    localDivide_m = (UInt32)(HPPmpMdl_B.VEMS_vidGET1 * 6);

    /* If: '<S83>/If2' incorporates:
     *  ActionPort: '<S87>/Action Port'
     *  ActionPort: '<S88>/Action Port'
     *  Constant: '<S83>/Constant7'
     *  RelationalOperator: '<S83>/Relational Operator'
     *  SubSystem: '<S83>/If Action Subsystem2'
     *  SubSystem: '<S83>/If Action Subsystem3'
     */
    if (localDivide_m == 0U) {
      /* Constant: '<S87>/Byp_Fonction_SC' */
      HPPmpMdl_B.Merge = 0U;
    } else {
      /* Product: '<S88>/Divide1' */
      localAdd = div_ssu32(PFuCtl_agBeg2PulseDif << 13, localDivide_m);
      if (localAdd <= 0) {
        localtmp_1 = 0U;
      } else if (localAdd > 65535) {
        localtmp_1 = MAX_uint16_T;
      } else {
        localtmp_1 = (UInt16)localAdd;
      }

      localDivide_m = (UInt32)((SInt32)(((UInt32)(localtmp_1 * 29297)) >>
        14));
      if (localDivide_m > 65535U) {
        HPPmpMdl_B.Merge = MAX_uint16_T;
      } else {
        HPPmpMdl_B.Merge = (UInt16)localDivide_m;
      }
    }

    /* Switch: '<S71>/Switch2' incorporates:
     *  Constant: '<S71>/Constant1'
     *  Constant: '<S71>/Constant8'
     *  Logic: '<S71>/Logical Operator'
     *  Lookup: '<S82>/Look-Up Table'
     *  RelationalOperator: '<S71>/Relational Operator2'
     */
    if ((HPPmpMdl_B.SignalConversion1 != 0) && PFuCtl_bPmpCmdDecelZone) {
      HPPmpMdl_B.Switch2_k = localLookUpTable_o;
    } else {
      HPPmpMdl_B.Switch2_k = 0U;
    }

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET4 */
    VEMS_vidGET(PFuCtl_NrProfCmd, HPPmpMdl_B.VEMS_vidGET4_g);

    /* DataTypeConversion Block: '<S89>/Data Type Conversion'
     *
     * Regarding '<S89>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Lookup: '<S89>/Look-Up Table'
     * About '<S89>/Look-Up Table':
     * Input0  Data Type:  Integer        U8
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_af), (&(PFuCtl_tiPeakDurnCmd_T[0])),
                  HPPmpMdl_B.VEMS_vidGET4_g, (&(PFuCtl_NumProfilCmd_A[0])), 24U);

    /* DataTypeDuplicate Block: '<S89>/Data Type Duplicate1'
     *
     * Regarding '<S89>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S72>/Add1' incorporates:
     *  Constant: '<S72>/PFuCtl_tiPeakDurnOfs_C'
     *  Lookup: '<S89>/Look-Up Table'
     */
    localDivide_m = (UInt32)(localLookUpTable_af + PFuCtl_tiPeakDurnOfs_C);
    if (localDivide_m > 65535U) {
      localAdd1_m = MAX_uint16_T;
    } else {
      localAdd1_m = (UInt16)localDivide_m;
    }

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET3 */
    VEMS_vidGET(FuSysM_tFuUsPmp, HPPmpMdl_B.VEMS_vidGET3_b);

    /* DataTypeConversion Block: '<S90>/Data Type Conversion1'
     *
     * Regarding '<S90>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S90>/Data Type Duplicate1'
     *
     * Regarding '<S90>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S90>/Look-Up Table (2-D)'
     * About '<S90>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U8  Bias 233.0
     * Output0 Data Type:  Fixed Point    U16  2^-18  FSlope 1.6777216
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U8( &(HPPmpMdl_B.LookUpTable2D),
                      (&(PFuCtl_tiPmpCmdDecelGap_M[0])), HPPmpMdl_B.VEMS_vidGET1,
                      (&(PFuCtl_nEng_A[0])), 15U, HPPmpMdl_B.VEMS_vidGET3_b,
                      (&(PFuCtl_tFuUsPmp_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S90>/Data Type Duplicate2'
     *
     * Regarding '<S90>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Sum: '<S72>/Add3' */
    localAdd2_e = (((Float32)HPPmpMdl_B.Merge) * 6.400000075E-006F) -
      (((Float32)HPPmpMdl_B.LookUpTable2D) * 6.400000075E-006F);

    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S72>/Constant1'
     *  RelationalOperator: '<S72>/Relational Operator'
     */
    if (HPPmpMdl_B.Switch2_k == 0) {
      localAdd2_e = ((Float32)HPPmpMdl_B.SignalConversion1) * 6.400000075E-006F;
    }

    /* DataTypeConversion: '<S91>/OutDTConv' incorporates:
     *  Constant: '<S91>/offset'
     *  Constant: '<S91>/offset1'
     *  Constant: '<S91>/one_on_slope'
     *  Product: '<S91>/Product4'
     *  Sum: '<S91>/Add1'
     *  Sum: '<S91>/Add2'
     */
    localAdd2_e = (156250.0F * localAdd2_e) + 0.5F;
    if (localAdd2_e >= 0.0F) {
      HPPmpMdl_B.OutDTConv_c = (UInt16)localAdd2_e;
    } else {
      HPPmpMdl_B.OutDTConv_c = 0U;
    }

    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S72>/Constant4'
     *  Constant: '<S72>/Constant5'
     *  RelationalOperator: '<S72>/Relational Operator1'
     */
    if (0 != HPPmpMdl_B.OutDTConv_c) {
      HPPmpMdl_B.Switch1 = localAdd1_m;
    } else {
      HPPmpMdl_B.Switch1 = 0U;
    }

    /* S-Function "vems_vidSET" Block: <S69>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_tiBeg2PulseDif, HPPmpMdl_B.Merge);

    /* S-Function "vems_vidSET" Block: <S69>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_tiPeakDurnCmd, HPPmpMdl_B.Switch1);

    /* S-Function "vems_vidSET" Block: <S69>/VEMS_vidSET2 */
    VEMS_vidSET(PFuCtl_tiPmpCmdDecelGap, HPPmpMdl_B.LookUpTable2D);

    /* S-Function "vems_vidSET" Block: <S69>/VEMS_vidSET3 */
    VEMS_vidSET(PFuCtl_tiPmpCmdDecelReq, HPPmpMdl_B.Switch2_k);

    /* S-Function "vems_vidSET" Block: <S69>/VEMS_vidSET4 */
    VEMS_vidSET(PFuCtl_tiPmpCmdReq, HPPmpMdl_B.OutDTConv_c);

    /* Update for UnitDelay: '<S77>/UnitDelay' */
    HPPmpMdl_DWork.UnitDelay = localSwitch2_h;

    /* Update for UnitDelay: '<S77>/UnitDelay1' incorporates:
     *  Constant: '<S77>/NotCLR2'
     */
    HPPmpMdl_DWork.UnitDelay_p = TRUE;

    /* Update for UnitDelay: '<S80>/UnitDelay' */
    HPPmpMdl_DWork.UnitDelay_e = localSwitch2_g;

    /* Update for UnitDelay: '<S80>/UnitDelay1' incorporates:
     *  Constant: '<S80>/NotCLR2'
     */
    HPPmpMdl_DWork.UnitDelay_n = TRUE;

    /* Update for UnitDelay: '<S78>/UnitDelay' */
    HPPmpMdl_DWork.UnitDelay_et = localSwitch2_d;

    /* Update for UnitDelay: '<S78>/UnitDelay1' incorporates:
     *  Constant: '<S78>/NotCLR2'
     */
    HPPmpMdl_DWork.UnitDelay_d = TRUE;

    /* Update for UnitDelay: '<S79>/UnitDelay' */
    HPPmpMdl_DWork.UnitDelay_a = localSwitch2_c;

    /* Update for UnitDelay: '<S79>/UnitDelay1' incorporates:
     *  Constant: '<S79>/NotCLR2'
     */
    HPPmpMdl_DWork.UnitDelay_f = TRUE;
  }

  /* end of Outputs for SubSystem: '<S10>/F04_HPPmpDecel' */
}

/* Start for exported function: PFuCtl_EveSpl_HPPmpMdl */
void PFuCtl_EveSpl_HPPmpMdl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc'
   */

  /* Start for S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F03_HPPmpMdl'
   *  Start for SubSystem: '<S1>/F04_HPPmpDecel'
   *
   * Block requirements for '<S1>/F03_HPPmpMdl':
   *  1. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_002.01 ;
   *  2. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_011.01 ;
   *  3. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_010.01 ;
   *  4. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_009.01 ;
   *  5. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_001.02 ;
   *
   * Block requirements for '<S1>/F04_HPPmpDecel':
   *  1. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_008.01 ;
   *  2. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_002.01 ;
   *  3. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_011.01 ;
   *  4. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_010.01 ;
   *  5. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_009.01 ;
   *  6. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_001.02 ;
   */
}

/* Output and update for exported function: PFuCtl_EveSpl_HPPmpMdl */
void PFuCtl_EveSpl_HPPmpMdl(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc'
   */

  /* S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  SubSystem: '<S1>/F03_HPPmpMdl'
   *  SubSystem: '<S1>/F04_HPPmpDecel'
   *
   * Block requirements for '<S1>/F03_HPPmpMdl':
   *  1. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_002.01 ;
   *  2. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_011.01 ;
   *  3. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_010.01 ;
   *  4. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_009.01 ;
   *  5. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_001.02 ;
   *
   * Block requirements for '<S1>/F04_HPPmpDecel':
   *  1. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_008.01 ;
   *  2. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_002.01 ;
   *  3. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_011.01 ;
   *  4. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_010.01 ;
   *  5. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_009.01 ;
   *  6. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_001.02 ;
   */
  HPPmpMdl_F03_HPPmpMdl();
  HPPmpMdl_F04_HPPmpDecel();
}

/* Model initialize function */
void HPPmpMdl_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    HPPmpMdl_B.VEMS_vidGET12 = 1048576U;
  }

  /* custom signals */
  PFuCtl_volFuReqEfc = 2097152U;

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  PFuCtl_EveSpl_HPPmpMdl_Start();
}

#define HPPMPMDL_STOP_SEC_CODE
#include "HPPmpMdl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
