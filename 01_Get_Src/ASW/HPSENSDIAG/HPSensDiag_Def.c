/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPSensDiag                                              */
/* !Description     : Functional diagnosis of HP Sensor                       */
/*                                                                            */
/* !Module          : HPSensDiag                                              */
/*                                                                            */
/* !File            : HPSensDiag_Def.c                                        */
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
/*   Code generated on: Thu Oct 17 18:16:02 2013                              */
/*   Model name       : HPSensDiag_Autocode.mdl                               */
/*   Model version    : 1.418                                                 */
/*   Root subsystem   : /HPSensDiag                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/HPSENSDIAG/HPSensDiag_Def.c_v$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   21 Oct 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPSensDiag.h"
#include "HPSensDiag_private.h"

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
#define HPSENSDIAG_START_SEC_CALIB_32BIT
#include "HPSensDiag_MemMap.h"

CONST(SInt32, HPSENSDIAG_CALIB) Fu_mFuDifBtwSpl_A[9] = { -9395, -6711, -4027,
  -2013, 0, 2013, 4027, 6711, 9395 } ;

#define HPSENSDIAG_STOP_SEC_CALIB_32BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define HPSENSDIAG_START_SEC_CALIB_16BIT
#include "HPSensDiag_MemMap.h"

CONST(UInt16, HPSENSDIAG_CALIB) Fu_mFuDifThdMin_C = 2684U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_mFuInjMinHPSensThd_C = 0U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuDifHPSensDiagThd_C = 256U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailDifNegThd_T[9] = { 64895U, 64895U,
  64895U, 64895U, 64895U, 64895U, 64895U, 64895U, 64895U } ;

CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailDifPosThd_T[9] = { 640U, 640U, 640U,
  640U, 640U, 640U, 640U, 640U, 640U } ;

CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailGrdHPSensDiag_C = 640U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailMaxHPSensThd_C = 26880U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailMinHPSensThd_C = 2560U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailThdMax_C = 32000U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailThdMin_C = 1280U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuReqGrdHPSensDiagThd_C = 26U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuReqThdBdVal_C = 128U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_rFuEngMinHPSensThd_C = 400U;
CONST(UInt16, HPSENSDIAG_CALIB) Fu_tiPFuRailStabHPSensDiagDly_C = 250U;

#define HPSENSDIAG_STOP_SEC_CALIB_16BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define HPSENSDIAG_START_SEC_CALIB_8BIT
#include "HPSensDiag_MemMap.h"

CONST(UInt8, HPSENSDIAG_CALIB) HPSENSDIAG_u8Inhib = 0U;

#define HPSENSDIAG_STOP_SEC_CALIB_8BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define HPSENSDIAG_START_SEC_VAR_32BIT
#include "HPSensDiag_MemMap.h"

VAR(SInt32, HPSENSDIAG_VAR) Fu_mFuDifBtwSpl;

#define HPSENSDIAG_STOP_SEC_VAR_32BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define HPSENSDIAG_START_SEC_VAR_16BIT
#include "HPSensDiag_MemMap.h"

VAR(UInt16, HPSENSDIAG_VAR) Fu_mFuInjBtwEveSpl;
VAR(SInt16, HPSENSDIAG_VAR) Fu_pFuDifHPSensDiag;
VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuRailGrdHPSensDiag;
VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuRailHPSensDiagMem;
VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqDiagMem;
VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqGrdHPSensDiag;
VAR(SInt16, HPSENSDIAG_VAR) Fu_pFuReqGrdHPSensDiagRaw;
VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqPrev;
VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqPrevIni;
VAR(UInt16, HPSENSDIAG_VAR) Fu_tiPFuRailStabHPSensDiagDly;

#define HPSENSDIAG_STOP_SEC_VAR_16BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define HPSENSDIAG_START_SEC_VAR_BOOLEAN
#include "HPSensDiag_MemMap.h"

VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvHPSensDiag_pFuRailCond;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvPFuRailSenDiag;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvStuck_HPSens;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvStuck_HPSens_prev;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bCondDiag_HPSens;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bDgoCoh_HPSens;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bDgoStuck_HPSens;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bMonRunCoh_HPSens;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bMonRunStuck_HPSens;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bPFuRailStabHPSensDiag;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bPFuRailStabHPSensDiag_prev;
VAR(Boolean, HPSENSDIAG_VAR) Fu_bRawDgoStuck_HPSens;

#define HPSENSDIAG_STOP_SEC_VAR_BOOLEAN
#include "HPSensDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
