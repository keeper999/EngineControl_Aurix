/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFFAR                                                   */
/* !Description     : IFFAR component.                                        */
/*                                                                            */
/* !Module          : IFFAR                                                   */
/* !Description     : INTERFACAGE DE LA FONCTION FAR .                        */
/*                                                                            */
/* !File            : IFFAR_SCH.C                                             */
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
/*   1 / Far_EveRst_IfFar                                                     */
/*   2 / RE_FARSp_022_TEVIf                                                   */
/*   3 / SenO2Ds_SdlMid_DsPlausIf                                             */
/*   4 / CatMon_SdlFast_CatAcvDiagIf2                                         */
/*                                                                            */
/* !Reference   : V02 NT 12 01358 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065272                                         */
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
#include "IFFAR.h"
#include "IFFAR_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Far_EveRst_IfFar                                           */
/* !Description :  Evénement reset interfacage du Far                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFFAR_vidInitFar();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Time Far_EveRst_IfFar                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Far_EveRst_IfFar(void)
{
   IFFAR_vidInitFar();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_FARSp_022_TEVIf                                         */
/* !Description :  Evènement du module d'interfacage en aval du FARSp         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFFAR_vidObjRich();                                      */
/*  input uint8 IFFAR_u8Inhib;                                                */
/*  input boolean Far_bAcvIfStrtFar_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_FARSp_022_TEVIf                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_FARSp_022_TEVIf(void)
{
   if (IFFAR_u8Inhib != 0x5A)
   {
      if (Far_bAcvIfStrtFar_C != 0)
      {
         IFFAR_vidObjRich();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlMid_DsPlausIf                                   */
/* !Description :  Moniteur du module d'interfacage en aval du SenO2Ds        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFFAR_vidAcvReqMonItrsv();                               */
/*  input uint8 IFFAR_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlMid_DsPlausIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlMid_DsPlausIf(void)
{
   if (IFFAR_u8Inhib != 0x5A)
   {
      IFFAR_vidAcvReqMonItrsv();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CatMon_SdlFast_CatAcvDiagIf2                               */
/* !Description :  Moniteur du module d'interface en aval du CatMon           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFFAR_vidMixtReqMonItrsv();                              */
/*  input uint8 IFFAR_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CatMon_SdlFast_CatAcvDiagIf2                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CatMon_SdlFast_CatAcvDiagIf2(void)
{
   if (IFFAR_u8Inhib != 0x5A)
   {
      IFFAR_vidMixtReqMonItrsv();
   }
}
/*-------------------------------- end of file -------------------------------*/