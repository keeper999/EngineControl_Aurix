/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPSWTACQDIAG                                          */
/* !Description     : ACCPSWTACQDIAG Component                                */
/*                                                                            */
/* !Module          : ACCPSWTACQDIAG                                          */
/* !Description     : IMPLEMENTATION DU TRAITEMENT DU CONTACTEUR ELECTRIQUE   */
/*                    LVV                                                     */
/*                                                                            */
/* !File            : ACCPSWTACQDIAG_FCT1.C                                   */
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
/*   1 / ACCPSWTACQDIAG_vidInitOutput                                         */
/*   2 / ACCPSWTACQDIAG_vidInitPointDur                                       */
/*   3 / ACCPSWTACQDIAG_vidLvvSwtAcqCond                                      */
/*   4 / ACCPSWTACQDIAG_vidLvvSwtAcq                                          */
/*   5 / ACCPSWTACQDIAG_vidLvvSwtDiagCond                                     */
/*   6 / ACCPSWTACQDIAG_vidLvvSwtDiag                                         */
/*   7 / ACCPSWTACQDIAG_vidMonitorMngCond                                     */
/*   8 / ACCPSWTACQDIAG_vidMonitoringMng                                      */
/*   9 / ACCPSWTACQDIAG_vidEndPointCohAff                                     */
/*   10 / ACCPSWTACQDIAG_vidEndPointAffKD                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6606841 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#050819                                         */
/* !OtherRefs   : VEMS V02 ECU#068754                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCP/ACCPSWTACQDIAG/ACCPSWTACQDIAG$*/
/* $Revision::   1.11     $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "ACCPSWTACQDIAG.H"
#include "ACCPSWTACQDIAG_L.H"
#include "ACCPSWTACQDIAG_IM.H"
#include "GDGAR.H"
#include "VEMS.H"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidInitOutput                               */
/* !Description :  Initialisation des variables produites par le module       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*  output boolean Etat_point_dur_prev;                                       */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidInitOutput(void)
{
   Lvv_cpt1_chg_etat_ou_rehab_def = 0;
   Lvv_cpt2_confirm_defaut_elec = 0;
   Etat_point_dur_prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidInitPointDur                             */
/* !Description :  Initialisation du point dur                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Cc_accel_pedal_wot_request;                                */
/*  output boolean Ext_bAccPHdPt;                                             */
/*  output boolean Lvv_pt_dur_ad_conv;                                        */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output boolean Etat_point_dur;                                            */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Tempo_maintien_etat_pt_dur;                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidInitPointDur(void)
{
   /* Initialisation des variables de sortie */
   VEMS_vidSET(Cc_accel_pedal_wot_request, 1);
   VEMS_vidSET(Ext_bAccPHdPt, 0);
   VEMS_vidSET(Lvv_pt_dur_ad_conv, 0);
   VEMS_vidSET(Lvv_etat_capteur, LVV_STABLE_HAUT);
   VEMS_vidSET(Etat_point_dur, 0);
   Etat_point_dur_raw = 0;
   Tempo_maintien_etat_pt_dur = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidLvvSwtAcqCond                            */
/* !Description :  Condition d'acquisition et de diagnostic du point dur      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACCPSWTACQDIAG_vidLvvSwtAcq();                           */
/*  input boolean Presence_bva_pt_dur;                                        */
/*  input boolean Presence_bvmp_pt_dur;                                       */
/*  input boolean Ext_bVSLimCf;                                               */
/*  output boolean Lvv_pt_dur_ad_conv;                                        */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidLvvSwtAcqCond(void)
{
   boolean bLocalPresence_bva_pt_dur;
   boolean bLocalPresence_bvmp_pt_dur;
   boolean bLocalExt_bVSLimCf;


   VEMS_vidGET(Presence_bva_pt_dur, bLocalPresence_bva_pt_dur);
   VEMS_vidGET(Presence_bvmp_pt_dur, bLocalPresence_bvmp_pt_dur);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);
   if (  (bLocalPresence_bva_pt_dur != 0)
      || (bLocalPresence_bvmp_pt_dur != 0)
      || (bLocalExt_bVSLimCf != 0))
   {
      VEMS_vidSET(Lvv_pt_dur_ad_conv, 1);
      ACCPSWTACQDIAG_vidLvvSwtAcq();
   }
   else
   {
      VEMS_vidSET(Lvv_pt_dur_ad_conv, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidLvvSwtAcq                                */
/* !Description :  Acquisition du signal point dur au cours du temps          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00973_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acqui_tension_contacteur_pt_dur;                             */
/*  output uint16 Lvv_pt_dur_result_ad_conv;                                  */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidLvvSwtAcq(void)
{
   uint16  u16LocalpPtDurResultAdConv;


   VEMS_vidGET(Acqui_tension_contacteur_pt_dur, u16LocalpPtDurResultAdConv);
   Lvv_pt_dur_result_ad_conv =
      (uint16)MATHSRV_udtMIN(u16LocalpPtDurResultAdConv, 4095);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidLvvSwtDiagCond                           */
/* !Description :  Condition de diagnostique de l'état de la tension du       */
/*                 contacteur LVV                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPSWTACQDIAG_vidLvvSwtDiag();                          */
/*  input boolean Lvv_pt_dur_ad_conv;                                         */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidLvvSwtDiagCond(void)
{
   boolean bLocalLvv_pt_dur_ad_conv;


   VEMS_vidGET(Lvv_pt_dur_ad_conv, bLocalLvv_pt_dur_ad_conv);
   if (bLocalLvv_pt_dur_ad_conv != 0)
   {
      ACCPSWTACQDIAG_vidLvvSwtDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidLvvSwtDiag                               */
/* !Description :  Les pannes à monter ou à descendre en fonction de la       */
/*                 tension du contacteur LVV sonde                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00973_002.01                                     */
/*                 VEMS_R_09_00973_003.01                                     */
/*                 VEMS_R_09_00973_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 Lvv_pt_dur_result_ad_conv;                                   */
/*  input uint16 Lvv_u_sup_plage_valide_basse;                                */
/*  input uint16 Lvv_u_inf_plage_valide_basse;                                */
/*  input uint16 Lvv_u_sup_plage_valide_haute;                                */
/*  input uint16 Lvv_u_inf_plage_valide_haute;                                */
/*  input uint16 Lvv_seuil_detection_cc_masse;                                */
/*  input uint16 Lvv_seuil_detection_cc_vbat;                                 */
/*  output boolean Lvv_valid_basse;                                           */
/*  output boolean Lvv_valid_haute;                                           */
/*  output boolean AccP_bMonRunScpAccPSwt;                                    */
/*  output boolean AccP_bMonRunStuckAccPSwt;                                  */
/*  output boolean AccP_bMonRunScgAccPSwt;                                    */
/*  output boolean AccP_bDgoScpAccPSwt;                                       */
/*  output boolean AccP_bDgoStuckAccPSwt;                                     */
/*  output boolean AccP_bDgoScgAccPSwt;                                       */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidLvvSwtDiag(void)
{
   boolean bLocalInhAccPSwtDiagEl;
   boolean bLocalAccPDgoScpAccPSwt;
   boolean bLocalAccPDgoStuckAccPSwt;
   boolean bLocalAccPDgoScgAccPSwt;


   if (  (Lvv_pt_dur_result_ad_conv <= Lvv_u_sup_plage_valide_basse)
      && (Lvv_pt_dur_result_ad_conv > Lvv_u_inf_plage_valide_basse))
   {
      Lvv_valid_basse = 1;
   }
   else
   {
      Lvv_valid_basse = 0;
   }
   if (  (Lvv_pt_dur_result_ad_conv <= Lvv_u_sup_plage_valide_haute)
      && (Lvv_pt_dur_result_ad_conv > Lvv_u_inf_plage_valide_haute))
   {
      Lvv_valid_haute = 1;
   }
   else
   {
      Lvv_valid_haute = 0;
   }

   if (Lvv_pt_dur_result_ad_conv > Lvv_u_inf_plage_valide_basse)
   {
      bLocalAccPDgoScpAccPSwt = 0;
      bLocalAccPDgoStuckAccPSwt = 0;
      bLocalAccPDgoScgAccPSwt = 0;
   }
   else
   {
      if (Lvv_pt_dur_result_ad_conv > Lvv_seuil_detection_cc_masse)
      {
         bLocalAccPDgoScpAccPSwt = 0;
         bLocalAccPDgoStuckAccPSwt = 1;
         bLocalAccPDgoScgAccPSwt = 0;
      }
      else
      {
         bLocalAccPDgoScpAccPSwt = 0;
         bLocalAccPDgoStuckAccPSwt = 0;
         bLocalAccPDgoScgAccPSwt = 1;
      }
   }

   bLocalInhAccPSwtDiagEl = GDGAR_bGetFRM(FRM_FRM_INHACCPSWTDIAGEL);
   if (bLocalInhAccPSwtDiagEl != 0)
   {
      AccP_bMonRunScpAccPSwt = 0;
      AccP_bMonRunStuckAccPSwt = 0;
      AccP_bMonRunScgAccPSwt = 0;
      AccP_bDgoScpAccPSwt = 0;
      AccP_bDgoStuckAccPSwt = 0;
      AccP_bDgoScgAccPSwt = 0;
   }
   else
   {
      AccP_bMonRunScpAccPSwt = 1;
      AccP_bMonRunStuckAccPSwt = 1;
      AccP_bMonRunScgAccPSwt = 1;
      if (Lvv_pt_dur_result_ad_conv >= Lvv_seuil_detection_cc_vbat)
      {
         AccP_bDgoScpAccPSwt = 1;
         AccP_bDgoStuckAccPSwt = 0;
         AccP_bDgoScgAccPSwt = 0;
      }
      else
      {
         if (Lvv_pt_dur_result_ad_conv > Lvv_u_sup_plage_valide_haute)
         {
            AccP_bDgoScpAccPSwt = 0;
            AccP_bDgoStuckAccPSwt = 1;
            AccP_bDgoScgAccPSwt = 0;
         }
         else
         {
            if (Lvv_pt_dur_result_ad_conv > Lvv_u_inf_plage_valide_haute)
            {
               AccP_bDgoScpAccPSwt = 0;
               AccP_bDgoStuckAccPSwt = 0;
               AccP_bDgoScgAccPSwt = 0;
            }
            else
            {
               if (Lvv_pt_dur_result_ad_conv > Lvv_u_sup_plage_valide_basse)
               {
                  AccP_bDgoScpAccPSwt = 0;
                  AccP_bDgoStuckAccPSwt = 1;
                  AccP_bDgoScgAccPSwt = 0;
               }
               else
               {
                  AccP_bDgoScpAccPSwt = bLocalAccPDgoScpAccPSwt;
                  AccP_bDgoStuckAccPSwt = bLocalAccPDgoStuckAccPSwt;
                  AccP_bDgoScgAccPSwt = bLocalAccPDgoScgAccPSwt;
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidMonitorMngCond                           */
/* !Description :  Le traitement du signal capteur du contacteur electrique   */
/*                 LVV est fait après une demande d’acquisition analogique sur*/
/*                 la voie LVV_PT_DUR                                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00973_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPSWTACQDIAG_vidMonitoringMng();                       */
/*  input boolean Lvv_pt_dur_ad_conv;                                         */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidMonitorMngCond(void)
{
   boolean bLocalLvv_pt_dur_ad_conv;


   VEMS_vidGET(Lvv_pt_dur_ad_conv, bLocalLvv_pt_dur_ad_conv);
   if (bLocalLvv_pt_dur_ad_conv != 0)
   {
      ACCPSWTACQDIAG_vidMonitoringMng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidMonitoringMng                            */
/* !Description :  Traitement du signal du capteur du contacteur electrique   */
/*                 pour juger l’information et sa stabilité                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPSWTACQDIAG_vidHightStabTrans();                      */
/*  extf argret void ACCPSWTACQDIAG_vidTempoHightTrans();                     */
/*  extf argret void ACCPSWTACQDIAG_vidTempoInvTrans();                       */
/*  extf argret void ACCPSWTACQDIAG_vidTempoLowTrans();                       */
/*  extf argret void ACCPSWTACQDIAG_vidLowStableTrans();                      */
/*  extf argret void ACCPSWTACQDIAG_vidHightFailTrans();                      */
/*  extf argret void ACCPSWTACQDIAG_vidInvFailTrans();                        */
/*  extf argret void ACCPSWTACQDIAG_vidLowFailTrans();                        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st11 Lvv_etat_capteur;                                              */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidMonitoringMng(void)
{
   uint8 u8localLvv_etat_capteur;


   VEMS_vidGET(Lvv_etat_capteur, u8localLvv_etat_capteur);
   switch (u8localLvv_etat_capteur)
   {
      case LVV_STABLE_HAUT:
         ACCPSWTACQDIAG_vidHightStabTrans();
         break;

      case LVV_TRANSITOIRE_HAUT:
         ACCPSWTACQDIAG_vidTempoHightTrans();
         break;

      case LVV_TRANSITOIRE_INVALIDE:
         ACCPSWTACQDIAG_vidTempoInvTrans();
         break;

      case LVV_TRANSITOIRE_BAS:
         ACCPSWTACQDIAG_vidTempoLowTrans();
         break;

      case LVV_STABLE_BAS:
         ACCPSWTACQDIAG_vidLowStableTrans();
         break;

      case DEFAUT_HAUT:
         ACCPSWTACQDIAG_vidHightFailTrans();
         break;

      case DEFAUT_INVALIDE:
         ACCPSWTACQDIAG_vidInvFailTrans();
         break;

      case DEFAUT_BAS:
         ACCPSWTACQDIAG_vidLowFailTrans();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(Lvv_etat_capteur, LVV_STABLE_HAUT);
         Etat_point_dur_raw = NON_FRANCHI;
         Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         Lvv_cpt2_confirm_defaut_elec = 0;
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidEndPointCohAff                           */
/* !Description :  Contrôle de  la cohérence entre l’état point dur et        */
/*                 l’enfoncement de la pédale et affectation de l’indicateur  */
/*                 de  passage  point  dur                                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPSWTACQDIAG_vidEndPointPedCoh();                      */
/*  extf argret void ACCPSWTACQDIAG_vidEndPointAffKD();                       */
/*  extf argret void ACCPSWTACQDIAG_vidAccPedSwtAff();                        */
/*  input boolean Lvv_pt_dur_ad_conv;                                         */
/*  input boolean AccP_bDgoScpAccPSwt;                                        */
/*  input boolean AccP_bDgoStuckAccPSwt;                                      */
/*  input boolean AccP_bDgoScgAccPSwt;                                        */
/*  input boolean Etat_point_dur;                                             */
/*  output boolean AccP_bMonRunCohAccPSwt;                                    */
/*  output boolean Etat_point_dur_prev;                                       */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidEndPointCohAff(void)
{
   boolean bLocalLvv_pt_dur_ad_conv;
   boolean bLocalCfmInCohHdPt;
   boolean bLocalIAcvAccPSwtCalc;
   boolean bLocalEtat_point_dur;


   bLocalIAcvAccPSwtCalc = GDGAR_bGetFRM(FRM_FRM_ACVACCPSWTCALC);
   VEMS_vidGET(Lvv_pt_dur_ad_conv, bLocalLvv_pt_dur_ad_conv);

   if (  (bLocalIAcvAccPSwtCalc == 0)
      && (bLocalLvv_pt_dur_ad_conv != 0))
   {
      AccP_bMonRunCohAccPSwt = 1;
      ACCPSWTACQDIAG_vidEndPointPedCoh();
   }
   else
   {
      AccP_bMonRunCohAccPSwt = 0;
   }

   bLocalCfmInCohHdPt = GDGAR_bGetFRM(FRM_FRM_CFMINCOHHDPT);
   if (bLocalLvv_pt_dur_ad_conv != 0)
   {
      if (  (bLocalCfmInCohHdPt != 0)
         || (AccP_bDgoScpAccPSwt != 0)
         || (AccP_bDgoStuckAccPSwt != 0)
         || (AccP_bDgoScgAccPSwt != 0))
      {
         ACCPSWTACQDIAG_vidEndPointAffKD();
      }
      else
      {
         ACCPSWTACQDIAG_vidAccPedSwtAff();
      }
   }
   VEMS_vidGET(Etat_point_dur, bLocalEtat_point_dur);
   Etat_point_dur_prev = bLocalEtat_point_dur;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidEndPointAffKD                            */
/* !Description :  Ce bloc décrit le cas où il y'a un défaut électrique du    */
/*                 capteur point dur , ou un défaut de cohérence entre pédale */
/*                 d’accélération et information point dur est confirmé.      */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACCPSWTACQDIAG_vidEndPtInstTempo();                      */
/*  extf argret void ACCPSWTACQDIAG_vidEndPtCounter();                        */
/*  input boolean Etat_point_dur_prev;                                        */
/*  input uint16 Tempo_maintien_etat_pt_dur;                                  */
/*  input uint16 Delai_maintien_etat_pt_dur;                                  */
/*  output boolean Cc_accel_pedal_wot_request;                                */
/*  output boolean Ext_bAccPHdPt;                                             */
/*  output boolean Etat_point_dur;                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidEndPointAffKD(void)
{
   VEMS_vidSET(Cc_accel_pedal_wot_request, 0);
   VEMS_vidSET(Ext_bAccPHdPt, 0);
   if (  (Etat_point_dur_prev != 0)
      && (Tempo_maintien_etat_pt_dur == 0))
   {
      /* 1_tempo_instantane_point_dur */
      ACCPSWTACQDIAG_vidEndPtInstTempo();
   }
   else
   {
      /* 3_compteur_point_dur */
      ACCPSWTACQDIAG_vidEndPtCounter();
   }

   if (Tempo_maintien_etat_pt_dur > Delai_maintien_etat_pt_dur)
   {
      VEMS_vidSET(Etat_point_dur, 1);
   }
   else
   {
      VEMS_vidSET(Etat_point_dur, 0);
   }
}
/*------------------------------- end of file --------------------------------*/