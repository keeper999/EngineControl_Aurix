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
/* !File            : COSYNC_FCT1.c                                           */
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
/*   1 / COSYNC_vidInitOutput                                                 */
/*   2 / COSYNC_vidSuperviseurFctSynchro                                      */
/*   3 / COSYNC_vidEvalSignalAACAUtiliser                                     */
/*   4 / COSYNC_vidActvCalcRisqGrippgeVil                                     */
/*   5 / COSYNC_vidPrevenirRisqGrippgeVil                                     */
/*   6 / COSYNC_vidEvalAbsnceSignVilEtAAC                                     */
/*   7 / COSYNC_vidEvalDefailSignAACEtVil                                     */
/*   8 / COSYNC_vidConnaitreEtatMoteur                                        */
/*   9 / COSYNC_vidCnfrmValidSignAACOuVil                                     */
/*   10 / COSYNC_vidGenererSortiesFonction                                    */
/*                                                                            */
/* !Reference   : V02 NT 10 02290 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2284 / 02                                       */
/* !OtherRefs   : VEMS V02 ECU#048141                                         */
/* !OtherRefs   : VEMS V02 ECU#048312                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COSYNC/COSYNC_FCT1.c_v$*/
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
#include "SWFAIL.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidInitOutput                                       */
/* !Description :  Cette fonction initialise les sorties et autres variables  */
/*                 intermédiaires du module.                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 CoSync_agEs;                                                */
/*  output uint8 CoSync_agUncrtEs;                                            */
/*  output boolean CoSync_bDemMissSync;                                       */
/*  output boolean CoSync_bDetEs;                                             */
/*  output boolean CoSync_bDetNNull;                                          */
/*  output boolean CoSync_bForcEngNotSync;                                    */
/*  output boolean CoSync_bStuckEngStaAcv;                                    */
/*  output uint8 CoSync_ctTDC;                                                */
/*  output uint8 CoSync_stSigCm2Sync;                                         */
/*  output uint8 CoSync_ctEdgeCk_MP;                                          */
/*  output uint8 CoSync_ctEdgeCmIn_MP;                                        */
/*  output uint8 CoSync_ctEdgeCmEx_MP;                                        */
/*  output uint8 COSYNC_u8ExtCtEdgeCkPrev;                                    */
/*  output uint8 COSYNC_u8SyncCtTDCPrev;                                      */
/*  output uint8 COSYNC_u8ctEdgeCmInEx;                                       */
/*  output boolean CoSync_bAcvCalcDgoPosEs;                                   */
/*  output boolean CoSync_bAcvCalcDetEs;                                      */
/*  output boolean CoSync_bAcvCalcStuckEng;                                   */
/*  output boolean CoSync_bAcvElSys;                                          */
/*  output uint16 COSYNC_u16DetEsRawThd;                                      */
/*  output uint16 COSYNC_u16DetEsCmfRawThd;                                   */
/*  output boolean COSYNC_bDetCmInElSys;                                      */
/*  output boolean COSYNC_bDetCmExElSys;                                      */
/*  output boolean CoSync_bDetNNullRaw;                                       */
/*  output boolean COSYNC_bDetNNullBasCntInput;                               */
/*  output boolean COSYNC_bDetNNullDgoCkCntInput;                             */
/*  output boolean COSYNC_bCfmVldSigCmCntInput;                               */
/*  output boolean COSYNC_bCfmVldSigCkCntInput;                               */
/*  output boolean COSYNC_bMissSigAACExCntInput;                              */
/*  output boolean COSYNC_bMissSigAACInCntInput;                              */
/*  output boolean COSYNC_bMissSigCkCntInput;                                 */
/*  output boolean COSYNC_bDetEsCmfRawCntInput;                               */
/*  output uint16 CoSync_ctDetNNullBas_MP;                                    */
/*  output uint16 CoSync_ctDetNNullDgoCk_MP;                                  */
/*  output uint16 CoSync_ctCfmVldSigCm_MP;                                    */
/*  output uint16 CoSync_ctCfmVldSigCk_MP;                                    */
/*  output uint16 CoSync_ctMissSigCmEx_MP;                                    */
/*  output uint16 CoSync_ctMissSigCmIn_MP;                                    */
/*  output uint16 CoSync_ctMissSigCk_MP;                                      */
/*  output uint16 COSYNC_u16DetEsRawCntOutput;                                */
/*  output uint16 COSYNC_u16DetEsCmfRawCntOutput;                             */
/*  output uint8 CoSync_stCoSync;                                             */
/*  output uint8 COSYNC_u8CoSyncStCoSyncPrev;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidInitOutput(void)
{
   /* Outputs' initialization */
   VEMS_vidSET(CoSync_agEs, 0);
   VEMS_vidSET(CoSync_agUncrtEs, 0);
   VEMS_vidSET(CoSync_bDemMissSync, 0);
   VEMS_vidSET(CoSync_bDetEs, 0);
   VEMS_vidSET(CoSync_bDetNNull, 0);
   VEMS_vidSET(CoSync_bForcEngNotSync, 0);
   VEMS_vidSET(CoSync_bStuckEngStaAcv, 0);
   VEMS_vidSET(CoSync_ctTDC, 0);
   VEMS_vidSET(CoSync_stSigCm2Sync, 0);

   /* Internal variables' initialization */
   CoSync_ctEdgeCk_MP = 0;
   CoSync_ctEdgeCmIn_MP = 0;
   CoSync_ctEdgeCmEx_MP = 0;
   COSYNC_u8ExtCtEdgeCkPrev = 0;
   COSYNC_u8SyncCtTDCPrev = 0;
   COSYNC_u8ctEdgeCmInEx = 0;
   CoSync_bAcvCalcDgoPosEs = 0;
   CoSync_bAcvCalcDetEs = 0;
   CoSync_bAcvCalcStuckEng = 0;
   CoSync_bAcvElSys = 0;
   COSYNC_u16DetEsRawThd = 0;
   COSYNC_u16DetEsCmfRawThd = 0;
   COSYNC_bDetCmInElSys = 0;
   COSYNC_bDetCmExElSys = 0;

   /* Counters' inputs' initialization */
   CoSync_bDetNNullRaw = 0;
   COSYNC_bDetNNullBasCntInput = 0;
   COSYNC_bDetNNullDgoCkCntInput = 0;
   COSYNC_bCfmVldSigCmCntInput = 0;
   COSYNC_bCfmVldSigCkCntInput = 0;
   COSYNC_bMissSigAACExCntInput = 0;
   COSYNC_bMissSigAACInCntInput = 0;
   COSYNC_bMissSigCkCntInput = 0;
   COSYNC_bDetEsCmfRawCntInput = 0;

   /* Counters' outputs' Initialization */
   CoSync_ctDetNNullBas_MP = 0;
   CoSync_ctDetNNullDgoCk_MP = 0;
   CoSync_ctCfmVldSigCm_MP = 0;
   CoSync_ctCfmVldSigCk_MP = 0;
   CoSync_ctMissSigCmEx_MP = 0;
   CoSync_ctMissSigCmIn_MP = 0;
   CoSync_ctMissSigCk_MP = 0;
   COSYNC_u16DetEsRawCntOutput = 0;
   COSYNC_u16DetEsCmfRawCntOutput = 0;

   /* State machine's Initialization */
   CoSync_stCoSync = 0;
   COSYNC_u8CoSyncStCoSyncPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidSuperviseurFctSynchro                            */
/* !Description :  Cette fonction crée plusieurs informations : 1. Le signal  */
/*                 AAC à utiliser pour la synchronisation, 2. Le risque de    */
/*                 blocage vilebrequin, 3. La détection d’arrêt moteur et la  */
/*                 position associées, 4. Une demande de recommencement du    */
/*                 cycle de synchronisation.                                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_001.01                                     */
/*                 VEMS_R_10_02290_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COSYNC_vidEvalSignalAACAUtiliser();                      */
/*  extf argret void COSYNC_vidActvCalcRisqGrippgeVil();                      */
/*  extf argret void COSYNC_vidPrevenirRisqGrippgeVil();                      */
/*  extf argret void COSYNC_vidBouchSortiesGrippgeVil();                      */
/*  extf argret void COSYNC_vidActvCalcDetectionArret();                      */
/*  extf argret void COSYNC_vidDetecterGererArretMotr();                      */
/*  extf argret void COSYNC_vidBouchSortiesDetecArret();                      */
/*  extf argret void COSYNC_vidActvCalcDiagPosArret();                        */
/*  extf argret void COSYNC_vidInfrmRsqClcErrPosArret();                      */
/*  extf argret void COSYNC_vidBouchSortiesDgPosArret();                      */
/*  input boolean CoSync_bAcvCalcStuckEng;                                    */
/*  input boolean CoSync_bAcvCalcDetEs;                                       */
/*  input boolean CoSync_bAcvCalcDgoPosEs;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidSuperviseurFctSynchro(void)
{
   COSYNC_vidEvalSignalAACAUtiliser();

   COSYNC_vidActvCalcRisqGrippgeVil();
   if(CoSync_bAcvCalcStuckEng != 0)
   {
      COSYNC_vidPrevenirRisqGrippgeVil();
   }
   COSYNC_vidBouchSortiesGrippgeVil();

   COSYNC_vidActvCalcDetectionArret();
   if(CoSync_bAcvCalcDetEs != 0)
   {
      COSYNC_vidDetecterGererArretMotr();
   }
   COSYNC_vidBouchSortiesDetecArret();

   COSYNC_vidActvCalcDiagPosArret();
   if(CoSync_bAcvCalcDgoPosEs != 0)
   {
      COSYNC_vidInfrmRsqClcErrPosArret();
   }
   COSYNC_vidBouchSortiesDgPosArret();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidEvalSignalAACAUtiliser                           */
/* !Description :  Ce bloc définit quel signal AAC est à utiliser par la      */
/*                 fonction de synchronisation fournisseur. La méthode est de */
/*                 retenir le signal existant et valide. Pour des applications*/
/*                 possédant 2 signaux AAC valides, une priorité est définie  */
/*                 sur l’un des signaux.                                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoSync_bPresSigCmIn_C;                                      */
/*  input boolean CoSync_bPresSigCmEx_C;                                      */
/*  input uint8 CoSync_noSigCm2SyncBas_C;                                     */
/*  output uint8 CoSync_stSigCm2Sync;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidEvalSignalAACAUtiliser(void)
{
   boolean bLocalAcvCoSyncDftCmIn;
   boolean bLocalAcvCoSyncDftCmEx;
   uint8   u8LocalCoSync_stSigCm2Sync;


   bLocalAcvCoSyncDftCmIn = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCMIN);
   bLocalAcvCoSyncDftCmEx = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCMEX);

   if (  (CoSync_bPresSigCmIn_C == 0)
      || (bLocalAcvCoSyncDftCmIn != 0))
   {
      u8LocalCoSync_stSigCm2Sync = 2;
   }
   else
   {
      u8LocalCoSync_stSigCm2Sync = 0;
   }

   if (  (CoSync_bPresSigCmEx_C == 0)
      || (bLocalAcvCoSyncDftCmEx != 0))
   {
      u8LocalCoSync_stSigCm2Sync = (uint8)(u8LocalCoSync_stSigCm2Sync + 1);
   }

   switch(u8LocalCoSync_stSigCm2Sync)
   {
      case 0:
         u8LocalCoSync_stSigCm2Sync =
            (uint8)MATHSRV_udtMIN(CoSync_noSigCm2SyncBas_C, 2);
         VEMS_vidSET(CoSync_stSigCm2Sync, u8LocalCoSync_stSigCm2Sync);
         break;
      case 1:
         VEMS_vidSET(CoSync_stSigCm2Sync, 1);
         break;
      case 2:
         VEMS_vidSET(CoSync_stSigCm2Sync, 2);
         break;
      case 3:
         VEMS_vidSET(CoSync_stSigCm2Sync, 0);
         break;
      default:
      /* This default label is dead code (needed to conform to the MISRA-C). */
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidActvCalcRisqGrippgeVil                           */
/* !Description :  Ce bloc fournit 2 informations : 1. L’information de       */
/*                 machine électrique active, 2. L’information d’activation de*/
/*                 la machine électrique. Il permet également d’activer le    */
/*                 calcul de prévention du risque de moteur bloqué.           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input uint8 CoEmCkg_stStrtRstrtFbCmd;                                     */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean CoSync_bAcvCalcStuckEng;                                    */
/*  input uint16 CoSync_nAcvStuckEng_C;                                       */
/*  input boolean CoSync_bAcvStuckEng_C;                                      */
/*  input boolean CoSync_bAcvElSys;                                           */
/*  output boolean CoSync_bAcvCalcStuckEng;                                   */
/*  output boolean CoSync_bAcvStuckEngIni;                                    */
/*  output boolean CoSync_bAcvElSys;                                          */
/*  output boolean CoSync_bStrtAcvElSys;                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidActvCalcRisqGrippgeVil(void)
{
   boolean bLocalAcvCoSyncDftCk;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocal_bAcvCalcStuckEngPrev;
   boolean bLocal_bAcvElSysPrev;
   uint8   u8LocalCoEmCkg_stStrtRstrtFbCmd;
   uint16  u16LocalExt_nEng;
   uint32  u32LocalCoSync_nAcvStuckEng_C;


   bLocalAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(CoEmCkg_stStrtRstrtFbCmd, u8LocalCoEmCkg_stStrtRstrtFbCmd);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);


   /* Checking the Conditions to Activate the Stuck Engine Risk's Calculation */
   bLocal_bAcvCalcStuckEngPrev = CoSync_bAcvCalcStuckEng;
   u32LocalCoSync_nAcvStuckEng_C = (uint32)(CoSync_nAcvStuckEng_C * 10);
   if (  (  ((uint32)u16LocalExt_nEng <= u32LocalCoSync_nAcvStuckEng_C)
         || (bLocalAcvCoSyncDftCk != 0)
         || (bLocalSync_bDgoCkSig != 0))
      && (CoSync_bAcvStuckEng_C != 0))
   {
      CoSync_bAcvCalcStuckEng = 1;
   }
   else
   {
      CoSync_bAcvCalcStuckEng = 0;
   }
   if (  (CoSync_bAcvCalcStuckEng != 0)
      && (bLocal_bAcvCalcStuckEngPrev == 0))
   {
      CoSync_bAcvStuckEngIni = 1;
   }
   else
   {
      CoSync_bAcvStuckEngIni = 0;
   }

   /* Checking the Electrical Machine's Activating Condition */
   bLocal_bAcvElSysPrev = CoSync_bAcvElSys;
   if (u8LocalCoEmCkg_stStrtRstrtFbCmd == 1)
   {
      CoSync_bAcvElSys = 1;
   }
   else
   {
      CoSync_bAcvElSys = 0;
   }
   if (  (CoSync_bAcvElSys != 0)
      && (bLocal_bAcvElSysPrev == 0))
   {
      CoSync_bStrtAcvElSys = 1;
   }
   else
   {
      CoSync_bStrtAcvElSys = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidPrevenirRisqGrippgeVil                           */
/* !Description :  Ce bloc informe et de prévient du risque d’un blocage      */
/*                 vilebrequin via : 1. L’information de risque moteur bloqué */
/*                 et machine électrique active, 2. L’information demandant de*/
/*                 forcer la désynchronisation, afin de prévenir l’injection. */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COSYNC_vidEvalAbsnceSignVilEtAAC();                      */
/*  extf argret void COSYNC_vidEvalDefailSignAACEtVil();                      */
/*  extf argret void COSYNC_vidConnaitreEtatMoteur();                         */
/*  extf argret void COSYNC_vidCnfrmValidSignAACOuVil();                      */
/*  extf argret void COSYNC_vidGenererSortiesFonction();                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidPrevenirRisqGrippgeVil(void)
{
   COSYNC_vidEvalAbsnceSignVilEtAAC();
   COSYNC_vidEvalDefailSignAACEtVil();
   COSYNC_vidConnaitreEtatMoteur();
   COSYNC_vidCnfrmValidSignAACOuVil();
   COSYNC_vidGenererSortiesFonction();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidEvalAbsnceSignVilEtAAC                           */
/* !Description :  Ce bloc permet de détecter l’absence de passage de dents   */
/*                 vilebrequin, de fronts AAC admission et de fronts AAC      */
/*                 échappement pendant un temps calibrable.                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COSYNC_vidTraitInfoCmptFrontsVil();                      */
/*  extf argret void COSYNC_vidTraitInfoCmptFrontsAAC();                      */
/*  extf argret void COSYNC_vidCalcAbsenceFrontsVil();                        */
/*  extf argret void COSYNC_vidCalcAbsenceFrontsAAC();                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidEvalAbsnceSignVilEtAAC(void)
{
   COSYNC_vidTraitInfoCmptFrontsVil();
   COSYNC_vidTraitInfoCmptFrontsAAC();
   COSYNC_vidCalcAbsenceFrontsVil();
   COSYNC_vidCalcAbsenceFrontsAAC();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidEvalDefailSignAACEtVil                           */
/* !Description :  Ce bloc permet de définir : 1. l’exploitation possible du  */
/*                 signal vilebrequin (présence de fronts, pas de remontée de */
/*                 diagnostic), 2. l’exploitation possible d’un signal AAC    */
/*                 (existence, présence, pas de remontée de diagnostic sur au */
/*                 moins un signal AAC).                                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  input boolean CoSync_bPresSigCmIn_C;                                      */
/*  input boolean CoSync_bMissSigCmIn;                                        */
/*  input boolean CoSync_bPresSigCmEx_C;                                      */
/*  input boolean CoSync_bMissSigCmEx;                                        */
/*  input boolean CoSync_bMissSigCk;                                          */
/*  output boolean CoSync_bDetErrSigCm;                                       */
/*  output boolean CoSync_bDetErrSigCk;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidEvalDefailSignAACEtVil(void)
{
   boolean bLocalAcvCoSyncDftCk;
   boolean bLocalAcvCoSyncDftCmIn;
   boolean bLocalAcvCoSyncDftCmEx;
   boolean bLocalCoSync_bDetErrSigCmAACIn;
   boolean bLocalCoSync_bDetErrSigCmAACEx;


   bLocalAcvCoSyncDftCmIn = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCMIN);
   bLocalAcvCoSyncDftCmEx = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCMEX);
   bLocalAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);

   /* Evaluating the presence of failures on the camshaft's intake signal */
   if (  (CoSync_bPresSigCmIn_C == 0)
      || (bLocalAcvCoSyncDftCmIn != 0)
      || (CoSync_bMissSigCmIn != 0))
   {
      bLocalCoSync_bDetErrSigCmAACIn = 1;
   }
   else
   {
      bLocalCoSync_bDetErrSigCmAACIn = 0;
   }

   /* Evaluating the presence of failures on the camshaft's exhaust signal */
   if (  (CoSync_bPresSigCmEx_C == 0)
      || (bLocalAcvCoSyncDftCmEx != 0)
      || (CoSync_bMissSigCmEx != 0))
   {
      bLocalCoSync_bDetErrSigCmAACEx = 1;
   }
   else
   {
      bLocalCoSync_bDetErrSigCmAACEx = 0;
   }

   /* Evaluating the presence of failures on the overall camshaft's signal */
   if (  (bLocalCoSync_bDetErrSigCmAACIn != 0)
      && (bLocalCoSync_bDetErrSigCmAACEx != 0))
   {
      CoSync_bDetErrSigCm = 1;
   }
   else
   {
      CoSync_bDetErrSigCm = 0;
   }

   /* Evaluating the presence of failures on the crankshaft's signal */
   if (  (CoSync_bMissSigCk != 0)
      || (bLocalAcvCoSyncDftCk != 0))
   {
      CoSync_bDetErrSigCk = 1;
   }
   else
   {
      CoSync_bDetErrSigCk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidConnaitreEtatMoteur                              */
/* !Description :  Ce bloc contient la machine d’état qui est utilisé pour    */
/*                 définir la stratégie de synchronisation à activer.         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoSync_stCoSync;                                              */
/*  input boolean CoSync_bStrtAcvElSys;                                       */
/*  input boolean CoSync_bDetErrSigCk;                                        */
/*  input boolean CoSync_bDetErrSigCm;                                        */
/*  input boolean CoSync_bCfmVldSigCm;                                        */
/*  input boolean CoSync_bCfmVldSigCk;                                        */
/*  output uint8 CoSync_stCoSync;                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidConnaitreEtatMoteur(void)
{
   switch(CoSync_stCoSync)
   {
      /* SURVEILLANCE_DEFAILLANCE */
      case 0:
         if (CoSync_bStrtAcvElSys == 0)
         {
            if (CoSync_bDetErrSigCk == 0)
            {
               if (CoSync_bDetErrSigCm != 0)
               {
                  CoSync_stCoSync = 2;
               }
            }
            else
            {
               if (CoSync_bDetErrSigCm == 0)
               {
                  CoSync_stCoSync = 1;
               }
               else
               {
                  CoSync_stCoSync = 5;
               }
            }
         }
         break;
      /* DEFAILLANCE_VIL */
      case 1:
         if (CoSync_bStrtAcvElSys != 0)
         {
            CoSync_stCoSync = 0;
         }
         else
         {
            if (CoSync_bDetErrSigCm != 0)
            {
               CoSync_stCoSync = 5;
            }
            else
            {
               if (CoSync_bCfmVldSigCm != 0)
               {
                  CoSync_stCoSync = 3;
               }
            }
         }
         break;
      /* DEFAILLANCE_AAC */
      case 2:
         if (CoSync_bStrtAcvElSys != 0)
         {
            CoSync_stCoSync = 0;
         }
         else
         {
            if (CoSync_bDetErrSigCk != 0)
            {
               CoSync_stCoSync = 5;
            }
            else
            {
               if (CoSync_bCfmVldSigCk != 0)
               {
                  CoSync_stCoSync = 4;
               }
            }
         }
         break;
      /* ACTIV_BACK_UP_VIL */
      case 3:
         if (CoSync_bStrtAcvElSys != 0)
         {
            CoSync_stCoSync = 0;
         }
         else
         {
            if (CoSync_bDetErrSigCm != 0)
            {
               CoSync_stCoSync = 5;
            }
         }
         break;
      /* ACTIV_BACK_UP_AAC */
      case 4:
         if (CoSync_bStrtAcvElSys != 0)
         {
            CoSync_stCoSync = 0;
         }
         else
         {
            if (CoSync_bDetErrSigCk != 0)
            {
               CoSync_stCoSync = 5;
            }
         }
         break;
      /* SIGNAUX_INEXPLOITABLES */
      case 5:
         if (CoSync_bStrtAcvElSys != 0)
         {
            CoSync_stCoSync = 0;
         }
         else
         {
            if (  (CoSync_bDetErrSigCk == 0)
               || (CoSync_bDetErrSigCm == 0))
            {
               CoSync_stCoSync = 6;
            }
         }
         break;
      /* SIGNAUX_DE_NOUVEAU_EXPLOITABLES */
      case 6:
         if (CoSync_bStrtAcvElSys != 0)
         {
            CoSync_stCoSync = 0;
         }
         else
         {
            if (  (CoSync_bDetErrSigCk != 0)
               && (CoSync_bDetErrSigCm != 0))
            {
               CoSync_stCoSync = 5;
            }
         }
         break;
      /* CAS DEFAUT */
      default:
         CoSync_stCoSync = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidCnfrmValidSignAACOuVil                           */
/* !Description :  Ce bloc permet de maintenir l’état « DEFAILLANCE_VIL »     */
/*                 (respectivement l’état « DEFAILLANCE_AAC ») durant une     */
/*                 certaine durée le temps de confirmation de l’exploitation  */
/*                 possible du signal AAC (respectivement vilebrequin).       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean CoSync_bStrtAcvElSys;                                       */
/*  input boolean CoSync_bAcvStuckEngIni;                                     */
/*  input uint8 COSYNC_u8CoSyncStCoSyncPrev;                                  */
/*  input uint8 CoSync_stCoSync;                                              */
/*  input boolean COSYNC_bCfmVldSigCmCntInput;                                */
/*  input uint16 CoSync_ctCfmVldSigCm_MP;                                     */
/*  input uint8 CoSync_tiRbm_C;                                               */
/*  input uint8 CoSync_tiCmfVldSigCm_C;                                       */
/*  input boolean COSYNC_bCfmVldSigCkCntInput;                                */
/*  input uint16 CoSync_ctCfmVldSigCk_MP;                                     */
/*  input uint8 CoSync_tiCmfVldSigCk_C;                                       */
/*  output uint8 COSYNC_u8CoSyncStCoSyncPrev;                                 */
/*  output uint16 CoSync_ctCfmVldSigCm_MP;                                    */
/*  output boolean COSYNC_bCfmVldSigCmCntInput;                               */
/*  output boolean CoSync_bCfmVldSigCm;                                       */
/*  output uint16 CoSync_ctCfmVldSigCk_MP;                                    */
/*  output boolean COSYNC_bCfmVldSigCkCntInput;                               */
/*  output boolean CoSync_bCfmVldSigCk;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidCnfrmValidSignAACOuVil(void)
{
   boolean bLocal_SigCmCntInput;
   boolean bLocal_SigCkCntInput;
   uint16  u16Local_CounterMaxThreshold;


   if (  (CoSync_bStrtAcvElSys != 0)
      || (CoSync_bAcvStuckEngIni != 0))
   {
      bLocal_SigCmCntInput = 1;
      bLocal_SigCkCntInput = 1;
   }
   else
   {
      if (COSYNC_u8CoSyncStCoSyncPrev != 1)
      {
         bLocal_SigCmCntInput = 1;
      }
      else
      {
         bLocal_SigCmCntInput = 0;
      }

      if (COSYNC_u8CoSyncStCoSyncPrev != 2)
      {
         bLocal_SigCkCntInput = 1;
      }
      else
      {
         bLocal_SigCkCntInput = 0;
      }
   }
   COSYNC_u8CoSyncStCoSyncPrev = (uint8)MATHSRV_udtMIN(CoSync_stCoSync,10);

   /* Confirming the validity of the camshaft's signal */
   if (bLocal_SigCmCntInput != 0)
   {
      if (COSYNC_bCfmVldSigCmCntInput == 0)
      {
         CoSync_ctCfmVldSigCm_MP = 0;
      }
      else
      {
         if (CoSync_ctCfmVldSigCm_MP > 600)
         {
            CoSync_ctCfmVldSigCm_MP = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(CoSync_ctCfmVldSigCm_MP < u16Local_CounterMaxThreshold)
      {
         CoSync_ctCfmVldSigCm_MP = (uint16)( CoSync_ctCfmVldSigCm_MP
                                           + CoSync_tiRbm_C);
      }
      else
      {
         CoSync_ctCfmVldSigCm_MP = 600;
      }
   }
   COSYNC_bCfmVldSigCmCntInput = bLocal_SigCmCntInput;

   if (CoSync_ctCfmVldSigCm_MP >= CoSync_tiCmfVldSigCm_C)
   {
      CoSync_bCfmVldSigCm = 1;
   }
   else
   {
      CoSync_bCfmVldSigCm = 0;
   }

   /* Confirming the validity of the crankshaft's signal */
   if (bLocal_SigCkCntInput !=0)
   {
      if (COSYNC_bCfmVldSigCkCntInput == 0)
      {
         CoSync_ctCfmVldSigCk_MP = 0;
      }
      else
      {
         if (CoSync_ctCfmVldSigCk_MP > 600)
         {
            CoSync_ctCfmVldSigCk_MP = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if (CoSync_ctCfmVldSigCk_MP < u16Local_CounterMaxThreshold)
      {
         CoSync_ctCfmVldSigCk_MP = (uint16)( CoSync_ctCfmVldSigCk_MP
                                           + CoSync_tiRbm_C);
      }
      else
      {
         CoSync_ctCfmVldSigCk_MP = 600;
      }
   }
   COSYNC_bCfmVldSigCkCntInput = bLocal_SigCkCntInput;

   if (CoSync_ctCfmVldSigCk_MP >= CoSync_tiCmfVldSigCk_C)
   {
      CoSync_bCfmVldSigCk = 1;
   }
   else
   {
      CoSync_bCfmVldSigCk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidGenererSortiesFonction                           */
/* !Description :  Ce bloc exploite l’état de la machine d’état et convertit  */
/*                 en informations : 1. Risque machine électrique bloquée et  */
/*                 active, 2. Demande de désynchronisation moteur (Pour les   */
/*                 cas ou il y a un risque de moteur bloqué).                 */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean Sync_bDgoCmSig;                                             */
/*  input uint8 CoSync_stCoSync;                                              */
/*  input boolean CoSync_bAcvElSys;                                           */
/*  input boolean CoSync_bAcvForc0Sync_C;                                     */
/*  output boolean CoSync_bStuckEngStaAcvRaw;                                 */
/*  output boolean CoSync_bForcEngNotSyncRaw;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidGenererSortiesFonction(void)
{
   boolean bLocalCoSync_bForcEngNotSyncRaw;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalSync_bDgoCmSig;


   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(Sync_bDgoCmSig, bLocalSync_bDgoCmSig);

   if (CoSync_stCoSync == 5)
   {
      CoSync_bStuckEngStaAcvRaw = CoSync_bAcvElSys;
      bLocalCoSync_bForcEngNotSyncRaw = 1;
   }
   else
   {
      CoSync_bStuckEngStaAcvRaw = 0;
      if (  (  (CoSync_stCoSync == 1)
            && (bLocalSync_bDgoCkSig == 0))
         || (  (CoSync_stCoSync == 2)
            && (bLocalSync_bDgoCmSig == 0)))
      {
         bLocalCoSync_bForcEngNotSyncRaw = 1;
      }
      else
      {
         bLocalCoSync_bForcEngNotSyncRaw = 0;
      }
   }

   if (  (bLocalCoSync_bForcEngNotSyncRaw != 0)
      && (CoSync_bAcvForc0Sync_C != 0))
   {
      CoSync_bForcEngNotSyncRaw = 1;
   }
   else
   {
      CoSync_bForcEngNotSyncRaw = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/