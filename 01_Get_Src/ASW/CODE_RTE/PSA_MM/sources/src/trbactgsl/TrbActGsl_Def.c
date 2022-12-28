/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActGsl                                               */
/* !Description     : TrbActGsl Software Component                            */
/*                                                                            */
/* !Module          : TrbActGsl                                               */
/*                                                                            */
/* !File            : TrbActGsl_Def.c                                         */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : TrbActGsl_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActGsl                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M15-TrbActGsl/5-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   15 Jan 2013 $*/
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

/* !Comment: Define data in section "CARTO_16BIT" */
#define TrbActGsl_START_SEC_CARTO_16BIT
#include "TrbActGsl_MemMap.h"

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_facFltRCOReqWoutAdp_T[9] = { 64881U,
  64881U, 64881U, 64881U, 64881U, 64881U, 64881U, 64881U, 64881U } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_facFltUsPresCorErr_T[9] = { 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U } ;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifPnmActEstim_M[9][9] = { { 10000, 9380,
  8724, 8203, 7500, 6120, 4843, 2291, 0 },{ 10000, 9375, 8725, 8200, 7500, 6125,
  4850, 2287, 0 },{ 10000, 9375, 8725, 8200, 7500, 6125, 4850, 2287, 0 },{ 10000, 9375,
  8725, 8200, 7500, 6125, 4850, 2287, 0 },{ 10000, 9375, 8725, 8200, 7500, 6125,
  4850, 2287, 0 },{ 10000, 9375, 8725, 8200, 7500, 6125, 4850, 2287, 0 },{ 10000, 9375,
  8725, 8200, 7500, 6125, 4850, 2287, 0 },{ 10000, 9375, 8725, 8200, 7500, 6125,
  4850, 2287, 0 },{ 10000, 9375, 8725, 8200, 7500, 6125, 4850, 2287, 0 } } ;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifPnmActReq_A[16] = { 0, 1250, 2500,
  3125, 3750, 4125, 4375, 4687, 5000, 6250, 7500, 8125, 8750, 9125, 9375, 10000
} ;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifTrbActEstim_A[16] = { 0, 625, 1250,
  1875, 2500, 2875, 3125, 3750, 4375, 5000, 5625, 6250, 6875, 7500, 8437, 9187 }
;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifTrbActReqAdd_M[9][16] = { { 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0 } } ;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifTrbActReq_M[16][16] = { { -3820, -3945,
  -4067, -4250, -4750, -5125, -5625, -5875, -6250, -6500, -6875, -7250, -7625,
  -8000, -8375, -8750 },{ -3320, -3445, -3567, -3750, -4250, -4625, -5125, -5375,
  -5750, -6000, -6375, -6750, -7125, -7500, -7875, -8250 },{ -3204, -3329, -3448,
  -3625, -4125, -4375, -4875, -5250, -5625, -5875, -6250, -6625, -7000, -7375,
  -7750, -8125 },{ -3088, -3213, -3328, -3500, -4000, -4250, -4750, -5125, -5500,
  -5750, -6000, -6375, -6875, -7250, -7625, -8000 },{ -2987, -3112, -3218, -3375,
  -3875, -4125, -4625, -5000, -5375, -5625, -5875, -6250, -6625, -7000, -7375,
  -7625 },{ -2933, -3058, -3160, -3313, -3750, -4063, -4500, -4875, -5250, -5500,
  -5750, -6000, -6375, -6750, -7125, -7375 },{ -2878, -3003, -3102, -3250, -3625,
  -4002, -4375, -4750, -5125, -5375, -5625, -5875, -6250, -6625, -7000, -7125 },
{ -2823, -2948, -3044, -3188, -3501, -3876, -4125, -4625, -5000, -5250, -5500,
  -5750, -6125, -6500, -6750, -6875 },{ -2768, -2893, -2961, -3063, -3410, -3751,
  -4013, -4313, -4750, -5125, -5388, -5438, -5750, -6125, -6500, -6625 },{ -2525,
  -2650, -2778, -2971, -3288, -3597, -3693, -4112, -4499, -4763, -5000, -5063,
  -5413, -5925, -6250, -6375 },{ -2196, -2321, -2496, -2757, -2996, -3298, -3497,
  -3739, -4101, -4409, -4663, -4813, -5163, -5475, -5875, -6250 },{ -1850, -1975,
  -2133, -2370, -2513, -2812, -3122, -3337, -3693, -3932, -4151, -4468, -4838,
  -5144, -5444, -5744 },{ -1608, -1733, -1870, -2076, -2148, -2457, -2848, -3032,
  -3421, -3730, -3965, -4148, -4451, -4688, -5000, -5313 },{ -1140, -1265, -1387,
  -1571, -1478, -1956, -2343, -2549, -2917, -3138, -3488, -3538, -3750, -4000,
  -4125, -4375 },{ -782, -907, -1028, -1210, -949, -1679, -1861, -2045, -2207,
  -2500, -2950, -3013, -3250, -3625, -3750, -3875 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0 } } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_pDsCmpr_A[16] = { 0U, 2500U, 5000U,
  7500U, 10000U, 12500U, 15000U, 17500U, 20000U, 22500U, 25000U, 27500U, 30000U,
  32500U, 35000U, 37500U } ;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pUsThrCorErrFil_A[9] = { -32767, -12500,
  -6250, -2500, 0, 2500, 6250, 12500, 32767 } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rOpTrbActEstim_M[16][16] = { { 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U },{ 60296U, 61018U, 61551U, 62149U, 61219U, 63095U,
  63334U, 63532U, 63680U, 63898U, 64148U, 64176U, 64276U, 64406U, 64444U, 64479U },
{ 50882U, 52698U, 54927U, 58246U, 55250U, 60654U, 61132U, 61529U, 61824U, 62259U,
  62759U, 62817U, 63015U, 63276U, 63351U, 63422U },{ 38836U, 42007U, 45736U, 48475U,
  48542U, 54327U, 58783U, 59525U, 59967U, 60621U, 61371U, 61457U, 61755U, 62146U,
  62259U, 62365U },{ 26703U, 29197U, 32659U, 37118U, 39554U, 45074U, 50388U, 53059U,
  56274U, 58982U, 59982U, 60097U, 60495U, 61016U, 61167U, 61308U },{ 9961U, 20134U,
  22727U, 29136U, 34401U, 38461U, 45218U, 47999U, 52811U, 55129U, 59149U, 59282U,
  59739U, 60338U, 60512U, 60674U },{ 4391U, 6340U, 9160U, 16384U, 29854U, 35093U,
  39266U, 43870U, 49718U, 52560U, 56849U, 57578U, 59234U, 59886U, 60075U, 60251U },
{ 228U, 637U, 1038U, 1638U, 8192U, 19666U, 25036U, 32570U, 38393U, 45225U,
  48819U, 50147U, 52429U, 56798U, 58982U, 59194U },{ 0U, 0U, 0U, 0U, 1229U, 3277U,
  9830U, 18350U, 28243U, 33223U, 36449U, 41224U, 46578U, 48854U, 50556U, 52429U },
{ 0U, 0U, 0U, 0U, 0U, 410U, 2458U, 6554U, 13107U, 21921U, 26214U, 27853U, 36045U,
  41386U, 45875U, 48060U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 819U, 3277U, 6554U, 9830U,
  15729U, 22088U, 30583U, 36567U, 41126U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  819U, 3277U, 6554U, 9830U, 17476U, 26214U, 32768U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 1229U, 4915U, 7373U, 11469U, 13107U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 410U, 1638U, 5734U, 7373U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1024U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rOpTrbActReq_A[16] = { 0U, 1638U, 3277U,
  4915U, 6554U, 8192U, 9830U, 13107U, 19661U, 26214U, 32768U, 39322U, 45875U,
  52429U, 58982U, 65529U } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReqAddCor_T[16] = { 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReqAdd_A[16] = { 327U, 6553U, 13107U,
  19660U, 26214U, 32768U, 36044U, 39321U, 42598U, 45875U, 49152U, 52428U, 55705U,
  58982U, 62259U, 65208U } ;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_rRCOReqFastAddCor_T[9] = { 0, 0, 0, 0, 0,
  0, 0, 0, 0 } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReq_A[9] = { 0U, 32505U, 41501U,
  45875U, 50463U, 55321U, 57999U, 61932U, 65535U } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReq_M[16][9] = { { 65529U, 63734U,
  61932U, 60948U, 59965U, 59376U, 58982U, 58491U, 57999U },{ 55319U, 50463U, 46642U,
  41504U, 36104U, 32506U, 0U, 65529U, 63734U },{ 61932U, 60948U, 59965U, 59376U,
  58982U, 58491U, 57999U, 55319U, 50463U },{ 46642U, 41504U, 36104U, 32506U, 0U,
  65529U, 63734U, 61932U, 60948U },{ 59965U, 59376U, 58982U, 58491U, 57999U, 55319U,
  50463U, 46642U, 41504U },{ 36104U, 32506U, 0U, 65529U, 63734U, 61932U, 60948U,
  59965U, 59376U },{ 58982U, 58491U, 57999U, 55319U, 50463U, 46642U, 41504U, 36104U,
  32506U },{ 0U, 65529U, 63734U, 61932U, 60948U, 59965U, 59376U, 58982U, 58491U },
{ 57999U, 55319U, 50463U, 46642U, 41504U, 36104U, 32506U, 0U, 65529U },{ 63734U,
  61932U, 60948U, 59965U, 59376U, 58982U, 58491U, 57999U, 55319U },{ 50463U, 46642U,
  41504U, 36104U, 32506U, 0U, 65529U, 63734U, 61932U },{ 60948U, 59965U, 59376U,
  58982U, 58491U, 57999U, 55319U, 50463U, 46642U },{ 41504U, 36104U, 32506U, 0U,
  65529U, 63734U, 61932U, 60948U, 59965U },{ 59376U, 58982U, 58491U, 57999U, 55319U,
  50463U, 46642U, 41504U, 36104U },{ 32506U, 0U, 65529U, 63734U, 61932U, 60948U,
  59965U, 59376U, 58982U },{ 58491U, 57999U, 55319U, 50463U, 46642U, 41504U, 36104U,
  32506U, 0U } } ;

CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOTestMod_M[9][9] = { { 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },
{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U } } ;

CONST(SInt16, TRBACTGSL_CARTO) TrbAct_tqIdcAirReq_A[9] = { 160, 320, 480, 640,
  800, 960, 1120, 1280, 1440 } ;

#define TrbActGsl_STOP_SEC_CARTO_16BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define TrbActGsl_START_SEC_CALIB_16BIT
#include "TrbActGsl_MemMap.h"

CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facFilGainTrbActPosn_C = 4856U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facFltPresDsCmpr_C = 65470U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facPresReqAdpOfs_C = 17U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facPresReqAdpRate_C = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facRCOReqAdpOfs_C = 655U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facRCOReqAdpRate_C = 655U;
CONST(SInt16, TRBACTGSL_CALIB) TrbAct_pDifMaxPnmActReq_B = -32768;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pDifPnmActHys_C = 625U;
CONST(SInt16, TRBACTGSL_CALIB) TrbAct_pDifTrbActReq_B = -32768;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pUsThrCorErrMax_C = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pUsThrCorErrMin_C = 65535U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pVacRef_C = 2500U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rCtlIntErrMax_C = 1311U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rCtlIntErrMin_C = 64224U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpOfsThd1_C = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpOfsThd2_C = 65535U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpRateThd1_C = 65535U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpRateThd2_C = 32768U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpTrbActEstimIni_C = 65535U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpTrbActEstim_B = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpTrbAct_B = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOMaxThd_C = 65535U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOMinThd_C = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpOfsMax_C = 6554U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpOfsMin_C = 58981U;
CONST(SInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpOfs_B = 0;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpRateMax_C = 6554U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpRateMin_C = 58981U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpRate_B = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqIni_C = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqRaw_B = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReq_B = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReq_C = 0U;
CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOTestMod_C = 0U;

#define TrbActGsl_STOP_SEC_CALIB_16BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define TrbActGsl_START_SEC_CALIB_BOOLEAN
#include "TrbActGsl_MemMap.h"

CONST(Boolean, TRBACTGSL_CALIB) TRBACTGSL_ACTIVE_BYP_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOAdp_C = 1;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOModTest_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOTestModRef1_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOTestModRef2_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bExtMnfPresSel_C = 1;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bInhTrbActCtlIni_C = 1;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bInhTrbActCtl_B = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bOpRCOAdpSel_C = 1;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bPresDifSel_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bRCOAdpSel_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bRCOReqSel_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bSelRCOCorReq_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bSelRatOpTrbAct_C = 0;
CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bUpPresAdpSel_C = 0;

#define TrbActGsl_STOP_SEC_CALIB_BOOLEAN
#include "TrbActGsl_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define TrbActGsl_START_SEC_INTERNAL_VAR_32BIT
#include "TrbActGsl_MemMap.h"

VAR(Float32, TRBACTGSL_INTERNAL_VAR) TrbAct_rOpTrbActEstimPrev = 0.0F;
VAR(SInt32, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAdpOfsErr_MP = 0;
VAR(SInt32, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAdpRateErr_MP = 0;

#define TrbActGsl_STOP_SEC_INTERNAL_VAR_32BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define TrbActGsl_START_SEC_INTERNAL_VAR_16BIT
#include "TrbActGsl_MemMap.h"

VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_facFltRCOReq_MP = 0U;
VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_facFltUsPresCorErr_MP = 0U;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifPnmActReq = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbActEstim_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbActReqAdd_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbActReqBas_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbEstim_IRV_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pUsThrCorErr_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rCtlIntErr_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOFastAddCor_MP = 0;
VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAddCor_MP = 32768U;
VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAdd_MP = 32768U;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqFastAdpOfs_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqWoutAdpBas_MP = 0;
VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqWoutAdpFlt_MP = 0;
VAR(UInt16, TRBACTGSL_INTERNAL_VAR) UsThrM_pDsCmprFlt_MP = 0U;

#define TrbActGsl_STOP_SEC_INTERNAL_VAR_16BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define TrbActGsl_START_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActGsl_MemMap.h"

VAR(Boolean, TRBACTGSL_INTERNAL_VAR) TrbAct_bAcvOfsRCOAdp_MP = FALSE;
VAR(Boolean, TRBACTGSL_INTERNAL_VAR) TrbAct_bAcvRateRCOAdp_MP = FALSE;

#define TrbActGsl_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActGsl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
