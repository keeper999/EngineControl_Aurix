/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : WDG                                                     */
/* !Description     : WDG Component                                           */
/*                                                                            */
/* !File            : Wdg_Add_On.h                                            */
/* !Description     : This file defines the add-on API of the WDG component.  */
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
 * %PID: P2017_BSW:0A111603.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef WDG_ADD_ON_H
#define WDG_ADD_ON_H

#include "Std_Types.h"
#include "Mcal.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define WDG_17_SCU_START_SEC_CODE
#include "WDG_17_SCU_MemMap.h"

void Wdg_vidRefreshCoreWatchdog(uint8 u8CoreId);

#define WDG_17_SCU_STOP_SEC_CODE
#include "WDG_17_SCU_MemMap.h"

/******************************************************************************/
/* MACRO-FUNCTIONS DECLARATION                                                */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : Wdg_vidRefreshWatchdog                                      */
/* !Description : This function refreshes the wdg of current core             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define Wdg_vidRefreshWatchdog() \
do \
{ \
   uint8 u8LocalCoreId = Mcal_GetCoreId(); \
   Wdg_vidRefreshCoreWatchdog(u8LocalCoreId); \
} \
while (0)

#endif  /* WDG_ADD_ON_H */

/*------------------------------ end of file ---------------------------------*/
