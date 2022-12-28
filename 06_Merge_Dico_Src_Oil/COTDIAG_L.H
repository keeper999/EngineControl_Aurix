/***************************************************************************
;**
;** FILE NAME      : COTDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COTDIAG_L_H
#define COTDIAG_L_H

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

extern const uint8  COTDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoT_bDgoTrck_tCoMes;
extern boolean CoT_bDgoWup_tCoMes;
extern boolean CoT_bMonRunTrck_tCoMes;
extern boolean CoT_bMonRunWup_tCoMes;
extern boolean CoT_bMonWaitWup_tCoMes;
extern boolean Flag_delay_injection;
extern boolean Warmup_test_complete;
extern uint8 CoT_tCoStallCohThd;
extern uint8 Injector_cut_off_counter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COTDIAG_vidCalcDgoIndicator(void);
void COTDIAG_vidCalcMonRunIndicator(void);
void COTDIAG_vidFunctDiagCoTemp(void);
void COTDIAG_vidFunctDiagCoTempInit(void);
void COTDIAG_vidInitOutput(void);
void COTDIAG_vidInjCutoffTimeCalc(void);
void COTDIAG_vidTrackerCoTempCalc(void);
void COTDIAG_vidWarmUpTestEnd(void);


#endif /* COTDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
