/***************************************************************************
;**
;** FILE NAME      : INJACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJACTEST_L_H
#define INJACTEST_L_H

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

/* enum st83 */
#define INJ_ACTRTST_IDLE                  1
#define INJ_ACTRTST_START                 2
#define INJ_ACTRTST_ON                    3
#define INJ_ACTRTST_STOP                  4
#define INJ_ACTRTST_OFF                   5
#define INJ_ACTRTST_END                   6
#define INJ_ACTRTST_LDB_RECONF            7
#define INJ_FIRSTFULL                     8
/*extern uint8 Inj_stActrTst;*/

/* enum st133 */
#define INJ_DELAY_FIRSFTFULL              1
#define INJ_APPLIED_FIRSTFULL             2
/*extern uint8 Inj_stFirstFull;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  INJACTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Inj_stActrTst;
extern uint8 Inj_stFirstFull;
extern boolean ActrTest_bAcvInjFirstFillFu;
extern boolean Inj_bInjTstCmpl;
extern boolean INJACTEST_bChgtActuator;
extern boolean INJACTEST_bMemFirstFillFuPrev;
extern boolean INJACTEST_bMemFirstFillFuPrev2;
extern boolean INJACTEST_bTestEna;
extern uint8 Inj_stActrTst_prev;
extern uint8 INJACTEST_u8CodeActrTestPrev;
extern uint16 ActrTstInj_CumulTime;
extern uint16 ActrTstInj_IntTime;
extern uint16 ActrTstInj_TempoIdle;
extern uint16 ActrTstInj_TimeToInject;
extern uint16 Inj_tiCntFirstFull;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJACTEST_vidEntryMode(void);
void INJACTEST_vidInitOutput(void);
void INJACTEST_vidStateEnd(void);
void INJACTEST_vidStateFirstFull(void);
void INJACTEST_vidStateIdle(void);
void INJACTEST_vidStateLdbReconf(void);
void INJACTEST_vidStateOff(void);
void INJACTEST_vidStateOn(void);
void INJACTEST_vidStateStart(void);
void INJACTEST_vidStateStop(void);
void INJACTEST_vidTestEnd(void);
void INJACTEST_vidTestFrLstRun(void);
void INJACTEST_vidTestMode(void);
void INJACTEST_vidTimeToInj(void);
void INJACTEST_vidTimeToInjCln(void);


#endif /* INJACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
