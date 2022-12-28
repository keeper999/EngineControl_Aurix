/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : STUB                                                    */
/* !Description     : Stub of HAL components                                  */
/*                                                                            */
/* !File            : BSW_GATEWAY.h                                           */
/* !Description     : Gateway for BSW component                               */
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
 * %PID:%
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef BSW_GATEWAY_H
#define BSW_GATEWAY_H

#include "Std_Types.h"
#include "PWMHAL.H"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef uint16 ADCHAL_tudtAdcResult;

/******************************************************************************/
/* APIs                                                                       */
/******************************************************************************/

#define PWMHAL_START_SEC_CODE
#include "PWMHAL_MemMap.h"

ADCHAL_tudtAdcResult ADCHAL_udtRead(uint8 u8Channel);
Std_ReturnType CRKHAL_udtReadLastToothDuration(uint32 *pu32Duration);
Std_ReturnType CRKHAL_udtReadToothInformation(uint8  *pu8ToothCounter,
                                              uint32 *pu32ToothDuration,
                                              uint32 *pu32PrevToothDuration);
void PWMHAL_vidWrite(PWMHAL_tudtChannel udtChannel,PWMHAL_tudtDutyCycle udtDutyCycle);
void PWMHAL_vidWriteFrequency(PWMHAL_tudtChannel udtChannel, PWMHAL_tudtFrequency udtFrequency);
void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32 *pu32Period, uint16 *pu16DutyCycle);


#define PWMHAL_STOP_SEC_CODE
#include "PWMHAL_MemMap.h"

#endif /* BSW_GATEWAY_H */


/*------------------------------- end of file --------------------------------*/
