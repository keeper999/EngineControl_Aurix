/***************************************************************************
;**
;** FILE NAME      : COTDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "COTDIAG.H"
#include "COTDIAG_L.H"
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
const uint8  CoT_tCoStallCoh_A[COT_TCOSTALLCOH_A_COLS] = {0};
const uint8  CoT_tCoStallCohMinWup_T[COT_TCOSTALLCOHMINWUP_T_COLS] = {0};
const uint8  COTDIAG_u8Inhib = 0;
const uint8  Min_warmup_water_temp_hyst = 0;
const uint8  Wat_func_diag_cut_off_delay_max = 0;
const uint8  Wat_func_diag_cut_off_delay_min = 0;
const uint8  Wat_func_diag_max_vehicle_speed = 0;
const uint8  Wt_max_tracker_value = 0;
const uint8  Wt_tracker_offset = 0;
const uint16  Water_temp_warmup_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoT_bDgoTrck_tCoMes;
boolean CoT_bDgoWup_tCoMes;
boolean CoT_bMonRunTrck_tCoMes;
boolean CoT_bMonRunWup_tCoMes;
boolean CoT_bMonWaitWup_tCoMes;
boolean Flag_delay_injection;
boolean Warmup_test_complete;
uint8 CoT_tCoStallCohThd;
uint8 Injector_cut_off_counter;
uint8 Temperature_eau_tracker_value;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

