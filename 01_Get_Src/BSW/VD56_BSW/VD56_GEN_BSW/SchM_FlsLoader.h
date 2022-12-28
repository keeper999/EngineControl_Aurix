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
**  FILENAME  : SchM_FlsLoader.h                                              **
**                                                                            **
**  VERSION   : 0.0.2                                                         **
**                                                                            **
**  DATE      : 2012.11.29                                                    **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **                                                                   **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This header file exports the exclusive area                **
**                  functions.                                                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 *
 * V0.0.2: 2012.11.29, Updated for AS4.0 support
 * V0.0.1: 2009.05.07, Initial version
 *
 */

#ifndef SCHM_FLS_LOADER_H
#define SCHM_FLS_LOADER_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
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
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Syntax          : void SchM_Enter_FlsLoader(void)                         **
**                                                                           **
** Service ID      : 0x03                                                    **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters(in)  : void                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value    : none                                                    **
**                                                                           **
** Description     : Enters Module exclusive area                            **
**                                                                           **
*******************************************************************************/
extern void SchM_Enter_FlsLoader_Write(void);
/*******************************************************************************
** Syntax          : void SchM_Enter_FlsLoader(void)                         **
**                                                                           **
** Service ID      : 0x03                                                    **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters(in)  : void                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value    : none                                                    **
**                                                                           **
** Description     : Enters Module exclusive area                            **
**                                                                           **
*******************************************************************************/
extern void SchM_Enter_FlsLoader_Erase(void);

/*******************************************************************************
** Syntax          : void SchM_Enter_FlsLoader(void)                         **
**                                                                           **
** Service ID      : 0x03                                                    **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters(in)  : void                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value    : none                                                    **
**                                                                           **
** Description     : Enters Module exclusive area                            **
**                                                                           **
*******************************************************************************/
extern void SchM_Enter_FlsLoader_lLock(void);

/*******************************************************************************
** Syntax          : void SchM_Exit_FlsLoader(void)                          **
**                                                                           **
** Service ID      : 0x04                                                    **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters(in)  : void                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value    : none                                                    **
**                                                                           **
** Description     : Exits Module exclusive area                             **
**                                                                           **
*******************************************************************************/
extern void SchM_Exit_FlsLoader_Write(void);
/*******************************************************************************
** Syntax          : void SchM_Exit_FlsLoader(void)                          **
**                                                                           **
** Service ID      : 0x04                                                    **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters(in)  : void                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value    : none                                                    **
**                                                                           **
** Description     : Exits Module exclusive area                             **
**                                                                           **
*******************************************************************************/
extern void SchM_Exit_FlsLoader_Erase(void);
/*******************************************************************************
** Syntax          : void SchM_Exit_FlsLoader(void)                          **
**                                                                           **
** Service ID      : 0x04                                                    **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters(in)  : void                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value    : none                                                    **
**                                                                           **
** Description     : Exits Module exclusive area                             **
**                                                                           **
*******************************************************************************/
extern void SchM_Exit_FlsLoader_lLock(void);

#endif /* SCHM_FLS_LOADER_H */
