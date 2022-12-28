/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DSCMD_H
#define HEATSENO2DSCMD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define LSSYS_FACLSDSMAINOXCHEATPHASED_M_LNS  ( 8 )
#define LSSYS_FACLSDSMAINOXCHEATPHASED_M_COLS  ( 8 )
#define LSSYS_FACLSDSOXCHEATPHASEC1_M_LNS     ( 8 )
#define LSSYS_FACLSDSOXCHEATPHASEC1_M_COLS     ( 8 )
#define LSSYS_FACLSDSOXCHEATPHASEC2_M_LNS     ( 8 )
#define LSSYS_FACLSDSOXCHEATPHASEC2_M_COLS     ( 8 )
#define LSSYS_MFEGTOTDSHEATPHASEC1_T_COLS      ( 8 )
#define LSSYS_MFEGTOTDSHEATPHASEC2_T_COLS      ( 8 )
#define LSSYS_MFEGTOTDSHEATPHASED_T_COLS       ( 8 )
#define LSSYS_MFEGTOTDSHEATPWRMOD_T_COLS       ( 8 )
#define LSSYS_RLSDSMAINOXCHEATPHASEC1_M_COLS   ( 6 )
#define LSSYS_RLSDSMAINOXCHEATPHASEC2_M_COLS   ( 6 )
#define LSSYS_RLSDSMAINOXCHEATPWRMOD_M_LNS    ( 8 )
#define LSSYS_RLSDSMAINOXCHEATPWRMOD_M_COLS    ( 8 )
#define LSSYS_TCOLSDSMAINOXCHEATPHAC1_T_COLS   ( 6 )
#define LSSYS_TCOLSDSMAINOXCHEATPHAC2_T_COLS   ( 6 )
#define LSSYS_TEXESTIMDSHEATPHASEC1_T_COLS     ( 8 )
#define LSSYS_TEXESTIMDSHEATPHASEC2_T_COLS     ( 8 )
#define LSSYS_TEXESTIMDSHEATPHASED_T_COLS      ( 8 )
#define LSSYS_TEXESTIMDSHEATPWRMOD_T_COLS      ( 8 )

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

extern const boolean  Lshd_dwstr_t_on_strategy;
extern const boolean  Lshd_lbdw_heat_diag_ena_uacb0;
extern const boolean  LsSys_bDsHeatPwrManEna_C;
extern const uint8  Lshd_lbdw_diag_cmd_per_uacn0;
extern const uint8  LsSys_DsPosSlopHeatDewProt_C;
extern const uint8  LsSys_DsPosSlopHeatHi_C;
extern const uint8  LsSys_DsPosSlopHeatHot_C;
extern const uint8  LsSys_DsPosSlopHeatNoHi_C;
extern const uint8  LsSys_DsPosSlopHeatWku_C;
extern const uint8  LsSys_facLsDsMainOxCHeatPhaseD_M[LSSYS_FACLSDSMAINOXCHEATPHASED_M_LNS][LSSYS_FACLSDSMAINOXCHEATPHASED_M_COLS];
extern const uint8  LsSys_facLsDsOxCHeatPhaseC1_M[LSSYS_FACLSDSOXCHEATPHASEC1_M_LNS][LSSYS_FACLSDSOXCHEATPHASEC1_M_COLS];
extern const uint8  LsSys_facLsDsOxCHeatPhaseC2_M[LSSYS_FACLSDSOXCHEATPHASEC2_M_LNS][LSSYS_FACLSDSOXCHEATPHASEC2_M_COLS];
extern const uint8  LsSys_rDsHeatPwrMan_C;
extern const uint8  LsSys_rLsDsMainOxCHeatPhaseB_C;
extern const uint8  LsSys_rLsDsMainOxCHeatPhaseC1_M[LSSYS_RLSDSMAINOXCHEATPHASEC1_M_COLS];
extern const uint8  LsSys_rLsDsMainOxCHeatPhaseC2_M[LSSYS_RLSDSMAINOXCHEATPHASEC2_M_COLS];
extern const uint8  LsSys_rLsDsMainOxCHeatPhaseD_C;
extern const uint8  LsSys_rLsDsMainOxCHeatPhaseF_C;
extern const uint8  LsSys_rLsDsMainOxCHeatPwrMod_M[LSSYS_RLSDSMAINOXCHEATPWRMOD_M_LNS][LSSYS_RLSDSMAINOXCHEATPWRMOD_M_COLS];
extern const uint8  LsSys_tCoLsDsMainOxCHeatPhaC1_T[LSSYS_TCOLSDSMAINOXCHEATPHAC1_T_COLS];
extern const uint8  LsSys_tCoLsDsMainOxCHeatPhaC2_T[LSSYS_TCOLSDSMAINOXCHEATPHAC2_T_COLS];
extern const uint8  LsSys_uBattDsHeatRef;
extern const sint16  LsSys_DsNegSlopHeatDewProt_C;
extern const sint16  LsSys_DsNegSlopHeatHi_C;
extern const sint16  LsSys_DsNegSlopHeatWku_C;
extern const uint16  Lshd_dwstr_rco_per_uacn0;
extern const uint16  Lshd_dwstr_t_on_delay;
extern const uint16  LsSys_mfEgTotDsHeatPhaseC1_T[LSSYS_MFEGTOTDSHEATPHASEC1_T_COLS];
extern const uint16  LsSys_mfEgTotDsHeatPhaseC2_T[LSSYS_MFEGTOTDSHEATPHASEC2_T_COLS];
extern const uint16  LsSys_mfEgTotDsHeatPhaseD_T[LSSYS_MFEGTOTDSHEATPHASED_T_COLS];
extern const uint16  LsSys_mfEgTotDsHeatPwrMod_T[LSSYS_MFEGTOTDSHEATPWRMOD_T_COLS];
extern const uint16  LsSys_tExEstimDsHeatPhaseC1_T[LSSYS_TEXESTIMDSHEATPHASEC1_T_COLS];
extern const uint16  LsSys_tExEstimDsHeatPhaseC2_T[LSSYS_TEXESTIMDSHEATPHASEC2_T_COLS];
extern const uint16  LsSys_tExEstimDsHeatPhaseD_T[LSSYS_TEXESTIMDSHEATPHASED_T_COLS];
extern const uint16  LsSys_tExEstimDsHeatPwrMod_T[LSSYS_TEXESTIMDSHEATPWRMOD_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Chauf_o2_aval_demande_on;
extern boolean Chauffage_sonde_o2_aval;
extern boolean HeatSenO2_bMonRunDsHeatCmd;
extern boolean Lshd_down_lbda_sens_heat_active;
extern uint8 LsSys_rLsDsMainOxCHeatPwrMan;
extern uint8 LsSys_rLsDsMainOxCHeatPwrReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_SdlFast_DsCmd(void);
void HeatSenO2_SdlMid_DsCmd(void);
void HEATSENO2DSCMD_vidEntryInit(void);


#endif /* HEATSENO2DSCMD_H */

/*-------------------------------- end of file -------------------------------*/
