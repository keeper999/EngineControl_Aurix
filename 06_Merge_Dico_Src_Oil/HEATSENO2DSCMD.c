/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2DSCMD.H"
#include "HEATSENO2DSCMD_L.H"
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
const boolean  Lshd_dwstr_t_on_strategy = 0;
const boolean  Lshd_lbdw_heat_diag_ena_uacb0 = 0;
const boolean  LsSys_bDsHeatPwrManEna_C = 0;
const uint8  HEATSENO2DSCMD_u8Inhib = 0;
const uint8  Lshd_lbdw_diag_cmd_per_uacn0 = 0;
const uint8  LsSys_DsPosSlopHeatDewProt_C = 0;
const uint8  LsSys_DsPosSlopHeatHi_C = 0;
const uint8  LsSys_DsPosSlopHeatHot_C = 0;
const uint8  LsSys_DsPosSlopHeatNoHi_C = 0;
const uint8  LsSys_DsPosSlopHeatWku_C = 0;
const uint8  LsSys_facLsDsMainOxCHeatPhaseD_M[LSSYS_FACLSDSMAINOXCHEATPHASED_M_LNS][LSSYS_FACLSDSMAINOXCHEATPHASED_M_COLS] = {0};
const uint8  LsSys_facLsDsOxCHeatPhaseC1_M[LSSYS_FACLSDSOXCHEATPHASEC1_M_LNS][LSSYS_FACLSDSOXCHEATPHASEC1_M_COLS] = {0};
const uint8  LsSys_facLsDsOxCHeatPhaseC2_M[LSSYS_FACLSDSOXCHEATPHASEC2_M_LNS][LSSYS_FACLSDSOXCHEATPHASEC2_M_COLS] = {0};
const uint8  LsSys_rDsHeatPwrMan_C = 0;
const uint8  LsSys_rLsDsMainOxCHeatPhaseB_C = 0;
const uint8  LsSys_rLsDsMainOxCHeatPhaseC1_M[LSSYS_RLSDSMAINOXCHEATPHASEC1_M_COLS] = {0};
const uint8  LsSys_rLsDsMainOxCHeatPhaseC2_M[LSSYS_RLSDSMAINOXCHEATPHASEC2_M_COLS] = {0};
const uint8  LsSys_rLsDsMainOxCHeatPhaseD_C = 0;
const uint8  LsSys_rLsDsMainOxCHeatPhaseF_C = 0;
const uint8  LsSys_rLsDsMainOxCHeatPwrMod_M[LSSYS_RLSDSMAINOXCHEATPWRMOD_M_LNS][LSSYS_RLSDSMAINOXCHEATPWRMOD_M_COLS] = {0};
const uint8  LsSys_tCoLsDsMainOxCHeatPhaC1_T[LSSYS_TCOLSDSMAINOXCHEATPHAC1_T_COLS] = {0};
const uint8  LsSys_tCoLsDsMainOxCHeatPhaC2_T[LSSYS_TCOLSDSMAINOXCHEATPHAC2_T_COLS] = {0};
const uint8  LsSys_uBattDsHeatRef = 0;
const sint16  LsSys_DsNegSlopHeatDewProt_C = 0;
const sint16  LsSys_DsNegSlopHeatHi_C = 0;
const sint16  LsSys_DsNegSlopHeatWku_C = 0;
const uint16  Lshd_dwstr_rco_per_uacn0 = 0;
const uint16  Lshd_dwstr_t_on_delay = 0;
const uint16  LsSys_mfEgTotDsHeatPhaseC1_T[LSSYS_MFEGTOTDSHEATPHASEC1_T_COLS] = {0};
const uint16  LsSys_mfEgTotDsHeatPhaseC2_T[LSSYS_MFEGTOTDSHEATPHASEC2_T_COLS] = {0};
const uint16  LsSys_mfEgTotDsHeatPhaseD_T[LSSYS_MFEGTOTDSHEATPHASED_T_COLS] = {0};
const uint16  LsSys_mfEgTotDsHeatPwrMod_T[LSSYS_MFEGTOTDSHEATPWRMOD_T_COLS] = {0};
const uint16  LsSys_tExEstimDsHeatPhaseC1_T[LSSYS_TEXESTIMDSHEATPHASEC1_T_COLS] = {0};
const uint16  LsSys_tExEstimDsHeatPhaseC2_T[LSSYS_TEXESTIMDSHEATPHASEC2_T_COLS] = {0};
const uint16  LsSys_tExEstimDsHeatPhaseD_T[LSSYS_TEXESTIMDSHEATPHASED_T_COLS] = {0};
const uint16  LsSys_tExEstimDsHeatPwrMod_T[LSSYS_TEXESTIMDSHEATPWRMOD_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Chauf_o2_aval_demande_on;
boolean Chauffage_sonde_o2_aval;
boolean HeatSenO2_bMonRunDsHeatCmd;
boolean Lshd_down_lbda_sens_heat_active;
boolean Lshd_dwstr_period_updating;
boolean LsSys_bLsDsMainOxCHeatPwrCmd;
uint8 HEATSENO2DSCMD_u8DiagCmdCntPrev;
uint8 HEATSENO2DSCMD_u8MainOxCHeatPrev;
uint8 Lshd_lbdw_diag_cmd_counter;
uint8 LsSys_DsPosSlopHeat;
uint8 LsSys_rLsDsMainOxCHeatPwrCor;
uint8 LsSys_rLsDsMainOxCHeatPwrDiag;
uint8 LsSys_rLsDsMainOxCHeatPwrMan;
uint8 LsSys_rLsDsMainOxCHeatPwrRaw;
uint8 LsSys_rLsDsMainOxCHeatPwrReq;
sint16 LsSys_DsNegSlopHeat;
uint16 HEATSENO2DSCMD_u16RcoPeriodPrev;
uint16 Lshd_dwstr_period_counter;
uint16 Lshd_dwstr_rco_periode;
uint16 Lshd_dwstr_t_on_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

