/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGVOLTADJ                                               */
/* !Description     : IGVOLTADJ component.                                    */
/*                                                                            */
/* !Module          : IGVOLTADJ                                               */
/* !Description     : VOLTAGE BOOST REQUEST FOR IGNITION SYSTEM               */
/*                                                                            */
/* !File            : IGVOLTADJ_SCH.C                                         */
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
/*   1 / IGVOLTADJ_vidEntryInit                                               */
/*   2 / Volt_SdlFast_IgVoltAdj                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6444206 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068440                                         */
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
#include "IGVOLTADJ.h"
#include "IGVOLTADJ_L.h"
#include "IGVOLTADJ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGVOLTADJ_vidEntryInit                                     */
/* !Description :  Fonction d'accroche Reset                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_11_05231_001.01                                     */
/*                 VEMS_E_11_05231_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGVOLTADJ_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IGVOLTADJ_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGVOLTADJ_vidEntryInit(void)
{
   IGVOLTADJ_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Volt_SdlFast_IgVoltAdj                                     */
/* !Description :  SdlFast for IgVoltAdj                                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_11_05231_001.01                                     */
/*                 VEMS_E_11_05231_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGVOLTADJ_vidIgVoltAdj();                                */
/*  input uint8 IGVOLTADJ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Volt_SdlFast_IgVoltAdj                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Volt_SdlFast_IgVoltAdj(void)
{
   if (IGVOLTADJ_u8Inhib != 0x5A)
   {
      IGVOLTADJ_vidIgVoltAdj();
   }
}
/*-------------------------------- end of file -------------------------------*/