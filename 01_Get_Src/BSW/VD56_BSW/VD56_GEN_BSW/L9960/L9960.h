/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960.h                                                                                         */
/* !Description     : Public definitions                                                                              */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A5915.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef L9960_H
#define L9960_H

#include "Std_Types.h"
#include "L9960_Cfg.h"
#include "HBHAL.h"

/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"

extern void L9960_vidInit(void);
extern void L9960_vidEnable(uint8 u8Channel);
extern void L9960_vidDisable(uint8 u8Channel);
extern void L9960_vidWrite(uint8 u8Channel, sint32 s32SetPoint);
extern void L9960_vidMainFunction(void);
extern void L9960_vidSpiM_Task(void);
extern HBHAL_tenuStatus L9960_enuReadStatus(uint8 u8Channel);
extern void L9960_vidEnableNotification(uint8 u8Channel);
extern void L9960_vidDisableNotification(uint8 u8Channel);

#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

#endif /* L9960_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
