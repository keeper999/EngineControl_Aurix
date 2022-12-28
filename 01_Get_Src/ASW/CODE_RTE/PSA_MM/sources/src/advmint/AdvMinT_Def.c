/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMinT                                                 */
/* !Description     : AdvMinT Software Component                              */
/*                                                                            */
/* !Module          : AdvMinT                                                 */
/*                                                                            */
/* !File            : AdvMinT_Def.c                                           */
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
/*   Model name       : AdvMinT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMinT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M02-AdvMinT/5-S$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   23 Oct 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvMinT.h"
#include "AdvMinT_private.h"

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
#define AdvMinT_START_SEC_CALIB_16BIT
#include "AdvMinT_MemMap.h"

CONST(UInt16, ADVMINT_CALIB) EngM_rAirLdCor_A[12] = { 1638U, 4096U, 6554U,
  9011U, 11469U, 13926U, 16384U, 18842U, 21299U, 23757U, 26214U, 28672U } ;

CONST(UInt16, ADVMINT_CALIB) FARSp_rMixtAgIgMinProtRef_C = 4000U;
CONST(UInt16, ADVMINT_CALIB) IgSys_agIgMinDrivIncOfs_C = 3U;
CONST(UInt16, ADVMINT_CALIB) IgSys_agIgMinThermoDecOfs_C = 3U;
CONST(UInt16, ADVMINT_CALIB) IgSys_agIgMinThermoIncOfs_C = 3U;
CONST(UInt16, ADVMINT_CALIB) IgSys_nEngMinStrt_A[16] = { 500U, 750U, 1000U,
  1250U, 1500U, 1750U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 5500U,
  6000U, 6500U } ;

CONST(UInt16, ADVMINT_CALIB) IgSys_nEng_Cor_A[6] = { 500U, 1000U, 2000U, 3000U,
  5000U, 7000U } ;

CONST(UInt16, ADVMINT_CALIB) IgSys_rAirLdCor_Cor_A[7] = { 1638U, 4915U, 9830U,
  14746U, 18022U, 22938U, 27853U } ;

CONST(UInt16, ADVMINT_CALIB) IgSys_rMixt_facAgIgMinProt_A[11] = { 0U, 400U,
  800U, 1200U, 1600U, 2000U, 2400U, 2800U, 3200U, 3600U, 4000U } ;

CONST(SInt16, ADVMINT_CALIB) IgSys_tCoAgIgMinX_A[8] = { -30, -15, 0, 20, 60, 90,
  100, 110 } ;

CONST(SInt16, ADVMINT_CALIB) IgSys_tCoMes_A[16] = { -30, -25, -18, -10, 0, 10,
  18, 25, 30, 40, 50, 62, 74, 86, 98, 110 } ;

CONST(UInt16, ADVMINT_CALIB) IgSys_tExMaxASR_C = 56864U;
CONST(UInt16, ADVMINT_CALIB) IgSys_tExMax_C = 40864U;

#define AdvMinT_STOP_SEC_CALIB_16BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define AdvMinT_START_SEC_CARTO_16BIT
#include "AdvMinT_MemMap.h"

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgColdCor_M[16][16] = { { 14, 14, 14, 30, 40,
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40 },{ 14, 14, 14, 30, 40, 40, 40, 40, 40,
  40, 40, 40, 40, 40, 40, 40 },{ 0, 5, 14, 28, 39, 40, 40, 40, 40, 40, 40, 40, 40,
  40, 40, 40 },{ 0, 5, 14, 28, 39, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40 },{ 0, 5,
  14, 25, 32, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40 },{ 0, 5, 14, 25, 32, 40,
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40 },{ 0, 0, 13, 25, 30, 40, 40, 40, 40, 40,
  40, 40, 40, 40, 40, 40 },{ 0, 0, 13, 24, 28, 40, 40, 40, 40, 40, 40, 40, 40, 40,
  40, 40 },{ 0, 0, 13, 21, 26, 32, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40 },{ 0, 0, 11,
  19, 21, 27, 32, 37, 40, 40, 40, 40, 40, 40, 40, 40 },{ 0, 0, 8, 13, 16, 19, 21,
  24, 27, 27, 27, 27, 27, 27, 27, 27 },{ 0, 0, 5, 8, 9, 10, 11, 12, 13, 13, 13, 13,
  13, 13, 13, 13 },{ 0, 0, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5 },{ 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } ;

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinDriv_M[16][16] = { { 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } ;

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinExVlvMax_M[16][16] = { { -44, -44, -44,
  -42, -72, -82, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -42, -72, -84, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -38, -64, -74, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -31, -49, -17,
  -25, -51, -60, -78, -81, -81, -81, -81, -81, -81, -81, -81, -81 },{ -31, -36, -2,
  -24, -39, -42, -46, -42, -42, -42, -42, -42, -42, -42, -42, -42 },{ -23, -20, 1,
  -18, -28, -30, -23, -20, -14, -14, -14, -14, -14, -14, -14, -14 },{ 8, 8, -2, -15,
  -15, -11, -3, 4, 7, 7, 7, 7, 7, 7, 7, 7 },{ 1, 1, -2, -4, 0, 2, 5, 10, 10, 10, 10,
  10, 10, 10, 10, 10 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },
{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10,
  16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16,
  16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6,
  4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16,
  16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16,
  16, 16, 16 } } ;

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinExVlvMin_M[16][16] = { { -44, -44, -44,
  -42, -72, -82, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -42, -72, -84, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -38, -64, -74, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -31, -49, -17,
  -25, -51, -60, -78, -81, -81, -81, -81, -81, -81, -81, -81, -81 },{ -31, -36, -2,
  -24, -39, -42, -46, -42, -42, -42, -42, -42, -42, -42, -42, -42 },{ -23, -20, 1,
  -18, -28, -30, -23, -20, -14, -14, -14, -14, -14, -14, -14, -14 },{ 8, 8, -2, -15,
  -15, -11, -3, 4, 7, 7, 7, 7, 7, 7, 7, 7 },{ 1, 1, -2, -4, 0, 2, 5, 10, 10, 10, 10,
  10, 10, 10, 10, 10 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },
{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10,
  16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16,
  16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6,
  4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16,
  16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16,
  16, 16, 16 } } ;

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinInVlvMax_M[16][16] = { { -44, -44, -44,
  -42, -72, -82, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -42, -72, -84, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -38, -64, -74, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -31, -49, -17,
  -25, -51, -60, -78, -81, -81, -81, -81, -81, -81, -81, -81, -81 },{ -31, -36, -2,
  -24, -39, -42, -46, -42, -42, -42, -42, -42, -42, -42, -42, -42 },{ -23, -20, 1,
  -18, -28, -30, -23, -20, -14, -14, -14, -14, -14, -14, -14, -14 },{ 8, 8, -2, -15,
  -15, -11, -3, 4, 7, 7, 7, 7, 7, 7, 7, 7 },{ 1, 1, -2, -4, 0, 2, 5, 10, 10, 10, 10,
  10, 10, 10, 10, 10 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },
{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10,
  16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16,
  16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6,
  4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16,
  16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16,
  16, 16, 16 } } ;

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinInVlvMin_M[16][16] = { { -44, -44, -44,
  -42, -72, -82, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -42, -72, -84, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -38, -64, -74, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -31, -49, -17,
  -25, -51, -60, -78, -81, -81, -81, -81, -81, -81, -81, -81, -81 },{ -31, -36, -2,
  -24, -39, -42, -46, -42, -42, -42, -42, -42, -42, -42, -42, -42 },{ -23, -20, 1,
  -18, -28, -30, -23, -20, -14, -14, -14, -14, -14, -14, -14, -14 },{ 8, 8, -2, -15,
  -15, -11, -3, 4, 7, 7, 7, 7, 7, 7, 7, 7 },{ 1, 1, -2, -4, 0, 2, 5, 10, 10, 10, 10,
  10, 10, 10, 10, 10 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },
{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10,
  16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16,
  16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6,
  4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16,
  16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 4, 7, 10, 16, 16, 16, 16, 16, 16,
  16, 16, 16 } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_agIgMinStrtDecOfs_T[8] = { 0U, 1U, 1U, 2U,
  2U, 3U, 3U, 3U } ;

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgNotCorMinThdReac_M[16][16] = { { -57, -57,
  -44, -42, -72, -82, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -57, -57,
  -44, -42, -72, -84, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -57, -57,
  -44, -38, -64, -74, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -57, -57,
  -44, -25, -51, -60, -78, -81, -81, -81, -81, -81, -81, -81, -81, -81 },{ -44, -44,
  -31, -24, -39, -42, -46, -42, -42, -42, -42, -42, -42, -42, -42, -42 },{ -23, -20,
  1, -18, -28, -30, -23, -20, -14, -14, -14, -14, -14, -14, -14, -14 },{ 8, 8, -2,
  -15, -15, -11, -3, 4, 7, 7, 7, 7, 7, 7, 7, 7 },{ 1, 1, -2, -4, 0, 2, 5, 10, 10,
  10, 10, 10, 10, 10, 10, 10 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16,
  16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4,
  5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16,
  16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16,
  16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7,
  10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16,
  16, 16, 16, 16, 16 } } ;

CONST(SInt16, ADVMINT_CARTO) IgSys_agIgNotCorMinThd_M[16][16] = { { -44, -44, -44,
  -42, -72, -82, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -42, -72, -84, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -44, -44, -44,
  -38, -64, -74, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96 },{ -31, -49, -17,
  -25, -51, -60, -78, -81, -81, -81, -81, -81, -81, -81, -81, -81 },{ -31, -36, -2,
  -24, -39, -42, -46, -42, -42, -42, -42, -42, -42, -42, -42, -42 },{ -23, -20, 1,
  -18, -28, -30, -23, -20, -14, -14, -14, -14, -14, -14, -14, -14 },{ 8, 8, -2, -15,
  -15, -11, -3, 4, 7, 7, 7, 7, 7, 7, 7, 7 },{ 1, 1, -2, -4, 0, 2, 5, 10, 10, 10, 10,
  10, 10, 10, 10, 10 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },
{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10,
  16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16,
  16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6,
  4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16,
  16, 16, 16, 16, 16, 16, 16, 16 },{ 6, 6, 4, 4, 5, 7, 10, 16, 16, 16, 16, 16, 16,
  16, 16, 16 } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinAOSAcv_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinAOSInh_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinESPAcv_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinESPInh_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinGcAcv_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinGcInh_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinLimSurgeAcv_M[6][7] = { { 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinLimSurgeInh_M[6][7] = { { 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinPrevAcv_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinPrevInh_M[6][7] = { { 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyIgLim_T[7] = { 1U, 1U, 1U, 1U, 1U, 1U,
  1U } ;

#define AdvMinT_STOP_SEC_CARTO_16BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AdvMinT_START_SEC_CALIB_8BIT
#include "AdvMinT_MemMap.h"

CONST(UInt8, ADVMINT_CALIB) IgSys_agCkVlvEstim_A[9] = { 0U, 32U, 64U, 96U,
  128U, 160U, 192U, 224U, 255U } ;

CONST(UInt8, ADVMINT_CALIB) IgSys_agIgLimMinKnk_B = 96U;
CONST(UInt8, ADVMINT_CALIB) IgSys_agIgLimMinRef_B = 96U;
CONST(UInt8, ADVMINT_CALIB) IgSys_agIgMinCmb_B = 96U;
CONST(UInt8, ADVMINT_CALIB) IgSys_agIgMinThermo_B = 96U;
CONST(UInt8, ADVMINT_CALIB) IgSys_agIgMin_B = 96U;
CONST(UInt8, ADVMINT_CALIB) IgSys_noGear6_A[7] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U
} ;

CONST(UInt8, ADVMINT_CALIB) IgSys_tAgIgMinDriv_C = 100U;
CONST(UInt8, ADVMINT_CALIB) InjSys_noCylCutOffInh_C = 1U;

#define AdvMinT_STOP_SEC_CALIB_8BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AdvMinT_START_SEC_CALIB_BOOLEAN
#include "AdvMinT_MemMap.h"

CONST(Boolean, ADVMINT_CALIB) ADVMINT_ACTIVE_BYP_C = 0;
CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinCurAAMin_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinESPASR_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinLimSurge_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinPrevAAMin_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinSIP_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAgIgMinDrivOfs_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bFlexMinCmbOfs_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bFlexMinThermoOfs_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bGasMinCmbOfs_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bGasMinThermoOfs_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_bRichLoTqAuth_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_idxAdvMinESPASR_C = 1;
CONST(Boolean, ADVMINT_CALIB) IgSys_idxAdvMinSIP_C = 1;

#define AdvMinT_STOP_SEC_CALIB_BOOLEAN
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define AdvMinT_START_SEC_CARTO_8BIT
#include "AdvMinT_MemMap.h"

CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinCANESP_M[16][12] = { { 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinCANSIP_M[16][12] = { { 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinGsl_M[16][16] = { { 69U, 57U, 43U, 31U,
  19U, 6U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 69U, 57U, 43U, 31U, 19U, 6U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 69U, 30U, 23U, 6U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 69U, 50U, 42U, 32U, 28U, 33U, 44U, 47U, 51U, 51U,
  51U, 51U, 51U, 51U, 51U, 51U },{ 69U, 63U, 58U, 57U, 59U, 66U, 71U, 76U, 76U, 76U,
  76U, 76U, 76U, 76U, 76U, 76U },{ 78U, 79U, 79U, 78U, 81U, 87U, 91U, 96U, 101U,
  101U, 101U, 101U, 101U, 101U, 101U, 101U },{ 86U, 90U, 89U, 89U, 92U, 97U, 103U,
  107U, 112U, 112U, 112U, 112U, 112U, 112U, 112U, 112U },{ 96U, 102U, 103U, 104U,
  105U, 111U, 114U, 120U, 125U, 125U, 125U, 125U, 125U, 125U, 125U, 125U },{ 104U,
  109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U,
  135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U,
  135U, 135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U,
  135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U,
  118U, 122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U },{ 104U, 109U,
  108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U, 135U,
  135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U, 135U,
  135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U,
  135U, 135U, 135U, 135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U,
  122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U } } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinKnk_M[16][16] = { { 69U, 57U, 43U, 31U,
  19U, 6U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 69U, 57U, 43U, 31U, 19U, 6U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 69U, 30U, 23U, 6U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 69U, 50U, 42U, 32U, 28U, 33U, 44U, 47U, 51U, 51U,
  51U, 51U, 51U, 51U, 51U, 51U },{ 69U, 63U, 58U, 57U, 59U, 66U, 71U, 76U, 76U, 76U,
  76U, 76U, 76U, 76U, 76U, 76U },{ 78U, 79U, 79U, 78U, 81U, 87U, 91U, 96U, 101U,
  101U, 101U, 101U, 101U, 101U, 101U, 101U },{ 86U, 90U, 89U, 89U, 92U, 97U, 103U,
  107U, 112U, 112U, 112U, 112U, 112U, 112U, 112U, 112U },{ 96U, 102U, 103U, 104U,
  105U, 111U, 114U, 120U, 125U, 125U, 125U, 125U, 125U, 125U, 125U, 125U },{ 104U,
  109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U,
  135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U,
  135U, 135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U,
  135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U,
  118U, 122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U },{ 104U, 109U,
  108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U, 135U,
  135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U, 135U, 135U, 135U,
  135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U, 122U, 128U, 135U,
  135U, 135U, 135U, 135U, 135U, 135U, 135U },{ 104U, 109U, 108U, 110U, 111U, 118U,
  122U, 128U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U } } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinStrt_M[16][16] = { { 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U },{ 96U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U, 96U } } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_facAgIgMinProt_T[11] = { 0U, 10U, 20U, 30U,
  40U, 50U, 60U, 70U, 80U, 90U, 100U } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_facMinDriv_M[16][16] = { { 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinExVlvMax_T[9] = { 0U, 32U, 64U, 96U,
  128U, 160U, 192U, 224U, 255U } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinExVlvMin_T[9] = { 0U, 32U, 64U, 96U,
  128U, 160U, 192U, 224U, 255U } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinInVlvMax_T[9] = { 0U, 32U, 64U, 96U,
  128U, 160U, 192U, 224U, 255U } ;

CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinInVlvMin_T[9] = { 0U, 32U, 64U, 96U,
  128U, 160U, 192U, 224U, 255U } ;

#define AdvMinT_STOP_SEC_CARTO_8BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define AdvMinT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvMinT_MemMap.h"

VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinCmbWoutOfs = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinExVlvMax = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinExVlvMin = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinInVlvMax = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinInVlvMin = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinThermoWoutOfs = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgWrmMin = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgWrmUpCor = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinExVlvMax = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinExVlvMin = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinInVlvMax = 0.0F;
VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinInVlvMin = 0.0F;

#define AdvMinT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define AdvMinT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvMinT_MemMap.h"

VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaExVlv3_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaExVlv4_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaInVlv3_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaInVlv4_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgColdCor_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgMinCmbWiFlexCor_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgMinDriv_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgMinThermoWiFlex_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgNotCorMinThdReac_MP = 0;
VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgNotCorMinThd_MP = 0;
VAR(UInt16, ADVMINT_INTERNAL_VAR) IgSys_rMixtAgIgMinLim_MP = 0U;

#define AdvMinT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define AdvMinT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvMinT_MemMap.h"

VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgMinCmbWiCANSpcReq = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgMinDriv_IRV_MP = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgMinStrt_IRV_MP = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopDrivInc = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopStrtDec = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopThermoDec = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopThermoInc = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSpDriv_MP = 96U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_ctLimAdvReact_IRV_MP = 0U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_facAgIgMinProt_MP = 0U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_facMinDriv_MP = 0U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaExVlv3_MP = 0U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaExVlv4_MP = 0U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaInVlv3_MP = 0U;
VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaInVlv4_MP = 0U;

#define AdvMinT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvMinT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMinT_MemMap.h"

VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bAcvMinMgr = FALSE;
VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bDriv = FALSE;
VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bDriv_MP = FALSE;
VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bExThermoProt = FALSE;
VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmInhThermoProt_MP[5] = { FALSE,
  FALSE, FALSE, FALSE, FALSE };

VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmTimerIn1_MP[5] = { FALSE, FALSE,
  FALSE, FALSE, FALSE };

VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmTimerOut1_MP[5] = { FALSE, FALSE,
  FALSE, FALSE, FALSE };

VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmTimerOut2_MP[5] = { FALSE, FALSE,
  FALSE, FALSE, FALSE };

#define AdvMinT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMinT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
