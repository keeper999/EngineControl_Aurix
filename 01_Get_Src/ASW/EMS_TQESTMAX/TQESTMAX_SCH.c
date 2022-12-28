/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQESTMAX                                                */
/* !Description     : TQESTMAX component.                                     */
/*                                                                            */
/* !Module          : TQESTMAX                                                */
/* !Description     : Modèle d’estimation du couple Max                       */
/*                                                                            */
/* !File            : TQESTMAX_SCH.C                                          */
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
/*   1 / TQESTMAX_vidEntryInit                                                */
/*   2 / TQESTMAX_TqSys_EveSync                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5795522 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0924 / 2.2                                      */
/* !OtherRefs   : VEMS V02 ECU#045173                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQESTMAX/TQESTMAX$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   25 Nov 2013 $*/
/* $Author::   mbenfrad                               $$Date::   25 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQESTMAX.h"
#include "TQESTMAX_L.h"
#include "TQESTMAX_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_vidEntryInit                                      */
/* !Description :  Evenement reset ECU                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQESTMAX_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQESTMAX_vidEntryInit                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_vidEntryInit(void)
{
   TQESTMAX_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQESTMAX_TqSys_EveSync                                     */
/* !Description :  Event TqSys_EveSync                                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_09_05545_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQESTMAX_vidModele_cpl_pot();                            */
/*  input uint8 TQESTMAX_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQESTMAX_TqSys_EveSync                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQESTMAX_TqSys_EveSync(void)
{
   if (TQESTMAX_u8Inhib != 0x5A)
   {
      TQESTMAX_vidModele_cpl_pot();
   }
}
/*------------------------------- end of file --------------------------------*/