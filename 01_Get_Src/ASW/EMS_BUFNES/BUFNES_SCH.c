/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BUFNES                                                  */
/* !Description     : BUFNES component.                                       */
/*                                                                            */
/* !Module          : BUFNES                                                  */
/* !Description     : RECORD THE CRANKSHAFT TEETH DURATION.                   */
/*                                                                            */
/* !File            : BUFNES_SCH.C                                            */
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
/*   1 / BufNEs_vidEntryInit                                                  */
/*   2 / BufNEs_EveCgt_BufNEs                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 01163 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_3145 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053616                                         */
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
#include "BUFNES.h"
#include "BUFNES_L.h"
#include "BUFNES_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BufNEs_vidEntryInit                                        */
/* !Description :  Evenement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01163_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BUFNES_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BufNEs_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BufNEs_vidEntryInit(void)
{
   BUFNES_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BufNEs_EveCgt_BufNEs                                       */
/* !Description :  Moniteur du module BUFNES                                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01163_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BUFNES_vidGlobal_View();                                 */
/*  input uint8 BUFNES_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BufNEs_EveCgt_BufNEs                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BufNEs_EveCgt_BufNEs(void)
{
   if (BUFNES_u8Inhib != 0x5A)
   {
      BUFNES_vidGlobal_View();
   }
}
/*------------------------------end-of-file-----------------------------------*/