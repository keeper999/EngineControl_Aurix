/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : MonEngStrt                                              */
/* !Description     : Surveillance du démarrage                               */
/*                                                                            */
/* !Module          : MonEngStrt                                              */
/*                                                                            */
/* !File            : MonEngStrt_Def.c                                        */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Sep 11 09:00:08 2013                              */
/*   Model name       : MonEngStrt_AUTOCODE.mdl                               */
/*   Model version    : 1.201                                                 */
/*   Root subsystem   : /MonEngStrt                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/MONENGSTRT/MonEngStrt_Def.$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   16 Sep 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "MonEngStrt.h"
#include "MonEngStrt_private.h"

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
#define MONENGSTRT_START_SEC_CALIB_16BIT
#include "MonEngStrt_MemMap.h"

CONST(UInt16, MONENGSTRT_CALIB) EngSt_nEngPFuLim_C = 60U;
CONST(UInt16, MONENGSTRT_CALIB) EngSt_nEngSyncLim_C = 60U;
CONST(UInt16, MONENGSTRT_CALIB) EngSt_nEngUnlockADCLim_C = 60U;
CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiPFuMinLim_T[6] = { 200U, 200U, 200U,
  200U, 200U, 200U } ;

CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiStrtLim_T[6] = { 1970U, 1400U, 870U,
  500U, 250U, 180U } ;

CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiSyncLim_T[6] = { 200U, 200U, 200U,
  200U, 200U, 200U } ;

CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiUnlockADCLim_C = 200U;
CONST(UInt16, MONENGSTRT_CALIB) EngSt_uBattPFuLim_C = 339U;
CONST(UInt16, MONENGSTRT_CALIB) EngSt_uBattSyncLim_C = 339U;
CONST(UInt16, MONENGSTRT_CALIB) EngSt_uBattThdCmdCrk_C = 339U;

#define MONENGSTRT_STOP_SEC_CALIB_16BIT
#include "MonEngStrt_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define MONENGSTRT_START_SEC_CALIB_8BIT
#include "MonEngStrt_MemMap.h"

CONST(UInt8, MONENGSTRT_CALIB) EngSt_bkptTcoStrt_A[6] = { 20U, 25U, 32U, 40U,
  50U, 55U } ;

CONST(UInt8, MONENGSTRT_CALIB) EngSt_volFuInitMin_C = 10U;
CONST(UInt8, MONENGSTRT_CALIB) MONENGSTRT_u8Inhib = 0U;

#define MONENGSTRT_STOP_SEC_CALIB_8BIT
#include "MonEngStrt_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define MONENGSTRT_START_SEC_CALIB_BOOLEAN
#include "MonEngStrt_MemMap.h"

CONST(Boolean, MONENGSTRT_CALIB) EngSt_bStrtDiagCf_C = 0;

#define MONENGSTRT_STOP_SEC_CALIB_BOOLEAN
#include "MonEngStrt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define MONENGSTRT_START_SEC_VAR_16BIT
#include "MonEngStrt_MemMap.h"

VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlyPFuMin;
VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlyStrt;
VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlySync;
VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlyUnlockADC;
VAR(UInt16, MONENGSTRT_VAR) EngSt_uBattInit;

#define MONENGSTRT_STOP_SEC_VAR_16BIT
#include "MonEngStrt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define MONENGSTRT_START_SEC_VAR_BOOLEAN
#include "MonEngStrt_MemMap.h"

VAR(Boolean, MONENGSTRT_VAR) EngSt_bAcvStrtDiag;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bCmdCranking;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngPFuEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngStrtEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngSyncEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngUnlockEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bFuLvlOK;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonEngStrtEnd;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngPFuEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngStrtEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngSyncEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngUnlockEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonWaitORngEngSt;
VAR(Boolean, MONENGSTRT_VAR) EngSt_bStrtDiagCf;

#define MONENGSTRT_STOP_SEC_VAR_BOOLEAN
#include "MonEngStrt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define MONENGSTRT_START_SEC_VAR_8BIT
#include "MonEngStrt_MemMap.h"

VAR(UInt8, MONENGSTRT_VAR) EngSt_stMonEngStrt;
VAR(UInt8, MONENGSTRT_VAR) EngSt_volFuInit;

#define MONENGSTRT_STOP_SEC_VAR_8BIT
#include "MonEngStrt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
