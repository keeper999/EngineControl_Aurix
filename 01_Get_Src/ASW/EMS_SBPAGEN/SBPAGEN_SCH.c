/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SBPAGEN                                                 */
/* !Description     : SBPAGEN Component                                       */
/*                                                                            */
/* !Module          : SBPAGEN                                                 */
/* !Description     : Générateur De Sbpa                                      */
/*                                                                            */
/* !File            : SBPAGEN_SCH.C                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : Renesas                                                 */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / SBPAGEN_vidEntryInit                                                 */
/*   2 / TqSys_EveSync_SBPA                                                   */
/*                                                                            */
/* !Reference   : V02 NT 08 07560 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_1271 / 1.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/SBPAGEN/SBPAGEN_S$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "SBPAGEN.H"
#include "SBPAGEN_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SBPAGEN_vidEntryInit                                       */
/* !Description :  Fonction d'accroche moniteur Reset.                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07560_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SBPAGEN_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Reset                                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SBPAGEN_vidEntryInit(void)
{
   SBPAGEN_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveSync_SBPA                                         */
/* !Description :  Scheduler de la fonction                                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07560_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SBPAGEN_vidCalculer_SBPA();                              */
/*  input uint8 SBPAGEN_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_EveSync_SBPA                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveSync_SBPA(void)
{
   if (SBPAGEN_u8Inhib != 0x5A)
   {
      SBPAGEN_vidCalculer_SBPA();
   }
}
/*---------------------------------end of file -------------------------------*/