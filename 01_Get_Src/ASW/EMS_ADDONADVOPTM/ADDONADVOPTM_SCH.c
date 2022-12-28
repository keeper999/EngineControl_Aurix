/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVOPTM                                            */
/* !Description     : ADDONADVOPTM component                                  */
/*                                                                            */
/* !Module          : ADDONADVOPTM                                            */
/* !Description     : TRAITEMENT TRAME 34DH                                   */
/*                                                                            */
/* !File            : ADDONADVOPTM_SCH.C                                      */
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
/*   1 / ADDONADVOPTM_vidEntryInit                                            */
/*   2 / IgSys_EveTDC_AddOnAdvOptm                                            */
/*                                                                            */
/* !Reference   : V02 NT 11 01474 / 01                                        */
/* !OtherRefs   : 01460_10_04403_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053829                                         */
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
#include "ADDONADVOPTM.h"
#include "ADDONADVOPTM_L.h"
#include "ADDONADVOPTM_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidEntryInit                                  */
/* !Description :  Evènement pour la fonction initialisation                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVOPTM_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ADDONADVOPTM_vidInitOutput                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidEntryInit(void)
{
   ADDONADVOPTM_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveTDC_AddOnAdvOptm                                  */
/* !Description :  Accroche moniteur pour le module ADDONADVOPTM              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVOPTM_vidOffset_AAO();                            */
/*  input uint8 ADDONADVOPTM_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveTDC_AddOnAdvOptm                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveTDC_AddOnAdvOptm(void)
{
   if (ADDONADVOPTM_u8Inhib != 0x5A)
   {
      ADDONADVOPTM_vidOffset_AAO();
   }
}

/*--------------------------------- end of file ------------------------------*/