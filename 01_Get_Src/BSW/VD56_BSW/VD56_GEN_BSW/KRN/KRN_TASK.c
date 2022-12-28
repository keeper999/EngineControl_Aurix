/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_TASK.c                                              */
/* !Description     : Defines Software tasks                                  */
/*                                                                            */
/* !Reference       : NONE                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192508.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "KRN_BSW.h"
#include "Os.h"

#define  KRN_START_SEC_CODE
#include "KRN_MemMap.h"

/******************************************************************************/
/* !FuncName    : OSTSK_S_INIT                                                */
/* !Description : This task is auto started after init                        */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
TASK(OSTSK_S_INIT)
{
   KRN_vidS_INIT_BSW_PRE();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_WTDG_REFRESH_WATCHDOG_BSW                           */
/* !Description : This task is activated on WATCHDOG event                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_WTDG_REFRESH_WATCHDOG_BSW)
{
   KRN_vidS_WTDG_REFRESH_WATCHDOG_BSW_PRE();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW                           */
/* !Description : This task is activated on WATCHDOG event                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW)
{
   KRN_vidS_WTDG_REFRESH_WATCHDOG_ASW_PRE();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DEVAID_COMM_CAN                                     */
/* !Description : This task is activated on Devaid Can Communication event    */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
TASK(OSTSK_S_DEVAID_COMM_CAN)
{
   KRN_vidS_DEVAID_COMM_CAN_BSW_PRE();
   (void)TerminateTask();
}


#define  KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
