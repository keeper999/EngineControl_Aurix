/***************************************************************************
;**
;** FILE NAME      : COTDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COTDIAG_H
#define COTDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COT_TCOSTALLCOH_A_COLS                 ( 5 )
#define COT_TCOSTALLCOHMINWUP_T_COLS           ( 5 )

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

extern const uint8  CoT_tCoStallCoh_A[COT_TCOSTALLCOH_A_COLS];
extern const uint8  CoT_tCoStallCohMinWup_T[COT_TCOSTALLCOHMINWUP_T_COLS];
extern const uint8  Min_warmup_water_temp_hyst;
extern const uint8  Wat_func_diag_cut_off_delay_max;
extern const uint8  Wat_func_diag_cut_off_delay_min;
extern const uint8  Wat_func_diag_max_vehicle_speed;
extern const uint8  Wt_max_tracker_value;
extern const uint8  Wt_tracker_offset;
extern const uint16  Water_temp_warmup_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Temperature_eau_tracker_value;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CoT_EveCrTR_FctDiagCoT(void);
void CoT_EveRst_FctDiagCoT(void);
void CoT_SdlSlow_FctDiagCoT(void);
void COTDIAG_vidEntryInit(void);


#endif /* COTDIAG_H */

/*-------------------------------- end of file -------------------------------*/
