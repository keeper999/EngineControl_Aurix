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
/* !File            : SYNCSTT_FCT1.C                                          */
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
/*   1 / SYNCSTT_vidOS1                                                       */
/*   2 / SYNCSTT_vidOS2                                                       */
/*   3 / SYNCSTT_vidInit                                                      */
/*   4 / SYNCSTT_vidInitOutput                                                */
/*   5 / SYNCSTT_vidBackUpAcv                                                 */
/*   6 / SYNCSTT_vidBackUpCk                                                  */
/*   7 / SYNCSTT_vidBackUpCm                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6912870 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNCSTT/SYNCSTT_FCT1.C_v          $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   04 Aug 2014 $*/
/* $Author::   wbouach                                $$Date::   04 Aug 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SYNCSTT.h"
#include "SYNCSTT_L.h"
#include "SYNCSTT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidOS1                                             */
/* !Description :  On crée 2 évènements qui permettent d’activer soit la      */
/*                 stratégie en cas de premier démarrage soit la stratégie en */
/*                 cas de redémarrage après un arrêt sans coupure du          */
/*                 calculateur et lorsque le signal AAC admission est valide. */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void SYNCSTT_vidSyncCalcStrt();                               */
/*  extf argret void SYNCSTT_vidSyncCalcRstrt();                              */
/*  input boolean CoSync_bDemMissSync;                                        */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input st62 Ext_stAgCmInAdapt;                                             */
/*  input boolean CoSync_bForcEngNotSync;                                     */
/*  input uint8 Sync_nSyncStrt_C;                                             */
/*  input uint8 Sync_nSyncRstrt_C;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidOS1(void)
{
   boolean  bLocalCoSync_bDemMissSync;
   boolean  bLocalCoSync_bForcEngNotSync;
   boolean  bLocalFRM_bInhEngSync;
   uint8    u8LocalCoSync_stSigCm2Sync;
   uint8    u8LocalExt_stAgCmInAdapt;
   uint16   u16LocalExt_nEng;


   VEMS_vidGET(CoSync_bDemMissSync, bLocalCoSync_bDemMissSync);
   VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_stAgCmInAdapt, u8LocalExt_stAgCmInAdapt);
   VEMS_vidGET(CoSync_bForcEngNotSync, bLocalCoSync_bForcEngNotSync);
   bLocalFRM_bInhEngSync = GDGAR_bGetFRM(FRM_FRM_INHENGSYNC);

   if (  (bLocalCoSync_bDemMissSync != 0)
      || (  (u8LocalCoSync_stSigCm2Sync == 1)
         && (u16LocalExt_nEng > Sync_nSyncStrt_C)
         && (u8LocalExt_stAgCmInAdapt == 0)))
   {
      if (  (bLocalCoSync_bForcEngNotSync == 0)
         && (bLocalFRM_bInhEngSync == 0))
      {
         SYNCSTT_vidSyncCalcStrt();
      }
   }
   if (  (u16LocalExt_nEng > Sync_nSyncRstrt_C)
      && (u8LocalCoSync_stSigCm2Sync == 1)
      && (u8LocalExt_stAgCmInAdapt == 1))
   {
      if (  (bLocalCoSync_bForcEngNotSync == 0)
         && (bLocalFRM_bInhEngSync == 0))
      {
         SYNCSTT_vidSyncCalcRstrt();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidOS2                                             */
/* !Description :  On crée 2 évènements qui permettent d’activer soit la      */
/*                 stratégie en cas de premier démarrage soit la stratégie en */
/*                 cas de redémarrage après un arrêt sans coupure du          */
/*                 calculateur et lorsque le signal AAC échappement est       */
/*                 valide.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void SYNCSTT_vidSyncCalcStrt();                               */
/*  extf argret void SYNCSTT_vidSyncCalcRstrt();                              */
/*  input boolean CoSync_bDemMissSync;                                        */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input st17 Ext_stAgCmExAdapt;                                             */
/*  input boolean CoSync_bForcEngNotSync;                                     */
/*  input uint8 Sync_nSyncStrt_C;                                             */
/*  input uint8 Sync_nSyncRstrt_C;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidOS2(void)
{
   boolean  bLocalCoSync_bDemMissSync;
   boolean  bLocalFRM_bInhEngSync;
   boolean  bLocalCoSync_bForcEngNotSync;
   uint8    u8LocalCoSync_stSigCm2Sync;
   uint8    u8LocalExt_stAgCmExAdapt;
   uint16   u16LocalExt_nEng;


   VEMS_vidGET(CoSync_bDemMissSync, bLocalCoSync_bDemMissSync);
   VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_stAgCmExAdapt, u8LocalExt_stAgCmExAdapt);
   VEMS_vidGET(CoSync_bForcEngNotSync, bLocalCoSync_bForcEngNotSync);
   bLocalFRM_bInhEngSync = GDGAR_bGetFRM(FRM_FRM_INHENGSYNC);
   if (  (bLocalCoSync_bDemMissSync != 0)
      || (  (u8LocalCoSync_stSigCm2Sync == 2)
         && (u16LocalExt_nEng > Sync_nSyncStrt_C)
         && (u8LocalExt_stAgCmExAdapt == 0)))
   {
      if (  (bLocalCoSync_bForcEngNotSync == 0)
         && (bLocalFRM_bInhEngSync == 0))
      {
         SYNCSTT_vidSyncCalcStrt();
      }
   }
   if (  (u16LocalExt_nEng > Sync_nSyncRstrt_C)
      && (u8LocalCoSync_stSigCm2Sync == 2)
      && (u8LocalExt_stAgCmExAdapt == 1))
   {
      if (  (bLocalCoSync_bForcEngNotSync == 0)
         && (bLocalFRM_bInhEngSync == 0))
      {
         SYNCSTT_vidSyncCalcRstrt();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidInit                                            */
/* !Description :  fonction d'initialisation des variables au reset du        */
/*                 calculateur                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bDirRotCk;                                             */
/*  output uint8 Ext_ctEdgeCk;                                                */
/*  output uint32 Ext_tiCgt;                                                  */
/*  output uint32 BufNEs_tiCgtLst;                                            */
/*  output uint8 Sync_agEng;                                                  */
/*  output uint8 Sync_agEsAfter;                                              */
/*  output boolean Sync_bEngSyncNotAccu;                                      */
/*  output boolean Sync_bDetEs;                                               */
/*  output boolean Sync_bDgoCkSig;                                            */
/*  output boolean Sync_bDgoCmSig;                                            */
/*  output uint8 Sync_agEs;                                                   */
/*  output boolean Sync_bVldAgEs;                                             */
/*  output boolean Sync_bEngSyncAccu;                                         */
/*  output boolean Sync_bDetLTo;                                              */
/*  output boolean Sync_bDetLTooth;                                           */
/*  output boolean Ext_bDetCgtMiss;                                           */
/*  output uint8 Sync_ctTDC;                                                  */
/*  output uint8 Sync_ctTeeth;                                                */
/*  output boolean Sync_bCalcOk;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidInit(void)
{

   VEMS_vidSET(Ext_bDirRotCk, 0);
   VEMS_vidSET(Ext_ctEdgeCk, 0);
   VEMS_vidSET(Ext_tiCgt, 500000);
   VEMS_vidSET(BufNEs_tiCgtLst, 500000);
   VEMS_vidSET(Sync_agEng, 0);
   VEMS_vidSET(Sync_agEsAfter, 0);
   VEMS_vidSET(Sync_bEngSyncNotAccu, 0);
   VEMS_vidSET(Sync_bDetEs, 0);
   VEMS_vidSET(Sync_bDgoCkSig, 0);
   VEMS_vidSET(Sync_bDgoCmSig, 0);
   VEMS_vidSET(Sync_agEs, 0);
   VEMS_vidSET(Sync_bVldAgEs, 0);
   VEMS_vidSET(Sync_bEngSyncAccu, 0);
   Sync_bDetLTo = 0;
   Sync_bDetLTooth = 0;
   VEMS_vidSET(Ext_bDetCgtMiss, 0);
   VEMS_vidSET(Sync_ctTDC, 0);
   VEMS_vidSET(Sync_ctTeeth, 0);
   Sync_bCalcOk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidInitOutput                                      */
/* !Description :  focntion d'initialisation des varaibles produites          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SYNCSTT_bAcqStPosAngMoteur_Prev;                           */
/*  output boolean SYNCSTT_bEngSyncAccu_Prev;                                 */
/*  output boolean SYNCSTT_bEngSyncNotAccu_Prev;                              */
/*  output uint8 Sync_ctCmExEdgeRstrtOk;                                      */
/*  output uint8 Sync_ctCmInEdgeRstrtOk;                                      */
/*  output uint8 Sync_ctCmExEdgeStrtOk;                                       */
/*  output uint8 Sync_ctCmInEdgeStrtOk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidInitOutput(void)
{
   SYNCSTT_bAcqStPosAngMoteur_Prev = 0;
   SYNCSTT_bEngSyncAccu_Prev = 0;
   SYNCSTT_bEngSyncNotAccu_Prev = 0;
   Sync_ctCmExEdgeRstrtOk = 0;
   Sync_ctCmInEdgeRstrtOk = 0;
   Sync_ctCmExEdgeStrtOk = 0;
   Sync_ctCmInEdgeStrtOk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidBackUpAcv                                       */
/* !Description :  Il permet de générer les booléens d’activation des back-up */
/*                 mode vilebrequin et arbre à cames.                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_034.01                                     */
/*                 VEMS_E_10_06977_035.01                                     */
/*                 VEMS_E_10_06977_036.01                                     */
/*                 VEMS_E_10_06977_037.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void SYNCSTT_vidBackUpCk();                                   */
/*  extf argret void SYNCSTT_vidBackUpCm();                                   */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean Sync_bDgoCkSig_C;                                           */
/*  input boolean Sync_bDgoCmSig_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidBackUpAcv(void)
{
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalFRM_bAcvCoSyncDftCk;
   uint8   u8LocalCoSync_stSigCm2Sync;


   VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);
   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   bLocalFRM_bAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);

   if (  (u8LocalCoSync_stSigCm2Sync !=0)
      && (Sync_bDgoCkSig_C != 0))
   {
      SYNCSTT_vidBackUpCk();
   }

   if (  (Sync_bDgoCmSig_C != 0)
      && (bLocalFRM_bAcvCoSyncDftCk == 0)
      && (bLocalSync_bDgoCkSig == 0))
   {
      SYNCSTT_vidBackUpCm();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidBackUpCk                                        */
/* !Description :  Active  la demande de passage en mode de back-up           */
/*                 vilebrequin.                                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_038.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bDgoCkSig;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidBackUpCk(void)
{
   boolean bLocalFRM_bAcvCoSyncDftCk;
   boolean bLocalSync_bDgoCkSig;


   bLocalFRM_bAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   if (bLocalFRM_bAcvCoSyncDftCk != 0)
   {
      bLocalSync_bDgoCkSig = 1;
   }
   else
   {
      bLocalSync_bDgoCkSig = 0;
   }
   VEMS_vidSET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCSTT_vidBackUpCm                                        */
/* !Description :  Active  la demande de passage en mode de back-up du signal */
/*                 arbre à cames.                                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_10_06977_039.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*  output boolean Sync_bDgoCmSig;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCSTT_vidBackUpCm(void)
{
   boolean bLocalSync_bDgoCmSig;
   uint8   u8LocalCoSync_stSigCm2Sync;


   VEMS_vidGET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);

   if (u8LocalCoSync_stSigCm2Sync == 0)
   {
      bLocalSync_bDgoCmSig = 1;
   }
   else
   {
      bLocalSync_bDgoCmSig = 0;
   }
   VEMS_vidSET(Sync_bDgoCmSig, bLocalSync_bDgoCmSig);
}

/*------------------------------ End of file ---------------------------------*/