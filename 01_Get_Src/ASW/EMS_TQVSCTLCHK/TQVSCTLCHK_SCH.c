/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQVSCTLCHK                                              */
/* !Description     : TQVSCTLCHK Component                                    */
/*                                                                            */
/* !Module          : TQVSCTLCHK                                              */
/* !Description     : SAFETY TMS : SECURISER RVV                              */
/*                                                                            */
/* !File            : TQVSCTLCHK_SCH.C                                        */
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
/*   1 / TQVSCTLCHK_vidEntryInit                                              */
/*   2 / SftyMgt_SdlMid_TqVSCtlChk                                            */
/*                                                                            */
/* !Reference   : V02 NT 11 01190 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2401 / 1.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQVSCTLCHK/TQVSCTLCHK_$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQVSCTLCHK.h"
#include "TQVSCTLCHK_L.h"
#include "TQVSCTLCHK_IM.H"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQVSCTLCHK_vidEntryInit                                    */
/* !Description :  Evénement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQVSCTLCHK_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQVSCTLCHK_vidEntryInit                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQVSCTLCHK_vidEntryInit(void)
{
   TQVSCTLCHK_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_TqVSCtlChk                                  */
/* !Description :  évenement de déclenchement de la fonction de surveillance  */
/*                 de  la pédale de frein                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_01190_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQVSCTLCHK_vidDesacRVVAppuiFrein();                      */
/*  input uint8 TQVSCTLCHK_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_TqVSCtlChk                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_TqVSCtlChk(void)
{
   if (TQVSCTLCHK_u8Inhib != 0x5A)
   {
      TQVSCTLCHK_vidDesacRVVAppuiFrein();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/