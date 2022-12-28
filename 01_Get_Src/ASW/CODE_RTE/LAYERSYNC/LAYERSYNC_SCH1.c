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
/* !File            : LAYERSYNC_SCH1.c                                        */
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
/*   1 / Sync_EveCkSnOn_AcqCkMngIf                                            */
/*   2 / Sync_EveTDC_AcqCkMngIf                                               */
/*   3 / Sync_EveTestEnd_AcqCkMngIf                                           */
/*   4 / Sync_EveKOn_AcqCkMngIf                                               */
/*   5 / Sync_EveStTR_AcqCkMngIf                                              */
/*   6 / Sync_EveBDC_AcqCkMngIf                                               */
/*   7 / Sync_SdlFast_AcqCkMngIf                                              */
/*   8 / Sync_EveExCmToo_AcqExCmSts                                           */
/*   9 / Sync_EveRst_ExCmStsIf                                                */
/*   10 / Sync_SdlSlow_AcqExCmSts                                             */
/*   11 / Sync_EveInCmToo_AcqInCmSts                                          */
/*   12 / Sync_EveRst_InCmStsIf                                               */
/*   13 / Sync_SdlSlow_AcqInCmSts                                             */
/*   14 / Sync_EveInCamEdge_AcqSyncSTT                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6944973 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/LAYERSYNC/LAYERSYNC_SCH1.c_v      $*/
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
/* !Function    :  Sync_EveCkSnOn_AcqCkMngIf                                  */
/* !Description :  Evènement Synchro trouvée                                  */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidAcquiDureeDent();                           */
/*  extf argret void LAYERSYNC_vidAcquiPeriodeMoteur();                       */
/*  extf argret void LAYERSYNC_vidTrouverPhaseMoteur();                       */
/*  extf argret void LAYERSYNC_vidPhaseCylEch();                              */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOn_AcqCkMngIf                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOn_AcqCkMngIf(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         LAYERSYNC_vidAcquiDureeDent();
         LAYERSYNC_vidAcquiPeriodeMoteur();
         LAYERSYNC_vidTrouverPhaseMoteur();
         LAYERSYNC_vidPhaseCylEch();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_AcqCkMngIf                                     */
/* !Description :  Interruption PMH                                           */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidAcquiPeriodeMoteur();                       */
/*  extf argret void LAYERSYNC_vidTrouverPhaseMoteur();                       */
/*  extf argret void LAYERSYNC_vidAcquiDureeDent();                           */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Sync_bAcvBDCEngSpdClcn_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_AcqCkMngIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_AcqCkMngIf(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         if (Sync_bAcvBDCEngSpdClcn_C != 0)
         {
            LAYERSYNC_vidAcquiPeriodeMoteur();
         }
         LAYERSYNC_vidTrouverPhaseMoteur();
         LAYERSYNC_vidAcquiDureeDent();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTestEnd_AcqCkMngIf                                 */
/* !Description :  Evènement indiquant la fin des tests fonctionnels          */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidInitAPI();                                  */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTestEnd_AcqCkMngIf                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTestEnd_AcqCkMngIf(void)
{
   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      LAYERSYNC_vidInitAPI();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveKOn_AcqCkMngIf                                     */
/* !Description :  Evènement clé Off -> On                                    */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidInitAPI();                                  */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Thr_bEndTestInh_CpuSfty;                                    */
/*  input boolean Sync_bAcvTest_CpuSfty_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveKOn_AcqCkMngIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveKOn_AcqCkMngIf(void)
{
   boolean bLocalThr_bEndTestInhCpuSfty;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Thr_bEndTestInh_CpuSfty, bLocalThr_bEndTestInhCpuSfty);
      if (  (Sync_bAcvTest_CpuSfty_C == 0)
         || (bLocalThr_bEndTestInhCpuSfty != 0))
      {
         LAYERSYNC_vidInitAPI();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveStTR_AcqCkMngIf                                    */
/* !Description :  Evènement Stall To Rot                                     */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidAcquiDureeDent();                           */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveStTR_AcqCkMngIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveStTR_AcqCkMngIf(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         LAYERSYNC_vidAcquiDureeDent();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveBDC_AcqCkMngIf                                     */
/* !Description :  Evénement Point Mort Bas (PMB / BDC)                       */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidAcquiPeriodeMoteur();                       */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveBDC_AcqCkMngIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveBDC_AcqCkMngIf(void)
{
   boolean bLocalCtrl_bAcvEngMes;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      if (bLocalCtrl_bAcvEngMes != 0)
      {
         LAYERSYNC_vidAcquiPeriodeMoteur();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlFast_AcqCkMngIf                                    */
/* !Description :  Moniteur rapide de la fonction Sync                        */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidPhaseCylEch();                              */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Moteur_synchronise;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlFast_AcqCkMngIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlFast_AcqCkMngIf(void)
{
   boolean bLocalCtrl_bAcvEngMes;
   boolean bLocalMoteurSynchronise;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcvEngMes);
      VEMS_vidGET(Moteur_synchronise, bLocalMoteurSynchronise);

      if (  (bLocalCtrl_bAcvEngMes != 0)
         && (bLocalMoteurSynchronise != 0))
      {
         LAYERSYNC_vidPhaseCylEch();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveExCmToo_AcqExCmSts                                 */
/* !Description :  Evènement Dent AAC                                         */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidExAcq();                                    */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidDiagExCm();                                 */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ext_bPresExCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveExCmToo_AcqExCmSts                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveExCmToo_AcqExCmSts(void)
{
   boolean bLocalExt_bPresExCmSen;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      LAYERSYNC_vidExAcq();
      VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);
      if (bLocalExt_bPresExCmSen != 0)
      {
         LAYERSYNC_vidDiagExCm();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_ExCmStsIf                                      */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidInitOutput();                               */
/*  extf argret void LAYERSYNC_vidIniExAcq();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_ExCmStsIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_ExCmStsIf(void)
{
   LAYERSYNC_vidInitOutput();
   LAYERSYNC_vidIniExAcq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlSlow_AcqExCmSts                                    */
/* !Description :  Moniteur lent de la fonction Sync                          */
/* !Number      :  SCH1.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidExAcq();                                    */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlSlow_AcqExCmSts                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlSlow_AcqExCmSts(void)
{
   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      LAYERSYNC_vidExAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveInCmToo_AcqInCmSts                                 */
/* !Description :  Evènement arbre à cames admission                          */
/* !Number      :  SCH1.11                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidAcq();                                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidDiagInCm();                                 */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ext_bPresInCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveInCmToo_AcqInCmSts                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveInCmToo_AcqInCmSts(void)
{
   boolean bLocalExt_bPresInCmSen;


   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      LAYERSYNC_vidAcq();
      VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
      if (bLocalExt_bPresInCmSen != 0)
      {
         LAYERSYNC_vidDiagInCm();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_InCmStsIf                                      */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH1.12                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidIniAcq();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_InCmStsIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_InCmStsIf(void)
{
   LAYERSYNC_vidIniAcq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlSlow_AcqInCmSts                                    */
/* !Description :  Moniteur lent de la fonction Sync                          */
/* !Number      :  SCH1.13                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAYERSYNC_vidAcq();                                      */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlSlow_AcqInCmSts                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlSlow_AcqInCmSts(void)
{
   if (LAYERSYNC_u8Inhib != 0x5A)
   {
      LAYERSYNC_vidAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveInCamEdge_AcqSyncSTT                               */
/* !Description :  Evènement détection d'un front arbre à cames admission pour*/
/*                 la fonction Synchro                                        */
/* !Number      :  SCH1.14                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidCtEdgeCmInStrt();                           */
/*  extf argret void LAYERSYNC_vidCtEdgeCmInRstrt();                          */
/*  input uint8 LAYERSYNC_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveInCamEdge_AcqSyncSTT                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveInCamEdge_AcqSyncSTT(void)
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
            && (u8LocalCoSyncStSigCm2Sync == 1))
         {
            LAYERSYNC_vidCtEdgeCmInStrt();
            LAYERSYNC_vidCtEdgeCmInRstrt();
         }
      }
   }
}
/*------------------------------- end of file --------------------------------*/