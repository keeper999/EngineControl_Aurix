/***************************************************************************
;**
;** FILE NAME      : HEATSENO2UPPERDDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2UPPERDDIAG.H"
#include "HEATSENO2UPPERDDIAG_L.H"
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
const boolean  Manu_inh_correction_perdiag = 0;
const boolean  SenO2Us_bAcvSeqOxyApvPerd_C = 0;
const boolean  SenO2Us_bAcvSeqOxySensPerd_C = 0;
const boolean  SenO2Us_bInhMonWait_PerDiag_C = 0;
const boolean  SenO2Us_bInhPerDiagPresScav_C = 0;
const boolean  SenO2Us_bInhPerLean_C = 0;
const boolean  SenO2Us_bInhPerRich_C = 0;
const uint8  HEATSENO2UPPERDDIAG_u8Inhib = 0;
const uint8  Os_period_tests_done_c = 0;
const uint8  Os_period_tests_done_gas_c = 0;
const uint8  Oxy_sens_diag_sample_size_c = 0;
const uint8  Oxy_sens_diag_sample_size_gas_c = 0;
const uint8  Oxy_sens_min_engine_speed = 0;
const uint8  Oxy_sens_min_engine_speed_gas = 0;
const uint8  Oxy_sens_min_water_temp = 0;
const uint8  Oxy_sens_min_water_temp_gas = 0;
const uint16  Lfbk_on_enlean_clamp_delay_c = 0;
const uint16  Lfbk_on_enrich_clamp_delay_c = 0;
const uint16  LsMon_tiPerUsNew_M[LSMON_TIPERUSNEW_M_LNS][LSMON_TIPERUSNEW_M_COLS] = {0};
const uint16  Max_oxy_apv_period_gas_map[MAX_OXY_APV_PERIOD_GAS_MAP_LNS][MAX_OXY_APV_PERIOD_GAS_MAP_COLS] = {0};
const uint16  Max_oxy_apv_period_map[MAX_OXY_APV_PERIOD_MAP_LNS][MAX_OXY_APV_PERIOD_MAP_COLS] = {0};
const uint16  Max_oxy_sens_period_emis_gas_map[MAX_OXY_SENS_PERIOD_EMIS_GAS_MAP_LNS][MAX_OXY_SENS_PERIOD_EMIS_GAS_MAP_COLS] = {0};
const uint16  Max_oxy_sens_period_emis_map[MAX_OXY_SENS_PERIOD_EMIS_MAP_LNS][MAX_OXY_SENS_PERIOD_EMIS_MAP_COLS] = {0};
const uint16  Max_oxy_sens_period_gas_map[MAX_OXY_SENS_PERIOD_GAS_MAP_LNS][MAX_OXY_SENS_PERIOD_GAS_MAP_COLS] = {0};
const uint16  Max_oxy_sens_period_map[MAX_OXY_SENS_PERIOD_MAP_LNS][MAX_OXY_SENS_PERIOD_MAP_COLS] = {0};
const uint16  Min_oxy_sens_amfr_c = 0;
const uint16  Min_oxy_sens_amfr_gas_c = 0;
const uint16  Oxy_sens_lower_voltage_thd_gas_c = 0;
const uint16  Oxy_sens_lower_voltage_thresh_c = 0;
const uint16  Oxy_sens_min_engine_load = 0;
const uint16  Oxy_sens_min_engine_load_gas = 0;
const uint16  Oxy_sens_upper_voltage_thd_gas_c = 0;
const uint16  Oxy_sens_upper_voltage_thresh_c = 0;
const uint16  SenO2Us_PerDiag_tiInhDiag_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 State_ups_oxy_sens;
boolean E_monitor_up_stream_oxy_sensor;
boolean Enable_period_lean;
boolean Enable_period_rich;
boolean HEATSENO2UPPERDDIAG_bEnleanPrev;
boolean HEATSENO2UPPERDDIAG_bEnrichPrev;
boolean HEATSENO2UPPERDDIAG_bOxyApvPrev;
boolean HEATSENO2UPPERDDIAG_bOxySensPrev;
boolean HEATSENO2UPPERDDIAG_bTimeout1;
boolean HEATSENO2UPPERDDIAG_bTimeout2;
boolean Oxy_sens_diag_test_completed;
boolean Oxy_sens_diag_test_finished;
boolean Oxy_sens_period_apv_failure;
boolean Oxy_sens_period_failure;
boolean SenO2Us_bAcvSeqMemOxyApvPerd;
boolean SenO2Us_bAcvSeqMemOxySensPerd;
boolean SenO2Us_bAcvSeqOxyApvPerd;
boolean SenO2Us_bAcvSeqOxySensPerd;
boolean SenO2Us_bDgoORng_OxyApvPerd;
boolean SenO2Us_bDgoORng_OxySensPerd;
boolean SenO2Us_bMonRunORng_OxyApvPerd;
boolean SenO2Us_bMonRunORng_OxySensPerd;
boolean SenO2Us_bMonRunRaw_OxyApvPerd;
boolean SenO2Us_bMonRunRaw_OxySensPerd;
boolean SenO2Us_bMonWaitORng_OxyApvPerd;
boolean SenO2Us_bMonWaitORng_OxySensPerd;
boolean SenO2Us_bMonWaitRaw_OxyApvPerd;
boolean SenO2Us_bMonWaitRaw_OxySensPerd;
uint8 HEATSENO2UPPERDDIAG_u8SysGasPrev;
uint8 Os_period_tests_done;
uint8 Oxy_period_tests;
uint16 Dnstr_modifier_temp;
uint16 Lfbk_on_enlean_clamp_delay;
uint16 Lfbk_on_enrich_clamp_delay;
uint16 LsMon_noRatEfcLsUsPer;
uint16 LsMon_tiPerUs;
uint16 Max_oxy_apv_period_l;
uint16 Max_oxy_apv_period_r;
uint16 Max_oxy_sens_period_l;
uint16 Max_oxy_sens_period_r;
uint16 Oxy_apv_period_map_max;
uint16 Oxy_sens_lower_voltage_thresh;
uint16 Oxy_sens_period_map_max;
uint16 Oxy_sens_upper_voltage_thresh;
uint16 Oxy_ups_period;
uint16 Oxy_ups_period_lean;
uint16 Oxy_ups_period_rich;
uint16 Oxy_ups_tempo_lean;
uint16 Oxy_ups_tempo_rich;
uint16 SenO2Us_PerDiag_FacMax_Obd6Mod;
uint16 SenO2Us_PerDiag_FacMaxRaw;
uint16 SenO2Us_PerDiag_FacMes_Obd6Mod;
uint16 SenO2Us_PerDiag_FacMesRaw;
uint16 SenO2Us_PerDiag_tiInhDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

