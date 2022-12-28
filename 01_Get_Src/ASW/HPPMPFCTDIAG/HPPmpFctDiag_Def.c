/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpFctDiag                                            */
/* !Description     : HPPmpFctDiag– DIAGNOSTIC FONCTIONNEL DE LA REGULATION PRESSION RAIL*/
/*                                                                            */
/* !Module          : HPPmpFctDiag                                            */
/*                                                                            */
/* !File            : HPPmpFctDiag_Def.c                                      */
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
/*   Code generated on: Wed Jul 17 22:17:33 2013                              */
/*   Model name       : HPPmpFctDiag_AUTOCODE.mdl                             */
/*   Model version    : 1.352                                                 */
/*   Root subsystem   : /HPPmpFctDiag                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPFCTDIAG/HPPmpFctDiag$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   24 Jul 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpFctDiag.h"
#include "HPPmpFctDiag_private.h"

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
#define HPPMPFCTDIAG_START_SEC_CALIB_32BIT
#include "HPPmpFctDiag_MemMap.h"

CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiAftrCutOff_C = 1000U;
CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiORngDly_C = 500U;
CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiPFuRailMes_C = 1000U;
CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiThdDetDeICtl_C = 1000U;
CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiTransPFuReq_C = 1000U;

#define HPPMPFCTDIAG_STOP_SEC_CALIB_32BIT
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define HPPMPFCTDIAG_START_SEC_CALIB_16BIT
#include "HPPmpFctDiag_MemMap.h"

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailNegDifColdTcoThd_T[9] = { 8000U,
  8000U, 8000U, 8000U, 8000U, 8000U, 8000U, 8000U, 8000U } ;

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailNegDifHotTcoThd_T[9] = { 8000U,
  8000U, 8000U, 8000U, 8000U, 8000U, 8000U, 8000U, 8000U } ;

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailPosDifColdTcoThd_T[9] = { 2000U,
  2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U } ;

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailPosDifHotTcoThd_T[9] = { 2000U,
  2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U } ;

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_nEngMin_C = 750U;
CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuRailINegThdDetDe_T[9] = { 62975U,
  62975U, 62975U, 62975U, 62975U, 62975U, 62975U, 62975U, 62975U } ;

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuRailIPosThdDetDe_T[9] = { 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U } ;

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuRailMesThd_C = 2560U;
CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuReqMax_C = 2560U;
CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuReqMin_C = 8960U;
CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuReq_A[9] = { 128U, 384U, 768U,
  1280U, 1664U, 2304U, 2560U, 2816U, 3200U } ;

CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pPrailSpDiff_C = 640U;

#define HPPMPFCTDIAG_STOP_SEC_CALIB_16BIT
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define HPPMPFCTDIAG_START_SEC_CALIB_8BIT
#include "HPPmpFctDiag_MemMap.h"

CONST(UInt8, HPPMPFCTDIAG_CALIB) HPPMPFCTDIAG_u8Inhib = 10U;
CONST(UInt8, HPPMPFCTDIAG_CALIB) PFuCtl_tCoMesThd_C = 50U;
CONST(UInt8, HPPMPFCTDIAG_CALIB) PFuCtl_tCoMes_A[9] = { 0U, 20U, 40U, 60U, 80U,
  100U, 120U, 140U, 160U } ;

#define HPPMPFCTDIAG_STOP_SEC_CALIB_8BIT
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define HPPMPFCTDIAG_START_SEC_VAR_32BIT
#include "HPPmpFctDiag_MemMap.h"

VAR(Float32, HPPMPFCTDIAG_VAR) PFuCtl_PrailLoopErr;
VAR(Float32, HPPMPFCTDIAG_VAR) PFuCtl_pFuReqDiff;
VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiAftrCutOffDly;
VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiPFuRailMesDly;
VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiPrailOvrThd_prev;
VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiThdDetDeICtlDlyNeg;
VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiThdDetDeICtlDlyPos;
VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiTransPFuReqDly;

#define HPPMPFCTDIAG_STOP_SEC_VAR_32BIT
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define HPPMPFCTDIAG_START_SEC_VAR_BOOLEAN
#include "HPPmpFctDiag_MemMap.h"

VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bAcvDecCntDeICtlNeg;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bAcvDecCntDeICtlPos;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngIFrz_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngMax_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngNegDifI_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngNeg_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngPosDifI_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngPos_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDiagAcvCond;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDlyAftrCutOff;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngDifI_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngIFrz_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngMax_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngNeg_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngPos_PFuCtl;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bTransDiagAcvCond;
VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bTransPFuReq;

#define HPPMPFCTDIAG_STOP_SEC_VAR_BOOLEAN
#include "HPPmpFctDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
