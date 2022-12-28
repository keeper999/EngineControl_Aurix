/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActrTstHPPmp                                            */
/* !Description     : ACTRTSTHPPmp- HP PUMP ACTUATOR TEST                     */
/*                                                                            */
/* !Module          : ActrTstHPPmp                                            */
/*                                                                            */
/* !File            : ActrTstHPPmp_Def.c                                      */
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
/*   Code generated on: Tue Mar 05 11:01:47 2013                              */
/*   Model name       : ActrTstHPPmp_AUTOCODE.mdl                             */
/*   Model version    : 1.89                                                  */
/*   Root subsystem   : /ActrTstHPPmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/ACTRTSTHPPMP/ActrTstHPPmp$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   08 Mar 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActrTstHPPmp.h"
#include "ActrTstHPPmp_private.h"

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
#define ACTRTSTHPPMP_START_SEC_CALIB_16BIT
#include "ActrTstHPPmp_MemMap.h"

CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_Tempo2_C = 40U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_TempoMax_C = 120U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_Tempo_Phase1_C = 20U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_agWdReq_C = 107U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailPerPmp_C = 0U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailPresDif2_C = 512U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailSpThdHi_C = 1344U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailSpThdLo_C = 1280U;
CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailSpThd_C = 1408U;

#define ACTRTSTHPPMP_STOP_SEC_CALIB_16BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define ACTRTSTHPPMP_START_SEC_CALIB_8BIT
#include "ActrTstHPPmp_MemMap.h"

CONST(UInt8, ACTRTSTHPPMP_CALIB) ACTRTSTHPPMP_u8Inhib = 0U;
CONST(UInt8, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_ctRstActTst_C = 5U;

#define ACTRTSTHPPMP_STOP_SEC_CALIB_8BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_32BIT
#include "ActrTstHPPmp_MemMap.h"

VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase0;
VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase1;
VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase1Bis;
VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase2;
VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase3;
VAR(Float32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pRailPerPmp;

#define ACTRTSTHPPMP_STOP_SEC_VAR_32BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_16BIT
#include "ActrTstHPPmp_MemMap.h"

VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_agWdPmpCmdReq;
VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesBeg1;
VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesBeg2;
VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesEnd1;
VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesEnd2;
VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pRailPresDif2;
VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pRailPresDiff;

#define ACTRTSTHPPMP_STOP_SEC_VAR_16BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_8BIT
#include "ActrTstHPPmp_MemMap.h"

VAR(UInt8, ACTRTSTHPPMP_VAR) ActrTstHPPmp_ctRstActTst;
VAR(UInt8, ACTRTSTHPPMP_VAR) ActrTstHPPmp_stActrTst;

#define ACTRTSTHPPMP_STOP_SEC_VAR_8BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define ACTRTSTHPPMP_START_SEC_VAR_BOOLEAN
#include "ActrTstHPPmp_MemMap.h"

VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bActrTstCmpl;
VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bActrTstInProgs;
VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bInjAuthReq;
VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bItActrTstReq;
VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bPrailLeak;
VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bPrailPresIncFail;

#define ACTRTSTHPPMP_STOP_SEC_VAR_BOOLEAN
#include "ActrTstHPPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
