/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SENO2DSACTEST                                           */
/* !Description     : SENO2DSACTEST Component                                 */
/*                                                                            */
/* !Module          : SENO2DSACTEST                                           */
/* !Description     : TEST ACTIONNEUR  SONDE O2 AVAL                          */
/*                                                                            */
/* !File            : SENO2DSACTEST_SCH.C                                     */
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
/*   1 / HeatSenO2_EveRst_ActrTSO2Ds                                          */
/*   2 / HeatSenO2_SdlFast_ActrTSO2Ds                                         */
/*                                                                            */
/* !Reference   : V02 NT 09 01049 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HeatSenO2/SENO2DSACTEST/SENO2DSA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SENO2DSACTEST.h"
#include "SENO2DSACTEST_L.h"
#include "SENO2DSACTEST_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRst_ActrTSO2Ds                                */
/* !Description :  Evènement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01049_001.01                                     */
/*                 VEMS_R_09_01049_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DSACTEST_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger    :     HeatSenO2_EveRst_ActrTSO2Ds                              */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRst_ActrTSO2Ds(void)
{
   SENO2DSACTEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_ActrTSO2Ds                               */
/* !Description :  Moniteur rapide de la fonction HeatSenO2                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01049_001.01                                     */
/*                 VEMS_R_09_01049_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SENO2DSACTEST_vidSO2DsTst();                             */
/*  input uint8 SENO2DSACTEST_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger    :     HeatSenO2_SdlFast_ActrTSO2Ds                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_ActrTSO2Ds(void)
{
   if (SENO2DSACTEST_u8Inhib != 0x5A)
   {
      SENO2DSACTEST_vidSO2DsTst();
   }
}
/*--------------------------------- end of file ------------------------------*/