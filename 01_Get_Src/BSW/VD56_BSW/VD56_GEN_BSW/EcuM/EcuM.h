/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ECUM                                                    */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : EcuM.h                                                  */
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
 * %PID: P2017_BSW:0A111740.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Ecum.h                                                        **
**                                                                            **
**  VERSION   : 0.0.2                                                         **
**                                                                            **
**  DATE      : 2012.11.29                                                    **
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
** AT           Angeswaran Thangaswamy                                        ** 
** SKB          Sai Kiran B                                                   ** 
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
  * V0.0.2: 2012.11.29, AT  : Function headers updated
  * V0.0.1: 2011.03.09, SKB : Initial version
*/

#ifndef ECUM_H
#define ECUM_H 


#include "Std_Types.h"
#include "Ecum_Cfg.h"
#ifdef ECUM_USES_CANTRCV_17_6251G
#include "EcuM_Cbk.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#ifndef MCU_USES_FIXED_ADDR
#define MCU_USES_FIXED_ADDR         (OFF)
#endif

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "ECUM_MemMap.h"

extern void EcuM_Init(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitOne                              **
**                                         (const EcuM_ConfigType *configptr) **
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
void EcuM_AL_DriverInitOne(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitTwo                              **
**                                         (const EcuM_ConfigType *configptr) **
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
void EcuM_AL_DriverInitTwo(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitThree                            **
**                                          (const EcuM_ConfigType *configptr)**
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
void EcuM_AL_DriverInitThree(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitZero                             **
**                                          (const EcuM_ConfigType *configptr)**
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
void EcuM_AL_DriverInitZero(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#define ECUM_STOP_SEC_CODE
#include "ECUM_MemMap.h"

#endif /* ECUM_H */

/*-------------------------------- end of file -------------------------------*/
