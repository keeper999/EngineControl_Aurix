/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : StuckInjrDiag                                           */
/* !Description     : Diagnosis of stuck injectors                            */
/*                                                                            */
/* !Module          : StuckInjrDiag                                           */
/*                                                                            */
/* !File            : StuckInjrDiag_Def.c                                     */
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
/*   Code generated on: Sun Oct 20 10:36:43 2013                              */
/*   Model name       : StuckInjrDiag_AUTOCODE.mdl                            */
/*   Model version    : 1.223                                                 */
/*   Root subsystem   : /StuckInjrDiag                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/STUCKINJRDIAG/StuckInjrDiag_D$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   28 Oct 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "StuckInjrDiag.h"
#include "StuckInjrDiag_private.h"

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
#define STUCKINJRDIAG_START_SEC_CALIB_16BIT
#include "StuckInjrDiag_MemMap.h"

CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_MinEngAuthDiagStuckInjr_C = 400U;
CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_mFuSpStckOpInjrFallp_A[9] = { 0U, 134U,
  403U, 671U, 1342U, 2684U, 4027U, 6711U, 9395U } ;

CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_nEngStckOpInjrThd_A[9] = { 0U, 800U,
  1600U, 2400U, 3200U, 4000U, 4800U, 5600U, 6000U } ;

CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuRailDifStckOpInjrThd_M[81] = { 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U,
  35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U, 35328U
} ;

CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuRailStckOpInjrFallp_M[81] = { 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U,
  64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U, 64768U
} ;

CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuRailStckOpInjrThd_A[9] = { 512U,
  6400U, 9600U, 12800U, 16000U, 19200U, 22400U, 25600U, 32000U } ;

CONST(SInt16, STUCKINJRDIAG_CALIB) Fu_pFuReqGainMaxThd_C = 1000;
CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuReqOfsMaxThd_C = 32768U;
CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_rFuReqGainThd_C = 50U;
CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_tiPFuRailStabDly_C = 150U;

#define STUCKINJRDIAG_STOP_SEC_CALIB_16BIT
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define STUCKINJRDIAG_START_SEC_CALIB_8BIT
#include "StuckInjrDiag_MemMap.h"

CONST(UInt8, STUCKINJRDIAG_CALIB) STUCKINJRDIAG_u8Inhib = 0U;

#define STUCKINJRDIAG_STOP_SEC_CALIB_8BIT
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define STUCKINJRDIAG_START_SEC_CALIB_BOOLEAN
#include "StuckInjrDiag_MemMap.h"

CONST(Boolean, STUCKINJRDIAG_CALIB) Fu_bInhPFuRailStabStckInjr_C = 1;

#define STUCKINJRDIAG_STOP_SEC_CALIB_BOOLEAN
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define STUCKINJRDIAG_START_SEC_VAR_32BIT
#include "StuckInjrDiag_MemMap.h"

VAR(Float32, STUCKINJRDIAG_VAR) Fu_pFuReqGrdStckOpInjr_irv;

#define STUCKINJRDIAG_STOP_SEC_VAR_32BIT
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define STUCKINJRDIAG_START_SEC_VAR_16BIT
#include "StuckInjrDiag_MemMap.h"

VAR(SInt16, STUCKINJRDIAG_VAR) Fu_pFuRailDifStckOpInjrThd_MP;
VAR(UInt16, STUCKINJRDIAG_VAR) Fu_tiPFuRailStabDly;

#define STUCKINJRDIAG_STOP_SEC_VAR_16BIT
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define STUCKINJRDIAG_START_SEC_VAR_BOOLEAN
#include "StuckInjrDiag_MemMap.h"

VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bAcvDiagStuckInjr;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl1;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl2;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl3;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl4;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bFuRailStabStckInjr;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl1;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl2;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl3;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl4;
VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bPFuRailStab;

#define STUCKINJRDIAG_STOP_SEC_VAR_BOOLEAN
#include "StuckInjrDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
