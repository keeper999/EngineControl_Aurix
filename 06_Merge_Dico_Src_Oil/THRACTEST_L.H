/***************************************************************************
;**
;** FILE NAME      : THRACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRACTEST_L_H
#define THRACTEST_L_H

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

/* enum st87 */
#define THR_ACTRTST_IDLE                  0
#define THR_ACTRTST_PHASE1                1
#define THR_ACTRTST_PHASE2                2
#define THR_ACTRTST_PHASE3                3
#define THR_ACTRTST_PHASE4                4
#define THR_ACTRTST_PHASE5                5
#define THR_ACTRTST_PHASE6                6
#define THR_ACTRTST_PHASE7                7
#define THR_ACTRTST_END                   8
/*extern uint8 Thr_stActrTst;*/

/* enum st88 */
#define THR_DYNTST_IDLE                   0
#define THR_DYNTST_RUN                    1
/*extern uint8 Thr_stDynTst;*/

/* enum st89 */
#define THR_GAPTST_IDLE                   0
#define THR_GAPTST_PHASE1                 1
#define THR_GAPTST_PHASE2                 2
#define THR_GAPTST_END                    3
/*extern uint8 Thr_stGapTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Thr_stActrTst;
extern uint8 Thr_stDynTst;
extern uint8 Thr_stGapTst;
extern boolean ActrTstThr_GapDetn;
extern boolean ActrTstThr_IntGapTstRes;
extern boolean ActrTstThr_RunDynTest;
extern boolean ActrTstThr_RunGapTest;
extern boolean ActrTstThr_StopDynTest;
extern boolean ActrTstThr_StopGapTest;
extern boolean THRACTEST_bTstInProgsPrev;
extern uint8 ActrTstThr_ChgtSp;
extern uint8 THRACTEST_u8ActrTstThrChgtSpPrev;
extern uint16 ActrDynTstThr_TstTime;
extern uint16 ActrGapTstThr_TstTime;
extern uint16 ActrTstThr_Tempo;
extern uint16 ActrTstThr_TstTime;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRACTEST_vidDiffPosnClcn(void);
void THRACTEST_vidDynTst(void);
void THRACTEST_vidDynTstEna(void);
void THRACTEST_vidDynTstResClcn(void);
void THRACTEST_vidDynTstResInit(void);
void THRACTEST_vidDynTstSpeed(void);
void THRACTEST_vidGapTest(void);
void THRACTEST_vidGapTestMain(void);
void THRACTEST_vidGapTstEna(void);
void THRACTEST_vidGapTstResClcn(void);
void THRACTEST_vidGapTstResInit(void);
void THRACTEST_vidInitDynTst(void);
void THRACTEST_vidInitGapTst(void);
void THRACTEST_vidInitOutput(void);
void THRACTEST_vidThrTstSpChart(void);
void THRACTEST_vidUpdateGapTst(void);


#endif /* THRACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
