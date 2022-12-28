/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvPrevKnkT                                             */
/* !Description     : AdvPrevKnkT Software Component                          */
/*                                                                            */
/* !Module          : AdvPrevKnkT                                             */
/*                                                                            */
/* !File            : AdvPrevKnkT_Def.c                                       */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
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
/*   Model name       : AdvPrevKnkT_AUTOSAR.mdl                               */
/*   Root subsystem   : /AdvPrevKnkT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M05-AdvPrevKnkT$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   11 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvPrevKnkT.h"
#include "AdvPrevKnkT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CARTO_16BIT" */
#define AdvPrevKnkT_START_SEC_CARTO_16BIT
#include "AdvPrevKnkT_MemMap.h"

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_AirLdDet_A[9] = { 750U, 1000U,
  1500U, 2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_PrevDynX_A[9] = { 750U, 1000U,
  1500U, 2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_PrevStatX_A[9] = { 750U, 1000U,
  1500U, 2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_facFilAirldDynX_A[9] = { 750U,
  1000U, 1500U, 2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_facFilDeltaAir_A[9] = { 750U,
  1000U, 1500U, 2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_noDlyCalcAirLd_A[9] = { 750U,
  1000U, 1500U, 2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_pAirExtMes_PrevStat_A[9] = { 7500U,
  8750U, 10000U, 10625U, 11250U, 11875U, 12500U, 13125U, 13750U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_pDsThr_facFilAirLdDynY_A[9] = { 7500U,
  10000U, 12500U, 13750U, 15000U, 16250U, 17500U, 18750U, 20000U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rAirLdCor_PrevDynY_A[9] = { 1638U,
  4915U, 7373U, 9830U, 11469U, 13107U, 14746U, 16384U, 18842U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rAirLdCor_PrevStatY_A[9] = { 1638U,
  4915U, 7373U, 9830U, 11469U, 13107U, 14746U, 16384U, 18842U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rDeltaAirLdDynThd_T[9] = { 655U, 655U,
  655U, 524U, 524U, 492U, 492U, 410U, 410U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rLamEngCorReq_PrevStaY_A[9] = { 4375U,
  4397U, 4420U, 4442U, 4464U, 4688U, 4911U, 5134U, 5357U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_spdVeh_PrevDynY_A[6] = { 640U, 3840U,
  7680U, 11520U, 15360U, 19200U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tAirUsInVlv_PrevDynY_A[16] = { 2560U,
  4352U, 6400U, 8320U, 10240U, 11520U, 12800U, 14080U, 15360U, 16000U, 16640U,
  17280U, 17920U, 19200U, 20480U, 21760U } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tAirUsInVlv_PrevStatY_A[9] = { 1280U,
  3840U, 6400U, 8960U, 11520U, 14080U, 16640U, 17920U, 19200U } ;

CONST(SInt16, ADVPREVKNKT_CARTO) IgSys_tCoMes_PrevStatX_A[9] = { -40, -20, 0,
  20, 40, 60, 80, 90, 100 } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tRefTAirUsInVlvEstim_M[9][9] = { { 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U },{ 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U },{ 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U },{ 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U },{ 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U },
{ 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U },{ 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U },{ 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U },{ 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U } } ;

CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tiAirLdDynDet_T[9] = { 400U, 400U, 300U,
  300U, 250U, 200U, 200U, 150U, 150U } ;

#define AdvPrevKnkT_STOP_SEC_CARTO_16BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define AdvPrevKnkT_START_SEC_CALIB_16BIT
#include "AdvPrevKnkT_MemMap.h"

CONST(UInt16, ADVPREVKNKT_CALIB) IgSys_agIgPrevDynIncOfs_C = 11U;
CONST(UInt16, ADVPREVKNKT_CALIB) IgSys_pAirExtMesDft_C = 12663U;
CONST(UInt16, ADVPREVKNKT_CALIB) IgSys_rAirLdClc_B = 0U;
CONST(SInt16, ADVPREVKNKT_CALIB) IgSys_tDifTAirUsInVlvEstim_B = 0;

#define AdvPrevKnkT_STOP_SEC_CALIB_16BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AdvPrevKnkT_START_SEC_CALIB_8BIT
#include "AdvPrevKnkT_MemMap.h"

CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_agIgKnkPrevOfs_B = 96U;
CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_agIgMaxPrevKnkOfsSat_C = 176U;
CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_agIgMinPrevKnkOfsSat_C = 69U;
CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_facFilDeltaAirLdDyn_C = 30U;
CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_idxModRatAirLdCalc_C = 0U;
CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_tCoMesDft_C = 130U;

#define AdvPrevKnkT_STOP_SEC_CALIB_8BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define AdvPrevKnkT_START_SEC_CARTO_8BIT
#include "AdvPrevKnkT_MemMap.h"

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevDynOfs_M[9][9] = { { 99U, 99U, 99U,
  99U, 99U, 99U, 99U, 99U, 99U },{ 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U },{ 99U,
  99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U },{ 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U,
  99U },{ 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U },{ 99U, 99U, 99U, 99U, 99U, 99U,
  99U, 99U, 99U },{ 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U },{ 99U, 99U, 99U, 99U,
  99U, 99U, 99U, 99U, 99U },{ 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U, 99U } } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevEGROfs_M[9][9] = { { 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U,
  96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U } } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevStatLamOfs_M[9][9] = { { 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },
{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U,
  96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U } } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevStatPOfs_M[9][9] = { { 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U,
  96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U } } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevStatTOfs_M[9][9] = { { 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U,
  96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U } } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_facFil1DeltaAirLdDyn_T[9] = { 60U, 60U,
  60U, 60U, 60U, 60U, 60U, 60U, 60U } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_facFil2DeltaAirLdDyn_T[9] = { 40U, 40U,
  40U, 40U, 40U, 40U, 40U, 40U, 40U } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_facFilAirLdDyn_M[9][9] = { { 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U },{ 100U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U },{ 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U },{ 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U },{ 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U },{ 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U },
{ 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U },{ 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U },{ 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U,
  100U } } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_knkAdp_PrevDynX_A[9] = { 96U, 99U, 101U,
  104U, 107U, 109U, 112U, 115U, 117U } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_noDlyCalcAirLdDyn_T[9] = { 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_noEgdGearCord_PrevDynX_A[6] = { 1U, 2U,
  3U, 4U, 5U, 6U } ;

CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevDyn1Ofs_M[9][16] = { { 25, 25, 25, 25,
  25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25 },{ 25, 25, 25, 25, 25, 25, 25, 25,
  25, 25, 25, 25, 25, 25, 25, 25 },{ 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
  25, 25, 25, 25 },{ 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25 },
{ 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25 },{ 25, 25, 25, 25,
  25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25 },{ 25, 25, 25, 25, 25, 25, 25, 25,
  25, 25, 25, 25, 25, 25, 25, 25 },{ 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
  25, 25, 25, 25 },{ 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25} };

CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevDyn2Ofs_M[6][6] = { { 25, 25, 25, 25,
  13, 13 },{ 25, 25, 25, 25, 13, 13 },{ 25, 25, 25, 25, 13, 13 },{ 25, 25, 25, 25, 13, 13 },
{ 25, 25, 25, 25, 13, 13 },{ 25, 25, 25, 25, 13, 13 } } ;

CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevStatPOfs_T[9] = { 0, 0, 0, 0, 0,
  0, 0, 0, 0 } ;

CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevStatTOfs_M[9][9] = { { 0, 0, 0, 0, 0,
  0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0,
  0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0,
  0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } } ;

#define AdvPrevKnkT_STOP_SEC_CARTO_8BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AdvPrevKnkT_START_SEC_CALIB_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"

CONST(Boolean, ADVPREVKNKT_CALIB) ADVPREVKNKT_ACTIVE_BYP_C = 0;
CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bAcvAirLdDynDet_C = 0;
CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bAcvAirLdDynPrevDet_C = 1;
CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bAirLdDynDet_B = 0;
CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bModDeltaAirLdDet_C = 1;
CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bSelFilTypAirLd_C = 1;

#define AdvPrevKnkT_STOP_SEC_CALIB_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvPrevKnkT_MemMap.h"

VAR(Float32, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynCalcOfs = 0.0F;
VAR(Float32, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynSlopDrivInc = 0.0F;
VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rDeltaAirLdDyn = 49152U;
VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rDeltaAirLdMod1_MP = 49152U;
VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rDeltaAirLdMod2_MP = 49152U;
VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rFil1DeltaAir_MP = 49152U;
VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rFil2DeltaAir_MP = 49152U;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvPrevKnkT_MemMap.h"

VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rAirLdClcRef = 0U;
VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rAirLdDynWoutFil = 0U;
VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rCorPrevStatPOfs_MP = 0U;
VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rCorPrevStatTOfs_MP = 0U;
VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_tiAirLdDynDet = 0U;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvPrevKnkT_MemMap.h"

VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynOfs = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynOfsCor_MP = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevEGROfs = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatLamOfs = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatOfs = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatPOfs = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatPOfs_MP = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatTOfs = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatTOfs_MP = 96U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_facFilAirLdDyn = 0U;
VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_noDlyClcAirLdDyn = 0U;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"

VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAcvAirLdDynDet2_MP = FALSE;
VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAcvKnkPrev = FALSE;
VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAirLdDynDetWoutTmr = FALSE;
VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAirLdDynPrevDynDet = FALSE;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
