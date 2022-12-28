/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTRTSTOP                                             */
/* !Description     : ENGSTRTSTOP Component                                   */
/*                                                                            */
/* !Module          : ENGSTRTSTOP                                             */
/* !Description     : DEMARRAGE ET ARRET MOTEUR                               */
/*                                                                            */
/* !File            : ENGSTRTSTOP_FCT1.C                                      */
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
/*   1 / ENGSTRTSTOP_vidInitialization                                        */
/*   2 / ENGSTRTSTOP_vidInitOutput                                            */
/*   3 / ENGSTRTSTOP_vidEngStopCond                                           */
/*   4 / ENGSTRTSTOP_vidKeyStopCond                                           */
/*   5 / ENGSTRTSTOP_vidEngStateDmlCalc                                       */
/*   6 / ENGSTRTSTOP_vidCmdCranking                                           */
/*   7 / ENGSTRTSTOP_vidInitAutoInjStlCrk                                     */
/*   8 / ENGSTRTSTOP_vidControlAutoInj                                        */
/*   9 / ENGSTRTSTOP_vidEveStallRunning                                       */
/*                                                                            */
/* !Reference   : V02 NT 08 05182 / 14                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ENGSTRTSTOP/ENGSTRTSTOP_FCT1.c_v  $*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   24 Aug 2012 $*/
/* $Author::   achebino                               $$Date::   24 Aug 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGSTRTSTOP.h"
#include "ENGSTRTSTOP_L.h"
#include "ENGSTRTSTOP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidInitialization                              */
/* !Description :  Fonctions d'nitialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Clef_off_on_sans_dem_init;                                  */
/*  input boolean First_crank;                                                */
/*  output boolean Arret_moteur_clef;                                         */
/*  output boolean Dml_auto_injection;                                        */
/*  output boolean Cranking_retry;                                            */
/*  output boolean Throttle_cranking_retry;                                   */
/*  output boolean Clef_off_on_sans_dem;                                      */
/*  output boolean Clef_off_on_sans_dem_init;                                 */
/*  output boolean Ext_bEngReStrt;                                            */
/*  output boolean Ext_bFirstStrt;                                            */
/*  output boolean Dml_auto_injection_prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidInitialization(void)
{
   boolean bLocalFirst_crank;


   VEMS_vidSET(Arret_moteur_clef,1);
   VEMS_vidSET(Dml_auto_injection,0);
   VEMS_vidSET(Cranking_retry,0);
   VEMS_vidSET(Throttle_cranking_retry,0);
   VEMS_vidSET(Clef_off_on_sans_dem,Clef_off_on_sans_dem_init);
   VEMS_vidSET(Ext_bEngReStrt,0);
   VEMS_vidGET(First_crank,bLocalFirst_crank);
   VEMS_vidSET(Ext_bFirstStrt,bLocalFirst_crank);
   Dml_auto_injection_prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidInitOutput                                  */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean EngSt_bMemrTrans_stEng;                                    */
/*  output boolean ENGSTRTSTOP_bAcvChangeOfMindPrev;                          */
/*  output boolean Dml_arret_moteur;                                          */
/*  output boolean ENGSTRTSTOP_bMainEngStopReqPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidInitOutput(void)
{
   EngSt_bMemrTrans_stEng = 0;
   ENGSTRTSTOP_bAcvChangeOfMindPrev = 0;
   VEMS_vidSET(Dml_arret_moteur, 0);
   ENGSTRTSTOP_bMainEngStopReqPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidEngStopCond                                 */
/* !Description :  Cette fonction définit si l’arrêt moteur est dû à une      */
/*                 coupure clef après un calage                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGSTRTSTOP_vidKeyStopCond();                            */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 ENGSTRTSTOP_u8CoPTStstEngPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidEngStopCond(void)
{
   uint8 u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng,u8LocalCoPTSt_stEng);
   if (  (ENGSTRTSTOP_u8CoPTStstEngPrev == Engine_Running)
      && (u8LocalCoPTSt_stEng != Engine_Running))
   {
      ENGSTRTSTOP_vidKeyStopCond();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidKeyStopCond                                 */
/* !Description :  Le booléen Arret_moteur_clef indique si l’arrêt moteur est */
/*                 dû à une demande d'arrêt moteur par la BSI (TRUE) ou bien à*/
/*                 un calage (FALSE).                                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bMainEngStopReq;                                     */
/*  input boolean Clef_de_contact;                                            */
/*  output boolean Arret_moteur_clef;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidKeyStopCond(void)
{
   boolean bLocalCoPTSt_bMainEngStopReq;
   boolean bLocalClef_de_contact;


   VEMS_vidGET(CoPTSt_bMainEngStopReq,bLocalCoPTSt_bMainEngStopReq);
   VEMS_vidGET(Clef_de_contact,bLocalClef_de_contact);
   if (  (bLocalClef_de_contact == 0)
      || (bLocalCoPTSt_bMainEngStopReq != 0))
   {
      VEMS_vidSET(Arret_moteur_clef,1);
   }
   else
   {
      VEMS_vidSET(Arret_moteur_clef,0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidEngStateDmlCalc                             */
/* !Description :  Fonction qui définit un compteur d’incrémentation réalisé à*/
/*                 chaque démarrage moteur.                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 ENGSTRTSTOP_u8CoPTStstEngPrev;                                */
/*  input uint16 Dml_demarrage_count_eep;                                     */
/*  input boolean CoPTSt_bMainEngStopReq;                                     */
/*  input boolean VlvAct_bInEngStopAuth;                                      */
/*  input boolean VlvAct_bExEngStopAuth;                                      */
/*  output uint16 Dml_demarrage_count_eep;                                    */
/*  output boolean Dml_arret_moteur;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidEngStateDmlCalc(void)
{
   boolean bLocalCoPTSt_bMainEngStopReq;
   boolean bLocalVlvAct_bInEngStopAuth;
   boolean bLocalVlvAct_bExEngStopAuth;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalDml_demarrage_count_eep;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);

   if (  (ENGSTRTSTOP_u8CoPTStstEngPrev != Engine_Running)
      && (u8LocalCoPTSt_stEng == Engine_Running))
   {
      VEMS_vidGET(Dml_demarrage_count_eep,u16LocalDml_demarrage_count_eep);
      VEMS_vidSET(Dml_demarrage_count_eep,
                  (uint16)MATHSRV_udtMIN((u16LocalDml_demarrage_count_eep + 1),
                                         65535));
   }

   VEMS_vidGET(CoPTSt_bMainEngStopReq,bLocalCoPTSt_bMainEngStopReq);
   VEMS_vidGET(VlvAct_bInEngStopAuth,bLocalVlvAct_bInEngStopAuth);
   VEMS_vidGET(VlvAct_bExEngStopAuth,bLocalVlvAct_bExEngStopAuth);
   if (  (bLocalCoPTSt_bMainEngStopReq != 0)
      && (bLocalVlvAct_bInEngStopAuth != 0)
      && (bLocalVlvAct_bExEngStopAuth != 0)
      && (u8LocalVehicle_active_state != VS_STALL))
   {
      VEMS_vidSET(Dml_arret_moteur,1);
   }
   else
   {
      VEMS_vidSET(Dml_arret_moteur,0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidCmdCranking                                 */
/* !Description :  La commande démarreur est attribuée à la même fréquence    */
/*                 d’appel que la fonction DAGMP.(StaCtl_bStaReq=0 :          */
/*                 Interdiction de démarrer, StaCtl_bStaReq=1 : Autorisation  */
/*                 de démarrer.)                                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean StaCtl_bStaReq;                                             */
/*  input boolean Dml_cmd_cranking_manu_inh;                                  */
/*  output boolean Dml_cmd_cranking;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidCmdCranking(void)
{
   boolean bLocalStaCtl_bStaReq;


   VEMS_vidGET(StaCtl_bStaReq,bLocalStaCtl_bStaReq);
   if (  (bLocalStaCtl_bStaReq != 0)
      && (Dml_cmd_cranking_manu_inh == 0))
   {
      VEMS_vidSET(Dml_cmd_cranking,1);
   }
   else
   {
      VEMS_vidSET(Dml_cmd_cranking,0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidInitAutoInjStlCrk                           */
/* !Description :  L'injection n'est autorisée qu'à la transition             */
/*                 "cale_tournant" et jusqu'à une demande d'arrêt moteur ou   */
/*                 une coupure du réveil principal.                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dml_auto_injection;                                        */
/*  output boolean Dml_auto_injection_prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidInitAutoInjStlCrk(void)
{
   VEMS_vidSET(Dml_auto_injection, 1);
   Dml_auto_injection_prev = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidControlAutoInj                              */
/* !Description :  Lorsqu'une demande d'arrêt moteur par la BSI est reçue, on */
/*                 doit lui renvoyer l'état du moteur égal à coupé ou calé,   */
/*                 alors elle peut désactiver sa demande d'arrêt,             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Dml_arret_moteur;                                           */
/*  input boolean EngSt_bAcvChangeOfMind;                                     */
/*  input boolean CoPTSt_bMainEngStopReq;                                     */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean EngSt_bInhChangeOfMind_C;                                   */
/*  input boolean ENGSTRTSTOP_bAcvChangeOfMindPrev;                           */
/*  input boolean EngSt_bInhMainEngStopReq_C;                                 */
/*  input boolean ENGSTRTSTOP_bMainEngStopReqPrev;                            */
/*  input boolean EngSt_bBypInjAuthCond_C;                                    */
/*  input boolean Dml_auto_injection_prev;                                    */
/*  output boolean Dml_auto_injection_prev;                                   */
/*  output boolean ENGSTRTSTOP_bAcvChangeOfMindPrev;                          */
/*  output boolean ENGSTRTSTOP_bMainEngStopReqPrev;                           */
/*  output boolean Dml_auto_injection;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidControlAutoInj(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalDml_arret_moteur;
   boolean bLocalbAcvChangeOfMind;
   boolean bLocalDmlAutoInjection;
   boolean bLocalCoPTSt_bMainEngStopReq;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Dml_arret_moteur, bLocalDml_arret_moteur);
   VEMS_vidGET(EngSt_bAcvChangeOfMind, bLocalbAcvChangeOfMind);
   VEMS_vidGET(CoPTSt_bMainEngStopReq, bLocalCoPTSt_bMainEngStopReq);

   if (  (bLocalClef_de_contact == 0)
      || (  (bLocalDml_arret_moteur != 0)
         && (Rcd_mode_active != 0)))
   {
      bLocalDmlAutoInjection = 0;
   }
   else
   {
      if (  (  (EngSt_bInhChangeOfMind_C == 0)
            && (bLocalbAcvChangeOfMind != 0)
            && (ENGSTRTSTOP_bAcvChangeOfMindPrev == 0))
         || (  (EngSt_bInhMainEngStopReq_C == 0)
            && (bLocalCoPTSt_bMainEngStopReq == 0)
            && (ENGSTRTSTOP_bMainEngStopReqPrev != 0))
         || (EngSt_bBypInjAuthCond_C != 0))
      {
         bLocalDmlAutoInjection = 1;
      }
      else
      {
         bLocalDmlAutoInjection = Dml_auto_injection_prev;
      }
   }

   Dml_auto_injection_prev = bLocalDmlAutoInjection;
   ENGSTRTSTOP_bAcvChangeOfMindPrev = bLocalbAcvChangeOfMind;
   ENGSTRTSTOP_bMainEngStopReqPrev = bLocalCoPTSt_bMainEngStopReq;
   VEMS_vidSET(Dml_auto_injection, bLocalDmlAutoInjection);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTRTSTOP_vidEveStallRunning                             */
/* !Description :  Fonction qui permet de calculer Cranking_retry lors du     */
/*                 passage de l'état stall vers running.                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Time_since_stall;                                            */
/*  input boolean Date_emf_available_mux;                                     */
/*  input boolean Cranking_retry;                                             */
/*  input uint16 Date_emf_retry_thresh_delay;                                 */
/*  input boolean Manu_inh_retry_emf;                                         */
/*  output boolean Cranking_retry;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTRTSTOP_vidEveStallRunning(void)
{
   boolean bLocalDate_emf_available_mux;
   boolean bLocalCranking_retry;
   uint32  u32LocalTime_since_stall;


   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidGET(Date_emf_available_mux, bLocalDate_emf_available_mux);
   VEMS_vidGET(Cranking_retry, bLocalCranking_retry);
   if (u32LocalTime_since_stall >= Date_emf_retry_thresh_delay)
   {
      VEMS_vidSET(Cranking_retry, 0);
   }
   else
   {
      if (  (bLocalDate_emf_available_mux != 0)
         && (Manu_inh_retry_emf == 0)
         && (bLocalCranking_retry == 0))
      {
         VEMS_vidSET(Cranking_retry, 1);
      }
   }
}
/*----------------------------- end of file ----------------------------------*/