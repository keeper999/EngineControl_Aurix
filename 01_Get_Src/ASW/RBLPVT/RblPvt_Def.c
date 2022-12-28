/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : RblPvt                                                  */
/* !Description     : RUMBLE PREVENTION                                       */
/*                                                                            */
/* !Module          : RblPvt                                                  */
/*                                                                            */
/* !File            : RblPvt_Def.c                                            */
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
/*   Code generated on: Thu Dec 13 15:30:24 2012                              */
/*   Model name       : RblPvt_AUTOCODE.mdl                                   */
/*   Model version    : 1.23                                                  */
/*   Root subsystem   : /RblPvt                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/RblPvt/5-SOFT-LIV/RblPvt_Def$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   14 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "RblPvt.h"
#include "RblPvt_private.h"

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
#define RBLPVT_START_SEC_CALIB_16BIT
#include "RblPvt_MemMap.h"

CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctRblIrvLdLimPvtHiThd_C = 3000U;
CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctRbllrvLdLimPvtLoThd_C = 2000U;
CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctToilRblIrvLdLimHiThd_C = 3000U;
CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctToilRbllrvLdLimLoThd_C = 2000U;
CONST(UInt16, RBLPVT_CALIB) KnkMgt_pDsThrMes_A[9] = { 0U, 625U, 1000U, 1250U,
  1375U, 1500U, 1625U, 1875U, 2500U } ;

CONST(SInt16, RBLPVT_CALIB) KnkMgt_tOilMesHi_C = 100;
CONST(SInt16, RBLPVT_CALIB) KnkMgt_tOilMesLo_C = 100;

#define RBLPVT_STOP_SEC_CALIB_16BIT
#include "RblPvt_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define RBLPVT_START_SEC_CALIB_8BIT
#include "RblPvt_MemMap.h"

CONST(UInt8, RBLPVT_CALIB) KnkMgt_ctTotRblPvtInc_M[81] = { 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U } ;

CONST(UInt8, RBLPVT_CALIB) KnkMgt_ctTotRblPvtToilH_M[81] = { 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U } ;

CONST(UInt8, RBLPVT_CALIB) KnkMgt_ctTotRblPvtToilL_M[81] = { 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U, 11U } ;

CONST(UInt8, RBLPVT_CALIB) RBLPVT_u8Inhib = 0U;

#define RBLPVT_STOP_SEC_CALIB_8BIT
#include "RblPvt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define RBLPVT_START_SEC_VAR_32BIT
#include "RblPvt_MemMap.h"

VAR(Float32, RBLPVT_VAR) KnkMgt_facCtRblToil;

#define RBLPVT_STOP_SEC_VAR_32BIT
#include "RblPvt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define RBLPVT_START_SEC_VAR_16BIT
#include "RblPvt_MemMap.h"

VAR(UInt16, RBLPVT_VAR) KnkMgt_ctTotRblPvtInc;
VAR(UInt16, RBLPVT_VAR) KnkMgt_ctTotRblToil;

#define RBLPVT_STOP_SEC_VAR_16BIT
#include "RblPvt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define RBLPVT_START_SEC_VAR_BOOLEAN
#include "RblPvt_MemMap.h"

VAR(Boolean, RBLPVT_VAR) KnkMgt_bAcvIrvLdLimRblPvtReq;
VAR(Boolean, RBLPVT_VAR) KnkMgt_bAcvIrvLdLimToilReq;

#define RBLPVT_STOP_SEC_VAR_BOOLEAN
#include "RblPvt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
