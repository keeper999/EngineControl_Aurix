/***************************************************************************
;**
;** FILE NAME      : INJACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJACTEST.H"
#include "INJACTEST_L.H"
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
const uint8  Inj_noInjFirstFull_C = 0;
const uint8  INJACTEST_u8Inhib = 0;
const uint16  ActrTstInj_TempoIdle_C = 0;
const uint16  Afts_tiDlyTotTestInj_C = 0;
const uint16  Afts_tiPerTestInj_C = 0;
const uint16  Afts_tiTestInj_C = 0;
const uint16  Inj_tiDlyFirstFillFu_C = 0;
const uint16  Inj_tiInjFirstFillFu_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Inj_stActrTst;
uint8 Inj_stFirstFull;
boolean ActrTest_bAcvInjFirstFillFu;
boolean Inj_bInj1TstCmpl;
boolean Inj_bInj2TstCmpl;
boolean Inj_bInj3TstCmpl;
boolean Inj_bInj4TstCmpl;
boolean Inj_bInjTstCmpl;
boolean Inj_bPwrRlyCmd;
boolean INJACTEST_bChgtActuator;
boolean INJACTEST_bMemFirstFillFuPrev;
boolean INJACTEST_bMemFirstFillFuPrev2;
boolean INJACTEST_bTestEna;
uint8 Inj_stActrTst_prev;
uint8 INJACTEST_u8CodeActrTestPrev;
uint16 ActrTstInj_CumulTime;
uint16 ActrTstInj_IntTime;
uint16 ActrTstInj_TempoIdle;
uint16 ActrTstInj_TimeToInject;
uint16 Inj_tiCntFirstFull;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

