/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MNGBRKPED                                               */
/* !Description     : MNGBRKPED component.                                    */
/*                                                                            */
/* !Module          : MNGBRKPED                                               */
/* !Description     : Gestion de l’information pédale de frein                */
/*                                                                            */
/* !File            : MNGBRKPED_SCH.C                                         */
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
/*   1 / Brk_EveRst_MngBrkPed                                                 */
/*   2 / Brk_SdlMid_MngBrkPed                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 03796 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHIBRK/MNGBRKPED/MNGBRKPED_SCH$*/
/* $Revision::   1.4      $$Author::   HHAMLAOU       $$Date::   06 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MNGBRKPED.h"
#include "MNGBRKPED_L.h"
#include "MNGBRKPED_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_EveRst_MngBrkPed                                       */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_11_03796_001.01                                     */
/*                 VEMS_E_11_03796_002.01                                     */
/*                 VEMS_E_11_03796_003.01                                     */
/*                 VEMS_R_10_02673_001.01                                     */
/*                 VEMS_R_10_02673_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MNGBRKPED_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_EveRst_MngBrkPed                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_EveRst_MngBrkPed(void)
{
   MNGBRKPED_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_SdlMid_MngBrkPed                                       */
/* !Description :  Moniteur du diagnostic acquisition frein                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_11_03796_001.01                                     */
/*                 VEMS_E_11_03796_002.01                                     */
/*                 VEMS_E_11_03796_003.01                                     */
/*                 VEMS_R_10_02673_001.01                                     */
/*                 VEMS_R_10_02673_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MNGBRKPED_vidFCall();                                    */
/*  input uint8 MNGBRKPED_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_SdlMid_MngBrkPed                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_SdlMid_MngBrkPed(void)
{
   if (MNGBRKPED_u8Inhib != 0x5A )
   {
      MNGBRKPED_vidFCall();
   }
}

/*------------------------------end-of-file-----------------------------------*/