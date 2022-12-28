/***************************************************************************
;**
;** FILE NAME      : VLVACTEXSERVO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXSERVO_L_H
#define VLVACTEXSERVO_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  VLVACTEXSERVO_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Vbx_pf_vvt_exhaust_blk;
extern boolean Vbx_pf_vvt_exhaust_int;
extern boolean Vcpe_bAcvClosedloop;
extern boolean Vcpe_initial_integral_is_lrnd;
extern boolean Vcpe_noise_is_learned;
extern boolean VlvActEx_bDgoIMaxVlvActEx;
extern boolean VlvActEx_bDgoServoErrVlvActEx;
extern boolean VlvActEx_bMonRunIMaxVlvActEx;
extern boolean VlvActEx_bMonRunServoErrVlvActEx;
extern boolean VLVACTEXSERVO_bHysteresisOutput;
extern boolean VLVACTEXSERVO_bHystOutput;
extern uint32 VLVACTEXSERVO_u32FilterKMem;
extern uint8 Vcpe_edge_count;
extern uint8 Vcpe_high_peak_noise;
extern uint8 Vcpe_low_peak_noise;
extern uint8 Vcpe_noise_count;
extern uint8 Vcpe_peak_to_peak_noise;
extern uint8 Vta_exhaust_block_failure_tempo;
extern uint8 Vta_exhaust_int_failure_tempo;
extern sint16 Vcpe_cam_position_error_prev;
extern sint16 Vcpe_cam_posn_error_control;
extern sint16 Vcpe_cam_posn_error_Raw;
extern sint16 Vcpe_derivative_term;
extern sint16 Vcpe_integral_term;
extern sint16 Vcpe_proportional_term;
extern sint16 Vta_exhaust_speed_sp;
extern uint16 Vcpe_cam_rel_posn_error;
extern uint16 Vcpe_current_integral;
extern uint16 Vcpe_derivative_gain;
extern uint16 Vcpe_derivative_gain_down;
extern uint16 Vcpe_derivative_gain_gl;
extern uint16 Vcpe_integral_gain;
extern uint16 Vcpe_integral_val_initMem;
extern uint16 Vcpe_pid_duty_cycle;
extern uint16 Vcpe_proportional_gain;
extern uint16 VLVACTEXSERVO_u16OutputFilter;
extern uint16 Vta_exhaust_prop_gain_Down;
extern uint16 Vta_exhaust_prop_gain_Up;
extern uint16 Vxx_vvtc_ex_angl_sp_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXSERVO_vidCalPeakToPNoise(void);
void VLVACTEXSERVO_vidControlAlgo(void);
void VLVACTEXSERVO_vidDetPIDTerms(void);
void VLVACTEXSERVO_vidDiagnosis(void);
void VLVACTEXSERVO_vidEvalDerivTerm(void);
void VLVACTEXSERVO_vidEvalIntegVal(void);
void VLVACTEXSERVO_vidEvalPIDDutCycle(void);
void VLVACTEXSERVO_vidEvalPropTerm(void);
void VLVACTEXSERVO_vidInitFailure(void);
void VLVACTEXSERVO_vidInitialize(void);
void VLVACTEXSERVO_vidInitIntegral(void);
void VLVACTEXSERVO_vidInitOutput(void);
void VLVACTEXSERVO_vidInitRst(void);
void VLVACTEXSERVO_vidLearnNoise(void);
void VLVACTEXSERVO_vidSelDutyCycl(void);
void VLVACTEXSERVO_vidSelectPWM(void);
void VLVACTEXSERVO_vidServoError(void);
void VLVACTEXSERVO_vidServoError_2(void);
void VLVACTEXSERVO_vidSetpVelocity(void);
void VLVACTEXSERVO_vidVcpeDiagnosis(void);


#endif /* VLVACTEXSERVO_L_H */

/*-------------------------------- end of file -------------------------------*/
