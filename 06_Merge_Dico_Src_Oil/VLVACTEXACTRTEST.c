/***************************************************************************
;**
;** FILE NAME      : VLVACTEXACTRTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXACTRTEST.H"
#include "VLVACTEXACTRTEST_L.H"
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
const uint8  VlvAct_ExActrTestSpdErrSpThd1_C = 0;
const uint8  VlvAct_ExActrTestSpdErrSpThd2_C = 0;
const uint8  VlvAct_ExActrTestSpdErrSpThd3_C = 0;
const uint8  VlvAct_ExActrTestSpdErrSpThd4_C = 0;
const uint8  VLVACTEXACTRTEST_u8Inhib = 0;
const uint16  VlvAct_agExActrTestMaxPosSp_C = 0;
const uint16  VlvAct_agExActrTestMinPosSp_C = 0;
const uint16  VlvAct_agExActrTestStaErrThd_C = 0;
const uint16  VlvAct_tiExActrSpdTest1RampThd_C = 0;
const uint16  VlvAct_tiExActrSpdTest2RampThd_C = 0;
const uint16  VlvAct_tiExActrSpdTest3RampThd_C = 0;
const uint16  VlvAct_tiExActrSpdTest4RampThd_C = 0;
const uint16  VlvAct_tiExActrTest10SplSp_C = 0;
const uint16  VlvAct_tiExActrTest1SplSp_C = 0;
const uint16  VlvAct_tiExActrTest2SplSp_C = 0;
const uint16  VlvAct_tiExActrTest3SplSp_C = 0;
const uint16  VlvAct_tiExActrTest4SplSp_C = 0;
const uint16  VlvAct_tiExActrTest5SplSp_C = 0;
const uint16  VlvAct_tiExActrTest6SplSp_C = 0;
const uint16  VlvAct_tiExActrTest7SplSp_C = 0;
const uint16  VlvAct_tiExActrTest8SplSp_C = 0;
const uint16  VlvAct_tiExActrTest9SplSp_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 VlvAct_stExActrTst;
uint8 VlvAct_stExActrTstLstSt;
boolean Srv_bActrTstExVVTEna;
boolean VlvAct_bExActrTest1RampSpdErrIdc;
boolean VlvAct_bExActrTest2RampSpdErrIdc;
boolean VlvAct_bExActrTest3RampSpdErrIdc;
boolean VlvAct_bExActrTest4RampSpdErrIdc;
boolean VlvAct_bExActrTestNotRun;
boolean VlvAct_bExActrTestSpEndIdc;
boolean VlvAct_bExActrTestSpStatErrEna;
boolean VlvAct_bExActrTestStatErrMax1;
boolean VlvAct_bExActrTestStatErrMax2;
boolean VlvAct_bExActrTestStatErrRef1;
boolean VlvAct_bExActrTestStatErrRef2;
boolean VlvAct_bExActrTestStatErrRef3;
boolean VLVACTEXACTRTEST_bCompCalc1Prev;
boolean VLVACTEXACTRTEST_bCompCalc2Prev;
boolean VLVACTEXACTRTEST_SrvbExVVTEnPrev;
uint32 VlvAct_agExActrTestAddErrRef;
uint32 VlvAct_agExActrTestAddErrRefInt;
uint32 VlvAct_agExActrTstAddErrPrev;
uint32 VLVACTEXACTRTEST_u32CalcPhase1;
uint32 VLVACTEXACTRTEST_u32CalcPhase10;
uint32 VLVACTEXACTRTEST_u32CalcPhase3;
uint32 VLVACTEXACTRTEST_u32CalcPhase5;
uint32 VLVACTEXACTRTEST_u32CalcPhase8;
sint8 VlvAct_ExActrTestSpdErrorCompCoe;
uint8 VlvAct_ExActrTestSpdErrorTiThd;
uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;
uint16 VlvAct_agExActrTestPosSp;
uint16 VlvAct_tiExActrTestAvgTiStatErr;
uint16 VlvAct_tiExActrTestPosMesSpdErr;
uint16 VlvAct_tiExActrTestSp;
uint16 VlvAct_tiExActrTestSpSpdErr;
uint16 VlvAct_tiExActrTstSpdErr;
uint16 VLVACTEXACTRTEST_u16CalcPhase2;
uint16 VLVACTEXACTRTEST_u16CalcPhase4;
uint16 VLVACTEXACTRTEST_u16CalcPhase7;
uint16 VLVACTEXACTRTEST_u16CalcPhase9;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

