/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : ANGSCHED                                                */
/* !Description     : Angular scheduler Component                             */
/*                                                                            */
/* !File            : ANGSCHED_IRQ.h                                          */
/* !Description     : ANGSCHED events handler                                 */
/*                                                                            */
/* !Reference       : V03 NT 10 08984                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192439.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef ANGSCHED_IRQ_H
#define ANGSCHED_IRQ_H

#include "Std_Types.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define ANGSCHED_START_SEC_CODE
#include "ANGSCHED_MemMap.h"

extern void ANGSCHED_vidInjCallback(uint32 u32Date);
extern void ANGSCHED_vidBumLtooCallback(uint32 u32Date);

#define ANGSCHED_STOP_SEC_CODE
#include "ANGSCHED_MemMap.h"


#endif /* ANGSCHED_IRQ_H */

/*------------------------------ end of file ---------------------------------*/
