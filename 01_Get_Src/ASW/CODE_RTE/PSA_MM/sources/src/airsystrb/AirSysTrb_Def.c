/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysTrb                                               */
/* !Description     : AirSysTrb Software Component                            */
/*                                                                            */
/* !Module          : AirSysTrb                                               */
/*                                                                            */
/* !File            : AirSysTrb_Def.c                                         */
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
/*   Model name       : AirSysTrb_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysTrb                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M18-AirSysTrb/5-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   PLCHINAZ                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirSysTrb.h"
#include "AirSysTrb_private.h"

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
#define AirSysTrb_START_SEC_CARTO_16BIT
#include "AirSysTrb_MemMap.h"

CONST(UInt16, AIRSYSTRB_CARTO) AirSys_facFilGainTrbMod_T[9] = { 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U } ;

CONST(UInt16, AIRSYSTRB_CARTO) AirSys_facFilGainUsThrPres_T[9] = { 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U } ;

CONST(UInt16, AIRSYSTRB_CARTO) AirSys_facRatPresThrClcn_A[9] = { 0U, 3880U,
  6711U, 9018U, 11534U, 14470U, 17511U, 23803U, 29675U } ;

CONST(UInt16, AIRSYSTRB_CARTO) AirSys_rAirPresThr_T[9] = { 8192U, 8208U, 8240U,
  8280U, 8336U, 8416U, 8520U, 8792U, 9112U } ;

CONST(UInt16, AIRSYSTRB_CARTO) Air_pLossAirFil_T[16] = { 0U, 20U, 40U, 81U,
  121U, 171U, 220U, 281U, 341U, 409U, 476U, 554U, 631U, 741U, 850U, 1094U } ;

CONST(UInt16, AIRSYSTRB_CARTO) Air_pLossCAC_T[16] = { 0U, 50U, 100U, 182U,
  264U, 375U, 486U, 643U, 800U, 988U, 1175U, 1377U, 1579U, 1821U, 2064U, 2554U }
;

#define AirSysTrb_STOP_SEC_CARTO_16BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define AirSysTrb_START_SEC_CALIB_16BIT
#include "AirSysTrb_MemMap.h"

CONST(UInt16, AIRSYSTRB_CALIB) AirSys_mfAirThrReqFil_B = 0U;
CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pDifDsCmprUsThrReq_B = -32768;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pDsCmprReqFil_B = 0U;
CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pGrdUsThrHiThd_C = 0;
CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pGrdUsThrInhFrzThd_C = 625;
CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pGrdUsThrLoThd_C = -312;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pLossAirThrMax_C = 0U;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pUsCmprReqFil_B = 0U;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pUsThrReqFil_B = 0U;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pUsThrReq_B = 0U;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_tiDlyDetAccPNull_C = 0U;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_tiDlyDetPGrdUsThr_C = 0U;
CONST(UInt16, AIRSYSTRB_CALIB) AirSys_tiDlyFrz_C = 5734U;

#define AirSysTrb_STOP_SEC_CALIB_16BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AirSysTrb_START_SEC_CALIB_BOOLEAN
#include "AirSysTrb_MemMap.h"

CONST(Boolean, AIRSYSTRB_CALIB) AIRSYSTRB_ACTIVE_BYP_C = 0;
CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bAcvFrzMod_B = 0;
CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bAcvFrzMod_C = 1;
CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bAcvStraLimSurgeFrz_C = 0;
CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bDetMT_C = 1;

#define AirSysTrb_STOP_SEC_CALIB_BOOLEAN
#include "AirSysTrb_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define AirSysTrb_START_SEC_INTERNAL_VAR_32BIT
#include "AirSysTrb_MemMap.h"

VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_mfAirThrReqFilPrev = 0.0F;
VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pDsCmprReqFilPrev = 0.0F;
VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pDsCmprReq_IRV_MP = 0.0F;
VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pUsCmprReqFilPrev = 0.0F;
VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pUsCmprReq_IRV_MP = 0.0F;
VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pUsThrReqFilPrev = 0.0F;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_32BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define AirSysTrb_START_SEC_INTERNAL_VAR_16BIT
#include "AirSysTrb_MemMap.h"

VAR(UInt16, AIRSYSTRB_INTERNAL_VAR) AirSys_facRatPresThrClcn_MP = 0U;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_16BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AirSysTrb_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysTrb_MemMap.h"

VAR(Boolean, AIRSYSTRB_INTERNAL_VAR) AirSys_bInhFrzMod_MP = FALSE;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysTrb_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
