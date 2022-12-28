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
/* !File            : COSYNC_FCT3.c                                           */
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
/*   1 / COSYNC_vidTraitInfoCmptFrontsVil                                     */
/*   2 / COSYNC_vidTraitInfoCmptFrontsAAC                                     */
/*   3 / COSYNC_vidCalcAbsenceFrontsVil                                       */
/*   4 / COSYNC_vidCalcAbsenceFrontsAAC                                       */
/*   5 / COSYNC_vidActvCalcDiagPosArret                                       */
/*   6 / COSYNC_vidInfrmRsqClcErrPosArret                                     */
/*   7 / COSYNC_vidBouchSortiesDgPosArret                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 02290 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2284 / 02                                       */
/* !OtherRefs   : VEMS V02 ECU#048141                                         */
/* !OtherRefs   : VEMS V02 ECU#048312                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COSYNC/COSYNC_FCT3.c_v$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   Jun 28 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 28 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "COSYNC.h"
#include "COSYNC_L.h"
#include "COSYNC_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidTraitInfoCmptFrontsVil                           */
/* !Description :  Ce bloc renvoie une information pour savoir s‘il y a eu ou */
/*                 pas un passage de front descendant du signal vilebrequin.  */
/*                 Il permet également de détecter le passage du 1er front    */
/*                 descendant du signal vilebrequin après l’activation de la  */
/*                 machine électrique.                                        */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_ctEdgeCk;                                                 */
/*  input boolean CoSync_bAcvStuckEngIni;                                     */
/*  input uint8 COSYNC_u8ExtCtEdgeCkPrev;                                     */
/*  input boolean CoSync_bDetCkAcvElSys;                                      */
/*  input boolean CoSync_bStrtAcvElSys;                                       */
/*  input boolean CoSync_bDifCntEdgeCk;                                       */
/*  output boolean CoSync_bDifCntEdgeCk;                                      */
/*  output boolean CoSync_bDetCkAcvElSys;                                     */
/*  output uint8 COSYNC_u8ExtCtEdgeCkPrev;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidTraitInfoCmptFrontsVil(void)
{
   boolean bLocalCoSync_bDetCkAcvElSys;
   uint8   u8LocalExt_ctEdgeCk;


   VEMS_vidGET(Ext_ctEdgeCk, u8LocalExt_ctEdgeCk);

   if (CoSync_bAcvStuckEngIni != 0)
   {
      CoSync_bDifCntEdgeCk = 0;
      bLocalCoSync_bDetCkAcvElSys = 1;
   }
   else
   {
      if (u8LocalExt_ctEdgeCk != COSYNC_u8ExtCtEdgeCkPrev)
      {
         CoSync_bDifCntEdgeCk = 1;
      }
      else
      {
         CoSync_bDifCntEdgeCk = 0;
      }

      bLocalCoSync_bDetCkAcvElSys = CoSync_bDetCkAcvElSys;
   }

   if (CoSync_bStrtAcvElSys != 0)
   {
      CoSync_bDetCkAcvElSys = 0;
   }
   else
   {
      if (  (CoSync_bDifCntEdgeCk != 0)
         || (bLocalCoSync_bDetCkAcvElSys != 0))
      {
         CoSync_bDetCkAcvElSys = 1;
      }
      else
      {
         CoSync_bDetCkAcvElSys = 0;
      }
   }

   COSYNC_u8ExtCtEdgeCkPrev = u8LocalExt_ctEdgeCk;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidTraitInfoCmptFrontsAAC                           */
/* !Description :  Ce bloc renvoie l'information de passage ou non de front   */
/*                 AAC pour le signal AAC admission et échappement. Il permet */
/*                 aussi de détecter le passage du 1er front AAC admission et */
/*                 échappement après l’activation de la machine électrique.   */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_ctEdgeCmIn;                                               */
/*  input uint8 Ext_ctEdgeCmEx;                                               */
/*  input boolean CoSync_bAcvStuckEngIni;                                     */
/*  input uint8 CoSync_ctEdgeCmIn_MP;                                         */
/*  input boolean COSYNC_bDetCmInElSys;                                       */
/*  input uint8 CoSync_ctEdgeCmEx_MP;                                         */
/*  input boolean COSYNC_bDetCmExElSys;                                       */
/*  input boolean CoSync_bStrtAcvElSys;                                       */
/*  input boolean CoSync_bPresSigCmIn_C;                                      */
/*  input boolean CoSync_bPresSigCmEx_C;                                      */
/*  output boolean COSYNC_bDetCmInElSys;                                      */
/*  output boolean COSYNC_bDetCmExElSys;                                      */
/*  output boolean CoSync_bDetCmInAcvElSys;                                   */
/*  output boolean CoSync_bDifCntEdgeCmIn;                                    */
/*  output boolean CoSync_bDetCmExAcvElSys;                                   */
/*  output boolean CoSync_bDifCntEdgeCmEx;                                    */
/*  output uint8 CoSync_ctEdgeCmIn_MP;                                        */
/*  output uint8 CoSync_ctEdgeCmEx_MP;                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidTraitInfoCmptFrontsAAC(void)
{
   boolean bLocalCoSync_bDifCntEdgeCmIn;
   boolean bLocalCoSync_bDetCmInAcvElSys;
   boolean bLocalCoSync_bDifCntEdgeCmEx;
   boolean bLocalCoSync_bDetCmExAcvElSys;
   uint8   u8LocalExt_ctEdgeCmIn;
   uint8   u8LocalExt_ctEdgeCmEx;


   VEMS_vidGET(Ext_ctEdgeCmIn, u8LocalExt_ctEdgeCmIn);
   VEMS_vidGET(Ext_ctEdgeCmEx, u8LocalExt_ctEdgeCmEx);

   if (CoSync_bAcvStuckEngIni != 0)
   {
      bLocalCoSync_bDifCntEdgeCmIn = 0;
      bLocalCoSync_bDetCmInAcvElSys = 1;
      bLocalCoSync_bDifCntEdgeCmEx = 0;
      bLocalCoSync_bDetCmExAcvElSys = 1;
   }
   else
   {
      if (u8LocalExt_ctEdgeCmIn != CoSync_ctEdgeCmIn_MP)
      {
         bLocalCoSync_bDifCntEdgeCmIn = 1;
      }
      else
      {
         bLocalCoSync_bDifCntEdgeCmIn = 0;
      }

      bLocalCoSync_bDetCmInAcvElSys = COSYNC_bDetCmInElSys;

      if (u8LocalExt_ctEdgeCmEx != CoSync_ctEdgeCmEx_MP)
      {
         bLocalCoSync_bDifCntEdgeCmEx = 1;
      }
      else
      {
         bLocalCoSync_bDifCntEdgeCmEx = 0;
      }

      bLocalCoSync_bDetCmExAcvElSys = COSYNC_bDetCmExElSys;
   }

   if (CoSync_bStrtAcvElSys != 0)
   {
      COSYNC_bDetCmInElSys = 0;
      COSYNC_bDetCmExElSys = 0;
   }
   else
   {
      if (  (bLocalCoSync_bDifCntEdgeCmIn != 0)
         || (bLocalCoSync_bDetCmInAcvElSys != 0))
      {
         COSYNC_bDetCmInElSys = 1;
      }
      else
      {
         COSYNC_bDetCmInElSys = 0;
      }

      if (  (bLocalCoSync_bDifCntEdgeCmEx != 0)
         || (bLocalCoSync_bDetCmExAcvElSys != 0))
      {
         COSYNC_bDetCmExElSys = 1;
      }
      else
      {
         COSYNC_bDetCmExElSys = 0;
      }
   }

   if (CoSync_bPresSigCmIn_C == 0)
   {
      CoSync_bDetCmInAcvElSys = 0;
      CoSync_bDifCntEdgeCmIn = 0;
   }
   else
   {
      CoSync_bDetCmInAcvElSys = COSYNC_bDetCmInElSys;
      CoSync_bDifCntEdgeCmIn = bLocalCoSync_bDifCntEdgeCmIn;
   }

   if (CoSync_bPresSigCmEx_C == 0)
   {
      CoSync_bDetCmExAcvElSys = 0;
      CoSync_bDifCntEdgeCmEx = 0;
   }
   else
   {
      CoSync_bDetCmExAcvElSys = COSYNC_bDetCmExElSys;
      CoSync_bDifCntEdgeCmEx = bLocalCoSync_bDifCntEdgeCmEx;
   }

   CoSync_ctEdgeCmIn_MP = u8LocalExt_ctEdgeCmIn;
   CoSync_ctEdgeCmEx_MP = u8LocalExt_ctEdgeCmEx;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidCalcAbsenceFrontsVil                             */
/* !Description :  Ce bloc permet de détecter l’absence de front vilebrequin. */
/*                 La temporisation est variable si l’initialisation          */
/*                 précédente du compteur s’est faite sur l’activation de la  */
/*                 machine électrique ou sur un front vilebrequin.            */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean CoSync_bDifCntEdgeCk;                                       */
/*  input boolean CoSync_bStrtAcvElSys;                                       */
/*  input boolean CoSync_bAcvStuckEngIni;                                     */
/*  input boolean COSYNC_bMissSigCkCntInput;                                  */
/*  input uint16 CoSync_ctMissSigCk_MP;                                       */
/*  input uint8 CoSync_tiRbm_C;                                               */
/*  input boolean CoSync_bDetCkAcvElSys;                                      */
/*  input uint8 CoSync_tiMaxDetEdgeCk_C;                                      */
/*  input uint8 CoSync_tiMaxDetEdgeCkIni_C;                                   */
/*  output uint16 CoSync_ctMissSigCk_MP;                                      */
/*  output boolean COSYNC_bMissSigCkCntInput;                                 */
/*  output boolean CoSync_bMissSigCk;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidCalcAbsenceFrontsVil(void)
{
   boolean bLocal_SigCkCntInput;
   uint8   u8Local_tiMaxDetEdgeCk;
   uint16  u16Local_CounterMaxThreshold;


   if (  (CoSync_bDifCntEdgeCk != 0)
      || (CoSync_bStrtAcvElSys != 0)
      || (CoSync_bAcvStuckEngIni != 0))
   {
      bLocal_SigCkCntInput = 1;
   }
   else
   {
      bLocal_SigCkCntInput = 0;
   }

   /* Checking the presence of the crankshaft's signal */
   if (bLocal_SigCkCntInput !=0)
   {
      if (COSYNC_bMissSigCkCntInput == 0)
      {
         CoSync_ctMissSigCk_MP = 0;
      }
      else
      {
         if (CoSync_ctMissSigCk_MP > 600)
         {
            CoSync_ctMissSigCk_MP = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(CoSync_ctMissSigCk_MP < u16Local_CounterMaxThreshold)
      {
         CoSync_ctMissSigCk_MP = (uint16)( CoSync_ctMissSigCk_MP
                                         + CoSync_tiRbm_C);
      }
      else
      {
         CoSync_ctMissSigCk_MP = 600;
      }
   }
   COSYNC_bMissSigCkCntInput = bLocal_SigCkCntInput;

   if (CoSync_bDetCkAcvElSys != 0)
   {
      u8Local_tiMaxDetEdgeCk = CoSync_tiMaxDetEdgeCk_C;
   }
   else
   {
      u8Local_tiMaxDetEdgeCk = CoSync_tiMaxDetEdgeCkIni_C;
   }
   if (CoSync_ctMissSigCk_MP >= u8Local_tiMaxDetEdgeCk)
   {
      CoSync_bMissSigCk = 1;
   }
   else
   {
      CoSync_bMissSigCk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidCalcAbsenceFrontsAAC                             */
/* !Description :  Ce bloc permet de détecter l’absence de front AAC admission*/
/*                 ou échappement. La temporisation est variable si           */
/*                 l’initialisation du compteur s’est faite sur l’activation  */
/*                 de la machine électrique ou sur un front vilebrequin.      */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean CoSync_bStrtAcvElSys;                                       */
/*  input boolean CoSync_bAcvStuckEngIni;                                     */
/*  input boolean CoSync_bDifCntEdgeCmIn;                                     */
/*  input boolean CoSync_bDifCntEdgeCmEx;                                     */
/*  input boolean COSYNC_bMissSigAACInCntInput;                               */
/*  input uint16 CoSync_ctMissSigCmIn_MP;                                     */
/*  input uint8 CoSync_tiRbm_C;                                               */
/*  input boolean CoSync_bDetCmInAcvElSys;                                    */
/*  input uint8 CoSync_tiMaxDetEdgeCm_C;                                      */
/*  input uint8 CoSync_tiMaxDetEdgeCmIni_C;                                   */
/*  input boolean COSYNC_bMissSigAACExCntInput;                               */
/*  input uint16 CoSync_ctMissSigCmEx_MP;                                     */
/*  input boolean CoSync_bDetCmExAcvElSys;                                    */
/*  output uint16 CoSync_ctMissSigCmIn_MP;                                    */
/*  output boolean COSYNC_bMissSigAACInCntInput;                              */
/*  output boolean CoSync_bMissSigCmIn;                                       */
/*  output uint16 CoSync_ctMissSigCmEx_MP;                                    */
/*  output boolean COSYNC_bMissSigAACExCntInput;                              */
/*  output boolean CoSync_bMissSigCmEx;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidCalcAbsenceFrontsAAC(void)
{
   boolean bLocal_SigAACInCntInput;
   boolean bLocal_SigAACExCntInput;
   uint8   u8Local_tiMaxDetEdgeAACIn;
   uint8   u8Local_tiMaxDetEdgeAACEx;
   uint16  u16Local_CounterMaxThreshold;


   if (  (CoSync_bStrtAcvElSys != 0)
      || (CoSync_bAcvStuckEngIni != 0))
   {
      bLocal_SigAACInCntInput = 1;
      bLocal_SigAACExCntInput = 1;
   }
   else
   {
      bLocal_SigAACInCntInput = CoSync_bDifCntEdgeCmIn;
      bLocal_SigAACExCntInput = CoSync_bDifCntEdgeCmEx;
   }

   /* Checking the presence of the camshaft's intake signal */
   if (bLocal_SigAACInCntInput !=0)
   {
      if (COSYNC_bMissSigAACInCntInput == 0)
      {
         CoSync_ctMissSigCmIn_MP = 0;
      }
      else
      {
         if (CoSync_ctMissSigCmIn_MP > 600)
         {
            CoSync_ctMissSigCmIn_MP = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(CoSync_ctMissSigCmIn_MP < u16Local_CounterMaxThreshold)
      {
         CoSync_ctMissSigCmIn_MP = (uint16)( CoSync_ctMissSigCmIn_MP
                                           + CoSync_tiRbm_C);
      }
      else
      {
         CoSync_ctMissSigCmIn_MP = 600;
      }
   }
   COSYNC_bMissSigAACInCntInput = bLocal_SigAACInCntInput;

   if (CoSync_bDetCmInAcvElSys != 0)
   {
      u8Local_tiMaxDetEdgeAACIn = CoSync_tiMaxDetEdgeCm_C;
   }
   else
   {
      u8Local_tiMaxDetEdgeAACIn = CoSync_tiMaxDetEdgeCmIni_C;
   }

   if (CoSync_ctMissSigCmIn_MP >= u8Local_tiMaxDetEdgeAACIn)
   {
      CoSync_bMissSigCmIn = 1;
   }
   else
   {
      CoSync_bMissSigCmIn = 0;
   }

   /* Checking the presence of the camshaft's exhaust signal */
   if (bLocal_SigAACExCntInput !=0)
   {
      if (COSYNC_bMissSigAACExCntInput == 0)
      {
         CoSync_ctMissSigCmEx_MP = 0;
      }
      else
      {
         if (CoSync_ctMissSigCmEx_MP > 600)
         {
            CoSync_ctMissSigCmEx_MP = 600;
         }
      }
   }
   else
   {
      u16Local_CounterMaxThreshold = (uint16)(600 - CoSync_tiRbm_C);
      if(CoSync_ctMissSigCmEx_MP < u16Local_CounterMaxThreshold)
      {
         CoSync_ctMissSigCmEx_MP = (uint16)( CoSync_ctMissSigCmEx_MP
                                           + CoSync_tiRbm_C);
      }
      else
      {
         CoSync_ctMissSigCmEx_MP = 600;
      }
   }
   COSYNC_bMissSigAACExCntInput = bLocal_SigAACExCntInput;

   if (CoSync_bDetCmExAcvElSys != 0)
   {
      u8Local_tiMaxDetEdgeAACEx = CoSync_tiMaxDetEdgeCm_C;
   }
   else
   {
      u8Local_tiMaxDetEdgeAACEx = CoSync_tiMaxDetEdgeCmIni_C;
   }
   if (CoSync_ctMissSigCmEx_MP >= u8Local_tiMaxDetEdgeAACEx)
   {
      CoSync_bMissSigCmEx = 1;
   }
   else
   {
      CoSync_bMissSigCmEx = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidActvCalcDiagPosArret                             */
/* !Description :  Ce bloc permet d’activer ou pas le calcul de diagnostic sur*/
/*                 la position d’arrêt moteur. Le calcul se déroule à bas     */
/*                 régime et si une défaillance est possible sur le signal    */
/*                 vilebrequin (car l’information Ext_nEng n’est plus fiable).*/
/* !Number      :  FCT3.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean CoSync_bAcvCalcDgoPosEs;                                    */
/*  input uint8 CoSync_nAcvDgoPosEs_C;                                        */
/*  input boolean CoSync_bAcvDgoPosEs_C;                                      */
/*  output boolean CoSync_bAcvCalcDgoPosEs;                                   */
/*  output boolean CoSync_bAcvDgoPosEsIni;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidActvCalcDiagPosArret(void)
{
   boolean bLocalAcvCoSyncDftCk;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalCoSync_bAcvCalcDgoPosEs;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalCoSync_nAcvDgoPosEs_C;


   bLocalAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   VEMS_vidGET(Ext_nEng,u16LocalExt_nEng);
   VEMS_vidGET(Sync_bDgoCkSig,bLocalSync_bDgoCkSig);

   bLocalCoSync_bAcvCalcDgoPosEs = CoSync_bAcvCalcDgoPosEs;
   u16LocalCoSync_nAcvDgoPosEs_C = (uint16)(CoSync_nAcvDgoPosEs_C * 10);

   if (  (CoSync_bAcvDgoPosEs_C != 0)
      && (  (u16LocalExt_nEng <= u16LocalCoSync_nAcvDgoPosEs_C)
         || (bLocalAcvCoSyncDftCk != 0)
         || (bLocalSync_bDgoCkSig != 0)))
   {
      CoSync_bAcvCalcDgoPosEs = 1;
   }
   else
   {
      CoSync_bAcvCalcDgoPosEs = 0;
   }

   if (  (CoSync_bAcvCalcDgoPosEs != 0)
      && (bLocalCoSync_bAcvCalcDgoPosEs == 0))
   {
      CoSync_bAcvDgoPosEsIni = 1;
   }
   else
   {
      CoSync_bAcvDgoPosEsIni = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidInfrmRsqClcErrPosArret                           */
/* !Description :  Ce bloc permet d’informer du risque que la position d’arrêt*/
/*                 moteur calculée est erronée ou pas. Actuellement cette     */
/*                 fonction n’est pas développée.                             */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CoSync_bDemMissSyncRaw;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidInfrmRsqClcErrPosArret(void)
{
   CoSync_bDemMissSyncRaw = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidBouchSortiesDgPosArret                           */
/* !Description :  Ce bloc permet de bouchonner les variables de la fonction «*/
/*                 Informer du risque de calcul erroné de la position d arrêt */
/*                 moteur » si le calcul de la fonction n’est pas activé.     */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoSync_bAcvCalcDgoPosEs;                                    */
/*  input boolean CoSync_bDemMissSyncRaw;                                     */
/*  output boolean CoSync_bDemMissSync;                                       */
/*  output boolean CoSync_bDemMissSyncRaw;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidBouchSortiesDgPosArret(void)
{
   if (CoSync_bAcvCalcDgoPosEs != 0)
   {
      VEMS_vidSET(CoSync_bDemMissSync, CoSync_bDemMissSyncRaw);
   }
   else
   {
      VEMS_vidSET(CoSync_bDemMissSync, 0);
   }
}
/*-------------------------------- end of file -------------------------------*/