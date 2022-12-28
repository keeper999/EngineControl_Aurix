/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCMD                                                  */
/* !Description     : INJCMD Component                                        */
/*                                                                            */
/* !Module          : INJCMD                                                  */
/* !Description     : INTERFACE COMMANDE INJECTEURS ESSENCE                   */
/*                                                                            */
/* !File            : INJCMD_SCH.C                                            */
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
/*   1 / Inj_EveRst_InjCmd                                                    */
/*   2 / Inj_EveCkOff_InjCmd                                                  */
/*   3 / Inj_EveCkSnOf_InjCmd                                                 */
/*   4 / Inj_EveSyncNotAccu_InjCmd                                            */
/*   5 / Inj_EveKOf_InjCmd                                                    */
/*   6 / Inj_EveCrTR_InjCmd                                                   */
/*   7 / Inj_EveStTCr_InjCmd                                                  */
/*   8 / Inj_EveInj_InjCmd                                                    */
/*   9 / Inj_SdlFast_InjCmd                                                   */
/*   10 / Inj_EveSpl_InjCmd                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_6886136 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCMD/INJCMD_SCH.C_v     $*/
/* $Revision::   1.14     $$Author::   mbenfrad       $$Date::   17 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "INJCMD.h"
#include "INJCMD_L.h"
#include "INJCMD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveRst_InjCmd                                          */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidInhibitAllCylinder();                          */
/*  extf argret void INJCMD_vidInitDiag();                                    */
/*  extf argret void INJCMD_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveRst_InjCmd                                              */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveRst_InjCmd(void)
{
   INJCMD_vidInhibitAllCylinder();
   INJCMD_vidInitDiag();
   INJCMD_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveCkOff_InjCmd                                        */
/* !Description :  |                                                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidDisableDriver();                               */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveCkOff_InjCmd                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveCkOff_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidDisableDriver();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveCkSnOf_InjCmd                                       */
/* !Description :  Evénement  d'appel  de  tâche  "synchro  perdue"  du  CMM  */
/*                 (à  la  perte  de  synchro  et  au  calage)                */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidInhibitAllCylinder();                          */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveCkSnOf_InjCmd                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveCkSnOf_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidInhibitAllCylinder();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveSyncNotAccu_InjCmd                                  */
/* !Description :  Evénement indiquant le passage en synchronisation non      */
/*                 précise du moteur                                          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidInitEnable();                                  */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveSyncNotAccu_InjCmd                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveSyncNotAccu_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidInitEnable();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveKOf_InjCmd                                          */
/* !Description :  Evènement associé au passage de clef ON à clef OFF         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidInhibitAllCylinder();                          */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveKOf_InjCmd                                              */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveKOf_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidInhibitAllCylinder();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveCrTR_InjCmd                                         */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.6                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidManInjTime();                                  */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveCrTR_InjCmd                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveCrTR_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidManInjTime();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveStTCr_InjCmd                                        */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.7                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidInitialisationMode();                          */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveStTCr_InjCmd                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveStTCr_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidInitialisationMode();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveInj_InjCmd                                          */
/* !Description :  Tâche INJ pour la commande injection                       */
/* !Number      :  SCH.8                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidManCutByCylinder();                            */
/*  extf argret void INJCMD_vidManInjTime();                                  */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveInj_InjCmd                                              */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveInj_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidManCutByCylinder();
      INJCMD_vidManInjTime();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_SdlFast_InjCmd                                         */
/* !Description :  Moniteur rapide pour la commande des injecteurs            */
/* !Number      :  SCH.9                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidInjectorsDiagnostic();                         */
/*  extf argret void INJCMD_vidManInjTime();                                  */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_SdlFast_InjCmd                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_SdlFast_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidInjectorsDiagnostic();
      INJCMD_vidManInjTime();
   }
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveSpl_InjCmd                                          */
/* !Description :  Evénement "Spill"                                          */
/* !Number      :  SCH.10                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_10_01613_002.01                                     */
/*                 VEMS_E_10_01613_003.01                                     */
/*                 VEMS_E_10_01613_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidManInjTime();                                  */
/*  input uint8 INJCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveSpl_InjCmd                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveSpl_InjCmd(void)
{
   if (INJCMD_u8Inhib != 0x5A)
   {
      INJCMD_vidManInjTime();
   }
}
/*------------------------------- end of file --------------------------------*/
