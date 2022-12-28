/***************************************************************************
;**
;** FILE NAME      : THRACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRACTEST.H"
#include "THRACTEST_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#pragma section ".calib" a
const uint8  ActrTstThr_DynTstMaxDiffPosn = 0;
const uint8  ActrTstThr_GapTstMaxDiffPosn = 0;
const uint8  ActrTstThr_GapTstMinDiffPosn = 0;
const uint8  ActrTstThr_HighPosn = 0;
const uint8  ActrTstThr_LowPosn = 0;
const uint8  ActrTstThr_MidPosn = 0;
const uint8  THRACTEST_u8Inhib = 0;
const uint16  ActrTstThr_DynTstDwnTime = 0;
const uint16  ActrTstThr_DynTstUpTime = 0;
const uint16  ActrTstThr_GapTstTime = 0;
const uint16  ActrTstThr_Phase1Time = 0;
const uint16  ActrTstThr_Phase2Time = 0;
const uint16  ActrTstThr_Phase3Time = 0;
const uint16  ActrTstThr_Phase4Time = 0;
const uint16  ActrTstThr_Phase5Time = 0;
const uint16  ActrTstThr_Phase6Time = 0;
const uint16  ActrTstThr_Phase7Time = 0;
const uint16  ActrTstThr_Tempo_C = 0;
const uint16  ActrTstThr_WaitTime = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Thr_stActrTst;
uint8 Thr_stDynTst;
uint8 Thr_stGapTst;
boolean ActrTstThr_GapDetn;
boolean ActrTstThr_IntGapTstRes;
boolean ActrTstThr_RunDynTest;
boolean ActrTstThr_RunGapTest;
boolean ActrTstThr_StopDynTest;
boolean ActrTstThr_StopGapTest;
boolean Thr_bDynActrTst;
boolean Thr_bGapActrTst;
boolean Thr_bThrTstCmpl;
boolean Thr_bTstInProgs;
boolean THRACTEST_bTstInProgsPrev;
uint8 ActrTstThr_ChgtSp;
uint8 THRACTEST_u8ActrTstThrChgtSpPrev;
uint16 ActrDynTstThr_TstTime;
uint16 ActrGapTstThr_TstTime;
uint16 ActrTstThr_Tempo;
uint16 ActrTstThr_TstTime;
uint16 Thr_rSpPosActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

