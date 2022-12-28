/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINSERVO                                           */
/* !Description     : VLVACTINSERVO Component                                 */
/*                                                                            */
/* !Module          : VLVACTINSERVO                                           */
/* !Description     : Asservissement du decalage VVT admission                */
/*                                                                            */
/* !File            : VLVACTINSERVO_FCT1.C                                    */
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
/*   1 / VLVACTINSERVO_vidInitRst                                             */
/*   2 / VLVACTINSERVO_vidInitOutput                                          */
/*   3 / VLVACTINSERVO_vidInitIntegral                                        */
/*   4 / VLVACTINSERVO_vidCalPeakToPNoise                                     */
/*   5 / VLVACTINSERVO_vidLearnNoise                                          */
/*   6 / VLVACTINSERVO_vidInitialize                                          */
/*   7 / VLVACTINSERVO_vidSetpVelocity                                        */
/*   8 / VLVACTINSERVO_vidSelDutyCycl                                         */
/*   9 / VLVACTINSERVO_vidSelectPWM                                           */
/*   10 / VLVACTINSERVO_vidInitFailure                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5060915 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068046                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINSERVO/VLVACTINS$*/
/* $Revision::   1.8      $$Author::   etsasson       $$Date::   22 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   22 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINSERVO.h"
#include "VLVACTINSERVO_L.h"
#include "VLVACTINSERVO_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidInitRst                                   */
/* !Description :  Initialisation des variables au reset.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Kfvcpi_initial_current_int;                                  */
/*  input uint8 Vta_intake_int_failure_delay;                                 */
/*  input uint8 Vta_intake_block_failure_delay;                               */
/*  output uint16 Vcpi_current_integral;                                      */
/*  output uint8 Vta_intake_int_failure_tempo;                                */
/*  output uint8 Vta_intake_block_failure_tempo;                              */
/*  output uint8 Vcpi_edge_count;                                             */
/*  output uint8 Vcpi_low_peak_noise;                                         */
/*  output uint8 Vcpi_high_peak_noise;                                        */
/*  output boolean Vcpi_initial_integral_is_lrnd;                             */
/*  output uint8 Vcpi_noise_count;                                            */
/*  output boolean Vcpi_noise_is_learned;                                     */
/*  output boolean Vbx_pf_vvt_intake_blk;                                     */
/*  output boolean Vbx_pf_vvt_intake_int;                                     */
/*  output uint16 Vcpi_integral_value;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidInitRst(void)
{
   uint16  u16LocalIntake_failure_tempo;

   Vcpi_current_integral = (uint16)MATHSRV_udtMIN(
                                      Kfvcpi_initial_current_int,
                                      1023);
   Vta_intake_int_failure_tempo = Vta_intake_int_failure_delay;
   u16LocalIntake_failure_tempo =
      (uint16)(Vta_intake_block_failure_delay * 10);
   Vta_intake_block_failure_tempo =
      (uint8)MATHSRV_udtMIN(u16LocalIntake_failure_tempo, 255);
   Vcpi_edge_count = 0;
   Vcpi_low_peak_noise = 0;
   Vcpi_high_peak_noise = 0;
   Vcpi_initial_integral_is_lrnd = 0;
   Vcpi_noise_count = 0;
   Vcpi_noise_is_learned = 0;
   Vbx_pf_vvt_intake_blk = 0;
   Vbx_pf_vvt_intake_int = 0;
   VEMS_vidSET(Vcpi_integral_value, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidInitOutput                                */
/* !Description :  Initialisation des variables produites.                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 VLVACTINSERVO_u16OutputFilter;                               */
/*  output uint16 Consigne_rco_vvt_adm;                                       */
/*  output sint16 Vcpi_cam_position_error;                                    */
/*  output boolean VlvAct_bAcvInServo;                                        */
/*  output boolean Vcpi_learning_finished;                                    */
/*  output uint16 VLVACTINSERVO_u16OutputFilter;                              */
/*  output uint32 VLVACTINSERVO_u32FilterKMem;                                */
/*  output boolean VLVACTINSERVO_bHysteresisOutput;                           */
/*  output boolean VLVACTINSERVO_bHystOutput;                                 */
/*  output uint16 Vcpi_integral_val_initMem;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidInitOutput(void)
{
   uint16 u16LocalVxx_vvtc_in_angl_sp;


   VEMS_vidSET(Consigne_rco_vvt_adm, 0);
   VEMS_vidSET(Vcpi_cam_position_error, 0);
   VEMS_vidSET(VlvAct_bAcvInServo, 0);
   VEMS_vidSET(Vcpi_learning_finished, 0);
   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxx_vvtc_in_angl_sp);
   VLVACTINSERVO_u16OutputFilter =
      (uint16)MATHSRV_udtMIN(u16LocalVxx_vvtc_in_angl_sp, 1066);
   VLVACTINSERVO_u32FilterKMem =
      (uint32)(VLVACTINSERVO_u16OutputFilter * 65536);
   VLVACTINSERVO_bHysteresisOutput = 0;
   VLVACTINSERVO_bHystOutput = 0;
   Vcpi_integral_val_initMem = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidInitIntegral                              */
/* !Description :  L'action intégrale est active à l'intérieur d'une bande    */
/*                 (Vta_intake_band), dans cette bande on actualise la valeur */
/*                 intégrale (qui suit les variations lentes du RCO           */
/*                 d'équilibre)                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINSERVO_vidCalPeakToPNoise();                      */
/*  extf argret void VLVACTINSERVO_vidInitialize();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bInServoEna;                                         */
/*  input boolean Vcpi_noise_is_learned;                                      */
/*  input boolean Vcpi_initial_integral_is_lrnd;                              */
/*  output boolean Vcpi_learning_finished;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidInitIntegral(void)
{
   boolean bLocalVlvAct_bInServoEna;
   boolean bLocalVcpi_learning_finished;


   VEMS_vidGET(VlvAct_bInServoEna, bLocalVlvAct_bInServoEna);
   if ( bLocalVlvAct_bInServoEna != 0)
   {
      if (Vcpi_noise_is_learned == 0)
      {
         VLVACTINSERVO_vidCalPeakToPNoise();
      }

      if (  (Vcpi_noise_is_learned != 0)
         && (Vcpi_initial_integral_is_lrnd == 0))
      {
         VLVACTINSERVO_vidInitialize();
      }
   }
   if(  (Vcpi_noise_is_learned !=0)
     && (Vcpi_initial_integral_is_lrnd != 0))
   {
      bLocalVcpi_learning_finished = 1;
   }
   else
   {
      bLocalVcpi_learning_finished = 0;
   }
   VEMS_vidSET(Vcpi_learning_finished, bLocalVcpi_learning_finished);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidCalPeakToPNoise                           */
/* !Description :  On commande le système sur sa butée basse  et on relève les*/
/*                 mesures min et max. Au bout de Kfvcpi_noise_learn_count    */
/*                 mesures on fait la différence entre le max et le min et on */
/*                 obtient le bruit de mesure.                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINSERVO_vidLearnNoise();                           */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint8 Vcpi_noise_count;                                             */
/*  input uint8 Vcpi_high_peak_noise;                                         */
/*  input uint8 Vcpi_low_peak_noise;                                          */
/*  input uint16 Kfvcpi_noise_learn_count;                                    */
/*  output uint8 Vcpi_high_peak_noise;                                        */
/*  output uint8 Vcpi_low_peak_noise;                                         */
/*  output uint8 Vcpi_noise_count;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidCalPeakToPNoise(void)
{
   uint8   u8LocalMin;
   uint16  u16Localsum;
   uint16  u16LocalVlvAct_agCmInPosnEstim;


   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
   if (Vcpi_noise_count == 0)
   {
      Vcpi_high_peak_noise =
         (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmInPosnEstim,106));
      Vcpi_low_peak_noise  =
         (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmInPosnEstim,106));
   }
   else
   {
      if (u16LocalVlvAct_agCmInPosnEstim > Vcpi_high_peak_noise)
      {
         Vcpi_high_peak_noise =
            (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmInPosnEstim,106));
      }

      u8LocalMin  = (uint8)(MATHSRV_udtMIN(u16LocalVlvAct_agCmInPosnEstim,
                                           Vcpi_low_peak_noise));
      Vcpi_low_peak_noise = (uint8)(MATHSRV_udtMIN(u8LocalMin,106));
   }
   u16Localsum = (uint16)(Vcpi_noise_count + 1);
   Vcpi_noise_count = (uint8)MATHSRV_udtMIN(u16Localsum, 100);
   if (Vcpi_noise_count >= Kfvcpi_noise_learn_count)
   {
      VLVACTINSERVO_vidLearnNoise();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidLearnNoise                                */
/* !Description :  Au bout de Kfvcpi_noise_learn_count mesures on fait la     */
/*                 différence entre le max et le min et on obtient le bruit de*/
/*                 mesure.                                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Kfvcpi_noise_learn_count;                                    */
/*  input uint8 Kfvcpi_phi_peak_to_peak_noise;                                */
/*  input uint8 Vcpi_high_peak_noise;                                         */
/*  input uint8 Vcpi_low_peak_noise;                                          */
/*  output uint8 Vcpi_peak_to_peak_noise;                                     */
/*  output boolean Vcpi_noise_is_learned;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidLearnNoise(void)
{
   sint16 s16Localpeaknoise;


   if (Kfvcpi_noise_learn_count == 0)
   {
      Vcpi_peak_to_peak_noise =
         (uint8)MATHSRV_udtMIN(Kfvcpi_phi_peak_to_peak_noise, 106);
   }
   else
   {
      s16Localpeaknoise = (sint16)(Vcpi_high_peak_noise - Vcpi_low_peak_noise);
      Vcpi_peak_to_peak_noise =
         (uint8)MATHSRV_udtCLAMP(s16Localpeaknoise, 0, 106);
   }
   Vcpi_noise_is_learned = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidInitialize                                */
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
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint8 Vcpi_peak_to_peak_noise;                                      */
/*  input uint16 Vcpi_current_integral;                                       */
/*  input uint16 Vta_intake_init_max_int_value;                               */
/*  input uint16 Kfvcpi_initial_int_step_size;                                */
/*  input uint8 Vcpi_edge_count;                                              */
/*  input uint16 Vcpi_integral_value;                                         */
/*  input uint8 Kfvcpi_set_edge_count;                                        */
/*  output boolean Vcpi_initial_integral_is_lrnd;                             */
/*  output uint16 Vcpi_integral_value;                                        */
/*  output uint16 Vcpi_integral_val_initMem;                                  */
/*  output uint16 Vcpi_current_integral;                                      */
/*  output uint8 Vcpi_edge_count;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidInitialize(void)
{
   uint16 u16LocaledgeCount;
   uint16 u16LocalVlvAct_agCmInPosnEstim;
   uint16 u16LocalVcpi_integral_value;
   sint32 s32LocalCurrentValue;
   sint32 s32LocalIntegValue;
   uint32 u32LocalCurInt;


   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
   if ( ((Vcpi_peak_to_peak_noise * 2) < u16LocalVlvAct_agCmInPosnEstim)
      ||(Vcpi_current_integral > Vta_intake_init_max_int_value))
   {
      Vcpi_initial_integral_is_lrnd = 1;
      s32LocalIntegValue = 64 * ( Vcpi_current_integral
                                - Kfvcpi_initial_int_step_size);
      u16LocalVcpi_integral_value =
               (uint16)(MATHSRV_udtCLAMP(s32LocalIntegValue,
                                         0,
                                         65535));
      VEMS_vidSET(Vcpi_integral_value, u16LocalVcpi_integral_value);
      Vcpi_integral_val_initMem = u16LocalVcpi_integral_value;
      s32LocalCurrentValue = (sint32)(Vcpi_current_integral -
                                      Kfvcpi_initial_int_step_size);
      Vcpi_current_integral = (uint16)(MATHSRV_udtCLAMP(s32LocalCurrentValue,
                                                        0, 1023));
      u16LocaledgeCount = Vcpi_edge_count;
   }
   else
   {
      Vcpi_initial_integral_is_lrnd = 0;
      VEMS_vidGET(Vcpi_integral_value, u16LocalVcpi_integral_value);
      Vcpi_integral_val_initMem = u16LocalVcpi_integral_value;

      if (Vcpi_edge_count < Kfvcpi_set_edge_count)
      {
         u16LocaledgeCount = (uint16)(Vcpi_edge_count + 1);
      }
      else
      {
         u32LocalCurInt = Vcpi_current_integral + Kfvcpi_initial_int_step_size;
         Vcpi_current_integral = (uint16)MATHSRV_udtMIN(u32LocalCurInt,1023);
         u16LocaledgeCount = 0;
      }
   }
   Vcpi_edge_count = (uint8)MATHSRV_udtMIN(u16LocaledgeCount,200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidSetpVelocity                              */
/* !Description :  Fonction qui calcule la dérivée de la consigne  utilisée   */
/*                 par l'action dérivée de l'asservissement VVT.              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 Vxx_vvtc_in_angl_sp_prev;                                    */
/*  output sint16 Vta_intake_speed_sp;                                        */
/*  output uint16 Vxx_vvtc_in_angl_sp_prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidSetpVelocity(void)
{
   uint16 u16LocalVxx_vvtc_in_angl_sp;
   sint32 s32LocalDiffValue;


   VEMS_vidGET(Vxx_vvtc_in_angl_sp,u16LocalVxx_vvtc_in_angl_sp);
   s32LocalDiffValue = (sint32)(  u16LocalVxx_vvtc_in_angl_sp
                                - Vxx_vvtc_in_angl_sp_prev);
   s32LocalDiffValue = ( (s32LocalDiffValue * 1000)
                       / (sint32)VlvAct_SampleTiFast_SC);
   Vta_intake_speed_sp =
      (sint16)MATHSRV_udtCLAMP(s32LocalDiffValue, -5333, 5333);
   Vxx_vvtc_in_angl_sp_prev = u16LocalVxx_vvtc_in_angl_sp;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidSelDutyCycl                               */
/* !Description :  fonction  de Selection de Duty_Cycle                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINSERVO_vidSelectPWM();                            */
/*  input boolean VlvAct_bInServoEna;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidSelDutyCycl(void)
{
   boolean bLocalVlvAct_bInServoEna;


   VEMS_vidGET(VlvAct_bInServoEna, bLocalVlvAct_bInServoEna);
   if ( bLocalVlvAct_bInServoEna != 0)
   {
      VLVACTINSERVO_vidSelectPWM();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidSelectPWM                                 */
/* !Description :  Choix du RCO à appliquer: apprentissage initial du RCO     */
/*                 d'équilibre, mode banc, valeur RCO issue du régulateur PID.*/
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cbx_vvtc_pwm_bch;                                           */
/*  input uint16 Cxx_vvtc_pwm_bch;                                            */
/*  input boolean Vcpi_initial_integral_is_lrnd;                              */
/*  input uint16 Vcpi_pid_duty_cycle;                                         */
/*  input uint16 Vcpi_current_integral;                                       */
/*  output uint16 Consigne_rco_vvt_adm;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidSelectPWM(void)
{
   uint16 u16LocalConsRcoVvt;
   uint16 u16LocalConsigne_rco_vvt_adm;


   if (Cbx_vvtc_pwm_bch != 0)
   {
      u16LocalConsRcoVvt = Cxx_vvtc_pwm_bch;
   }
   else
   {
      if (Vcpi_initial_integral_is_lrnd != 0)
      {
         u16LocalConsRcoVvt = Vcpi_pid_duty_cycle;
      }
      else
      {
         u16LocalConsRcoVvt = Vcpi_current_integral;
      }
   }
   u16LocalConsigne_rco_vvt_adm = (uint16)MATHSRV_udtMIN(u16LocalConsRcoVvt,
                                                         1023);
   VEMS_vidSET(Consigne_rco_vvt_adm, u16LocalConsigne_rco_vvt_adm);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidInitFailure                               */
/* !Description :  Les pannes présentes sont initialisées sur clé off --> on  */
/*                 afin qu’elles ne restent pas figées à ON entre le clé off  */
/*                 --> on et le démarrage du moteur.                          */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Vbx_pf_vvt_intake_blk;                                     */
/*  output boolean Vbx_pf_vvt_intake_int;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidInitFailure(void)
{
   Vbx_pf_vvt_intake_blk = 0;
   Vbx_pf_vvt_intake_int = 0;
}
/*-------------------------------end of file----------------------------------*/