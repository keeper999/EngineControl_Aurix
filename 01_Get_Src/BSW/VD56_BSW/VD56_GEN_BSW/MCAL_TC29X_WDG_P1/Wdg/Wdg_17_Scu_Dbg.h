 
 /******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Wdg_17_Scu_Dbg.h $                                         **
**                                                                           **
**  $CC VERSION : \main\17 $                                                 **
**                                                                           **
**  $DATE       : 2013-08-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - Debug information of WDG driver for AS 4.0.3             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                           **
******************************************************************************/
 
 
/******************************************************************************/
#ifndef WDG_17_SCU_DBG_H
#define WDG_17_SCU_DBG_H

/******************************************************************************
**                      Includes                                              *
******************************************************************************/

#include "Wdg_17_Scu.h"
/******************************************************************************/
/** Traceability : [cover parentID=DS_AS40X_WDG152, DS_AS40X_WDG153,
    DS_AS40X_WDG154, DS_AS40X_WDG148, DS_AS40X_WDG149, DS_AS40X_WDG150,
    DS_AS40X_WDG151]
    [/cover]                                                                 */
#if(WDG_MAXQM_TIMERS != 0U)
#if (WDG_DEBUG_SUPPORT == STD_ON)

#define WDG_17_SCU_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 Wdg_TimeoutCounter[WDG_MAX_TIMERS];
#define WDG_17_SCU_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define WDG_17_SCU_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* Driver Internal State, Assigned Default state: WDGIF_UNINIT */
extern Wdg_17_Scu_StatusType Wdg_17_Scu_DriverState[WDG_MAX_TIMERS];
/* Driver current mode */
extern WdgIf_ModeType Wdg_17_Scu_DriverMode[WDG_MAX_TIMERS];

#define WDG_17_SCU_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif /* WDG_DEBUG_SUPPORT */
#endif /* WDG_MAXQM_TIMERS */
#endif /* WDG_17_SCU_DBG_H */
