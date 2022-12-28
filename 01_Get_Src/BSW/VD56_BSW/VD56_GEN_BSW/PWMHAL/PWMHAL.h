/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !Module          : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !File            : PWMHAL.h                                                                                        */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A373.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/


#ifndef PWMHAL_H
#define PWMHAL_H


#include "PWMHAL_Types.h"
#include "PWMHAL_Cfg.h"
#include "Std_Types.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/
#define PWMHAL_START_SEC_CODE
#include "PWMHAL_MemMap.h"

extern void PWMHAL_vidInit(void);
extern Std_ReturnType PWMHAL_udtWriteDutyCycle(PWMHAL_tudtChannel udtChannel, PWMHAL_tudtDutyCycle udtDutyCycle);
extern Std_ReturnType PWMHAL_udtWriteFrequency(PWMHAL_tudtChannel udtChannel, PWMHAL_tudtFrequency udtFrequency);

#define PWMHAL_STOP_SEC_CODE
#include "PWMHAL_MemMap.h"

#endif /* PWMHAL_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/