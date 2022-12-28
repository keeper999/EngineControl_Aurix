/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : InThMdlT                                                */
/* !Description     : InThMdlT Software Component                             */
/*                                                                            */
/* !Module          : InThMdlT                                                */
/*                                                                            */
/* !File            : InThMdlT_Def.c                                          */
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
/*   Model name       : InThMdlT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /InThMdlT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M03-InThMdlT/5-S$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Nov 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InThMdlT.h"
#include "InThMdlT_private.h"

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
#define InThMdlT_START_SEC_CARTO_16BIT
#include "InThMdlT_MemMap.h"

CONST(SInt16, INTHMDLT_CARTO) InThM_rEngSpdCorDB_T[16] = { MIN_int16_T, -26214,
  -19661, -16384, -13107, -9830, -6554, MIN_int16_T, 0, 32767, 6554, 9830, 13107,
  19661, 26214, 32767 } ;

CONST(SInt16, INTHMDLT_CARTO) InThM_rEngSpdCor_A[16] = { MIN_int16_T, -26214,
  -19661, -16384, -13107, -9830, -6554, -3277, 0, 3277, 6554, 9830, 13107, 19661,
  26214, 32767 } ;

CONST(SInt16, INTHMDLT_CARTO) InThM_rEngSpdCor_M[16][16] = { {14772, 14772, 14772,
  14772, 14772, 14772, 14772, 14772, 14772, 14772, 14772, 14772, 14772, 14772,
  14772, 14772}, {10705, 10705, 10705, 10705, 10705, 10705, 10705, 10705, 10705,
  10705, 10705, 10705, 10705, 10705, 10705, 10705}, {6919, 6919, 6919, 6919, 6919,
  6919, 6919, 6919, 6919, 6919, 6919, 6919, 6919, 6919, 6919, 6919}, {5115, 5115,
  5115, 5115, 5115, 5115, 5115, 5115, 5115, 5115, 5115, 5115, 5115, 5115, 5115,
  5115}, {3709, 3709, 3709, 3709, 3709, 3709, 3709, 3709, 3709, 3709, 3709, 3709,
  3709, 3709, 3709, 3709}, {2335, 2335, 2335, 2335, 2335, 2335, 2335, 2335, 2335,
  2335, 2335, 2335, 2335, 2335, 2335, 2335}, {991, 991, 991, 991, 991, 991, 991,
  991, 991, 991, 991, 991, 991, 991, 991, 991}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0}, {-1618, -1618, -1618, -1618, -1618, -1618, -1618, -1618, -1618,
  -1618, -1618, -1618, -1618, -1618, -1618, -1618}, {-3199, -3199, -3199, -3199,
  -3199, -3199, -3199, -3199, -3199, -3199, -3199, -3199, -3199, -3199, -3199,
  -3199}, {-4744, -4744, -4744, -4744, -4744, -4744, -4744, -4744, -4744, -4744,
  -4744, -4744, -4744, -4744, -4744, -4744}, {-6255, -6255, -6255, -6255, -6255,
  -6255, -6255, -6255, -6255, -6255, -6255, -6255, -6255, -6255, -6255, -6255},
  {-9187, -9187, -9187, -9187, -9187, -9187, -9187, -9187, -9187, -9187, -9187,
  -9187, -9187, -9187, -9187, -9187}, {-12007, -12007, -12007, -12007, -12007,
  -12007, -12007, -12007, -12007, -12007, -12007, -12007, -12007, -12007, -12007,
  -12007}, {-14729, -14729, -14729, -14729, -14729, -14729, -14729, -14729, -14729,
  -14729, -14729, -14729, -14729, -14729, -14729, -14729}, {-14729, -14729, -14729,
  -14729, -14729, -14729, -14729, -14729, -14729, -14729, -14729, -14729, -14729,
  -14729, -14729, -14729} } ;

CONST(UInt16, INTHMDLT_CARTO) InThM_rtInMnf_A[16] = { 19660U, 22937U, 26213U,
  27852U, 29163U, 30473U, 31784U, 32767U, 34405U, 36044U, 37682U, 39321U, 42597U,
  45874U, 49151U, 62258U } ;

CONST(UInt16, INTHMDLT_CARTO) InThM_tInMnfRef_M[16][16] = { {9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U}, {9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U}, {9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U}, {9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U}, {9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U},
  {9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U}, {9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U}, {9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U}, {9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U}, {9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U}, {9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U}, {9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U}, {9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U}, {9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U}, {9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U}, {9619U, 9619U, 9619U, 9619U, 9619U,
  9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U, 9619U} } ;

CONST(UInt16, INTHMDLT_CARTO) InThM_tOfsCorUsEGRVlv_M[9][9] = { {32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U},
  {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U} } ;

CONST(UInt16, INTHMDLT_CARTO) InThM_tUsEGRVlv_T[9] = { 3104U, 4128U, 10528U,
  11808U, 12832U, 13856U, 14624U, 18208U, 27680U } ;

#define InThMdlT_STOP_SEC_CARTO_16BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define InThMdlT_START_SEC_CALIB_16BIT
#include "InThMdlT_MemMap.h"

CONST(UInt16, INTHMDLT_CALIB) Eng_rAirLdRef2_A[9] = { 1802U, 3277U, 4096U,
  5079U, 6226U, 8192U, 9831U, 11469U, 13927U } ;

CONST(UInt16, INTHMDLT_CALIB) InThM_nEngCor_B = 0U;
CONST(UInt16, INTHMDLT_CALIB) InThM_tAirUsInVlvEstim_B = 0U;
CONST(UInt16, INTHMDLT_CALIB) InThM_tCylEstimETB_C = 9600U;
CONST(UInt16, INTHMDLT_CALIB) InThM_tEGRInMnf_B = 0U;
CONST(UInt16, INTHMDLT_CALIB) InThM_tInMnfEstim_B = 0U;
CONST(UInt16, INTHMDLT_CALIB) InThM_tMixtInMnf_B = 0U;
CONST(UInt16, INTHMDLT_CALIB) InThM_tWallInMnf_B = 0U;

#define InThMdlT_STOP_SEC_CALIB_16BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define InThMdlT_START_SEC_CALIB_BOOLEAN
#include "InThMdlT_MemMap.h"

CONST(Boolean, INTHMDLT_CALIB) INTHMDLT_ACTIVE_BYP_C = 0;
CONST(Boolean, INTHMDLT_CALIB) InThM_bAcvETB_tCylEstim_C = 1;
CONST(Boolean, INTHMDLT_CALIB) InThM_bAcvEngSpdCor_C = 1;
CONST(Boolean, INTHMDLT_CALIB) InThM_bSelHtfClcMod_C = 0;

#define InThMdlT_STOP_SEC_CALIB_BOOLEAN
#include "InThMdlT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define InThMdlT_START_SEC_CALIB_8BIT
#include "InThMdlT_MemMap.h"

CONST(UInt8, INTHMDLT_CALIB) InThM_facGainHeatFil_tEGR_C = 255U;
CONST(UInt8, INTHMDLT_CALIB) InThM_facHeatExcWallInMnf_B = 0U;
CONST(UInt8, INTHMDLT_CALIB) InThM_tSqrtEgUsEGRVlv_B = 0U;

#define InThMdlT_STOP_SEC_CALIB_8BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define InThMdlT_START_SEC_CARTO_8BIT
#include "InThMdlT_MemMap.h"

CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExcWallInMnfPipe_M[16][16] = { {255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U},
  {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U} } ;

CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExcWallInMnfPipe_T[9] = { 150U, 88U,
  53U, 39U, 31U, 25U, 20U, 17U, 15U } ;

CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExcWallInMnf_T[9] = { 255U, 237U,
  191U, 166U, 150U, 136U, 126U, 117U, 111U } ;

CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExgWallEGRPipe_T[9] = { 113U, 113U,
  113U, 113U, 113U, 110U, 105U, 92U, 84U } ;

CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatFil_tWallInMnf_M[9] = { 109U, 109U,
  92U, 81U, 73U, 67U, 62U, 58U, 54U } ;

#define InThMdlT_STOP_SEC_CARTO_8BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define InThMdlT_START_SEC_INTERNAL_VAR_32BIT
#include "InThMdlT_MemMap.h"

VAR(Float32, INTHMDLT_INTERNAL_VAR) InThM_tEGRUsEGRVlvPrev = 0.0F;
VAR(Float32, INTHMDLT_INTERNAL_VAR) InThM_tEgRawUsEGRVlv = 0.0F;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_32BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define InThMdlT_START_SEC_INTERNAL_VAR_16BIT
#include "InThMdlT_MemMap.h"

VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_facHeatFil_tWallInMnf_MP = 0U;
VAR(SInt16, INTHMDLT_INTERNAL_VAR) InThM_nDeltaEngSpd_MP = 0;
VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_nEngCorWoutDiag = 0U;
VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_nEng_MP = 0U;
VAR(SInt16, INTHMDLT_INTERNAL_VAR) InThM_rEngSpdCorDB_MP = 0;
VAR(SInt16, INTHMDLT_INTERNAL_VAR) InThM_rEngSpdCor_MP = 0;
VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_rtInMnf_MP = 0U;
VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_tAirUsInVlvEstimRaw = 0U;
VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_tEGRUsEGRVlv_IRV_MP = 1600U;
VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_tWallInCylHead_IRV_MP = 6400U;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_16BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define InThMdlT_START_SEC_INTERNAL_VAR_8BIT
#include "InThMdlT_MemMap.h"

VAR(UInt8, INTHMDLT_INTERNAL_VAR) InThM_facHeatExcWallEGRPipe_MP = 0U;
VAR(UInt8, INTHMDLT_INTERNAL_VAR) InThM_facHeatExcWallInPipe_MP = 0U;
VAR(UInt8, INTHMDLT_INTERNAL_VAR) InThM_facNormHeat_tWallInMnf_MP = 0U;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_8BIT
#include "InThMdlT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
