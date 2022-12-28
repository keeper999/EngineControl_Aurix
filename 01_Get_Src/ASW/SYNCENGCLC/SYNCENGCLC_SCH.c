/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCENGCLC                                              */
/* !Description     : SYNCENGCLC Component                                    */
/*                                                                            */
/* !Module          : SYNCENGCLC                                              */
/* !Description     : CALCUL DU REGIME RECENTRE.                              */
/*                                                                            */
/* !File            : SYNCENGCLC_SCH.C                                        */
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
/*   1 / Sync_EveRst_NEngClc                                                  */
/*   2 / Sync_SdlMid_NEngClc                                                  */
/*   3 / Sync_SdlSlow_NEngClc                                                 */
/*   4 / Sync_EveTDC_NEngClc                                                  */
/*   5 / Sync_EveWrAdaptSpdTar_NEngClc                                        */
/*   6 / Sync_EveBDC_NEngClc                                                  */
/*                                                                            */
/* !Reference   : V02 NT 09 06456 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SYNC/SYNCENGCLC/SYNCENGCLC_SCH.C$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   07 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "SYNCENGCLC.H"
#include "SYNCENGCLC_L.H"
#include "SYNCENGCLC_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_NEngClc                                        */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidCalculAreaEngClc();                        */
/*  extf argret void SYNCENGCLC_vidResetnEngClc();                            */
/*  extf argret void SYNCENGCLC_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_NEngClc                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_NEngClc(void)
{
   SYNCENGCLC_vidCalculAreaEngClc();
   SYNCENGCLC_vidResetnEngClc();
   SYNCENGCLC_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlMid_NEngClc                                        */
/* !Description :  Scheduler moyen de la fonction Sync.                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidActLearningCorr();                         */
/*  input uint8 SYNCENGCLC_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlMid_NEngClc                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlMid_NEngClc(void)
{
   if (SYNCENGCLC_u8Inhib != 0x5A)
   {
      SYNCENGCLC_vidActLearningCorr();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlSlow_NEngClc                                       */
/* !Description :  Scheduler lent de la fonction Sync.                        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidCalculAreaEngClc();                        */
/*  input uint8 SYNCENGCLC_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlSlow_NEngClc                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlSlow_NEngClc(void)
{
   if (SYNCENGCLC_u8Inhib != 0x5A)
   {
      SYNCENGCLC_vidCalculAreaEngClc();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_NEngClc                                        */
/* !Description :  Interruption PMH.                                          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidCalculCorrEngClc();                        */
/*  extf argret void SYNCENGCLC_vidApplicationCorr();                         */
/*  input uint8 SYNCENGCLC_u8Inhib;                                           */
/*  input boolean Sync_bAcvBDCEngSpdClcn_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_NEngClc                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_NEngClc(void)
{
   if (SYNCENGCLC_u8Inhib != 0x5A)
   {
      if (Sync_bAcvBDCEngSpdClcn_C == 0)
      {
         SYNCENGCLC_vidCalculCorrEngClc();
         SYNCENGCLC_vidApplicationCorr();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveWrAdaptSpdTar_NEngClc                              */
/* !Description :  Évènement demande de mise à jour des données adaptatives   */
/*                 cible régime suite à une requête d'écriture des outils APV.*/
/* !Number      :  SCH.5                                                      */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidEcritureAdapt();                           */
/*  input uint8 SYNCENGCLC_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveWrAdaptSpdTar_NEngClc                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveWrAdaptSpdTar_NEngClc(void)
{
   if (SYNCENGCLC_u8Inhib != 0x5A)
   {
      SYNCENGCLC_vidEcritureAdapt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveBDC_NEngClc                                        */
/* !Description :  Evènement Point Mort Bas (PMB / BDC)                       */
/* !Number      :  SCH.6                                                      */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidCalculCorrEngClc();                        */
/*  extf argret void SYNCENGCLC_vidApplicationCorr();                         */
/*  input uint8 SYNCENGCLC_u8Inhib;                                           */
/*  input boolean Sync_bAcvBDCEngSpdClcn_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveBDC_NEngClc                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveBDC_NEngClc(void)
{
   if (SYNCENGCLC_u8Inhib != 0x5A)
   {
      if (Sync_bAcvBDCEngSpdClcn_C != 0)
      {
         SYNCENGCLC_vidCalculCorrEngClc();
         SYNCENGCLC_vidApplicationCorr();
      }
   }
}

/*------------------------------end of file-----------------------------------*/