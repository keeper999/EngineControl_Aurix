/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSpMgt                                                */
/* !Description     : INJECTION PARAMETERS MANAGER                            */
/*                                                                            */
/* !Module          : InjSpMgt                                                */
/*                                                                            */
/* !File            : InjSpMgt_Def.c                                          */
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
/*   Code generated on: Thu Mar 07 15:35:56 2013                              */
/*   Model name       : InjSpMgt_AUTOCODE.mdl                                 */
/*   Model version    : 1.1004                                                */
/*   Root subsystem   : /InjSpMgt                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjSpMgt/5-SOFT-LIV/InjSpMgt$*/
/* $Revision::   1.12                                                        $*/
/* $Author::   adelvare                               $$Date::   11 Mar 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjSpMgt.h"
#include "InjSpMgt_private.h"

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
#define INJSPMGT_START_SEC_CALIB_16BIT
#include "InjSpMgt_MemMap.h"

CONST(UInt16, INJSPMGT_CALIB) Eng_AgCkOffFuInjStrt_T[9] = { 107U, 107U, 107U,
  107U, 107U, 107U, 107U, 107U, 107U } ;

CONST(UInt16, INJSPMGT_CALIB) Eng_tiAgCkInjPhd_M[81] = { 960U, 960U, 960U,
  960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U,
  960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U,
  960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U,
  960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U,
  960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U,
  960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U, 960U }
;

CONST(UInt16, INJSPMGT_CALIB) InjSys_DifInjr_A[9] = { 0U, 8192U, 16384U,
  24576U, 32768U, 40960U, 49152U, 57344U, 65535U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjH1SpcInjMod_M[256] = { 2987U,
  2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 3200U, 3200U,
  3200U, 3200U, 3200U, 3200U, 2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 2987U,
  2987U, 2987U, 2987U, 3200U, 3200U, 3200U, 3200U, 3200U, 3200U, 2987U, 2987U,
  2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 2987U, 3200U, 3200U, 3200U,
  3200U, 3200U, 3200U, 3093U, 3093U, 3093U, 3093U, 3093U, 3093U, 3093U, 3093U,
  3093U, 3093U, 3307U, 3307U, 3307U, 3307U, 3307U, 3307U, 3093U, 3093U, 3093U,
  3093U, 3093U, 3093U, 3093U, 3093U, 3093U, 3093U, 3307U, 3307U, 3307U, 3307U,
  3307U, 3307U, 3200U, 3200U, 3200U, 3200U, 3200U, 3200U, 3200U, 3200U, 3200U,
  3200U, 3413U, 3413U, 3413U, 3413U, 3413U, 3413U, 3200U, 3200U, 3200U, 3200U,
  3200U, 3200U, 3200U, 3200U, 3200U, 3200U, 3413U, 3413U, 3413U, 3413U, 3413U,
  3413U, 3307U, 3307U, 3307U, 3307U, 3307U, 3307U, 3307U, 3307U, 3307U, 3307U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3413U, 3413U, 3413U, 3413U, 3413U,
  3413U, 3413U, 3413U, 3413U, 3413U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3413U, 3413U, 3413U, 3413U, 3413U, 3413U, 3413U, 3413U, 3413U, 3413U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U, 3520U,
  3520U, 3520U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjH2HiThd_T[16] = { 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjH2LoThd_T[16] = { 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjSpcModLP_C = 4053U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agCkClsInVlvEstimRef1_A[16] = { 0U, 1U,
  2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agEndInjSpcModMaxLP_M[256] = { 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2453U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U,
  2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U,
  2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U,
  2347U, 2347U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U,
  2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U,
  2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U,
  2240U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U,
  2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH1SpHiThd_C = 4053U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH1SpLoThd_C = 3733U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH2SpMax_C = 4000U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH2SpMin_C = 373U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH2SpcInjMod_C = 480U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS1SpMax_C = 1920U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS1SpcInjMod_C = 469U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpMax_C = 1707U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpMinLP_T[16] = { 373U, 373U, 373U,
  373U, 373U, 373U, 373U, 373U, 373U, 373U, 373U, 373U, 373U, 373U, 373U, 373U }
;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpMin_C = 373U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpcInjMod_C = 459U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_agOfsPhaIg_T[16] = { 16U, 22U, 27U, 32U,
  40U, 48U, 56U, 64U, 80U, 96U, 112U, 128U, 144U, 160U, 192U, 208U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_agOfsPhaInj_T[16] = { 16U, 22U, 27U, 32U,
  40U, 48U, 56U, 64U, 80U, 96U, 112U, 128U, 144U, 160U, 192U, 208U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_facConvTiToagWdStall_C = 1500U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_mAirCrkSpRef_C = 839U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_mAirInjSpMgt_A[16] = { 0U, 419U, 839U,
  1258U, 1678U, 2097U, 2517U, 2936U, 3356U, 3775U, 4195U, 4614U, 5033U, 5453U,
  5872U, 6292U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_nEng_A[16] = { 0U, 400U, 800U, 1200U,
  1600U, 2000U, 2400U, 2800U, 3200U, 3600U, 4000U, 4400U, 4800U, 5200U, 5600U,
  6000U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_nEng_AgCkInjPhd_A[9] = { 500U, 850U,
  1000U, 1500U, 2000U, 3000U, 4000U, 5000U, 6500U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuGrdNeg_C = 2560U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuGrdPos_C = 2560U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuRailIni_T[9] = { 0U, 1280U, 2560U,
  3840U, 5120U, 6400U, 7680U, 8960U, 10240U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuRailMes_A[16] = { 1280U, 2560U, 3840U,
  5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U, 16640U,
  17920U, 19200U, 20480U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuRailMin_C = 2560U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuReqMaxDft_C = 25600U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuReqMax_C = 25600U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuReqMin_C = 2560U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_rMFuReqLPFu_C = 32768U;
CONST(UInt16, INJSPMGT_CALIB) InjSys_tiInjMinHys_T[16] = { 16U, 16U, 16U, 16U,
  16U, 16U, 16U, 16U, 16U, 31U, 31U, 31U, 31U, 31U, 31U, 31U } ;

CONST(UInt16, INJSPMGT_CALIB) InjSys_tiInjMinLoThd_T[16] = { 156U, 156U, 156U,
  156U, 156U, 156U, 156U, 156U, 156U, 187U, 187U, 187U, 187U, 187U, 187U, 187U }
;

#define INJSPMGT_STOP_SEC_CALIB_16BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define INJSPMGT_START_SEC_CALIB_8BIT
#include "InjSpMgt_MemMap.h"

CONST(UInt8, INJSPMGT_CALIB) INJSPMGT_u8Inhib = 0U;
CONST(UInt8, INJSPMGT_CALIB) InjSys_rFilGainPFuReq_T[16] = { 26U, 51U, 77U,
  102U, 115U, 128U, 141U, 154U, 166U, 179U, 192U, 205U, 218U, 230U, 243U, 255U }
;

CONST(UInt8, INJSPMGT_CALIB) Sync_agEs_A[9] = { 0U, 30U, 60U, 90U, 120U, 150U,
  180U, 210U, 240U } ;

#define INJSPMGT_STOP_SEC_CALIB_8BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define INJSPMGT_START_SEC_CALIB_BOOLEAN
#include "InjSpMgt_MemMap.h"

CONST(Boolean, INJSPMGT_CALIB) InjSys_bAcvTiInjETB_C = 1;
CONST(Boolean, INJSPMGT_CALIB) InjSys_bEnaPresFuGrdLim_C = 0;
CONST(Boolean, INJSPMGT_CALIB) InjSys_bInhCorInjPhaSIgSp_C = 0;
CONST(Boolean, INJSPMGT_CALIB) InjSys_bInhrMFuReqLPFu_C = 1;

#define INJSPMGT_STOP_SEC_CALIB_BOOLEAN
#include "InjSpMgt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define INJSPMGT_START_SEC_VAR_32BIT
#include "InjSpMgt_MemMap.h"

VAR(Float32, INJSPMGT_VAR) Eng_AgCkOffFuInjStrt;
VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH1Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH2Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjS1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjS1Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjS2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjH1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjH2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjS1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjS2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjS2Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_agFrstInjSTTReq;
VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjH1;
VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjH2;
VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjS1;
VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjS2;
VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjH1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjH2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjS1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjS2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjH1;
VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjH2;
VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjS1;
VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjS2;
VAR(Float32, INJSPMGT_VAR) InjSys_mFuSpMgt;
VAR(Float32, INJSPMGT_VAR) InjSys_pFuReqRaw;
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjH1SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjH2SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjS1SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjS2SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjH1SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjH2SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjS1SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjS2SpSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agFrstInjSTTSp[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agMaxFrstInjSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_prm_agOfsFrstInjSTT[2];
VAR(Float32, INJSPMGT_VAR) InjSys_rFilGainPFuReq;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjH1Resi;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjH1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjH1Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjH2Resi;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjH2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjH2Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjResi;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjS1Resi;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjS1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjS1Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjS2Resi;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjS2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_rInjS2Tmp;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH1TmpSat;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH2TmpSat;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjMinHiThd;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjMinLoThd;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjH1;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjH2;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjS1;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjS2;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS1Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS1TmpSat;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS2Sp;
VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS2TmpSat;

#define INJSPMGT_STOP_SEC_VAR_32BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define INJSPMGT_START_SEC_VAR_16BIT
#include "InjSpMgt_MemMap.h"

VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjH1Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjH2Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjS1Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjS2Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjH1Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjH2Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjS1Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjS2Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_mAirSpMgt;
VAR(UInt16, INJSPMGT_VAR) InjSys_pFuReq;
VAR(UInt16, INJSPMGT_VAR) InjSys_pFuReqPrev;
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH1CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH1ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH2CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH2ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS1CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS1ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS2CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS2ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH1CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH1ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH2CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH2ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS1CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS1ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS2CylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS2ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH1ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH1ReqCylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH2ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH2ReqCylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS1ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS1ReqCylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS2ReqCyl[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS2ReqCylPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rMFuReqLPFu[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rMFuReqLPFuPrev[6];
VAR(UInt16, INJSPMGT_VAR) InjSys_rInjH1Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_rInjH2Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_rInjS1Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_rInjS2Req;
VAR(UInt16, INJSPMGT_VAR) InjSys_rMFuReqLPFu;

#define INJSPMGT_STOP_SEC_VAR_16BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define INJSPMGT_START_SEC_VAR_8BIT
#include "InjSpMgt_MemMap.h"

VAR(UInt8, INJSPMGT_VAR) InjSys_noCmprCylStopSTT;
VAR(UInt8, INJSPMGT_VAR) InjSys_noCylInjSp;
VAR(UInt8, INJSPMGT_VAR) InjSys_noInCylStopSTT;

#define INJSPMGT_STOP_SEC_VAR_8BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define INJSPMGT_START_SEC_VAR_BOOLEAN
#include "InjSpMgt_MemMap.h"

VAR(Boolean, INJSPMGT_VAR) InjSys_bAcvSpcInjModOvlp;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetBegInjMaxThd;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetCylInjSp;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetInjOvlp;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjH1Max;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjH2Max;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjS1Max;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjS2Max;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjH1Min;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjH2Min;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjS1Min;
VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjS2Min;
VAR(Boolean, INJSPMGT_VAR) InjSys_bHPFuRail;
VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjH1;
VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjH2;
VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjS1;
VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjS2;
VAR(Boolean, INJSPMGT_VAR) InjSys_prm_bInhFrstInjSTT[2];
VAR(Boolean, INJSPMGT_VAR) InjSys_prm_bInhFrstInjSTTPrev[2];

#define INJSPMGT_STOP_SEC_VAR_BOOLEAN
#include "InjSpMgt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
