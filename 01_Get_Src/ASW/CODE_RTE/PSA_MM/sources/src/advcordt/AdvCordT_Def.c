/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvCordT                                                */
/* !Description     : AdvCordT Software Component                             */
/*                                                                            */
/* !Module          : AdvCordT                                                */
/*                                                                            */
/* !File            : AdvCordT_Def.c                                          */
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
/*   Model name       : AdvCordT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /AdvCordT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M07-AdvCordT/5-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvCordT.h"
#include "AdvCordT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CALIB_16BIT" */
#define AdvCordT_START_SEC_CALIB_16BIT
#include "AdvCordT_MemMap.h"

CONST(UInt16, ADVCORDT_CALIB) IgSys_agIgOfsTest_C = 267U;
CONST(SInt16, ADVCORDT_CALIB) IgSys_agIgSTTEsOfsDown_C = 3;
CONST(SInt16, ADVCORDT_CALIB) IgSys_agIgSTTEsOfsUp_C = 1;
CONST(SInt16, ADVCORDT_CALIB) IgSys_agIgTCoThdOfs_C = 40;
CONST(SInt16, ADVCORDT_CALIB) IgSys_pDsThrMesRef_C = 1015;

#define AdvCordT_STOP_SEC_CALIB_16BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define AdvCordT_START_SEC_CARTO_16BIT
#include "AdvCordT_MemMap.h"

CONST(UInt16, ADVCORDT_CARTO) IgSys_nCkFilTestY_A[16] = { 500U, 750U, 900U,
  1000U, 1500U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 5500U, 6000U,
  6500U, 7000U } ;

CONST(UInt16, ADVCORDT_CARTO) IgSys_rAirLdTestX_A[16] = { 3277U, 4915U, 6554U,
  8192U, 9830U, 11469U, 13107U, 14746U, 16384U, 18022U, 19661U, 21299U, 22938U,
  24576U, 26214U, 27853U } ;

#define AdvCordT_STOP_SEC_CARTO_16BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AdvCordT_START_SEC_CALIB_8BIT
#include "AdvCordT_MemMap.h"

CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgColdOfs_C = 96U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgDeltaMaxThd_C = 99U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgDynIgSpEfc_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgLimKnkMax_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgLimKnkMin_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgLimKnkMv_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgMaxMod_C = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgMax_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgSpNxt_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgSpWoutKnkDet_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgSp_B = 0U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl1_C = 96U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl2_C = 96U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl3_C = 96U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl4_C = 96U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl5_C = 96U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl6_C = 96U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgWarmOfs_C = 97U;
CONST(UInt8, ADVCORDT_CALIB) IgSys_noAdvETBMod_C = 3U;

#define AdvCordT_STOP_SEC_CALIB_8BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AdvCordT_START_SEC_CALIB_BOOLEAN
#include "AdvCordT_MemMap.h"

CONST(Boolean, ADVCORDT_CALIB) ADVCORDT_ACTIVE_BYP_C = 0;
CONST(Boolean, ADVCORDT_CALIB) IgSys_bAirLdSel_C = 1;
CONST(Boolean, ADVCORDT_CALIB) IgSys_bKnkAdvETB_C = 1;
CONST(Boolean, ADVCORDT_CALIB) IgSys_bSelAgIgCordTyp_C = 1;

#define AdvCordT_STOP_SEC_CALIB_BOOLEAN
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define AdvCordT_START_SEC_CARTO_8BIT
#include "AdvCordT_MemMap.h"

CONST(UInt8, ADVCORDT_CARTO) IgSys_agIgTest_M[16][16] = { {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U}, {96U, 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U} } ;

CONST(UInt8, ADVCORDT_CARTO) IgSys_prm_agIgLimKnk_B[6] = { 0U, 0U, 0U, 0U, 0U,
  0U } ;

CONST(UInt8, ADVCORDT_CARTO) IgSys_prm_agIgSpCyl_B[6] = { 0U, 0U, 0U, 0U, 0U,
  0U } ;

#define AdvCordT_STOP_SEC_CARTO_8BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define AdvCordT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvCordT_MemMap.h"

VAR(Float32, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxAfterStrt = 0.0F;
VAR(Float32, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxAfterStrtOfs = 0.0F;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define AdvCordT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvCordT_MemMap.h"

VAR(UInt16, ADVCORDT_INTERNAL_VAR) IgSys_agIgOfsTest_IRV_MP = 267U;
VAR(UInt16, ADVCORDT_INTERNAL_VAR) IgSys_rAirLdSel_MP = 0U;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvCordT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvCordT_MemMap.h"

VAR(Boolean, ADVCORDT_INTERNAL_VAR) IgSys_bSelAgIgOfs_MP = FALSE;
VAR(Boolean, ADVCORDT_INTERNAL_VAR) IgSys_bSelAgIgTarThd_MP = FALSE;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvCordT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define AdvCordT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvCordT_MemMap.h"

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgCord1Next_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgCord2Next_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgCord3Next_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgDeltaMaxAfterStrt_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCyl1_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCylMv_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCylSel1_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCylSel_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCyl_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgLimKnkCyl1_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgLimKnkCyl_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxAgIgMinMax1_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxWiPrevAdpCyl_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgOfs = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgOfsPrev_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgSpSel1_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgSpSel_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgTestCyl1_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgTestCyl_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgTest_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgCord1_MP[3] = { 96U, 96U, 96U
};

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgCord2_MP[3] = { 96U, 96U, 96U
};

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgCord3_MP[3] = { 96U, 96U, 96U
};

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgKnkSatMax_MP[6] = { 96U, 96U,
  96U, 96U, 96U, 96U };

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgKnkSatMin_MP[6] = { 96U, 96U,
  96U, 96U, 96U, 96U };

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgMaxAgIgMinMax_MP[3] = { 96U,
  96U, 96U };

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgMaxCord_MP[3] = { 96U, 96U,
  96U };

VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_001_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_002_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_003_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_004_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_005_IRV_MP = 96U;
VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_006_IRV_MP = 96U;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvCordT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
