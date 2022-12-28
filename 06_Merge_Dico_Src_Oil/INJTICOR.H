/***************************************************************************
;**
;** FILE NAME      : INJTICOR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJTICOR_H
#define INJTICOR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Inj_SampleTiMid_SC                200

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

extern const boolean  Inj_bAcvSeqDftFu_Afl_C;
extern const boolean  Inj_bAcvSeqDftFu_Afr_C;
extern const boolean  Inj_bAcvSeqDftSenO2_Afl_C;
extern const boolean  Inj_bAcvSeqDftSenO2_Afr_C;
extern const boolean  Inj_bAcvSeqORngLfbk_Afl_C;
extern const boolean  Inj_bAcvSeqORngLfbk_Afr_C;
extern const boolean  Inj_bAcvSeqORngLfbkGas_Afl_C;
extern const boolean  Inj_bInhDiagPresScav_C;
extern const boolean  Lfbk_diag_trim_enable;
extern const boolean  Manu_inh_lfbk_monitoring;
extern const uint32  Lfbk_settling_delay_c;
extern const uint32  Lfbk_settling_delay_gas_c;
extern const uint8  Lfbk_enlean_extra_c;
extern const uint8  Lfbk_enlean_extra_gas_c;
extern const uint8  Lfbk_enlean_max_c;
extern const uint8  Lfbk_enlean_max_gas_c;
extern const uint8  Lfbk_enlean_percent_c;
extern const uint8  Lfbk_enlean_percent_gas_c;
extern const uint8  Lfbk_enrich_extra_c;
extern const uint8  Lfbk_enrich_extra_gas_c;
extern const uint8  Lfbk_enrich_max_c;
extern const uint8  Lfbk_enrich_max_gas_c;
extern const uint8  Lfbk_enrich_percent_c;
extern const uint8  Lfbk_enrich_percent_gas_c;
extern const uint8  Lfbk_min_temp_c;
extern const uint8  Lfbk_min_temp_gas_c;
extern const uint8  Lfbk_stuck_lean_delay;
extern const uint8  Lfbk_stuck_rich_delay;
extern const uint8  Lfbk_switch_lean_delay;
extern const uint8  Lfbk_switch_rich_delay;
extern const uint16  Flev_low_fuel_level_lfbk_tempo;
extern const uint16  Flev_low_gas_level_lfbk_tempo;
extern const uint16  Inj_tiInhDiag_C;
extern const uint16  Lfbk_clamp_test_time_c;
extern const uint16  Lfbk_clamp_test_time_gas_c;
extern const uint16  Lfbk_desired_conditions_delay_C;
extern const uint16  Lfbk_desired_conditions_dly_g_C;
extern const uint16  Lfbk_diag_aborted_delay_c;
extern const uint16  Lfbk_diag_aborted_delay_gas_c;
extern const uint16  Lfbk_fuelling_clamp_delay_c;
extern const uint16  Lfbk_fuelling_clamp_delay_gas_c;
extern const uint16  Lfbk_no_failure_delay_c;
extern const uint16  Lfbk_no_failure_delay_gas_c;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Inj_bAcvSeqDftFu_Afl;
extern boolean Inj_bAcvSeqDftFu_Afr;
extern boolean Inj_bAcvSeqDftFuGas_Afl;
extern boolean Inj_bAcvSeqDftFuGas_Afr;
extern boolean Inj_bAcvSeqDftSenO2_Afl;
extern boolean Inj_bAcvSeqDftSenO2_Afr;
extern boolean Inj_bAcvSeqDftSenO2Gas_Afl;
extern boolean Inj_bAcvSeqDftSenO2Gas_Afr;
extern boolean Inj_bAcvSeqMemDftFu_Afl;
extern boolean Inj_bAcvSeqMemDftFu_Afr;
extern boolean Inj_bAcvSeqMemDftFuGas_Afl;
extern boolean Inj_bAcvSeqMemDftFuGas_Afr;
extern boolean Inj_bAcvSeqMemDftSenO2_Afl;
extern boolean Inj_bAcvSeqMemDftSenO2_Afr;
extern boolean Inj_bAcvSeqMemDftSenO2Gas_Afl;
extern boolean Inj_bAcvSeqMemDftSenO2Gas_Afr;
extern boolean Inj_bAcvSeqMemORngLfbk_Afl;
extern boolean Inj_bAcvSeqMemORngLfbk_Afr;
extern boolean Inj_bAcvSeqMemORngLfbkGas_Afl;
extern boolean Inj_bAcvSeqMemORngLfbkGas_Afr;
extern boolean Inj_bAcvSeqORngLfbk_Afl;
extern boolean Inj_bAcvSeqORngLfbk_Afr;
extern boolean Inj_bAcvSeqORngLfbkGas_Afl;
extern boolean Inj_bAcvSeqORngLfbkGas_Afr;
extern boolean Lfbk_cor_completed;
extern boolean Lfbk_diag_no_failure_completed;
extern boolean Lfbk_mon_diag_test_request;
extern sint8 Diag_trim;
extern sint16 Inj_InjTiCorFacMax_Obd6Mod;
extern sint16 Inj_InjTiCorFacMes_Obd6Mod;
extern sint16 Inj_InjTiCorFacMin_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Inj_EveRst_InjTiCor(void);
void Inj_EveRTSt_InjTiCor(void);
void Inj_SdlFast_InjTiCor(void);
void Inj_SdlMid_InjTiCor(void);


#endif /* INJTICOR_H */

/*-------------------------------- end of file -------------------------------*/
