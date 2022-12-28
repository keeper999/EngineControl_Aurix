/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvSpT                                                  */
/* !Description     : AdvSpT Software Component                               */
/*                                                                            */
/* !Module          : AdvSpT                                                  */
/*                                                                            */
/* !File            : AdvSpT_Def.c                                            */
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
/*   Model name       : AdvSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /AdvSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M06-AdvSpT/5-SO$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   02 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvSpT.h"
#include "AdvSpT_private.h"

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
#define AdvSpT_START_SEC_CALIB_16BIT
#include "AdvSpT_MemMap.h"

CONST(UInt16, ADVSPT_CALIB) IgSys_nEngThd_CutOff_C = 100U;
CONST(UInt16, ADVSPT_CALIB) IgSys_r80PercTq_C = 819U;
CONST(SInt16, ADVSPT_CALIB) IgSys_tCoMesSftyVal_C = -30;
CONST(SInt16, ADVSPT_CALIB) IgSys_tCoThd_CutOff_C = 90;
CONST(UInt16, ADVSPT_CALIB) IgSys_tOxCThdMax_CutOff_C = 24864U;
CONST(UInt16, ADVSPT_CALIB) IgSys_tOxCThdMin_CutOff_C = 5664U;
CONST(SInt16, ADVSPT_CALIB) IgSys_tqIdcEngCurMinThdNoRcvSC_C = 80;
CONST(SInt16, ADVSPT_CALIB) IgSys_tqIdcEngCurMinThd_NoRcv_C = 80;
CONST(SInt16, ADVSPT_CALIB) IgSys_tqIdcEngCurMinThd_Rcv_C = -80;

#define AdvSpT_STOP_SEC_CALIB_16BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define AdvSpT_START_SEC_CARTO_16BIT
#include "AdvSpT_MemMap.h"

CONST(UInt16, ADVSPT_CARTO) IgSys_rTar_OfsAgIg_A[104] = { 164U, 169U, 174U,
  184U, 195U, 205U, 210U, 215U, 225U, 236U, 241U, 246U, 256U, 266U, 276U, 282U,
  287U, 297U, 307U, 312U, 317U, 328U, 338U, 348U, 353U, 358U, 369U, 379U, 389U,
  399U, 410U, 420U, 425U, 430U, 440U, 451U, 461U, 471U, 481U, 492U, 497U, 502U,
  512U, 522U, 532U, 543U, 553U, 563U, 568U, 573U, 584U, 604U, 614U, 625U, 630U,
  635U, 645U, 655U, 660U, 666U, 676U, 686U, 696U, 701U, 707U, 717U, 727U, 732U,
  737U, 748U, 758U, 768U, 773U, 778U, 788U, 799U, 809U, 814U, 819U, 829U, 840U,
  845U, 850U, 860U, 870U, 881U, 886U, 891U, 901U, 911U, 916U, 922U, 932U, 942U,
  952U, 957U, 963U, 973U, 983U, 988U, 993U, 1004U, 1014U, 1024U } ;

#define AdvSpT_STOP_SEC_CARTO_16BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AdvSpT_START_SEC_CALIB_8BIT
#include "AdvSpT_MemMap.h"

CONST(UInt8, ADVSPT_CALIB) IgSys_agIg80PercTq_B = 96U;
CONST(UInt8, ADVSPT_CALIB) IgSys_agIgOfs80PrecTq_B = 0U;
CONST(UInt8, ADVSPT_CALIB) IgSys_agIgTarWiCllTar_B = 96U;
CONST(UInt8, ADVSPT_CALIB) IgSys_agIgTarWoutAntiJerk_B = 96U;
CONST(UInt8, ADVSPT_CALIB) IgSys_noCylCutOffTar_B = 0U;
CONST(UInt8, ADVSPT_CALIB) IgSys_noCylMaxCutOff_C = 0U;
CONST(UInt8, ADVSPT_CALIB) IgSys_rtqIdcEngCurMinNoRcvSC_C = 25U;
CONST(UInt8, ADVSPT_CALIB) IgSys_rtqIdcEngCurMin_NoRcv_C = 50U;
CONST(UInt8, ADVSPT_CALIB) IgSys_rtqIdcEngCurMin_Rcv_C = 25U;

#define AdvSpT_STOP_SEC_CALIB_8BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AdvSpT_START_SEC_CALIB_BOOLEAN
#include "AdvSpT_MemMap.h"

CONST(Boolean, ADVSPT_CALIB) ADVSPT_ACTIVE_BYP_C = 0;
CONST(Boolean, ADVSPT_CALIB) IgSys_bInh_SelCutOff_C = 0;

#define AdvSpT_STOP_SEC_CALIB_BOOLEAN
#include "AdvSpT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define AdvSpT_START_SEC_CARTO_8BIT
#include "AdvSpT_MemMap.h"

CONST(UInt8, ADVSPT_CARTO) IgSys_agIgTarOfs_OfsAgIg_T[104] = { 152U, 146U,
  142U, 138U, 136U, 130U, 128U, 126U, 124U, 124U, 122U, 120U, 118U, 118U, 116U,
  116U, 114U, 112U, 112U, 110U, 110U, 108U, 108U, 106U, 106U, 104U, 102U, 102U,
  100U, 100U, 98U, 98U, 96U, 96U, 94U, 94U, 94U, 92U, 90U, 90U, 88U, 88U, 88U,
  86U, 84U, 84U, 84U, 82U, 82U, 80U, 80U, 78U, 78U, 76U, 76U, 74U, 74U, 74U, 72U,
  72U, 70U, 70U, 70U, 68U, 68U, 66U, 66U, 66U, 64U, 64U, 62U, 62U, 60U, 60U, 58U,
  58U, 58U, 56U, 56U, 54U, 54U, 52U, 52U, 50U, 50U, 48U, 46U, 46U, 44U, 44U, 42U,
  40U, 40U, 38U, 36U, 34U, 32U, 30U, 28U, 26U, 24U, 20U, 16U, 0U } ;

#define AdvSpT_STOP_SEC_CARTO_8BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define AdvSpT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvSpT_MemMap.h"

VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_agIgTar_AgIg_MP = 0;
VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_agIgTar_MP = 0;
VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_agIg_AntiJerk_MP = 0;
VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_facAgCorSwtTar_MP = 0U;
VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_facTarAgCorSwtAntiJ_MP = 0U;
VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_rTarEfcMux_MP[2] = { 0U, 0U };

VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_rTarEfcWoutAntiJerk_IRV_MP = 0U;
VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_rTarEfc_IRV_MP = 0U;
VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_tSelTCoUsr_MP = 0;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define AdvSpT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvSpT_MemMap.h"

VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_agIgAntiJerkOfs_MP = 0U;
VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_agIgTarOfs_MP = 0U;
VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_noCylCutOffInc_MP = 0U;
VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_noCylCutOffSwt_MP = 0U;
VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_noCylCutOff_MP = 0U;
VAR(UInt8, ADVSPT_INTERNAL_VAR) InjSys_noCylCutOffDly = 0U;
VAR(UInt8, ADVSPT_INTERNAL_VAR) InjSys_noCylCutOffDlyOut = 0U;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvSpT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvSpT_MemMap.h"

VAR(Boolean, ADVSPT_INTERNAL_VAR) InjSys_bCylCutOff = FALSE;
VAR(Boolean, ADVSPT_INTERNAL_VAR) InjSys_bCylCutOffTrig = FALSE;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvSpT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
