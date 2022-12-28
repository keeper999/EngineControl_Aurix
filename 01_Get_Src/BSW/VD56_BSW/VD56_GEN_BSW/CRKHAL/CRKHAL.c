/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL.c                                                */
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
 * %PID: P2017_BSW:A18529.A-SRC;7 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "CRKHAL_Cfg.h"

/******************************************************************************/
/* CALIBRATIONS                                                               */
/******************************************************************************/
#define CRKHAL_START_SEC_CALIB_BOOLEAN
#include "CRKHAL_MemMap.h"

const boolean CRKHAL_kbBidirSensorUsed   = (uint8)FALSE;
const boolean CRKHAL_kbEnaQuickSynchro   = (uint8)FALSE;
const boolean CRKHAL_kbSyncOnFirstCylEn  = (uint8)FALSE;
const boolean CRKHAL_kbSyncOnFourthCylEn = (uint8)FALSE;
const boolean CRKHAL_kbSyncOnSecondCylEn = (uint8)FALSE;
const boolean CRKHAL_kbSyncOnThirdCylEn  = (uint8)FALSE;

#define CRKHAL_STOP_SEC_CALIB_BOOLEAN
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_8BIT
#include "CRKHAL_MemMap.h"

const uint8 CRKHAL_ku8CrankshaftFactor = 6U;          /* 360/6=6 degrees */
const uint8 CRKHAL_ku8CrkInputSignal   = 0U;          /* 0 user configured Please configure
                                                         available options from - CRKHAL_GTM_CFG.H -
                                                            CRKHAL_TIM0CH0_IN_PORT PORT_xx_PIN_yy*/
/* 1 - Default pin PORT_02_PIN_00 will be assigned */
const uint8 CRKHAL_ku8CrkOnToothNr = 4U;
/* const uint8  CRKHAL_ku8EndStartCtrSynNbTooth = 0U; */
const uint8 CRKHAL_ku8MaxNbTeethWithoutLtoo = 145U;
const uint8 CRKHAL_ku8NumberOfCylinders     = 3U;
const uint8 CRKHAL_ku8NumberOfSingularities = 1U;     /* only 1 long tooth per rotation */
/* const uint8  CRKHAL_ku8StopPositionErrorMax  = 0U; */

#define CRKHAL_STOP_SEC_CALIB_8BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_16BIT
#include "CRKHAL_MemMap.h"
/* below configurations should be configurable as per resoltion after Calibration */
const uint16 CRKHAL_ku16EngSpeedThd         = UINT16_MAX; /* Default No Tooth Duration*/
const uint16 CRKHAL_ku16BiDirBwdPulseDurMax = (1040U);    /* 100ns Res */
const uint16 CRKHAL_ku16BiDirBwdPulseDurMin = (780U);     /* 100ns Res */
const uint16 CRKHAL_ku16BiDirFwdPulseDurMax = (520U);     /* 100ns Res */
const uint16 CRKHAL_ku16BiDirFwdPulseDurMin = (380U);     /* 100ns Res */
/* 0 for NoBiDir
 * 850 for 100ns Res */
/** Valeo configuration parameter for Doc..
 * a - CRKHAL_ku16BiDirTrgHoldTimMin
 * b - CRKHAL_ku32BidirSensorValidThd
 * c - CRKHAL_ku32NoiseCancelerTime
 * calibration.. the value should be Bwd Min value */
const uint16 CRKHAL_ku16BiDirTrgHoldTimMin = (780U);
/* CRKHAL_ku16EngineCycleAngle = ( (CRKHAL_ku16NbPhysTeeth + CRKHAL_udtNUM_GAP_TEETH)
 * CRKHAL_udtNUM_CYCLE
 * CRKHAL_u16NORMAL_TOOTH_ANGLE) */
const uint16 CRKHAL_ku16EngineCycleAngle = 46080U;
const uint16 CRKHAL_ku16NbPhysTeeth      = 58U;

/* const uint16  CRKHAL_ku16RotDirMngDelay    = 0U; */
const uint16 CRKHAL_ku16TDC_1_Angle = 9600U;           /* 150 degrees */

const uint16 CRKHAL_ku16SyncApt2bAtFirstCyl  = 3U;
const uint16 CRKHAL_ku16SyncApt2cAtFirstCyl  = 3U;
const uint16 CRKHAL_ku16SyncApt2bAtSecondCyl = 63U;
const uint16 CRKHAL_ku16SyncApt2cAtSecondCyl = 61U;
const uint16 CRKHAL_ku16SyncApt2bAtThirdCyl  = 63U;
const uint16 CRKHAL_ku16SyncApt2cAtThirdCyl  = 61U;
const uint16 CRKHAL_ku16SyncApt2bAtFourthCyl = 63U;
const uint16 CRKHAL_ku16SyncApt2cAtFourthCyl = 61U;

#define CRKHAL_STOP_SEC_CALIB_16BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_32BIT
#include "CRKHAL_MemMap.h"

/* Noise canceler is 64 means 6.5uSec since CLK0 is 100nSec */
/** For BiDir Sensor support the calibration value ~16 */
const uint32 CRKHAL_ku32NoiseCancelerTime = 64U;

const uint32 CRKHAL_ku32OffCrkDly           = 3200000U; /* 320ms with resolution = 100ns */
const uint32 CRKHAL_ku32StalDetThd          = 335000U;  /* 33.5ms with resolution = 100ns */
const uint32 CRKHAL_ku32BidirSensorValidThd = 5000U;    /* 500 uSec */
#define CRKHAL_STOP_SEC_CALIB_32BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_UNSPECIFIED
#include "CRKHAL_MemMap.h"

const CRKHAL_tenuEdgeTypeDetection CRKHAL_kenuEdgeTypeDetection = (CRKHAL_tenuEdgeTypeDetection)CRKHAL_udtFALLING_EDGE;

#define CRKHAL_STOP_SEC_CALIB_UNSPECIFIED
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/
#define CRKHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "CRKHAL_MemMap.h"

boolean CRKHAL_bAptPtrReset;
boolean CRKHAL_bBwdRotationPhase;
boolean CRKHAL_bChangeOfMindEnabled;
boolean CRKHAL_bDesynchroForcee;
boolean CRKHAL_bDesynchroThdEnabled;
boolean CRKHAL_bDetected;
boolean CRKHAL_bDetection;
boolean CRKHAL_bDirectionChangeDet;
boolean CRKHAL_bRotationDirection;
boolean CRKHAL_bEnaBwdRotationDetection;
boolean CRKHAL_bEnaLtooSearchAftRestart;
boolean CRKHAL_bStopPosAfterCalculation;
boolean CRKHAL_bEnaStopPosAfterCalc;
boolean CRKHAL_bEngPositionKnown;
boolean CRKHAL_bEngSynchronized;
boolean CRKHAL_bMcsFirstEdge;
boolean CRKHAL_bLtooFaultOccur;
boolean CRKHAL_bQuickSynchroEnabled;
boolean CRKHAL_bRestartPhase;
boolean CRKHAL_bRunning;
boolean CRKHAL_bSingularityDetected;
boolean CRKHAL_bChangeOfDirTaskEvent;
boolean CRKHAL_bStopPosCalculation;
boolean CRKHAL_bSynchroEnable;
boolean CRKHAL_bSynchronized;
boolean CRKHAL_ubGliLockStatus;
boolean CRKHAL_ubNutcCheck;
boolean CRKHAL_bFirstLtoo1Event;
#define CRKHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_32BIT
#include "CRKHAL_MemMap.h"

uint32 CRKHAL_u32EnaToothTskDurThd;
uint32 CRKHAL_u32EngRunThDuration;
uint32 CRKHAL_u32LongToothMaxDuration;
uint32 CRKHAL_u32LongToothStalDetThd;
uint32 CRKHAL_u32Ltoo1TbuValue;
uint32 CRKHAL_u32NumberOfMlt_Full;
uint32 CRKHAL_u32NumberOfMlt_Half;
uint32 CRKHAL_u32NumberOfMlt_Tdc;
uint32 CRKHAL_u32OffCrkDly;
uint32 CRKHAL_u32StalDetThd;
uint32 CRKHAL_u32ToothMaxDuration;
uint32 CRKHAL_u32ToothCntLtoo1event;
uint32 CRKHAL_u32LastToothDurInLtoo1;
uint32 CRKHAL_u32GlobalTeethOffset;
#define CRKHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CRKHAL_MemMap.h"

CRKHAL_tenuCylinderNumber CRKHAL_enuCylinderNumber;
CRKHAL_tenuMode           CRKHAL_enuMode;

uint32 *CRKHAL_ADT_Tx;

volatile Ifx_GTM_TIM_CH *CRKHAL_Tim0CrkToDpll;
volatile Ifx_GTM_TIM_CH *CRKHAL_Tim0CrkToMcs;

volatile uint32 *CRKHAL_pu32McsBiDirBwPlsDurMax;
volatile uint32 *CRKHAL_pu32McsBiDirBwPlsDurMin;
volatile uint32 *CRKHAL_pu32McsBiDirFwPlsDurMax;
volatile uint32 *CRKHAL_pu32McsBiDirFwPlsDurMin;
volatile uint32 *CRKHAL_pu32McsDuration;
volatile uint32 *CRKHAL_pu32McsEngineRunThd;
volatile uint32 *CRKHAL_pu32McsEngineSpeedThd;
volatile uint32 *CRKHAL_pu32McsEngineStatus;
volatile uint32 *CRKHAL_pu32McsPulseDiagCounter;
volatile uint32 *CRKHAL_pu32McsLtoo1event;
volatile uint32 *CRKHAL_pu32McsOnTime;
volatile uint32 *CRKHAL_pu32McsOorPulseCounter;
volatile uint32 *CRKHAL_pu32McsPrevToothDur;
volatile uint32 *CRKHAL_pu32McsTeeAfrLastSyLos;
volatile uint32 *CRKHAL_pu32McsBiDirEn;
volatile uint32 *CRKHAL_pu32McsBiDirDiaEn;
volatile uint32 *CRKHAL_pu32McsTskIntrEn;
volatile uint32 *CRKHAL_pu32McsBiDirBwdCnt;
volatile uint32 *CRKHAL_pu32McsBiDirFwdCnt;
volatile uint32 *CRKHAL_pu32McsBiDirChgMndEn;
volatile uint32 *CRKHAL_pu32McsToothCnt;
volatile uint32 *CRKHAL_pu32McsDirCfgEn;
volatile uint32 *CRKHAL_pu32McsBwdReliable;
volatile uint32 *CRKHAL_pu32McsBiDirFwTotCfg;
volatile uint32 *CRKHAL_pu32McsRotDirMngMaxDur;
volatile uint32 *CRKHAL_pu32McsT_2;


volatile uint32 *CRKHAL_pu32McsGlobalOffsetCnt;
volatile uint32 *CRKHAL_pu32McsGlobalTeethOffset;

volatile uint32 *CRKHAL_TOOTH_DUR_ARRAY;
volatile uint32 *CRKHAL_TOOTH_TIME_STAMP_ARRAY;

#define CRKHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_16BIT
#include "CRKHAL_MemMap.h"

uint16 CRKHAL_u16DeltaAngleOnSynchro;
uint16 CRKHAL_u16EngineCycleAngle;
uint16 CRKHAL_u16NbPhysTeeth;
uint16 CRKHAL_u16NumOfMissingTooth;
uint16 CRKHAL_u16NumOfSyncLoss;
uint16 CRKHAL_u16NumOfToothInExcess;
uint16 CRKHAL_u16OffsetInjDriver;
uint16 CRKHAL_u16PhyTeeth1Minus;
uint16 CRKHAL_u16PhyTeeth1Plus;
uint16 CRKHAL_u16EndFirstLongTooth;
uint16 CRKHAL_u16BegSecondLongTooth;
uint16 CRKHAL_u16PhyTeethFullScale;
uint16 CRKHAL_u16PhyTeethFullScale1Ms;
uint16 CRKHAL_u16PhyTeethFullScale1Ps;
uint16 CRKHAL_u16StopAngPosition;
uint16 CRKHAL_u16StopAngPositionAfter;
uint16 CRKHAL_u16SynchroCountPosition;
uint16 CRKHAL_u16TeethAftrLastSyncLoss;
uint16 CRKHAL_u16SynchroApt2bPosition;
uint16 CRKHAL_u16SynchroApt2cPosition;
uint16 CRKHAL_u16BegFirstLongToothPos;
uint16 CRKHAL_u16BegSecondLongToothPos;

#define CRKHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_8BIT
#include "CRKHAL_MemMap.h"

uint8 CRKHAL_u8CrkInputSignal;
uint8 CRKHAL_u8Apt2c;
uint8 CRKHAL_u8FwdTeeth;
/*uint8  CRKHAL_u8BiDirThresholdOffset;*/
/*uint8  CRKHAL_u8NtiVal;*/

#define CRKHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "CRKHAL_MemMap.h"

/*------------------------------ end of file ------------------------------*/
