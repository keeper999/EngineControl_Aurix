/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COSYNC                                                  */
/* !Description     : COSYNC component.                                       */
/*                                                                            */
/* !Module          : COSYNC                                                  */
/* !Description     : Superviseur de la fonction de synchronisation           */
/*                                                                            */
/* !File            : COSYNC_FCT2.c                                           */
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
/*   1 / COSYNC_vidBouchSortiesGrippgeVil                                     */
/*   2 / COSYNC_vidActvCalcDetectionArret                                     */
/*   3 / COSYNC_vidDetecterGererArretMotr                                     */
/*   4 / COSYNC_vidDetectArretAvcBckupVil                                     */
/*   5 / COSYNC_vidDetectArretSnsBckupVil                                     */
/*   6 / COSYNC_vidCreerInfoArretMoteur                                       */
/*   7 / COSYNC_vidCalculerComptrPMHa10ms                                     */
/*   8 / COSYNC_vidBouchSortiesDetecArret                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 02290 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2284 / 02                                       */
/* !OtherRefs   : VEMS V02 ECU#048141                                         */
/* !OtherRefs   : VEMS V02 ECU#048312                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COSYNC/COSYNC_FCT2.c_v$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   Jun 28 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 28 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "COSYNC.h"
#include "COSYNC_L.h"
#include "COSYNC_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidBouchSortiesGrippgeVil                           */
/* !Description :  Ce bloc permet de bouchonner les variables de la fonction «*/
/*                 Prévenir du risque de blocage vilebrequin » si le calcul de*/
/*                 la fonction n’est pas activé.                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoSync_bAcvCalcStuckEng;                                    */
/*  input boolean CoSync_bForcEngNotSyncRaw;                                  */
/*  input boolean CoSync_bStuckEngStaAcvRaw;                                  */
/*  output boolean CoSync_bForcEngNotSync;                                    */
/*  output boolean CoSync_bForcEngNotSyncRaw;                                 */
/*  output boolean CoSync_bStuckEngStaAcv;                                    */
/*  output boolean CoSync_bStuckEngStaAcvRaw;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidBouchSortiesGrippgeVil(void)
{
   if (CoSync_bAcvCalcStuckEng != 0)
   {
      VEMS_vidSET(CoSync_bForcEngNotSync, CoSync_bForcEngNotSyncRaw);
      VEMS_vidSET(CoSync_bStuckEngStaAcv, CoSync_bStuckEngStaAcvRaw);
   }
   else
   {
      VEMS_vidSET(CoSync_bForcEngNotSync, 0);
      VEMS_vidSET(CoSync_bStuckEngStaAcv, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidActvCalcDetectionArret                           */
/* !Description :  Ce bloc permet d’activer ou pas le calcul d’information de */
/*                 détection d’arrêt moteur.                                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean CoSync_bAcvCalcDetEs;                                       */
/*  input uint8 CoSync_nAcvDetEs_C;                                           */
/*  input boolean CoSync_bAcvDetEs_C;                                         */
/*  output boolean CoSync_bAcvCalcDetEs;                                      */
/*  output boolean CoSync_bAcvDetEsIni;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidActvCalcDetectionArret(void)
{
   boolean bLocalAcvCoSyncDftCk;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalCoSync_bAcvCalcDetEs;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalCoSync_nAcvDetEs_C;


   bLocalAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   VEMS_vidGET(Ext_nEng,u16LocalExt_nEng);
   VEMS_vidGET(Sync_bDgoCkSig,bLocalSync_bDgoCkSig);

   bLocalCoSync_bAcvCalcDetEs = CoSync_bAcvCalcDetEs;
   u16LocalCoSync_nAcvDetEs_C = (uint16)(CoSync_nAcvDetEs_C * 10);

   if (  (CoSync_bAcvDetEs_C != 0)
      && (  (u16LocalExt_nEng <= u16LocalCoSync_nAcvDetEs_C)
         || (bLocalAcvCoSyncDftCk != 0)
         || (bLocalSync_bDgoCkSig != 0)))
   {
      CoSync_bAcvCalcDetEs = 1;
   }
   else
   {
      CoSync_bAcvCalcDetEs = 0;
   }

   if (  (CoSync_bAcvCalcDetEs != 0)
      && (bLocalCoSync_bAcvCalcDetEs == 0))
   {
      CoSync_bAcvDetEsIni = 1;
   }
   else
   {
      CoSync_bAcvDetEsIni = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidDetecterGererArretMotr                           */
/* !Description :  Ce bloc permet de fournir plusieurs informations : 1. La   */
/*                 détection d’un régime nul (le moteur est effectivement à   */
/*                 l’arrêt), 2. Le fait qu’une détection d’arrêt vient d’avoir*/
/*                 lieu, 3. Un compteur de nombre de PMH resté lors de la     */
/*                 détection d’arrêt moteur.                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COSYNC_vidDetectArretAvcBckupVil();                      */
/*  extf argret void COSYNC_vidDetectArretSnsBckupVil();                      */
/*  extf argret void COSYNC_vidCreerInfoArretMoteur();                        */
/*  extf argret void COSYNC_vidCalculerComptrPMHa10ms();                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidDetecterGererArretMotr(void)
{
   COSYNC_vidDetectArretAvcBckupVil();
   COSYNC_vidDetectArretSnsBckupVil();
   COSYNC_vidCreerInfoArretMoteur();
   COSYNC_vidCalculerComptrPMHa10ms();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidDetectArretAvcBckupVil                           */
/* !Description :  Ce bloc permet de créer une information de détection       */
/*                 d’arrêt moteur à partir du signal AAC.                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*  input uint8 Ext_ctEdgeCmIn;                                               */
/*  input uint8 Ext_ctEdgeCmEx;                                               */
/*  input uint8 COSYNC_u8ctEdgeCmInEx;                                        */
/*  input boolean CoSync_bAcvDetEsIni;                                        */
/*  input boolean COSYNC_bDetNNullDgoCkCntInput;                              */
/*  input uint16 CoSync_ctDetNNullDgoCk_MP;                                   */
/*  input uint8 CoSync_tiRbm_C;                                               */
/*  input uint8 CoSync_tiDetEsCm_C;                                           */
/*  output uint8 COSYNC_u8ctEdgeCmInEx;                                       */
/*  output uint16 CoSync_ctDetNNullDgoCk_MP;                                  */
/*  output boolean COSYNC_bDetNNullDgoCkCntInput;                             */
/*  output boolean CoSync_bDetNNullDgoCk;                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidDetectArretAvcBckupVil(void)
{
   boolean bLocalDetNNullDgoCkCntInput;
   uint8   u8LocalCoSync_stSigCm2Sync;
   uint8   u8LocalExt_ctEdgeCmIn;
   uint8   u8LocalExt_ctEdgeCmEx;
   uint8   u8Local_ctEdgeCmInExPrev;
   uint16  u16Local_CounterMaxThreshold;


   VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);
   VEMS_vidGET(Ext_ctEdgeCmIn, u8LocalExt_ctEdgeCmIn);
   VEMS_vidGET(Ext_ctEdgeCmEx, u8LocalExt_ctEdgeCmEx);

   u8Local_ctEdgeCmInExPrev = COSYNC_u8ctEdgeCmInEx;
   if (u8LocalCoSync_stSigCm2Sync == 1)
   {
      COSYNC_u8ctEdgeCmInEx = u8LocalExt_ctEdgeCmIn;
   }
   else
   {
      COSYNC_u8ctEdgeCmInEx = u8LocalExt_ctEdgeCmEx;
   }

   if (  (COSYNC_u8ctEdgeCmInEx != u8Local_ctEdgeCmInExPrev)
      || (CoSync_bAcvDetEsIni != 0))
   {
      bLocalDetNNullDgoCkCntInput = 1;
   }
   else
   {
      bLocalDetNNullDgoCkCntInput = 0;
   }

   if (bLocalDetNNullDgoCkCntInput !=0)
   {
      if (COSYNC_bDetNNullDgoCkCntInput == 0)
      {
         CoSync_ctDetNNullDgoCk_MP = 0;
      }
      else
      {
         if (CoSync_ctDetNNullDgoCk_MP > 600)
         {
            CoSync_ctDetNNullDgoCk_MP = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(CoSync_ctDetNNullDgoCk_MP < u16Local_CounterMaxThreshold)
      {
         CoSync_ctDetNNullDgoCk_MP = (uint16)( CoSync_ctDetNNullDgoCk_MP
                                             + CoSync_tiRbm_C);
      }
      else
      {
         CoSync_ctDetNNullDgoCk_MP = 600;
      }
   }
   COSYNC_bDetNNullDgoCkCntInput = bLocalDetNNullDgoCkCntInput;

   if (  (CoSync_ctDetNNullDgoCk_MP >= CoSync_tiDetEsCm_C)
      && (u8LocalCoSync_stSigCm2Sync != 0))
   {
      CoSync_bDetNNullDgoCk = 1;
   }
   else
   {
      CoSync_bDetNNullDgoCk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidDetectArretSnsBckupVil                           */
/* !Description :  Ce bloc permet de créer une information de détection       */
/*                 d’arrêt moteur à partir du signal vilebrequin. Pour cela,  */
/*                 il faut ne pas avoir vu de fronts sur le signal vilebrequin*/
/*                 pendant un certain temps, temps calibrable en fonction de  */
/*                 certains paramètres.                                       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean Sync_bVldAgEs;                                              */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input uint8 Ext_ctEdgeCk;                                                 */
/*  input uint8 Sync_agEng;                                                   */
/*  input uint8 CoSync_ctEdgeCk_MP;                                           */
/*  input boolean CoSync_bAcvDetEsIni;                                        */
/*  input boolean COSYNC_bDetNNullBasCntInput;                                */
/*  input uint16 CoSync_ctDetNNullBas_MP;                                     */
/*  input uint8 CoSync_tiRbm_C;                                               */
/*  input boolean CoSync_bSelTiDetNulBas_MP;                                  */
/*  input uint8 CoSync_agNearMissCgt_C;                                       */
/*  input uint16 PredEs_agMissCgt_C;                                          */
/*  input uint8 CoSync_tiDetEsMissCgt_C;                                      */
/*  input uint8 CoSync_agNearTDC_C;                                           */
/*  input uint8 CoSync_tiDetEsTDC_C;                                          */
/*  input uint8 CoSync_tiDetEsCgt_C;                                          */
/*  input uint16 CoSync_tiDetNNullBas_MP;                                     */
/*  input uint8 CoSync_tiDetEsCmf_C;                                          */
/*  output uint8 CoSync_agEng_MP;                                             */
/*  output uint8 CoSync_ctEdgeCk_MP;                                          */
/*  output uint16 CoSync_ctDetNNullBas_MP;                                    */
/*  output boolean COSYNC_bDetNNullBasCntInput;                               */
/*  output boolean CoSync_bSelTiDetNulBas_MP;                                 */
/*  output uint16 CoSync_tiDetNNullBas_MP;                                    */
/*  output boolean CoSync_bDetNNullBas;                                       */
/*  output boolean CoSync_bDetNNullCmf;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidDetectArretSnsBckupVil(void)
{
   boolean bLocalDetNNullBasCntInput;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalSync_bVldAgEs;
   boolean bLocalSync_bEngSyncAccu;
   uint8   u8LocalExt_ctEdgeCk;
   uint8   u8LocalSync_agEng;
   uint8   u8LocalCoSync_tiDetNNullBas_MP;
   uint16  u16Local_CounterMaxThreshold;
   uint16  u16LocalSync_agEngMod;
   uint16  u16LocalSync_agEngMaxThdMod;
   uint16  u16LocalDeltaTDC;
   sint16  s16LocalSync_agEngMinThdMod;
   sint32  s32LocalSync_agEngMaxThd;
   sint32  s32LocalSync_agEngMinThd;


   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(Sync_bVldAgEs, bLocalSync_bVldAgEs);
   VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   VEMS_vidGET(Ext_ctEdgeCk, u8LocalExt_ctEdgeCk);
   VEMS_vidGET(Sync_agEng, u8LocalSync_agEng);

   CoSync_agEng_MP = (uint8)MATHSRV_udtMIN(u8LocalSync_agEng, 120);

   if (  (u8LocalExt_ctEdgeCk != CoSync_ctEdgeCk_MP)
      || (CoSync_bAcvDetEsIni != 0))
   {
      bLocalDetNNullBasCntInput = 1;
   }
   else
   {
      bLocalDetNNullBasCntInput = 0;
   }
   CoSync_ctEdgeCk_MP = u8LocalExt_ctEdgeCk;

   if (bLocalDetNNullBasCntInput !=0)
   {
      if (COSYNC_bDetNNullBasCntInput == 0)
      {
         CoSync_ctDetNNullBas_MP = 0;
      }
      else
      {
         if (CoSync_ctDetNNullBas_MP > 600)
         {
            CoSync_ctDetNNullBas_MP = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(CoSync_ctDetNNullBas_MP < u16Local_CounterMaxThreshold)
      {
         CoSync_ctDetNNullBas_MP = (uint16)( CoSync_ctDetNNullBas_MP
                                           + CoSync_tiRbm_C);
      }
      else
      {
         CoSync_ctDetNNullBas_MP = 600;
      }
   }
   COSYNC_bDetNNullBasCntInput = bLocalDetNNullBasCntInput;

   if (  (bLocalSync_bDgoCkSig == 0)
      && (  (bLocalSync_bVldAgEs != 0)
         || (bLocalSync_bEngSyncAccu != 0)))
   {
      CoSync_bSelTiDetNulBas_MP = 1;
   }
   else
   {
      CoSync_bSelTiDetNulBas_MP = 0;
   }

   if (CoSync_bSelTiDetNulBas_MP != 0)
   {
      s32LocalSync_agEngMaxThd = (sint32)( PredEs_agMissCgt_C
                                         + (CoSync_agNearMissCgt_C * 6)
                                         + 18);
      s32LocalSync_agEngMinThd = (sint32)( PredEs_agMissCgt_C
                                         - (CoSync_agNearMissCgt_C * 6));

      u16LocalSync_agEngMod = (uint16)((sint32)(u8LocalSync_agEng * 6) % 360);
      u16LocalSync_agEngMaxThdMod = (uint16)(s32LocalSync_agEngMaxThd % 360);
      s16LocalSync_agEngMinThdMod = (sint16)(s32LocalSync_agEngMinThd % 360);
      /* The "%" operator returns the remainder and not the modulus. */
      if (s16LocalSync_agEngMinThdMod < 0)
      {
         s16LocalSync_agEngMinThdMod = (sint16)( s16LocalSync_agEngMinThdMod
                                               + 360);
      }

      if (  (u16LocalSync_agEngMod <= u16LocalSync_agEngMaxThdMod)
         && ((sint16)u16LocalSync_agEngMod >= s16LocalSync_agEngMinThdMod))
      {
         CoSync_tiDetNNullBas_MP = CoSync_tiDetEsMissCgt_C;
      }
      else
      {
         u16LocalDeltaTDC = (uint16)(720 / Ext_noCylEng_SC);
         u16LocalSync_agEngMod = (uint16)( (uint32)(u8LocalSync_agEng * 6)
                                         % u16LocalDeltaTDC);
         s32LocalSync_agEngMaxThd = (sint32)( u16LocalDeltaTDC
                                            - ( CoSync_agNearTDC_C * 6));
         s32LocalSync_agEngMinThd = (sint32)(CoSync_agNearTDC_C * 6);

         if (  ((sint32)u16LocalSync_agEngMod >= s32LocalSync_agEngMaxThd)
            || ((sint32)u16LocalSync_agEngMod <= s32LocalSync_agEngMinThd))
         {
            CoSync_tiDetNNullBas_MP = CoSync_tiDetEsTDC_C;
         }
         else
         {
            CoSync_tiDetNNullBas_MP = CoSync_tiDetEsCgt_C;
         }
      }
   }
   else
   {
      u8LocalCoSync_tiDetNNullBas_MP =
         (uint8)MATHSRV_udtMAX(CoSync_tiDetEsMissCgt_C,
                               CoSync_tiDetEsTDC_C);
      CoSync_tiDetNNullBas_MP =
         (uint16)MATHSRV_udtMAX(u8LocalCoSync_tiDetNNullBas_MP,
                                CoSync_tiDetEsCgt_C);
   }

   if (CoSync_ctDetNNullBas_MP >= CoSync_tiDetNNullBas_MP)
   {
      CoSync_bDetNNullBas = 1;
   }
   else
   {
      CoSync_bDetNNullBas = 0;
   }

   if (CoSync_ctDetNNullBas_MP >= CoSync_tiDetEsCmf_C)
   {
      CoSync_bDetNNullCmf = 1;
   }
   else
   {
      CoSync_bDetNNullCmf = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidCreerInfoArretMoteur                             */
/* !Description :  Ce bloc permet de choisir l'information de régime à        */
/*                 retenir. En cas de défaillance sur le signal vilebrequin,  */
/*                 on retient l’information construite par le signal          */
/*                 vilebrequin. La détection de régime nul est retardée pour  */
/*                 bien confirmer l'arrêt du moteur.                          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  input boolean CoSync_bDetNNullDgoCk;                                      */
/*  input boolean CoSync_bDetNNullBas;                                        */
/*  input boolean CoSync_bDetNNullCmf;                                        */
/*  input boolean CoSync_bAcvDetEsIni;                                        */
/*  input boolean CoSync_bDetNNullRaw;                                        */
/*  input uint16 CoSync_tiForcNNull_C;                                        */
/*  input uint16 COSYNC_u16DetEsRawThd;                                       */
/*  input boolean COSYNC_bDetEsCmfRawCntInput;                                */
/*  input uint16 COSYNC_u16DetEsCmfRawThd;                                    */
/*  input uint16 COSYNC_u16DetEsRawCntOutput;                                 */
/*  input uint8 CoSync_tiRbm_C;                                               */
/*  input uint16 COSYNC_u16DetEsCmfRawCntOutput;                              */
/*  output uint16 COSYNC_u16DetEsRawThd;                                      */
/*  output uint16 COSYNC_u16DetEsCmfRawThd;                                   */
/*  output uint16 COSYNC_u16DetEsRawCntOutput;                                */
/*  output boolean CoSync_bDetNNullRaw;                                       */
/*  output boolean CoSync_bDetEsRaw;                                          */
/*  output uint16 COSYNC_u16DetEsCmfRawCntOutput;                             */
/*  output boolean COSYNC_bDetEsCmfRawCntInput;                               */
/*  output boolean CoSync_bDetEsCmfRaw;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidCreerInfoArretMoteur(void)
{
   boolean bLocalAcvCoSyncDftCk;
   boolean bLocalDetEsRawCntInput;
   boolean bLocalDetEsCmfRawCntInput;
   uint16  u16Local_CounterMaxThreshold;


   bLocalAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   if (bLocalAcvCoSyncDftCk != 0)
   {
      bLocalDetEsRawCntInput = CoSync_bDetNNullDgoCk;
      bLocalDetEsCmfRawCntInput = CoSync_bDetNNullDgoCk;
   }
   else
   {
      bLocalDetEsRawCntInput = CoSync_bDetNNullBas;
      bLocalDetEsCmfRawCntInput = CoSync_bDetNNullCmf;
   }

   if (CoSync_bAcvDetEsIni != 0)
   {
      COSYNC_u16DetEsRawThd = 0;
      COSYNC_u16DetEsCmfRawThd = 0;
   }
   else
   {
      /* Computing duration threshold for Stopped Engine's Detection */
      if (  (bLocalDetEsRawCntInput !=0)
         && (CoSync_bDetNNullRaw == 0))
      {
         COSYNC_u16DetEsRawThd = (uint16)MATHSRV_udtMIN(CoSync_tiForcNNull_C,
                                                        1000);
      }
      else
      {
         COSYNC_u16DetEsRawThd = (uint16)MATHSRV_udtMIN(COSYNC_u16DetEsRawThd,
                                                        1000);
      }
      /* Computing duration threshold for Stopped Engine's Delayed Detection */
      if (  (bLocalDetEsCmfRawCntInput !=0)
         && (COSYNC_bDetEsCmfRawCntInput == 0))
      {
         COSYNC_u16DetEsCmfRawThd = (uint16)MATHSRV_udtMIN(CoSync_tiForcNNull_C,
                                                           1000);
      }
      else
      {
         COSYNC_u16DetEsCmfRawThd =
            (uint16)MATHSRV_udtMIN(COSYNC_u16DetEsCmfRawThd, 1000);
      }
   }

   /* Stopped Engine's Detection */
   if (bLocalDetEsRawCntInput !=0)
   {
      if (CoSync_bDetNNullRaw == 0)
      {
         COSYNC_u16DetEsRawCntOutput = 0;
      }
      else
      {
         if (COSYNC_u16DetEsRawCntOutput > 600)
         {
            COSYNC_u16DetEsRawCntOutput = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(COSYNC_u16DetEsRawCntOutput < u16Local_CounterMaxThreshold)
      {
         COSYNC_u16DetEsRawCntOutput =
            (uint16)(COSYNC_u16DetEsRawCntOutput + CoSync_tiRbm_C);
      }
      else
      {
         COSYNC_u16DetEsRawCntOutput = 600;
      }
   }
   CoSync_bDetNNullRaw = bLocalDetEsRawCntInput;

   if (COSYNC_u16DetEsRawCntOutput <= COSYNC_u16DetEsRawThd)
   {
      CoSync_bDetEsRaw = 1;
   }
   else
   {
      CoSync_bDetEsRaw = CoSync_bDetNNullRaw;
   }

   /* Stopped Engine's Delayed Detection */
   if (bLocalDetEsCmfRawCntInput !=0)
   {
      if (COSYNC_bDetEsCmfRawCntInput == 0)
      {
         COSYNC_u16DetEsCmfRawCntOutput = 0;
      }
      else
      {
         if (COSYNC_u16DetEsCmfRawCntOutput > 600)
         {
            COSYNC_u16DetEsCmfRawCntOutput = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(COSYNC_u16DetEsCmfRawCntOutput < u16Local_CounterMaxThreshold)
      {
         COSYNC_u16DetEsCmfRawCntOutput =
            (uint16)(COSYNC_u16DetEsCmfRawCntOutput + CoSync_tiRbm_C);
      }
      else
      {
         COSYNC_u16DetEsCmfRawCntOutput = 600;
      }
   }
   COSYNC_bDetEsCmfRawCntInput = bLocalDetEsCmfRawCntInput;

   if (COSYNC_u16DetEsCmfRawCntOutput <= COSYNC_u16DetEsCmfRawThd)
   {
      CoSync_bDetEsCmfRaw = 1;
   }
   else
   {
      CoSync_bDetEsCmfRaw = COSYNC_bDetEsCmfRawCntInput;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidCalculerComptrPMHa10ms                           */
/* !Description :  Ce bloc permet de reseter la valeur du compteur de PMH à   */
/*                 chaque détection de régime nul.                            */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Sync_ctTDC;                                                   */
/*  input boolean CoSync_bDetNNullRaw;                                        */
/*  input uint8 COSYNC_u8SyncCtTDCPrev;                                       */
/*  output uint8 CoSync_ctTDCRaw;                                             */
/*  output uint8 COSYNC_u8SyncCtTDCPrev;                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidCalculerComptrPMHa10ms(void)
{
   uint8  u8LocalSync_ctTDC;
   sint16 s16LocalCoSync_ctTDCRaw;


   VEMS_vidGET(Sync_ctTDC, u8LocalSync_ctTDC);

   if (CoSync_bDetNNullRaw != 0)
   {
      CoSync_ctTDCRaw = 0;
      COSYNC_u8SyncCtTDCPrev = u8LocalSync_ctTDC;
   }
   else
   {
      s16LocalCoSync_ctTDCRaw = (sint16)( u8LocalSync_ctTDC
                                        - COSYNC_u8SyncCtTDCPrev);
      s16LocalCoSync_ctTDCRaw = (sint16)(s16LocalCoSync_ctTDCRaw % 256);

      /* The "%" operator returns the remainder and not the modulus. */
      if (s16LocalCoSync_ctTDCRaw < 0)
      {
         s16LocalCoSync_ctTDCRaw = (sint16)(s16LocalCoSync_ctTDCRaw + 256);
      }
      CoSync_ctTDCRaw = (uint8)s16LocalCoSync_ctTDCRaw;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidBouchSortiesDetecArret                           */
/* !Description :  Ce bloc permet de bouchonner les variables de la fonction «*/
/*                 Détecter et gérer l’arrêt moteur » si le calcul de la      */
/*                 fonction n’est pas activé.                                 */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_agEs;                                                    */
/*  input uint8 Sync_agEng;                                                   */
/*  input boolean Sync_bVldAgEs;                                              */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input boolean CoSync_bAcvCalcDetEs;                                       */
/*  input boolean CoSync_bDetNNullRaw;                                        */
/*  input uint8 CoSync_ctTDCRaw;                                              */
/*  input boolean CoSync_bDetEsRaw;                                           */
/*  input boolean CoSync_bDetEsCmfRaw;                                        */
/*  input boolean CoSync_bDetEsCmf;                                           */
/*  input uint16 PredEs_agMissCgt_C;                                          */
/*  input boolean CoSync_bDetEs;                                              */
/*  output boolean CoSync_bDetNNull;                                          */
/*  output boolean CoSync_bDetNNullRaw;                                       */
/*  output uint8 CoSync_ctTDC;                                                */
/*  output uint8 CoSync_ctTDCRaw;                                             */
/*  output boolean CoSync_bDetEs;                                             */
/*  output boolean CoSync_bDetEsRaw;                                          */
/*  output boolean CoSync_bDetEsCmf;                                          */
/*  output boolean CoSync_bEngSyncAccu_MP;                                    */
/*  output uint16 CoSync_agEs;                                                */
/*  output uint8 CoSync_agUncrtEs;                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidBouchSortiesDetecArret(void)
{
   boolean bLocalSync_bVldAgEs;
   boolean bLocalCoSync_bDetEs;
   boolean bLocalSync_bEngSyncAccu;
   uint8   u8LocalSync_agEs;
   uint8   u8LocalSync_agEng;
   uint16  u16LocalSync_agEs_MOD_360;
   uint16  u16LocalCoSync_agEs;
   uint16  u16LocalPredEsAgMissCgtC_MOD_360;


   VEMS_vidGET(Sync_agEs, u8LocalSync_agEs);
   VEMS_vidGET(Sync_agEng, u8LocalSync_agEng);
   VEMS_vidGET(Sync_bVldAgEs, bLocalSync_bVldAgEs);
   VEMS_vidGET(Sync_bEngSyncAccu,bLocalSync_bEngSyncAccu);

   if (CoSync_bAcvCalcDetEs != 0)
   {
      VEMS_vidSET(CoSync_bDetNNull, CoSync_bDetNNullRaw);
      VEMS_vidSET(CoSync_ctTDC, CoSync_ctTDCRaw);
      VEMS_vidSET(CoSync_bDetEs, CoSync_bDetEsRaw);
      CoSync_bDetEsCmf = CoSync_bDetEsCmfRaw;
   }
   else
   {
      VEMS_vidSET(CoSync_bDetNNull, 0);
      VEMS_vidSET(CoSync_ctTDC, 0);
      VEMS_vidSET(CoSync_bDetEs, 0);
      CoSync_bDetEsCmf = 0;
   }

   if (  (bLocalSync_bEngSyncAccu != 0)
      && (bLocalSync_bEngSyncAccu != 0))
   /* This logical operation is imposed by the specification document. */
   {
      CoSync_bEngSyncAccu_MP = 1;
   }
   else
   {
      CoSync_bEngSyncAccu_MP = 0;
   }

   if (CoSync_bAcvCalcDetEs != 0)
   {
      if (  (CoSync_bDetEsCmf != 0)
         && (bLocalSync_bVldAgEs != 0))
      {
         u16LocalCoSync_agEs = (uint16)(u8LocalSync_agEs * 3);
         u16LocalCoSync_agEs = (uint16)MATHSRV_udtMIN(u16LocalCoSync_agEs, 720);
         VEMS_vidSET(CoSync_agEs, u16LocalCoSync_agEs);

         u16LocalSync_agEs_MOD_360 = (uint16)( (uint32)(u8LocalSync_agEs * 3)
                                             % 360);
         u16LocalPredEsAgMissCgtC_MOD_360 =
            (uint16)( (uint32)( PredEs_agMissCgt_C + 9) % 360);
         if (u16LocalSync_agEs_MOD_360 == u16LocalPredEsAgMissCgtC_MOD_360)
         {
            VEMS_vidSET(CoSync_agUncrtEs, 9);
         }
         else
         {
            VEMS_vidSET(CoSync_agUncrtEs, 3);
         }
      }
      else
      {
         VEMS_vidGET(CoSync_bDetEs,bLocalCoSync_bDetEs);
         if (  (bLocalCoSync_bDetEs != 0)
            && (bLocalSync_bEngSyncAccu != 0))
         {
            u16LocalCoSync_agEs = (uint16)(u8LocalSync_agEng * 6);
            u16LocalCoSync_agEs = (uint16)MATHSRV_udtMIN(u16LocalCoSync_agEs,
                                                         720);
            VEMS_vidSET(CoSync_agEs, u16LocalCoSync_agEs);

            VEMS_vidSET(CoSync_agUncrtEs, 12);
         }
         else
         {
            VEMS_vidSET(CoSync_agEs, 0);
            VEMS_vidSET(CoSync_agUncrtEs, 45);
         }
      }
   }
   else
   {
      VEMS_vidSET(CoSync_agEs, 0);
      VEMS_vidSET(CoSync_agUncrtEs, 45);
   }
}
/*-------------------------------- end of file -------------------------------*/