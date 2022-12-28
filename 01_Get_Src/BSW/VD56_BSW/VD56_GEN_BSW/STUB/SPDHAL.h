/******************************************************************************/
/* !Description     : Stub of HAL components                                  */
/*                                                                            */
/* !File            : SPDHAL.h                                                */
/* !Description     : Stub of SPDHAL component                                */
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
 * %PID: P2017_BSW:0A192453.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SPDHAL_H
#define SPDHAL_H

#include "Std_Types.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !Comment: The Period taken by timer to over flow.                          */
#define SPDHAL_u32TIMER_PERIOD        0x20000000


/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

#define SPDHAL_START_SEC_CODE
#include "SPDHAL_MemMap.h"

void SPDHAL_vidEnable(void);
void SPDHAL_vidDisable(void);
void SPDHAL_vidGetPulseInformation(uint16 *pu16PulseCounter, uint32 *pu32LastPulseDate);

#define SPDHAL_STOP_SEC_CODE
#include "SPDHAL_MemMap.h"


#endif /* SPDHAL_H */

/*-------------------------------- end of file -------------------------------*/
