/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pCylM                                                   */
/* !Description     : CYLINDER PRESSURE ESTIMATOR                             */
/*                                                                            */
/* !Module          : pCylM                                                   */
/*                                                                            */
/* !File            : pCylM_Def.c                                             */
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
/*   Code generated on: Tue Dec 06 14:44:34 2011                              */
/*   Model name       : pCylM_AUTOCODE.mdl                                    */
/*   Model version    : 1.181                                                 */
/*   Root subsystem   : /pCylM                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PCYLM/pCylM_Def.c_v       $*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   08 Dec 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "pCylM.h"
#include "pCylM_private.h"

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
#define PCYLM_START_SEC_CALIB_16BIT
#include "pCylM_MemMap.h"

CONST(UInt16, PCYLM_CALIB) CylM_agInjPha_A[16] = { 43U, 213U, 384U, 555U, 725U,
  896U, 1067U, 1237U, 1408U, 1579U, 1749U, 1835U, 1920U, 2005U, 2069U, 2133U } ;

CONST(SInt16, PCYLM_CALIB) CylM_agOfsConvVlvRef_C = 3840;
CONST(UInt16, PCYLM_CALIB) CylM_facCorPresCylNEng_T[16] = { 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 65535U, 32768U, 32768U } ;

CONST(UInt16, PCYLM_CALIB) CylM_nEng_A[16] = { 500U, 700U, 850U, 1000U, 1250U,
  1500U, 1750U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 6000U, 6500U } ;

CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjH1ETB_C = 128U;
CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjH2ETB_C = 128U;
CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjS1ETB_C = 128U;
CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjS2ETB_C = 128U;
CONST(UInt16, PCYLM_CALIB) CylM_vCylInjPha_T[16] = { 447U, 753U, 1324U, 2256U,
  3482U, 4893U, 6321U, 7364U, 8680U, 9461U, 9979U, 10174U, 10372U, 10491U,
  10505U, 10527U } ;

#define PCYLM_STOP_SEC_CALIB_16BIT
#include "pCylM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define PCYLM_START_SEC_CALIB_8BIT
#include "pCylM_MemMap.h"

CONST(SInt8, PCYLM_CALIB) CylM_facConvVlvRef_C = -1;

#define PCYLM_STOP_SEC_CALIB_8BIT
#include "pCylM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define PCYLM_START_SEC_CALIB_BOOLEAN
#include "pCylM_MemMap.h"

CONST(Boolean, PCYLM_CALIB) CylM_bAcvETBCylPresEstim1_C = 0;
CONST(Boolean, PCYLM_CALIB) CylM_bAcvETBCylPresEstim2_C = 0;

#define PCYLM_STOP_SEC_CALIB_BOOLEAN
#include "pCylM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define PCYLM_START_SEC_VAR_32BIT
#include "pCylM_MemMap.h"

VAR(Float, PCYLM_VAR) CylM_agBegInjH1ReqRef;
VAR(Float, PCYLM_VAR) CylM_agBegInjH2ReqRef;
VAR(Float, PCYLM_VAR) CylM_agBegInjS1ReqRef;
VAR(Float, PCYLM_VAR) CylM_agBegInjS2ReqRef;
VAR(Float, PCYLM_VAR) CylM_agCkClsInVlvEstimRef1;
VAR(Float, PCYLM_VAR) CylM_agEndInjH1ReqRef;
VAR(Float, PCYLM_VAR) CylM_agEndInjH2ReqRef;
VAR(Float, PCYLM_VAR) CylM_agEndInjS1ReqRef;
VAR(Float, PCYLM_VAR) CylM_agEndInjS2ReqRef;
VAR(Float, PCYLM_VAR) CylM_pDsThrPredRefCmpr;
VAR(Float, PCYLM_VAR) CylM_pDsThrPredRefIn;

#define PCYLM_STOP_SEC_VAR_32BIT
#include "pCylM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define PCYLM_START_SEC_VAR_16BIT
#include "pCylM_MemMap.h"

VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjH1;
VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjH2;
VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjS1;
VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjS2;
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimH1CylPrev[6];
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimH2CylPrev[6];
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjH1Cyl[6];
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjH2Cyl[6];
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjS1Cyl[6];
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjS2Cyl[6];
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimS1CylPrev[6];
VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimS2CylPrev[6];

#define PCYLM_STOP_SEC_VAR_16BIT
#include "pCylM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
