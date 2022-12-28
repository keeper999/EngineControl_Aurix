/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXESTIM                                           */
/* !Description     : VLVACTEXESTIM component                                 */
/*                                                                            */
/* !Module          : VLVACTEXESTIM                                           */
/* !Description     : ESTIMATION DU DECALAGE AAC D’ECHAPPEMENT                */
/*                                                                            */
/* !File            : VLVACTEXESTIM_SCH.C                                     */
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
/*   1 / VLVACTEXESTIM_vidEntryInit                                           */
/*   2 / VlvAct_SdlFast_ExEstim                                               */
/*   3 / VlvAct_EveExCmToo_ExEstim                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 02851 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#063078                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXESTIM/VLVACTEXE$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   11 Oct 2012 $*/
/* $Author::   etsasson                               $$Date::   11 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTEXESTIM.h"
#include "VLVACTEXESTIM_L.h"
#include "VLVACTEXESTIM_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidEntryInit                                 */
/* !Description :  Initialisation function                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_02851_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXESTIM_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VLVACTEXESTIM_vidEntryInit                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXESTIM_vidEntryInit(void)
{
   VLVACTEXESTIM_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExEstim                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_02851_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXESTIM_vidExPosnEstimCmp();                       */
/*  input uint8 VLVACTEXESTIM_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExEstim                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExEstim(void)
{
   if (VLVACTEXESTIM_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXESTIM_vidExPosnEstimCmp();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveExCmToo_ExEstim                                  */
/* !Description :  Evènement dent AAC admission                               */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_02851_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXESTIM_vidExPosnEstimUpd();                       */
/*  extf argret void VLVACTEXESTIM_vidExPosnEstimVar();                       */
/*  input uint8 VLVACTEXESTIM_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveExCmToo_ExEstim                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveExCmToo_ExEstim(void)
{
   if (VLVACTEXESTIM_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXESTIM_vidExPosnEstimUpd();
         VLVACTEXESTIM_vidExPosnEstimVar();
      }
   }
}
/*--------------------------------- end of file ------------------------------*/