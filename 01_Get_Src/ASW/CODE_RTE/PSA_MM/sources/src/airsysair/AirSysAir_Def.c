/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysAir                                               */
/* !Description     : AirSysAir Software Component                            */
/*                                                                            */
/* !Module          : AirSysAir                                               */
/*                                                                            */
/* !File            : AirSysAir_Def.c                                         */
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
/*   Model name       : AirSysAir_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysAir                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M17-AirSysAir/5-$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirSysAir.h"
#include "AirSysAir_private.h"

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
#define AirSysAir_START_SEC_CALIB_32BIT
#include "AirSysAir_MemMap.h"

CONST(UInt32, AIRSYSAIR_CALIB) AirSys_mAirEngIntCor_B = 2147456160U;
CONST(UInt32, AIRSYSAIR_CALIB) AirSys_tiAcvDlyDmp_C = 10486U;
CONST(UInt32, AIRSYSAIR_CALIB) AirSys_tiSampleFastThr_C = 655U;

#define AirSysAir_STOP_SEC_CALIB_32BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "CARTO_32BIT" */
#define AirSysAir_START_SEC_CARTO_32BIT
#include "AirSysAir_MemMap.h"

CONST(UInt32, AIRSYSAIR_CARTO) AirSys_facCfe_T[22] = { 42382U, 42382U, 42082U,
  41237U, 39851U, 38330U, 36412U, 34043U, 31538U, 28983U, 26501U, 23578U, 20439U,
  17486U, 14669U, 12478U, 10052U, 9031U, 8704U, 8363U, 8013U, 1174U } ;

CONST(UInt32, AIRSYSAIR_CARTO) AirSys_tiDmpDec_T[8] = { 3277U, 3277U, 3277U,
  3277U, 3277U, 3277U, 3277U, 3277U } ;

CONST(UInt32, AIRSYSAIR_CARTO) AirSys_tiTqDec_T[8] = { 3277U, 3277U, 3277U,
  3277U, 3277U, 3277U, 3277U, 3277U } ;

#define AirSysAir_STOP_SEC_CARTO_32BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define AirSysAir_START_SEC_CARTO_16BIT
#include "AirSysAir_MemMap.h"

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_arEfcThrReqTqY_A[6] = { 168U, 8389U,
  16777U, 33554U, 50332U, 65431U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_facArEfcThrFil_M[8][6] = { { 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },
{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },
{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U } } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_facFilGain_M[10][12] = { { 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },
{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 58981U, 65535U, 65535U, 65535U, 65535U },{ 65535U, 65535U,
  65535U, 65535U, 65535U, 52428U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U },
{ 65535U, 65535U, 65535U, 52428U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U },{ 65535U, 52428U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 58981U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 58981U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U } } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_faciMassIntCorRef1_T[9] = { 1311U, 655U,
  328U, 131U, 66U, 131U, 328U, 655U, 1311U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_facpMassIntCorRef1_M[10][9] = { { 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U },{ 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U },{ 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U },{ 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U },{ 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U },{ 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U },{ 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U },{ 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U },{ 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U },
{ 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U } } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_mEngAirErr_A[9] = { 31929U, 32349U,
  32684U, 32726U, 32768U, 32810U, 32852U, 33187U, 33607U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_mfAirThrReq_A[8] = { 0U, 6554U, 13107U,
  19661U, 26214U, 32768U, 39322U, 45875U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_mfFuStmMax_T[8] = { 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngArFilGainX_A[8] = { 800U, 1800U,
  2000U, 3000U, 4000U, 5000U, 6000U, 6500U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngDec_A[8] = { 800U, 1800U, 2000U,
  3000U, 4000U, 5000U, 6000U, 6500U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngFilGainX_A[10] = { 1000U, 1250U,
  1500U, 2000U, 2500U, 2750U, 3000U, 3500U, 4000U, 5000U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngTq_A[8] = { 800U, 1800U, 2000U,
  3000U, 4000U, 5000U, 6000U, 6500U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEng_A[10] = { 500U, 800U, 1000U, 1500U,
  2000U, 2500U, 3000U, 4000U, 5000U, 6500U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_prm_mfAirThrReq_B[2] = { 0U, 0U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_prm_pInMnfReq_B[2] = { 0U, 0U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresCorFilGainY_A[12] = { 13106U,
  55705U, 58326U, 58981U, 60292U, 62258U, 62586U, 62914U, 63569U, 64224U, 64880U,
  65535U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresFilGain_A[9] = { 0U, 39452U,
  45809U, 52493U, 55836U, 58850U, 62258U, 63503U, 65534U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresFilGain_M[10][12] = { { 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  52428U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  6553U, 26213U, 65535U, 65535U, 65535U },{ 65535U, 65535U, 65535U, 65535U, 65535U,
  45874U, 2620U, 26213U, 45874U, 52428U, 58981U, 65535U },{ 65535U, 65535U, 65535U,
  58981U, 19660U, 654U, 1310U, 6553U, 32767U, 6553U, 6553U, 65535U },{ 65535U,
  58981U, 52428U, 3276U, 130U, 1310U, 6553U, 1965U, 5242U, 65535U, 65535U,
  52428U },{ 39321U, 6553U, 1310U, 130U, 3931U, 2620U, 3931U, 65535U, 65535U,
  45874U, 32767U, 13106U },{ 5242U, 1310U, 130U, 1965U, 3276U, 65535U, 65535U,
  65535U, 45874U, 6553U, 5242U, 5897U },{ 1965U, 130U, 3931U, 19660U, 65535U,
  65535U, 58981U, 45874U, 32767U, 6553U, 5242U, 2620U },{ 130U, 6553U, 65535U,
  65535U, 58981U, 45874U, 39321U, 32767U, 19660U, 13106U, 3276U, 130U } } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresFilGain_T[9] = { 65534U, 65534U,
  65534U, 62914U, 58981U, 49151U, 26213U, 3931U, 654U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresRawFilGainX_A[10] = { 13106U,
  58981U, 60292U, 62258U, 62586U, 62914U, 63569U, 64224U, 64880U, 65535U } ;

CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rMaxThrPosn_T[10] = { 1014U, 1014U,
  1014U, 1014U, 1014U, 1014U, 1014U, 1014U, 1014U, 1014U } ;

CONST(SInt16, AIRSYSAIR_CARTO) AirSys_tqLoThd_T[8] = { 160, 160, 160, 160, 160,
  160, 160, 160 } ;

#define AirSysAir_STOP_SEC_CARTO_16BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define AirSysAir_START_SEC_CALIB_16BIT
#include "AirSysAir_MemMap.h"

CONST(UInt16, AIRSYSAIR_CALIB) AirSys_arEfcThrMax_C = 65431U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_arThrReq_B = 0U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_facFilArEfcThr_C = 15073U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylMaxReq_C = 2265U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylReq_tqEng_B = 0U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylThdReq_C = 4375U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylThd_C = 0U;
CONST(SInt16, AIRSYSAIR_CALIB) AirSys_mEngAirIntCorMin_C = 0;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mEngAirThd_C = 2125U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pCllThrHyst_C = 1875U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pCllThrThd_C = 4750U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pFilInhHiThd_C = 65510U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pFilInhLoThd_C = 0U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pNoiseNegThd_C = 2000U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pNoiseThd_C = 4000U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rAirLdReq_B = 0U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rFrzHiThd_C = 34734U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rFrzLoThd_C = 36045U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rMinThrPosn_C = 15U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rOpThrReqMaxOfs_C = 10U;
CONST(UInt16, AIRSYSAIR_CALIB) AirSys_tiDlyAftEgrFoul_C = 0U;
CONST(SInt16, AIRSYSAIR_CALIB) AirSys_tqOfsHiThd_C = 160;

#define AirSysAir_STOP_SEC_CALIB_16BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AirSysAir_START_SEC_CALIB_BOOLEAN
#include "AirSysAir_MemMap.h"

CONST(Boolean, AIRSYSAIR_CALIB) AIRSYSAIR_ACTIVE_BYP_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bActStraLimSurge_B = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvDeceThrCtl_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvDlyThr2_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvDlyThr_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvFilArEfcThr_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvFilAr_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvInhCfeFilDmp_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvInhCfeFilTq_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvStraTqReq_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvTqReqASR_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvTqReq_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bArMaxInh_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bFilGain_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhFilRat_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhFullLdCtl_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhPIIdl_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhPILimSurge_C = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhPiAirEngCor_B = 0;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bPresTrb_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bSelClcMod_pDsThrReq_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bSelMAirEngCylReq_C = 1;
CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bSelMaxThrPosn_C = 0;

#define AirSysAir_STOP_SEC_CALIB_BOOLEAN
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AirSysAir_START_SEC_CALIB_8BIT
#include "AirSysAir_MemMap.h"

CONST(UInt8, AIRSYSAIR_CALIB) AirSys_mEngAirIntCorMax_C = 0U;
CONST(UInt8, AIRSYSAIR_CALIB) AirSys_rAirPresMaxDif_C = 255U;
CONST(UInt8, AIRSYSAIR_CALIB) AirSys_rFrzPres_C = 255U;

#define AirSysAir_STOP_SEC_CALIB_8BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define AirSysAir_START_SEC_INTERNAL_VAR_32BIT
#include "AirSysAir_MemMap.h"

VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqDmpSysFil = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSysFil = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSysRaw = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_facAcvDmp = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_facAcvTq = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_facArEfcThrFilGain = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngIntCorPrev = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngPropCor = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngSelReq = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mEngAirCorOfs = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mEngAirErr = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mfAirThrReq_arThr = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_pInMnfOplReq = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_pInMnfReq = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_pInMnfReq_tqEng = 0.0F;
VAR(UInt32, AIRSYSAIR_INTERNAL_VAR) AirSys_prm_mAirEngReq_MP[2] = { 0U, 0U };

VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresFinal = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresRaw = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReqFil = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReqNoFil = 0.0F;
VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rFilGainPresRat = 0.0F;

#define AirSysAir_STOP_SEC_INTERNAL_VAR_32BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define AirSysAir_START_SEC_INTERNAL_VAR_16BIT
#include "AirSysAir_MemMap.h"

VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqDmpSys_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSysSat = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSys_IRV_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrTq_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_facArEfcThrFilGain_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_facCfe_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngCorReq_IRV_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngCylSurgeLimReq_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_prm_mAirCylReq_IRV_MP[2] = { 0U, 0U
};

VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresCor_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresInter_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReqPrev = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReq_IRV_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPres_MP = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_tiDlyAftEgrFoulPrev = 0U;
VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_tiDlyAftEgrFoul_IRV_MP = 0U;

#define AirSysAir_STOP_SEC_INTERNAL_VAR_16BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AirSysAir_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysAir_MemMap.h"

VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bActStraLimSurgeDmpSw = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvDmp = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvDmpRaw_MP = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvTq = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvTqRaw_MP = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhCfeFil = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIAccPMin = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIEgrFoul = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPILimSurge = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIStructAirOpl = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIThrLim = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPITranLdDet = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhTrbAirPresRatCtl = FALSE;
VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bThrEff_MP = FALSE;

#define AirSysAir_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysAir_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
