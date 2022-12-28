/***************************************************************************
;**
;** FILE NAME      : HEATSENO2USCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2USCMD_H
#define HEATSENO2USCMD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define LSSYS_FACLSUSMAINOXCHEATPHASED_M_LNS  ( 8 )
#define LSSYS_FACLSUSMAINOXCHEATPHASED_M_COLS  ( 8 )
#define LSSYS_FACLSUSOXCHEATPHASEC1_M_LNS     ( 8 )
#define LSSYS_FACLSUSOXCHEATPHASEC1_M_COLS     ( 8 )
#define LSSYS_FACLSUSOXCHEATPHASEC2_M_LNS     ( 8 )
#define LSSYS_FACLSUSOXCHEATPHASEC2_M_COLS     ( 8 )
#define LSSYS_MFEGTOTUSHEATPHASEC1_T_COLS      ( 8 )
#define LSSYS_MFEGTOTUSHEATPHASEC2_T_COLS      ( 8 )
#define LSSYS_MFEGTOTUSHEATPHASED_T_COLS       ( 8 )
#define LSSYS_MFEGTOTUSHEATPWRMOD_T_COLS       ( 8 )
#define LSSYS_RLSUSMAINOXCHEATPHASEC1_M_COLS   ( 6 )
#define LSSYS_RLSUSMAINOXCHEATPHASEC2_M_COLS   ( 6 )
#define LSSYS_RLSUSMAINOXCHEATPWRMOD_M_LNS    ( 8 )
#define LSSYS_RLSUSMAINOXCHEATPWRMOD_M_COLS    ( 8 )
#define LSSYS_TCOLSUSMAINOXCHEATPHAC1_T_COLS   ( 6 )
#define LSSYS_TCOLSUSMAINOXCHEATPHAC2_T_COLS   ( 6 )
#define LSSYS_TEXESTIMUSHEATPHASEC1_T_COLS     ( 8 )
#define LSSYS_TEXESTIMUSHEATPHASEC2_T_COLS     ( 8 )
#define LSSYS_TEXESTIMUSHEATPHASED_T_COLS      ( 8 )
#define LSSYS_TEXESTIMUSHEATPWRMOD_T_COLS      ( 8 )

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

extern const boolean  Lshd_lbup_heat_diag_ena_uacb0;
extern const boolean  Lshd_upstr_t_on_strategy;
extern const boolean  LsSys_bUsHeatPwrManEna_C;
extern const uint8  Lshd_lbup_diag_cmd_per_uacn0;
extern const uint8  LsSys_facLsUsMainOxCHeatPhaseD_M[LSSYS_FACLSUSMAINOXCHEATPHASED_M_LNS][LSSYS_FACLSUSMAINOXCHEATPHASED_M_COLS];
extern const uint8  LsSys_facLsUsOxCHeatPhaseC1_M[LSSYS_FACLSUSOXCHEATPHASEC1_M_LNS][LSSYS_FACLSUSOXCHEATPHASEC1_M_COLS];
extern const uint8  LsSys_facLsUsOxCHeatPhaseC2_M[LSSYS_FACLSUSOXCHEATPHASEC2_M_LNS][LSSYS_FACLSUSOXCHEATPHASEC2_M_COLS];
extern const uint8  LsSys_rLsUsMainOxCHeatPhaseB_C;
extern const uint8  LsSys_rLsUsMainOxCHeatPhaseC1_M[LSSYS_RLSUSMAINOXCHEATPHASEC1_M_COLS];
extern const uint8  LsSys_rLsUsMainOxCHeatPhaseC2_M[LSSYS_RLSUSMAINOXCHEATPHASEC2_M_COLS];
extern const uint8  LsSys_rLsUsMainOxCHeatPhaseD_C;
extern const uint8  LsSys_rLsUsMainOxCHeatPhaseF_C;
extern const uint8  LsSys_rLsUsMainOxCHeatPwrMod_M[LSSYS_RLSUSMAINOXCHEATPWRMOD_M_LNS][LSSYS_RLSUSMAINOXCHEATPWRMOD_M_COLS];
extern const uint8  LsSys_rUsHeatPwrMan_C;
extern const uint8  LsSys_tCoLsUsMainOxCHeatPhaC1_T[LSSYS_TCOLSUSMAINOXCHEATPHAC1_T_COLS];
extern const uint8  LsSys_tCoLsUsMainOxCHeatPhaC2_T[LSSYS_TCOLSUSMAINOXCHEATPHAC2_T_COLS];
extern const uint8  LsSys_uBattUsHeatRef;
extern const uint8  LsSys_UsPosSlopHeatDewProt_C;
extern const uint8  LsSys_UsPosSlopHeatHi_C;
extern const uint8  LsSys_UsPosSlopHeatHot_C;
extern const uint8  LsSys_UsPosSlopHeatNoHi_C;
extern const uint8  LsSys_UsPosSlopHeatWku_C;
extern const sint16  LsSys_UsNegSlopHeatDewProt_C;
extern const sint16  LsSys_UsNegSlopHeatHi_C;
extern const sint16  LsSys_UsNegSlopHeatWku_C;
extern const uint16  Lshd_upstr_rco_per_uacn0;
extern const uint16  Lshd_upstr_t_on_delay;
extern const uint16  LsSys_mfEgTotUsHeatPhaseC1_T[LSSYS_MFEGTOTUSHEATPHASEC1_T_COLS];
extern const uint16  LsSys_mfEgTotUsHeatPhaseC2_T[LSSYS_MFEGTOTUSHEATPHASEC2_T_COLS];
extern const uint16  LsSys_mfEgTotUsHeatPhaseD_T[LSSYS_MFEGTOTUSHEATPHASED_T_COLS];
extern const uint16  LsSys_mfEgTotUsHeatPwrMod_T[LSSYS_MFEGTOTUSHEATPWRMOD_T_COLS];
extern const uint16  LsSys_tExEstimUsHeatPhaseC1_T[LSSYS_TEXESTIMUSHEATPHASEC1_T_COLS];
extern const uint16  LsSys_tExEstimUsHeatPhaseC2_T[LSSYS_TEXESTIMUSHEATPHASEC2_T_COLS];
extern const uint16  LsSys_tExEstimUsHeatPhaseD_T[LSSYS_TEXESTIMUSHEATPHASED_T_COLS];
extern const uint16  LsSys_tExEstimUsHeatPwrMod_T[LSSYS_TEXESTIMUSHEATPWRMOD_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Chauf_o2_amont_demande_on;
extern boolean Chauffage_sonde_o2_amont;
extern boolean HeatSenO2_bMonRunUsHeatCmd;
extern uint8 LsSys_rLsUsMainOxCHeatPwrMan;
extern uint8 LsSys_rLsUsMainOxCHeatPwrReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_SdlFast_UsCmd(void);
void HeatSenO2_SdlMid_UsCmd(void);
void HEATSENO2USCMD_vidEntryInit(void);


#endif /* HEATSENO2USCMD_H */

/*-------------------------------- end of file -------------------------------*/
