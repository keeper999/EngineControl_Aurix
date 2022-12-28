/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_L9960.c                                            */
/* !Description     : SchM configuration of the L9960 component               */
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
 * %PID: P2017_BSW:0A192401.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Os.h"
#include "L9960.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

TASK(OSTSK_S_L9960_SPIM)
{
   L9960_vidSpiM_Task();
   TerminateTask();
}


/*-------------------------------- end of file -------------------------------*/
