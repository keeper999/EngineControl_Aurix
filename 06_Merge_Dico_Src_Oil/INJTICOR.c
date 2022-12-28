/***************************************************************************
;**
;** FILE NAME      : INJTICOR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJTICOR.H"
#include "INJTICOR_L.H"
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
const boolean  Inj_bAcvSeqDftFu_Afl_C = 0;
const boolean  Inj_bAcvSeqDftFu_Afr_C = 0;
const boolean  Inj_bAcvSeqDftSenO2_Afl_C = 0;
const boolean  Inj_bAcvSeqDftSenO2_Afr_C = 0;
const boolean  Inj_bAcvSeqORngLfbk_Afl_C = 0;
const boolean  Inj_bAcvSeqORngLfbk_Afr_C = 0;
const boolean  Inj_bAcvSeqORngLfbkGas_Afl_C = 0;
const boolean  Inj_bInhDiagPresScav_C = 0;
const boolean  Lfbk_diag_trim_enable = 0;
const boolean  Manu_inh_lfbk_monitoring = 0;
const uint32  Lfbk_settling_delay_c = 0;
const uint32  Lfbk_settling_delay_gas_c = 0;
const uint8  INJTICOR_u8Inhib = 0;
const uint8  Lfbk_enlean_extra_c = 0;
const uint8  Lfbk_enlean_extra_gas_c = 0;
const uint8  Lfbk_enlean_max_c = 0;
const uint8  Lfbk_enlean_max_gas_c = 0;
const uint8  Lfbk_enlean_percent_c = 0;
const uint8  Lfbk_enlean_percent_gas_c = 0;
const uint8  Lfbk_enrich_extra_c = 0;
const uint8  Lfbk_enrich_extra_gas_c = 0;
const uint8  Lfbk_enrich_max_c = 0;
const uint8  Lfbk_enrich_max_gas_c = 0;
const uint8  Lfbk_enrich_percent_c = 0;
const uint8  Lfbk_enrich_percent_gas_c = 0;
const uint8  Lfbk_min_temp_c = 0;
const uint8  Lfbk_min_temp_gas_c = 0;
const uint8  Lfbk_stuck_lean_delay = 0;
const uint8  Lfbk_stuck_rich_delay = 0;
const uint8  Lfbk_switch_lean_delay = 0;
const uint8  Lfbk_switch_rich_delay = 0;
const uint16  Flev_low_fuel_level_lfbk_tempo = 0;
const uint16  Flev_low_gas_level_lfbk_tempo = 0;
const uint16  Inj_tiInhDiag_C = 0;
const uint16  Lfbk_clamp_test_time_c = 0;
const uint16  Lfbk_clamp_test_time_gas_c = 0;
const uint16  Lfbk_desired_conditions_delay_C = 0;
const uint16  Lfbk_desired_conditions_dly_g_C = 0;
const uint16  Lfbk_diag_aborted_delay_c = 0;
const uint16  Lfbk_diag_aborted_delay_gas_c = 0;
const uint16  Lfbk_fuelling_clamp_delay_c = 0;
const uint16  Lfbk_fuelling_clamp_delay_gas_c = 0;
const uint16  Lfbk_no_failure_delay_c = 0;
const uint16  Lfbk_no_failure_delay_gas_c = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Check_fuelling_fault;
boolean Clamp_operated;
boolean Flev_low_fuel_level_Afl;
boolean Inj_bAcvSeqDftFu_Afl;
boolean Inj_bAcvSeqDftFu_Afr;
boolean Inj_bAcvSeqDftFuGas_Afl;
boolean Inj_bAcvSeqDftFuGas_Afr;
boolean Inj_bAcvSeqDftSenO2_Afl;
boolean Inj_bAcvSeqDftSenO2_Afr;
boolean Inj_bAcvSeqDftSenO2Gas_Afl;
boolean Inj_bAcvSeqDftSenO2Gas_Afr;
boolean Inj_bAcvSeqMemDftFu_Afl;
boolean Inj_bAcvSeqMemDftFu_Afr;
boolean Inj_bAcvSeqMemDftFuGas_Afl;
boolean Inj_bAcvSeqMemDftFuGas_Afr;
boolean Inj_bAcvSeqMemDftSenO2_Afl;
boolean Inj_bAcvSeqMemDftSenO2_Afr;
boolean Inj_bAcvSeqMemDftSenO2Gas_Afl;
boolean Inj_bAcvSeqMemDftSenO2Gas_Afr;
boolean Inj_bAcvSeqMemORngLfbk_Afl;
boolean Inj_bAcvSeqMemORngLfbk_Afr;
boolean Inj_bAcvSeqMemORngLfbkGas_Afl;
boolean Inj_bAcvSeqMemORngLfbkGas_Afr;
boolean Inj_bAcvSeqORngLfbk_Afl;
boolean Inj_bAcvSeqORngLfbk_Afr;
boolean Inj_bAcvSeqORngLfbkGas_Afl;
boolean Inj_bAcvSeqORngLfbkGas_Afr;
boolean Inj_bDgoDftFu_Afl;
boolean Inj_bDgoDftFu_Afr;
boolean Inj_bDgoDftFuGas_Afl;
boolean Inj_bDgoDftFuGas_Afr;
boolean Inj_bDgoDftSenO2_Afl;
boolean Inj_bDgoDftSenO2_Afr;
boolean Inj_bDgoDftSenO2Gas_Afl;
boolean Inj_bDgoDftSenO2Gas_Afr;
boolean Inj_bDgoORngLfbk_Afl;
boolean Inj_bDgoORngLfbk_Afr;
boolean Inj_bDgoORngLfbkGas_Afl;
boolean Inj_bDgoORngLfbkGas_Afr;
boolean Inj_bMonRunDftFu_Afl;
boolean Inj_bMonRunDftFu_Afr;
boolean Inj_bMonRunDftFuGas_Afl;
boolean Inj_bMonRunDftFuGas_Afr;
boolean Inj_bMonRunDftSenO2_Afl;
boolean Inj_bMonRunDftSenO2_Afr;
boolean Inj_bMonRunDftSenO2Gas_Afl;
boolean Inj_bMonRunDftSenO2Gas_Afr;
boolean Inj_bMonRunORngLfbk_Afl;
boolean Inj_bMonRunORngLfbk_Afr;
boolean Inj_bMonRunORngLfbkGas_Afl;
boolean Inj_bMonRunORngLfbkGas_Afr;
boolean Inj_bMonWaitDftFu_Afl;
boolean Inj_bMonWaitDftFu_Afr;
boolean Inj_bMonWaitDftFuGas_Afl;
boolean Inj_bMonWaitDftFuGas_Afr;
boolean Inj_bMonWaitDftSenO2_Afl;
boolean Inj_bMonWaitDftSenO2_Afr;
boolean Inj_bMonWaitDftSenO2Gas_Afl;
boolean Inj_bMonWaitDftSenO2Gas_Afr;
boolean Inj_bMonWaitORngLfbk_Afl;
boolean Inj_bMonWaitORngLfbk_Afr;
boolean Inj_bMonWaitORngLfbkGas_Afl;
boolean Inj_bMonWaitORngLfbkGas_Afr;
boolean Lfbk_clamp_tests_aborted;
boolean Lfbk_cor_completed;
boolean Lfbk_desired_conditions;
boolean Lfbk_diag_completed;
boolean Lfbk_diag_enable;
boolean Lfbk_diag_no_failure_completed;
boolean Lfbk_init_fait;
boolean Lfbk_lean_fuel;
boolean Lfbk_mon_diag_test_request;
boolean Lfbk_rich_fuel;
boolean Lfbk_stuck_diag_done;
boolean Lfbk_stuck_lean;
boolean Lfbk_stuck_rich;
boolean Lfbk_switch_lean;
boolean Lfbk_switch_rich;
boolean Oxy_sensor_test;
uint32 Lfbk_settling_delay_count;
sint8 Diag_trim;
uint8 INJTICOR_u8Ext_stSysGasPrev;
uint8 Lfbk_stuck_lean_delay_count;
uint8 Lfbk_stuck_rich_delay_count;
uint8 Lfbk_switch_lean_delay_count;
uint8 Lfbk_switch_rich_delay_count;
sint16 Inj_InjTiCorFacMax_Obd6Mod;
sint16 Inj_InjTiCorFacMes_Obd6Mod;
sint16 Inj_InjTiCorFacMin_Obd6Mod;
uint16 Flev_low_fuel_level_lfbk_count;
uint16 Inj_tiInhDiag;
uint16 Lfbk_clamp_corr_count;
uint16 Lfbk_desired_conditions_counter;
uint16 Lfbk_diag_aborted_count;
uint16 Lfbk_end_of_delay_period_count;
uint16 Lfbk_tempo_no_failure;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

