/***************************************************************************
;**
;** FILE NAME      : THRSERVO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSERVO_H
#define THRSERVO_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TPAC_ATTENUATION_POS_BKPT_COLS         ( 6 )
#define TPAC_BATTERY_VOLTAGE_GAIN_MAP_COLS     ( 9 )
#define TPAC_FRICT_FALLING_MAP_COLS            ( 6 )
#define TPAC_FRICT_POS_BKPT_MAP_COLS           ( 6 )
#define TPAC_FRICT_RISING_MAP_COLS             ( 6 )
#define TPAC_STATE_CTL_ATT_GAIN_MAP_COLS       ( 6 )

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

extern const boolean  Tpac_attenuation_enab;
extern const boolean  Tpac_current_select_bool;
extern const boolean  Tpac_frict_strategy_enab;
extern const boolean  Tpac_median_filter_inh;
extern const boolean  Tpac_thr_pwm_typ_selec;
extern const boolean  Tpac_throttle_select;
extern const uint8  Anti_wind_up_gain;
extern const uint8  Tpac_current_estimation_gain_1;
extern const uint8  Tpac_current_estimation_gain_2;
extern const uint8  Tpac_est_vel_gain_retard;
extern const uint8  Tpac_frict_ff_filt_gain_e1;
extern const uint8  Tpac_frict_ff_filt_gain_s1;
extern const uint8  Tpac_frict_ff_gain_dec;
extern const uint8  Tpac_frict_ff_gain_inc;
extern const uint8  Tpac_frict_null_spd_gain;
extern const uint8  Tpac_frict_reset_delay;
extern const uint8  Tpac_frict_set_delay;
extern const uint8  Tpac_integral_gain_in;
extern const uint8  Tpac_integral_gain_out;
extern const uint8  Tpac_lh_area_limit_inf;
extern const uint8  Tpac_lh_area_limit_sup;
extern const uint8  Tpac_state_ctl_att_gain_map[TPAC_STATE_CTL_ATT_GAIN_MAP_COLS];
extern const sint16  Tpac_frict_pos_bkpt_map[TPAC_FRICT_POS_BKPT_MAP_COLS];
extern const sint16  Tpac_frict_thr_vel_thresh;
extern const sint16  Tpac_lh_area_speed_thresh;
extern const sint16  Tpac_state_feedback_coef_k2_in;
extern const sint16  Tpac_state_feedback_coef_k2_out;
extern const sint16  Tpac_thr_ctl_volt_temp_max;
extern const sint16  Tpac_thr_ctl_volt_temp_min;
extern const uint16  Tpac_attenuation_pos_bkpt[TPAC_ATTENUATION_POS_BKPT_COLS];
extern const uint16  Tpac_battery_voltage_gain_map[TPAC_BATTERY_VOLTAGE_GAIN_MAP_COLS];
extern const uint16  Tpac_est_vel_gain_1;
extern const uint16  Tpac_est_vel_gain_2;
extern const uint16  Tpac_est_vel_gain_3;
extern const uint16  Tpac_est_vel_gain_4;
extern const uint16  Tpac_est_vel_thresh_1;
extern const uint16  Tpac_est_vel_thresh_2;
extern const uint16  Tpac_est_vel_thresh_3;
extern const uint16  Tpac_est_vel_thresh_4;
extern const uint16  Tpac_frict_err_pos_thresh;
extern const uint16  Tpac_frict_falling_map[TPAC_FRICT_FALLING_MAP_COLS];
extern const uint16  Tpac_frict_lh_area_inf;
extern const uint16  Tpac_frict_lh_area_sup;
extern const uint16  Tpac_frict_null_err_thresh;
extern const uint16  Tpac_frict_null_spd_thresh;
extern const uint16  Tpac_frict_rising_map[TPAC_FRICT_RISING_MAP_COLS];
extern const uint16  Tpac_ini_throttle_control_delay;
extern const uint16  Tpac_motive_torque_per2rd;
extern const uint16  Tpac_nul_torque_duty_cycle;
extern const uint16  Tpac_state_feedback_coef_k1_in;
extern const uint16  Tpac_state_feedback_coef_k1_out;
extern const uint16  Tpac_state_feedback_coef_k3_in;
extern const uint16  Tpac_state_feedback_coef_k3_out;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bCdnAcvCll;
extern sint16 Thr_uCmd;
extern sint16 Tpac_integral_output;
extern sint16 Tpac_position_error;
extern sint16 Tpac_request_thr_jc_duty_cycle;
extern sint16 Tpac_state_ctl_position_error;
extern sint16 Tpac_throttle_control_volt_temp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveClcnServo_Servo(void);
void Thr_EveRst_Servo(void);
void Thr_SdlMid_Servo(void);


#endif /* THRSERVO_H */

/*-------------------------------- end of file -------------------------------*/
