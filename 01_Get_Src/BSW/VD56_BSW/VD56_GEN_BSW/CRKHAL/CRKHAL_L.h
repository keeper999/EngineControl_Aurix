/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL_L.h                                              */
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
 * %PID: P2017_BSW:A18534.A-SRC;8 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CRKHAL_L_H
#define CRKHAL_L_H

#include "Std_Types.h"
#include "CRKHAL_Cfg.h"
#include "CRKHAL_I.h"
#include "CRKHAL_Typ.h"
#include "IfxGtm_Typ.h"

/*lint -esym(960,8.7) */
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CRKHAL_bQUICK_SYNCHRO_DISABLED    (0U)
#define CRKHAL_bQUICK_SYNCHRO_ENABLED     (1U)
#define CRKHAL_u16_1_25_TOOTH_CRK         (80U)    /* CRKHAL_u16COMMON_ANGLE_RESOL * 1.25 */
#define CRKHAL_u16CNTB3_INIT_VAL_CRK_OFF  (64U)    /* 1 * CRKHAL_u16COMMON_ANGLE_RESOL */
#define CRKHAL_u16COEF_DESIRED_RESOL      (8U)
#define CRKHAL_u16COEF_TIMER_RESOL        (2U)
#define CRKHAL_u16CRK_OFF_TIMER_RESOL     (20000U) /* 2000 uSec */
#define CRKHAL_u16STALL_TIMER_RESOL       (5000U) /* 500 uSec */
#define CRKHAL_u16HALF_REVOL_SIZE         (11520U) /* 180 * CRKHAL_u16COMMON_ANGLE_RESOL */
#define CRKHAL_u16NB_PERIOD_TO_MEASURE    (1U)
#define CRKHAL_u16REVOL_OFFSET            23040 /* 360 * CRKHAL_u16COMMON_ANGLE_RESOL */
#define CRKHAL_u16TOOTH_NB_1ST_RUN        (0U)
#define CRKHAL_u16TOOTH_NB_2ND_RUN        (60U)
#define CRKHAL_u16TOOTH_TIMER_RESOLUTION  (200U)
#define CRKHAL_u32_1MIN_IN_RES_100NS      (600000000U)
#define CRKHAL_u32_500_MICRO_SEC          (5000U)
#define CRKHAL_u8ADAPT_RESOL_TIMER        (2U)
#define CRKHAL_u8BWD_TOOTH_NR             (1U)
#define CRKHAL_u8DEFAULT_CRK_INPUT_SGN    TIM0CH0_PORT_00_PIN_09 /* TIM0CH0 options */
#define CRKHAL_u8FAST_TEETH_NB_THD        (1U)
#define CRKHAL_u8FOUR_CYLINDERS           (4U)
#define CRKHAL_u8FWD_TOOTH_NR             (1U)
#define CRKHAL_u8LONG_TOOTH_SIZE          (2U)
#define CRKHAL_u8TEETH_INFO_TABLE_SIZE    (2U)
#define CRKHAL_u8THREE_CYLINDERS          (3U)
#define CRKHAL_u8TIME_TO_ANGLE_SCALE      (4U)
#define CRKHAL_u8TOOTH_DIR_MASK           (15U)
#define CRKHAL_u8TOOTH_TABLE_SIZE_MAX     5
#define CRKHAL_u8SPECIFIC_TOOTH_TABLE_SIZE_MAX     (2U)
#define CRKHAL_udtBOTH_EDGES              (3U)
#define CRKHAL_udtFALLING_EDGE            (2U)
#define CRKHAL_udtFIRST_CYLINDER          (CRKHAL_tenuCylinderNumber)2
#define CRKHAL_udtFOURTH_CYLINDER         (CRKHAL_tenuCylinderNumber)16
#define CRKHAL_udtNO_EDGE                 (0U)
#define CRKHAL_udtRISING_EDGE             (1U)
#define CRKHAL_udtSECOND_CYLINDER         (CRKHAL_tenuCylinderNumber)4
#define CRKHAL_udtTHIRD_CYLINDER          (CRKHAL_tenuCylinderNumber)8
#define CRKHAL_udtUNKNOWN_CYLINDER        (CRKHAL_tenuCylinderNumber)1
#define CRKHAL_udtNUM_GAP_TEETH           (2U)
#define CRKHAL_udtNUM_CYCLE               (2U)
#define NB_DENTS_CTRL_SYNCHRO             (6U)

/******************************************************************************/
/* CALIBRATIONS                                                               */
/******************************************************************************/
#define CRKHAL_START_SEC_CALIB_BOOLEAN
#include "CRKHAL_MemMap.h"

extern const boolean  CRKHAL_kbBidirSensorUsed;
extern const boolean  CRKHAL_kbEnaQuickSynchro;
extern const boolean  CRKHAL_kbSyncOnFirstCylEn;
extern const boolean  CRKHAL_kbSyncOnFourthCylEn;
extern const boolean  CRKHAL_kbSyncOnSecondCylEn;
extern const boolean  CRKHAL_kbSyncOnThirdCylEn;

#define CRKHAL_STOP_SEC_CALIB_BOOLEAN
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_32BIT
#include "CRKHAL_MemMap.h"

extern const uint32  CRKHAL_ku32NoiseCancelerTime;
extern const uint32  CRKHAL_ku32OffCrkDly;
extern const uint32  CRKHAL_ku32StalDetThd;
extern const uint32  CRKHAL_ku32BidirSensorValidThd;

#define CRKHAL_STOP_SEC_CALIB_32BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_UNSPECIFIED
#include "CRKHAL_MemMap.h"

extern const CRKHAL_tenuEdgeTypeDetection  CRKHAL_kenuEdgeTypeDetection;

#define CRKHAL_STOP_SEC_CALIB_UNSPECIFIED
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_8BIT
#include "CRKHAL_MemMap.h"

extern const uint8  CRKHAL_ku8CrankshaftFactor;
extern const uint8  CRKHAL_ku8CrkInputSignal;
extern const uint8  CRKHAL_ku8CrkOnToothNr;
extern const uint8  CRKHAL_ku8MaxNbTeethWithoutLtoo;
extern const uint8  CRKHAL_ku8NumberOfCylinders;
extern const uint8  CRKHAL_ku8NumberOfSingularities;

#define CRKHAL_STOP_SEC_CALIB_8BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_CALIB_16BIT
#include "CRKHAL_MemMap.h"

extern const uint16  CRKHAL_ku16EngSpeedThd;
extern const uint16  CRKHAL_ku16BiDirBwdPulseDurMax;
extern const uint16  CRKHAL_ku16BiDirBwdPulseDurMin;
extern const uint16  CRKHAL_ku16BiDirFwdPulseDurMax;
extern const uint16  CRKHAL_ku16BiDirFwdPulseDurMin;
extern const uint16  CRKHAL_ku16BiDirTrgHoldTimMin;
extern const uint16  CRKHAL_ku16EngineCycleAngle;
extern const uint16  CRKHAL_ku16NbPhysTeeth;
extern const uint16  CRKHAL_ku16TDC_1_Angle;
extern const uint16  CRKHAL_ku16SyncApt2bAtFirstCyl;
extern const uint16  CRKHAL_ku16SyncApt2cAtFirstCyl;
extern const uint16  CRKHAL_ku16SyncApt2bAtSecondCyl;
extern const uint16  CRKHAL_ku16SyncApt2cAtSecondCyl;
extern const uint16  CRKHAL_ku16SyncApt2bAtThirdCyl;
extern const uint16  CRKHAL_ku16SyncApt2cAtThirdCyl;
extern const uint16  CRKHAL_ku16SyncApt2bAtFourthCyl;
extern const uint16  CRKHAL_ku16SyncApt2cAtFourthCyl;

#define CRKHAL_STOP_SEC_CALIB_16BIT
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/
#define CRKHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "CRKHAL_MemMap.h"

extern boolean CRKHAL_bAptPtrReset;
extern boolean CRKHAL_bBwdRotationPhase;
extern boolean CRKHAL_bChangeOfMindEnabled;
extern boolean CRKHAL_bDesynchroForcee;
extern boolean CRKHAL_bDesynchroThdEnabled;
extern boolean CRKHAL_bDetected;
extern boolean CRKHAL_bDetection;
extern boolean CRKHAL_bDirectionChangeDet;
extern boolean CRKHAL_bRotationDirection;
extern boolean CRKHAL_bEnaBwdRotationDetection;
extern boolean CRKHAL_bEnaLtooSearchAftRestart;
extern boolean CRKHAL_bEnaStopPosAfterCalc;
extern boolean CRKHAL_bStopPosAfterCalculation;
extern boolean CRKHAL_bEngPositionKnown;
extern boolean CRKHAL_bEngSynchronized;
/*extern boolean CRKHAL_bFastEngSpeedConfirmed;*/
extern boolean CRKHAL_bMcsFirstEdge;
extern boolean CRKHAL_bLtooFaultOccur;
extern boolean CRKHAL_bQuickSynchroEnabled;
extern boolean CRKHAL_bRestartPhase;
extern boolean CRKHAL_bRunning;
extern boolean CRKHAL_bSingularityDetected;
extern boolean CRKHAL_bChangeOfDirTaskEvent;
extern boolean CRKHAL_bStopPosCalculation;
extern boolean CRKHAL_bSynchroEnable;
extern boolean CRKHAL_bSynchronized;
extern boolean CRKHAL_ubGliLockStatus;
extern boolean CRKHAL_ubNutcCheck;
/*extern boolean CRKHAL_bFwdCntCfg;*/
extern boolean CRKHAL_bFirstLtoo1Event;
#define CRKHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_32BIT
#include "CRKHAL_MemMap.h"

extern uint32 CRKHAL_u32EnaToothTskDurThd;
extern uint32 CRKHAL_u32EngRunThDuration;
extern uint32 CRKHAL_u32GlobalTeethOffset;
extern uint32 CRKHAL_u32LongToothMaxDuration;
extern uint32 CRKHAL_u32LongToothStalDetThd;
extern uint32 CRKHAL_u32Ltoo1TbuValue;
extern uint32 CRKHAL_u32NumberOfMlt_Full;
extern uint32 CRKHAL_u32NumberOfMlt_Half;
extern uint32 CRKHAL_u32NumberOfMlt_Tdc;
extern uint32 CRKHAL_u32OffCrkDly;
extern uint32 CRKHAL_u32StalDetThd;
extern uint32 CRKHAL_u32ToothMaxDuration;
extern uint32 CRKHAL_u32ToothCntLtoo1event;
/*extern uint32 CRKHAL_u32BiDirFwdToothCnt;
extern uint32 CRKHAL_u32BiDirBwdToothCnt;*/
extern uint32 CRKHAL_u32LastToothDurInLtoo1;

#define CRKHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CRKHAL_MemMap.h"

extern CRKHAL_tenuCylinderNumber CRKHAL_enuCylinderNumber;
extern CRKHAL_tenuMode           CRKHAL_enuMode;

extern uint32 *CRKHAL_ADT_Tx;

extern volatile Ifx_GTM_TIM_CH* CRKHAL_Tim0CrkToDpll;
extern volatile Ifx_GTM_TIM_CH* CRKHAL_Tim0CrkToMcs;

extern volatile uint32 *CRKHAL_pu32McsBiDirBwPlsDurMax;
extern volatile uint32 *CRKHAL_pu32McsBiDirBwPlsDurMin;
extern volatile uint32 *CRKHAL_pu32McsBiDirFwPlsDurMax;
extern volatile uint32 *CRKHAL_pu32McsBiDirFwPlsDurMin;
extern volatile uint32 *CRKHAL_pu32McsDuration;
extern volatile uint32 *CRKHAL_pu32McsEngineRunThd;
extern volatile uint32 *CRKHAL_pu32McsEngineSpeedThd;
extern volatile uint32 *CRKHAL_pu32McsEngineStatus;
extern volatile uint32 *CRKHAL_pu32McsPulseDiagCounter;
extern volatile uint32 *CRKHAL_pu32McsLtoo1event;
extern volatile uint32 *CRKHAL_pu32McsOnTime;
extern volatile uint32 *CRKHAL_pu32McsOorPulseCounter;
extern volatile uint32 *CRKHAL_pu32McsPrevToothDur;
extern volatile uint32 *CRKHAL_pu32McsPulseDiagCounter;
extern volatile uint32 *CRKHAL_pu32McsTeeAfrLastSyLos;
extern volatile uint32 *CRKHAL_pu32McsBiDirEn;
extern volatile uint32 *CRKHAL_pu32McsBiDirDiaEn;
extern volatile uint32 *CRKHAL_pu32McsTskIntrEn;
extern volatile uint32 *CRKHAL_pu32McsBiDirBwdCnt;
extern volatile uint32 *CRKHAL_pu32McsBiDirFwdCnt;
extern volatile uint32 *CRKHAL_pu32McsBiDirChgMndEn;
extern volatile uint32 *CRKHAL_pu32McsToothCnt;
extern volatile uint32 *CRKHAL_TOOTH_DUR_ARRAY;
extern volatile uint32 *CRKHAL_TOOTH_TIME_STAMP_ARRAY;
extern volatile uint32 *CRKHAL_pu32McsPrevToothDur;
extern volatile uint32 *CRKHAL_pu32McsToothCnt;
extern volatile uint32 *CRKHAL_pu32McsDirCfgEn;
extern volatile uint32 *CRKHAL_pu32McsBwdReliable;
extern volatile uint32 *CRKHAL_pu32McsBiDirFwTotCfg;
extern volatile uint32 *CRKHAL_pu32McsRotDirMngMaxDur;
extern volatile uint32 *CRKHAL_pu32McsT_2;
extern volatile uint32 *CRKHAL_pu32McsGlobalOffsetCnt;
extern volatile uint32 *CRKHAL_pu32McsGlobalTeethOffset;
/*extern volatile uint32 *CRKHAL_pu32McsRotationDir;
extern volatile uint32 *CRKHAL_pu32McsDirChange;
extern volatile uint32 *CRKHAL_pu32McsDirConfirm;*/

#define CRKHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_16BIT
#include "CRKHAL_MemMap.h"

extern uint16 CRKHAL_u16DeltaAngleOnSynchro;
extern uint16 CRKHAL_u16EngineCycleAngle;
extern uint16 CRKHAL_u16NbPhysTeeth;
extern uint16 CRKHAL_u16NumOfMissingTooth;
extern uint16 CRKHAL_u16NumOfSyncLoss;
extern uint16 CRKHAL_u16NumOfToothInExcess;
extern uint16 CRKHAL_u16OffsetInjDriver;
extern uint16 CRKHAL_u16PhyTeeth1Minus;
extern uint16 CRKHAL_u16PhyTeeth1Plus;
extern uint16 CRKHAL_u16EndFirstLongTooth;
extern uint16 CRKHAL_u16BegSecondLongTooth;
extern uint16 CRKHAL_u16PhyTeethFullScale;
extern uint16 CRKHAL_u16PhyTeethFullScale1Ms;
extern uint16 CRKHAL_u16PhyTeethFullScale1Ps;
extern uint16 CRKHAL_u16StopAngPosition;
extern uint16 CRKHAL_u16StopAngPositionAfter;
extern uint16 CRKHAL_u16SynchroCountPosition;
extern uint16 CRKHAL_u16TeethAftrLastSyncLoss;
extern uint16 CRKHAL_u16SynchroApt2bPosition;
extern uint16 CRKHAL_u16SynchroApt2cPosition;
extern uint16 CRKHAL_u16BegFirstLongToothPos;
extern uint16 CRKHAL_u16BegSecondLongToothPos;

#define CRKHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "CRKHAL_MemMap.h"

#define CRKHAL_START_SEC_VAR_CLEARED_8BIT
#include "CRKHAL_MemMap.h"

extern uint8  CRKHAL_u8CrkInputSignal;
extern uint8  CRKHAL_u8Apt2c;
extern uint8  CRKHAL_u8FwdTeeth;
/*extern uint8  CRKHAL_u8BiDirThresholdOffset;*/
/*extern uint8  CRKHAL_u8NtiVal;*/

#define CRKHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

void CRKHAL_vidDesyncManagement(void);
void CRKHAL_vidEngStopManagement(void);
void CRKHAL_vidForceSignalLoss(void);
void CRKHAL_vidStallDetection(void);
void CRKHAL_vidSynchroCrkTimerConf(void);
void CRKHAL_vidSynchroFound(void);
extern void CRKHAL_vidSynchroLost(void);
void CRKHAL_vidUpdateAngAlarms(uint16 u16AngleOffset);

void CRKHAL_vidTimCrkInputToDpllIsr(void);
void CRKHAL_vidTimCrkInputToMcsIsr(void);
void CRKHAL_vidDpllLongToothIsr(void);
void CRKHAL_vidDpllGetLockIsr(void);
void CRKHAL_vidStartOfSyncWinIsr(void);
void CRKHAL_vidSynchSearchAndCtlIsr(void);
void CRKHAL_vidDirectionChangeIsr(void);
void CRKHAL_vidCrkOnMngtIsr(void);
void CRKHAL_vidDpllLostLockIsr(void);
void CRKHAL_vidUpdateIntAngOffIsr(void);
void CRKHAL_vidMcsTaskMgmtIsr(void);

void GTM_ISR_ATOM0_SR0(void);
void GTM_ISR_ATOM0_SR1(void);
void GTM_ISR_ATOM0_SR2(void);
void GTM_ISR_ATOM0_SR3(void);
void GTM_ISR_ATOM3_SR0(void);

void GTM_ISR_ATOM1_SR0(void);
void GTM_ISR_ATOM1_SR1(void);
void GTM_ISR_ATOM2_SR2(void);

void GTM_ISR_TIM0_SR2(void) ;
void GTM_ISR_TIM0_SR4(void);


#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

#endif /* CRKHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
