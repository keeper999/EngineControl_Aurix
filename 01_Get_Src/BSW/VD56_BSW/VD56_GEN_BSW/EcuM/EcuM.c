/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ECUM                                                    */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : EcuM.c                                                  */
/* !Description     : This file contains APIs of ECU State Manager            */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A111742.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : EcuM.c                                                        **
**                                                                            **
**  VERSION   : 0.0.3                                                         **
**                                                                            **
**  DATE      : 2013.02.26                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Independent                                                   **
**                                                                            **
**  COMPILER  : Independent                                                   **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Contains a simple example of ECU State Manager Code        **
**                 This file is for Evaluation Purpose Only                   **
**                                                                            **
**  SPECIFICATION(S) : Specification of ECU State Manager V3.0.0              **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** AT        Angeswaran Thangaswamy                                           **
** SKB       Sai Kiran B                                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
  * V0.0.3: 2013.02.26, AT : Updated for MultiCore Demo
  * V0.0.2: 2012.11.29, AT : Unused param warnings removed
  * V0.0.1: 2008.04.04, SKB : Initial version-Adapted from PB-1798
*/

#include "Std_Types.h"
#include "EcuM.h"
#include "EcuM_Cbk.h"
#include "Mcu.h"

#define ECUM_START_SEC_CODE
#include "ECUM_MemMap.h"

/*******************************************************************************
** Syntax           : void EcuM_Init(const EcuM_ConfigType *configptr)        **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_Init(const EcuM_ConfigType *configptr) 
{
   volatile uint32 u32LocalConfError;
  
   u32LocalConfError = 0;
  
   /* Check Consistency of configuration data */
   if(EcuM_ConfigConsistencyHash != configptr->PreCompileIdentifier) 
   {
      /* printf("Configuration mismatch!!!\n"); */
      u32LocalConfError = 2;
   }
   if (u32LocalConfError != 0)  
   {
      /* print_f("\nConfiguration Problem\n "); */
   }
           
   /* Initialize DET Module */
   Det_Init();
  
   /* Pre-Initialize DEM Module */
   /*Dem_PreInit() // dbg */

   /* Start Det component running */
   Det_Start();

   /* Call Driver Init Zero. Initialize drivers before OS Init */
   /* No parameters for this function, call modules like DET or 
      pre compile, LT modules */
   EcuM_AL_DriverInitZero();
  
   /* List one is mandated with MCU configuration */
   /* Initialize MCU Driver */
   #if(MCU_USES_FIXED_ADDR == ON)
   Mcu_Init(&Mcu_ConfigRoot[0]);
   #else
   Mcu_Init(configptr->Mcu_ConfigData);
   #endif
     
   /* Call Driver Init One. Initialize drivers before OS Init */
   EcuM_AL_DriverInitOne(configptr);
  
   /* Select Shut Down Target */
  
   /* Call OS */  
 
   /* Call Driver Init Two. Initialize drivers after OS Init */
   EcuM_AL_DriverInitTwo(configptr);
   /* Call Driver Init Three. Initialize drivers after OS Init */
   EcuM_AL_DriverInitThree(configptr);

}

/*******************************************************************************
** Syntax           : void EcuM_SetWakeupEvent(EcuM_WakeupSourceType events)  **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType WakeupInfo)
{
   COMPILER_UNUSED_PARAMETER(WakeupInfo);
}

/*******************************************************************************
** Syntax           : void EcuM_ValidateWakeupEvent                           **
**                    (EcuM_WakeupSourceType events)                          **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType events)
{
   COMPILER_UNUSED_PARAMETER(events);
}

/*******************************************************************************
** Syntax           : void EcuM_CheckWakeup                                   **
**                    (EcuM_WakeupSourceType wakeupSource)                    **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : wakeupSource                                            **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
   COMPILER_UNUSED_PARAMETER(wakeupSource);
}

#define ECUM_STOP_SEC_CODE
#include "ECUM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
