/***************************************************************************
;**
;** FILE NAME      : THRSERVO.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRSERVO.H"
#include "THRSERVO_L.H"
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
const boolean  Tpac_attenuation_enab = 0;
const boolean  Tpac_current_select_bool = 0;
const boolean  Tpac_frict_strategy_enab = 0;
const boolean  Tpac_median_filter_inh = 0;
const boolean  Tpac_thr_pwm_typ_selec = 0;
const boolean  Tpac_throttle_select = 0;
const uint8  Anti_wind_up_gain = 0;
const uint8  THRSERVO_u8Inhib = 0;
const uint8  Tpac_current_estimation_gain_1 = 0;
const uint8  Tpac_current_estimation_gain_2 = 0;
const uint8  Tpac_est_vel_gain_retard = 0;
const uint8  Tpac_frict_ff_filt_gain_e1 = 0;
const uint8  Tpac_frict_ff_filt_gain_s1 = 0;
const uint8  Tpac_frict_ff_gain_dec = 0;
const uint8  Tpac_frict_ff_gain_inc = 0;
const uint8  Tpac_frict_null_spd_gain = 0;
const uint8  Tpac_frict_reset_delay = 0;
const uint8  Tpac_frict_set_delay = 0;
const uint8  Tpac_integral_gain_in = 0;
const uint8  Tpac_integral_gain_out = 0;
const uint8  Tpac_lh_area_limit_inf = 0;
const uint8  Tpac_lh_area_limit_sup = 0;
const uint8  Tpac_state_ctl_att_gain_map[TPAC_STATE_CTL_ATT_GAIN_MAP_COLS] = {0};
const sint16  Tpac_frict_pos_bkpt_map[TPAC_FRICT_POS_BKPT_MAP_COLS] = {0};
const sint16  Tpac_frict_thr_vel_thresh = 0;
const sint16  Tpac_lh_area_speed_thresh = 0;
const sint16  Tpac_state_feedback_coef_k2_in = 0;
const sint16  Tpac_state_feedback_coef_k2_out = 0;
const sint16  Tpac_thr_ctl_volt_temp_max = 0;
const sint16  Tpac_thr_ctl_volt_temp_min = 0;
const uint16  Tpac_attenuation_pos_bkpt[TPAC_ATTENUATION_POS_BKPT_COLS] = {0};
const uint16  Tpac_battery_voltage_gain_map[TPAC_BATTERY_VOLTAGE_GAIN_MAP_COLS] = {0};
const uint16  Tpac_est_vel_gain_1 = 0;
const uint16  Tpac_est_vel_gain_2 = 0;
const uint16  Tpac_est_vel_gain_3 = 0;
const uint16  Tpac_est_vel_gain_4 = 0;
const uint16  Tpac_est_vel_thresh_1 = 0;
const uint16  Tpac_est_vel_thresh_2 = 0;
const uint16  Tpac_est_vel_thresh_3 = 0;
const uint16  Tpac_est_vel_thresh_4 = 0;
const uint16  Tpac_frict_err_pos_thresh = 0;
const uint16  Tpac_frict_falling_map[TPAC_FRICT_FALLING_MAP_COLS] = {0};
const uint16  Tpac_frict_lh_area_inf = 0;
const uint16  Tpac_frict_lh_area_sup = 0;
const uint16  Tpac_frict_null_err_thresh = 0;
const uint16  Tpac_frict_null_spd_thresh = 0;
const uint16  Tpac_frict_rising_map[TPAC_FRICT_RISING_MAP_COLS] = {0};
const uint16  Tpac_ini_throttle_control_delay = 0;
const uint16  Tpac_motive_torque_per2rd = 0;
const uint16  Tpac_nul_torque_duty_cycle = 0;
const uint16  Tpac_state_feedback_coef_k1_in = 0;
const uint16  Tpac_state_feedback_coef_k1_out = 0;
const uint16  Tpac_state_feedback_coef_k3_in = 0;
const uint16  Tpac_state_feedback_coef_k3_out = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Tpac_frict_status;
uint8 Tpac_lh_etat_papillon;
boolean Thr_bCdnAcvCll;
boolean Tpac_closed_loop_enable;
boolean Tpac_frict_fal_set;
boolean Tpac_frict_fal_set_enab;
boolean Tpac_frict_reset;
boolean Tpac_frict_reset_enab;
boolean Tpac_frict_ris_set;
boolean Tpac_frict_ris_set_enab;
uint8 Tpac_est_vel_window_size;
uint8 Tpac_frict_fal_count;
uint8 Tpac_frict_reset_count;
uint8 Tpac_frict_ris_count;
uint8 Tpac_state_ctl_attenuation_gain;
uint8 Tpac_state_ctl_integral_gain;
sint16 Anti_wind_up_signal;
sint16 Thr_uCmd;
sint16 THRSERVO_s16EstVelocityPrev1;
sint16 THRSERVO_s16EstVelocityPrev2;
sint16 THRSERVO_s16FrictFFCompVoltPrev;
sint16 THRSERVO_s16TpacStCtlPosErrPrev;
sint16 Tpac_control_voltage_lin;
sint16 Tpac_dist_to_limp_home;
sint16 Tpac_estimated_current;
sint16 Tpac_frict_ff_comp_volt_filt;
sint16 Tpac_frict_ff_comp_volt_raw;
sint16 Tpac_frict_ff_comp_voltage;
sint16 Tpac_integral_output;
sint16 Tpac_non_filt_est_velocity;
sint16 Tpac_position_error;
sint16 Tpac_request_thr_jc_duty_cycle;
sint16 Tpac_state_ctl_est_velocity;
sint16 Tpac_state_ctl_ff_spring_comp;
sint16 Tpac_state_ctl_position_error;
sint16 Tpac_state_feedback_coef_k2;
sint16 Tpac_state_feedback_control;
sint16 Tpac_throttle_control_volt_temp;
sint16 Tpac_throttle_control_voltage;
uint16 THRSERVO_u16SsmRawFiltThrPosMem;
uint16 Tpac_batterry_voltage_gain;
uint16 Tpac_ini_throttle_control_tempo;
uint16 Tpac_previous_throttle_pos_1;
uint16 Tpac_previous_throttle_pos_2;
uint16 Tpac_previous_throttle_pos_3;
uint16 Tpac_previous_throttle_pos_4;
uint16 Tpac_state_feedback_coef_k1;
uint16 Tpac_state_feedback_coef_k3;
sint32 Tpac_integral_output_temp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

