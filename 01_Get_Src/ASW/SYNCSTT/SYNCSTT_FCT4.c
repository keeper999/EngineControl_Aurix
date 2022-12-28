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
/* !File            : SYNCSTT_FCT4.C                                          */
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
/*   1 / SYNCSTT_vidctEdgeCmInRstrt                                           */
/*   2 / SYNCSTT_vidctEdgeCmExRstrt                                           */
/*   3 / SYNCSTT_vidSyncCalcRstrt                                             */
/*   4 / SYNCSTT_vidEngStopPosn                                               */
/*   5 / SYNCSTT_vidForcSyncOff                                               */
/*   6 / SYNCSTT_vidCkOff                                                     */
/*   7 / SYNCSTT_vidEveProd                                                   */
/*   8 / SYNCSTT_vidSync_SdlMid_SyncSTT                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6912870 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNCSTT/SYNCSTT_FCT4.c_v          $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   25 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   25 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCSTT.h"
#include "SYNCSTT_L.h"
#include "SYNCSTT_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidctEdgeCmInRstrt                                 */
/* !Description :  A chaque détection de front AAC admission, la fonction     */
/*                 vérifie que la position de ce front est située à moins de  */
/*                 Sync_agWinAgCmThLrn_C de sa position apprise.  Si c’est le */
/*                 cas on incrémente le compteur de fronts AAC correspondant à*/
/*                 ce critère.                                                */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acq_pos_ang_red_mot_frt_aac_adm;                             */
/*  input uint8 Sync_agEngRstrtInCmEdge;                                      */
/*  input uint16 Sync_prm_agRefInCmEdge_C[6];                                 */
/*  input uint8 Sync_agWinAgCmThLrn_C;                                        */
/*  input uint8 Sync_ctCmInEdgeRstrtOk;                                       */
/*  output uint8 Sync_agEngRstrtInCmEdge;                                     */
/*  output uint8 Sync_ctCmInEdgeRstrtOk;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidctEdgeCmInRstrt(void)
{
   boolean bLocalResult;
   uint16  u16LocalSync_ctCmInEdgeRstrtOk;
   uint16  u16LocalSync_prm_agDiffABS;
   uint16  u16LocalSync_agEngRstrtInCmEdge;
   uint16  u16LocalAcqPosAngRedMotFrtAacAdm;
   uint32  u32LocalIndex;
   sint32  s32LocalSync_prm_agDiff;


   VEMS_vidGET(Acq_pos_ang_red_mot_frt_aac_adm,
               u16LocalAcqPosAngRedMotFrtAacAdm);
   u16LocalSync_agEngRstrtInCmEdge =
      (uint16)((u16LocalAcqPosAngRedMotFrtAacAdm + 192) / 384);
   Sync_agEngRstrtInCmEdge =
      (uint8)MATHSRV_udtMIN(u16LocalSync_agEngRstrtInCmEdge, 120);

   bLocalResult = 0;
   for ( (u32LocalIndex = 0);
       (  (u32LocalIndex < 6)
       && (bLocalResult == 0));
       u32LocalIndex++)
   {
      s32LocalSync_prm_agDiff = (sint32)( (6 * Sync_agEngRstrtInCmEdge)
                             - Sync_prm_agRefInCmEdge_C[u32LocalIndex]);
      u16LocalSync_prm_agDiffABS =
         (uint16)MATHSRV_udtABS(s32LocalSync_prm_agDiff);
      if (u16LocalSync_prm_agDiffABS < Sync_agWinAgCmThLrn_C)
      {
         bLocalResult = 1;
      }
   }

   if (bLocalResult != 0)
   {
      u16LocalSync_ctCmInEdgeRstrtOk = (uint16)(Sync_ctCmInEdgeRstrtOk + 1);
   }
   else
   {
      u16LocalSync_ctCmInEdgeRstrtOk = (uint16)(Sync_ctCmInEdgeRstrtOk);
   }
   Sync_ctCmInEdgeRstrtOk = (uint8)(u16LocalSync_ctCmInEdgeRstrtOk % 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidctEdgeCmExRstrt                                 */
/* !Description :  A chaque détection de front AAC échappement, la fonction   */
/*                 vérifie que la position de ce front est située à moins de  */
/*                 Sync_agWinAgCmThLrn_C de sa position apprise.  Si c’est le */
/*                 cas on incrémente le compteur de fronts AAC correspondant à*/
/*                 ce critère.                                                */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acq_pos_ang_red_mot_frnt_aac_ech;                            */
/*  input uint8 Sync_agEngRstrtExCmEdge;                                      */
/*  input uint16 Sync_prm_agRefExCmEdge_C[6];                                 */
/*  input uint8 Sync_agWinAgCmThLrn_C;                                        */
/*  input uint8 Sync_ctCmExEdgeRstrtOk;                                       */
/*  output uint8 Sync_agEngRstrtExCmEdge;                                     */
/*  output uint8 Sync_ctCmExEdgeRstrtOk;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidctEdgeCmExRstrt(void)
{
   boolean bLocalResult;
   uint16  u16LocalSync_ctCmExEdgeRstrtOk;
   uint16  u16LocalSync_prm_agDiffABS;
   uint16  u16LocalSync_agEngRstrtExCmEdge;
   uint16  u16LocalAcqPosAngRedMoFrntAacEch;
   uint32  u32LocalIndex;
   sint32  s32LocalSync_prm_agDiff;


   VEMS_vidGET(Acq_pos_ang_red_mot_frnt_aac_ech,
               u16LocalAcqPosAngRedMoFrntAacEch);
   u16LocalSync_agEngRstrtExCmEdge =
      (uint16)((u16LocalAcqPosAngRedMoFrntAacEch + 192) / 384);
   Sync_agEngRstrtExCmEdge =
      (uint8)MATHSRV_udtMIN(u16LocalSync_agEngRstrtExCmEdge, 120);

   bLocalResult = 0;
   for ( (u32LocalIndex = 0);
       (  (u32LocalIndex < 6)
       && (bLocalResult == 0));
       u32LocalIndex++)
   {
      s32LocalSync_prm_agDiff = (sint32)( (6 * Sync_agEngRstrtExCmEdge)
                             - Sync_prm_agRefExCmEdge_C[u32LocalIndex]);
      u16LocalSync_prm_agDiffABS =
         (uint16)MATHSRV_udtABS(s32LocalSync_prm_agDiff);
      if (u16LocalSync_prm_agDiffABS < Sync_agWinAgCmThLrn_C)
      {
         bLocalResult = 1;
      }
   }

   if (bLocalResult != 0)
   {
      u16LocalSync_ctCmExEdgeRstrtOk = (uint16)(Sync_ctCmExEdgeRstrtOk + 1);
   }
   else
   {
      u16LocalSync_ctCmExEdgeRstrtOk = (uint16)(Sync_ctCmExEdgeRstrtOk);
   }
   Sync_ctCmExEdgeRstrtOk = (uint8)(u16LocalSync_ctCmExEdgeRstrtOk % 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidSyncCalcRstrt                                   */
/* !Description :  Après un redémarrage, la variable Sync_bEngSyncAccu prend  */
/*                 la valeur 1 dans le cas ou on a détecté la  singularité    */
/*                 vilebrequin ou si on a comptabilisé au moins               */
/*                 Sync_noEdgeCmAccuRstrt_C fronts AAC à une  position proche */
/*                 de leur valeur théorique.                                  */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_10_06977_009.01                                     */
/*                 VEMS_R_10_06977_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sync_bVldAgEs;                                              */
/*  input boolean Sync_bDetLTo;                                               */
/*  input uint8 Sync_ctCmInEdgeRstrtOk;                                       */
/*  input uint8 Sync_noEdgeCmAccuRstrt_C;                                     */
/*  input uint8 Sync_ctCmExEdgeRstrtOk;                                       */
/*  input uint8 Sync_noEdgeCmNotAccuRstrt_C;                                  */
/*  output boolean Sync_bEngSyncAccu;                                         */
/*  output boolean Sync_bEngSyncNotAccu;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidSyncCalcRstrt(void)
{
   boolean  bLocalSync_bEngSyncAccu;
   boolean  bLocalSync_bEngSyncNotAccu;
   boolean  bLocalSync_bVldAgEs;


   VEMS_vidGET(Sync_bVldAgEs, bLocalSync_bVldAgEs);
   if (  (Sync_bDetLTo != 0)
      || (  (Sync_ctCmInEdgeRstrtOk >= Sync_noEdgeCmAccuRstrt_C)
         || (Sync_ctCmExEdgeRstrtOk >= Sync_noEdgeCmAccuRstrt_C)))
   {
      bLocalSync_bEngSyncAccu = 1;
   }
   else
   {
      bLocalSync_bEngSyncAccu = 0;
   }
   VEMS_vidSET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   if (  (Sync_ctCmInEdgeRstrtOk >= Sync_noEdgeCmNotAccuRstrt_C)
      || (Sync_ctCmExEdgeRstrtOk >= Sync_noEdgeCmNotAccuRstrt_C))
   {
      bLocalSync_bEngSyncNotAccu = 1;
   }
   else
   {
      bLocalSync_bEngSyncNotAccu = 0;
   }

   if (  (bLocalSync_bEngSyncAccu != 0)
      || (Sync_bDetLTo != 0)
      || (bLocalSync_bVldAgEs != 0)
      || (bLocalSync_bEngSyncNotAccu != 0))
   {
      VEMS_vidSET(Sync_bEngSyncNotAccu, 1);
   }
   else
   {
      VEMS_vidSET(Sync_bEngSyncNotAccu, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidEngStopPosn                                     */
/* !Description :  Lors de la détection d’arrêt moteur on force la variable   */
/*                 Sync_bVldAgEs à la valeur de Sync_bEngSyncAccu.  On        */
/*                 effectue également la lecture de l’API donnant la position */
/*                 d’arrêt moteur calculée.                                   */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_031.01                                     */
/*                 VEMS_E_10_06977_032.01                                     */
/*                 VEMS_R_10_06977_011.01                                     */
/*                 VEMS_R_10_06977_012.01                                     */
/*                 VEMS_R_10_06977_013.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean Sync_bEngPosOk;                                             */
/*  input uint16 Acq_angle_arret_moteur;                                      */
/*  output boolean Sync_bVldAgEs;                                             */
/*  output boolean Sync_bDetEs;                                               */
/*  output uint8 Sync_agEs;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidEngStopPosn(void)
{
   boolean bLocalSync_bEngSyncAccu;
   boolean bLocalSync_bVldAgEs;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalSync_bEngPosOk;
   uint8   u8LocalSync_agEs;
   uint16  u16LocalEngStopPosition;
   uint16  u16LocalAcqAngleArretMoteur;


   VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(Sync_bEngPosOk, bLocalSync_bEngPosOk);
   if (bLocalSync_bDgoCkSig != 0)
   {
      bLocalSync_bVldAgEs = 0;
   }
   else
   {
      if (  (bLocalSync_bEngSyncAccu != 0)
         && (bLocalSync_bEngPosOk != 0))
      {
         bLocalSync_bVldAgEs = 1;
      }
      else
      {
         bLocalSync_bVldAgEs = 0;
      }
   }
   VEMS_vidSET(Sync_bVldAgEs, bLocalSync_bVldAgEs);
   VEMS_vidSET(Sync_bDetEs, 1);

   VEMS_vidGET(Acq_angle_arret_moteur, u16LocalAcqAngleArretMoteur);
   u16LocalEngStopPosition =
      (uint16)(u16LocalAcqAngleArretMoteur  / 192);
   u8LocalSync_agEs = (uint8)MATHSRV_udtMIN(u16LocalEngStopPosition, 240);

   VEMS_vidSET(Sync_agEs, u8LocalSync_agEs);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidForcSyncOff                                     */
/* !Description :  Fonction permettant en cas de défaillance du signal        */
/*                 vilebrequin ou sur demande de désynchronisation forcée, on */
/*                 passe les  variables de synchronisation à 0.               */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_10_06977_001.01                                     */
/*                 VEMS_R_10_06977_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bEngSyncAccu;                                         */
/*  output boolean Sync_bEngSyncNotAccu;                                      */
/*  output boolean Sync_bDetLTo;                                              */
/*  output uint8 Sync_ctCmInEdgeRstrtOk;                                      */
/*  output uint8 Sync_ctCmExEdgeRstrtOk;                                      */
/*  output uint8 Sync_ctCmInEdgeStrtOk;                                       */
/*  output uint8 Sync_ctCmExEdgeStrtOk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidForcSyncOff(void)
{
   VEMS_vidSET(Sync_bEngSyncAccu, 0);
   VEMS_vidSET(Sync_bEngSyncNotAccu, 0);
   Sync_bDetLTo = 0;
   Sync_ctCmInEdgeRstrtOk = 0;
   Sync_ctCmExEdgeRstrtOk = 0;
   Sync_ctCmInEdgeStrtOk = 0;
   Sync_ctCmExEdgeStrtOk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidCkOff                                           */
/* !Description :  Lors de la perte de la synchronisation par le LDB,  ou lors*/
/*                  d’un arrêt moteur, sur l’événement Crank Off, on          */
/*                 réinitialise les variables de synchronisation.             */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bDetLTo;                                              */
/*  output boolean Sync_bEngSyncAccu;                                         */
/*  output boolean Sync_bEngSyncNotAccu;                                      */
/*  output uint8 Sync_ctTDC;                                                  */
/*  output uint8 Sync_ctCmInEdgeRstrtOk;                                      */
/*  output uint8 Sync_ctCmExEdgeRstrtOk;                                      */
/*  output uint8 Sync_ctCmInEdgeStrtOk;                                       */
/*  output uint8 Sync_ctCmExEdgeStrtOk;                                       */
/*  output boolean Sync_bCalcOk;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidCkOff(void)
{
   Sync_bDetLTo = 0;
   VEMS_vidSET(Sync_bEngSyncAccu, 0);
   VEMS_vidSET(Sync_bEngSyncNotAccu, 0);
   VEMS_vidSET(Sync_ctTDC, 0);
   Sync_ctCmInEdgeRstrtOk = 0;
   Sync_ctCmExEdgeRstrtOk = 0;
   Sync_ctCmInEdgeStrtOk = 0;
   Sync_ctCmExEdgeStrtOk = 0;
   Sync_bCalcOk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidEveProd                                         */
/* !Description :  On crée un évènement lorsque la synchro non précise est    */
/*                 trouvée pour permettre l’autorisation d’injection, ainsi   */
/*                 qu’un évènement lorsque la synchro précise est trouvée pour*/
/*                 permettre l’autorisation de l’allumage.                    */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Sync_EveSyncAccu_SyncSTT();                              */
/*  extf argret void SYNCSTT_vidIniTDCCnt();                                  */
/*  extf argret void SYNCSTT_vidReadToothInfo();                              */
/*  extf argret void Sync_EveSyncNotAccu_SyncSTT();                           */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input boolean Sync_bEngSyncNotAccu;                                       */
/*  input boolean SYNCSTT_bEngSyncAccu_Prev;                                  */
/*  input boolean SYNCSTT_bEngSyncNotAccu_Prev;                               */
/*  output boolean SYNCSTT_bEngSyncAccu_Prev;                                 */
/*  output boolean SYNCSTT_bEngSyncNotAccu_Prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidEveProd(void)
{
   boolean   bLocalSync_bEngSyncAccu;
   boolean   bLocalSync_bEngSyncNotAccu;


   VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   VEMS_vidGET(Sync_bEngSyncNotAccu, bLocalSync_bEngSyncNotAccu);
   if (  (bLocalSync_bEngSyncAccu != 0)
      && (SYNCSTT_bEngSyncAccu_Prev == 0))
   {
      Sync_EveSyncAccu_SyncSTT();
      SYNCSTT_vidIniTDCCnt();
   }

   if (  (bLocalSync_bEngSyncNotAccu != 0)
      && (SYNCSTT_bEngSyncNotAccu_Prev == 0))
   {
      SYNCSTT_vidReadToothInfo();
      Sync_EveSyncNotAccu_SyncSTT();
   }
   SYNCSTT_bEngSyncAccu_Prev = bLocalSync_bEngSyncAccu;
   SYNCSTT_bEngSyncNotAccu_Prev = bLocalSync_bEngSyncNotAccu;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidSync_SdlMid_SyncSTT                             */
/* !Description :  Fonction d'appel de l' événement Sync_SdlMid_SyncSTT       */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCSTT_vidReadToothInfo();                              */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCSTT_vidForcSyncOff();                                */
/*  input boolean CoSync_bForcEngNotSync;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidSync_SdlMid_SyncSTT(void)
{
   boolean  bLocalInhEngSync;
   boolean  bLocalCosync_bForcEngNotSync;


   SYNCSTT_vidReadToothInfo();
   bLocalInhEngSync = GDGAR_bGetFRM(FRM_FRM_INHENGSYNC);
   VEMS_vidGET(CoSync_bForcEngNotSync, bLocalCosync_bForcEngNotSync);
   if (  (bLocalInhEngSync != 0)
      || (bLocalCosync_bForcEngNotSync != 0))
   {
      SYNCSTT_vidForcSyncOff();
   }
}
/*------------------------------ End of file ---------------------------------*/