/***************************************************************************
;**
;** FILE NAME      : VLVACTINSERVO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINSERVO_H
#define VLVACTINSERVO_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VTA_INTAKE_DER_GAIN_DOWN_MAP_LNS      ( 6 )
#define VTA_INTAKE_DER_GAIN_DOWN_MAP_COLS      ( 5 )
#define VTA_INTAKE_DER_GAIN_MAP_LNS           ( 6 )
#define VTA_INTAKE_DER_GAIN_MAP_COLS           ( 5 )
#define VTA_INTAKE_INT_GAIN_MAP_LNS           ( 6 )
#define VTA_INTAKE_INT_GAIN_MAP_COLS           ( 5 )
#define VTA_INTAKE_N_GAIN_BKPT_COLS            ( 6 )
#define VTA_INTAKE_PROP_GAIN_DOWN_MAP_LNS     ( 6 )
#define VTA_INTAKE_PROP_GAIN_DOWN_MAP_COLS     ( 5 )
#define VTA_INTAKE_PROP_GAIN_MAP_LNS          ( 6 )
#define VTA_INTAKE_PROP_GAIN_MAP_COLS          ( 5 )
#define VTA_INTAKE_RSTINIT_TOIL_BKPT_COLS      ( 9 )
#define VTA_INTAKE_RSTINT_MAP_COLS             ( 9 )
#define VTA_INTAKE_TOIL_GAIN_BKPT_COLS         ( 5 )

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

extern const boolean  Cbx_vvtc_pwm_bch;
extern const boolean  Vcpi_bInhReinitIntVal_C;
extern const boolean  VlvAct_bInInhNegErrDerGainClcn_C;
extern const boolean  VlvAct_bInInhNegErrPGainClcn_C;
extern const boolean  Vta_intake_band_Type;
extern const boolean  Vta_intake_der_mod;
extern const boolean  Vta_intake_Servo_Type;
extern const boolean  Vta_intake_Sp_Type_C;
extern const uint8  Kfvcpi_phi_peak_to_peak_noise;
extern const uint8  Kfvcpi_set_edge_count;
extern const uint8  Vta_intake_band_relative_C;
extern const uint8  Vta_intake_block_failure_delay;
extern const uint8  Vta_intake_int_failure_delay;
extern const sint16  VlvAct_gainInDerErrNegThd_C;
extern const sint16  VlvAct_gainInDerErrPosThd_C;
extern const sint16  VlvAct_gainInPropErrNegThd_C;
extern const sint16  VlvAct_gainInPropErrPosThd_C;
extern const uint16  Cxx_vvtc_pwm_bch;
extern const uint16  Kfvcpi_initial_current_int;
extern const uint16  Kfvcpi_initial_int_step_size;
extern const uint16  Kfvcpi_noise_learn_count;
extern const uint16  Kfvcpi_phi_maximum_cam_advance;
extern const uint16  VlvAct_agCmInPosnEstimHiLim_C;
extern const uint16  VlvAct_agCmInPosnEstimLoLim_C;
extern const uint16  VlvAct_InHiEndStopHld_C;
extern const uint16  VlvAct_InLoEndStopHld_C;
extern const uint16  Vta_intake_band;
extern const uint16  Vta_intake_band_relSp_C;
extern const uint16  Vta_intake_der_gain_down_map[VTA_INTAKE_DER_GAIN_DOWN_MAP_LNS][VTA_INTAKE_DER_GAIN_DOWN_MAP_COLS];
extern const uint16  Vta_intake_der_gain_map[VTA_INTAKE_DER_GAIN_MAP_LNS][VTA_INTAKE_DER_GAIN_MAP_COLS];
extern const uint16  Vta_intake_FacSpW_C;
extern const uint16  Vta_intake_gain_hb;
extern const uint16  Vta_intake_high_setpoint_thrust;
extern const uint16  Vta_intake_init_max_int_value;
extern const uint16  Vta_intake_int_gain_map[VTA_INTAKE_INT_GAIN_MAP_LNS][VTA_INTAKE_INT_GAIN_MAP_COLS];
extern const uint16  Vta_intake_int_inh_band;
extern const uint16  Vta_intake_low_setpoint_thrust;
extern const uint16  Vta_intake_min_reg_inh;
extern const uint16  Vta_intake_n_gain_bkpt[VTA_INTAKE_N_GAIN_BKPT_COLS];
extern const uint16  Vta_intake_prop_gain_Down_map[VTA_INTAKE_PROP_GAIN_DOWN_MAP_LNS][VTA_INTAKE_PROP_GAIN_DOWN_MAP_COLS];
extern const uint16  Vta_intake_prop_gain_map[VTA_INTAKE_PROP_GAIN_MAP_LNS][VTA_INTAKE_PROP_GAIN_MAP_COLS];
extern const uint16  Vta_intake_PropBand;
extern const uint16  Vta_intake_rstInit_toil_bkpt[VTA_INTAKE_RSTINIT_TOIL_BKPT_COLS];
extern const uint16  Vta_intake_rstInt_map[VTA_INTAKE_RSTINT_MAP_COLS];
extern const uint16  Vta_intake_SpFiltGain_C;
extern const uint16  Vta_intake_threshold_error;
extern const uint16  Vta_intake_threshold_int_max;
extern const uint16  Vta_intake_threshold_int_min;
extern const uint16  Vta_intake_toil_gain_bkpt[VTA_INTAKE_TOIL_GAIN_BKPT_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Vcpi_learning_finished;
extern boolean VlvAct_bAcvInServoWithActrTest;
extern sint16 Vcpi_cam_position_error;
extern uint16 Consigne_rco_vvt_adm;
extern uint16 Vcpi_integral_value;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveInCmToo_InServo(void);
void VlvAct_EveKOn_InServo(void);
void VlvAct_EveRst_InServo(void);
void VlvAct_SdlFast_InServo(void);


#endif /* VLVACTINSERVO_H */

/*-------------------------------- end of file -------------------------------*/
