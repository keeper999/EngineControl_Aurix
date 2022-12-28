/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_L9960.h                                            */
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
 * %PID: P2017_BSW:0A192433.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_L9960_H
#define SCHM_L9960_H

#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_L9960_SPI_ISR  DisableAllInterrupts
#define SchM_Exit_L9960_SPI_ISR   EnableAllInterrupts
#define SchM_Trigger_L9960_SpiM() ActivateTask(OSTSK_S_L9960_SPIM)

#endif /* SCHM_L9960_H */

/*-------------------------------- end of file -------------------------------*/
