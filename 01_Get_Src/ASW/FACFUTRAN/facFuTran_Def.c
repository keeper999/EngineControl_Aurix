/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : facFuTran                                               */
/* !Description     : FACFUTRAN : INJECTED FUEL MASS CORRECTION FACTOR DURING LOAD TRANSIENT*/
/*                                                                            */
/* !Module          : facFuTran                                               */
/*                                                                            */
/* !File            : facFuTran_Def.c                                         */
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
/*   Code generated on: Mon May 19 23:02:25 2014                              */
/*   Model name       : facFuTran_AUTOCODE.mdl                                */
/*   Model version    : 1.640                                                 */
/*   Root subsystem   : /facFuTran                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/FACFUTRAN/facFuTran_Def.c_$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   etsasson                               $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "facFuTran.h"
#include "facFuTran_private.h"

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
#define FACFUTRAN_START_SEC_CALIB_16BIT
#include "facFuTran_MemMap.h"

CONST(UInt16, FACFUTRAN_CALIB) InjSys_ctNbCmbAst_A[9] = { 0U, 4U, 24U, 96U,
  256U, 384U, 580U, 896U, 1280U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facCorAst_M[81] = { 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facCorExtCd_M[81] = { 11059U, 9708U,
  8479U, 7373U, 6390U, 5734U, 4997U, 4506U, 4096U, 8602U, 8110U, 7373U, 6554U,
  5775U, 5243U, 4710U, 4301U, 4096U, 6554U, 6554U, 6267U, 5734U, 5202U, 4792U,
  4383U, 4096U, 4096U, 5120U, 5120U, 5120U, 4915U, 4669U, 4424U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U, 4096U,
  4096U, 4096U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal1_M[81] = { 1147U, 1147U,
  1147U, 1147U, 1106U, 1024U, 942U, 901U, 860U, 1147U, 1147U, 1147U, 1024U, 901U,
  819U, 737U, 737U, 737U, 819U, 819U, 819U, 819U, 819U, 778U, 737U, 717U, 696U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal2_M[81] = { 1147U, 1147U,
  1147U, 1147U, 1106U, 1024U, 942U, 901U, 860U, 1147U, 1147U, 1147U, 1024U, 901U,
  819U, 737U, 737U, 737U, 819U, 819U, 819U, 819U, 819U, 778U, 737U, 717U, 696U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal3_M[81] = { 1147U, 1147U,
  1147U, 1147U, 1106U, 1024U, 942U, 901U, 860U, 1147U, 1147U, 1147U, 1024U, 901U,
  819U, 737U, 737U, 737U, 819U, 819U, 819U, 819U, 819U, 778U, 737U, 717U, 696U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal4_M[81] = { 1147U, 1147U,
  1147U, 1147U, 1106U, 1024U, 942U, 901U, 860U, 1147U, 1147U, 1147U, 1024U, 901U,
  819U, 737U, 737U, 737U, 819U, 819U, 819U, 819U, 819U, 778U, 737U, 717U, 696U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal5_M[81] = { 1147U, 1147U,
  1147U, 1147U, 1106U, 1024U, 942U, 901U, 860U, 1147U, 1147U, 1147U, 1024U, 901U,
  819U, 737U, 737U, 737U, 819U, 819U, 819U, 819U, 819U, 778U, 737U, 717U, 696U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal6_M[81] = { 1147U, 1147U,
  1147U, 1147U, 1106U, 1024U, 942U, 901U, 860U, 1147U, 1147U, 1147U, 1024U, 901U,
  819U, 737U, 737U, 737U, 819U, 819U, 819U, 819U, 819U, 778U, 737U, 717U, 696U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U, 614U,
  614U, 614U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal1_M[81] = { 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal2_M[81] = { 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal3_M[81] = { 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal4_M[81] = { 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal5_M[81] = { 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal6_M[81] = { 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U, 819U,
  819U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_mAirInjSpTranY_A[9] = { 419U, 839U,
  1258U, 1678U, 2517U, 3356U, 4195U, 5033U, 5872U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_mAirPredInjSp_A[9] = { 419U, 839U, 1258U,
  1678U, 2517U, 3356U, 4195U, 5033U, 5872U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_nEngInjSpTranX_A[9] = { 750U, 1000U,
  1500U, 2000U, 2500U, 3000U, 3500U, 4000U, 6000U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_nEngInjSp_A[9] = { 0U, 500U, 1000U,
  2000U, 3000U, 4000U, 5000U, 6000U, 7000U } ;

CONST(UInt16, FACFUTRAN_CALIB) InjSys_nMaxAcvWf_C = 6500U;

#define FACFUTRAN_STOP_SEC_CALIB_16BIT
#include "facFuTran_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define FACFUTRAN_START_SEC_CALIB_8BIT
#include "facFuTran_MemMap.h"

CONST(UInt8, FACFUTRAN_CALIB) FACFUTRAN_u8Inhib = 0U;
CONST(UInt8, FACFUTRAN_CALIB) InjSys_facDetAccTranHiThr_M[81] = { 17U, 17U,
  17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U, 17U,
  15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 13U, 13U, 13U, 13U, 13U, 13U, 13U,
  13U, 13U, 12U, 12U, 12U, 12U, 12U, 12U, 12U, 12U, 12U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_facDetDecTranLoThr_M[81] = { 19U, 19U,
  19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U, 19U,
  16U, 16U, 16U, 16U, 16U, 16U, 16U, 16U, 16U, 14U, 14U, 14U, 14U, 14U, 14U, 14U,
  14U, 14U, 12U, 12U, 12U, 12U, 12U, 12U, 12U, 12U, 12U, 11U, 11U, 11U, 11U, 11U,
  11U, 11U, 11U, 11U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_idxModInjTranSatMax_C = 6U;
CONST(UInt8, FACFUTRAN_CALIB) InjSys_idxModInjTranSatMin_C = 1U;
CONST(UInt8, FACFUTRAN_CALIB) InjSys_noClcnAftrReInjThr_C = 4U;
CONST(UInt8, FACFUTRAN_CALIB) InjSys_noCmbRmpTranAcc_M[81] = { 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 2U,
  2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U, 2U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_noCmbRmpTranDec_M[81] = { 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U,
  3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetAccTranHiThr_T[9] = { 42U, 39U, 36U,
  34U, 33U, 32U, 30U, 29U, 29U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetAccTranLoThr_T[9] = { 5U, 5U, 5U, 5U,
  5U, 5U, 5U, 5U, 5U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetDecTranHiThr_T[9] = { 251U, 251U,
  251U, 251U, 251U, 251U, 251U, 251U, 251U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetDecTranLoThr_T[9] = { 206U, 210U,
  214U, 218U, 220U, 222U, 225U, 226U, 227U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_rGainFilAccCmp_M[81] = { 13U, 13U, 13U,
  13U, 13U, 13U, 13U, 13U, 13U, 20U, 20U, 20U, 20U, 20U, 20U, 20U, 20U, 20U, 28U,
  28U, 28U, 28U, 28U, 28U, 28U, 28U, 28U, 36U, 36U, 36U, 36U, 36U, 36U, 36U, 36U,
  36U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U,
  38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U,
  38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 38U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_rGainFilDecCmp_M[81] = { 13U, 13U, 13U,
  13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U,
  13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U,
  13U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 18U, 18U, 18U, 18U, 18U, 18U,
  18U, 18U, 18U, 23U, 23U, 23U, 23U, 23U, 23U, 23U, 23U, 23U, 26U, 26U, 26U, 26U,
  26U, 26U, 26U, 26U, 26U, 26U, 26U, 26U, 26U, 26U, 26U, 26U, 26U, 26U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_tAirExtMes_A[9] = { 20U, 30U, 40U, 50U,
  60U, 70U, 80U, 90U, 100U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_tCoMes_A[9] = { 10U, 20U, 30U, 40U, 50U,
  60U, 80U, 100U, 120U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_tCoStrtMes_A[9] = { 10U, 20U, 30U, 40U,
  50U, 60U, 80U, 100U, 120U } ;

CONST(UInt8, FACFUTRAN_CALIB) InjSys_tiDlyAcvWfSTT_C = 50U;
CONST(UInt8, FACFUTRAN_CALIB) InjSys_tiDlyAcvWf_C = 50U;

#define FACFUTRAN_STOP_SEC_CALIB_8BIT
#include "facFuTran_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define FACFUTRAN_START_SEC_CALIB_BOOLEAN
#include "facFuTran_MemMap.h"

CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvFISAWupAdp_C = 1;
CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvWfModTran_C = 1;
CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvWfResuTran_C = 1;
CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvfacFuTranClcn_C = 1;
CONST(Boolean, FACFUTRAN_CALIB) InjSys_bInhReInjCond_C = 1;
CONST(Boolean, FACFUTRAN_CALIB) InjSys_bSelVarInjSys_C = 1;

#define FACFUTRAN_STOP_SEC_CALIB_BOOLEAN
#include "facFuTran_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define FACFUTRAN_START_SEC_VAR_32BIT
#include "facFuTran_MemMap.h"

VAR(Float32, FACFUTRAN_VAR) InjSys_facBasModCurInjTran;
VAR(Float32, FACFUTRAN_VAR) InjSys_facBasModTarInjTran;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal1;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal2;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal3;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal4;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal5;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal6;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpIni;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpPrevRmp;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpRawRmp;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpRmp;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal1;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal2;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal3;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal4;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal5;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal6;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranModInjTran;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSp;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas1ModCur;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas1ModTar;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas2ModCur;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas2ModTar;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpModCur_MP;
VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpModTar_MP;
VAR(Float32, FACFUTRAN_VAR) InjSys_prm_facTranAccSpCal[6];
VAR(Float32, FACFUTRAN_VAR) InjSys_prm_facTranDecSpCal[6];
VAR(Float32, FACFUTRAN_VAR) InjSys_prm_facTranSpCal[6];
VAR(Float32, FACFUTRAN_VAR) InjSys_rMAirPredMAirCor;

#define FACFUTRAN_STOP_SEC_VAR_32BIT
#include "facFuTran_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define FACFUTRAN_START_SEC_VAR_16BIT
#include "facFuTran_MemMap.h"

VAR(UInt16, FACFUTRAN_VAR) InjSys_facTranCmp;
VAR(UInt16, FACFUTRAN_VAR) InjSys_prm_facTranCmpCylPrev[6];
VAR(UInt16, FACFUTRAN_VAR) InjSys_prm_facTranCmpCylRaw[6];

#define FACFUTRAN_STOP_SEC_VAR_16BIT
#include "facFuTran_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define FACFUTRAN_START_SEC_VAR_8BIT
#include "facFuTran_MemMap.h"

VAR(UInt8, FACFUTRAN_VAR) InjSys_ctNbCmbTran;
VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas1ModCurInjTran;
VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas1ModTarInjTran;
VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas2ModCurInjTran;
VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas2ModTarInjTran;
VAR(UInt8, FACFUTRAN_VAR) InjSys_noClcnAfterReInj;
VAR(UInt8, FACFUTRAN_VAR) InjSys_noCmbRmpTran;

#define FACFUTRAN_STOP_SEC_VAR_8BIT
#include "facFuTran_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define FACFUTRAN_START_SEC_VAR_BOOLEAN
#include "facFuTran_MemMap.h"

VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal1;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal2;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal3;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal4;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal5;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal6;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvWfCmp;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvWfCmpSet_MP;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetAccTran;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetAccTranTmp;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetAcvWfCmp;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetDecTran;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetDecTranTmp;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetRmpTran;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bRstDetAccTran;
VAR(Boolean, FACFUTRAN_VAR) InjSys_bRstDetDecTran;
VAR(Boolean, FACFUTRAN_VAR) InjSys_prm_bAcvInjTranSpCal[6];

#define FACFUTRAN_STOP_SEC_VAR_BOOLEAN
#include "facFuTran_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
