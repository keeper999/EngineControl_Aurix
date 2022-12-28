/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PRSHAL                                                  */
/* !Description     : PRSHAL Component                                        */
/*                                                                            */
/* !File            : PRSHAL.h                                                */
/* !Description     : APIs of PRSHAL Component                                */
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
 * %PID: P2017_BSW:A244.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PRSHAL_H
#define PRSHAL_H

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define PRSHAL_u16ERR_ADJUST_FACTOR_D     2    /* 2 */
#define PRSHAL_u16ERR_ADJUST_FACTOR_N     3    /* 3 */

/******************************************************************************/
/* APIs                                                                       */
/******************************************************************************/

#define PRSHAL_START_SEC_CODE
#include "PRSHAL_MemMap.h"

void PRSHAL_vidInit(void);
void PRSHAL_vidDeInit(void);
void PRSHAL_vidInterrupt(void);

#define PRSHAL_STOP_SEC_CODE
#include "PRSHAL_MemMap.h"

#endif /* PRSHAL_H */

/*------------------------------- end of file --------------------------------*/
