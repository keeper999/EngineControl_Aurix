/***************************************************************************
;**
;** FILE NAME      : THRMNGSERVO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRMNGSERVO_L_H
#define THRMNGSERVO_L_H

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

/* enum st113 */
#define CLEF_OFF                          0
#define CLEF_ON                           1
/*extern uint8 THRMNGSERVO_stCalcTempoCleoff;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  THRMNGSERVO_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 THRMNGSERVO_stCalcTempoCleoff;
extern boolean Thr_bInhThrFallTran;
extern boolean Thr_bPtlWkuOn;
extern boolean THRMNGSERVO_bCalcCleTempo_on;
extern boolean THRMNGSERVO_bExtbDrvCyGlblPrev;
extern boolean THRMNGSERVO_bSrv_bInhThrPrev;
extern boolean THRMNGSERVO_bTpacLimpHomeFlag;
extern boolean THRMNGSERVO_bTransitionDone;
extern boolean Trans_clef_off_on;
extern uint8 Thr_dlyKeyOn;
extern uint16 Tpac_store_limp_home_tempo;
extern uint16 Tpac_thrust_search_cleoff_tempo;
extern uint16 Tpac_thrust_search_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRMNGSERVO_LearningStopsAndStop(void);
void THRMNGSERVO_vidCalInhibInjection(void);
void THRMNGSERVO_vidCalTempCleoff(void);
void THRMNGSERVO_vidDownThrustEnable(void);
void THRMNGSERVO_vidEndThrLrn(void);
void THRMNGSERVO_vidEntryNodeInitSdf(void);
void THRMNGSERVO_vidFClnReset(void);
void THRMNGSERVO_vidForceLrnRst(void);
void THRMNGSERVO_vidInitOutput(void);
void THRMNGSERVO_vidManager(void);
void THRMNGSERVO_vidManagerTransition(void);
void THRMNGSERVO_vidManagerTreatment(void);
void THRMNGSERVO_vidPowrLatchCountMng(void);
void THRMNGSERVO_vidSrvTran(void);
void THRMNGSERVO_vidThrIniAftsStopCln(void);
void THRMNGSERVO_vidThrIniAftsStopLrn(void);
void THRMNGSERVO_vidThrServoInh(void);
void THRMNGSERVO_vidTransClosingRamp(void);
void THRMNGSERVO_vidTransControl(void);
void THRMNGSERVO_vidTransExitLowThrus(void);
void THRMNGSERVO_vidTransHighThSearch(void);
void THRMNGSERVO_vidTransLimpHome(void);
void THRMNGSERVO_vidTransMcwInhibTest(void);
void THRMNGSERVO_vidTransRestorMobil(void);
void THRMNGSERVO_vidTransWaitForAdc(void);
void THRMNGSERVO_vidTreatClosingRamp(void);
void THRMNGSERVO_vidTreatExitLowThrus(void);
void THRMNGSERVO_vidTreatHighThSearch(void);
void THRMNGSERVO_vidTreatLimpHome(void);


#endif /* THRMNGSERVO_L_H */

/*-------------------------------- end of file -------------------------------*/
