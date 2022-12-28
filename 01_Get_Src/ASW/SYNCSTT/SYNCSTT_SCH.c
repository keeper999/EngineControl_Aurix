/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCSTT                                                 */
/* !Description     : SYNCSTT component.                                      */
/*                                                                            */
/* !Module          : SYNCSTT                                                 */
/* !Description     : Détermination de la synchronisation et position du      */
/*                    moteur                                                  */
/*                                                                            */
/* !File            : SYNCSTT_SCH.C                                           */
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
/*   1 / Sync_EveCkLTo_SyncSTT                                                */
/*   2 / Sync_EveCkOff_SyncSTT                                                */
/*   3 / Sync_EveCkOn_SyncSTT                                                 */
/*   4 / Sync_EveCkSnOf_SyncSTT                                               */
/*   5 / Sync_EveCkTo_SyncSTT                                                 */
/*   6 / Sync_EveExCamEdge_SyncSTT                                            */
/*   7 / Sync_EveInCamEdge_SyncSTT                                            */
/*   8 / Sync_EveRst_SyncSTT                                                  */
/*   9 / Sync_EveTDC_SyncSTT                                                  */
/*   10 / Sync_SdlMid_SyncSTT                                                 */
/*   11 / Sync_EveCkLTo1_SyncSTT                                              */
/*   12 / Sync_EveNInvOff_SyncSTT                                             */
/*   13 / Sync_SdlFast_SyncSTT                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6912870 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNCSTT/SYNCSTT_SCH.C_v           $*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   25 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   25 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "SYNCSTT.H"
#include "SYNCSTT_IM.H"
#include "SYNCSTT_L.H"
#include "VEMS.H"
#include "GDGAR.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkLTo_SyncSTT                                      */
/* !Description :  Evènement correspondant au passage de la dent longue du    */
/*                 vilebrequin                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidDetLTo();                                     */
/*  extf argret void SYNCSTT_vidOS1();                                        */
/*  extf argret void SYNCSTT_vidOS2();                                        */
/*  extf argret void SYNCSTT_vidEveProd();                                    */
/*  extf argret void SYNCSTT_vidDiagResult();                                 */
/*  extf argret void SYNCSTT_vidEngStopPosnAfter();                           */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Sync_bCalcOk;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkLTo_SyncSTT                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkLTo_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;
   uint16   u16LocalExt_nEng;


   if (SYNCSTT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         SYNCSTT_vidDetLTo();
         SYNCSTT_vidOS1();
         SYNCSTT_vidOS2();
         SYNCSTT_vidEveProd();
         SYNCSTT_vidDiagResult();
      }
      if (  (Sync_bCalcOk == 0)
         && (bLocalCtrl_bAcv_EngMes != 0))
      {
         if (u16LocalExt_nEng <= 600)
         {
            SYNCSTT_vidEngStopPosnAfter();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkOff_SyncSTT                                      */
/* !Description :  Evènement correspondant à la détection de l'arrêt moteur   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidEngStopPosn();                                */
/*  extf argret void SYNCSTT_vidCkOff();                                      */
/*  extf argret void SYNCSTT_vidEveProd();                                    */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkOff_SyncSTT                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkOff_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;


   VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         SYNCSTT_vidEngStopPosn();
         SYNCSTT_vidCkOff();
         SYNCSTT_vidEveProd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkOn_SyncSTT                                       */
/* !Description :  Evènement correspondant à la détection de la rotation du   */
/*                 moteur                                                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCSTT_vidCkOn();                                       */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkOn_SyncSTT                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkOn_SyncSTT(void)
{
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      SYNCSTT_vidCkOn();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOf_SyncSTT                                     */
/* !Description :  Evènement synchronisation perdue                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidCkOff();                                      */
/*  input boolean Sync_bEngPosOk;                                             */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOf_SyncSTT                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOf_SyncSTT(void)
{
   boolean bLocalSync_bEngPosOk;


   VEMS_vidGET(Sync_bEngPosOk, bLocalSync_bEngPosOk);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if(bLocalSync_bEngPosOk == 0)
      {
         SYNCSTT_vidCkOff();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkTo_SyncSTT                                       */
/* !Description :  Evènement dent vilebrequin activé si le régime est         */
/*                 inférieur à un seuil                                       */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidReadToothInfo();                              */
/*  extf argret void SYNCSTT_vidTeethCnt();                                   */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkTo_SyncSTT                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkTo_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;


   VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         SYNCSTT_vidReadToothInfo();
         SYNCSTT_vidTeethCnt();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveExCamEdge_SyncSTT                                  */
/* !Description :  Evènement détection d'un front arbre à cames échappement   */
/*                 pour la fonction  Synchro                                  */
/* !Number      :  SCH.6                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidctEdgeCmExStrt();                             */
/*  extf argret void SYNCSTT_vidctEdgeCmExRstrt();                            */
/*  extf argret void SYNCSTT_vidOS2();                                        */
/*  extf argret void SYNCSTT_vidEveProd();                                    */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveExCamEdge_SyncSTT                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveExCamEdge_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;
   boolean  bLocalSync_bEngSyncAccu;
   uint8    u8LocalCoSync_stSigCm2Sync;


   VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
   VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
      /* bloc F14_ctEdgeCmExStrt & F18_ctEdgeCmExRstrt*/
         if (  (bLocalSync_bEngSyncAccu == 0)
            && (u8LocalCoSync_stSigCm2Sync == 2))
         {
            SYNCSTT_vidctEdgeCmExStrt();
            SYNCSTT_vidctEdgeCmExRstrt();
         }
         SYNCSTT_vidOS2();
         SYNCSTT_vidEveProd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveInCamEdge_SyncSTT                                  */
/* !Description :  Evènement détection d'un front arbre à cames admission pour*/
/*                 la fonction  Synchro                                       */
/* !Number      :  SCH.7                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidctEdgeCmInStrt();                             */
/*  extf argret void SYNCSTT_vidctEdgeCmInRstrt();                            */
/*  extf argret void SYNCSTT_vidOS1();                                        */
/*  extf argret void SYNCSTT_vidEveProd();                                    */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveInCamEdge_SyncSTT                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveInCamEdge_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;
   boolean  bLocalSync_bEngSyncAccu;
   uint8    u8LocalCoSync_stSigCm2Sync;


   VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
   VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         /* bloc F13_ctEdgeCmInStrt & F17_ctEdgeCmInRstrt*/
         if (  (bLocalSync_bEngSyncAccu == 0)
            && (u8LocalCoSync_stSigCm2Sync == 1))
         {
            SYNCSTT_vidctEdgeCmInStrt();
            SYNCSTT_vidctEdgeCmInRstrt();
         }
         SYNCSTT_vidOS1();
         SYNCSTT_vidEveProd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_SyncSTT                                        */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.8                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCSTT_vidInit();                                       */
/*  extf argret void SYNCSTT_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_SyncSTT                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_SyncSTT(void)
{
   SYNCSTT_vidInit();
   SYNCSTT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_SyncSTT                                        */
/* !Description :  Interruption PMH                                           */
/* !Number      :  SCH.9                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidTDCCnt();                                     */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_SyncSTT                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_SyncSTT(void)
{
   boolean  bLocalSync_bEngSyncAccu;


   VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalSync_bEngSyncAccu != 0)
      {
         SYNCSTT_vidTDCCnt();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlMid_SyncSTT                                        */
/* !Description :  Moniteur moyen de la fonction Sync                         */
/* !Number      :  SCH.10                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidSync_SdlMid_SyncSTT();                        */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlMid_SyncSTT                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlMid_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;


   VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         SYNCSTT_vidSync_SdlMid_SyncSTT();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkLTo1_SyncSTT                                     */
/* !Description :  Evènement indiquant la première détection de la singularité*/
/*                 vilebrequin                                                */
/* !Number      :  SCH.11                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidOS1();                                        */
/*  extf argret void SYNCSTT_vidOS2();                                        */
/*  extf argret void SYNCSTT_vidEveProd();                                    */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkLTo1_SyncSTT                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkLTo1_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;


   if (SYNCSTT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         SYNCSTT_vidOS1();
         SYNCSTT_vidOS2();
         SYNCSTT_vidEveProd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveNInvOff_SyncSTT                                    */
/* !Description :  Evénement indiquant le retour à une rotation en sens avant */
/*                 du moteur                                                  */
/* !Number      :  SCH.12                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidChangeOfMind();                               */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveNInvOff_SyncSTT                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveNInvOff_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;


   VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         SYNCSTT_vidChangeOfMind();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlFast_SyncSTT                                       */
/* !Description :  Moniteur rapide de la fonction Sync                        */
/* !Number      :  SCH.13                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_014.01                                     */
/*                 VEMS_E_10_06977_015.01                                     */
/*                 VEMS_E_10_06977_016.01                                     */
/*                 VEMS_E_10_06977_017.01                                     */
/*                 VEMS_E_10_06977_018.01                                     */
/*                 VEMS_E_10_06977_019.01                                     */
/*                 VEMS_E_10_06977_040.01                                     */
/*                 VEMS_E_10_06977_041.01                                     */
/*                 VEMS_E_10_06977_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidDiagAuth();                                   */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SYNCSTT_vidBackUpAcv();                                  */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input uint8 SYNCSTT_u8Inhib;                                              */
/*  input boolean Sync_bDgoDistSig;                                           */
/*  input boolean Sync_bMonRunDistSig;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlFast_SyncSTT                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlFast_SyncSTT(void)
{
   boolean  bLocalCtrl_bAcv_EngMes;


   VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
   if (SYNCSTT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         SYNCSTT_vidDiagAuth();
         GDGAR_vidGdu(GD_DFT_DISTSIG,
                      Sync_bDgoDistSig,
                      Sync_bMonRunDistSig,
                      DIAG_DISPO);
         SYNCSTT_vidBackUpAcv();
      }
   }
}
/*------------------------------ End of file ---------------------------------*/