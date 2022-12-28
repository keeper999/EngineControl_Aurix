/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUSWTDIAG                                              */
/* !Description     : CLUSWTDIAG Component                                    */
/*                                                                            */
/* !Module          : CLUSWTDIAG                                              */
/* !Description     : Diagnostic switch embrayage                             */
/*                                                                            */
/* !File            : CLUSWTDIAG_FCT2.C                                       */
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
/*   1 / CLUSWTDIAG_vidDgoCoh_CluSt                                           */
/*   2 / CLUSWTDIAG_vidCps_switch_mal_cpt                                     */
/*   3 / CLUSWTDIAG_vidDiagStuck_CluSt                                        */
/*   4 / CLUSWTDIAG_vidTempoCoh                                               */
/*   5 / CLUSWTDIAG_vidTempoStuck                                             */
/*   6 / CLUSWTDIAG_vidDiagStuckAcvn                                          */
/*   7 / CLUSWTDIAG_vidDiagStuckInitTempo                                     */
/*   8 / CLUSWTDIAG_vidDiagStuckDft                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 04680 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#045677                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CLUSWTDIAG/CLUSWTDIAG_FCT2.C_v    $*/
/* $Revision::   1.3      $$Author::   ACHEBINO       $$Date::   12 Jul 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   12 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "CLUSWTDIAG.H"
#include "CLUSWTDIAG_L.H"
#include "CLUSWTDIAG_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDgoCoh_CluSt                                 */
/* !Description :  Cette fonction gère la detection d'une panne du capteur    */
/*                 d'embrayage                                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  dobregon                                                   */
/* !Trace_To    :  VEMS_R_08_04680_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Moteur_tournant;                                            */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Required_fuel_flow_rate;                                     */
/*  input uint8 Cps_vit_veh_min_init_diag;                                    */
/*  input uint8 Cps_vit_veh_max_init_diag;                                    */
/*  input uint8 Cps_reg_mot_min_init_diag;                                    */
/*  input uint16 Cps_req_fuel_min_init_diag;                                  */
/*  input boolean CLUSWTDIAG_bExtBCluPedPrssPrev;                             */
/*  input uint8 Cps_vitesse_max_diag_desac;                                   */
/*  input uint8 Cps_vitesse_max_sans_debrayage;                               */
/*  output boolean Clu_bDiagCohIninCdn;                                       */
/*  output boolean Cps_controle_ok;                                           */
/*  output boolean Clu_bDiagCohDacvn;                                         */
/*  output boolean Clu_bDiagCohCdn;                                           */
/*  output boolean CLUSWTDIAG_bExtBCluPedPrssPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDgoCoh_CluSt(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalMoteur_tournant;
   boolean bLocalInhCluSwtDiagEl;
   boolean bLocalExt_bCluPedPrss;
   uint8   u8LocalVitesse_vehicule;
   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalRequired_fuel_flow_rate;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Required_fuel_flow_rate, u16LocalRequired_fuel_flow_rate);

   if (  (u8LocalVitesse_vehicule > Cps_vit_veh_min_init_diag)
      && (u8LocalVitesse_vehicule < Cps_vit_veh_max_init_diag)
      && (u8LocalRegime_moteur_32 >= Cps_reg_mot_min_init_diag)
      && (u16LocalRequired_fuel_flow_rate >= Cps_req_fuel_min_init_diag) )
   {
      Clu_bDiagCohIninCdn = 1;
   }
   else
   {
      Clu_bDiagCohIninCdn = 0;
   }

   if (bLocalExt_bCluPedPrss != CLUSWTDIAG_bExtBCluPedPrssPrev)
   {
      Cps_controle_ok = 1;
   }
   else
   {
      Cps_controle_ok = 0;
   }

   bLocalInhCluSwtDiagEl = GDGAR_bGetFRM(FRM_FRM_INHCLUSWTDIAGEL);
   if (  (bLocalInhCluSwtDiagEl != 0)
      || (u8LocalVitesse_vehicule >= Cps_vitesse_max_diag_desac))
   {
      Clu_bDiagCohDacvn = 1;
   }
   else
   {
      Clu_bDiagCohDacvn = 0;
   }

   if (  (bLocalClef_de_contact != 0)
      && (bLocalMoteur_tournant != 0)
      && (u8LocalVitesse_vehicule >= Cps_vitesse_max_sans_debrayage))
   {
      Clu_bDiagCohCdn = 1;
   }
   else
   {
      Clu_bDiagCohCdn = 0;
   }
   CLUSWTDIAG_bExtBCluPedPrssPrev = bLocalExt_bCluPedPrss;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidCps_switch_mal_cpt                           */
/* !Description :  Le calcul réalisé ici est l’incrémentation du compteur de  */
/*                 défaut "Cps_switch_mal_utilise_cpt".                       */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Cps_switch_mal_utilise_cpt;                                   */
/*  output uint8 Cps_switch_mal_utilise_cpt;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidCps_switch_mal_cpt(void)
{
   uint8  u8Local_switch_mal_utilise_cpt;


   VEMS_vidGET(Cps_switch_mal_utilise_cpt, u8Local_switch_mal_utilise_cpt);
   if (u8Local_switch_mal_utilise_cpt < 255)
   {
      u8Local_switch_mal_utilise_cpt =
         (uint8)(u8Local_switch_mal_utilise_cpt + 1);
   }
   VEMS_vidSET(Cps_switch_mal_utilise_cpt, u8Local_switch_mal_utilise_cpt);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDiagStuck_CluSt                              */
/* !Description :  Cette fonction gère la génération des variables            */
/*                 Ext_bDgoStuck_CluSt et Ext_bMonRunStuck_CluSt.             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  dobregon                                                   */
/* !Trace_To    :  VEMS_R_08_04680_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUSWTDIAG_vidDiagStuckAcvn();                           */
/*  extf argret void CLUSWTDIAG_vidDiagStuckInitTempo();                      */
/*  extf argret void CLUSWTDIAG_vidDiagStuckDft();                            */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 Cps_vit_veh_min_init_diag;                                    */
/*  input uint8 Cps_vit_veh_max_init_diag;                                    */
/*  input boolean Cps_controle_ok;                                            */
/*  input boolean Clu_bDiagStuckCtrDacvn;                                     */
/*  input boolean CLUSWTDIAG_bRisingCompInit_prev;                            */
/*  input uint8 Clu_spdMaxStuck_C;                                            */
/*  input uint16 Cps_emb_tempo;                                               */
/*  input uint16 Cps_tempo_emb_max;                                           */
/*  input boolean CLUSWTDIAG_bMonRunStuck_prev;                               */
/*  output boolean Clu_bDiagStuckCtrDacvn;                                    */
/*  output boolean CLUSWTDIAG_bRisingCompInit_prev;                           */
/*  output boolean Clu_bDiagStuckCtrInin;                                     */
/*  output boolean Clu_bMonRunStuck_CluSt;                                    */
/*  output boolean CLUSWTDIAG_bMonRunStuck_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDiagStuck_CluSt(void)
{
   boolean bLocalRisingEdgeInit;
   boolean bLocalClu_MonRunStuck_CluSt;
   boolean bLocalClef_de_contact;
   uint8   u8LocalVitesse_vehicule;


   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (  (u8LocalVitesse_vehicule > Cps_vit_veh_min_init_diag)
      && (u8LocalVitesse_vehicule < Cps_vit_veh_max_init_diag))
   {
      bLocalRisingEdgeInit = 1;
   }
   else
   {
      bLocalRisingEdgeInit = 0;
   }

   if (  (Cps_controle_ok != 0)
      || (bLocalClef_de_contact == 0))
   {
      Clu_bDiagStuckCtrDacvn = 1;
   }
   else
   {
      Clu_bDiagStuckCtrDacvn = 0;
   }

   if (  (Clu_bDiagStuckCtrDacvn != 0)
      || (  (bLocalRisingEdgeInit != 0)
         && (CLUSWTDIAG_bRisingCompInit_prev == 0)))
   {
      CLUSWTDIAG_vidDiagStuckAcvn();
   }
   CLUSWTDIAG_bRisingCompInit_prev = bLocalRisingEdgeInit;


   if (  (Cps_controle_ok != 0)
      || (u8LocalVitesse_vehicule < Clu_spdMaxStuck_C))
   {
      Clu_bDiagStuckCtrInin = 1;
      CLUSWTDIAG_vidDiagStuckInitTempo();
   }
   else
   {
      Clu_bDiagStuckCtrInin = 0;
   }

   if (Cps_emb_tempo >= Cps_tempo_emb_max)
   {
      bLocalClu_MonRunStuck_CluSt = 1;
   }
   else
   {
      bLocalClu_MonRunStuck_CluSt = 0;
   }

   if (  (Cps_controle_ok != 0)
      || (  (bLocalClu_MonRunStuck_CluSt != 0)
         && (CLUSWTDIAG_bMonRunStuck_prev == 0)))
   {
      Clu_bMonRunStuck_CluSt = 1;
      CLUSWTDIAG_vidDiagStuckDft();
   }
   else
   {
      Clu_bMonRunStuck_CluSt = 0;
   }
   CLUSWTDIAG_bMonRunStuck_prev = bLocalClu_MonRunStuck_CluSt;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidTempoCoh                                     */
/* !Description :  Calcul de la temporisation du diagnostic de cohérence,     */
/*                 lorsque l’indicateur télécodé de présence du capteur       */
/*                 d’embrayage est à la valeur 1.                             */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Clu_bDiagCohCtrInin;                                        */
/*  input uint8 Cps_controle_coh_delay;                                       */
/*  input uint8 Cps_controle_coh_tempo;                                       */
/*  input boolean Clu_bDiagCohCtrAcvn;                                        */
/*  output uint8 Cps_controle_coh_tempo;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidTempoCoh(void)
{
   uint8 u8LocalCpsControleCohTempo;


   if (Clu_bDiagCohCtrInin != 0)
   {
      u8LocalCpsControleCohTempo = Cps_controle_coh_delay;
   }
   else
   {
      u8LocalCpsControleCohTempo = Cps_controle_coh_tempo;
   }

   if (Clu_bDiagCohCtrAcvn != 0)
   {
      if (u8LocalCpsControleCohTempo > 0)
      {
         Cps_controle_coh_tempo = (uint8)(u8LocalCpsControleCohTempo - 1);
      }
   }
   else
   {
      Cps_controle_coh_tempo = u8LocalCpsControleCohTempo;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidTempoStuck                                   */
/* !Description :  Calcul de la temporisation du diagnostic de plausibilité   */
/*                 temporel, lorsque l’indicateur télécodé de présence du     */
/*                 capteur d’embrayage est à la valeur 1.                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Clu_bDiagStuckCtrInin;                                      */
/*  input boolean Clu_bDiagStuckCtrAcvn;                                      */
/*  input uint16 Cps_emb_tempo;                                               */
/*  input uint16 Cps_tempo_emb_max;                                           */
/*  output uint16 Cps_emb_tempo;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidTempoStuck(void)
{
   uint32 u32LocalCpsEmbTempo;


   if (Clu_bDiagStuckCtrInin != 0)
   {
      Cps_emb_tempo = 0;
   }
   else
   {
      if (Clu_bDiagStuckCtrAcvn != 0)
      {
         u32LocalCpsEmbTempo = Cps_emb_tempo + 1;
      }
      else
      {
         u32LocalCpsEmbTempo = Cps_emb_tempo;
      }

      u32LocalCpsEmbTempo = MATHSRV_udtMIN(Cps_tempo_emb_max,
                                           u32LocalCpsEmbTempo);
      Cps_emb_tempo = (uint16)MATHSRV_udtMIN(u32LocalCpsEmbTempo, 900);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDiagStuckAcvn                                */
/* !Description :  Fonction de production de Clu_bDiagStuckCtrAcvn            */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Clu_bDiagStuckCtrDacvn;                                     */
/*  output boolean Clu_bDiagStuckCtrAcvn;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDiagStuckAcvn(void)
{
   if (Clu_bDiagStuckCtrDacvn != 0)
   {
      Clu_bDiagStuckCtrAcvn = 0;
   }
   else
   {
      Clu_bDiagStuckCtrAcvn = 1;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDiagStuckInitTempo                           */
/* !Description :  Fonction d'initialisation de Cps_emb_tempo.                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Cps_emb_tempo;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDiagStuckInitTempo(void)
{
   Cps_emb_tempo = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDiagStuckDft                                 */
/* !Description :  Fonction de production de Clu_bDgoStuck_CluSt.             */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Cps_controle_ok;                                            */
/*  output boolean Clu_bDgoStuck_CluSt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : Y.FENDRI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDiagStuckDft(void)
{
   if (Cps_controle_ok != 0)
   {
      Clu_bDgoStuck_CluSt = 0;
   }
   else
   {
      Clu_bDgoStuck_CluSt = 1;
   }
}
/*------------------------------- end of file --------------------------------*/