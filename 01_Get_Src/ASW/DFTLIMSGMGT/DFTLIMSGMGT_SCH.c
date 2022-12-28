/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DFTLIMSGMGT                                             */
/* !Description     : DFTLIMSGMGT Component                                   */
/*                                                                            */
/* !Module          : DFTLIMSGMGT                                             */
/* !Description     : ELABORATION DES MESSAGES CAN POUR ALLUMAGE DES VOYANTS  */
/*                    NON REGLEMENTAIRES                                      */
/*                                                                            */
/* !File            : DFTLIMSGMGT_SCH.C                                       */
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
/*   1 / Can_EveRst_DftLiMsgMgt                                               */
/*   2 / Can_SdlMid_DftLiMsgMgt                                               */
/*                                                                            */
/* !Reference   : V02 NT 11 02272 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/DFTLIMSGMGT/DFTLIMSGMGT_SCH.C_v   $*/
/* $Revision::   1.1      $$Author::   cbanchie       $$Date::   29 Apr 2011 $*/
/* $Author::   cbanchie                               $$Date::   29 Apr 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DFTLIMSGMGT.h"
#include "DFTLIMSGMGT_L.h"
#include "DFTLIMSGMGT_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_DftLiMsgMgt                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  M.BOUKADIDA                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DFTLIMSGMGT_vidInit();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_DftLiMsgMgt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_DftLiMsgMgt(void)
{
   DFTLIMSGMGT_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_SdlMid_DftLiMsgMgt                                     */
/* !Description :  Moniteur moyen de la fonction                              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  M.BOUKADIDA                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DFTLIMSGMGT_vidTimeTreatment();                          */
/*  input uint8 DFTLIMSGMGT_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_SdlMid_DftLiMsgMgt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_SdlMid_DftLiMsgMgt(void)
{
   if (DFTLIMSGMGT_u8Inhib != 0x5A)
   {
      DFTLIMSGMGT_vidTimeTreatment();
   }

}
/*----------------------------------end of file-------------------------------*/