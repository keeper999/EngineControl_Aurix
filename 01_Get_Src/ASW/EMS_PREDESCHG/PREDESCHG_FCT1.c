/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PREDESCHG                                               */
/* !Description     : PREDESCHG Component.                                    */
/*                                                                            */
/* !Module          : PREDESCHG                                               */
/* !Description     : Sélection de variables durant l’arrêt moteur            */
/*                    (PredEsChg).                                            */
/*                                                                            */
/* !File            : PREDESCHG_FCT1.C                                        */
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
/*   1 / PREDESCHG_vidInitOutput                                              */
/*   2 / PREDESCHG_vidPredEsChgDraft                                          */
/*   3 / PREDESCHG_vidInhibCalcRegHautReg                                     */
/*   4 / PREDESCHG_vidEffectCalcRegInsta                                      */
/*   5 / PREDESCHG_vidEffectSwitchCasVie                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 02549 / 02                                        */
/* !OtherRefs   : 01460_10_00599 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/PREDESCHG/PREDESCHG_FC$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   29 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   29 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "PREDESCHG.h"
#include "PREDESCHG_L.h"
#include "PREDESCHG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDESCHG_vidInitOutput                                    */
/* !Description :  Initialisation des sorties et des variables internes.      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 PredEs_agEs;                                                */
/*  output uint8 PredEs_agUncrtEs;                                            */
/*  output boolean PredEs_bDetSlowN;                                          */
/*  output boolean PredEs_bVldAgEs;                                           */
/*  output boolean PredEs_bVldFastN;                                          */
/*  output sint16 PredEs_nFast;                                               */
/*  output boolean PredEsChg_bAcvCalcPredEs;                                  */
/*  output boolean PredEsChg_bCalcPredEs;                                     */
/*  output boolean PredEsChg_bDirRotCk_MP;                                    */
/*  output boolean PredEsChg_bVldFastN;                                       */
/*  output uint8 PredEsChg_ctEdgeCk_MP;                                       */
/*  output sint16 PredEsChg_nFast;                                            */
/*  output uint32 PredEsChg_tiCgtLst_MP;                                      */
/*  output uint32 PredEsChg_tiCgt_MP;                                         */
/*  output uint8 PREDESCHG_u8ExtctEdgeCkPrev;                                 */
/*  output boolean PREDESCHG_bVld;                                            */
/*  output uint8 PREDESCHG_u8ExtctEdgeCk;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDESCHG_vidInitOutput(void)
{
   VEMS_vidSET(PredEs_agEs, 0);
   VEMS_vidSET(PredEs_agUncrtEs, 0);
   VEMS_vidSET(PredEs_bDetSlowN, 0);
   VEMS_vidSET(PredEs_bVldAgEs, 0);
   VEMS_vidSET(PredEs_bVldFastN, 0);
   VEMS_vidSET(PredEs_nFast, 0);
   PredEsChg_bAcvCalcPredEs = 0;
   PredEsChg_bCalcPredEs = 0;
   PredEsChg_bDirRotCk_MP = 0;
   PredEsChg_bVldFastN = 0;
   PredEsChg_ctEdgeCk_MP = 0;
   PredEsChg_nFast = 0;
   PredEsChg_tiCgtLst_MP = 500000;
   PredEsChg_tiCgt_MP = 500000;
   PREDESCHG_u8ExtctEdgeCkPrev = 0;
   PREDESCHG_bVld = 0;
   PREDESCHG_u8ExtctEdgeCk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDESCHG_vidPredEsChgDraft                                */
/* !Description :  Cette fonction permet d’effectuer la sélection de          */
/*                 l’information dans les différents cas de  vie (Moteur en   */
/*                 phase de coupure moteur, moteur à l’arrêt).                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02549_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDESCHG_vidInhibCalcRegHautReg();                      */
/*  extf argret void PREDESCHG_vidEffectCalcRegInsta();                       */
/*  extf argret void PREDESCHG_vidEffectSwitchCasVie();                       */
/*  input boolean PredEsChg_bCalcPredEs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDESCHG_vidPredEsChgDraft(void)
{
   PREDESCHG_vidInhibCalcRegHautReg();
   if (PredEsChg_bCalcPredEs != 0)
   {
      PREDESCHG_vidEffectCalcRegInsta();
   }

   PREDESCHG_vidEffectSwitchCasVie();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDESCHG_vidInhibCalcRegHautReg                           */
/* !Description :  Ce bloc permet d’activer ou pas le calcul du régime rapide.*/
/*                 Ce calcul est effectué en  dessous d’un seuil de régime    */
/*                 calibrable. Cela permet d’optimiser la fonction en ne      */
/*                 l’activant pas dans les phases de vie non utiles (à haut   */
/*                 régime).                                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02549_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 PredEsChg_nThdAcvFct_C;                                       */
/*  input boolean PredEsChg_bCalcPredEs;                                      */
/*  output boolean PredEsChg_bAcvCalcPredEs;                                  */
/*  output boolean PredEsChg_bCalcPredEs;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDESCHG_vidInhibCalcRegHautReg(void)
{
   boolean bLocalPredEsChg_bCalcPredEs;
   uint16  u16LocalExt_nEng;
   uint16  u16Local;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16Local = (uint16)(PredEsChg_nThdAcvFct_C * 10);
   if (u16LocalExt_nEng <= u16Local)
   {
      bLocalPredEsChg_bCalcPredEs = 1;
   }
   else
   {
      bLocalPredEsChg_bCalcPredEs = 0;
   }

   if (  (bLocalPredEsChg_bCalcPredEs !=0)
      && (PredEsChg_bCalcPredEs == 0))
   {
      PredEsChg_bAcvCalcPredEs = 1;
   }
   else
   {
      PredEsChg_bAcvCalcPredEs = 0;
   }
   PredEsChg_bCalcPredEs = bLocalPredEsChg_bCalcPredEs;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDESCHG_vidEffectCalcRegInsta                            */
/* !Description :  Ce bloc permet de calculer le régime instantané.           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02549_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint32 Ext_tiCgt;                                                   */
/*  input uint32 BufNEs_tiCgtLst;                                             */
/*  input boolean Ext_bDirRotCk;                                              */
/*  input uint8 Ext_ctEdgeCk;                                                 */
/*  input uint8 PREDESCHG_u8ExtctEdgeCkPrev;                                  */
/*  input boolean PredEsChg_bDgoNFast_C;                                      */
/*  input boolean PredEsChg_bAcvCalcPredEs;                                   */
/*  input uint8 PREDESCHG_u8ExtctEdgeCk;                                      */
/*  input boolean PREDESCHG_bVld;                                             */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  output uint32 PredEsChg_tiCgt_MP;                                         */
/*  output uint32 PredEsChg_tiCgtLst_MP;                                      */
/*  output boolean PredEsChg_bDirRotCk_MP;                                    */
/*  output sint16 PredEsChg_nFast;                                            */
/*  output uint8 PredEsChg_ctEdgeCk_MP;                                       */
/*  output uint8 PREDESCHG_u8ExtctEdgeCk;                                     */
/*  output boolean PREDESCHG_bVld;                                            */
/*  output boolean PredEsChg_bVldFastN;                                       */
/*  output uint8 PREDESCHG_u8ExtctEdgeCkPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDESCHG_vidEffectCalcRegInsta(void)
{
   boolean bLocalExt_bDirRotCk;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalFRM_bAcvCoSyncDftCk;
   uint8   u8LocalExt_ctEdgeCk;
   uint8   u8LocalPredEsChg_nFast;
   uint8   u8LocalMOD;
   sint16  s16Local;
   sint16  s16LocalPredEsChg_nFast;
   uint32  u32LocalMin;
   uint32  u32LocalMax;
   uint32  u32LocalExt_tiCgt;
   uint32  u32LocalBufNEs_tiCgtLst;


   VEMS_vidGET(Ext_tiCgt, u32LocalExt_tiCgt);
   VEMS_vidGET(BufNEs_tiCgtLst, u32LocalBufNEs_tiCgtLst);
   PredEsChg_tiCgt_MP = MATHSRV_udtMIN(u32LocalExt_tiCgt, 500000);
   PredEsChg_tiCgtLst_MP = MATHSRV_udtMIN(u32LocalBufNEs_tiCgtLst, 500000);
   u32LocalMin = MATHSRV_udtMIN(u32LocalExt_tiCgt, u32LocalBufNEs_tiCgtLst);
   u32LocalMax = MATHSRV_udtMAX(u32LocalMin, 1000);
   u32LocalMax = MATHSRV_udtMIN(u32LocalMax, 500000);

   VEMS_vidGET(Ext_bDirRotCk, bLocalExt_bDirRotCk);
   if (bLocalExt_bDirRotCk != 0)
   {
      PredEsChg_bDirRotCk_MP = 1;
      s16LocalPredEsChg_nFast = (sint16)(1000000 / u32LocalMax);
   }
   else
   {
      PredEsChg_bDirRotCk_MP = 0;
      s16LocalPredEsChg_nFast = (sint16)(-1000000 / (sint32)u32LocalMax);

   }

   VEMS_vidGET(Ext_ctEdgeCk, u8LocalExt_ctEdgeCk);
   if (u8LocalExt_ctEdgeCk == PREDESCHG_u8ExtctEdgeCkPrev)
   {
      u8LocalPredEsChg_nFast = 0;
   }
   else
   {
      u8LocalPredEsChg_nFast = 200;
   }

   if (PredEsChg_bDgoNFast_C != 0)
   {
      PredEsChg_nFast = (sint16)u8LocalPredEsChg_nFast;
   }
   else
   {
      PredEsChg_nFast = (sint16)MATHSRV_udtMAX(s16LocalPredEsChg_nFast, -500);
   }
   PredEsChg_ctEdgeCk_MP = u8LocalExt_ctEdgeCk;

   if (PredEsChg_bAcvCalcPredEs != 0)
   {
      PREDESCHG_u8ExtctEdgeCk = u8LocalExt_ctEdgeCk;
   }
   s16Local = (sint16)(u8LocalExt_ctEdgeCk - PREDESCHG_u8ExtctEdgeCk);
   if (s16Local < 0)
   {
      u8LocalMOD = (uint8)(s16Local + 256);
   }
   else
   {
      u8LocalMOD = (uint8)(s16Local);
   }
   u8LocalMOD = (uint8)(u8LocalMOD % 256);
   if (  (PredEsChg_bAcvCalcPredEs == 0)
      && (  (u8LocalMOD >= 2)
         || (PREDESCHG_bVld != 0)))
   {
      PREDESCHG_bVld = 1;
   }
   else
   {
      PREDESCHG_bVld = 0;
   }

   bLocalFRM_bAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   if (  (bLocalFRM_bAcvCoSyncDftCk == 0)
      && (bLocalSync_bDgoCkSig == 0)
      && (PREDESCHG_bVld != 0))
   {
      PredEsChg_bVldFastN = 1;
   }
   else
   {
      PredEsChg_bVldFastN = 0;
   }
   PREDESCHG_u8ExtctEdgeCkPrev = u8LocalExt_ctEdgeCk;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDESCHG_vidEffectSwitchCasVie                            */
/* !Description :  Ce bloc permet de donner une valeur définie aux variables  */
/*                 régime instantané, validité de la variable de régime       */
/*                 instantané, angle d’arrêt moteur et son incertitude et     */
/*                 validité des variables d’angle d’arrêt moteur selon les    */
/*                 informations disponibles.                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoSync_bDetNNull;                                           */
/*  input boolean PredEs_bDetSlowNPred;                                       */
/*  input boolean PredEs_bVldFastNPred;                                       */
/*  input sint16 PredEs_nFastPred;                                            */
/*  input boolean PredEsChg_bCalcPredEs;                                      */
/*  input boolean PredEsChg_bVldFastN;                                        */
/*  input sint16 PredEsChg_nFast;                                             */
/*  input boolean CoSync_bDetEs;                                              */
/*  input uint16 CoSync_agEs;                                                 */
/*  input uint8 CoSync_agUncrtEs;                                             */
/*  input boolean PredEs_bVldAgEsPred;                                        */
/*  input uint16 PredEs_agEsPred;                                             */
/*  input uint8 PredEs_agUncrtEsPred;                                         */
/*  output boolean PredEs_bDetSlowN;                                          */
/*  output sint16 PredEs_nFast;                                               */
/*  output boolean PredEs_bVldFastN;                                          */
/*  output uint16 PredEs_agEs;                                                */
/*  output uint8 PredEs_agUncrtEs;                                            */
/*  output boolean PredEs_bVldAgEs;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDESCHG_vidEffectSwitchCasVie(void)
{
   boolean bLocalCoSync_bDetNNull;
   boolean bLocalPredEs_bDetSlowNPred;
   boolean bLocalPredEs_bDetSlowN;
   boolean bLocalPredEs_bVldFastNPred;
   boolean bLocalPredEs_bVldFastN;
   boolean bLocalCoSync_bDetEs;
   boolean bLocalPredEs_bVldAgEsPred;
   boolean bLocalPredEs_bVldAgEs;
   uint8   u8LocalPredEs_agUncrtEsPred;
   uint8   u8LocalCoSync_agUncrtEs;
   uint8   u8LocalPredEs_agUncrtEs;
   uint16  u16LocalCoSync_agEs;
   uint16  u16LocalPredEs_agEsPred;
   uint16  u16LocalPredEs_agEs;
   sint16  s16LocalPredEs_nFastPred;
   sint16  s16LocalPredEs_nFast;


   VEMS_vidGET(CoSync_bDetNNull, bLocalCoSync_bDetNNull);
   VEMS_vidGET(PredEs_bDetSlowNPred, bLocalPredEs_bDetSlowNPred);

   if (  (bLocalCoSync_bDetNNull != 0)
      || (bLocalPredEs_bDetSlowNPred != 0))
   {
      bLocalPredEs_bDetSlowN = 1;
   }
   else
   {
      bLocalPredEs_bDetSlowN = 0;
   }
   VEMS_vidSET(PredEs_bDetSlowN, bLocalPredEs_bDetSlowN);

   VEMS_vidGET(PredEs_bVldFastNPred, bLocalPredEs_bVldFastNPred);
   VEMS_vidGET(PredEs_nFastPred, s16LocalPredEs_nFastPred);
   if (bLocalCoSync_bDetNNull != 0)
   {
      s16LocalPredEs_nFast = 0;
   }
   else
   {
      if (bLocalPredEs_bVldFastNPred != 0)
      {
         s16LocalPredEs_nFast =
            (sint16)MATHSRV_udtCLAMP(s16LocalPredEs_nFastPred, -500, 1000);
      }
      else
      {
         if (  (PredEsChg_bCalcPredEs != 0)
            && (PredEsChg_bVldFastN != 0))
         {
            s16LocalPredEs_nFast =
               (sint16)MATHSRV_udtCLAMP(PredEsChg_nFast, -500, 1000);
         }
         else
         {
            s16LocalPredEs_nFast = 0;
         }
      }
   }
   VEMS_vidSET(PredEs_nFast, s16LocalPredEs_nFast);

   if (  (bLocalPredEs_bVldFastNPred != 0)
      || (  (PredEsChg_bCalcPredEs != 0)
         && (PredEsChg_bVldFastN != 0))
      || (bLocalCoSync_bDetNNull != 0))
   {
      bLocalPredEs_bVldFastN = 1;
   }
   else
   {
      bLocalPredEs_bVldFastN = 0;
   }
   VEMS_vidSET(PredEs_bVldFastN, bLocalPredEs_bVldFastN);

   VEMS_vidGET(CoSync_bDetEs, bLocalCoSync_bDetEs);
   VEMS_vidGET(CoSync_agEs, u16LocalCoSync_agEs);
   VEMS_vidGET(CoSync_agUncrtEs, u8LocalCoSync_agUncrtEs);
   VEMS_vidGET(PredEs_bVldAgEsPred, bLocalPredEs_bVldAgEsPred);
   VEMS_vidGET(PredEs_agEsPred, u16LocalPredEs_agEsPred);
   VEMS_vidGET(PredEs_agUncrtEsPred, u8LocalPredEs_agUncrtEsPred);
   if (bLocalCoSync_bDetEs != 0)
   {
      u16LocalPredEs_agEs = (uint16)MATHSRV_udtMIN(u16LocalCoSync_agEs, 720);
      u8LocalPredEs_agUncrtEs =
         (uint8)MATHSRV_udtMIN(u8LocalCoSync_agUncrtEs, 90);
   }
   else
   {
      if (bLocalPredEs_bVldAgEsPred != 0)
      {
         u16LocalPredEs_agEs =
            (uint16)MATHSRV_udtMIN(u16LocalPredEs_agEsPred, 720);
         u8LocalPredEs_agUncrtEs =
            (uint8)MATHSRV_udtMIN(u8LocalPredEs_agUncrtEsPred, 90);
      }
      else
      {
         u16LocalPredEs_agEs = 0;
         u8LocalPredEs_agUncrtEs = 45;
      }
   }
   VEMS_vidSET(PredEs_agEs, u16LocalPredEs_agEs);
   VEMS_vidSET(PredEs_agUncrtEs, u8LocalPredEs_agUncrtEs);

   if (  (bLocalPredEs_bVldAgEsPred != 0)
      || (  (bLocalCoSync_bDetEs != 0)
         && (u8LocalCoSync_agUncrtEs <= 24)))
   {
      bLocalPredEs_bVldAgEs = 1;
   }
   else
   {
      bLocalPredEs_bVldAgEs = 0;
   }
   VEMS_vidSET(PredEs_bVldAgEs, bLocalPredEs_bVldAgEs);
}
/************************************ end of file *****************************/