/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_I.h                                                                                      */
/* !Description     : External Functions of the PMPHAL Component                                                      */
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
 * %PID: P2017_BSW:0A189062.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef PMPHAL_E_H
#define PMPHAL_E_H

#include "Std_Types.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/

#define PMPHAL_START_SEC_CODE
#include "PMPHAL_MemMap.h"

extern void PMPHAL_vidCrkSyncFoundEntry(void);
extern void PMPHAL_vidCrkSyncLostEntry(void);
extern void PMPHAL_vidDisable(void);
extern void PMPHAL_vidEnable(void);
extern void PMPHAL_vidInit(void);
extern void PMPHAL_vidSpillCmdNotification(void);
extern void PMPHAL_vidSpillCommandManager(void);
extern void PMPHAL_vidSpillEventManager(void);
extern void PMPHAL_vidSpillEventNotification(void);
extern void PMPHAL_vidWriteDecelHppProfilDly(uint32 u32ProfilSwitchDelay);
extern void PMPHAL_vidWriteSpillCmdAngle(uint16 u16SpillCmdAngle);
extern void PMPHAL_vidWriteSpillCmdTime(uint32 u32CommandTime);
extern void PMPHAL_vidWriteSpillDecelDly(uint32 u32SpillDecelDelay);
extern void PMPHAL_vidWriteSpillDecelTime(uint32 u32DecelTime);
extern Std_ReturnType PMPHAL_udtDisableSpillCommand(void);
extern Std_ReturnType PMPHAL_udtEnableSpillCommand(void);
extern Std_ReturnType PMPHAL_udtSwitchHppProfile(uint8 u8HppPulseId, uint8 u8HppProfileId);
extern Std_ReturnType PMPHAL_udtWriteSpillCmdLevel(boolean bSpillCmdLevel);

#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"

#endif /* PMPHAL_E_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
