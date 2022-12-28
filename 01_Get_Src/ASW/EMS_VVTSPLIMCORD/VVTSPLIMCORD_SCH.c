/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VVTSPLIMCORD                                            */
/* !Description     : VVTSPLIMCORD component.                                 */
/*                                                                            */
/* !Module          : VVTSPLIMCORD                                            */
/* !Description     : OFFSET T3 SOUPAPE                                       */
/*                                                                            */
/* !File            : VVTSPLIMCORD_SCH.C                                      */
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
/*   1 / VVTSPLIMCORD_vidEntryInit                                            */
/*   2 / ExM_SdlFast_ExOfs                                                    */
/*                                                                            */
/* !Reference   : V02 NT 11 02903 / 01                                        */
/* !OtherRefs   : 01460_10_01471_2 / 1                                        */
/* !OtherRefs   : VEMS V02 ECU#053815                                         */
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

#include "VVTSPLIMCORD.h"
#include "VVTSPLIMCORD_L.h"
#include "VVTSPLIMCORD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidEntryInit                                  */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VVTSPLIMCORD_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VVTSPLIMCORD_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidEntryInit(void)
{
   VVTSPLIMCORD_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ExM_SdlFast_ExOfs                                          */
/* !Description :  Fonction d'accroche au moniteur 10ms                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VVTSPLIMCORD_vidExOfs();                                 */
/*  input uint8 VVTSPLIMCORD_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ExM_SdlFast_ExOfs                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ExM_SdlFast_ExOfs(void)
{
   if (VVTSPLIMCORD_u8Inhib != 0x5A)
   {
      VVTSPLIMCORD_vidExOfs();
   }
}
/*------------------------------end-of-file-----------------------------------*/