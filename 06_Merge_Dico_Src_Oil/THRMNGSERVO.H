/***************************************************************************
;**
;** FILE NAME      : THRMNGSERVO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRMNGSERVO_H
#define THRMNGSERVO_H

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

/* enum st01 */
#define TPAC_CONTROL                      1
#define TPAC_CLOSING_RAMP                 2
#define TPAC_HIGH_THRUST_SEARCH           4
#define TPAC_MCW_INHIBIT_TEST             8
#define TPAC_LIMP_HOME                    16
#define TPAC_EXIT_LOW_THRUST              32
#define TPAC_WAIT_FOR_ADC                 64
#define TPAC_RESTOR_MOBILITY              128
/*extern uint8 Tpac_throttle_control_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Thr_bAcvPtlWku_C;
extern const boolean  Thr_bAcvTestAbortSfty_C;
extern const boolean  Thr_bAcvThrLrnKeyOn_drf_C;
extern const boolean  Thr_bInhCdnAcvCll_C;
extern const boolean  Thr_bInhFClnHiStop_C;
extern const boolean  Thr_bInhStopLrnKeyOff;
extern const boolean  Thr_bInhThrCln_C;
extern const boolean  Tpac_open_thrust_search_inh;
extern const boolean  Tpac_throttle_lh_pos;
extern const boolean  Tpac_thrusts_search_diag_inh;
extern const uint8  Cal_pres_chk;
extern const uint8  Thr_dlyKeyOn_C;
extern const uint8  Thr_tAirMaxAuthStopLrn_C;
extern const uint8  Thr_tAirMinAuthStopLrn_C;
extern const uint8  Tpac_FCln_powerlatch_cnt_Thd;
extern const uint8  Tpac_FCln_water_temp_mini;
extern const uint8  Tpac_thrusts_air_temp_maxi;
extern const uint8  Tpac_thrusts_air_temp_mini;
extern const uint8  Tpac_thrusts_powerlatch_cnt_max;
extern const uint8  Tpac_thrusts_water_temp_maxi;
extern const uint8  Tpac_thrusts_water_temp_mini;
extern const uint16  Thr_nMaxAuthStopLrn_C;
extern const uint16  Thr_tiStrtMinStopsCln_C;
extern const uint16  Thr_uBattMaxStopsCln_C;
extern const uint16  Thr_uBattMaxStopsLrn_C;
extern const uint16  Thr_uBattMinStopsCln_C;
extern const uint16  Thr_uBattMinStopsLrn_C;
extern const uint16  Thr_uMinBattAuthStopLrn_C;
extern const uint16  Tpac_closing_ramp_delay;
extern const uint16  Tpac_exit_low_thrust_delay;
extern const uint16  Tpac_store_limp_home_delay;
extern const uint16  Tpac_thrust_search_cleoff_delay;
extern const uint16  Tpac_thrust_search_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Tpac_throttle_control_state;
extern boolean Thr_bFClnInProgs;
extern boolean Thr_bInhInjMngServo;
extern boolean Thr_bInhMngThrServo;
extern boolean Thr_bStopsLrnInProgs;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_MngServo(void);
void Thr_EveRstThr_MngServo(void);
void Thr_SdlMid_MngServo(void);


#endif /* THRMNGSERVO_H */

/*-------------------------------- end of file -------------------------------*/
