/***************************************************************************
;**
;** FILE NAME      : VLVACTEXSERVO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXSERVO_H
#define VLVACTEXSERVO_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VTA_EXHAUST_DER_GAIN_DOWN_MAP_LNS     ( 6 )
#define VTA_EXHAUST_DER_GAIN_DOWN_MAP_COLS     ( 5 )
#define VTA_EXHAUST_DER_GAIN_MAP_LNS          ( 6 )
#define VTA_EXHAUST_DER_GAIN_MAP_COLS          ( 5 )
#define VTA_EXHAUST_INT_GAIN_MAP_LNS          ( 6 )
#define VTA_EXHAUST_INT_GAIN_MAP_COLS          ( 5 )
#define VTA_EXHAUST_N_GAIN_BKPT_COLS           ( 6 )
#define VTA_EXHAUST_PROP_GAIN_DOWN_MAP_LNS    ( 6 )
#define VTA_EXHAUST_PROP_GAIN_DOWN_MAP_COLS    ( 5 )
#define VTA_EXHAUST_PROP_GAIN_MAP_LNS         ( 6 )
#define VTA_EXHAUST_PROP_GAIN_MAP_COLS         ( 5 )
#define VTA_EXHAUST_RSTINIT_TOIL_BKPT_COLS     ( 9 )
#define VTA_EXHAUST_RSTINT_MAP_COLS            ( 9 )
#define VTA_EXHAUST_TOIL_GAIN_BKPT_COLS        ( 5 )

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

extern const boolean  Cbx_vvtc_pwm_bch2;
extern const boolean  Vcpe_bInhReinitIntVal_C;
extern const boolean  VlvAct_bExInhNegErrDerGainClcn_C;
extern const boolean  VlvAct_bExInhNegErrPGainClcn_C;
extern const boolean  Vta_exhaust_band_Type;
extern const boolean  Vta_exhaust_der_mod;
extern const boolean  Vta_exhaust_Servo_Type;
extern const boolean  Vta_exhaust_Sp_Type_C;
extern const uint8  Kfvcpe_phi_peak_to_peak_noise;
extern const uint8  Kfvcpe_set_edge_count;
extern const uint8  Vta_exhaust_band_relative_C;
extern const uint8  Vta_exhaust_block_failure_delay;
extern const uint8  Vta_exhaust_int_failure_delay;
extern const sint16  VlvAct_gainExDerErrNegThd_C;
extern const sint16  VlvAct_gainExDerErrPosThd_C;
extern const sint16  VlvAct_gainExPropErrNegThd_C;
extern const sint16  VlvAct_gainExPropErrPosThd_C;
extern const uint16  Cxx_vvtc_pwm_bch2;
extern const uint16  Kfvcpe_initial_current_int;
extern const uint16  Kfvcpe_initial_int_step_size;
extern const uint16  Kfvcpe_noise_learn_count;
extern const uint16  Kfvcpe_phi_maximum_cam_advance;
extern const uint16  VlvAct_agCmExPosnEstimHiLim_C;
extern const uint16  VlvAct_agCmExPosnEstimLoLim_C;
extern const uint16  VlvAct_ExHiEndStopHld_C;
extern const uint16  VlvAct_ExLoEndStopHld_C;
extern const uint16  Vta_exhaust_band;
extern const uint16  Vta_exhaust_band_relSp_C;
extern const uint16  Vta_exhaust_der_gain_down_map[VTA_EXHAUST_DER_GAIN_DOWN_MAP_LNS][VTA_EXHAUST_DER_GAIN_DOWN_MAP_COLS];
extern const uint16  Vta_exhaust_der_gain_map[VTA_EXHAUST_DER_GAIN_MAP_LNS][VTA_EXHAUST_DER_GAIN_MAP_COLS];
extern const uint16  Vta_exhaust_FacSpW_C;
extern const uint16  Vta_exhaust_gain_hb;
extern const uint16  Vta_exhaust_high_setpoint_thrust;
extern const uint16  Vta_exhaust_init_max_int_value;
extern const uint16  Vta_exhaust_int_gain_map[VTA_EXHAUST_INT_GAIN_MAP_LNS][VTA_EXHAUST_INT_GAIN_MAP_COLS];
extern const uint16  Vta_exhaust_int_inh_band;
extern const uint16  Vta_exhaust_low_setpoint_thrust;
extern const uint16  Vta_exhaust_min_reg_inh;
extern const uint16  Vta_exhaust_n_gain_bkpt[VTA_EXHAUST_N_GAIN_BKPT_COLS];
extern const uint16  Vta_exhaust_prop_gain_Down_map[VTA_EXHAUST_PROP_GAIN_DOWN_MAP_LNS][VTA_EXHAUST_PROP_GAIN_DOWN_MAP_COLS];
extern const uint16  Vta_exhaust_prop_gain_map[VTA_EXHAUST_PROP_GAIN_MAP_LNS][VTA_EXHAUST_PROP_GAIN_MAP_COLS];
extern const uint16  Vta_exhaust_PropBand;
extern const uint16  Vta_exhaust_rstInit_toil_bkpt[VTA_EXHAUST_RSTINIT_TOIL_BKPT_COLS];
extern const uint16  Vta_exhaust_rstInt_map[VTA_EXHAUST_RSTINT_MAP_COLS];
extern const uint16  Vta_exhaust_SpFiltGain_C;
extern const uint16  Vta_exhaust_threshold_error;
extern const uint16  Vta_exhaust_threshold_int_max;
extern const uint16  Vta_exhaust_threshold_int_min;
extern const uint16  Vta_exhaust_toil_gain_bkpt[VTA_EXHAUST_TOIL_GAIN_BKPT_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Vcpe_learning_finished;
extern boolean VlvAct_bAcvExServoWithActrTest;
extern sint16 Vcpe_cam_position_error;
extern uint16 Consigne_rco_vvt_echap;
extern uint16 Vcpe_integral_value;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveExCmToo_ExServo(void);
void VlvAct_EveKOn_ExServo(void);
void VlvAct_EveRst_ExServo(void);
void VlvAct_SdlFast_ExServo(void);


#endif /* VLVACTEXSERVO_H */

/*-------------------------------- end of file -------------------------------*/
