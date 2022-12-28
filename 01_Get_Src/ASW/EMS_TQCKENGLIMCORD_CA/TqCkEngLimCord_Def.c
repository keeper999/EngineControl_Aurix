/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : TqCkEngLimCord                                          */
/* !Description     : SAFETY TMS : GERER LE BOUCLAGE                          */
/*                                                                            */
/* !Module          : TqCkEngLimCord                                          */
/*                                                                            */
/* !File            : TqCkEngLimCord_Def.c                                    */
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
/*   Code generated on: Tue Jun 19 17:16:01 2012                              */
/*   Model name       : TqCkEngLimCord_AUTOCODE.mdl                           */
/*   Model version    : 1.173                                                 */
/*   Root subsystem   : /TqCkEngLimCord                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKENGLIMCORD_CA/TqCk$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Jun 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TqCkEngLimCord.h"
#include "TqCkEngLimCord_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define TQCKENGLIMCORD_START_SEC_CALIB_16BIT
#include "TqCkEngLimCord_MemMap.h"

CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_nEngOplThdX_A[8] = { 3000U, 4000U,
  8000U, 12000U, 16000U, 20000U, 24000U, 28000U } ;

CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftTqIdcAgIgMin_C = 500U;
CONST(SInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqDifHighForc_C = 200;
CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqHiResThr_C = 3200U;
CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqLoResThr_C = 0U;
CONST(SInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqMaxAntiOsc_C = 400;
CONST(SInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqOfsAgIgMin_C = 384;
CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqOplThd_T[8] = { 33120U, 33120U,
  33120U, 33120U, 33120U, 33120U, 33120U, 33120U } ;

#define TQCKENGLIMCORD_STOP_SEC_CALIB_16BIT
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define TQCKENGLIMCORD_START_SEC_CALIB_8BIT
#include "TqCkEngLimCord_MemMap.h"

CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_noTqReqChaASR_C = 5U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_noTqReqChaMSR_C = 6U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiAcvForcCll_C = 25U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDeacForcCll_C = 10U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftCll_C = 10U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftIdcAir_C = 10U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftTqAntiOscMon_C = 10U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiTqDifCfm_C = 25U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiTranCll_C = 25U;
CONST(UInt8, TQCKENGLIMCORD_CALIB) TQCKENGLIMCORD_u8Inhib = 0U;

#define TQCKENGLIMCORD_STOP_SEC_CALIB_8BIT
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define TQCKENGLIMCORD_START_SEC_CALIB_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftAOS_C = 0;
CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftAgIgMin_C = 1;
CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftCll_C = 0;
CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftIdcAir_C = 0;

#define TQCKENGLIMCORD_STOP_SEC_CALIB_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define TQCKENGLIMCORD_START_SEC_VAR_16BIT
#include "TqCkEngLimCord_MemMap.h"

VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqCkAntiOscCord;
VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqCkEngLimCord;
VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqCkEngLimCordRaw;
VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqIdcEngLimCordIgMin;

#define TQCKENGLIMCORD_STOP_SEC_VAR_16BIT
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define TQCKENGLIMCORD_START_SEC_VAR_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bAcvCllRaw_MP;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftAOS;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftAgIgMin;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftCll;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftIdcAir;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoAOS_MP;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoAgIgMin_MP;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoCll_MP;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoIdcAir_MP;
VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoTqCord;

#define TQCKENGLIMCORD_STOP_SEC_VAR_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
