/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINESTIM                                           */
/* !Description     : VLVACTINESTIM component                                 */
/*                                                                            */
/* !Module          : VLVACTINESTIM                                           */
/* !Description     : ESTIMATION DU DECALAGE AAC D’ADMISSION                  */
/*                                                                            */
/* !File            : VLVACTINESTIM_SCH.C                                     */
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
/*   1 / VLVACTINESTIM_vidEntryInit                                           */
/*   2 / VlvAct_SdlFast_InEstim                                               */
/*   3 / VlvAct_EveInCmToo_InEstim                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 01756 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#063078                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINESTIM/VLVACTINE$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   11 Oct 2012 $*/
/* $Author::   etsasson                               $$Date::   11 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINESTIM.h"
#include "VLVACTINESTIM_L.h"
#include "VLVACTINESTIM_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidEntryInit                                 */
/* !Description :  Initialisation function                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINESTIM_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VLVACTINESTIM_vidEntryInit                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidEntryInit(void)
{
   VLVACTINESTIM_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InEstim                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINESTIM_vidInPosnEstimCmp();                       */
/*  input uint8 VLVACTINESTIM_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InEstim                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InEstim(void)
{
   if (VLVACTINESTIM_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINESTIM_vidInPosnEstimCmp();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveInCmToo_InEstim                                  */
/* !Description :  Evènement dent AAC admission                               */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINESTIM_vidInPosnEstimUpd();                       */
/*  extf argret void VLVACTINESTIM_vidInPosnEstimVar();                       */
/*  input uint8 VLVACTINESTIM_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveInCmToo_InEstim                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveInCmToo_InEstim(void)
{
   if (VLVACTINESTIM_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINESTIM_vidInPosnEstimUpd();
         VLVACTINESTIM_vidInPosnEstimVar();
      }
   }
}
/*--------------------------------- end of file ------------------------------*/