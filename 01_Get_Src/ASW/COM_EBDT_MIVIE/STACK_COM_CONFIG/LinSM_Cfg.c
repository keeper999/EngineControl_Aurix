
/******************************************************************************/
/*! \file LinSM_Cfg.c
*
* \brief
*   This file containing the implementation of the configuration of the  
    Component APIs                                                            */
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
/* !File            : LinSM_Cfg.c                                             */
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
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/DEI Team room/archives/E95110014/02_Modules/21_Lin$*/
/* $Revision::   1.0      $$Author::   mnagy        $$Date::   25 Sep 2012 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#include "Std_Types.h"
#include "Compiler.h"
#include "LinSM_Cfg.h"


/* PRQA S 0850 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Memclass is defined as an empty    */
/*              macro                                                         */
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
/*! \Description  The LinSM Configuration structure                           */

CONST(LinSM_tstrChannelCfg, LINSM_VAR) LinSM_akstreChannelReference[LinSM_u16MAX_CHANNEL_NUM] =
{

  {
    /**********************************************************************/
    /*! \Description   Timeout in  seconds for the goto sleep and wakeup 
                       calls to LinIf. The timeout must be longer than a 
               goto-sleep command on the bus.  \n
                           This Timeout shall equal to number of multiples of 
               the main function periodic time                 \n
        \Range                  0..65535                                      */
    /**********************************************************************/  
    0,/*u16ConfirmationTimeout = 0.0/0.02*/   
    /**********************************************************************/    
    /*! \Description        Maximum number of schedule entries specified
                                configured for each LinChannel                \n
        \Range                  0..255                                        */
    /**********************************************************************/    
    1,/*u8MaxScheduleEntries*/
  },
  
};

/*-------------------------------- end of file -------------------------------*/
