/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngLimTqT                                               */
/* !Description     : EngLimTqT Software Component                            */
/*                                                                            */
/* !Module          : EngLimTqT                                               */
/*                                                                            */
/* !File            : EngLimTqT_Def.c                                         */
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
/*   Model name       : EngLimTqT_AUTOSAR.mdl                                 */
/*   Root subsystem   : /EngLimTqT                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M01-EngLimTqT/5$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Sep 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngLimTqT.h"
#include "EngLimTqT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CALIB_32BIT" */
#define EngLimTqT_START_SEC_CALIB_32BIT
#include "EngLimTqT_MemMap.h"

CONST(UInt32, ENGLIMTQT_CALIB) IgSys_lamClc_B = 0U;

#define EngLimTqT_STOP_SEC_CALIB_32BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define EngLimTqT_START_SEC_CARTO_16BIT
#include "EngLimTqT_MemMap.h"

CONST(SInt16, ENGLIMTQT_CARTO) EngLim_tqIdcPresUsThrMax_T[16] = { 4800, 4800,
  4800, 4800, 4800, 4800, 4800, 4800, 4800, 4800, 4800, 4800, 4800, 4800, 4800,
  4800 } ;

CONST(UInt16, ENGLIMTQT_CARTO) IgSys_rIgEfc_EfcIg_T[104] = { 1024U, 1014U,
  1004U, 993U, 983U, 983U, 973U, 963U, 952U, 952U, 942U, 932U, 922U, 911U, 911U,
  901U, 891U, 881U, 881U, 870U, 860U, 850U, 840U, 840U, 829U, 819U, 809U, 809U,
  799U, 788U, 778U, 768U, 768U, 758U, 748U, 737U, 727U, 727U, 717U, 707U, 696U,
  696U, 686U, 676U, 666U, 655U, 655U, 645U, 635U, 625U, 625U, 614U, 604U, 584U,
  573U, 563U, 563U, 553U, 543U, 532U, 522U, 512U, 502U, 492U, 492U, 481U, 471U,
  461U, 451U, 440U, 430U, 420U, 420U, 410U, 399U, 389U, 389U, 369U, 358U, 348U,
  348U, 338U, 328U, 317U, 307U, 307U, 297U, 287U, 276U, 276U, 266U, 256U, 246U,
  236U, 236U, 225U, 215U, 205U, 205U, 195U, 184U, 174U, 164U, 164U } ;

#define EngLimTqT_STOP_SEC_CARTO_16BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define EngLimTqT_START_SEC_CALIB_16BIT
#include "EngLimTqT_MemMap.h"

CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcAdvOptmTrbMax_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcAirResMax_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcAirTqWoutTotCutOf_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurGBx_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurMax_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurMinSelc_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurMin_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCur_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMaxTrbMaxNoOvb_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMaxTrbMax_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMinAdvMinSelc_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMinAdvMin_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcPresUsThrMax_B = 0;
CONST(UInt16, ENGLIMTQT_CALIB) IgSys_facTqtoPresIdc_C = 32001U;
CONST(UInt16, ENGLIMTQT_CALIB) IgSys_nEngStallThd_C = 200U;
CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rDynIgSpEfc_B = 0U;
CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rMaxIgEfc_B = 0U;
CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rMinIgEfc_B = 0U;
CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rStatIgSpEfc_B = 0U;
CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rlamClc_B = 0U;
CONST(SInt16, ENGLIMTQT_CALIB) IgSys_tqIdcEstim_B = 0;
CONST(SInt16, ENGLIMTQT_CALIB) IgSys_tqIdcLimMin_C = 32000;
CONST(SInt16, ENGLIMTQT_CALIB) IgSys_tqIdcThdMin_C = 0;

#define EngLimTqT_STOP_SEC_CALIB_16BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define EngLimTqT_START_SEC_CALIB_8BIT
#include "EngLimTqT_MemMap.h"

CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCCutOffDly_B = 0U;
CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCCutOffDly_C = 0U;
CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCOutCutOffDly_B = 0U;
CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCOutCutOffDly_C = 0U;
CONST(UInt8, ENGLIMTQT_CALIB) IgSys_stIgAgEfcGBx_C = 1U;
CONST(UInt8, ENGLIMTQT_CALIB) IgSys_stIgAgEfc_C = 1U;

#define EngLimTqT_STOP_SEC_CALIB_8BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define EngLimTqT_START_SEC_CALIB_BOOLEAN
#include "EngLimTqT_MemMap.h"

CONST(Boolean, ENGLIMTQT_CALIB) ENGLIMTQT_ACTIVE_BYP_C = 0;
CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLam1_C = 1;
CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLam2_C = 1;
CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLamClc_C = 1;
CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLamEfcGBx_C = 1;
CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLamEfc_C = 1;
CONST(Boolean, ENGLIMTQT_CALIB) IgSys_btqIdcPresUsThrMax_C = 0;

#define EngLimTqT_STOP_SEC_CALIB_BOOLEAN
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define EngLimTqT_START_SEC_CARTO_8BIT
#include "EngLimTqT_MemMap.h"

CONST(UInt8, ENGLIMTQT_CARTO) IgSys_agIg_EfcIg_A[104] = { 0U, 2U, 5U, 7U, 10U,
  12U, 15U, 17U, 20U, 22U, 25U, 27U, 30U, 32U, 35U, 37U, 40U, 42U, 45U, 47U, 50U,
  52U, 54U, 57U, 59U, 62U, 64U, 67U, 69U, 72U, 74U, 77U, 79U, 82U, 84U, 87U, 89U,
  92U, 94U, 97U, 99U, 102U, 104U, 106U, 109U, 111U, 114U, 116U, 119U, 121U, 124U,
  126U, 129U, 131U, 134U, 136U, 139U, 141U, 144U, 146U, 149U, 151U, 153U, 156U,
  158U, 161U, 163U, 166U, 168U, 171U, 173U, 176U, 178U, 181U, 183U, 186U, 188U,
  191U, 193U, 196U, 198U, 201U, 203U, 205U, 208U, 210U, 213U, 215U, 218U, 220U,
  223U, 225U, 228U, 230U, 233U, 235U, 238U, 240U, 243U, 245U, 248U, 250U, 253U,
  255U } ;

#define EngLimTqT_STOP_SEC_CARTO_8BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_32BIT
#include "EngLimTqT_MemMap.h"

VAR(Float32, ENGLIMTQT_INTERNAL_VAR) IgSys_facLamReqCor = 0.0F;
VAR(Float32, ENGLIMTQT_INTERNAL_VAR) IgSys_rMaxIgEfcWoutMv = 0.0F;
VAR(UInt32, ENGLIMTQT_INTERNAL_VAR) IgSys_rlamEngCorReqPrev = 0U;
VAR(UInt32, ENGLIMTQT_INTERNAL_VAR) IgSys_rlamEngCorReq_IRV_MP = 0U;
VAR(Float32, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimPrev = 0.0F;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_32BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_16BIT
#include "EngLimTqT_MemMap.h"

VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_presIdcEngCur = 32000U;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcAdvOptmMaxWoutOfs = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcEstimMax_MP = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcEstim_MP = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcMaxWoutOvb_MP = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcMinAirLdAvgCyl = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcMinAirLd_IRV_MP = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcPresMinEstim_MP = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcPresUsMax_IRV_MP = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcTrbMaxWoutOvb_IRV_MP = 0;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtDyn_MP = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtMax_MP = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtMin_MP = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtStat_MP = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_01 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_02 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_03 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_04 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_05 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_06 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcPrevCyl[6] = { 0U, 0U,
  0U, 0U, 0U, 0U };

VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_01 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_02 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_03 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_04 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_05 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_06 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcPrevCyl[6] = { 0U, 0U,
  0U, 0U, 0U, 0U };

VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_01 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_02 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_03 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_04 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_05 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_06 = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcPrevCyl[6] = { 0U,
  0U, 0U, 0U, 0U, 0U };

VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rAirLdPredPrev = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rAirLdPred_IRV_MP = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rDynIgSpEfcWoutMv_IRV_MP = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rMaxIgEfcWoutMv_MP = 0U;
VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rStatIgSpEfcWoutMv_IRV_MP = 0U;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimAvgCylWiLam = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimAvgCylWoutLam = 0;
VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimAvgCyl_IRV_MP = 0;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_16BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_8BIT
#include "EngLimTqT_MemMap.h"

VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcDyn_MP = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcMax_MP = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcMin_MP = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcStat_MP = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylCutOffDlyOutSat = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylCutOffSat = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylCutOffSatDly = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylInc1_IRV_MP = 0U;
VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylIncPrev1 = 0U;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_8BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "EngLimTqT_MemMap.h"

VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bCylCutOffSat = FALSE;
VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bCylCutOffTrigSat = FALSE;
VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bTotCutOffDly = FALSE;
VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bTqIdcCutOff_IRV_MP = FALSE;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "EngLimTqT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
