/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFWINACQ                                              */
/* !Description     : MISFWINACQ Component                                    */
/*                                                                            */
/* !Module          : MISFWINACQ                                              */
/* !Description     : ACQUISITION DES FENETRES MISFIRE                        */
/*                                                                            */
/* !File            : MISFWINACQ_SCH.c                                        */
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
/*   1 / Misf_EveRst_MisfWinAcq                                               */
/*   2 / Misf_EveCkSnOn_MisfWinAcq                                            */
/*   3 / Misf_SdlFast_MisfWinAcq                                              */
/*   4 / Misf_EveCkSnOf_MisfWinAcq                                            */
/*   5 / Misf_EveMisf_MisfWinAcq                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 05081 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFWINACQ/MISFWINACQ_SCH.c_v$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Jan 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MISFWINACQ.H"
#include "MISFWINACQ_l.h"
#include "MISFWINACQ_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRst_MisfWinAcq                                     */
/* !Description :  événement Reset pour la stratégie d'acquisition des        */
/*                 fenêtres                                                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_vidInitOuput();                               */
/*  extf argret void MISFWINACQ_vidinitWintiDly();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Misf_EveRst_MisfWinAcq                                         */
/* !Trigger  : Misf_EveRst_MisfWinAcq                                         */
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRst_MisfWinAcq(void)
{
   MISFWINACQ_vidInitOuput();
   MISFWINACQ_vidinitWintiDly();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveCkSnOn_MisfWinAcq                                  */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_vidMisfAcqSyncActive();                       */
/*  input uint8 MISFWINACQ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Misf_EveCkSnOn_MisfWinAcq                                      */
/* !Trigger  : Misf_EveCkSnOn_MisfWinAcq                                      */
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveCkSnOn_MisfWinAcq(void)
{
   if ( MISFWINACQ_u8Inhib != 0x5A)
   {
      MISFWINACQ_vidMisfAcqSyncActive();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_SdlFast_MisfWinAcq                                    */
/* !Description :  Moniteur rapide pour la fonction Misfire                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_vidMisfAcqSdlActive();                        */
/*  input uint8 MISFWINACQ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Misf_SdlFast_MisfWinAcq                                        */
/* !Trigger  : Misf_SdlFast_MisfWinAcq                                        */
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_SdlFast_MisfWinAcq(void)
{
   if ( MISFWINACQ_u8Inhib != 0x5A)
   {
      MISFWINACQ_vidMisfAcqSdlActive();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveCkSnOf_MisfWinAcq                                  */
/* !Description :  Evénement d'appel de tâche "synchro perdue" du CMM (à la   */
/*                 perte de synchro et au calage)                             */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_vidMisfAcqDesactive();                        */
/*  input uint8 MISFWINACQ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Misf_EveCkSnOf_MisfWinAcq                                      */
/* !Trigger  : Misf_EveCkSnOf_MisfWinAcq                                      */
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveCkSnOf_MisfWinAcq(void)
{
   if ( MISFWINACQ_u8Inhib != 0x5A)
   {
      MISFWINACQ_vidMisfAcqDesactive();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfWinAcq                                    */
/* !Description :  événement misfire pour la stratégie d'acquisition des      */
/*                 fenêtres                                                   */
/* !Number      :  SCH.5                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_vidReadWintiDly();                            */
/*  input uint8 MISFWINACQ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Misf_EveMisf_MisfWinAcq                                        */
/* !Trigger  : Misf_EveMisf_MisfWinAcq                                        */
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfWinAcq(void)
{
   if ( MISFWINACQ_u8Inhib != 0x5A)
   {
      MISFWINACQ_vidReadWintiDly();
   }
}

/*-------------------------------end of file----------------------------------*/