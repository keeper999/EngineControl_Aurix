/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSpCrk                                                */
/* !Description     : INJECTED FUEL MASS SET POINT DURING CRANKING            */
/*                                                                            */
/* !Module          : mFuSpCrk                                                */
/*                                                                            */
/* !File            : mFuSpCrk.c                                              */
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
/* !Reference       : V02NT1101977 / 03                                       */
/* !OtherRefs       : VEMS V02 ECU#059784                                     */
/* !OtherRefs       : VEMS V02 ECU#065158                                     */
/* !OtherRefs       : VEMS V02 ECU#065981                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Sun Jun 02 16:30:57 2013                              */
/*   Model name       : mFuSpCrk_AUTOCODE.mdl                                 */
/*   Model version    : 1.387                                                 */
/*   Root subsystem   : /mFuSpCrk                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSPCRK/mFuSpCrk.c_v     $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "mFuSpCrk.h"
#include "mFuSpCrk_private.h"

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
#define MFUSPCRK_START_SEC_VAR_UNSPECIFIED
#include "mFuSpCrk_MemMap.h"

/* Block signals (auto storage) */
BlockIO_mFuSpCrk mFuSpCrk_B;

/* Block states (auto storage) */
D_Work_mFuSpCrk mFuSpCrk_DWork;

#define MFUSPCRK_STOP_SEC_VAR_UNSPECIFIED
#include "mFuSpCrk_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define MFUSPCRK_START_SEC_CODE
#include "mFuSpCrk_MemMap.h"

void mFuSpCrk_ASYNC1(int controlPortIdx)
{
}

void mFuSpCrk_ASYNC2(int controlPortIdx)
{
}

void mFuSpCrk_ASYNC3(int controlPortIdx)
{
}

void mFuSpCrk_ASYNC4(int controlPortIdx)
{
  mFuSpCrk_F01_mFuFacCorRstrtSTT(controlPortIdx);
}

void mFuSpCrk_ASYNC7(int controlPortIdx)
{
  mFuSpCrk_F02_IniCrkMass(controlPortIdx);
}

void mFuSpCrk_ASYNC9(int controlPortIdx)
{
  mFuSpCrk_F01_IniCrkfacCor(controlPortIdx);
}

/*
 * Output and update for atomic system:
 *    '<S9>/F01_mFuFacCorRstrtSTT_Reusable'
 *    '<S16>/F01_mFuFacCorRstrtSTT_Reusable'
 */
void F01_mFuFacCorRstrtSTT_Reusable(UInt16 rtu_Eng_mO2Cat, SInt16
  rtu_Ext_tCoMes, UInt16 rtu_Ext_nEng, UInt8 rtu_Eng_ctTDCStrt, Boolean
  rtu_CoPTSt_bRStrtSTT, UInt16 rtu_UsThrM_pAirExt,
  rtB_F01_mFuFacCorRstrtSTT_Reusa *localB)
{
  UInt32 localbpIdx;
  Float32 localSwitch2_n;
  Float32 localSwitch1_m;
  Float32 localDivide_bi;
  SInt32 localtmp;
  UInt8 locallocalDataTypeConversion1_n;

  /* DataTypeConversion: '<S36>/Conversion' incorporates:
   *  Constant: '<S28>/InjSys_FacMaxCorRstrtSTT_C'
   */
  localSwitch2_n = (((Float32)InjSys_FacMaxCorRstrtSTT_C) * 0.0078125F) +
    0.0078125F;

  /* DataTypeConversion: '<S28>/Data Type Conversion1' */
  localtmp = rtu_Ext_tCoMes + 40;
  if (localtmp <= 0) {
    locallocalDataTypeConversion1_n = 0U;
  } else if (localtmp > 255) {
    locallocalDataTypeConversion1_n = MAX_uint8_T;
  } else {
    locallocalDataTypeConversion1_n = (UInt8)localtmp;
  }

  /* Product: '<S34>/Divide' incorporates:
   *  Lookup_n-D: '<S30>/Lookup Table (n-D)'
   *  Lookup_n-D: '<S33>/Lookup Table (n-D)'
   */
  localDivide_bi = look1_iu16lftu8n7If_binlcns__1(rtu_Eng_mO2Cat,
    (&(InjSys_mO2Cat_A[0])), (&(InjSys_FacCorRstrtSTT_mO2Cat_T[0])), 15U) *
    look2_iu16u8lftu8n7If_binlcns(rtu_Ext_nEng, locallocalDataTypeConversion1_n,
                                  (&(Ext_nEng_A[0])), (&(Ext_tCoMes_A[0])),
    (&(InjSys_FacCorRstrtSTT_nEng_tCo_M[0])), &mFuSpCrk_ConstP.pooled5[0], 16U);

  /* Lookup_n-D: '<S31>/Lookup Table (n-D)' */
  localSwitch1_m = look1_iu8lftu8n7If_binlcns(rtu_Eng_ctTDCStrt,
    (&(InjSys_ctTDCStrt_A[0])), (&(InjSys_FacCorRstrtSTT_cntTDC_T[0])), 15U);

  /* Outputs for atomic SubSystem: '<S28>/LookUp_1D2_Index'
   * Block description for '<S28>/LookUp_1D2_Index':
   *  The carto InjSys_bCorRstrtSTT_pAirExt_T is not linked to the library,
   *  because the Interpolation method is changed : here we must have an indexation
   *  and not an Interpolation
   */

  /* Lookup_n-D: '<S32>/Lookup Table (n-D)' */
  localbpIdx = plook_u32u16_bincka(rtu_UsThrM_pAirExt, (&(InjSys_pAirExt_A[0])),
    8U);

  /* end of Outputs for SubSystem: '<S28>/LookUp_1D2_Index' */

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/ConstVal'
   *  DataTypeConversion: '<S28>/Data Type Conversion'
   *  Product: '<S35>/Divide'
   */
  if (InjSys_bCorRstrtSTT_pAirExt_T[(localbpIdx)] != 0) {
    localSwitch1_m *= localDivide_bi;
  } else {
    localSwitch1_m = 1.0F;
  }

  /* DataTypeConversion: '<S37>/Conversion' incorporates:
   *  Constant: '<S28>/InjSys_FacMinCorRstrtSTT_C'
   */
  localDivide_bi = (((Float32)InjSys_FacMinCorRstrtSTT_C) * 0.0078125F) +
    0.0078125F;

  /* Switch: '<S38>/Switch' incorporates:
   *  RelationalOperator: '<S38>/UpperRelop'
   */
  if (!(localSwitch1_m < localDivide_bi)) {
    localDivide_bi = localSwitch1_m;
  }

  /* Switch: '<S38>/Switch2' incorporates:
   *  RelationalOperator: '<S38>/LowerRelop1'
   */
  if (!(localSwitch1_m > localSwitch2_n)) {
    localSwitch2_n = localDivide_bi;
  }

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/ConstVal_1'
   */
  if (rtu_CoPTSt_bRStrtSTT) {
    localB->Switch = localSwitch2_n;
  } else {
    localB->Switch = 1.0F;
  }

  /* DataStoreWrite: '<S28>/Data Store Write' */
  InjSys_mFuFacCorRstrtSTT = localB->Switch;
}

/* Start for exported function: InjSys_EveRst_mFuSpCrk */
void InjSys_EveRst_mFuSpCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S7>/F01_mFuFacCorRstrtSTT_Rst'
   *
   * Block requirements for '<S7>/F01_mFuFacCorRstrtSTT_Rst':
   *  1. SubSystem "F01_mFuFacCorRstrtSTT" !Trace_To : VEMS_E_11_01977_001.01 ;
   */
}

/* Output and update for exported function: InjSys_EveRst_mFuSpCrk */
void InjSys_EveRst_mFuSpCrk(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S7>/F01_mFuFacCorRstrtSTT_Rst'
   *
   * Block requirements for '<S7>/F01_mFuFacCorRstrtSTT_Rst':
   *  1. SubSystem "F01_mFuFacCorRstrtSTT" !Trace_To : VEMS_E_11_01977_001.01 ;
   */
  /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET4 */
  VEMS_vidGET(Ext_tCoMes, mFuSpCrk_B.VEMS_vidGET4_b);

  /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET */
  VEMS_vidGET(CoPTSt_bRStrtSTT, mFuSpCrk_B.VEMS_vidGET_h);

  /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET5 */
  VEMS_vidGET(UsThrM_pAirExt, mFuSpCrk_B.VEMS_vidGET5_i);

  /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET2 */
  VEMS_vidGET(Eng_mO2Cat, mFuSpCrk_B.VEMS_vidGET2_o);

  /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET3 */
  VEMS_vidGET(Ext_nEng, mFuSpCrk_B.VEMS_vidGET3_f);

  /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET1 */
  VEMS_vidGET(Eng_ctTDCStrt, mFuSpCrk_B.VEMS_vidGET1_p);

  /* Outputs for atomic SubSystem: '<S9>/F01_mFuFacCorRstrtSTT_Reusable' */
  F01_mFuFacCorRstrtSTT_Reusable(mFuSpCrk_B.VEMS_vidGET2_o,
    mFuSpCrk_B.VEMS_vidGET4_b, mFuSpCrk_B.VEMS_vidGET3_f,
    mFuSpCrk_B.VEMS_vidGET1_p, mFuSpCrk_B.VEMS_vidGET_h,
    mFuSpCrk_B.VEMS_vidGET5_i, &mFuSpCrk_B.F01_mFuFacCorRstrtSTT_Reusabl_d);

  /* end of Outputs for SubSystem: '<S9>/F01_mFuFacCorRstrtSTT_Reusable' */

  /* SignalConversion: '<S9>/Signal Conversion2' */
  mFuSpCrk_B.Merge3 = mFuSpCrk_B.F01_mFuFacCorRstrtSTT_Reusabl_d.Switch;
}

/* Output and update for function-call system: '<S10>/F01_IniCrkfacCor' */
void mFuSpCrk_F01_IniCrkfacCor(SInt32 controlPortIdx)
{
  /* local block i/o variables */
  UInt8 localDataTypeConversion;
  UInt8 localLookUpTable2D;
  UInt8 localLookUpTable2D_l;
  UInt8 localSwitch1;
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S39>/F01_IniCrkfacCor' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Constant: '<S39>/OFSVLV_u8Inhib'
   *  EnablePort: '<S43>/Enable'
   *  RelationalOperator: '<S39>/Relational Operator'
   */
  if (MFUSPCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S43>/VEMS_vidGET2 */
    VEMS_vidGET(EOM_tiEngStopRst, mFuSpCrk_B.VEMS_vidGET2);

    /* DataTypeConversion Block: '<S44>/Data Type Conversion'
     *
     * Regarding '<S44>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S43>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tCoMes, mFuSpCrk_B.VEMS_vidGET4_h);

    /* DataTypeConversion: '<S43>/Data Type Conversion' */
    localtmp = mFuSpCrk_B.VEMS_vidGET4_h + 40;
    if (localtmp <= 0) {
      localDataTypeConversion = 0U;
    } else if (localtmp > 255) {
      localDataTypeConversion = MAX_uint8_T;
    } else {
      localDataTypeConversion = (UInt8)localtmp;
    }

    /* Lookup2D: '<S44>/Look-Up Table (2-D)'
     * About '<S44>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U32
     * Input1  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U8  2^-8  Bias 0.00390625
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U32_U8( &(localLookUpTable2D), (&(InjSys_facCorMassFuRstrtSTT_M[0])),
                     mFuSpCrk_B.VEMS_vidGET2, (&(EOM_tiEngStopRst_A[0])), 8U,
                     localDataTypeConversion, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S44>/Data Type Duplicate2'
     *
     * Regarding '<S44>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S43>/VEMS_vidGET1 */
    VEMS_vidGET(EOM_tiEngStop, mFuSpCrk_B.VEMS_vidGET1);

    /* DataTypeConversion Block: '<S45>/Data Type Conversion'
     *
     * Regarding '<S45>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Lookup2D: '<S45>/Look-Up Table (2-D)'
     * About '<S45>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U32
     * Input1  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U8  2^-8  Bias 0.00390625
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U32_U8( &(localLookUpTable2D_l), (&(InjSys_facCorMassFuRstrt_M[0])),
                     mFuSpCrk_B.VEMS_vidGET1, (&(InjSys_tiEngStop_A[0])), 8U,
                     localDataTypeConversion, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S45>/Data Type Duplicate2'
     *
     * Regarding '<S45>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S43>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, mFuSpCrk_B.VEMS_vidGET_l);

    /* Switch: '<S43>/Switch1' incorporates:
     *  Logic: '<S43>/Logical Operator'
     *  Lookup2D: '<S44>/Look-Up Table (2-D)'
     *  Lookup2D: '<S45>/Look-Up Table (2-D)'
     */
    if (!mFuSpCrk_B.VEMS_vidGET_l) {
      localSwitch1 = localLookUpTable2D_l;
    } else {
      localSwitch1 = localLookUpTable2D;
    }

    /* S-Function "vems_vidGET" Block: <S43>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_bEngReStrt, mFuSpCrk_B.VEMS_vidGET3_b);

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S43>/ConstVal'
     *  DataTypeConversion: '<S43>/Data Type Conversion1'
     */
    if (mFuSpCrk_B.VEMS_vidGET3_b) {
      InjSys_facCorMassFuRstrt = (((Float32)localSwitch1) * 0.00390625F) +
        0.00390625F;
    } else {
      InjSys_facCorMassFuRstrt = 1.0F;
    }
  }

  /* end of Outputs for SubSystem: '<S39>/F01_IniCrkfacCor' */
}

/* Output and update for function-call system: '<S10>/F02_IniCrkMass' */
void mFuSpCrk_F02_IniCrkMass(SInt32 controlPortIdx)
{
  Float32 localDataTypeConversion4;
  Float32 localLookupTablenD_o;
  Float32 localfractionTmp_0d;
  UInt32 localExt_tCoMes_Ext_tCoMes_A_16;
  Float32 localInterpolationUsingPreloo_l;
  Float32 localfrac[2];
  UInt32 localExt_nEngLoResl_Ext_nEngRef;
  UInt32 localbpIndex[2];
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Boolean localLogicalOperator_o;
  Boolean localLogicalOperator1;
  Boolean localLogicalOperator2;
  Float32 localSwitch3;
  Float32 localLookupTablenD;
  Float32 localAdd2;
  Float32 localSwitch2;
  Float32 localSwitch5;
  Float32 localInterpolationUsingPrelooku;
  UInt16 localOutDTConv;
  SInt32 localtmp;
  UInt8 locallocalDataTypeConversion_b;
  UInt16 locallocalDataTypeConversion1_o;

  /* Outputs for enable SubSystem: '<S40>/F02_IniCrkMass' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Constant: '<S40>/OFSVLV_u8Inhib'
   *  EnablePort: '<S46>/Enable'
   *  RelationalOperator: '<S40>/Relational Operator'
   */
  if (MFUSPCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tCoMes, mFuSpCrk_B.VEMS_vidGET4_l);

    /* DataTypeConversion: '<S46>/Data Type Conversion' */
    localtmp = mFuSpCrk_B.VEMS_vidGET4_l + 40;
    if (localtmp <= 0) {
      locallocalDataTypeConversion_b = 0U;
    } else if (localtmp > 255) {
      locallocalDataTypeConversion_b = MAX_uint8_T;
    } else {
      locallocalDataTypeConversion_b = (UInt8)localtmp;
    }

    /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_nEngLoResl, mFuSpCrk_B.VEMS_vidGET2_n);

    /* DataTypeConversion: '<S46>/Data Type Conversion1' */
    if (mFuSpCrk_B.VEMS_vidGET2_n > 2047) {
      locallocalDataTypeConversion1_o = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion1_o = (UInt16)(mFuSpCrk_B.VEMS_vidGET2_n <<
        5);
    }

    /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET5 */
    VEMS_vidGET(FISA_facStrtAdp, mFuSpCrk_B.VEMS_vidGET5_mw);

    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S46>/ConstVal'
     *  Constant: '<S46>/InjSys_bInhFISACalcMFu_C'
     */
    if (InjSys_bInhFISACalcMFu_C) {
      localOutDTConv = 128U;
    } else {
      localOutDTConv = mFuSpCrk_B.VEMS_vidGET5_mw;
    }

    /* DataTypeConversion: '<S46>/Data Type Conversion4' */
    localDataTypeConversion4 = ((Float32)localOutDTConv) * 0.0078125F;

    /* PreLookup: '<S56>/Prelookup' */
    localExt_tCoMes_Ext_tCoMes_A_16 = plook_u32u8f_binc
      (locallocalDataTypeConversion_b, (&(Ext_tCoMes_A[0])), 15U,
       &localLookupTablenD_o);

    /* Interpolation_n-D: '<S47>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localLookupTablenD_o;
    localSwitch2 = intrp1d_iu16ff_u32f_l_s(localExt_tCoMes_Ext_tCoMes_A_16,
      localfractionTmp_0d, (&(InjSys_ctTDCThdAcvDecst_T[0])));

    /* Interpolation_n-D: '<S48>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localLookupTablenD_o;
    localInterpolationUsingPrelooku = intrp1d_iu16ff_u32f_l_s
      (localExt_tCoMes_Ext_tCoMes_A_16, localfractionTmp_0d,
       (&(InjSys_ctTDCThdAcvDecSTTst_T[0])));

    /* PreLookup: '<S55>/Prelookup' */
    localExt_nEngLoResl_Ext_nEngRef = plook_u32u16f_binc
      (locallocalDataTypeConversion1_o, (&(Ext_nEngRef3_A[0])), 8U,
       &localInterpolationUsingPreloo_l);

    /* Interpolation_n-D: '<S49>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localLookupTablenD_o;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localExt_nEngLoResl_Ext_nEngRef;
    localbpIndex[1] = localExt_tCoMes_Ext_tCoMes_A_16;
    localSwitch3 = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex, localfrac,
      (&(InjSys_mFuReqCrkst_M[0])), 9U);

    /* Interpolation_n-D: '<S50>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    localfrac_0[0] = localfractionTmp_0d;
    localfractionTmp_0d = localLookupTablenD_o;
    localfrac_0[1] = localfractionTmp_0d;
    localbpIndex_0[0] = localExt_nEngLoResl_Ext_nEngRef;
    localbpIndex_0[1] = localExt_tCoMes_Ext_tCoMes_A_16;
    localAdd2 = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjSys_mFuReqCrkSTTst_M[0])), 9U);

    /* Interpolation_n-D: '<S51>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    localfrac_1[0] = localfractionTmp_0d;
    localfractionTmp_0d = localLookupTablenD_o;
    localfrac_1[1] = localfractionTmp_0d;
    localbpIndex_1[0] = localExt_nEngLoResl_Ext_nEngRef;
    localbpIndex_1[1] = localExt_tCoMes_Ext_tCoMes_A_16;
    localSwitch5 = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex_1, localfrac_1,
      (&(InjSys_mFuReqCrkMinst_M[0])), 9U);

    /* Interpolation_n-D: '<S52>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    localfrac_2[0] = localfractionTmp_0d;
    localfractionTmp_0d = localLookupTablenD_o;
    localfrac_2[1] = localfractionTmp_0d;
    localbpIndex_2[0] = localExt_nEngLoResl_Ext_nEngRef;
    localbpIndex_2[1] = localExt_tCoMes_Ext_tCoMes_A_16;
    localInterpolationUsingPreloo_l = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex_2,
      localfrac_2, (&(InjSys_mFuReqCrkMinSTTst_M[0])), 9U);

    /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, mFuSpCrk_B.VEMS_vidGET1_g);

    /* Logic: '<S46>/Logical Operator' */
    localLogicalOperator_o = !mFuSpCrk_B.VEMS_vidGET1_g;

    /* Logic: '<S46>/Logical Operator1' */
    localLogicalOperator1 = !mFuSpCrk_B.VEMS_vidGET1_g;

    /* Logic: '<S46>/Logical Operator2' */
    localLogicalOperator2 = !mFuSpCrk_B.VEMS_vidGET1_g;

    /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET6 */
    VEMS_vidGET(UsThrM_pAirExt, mFuSpCrk_B.VEMS_vidGET6_i);

    /* Lookup_n-D: '<S53>/Lookup Table (n-D)' */
    localLookupTablenD_o = look1_iu16lftu8n7If_binlcns__1(mFuSpCrk_B.VEMS_vidGET6_i,
      (&(InjSys_pAirExt_A[0])), (&(InjSys_facCorpAirMassFu_T[0])), 8U);

    /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_pFuRailMes, mFuSpCrk_B.VEMS_vidGET3_a);

    /* Lookup_n-D: '<S54>/Lookup Table (n-D)' */
    localLookupTablenD = look1_iu16lftu8n7If_binlcns__1(mFuSpCrk_B.VEMS_vidGET3_a,
      (&(Ext_pFuRailMesRef2_A[0])), (&(InjSys_facCorpFuMassFu_T[0])), 8U);

    /* Switch: '<S46>/Switch3' */
    if (!localLogicalOperator1) {
      localSwitch3 = localAdd2;
    }

    /* Product: '<S61>/Divide' incorporates:
     *  Product: '<S59>/Divide'
     */
    localfractionTmp_0d = (localSwitch3 * localLookupTablenD) *
      localLookupTablenD_o;

    /* DataTypeConversion: '<S57>/OutDTConv' incorporates:
     *  Constant: '<S57>/offset'
     *  Constant: '<S57>/offset1'
     *  Constant: '<S57>/one_on_slope'
     *  Product: '<S57>/Product4'
     *  Product: '<S62>/Divide'
     *  Product: '<S63>/Divide'
     *  Product: '<S64>/Divide'
     *  Sum: '<S57>/Add1'
     *  Sum: '<S57>/Add2'
     */
    localfractionTmp_0d = ((((localfractionTmp_0d * localDataTypeConversion4) *
      InjSys_facCorMassFuRstrt) * mFuSpCrk_B.Merge3) * 1.34217728E+008F) + 0.5F;
    if (localfractionTmp_0d < 65536.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        locallocalDataTypeConversion1_o = (UInt16)localfractionTmp_0d;
      } else {
        locallocalDataTypeConversion1_o = 0U;
      }
    } else {
      locallocalDataTypeConversion1_o = MAX_uint16_T;
    }

    /* Switch: '<S46>/Switch2' */
    if (!localLogicalOperator_o) {
      localSwitch2 = localInterpolationUsingPrelooku;
    }

    /* DataTypeConversion: '<S58>/OutDTConv' incorporates:
     *  Constant: '<S58>/offset'
     *  Constant: '<S58>/offset1'
     *  Constant: '<S58>/one_on_slope'
     *  Product: '<S58>/Product4'
     *  Sum: '<S58>/Add1'
     *  Sum: '<S58>/Add2'
     */
    localfractionTmp_0d = localSwitch2 + 0.5F;
    if (localfractionTmp_0d < 65536.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        InjSys_ctTDCThdAcvDecMassFu = (UInt16)localfractionTmp_0d;
      } else {
        InjSys_ctTDCThdAcvDecMassFu = 0U;
      }
    } else {
      InjSys_ctTDCThdAcvDecMassFu = MAX_uint16_T;
    }

    /* S-Function "vems_vidGET" Block: <S46>/VEMS_vidGET */
    VEMS_vidGET(ActrTstHPPmp_bActrTstInProgs, mFuSpCrk_B.VEMS_vidGET_g);

    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S46>/InjSys_bInhFISACalcMFu_C1'
     */
    if (mFuSpCrk_B.VEMS_vidGET_g) {
      mFuSpCrk_B.Switch1 = InjSys_mFuCrkActrTstHPPmp_C;
    } else {
      mFuSpCrk_B.Switch1 = locallocalDataTypeConversion1_o;
    }

    /* Switch: '<S46>/Switch5' */
    if (!localLogicalOperator2) {
      localSwitch5 = localInterpolationUsingPreloo_l;
    }

    /* S-Function "vems_vidSET" Block: <S46>/VEMS_vidSET */
    VEMS_vidSET(InjSys_mFuCrkSp, mFuSpCrk_B.Switch1);

    /* Product: '<S68>/Divide' incorporates:
     *  Product: '<S60>/Divide'
     */
    localfractionTmp_0d = (localLookupTablenD * localSwitch5) *
      localLookupTablenD_o;

    /* Product: '<S65>/Divide' incorporates:
     *  Product: '<S66>/Divide'
     *  Product: '<S67>/Divide'
     */
    InjSys_mFuReqCrkMin = ((localDataTypeConversion4 * localfractionTmp_0d) *
      InjSys_facCorMassFuRstrt) * mFuSpCrk_B.Merge3;
  }

  /* end of Outputs for SubSystem: '<S40>/F02_IniCrkMass' */
}

/* Start for exported function: InjSys_EveKOn_mFuSpCrk */
void InjSys_EveKOn_mFuSpCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S10>/mFuSpCrk_fc_demux1'
   */
}

/* Output and update for exported function: InjSys_EveKOn_mFuSpCrk */
void InjSys_EveKOn_mFuSpCrk(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S10>/mFuSpCrk_fc_demux1'
   */

  /* S-Function (fcncallgen): '<S41>/Function-Call Generator' */
  mFuSpCrk_ASYNC9(0);
  mFuSpCrk_ASYNC7(1);
}

/* Output and update for function-call system: '<S7>/F01_mFuFacCorRstrtSTT' */
void mFuSpCrk_F01_mFuFacCorRstrtSTT(SInt32 controlPortIdx)
{
  /* Outputs for enable SubSystem: '<S8>/F01_mFuFacCorRstrtSTT' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/OFSVLV_u8Inhib'
   *  EnablePort: '<S16>/Enable'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if (MFUSPCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tCoMes, mFuSpCrk_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, mFuSpCrk_B.VEMS_vidGET_f);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET5 */
    VEMS_vidGET(UsThrM_pAirExt, mFuSpCrk_B.VEMS_vidGET5_l);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_mO2Cat, mFuSpCrk_B.VEMS_vidGET2_i);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_nEng, mFuSpCrk_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_ctTDCStrt, mFuSpCrk_B.VEMS_vidGET1_b);

    /* Outputs for atomic SubSystem: '<S16>/F01_mFuFacCorRstrtSTT_Reusable' */
    F01_mFuFacCorRstrtSTT_Reusable(mFuSpCrk_B.VEMS_vidGET2_i,
      mFuSpCrk_B.VEMS_vidGET4, mFuSpCrk_B.VEMS_vidGET3,
      mFuSpCrk_B.VEMS_vidGET1_b, mFuSpCrk_B.VEMS_vidGET_f,
      mFuSpCrk_B.VEMS_vidGET5_l, &mFuSpCrk_B.F01_mFuFacCorRstrtSTT_Reusabl_g);

    /* end of Outputs for SubSystem: '<S16>/F01_mFuFacCorRstrtSTT_Reusable' */

    /* SignalConversion: '<S16>/Signal Conversion2' */
    mFuSpCrk_B.Merge3 = mFuSpCrk_B.F01_mFuFacCorRstrtSTT_Reusabl_g.Switch;
  }

  /* end of Outputs for SubSystem: '<S8>/F01_mFuFacCorRstrtSTT' */
}

/* Start for exported function: InjSys_EveStTR_mFuSpCrk */
void InjSys_EveStTR_mFuSpCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S7>/demux_fc1'
   */
}

/* Output and update for exported function: InjSys_EveStTR_mFuSpCrk */
void InjSys_EveStTR_mFuSpCrk(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S7>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S13>/gen' incorporates:
   *  SubSystem: '<S10>/mFuSpCrk_fc_demux2'
   */
  mFuSpCrk_ASYNC4(0);

  /* S-Function (fcncallgen): '<S42>/Function-Call Generator' */
  mFuSpCrk_ASYNC9(1);
  mFuSpCrk_ASYNC7(2);
}

/* Output and update for exported function: InjSys_EveRTCr_mFuSpCrk */
void InjSys_EveRTCr_mFuSpCrk(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' */
  mFuSpCrk_ASYNC7(0);
}

/*
 * Output and update for action system:
 *    '<S70>/F01_mFuInjCutOff'
 *    '<S99>/F01_mFuTDCInjCutOff'
 */
void mFuSpCrk_F01_mFuInjCutOff(UInt16 *rty_InjSys_mFuCrkSp)
{
  /* SignalConversion: '<S71>/Signal Conversion2' incorporates:
   *  Constant: '<S71>/ConstVal'
   */
  (*rty_InjSys_mFuCrkSp) = 0U;
}

/* Start for exported function: InjSys_SdlFast_mFuSpCrk */
void InjSys_SdlFast_mFuSpCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S7>/demux_fc2'
   */

  /* Start for S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  Start for SubSystem: '<S7>/F03_mFuSpClcnSdlFast'
   */

  /* Start for enable SubSystem: '<S11>/F03_mFuSpClcnSdlFast' */

  /* Start for If: '<S69>/If' */
  mFuSpCrk_DWork.If_ActiveSubsystem_h = -1;

  /* Start for ifaction SubSystem: '<S69>/F01_mFuSpCrkSdlFast' */

  /* Start for If: '<S70>/If' */
  mFuSpCrk_DWork.If_ActiveSubsystem_ev = -1;

  /* end of Start for SubSystem: '<S69>/F01_mFuSpCrkSdlFast' */

  /* end of Start for SubSystem: '<S11>/F03_mFuSpClcnSdlFast' */
}

/* Output and update for exported function: InjSys_SdlFast_mFuSpCrk */
void InjSys_SdlFast_mFuSpCrk(void)
{
  /* local block i/o variables */
  UInt8 localSwitch1_f;
  Boolean localRelationalOperator;
  SInt8 localrtAction;
  SInt8 localrtAction_0;
  Float32 localDataTypeConversion2_e;
  Float32 localInterpolationUsingPreloo_f;
  Float32 localfrac[2];
  Float32 localLookupTablenD_m;
  UInt32 localExt_nEngLoResl_Ext_nEngR_o;
  UInt32 localbpIndex[2];
  UInt32 localExt_tCoMes_Ext_tCoMes_A__i;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Float32 localSwitch3_d;
  Float32 localLookupTablenD_j;
  Float32 localAdd2_h;
  Float32 localSwitch5_c;
  Float32 localDataTypeConversion1_l;
  UInt16 localOutDTConv_l;
  UInt16 localOutDTConv_l1;
  SInt32 localtmp;
  UInt8 locallocalDataTypeConversion_i;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S7>/demux_fc2'
   */

  /* S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  SubSystem: '<S7>/F03_mFuSpClcnSdlFast'
   */
  mFuSpCrk_ASYNC4(1);

  /* RelationalOperator: '<S11>/Relational Operator' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/OFSVLV_u8Inhib'
   */
  localRelationalOperator = (MFUSPCRK_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S11>/F03_mFuSpClcnSdlFast' incorporates:
   *  EnablePort: '<S69>/Enable'
   */
  if (localRelationalOperator) {
    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bInhInjAntiFlood, mFuSpCrk_B.VEMS_vidGET8_i);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET6 */
    VEMS_vidGET(Ext_tCoMes, mFuSpCrk_B.VEMS_vidGET6_d);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_nEngLoResl, mFuSpCrk_B.VEMS_vidGET4_e);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_ctTDCTot, mFuSpCrk_B.VEMS_vidGET3_e);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET9 */
    VEMS_vidGET(InjSys_bInhInjHPst, mFuSpCrk_B.VEMS_vidGET9_o);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_pFuRailMes, mFuSpCrk_B.VEMS_vidGET5_m);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, mFuSpCrk_B.VEMS_vidGET1_k);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET10 */
    VEMS_vidGET(UsThrM_pAirExt, mFuSpCrk_B.VEMS_vidGET10_g);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET7 */
    VEMS_vidGET(FISA_facStrtAdp, mFuSpCrk_B.VEMS_vidGET7_i);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET12 */
    VEMS_vidGET(InjSys_mFuCrkSp, InjSys_mFuCrkSpPrev);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET */
    VEMS_vidGET(ActrTstHPPmp_bActrTstInProgs, mFuSpCrk_B.VEMS_vidGET_p);

    /* S-Function "vems_vidGET" Block: <S69>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_stEru, mFuSpCrk_B.VEMS_vidGET2_j);

    /* If: '<S69>/If' incorporates:
     *  ActionPort: '<S70>/Action Port'
     *  Constant: '<S69>/Ext_stCrk_SC'
     *  Constant: '<S69>/InjSys_bSelSdlClcnMassFuCrk_C'
     *  Logic: '<S69>/Logical Operator3'
     *  RelationalOperator: '<S69>/Relational Operator2'
     *  SubSystem: '<S69>/F01_mFuSpCrkSdlFast'
     */
    localrtAction = -1;
    if ((mFuSpCrk_B.VEMS_vidGET2_j == Ext_stCrk_SC) &&
        InjSys_bSelSdlClcnMassFuCrk_C) {
      localrtAction = 0;

      /* If: '<S70>/If' incorporates:
       *  ActionPort: '<S71>/Action Port'
       *  ActionPort: '<S72>/Action Port'
       *  SubSystem: '<S70>/F01_mFuInjCutOff'
       *  SubSystem: '<S70>/F02_mFuNoInjCutOff'
       */
      if (mFuSpCrk_B.VEMS_vidGET8_i) {
        localrtAction_0 = 0;
        mFuSpCrk_F01_mFuInjCutOff(&mFuSpCrk_B.Merge_n);
      } else {
        localrtAction_0 = 1;

        /* Switch: '<S75>/Switch1' incorporates:
         *  Logic: '<S72>/Logical Operator2'
         *  UnitDelay: '<S97>/Unit Delay'
         */
        if (!mFuSpCrk_B.VEMS_vidGET9_o) {
          localSwitch1_f = mFuSpCrk_DWork.UnitDelay_DSTATE_d;
        } else {
          localSwitch1_f = mFuSpCrk_B.VEMS_vidGET3_e;
        }

        /* If: '<S72>/If' incorporates:
         *  ActionPort: '<S73>/Action Port'
         *  ActionPort: '<S74>/Action Port'
         *  Logic: '<S72>/Logical Operator1'
         *  RelationalOperator: '<S72>/Relational Operator'
         *  SubSystem: '<S72>/F01_mFuSpPrevDec'
         *  SubSystem: '<S72>/F02_mFuSpDec'
         *  Sum: '<S72>/Sum1'
         */
        if (!((mFuSpCrk_B.VEMS_vidGET3_e - localSwitch1_f) >
              InjSys_ctTDCThdAcvDecMassFu)) {
          /* DataTypeConversion: '<S73>/Data Type Conversion' */
          localtmp = mFuSpCrk_B.VEMS_vidGET6_d + 40;
          if (localtmp <= 0) {
            locallocalDataTypeConversion_i = 0U;
          } else if (localtmp > 255) {
            locallocalDataTypeConversion_i = MAX_uint8_T;
          } else {
            locallocalDataTypeConversion_i = (UInt8)localtmp;
          }

          /* DataTypeConversion: '<S73>/Data Type Conversion1' */
          if (mFuSpCrk_B.VEMS_vidGET4_e > 2047) {
            localOutDTConv_l1 = MAX_uint16_T;
          } else {
            localOutDTConv_l1 = (UInt16)(mFuSpCrk_B.VEMS_vidGET4_e << 5);
          }

          /* Switch: '<S73>/Switch1' incorporates:
           *  Constant: '<S73>/ConstVal'
           *  Constant: '<S73>/InjSys_bInhFISACalcMFu_C'
           */
          if (InjSys_bInhFISACalcMFu_C) {
            localOutDTConv_l = 128U;
          } else {
            localOutDTConv_l = mFuSpCrk_B.VEMS_vidGET7_i;
          }

          /* DataTypeConversion: '<S73>/Data Type Conversion2' */
          localDataTypeConversion2_e = ((Float32)localOutDTConv_l) * 0.0078125F;

          /* PreLookup: '<S82>/Prelookup' */
          localExt_nEngLoResl_Ext_nEngR_o = plook_u32u16f_binc(localOutDTConv_l1,
            (&(Ext_nEngRef3_A[0])), 8U, &localInterpolationUsingPreloo_f);

          /* PreLookup: '<S83>/Prelookup' */
          localExt_tCoMes_Ext_tCoMes_A__i = plook_u32u8f_binc
            (locallocalDataTypeConversion_i, (&(Ext_tCoMes_A[0])), 15U,
             &localLookupTablenD_m);

          /* Interpolation_n-D: '<S76>/Interpolation Using Prelookup3' */
          localDataTypeConversion1_l = localInterpolationUsingPreloo_f;
          localfrac[0] = localDataTypeConversion1_l;
          localDataTypeConversion1_l = localLookupTablenD_m;
          localfrac[1] = localDataTypeConversion1_l;
          localbpIndex[0] = localExt_nEngLoResl_Ext_nEngR_o;
          localbpIndex[1] = localExt_tCoMes_Ext_tCoMes_A__i;
          localSwitch3_d = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex, localfrac,
            (&(InjSys_mFuReqCrkst_M[0])), 9U);

          /* Interpolation_n-D: '<S77>/Interpolation Using Prelookup3' */
          localDataTypeConversion1_l = localInterpolationUsingPreloo_f;
          localfrac_0[0] = localDataTypeConversion1_l;
          localDataTypeConversion1_l = localLookupTablenD_m;
          localfrac_0[1] = localDataTypeConversion1_l;
          localbpIndex_0[0] = localExt_nEngLoResl_Ext_nEngR_o;
          localbpIndex_0[1] = localExt_tCoMes_Ext_tCoMes_A__i;
          localAdd2_h = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex_0, localfrac_0,
            (&(InjSys_mFuReqCrkSTTst_M[0])), 9U);

          /* Interpolation_n-D: '<S78>/Interpolation Using Prelookup3' */
          localDataTypeConversion1_l = localInterpolationUsingPreloo_f;
          localfrac_1[0] = localDataTypeConversion1_l;
          localDataTypeConversion1_l = localLookupTablenD_m;
          localfrac_1[1] = localDataTypeConversion1_l;
          localbpIndex_1[0] = localExt_nEngLoResl_Ext_nEngR_o;
          localbpIndex_1[1] = localExt_tCoMes_Ext_tCoMes_A__i;
          localSwitch5_c = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex_1,
            localfrac_1, (&(InjSys_mFuReqCrkMinst_M[0])), 9U);

          /* Interpolation_n-D: '<S79>/Interpolation Using Prelookup3' */
          localDataTypeConversion1_l = localInterpolationUsingPreloo_f;
          localfrac_2[0] = localDataTypeConversion1_l;
          localDataTypeConversion1_l = localLookupTablenD_m;
          localfrac_2[1] = localDataTypeConversion1_l;
          localbpIndex_2[0] = localExt_nEngLoResl_Ext_nEngR_o;
          localbpIndex_2[1] = localExt_tCoMes_Ext_tCoMes_A__i;
          localInterpolationUsingPreloo_f = intrp2d_iu16n27ff_u32f_l_ns
            (localbpIndex_2, localfrac_2, (&(InjSys_mFuReqCrkMinSTTst_M[0])), 9U);

          /* Lookup_n-D: '<S80>/Lookup Table (n-D)' */
          localLookupTablenD_m = look1_iu16lftu8n7If_binlcns__1
            (mFuSpCrk_B.VEMS_vidGET5_m, (&(Ext_pFuRailMesRef2_A[0])),
             (&(InjSys_facCorpFuMassFu_T[0])), 8U);

          /* Lookup_n-D: '<S81>/Lookup Table (n-D)' */
          localLookupTablenD_j = look1_iu16lftu8n7If_binlcns__1
            (mFuSpCrk_B.VEMS_vidGET10_g, (&(InjSys_pAirExt_A[0])),
             (&(InjSys_facCorpAirMassFu_T[0])), 8U);

          /* Switch: '<S73>/Switch3' incorporates:
           *  Logic: '<S73>/Logical Operator1'
           */
          if (mFuSpCrk_B.VEMS_vidGET1_k) {
            localSwitch3_d = localAdd2_h;
          }

          /* Product: '<S85>/Divide' */
          localDataTypeConversion1_l = localSwitch3_d * localLookupTablenD_m;

          /* Switch: '<S73>/Switch2' incorporates:
           *  Constant: '<S73>/InjSys_bInhFISACalcMFu_C1'
           *  Constant: '<S84>/offset'
           *  Constant: '<S84>/offset1'
           *  Constant: '<S84>/one_on_slope'
           *  DataTypeConversion: '<S84>/OutDTConv'
           *  Product: '<S84>/Product4'
           *  Product: '<S87>/Divide'
           *  Product: '<S89>/Divide'
           *  Product: '<S90>/Divide'
           *  Product: '<S93>/Divide'
           *  Sum: '<S84>/Add1'
           *  Sum: '<S84>/Add2'
           */
          if (mFuSpCrk_B.VEMS_vidGET_p) {
            mFuSpCrk_B.Merge_n = InjSys_mFuCrkActrTstHPPmp_C;
          } else {
            localDataTypeConversion1_l = (((((localDataTypeConversion1_l *
              localLookupTablenD_j) * localDataTypeConversion2_e) *
              InjSys_facCorMassFuRstrt) * mFuSpCrk_B.Merge3) * 1.34217728E+008F)
              + 0.5F;
            if (localDataTypeConversion1_l < 65536.0F) {
              if (localDataTypeConversion1_l >= 0.0F) {
                mFuSpCrk_B.Merge_n = (UInt16)localDataTypeConversion1_l;
              } else {
                mFuSpCrk_B.Merge_n = 0U;
              }
            } else {
              mFuSpCrk_B.Merge_n = MAX_uint16_T;
            }
          }

          /* Switch: '<S73>/Switch5' incorporates:
           *  Logic: '<S73>/Logical Operator2'
           */
          if (mFuSpCrk_B.VEMS_vidGET1_k) {
            localSwitch5_c = localInterpolationUsingPreloo_f;
          }

          /* Product: '<S86>/Divide' */
          localDataTypeConversion1_l = localLookupTablenD_m * localSwitch5_c;

          /* Product: '<S94>/Divide' incorporates:
           *  Product: '<S88>/Divide'
           *  Product: '<S91>/Divide'
           *  Product: '<S92>/Divide'
           */
          InjSys_mFuReqCrkMin = (((localLookupTablenD_j *
            localDataTypeConversion1_l) * localDataTypeConversion2_e) *
            InjSys_facCorMassFuRstrt) * mFuSpCrk_B.Merge3;
        } else {
          /* Switch: '<S74>/Switch3' incorporates:
           *  Constant: '<S74>/InjSys_mFuDecStepSTTst_C'
           *  Constant: '<S74>/InjSys_mFuDecStepst_C'
           *  Logic: '<S74>/Logical Operator2'
           */
          if (!mFuSpCrk_B.VEMS_vidGET1_k) {
            localOutDTConv_l1 = InjSys_mFuDecStepst_C;
          } else {
            localOutDTConv_l1 = InjSys_mFuDecStepSTTst_C;
          }

          /* DataTypeConversion: '<S74>/Data Type Conversion1' */
          localDataTypeConversion1_l = ((Float32)localOutDTConv_l1) *
            3.200000037E-006F;

          /* Switch: '<S74>/Switch' incorporates:
           *  Constant: '<S74>/ConstVal'
           *  Constant: '<S74>/InjSys_bInhFISAAntiFlood_C'
           */
          if (InjSys_bInhFISAAntiFlood_C) {
            localOutDTConv_l1 = 128U;
          } else {
            localOutDTConv_l1 = mFuSpCrk_B.VEMS_vidGET7_i;
          }

          /* Sum: '<S74>/Sum' incorporates:
           *  DataTypeConversion: '<S74>/Data Type Conversion2'
           *  DataTypeConversion: '<S74>/Data Type Conversion3'
           *  Product: '<S96>/Divide'
           */
          localDataTypeConversion1_l = (((Float32)InjSys_mFuCrkSpPrev) *
            7.450580597E-009F) - ((((Float32)localOutDTConv_l1) * 0.0078125F) *
            localDataTypeConversion1_l);

          /* SignalConversion: '<S74>/Signal Conversion2' */
          InjSys_mFuReqCrkMinPrev = InjSys_mFuReqCrkMin;

          /* Switch: '<S74>/Switch2' incorporates:
           *  Constant: '<S74>/InjSys_bInhFISACalcMFu_C1'
           *  Constant: '<S95>/offset'
           *  Constant: '<S95>/offset1'
           *  Constant: '<S95>/one_on_slope'
           *  DataTypeConversion: '<S95>/OutDTConv'
           *  MinMax: '<S74>/MinMax'
           *  Product: '<S95>/Product4'
           *  Sum: '<S95>/Add1'
           *  Sum: '<S95>/Add2'
           */
          if (mFuSpCrk_B.VEMS_vidGET_p) {
            mFuSpCrk_B.Merge_n = InjSys_mFuCrkActrTstHPPmp_C;
          } else {
            localDataTypeConversion1_l = (1.34217728E+008F * rt_MAXf
              (localDataTypeConversion1_l, InjSys_mFuReqCrkMinPrev)) + 0.5F;
            if (localDataTypeConversion1_l < 65536.0F) {
              if (localDataTypeConversion1_l >= 0.0F) {
                mFuSpCrk_B.Merge_n = (UInt16)localDataTypeConversion1_l;
              } else {
                mFuSpCrk_B.Merge_n = 0U;
              }
            } else {
              mFuSpCrk_B.Merge_n = MAX_uint16_T;
            }
          }
        }
      }

      mFuSpCrk_DWork.If_ActiveSubsystem_ev = localrtAction_0;

      /* S-Function "vems_vidSET" Block: <S70>/VEMS_vidSET */
      VEMS_vidSET(InjSys_mFuCrkSp, mFuSpCrk_B.Merge_n);
    }

    mFuSpCrk_DWork.If_ActiveSubsystem_h = localrtAction;
  }

  /* end of Outputs for SubSystem: '<S11>/F03_mFuSpClcnSdlFast' */

  /* Update for enable SubSystem: '<S11>/F03_mFuSpClcnSdlFast' incorporates:
   *  Update for EnablePort: '<S69>/Enable'
   */
  if (localRelationalOperator) {
    /* Update for If: '<S69>/If' incorporates:
     *  Update for ActionPort: '<S70>/Action Port'
     *  Update for SubSystem: '<S69>/F01_mFuSpCrkSdlFast'
     */
    if (mFuSpCrk_DWork.If_ActiveSubsystem_h == 0) {
      /* Update for If: '<S70>/If' incorporates:
       *  Update for ActionPort: '<S72>/Action Port'
       *  Update for SubSystem: '<S70>/F02_mFuNoInjCutOff'
       */
      if (mFuSpCrk_DWork.If_ActiveSubsystem_ev == 1) {
        /* Update for UnitDelay: '<S97>/Unit Delay' */
        mFuSpCrk_DWork.UnitDelay_DSTATE_d = localSwitch1_f;
      }
    }
  }

  /* end of Update for SubSystem: '<S11>/F03_mFuSpClcnSdlFast' */
}

/* Start for exported function: InjSys_EveInj_mFuSpCrk */
void InjSys_EveInj_mFuSpCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S7>/demux_fc3'
   */

  /* Start for S-Function (fcncallgen): '<S15>/gen' incorporates:
   *  Start for SubSystem: '<S7>/F04_mFuSpClcnTDC'
   */

  /* Start for enable SubSystem: '<S12>/F04_mFuSpClcnTDC' */

  /* Start for If: '<S98>/If' */
  mFuSpCrk_DWork.If_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S98>/F01_mFuSpCrkTDC' */

  /* Start for If: '<S99>/If' */
  mFuSpCrk_DWork.If_ActiveSubsystem_e = -1;

  /* end of Start for SubSystem: '<S98>/F01_mFuSpCrkTDC' */

  /* end of Start for SubSystem: '<S12>/F04_mFuSpClcnTDC' */
}

/* Output and update for exported function: InjSys_EveInj_mFuSpCrk */
void InjSys_EveInj_mFuSpCrk(void)
{
  /* local block i/o variables */
  UInt8 localSwitch1_fc;
  Boolean localRelationalOperator_g;
  Float32 localSignalConversion;
  SInt8 localrtAction;
  SInt8 localrtAction_0;
  Float32 localDataTypeConversion1_i;
  Float32 localExt_nEngLoResl_Ext_nEngR_c;
  Float32 localfrac[2];
  Float32 localExt_tCoMes_Ext_tCoMes_A__f;
  UInt32 localExt_nEngLoResl_Ext_nEngR_g;
  UInt32 localbpIndex[2];
  UInt32 localExt_tCoMes_Ext_tCoMes_A__a;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Float32 localSwitch3_f;
  Float32 localLookupTablenD_d;
  Float32 localLookupTablenD_e;
  Float32 localDataTypeConversion2_f;
  Float32 localfractionTmp_0d;
  Float32 localSwitch3_n;
  SInt32 localtmp;
  UInt8 locallocalDataTypeConversion1_c;
  UInt16 locallocalDataTypeConversion2_h;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S7>/demux_fc3'
   */

  /* S-Function (fcncallgen): '<S15>/gen' incorporates:
   *  SubSystem: '<S7>/F04_mFuSpClcnTDC'
   */
  mFuSpCrk_ASYNC4(2);

  /* RelationalOperator: '<S12>/Relational Operator' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/OFSVLV_u8Inhib'
   */
  localRelationalOperator_g = (MFUSPCRK_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S12>/F04_mFuSpClcnTDC' incorporates:
   *  EnablePort: '<S98>/Enable'
   */
  if (localRelationalOperator_g) {
    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bInhInjAntiFlood, mFuSpCrk_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET6 */
    VEMS_vidGET(Ext_tCoMes, mFuSpCrk_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_nEngLoResl, mFuSpCrk_B.VEMS_vidGET4_bo);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_ctTDCTot, mFuSpCrk_B.VEMS_vidGET3_d);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET9 */
    VEMS_vidGET(InjSys_bInhInjHPst, mFuSpCrk_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_pFuRailMes, mFuSpCrk_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, mFuSpCrk_B.VEMS_vidGET1_e);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET10 */
    VEMS_vidGET(UsThrM_pAirExt, mFuSpCrk_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET7 */
    VEMS_vidGET(FISA_facStrtAdp, mFuSpCrk_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET12 */
    VEMS_vidGET(InjSys_mFuCrkSp, mFuSpCrk_B.VEMS_vidGET12);

    /* SignalConversion: '<S98>/Signal Conversion' */
    localSignalConversion = mFuSpCrk_B.Merge3;

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET */
    VEMS_vidGET(ActrTstHPPmp_bActrTstInProgs, mFuSpCrk_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S98>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_stEru, mFuSpCrk_B.VEMS_vidGET2_p);

    /* If: '<S98>/If' incorporates:
     *  ActionPort: '<S99>/Action Port'
     *  Constant: '<S98>/Ext_stCrk_SC'
     *  Constant: '<S98>/InjSys_bSelSdlClcnMassFuCrk_C'
     *  Logic: '<S98>/Logical Operator1'
     *  Logic: '<S98>/Logical Operator2'
     *  RelationalOperator: '<S98>/Relational Operator2'
     *  SubSystem: '<S98>/F01_mFuSpCrkTDC'
     */
    localrtAction = -1;
    if ((mFuSpCrk_B.VEMS_vidGET2_p == Ext_stCrk_SC) &&
        (!InjSys_bSelSdlClcnMassFuCrk_C)) {
      localrtAction = 0;

      /* If: '<S99>/If' incorporates:
       *  ActionPort: '<S100>/Action Port'
       *  ActionPort: '<S101>/Action Port'
       *  SubSystem: '<S99>/F01_mFuTDCInjCutOff'
       *  SubSystem: '<S99>/F02_mFuTDC'
       */
      if (mFuSpCrk_B.VEMS_vidGET8) {
        localrtAction_0 = 0;
        mFuSpCrk_F01_mFuInjCutOff(&mFuSpCrk_B.Merge);
      } else {
        localrtAction_0 = 1;

        /* DataTypeConversion: '<S101>/Data Type Conversion1' */
        localtmp = mFuSpCrk_B.VEMS_vidGET6 + 40;
        if (localtmp <= 0) {
          locallocalDataTypeConversion1_c = 0U;
        } else if (localtmp > 255) {
          locallocalDataTypeConversion1_c = MAX_uint8_T;
        } else {
          locallocalDataTypeConversion1_c = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S101>/Data Type Conversion2' */
        if (mFuSpCrk_B.VEMS_vidGET4_bo > 2047) {
          locallocalDataTypeConversion2_h = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion2_h = (UInt16)
            (mFuSpCrk_B.VEMS_vidGET4_bo << 5);
        }

        /* PreLookup: '<S105>/Prelookup' */
        localExt_nEngLoResl_Ext_nEngR_g = plook_u32u16f_binc
          (locallocalDataTypeConversion2_h, (&(Ext_nEngRef3_A[0])), 8U,
           &localExt_nEngLoResl_Ext_nEngR_c);

        /* PreLookup: '<S106>/Prelookup' */
        localExt_tCoMes_Ext_tCoMes_A__a = plook_u32u8f_binc
          (locallocalDataTypeConversion1_c, (&(Ext_tCoMes_A[0])), 15U,
           &localExt_tCoMes_Ext_tCoMes_A__f);

        /* Switch: '<S104>/Switch1' incorporates:
         *  Logic: '<S101>/Logical Operator2'
         *  UnitDelay: '<S129>/Unit Delay'
         */
        if (!mFuSpCrk_B.VEMS_vidGET9) {
          localSwitch1_fc = mFuSpCrk_DWork.UnitDelay_DSTATE;
        } else {
          localSwitch1_fc = mFuSpCrk_B.VEMS_vidGET3_d;
        }

        /* If: '<S101>/If' incorporates:
         *  ActionPort: '<S102>/Action Port'
         *  ActionPort: '<S103>/Action Port'
         *  Logic: '<S101>/Logical Operator1'
         *  RelationalOperator: '<S101>/Relational Operator'
         *  SubSystem: '<S101>/F01_mFuSpTDCPrevDec'
         *  SubSystem: '<S101>/F02_mFuSpFiltTDC'
         *  Sum: '<S101>/Sum1'
         */
        if (!((mFuSpCrk_B.VEMS_vidGET3_d - localSwitch1_fc) >
              InjSys_ctTDCThdAcvDecMassFu)) {
          /* Switch: '<S102>/Switch' incorporates:
           *  Constant: '<S102>/ConstVal'
           *  Constant: '<S102>/InjSys_bInhFISACalcMFu_C'
           */
          if (InjSys_bInhFISACalcMFu_C) {
            locallocalDataTypeConversion2_h = 128U;
          } else {
            locallocalDataTypeConversion2_h = mFuSpCrk_B.VEMS_vidGET7;
          }

          /* DataTypeConversion: '<S102>/Data Type Conversion1' */
          localDataTypeConversion1_i = ((Float32)
            locallocalDataTypeConversion2_h) * 0.0078125F;

          /* Interpolation_n-D: '<S107>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_nEngLoResl_Ext_nEngR_c;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A__f;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localExt_nEngLoResl_Ext_nEngR_g;
          localbpIndex[1] = localExt_tCoMes_Ext_tCoMes_A__a;
          localSwitch3_f = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex, localfrac,
            (&(InjSys_mFuReqCrkst_M[0])), 9U);

          /* Interpolation_n-D: '<S108>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_nEngLoResl_Ext_nEngR_c;
          localfrac_0[0] = localfractionTmp_0d;
          localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A__f;
          localfrac_0[1] = localfractionTmp_0d;
          localbpIndex_0[0] = localExt_nEngLoResl_Ext_nEngR_g;
          localbpIndex_0[1] = localExt_tCoMes_Ext_tCoMes_A__a;
          localDataTypeConversion2_f = intrp2d_iu16n27ff_u32f_l_ns
            (localbpIndex_0, localfrac_0, (&(InjSys_mFuReqCrkSTTst_M[0])), 9U);

          /* Interpolation_n-D: '<S109>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_nEngLoResl_Ext_nEngR_c;
          localfrac_1[0] = localfractionTmp_0d;
          localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A__f;
          localfrac_1[1] = localfractionTmp_0d;
          localbpIndex_1[0] = localExt_nEngLoResl_Ext_nEngR_g;
          localbpIndex_1[1] = localExt_tCoMes_Ext_tCoMes_A__a;
          localSwitch3_n = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex_1,
            localfrac_1, (&(InjSys_mFuReqCrkMinst_M[0])), 9U);

          /* Interpolation_n-D: '<S110>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_nEngLoResl_Ext_nEngR_c;
          localfrac_2[0] = localfractionTmp_0d;
          localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A__f;
          localfrac_2[1] = localfractionTmp_0d;
          localbpIndex_2[0] = localExt_nEngLoResl_Ext_nEngR_g;
          localbpIndex_2[1] = localExt_tCoMes_Ext_tCoMes_A__a;
          localfractionTmp_0d = intrp2d_iu16n27ff_u32f_l_ns(localbpIndex_2,
            localfrac_2, (&(InjSys_mFuReqCrkMinSTTst_M[0])), 9U);

          /* Lookup_n-D: '<S111>/Lookup Table (n-D)' */
          localLookupTablenD_e = look1_iu16lftu8n7If_binlcns__1
            (mFuSpCrk_B.VEMS_vidGET10, (&(InjSys_pAirExt_A[0])),
             (&(InjSys_facCorpAirMassFu_T[0])), 8U);

          /* Lookup_n-D: '<S112>/Lookup Table (n-D)' */
          localLookupTablenD_d = look1_iu16lftu8n7If_binlcns__1
            (mFuSpCrk_B.VEMS_vidGET5, (&(Ext_pFuRailMesRef2_A[0])),
             (&(InjSys_facCorpFuMassFu_T[0])), 8U);

          /* Switch: '<S102>/Switch3' incorporates:
           *  Logic: '<S102>/Logical Operator1'
           */
          if (mFuSpCrk_B.VEMS_vidGET1_e) {
            localSwitch3_f = localDataTypeConversion2_f;
          }

          /* Switch: '<S102>/Switch2' incorporates:
           *  Constant: '<S102>/InjSys_bInhFISACalcMFu_C1'
           *  Constant: '<S113>/offset'
           *  Constant: '<S113>/offset1'
           *  Constant: '<S113>/one_on_slope'
           *  DataTypeConversion: '<S113>/OutDTConv'
           *  Product: '<S113>/Product4'
           *  Product: '<S114>/Divide'
           *  Product: '<S116>/Divide'
           *  Product: '<S118>/Divide'
           *  Product: '<S120>/Divide'
           *  Product: '<S122>/Divide'
           *  Sum: '<S113>/Add1'
           *  Sum: '<S113>/Add2'
           */
          if (mFuSpCrk_B.VEMS_vidGET) {
            mFuSpCrk_B.Merge = InjSys_mFuCrkActrTstHPPmp_C;
          } else {
            localDataTypeConversion2_f = ((((((localSwitch3_f *
              localLookupTablenD_d) * localLookupTablenD_e) *
              localDataTypeConversion1_i) * InjSys_facCorMassFuRstrt) *
              localSignalConversion) * 1.34217728E+008F) + 0.5F;
            if (localDataTypeConversion2_f < 65536.0F) {
              if (localDataTypeConversion2_f >= 0.0F) {
                mFuSpCrk_B.Merge = (UInt16)localDataTypeConversion2_f;
              } else {
                mFuSpCrk_B.Merge = 0U;
              }
            } else {
              mFuSpCrk_B.Merge = MAX_uint16_T;
            }
          }

          /* Switch: '<S102>/Switch5' incorporates:
           *  Logic: '<S102>/Logical Operator2'
           */
          if (mFuSpCrk_B.VEMS_vidGET1_e) {
            localSwitch3_n = localfractionTmp_0d;
          }

          /* Product: '<S123>/Divide' incorporates:
           *  Product: '<S115>/Divide'
           *  Product: '<S117>/Divide'
           *  Product: '<S119>/Divide'
           *  Product: '<S121>/Divide'
           */
          InjSys_mFuReqCrkMin = ((((localLookupTablenD_d * localSwitch3_n) *
            localLookupTablenD_e) * localDataTypeConversion1_i) *
            InjSys_facCorMassFuRstrt) * localSignalConversion;
        } else {
          /* Switch: '<S103>/Switch' incorporates:
           *  Constant: '<S103>/ConstVal'
           *  Constant: '<S103>/InjSys_bInhFISAAntiFlood_C'
           */
          if (InjSys_bInhFISAAntiFlood_C) {
            locallocalDataTypeConversion2_h = 128U;
          } else {
            locallocalDataTypeConversion2_h = mFuSpCrk_B.VEMS_vidGET7;
          }

          /* DataTypeConversion: '<S103>/Data Type Conversion2' */
          localDataTypeConversion2_f = ((Float32)mFuSpCrk_B.VEMS_vidGET12) *
            7.450580597E-009F;

          /* Interpolation_n-D: '<S124>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A__f;
          localSwitch3_n = intrp1d_iu8n8ff_u32f_l_ns
            (localExt_tCoMes_Ext_tCoMes_A__a, localfractionTmp_0d,
             (&(InjSys_rFilGainMassFust_T[0])));

          /* Interpolation_n-D: '<S125>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_tCoMes_Ext_tCoMes_A__f;
          localfractionTmp_0d = intrp1d_iu8n8ff_u32f_l_ns
            (localExt_tCoMes_Ext_tCoMes_A__a, localfractionTmp_0d,
             (&(InjSys_rFilGainMassFuSTTst_T[0])));

          /* Switch: '<S103>/Switch3' incorporates:
           *  Logic: '<S103>/Logical Operator2'
           */
          if (mFuSpCrk_B.VEMS_vidGET1_e) {
            localSwitch3_n = localfractionTmp_0d;
          }

          /* Product: '<S128>/Divide' incorporates:
           *  DataTypeConversion: '<S103>/Data Type Conversion1'
           *  Product: '<S127>/Divide'
           */
          localfractionTmp_0d = ((((Float32)locallocalDataTypeConversion2_h) *
            0.0078125F) * localSwitch3_n) * localDataTypeConversion2_f;

          /* Switch: '<S103>/Switch2' incorporates:
           *  Constant: '<S103>/InjSys_bInhFISACalcMFu_C1'
           *  Constant: '<S126>/offset'
           *  Constant: '<S126>/offset1'
           *  Constant: '<S126>/one_on_slope'
           *  DataTypeConversion: '<S126>/OutDTConv'
           *  MinMax: '<S103>/MinMax'
           *  Product: '<S126>/Product4'
           *  Sum: '<S126>/Add1'
           *  Sum: '<S126>/Add2'
           */
          if (mFuSpCrk_B.VEMS_vidGET) {
            mFuSpCrk_B.Merge = InjSys_mFuCrkActrTstHPPmp_C;
          } else {
            localDataTypeConversion2_f = (1.34217728E+008F * rt_MAXf
              (localfractionTmp_0d, InjSys_mFuReqCrkMin)) + 0.5F;
            if (localDataTypeConversion2_f < 65536.0F) {
              if (localDataTypeConversion2_f >= 0.0F) {
                mFuSpCrk_B.Merge = (UInt16)localDataTypeConversion2_f;
              } else {
                mFuSpCrk_B.Merge = 0U;
              }
            } else {
              mFuSpCrk_B.Merge = MAX_uint16_T;
            }
          }
        }
      }

      mFuSpCrk_DWork.If_ActiveSubsystem_e = localrtAction_0;

      /* S-Function "vems_vidSET" Block: <S99>/VEMS_vidSET */
      VEMS_vidSET(InjSys_mFuCrkSp, mFuSpCrk_B.Merge);
    }

    mFuSpCrk_DWork.If_ActiveSubsystem = localrtAction;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_mFuSpClcnTDC' */

  /* Update for enable SubSystem: '<S12>/F04_mFuSpClcnTDC' incorporates:
   *  Update for EnablePort: '<S98>/Enable'
   */
  if (localRelationalOperator_g) {
    /* Update for If: '<S98>/If' incorporates:
     *  Update for ActionPort: '<S99>/Action Port'
     *  Update for SubSystem: '<S98>/F01_mFuSpCrkTDC'
     */
    if (mFuSpCrk_DWork.If_ActiveSubsystem == 0) {
      /* Update for If: '<S99>/If' incorporates:
       *  Update for ActionPort: '<S101>/Action Port'
       *  Update for SubSystem: '<S99>/F02_mFuTDC'
       */
      if (mFuSpCrk_DWork.If_ActiveSubsystem_e == 1) {
        /* Update for UnitDelay: '<S129>/Unit Delay' */
        mFuSpCrk_DWork.UnitDelay_DSTATE = localSwitch1_fc;
      }
    }
  }

  /* end of Update for SubSystem: '<S12>/F04_mFuSpClcnTDC' */
}

/* Model initialize function */
void mFuSpCrk_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   */
  InjSys_EveRst_mFuSpCrk_Start();
  InjSys_EveKOn_mFuSpCrk_Start();
  InjSys_EveStTR_mFuSpCrk_Start();
  InjSys_SdlFast_mFuSpCrk_Start();
  InjSys_EveInj_mFuSpCrk_Start();
}

#define MFUSPCRK_STOP_SEC_CODE
#include "mFuSpCrk_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
