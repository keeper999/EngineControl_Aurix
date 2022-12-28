/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQIDCENGREAL                                            */
/* !Description     : TQIDCENGREAL Component                                  */
/*                                                                            */
/* !Module          : TQIDCENGREAL                                            */
/* !Description     : ESTIMER COUPLE REEL                                     */
/*                                                                            */
/* !File            : TQIDCENGREAL_SCH.C                                      */
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
/*   1 / TQIDCENGREAL_vidEntryInit                                            */
/*   2 / SftyMgt_SdlMid_tqIdcEngReal                                          */
/*                                                                            */
/* !Reference   : V02 NT 10 01238 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_2402 / 1.3                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDCENGREAL/TQIDCENGR$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.H"
#include "TQIDCENGREAL.H"
#include "TQIDCENGREAL_L.H"
#include "TQIDCENGREAL_IM.H"

#define TMS_START_SEC_CODE
#include "MemMap.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDCENGREAL_vidEntryInit                                  */
/* !Description :  Evenement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDCENGREAL_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQIDCENGREAL_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDCENGREAL_vidEntryInit(void)
{
   TQIDCENGREAL_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqIdcEngReal                                */
/* !Description :  Evenement du déclenchement de la fonction d'estimation du  */
/*                 couple réel                                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01238_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDCENGREAL_vidEstimCplIndiqRel();                      */
/*  input uint8 TQIDCENGREAL_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqIdcEngReal                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqIdcEngReal(void)
{
   if (TQIDCENGREAL_u8Inhib != 0x5A)
   {
      TQIDCENGREAL_vidEstimCplIndiqRel();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/******************************* <End_Of_File> ********************************/