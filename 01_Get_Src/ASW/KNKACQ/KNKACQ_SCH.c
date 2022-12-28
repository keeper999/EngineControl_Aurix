/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKACQ                                                  */
/* !Description     : KNKACQ component                                        */
/*                                                                            */
/* !Module          : KNKACQ                                                  */
/* !Description     : Knock signal acquisition parameter configuration        */
/*                                                                            */
/* !File            : KNKACQ_SCH.C                                            */
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
/*   1 / KnkTreat_EveRst_KnkAcq                                               */
/*   2 / KnkTreat_EveKnk_KnkAcqLst                                            */
/*   3 / KnkTreat_EveCkSnOn_KnkAcq                                            */
/*   4 / KnkTreat_SdlFast_KnkAcq                                              */
/*   5 / KnkTreat_EveRTSt_KnkAcq                                              */
/*   6 / KnkTreat_EveCkSnOf_KnkAcq                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5066621 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKACQ/KNKACQ_SCH$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   15 Feb 2013 $*/
/* $Author::   etsasson                               $$Date::   15 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KNKACQ.h"
#include "KNKACQ_L.h"
#include "KNKACQ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_KnkAcq                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQ_vidInitOutput();                                  */
/*  extf argret void KNKACQ_vidConfigParametersInit();                        */
/*  input boolean Autorise_clq_num;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_KnkAcq                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_KnkAcq(void)
{
   KNKACQ_vidInitOutput();
   if (Autorise_clq_num != 0)
   {
      KNKACQ_vidConfigParametersInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_KnkAcqLst                                  */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours.                                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQ_vidEndKnoksTaskTreatment();                       */
/*  input uint8 KNKACQ_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TKnkTreat_EveKnk_KnkAcqLst                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_KnkAcqLst(void)
{
   if (KNKACQ_u8Inhib != 0x5A)
   {
      KNKACQ_vidEndKnoksTaskTreatment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOn_KnkAcq                                  */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQ_vidTemporalTreatment();                           */
/*  input uint8 KNKACQ_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOn_KnkAcq                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOn_KnkAcq(void)
{
   if (KNKACQ_u8Inhib != 0x5A)
   {
      KNKACQ_vidTemporalTreatment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlFast_KnkAcq                                    */
/* !Description :  Moniteur Rapide .                                          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQ_vidTemporalTreatment();                           */
/*  input uint8 KNKACQ_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/* !Trigger  : KnkTreat_SdlFast_KnkAcq                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlFast_KnkAcq(void)
{
   if (KNKACQ_u8Inhib != 0x5A)
   {
      KNKACQ_vidTemporalTreatment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRTSt_KnkAcq                                    */
/* !Description :  Fonction d'accroche à l'événement correspondant au passage */
/*                 à 0 de la variable Moteur_tournant                         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQ_vidConfigParametersInit();                        */
/*  input uint8 KNKACQ_u8Inhib;                                               */
/*  input boolean Autorise_clq_num;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRTSt_KnkAcq                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRTSt_KnkAcq(void)
{
   if (KNKACQ_u8Inhib != 0x5A)
   {
      if (Autorise_clq_num != 0)
      {
         KNKACQ_vidConfigParametersInit();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOf_KnkAcq                                  */
/* !Description :  Evénement d'appel de tâche "synchro perdue" du CMM.        */
/* !Number      :  SCH.6                                                      */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQ_vidConfigParametersInit();                        */
/*  input uint8 KNKACQ_u8Inhib;                                               */
/*  input boolean Autorise_clq_num;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOf_KnkAcq                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOf_KnkAcq(void)
{
   if (KNKACQ_u8Inhib != 0x5A)
   {
      if (Autorise_clq_num != 0)
      {
         KNKACQ_vidConfigParametersInit();
      }
   }
}
/*------------------------------- end of file --------------------------------*/