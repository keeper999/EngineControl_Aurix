/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ALDALTCOR                                               */
/* !Description     : ALDALTCOR Component                                     */
/*                                                                            */
/* !Module          : ALDALTCOR                                               */
/* !Description     : Correction altimétrique de la charge en air             */
/*                                                                            */
/* !File            : ALDALTCOR_SCH.C                                         */
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
/*   1 / ALDALTCOR_vidEntryInit                                               */
/*   2 / VlvSys_SdlFast_AltiCor                                               */
/*                                                                            */
/* !Reference   : V02 NT 11 02165 / 01                                        */
/* !OtherRefs   : CSMT_CGMT09_2173_2 / 01                                     */
/* !OtherRefs   : VEMS V02 ECU#053821                                         */
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
#include "ALDALTCOR.h"
#include "ALDALTCOR_L.h"
#include "ALDALTCOR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ALDALTCOR_vidEntryInit                                     */
/* !Description :  Evénement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_02165_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ALDALTCOR_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ALDALTCOR_vidEntryInit                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ALDALTCOR_vidEntryInit(void)
{
   ALDALTCOR_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvSys_SdlFast_AltiCor                                     */
/* !Description :  Fonction d'accroche à l'event VlvSys_SdlFast_AltiCor       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_02165_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ALDALTCOR_vidAlticor();                                  */
/*  input uint8 ALDALTCOR_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvSys_SdlFast_AltiCor                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvSys_SdlFast_AltiCor(void)
{
   if (ALDALTCOR_u8Inhib != 0x5A)
   {
      ALDALTCOR_vidAlticor();
   }
}

/*------------------------------- end of file --------------------------------*/