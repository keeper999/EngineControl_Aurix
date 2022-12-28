/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQANTISTALLBVM                                          */
/* !Description     : TQANTISTALLBVM component                                */
/*                                                                            */
/* !Module          : TQANTISTALLBVM                                          */
/* !Description     : Anti-calage BVM                                         */
/*                                                                            */
/* !File            : TQANTISTALLBVM_SCH.C                                    */
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
/*   1 / TQANTISTALLBVM_vidEntryInit                                          */
/*   2 / IdlSys_EveSync_AntiStall                                             */
/*                                                                            */
/* !Reference   : V02 NT 10 04974 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_2609 / 2.1                                      */
/* !OtherRefs   : VEMS V02 ECU#050078                                         */
/* !OtherRefs   : VEMS V02 ECU#054080                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQANTISTALLBVM/TQ$*/
/* $Revision::   1.5      $$Author::   etsasson       $$Date::   28 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQANTISTALLBVM.h"
#include "TQANTISTALLBVM_L.h"
#include "TQANTISTALLBVM_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidEntryInit                                */
/* !Description :  Fonction d'accroche au moniteur reset                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQANTISTALLBVM_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQANTISTALLBVM_vidEntryInit                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidEntryInit(void)
{
   TQANTISTALLBVM_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IdlSys_EveSync_AntiStall                                   */
/* !Description :  Fonction d'accroche au PMH.                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQANTISTALLBVM_vidAnticalBVM();                          */
/*  input uint8 TQANTISTALLBVM_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IdlSys_EveSync_AntiStall                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IdlSys_EveSync_AntiStall(void)
{
   if(TQANTISTALLBVM_u8Inhib != 0x5A)
   {
      TQANTISTALLBVM_vidAnticalBVM();
   }
}
/*------------------------------- end of file --------------------------------*/