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
/* !File            : THRSERVO_FCT1.C                                         */
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
/*   1 / THRSERVO_vidInitOutput                                               */
/*   2 / THRSERVO_vidComputeInitTasks                                         */
/*   3 / THRSERVO_vidInitControlVariables                                     */
/*   4 / THRSERVO_vidInitTempo                                                */
/*   5 / THRSERVO_vidDecTempo                                                 */
/*   6 / THRSERVO_vidComputeInnerLoop                                         */
/*   7 / THRSERVO_vidComputePhysicalState                                     */
/*   8 / THRSERVO_vidComputeVelocity                                          */
/*   9 / THRSERVO_vidUpdatePositionValues                                     */
/*   10 / THRSERVO_vidSetWindowSize                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 04514 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRSERVO/THRSERVO_FCT1.C_v    $*/
/* $Revision::   1.4      $$Author::   acabresp       $$Date::   02 Jun 2010 $*/
/* $Author::   acabresp                               $$Date::   02 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRSERVO.h"
#include "THRSERVO_L.h"
#include "THRSERVO_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input bool TPAC_FRICT_ADHER;                                              */
/*  input bool TPAC_LH_INIT;                                                  */
/*  output st04 Tpac_frict_status;                                            */
/*  output st42 Tpac_lh_etat_papillon;                                        */
/*  output sint16 Tpac_throttle_control_volt_temp;                            */
/*  output sint16 Tpac_position_error;                                        */
/*  output sint16 Tpac_request_thr_jc_duty_cycle;                             */
/*  output sint16 Thr_uCmd;                                                   */
/*  output boolean Thr_bCdnAcvCll;                                            */
/*  output sint16 Tpac_throttle_control_voltage;                              */
/*  output sint16 Tpac_state_feedback_control;                                */
/*  output sint16 Tpac_frict_ff_comp_volt_filt;                               */
/*  output sint16 THRSERVO_s16TpacStCtlPosErrPrev;                            */
/*  output sint16 THRSERVO_s16EstVelocityPrev1;                               */
/*  output sint16 THRSERVO_s16EstVelocityPrev2;                               */
/*  output sint16 THRSERVO_s16FrictFFCompVoltPrev;                            */
/*  output uint16 THRSERVO_u16SsmRawFiltThrPosMem;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidInitOutput(void)
{
   Tpac_frict_status = TPAC_FRICT_ADHER;
   Tpac_lh_etat_papillon = TPAC_LH_INIT;

   VEMS_vidSET(Tpac_throttle_control_volt_temp, 0);
   VEMS_vidSET(Tpac_position_error, 0);
   VEMS_vidSET(Tpac_request_thr_jc_duty_cycle, 0);
   VEMS_vidSET(Thr_uCmd, 0);
   VEMS_vidSET(Thr_bCdnAcvCll, 0);
   Tpac_throttle_control_voltage = 0;
   Tpac_state_feedback_control = 0;

   Tpac_frict_ff_comp_volt_filt = 0;
   THRSERVO_s16TpacStCtlPosErrPrev = 0;
   THRSERVO_s16EstVelocityPrev1 = 0;
   THRSERVO_s16EstVelocityPrev2 = 0;
   THRSERVO_s16FrictFFCompVoltPrev = 0;
   THRSERVO_u16SsmRawFiltThrPosMem = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeInitTasks                               */
/* !Description :  Ce sous-système réalise les tâches d’initialisation de la  */
/*                 stratégie de pilotage du papillon motorisé.                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidInitControlVariables();                      */
/*  extf argret void THRSERVO_vidInitTempo();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeInitTasks(void)
{
   /* Compute_initialization_tasks */
   THRSERVO_vidInitControlVariables();
   THRSERVO_vidInitTempo();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidInitControlVariables                           */
/* !Description :  initialisation des variables des algorithmes de            */
/*                 l’asservissement                                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint8 Tpac_integral_gain_out;                                       */
/*  input uint16 Tpac_state_feedback_coef_k1_out;                             */
/*  input sint16 Tpac_state_feedback_coef_k2_out;                             */
/*  input uint16 Tpac_state_feedback_coef_k3_out;                             */
/*  output sint16 Tpac_estimated_current;                                     */
/*  output sint16 Anti_wind_up_signal;                                        */
/*  output sint16 Tpac_state_ctl_est_velocity;                                */
/*  output sint16 Tpac_non_filt_est_velocity;                                 */
/*  output sint16 Tpac_integral_output;                                       */
/*  output sint32 Tpac_integral_output_temp;                                  */
/*  output sint16 Tpac_state_ctl_position_error;                              */
/*  output boolean Tpac_closed_loop_enable;                                   */
/*  output uint16 Tpac_previous_throttle_pos_1;                               */
/*  output uint16 Tpac_previous_throttle_pos_2;                               */
/*  output uint16 Tpac_previous_throttle_pos_3;                               */
/*  output uint16 Tpac_previous_throttle_pos_4;                               */
/*  output uint8 Tpac_state_ctl_integral_gain;                                */
/*  output uint16 Tpac_state_feedback_coef_k1;                                */
/*  output sint16 Tpac_state_feedback_coef_k2;                                */
/*  output uint16 Tpac_state_feedback_coef_k3;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidInitControlVariables(void)
{
   /* Init_control_variables */
   uint16 u16LocalSsm_raw_filt_thr_pos;


   Tpac_estimated_current = 0;
   Anti_wind_up_signal = 0;
   Tpac_state_ctl_est_velocity = 0;
   Tpac_non_filt_est_velocity = 0;
   VEMS_vidSET(Tpac_integral_output, 0);
   Tpac_integral_output_temp = 0;
   VEMS_vidSET(Tpac_state_ctl_position_error, 0);
   Tpac_closed_loop_enable = 0;
   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   Tpac_previous_throttle_pos_1 =
      (uint16)MATHSRV_udtMIN(u16LocalSsm_raw_filt_thr_pos, 1024);

   Tpac_previous_throttle_pos_2 =
      (uint16)MATHSRV_udtMIN(u16LocalSsm_raw_filt_thr_pos, 1024);

   Tpac_previous_throttle_pos_3 =
      (uint16)MATHSRV_udtMIN(u16LocalSsm_raw_filt_thr_pos, 1024);

   Tpac_previous_throttle_pos_4 =
      (uint16)MATHSRV_udtMIN(u16LocalSsm_raw_filt_thr_pos, 1024);

   Tpac_state_ctl_integral_gain = Tpac_integral_gain_out;
   Tpac_state_feedback_coef_k1 = Tpac_state_feedback_coef_k1_out;
   Tpac_state_feedback_coef_k2 = Tpac_state_feedback_coef_k2_out;
   Tpac_state_feedback_coef_k3 = Tpac_state_feedback_coef_k3_out;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidInitTempo                                      */
/* !Description :  initialisation d’une temporisation durant laquelle le      */
/*                 calcul d’estimation du courant est inhibé                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_ini_throttle_control_delay;                             */
/*  input uint8 Tpac_frict_set_delay;                                         */
/*  input uint8 Tpac_frict_reset_delay;                                       */
/*  output uint16 Tpac_ini_throttle_control_tempo;                            */
/*  output uint8 Tpac_frict_ris_count;                                        */
/*  output uint8 Tpac_frict_fal_count;                                        */
/*  output uint8 Tpac_frict_reset_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidInitTempo(void)
{
   /* Init_tempo */
   Tpac_ini_throttle_control_tempo = Tpac_ini_throttle_control_delay;
   Tpac_frict_ris_count = Tpac_frict_set_delay;
   Tpac_frict_fal_count = Tpac_frict_set_delay;
   Tpac_frict_reset_count = Tpac_frict_reset_delay;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidDecTempo                                       */
/* !Description :  Ce sous-système décrémente la temporisation                */
/*                 d’initialisation de la stratégie de contrôle               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_ini_throttle_control_tempo;                             */
/*  output uint16 Tpac_ini_throttle_control_tempo;                            */
/*  output boolean Thr_bCdnAcvCll;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidDecTempo(void)
{
   /* Dec_tempo */
   if (Tpac_ini_throttle_control_tempo > 0)
   {
      Tpac_ini_throttle_control_tempo =
         (uint16)(Tpac_ini_throttle_control_tempo - 1);
   }

   if (Tpac_ini_throttle_control_tempo == 0)
   {
      VEMS_vidSET(Thr_bCdnAcvCll, 1);
   }
   else
   {
      VEMS_vidSET(Thr_bCdnAcvCll, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeInnerLoop                               */
/* !Description :  Ce sous-système réalise le calcul de la boucle interne de  */
/*                 la loi de commande                                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidComputePhysicalState();                      */
/*  extf argret void THRSERVO_vidCompStateFeedbackCtl();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeInnerLoop(void)
{
   /* Compute_inner_loop */
   THRSERVO_vidComputePhysicalState();
   THRSERVO_vidCompStateFeedbackCtl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputePhysicalState                           */
/* !Description :  Estimation de l’état non mesuré du système (calcul de la   */
/*                 vitesse du papillon, calcul du courant), du couple ressort */
/*                 et de sa dérivée (en vue du calcul du feedforward)         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidComputeVelocity();                           */
/*  extf argret void THRSERVO_vidComputeCurrentCall();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputePhysicalState(void)
{
   /* Compute_physical_states */
   THRSERVO_vidComputeVelocity();
   THRSERVO_vidComputeCurrentCall();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeVelocity                                */
/* !Description :  Ce sous-système calcule l’estimation de la vitesse du      */
/*                 papillon motorisé (Tpac_estimated_velocity) par dérivation */
/*                 numérique de la position (Ssm_raw_filt_throttle_position)  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidUpdatePositionValues();                      */
/*  extf argret void THRSERVO_vidSetWindowSize();                             */
/*  extf argret void THRSERVO_vidAdjustVelocity();                            */
/*  extf argret void THRSERVO_vidMedianFilter();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeVelocity(void)
{
   /* Compute_velocity */
   THRSERVO_vidUpdatePositionValues();
   THRSERVO_vidSetWindowSize();
   THRSERVO_vidAdjustVelocity();
   THRSERVO_vidMedianFilter();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidUpdatePositionValues                           */
/* !Description :  Mise à jour des valeurs retardées de la position papillon  */
/*                 utilisées dans l'algorithme de détermination de la taille  */
/*                 de la fenêtre                                              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_previous_throttle_pos_3;                                */
/*  input uint16 Tpac_previous_throttle_pos_2;                                */
/*  input uint16 Tpac_previous_throttle_pos_1;                                */
/*  input uint16 THRSERVO_u16SsmRawFiltThrPosMem;                             */
/*  output uint16 Tpac_previous_throttle_pos_4;                               */
/*  output uint16 Tpac_previous_throttle_pos_3;                               */
/*  output uint16 Tpac_previous_throttle_pos_2;                               */
/*  output uint16 Tpac_previous_throttle_pos_1;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidUpdatePositionValues(void)
{
   /* update_position_values */
   Tpac_previous_throttle_pos_4 =
      (uint16)MATHSRV_udtMIN(Tpac_previous_throttle_pos_3, 1024);

   Tpac_previous_throttle_pos_3 =
      (uint16)MATHSRV_udtMIN(Tpac_previous_throttle_pos_2, 1024);

   Tpac_previous_throttle_pos_2 =
      (uint16)MATHSRV_udtMIN(Tpac_previous_throttle_pos_1, 1024);

   Tpac_previous_throttle_pos_1 =
      (uint16)MATHSRV_udtMIN(THRSERVO_u16SsmRawFiltThrPosMem, 1024);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidSetWindowSize                                  */
/* !Description :  L'algorithme utilisé pour déterminer la taille de la       */
/*                 fenêtre se base sur la dispersion des positions autour     */
/*                 d'une valeur moyenne estimée de la dérivée et sur          */
/*                 l'amplitude des variations de la position.                 */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint16 Tpac_previous_throttle_pos_1;                                */
/*  input uint16 Tpac_est_vel_thresh_1;                                       */
/*  input uint8 Tpac_est_vel_window_size;                                     */
/*  input uint16 Tpac_previous_throttle_pos_2;                                */
/*  input uint16 Tpac_previous_throttle_pos_3;                                */
/*  input uint16 Tpac_est_vel_thresh_2;                                       */
/*  input uint16 Tpac_est_vel_thresh_3;                                       */
/*  input uint16 Tpac_previous_throttle_pos_4;                                */
/*  input uint16 Tpac_est_vel_thresh_4;                                       */
/*  output uint8 Tpac_est_vel_window_size;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidSetWindowSize(void)
{
   /* set_window_size */
   uint8  u8LocalWindSize;
   uint16 u16LocalAbsThrPos;
   uint16 u16LocalSsm_raw_filt_thr_pos;
   uint32 u32LocalAbsThrPos;
   sint32 s32LocalABS0;
   sint32 s32LocalABS01;
   sint32 s32LocalABS1;
   sint32 s32LocalABS2;
   sint32 s32LocalABS3;
   uint32 u32LocalAbsThrPos2;


   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   s32LocalABS0 = u16LocalSsm_raw_filt_thr_pos - Tpac_previous_throttle_pos_1;
   u16LocalAbsThrPos = (uint16)MATHSRV_udtABS(s32LocalABS0);


   if (u16LocalAbsThrPos < Tpac_est_vel_thresh_1)
   {
      if (Tpac_est_vel_window_size == 1)
      {
         u8LocalWindSize = 2;
      }
      else
      {
         s32LocalABS01 =
            u16LocalSsm_raw_filt_thr_pos - Tpac_previous_throttle_pos_2;
         u16LocalAbsThrPos = (uint16)MATHSRV_udtABS(s32LocalABS01);
         s32LocalABS1 = ( ( (2 * u16LocalSsm_raw_filt_thr_pos)
                          - (3 * Tpac_previous_throttle_pos_1))
                        + Tpac_previous_throttle_pos_3);
         u32LocalAbsThrPos =
            (uint32)MATHSRV_udtABS( s32LocalABS1);
         s32LocalABS2 = ( u16LocalSsm_raw_filt_thr_pos
                        - ( (3 * Tpac_previous_throttle_pos_2)
                          + (2 * Tpac_previous_throttle_pos_3) ));
         u32LocalAbsThrPos2 =
            (uint32)MATHSRV_udtABS( s32LocalABS2);
         if (  (u16LocalAbsThrPos  < Tpac_est_vel_thresh_2)
            && (u32LocalAbsThrPos  < Tpac_est_vel_thresh_3)
            && (u32LocalAbsThrPos2 < Tpac_est_vel_thresh_3) )
         {
            if (Tpac_est_vel_window_size == 2)
            {
               u8LocalWindSize = 3;
            }
            else
            {
               s32LocalABS3 = ( ( ( u16LocalSsm_raw_filt_thr_pos
                                  - Tpac_previous_throttle_pos_1)
                                - Tpac_previous_throttle_pos_3)
                              + Tpac_previous_throttle_pos_4 );
               u32LocalAbsThrPos =
                  (uint32)MATHSRV_udtABS(s32LocalABS3);
               if (u32LocalAbsThrPos < Tpac_est_vel_thresh_4)
               {
                  u8LocalWindSize = 4;
               }
               else
               {
                  u8LocalWindSize = 3;
               }
            }
         }
         else
         {
            u8LocalWindSize = 2;
         }
      }
   }
   else
   {
      u8LocalWindSize = 1;
   }
   Tpac_est_vel_window_size = u8LocalWindSize;
}
/*------------------------------- end of file --------------------------------*/