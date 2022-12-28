/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : STUB                                                    */
/* !Description     : Stub of HAL components                                  */
/*                                                                            */
/* !File            : BSW_GATEWAY.c                                           */
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

#include "Std_Types.h"
#include "Std_Limits.h"
#include "BSW_GATEWAY.h"
#include "CRKHAL.h"
#include "PWDHAL.h"
#include "PWMHAL.h"
#include "ADCHAL.h"


#define PWMHAL_START_SEC_CODE
#include "PWMHAL_MemMap.h"

ADCHAL_tudtAdcResult ADCHAL_udtRead(uint8 u8Channel)
{
	ADCHAL_tudtResultValue udtResultValue;
	
	(void) ADCHAL_udtPrivateRead( (ADCHAL_tudtChannelType) u8Channel, &udtResultValue);
	return ((ADCHAL_tudtAdcResult) udtResultValue);
}


Std_ReturnType CRKHAL_udtReadLastToothDuration
(
   uint32 *pu32Duration
)
{
   uint32         u32LocalToothInfoBuf[2];
   Std_ReturnType Local_udtRetValue;


   Local_udtRetValue = CRKHAL_udtGetToothInfo(2, u32LocalToothInfoBuf);
   *pu32Duration     = u32LocalToothInfoBuf[1];
   return(Local_udtRetValue);
}


Std_ReturnType CRKHAL_udtReadToothInformation
(
   uint8  *pu8ToothCounter,
   uint32 *pu32ToothDuration,
   uint32 *pu32PrevToothDuration
)
{
   uint32         u32LocalToothInfoBuf[3];
   Std_ReturnType Local_udtRetValue;


   Local_udtRetValue      = CRKHAL_udtGetToothInfo(3, u32LocalToothInfoBuf);
   *pu8ToothCounter       = u32LocalToothInfoBuf[0];
   *pu32ToothDuration     = u32LocalToothInfoBuf[1];
   *pu32PrevToothDuration = u32LocalToothInfoBuf[2];
   return(Local_udtRetValue);
}


void PWMHAL_vidWrite
(
   PWMHAL_tudtChannel udtChannel, 
   PWMHAL_tudtDutyCycle udtDutyCycle
)
{
   (void)PWMHAL_udtWriteDutyCycle(udtChannel, udtDutyCycle);
}


void PWMHAL_vidWriteFrequency(PWMHAL_tudtChannel udtChannel, PWMHAL_tudtFrequency udtFrequency)
{
   (void)PWMHAL_udtWriteFrequency(udtChannel, udtFrequency);
}


void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32 *pu32Period, uint16 *pu16DutyCycle)
{
   (void)PWDHAL_udtGetPeriodAndDutyCycle(u8Channel,
                                         pu32Period,
                                         pu16DutyCycle);
}


#define PWMHAL_STOP_SEC_CODE
#include "PWMHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
