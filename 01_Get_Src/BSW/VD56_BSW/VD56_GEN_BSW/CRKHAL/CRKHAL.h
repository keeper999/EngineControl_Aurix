/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL.h                                                */
/* !Description     : Data Definition of CRKHAL Component                     */
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
 * %PID: P2017_BSW:A18525.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CRKHAL_H
#define CRKHAL_H

#include "Std_Types.h"
#include "CRKHAL_I.h"
#include "CRKHAL_Typ.h"
#include "CRKHAL_Cfg.h"

/*lint -esym(960,19.5) */

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CRKHAL_bBWD_ROTATION            (1U)
#define CRKHAL_bFWD_ROTATION            (0U)
#define CRKHAL_u16COMMON_ANGLE_RESOL    (64U) /* resol = 1degree / 64 */
#define CRKHAL_u16ENGINE_CYCLE          (46080U) /* 720 degree * CRKHAL_u16COMMON_ANGLE_RESOL */
#define CRKHAL_u16NORMAL_TOOTH_ANGLE    (6U * CRKHAL_u16COMMON_ANGLE_RESOL) /* 6degree */
#define CRKHAL_u8DETECTED               (1U)
#define CRKHAL_u8ENG_POSITION_KNOWN     (16U)
#define CRKHAL_u8ENG_SYNCHRONISED       (8U)
#define CRKHAL_u8NB_INPUT_SGN           (1U) /* dbg */
#define CRKHAL_u8RUNNING                (2U)
#define CRKHAL_u8STOP_POSITION          (1U)
#define CRKHAL_u8STOP_POSITION_AFTER    (2U)
#define CRKHAL_u8SYNCHRONISED           (4U)
#define CRKHAL_udtDOWNGRADED_MODE       (4U)
#define CRKHAL_udtNORMAL_MODE           (2U)
#define CRKHAL_udtNOT_SET               (1U)
#define MODE_CAP_BOTH_EDGES             (64U)
#define MODE_CAP_FALLING                (32U)
#define MODE_CAP_RISING                 (16U)
#define MODE_NO_ACTION                  (8U)
#define MODE_OUTPUT_0                   (1U)
#define MODE_OUTPUT_1                   (2U)
#define MODE_OUTPUT_TOGGLE              (4U)

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

uint16 CRKHAL_u16GetEngineAngle(void);
uint16 CRKHAL_u16ReadAlarm(uint8 u8Channel);
uint16 CRKHAL_u16ReadCounter(uint8 u8Channel);
void CRKHAL_vidActivateAlarmMode(uint8 u8Channel, uint8 u8Mode);
void CRKHAL_vidCrkOnMngtIsr(void);
void CRKHAL_vidUpdateIntAngOffIsr(void);
void CRKHAL_vidDeactivateAlarmMode(uint8 u8Channel);
void CRKHAL_vidDisableAlarmNotif(uint8 u8Channel);
void CRKHAL_vidDpllGetLockIsr(void);
void CRKHAL_vidDpllLongToothIsr(void);
void CRKHAL_vidDpllLostLockIsr(void);
void CRKHAL_vidEnableAlarmNotif(uint8 u8Channel);
void CRKHAL_vidInit(void);
void CRKHAL_vidInjDriverRephase(uint16 u16AngleOffset);
void CRKHAL_vidSetAbsAlarm(uint8  u8Channel, uint16 u16AbsoluteAngle);
void CRKHAL_vidSetMode(CRKHAL_tenuMode enuMode);
void CRKHAL_vidSetRelAlarm(uint8  u8Channel, uint16 u16RelativeAngle);
void CRKHAL_vidStartOfSyncWinIsr(void);
void CRKHAL_vidSynchSearchAndCtlIsr(void);
void CRKHAL_vidTimCrkInputToDpllIsr(void);
void CRKHAL_vidTimCrkInputToMcsIsr(void);
void CRKHAL_vidMcsTaskMgmtIsr(void);
void CRKHAL_vidDirectionChangeIsr(void);
void CRKHAL_vidStopPosCalculation(uint8 *pu8ToothPosition,uint16 *pu16CountPosition);
void CRKHAL_vidSyncFoundMngt(void);
void CRKHAL_vidDeltaOnAngleUpdate(uint32 u32LocalCurrAbsAng_1);
void CRKHAL_vidEngRun(void);
void CRKHAL_vidCfgDirDetThreshold(void);
Std_ReturnType CRKHAL_udtDisableBwdRotation(void);
Std_ReturnType CRKHAL_udtDisableDetection(void);
Std_ReturnType CRKHAL_udtDisableQuickSynchro(void);
Std_ReturnType CRKHAL_udtDisableSynchronisation(void);
Std_ReturnType CRKHAL_udtEnableBwdRotation(void);
Std_ReturnType CRKHAL_udtEnableDetection(void);
Std_ReturnType CRKHAL_udtEnableQuickSynchro(void);
Std_ReturnType CRKHAL_udtEnableSynchronisation(void);
Std_ReturnType CRKHAL_udtForceDesynchronisation(void);
Std_ReturnType CRKHAL_udtGetDeltaAngleOnSync(uint16 *pu16DeltaAngle);
Std_ReturnType CRKHAL_udtGetEngStopPosition(uint8 u8StopPositionType, uint16 *pu16StopPosition);
Std_ReturnType CRKHAL_udtGetOorPulseInfo(uint8 *pu8OorPulseCounter, uint8 *pu8TeethCounter);
Std_ReturnType CRKHAL_udtGetRoundedAngle(uint16 u16Angle, uint16 *pu16RoundedAngle);
Std_ReturnType CRKHAL_udtGetTargetToothAngle(uint16 *pu16ToothAngle);
Std_ReturnType CRKHAL_udtGetToothInfo(uint8 u8MaxTableSize, uint32 *pau32ToothInfoTable);
Std_ReturnType CRKHAL_udtReadMode(CRKHAL_tenuMode *penuMode);
Std_ReturnType CRKHAL_udtReadStatus(uint8 u8Channel, boolean *pbStatus);
Std_ReturnType CRKHAL_udtReadTeethAftrSyncLoss(uint16 *pu16TeethNumber);
Std_ReturnType CRKHAL_udtReadToothEdgeDate(uint32 *pu32Date);
Std_ReturnType CRKHAL_udtTimeToAngle(uint32 u32Time, uint16 *pu16Angle);
Std_ReturnType CRKHAL_udtWriteDesynchroRpmThd(uint16 u16EngineSpeedThd);
Std_ReturnType CRKHAL_udtWriteEnaToothTskRpmThd(uint16 u16EngineSpeedThd);
Std_ReturnType CRKHAL_udtGetSpecificToothInfo(uint8 ToothNb, uint8 u8MaxTableSize,
		uint32 *pau32ToothInfoTable);

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

#endif /* CRKHAL_H */

/*-------------------------------- end of file -------------------------------*/
