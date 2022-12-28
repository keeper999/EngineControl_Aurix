/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_TLE8718.c                                          */
/* !Description     : SchM configuration of the TLE8718 component             */
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
 * %PID: P2017_BSW:0A192412.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Os.h"
#include "TLE8718.h"
#include "TLE8718_MscM.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

TASK(OSTSK_S_TLE8718_MSCM_END_SEQ)
{
   TLE8718_vidMscM_Task(TLE8718_udtINSTANCE_1);
   TerminateTask();
}

/*-------------------------------- end of file -------------------------------*/
