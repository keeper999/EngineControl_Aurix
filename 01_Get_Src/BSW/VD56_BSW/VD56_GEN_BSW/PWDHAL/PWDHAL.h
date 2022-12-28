/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PWDHAL                                                                                          */
/* !Description     : Pulse width demodulation                                                                        */
/*                                                                                                                    */
/* !File            : PWDHAL.h                                                                                        */
/* !Description     : Public declarations                                                                             */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5611943                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A3470.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef PWDHAL_H
#define PWDHAL_H

#include "Std_Types.h"
#include "PWDHAL_Types.h"

/* to have entry points */
#include "PWDHAL_Cfg.h"


#define PWDHAL_START_SEC_CODE
#include "PWDHAL_MemMap.h"

extern void PWDHAL_vidInit(void);
extern void PWDHAL_vidDisable(uint8 u8Channel);
extern void PWDHAL_vidEnable(uint8 u8Channel);
extern Std_ReturnType PWDHAL_udtWriteTimeoutValue(uint8 u8Channel, PWDHAL_tudtTimeoutType udtTimeoutValue);
extern Std_ReturnType PWDHAL_udtGetPeriodAndDutyCycle(uint8                  u8Channel,
                                                      PWDHAL_tudtPeriod    * pudtPeriod,
                                                      PWDHAL_tudtDutyCycle * pudtDutyCycle);

/* Used indirectly by the entry point macros */
extern void PWDHAL_vidMainFunction(uint8 u8Channel);

#define PWDHAL_STOP_SEC_CODE
#include "PWDHAL_MemMap.h"


#endif /* PWDHAL_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
