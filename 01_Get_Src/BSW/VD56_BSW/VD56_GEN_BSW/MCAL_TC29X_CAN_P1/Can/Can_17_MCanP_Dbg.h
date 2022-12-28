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
**  $FILENAME   : Can_17_MCanP_Dbg.h $                                       **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2013-06-26 $                                               **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - declarations of debug variables.                        **
**                                                                           **
**  MAY BE CHANGED BY USER [Yes/No]: No                                      **
**                                                                           **
******************************************************************************/



#ifndef CAN_17_MCANP_DBG_H
#define CAN_17_MCANP_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "CanIf.h"
#include "Can_17_MCanP.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

#if (CAN_DEBUG_SUPPORT == STD_ON)

#define CAN_17_MCANP_START_SEC_VAR_8BIT
#include "MemMap.h"

/* CAN controller interrupt disable count */
extern uint8 Can_17_MCanP_InterruptDisableCount[CAN_NUM_CONTROLLER_MAX]; 

#if(CAN_WAKEUP_CONFIGURED == STD_ON)
/* CAN Controller wakeup status */
extern uint8 Can_17_MCanP_ControllerWakeupStatus[CAN_NUM_CONTROLLER_MAX];
#endif

/* CAN driver state */
extern Can_17_MCanP_DriverStateType Can_17_MCanP_DriverState;

#define CAN_17_MCANP_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define CAN_17_MCANP_START_SEC_VAR_32BIT
#include "MemMap.h"

/* Current state of the CAN controller */
extern CanIf_ControllerModeType 
       Can_17_MCanP_ControllerMode[CAN_NUM_CONTROLLER_MAX];

#define CAN_17_MCANP_STOP_SEC_VAR_32BIT
#include "MemMap.h" 

#endif

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* #ifndef CAN_17_MCANP_DBG_H */
