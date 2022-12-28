/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : THRHAL                                                  */
/* !Description     : THRHAL Component                                        */
/*                                                                            */
/* !File            : THRHAL.h                                                */
/* !Description     : APIs of THRHAL Component                                */
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
 * %PID: P2017_BSW:0A111592.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef THRHAL_H
#define THRHAL_H

#include "Std_Types.h"

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

#define THRHAL_START_SEC_CODE
#include "THRHAL_MemMap.h"

extern void THRHAL_vidInit(void);
extern void THRHAL_vidInterrupt(void);
extern void THRHAL_vidDisable(void);
extern void THRHAL_vidEnable(void);
extern void THRHAL_vidMainFunction(void);

#define THRHAL_STOP_SEC_CODE
#include "THRHAL_MemMap.h"

#endif /* THRHAL_H */

/*-------------------------------- end of file -------------------------------*/
