/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_SCH15.C                                   */
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
/*   1 / InjrM_EveCkSnOn_InjrMdlIf                                            */
/*   2 / InjrM_SdlFast_InjrMdlIf                                              */
/*   3 / InjrM_EveInj_InjrMdlIf                                               */
/*   4 / InjrM_EveSpl_InjrMdlIf                                               */
/*   5 / CrkMgt_SdlFast_IfTqSysIf                                             */
/*   6 / Eng_Sdl100ms_tOilEstimIf                                             */
/*   7 / RE_TqSys_EveSync_IdlCordLimIf                                        */
/*   8 / FuAcq_SdlFast_PFuAcqIf                                               */
/*   9 / Can_EveRxn592_FHCanF592If                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjrM_EveCkSnOn_InjrMdlIf                                  */
/* !Description :  Evènement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise pour InjrMdlFct                         */
/* !Number      :  SCH15.1                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInjrMSys1();                            */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjrM_EveCkSnOn_InjrMdlIf                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjrM_EveCkSnOn_InjrMdlIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidInjrMSys1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjrM_SdlFast_InjrMdlIf                                    */
/* !Description :  Moniteur rapide pour la fonction de calcul du modèle       */
/*                 injecteur.                                                 */
/* !Number      :  SCH15.2                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInjrMSys1();                            */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjrM_SdlFast_InjrMdlIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjrM_SdlFast_InjrMdlIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidInjrMSys1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjrM_EveInj_InjrMdlIf                                     */
/* !Description :  Evènement Injection pour la fonction de calcul du modèle   */
/*                 injecteur.                                                 */
/* !Number      :  SCH15.3                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInjrMSys1();                            */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjrM_EveInj_InjrMdlIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjrM_EveInj_InjrMdlIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidInjrMSys1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjrM_EveSpl_InjrMdlIf                                     */
/* !Description :  Evènement Spill pour la fonction du calcul du modèle       */
/*                 injecteur.                                                 */
/* !Number      :  SCH15.4                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInjrMSys1();                            */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjrM_EveSpl_InjrMdlIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjrM_EveSpl_InjrMdlIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidInjrMSys1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrkMgt_SdlFast_IfTqSysIf                                   */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH15.5                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutputStrtEnd();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrkMgt_SdlFast_IfTqSysIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrkMgt_SdlFast_IfTqSysIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutputStrtEnd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Eng_Sdl100ms_tOilEstimIf                                   */
/* !Description :  Moniteur 100ms.                                            */
/* !Number      :  SCH15.6                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_tOilChk();                       */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_tOilMes();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Eng_Sdl100ms_tOilEstimIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Eng_Sdl100ms_tOilEstimIf(void)
{
/*QAC Warning(2:4152): Name imposed by specification*/
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutput_tOilChk();
      IFAIRSYSIGSYS_vidOutput_tOilMes();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_TqSys_EveSync_IdlCordLimIf                              */
/* !Description :  Scheduler du module CoClLASl.                              */
/* !Number      :  SCH15.7                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_IdlLim();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_TqSys_EveSync_IdlCordLimIf                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_TqSys_EveSync_IdlCordLimIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutput_IdlLim();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_SdlFast_PFuAcqIf                                     */
/* !Description :  Moniteur rapide pour l'acquisition de la pression rail .   */
/* !Number      :  SCH15.8                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_pFuMes();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Ext_bRun;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_SdlFast_PFuAcqIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_SdlFast_PFuAcqIf(void)
{
   boolean bLocalCtrl_bAcv_PFuAcq;
   boolean bLocalMoteur_synchronise;
   boolean bLocalExt_bRun;


   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);
      VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);

      if (bLocalCtrl_bAcv_PFuAcq != 0)
      {
         if (  (bLocalMoteur_synchronise == 0)
            || (bLocalExt_bRun == 0))
         {
            IFAIRSYSIGSYS_vidOutput_pFuMes();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn592_FHCanF592If                                  */
/* !Description :  Evenement de réception de trames CAN                       */
/* !Number      :  SCH15.9                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutNotAvlBatMes();                      */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_iBattMes();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn592_FHCanF592If                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn592_FHCanF592If(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutNotAvlBatMes();
      IFAIRSYSIGSYS_vidOutput_iBattMes();
   }
}

/*-------------------------------- end of file -------------------------------*/