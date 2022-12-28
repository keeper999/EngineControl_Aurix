/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuM                                                    */
/* !Description     : FUEL PRESSURE MODEL                                     */
/*                                                                            */
/* !Module          : pFuM                                                    */
/*                                                                            */
/* !File            : pFuM_Def.c                                              */
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
/*   Code generated on: Sun Jul 15 20:51:22 2012                              */
/*   Model name       : pFuM_AUTOCODE.mdl                                     */
/*   Model version    : 1.1269                                                */
/*   Root subsystem   : /pFuM                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/pFuM/5-SOFT-LIV/pFuM_Def.c_v$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   16 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "pFuM.h"
#include "pFuM_private.h"

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
#define PFUM_START_SEC_CALIB_16BIT
#include "pFuM_MemMap.h"

CONST(UInt16, PFUM_CALIB) FuSysM_agConvInjHRef_C = 4693U;
CONST(UInt16, PFUM_CALIB) FuSysM_agConvInjSRef_C = 2133U;
CONST(UInt16, PFUM_CALIB) FuSysM_agDlyInj_T[16] = { 0U, 6U, 13U, 19U, 26U, 32U,
  38U, 45U, 51U, 58U, 64U, 70U, 77U, 83U, 90U, 96U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_agPerInjRef_C = 2560U;
CONST(UInt16, PFUM_CALIB) FuSysM_facCnvMassFuPFu_M[144] = { 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U, 16128U,
  16128U, 16128U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_facCorMassBegPmpStk_T[9] = { 0U, 3277U, 6554U,
  9830U, 16384U, 22938U, 26214U, 29491U, 32768U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_facCorMassEndPmpStk_T[9] = { 0U, 3277U, 6554U,
  9830U, 16384U, 22938U, 26214U, 29491U, 32768U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_nEng_mOvlpPmp_A[9] = { 0U, 800U, 1600U, 2400U,
  3200U, 4000U, 4800U, 5600U, 6000U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_pFuMin_C = 640U;
CONST(UInt16, PFUM_CALIB) FuSysM_pFuRailMes_A[16] = { 0U, 20U, 40U, 50U, 60U,
  70U, 80U, 90U, 100U, 110U, 120U, 130U, 140U, 160U, 180U, 200U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_rAgInj_A[9] = { 0U, 3277U, 6554U, 9830U,
  16384U, 22938U, 26214U, 29491U, 32768U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_rAgPmp_A[9] = { 0U, 3277U, 6554U, 9830U,
  16384U, 22938U, 26214U, 29491U, 32768U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_rMassInj_T[9] = { 0U, 3277U, 6554U, 9830U,
  16384U, 22938U, 26214U, 29491U, 32768U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_rMassPFuMeanEstim_C = 16384U;
CONST(UInt16, PFUM_CALIB) FuSysM_rMassPmp_M[81] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 6554U, 6554U, 6554U, 6554U, 6554U, 6554U, 6554U, 6554U, 6554U, 10813U,
  10813U, 10813U, 10813U, 10813U, 10813U, 10813U, 10813U, 10813U, 15729U, 15729U,
  15729U, 15729U, 15729U, 15729U, 15729U, 15729U, 15729U, 23921U, 23921U, 23921U,
  23921U, 23921U, 23921U, 23921U, 23921U, 23921U, 29164U, 29164U, 29164U, 29164U,
  29164U, 29164U, 29164U, 29164U, 29164U, 30474U, 30474U, 30474U, 30474U, 30474U,
  30474U, 30474U, 30474U, 30474U, 32113U, 32113U, 32113U, 32113U, 32113U, 32113U,
  32113U, 32113U, 32113U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U } ;

CONST(UInt16, PFUM_CALIB) FuSysM_tFu_A[9] = { 10U, 20U, 30U, 40U, 60U, 80U,
  100U, 120U, 140U } ;

#define PFUM_STOP_SEC_CALIB_16BIT
#include "pFuM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define PFUM_START_SEC_CALIB_8BIT
#include "pFuM_MemMap.h"

CONST(UInt8, PFUM_CALIB) FuSysM_rFilGainPFuMdl_C = 230U;
CONST(UInt8, PFUM_CALIB) PFUM_u8Inhib = 0U;

#define PFUM_STOP_SEC_CALIB_8BIT
#include "pFuM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define PFUM_START_SEC_CALIB_BOOLEAN
#include "pFuM_MemMap.h"

CONST(Boolean, PFUM_CALIB) FuSysM_bAcvPFuMdl_C = 1;

#define PFUM_STOP_SEC_CALIB_BOOLEAN
#include "pFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define PFUM_START_SEC_VAR_32BIT
#include "pFuM_MemMap.h"

VAR(Float32, PFUM_VAR) FuSysM_agBegInjH1Ref;
VAR(Float32, PFUM_VAR) FuSysM_agBegInjH1RefNxt;
VAR(Float32, PFUM_VAR) FuSysM_agBegInjH1RefPrev;
VAR(Float32, PFUM_VAR) FuSysM_agBegInjH2Ref;
VAR(Float32, PFUM_VAR) FuSysM_agBegInjH2RefNxt;
VAR(Float32, PFUM_VAR) FuSysM_agBegInjH2RefPrev;
VAR(Float32, PFUM_VAR) FuSysM_agBegInjS1Ref;
VAR(Float32, PFUM_VAR) FuSysM_agBegInjS2Ref;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjH1Ref;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjH1RefNxt;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjH1RefPrev;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjH2Ref;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjH2RefNxt;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjH2RefPrev;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjS1Ref;
VAR(Float32, PFUM_VAR) FuSysM_agEndInjS2Ref;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH1;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH1Nxt;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH1Prev;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH2;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH2Nxt;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH2Prev;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjS1;
VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjS2;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegH1;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegH2;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegS1;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegS2;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjH1Prev;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjH2Prev;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjS1Prev;
VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjS2Prev;
VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjH1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjH2[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjS1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjS2[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjH1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjH2[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjS1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjS2[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegH1[6];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegH2[6];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegS1[4];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegS2[4];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpH1[6];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpH2[6];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpS1[4];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpS2[4];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegH1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegH2[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegS1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegS2[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpH1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpH2[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpS1[2];
VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpS2[2];

#define PFUM_STOP_SEC_VAR_32BIT
#include "pFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define PFUM_START_SEC_VAR_16BIT
#include "pFuM_MemMap.h"

VAR(UInt16, PFUM_VAR) FuSysM_facCnvMassFuPFu;
VAR(UInt16, PFUM_VAR) FuSysM_pFuEstimInjH1;
VAR(UInt16, PFUM_VAR) FuSysM_pFuEstimInjH2;
VAR(UInt16, PFUM_VAR) FuSysM_pFuEstimInjS1;
VAR(UInt16, PFUM_VAR) FuSysM_pFuEstimInjS2;
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimH1CylPrev[6];
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimH2CylPrev[6];
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimInjH1Cyl[6];
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimInjH2Cyl[6];
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimInjS1Cyl[6];
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimInjS2Cyl[6];
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimS1CylPrev[6];
VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimS2CylPrev[6];

#define PFUM_STOP_SEC_VAR_16BIT
#include "pFuM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
