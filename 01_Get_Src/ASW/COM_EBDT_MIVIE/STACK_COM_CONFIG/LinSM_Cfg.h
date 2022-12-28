
/******************************************************************************/
/*! \file LinSM_Cfg.h
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
/* !File            : LinSM_Cfg.h                                             */
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
/* $Revision::   1.0      $$Author::   mnagy        $$Date::   25 Sep 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINSM_CFG_H
#define LINSM_CFG_H

#include "Std_Types.h"
#include "Compiler.h"


/* PRQA S 0850 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Memclass is defined as an empty    */
/*              macro                                                         */
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* ! \Description   The Configuration Major version                           */
#define LINSM_CFG_MAJOR_VERSION                         (2U)
/* ! \Description   The Configuration Minor version                           */
#define LINSM_CFG_MINOR_VERSION                         (0U)
/******************************************************************************/
/*! \Description    Switched on/off the inter-module version checks 
                    between LinSM and the interfaced modules.                 \n
    \Range          STD_ON,STD_OFF                                            \n
*******************************************************************************/
#define LinSM_bINTER_MOD_VER_CHECK		STD_OFF
/******************************************************************************/
/*! \Description    This parameter indicates that a Lin transceiver is  
                    used or not.                                              \n
    \Range          STD_ON,STD_OFF                                            \n
*******************************************************************************/
#define LinSM_bLIN_TRNCVR_USED		STD_OFF
/******************************************************************************/
/*! \Description    Switches the Development Error Detection and Notification 
                    ON or OFF.                                                \n
    \Range          STD_ON,STD_OFF                                            \n
*******************************************************************************/

#define LinSM_bDEV_ERROR_DETECT		STD_ON

/******************************************************************************/
/*! \Description    Switches the LinSM_GetVersionInfo function ON or OFF.     \n
    \Range          STD_ON,STD_OFF                                            \n
*******************************************************************************/

#define LinSM_bVERSION_INFO_API 	STD_OFF

/******************************************************************************/
/*! \Description Number of LinChannels configured for the LinSM component.    */
/*! \Range   1..256                                                           */

#define LinSM_u16MAX_CHANNEL_NUM			1

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/*! \Description  Type for the LinSM Configuration structure.                 */
typedef    struct 
{
    /*! \Description            Timeout in  seconds for the goto sleep and 
                                wakeup calls to LinIf. The timeout must be 
                                longer than a goto-sleep command on the bus.  \n
                                This Timeout shall equal to number of multiples 
                                 of the main function periodic time           \n
        \Range                  0..65535                                      */
        VAR(uint16, AUTOMATIC)      u16ConfirmationTimeout;
        /*! \Description        Maximum number of schedule entries specified
                                configured for each LinChannel                \n
        \Range                  0..255                                        */
        VAR(uint8, AUTOMATIC)     u8MaxScheduleEntries;
} LinSM_tstrChannelCfg;

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
/*! \Description  The LinSM Configuration structure                           */
extern CONST(LinSM_tstrChannelCfg, LINSM_VAR) LinSM_akstreChannelReference[LinSM_u16MAX_CHANNEL_NUM];
#endif /* LINSM_CFG_H */
