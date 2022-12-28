/***************************************************************************
;**
;** FILE NAME      : VLVACTINACTRTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINACTRTEST.H"
#include "VLVACTINACTRTEST_L.H"
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
const uint8  VlvAct_InActrTestSpdErrSpThd1_C = 0;
const uint8  VlvAct_InActrTestSpdErrSpThd2_C = 0;
const uint8  VlvAct_InActrTestSpdErrSpThd3_C = 0;
const uint8  VlvAct_InActrTestSpdErrSpThd4_C = 0;
const uint8  VLVACTINACTRTEST_u8Inhib = 0;
const uint16  VlvAct_agInActrTestMaxPosSp_C = 0;
const uint16  VlvAct_agInActrTestMinPosSp_C = 0;
const uint16  VlvAct_agInActrTestStaErrThd_C = 0;
const uint16  VlvAct_tiInActrSpdTest1RampThd_C = 0;
const uint16  VlvAct_tiInActrSpdTest2RampThd_C = 0;
const uint16  VlvAct_tiInActrSpdTest3RampThd_C = 0;
const uint16  VlvAct_tiInActrSpdTest4RampThd_C = 0;
const uint16  VlvAct_tiInActrTest10SplSp_C = 0;
const uint16  VlvAct_tiInActrTest1SplSp_C = 0;
const uint16  VlvAct_tiInActrTest2SplSp_C = 0;
const uint16  VlvAct_tiInActrTest3SplSp_C = 0;
const uint16  VlvAct_tiInActrTest4SplSp_C = 0;
const uint16  VlvAct_tiInActrTest5SplSp_C = 0;
const uint16  VlvAct_tiInActrTest6SplSp_C = 0;
const uint16  VlvAct_tiInActrTest7SplSp_C = 0;
const uint16  VlvAct_tiInActrTest8SplSp_C = 0;
const uint16  VlvAct_tiInActrTest9SplSp_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 VlvAct_stInActrTst;
uint8 VlvAct_stInActrTstLstSt;
boolean Srv_bActrTstInVVTEna;
boolean VlvAct_bInActrTest1RampSpdErrIdc;
boolean VlvAct_bInActrTest2RampSpdErrIdc;
boolean VlvAct_bInActrTest3RampSpdErrIdc;
boolean VlvAct_bInActrTest4RampSpdErrIdc;
boolean VlvAct_bInActrTestNotRun;
boolean VlvAct_bInActrTestSpEndIdc;
boolean VlvAct_bInActrTestSpStatErrEna;
boolean VlvAct_bInActrTestStatErrMax1;
boolean VlvAct_bInActrTestStatErrMax2;
boolean VlvAct_bInActrTestStatErrRef1;
boolean VlvAct_bInActrTestStatErrRef2;
boolean VlvAct_bInActrTestStatErrRef3;
boolean VLVACTINACTRTEST_bCompCalc1Prev;
boolean VLVACTINACTRTEST_bCompCalc2Prev;
boolean VLVACTINACTRTEST_SrvbInVVTEnPrev;
uint32 VlvAct_agInActrTestAddErrRef;
uint32 VlvAct_agInActrTestAddErrRefInt;
uint32 VlvAct_agInActrTstAddErrPrev;
uint32 VLVACTINACTRTEST_u32CalcPhase1;
uint32 VLVACTINACTRTEST_u32CalcPhase10;
uint32 VLVACTINACTRTEST_u32CalcPhase3;
uint32 VLVACTINACTRTEST_u32CalcPhase5;
uint32 VLVACTINACTRTEST_u32CalcPhase8;
sint8 VlvAct_InActrTestSpdErrorCompCoe;
uint8 VlvAct_InActrTestSpdErrorTiThd;
uint8 VLVACTINACTRTEST_u8CdeTstActPrev;
uint16 VlvAct_agInActrTestPosSp;
uint16 VlvAct_tiInActrTestAvgTiStatErr;
uint16 VlvAct_tiInActrTestPosMesSpdErr;
uint16 VlvAct_tiInActrTestSp;
uint16 VlvAct_tiInActrTestSpSpdErr;
uint16 VlvAct_tiInActrTstSpdErr;
uint16 VLVACTINACTRTEST_u16CalcPhase2;
uint16 VLVACTINACTRTEST_u16CalcPhase4;
uint16 VLVACTINACTRTEST_u16CalcPhase7;
uint16 VLVACTINACTRTEST_u16CalcPhase9;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

