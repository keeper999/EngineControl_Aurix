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
/* !File            : JDD_FCT3.C                                              */
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
/*   1 / JDD_vidTransmissionFramesMngr                                        */
/*   2 / JDD_vidStateJbsiIdle                                                 */
/*   3 / JDD_vidStateJbsiWaitSendFrame1                                       */
/*   4 / JDD_vidStateJbsiWaitSendFrame2                                       */
/*   5 / JDD_vidStateJbsiWaitSendFrame3                                       */
/*   6 / JDD_vidStateJbsiWaitAcquittement                                     */
/*   7 / JDD_vidStateJbsiWaitRestartProc                                      */
/*   8 / JDD_vidTransToIdleOrSendFrame1                                       */
/*   9 / JDD_vidRstAckBsi                                                     */
/*   10 / JDD_vidDftClrData                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5447356 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/JDD/JDD_FCT3.C_v             $*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "JDD.h"
#include "JDD_L.h"
#include "JDD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidTransmissionFramesMngr                              */
/* !Description :  Cette fonction traite de la gestion du séquencement de     */
/*                 l’émission des évènements défauts vers le calculateur BSI. */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_007.01                                     */
/*                 VEMS_R_10_08914_008.01                                     */
/*                 VEMS_R_10_08914_009.01                                     */
/*                 VEMS_R_10_08914_010.01                                     */
/*                 VEMS_R_10_08914_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidStateJbsiIdle();                                  */
/*  extf argret void JDD_vidStateJbsiWaitSendFrame1();                        */
/*  extf argret void JDD_vidStateJbsiWaitSendFrame2();                        */
/*  extf argret void JDD_vidStateJbsiWaitSendFrame3();                        */
/*  extf argret void JDD_vidStateJbsiWaitAcquittement();                      */
/*  extf argret void JDD_vidStateJbsiWaitRestartProc();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st112 Jbsi_etat_automate;                                           */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output boolean Jbsi_autorise_fin_power_latch;                             */
/*  output uint8 Jbsi_nbre_panne_en_attente;                                  */
/*  output uint8 Jbsi_tentative_envoi;                                        */
/*  output uint8 Jbsi_tentative_envoi_processus;                              */
/*  output uint8 Jbsi_time_out;                                               */
/*  output uint8 Jbsi_tempo_envoi_trame;                                      */
/*  output uint8 Jbsi_tempo_restart_processus;                                */
/*  output uint8 JDD_u8JbsiEtatAutomatePrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidTransmissionFramesMngr(void)
{

   switch(Jbsi_etat_automate)
   {
      case JBSI_IDLE:
         JDD_vidStateJbsiIdle();
         break;

      case JBSI_ATTENTE_ENVOI_TRAME_1:
         JDD_vidStateJbsiWaitSendFrame1();
         break;

      case JBSI_ATTENTE_ENVOI_TRAME_2:
         JDD_vidStateJbsiWaitSendFrame2();
         break;

      case JBSI_ATTENTE_ENVOI_TRAME_3:
         JDD_vidStateJbsiWaitSendFrame3();
         break;

      case JBSI_ATTENTE_ACQUITTEMENT:
         JDD_vidStateJbsiWaitAcquittement();
         break;

      case JBSI_ATTENTE_RESTART_PROCESSUS:
         JDD_vidStateJbsiWaitRestartProc();
         break;

      default :
         Jbsi_etat_automate = JBSI_IDLE;
         VEMS_vidSET(Jbsi_autorise_fin_power_latch, 1);
         Jbsi_nbre_panne_en_attente = 0;
         Jbsi_tentative_envoi = 0;
         Jbsi_tentative_envoi_processus = 0;
         Jbsi_time_out = 0;
         Jbsi_tempo_envoi_trame = 0;
         Jbsi_tempo_restart_processus = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   JDD_u8JbsiEtatAutomatePrev = Jbsi_etat_automate;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidStateJbsiIdle                                       */
/* !Description :  Transition de l'état JBSI_IDLE                             */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void JDD_vidStartFaultSending();                              */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Jbsi_bFirstSyncRx;                                          */
/*  input uint8 Jbsi_nbre_panne_en_attente;                                   */
/*  input uint8 Jbsi_tentative_envoi;                                         */
/*  output boolean Jbsi_autorise_fin_power_latch;                             */
/*  output uint8 Jbsi_tentative_envoi_processus;                              */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output uint8 Jbsi_tentative_envoi;                                        */
/*  output uint8 Jbsi_numero_trame;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidStateJbsiIdle(void)
{
   boolean bLocalExt_bArchiCf;
   boolean bLocalJbsi_bFirstSyncRx;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Jbsi_bFirstSyncRx, bLocalJbsi_bFirstSyncRx);

   if (  (Jbsi_nbre_panne_en_attente > 0)
      && (  (bLocalExt_bArchiCf == 0) || (bLocalJbsi_bFirstSyncRx != 0)))
   {
      VEMS_vidSET(Jbsi_autorise_fin_power_latch, 0);
      Jbsi_tentative_envoi_processus = 1;
      JDD_vidStartFaultSending();
      Jbsi_etat_automate = JBSI_ATTENTE_ENVOI_TRAME_1;
      if (Jbsi_tentative_envoi < 255 )
      {
         Jbsi_tentative_envoi = (uint8)(Jbsi_tentative_envoi + 1);
      }
      VEMS_vidSET(Jbsi_numero_trame, 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidStateJbsiWaitSendFrame1                             */
/* !Description :  Transition de l'état JBSI_ATTENTE_ENVOI_TRAME_1            */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDD_vidPrepaDataIscanBuffer();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Jbsi_tempo_envoi_trame;                                       */
/*  input boolean Jbsi_manu_inh_3_trames_evt_fug;                             */
/*  input uint8 Jbsi_tentative_envoi;                                         */
/*  input uint8 Jbsi_calib_tentative_envoi;                                   */
/*  input uint8 Jbsi_tempo_restart_proc_delay;                                */
/*  input uint8 Jbsi_calib_time_out;                                          */
/*  input uint8 Jbsi_calib_tempo_envoi_trame;                                 */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output uint8 Jbsi_tempo_restart_processus;                                */
/*  output uint8 Jbsi_time_out;                                               */
/*  output uint8 Jbsi_numero_trame;                                           */
/*  output uint8 Jbsi_tempo_envoi_trame;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidStateJbsiWaitSendFrame1(void)
{
   boolean bLocalExt_bArchiCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (Jbsi_tempo_envoi_trame <= 1)
   {
      if (Jbsi_manu_inh_3_trames_evt_fug != 0)
      {
         if (bLocalExt_bArchiCf == 0)
         {
            JDD_vidPrepaDataIscanBuffer();
            if (Jbsi_tentative_envoi < Jbsi_calib_tentative_envoi)
            {
               Jbsi_etat_automate = JBSI_ATTENTE_ACQUITTEMENT;
            }
            else
            {
               Jbsi_etat_automate = JBSI_ATTENTE_RESTART_PROCESSUS;
               Jbsi_tempo_restart_processus = Jbsi_tempo_restart_proc_delay;
            }
            Jbsi_time_out = Jbsi_calib_time_out;
         }
      }
      else
      {
         JDD_vidPrepaDataIscanBuffer();
         Jbsi_etat_automate = JBSI_ATTENTE_ENVOI_TRAME_2;
         VEMS_vidSET(Jbsi_numero_trame, 2);
         Jbsi_tempo_envoi_trame = Jbsi_calib_tempo_envoi_trame;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidStateJbsiWaitSendFrame2                             */
/* !Description :  Transition de l'état JBSI_ATTENTE_ENVOI_TRAME_2            */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDD_vidPrepaDataIscanBuffer();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Jbsi_tempo_envoi_trame;                                       */
/*  input uint8 Jbsi_tentative_envoi;                                         */
/*  input uint8 Jbsi_calib_tentative_envoi;                                   */
/*  input uint8 Jbsi_tempo_restart_proc_delay;                                */
/*  input uint8 Jbsi_calib_time_out;                                          */
/*  input uint8 Jbsi_calib_tempo_envoi_trame;                                 */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output uint8 Jbsi_tempo_restart_processus;                                */
/*  output uint8 Jbsi_time_out;                                               */
/*  output uint8 Jbsi_numero_trame;                                           */
/*  output uint8 Jbsi_tempo_envoi_trame;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidStateJbsiWaitSendFrame2(void)
{
   boolean bLocalExt_bArchiCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (Jbsi_tempo_envoi_trame <= 1)
   {
      JDD_vidPrepaDataIscanBuffer();
      if (bLocalExt_bArchiCf != 0)
      {
         if (Jbsi_tentative_envoi < Jbsi_calib_tentative_envoi)
         {
            Jbsi_etat_automate = JBSI_ATTENTE_ACQUITTEMENT;
         }
         else
         {
            Jbsi_etat_automate = JBSI_ATTENTE_RESTART_PROCESSUS;
            Jbsi_tempo_restart_processus = Jbsi_tempo_restart_proc_delay;
         }
         Jbsi_time_out = Jbsi_calib_time_out;
      }
      else
      {
         Jbsi_etat_automate = JBSI_ATTENTE_ENVOI_TRAME_3;
         VEMS_vidSET(Jbsi_numero_trame, 3);
         Jbsi_tempo_envoi_trame = Jbsi_calib_tempo_envoi_trame;
      }
   }
   else
   {
      Jbsi_tempo_envoi_trame = (uint8)(Jbsi_tempo_envoi_trame - 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidStateJbsiWaitSendFrame3                             */
/* !Description :  Transition de l'état JBSI_ATTENTE_ENVOI_TRAME_3            */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidPrepaDataIscanBuffer();                           */
/*  input uint8 Jbsi_tempo_envoi_trame;                                       */
/*  input uint8 Jbsi_tentative_envoi;                                         */
/*  input uint8 Jbsi_calib_tentative_envoi;                                   */
/*  input uint8 Jbsi_tempo_restart_proc_delay;                                */
/*  input uint8 Jbsi_calib_time_out;                                          */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output uint8 Jbsi_tempo_restart_processus;                                */
/*  output uint8 Jbsi_time_out;                                               */
/*  output uint8 Jbsi_tempo_envoi_trame;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidStateJbsiWaitSendFrame3(void)
{
   if (Jbsi_tempo_envoi_trame <= 1)
   {
      JDD_vidPrepaDataIscanBuffer();
      if (Jbsi_tentative_envoi < Jbsi_calib_tentative_envoi)
      {
         Jbsi_etat_automate = JBSI_ATTENTE_ACQUITTEMENT;
      }
      else
      {
         Jbsi_etat_automate = JBSI_ATTENTE_RESTART_PROCESSUS;
         Jbsi_tempo_restart_processus = Jbsi_tempo_restart_proc_delay;
      }
      Jbsi_time_out = Jbsi_calib_time_out;
   }
   else
   {
      Jbsi_tempo_envoi_trame = (uint8)(Jbsi_tempo_envoi_trame - 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidStateJbsiWaitAcquittement                           */
/* !Description :  Transition de l'état JBSI_ATTENTE_ACQUITTEMENT             */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidRstAckBsi();                                      */
/*  extf argret void JDD_vidDftClrData();                                     */
/*  extf argret void JDD_vidTransToIdleOrSendFrame1();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Jbsi_ack_bsi;                                               */
/*  input uint8 Jbsi_time_out;                                                */
/*  input uint8 Jbsi_nbre_panne_en_attente;                                   */
/*  input uint8 Jbsi_tentative_envoi;                                         */
/*  output uint8 Jbsi_nbre_panne_en_attente;                                  */
/*  output uint8 Jbsi_time_out;                                               */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output uint8 Jbsi_tentative_envoi;                                        */
/*  output uint8 Jbsi_numero_trame;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidStateJbsiWaitAcquittement(void)
{
   if (Jbsi_ack_bsi != 0)
   {
      if (Jbsi_time_out == 2)
      {
         if (Jbsi_nbre_panne_en_attente > 0)
         {
            Jbsi_nbre_panne_en_attente =
               (uint8)(Jbsi_nbre_panne_en_attente - 1);
         }
         JDD_vidRstAckBsi();
         JDD_vidDftClrData();
         JDD_vidTransToIdleOrSendFrame1();
      }
      else
      {
         Jbsi_time_out = (uint8)(Jbsi_time_out - 1);
      }
   }
   else
   {
      if (Jbsi_time_out <= 2)
      {
         JDD_vidRstAckBsi();
         Jbsi_etat_automate = JBSI_ATTENTE_ENVOI_TRAME_1;
         Jbsi_tentative_envoi = (uint8)(Jbsi_tentative_envoi + 1);
         VEMS_vidSET(Jbsi_numero_trame, 1);
      }
      else
      {
         Jbsi_time_out = (uint8)(Jbsi_time_out - 1);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidStateJbsiWaitRestartProc                            */
/* !Description :  Transition de l'état JBSI_ATTENTE_RESTART_PROCESSUS        */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidRstAckBsi();                                      */
/*  extf argret void JDD_vidDftClrData();                                     */
/*  extf argret void JDD_vidTransToIdleOrSendFrame1();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Jbsi_ack_bsi;                                               */
/*  input uint8 Jbsi_time_out;                                                */
/*  input uint8 Jbsi_nbre_panne_en_attente;                                   */
/*  input uint8 Jbsi_tempo_restart_processus;                                 */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Jbsi_tentative_envoi_processus;                               */
/*  input uint8 Jbsi_calib_tentative_envoi_proc;                              */
/*  output uint8 Jbsi_nbre_panne_en_attente;                                  */
/*  output uint8 Jbsi_tentative_envoi_processus;                              */
/*  output uint8 Jbsi_tentative_envoi;                                        */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output uint8 Jbsi_numero_trame;                                           */
/*  output uint8 Jbsi_time_out;                                               */
/*  output uint8 Jbsi_tempo_restart_processus;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidStateJbsiWaitRestartProc(void)
{
   boolean bLocalExt_bArchiCf;

   if (  (Jbsi_ack_bsi != 0)
      && (Jbsi_time_out == 2))
   {
      JDD_vidRstAckBsi();
      if (Jbsi_nbre_panne_en_attente > 0)
      {
         Jbsi_nbre_panne_en_attente = (uint8)(Jbsi_nbre_panne_en_attente - 1);
      }
      JDD_vidDftClrData();
      JDD_vidTransToIdleOrSendFrame1();
   }
   else
   {
      if (  (Jbsi_time_out <= 2)
         && (Jbsi_tempo_restart_processus <= 2))
      {
         VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
         if (  (bLocalExt_bArchiCf == 1)
            && ( Jbsi_tentative_envoi_processus
               < Jbsi_calib_tentative_envoi_proc))
         {
            JDD_vidRstAckBsi();
            Jbsi_tentative_envoi_processus =
               (uint8)(Jbsi_tentative_envoi_processus + 1);
            Jbsi_tentative_envoi = 1;
            Jbsi_etat_automate = JBSI_ATTENTE_ENVOI_TRAME_1;
            VEMS_vidSET(Jbsi_numero_trame, 1);
         }
         else
         {
            JDD_vidRstAckBsi();
            if (Jbsi_nbre_panne_en_attente > 0)
            {
               Jbsi_nbre_panne_en_attente =
                  (uint8)(Jbsi_nbre_panne_en_attente - 1);
            }
            JDD_vidDftClrData();
            JDD_vidTransToIdleOrSendFrame1();
         }
      }
      else
      {
         if (Jbsi_time_out > 0)
         {
            Jbsi_time_out = (uint8)(Jbsi_time_out - 1);
         }
         if (Jbsi_tempo_restart_processus > 0)
         {
            Jbsi_tempo_restart_processus =
               (uint8)(Jbsi_tempo_restart_processus - 1);
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidTransToIdleOrSendFrame1                             */
/* !Description :  Transition à l'état  JBSI_IDLE ou                          */
/*                 JBSI_ATTENTE_ENVOI_TRAME_1.                                */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void JDD_vidStartFaultSending();                              */
/*  input uint8 Jbsi_nbre_panne_en_attente;                                   */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output boolean Jbsi_autorise_fin_power_latch;                             */
/*  output uint8 Jbsi_tentative_envoi;                                        */
/*  output uint8 Jbsi_tentative_envoi_processus;                              */
/*  output uint8 Jbsi_time_out;                                               */
/*  output uint8 Jbsi_tempo_envoi_trame;                                      */
/*  output uint8 Jbsi_tempo_restart_processus;                                */
/*  output uint8 Jbsi_numero_trame;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidTransToIdleOrSendFrame1(void)
{

   if (Jbsi_nbre_panne_en_attente == 0)
   {
      Jbsi_etat_automate = JBSI_IDLE;
      VEMS_vidSET(Jbsi_autorise_fin_power_latch, 1);
      Jbsi_tentative_envoi = 0;
      Jbsi_tentative_envoi_processus = 0;
      Jbsi_time_out = 0;
      Jbsi_tempo_envoi_trame = 0;
      Jbsi_tempo_restart_processus = 0;
   }
   else
   {
      Jbsi_tentative_envoi = 1;
      Jbsi_tentative_envoi_processus = 1;
      JDD_vidStartFaultSending();
      Jbsi_etat_automate = JBSI_ATTENTE_ENVOI_TRAME_1;
      VEMS_vidSET(Jbsi_numero_trame, 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidRstAckBsi                                           */
/* !Description :  A chaque demande d’émission de la trame JDD par le manager,*/
/*                 le flag de réception de l’acquittement est  reseté.        */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Jbsi_ack_bsi;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidRstAckBsi(void)
{
   Jbsi_ack_bsi = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidDftClrData                                          */
/* !Description :  Cette fonction gère l’effacement du contexte associé à un  */
/*                 défaut lorsque celui-ci a été correctement transmis au BSI */
/*                 ou lorsque toutes les tentatives d’envoi de celui-ci ont   */
/*                 été épuisées.                                              */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Jbsi_au8idxFltToCxtNoCxt[30];                                 */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidDftClrData(void)
{
   boolean  bLocalEndFlag;
   sint32   s32LocalIdx;


   bLocalEndFlag = 0;
   for (s32LocalIdx = 0;
        (s32LocalIdx < JBSI_NB_CTXT) && (bLocalEndFlag == 0);
        s32LocalIdx++)
   {
      if (Jbsi_au8idxFltToCxtNoCxt[s32LocalIdx] == 1)
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
         bLocalEndFlag = 1;
      }
   }

   for(s32LocalIdx = 0 ; s32LocalIdx < JBSI_NB_CTXT; s32LocalIdx++)
   {
      if ( Jbsi_au8idxFltToCxtNoCxt[s32LocalIdx] > 0)
      {
      Jbsi_au8idxFltToCxtNoCxt[s32LocalIdx] =
            (uint8)(Jbsi_au8idxFltToCxtNoCxt[s32LocalIdx] - 1);
      }
   }
}
/*------------------------------- end of file --------------------------------*/