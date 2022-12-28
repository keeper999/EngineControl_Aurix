/***************************************************************************
;**
;** FILE NAME      : VLVACTEXACTRTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXACTRTEST_L_H
#define VLVACTEXACTRTEST_L_H

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

extern const uint8  VLVACTEXACTRTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bExActrTestSpStatErrEna;
extern boolean VLVACTEXACTRTEST_bCompCalc1Prev;
extern boolean VLVACTEXACTRTEST_bCompCalc2Prev;
extern boolean VLVACTEXACTRTEST_SrvbExVVTEnPrev;
extern uint32 VlvAct_agExActrTestAddErrRef;
extern uint32 VlvAct_agExActrTestAddErrRefInt;
extern uint32 VlvAct_agExActrTstAddErrPrev;
extern uint32 VLVACTEXACTRTEST_u32CalcPhase1;
extern uint32 VLVACTEXACTRTEST_u32CalcPhase10;
extern uint32 VLVACTEXACTRTEST_u32CalcPhase3;
extern uint32 VLVACTEXACTRTEST_u32CalcPhase5;
extern uint32 VLVACTEXACTRTEST_u32CalcPhase8;
extern sint8 VlvAct_ExActrTestSpdErrorCompCoe;
extern uint8 VlvAct_ExActrTestSpdErrorTiThd;
extern uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;
extern uint16 VlvAct_tiExActrTestAvgTiStatErr;
extern uint16 VlvAct_tiExActrTestPosMesSpdErr;
extern uint16 VlvAct_tiExActrTestSp;
extern uint16 VlvAct_tiExActrTestSpSpdErr;
extern uint16 VlvAct_tiExActrTstSpdErr;
extern uint16 VLVACTEXACTRTEST_u16CalcPhase2;
extern uint16 VLVACTEXACTRTEST_u16CalcPhase4;
extern uint16 VLVACTEXACTRTEST_u16CalcPhase7;
extern uint16 VLVACTEXACTRTEST_u16CalcPhase9;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXACTRTEST_vidAgregatedErr(void);
void VLVACTEXACTRTEST_vidCalcSdlFast(void);
void VLVACTEXACTRTEST_vidCriteriaCalc(void);
void VLVACTEXACTRTEST_vidEndStTrans(void);
void VLVACTEXACTRTEST_vidFstSpdErrClc(void);
void VLVACTEXACTRTEST_vidIdleStTrans(void);
void VLVACTEXACTRTEST_vidInitializati(void);
void VLVACTEXACTRTEST_vidMeaCriTiComp(void);
void VLVACTEXACTRTEST_vidPhase10Trans(void);
void VLVACTEXACTRTEST_vidPhase1Trans(void);
void VLVACTEXACTRTEST_vidPhase2Trans(void);
void VLVACTEXACTRTEST_vidPhase3Trans(void);
void VLVACTEXACTRTEST_vidPhase4Trans(void);
void VLVACTEXACTRTEST_vidPhase5Trans(void);
void VLVACTEXACTRTEST_vidPhase6Trans(void);
void VLVACTEXACTRTEST_vidPhase7Trans(void);
void VLVACTEXACTRTEST_vidPhase8Trans(void);
void VLVACTEXACTRTEST_vidPhase9Trans(void);
void VLVACTEXACTRTEST_vidSetpointComp(void);
void VLVACTEXACTRTEST_vidSetpointCrit(void);
void VLVACTEXACTRTEST_vidSpdErrExCalc(void);
void VLVACTEXACTRTEST_vidSpeedErrorCo(void);
void VLVACTEXACTRTEST_vidSpeedErrorMe(void);
void VLVACTEXACTRTEST_vidStatErrorCom(void);
void VLVACTEXACTRTEST_vidStatErrorMea(void);
void VLVACTEXACTRTEST_vidStErrCritClc(void);


#endif /* VLVACTEXACTRTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
