/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : agPmpRefPFuM                                            */
/* !Description     : CALCULATION OF THE ANGULAR REFERENCES FOR THE PUMP STRIKES (GDI)*/
/*                                                                            */
/* !Module          : agPmpRefPFuM                                            */
/*                                                                            */
/* !File            : agPmpRefPFuM_Def.c                                      */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Thu Sep 12 10:58:54 2013                              */
/*   Model name       : agPmpRefPFuM_AUTOCODE.mdl                             */
/*   Model version    : 1.77                                                  */
/*   Root subsystem   : /agPmpRefPFuM                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/agPmpRefPFuM/5-SOFT-LIV/agPm$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Sep 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "agPmpRefPFuM.h"
#include "agPmpRefPFuM_private.h"

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
#define AGPMPREFPFUM_START_SEC_CALIB_16BIT
#include "agPmpRefPFuM_MemMap.h"

CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_agBtwTDCRef_C = 1920U;
CONST(SInt16, AGPMPREFPFUM_CALIB) FuSysM_agConvSplRefEveInj_C = 1237;
CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_agDlyPmpStk_T[16] = { 0U, 26U, 51U,
  77U, 102U, 128U, 154U, 179U, 205U, 230U, 256U, 282U, 307U, 333U, 358U, 384U } ;

CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_agPerPmpRef_C = 2560U;
CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_nEng_A[16] = { 0U, 400U, 800U, 1200U,
  1600U, 2000U, 2400U, 2800U, 3200U, 3600U, 4000U, 4400U, 4800U, 5200U, 5600U,
  6000U } ;

#define AGPMPREFPFUM_STOP_SEC_CALIB_16BIT
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define AGPMPREFPFUM_START_SEC_CALIB_8BIT
#include "agPmpRefPFuM_MemMap.h"

CONST(UInt8, AGPMPREFPFUM_CALIB) AGPMPREFPFUM_u8Inhib = 0U;
CONST(UInt8, AGPMPREFPFUM_CALIB) FuSysM_ctTDCRefPmpCmd_C = 1U;
CONST(UInt8, AGPMPREFPFUM_CALIB) FuSysM_noTDCBtwPmpStk_C = 1U;

#define AGPMPREFPFUM_STOP_SEC_CALIB_8BIT
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define AGPMPREFPFUM_START_SEC_CALIB_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"

CONST(Boolean, AGPMPREFPFUM_CALIB) FuSysM_bCfPmpOneTDCStk_C = 1;

#define AGPMPREFPFUM_STOP_SEC_CALIB_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define AGPMPREFPFUM_START_SEC_VAR_32BIT
#include "agPmpRefPFuM_MemMap.h"

VAR(SInt32, AGPMPREFPFUM_VAR) FuSysM_mFuPmpStk1Req;
VAR(SInt32, AGPMPREFPFUM_VAR) FuSysM_mFuPmpStk2Req;

#define AGPMPREFPFUM_STOP_SEC_VAR_32BIT
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define AGPMPREFPFUM_START_SEC_VAR_16BIT
#include "agPmpRefPFuM_MemMap.h"

VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agBegPmpStk1Ref;
VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agBegPmpStk2Ref;
VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agEndPmpStk1Ref;
VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agEndPmpStk2Ref;

#define AGPMPREFPFUM_STOP_SEC_VAR_16BIT
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define AGPMPREFPFUM_START_SEC_VAR_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"

VAR(Boolean, AGPMPREFPFUM_VAR) FuSysM_bAcvPmpCmdTDCCur;

#define AGPMPREFPFUM_STOP_SEC_VAR_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
