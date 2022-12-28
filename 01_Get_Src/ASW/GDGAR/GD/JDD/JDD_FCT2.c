/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : JDD                                                     */
/* !Description     : JDD Component                                           */
/*                                                                            */
/* !Module          : JDD                                                     */
/* !Description     : Gestionnaire du Journal Des Défauts                     */
/*                                                                            */
/* !File            : JDD_FCT2.C                                              */
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
/*   1 / JDD_vidFillBufferContextFailure                                      */
/*   2 / JDD_vidStartFaultSending                                             */
/*   3 / JDD_vidAcqFrame772                                                   */
/*   4 / JDD_vidAcqFrame55F                                                   */
/*   5 / JDD_vidReqClrDft                                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5447356 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/JDD/JDD_FCT2.C_v             $*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "JDD.h"
#include "JDD_L.h"
#include "JDD_IM.h"
#include "VEMS.h"

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidFillBufferContextFailure                            */
/* !Description :  La gestion du remplissage dans le Buffer des évènements    */
/*                 défauts à émettre peut être inhibé par calibration         */
/*                 (Jbsi_manu_inh).                                           */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Jbsi_manu_inh;                                              */
/*  input uint8 Jbsi_nbre_panne_en_attente;                                   */
/*  input uint16 Jbsi_au16idxDftNoCxt[30];                                    */
/*  input uint8 Jbsi_au8stCxtRecNoCxt[30];                                    */
/*  input uint32 GD_NoDTC_C[350];                                             */
/*  input boolean JDD_bEvtFailurePerm[350];                                   */
/*  output uint8 Jbsi_nbre_panne_en_attente;                                  */
/*  output uint8 Jbsi_au8stCxtRecNoCxt[30];                                   */
/*  output uint8 Jbsi_au8idxFltToCxtNoCxt[30];                                */
/*  output uint32 Jbsi_au32noDTCNoCxt[30];                                    */
/*  output boolean Jbsi_abstDTCNoCxt[30];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidFillBufferContextFailure
(
   uint16 u16IdxDft
)
{
   boolean bLocalEndFlag;
   boolean bLocalDIAGCAN_IntegratElect;
   sint32  s32LocalIdx;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_IntegratElect);
   if (  (Jbsi_manu_inh == 0)
      && (bLocalDIAGCAN_IntegratElect == 0))
   {
      if (Jbsi_nbre_panne_en_attente < JBSI_NB_CTXT)
      {
         bLocalEndFlag = 0;
         for(s32LocalIdx = 0;
             ((s32LocalIdx < JBSI_NB_CTXT) && (bLocalEndFlag == 0));
             s32LocalIdx++)
         {
            if (  (Jbsi_au16idxDftNoCxt[s32LocalIdx] == u16IdxDft)
               && (Jbsi_au8stCxtRecNoCxt[s32LocalIdx] == 1))
            {
               bLocalEndFlag = 1;
               Jbsi_nbre_panne_en_attente =
                  (uint8)(Jbsi_nbre_panne_en_attente + 1);

               Jbsi_au8stCxtRecNoCxt[s32LocalIdx] = 2;
               Jbsi_au8idxFltToCxtNoCxt[s32LocalIdx] =
                  Jbsi_nbre_panne_en_attente;
               Jbsi_au32noDTCNoCxt[s32LocalIdx] = GD_NoDTC_C[u16IdxDft];
               Jbsi_abstDTCNoCxt[s32LocalIdx] =
                   JDD_bEvtFailurePerm[u16IdxDft];
            }
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidStartFaultSending                                   */
/* !Description :  Cette fonction gère la préparation des données des         */
/*                 différentes trames de l’évènement défaut à émettre         */
/*                 l’architecture AEE en place.                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Jbsi_au8idxFltToCxtNoCxt[30];                                 */
/*  input uint32 Jbsi_au32noDTCNoCxt[30];                                     */
/*  input boolean Jbsi_abstDTCNoCxt[30];                                      */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint32 Jbsi_au32idxBuffer01NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer03NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer04NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer05NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer06NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer07NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer08NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer09NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer02NoCxt[30];                               */
/*  input uint32 Jbsi_au32idxBuffer10NoCxt[30];                               */
/*  input uint32 Jbsi_reference_horaire;                                      */
/*  input uint32 Jbsi_cpt_temp_local_av_synchro;                              */
/*  output uint32 Jbsi_code_defaut;                                           */
/*  output boolean Jbsi_etat_dtc;                                             */
/*  output uint32 Jbsi_kilometrage;                                           */
/*  output uint8 Jbsi_info_moteur_therm;                                      */
/*  output st111 Jbsi_etat_rcd;                                               */
/*  output boolean Jbsi_pertinence_info_bsi;                                  */
/*  output uint8 Jbsi_shunt_parc_bsi;                                         */
/*  output uint8 Jbsi_etat_reseau_electrique;                                 */
/*  output uint8 Jbsi_etat_principal_sev;                                     */
/*  output uint8 Jbsi_etat_alimentation;                                      */
/*  output uint32 Jbsi_ref_horaire;                                           */
/*  output uint8 Jbsi_Ld_feedback;                                            */
/*  output uint8 Jbsi_pDsThrMes;                                              */
/*  output uint8 Jbsi_spdVeh;                                                 */
/*  output uint8 Jbsi_Lbd_closed_loop;                                        */
/*  output uint16 Jbsi_nEng;                                                  */
/*  output uint8 Jbsi_tCoMes;                                                 */
/*  output uint8 Jbsi_engine_air_load;                                        */
/*  output uint8 Jbsi_Correct_lente;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidStartFaultSending(void)
{
   boolean bLocalEndFlag;
   boolean bLocalExt_bArchiCf;
   boolean bLocalJbsi_etat_dtc;
   uint8   u8LocalShParc;
   uint8   u8LocalResEle;
   uint8   u8LocalPrincipalSev;
   uint8   u8LocalAlim;
   uint8   u8LocalMoteur;
   uint8   u8LocalInfo;
   uint8   u8LocalEtaRcd;
   uint8   u8LocalJbsi_Lbd_closed_loop;
   uint8   u8LocalJbsi_spdVeh;
   uint8   u8LocalJbsi_engine_air_load;
   uint8   u8LocalJbsi_Ld_feedback;
   uint8   u8LocalJbsi_Correct_lente;
   uint8   u8LocaltCoMes;
   uint8   u8LocalJbsi_pDsThrMes;
   uint8   u8LocalJbsi_tCoMes;
   uint16  u16LocalJbsi_nEng;
   sint32  s32LocalIdx;
   uint32  u32LocalDate;
   uint32  u32LocalDiff;
   uint32  u32Local;
   uint32  u32LocalJbsi_ref_horaire;
   uint32  u32LocalJbsi_reference_horaire;
   uint32  u32Localkilometrage;
   uint32  u32LocalJbsi_code_defaut;


   bLocalEndFlag = 0;
   for(s32LocalIdx = 0;
      (s32LocalIdx < JBSI_NB_CTXT) && (bLocalEndFlag == 0);
      s32LocalIdx++)
   {
      if (Jbsi_au8idxFltToCxtNoCxt[s32LocalIdx] == 1)
      {
         u32LocalJbsi_code_defaut = Jbsi_au32noDTCNoCxt[s32LocalIdx];
         VEMS_vidSET(Jbsi_code_defaut, u32LocalJbsi_code_defaut);
         bLocalJbsi_etat_dtc = Jbsi_abstDTCNoCxt[s32LocalIdx];
         if (bLocalJbsi_etat_dtc != 0)
         {
            VEMS_vidSET(Jbsi_etat_dtc, 1);
         }
         else
         {
            VEMS_vidSET(Jbsi_etat_dtc, 0);
         }

         VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
         if (bLocalExt_bArchiCf != 0)
         {
            /* AEE 2010 */
            u32Localkilometrage =
               Jbsi_au32idxBuffer01NoCxt[s32LocalIdx];
            u32Localkilometrage = MATHSRV_udtMIN(u32Localkilometrage,
                                                 16777214);
            VEMS_vidSET(Jbsi_kilometrage, u32Localkilometrage);

            u8LocalMoteur =
               (uint8)Jbsi_au32idxBuffer03NoCxt[s32LocalIdx];
            u8LocalMoteur = (uint8)MATHSRV_udtCLAMP(u8LocalMoteur, 1, 15);
            VEMS_vidSET(Jbsi_info_moteur_therm, u8LocalMoteur);

            u8LocalEtaRcd =
               (uint8)Jbsi_au32idxBuffer04NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_etat_rcd, u8LocalEtaRcd);


            u8LocalInfo = (uint8)Jbsi_au32idxBuffer05NoCxt[s32LocalIdx];

            if (u8LocalInfo != 0)
            {
               VEMS_vidSET(Jbsi_pertinence_info_bsi, 1);
            }
            else
            {
               VEMS_vidSET(Jbsi_pertinence_info_bsi, 0);
            }

            u8LocalShParc =
               (uint8)Jbsi_au32idxBuffer06NoCxt[s32LocalIdx];
            u8LocalShParc = (uint8)MATHSRV_udtMIN(u8LocalShParc, 3);
            VEMS_vidSET(Jbsi_shunt_parc_bsi, u8LocalShParc);

            u8LocalResEle =
               (uint8)Jbsi_au32idxBuffer07NoCxt[s32LocalIdx];
            u8LocalResEle = (uint8)MATHSRV_udtMIN(u8LocalResEle, 15);
            VEMS_vidSET(Jbsi_etat_reseau_electrique, u8LocalResEle);

            u8LocalPrincipalSev =
               (uint8)Jbsi_au32idxBuffer08NoCxt[s32LocalIdx];
            u8LocalPrincipalSev =
                  (uint8)MATHSRV_udtMIN(u8LocalPrincipalSev, 3);
            VEMS_vidSET(Jbsi_etat_principal_sev, u8LocalPrincipalSev);

            u8LocalAlim = (uint8)Jbsi_au32idxBuffer09NoCxt[s32LocalIdx];
            u8LocalAlim = (uint8)MATHSRV_udtMIN(u8LocalAlim, 7);
            VEMS_vidSET(Jbsi_etat_alimentation, u8LocalAlim);

            u32LocalDate =  Jbsi_au32idxBuffer02NoCxt[s32LocalIdx];
            if (Jbsi_au32idxBuffer10NoCxt[s32LocalIdx] == 1)
            {
               if (u32LocalDate == UINT32_MAX)
               {
                  u32LocalJbsi_ref_horaire = UINT32_MAX;
               }
               else
               {
                  VEMS_vidGET(Jbsi_reference_horaire,
                              u32LocalJbsi_reference_horaire);
                  if (u32LocalJbsi_reference_horaire >=
                      Jbsi_cpt_temp_local_av_synchro)
                  {
                     u32LocalDiff = ( u32LocalJbsi_reference_horaire
                                    - Jbsi_cpt_temp_local_av_synchro);
                     u32Local = UINT32_MAX - u32LocalDate;
                     if (u32LocalDiff >= u32Local)
                     {
                        u32LocalJbsi_ref_horaire = UINT32_MAX;
                     }
                     else
                     {
                        u32LocalJbsi_ref_horaire = ( u32LocalDiff
                                                   + u32LocalDate);
                     }
                  }
                  else
                  {
                     u32LocalJbsi_ref_horaire = UINT32_MAX;
                  }
               }
            }
            else
            {
               u32LocalJbsi_ref_horaire = u32LocalDate;
            }
            VEMS_vidSET(Jbsi_ref_horaire, u32LocalJbsi_ref_horaire);
         }

         if (bLocalExt_bArchiCf == 0)
         {
            /* AEE 2004 */
            u8LocalJbsi_Ld_feedback =
               (uint8)Jbsi_au32idxBuffer01NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_Ld_feedback, u8LocalJbsi_Ld_feedback);

            u8LocalJbsi_pDsThrMes =
               (uint8)Jbsi_au32idxBuffer02NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_pDsThrMes, u8LocalJbsi_pDsThrMes);

            u8LocalJbsi_spdVeh =
               (uint8)Jbsi_au32idxBuffer03NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_spdVeh, u8LocalJbsi_spdVeh);

            u8LocalJbsi_Lbd_closed_loop =
               (uint8)Jbsi_au32idxBuffer04NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_Lbd_closed_loop, u8LocalJbsi_Lbd_closed_loop);

            u16LocalJbsi_nEng =
               (uint16)Jbsi_au32idxBuffer06NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_nEng, u16LocalJbsi_nEng);

            u8LocaltCoMes =
               (uint8)Jbsi_au32idxBuffer07NoCxt[s32LocalIdx];
            u8LocalJbsi_tCoMes = (uint8)MATHSRV_udtMIN(u8LocaltCoMes, 254);
            VEMS_vidSET(Jbsi_tCoMes, u8LocalJbsi_tCoMes);

            u8LocalJbsi_engine_air_load =
               (uint8)Jbsi_au32idxBuffer08NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_engine_air_load, u8LocalJbsi_engine_air_load);

            u8LocalJbsi_Correct_lente =
               (uint8)Jbsi_au32idxBuffer10NoCxt[s32LocalIdx];
            VEMS_vidSET(Jbsi_Correct_lente, u8LocalJbsi_Correct_lente);
         }
         bLocalEndFlag = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidAcqFrame772                                         */
/* !Description :  Cette fonction est exécutée à chaque réception de la trame */
/*                 d’acquittement du journal BSI (AEE 2004).                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Ext_stJDDAnsw;                                                */
/*  input uint8 JDD_u8JbsiEtatAutomatePrev;                                   */
/*  output boolean Jbsi_ack_bsi;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidAcqFrame772(void)
{
   boolean bLocalExt_bArchiCf;
   uint8   u8LocalExt_stJDDAnsw;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_stJDDAnsw, u8LocalExt_stJDDAnsw);

   if (  (bLocalExt_bArchiCf == 0)
      && (  (JDD_u8JbsiEtatAutomatePrev == JBSI_ATTENTE_ACQUITTEMENT)
         || (JDD_u8JbsiEtatAutomatePrev == JBSI_ATTENTE_RESTART_PROCESSUS))
      && (u8LocalExt_stJDDAnsw == JBSI_ACK_CMM_772))
   {
      Jbsi_ack_bsi = 1;
   }
   else
   {
      Jbsi_ack_bsi = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidAcqFrame55F                                         */
/* !Description :  Cette fonction est exécutée à chaque réception de la trame */
/*                 d’acquittement du journal BSI (AEE 2010).                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Jbsi_acq_trame55F;                                            */
/*  input uint8 JDD_u8JbsiEtatAutomatePrev;                                   */
/*  output boolean Jbsi_ack_bsi;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidAcqFrame55F(void)
{
   boolean bLocalExt_bArchiCf;
   uint8   u8LocalJbsi_acq_trame55F;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Jbsi_acq_trame55F, u8LocalJbsi_acq_trame55F);

   if (  (bLocalExt_bArchiCf != 0)
      && (  (JDD_u8JbsiEtatAutomatePrev == JBSI_ATTENTE_ACQUITTEMENT)
         || (JDD_u8JbsiEtatAutomatePrev == JBSI_ATTENTE_RESTART_PROCESSUS))
      && (u8LocalJbsi_acq_trame55F == JBSI_ACK_CMM_55F))
   {
      Jbsi_ack_bsi = 1;
   }
   else
   {
      Jbsi_ack_bsi = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidReqClrDft                                           */
/* !Description :  Lors d'une requête d'effacement des défauts ou par passage */
/*                 à 1 du CLRDTC de la  trame 92h, le buffer est réinitialisé */
/*                 et le nombre de pannes en attente passe à 0                */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Jbsi_nbre_panne_en_attente;                                  */
/*  output uint8 Jbsi_au8stCxtRecNoCxt[30];                                   */
/*  output uint16 Jbsi_au16idxDftNoCxt[30];                                   */
/*  output uint8 Jbsi_au8idxFltToCxtNoCxt[30];                                */
/*  output uint32 Jbsi_au32noDTCNoCxt[30];                                    */
/*  output boolean Jbsi_abstDTCNoCxt[30];                                     */
/*  output uint32 Jbsi_au32idxBuffer01NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer02NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer03NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer04NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer05NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer06NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer07NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer08NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer09NoCxt[30];                              */
/*  output uint32 Jbsi_au32idxBuffer10NoCxt[30];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidReqClrDft(void)
{
   sint32 s32LocalIdx;


   Jbsi_nbre_panne_en_attente = 0;

   for (s32LocalIdx = 0;
        s32LocalIdx < JBSI_NB_CTXT;
        s32LocalIdx++)
   {
      Jbsi_au8stCxtRecNoCxt[s32LocalIdx] = 0;
      Jbsi_au16idxDftNoCxt[s32LocalIdx] = 0;
      Jbsi_au8idxFltToCxtNoCxt[s32LocalIdx] = 0;
      Jbsi_au32noDTCNoCxt[s32LocalIdx] = 0;
      Jbsi_abstDTCNoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer01NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer02NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer03NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer04NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer05NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer06NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer07NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer08NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer09NoCxt[s32LocalIdx] = 0;
      Jbsi_au32idxBuffer10NoCxt[s32LocalIdx] = 0;
   }
}
/*------------------------------- end of file --------------------------------*/