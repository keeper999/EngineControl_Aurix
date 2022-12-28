/***************************************************************************
;**
;** FILE NAME      : TIENGSTOP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TIENGSTOP_L_H
#define TIENGSTOP_L_H

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

extern const uint8  TIENGSTOP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Date_emf_dem_calcule;
extern boolean Date_emf_init_time_since_stall;
extern boolean EngSt_bDetEngStallSTT;
extern boolean EngSt_bDiagCohCtTi;
extern boolean EngSt_bTramTairCANVal;
extern boolean EOM_bDgoCoh_tiEngStop;
extern boolean EOM_bDgoORng_tiEngStop;
extern boolean EOM_bMonRunCoh_tiEngStop;
extern boolean EOM_bMonRunORng_tiEngStop;
extern boolean TIENGSTOP_bWkuMainPrev;
extern uint32 Date_emf_arret_s;
extern uint32 Date_emf_reveil_s;
extern uint32 EngSt_ctSec_buff_0;
extern uint32 EngSt_ctSec_buff_1;
extern uint32 EngSt_ctSec_buff_2;
extern uint8 Date_emf_arret_a;
extern uint8 Date_emf_reveil_a;
extern uint8 EngSt_ctYr_buff_0;
extern uint8 EngSt_ctYr_buff_1;
extern uint8 EngSt_ctYr_buff_2;
extern uint8 TIENGSTOP_u8CoPTStEngPrev;
extern uint8 TIENGSTOP_u8CtTiIndex;
extern sint16 EngSt_tAirMesSel;
extern sint16 TIENGSTOP_s16TCoMesDelta;
extern uint16 Date_emf_arret_j;
extern uint16 Date_emf_reveil_j;
extern uint16 EngSt_ctDay_buff_0;
extern uint16 EngSt_ctDay_buff_1;
extern uint16 EngSt_ctDay_buff_2;
extern uint16 EngSt_tiEngStopDft;
extern uint16 TIENGSTOP_u16Ext_nEngPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TIENGSTOP_vidAlarmClockCalc(void);
void TIENGSTOP_vidChangeOfMind(void);
void TIENGSTOP_vidDegradedPeriodEstim(void);
void TIENGSTOP_vidEmfActiveDate(void);
void TIENGSTOP_vidEmfDate(void);
void TIENGSTOP_vidEmfDateCalc(void);
void TIENGSTOP_vidEmfDateCoh(void);
void TIENGSTOP_vidEmfDateSinceStall(void);
void TIENGSTOP_vidEmfInvalidCrankDate(void);
void TIENGSTOP_vidEmfSaveLastAlarmClk(void);
void TIENGSTOP_vidEmfSaveLastStopDate(void);
void TIENGSTOP_vidEmfValidCrankDate(void);
void TIENGSTOP_vidFrameTairCAN(void);
void TIENGSTOP_vidInitialisation(void);
void TIENGSTOP_vidInitOutput(void);
void TIENGSTOP_vidInitTimeSinceStall(void);
void TIENGSTOP_vidRazTimeSinceStall(void);
void TIENGSTOP_vidTimeBuffer(void);


#endif /* TIENGSTOP_L_H */

/*-------------------------------- end of file -------------------------------*/
