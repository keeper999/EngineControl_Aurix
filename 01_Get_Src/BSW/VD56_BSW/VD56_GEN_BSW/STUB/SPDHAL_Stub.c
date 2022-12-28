/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : STUB                                                    */
/* !Description     : Stub of HAL components                                  */
/*                                                                            */
/* !File            : SPDHAL_Stub.c                                           */
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
 * %PID: P2017_BSW:0A192445.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "SPDHAL.h"


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define SPDHAL_START_SEC_CODE
#include "SPDHAL_MemMap.h"

void SPDHAL_vidEnable(void)
{
}

void SPDHAL_vidDisable(void)
{
}

void SPDHAL_vidGetPulseInformation
(
   uint16 *pu16PulseCounter,
   uint32 *pu32LastPulseDate
)
{
   *pu16PulseCounter  = UINT16_MIN;
   *pu32LastPulseDate = UINT32_MIN;
}

#define SPDHAL_STOP_SEC_CODE
#include "SPDHAL_MemMap.h"


/*------------------------------ end of file ------------------------------*/
