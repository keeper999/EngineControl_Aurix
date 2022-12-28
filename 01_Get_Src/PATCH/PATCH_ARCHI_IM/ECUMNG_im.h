/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ECUMNG                                                */
/* !Description     : ECUMNG Component.                                     */
/*                                                                            */
/* !Module          : ECUMNG                                                */
/* !Description     : interface du module  ECUMNG                           */
/*                                                                            */
/* !File            : ECUMNG_IM.H                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/ECUM$*/
/* $Revision::   1.1 $$Author::   ynicaise       $$Date::   13 Oct 2$  */
/* $Author::   ynicaise                          $$Date::   13 Oct 2$  */
/******************************************************************************/
#ifndef ECUMNG_IM_H
#define ECUMNG_IM_H

#include "TUNCFG.h"
#include "DCM_MANU.h"
#include "ACQWKUSIG.h"
#include "WKU.h"
#include "IFAIRSYSIGSYS.h"
#include "RSTSRV.h"
#include "SAIMMO.h"
#include "GDGAR.h"
#include "FRM.h"
#include "FHCANF552.h"
#include "JDD.h"
#include "NOPROD.h"
#include "IFRTE.h"
#include "DIOHAL.h"
#include "NVMSRV.h"
#include "ISCAN.h"

#include "MATHSRV.h"

/* A voir avec FTOU */
/* call ECUMNG */
#undef EcuSt_EveEcuSt_EcuMng
#define EcuSt_EveEcuSt_EcuMng()\
do \
{ \
   ISCAN_EveEcuSt_TxFrame788();\
 } \
while (0)

#undef EcuSt_EveFct_WaitForPwrl
#define EcuSt_EveFct_WaitForPwrl()\
do \
{ \
   EcuSt_EveFct_PwrlMrk(); /* V02NT1104404 */\
 } \
while (0)

/* Issues VEMS V02 ECU#058267 */
#define RCD_PARTIAL_WAKEUP                RTE_MODE_RCD_Mode_PARTIAL_WAKEUP
#define RCD_INTERNAL_PARTIAL_WAKEUP       RTE_MODE_RCD_Mode_INTERNAL_PARTIAL_WAKEUP
#define RCD_MAIN_WAKEUP                   RTE_MODE_RCD_Mode_MAIN_WAKEUP
#define RCD_MAIN_WAKEUP_APC               RTE_MODE_RCD_Mode_MAIN_WAKEUP_APC
#define RCD_DEGRADED_MAIN_WAKEUP          RTE_MODE_RCD_Mode_DEGRADED_MAIN_WAKEUP
#define RCD_INTERNAL_PARTIAL_WAKEUP_APC   RTE_MODE_RCD_Mode_INTERNAL_PARTIAL_WAKEUP_APC
#define RCD_TRANSITORY                    RTE_MODE_RCD_Mode_TRANSITORY
#define RCD_SHUTDOWN_PREPARATION          RTE_MODE_RCD_Mode_SHUTDOWN_PREPARATION
#define RCD_COM_LATCH                     RTE_MODE_RCD_Mode_COM_LATCH
#define RCD_SHUTDOWN_PREPARATION_APC      RTE_MODE_RCD_Mode_SHUTDOWN_PREPARATION_APC

#endif /*ECUMNG_IM_H */
/*-------------------------------- end of file -------------------------------*/
