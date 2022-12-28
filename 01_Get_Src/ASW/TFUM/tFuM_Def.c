/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tFuM                                                    */
/* !Description     : tFuM – Fuel temperature estimation                      */
/*                                                                            */
/* !Module          : tFuM                                                    */
/*                                                                            */
/* !File            : tFuM_Def.c                                              */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Jul 12 15:18:26 2012                              */
/*   Model name       : tFuM_AUTOCODE.mdl                                     */
/*   Model version    : 1.500                                                 */
/*   Root subsystem   : /tFuM                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/tFuM/5-SOFT-LIV/tFuM_Def.c_v$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "tFuM.h"
#include "tFuM_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "SEC_CALIB_32BIT" */
#define TFUM_START_SEC_CALIB_32BIT
#include "tFuM_MemMap.h"

CONST(UInt32, TFUM_CALIB) FuSysM_tiEngStop_A[9] = { 0U, 50U, 150U, 300U, 500U,
  1000U, 1800U, 3600U, 36000U } ;

#define TFUM_STOP_SEC_CALIB_32BIT
#include "tFuM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define TFUM_START_SEC_CALIB_16BIT
#include "tFuM_MemMap.h"

CONST(UInt16, TFUM_CALIB) FuSysM_facExgAirStalltFuUsPmp_T[9] = { 26U, 26U, 26U,
  26U, 26U, 26U, 26U, 26U, 26U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_facExgAirStalltFu_T[9] = { 16U, 16U, 16U, 16U,
  16U, 16U, 16U, 16U, 16U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_facExgUndHo_M[81] = { 33882U, 27931U, 12229U,
  11888U, 11620U, 12707U, 10027U, 10027U, 10027U, 33882U, 27931U, 12229U, 11888U,
  11620U, 12707U, 10027U, 10027U, 10027U, 33882U, 27931U, 12229U, 11888U, 11620U,
  12707U, 10027U, 10027U, 10027U, 33882U, 27931U, 12229U, 11888U, 11620U, 12707U,
  10027U, 10027U, 10027U, 33882U, 27931U, 12229U, 11888U, 11620U, 12707U, 10027U,
  10027U, 10027U, 33882U, 27931U, 12229U, 11888U, 11620U, 12707U, 10027U, 10027U,
  10027U, 33882U, 27931U, 12229U, 11888U, 11620U, 12707U, 10027U, 10027U, 10027U,
  33882U, 27931U, 12229U, 11888U, 11620U, 12707U, 10027U, 10027U, 10027U, 33882U,
  27931U, 12229U, 11888U, 11620U, 12707U, 10027U, 10027U, 10027U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_facExgWatFuUsPmp_C = 37U;
CONST(UInt16, TFUM_CALIB) FuSysM_facExgWatFu_C = 56U;
CONST(UInt16, TFUM_CALIB) FuSysM_facExgmfFu_M[81] = { 0U, 249U, 498U, 747U,
  996U, 1245U, 1501U, 1750U, 2248U, 0U, 249U, 498U, 747U, 996U, 1245U, 1501U,
  1750U, 2248U, 0U, 249U, 498U, 747U, 996U, 1245U, 1501U, 1750U, 2248U, 0U, 249U,
  498U, 747U, 996U, 1245U, 1501U, 1750U, 2248U, 0U, 249U, 498U, 747U, 996U,
  1245U, 1501U, 1750U, 2248U, 0U, 249U, 498U, 747U, 996U, 1245U, 1501U, 1750U,
  2248U, 0U, 249U, 498U, 747U, 996U, 1245U, 1501U, 1750U, 2248U, 0U, 249U, 498U,
  747U, 996U, 1245U, 1501U, 1750U, 2248U, 0U, 249U, 498U, 747U, 996U, 1245U,
  1501U, 1750U, 2248U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_facExgtEngtFuUsPmp_M[81] = { 3303U, 2936U,
  2202U, 2386U, 2800U, 3447U, 5321U, 7596U, 8265U, 3303U, 2936U, 2202U, 2386U,
  2800U, 3447U, 5321U, 7596U, 8265U, 3303U, 2936U, 2202U, 2386U, 2800U, 3447U,
  5321U, 7596U, 8265U, 3303U, 2936U, 2202U, 2386U, 2800U, 3447U, 5321U, 7596U,
  8265U, 3303U, 2936U, 2202U, 2386U, 2800U, 3447U, 5321U, 7596U, 8265U, 3303U,
  2936U, 2202U, 2386U, 2800U, 3447U, 5321U, 7596U, 8265U, 3303U, 2936U, 2202U,
  2386U, 2800U, 3447U, 5321U, 7596U, 8265U, 3303U, 2936U, 2202U, 2386U, 2800U,
  3447U, 5321U, 7596U, 8265U, 3303U, 2936U, 2202U, 2386U, 2800U, 3447U, 5321U,
  7596U, 8265U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_facExgtEngtFu_M[81] = { 26U, 22U, 13U, 11U,
  10U, 10U, 10U, 10U, 10U, 26U, 22U, 13U, 11U, 10U, 10U, 10U, 10U, 10U, 26U, 22U,
  13U, 11U, 10U, 10U, 10U, 10U, 10U, 26U, 22U, 13U, 11U, 10U, 10U, 10U, 10U, 10U,
  26U, 22U, 13U, 11U, 10U, 10U, 10U, 10U, 10U, 26U, 22U, 13U, 11U, 10U, 10U, 10U,
  10U, 10U, 26U, 22U, 13U, 11U, 10U, 10U, 10U, 10U, 10U, 26U, 22U, 13U, 11U, 10U,
  10U, 10U, 10U, 10U, 26U, 22U, 13U, 11U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_facExgtExttFuUsPmp_M[81] = { 2552U, 4831U,
  5455U, 5897U, 6637U, 7677U, 8518U, 10851U, 11807U, 4518U, 4831U, 5455U, 5897U,
  6637U, 7677U, 8518U, 10851U, 11807U, 4518U, 4831U, 5455U, 5897U, 6637U, 7677U,
  8518U, 10851U, 11807U, 4518U, 4831U, 5455U, 5897U, 6637U, 7677U, 8518U, 10851U,
  11807U, 4518U, 4831U, 5455U, 5897U, 6637U, 7677U, 8518U, 10851U, 11807U, 4518U,
  4831U, 5455U, 5897U, 6637U, 7677U, 8518U, 10851U, 11807U, 4518U, 4831U, 5455U,
  5897U, 6637U, 7677U, 8518U, 10851U, 11807U, 4518U, 4831U, 5455U, 5897U, 6637U,
  7677U, 8518U, 10851U, 11807U, 4518U, 4831U, 5455U, 5897U, 6637U, 7677U, 8518U,
  10851U, 11807U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_mfFuEstim_A[9] = { 0U, 7680U, 15360U, 23040U,
  30720U, 38400U, 46080U, 53760U, 64000U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_pFuRail_A[9] = { 128U, 3840U, 7680U, 11520U,
  15360U, 19200U, 23040U, 26880U, 28160U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_rGainFilUndHo_M[81] = { 1347U, 1347U, 1347U,
  1737U, 32768U, 32768U, 32768U, 32768U, 32768U, 1347U, 1347U, 1347U, 1737U,
  32768U, 32768U, 32768U, 32768U, 32768U, 1347U, 1347U, 1347U, 1737U, 32768U,
  32768U, 32768U, 32768U, 32768U, 1347U, 1347U, 1347U, 1737U, 32768U, 32768U,
  32768U, 32768U, 32768U, 1347U, 1347U, 1347U, 1737U, 32768U, 32768U, 32768U,
  32768U, 32768U, 1347U, 1347U, 1347U, 1737U, 32768U, 32768U, 32768U, 32768U,
  32768U, 1347U, 1347U, 1347U, 1737U, 32768U, 32768U, 32768U, 32768U, 32768U,
  1347U, 1347U, 1347U, 1737U, 32768U, 32768U, 32768U, 32768U, 32768U, 1347U,
  1347U, 1347U, 1737U, 32768U, 32768U, 32768U, 32768U, 32768U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_tiFilBastFuUsPmp_M[81] = { 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1600U, 1600U, 1600U, 1600U, 1600U,
  1600U, 1600U, 1600U, 1600U, 1600U, 1600U, 1600U, 1600U, 1600U, 1600U, 1600U,
  1600U, 1600U } ;

CONST(UInt16, TFUM_CALIB) FuSysM_tiFilExgtFuUsPmp_M[81] = { 5760U, 5547U,
  5120U, 3413U, 2560U, 2560U, 2560U, 2560U, 2560U, 5760U, 5547U, 5120U, 3413U,
  2560U, 2560U, 2560U, 2560U, 2560U, 5760U, 5547U, 5120U, 3413U, 2560U, 2560U,
  2560U, 2560U, 2560U, 5760U, 5547U, 5120U, 3413U, 2560U, 2560U, 2560U, 2560U,
  2560U, 5760U, 5547U, 5120U, 3413U, 2560U, 2560U, 2560U, 2560U, 2560U, 5760U,
  5547U, 5120U, 3413U, 2560U, 2560U, 2560U, 2560U, 2560U, 5760U, 5547U, 5120U,
  3413U, 2560U, 2560U, 2560U, 2560U, 2560U, 5760U, 5547U, 5120U, 3413U, 2560U,
  2560U, 2560U, 2560U, 2560U, 5760U, 5547U, 5120U, 3413U, 2560U, 2560U, 2560U,
  2560U, 2560U } ;

#define TFUM_STOP_SEC_CALIB_16BIT
#include "tFuM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define TFUM_START_SEC_CALIB_8BIT
#include "tFuM_MemMap.h"

CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuExgWa_T[9] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuUsPmpEng_T[9] = { 128U, 96U, 79U,
  64U, 51U, 40U, 29U, 19U, 13U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuUsPmpExt_T[9] = { 128U, 96U, 79U,
  64U, 51U, 40U, 29U, 19U, 13U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuUsPmp_T[9] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFu_T[9] = { 128U, 96U, 79U, 64U,
  51U, 40U, 29U, 19U, 13U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_rCorTFuIni_M[81] = { 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 248U, 248U, 248U, 248U, 248U, 248U, 248U, 248U,
  248U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 244U, 244U, 244U,
  244U, 244U, 244U, 244U, 244U, 244U, 227U, 227U, 227U, 227U, 227U, 227U, 227U,
  227U, 227U, 198U, 198U, 198U, 198U, 198U, 198U, 198U, 198U, 198U, 165U, 165U,
  165U, 165U, 165U, 165U, 165U, 165U, 165U, 140U, 140U, 140U, 140U, 140U, 140U,
  140U, 140U, 140U, 127U, 127U, 127U, 127U, 127U, 127U, 127U, 127U, 127U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_rCorTFuUsPmpIni_M[81] = { 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 251U, 251U,
  251U, 251U, 251U, 251U, 251U, 251U, 251U, 239U, 239U, 239U, 239U, 239U, 239U,
  239U, 239U, 239U, 215U, 215U, 215U, 215U, 215U, 215U, 215U, 215U, 215U, 196U,
  196U, 196U, 196U, 196U, 196U, 196U, 196U, 196U, 140U, 140U, 140U, 140U, 140U,
  140U, 140U, 140U, 140U, 127U, 127U, 127U, 127U, 127U, 127U, 127U, 127U, 127U }
;

CONST(UInt8, TFUM_CALIB) FuSysM_rSpdFanReq_A[9] = { 0U, 5U, 10U, 15U, 20U, 25U,
  35U, 40U, 50U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_spdVeh_A[9] = { 0U, 10U, 30U, 50U, 70U, 90U,
  110U, 140U, 180U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_tAirExtMes_A[9] = { 10U, 20U, 30U, 40U, 50U,
  60U, 70U, 80U, 90U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_tCoMes_A[9] = { 10U, 28U, 45U, 63U, 80U, 98U,
  115U, 133U, 150U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_tFuETB_C = 70U;
CONST(UInt8, TFUM_CALIB) FuSysM_tFuUsPmpETB_C = 70U;
CONST(UInt8, TFUM_CALIB) FuSysM_tFuUsPmpWaPmpOff_M[81] = { 1U, 2U, 4U, 6U, 8U,
  10U, 12U, 15U, 17U, 10U, 11U, 13U, 15U, 17U, 20U, 22U, 24U, 26U, 19U, 21U, 22U,
  24U, 27U, 29U, 31U, 33U, 35U, 29U, 30U, 32U, 34U, 36U, 38U, 40U, 42U, 45U, 38U,
  39U, 41U, 43U, 45U, 47U, 49U, 52U, 54U, 47U, 48U, 50U, 52U, 54U, 57U, 59U, 61U,
  63U, 56U, 58U, 59U, 61U, 64U, 66U, 68U, 70U, 72U, 66U, 67U, 69U, 71U, 73U, 75U,
  77U, 79U, 82U, 75U, 76U, 78U, 80U, 82U, 84U, 86U, 89U, 91U } ;

CONST(UInt8, TFUM_CALIB) FuSysM_tFuUsPmpWaPmpOn_M[81] = { 1U, 2U, 4U, 6U, 8U,
  10U, 12U, 15U, 17U, 10U, 11U, 13U, 15U, 17U, 20U, 22U, 24U, 26U, 19U, 21U, 22U,
  24U, 27U, 29U, 31U, 33U, 35U, 29U, 30U, 32U, 34U, 36U, 38U, 40U, 42U, 45U, 38U,
  39U, 41U, 43U, 45U, 47U, 49U, 52U, 54U, 47U, 48U, 50U, 52U, 54U, 57U, 59U, 61U,
  63U, 56U, 58U, 59U, 61U, 64U, 66U, 68U, 70U, 72U, 66U, 67U, 69U, 71U, 73U, 75U,
  77U, 79U, 82U, 75U, 76U, 78U, 80U, 82U, 84U, 86U, 89U, 91U } ;

CONST(UInt8, TFUM_CALIB) TFUM_u8Inhib = 0U;

#define TFUM_STOP_SEC_CALIB_8BIT
#include "tFuM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define TFUM_START_SEC_CALIB_BOOLEAN
#include "tFuM_MemMap.h"

CONST(Boolean, TFUM_CALIB) FuSysM_bAcvTFuETB_C = 0;

#define TFUM_STOP_SEC_CALIB_BOOLEAN
#include "tFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define TFUM_START_SEC_VAR_32BIT
#include "tFuM_MemMap.h"

VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFu;
VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuExgWa;
VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuUsPmp;
VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuUsPmpEng;
VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuUsPmpExt;
VAR(Float32, TFUM_VAR) FuSysM_facExgAirtFuUsPmp;
VAR(Float32, TFUM_VAR) FuSysM_facExgUndHo;
VAR(Float32, TFUM_VAR) FuSysM_facExgmfFu;
VAR(Float32, TFUM_VAR) FuSysM_facExgtEngtFu;
VAR(Float32, TFUM_VAR) FuSysM_facExgtEngtFuUsPmp;
VAR(Float32, TFUM_VAR) FuSysM_facExgtExttFuUsPmp;
VAR(Float32, TFUM_VAR) FuSysM_factFuExgAirStall;
VAR(Float32, TFUM_VAR) FuSysM_rCorTFuIni;
VAR(Float32, TFUM_VAR) FuSysM_rCorTFuUsPmpIni;
VAR(Float32, TFUM_VAR) FuSysM_rGainFilUndHo;
VAR(Float32, TFUM_VAR) FuSysM_tEng;
VAR(Float32, TFUM_VAR) FuSysM_tEngPrev;
VAR(Float32, TFUM_VAR) FuSysM_tEngRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuExgAirStallCor;
VAR(Float32, TFUM_VAR) FuSysM_tFuExgWaCor;
VAR(Float32, TFUM_VAR) FuSysM_tFuExgWaStallCor;
VAR(Float32, TFUM_VAR) FuSysM_tFuExgmfFuCor;
VAR(Float32, TFUM_VAR) FuSysM_tFuExgtEngCor;
VAR(Float32, TFUM_VAR) FuSysM_tFuExgtEngRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuFineRsl;
VAR(Float32, TFUM_VAR) FuSysM_tFuPrev;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpAirDif;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpAirDifStall;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpBasCorRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpBasFil;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpBasRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpEngCorFil;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpEngCorRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpEngRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExgAirCor;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExgWaCor;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExtCorFil;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExtCorRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExtRaw;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpFineRsl;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpPrev;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpWaDifStall;
VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmptEngDif;
VAR(Float32, TFUM_VAR) FuSysM_tFutAirDifStall;
VAR(Float32, TFUM_VAR) FuSysM_tFutEngDif;
VAR(Float32, TFUM_VAR) FuSysM_tFutFuUsPmpDif;
VAR(Float32, TFUM_VAR) FuSysM_tFutWaDif;
VAR(Float32, TFUM_VAR) FuSysM_tFutWaDifStall;
VAR(Float32, TFUM_VAR) FuSysM_tOiltAirDif;
VAR(UInt32, TFUM_VAR) FuSysM_tiEcuStop;
VAR(Float32, TFUM_VAR) FuSysM_tiFilBastFuUsPmp;
VAR(Float32, TFUM_VAR) FuSysM_tiFilExgtFuUsPmp;

#define TFUM_STOP_SEC_VAR_32BIT
#include "tFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define TFUM_START_SEC_VAR_16BIT
#include "tFuM_MemMap.h"

VAR(UInt16, TFUM_VAR) FuSysM_mfFuEstim;
VAR(UInt16, TFUM_VAR) FuSysM_tFu;

#define TFUM_STOP_SEC_VAR_16BIT
#include "tFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define TFUM_START_SEC_VAR_BOOLEAN
#include "tFuM_MemMap.h"

VAR(Boolean, TFUM_VAR) FuSysM_bAcvTFuInit;
VAR(Boolean, TFUM_VAR) FuSysM_bRstFil;

#define TFUM_STOP_SEC_VAR_BOOLEAN
#include "tFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define TFUM_START_SEC_VAR_8BIT
#include "tFuM_MemMap.h"

VAR(UInt8, TFUM_VAR) FuSysM_tFuUsPmp;

#define TFUM_STOP_SEC_VAR_8BIT
#include "tFuM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
