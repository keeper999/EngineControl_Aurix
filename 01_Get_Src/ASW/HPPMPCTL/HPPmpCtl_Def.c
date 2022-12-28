/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpCtl                                                */
/* !Description     : HPPmpCtl - RÉGULATION DE LA PRESSION RAIL               */
/*                                                                            */
/* !Module          : HPPmpCtl                                                */
/*                                                                            */
/* !File            : HPPmpCtl_Def.c                                          */
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
/*   Code generated on: Tue Jul 10 10:40:13 2012                              */
/*   Model name       : HPPmpCtl_AUTOCODE.mdl                                 */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /HPPmpCtl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPCTL/HPPmpCtl_Def.c_v$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpCtl.h"
#include "HPPmpCtl_private.h"

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
#define HPPMPCTL_START_SEC_CALIB_16BIT
#include "HPPmpCtl_MemMap.h"

CONST(UInt16, HPPMPCTL_CALIB) InjrSys_mFuInjEstim_A[7] = { 0U, 13U, 34U, 54U,
  74U, 94U, 107U } ;

CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainD1PFuCtl_T[16] = { 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U } ;

CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainD2PFuCtl_T[16] = { 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U } ;

CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainIPFuCtl_M[112] = { 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U, 367U,
  367U, 367U, 367U, 367U, 367U, 367U } ;

CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainPPFuCtl_M[112] = { 65535U, 65535U,
  65535U, 65535U, 51118U, 34079U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U,
  17039U, 17039U, 17039U, 17039U, 65535U, 65535U, 65535U, 65535U, 51118U, 34079U,
  17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U,
  65535U, 65535U, 65535U, 65535U, 51118U, 34079U, 17039U, 17039U, 17039U, 17039U,
  17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 65535U, 65535U, 65535U, 65535U,
  51118U, 34079U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U,
  17039U, 17039U, 65535U, 65535U, 65535U, 65535U, 51118U, 34079U, 17039U, 17039U,
  17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 65535U, 65535U,
  65535U, 65535U, 51118U, 34079U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U,
  17039U, 17039U, 17039U, 17039U, 65535U, 65535U, 65535U, 65535U, 51118U, 34079U,
  17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U, 17039U
} ;

CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_nEng1_A[16] = { 500U, 700U, 850U, 1000U,
  1250U, 1500U, 1750U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 6000U,
  6500U } ;

CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifAcvClCtlDft_C = 2560U;
CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifAcvClCtl_C = 2560U;
CONST(SInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifReqETB_C = 64;
CONST(SInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifStep1ETB_C = 256;
CONST(SInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifStep2ETB_C = 128;
CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDif_A[5] = { 28928U, 32128U,
  32768U, 33408U, 36608U } ;

CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pRailRampMaxETB_C = 51200U;
CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_tiPFuDifStep1ETB_C = 13U;
CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_tiPFuDifStep2ETB_C = 13U;

#define HPPMPCTL_STOP_SEC_CALIB_16BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define HPPMPCTL_START_SEC_CALIB_8BIT
#include "HPPmpCtl_MemMap.h"

CONST(UInt8, HPPMPCTL_CALIB) HPPMPCTL_u8Inhib = 0U;
CONST(UInt8, HPPMPCTL_CALIB) PFuCtl_facWErrGainPPFuCtl_T[5] = { 50U, 50U, 50U,
  50U, 50U } ;

CONST(UInt8, HPPMPCTL_CALIB) PFuCtl_noTDCPmpStk_C = 1U;

#define HPPMPCTL_STOP_SEC_CALIB_8BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define HPPMPCTL_START_SEC_CALIB_BOOLEAN
#include "HPPmpCtl_MemMap.h"

CONST(Boolean, HPPMPCTL_CALIB) PFuCtl_bAcvETBPFuClCtl_C = 0;
CONST(Boolean, HPPMPCTL_CALIB) PFuCtl_bAcvRstIFuRailCtl_C = 0;
CONST(Boolean, HPPMPCTL_CALIB) PFuCtl_bSelETBpFuRailDifReq_C = 1;

#define HPPMPCTL_STOP_SEC_CALIB_BOOLEAN
#include "HPPmpCtl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define HPPMPCTL_START_SEC_VAR_32BIT
#include "HPPmpCtl_MemMap.h"

VAR(Float32, HPPMPCTL_VAR) PFuCtl_facGainPPFuCtlErrCor_MP;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_facGainPPFuCtlErrW_MP;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_facGainPPFuCtl_MP;
VAR(UInt32, HPPMPCTL_VAR) PFuCtl_mFuPmpReq;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_mFuPmpReqCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_mFuPmpReqOpl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifClCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifDClCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifDClCtl_prev;
VAR(SInt32, HPPMPCTL_VAR) PFuCtl_pFuRailDifIClCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifIClCtl_prev;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifIncIClCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifOplCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifOplCtl_prev;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifPClCtl;
VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDif_prev;

#define HPPMPCTL_STOP_SEC_VAR_32BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define HPPMPCTL_START_SEC_VAR_16BIT
#include "HPPmpCtl_MemMap.h"

VAR(SInt16, HPPMPCTL_VAR) PFuCtl_pFuRailDif;
VAR(UInt16, HPPMPCTL_VAR) PFuCtl_tiETB;
VAR(UInt16, HPPMPCTL_VAR) PFuCtl_tiETB_Prev;

#define HPPMPCTL_STOP_SEC_VAR_16BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define HPPMPCTL_START_SEC_VAR_BOOLEAN
#include "HPPmpCtl_MemMap.h"

VAR(Boolean, HPPMPCTL_VAR) PFuCtl_bAcvETBPFuOplCtl;
VAR(Boolean, HPPMPCTL_VAR) PFuCtl_bAcvIFrzPrailDif;
VAR(Boolean, HPPMPCTL_VAR) PFuCtl_bPFuRailClCtlIni;

#define HPPMPCTL_STOP_SEC_VAR_BOOLEAN
#include "HPPmpCtl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
