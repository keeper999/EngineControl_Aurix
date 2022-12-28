/***************************************************************************
;**
;** FILE NAME      : CSTRMGR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CSTRMGR.H"
#include "CSTRMGR_L.H"
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
const boolean  Cpc_bAcvClsCanPurgSTTLbdaCdn_C = 0;
const boolean  Purge_test_banc = 0;
const uint8  Cpc_decreasing_ratio = 0;
const uint8  Cpc_diff_purge_ratio_thresh = 0;
const uint8  Cpc_full_load_purge_rco = 0;
const uint8  Cpc_min_purge_rco = 0;
const uint8  Cpc_purge_dc_map[CPC_PURGE_DC_MAP_COLS] = {0};
const uint8  Cpc_purge_inh_high_lambda_thresh = 0;
const uint8  Cpc_purge_inh_low_lambda_thresh = 0;
const uint8  Cpc_test_bed_purge_rco = 0;
const uint8  CSTRMGR_u8Inhib = 0;
const sint16  Cpc_water_temp_thresh = 0;
const uint16  Cpc_effective_area_map[CPC_EFFECTIVE_AREA_MAP_COLS] = {0};
const uint16  Cpc_purge_ratio_step_min = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Cpc_purge_control_state;
boolean CSTRMGR_cdn_rco_ctld;
boolean CSTRMGR_open_loop_min_purge_req;
boolean Demande_purge_dormant;
boolean Demande_purge_dormant_banc;
boolean Demande_purge_dormant_nom;
boolean Demande_purge_dormant_raw;
boolean OxC_bMonIntrPurgeCdn;
uint8 Rco_applique_purge;
uint8 Rco_demande_purge;
uint8 Rco_demande_purge_banc;
uint8 Rco_demande_purge_ctld;
uint8 Rco_demande_purge_nom;
uint16 Cpc_control_purge_ratio;
uint16 Cpc_purge_ratio_step;
uint16 CSTRMGR_u16EffectiveArea;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

