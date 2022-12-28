/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstCtlPmp                                            */
/* !Description     : Test actionneur Electrovanne Pompe à Huile              */
/*                                                                            */
/* !Module          : ActTstCtlPmp                                            */
/*                                                                            */
/* !File            : ActTstCtlPmp_Def.c                                      */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Tue Sep 27 14:15:26 2011                              */
/*   Model name       : ActTstCtlPmp_AUTOCODE.mdl                             */
/*   Model version    : 1.27                                                  */
/*   Root subsystem   : /ActTstCtlPmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/ACTTSTCTLPMP/ActTstCtlPmp_De$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   17 Oct 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActTstCtlPmp.h"
#include "ActTstCtlPmp_private.h"

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
#define ACTTSTCTLPMP_START_SEC_CALIB_16BIT
#include "ActTstCtlPmp_MemMap.h"

CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_OffTime_C = 50U;
CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_OnTime_C = 50U;
CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_Tempo_C = 200U;
CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_TotTime_C = 200U;

#define ACTTSTCTLPMP_STOP_SEC_CALIB_16BIT
#include "ActTstCtlPmp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define ACTTSTCTLPMP_START_SEC_CALIB_8BIT
#include "ActTstCtlPmp_MemMap.h"

CONST(UInt8, ACTTSTCTLPMP_CALIB) Oil_rSpPosnActrTstPos1_C = 255U;
CONST(UInt8, ACTTSTCTLPMP_CALIB) Oil_rSpPosnActrTstPos2_C = 0U;

#define ACTTSTCTLPMP_STOP_SEC_CALIB_8BIT
#include "ActTstCtlPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define ACTTSTCTLPMP_START_SEC_VAR_BOOLEAN
#include "ActTstCtlPmp_MemMap.h"

VAR(Boolean, ACTTSTCTLPMP_VAR) Oil_bActrTstInProgs;
VAR(Boolean, ACTTSTCTLPMP_VAR) Oil_bCtlPmpTstCmpl;

#define ACTTSTCTLPMP_STOP_SEC_VAR_BOOLEAN
#include "ActTstCtlPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define ACTTSTCTLPMP_START_SEC_VAR_8BIT
#include "ActTstCtlPmp_MemMap.h"

VAR(UInt8, ACTTSTCTLPMP_VAR) Oil_rSpPosnActrTst;
VAR(UInt8, ACTTSTCTLPMP_VAR) Oil_stActrTst;

#define ACTTSTCTLPMP_STOP_SEC_VAR_8BIT
#include "ActTstCtlPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define ACTTSTCTLPMP_START_SEC_VAR_16BIT
#include "ActTstCtlPmp_MemMap.h"

VAR(UInt16, ACTTSTCTLPMP_VAR) ActrTstCtlPmp_CumulTime;
VAR(UInt16, ACTTSTCTLPMP_VAR) ActrTstCtlPmp_IntTime;
VAR(UInt16, ACTTSTCTLPMP_VAR) ActrTstCtlPmp_Tempo;

#define ACTTSTCTLPMP_STOP_SEC_VAR_16BIT
#include "ActTstCtlPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
