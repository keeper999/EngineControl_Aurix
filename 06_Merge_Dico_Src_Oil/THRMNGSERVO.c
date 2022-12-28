/***************************************************************************
;**
;** FILE NAME      : THRMNGSERVO.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRMNGSERVO.H"
#include "THRMNGSERVO_L.H"
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
const boolean  Thr_bAcvPtlWku_C = 0;
const boolean  Thr_bAcvTestAbortSfty_C = 0;
const boolean  Thr_bAcvThrLrnKeyOn_drf_C = 0;
const boolean  Thr_bInhCdnAcvCll_C = 0;
const boolean  Thr_bInhFClnHiStop_C = 0;
const boolean  Thr_bInhStopLrnKeyOff = 0;
const boolean  Thr_bInhThrCln_C = 0;
const boolean  Tpac_open_thrust_search_inh = 0;
const boolean  Tpac_throttle_lh_pos = 0;
const boolean  Tpac_thrusts_search_diag_inh = 0;
const uint8  Cal_pres_chk = 0;
const uint8  Thr_dlyKeyOn_C = 0;
const uint8  Thr_tAirMaxAuthStopLrn_C = 0;
const uint8  Thr_tAirMinAuthStopLrn_C = 0;
const uint8  THRMNGSERVO_u8Inhib = 0;
const uint8  Tpac_FCln_powerlatch_cnt_Thd = 0;
const uint8  Tpac_FCln_water_temp_mini = 0;
const uint8  Tpac_thrusts_air_temp_maxi = 0;
const uint8  Tpac_thrusts_air_temp_mini = 0;
const uint8  Tpac_thrusts_powerlatch_cnt_max = 0;
const uint8  Tpac_thrusts_water_temp_maxi = 0;
const uint8  Tpac_thrusts_water_temp_mini = 0;
const uint16  Thr_nMaxAuthStopLrn_C = 0;
const uint16  Thr_tiStrtMinStopsCln_C = 0;
const uint16  Thr_uBattMaxStopsCln_C = 0;
const uint16  Thr_uBattMaxStopsLrn_C = 0;
const uint16  Thr_uBattMinStopsCln_C = 0;
const uint16  Thr_uBattMinStopsLrn_C = 0;
const uint16  Thr_uMinBattAuthStopLrn_C = 0;
const uint16  Tpac_closing_ramp_delay = 0;
const uint16  Tpac_exit_low_thrust_delay = 0;
const uint16  Tpac_store_limp_home_delay = 0;
const uint16  Tpac_thrust_search_cleoff_delay = 0;
const uint16  Tpac_thrust_search_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 THRMNGSERVO_stCalcTempoCleoff;
uint8 Tpac_throttle_control_state;
boolean Thr_bFClnInProgs;
boolean Thr_bInhInjMngServo;
boolean Thr_bInhMngThrServo;
boolean Thr_bInhThrFallTran;
boolean Thr_bPtlWkuOn;
boolean Thr_bStopsLrnInProgs;
boolean THRMNGSERVO_bCalcCleTempo_on;
boolean THRMNGSERVO_bExtbDrvCyGlblPrev;
boolean THRMNGSERVO_bSrv_bInhThrPrev;
boolean THRMNGSERVO_bTpacLimpHomeFlag;
boolean THRMNGSERVO_bTransitionDone;
boolean Trans_clef_off_on;
uint8 Thr_dlyKeyOn;
uint16 Tpac_store_limp_home_tempo;
uint16 Tpac_thrust_search_cleoff_tempo;
uint16 Tpac_thrust_search_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

