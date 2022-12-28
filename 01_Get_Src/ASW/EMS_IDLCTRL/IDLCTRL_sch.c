/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLCTRL                                                 */
/* !Description     : IDLCTRL Component                                       */
/*                                                                            */
/* !Module          : IDLCTRL                                                 */
/* !Description     : Régulateur de régime ralenti                            */
/*                                                                            */
/* !File            : IDLCTRL_SCH.c                                           */
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
/*   1 / IDLCTRL_vidEntryInit                                                 */
/*   2 / IdlSys_EveSync_tqIdcIdl                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5659858 / 01                                        */
/* !Reference   : PTS_DOC_5700651 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_1336 / 2.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLCTRL/IDLCTRL_S$*/
/* $Revision::   1.16                                                        $*/
/* $Author::   mbenfrad                               $$Date::   21 Oct 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IDLCTRL.h"
#include "IDLCTRL_L.h"
#include "IDLCTRL_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidEntryInit                                       */
/* !Description :  Fonction d'accroche au moniteur Reset                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLCTRL_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IDLCTRL_vidEntryInit                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidEntryInit(void)
{
   IDLCTRL_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IdlSys_EveSync_tqIdcIdl                                    */
/* !Description :  Fonction d'accroche au moniteur Pmh (TDC)                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLCTRL_vidIdleSpeedControl();                           */
/*  input uint8 IDLCTRL_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IdlSys_EveSync_tqIdcIdl                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IdlSys_EveSync_tqIdcIdl(void)
{
   if (IDLCTRL_u8Inhib != 0x5A)
   {
      IDLCTRL_vidIdleSpeedControl();
   }
}

/*------------------------------ end of file ---------------------------------*/