/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkLdLim                                                */
/* !Description     : LOAD LIMITATION IN KNOCK SITUATION                      */
/*                                                                            */
/* !Module          : KnkLdLim                                                */
/*                                                                            */
/* !File            : KnkLdLim_Def.c                                          */
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
/*   Code generated on: Thu Mar 28 15:46:24 2013                              */
/*   Model name       : KnkLdLim_AUTOCODE.mdl                                 */
/*   Model version    : 1.206                                                 */
/*   Root subsystem   : /KnkLdLim                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKLDLIM/KnkLdLim$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   etsasson                               $$Date::   29 Mar 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "KnkLdLim.h"
#include "KnkLdLim_private.h"

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
#define KNKLDLIM_START_SEC_CALIB_16BIT
#include "KnkLdLim_MemMap.h"

CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctKnkDetHiThd_C = 25U;
CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctKnkDetLoThd_C = 6U;
CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetDec_C = 1U;
CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetHiThd_C = 15U;
CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetLoThd_C = 4U;
CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_nEng_ldLim_A[8] = { 0U, 1000U, 2000U,
  3000U, 4000U, 5000U, 6000U, 7000U } ;

CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_rAirLd_ldLim_A[8] = { 2185U, 4369U, 6554U,
  8738U, 10923U, 13107U, 15292U, 17476U } ;

#define KNKLDLIM_STOP_SEC_CALIB_16BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define KNKLDLIM_START_SEC_CALIB_8BIT
#include "KnkLdLim_MemMap.h"

CONST(UInt8, KNKLDLIM_CALIB) KNKLDLIM_u8Inhib = 15U;
CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_agIgHiThd_KnkLdLim_M[64] = { 136U, 136U,
  136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U,
  136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U, 136U, 133U, 133U, 133U, 133U,
  133U, 133U, 133U, 133U, 131U, 131U, 131U, 131U, 131U, 131U, 131U, 131U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 125U, 125U, 125U, 125U, 125U, 125U,
  125U, 125U, 123U, 123U, 123U, 123U, 123U, 123U, 123U, 123U } ;

CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_agIgLoThd_KnkLdLim_M[64] = { 120U, 120U,
  120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U,
  120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 117U, 117U, 117U, 117U,
  117U, 117U, 117U, 117U, 115U, 115U, 115U, 115U, 115U, 115U, 115U, 115U, 112U,
  112U, 112U, 112U, 112U, 112U, 112U, 112U, 109U, 109U, 109U, 109U, 109U, 109U,
  109U, 109U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U } ;

CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_ctKnkDetDec_C = 1U;
CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_ctKnkDetInc_C = 5U;
CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetInc_C = 5U;
CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_tiFilAgIgKnkCor_C = 20U;

#define KNKLDLIM_STOP_SEC_CALIB_8BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define KNKLDLIM_START_SEC_CALIB_BOOLEAN
#include "KnkLdLim_MemMap.h"

CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bAcvLdLimAdvCor_C = 1;
CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bAcvLdLimKnkDet_C = 1;
CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bAcvLdLimSuperKnkDet_C = 0;
CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bLdLimAdvCor_knk_C = 1;
CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bLdLimAdvCor_superKnk_C = 0;
CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bLdLimStra_C = 0;
CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bStraLdLimKnkDet_C = 1;

#define KNKLDLIM_STOP_SEC_CALIB_BOOLEAN
#include "KnkLdLim_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define KNKLDLIM_START_SEC_VAR_32BIT
#include "KnkLdLim_MemMap.h"

VAR(Float32, KNKLDLIM_VAR) KnkMgt_agIgKnkCorFil;

#define KNKLDLIM_STOP_SEC_VAR_32BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define KNKLDLIM_START_SEC_VAR_16BIT
#include "KnkLdLim_MemMap.h"

VAR(UInt16, KNKLDLIM_VAR) KnkMgt_ctKnkDetLdLim;
VAR(UInt16, KNKLDLIM_VAR) KnkMgt_ctSuperKnkDetLdLim;

#define KNKLDLIM_STOP_SEC_VAR_16BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define KNKLDLIM_START_SEC_VAR_BOOLEAN
#include "KnkLdLim_MemMap.h"

VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimKnkRaw;
VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimKnkReq;
VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimSuperKnkRaw;
VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimSuperKnkReq;
VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bLdLimKnkAdvCor;

#define KNKLDLIM_STOP_SEC_VAR_BOOLEAN
#include "KnkLdLim_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
