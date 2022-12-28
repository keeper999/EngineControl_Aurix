/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_CJ135.c                                            */
/* !Description     : SchM configuration of the CJ135 component               */
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
 * %PID: P2017_BSW:0A195304.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Os.h"
#include "CJ135.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

TASK(OSTSK_S_CJ135_U2450_SPIM)
{
   CJ135_vidSpiM_Task(CJ135_u8U2450);
   TerminateTask();
}

TASK(OSTSK_S_CJ135_U2450_IRQ)
{
   CJ135_vidInstanceMainFunction(CJ135_u8U2450);
   TerminateTask();
}


/*-------------------------------- end of file -------------------------------*/
