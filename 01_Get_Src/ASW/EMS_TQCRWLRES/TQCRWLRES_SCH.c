/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCRWLRES                                               */
/* !Description     : TQCRWLRES Component.                                    */
/*                                                                            */
/* !Module          : TQCRWLRES                                               */
/* !Description     : Reserve de couple rampage BVMP.                         */
/*                                                                            */
/* !File            : TQCRWLRES_SCH.C                                         */
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
/*   1 / TQCRWLRES_vidEntryInit                                               */
/*   2 / TqRes_Sdl10ms_tqCrawlRes                                             */
/*                                                                            */
/* !Reference   : V02 NT 10 04975 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2909 / 2                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCRWLRES/TQCRWLR$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQCRWLRES.h"
#include "TQCRWLRES_L.h"
#include "TQCRWLRES_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCRWLRES_vidEntryInit                                     */
/* !Description :  Evenement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04975_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCRWLRES_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCRWLRES_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCRWLRES_vidEntryInit(void)
{
   TQCRWLRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqCrawlRes                                   */
/* !Description :  Evenement d'activation du bloc                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04975_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCRWLRES_vidReserveRampBVMP();                          */
/*  input uint8 TQCRWLRES_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqRes_Sdl10ms_tqCrawlRes                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqCrawlRes(void)
{
   /*QAC Warning(2:4152): Name imposed in specification*/
   if (TQCRWLRES_u8Inhib != 0x5A)
   {
      TQCRWLRES_vidReserveRampBVMP();
   }
}

/*------------------------------- end of file --------------------------------*/