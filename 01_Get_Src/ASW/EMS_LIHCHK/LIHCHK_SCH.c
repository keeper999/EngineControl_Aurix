/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : LIHCHK                                                  */
/* !Description     : LIHCHK Component                                        */
/*                                                                            */
/* !Module          : LIHCHK                                                  */
/* !Description     : Safety TMS :SECURISER LE LIMP HOME                      */
/*                                                                            */
/* !File            : LIHCHK_SCH.C                                            */
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
/*   1 / LIHCHK_vidEntryInit                                                  */
/*   2 / SftyMgt_SdlMid_LiHChk                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 01261 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2403 / 1.1                                      */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/LIHCHK/LIHCHK_SCH.C_v $*/
/* $Revision::   1.3.1.2  $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "LIHCHK.h"
#include "LIHCHK_L.h"
#include "LIHCHK_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LIHCHK_vidEntryInit                                        */
/* !Description :  évènement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01261_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LIHCHK_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : LIHCHK_vidEntryInit                                            */
/* !Trigger  : LIHCHK_vidEntryInit                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LIHCHK_vidEntryInit(void)
{
   LIHCHK_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_LiHChk                                      */
/* !Description :  L’évènement d’appel de la fonction de sécurisation de      */
/*                 l’application des limitations de régime.                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01261_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LIHCHK_vidValider_Limp_Home();                           */
/*  input uint8 LIHCHK_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : SftyMgt_SdlMid_LiHChk                                          */
/* !Trigger  : SftyMgt_SdlMid_LiHChk                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_LiHChk(void)
{
   if (LIHCHK_u8Inhib != 0x5A)
   {
      LIHCHK_vidValider_Limp_Home();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/