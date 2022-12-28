/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_E.h                                                                                       */
/* !Description     : External Functions / Macros of the L9781 Component                                              */
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
 * %PID: P2017_BSW:0A189039.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef L9781_E_H
#define L9781_E_H

#include "Std_Types.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/

#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"

extern void L9781_vidDiagManager(void);
extern void L9781_vidDisable(void);
extern void L9781_vidInit(void);
extern void L9781_vidStartupSequence(void);
extern Std_ReturnType L9781_udtEnable(void);
extern Std_ReturnType L9781_udtFullStop(void);
extern Std_ReturnType L9781_udtReInitialize(void);
extern Std_ReturnType L9781_udtGetInjProfileStatus(uint8 u8Channel);
extern Std_ReturnType L9781_udtGetPumpProfileStatus(uint8 u8Channel);
extern Std_ReturnType L9781_udtLoadInjectorProfile(uint8 u8Channel, uint8 u8InjProfile);
extern Std_ReturnType L9781_udtLoadPumpProfile(uint8 u8Channel, uint8 u8PmpProfile);

#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

#endif /* L9781_E_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
