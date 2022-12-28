/***************************************************************************
;**
;** FILE NAME      : HEATSENO2USCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2USCMD.H"
#include "HEATSENO2USCMD_L.H"
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
const boolean  Lshd_lbup_heat_diag_ena_uacb0 = 0;
const boolean  Lshd_upstr_t_on_strategy = 0;
const boolean  LsSys_bUsHeatPwrManEna_C = 0;
const uint8  HEATSENO2USCMD_u8Inhib = 0;
const uint8  Lshd_lbup_diag_cmd_per_uacn0 = 0;
const uint8  LsSys_facLsUsMainOxCHeatPhaseD_M[LSSYS_FACLSUSMAINOXCHEATPHASED_M_LNS][LSSYS_FACLSUSMAINOXCHEATPHASED_M_COLS] = {0};
const uint8  LsSys_facLsUsOxCHeatPhaseC1_M[LSSYS_FACLSUSOXCHEATPHASEC1_M_LNS][LSSYS_FACLSUSOXCHEATPHASEC1_M_COLS] = {0};
const uint8  LsSys_facLsUsOxCHeatPhaseC2_M[LSSYS_FACLSUSOXCHEATPHASEC2_M_LNS][LSSYS_FACLSUSOXCHEATPHASEC2_M_COLS] = {0};
const uint8  LsSys_rLsUsMainOxCHeatPhaseB_C = 0;
const uint8  LsSys_rLsUsMainOxCHeatPhaseC1_M[LSSYS_RLSUSMAINOXCHEATPHASEC1_M_COLS] = {0};
const uint8  LsSys_rLsUsMainOxCHeatPhaseC2_M[LSSYS_RLSUSMAINOXCHEATPHASEC2_M_COLS] = {0};
const uint8  LsSys_rLsUsMainOxCHeatPhaseD_C = 0;
const uint8  LsSys_rLsUsMainOxCHeatPhaseF_C = 0;
const uint8  LsSys_rLsUsMainOxCHeatPwrMod_M[LSSYS_RLSUSMAINOXCHEATPWRMOD_M_LNS][LSSYS_RLSUSMAINOXCHEATPWRMOD_M_COLS] = {0};
const uint8  LsSys_rUsHeatPwrMan_C = 0;
const uint8  LsSys_tCoLsUsMainOxCHeatPhaC1_T[LSSYS_TCOLSUSMAINOXCHEATPHAC1_T_COLS] = {0};
const uint8  LsSys_tCoLsUsMainOxCHeatPhaC2_T[LSSYS_TCOLSUSMAINOXCHEATPHAC2_T_COLS] = {0};
const uint8  LsSys_uBattUsHeatRef = 0;
const uint8  LsSys_UsPosSlopHeatDewProt_C = 0;
const uint8  LsSys_UsPosSlopHeatHi_C = 0;
const uint8  LsSys_UsPosSlopHeatHot_C = 0;
const uint8  LsSys_UsPosSlopHeatNoHi_C = 0;
const uint8  LsSys_UsPosSlopHeatWku_C = 0;
const sint16  LsSys_UsNegSlopHeatDewProt_C = 0;
const sint16  LsSys_UsNegSlopHeatHi_C = 0;
const sint16  LsSys_UsNegSlopHeatWku_C = 0;
const uint16  Lshd_upstr_rco_per_uacn0 = 0;
const uint16  Lshd_upstr_t_on_delay = 0;
const uint16  LsSys_mfEgTotUsHeatPhaseC1_T[LSSYS_MFEGTOTUSHEATPHASEC1_T_COLS] = {0};
const uint16  LsSys_mfEgTotUsHeatPhaseC2_T[LSSYS_MFEGTOTUSHEATPHASEC2_T_COLS] = {0};
const uint16  LsSys_mfEgTotUsHeatPhaseD_T[LSSYS_MFEGTOTUSHEATPHASED_T_COLS] = {0};
const uint16  LsSys_mfEgTotUsHeatPwrMod_T[LSSYS_MFEGTOTUSHEATPWRMOD_T_COLS] = {0};
const uint16  LsSys_tExEstimUsHeatPhaseC1_T[LSSYS_TEXESTIMUSHEATPHASEC1_T_COLS] = {0};
const uint16  LsSys_tExEstimUsHeatPhaseC2_T[LSSYS_TEXESTIMUSHEATPHASEC2_T_COLS] = {0};
const uint16  LsSys_tExEstimUsHeatPhaseD_T[LSSYS_TEXESTIMUSHEATPHASED_T_COLS] = {0};
const uint16  LsSys_tExEstimUsHeatPwrMod_T[LSSYS_TEXESTIMUSHEATPWRMOD_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Chauf_o2_amont_demande_on;
boolean Chauffage_sonde_o2_amont;
boolean HeatSenO2_bMonRunUsHeatCmd;
boolean Lshd_upstr_period_updating;
boolean LsSys_bLsUsMainOxCHeatPwrCmd;
uint8 HEATSENO2USCMD_u8DiagCmdCntPrev;
uint8 HEATSENO2USCMD_u8MainOxCHeatPrev;
uint8 Lshd_lbup_diag_cmd_counter;
uint8 LsSys_rLsUsMainOxCHeatPwrCor;
uint8 LsSys_rLsUsMainOxCHeatPwrDiag;
uint8 LsSys_rLsUsMainOxCHeatPwrMan;
uint8 LsSys_rLsUsMainOxCHeatPwrRaw;
uint8 LsSys_rLsUsMainOxCHeatPwrReq;
uint8 LsSys_UsPosSlopHeat;
sint16 LsSys_UsNegSlopHeat;
uint16 HEATSENO2USCMD_u16RcoPeriodPrev;
uint16 Lshd_upstr_period_counter;
uint16 Lshd_upstr_rco_periode;
uint16 Lshd_upstr_t_on_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

