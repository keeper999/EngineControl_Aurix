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
/* !File            : JDD_FCT1.C                                              */
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
/*   1 / JDD_vidInitOutput                                                    */
/*   2 / JDD_vidIni                                                           */
/*   3 / JDD_vidTimeCounterBeforeSynchro                                      */
/*   4 / JDD_vidAcquisitionCptBeforSyncro                                     */
/*   5 / JDD_vidSetStateDtcPresent                                            */
/*   6 / JDD_vidSetStateDtcFugitf                                             */
/*   7 / JDD_vidCaptureData                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5447356 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/JDD/JDD_FCT1.C_v             $*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "JDD.h"
#include "JDD_L.h"
#include "JDD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidInitOutput                                          */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Jbsi_Correct_lente;                                          */
/*  output uint8 Jbsi_Lbd_closed_loop;                                        */
/*  output uint8 Jbsi_Ld_feedback;                                            */
/*  output uint32 Jbsi_code_defaut;                                           */
/*  output uint8 Jbsi_engine_air_load;                                        */
/*  output uint8 Jbsi_etat_alimentation;                                      */
/*  output boolean Jbsi_etat_dtc;                                             */
/*  output uint8 Jbsi_etat_principal_sev;                                     */
/*  output st111 Jbsi_etat_rcd;                                               */
/*  output uint8 Jbsi_etat_reseau_electrique;                                 */
/*  output uint8 Jbsi_info_moteur_therm;                                      */
/*  output uint32 Jbsi_kilometrage;                                           */
/*  output uint16 Jbsi_nEng;                                                  */
/*  output uint8 Jbsi_numero_trame;                                           */
/*  output uint8 Jbsi_pDsThrMes;                                              */
/*  output uint32 Jbsi_ref_horaire;                                           */
/*  output uint8 Jbsi_shunt_parc_bsi;                                         */
/*  output uint8 Jbsi_spdVeh;                                                 */
/*  output uint8 Jbsi_tCoMes;                                                 */
/*  output st112 Jbsi_etat_automate;                                          */
/*  output boolean Jbsi_autorise_fin_power_latch;                             */
/*  output uint8 Jbsi_nbre_panne_en_attente;                                  */
/*  output uint8 Jbsi_tentative_envoi;                                        */
/*  output uint8 Jbsi_tentative_envoi_processus;                              */
/*  output uint8 Jbsi_time_out;                                               */
/*  output uint8 Jbsi_tempo_envoi_trame;                                      */
/*  output uint8 Jbsi_tempo_restart_processus;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidInitOutput(void)
{
   VEMS_vidSET(Jbsi_Correct_lente, 0);
   VEMS_vidSET(Jbsi_Lbd_closed_loop, 0);
   VEMS_vidSET(Jbsi_Ld_feedback, 0);
   VEMS_vidSET(Jbsi_code_defaut, 0);
   VEMS_vidSET(Jbsi_engine_air_load, 0);
   VEMS_vidSET(Jbsi_etat_alimentation, 0);
   VEMS_vidSET(Jbsi_etat_dtc, 0);
   VEMS_vidSET(Jbsi_etat_principal_sev, 0);
   VEMS_vidSET(Jbsi_etat_rcd, 0);
   VEMS_vidSET(Jbsi_etat_reseau_electrique, 0);
   VEMS_vidSET(Jbsi_info_moteur_therm, 1);
   VEMS_vidSET(Jbsi_kilometrage, 0);
   VEMS_vidSET(Jbsi_nEng, 0);
   VEMS_vidSET(Jbsi_numero_trame, 0);
   VEMS_vidSET(Jbsi_pDsThrMes, 0);
   VEMS_vidSET(Jbsi_ref_horaire, 0);
   VEMS_vidSET(Jbsi_shunt_parc_bsi, 0);
   VEMS_vidSET(Jbsi_spdVeh, 0);
   VEMS_vidSET(Jbsi_tCoMes, 0);

   Jbsi_etat_automate = JBSI_IDLE;
   VEMS_vidSET(Jbsi_autorise_fin_power_latch, 1);
   Jbsi_nbre_panne_en_attente = 0;
   Jbsi_tentative_envoi = 0;
   Jbsi_tentative_envoi_processus = 0;
   Jbsi_time_out = 0;
   Jbsi_tempo_envoi_trame = 0;
   Jbsi_tempo_restart_processus = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidIni                                                 */
/* !Description :  A l’initialisation de l’ECU, les données statiques de      */
/*                 l’entête des différentes trames se configurent selon       */
/*                 l’architecture AEE en place.                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_003.01                                     */
/*                 VEMS_R_10_08914_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Jbsi_manu_inh_3_trames_evt_fug;                             */
/*  output boolean Jbsi_pertinence_info_bsi;                                  */
/*  output uint8 Jbsi_type_message;                                           */
/*  output uint8 Jbsi_nombre_trame;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidIni(void)
{
   boolean bLocalExt_bArchiCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidSET(Jbsi_pertinence_info_bsi, 1);
   if (bLocalExt_bArchiCf != 0)
   {
      VEMS_vidSET(Jbsi_type_message, 1);
      VEMS_vidSET(Jbsi_nombre_trame, 2);
   }
   else
   {
      VEMS_vidSET(Jbsi_type_message, 0);
      if (Jbsi_manu_inh_3_trames_evt_fug != 0)
      {
         VEMS_vidSET(Jbsi_nombre_trame, 1);
      }
      else
      {
         VEMS_vidSET(Jbsi_nombre_trame, 3);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidTimeCounterBeforeSynchro                            */
/* !Description :  Ce bloc traite de l’acquisition de la référence horaire    */
/*                 avant la première synchronisation (uniquement en AEE 2010).*/
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDD_vidAcquisitionCptBeforSyncro();                      */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Jbsi_bFirstSyncRx;                                          */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Jbsi_manu_inh;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidTimeCounterBeforeSynchro(void)
{
   boolean bLocalExt_bArchiCf;
   boolean bLocalJbsi_bFirstSyncRx;
   boolean bLocalDIAGCAN_bIntegratioElec;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Jbsi_bFirstSyncRx, bLocalJbsi_bFirstSyncRx);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegratioElec);
   if (  (bLocalJbsi_bFirstSyncRx == 0)
      && (bLocalExt_bArchiCf != 0)
      && (Jbsi_manu_inh == 0)
      && (bLocalDIAGCAN_bIntegratioElec == 0))
   {
      JDD_vidAcquisitionCptBeforSyncro();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidAcquisitionCptBeforSyncro                           */
/* !Description :  Acquisition de la référence horaire                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Jbsi_reference_horaire;                                      */
/*  output uint32 Jbsi_cpt_temp_local_av_synchro;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidAcquisitionCptBeforSyncro(void)
{
   uint32 u32LocalJbsi_reference_horaire;


   VEMS_vidGET(Jbsi_reference_horaire, u32LocalJbsi_reference_horaire);
   Jbsi_cpt_temp_local_av_synchro = u32LocalJbsi_reference_horaire;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidSetStateDtcPresent                                  */
/* !Description :  Indique que l’évènement défaut à émettre s’agit d’un défaut*/
/*                 confirmé.                                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean JDD_bEvtFailurePerm[350];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidSetStateDtcPresent
(
   uint16 u16IdxDft
)
{
   JDD_bEvtFailurePerm[u16IdxDft] = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidSetStateDtcFugitf                                   */
/* !Description :  Indique que l’évènement défaut à émettre s’agit d’un défaut*/
/*                 disparu.                                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean JDD_bEvtFailurePerm[350];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_vidSetStateDtcFugitf
(
   uint16 u16IdxDft
)
{
   JDD_bEvtFailurePerm[u16IdxDft] = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_vidCaptureData                                         */
/* !Description :  Ce bloc traite du figeage des paramètres (captures) pour   */
/*                 les 2 architecture AEE 2004 / 2010 lors de la détection ou */
/*                 de la confirmation d’absence d’un défaut.                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_10_08914_004.01                                     */
/*                 VEMS_R_10_08914_005.01                                     */
/*                 VEMS_R_10_08914_006.01                                     */
/*                 VEMS_R_10_08914_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Jbsi_manu_inh;                                              */
/*  input uint16 Jbsi_au16idxDftNoCxt[30];                                    */
/*  input uint8 Jbsi_au8stCxtRecNoCxt[30];                                    */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint32 Km_vehicle_mux;                                              */
/*  input uint32 Jbsi_reference_horaire;                                      */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input st09 Rcd_power_state;                                               */
/*  input uint32 Jbsi_au32idxBuffer05NoCxt[30];                               */
/*  input uint8 Jbsi_shunt_bsi;                                               */
/*  input uint8 CoReqVeh_stNetwEl;                                            */
/*  input uint8 Jbsi_etat_ppal_sev;                                           */
/*  input uint8 Ext_noJDD;                                                    */
/*  input boolean Jbsi_bFirstSyncRx;                                          */
/*  input uint8 Srv_Lfbk_Pid06;                                               */
/*  input uint8 Srv_pDsThrMes_Pid0B;                                          */
/*  input uint8 Srv_spdVeh_Pid0D;                                             */
/*  input uint8 Srv_Fuel_System_Pid03;                                        */
/*  input uint16 Srv_nEng_Pid0C;                                              */
/*  input uint8 Srv_tCoMes_Pid05;                                             */
/*  input uint8 Srv_Engine_load_Pid04;                                        */
/*  input uint8 Srv_Diag_trim_Pid07;                                          */
/*  output uint8 Jbsi_au8stCxtRecNoCxt[30];                                   */
/*  output uint16 Jbsi_au16idxDftNoCxt[30];                                   */
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
void JDD_vidCaptureData
(
   uint16 u16IdxDft
)
{
   boolean bLocalEndFlag;
   boolean bLocalAcvModBsiFail;
   boolean bLocalJbsi_bFirstSyncRx;
   boolean bLocalDIAGCAN_IntegratElect;
   boolean bLocalExt_bArchiCf;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalJbsi_shunt_bsi;
   uint8   u8LocalCoReqVeh_stNetwEl;
   uint8   u8LocalJbsi_etat_ppal_sev;
   uint8   u8LocalExt_noJDD;
   uint8   u8LocalRcd_power_state;
   uint8   u8LocalSrv_pDsThrMes_Pid0B;
   uint8   u8LocalSrv_spdVeh_Pid0D;
   uint8   u8LocalSrv_Fuel_System_Pid03;
   uint8   u8LocalSrv_Engine_load_Pid04;
   uint8   u8LocalSrv_tCoMes_Pid05;
   uint8   u8LocalSrv_Diag_trim_Pid07;
   uint8   u8LocalSrv_Lfbk_Pid06;
   uint16  u16LocalSrv_nEng_Pid0C;
   sint32  s32LocalIndCxt;
   sint32  s32LocalIdx;
   uint32  u32LocalJbsi_reference_horaire;
   uint32  u32LocalKm_vehicle_mux;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_IntegratElect);
   if (  (Jbsi_manu_inh == 0)
      && (bLocalDIAGCAN_IntegratElect == 0))
   {
      s32LocalIndCxt = 0xFF;

      bLocalEndFlag = 0;
      for( s32LocalIdx = 0;
          (s32LocalIdx < JBSI_NB_CTXT) && (bLocalEndFlag == 0);
           s32LocalIdx++)
      {
         if ((Jbsi_au16idxDftNoCxt[s32LocalIdx] == u16IdxDft)
            && (Jbsi_au8stCxtRecNoCxt[s32LocalIdx] == 1))
         {
            s32LocalIndCxt = s32LocalIdx;
            bLocalEndFlag = 1;
         }
      }

      if (s32LocalIndCxt == 0xFF)
      {
         bLocalEndFlag = 0;
         for(s32LocalIdx = 0;
             (  (s32LocalIdx < JBSI_NB_CTXT)
             && (bLocalEndFlag == 0));
             s32LocalIdx++)
         {
            if (Jbsi_au8stCxtRecNoCxt[s32LocalIdx] == 0)
            {
               s32LocalIndCxt = s32LocalIdx;
               bLocalEndFlag = 1;
            }
         }
      }

      if (s32LocalIndCxt != 0xFF)
      {
         Jbsi_au8stCxtRecNoCxt[s32LocalIndCxt] = 1;
         Jbsi_au16idxDftNoCxt[s32LocalIndCxt]= u16IdxDft;
      }

      VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
      if (  (bLocalExt_bArchiCf != 0)
         && (s32LocalIndCxt != 0xFF))
      {
         /* AEE 2010 */
         VEMS_vidGET(Km_vehicle_mux, u32LocalKm_vehicle_mux);
         Jbsi_au32idxBuffer01NoCxt[s32LocalIndCxt] =
            MATHSRV_udtMIN(u32LocalKm_vehicle_mux, 16777214);

         VEMS_vidGET(Jbsi_reference_horaire, u32LocalJbsi_reference_horaire);
         Jbsi_au32idxBuffer02NoCxt[s32LocalIndCxt] =
            u32LocalJbsi_reference_horaire;

         VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
         Jbsi_au32idxBuffer03NoCxt[s32LocalIndCxt] =
            (uint32)MATHSRV_udtCLAMP(u8LocalCoPTSt_stEng, 1, 15);

         VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
         switch(u8LocalRcd_power_state)
         {
         case RCD_TRANSIT:
            Jbsi_au32idxBuffer04NoCxt[s32LocalIndCxt] = JBSI_TRANSIT;
            break;

         case RCD_POWER_LATCH:
            Jbsi_au32idxBuffer04NoCxt[s32LocalIndCxt] = JBSI_POWER_LATCH;
            break;

         case RCD_ANTICIPATION:
            Jbsi_au32idxBuffer04NoCxt[s32LocalIndCxt] = JBSI_ANTICIPATION;
            break;

         case RCD_POWER_ON:
            Jbsi_au32idxBuffer04NoCxt[s32LocalIndCxt] = JBSI_POWER_ON;
            break;

         case RCD_POWER_ON_DEFAULT:
            Jbsi_au32idxBuffer04NoCxt[s32LocalIndCxt] =JBSI_POWER_ON_DEFAUT;
            break;

         default:
            Jbsi_au32idxBuffer04NoCxt[s32LocalIndCxt] = JBSI_POWER_ON;
            break;
         }

         bLocalAcvModBsiFail = GDGAR_bGetFRM(FRM_FRM_ACVMODBSIFAIL);
         Jbsi_au32idxBuffer05NoCxt[s32LocalIndCxt] = bLocalAcvModBsiFail;

         if (Jbsi_au32idxBuffer05NoCxt[s32LocalIndCxt] != 0)
         {
            Jbsi_au32idxBuffer06NoCxt[s32LocalIndCxt] = 0;
            Jbsi_au32idxBuffer07NoCxt[s32LocalIndCxt] = 0;
            Jbsi_au32idxBuffer08NoCxt[s32LocalIndCxt] = 0;
            Jbsi_au32idxBuffer09NoCxt[s32LocalIndCxt] = 0;
         }
         else
         {
            VEMS_vidGET(Jbsi_shunt_bsi, u8LocalJbsi_shunt_bsi);
            Jbsi_au32idxBuffer06NoCxt[s32LocalIndCxt] = u8LocalJbsi_shunt_bsi;

            VEMS_vidGET(CoReqVeh_stNetwEl, u8LocalCoReqVeh_stNetwEl);
            Jbsi_au32idxBuffer07NoCxt[s32LocalIndCxt] =
               u8LocalCoReqVeh_stNetwEl;

            VEMS_vidGET(Jbsi_etat_ppal_sev, u8LocalJbsi_etat_ppal_sev);
            Jbsi_au32idxBuffer08NoCxt[s32LocalIndCxt] =
               u8LocalJbsi_etat_ppal_sev;

            VEMS_vidGET(Ext_noJDD, u8LocalExt_noJDD);
            Jbsi_au32idxBuffer09NoCxt[s32LocalIndCxt] = u8LocalExt_noJDD;
         }

         VEMS_vidGET(Jbsi_bFirstSyncRx, bLocalJbsi_bFirstSyncRx);
         if (bLocalJbsi_bFirstSyncRx != 0)
         {
            Jbsi_au32idxBuffer10NoCxt[s32LocalIndCxt] = 0;
         }
         else
         {
            Jbsi_au32idxBuffer10NoCxt[s32LocalIndCxt] = 1;
         }
      }

      if (  (bLocalExt_bArchiCf == 0)
         && (s32LocalIndCxt != 0xFF))
      {
         /* AEE 2004 */
         VEMS_vidGET(Srv_Lfbk_Pid06, u8LocalSrv_Lfbk_Pid06);
         Jbsi_au32idxBuffer01NoCxt[s32LocalIndCxt] = u8LocalSrv_Lfbk_Pid06;

         VEMS_vidGET(Srv_pDsThrMes_Pid0B, u8LocalSrv_pDsThrMes_Pid0B);
         Jbsi_au32idxBuffer02NoCxt[s32LocalIndCxt] = u8LocalSrv_pDsThrMes_Pid0B;

         VEMS_vidGET(Srv_spdVeh_Pid0D, u8LocalSrv_spdVeh_Pid0D);
         Jbsi_au32idxBuffer03NoCxt[s32LocalIndCxt] = u8LocalSrv_spdVeh_Pid0D;

         VEMS_vidGET(Srv_Fuel_System_Pid03, u8LocalSrv_Fuel_System_Pid03);
         Jbsi_au32idxBuffer04NoCxt[s32LocalIndCxt] =
            u8LocalSrv_Fuel_System_Pid03;

         VEMS_vidGET(Srv_nEng_Pid0C, u16LocalSrv_nEng_Pid0C);
         Jbsi_au32idxBuffer06NoCxt[s32LocalIndCxt] = u16LocalSrv_nEng_Pid0C;

         VEMS_vidGET(Srv_tCoMes_Pid05, u8LocalSrv_tCoMes_Pid05);
         Jbsi_au32idxBuffer07NoCxt[s32LocalIndCxt] = u8LocalSrv_tCoMes_Pid05;

         VEMS_vidGET(Srv_Engine_load_Pid04, u8LocalSrv_Engine_load_Pid04);
         Jbsi_au32idxBuffer08NoCxt[s32LocalIndCxt] =
            u8LocalSrv_Engine_load_Pid04;

         VEMS_vidGET(Srv_Diag_trim_Pid07, u8LocalSrv_Diag_trim_Pid07);
         Jbsi_au32idxBuffer10NoCxt[s32LocalIndCxt] = u8LocalSrv_Diag_trim_Pid07;
      }
   }
}
/*------------------------------- end of file --------------------------------*/