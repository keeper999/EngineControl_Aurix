/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : STARTUP                                                 */
/* !Description     : Start-up                                                */
/*                                                                            */
/* !File            : STARTUP.h                                               */
/* !Description     : Start-up software                                       */
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
 * %PID: P2017_BSW:0A111546.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef STARTUP_H_
#define STARTUP_H_

/******************************************************************************/
/*                         Exported prototypes                                */
/******************************************************************************/
#define STARTUP_START_SEC_CODE
#include "STARTUP_MemMap.h"

void cstart(void);
void STARTUP_Core0_start(void);
void STARTUP_Core1_start(void);
void STARTUP_Core2_start(void);

#define STARTUP_STOP_SEC_CODE
#include "STARTUP_MemMap.h"

#endif /* STARTUP_H_ */

/*-------------------------------- end of file -------------------------------*/
