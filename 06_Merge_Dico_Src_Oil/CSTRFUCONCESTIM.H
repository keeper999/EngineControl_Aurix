/***************************************************************************
;**
;** FILE NAME      : CSTRFUCONCESTIM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRFUCONCESTIM_H
#define CSTRFUCONCESTIM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CPC_CONC_100_PERC                 65535
#define CPC_CONC_CLOSED_LOOP_STEP_MAP_COLS     ( 5 )
#define CPC_CONC_ERR_100_PERC             65535
#define CPC_CONC_ERR_5_PERC               3276.8
#define CPC_CONC_OPEN_LOOP_STEP_MAP_COLS       ( 5 )
#define FUCONCESTIM_CONCFUVAPTHD_M_COLS        ( 8 )
#define FUCONCESTIM_RLAMTHD_M_COLS             ( 8 )
#define FUCONCESTIM_TAIRFUCONCTHD_A_COLS       ( 8 )
#define FUCONCESTIM_TAIRRLAMTHD_A_COLS         ( 8 )

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

extern const boolean  Cal_reset_fuel_vapour_conc;
extern const boolean  Cal_reset_fuel_vapour_conc_err;
extern const boolean  CanPurg_bAcvBypconcFuStmErr_C;
extern const boolean  Cstr_bAcvBoostPresCond_C;
extern const uint8  Cpc_dead_zone_thresh;
extern const uint8  Cpc_fuel_vapour_conc_err_init;
extern const uint8  Cpc_fuel_vapour_conc_init;
extern const uint8  Cpc_init_after_stall_delay;
extern const uint8  Cstr_facAfs_C;
extern const uint8  FuConcEstim_tAirFuConcThd_A[FUCONCESTIM_TAIRFUCONCTHD_A_COLS];
extern const uint8  FuConcEstim_tAirRlamThd_A[FUCONCESTIM_TAIRRLAMTHD_A_COLS];
extern const uint16  CanPurg_concFuStmErr_BypC;
extern const uint16  Cpc_conc_closed_loop_step_map[CPC_CONC_CLOSED_LOOP_STEP_MAP_COLS];
extern const uint16  Cpc_conc_err_filter_gain;
extern const uint16  Cpc_conc_open_loop_step_map[CPC_CONC_OPEN_LOOP_STEP_MAP_COLS];
extern const uint16  Cpc_err_open_loop_step;
extern const uint16  Cpc_estim_inh_pres_ratio_thresh;
extern const uint16  Cpc_purge_ratio_estim_min;
extern const uint16  Cstr_rAirPresBoostZoneThd_C;
extern const uint16  Cstr_rMixtSpMaxThd_C;
extern const uint16  Cstr_rMixtSpMinThd_C;
extern const uint16  FuConcEstim_concFuVapThd_M[FUCONCESTIM_CONCFUVAPTHD_M_COLS];
extern const uint16  FuConcEstim_rLamThd_M[FUCONCESTIM_RLAMTHD_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 CanPurg_ldGasFuCan;
extern uint16 CanPurg_mFuEstim;
extern uint16 Cpc_fuel_mass_flow_rate;
extern uint16 Cpc_fuel_vapour_conc_err;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cstr_EveCrTR_FuConcEstim(void);
void Cstr_EveRst_FuConcEstim(void);
void Cstr_SdlFast_FuConcEstim(void);
void Cstr_SdlSlow_FuConcEstim(void);
void CSTRFUCONCESTIM_NVMSRV_vidInit(void);


#endif /* CSTRFUCONCESTIM_H */

/*-------------------------------- end of file -------------------------------*/
