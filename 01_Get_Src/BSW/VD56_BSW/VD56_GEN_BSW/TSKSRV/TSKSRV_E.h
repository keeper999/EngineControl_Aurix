/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : TSKSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : TSKSRV_E.h                                              */
/* !Description     : External Macros of TSKSRV Component                     */
/*                                                                            */
/* !Reference       : V03 NT 12 00698                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A286.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef TSKSRV_E_H
#define TSKSRV_E_H

#include "Isr_Cfg.h"
#include "Os.h"
#include "Std_Types.h"
#include "TSKSRV_I.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : TSKSRV_vidActivateTask                                      */
/* !Description: Sets the activation request boolean for snTaskName           */
/*                                                                            */
/* !Trace_To   : VEES_R_12_00698_005                                          */
/* !Trace_To   : VEES_R_12_00698_006                                          */
/* !Trace_To   : VEES_R_12_00698_007                                          */
/* !Trace_To   : VEES_R_12_00698_008                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define TSKSRV_vidActivateTask(snTaskName) \
do \
{ \
   TSKSRV_abActivationRequest[TSKSRV_u8TASK_##snTaskName] = TRUE; \
   INTBSL_vidSTART_SW_IT(TSKSRV_ACTIVATION_MANAGER_IT); \
} \
while (0)


/******************************************************************************/
/* FUNCTION DECLARATIONS                                                      */
/******************************************************************************/

#define  TSKSRV_START_SEC_CODE
#include "TSKSRV_MemMap.h"

extern void TSKSRV_vidInit(void);

#define  TSKSRV_STOP_SEC_CODE
#include "TSKSRV_MemMap.h"


#endif /* TSKSRV_E_H */


/*-------------------------------- end of file -------------------------------*/
