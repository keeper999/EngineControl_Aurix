/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tiFuSp                                                  */
/* !Description     : CALCUL DU TEMPS D INJECTION                             */
/*                                                                            */
/* !Module          : tiFuSp                                                  */
/*                                                                            */
/* !File            : tiFuSp.c                                                */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : PTS_DOC_5182663 / 09                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Nov 19 10:39:37 2013                              */
/*   Model name       : tiFuSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.767                                                 */
/*   Root subsystem   : /tiFuSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/TIFUSP/tiFuSp.c_v         $*/
/* $Revision::   1.25                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "tiFuSp.h"
#include "tiFuSp_private.h"

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
#define TIFUSP_START_SEC_VAR_UNSPECIFIED
#include "tiFuSp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_tiFuSp tiFuSp_B;

/* Block states (auto storage) */
D_Work_tiFuSp tiFuSp_DWork;

#define TIFUSP_STOP_SEC_VAR_UNSPECIFIED
#include "tiFuSp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define TIFUSP_START_SEC_CODE
#include "tiFuSp_MemMap.h"

void tiFuSp_ASYNC1(int controlPortIdx)
{
}

void tiFuSp_ASYNC2(int controlPortIdx)
{
}

void tiFuSp_ASYNC3(int controlPortIdx)
{
}

void tiFuSp_ASYNC4(int controlPortIdx)
{
  tiFuSp_F02_InjmFu();
}

void tiFuSp_ASYNC5(int controlPortIdx)
{
  tiFuSp_F02_tiFuSpClcn();
}

void tiFuSp_ASYNC6(int controlPortIdx)
{
  tiFuSp_F01_tiFuSpSyncInEveClcn();
  tiFuSp_F03_InjtiSyncEveClcn();
}

/* Output and update for function-call system: '<S7>/F01_tiFuSpSyncInEveClcn' */
void tiFuSp_F01_tiFuSpSyncInEveClcn(void)
{
  UInt32 localAdd;
  UInt32 localAdd_g;
  UInt32 localAdd_p;
  SInt32 localmin;
  SInt32 localmin_0;
  UInt16 localSelector_c;
  UInt16 localSelector_jk;
  UInt16 localSelector_g;
  UInt16 localSelector_ch;
  UInt16 localSelector_jp;
  UInt16 localSelector_j;
  UInt16 localSelector;
  UInt16 localSelector_o;
  UInt16 localSelector_l;
  SInt16 localSelector_dz;
  SInt16 localSelector_i;
  SInt16 localSelector_i5;
  SInt16 localSelector_je;
  UInt8 locallocalMultiportSwitch_idx;
  UInt8 locallocalMultiportSwitch_idx_0;

  /* Outputs for enable SubSystem: '<S16>/F00_tiFuSpSyncInEveClcn' incorporates:
   *  Constant: '<S16>/ConstVal'
   *  Constant: '<S16>/TIFUSP_u8Inhib'
   *  EnablePort: '<S18>/Enable'
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  if (TIFUSP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH1Cyl, 6, tiFuSp_B.VEMS_vidGET13_p);

    /* DataTypeDuplicate Block: '<S43>/Data Type Duplicate'
     *
     * Regarding '<S43>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, tiFuSp_B.VEMS_vidGET1_oj);

    /* DataTypeConversion: '<S18>/Data Type Conversion14' */
    localAdd = tiFuSp_B.VEMS_vidGET1_oj;

    /* Sum: '<S43>/Add' incorporates:
     *  Constant: '<S43>/Constant1'
     */
    localAdd_g = localAdd - 1U;

    /* Selector: '<S43>/Selector' incorporates:
     *  Constant: '<S43>/Constant'
     *  MinMax: '<S43>/MinMax'
     */
    localSelector_c = tiFuSp_B.VEMS_vidGET13_p[rt_MIN(localAdd_g, 5U)];

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET14 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH2Cyl, 6, tiFuSp_B.VEMS_vidGET14_e);

    /* DataTypeDuplicate Block: '<S44>/Data Type Duplicate'
     *
     * Regarding '<S44>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S44>/Add' incorporates:
     *  Constant: '<S44>/Constant1'
     */
    localAdd_g = localAdd - 1U;

    /* Selector: '<S44>/Selector' incorporates:
     *  Constant: '<S44>/Constant'
     *  MinMax: '<S44>/MinMax'
     */
    localSelector_jk = tiFuSp_B.VEMS_vidGET14_e[rt_MIN(localAdd_g, 5U)];

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET15 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS1Cyl, 6, tiFuSp_B.VEMS_vidGET15_o);

    /* DataTypeDuplicate Block: '<S45>/Data Type Duplicate'
     *
     * Regarding '<S45>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, tiFuSp_B.VEMS_vidGET_m);

    /* DataTypeConversion: '<S18>/Data Type Conversion15' */
    localAdd_g = tiFuSp_B.VEMS_vidGET_m;

    /* Sum: '<S45>/Add' incorporates:
     *  Constant: '<S45>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* Selector: '<S45>/Selector' incorporates:
     *  Constant: '<S45>/Constant'
     *  MinMax: '<S45>/MinMax'
     */
    localSelector_g = tiFuSp_B.VEMS_vidGET15_o[rt_MIN(localAdd_p, 5U)];

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET16 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS2Cyl, 6, tiFuSp_B.VEMS_vidGET16_k);

    /* DataTypeDuplicate Block: '<S46>/Data Type Duplicate'
     *
     * Regarding '<S46>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S46>/Add' incorporates:
     *  Constant: '<S46>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* Selector: '<S46>/Selector' incorporates:
     *  Constant: '<S46>/Constant'
     *  MinMax: '<S46>/MinMax'
     */
    localSelector_ch = tiFuSp_B.VEMS_vidGET16_k[rt_MIN(localAdd_p, 5U)];

    /* DataTypeConversion: '<S18>/Data Type Conversion1' */
    InjrSys_prm_facGain[0] = ((Float32)localSelector_c) * 0.015625F;
    InjrSys_prm_facGain[1] = ((Float32)localSelector_jk) * 0.015625F;
    InjrSys_prm_facGain[2] = ((Float32)localSelector_g) * 0.015625F;
    InjrSys_prm_facGain[3] = ((Float32)localSelector_ch) * 0.015625F;
    InjrSys_prm_facGain[4] = ((Float32)localSelector_g) * 0.015625F;
    InjrSys_prm_facGain[5] = ((Float32)localSelector_ch) * 0.015625F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, tiFuSp_B.VEMS_vidGET3_k);

    /* DataTypeDuplicate Block: '<S48>/Data Type Duplicate'
     *
     * Regarding '<S48>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S49>/Data Type Duplicate'
     *
     * Regarding '<S49>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S48>/Add' incorporates:
     *  Constant: '<S48>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* MinMax: '<S48>/MinMax' incorporates:
     *  Constant: '<S48>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_p, 5U);

    /* Sum: '<S49>/Add' incorporates:
     *  Constant: '<S49>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* DataTypeConversion: '<S18>/Data Type Conversion10' incorporates:
     *  Constant: '<S49>/Constant'
     *  MinMax: '<S49>/MinMax'
     *  Selector: '<S48>/Selector'
     *  Selector: '<S49>/Selector'
     */
    InjrSys_prm_agBegInjH2[0] = (UInt16)((((UInt32)tiFuSp_B.VEMS_vidGET3_k
      [(localmin)]) * 43691U) >> 16U);
    InjrSys_prm_agBegInjH2[1] = (UInt16)((((UInt32)
      tiFuSp_B.VEMS_vidGET3_k[rt_MIN(localAdd_p, 5U)]) * 43691U) >> 16U);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, tiFuSp_B.VEMS_vidGET9_l);

    /* DataTypeDuplicate Block: '<S21>/Data Type Duplicate'
     *
     * Regarding '<S21>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S21>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* Selector: '<S21>/Selector' incorporates:
     *  Constant: '<S21>/Constant'
     *  MinMax: '<S21>/MinMax'
     */
    localSelector_ch = tiFuSp_B.VEMS_vidGET9_l[rt_MIN(localAdd_p, 5U)];

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, tiFuSp_B.VEMS_vidGET10_c);

    /* DataTypeDuplicate Block: '<S20>/Data Type Duplicate'
     *
     * Regarding '<S20>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate'
     *
     * Regarding '<S22>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S52>/Data Type Duplicate'
     *
     * Regarding '<S52>/Data Type Duplicate':
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
    localSelector_g = tiFuSp_B.VEMS_vidGET10_c[rt_MIN(localAdd_p, 5U)];

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, tiFuSp_B.VEMS_vidGET11_b);

    /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate'
     *
     * Regarding '<S23>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate'
     *
     * Regarding '<S25>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate'
     *
     * Regarding '<S34>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate'
     *
     * Regarding '<S35>/Data Type Duplicate':
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
    localSelector_jk = tiFuSp_B.VEMS_vidGET11_b[rt_MIN(localAdd_p, 5U)];

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, tiFuSp_B.VEMS_vidGET12_j);

    /* DataTypeDuplicate Block: '<S24>/Data Type Duplicate'
     *
     * Regarding '<S24>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S26>/Data Type Duplicate'
     *
     * Regarding '<S26>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate'
     *
     * Regarding '<S36>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate'
     *
     * Regarding '<S37>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S24>/Add' incorporates:
     *  Constant: '<S24>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* MinMax: '<S24>/MinMax' incorporates:
     *  Constant: '<S24>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_p, 5U);

    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S25>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S25>/Constant'
     */
    localmin_0 = (SInt32)rt_MIN(localAdd_p, 5U);

    /* Sum: '<S26>/Add' incorporates:
     *  Constant: '<S26>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
     *  Constant: '<S26>/Constant'
     *  MinMax: '<S26>/MinMax'
     *  Selector: '<S24>/Selector'
     *  Selector: '<S25>/Selector'
     *  Selector: '<S26>/Selector'
     */
    InjrSys_prm_mFuInjReq[0] = ((Float32)localSelector_ch) * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[1] = ((Float32)localSelector_g) * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[2] = ((Float32)localSelector_jk) * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[3] = ((Float32)tiFuSp_B.VEMS_vidGET12_j[(localmin)]) *
      7.450580597E-009F;
    InjrSys_prm_mFuInjReq[4] = ((Float32)tiFuSp_B.VEMS_vidGET11_b[(localmin_0)])
      * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[5] = ((Float32)tiFuSp_B.VEMS_vidGET12_j[rt_MIN
      (localAdd_p, 5U)]) * 7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, tiFuSp_B.VEMS_vidGET6_g);

    /* DataTypeDuplicate Block: '<S30>/Data Type Duplicate'
     *
     * Regarding '<S30>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S41>/Data Type Duplicate'
     *
     * Regarding '<S41>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S30>/Add' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* MinMax: '<S30>/MinMax' incorporates:
     *  Constant: '<S30>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_p, 5U);

    /* Sum: '<S41>/Add' incorporates:
     *  Constant: '<S41>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* DataTypeConversion: '<S18>/Data Type Conversion3' incorporates:
     *  Constant: '<S41>/Constant'
     *  MinMax: '<S41>/MinMax'
     *  Selector: '<S30>/Selector'
     *  Selector: '<S41>/Selector'
     */
    InjrSys_prm_agEndInjH1[0] = ((Float32)tiFuSp_B.VEMS_vidGET6_g[(localmin)]) *
      0.0625F;
    InjrSys_prm_agEndInjH1[1] = ((Float32)tiFuSp_B.VEMS_vidGET6_g[rt_MIN
      (localAdd_p, 5U)]) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, tiFuSp_B.VEMS_vidGET7_i);

    /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate'
     *
     * Regarding '<S50>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate'
     *
     * Regarding '<S51>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S50>/Add' incorporates:
     *  Constant: '<S50>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* MinMax: '<S50>/MinMax' incorporates:
     *  Constant: '<S50>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_p, 5U);

    /* Sum: '<S51>/Add' incorporates:
     *  Constant: '<S51>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* DataTypeConversion: '<S18>/Data Type Conversion4' incorporates:
     *  Constant: '<S51>/Constant'
     *  MinMax: '<S51>/MinMax'
     *  Selector: '<S50>/Selector'
     *  Selector: '<S51>/Selector'
     */
    InjrSys_prm_agEndInjH2[0] = ((Float32)tiFuSp_B.VEMS_vidGET7_i[(localmin)]) *
      0.0625F;
    InjrSys_prm_agEndInjH2[1] = ((Float32)tiFuSp_B.VEMS_vidGET7_i[rt_MIN
      (localAdd_p, 5U)]) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, tiFuSp_B.VEMS_vidGET2_l);

    /* DataTypeDuplicate Block: '<S19>/Data Type Duplicate'
     *
     * Regarding '<S19>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S47>/Data Type Duplicate'
     *
     * Regarding '<S47>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S47>/Add' incorporates:
     *  Constant: '<S47>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* Selector: '<S47>/Selector' incorporates:
     *  Constant: '<S47>/Constant'
     *  MinMax: '<S47>/MinMax'
     */
    localSelector_j = tiFuSp_B.VEMS_vidGET2_l[rt_MIN(localAdd_p, 5U)];

    /* DataTypeConversion: '<S18>/Data Type Conversion5' */
    InjrSys_agBegInjH1 = ((Float32)localSelector_j) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, tiFuSp_B.VEMS_vidGET8_k);

    /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate'
     *
     * Regarding '<S29>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate'
     *
     * Regarding '<S31>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S29>/Add' incorporates:
     *  Constant: '<S29>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* MinMax: '<S29>/MinMax' incorporates:
     *  Constant: '<S29>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_p, 5U);

    /* Sum: '<S31>/Add' incorporates:
     *  Constant: '<S31>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* DataTypeConversion: '<S18>/Data Type Conversion6' incorporates:
     *  Constant: '<S31>/Constant'
     *  MinMax: '<S31>/MinMax'
     *  Selector: '<S29>/Selector'
     *  Selector: '<S31>/Selector'
     */
    InjrSys_prm_agEndInjS1[0] = ((Float32)tiFuSp_B.VEMS_vidGET8_k[(localmin)]) *
      0.09375F;
    InjrSys_prm_agEndInjS1[1] = ((Float32)tiFuSp_B.VEMS_vidGET8_k[rt_MIN
      (localAdd_p, 5U)]) * 0.09375F;

    /* Sum: '<S19>/Add' incorporates:
     *  Constant: '<S19>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* DataTypeConversion: '<S18>/Data Type Conversion9' incorporates:
     *  Constant: '<S19>/Constant'
     *  MinMax: '<S19>/MinMax'
     *  Selector: '<S19>/Selector'
     */
    InjrSys_prm_agBegInjH1[0] = (UInt16)((((UInt32)localSelector_j) * 43691U)
      >> 16U);
    InjrSys_prm_agBegInjH1[1] = (UInt16)((((UInt32)
      tiFuSp_B.VEMS_vidGET2_l[rt_MIN(localAdd_p, 5U)]) * 43691U) >> 16U);

    /* MultiPortSwitch: '<S18>/Multiport Switch' incorporates:
     *  Constant: '<S18>/InjrSys_facCorInjETBCyl1_C'
     *  Constant: '<S18>/InjrSys_facCorInjETBCyl2_C'
     *  Constant: '<S18>/InjrSys_facCorInjETBCyl3_C'
     *  Constant: '<S18>/InjrSys_facCorInjETBCyl4_C'
     *  Constant: '<S18>/InjrSys_facCorInjETBCyl5_C'
     *  Constant: '<S18>/InjrSys_facCorInjETBCyl6_C'
     */
    switch ((UInt32)((SInt32)localAdd)) {
     case 1:
      locallocalMultiportSwitch_idx_0 = InjrSys_facCorInjETBCyl1_C;
      break;

     case 2:
      locallocalMultiportSwitch_idx_0 = InjrSys_facCorInjETBCyl2_C;
      break;

     case 3:
      locallocalMultiportSwitch_idx_0 = InjrSys_facCorInjETBCyl3_C;
      break;

     case 4:
      locallocalMultiportSwitch_idx_0 = InjrSys_facCorInjETBCyl4_C;
      break;

     case 5:
      locallocalMultiportSwitch_idx_0 = InjrSys_facCorInjETBCyl5_C;
      break;

     default:
      locallocalMultiportSwitch_idx_0 = InjrSys_facCorInjETBCyl6_C;
      break;
    }

    switch ((UInt32)((SInt32)localAdd_g)) {
     case 1:
      locallocalMultiportSwitch_idx = InjrSys_facCorInjETBCyl1_C;
      break;

     case 2:
      locallocalMultiportSwitch_idx = InjrSys_facCorInjETBCyl2_C;
      break;

     case 3:
      locallocalMultiportSwitch_idx = InjrSys_facCorInjETBCyl3_C;
      break;

     case 4:
      locallocalMultiportSwitch_idx = InjrSys_facCorInjETBCyl4_C;
      break;

     case 5:
      locallocalMultiportSwitch_idx = InjrSys_facCorInjETBCyl5_C;
      break;

     default:
      locallocalMultiportSwitch_idx = InjrSys_facCorInjETBCyl6_C;
      break;
    }

    /* Sum: '<S20>/Add' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* Selector: '<S20>/Selector' incorporates:
     *  Constant: '<S20>/Constant'
     *  MinMax: '<S20>/MinMax'
     */
    localSelector_j = tiFuSp_B.VEMS_vidGET10_c[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S27>/Add' incorporates:
     *  Constant: '<S27>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, tiFuSp_B.VEMS_vidGET4_f);

    /* DataTypeDuplicate Block: '<S27>/Data Type Duplicate'
     *
     * Regarding '<S27>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate'
     *
     * Regarding '<S28>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S27>/Selector' incorporates:
     *  Constant: '<S27>/Constant'
     *  MinMax: '<S27>/MinMax'
     */
    localSelector_jp = tiFuSp_B.VEMS_vidGET4_f[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S28>/Add' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* Selector: '<S28>/Selector' incorporates:
     *  Constant: '<S28>/Constant'
     *  MinMax: '<S28>/MinMax'
     */
    localSelector_ch = tiFuSp_B.VEMS_vidGET4_f[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S32>/Add' incorporates:
     *  Constant: '<S32>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, tiFuSp_B.VEMS_vidGET5_e);

    /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate'
     *
     * Regarding '<S32>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S33>/Data Type Duplicate'
     *
     * Regarding '<S33>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S32>/Selector' incorporates:
     *  Constant: '<S32>/Constant'
     *  MinMax: '<S32>/MinMax'
     */
    localSelector_g = tiFuSp_B.VEMS_vidGET5_e[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S33>/Add' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* Selector: '<S33>/Selector' incorporates:
     *  Constant: '<S33>/Constant'
     *  MinMax: '<S33>/MinMax'
     */
    localSelector_jk = tiFuSp_B.VEMS_vidGET5_e[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S34>/Add' incorporates:
     *  Constant: '<S34>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* Selector: '<S34>/Selector' incorporates:
     *  Constant: '<S34>/Constant'
     *  MinMax: '<S34>/MinMax'
     */
    localSelector_c = tiFuSp_B.VEMS_vidGET11_b[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S35>/Add' incorporates:
     *  Constant: '<S35>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* Selector: '<S35>/Selector' incorporates:
     *  Constant: '<S35>/Constant'
     *  MinMax: '<S35>/MinMax'
     */
    localSelector = tiFuSp_B.VEMS_vidGET11_b[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S36>/Add' incorporates:
     *  Constant: '<S36>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* Selector: '<S36>/Selector' incorporates:
     *  Constant: '<S36>/Constant'
     *  MinMax: '<S36>/MinMax'
     */
    localSelector_o = tiFuSp_B.VEMS_vidGET12_j[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S37>/Add' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* Selector: '<S37>/Selector' incorporates:
     *  Constant: '<S37>/Constant'
     *  MinMax: '<S37>/MinMax'
     */
    localSelector_l = tiFuSp_B.VEMS_vidGET12_j[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S38>/Add' incorporates:
     *  Constant: '<S38>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET17 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH1Cyl, 6, tiFuSp_B.VEMS_vidGET17_n);

    /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate'
     *
     * Regarding '<S38>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S38>/Selector' incorporates:
     *  Constant: '<S38>/Constant'
     *  MinMax: '<S38>/MinMax'
     */
    localSelector_dz = tiFuSp_B.VEMS_vidGET17_n[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S39>/Add' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    localAdd_p = localAdd - 1U;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET18 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH2Cyl, 6, tiFuSp_B.VEMS_vidGET18_b);

    /* DataTypeDuplicate Block: '<S39>/Data Type Duplicate'
     *
     * Regarding '<S39>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S39>/Selector' incorporates:
     *  Constant: '<S39>/Constant'
     *  MinMax: '<S39>/MinMax'
     */
    localSelector_i = tiFuSp_B.VEMS_vidGET18_b[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S40>/Add' incorporates:
     *  Constant: '<S40>/Constant1'
     */
    localAdd_p = localAdd_g - 1U;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET19 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS1Cyl, 6, tiFuSp_B.VEMS_vidGET19_c);

    /* DataTypeDuplicate Block: '<S40>/Data Type Duplicate'
     *
     * Regarding '<S40>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S40>/Selector' incorporates:
     *  Constant: '<S40>/Constant'
     *  MinMax: '<S40>/MinMax'
     */
    localSelector_i5 = tiFuSp_B.VEMS_vidGET19_c[rt_MIN(localAdd_p, 5U)];

    /* Sum: '<S42>/Add' incorporates:
     *  Constant: '<S42>/Constant1'
     */
    localAdd_g--;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET20 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS2Cyl, 6, tiFuSp_B.VEMS_vidGET20_m);

    /* DataTypeDuplicate Block: '<S42>/Data Type Duplicate'
     *
     * Regarding '<S42>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S42>/Selector' incorporates:
     *  Constant: '<S42>/Constant'
     *  MinMax: '<S42>/MinMax'
     */
    localSelector_je = tiFuSp_B.VEMS_vidGET20_m[rt_MIN(localAdd_g, 5U)];

    /* Sum: '<S52>/Add' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    localAdd--;

    /* SignalConversion: '<S18>/Signal Conversion1' */
    InjrSys_facCorInjETBCmpr = locallocalMultiportSwitch_idx;

    /* SignalConversion: '<S18>/Signal Conversion10' */
    InjrSys_prm_agBegInjS2[0] = localSelector_g;
    InjrSys_prm_agBegInjS2[1] = localSelector_jk;

    /* SignalConversion: '<S18>/Signal Conversion13' */
    InjrSys_prm_tiInjOfs[0] = localSelector_dz;
    InjrSys_prm_tiInjOfs[1] = localSelector_i;
    InjrSys_prm_tiInjOfs[2] = localSelector_i5;
    InjrSys_prm_tiInjOfs[3] = localSelector_je;
    InjrSys_prm_tiInjOfs[4] = localSelector_i5;
    InjrSys_prm_tiInjOfs[5] = localSelector_je;

    /* SignalConversion: '<S18>/Signal Conversion2' incorporates:
     *  Constant: '<S52>/Constant'
     *  MinMax: '<S52>/MinMax'
     *  Selector: '<S52>/Selector'
     */
    InjrSys_prm_mFuInjH2Req[0] = tiFuSp_B.VEMS_vidGET10_c[rt_MIN(localAdd, 5U)];
    InjrSys_prm_mFuInjH2Req[1] = localSelector_j;

    /* SignalConversion: '<S18>/Signal Conversion3' */
    InjrSys_prm_mFuInjS1Req[0] = localSelector_c;
    InjrSys_prm_mFuInjS1Req[1] = localSelector;

    /* SignalConversion: '<S18>/Signal Conversion4' */
    InjrSys_prm_mFuInjS2Req[0] = localSelector_o;
    InjrSys_prm_mFuInjS2Req[1] = localSelector_l;

    /* SignalConversion: '<S18>/Signal Conversion7' */
    InjrSys_facCorInjETBIn = locallocalMultiportSwitch_idx_0;

    /* SignalConversion: '<S18>/Signal Conversion8' */
    InjrSys_prm_agBegInjS1[0] = localSelector_jp;
    InjrSys_prm_agBegInjS1[1] = localSelector_ch;
  }

  /* end of Outputs for SubSystem: '<S16>/F00_tiFuSpSyncInEveClcn' */
}

/* Output and update for function-call system: '<S8>/F02_tiFuSpClcn' */
void tiFuSp_F02_tiFuSpClcn(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable2D[2];
  UInt16 localLookUpTable2D_l[2];
  Float32 localfrac;
  UInt32 localbpIndices[2];
  Float32 localfractions[2];
  Float32 localDataTypeConversion1_m;
  Float32 localDivide_a;
  Float32 localExt_pFuRailMes_InjrSys_pFu;
  Float32 localfractionTmp_0d;
  UInt32 localExt_pFuRailMes_InjrSys_p_d;
  Float32 localInterpolationUsingPrelo_jj;
  Float32 localDivide_co[6];
  SInt32 localSum1_m[6];
  UInt32 localOutDTConv_i[6];
  Boolean localMerge[6];
  SInt32 locali;
  Boolean locallocalRelationalOperator_h;
  Float32 locallocalDataTypeConversion6_m;
  SInt32 locallocalSum1_m;
  Float32 locallocalDataTypeConversion6_0;
  Float32 locallocalDataTypeConversion5_i;
  Float32 locallocalDataTypeConversion5_0;
  Float32 locallocalDataTypeConversion6_1;
  Float32 locallocalDataTypeConversion6_2;
  UInt32 locallocalOutDTConv_b;
  SInt16 localtmp;
  UInt16 localrtmax;
  UInt16 locallocalDataTypeConversion1_p;

  /* Outputs for enable SubSystem: '<S89>/F00_InjTi' incorporates:
   *  Constant: '<S89>/ConstVal'
   *  Constant: '<S89>/TIFUSP_u8Inhib'
   *  EnablePort: '<S90>/Enable'
   *  RelationalOperator: '<S89>/Relational Operator'
   */
  if (TIFUSP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_pDsThrMesSI, tiFuSp_B.VEMS_vidGET2);

    /* DataTypeDuplicate Block: '<S96>/Data Type Duplicate2'
     *
     * Regarding '<S96>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_nEng, tiFuSp_B.VEMS_vidGET1_h);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_pFuRailMes, tiFuSp_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET7 */
    VEMS_vidGET(InjrM_IdxInjrMdlInj, tiFuSp_B.VEMS_vidGET7_g);

    /* DataTypeDuplicate Block: '<S154>/Data Type Duplicate2'
     *
     * Regarding '<S154>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tiToothLen, tiFuSp_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bAcvSpcInjModOvlp, tiFuSp_B.VEMS_vidGET6_j);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET */
    VEMS_vidGET(EngM_agCkClsInVlvEstimRef1, tiFuSp_B.VEMS_vidGET_f);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET5 */
    VEMS_vidGET(IgCmd_agIgSp, tiFuSp_B.VEMS_vidGET5_l);

    /* If: '<S90>/If' incorporates:
     *  ActionPort: '<S91>/Action Port'
     *  ActionPort: '<S92>/Action Port'
     *  Constant: '<S90>/InjrSys_bAcvTiInjETB_C'
     *  SubSystem: '<S90>/F01_InjTiTest'
     *  SubSystem: '<S90>/F02_InjTinoTest'
     */
    if (InjrSys_bAcvTiInjETB_C) {
      /* DataTypeConversion: '<S91>/Data Type Conversion3' incorporates:
       *  Constant: '<S91>/InjrSys_rTiInjS2ETB_C'
       */
      localfractionTmp_0d = ((Float32)InjrSys_rTiInjS2ETB_C) *
        3.051757813E-005F;

      /* Switch: '<S113>/Switch2' incorporates:
       *  Constant: '<S91>/ConstVal_8'
       *  RelationalOperator: '<S113>/LowerRelop1'
       */
      if (localfractionTmp_0d > 1.0F) {
        localfractionTmp_0d = 1.0F;
      }

      /* Sum: '<S91>/Add1' incorporates:
       *  Constant: '<S91>/ConstVal_4'
       */
      localInterpolationUsingPrelo_jj = 1.0F - localfractionTmp_0d;

      /* DataTypeConversion: '<S91>/Data Type Conversion1' incorporates:
       *  Constant: '<S91>/InjrSys_rTiInjS1ETB_C'
       */
      localDataTypeConversion1_m = ((Float32)InjrSys_rTiInjS1ETB_C) *
        3.051757813E-005F;

      /* Switch: '<S107>/Switch2' incorporates:
       *  RelationalOperator: '<S107>/LowerRelop1'
       */
      if (localDataTypeConversion1_m > localInterpolationUsingPrelo_jj) {
        localDataTypeConversion1_m = localInterpolationUsingPrelo_jj;
      }

      /* Sum: '<S91>/Add3' */
      localInterpolationUsingPrelo_jj -= localDataTypeConversion1_m;

      /* DataTypeConversion: '<S91>/Data Type Conversion2' incorporates:
       *  Constant: '<S91>/InjrSys_rTiInjH2ETB_C'
       */
      localDivide_a = ((Float32)InjrSys_rTiInjH2ETB_C) * 3.051757813E-005F;

      /* Switch: '<S110>/Switch2' incorporates:
       *  RelationalOperator: '<S110>/LowerRelop1'
       */
      if (!(localDivide_a > localInterpolationUsingPrelo_jj)) {
        localInterpolationUsingPrelo_jj = localDivide_a;
      }

      /* Sum: '<S91>/Add2' incorporates:
       *  Constant: '<S91>/ConstVal_10'
       */
      locallocalDataTypeConversion6_1 = ((1.0F - localInterpolationUsingPrelo_jj)
        - localDataTypeConversion1_m) - localfractionTmp_0d;

      /* DataTypeConversion: '<S91>/Data Type Conversion7' */
      localDivide_a = ((Float32)InjrSys_facCorInjETBCmpr) * 0.0078125F;

      /* DataTypeConversion: '<S91>/Data Type Conversion8' */
      locallocalDataTypeConversion6_0 = ((Float32)InjrSys_facCorInjETBIn) *
        0.0078125F;

      /* Lookup_n-D: '<S96>/Lookup Table (n-D)' */
      locallocalDataTypeConversion6_m = look2_1fcv2bcvbcvbfbba5nfbbnx
        (tiFuSp_B.VEMS_vidGET1_h, tiFuSp_B.VEMS_vidGET2, (&(Ext_nEngX_A[0])),
         (&(Ext_pDsThrMesSIY_A[0])), (&(InjrSys_tiInjTotETB_M[0])),
         &tiFuSp_ConstP.pooled10[0], 16U);

      /* MultiPortSwitch: '<S91>/Multiport Switch' incorporates:
       *  Constant: '<S91>/InjrSys_noETBSelMassFuReq_C'
       *  Constant: '<S91>/InjrSys_tiInjTotETB_C'
       *  DataTypeConversion: '<S91>/Data Type Conversion5'
       */
      if (InjrSys_noETBSelMassFuReq_C == 0) {
        locallocalDataTypeConversion6_m = ((Float32)InjrSys_tiInjTotETB_C) *
          3.200000037E-006F;
      }

      /* Product: '<S100>/Divide' */
      localDataTypeConversion1_m *= locallocalDataTypeConversion6_m;

      /* Product: '<S101>/Divide' */
      localfractionTmp_0d *= locallocalDataTypeConversion6_m;

      /* Product: '<S103>/Divide' */
      locallocalDataTypeConversion5_i = localDataTypeConversion1_m *
        localDivide_a;
      locallocalDataTypeConversion5_0 = localfractionTmp_0d * localDivide_a;

      /* Product: '<S102>/Divide' */
      localDivide_a = locallocalDataTypeConversion6_m *
        locallocalDataTypeConversion6_1;

      /* Product: '<S99>/Divide' */
      locallocalDataTypeConversion6_m *= localInterpolationUsingPrelo_jj;

      /* Product: '<S104>/Divide' */
      locallocalDataTypeConversion6_1 = localDivide_a *
        locallocalDataTypeConversion6_0;
      locallocalDataTypeConversion6_2 = locallocalDataTypeConversion6_m *
        locallocalDataTypeConversion6_0;

      /* RelationalOperator: '<S91>/Relational Operator2' incorporates:
       *  Constant: '<S91>/InjrSys_tiInjMin_C'
       *  Constant: '<S91>/InjrSys_tiInjMin_C_2'
       *  Constant: '<S91>/InjrSys_tiInjMin_C_3'
       *  Constant: '<S97>/offset'
       *  Constant: '<S97>/offset1'
       *  Constant: '<S97>/one_on_slope'
       *  Constant: '<S98>/offset'
       *  Constant: '<S98>/offset1'
       *  Constant: '<S98>/one_on_slope'
       *  DataTypeConversion: '<S97>/OutDTConv'
       *  DataTypeConversion: '<S98>/OutDTConv'
       *  MinMax: '<S91>/MinMax1'
       *  MinMax: '<S91>/MinMax4'
       *  Product: '<S97>/Product4'
       *  Product: '<S98>/Product4'
       *  Sum: '<S97>/Add1'
       *  Sum: '<S97>/Add2'
       *  Sum: '<S98>/Add1'
       *  Sum: '<S98>/Add2'
       */
      locallocalDataTypeConversion6_m = (312500.0F *
        locallocalDataTypeConversion5_i) + 0.5F;
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_m;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      if (InjrSys_tiInjMin_C > locallocalDataTypeConversion1_p) {
        locallocalDataTypeConversion1_p = InjrSys_tiInjMin_C;
      }

      locallocalDataTypeConversion6_m = (312500.0F *
        locallocalDataTypeConversion6_1) + 0.5F;
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          localrtmax = (UInt16)locallocalDataTypeConversion6_m;
        } else {
          localrtmax = 0U;
        }
      } else {
        localrtmax = MAX_uint16_T;
      }

      if (InjrSys_tiInjMin_C > localrtmax) {
        localrtmax = InjrSys_tiInjMin_C;
      }

      /* Switch: '<S91>/Switch4' incorporates:
       *  Constant: '<S91>/ConstVal_2'
       *  Constant: '<S91>/ConstVal_3'
       *  RelationalOperator: '<S91>/Relational Operator5'
       */
      if (locallocalDataTypeConversion6_1 > 0.0F) {
        locali = localrtmax;
      } else {
        locali = 0;
      }

      /* Switch: '<S91>/Switch1' incorporates:
       *  Constant: '<S91>/ConstVal'
       *  Constant: '<S91>/ConstVal_1'
       *  RelationalOperator: '<S91>/Relational Operator1'
       */
      if (locallocalDataTypeConversion5_i > 0.0F) {
        localbpIndices[0] = locallocalDataTypeConversion1_p;
      } else {
        localbpIndices[0] = 0U;
      }

      localMerge[0] = (((UInt32)locali) == ((UInt32)InjrSys_tiInjMin_C));
      locallocalSum1_m = locali;
      locallocalDataTypeConversion6_m = (312500.0F *
        locallocalDataTypeConversion5_0) + 0.5F;
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_m;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      if (InjrSys_tiInjMin_C > locallocalDataTypeConversion1_p) {
        locallocalDataTypeConversion1_p = InjrSys_tiInjMin_C;
      }

      locallocalDataTypeConversion6_m = (312500.0F *
        locallocalDataTypeConversion6_2) + 0.5F;
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          localrtmax = (UInt16)locallocalDataTypeConversion6_m;
        } else {
          localrtmax = 0U;
        }
      } else {
        localrtmax = MAX_uint16_T;
      }

      if (InjrSys_tiInjMin_C > localrtmax) {
        localrtmax = InjrSys_tiInjMin_C;
      }

      /* Switch: '<S91>/Switch4' incorporates:
       *  Constant: '<S91>/ConstVal_2'
       *  Constant: '<S91>/ConstVal_3'
       *  RelationalOperator: '<S91>/Relational Operator5'
       */
      if (locallocalDataTypeConversion6_2 > 0.0F) {
        locali = localrtmax;
      } else {
        locali = 0;
      }

      /* Switch: '<S91>/Switch1' incorporates:
       *  Constant: '<S91>/ConstVal'
       *  Constant: '<S91>/ConstVal_1'
       *  RelationalOperator: '<S91>/Relational Operator1'
       */
      if (locallocalDataTypeConversion5_0 > 0.0F) {
        localbpIndices[1] = locallocalDataTypeConversion1_p;
      } else {
        localbpIndices[1] = 0U;
      }

      localMerge[1] = (((UInt32)locali) == ((UInt32)InjrSys_tiInjMin_C));
      localMerge[2] = (localbpIndices[0] == ((UInt32)InjrSys_tiInjMin_C));
      localMerge[3] = (localbpIndices[1] == ((UInt32)InjrSys_tiInjMin_C));

      /* SignalConversion: '<S91>/Signal Conversion1' */
      localMerge[4] = (localbpIndices[0] == ((UInt32)InjrSys_tiInjMin_C));
      InjrSys_prm_tiInjReq[0] = (UInt32)locallocalSum1_m;
      localMerge[5] = (localbpIndices[1] == ((UInt32)InjrSys_tiInjMin_C));
      InjrSys_prm_tiInjReq[1] = (UInt32)locali;
      InjrSys_prm_tiInjReq[2] = localbpIndices[0];
      InjrSys_prm_tiInjReq[3] = localbpIndices[1];
      InjrSys_prm_tiInjReq[4] = localbpIndices[0];
      InjrSys_prm_tiInjReq[5] = localbpIndices[1];
      for (locali = 0; locali < 6; locali++) {
        /* SignalConversion: '<S91>/Signal Conversion2' */
        InjrSys_prm_facGainCor[(locali)] = InjrSys_prm_facGain[(locali)];

        /* SignalConversion: '<S91>/Signal Conversion3' */
        InjrSys_prm_tiInjOfsCor[(locali)] = InjrSys_prm_tiInjOfs[(locali)];
      }
    } else {
      /* Outputs for atomic SubSystem: '<S92>/F01_tiOfsCorClcn' *
       * Block requirements for '<S92>/F01_tiOfsCorClcn':
       *  1. SubSystem "F01_tiOfsCorClcn" !Trace_To : VEMS_E_11_01980_001.01 ;
       */

      /* PreLookup: '<S120>/Prelookup' */
      localExt_pFuRailMes_InjrSys_p_d = plook_u32u16f_binc(tiFuSp_B.VEMS_vidGET3,
        (&(InjrSys_pFuRailMes_A[0])), 15U, &localExt_pFuRailMes_InjrSys_pFu);

      /* Outputs for atomic SubSystem: '<S114>/F01_InjH2CorClcn' */

      /* DataTypeConversion: '<S116>/Data Type Conversion1' */
      localDataTypeConversion1_m = ((Float32)tiFuSp_B.VEMS_vidGET4) *
        3.200000037E-006F;

      /* DataTypeConversion: '<S116>/Data Type Conversion2' incorporates:
       *  Constant: '<S116>/Ext_agWdTooth_SC'
       */
      localDivide_a = (Float32)Ext_agWdTooth_SC;

      /* DataTypeConversion: '<S116>/Data Type Conversion5' */
      locallocalDataTypeConversion5_i = ((Float32)InjrSys_prm_agBegInjH1[0]) *
        0.09375F;

      /* DataTypeConversion: '<S116>/Data Type Conversion6' */
      locallocalDataTypeConversion6_1 = ((Float32)InjrSys_prm_agBegInjH2[0]) *
        0.09375F;

      /* DataTypeConversion: '<S116>/Data Type Conversion5' */
      locallocalDataTypeConversion5_0 = ((Float32)InjrSys_prm_agBegInjH1[1]) *
        0.09375F;

      /* DataTypeConversion: '<S116>/Data Type Conversion6' */
      locallocalDataTypeConversion6_2 = ((Float32)InjrSys_prm_agBegInjH2[1]) *
        0.09375F;

      /* Interpolation_n-D: '<S121>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_pFuRailMes_InjrSys_pFu;
      localInterpolationUsingPrelo_jj = intrp1d_iu8n7ff_u32f_l_ns
        (localExt_pFuRailMes_InjrSys_p_d, localfractionTmp_0d,
         (&(InjrSys_tiOfsH2CorPFu_T[0])));

      /* Product: '<S126>/Divide' */
      localDivide_a = localDataTypeConversion1_m / localDivide_a;

      /* end of Outputs for SubSystem: '<S114>/F01_InjH2CorClcn' */

      /* Outputs for atomic SubSystem: '<S114>/F02_InjS1CorClcn' */

      /* Product: '<S136>/Divide' incorporates:
       *  Constant: '<S117>/Ext_agWdTooth_SC'
       *  DataTypeConversion: '<S117>/Data Type Conversion1'
       *  DataTypeConversion: '<S117>/Data Type Conversion8'
       */
      localDataTypeConversion1_m = (((Float32)tiFuSp_B.VEMS_vidGET4) *
        3.200000037E-006F) / ((Float32)Ext_agWdTooth_SC);

      /* DataTypeConversion: '<S123>/OutDTConv' incorporates:
       *  Constant: '<S123>/offset'
       *  Constant: '<S123>/offset1'
       *  Constant: '<S123>/one_on_slope'
       *  Product: '<S123>/Product4'
       *  Product: '<S128>/Divide'
       *  Sum: '<S116>/Sum1'
       *  Sum: '<S123>/Add1'
       *  Sum: '<S123>/Add2'
       */
      locallocalDataTypeConversion6_m = (((locallocalDataTypeConversion5_i -
        InjrSys_prm_agEndInjH1[0]) * localDivide_a) * 312500.0F) + 0.5F;
      if (locallocalDataTypeConversion6_m < 4.294967296E+009F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_m;
        } else {
          locallocalOutDTConv_b = 0U;
        }
      } else {
        locallocalOutDTConv_b = MAX_uint32_T;
      }

      /* Sum: '<S125>/Add2' incorporates:
       *  Constant: '<S125>/offset'
       *  Constant: '<S125>/offset1'
       *  Constant: '<S125>/one_on_slope'
       *  Product: '<S125>/Product4'
       *  Product: '<S127>/Divide'
       *  Sum: '<S116>/Sum2'
       *  Sum: '<S125>/Add1'
       */
      locallocalDataTypeConversion6_m = (((InjrSys_prm_agEndInjH1[0] -
        locallocalDataTypeConversion6_1) * localDivide_a) * 312500.0F) + 0.5F;

      /* DataTypeConversion: '<S125>/OutDTConv' */
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_m;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      InjrSys_prm_tiWoutInjPrevH2[0] = locallocalDataTypeConversion1_p;

      /* RelationalOperator: '<S116>/Relational Operator' incorporates:
       *  Constant: '<S116>/ConstVal'
       */
      locallocalRelationalOperator_h = (InjrSys_prm_mFuInjH2Req[0] > 0);

      /* Product: '<S124>/Product4' incorporates:
       *  Constant: '<S124>/offset'
       *  Constant: '<S124>/one_on_slope'
       *  Lookup_n-D: '<S122>/Lookup Table (n-D)'
       *  Product: '<S129>/Divide'
       *  Sum: '<S124>/Add1'
       */
      locallocalDataTypeConversion6_m = (look2_1hcwlbcvbcvbfbbt5nfbbnx
        (locallocalOutDTConv_b, InjrSys_prm_tiWoutInjPrevH2[0],
         (&(InjrSys_tiInj_A[0])), (&(InjrSys_tiBtwnInj_A[0])),
         (&(InjrSys_tiOfsH2Cor_M[0])), &tiFuSp_ConstP.pooled10[0], 16U) *
        localInterpolationUsingPrelo_jj) * 312500.0F;

      /* Switch: '<S124>/Switch1' incorporates:
       *  Constant: '<S124>/offset2'
       *  Constant: '<S124>/offset3'
       *  Constant: '<S124>/offset4'
       *  RelationalOperator: '<S124>/Relational Operator'
       *  Sum: '<S124>/Add3'
       *  Sum: '<S124>/Add4'
       */
      if (locallocalDataTypeConversion6_m >= 0.0F) {
        locallocalDataTypeConversion6_m += 0.5F;
      } else {
        locallocalDataTypeConversion6_m -= 0.5F;
      }

      /* Switch: '<S116>/Switch' incorporates:
       *  Constant: '<S116>/ConstVal_2'
       *  DataTypeConversion: '<S124>/OutDTConv'
       */
      if (locallocalRelationalOperator_h) {
        if (locallocalDataTypeConversion6_m < 32768.0F) {
          if (locallocalDataTypeConversion6_m >= -32768.0F) {
            localtmp = (SInt16)locallocalDataTypeConversion6_m;
          } else {
            localtmp = MIN_int16_T;
          }
        } else {
          localtmp = MAX_int16_T;
        }

        InjrSys_prm_tiOfsH2Cor[0] = localtmp;
      } else {
        InjrSys_prm_tiOfsH2Cor[0] = 0;
      }

      /* Switch: '<S116>/Switch1' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agBegInjS1Prev[0] = InjrSys_prm_agBegInjH2[0];
      } else {
        InjrSys_prm_agBegInjS1Prev[0] = InjrSys_prm_agBegInjH1[0];
      }

      /* Switch: '<S116>/Switch2' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agEndInjS1Prev[0] = InjrSys_prm_agEndInjH2[0];
      } else {
        InjrSys_prm_agEndInjS1Prev[0] = InjrSys_prm_agEndInjH1[0];
      }

      /* DataTypeConversion: '<S135>/OutDTConv' incorporates:
       *  Constant: '<S135>/offset'
       *  Constant: '<S135>/offset1'
       *  Constant: '<S135>/one_on_slope'
       *  DataTypeConversion: '<S117>/Data Type Conversion7'
       *  Product: '<S135>/Product4'
       *  Product: '<S137>/Divide'
       *  Sum: '<S117>/Sum3'
       *  Sum: '<S135>/Add1'
       *  Sum: '<S135>/Add2'
       */
      locallocalDataTypeConversion6_0 = (((InjrSys_prm_agEndInjS1Prev[0] -
        (((Float32)InjrSys_prm_agBegInjS1[0]) * 0.09375F)) *
        localDataTypeConversion1_m) * 312500.0F) + 0.5F;
      if (locallocalDataTypeConversion6_0 < 65536.0F) {
        if (locallocalDataTypeConversion6_0 >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_0;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      InjrSys_prm_tiWoutInjPrevS1[0] = locallocalDataTypeConversion1_p;

      /* DataTypeConversion: '<S123>/OutDTConv' incorporates:
       *  Constant: '<S123>/offset'
       *  Constant: '<S123>/offset1'
       *  Constant: '<S123>/one_on_slope'
       *  Product: '<S123>/Product4'
       *  Product: '<S128>/Divide'
       *  Sum: '<S116>/Sum1'
       *  Sum: '<S123>/Add1'
       *  Sum: '<S123>/Add2'
       */
      locallocalDataTypeConversion6_m = (((locallocalDataTypeConversion5_0 -
        InjrSys_prm_agEndInjH1[1]) * localDivide_a) * 312500.0F) + 0.5F;
      if (locallocalDataTypeConversion6_m < 4.294967296E+009F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_m;
        } else {
          locallocalOutDTConv_b = 0U;
        }
      } else {
        locallocalOutDTConv_b = MAX_uint32_T;
      }

      /* Sum: '<S125>/Add2' incorporates:
       *  Constant: '<S125>/offset'
       *  Constant: '<S125>/offset1'
       *  Constant: '<S125>/one_on_slope'
       *  Product: '<S125>/Product4'
       *  Product: '<S127>/Divide'
       *  Sum: '<S116>/Sum2'
       *  Sum: '<S125>/Add1'
       */
      locallocalDataTypeConversion6_m = (((InjrSys_prm_agEndInjH1[1] -
        locallocalDataTypeConversion6_2) * localDivide_a) * 312500.0F) + 0.5F;

      /* DataTypeConversion: '<S125>/OutDTConv' */
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_m;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      InjrSys_prm_tiWoutInjPrevH2[1] = locallocalDataTypeConversion1_p;

      /* RelationalOperator: '<S116>/Relational Operator' incorporates:
       *  Constant: '<S116>/ConstVal'
       */
      locallocalRelationalOperator_h = (InjrSys_prm_mFuInjH2Req[1] > 0);

      /* Product: '<S124>/Product4' incorporates:
       *  Constant: '<S124>/offset'
       *  Constant: '<S124>/one_on_slope'
       *  Lookup_n-D: '<S122>/Lookup Table (n-D)'
       *  Product: '<S129>/Divide'
       *  Sum: '<S124>/Add1'
       */
      locallocalDataTypeConversion6_m = (look2_1hcwlbcvbcvbfbbt5nfbbnx
        (locallocalOutDTConv_b, InjrSys_prm_tiWoutInjPrevH2[1],
         (&(InjrSys_tiInj_A[0])), (&(InjrSys_tiBtwnInj_A[0])),
         (&(InjrSys_tiOfsH2Cor_M[0])), &tiFuSp_ConstP.pooled10[0], 16U) *
        localInterpolationUsingPrelo_jj) * 312500.0F;

      /* Switch: '<S124>/Switch1' incorporates:
       *  Constant: '<S124>/offset2'
       *  Constant: '<S124>/offset3'
       *  Constant: '<S124>/offset4'
       *  RelationalOperator: '<S124>/Relational Operator'
       *  Sum: '<S124>/Add3'
       *  Sum: '<S124>/Add4'
       */
      if (locallocalDataTypeConversion6_m >= 0.0F) {
        locallocalDataTypeConversion6_m += 0.5F;
      } else {
        locallocalDataTypeConversion6_m -= 0.5F;
      }

      /* Switch: '<S116>/Switch' incorporates:
       *  Constant: '<S116>/ConstVal_2'
       *  DataTypeConversion: '<S124>/OutDTConv'
       */
      if (locallocalRelationalOperator_h) {
        if (locallocalDataTypeConversion6_m < 32768.0F) {
          if (locallocalDataTypeConversion6_m >= -32768.0F) {
            localtmp = (SInt16)locallocalDataTypeConversion6_m;
          } else {
            localtmp = MIN_int16_T;
          }
        } else {
          localtmp = MAX_int16_T;
        }

        InjrSys_prm_tiOfsH2Cor[1] = localtmp;
      } else {
        InjrSys_prm_tiOfsH2Cor[1] = 0;
      }

      /* Switch: '<S116>/Switch1' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agBegInjS1Prev[1] = InjrSys_prm_agBegInjH2[1];
      } else {
        InjrSys_prm_agBegInjS1Prev[1] = InjrSys_prm_agBegInjH1[1];
      }

      /* Switch: '<S116>/Switch2' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agEndInjS1Prev[1] = InjrSys_prm_agEndInjH2[1];
      } else {
        InjrSys_prm_agEndInjS1Prev[1] = InjrSys_prm_agEndInjH1[1];
      }

      /* DataTypeConversion: '<S135>/OutDTConv' incorporates:
       *  Constant: '<S135>/offset'
       *  Constant: '<S135>/offset1'
       *  Constant: '<S135>/one_on_slope'
       *  DataTypeConversion: '<S117>/Data Type Conversion7'
       *  Product: '<S135>/Product4'
       *  Product: '<S137>/Divide'
       *  Sum: '<S117>/Sum3'
       *  Sum: '<S135>/Add1'
       *  Sum: '<S135>/Add2'
       */
      locallocalDataTypeConversion6_m = (((InjrSys_prm_agEndInjS1Prev[1] -
        (((Float32)InjrSys_prm_agBegInjS1[1]) * 0.09375F)) *
        localDataTypeConversion1_m) * 312500.0F) + 0.5F;
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_m;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      InjrSys_prm_tiWoutInjPrevS1[1] = locallocalDataTypeConversion1_p;

      /* Lookup2D: '<S130>/Look-Up Table (2-D)'
       * About '<S130>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    S16  2^-19  FSlope 1.6777216
       * Input1  Data Type:  Fixed Point    U16  2^-19  FSlope 1.6777216
       * Output0 Data Type:  Fixed Point    U16  2^-19  FSlope 1.6777216  Bias -0.1048576
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_S16_U16( &(localLookUpTable2D_l[0]), (&(InjrSys_tiOfsS1CorH2_M
        [0])), InjrSys_prm_tiOfsH2Cor[0], (&(InjrSys_tiOfsCor_A[0])), 15U,
                         InjrSys_prm_tiWoutInjPrevS1[0], (&(InjrSys_tiBtwnInj_A
        [0])), 15U);
      Look2D_U16_S16_U16( &(localLookUpTable2D_l[1]), (&(InjrSys_tiOfsS1CorH2_M
        [0])), InjrSys_prm_tiOfsH2Cor[1], (&(InjrSys_tiOfsCor_A[0])), 15U,
                         InjrSys_prm_tiWoutInjPrevS1[1], (&(InjrSys_tiBtwnInj_A
        [0])), 15U);

      /* DataTypeDuplicate Block: '<S130>/Data Type Duplicate2'
       *
       * Regarding '<S130>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S117>/Data Type Conversion2' incorporates:
       *  Lookup2D: '<S130>/Look-Up Table (2-D)'
       */
      locallocalDataTypeConversion5_i = (((Float32)localLookUpTable2D_l[0]) *
        3.200000037E-006F) - 1.048576012E-001F;

      /* DataTypeConversion: '<S117>/Data Type Conversion6' */
      locallocalDataTypeConversion6_1 = ((Float32)InjrSys_prm_agBegInjS1Prev[0])
        * 0.09375F;

      /* DataTypeConversion: '<S117>/Data Type Conversion2' incorporates:
       *  Lookup2D: '<S130>/Look-Up Table (2-D)'
       */
      locallocalDataTypeConversion5_0 = (((Float32)localLookUpTable2D_l[1]) *
        3.200000037E-006F) - 1.048576012E-001F;

      /* DataTypeConversion: '<S117>/Data Type Conversion6' */
      locallocalDataTypeConversion6_2 = ((Float32)InjrSys_prm_agBegInjS1Prev[1])
        * 0.09375F;

      /* Interpolation_n-D: '<S131>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_pFuRailMes_InjrSys_pFu;
      localInterpolationUsingPrelo_jj = intrp1d_iu8n7ff_u32f_l_ns
        (localExt_pFuRailMes_InjrSys_p_d, localfractionTmp_0d,
         (&(InjrSys_tiOfsS1CorPFu_T[0])));

      /* Sum: '<S133>/Add2' incorporates:
       *  Constant: '<S133>/offset'
       *  Constant: '<S133>/offset1'
       *  Constant: '<S133>/one_on_slope'
       *  Product: '<S133>/Product4'
       *  Product: '<S139>/Divide'
       *  Sum: '<S117>/Sum1'
       *  Sum: '<S133>/Add1'
       */
      locallocalDataTypeConversion6_0 = (((locallocalDataTypeConversion6_1 -
        InjrSys_prm_agEndInjS1Prev[0]) * localDataTypeConversion1_m) * 312500.0F)
        + 0.5F;

      /* DataTypeConversion: '<S133>/OutDTConv' */
      if (locallocalDataTypeConversion6_0 < 4.294967296E+009F) {
        if (locallocalDataTypeConversion6_0 >= 0.0F) {
          locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_0;
        } else {
          locallocalOutDTConv_b = 0U;
        }
      } else {
        locallocalOutDTConv_b = MAX_uint32_T;
      }

      /* RelationalOperator: '<S117>/Relational Operator' incorporates:
       *  Constant: '<S117>/ConstVal'
       */
      locallocalRelationalOperator_h = (InjrSys_prm_mFuInjS1Req[0] > 0);

      /* Product: '<S134>/Product4' incorporates:
       *  Constant: '<S134>/offset'
       *  Constant: '<S134>/one_on_slope'
       *  Lookup_n-D: '<S132>/Lookup Table (n-D)'
       *  Product: '<S138>/Divide'
       *  Sum: '<S117>/Sum2'
       *  Sum: '<S134>/Add1'
       */
      locallocalDataTypeConversion6_0 = ((look2_1hcwlbcvbcvbfbbt5nfbbnx
        (locallocalOutDTConv_b, InjrSys_prm_tiWoutInjPrevS1[0],
         (&(InjrSys_tiInj_A[0])), (&(InjrSys_tiBtwnInj_A[0])),
         (&(InjrSys_tiOfsS1Cor_M[0])), &tiFuSp_ConstP.pooled10[0], 16U) +
        locallocalDataTypeConversion5_i) * localInterpolationUsingPrelo_jj) *
        312500.0F;

      /* Switch: '<S134>/Switch1' incorporates:
       *  Constant: '<S134>/offset2'
       *  Constant: '<S134>/offset3'
       *  Constant: '<S134>/offset4'
       *  RelationalOperator: '<S134>/Relational Operator'
       *  Sum: '<S134>/Add3'
       *  Sum: '<S134>/Add4'
       */
      if (locallocalDataTypeConversion6_0 >= 0.0F) {
        locallocalDataTypeConversion6_0 += 0.5F;
      } else {
        locallocalDataTypeConversion6_0 -= 0.5F;
      }

      /* Switch: '<S117>/Switch' incorporates:
       *  Constant: '<S117>/ConstVal_2'
       *  DataTypeConversion: '<S134>/OutDTConv'
       */
      if (locallocalRelationalOperator_h) {
        if (locallocalDataTypeConversion6_0 < 32768.0F) {
          if (locallocalDataTypeConversion6_0 >= -32768.0F) {
            localtmp = (SInt16)locallocalDataTypeConversion6_0;
          } else {
            localtmp = MIN_int16_T;
          }
        } else {
          localtmp = MAX_int16_T;
        }

        InjrSys_prm_tiOfsS1Cor[0] = localtmp;
      } else {
        InjrSys_prm_tiOfsS1Cor[0] = 0;
      }

      /* Switch: '<S117>/Switch1' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agBegInjS2Prev[0] = InjrSys_prm_agBegInjS1[0];
      } else {
        InjrSys_prm_agBegInjS2Prev[0] = InjrSys_prm_agBegInjS1Prev[0];
      }

      /* Switch: '<S117>/Switch2' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agEndInjS2Prev[0] = InjrSys_prm_agEndInjS1[0];
      } else {
        InjrSys_prm_agEndInjS2Prev[0] = InjrSys_prm_agEndInjS1Prev[0];
      }

      /* Switch: '<S117>/Switch3' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_tiOfsS2CorPrev[0] = InjrSys_prm_tiOfsS1Cor[0];
      } else {
        InjrSys_prm_tiOfsS2CorPrev[0] = InjrSys_prm_tiOfsH2Cor[0];
      }

      /* Sum: '<S133>/Add2' incorporates:
       *  Constant: '<S133>/offset'
       *  Constant: '<S133>/offset1'
       *  Constant: '<S133>/one_on_slope'
       *  Product: '<S133>/Product4'
       *  Product: '<S139>/Divide'
       *  Sum: '<S117>/Sum1'
       *  Sum: '<S133>/Add1'
       */
      locallocalDataTypeConversion6_0 = (((locallocalDataTypeConversion6_2 -
        InjrSys_prm_agEndInjS1Prev[1]) * localDataTypeConversion1_m) * 312500.0F)
        + 0.5F;

      /* DataTypeConversion: '<S133>/OutDTConv' */
      if (locallocalDataTypeConversion6_0 < 4.294967296E+009F) {
        if (locallocalDataTypeConversion6_0 >= 0.0F) {
          locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_0;
        } else {
          locallocalOutDTConv_b = 0U;
        }
      } else {
        locallocalOutDTConv_b = MAX_uint32_T;
      }

      /* RelationalOperator: '<S117>/Relational Operator' incorporates:
       *  Constant: '<S117>/ConstVal'
       */
      locallocalRelationalOperator_h = (InjrSys_prm_mFuInjS1Req[1] > 0);

      /* Product: '<S134>/Product4' incorporates:
       *  Constant: '<S134>/offset'
       *  Constant: '<S134>/one_on_slope'
       *  Lookup_n-D: '<S132>/Lookup Table (n-D)'
       *  Product: '<S138>/Divide'
       *  Sum: '<S117>/Sum2'
       *  Sum: '<S134>/Add1'
       */
      locallocalDataTypeConversion6_0 = ((look2_1hcwlbcvbcvbfbbt5nfbbnx
        (locallocalOutDTConv_b, InjrSys_prm_tiWoutInjPrevS1[1],
         (&(InjrSys_tiInj_A[0])), (&(InjrSys_tiBtwnInj_A[0])),
         (&(InjrSys_tiOfsS1Cor_M[0])), &tiFuSp_ConstP.pooled10[0], 16U) +
        locallocalDataTypeConversion5_0) * localInterpolationUsingPrelo_jj) *
        312500.0F;

      /* Switch: '<S134>/Switch1' incorporates:
       *  Constant: '<S134>/offset2'
       *  Constant: '<S134>/offset3'
       *  Constant: '<S134>/offset4'
       *  RelationalOperator: '<S134>/Relational Operator'
       *  Sum: '<S134>/Add3'
       *  Sum: '<S134>/Add4'
       */
      if (locallocalDataTypeConversion6_0 >= 0.0F) {
        locallocalDataTypeConversion6_0 += 0.5F;
      } else {
        locallocalDataTypeConversion6_0 -= 0.5F;
      }

      /* Switch: '<S117>/Switch' incorporates:
       *  Constant: '<S117>/ConstVal_2'
       *  DataTypeConversion: '<S134>/OutDTConv'
       */
      if (locallocalRelationalOperator_h) {
        if (locallocalDataTypeConversion6_0 < 32768.0F) {
          if (locallocalDataTypeConversion6_0 >= -32768.0F) {
            localtmp = (SInt16)locallocalDataTypeConversion6_0;
          } else {
            localtmp = MIN_int16_T;
          }
        } else {
          localtmp = MAX_int16_T;
        }

        InjrSys_prm_tiOfsS1Cor[1] = localtmp;
      } else {
        InjrSys_prm_tiOfsS1Cor[1] = 0;
      }

      /* Switch: '<S117>/Switch1' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agBegInjS2Prev[1] = InjrSys_prm_agBegInjS1[1];
      } else {
        InjrSys_prm_agBegInjS2Prev[1] = InjrSys_prm_agBegInjS1Prev[1];
      }

      /* Switch: '<S117>/Switch2' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_agEndInjS2Prev[1] = InjrSys_prm_agEndInjS1[1];
      } else {
        InjrSys_prm_agEndInjS2Prev[1] = InjrSys_prm_agEndInjS1Prev[1];
      }

      /* Switch: '<S117>/Switch3' */
      if (locallocalRelationalOperator_h) {
        InjrSys_prm_tiOfsS2CorPrev[1] = InjrSys_prm_tiOfsS1Cor[1];
      } else {
        InjrSys_prm_tiOfsS2CorPrev[1] = InjrSys_prm_tiOfsH2Cor[1];
      }

      /* end of Outputs for SubSystem: '<S114>/F02_InjS1CorClcn' */

      /* Outputs for atomic SubSystem: '<S114>/F03_InjS2CorClcn' */

      /* Product: '<S146>/Divide' incorporates:
       *  Constant: '<S118>/Ext_agWdTooth_SC'
       *  DataTypeConversion: '<S118>/Data Type Conversion1'
       *  DataTypeConversion: '<S118>/Data Type Conversion2'
       */
      localInterpolationUsingPrelo_jj = (((Float32)tiFuSp_B.VEMS_vidGET4) *
        3.200000037E-006F) / ((Float32)Ext_agWdTooth_SC);

      /* DataTypeConversion: '<S145>/OutDTConv' incorporates:
       *  Constant: '<S145>/offset'
       *  Constant: '<S145>/offset1'
       *  Constant: '<S145>/one_on_slope'
       *  DataTypeConversion: '<S118>/Data Type Conversion6'
       *  Product: '<S145>/Product4'
       *  Product: '<S148>/Divide'
       *  Sum: '<S118>/Sum'
       *  Sum: '<S145>/Add1'
       *  Sum: '<S145>/Add2'
       */
      locallocalDataTypeConversion6_m = (((InjrSys_prm_agEndInjS2Prev[0] -
        (((Float32)InjrSys_prm_agBegInjS2[0]) * 0.09375F)) *
        localInterpolationUsingPrelo_jj) * 312500.0F) + 0.5F;
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_m;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      InjrSys_prm_tiWoutInjPrevS2[0] = locallocalDataTypeConversion1_p;
      locallocalDataTypeConversion6_m = (((InjrSys_prm_agEndInjS2Prev[1] -
        (((Float32)InjrSys_prm_agBegInjS2[1]) * 0.09375F)) *
        localInterpolationUsingPrelo_jj) * 312500.0F) + 0.5F;
      if (locallocalDataTypeConversion6_m < 65536.0F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalDataTypeConversion1_p = (UInt16)
            locallocalDataTypeConversion6_m;
        } else {
          locallocalDataTypeConversion1_p = 0U;
        }
      } else {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      }

      InjrSys_prm_tiWoutInjPrevS2[1] = locallocalDataTypeConversion1_p;

      /* Lookup2D: '<S141>/Look-Up Table (2-D)'
       * About '<S141>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    S16  2^-19  FSlope 1.6777216
       * Input1  Data Type:  Fixed Point    U16  2^-19  FSlope 1.6777216
       * Output0 Data Type:  Fixed Point    U16  2^-19  FSlope 1.6777216  Bias -0.1048576
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_S16_U16( &(localLookUpTable2D[0]), (&(InjrSys_tiOfsS2CorS1_M[0])),
                         InjrSys_prm_tiOfsS2CorPrev[0], (&(InjrSys_tiOfsCor_A[0])),
                         15U, InjrSys_prm_tiWoutInjPrevS2[0],
                         (&(InjrSys_tiBtwnInj_A[0])), 15U);
      Look2D_U16_S16_U16( &(localLookUpTable2D[1]), (&(InjrSys_tiOfsS2CorS1_M[0])),
                         InjrSys_prm_tiOfsS2CorPrev[1], (&(InjrSys_tiOfsCor_A[0])),
                         15U, InjrSys_prm_tiWoutInjPrevS2[1],
                         (&(InjrSys_tiBtwnInj_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S141>/Data Type Duplicate2'
       *
       * Regarding '<S141>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S118>/Data Type Conversion3' incorporates:
       *  Lookup2D: '<S141>/Look-Up Table (2-D)'
       */
      locallocalDataTypeConversion5_i = (((Float32)localLookUpTable2D[0]) *
        3.200000037E-006F) - 1.048576012E-001F;

      /* DataTypeConversion: '<S118>/Data Type Conversion7' */
      locallocalDataTypeConversion6_1 = ((Float32)InjrSys_prm_agBegInjS2Prev[0])
        * 0.09375F;

      /* DataTypeConversion: '<S118>/Data Type Conversion3' incorporates:
       *  Lookup2D: '<S141>/Look-Up Table (2-D)'
       */
      locallocalDataTypeConversion5_0 = (((Float32)localLookUpTable2D[1]) *
        3.200000037E-006F) - 1.048576012E-001F;

      /* DataTypeConversion: '<S118>/Data Type Conversion7' */
      locallocalDataTypeConversion6_2 = ((Float32)InjrSys_prm_agBegInjS2Prev[1])
        * 0.09375F;

      /* Interpolation_n-D: '<S140>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_pFuRailMes_InjrSys_pFu;
      localfractionTmp_0d = intrp1d_iu8n7ff_u32f_l_ns
        (localExt_pFuRailMes_InjrSys_p_d, localfractionTmp_0d,
         (&(InjrSys_tiOfsS2CorPFu_T[0])));

      /* Sum: '<S143>/Add2' incorporates:
       *  Constant: '<S143>/offset'
       *  Constant: '<S143>/offset1'
       *  Constant: '<S143>/one_on_slope'
       *  Product: '<S143>/Product4'
       *  Product: '<S149>/Divide'
       *  Sum: '<S118>/Sum1'
       *  Sum: '<S143>/Add1'
       */
      locallocalDataTypeConversion6_m = (((locallocalDataTypeConversion6_1 -
        InjrSys_prm_agEndInjS2Prev[0]) * localInterpolationUsingPrelo_jj) *
        312500.0F) + 0.5F;

      /* DataTypeConversion: '<S143>/OutDTConv' */
      if (locallocalDataTypeConversion6_m < 4.294967296E+009F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_m;
        } else {
          locallocalOutDTConv_b = 0U;
        }
      } else {
        locallocalOutDTConv_b = MAX_uint32_T;
      }

      /* Product: '<S144>/Product4' incorporates:
       *  Constant: '<S144>/offset'
       *  Constant: '<S144>/one_on_slope'
       *  Lookup_n-D: '<S142>/Lookup Table (n-D)'
       *  Product: '<S147>/Divide'
       *  Sum: '<S118>/Sum2'
       *  Sum: '<S144>/Add1'
       */
      locallocalDataTypeConversion6_m = ((look2_1hcwlbcvbcvbfbbt5nfbbnx
        (locallocalOutDTConv_b, InjrSys_prm_tiWoutInjPrevS2[0],
         (&(InjrSys_tiInj_A[0])), (&(InjrSys_tiBtwnInj_A[0])),
         (&(InjrSys_tiOfsS2Cor_M[0])), &tiFuSp_ConstP.pooled10[0], 16U) +
        locallocalDataTypeConversion5_i) * localfractionTmp_0d) * 312500.0F;

      /* Switch: '<S144>/Switch1' incorporates:
       *  Constant: '<S144>/offset2'
       *  Constant: '<S144>/offset3'
       *  Constant: '<S144>/offset4'
       *  RelationalOperator: '<S144>/Relational Operator'
       *  Sum: '<S144>/Add3'
       *  Sum: '<S144>/Add4'
       */
      if (locallocalDataTypeConversion6_m >= 0.0F) {
        locallocalDataTypeConversion6_m += 0.5F;
      } else {
        locallocalDataTypeConversion6_m -= 0.5F;
      }

      /* Switch: '<S118>/Switch' incorporates:
       *  Constant: '<S118>/ConstVal'
       *  Constant: '<S118>/ConstVal_2'
       *  DataTypeConversion: '<S144>/OutDTConv'
       *  RelationalOperator: '<S118>/Relational Operator'
       */
      if (InjrSys_prm_mFuInjS2Req[0] > 0) {
        if (locallocalDataTypeConversion6_m < 32768.0F) {
          if (locallocalDataTypeConversion6_m >= -32768.0F) {
            localtmp = (SInt16)locallocalDataTypeConversion6_m;
          } else {
            localtmp = MIN_int16_T;
          }
        } else {
          localtmp = MAX_int16_T;
        }

        InjrSys_prm_tiOfsS2Cor[0] = localtmp;
      } else {
        InjrSys_prm_tiOfsS2Cor[0] = 0;
      }

      /* Sum: '<S143>/Add2' incorporates:
       *  Constant: '<S143>/offset'
       *  Constant: '<S143>/offset1'
       *  Constant: '<S143>/one_on_slope'
       *  Product: '<S143>/Product4'
       *  Product: '<S149>/Divide'
       *  Sum: '<S118>/Sum1'
       *  Sum: '<S143>/Add1'
       */
      locallocalDataTypeConversion6_m = (((locallocalDataTypeConversion6_2 -
        InjrSys_prm_agEndInjS2Prev[1]) * localInterpolationUsingPrelo_jj) *
        312500.0F) + 0.5F;

      /* DataTypeConversion: '<S143>/OutDTConv' */
      if (locallocalDataTypeConversion6_m < 4.294967296E+009F) {
        if (locallocalDataTypeConversion6_m >= 0.0F) {
          locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_m;
        } else {
          locallocalOutDTConv_b = 0U;
        }
      } else {
        locallocalOutDTConv_b = MAX_uint32_T;
      }

      /* Product: '<S144>/Product4' incorporates:
       *  Constant: '<S144>/offset'
       *  Constant: '<S144>/one_on_slope'
       *  Lookup_n-D: '<S142>/Lookup Table (n-D)'
       *  Product: '<S147>/Divide'
       *  Sum: '<S118>/Sum2'
       *  Sum: '<S144>/Add1'
       */
      locallocalDataTypeConversion6_m = ((look2_1hcwlbcvbcvbfbbt5nfbbnx
        (locallocalOutDTConv_b, InjrSys_prm_tiWoutInjPrevS2[1],
         (&(InjrSys_tiInj_A[0])), (&(InjrSys_tiBtwnInj_A[0])),
         (&(InjrSys_tiOfsS2Cor_M[0])), &tiFuSp_ConstP.pooled10[0], 16U) +
        locallocalDataTypeConversion5_0) * localfractionTmp_0d) * 312500.0F;

      /* Switch: '<S144>/Switch1' incorporates:
       *  Constant: '<S144>/offset2'
       *  Constant: '<S144>/offset3'
       *  Constant: '<S144>/offset4'
       *  RelationalOperator: '<S144>/Relational Operator'
       *  Sum: '<S144>/Add3'
       *  Sum: '<S144>/Add4'
       */
      if (locallocalDataTypeConversion6_m >= 0.0F) {
        locallocalDataTypeConversion6_m += 0.5F;
      } else {
        locallocalDataTypeConversion6_m -= 0.5F;
      }

      /* Switch: '<S118>/Switch' incorporates:
       *  Constant: '<S118>/ConstVal'
       *  Constant: '<S118>/ConstVal_2'
       *  DataTypeConversion: '<S144>/OutDTConv'
       *  RelationalOperator: '<S118>/Relational Operator'
       */
      if (InjrSys_prm_mFuInjS2Req[1] > 0) {
        if (locallocalDataTypeConversion6_m < 32768.0F) {
          if (locallocalDataTypeConversion6_m >= -32768.0F) {
            localtmp = (SInt16)locallocalDataTypeConversion6_m;
          } else {
            localtmp = MIN_int16_T;
          }
        } else {
          localtmp = MAX_int16_T;
        }

        InjrSys_prm_tiOfsS2Cor[1] = localtmp;
      } else {
        InjrSys_prm_tiOfsS2Cor[1] = 0;
      }

      /* end of Outputs for SubSystem: '<S114>/F03_InjS2CorClcn' */

      /* Outputs for atomic SubSystem: '<S114>/F04_InjS2CorClcn1' */

      /* SignalConversion: '<S119>/Signal Conversion' incorporates:
       *  Constant: '<S119>/ConstVal'
       */
      InjrSys_prm_tiOfsCor[0] = 0;
      InjrSys_prm_tiOfsCor[1] = InjrSys_prm_tiOfsH2Cor[0];
      InjrSys_prm_tiOfsCor[2] = InjrSys_prm_tiOfsS1Cor[0];
      InjrSys_prm_tiOfsCor[3] = InjrSys_prm_tiOfsS2Cor[0];
      InjrSys_prm_tiOfsCor[4] = InjrSys_prm_tiOfsS1Cor[1];
      InjrSys_prm_tiOfsCor[5] = InjrSys_prm_tiOfsS2Cor[1];

      /* end of Outputs for SubSystem: '<S114>/F04_InjS2CorClcn1' */

      /* end of Outputs for SubSystem: '<S92>/F01_tiOfsCorClcn' */

      /* Outputs for atomic SubSystem: '<S92>/F02_tiClcn' */

      /* Outputs for atomic SubSystem: '<S115>/F01_tiInjMinSat' */
      for (locali = 0; locali < 6; locali++) {
        /* Sum: '<S150>/Sum1' */
        locallocalSum1_m = InjrSys_prm_tiInjOfs[(locali)] +
          InjrSys_prm_tiOfsCor[(locali)];

        /* DataTypeConversion: '<S150>/Data Type Conversion1' */
        if (locallocalSum1_m > 32767) {
          localtmp = MAX_int16_T;
        } else if (locallocalSum1_m <= -32768) {
          localtmp = MIN_int16_T;
        } else {
          localtmp = (SInt16)locallocalSum1_m;
        }

        InjrSys_prm_tiInjOfsCor[(locali)] = localtmp;

        /* Sum: '<S155>/Add2' incorporates:
         *  Constant: '<S155>/offset'
         *  Constant: '<S155>/offset1'
         *  Constant: '<S155>/one_on_slope'
         *  Product: '<S155>/Product4'
         *  Product: '<S156>/Divide'
         *  Sum: '<S155>/Add1'
         */
        locallocalDataTypeConversion6_m = ((InjrSys_prm_mFuInjReq[(locali)] *
          InjrSys_prm_facGain[(locali)]) * 312500.0F) + 0.5F;

        /* DataTypeConversion: '<S155>/OutDTConv' */
        if (locallocalDataTypeConversion6_m < 4.294967296E+009F) {
          if (locallocalDataTypeConversion6_m >= 0.0F) {
            locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_m;
          } else {
            locallocalOutDTConv_b = 0U;
          }
        } else {
          locallocalOutDTConv_b = MAX_uint32_T;
        }

        localOutDTConv_i[locali] = locallocalOutDTConv_b;
        localSum1_m[locali] = locallocalSum1_m;
      }

      /* Lookup_n-D: '<S153>/Lookup Table (n-D)' */
      locallocalOutDTConv_b = plook_u32u16f_binc(tiFuSp_B.VEMS_vidGET1_h,
        (&(InjrSys_nEng_facCorInjGain_A[0])), 8U, &localfrac);
      localfractions[0U] = localfrac;
      localbpIndices[0U] = locallocalOutDTConv_b;
      for (locali = 0; locali < 6; locali++) {
        locallocalOutDTConv_b = plook_u32u32f_binc(localOutDTConv_i[(UInt32)
          locali], (&(InjrSys_ti_facCorInjGain_A[0])), 8U, &localfrac);
        localfractions[1U] = localfrac;
        localbpIndices[1U] = locallocalOutDTConv_b;
        localDivide_co[(UInt32)locali] = intrp2d_iu8n7ff_u32f_l_ns
          (localbpIndices, localfractions, (&(InjrSys_facFuSysCor_M[0])), 9U);
      }

      /* Lookup_n-D: '<S154>/Lookup Table (n-D)' */
      locallocalDataTypeConversion6_1 = look2_iu16u8lftu16n19If_binlcns
        (tiFuSp_B.VEMS_vidGET3, tiFuSp_B.VEMS_vidGET7_g,
         (&(InjrSys_pFuRailMes_A[0])), (&(InjrSys_IdxInjrMdlInj_A[0])),
         (&(InjrSys_tiInjMin_M[0])), &tiFuSp_ConstP.LookupTablenD_maxIn_b[0],
         16U);
      for (locali = 0; locali < 6; locali++) {
        /* Product: '<S157>/Divide' */
        locallocalDataTypeConversion6_m = localDivide_co[locali] *
          InjrSys_prm_facGain[(locali)];

        /* Product: '<S158>/Divide' */
        InjrSys_prm_tiEfcInj_MP[(locali)] = locallocalDataTypeConversion6_m *
          InjrSys_prm_mFuInjReq[(locali)];

        /* Sum: '<S150>/Sum4' incorporates:
         *  DataTypeConversion: '<S150>/Data Type Conversion3'
         */
        locallocalDataTypeConversion6_0 = (((Float32)localSum1_m[locali]) *
          3.200000037E-006F) + InjrSys_prm_tiEfcInj_MP[(locali)];

        /* MinMax: '<S150>/MinMax4' */
        InjrSys_prm_tiInjReqSatMin[(locali)] = rt_MAXf
          (locallocalDataTypeConversion6_0, locallocalDataTypeConversion6_1);

        /* SignalConversion: '<S150>/Signal Conversion2' */
        InjrSys_prm_facGainCor[(locali)] = locallocalDataTypeConversion6_m;

        /* SignalConversion: '<S150>/Signal Conversion4' incorporates:
         *  Constant: '<S150>/ConstVal'
         *  Logic: '<S150>/Logical Operator'
         *  RelationalOperator: '<S150>/Relational Operator1'
         *  RelationalOperator: '<S150>/Relational Operator2'
         */
        localMerge[locali] = ((locallocalDataTypeConversion6_1 >=
          locallocalDataTypeConversion6_0) && (locallocalDataTypeConversion6_0 >
          0.0F));
      }

      /* end of Outputs for SubSystem: '<S115>/F01_tiInjMinSat' */

      /* Outputs for atomic SubSystem: '<S115>/F02_tiInjMaxSat' */

      /* DataTypeConversion: '<S151>/Data Type Conversion1' */
      locallocalOutDTConv_b = (UInt32)(tiFuSp_B.VEMS_vidGET_f + 896);
      if (locallocalOutDTConv_b > 65535U) {
        locallocalDataTypeConversion1_p = MAX_uint16_T;
      } else {
        locallocalDataTypeConversion1_p = (UInt16)locallocalOutDTConv_b;
      }

      /* DataTypeConversion: '<S151>/Data Type Conversion3' incorporates:
       *  Constant: '<S151>/InjSys_agInjS2SpMin_C'
       */
      localInterpolationUsingPrelo_jj = ((Float32)InjSys_agInjS2SpMin_C) *
        0.09375F;

      /* Lookup_n-D: '<S160>/Lookup Table (n-D)' */
      locallocalDataTypeConversion6_m = look2_iu16u16lftu16n4If_binlcns
        (tiFuSp_B.VEMS_vidGET3, locallocalDataTypeConversion1_p,
         (&(InjSys_pFuRailMes_A[0])), (&(InjSys_agCkClsInVlvEstimRef1_A[0])),
         (&(InjrSys_agEndInjSpcModMax_M[0])), &tiFuSp_ConstP.pooled10[0], 16U);

      /* Sum: '<S151>/Sum3' incorporates:
       *  DataTypeConversion: '<S151>/Data Type Conversion2'
       *  Lookup_n-D: '<S159>/Lookup Table (n-D)'
       */
      locallocalDataTypeConversion6_0 = ((((Float32)tiFuSp_B.VEMS_vidGET5_l) *
        0.375F) - 36.0F) + look1_iu16lftu16n4If_binlcns(tiFuSp_B.VEMS_vidGET1_h,
        (&(InjSys_nEng_A[0])), (&(InjSys_agOfsPhaIg_T[0])), 15U);

      /* MinMax: '<S151>/MinMax2' */
      localfractionTmp_0d = rt_MAXf(locallocalDataTypeConversion6_0,
        locallocalDataTypeConversion6_m);

      /* Sum: '<S151>/Sum2' */
      InjrSys_agWdInjSpcModMax = InjrSys_agBegInjH1 - rt_MAXf
        (localfractionTmp_0d, localInterpolationUsingPrelo_jj);

      /* Product: '<S161>/Divide' incorporates:
       *  Constant: '<S151>/Ext_agWdTooth_SC'
       *  DataTypeConversion: '<S151>/Data Type Conversion4'
       *  Product: '<S162>/Divide'
       */
      InjrSys_tiInjSpcModMax = ((((Float32)tiFuSp_B.VEMS_vidGET4) *
        3.200000037E-006F) * InjrSys_agWdInjSpcModMax) / ((Float32)
        Ext_agWdTooth_SC);

      /* Switch: '<S151>/Switch1' incorporates:
       *  Logic: '<S151>/Logical Operator1'
       *  MinMax: '<S151>/MinMax1'
       */
      if (!tiFuSp_B.VEMS_vidGET6_j) {
        for (locali = 0; locali < 6; locali++) {
          InjrSys_prm_tiInjReqSat[(locali)] = InjrSys_prm_tiInjReqSatMin[(locali)];
        }
      } else {
        for (locali = 0; locali < 6; locali++) {
          InjrSys_prm_tiInjReqSat[(locali)] = rt_MINf
            (InjrSys_prm_tiInjReqSatMin[(locali)], InjrSys_tiInjSpcModMax);
        }
      }

      /* end of Outputs for SubSystem: '<S115>/F02_tiInjMaxSat' */

      /* Outputs for atomic SubSystem: '<S115>/F03_InjCutOfftiInjReq' */

      /* Switch: '<S152>/Switch5' incorporates:
       *  Constant: '<S152>/ConstVal'
       *  Constant: '<S152>/ConstVal_2'
       *  Constant: '<S163>/offset'
       *  Constant: '<S163>/offset1'
       *  Constant: '<S163>/one_on_slope'
       *  DataTypeConversion: '<S163>/OutDTConv'
       *  Product: '<S163>/Product4'
       *  RelationalOperator: '<S152>/Relational Operator5'
       *  Sum: '<S163>/Add1'
       *  Sum: '<S163>/Add2'
       */
      for (locali = 0; locali < 6; locali++) {
        if (InjrSys_prm_mFuInjReq[(locali)] > 0.0F) {
          locallocalDataTypeConversion6_m = (312500.0F *
            InjrSys_prm_tiInjReqSat[(locali)]) + 0.5F;
          if (locallocalDataTypeConversion6_m < 4.294967296E+009F) {
            if (locallocalDataTypeConversion6_m >= 0.0F) {
              locallocalOutDTConv_b = (UInt32)locallocalDataTypeConversion6_m;
            } else {
              locallocalOutDTConv_b = 0U;
            }
          } else {
            locallocalOutDTConv_b = MAX_uint32_T;
          }

          InjrSys_prm_tiInjReq[(locali)] = locallocalOutDTConv_b;
        } else {
          InjrSys_prm_tiInjReq[(locali)] = 0U;
        }
      }

      /* end of Outputs for SubSystem: '<S115>/F03_InjCutOfftiInjReq' */

      /* end of Outputs for SubSystem: '<S92>/F02_tiClcn' */
    }

    /* DataStoreWrite: '<S90>/InjrSys_prm_bDettiInjMin_DSW' */
    for (locali = 0; locali < 6; locali++) {
      InjrSys_prm_bDettiInjMin[(locali)] = localMerge[locali];
    }
  }

  /* end of Outputs for SubSystem: '<S89>/F00_InjTi' */
}

/* Output and update for function-call system: '<S9>/F03_InjtiSyncEveClcn' */
void tiFuSp_F03_InjtiSyncEveClcn(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator4;
  Boolean localRelationalOperator2_b;
  Boolean localLogicalOperator3;
  Boolean localLogicalOperator1_m;
  UInt32 localSwitch12;
  UInt32 localSelector_h;
  UInt32 localSelector_b;
  UInt32 localSelector_f;
  Float32 localDataTypeConversion8_m[6];
  UInt32 localSelector_dg;
  UInt32 localSwitch6[6];
  UInt32 localAssignment[6];
  UInt32 localOutDTConv_l[6];
  UInt32 localAssignment_c[6];
  UInt32 localAssignment_k[6];
  Boolean localRelationalOperator_p_0;
  SInt32 locali;
  Float32 locallocalDataTypeConversion8_m;

  /* RelationalOperator: '<S166>/Relational Operator' incorporates:
   *  Constant: '<S166>/ConstVal'
   *  Constant: '<S166>/TIFUSP_u8Inhib'
   */
  localRelationalOperator_p_0 = (TIFUSP_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S166>/F00_InjtiSyncEveClcn' incorporates:
   *  EnablePort: '<S189>/Enable'
   */
  if (localRelationalOperator_p_0) {
    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET5 */
    VEMS_vidGET(Eng_stEru, tiFuSp_B.VEMS_vidGET5_d);

    /* RelationalOperator: '<S189>/Relational Operator2' incorporates:
     *  Constant: '<S189>/Ext_stStall_SC'
     */
    localRelationalOperator2_b = (tiFuSp_B.VEMS_vidGET5_d == Ext_stStall_SC);

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET */
    VEMS_vidGET(ActrTstHPPmp_bInjAuthReq, tiFuSp_B.VEMS_vidGET_k);

    /* Logic: '<S189>/Logical Operator3' */
    localLogicalOperator3 = !tiFuSp_B.VEMS_vidGET_k;

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET9 */
    VEMS_vidGET(Srv_bActrTstEna, tiFuSp_B.VEMS_vidGET9_d);

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET2 */
    VEMS_vidGET(Code_test_action, tiFuSp_B.VEMS_vidGET2_p);

    /* Logic: '<S189>/Logical Operator1' incorporates:
     *  Constant: '<S189>/CODE_TEST_HPPMP'
     *  Logic: '<S189>/Logical Operator2'
     *  RelationalOperator: '<S189>/Relational Operator3'
     */
    localLogicalOperator1_m = ((localRelationalOperator2_b) ||
      (((localLogicalOperator3) && tiFuSp_B.VEMS_vidGET9_d) &&
       (tiFuSp_B.VEMS_vidGET2_p == CODE_TEST_HPPMP)));

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_bCylCutOff, 6, tiFuSp_B.VEMS_vidGET7_n);

    /* SignalConversion: '<S189>/Signal Conversion3' */
    for (locali = 0; locali < 6; locali++) {
      localSwitch6[locali] = InjrSys_prm_tiInjH1TmpCyl[(locali)];
    }

    /* Selector: '<S203>/Selector' incorporates:
     *  Constant: '<S189>/ConstVal_7'
     *  Constant: '<S203>/Constant'
     *  Constant: '<S203>/Constant1'
     *  MinMax: '<S203>/MinMax'
     *  Sum: '<S203>/Add'
     */
    localSwitch12 = InjrSys_prm_tiInjReq[0];

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET4 */
    VEMS_vidGET(Eng_noInCyl, tiFuSp_B.VEMS_vidGET4_fz);

    /* DataTypeConversion: '<S189>/Data Type Conversion3' */
    localSelector_h = tiFuSp_B.VEMS_vidGET4_fz;

    /* Sum: '<S191>/Add' incorporates:
     *  Constant: '<S191>/Constant1'
     */
    localSelector_b = localSelector_h - 1U;

    /* Assignment: '<S191>/Assignment' incorporates:
     *  Constant: '<S191>/Constant'
     *  MinMax: '<S191>/MinMax'
     */
    localSwitch6[(SInt32)rt_MIN(localSelector_b, 5U)] = localSwitch12;

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_stEng, tiFuSp_B.VEMS_vidGET1_o);

    /* RelationalOperator: '<S189>/Relational Operator4' incorporates:
     *  Constant: '<S189>/ConstVal_4'
     */
    localRelationalOperator4 = (tiFuSp_B.VEMS_vidGET1_o == 6);

    /* Logic: '<S190>/OU7' incorporates:
     *  Logic: '<S190>/OU1'
     *  UnitDelay: '<S210>/Unit Delay'
     */
    localRelationalOperator2_b = ((!localRelationalOperator4) &&
      tiFuSp_DWork.UnitDelay_DSTATE);

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_bInhFrstInjSTT, 2, tiFuSp_B.VEMS_vidGET8_h);

    /* Logic: '<S189>/Logical Operator4' */
    InjrSys_bAcvRstrtSTT = (((localRelationalOperator4) ||
      (localRelationalOperator2_b)) || tiFuSp_B.VEMS_vidGET8_h[1]);

    /* Logic: '<S189>/Logical Operator6' */
    localRelationalOperator2_b = !InjrSys_bAcvRstrtSTT;

    /* Switch: '<S189>/Switch10' incorporates:
     *  Constant: '<S189>/ConstVal_8'
     *  Logic: '<S189>/Logical Operator5'
     */
    if (tiFuSp_B.VEMS_vidGET8_h[1]) {
      localSwitch12 = 0U;
    }

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET3 */
    VEMS_vidGET(Eng_noCmprCyl, tiFuSp_B.VEMS_vidGET3_g);

    /* DataTypeConversion: '<S189>/Data Type Conversion2' */
    localSelector_b = tiFuSp_B.VEMS_vidGET3_g;

    /* Sum: '<S197>/Add' incorporates:
     *  Constant: '<S197>/Constant1'
     */
    localSelector_f = localSelector_b - 1U;

    /* Assignment: '<S197>/Assignment' incorporates:
     *  Constant: '<S197>/Constant'
     *  MinMax: '<S197>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localSwitch6[locali];
    }

    localAssignment[(SInt32)rt_MIN(localSelector_f, 5U)] = localSwitch12;
    for (locali = 0; locali < 6; locali++) {
      localSwitch12 = localSwitch6[locali];

      /* Switch: '<S189>/Switch11' */
      if (!localRelationalOperator2_b) {
        localSwitch12 = localAssignment[locali];
      }

      /* Switch: '<S189>/Switch1' incorporates:
       *  Constant: '<S189>/ConstVal'
       */
      if (tiFuSp_B.VEMS_vidGET7_n[(locali)]) {
        localSwitch12 = 0U;
      }

      /* Switch: '<S189>/Switch6' incorporates:
       *  Constant: '<S189>/ConstMat'
       */
      if (localLogicalOperator1_m) {
        localSwitch12 = tiFuSp_ConstP.pooled16[(locali)];
      }

      localSwitch6[locali] = localSwitch12;
    }

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_InjClsRespCor_prmtiOfsH1, 6,
                       tiFuSp_B.VEMS_vidGET6_k);

    /* DataTypeConversion: '<S189>/Data Type Conversion8' */
    for (locali = 0; locali < 6; locali++) {
      localDataTypeConversion8_m[locali] = ((Float32)tiFuSp_B.VEMS_vidGET6_k
        [(locali)]) * 3.200000037E-006F;
    }

    /* Logic: '<S189>/Logical Operator7' */
    localRelationalOperator2_b = !tiFuSp_B.VEMS_vidGET8_h[1];

    /* Logic: '<S189>/Logical Operator8' */
    localLogicalOperator3 = !InjrSys_bAcvRstrtSTT;

    /* Sum: '<S192>/Add' incorporates:
     *  Constant: '<S192>/Constant1'
     */
    localSelector_f = localSelector_h - 1U;

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjrSys_prm_tiInjH2ReqCyl, 6, tiFuSp_B.VEMS_vidGET10);

    /* DataTypeDuplicate Block: '<S192>/Data Type Duplicate'
     *
     * Regarding '<S192>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S192>/Data Type Duplicate1'
     *
     * Regarding '<S192>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Selector: '<S204>/Selector' incorporates:
     *  Constant: '<S204>/Constant'
     *  MinMax: '<S204>/MinMax'
     */
    localSwitch12 = InjrSys_prm_tiInjReq[1];

    /* Assignment: '<S192>/Assignment' incorporates:
     *  Constant: '<S192>/Constant'
     *  MinMax: '<S192>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = tiFuSp_B.VEMS_vidGET10[(locali)];
    }

    localAssignment[(SInt32)rt_MIN(localSelector_f, 5U)] =
      InjrSys_prm_tiInjReq[1];

    /* Sum: '<S193>/Add' incorporates:
     *  Constant: '<S193>/Constant1'
     */
    localSelector_f = localSelector_b - 1U;

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjrSys_prm_tiInjS1ReqCyl, 6, tiFuSp_B.VEMS_vidGET11);

    /* DataTypeDuplicate Block: '<S193>/Data Type Duplicate'
     *
     * Regarding '<S193>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S193>/Data Type Duplicate1'
     *
     * Regarding '<S193>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S193>/Assignment' incorporates:
     *  Constant: '<S193>/Constant'
     *  Constant: '<S205>/Constant'
     *  MinMax: '<S193>/MinMax'
     *  MinMax: '<S205>/MinMax'
     *  Selector: '<S205>/Selector'
     */
    for (locali = 0; locali < 6; locali++) {
      localOutDTConv_l[locali] = tiFuSp_B.VEMS_vidGET11[(locali)];
    }

    localOutDTConv_l[(SInt32)rt_MIN(localSelector_f, 5U)] =
      InjrSys_prm_tiInjReq[4];

    /* Sum: '<S194>/Add' incorporates:
     *  Constant: '<S194>/Constant1'
     */
    localSelector_dg = localSelector_h - 1U;

    /* Assignment: '<S194>/Assignment' incorporates:
     *  Constant: '<S194>/Constant'
     *  Constant: '<S206>/Constant'
     *  MinMax: '<S194>/MinMax'
     *  MinMax: '<S206>/MinMax'
     *  Selector: '<S206>/Selector'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_c[locali] = localOutDTConv_l[locali];
    }

    localAssignment_c[(SInt32)rt_MIN(localSelector_dg, 5U)] =
      InjrSys_prm_tiInjReq[2];

    /* Sum: '<S195>/Add' incorporates:
     *  Constant: '<S195>/Constant1'
     */
    localSelector_dg = localSelector_h - 1U;

    /* S-Function "vems_vidGET" Block: <S189>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjrSys_prm_tiInjS2ReqCyl, 6, tiFuSp_B.VEMS_vidGET12);

    /* DataTypeDuplicate Block: '<S196>/Data Type Duplicate'
     *
     * Regarding '<S196>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S196>/Data Type Duplicate1'
     *
     * Regarding '<S196>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S196>/Add' incorporates:
     *  Constant: '<S196>/Constant1'
     */
    localSelector_f = localSelector_b - 1U;

    /* Assignment: '<S196>/Assignment' incorporates:
     *  Constant: '<S196>/Constant'
     *  MinMax: '<S196>/MinMax'
     *  Selector: '<S207>/Selector'
     */
    for (locali = 0; locali < 6; locali++) {
      localOutDTConv_l[locali] = tiFuSp_B.VEMS_vidGET12[(locali)];
    }

    localOutDTConv_l[(SInt32)rt_MIN(localSelector_f, 5U)] =
      InjrSys_prm_tiInjReq[5];

    /* Assignment: '<S195>/Assignment' incorporates:
     *  Constant: '<S195>/Constant'
     *  Constant: '<S208>/Constant'
     *  MinMax: '<S195>/MinMax'
     *  MinMax: '<S208>/MinMax'
     *  Selector: '<S208>/Selector'
     */
    localOutDTConv_l[(SInt32)rt_MIN(localSelector_dg, 5U)] =
      InjrSys_prm_tiInjReq[3];

    /* Sum: '<S198>/Add' incorporates:
     *  Constant: '<S198>/Constant1'
     */
    localSelector_dg = localSelector_b - 1U;

    /* Switch: '<S189>/Switch12' incorporates:
     *  Constant: '<S189>/ConstVal_5'
     */
    if (!localRelationalOperator2_b) {
      localSwitch12 = 0U;
    }

    /* Assignment: '<S198>/Assignment' incorporates:
     *  Constant: '<S198>/Constant'
     *  MinMax: '<S198>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_k[locali] = localAssignment[locali];
    }

    localAssignment_k[(SInt32)rt_MIN(localSelector_dg, 5U)] = localSwitch12;

    /* Sum: '<S199>/Add' incorporates:
     *  Constant: '<S199>/Constant1'
     */
    localSelector_dg = localSelector_h - 1U;

    /* Sum: '<S200>/Add' incorporates:
     *  Constant: '<S200>/Constant1'
     */
    localSelector_f = localSelector_h - 1U;
    for (locali = 0; locali < 6; locali++) {
      localSwitch12 = localAssignment[locali];

      /* Switch: '<S189>/Switch13' */
      if (!localLogicalOperator3) {
        localSwitch12 = localAssignment_k[locali];
      }

      /* Switch: '<S189>/Switch2' incorporates:
       *  Constant: '<S189>/ConstVal_6'
       */
      if (tiFuSp_B.VEMS_vidGET7_n[(locali)]) {
        localSwitch12 = 0U;
      }

      /* Switch: '<S189>/Switch7' incorporates:
       *  Constant: '<S189>/ConstMat_4'
       */
      if (localLogicalOperator1_m) {
        tiFuSp_B.Switch7_b[(locali)] = tiFuSp_ConstP.pooled16[(locali)];
      } else {
        tiFuSp_B.Switch7_b[(locali)] = localSwitch12;
      }
    }

    /* Switch: '<S189>/Switch14' incorporates:
     *  Constant: '<S189>/CODE_TEST_HPPMP1'
     */
    if (!InjrSys_bAcvMFuInjCmprCyl_C) {
      localSelector_b = localSelector_h;
    }

    /* Sum: '<S201>/Add' incorporates:
     *  Constant: '<S201>/Constant1'
     */
    localSelector_h = localSelector_b - 1U;

    /* Sum: '<S202>/Add' incorporates:
     *  Constant: '<S202>/Constant1'
     */
    localSelector_b--;

    /* SignalConversion: '<S189>/Signal Conversion1' incorporates:
     *  Constant: '<S199>/Constant'
     *  Constant: '<S200>/Constant'
     *  Constant: '<S201>/Constant'
     *  Constant: '<S202>/Constant'
     *  MinMax: '<S199>/MinMax'
     *  MinMax: '<S200>/MinMax'
     *  MinMax: '<S201>/MinMax'
     *  MinMax: '<S202>/MinMax'
     *  Selector: '<S199>/Selector'
     *  Selector: '<S200>/Selector'
     *  Selector: '<S201>/Selector'
     *  Selector: '<S202>/Selector'
     */
    InjrSys_prm_tiInjMFu[0] = localSwitch6[(SInt32)rt_MIN(localSelector_dg, 5U)];
    InjrSys_prm_tiInjMFu[1] = tiFuSp_B.Switch7_b[rt_MIN(localSelector_f, 5U)];
    for (locali = 0; locali < 6; locali++) {
      /* Switch: '<S189>/Switch8' incorporates:
       *  Constant: '<S189>/ConstMat_1'
       *  Constant: '<S189>/ConstVal_1'
       *  Switch: '<S189>/Switch3'
       */
      if (localLogicalOperator1_m) {
        tiFuSp_B.Switch8_g[(locali)] = tiFuSp_ConstP.pooled16[(locali)];
      } else if (tiFuSp_B.VEMS_vidGET7_n[(locali)]) {
        tiFuSp_B.Switch8_g[(locali)] = 0U;
      } else {
        tiFuSp_B.Switch8_g[(locali)] = localAssignment_c[locali];
      }

      /* Switch: '<S189>/Switch5' incorporates:
       *  Constant: '<S189>/ConstMat_2'
       *  Constant: '<S189>/ConstVal_2'
       *  Switch: '<S189>/Switch4'
       */
      if (localLogicalOperator1_m) {
        tiFuSp_B.Switch5_g[(locali)] = tiFuSp_ConstP.pooled16[(locali)];
      } else if (tiFuSp_B.VEMS_vidGET7_n[(locali)]) {
        tiFuSp_B.Switch5_g[(locali)] = 0U;
      } else {
        tiFuSp_B.Switch5_g[(locali)] = localOutDTConv_l[locali];
      }

      /* Sum: '<S189>/Sum2' incorporates:
       *  DataTypeConversion: '<S189>/Data Type Conversion1'
       */
      locallocalDataTypeConversion8_m = (((Float32)localSwitch6[locali]) *
        3.200000037E-006F) - localDataTypeConversion8_m[locali];

      /* SignalConversion: '<S189>/Signal Conversion2' */
      InjrSys_prm_tiInjH1TmpCyl[(locali)] = localSwitch6[locali];

      /* Switch: '<S189>/Switch9' incorporates:
       *  Constant: '<S189>/ConstVal_3'
       *  Constant: '<S209>/offset'
       *  Constant: '<S209>/offset1'
       *  Constant: '<S209>/one_on_slope'
       *  DataTypeConversion: '<S209>/OutDTConv'
       *  Product: '<S209>/Product4'
       *  RelationalOperator: '<S189>/Relational Operator1'
       *  Sum: '<S209>/Add1'
       *  Sum: '<S209>/Add2'
       */
      if (locallocalDataTypeConversion8_m > 0.0F) {
        locallocalDataTypeConversion8_m = (312500.0F *
          locallocalDataTypeConversion8_m) + 0.5F;
        if (locallocalDataTypeConversion8_m < 4.294967296E+009F) {
          localSwitch12 = (UInt32)locallocalDataTypeConversion8_m;
        } else {
          localSwitch12 = MAX_uint32_T;
        }

        tiFuSp_B.Switch9_h[(locali)] = localSwitch12;
      } else {
        tiFuSp_B.Switch9_h[(locali)] = localSwitch6[locali];
      }
    }

    InjrSys_prm_tiInjMFu[2] = tiFuSp_B.Switch8_g[rt_MIN(localSelector_h, 5U)];
    InjrSys_prm_tiInjMFu[3] = tiFuSp_B.Switch5_g[rt_MIN(localSelector_b, 5U)];

    /* S-Function "vems_vidSET" Block: <S189>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjH1ReqCyl, 6, tiFuSp_B.Switch9_h);

    /* S-Function "vems_vidSET" Block: <S189>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjH2ReqCyl, 6, tiFuSp_B.Switch7_b);

    /* S-Function "vems_vidSET" Block: <S189>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjS1ReqCyl, 6, tiFuSp_B.Switch8_g);

    /* S-Function "vems_vidSET" Block: <S189>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjS2ReqCyl, 6, tiFuSp_B.Switch5_g);
  }

  /* end of Outputs for SubSystem: '<S166>/F00_InjtiSyncEveClcn' */

  /* Update for enable SubSystem: '<S166>/F00_InjtiSyncEveClcn' incorporates:
   *  Update for EnablePort: '<S189>/Enable'
   */
  if (localRelationalOperator_p_0) {
    /* Update for UnitDelay: '<S210>/Unit Delay' */
    tiFuSp_DWork.UnitDelay_DSTATE = localRelationalOperator4;
  }

  /* end of Update for SubSystem: '<S166>/F00_InjtiSyncEveClcn' */
}

/* Start for exported function: InjrSys_EveCkSnOn_tiFuSp */
void InjrSys_EveCkSnOn_tiFuSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/tiFuSp_fc_demux1'
   */

  /* Start for S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S7>/F01_tiFuSpSyncInEveClcn'
   *  Start for SubSystem: '<S8>/F02_tiFuSpClcn'
   *  Start for SubSystem: '<S9>/F03_InjtiSyncEveClcn'
   */
}

/* Output and update for exported function: InjrSys_EveCkSnOn_tiFuSp */
void InjrSys_EveCkSnOn_tiFuSp(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S6>/tiFuSp_fc_demux1'
   */

  /* S-Function (fcncallgen): '<S11>/Function-Call Generator' */
  tiFuSp_F01_tiFuSpSyncInEveClcn();
  tiFuSp_F02_tiFuSpClcn();
  tiFuSp_F03_InjtiSyncEveClcn();
}

/* Output and update for function-call system: '<S7>/F02_tiFuSpSyncInEveInj' */
void tiFuSp_F02_tiFuSpSyncInEveInj(void)
{
  UInt32 localAdd_k;
  UInt32 localAdd_j;
  UInt32 localAdd_a;
  SInt32 localmin;
  SInt32 localmin_0;
  UInt16 localSelector_kn;
  UInt16 localSelector_lm;
  UInt16 localSelector_h5;
  UInt16 localSelector_jb;
  UInt16 localSelector_fy;
  UInt16 localSelector_bd;
  UInt16 localSelector_fs;
  UInt16 localSelector_kf;
  UInt16 localSelector_ec;
  SInt16 localSelector_a;
  SInt16 localSelector_jkm;
  SInt16 localSelector_fi;
  SInt16 localSelector_le;
  UInt8 locallocalMultiportSwitch_g_idx;
  UInt8 locallocalMultiportSwitch_g_i_0;

  /* Outputs for enable SubSystem: '<S17>/F00_tiFuSpSyncInEveInj' incorporates:
   *  Constant: '<S17>/ConstVal'
   *  Constant: '<S17>/TIFUSP_u8Inhib'
   *  EnablePort: '<S53>/Enable'
   *  RelationalOperator: '<S17>/Relational Operator'
   */
  if (TIFUSP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH1Cyl, 6, tiFuSp_B.VEMS_vidGET13);

    /* DataTypeDuplicate Block: '<S78>/Data Type Duplicate'
     *
     * Regarding '<S78>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, tiFuSp_B.VEMS_vidGET1_n);

    /* DataTypeConversion: '<S53>/Data Type Conversion12' */
    localAdd_k = tiFuSp_B.VEMS_vidGET1_n;

    /* Sum: '<S78>/Add' incorporates:
     *  Constant: '<S78>/Constant1'
     */
    localAdd_j = localAdd_k - 1U;

    /* Selector: '<S78>/Selector' incorporates:
     *  Constant: '<S78>/Constant'
     *  MinMax: '<S78>/MinMax'
     */
    localSelector_kn = tiFuSp_B.VEMS_vidGET13[rt_MIN(localAdd_j, 5U)];

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET14 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH2Cyl, 6, tiFuSp_B.VEMS_vidGET14);

    /* DataTypeDuplicate Block: '<S79>/Data Type Duplicate'
     *
     * Regarding '<S79>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S79>/Add' incorporates:
     *  Constant: '<S79>/Constant1'
     */
    localAdd_j = localAdd_k - 1U;

    /* Selector: '<S79>/Selector' incorporates:
     *  Constant: '<S79>/Constant'
     *  MinMax: '<S79>/MinMax'
     */
    localSelector_lm = tiFuSp_B.VEMS_vidGET14[rt_MIN(localAdd_j, 5U)];

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET15 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS1Cyl, 6, tiFuSp_B.VEMS_vidGET15);

    /* DataTypeDuplicate Block: '<S80>/Data Type Duplicate'
     *
     * Regarding '<S80>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, tiFuSp_B.VEMS_vidGET_fn);

    /* DataTypeConversion: '<S53>/Data Type Conversion13' */
    localAdd_j = tiFuSp_B.VEMS_vidGET_fn;

    /* Sum: '<S80>/Add' incorporates:
     *  Constant: '<S80>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* Selector: '<S80>/Selector' incorporates:
     *  Constant: '<S80>/Constant'
     *  MinMax: '<S80>/MinMax'
     */
    localSelector_h5 = tiFuSp_B.VEMS_vidGET15[rt_MIN(localAdd_a, 5U)];

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET16 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS2Cyl, 6, tiFuSp_B.VEMS_vidGET16);

    /* DataTypeDuplicate Block: '<S81>/Data Type Duplicate'
     *
     * Regarding '<S81>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S81>/Add' incorporates:
     *  Constant: '<S81>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* Selector: '<S81>/Selector' incorporates:
     *  Constant: '<S81>/Constant'
     *  MinMax: '<S81>/MinMax'
     */
    localSelector_jb = tiFuSp_B.VEMS_vidGET16[rt_MIN(localAdd_a, 5U)];

    /* DataTypeConversion: '<S53>/Data Type Conversion1' */
    InjrSys_prm_facGain[0] = ((Float32)localSelector_kn) * 0.015625F;
    InjrSys_prm_facGain[1] = ((Float32)localSelector_lm) * 0.015625F;
    InjrSys_prm_facGain[2] = ((Float32)localSelector_h5) * 0.015625F;
    InjrSys_prm_facGain[3] = ((Float32)localSelector_jb) * 0.015625F;
    InjrSys_prm_facGain[4] = ((Float32)localSelector_h5) * 0.015625F;
    InjrSys_prm_facGain[5] = ((Float32)localSelector_jb) * 0.015625F;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, tiFuSp_B.VEMS_vidGET3_l);

    /* DataTypeDuplicate Block: '<S83>/Data Type Duplicate'
     *
     * Regarding '<S83>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S84>/Data Type Duplicate'
     *
     * Regarding '<S84>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S83>/Add' incorporates:
     *  Constant: '<S83>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* MinMax: '<S83>/MinMax' incorporates:
     *  Constant: '<S83>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_a, 5U);

    /* Sum: '<S84>/Add' incorporates:
     *  Constant: '<S84>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* DataTypeConversion: '<S53>/Data Type Conversion10' incorporates:
     *  Constant: '<S84>/Constant'
     *  MinMax: '<S84>/MinMax'
     *  Selector: '<S83>/Selector'
     *  Selector: '<S84>/Selector'
     */
    InjrSys_prm_agBegInjH2[0] = (UInt16)((((UInt32)tiFuSp_B.VEMS_vidGET3_l
      [(localmin)]) * 43691U) >> 16U);
    InjrSys_prm_agBegInjH2[1] = (UInt16)((((UInt32)
      tiFuSp_B.VEMS_vidGET3_l[rt_MIN(localAdd_a, 5U)]) * 43691U) >> 16U);

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, tiFuSp_B.VEMS_vidGET9);

    /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate'
     *
     * Regarding '<S56>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S56>/Add' incorporates:
     *  Constant: '<S56>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* Selector: '<S56>/Selector' incorporates:
     *  Constant: '<S56>/Constant'
     *  MinMax: '<S56>/MinMax'
     */
    localSelector_jb = tiFuSp_B.VEMS_vidGET9[rt_MIN(localAdd_a, 5U)];

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, tiFuSp_B.VEMS_vidGET10_n);

    /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate'
     *
     * Regarding '<S55>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate'
     *
     * Regarding '<S57>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S87>/Data Type Duplicate'
     *
     * Regarding '<S87>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S57>/Add' incorporates:
     *  Constant: '<S57>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* Selector: '<S57>/Selector' incorporates:
     *  Constant: '<S57>/Constant'
     *  MinMax: '<S57>/MinMax'
     */
    localSelector_h5 = tiFuSp_B.VEMS_vidGET10_n[rt_MIN(localAdd_a, 5U)];

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, tiFuSp_B.VEMS_vidGET11_j);

    /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate'
     *
     * Regarding '<S58>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S60>/Data Type Duplicate'
     *
     * Regarding '<S60>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S69>/Data Type Duplicate'
     *
     * Regarding '<S69>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S70>/Data Type Duplicate'
     *
     * Regarding '<S70>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S58>/Add' incorporates:
     *  Constant: '<S58>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* Selector: '<S58>/Selector' incorporates:
     *  Constant: '<S58>/Constant'
     *  MinMax: '<S58>/MinMax'
     */
    localSelector_lm = tiFuSp_B.VEMS_vidGET11_j[rt_MIN(localAdd_a, 5U)];

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, tiFuSp_B.VEMS_vidGET12_k);

    /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate'
     *
     * Regarding '<S59>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate'
     *
     * Regarding '<S61>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S71>/Data Type Duplicate'
     *
     * Regarding '<S71>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S72>/Data Type Duplicate'
     *
     * Regarding '<S72>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S59>/Add' incorporates:
     *  Constant: '<S59>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* MinMax: '<S59>/MinMax' incorporates:
     *  Constant: '<S59>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_a, 5U);

    /* Sum: '<S60>/Add' incorporates:
     *  Constant: '<S60>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* MinMax: '<S60>/MinMax' incorporates:
     *  Constant: '<S60>/Constant'
     */
    localmin_0 = (SInt32)rt_MIN(localAdd_a, 5U);

    /* Sum: '<S61>/Add' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* DataTypeConversion: '<S53>/Data Type Conversion2' incorporates:
     *  Constant: '<S61>/Constant'
     *  MinMax: '<S61>/MinMax'
     *  Selector: '<S59>/Selector'
     *  Selector: '<S60>/Selector'
     *  Selector: '<S61>/Selector'
     */
    InjrSys_prm_mFuInjReq[0] = ((Float32)localSelector_jb) * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[1] = ((Float32)localSelector_h5) * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[2] = ((Float32)localSelector_lm) * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[3] = ((Float32)tiFuSp_B.VEMS_vidGET12_k[(localmin)]) *
      7.450580597E-009F;
    InjrSys_prm_mFuInjReq[4] = ((Float32)tiFuSp_B.VEMS_vidGET11_j[(localmin_0)])
      * 7.450580597E-009F;
    InjrSys_prm_mFuInjReq[5] = ((Float32)tiFuSp_B.VEMS_vidGET12_k[rt_MIN
      (localAdd_a, 5U)]) * 7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, tiFuSp_B.VEMS_vidGET6);

    /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate'
     *
     * Regarding '<S65>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S76>/Data Type Duplicate'
     *
     * Regarding '<S76>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S65>/Add' incorporates:
     *  Constant: '<S65>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* MinMax: '<S65>/MinMax' incorporates:
     *  Constant: '<S65>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_a, 5U);

    /* Sum: '<S76>/Add' incorporates:
     *  Constant: '<S76>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* DataTypeConversion: '<S53>/Data Type Conversion3' incorporates:
     *  Constant: '<S76>/Constant'
     *  MinMax: '<S76>/MinMax'
     *  Selector: '<S65>/Selector'
     *  Selector: '<S76>/Selector'
     */
    InjrSys_prm_agEndInjH1[0] = ((Float32)tiFuSp_B.VEMS_vidGET6[(localmin)]) *
      0.0625F;
    InjrSys_prm_agEndInjH1[1] = ((Float32)tiFuSp_B.VEMS_vidGET6[rt_MIN
      (localAdd_a, 5U)]) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, tiFuSp_B.VEMS_vidGET7);

    /* DataTypeDuplicate Block: '<S85>/Data Type Duplicate'
     *
     * Regarding '<S85>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S86>/Data Type Duplicate'
     *
     * Regarding '<S86>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S85>/Add' incorporates:
     *  Constant: '<S85>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* MinMax: '<S85>/MinMax' incorporates:
     *  Constant: '<S85>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_a, 5U);

    /* Sum: '<S86>/Add' incorporates:
     *  Constant: '<S86>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* DataTypeConversion: '<S53>/Data Type Conversion4' incorporates:
     *  Constant: '<S86>/Constant'
     *  MinMax: '<S86>/MinMax'
     *  Selector: '<S85>/Selector'
     *  Selector: '<S86>/Selector'
     */
    InjrSys_prm_agEndInjH2[0] = ((Float32)tiFuSp_B.VEMS_vidGET7[(localmin)]) *
      0.0625F;
    InjrSys_prm_agEndInjH2[1] = ((Float32)tiFuSp_B.VEMS_vidGET7[rt_MIN
      (localAdd_a, 5U)]) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, tiFuSp_B.VEMS_vidGET2_h);

    /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate'
     *
     * Regarding '<S54>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S82>/Data Type Duplicate'
     *
     * Regarding '<S82>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S82>/Add' incorporates:
     *  Constant: '<S82>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* Selector: '<S82>/Selector' incorporates:
     *  Constant: '<S82>/Constant'
     *  MinMax: '<S82>/MinMax'
     */
    localSelector_bd = tiFuSp_B.VEMS_vidGET2_h[rt_MIN(localAdd_a, 5U)];

    /* DataTypeConversion: '<S53>/Data Type Conversion5' */
    InjrSys_agBegInjH1 = ((Float32)localSelector_bd) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, tiFuSp_B.VEMS_vidGET8);

    /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate'
     *
     * Regarding '<S64>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S66>/Data Type Duplicate'
     *
     * Regarding '<S66>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S64>/Add' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* MinMax: '<S64>/MinMax' incorporates:
     *  Constant: '<S64>/Constant'
     */
    localmin = (SInt32)rt_MIN(localAdd_a, 5U);

    /* Sum: '<S66>/Add' incorporates:
     *  Constant: '<S66>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* DataTypeConversion: '<S53>/Data Type Conversion6' incorporates:
     *  Constant: '<S66>/Constant'
     *  MinMax: '<S66>/MinMax'
     *  Selector: '<S64>/Selector'
     *  Selector: '<S66>/Selector'
     */
    InjrSys_prm_agEndInjS1[0] = ((Float32)tiFuSp_B.VEMS_vidGET8[(localmin)]) *
      0.09375F;
    InjrSys_prm_agEndInjS1[1] = ((Float32)tiFuSp_B.VEMS_vidGET8[rt_MIN
      (localAdd_a, 5U)]) * 0.09375F;

    /* Sum: '<S54>/Add' incorporates:
     *  Constant: '<S54>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* DataTypeConversion: '<S53>/Data Type Conversion9' incorporates:
     *  Constant: '<S54>/Constant'
     *  MinMax: '<S54>/MinMax'
     *  Selector: '<S54>/Selector'
     */
    InjrSys_prm_agBegInjH1[0] = (UInt16)((((UInt32)localSelector_bd) *
      43691U) >> 16U);
    InjrSys_prm_agBegInjH1[1] = (UInt16)((((UInt32)
      tiFuSp_B.VEMS_vidGET2_h[rt_MIN(localAdd_a, 5U)]) * 43691U) >> 16U);

    /* MultiPortSwitch: '<S53>/Multiport Switch' incorporates:
     *  Constant: '<S53>/InjrSys_facCorInjETBCyl1_C'
     *  Constant: '<S53>/InjrSys_facCorInjETBCyl2_C'
     *  Constant: '<S53>/InjrSys_facCorInjETBCyl3_C'
     *  Constant: '<S53>/InjrSys_facCorInjETBCyl4_C'
     *  Constant: '<S53>/InjrSys_facCorInjETBCyl5_C'
     *  Constant: '<S53>/InjrSys_facCorInjETBCyl6_C'
     */
    switch ((UInt32)((SInt32)localAdd_k)) {
     case 1:
      locallocalMultiportSwitch_g_i_0 = InjrSys_facCorInjETBCyl1_C;
      break;

     case 2:
      locallocalMultiportSwitch_g_i_0 = InjrSys_facCorInjETBCyl2_C;
      break;

     case 3:
      locallocalMultiportSwitch_g_i_0 = InjrSys_facCorInjETBCyl3_C;
      break;

     case 4:
      locallocalMultiportSwitch_g_i_0 = InjrSys_facCorInjETBCyl4_C;
      break;

     case 5:
      locallocalMultiportSwitch_g_i_0 = InjrSys_facCorInjETBCyl5_C;
      break;

     default:
      locallocalMultiportSwitch_g_i_0 = InjrSys_facCorInjETBCyl6_C;
      break;
    }

    switch ((UInt32)((SInt32)localAdd_j)) {
     case 1:
      locallocalMultiportSwitch_g_idx = InjrSys_facCorInjETBCyl1_C;
      break;

     case 2:
      locallocalMultiportSwitch_g_idx = InjrSys_facCorInjETBCyl2_C;
      break;

     case 3:
      locallocalMultiportSwitch_g_idx = InjrSys_facCorInjETBCyl3_C;
      break;

     case 4:
      locallocalMultiportSwitch_g_idx = InjrSys_facCorInjETBCyl4_C;
      break;

     case 5:
      locallocalMultiportSwitch_g_idx = InjrSys_facCorInjETBCyl5_C;
      break;

     default:
      locallocalMultiportSwitch_g_idx = InjrSys_facCorInjETBCyl6_C;
      break;
    }

    /* Sum: '<S55>/Add' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* Selector: '<S55>/Selector' incorporates:
     *  Constant: '<S55>/Constant'
     *  MinMax: '<S55>/MinMax'
     */
    localSelector_bd = tiFuSp_B.VEMS_vidGET10_n[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S62>/Add' incorporates:
     *  Constant: '<S62>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, tiFuSp_B.VEMS_vidGET4_c);

    /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate'
     *
     * Regarding '<S62>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate'
     *
     * Regarding '<S63>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S62>/Selector' incorporates:
     *  Constant: '<S62>/Constant'
     *  MinMax: '<S62>/MinMax'
     */
    localSelector_fy = tiFuSp_B.VEMS_vidGET4_c[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S63>/Add' incorporates:
     *  Constant: '<S63>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* Selector: '<S63>/Selector' incorporates:
     *  Constant: '<S63>/Constant'
     *  MinMax: '<S63>/MinMax'
     */
    localSelector_jb = tiFuSp_B.VEMS_vidGET4_c[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S67>/Add' incorporates:
     *  Constant: '<S67>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, tiFuSp_B.VEMS_vidGET5);

    /* DataTypeDuplicate Block: '<S67>/Data Type Duplicate'
     *
     * Regarding '<S67>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S68>/Data Type Duplicate'
     *
     * Regarding '<S68>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S67>/Selector' incorporates:
     *  Constant: '<S67>/Constant'
     *  MinMax: '<S67>/MinMax'
     */
    localSelector_h5 = tiFuSp_B.VEMS_vidGET5[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S68>/Add' incorporates:
     *  Constant: '<S68>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* Selector: '<S68>/Selector' incorporates:
     *  Constant: '<S68>/Constant'
     *  MinMax: '<S68>/MinMax'
     */
    localSelector_lm = tiFuSp_B.VEMS_vidGET5[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S69>/Add' incorporates:
     *  Constant: '<S69>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* Selector: '<S69>/Selector' incorporates:
     *  Constant: '<S69>/Constant'
     *  MinMax: '<S69>/MinMax'
     */
    localSelector_kn = tiFuSp_B.VEMS_vidGET11_j[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S70>/Add' incorporates:
     *  Constant: '<S70>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* Selector: '<S70>/Selector' incorporates:
     *  Constant: '<S70>/Constant'
     *  MinMax: '<S70>/MinMax'
     */
    localSelector_fs = tiFuSp_B.VEMS_vidGET11_j[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S71>/Add' incorporates:
     *  Constant: '<S71>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* Selector: '<S71>/Selector' incorporates:
     *  Constant: '<S71>/Constant'
     *  MinMax: '<S71>/MinMax'
     */
    localSelector_kf = tiFuSp_B.VEMS_vidGET12_k[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S72>/Add' incorporates:
     *  Constant: '<S72>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* Selector: '<S72>/Selector' incorporates:
     *  Constant: '<S72>/Constant'
     *  MinMax: '<S72>/MinMax'
     */
    localSelector_ec = tiFuSp_B.VEMS_vidGET12_k[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S73>/Add' incorporates:
     *  Constant: '<S73>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET17 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH1Cyl, 6, tiFuSp_B.VEMS_vidGET17);

    /* DataTypeDuplicate Block: '<S73>/Data Type Duplicate'
     *
     * Regarding '<S73>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S73>/Selector' incorporates:
     *  Constant: '<S73>/Constant'
     *  MinMax: '<S73>/MinMax'
     */
    localSelector_a = tiFuSp_B.VEMS_vidGET17[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S74>/Add' incorporates:
     *  Constant: '<S74>/Constant1'
     */
    localAdd_a = localAdd_k - 1U;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET18 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH2Cyl, 6, tiFuSp_B.VEMS_vidGET18);

    /* DataTypeDuplicate Block: '<S74>/Data Type Duplicate'
     *
     * Regarding '<S74>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S74>/Selector' incorporates:
     *  Constant: '<S74>/Constant'
     *  MinMax: '<S74>/MinMax'
     */
    localSelector_jkm = tiFuSp_B.VEMS_vidGET18[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S75>/Add' incorporates:
     *  Constant: '<S75>/Constant1'
     */
    localAdd_a = localAdd_j - 1U;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET19 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS1Cyl, 6, tiFuSp_B.VEMS_vidGET19);

    /* DataTypeDuplicate Block: '<S75>/Data Type Duplicate'
     *
     * Regarding '<S75>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S75>/Selector' incorporates:
     *  Constant: '<S75>/Constant'
     *  MinMax: '<S75>/MinMax'
     */
    localSelector_fi = tiFuSp_B.VEMS_vidGET19[rt_MIN(localAdd_a, 5U)];

    /* Sum: '<S77>/Add' incorporates:
     *  Constant: '<S77>/Constant1'
     */
    localAdd_j--;

    /* S-Function "vems_vidGET" Block: <S53>/VEMS_vidGET20 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS2Cyl, 6, tiFuSp_B.VEMS_vidGET20);

    /* DataTypeDuplicate Block: '<S77>/Data Type Duplicate'
     *
     * Regarding '<S77>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S77>/Selector' incorporates:
     *  Constant: '<S77>/Constant'
     *  MinMax: '<S77>/MinMax'
     */
    localSelector_le = tiFuSp_B.VEMS_vidGET20[rt_MIN(localAdd_j, 5U)];

    /* Sum: '<S87>/Add' incorporates:
     *  Constant: '<S87>/Constant1'
     */
    localAdd_k--;

    /* SignalConversion: '<S53>/Signal Conversion1' */
    InjrSys_facCorInjETBCmpr = locallocalMultiportSwitch_g_idx;

    /* SignalConversion: '<S53>/Signal Conversion10' */
    InjrSys_prm_agBegInjS2[0] = localSelector_h5;
    InjrSys_prm_agBegInjS2[1] = localSelector_lm;

    /* SignalConversion: '<S53>/Signal Conversion13' */
    InjrSys_prm_tiInjOfs[0] = localSelector_a;
    InjrSys_prm_tiInjOfs[1] = localSelector_jkm;
    InjrSys_prm_tiInjOfs[2] = localSelector_fi;
    InjrSys_prm_tiInjOfs[3] = localSelector_le;
    InjrSys_prm_tiInjOfs[4] = localSelector_fi;
    InjrSys_prm_tiInjOfs[5] = localSelector_le;

    /* SignalConversion: '<S53>/Signal Conversion2' incorporates:
     *  Constant: '<S87>/Constant'
     *  MinMax: '<S87>/MinMax'
     *  Selector: '<S87>/Selector'
     */
    InjrSys_prm_mFuInjH2Req[0] = tiFuSp_B.VEMS_vidGET10_n[rt_MIN(localAdd_k, 5U)];
    InjrSys_prm_mFuInjH2Req[1] = localSelector_bd;

    /* SignalConversion: '<S53>/Signal Conversion3' */
    InjrSys_prm_mFuInjS1Req[0] = localSelector_kn;
    InjrSys_prm_mFuInjS1Req[1] = localSelector_fs;

    /* SignalConversion: '<S53>/Signal Conversion4' */
    InjrSys_prm_mFuInjS2Req[0] = localSelector_kf;
    InjrSys_prm_mFuInjS2Req[1] = localSelector_ec;

    /* SignalConversion: '<S53>/Signal Conversion7' */
    InjrSys_facCorInjETBIn = locallocalMultiportSwitch_g_i_0;

    /* SignalConversion: '<S53>/Signal Conversion8' */
    InjrSys_prm_agBegInjS1[0] = localSelector_fy;
    InjrSys_prm_agBegInjS1[1] = localSelector_jb;
  }

  /* end of Outputs for SubSystem: '<S17>/F00_tiFuSpSyncInEveInj' */
}

/* Output and update for function-call system: '<S9>/F02_InjtiSyncEveInj' */
void tiFuSp_F02_InjtiSyncEveInj(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_d;
  Boolean localRelationalOperator2_d;
  Boolean localLogicalOperator3_a;
  UInt32 localSelector_pn;
  UInt32 localSelector_cb;
  Float32 localDataTypeConversion8_l[6];
  UInt32 localSelector_n;
  UInt32 localSelector_en;
  UInt32 localSelector_p;
  UInt32 localSelector_m;
  UInt32 localSelector_mn;
  UInt32 localSelector_gy;
  UInt32 localAssignment_b[6];
  UInt32 localAssignment_a[6];
  UInt32 localAssignment_j1[6];
  UInt32 localOutDTConv_dl[6];
  SInt32 locali;
  Float32 locallocalDataTypeConversion8_l;

  /* RelationalOperator: '<S165>/Relational Operator' incorporates:
   *  Constant: '<S165>/ConstVal'
   *  Constant: '<S165>/TIFUSP_u8Inhib'
   */
  localRelationalOperator_d = (TIFUSP_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S165>/F00_InjtiSyncEveInj' incorporates:
   *  EnablePort: '<S167>/Enable'
   */
  if (localRelationalOperator_d) {
    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET4 */
    VEMS_vidGET(Eng_stEru, tiFuSp_B.VEMS_vidGET4_fk);

    /* RelationalOperator: '<S167>/Relational Operator2' incorporates:
     *  Constant: '<S167>/Ext_stStall_SC'
     */
    localRelationalOperator2_d = (tiFuSp_B.VEMS_vidGET4_fk == Ext_stStall_SC);

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET */
    VEMS_vidGET(ActrTstHPPmp_bInjAuthReq, tiFuSp_B.VEMS_vidGET_c);

    /* Logic: '<S167>/Logical Operator3' */
    localLogicalOperator3_a = !tiFuSp_B.VEMS_vidGET_c;

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET7 */
    VEMS_vidGET(Srv_bActrTstEna, tiFuSp_B.VEMS_vidGET7_c);

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET1 */
    VEMS_vidGET(Code_test_action, tiFuSp_B.VEMS_vidGET1_hr);

    /* Logic: '<S167>/Logical Operator1' incorporates:
     *  Constant: '<S167>/CODE_TEST_HPPMP'
     *  Logic: '<S167>/Logical Operator2'
     *  RelationalOperator: '<S167>/Relational Operator3'
     */
    localRelationalOperator2_d = ((localRelationalOperator2_d) ||
      (((localLogicalOperator3_a) && tiFuSp_B.VEMS_vidGET7_c) &&
       (tiFuSp_B.VEMS_vidGET1_hr == CODE_TEST_HPPMP)));

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_bCylCutOff, 6, tiFuSp_B.VEMS_vidGET6_o);

    /* SignalConversion: '<S167>/Signal Conversion1' */
    for (locali = 0; locali < 6; locali++) {
      InjrSys_prm_tiInjH1TmpCylPrev[(locali)] = InjrSys_prm_tiInjH1TmpCyl
        [(locali)];
    }

    /* Selector: '<S182>/Selector' incorporates:
     *  Constant: '<S167>/ConstVal_4'
     *  Constant: '<S182>/Constant'
     *  Constant: '<S182>/Constant1'
     *  MinMax: '<S182>/MinMax'
     *  Sum: '<S182>/Add'
     */
    localSelector_gy = InjrSys_prm_tiInjReq[0];

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET3 */
    VEMS_vidGET(Eng_noInNxtCyl, tiFuSp_B.VEMS_vidGET3_e);

    /* DataTypeConversion: '<S167>/Data Type Conversion2' */
    localSelector_pn = tiFuSp_B.VEMS_vidGET3_e;

    /* Sum: '<S168>/Add' incorporates:
     *  Constant: '<S168>/Constant1'
     */
    localSelector_cb = localSelector_pn - 1U;

    /* Assignment: '<S168>/Assignment' incorporates:
     *  Constant: '<S168>/Constant'
     *  MinMax: '<S168>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_b[locali] = InjrSys_prm_tiInjH1TmpCylPrev[(locali)];
    }

    localAssignment_b[(SInt32)rt_MIN(localSelector_cb, 5U)] = localSelector_gy;
    for (locali = 0; locali < 6; locali++) {
      localSelector_en = localAssignment_b[locali];

      /* Switch: '<S167>/Switch1' incorporates:
       *  Constant: '<S167>/ConstVal'
       */
      if (tiFuSp_B.VEMS_vidGET6_o[(locali)]) {
        localSelector_en = 0U;
      }

      /* Switch: '<S167>/Switch6' incorporates:
       *  Constant: '<S167>/ConstMat'
       */
      if (localRelationalOperator2_d) {
        localSelector_en = tiFuSp_ConstP.pooled16[(locali)];
      }

      localAssignment_b[locali] = localSelector_en;
    }

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_noInCyl, tiFuSp_B.VEMS_vidGET2_a);

    /* DataTypeConversion: '<S167>/Data Type Conversion3' */
    localSelector_cb = tiFuSp_B.VEMS_vidGET2_a;

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_InjClsRespCor_prmtiOfsH1, 6,
                       tiFuSp_B.VEMS_vidGET5_m);

    /* DataTypeConversion: '<S167>/Data Type Conversion8' */
    for (locali = 0; locali < 6; locali++) {
      localDataTypeConversion8_l[locali] = ((Float32)tiFuSp_B.VEMS_vidGET5_m
        [(locali)]) * 3.200000037E-006F;
    }

    /* Sum: '<S169>/Add' incorporates:
     *  Constant: '<S169>/Constant1'
     */
    localSelector_gy = localSelector_pn - 1U;

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjrSys_prm_tiInjH2ReqCyl, 6, InjrSys_prm_tiH2ReqCylPrev);

    /* DataTypeDuplicate Block: '<S169>/Data Type Duplicate'
     *
     * Regarding '<S169>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S169>/Data Type Duplicate1'
     *
     * Regarding '<S169>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S169>/Assignment' incorporates:
     *  Constant: '<S169>/Constant'
     *  Constant: '<S183>/Constant'
     *  MinMax: '<S169>/MinMax'
     *  MinMax: '<S183>/MinMax'
     *  Selector: '<S183>/Selector'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_a[locali] = InjrSys_prm_tiH2ReqCylPrev[(locali)];
    }

    localAssignment_a[(SInt32)rt_MIN(localSelector_gy, 5U)] =
      InjrSys_prm_tiInjReq[1];

    /* Sum: '<S170>/Add' incorporates:
     *  Constant: '<S170>/Constant1'
     */
    localSelector_n = localSelector_cb - 1U;

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjrSys_prm_tiInjS1ReqCyl, 6, InjrSys_prm_tiS1ReqCylPrev);

    /* DataTypeDuplicate Block: '<S170>/Data Type Duplicate'
     *
     * Regarding '<S170>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S170>/Data Type Duplicate1'
     *
     * Regarding '<S170>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S170>/Assignment' incorporates:
     *  Constant: '<S170>/Constant'
     *  Constant: '<S184>/Constant'
     *  MinMax: '<S170>/MinMax'
     *  MinMax: '<S184>/MinMax'
     *  Selector: '<S184>/Selector'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_j1[locali] = InjrSys_prm_tiS1ReqCylPrev[(locali)];
    }

    localAssignment_j1[(SInt32)rt_MIN(localSelector_n, 5U)] =
      InjrSys_prm_tiInjReq[4];

    /* Sum: '<S171>/Add' incorporates:
     *  Constant: '<S171>/Constant1'
     */
    localSelector_n = localSelector_cb - 1U;

    /* S-Function "vems_vidGET" Block: <S167>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjrSys_prm_tiInjS2ReqCyl, 6, InjrSys_prm_tiS2ReqCylPrev);

    /* DataTypeDuplicate Block: '<S171>/Data Type Duplicate'
     *
     * Regarding '<S171>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S171>/Data Type Duplicate1'
     *
     * Regarding '<S171>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S171>/Assignment' incorporates:
     *  Constant: '<S171>/Constant'
     *  Constant: '<S186>/Constant'
     *  MinMax: '<S171>/MinMax'
     *  MinMax: '<S186>/MinMax'
     *  Selector: '<S186>/Selector'
     */
    for (locali = 0; locali < 6; locali++) {
      localOutDTConv_dl[locali] = InjrSys_prm_tiS2ReqCylPrev[(locali)];

      /* Switch: '<S167>/Switch7' incorporates:
       *  Constant: '<S167>/ConstMat_4'
       *  Constant: '<S167>/ConstVal_5'
       *  Switch: '<S167>/Switch2'
       */
      if (localRelationalOperator2_d) {
        tiFuSp_B.Switch7[(locali)] = tiFuSp_ConstP.pooled16[(locali)];
      } else if (tiFuSp_B.VEMS_vidGET6_o[(locali)]) {
        tiFuSp_B.Switch7[(locali)] = 0U;
      } else {
        tiFuSp_B.Switch7[(locali)] = localAssignment_a[locali];
      }
    }

    localOutDTConv_dl[(SInt32)rt_MIN(localSelector_n, 5U)] =
      InjrSys_prm_tiInjReq[5];

    /* Sum: '<S172>/Add' incorporates:
     *  Constant: '<S172>/Constant1'
     */
    localSelector_n = localSelector_pn - 1U;

    /* Assignment: '<S172>/Assignment' incorporates:
     *  Constant: '<S172>/Constant'
     *  Constant: '<S185>/Constant'
     *  MinMax: '<S172>/MinMax'
     *  MinMax: '<S185>/MinMax'
     *  Selector: '<S185>/Selector'
     */
    localAssignment_j1[(SInt32)rt_MIN(localSelector_n, 5U)] =
      InjrSys_prm_tiInjReq[2];

    /* Sum: '<S173>/Add' incorporates:
     *  Constant: '<S173>/Constant1'
     */
    localSelector_n = localSelector_pn - 1U;

    /* Assignment: '<S173>/Assignment' incorporates:
     *  Constant: '<S173>/Constant'
     *  Constant: '<S187>/Constant'
     *  MinMax: '<S173>/MinMax'
     *  MinMax: '<S187>/MinMax'
     *  Selector: '<S187>/Selector'
     */
    localOutDTConv_dl[(SInt32)rt_MIN(localSelector_n, 5U)] =
      InjrSys_prm_tiInjReq[3];

    /* Sum: '<S174>/Add' incorporates:
     *  Constant: '<S174>/Constant1'
     */
    localSelector_n = localSelector_pn - 1U;

    /* Sum: '<S175>/Add' incorporates:
     *  Constant: '<S175>/Constant1'
     */
    localSelector_gy = localSelector_pn - 1U;

    /* Sum: '<S176>/Add' incorporates:
     *  Constant: '<S176>/Constant1'
     */
    localSelector_en = localSelector_pn - 1U;

    /* Sum: '<S177>/Add' incorporates:
     *  Constant: '<S177>/Constant1'
     */
    localSelector_p = localSelector_pn - 1U;

    /* Sum: '<S178>/Add' incorporates:
     *  Constant: '<S178>/Constant1'
     */
    localSelector_m = localSelector_pn - 1U;

    /* Sum: '<S179>/Add' incorporates:
     *  Constant: '<S179>/Constant1'
     */
    localSelector_pn--;

    /* Sum: '<S180>/Add' incorporates:
     *  Constant: '<S180>/Constant1'
     */
    localSelector_mn = localSelector_cb - 1U;

    /* Sum: '<S181>/Add' incorporates:
     *  Constant: '<S181>/Constant1'
     */
    localSelector_cb--;

    /* SignalConversion: '<S167>/Signal Conversion5' incorporates:
     *  Constant: '<S176>/Constant'
     *  Constant: '<S177>/Constant'
     *  Constant: '<S178>/Constant'
     *  Constant: '<S179>/Constant'
     *  MinMax: '<S176>/MinMax'
     *  MinMax: '<S177>/MinMax'
     *  MinMax: '<S178>/MinMax'
     *  MinMax: '<S179>/MinMax'
     *  Selector: '<S176>/Selector'
     *  Selector: '<S177>/Selector'
     *  Selector: '<S178>/Selector'
     *  Selector: '<S179>/Selector'
     */
    InjrSys_prm_tiInjMFu[0] = localAssignment_b[(SInt32)rt_MIN(localSelector_en,
      5U)];
    InjrSys_prm_tiInjMFu[1] = tiFuSp_B.Switch7[rt_MIN(localSelector_p, 5U)];
    for (locali = 0; locali < 6; locali++) {
      /* Switch: '<S167>/Switch8' incorporates:
       *  Constant: '<S167>/ConstMat_1'
       *  Constant: '<S167>/ConstVal_1'
       *  Switch: '<S167>/Switch3'
       */
      if (localRelationalOperator2_d) {
        tiFuSp_B.Switch8[(locali)] = tiFuSp_ConstP.pooled16[(locali)];
      } else if (tiFuSp_B.VEMS_vidGET6_o[(locali)]) {
        tiFuSp_B.Switch8[(locali)] = 0U;
      } else {
        tiFuSp_B.Switch8[(locali)] = localAssignment_j1[locali];
      }

      /* Switch: '<S167>/Switch5' incorporates:
       *  Constant: '<S167>/ConstMat_2'
       *  Constant: '<S167>/ConstVal_2'
       *  Switch: '<S167>/Switch4'
       */
      if (localRelationalOperator2_d) {
        tiFuSp_B.Switch5[(locali)] = tiFuSp_ConstP.pooled16[(locali)];
      } else if (tiFuSp_B.VEMS_vidGET6_o[(locali)]) {
        tiFuSp_B.Switch5[(locali)] = 0U;
      } else {
        tiFuSp_B.Switch5[(locali)] = localOutDTConv_dl[locali];
      }

      /* Sum: '<S167>/Sum2' incorporates:
       *  DataTypeConversion: '<S167>/Data Type Conversion1'
       */
      locallocalDataTypeConversion8_l = (((Float32)localAssignment_b[locali]) *
        3.200000037E-006F) - localDataTypeConversion8_l[locali];

      /* SignalConversion: '<S167>/Signal Conversion2' */
      InjrSys_prm_tiInjH1TmpCyl[(locali)] = localAssignment_b[locali];

      /* Switch: '<S167>/Switch9' incorporates:
       *  Constant: '<S167>/ConstVal_3'
       *  Constant: '<S188>/offset'
       *  Constant: '<S188>/offset1'
       *  Constant: '<S188>/one_on_slope'
       *  DataTypeConversion: '<S188>/OutDTConv'
       *  Product: '<S188>/Product4'
       *  RelationalOperator: '<S167>/Relational Operator1'
       *  Sum: '<S188>/Add1'
       *  Sum: '<S188>/Add2'
       */
      if (locallocalDataTypeConversion8_l > 0.0F) {
        locallocalDataTypeConversion8_l = (312500.0F *
          locallocalDataTypeConversion8_l) + 0.5F;
        if (locallocalDataTypeConversion8_l < 4.294967296E+009F) {
          localSelector_en = (UInt32)locallocalDataTypeConversion8_l;
        } else {
          localSelector_en = MAX_uint32_T;
        }

        tiFuSp_B.Switch9[(locali)] = localSelector_en;
      } else {
        tiFuSp_B.Switch9[(locali)] = localAssignment_b[locali];
      }
    }

    InjrSys_prm_tiInjMFu[2] = tiFuSp_B.Switch8[rt_MIN(localSelector_m, 5U)];
    InjrSys_prm_tiInjMFu[3] = tiFuSp_B.Switch5[rt_MIN(localSelector_pn, 5U)];

    /* SignalConversion: '<S167>/TmpSignal ConversionAtVEMS_vidSETInport1' incorporates:
     *  Constant: '<S174>/Constant'
     *  Constant: '<S175>/Constant'
     *  Constant: '<S180>/Constant'
     *  Constant: '<S181>/Constant'
     *  MinMax: '<S174>/MinMax'
     *  MinMax: '<S175>/MinMax'
     *  MinMax: '<S180>/MinMax'
     *  MinMax: '<S181>/MinMax'
     *  Selector: '<S174>/Selector'
     *  Selector: '<S175>/Selector'
     *  Selector: '<S180>/Selector'
     *  Selector: '<S181>/Selector'
     */
    tiFuSp_B.TmpSignalConversionAtVEMS_vidSE[0] = localAssignment_b[(SInt32)
      rt_MIN(localSelector_n, 5U)];
    tiFuSp_B.TmpSignalConversionAtVEMS_vidSE[1] = tiFuSp_B.Switch7[rt_MIN
      (localSelector_gy, 5U)];
    tiFuSp_B.TmpSignalConversionAtVEMS_vidSE[2] = tiFuSp_B.Switch8[rt_MIN
      (localSelector_mn, 5U)];
    tiFuSp_B.TmpSignalConversionAtVEMS_vidSE[3] = tiFuSp_B.Switch5[rt_MIN
      (localSelector_cb, 5U)];

    /* S-Function "vems_vidSET" Block: <S167>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjrSys_prm_tiInj, 4,
                       tiFuSp_B.TmpSignalConversionAtVEMS_vidSE);

    /* S-Function "vems_vidSET" Block: <S167>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjH1ReqCyl, 6, tiFuSp_B.Switch9);

    /* S-Function "vems_vidSET" Block: <S167>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjH2ReqCyl, 6, tiFuSp_B.Switch7);

    /* S-Function "vems_vidSET" Block: <S167>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjS1ReqCyl, 6, tiFuSp_B.Switch8);

    /* S-Function "vems_vidSET" Block: <S167>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjrSys_prm_tiInjS2ReqCyl, 6, tiFuSp_B.Switch5);
  }

  /* end of Outputs for SubSystem: '<S165>/F00_InjtiSyncEveInj' */
}

/* Output and update for function-call system: '<S10>/F02_InjmFu' */
void tiFuSp_F02_InjmFu(void)
{
  Float32 localDivide_d;
  Float32 localDivide_oz;
  Float32 localDivide_c2;
  Float32 localDivide_iv;
  UInt32 localtmp;
  UInt32 locallocalAdd1_nl;
  UInt16 locallocalDataTypeConversion;

  /* Outputs for enable SubSystem: '<S212>/F00_InjmFu' incorporates:
   *  Constant: '<S212>/ConstVal'
   *  Constant: '<S212>/TIFUSP_u8Inhib'
   *  EnablePort: '<S213>/Enable'
   *  RelationalOperator: '<S212>/Relational Operator'
   */
  if (TIFUSP_u8Inhib != 90) {
    /* Sum: '<S213>/Add1' */
    locallocalAdd1_nl = InjrSys_prm_tiInjMFu[0] + InjrSys_prm_tiInjMFu[1];
    if (locallocalAdd1_nl < InjrSys_prm_tiInjMFu[0]) {
      locallocalAdd1_nl = MAX_uint32_T;
    }

    localtmp = locallocalAdd1_nl + InjrSys_prm_tiInjMFu[2];
    if (localtmp < locallocalAdd1_nl) {
      localtmp = MAX_uint32_T;
    }

    locallocalAdd1_nl = localtmp + InjrSys_prm_tiInjMFu[3];
    if (locallocalAdd1_nl < localtmp) {
      locallocalAdd1_nl = MAX_uint32_T;
    }

    /* Product: '<S232>/Divide' incorporates:
     *  Constant: '<S213>/ConstVal_12'
     *  Constant: '<S213>/ConstVal_19'
     *  Constant: '<S213>/ConstVal_8'
     *  Constant: '<S215>/Constant'
     *  Constant: '<S215>/Constant1'
     *  Constant: '<S221>/Constant'
     *  Constant: '<S221>/Constant1'
     *  Constant: '<S226>/Constant'
     *  Constant: '<S226>/Constant1'
     *  DataTypeConversion: '<S213>/Data Type Conversion1'
     *  DataTypeConversion: '<S213>/Data Type Conversion8'
     *  MinMax: '<S215>/MinMax'
     *  MinMax: '<S221>/MinMax'
     *  MinMax: '<S226>/MinMax'
     *  Selector: '<S215>/Selector'
     *  Selector: '<S221>/Selector'
     *  Selector: '<S226>/Selector'
     *  Sum: '<S213>/Sum4'
     *  Sum: '<S215>/Add'
     *  Sum: '<S221>/Add'
     *  Sum: '<S226>/Add'
     */
    localDivide_d = ((((Float32)InjrSys_prm_tiInjMFu[0]) * 3.200000037E-006F) -
                     (((Float32)InjrSys_prm_tiInjOfsCor[0]) * 3.200000037E-006F))
      / InjrSys_prm_facGainCor[0];

    /* Outputs for atomic SubSystem: '<S232>/If Action Subsystem3' */

    /* Switch: '<S240>/Switch1' incorporates:
     *  Constant: '<S240>/Constant1'
     *  Constant: '<S240>/Constant2'
     *  Constant: '<S240>/Constant3'
     *  Logic: '<S240>/Logical Operator1'
     *  RelationalOperator: '<S240>/Relational Operator'
     *  RelationalOperator: '<S240>/Relational Operator1'
     *  RelationalOperator: '<S240>/Relational Operator3'
     */
    if (((localDivide_d != localDivide_d) || (localDivide_d > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_d)) {
      localDivide_d = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S232>/If Action Subsystem3' */

    /* Switch: '<S213>/Switch4' incorporates:
     *  Constant: '<S213>/ConstVal'
     *  Constant: '<S213>/ConstVal_1'
     *  Logic: '<S213>/Logical Operator4'
     *  RelationalOperator: '<S213>/Relational Operator4'
     *  Selector: '<S226>/Selector'
     */
    if (!(InjrSys_prm_tiInjMFu[0] > 0U)) {
      localDivide_d = 0.0F;
    }

    /* Product: '<S231>/Divide' incorporates:
     *  Constant: '<S216>/Constant'
     *  Constant: '<S220>/Constant'
     *  DataTypeConversion: '<S213>/Data Type Conversion2'
     *  DataTypeConversion: '<S213>/Data Type Conversion3'
     *  MinMax: '<S216>/MinMax'
     *  MinMax: '<S220>/MinMax'
     *  Selector: '<S216>/Selector'
     *  Selector: '<S219>/Selector'
     *  Selector: '<S220>/Selector'
     *  Sum: '<S213>/Sum1'
     */
    localDivide_oz = ((((Float32)InjrSys_prm_tiInjMFu[1]) * 3.200000037E-006F)
                      - (((Float32)InjrSys_prm_tiInjOfsCor[1]) *
                         3.200000037E-006F)) / InjrSys_prm_facGainCor[1];

    /* Outputs for atomic SubSystem: '<S231>/If Action Subsystem3' */

    /* Switch: '<S238>/Switch1' incorporates:
     *  Constant: '<S238>/Constant1'
     *  Constant: '<S238>/Constant2'
     *  Constant: '<S238>/Constant3'
     *  Logic: '<S238>/Logical Operator1'
     *  RelationalOperator: '<S238>/Relational Operator'
     *  RelationalOperator: '<S238>/Relational Operator1'
     *  RelationalOperator: '<S238>/Relational Operator3'
     */
    if (((localDivide_oz != localDivide_oz) || (localDivide_oz >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_oz)) {
      localDivide_oz = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S231>/If Action Subsystem3' */

    /* Switch: '<S213>/Switch1' incorporates:
     *  Constant: '<S213>/ConstVal_2'
     *  Constant: '<S213>/ConstVal_20'
     *  Logic: '<S213>/Logical Operator1'
     *  RelationalOperator: '<S213>/Relational Operator1'
     *  Selector: '<S216>/Selector'
     */
    if (!(InjrSys_prm_tiInjMFu[1] > 0U)) {
      localDivide_oz = 0.0F;
    }

    /* Product: '<S230>/Divide' incorporates:
     *  Constant: '<S217>/Constant'
     *  Constant: '<S223>/Constant'
     *  DataTypeConversion: '<S213>/Data Type Conversion4'
     *  DataTypeConversion: '<S213>/Data Type Conversion5'
     *  MinMax: '<S217>/MinMax'
     *  MinMax: '<S223>/MinMax'
     *  Selector: '<S217>/Selector'
     *  Selector: '<S222>/Selector'
     *  Selector: '<S223>/Selector'
     *  Sum: '<S213>/Sum2'
     */
    localDivide_c2 = ((((Float32)InjrSys_prm_tiInjMFu[2]) * 3.200000037E-006F)
                      - (((Float32)InjrSys_prm_tiInjOfsCor[4]) *
                         3.200000037E-006F)) / InjrSys_prm_facGainCor[4];

    /* Outputs for atomic SubSystem: '<S230>/If Action Subsystem3' */

    /* Switch: '<S236>/Switch1' incorporates:
     *  Constant: '<S236>/Constant1'
     *  Constant: '<S236>/Constant2'
     *  Constant: '<S236>/Constant3'
     *  Logic: '<S236>/Logical Operator1'
     *  RelationalOperator: '<S236>/Relational Operator'
     *  RelationalOperator: '<S236>/Relational Operator1'
     *  RelationalOperator: '<S236>/Relational Operator3'
     */
    if (((localDivide_c2 != localDivide_c2) || (localDivide_c2 >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_c2)) {
      localDivide_c2 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S230>/If Action Subsystem3' */

    /* Switch: '<S213>/Switch2' incorporates:
     *  Constant: '<S213>/ConstVal_3'
     *  Constant: '<S213>/ConstVal_5'
     *  Logic: '<S213>/Logical Operator2'
     *  RelationalOperator: '<S213>/Relational Operator2'
     *  Selector: '<S217>/Selector'
     */
    if (!(InjrSys_prm_tiInjMFu[2] > 0U)) {
      localDivide_c2 = 0.0F;
    }

    /* Product: '<S229>/Divide' incorporates:
     *  Constant: '<S218>/Constant'
     *  Constant: '<S225>/Constant'
     *  DataTypeConversion: '<S213>/Data Type Conversion6'
     *  DataTypeConversion: '<S213>/Data Type Conversion7'
     *  MinMax: '<S218>/MinMax'
     *  MinMax: '<S225>/MinMax'
     *  Selector: '<S218>/Selector'
     *  Selector: '<S224>/Selector'
     *  Selector: '<S225>/Selector'
     *  Sum: '<S213>/Sum3'
     */
    localDivide_iv = ((((Float32)InjrSys_prm_tiInjMFu[3]) * 3.200000037E-006F)
                      - (((Float32)InjrSys_prm_tiInjOfsCor[5]) *
                         3.200000037E-006F)) / InjrSys_prm_facGainCor[5];

    /* Outputs for atomic SubSystem: '<S229>/If Action Subsystem3' */

    /* Switch: '<S234>/Switch1' incorporates:
     *  Constant: '<S234>/Constant1'
     *  Constant: '<S234>/Constant2'
     *  Constant: '<S234>/Constant3'
     *  Logic: '<S234>/Logical Operator1'
     *  RelationalOperator: '<S234>/Relational Operator'
     *  RelationalOperator: '<S234>/Relational Operator1'
     *  RelationalOperator: '<S234>/Relational Operator3'
     */
    if (((localDivide_iv != localDivide_iv) || (localDivide_iv >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_iv)) {
      localDivide_iv = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S229>/If Action Subsystem3' */

    /* Switch: '<S213>/Switch3' incorporates:
     *  Constant: '<S213>/ConstVal_4'
     *  Constant: '<S213>/ConstVal_6'
     *  Logic: '<S213>/Logical Operator3'
     *  RelationalOperator: '<S213>/Relational Operator3'
     *  Selector: '<S218>/Selector'
     */
    if (!(InjrSys_prm_tiInjMFu[3] > 0U)) {
      localDivide_iv = 0.0F;
    }

    /* S-Function "vems_vidGET" Block: <S213>/VEMS_vidGET1 */
    VEMS_vidGET(InjSys_mFuReq, tiFuSp_B.VEMS_vidGET1);

    /* DataTypeConversion: '<S213>/Data Type Conversion9' */
    if (tiFuSp_B.VEMS_vidGET1 > 65535U) {
      locallocalDataTypeConversion = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion = (UInt16)tiFuSp_B.VEMS_vidGET1;
    }

    /* S-Function "vems_vidGET" Block: <S213>/VEMS_vidGET */
    VEMS_vidGET(Ext_pFuRailSplMes, tiFuSp_B.VEMS_vidGET);

    /* MultiPortSwitch: '<S213>/Multiport Switch' incorporates:
     *  Constant: '<S213>/InjrSys_noETBSelMassFuEstim_C'
     *  Constant: '<S227>/offset'
     *  Constant: '<S227>/offset1'
     *  Constant: '<S227>/one_on_slope'
     *  Constant: '<S228>/offset'
     *  Constant: '<S228>/offset1'
     *  Constant: '<S228>/one_on_slope'
     *  DataTypeConversion: '<S227>/OutDTConv'
     *  DataTypeConversion: '<S228>/OutDTConv'
     *  Lookup_n-D: '<S214>/Lookup Table (n-D)'
     *  Product: '<S227>/Product4'
     *  Product: '<S228>/Product4'
     *  Sum: '<S213>/Add2'
     *  Sum: '<S227>/Add1'
     *  Sum: '<S227>/Add2'
     *  Sum: '<S228>/Add1'
     *  Sum: '<S228>/Add2'
     */
    switch (InjrSys_noETBSelMassFuEstim_C) {
     case 0:
      tiFuSp_B.MultiportSwitch = locallocalDataTypeConversion;
      break;

     case 1:
      localDivide_d = (1.34217728E+008F * look2_1fdv2bdvbcvbfbbr3nfbbnx
                       (tiFuSp_B.VEMS_vidGET, locallocalAdd1_nl,
                        (&(InjrSys_pFuRailSplMes_A[0])),
                        (&(InjrSys_tiInjTotETB_A[0])),
                        (&(InjrSys_mFuInjEstimETB_M[0])),
                        &tiFuSp_ConstP.pooled10[0], 16U)) + 0.5F;
      if (localDivide_d < 65536.0F) {
        if (localDivide_d >= 0.0F) {
          tiFuSp_B.MultiportSwitch = (UInt16)localDivide_d;
        } else {
          tiFuSp_B.MultiportSwitch = 0U;
        }
      } else {
        tiFuSp_B.MultiportSwitch = MAX_uint16_T;
      }
      break;

     default:
      localDivide_d = ((((localDivide_d + localDivide_oz) + localDivide_c2) +
                        localDivide_iv) * 1.34217728E+008F) + 0.5F;
      if (localDivide_d < 65536.0F) {
        if (localDivide_d >= 0.0F) {
          tiFuSp_B.MultiportSwitch = (UInt16)localDivide_d;
        } else {
          tiFuSp_B.MultiportSwitch = 0U;
        }
      } else {
        tiFuSp_B.MultiportSwitch = MAX_uint16_T;
      }
      break;
    }

    /* S-Function "vems_vidSET" Block: <S213>/VEMS_vidSET */
    VEMS_vidSET(InjrSys_mFuInjEstim, tiFuSp_B.MultiportSwitch);
  }

  /* end of Outputs for SubSystem: '<S212>/F00_InjmFu' */
}

/* Start for exported function: InjrSys_EveInj_tiFuSp */
void InjrSys_EveInj_tiFuSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/tiFuSp_fc_demux3'
   */

  /* Start for S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S10>/F02_InjmFu'
   *  Start for SubSystem: '<S7>/F02_tiFuSpSyncInEveInj'
   *  Start for SubSystem: '<S9>/F02_InjtiSyncEveInj'
   */
}

/* Output and update for exported function: InjrSys_EveInj_tiFuSp */
void InjrSys_EveInj_tiFuSp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S6>/tiFuSp_fc_demux3'
   */

  /* S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  SubSystem: '<S7>/F02_tiFuSpSyncInEveInj'
   *  SubSystem: '<S9>/F02_InjtiSyncEveInj'
   */
  tiFuSp_F02_tiFuSpSyncInEveInj();
  tiFuSp_ASYNC5(2);
  tiFuSp_F02_InjtiSyncEveInj();
  tiFuSp_ASYNC4(0);
}

/* Output and update for function-call system: '<S8>/F01_tiFuSpRst' */
void tiFuSp_F01_tiFuSpRst(void)
{
  SInt32 locali;

  /* DataStoreWrite: '<S88>/InjrSys_prm_bDettiInjMin_DSW' incorporates:
   *  Constant: '<S88>/ConstMat'
   */
  for (locali = 0; locali < 6; locali++) {
    InjrSys_prm_bDettiInjMin[(locali)] = tiFuSp_ConstP.pooled20[(locali)];
  }
}

/* Output and update for function-call system: '<S9>/F01_InjtiSyncIni' */
void tiFuSp_F01_InjtiSyncIni(void)
{
  /* SignalConversion: '<S164>/Signal Conversion5' incorporates:
   *  Constant: '<S164>/ConstMat_3'
   */
  InjrSys_prm_tiInjMFu[0] = 0U;
  InjrSys_prm_tiInjMFu[1] = 0U;
  InjrSys_prm_tiInjMFu[2] = 0U;
  InjrSys_prm_tiInjMFu[3] = 0U;

  /* S-Function "vems_vidSET" Block: <S164>/VEMS_vidSET */
  {
    UInt32 localArray[4] = {
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjrSys_prm_tiInj, 4 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S164>/VEMS_vidSET1 */
  {
    UInt32 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjrSys_prm_tiInjH1ReqCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S164>/VEMS_vidSET2 */
  {
    UInt32 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjrSys_prm_tiInjH2ReqCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S164>/VEMS_vidSET3 */
  {
    UInt32 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjrSys_prm_tiInjS1ReqCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S164>/VEMS_vidSET4 */
  {
    UInt32 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjrSys_prm_tiInjS2ReqCyl, 6 , localArray );
  }
}

/* Output and update for function-call system: '<S10>/F01_InjmFuIni' */
void tiFuSp_F01_InjmFuIni(void)
{
  /* S-Function "vems_vidSET" Block: <S211>/VEMS_vidSET */
  VEMS_vidSET(InjrSys_mFuInjEstim, 0U);
}

/* Start for exported function: InjrSys_EveRst_tiFuSp */
void InjrSys_EveRst_tiFuSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/tiFuSp_fc_demux5'
   */

  /* Start for S-Function (fcncallgen): '<S15>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S10>/F01_InjmFuIni'
   *  Start for SubSystem: '<S8>/F01_tiFuSpRst'
   *  Start for SubSystem: '<S9>/F01_InjtiSyncIni'
   */
}

/* Output and update for exported function: InjrSys_EveRst_tiFuSp */
void InjrSys_EveRst_tiFuSp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S6>/tiFuSp_fc_demux5'
   */

  /* S-Function (fcncallgen): '<S15>/Function-Call Generator' incorporates:
   *  SubSystem: '<S10>/F01_InjmFuIni'
   *  SubSystem: '<S8>/F01_tiFuSpRst'
   *  SubSystem: '<S9>/F01_InjtiSyncIni'
   */
  tiFuSp_F01_tiFuSpRst();
  tiFuSp_F01_InjtiSyncIni();
  tiFuSp_F01_InjmFuIni();
}

/* Output and update for exported function: InjrSys_EveSpl_tiFuSp */
void InjrSys_EveSpl_tiFuSp(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S6>/tiFuSp_fc_demux4'
   */

  /* S-Function (fcncallgen): '<S14>/Function-Call Generator' */
  tiFuSp_F01_tiFuSpSyncInEveClcn();
  tiFuSp_F02_tiFuSpClcn();
  tiFuSp_F03_InjtiSyncEveClcn();  
  tiFuSp_F02_InjmFu();
}

/* Output and update for exported function: InjrSys_SdlFast_tiFuSp */
void InjrSys_SdlFast_tiFuSp(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S6>/tiFuSp_fc_demux2'
   */

  /* S-Function (fcncallgen): '<S12>/Function-Call Generator' */
  tiFuSp_F01_tiFuSpSyncInEveClcn();
  tiFuSp_F02_tiFuSpClcn();
  tiFuSp_F03_InjtiSyncEveClcn();  
  tiFuSp_F02_InjmFu();
}

/* Model initialize function */
void tiFuSp_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    tiFuSp_B.VEMS_vidGET5_l = 96U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  InjrSys_EveCkSnOn_tiFuSp_Start();
  InjrSys_EveInj_tiFuSp_Start();
  InjrSys_EveRst_tiFuSp_Start();
}

#define TIFUSP_STOP_SEC_CODE
#include "tiFuSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
