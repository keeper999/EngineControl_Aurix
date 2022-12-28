/***************************************************************************
;**
;** FILE NAME      : CSTRDYNLIM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CSTRDYNLIM.H"
#include "CSTRDYNLIM_L.H"
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
const boolean  Cpc_bAcvClsCanPurgSTTRamp_C = 0;
const uint8  Cpc_fuel_constraint_max_map[CPC_FUEL_CONSTRAINT_MAX_MAP_LNS][CPC_FUEL_CONSTRAINT_MAX_MAP_COLS] = {0};
const uint8  Cpc_max_amfr_thresh = 0;
const uint8  Cpc_max_purge_ratio_max_step = 0;
const uint8  Cpc_max_purge_ratio_max_step_stt = 0;
const uint8  Cpc_min_fuel_pulse_width = 0;
const uint8  CSTRDYNLIM_u8Inhib = 0;
const uint16  Cpc_cat_diag_max_purge_ratio = 0;
const uint16  Cpc_purge_rate_gain_map[CPC_PURGE_RATE_GAIN_MAP_COLS] = {0};
const uint16  Cpc_purge_rate_gain_stt_map[CPC_PURGE_RATE_GAIN_STT_MAP_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CSTRDYNLIM_bGsmPurgeClosingEntry;
uint8 Cpc_fuel_constraint_max;
uint8 Cpc_purge_fuel_ratio;
uint8 CSTRDYNLIM_u8CpcPurgCtrlStatPrev;
uint16 Cpc_air_constraint_max_mfr;
uint16 Cpc_constraints_max_purge_ratio;
uint16 Cpc_current_purge_ratio;
uint16 Cpc_fpw_constraint_max_mfr;
uint16 Cpc_fuel_constraint_max_mfr;
uint16 Cpc_lambda_constraint_max_mfr;
uint16 Cpc_max_air_mfr;
uint16 Cpc_max_purge_ratio;
uint16 Cpc_min_inj_time_fuel_flow_rate;
uint16 Cpc_purge_rate_gain;
uint16 Cpc_purge_rate_gain_stt;
uint16 Required_fuel_flow_rate_si;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

