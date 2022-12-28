/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslT                                                */
/* !Description     : EngMGslT Software Component                             */
/*                                                                            */
/* !Module          : EngMGslT                                                */
/*                                                                            */
/* !File            : EngMGslT_Def.c                                          */
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
/*   Model name       : EngMGslT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /EngMGslT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M05-EngMGslT/5-S$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   31 May 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngMGslT.h"
#include "EngMGslT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CALIB_32BIT" */
#define EngMGslT_START_SEC_CALIB_32BIT
#include "EngMGslT_MemMap.h"

CONST(UInt32, ENGMGSLT_CALIB) EngM_facMassAirScvCor_B = 0U;
CONST(UInt32, ENGMGSLT_CALIB) EngM_facMassAirScvReq_B = 0U;
CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirEngCylMax_B = 0U;
CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirEngCylMin_B = 0U;
CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirEngCylTrbMax_B = 0U;
CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirPresUsThr_B = 0U;
CONST(UInt32, ENGMGSLT_CALIB) EngM_tiInjMin_C = 229U;

#define EngMGslT_STOP_SEC_CALIB_32BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "CARTO_32BIT" */
#define EngMGslT_START_SEC_CARTO_32BIT
#include "EngMGslT_MemMap.h"

CONST(UInt32, ENGMGSLT_CARTO) EngM_rPresX_A[11] = { 0U, 6554U, 13107U, 19661U,
  26214U, 32768U, 39322U, 45875U, 52429U, 58982U, 65536U } ;

#define EngMGslT_STOP_SEC_CARTO_32BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define EngMGslT_START_SEC_CARTO_16BIT
#include "EngMGslT_MemMap.h"

CONST(UInt16, ENGMGSLT_CARTO) Air_rAirPresRef2_A[22] = { 0U, 655U, 1311U,
  3631U, 7563U, 10715U, 13867U, 17020U, 19772U, 22138U, 24104U, 26077U, 27846U,
  29223U, 30304U, 30999U, 31628U, 31850U, 32185U, 32375U, 32571U, 32768U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_facChgCorSlopEfc_T[11] = { 0U, 6554U,
  13107U, 19661U, 26214U, 32768U, 39322U, 45875U, 52429U, 58982U, 65535U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_facCorRatPresExt_T[22] = { 0U, 655U, 1966U,
  3631U, 7563U, 10715U, 13867U, 17020U, 19772U, 22138U, 24104U, 26077U, 27846U,
  29223U, 30304U, 30999U, 31628U, 31850U, 32185U, 32375U, 32571U, 32768U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_facCorT_T[8] = { 34816U, 33935U, 32768U,
  31487U, 31231U, 30720U, 29825U, 28928U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_mfFuInjMin_T[6] = { 197U, 642U, 779U, 1135U,
  1376U, 1442U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_nEng_LfpPresAtmY_A[8] = { 700U, 1000U,
  1500U, 2000U, 3000U, 4000U, 5000U, 6500U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_pFuLdMin_A[6] = { 6400U, 12800U, 15360U,
  19200U, 25600U, 38400U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_pInMnfMinReq_T[9] = { 2750U, 2750U, 2750U,
  2750U, 2750U, 2750U, 2750U, 2750U, 2750U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mAirPredInCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mAirScvCorCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfAirCorCyl_B[6] = { 0U, 0U, 0U, 0U, 0U,
  0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfAirPredInCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfAirScvCorCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfTotExCorCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_rAirLdPredInCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_rTotLdExCorCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_rLdMinProt_M[16][17] = { {3318U, 3318U, 3318U,
  3318U, 3318U, 3318U, 3318U, 3318U, 3318U, 2458U, 2458U, 2458U, 2458U, 2458U,
  2458U, 2335U, 3318U}, {3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U,
  2458U, 2458U, 2458U, 2458U, 2458U, 2458U, 2089U, 3318U, 3318U}, {3318U, 3195U,
  3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2458U, 2458U, 2458U,
  2212U, 3318U, 3318U, 3318U}, {3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U,
  2458U, 2458U, 2335U, 2335U, 2335U, 2212U, 3318U, 3318U, 3318U, 3195U}, {3195U,
  3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2089U, 2089U, 2089U, 2089U,
  3318U, 3318U, 3318U, 3195U, 3195U}, {3195U, 2703U, 2703U, 2703U, 2458U, 2458U,
  2458U, 2089U, 2089U, 2089U, 2089U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U},
  {2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2089U, 2089U, 2089U, 2089U, 3318U,
  3318U, 3318U, 3195U, 3195U, 3195U, 2703U}, {2703U, 2703U, 2458U, 2458U, 2458U,
  2089U, 2089U, 2089U, 2089U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U,
  2703U}, {2703U, 2458U, 2458U, 2458U, 2089U, 2089U, 2089U, 2089U, 3318U, 3318U,
  3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U}, {2458U, 2458U, 2458U, 2335U,
  2335U, 2335U, 2335U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U,
  2703U, 2458U}, {2458U, 2458U, 2458U, 2458U, 2458U, 2458U, 3318U, 3318U, 3318U,
  3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U}, {2458U, 2458U, 2458U,
  2458U, 2458U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U,
  2458U, 2458U, 2458U}, {2089U, 2089U, 2089U, 2089U, 3318U, 3318U, 3318U, 3195U,
  3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2335U}, {2335U, 2335U,
  2335U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U,
  2458U, 2458U, 2458U, 2458U}, {2458U, 2458U, 3318U, 3318U, 3318U, 3195U, 3195U,
  3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2458U, 2458U, 2458U}, {2458U,
  3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U,
  2458U, 2458U, 2458U, 2458U, 2458U} } ;

CONST(UInt16, ENGMGSLT_CARTO) EngM_rLdMinRef_M[16][17] = { {3318U, 3318U, 3318U,
  3318U, 3318U, 3318U, 3318U, 3318U, 3318U, 2458U, 2458U, 2458U, 2458U, 2458U,
  2458U, 2335U, 3318U}, {3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U,
  2458U, 2458U, 2458U, 2458U, 2458U, 2458U, 2089U, 3318U, 3318U}, {3318U, 3195U,
  3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2458U, 2458U, 2458U,
  2212U, 3318U, 3318U, 3318U}, {3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U,
  2458U, 2458U, 2335U, 2335U, 2335U, 2212U, 3318U, 3318U, 3318U, 3195U}, {3195U,
  3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2089U, 2089U, 2089U, 2089U,
  3318U, 3318U, 3318U, 3195U, 3195U}, {3195U, 2703U, 2703U, 2703U, 2458U, 2458U,
  2458U, 2089U, 2089U, 2089U, 2089U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U},
  {2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2089U, 2089U, 2089U, 2089U, 3318U,
  3318U, 3318U, 3195U, 3195U, 3195U, 2703U}, {2703U, 2703U, 2458U, 2458U, 2458U,
  2089U, 2089U, 2089U, 2089U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U,
  2703U}, {2703U, 2458U, 2458U, 2458U, 2089U, 2089U, 2089U, 2089U, 3318U, 3318U,
  3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U}, {2458U, 2458U, 2458U, 2335U,
  2335U, 2335U, 2335U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U,
  2703U, 2458U}, {2458U, 2458U, 2458U, 2458U, 2458U, 2458U, 3318U, 3318U, 3318U,
  3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U}, {2458U, 2458U, 2458U,
  2458U, 2458U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U,
  2458U, 2458U, 2458U}, {2089U, 2089U, 2089U, 2089U, 3318U, 3318U, 3318U, 3195U,
  3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2335U}, {2335U, 2335U,
  2335U, 3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U,
  2458U, 2458U, 2458U, 2458U}, {2458U, 2458U, 3318U, 3318U, 3318U, 3195U, 3195U,
  3195U, 2703U, 2703U, 2703U, 2458U, 2458U, 2458U, 2458U, 2458U, 2458U}, {2458U,
  3318U, 3318U, 3318U, 3195U, 3195U, 3195U, 2703U, 2703U, 2703U, 2458U, 2458U,
  2458U, 2458U, 2458U, 2458U, 2458U} } ;

CONST(UInt16, ENGMGSLT_CARTO) Ext_tAirRef1_A[8] = { 2579U, 3859U, 6419U, 8979U,
  10259U, 11539U, 14099U, 16659U } ;

CONST(SInt16, ENGMGSLT_CARTO) Ext_tCoRef1_A[17] = { -30, -20, -15, -9, -5, 0,
  10, 18, 23, 30, 40, 50, 65, 80, 90, 100, 110 } ;

#define EngMGslT_STOP_SEC_CARTO_16BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define EngMGslT_START_SEC_CALIB_16BIT
#include "EngMGslT_MemMap.h"

CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkClsExVlvEstimRef1_B = -1024;
CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkClsExVlvReqRef1_B = -1024;
CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkClsInVlvEstimRef0_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkClsInVlvEstimRef1_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkOpExVlvEstimRef0_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkOpExVlvEstimRef1_B = 0U;
CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkOpInVlvEstimRef1_B = -1024;
CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkOpInVlvReqRef1_B = -1024;
CONST(UInt16, ENGMGSLT_CALIB) EngM_facChgCorSlopEfc_A[11] = { 0U, 3277U, 6554U,
  13107U, 19661U, 29491U, 36045U, 42598U, 55706U, 62259U, 65535U } ;

CONST(UInt16, ENGMGSLT_CALIB) EngM_facMassFlowLdCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_facOfsEfcCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_facOfsEfcPred_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_facOfsEfcReq_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_facSlopEfcCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_facSlopEfcPred_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_facSlopEfcReq_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirPredIn_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirPred_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirScvCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mBurnCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mTotExPredIn_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mTotExPred_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirPredIn_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirPred_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirScvCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mfTotExCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mfTotExPredIn_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_mfTotExPred_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_pInMnfMinReq_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rAirLdCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rAirLdPredIn_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rAirLdPred_B = 0U;
CONST(SInt16, ENGMGSLT_CALIB) EngM_rDeltaLdInjPha_B = -32768;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rItBurnRateCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rMassAirResiCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rMassAirScvCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rMaxTotLd_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rPresLostThrPosnInfo_C = 243U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rTotLdExCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rTotLdExPred_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_rltMassAirScvCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_tBurnCylCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_tMixtCylCor_B = 0U;
CONST(UInt16, ENGMGSLT_CALIB) EngM_tMixtCylGDICor_B = 0U;

#define EngMGslT_STOP_SEC_CALIB_16BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define EngMGslT_START_SEC_CALIB_BOOLEAN
#include "EngMGslT_MemMap.h"

CONST(Boolean, ENGMGSLT_CALIB) ENGMGSLT_ACTIVE_BYP_C = 0;
CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvMPMMod_C = 1;
CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvReqPres_C = 1;
CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvStraLdMin_C = 1;
CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvTPMMod_C = 1;
CONST(Boolean, ENGMGSLT_CALIB) EngM_bSelMaxLdClcMod_C = 0;
CONST(Boolean, ENGMGSLT_CALIB) Ext_bAcvTrbMod_C = 1;

#define EngMGslT_STOP_SEC_CALIB_BOOLEAN
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define EngMGslT_START_SEC_CALIB_8BIT
#include "EngMGslT_MemMap.h"

CONST(UInt8, ENGMGSLT_CALIB) EngM_agCkClsInVlvReqRef0_B = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_agCkOpExVlvReqRef0_B = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_agCkOpExVlvReqRef1_B = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_facACor_B = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_facAPred_B = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_facDCor_B = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_noPhaInjLoaEstimn_C = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_noPhaInjLoaReq_C = 0U;
CONST(UInt8, ENGMGSLT_CALIB) EngM_noPhaInjPredLoaEstimn_C = 3U;

#define EngMGslT_STOP_SEC_CALIB_8BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define EngMGslT_START_SEC_CARTO_8BIT
#include "EngMGslT_MemMap.h"

CONST(UInt8, ENGMGSLT_CARTO) EngM_facLfpPresAtmBoost_M[11][8] = { {100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U}, {100U, 100U, 100U, 100U, 100U, 100U, 100U,
  100U}, {100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U}, {100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U}, {100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U}, {100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U}, {100U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U}, {100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U}, {100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U}, {100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U},
  {100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U} } ;

#define EngMGslT_STOP_SEC_CARTO_8BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define EngMGslT_START_SEC_INTERNAL_VAR_32BIT
#include "EngMGslT_MemMap.h"

VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_facAtmSlop_MP = 0.0F;
VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_facBoostSlop_MP = 0.0F;
VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_mFuStmEstim = 0.0F;
VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_rLdMinCord = 0.0F;
VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_rMinLd = 0.0F;
VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_rTotLdExPredIn = 0.0F;

#define EngMGslT_STOP_SEC_INTERNAL_VAR_32BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define EngMGslT_START_SEC_INTERNAL_VAR_16BIT
#include "EngMGslT_MemMap.h"

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpFilCor_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpFilPred_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpFilReq_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpScvFilCor_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpScvFilPred = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpScvFilReq_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facCorAtmSlopEfcPrev_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facCorBoostSlopEfcPrev_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facECor_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facRLdMax_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facTAirUsInVlvPrev_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facUsThr_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_mAirMin_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_pBegCorBoostSlopEfcPrev_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_pDeltaCorSlopEfcPrev_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_001_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_002_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_003_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_004_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_005_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_006_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_MP[6] = { 0U, 0U, 0U,
  0U, 0U, 0U };

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirScvCorCyl_MP[6] = { 0U, 0U, 0U,
  0U, 0U, 0U };

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirCorCyl_MP[6] = { 0U, 0U, 0U,
  0U, 0U, 0U };

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_001_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_002_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_003_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_004_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_005_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_006_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_MP[6] = { 0U, 0U, 0U,
  0U, 0U, 0U };

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirScvCorCyl_MP[6] = { 0U, 0U,
  0U, 0U, 0U, 0U };

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_001 = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_002 = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_003 = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_004 = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_005 = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_006 = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_MP[6] = { 0U, 0U, 0U,
  0U, 0U, 0U };

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rTotLdExCorCyl_MP[6] = { 0U, 0U,
  0U, 0U, 0U, 0U };

VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdBas_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdMaxBas_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdMinBas_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdMinCor_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLd_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMaxAvlLd_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMaxLimLd = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMinCord_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMinLd_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMinTotLd_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rTotLdEx_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rVolCylClsInVlvPrev_IRV_MP = 0U;
VAR(UInt16, ENGMGSLT_INTERNAL_VAR) InM_pDsThrPrev_IRV_MP = 0U;

#define EngMGslT_STOP_SEC_INTERNAL_VAR_16BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define EngMGslT_START_SEC_INTERNAL_VAR_8BIT
#include "EngMGslT_MemMap.h"

VAR(UInt8, ENGMGSLT_INTERNAL_VAR) EngM_agCkClsInVlvReqRef1_IRV_MP = 0U;
VAR(SInt8, ENGMGSLT_INTERNAL_VAR) EngM_facD_MP = 0;
VAR(UInt8, ENGMGSLT_INTERNAL_VAR) EngM_facLfpPresAtmBoost_MP = 0U;
VAR(UInt8, ENGMGSLT_INTERNAL_VAR) EngM_facTCoPrev_IRV_MP = 0U;

#define EngMGslT_STOP_SEC_INTERNAL_VAR_8BIT
#include "EngMGslT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
