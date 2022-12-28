/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGBRKPED                                              */
/* !Description     : DIAGBRKPED component                                    */
/*                                                                            */
/* !Module          : DIAGBRKPED                                              */
/* !Description     : ACQUISITION DE LA PEDALE DE FREIN                       */
/*                                                                            */
/* !File            : DIAGBRKPED_SCH.C                                        */
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
/*   1 / Brk_EveRst_DiagBrkPed                                                */
/*   2 / Brk_SdlMid_DiagBrkPed                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6526884 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/BRK/DIAGBRKPED/DIAGBRKPED_SCH.C_v $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DIAGBRKPED.h"
#include "DIAGBRKPED_l.h"
#include "DIAGBRKPED_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_EveRst_DiagBrkPed                                      */
/* !Description :  Fonction d'accroche à l'evenement Reset                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_04207_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGBRKPED_vidInitOutput();                              */
/*  extf argret void DIAGBRKPED_vidIni();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Brk_EveRst_DiagBrkPed                                          */
/* !Trigger  : Brk_EveRst_DiagBrkPed                                          */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_EveRst_DiagBrkPed(void)
{
   DIAGBRKPED_vidInitOutput();
   DIAGBRKPED_vidIni();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_SdlMid_DiagBrkPed                                      */
/* !Description :  Moniteur du diagnostic acquisition frein                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_04207_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGBRKPED_vidLogicAcqui();                              */
/*  input uint8 DIAGBRKPED_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Brk_SdlMid_DiagBrkPed                                          */
/* !Trigger  : Brk_SdlMid_DiagBrkPed                                          */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_SdlMid_DiagBrkPed(void)
{
   if (DIAGBRKPED_u8Inhib != 0x5A)
   {
      DIAGBRKPED_vidLogicAcqui();
   }
}

/*------------------------------- end of file --------------------------------*/