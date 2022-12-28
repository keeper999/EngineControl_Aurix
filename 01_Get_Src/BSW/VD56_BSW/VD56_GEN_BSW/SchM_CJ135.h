/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_CJ135.h                                            */
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
 * %PID: P2017_BSW:0A195305.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_CJ135_H
#define SCHM_CJ135_H

#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/*#define SchM_Enter_CJ135_SPI_ISR  DisableAllInterrupts
#define SchM_Exit_CJ135_SPI_ISR   EnableAllInterrupts*/
#define SchM_Trigger_CJ135_SpiM(udtInstance) ActivateTask(OSTSK_S_CJ135_U2450_SPIM)

#endif /* SCHM_CJ135_H */

/*-------------------------------- end of file -------------------------------*/
