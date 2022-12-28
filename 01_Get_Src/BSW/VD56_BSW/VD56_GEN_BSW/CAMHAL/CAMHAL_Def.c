/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Data definition of the CAMHAL component                 */
/*                                                                            */
/* !File            : CAMHAL_Def.c                                            */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:A81087.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "CAMHAL_L.H"
#include "CAMHAL_Typ.H"
#include "CAMHAL.h"
#include "CAMHAL_CFG_I.h"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/

#define CAMHAL_START_SEC_CALIB_16BIT
#include "CAMHAL_MemMap.h"

const uint16 CAMHAL_kau16CamSynchroMode[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};

#if (CAMHAL_bNSN_4CYL_ALLOWED == 1)
const uint16 CAMHAL_kau16EdgeToTdcAngleOffset[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};
#endif

const uint16 CAMHAL_kau16StdByEventPosition[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};

#define CAMHAL_STOP_SEC_CALIB_16BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_CALIB_8BIT
#include "CAMHAL_MemMap.h"

const uint8 CAMHAL_kau8DetectedThreshold[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};

const uint8 CAMHAL_kau8LongToothRecoRatio[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};

const uint8 CAMHAL_kau8PatternCylinders[CAMHAL_udtCHANNELS_NUMBER][4] =
{
   {0U}
};

const uint8 CAMHAL_kau8RunningThreshold[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};

const uint8 CAMHAL_kau8SynchroCylinders[CAMHAL_udtCHANNELS_NUMBER][2] =
{
   {0U}
};

#define CAMHAL_STOP_SEC_CALIB_8BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_CALIB_BOOLEAN
#include "CAMHAL_MemMap.h"

#if (CAMHAL_bSTANDARD_ALLOWED == 1)
const boolean CAMHAL_kabSynchroSigLvlType[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};
#endif

const boolean CAMHAL_kabSyncLossPeriodInit[CAMHAL_udtCHANNELS_NUMBER] =
{
   0U
};

#define CAMHAL_STOP_SEC_CALIB_BOOLEAN
#include "CAMHAL_MemMap.h"


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define CAMHAL_START_SEC_VAR_CLEARED_32BIT
#include "CAMHAL_MemMap.h"

uint32 CAMHAL_au32CamToothPeriod[CAMHAL_udtCHANNELS_NUMBER];
uint32 CAMHAL_au32FirstToothDuration[CAMHAL_udtCHANNELS_NUMBER];
uint32 CAMHAL_au32LastEdgeDate[CAMHAL_udtCHANNELS_NUMBER];
uint32 CAMHAL_au32LastEventTime[CAMHAL_udtCHANNELS_NUMBER];
uint32 CAMHAL_au32LastToothDuration[CAMHAL_udtCHANNELS_NUMBER];
uint32 CAMHAL_au32PreviousEdgeTime[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_16BIT
#include "CAMHAL_MemMap.h"

uint16 CAMHAL_au16CylinderNbDate[CAMHAL_udtCHANNELS_NUMBER];
uint16 CAMHAL_au16EdgeAnglePosition_1[CAMHAL_udtCHANNELS_NUMBER];
uint16 CAMHAL_au16EdgeAnglePosition_2[CAMHAL_udtCHANNELS_NUMBER];
uint16 CAMHAL_au16EdgeAnglePosition_3[CAMHAL_udtCHANNELS_NUMBER];
uint16 CAMHAL_au16EdgeAnglePosition_4[CAMHAL_udtCHANNELS_NUMBER];
uint16 CAMHAL_au16EngineAngle[CAMHAL_udtCHANNELS_NUMBER];
uint16 CAMHAL_au16FallingEdgeCounter[CAMHAL_udtCHANNELS_NUMBER];
uint16 CAMHAL_au16RisingEdgeCounter[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_8BIT
#include "CAMHAL_MemMap.h"

uint8 CAMHAL_au8DetectedTimeoutCnt[CAMHAL_udtCHANNELS_NUMBER];
uint8 CAMHAL_au8EdgeCounter[CAMHAL_udtCHANNELS_NUMBER];
uint8 CAMHAL_au8EventCounter[CAMHAL_udtCHANNELS_NUMBER];
uint8 CAMHAL_au8ExpectedPosition[CAMHAL_udtCHANNELS_NUMBER];
uint8 CAMHAL_au8Position[CAMHAL_udtCHANNELS_NUMBER];
uint8 CAMHAL_au8RunningTimeoutCnt[CAMHAL_udtCHANNELS_NUMBER];
uint8 CAMHAL_au8ToothCounter[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "CAMHAL_MemMap.h"

boolean CAMHAL_abDesynchroDetected[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abDesynchroRequested[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abDetected[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abDetectionEnabled[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abEdgeType[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abEnableCaptMng[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abEvtActivationEnabled[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abEvtPositionAvailable[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abFirstCamPeriod[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abFirstCamPeriodCalc[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abNSNCamPosition[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abPreviousGap[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abPreviousToothType[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abRunning[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abSynchroEnabled[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abSynchronised[CAMHAL_udtCHANNELS_NUMBER];
boolean CAMHAL_abToothType[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CAMHAL_MemMap.h"

CAMHAL_tenuCylinderNumber CAMHAL_aenuCylinderNumber[CAMHAL_udtCHANNELS_NUMBER];
CAMHAL_tenuCylinderNumber
   CAMHAL_aenuLastCylinderNumber[CAMHAL_udtCHANNELS_NUMBER];
CAMHAL_tenuMode CAMHAL_aenuMode[CAMHAL_udtCHANNELS_NUMBER];
CAMHAL_tenuPatternDiagStatus
   CAMHAL_aenuPatternDiagStatus[CAMHAL_udtCHANNELS_NUMBER];
CAMHAL_tenuPatternStatus CAMHAL_aenuPatternStatus[CAMHAL_udtCHANNELS_NUMBER];

#define CAMHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CAMHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
