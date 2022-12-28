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
/* !File            : THRSERVO_FCT5.C                                         */
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
/*   1 / THRSERVO_vidManagerThrottleState                                     */
/*   2 / THRSERVO_vidSetControlGainsOut                                       */
/*   3 / THRSERVO_vidSetControlGainsIn                                        */
/*   4 / THRSERVO_vidIntegInitOnSetGainIO                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 04514 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRSERVO/THRSERVO_FCT5.C_v    $*/
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
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidManagerThrottleState                           */
/* !Description :  Stateflow qui définit l’état de l’asservissement papillon  */
/*                 selon la position de ce dernier et gère les événements     */
/*                 relatifs à la commutation des gains fortsou faibles.       */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidSetControlGainsOut();                        */
/*  extf argret void THRSERVO_vidIntegInitOnSetGainIO();                      */
/*  extf argret void THRSERVO_vidSetControlGainsIn();                         */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st42 Tpac_lh_etat_papillon;                                         */
/*  input bool TPAC_LH_IN;                                                    */
/*  input bool TPAC_LH_INIT;                                                  */
/*  input sint16 Tpac_dist_to_limp_home;                                      */
/*  input uint8 Tpac_lh_area_limit_sup;                                       */
/*  input bool TPAC_LH_UP;                                                    */
/*  input uint8 Tpac_lh_area_limit_inf;                                       */
/*  input bool TPAC_LH_LOW;                                                   */
/*  input sint16 Tpac_state_ctl_est_velocity;                                 */
/*  input sint16 Tpac_lh_area_speed_thresh;                                   */
/*  output st42 Tpac_lh_etat_papillon;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidManagerThrottleState(void)
{
   /* Manager_etat_papillon */
   switch (Tpac_lh_etat_papillon)
   {
      case TPAC_LH_INIT:
         THRSERVO_vidSetControlGainsOut();
         THRSERVO_vidIntegInitOnSetGainIO();
         Tpac_lh_etat_papillon = TPAC_LH_IN;
         break;

      case TPAC_LH_IN:
         if (Tpac_dist_to_limp_home >= Tpac_lh_area_limit_sup)
         {
            THRSERVO_vidSetControlGainsOut();
            THRSERVO_vidIntegInitOnSetGainIO();
            Tpac_lh_etat_papillon = TPAC_LH_UP;
         }
         else
         {
            if (Tpac_dist_to_limp_home <= (Tpac_lh_area_limit_inf - 255))
            {
               THRSERVO_vidSetControlGainsOut();
               THRSERVO_vidIntegInitOnSetGainIO();
               Tpac_lh_etat_papillon = TPAC_LH_LOW;
            }
         }
         break;

      case TPAC_LH_UP:
         if (Tpac_dist_to_limp_home <= (Tpac_lh_area_limit_inf - 255))
         {
            Tpac_lh_etat_papillon = TPAC_LH_LOW;
         }
         else
         {
            if (Tpac_dist_to_limp_home < Tpac_lh_area_limit_sup)
            {
               if(Tpac_state_ctl_est_velocity > (-Tpac_lh_area_speed_thresh) )
               {
                  THRSERVO_vidSetControlGainsIn();
                  THRSERVO_vidIntegInitOnSetGainIO();
               }
               Tpac_lh_etat_papillon = TPAC_LH_IN;
            }
         }
         break;

      case TPAC_LH_LOW:
         if (Tpac_dist_to_limp_home >= Tpac_lh_area_limit_sup)
         {
            Tpac_lh_etat_papillon = TPAC_LH_UP;
         }
         else
         {
            if (Tpac_dist_to_limp_home > (Tpac_lh_area_limit_inf - 255))
            {
               if (Tpac_state_ctl_est_velocity < Tpac_lh_area_speed_thresh)
               {
                  THRSERVO_vidSetControlGainsIn();
                  THRSERVO_vidIntegInitOnSetGainIO();
               }
               Tpac_lh_etat_papillon = TPAC_LH_IN;
            }
         }
         break;

      default:
         Tpac_lh_etat_papillon = TPAC_LH_INIT;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidSetControlGainsOut                             */
/* !Description :  Ce bloc positionnne  les gains du  retour d’état  sur  les */
/*                 valeurs  faibles  (en  dehors de la zone "limp-home")      */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_state_feedback_coef_k1_out;                             */
/*  input sint16 Tpac_state_feedback_coef_k2_out;                             */
/*  input uint16 Tpac_state_feedback_coef_k3_out;                             */
/*  input uint8 Tpac_integral_gain_out;                                       */
/*  output uint16 Tpac_state_feedback_coef_k1;                                */
/*  output sint16 Tpac_state_feedback_coef_k2;                                */
/*  output uint16 Tpac_state_feedback_coef_k3;                                */
/*  output uint8 Tpac_state_ctl_integral_gain;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidSetControlGainsOut(void)
{
   /* Set_control_gains_out */
   Tpac_state_feedback_coef_k1  = Tpac_state_feedback_coef_k1_out;
   Tpac_state_feedback_coef_k2  = Tpac_state_feedback_coef_k2_out;
   Tpac_state_feedback_coef_k3  = Tpac_state_feedback_coef_k3_out;
   Tpac_state_ctl_integral_gain = Tpac_integral_gain_out;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidSetControlGainsIn                              */
/* !Description :  Ce bloc positionnne les gains du retour d’état sur les     */
/*                 valeurs fortes (dans la  zone "limp-home")                 */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_state_feedback_coef_k1_in;                              */
/*  input sint16 Tpac_state_feedback_coef_k2_in;                              */
/*  input uint16 Tpac_state_feedback_coef_k3_in;                              */
/*  input uint8 Tpac_integral_gain_in;                                        */
/*  output uint16 Tpac_state_feedback_coef_k1;                                */
/*  output sint16 Tpac_state_feedback_coef_k2;                                */
/*  output uint16 Tpac_state_feedback_coef_k3;                                */
/*  output uint8 Tpac_state_ctl_integral_gain;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidSetControlGainsIn(void)
{
   /* Set_control_gains_in */
   Tpac_state_feedback_coef_k1  = Tpac_state_feedback_coef_k1_in;
   Tpac_state_feedback_coef_k2  = Tpac_state_feedback_coef_k2_in;
   Tpac_state_feedback_coef_k3  = Tpac_state_feedback_coef_k3_in;
   Tpac_state_ctl_integral_gain = Tpac_integral_gain_in;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidIntegInitOnSetGainIO                           */
/* !Description :  Ce bloc réinitialise le terme intégral pour garantir la    */
/*                 continuité de la commande, lors d’un changement de gains.  */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint16 Tpac_state_feedback_coef_k1;                                 */
/*  input sint16 Tpac_state_ctl_est_velocity;                                 */
/*  input sint16 Tpac_state_feedback_coef_k2;                                 */
/*  input boolean Tpac_current_select_bool;                                   */
/*  input sint16 Tpac_measured_current;                                       */
/*  input uint16 Tpac_state_feedback_coef_k3;                                 */
/*  input sint16 Tpac_estimated_current;                                      */
/*  input sint16 Tpac_throttle_control_voltage;                               */
/*  output sint32 Tpac_integral_output_temp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidIntegInitOnSetGainIO(void)
{
   /* Compute_integral_init_on_set_gain_in_out */
   uint16 u16LocalIntegral;
   uint16 u16LocalTpac_corr_thr_pos;
   sint16 s16LocalTpac_meas_cur;
   uint32 u32LocalFeedBack_1;
   uint32 u32LocalIntegral;
   sint32 s32LocalFeedBack_2;
   sint32 s32LocalFeedBack_3;
   sint32 s32LocalFeedBack_4;
   sint32 s32LocalTpacIntegralOutputTemp;


   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpac_corr_thr_pos);
   u32LocalIntegral = u16LocalTpac_corr_thr_pos * 25;
   u16LocalIntegral = (uint16)MATHSRV_udtMIN(u32LocalIntegral, 65535);
   u32LocalFeedBack_1 = (uint32)( Tpac_state_feedback_coef_k1
                                * u16LocalIntegral);
   u32LocalFeedBack_1 = (u32LocalFeedBack_1 + 8) / 16;

   s32LocalFeedBack_2 = (sint32)( Tpac_state_ctl_est_velocity
                                * Tpac_state_feedback_coef_k2);

   if (s32LocalFeedBack_2 >= 0)
   {
      s32LocalFeedBack_2 = (s32LocalFeedBack_2 + 4) / 8;
   }
   else
   {
      s32LocalFeedBack_2 = (s32LocalFeedBack_2 - 4) / 8;
   }

   if (Tpac_current_select_bool != 0)
   {
      VEMS_vidGET(Tpac_measured_current, s16LocalTpac_meas_cur);
      s32LocalFeedBack_3 = (sint32)( s16LocalTpac_meas_cur
                                   * Tpac_state_feedback_coef_k3);
   }
   else
   {
      s32LocalFeedBack_3 = (sint32)( Tpac_estimated_current
                                   * Tpac_state_feedback_coef_k3);
   }

   if (s32LocalFeedBack_3 >= 0)
   {
      s32LocalFeedBack_3 = (s32LocalFeedBack_3 + 16) / 32;
   }
   else
   {
      s32LocalFeedBack_3 = (s32LocalFeedBack_3 - 16) / 32;
   }

   s32LocalFeedBack_4 = (sint32)((Tpac_throttle_control_voltage * 1024) / 25);

   s32LocalTpacIntegralOutputTemp = ( (sint32)u32LocalFeedBack_1
                                    + s32LocalFeedBack_2
                                    + s32LocalFeedBack_3
                                    + s32LocalFeedBack_4);
   Tpac_integral_output_temp =
      MATHSRV_udtCLAMP(s32LocalTpacIntegralOutputTemp, -67107840, 67107840);
}
/*------------------------------- end of file --------------------------------*/