/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTQSTRUCTMNGT                                         */
/* !Description     : AIRTQSTRUCTMNGT component                               */
/*                                                                            */
/* !Module          : AIRTQSTRUCTMNGT                                         */
/* !Description     : MANAGER DES ÉTATS DE LA STRUCTURE COUPLE                */
/*                                                                            */
/* !File            : AIRTQSTRUCTMNGT_SCH.c                                   */
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
/*   1 / CrkMgt_EveRst_AirTqStructMngt                                        */
/*   2 / CrkMgt_SdlMid_AirTqStructMngt                                        */
/*   3 / CrkMgt_SdlFast_AirTqStructMngt                                       */
/*                                                                            */
/* !Reference   : PTS DOC 5015877 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/AIRTQSTRUCTMNGT/AIRTQSTRUC$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   24 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "AIRTQSTRUCTMNGT.h"
#include "AIRTQSTRUCTMNGT_L.h"
#include "AIRTQSTRUCTMNGT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrkMgt_EveRst_AirTqStructMngt                              */
/* !Description :  évenement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_08_04993_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQSTRUCTMNGT_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrkMgt_EveRst_AirTqStructMngt                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrkMgt_EveRst_AirTqStructMngt(void)
{
   AIRTQSTRUCTMNGT_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrkMgt_SdlMid_AirTqStructMngt                              */
/* !Description :  moniteur moyen                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_08_04993_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQSTRUCTMNGT_vidCalcSecCrOffs();                      */
/*  input uint8 AIRTQSTRUCTMNGT_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrkMgt_SdlMid_AirTqStructMngt                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrkMgt_SdlMid_AirTqStructMngt(void)
{
   if (AIRTQSTRUCTMNGT_u8Inhib != 0x5A)
   {
      AIRTQSTRUCTMNGT_vidCalcSecCrOffs();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrkMgt_SdlFast_AirTqStructMngt                             */
/* !Description :  moniteur rapide                                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_08_04993_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQSTRUCTMNGT_vidManager();                            */
/*  input uint8 AIRTQSTRUCTMNGT_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrkMgt_SdlFast_AirTqStructMngt                                 */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrkMgt_SdlFast_AirTqStructMngt(void)
{
   if (AIRTQSTRUCTMNGT_u8Inhib != 0x5A)
   {
      AIRTQSTRUCTMNGT_vidManager();
   }
}

/*------------------------------- end of file --------------------------------*/