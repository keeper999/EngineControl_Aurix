/***************************************************************************
;**
;** FILE NAME      : INJFARCTLUSCTL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJFARCTLUSCTL.H"
#include "INJFARCTLUSCTL_L.H"
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
const boolean  Feedback_saf_inh_diag_req_C = 0;
const boolean  Lbda_att_always_manu_inh = 0;
const boolean  Lbda_att_idle_manu_inh = 0;
const boolean  Lbda_att_transient_manu_inh = 0;
const boolean  Manu_inh_clamp_lambda_feedback = 0;
const boolean  Manu_inh_Delta_PMH_gaz = 0;
const boolean  Test_bed_transfer_count_l_to_r = 0;
const boolean  Test_bed_transfer_count_r_to_l = 0;
const uint8  Fast_tracking_water_temp_thresh = 0;
const uint8  InjCtl_facFillamAdapt_C = 0;
const uint8  InjCtl_tiDlyClcrlamAdapt_C = 0;
const uint8  INJFARCTLUSCTL_u8Inhib = 0;
const uint8  Lambda_fdbk_filter_fast_gain = 0;
const uint8  Lambda_fdbk_filter_slow_gain = 0;
const uint8  Lambda_filt_fdbk_mode_delay_idle = 0;
const uint8  Lambda_filt_fdbk_mode_delay_map[LAMBDA_FILT_FDBK_MODE_DELAY_MAP_COLS] = {0};
const uint8  Lambda_for_saf_diag_lump_lean = 0;
const uint8  Lambda_for_saf_diag_lump_rich = 0;
const uint8  Lambda_for_saf_diag_step_lean = 0;
const uint8  Lambda_for_saf_diag_step_rich = 0;
const uint8  Lambda_l_step_lean_non_idle_map[LAMBDA_L_STEP_LEAN_NON_IDLE_MAP_COLS] = {0};
const uint8  Lambda_l_step_rich_non_idle_map[LAMBDA_L_STEP_RICH_NON_IDLE_MAP_COLS] = {0};
const uint8  Lambda_large_lump_lean_idle = 0;
const uint8  Lambda_large_lump_non_idle_map[LAMBDA_LARGE_LUMP_NON_IDLE_MAP_COLS] = {0};
const uint8  Lambda_large_lump_rich_idle = 0;
const uint8  Lambda_large_step_lean_idle = 0;
const uint8  Lambda_large_step_rich_idle = 0;
const uint8  Lambda_lump_lean_idle = 0;
const uint8  Lambda_lump_lean_non_idle_map[LAMBDA_LUMP_LEAN_NON_IDLE_MAP_LNS][LAMBDA_LUMP_LEAN_NON_IDLE_MAP_COLS] = {0};
const uint8  Lambda_lump_rich_idle = 0;
const uint8  Lambda_lump_rich_non_idle_map[LAMBDA_LUMP_RICH_NON_IDLE_MAP_LNS][LAMBDA_LUMP_RICH_NON_IDLE_MAP_COLS] = {0};
const uint8  Lambda_slow_mode_delay_idle = 0;
const uint8  Lambda_slow_mode_delay_map[LAMBDA_SLOW_MODE_DELAY_MAP_COLS] = {0};
const uint8  Lambda_step_lean_idle = 0;
const uint8  Lambda_step_lean_non_idle_map[LAMBDA_STEP_LEAN_NON_IDLE_MAP_LNS][LAMBDA_STEP_LEAN_NON_IDLE_MAP_COLS] = {0};
const uint8  Lambda_step_rich_idle = 0;
const uint8  Lambda_step_rich_non_idle_map[LAMBDA_STEP_RICH_NON_IDLE_MAP_LNS][LAMBDA_STEP_RICH_NON_IDLE_MAP_COLS] = {0};
const uint8  Lbda_lean_attenuation_gain_map[LBDA_LEAN_ATTENUATION_GAIN_MAP_COLS] = {0};
const uint8  Lbda_lump_attenuation_gain_map[LBDA_LUMP_ATTENUATION_GAIN_MAP_LNS][LBDA_LUMP_ATTENUATION_GAIN_MAP_COLS] = {0};
const uint8  Lbda_lump_step_ratio = 0;
const uint8  Lbda_rich_attenuation_gain_map[LBDA_RICH_ATTENUATION_GAIN_MAP_COLS] = {0};
const uint8  Lbda_step_attenuation_gain_map[LBDA_STEP_ATTENUATION_GAIN_MAP_LNS][LBDA_STEP_ATTENUATION_GAIN_MAP_COLS] = {0};
const uint8  Lbda_transitoire_eal_seuil_bas = 0;
const uint8  Lbda_transitoire_eal_seuil_haut = 0;
const uint8  Lbda_transitoire_reg_seuil_bas = 0;
const uint8  Lbda_transitoire_reg_seuil_haut = 0;
const uint8  Lffc_l_r_non_idle_delay_emis_map[LFFC_L_R_NON_IDLE_DELAY_EMIS_MAP_LNS][LFFC_L_R_NON_IDLE_DELAY_EMIS_MAP_COLS] = {0};
const uint8  Lffc_l_r_non_idle_delay_neuf_map[LFFC_L_R_NON_IDLE_DELAY_NEUF_MAP_LNS][LFFC_L_R_NON_IDLE_DELAY_NEUF_MAP_COLS] = {0};
const uint8  Lffc_lean_to_rich_idle_delay = 0;
const uint8  Lffc_r_l_non_idle_delay_emis_map[LFFC_R_L_NON_IDLE_DELAY_EMIS_MAP_LNS][LFFC_R_L_NON_IDLE_DELAY_EMIS_MAP_COLS] = {0};
const uint8  Lffc_r_l_non_idle_delay_neuf_map[LFFC_R_L_NON_IDLE_DELAY_NEUF_MAP_LNS][LFFC_R_L_NON_IDLE_DELAY_NEUF_MAP_COLS] = {0};
const uint8  Lffc_rich_to_lean_idle_delay = 0;
const uint8  Reg_mean_filtered_factor = 0;
const uint8  Reg_range_filtered_factor = 0;
const uint8  Regime_moteur_InjCtl_bkpt_map[REGIME_MOTEUR_INJCTL_BKPT_MAP_COLS] = {0};
const uint8  Temperature_eau_InjCtl_bkpt_map[TEMPERATURE_EAU_INJCTL_BKPT_MAP_COLS] = {0};
const uint8  Transfer_count_l_to_r_c = 0;
const uint8  Transfer_count_r_to_l_c = 0;
const uint16  Engine_load_bkpt_map[ENGINE_LOAD_BKPT_MAP_COLS] = {0};
const uint16  Engine_load_InjCtl_bkpt_map[ENGINE_LOAD_INJCTL_BKPT_MAP_COLS] = {0};
const uint16  InjCtl_rlamAdaptminThd_C = 0;
const uint16  Lbda_maintien_attenu_delay_map[LBDA_MAINTIEN_ATTENU_DELAY_MAP_COLS] = {0};
const uint16  T_Regulation_map[T_REGULATION_MAP_LNS][T_REGULATION_MAP_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Feedback_calculations_state;
uint8 Feedback_saf_diag_calc_state;
boolean Fast_traking_ok;
boolean InjCtl_bUpdlamMax;
boolean InjCtl_bUpdlamMin;
boolean INJFARCTLUSCTL_bECUReset;
boolean INJFARCTLUSCTL_bLocalDetinitprev;
boolean INJFARCTLUSCTL_bMnRnORgItrPrev;
boolean INJFARCTLUSCTL_bMnRnORngIntrPrev;
boolean INJFARCTLUSCTL_bRlamAdpReqPrev;
boolean Lambda_feedback_max_calc;
boolean Lambda_feedback_min_calc;
boolean Lambda_slow_mode;
boolean Lambda_waiting;
boolean Lbda_active_gain_attenu_rich;
boolean Lbda_attenuation_condition;
boolean Lbda_transitoire_detect;
boolean Lbda_transitoire_detectPrev;
uint32 INJFARCTLUSCTL_u32AregulFiltMem;
uint32 Lambda_feedback_can;
sint8 Engine_air_load_derivate;
uint8 Delta_PMH_gaz;
uint8 Dnstr_modifier_sampled;
uint8 InjCtl_tiDlyClcrlamAdapt;
uint8 Lambda_filtered_fdbk_mode_delay;
uint8 Lambda_slow_mode_delay;
uint8 Lbda_lump_lean_gain;
uint8 Lbda_lump_rich_gain;
uint8 Lbda_step_lean_gain;
uint8 Lbda_step_rich_gain;
uint8 Transfer_count;
sint16 InjCtl_rlamAdapt;
sint16 InjCtl_rlamAdaptIntery;
sint16 InjCtl_rlamAdaptMv;
sint16 INJFARCTLUSCTL_s16LamFeedCanFilt;
sint16 Lambda_feedback;
sint16 Lambda_feedback_filtered;
sint16 Lambda_feedback_max;
sint16 Lambda_feedback_mean;
sint16 Lambda_feedback_min;
sint16 Lambda_feedback_previous;
sint16 Moyenne_Lambda_feedback;
uint16 Aregulation;
uint16 Aregulation_filt;
uint16 Dnstr_modifier_time_scale;
uint16 Lambda_feedback_delta;
uint16 Lambda_feedback_lump;
uint16 Lambda_feedback_step;
uint16 Lbda_engine_air_load_prev;
uint16 Lbda_maintien_attenuation_count;
uint16 T_Regulation;
sint32 INJFARCTLUSCTL_s32lamAdaptIntMem;
sint32 INJFARCTLUSCTL_s32LamFeedCanMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

