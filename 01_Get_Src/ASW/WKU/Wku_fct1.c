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
/* !File            : WKU_FCT1.c                                              */
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
/*   1 / WKU_vidInitWku                                                       */
/*   2 / WKU_vidFrameReception                                                */
/*   3 / WKU_vidFrameMonitoring                                               */
/*   4 / WKU_vidTimerFlow                                                     */
/*   5 / WKU_vidPartWkADCAnticip                                              */
/*   6 / WKU_vidPartWkEngStartPrep                                            */
/*   7 / WKU_vidBlocPartWkEngOilMeas                                          */
/*   8 / WKU_vidPartWkEngPostVent                                             */
/*   9 / WKU_vidMainWku                                                       */
/*   10 / WKU_vidMgmtCntPowerOnDefault                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6765172 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECUST/WKU/Wku_fct1.c_v            $*/
/* $Revision::   1.27     $$Author::   achebino       $$Date::   16 Jun 2014 $*/
/* $Author::   achebino                               $$Date::   16 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.H"
#include "WKU.h"
#include "WKU_L.h"
#include "WKU_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidInitWku                                             */
/* !Description :  Au reset, on différencie le cas d'une gestion +APC ou RCD  */
/*                 afin que le calculateur ne reste pas verrouillé.           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Rcd_clef_off_default_delay;                                   */
/*  input uint16 Rcd_tempo_boot_delay;                                        */
/*  input boolean Rcd_mode_active;                                            */
/*  output boolean EcuSt_bImmoUnlockReq;                                      */
/*  output boolean EcuSt_bOilMesEng;                                          */
/*  output uint8 Rcd_anticipation_adc_count;                                  */
/*  output boolean EcuSt_bEngPrep;                                            */
/*  output boolean EcuSt_bEngFanReq;                                          */
/*  output uint16 Rcd_anticipation_adc_max_count;                             */
/*  output uint16 Rcd_prepa_mot_max_count;                                    */
/*  output uint16 Rcd_mes_huile_moteur_max_count;                             */
/*  output uint16 Rcd_bascule_vers_principal_count;                           */
/*  output uint8 Rcd_clef_off_default_count;                                  */
/*  output boolean Rcd_demand_anticip_adc;                                    */
/*  output boolean Rcd_demand_prepa_moteur;                                   */
/*  output boolean Rcd_demand_mes_huile_moteur;                               */
/*  output uint8 Rcd_reception_trame_compteur;                                */
/*  output uint8 Rcd_retour_power_on_count;                                   */
/*  output uint8 Rcd_reveil_principal_count;                                  */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*  output uint16 Rcd_post_ventil_mot_max_count;                              */
/*  output boolean Rcd_demand_post_ventil_mot;                                */
/*  output uint8 Rcd_autoris_surveil_trame_compt;                             */
/*  output boolean Clef_de_contact;                                           */
/*  output boolean EcuSt_bWkuMain;                                            */
/*  output boolean Ext_bKeyOn;                                                */
/*  output boolean Ext_bKeyOff;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidInitWku(void)
{
   uint16   u16LocalRcd_tempo_boot_count;


   EcuSt_bImmoUnlockReq = 0;
   EcuSt_bOilMesEng = 0;
   Rcd_anticipation_adc_count = 0;
   EcuSt_bEngPrep = 0;
   EcuSt_bEngFanReq = 0;
   Rcd_anticipation_adc_max_count = 0;
   Rcd_prepa_mot_max_count = 0;
   Rcd_mes_huile_moteur_max_count = 0;
   Rcd_bascule_vers_principal_count = 0;
   Rcd_clef_off_default_count = Rcd_clef_off_default_delay;
   Rcd_demand_anticip_adc = 0;
   Rcd_demand_prepa_moteur = 0;
   Rcd_demand_mes_huile_moteur = 0;
   Rcd_reception_trame_compteur = 0;
   VEMS_vidSET(Rcd_retour_power_on_count, 0);
   Rcd_reveil_principal_count = 0;

   u16LocalRcd_tempo_boot_count =
      (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
   VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);

   Rcd_post_ventil_mot_max_count = 0;
   Rcd_demand_post_ventil_mot = 0;
   Rcd_autoris_surveil_trame_compt = 0;

   if (Rcd_mode_active != 0)
   {
      VEMS_vidSET(Clef_de_contact, 0);
      EcuSt_bWkuMain = 0;
      VEMS_vidSET(Ext_bKeyOn, 0);
      VEMS_vidSET(Ext_bKeyOff, 1);
   }
   else
   {
      VEMS_vidSET(Clef_de_contact, 1);
      EcuSt_bWkuMain = 1;
      VEMS_vidSET(Ext_bKeyOn, 1);
      VEMS_vidSET(Ext_bKeyOff, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidFrameReception                                      */
/* !Description :  Réception de la trame 432H                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void WKU_vidPartWkADCAnticip();                               */
/*  extf argret void WKU_vidPartWkEngStartPrep();                             */
/*  extf argret void WKU_vidBlocPartWkEngOilMeas();                           */
/*  extf argret void WKU_vidPartWkEngPostVent();                              */
/*  extf argret void WKU_vidMainWku();                                        */
/*  extf argret void WKU_vidMainWkIncoh();                                    */
/*  extf argret void WKU_vidMgmtCntPowerOnDefault();                          */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Srv_bStartDiag;                                             */
/*  input boolean Rcd_mode_active;                                            */
/*  input uint8 Rcd_reception_trame_compteur;                                 */
/*  input boolean Rcd_reveil_princ_mux_default;                               */
/*  input boolean Rcd_inh_anticipation_adc;                                   */
/*  input boolean Rcd_inh_preparation_moteur;                                 */
/*  input boolean Rcd_inh_mes_huile_moteur;                                   */
/*  input boolean Rcd_inh_post_ventil_mot;                                    */
/*  input boolean EcuSt_bDgoMainWkuDisrd;                                     */
/*  input boolean EcuSt_bDgoF432Lost;                                         */
/*  output uint8 Rcd_reception_trame_compteur;                                */
/*  output boolean EcuSt_bMonRunMainWkuDisrd;                                 */
/*  output boolean EcuSt_bDgoMainWkuDisrd;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidFrameReception(void)
{
   boolean bLocalRcd_reveil_princ_mux_dft;
   boolean bLocalClef_de_contact;
   boolean bLocalIntegratioElectronique;
   boolean bLocalSrv_bStartDiag;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   VEMS_vidGET(Srv_bStartDiag, bLocalSrv_bStartDiag);

   if (  (Rcd_mode_active != 0)
      && (bLocalIntegratioElectronique == 0)
      && (bLocalSrv_bStartDiag == 0))
   {
      if (Rcd_reception_trame_compteur >= UINT8_MAX)
      {
         Rcd_reception_trame_compteur = UINT8_MAX;
      }
      else
      {
         Rcd_reception_trame_compteur = (uint8)( Rcd_reception_trame_compteur
                                               + 1);
      }

      if (bLocalClef_de_contact != 0)
      {
         EcuSt_bMonRunMainWkuDisrd = 1;
      }
      else
      {
         EcuSt_bMonRunMainWkuDisrd = 0;
      }

      VEMS_vidGET(Rcd_reveil_princ_mux_default, bLocalRcd_reveil_princ_mux_dft);
      if (bLocalRcd_reveil_princ_mux_dft != 0)
      {
         EcuSt_bDgoMainWkuDisrd = 1;
      }
      else
      {
         EcuSt_bDgoMainWkuDisrd = 0;
      }
      if (Rcd_inh_anticipation_adc == 0)
      {
       /* Mise a jour des variables liees au reveil partiel anticipation ADC */
         WKU_vidPartWkADCAnticip();
      }

      if (Rcd_inh_preparation_moteur == 0)
      {
      /* Mise a jour des variables liees au reveil partiel preparation moteur*/
         WKU_vidPartWkEngStartPrep();
      }

      if (Rcd_inh_mes_huile_moteur == 0)
      {
      /* Mise a jour des variables liees au reveil partiel pour mesure niveau
         d'huile */
         WKU_vidBlocPartWkEngOilMeas();
      }

      if (Rcd_inh_post_ventil_mot == 0)
      {
      /* Mise a jour des variables liees au reveil partiel pour post
           ventilation moteur*/
         WKU_vidPartWkEngPostVent();
      }
      if (  (EcuSt_bDgoMainWkuDisrd == 0)
         && (EcuSt_bDgoF432Lost == 0))
      {
         /* Mise a jour des variables liees au reveil principal*/
         WKU_vidMainWku();
         WKU_vidMainWkIncoh();
      }
   }
   WKU_vidMgmtCntPowerOnDefault();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidFrameMonitoring                                     */
/* !Description :  Sur moniteur fixe EcuSt_SdlMid_Wku, on calcule le nombre de*/
/*                 trames reçues, qui doit être de 1 ou 2 trames (trame 50    */
/*                 ms). Si ce n'est pas le cas, la panne d'absence de trame   */
/*                 est comptée avant d'appeler le mode dégradé correspondant  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean bDiagStWait);                         */
/*  input uint16 Rcd_waiting_for_anticip_count;                               */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Srv_bStartDiag;                                             */
/*  input boolean Rcd_mode_active;                                            */
/*  input uint8 Rcd_autoris_surveil_trame_compt;                              */
/*  input uint8 Rcd_surveil_trame_C;                                          */
/*  input uint8 Rcd_reception_trame_compteur;                                 */
/*  input uint8 Rcd_nbr_trame_432_min;                                        */
/*  input uint8 Rcd_nbr_trame_432_max;                                        */
/*  input boolean EcuSt_bDgoF432Lost;                                         */
/*  input boolean EcuSt_bMonRunF432Lost;                                      */
/*  output boolean EcuSt_bMonRunF432Lost;                                     */
/*  output uint8 Rcd_autoris_surveil_trame_compt;                             */
/*  output boolean EcuSt_bDgoF432Lost;                                        */
/*  output boolean EcuSt_bEngPrep;                                            */
/*  output boolean EcuSt_bEngFanReq;                                          */
/*  output boolean EcuSt_bOilMesEng;                                          */
/*  output boolean EcuSt_bImmoUnlockReq;                                      */
/*  output boolean Rcd_demand_anticip_adc;                                    */
/*  output boolean Rcd_demand_prepa_moteur;                                   */
/*  output boolean Rcd_demand_mes_huile_moteur;                               */
/*  output boolean Rcd_demand_post_ventil_mot;                                */
/*  output uint8 Rcd_reception_trame_compteur;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidFrameMonitoring(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalIntegratioElectronique;
   boolean bLocalSrv_bStartDiag;
   uint16  u16LocalRcd_waiting_for_anticip;


   VEMS_vidGET(Rcd_waiting_for_anticip_count, u16LocalRcd_waiting_for_anticip);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   VEMS_vidGET(Srv_bStartDiag, bLocalSrv_bStartDiag);
   if (  (Rcd_mode_active != 0)
      && (bLocalIntegratioElectronique == 0)
      && (bLocalSrv_bStartDiag == 0))
   {
      if (bLocalClef_de_contact != 0)
      {
         EcuSt_bMonRunF432Lost = 1;
      }
      else
      {
         EcuSt_bMonRunF432Lost = 0;
      }

      if (Rcd_autoris_surveil_trame_compt == Rcd_surveil_trame_C)
      {
         Rcd_autoris_surveil_trame_compt = 0;

         if (  (Rcd_reception_trame_compteur <= Rcd_nbr_trame_432_min)
            || (Rcd_reception_trame_compteur > Rcd_nbr_trame_432_max))
         {
            if (u16LocalRcd_waiting_for_anticip != 0)
            {
               /*CALL_GduFrame432_Lost; */
               EcuSt_bDgoF432Lost = 1;
               GDGAR_vidGdu(GD_DFT_F432LOST,
                            EcuSt_bDgoF432Lost,
                            EcuSt_bMonRunF432Lost,
                            0);
            }
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
            if (u16LocalRcd_waiting_for_anticip != 0)
            {
               /*CALL_GduFrame432_Lost(); */
               EcuSt_bDgoF432Lost = 0;
               GDGAR_vidGdu(GD_DFT_F432LOST,
                            EcuSt_bDgoF432Lost,
                            EcuSt_bMonRunF432Lost,
                            0);
            }
         }
         Rcd_reception_trame_compteur = Rcd_nbr_trame_432_min;
      }
      else
      {
         if (Rcd_autoris_surveil_trame_compt < UINT8_MAX)
         {
            Rcd_autoris_surveil_trame_compt =
               (uint8)(Rcd_autoris_surveil_trame_compt + 1);
         }
         else
         {
            Rcd_autoris_surveil_trame_compt = UINT8_MAX;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidTimerFlow                                           */
/* !Description :  Ecoulement du timer Rcd_tempo_boot_count pour que le       */
/*                 comptage des pannes FRM_bAcvPwrOnDftModRVRxn432 et         */
/*                 FRM_bAcvDft_EcuSt_CohBsi soit possible.                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Rcd_tempo_boot_count;                                        */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Rcd_mode_active;                                            */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidTimerFlow(void)
{
   boolean bLocalIntegratioElectronique;
   uint16  u16LocalRcd_tempo_boot_count;


   VEMS_vidGET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   if (  (Rcd_mode_active != 0)
      && (bLocalIntegratioElectronique == 0)
      && (u16LocalRcd_tempo_boot_count != 0))
   {
      u16LocalRcd_tempo_boot_count = (uint16)(u16LocalRcd_tempo_boot_count - 1);
      u16LocalRcd_tempo_boot_count =
         (uint16)MATHSRV_udtMIN(u16LocalRcd_tempo_boot_count, 60000);
      VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidPartWkADCAnticip                                    */
/* !Description :  Mise à jour des variables liées au réveil partiel          */
/*                 anticipation ADC. En cas de réveils partiels multiples le  */
/*                 CMM effectue l'ensemble des réveils partiels activés.      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EcuSt_EvePtlWku_Wku();                                   */
/*  input boolean Rcd_anticipation_adc_mux;                                   */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Rcd_demand_anticip_adc;                                     */
/*  input uint8 Rcd_anticipation_adc_count;                                   */
/*  input uint8 Rcd_reveil_partiel_count_off;                                 */
/*  input uint8 Rcd_reveil_partiel_count_on;                                  */
/*  input boolean EcuSt_bImmoUnlockReq;                                       */
/*  input boolean EcuSt_bEngPrep;                                             */
/*  input boolean EcuSt_bOilMesEng;                                           */
/*  input boolean EcuSt_bEngFanReq;                                           */
/*  input uint16 Rcd_tempo_boot_delay;                                        */
/*  output uint8 Rcd_anticipation_adc_count;                                  */
/*  output boolean Rcd_demand_anticip_adc;                                    */
/*  output boolean EcuSt_bImmoUnlockReq;                                      */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidPartWkADCAnticip(void)
{
   boolean bLocalRcd_anticipation_adc_mux;
   boolean bLocalRcd_signal;
   boolean bLocalClef_de_contact;
   uint16  u16LocalRcd_tempo_boot_count;


   /*Mise a jour des variables liees au reveil partiel anticipation ADC*/
   VEMS_vidGET(Rcd_anticipation_adc_mux, bLocalRcd_anticipation_adc_mux);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (  (Rcd_demand_anticip_adc != bLocalRcd_anticipation_adc_mux )
      && (  (bLocalRcd_signal != 0)
         || (bLocalRcd_anticipation_adc_mux == 0)))
   {
      if (Rcd_anticipation_adc_count < UINT8_MAX)
      {
         Rcd_anticipation_adc_count = (uint8)(Rcd_anticipation_adc_count + 1);
      }
      else
      {
         Rcd_anticipation_adc_count = UINT8_MAX;
      }

      if (  (  (bLocalRcd_anticipation_adc_mux == 0)
            && (Rcd_anticipation_adc_count == Rcd_reveil_partiel_count_off))
         || (  (bLocalRcd_anticipation_adc_mux != 0)
            && (Rcd_anticipation_adc_count == Rcd_reveil_partiel_count_on)))
      {
         Rcd_anticipation_adc_count = 0;
         Rcd_demand_anticip_adc = bLocalRcd_anticipation_adc_mux;
         EcuSt_bImmoUnlockReq = bLocalRcd_anticipation_adc_mux;
         if (  (EcuSt_bImmoUnlockReq != 0)
            && (bLocalClef_de_contact == 0)
            && (EcuSt_bEngPrep == 0)
            && (EcuSt_bOilMesEng == 0)
            && (EcuSt_bEngFanReq == 0))
         {
            /* Transition Transitoire --> Partiel*/
            u16LocalRcd_tempo_boot_count =
               (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
            VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
            /* Evenement EcuSt_EvePtlWku_Wku*/
            EcuSt_EvePtlWku_Wku();
         }
      }
   }
   else
   {
      Rcd_anticipation_adc_count = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidPartWkEngStartPrep                                  */
/* !Description :  Mise à jour des variables liées au réveil partiel          */
/*                 préparation moteur                                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EcuSt_EvePtlWku_Wku();                                   */
/*  input boolean Rcd_preparation_moteur_mux;                                 */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Rcd_demand_prepa_moteur;                                    */
/*  input uint8 Rcd_preparation_moteur_count;                                 */
/*  input uint8 Rcd_reveil_partiel_count_off;                                 */
/*  input uint8 Rcd_reveil_partiel_count_on;                                  */
/*  input boolean EcuSt_bEngPrep;                                             */
/*  input boolean EcuSt_bImmoUnlockReq;                                       */
/*  input boolean EcuSt_bOilMesEng;                                           */
/*  input boolean EcuSt_bEngFanReq;                                           */
/*  input uint16 Rcd_tempo_boot_delay;                                        */
/*  output uint8 Rcd_preparation_moteur_count;                                */
/*  output boolean Rcd_demand_prepa_moteur;                                   */
/*  output boolean EcuSt_bEngPrep;                                            */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidPartWkEngStartPrep(void)
{
   boolean bLocalRcd_preparation_moteur_mux;
   boolean bLocalRcd_signal;
   boolean bLocalClef_de_contact;
   uint16  u16LocalRcd_tempo_boot_count;


   /* Mise a jour des variables liees au reveil partiel preparation moteur*/
   VEMS_vidGET(Rcd_preparation_moteur_mux, bLocalRcd_preparation_moteur_mux);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (  (Rcd_demand_prepa_moteur != bLocalRcd_preparation_moteur_mux)
      && (  (bLocalRcd_signal != 0)
         || (bLocalRcd_preparation_moteur_mux == 0)
          )
      )
   {
      if (Rcd_preparation_moteur_count < UINT8_MAX)
      {
         Rcd_preparation_moteur_count = (uint8)(Rcd_preparation_moteur_count
                                               + 1);
      }
      else
      {
         Rcd_preparation_moteur_count = UINT8_MAX;
      }
      if (  (  (bLocalRcd_preparation_moteur_mux == 0)
            && (Rcd_preparation_moteur_count == Rcd_reveil_partiel_count_off))
         || (  (bLocalRcd_preparation_moteur_mux != 0)
            && (Rcd_preparation_moteur_count == Rcd_reveil_partiel_count_on)))
      {
         Rcd_preparation_moteur_count = 0;
         Rcd_demand_prepa_moteur = bLocalRcd_preparation_moteur_mux;
         EcuSt_bEngPrep = bLocalRcd_preparation_moteur_mux;
         if (  (EcuSt_bEngPrep != 0)
            && (bLocalClef_de_contact == 0)
            && (EcuSt_bImmoUnlockReq == 0)
            && (EcuSt_bOilMesEng == 0)
            && (EcuSt_bEngFanReq == 0))
         {
            /*Transition Transitoire --> Partiel */
            u16LocalRcd_tempo_boot_count =
               (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
            VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
            /* Evenement WKU_EcuSt_EvePtlWku_Wku*/
            EcuSt_EvePtlWku_Wku();
         }
      }
   }
   else
   {
      Rcd_preparation_moteur_count = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidBlocPartWkEngOilMeas                                */
/* !Description :  Mise à jour des variables liées au réveil partiel pour     */
/*                 mesure du niveau d'huile                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EcuSt_EvePtlWku_Wku();                                   */
/*  input boolean Rcd_mes_huile_moteur_mux;                                   */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Rcd_demand_mes_huile_moteur;                                */
/*  input uint8 Rcd_mes_huile_moteur_count;                                   */
/*  input uint8 Rcd_reveil_partiel_count_off;                                 */
/*  input uint8 Rcd_reveil_partiel_count_on;                                  */
/*  input boolean EcuSt_bOilMesEng;                                           */
/*  input boolean EcuSt_bImmoUnlockReq;                                       */
/*  input boolean EcuSt_bEngPrep;                                             */
/*  input boolean EcuSt_bEngFanReq;                                           */
/*  input uint16 Rcd_tempo_boot_delay;                                        */
/*  output uint8 Rcd_mes_huile_moteur_count;                                  */
/*  output boolean Rcd_demand_mes_huile_moteur;                               */
/*  output boolean EcuSt_bOilMesEng;                                          */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidBlocPartWkEngOilMeas(void)
{
   boolean bLocalRcd_mes_huile_moteur_mux;
   boolean bLocalRcd_signal;
   boolean bLocalClef_de_contact;
   uint16  u16LocalRcd_tempo_boot_count;


   /* Mise a jour des variables liees au reveil partiel pour mesure du niveau
         d'huile */
   VEMS_vidGET(Rcd_mes_huile_moteur_mux, bLocalRcd_mes_huile_moteur_mux);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (  (Rcd_demand_mes_huile_moteur != bLocalRcd_mes_huile_moteur_mux)
      && (  (bLocalRcd_signal != 0)
         || (bLocalRcd_mes_huile_moteur_mux == 0)))
   {
      if (Rcd_mes_huile_moteur_count < UINT8_MAX)
      {
         Rcd_mes_huile_moteur_count = (uint8)(Rcd_mes_huile_moteur_count + 1);
      }
      else
      {
         Rcd_mes_huile_moteur_count = UINT8_MAX;
      }

      if (  (  (bLocalRcd_mes_huile_moteur_mux == 0)
            && (Rcd_mes_huile_moteur_count == Rcd_reveil_partiel_count_off))
         || (  (bLocalRcd_mes_huile_moteur_mux != 0)
            && (Rcd_mes_huile_moteur_count == Rcd_reveil_partiel_count_on)))
      {
         Rcd_mes_huile_moteur_count = 0;
         Rcd_demand_mes_huile_moteur = bLocalRcd_mes_huile_moteur_mux;
         EcuSt_bOilMesEng = bLocalRcd_mes_huile_moteur_mux;

         if (  (EcuSt_bOilMesEng != 0)
            && (bLocalClef_de_contact == 0)
            && (EcuSt_bImmoUnlockReq == 0)
            && (EcuSt_bEngPrep == 0)
            && (EcuSt_bEngFanReq == 0))
         {
            /* Transitoire -->  Partiel*/
            u16LocalRcd_tempo_boot_count =
               (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
            VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
            /* Evenement WKU_EcuSt_EvePtlWku_Wku*/
            EcuSt_EvePtlWku_Wku();
         }
      }
   }
   else
   {
      Rcd_mes_huile_moteur_count = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidPartWkEngPostVent                                   */
/* !Description :  Mise à jour des variables liées au réveil partiel pour     */
/*                 post-ventilation moteur                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EcuSt_EvePtlWku_Wku();                                   */
/*  input boolean Rcd_post_ventil_mot_mux;                                    */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Rcd_demand_post_ventil_mot;                                 */
/*  input uint8 Rcd_post_ventil_mot_count;                                    */
/*  input uint8 Rcd_reveil_partiel_count_off;                                 */
/*  input uint8 Rcd_reveil_partiel_count_on;                                  */
/*  input boolean EcuSt_bEngFanReq;                                           */
/*  input boolean EcuSt_bImmoUnlockReq;                                       */
/*  input boolean EcuSt_bEngPrep;                                             */
/*  input boolean EcuSt_bOilMesEng;                                           */
/*  input uint16 Rcd_tempo_boot_delay;                                        */
/*  output uint8 Rcd_post_ventil_mot_count;                                   */
/*  output boolean Rcd_demand_post_ventil_mot;                                */
/*  output boolean EcuSt_bEngFanReq;                                          */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidPartWkEngPostVent(void)
{
   boolean bLocalRcd_post_ventil_mot_mux;
   boolean bLocalRcd_signal;
   boolean bLocalClef_de_contact;
   uint16  u16LocalRcd_tempo_boot_count;


   /* Mise a jour des variables liees au reveil partiel pour post-ventilation
               moteur */
   VEMS_vidGET(Rcd_post_ventil_mot_mux, bLocalRcd_post_ventil_mot_mux);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (  (Rcd_demand_post_ventil_mot != bLocalRcd_post_ventil_mot_mux)
      && (  (bLocalRcd_signal != 0)
         || (bLocalRcd_post_ventil_mot_mux == 0)))
   {
      if (Rcd_post_ventil_mot_count < UINT8_MAX)
      {
         Rcd_post_ventil_mot_count = (uint8)(Rcd_post_ventil_mot_count + 1);
      }
      else
      {
         Rcd_post_ventil_mot_count = UINT8_MAX;
      }
      if (  (  (bLocalRcd_post_ventil_mot_mux == 0)
            && (Rcd_post_ventil_mot_count == Rcd_reveil_partiel_count_off))
         || (  (bLocalRcd_post_ventil_mot_mux != 0)
            && (Rcd_post_ventil_mot_count == Rcd_reveil_partiel_count_on)))
      {
         Rcd_post_ventil_mot_count = 0;
         Rcd_demand_post_ventil_mot = bLocalRcd_post_ventil_mot_mux;
         EcuSt_bEngFanReq = bLocalRcd_post_ventil_mot_mux;

         if (  (EcuSt_bEngFanReq != 0)
            && (bLocalClef_de_contact == 0)
            && (EcuSt_bImmoUnlockReq == 0)
            && (EcuSt_bEngPrep == 0)
            && (EcuSt_bOilMesEng == 0))
         {
            /*Transition Transitoire --> Partiel*/
            u16LocalRcd_tempo_boot_count =
               (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
            VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
            /*Evènement EcuSt_EvePtlWku_Wku*/
            EcuSt_EvePtlWku_Wku();
         }
      }
   }
   else
   {
      Rcd_post_ventil_mot_count = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidMainWku                                             */
/* !Description :  Mise à jour des variables liées au réveil principal        */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_reveil_principal;                                       */
/*  input boolean Clef_de_contact_ss_coh;                                     */
/*  input uint8 Rcd_reveil_principal_count;                                   */
/*  input uint8 Rcd_reveil_principal_count_off;                               */
/*  input uint8 Rcd_reveil_principal_count_on;                                */
/*  output uint8 Rcd_reveil_principal_count;                                  */
/*  output boolean Clef_de_contact_ss_coh;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidMainWku(void)
{
   boolean bLocalRcd_reveil_principal;


   /* Confirmation sur plusieurs trames du reveil principal*/
   VEMS_vidGET(Rcd_reveil_principal, bLocalRcd_reveil_principal);
   if (Clef_de_contact_ss_coh != bLocalRcd_reveil_principal)
   {
      if (Rcd_reveil_principal_count < UINT8_MAX)
      {
         Rcd_reveil_principal_count = (uint8)(Rcd_reveil_principal_count + 1);
      }
      else
      {
         Rcd_reveil_principal_count = UINT8_MAX;
      }
      if (  (  (bLocalRcd_reveil_principal == 0)
            && (Rcd_reveil_principal_count == Rcd_reveil_principal_count_off))
         || (  (bLocalRcd_reveil_principal != 0)
            && (Rcd_reveil_principal_count == Rcd_reveil_principal_count_on)))
      {
         Rcd_reveil_principal_count = 0;
         Clef_de_contact_ss_coh = bLocalRcd_reveil_principal;
      }
   }
   else
   {
      Rcd_reveil_principal_count = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidMgmtCntPowerOnDefault                               */
/* !Description :  Gérer le compteur de passage en POWER_ON_DEFAULT           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 Rcd_retour_power_on_count;                                    */
/*  input uint8 Rcd_retour_power_on_nb;                                       */
/*  output uint8 Rcd_retour_power_on_count;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidMgmtCntPowerOnDefault(void)
{
   boolean bLocalFrmAcvEcuPwrOnDft;
   boolean bLocalClef_de_contact;
   uint8   u8LocalRcd_retour_power_on_count;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Rcd_retour_power_on_count, u8LocalRcd_retour_power_on_count);
   if (bLocalClef_de_contact != 0)
   {
      bLocalFrmAcvEcuPwrOnDft = GDGAR_bGetFRM(FRM_FRM_ACVECUPWRONDFT);

      if(bLocalFrmAcvEcuPwrOnDft == 0)
      {
         if (u8LocalRcd_retour_power_on_count != 0)
         {
            u8LocalRcd_retour_power_on_count =
               (uint8)(u8LocalRcd_retour_power_on_count - 1);
         }
      }
      else
      {
         u8LocalRcd_retour_power_on_count = Rcd_retour_power_on_nb;
      }
   }
   else
   {
      if (u8LocalRcd_retour_power_on_count != 0)
      {
         u8LocalRcd_retour_power_on_count = 0;
      }
   }
   VEMS_vidSET(Rcd_retour_power_on_count, u8LocalRcd_retour_power_on_count);
}
/*--------------------------------- end of file ------------------------------*/