/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLSYSCUTOFF                                            */
/* !Description     : IDLSYSCUTOFF component.                                 */
/*                                                                            */
/* !Module          : IDLSYSCUTOFF                                            */
/* !Description     : Gestion coupure - reinjection agrement                  */
/*                                                                            */
/* !File            : IDLSYSCUTOFF_SCH.C                                      */
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
/*   1 / IDLSYSCUTOFF_vidEntryInit                                            */
/*   2 / IdlSys_EveSync_bInjCutOff                                            */
/*                                                                            */
/* !Reference   : V02 NT 10 04612 / 02                                        */
/* !OtherRefs   : 01460_10_01410 / 1.1                                        */
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
#include "IDLSYSCUTOFF.h"
#include "IDLSYSCUTOFF_L.h"
#include "IDLSYSCUTOFF_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidEntryInit                                  */
/* !Description :  Tache reset.                                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLSYSCUTOFF_vidInitOutput(void);                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IDLSYSCUTOFF_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidEntryInit(void)
{
   IDLSYSCUTOFF_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IdlSys_EveSync_bInjCutOff                                  */
/* !Description :  Evenement de synchronisation                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLSYSCUTOFF_vidCalculCondRegime(void);                  */
/*  extf argret void IDLSYSCUTOFF_vidCalculCondIVC(void);                     */
/*  extf argret void IDLSYSCUTOFF_vidAutoriCoupureInj(void);                  */
/*  input uint8 IDLSYSCUTOFF_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IdlSys_EveSync_bInjCutOff                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IdlSys_EveSync_bInjCutOff(void)
{
   if (IDLSYSCUTOFF_u8Inhib != 0x5A)
   {
      IDLSYSCUTOFF_vidCalculCondRegime();
      IDLSYSCUTOFF_vidCalculCondIVC();
      IDLSYSCUTOFF_vidAutoriCoupureInj();
   }
}
/*-------------------------------- end of file -------------------------------*/
