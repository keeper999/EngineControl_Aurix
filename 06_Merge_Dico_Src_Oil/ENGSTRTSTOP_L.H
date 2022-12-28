/***************************************************************************
;**
;** FILE NAME      : ENGSTRTSTOP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGSTRTSTOP_L_H
#define ENGSTRTSTOP_L_H

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

extern const uint8  ENGSTRTSTOP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Dml_auto_injection_prev;
extern boolean EngSt_bMemrTrans_stEng;
extern boolean ENGSTRTSTOP_bAcvChangeOfMindPrev;
extern boolean ENGSTRTSTOP_bMainEngStopReqPrev;
extern uint8 ENGSTRTSTOP_u8CoPTStstEngPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ENGSTRTSTOP_vidCmdCranking(void);
void ENGSTRTSTOP_vidComputeCrankRetry(void);
void ENGSTRTSTOP_vidControlAutoInj(void);
void ENGSTRTSTOP_vidEnaTransitToCrank(void);
void ENGSTRTSTOP_vidEngStateDmlCalc(void);
void ENGSTRTSTOP_vidEngStopCond(void);
void ENGSTRTSTOP_vidEveStallRunning(void);
void ENGSTRTSTOP_vidFirstCrank(void);
void ENGSTRTSTOP_vidInitAutoInjStlCrk(void);
void ENGSTRTSTOP_vidInitialization(void);
void ENGSTRTSTOP_vidInitOutput(void);
void ENGSTRTSTOP_vidKeyOffOn(void);
void ENGSTRTSTOP_vidKeyOnOff(void);
void ENGSTRTSTOP_vidKeyStopCond(void);
void ENGSTRTSTOP_vidMajFirstCrank(void);
void ENGSTRTSTOP_vidMemrTransStEng(void);
void ENGSTRTSTOP_vidStallRunning(void);
void ENGSTRTSTOP_vidTransEngine(void);
void ENGSTRTSTOP_vidTransToCranking(void);


#endif /* ENGSTRTSTOP_L_H */

/*-------------------------------- end of file -------------------------------*/
