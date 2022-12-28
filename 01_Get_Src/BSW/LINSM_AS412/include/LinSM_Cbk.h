/******************************************************************************/
/*! \file LinSM_Cbk.h
*
* \brief
*   This file containing the APIs declaration, symbols, and data exported     */
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : LinSM                                                   */
/* !Description     : LinSM is a part of the Communication service layer,     */
/*                    and it's responsible for:                               */
/*                    -Switching Schedule tables when requested by Upper layer*/
/*                    - GotoSleep and Wakeup Handling.                        */
/*                    - Notification to the upper layer when new state entered*/
/*                                                                            */
/* !File            : LinSM_Cbk.h                                             */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/DEI Team room/archives/E95110014/02_Modules/21_Lin$*/
/* $Revision::   1.1      $$Author::   mnagy        $$Date::   28 Nov 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINSM_CBK_H
#define LINSM_CBK_H

#include "Std_Types.h"
#include "Compiler.h"


/* PRQA S 0850 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Memclass is defined as an empty    */
/*              macro                                                         */
/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define LINSM_START_SEC_CODE
#include "MemMap.h"
                    
/******************************************************************************/
/*! \Description    The LinIf module will call this callback when the new 
                    requested schedule table is active.                       \n
    \param[in]      udtNetwork  Identification of the LIN channel             \n
    \param[in]      udtSchedule    The new Schedule table                     \n
*******************************************************************************/
FUNC(void, LINSM_CODE) LinSM_ScheduleRequestConfirmation( 
    NetworkHandleType udtNetwork, 
    LinIf_SchHandleType udtSchedule );    
/******************************************************************************/
/*! \Description    The LinIf module will call this callback when go to sleep 
                    command is sent successfully or not sent successfully on 
                    the network.                                              \n
    \param[in]      udtNetwork  Identification of the LIN channel             \n
    \param[in]      bSuccess    True if goto sleep was successfully sent, 
                                false otherwise                               \n
*******************************************************************************/
FUNC(void, LINSM_CODE) LinSM_GotoSleepConfirmation( 
    NetworkHandleType udtNetwork, 
    boolean bSuccess );    

/******************************************************************************/
/*! \Description    The  LinIf will call this callback when the wake up signal
                    command is sent not successfully/successfully on the
                     network.                                                  \n
    \param[in]      udtNetwork  Identification of the LIN channel             \n
    \param[in]      bSuccess    True if Wakeup was successfully sent, 
                                false otherwise                               \n
*******************************************************************************/    
FUNC(void, LINSM_CODE) LinSM_WakeupConfirmation( 
    NetworkHandleType udtNetwork, 
    boolean bSuccess );
/******************************************************************************/    
#define LINSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* LINSM_H */

/*-------------------------------- end of file -------------------------------*/                