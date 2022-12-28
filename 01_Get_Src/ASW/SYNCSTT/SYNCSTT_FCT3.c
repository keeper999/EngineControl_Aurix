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
/* !File            : SYNCSTT_FCT3.C                                          */
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
/*   1 / SYNCSTT_vidDetLTo                                                    */
/*   2 / SYNCSTT_vidTeethCnt                                                  */
/*   3 / SYNCSTT_vidCnt                                                       */
/*   4 / SYNCSTT_vidRstTeethCnt                                               */
/*   5 / SYNCSTT_vidctEdgeCmInStrt                                            */
/*   6 / SYNCSTT_vidctEdgeCmExStrt                                            */
/*   7 / SYNCSTT_vidChangeOfMind                                              */
/*   8 / SYNCSTT_vidRstSyncVar                                                */
/*   9 / SYNCSTT_vidSyncCalcStrt                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6912870 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNCSTT/SYNCSTT_FCT3.C_v          $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   04 Aug 2014 $*/
/* $Author::   wbouach                                $$Date::   04 Aug 2014 $*/
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
/* !Function    :  SYNCSTT_vidDetLTo                                          */
/* !Description :  Lors de la détection de la singularité vilebrequin, on     */
/*                 passe les variables Sync_bDetLTo et Sync_bDetLTo2  à 1.    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bDetLTooth;                                           */
/*  output boolean Sync_bDetLTo;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidDetLTo(void)
{
   Sync_bDetLTooth = 1;
   Sync_bDetLTo = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidTeethCnt                                        */
/* !Description :  donction de compteur de dents vilebrequin                  */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCSTT_vidCnt();                                        */
/*  extf argret void SYNCSTT_vidRstTeethCnt();                                */
/*  input boolean Sync_bDetLTooth;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidTeethCnt(void)
{
   SYNCSTT_vidCnt();
   if (Sync_bDetLTooth != 0)
   {
      SYNCSTT_vidRstTeethCnt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidCnt                                             */
/* !Description :  On incrémente le compteur de dents vilebrequin sur         */
/*                 l’évènement dent vilebrequin.                              */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_ctTeeth;                                                 */
/*  input uint8 Sync_noToTar_C;                                               */
/*  input uint8 Sync_noToGapTar_C;                                            */
/*  output uint8 Sync_ctTeeth;                                                */
/*  output boolean Ext_bDetCgtMiss;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidCnt(void)
{
   boolean  bLocalExt_bDetCgtMiss;
   uint8    u8LocalSync_ctTeeth;
   sint16   s16LocalSync_noToDiff;


   VEMS_vidGET(Sync_ctTeeth, u8LocalSync_ctTeeth);
   if ( u8LocalSync_ctTeeth < 255)
   {
      u8LocalSync_ctTeeth = (uint8)(u8LocalSync_ctTeeth + 1);
   }
   s16LocalSync_noToDiff = (sint16)(Sync_noToTar_C - Sync_noToGapTar_C);
   if (u8LocalSync_ctTeeth == s16LocalSync_noToDiff)
   {
      bLocalExt_bDetCgtMiss = 1;
   }
   else
   {
      bLocalExt_bDetCgtMiss = 0;
   }
   u8LocalSync_ctTeeth = (uint8)MATHSRV_udtMIN(u8LocalSync_ctTeeth, 70);
   VEMS_vidSET(Sync_ctTeeth, u8LocalSync_ctTeeth);
   VEMS_vidSET(Ext_bDetCgtMiss, bLocalExt_bDetCgtMiss);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidRstTeethCnt                                     */
/* !Description :  Lorsqu’on a détecté la dent longue de la cible vilebrequin,*/
/*                 on effectue un reset du compteur de dent vilebrequin et de */
/*                 la variable permettant la détection de la singularité      */
/*                 vilebrequin dès la dent suivante.                          */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Sync_ctTeeth;                                                */
/*  output boolean Sync_bDetLTooth;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidRstTeethCnt(void)
{
   VEMS_vidSET(Sync_ctTeeth, 0);
   Sync_bDetLTooth = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidctEdgeCmInStrt                                  */
/* !Description :  A chaque détection de front AAC admission, la fonction     */
/*                 vérifie que la position de ce front est située à moins de  */
/*                 Sync_agWinAgCmTh_C de sa position théorique.  Si c’est le  */
/*                 cas on incrémente le compteur de fronts AAC correspondant à*/
/*                 ce critère.                                                */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acq_pos_ang_moteur_front_aac_adm;                            */
/*  input uint8 Sync_agEngStrtInCmEdge;                                       */
/*  input uint16 Sync_prm_agRefInCmEdge_C[6];                                 */
/*  input uint8 Sync_agWinAgCmTh_C;                                           */
/*  input uint8 Sync_ctCmInEdgeStrtOk;                                        */
/*  output uint8 Sync_agEngStrtInCmEdge;                                      */
/*  output uint8 Sync_ctCmInEdgeStrtOk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidctEdgeCmInStrt(void)
{
   boolean bLocalResult;
   uint16  u16LocalSync_ctCmInEdgeStrtOk;
   uint16  u16LocalSync_prm_agDiffABS;
   uint16  u16LocalSync_agEngStrtInCmEdge;
   uint16  u16LocalAcqPosAngMotFrontAacAdm;
   uint32  u32LocalIndex;
   sint32  s32LocalSync_prm_agDiff;


   VEMS_vidGET(Acq_pos_ang_moteur_front_aac_adm,
               u16LocalAcqPosAngMotFrontAacAdm);
   u16LocalSync_agEngStrtInCmEdge =
      (uint16)((u16LocalAcqPosAngMotFrontAacAdm + 192) / 384);
   Sync_agEngStrtInCmEdge =
      (uint8)MATHSRV_udtMIN(u16LocalSync_agEngStrtInCmEdge, 120);

   bLocalResult = 0;
   for ( (u32LocalIndex = 0);
       (  (u32LocalIndex < 6)
       && (bLocalResult == 0));
       u32LocalIndex++)
   {
      s32LocalSync_prm_agDiff =
         (sint32)( (6 * Sync_agEngStrtInCmEdge)
                 - Sync_prm_agRefInCmEdge_C[u32LocalIndex]);
      u16LocalSync_prm_agDiffABS =
         (uint16)MATHSRV_udtABS(s32LocalSync_prm_agDiff);
      if (u16LocalSync_prm_agDiffABS < Sync_agWinAgCmTh_C)
      {
         bLocalResult = 1;
      }
   }

   if (bLocalResult != 0)
   {
      u16LocalSync_ctCmInEdgeStrtOk = (uint16)(Sync_ctCmInEdgeStrtOk + 1);
   }
   else
   {
      u16LocalSync_ctCmInEdgeStrtOk = (uint16)(Sync_ctCmInEdgeStrtOk);
   }
   Sync_ctCmInEdgeStrtOk = (uint8)(u16LocalSync_ctCmInEdgeStrtOk % 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidctEdgeCmExStrt                                  */
/* !Description :  A chaque détection de front AAC échappement, la fonction   */
/*                 vérifie que la position de ce front est située à moins de  */
/*                 Sync_agWinAgCmTh_C de sa position théorique.  Si c’est le  */
/*                 cas on incrémente le compteur de fronts AAC correspondant à*/
/*                 ce critère.                                                */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acq_pos_ang_moteur_front_aac_ech;                            */
/*  input uint8 Sync_agEngStrtExCmEdge;                                       */
/*  input uint16 Sync_prm_agRefExCmEdge_C[6];                                 */
/*  input uint8 Sync_agWinAgCmTh_C;                                           */
/*  input uint8 Sync_ctCmExEdgeStrtOk;                                        */
/*  output uint8 Sync_agEngStrtExCmEdge;                                      */
/*  output uint8 Sync_ctCmExEdgeStrtOk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidctEdgeCmExStrt(void)
{
   boolean bLocalResult;
   uint16  u16LocalSync_ctCmExEdgeStrtOk;
   uint16  u16LocalSync_prm_agDiffABS;
   uint16  u16LocalSync_agEngStrtExCmEdge;
   uint16  u16LocalAcqPosAngMotFrontAacEch;
   uint32  u32LocalIndex;
   sint32  s32LocalSync_prm_agDiff;


   VEMS_vidGET(Acq_pos_ang_moteur_front_aac_ech,
               u16LocalAcqPosAngMotFrontAacEch);
   u16LocalSync_agEngStrtExCmEdge =
      (uint16)((u16LocalAcqPosAngMotFrontAacEch  + 192) / 384);
   Sync_agEngStrtExCmEdge =
      (uint8)MATHSRV_udtMIN(u16LocalSync_agEngStrtExCmEdge, 120);

   bLocalResult = 0;
   for ( (u32LocalIndex = 0);
       (  (u32LocalIndex < 6)
       && (bLocalResult == 0));
       u32LocalIndex++)
   {
      s32LocalSync_prm_agDiff =
         (sint32)( (6 * Sync_agEngStrtExCmEdge)
                 - Sync_prm_agRefExCmEdge_C[u32LocalIndex]);
      u16LocalSync_prm_agDiffABS =
         (uint16)MATHSRV_udtABS(s32LocalSync_prm_agDiff);
      if (u16LocalSync_prm_agDiffABS < Sync_agWinAgCmTh_C)
      {
         bLocalResult = 1;
      }
   }

   if (bLocalResult != 0)
   {
      u16LocalSync_ctCmExEdgeStrtOk = (uint16)(Sync_ctCmExEdgeStrtOk + 1);
   }
   else
   {
      u16LocalSync_ctCmExEdgeStrtOk = (uint16)(Sync_ctCmExEdgeStrtOk);
   }
   Sync_ctCmExEdgeStrtOk = (uint8)(u16LocalSync_ctCmExEdgeStrtOk % 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidChangeOfMind                                    */
/* !Description :  Sur l’évènement N_Inv_Off on vient vérifier si la position */
/*                 angulaire du moteur est connue. Si c’est le cas alors es   */
/*                 variables de synchronisation reste à 1.                    */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void SYNCSTT_vidSyncCalcStrt();                               */
/*  extf argret void SYNCSTT_vidRstSyncVar();                                 */
/*  input boolean CoSync_bForcEngNotSync;                                     */
/*  input boolean Acq_statut_pos_angulaire_moteur;                            */
/*  input boolean SYNCSTT_bAcqStPosAngMoteur_Prev;                            */
/*  output boolean SYNCSTT_bAcqStPosAngMoteur_Prev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidChangeOfMind(void)
{
   boolean bLocalFRM_bInhEngSync;
   boolean bLocalCoSync_bForcEngNotSync;
   boolean bLocalAcqStatutPosAngMoteur;


   VEMS_vidGET(CoSync_bForcEngNotSync, bLocalCoSync_bForcEngNotSync);
   VEMS_vidGET(Acq_statut_pos_angulaire_moteur, bLocalAcqStatutPosAngMoteur);
   bLocalFRM_bInhEngSync = GDGAR_bGetFRM(FRM_FRM_INHENGSYNC);
   if (bLocalAcqStatutPosAngMoteur == 1)
   {
      /*Generation of the event Sync_EveChgOfMind_SyncSTT*/
      if (  (bLocalCoSync_bForcEngNotSync == 0)
         && (bLocalFRM_bInhEngSync == 0))
      {
         SYNCSTT_vidSyncCalcStrt();
      }

      /*F01_RstSyncVar*/
      if (SYNCSTT_bAcqStPosAngMoteur_Prev == 0)
      {
         SYNCSTT_vidRstSyncVar();
      }
   }

   SYNCSTT_bAcqStPosAngMoteur_Prev = bLocalAcqStatutPosAngMoteur;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidRstSyncVar                                      */
/* !Description :  Si la position angulaire du moteur n’est plus connue par le*/
/*                 LDB, on force les variables de synchronisation à 0         */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
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
void SYNCSTT_vidRstSyncVar(void)
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
/* !Function    :  SYNCSTT_vidSyncCalcStrt                                    */
/* !Description :  Ce bloc permet de calculer les variables de synchronisation*/
/*                 précise et imprécise après un démarrage. Il est  appelé par*/
/*                 un évènement interne qui dépend de différentes conditions  */
/*                 d’activatio                                                */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_029.01                                     */
/*                 VEMS_E_10_06977_030.01                                     */
/*                 VEMS_R_10_06977_005.01                                     */
/*                 VEMS_R_10_06977_006.01                                     */
/*                 VEMS_R_10_06977_007.01                                     */
/*                 VEMS_R_10_06977_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sync_bDetLTo;                                               */
/*  input uint8 Sync_ctCmInEdgeStrtOk;                                        */
/*  input uint8 Sync_noEdgeCmAccuStrt_C;                                      */
/*  input uint8 Sync_ctCmExEdgeStrtOk;                                        */
/*  input uint8 Sync_noEdgeCmNotAccuStrt_C;                                   */
/*  output boolean Sync_bEngSyncAccu;                                         */
/*  output boolean Sync_bEngSyncNotAccu;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidSyncCalcStrt(void)
{
   boolean  bLocalSync_bEngSyncAccu;
   boolean  bLocalSync_bEngSyncNotAccu;


   if (  (Sync_bDetLTo != 0)
      && (  (Sync_ctCmInEdgeStrtOk >= Sync_noEdgeCmAccuStrt_C)
         || (Sync_ctCmExEdgeStrtOk >= Sync_noEdgeCmAccuStrt_C)))
   {
      bLocalSync_bEngSyncAccu = 1;
   }
   else
   {
      bLocalSync_bEngSyncAccu = 0;
   }
   VEMS_vidSET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);

   if (  (Sync_ctCmInEdgeStrtOk >= Sync_noEdgeCmNotAccuStrt_C)
      || (Sync_ctCmExEdgeStrtOk >= Sync_noEdgeCmNotAccuStrt_C))
   {
      bLocalSync_bEngSyncNotAccu = 1;
   }
   else
   {
      bLocalSync_bEngSyncNotAccu = 0;
   }

   if (  (bLocalSync_bEngSyncAccu != 0)
      || (Sync_bDetLTo != 0)
      || (bLocalSync_bEngSyncNotAccu != 0))
   {
      VEMS_vidSET(Sync_bEngSyncNotAccu, 1);
   }
   else
   {
      VEMS_vidSET(Sync_bEngSyncNotAccu, 0);
   }
}

/*------------------------------ End of file ---------------------------------*/