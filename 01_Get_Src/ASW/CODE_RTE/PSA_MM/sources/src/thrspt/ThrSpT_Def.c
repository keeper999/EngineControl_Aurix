/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ThrSpT                                                  */
/* !Description     : ThrSpT Software Component                               */
/*                                                                            */
/* !Module          : ThrSpT                                                  */
/*                                                                            */
/* !File            : ThrSpT_Def.c                                            */
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
/*   Model name       : ThrSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /ThrSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M09-ThrSpT/5-SOF$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   plchinaz                               $$Date::   03 May 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ThrSpT.h"
#include "ThrSpT_private.h"

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
#define ThrSpT_START_SEC_CALIB_16BIT
#include "ThrSpT_MemMap.h"

CONST(SInt16, THRSPT_CALIB) ThrSys_arMaxSpdAdpThr_C = 520;
CONST(SInt16, THRSPT_CALIB) ThrSys_arMinSpdAdpThr_C = -520;
CONST(UInt16, THRSPT_CALIB) ThrSys_arStepSpdAdpThr_C = 31U;
CONST(UInt16, THRSPT_CALIB) ThrSys_rOpThrReq_B = 0U;
CONST(UInt16, THRSPT_CALIB) ThrSys_tiDlyStabSign_mAirInt_C = 2040U;

#define ThrSpT_STOP_SEC_CALIB_16BIT
#include "ThrSpT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define ThrSpT_START_SEC_CALIB_BOOLEAN
#include "ThrSpT_MemMap.h"

CONST(Boolean, THRSPT_CALIB) THRSPT_ACTIVE_BYP_C = 0;

#define ThrSpT_STOP_SEC_CALIB_BOOLEAN
#include "ThrSpT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define ThrSpT_START_SEC_INTERNAL_VAR_32BIT
#include "ThrSpT_MemMap.h"

VAR(Float32, THRSPT_INTERNAL_VAR) ThrSys_arOpEffThrOfs = 0.0F;
VAR(SInt32, THRSPT_INTERNAL_VAR) ThrSys_arSpdAdpThr_IRV_MP = 0;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_32BIT
#include "ThrSpT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define ThrSpT_START_SEC_INTERNAL_VAR_16BIT
#include "ThrSpT_MemMap.h"

VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_arThrCor_MP = 0U;
VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNom = 0U;
VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNomRef2_MP = 0U;
VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNomRef3_MP = 0U;
VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNomSat_MP = 0U;
VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_tiStabSign_mAirInt = 0U;
VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_tiStabSign_mIntPrev = 0U;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_16BIT
#include "ThrSpT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define ThrSpT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ThrSpT_MemMap.h"

VAR(Boolean, THRSPT_INTERNAL_VAR) ThrSys_bAcvSpdAdpThr = FALSE;
VAR(Boolean, THRSPT_INTERNAL_VAR) ThrSys_bAdpThrSign_mAirInt = FALSE;
VAR(Boolean, THRSPT_INTERNAL_VAR) ThrSys_bAdpThrSign_mIntPrev = FALSE;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ThrSpT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
