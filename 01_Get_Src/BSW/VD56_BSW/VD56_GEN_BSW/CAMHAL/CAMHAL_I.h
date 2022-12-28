/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_I.H                                              */
/* !Description     : Contains internal macros of the CAMHAL component        */
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
 * %PID: P2017_BSW:A81085.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CAMHAL_I_H
#define CAMHAL_I_H

#include "Std_Types.h"
#include "Std_Limits.h"
/*#include "ANGSCHED.h"*/
#include "CAMHAL_L.h"
#include "CAMHAL_Typ.h"
#include "SWFAIL.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_vidSYNC_LOSS                                         */
/* !Description : Synchronisation loss treatment                              */
/******************************************************************************/
#define CAMHAL_vidSYNC_LOSS(udtChannelName) \
do \
{ \
   CAMHAL_abSynchronised[udtChannelName]         = (boolean)FALSE; \
   CAMHAL_aenuPatternDiagStatus[udtChannelName]  = \
      CAMHAL_udtPATTERN_DIAG_DISABLED; \
   CAMHAL_au8ToothCounter[udtChannelName]        = (uint8)UINT8_MIN; \
   CAMHAL_aenuPatternStatus[udtChannelName]      = \
      CAMHAL_udtPATTERN_NOT_DETECTED; \
   CAMHAL_aenuLastCylinderNumber[udtChannelName] = (CAMHAL_tenuCylinderNumber)CAMHAL_udtUNKNOWN_CYLINDER; \
   CAMHAL_aenuCylinderNumber[udtChannelName]     = (CAMHAL_tenuCylinderNumber)CAMHAL_udtUNKNOWN_CYLINDER; \
   CAMHAL_abDesynchroRequested[udtChannelName]   = (boolean)FALSE; \
   CAMHAL_au8Position[udtChannelName]            = CAMHAL_udtPOSITION_INIT; \
   CAMHAL_au8ExpectedPosition[udtChannelName]    = CAMHAL_udtPOSITION_INIT; \
   CAMHAL_au32LastEventTime[udtChannelName]      = (uint32)UINT32_MIN; \
   CAMHAL_abDesynchroDetected[udtChannelName]    = (boolean)FALSE; \
   CAMHAL_abFirstCamPeriodCalc[udtChannelName]   = (boolean)TRUE; \
 \
   if (CAMHAL_kabSyncLossPeriodInit[udtChannelName] == (boolean)TRUE) \
   { \
      CAMHAL_au32CamToothPeriod[udtChannelName]  = (uint32)UINT32_MAX; \
      CAMHAL_vidRUN_TO_STALL(udtChannelName); \
   } \
} \
while (0)

/* todo ANGSCHED_vidDisable(CAMHAL_u8ANGSCHED_ALARM); */
/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_vidRUN_TO_STALL                                      */
/* !Description : Stall treatment                                             */
/******************************************************************************/
#define CAMHAL_vidRUN_TO_STALL(udtChannelName) \
do \
{ \
   CAMHAL_abRunning[udtChannelName]            = (boolean)FALSE; \
   CAMHAL_au8RunningTimeoutCnt[udtChannelName] = \
      CAMHAL_kau8RunningThreshold[udtChannelName]; \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_vidSIGNAL_LOSS                                       */
/* !Description : Signal loss treatment                                       */
/******************************************************************************/
#define CAMHAL_vidSIGNAL_LOSS(udtChannelName) \
do \
{ \
   CAMHAL_abDetected[udtChannelName]             = (boolean)FALSE; \
   CAMHAL_abEnableCaptMng[udtChannelName]        = (boolean)FALSE; \
   CAMHAL_au8EventCounter[udtChannelName]        = (uint8)UINT8_MIN; \
   CAMHAL_abPreviousGap[udtChannelName]          = (boolean)FALSE; \
   CAMHAL_abFirstCamPeriod[udtChannelName]       = (boolean)TRUE; \
   CAMHAL_abEvtPositionAvailable[udtChannelName] = (boolean)FALSE; \
   CAMHAL_au32CamToothPeriod[udtChannelName]     = (uint32)UINT32_MAX; \
   CAMHAL_au8DetectedTimeoutCnt[udtChannelName]  = \
      CAMHAL_kau8DetectedThreshold[udtChannelName]; \
   CAMHAL_au32LastToothDuration[udtChannelName]  = (uint32)UINT32_MIN; \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_vidSET_RELOAD_COUNTER                                */
/* !Description : Set Tick duration for Angular Clock Generation              */
/******************************************************************************/
#define CAMHAL_vidSET_RELOAD_COUNTER(value) \
do \
{ \
   ATUDRV_vidWRITE(ATU_B_MUL_CLK_RELOAD_VAL, (uint32)(value)); \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_udtCALC_POSITION                                     */
/* !Description : Calculate current position.                                 */
/*                The last position is shifted to left; the LSB is set 1 if   */
/*                it's a long tooth, 0 if it's a short one. the cam level is  */
/*                set on bit 3. The 4 LSBs take the following form            */
/*                [cam level][tooth(n-2)type][tooth(n-2)type][tooth(n)type]   */
/******************************************************************************/
#define CAMHAL_udtCALC_POSITION(u8LastPosition, bToothType, bCamLevel) \
   ((0x06 & ((u8LastPosition) << 1)) | (bToothType) | ((bCamLevel) << 3))

/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_vidEXPECT_NEXT_POSITION                              */
/* !Description : Update the pattern form. It's used in the PSA EBx driver.   */
/*                The sequence is:0x04, 0x08, 0x00, 0x09, 0x03, 0x0E, 0x04,...*/
/*                This macro is used when CAMHAL_kau16CamSynchroMode equals   */
/*                CAMHAL_u16PSA_3CYL_CAMSHAFT                                 */
/******************************************************************************/
#define CAMHAL_vidEXPECT_NEXT_POSITION(udtChannelName) \
do \
{ \
   switch (CAMHAL_au8Position[udtChannelName]) \
   { \
      case CAMHAL_udtPOSITION_1: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_2; \
         break; \
      case CAMHAL_udtPOSITION_2: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_3; \
         break; \
      case CAMHAL_udtPOSITION_3: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_4; \
         break; \
      case CAMHAL_udtPOSITION_4: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_5; \
         break; \
      case CAMHAL_udtPOSITION_5: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_6; \
         break; \
      case CAMHAL_udtPOSITION_6: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_1; \
         break; \
      case CAMHAL_udtPOSITION_INIT: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_INIT; \
         break; \
      default: \
         CAMHAL_au8ExpectedPosition[udtChannelName] = CAMHAL_udtPOSITION_INIT; \
         SWFAIL_vidSoftwareErrorHook(); \
         break; \
   } \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_vidGET_NEXT_CYLINDER_4                               */
/* !Description : Updates CAMHAL_aenuCylinderNumber according to the value of */
/*                last cylinder number. It's used in the 4 cylinder drivers.  */
/*                This macro is used when CAMHAL_kau16CamSynchroMode equals   */
/*                CAMHAL_u16NSN_4CYL_CAMSHAFT or CAMHAL_u16RSA_STD_CAMSHAFT   */
/******************************************************************************/
#define CAMHAL_vidGET_NEXT_CYLINDER_4(udtChannelName) \
do \
{ \
   switch (CAMHAL_aenuLastCylinderNumber[udtChannelName]) \
   { \
      case CAMHAL_udtFIRST_CYLINDER: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = \
            CAMHAL_udtSECOND_CYLINDER; \
         break; \
      case CAMHAL_udtSECOND_CYLINDER: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = CAMHAL_udtTHIRD_CYLINDER; \
         break; \
      case CAMHAL_udtTHIRD_CYLINDER: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = \
            CAMHAL_udtFOURTH_CYLINDER; \
         break; \
      case CAMHAL_udtFOURTH_CYLINDER: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = CAMHAL_udtFIRST_CYLINDER; \
         break; \
      default: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = \
            CAMHAL_udtUNKNOWN_CYLINDER; \
         SWFAIL_vidSoftwareErrorHook(); \
         break; \
   } \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Updates CAMHAL_aenuCylinderNumber according to the value of */
/*                last cylinder number. It's used in the 3 cylinder drivers   */
/*                This macro is used when CAMHAL_kau16CamSynchroMode equals   */
/*                CAMHAL_u16PSA_3CYL_CAMSHAFT or CAMHAL_u16RSA_STD_CAMSHAFT   */
/******************************************************************************/
#define CAMHAL_vidGET_NEXT_CYLINDER_3(udtChannelName) \
do \
{ \
   switch (CAMHAL_aenuLastCylinderNumber[udtChannelName]) \
   { \
      case CAMHAL_udtFIRST_CYLINDER: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = \
            CAMHAL_udtSECOND_CYLINDER; \
         break; \
      case CAMHAL_udtSECOND_CYLINDER: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = CAMHAL_udtTHIRD_CYLINDER; \
         break; \
      case CAMHAL_udtTHIRD_CYLINDER: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = CAMHAL_udtFIRST_CYLINDER; \
         break; \
      default: \
         CAMHAL_aenuCylinderNumber[udtChannelName] = \
            CAMHAL_udtUNKNOWN_CYLINDER; \
         SWFAIL_vidSoftwareErrorHook(); \
         break; \
   } \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !FuncName    : CAMHAL_vidCONVERT_ANGLE_TO_TICK                             */
/* !Description : Converts Angle value into Tick value for Angular Clock      */
/*                Generation                                                  */
/******************************************************************************/
#define CAMHAL_vidCONVERT_ANGLE_TO_TICK(angle_value, tick_value) \
do \
{ \
   uint16 u16LocalResult; \
   uint32 u32LocalResult; \
   \
   \
   /* !Comment: scaling 1 CRK deg per 64 -> 1 tooth per 64 */ \
   u16LocalResult = (uint16)((angle_value) / CAMHAL_u8DEG_TO_TOOTH_FACTOR); \
   \
   /* !Comment: applying TDC1 Offset */ \
   u32LocalResult = (uint32)(CAMHAL_u16TDC_1_POSITION + u16LocalResult); \
   \
   if (u32LocalResult >= CAMHAL_u16ENG_CYCLE_TICK_VALUE) \
   { \
      u32LocalResult -= CAMHAL_u16ENG_CYCLE_TICK_VALUE; \
   } \
   \
   (tick_value) = (uint16)(u32LocalResult); \
} \
while (0)

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define CAMHAL_START_SEC_CALIB_16BIT
#include "CAMHAL_MemMap.h"

extern const uint16 CAMHAL_kau16CamSynchroMode[CAMHAL_udtCHANNELS_NUMBER];
#if (CAMHAL_bNSN_4CYL_ALLOWED == 1)
extern const uint16 CAMHAL_kau16EdgeToTdcAngleOffset[CAMHAL_udtCHANNELS_NUMBER];
#endif
extern const uint16 CAMHAL_kau16StdByEventPosition[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_CALIB_16BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_CALIB_8BIT
#include "CAMHAL_MemMap.h"

extern const uint8 CAMHAL_kau8DetectedThreshold[CAMHAL_udtCHANNELS_NUMBER];
extern const uint8 CAMHAL_kau8LongToothRecoRatio[CAMHAL_udtCHANNELS_NUMBER];
extern const uint8 CAMHAL_kau8PatternCylinders[CAMHAL_udtCHANNELS_NUMBER][4];
extern const uint8 CAMHAL_kau8RunningThreshold[CAMHAL_udtCHANNELS_NUMBER];
extern const uint8 CAMHAL_kau8SynchroCylinders[CAMHAL_udtCHANNELS_NUMBER][2];

#define CAMHAL_STOP_SEC_CALIB_8BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_CALIB_BOOLEAN
#include "CAMHAL_MemMap.h"

#if (CAMHAL_bSTANDARD_ALLOWED == 1)
extern const boolean CAMHAL_kabSynchroSigLvlType[CAMHAL_udtCHANNELS_NUMBER];
#endif
extern const boolean CAMHAL_kabSyncLossPeriodInit[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_CALIB_BOOLEAN
#include "CAMHAL_MemMap.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define CAMHAL_START_SEC_VAR_CLEARED_32BIT
#include "CAMHAL_MemMap.h"

extern uint32 CAMHAL_au32CamToothPeriod[CAMHAL_udtCHANNELS_NUMBER];
extern uint32 CAMHAL_au32FirstToothDuration[CAMHAL_udtCHANNELS_NUMBER];
extern uint32 CAMHAL_au32LastEdgeDate[CAMHAL_udtCHANNELS_NUMBER];
extern uint32 CAMHAL_au32LastEventTime[CAMHAL_udtCHANNELS_NUMBER];
extern uint32 CAMHAL_au32LastToothDuration[CAMHAL_udtCHANNELS_NUMBER];
extern uint32 CAMHAL_au32PreviousEdgeTime[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_16BIT
#include "CAMHAL_MemMap.h"

extern uint16 CAMHAL_au16CylinderNbDate[CAMHAL_udtCHANNELS_NUMBER];
extern uint16 CAMHAL_au16EdgeAnglePosition_1[CAMHAL_udtCHANNELS_NUMBER];
extern uint16 CAMHAL_au16EdgeAnglePosition_2[CAMHAL_udtCHANNELS_NUMBER];
extern uint16 CAMHAL_au16EdgeAnglePosition_3[CAMHAL_udtCHANNELS_NUMBER];
extern uint16 CAMHAL_au16EdgeAnglePosition_4[CAMHAL_udtCHANNELS_NUMBER];
extern uint16 CAMHAL_au16EngineAngle[CAMHAL_udtCHANNELS_NUMBER];
extern uint16 CAMHAL_au16FallingEdgeCounter[CAMHAL_udtCHANNELS_NUMBER];
extern uint16 CAMHAL_au16RisingEdgeCounter[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_8BIT
#include "CAMHAL_MemMap.h"

extern uint8 CAMHAL_au8DetectedTimeoutCnt[CAMHAL_udtCHANNELS_NUMBER];
extern uint8 CAMHAL_au8EdgeCounter[CAMHAL_udtCHANNELS_NUMBER];
extern uint8 CAMHAL_au8EventCounter[CAMHAL_udtCHANNELS_NUMBER];
extern uint8 CAMHAL_au8ExpectedPosition[CAMHAL_udtCHANNELS_NUMBER];
extern uint8 CAMHAL_au8Position[CAMHAL_udtCHANNELS_NUMBER];
extern uint8 CAMHAL_au8RunningTimeoutCnt[CAMHAL_udtCHANNELS_NUMBER];
extern uint8 CAMHAL_au8ToothCounter[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "CAMHAL_MemMap.h"

extern boolean CAMHAL_abDesynchroDetected[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abDesynchroRequested[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abDetected[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abDetectionEnabled[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abEdgeType[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abEnableCaptMng[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abEvtActivationEnabled[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abEvtPositionAvailable[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abFirstCamPeriod[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abFirstCamPeriodCalc[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abNSNCamPosition[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abPreviousGap[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abPreviousToothType[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abRunning[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abSynchroEnabled[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abSynchronised[CAMHAL_udtCHANNELS_NUMBER];
extern boolean CAMHAL_abToothType[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CAMHAL_MemMap.h"

extern CAMHAL_tenuCylinderNumber
          CAMHAL_aenuCylinderNumber[CAMHAL_udtCHANNELS_NUMBER];
extern CAMHAL_tenuCylinderNumber
          CAMHAL_aenuLastCylinderNumber[CAMHAL_udtCHANNELS_NUMBER];
extern CAMHAL_tenuMode CAMHAL_aenuMode[CAMHAL_udtCHANNELS_NUMBER];
extern CAMHAL_tenuPatternDiagStatus
          CAMHAL_aenuPatternDiagStatus[CAMHAL_udtCHANNELS_NUMBER];
extern CAMHAL_tenuPatternStatus
          CAMHAL_aenuPatternStatus[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CAMHAL_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"

boolean CAMHAL_bDioRead(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidActivateCamEvent(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidActivateCamEdgeEvent(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidSyncLossEntry(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidDgoWriteFault(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidDgoWriteNoFault(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidNormalModeEntry(CAMHAL_tudtChannel udtChannelName);
CAMHAL_tenuCylinderNumber CAMHAL_enuGetCylinder(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidPatternManagement(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidDisableInputAcq(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidForceSignalLoss(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidDwnModeEntry(CAMHAL_tudtChannel udtChannelName);
void CAMHAL_vidCaptureManagement(CAMHAL_tudtChannel udtChannelName);


#if (CAMHAL_bSTANDARD_ALLOWED == 1)

void CAMHAL_vidSTANDARD_CaptureMng(CAMHAL_tudtChannel udtChannelName,uint32 u32EdgeTime);
void CAMHAL_vidSTANDARD_SetMode(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtSTANDARD_ReadCylNum(CAMHAL_tudtChannel udtChannelName,CAMHAL_tenuCylinderNumber *penuCylinderNumber);
Std_ReturnType CAMHAL_udtSTANDARD_ReadSigLvl(CAMHAL_tudtChannel udtChannelName,boolean *pbLevel);

#endif /* (CAMHAL_bSTANDARD_ALLOWED == 1) */

#if (CAMHAL_bPSA_3CYL_ALLOWED == 1)

void CAMHAL_vidPSA_3CYL_CaptureMng(CAMHAL_tudtChannel udtChannelName,uint32 u32EdgeTime);
void CAMHAL_vidPSA_3CYL_PatternMng(CAMHAL_tudtChannel udtChannelName,boolean* pbFaultExist);
void CAMHAL_vidPSA_3CYL_SetMode(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtPSA_3CYL_ReadCylNum(CAMHAL_tudtChannel udtChannelName,CAMHAL_tenuCylinderNumber* penuCylinderNumber);
Std_ReturnType CAMHAL_udtPSA_3CYL_ReadSigLvl(CAMHAL_tudtChannel udtChannelName,boolean* pbLevel);

#endif /* (CAMHAL_bPSA_3CYL_ALLOWED == 1) */

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"


#endif /* CAMHAL_I_H */


/*------------------------------- end of file --------------------------------*/
