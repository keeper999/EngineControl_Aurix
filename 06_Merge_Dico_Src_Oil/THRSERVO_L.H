/***************************************************************************
;**
;** FILE NAME      : THRSERVO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSERVO_L_H
#define THRSERVO_L_H

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

/* enum st04 */
#define TPAC_FRICT_FAL                    1
#define TPAC_FRICT_RIS                    2
#define TPAC_FRICT_ADHER                  4
/*extern uint8 Tpac_frict_status;*/

/* enum st42 */
#define TPAC_LH_IN                        0
#define TPAC_LH_UP                        1
#define TPAC_LH_LOW                       2
#define TPAC_LH_INIT                      8
/*extern uint8 Tpac_lh_etat_papillon;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  THRSERVO_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Tpac_frict_status;
extern uint8 Tpac_lh_etat_papillon;
extern boolean Tpac_closed_loop_enable;
extern boolean Tpac_frict_fal_set;
extern boolean Tpac_frict_fal_set_enab;
extern boolean Tpac_frict_reset;
extern boolean Tpac_frict_reset_enab;
extern boolean Tpac_frict_ris_set;
extern boolean Tpac_frict_ris_set_enab;
extern uint8 Tpac_est_vel_window_size;
extern uint8 Tpac_frict_fal_count;
extern uint8 Tpac_frict_reset_count;
extern uint8 Tpac_frict_ris_count;
extern uint8 Tpac_state_ctl_attenuation_gain;
extern uint8 Tpac_state_ctl_integral_gain;
extern sint16 Anti_wind_up_signal;
extern sint16 THRSERVO_s16EstVelocityPrev1;
extern sint16 THRSERVO_s16EstVelocityPrev2;
extern sint16 THRSERVO_s16FrictFFCompVoltPrev;
extern sint16 THRSERVO_s16TpacStCtlPosErrPrev;
extern sint16 Tpac_control_voltage_lin;
extern sint16 Tpac_dist_to_limp_home;
extern sint16 Tpac_estimated_current;
extern sint16 Tpac_frict_ff_comp_volt_filt;
extern sint16 Tpac_frict_ff_comp_volt_raw;
extern sint16 Tpac_frict_ff_comp_voltage;
extern sint16 Tpac_non_filt_est_velocity;
extern sint16 Tpac_state_ctl_est_velocity;
extern sint16 Tpac_state_ctl_ff_spring_comp;
extern sint16 Tpac_state_feedback_coef_k2;
extern sint16 Tpac_state_feedback_control;
extern sint16 Tpac_throttle_control_voltage;
extern uint16 THRSERVO_u16SsmRawFiltThrPosMem;
extern uint16 Tpac_batterry_voltage_gain;
extern uint16 Tpac_ini_throttle_control_tempo;
extern uint16 Tpac_previous_throttle_pos_1;
extern uint16 Tpac_previous_throttle_pos_2;
extern uint16 Tpac_previous_throttle_pos_3;
extern uint16 Tpac_previous_throttle_pos_4;
extern uint16 Tpac_state_feedback_coef_k1;
extern uint16 Tpac_state_feedback_coef_k3;
extern sint32 Tpac_integral_output_temp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRSERVO_vidAdjustVelocity(void);
void THRSERVO_vidBatteryVoltageGain(void);
void THRSERVO_vidCompGloblAttenuation(void);
void THRSERVO_vidCompStateFeedbackCtl(void);
void THRSERVO_vidComputeCtrlVoltage(void);
void THRSERVO_vidComputeCtrlVoltLin(void);
void THRSERVO_vidComputeCurrent(void);
void THRSERVO_vidComputeCurrentCall(void);
void THRSERVO_vidComputeFeedForward(void);
void THRSERVO_vidComputeFrictCompens(void);
void THRSERVO_vidComputeInitTasks(void);
void THRSERVO_vidComputeInnerLoop(void);
void THRSERVO_vidComputeIntegrOutput(void);
void THRSERVO_vidComputeOutterLoop(void);
void THRSERVO_vidComputePhysicalState(void);
void THRSERVO_vidComputePositionError(void);
void THRSERVO_vidComputeVelocity(void);
void THRSERVO_vidControlSwitchMode(void);
void THRSERVO_vidDecTempo(void);
void THRSERVO_vidFiltCompensFeedBack(void);
void THRSERVO_vidFiltering(void);
void THRSERVO_vidFrictConstCounter(void);
void THRSERVO_vidFrictionCompensation(void);
void THRSERVO_vidFrictionDetection(void);
void THRSERVO_vidInitControlVariables(void);
void THRSERVO_vidInitOutput(void);
void THRSERVO_vidInitTempo(void);
void THRSERVO_vidIntegInitOnSetGainIO(void);
void THRSERVO_vidManageLimpHome(void);
void THRSERVO_vidManagerThrottleState(void);
void THRSERVO_vidMedianFilter(void);
void THRSERVO_vidSetControlGainsIn(void);
void THRSERVO_vidSetControlGainsOut(void);
void THRSERVO_vidSetFrictStatus(void);
void THRSERVO_vidSetWindowSize(void);
void THRSERVO_vidUpdatePositionValues(void);
void THRSERVO_vidVelocityWindow1(void);
void THRSERVO_vidVelocityWindow2(void);
void THRSERVO_vidVelocityWindow3(void);
void THRSERVO_vidVelocityWindow4(void);


#endif /* THRSERVO_L_H */

/*-------------------------------- end of file -------------------------------*/
