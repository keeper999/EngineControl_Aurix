/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSysMgrCrk                                            */
/* !Description     : InjSysMgrCrk : Start manager                            */
/*                                                                            */
/* !Module          : InjSysMgrCrk                                            */
/*                                                                            */
/* !File            : InjSysMgrCrk_Def.c                                      */
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
/*   Code generated on: Wed May 01 18:07:07 2013                              */
/*   Model name       : InjSysMgrCrk_AUTOCODE.mdl                             */
/*   Model version    : 1.204                                                 */
/*   Root subsystem   : /InjSysMgrCrk                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJSYSMGRCRK/InjSysMgrCrk_$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   14 May 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjSysMgrCrk.h"
#include "InjSysMgrCrk_private.h"

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
#define INJSYSMGRCRK_START_SEC_CALIB_16BIT
#include "InjSysMgrCrk_MemMap.h"

CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuRailLoThdInhHPst_C = 1920U;
CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThAcvInjLPSt_C = 640U;
CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModHSTT_T[16] = { 3840U,
  3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U,
  3840U, 3840U, 3840U, 3840U } ;

CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModH_T[16] = { 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U } ;

CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModSSTT_T[16] = { 3840U,
  3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U, 3840U,
  3840U, 3840U, 3840U, 3840U } ;

CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModS_T[16] = { 5120U,
  5120U, 5120U, 5120U, 5120U, 5120U, 5120U, 5120U, 5120U, 5120U, 5120U, 5120U,
  5120U, 5120U, 5120U, 5120U } ;

CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModSplSTT_T[16] = { 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U } ;

CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModSpl_T[16] = { 2560U,
  2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U, 2560U,
  2560U, 2560U, 2560U, 2560U } ;

CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_tFuHPSt_A[9] = { 10U, 25U, 40U, 55U,
  70U, 85U, 100U, 115U, 130U } ;

#define INJSYSMGRCRK_STOP_SEC_CALIB_16BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define INJSYSMGRCRK_START_SEC_CALIB_8BIT
#include "InjSysMgrCrk_MemMap.h"

CONST(UInt8, INJSYSMGRCRK_CALIB) INJSYSMGRCRK_u8Inhib = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_bAuthHPStSTT_T[9] = { 0U, 0U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U } ;

CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_bAuthHPSt_T[9] = { 0U, 0U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U } ;

CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_ctTDCThdAcvInjHPRstrt_T[16] = { 15U,
  15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U } ;

CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_ctTDCThdAcvInjHPstSTT_T[16] = { 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_ctTDCThdAcvInjHPst_T[16] = { 15U, 15U,
  15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U } ;

CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvHPstSTT_C = 160U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvHPst_C = 160U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplLPSTT_C = 40U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplstLP_C = 40U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplstSTT_C = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplst_C = 160U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSstSTT_C = 160U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSst_C = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvHPstSTT_C = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvHPst_C = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplLPSTT_C = 40U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplstLP_C = 40U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplstSTT_C = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplst_C = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSstSTT_C = 0U;
CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSst_C = 0U;

#define INJSYSMGRCRK_STOP_SEC_CALIB_8BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define INJSYSMGRCRK_START_SEC_CALIB_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

CONST(Boolean, INJSYSMGRCRK_CALIB) InjSys_bInhETBHPst_C = 0;
CONST(Boolean, INJSYSMGRCRK_CALIB) InjSys_bInhTFuelCondForHPStrt_C = 0;

#define INJSYSMGRCRK_STOP_SEC_CALIB_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define INJSYSMGRCRK_START_SEC_VAR_16BIT
#include "InjSysMgrCrk_MemMap.h"

VAR(UInt16, INJSYSMGRCRK_VAR) InjSys_pFuThdAcvInjHPst;

#define INJSYSMGRCRK_STOP_SEC_VAR_16BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define INJSYSMGRCRK_START_SEC_VAR_8BIT
#include "InjSysMgrCrk_MemMap.h"

VAR(UInt8, INJSYSMGRCRK_VAR) InjSys_ctTDCThdAcvInjHPPrev;
VAR(UInt8, INJSYSMGRCRK_VAR) InjSys_ctTDCThdAcvInjHPst;

#define INJSYSMGRCRK_STOP_SEC_VAR_8BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define INJSYSMGRCRK_START_SEC_VAR_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvHPst;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModH;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModHprev;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSplst;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSplstPrev;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSst;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSstPrev;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAgStopNoInhHP;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAuthHPst;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bDetPFuThdInjHPst;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bDetPFuThdInjHPstPrev;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bDisaHPst;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bInhInjHPst;
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_prm_bInhInjHPCylPrev[6];
VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_prm_bInhInjHPstCyl[6];

#define INJSYSMGRCRK_STOP_SEC_VAR_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
