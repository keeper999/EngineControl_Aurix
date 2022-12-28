/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : LAMCLMPD                                                */
/* !Description     : LAMCLMPD component                                      */
/*                                                                            */
/* !Module          : LAMCLMPD                                                */
/* !Description     : Régulation De Richesse En Butée                         */
/*                                                                            */
/* !File            : LAMCLMPD_SCH.c                                          */
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
/*   1 / InjCtl_EveRst_LamClmpd                                               */
/*   2 / InjCtl_SdlFast_LamClmpd                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 02030 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/LAMCLMPD/LAMCLMPD_SCH.$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   25 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "std_types.h"
#include "LAMCLMPD.h"
#include "LAMCLMPD_L.h"
#include "LAMCLMPD_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveRst_LamClmpd                                     */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveRst_LamClmpd       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAMCLMPD_vidInitIndicRichActobd();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : InjCtl_EveRst_LamClmpd                                         */
/* !Trigger  : InjCtl_EveRst_LamClmpd                                         */
/*                                                                            */
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveRst_LamClmpd(void)
{
   LAMCLMPD_vidInitIndicRichActobd();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_SdlFast_LamClmpd                                    */
/* !Description :  Fonction d'accroche à l'event InjCtl_SdlFast_LamClmpd      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LAMCLMPD_vidRichCalcIndicators();                        */
/*  input uint8 LAMCLMPD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : InjCtl_SdlFast_LamClmpd                                        */
/* !Trigger  : InjCtl_SdlFast_LamClmpd                                        */
/*                                                                            */
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_SdlFast_LamClmpd(void)
{
   if (LAMCLMPD_u8Inhib != 0x5A)
   {
      LAMCLMPD_vidRichCalcIndicators();
   }
}
/*------------------------------- end of file --------------------------------*/