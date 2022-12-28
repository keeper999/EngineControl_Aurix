/***************************************************************************
;**
;** FILE NAME      : VLVACTINACTRTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINACTRTEST_L_H
#define VLVACTINACTRTEST_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  VLVACTINACTRTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bInActrTestSpStatErrEna;
extern boolean VLVACTINACTRTEST_bCompCalc1Prev;
extern boolean VLVACTINACTRTEST_bCompCalc2Prev;
extern boolean VLVACTINACTRTEST_SrvbInVVTEnPrev;
extern uint32 VlvAct_agInActrTestAddErrRef;
extern uint32 VlvAct_agInActrTestAddErrRefInt;
extern uint32 VlvAct_agInActrTstAddErrPrev;
extern uint32 VLVACTINACTRTEST_u32CalcPhase1;
extern uint32 VLVACTINACTRTEST_u32CalcPhase10;
extern uint32 VLVACTINACTRTEST_u32CalcPhase3;
extern uint32 VLVACTINACTRTEST_u32CalcPhase5;
extern uint32 VLVACTINACTRTEST_u32CalcPhase8;
extern sint8 VlvAct_InActrTestSpdErrorCompCoe;
extern uint8 VlvAct_InActrTestSpdErrorTiThd;
extern uint8 VLVACTINACTRTEST_u8CdeTstActPrev;
extern uint16 VlvAct_tiInActrTestAvgTiStatErr;
extern uint16 VlvAct_tiInActrTestPosMesSpdErr;
extern uint16 VlvAct_tiInActrTestSp;
extern uint16 VlvAct_tiInActrTestSpSpdErr;
extern uint16 VlvAct_tiInActrTstSpdErr;
extern uint16 VLVACTINACTRTEST_u16CalcPhase2;
extern uint16 VLVACTINACTRTEST_u16CalcPhase4;
extern uint16 VLVACTINACTRTEST_u16CalcPhase7;
extern uint16 VLVACTINACTRTEST_u16CalcPhase9;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINACTRTEST_vidAgregatedErr(void);
void VLVACTINACTRTEST_vidCalcSdlFast(void);
void VLVACTINACTRTEST_vidCriteriaCalc(void);
void VLVACTINACTRTEST_vidEndStTrans(void);
void VLVACTINACTRTEST_vidFstSpdErrClc(void);
void VLVACTINACTRTEST_vidIdleStTrans(void);
void VLVACTINACTRTEST_vidInitializati(void);
void VLVACTINACTRTEST_vidMeaCriTiComp(void);
void VLVACTINACTRTEST_vidPhase10Trans(void);
void VLVACTINACTRTEST_vidPhase1Trans(void);
void VLVACTINACTRTEST_vidPhase2Trans(void);
void VLVACTINACTRTEST_vidPhase3Trans(void);
void VLVACTINACTRTEST_vidPhase4Trans(void);
void VLVACTINACTRTEST_vidPhase5Trans(void);
void VLVACTINACTRTEST_vidPhase6Trans(void);
void VLVACTINACTRTEST_vidPhase7Trans(void);
void VLVACTINACTRTEST_vidPhase8Trans(void);
void VLVACTINACTRTEST_vidPhase9Trans(void);
void VLVACTINACTRTEST_vidSetpointComp(void);
void VLVACTINACTRTEST_vidSetpointCrit(void);
void VLVACTINACTRTEST_vidSpdErrInCalc(void);
void VLVACTINACTRTEST_vidSpeedErrorCo(void);
void VLVACTINACTRTEST_vidSpeedErrorMe(void);
void VLVACTINACTRTEST_vidStatErrorCom(void);
void VLVACTINACTRTEST_vidStatErrorMea(void);
void VLVACTINACTRTEST_vidStErrCritClc(void);


#endif /* VLVACTINACTRTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
