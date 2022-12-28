/***************************************************************************
;**
;** FILE NAME      : THRSPPOSN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSPPOSN_L_H
#define THRSPPOSN_L_H

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

extern const uint8  THRSPPOSN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bEngStopAuthCloSlopeThr;
extern boolean Thr_bEngStopAuthCloThr;
extern boolean Throt_pos_ref_freeze_enab_prev;
extern boolean THRSPPOSN_bTimeOut;
extern boolean THRSPPOSN_bTriggerPrev;
extern boolean THRSPPOSN_BypCtAuthCloThr_Prev;
extern boolean THRSPPOSN_InitTimerPrev;
extern uint16 Dtc_diff_pos_ref_overlap;
extern uint16 Dtc_throt_position_ref_tmp;
extern uint16 Dtc_throttle_position_raw_ref;
extern uint16 Dtc_throttle_position_ref_temp;
extern uint16 Dtc_throttle_position_ref_w_mcut;
extern uint16 THRSPPOSN_u16CntTimer;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRSPPOSN_vidComputeDtcThrPos(void);
void THRSPPOSN_vidComputeDtcThrPosRef(void);
void THRSPPOSN_vidCounter(void);
void THRSPPOSN_vidDeadBandLH(void);
void THRSPPOSN_vidDiffEstimation(void);
void THRSPPOSN_vidInitOutput(void);
void THRSPPOSN_vidInitThrottleRef(void);
void THRSPPOSN_vidStopEngineCase(void);
void THRSPPOSN_vidSwitchingTransients(void);
void THRSPPOSN_vidSwitchMgtMcut(void);


#endif /* THRSPPOSN_L_H */

/*-------------------------------- end of file -------------------------------*/
