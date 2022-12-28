/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstFuPmp                                             */
/* !Description     : Test actionneur Pompe de Gavage                         */
/*                                                                            */
/* !Module          : ActTstFuPmp                                             */
/*                                                                            */
/* !File            : ActTstFuPmp_Def.c                                       */
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
/*   Code generated on: Tue Sep 27 15:48:17 2011                              */
/*   Model name       : ActTstFuPmp_AUTOCODE.mdl                              */
/*   Model version    : 1.65                                                  */
/*   Root subsystem   : /ActTstFuPmp                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUPMP/ACTTSTFUPMP/ActTstFuPmp_De$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Oct 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActTstFuPmp.h"
#include "ActTstFuPmp_private.h"

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
#define ACTTSTFUPMP_START_SEC_CALIB_16BIT
#include "ActTstFuPmp_MemMap.h"

CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_OffTime_C = 13U;
CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_OnTime_C = 13U;
CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_Tempo_C = 5U;
CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_TotTime_C = 250U;
CONST(UInt16, ACTTSTFUPMP_CALIB) FuPmp_rSpPosnActrTstPos1_C = 1000U;
CONST(UInt16, ACTTSTFUPMP_CALIB) FuPmp_rSpPosnActrTstPos2_C = 0U;

#define ACTTSTFUPMP_STOP_SEC_CALIB_16BIT
#include "ActTstFuPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define ACTTSTFUPMP_START_SEC_VAR_16BIT
#include "ActTstFuPmp_MemMap.h"

VAR(UInt16, ACTTSTFUPMP_VAR) ActrTstFuTnkPmp_CumulTime;
VAR(UInt16, ACTTSTFUPMP_VAR) ActrTstFuTnkPmp_IntTime;
VAR(UInt16, ACTTSTFUPMP_VAR) ActrTstFuTnkPmp_Tempo;
VAR(UInt16, ACTTSTFUPMP_VAR) FuPmp_rSpPosnActrTst;

#define ACTTSTFUPMP_STOP_SEC_VAR_16BIT
#include "ActTstFuPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define ACTTSTFUPMP_START_SEC_VAR_BOOLEAN
#include "ActTstFuPmp_MemMap.h"

VAR(Boolean, ACTTSTFUPMP_VAR) FuPmp_bActrTstInProgs;
VAR(Boolean, ACTTSTFUPMP_VAR) FuPmp_bFuTnkPmpTstCmpl;

#define ACTTSTFUPMP_STOP_SEC_VAR_BOOLEAN
#include "ActTstFuPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define ACTTSTFUPMP_START_SEC_VAR_8BIT
#include "ActTstFuPmp_MemMap.h"

VAR(UInt8, ACTTSTFUPMP_VAR) FuPmp_stActrTst;

#define ACTTSTFUPMP_STOP_SEC_VAR_8BIT
#include "ActTstFuPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
