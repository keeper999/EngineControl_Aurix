/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SENO2USACTEST                                           */
/* !Description     : SENO2USACTEST Component                                 */
/*                                                                            */
/* !Module          : SENO2USACTEST                                           */
/* !Description     : TEST ACTIONNEUR  SONDE O2 AMONT                         */
/*                                                                            */
/* !File            : SENO2USACTEST_SCH.C                                     */
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
/*   1 / HeatSenO2_EveRst_ActrTSO2Us                                          */
/*   2 / HeatSenO2_SdlFast_ActrTSO2Us                                         */
/*                                                                            */
/* !Reference   : V02 NT 08 08131 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HeatSenO2/SENO2USACTEST/SENO2USA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SENO2USACTEST.h"
#include "SENO2USACTEST_L.h"
#include "SENO2USACTEST_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRst_ActrTSO2Us                                */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_08131_001.01                                     */
/*                 VEMS_R_08_08131_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2USACTEST_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger    :     HeatSenO2_EveRst_ActrTSO2Us                              */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRst_ActrTSO2Us(void)
{
   SENO2USACTEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_ActrTSO2Us                               */
/* !Description :  Moniteur rapide de la fonction HeatSenO2                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_08131_001.01                                     */
/*                 VEMS_R_08_08131_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2USACTEST_vidSO2UsTst();                             */
/*  input uint8 SENO2USACTEST_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger    :     HeatSenO2_SdlFast_ActrTSO2Us                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_ActrTSO2Us(void)
{
   if (SENO2USACTEST_u8Inhib != 0x5A)
   {
      SENO2USACTEST_vidSO2UsTst();
   }
}
/*--------------------------------- end of file ------------------------------*/