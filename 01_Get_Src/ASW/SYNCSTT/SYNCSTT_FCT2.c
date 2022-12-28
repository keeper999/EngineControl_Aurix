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
/* !File            : SYNCSTT_FCT2.C                                          */
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
/*   1 / SYNCSTT_vidCkOn                                                      */
/*   2 / SYNCSTT_vidIniTDCCnt                                                 */
/*   3 / SYNCSTT_vidDiagAuth                                                  */
/*   4 / SYNCSTT_vidDiagResult                                                */
/*   5 / SYNCSTT_vidDiag                                                      */
/*   6 / SYNCSTT_vidEngStopPosnAfter                                          */
/*   7 / SYNCSTT_vidReadToothInfo                                             */
/*   8 / SYNCSTT_vidTDCCnt                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_6912870 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNCSTT/SYNCSTT_FCT2.C_v          $*/
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
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidCkOn                                            */
/* !Description :  Fonction pour remise à zero du Sync_bDetEs                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bDetEs;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidCkOn(void)
{
   VEMS_vidSET(Sync_bDetEs, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidIniTDCCnt                                       */
/* !Description :  Lors de la synchronisation moteur, .on vient lire la       */
/*                 position angulaire du moteur. A partir de la position      */
/*                 d’arrêt moteur on détermine l’angle moteur parcouru entre  */
/*                 la position d’arrêt et la position de synchronisation.     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_020.01                                     */
/*                 VEMS_R_10_06977_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_agEs;                                                    */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Acq_pos_ang_lors_synchro;                                    */
/*  input uint8 Sync_agTDC;                                                   */
/*  input uint8 Sync_agEngStopToSync;                                         */
/*  output uint8 Sync_agEngStopToSync;                                        */
/*  output uint8 Sync_agTDC;                                                  */
/*  output uint8 Sync_ctTDC;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidIniTDCCnt(void)
{
   uint8  u8LocalSync_agEs;
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalEngStopToSync;
   uint8  u8LocalSync_ctTDC;
   uint16 u16LocalSync_agTDC;
   uint16 u16LocalSync_agTDC_1;
   uint16 u16LocalAcqPosAngLorsSynchro;
   sint16 s16LocalSync_ctTDC;
   uint32 u32LocalSync_agTDC;
   sint32 s32LocalSync_agTDC;
   sint32 s32LocalDiff;

   VEMS_vidGET(Sync_agEs, u8LocalSync_agEs);
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(Acq_pos_ang_lors_synchro, u16LocalAcqPosAngLorsSynchro);

   s32LocalDiff =
      (sint32)(u16LocalAcqPosAngLorsSynchro - (u8LocalSync_agEs * 192));
   if (s32LocalDiff >= 0)
   {
      s32LocalDiff = s32LocalDiff / 192;
      Sync_agEngStopToSync = (uint8)MATHSRV_udtMIN(s32LocalDiff, 240);
   }
   else
   {
      s32LocalDiff = (s32LocalDiff + 46080) / 192;
      Sync_agEngStopToSync = (uint8)MATHSRV_udtMAX(s32LocalDiff, 0);
   }

   if (u8LocalExt_noCylEng != 0)
   {
      Sync_agTDC = (uint8)(12 / u8LocalExt_noCylEng);
   }
   else
   {
      Sync_agTDC = 12;
   }

   if (Sync_agTDC != 0)
   {
      u16LocalSync_agTDC = (uint16)(Sync_agTDC * 20);
      u8LocalEngStopToSync = (uint8)(Sync_agEngStopToSync / u16LocalSync_agTDC);
      if ((u8LocalSync_agEs % u16LocalSync_agTDC) == 0)
      {
         if ((Sync_agEngStopToSync % u16LocalSync_agTDC) != 0)
         {
            s16LocalSync_ctTDC = (sint16)(u8LocalEngStopToSync + 1);
         }
         else
         {
            s16LocalSync_ctTDC = (sint16)u8LocalEngStopToSync;
         }
      }
      else
      {
         u16LocalSync_agTDC_1 =
            (uint16)((u8LocalSync_agEs / u16LocalSync_agTDC) + 1);
         u32LocalSync_agTDC = u16LocalSync_agTDC_1 * u16LocalSync_agTDC;
         s32LocalSync_agTDC = (sint32)(u32LocalSync_agTDC - u8LocalSync_agEs);
         s32LocalSync_agTDC = (Sync_agEngStopToSync - s32LocalSync_agTDC);
         if (s32LocalSync_agTDC <= 0)
         {
            s16LocalSync_ctTDC = 0;
         }
         else
         {
            if ((s32LocalSync_agTDC % u16LocalSync_agTDC) == 0)
            {
               s16LocalSync_ctTDC =
                  (sint16)(s32LocalSync_agTDC /  u16LocalSync_agTDC);
            }
            else
            {
               s16LocalSync_ctTDC =
                  (sint16)((s32LocalSync_agTDC /  u16LocalSync_agTDC) + 1);
            }
         }
      }
   }
   else
   {
      s16LocalSync_ctTDC = 255;
   }
   u8LocalSync_ctTDC = (uint8)MATHSRV_udtMAX(s16LocalSync_ctTDC, 0);
   VEMS_vidSET(Sync_ctTDC, u8LocalSync_ctTDC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidDiagAuth                                        */
/* !Description :  fonction de calcul de Sync_bMonRunDistSig                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 Sync_nEngDiagLoThd_C;                                         */
/*  output boolean Sync_bMonRunDistSig;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidDiagAuth(void)
{
   boolean  bLocalInhNoSigSigLossCkDiag;
   uint16   u16LocalExt_nEng;
   uint16   u16LocalSync_nEngDiagLoThd_C;


   bLocalInhNoSigSigLossCkDiag = GDGAR_bGetFRM(FRM_FRM_INHNOSIGSIGLOSSCKDIAG);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalSync_nEngDiagLoThd_C = (uint16)(Sync_nEngDiagLoThd_C * 10);
   if (  (bLocalInhNoSigSigLossCkDiag == 0)
      && (u16LocalExt_nEng >= u16LocalSync_nEngDiagLoThd_C))
   {
      Sync_bMonRunDistSig = 1;
   }
   else
   {
      Sync_bMonRunDistSig = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidDiagResult                                      */
/* !Description :  fonction de calcul de Sync_bDgoDistSig                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCSTT_vidDiag();                                       */
/*  input boolean Sync_bMonRunDistSig;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidDiagResult(void)
{
   if (Sync_bMonRunDistSig != 0)
   {
      SYNCSTT_vidDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidDiag                                            */
/* !Description :  fonction de calcul de defaut DistSig                       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Sync_noToTar_C;                                               */
/*  input uint8 Sync_noToDft_C;                                               */
/*  input uint8 Sync_noToGapTar_C;                                            */
/*  input uint8 Sync_ctTeeth;                                                 */
/*  output boolean Sync_bDgoDistSig;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidDiag(void)
{
   uint8  u8LocalSync_ctTeeth;
   sint16 s16LocalSync_noTo1;
   sint16 s16LocalSync_noTo2;


   s16LocalSync_noTo1 = (sint16)( (Sync_noToTar_C + Sync_noToDft_C)
                                - Sync_noToGapTar_C);
   s16LocalSync_noTo2 = (sint16)( (Sync_noToTar_C - Sync_noToDft_C)
                                - Sync_noToGapTar_C);
   VEMS_vidGET(Sync_ctTeeth, u8LocalSync_ctTeeth);
   if (  (u8LocalSync_ctTeeth >= s16LocalSync_noTo1)
      || (u8LocalSync_ctTeeth <= s16LocalSync_noTo2))
   {
      Sync_bDgoDistSig = 1;
   }
   else
   {
      Sync_bDgoDistSig = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidEngStopPosnAfter                                */
/* !Description :  Lors de la détection de la singularité du signal           */
/*                 vilebrequin on effectue la lecture de l’API donnant la     */
/*                 position d’arrêt du moteur calculée à posteriori.          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_021.01                                     */
/*                 VEMS_E_10_06977_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acq_angle_arret_moteur_redem;                                */
/*  output uint8 Sync_agEsAfter;                                              */
/*  output boolean Sync_bCalcOk;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidEngStopPosnAfter(void)
{
   uint8  u8LocalSync_agEsAfter;
   uint16 u16LocalAcqAngleArretMoteurRedem;


   VEMS_vidGET(Acq_angle_arret_moteur_redem, u16LocalAcqAngleArretMoteurRedem);

   u16LocalAcqAngleArretMoteurRedem =
      (uint16)((u16LocalAcqAngleArretMoteurRedem + 96) / 192);
   u8LocalSync_agEsAfter =
      (uint8)MATHSRV_udtMIN(u16LocalAcqAngleArretMoteurRedem, 240);

   VEMS_vidSET(Sync_agEsAfter, u8LocalSync_agEsAfter);
   Sync_bCalcOk = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidReadToothInfo                                   */
/* !Description :  Fonction de lecture des variables de synchronisation       */
/*                 provenant du LdB.                                          */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_023.02                                     */
/*                 VEMS_E_10_06977_024.01                                     */
/*                 VEMS_E_10_06977_025.01                                     */
/*                 VEMS_R_10_06977_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sync_bEngSyncNotAccu;                                       */
/*  input boolean Acq_sens_rotation_moteur;                                   */
/*  input boolean Acq_position_anglaire_moteur;                               */
/*  input uint8 Acq_tooth_compteur;                                           */
/*  input uint32 Acq_dernier_tps_inter_dent_vileb;                            */
/*  input uint32 Acq_av_dernie_tps_int_dent_vileb;                            */
/*  input uint16 Acq_angle_moteur;                                            */
/*  output uint8 Ext_ctEdgeCk;                                                */
/*  output uint32 Ext_tiCgt;                                                  */
/*  output uint32 BufNEs_tiCgtLst;                                            */
/*  output uint8 Sync_agEng;                                                  */
/*  output boolean Ext_bDirRotCk;                                             */
/*  output boolean Sync_bEngPosOk;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidReadToothInfo(void)
{
   boolean bLocalSync_bEngSyncNotAccu;
   boolean bLocalAcqSensRotationMoteur;
   boolean bLocalAcqPositionAnglaireMoteur;
   boolean bLocalExt_bDirRotCk;
   uint8   u8LocalExt_ctEdgeCk;
   uint8   u8LocalSync_agEng;
   uint8   u8LocalAcqToothCompteur;
   uint16  u16LocalAcqAngleMoteur;
   uint32  u32LocalExtTiCgt;
   uint32  u32LocalBufNEs_tiCgtLst1;
   uint32  u32LocalAcqDerTpsIntDentVileb;
   uint32  u32LocalAcqAvDerTpsIntDentVileb;


   VEMS_vidGET(Sync_bEngSyncNotAccu, bLocalSync_bEngSyncNotAccu);
   VEMS_vidGET(Acq_sens_rotation_moteur, bLocalAcqSensRotationMoteur);
   VEMS_vidGET(Acq_position_anglaire_moteur, bLocalAcqPositionAnglaireMoteur);
   VEMS_vidGET(Acq_tooth_compteur, u8LocalAcqToothCompteur);
   VEMS_vidGET(Acq_dernier_tps_inter_dent_vileb, u32LocalAcqDerTpsIntDentVileb);
   VEMS_vidGET(Acq_av_dernie_tps_int_dent_vileb,
               u32LocalAcqAvDerTpsIntDentVileb);
   VEMS_vidGET(Acq_angle_moteur, u16LocalAcqAngleMoteur);

   u8LocalExt_ctEdgeCk = u8LocalAcqToothCompteur;
   u32LocalExtTiCgt = u32LocalAcqDerTpsIntDentVileb / 10;
   u32LocalExtTiCgt = MATHSRV_udtMIN(u32LocalExtTiCgt, 500000);
   u32LocalBufNEs_tiCgtLst1 = u32LocalAcqAvDerTpsIntDentVileb / 10;
   u32LocalBufNEs_tiCgtLst1 =
      MATHSRV_udtMIN(u32LocalBufNEs_tiCgtLst1, 500000);

   if (bLocalSync_bEngSyncNotAccu != 0)
   {
      u16LocalAcqAngleMoteur = (uint16)((u16LocalAcqAngleMoteur + 192) / 384);
      u8LocalSync_agEng = (uint8)MATHSRV_udtMIN(u16LocalAcqAngleMoteur, 120);
   }
   else
   {
      u8LocalSync_agEng = 0;
   }

   if (bLocalAcqSensRotationMoteur != 0)
   {
      bLocalExt_bDirRotCk = 1;
   }
   else
   {
      bLocalExt_bDirRotCk = 0;
   }
   VEMS_vidSET(Ext_ctEdgeCk, u8LocalExt_ctEdgeCk);
   VEMS_vidSET(Ext_tiCgt, u32LocalExtTiCgt);
   VEMS_vidSET(BufNEs_tiCgtLst, u32LocalBufNEs_tiCgtLst1);
   VEMS_vidSET(Sync_agEng, u8LocalSync_agEng);
   VEMS_vidSET(Ext_bDirRotCk, bLocalExt_bDirRotCk);
   VEMS_vidSET(Sync_bEngPosOk, bLocalAcqPositionAnglaireMoteur);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidTDCCnt                                          */
/* !Description :  On incrémente le compteur de PMH à chaque évènement PMH,   */
/*                 uniquement à partir du moment où la position, de ceux-ci   */
/*                 est connue, c'est-à-dire lorsque la synchro est OK.        */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_ctTDC;                                                   */
/*  output uint8 Sync_ctTDC;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidTDCCnt(void)
{
   uint8 u8LocalSync_ctTDC;


   VEMS_vidGET(Sync_ctTDC, u8LocalSync_ctTDC);
   if (u8LocalSync_ctTDC < 255)
   {
      u8LocalSync_ctTDC = (uint8)(u8LocalSync_ctTDC + 1);
   }
   u8LocalSync_ctTDC = (uint8)(u8LocalSync_ctTDC % 255);
   VEMS_vidSET(Sync_ctTDC, u8LocalSync_ctTDC);
}

/*------------------------------ End of file ---------------------------------*/