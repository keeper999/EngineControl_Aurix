/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuInj                                                  */
/* !Description     : INJECTION MASS PER INJECTION                            */
/*                                                                            */
/* !Module          : mFuInj                                                  */
/*                                                                            */
/* !File            : mFuInj_Def.c                                            */
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
/*   Code generated on: Thu Jul 18 15:02:19 2013                              */
/*   Model name       : mFuInj_AUTOCODE.mdl                                   */
/*   Model version    : 1.302                                                 */
/*   Root subsystem   : /mFuInj                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUINJ/mFuInj_Def.c_v     $*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   29 Jul 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "mFuInj.h"
#include "mFuInj_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define MFUINJ_START_SEC_CALIB_8BIT
#include "mFuInj_MemMap.h"

CONST(UInt8, MFUINJ_CALIB) MFUINJ_u8Inhib = 0U;

#define MFUINJ_STOP_SEC_CALIB_8BIT
#include "mFuInj_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define MFUINJ_START_SEC_CALIB_BOOLEAN
#include "mFuInj_MemMap.h"

CONST(Boolean, MFUINJ_CALIB) InjSys_bAcvInjPatcond_C = 0;

#define MFUINJ_STOP_SEC_CALIB_BOOLEAN
#include "mFuInj_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define MFUINJ_START_SEC_VAR_32BIT
#include "mFuInj_MemMap.h"

VAR(Float32, MFUINJ_VAR) InjSys_mFuInjH1CrkReq;
VAR(Float32, MFUINJ_VAR) InjSys_mFuInjH2CrkReq;
VAR(Float32, MFUINJ_VAR) InjSys_mFuInjS1CrkReq;
VAR(Float32, MFUINJ_VAR) InjSys_mFuInjS2CrkReq;
VAR(UInt32, MFUINJ_VAR) InjSys_mFuReq;
VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjH1Req[2];
VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjH2Req[2];
VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjS1Req[2];
VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjS2Req[2];

#define MFUINJ_STOP_SEC_VAR_32BIT
#include "mFuInj_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define MFUINJ_START_SEC_VAR_16BIT
#include "mFuInj_MemMap.h"

VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH1ReqCyl[6];
VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH1ReqCylPre[6];
VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH2ReqCyl[6];
VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH2ReqCylPre[6];
VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS1ReqCyl[6];
VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS1ReqCylPre[6];
VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS2ReqCyl[6];
VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS2ReqCylPre[6];

#define MFUINJ_STOP_SEC_VAR_16BIT
#include "mFuInj_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define MFUINJ_START_SEC_VAR_8BIT
#include "mFuInj_MemMap.h"

VAR(UInt8, MFUINJ_VAR) InjSys_noCylmFuInjCrk;

#define MFUINJ_STOP_SEC_VAR_8BIT
#include "mFuInj_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define MFUINJ_START_SEC_VAR_BOOLEAN
#include "mFuInj_MemMap.h"

VAR(Boolean, MFUINJ_VAR) InjSys_bEngStall;
VAR(Boolean, MFUINJ_VAR) InjSys_bInhFrstInjSTTCmprCyl;
VAR(Boolean, MFUINJ_VAR) InjSys_bInhFrstInjSTTInCyl;
VAR(Boolean, MFUINJ_VAR) InjSys_bInhSTTSync;
VAR(Boolean, MFUINJ_VAR) InjSys_bInjPatCond;
VAR(Boolean, MFUINJ_VAR) InjSys_bMFuH1SpNull;
VAR(Boolean, MFUINJ_VAR) InjSys_bMFuH2SpNull;
VAR(Boolean, MFUINJ_VAR) InjSys_bMFuS1SpNull;
VAR(Boolean, MFUINJ_VAR) InjSys_bMFuS2SpNull;
VAR(Boolean, MFUINJ_VAR) InjSys_bMufInjTotNull;

#define MFUINJ_STOP_SEC_VAR_BOOLEAN
#include "mFuInj_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
