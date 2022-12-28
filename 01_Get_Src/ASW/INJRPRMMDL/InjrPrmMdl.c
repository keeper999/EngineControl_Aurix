/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjrPrmMdl                                              */
/* !Description     : INJECTOR MODEL PARAMETERS SPECIFICATION                 */
/*                                                                            */
/* !Module          : InjrPrmMdl                                              */
/*                                                                            */
/* !File            : InjrPrmMdl.c                                            */
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
/* !Reference       : V02NT1203959 / 01                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Sep 12 10:33:08 2012                              */
/*   Model name       : InjrPrmMdl_AUTOCODE.mdl                               */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /InjrPrmMdl                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjrPrmMdl/5-SOFT-LIV/InjrPr$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   25 Sep 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjrPrmMdl.h"
#include "InjrPrmMdl_private.h"

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
#define INJRPRMMDL_START_SEC_VAR_UNSPECIFIED
#include "InjrPrmMdl_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjrPrmMdl InjrPrmMdl_B;

#define INJRPRMMDL_STOP_SEC_VAR_UNSPECIFIED
#include "InjrPrmMdl_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJRPRMMDL_START_SEC_CODE
#include "InjrPrmMdl_MemMap.h"

void InjrPrmMdl_ASYNC1(int controlPortIdx)
{
}

void InjrPrmMdl_ASYNC2(int controlPortIdx)
{
  InjrPrmMdl_F03_InjrPrmMdlFct_e();
}

void InjrPrmMdl_ASYNC3(int controlPortIdx)
{
  InjrPrmMdl_F01_SyncIn();
  InjrPr_F03_InjrMdlCylCorSyncEve();
}

/*
 * Output and update for atomic system:
 *    '<S18>/F02_SyncIn1'
 *    '<S32>/F02_SyncIn1'
 */
void InjrPrmMdl_F02_SyncIn1(UInt8 rtu_Eng_noInNxtCyl, UInt8 rtu_Eng_noInCyl,
  const UInt16 rtu_FuSysM_prm_pFuEstimInjS2Cyl[6], const UInt16
  rtu_InjSys_prm_mFuInjH2ReqCyl[6], const UInt16
  rtu_InjSys_prm_mFuInjS1ReqCyl[6], const UInt16
  rtu_InjSys_prm_mFuInjS2ReqCyl[6], const UInt16
  rtu_FuSysM_prm_pFuEstimInjS1Cyl[6], const UInt16
  rtu_FuSysM_prm_pFuEstimInjH2Cyl[6], const UInt16
  rtu_FuSysM_prm_pFuEstimInjH1Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjH1Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjH2Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjS1Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjS2Cyl[6], const UInt16
  rtu_InjSys_prm_mFuInjH1ReqCyl[6], UInt16 *rty_InjrM_prm_pCylEstimInj,
  UInt16 *rty_InjrM_prm_pFuEstimInj, UInt16 *rty_InjrM_prm_pFuEstimInj_l,
  UInt16 *rty_InjrM_prm_pFuEstimInj_a, UInt16 *rty_InjrM_prm_pCylEstimInj_j,
  UInt16 *rty_InjrM_prm_pCylEstimInj_i, UInt16 *rty_InjrM_prm_mFuInjReq,
  UInt16 *rty_InjrM_prm_mFuInjReq_k, UInt16 *rty_InjrM_prm_mFuInjReq_l,
  UInt16 *rty_InjrM_prm_pCylEstimInj_l, UInt16 *rty_InjrM_prm_mFuInjReq_n,
  UInt16 *rty_InjrM_prm_pFuEstimInj_m)
{
  UInt32 localAdd_c;
  UInt32 localAdd_n;
  UInt32 localAdd_ct;
  SInt32 localmin;
  SInt32 localmin_0;
  SInt32 localmin_1;
  SInt32 localmin_2;
  SInt32 localmin_3;
  SInt32 localmin_4;
  SInt32 localmin_5;
  SInt32 localmin_6;
  SInt32 localmin_7;

  /* DataTypeConversion: '<S46>/Data Type Conversion1' */
  localAdd_c = rtu_Eng_noInNxtCyl;

  /* DataTypeConversion: '<S46>/Data Type Conversion3' */
  localAdd_n = rtu_Eng_noInCyl;

  /* Sum: '<S47>/Add' incorporates:
   *  Constant: '<S47>/Constant1'
   */
  localAdd_ct = localAdd_n - 1U;

  /* MinMax: '<S47>/MinMax' incorporates:
   *  Constant: '<S47>/Constant'
   */
  localmin = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S48>/Add' incorporates:
   *  Constant: '<S48>/Constant1'
   */
  localAdd_ct = localAdd_c - 1U;

  /* MinMax: '<S48>/MinMax' incorporates:
   *  Constant: '<S48>/Constant'
   */
  localmin_0 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S49>/Add' incorporates:
   *  Constant: '<S49>/Constant1'
   */
  localAdd_ct = localAdd_n - 1U;

  /* MinMax: '<S49>/MinMax' incorporates:
   *  Constant: '<S49>/Constant'
   */
  localmin_1 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S50>/Add' incorporates:
   *  Constant: '<S50>/Constant1'
   */
  localAdd_ct = localAdd_n - 1U;

  /* MinMax: '<S50>/MinMax' incorporates:
   *  Constant: '<S50>/Constant'
   */
  localmin_2 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S51>/Add' incorporates:
   *  Constant: '<S51>/Constant1'
   */
  localAdd_ct = localAdd_n - 1U;

  /* MinMax: '<S51>/MinMax' incorporates:
   *  Constant: '<S51>/Constant'
   */
  localmin_3 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S52>/Add' incorporates:
   *  Constant: '<S52>/Constant1'
   */
  localAdd_ct = localAdd_c - 1U;

  /* MinMax: '<S52>/MinMax' incorporates:
   *  Constant: '<S52>/Constant'
   */
  localmin_4 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S53>/Add' incorporates:
   *  Constant: '<S53>/Constant1'
   */
  localAdd_ct = localAdd_c - 1U;

  /* MinMax: '<S53>/MinMax' incorporates:
   *  Constant: '<S53>/Constant'
   */
  localmin_5 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S54>/Add' incorporates:
   *  Constant: '<S54>/Constant1'
   */
  localAdd_ct = localAdd_c - 1U;

  /* MinMax: '<S54>/MinMax' incorporates:
   *  Constant: '<S54>/Constant'
   */
  localmin_6 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S55>/Add' incorporates:
   *  Constant: '<S55>/Constant1'
   */
  localAdd_ct = localAdd_c - 1U;

  /* MinMax: '<S55>/MinMax' incorporates:
   *  Constant: '<S55>/Constant'
   */
  localmin_7 = (SInt32)rt_MIN(localAdd_ct, 5U);

  /* Sum: '<S56>/Add' incorporates:
   *  Constant: '<S56>/Constant1'
   */
  localAdd_ct = localAdd_n - 1U;

  /* Sum: '<S57>/Add' incorporates:
   *  Constant: '<S57>/Constant1'
   */
  localAdd_n--;

  /* Sum: '<S58>/Add' incorporates:
   *  Constant: '<S58>/Constant1'
   */
  localAdd_c--;

  /* SignalConversion: '<S46>/Signal Conversion1' incorporates:
   *  Selector: '<S55>/Selector'
   */
  (*rty_InjrM_prm_pCylEstimInj) = rtu_CylM_prm_pCylEstimInjH2Cyl[(localmin_7)];

  /* SignalConversion: '<S46>/Signal Conversion10' incorporates:
   *  Selector: '<S52>/Selector'
   */
  (*rty_InjrM_prm_pFuEstimInj) = rtu_FuSysM_prm_pFuEstimInjH2Cyl[(localmin_4)];

  /* SignalConversion: '<S46>/Signal Conversion11' incorporates:
   *  Selector: '<S51>/Selector'
   */
  (*rty_InjrM_prm_pFuEstimInj_l) = rtu_FuSysM_prm_pFuEstimInjS1Cyl[(localmin_3)];

  /* SignalConversion: '<S46>/Signal Conversion12' incorporates:
   *  Selector: '<S47>/Selector'
   */
  (*rty_InjrM_prm_pFuEstimInj_a) = rtu_FuSysM_prm_pFuEstimInjS2Cyl[(localmin)];

  /* SignalConversion: '<S46>/Signal Conversion2' incorporates:
   *  Constant: '<S56>/Constant'
   *  MinMax: '<S56>/MinMax'
   *  Selector: '<S56>/Selector'
   */
  (*rty_InjrM_prm_pCylEstimInj_j) = rtu_CylM_prm_pCylEstimInjS1Cyl[rt_MIN
    (localAdd_ct, 5U)];

  /* SignalConversion: '<S46>/Signal Conversion3' incorporates:
   *  Constant: '<S57>/Constant'
   *  MinMax: '<S57>/MinMax'
   *  Selector: '<S57>/Selector'
   */
  (*rty_InjrM_prm_pCylEstimInj_i) = rtu_CylM_prm_pCylEstimInjS2Cyl[rt_MIN
    (localAdd_n, 5U)];

  /* SignalConversion: '<S46>/Signal Conversion4' incorporates:
   *  Constant: '<S58>/Constant'
   *  MinMax: '<S58>/MinMax'
   *  Selector: '<S58>/Selector'
   */
  (*rty_InjrM_prm_mFuInjReq) = rtu_InjSys_prm_mFuInjH1ReqCyl[rt_MIN(localAdd_c,
    5U)];

  /* SignalConversion: '<S46>/Signal Conversion5' incorporates:
   *  Selector: '<S48>/Selector'
   */
  (*rty_InjrM_prm_mFuInjReq_k) = rtu_InjSys_prm_mFuInjH2ReqCyl[(localmin_0)];

  /* SignalConversion: '<S46>/Signal Conversion6' incorporates:
   *  Selector: '<S49>/Selector'
   */
  (*rty_InjrM_prm_mFuInjReq_l) = rtu_InjSys_prm_mFuInjS1ReqCyl[(localmin_1)];

  /* SignalConversion: '<S46>/Signal Conversion7' incorporates:
   *  Selector: '<S54>/Selector'
   */
  (*rty_InjrM_prm_pCylEstimInj_l) = rtu_CylM_prm_pCylEstimInjH1Cyl[(localmin_6)];

  /* SignalConversion: '<S46>/Signal Conversion8' incorporates:
   *  Selector: '<S50>/Selector'
   */
  (*rty_InjrM_prm_mFuInjReq_n) = rtu_InjSys_prm_mFuInjS2ReqCyl[(localmin_2)];

  /* SignalConversion: '<S46>/Signal Conversion9' incorporates:
   *  Selector: '<S53>/Selector'
   */
  (*rty_InjrM_prm_pFuEstimInj_m) = rtu_FuSysM_prm_pFuEstimInjH1Cyl[(localmin_5)];
}

/* Output and update for function-call system: '<S7>/F02_SyncIn2' */
void InjrPrmMdl_F02_SyncIn2(void)
{
  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET6 */
  VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET6_m);

  /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate'
   *
   * Regarding '<S53>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET_n);

  /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate'
   *
   * Regarding '<S54>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET1 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6, InjrPrmMdl_B.VEMS_vidGET1_h);

  /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate'
   *
   * Regarding '<S55>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET4 */
  VEMS_vidGET(Eng_noInCyl, InjrPrmMdl_B.VEMS_vidGET4_h);

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET5 */
  VEMS_vidGET(Eng_noInNxtCyl, InjrPrmMdl_B.VEMS_vidGET5_d);

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET10 */
  VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET10_f);

  /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate'
   *
   * Regarding '<S58>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET7 */
  VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6, InjrPrmMdl_B.VEMS_vidGET7_h);

  /* DataTypeDuplicate Block: '<S52>/Data Type Duplicate'
   *
   * Regarding '<S52>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET11 */
  VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET11_k);

  /* DataTypeDuplicate Block: '<S48>/Data Type Duplicate'
   *
   * Regarding '<S48>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET8 */
  VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET8_k);

  /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate'
   *
   * Regarding '<S51>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET2 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET2_a);

  /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate'
   *
   * Regarding '<S56>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET9 */
  VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6,
                     InjrPrmMdl_B.VEMS_vidGET9_ne);

  /* DataTypeDuplicate Block: '<S47>/Data Type Duplicate'
   *
   * Regarding '<S47>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET3 */
  VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6, InjrPrmMdl_B.VEMS_vidGET3_n);

  /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate'
   *
   * Regarding '<S57>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET12 */
  VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET12_i);

  /* DataTypeDuplicate Block: '<S49>/Data Type Duplicate'
   *
   * Regarding '<S49>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET13 */
  VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET13_g);

  /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate'
   *
   * Regarding '<S50>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* Outputs for atomic SubSystem: '<S18>/F02_SyncIn1' */
  InjrPrmMdl_F02_SyncIn1(InjrPrmMdl_B.VEMS_vidGET5_d,
    InjrPrmMdl_B.VEMS_vidGET4_h, InjrPrmMdl_B.VEMS_vidGET9_ne,
    InjrPrmMdl_B.VEMS_vidGET11_k, InjrPrmMdl_B.VEMS_vidGET12_i,
    InjrPrmMdl_B.VEMS_vidGET13_g, InjrPrmMdl_B.VEMS_vidGET8_k,
    InjrPrmMdl_B.VEMS_vidGET7_h, InjrPrmMdl_B.VEMS_vidGET6_m,
    InjrPrmMdl_B.VEMS_vidGET_n, InjrPrmMdl_B.VEMS_vidGET1_h,
    InjrPrmMdl_B.VEMS_vidGET2_a, InjrPrmMdl_B.VEMS_vidGET3_n,
    InjrPrmMdl_B.VEMS_vidGET10_f, &InjrM_prm_pCylEstimInj[1],
    &InjrM_prm_pFuEstimInj[1], &InjrM_prm_pFuEstimInj[2],
    &InjrM_prm_pFuEstimInj[3], &InjrM_prm_pCylEstimInj[2],
    &InjrM_prm_pCylEstimInj[3], &InjrM_prm_mFuInjReq[0], &InjrM_prm_mFuInjReq[1],
    &InjrM_prm_mFuInjReq[2], &InjrM_prm_pCylEstimInj[0], &InjrM_prm_mFuInjReq[3],
    &InjrM_prm_pFuEstimInj[0]);

  /* end of Outputs for SubSystem: '<S18>/F02_SyncIn1' */
}

/* Output and update for function-call system: '<S8>/F01_InjrMdlCylCorSyncRst' */
void InjrPr_F01_InjrMdlCylCorSyncRst(void)
{
  /* Constant: '<S59>/Constant1' */
  InjrM_prm_facCorCylPFuInj[0] = 1.0F;

  /* Constant: '<S59>/Constant12' */
  InjrM_prm_facCorCylPFuInj[3] = 1.0F;

  /* Constant: '<S59>/Constant2' */
  InjrM_prm_facCorCylPFuInj[1] = 1.0F;

  /* Constant: '<S59>/Constant5' */
  InjrM_prm_facCorCylPFuInj[2] = 1.0F;

  /* Constant: '<S59>/Constant3' */
  InjrM_prm_facCorCylOfs[0] = 1.0F;

  /* Constant: '<S59>/Constant4' */
  InjrM_prm_facCorCylOfs[3] = 1.0F;

  /* Constant: '<S59>/Constant8' */
  InjrM_prm_facCorCylOfs[1] = 1.0F;

  /* Constant: '<S59>/Constant9' */
  InjrM_prm_facCorCylOfs[2] = 1.0F;

  /* Constant: '<S59>/Constant10' */
  InjrM_prm_facCorCylGainLnr[1] = 1.0F;

  /* Constant: '<S59>/Constant11' */
  InjrM_prm_facCorCylGainLnr[2] = 1.0F;

  /* Constant: '<S59>/Constant6' */
  InjrM_prm_facCorCylGainLnr[0] = 1.0F;

  /* Constant: '<S59>/Constant7' */
  InjrM_prm_facCorCylGainLnr[3] = 1.0F;
}

/*
 * Output and update for atomic system:
 *    '<S10>/F03_InjrPrmMdlFct'
 *    '<S72>/F03_InjrPrmMdlFct'
 */
void InjrPrmMdl_F03_InjrPrmMdlFct(const UInt16 rtu_InjrM_prm_pFuEstimInj[4],
  const UInt16 rtu_InjrM_prm_pCylEstimInj[4], const Float32
  rtu_InjrM_prm_facCorCylPFuInj[4], UInt16 rtu_FuSysM_tFu, UInt8
  rtu_InjSys_stTypElCmdInjrReq, const Float32 rtu_InjrM_prm_facCorCylOfs[4],
  UInt16 rtu_Ext_nEng, const UInt16 rtu_InjrM_prm_mFuInjReq[4], const
  Float32 rtu_InjrM_prm_facCorCylGainLnr[4], rtB_F03_InjrPrmMdlFct_InjrPrmMd
  *localB)
{
  Float32 localExt_nEng_InjrM_nEng_A_16_f;
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  Float32 localInjrM_prm_pDifInjr_InjrM_p[4];
  Float32 localFuSysM_tFu_InjrM_tFu_A_16_;
  Float32 localfrac_0[2];
  UInt32 localFuSysM_tFu_InjrM_tFu_A_1_g;
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  Float32 localInterpolationUsingPreloo_p[4];
  UInt32 localbpIndex_1[2];
  Float32 localInterpolationUsingPreloo_j[4];
  Float32 localInterpolationUsingPrelo_nu[4];
  Float32 localInterpolationUsingPreloo_e[4];
  Float32 locallocalAdd2_j;
  Float32 locallocalAdd;
  Float32 locallocalAdd2_j_idx;
  Float32 locallocalAdd2_idx;
  Float32 locallocalAdd2_j_idx_0;
  Float32 locallocalAdd2_idx_0;
  UInt32 locallocalInjrM_prm_pDifInjr_In;
  UInt32 locallocalInjrM_prm_pDifInjr__0;
  UInt32 locallocalInjrM_prm_pDifInjr__1;
  UInt32 locallocalInjrM_prm_pDifInjr__2;
  Float32 locallocalInterpolationUsingPre;
  Float32 locallocalInterpolationUsingP_0;
  UInt32 locallocalInjrM_prm_mFuInjReq_I;
  UInt32 locallocalInjrM_prm_mFuInjReq_0;
  UInt32 locallocalInjrM_prm_mFuInjReq_1;
  UInt8 locallocalOutDTConv_go;
  UInt16 locallocalOutDTConv_idx;
  UInt16 locallocalOutDTConv_idx_0;
  UInt16 locallocalOutDTConv_idx_1;
  UInt16 locallocalOutDTConv_idx_2;
  SInt16 localtmp;
  UInt16 locallocalOutDTConv_g;
  UInt16 localtmp_0;

  /* Lookup_n-D: '<S121>/Lookup Table (n-D)' */
  locallocalAdd = look2_iu16lfts16p9If_binlcs(rtu_InjrM_prm_pFuEstimInj[0],
    rtu_InjrM_prm_pCylEstimInj[0], (&(InjrM_pFuEstim_A[0])),
    (&(InjrM_pCylEstim_A[0])), (&(InjrM_pDsInjrCor_M[0])),
    &InjrPrmMdl_ConstP.pooled12[0], 16U);

  /* DataStoreWrite: '<S117>/Data Store Write1' */
  InjrM_prm_pDsInjrCor[0] = locallocalAdd;

  /* Product: '<S123>/Divide' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion2'
   */
  locallocalAdd2_j = (((Float32)rtu_InjrM_prm_pFuEstimInj[0]) * 781.25F) *
    rtu_InjrM_prm_facCorCylPFuInj[0];

  /* DataStoreWrite: '<S117>/Data Store Write2' */
  InjrM_prm_pFuEstimInjCor[0] = locallocalAdd2_j;

  /* DataTypeConversion: '<S122>/OutDTConv' incorporates:
   *  Constant: '<S122>/offset'
   *  Constant: '<S122>/offset1'
   *  Constant: '<S122>/one_on_slope'
   *  Product: '<S122>/Product4'
   *  Sum: '<S117>/Sum3'
   *  Sum: '<S122>/Add1'
   *  Sum: '<S122>/Add2'
   */
  locallocalAdd = ((locallocalAdd2_j - locallocalAdd) * 1.279999968E-003F) +
    0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_idx = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_idx = 0U;
    }
  } else {
    locallocalOutDTConv_idx = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S121>/Lookup Table (n-D)' */
  locallocalAdd = look2_iu16lfts16p9If_binlcs(rtu_InjrM_prm_pFuEstimInj[1],
    rtu_InjrM_prm_pCylEstimInj[1], (&(InjrM_pFuEstim_A[0])),
    (&(InjrM_pCylEstim_A[0])), (&(InjrM_pDsInjrCor_M[0])),
    &InjrPrmMdl_ConstP.pooled12[0], 16U);

  /* DataStoreWrite: '<S117>/Data Store Write1' */
  InjrM_prm_pDsInjrCor[1] = locallocalAdd;

  /* Product: '<S123>/Divide' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion2'
   */
  locallocalAdd2_j = (((Float32)rtu_InjrM_prm_pFuEstimInj[1]) * 781.25F) *
    rtu_InjrM_prm_facCorCylPFuInj[1];

  /* DataStoreWrite: '<S117>/Data Store Write2' */
  InjrM_prm_pFuEstimInjCor[1] = locallocalAdd2_j;

  /* DataTypeConversion: '<S122>/OutDTConv' incorporates:
   *  Constant: '<S122>/offset'
   *  Constant: '<S122>/offset1'
   *  Constant: '<S122>/one_on_slope'
   *  Product: '<S122>/Product4'
   *  Sum: '<S117>/Sum3'
   *  Sum: '<S122>/Add1'
   *  Sum: '<S122>/Add2'
   */
  locallocalAdd = ((locallocalAdd2_j - locallocalAdd) * 1.279999968E-003F) +
    0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_idx_0 = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_idx_0 = 0U;
    }
  } else {
    locallocalOutDTConv_idx_0 = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S121>/Lookup Table (n-D)' */
  locallocalAdd = look2_iu16lfts16p9If_binlcs(rtu_InjrM_prm_pFuEstimInj[2],
    rtu_InjrM_prm_pCylEstimInj[2], (&(InjrM_pFuEstim_A[0])),
    (&(InjrM_pCylEstim_A[0])), (&(InjrM_pDsInjrCor_M[0])),
    &InjrPrmMdl_ConstP.pooled12[0], 16U);

  /* DataStoreWrite: '<S117>/Data Store Write1' */
  InjrM_prm_pDsInjrCor[2] = locallocalAdd;

  /* Product: '<S123>/Divide' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion2'
   */
  locallocalAdd2_j = (((Float32)rtu_InjrM_prm_pFuEstimInj[2]) * 781.25F) *
    rtu_InjrM_prm_facCorCylPFuInj[2];

  /* DataStoreWrite: '<S117>/Data Store Write2' */
  InjrM_prm_pFuEstimInjCor[2] = locallocalAdd2_j;

  /* DataTypeConversion: '<S122>/OutDTConv' incorporates:
   *  Constant: '<S122>/offset'
   *  Constant: '<S122>/offset1'
   *  Constant: '<S122>/one_on_slope'
   *  Product: '<S122>/Product4'
   *  Sum: '<S117>/Sum3'
   *  Sum: '<S122>/Add1'
   *  Sum: '<S122>/Add2'
   */
  locallocalAdd = ((locallocalAdd2_j - locallocalAdd) * 1.279999968E-003F) +
    0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_idx_1 = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_idx_1 = 0U;
    }
  } else {
    locallocalOutDTConv_idx_1 = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S121>/Lookup Table (n-D)' */
  locallocalAdd = look2_iu16lfts16p9If_binlcs(rtu_InjrM_prm_pFuEstimInj[3],
    rtu_InjrM_prm_pCylEstimInj[3], (&(InjrM_pFuEstim_A[0])),
    (&(InjrM_pCylEstim_A[0])), (&(InjrM_pDsInjrCor_M[0])),
    &InjrPrmMdl_ConstP.pooled12[0], 16U);

  /* DataStoreWrite: '<S117>/Data Store Write1' */
  InjrM_prm_pDsInjrCor[3] = locallocalAdd;

  /* Product: '<S123>/Divide' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion2'
   */
  locallocalAdd2_j = (((Float32)rtu_InjrM_prm_pFuEstimInj[3]) * 781.25F) *
    rtu_InjrM_prm_facCorCylPFuInj[3];

  /* DataStoreWrite: '<S117>/Data Store Write2' */
  InjrM_prm_pFuEstimInjCor[3] = locallocalAdd2_j;

  /* DataTypeConversion: '<S122>/OutDTConv' incorporates:
   *  Constant: '<S122>/offset'
   *  Constant: '<S122>/offset1'
   *  Constant: '<S122>/one_on_slope'
   *  Product: '<S122>/Product4'
   *  Sum: '<S117>/Sum3'
   *  Sum: '<S122>/Add1'
   *  Sum: '<S122>/Add2'
   */
  locallocalAdd = ((locallocalAdd2_j - locallocalAdd) * 1.279999968E-003F) +
    0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_idx_2 = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_idx_2 = 0U;
    }
  } else {
    locallocalOutDTConv_idx_2 = MAX_uint16_T;
  }

  /* PreLookup: '<S126>/Prelookup' */
  locallocalInjrM_prm_pDifInjr_In = plook_u32u16f_binc(locallocalOutDTConv_idx,
    (&(InjrM_pDifInjr_A[0])), 15U, &localInjrM_prm_pDifInjr_InjrM_p[0]);
  locallocalInjrM_prm_pDifInjr__0 = plook_u32u16f_binc(locallocalOutDTConv_idx_0,
    (&(InjrM_pDifInjr_A[0])), 15U, &localInjrM_prm_pDifInjr_InjrM_p[1]);
  locallocalInjrM_prm_pDifInjr__1 = plook_u32u16f_binc(locallocalOutDTConv_idx_1,
    (&(InjrM_pDifInjr_A[0])), 15U, &localInjrM_prm_pDifInjr_InjrM_p[2]);
  locallocalInjrM_prm_pDifInjr__2 = plook_u32u16f_binc(locallocalOutDTConv_idx_2,
    (&(InjrM_pDifInjr_A[0])), 15U, &localInjrM_prm_pDifInjr_InjrM_p[3]);

  /* PreLookup: '<S132>/Prelookup' */
  localFuSysM_tFu_InjrM_tFu_A_1_g = plook_u32u16f_binc(rtu_FuSysM_tFu,
    (&(InjrM_tFu_A[0])), 15U, &localFuSysM_tFu_InjrM_tFu_A_16_);

  /* Lookup_n-D: '<S119>/Lookup Table (n-D)' */
  localExt_nEng_InjrM_nEng_A_16_f = look1_iu8lfIf_binlcs
    (rtu_InjSys_stTypElCmdInjrReq, (&(InjrM_stTypElCmdInjrReq_A[0])),
     (&(InjrM_IdxInjrMdlInj_T[0])), 3U);

  /* Sum: '<S120>/Add1' incorporates:
   *  Constant: '<S120>/offset'
   */
  locallocalAdd2_j = localExt_nEng_InjrM_nEng_A_16_f;

  /* Sum: '<S120>/Add2' incorporates:
   *  Constant: '<S120>/offset1'
   *  Constant: '<S120>/one_on_slope'
   *  Product: '<S120>/Product4'
   */
  localExt_nEng_InjrM_nEng_A_16_f = locallocalAdd2_j + 0.5F;

  /* DataTypeConversion: '<S120>/OutDTConv' */
  locallocalAdd = localExt_nEng_InjrM_nEng_A_16_f;
  if (locallocalAdd < 256.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_go = (UInt8)locallocalAdd;
    } else {
      locallocalOutDTConv_go = 0U;
    }
  } else {
    locallocalOutDTConv_go = MAX_uint8_T;
  }

  /* SwitchCase: '<S124>/Switch Case' incorporates:
   *  ActionPort: '<S127>/Action Port'
   *  ActionPort: '<S128>/Action Port'
   *  ActionPort: '<S129>/Action Port'
   *  ActionPort: '<S130>/Action Port'
   *  ActionPort: '<S131>/Action Port'
   *  SubSystem: '<S124>/F01_tiInjOfs1'
   *  SubSystem: '<S124>/F02_tiInjOfs2'
   *  SubSystem: '<S124>/F03_tiInjOfs3'
   *  SubSystem: '<S124>/F04_tiInjOfs4'
   *  SubSystem: '<S124>/F09_tiInjOfs9'
   */
  switch (locallocalOutDTConv_go) {
   case 1:
    /* Interpolation_n-D: '<S135>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localFuSysM_tFu_InjrM_tFu_A_16_;
    localfrac_0[1] = locallocalAdd2_j;
    localbpIndex_0[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr_In;
    locallocalAdd = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf1_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__0;
    locallocalInterpolationUsingPre = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf1_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__1;
    locallocalInterpolationUsingP_0 = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf1_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__2;
    locallocalAdd2_j = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf1_M[0])), 16U);
    break;

   case 2:
    /* Interpolation_n-D: '<S136>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localFuSysM_tFu_InjrM_tFu_A_16_;
    localfrac_0[1] = locallocalAdd2_j;
    localbpIndex_0[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr_In;
    locallocalAdd = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf2_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__0;
    locallocalInterpolationUsingPre = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf2_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__1;
    locallocalInterpolationUsingP_0 = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf2_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__2;
    locallocalAdd2_j = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf2_M[0])), 16U);
    break;

   case 3:
    /* Interpolation_n-D: '<S137>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localFuSysM_tFu_InjrM_tFu_A_16_;
    localfrac_0[1] = locallocalAdd2_j;
    localbpIndex_0[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr_In;
    locallocalAdd = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf3_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__0;
    locallocalInterpolationUsingPre = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf3_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__1;
    locallocalInterpolationUsingP_0 = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf3_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__2;
    locallocalAdd2_j = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf3_M[0])), 16U);
    break;

   case 4:
    /* Interpolation_n-D: '<S138>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localFuSysM_tFu_InjrM_tFu_A_16_;
    localfrac_0[1] = locallocalAdd2_j;
    localbpIndex_0[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr_In;
    locallocalAdd = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf4_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__0;
    locallocalInterpolationUsingPre = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf4_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__1;
    locallocalInterpolationUsingP_0 = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjrM_tiInjOfsRawProf4_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_0[0] = locallocalAdd2_j;
    localbpIndex_0[0] = locallocalInjrM_prm_pDifInjr__2;
    locallocalAdd2_j = intrp2d_is16n19ff_u32f_l_ns(localbpIndex_0, localfrac_0,
      (&(InjrM_tiInjOfsRawProf4_M[0])), 16U);
    break;

   default:
    /* SignalConversion: '<S131>/Signal Conversion16' incorporates:
     *  Constant: '<S131>/Constant'
     */
    locallocalAdd = 0.0F;
    locallocalInterpolationUsingPre = 0.0F;
    locallocalInterpolationUsingP_0 = 0.0F;
    locallocalAdd2_j = 0.0F;
    break;
  }

  /* DataStoreWrite: '<S124>/Data Store Write' */
  InjrM_prm_tiInjOfsCal[0] = locallocalAdd;

  /* Product: '<S133>/Product4' incorporates:
   *  Constant: '<S133>/offset'
   *  Constant: '<S133>/one_on_slope'
   *  Product: '<S134>/Divide'
   *  Sum: '<S133>/Add1'
   */
  locallocalAdd = (locallocalAdd * rtu_InjrM_prm_facCorCylOfs[0]) * 312500.0F;

  /* Switch: '<S133>/Switch1' incorporates:
   *  Constant: '<S133>/offset2'
   *  Constant: '<S133>/offset3'
   *  Constant: '<S133>/offset4'
   *  RelationalOperator: '<S133>/Relational Operator'
   *  Sum: '<S133>/Add3'
   *  Sum: '<S133>/Add4'
   */
  if (locallocalAdd >= 0.0F) {
    locallocalAdd += 0.5F;
  } else {
    locallocalAdd -= 0.5F;
  }

  /* DataTypeConversion: '<S133>/OutDTConv' */
  if (locallocalAdd < 32768.0F) {
    if (locallocalAdd >= -32768.0F) {
      localtmp = (SInt16)locallocalAdd;
    } else {
      localtmp = MIN_int16_T;
    }
  } else {
    localtmp = MAX_int16_T;
  }

  localB->OutDTConv[0] = localtmp;

  /* DataStoreWrite: '<S124>/Data Store Write' */
  InjrM_prm_tiInjOfsCal[1] = locallocalInterpolationUsingPre;

  /* Product: '<S133>/Product4' incorporates:
   *  Constant: '<S133>/offset'
   *  Constant: '<S133>/one_on_slope'
   *  Product: '<S134>/Divide'
   *  Sum: '<S133>/Add1'
   */
  locallocalAdd = (locallocalInterpolationUsingPre * rtu_InjrM_prm_facCorCylOfs
                   [1]) * 312500.0F;

  /* Switch: '<S133>/Switch1' incorporates:
   *  Constant: '<S133>/offset2'
   *  Constant: '<S133>/offset3'
   *  Constant: '<S133>/offset4'
   *  RelationalOperator: '<S133>/Relational Operator'
   *  Sum: '<S133>/Add3'
   *  Sum: '<S133>/Add4'
   */
  if (locallocalAdd >= 0.0F) {
    locallocalAdd += 0.5F;
  } else {
    locallocalAdd -= 0.5F;
  }

  /* DataTypeConversion: '<S133>/OutDTConv' */
  if (locallocalAdd < 32768.0F) {
    if (locallocalAdd >= -32768.0F) {
      localtmp = (SInt16)locallocalAdd;
    } else {
      localtmp = MIN_int16_T;
    }
  } else {
    localtmp = MAX_int16_T;
  }

  localB->OutDTConv[1] = localtmp;

  /* DataStoreWrite: '<S124>/Data Store Write' */
  InjrM_prm_tiInjOfsCal[2] = locallocalInterpolationUsingP_0;

  /* Product: '<S133>/Product4' incorporates:
   *  Constant: '<S133>/offset'
   *  Constant: '<S133>/one_on_slope'
   *  Product: '<S134>/Divide'
   *  Sum: '<S133>/Add1'
   */
  locallocalAdd = (locallocalInterpolationUsingP_0 * rtu_InjrM_prm_facCorCylOfs
                   [2]) * 312500.0F;

  /* Switch: '<S133>/Switch1' incorporates:
   *  Constant: '<S133>/offset2'
   *  Constant: '<S133>/offset3'
   *  Constant: '<S133>/offset4'
   *  RelationalOperator: '<S133>/Relational Operator'
   *  Sum: '<S133>/Add3'
   *  Sum: '<S133>/Add4'
   */
  if (locallocalAdd >= 0.0F) {
    locallocalAdd += 0.5F;
  } else {
    locallocalAdd -= 0.5F;
  }

  /* DataTypeConversion: '<S133>/OutDTConv' */
  if (locallocalAdd < 32768.0F) {
    if (locallocalAdd >= -32768.0F) {
      localtmp = (SInt16)locallocalAdd;
    } else {
      localtmp = MIN_int16_T;
    }
  } else {
    localtmp = MAX_int16_T;
  }

  localB->OutDTConv[2] = localtmp;

  /* DataStoreWrite: '<S124>/Data Store Write' */
  InjrM_prm_tiInjOfsCal[3] = locallocalAdd2_j;

  /* Product: '<S133>/Product4' incorporates:
   *  Constant: '<S133>/offset'
   *  Constant: '<S133>/one_on_slope'
   *  Product: '<S134>/Divide'
   *  Sum: '<S133>/Add1'
   */
  locallocalAdd = (locallocalAdd2_j * rtu_InjrM_prm_facCorCylOfs[3]) * 312500.0F;

  /* Switch: '<S133>/Switch1' incorporates:
   *  Constant: '<S133>/offset2'
   *  Constant: '<S133>/offset3'
   *  Constant: '<S133>/offset4'
   *  RelationalOperator: '<S133>/Relational Operator'
   *  Sum: '<S133>/Add3'
   *  Sum: '<S133>/Add4'
   */
  if (locallocalAdd >= 0.0F) {
    locallocalAdd += 0.5F;
  } else {
    locallocalAdd -= 0.5F;
  }

  /* DataTypeConversion: '<S133>/OutDTConv' */
  if (locallocalAdd < 32768.0F) {
    if (locallocalAdd >= -32768.0F) {
      localtmp = (SInt16)locallocalAdd;
    } else {
      localtmp = MIN_int16_T;
    }
  } else {
    localtmp = MAX_int16_T;
  }

  localB->OutDTConv[3] = localtmp;

  /* PreLookup: '<S145>/Prelookup' */
  localFuSysM_tFu_InjrM_tFu_A_1_g = plook_u32u16f_binc(rtu_Ext_nEng,
    (&(InjrM_nEng_A[0])), 15U, &localExt_nEng_InjrM_nEng_A_16_f);

  /* Interpolation_n-D: '<S144>/Interpolation Using Prelookup3' */
  locallocalAdd2_j = localExt_nEng_InjrM_nEng_A_16_f;
  localfrac[1] = locallocalAdd2_j;
  localbpIndex[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
  locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
  localfrac[0] = locallocalAdd2_j;
  localbpIndex[0] = locallocalInjrM_prm_pDifInjr_In;
  locallocalInterpolationUsingPre = intrp2d_iu16n6ff_u32f_l_ns(localbpIndex,
    localfrac, (&(InjrM_facGainLnrRawProf_M[0])), 16U);
  locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
  localfrac[0] = locallocalAdd2_j;
  localbpIndex[0] = locallocalInjrM_prm_pDifInjr__0;
  locallocalInterpolationUsingP_0 = intrp2d_iu16n6ff_u32f_l_ns(localbpIndex,
    localfrac, (&(InjrM_facGainLnrRawProf_M[0])), 16U);
  locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
  localfrac[0] = locallocalAdd2_j;
  localbpIndex[0] = locallocalInjrM_prm_pDifInjr__1;
  locallocalAdd2_j_idx = intrp2d_iu16n6ff_u32f_l_ns(localbpIndex, localfrac,
    (&(InjrM_facGainLnrRawProf_M[0])), 16U);
  locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
  localfrac[0] = locallocalAdd2_j;
  localbpIndex[0] = locallocalInjrM_prm_pDifInjr__2;
  locallocalAdd2_j_idx_0 = intrp2d_iu16n6ff_u32f_l_ns(localbpIndex, localfrac, (
    &(InjrM_facGainLnrRawProf_M[0])), 16U);

  /* DataStoreWrite: '<S125>/Data Store Write' */
  InjrM_prm_facGainLnrInjCal[0] = locallocalInterpolationUsingPre;
  InjrM_prm_facGainLnrInjCal[1] = locallocalInterpolationUsingP_0;
  InjrM_prm_facGainLnrInjCal[2] = locallocalAdd2_j_idx;
  InjrM_prm_facGainLnrInjCal[3] = locallocalAdd2_j_idx_0;

  /* SwitchCase: '<S125>/Switch Case1' incorporates:
   *  ActionPort: '<S139>/Action Port'
   *  ActionPort: '<S140>/Action Port'
   *  ActionPort: '<S141>/Action Port'
   *  ActionPort: '<S142>/Action Port'
   *  ActionPort: '<S143>/Action Port'
   *  SubSystem: '<S125>/F10_facCorGainLnr1'
   *  SubSystem: '<S125>/F11_facCorGainLnr2'
   *  SubSystem: '<S125>/F12_facCorGainLnr3'
   *  SubSystem: '<S125>/F13_facCorGainLnr4'
   *  SubSystem: '<S125>/F18_facCorGainLnr9'
   */
  switch (locallocalOutDTConv_go) {
   case 1:
    /* PreLookup: '<S150>/Prelookup' */
    localFuSysM_tFu_InjrM_tFu_A_1_g = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[0], (&(InjrM_mFuReq1_A[0])), 15U,
       &localInterpolationUsingPreloo_p[0]);
    locallocalInjrM_prm_mFuInjReq_I = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[1], (&(InjrM_mFuReq1_A[0])), 15U,
       &localInterpolationUsingPreloo_p[1]);
    locallocalInjrM_prm_mFuInjReq_0 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[2], (&(InjrM_mFuReq1_A[0])), 15U,
       &localInterpolationUsingPreloo_p[2]);
    locallocalInjrM_prm_mFuInjReq_1 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[3], (&(InjrM_mFuReq1_A[0])), 15U,
       &localInterpolationUsingPreloo_p[3]);

    /* Interpolation_n-D: '<S149>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_p[0];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr_In;
    localbpIndex_1[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    localInterpolationUsingPreloo_p[0] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf1_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_p[1];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__0;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_I;
    localInterpolationUsingPreloo_p[1] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf1_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_p[2];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__1;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_0;
    localInterpolationUsingPreloo_p[2] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf1_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_p[3];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__2;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_1;
    localInterpolationUsingPreloo_p[3] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf1_M[0])), 16U);

    /* SignalConversion: '<S139>/Signal Conversion16' */
    locallocalAdd = localInterpolationUsingPreloo_p[0];
    locallocalAdd2_j = localInterpolationUsingPreloo_p[1];
    locallocalAdd2_idx = localInterpolationUsingPreloo_p[2];
    locallocalAdd2_idx_0 = localInterpolationUsingPreloo_p[3];
    break;

   case 2:
    /* PreLookup: '<S152>/Prelookup' */
    localFuSysM_tFu_InjrM_tFu_A_1_g = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[0], (&(InjrM_mFuReq2_A[0])), 15U,
       &localInterpolationUsingPreloo_j[0]);
    locallocalInjrM_prm_mFuInjReq_I = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[1], (&(InjrM_mFuReq2_A[0])), 15U,
       &localInterpolationUsingPreloo_j[1]);
    locallocalInjrM_prm_mFuInjReq_0 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[2], (&(InjrM_mFuReq2_A[0])), 15U,
       &localInterpolationUsingPreloo_j[2]);
    locallocalInjrM_prm_mFuInjReq_1 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[3], (&(InjrM_mFuReq2_A[0])), 15U,
       &localInterpolationUsingPreloo_j[3]);

    /* Interpolation_n-D: '<S151>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_j[0];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr_In;
    localbpIndex_1[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    localInterpolationUsingPreloo_j[0] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf2_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_j[1];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__0;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_I;
    localInterpolationUsingPreloo_j[1] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf2_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_j[2];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__1;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_0;
    localInterpolationUsingPreloo_j[2] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf2_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_j[3];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__2;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_1;
    localInterpolationUsingPreloo_j[3] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf2_M[0])), 16U);

    /* SignalConversion: '<S140>/Signal Conversion16' */
    locallocalAdd = localInterpolationUsingPreloo_j[0];
    locallocalAdd2_j = localInterpolationUsingPreloo_j[1];
    locallocalAdd2_idx = localInterpolationUsingPreloo_j[2];
    locallocalAdd2_idx_0 = localInterpolationUsingPreloo_j[3];
    break;

   case 3:
    /* PreLookup: '<S154>/Prelookup' */
    localFuSysM_tFu_InjrM_tFu_A_1_g = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[0], (&(InjrM_mFuReq3_A[0])), 15U,
       &localInterpolationUsingPrelo_nu[0]);
    locallocalInjrM_prm_mFuInjReq_I = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[1], (&(InjrM_mFuReq3_A[0])), 15U,
       &localInterpolationUsingPrelo_nu[1]);
    locallocalInjrM_prm_mFuInjReq_0 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[2], (&(InjrM_mFuReq3_A[0])), 15U,
       &localInterpolationUsingPrelo_nu[2]);
    locallocalInjrM_prm_mFuInjReq_1 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[3], (&(InjrM_mFuReq3_A[0])), 15U,
       &localInterpolationUsingPrelo_nu[3]);

    /* Interpolation_n-D: '<S153>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPrelo_nu[0];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr_In;
    localbpIndex_1[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    localInterpolationUsingPrelo_nu[0] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf3_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPrelo_nu[1];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__0;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_I;
    localInterpolationUsingPrelo_nu[1] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf3_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPrelo_nu[2];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__1;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_0;
    localInterpolationUsingPrelo_nu[2] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf3_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPrelo_nu[3];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__2;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_1;
    localInterpolationUsingPrelo_nu[3] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf3_M[0])), 16U);

    /* SignalConversion: '<S141>/Signal Conversion16' */
    locallocalAdd = localInterpolationUsingPrelo_nu[0];
    locallocalAdd2_j = localInterpolationUsingPrelo_nu[1];
    locallocalAdd2_idx = localInterpolationUsingPrelo_nu[2];
    locallocalAdd2_idx_0 = localInterpolationUsingPrelo_nu[3];
    break;

   case 4:
    /* PreLookup: '<S156>/Prelookup' */
    localFuSysM_tFu_InjrM_tFu_A_1_g = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[0], (&(InjrM_mFuReq4_A[0])), 15U,
       &localInterpolationUsingPreloo_e[0]);
    locallocalInjrM_prm_mFuInjReq_I = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[1], (&(InjrM_mFuReq4_A[0])), 15U,
       &localInterpolationUsingPreloo_e[1]);
    locallocalInjrM_prm_mFuInjReq_0 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[2], (&(InjrM_mFuReq4_A[0])), 15U,
       &localInterpolationUsingPreloo_e[2]);
    locallocalInjrM_prm_mFuInjReq_1 = plook_u32u16f_binc
      (rtu_InjrM_prm_mFuInjReq[3], (&(InjrM_mFuReq4_A[0])), 15U,
       &localInterpolationUsingPreloo_e[3]);

    /* Interpolation_n-D: '<S155>/Interpolation Using Prelookup3' */
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[0];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_e[0];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr_In;
    localbpIndex_1[1] = localFuSysM_tFu_InjrM_tFu_A_1_g;
    localInterpolationUsingPreloo_e[0] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf4_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[1];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_e[1];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__0;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_I;
    localInterpolationUsingPreloo_e[1] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf4_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[2];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_e[2];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__1;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_0;
    localInterpolationUsingPreloo_e[2] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf4_M[0])), 16U);
    locallocalAdd2_j = localInjrM_prm_pDifInjr_InjrM_p[3];
    localfrac_1[0] = locallocalAdd2_j;
    locallocalAdd2_j = localInterpolationUsingPreloo_e[3];
    localfrac_1[1] = locallocalAdd2_j;
    localbpIndex_1[0] = locallocalInjrM_prm_pDifInjr__2;
    localbpIndex_1[1] = locallocalInjrM_prm_mFuInjReq_1;
    localInterpolationUsingPreloo_e[3] = intrp2d_iu16n15ff_u32f_l_ns
      (localbpIndex_1, localfrac_1, (&(InjrM_facCorGainLnrProf4_M[0])), 16U);

    /* SignalConversion: '<S142>/Signal Conversion16' */
    locallocalAdd = localInterpolationUsingPreloo_e[0];
    locallocalAdd2_j = localInterpolationUsingPreloo_e[1];
    locallocalAdd2_idx = localInterpolationUsingPreloo_e[2];
    locallocalAdd2_idx_0 = localInterpolationUsingPreloo_e[3];
    break;

   default:
    /* SignalConversion: '<S143>/Signal Conversion16' incorporates:
     *  Constant: '<S143>/Constant'
     */
    locallocalAdd = 1.0F;
    locallocalAdd2_j = 1.0F;
    locallocalAdd2_idx = 1.0F;
    locallocalAdd2_idx_0 = 1.0F;
    break;
  }

  /* DataTypeConversion: '<S147>/OutDTConv' incorporates:
   *  Constant: '<S147>/offset'
   *  Constant: '<S147>/offset1'
   *  Constant: '<S147>/one_on_slope'
   *  Product: '<S147>/Product4'
   *  Sum: '<S147>/Add1'
   *  Sum: '<S147>/Add2'
   */
  locallocalAdd = (32768.0F * locallocalAdd) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_g = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_g = 0U;
    }
  } else {
    locallocalOutDTConv_g = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S125>/Data Store Write1' */
  InjrM_prm_facCorGainLnrCal[0] = locallocalOutDTConv_g;

  /* DataTypeConversion: '<S146>/OutDTConv' incorporates:
   *  Constant: '<S146>/offset'
   *  Constant: '<S146>/offset1'
   *  Constant: '<S146>/one_on_slope'
   *  Product: '<S146>/Product4'
   *  Product: '<S148>/Divide'
   *  Sum: '<S146>/Add1'
   *  Sum: '<S146>/Add2'
   */
  locallocalAdd = ((locallocalInterpolationUsingPre *
                    rtu_InjrM_prm_facCorCylGainLnr[0]) * 64.0F) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      localtmp_0 = (UInt16)locallocalAdd;
    } else {
      localtmp_0 = 0U;
    }
  } else {
    localtmp_0 = MAX_uint16_T;
  }

  localB->OutDTConv_d[0] = localtmp_0;

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S125>/Constant1'
   *  RelationalOperator: '<S125>/Relational Operator'
   */
  if (rtu_InjrM_prm_mFuInjReq[0] > 0) {
    localB->Switch[0] = locallocalOutDTConv_g;
  } else {
    localB->Switch[0] = 32768U;
  }

  /* SignalConversion: '<S115>/Signal Conversion' */
  localB->SignalConversion[0] = locallocalOutDTConv_idx;

  /* DataTypeConversion: '<S147>/OutDTConv' incorporates:
   *  Constant: '<S147>/offset'
   *  Constant: '<S147>/offset1'
   *  Constant: '<S147>/one_on_slope'
   *  Product: '<S147>/Product4'
   *  Sum: '<S147>/Add1'
   *  Sum: '<S147>/Add2'
   */
  locallocalAdd = (32768.0F * locallocalAdd2_j) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_idx = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_idx = 0U;
    }
  } else {
    locallocalOutDTConv_idx = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S125>/Data Store Write1' */
  InjrM_prm_facCorGainLnrCal[1] = locallocalOutDTConv_idx;

  /* DataTypeConversion: '<S146>/OutDTConv' incorporates:
   *  Constant: '<S146>/offset'
   *  Constant: '<S146>/offset1'
   *  Constant: '<S146>/one_on_slope'
   *  Product: '<S146>/Product4'
   *  Product: '<S148>/Divide'
   *  Sum: '<S146>/Add1'
   *  Sum: '<S146>/Add2'
   */
  locallocalAdd = ((locallocalInterpolationUsingP_0 *
                    rtu_InjrM_prm_facCorCylGainLnr[1]) * 64.0F) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_g = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_g = 0U;
    }
  } else {
    locallocalOutDTConv_g = MAX_uint16_T;
  }

  localB->OutDTConv_d[1] = locallocalOutDTConv_g;

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S125>/Constant1'
   *  RelationalOperator: '<S125>/Relational Operator'
   */
  if (rtu_InjrM_prm_mFuInjReq[1] > 0) {
    localB->Switch[1] = locallocalOutDTConv_idx;
  } else {
    localB->Switch[1] = 32768U;
  }

  /* SignalConversion: '<S115>/Signal Conversion' */
  localB->SignalConversion[1] = locallocalOutDTConv_idx_0;

  /* DataTypeConversion: '<S147>/OutDTConv' incorporates:
   *  Constant: '<S147>/offset'
   *  Constant: '<S147>/offset1'
   *  Constant: '<S147>/one_on_slope'
   *  Product: '<S147>/Product4'
   *  Sum: '<S147>/Add1'
   *  Sum: '<S147>/Add2'
   */
  locallocalAdd = (32768.0F * locallocalAdd2_idx) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_idx = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_idx = 0U;
    }
  } else {
    locallocalOutDTConv_idx = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S125>/Data Store Write1' */
  InjrM_prm_facCorGainLnrCal[2] = locallocalOutDTConv_idx;

  /* DataTypeConversion: '<S146>/OutDTConv' incorporates:
   *  Constant: '<S146>/offset'
   *  Constant: '<S146>/offset1'
   *  Constant: '<S146>/one_on_slope'
   *  Product: '<S146>/Product4'
   *  Product: '<S148>/Divide'
   *  Sum: '<S146>/Add1'
   *  Sum: '<S146>/Add2'
   */
  locallocalAdd = ((locallocalAdd2_j_idx * rtu_InjrM_prm_facCorCylGainLnr[2]) *
                   64.0F) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_g = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_g = 0U;
    }
  } else {
    locallocalOutDTConv_g = MAX_uint16_T;
  }

  localB->OutDTConv_d[2] = locallocalOutDTConv_g;

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S125>/Constant1'
   *  RelationalOperator: '<S125>/Relational Operator'
   */
  if (rtu_InjrM_prm_mFuInjReq[2] > 0) {
    localB->Switch[2] = locallocalOutDTConv_idx;
  } else {
    localB->Switch[2] = 32768U;
  }

  /* SignalConversion: '<S115>/Signal Conversion' */
  localB->SignalConversion[2] = locallocalOutDTConv_idx_1;

  /* DataTypeConversion: '<S147>/OutDTConv' incorporates:
   *  Constant: '<S147>/offset'
   *  Constant: '<S147>/offset1'
   *  Constant: '<S147>/one_on_slope'
   *  Product: '<S147>/Product4'
   *  Sum: '<S147>/Add1'
   *  Sum: '<S147>/Add2'
   */
  locallocalAdd = (32768.0F * locallocalAdd2_idx_0) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_idx = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_idx = 0U;
    }
  } else {
    locallocalOutDTConv_idx = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S125>/Data Store Write1' */
  InjrM_prm_facCorGainLnrCal[3] = locallocalOutDTConv_idx;

  /* DataTypeConversion: '<S146>/OutDTConv' incorporates:
   *  Constant: '<S146>/offset'
   *  Constant: '<S146>/offset1'
   *  Constant: '<S146>/one_on_slope'
   *  Product: '<S146>/Product4'
   *  Product: '<S148>/Divide'
   *  Sum: '<S146>/Add1'
   *  Sum: '<S146>/Add2'
   */
  locallocalAdd = ((locallocalAdd2_j_idx_0 * rtu_InjrM_prm_facCorCylGainLnr[3]) *
                   64.0F) + 0.5F;
  if (locallocalAdd < 65536.0F) {
    if (locallocalAdd >= 0.0F) {
      locallocalOutDTConv_g = (UInt16)locallocalAdd;
    } else {
      locallocalOutDTConv_g = 0U;
    }
  } else {
    locallocalOutDTConv_g = MAX_uint16_T;
  }

  localB->OutDTConv_d[3] = locallocalOutDTConv_g;

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S125>/Constant1'
   *  RelationalOperator: '<S125>/Relational Operator'
   */
  if (rtu_InjrM_prm_mFuInjReq[3] > 0) {
    localB->Switch[3] = locallocalOutDTConv_idx;
  } else {
    localB->Switch[3] = 32768U;
  }

  /* SignalConversion: '<S115>/Signal Conversion' */
  localB->SignalConversion[3] = locallocalOutDTConv_idx_2;

  /* SignalConversion: '<S115>/Signal Conversion1' */
  localB->SignalConversion1 = locallocalOutDTConv_go;
}

/* Output and update for function-call system: '<S1>/F03_InjrPrmMdlFct1' */
void InjrPrmMdl_F03_InjrPrmMdlFct1(void)
{
  /* S-Function "vems_vidGET" Block: <S10>/VEMS_vidGET2 */
  VEMS_vidGET(InjSys_stTypElCmdInjrReq, InjrPrmMdl_B.VEMS_vidGET2_d);

  /* S-Function "vems_vidGET" Block: <S10>/VEMS_vidGET */
  VEMS_vidGET(Ext_nEng, InjrPrmMdl_B.VEMS_vidGET_k);

  /* S-Function "vems_vidGET" Block: <S10>/VEMS_vidGET1 */
  VEMS_vidGET(FuSysM_tFu, InjrPrmMdl_B.VEMS_vidGET1_e);

  /* Outputs for atomic SubSystem: '<S10>/F03_InjrPrmMdlFct' */
  InjrPrmMdl_F03_InjrPrmMdlFct((&(InjrM_prm_pFuEstimInj[0])),
    (&(InjrM_prm_pCylEstimInj[0])), (&(InjrM_prm_facCorCylPFuInj[0])),
    InjrPrmMdl_B.VEMS_vidGET1_e, InjrPrmMdl_B.VEMS_vidGET2_d,
    (&(InjrM_prm_facCorCylOfs[0])), InjrPrmMdl_B.VEMS_vidGET_k,
    (&(InjrM_prm_mFuInjReq[0])), (&(InjrM_prm_facCorCylGainLnr[0])),
    &InjrPrmMdl_B.F03_InjrPrmMdlFct_f);

  /* end of Outputs for SubSystem: '<S10>/F03_InjrPrmMdlFct' */

  /* S-Function "vems_vidSET" Block: <S10>/VEMS_vidSET */
  VEMS_vidSET(InjrM_IdxInjrMdlInj,
              InjrPrmMdl_B.F03_InjrPrmMdlFct_f.SignalConversion1);

  /* S-Function "vems_vidSET" Block: <S10>/VEMS_vidSET1 */
  VEMS_vidSET1DArray(InjrM_prm_facCorGainLnr, 4,
                     InjrPrmMdl_B.F03_InjrPrmMdlFct_f.Switch);

  /* S-Function "vems_vidSET" Block: <S10>/VEMS_vidSET2 */
  VEMS_vidSET1DArray(InjrM_prm_facGainLnrlnjRaw, 4,
                     InjrPrmMdl_B.F03_InjrPrmMdlFct_f.OutDTConv_d);

  /* S-Function "vems_vidSET" Block: <S10>/VEMS_vidSET3 */
  VEMS_vidSET1DArray(InjrM_prm_pDifInjr, 4,
                     InjrPrmMdl_B.F03_InjrPrmMdlFct_f.SignalConversion);

  /* S-Function "vems_vidSET" Block: <S10>/VEMS_vidSET4 */
  VEMS_vidSET1DArray(InjrM_prm_tiInjOfsRaw, 4,
                     InjrPrmMdl_B.F03_InjrPrmMdlFct_f.OutDTConv);
}

/* Start for exported function: InjrM_EveRst_InjrPrmMdl */
void InjrM_EveRst_InjrPrmMdl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjrPrmMdl_fc_demux5'
   */

  /* Start for S-Function (fcncallgen): '<S15>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S1>/F03_InjrPrmMdlFct1'
   *  Start for SubSystem: '<S7>/F02_SyncIn2'
   *  Start for SubSystem: '<S8>/F01_InjrMdlCylCorSyncRst'
   */
}

/* Output and update for exported function: InjrM_EveRst_InjrPrmMdl */
void InjrM_EveRst_InjrPrmMdl(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrPrmMdl_fc_demux5'
   */

  /* S-Function (fcncallgen): '<S15>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/F03_InjrPrmMdlFct1'
   *  SubSystem: '<S7>/F02_SyncIn2'
   *  SubSystem: '<S8>/F01_InjrMdlCylCorSyncRst'
   */
  InjrPrmMdl_F02_SyncIn2();
  InjrPr_F01_InjrMdlCylCorSyncRst();
  InjrPrmMdl_F03_InjrPrmMdlFct1();
}

/* Output and update for function-call system: '<S7>/F01_SyncIn' */
void InjrPrmMdl_F01_SyncIn(void)
{
  UInt32 localAdd;
  UInt32 localAdd_e;
  UInt32 localAdd_k;
  UInt16 localSelector;
  UInt16 localSelector_o;
  UInt16 localSelector_d;
  UInt16 localSelector_m;
  UInt16 localSelector_f;
  UInt16 localSelector_p;
  UInt16 localSelector_i;
  UInt16 localSelector_f0;
  UInt16 localSelector_pp;
  UInt16 localSelector_n;
  UInt16 localSelector_g;

  /* Outputs for enable SubSystem: '<S16>/F01_SyncIn' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/INJRPRMMDL_u8Inhib'
   *  EnablePort: '<S19>/Enable'
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  if (INJRPRMMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET4 */
    VEMS_vidGET(Eng_noCmprCyl, InjrPrmMdl_B.VEMS_vidGET4_i);

    /* DataTypeConversion: '<S19>/Data Type Conversion1' */
    localAdd = InjrPrmMdl_B.VEMS_vidGET4_i;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET5 */
    VEMS_vidGET(Eng_noInCyl, InjrPrmMdl_B.VEMS_vidGET5_j);

    /* DataTypeConversion: '<S19>/Data Type Conversion3' */
    localAdd_e = InjrPrmMdl_B.VEMS_vidGET5_j;

    /* Sum: '<S20>/Add' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    localAdd_k = localAdd - 1U;

    /* MinMax: '<S20>/MinMax' incorporates:
     *  Constant: '<S20>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET9_n);

    /* DataTypeDuplicate Block: '<S20>/Data Type Duplicate'
     *
     * Regarding '<S20>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S20>/Selector' */
    localSelector = InjrPrmMdl_B.VEMS_vidGET9_n[(localAdd_k)];

    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S21>/Constant1'
     */
    localAdd_k = localAdd - 1U;

    /* MinMax: '<S21>/MinMax' incorporates:
     *  Constant: '<S21>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET8_n);

    /* DataTypeDuplicate Block: '<S21>/Data Type Duplicate'
     *
     * Regarding '<S21>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S21>/Selector' */
    localSelector_o = InjrPrmMdl_B.VEMS_vidGET8_n[(localAdd_k)];

    /* Sum: '<S22>/Add' incorporates:
     *  Constant: '<S22>/Constant1'
     */
    localAdd_k = localAdd - 1U;

    /* MinMax: '<S22>/MinMax' incorporates:
     *  Constant: '<S22>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET12_j);

    /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate'
     *
     * Regarding '<S22>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S22>/Selector' */
    localSelector_d = InjrPrmMdl_B.VEMS_vidGET12_j[(localAdd_k)];

    /* Sum: '<S23>/Add' incorporates:
     *  Constant: '<S23>/Constant1'
     */
    localAdd_k = localAdd - 1U;

    /* MinMax: '<S23>/MinMax' incorporates:
     *  Constant: '<S23>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET13_c);

    /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate'
     *
     * Regarding '<S23>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S23>/Selector' */
    localSelector_m = InjrPrmMdl_B.VEMS_vidGET13_c[(localAdd_k)];

    /* Sum: '<S24>/Add' incorporates:
     *  Constant: '<S24>/Constant1'
     */
    localAdd_k = localAdd_e - 1U;

    /* MinMax: '<S24>/MinMax' incorporates:
     *  Constant: '<S24>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET7_l);

    /* DataTypeDuplicate Block: '<S24>/Data Type Duplicate'
     *
     * Regarding '<S24>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S24>/Selector' */
    localSelector_f = InjrPrmMdl_B.VEMS_vidGET7_l[(localAdd_k)];

    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S25>/Constant1'
     */
    localAdd_k = localAdd_e - 1U;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S25>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET6_h);

    /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate'
     *
     * Regarding '<S25>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S25>/Selector' */
    localSelector_p = InjrPrmMdl_B.VEMS_vidGET6_h[(localAdd_k)];

    /* Sum: '<S26>/Add' incorporates:
     *  Constant: '<S26>/Constant1'
     */
    localAdd_k = localAdd_e - 1U;

    /* MinMax: '<S26>/MinMax' incorporates:
     *  Constant: '<S26>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET_f);

    /* DataTypeDuplicate Block: '<S26>/Data Type Duplicate'
     *
     * Regarding '<S26>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S26>/Selector' */
    localSelector_i = InjrPrmMdl_B.VEMS_vidGET_f[(localAdd_k)];

    /* Sum: '<S27>/Add' incorporates:
     *  Constant: '<S27>/Constant1'
     */
    localAdd_k = localAdd_e - 1U;

    /* MinMax: '<S27>/MinMax' incorporates:
     *  Constant: '<S27>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET1_m);

    /* DataTypeDuplicate Block: '<S27>/Data Type Duplicate'
     *
     * Regarding '<S27>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S27>/Selector' */
    localSelector_f0 = InjrPrmMdl_B.VEMS_vidGET1_m[(localAdd_k)];

    /* Sum: '<S28>/Add' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    localAdd_k = localAdd - 1U;

    /* MinMax: '<S28>/MinMax' incorporates:
     *  Constant: '<S28>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET2_l);

    /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate'
     *
     * Regarding '<S28>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S28>/Selector' */
    localSelector_pp = InjrPrmMdl_B.VEMS_vidGET2_l[(localAdd_k)];

    /* Sum: '<S29>/Add' incorporates:
     *  Constant: '<S29>/Constant1'
     */
    localAdd--;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET3_b);

    /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate'
     *
     * Regarding '<S29>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S29>/Selector' incorporates:
     *  Constant: '<S29>/Constant'
     *  MinMax: '<S29>/MinMax'
     */
    localSelector_n = InjrPrmMdl_B.VEMS_vidGET3_b[rt_MIN(localAdd, 5U)];

    /* Sum: '<S30>/Add' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    localAdd_k = localAdd_e - 1U;

    /* MinMax: '<S30>/MinMax' incorporates:
     *  Constant: '<S30>/Constant'
     */
    localAdd_k = rt_MIN(localAdd_k, 5U);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET10_g);

    /* DataTypeDuplicate Block: '<S30>/Data Type Duplicate'
     *
     * Regarding '<S30>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S30>/Selector' */
    localSelector_g = InjrPrmMdl_B.VEMS_vidGET10_g[(localAdd_k)];

    /* Sum: '<S31>/Add' incorporates:
     *  Constant: '<S31>/Constant1'
     */
    localAdd_e--;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6,
                       InjrPrmMdl_B.VEMS_vidGET11_g);

    /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate'
     *
     * Regarding '<S31>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* SignalConversion: '<S19>/Signal Conversion1' */
    InjrM_prm_pCylEstimInj[1] = localSelector_f0;

    /* SignalConversion: '<S19>/Signal Conversion10' */
    InjrM_prm_pFuEstimInj[1] = localSelector_f;

    /* SignalConversion: '<S19>/Signal Conversion11' */
    InjrM_prm_pFuEstimInj[2] = localSelector_o;

    /* SignalConversion: '<S19>/Signal Conversion12' */
    InjrM_prm_pFuEstimInj[3] = localSelector;

    /* SignalConversion: '<S19>/Signal Conversion2' */
    InjrM_prm_pCylEstimInj[2] = localSelector_pp;

    /* SignalConversion: '<S19>/Signal Conversion3' */
    InjrM_prm_pCylEstimInj[3] = localSelector_n;

    /* SignalConversion: '<S19>/Signal Conversion4' */
    InjrM_prm_mFuInjReq[0] = localSelector_g;

    /* SignalConversion: '<S19>/Signal Conversion5' incorporates:
     *  Constant: '<S31>/Constant'
     *  MinMax: '<S31>/MinMax'
     *  Selector: '<S31>/Selector'
     */
    InjrM_prm_mFuInjReq[1] = InjrPrmMdl_B.VEMS_vidGET11_g[rt_MIN(localAdd_e, 5U)];

    /* SignalConversion: '<S19>/Signal Conversion6' */
    InjrM_prm_mFuInjReq[2] = localSelector_d;

    /* SignalConversion: '<S19>/Signal Conversion7' */
    InjrM_prm_pCylEstimInj[0] = localSelector_i;

    /* SignalConversion: '<S19>/Signal Conversion8' */
    InjrM_prm_mFuInjReq[3] = localSelector_m;

    /* SignalConversion: '<S19>/Signal Conversion9' */
    InjrM_prm_pFuEstimInj[0] = localSelector_p;
  }

  /* end of Outputs for SubSystem: '<S16>/F01_SyncIn' */
}

/* Output and update for function-call system: '<S8>/F03_InjrMdlCylCorSyncEve' */
void InjrPr_F03_InjrMdlCylCorSyncEve(void)
{
  Float32 localInterpolationUsingPreloo_d[2];
  Float32 localfractionTmp_0d;
  UInt8 locallocalTmpSignalConversionAt;
  Float32 locallocalInterpolationUsingPre;
  Float32 locallocalInterpolationUsingP_0;
  Float32 locallocalInterpolationUsingP_1;
  Float32 locallocalInterpolationUsingP_2;
  UInt32 locallocalEng_noCmprCyl_InjrM_n;
  UInt32 locallocalEng_noCmprCyl_InjrM_0;

  /* Outputs for enable SubSystem: '<S61>/F03_InjrMdlCylCorSyncEve' incorporates:
   *  Constant: '<S61>/Constant1'
   *  Constant: '<S61>/INJRPRMMDL_u8Inhib'
   *  EnablePort: '<S67>/Enable'
   *  RelationalOperator: '<S61>/Relational Operator'
   */
  if (INJRPRMMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S67>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, InjrPrmMdl_B.VEMS_vidGET1_f);

    /* S-Function "vems_vidGET" Block: <S67>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, InjrPrmMdl_B.VEMS_vidGET_g);

    /* SignalConversion: '<S71>/TmpSignal ConversionAtPrelookupInport1' */
    locallocalTmpSignalConversionAt = InjrPrmMdl_B.VEMS_vidGET_g;

    /* PreLookup: '<S71>/Prelookup' */
    locallocalEng_noCmprCyl_InjrM_n = plook_u32u8f_binc
      (InjrPrmMdl_B.VEMS_vidGET1_f, (&(InjrM_noCyl_A[0])), 5U,
       &localInterpolationUsingPreloo_d[0]);
    locallocalEng_noCmprCyl_InjrM_0 = plook_u32u8f_binc
      (locallocalTmpSignalConversionAt, (&(InjrM_noCyl_A[0])), 5U,
       &localInterpolationUsingPreloo_d[1]);

    /* Interpolation_n-D: '<S68>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_d[0];
    locallocalInterpolationUsingP_0 = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noCmprCyl_InjrM_n, localfractionTmp_0d,
       (&(InjrM_facCorCylPFuInj_T[0])));
    localfractionTmp_0d = localInterpolationUsingPreloo_d[1];
    locallocalInterpolationUsingPre = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noCmprCyl_InjrM_0, localfractionTmp_0d,
       (&(InjrM_facCorCylPFuInj_T[0])));

    /* Interpolation_n-D: '<S69>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_d[0];
    locallocalInterpolationUsingP_2 = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noCmprCyl_InjrM_n, localfractionTmp_0d,
       (&(InjrM_facCorCylOfsInj_T[0])));
    localfractionTmp_0d = localInterpolationUsingPreloo_d[1];
    locallocalInterpolationUsingP_1 = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noCmprCyl_InjrM_0, localfractionTmp_0d,
       (&(InjrM_facCorCylOfsInj_T[0])));

    /* Interpolation_n-D: '<S70>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_d[0];
    localInterpolationUsingPreloo_d[0] = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noCmprCyl_InjrM_n, localfractionTmp_0d,
       (&(InjrM_facCorCylGainLnr_T[0])));
    localfractionTmp_0d = localInterpolationUsingPreloo_d[1];
    localInterpolationUsingPreloo_d[1] = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noCmprCyl_InjrM_0, localfractionTmp_0d,
       (&(InjrM_facCorCylGainLnr_T[0])));

    /* SignalConversion: '<S67>/Signal Conversion1' */
    InjrM_prm_facCorCylPFuInj[3] = locallocalInterpolationUsingPre;

    /* SignalConversion: '<S67>/Signal Conversion10' */
    InjrM_prm_facCorCylGainLnr[2] = localInterpolationUsingPreloo_d[1];

    /* SignalConversion: '<S67>/Signal Conversion11' */
    InjrM_prm_facCorCylGainLnr[1] = localInterpolationUsingPreloo_d[0];

    /* SignalConversion: '<S67>/Signal Conversion12' */
    InjrM_prm_facCorCylPFuInj[0] = locallocalInterpolationUsingP_0;

    /* SignalConversion: '<S67>/Signal Conversion2' */
    InjrM_prm_facCorCylOfs[3] = locallocalInterpolationUsingP_1;

    /* SignalConversion: '<S67>/Signal Conversion3' */
    InjrM_prm_facCorCylOfs[0] = locallocalInterpolationUsingP_2;

    /* SignalConversion: '<S67>/Signal Conversion4' */
    InjrM_prm_facCorCylOfs[2] = locallocalInterpolationUsingP_1;

    /* SignalConversion: '<S67>/Signal Conversion5' */
    InjrM_prm_facCorCylOfs[1] = locallocalInterpolationUsingP_2;

    /* SignalConversion: '<S67>/Signal Conversion6' */
    InjrM_prm_facCorCylPFuInj[2] = locallocalInterpolationUsingPre;

    /* SignalConversion: '<S67>/Signal Conversion7' */
    InjrM_prm_facCorCylPFuInj[1] = locallocalInterpolationUsingP_0;

    /* SignalConversion: '<S67>/Signal Conversion8' */
    InjrM_prm_facCorCylGainLnr[3] = localInterpolationUsingPreloo_d[1];

    /* SignalConversion: '<S67>/Signal Conversion9' */
    InjrM_prm_facCorCylGainLnr[0] = localInterpolationUsingPreloo_d[0];
  }

  /* end of Outputs for SubSystem: '<S61>/F03_InjrMdlCylCorSyncEve' */
}

/* Output and update for function-call system: '<S1>/F03_InjrPrmMdlFct' */
void InjrPrmMdl_F03_InjrPrmMdlFct_e(void)
{
  /* Outputs for enable SubSystem: '<S9>/F03_InjrPrmMdlFct' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/INJRPRMMDL_u8Inhib'
   *  EnablePort: '<S72>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (INJRPRMMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET2 */
    VEMS_vidGET(InjSys_stTypElCmdInjrReq, InjrPrmMdl_B.VEMS_vidGET2_c);

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET */
    VEMS_vidGET(Ext_nEng, InjrPrmMdl_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET1 */
    VEMS_vidGET(FuSysM_tFu, InjrPrmMdl_B.VEMS_vidGET1_d);

    /* Outputs for atomic SubSystem: '<S72>/F03_InjrPrmMdlFct' */
    InjrPrmMdl_F03_InjrPrmMdlFct((&(InjrM_prm_pFuEstimInj[0])),
      (&(InjrM_prm_pCylEstimInj[0])), (&(InjrM_prm_facCorCylPFuInj[0])),
      InjrPrmMdl_B.VEMS_vidGET1_d, InjrPrmMdl_B.VEMS_vidGET2_c,
      (&(InjrM_prm_facCorCylOfs[0])), InjrPrmMdl_B.VEMS_vidGET,
      (&(InjrM_prm_mFuInjReq[0])), (&(InjrM_prm_facCorCylGainLnr[0])),
      &InjrPrmMdl_B.F03_InjrPrmMdlFct_fy);

    /* end of Outputs for SubSystem: '<S72>/F03_InjrPrmMdlFct' */

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET */
    VEMS_vidSET(InjrM_IdxInjrMdlInj,
                InjrPrmMdl_B.F03_InjrPrmMdlFct_fy.SignalConversion1);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjrM_prm_facCorGainLnr, 4,
                       InjrPrmMdl_B.F03_InjrPrmMdlFct_fy.Switch);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjrM_prm_facGainLnrlnjRaw, 4,
                       InjrPrmMdl_B.F03_InjrPrmMdlFct_fy.OutDTConv_d);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjrM_prm_pDifInjr, 4,
                       InjrPrmMdl_B.F03_InjrPrmMdlFct_fy.SignalConversion);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsRaw, 4,
                       InjrPrmMdl_B.F03_InjrPrmMdlFct_fy.OutDTConv);
  }

  /* end of Outputs for SubSystem: '<S9>/F03_InjrPrmMdlFct' */
}

/* Start for exported function: InjrM_EveCkSnOn_InjrPrmMdl */
void InjrM_EveCkSnOn_InjrPrmMdl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjrPrmMdl_fc_demux1'
   */

  /* Start for S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S1>/F03_InjrPrmMdlFct'
   *  Start for SubSystem: '<S7>/F01_SyncIn'
   *  Start for SubSystem: '<S8>/F03_InjrMdlCylCorSyncEve'
   */
}

/* Output and update for exported function: InjrM_EveCkSnOn_InjrPrmMdl */
void InjrM_EveCkSnOn_InjrPrmMdl(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrPrmMdl_fc_demux1'
   */

  /* S-Function (fcncallgen): '<S11>/Function-Call Generator' */
  InjrPrmMdl_ASYNC3(0);
  InjrPrmMdl_ASYNC2(0);
}

/* Output and update for exported function: InjrM_SdlFast_InjrPrmMdl */
void InjrM_SdlFast_InjrPrmMdl(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrPrmMdl_fc_demux2'
   */

  /* S-Function (fcncallgen): '<S12>/Function-Call Generator' */
  InjrPrmMdl_ASYNC3(1);
  InjrPrmMdl_ASYNC2(1);
}

/* Output and update for function-call system: '<S7>/F02_SyncIn1' */
void InjrPrmMdl_F02_SyncIn1_k(void)
{
  /* Outputs for enable SubSystem: '<S17>/F02_SyncIn1' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S17>/INJRPRMMDL_u8Inhib'
   *  EnablePort: '<S32>/Enable'
   *  RelationalOperator: '<S17>/Relational Operator'
   */
  if (INJRPRMMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET6);

    /* DataTypeDuplicate Block: '<S40>/Data Type Duplicate'
     *
     * Regarding '<S40>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET_d);

    /* DataTypeDuplicate Block: '<S41>/Data Type Duplicate'
     *
     * Regarding '<S41>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjH2Cyl, 6, InjrPrmMdl_B.VEMS_vidGET1);

    /* DataTypeDuplicate Block: '<S42>/Data Type Duplicate'
     *
     * Regarding '<S42>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET4 */
    VEMS_vidGET(Eng_noInCyl, InjrPrmMdl_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET5 */
    VEMS_vidGET(Eng_noInNxtCyl, InjrPrmMdl_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET10);

    /* DataTypeDuplicate Block: '<S45>/Data Type Duplicate'
     *
     * Regarding '<S45>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6, InjrPrmMdl_B.VEMS_vidGET7);

    /* DataTypeDuplicate Block: '<S39>/Data Type Duplicate'
     *
     * Regarding '<S39>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET11);

    /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate'
     *
     * Regarding '<S35>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET8);

    /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate'
     *
     * Regarding '<S38>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS1Cyl, 6, InjrPrmMdl_B.VEMS_vidGET2);

    /* DataTypeDuplicate Block: '<S43>/Data Type Duplicate'
     *
     * Regarding '<S43>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6, InjrPrmMdl_B.VEMS_vidGET9);

    /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate'
     *
     * Regarding '<S34>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(CylM_prm_pCylEstimInjS2Cyl, 6, InjrPrmMdl_B.VEMS_vidGET3);

    /* DataTypeDuplicate Block: '<S44>/Data Type Duplicate'
     *
     * Regarding '<S44>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET12);

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate'
     *
     * Regarding '<S36>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S32>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, InjrPrmMdl_B.VEMS_vidGET13);

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate'
     *
     * Regarding '<S37>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Outputs for atomic SubSystem: '<S32>/F02_SyncIn1' */
    InjrPrmMdl_F02_SyncIn1(InjrPrmMdl_B.VEMS_vidGET5, InjrPrmMdl_B.VEMS_vidGET4,
      InjrPrmMdl_B.VEMS_vidGET9, InjrPrmMdl_B.VEMS_vidGET11,
      InjrPrmMdl_B.VEMS_vidGET12, InjrPrmMdl_B.VEMS_vidGET13,
      InjrPrmMdl_B.VEMS_vidGET8, InjrPrmMdl_B.VEMS_vidGET7,
      InjrPrmMdl_B.VEMS_vidGET6, InjrPrmMdl_B.VEMS_vidGET_d,
      InjrPrmMdl_B.VEMS_vidGET1, InjrPrmMdl_B.VEMS_vidGET2,
      InjrPrmMdl_B.VEMS_vidGET3, InjrPrmMdl_B.VEMS_vidGET10,
      &InjrM_prm_pCylEstimInj[1], &InjrM_prm_pFuEstimInj[1],
      &InjrM_prm_pFuEstimInj[2], &InjrM_prm_pFuEstimInj[3],
      &InjrM_prm_pCylEstimInj[2], &InjrM_prm_pCylEstimInj[3],
      &InjrM_prm_mFuInjReq[0], &InjrM_prm_mFuInjReq[1], &InjrM_prm_mFuInjReq[2],
      &InjrM_prm_pCylEstimInj[0], &InjrM_prm_mFuInjReq[3],
      &InjrM_prm_pFuEstimInj[0]);

    /* end of Outputs for SubSystem: '<S32>/F02_SyncIn1' */
  }

  /* end of Outputs for SubSystem: '<S17>/F02_SyncIn1' */
}

/* Output and update for function-call system: '<S8>/F02_InjrMdlCylCorSyncEveInj' */
void Inj_F02_InjrMdlCylCorSyncEveInj(void)
{
  Float32 localInterpolationUsingPreloo_c[2];
  Float32 localfractionTmp_0d;
  UInt8 locallocalTmpSignalConversionAt;
  Float32 locallocalInterpolationUsingPre;
  Float32 locallocalInterpolationUsingP_0;
  Float32 locallocalInterpolationUsingP_1;
  Float32 locallocalInterpolationUsingP_2;
  UInt32 locallocalEng_noInCyl_InjrM_noC;
  UInt32 locallocalEng_noInCyl_InjrM_n_0;

  /* Outputs for enable SubSystem: '<S60>/F02_InjrMdlCylCorSyncEveInj' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S60>/INJRPRMMDL_u8Inhib'
   *  EnablePort: '<S62>/Enable'
   *  RelationalOperator: '<S60>/Relational Operator'
   */
  if (INJRPRMMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S62>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, InjrPrmMdl_B.VEMS_vidGET1_ei);

    /* S-Function "vems_vidGET" Block: <S62>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, InjrPrmMdl_B.VEMS_vidGET_b);

    /* SignalConversion: '<S66>/TmpSignal ConversionAtPrelookupInport1' */
    locallocalTmpSignalConversionAt = InjrPrmMdl_B.VEMS_vidGET_b;

    /* PreLookup: '<S66>/Prelookup' */
    locallocalEng_noInCyl_InjrM_noC = plook_u32u8f_binc
      (InjrPrmMdl_B.VEMS_vidGET1_ei, (&(InjrM_noCyl_A[0])), 5U,
       &localInterpolationUsingPreloo_c[0]);
    locallocalEng_noInCyl_InjrM_n_0 = plook_u32u8f_binc
      (locallocalTmpSignalConversionAt, (&(InjrM_noCyl_A[0])), 5U,
       &localInterpolationUsingPreloo_c[1]);

    /* Interpolation_n-D: '<S63>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_c[0];
    locallocalInterpolationUsingP_0 = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noInCyl_InjrM_noC, localfractionTmp_0d,
       (&(InjrM_facCorCylPFuInj_T[0])));
    localfractionTmp_0d = localInterpolationUsingPreloo_c[1];
    locallocalInterpolationUsingPre = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noInCyl_InjrM_n_0, localfractionTmp_0d,
       (&(InjrM_facCorCylPFuInj_T[0])));

    /* Interpolation_n-D: '<S64>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_c[0];
    locallocalInterpolationUsingP_2 = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noInCyl_InjrM_noC, localfractionTmp_0d,
       (&(InjrM_facCorCylOfsInj_T[0])));
    localfractionTmp_0d = localInterpolationUsingPreloo_c[1];
    locallocalInterpolationUsingP_1 = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noInCyl_InjrM_n_0, localfractionTmp_0d,
       (&(InjrM_facCorCylOfsInj_T[0])));

    /* Interpolation_n-D: '<S65>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_c[0];
    localInterpolationUsingPreloo_c[0] = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noInCyl_InjrM_noC, localfractionTmp_0d,
       (&(InjrM_facCorCylGainLnr_T[0])));
    localfractionTmp_0d = localInterpolationUsingPreloo_c[1];
    localInterpolationUsingPreloo_c[1] = intrp1d_iu16n15ff_u32f_l_ns
      (locallocalEng_noInCyl_InjrM_n_0, localfractionTmp_0d,
       (&(InjrM_facCorCylGainLnr_T[0])));

    /* SignalConversion: '<S62>/Signal Conversion1' */
    InjrM_prm_facCorCylPFuInj[3] = locallocalInterpolationUsingPre;

    /* SignalConversion: '<S62>/Signal Conversion10' */
    InjrM_prm_facCorCylGainLnr[2] = localInterpolationUsingPreloo_c[1];

    /* SignalConversion: '<S62>/Signal Conversion11' */
    InjrM_prm_facCorCylGainLnr[1] = localInterpolationUsingPreloo_c[0];

    /* SignalConversion: '<S62>/Signal Conversion12' */
    InjrM_prm_facCorCylPFuInj[0] = locallocalInterpolationUsingP_0;

    /* SignalConversion: '<S62>/Signal Conversion2' */
    InjrM_prm_facCorCylOfs[3] = locallocalInterpolationUsingP_1;

    /* SignalConversion: '<S62>/Signal Conversion3' */
    InjrM_prm_facCorCylOfs[0] = locallocalInterpolationUsingP_2;

    /* SignalConversion: '<S62>/Signal Conversion4' */
    InjrM_prm_facCorCylOfs[2] = locallocalInterpolationUsingP_1;

    /* SignalConversion: '<S62>/Signal Conversion5' */
    InjrM_prm_facCorCylOfs[1] = locallocalInterpolationUsingP_2;

    /* SignalConversion: '<S62>/Signal Conversion6' */
    InjrM_prm_facCorCylPFuInj[2] = locallocalInterpolationUsingPre;

    /* SignalConversion: '<S62>/Signal Conversion7' */
    InjrM_prm_facCorCylPFuInj[1] = locallocalInterpolationUsingP_0;

    /* SignalConversion: '<S62>/Signal Conversion8' */
    InjrM_prm_facCorCylGainLnr[3] = localInterpolationUsingPreloo_c[1];

    /* SignalConversion: '<S62>/Signal Conversion9' */
    InjrM_prm_facCorCylGainLnr[0] = localInterpolationUsingPreloo_c[0];
  }

  /* end of Outputs for SubSystem: '<S60>/F02_InjrMdlCylCorSyncEveInj' */
}

/* Start for exported function: InjrM_EveInj_InjrPrmMdl */
void InjrM_EveInj_InjrPrmMdl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjrPrmMdl_fc_demux3'
   */

  /* Start for S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S7>/F02_SyncIn1'
   *  Start for SubSystem: '<S8>/F02_InjrMdlCylCorSyncEveInj'
   */
}

/* Output and update for exported function: InjrM_EveInj_InjrPrmMdl */
void InjrM_EveInj_InjrPrmMdl(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrPrmMdl_fc_demux3'
   */

  /* S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  SubSystem: '<S7>/F02_SyncIn1'
   *  SubSystem: '<S8>/F02_InjrMdlCylCorSyncEveInj'
   */
  InjrPrmMdl_F02_SyncIn1_k();
  Inj_F02_InjrMdlCylCorSyncEveInj();
  InjrPrmMdl_ASYNC2(2);
}

/* Output and update for exported function: InjrM_EveSpl_InjrPrmMdl */
void InjrM_EveSpl_InjrPrmMdl(void)
{
  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrPrmMdl_fc_demux4'
   */

  /* S-Function (fcncallgen): '<S14>/Function-Call Generator' */
  InjrPrmMdl_ASYNC3(2);
  InjrPrmMdl_ASYNC2(3);
}

/* Model initialize function */
void InjrPrmMdl_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  InjrM_EveRst_InjrPrmMdl_Start();
  InjrM_EveCkSnOn_InjrPrmMdl_Start();
  InjrM_EveInj_InjrPrmMdl_Start();

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  InjrM_prm_tiInjOfsCal[0] = -1.048576012E-001F;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
  InjrM_prm_pDsInjrCor[0] = -2.56E+007F;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  InjrM_prm_tiInjOfsCal[1] = -1.048576012E-001F;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
  InjrM_prm_pDsInjrCor[1] = -2.56E+007F;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  InjrM_prm_tiInjOfsCal[2] = -1.048576012E-001F;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
  InjrM_prm_pDsInjrCor[2] = -2.56E+007F;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  InjrM_prm_tiInjOfsCal[3] = -1.048576012E-001F;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
  InjrM_prm_pDsInjrCor[3] = -2.56E+007F;
}

#define INJRPRMMDL_STOP_SEC_CODE
#include "InjrPrmMdl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
