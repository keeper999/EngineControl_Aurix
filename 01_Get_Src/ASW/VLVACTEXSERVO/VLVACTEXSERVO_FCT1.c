/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXSERVO                                           */
/* !Description     : VLVACTEXSERVO Component                                 */
/*                                                                            */
/* !Module          : VLVACTEXSERVO                                           */
/* !Description     : Asservissement du decalage VVT echappement              */
/*                                                                            */
/* !File            : VLVACTEXSERVO_FCT1.C                                    */
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
/*   1 / VLVACTEXSERVO_vidInitRst                                             */
/*   2 / VLVACTEXSERVO_vidInitOutput                                          */
/*   3 / VLVACTEXSERVO_vidInitIntegral                                        */
/*   4 / VLVACTEXSERVO_vidCalPeakToPNoise                                     */
/*   5 / VLVACTEXSERVO_vidLearnNoise                                          */
/*   6 / VLVACTEXSERVO_vidInitialize                                          */
/*   7 / VLVACTEXSERVO_vidSetpVelocity                                        */
/*   8 / VLVACTEXSERVO_vidSelDutyCycl                                         */
/*   9 / VLVACTEXSERVO_vidSelectPWM                                           */
/*   10 / VLVACTEXSERVO_vidInitFailure                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5060920 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068045                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXSERVO/VLVACTEXS$*/
/* $Revision::   1.8      $$Author::   etsasson       $$Date::   22 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   22 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXSERVO.h"
#include "VLVACTEXSERVO_L.h"
#include "VLVACTEXSERVO_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidInitRst                                   */
/* !Description :  Initialisation des variables au reset.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Kfvcpe_initial_current_int;                                  */
/*  input uint8 Vta_exhaust_int_failure_delay;                                */
/*  input uint8 Vta_exhaust_block_failure_delay;                              */
/*  output uint16 Vcpe_current_integral;                                      */
/*  output uint8 Vta_exhaust_int_failure_tempo;                               */
/*  output uint8 Vta_exhaust_block_failure_tempo;                             */
/*  output uint8 Vcpe_edge_count;                                             */
/*  output uint8 Vcpe_low_peak_noise;                                         */
/*  output uint8 Vcpe_high_peak_noise;                                        */
/*  output boolean Vcpe_initial_integral_is_lrnd;                             */
/*  output uint8 Vcpe_noise_count;                                            */
/*  output boolean Vcpe_noise_is_learned;                                     */
/*  output boolean Vbx_pf_vvt_exhaust_blk;                                    */
/*  output boolean Vbx_pf_vvt_exhaust_int;                                    */
/*  output uint16 Vcpe_integral_value;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidInitRst(void)
{
   uint16  u16LocalExhaust_failure_tempo;

   Vcpe_current_integral = (uint16)MATHSRV_udtMIN(
                                      Kfvcpe_initial_current_int,
                                      1023);
   Vta_exhaust_int_failure_tempo = Vta_exhaust_int_failure_delay;
   u16LocalExhaust_failure_tempo =
      (uint16)(Vta_exhaust_block_failure_delay * 10);
   Vta_exhaust_block_failure_tempo =
      (uint8)MATHSRV_udtMIN(u16LocalExhaust_failure_tempo, 255);
   Vcpe_edge_count = 0;
   Vcpe_low_peak_noise = 0;
   Vcpe_high_peak_noise = 0;
   Vcpe_initial_integral_is_lrnd = 0;
   Vcpe_noise_count = 0;
   Vcpe_noise_is_learned = 0;
   Vbx_pf_vvt_exhaust_blk = 0;
   Vbx_pf_vvt_exhaust_int = 0;
   VEMS_vidSET(Vcpe_integral_value, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidInitOutput                                */
/* !Description :  Initialisation des variables produites.                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input uint16 VLVACTEXSERVO_u16OutputFilter;                               */
/*  output uint16 Consigne_rco_vvt_echap;                                     */
/*  output sint16 Vcpe_cam_position_error;                                    */
/*  output boolean VlvAct_bAcvExServo;                                        */
/*  output boolean Vcpe_learning_finished;                                    */
/*  output uint16 VLVACTEXSERVO_u16OutputFilter;                              */
/*  output uint32 VLVACTEXSERVO_u32FilterKMem;                                */
/*  output boolean VLVACTEXSERVO_bHysteresisOutput;                           */
/*  output boolean VLVACTEXSERVO_bHystOutput;                                 */
/*  output uint16 Vcpe_integral_val_initMem;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidInitOutput(void)
{
   uint16 u16LocalVxx_vvtc_ex_angl_sp;


   VEMS_vidSET(Consigne_rco_vvt_echap, 0);
   VEMS_vidSET(Vcpe_cam_position_error, 0);
   VEMS_vidSET(VlvAct_bAcvExServo, 0);
   VEMS_vidSET(Vcpe_learning_finished, 0);
   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxx_vvtc_ex_angl_sp);
   VLVACTEXSERVO_u16OutputFilter =
      (uint16)MATHSRV_udtMIN(u16LocalVxx_vvtc_ex_angl_sp, 1066);
   VLVACTEXSERVO_u32FilterKMem =
      (uint32)(VLVACTEXSERVO_u16OutputFilter * 65536);
   VLVACTEXSERVO_bHysteresisOutput = 0;
   VLVACTEXSERVO_bHystOutput = 0;
   Vcpe_integral_val_initMem = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidInitIntegral                              */
/* !Description :  L'action intégrale est active à l'intérieur d'une bande    */
/*                 (Vta_exhaust_band), dans cette bande on actualise la valeur*/
/*                 intégrale (qui suit les variations lentes du RCO           */
/*                 d'équilibre)                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXSERVO_vidCalPeakToPNoise();                      */
/*  extf argret void VLVACTEXSERVO_vidInitialize();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bExServoEna;                                         */
/*  input boolean Vcpe_noise_is_learned;                                      */
/*  input boolean Vcpe_initial_integral_is_lrnd;                              */
/*  output boolean Vcpe_learning_finished;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidInitIntegral(void)
{
   boolean bLocalVlvAct_bExServoEna;


   VEMS_vidGET(VlvAct_bExServoEna, bLocalVlvAct_bExServoEna);
   if ( bLocalVlvAct_bExServoEna != 0)
   {
      if (Vcpe_noise_is_learned == 0)
      {
         VLVACTEXSERVO_vidCalPeakToPNoise();
      }

      if (  (Vcpe_noise_is_learned != 0)
         && (Vcpe_initial_integral_is_lrnd == 0))
      {
         VLVACTEXSERVO_vidInitialize();
      }
   }
   if(  (Vcpe_noise_is_learned !=0)
     && (Vcpe_initial_integral_is_lrnd != 0))
   {
      VEMS_vidSET(Vcpe_learning_finished, 1);
   }
   else
   {
      VEMS_vidSET(Vcpe_learning_finished, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidCalPeakToPNoise                           */
/* !Description :  On commande le système sur sa butée basse et on relève les */
/*                 mesures min et max. Au bout de Kfvcpe_noise_learn_count    */
/*                 mesures on fait la différence entre le max et le min et on */
/*                 obtient le bruit de mesure.                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXSERVO_vidLearnNoise();                           */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint8 Vcpe_noise_count;                                             */
/*  input uint8 Vcpe_high_peak_noise;                                         */
/*  input uint8 Vcpe_low_peak_noise;                                          */
/*  input uint16 Kfvcpe_noise_learn_count;                                    */
/*  output uint8 Vcpe_high_peak_noise;                                        */
/*  output uint8 Vcpe_low_peak_noise;                                         */
/*  output uint8 Vcpe_noise_count;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidCalPeakToPNoise(void)
{
   uint8   u8LocalMin;
   uint16  u16Localsum;
   uint16  u16LocalVlvAct_agCmExPosnEstim;


   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
   if (Vcpe_noise_count == 0)
   {
      Vcpe_high_peak_noise =
         (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmExPosnEstim,106));
      Vcpe_low_peak_noise  =
         (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmExPosnEstim,106));
   }
   else
   {
      if (u16LocalVlvAct_agCmExPosnEstim > Vcpe_high_peak_noise)
      {
         Vcpe_high_peak_noise =
            (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmExPosnEstim,106));
      }
      u8LocalMin  = (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmExPosnEstim,
                                           Vcpe_low_peak_noise));
      Vcpe_low_peak_noise  = (uint8)(MATHSRV_udtMIN(u8LocalMin, 106));
   }
   u16Localsum = (uint16)(Vcpe_noise_count + 1);
   Vcpe_noise_count = (uint8)MATHSRV_udtMIN(u16Localsum,100);

   if (Vcpe_noise_count >= Kfvcpe_noise_learn_count)
   {
      VLVACTEXSERVO_vidLearnNoise();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidLearnNoise                                */
/* !Description :  Au bout de Kfvcpe_noise_learn_count mesures on fait la     */
/*                 différence entre le max et le min et on obtient le bruit de*/
/*                 mesure.                                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Kfvcpe_noise_learn_count;                                    */
/*  input uint8 Kfvcpe_phi_peak_to_peak_noise;                                */
/*  input uint8 Vcpe_high_peak_noise;                                         */
/*  input uint8 Vcpe_low_peak_noise;                                          */
/*  output uint8 Vcpe_peak_to_peak_noise;                                     */
/*  output boolean Vcpe_noise_is_learned;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidLearnNoise(void)
{
   sint16 s16Localpeaknoise;


   if (Kfvcpe_noise_learn_count == 0)
   {
      Vcpe_peak_to_peak_noise =
         (uint8)MATHSRV_udtMIN(Kfvcpe_phi_peak_to_peak_noise, 106);
   }
   else
   {
      s16Localpeaknoise = (sint16)(Vcpe_high_peak_noise - Vcpe_low_peak_noise);
      Vcpe_peak_to_peak_noise =
         (uint8)MATHSRV_udtCLAMP(s16Localpeaknoise, 0, 106);
   }
   Vcpe_noise_is_learned = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidInitialize                                */
/* !Description :  Dans le cadre de l’apprentissage de la valeur RCO          */
/*                 d’équilibre, on incrémente la commande et on teste si il y */
/*                 a eu du mouvement.                                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint8 Vcpe_peak_to_peak_noise;                                      */
/*  input uint16 Vcpe_current_integral;                                       */
/*  input uint16 Vta_exhaust_init_max_int_value;                              */
/*  input uint16 Kfvcpe_initial_int_step_size;                                */
/*  input uint8 Vcpe_edge_count;                                              */
/*  input uint16 Vcpe_integral_value;                                         */
/*  input uint8 Kfvcpe_set_edge_count;                                        */
/*  output boolean Vcpe_initial_integral_is_lrnd;                             */
/*  output uint16 Vcpe_integral_value;                                        */
/*  output uint16 Vcpe_integral_val_initMem;                                  */
/*  output uint16 Vcpe_current_integral;                                      */
/*  output uint8 Vcpe_edge_count;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidInitialize(void)
{
   uint16 u16LocaledgeCount;
   uint16 u16LocalVlvAct_agCmExPosnEstim;
   uint16 u16LocalVcpe_integral_value;
   uint32 u32LocalCurInt;
   sint32 s32LocalCurrentValue;
   sint32 s32LocalIntegValue;


   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
   if ( ((Vcpe_peak_to_peak_noise * 2) < u16LocalVlvAct_agCmExPosnEstim)
      || (Vcpe_current_integral > Vta_exhaust_init_max_int_value))
   {
      Vcpe_initial_integral_is_lrnd = 1;
      s32LocalIntegValue = 64 * ( Vcpe_current_integral
                                - Kfvcpe_initial_int_step_size);
      u16LocalVcpe_integral_value =
               (uint16)MATHSRV_udtCLAMP(s32LocalIntegValue,
                                         0,
                                         65535);
      VEMS_vidSET(Vcpe_integral_value, u16LocalVcpe_integral_value);
      Vcpe_integral_val_initMem = u16LocalVcpe_integral_value;
      s32LocalCurrentValue = (sint32)(Vcpe_current_integral -
                                      Kfvcpe_initial_int_step_size);
      Vcpe_current_integral = (uint16)MATHSRV_udtCLAMP(s32LocalCurrentValue,
                                                        0, 1023);
      u16LocaledgeCount = Vcpe_edge_count;
   }
   else
   {
      Vcpe_initial_integral_is_lrnd = 0;
      VEMS_vidGET(Vcpe_integral_value, u16LocalVcpe_integral_value);
      Vcpe_integral_val_initMem = u16LocalVcpe_integral_value;
      if (Vcpe_edge_count < Kfvcpe_set_edge_count)
      {
         u16LocaledgeCount = (uint16)(Vcpe_edge_count + 1);
      }
      else
      {
         u32LocalCurInt = Vcpe_current_integral + Kfvcpe_initial_int_step_size;
         Vcpe_current_integral = (uint16)MATHSRV_udtMIN(u32LocalCurInt,1023);
         u16LocaledgeCount = 0;
      }
   }
   Vcpe_edge_count = (uint8)MATHSRV_udtMIN(u16LocaledgeCount,200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidSetpVelocity                              */
/* !Description :  Fonction qui calcule la dérivée de la  consigne  utilisée  */
/*                 par l'action dérivée de l'asservissement VVT.              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input uint16 Vxx_vvtc_ex_angl_sp_prev;                                    */
/*  output sint16 Vta_exhaust_speed_sp;                                       */
/*  output uint16 Vxx_vvtc_ex_angl_sp_prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidSetpVelocity(void)
{
   uint16  u16LocalVxx_vvtc_ex_angl_sp;
   sint32  s32LocalDiffValue;


   VEMS_vidGET(Vxx_vvtc_ex_angl_sp,u16LocalVxx_vvtc_ex_angl_sp);
   s32LocalDiffValue = (sint32)( u16LocalVxx_vvtc_ex_angl_sp
                               - Vxx_vvtc_ex_angl_sp_prev);
   s32LocalDiffValue = ( (s32LocalDiffValue* 1000)
                       / (sint32)VlvAct_SampleTiFast_SC);
   Vta_exhaust_speed_sp =
      (sint16)MATHSRV_udtCLAMP(s32LocalDiffValue, -5333, 5333);
   Vxx_vvtc_ex_angl_sp_prev = u16LocalVxx_vvtc_ex_angl_sp;

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidSelDutyCycl                               */
/* !Description :  fonction de Selection de Duty_Cycle                        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXSERVO_vidSelectPWM();                            */
/*  input boolean VlvAct_bExServoEna;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidSelDutyCycl(void)
{
   boolean bLocalVlvAct_bExServoEna;


   VEMS_vidGET(VlvAct_bExServoEna, bLocalVlvAct_bExServoEna);
   if ( bLocalVlvAct_bExServoEna != 0)
   {
      VLVACTEXSERVO_vidSelectPWM();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidSelectPWM                                 */
/* !Description :  Choix du RCO à appliquer: apprentissage initial du RCO     */
/*                 d'équilibre, mode banc, valeur RCO issue du régulateur PID.*/
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cbx_vvtc_pwm_bch2;                                          */
/*  input uint16 Cxx_vvtc_pwm_bch2;                                           */
/*  input boolean Vcpe_initial_integral_is_lrnd;                              */
/*  input uint16 Vcpe_pid_duty_cycle;                                         */
/*  input uint16 Vcpe_current_integral;                                       */
/*  output uint16 Consigne_rco_vvt_echap;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidSelectPWM(void)
{
   uint16 u16LocalConsRcoVvt;
   uint16 u16LocalConsigne_rco_vvt_echap;


   if (Cbx_vvtc_pwm_bch2 != 0)
   {
      u16LocalConsRcoVvt = Cxx_vvtc_pwm_bch2;
   }
   else
   {
      if (Vcpe_initial_integral_is_lrnd != 0)
      {
         u16LocalConsRcoVvt = Vcpe_pid_duty_cycle;
      }
      else
      {
         u16LocalConsRcoVvt = Vcpe_current_integral;
      }
   }
   u16LocalConsigne_rco_vvt_echap = (uint16)MATHSRV_udtMIN(u16LocalConsRcoVvt,
                                                           1023);
   VEMS_vidSET(Consigne_rco_vvt_echap, u16LocalConsigne_rco_vvt_echap);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidInitFailure                               */
/* !Description :  Les pannes présentes sont initialisées sur clé off --> on  */
/*                 afin qu’elles ne restent pas figées à ON entre le clé off  */
/*                 --> on et le démarrage du moteur.                          */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Vbx_pf_vvt_exhaust_blk;                                    */
/*  output boolean Vbx_pf_vvt_exhaust_int;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidInitFailure(void)
{
   Vbx_pf_vvt_exhaust_blk = 0;
   Vbx_pf_vvt_exhaust_int = 0;
}
/*-------------------------------end of file----------------------------------*/