/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGLIMEFCCORD                                           */
/* !Description     : ENGLIMEFCCORD Component.                                */
/*                                                                            */
/* !Module          : ENGLIMEFCCORD                                           */
/* !Description     : Coordination des limitations CME.                       */
/*                                                                            */
/* !File            : ENGLIMEFCCORD_SCH.C                                     */
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
/*   1 / ENGLIMEFCCORD_vidEntryInit                                           */
/*   2 / TqSys_Sdl10ms_TqEfcCordLim                                           */
/*                                                                            */
/* !Reference   : V02 NT 10 03267 / 03                                        */
/* !OtherRefs   : CSMT_CGMT08_0923 / 2.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/ENGLIMEFCCORD/ENG$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ENGLIMEFCCORD.h"
#include "ENGLIMEFCCORD_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidEntryInit                                 */
/* !Description :  Fonction d'accroche moniteur Reset                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGLIMEFCCORD_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ENGLIMEFCCORD_vidEntryInit                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidEntryInit(void)
{
   ENGLIMEFCCORD_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl10ms_TqEfcCordLim                                 */
/* !Description :  Fonction d'accroche moniteur 10ms                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGLIMEFCCORD_vidCoord_Lim_CME();                        */
/*  input uint8 ENGLIMEFCCORD_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_Sdl10ms_TqEfcCordLim                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl10ms_TqEfcCordLim(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (ENGLIMEFCCORD_u8Inhib != 0x5A)
   {
      ENGLIMEFCCORD_vidCoord_Lim_CME();
   }
}
/*------------------------------- end of file --------------------------------*/