/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRSCTLINTREATIF                                         */
/* !Description     : CRSCTLINTREATIF component.                              */
/*                                                                            */
/* !Module          : CRSCTLINTREATIF                                         */
/* !Description     : SPECIFICATION D’INTERFACE POUR LES BESOINS DE LA XVV    */
/*                                                                            */
/* !File            : CRSCTLINTREATIF_SCH.C                                   */
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
/*   1 / CrsCtl_EveRst_CrsCtlInTreatIf                                        */
/*   2 / CrsCtl_SdlFast_CrsCtlInTreatIf                                       */
/*   3 / CrsCtl_SdlSlow_CrsCtlInTreatIf                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 06065 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLINTREATIF/CRSCTLINT$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   03 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   03 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CRSCTLINTREATIF.h"
#include "CRSCTLINTREATIF_L.h"
#include "CRSCTLINTREATIF_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_EveRst_CrsCtlInTreatIf                              */
/* !Description :  Evenement reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_06065_001.01                                     */
/*                 VEMS_E_11_06065_002.01                                     */
/*                 VEMS_E_11_06065_003.01                                     */
/*                 VEMS_E_11_06065_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLINTREATIF_vidInit();                               */
/*  extf argret void CRSCTLINTREATIF_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrsCtl_EveRst_CrsCtlInTreatIf                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_EveRst_CrsCtlInTreatIf(void)
{
   CRSCTLINTREATIF_vidInit();
   CRSCTLINTREATIF_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_SdlFast_CrsCtlInTreatIf                             */
/* !Description :  Evenement moniteur rapide                                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_06065_001.01                                     */
/*                 VEMS_E_11_06065_002.01                                     */
/*                 VEMS_E_11_06065_003.01                                     */
/*                 VEMS_E_11_06065_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLINTREATIF_vidAuth_clc();                           */
/*  extf argret void CRSCTLINTREATIF_vidOutClunGearEg();                      */
/*  input uint8 CRSCTLINTREATIF_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrsCtl_SdlFast_CrsCtlInTreatIf                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_SdlFast_CrsCtlInTreatIf(void)
{
   if (CRSCTLINTREATIF_u8Inhib != 0x5A)
   {
      CRSCTLINTREATIF_vidAuth_clc();
      CRSCTLINTREATIF_vidOutClunGearEg();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_SdlSlow_CrsCtlInTreatIf                             */
/* !Description :  Evenement SdlSlow                                          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_06065_003.01                                     */
/*                 VEMS_E_11_06065_013.01                                     */
/*                 VEMS_E_11_06065_001.01                                     */
/*                 VEMS_E_11_06065_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLINTREATIF_vidCrsCtl_Can();                         */
/*  extf argret void CRSCTLINTREATIF_vidCrsctl();                             */
/*  input uint8 CRSCTLINTREATIF_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrsCtl_SdlSlow_CrsCtlInTreatIf                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_SdlSlow_CrsCtlInTreatIf(void)
{
   if (CRSCTLINTREATIF_u8Inhib != 0x5A)
   {
      CRSCTLINTREATIF_vidCrsCtl_Can();
      CRSCTLINTREATIF_vidCrsctl();
   }
}
/*------------------------------- end of file --------------------------------*/