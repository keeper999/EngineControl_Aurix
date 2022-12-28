/***************************************************************************
;**
;** FILE NAME      : THRSPPOSN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRSPPOSN.H"
#include "THRSPPOSN_L.H"
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
const boolean  Dtc_throttle_test_bed_mode_manu = 0;
const boolean  Manu_inh_pm = 0;
const boolean  Thr_bAcvCloThrSTTStop_C = 0;
const boolean  Thr_bAcvThrPosEngStop_C = 0;
const boolean  Thr_bAcvTypSpEngStop_Sel1_C = 0;
const boolean  Thr_bBypSpEngStopSTT_C = 0;
const uint8  Dtc_throttle_position_max = 0;
const uint8  Dtc_throttle_position_max_map[DTC_THROTTLE_POSITION_MAX_MAP_COLS] = {0};
const uint8  Dtc_throttle_position_max_offset = 0;
const uint8  Dtc_throttle_position_min = 0;
const uint8  Dtc_throttle_position_rate_limit = 0;
const uint8  Regime_moteur_2_bkpt_map[REGIME_MOTEUR_2_BKPT_MAP_COLS] = {0};
const uint8  Thr_nEngLoThdEngStop_C = 0;
const uint8  Thr_rThrMinPosEngStop_C = 0;
const uint8  Thr_tAirHiThdEngStop_C = 0;
const uint8  Thr_tAirLoThdEngStop_C = 0;
const uint8  Thr_vThrPosSpRateEngStop_C = 0;
const uint8  THRSPPOSN_u8Inhib = 0;
const uint8  Tpac_limp_home_variation = 0;
const sint16  Thr_tEauHiThdEngStop_C = 0;
const sint16  Thr_tEauLoThdEngStop_C = 0;
const uint16  Dtc_diff_switch_mcut_dec = 0;
const uint16  Dtc_switch_mcut_max_rate = 0;
const uint16  Dtc_throt_pos_for_test_bed_manu = 0;
const uint16  Thr_ctAuthCloThr_C = 0;
const uint16  Thr_rSpPosCloThdEngStop_C = 0;
const uint16  Thr_rSpPosCloThdSlopeEngStop_C = 0;
const uint16  Thr_rThrPosEngStop_C = 0;
const uint16  Thr_tiCloThrDlyEngStop_C = 0;
const uint16  Thr_uBattHiThdEngStop_C = 0;
const uint16  Thr_uBattLoThdEngStop_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Dtc_throttle_test_bed_mode_act;
boolean Thr_bEngStopAuthCloSlopeThr;
boolean Thr_bEngStopAuthCloThr;
boolean Throt_pos_ref_freeze_enab_prev;
boolean THRSPPOSN_bTimeOut;
boolean THRSPPOSN_bTriggerPrev;
boolean THRSPPOSN_BypCtAuthCloThr_Prev;
boolean THRSPPOSN_InitTimerPrev;
uint8 Dtc_throttle_position_max_limit;
uint8 Dtc_throttle_position_min_limit;
uint16 Dtc_diff_pos_ref_overlap;
uint16 Dtc_throt_position_ref_tmp;
uint16 Dtc_throttle_position_raw_ref;
uint16 Dtc_throttle_position_ref_raw;
uint16 Dtc_throttle_position_ref_temp;
uint16 Dtc_throttle_position_ref_w_mcut;
uint16 THRSPPOSN_u16CntTimer;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

