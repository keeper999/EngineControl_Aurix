/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : LAYERSYNC                                               */
/* !Description     : LAYERSYNC component.                                    */
/*                                                                            */
/* !Module          : LAYERSYNC                                               */
/* !Description     : LAYER DE LA FONCTION SYNCHRO                            */
/*                                                                            */
/* !File            : LAYERSYNC_SCH2.c                                        */
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
/*   1 / Sync_EveExCamEdge_AcqSyncSTT                                         */
/*   2 / Sync_EveCkTo_AcqSyncSTT                                              */
/*   3 / Sync_EveCkOff_AcqSyncSTT                                             */
/*   4 / Sync_EveCkSnOf_AcqSyncSTT                                            */
/*   5 / Sync_EveRst_AcqSyncSTT                                               */
/*   6 / Sync_SdlMid_AcqSyncSTT                                               */
/*   7 / Sync_EveCkLTo_AcqSyncSTT                                             */
/*   8 / Sync_EveNInvOff_AcqSyncSTT                                           */
/*   9 / Sync_EveSyncAccu_AcqSyncSTT                                          */
/*   10 / VlvAct_EveRst_AcqVlVActPos                                          */
/*   11 / VlVAct_EveExCmToo_AcqVlVActPos                                      */
/*   12 / VlVAct_EveInCmToo_AcqVlVActPos                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6944973 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/LAYERSYNC/LAYERSYNC_SCH2.c_v      $*/
/* $Revision::   1.1      $$Author::   achebino       $$Date::   21 Aug 2014 $*/
/* $Author::   achebino                               $$Date::   21 Aug 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "LAYERSYNC.h"
#include "LAYERSYNC_L.h"
#include "LAYERSYNC_IM.h"
#include "LAYERSYNC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveExCamEdge_AcqSyncSTT                               */
/* !Description :  Evènement détection d'un front arbre à cames échappement   */
/*                 pour la fonction Synchro                                   */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidCtEdgeCmExStrt();                           */
/*  extf argret void LAYERSYNC_vidCtEdgeCmExRstrt();                          */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveExCamEdge_AcqSyncSTT                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveExCamEdge_AcqSyncSTT(void)
{
   boolean bLocalCtrl_bAcvEngMes;
   boolean bLocalSync_bEngSyncAccu;
   uint8   u8LocalCoSyncStSigCm2Sync;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
         VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSyncStSigCm2Sync);
         if (  (bLocalSync_bEngSyncAccu == 0)
            && (u8LocalCoSyncStSigCm2Sync == 2))
         {
            LAYERSYNC_vidCtEdgeCmExStrt();
            LAYERSYNC_vidCtEdgeCmExRstrt();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkTo_AcqSyncSTT                                    */
/* !Description :  Evènement dent vilebrequin activé si le régime est         */
/*                 inférieur à un seuil                                       */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidBwdRotMng();                                */
/*  extf argret void LAYERSYNC_vidReadToothInfo();                            */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkTo_AcqSyncSTT                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkTo_AcqSyncSTT(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         LAYERSYNC_vidBwdRotMng();
         LAYERSYNC_vidReadToothInfo();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkOff_AcqSyncSTT                                   */
/* !Description :  Evènement  Crk off                                         */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidEngStopPosn();                              */
/*  extf argret void LAYERSYNC_vidCkOff();                                    */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkOff_AcqSyncSTT                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkOff_AcqSyncSTT(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         LAYERSYNC_vidEngStopPosn();
         LAYERSYNC_vidCkOff();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOf_AcqSyncSTT                                  */
/* !Description :  Evènement synchronisation perdue                           */
/* !Number      :  SCH2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidCkOff();                                    */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Acq_position_anglaire_moteur;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOf_AcqSyncSTT                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOf_AcqSyncSTT(void)
{
   boolean bLocalAcqPositionAnglaireMoteur;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Acq_position_anglaire_moteur,
                  bLocalAcqPositionAnglaireMoteur);
      if (bLocalAcqPositionAnglaireMoteur == 0)
      {
         LAYERSYNC_vidCkOff();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_AcqSyncSTT                                     */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH2.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidCallAPI();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_AcqSyncSTT                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_AcqSyncSTT(void)
{
   LAYERSYNC_vidCallAPI();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlMid_AcqSyncSTT                                     */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH2.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidReadToothInfo();                            */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlMid_AcqSyncSTT                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlMid_AcqSyncSTT(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         LAYERSYNC_vidReadToothInfo();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkLTo_AcqSyncSTT                                   */
/* !Description :  Evènement dent longue                                      */
/* !Number      :  SCH2.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidEngStopPosnAfter();                         */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean SyncAcq_bCalcOk;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkLTo_AcqSyncSTT                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkLTo_AcqSyncSTT(void)
{
   boolean bLocalCtrl_bAcvEngMes;
   uint16  u16LocalExt_nEng;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

      if (  (bLocalCtrl_bAcvEngMes != 0)
         && (SyncAcq_bCalcOk == 0)
         && (u16LocalExt_nEng <= 600))
      {
         LAYERSYNC_vidEngStopPosnAfter();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveNInvOff_AcqSyncSTT                                 */
/* !Description :  Evénement indiquant le retour à une rotation en sens avant */
/*                 du moteur                                                  */
/* !Number      :  SCH2.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidChangeOfMind();                             */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveNInvOff_AcqSyncSTT                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveNInvOff_AcqSyncSTT(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         LAYERSYNC_vidChangeOfMind();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveSyncAccu_AcqSyncSTT                                */
/* !Description :  Evénement indiquant le passage en synchronisation précise  */
/*                 du moteur                                                  */
/* !Number      :  SCH2.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidIniTDCCnt();                                */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveSyncAccu_AcqSyncSTT                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveSyncAccu_AcqSyncSTT(void)
{
   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      LAYERSYNC_vidIniTDCCnt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_AcqVlVActPos                                 */
/* !Description :  Evènement Reset                                            */
/* !Number      :  SCH2.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidInit();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_AcqVlVActPos                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_AcqVlVActPos(void)
{
   LAYERSYNC_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlVAct_EveExCmToo_AcqVlVActPos                             */
/* !Description :  Evènement dent AAC échappemen                              */
/* !Number      :  SCH2.11                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidAcqExPos();                                 */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ext_bPresExCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlVAct_EveExCmToo_AcqVlVActPos                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlVAct_EveExCmToo_AcqVlVActPos(void)
{
   boolean bLocalExt_bPresExCmSen;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);
      if (bLocalExt_bPresExCmSen != 0)
      {
         LAYERSYNC_vidAcqExPos();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlVAct_EveInCmToo_AcqVlVActPos                             */
/* !Description :  Evènement dent AAC admission                               */
/* !Number      :  SCH2.12                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidAcqInPos();                                 */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ext_bPresInCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlVAct_EveInCmToo_AcqVlVActPos                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlVAct_EveInCmToo_AcqVlVActPos(void)
{
   boolean bLocalExt_bPresInCmSen;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
      if (bLocalExt_bPresInCmSen != 0)
      {
         LAYERSYNC_vidAcqInPos();
      }
   }
}
/*------------------------------- end of file --------------------------------*/