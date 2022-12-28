/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_Spi.h                                              */
/* !Description     : SchM configuration of the SPI component                 */
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
 * %PID: P2017_BSW:0A192460.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_SPI_H
#define SCHM_SPI_H

#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_Spi_WriteIB() SuspendAllInterrupts()
#define SchM_Enter_Spi_AsyncTransmit() SuspendAllInterrupts()
#define SchM_Enter_Spi_GetSequenceResult() SuspendAllInterrupts()
#define SchM_Enter_Spi_Cancel() SuspendAllInterrupts()
#define SchM_Enter_Spi_Init() SuspendAllInterrupts()
#define SchM_Enter_Spi_DeInit() SuspendAllInterrupts()

#define SchM_Exit_Spi_WriteIB() ResumeAllInterrupts()
#define SchM_Exit_Spi_AsyncTransmit() ResumeAllInterrupts()
#define SchM_Exit_Spi_GetSequenceResult() ResumeAllInterrupts()
#define SchM_Exit_Spi_Cancel() ResumeAllInterrupts()
#define SchM_Exit_Spi_Init() ResumeAllInterrupts()
#define SchM_Exit_Spi_DeInit() ResumeAllInterrupts()

#endif /* SCHM_SPI_H */

/*-------------------------------- end of file -------------------------------*/
