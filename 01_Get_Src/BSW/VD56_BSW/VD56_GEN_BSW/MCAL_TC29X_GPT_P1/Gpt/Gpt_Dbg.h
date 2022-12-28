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
**  $FILENAME   : Gpt_Dbg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-08-21 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains GPT debug variable declarations.        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef GPT_DBG_H
#define GPT_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Gpt.h"

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

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#if  ( GPT_DEBUG_SUPPORT == STD_ON )


#define GPT_START_SEC_VAR_8BIT
#include "MemMap.h"
/* Variable to store channel status i.e. Channel Initilaized/started/stopped/
    expired */
#if( GPT_SAFETY_ENABLE == STD_ON)
#if (GPT_MAX_ASIL_CHANNELS != 0U)
extern uint8 Gpt_AsilChannelStatus[GPT_MAX_ASIL_CHANNELS];
#endif
#endif
#if (GPT_MAX_QM_CHANNELS != 0U)
extern uint8 Gpt_QMChannelStatus[GPT_MAX_QM_CHANNELS];
#endif
/* Driver current mode (GPT_MODE_SLEEP/GPT_MODE_NORMAL) */
extern volatile uint8 Gpt_DriverMode;
  
#define GPT_STOP_SEC_VAR_8BIT
#include "MemMap.h"


#endif


#endif /* GPT_DBG_H */
