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
/* !File            : LAYERSYNC_FCT2.C                                        */
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
/*   1 / LAYERSYNC_vidDiagInCm                                                */
/*   2 / LAYERSYNC_vidIniAcq                                                  */
/*   3 / LAYERSYNC_vidIniInCmAcq                                              */
/*   4 / LAYERSYNC_vidAcq                                                     */
/*   5 / LAYERSYNC_vidInCmSt                                                  */
/*   6 / LAYERSYNC_vidCallAPI                                                 */
/*   7 / LAYERSYNC_vidEnaQuickSync                                            */
/*   8 / LAYERSYNC_vidDisQuickSync                                            */
/*   9 / LAYERSYNC_vidBwdRotMng                                               */
/*   10 / LAYERSYNC_vidDisBwdRot                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6944973 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/LAYERSYNC/LAYERSYNC_FCT2.c_v      $*/
/* $Revision::   1.1      $$Author::   achebino       $$Date::   21 Aug 2014 $*/
/* $Author::   achebino                               $$Date::   21 Aug 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "LAYERSYNC.h"
#include "LAYERSYNC_L.h"
#include "LAYERSYNC_IM.h"
#include "CRKHAL.h"
#include "DGOHAL.h"
#include "CAMHAL.h"
#include "LAYERSYNC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidDiagInCm                                      */
/* !Description :  Fonction responsable du diagnostic.                        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_chr_incamdiag;                                        */
/*  output boolean Dft_chr_incamdiag;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidDiagInCm(void)
{
   DGOHAL_tbfStatus u32LocalFault;


   u32LocalFault = DGOHAL_bfRead(DGOHAL_udtCAMSHAFT);

   if ( (u32LocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_CAM_PATTERN)) != 0)
   {
      VEMS_vidSET(Dena_chr_incamdiag, 1);
      if ((u32LocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_CAM_PATTERN)) != 0)
      {
         VEMS_vidSET(Dft_chr_incamdiag, 1);
      }
      else
      {
         VEMS_vidSET(Dft_chr_incamdiag, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_chr_incamdiag, 0);
      VEMS_vidSET(Dft_chr_incamdiag, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidIniAcq                                        */
/* !Description :  Au réveil du calculateur, les booléens d’états et leur     */
/*                 indicateur de validité sont forcés à 0                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidIniInCmAcq();                               */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  output boolean Acq_incam_sync_upvb0;                                      */
/*  output boolean Acq_incam_sync_status_upvb0;                               */
/*  output boolean Acq_incam_tooth_det_upvb0;                                 */
/*  output boolean Acq_incam_tooth_det_vld_upvb0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidIniAcq(void)
{
   boolean bLocalExt_bPresInCmSen;


   VEMS_vidSET(Acq_incam_sync_upvb0, 0);
   VEMS_vidSET(Acq_incam_sync_status_upvb0, 0);
   VEMS_vidSET(Acq_incam_tooth_det_upvb0, 0);
   VEMS_vidSET(Acq_incam_tooth_det_vld_upvb0, 0);

   VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
   if (bLocalExt_bPresInCmSen != 0)
   {
      LAYERSYNC_vidIniInCmAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidIniInCmAcq                                    */
/* !Description :  Fonction d'initialisation de L'API CAMHAL                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CAMHAL_vidSetMode(argin CAMHAL_tudtChannel               */
/*  udtChannelName, argin CAMHAL_tenuMode enuMode);                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidIniInCmAcq(void)
{
   CAMHAL_vidSetMode(CAMHAL_udtCH_INTAKE_CAMSHAFT, CAMHAL_udtNORMAL_MODE);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidAcq                                           */
/* !Description :  Afin de délivrer des informations pertinentes et           */
/*                 d’économiser de la charge CPU, les booléens d’états et leur*/
/*                 flag de validité ne sont acquis que si le capteur arbre à  */
/*                 cames admission est présent sur le moteur.                 */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidInCmSt();                                   */
/*  input boolean Ext_bPresInCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidAcq(void)
 {
   boolean bLocalExt_bPresInCmSen;


   VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
   if (bLocalExt_bPresInCmSen != 0)
   {
      LAYERSYNC_vidInCmSt();
   }
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidInCmSt                                        */
/* !Description :  Ce bloc permet le diagnostic du signal arbre à cames       */
/*                 admission                                                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  CAMHAL_udtReadStatus(argin CAMHAL_tudtChannel        */
/*  udtChannel, argin uint8 u8Channel, argout boolean *pbStatus);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acq_incam_sync_upvb0;                                      */
/*  output boolean Acq_incam_sync_status_upvb0;                               */
/*  output boolean Acq_incam_tooth_det_upvb0;                                 */
/*  output boolean Acq_incam_tooth_det_vld_upvb0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidInCmSt(void)
 {
   boolean bLocalCAMHALReadStatus;
   boolean bLocalAcqIncamSyncUpvb0;
   boolean bLocalAcqIncamSyncStatuUpvb0;
   boolean bLocalAcqIncamToothDetUpvb0;
   boolean bLocalAcqIncamToothDetVldUpvb0;


   bLocalCAMHALReadStatus = CAMHAL_udtReadStatus(CAMHAL_udtCH_INTAKE_CAMSHAFT,
                                                 CAMHAL_u8SYNCHRONISED,
                                                 &bLocalAcqIncamSyncUpvb0);
   if (bLocalCAMHALReadStatus == E_OK)
   {
      bLocalAcqIncamSyncStatuUpvb0 = 1;
   }
   else
   {
      bLocalAcqIncamSyncStatuUpvb0 = 0;
   }

   bLocalCAMHALReadStatus = CAMHAL_udtReadStatus(CAMHAL_udtCH_INTAKE_CAMSHAFT,
                                                 CAMHAL_u8DETECTED,
                                                 &bLocalAcqIncamToothDetUpvb0);
   if (bLocalCAMHALReadStatus == E_OK)
   {
      bLocalAcqIncamToothDetVldUpvb0 = 1;
   }
   else
   {
      bLocalAcqIncamToothDetVldUpvb0 = 0;
   }

   VEMS_vidSET(Acq_incam_sync_upvb0, bLocalAcqIncamSyncUpvb0);
   VEMS_vidSET(Acq_incam_sync_status_upvb0, bLocalAcqIncamSyncStatuUpvb0);
   VEMS_vidSET(Acq_incam_tooth_det_upvb0, bLocalAcqIncamToothDetUpvb0);
   VEMS_vidSET(Acq_incam_tooth_det_vld_upvb0, bLocalAcqIncamToothDetVldUpvb0);
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidCallAPI                                       */
/* !Description :  Au reset du calculateur on  fournit  la valeur de régime   */
/*                 (Sync_AcvAgEng_C) en dessous duquel la tache               */
/*                 CRKHAL_TOOTH_EVENT sera produite.                          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtWriteEnaToothTskRpmThd(argin uint16            */
/*  u16EngineSpeedThd)Std_ReturnType;                                         */
/*  extf argret void LAYERSYNC_vidEnaQuickSync();                             */
/*  extf argret void LAYERSYNC_vidDisQuickSync();                             */
/*  input uint8 Sync_nAcvAgEng_C;                                             */
/*  input boolean Sync_bEnaFastSync_C;                                        */
/*  output boolean SyncAcq_bCalcOk;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidCallAPI(void)
 {
   Std_ReturnType  udtLocalStatus;
   /*QAC Warning(3:3203): CRKHAL_udtWriteEnaToothTskRpmThd returns Std value*/
   uint16          u16LocalEngineSpeedThd;


   u16LocalEngineSpeedThd = (uint16)(Sync_nAcvAgEng_C * 10);
   udtLocalStatus = CRKHAL_udtWriteEnaToothTskRpmThd(u16LocalEngineSpeedThd);
   /*QAC Warning(3:3199): CRKHAL_udtWriteEnaToothTskRpmThd returns Std value*/

   if (Sync_bEnaFastSync_C != 0)
   {
      LAYERSYNC_vidEnaQuickSync();
   }
   else
   {
      LAYERSYNC_vidDisQuickSync();
   }

   SyncAcq_bCalcOk = 0;
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidEnaQuickSync                                  */
/* !Description :  API d’autorisation de synchronisation rapide               */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtEnableQuickSynchro()Std_ReturnType;            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidEnaQuickSync(void)
 {
   Std_ReturnType udtLocalStatus;
   /*QAC Warning(3:3203): CRKHAL_udtEnableQuickSynchro returns Std value*/


   udtLocalStatus = CRKHAL_udtEnableQuickSynchro();
   /*QAC Warning(3:3199): CRKHAL_udtEnableQuickSynchro returns Std value*/
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidDisQuickSync                                  */
/* !Description :  API d’interdiction de synchronisation rapide               */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtDisableQuickSynchro()Std_ReturnType;           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidDisQuickSync(void)
 {
   Std_ReturnType udtLocalStatus;
   /*QAC Warning(3:3203): CRKHAL_udtDisableQuickSynchro returns Std value*/


   udtLocalStatus = CRKHAL_udtDisableQuickSynchro();
   /*QAC Warning(3:3199): CRKHAL_udtDisableQuickSynchro returns Std value*/
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidBwdRotMng                                     */
/* !Description :  On autorise la rotation du moteur en sens inverse jusqu’à  */
/*                 un seuil de régime défini par Sync_nEngEnaBwdRotThd_C. Si  */
/*                 le régime dépasse ce seuil on appelle alors l’API qui      */
/*                 permet de désactiver la rotation en sens inverse.          */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidDisBwdRot();                                */
/*  extf argret void LAYERSYNC_vidEnaBwdRot();                                */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 Sync_nEngThdDiBwdRot_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidBwdRotMng(void)
 {
   uint16 u16LocalExt_nEng;
   uint16 u16LocalSyncNEngThdDiBwdRot;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalSyncNEngThdDiBwdRot = (uint16)(Sync_nEngThdDiBwdRot_C * 10);
   if (u16LocalExt_nEng > u16LocalSyncNEngThdDiBwdRot)
   {
      LAYERSYNC_vidDisBwdRot();
   }
   else
   {
      LAYERSYNC_vidEnaBwdRot();
   }
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidDisBwdRot                                     */
/* !Description :  API qui permet de désactiver la rotation en sens inverse.  */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtDisableBwdRotation()Std_ReturnType;            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidDisBwdRot(void)
 {
   Std_ReturnType udtLocalStatus;
   /*QAC Warning(3:3203): CRKHAL_udtDisableBwdRotation returns Std value*/


   udtLocalStatus = CRKHAL_udtDisableBwdRotation();
   /*QAC Warning(3:3199): CRKHAL_udtDisableBwdRotation returns Std value*/
 }
/*------------------------------- end of file --------------------------------*/