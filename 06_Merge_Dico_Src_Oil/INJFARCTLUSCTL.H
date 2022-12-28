/***************************************************************************
;**
;** FILE NAME      : INJFARCTLUSCTL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJFARCTLUSCTL_H
#define INJFARCTLUSCTL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENGINE_LOAD_BKPT_MAP_COLS              ( 16 )
#define ENGINE_LOAD_INJCTL_BKPT_MAP_COLS       ( 9 )
#define LAMBDA_FILT_FDBK_MODE_DELAY_MAP_COLS   ( 16 )
#define LAMBDA_L_STEP_LEAN_NON_IDLE_MAP_COLS   ( 9 )
#define LAMBDA_L_STEP_RICH_NON_IDLE_MAP_COLS   ( 9 )
#define LAMBDA_LARGE_LUMP_NON_IDLE_MAP_COLS    ( 9 )
#define LAMBDA_LUMP_LEAN_NON_IDLE_MAP_LNS     ( 9 )
#define LAMBDA_LUMP_LEAN_NON_IDLE_MAP_COLS     ( 9 )
#define LAMBDA_LUMP_RICH_NON_IDLE_MAP_LNS     ( 9 )
#define LAMBDA_LUMP_RICH_NON_IDLE_MAP_COLS     ( 9 )
#define LAMBDA_SLOW_MODE_DELAY_MAP_COLS        ( 16 )
#define LAMBDA_STEP_LEAN_NON_IDLE_MAP_LNS     ( 9 )
#define LAMBDA_STEP_LEAN_NON_IDLE_MAP_COLS     ( 9 )
#define LAMBDA_STEP_RICH_NON_IDLE_MAP_LNS     ( 9 )
#define LAMBDA_STEP_RICH_NON_IDLE_MAP_COLS     ( 9 )
#define LBDA_LEAN_ATTENUATION_GAIN_MAP_COLS    ( 16 )
#define LBDA_LUMP_ATTENUATION_GAIN_MAP_LNS    ( 16 )
#define LBDA_LUMP_ATTENUATION_GAIN_MAP_COLS    ( 9 )
#define LBDA_MAINTIEN_ATTENU_DELAY_MAP_COLS    ( 16 )
#define LBDA_RICH_ATTENUATION_GAIN_MAP_COLS    ( 16 )
#define LBDA_STEP_ATTENUATION_GAIN_MAP_LNS    ( 16 )
#define LBDA_STEP_ATTENUATION_GAIN_MAP_COLS    ( 9 )
#define LFFC_L_R_NON_IDLE_DELAY_EMIS_MAP_LNS  ( 9 )
#define LFFC_L_R_NON_IDLE_DELAY_EMIS_MAP_COLS  ( 9 )
#define LFFC_L_R_NON_IDLE_DELAY_NEUF_MAP_LNS  ( 9 )
#define LFFC_L_R_NON_IDLE_DELAY_NEUF_MAP_COLS  ( 9 )
#define LFFC_R_L_NON_IDLE_DELAY_EMIS_MAP_LNS  ( 9 )
#define LFFC_R_L_NON_IDLE_DELAY_EMIS_MAP_COLS  ( 9 )
#define LFFC_R_L_NON_IDLE_DELAY_NEUF_MAP_LNS  ( 9 )
#define LFFC_R_L_NON_IDLE_DELAY_NEUF_MAP_COLS  ( 9 )
#define REGIME_MOTEUR_INJCTL_BKPT_MAP_COLS     ( 9 )
#define T_REGULATION_MAP_LNS                  ( 9 )
#define T_REGULATION_MAP_COLS                  ( 9 )
#define TEMPERATURE_EAU_INJCTL_BKPT_MAP_COLS   ( 16 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st26 */
#define FEEDBACK_CLOSED_LOOP_INIT         8
#define FEEDBACK_MOVING_LEAN_TO_RICH      16
#define FEEDBACK_MOVING_RICH_TO_LEAN      32
#define FEEDBACK_SYSTEM_RICH              64
#define FEEDBACK_SYSTEM_LEAN              128
/*extern uint8 Feedback_calculations_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Feedback_saf_inh_diag_req_C;
extern const boolean  Lbda_att_always_manu_inh;
extern const boolean  Lbda_att_idle_manu_inh;
extern const boolean  Lbda_att_transient_manu_inh;
extern const boolean  Manu_inh_clamp_lambda_feedback;
extern const boolean  Manu_inh_Delta_PMH_gaz;
extern const boolean  Test_bed_transfer_count_l_to_r;
extern const boolean  Test_bed_transfer_count_r_to_l;
extern const uint8  Fast_tracking_water_temp_thresh;
extern const uint8  InjCtl_facFillamAdapt_C;
extern const uint8  InjCtl_tiDlyClcrlamAdapt_C;
extern const uint8  Lambda_fdbk_filter_fast_gain;
extern const uint8  Lambda_fdbk_filter_slow_gain;
extern const uint8  Lambda_filt_fdbk_mode_delay_idle;
extern const uint8  Lambda_filt_fdbk_mode_delay_map[LAMBDA_FILT_FDBK_MODE_DELAY_MAP_COLS];
extern const uint8  Lambda_for_saf_diag_lump_lean;
extern const uint8  Lambda_for_saf_diag_lump_rich;
extern const uint8  Lambda_for_saf_diag_step_lean;
extern const uint8  Lambda_for_saf_diag_step_rich;
extern const uint8  Lambda_l_step_lean_non_idle_map[LAMBDA_L_STEP_LEAN_NON_IDLE_MAP_COLS];
extern const uint8  Lambda_l_step_rich_non_idle_map[LAMBDA_L_STEP_RICH_NON_IDLE_MAP_COLS];
extern const uint8  Lambda_large_lump_lean_idle;
extern const uint8  Lambda_large_lump_non_idle_map[LAMBDA_LARGE_LUMP_NON_IDLE_MAP_COLS];
extern const uint8  Lambda_large_lump_rich_idle;
extern const uint8  Lambda_large_step_lean_idle;
extern const uint8  Lambda_large_step_rich_idle;
extern const uint8  Lambda_lump_lean_idle;
extern const uint8  Lambda_lump_lean_non_idle_map[LAMBDA_LUMP_LEAN_NON_IDLE_MAP_LNS][LAMBDA_LUMP_LEAN_NON_IDLE_MAP_COLS];
extern const uint8  Lambda_lump_rich_idle;
extern const uint8  Lambda_lump_rich_non_idle_map[LAMBDA_LUMP_RICH_NON_IDLE_MAP_LNS][LAMBDA_LUMP_RICH_NON_IDLE_MAP_COLS];
extern const uint8  Lambda_slow_mode_delay_idle;
extern const uint8  Lambda_slow_mode_delay_map[LAMBDA_SLOW_MODE_DELAY_MAP_COLS];
extern const uint8  Lambda_step_lean_idle;
extern const uint8  Lambda_step_lean_non_idle_map[LAMBDA_STEP_LEAN_NON_IDLE_MAP_LNS][LAMBDA_STEP_LEAN_NON_IDLE_MAP_COLS];
extern const uint8  Lambda_step_rich_idle;
extern const uint8  Lambda_step_rich_non_idle_map[LAMBDA_STEP_RICH_NON_IDLE_MAP_LNS][LAMBDA_STEP_RICH_NON_IDLE_MAP_COLS];
extern const uint8  Lbda_lean_attenuation_gain_map[LBDA_LEAN_ATTENUATION_GAIN_MAP_COLS];
extern const uint8  Lbda_lump_attenuation_gain_map[LBDA_LUMP_ATTENUATION_GAIN_MAP_LNS][LBDA_LUMP_ATTENUATION_GAIN_MAP_COLS];
extern const uint8  Lbda_lump_step_ratio;
extern const uint8  Lbda_rich_attenuation_gain_map[LBDA_RICH_ATTENUATION_GAIN_MAP_COLS];
extern const uint8  Lbda_step_attenuation_gain_map[LBDA_STEP_ATTENUATION_GAIN_MAP_LNS][LBDA_STEP_ATTENUATION_GAIN_MAP_COLS];
extern const uint8  Lbda_transitoire_eal_seuil_bas;
extern const uint8  Lbda_transitoire_eal_seuil_haut;
extern const uint8  Lbda_transitoire_reg_seuil_bas;
extern const uint8  Lbda_transitoire_reg_seuil_haut;
extern const uint8  Lffc_l_r_non_idle_delay_emis_map[LFFC_L_R_NON_IDLE_DELAY_EMIS_MAP_LNS][LFFC_L_R_NON_IDLE_DELAY_EMIS_MAP_COLS];
extern const uint8  Lffc_l_r_non_idle_delay_neuf_map[LFFC_L_R_NON_IDLE_DELAY_NEUF_MAP_LNS][LFFC_L_R_NON_IDLE_DELAY_NEUF_MAP_COLS];
extern const uint8  Lffc_lean_to_rich_idle_delay;
extern const uint8  Lffc_r_l_non_idle_delay_emis_map[LFFC_R_L_NON_IDLE_DELAY_EMIS_MAP_LNS][LFFC_R_L_NON_IDLE_DELAY_EMIS_MAP_COLS];
extern const uint8  Lffc_r_l_non_idle_delay_neuf_map[LFFC_R_L_NON_IDLE_DELAY_NEUF_MAP_LNS][LFFC_R_L_NON_IDLE_DELAY_NEUF_MAP_COLS];
extern const uint8  Lffc_rich_to_lean_idle_delay;
extern const uint8  Reg_mean_filtered_factor;
extern const uint8  Reg_range_filtered_factor;
extern const uint8  Regime_moteur_InjCtl_bkpt_map[REGIME_MOTEUR_INJCTL_BKPT_MAP_COLS];
extern const uint8  Temperature_eau_InjCtl_bkpt_map[TEMPERATURE_EAU_INJCTL_BKPT_MAP_COLS];
extern const uint8  Transfer_count_l_to_r_c;
extern const uint8  Transfer_count_r_to_l_c;
extern const uint16  Engine_load_bkpt_map[ENGINE_LOAD_BKPT_MAP_COLS];
extern const uint16  Engine_load_InjCtl_bkpt_map[ENGINE_LOAD_INJCTL_BKPT_MAP_COLS];
extern const uint16  InjCtl_rlamAdaptminThd_C;
extern const uint16  Lbda_maintien_attenu_delay_map[LBDA_MAINTIEN_ATTENU_DELAY_MAP_COLS];
extern const uint16  T_Regulation_map[T_REGULATION_MAP_LNS][T_REGULATION_MAP_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Feedback_calculations_state;
extern boolean Lambda_slow_mode;
extern uint32 Lambda_feedback_can;
extern uint8 Lambda_filtered_fdbk_mode_delay;
extern sint16 InjCtl_rlamAdapt;
extern sint16 Lambda_feedback;
extern sint16 Lambda_feedback_filtered;
extern uint16 Dnstr_modifier_time_scale;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void InjCtl_EveFbDisab_FarCtlMgr(void);
void InjCtl_EveFbEnad_FarCtlMgr(void);
void InjCtl_EveFbForSafEnad_FarCtlMgr(void);
void InjCtl_EveIniClsdLoop_FarCtlMgr(void);
void InjCtl_EveIniFbClcn_FarCtlMgr(void);
void InjCtl_EveIniFbPrm_FarCtlMgr(void);
void InjCtl_EveMonrFbCdn_FarCtlMgr(void);
void InjCtl_EveReIniFbSaf_FarCtlMgr(void);
void InjCtl_EveRst_InjFarCtlUsCtl(void);
void InjCtl_EveRstLbdFb_FarCtlMgr(void);
void InjCtl_EveRTSt_FarCtlUsCtl(void);
void InjCtl_EveTDC_FarCtlUsCtl(void);
void InjCtl_SdlFast_FarCtlUsCtl(void);


#endif /* INJFARCTLUSCTL_H */

/*-------------------------------- end of file -------------------------------*/
