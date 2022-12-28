/***************************************************************************
;**
;** FILE NAME      : CSTRFUCONCESTIM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CSTRFUCONCESTIM.H"
#include "CSTRFUCONCESTIM_L.H"
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
const boolean  Cal_reset_fuel_vapour_conc = 0;
const boolean  Cal_reset_fuel_vapour_conc_err = 0;
const boolean  CanPurg_bAcvBypconcFuStmErr_C = 0;
const boolean  Cstr_bAcvBoostPresCond_C = 0;
const uint8  Cpc_dead_zone_thresh = 0;
const uint8  Cpc_fuel_vapour_conc_err_init = 0;
const uint8  Cpc_fuel_vapour_conc_init = 0;
const uint8  Cpc_init_after_stall_delay = 0;
const uint8  Cstr_facAfs_C = 0;
const uint8  CSTRFUCONCESTIM_u8Inhib = 0;
const uint8  FuConcEstim_tAirFuConcThd_A[FUCONCESTIM_TAIRFUCONCTHD_A_COLS] = {0};
const uint8  FuConcEstim_tAirRlamThd_A[FUCONCESTIM_TAIRRLAMTHD_A_COLS] = {0};
const uint16  CanPurg_concFuStmErr_BypC = 0;
const uint16  Cpc_conc_closed_loop_step_map[CPC_CONC_CLOSED_LOOP_STEP_MAP_COLS] = {0};
const uint16  Cpc_conc_err_filter_gain = 0;
const uint16  Cpc_conc_open_loop_step_map[CPC_CONC_OPEN_LOOP_STEP_MAP_COLS] = {0};
const uint16  Cpc_err_open_loop_step = 0;
const uint16  Cpc_estim_inh_pres_ratio_thresh = 0;
const uint16  Cpc_purge_ratio_estim_min = 0;
const uint16  Cstr_rAirPresBoostZoneThd_C = 0;
const uint16  Cstr_rMixtSpMaxThd_C = 0;
const uint16  Cstr_rMixtSpMinThd_C = 0;
const uint16  FuConcEstim_concFuVapThd_M[FUCONCESTIM_CONCFUVAPTHD_M_COLS] = {0};
const uint16  FuConcEstim_rLamThd_M[FUCONCESTIM_RLAMTHD_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Cpc_fuel_vapour_conc_err_near_0;
boolean Cstr_bBoostPresZone;
boolean Cstr_bEnaCllConcEstim;
boolean Cstr_bEnaOplConcEstim;
boolean Cstr_bOplPurgeCdn;
boolean CSTRFUCONCESTIM_CalreseterPrev;
boolean CSTRFUCONCESTIM_CalresetPrev;
uint32 CSTRFUCONCESTIM_u32FuelFilterMem;
uint8 Cpc_init_after_stall_count;
sint16 FuConcEstim_rLamThd;
uint16 CanPurg_ldGasFuCan;
uint16 CanPurg_mFuEstim;
uint16 CanPurg_rAirPresPurgVlv;
uint16 Cpc_conc_closed_loop_step;
uint16 Cpc_conc_open_loop_step;
uint16 Cpc_fuel_mass_flow_rate;
uint16 Cpc_fuel_vap_conc_err_close_loop;
uint16 Cpc_fuel_vapour_conc_err;
uint16 FuConcEstim_concFuVapThd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

