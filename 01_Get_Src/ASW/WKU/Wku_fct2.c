/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WKU                                                     */
/* !Description     : WKU component.                                          */
/*                                                                            */
/* !Module          : WKU                                                     */
/* !Description     : GENERATION OF INFORMATION RELATED TO RCD .              */
/*                                                                            */
/* !File            : WKU_FCT2.c                                              */
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
/*   1 / WKU_vidMainWkCohDmdWku                                               */
/*   2 / WKU_vidMainWkIncoh                                                   */
/*   3 / WKU_vidBlcPartWkADCAntCase                                           */
/*   4 / WKU_vidBlcPartWkEngStartPrep                                         */
/*   5 / WKU_vidBlcPartWkEngOilMesPrep                                        */
/*   6 / WKU_vidBlcPartWkEngPostVent                                          */
/*   7 / WKU_vidMainGradToPass                                                */
/*   8 / WKU_vidMainWkPassCANOutOfOrd                                         */
/*   9 / WKU_vidForcMainWkAtReqDiag                                           */
/*   10 / WKU_vidRstRcdCount                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6765172 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECUST/WKU/Wku_fct2.c_v            $*/
/* $Revision::   1.27     $$Author::   achebino       $$Date::   16 Jun 2014 $*/
/* $Author::   achebino                               $$Date::   16 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "WKU.h"
#include "WKU_L.h"
#include "WKU_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidMainWkCohDmdWku                                     */
/* !Description :  Reveil principal du contrôle de cohérence des demandes RCD */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ActivateTask(argin uint8 Taskid);                        */
/*  extf argret void WKU_vidRstRcdCount();                                    */
/*  input boolean Rcd_signal;                                                 */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Clef_de_contact_ss_coh;                                     */
/*  input uint8 Rcd_seuil_vvh_clef_off;                                       */
/*  input uint8 Rcd_seuil_regime_clef_off;                                    */
/*  input uint16 Rcd_tempo_boot_delay;                                        */
/*  output boolean Temp_panne_coh_1;                                          */
/*  output boolean EcuSt_bWkuMain;                                            */
/*  output boolean Ext_bKeyOn;                                                */
/*  output boolean Ext_bKeyOff;                                               */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*  output boolean Clef_de_contact;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidMainWkCohDmdWku(void)
{
   boolean bLocalFRMInhCtlCohPwrOffVehSpd;
   boolean bLocalFRMAcvEcuPwrOnDft;
   boolean bLocalRcd_signal;
   boolean bLocalClef_de_contact;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalRcd_tempo_boot_count;

   Temp_panne_coh_1 = 0;

   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (  (Clef_de_contact_ss_coh == 0)
      && (bLocalClef_de_contact != 0))
   {
      bLocalFRMInhCtlCohPwrOffVehSpd =
         GDGAR_bGetFRM(FRM_FRM_INHCTLCOHPWROFFVEHSPD);
      bLocalFRMAcvEcuPwrOnDft =
         GDGAR_bGetFRM(FRM_FRM_ACVECUPWRONDFT);

      if ( bLocalFRMInhCtlCohPwrOffVehSpd == 0)
      {
         /* Le CMM est en reveil principal nominal*/
         if ( (u8LocalVitesse_vehicule <= Rcd_seuil_vvh_clef_off)
            && (u16LocalRegime_moteur <= (Rcd_seuil_regime_clef_off << 5)))
         {
            Temp_panne_coh_1 = 0;
            if (bLocalFRMAcvEcuPwrOnDft == 0)
            {
               /* Clef_on_off*/
               bLocalClef_de_contact = 0;
               EcuSt_bWkuMain = 0;
               VEMS_vidSET(Ext_bKeyOn,0);
               VEMS_vidSET(Ext_bKeyOff,1);
               u16LocalRcd_tempo_boot_count =
                  (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
               VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
               /* Evenement EcuSt_EveKOf_Wku*/
               ActivateTask(OSTSK_S_IGK_OFF);
            }
         }
         else
         {
            /* Incoherence entre la demande de fin du reveil principal et
                            le regime ou la vitesse*/
            Temp_panne_coh_1 = 1;
         }
      }
      else
      {
         /* Le CMM est en reveil principal degrade pour cause de vitesse
                     invalide ou absente*/
         Temp_panne_coh_1 = 0;
         if (bLocalFRMAcvEcuPwrOnDft == 0)
         {
            bLocalClef_de_contact = 0;
            EcuSt_bWkuMain = 0;
            VEMS_vidSET(Ext_bKeyOn,0);
            VEMS_vidSET(Ext_bKeyOff,1);
            u16LocalRcd_tempo_boot_count =
               (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
            VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
            /* Evenement EcuSt_EveKOf_Wku*/
            ActivateTask(OSTSK_S_IGK_OFF);
         }
      }
   }
   if (  (Clef_de_contact_ss_coh != 0)
      && (bLocalClef_de_contact == 0))
   {
      /* Clef_off_on*/
      bLocalClef_de_contact = 1;
      EcuSt_bWkuMain = 1;
      VEMS_vidSET(Ext_bKeyOn,1);
      VEMS_vidSET(Ext_bKeyOff,0);
      u16LocalRcd_tempo_boot_count =
         (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
      VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
      /* Evenement EcuSt_EveKOn_Wku */
      ActivateTask(OSTSK_S_IGK_ON);
      WKU_vidRstRcdCount();
   }

   VEMS_vidSET(Clef_de_contact, bLocalClef_de_contact);

   if (  (Clef_de_contact_ss_coh != 0)
      && (bLocalRcd_signal != 0)
      && (bLocalClef_de_contact != 0))
   {
      Temp_panne_coh_1 = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidMainWkIncoh                                         */
/* !Description :  Contrôle de cohérence entre Clef_de_contact et Rcd_signal  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WKU_vidMainWkCohDmdWku();                                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_reveil_principal;                                       */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Temp_panne_coh_1;                                           */
/*  input boolean Temp_panne_coh_2;                                           */
/*  input st09 Rcd_power_state;                                               */
/*  input bool RCD_POWER_ON;                                                  */
/*  output boolean Temp_panne_coh_2;                                          */
/*  output boolean EcuSt_bEngPrep;                                            */
/*  output boolean EcuSt_bEngFanReq;                                          */
/*  output boolean EcuSt_bOilMesEng;                                          */
/*  output boolean EcuSt_bImmoUnlockReq;                                      */
/*  output boolean Rcd_demand_anticip_adc;                                    */
/*  output boolean Rcd_demand_prepa_moteur;                                   */
/*  output boolean Rcd_demand_mes_huile_moteur;                               */
/*  output boolean Rcd_demand_post_ventil_mot;                                */
/*  output boolean EcuSt_bMonRunMainWkuIncst;                                 */
/*  output boolean EcuSt_bDgoMainWkuIncst;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidMainWkIncoh(void)
{
   boolean bLocalRcd_signal;
   boolean bLocalClef_de_contact;
   boolean bLocalRcd_reveil_principal;
   uint8   u8LocalRcd_power_state;


   WKU_vidMainWkCohDmdWku();

   VEMS_vidGET(Rcd_reveil_principal, bLocalRcd_reveil_principal);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   /* Controle de coherence entre Clef_de_contact et Rcd_signal*/
   if (bLocalClef_de_contact != 0)
   {
      if (bLocalRcd_signal == 0)
      {
         Temp_panne_coh_2 = 1;
         EcuSt_bEngPrep = 0;
         EcuSt_bEngFanReq = 0;
         EcuSt_bOilMesEng = 0;
         EcuSt_bImmoUnlockReq = 0;
         Rcd_demand_anticip_adc = 0;
         Rcd_demand_prepa_moteur = 0;
         Rcd_demand_mes_huile_moteur = 0;
         Rcd_demand_post_ventil_mot = 0;
      }
      else
      {
         Temp_panne_coh_2 = 0;
      }

      EcuSt_bMonRunMainWkuIncst = 1;
      if (  (Temp_panne_coh_1 == 0)
         && (Temp_panne_coh_2 == 0))
      {
         if (bLocalRcd_reveil_principal != 0)
         {
            EcuSt_bDgoMainWkuIncst = 0;
         }
      }
      else
      {
         VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
         if (u8LocalRcd_power_state == RCD_POWER_ON)
         {
            EcuSt_bDgoMainWkuIncst = 1;
         }
      }
   }
   else
   {
      EcuSt_bMonRunMainWkuIncst = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidBlcPartWkADCAntCase                                 */
/* !Description :  Cas réveil partiel bloqué anticipation ADC                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean EcuSt_bImmoUnlockReq;                                       */
/*  input boolean Rcd_inh_anticipation_adc_bloque;                            */
/*  input uint16 Rcd_anticipation_adc_max_count;                              */
/*  input uint16 Rcd_reveil_partiel_max_delay;                                */
/*  output uint16 Rcd_anticipation_adc_max_count;                             */
/*  output boolean EcuSt_bImmoUnlockReq;                                      */
/*  output boolean Rcd_demand_anticip_adc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidBlcPartWkADCAntCase(void)
{
   boolean bLocalClef_de_contact;


   if (Rcd_mode_active != 0)
   {
      /* Sortie du reveil partiel anticipation ADC lorsque
            sa demande est bloquee*/
      VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
      if (  (bLocalClef_de_contact == 0)
         && (EcuSt_bImmoUnlockReq != 0)
         && (Rcd_inh_anticipation_adc_bloque == 0))
      {
         if (Rcd_anticipation_adc_max_count == 0)
         {
            Rcd_anticipation_adc_max_count =
               (uint16)MATHSRV_udtMIN(Rcd_reveil_partiel_max_delay,
                                      U16MAX_TIME_DEC_RANGE);
         }
         else
         {
            Rcd_anticipation_adc_max_count =
               (uint16)(Rcd_anticipation_adc_max_count - 1);
         }
         if (Rcd_anticipation_adc_max_count == 0)
         {
            EcuSt_bImmoUnlockReq= 0;
            Rcd_demand_anticip_adc = 0;
         }
      }
      else
      {
         if (Rcd_anticipation_adc_max_count != 0)
         {
            Rcd_anticipation_adc_max_count = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidBlcPartWkEngStartPrep                               */
/* !Description :  Cas réveil partiel bloqué préparation démarrage moteur     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean EcuSt_bEngPrep;                                             */
/*  input boolean Rcd_inh_prepa_moteur_bloque;                                */
/*  input uint16 Rcd_prepa_mot_max_count;                                     */
/*  input uint16 Rcd_reveil_partiel_max_delay;                                */
/*  output uint16 Rcd_prepa_mot_max_count;                                    */
/*  output boolean EcuSt_bEngPrep;                                            */
/*  output boolean Rcd_demand_prepa_moteur;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidBlcPartWkEngStartPrep(void)
{
   boolean bLocalClef_de_contact;


   if (Rcd_mode_active != 0)
   {
         /* Sortie du reveil partiel preparation moteur lorsque
               sa demande est bloquee*/
      VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
      if (  (bLocalClef_de_contact == 0)
         && (EcuSt_bEngPrep != 0)
         && (Rcd_inh_prepa_moteur_bloque == 0))
      {
         if (Rcd_prepa_mot_max_count == 0)
         {
            Rcd_prepa_mot_max_count =
               (uint16)MATHSRV_udtMIN(Rcd_reveil_partiel_max_delay,
                                      U16MAX_TIME_DEC_RANGE);
         }
         else
         {
            Rcd_prepa_mot_max_count = (uint16)(Rcd_prepa_mot_max_count - 1);
         }
         if (Rcd_prepa_mot_max_count == 0)
         {
            EcuSt_bEngPrep = 0;
            Rcd_demand_prepa_moteur = 0;
         }
      }
      else
      {
         if (Rcd_prepa_mot_max_count != 0)
         {
            Rcd_prepa_mot_max_count = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidBlcPartWkEngOilMesPrep                              */
/* !Description :  Cas réveil partiel bloqué préparation mesures huile moteur */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean EcuSt_bOilMesEng;                                           */
/*  input boolean Rcd_inh_mes_huile_moteur_bloque;                            */
/*  input uint16 Rcd_mes_huile_moteur_max_count;                              */
/*  input uint16 Rcd_reveil_partiel_max_delay;                                */
/*  output uint16 Rcd_mes_huile_moteur_max_count;                             */
/*  output boolean EcuSt_bOilMesEng;                                          */
/*  output boolean Rcd_demand_mes_huile_moteur;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidBlcPartWkEngOilMesPrep(void)
{
   boolean bLocalClef_de_contact;


   if (Rcd_mode_active != 0)
   {
      /* Sortie du reveil partiel pour mesure niveau d'huile
      lorsque sa demande est bloquee*/
      VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
      if (  (bLocalClef_de_contact == 0)
         && (EcuSt_bOilMesEng != 0)
         && (Rcd_inh_mes_huile_moteur_bloque == 0))
      {
         if (Rcd_mes_huile_moteur_max_count == 0)
         {
            Rcd_mes_huile_moteur_max_count =
               (uint16)MATHSRV_udtMIN(Rcd_reveil_partiel_max_delay,
                                      U16MAX_TIME_DEC_RANGE);
         }
         else
         {
            Rcd_mes_huile_moteur_max_count =
               (uint16)(Rcd_mes_huile_moteur_max_count - 1);
         }
         if (Rcd_mes_huile_moteur_max_count == 0)
         {
            EcuSt_bOilMesEng = 0;
            Rcd_demand_mes_huile_moteur = 0;
         }
      }
      else
      {
         if (Rcd_mes_huile_moteur_max_count != 0)
         {
            Rcd_mes_huile_moteur_max_count = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidBlcPartWkEngPostVent                                */
/* !Description :  Cas réveil partiel bloqué préparation post-ventilation     */
/*                 moteur                                                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean EcuSt_bEngFanReq;                                           */
/*  input boolean Rcd_inh_post_ventil_mot_bloque;                             */
/*  input uint16 Rcd_post_ventil_mot_max_count;                               */
/*  input uint16 Rcd_reveil_partiel_pvm_max_delay;                            */
/*  output uint16 Rcd_post_ventil_mot_max_count;                              */
/*  output boolean EcuSt_bEngFanReq;                                          */
/*  output boolean Rcd_demand_post_ventil_mot;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidBlcPartWkEngPostVent(void)
{
   boolean bLocalClef_de_contact;


   if (Rcd_mode_active != 0)
   {
      /* Sortie du reveil partiel pour post-ventilation moteur
         lorsque sa demande est bloquee*/
      VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
      if (  (bLocalClef_de_contact == 0)
         && (EcuSt_bEngFanReq != 0)
         && (Rcd_inh_post_ventil_mot_bloque == 0))
      {
         if (Rcd_post_ventil_mot_max_count == 0)
         {
            Rcd_post_ventil_mot_max_count =
               (uint16)MATHSRV_udtMIN(Rcd_reveil_partiel_pvm_max_delay,
                                      U16MAX_TIME_DEC_RANGE);
         }
         else
         {
            Rcd_post_ventil_mot_max_count =
               (uint16)(Rcd_post_ventil_mot_max_count - 1);
         }
         if (Rcd_post_ventil_mot_max_count == 0)
         {
            EcuSt_bEngFanReq = 0;
            Rcd_demand_post_ventil_mot = 0;
         }
      }
      else
      {
         if (Rcd_post_ventil_mot_max_count != 0)
         {
            Rcd_post_ventil_mot_max_count = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidMainGradToPass                                      */
/* !Description :  Sortie du réveil principal dégradé vers la phase           */
/*                 transitoire                                                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ActivateTask(argin uint8 Taskid);                        */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Rcd_signal;                                                 */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Clef_de_contact_ss_coh;                                     */
/*  input uint8 Rcd_seuil_vvh_clef_off_def;                                   */
/*  input uint8 Rcd_seuil_regime_clef_off_def;                                */
/*  input uint8 Rcd_clef_off_default_count;                                   */
/*  input uint8 Rcd_clef_off_default_delay;                                   */
/*  output uint8 Rcd_clef_off_default_count;                                  */
/*  output boolean Clef_de_contact;                                           */
/*  output boolean Clef_de_contact_ss_coh;                                    */
/*  output boolean EcuSt_bWkuMain;                                            */
/*  output boolean Ext_bKeyOn;                                                */
/*  output boolean Ext_bKeyOff;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidMainGradToPass(void)
{
   boolean bLocalAcvEcuPwrOnDft;
   boolean bLocalInhTreatFrame432;
   boolean bLocalClef_de_contact;
   boolean bLocalRcd_signal;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalRegime_moteur;
   sint16  s16LocalRcd_clef_off_default_cnt;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   if (Rcd_mode_active != 0)
   {
      bLocalAcvEcuPwrOnDft = GDGAR_bGetFRM(FRM_FRM_ACVECUPWRONDFT);
      bLocalInhTreatFrame432 = GDGAR_bGetFRM(FRM_FRM_INHTREATFRAME432);

      if (  (bLocalAcvEcuPwrOnDft != 0)
         && (  (Clef_de_contact_ss_coh == 0)
            || (bLocalInhTreatFrame432 != 0))
         && (bLocalClef_de_contact != 0)
         && (bLocalRcd_signal == 0)
         && (u8LocalVitesse_vehicule <= Rcd_seuil_vvh_clef_off_def)
         && (u16LocalRegime_moteur <= (Rcd_seuil_regime_clef_off_def << 5)))
      {
         s16LocalRcd_clef_off_default_cnt =
            (sint16)(Rcd_clef_off_default_count - 1);
         Rcd_clef_off_default_count =
            (uint8)MATHSRV_udtMAX(s16LocalRcd_clef_off_default_cnt, 0);
      }
      else
      {
         Rcd_clef_off_default_count = Rcd_clef_off_default_delay;
      }
      if (Rcd_clef_off_default_count == 0)
      {
         VEMS_vidSET(Clef_de_contact, 0);
         Clef_de_contact_ss_coh = 0;
         EcuSt_bWkuMain = 0;
         VEMS_vidSET(Ext_bKeyOn, 0);
         VEMS_vidSET(Ext_bKeyOff, 1);
        /* Evenement EcuSt_EveKOf_Wku*/
         ActivateTask(OSTSK_S_IGK_OFF);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidMainWkPassCANOutOfOrd                               */
/* !Description :  Passage en réveil principal en cas de CAN hors service     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ActivateTask(argin uint8 Taskid);                        */
/*  extf argret void WKU_vidRstRcdCount();                                    */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean EcuSt_bDgoF432Lost;                                         */
/*  input boolean EcuSt_bDgoMainWkuDisrd;                                     */
/*  input uint16 Rcd_bascule_vers_principal_count;                            */
/*  input uint16 Rcd_bascule_vers_principal_delay;                            */
/*  input boolean Clef_signal_filt;                                           */
/*  input boolean EcuSt_bKeyOffForce;                                         */
/*  output uint16 Rcd_bascule_vers_principal_count;                           */
/*  output boolean Clef_de_contact;                                           */
/*  output boolean EcuSt_bWkuMain;                                            */
/*  output boolean Ext_bKeyOn;                                                */
/*  output boolean Ext_bKeyOff;                                               */
/*  output boolean Clef_de_contact_ss_coh;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidMainWkPassCANOutOfOrd(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalClef_signal_filt;
   boolean bLocalRcd_signal;
   boolean bLocalEcuSt_bKeyOffForce;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   if (Rcd_mode_active != 0)
   {
      if (  (bLocalRcd_signal != 0)
         && (  (EcuSt_bDgoF432Lost != 0)
            || (EcuSt_bDgoMainWkuDisrd != 0))
         && (bLocalClef_de_contact == 0))
      {
         if (Rcd_bascule_vers_principal_count == 0)
         {
            /* Init tempo sur evenement pour eviter de coder sur niveau*/
            Rcd_bascule_vers_principal_count =
               (uint16)MATHSRV_udtMIN(Rcd_bascule_vers_principal_delay,
                                      U16MAX_TIME_DEC_RANGE);
         }
         else
         {
            Rcd_bascule_vers_principal_count =
               (uint16)(Rcd_bascule_vers_principal_count - 1);
         }
         if (Rcd_bascule_vers_principal_count == 0)
         {
            VEMS_vidSET(Clef_de_contact, 1);
            EcuSt_bWkuMain = 1;
            VEMS_vidSET(Ext_bKeyOn, 1);
            VEMS_vidSET(Ext_bKeyOff, 0);
            Clef_de_contact_ss_coh = 1;
            /* Evenement EcuSt_EveKOn_Wku*/
            ActivateTask(OSTSK_S_IGK_ON);
            WKU_vidRstRcdCount();
         }
      }
      else
      {
         Rcd_bascule_vers_principal_count = 0;
      }
   }
   else
   {
      VEMS_vidGET(Clef_signal_filt, bLocalClef_signal_filt);
      VEMS_vidGET(EcuSt_bKeyOffForce, bLocalEcuSt_bKeyOffForce);
      if (  (bLocalClef_de_contact != bLocalClef_signal_filt)
         && (bLocalEcuSt_bKeyOffForce == 0))
      {
         if (bLocalClef_de_contact == 0)
         {
            VEMS_vidSET(Clef_de_contact, 1);
            EcuSt_bWkuMain = 1;
            VEMS_vidSET(Ext_bKeyOn, 1);
            VEMS_vidSET(Ext_bKeyOff, 0);
            Clef_de_contact_ss_coh = 1;
            /* Evenement EcuSt_EveKOn_Wku*/
            ActivateTask(OSTSK_S_IGK_ON);
            WKU_vidRstRcdCount();
         }
         else
         {
            VEMS_vidSET(Clef_de_contact, 0);
            EcuSt_bWkuMain = 0;
            VEMS_vidSET(Ext_bKeyOn, 0);
            VEMS_vidSET(Ext_bKeyOff, 1);
            Clef_de_contact_ss_coh = 0;
            /* Evenement EcuSt_EveKOf_Wku*/
            ActivateTask(OSTSK_S_IGK_OFF);
         }
      }
      if (  (bLocalClef_de_contact != 0)
         && (bLocalEcuSt_bKeyOffForce != 0))
      {
         VEMS_vidSET(Clef_de_contact, 0);
         EcuSt_bWkuMain = 0;
         VEMS_vidSET(Ext_bKeyOn, 0);
         VEMS_vidSET(Ext_bKeyOff, 1);
         Clef_de_contact_ss_coh = 0;
         /* Evenement EcuSt_EveKOf_Wku*/
         ActivateTask(OSTSK_S_IGK_OFF);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidForcMainWkAtReqDiag                                 */
/* !Description :  Forçage réveil principal sur requête diagnostic            */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ActivateTask(argin uint8 Taskid);                        */
/*  extf argret void WKU_vidRstRcdCount();                                    */
/*  input boolean Srv_bStartDiag;                                             */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Rcd_auto_reveil_princ_req_diag;                             */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  output boolean Clef_de_contact;                                           */
/*  output boolean Clef_de_contact_ss_coh;                                    */
/*  output boolean EcuSt_bWkuMain;                                            */
/*  output boolean Ext_bKeyOn;                                                */
/*  output boolean Ext_bKeyOff;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidForcMainWkAtReqDiag(void)
{
   boolean bLocalRcd_signal;
   boolean bLocalClef_de_contact;
   boolean bLocalSrv_bStartDiag;

   /* Sur evenement requetRcd_mode_activee diagnostique ligne K ou CAN*/
   VEMS_vidGET(Srv_bStartDiag, bLocalSrv_bStartDiag);
   if (  (Rcd_mode_active != 0)
      && (Rcd_auto_reveil_princ_req_diag != 0)
      && (bLocalSrv_bStartDiag != 0))
   {
      VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
      VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
      if (  (bLocalClef_de_contact == 0)
         && (bLocalRcd_signal != 0))
      {
         VEMS_vidSET(Clef_de_contact, 1);
         Clef_de_contact_ss_coh = 1;
         EcuSt_bWkuMain = 1;
         VEMS_vidSET(Ext_bKeyOn, 1);
         VEMS_vidSET(Ext_bKeyOff, 0);
         /* Evenement EcuSt_EveKOn_Wku*/
         ActivateTask(OSTSK_S_IGK_ON);
         WKU_vidRstRcdCount();
      }
      else
      {
         if (  (bLocalClef_de_contact != 0)
            && (bLocalRcd_signal == 0))
         {
            VEMS_vidSET(Clef_de_contact, 0);
            Clef_de_contact_ss_coh = 0;
            EcuSt_bWkuMain = 0;
            VEMS_vidSET(Ext_bKeyOn, 0);
            VEMS_vidSET(Ext_bKeyOff, 1);
            /* Evenement EcuSt_EveKOf_Wku*/
            ActivateTask(OSTSK_S_IGK_OFF);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidRstRcdCount                                         */
/* !Description :  Ré-initialisation de Rcd_bascule_vers_principal_count sur  */
/*                 l'événement Clef_off_on                                    */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Rcd_bascule_vers_principal_count;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidRstRcdCount(void)
{
   Rcd_bascule_vers_principal_count = 0;
}

/*--------------------------------- end of file ------------------------------*/
