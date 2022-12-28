/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuRailCtlMgr                                            */
/* !Description     : FuRailCtlMgr- RAIL PRESSURE CONTROL MANAGER             */
/*                                                                            */
/* !Module          : FuRailCtlMgr                                            */
/*                                                                            */
/* !File            : FuRailCtlMgr_Def.c                                      */
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
/*   Code generated on: Wed Dec 19 10:34:55 2012                              */
/*   Model name       : FuRailCtlMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.333                                                 */
/*   Root subsystem   : /FuRailCtlMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/FuRailCtlMgr/5-SOFT-LIV/FuRa$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   19 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "FuRailCtlMgr.h"
#include "FuRailCtlMgr_private.h"

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
#define FURAILCTLMGR_START_SEC_CALIB_16BIT
#include "FuRailCtlMgr_MemMap.h"

CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailLoThdInhClCtl_C = 0U;
CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModHSTT_T[16] = { 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModH_T[16] = { 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModSSTT_T[16] = { 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModS_T[16] = { 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModSpl_T[16] = { 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlSplSTT_T[16] = { 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

#define FURAILCTLMGR_STOP_SEC_CALIB_16BIT
#include "FuRailCtlMgr_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define FURAILCTLMGR_START_SEC_CALIB_8BIT
#include "FuRailCtlMgr_MemMap.h"

CONST(UInt8, FURAILCTLMGR_CALIB) Ext_tCoMes_A[16] = { 10U, 15U, 20U, 25U, 30U,
  36U, 40U, 50U, 58U, 70U, 80U, 90U, 100U, 115U, 130U, 150U } ;

CONST(UInt8, FURAILCTLMGR_CALIB) FURAILCTLMGR_u8Inhib = 0U;

#define FURAILCTLMGR_STOP_SEC_CALIB_8BIT
#include "FuRailCtlMgr_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define FURAILCTLMGR_START_SEC_CALIB_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

CONST(Boolean, FURAILCTLMGR_CALIB) PFuCtl_bAcvHPPmpCutOff_C = 1;
CONST(Boolean, FURAILCTLMGR_CALIB) PFuCtl_bAcvLPCmdContns_C = 0;
CONST(Boolean, FURAILCTLMGR_CALIB) PFuCtl_bAcvPFuCtlCrk_C = 1;

#define FURAILCTLMGR_STOP_SEC_CALIB_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define FURAILCTLMGR_START_SEC_VAR_16BIT
#include "FuRailCtlMgr_MemMap.h"

VAR(UInt16, FURAILCTLMGR_VAR) PFuCtl_pFuRailHiThdAcvClCtl;

#define FURAILCTLMGR_STOP_SEC_VAR_16BIT
#include "FuRailCtlMgr_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define FURAILCTLMGR_START_SEC_VAR_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bAcvCmdContnsReq;
VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bAcvPFuCtl;
VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bEveFirstSpl;
VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bInhPFuCtl;

#define FURAILCTLMGR_STOP_SEC_VAR_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
