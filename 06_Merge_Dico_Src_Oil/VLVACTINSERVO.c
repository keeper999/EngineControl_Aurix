/***************************************************************************
;**
;** FILE NAME      : VLVACTINSERVO.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINSERVO.H"
#include "VLVACTINSERVO_L.H"
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
const boolean  Cbx_vvtc_pwm_bch = 0;
const boolean  Vcpi_bInhReinitIntVal_C = 0;
const boolean  VlvAct_bInInhNegErrDerGainClcn_C = 0;
const boolean  VlvAct_bInInhNegErrPGainClcn_C = 0;
const boolean  Vta_intake_band_Type = 0;
const boolean  Vta_intake_der_mod = 0;
const boolean  Vta_intake_Servo_Type = 0;
const boolean  Vta_intake_Sp_Type_C = 0;
const uint8  Kfvcpi_phi_peak_to_peak_noise = 0;
const uint8  Kfvcpi_set_edge_count = 0;
const uint8  VLVACTINSERVO_u8Inhib = 0;
const uint8  Vta_intake_band_relative_C = 0;
const uint8  Vta_intake_block_failure_delay = 0;
const uint8  Vta_intake_int_failure_delay = 0;
const sint16  VlvAct_gainInDerErrNegThd_C = 0;
const sint16  VlvAct_gainInDerErrPosThd_C = 0;
const sint16  VlvAct_gainInPropErrNegThd_C = 0;
const sint16  VlvAct_gainInPropErrPosThd_C = 0;
const uint16  Cxx_vvtc_pwm_bch = 0;
const uint16  Kfvcpi_initial_current_int = 0;
const uint16  Kfvcpi_initial_int_step_size = 0;
const uint16  Kfvcpi_noise_learn_count = 0;
const uint16  Kfvcpi_phi_maximum_cam_advance = 0;
const uint16  VlvAct_agCmInPosnEstimHiLim_C = 0;
const uint16  VlvAct_agCmInPosnEstimLoLim_C = 0;
const uint16  VlvAct_InHiEndStopHld_C = 0;
const uint16  VlvAct_InLoEndStopHld_C = 0;
const uint16  Vta_intake_band = 0;
const uint16  Vta_intake_band_relSp_C = 0;
const uint16  Vta_intake_der_gain_down_map[VTA_INTAKE_DER_GAIN_DOWN_MAP_LNS][VTA_INTAKE_DER_GAIN_DOWN_MAP_COLS] = {0};
const uint16  Vta_intake_der_gain_map[VTA_INTAKE_DER_GAIN_MAP_LNS][VTA_INTAKE_DER_GAIN_MAP_COLS] = {0};
const uint16  Vta_intake_FacSpW_C = 0;
const uint16  Vta_intake_gain_hb = 0;
const uint16  Vta_intake_high_setpoint_thrust = 0;
const uint16  Vta_intake_init_max_int_value = 0;
const uint16  Vta_intake_int_gain_map[VTA_INTAKE_INT_GAIN_MAP_LNS][VTA_INTAKE_INT_GAIN_MAP_COLS] = {0};
const uint16  Vta_intake_int_inh_band = 0;
const uint16  Vta_intake_low_setpoint_thrust = 0;
const uint16  Vta_intake_min_reg_inh = 0;
const uint16  Vta_intake_n_gain_bkpt[VTA_INTAKE_N_GAIN_BKPT_COLS] = {0};
const uint16  Vta_intake_prop_gain_Down_map[VTA_INTAKE_PROP_GAIN_DOWN_MAP_LNS][VTA_INTAKE_PROP_GAIN_DOWN_MAP_COLS] = {0};
const uint16  Vta_intake_prop_gain_map[VTA_INTAKE_PROP_GAIN_MAP_LNS][VTA_INTAKE_PROP_GAIN_MAP_COLS] = {0};
const uint16  Vta_intake_PropBand = 0;
const uint16  Vta_intake_rstInit_toil_bkpt[VTA_INTAKE_RSTINIT_TOIL_BKPT_COLS] = {0};
const uint16  Vta_intake_rstInt_map[VTA_INTAKE_RSTINT_MAP_COLS] = {0};
const uint16  Vta_intake_SpFiltGain_C = 0;
const uint16  Vta_intake_threshold_error = 0;
const uint16  Vta_intake_threshold_int_max = 0;
const uint16  Vta_intake_threshold_int_min = 0;
const uint16  Vta_intake_toil_gain_bkpt[VTA_INTAKE_TOIL_GAIN_BKPT_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Vbx_pf_vvt_intake_blk;
boolean Vbx_pf_vvt_intake_int;
boolean Vcpi_bAcvClosedloop;
boolean Vcpi_initial_integral_is_lrnd;
boolean Vcpi_learning_finished;
boolean Vcpi_noise_is_learned;
boolean VlvAct_bAcvInServoWithActrTest;
boolean VlvActIn_bDgoIMaxVlvActIn;
boolean VlvActIn_bDgoServoErrVlvActIn;
boolean VlvActIn_bMonRunIMaxVlvActIn;
boolean VlvActIn_bMonRunServoErrVlvActIn;
boolean VLVACTINSERVO_bHysteresisOutput;
boolean VLVACTINSERVO_bHystOutput;
uint32 VLVACTINSERVO_u32FilterKMem;
uint8 Vcpi_edge_count;
uint8 Vcpi_high_peak_noise;
uint8 Vcpi_low_peak_noise;
uint8 Vcpi_noise_count;
uint8 Vcpi_peak_to_peak_noise;
uint8 Vta_intake_block_failure_tempo;
uint8 Vta_intake_int_failure_tempo;
sint16 Vcpi_cam_position_error;
sint16 Vcpi_cam_position_error_prev;
sint16 Vcpi_cam_posn_error_control;
sint16 Vcpi_cam_posn_error_Raw;
sint16 Vcpi_derivative_term;
sint16 Vcpi_integral_term;
sint16 Vcpi_proportional_term;
sint16 Vta_intake_speed_sp;
uint16 Consigne_rco_vvt_adm;
uint16 Vcpi_cam_rel_posn_error;
uint16 Vcpi_current_integral;
uint16 Vcpi_derivative_gain;
uint16 Vcpi_derivative_gain_down;
uint16 Vcpi_derivative_gain_gl;
uint16 Vcpi_integral_gain;
uint16 Vcpi_integral_val_initMem;
uint16 Vcpi_integral_value;
uint16 Vcpi_pid_duty_cycle;
uint16 Vcpi_proportional_gain;
uint16 VLVACTINSERVO_u16OutputFilter;
uint16 Vta_intake_prop_gain_Down;
uint16 Vta_intake_prop_gain_Up;
uint16 Vxx_vvtc_in_angl_sp_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

