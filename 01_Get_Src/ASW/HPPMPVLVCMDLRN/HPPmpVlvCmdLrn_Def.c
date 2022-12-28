/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpVlvCmdLrn                                          */
/* !Description     : HPPMPVLVCMDLRN - LEARNING STRATEGY OF THE HP PUMP SPILL VALVE COMMAND PROFILE*/
/*                                                                            */
/* !Module          : HPPmpVlvCmdLrn                                          */
/*                                                                            */
/* !File            : HPPmpVlvCmdLrn_Def.c                                    */
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
/*   Code generated on: Sun Mar 31 19:11:05 2013                              */
/*   Model name       : HPPmpVlvCmdLrn_AUTOCODE.mdl                           */
/*   Model version    : 1.471                                                 */
/*   Root subsystem   : /HPPmpVlvCmdLrn                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPVLVCMDLRN/HPPmpVlvCm$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   etsasson                               $$Date::   03 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpVlvCmdLrn.h"
#include "HPPmpVlvCmdLrn_private.h"

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
#define HPPMPVLVCMDLRN_START_SEC_CALIB_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

CONST(UInt32, HPPMPVLVCMDLRN_CALIB) PFuCtl_tiTransLrn_C = 1000U;
CONST(UInt32, HPPMPVLVCMDLRN_CALIB) PFuCtl_tiTransPrail_M[81] = { 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U, 3000U,
  3000U, 3000U } ;

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

CONST(SInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_FaildPmpStk_C = 2;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_NrAppl_T[16] = { 35U, 10U, 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_NrLrnCond_C = 3U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_OfsNrProfCmd_M[256] = { 250U, 248U,
  248U, 248U, 248U, 248U, 247U, 247U, 246U, 246U, 246U, 245U, 245U, 245U, 244U,
  244U, 252U, 250U, 248U, 248U, 248U, 248U, 247U, 247U, 246U, 246U, 246U, 245U,
  245U, 245U, 244U, 244U, 252U, 252U, 250U, 248U, 249U, 248U, 248U, 247U, 247U,
  246U, 246U, 246U, 245U, 245U, 244U, 244U, 252U, 252U, 252U, 250U, 248U, 249U,
  248U, 248U, 247U, 247U, 246U, 246U, 246U, 245U, 245U, 244U, 252U, 252U, 251U,
  252U, 250U, 248U, 249U, 248U, 248U, 247U, 247U, 246U, 246U, 246U, 245U, 245U,
  252U, 252U, 252U, 251U, 252U, 250U, 248U, 249U, 248U, 248U, 247U, 247U, 246U,
  246U, 246U, 245U, 253U, 253U, 252U, 252U, 251U, 252U, 250U, 248U, 248U, 248U,
  248U, 247U, 247U, 246U, 246U, 246U, 253U, 253U, 253U, 252U, 252U, 251U, 252U,
  250U, 248U, 248U, 248U, 248U, 247U, 247U, 246U, 246U, 254U, 254U, 253U, 253U,
  252U, 252U, 252U, 252U, 250U, 248U, 249U, 248U, 248U, 247U, 247U, 246U, 254U,
  254U, 254U, 253U, 253U, 252U, 252U, 252U, 252U, 250U, 249U, 249U, 248U, 248U,
  247U, 247U, 254U, 254U, 254U, 254U, 253U, 253U, 252U, 252U, 251U, 251U, 250U,
  248U, 249U, 248U, 248U, 247U, 255U, 255U, 254U, 254U, 254U, 253U, 253U, 252U,
  252U, 251U, 252U, 250U, 248U, 249U, 248U, 247U, 255U, 255U, 255U, 254U, 254U,
  254U, 253U, 253U, 252U, 252U, 251U, 252U, 250U, 248U, 249U, 249U, 255U, 255U,
  255U, 255U, 254U, 254U, 254U, 253U, 253U, 252U, 252U, 251U, 252U, 250U, 248U,
  249U, 256U, 256U, 256U, 255U, 255U, 254U, 254U, 254U, 253U, 253U, 252U, 252U,
  251U, 252U, 250U, 248U, 256U, 256U, 256U, 256U, 255U, 255U, 254U, 254U, 254U,
  253U, 253U, 253U, 251U, 251U, 252U, 250U } ;

CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_mFuInjEstim_A[16] = { 671U, 1342U,
  2013U, 2684U, 3355U, 4027U, 4698U, 5369U, 6040U, 6711U, 7382U, 8053U, 8724U,
  9395U, 10066U, 10737U } ;

CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngDiff_C = 400U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngHiLrnThdHi_C = 2000U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngHiLrnThdLo_C = 650U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngLoLrnThdHi_C = 1900U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngLoLrnThdLo_C = 600U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEng_tiTrans_A[9] = { 512U, 750U,
  1000U, 1500U, 2000U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesDiff_C = 6250U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesHiLrnThdHi_C = 15000U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesHiLrnThdLo_C = 13750U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesLoLrnThdHi_C = 11250U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesLoLrnThdLo_C = 11250U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pFuRailMesDiff_C = 640U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pFuReqDiff_C = 3840U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailDiffThd_C = 1024U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailHiDiffThdPmpStk_C = 1280U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailLoDiffThdPmpStk_C = 1152U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailSpDiffThdHi_C = 13U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pRailSpDifAbs_A[9] = { 640U, 1280U,
  2560U, 4480U, 6400U, 9600U, 12800U, 19200U, 25600U } ;

CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattDiff_C = 254U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattHiLrnThdHi_C = 614U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattHiLrnThdLo_C = 275U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattLoLrnThdHi_C = 572U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattLoLrnThdLo_C = 233U;
CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattLrn_A[16] = { 424U, 432U, 441U,
  466U, 475U, 483U, 500U, 508U, 517U, 525U, 542U, 551U, 568U, 581U, 593U, 614U }
;

CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBatt_A[16] = { 424U, 432U, 441U,
  466U, 475U, 483U, 500U, 508U, 517U, 525U, 542U, 551U, 568U, 581U, 593U, 614U }
;

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

CONST(UInt8, HPPMPVLVCMDLRN_CALIB) HPPMPVLVCMDLRN_u8Inhib = 0U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfCor_C = 0U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfETB_C = 2U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfiNoIdle_C = 2U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfilInit_C = 25U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfilTst_C = 25U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_FaildCndProfilInc_C = 1U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_LrnPmpCmdProfMax_C = 25U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_LrnPmpCmdProfMin_C = 6U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_NoSplRazFailPmpStk_C = 3U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_NrSpilEvePerCycle_C = 3U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdDftProfil_T[16] = { 1U, 1U, 1U,
  1U, 2U, 2U, 2U, 2U, 3U, 3U, 3U, 3U, 4U, 4U, 5U, 5U } ;

CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdProfDft_C = 25U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdProfMax_C = 25U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdProfMin_C = 1U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirHiLrnThdHi_C = 82U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirHiLrnThdLo_C = 30U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirLoLrnThdHi_C = 81U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirLoLrnThdLo_C = 30U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesHiLrnThdHi_C = 160U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesHiLrnThdLo_C = 20U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesLoLrnThdHi_C = 140U;
CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesLoLrnThdLo_C = 20U;

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

CONST(Boolean, HPPMPVLVCMDLRN_CALIB) PFuCtl_bAcvETBHPPmpVlvCmdLrn_C = 0;
CONST(Boolean, HPPMPVLVCMDLRN_CALIB) PFuCtl_bForcAcvLrn_C = 0;
CONST(Boolean, HPPMPVLVCMDLRN_CALIB) PFuCtl_bForcIntLrn_C = 0;

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

VAR(Float32, HPPMPVLVCMDLRN_VAR) PFuCtl_tideltaT;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_nEngLrn;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_pDsThrMesSILrn;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_pFuRailSplMesLrn;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_uBattLrn;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) InjSys_pFuReqLrn;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_NrAppl;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_NrLrnIt;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_NrLrnIt_prev;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_OfsNrProfCmd;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_ctNrAppl;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_ctNrLrnInProgs;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_ctNrLrnVld;
VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_pRailSpDifAbs;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmd;
VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmdRaw;
VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmdRawSat;
VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmdRaw_prev;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvFaildPmpStk;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvFaildPmpStks;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvHPPmpBgnLrn;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvHPPmpVlvLrnCond;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvLowNoiseZone;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvLrnInProgs;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvLrnInProgs_prev;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvPFuIncTst;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvRstLrnPFuInc;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bFaildPmpStk;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnFaild;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnIt;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnIt_prev;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnVld;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnVld_prev;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bLrnVldFaildPmpStk;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bPmpCmdLrnRst;
VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bRunHPPmpLrn;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
