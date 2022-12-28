/***************************************************************************
;**
;** FILE NAME      : HEATSENO2UPPERDDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2UPPERDDIAG_H
#define HEATSENO2UPPERDDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define LSMON_TIPERUSNEW_M_LNS                ( 9 )
#define LSMON_TIPERUSNEW_M_COLS                ( 9 )
#define MAX_OXY_APV_PERIOD_GAS_MAP_LNS        ( 9 )
#define MAX_OXY_APV_PERIOD_GAS_MAP_COLS        ( 9 )
#define MAX_OXY_APV_PERIOD_MAP_LNS            ( 9 )
#define MAX_OXY_APV_PERIOD_MAP_COLS            ( 9 )
#define MAX_OXY_SENS_PERIOD_EMIS_GAS_MAP_LNS  ( 9 )
#define MAX_OXY_SENS_PERIOD_EMIS_GAS_MAP_COLS  ( 9 )
#define MAX_OXY_SENS_PERIOD_EMIS_MAP_LNS      ( 9 )
#define MAX_OXY_SENS_PERIOD_EMIS_MAP_COLS      ( 9 )
#define MAX_OXY_SENS_PERIOD_GAS_MAP_LNS       ( 9 )
#define MAX_OXY_SENS_PERIOD_GAS_MAP_COLS       ( 9 )
#define MAX_OXY_SENS_PERIOD_MAP_LNS           ( 9 )
#define MAX_OXY_SENS_PERIOD_MAP_COLS           ( 9 )
#define MAX_OXY_SENS_TEMPO_L              250
#define MAX_OXY_SENS_TEMPO_R              250

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st63 */
#define SYNCH_TO_UPS_OXY_SENS_START       2
#define UPS_OXY_SENS_TRANSIT_TO_LEAN      4
#define UPS_OXY_SENS_RICH                 8
#define UPS_OXY_SENS_TRANSIT_TO_RICH      16
#define UPS_OXY_SENS_LEAN                 32
#define SYNCH_TO_UPS_OXY_SENS_LEAN        64
#define SYNCH_TO_UPS_OXY_SENS_RICH        128
/*extern uint8 State_ups_oxy_sens;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Manu_inh_correction_perdiag;
extern const boolean  SenO2Us_bAcvSeqOxyApvPerd_C;
extern const boolean  SenO2Us_bAcvSeqOxySensPerd_C;
extern const boolean  SenO2Us_bInhMonWait_PerDiag_C;
extern const boolean  SenO2Us_bInhPerDiagPresScav_C;
extern const boolean  SenO2Us_bInhPerLean_C;
extern const boolean  SenO2Us_bInhPerRich_C;
extern const uint8  Os_period_tests_done_c;
extern const uint8  Os_period_tests_done_gas_c;
extern const uint8  Oxy_sens_diag_sample_size_c;
extern const uint8  Oxy_sens_diag_sample_size_gas_c;
extern const uint8  Oxy_sens_min_engine_speed;
extern const uint8  Oxy_sens_min_engine_speed_gas;
extern const uint8  Oxy_sens_min_water_temp;
extern const uint8  Oxy_sens_min_water_temp_gas;
extern const uint16  Lfbk_on_enlean_clamp_delay_c;
extern const uint16  Lfbk_on_enrich_clamp_delay_c;
extern const uint16  LsMon_tiPerUsNew_M[LSMON_TIPERUSNEW_M_LNS][LSMON_TIPERUSNEW_M_COLS];
extern const uint16  Max_oxy_apv_period_gas_map[MAX_OXY_APV_PERIOD_GAS_MAP_LNS][MAX_OXY_APV_PERIOD_GAS_MAP_COLS];
extern const uint16  Max_oxy_apv_period_map[MAX_OXY_APV_PERIOD_MAP_LNS][MAX_OXY_APV_PERIOD_MAP_COLS];
extern const uint16  Max_oxy_sens_period_emis_gas_map[MAX_OXY_SENS_PERIOD_EMIS_GAS_MAP_LNS][MAX_OXY_SENS_PERIOD_EMIS_GAS_MAP_COLS];
extern const uint16  Max_oxy_sens_period_emis_map[MAX_OXY_SENS_PERIOD_EMIS_MAP_LNS][MAX_OXY_SENS_PERIOD_EMIS_MAP_COLS];
extern const uint16  Max_oxy_sens_period_gas_map[MAX_OXY_SENS_PERIOD_GAS_MAP_LNS][MAX_OXY_SENS_PERIOD_GAS_MAP_COLS];
extern const uint16  Max_oxy_sens_period_map[MAX_OXY_SENS_PERIOD_MAP_LNS][MAX_OXY_SENS_PERIOD_MAP_COLS];
extern const uint16  Min_oxy_sens_amfr_c;
extern const uint16  Min_oxy_sens_amfr_gas_c;
extern const uint16  Oxy_sens_lower_voltage_thd_gas_c;
extern const uint16  Oxy_sens_lower_voltage_thresh_c;
extern const uint16  Oxy_sens_min_engine_load;
extern const uint16  Oxy_sens_min_engine_load_gas;
extern const uint16  Oxy_sens_upper_voltage_thd_gas_c;
extern const uint16  Oxy_sens_upper_voltage_thresh_c;
extern const uint16  SenO2Us_PerDiag_tiInhDiag_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 State_ups_oxy_sens;
extern boolean E_monitor_up_stream_oxy_sensor;
extern boolean Oxy_sens_diag_test_completed;
extern boolean Oxy_sens_diag_test_finished;
extern boolean SenO2Us_bAcvSeqMemOxyApvPerd;
extern boolean SenO2Us_bAcvSeqMemOxySensPerd;
extern boolean SenO2Us_bAcvSeqOxyApvPerd;
extern boolean SenO2Us_bAcvSeqOxySensPerd;
extern uint16 LsMon_noRatEfcLsUsPer;
extern uint16 SenO2Us_PerDiag_FacMax_Obd6Mod;
extern uint16 SenO2Us_PerDiag_FacMes_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SenO2Us_EveRst_PerDiag(void);
void SenO2Us_SdlFast_PerDiag(void);


#endif /* HEATSENO2UPPERDDIAG_H */

/*-------------------------------- end of file -------------------------------*/
