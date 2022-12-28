/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuSysExtLeakDiag                                        */
/* !Description     : Functional diagnosis of external leak on Fuel System    */
/*                                                                            */
/* !Module          : FuSysExtLeakDiag                                        */
/*                                                                            */
/* !File            : FuSysExtLeakDiag_Def.c                                  */
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
/*   Code generated on: Tue Dec 17 15:22:53 2013                              */
/*   Model name       : FuSysExtLeakDiag_AUTOCODE.mdl                         */
/*   Model version    : 1.349                                                 */
/*   Root subsystem   : /FuSysExtLeakDiag                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FUSYSEXTLEAKDIAG/FuSysExtLeak$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   etsasson                               $$Date::   19 Dec 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "FuSysExtLeakDiag.h"
#include "FuSysExtLeakDiag_private.h"

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
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

CONST(UInt32, FUSYSEXTLEAKDIAG_CALIB) Fu_mFuReqDiff_C = 134U;
CONST(SInt32, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailDifExtLeakThd_C = 126;
CONST(UInt32, FUSYSEXTLEAKDIAG_CALIB) Fu_tiTransPFuReq_C = 1000U;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_nEngMinLeakEngRunDiag_C = 400U;
CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailExtLeakEngStallMem_A[9] = {
  512U, 3200U, 6400U, 9600U, 12800U, 16000U, 19200U, 22400U, 25600U } ;

CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailExtLeakMinThd_C = 15360U;
CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailGrdExtLkEngRunOfsThd_C = 3840U;
CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailGrdExtLkEngStallThd_T[9] = {
  3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U } ;

CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuReqDiff_C = 1280U;
CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_tiPFuRailExtLeakEngRunDly_C = 50U;
CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_tiPFuRailExtLeakEngStallDly_C = 100U;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_8BIT
#include "FuSysExtLeakDiag_MemMap.h"

CONST(UInt8, FUSYSEXTLEAKDIAG_CALIB) FUSYSEXTLEAKDIAG_u8Inhib = 0U;
CONST(UInt8, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailGrdExtLkEngRunGThd_C = 0U;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_8BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"

CONST(Boolean, FUSYSEXTLEAKDIAG_CALIB) Fu_bAcvExtLeakEngRunDiag_C = 1;
CONST(Boolean, FUSYSEXTLEAKDIAG_CALIB) Fu_bAcvExtLeakEngStallDiag_C = 1;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

VAR(UInt32, FUSYSEXTLEAKDIAG_VAR) Fu_tiTransPFuReqDly;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailExtLeakEngRunMem;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailExtLeakEngStallMem;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailGrdExtLeakEngRun;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailGrdExtLeakEngStall;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuReqDiff;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngRunDly;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngRunDlyIn;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngStallDly;
VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngStallDlyIn;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"

VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bActrTstInjr;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bAcvExtLeakEngRunDiag;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bAcvExtLeakEngStallDiag;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bDgoExtLeak_FuSys;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bMonRunExtLeak_FuSys;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStabMFuReq;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStabPFuReq;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStrtDiagExtLeakEngRun;
VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStrtDiagExtLeakEngStall;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
