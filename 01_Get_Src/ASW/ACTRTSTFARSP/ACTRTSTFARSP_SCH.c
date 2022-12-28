/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTFARSP                                            */
/* !Description     : ACTRTSTFARSP Component                                  */
/*                                                                            */
/* !Module          : ACTRTSTFARSP                                            */
/* !Description     : Test actionneur consigne de richesse                    */
/*                                                                            */
/* !File            : ACTRTSTFARSP_SCH.C                                      */
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
/*   1 / FarSp_EveRst_ActrTstFarSp                                            */
/*   2 / FarSp_SdlFast_ActrTstFarSp                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5066987 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FAR/ACTRTSTFARSP/ACTRTSTFARSP_SC$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   20 Feb 2013 $*/
/* $Author::   etsasson                               $$Date::   20 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACTRTSTFARSP.h"
#include "ACTRTSTFARSP_l.h"
#include "ACTRTSTFARSP_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FarSp_EveRst_ActrTstFarSp                                  */
/* !Description :  Evenement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTFARSP_vidInitOutput();                            */
/*  extf argret void ACTRTSTFARSP_vidFarSpUsActrTst();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FarSp_EveRst_ActrTstFarSp                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FarSp_EveRst_ActrTstFarSp(void)
{
   ACTRTSTFARSP_vidInitOutput();
   ACTRTSTFARSP_vidFarSpUsActrTst();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FarSp_SdlFast_ActrTstFarSp                                 */
/* !Description :  Moniteur rapide de la fonction objectif de richesse pour le*/
/*                 test actionneur                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTFARSP_vidFarSpUsActrTst();                        */
/*  input uint8 ACTRTSTFARSP_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FarSp_SdlFast_ActrTstFarSp                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FarSp_SdlFast_ActrTstFarSp(void)
{
   if (ACTRTSTFARSP_u8Inhib != 0x5A)
   {
      ACTRTSTFARSP_vidFarSpUsActrTst();
   }
}
/*---------------------------------End Of File--------------------------------*/