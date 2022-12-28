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
/* !File            : THRSERVO_FCT4.C                                         */
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
/*   1 / THRSERVO_vidFrictionCompensation                                     */
/*   2 / THRSERVO_vidFrictionDetection                                        */
/*   3 / THRSERVO_vidFrictConstCounter                                        */
/*   4 / THRSERVO_vidSetFrictStatus                                           */
/*   5 / THRSERVO_vidComputeFrictCompens                                      */
/*   6 / THRSERVO_vidFiltering                                                */
/*   7 / THRSERVO_vidFiltCompensFeedBack                                      */
/*                                                                            */
/* !Reference   : V02 NT 08 04514 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRSERVO/THRSERVO_FCT4.C_v    $*/
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
/* !Function    :  THRSERVO_vidFrictionCompensation                           */
/* !Description :  Stratégie de compensation des  frottements secs.           */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidFrictionDetection();                         */
/*  extf argret void THRSERVO_vidFrictConstCounter();                         */
/*  extf argret void THRSERVO_vidSetFrictStatus();                            */
/*  extf argret void THRSERVO_vidComputeFrictCompens();                       */
/*  extf argret void THRSERVO_vidFiltering();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidFrictionCompensation(void)
{
   /* Friction_compensation */
   THRSERVO_vidFrictionDetection();
   THRSERVO_vidFrictConstCounter();
   THRSERVO_vidSetFrictStatus();
   THRSERVO_vidComputeFrictCompens();
   THRSERVO_vidFiltering();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidFrictionDetection                              */
/* !Description :  Ce bloc défini la détection d’accrochage du papillon dû à  */
/*                 des frottements secs.                                      */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Tpac_state_ctl_position_error;                               */
/*  input uint16 Tpac_frict_null_err_thresh;                                  */
/*  input sint16 Tpac_state_ctl_est_velocity;                                 */
/*  input sint16 Tpac_frict_thr_vel_thresh;                                   */
/*  input uint16 Tpac_frict_lh_area_sup;                                      */
/*  input sint16 Tpac_dist_to_limp_home;                                      */
/*  input uint16 Tpac_frict_lh_area_inf;                                      */
/*  input uint16 Tpac_frict_err_pos_thresh;                                   */
/*  output boolean Tpac_frict_reset;                                          */
/*  output boolean Tpac_frict_ris_set;                                        */
/*  output boolean Tpac_frict_fal_set;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidFrictionDetection(void)
{
   /* Friction_detection */
   sint16 s16LocalTpac_stat_ctl_pos_err;


   VEMS_vidGET(Tpac_state_ctl_position_error, s16LocalTpac_stat_ctl_pos_err);
   if ( MATHSRV_udtABS(s16LocalTpac_stat_ctl_pos_err)
      < Tpac_frict_null_err_thresh)
   {
      Tpac_frict_reset = 1;
   }
   else
   {
      Tpac_frict_reset = 0;
   }

   if (  ( MATHSRV_udtABS(Tpac_state_ctl_est_velocity)
         < Tpac_frict_thr_vel_thresh)
      && (  (Tpac_frict_lh_area_sup < Tpac_dist_to_limp_home)
         || (Tpac_dist_to_limp_home < (- (sint32)Tpac_frict_lh_area_inf) )))
   {
      if (s16LocalTpac_stat_ctl_pos_err < Tpac_frict_err_pos_thresh)
      {
         Tpac_frict_ris_set = 1;
      }
      else
      {
         Tpac_frict_ris_set = 0;
      }
      if (s16LocalTpac_stat_ctl_pos_err < (-(sint32)Tpac_frict_err_pos_thresh))
      {
         Tpac_frict_fal_set = 1;
      }
      else
      {
         Tpac_frict_fal_set = 0;
      }
   }
   else
   {
      Tpac_frict_ris_set = 0;
      Tpac_frict_fal_set = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidFrictConstCounter                              */
/* !Description :  Ce bloc décompte des temporisation avant l'activation ou la*/
/*                 désactivation de la stratégie de compensation des          */
/*                 frottements secs.                                          */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Tpac_frict_ris_set;                                         */
/*  input uint8 Tpac_frict_ris_count;                                         */
/*  input uint8 Tpac_frict_set_delay;                                         */
/*  input boolean Tpac_frict_fal_set;                                         */
/*  input uint8 Tpac_frict_fal_count;                                         */
/*  input boolean Tpac_frict_reset;                                           */
/*  input uint8 Tpac_frict_reset_count;                                       */
/*  input uint8 Tpac_frict_reset_delay;                                       */
/*  output uint8 Tpac_frict_ris_count;                                        */
/*  output boolean Tpac_frict_ris_set_enab;                                   */
/*  output uint8 Tpac_frict_fal_count;                                        */
/*  output boolean Tpac_frict_fal_set_enab;                                   */
/*  output uint8 Tpac_frict_reset_count;                                      */
/*  output boolean Tpac_frict_reset_enab;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidFrictConstCounter(void)
{
   /* Frict_const_counter */
   if (Tpac_frict_ris_set != 0)
   {
      if (Tpac_frict_ris_count > 0)
      {
         Tpac_frict_ris_count = (uint8)(Tpac_frict_ris_count - 1);
      }
   }
   else
   {
      Tpac_frict_ris_count = Tpac_frict_set_delay;
   }
   if (Tpac_frict_ris_count == 0)
   {
      Tpac_frict_ris_set_enab = 1;
   }
   else
   {
      Tpac_frict_ris_set_enab = 0;
   }

   if (Tpac_frict_fal_set != 0)
   {
      if (Tpac_frict_fal_count > 0)
      {
         Tpac_frict_fal_count = (uint8)(Tpac_frict_fal_count - 1);
      }
   }
   else
   {
      Tpac_frict_fal_count = Tpac_frict_set_delay;
   }
   if (Tpac_frict_fal_count == 0)
   {
      Tpac_frict_fal_set_enab = 1;
   }
   else
   {
      Tpac_frict_fal_set_enab = 0;
   }

   if (Tpac_frict_reset != 0)
   {
      if (Tpac_frict_reset_count > 0)
      {
         Tpac_frict_reset_count = (uint8)(Tpac_frict_reset_count - 1);
      }
   }
   else
   {
      Tpac_frict_reset_count = Tpac_frict_reset_delay;
   }
   if (Tpac_frict_reset_count == 0)
   {
      Tpac_frict_reset_enab = 1;
   }
   else
   {
      Tpac_frict_reset_enab = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidSetFrictStatus                                 */
/* !Description :  Automate de la stratégie de frottements secs.              */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st04 Tpac_frict_status;                                             */
/*  input boolean Tpac_frict_ris_set_enab;                                    */
/*  input bool TPAC_FRICT_RIS;                                                */
/*  input boolean Tpac_frict_fal_set_enab;                                    */
/*  input bool TPAC_FRICT_FAL;                                                */
/*  input bool TPAC_FRICT_ADHER;                                              */
/*  input boolean Tpac_frict_reset_enab;                                      */
/*  output st04 Tpac_frict_status;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidSetFrictStatus(void)
{
   /* set_frict_status */
   switch (Tpac_frict_status)
   {
      case TPAC_FRICT_ADHER:
         if (Tpac_frict_ris_set_enab != 0)
         {
            Tpac_frict_status = TPAC_FRICT_RIS;
         }
         else
         {
            if (Tpac_frict_fal_set_enab != 0)
            {
               Tpac_frict_status = TPAC_FRICT_FAL;
            }
         }
         break;

      case TPAC_FRICT_RIS:
         if (  (Tpac_frict_reset_enab   != 0)
            || (Tpac_frict_fal_set_enab != 0) )
         {
            Tpac_frict_status = TPAC_FRICT_ADHER;
         }
         break;

      case TPAC_FRICT_FAL:
         if (  (Tpac_frict_reset_enab   != 0)
            || (Tpac_frict_ris_set_enab != 0) )
         {
            Tpac_frict_status = TPAC_FRICT_ADHER;
         }
         break;

      default:
         Tpac_frict_status = TPAC_FRICT_ADHER;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidComputeFrictCompens                            */
/* !Description :  Ce module calcul la valeur du feedforward à appliquer sur  */
/*                 la commande afin de compenser les frottements secs. Cette  */
/*                 compensation est réalisée en considérant le couple de      */
/*                 frottements secs comme une tension.                        */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input st04 Tpac_frict_status;                                             */
/*  input bool TPAC_FRICT_RIS;                                                */
/*  input bool TPAC_FRICT_FAL;                                                */
/*  input sint16 Tpac_frict_pos_bkpt_map[6];                                  */
/*  input sint16 Tpac_dist_to_limp_home;                                      */
/*  input uint16 Tpac_frict_falling_map[6];                                   */
/*  input uint16 Tpac_frict_rising_map[6];                                    */
/*  input sint16 Tpac_state_ctl_est_velocity;                                 */
/*  input uint16 Tpac_frict_null_spd_thresh;                                  */
/*  input uint8 Tpac_frict_null_spd_gain;                                     */
/*  output sint16 Tpac_frict_ff_comp_volt_raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidComputeFrictCompens(void)
{
   /* Compute_friction_compensation */
   uint8  u8LocalIndex;
   uint16 u16LocalGain;
   uint16 u16LocalPara;
   uint16 u16LocalLimpHome;
   uint16 u16LocalBkpt[6];
   /*Msg(2:3132) Hard coded 'magic' number '6' used to define the size of an  */
   /* array.                                                                  */
   /* This message is only generated for constants which are used to define   */
   /* the size of an array. It is usually better practice to use a macro      */
   /* constant which can be defined in an appropriate location where it is    */
   /* easily reviewed and maintained => Dans notre cas, la table est déclarée */
   /* en locale, donc on ne peut pas   déclarer  sa    dimension     comme    */
   /* étant un Define.                                                        */
   sint16 s16LocalVoltage;
   sint32 s32LocalTpac_frict;


   if (  (Tpac_frict_status != TPAC_FRICT_RIS)
      && (Tpac_frict_status != TPAC_FRICT_FAL) )
   {
      s16LocalVoltage = 0;
      u16LocalGain = 0;
   }
   else
   {
      for (u8LocalIndex = 0;u8LocalIndex < 6;u8LocalIndex++)
      {
         u16LocalBkpt[u8LocalIndex] =
            (uint16)(Tpac_frict_pos_bkpt_map[u8LocalIndex] + 32768);
      }
      u16LocalLimpHome = (uint16)(Tpac_dist_to_limp_home + 32768);
      u16LocalPara = MATHSRV_u16CalcParaIncAryU16Loc(u16LocalBkpt,
                                                     u16LocalLimpHome,
                                                     5);
      if (Tpac_frict_status ==  TPAC_FRICT_FAL)
      {
         s16LocalVoltage = (sint16)( MATHSRV_u16Interp1d(Tpac_frict_falling_map,
                                                         u16LocalPara)
                                   - 32768 );
      }
      else
      {
         s16LocalVoltage = (sint16)( MATHSRV_u16Interp1d(Tpac_frict_rising_map,
                                                         u16LocalPara)
                                   - 32768 );
      }

      if ( (uint16)MATHSRV_udtABS(Tpac_state_ctl_est_velocity)
         < Tpac_frict_null_spd_thresh)
      {
         u16LocalGain = (uint16)(Tpac_frict_null_spd_gain + 255);
      }
      else
      {
         u16LocalGain = 255;
      }
   }
   s32LocalTpac_frict = (sint32)((s16LocalVoltage * u16LocalGain) / 255);
   Tpac_frict_ff_comp_volt_raw =
      (sint16)MATHSRV_udtCLAMP( s32LocalTpac_frict, SINT16_MIN, SINT16_MAX );
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidFiltering                                      */
/* !Description :  Ce bloc applique un filtrage de la consigne de feedforward.*/
/* !Number      :  FCT4.6                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVO_vidFiltCompensFeedBack();                       */
/*  input sint16 Tpac_frict_ff_comp_volt_raw;                                 */
/*  input sint16 Tpac_frict_ff_comp_voltage;                                  */
/*  input uint8 Tpac_frict_ff_gain_dec;                                       */
/*  input uint8 Tpac_frict_ff_gain_inc;                                       */
/*  input boolean Tpac_throttle_select;                                       */
/*  output sint16 Tpac_frict_ff_comp_voltage;                                 */
/*  output sint16 Tpac_frict_ff_comp_volt_filt;                               */
/*  output sint16 THRSERVO_s16FrictFFCompVoltPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidFiltering(void)
{
   /* filtrage */
   sint16 s16LocalVoltage;
   sint32 s32LocalVoltage;


   if (Tpac_frict_ff_comp_volt_raw == 0)
   {
      s16LocalVoltage = (sint16)( ( Tpac_frict_ff_comp_voltage
                                  * Tpac_frict_ff_gain_dec)
                                / 255);
   }
   else
   {
      s32LocalVoltage = (sint32)( Tpac_frict_ff_comp_voltage
                                + ( ( Tpac_frict_ff_comp_volt_raw
                                    * Tpac_frict_ff_gain_inc)
                                  / 255) );
      s16LocalVoltage = (sint16)MATHSRV_udtCLAMP(s32LocalVoltage,
                                                 SINT16_MIN,
                                                 SINT16_MAX );
      if (s16LocalVoltage >= 0)
      {
         s16LocalVoltage = (sint16)MATHSRV_udtMIN(Tpac_frict_ff_comp_volt_raw,
                                                  s16LocalVoltage);
      }
      else
      {
         s16LocalVoltage = (sint16)MATHSRV_udtMAX(Tpac_frict_ff_comp_volt_raw,
                                                  s16LocalVoltage);
      }
   }

   Tpac_frict_ff_comp_voltage = s16LocalVoltage;
   if (Tpac_throttle_select != 0)
   {
      THRSERVO_vidFiltCompensFeedBack();
   }
   else
   {
      Tpac_frict_ff_comp_volt_filt = s16LocalVoltage;
   }
   THRSERVO_s16FrictFFCompVoltPrev = Tpac_frict_ff_comp_voltage;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVO_vidFiltCompensFeedBack                            */
/* !Description :  Ce bloc applique un filtrage de la consigne de feedforward.*/
/*                 L'idée est de compenser les effets induits par le retour   */
/*                 d'état en courant.                                         */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  A. BENAMAR                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 Tpac_frict_ff_comp_volt_filt;                                */
/*  input uint8 Tpac_frict_ff_filt_gain_s1;                                   */
/*  input sint16 THRSERVO_s16FrictFFCompVoltPrev;                             */
/*  input uint8 Tpac_frict_ff_filt_gain_e1;                                   */
/*  input sint16 Tpac_frict_ff_comp_voltage;                                  */
/*  output sint16 Tpac_frict_ff_comp_volt_filt;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVO_vidFiltCompensFeedBack(void)
{
   /* filtre_comp_retour_etat  */
   sint32 s32LocalFilt;


   s32LocalFilt = (sint32)( ( ( ( Tpac_frict_ff_comp_volt_filt
                                * Tpac_frict_ff_filt_gain_s1)
                              - ( THRSERVO_s16FrictFFCompVoltPrev
                                * Tpac_frict_ff_filt_gain_e1) )
                            + 128)
                          / 256);
   s32LocalFilt = s32LocalFilt + Tpac_frict_ff_comp_voltage;

   Tpac_frict_ff_comp_volt_filt = (sint16)MATHSRV_udtCLAMP(s32LocalFilt,
                                                           SINT16_MIN,
                                                           SINT16_MAX );
}

/*------------------------------- end of file --------------------------------*/