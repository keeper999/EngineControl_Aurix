/***************************************************************************
;**
;** FILE NAME      : VLVACTEXSERVO.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXSERVO.H"
#include "VLVACTEXSERVO_L.H"
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
const boolean  Cbx_vvtc_pwm_bch2 = 0;
const boolean  Vcpe_bInhReinitIntVal_C = 0;
const boolean  VlvAct_bExInhNegErrDerGainClcn_C = 0;
const boolean  VlvAct_bExInhNegErrPGainClcn_C = 0;
const boolean  Vta_exhaust_band_Type = 0;
const boolean  Vta_exhaust_der_mod = 0;
const boolean  Vta_exhaust_Servo_Type = 0;
const boolean  Vta_exhaust_Sp_Type_C = 0;
const uint8  Kfvcpe_phi_peak_to_peak_noise = 0;
const uint8  Kfvcpe_set_edge_count = 0;
const uint8  VLVACTEXSERVO_u8Inhib = 0;
const uint8  Vta_exhaust_band_relative_C = 0;
const uint8  Vta_exhaust_block_failure_delay = 0;
const uint8  Vta_exhaust_int_failure_delay = 0;
const sint16  VlvAct_gainExDerErrNegThd_C = 0;
const sint16  VlvAct_gainExDerErrPosThd_C = 0;
const sint16  VlvAct_gainExPropErrNegThd_C = 0;
const sint16  VlvAct_gainExPropErrPosThd_C = 0;
const uint16  Cxx_vvtc_pwm_bch2 = 0;
const uint16  Kfvcpe_initial_current_int = 0;
const uint16  Kfvcpe_initial_int_step_size = 0;
const uint16  Kfvcpe_noise_learn_count = 0;
const uint16  Kfvcpe_phi_maximum_cam_advance = 0;
const uint16  VlvAct_agCmExPosnEstimHiLim_C = 0;
const uint16  VlvAct_agCmExPosnEstimLoLim_C = 0;
const uint16  VlvAct_ExHiEndStopHld_C = 0;
const uint16  VlvAct_ExLoEndStopHld_C = 0;
const uint16  Vta_exhaust_band = 0;
const uint16  Vta_exhaust_band_relSp_C = 0;
const uint16  Vta_exhaust_der_gain_down_map[VTA_EXHAUST_DER_GAIN_DOWN_MAP_LNS][VTA_EXHAUST_DER_GAIN_DOWN_MAP_COLS] = {0};
const uint16  Vta_exhaust_der_gain_map[VTA_EXHAUST_DER_GAIN_MAP_LNS][VTA_EXHAUST_DER_GAIN_MAP_COLS] = {0};
const uint16  Vta_exhaust_FacSpW_C = 0;
const uint16  Vta_exhaust_gain_hb = 0;
const uint16  Vta_exhaust_high_setpoint_thrust = 0;
const uint16  Vta_exhaust_init_max_int_value = 0;
const uint16  Vta_exhaust_int_gain_map[VTA_EXHAUST_INT_GAIN_MAP_LNS][VTA_EXHAUST_INT_GAIN_MAP_COLS] = {0};
const uint16  Vta_exhaust_int_inh_band = 0;
const uint16  Vta_exhaust_low_setpoint_thrust = 0;
const uint16  Vta_exhaust_min_reg_inh = 0;
const uint16  Vta_exhaust_n_gain_bkpt[VTA_EXHAUST_N_GAIN_BKPT_COLS] = {0};
const uint16  Vta_exhaust_prop_gain_Down_map[VTA_EXHAUST_PROP_GAIN_DOWN_MAP_LNS][VTA_EXHAUST_PROP_GAIN_DOWN_MAP_COLS] = {0};
const uint16  Vta_exhaust_prop_gain_map[VTA_EXHAUST_PROP_GAIN_MAP_LNS][VTA_EXHAUST_PROP_GAIN_MAP_COLS] = {0};
const uint16  Vta_exhaust_PropBand = 0;
const uint16  Vta_exhaust_rstInit_toil_bkpt[VTA_EXHAUST_RSTINIT_TOIL_BKPT_COLS] = {0};
const uint16  Vta_exhaust_rstInt_map[VTA_EXHAUST_RSTINT_MAP_COLS] = {0};
const uint16  Vta_exhaust_SpFiltGain_C = 0;
const uint16  Vta_exhaust_threshold_error = 0;
const uint16  Vta_exhaust_threshold_int_max = 0;
const uint16  Vta_exhaust_threshold_int_min = 0;
const uint16  Vta_exhaust_toil_gain_bkpt[VTA_EXHAUST_TOIL_GAIN_BKPT_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Vbx_pf_vvt_exhaust_blk;
boolean Vbx_pf_vvt_exhaust_int;
boolean Vcpe_bAcvClosedloop;
boolean Vcpe_initial_integral_is_lrnd;
boolean Vcpe_learning_finished;
boolean Vcpe_noise_is_learned;
boolean VlvAct_bAcvExServoWithActrTest;
boolean VlvActEx_bDgoIMaxVlvActEx;
boolean VlvActEx_bDgoServoErrVlvActEx;
boolean VlvActEx_bMonRunIMaxVlvActEx;
boolean VlvActEx_bMonRunServoErrVlvActEx;
boolean VLVACTEXSERVO_bHysteresisOutput;
boolean VLVACTEXSERVO_bHystOutput;
uint32 VLVACTEXSERVO_u32FilterKMem;
uint8 Vcpe_edge_count;
uint8 Vcpe_high_peak_noise;
uint8 Vcpe_low_peak_noise;
uint8 Vcpe_noise_count;
uint8 Vcpe_peak_to_peak_noise;
uint8 Vta_exhaust_block_failure_tempo;
uint8 Vta_exhaust_int_failure_tempo;
sint16 Vcpe_cam_position_error;
sint16 Vcpe_cam_position_error_prev;
sint16 Vcpe_cam_posn_error_control;
sint16 Vcpe_cam_posn_error_Raw;
sint16 Vcpe_derivative_term;
sint16 Vcpe_integral_term;
sint16 Vcpe_proportional_term;
sint16 Vta_exhaust_speed_sp;
uint16 Consigne_rco_vvt_echap;
uint16 Vcpe_cam_rel_posn_error;
uint16 Vcpe_current_integral;
uint16 Vcpe_derivative_gain;
uint16 Vcpe_derivative_gain_down;
uint16 Vcpe_derivative_gain_gl;
uint16 Vcpe_integral_gain;
uint16 Vcpe_integral_val_initMem;
uint16 Vcpe_integral_value;
uint16 Vcpe_pid_duty_cycle;
uint16 Vcpe_proportional_gain;
uint16 VLVACTEXSERVO_u16OutputFilter;
uint16 Vta_exhaust_prop_gain_Down;
uint16 Vta_exhaust_prop_gain_Up;
uint16 Vxx_vvtc_ex_angl_sp_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

