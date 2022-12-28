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
/* !File            : THRSERVO_FCT2.C                                         */
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
/*   1 / THRSERVO_vidAdjustVelocity                                           */
/*   2 / THRSERVO_vidVelocityWindow1                                          */
/*   3 / THRSERVO_vidVelocityWindow2                                          */
/*   4 / THRSERVO_vidVelocityWindow3                                          */
/*   5 / THRSERVO_vidVelocityWindow4                                          */
/*   6 / THRSERVO_vidMedianFilter                                             */
/*   7 / THRSERVO_vidComputeCurrentCall                                       */
/*   8 / THRSERVO_vidComputeCurrent                                           */
/*   9 / THRSERVO_vidManageLimpHome                                           */
/*   10 / THRSERVO_vidCompStateFeedbackCtl                                    */
/*                                                                            */
/* !Reference   : V02 NT 08 04514 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRSERVO/THRSERVO_FCT2.C_v    $*/
/* $Revision::   1.4      $$Author::   acabresp       $$Date::   02 Jun 2010 $*/
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
/* !Function    :  THRSERVO_vidAdjustVelocity                                 */
/* !Description :  Le calcul de la dérivée est basé sur la taille estimée de  */
/*                 la fenêtre. Les coefficients utilisés pour le calcul de la */
/*                 dérivée sont basés sur la méthode du "Best-fit-FOAW"       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidVelocityWindow1();                           */
/*  extf argret void THRSERVO_vidVelocityWindow2();                           */
/*  extf argret void THRSERVO_vidVelocityWindow3();                           */
/*  extf argret void THRSERVO_vidVelocityWindow4();                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Tpac_est_vel_window_size;                                     */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  output sint16 Tpac_non_filt_est_velocity;                                 */
/*  output uint16 THRSERVO_u16SsmRawFiltThrPosMem;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidAdjustVelocity(void)
{
   /* adjust_velocity */
   uint16 u16LocalSsm_raw_filt_thr_pos;


   switch (Tpac_est_vel_window_size)
   {
      case 1:
         THRSERVO_vidVelocityWindow1();
         break;
      case 2:
         THRSERVO_vidVelocityWindow2();
         break;
      case 3:
         THRSERVO_vidVelocityWindow3();
         break;
      case 4:
         THRSERVO_vidVelocityWindow4();
         break;
      default:
         Tpac_non_filt_est_velocity = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   THRSERVO_u16SsmRawFiltThrPosMem = u16LocalSsm_raw_filt_thr_pos;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidVelocityWindow1                                */
/* !Description :  calcul de la vitesse du rotor estimée avec une fenêtre de  */
/*                 taille 1                                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint16 Tpac_previous_throttle_pos_1;                                */
/*  input uint16 Tpac_est_vel_gain_1;                                         */
/*  output sint16 Tpac_non_filt_est_velocity;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidVelocityWindow1(void)
{
   /* velocity_window_1 */
   uint16 u16LocalSsm_raw_filt_thr_pos;
   sint32 s32LocalVelocity;


   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   s32LocalVelocity = ( u16LocalSsm_raw_filt_thr_pos
                      - Tpac_previous_throttle_pos_1) * Tpac_est_vel_gain_1;
   s32LocalVelocity = (s32LocalVelocity * 25) / 16;
   Tpac_non_filt_est_velocity = (sint16)MATHSRV_udtCLAMP(s32LocalVelocity,
                                                         SINT16_MIN,
                                                         SINT16_MAX);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidVelocityWindow2                                */
/* !Description :  calcul de la vitesse du rotor estimée avec une fenêtre de  */
/*                 taille 2                                                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint16 Tpac_previous_throttle_pos_2;                                */
/*  input uint16 Tpac_est_vel_gain_2;                                         */
/*  output sint16 Tpac_non_filt_est_velocity;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidVelocityWindow2(void)
{
   /* velocity_window_2 */
   uint16 u16LocalSsm_raw_filt_thr_pos;
   sint32 s32LocalVelocity;


   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   s32LocalVelocity = ( u16LocalSsm_raw_filt_thr_pos
                      - Tpac_previous_throttle_pos_2) * Tpac_est_vel_gain_2;
   s32LocalVelocity = (s32LocalVelocity * 25) / 16;
   Tpac_non_filt_est_velocity = (sint16)MATHSRV_udtCLAMP(s32LocalVelocity,
                                                         SINT16_MIN,
                                                         SINT16_MAX);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidVelocityWindow3                                */
/* !Description :  calcul de la vitesse du rotor estimée avec une fenêtre de  */
/*                 taille 3                                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint16 Tpac_previous_throttle_pos_3;                                */
/*  input uint16 Tpac_previous_throttle_pos_1;                                */
/*  input uint16 Tpac_previous_throttle_pos_2;                                */
/*  input uint16 Tpac_est_vel_gain_3;                                         */
/*  output sint16 Tpac_non_filt_est_velocity;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidVelocityWindow3(void)
{
   /* velocity_window_3 */
   uint16 u16LocalSsm_raw_filt_thr_pos;
   sint32 s32LocalVelocity;


   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   s32LocalVelocity = ( ( ( (3 * u16LocalSsm_raw_filt_thr_pos)
                          - (3 * Tpac_previous_throttle_pos_3) )
                        + Tpac_previous_throttle_pos_1)
                      - Tpac_previous_throttle_pos_2 ) * Tpac_est_vel_gain_3;
   s32LocalVelocity = (s32LocalVelocity * 25) / 16;
   Tpac_non_filt_est_velocity = (sint16)MATHSRV_udtCLAMP(s32LocalVelocity,
                                                         SINT16_MIN,
                                                         SINT16_MAX);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidVelocityWindow4                                */
/* !Description :  calcul de la vitesse du rotor estimée avec une fenêtre de  */
/*                 taille 4                                                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint16 Tpac_previous_throttle_pos_4;                                */
/*  input uint16 Tpac_previous_throttle_pos_1;                                */
/*  input uint16 Tpac_previous_throttle_pos_3;                                */
/*  input uint16 Tpac_est_vel_gain_4;                                         */
/*  output sint16 Tpac_non_filt_est_velocity;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidVelocityWindow4(void)
{
   /* velocity_window_4 */
   uint16 u16LocalSsm_raw_filt_thr_pos;
   sint32 s32LocalVelocity;

   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsm_raw_filt_thr_pos);
   s32LocalVelocity = ( ( ( (4 * u16LocalSsm_raw_filt_thr_pos)
                          - (4 * Tpac_previous_throttle_pos_4) )
                        + (2 * Tpac_previous_throttle_pos_1) )
                      - (2 * Tpac_previous_throttle_pos_3) )
                      * Tpac_est_vel_gain_4;
   s32LocalVelocity = (s32LocalVelocity * 25) / 16;
   Tpac_non_filt_est_velocity = (sint16)MATHSRV_udtCLAMP(s32LocalVelocity,
                                                         SINT16_MIN,
                                                         SINT16_MAX);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidMedianFilter                                   */
/* !Description :  Les entrées du filtre médian sont les trois dernières      */
/*                 valeurs de la vitesse.  La sortie du filtre médian est la  */
/*                 valeur non extrême des trois entrées. Un gain de retard    */
/*                 permet de filtrer les valeurs de la vitesse pour éviter de */
/*                 trop brusques variations.                                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tpac_est_vel_gain_retard;                                     */
/*  input sint16 THRSERVO_s16EstVelocityPrev1;                                */
/*  input boolean Tpac_median_filter_inh;                                     */
/*  input sint16 Tpac_non_filt_est_velocity;                                  */
/*  input sint16 THRSERVO_s16EstVelocityPrev2;                                */
/*  output sint16 Tpac_state_ctl_est_velocity;                                */
/*  output sint16 THRSERVO_s16EstVelocityPrev2;                               */
/*  output sint16 THRSERVO_s16EstVelocityPrev1;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidMedianFilter(void)
{
   /* median_filter */
   uint16 u16LocalVelocityPrev1;
   uint16 u16LocalVelocityPrev2;
   uint16 u16LocalVelocityPrev3;
   uint16 u16LocalOutMedianFilter;
   sint16 s16LocalVelocity;
   sint32 s32LocalVelocity;


   s16LocalVelocity = (sint16)( ( Tpac_est_vel_gain_retard
                                * THRSERVO_s16EstVelocityPrev1) / 255 );
   if (Tpac_median_filter_inh != 0)
   {
      s32LocalVelocity = ( Tpac_non_filt_est_velocity + s16LocalVelocity);
      Tpac_state_ctl_est_velocity =
         (sint16)MATHSRV_udtCLAMP(( s32LocalVelocity),
                                   SINT16_MIN,
                                   SINT16_MAX );
   }
   else
   {
      u16LocalVelocityPrev1 = (uint16)(Tpac_non_filt_est_velocity + 32768);
      u16LocalVelocityPrev2 = (uint16)(THRSERVO_s16EstVelocityPrev1 + 32768);
      u16LocalVelocityPrev3 = (uint16)(THRSERVO_s16EstVelocityPrev2 + 32768);
      u16LocalOutMedianFilter = MATHSRV_u16MedianFilter(u16LocalVelocityPrev1,
                                                        u16LocalVelocityPrev2,
                                                        u16LocalVelocityPrev3);
      s32LocalVelocity = (s16LocalVelocity + u16LocalOutMedianFilter) - 32768;
      Tpac_state_ctl_est_velocity = (sint16)MATHSRV_udtCLAMP(s32LocalVelocity,
                                                             SINT16_MIN,
                                                             SINT16_MAX);
   }
   THRSERVO_s16EstVelocityPrev2 = THRSERVO_s16EstVelocityPrev1;
   THRSERVO_s16EstVelocityPrev1 = Tpac_non_filt_est_velocity;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeCurrentCall                             */
/* !Description :  Cette fonction définit les conditions d'appel de la        */
/*                 fonction qui estime le courant circulant dans le papillon. */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidComputeCurrent();                            */
/*  input uint16 Tpac_ini_throttle_control_tempo;                             */
/*  input boolean Tpac_current_select_bool;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeCurrentCall(void)
{
   if (  (Tpac_ini_throttle_control_tempo == 0)
      && (Tpac_current_select_bool == 0))
   {
      THRSERVO_vidComputeCurrent();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeCurrent                                 */
/* !Description :  estimation de l’état non mesuré du système (calcul du      */
/*                 courant)                                                   */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 Tpac_state_ctl_est_velocity;                                 */
/*  input uint16 Tpac_motive_torque_per2rd;                                   */
/*  input sint16 Tpac_throttle_control_voltage;                               */
/*  input uint8 Tpac_current_estimation_gain_1;                               */
/*  input sint16 Tpac_estimated_current;                                      */
/*  input uint8 Tpac_current_estimation_gain_2;                               */
/*  output sint16 Tpac_estimated_current;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeCurrent(void)
{
   /* Compute_current */
   sint32 s32LocalCurrent;
   sint16 s16LocalCurrent;


   /* Tpac_state_ctl_est_velocity   : 1 / 2^4      %/s         */
   /* Tpac_motive_torque_per2rd     : 0.5 / 2^16   Nm/A/%      */
   /* Tpac_throttle_control_voltage : 1 / 100*2^4  V           */
   /* Tpac_current_estimation_gain_1: 1 / 2^8      1/Ohm       */
   /* s32LocalCurrent               : 2^4 / 2^16   A           */
   s32LocalCurrent = (Tpac_state_ctl_est_velocity * Tpac_motive_torque_per2rd)
                   / 1024;
   s32LocalCurrent = ( ((Tpac_throttle_control_voltage * 128) / 100)
                     - s32LocalCurrent);
   s32LocalCurrent = (s32LocalCurrent * Tpac_current_estimation_gain_1) / 256;

   s16LocalCurrent = (sint16)( ( Tpac_estimated_current
                              * Tpac_current_estimation_gain_2) / 256 );
   s32LocalCurrent = s32LocalCurrent + s16LocalCurrent;
   Tpac_estimated_current = (sint16)MATHSRV_udtCLAMP(s32LocalCurrent,
                                                     SINT16_MIN,
                                                     SINT16_MAX);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidManageLimpHome                                 */
/* !Description :  La stratégie de franchissement du limp-home consiste à     */
/*                 adapter les 4 gains du retour d’état à l’intérieur d’une   */
/*                 zone calibrable autour du limp-home.                       */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRSERVO_vidManagerThrottleState();                      */
/*  input uint16 Ssm_limp_home_throttle_pos;                                  */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  output sint16 Tpac_dist_to_limp_home;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidManageLimpHome(void)
{
   /* Gestion_limp_home */
   uint16 u16LocalSsm_limp_thr_pos;
   uint16 u16LocalTpac_corr_thr_pos;
   sint32 s32LocalTpac_dist;


   VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsm_limp_thr_pos);
   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpac_corr_thr_pos);
   s32LocalTpac_dist = (u16LocalTpac_corr_thr_pos - u16LocalSsm_limp_thr_pos);
   Tpac_dist_to_limp_home =
      (sint16)MATHSRV_udtCLAMP( s32LocalTpac_dist,
                                -1024,
                                1024 );
   THRSERVO_vidManagerThrottleState();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidCompStateFeedbackCtl                           */
/* !Description :  Ce sous-système réalise le calcul du produit scalaire [K1  */
/*                 K2 K3]*[x1 x2 x3] , où K1, K2 et K3 sont les gains du      */
/*                 retour d’état respectivement appliqués à la position (état */
/*                 x1), à la vitesse (état x2) et au courant (état x3).       */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint16 Tpac_state_feedback_coef_k1;                                 */
/*  input sint16 Tpac_state_feedback_coef_k2;                                 */
/*  input sint16 Tpac_state_ctl_est_velocity;                                 */
/*  input boolean Tpac_throttle_select;                                       */
/*  input boolean Tpac_current_select_bool;                                   */
/*  input sint16 Tpac_measured_current;                                       */
/*  input uint16 Tpac_state_feedback_coef_k3;                                 */
/*  input sint16 Tpac_estimated_current;                                      */
/*  output sint16 Tpac_state_feedback_control;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidCompStateFeedbackCtl(void)
{
   /* Compute_state_feedback_control */
   uint16 u16LocalTpac_corr_thr_pos;
   sint16 s16LocalTpac_meas_cur;
   uint32 u32LocalFdBack1;
   uint32 u32LocalMIN;
   uint32 u32LocalCalc;
   sint32 s32LocalFdBack2;
   sint32 s32LocalFdBack3;
   sint32 s32LocalTpac_state;


   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpac_corr_thr_pos);
   u32LocalMIN = (u16LocalTpac_corr_thr_pos * 25);
   if (Tpac_state_feedback_coef_k1 != 0)
   {
      u32LocalCalc = UINT32_MAX / (uint32)Tpac_state_feedback_coef_k1;
      if (u32LocalMIN > u32LocalCalc)
      {
         u32LocalFdBack1 = u32LocalMIN / 32768;
         u32LocalFdBack1 = u32LocalFdBack1 * Tpac_state_feedback_coef_k1;
      }
      else
      {
         u32LocalFdBack1 = Tpac_state_feedback_coef_k1 * u32LocalMIN;
         u32LocalFdBack1 = u32LocalFdBack1 / 32768;
      }
   }
   else
   {
      u32LocalFdBack1 = 0;
   }
   s32LocalFdBack2 = (Tpac_state_feedback_coef_k2 * Tpac_state_ctl_est_velocity)
                   / 16384;
   if (Tpac_throttle_select != 0)
   {
      if (Tpac_current_select_bool != 0)
      {
         VEMS_vidGET(Tpac_measured_current, s16LocalTpac_meas_cur);
         s32LocalFdBack3 = s16LocalTpac_meas_cur * Tpac_state_feedback_coef_k3;
      }
      else
      {
         s32LocalFdBack3 = Tpac_estimated_current * Tpac_state_feedback_coef_k3;
      }
      s32LocalFdBack3 = s32LocalFdBack3 / 65536;
   }
   else
   {
      s32LocalFdBack3 = 0;
   }
   s32LocalTpac_state = ( (sint32)u32LocalFdBack1
                        + s32LocalFdBack2
                        + s32LocalFdBack3);
   Tpac_state_feedback_control = (sint16)MATHSRV_udtCLAMP(s32LocalTpac_state,
                                                          SINT16_MIN,
                                                          SINT16_MAX);
}
/*------------------------------- end of file --------------------------------*/