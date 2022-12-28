/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : UsThrMT                                                 */
/* !Description     : UsThrMT Software Component                              */
/*                                                                            */
/* !Module          : UsThrMT                                                 */
/*                                                                            */
/* !File            : UsThrMT_Def.c                                           */
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
/*   Model name       : UsThrMT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /UsThrMT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M01-UsThrMT/5-SO$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   14 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "UsThrMT.h"
#include "UsThrMT_private.h"

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
#define UsThrMT_START_SEC_CARTO_16BIT
#include "UsThrMT_MemMap.h"

CONST(UInt16, USTHRMT_CARTO) UsThrM_mfAirThr_A[16] = { 544U, 727U, 911U, 1055U,
  1199U, 1363U, 1494U, 1638U, 1914U, 2182U, 2458U, 2733U, 3002U, 3277U, 3552U,
  3821U } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_nEng_A[9] = { 800U, 1000U, 1500U, 2000U,
  2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_pDifCACAirThr_T[16] = { 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(SInt16, USTHRMT_CARTO) UsThrM_pDifCmprAirThr_T[16] = { 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_pDsThrMesThdAfu_T[9] = { 12500U, 12500U,
  12500U, 12500U, 12500U, 12500U, 12500U, 12500U, 12500U } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_pDsThrMesThd_T[9] = { 12500U, 12500U,
  12500U, 12500U, 12500U, 12500U, 12500U, 12500U, 12500U } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_pLossAirFil_T[16] = { 0U, 0U, 0U, 0U, 2U,
  24U, 48U, 82U, 109U, 150U, 168U, 178U, 188U, 203U, 226U, 246U } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_rFilTUndHo_M[9][3] = { { 1106U, 1106U, 1106U },
{ 1434U, 64881U, 64881U },{ 64881U, 64881U, 64881U },{ 1106U, 1106U, 1106U },{ 1434U,
  64881U, 64881U },{ 64881U, 64881U, 64881U },{ 1106U, 1106U, 1106U },{ 1434U, 64881U,
  64881U },{ 64881U, 64881U, 64881U } } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_rFilTUsCmpr_M[9][3] = { { 108U, 108U, 108U },
{ 108U, 108U, 108U },{ 108U, 108U, 108U },{ 108U, 108U, 108U },{ 108U, 108U, 108U },{ 108U,
  108U, 108U },{ 108U, 108U, 108U },{ 108U, 108U, 108U },{ 108U, 108U, 108U } } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_rMinThrUpdAirExtPres_T[16] = { 400U, 400U,
  400U, 460U, 564U, 616U, 652U, 680U, 688U, 696U, 708U, 712U, 716U, 716U, 716U,
  716U } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_rMinTrbThrUpdAirExtPres_T[16] = { 51U, 51U,
  51U, 51U, 51U, 51U, 51U, 51U, 51U, 51U, 51U, 51U, 51U, 51U, 51U, 51U } ;

CONST(UInt16, USTHRMT_CARTO) UsThrM_spdVeh_A[9] = { 0U, 1280U, 3840U, 6400U,
  8960U, 11520U, 14080U, 16640U, 19200U } ;

#define UsThrMT_STOP_SEC_CARTO_16BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define UsThrMT_START_SEC_CALIB_16BIT
#include "UsThrMT_MemMap.h"

CONST(UInt16, USTHRMT_CALIB) Air_pAirExtRef_C = 12666U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_facPresAltiCor_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_nCutThd_C = 6500U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_nIdlThd_C = 992U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_nUpdAirExtPresThd_C = 992U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pAirExtDft_C = 12500U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pAirExtMesCor_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pAirExt_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsCmpr_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsThrAcvAirExtCtlMod_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsThrMesCor_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsThrMesHys_C = 625U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pLossAirFil_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pLossCAC_B = 0U;
CONST(SInt16, USTHRMT_CALIB) UsThrM_pLossCmpr_B = 0;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pLossThd_C = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pOfsMaxAirExtPres_C = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pStallThd_C = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsCmpr_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsThrCor_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsThrMesCor_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsThrTrbCor_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_rFilMes_C = 5898U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_rFilPresAirExt_C = 65535U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_rMaxThrStabThd_C = 10U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tThrMes_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tUsCmpr_B = 0U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyThrStab_C = 200U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyUpdAirExtPresIdl_C = 9984U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyUpdAirExtPresStall_C = 5000U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyUpdAirExtPres_C = 5000U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tiTmrDifPres_C = 4000U;
CONST(UInt16, USTHRMT_CALIB) UsThrM_tiUpdAirExtPresInjCut_C = 9984U;

#define UsThrMT_STOP_SEC_CALIB_16BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define UsThrMT_START_SEC_CARTO_8BIT
#include "UsThrMT_MemMap.h"

CONST(UInt8, USTHRMT_CARTO) UsThrM_rEthWoutExctCor_T[8] = { 0U, 32U, 64U, 77U,
  90U, 102U, 115U, 128U } ;

CONST(UInt8, USTHRMT_CARTO) UsThrM_rEthWoutExct_A[8] = { 0U, 32U, 64U, 77U,
  90U, 102U, 115U, 128U } ;

CONST(UInt8, USTHRMT_CARTO) UsThrM_rFacTUndHo_M[9][3] = { { 132U, 109U, 48U },{ 46U,
  45U, 50U },{ 39U, 39U, 39U },{ 132U, 109U, 48U },{ 46U, 45U, 50U },{ 39U, 39U, 39U },{ 132U,
  109U, 48U },{ 46U, 45U, 50U },{ 39U, 39U, 39U } } ;

CONST(UInt8, USTHRMT_CARTO) UsThrM_rSpdFan_A[3] = { 0U, 50U, 100U } ;

#define UsThrMT_STOP_SEC_CARTO_8BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define UsThrMT_START_SEC_CALIB_BOOLEAN
#include "UsThrMT_MemMap.h"

CONST(Boolean, USTHRMT_CALIB) USTHRMT_ACTIVE_BYP_C = 0;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bAcvAirExtCtlMod_B = 0;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bAcvAltiCor_C = 1;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bAcvEth_C = 1;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bInhPresSenAdj_C = 0;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bInhTOil_C = 0;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bInhTUsCmprEstim_C = 0;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bPresDsThrSenRef_C = 1;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bPresUsThrSenRef_C = 1;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bSelTSen1_C = 0;
CONST(Boolean, USTHRMT_CALIB) UsThrM_bSelTSen2_C = 0;

#define UsThrMT_STOP_SEC_CALIB_BOOLEAN
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define UsThrMT_START_SEC_CALIB_8BIT
#include "UsThrMT_MemMap.h"

CONST(UInt8, USTHRMT_CALIB) UsThrM_pDeUsThr_C = 20U;
CONST(UInt8, USTHRMT_CALIB) UsThrM_tSqrtInAir_B = 120U;

#define UsThrMT_STOP_SEC_CALIB_8BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define UsThrMT_START_SEC_INTERNAL_VAR_32BIT
#include "UsThrMT_MemMap.h"

VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtMesSIFilPrev = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pAirExt_prev = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefAirExt = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefAirExtClc = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefDsThr = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefDsThrClc = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefUsThr = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefUsThrClc = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesSIFilPrev = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesThd = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesThdGsl = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pSenRef = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrMesSIFilPrev = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tAirExt = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tEng = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tUndHoPrev = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tUndHo_IRV_MP = 0.0F;
VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tUsCmprPrev = 0.0F;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_32BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define UsThrMT_START_SEC_INTERNAL_VAR_16BIT
#include "UsThrMT_MemMap.h"

VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresCut_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresCut_prev = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresIdl_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresIdl_prev = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresRun_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresRun_prev = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresStall = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresStall_prev = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtMesSIFil_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtRaw_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtRaw_prev = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesSIFil_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesThdAfu_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrAtmCor_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrCorPrev = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrMesSIFil_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tUndHoRaw_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tiTmrDifPresPrev = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tiTmrDifPres_IRV_MP = 0U;
VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tiTmrDifPres_SF = 0U;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_16BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define UsThrMT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "UsThrMT_MemMap.h"

VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvTrbUpdAirExtPres = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdAirExtPresCut = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdAirExtPresIdl = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdAirExtPresTrb = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdThrStab_MP = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresAvl = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresAvl_SF = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresClcEna = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresClcEna_SF = FALSE;
VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bUpdAirExtPresStall = FALSE;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "UsThrMT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define UsThrMT_START_SEC_INTERNAL_VAR_8BIT
#include "UsThrMT_MemMap.h"

VAR(UInt8, USTHRMT_INTERNAL_VAR) UsThrM_rEthWoutExctCor_MP = 0U;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_8BIT
#include "UsThrMT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
