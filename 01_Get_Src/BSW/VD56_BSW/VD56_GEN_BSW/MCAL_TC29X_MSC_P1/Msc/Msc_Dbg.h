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
**  $FILENAME   : Msc_Dbg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\4 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                 - Debug information of MSC driver.                        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef MSC_DBG_H
#define MSC_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Msc.h"

/*******************************************************************************
**                            Global Variables                               **
*******************************************************************************/
#if ( MSC_DEBUG_SUPPORT == STD_ON )

#define MSC_START_SEC_VAR_8BIT
#include "MemMap.h"

extern uint8 Msc_DriverState;

#define MSC_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif /* End of MSC_DEBUG_SUPPORT */

#endif /* MSC_DBG_H */
