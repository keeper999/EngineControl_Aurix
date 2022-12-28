
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
**  $FILENAME   : Wdg_17_Scu_Cbk.h $                                         **
**                                                                           **
**  $CC VERSION : \main\10 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-16 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains call back function of WDG driver        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef WDG_17_SCU_CBK_H
#define WDG_17_SCU_CBK_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#if(WDG_MAXQM_TIMERS != 0U)
#define WDG_17_SCU_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax           : void Wdg_17_Scu_Cbk_GtmNotifySRV(uint8 ModuleType,      **
**                     int8 ModuleNo,uint8 ChannelNo,uint16 IrqNotifVal)      **
**                                                                            **
** Service ID       : 5                                                       **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Callback function for SRV timer.                        **
**                    This function is called if SRV timer is expired and     **
**                    triggers the Watchdog hardware timer if Timeout counter **
**                    value has not reached zero.                             **
**                                                                            **
*******************************************************************************/
extern void Wdg_17_Scu_Cbk_GtmNotifySRV(uint8 ModuleType, uint8 ModuleNo,
                                   uint8 ChannelNo,uint16 IrqNotifVal);
#define WDG_17_SCU_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"
#endif /* WDG_MAXQM_TIMERS */
#endif /* WDG_17_SCU_CBK_H */
