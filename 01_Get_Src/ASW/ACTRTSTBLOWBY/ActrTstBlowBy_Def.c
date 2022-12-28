/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActrTstBlowBy                                           */
/* !Description     : Test actionneur Blow By                                 */
/*                                                                            */
/* !Module          : ActrTstBlowBy                                           */
/*                                                                            */
/* !File            : ActrTstBlowBy_Def.c                                     */
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
/*   Code generated on: Thu Jan 17 11:16:37 2013                              */
/*   Model name       : ActrTstBlowBy_AUTOCODE.mdl                            */
/*   Model version    : 1.78                                                  */
/*   Root subsystem   : /ActrTstBlowBy                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/ACTRTSTBLOWBY/ActrTstBlowBy_$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   18 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActrTstBlowBy.h"
#include "ActrTstBlowBy_private.h"

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
#define ACTRTSTBLOWBY_START_SEC_CALIB_16BIT
#include "ActrTstBlowBy_MemMap.h"

CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_OffTime_C = 5U;
CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_OnTime_C = 5U;
CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_Tempo_C = 20U;
CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_TotTime_C = 100U;
CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_OffTime_C = 5U;
CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_OnTime_C = 5U;
CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_Tempo_C = 20U;
CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_TotTime_C = 200U;

#define ACTRTSTBLOWBY_STOP_SEC_CALIB_16BIT
#include "ActrTstBlowBy_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define ACTRTSTBLOWBY_START_SEC_VAR_BOOLEAN
#include "ActrTstBlowBy_MemMap.h"

VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bActrTstInProgsBB1;
VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bActrTstInProgsBB2;
VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bBlowBy1ReqActrTst;
VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bBlowBy2ReqActrTst;
VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bBlowByTstCmpl;

#define ACTRTSTBLOWBY_STOP_SEC_VAR_BOOLEAN
#include "ActrTstBlowBy_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define ACTRTSTBLOWBY_START_SEC_VAR_16BIT
#include "ActrTstBlowBy_MemMap.h"

VAR(UInt16, ACTRTSTBLOWBY_VAR) ActrTstBlowBy1_CumulTime;
VAR(UInt16, ACTRTSTBLOWBY_VAR) ActrTstBlowBy1_IntTime;
VAR(UInt16, ACTRTSTBLOWBY_VAR) ActrTstBlowBy1_Tempo;
VAR(UInt16, ACTRTSTBLOWBY_VAR) ActrTstBlowBy2_CumulTime;
VAR(UInt16, ACTRTSTBLOWBY_VAR) ActrTstBlowBy2_IntTime;
VAR(UInt16, ACTRTSTBLOWBY_VAR) ActrTstBlowBy2_Tempo;

#define ACTRTSTBLOWBY_STOP_SEC_VAR_16BIT
#include "ActrTstBlowBy_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define ACTRTSTBLOWBY_START_SEC_VAR_8BIT
#include "ActrTstBlowBy_MemMap.h"

VAR(UInt8, ACTRTSTBLOWBY_VAR) Oil_stActrTstBB1;
VAR(UInt8, ACTRTSTBLOWBY_VAR) Oil_stActrTstBB2;

#define ACTRTSTBLOWBY_STOP_SEC_VAR_8BIT
#include "ActrTstBlowBy_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
