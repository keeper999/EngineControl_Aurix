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
**  $FILENAME   : Wdg_17_Scu_Safe.h $                                        **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-08-15 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionalities of WDG driver           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

 
#ifndef WDG_17_SCU_SAFE_H
#define WDG_17_SCU_SAFE_H

/******************************************************************************
**                      Includes                                              *
******************************************************************************/
  
 

/* Wdg module header file  */
#include "Wdg_17_Scu.h"

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

#define WDG_17_SCU_START_SEC_CODE
#include "MemMap.h"
#if (WDG_MAXSAFE_TIMERS != 0U)
extern void Wdg_lSafetyInit(const Wdg_17_Scu_ConfigType* ConfigPtr);
#endif
#define WDG_17_SCU_STOP_SEC_CODE
#include "MemMap.h"



/******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/




#endif /* WDG_17_SCU_SAFE_H */
