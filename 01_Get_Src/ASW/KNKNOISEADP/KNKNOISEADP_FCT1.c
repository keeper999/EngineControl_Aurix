/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKNOISEADP                                             */
/* !Description     : KNKNOISEADP component                                   */
/*                                                                            */
/* !Module          : KNKNOISEADP                                             */
/* !Description     : ADAPTATION DU BRUIT MOTEUR MOYEN POUR LA STRATEGIE DE   */
/*                    DETECTION CLIQUETIS                                     */
/*                                                                            */
/* !File            : KNKNOISEADP_FCT1.C                                      */
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
/*   1 / KNKNOISEADP_vidInitOutput                                            */
/*   2 / KNKNOISEADP_vidInitialization                                        */
/*   3 / KNKNOISEADP_vidActivationCond                                        */
/*   4 / KNKNOISEADP_vidAdaptation                                            */
/*   5 / KNKNOISEADP_vidComputeAdapt                                          */
/*   6 / KNKNOISEADP_vidDiagnostic                                            */
/*   7 / KNKNOISEADP_vidDiagTimer                                             */
/*   8 / KNKNOISEADP_vidDiagResult                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 05725 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "KNKNOISEADP.H"
#include "KNKNOISEADP_L.H"
#include "KNKNOISEADP_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidInitOutput                                  */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean KnkTreat_bMonRun_NoiseAdp;                                 */
/*  output uint16 Knk_noi_ad_diag_tempo_uavn0;                                */
/*  output boolean KNKNOISEADP_bInitTimerPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidInitOutput(void)
{
   KnkTreat_bMonRun_NoiseAdp = 0;
   Knk_noi_ad_diag_tempo_uavn0 = 0;
   KNKNOISEADP_bInitTimerPrev = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidInitialization                              */
/* !Description :  On calcule un adaptatif par cylindre. Les variables        */
/*                 visualisables sont Knk_noi_ad_gain_cyl1_uavn0              */
/*                 (respectivement _cyl2_, _cyl3_, _cyl4_).                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 Knk_noi_ad_gain_init_uacn1[4];                               */
/*  output uint16 Knk_noi_ad_gain_uavn1[4];                                   */
/*  output boolean Knk_noi_ad_h_hit_uavb1[4];                                 */
/*  output boolean Knk_noi_ad_l_hit_uavb1[4];                                 */
/*  output boolean Knk_noi_ad_high_uavb1[4];                                  */
/*  output boolean Knk_noi_ad_low_uavb1[4];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidInitialization(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalKnk_noi_ad_gain_uavn1;
   uint32 u32LocalKnk_gain_init;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      u32LocalKnk_gain_init = Knk_noi_ad_gain_init_uacn1[u8LocalIndex] + 1;
      u16LocalKnk_noi_ad_gain_uavn1 =
         (uint16)MATHSRV_udtMIN(u32LocalKnk_gain_init, 65535);
      VEMS_vidSET1DArrayElement(Knk_noi_ad_gain_uavn1,
                                u8LocalIndex,
                                u16LocalKnk_noi_ad_gain_uavn1);

      Knk_noi_ad_h_hit_uavb1[u8LocalIndex] = 0;
      Knk_noi_ad_l_hit_uavb1[u8LocalIndex] = 0;
      Knk_noi_ad_high_uavb1[u8LocalIndex] = 0;
      Knk_noi_ad_low_uavb1[u8LocalIndex] = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidActivationCond                              */
/* !Description :  Le calcul de l'adaptatif du bruit cliquetis n'est autorisé */
/*                 que si le bruit moyen est représentatif de ce qui est      */
/*                 mesuré en conditions normales. Il faut donc que certaines  */
/*                 conditions soient réunies sur le régime, charge,           */
/*                 température eau et signal cliquetis                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_R_08_05725_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input uint8 Knk_noCyl;                                                    */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input boolean Detection_rbl[4];                                           */
/*  input boolean Detection_cliquetis[4];                                     */
/*  input boolean Knk_det_ris_knk_cyl_uavb1[4];                               */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Temperature_eau;                                              */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input boolean Knk_noi_ad_manu_inh_uacb0;                                  */
/*  input uint8 Knk_noi_ad_cdn_n_hthresh_uacn0;                               */
/*  input uint8 Knk_noi_ad_cdn_n_lthresh_uacn0;                               */
/*  input uint8 Knk_noi_ad_cdn_load_hthrsh_uacn0;                             */
/*  input uint8 Knk_noi_ad_cdn_load_lthrsh_uacn0;                             */
/*  input uint8 Knk_noi_ad_cdn_tco_lthresh_uacn0;                             */
/*  output boolean Knk_noi_ad_cdn_ok_uavb0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidActivationCond(void)
{
   boolean bLocalInhNoiseAdp;
   boolean bLocalDetection_fort_cliquetis;
   boolean bLocalDetection_rbl;
   boolean bLocalDetection_cliquetis;
   boolean bLocalKnk_sens_diag_act_uavb0;
   boolean bLocalKnk_det_ris_knk_cyl_uavb1;
   uint8   u8LocalKnk_noCyl;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalExt_rTotLd;


   bLocalInhNoiseAdp = GDGAR_bGetFRM(FRM_FRM_INHNOISEADP);
   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
   if (  (bLocalKnk_sens_diag_act_uavb0 != 0)
      || (bLocalInhNoiseAdp != 0) )
   {
      Knk_noi_ad_cdn_ok_uavb0 = 0;
   }
   else
   {
      VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
      switch(u8LocalKnk_noCyl)
      {
         case 0:
         case 1:
         case 2:
         case 3:
         VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_fort_cliquetis);
         VEMS_vidGET1DArrayElement(Detection_rbl,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_rbl);
         VEMS_vidGET1DArrayElement(Detection_cliquetis,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_cliquetis);
         VEMS_vidGET1DArrayElement(Knk_det_ris_knk_cyl_uavb1,
                                   u8LocalKnk_noCyl,
                                   bLocalKnk_det_ris_knk_cyl_uavb1);
         VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
         VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
         VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
         if (  (Knk_noi_ad_manu_inh_uacb0 == 0)
            && (u8LocalRegime_moteur_32 <= Knk_noi_ad_cdn_n_hthresh_uacn0)
            && (u8LocalRegime_moteur_32 >= Knk_noi_ad_cdn_n_lthresh_uacn0)
            && (  u16LocalExt_rTotLd
               <= (Knk_noi_ad_cdn_load_hthrsh_uacn0 * 256))
            && (  u16LocalExt_rTotLd
               >= (Knk_noi_ad_cdn_load_lthrsh_uacn0 * 256))
            && (u8LocalTemperature_eau >= Knk_noi_ad_cdn_tco_lthresh_uacn0)
            && (bLocalDetection_fort_cliquetis == 0)
            && (bLocalDetection_rbl == 0)
            && (bLocalDetection_cliquetis == 0)
            && (bLocalKnk_det_ris_knk_cyl_uavb1 == 0) )
         {
            Knk_noi_ad_cdn_ok_uavb0 = 1;
         }
         else
         {
            Knk_noi_ad_cdn_ok_uavb0 = 0;
         }
         break;

         default:
         SWFAIL_vidSoftwareErrorHook();
         break;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidAdaptation                                  */
/* !Description :  On ne calcule l’adaptatif que si les conditions le         */
/*                 requièrent (Knk_noi_ad_cdn_ok_uavb0=1) .                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKNOISEADP_vidComputeAdapt();                           */
/*  input boolean Knk_noi_ad_cdn_ok_uavb0;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidAdaptation(void)
{
   if (Knk_noi_ad_cdn_ok_uavb0 != 0)
   {
      KNKNOISEADP_vidComputeAdapt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidComputeAdapt                                */
/* !Description :  L'adaptatif est mis à jour selon l'itération suivante :    */
/*                 Adaptatif(k) = Adaptatif(k-1) + Gain_filtre × (Consigne -  */
/*                 BruitMoyen).                                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_R_08_00107_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Knk_noCyl;                                                    */
/*  input uint16 Bruit_moyen_cyl[4];                                          */
/*  input uint16 Knk_noi_mv_sp_uacn0;                                         */
/*  input uint16 Knk_noi_ad_dz_uacn0;                                         */
/*  input uint16 Knk_noi_ad_filt_gain_uacn0;                                  */
/*  input uint16 Knk_noi_ad_var_clmp_uacn0;                                   */
/*  input uint16 Knk_noi_ad_gain_uavn1[4];                                    */
/*  input uint8 Knk_noi_ad_gain_lclmp_uacn0;                                  */
/*  input uint8 Knk_noi_ad_gain_hclmp_uacn0;                                  */
/*  input uint8 Knk_noi_ad_gain_hthr_uacn0;                                   */
/*  input uint8 Knk_noi_ad_gain_lthr_uacn0;                                   */
/*  output uint16 Knk_noi_ad_gain_uavn1[4];                                   */
/*  output boolean Knk_noi_ad_h_hit_uavb1[4];                                 */
/*  output boolean Knk_noi_ad_l_hit_uavb1[4];                                 */
/*  output boolean Knk_noi_ad_high_uavb1[4];                                  */
/*  output boolean Knk_noi_ad_low_uavb1[4];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidComputeAdapt(void)
{
   uint8  u8LocalKnk_noCyl;
   uint16 u16LocalBruit_moyen_cyl;
   uint16 u16LocalKnk_gain_lclmp;
   uint16 u16LocalKnk_noi_ad_gain_uavn1;
   uint16 u16LocalKnk_gain_hclmp;
   uint16 u16LocalKnkNoise;
   uint32 u32LocalKnkNoise;
   sint32 s32LocalKnkNoise;


   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   switch(u8LocalKnk_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      VEMS_vidGET1DArrayElement(Bruit_moyen_cyl,
                                u8LocalKnk_noCyl,
                                u16LocalBruit_moyen_cyl);
      s32LocalKnkNoise = (sint32)( Knk_noi_mv_sp_uacn0
                                 - u16LocalBruit_moyen_cyl);
      u16LocalKnkNoise = (uint16)MATHSRV_udtABS(s32LocalKnkNoise);
      if (u16LocalKnkNoise > Knk_noi_ad_dz_uacn0)
      {
         u32LocalKnkNoise = ( (Knk_noi_ad_filt_gain_uacn0 * u16LocalKnkNoise)
                            / 16384);
         if (s32LocalKnkNoise > 0)
         {
            s32LocalKnkNoise = (sint32)u32LocalKnkNoise;
            s32LocalKnkNoise =
               MATHSRV_udtMIN(s32LocalKnkNoise,
                              (sint32)Knk_noi_ad_var_clmp_uacn0);
         }
         else
         {
            s32LocalKnkNoise = (sint32) ( (-1) * u32LocalKnkNoise);
            s32LocalKnkNoise =
               MATHSRV_udtMAX(s32LocalKnkNoise,
                              -(sint32)Knk_noi_ad_var_clmp_uacn0);
         }
      }
      else
      {
         s32LocalKnkNoise = 0;
      }
      VEMS_vidGET1DArrayElement(Knk_noi_ad_gain_uavn1,
                                u8LocalKnk_noCyl,
                                u16LocalKnk_noi_ad_gain_uavn1);
      s32LocalKnkNoise = s32LocalKnkNoise
                       + (sint32)u16LocalKnk_noi_ad_gain_uavn1;
      u16LocalKnk_gain_lclmp = (uint16)(Knk_noi_ad_gain_lclmp_uacn0 * 256);
      u16LocalKnk_gain_hclmp = (uint16)(Knk_noi_ad_gain_hclmp_uacn0 * 256);
      u16LocalKnk_noi_ad_gain_uavn1 =
         (uint16)MATHSRV_udtCLAMP(s32LocalKnkNoise,
                                  u16LocalKnk_gain_lclmp,
                                  u16LocalKnk_gain_hclmp);
      VEMS_vidSET1DArrayElement(Knk_noi_ad_gain_uavn1,
                                u8LocalKnk_noCyl,
                                u16LocalKnk_noi_ad_gain_uavn1);

      if (  u16LocalKnk_noi_ad_gain_uavn1
         == (uint16)(Knk_noi_ad_gain_hclmp_uacn0 * 256) )
      {
         Knk_noi_ad_h_hit_uavb1[u8LocalKnk_noCyl] = 1;
      }
      else
      {
         Knk_noi_ad_h_hit_uavb1[u8LocalKnk_noCyl] = 0;
      }

      if (  u16LocalKnk_noi_ad_gain_uavn1
         == (uint16)(Knk_noi_ad_gain_lclmp_uacn0 * 256) )
      {
         Knk_noi_ad_l_hit_uavb1[u8LocalKnk_noCyl] = 1;
      }
      else
      {
         Knk_noi_ad_l_hit_uavb1[u8LocalKnk_noCyl] = 0;
      }

      if ( u16LocalKnk_noi_ad_gain_uavn1
         > (uint16)(Knk_noi_ad_gain_hthr_uacn0 * 256) )
      {
         Knk_noi_ad_high_uavb1[u8LocalKnk_noCyl] = 1;
      }
      else
      {
         Knk_noi_ad_high_uavb1[u8LocalKnk_noCyl] = 0;
      }
      if (  u16LocalKnk_noi_ad_gain_uavn1
         <= (uint16)(Knk_noi_ad_gain_lthr_uacn0 * 256) )
      {
         Knk_noi_ad_low_uavb1[u8LocalKnk_noCyl] = 1;
      }
      else
      {
         Knk_noi_ad_low_uavb1[u8LocalKnk_noCyl] = 0;
      }
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidDiagnostic                                  */
/* !Description :  Après une durée calibrable déterminée à compter de         */
/*                 l'événement moteur_tournant et sous la condition que la    */
/*                 température d'eau soit supérieure à un certain seuil, le   */
/*                 diagnostic de l'adaptatif est réalisé à la fréquence       */
/*                 SdlSlow.                                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_R_08_00107_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKNOISEADP_vidDiagTimer();                              */
/*  extf argret void KNKNOISEADP_vidDiagResult();                             */
/*  input boolean KnkTreat_bMonRun_NoiseAdp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidDiagnostic(void)
{
   KNKNOISEADP_vidDiagTimer();
   if (KnkTreat_bMonRun_NoiseAdp != 0)
   {
      KNKNOISEADP_vidDiagResult();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidDiagTimer                                   */
/* !Description :  Cette attente est nécessaire afin de laisser à l'adaptation*/
/*                 le temps de converger avant de commencer le diagnostic.    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Moteur_tournant;                                            */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Knk_noi_ad_diag_tco_thresh_uacn0;                             */
/*  input boolean KNKNOISEADP_bInitTimerPrev;                                 */
/*  input uint16 Knk_noi_ad_diag_delay_uacn0;                                 */
/*  input uint16 Knk_noi_ad_diag_tempo_uavn0;                                 */
/*  output uint16 Knk_noi_ad_diag_tempo_uavn0;                                */
/*  output boolean KnkTreat_bMonRun_NoiseAdp;                                 */
/*  output boolean KNKNOISEADP_bInitTimerPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidDiagTimer(void)
{
   boolean bLocalInitTimer;
   boolean bLocalMoteur_tournant;
   uint8   u8LocalTemperature_eau;


   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   if (  (bLocalMoteur_tournant != 0)
      && (u8LocalTemperature_eau >= Knk_noi_ad_diag_tco_thresh_uacn0) )
   {
      bLocalInitTimer = 1;
   }
   else
   {
      bLocalInitTimer = 0;
   }

   if (  (KNKNOISEADP_bInitTimerPrev == 0)
      && (bLocalInitTimer != 0) )
   {
      Knk_noi_ad_diag_tempo_uavn0 =
         (uint16)MATHSRV_udtMIN(Knk_noi_ad_diag_delay_uacn0, 400);
      KnkTreat_bMonRun_NoiseAdp = 0;
   }
   else
   {
      if (Knk_noi_ad_diag_tempo_uavn0 > 0)
      {
         Knk_noi_ad_diag_tempo_uavn0 = (uint16)( Knk_noi_ad_diag_tempo_uavn0
                                               - 1);
      }
      if (Knk_noi_ad_diag_tempo_uavn0 == 0)
      {
         KnkTreat_bMonRun_NoiseAdp = 1;
      }
      else
      {
         KnkTreat_bMonRun_NoiseAdp = 0;
      }
   }
   KNKNOISEADP_bInitTimerPrev = bLocalInitTimer;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKNOISEADP_vidDiagResult                                  */
/* !Description :  Le résultat du diagnostic est positif lorsque l’adaptatif  */
/*                 de l’un des N cylindres est saturé ou diverge vers sa      */
/*                 limite. On a alors l’indicateur correspondant qui vaut 1.  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Knk_noi_ad_h_hit_uavb1[4];                                  */
/*  input boolean Knk_noi_ad_l_hit_uavb1[4];                                  */
/*  input boolean Knk_noi_ad_high_uavb1[4];                                   */
/*  input boolean Knk_noi_ad_low_uavb1[4];                                    */
/*  output boolean KnkTreat_bDgoHHit_NoiseAdp;                                */
/*  output boolean KnkTreat_bDgoLHit_NoiseAdp;                                */
/*  output boolean KnkTreat_bDgoHSld_NoiseAdp;                                */
/*  output boolean KnkTreat_bDgoLSld_NoiseAdp;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKNOISEADP_vidDiagResult(void)
{
   if (  (Knk_noi_ad_h_hit_uavb1[0] != 0)
      || (Knk_noi_ad_h_hit_uavb1[1] != 0)
      || (Knk_noi_ad_h_hit_uavb1[2] != 0)
      || (Knk_noi_ad_h_hit_uavb1[3] != 0) )
   {
      KnkTreat_bDgoHHit_NoiseAdp = 1;
   }
   else
   {
      KnkTreat_bDgoHHit_NoiseAdp = 0;
   }

   if (  (Knk_noi_ad_l_hit_uavb1[0] != 0)
      || (Knk_noi_ad_l_hit_uavb1[1] != 0)
      || (Knk_noi_ad_l_hit_uavb1[2] != 0)
      || (Knk_noi_ad_l_hit_uavb1[3] != 0) )
   {
      KnkTreat_bDgoLHit_NoiseAdp = 1;
   }
   else
   {
      KnkTreat_bDgoLHit_NoiseAdp = 0;
   }

   if (  (Knk_noi_ad_high_uavb1[0] != 0)
      || (Knk_noi_ad_high_uavb1[1] != 0)
      || (Knk_noi_ad_high_uavb1[2] != 0)
      || (Knk_noi_ad_high_uavb1[3] != 0) )
   {
      KnkTreat_bDgoHSld_NoiseAdp = 1;
   }
   else
   {
      KnkTreat_bDgoHSld_NoiseAdp = 0;
   }

   if (  (Knk_noi_ad_low_uavb1[0] != 0)
      || (Knk_noi_ad_low_uavb1[1] != 0)
      || (Knk_noi_ad_low_uavb1[2] != 0)
      || (Knk_noi_ad_low_uavb1[3] != 0) )
   {
      KnkTreat_bDgoLSld_NoiseAdp = 1;
   }
   else
   {
      KnkTreat_bDgoLSld_NoiseAdp = 0;
   }
}
/*QAC Warning(2:4700): Complexity Accepted                                    */
/*------------------------------end of file-----------------------------------*/