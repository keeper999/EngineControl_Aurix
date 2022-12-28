/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstTrbWaPmp                                          */
/* !Description     : Test actionneur Pompe à Eau Turbo                       */
/*                                                                            */
/* !Module          : ActTstTrbWaPmp                                          */
/*                                                                            */
/* !File            : ActTstTrbWaPmp_Def.c                                    */
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
/*   Code generated on: Sun Oct 02 10:12:20 2011                              */
/*   Model name       : ActTstTrbWaPmp_AUTOCODE.mdl                           */
/*   Model version    : 1.32                                                  */
/*   Root subsystem   : /ActTstTrbWaPmp                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ACTTSTTRBWAPMP/ActTstTrbWaPmp_De$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   14 Oct 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActTstTrbWaPmp.h"
#include "ActTstTrbWaPmp_private.h"

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
#define ACTTSTTRBWAPMP_START_SEC_CALIB_16BIT
#include "ActTstTrbWaPmp_MemMap.h"

CONST(UInt16, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_Tempo_C = 20U;
CONST(UInt16, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_TotTime_C = 20U;

#define ACTTSTTRBWAPMP_STOP_SEC_CALIB_16BIT
#include "ActTstTrbWaPmp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define ACTTSTTRBWAPMP_START_SEC_CALIB_8BIT
#include "ActTstTrbWaPmp_MemMap.h"

CONST(UInt8, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_OffTime_C = 5U;
CONST(UInt8, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_OnTime_C = 5U;

#define ACTTSTTRBWAPMP_STOP_SEC_CALIB_8BIT
#include "ActTstTrbWaPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define ACTTSTTRBWAPMP_START_SEC_VAR_BOOLEAN
#include "ActTstTrbWaPmp_MemMap.h"

VAR(Boolean, ACTTSTTRBWAPMP_VAR) ThMgt_bActrTstInProgs;
VAR(Boolean, ACTTSTTRBWAPMP_VAR) ThMgt_bTrbWaPmpReqActrTst;
VAR(Boolean, ACTTSTTRBWAPMP_VAR) ThMgt_bTrbWaPmpTstCmpl;

#define ACTTSTTRBWAPMP_STOP_SEC_VAR_BOOLEAN
#include "ActTstTrbWaPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define ACTTSTTRBWAPMP_START_SEC_VAR_16BIT
#include "ActTstTrbWaPmp_MemMap.h"

VAR(UInt16, ACTTSTTRBWAPMP_VAR) ActrTstTrbWaPmp_CumulTime;
VAR(UInt16, ACTTSTTRBWAPMP_VAR) ActrTstTrbWaPmp_Tempo;

#define ACTTSTTRBWAPMP_STOP_SEC_VAR_16BIT
#include "ActTstTrbWaPmp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define ACTTSTTRBWAPMP_START_SEC_VAR_8BIT
#include "ActTstTrbWaPmp_MemMap.h"

VAR(UInt8, ACTTSTTRBWAPMP_VAR) ActrTstTrbWaPmp_IntTime;
VAR(UInt8, ACTTSTTRBWAPMP_VAR) ThMgt_stActrTst;

#define ACTTSTTRBWAPMP_STOP_SEC_VAR_8BIT
#include "ActTstTrbWaPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
