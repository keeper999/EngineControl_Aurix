/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKDIAG                                                 */
/* !Description     : KNKDIAG component.                                      */
/*                                                                            */
/* !Module          : KNKDIAG                                                 */
/* !Description     : DIAGNOSTIC DU CAPTEUR CLIQUETIS.                        */
/*                                                                            */
/* !File            : KNKDIAG_FCT1.C                                          */
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
/*   1 / KNKDIAG_vidInitOutput                                                */
/*   2 / KNKDIAG_vidTreatment                                                 */
/*   3 / KNKDIAG_vidDiagStrategy                                              */
/*   4 / KNKDIAG_vidDiagStateManagement                                       */
/*   5 / KNKDIAG_vidDiagnosticConditions                                      */
/*   6 / KNKDIAG_vidEndDiag                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5307525 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KNKTREAT/KNKDIAG/KNKDIAG_FCT1.C_v $*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   04 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   04 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKDIAG.h"
#include "KNKDIAG_L.h"
#include "KNKDIAG_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDIAG_vidInitOutput                                      */
/* !Description :  Fonction d'initialisation des variables produites par la   */
/*                 spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cliq_diag_knk_tdc_nr;                                        */
/*  output boolean Knk_sens_diag_dmd_uavb0;                                   */
/*  output st51 Knk_sens_diag_stt_uavs0;                                      */
/*  output uint16 Compteur_diag_k;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDIAG_vidInitOutput(void)
{
   VEMS_vidSET(Knk_sens_diag_dmd_uavb0, 0);
   /*initilize state machine*/
   Knk_sens_diag_stt_uavs0 = DIAG_NOT_REQUESTED;
   Compteur_diag_k = Cliq_diag_knk_tdc_nr;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDIAG_vidTreatment                                       */
/* !Description :  La calibration Cliq_diag_knk_tdc_nr est à double emploi :  */
/*                 Positionnée à zéro, elle inhibe la stratrégie de diagnostic*/
/*                 et toute valeur strictement positive désigne le nombre de  */
/*                 PMH que l’on souhaite laisser entre deux passages  en mode */
/*                 diagnostic.                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKDIAG_vidDiagStrategy();                               */
/*  input boolean Autorise_detection_clq;                                     */
/*  input uint16 Cliq_diag_knk_tdc_nr;                                        */
/*  input st51 Knk_sens_diag_stt_uavs0;                                       */
/*  output boolean KnkTreat_bMonRun_KnkDiag;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDIAG_vidTreatment(void)
{
   boolean bLocalAutorise_detection_clq;


   VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
   if (  (bLocalAutorise_detection_clq != 0)
      && (Cliq_diag_knk_tdc_nr != 0))
   {
      KNKDIAG_vidDiagStrategy();
   }
   if (Knk_sens_diag_stt_uavs0 == DIAG_ENDING)
   {
      KnkTreat_bMonRun_KnkDiag = 1;
   }
   else
   {
      KnkTreat_bMonRun_KnkDiag = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDIAG_vidDiagStrategy                                    */
/* !Description :  La stratégie de diagnostic cliquetis peut se trouver dans  */
/*                 quatre états différents, gérés dans un diagramme d’états:  */
/*                 DIAG_NOT_REQUESTED, DIAG_REQUIRED, DIAG_RUNNING et         */
/*                 DIAG_ENDING.                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDIAG_vidDiagStateManagement();                        */
/*  extf argret void KNKDIAG_vidDiagnosticConditions();                       */
/*  extf argret void KNKDIAG_vidEndDiag();                                    */
/*  input st51 Knk_sens_diag_stt_uavs0;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDIAG_vidDiagStrategy(void)
{
   KNKDIAG_vidDiagStateManagement();
   if (Knk_sens_diag_stt_uavs0 == DIAG_REQUIRED)
   {
      KNKDIAG_vidDiagnosticConditions();
   }
   else
   {
      if (Knk_sens_diag_stt_uavs0 == DIAG_ENDING)
      {
         KNKDIAG_vidEndDiag();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDIAG_vidDiagStateManagement                             */
/* !Description :  Ce module gère les opérations menées dans chaque état du   */
/*                 diagramme et les conditions qui déclenchent les transitions*/
/*                 d’un état à un autre.                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st51 Knk_sens_diag_stt_uavs0;                                       */
/*  input uint16 Compteur_diag_k;                                             */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input uint8 Knk_noCyl;                                                    */
/*  input uint16 Somme_clq_cyl[4];                                            */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Knk_sens_diag_count_uavn0;                                    */
/*  input uint16 Knk_diag_noi_inc_uavn0;                                      */
/*  input boolean KnkTreat_bDgoORng_KnkDiag;                                  */
/*  input uint16 Cliq_diag_knk_tdc_nr;                                        */
/*  output st51 Knk_sens_diag_stt_uavs0;                                      */
/*  output uint16 Compteur_diag_k;                                            */
/*  output uint8 Knk_sens_diag_count_uavn0;                                   */
/*  output uint16 Knk_diag_noi_inc_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDIAG_vidDiagStateManagement(void)
{
   boolean bLocalKnk_sens_diag_act_uavb0;
   uint8   u8LocalKnk_noCyl;
   uint8   u8LocalExt_noCylEng;
   uint16  u16LocalSomme_clq_cyl;
   uint32  u32LocalDiagNoise;


   switch (Knk_sens_diag_stt_uavs0)
   {
      case DIAG_NOT_REQUESTED:
         if (Compteur_diag_k == 0)
         {
            Knk_sens_diag_stt_uavs0 = DIAG_REQUIRED;
         }
         else
         {
            Compteur_diag_k = (uint16)(Compteur_diag_k - 1);
         }
         break;

      case DIAG_REQUIRED:
         VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
         if (bLocalKnk_sens_diag_act_uavb0 != 0)
         {
            Knk_sens_diag_stt_uavs0 = DIAG_RUNNING;
            Knk_sens_diag_count_uavn0 = 1;
            VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
            if (u8LocalKnk_noCyl < 4)
            {
               VEMS_vidGET1DArrayElement(Somme_clq_cyl,
                                         u8LocalKnk_noCyl,
                                         u16LocalSomme_clq_cyl);
               Knk_diag_noi_inc_uavn0 =
                  (uint16)MATHSRV_udtMIN(u16LocalSomme_clq_cyl,
                                         65534);
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }

         }
         break;

      case DIAG_RUNNING:
         VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
         if (  (u8LocalExt_noCylEng < 13)
            && (u8LocalExt_noCylEng > 0) )
         {
            if (Knk_sens_diag_count_uavn0 == (uint8)(u8LocalExt_noCylEng - 1))
            {
               Knk_sens_diag_stt_uavs0 = DIAG_ENDING;
            }
            else
            {
               if (Knk_sens_diag_count_uavn0 < 255)
               {
                  Knk_sens_diag_count_uavn0 = (uint8)( Knk_sens_diag_count_uavn0
                                                     + 1);
               }
            }
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }

         VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
         if (u8LocalKnk_noCyl < 4)
         {
            VEMS_vidGET1DArrayElement(Somme_clq_cyl,
                                      u8LocalKnk_noCyl,
                                      u16LocalSomme_clq_cyl);
            u32LocalDiagNoise = (uint32)( Knk_diag_noi_inc_uavn0
                                        + u16LocalSomme_clq_cyl);
            Knk_diag_noi_inc_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalDiagNoise,
                                                            65534);
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         break;

      case DIAG_ENDING:
         if (KnkTreat_bDgoORng_KnkDiag != 0)
         {
            VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
            if (bLocalKnk_sens_diag_act_uavb0 != 0)
            {
               Knk_sens_diag_stt_uavs0 = DIAG_RUNNING;
               Knk_sens_diag_count_uavn0 = 1;

               VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
               if (u8LocalKnk_noCyl < 4)
               {
                  VEMS_vidGET1DArrayElement(Somme_clq_cyl,
                                            u8LocalKnk_noCyl,
                                            u16LocalSomme_clq_cyl);
                  Knk_diag_noi_inc_uavn0 =
                     (uint16)MATHSRV_udtMIN(u16LocalSomme_clq_cyl, 65534);
               }
               else
               {
                  SWFAIL_vidSoftwareErrorHook();
               }
            }
            else
            {
               Knk_sens_diag_stt_uavs0 = DIAG_REQUIRED;
            }
         }
         else
         {
            Knk_sens_diag_stt_uavs0 = DIAG_NOT_REQUESTED;
            Compteur_diag_k = Cliq_diag_knk_tdc_nr;
         }
         break;

      default:
         Knk_sens_diag_stt_uavs0 = DIAG_NOT_REQUESTED;
         Compteur_diag_k = Cliq_diag_knk_tdc_nr;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDIAG_vidDiagnosticConditions                            */
/* !Description :  Ce module est activé lorsque le diagnostic est requis. On  */
/*                 doit alors s’assurer que les conditions de régime,         */
/*                 température d’eau et position papillon sont bien réunies   */
/*                 pour le passage en mode diagnostic. Le diagnostic est      */
/*                 inhibé lors de coupure d'injection.                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Auto_injection;                                             */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input uint16 Seuil_regime_diag_k;                                         */
/*  input uint8 Seuil_temp_eau_diag_k;                                        */
/*  input uint8 Seuil_throttle_diag_k;                                        */
/*  input boolean Knk_bInhVlvCdn_KnkDgo_C;                                    */
/*  output boolean Knk_sens_diag_dmd_uavb0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDIAG_vidDiagnosticConditions(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalVlvAct_bAcvInServo;
   uint8   u8LocalCorrected_throttle_pos;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrected_throttle_pos);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(VlvAct_bAcvInServo, bLocalVlvAct_bAcvInServo);

   if (  (u16LocalRegime_moteur >= Seuil_regime_diag_k)
      && (u8LocalTemperature_eau >= Seuil_temp_eau_diag_k)
      && (u8LocalCorrected_throttle_pos >= Seuil_throttle_diag_k)
      && (bLocalAuto_injection != 0)
      && (  (bLocalVlvAct_bAcvInServo == 0)
         || (Knk_bInhVlvCdn_KnkDgo_C != 0)))
   {
      VEMS_vidSET(Knk_sens_diag_dmd_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Knk_sens_diag_dmd_uavb0, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDIAG_vidEndDiag                                         */
/* !Description :  Lorsque les bruits de tous les cylindres ont été           */
/*                 additionnés, on compare la moyenne de bruit à un seuil     */
/*                 calibrable. On considère qu’en dessous de ce seuil, le     */
/*                 capteur est en panne.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input boolean Auto_injection;                                             */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input uint16 Regime_moteur_A[8];                                          */
/*  input uint16 Seuil_defaut_capteur_k[8];                                   */
/*  input uint16 Knk_diag_noi_inc_uavn0;                                      */
/*  input uint16 Seuil_defaut_capteur;                                        */
/*  input uint16 Seuil_regime_diag_k;                                         */
/*  input uint8 Seuil_temp_eau_diag_k;                                        */
/*  input uint8 Seuil_throttle_diag_k;                                        */
/*  input boolean Knk_bInhVlvCdn_KnkDgo_C;                                    */
/*  output uint16 Seuil_defaut_capteur;                                       */
/*  output boolean KnkTreat_bDgoORng_KnkDiag;                                 */
/*  output boolean Knk_sens_diag_dmd_uavb0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDIAG_vidEndDiag(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalVlvAct_bAcvInServo;
   uint8   u8LocalExt_noCylEng;
   uint8   u8LocalCorrect_throttle_position;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalKnkNoise;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalInterp1d;
   uint16  u16LocalParaRegime_moteur;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Corrected_throttle_position,
               u8LocalCorrect_throttle_position);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(VlvAct_bAcvInServo, bLocalVlvAct_bAcvInServo);

   u16LocalKnkNoise = 0;
   u16LocalParaRegime_moteur =
      MATHSRV_u16CalcParaIncAryU16(Regime_moteur_A,
                                   u16LocalRegime_moteur,
                                   8);
   u16LocalInterp1d = MATHSRV_u16Interp1d(Seuil_defaut_capteur_k,
                                          u16LocalParaRegime_moteur);
   Seuil_defaut_capteur =(uint16)MATHSRV_udtMIN(u16LocalInterp1d, 65534);
   if (  (u8LocalExt_noCylEng < 13)
      && (u8LocalExt_noCylEng > 0) )
   {
      u16LocalKnkNoise = (uint16)(Knk_diag_noi_inc_uavn0 / u8LocalExt_noCylEng);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   if (u16LocalKnkNoise > Seuil_defaut_capteur)
   {
      KnkTreat_bDgoORng_KnkDiag = 0;
      VEMS_vidSET(Knk_sens_diag_dmd_uavb0, 0);
   }
   else
   {
      KnkTreat_bDgoORng_KnkDiag = 1;
      if (  (u16LocalRegime_moteur >= Seuil_regime_diag_k)
         && (u8LocalTemperature_eau >= Seuil_temp_eau_diag_k)
         && (u8LocalCorrect_throttle_position >= Seuil_throttle_diag_k)
         && (bLocalAuto_injection != 0)
         && (  (bLocalVlvAct_bAcvInServo == 0)
            || (Knk_bInhVlvCdn_KnkDgo_C != 0)))
      {
         VEMS_vidSET(Knk_sens_diag_dmd_uavb0, 1);
      }
      else
      {
         VEMS_vidSET(Knk_sens_diag_dmd_uavb0, 0);
      }
   }
}
/*-------------------------------- End of file -------------------------------*/