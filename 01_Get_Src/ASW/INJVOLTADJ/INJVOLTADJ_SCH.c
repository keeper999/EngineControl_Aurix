/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJVOLTADJ                                              */
/* !Description     : INJVOLTADJ Component                                    */
/*                                                                            */
/* !Module          : INJVOLTADJ                                              */
/* !Description     : VOLTAGE BOOST REQUEST FOR INJECTION SYSTEM              */
/*                                                                            */
/* !File            : INJVOLTADJ_SCH.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / INJVOLTADJ_vidEntryInit                                              */
/*   2 / Volt_EveInj_InjVoltAdj                                               */
/*   3 / Volt_EveSpl_InjVoltAdj                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5074748 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#059782                                         */
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
#include "INJVOLTADJ.h"
#include "INJVOLTADJ_L.h"
#include "INJVOLTADJ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJVOLTADJ_vidEntryInit                                    */
/* !Description :  Evénement Reset du module INJVOLTADJ                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJVOLTADJ_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : INJVOLTADJ_vidEntryInit                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJVOLTADJ_vidEntryInit(void)
{
   INJVOLTADJ_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Volt_EveInj_InjVoltAdj                                     */
/* !Description :  Injection Event for InjVoltAdj                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_05229_001.01                                     */
/*                 VEMS_E_11_05229_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJVOLTADJ_vidInjVoltAdj();                              */
/*  input uint8 INJVOLTADJ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Volt_EveInj_InjVoltAdj                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Volt_EveInj_InjVoltAdj(void)
{
   if (INJVOLTADJ_u8Inhib != 0x5A)
   {
      INJVOLTADJ_vidInjVoltAdj();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Volt_EveSpl_InjVoltAdj                                     */
/* !Description :  Spill Event for InjVoltAdj                                 */
/* !Number      :  SCH.3                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_05229_001.01                                     */
/*                 VEMS_E_11_05229_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJVOLTADJ_vidInjVoltAdj();                              */
/*  input uint8 INJVOLTADJ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Volt_EveSpl_InjVoltAdj                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Volt_EveSpl_InjVoltAdj(void)
{
   if (INJVOLTADJ_u8Inhib != 0x5A)
   {
      INJVOLTADJ_vidInjVoltAdj();
   }
}
/*------------------------------- end of file --------------------------------*/