/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSERVO                                                */
/* !Description     : THRSERVO component.                                     */
/*                                                                            */
/* !Module          : THRSERVO                                                */
/* !Description     : ASSERVISSEMENT PAR RETOUR D’ETAT DE LA POSITION DU      */
/*                    PAPILLON MOTORISE                                       */
/*                                                                            */
/* !File            : THRSERVO_FCT3.C                                         */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / THRSERVO_vidComputeOutterLoop                                        */
/*   2 / THRSERVO_vidComputeIntegrOutput                                      */
/*   3 / THRSERVO_vidComputeCtrlVoltLin                                       */
/*   4 / THRSERVO_vidComputeFeedForward                                       */
/*   5 / THRSERVO_vidCompGloblAttenuation                                     */
/*   6 / THRSERVO_vidComputeCtrlVoltage                                       */
/*   7 / THRSERVO_vidControlSwitchMode                                        */
/*   8 / THRSERVO_vidComputePositionError                                     */
/*   9 / THRSERVO_vidBatteryVoltageGain                                       */
/*                                                                            */
/* !Reference   : V02 NT 08 04514 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRSERVO/THRSERVO_FCT3.C_v    $*/
/* $Revision::   1.6      $$Author::   acabresp       $$Date::   02 Jun 2010 $*/
/* $Author::   acabresp                               $$Date::   02 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "THRSERVO.h"
#include "THRSERVO_L.h"
#include "THRSERVO_IM.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeOutterLoop                              */
/* !Description :  Ce sous-système spécifie le traitement de la boucle externe*/
/*                 de la stratégie                                            */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidComputePositionError();                      */
/*  extf argret void THRSERVO_vidComputeIntegrOutput();                       */
/*  extf argret void THRSERVO_vidComputeCtrlVoltLin();                        */
/*  extf argret void THRSERVO_vidComputeFeedForward();                        */
/*  extf argret void THRSERVO_vidCompGloblAttenuation();                      */
/*  extf argret void THRSERVO_vidComputeCtrlVoltage();                        */
/*  extf argret void THRSERVO_vidControlSwitchMode();                         */
/*  extf argret void THRSERVO_vidManageLimpHome();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeOutterLoop(void)
{
   /* Compute_outter_loop */
   THRSERVO_vidComputePositionError();
   THRSERVO_vidComputeIntegrOutput();
   THRSERVO_vidComputeCtrlVoltLin();
   THRSERVO_vidComputeFeedForward();
   THRSERVO_vidCompGloblAttenuation();
   THRSERVO_vidComputeCtrlVoltage();
   THRSERVO_vidControlSwitchMode();
   THRSERVO_vidManageLimpHome();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeIntegrOutput                            */
/* !Description :  Ce sous-système produit la valeur du terme intégral de la  */
/*                 stratégie de contrôle par retour d’état                    */
/*                 (Tpac_integral_output).                                    */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tpac_open_loop_control;                                     */
/*  input sint16 Tpac_state_ctl_position_error;                               */
/*  input sint16 THRSERVO_s16TpacStCtlPosErrPrev;                             */
/*  input uint8 Tpac_state_ctl_integral_gain;                                 */
/*  input sint32 Tpac_integral_output_temp;                                   */
/*  input sint16 Tpac_state_feedback_control;                                 */
/*  output boolean Tpac_closed_loop_enable;                                   */
/*  output sint32 Tpac_integral_output_temp;                                  */
/*  output sint16 Tpac_integral_output;                                       */
/*  output sint16 Tpac_state_feedback_control;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeIntegrOutput(void)
{
   /* Compute_integral_output */
   boolean blocalTpac_open_loop_control;
   uint16  u16LocalGain;
   sint16  s16LocalTpac_stat_ctl_pos_err;
   sint16  s16LocalTpac_integral_output;
   uint32  u32LocalIntegralOutput;
   uint32  u32LocalOutputTemp;
   uint32  u32LocalAbs;
   sint32  s32LocalIntegralOutput;
   sint32  s32LocalOutput_temp;
   sint32  s32LocalTpac_integral_output;
   sint32  s32LocalTpacIntOutputTemp;


   VEMS_vidGET(Tpac_open_loop_control, blocalTpac_open_loop_control);
   if (blocalTpac_open_loop_control == 0)
   {
      Tpac_closed_loop_enable = 1;
      VEMS_vidGET(Tpac_state_ctl_position_error, s16LocalTpac_stat_ctl_pos_err);
      s32LocalIntegralOutput = (sint32)( s16LocalTpac_stat_ctl_pos_err
                                       + THRSERVO_s16TpacStCtlPosErrPrev);

      u16LocalGain = (uint16)(Tpac_state_ctl_integral_gain * 25);
      s32LocalIntegralOutput = s32LocalIntegralOutput * u16LocalGain;

      if (s32LocalIntegralOutput > 0)
      {
         if (Tpac_integral_output_temp > 0)
         {
            u32LocalOutputTemp = (uint32)( s32LocalIntegralOutput
                                         + Tpac_integral_output_temp);
            Tpac_integral_output_temp =
               (sint32)MATHSRV_udtMIN(u32LocalOutputTemp, 67107840);
         }
         else
         {
            s32LocalOutput_temp = (s32LocalIntegralOutput
                                  + Tpac_integral_output_temp);
            Tpac_integral_output_temp = MATHSRV_udtCLAMP(s32LocalOutput_temp,
                                                         -67107840,
                                                         67107840);
         }
      }
      else
      {
         if (Tpac_integral_output_temp > 0)
         {
            s32LocalOutput_temp = ( s32LocalIntegralOutput
                                  + Tpac_integral_output_temp);
            Tpac_integral_output_temp = MATHSRV_udtCLAMP(s32LocalOutput_temp,
                                                         -67107840,
                                                         67107840);
         }
         else
         {
            u32LocalIntegralOutput =
               (uint32)MATHSRV_udtABS(s32LocalIntegralOutput);
            u32LocalAbs = (uint32)MATHSRV_udtABS(Tpac_integral_output_temp);
            u32LocalOutputTemp = u32LocalIntegralOutput + u32LocalAbs;
            s32LocalOutput_temp = (sint32)MATHSRV_udtMIN(u32LocalOutputTemp,
                                                         67107840);
            Tpac_integral_output_temp = -s32LocalOutput_temp;
         }
      }

      if (Tpac_integral_output_temp >= 0)
      {
         s32LocalTpac_integral_output = ( (Tpac_integral_output_temp + 1024)
                                        / 2048);
         s16LocalTpac_integral_output =
            (sint16)MATHSRV_udtMIN(s32LocalTpac_integral_output, 32767);
      }
      else
      {
         s16LocalTpac_integral_output =
            (sint16)((Tpac_integral_output_temp - 1024) / 2048);
      }
      VEMS_vidSET(Tpac_integral_output, s16LocalTpac_integral_output);
   }
   else
   {
      Tpac_closed_loop_enable = 0;
      VEMS_vidSET(Tpac_integral_output, Tpac_state_feedback_control);
      s32LocalTpacIntOutputTemp = Tpac_state_feedback_control * 2048;
      Tpac_integral_output_temp = MATHSRV_udtMAX(s32LocalTpacIntOutputTemp,
                                                 -67107840);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeCtrlVoltLin                             */
/* !Description :  Ce sous-système spécifie le calcul de la partie linéaire de*/
/*                 la commande (Tpac_control_voltage_lin) qui  correspond à la*/
/*                 différence entre le terme intégral (Tpac_integral_output)  */
/*                 et le retour d’état (Tpac_state_feedback_control).         */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Tpac_integral_output;                                        */
/*  input sint16 Tpac_state_feedback_control;                                 */
/*  output sint16 Tpac_control_voltage_lin;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeCtrlVoltLin(void)
{
   /* Compute_control_voltage_lin */
   sint16 s16LocalTpac_integrl_out;
   sint32 s32LocalTpac_control;

   VEMS_vidGET(Tpac_integral_output, s16LocalTpac_integrl_out);
   s32LocalTpac_control = (sint32)( s16LocalTpac_integrl_out
                                  - Tpac_state_feedback_control);
   Tpac_control_voltage_lin =
            (sint16)MATHSRV_udtCLAMP( s32LocalTpac_control,
                                      SINT16_MIN,
                                      SINT16_MAX );
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeFeedForward                             */
/* !Description :  Ce module décrit l'activation ou la désactivation de la    */
/*                 stratégie de compensation des  frottements secs.           */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidFrictionCompensation();                      */
/*  input boolean Tpac_frict_strategy_enab;                                   */
/*  input sint16 Tpac_frict_ff_comp_volt_filt;                                */
/*  output sint16 Tpac_state_ctl_ff_spring_comp;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeFeedForward(void)
{
   /* Compute_feed_forward */
   if (Tpac_frict_strategy_enab != 0)
   {
      THRSERVO_vidFrictionCompensation();
      Tpac_state_ctl_ff_spring_comp = Tpac_frict_ff_comp_volt_filt;
   }
   else
   {
      /* Absence de la strategie de detection de frottements secs */
      Tpac_state_ctl_ff_spring_comp = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidCompGloblAttenuation                           */
/* !Description :  Calcul du gain d'atténuation autour de la position limp    */
/*                 home.                                                      */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Tpac_attenuation_enab;                                      */
/*  input uint16 Dtc_throttle_position_reference;                             */
/*  input uint16 Tpac_attenuation_pos_bkpt[6];                                */
/*  input uint8 Tpac_state_ctl_att_gain_map[6];                               */
/*  output uint8 Tpac_state_ctl_attenuation_gain;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidCompGloblAttenuation(void)
{
   /* Compute_global_attenuation */
   uint16 u16LocalDtc_thr_pos_ref;
   uint16 u16LocalPara;


   if (Tpac_attenuation_enab != 0)
   {
      VEMS_vidGET(Dtc_throttle_position_reference, u16LocalDtc_thr_pos_ref);
      u16LocalPara =
         MATHSRV_u16CalcParaIncAryU16Loc(Tpac_attenuation_pos_bkpt,
                                         u16LocalDtc_thr_pos_ref,
                                         5);
      Tpac_state_ctl_attenuation_gain =
         MATHSRV_u8Interp1d(Tpac_state_ctl_att_gain_map, u16LocalPara);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeCtrlVoltage                             */
/* !Description :  Calcul de la commande de l'actionneur PAPMOT.              */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Tpac_closed_loop_enable;                                    */
/*  input boolean Tpac_attenuation_enab;                                      */
/*  input uint8 Tpac_state_ctl_attenuation_gain;                              */
/*  input sint16 Tpac_state_ctl_ff_spring_comp;                               */
/*  input sint16 Tpac_control_voltage_lin;                                    */
/*  input sint16 Tpac_thr_ctl_volt_temp_min;                                  */
/*  input sint16 Tpac_thr_ctl_volt_temp_max;                                  */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input sint16 Tpac_throttle_control_voltage;                               */
/*  input uint8 Anti_wind_up_gain;                                            */
/*  output sint16 Tpac_throttle_control_volt_temp;                            */
/*  output sint16 Tpac_throttle_control_voltage;                              */
/*  output sint16 Anti_wind_up_signal;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeCtrlVoltage(void)
{
   /* Compute_control_voltage */
   uint16 u16LocalMax;
   uint16 u16LocalTens_bat_brut;
   uint16 u16LocalMin;
   sint16 s16LocalTpac_thr_ctrl_volt;
   sint16 s16LocalVoltage;
   sint16 s16LocalMin;
   sint16 s16LocalAntWinUpSig;
   uint32 u32LocalCalc;
   sint32 s32LocalCLAMP1;
   sint32 s32LocalVoltage;
   sint32 s32LocalTpac_thr_ctrl_volt;


   if (Tpac_closed_loop_enable != 0)
   {
      if (Tpac_attenuation_enab != 0)
      {
         /* Tpac_state_ctl_ff_spring_comp   : 2^10 / 25*2^16  V       /inc */
         /* Tpac_state_ctl_attenuation_gain : 1    / 2^8              /inc */
         /* s16LocalVoltage                 : 2^11 / 25*2^16  V       /inc */
         s16LocalVoltage = (sint16)( ( ( Tpac_state_ctl_attenuation_gain
                                       * Tpac_state_ctl_ff_spring_comp)
                                     + 256)
                                   / 512);
      }
      else
      {
         s16LocalVoltage = (sint16)(Tpac_state_ctl_ff_spring_comp / 2);
      }
      /* Tpac_control_voltage_lin         : 2^11 / 2^16  V     /inc */
      /* Tpac_throttle_control_volt_temp  : 2^11 / 25*2^16  V  /inc */
      /* s16LocalVoltage                  : 2^11 / 25*2^16  V  /inc */
      s32LocalCLAMP1 = (sint32)( s16LocalVoltage
                               + (Tpac_control_voltage_lin * 25));
   }
   else
   {
      s32LocalCLAMP1 = 0;
   }
   s16LocalTpac_thr_ctrl_volt =
      (sint16)MATHSRV_udtCLAMP(s32LocalCLAMP1,
                               Tpac_thr_ctl_volt_temp_min,
                               Tpac_thr_ctl_volt_temp_max);
   VEMS_vidSET(Tpac_throttle_control_volt_temp, s16LocalTpac_thr_ctrl_volt);

   /* max physical value of boundaries is 20.479375V -> 32768 dec*/
   VEMS_vidGET(Tension_batterie_brute, u16LocalTens_bat_brut);
   u32LocalCalc = (uint32)(((u16LocalTens_bat_brut * 2415) + 32) / 64);
   u16LocalMax = (uint16)MATHSRV_udtMIN(u32LocalCalc, 32767);
   u16LocalMin = (uint16)MATHSRV_udtMIN(u32LocalCalc, 32768);
   s16LocalMin = (sint16)((-1) * u16LocalMin);

   s32LocalTpac_thr_ctrl_volt = (sint32)(s16LocalTpac_thr_ctrl_volt * 2);
   Tpac_throttle_control_voltage =
      (sint16)MATHSRV_udtCLAMP(s32LocalTpac_thr_ctrl_volt,
                               (sint32)s16LocalMin,
                               (sint32)u16LocalMax);
   s32LocalVoltage = ( Tpac_throttle_control_voltage
                     - s32LocalTpac_thr_ctrl_volt);

   /* s32LocalVoltage               : 2^10 / 25*2^16  V   /inc */
   /* Anti_wind_up_gain             : 2^4  / 2^8     %/V  /inc */
   /* Anti_wind_up_signal           : 100  / 2^11     %   /inc */
   s16LocalAntWinUpSig = (sint16)( ((s32LocalVoltage * Anti_wind_up_gain) + 625)
                                 / 1250);
   Anti_wind_up_signal = (sint16)MATHSRV_udtCLAMP(s16LocalAntWinUpSig,
                                                  -2048,
                                                  2048);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidControlSwitchMode                              */
/* !Description :  Calcul de l'RCO du PWM de commande papillon en sortie de   */
/*                 l'asservissement générique JCAE                            */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tpac_open_loop_control;                                     */
/*  input sint16 Tpac_open_loop_control_voltage;                              */
/*  input sint16 Tpac_throttle_control_voltage;                               */
/*  input uint16 Tpac_batterry_voltage_gain;                                  */
/*  input boolean Tpac_thr_pwm_typ_selec;                                     */
/*  input uint16 Tpac_nul_torque_duty_cycle;                                  */
/*  output sint16 Thr_uCmd;                                                   */
/*  output sint16 Tpac_request_thr_jc_duty_cycle;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidControlSwitchMode(void)
{
   /* Control_mode_switch */
   sint16  s16LocalTpac_open_ctrl_volt;
   sint16  s16LocalTpac_req_thr_jc_duty;
   sint16  s16localvoltage;
   sint32  s32LocalDutyCyc;
   boolean bLocalTpac_open_loop_ctrl;


   VEMS_vidGET(Tpac_open_loop_control, bLocalTpac_open_loop_ctrl);
   if (bLocalTpac_open_loop_ctrl != 0)
   {
      VEMS_vidGET(Tpac_open_loop_control_voltage, s16LocalTpac_open_ctrl_volt);
      s16localvoltage = s16LocalTpac_open_ctrl_volt;
   }
   else
   {
      s16localvoltage = Tpac_throttle_control_voltage;
   }
   VEMS_vidSET(Thr_uCmd, s16localvoltage);

   /* s16localvoltage             : 2^10   / 25*2^16  V    /inc */
   /* Tpac_battery_voltage_gain   : 9.7656 / 2^16    %/V   /inc */
   /* Tpac_nul_torque_duty_cycle  : 100    / 2^14     %    /inc */
   s32LocalDutyCyc = Tpac_batterry_voltage_gain * s16localvoltage;

   if (Tpac_thr_pwm_typ_selec != 0)
   {
      s32LocalDutyCyc = ((s32LocalDutyCyc + 32768) / 65536)
                      + Tpac_nul_torque_duty_cycle;
   }
   else
   {
      s32LocalDutyCyc = ((s32LocalDutyCyc + 16384) / 32768)
                      + Tpac_nul_torque_duty_cycle;
   }

   s16LocalTpac_req_thr_jc_duty = (sint16)MATHSRV_udtCLAMP(s32LocalDutyCyc,
                                                           -16384,
                                                           16384);
   VEMS_vidSET(Tpac_request_thr_jc_duty_cycle, s16LocalTpac_req_thr_jc_duty);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputePositionError                           */
/* !Description :  Ce sous-système spécifie le calcul de l’erreur de position */
/*                 (Tpac_position_error) entre la consigne de position        */
/*                 (Tpac_throttle_position_reference) et la position          */
/*                 (Ssm_raw_filt_throttle_position).                          */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Tpac_state_ctl_position_error;                               */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint16 Tpac_throttle_position_reference;                            */
/*  input sint16 Anti_wind_up_signal;                                         */
/*  output sint16 THRSERVO_s16TpacStCtlPosErrPrev;                            */
/*  output sint16 Tpac_position_error;                                        */
/*  output sint16 Tpac_state_ctl_position_error;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputePositionError(void)
{
   /* Compute_position_error */
   uint16 u16LocalSsm_raw_filt_thr_pos;
   uint16 u16LocalTpac_thr_pos_ref;
   sint16 s16LocalTpac_stat_ctl_pos_err;
   sint16 s16LocalTpac_pos_err;
   sint32 s32localError;

   VEMS_vidGET(Tpac_state_ctl_position_error, s16LocalTpac_stat_ctl_pos_err);
   THRSERVO_s16TpacStCtlPosErrPrev = s16LocalTpac_stat_ctl_pos_err;
   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   VEMS_vidGET(Tpac_throttle_position_reference, u16LocalTpac_thr_pos_ref);
   s32localError = (sint32)( u16LocalTpac_thr_pos_ref
                           - u16LocalSsm_raw_filt_thr_pos);
   s16LocalTpac_pos_err = (sint16)MATHSRV_udtCLAMP(s32localError, -1024, 1024);
   VEMS_vidSET(Tpac_position_error, s16LocalTpac_pos_err);
   s32localError = (Anti_wind_up_signal / 2) + s32localError;
   s16LocalTpac_stat_ctl_pos_err = (sint16)MATHSRV_udtCLAMP(s32localError,
                                                            -1024,
                                                            1024);
   VEMS_vidSET(Tpac_state_ctl_position_error, s16LocalTpac_stat_ctl_pos_err);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidBatteryVoltageGain                             */
/* !Description :  Calcul du gain sur la tension de commande fonction de la   */
/*                 tension batterie.                                          */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input uint16 Tpac_battery_voltage_gain_map[9];                            */
/*  output uint16 Tpac_batterry_voltage_gain;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidBatteryVoltageGain(void)
{
   /* Battery_voltage_gain */
   uint16 u16LocalPara;
   uint16 u16LocalTens_bat_brut;


   VEMS_vidGET(Tension_batterie_brute, u16LocalTens_bat_brut);
   if (u16LocalTens_bat_brut < 1024)
   {
      u16LocalPara = (uint16)(u16LocalTens_bat_brut * 2);
   }
   else
   {
      u16LocalPara = 0x07FF;
   }
   Tpac_batterry_voltage_gain =
      MATHSRV_u16Interp1d(Tpac_battery_voltage_gain_map, u16LocalPara);
}
/*------------------------------- end of file --------------------------------*/