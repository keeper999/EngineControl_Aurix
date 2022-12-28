/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_I.h                                                                                      */
/* !Description     : Internal Macros of the PMPHAL Component                                                         */
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
 * %PID: P2017_BSW:0A189074.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef PMPHAL_I_H
#define PMPHAL_I_H

#include "Std_Types.h"

#include "PMPHAL.h"
#include "PMPHAL_CFG_I.h"
#include "PMPHAL_GTM_CFG.h"
#include "PMPHAL_L.h"

#include "CRKHAL.h"
#include "Dio.h"
#include "Gpt.h"
#include "IfxGtm_Ccu.h"
#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"
#include "MATHSRV.h"
#include "Port.h"
#include "SchM_PMPHAL.h"

/**********************************************************************************************************************/
/* MACRO FUNCTIONS                                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidACTUATE_SPILL_CMD                                                                         */
/* !Description : This internal macro programs the next spill pulse angle.                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidACTUATE_SPILL_CMD() \
do \
{ \
   sint32         s32LocalRelEngAngle; \
   uint16         u16LocalPrevSpillEventAngle; \
   uint16         u16LocalRelSpillCmdAngle; \
   \
   \
   PMPHAL_bActuationProgrammed = TRUE; \
   \
   u16LocalRelSpillCmdAngle = PMPHAL_u16SpillCmdAngle; \
   \
   u16LocalPrevSpillEventAngle = PMPHAL_u16PrevSpillEventAngle; \
   \
   PMPHAL_u16NextSpillCmdAngle = (uint16)(u16LocalRelSpillCmdAngle + u16LocalPrevSpillEventAngle); \
   \
   if (PMPHAL_u16NextSpillCmdAngle >= PMPHAL_u16ENGINE_CYCLE) \
   { \
      PMPHAL_u16NextSpillCmdAngle = (uint16)(PMPHAL_u16NextSpillCmdAngle - PMPHAL_u16ENGINE_CYCLE); \
   } \
   \
   CRKHAL_vidActivateAlarmMode(PMPHAL_u8CRKHAL_SPILL_CMD_CH, MODE_NO_ACTION); \
   \
   CRKHAL_vidSetAbsAlarm(PMPHAL_u8CRKHAL_SPILL_CMD_CH, PMPHAL_u16NextSpillCmdAngle); \
   \
   s32LocalRelEngAngle = CRKHAL_u16ReadCounter(PMPHAL_u8CRKHAL_SPILL_CMD_CH); \
   s32LocalRelEngAngle = (sint32)(s32LocalRelEngAngle - u16LocalPrevSpillEventAngle); \
   if (s32LocalRelEngAngle < 0) \
   { \
      s32LocalRelEngAngle = (sint32)(s32LocalRelEngAngle + PMPHAL_u16ENGINE_CYCLE); \
   } \
   \
   if (s32LocalRelEngAngle >= u16LocalRelSpillCmdAngle) \
   { \
      CRKHAL_vidDeactivateAlarmMode(PMPHAL_u8CRKHAL_SPILL_CMD_CH); \
      PMPHAL_vidSpillCmdNotification(); \
   } \
   else \
   { \
      CRKHAL_vidEnableAlarmNotif(PMPHAL_u8CRKHAL_SPILL_CMD_CH); \
   } \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDISABLE_SPILL_CMD                                                                         */
/* !Description : This internal macro disables the spill command                                                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidDISABLE_SPILL_CMD() \
do \
{ \
   uint32 u32LocalTbu_Data; \
   PMPHAL_vidDisableSpillCmd(); \
   PMPHAL_vidDisableSpillCmdInt(); \
   Dio_WriteChannel(PMPHAL_snDIO_SPILL_CMD_CH, STD_LOW); \
   PMPHAL_bActuationProgrammed = FALSE; \
   PMPHAL_bSpillCmdRequested   = FALSE; \
   PMPHAL_bGioCmdLevel         = STD_LOW; \
   PMPHAL_u16NextSpillCmdAngle = PMPHAL_u16UNKNOWN_ANGLE; \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDISABLE_SPILL_EVENT                                                                       */
/* !Description : This internal macro disables the spill event                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidDISABLE_SPILL_EVENT() \
do \
{ \
   PMPHAL_vidDisableSpillEventInt(); \
   PMPHAL_u16PrevSpillEventAngle = PMPHAL_u16UNKNOWN_ANGLE; \
   PMPHAL_u16NextSpillEventAngle = PMPHAL_u16UNKNOWN_ANGLE; \
   PMPHAL_u8SpillEventCounter    = 0u; \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidENABLE_SEQUENTIAL_MODE                                                                    */
/* !Description : This internal macro enables the sequential mode of the spill command                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidENABLE_SEQUENTIAL_MODE() \
do \
{ \
   uint8   u8LocalSpillEventIndex; \
   uint16  u16LocalEngineAngle; \
   uint16  u16LocalNextSpillEventAngle; \
   boolean bLocalSpillEventFound; \
   \
   if (PMPHAL_bSpillEventParamOk != FALSE) \
   { \
      PMPHAL_u16NextSpillEventAngle = PMPHAL_u16SpillEventAngleRqstd; \
      PMPHAL_u8SpillEventCounter    = 0u; \
      bLocalSpillEventFound         = FALSE; \
      u8LocalSpillEventIndex        = 0u; \
      u16LocalEngineAngle           = CRKHAL_u16ReadCounter(PMPHAL_u8CRKHAL_SPILL_EVENT_CH); \
      \
      do \
      { \
         u16LocalNextSpillEventAngle = (uint16)( PMPHAL_u16SpillEventAngleRqstd \
                                               + (uint16)(u8LocalSpillEventIndex * PMPHAL_u16InterSpillEventAngle)); \
         \
         if (u16LocalNextSpillEventAngle > ((uint16)( u16LocalEngineAngle + PMPHAL_u16_6_DEG_FOR_1ST_EVENT))) \
         { \
            bLocalSpillEventFound         = TRUE; \
            PMPHAL_u8SpillEventCounter    = u8LocalSpillEventIndex; \
            PMPHAL_u16NextSpillEventAngle = u16LocalNextSpillEventAngle; \
         } \
         \
         u8LocalSpillEventIndex++; \
         \
      } while ((u8LocalSpillEventIndex < PMPHAL_u8NbSpillEventsRqstd) && (bLocalSpillEventFound == FALSE)); \
      \
      CRKHAL_vidActivateAlarmMode(PMPHAL_u8CRKHAL_SPILL_EVENT_CH, MODE_NO_ACTION); \
      CRKHAL_vidSetAbsAlarm(PMPHAL_u8CRKHAL_SPILL_EVENT_CH, PMPHAL_u16NextSpillEventAngle); \
      CRKHAL_vidEnableAlarmNotif(PMPHAL_u8CRKHAL_SPILL_EVENT_CH); \
      \
      PMPHAL_enuCommandMode = PMPHAL_enuSEQUENTIAL_MODE; \
   } \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidENABLE_CONTINUOUS_MODE                                                                    */
/* !Description : This internal macro enables the continuous mode of the spill command                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidENABLE_CONTINUOUS_MODE() \
do \
{ \
   PMPHAL_vidDISABLE_SPILL_CMD(); \
   PMPHAL_vidDISABLE_SPILL_EVENT(); \
   PMPHAL_vidDISABLE_CAPCOM_DELAY(); \
   PMPHAL_vidGtmDisable(); \
   Port_SetPinMode(PMPHAL_snDIO_SPILL_CMD_CH, PORT_PIN_MODE_GPIO); \
   Dio_WriteChannel(PMPHAL_snDIO_SPILL_CMD_CH, STD_LOW); \
   PMPHAL_bGioCmdLevel = STD_LOW; \
   PMPHAL_enuCommandMode = PMPHAL_enuCONTINUOUS_MODE; \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDISABLE_CAPCOM_DELAY                                                                      */
/* !Description : This internal macro disables the Capcom Delay on CCU match                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidDISABLE_CAPCOM_DELAY() \
do \
{ \
   Gpt_StopTimer(PMPHAL_snGPT_PMP_DELAY_CH); \
   Gpt_DisableNotification(PMPHAL_snGPT_PMP_DELAY_CH); \
   PMPHAL_bProfSwitchProgrammed = FALSE; \
   PMPHAL_enuCapcomDelayState   = PMPHAL_enuSWITCH_DECEL_PROFILE; \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidPROG_CAPCOM_DLY                                                                           */
/* !Description : This internal macro programs the temporal interrupt with the delay provided into parameter.         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidPROG_CAPCOM_DLY( \
\
   u32SpillTime \
\
) \
do \
{ \
   if (u32SpillTime != 0u) \
   { \
      SchM_Enter_PMPHAL_ACCESS_001(); \
      Gpt_StopTimer(PMPHAL_snGPT_PMP_DELAY_CH); \
      Gpt_EnableNotification(PMPHAL_snGPT_PMP_DELAY_CH); \
      Gpt_StartTimer(PMPHAL_snGPT_PMP_DELAY_CH, u32SpillTime); \
      SchM_Exit_PMPHAL_ACCESS_001(); \
   } \
   else \
   { \
      PMPHAL_vidDelayEndNotification(); \
   } \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidFIRST_SPILL_EVENT                                                                         */
/* !Description : BSL configuration for sequential mode.                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidFIRST_SPILL_EVENT() \
do \
{ \
   Dio_WriteChannel(PMPHAL_snDIO_SPILL_CMD_CH, STD_LOW); \
   PMPHAL_bGioCmdLevel = STD_LOW; \
   /* Enable GTM channels */ \
   PMPHAL_vidGtmEnable(); \
   Port_SetPinMode(PMPHAL_snDIO_SPILL_CMD_CH, PMPHAL_snPORT_OSP_MODE); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDisableSpillCmdInt                                                                        */
/* !Description : This internal macro disables the angular interrupt of spill command                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidDisableSpillCmdInt() \
do \
{ \
   CRKHAL_vidDisableAlarmNotif(PMPHAL_u8CRKHAL_SPILL_CMD_CH); \
   CRKHAL_vidDeactivateAlarmMode(PMPHAL_u8CRKHAL_SPILL_CMD_CH); \
   IfxGtm_vidAtomDisableNotification(PMPHAL_pstrSPILL_CMD_CH, (uint8)IfxGtm_Compare_Unit_1); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDisableSpillCmd                                                                           */
/* !Description : This internal macro disables the command of spill command                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidDisableSpillCmd() \
do \
{ \
   /* Set the Signal Low */ \
   u32LocalTbu_Data = IfxGtm_u32ReadCapTime(PMPHAL_pstrSPILL_CMD_CH); \
   IfxGtm_vidAtomSetCond_Immediate(PMPHAL_pstrSPILL_CMD_CH, \
                         INACTIVE_CCU1, \
                         u32LocalTbu_Data, \
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                         CCU0_ONLY_OUT_INACT); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDisableSpillEventInt                                                                      */
/* !Description : This internal macro disables the angular interrupt of spill event                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidDisableSpillEventInt() \
do \
{ \
   CRKHAL_vidDisableAlarmNotif(PMPHAL_u8CRKHAL_SPILL_EVENT_CH); \
   CRKHAL_vidDeactivateAlarmMode(PMPHAL_u8CRKHAL_SPILL_EVENT_CH); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidStartSpillCmd                                                                             */
/* !Description : This internal macro starts the spill cmd during u32CmdTime                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidStartSpillCmd(u32CmdTime) \
do \
{ \
   uint32 u32LocalSR0_Data; \
   uint32 u32LocalSpillCmdTime; \
   /* Starts the Spill Command: Set The Signal High */ \
   u32LocalSR0_Data = IfxGtm_u32ReadCapTime(PMPHAL_pstrSPILL_CMD_CH); \
   u32LocalSpillCmdTime = (u32CmdTime + TBU_READ_TIME()) & 0x00FFFFFFu; \
   IfxGtm_vidAtomSetCond_Immediate(PMPHAL_pstrSPILL_CMD_CH, \
                         INACTIVE_CCU1, \
                                   u32LocalSR0_Data, \
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                         CCU0_ONLY_OUT_ACTIVE); \
   /* Programs the Disable of Spill Command After SpillCmdTime: Set the Signal Low on Compare Match */ \
   IfxGtm_vidAtomSetCond(PMPHAL_pstrSPILL_CMD_CH, \
                         INACTIVE_CCU1, \
                         u32LocalSpillCmdTime, \
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                         CCU0_ONLY_OUT_INACT); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidSpillCmdEnded                                                                             */
/* !Description : This internal macro returns TRUE if the spill cmd is ended                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define PMPHAL_vidSpillCmdEnded(pbLocalState) \
do \
{ \
   uint32 u32LocalDcntValue; \
   uint32 u32LocalSR0_Data; \
   \
   u32LocalSR0_Data  = IfxGtm_u32ReadCapTime(PMPHAL_pstrSPILL_CMD_CH); \
   u32LocalDcntValue = (u32LocalSR0_Data - IfxGtm_u32AtomCcu0Read(PMPHAL_pstrSPILL_CMD_CH)) & 0x00FFFFFFu; \
   if (u32LocalDcntValue <= 0x007FFFFFu) /* Positive Value => Command Is Already Ended */ \
   { \
      *(pbLocalState) = TRUE; \
   } \
   else \
   { \
      *(pbLocalState) = FALSE; \
   } \
} \
while (0u)

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/

#define PMPHAL_START_SEC_CODE
#include "PMPHAL_MemMap.h"

extern void PMPHAL_vidDelayEndNotification(void);

#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"
#endif /* PMPHAL_I_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
