/***************************************************************************
;**
;** FILE NAME      : VLVACTINSERVO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINSERVO_L_H
#define VLVACTINSERVO_L_H

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

extern const uint8  VLVACTINSERVO_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Vbx_pf_vvt_intake_blk;
extern boolean Vbx_pf_vvt_intake_int;
extern boolean Vcpi_bAcvClosedloop;
extern boolean Vcpi_initial_integral_is_lrnd;
extern boolean Vcpi_noise_is_learned;
extern boolean VlvActIn_bDgoIMaxVlvActIn;
extern boolean VlvActIn_bDgoServoErrVlvActIn;
extern boolean VlvActIn_bMonRunIMaxVlvActIn;
extern boolean VlvActIn_bMonRunServoErrVlvActIn;
extern boolean VLVACTINSERVO_bHysteresisOutput;
extern boolean VLVACTINSERVO_bHystOutput;
extern uint32 VLVACTINSERVO_u32FilterKMem;
extern uint8 Vcpi_edge_count;
extern uint8 Vcpi_high_peak_noise;
extern uint8 Vcpi_low_peak_noise;
extern uint8 Vcpi_noise_count;
extern uint8 Vcpi_peak_to_peak_noise;
extern uint8 Vta_intake_block_failure_tempo;
extern uint8 Vta_intake_int_failure_tempo;
extern sint16 Vcpi_cam_position_error_prev;
extern sint16 Vcpi_cam_posn_error_control;
extern sint16 Vcpi_cam_posn_error_Raw;
extern sint16 Vcpi_derivative_term;
extern sint16 Vcpi_integral_term;
extern sint16 Vcpi_proportional_term;
extern sint16 Vta_intake_speed_sp;
extern uint16 Vcpi_cam_rel_posn_error;
extern uint16 Vcpi_current_integral;
extern uint16 Vcpi_derivative_gain;
extern uint16 Vcpi_derivative_gain_down;
extern uint16 Vcpi_derivative_gain_gl;
extern uint16 Vcpi_integral_gain;
extern uint16 Vcpi_integral_val_initMem;
extern uint16 Vcpi_pid_duty_cycle;
extern uint16 Vcpi_proportional_gain;
extern uint16 VLVACTINSERVO_u16OutputFilter;
extern uint16 Vta_intake_prop_gain_Down;
extern uint16 Vta_intake_prop_gain_Up;
extern uint16 Vxx_vvtc_in_angl_sp_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINSERVO_vidCalPeakToPNoise(void);
void VLVACTINSERVO_vidControlAlgo(void);
void VLVACTINSERVO_vidDetPIDTerms(void);
void VLVACTINSERVO_vidDiagnosis(void);
void VLVACTINSERVO_vidEvalDerivTerm(void);
void VLVACTINSERVO_vidEvalIntegVal(void);
void VLVACTINSERVO_vidEvalPIDDutCycle(void);
void VLVACTINSERVO_vidEvalPropTerm(void);
void VLVACTINSERVO_vidInitFailure(void);
void VLVACTINSERVO_vidInitialize(void);
void VLVACTINSERVO_vidInitIntegral(void);
void VLVACTINSERVO_vidInitOutput(void);
void VLVACTINSERVO_vidInitRst(void);
void VLVACTINSERVO_vidLearnNoise(void);
void VLVACTINSERVO_vidSelDutyCycl(void);
void VLVACTINSERVO_vidSelectPWM(void);
void VLVACTINSERVO_vidServoError(void);
void VLVACTINSERVO_vidServoError_2(void);
void VLVACTINSERVO_vidSetpVelocity(void);
void VLVACTINSERVO_vidVcpiDiagnosis(void);


#endif /* VLVACTINSERVO_L_H */

/*-------------------------------- end of file -------------------------------*/
