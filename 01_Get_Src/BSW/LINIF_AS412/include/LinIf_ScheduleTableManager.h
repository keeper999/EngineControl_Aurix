/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                    */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_ScheduleTableManager                              */
/*!Description     : The "ScheduleTableManager" subcomponent header file.     */
/*                                                                            */
/*!\File             LinIf_ScheduleTableManager.h                             */
/* \par              The "ScheduleTableManager" subcomponent header file.    */
/*!Scope           : Private component                                       */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.5      $$Author::   mnabil         $$Date::   Jan 29 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_SCHEDULETABLEMANAGER_H
#define LINIF_SCHEDULETABLEMANAGER_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf_Types.h"
#include "LinIf_Types_Internal.h"
#include "LinIf_Cfg.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define LINIF_START_SEC_CODE
#include "Memmap.h"

extern FUNC(void, LINIF_CODE) LinIf_vidSTMInit(
   VAR(uint8, AUTOMATIC) u8ChannelIndex);


extern FUNC(void, LINIF_CODE) LinIf_vidSTMMain(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, AUTOMATIC) pkstrChannel);


extern FUNC(void, LINIF_CODE) LinIf_vidSTMTxConf(
   VAR(uint8, AUTOMATIC) u8ChannelIndex
);

extern FUNC(void, LINIF_CODE) LinIf_vidSTMRxInd(
   VAR(uint8, AUTOMATIC) u8ChannelIndex
);


extern FUNC(void, LINIF_CODE) LinIf_vidSTMHandlEvtTrigErr(
   VAR(uint8, AUTOMATIC) u8ChannelIndex);

extern FUNC(void, LINIF_CODE) LinIf_vidSTMSetNullSchedule(
   VAR(uint8, AUTOMATIC) u8ChannelIndex);

#define LINIF_STOP_SEC_CODE
#include "Memmap.h"

#endif /* LINIF_SCHEDULETABLEMANAGER_H */

/*-------------------------------- end of file -------------------------------*/
