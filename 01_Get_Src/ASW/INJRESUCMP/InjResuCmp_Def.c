/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjResuCmp                                              */
/* !Description     : InjResuCmp : INJECTION COMPENSATION AFTER CUT OFF       */
/*                                                                            */
/* !Module          : InjResuCmp                                              */
/*                                                                            */
/* !File            : InjResuCmp_Def.c                                        */
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
/*   Code generated on: Mon Dec 02 18:06:23 2013                              */
/*   Model name       : InjResuCmp_AUTOCODE.mdl                               */
/*   Model version    : 1.293                                                 */
/*   Root subsystem   : /InjResuCmp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJRESUCMP/InjResuCmp_Def.$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Dec 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjResuCmp.h"
#include "InjResuCmp_private.h"

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
#define INJRESUCMP_START_SEC_CALIB_16BIT
#include "InjResuCmp_MemMap.h"

CONST(UInt16, INJRESUCMP_CALIB) InjSys_ctAntCmpStop_A[8] = { 0U, 2U, 5U, 10U,
  14U, 17U, 19U, 20U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_ctAntCmpStop_T[8] = { 20U, 19U, 17U,
  14U, 10U, 5U, 2U, 0U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_ct_facInjResuIdlCmp_A[8] = { 0U, 1U, 2U,
  3U, 5U, 10U, 15U, 20U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_ct_facInjResuIntrSTT_A[8] = { 1U, 2U,
  3U, 4U, 5U, 6U, 7U, 8U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_ct_facInjResuTqCmp_A[8] = { 0U, 1U, 2U,
  3U, 5U, 10U, 15U, 20U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuCorIntrSTT_M[64] = { 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuCor_M[64] = { 5243U, 5243U,
  4806U, 4806U, 4588U, 4588U, 4369U, 4369U, 5243U, 5243U, 4806U, 4806U, 4588U,
  4588U, 4369U, 4369U, 4806U, 4806U, 4806U, 4806U, 4588U, 4588U, 4369U, 4369U,
  4806U, 4806U, 4806U, 4806U, 4588U, 4588U, 4369U, 4369U, 4588U, 4588U, 4588U,
  4588U, 4588U, 4588U, 4369U, 4369U, 4588U, 4588U, 4588U, 4588U, 4588U, 4588U,
  4369U, 4369U, 4369U, 4369U, 4369U, 4369U, 4369U, 4369U, 4369U, 4369U, 4369U,
  4369U, 4369U, 4369U, 4369U, 4369U, 4369U, 4369U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuIdlCmp_T[8] = { 6554U, 6554U,
  6497U, 6117U, 5680U, 4806U, 4369U, 4369U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuIntrSTT_T[8] = { 4369U, 8738U,
  13107U, 17476U, 21845U, 26214U, 30583U, 34953U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuTCorIntrSTT_T[8] = { 4369U,
  8738U, 13107U, 17476U, 21845U, 26214U, 30583U, 34953U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuTCor_T[8] = { 6554U, 6554U,
  6497U, 6117U, 5680U, 4806U, 4369U, 4369U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuTqCmp_T[8] = { 6554U, 6554U,
  6497U, 6117U, 5680U, 4806U, 4369U, 4369U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_mAir_facInjResuCorY_A[8] = { 8389U,
  12584U, 16778U, 20973U, 25167U, 33557U, 41946U, 50335U } ;

CONST(UInt16, INJRESUCMP_CALIB) InjSys_nEng_facInjResuCorX_A[8] = { 800U,
  1000U, 1500U, 2000U, 2500U, 3000U, 4000U, 5000U } ;

#define INJRESUCMP_STOP_SEC_CALIB_16BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define INJRESUCMP_START_SEC_CALIB_8BIT
#include "InjResuCmp_MemMap.h"

CONST(UInt8, INJRESUCMP_CALIB) INJRESUCMP_u8Inhib = 0U;
CONST(UInt8, INJRESUCMP_CALIB) InjSys_tCo_facInjResuTCor_A[8] = { 10U, 20U,
  30U, 40U, 50U, 60U, 80U, 120U } ;

#define INJRESUCMP_STOP_SEC_CALIB_8BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define INJRESUCMP_START_SEC_CALIB_BOOLEAN
#include "InjResuCmp_MemMap.h"

CONST(Boolean, INJRESUCMP_CALIB) InjSys_bAcvInjResuCmp_C = 1;

#define INJRESUCMP_STOP_SEC_CALIB_BOOLEAN
#include "InjResuCmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define INJRESUCMP_START_SEC_VAR_32BIT
#include "InjResuCmp_MemMap.h"

VAR(Float32, INJRESUCMP_VAR) InjSys_facInjResuTCor_MP;
VAR(Float32, INJRESUCMP_VAR) InjSys_facTCorIntrSTT_MP;
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facCorIntrSTT_MP[6];
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facGslResuCyl[6];
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuCor_MP[6];
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuIdlCmp_MP[6];
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuIntrSTT_MP[6];
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuTqCmp_MP[6];
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facResuIdl_MP[6];
VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facResuTq_MP[6];

#define INJRESUCMP_STOP_SEC_VAR_32BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define INJRESUCMP_START_SEC_VAR_16BIT
#include "InjResuCmp_MemMap.h"

VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_ctAntCmpStopCyl[6];
VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_ctInjResuCyl[6];
VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_ctNbCmbCutOffCyl[6];
VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_facInjResuCyl[6];

#define INJRESUCMP_STOP_SEC_VAR_16BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define INJRESUCMP_START_SEC_VAR_BOOLEAN
#include "InjResuCmp_MemMap.h"

VAR(Boolean, INJRESUCMP_VAR) InjSys_bDetStall;
VAR(Boolean, INJRESUCMP_VAR) InjSys_prm_bDetStall[6];
VAR(Boolean, INJRESUCMP_VAR) InjSys_prm_bInjResuCyl[6];

#define INJRESUCMP_STOP_SEC_VAR_BOOLEAN
#include "InjResuCmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
