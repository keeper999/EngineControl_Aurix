/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPPERDDIAG                                     */
/* !Description     : HEATSENO2UPPERDDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPPERDDIAG                                     */
/* !Description     : DIAGNOSTIC DE LA SONDE A OXYGENE AMONT                  */
/*                                                                            */
/* !File            : HEATSENO2UPPERDDIAG_SCH.C                               */
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
/*   1 / SenO2Us_EveRst_PerDiag                                               */
/*   2 / SenO2Us_SdlFast_PerDiag                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5012863 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPPERDDIA$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "HEATSENO2UPPERDDIAG.h"
#include "HEATSENO2UPPERDDIAG_L.h"
#include "HEATSENO2UPPERDDIAG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_EveRst_PerDiag                                     */
/* !Description :  Evènement reset du calculateur pour la fonction Sen02Us    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_08083_002.01                                     */
/*                 VEMS_R_11_08083_003.01                                     */
/*                 VEMS_R_11_08083_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPPERDDIAG_vidIniOutput();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidIniTimers();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidInit();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_EveRst_PerDiag                                         */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_EveRst_PerDiag(void)
{
   HEATSENO2UPPERDDIAG_vidIniOutput();
   HEATSENO2UPPERDDIAG_vidIniTimers();
   HEATSENO2UPPERDDIAG_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlFast_PerDiag                                    */
/* !Description :  Moniteur rapide de la fonction SenO2Us                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_08083_002.01                                     */
/*                 VEMS_R_11_08083_003.01                                     */
/*                 VEMS_R_11_08083_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPPERDDIAG_vidDiagCond();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidStateMgr();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCounters();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidDiagCompl();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidPMonitor();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidApvPMonit();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidTgInitTrn();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidPerDgSens();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidPerDgApv();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidcallGDU();                        */
/*  input uint8 HEATSENO2UPPERDDIAG_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_SdlFast_PerDiag                                        */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlFast_PerDiag(void)
{
   if (HEATSENO2UPPERDDIAG_u8Inhib != 0x5A)
   {
      HEATSENO2UPPERDDIAG_vidDiagCond();
      HEATSENO2UPPERDDIAG_vidStateMgr();
      HEATSENO2UPPERDDIAG_vidCounters();
      HEATSENO2UPPERDDIAG_vidDiagCompl();
      HEATSENO2UPPERDDIAG_vidPMonitor();
      HEATSENO2UPPERDDIAG_vidApvPMonit();
      HEATSENO2UPPERDDIAG_vidTgInitTrn();
      HEATSENO2UPPERDDIAG_vidPerDgSens();
      HEATSENO2UPPERDDIAG_vidPerDgApv();
      HEATSENO2UPPERDDIAG_vidcallGDU();
   }
}

/*------------------------------- end of file --------------------------------*/