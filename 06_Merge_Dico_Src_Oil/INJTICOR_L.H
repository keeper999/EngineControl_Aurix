/***************************************************************************
;**
;** FILE NAME      : INJTICOR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJTICOR_L_H
#define INJTICOR_L_H

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


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  INJTICOR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Check_fuelling_fault;
extern boolean Clamp_operated;
extern boolean Flev_low_fuel_level_Afl;
extern boolean Inj_bDgoDftFu_Afl;
extern boolean Inj_bDgoDftFu_Afr;
extern boolean Inj_bDgoDftFuGas_Afl;
extern boolean Inj_bDgoDftFuGas_Afr;
extern boolean Inj_bDgoDftSenO2_Afl;
extern boolean Inj_bDgoDftSenO2_Afr;
extern boolean Inj_bDgoDftSenO2Gas_Afl;
extern boolean Inj_bDgoDftSenO2Gas_Afr;
extern boolean Inj_bDgoORngLfbk_Afl;
extern boolean Inj_bDgoORngLfbk_Afr;
extern boolean Inj_bDgoORngLfbkGas_Afl;
extern boolean Inj_bDgoORngLfbkGas_Afr;
extern boolean Inj_bMonRunDftFu_Afl;
extern boolean Inj_bMonRunDftFu_Afr;
extern boolean Inj_bMonRunDftFuGas_Afl;
extern boolean Inj_bMonRunDftFuGas_Afr;
extern boolean Inj_bMonRunDftSenO2_Afl;
extern boolean Inj_bMonRunDftSenO2_Afr;
extern boolean Inj_bMonRunDftSenO2Gas_Afl;
extern boolean Inj_bMonRunDftSenO2Gas_Afr;
extern boolean Inj_bMonRunORngLfbk_Afl;
extern boolean Inj_bMonRunORngLfbk_Afr;
extern boolean Inj_bMonRunORngLfbkGas_Afl;
extern boolean Inj_bMonRunORngLfbkGas_Afr;
extern boolean Inj_bMonWaitDftFu_Afl;
extern boolean Inj_bMonWaitDftFu_Afr;
extern boolean Inj_bMonWaitDftFuGas_Afl;
extern boolean Inj_bMonWaitDftFuGas_Afr;
extern boolean Inj_bMonWaitDftSenO2_Afl;
extern boolean Inj_bMonWaitDftSenO2_Afr;
extern boolean Inj_bMonWaitDftSenO2Gas_Afl;
extern boolean Inj_bMonWaitDftSenO2Gas_Afr;
extern boolean Inj_bMonWaitORngLfbk_Afl;
extern boolean Inj_bMonWaitORngLfbk_Afr;
extern boolean Inj_bMonWaitORngLfbkGas_Afl;
extern boolean Inj_bMonWaitORngLfbkGas_Afr;
extern boolean Lfbk_clamp_tests_aborted;
extern boolean Lfbk_desired_conditions;
extern boolean Lfbk_diag_completed;
extern boolean Lfbk_diag_enable;
extern boolean Lfbk_init_fait;
extern boolean Lfbk_lean_fuel;
extern boolean Lfbk_rich_fuel;
extern boolean Lfbk_stuck_diag_done;
extern boolean Lfbk_stuck_lean;
extern boolean Lfbk_stuck_rich;
extern boolean Lfbk_switch_lean;
extern boolean Lfbk_switch_rich;
extern boolean Oxy_sensor_test;
extern uint32 Lfbk_settling_delay_count;
extern uint8 INJTICOR_u8Ext_stSysGasPrev;
extern uint8 Lfbk_stuck_lean_delay_count;
extern uint8 Lfbk_stuck_rich_delay_count;
extern uint8 Lfbk_switch_lean_delay_count;
extern uint8 Lfbk_switch_rich_delay_count;
extern uint16 Flev_low_fuel_level_lfbk_count;
extern uint16 Inj_tiInhDiag;
extern uint16 Lfbk_clamp_corr_count;
extern uint16 Lfbk_desired_conditions_counter;
extern uint16 Lfbk_diag_aborted_count;
extern uint16 Lfbk_end_of_delay_period_count;
extern uint16 Lfbk_tempo_no_failure;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJTICOR_vidAcvDiagEngineRunning(void);
void INJTICOR_vidbDgoAlimLeanFuel(void);
void INJTICOR_vidbDgoAlimRichFuel(void);
void INJTICOR_vidbDgoSen02AmLeanBlo(void);
void INJTICOR_vidbDgoSen02AmRichBlo(void);
void INJTICOR_vidClampDiagnosis(void);
void INJTICOR_vidClampTstNotPerformed(void);
void INJTICOR_vidComputation(void);
void INJTICOR_vidCtrlLfbkMonitoring(void);
void INJTICOR_vidDiagComputation(void);
void INJTICOR_vidDiagEngineRunning(void);
void INJTICOR_vidDiagnostic(void);
void INJTICOR_vidDiagTrim(void);
void INJTICOR_vidEndOfDlyPeriodCntDec(void);
void INJTICOR_vidEndOfDlyPeriodCntMgr(void);
void INJTICOR_vidFailureManager(void);
void INJTICOR_vidFailuresCalculations(void);
void INJTICOR_vidFuelAdjustment(void);
void INJTICOR_vidInitGasMod(void);
void INJTICOR_vidInitGslMod(void);
void INJTICOR_vidInitializeCorrection(void);
void INJTICOR_vidInitLfbkMonitoring(void);
void INJTICOR_vidInitLfbkSwitchGslGas(void);
void INJTICOR_vidInitOutput(void);
void INJTICOR_vidInjTimeCorSwitchLean(void);
void INJTICOR_vidInjTimeCorSwitchRich(void);
void INJTICOR_vidLeanFuelCalc(void);
void INJTICOR_vidLfbkInitGas(void);
void INJTICOR_vidLfbkInitGsl(void);
void INJTICOR_vidLfbkMod6NoFailure(void);
void INJTICOR_vidLowFuelTempo(void);
void INJTICOR_vidNoFailure(void);
void INJTICOR_vidOnEnleanClampDiag(void);
void INJTICOR_vidOnEnrichClampDiag(void);
void INJTICOR_vidOxySensorTPerformed(void);
void INJTICOR_vidPerformClampTests(void);
void INJTICOR_vidReinitFarStraMon(void);
void INJTICOR_vidResetCorrection(void);
void INJTICOR_vidResetDelayCount(void);
void INJTICOR_vidResetDiag(void);
void INJTICOR_vidResetDiagTempo(void);
void INJTICOR_vidRichFuelCalc(void);
void INJTICOR_vidSeqDftFuAfl(void);
void INJTICOR_vidSeqDftFuAfr(void);
void INJTICOR_vidSeqDftSenO2Afl(void);
void INJTICOR_vidSeqDftSenO2Afr(void);
void INJTICOR_vidSeqORngLfbkAfl(void);
void INJTICOR_vidSeqORngLfbkAfr(void);
void INJTICOR_vidSwitchLeanCalc(void);
void INJTICOR_vidSwitchRichCalc(void);
void INJTICOR_vidTempoNoFailure(void);
void INJTICOR_vidWaitAbortFuelCheck(void);
void INJTICOR_vidWaitApplyInitAdjust(void);


#endif /* INJTICOR_L_H */

/*-------------------------------- end of file -------------------------------*/
