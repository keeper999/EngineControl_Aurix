/***************************************************************************
;**
;** FILE NAME      : THRSPPOSN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSPPOSN_H
#define THRSPPOSN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DTC_THROTTLE_POSITION_MAX_MAP_COLS     ( 9 )
#define REGIME_MOTEUR_2_BKPT_MAP_COLS          ( 9 )

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

extern const boolean  Dtc_throttle_test_bed_mode_manu;
extern const boolean  Manu_inh_pm;
extern const boolean  Thr_bAcvCloThrSTTStop_C;
extern const boolean  Thr_bAcvThrPosEngStop_C;
extern const boolean  Thr_bAcvTypSpEngStop_Sel1_C;
extern const boolean  Thr_bBypSpEngStopSTT_C;
extern const uint8  Dtc_throttle_position_max;
extern const uint8  Dtc_throttle_position_max_map[DTC_THROTTLE_POSITION_MAX_MAP_COLS];
extern const uint8  Dtc_throttle_position_max_offset;
extern const uint8  Dtc_throttle_position_min;
extern const uint8  Dtc_throttle_position_rate_limit;
extern const uint8  Regime_moteur_2_bkpt_map[REGIME_MOTEUR_2_BKPT_MAP_COLS];
extern const uint8  Thr_nEngLoThdEngStop_C;
extern const uint8  Thr_rThrMinPosEngStop_C;
extern const uint8  Thr_tAirHiThdEngStop_C;
extern const uint8  Thr_tAirLoThdEngStop_C;
extern const uint8  Thr_vThrPosSpRateEngStop_C;
extern const uint8  Tpac_limp_home_variation;
extern const sint16  Thr_tEauHiThdEngStop_C;
extern const sint16  Thr_tEauLoThdEngStop_C;
extern const uint16  Dtc_diff_switch_mcut_dec;
extern const uint16  Dtc_switch_mcut_max_rate;
extern const uint16  Dtc_throt_pos_for_test_bed_manu;
extern const uint16  Thr_ctAuthCloThr_C;
extern const uint16  Thr_rSpPosCloThdEngStop_C;
extern const uint16  Thr_rSpPosCloThdSlopeEngStop_C;
extern const uint16  Thr_rThrPosEngStop_C;
extern const uint16  Thr_tiCloThrDlyEngStop_C;
extern const uint16  Thr_uBattHiThdEngStop_C;
extern const uint16  Thr_uBattLoThdEngStop_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Dtc_throttle_test_bed_mode_act;
extern uint8 Dtc_throttle_position_max_limit;
extern uint8 Dtc_throttle_position_min_limit;
extern uint16 Dtc_throttle_position_ref_raw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveOplCllEna_ThrSpPosn(void);
void Thr_EveRst_SpPosn(void);
void Thr_SdlMid_SpPosn(void);


#endif /* THRSPPOSN_H */

/*-------------------------------- end of file -------------------------------*/
