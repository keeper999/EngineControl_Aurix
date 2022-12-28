/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKRBLACQ                                               */
/* !Description     : KNKRBLACQ component                                     */
/*                                                                            */
/* !Module          : KNKRBLACQ                                               */
/* !Description     : RUMBLE SIGNAL ACQUISITION PARAMETER CONFIGURATION       */
/*                                                                            */
/* !File            : KnkRblAcq_sch.c                                         */
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
/*   1 / KnkTreat_EveRst_KnkRblAcq                                            */
/*   2 / KnkTreat_SdlFast_KnkRblAcq                                           */
/*   3 / KnkTreat_EveCkSnOn_KnkRblAcq                                         */
/*   4 / KnkTreat_EveRbl_KnkRblAcqLst                                         */
/*   5 / KnkTreat_EveRTSt_KnkRblAcq                                           */
/*   6 / KnkTreat_EveCkSnOf_KnkRblAcq                                         */
/*                                                                            */
/* !Reference   : V02 NT 12 02237 / 03                                        */
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

#include "KNKRBLACQ.H"
#include "KNKRBLACQ_L.H"
#include "KNKRBLACQ_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_KnkRblAcq                                  */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BARHOUMI                                                   */
/* !Trace_To    :  VEMS_E_10_02579_001.03                                     */
/*                 VEMS_E_10_02579_004.02                                     */
/*                 VEMS_E_10_02579_005.01                                     */
/*                 VEMS_E_10_02579_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKRBLACQ_vidInitOutput();                               */
/*  extf argret void KNKRBLACQ_vidInitConfigParam();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_KnkRblAcq                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_KnkRblAcq(void)
{
   KNKRBLACQ_vidInitOutput();
   KNKRBLACQ_vidInitConfigParam();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlFast_KnkRblAcq                                 */
/* !Description :  Moniteur Rapide                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BARHOUMI                                                   */
/* !Trace_To    :  VEMS_E_10_02579_001.03                                     */
/*                 VEMS_E_10_02579_004.02                                     */
/*                 VEMS_E_10_02579_005.01                                     */
/*                 VEMS_E_10_02579_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKRBLACQ_vidTemporalTreatment();                        */
/*  input uint8 KNKRBLACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlFast_KnkRblAcq                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlFast_KnkRblAcq(void)
{
   if (KNKRBLACQ_u8Inhib != 0x5A)
   {
      KNKRBLACQ_vidTemporalTreatment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOn_KnkRblAcq                               */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  BARHOUMI                                                   */
/* !Trace_To    :  VEMS_E_10_02579_001.03                                     */
/*                 VEMS_E_10_02579_004.02                                     */
/*                 VEMS_E_10_02579_005.01                                     */
/*                 VEMS_E_10_02579_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKRBLACQ_vidTemporalTreatment();                        */
/*  input uint8 KNKRBLACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOn_KnkRblAcq                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOn_KnkRblAcq(void)
{
   if (KNKRBLACQ_u8Inhib != 0x5A)
   {
      KNKRBLACQ_vidTemporalTreatment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRbl_KnkRblAcqLst                               */
/* !Description :  Tâche de calcul du niveau de rumble pour le cylindre en    */
/*                 cours.                                                     */
/* !Number      :  SCH.4                                                      */
/* !Author      :  BARHOUMI                                                   */
/* !Trace_To    :  VEMS_E_10_02579_001.03                                     */
/*                 VEMS_E_10_02579_004.02                                     */
/*                 VEMS_E_10_02579_005.01                                     */
/*                 VEMS_E_10_02579_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKRBLACQ_vidRblTaskEndTreatment();                      */
/*  input uint8 KNKRBLACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRbl_KnkRblAcqLst                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRbl_KnkRblAcqLst(void)
{
   if (KNKRBLACQ_u8Inhib != 0x5A)
   {
      KNKRBLACQ_vidRblTaskEndTreatment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRTSt_KnkRblAcq                                 */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.5                                                      */
/* !Author      :  BARHOUMI                                                   */
/* !Trace_To    :  VEMS_E_10_02579_001.03                                     */
/*                 VEMS_E_10_02579_004.02                                     */
/*                 VEMS_E_10_02579_005.01                                     */
/*                 VEMS_E_10_02579_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKRBLACQ_vidInitConfigParam();                          */
/*  input uint8 KNKRBLACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRTSt_KnkRblAcq                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRTSt_KnkRblAcq(void)
{
   if (KNKRBLACQ_u8Inhib != 0x5A)
   {
      KNKRBLACQ_vidInitConfigParam();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOf_KnkRblAcq                               */
/* !Description :  Event corresponding to the loss of synchronisation         */
/* !Number      :  SCH.6                                                      */
/* !Author      :  BARHOUMI                                                   */
/* !Trace_To    :  VEMS_E_10_02579_001.03                                     */
/*                 VEMS_E_10_02579_004.02                                     */
/*                 VEMS_E_10_02579_005.01                                     */
/*                 VEMS_E_10_02579_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKRBLACQ_vidInitConfigParam();                          */
/*  input uint8 KNKRBLACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOf_KnkRblAcq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOf_KnkRblAcq(void)
{
   if (KNKRBLACQ_u8Inhib != 0x5A)
   {
      KNKRBLACQ_vidInitConfigParam();
   }
}
/*------------------------------ end of file ---------------------------------*/