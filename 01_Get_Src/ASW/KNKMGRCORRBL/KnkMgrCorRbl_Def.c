/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkMgrCorRbl                                            */
/* !Description     : CORRECTION RUMBLE                                       */
/*                                                                            */
/* !Module          : KnkMgrCorRbl                                            */
/*                                                                            */
/* !File            : KnkMgrCorRbl_Def.c                                      */
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
/*   Code generated on: Mon Mar 03 16:32:53 2014                              */
/*   Model name       : KnkMgrCorRbl_AUTOCODE.mdl                             */
/*   Model version    : 1.302                                                 */
/*   Root subsystem   : /KnkMgrCorRbl                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKMGRCORRBL/KnkM$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   mbenfrad                               $$Date::   04 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "KnkMgrCorRbl.h"
#include "KnkMgrCorRbl_private.h"

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
#define KNKMGRCORRBL_START_SEC_CALIB_32BIT
#include "KnkMgrCorRbl_MemMap.h"

CONST(UInt32, KNKMGRCORRBL_CALIB) KnkMgt_ctOccurRblIrvLdLimHiThd_C = 500U;
CONST(UInt32, KNKMGRCORRBL_CALIB) KnkMgt_ctOccurRbllrvLdLimLoThd_C = 200U;

#define KNKMGRCORRBL_STOP_SEC_CALIB_32BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define KNKMGRCORRBL_START_SEC_CALIB_16BIT
#include "KnkMgrCorRbl_MemMap.h"

CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_ctTotKnkRblInc_M[81] = { 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } ;

CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_ctTotRblInc_M[81] = { 30U, 30U, 30U,
  30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U,
  30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U,
  30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U,
  30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U,
  30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U } ;

CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEngNbZoneRbl_A[3] = { 1000U, 4000U,
  7000U } ;

CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEngSuperKnkHiThd_C = 3500U;
CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEngSuperKnkLoThd_C = 3300U;
CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEng_A[9] = { 6000U, 10000U, 14000U,
  18000U, 24000U, 32000U, 40000U, 44000U, 48000U } ;

CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rAirLdNbZoneRbl_A[3] = { 1638U,
  18022U, 32768U } ;

CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rAirLd_A[9] = { 1638U, 4915U, 8192U,
  11469U, 14746U, 18022U, 21299U, 24576U, 32768U } ;

CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rLdSuperKnkHiThd_C = 24576U;
CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rLdSuperKnkLoThd_C = 8192U;
CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_tqGlblTqRawSpThd_M[9] = { 32800U,
  32800U, 32800U, 32800U, 32800U, 33600U, 33600U, 33600U, 33600U } ;

#define KNKMGRCORRBL_STOP_SEC_CALIB_16BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define KNKMGRCORRBL_START_SEC_CALIB_8BIT
#include "KnkMgrCorRbl_MemMap.h"

CONST(UInt8, KNKMGRCORRBL_CALIB) KNKMGRCORRBL_u8Inhib = 0U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl1_T[16] = { 5U, 2U, 2U, 10U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl2_T[16] = { 5U, 1U, 4U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl3_T[16] = { 9U, 1U, 7U, 1U,
  5U, 1U, 3U, 1U, 1U, 1U, 1U, 30U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl4_T[16] = { 5U, 3U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOfTmpLimLdHiThd_C = 30U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOfTmpLimLdLoThd_C = 10U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOffVlvPosnHiThd_C = 20U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOffVlvPosnLoThd_C = 5U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdKnkRblInc_M[81] = { 5U, 5U, 5U,
  5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U,
  5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U,
  5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U,
  5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U, 5U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblDec_M[81] = { 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInc_M[81] = { 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInjCutOffDec_C = 2U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInjCutOffThd1_T[9] = { 5U, 5U,
  5U, 5U, 5U, 5U, 5U, 5U, 5U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInjCutOffThd2_T[9] = { 5U, 5U,
  5U, 5U, 5U, 5U, 5U, 5U, 5U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctTDCInjCutOffDec_M[81] = { 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctTDCInjCutOffInc_M[81] = { 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctTotNbCycDecRbl_C = 5U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxBkptETB_A[16] = { 0U, 1U, 2U, 3U,
  4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxCritRblThd_C = 1U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl1_C = 3U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl2_C = 2U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl3_C = 11U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl4_C = 1U;
CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl1_T[16] = { 0U, 1U, 2U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl2_T[16] = { 0U, 2U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl3_T[16] = { 0U, 1U, 0U, 1U,
  0U, 1U, 0U, 1U, 0U, 1U, 1U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl4_T[16] = { 0U, 2U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

#define KNKMGRCORRBL_STOP_SEC_CALIB_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define KNKMGRCORRBL_START_SEC_CALIB_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

CONST(Boolean, KNKMGRCORRBL_CALIB) KnkMgt_bIdxMinPosnRblAcv_C = 0;
CONST(Boolean, KNKMGRCORRBL_CALIB) KnkMgt_bInhIrvLdLimRbl_C = 0;
CONST(Boolean, KNKMGRCORRBL_CALIB) KnkMgt_bRblETB_C = 0;

#define KNKMGRCORRBL_STOP_SEC_CALIB_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define KNKMGRCORRBL_START_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"

VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctInjCutOffRbl_prev[4];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl1_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl2_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl3_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl4_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl1_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl2_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl3_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl4_prev[9];
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctTotRbl_prev[4];
VAR(SInt16, KNKMGRCORRBL_VAR) KnkMgt_tqGlblTqRawSpThd;

#define KNKMGRCORRBL_STOP_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define KNKMGRCORRBL_START_SEC_VAR_8BIT
#include "KnkMgrCorRbl_MemMap.h"

VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl1;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl1Prev;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl2;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl2Prev;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl3;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl3Prev;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl4;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl4Prev;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctPerdRbl[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctPerdRblCyl_prev;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctPerdRbl_prev[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTDCInjCutOff[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTDCInjCutOffCyl_prev;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTDCInjCutOff_prev[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTotNbCycDecRbl[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTotNbCycDecRbl_prev[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl1;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl2;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl3;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl4;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxMinPosnRbl[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxMinPosnRbl_prev[4];
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_nbNEngZoneRbl;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_nbRLdZoneRbl;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCurCyl;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl1;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl2;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl3;
VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl4;
VAR(UInt8, KNKMGRCORRBL_VAR) Knk_rbl_index_cyl;

#define KNKMGRCORRBL_STOP_SEC_VAR_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define KNKMGRCORRBL_START_SEC_VAR_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

VAR(Boolean, KNKMGRCORRBL_VAR) Detection_cliquetis_CurCyl;
VAR(Boolean, KNKMGRCORRBL_VAR) Detection_fort_cliq_CurCyl;
VAR(Boolean, KNKMGRCORRBL_VAR) Detection_fort_cliquetis_Cfm[4];
VAR(Boolean, KNKMGRCORRBL_VAR) Detection_fort_cliquetis_bench[4];
VAR(Boolean, KNKMGRCORRBL_VAR) Detection_rbl_Cfm[4];
VAR(Boolean, KNKMGRCORRBL_VAR) Detection_rbl_CurCyl;
VAR(Boolean, KNKMGRCORRBL_VAR) Detection_rbl_bench[4];
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bAcvIrvLdLimRblReq;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bAcvTmpLdLimRblReq;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bAcvVlvPosnRblReq;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bDgoORng_RblIrvLdLim;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bDgoORng_RblTmpLdLim;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bDgoORng_RblVlvPosn;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bInjCutOffCylReq;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bInjCutOffRblCurCyl;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bKnkRblDetnCyl;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bMonRunORng_RblIrvLdLim;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bMonRunORng_RblTmpLdLim;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bMonRunORng_RblVlvPosn;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bRblAcvWin3;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bRblDetnCyl;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bRblInhWin;
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bSuperKnkDet[4];
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_prm_bInjCutOffRblCyl[4];
VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_prm_bInjCutOffRblCyl_prev[4];
VAR(Boolean, KNKMGRCORRBL_VAR) KnkRbl_bNEngHiSuperKnk;

#define KNKMGRCORRBL_STOP_SEC_VAR_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
