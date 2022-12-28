/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TIENGSTOP                                               */
/* !Description     : TIENGSTOP Component                                     */
/*                                                                            */
/* !Module          : TIENGSTOP                                               */
/* !Description     : DUREE D’ARRET MOTEUR                                    */
/*                                                                            */
/* !File            : TIENGSTOP_SCH.c                                         */
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
/*   1 / EngSt_EveRst_TiEngStop                                               */
/*   2 / EngSt_SdlMid_TiEngStop                                               */
/*   3 / EngSt_EveRxn552_TiEngStop                                            */
/*   4 / EngSt_SdlSlow_TiEngStop                                              */
/*   5 / EngSt_EveRTSt_TiEngStop                                              */
/*   6 / EngSt_EvePwrl_TiEngStop                                              */
/*   7 / EngSt_EveRxn552bis_TiEngStop                                         */
/*   8 / EngSt_SdlFast_TiEngStop                                              */
/*   9 / Can_EveRxn5B2_TiEngStop                                              */
/*   10 / Can_EveRxn7F2_TiEngStop                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5329313 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/TIENGSTOP/TIENGSTOP_SCH.C_$*/
/* $Revision::   1.7      $$Author::   HHAMLAOU       $$Date::   02 Jul 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   02 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "TIENGSTOP.h"
#include "TIENGSTOP_L.h"
#include "TIENGSTOP_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_TiEngStop                                     */
/* !Description :  Cette fonction permet l'initialisation des sorties au reset*/
/*                 du calculateur.                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidInitOutput();                               */
/*  extf argret void TIENGSTOP_vidInitialisation();                           */
/*  extf argret void TIENGSTOP_vidDegradedPeriodEstim();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_TiEngStop                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_TiEngStop(void)
{
   TIENGSTOP_vidInitOutput();
   TIENGSTOP_vidInitialisation();
   TIENGSTOP_vidDegradedPeriodEstim();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlMid_TiEngStop                                     */
/* !Description :  Moniteur moyen pour la fonction EngSt.                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidEmfSaveLastAlarmClk();                      */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlMid_TiEngStop                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlMid_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidEmfSaveLastAlarmClk();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRxn552_TiEngStop                                  */
/* !Description :  Evènement correspondent à la reception de la trame 552h.   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidEmfDate();                                  */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRxn552_TiEngStop                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRxn552_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidEmfDate();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlSlow_TiEngStop                                    */
/* !Description :  Moniteur lent pour la fonction EngSt                       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidDegradedPeriodEstim();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*  input boolean EOM_bDgoORng_tiEngStop;                                     */
/*  input boolean EOM_bMonRunORng_tiEngStop;                                  */
/*  input boolean EOM_bDgoCoh_tiEngStop;                                      */
/*  input boolean EOM_bMonRunCoh_tiEngStop;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlSlow_TiEngStop                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlSlow_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidDegradedPeriodEstim();
      GDGAR_vidGdu(GD_DFT_ORNG_TIENGSTOP,
                   EOM_bDgoORng_tiEngStop,
                   EOM_bMonRunORng_tiEngStop,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COH_TIENGSTOP,
                   EOM_bDgoCoh_tiEngStop,
                   EOM_bMonRunCoh_tiEngStop,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRTSt_TiEngStop                                    */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.5                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidRazTimeSinceStall();                        */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRTSt_TiEngStop                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRTSt_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidRazTimeSinceStall();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EvePwrl_TiEngStop                                    */
/* !Description :  Evénement powerlatch                                       */
/* !Number      :  SCH.6                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidEmfSaveLastStopDate();                      */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EvePwrl_TiEngStop                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EvePwrl_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidEmfSaveLastStopDate();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRxn552bis_TiEngStop                               */
/* !Description :  Evènement correspondent à la reception de la trame 552bis  */
/* !Number      :  SCH.7                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidEmfDate();                                  */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRxn552bis_TiEngStop                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRxn552bis_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidEmfDate();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_TiEngStop                                    */
/* !Description :  Moniteur rapide pour la fonction EngSt                     */
/* !Number      :  SCH.8                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidChangeOfMind();                             */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_TiEngStop                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidChangeOfMind();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn5B2_TiEngStop                                    */
/* !Description :  Evènement de réception de la trame CAN 5B2.                */
/* !Number      :  SCH.9                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidFrameTairCAN();                             */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn5B2_TiEngStop                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn5B2_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidFrameTairCAN();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn7F2_TiEngStop                                    */
/* !Description :  Evènement de réceprion de la trame CAN 7F2.                */
/* !Number      :  SCH.10                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_12_01073_015.01                                     */
/*                 VEMS_E_12_01073_016.01                                     */
/*                 VEMS_E_12_01073_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIENGSTOP_vidFrameTairCAN();                             */
/*  input uint8 TIENGSTOP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn7F2_TiEngStop                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn7F2_TiEngStop(void)
{
   if (TIENGSTOP_u8Inhib != 0x5A)
   {
      TIENGSTOP_vidFrameTairCAN();
   }
}
/*-------------------------------End Of File----------------------------------*/