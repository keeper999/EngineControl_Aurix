/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPFRM                                                 */
/* !Description     : ACCPFRM component.                                      */
/*                                                                            */
/* !Module          : ACCPFRM                                                 */
/* !Description     : Formatage de la volonté conducteur sur la pédale        */
/*                    accélérateur.                                           */
/*                                                                            */
/* !File            : ACCPFRM_SCH.C                                           */
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
/*   1 / ACCPFRM_vidEntryInit                                                 */
/*   2 / AccP_SdlFast_Ftm                                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 03781 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPFRM/ACCPFRM_SCH.C_v      $*/
/* $Revision::   1.6                                                         $*/
/* $Author::   wbouach                                $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "ACCPFRM.h"
#include "ACCPFRM_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPFRM_vidEntryInit                                       */
/* !Description :  Fonction moniteur Reset                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPFRM_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : ACCPFRM_vidEntryInit                                           */
/* !Trigger  : event Reset                                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPFRM_vidEntryInit(void)
{
   ACCPFRM_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_Ftm                                           */
/* !Description :  Fonction moniteur activé suite à l'évènement               */
/*                 AccP_SdlFast_Ftm                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPFRM_vidMuxFormatting();                              */
/*  input uint8 ACCPFRM_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : AccP_SdlFast_Ftm                                               */
/* !Trigger  : event AccP_SdlFast_Ftm                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_Ftm(void)
{
   if(ACCPFRM_u8Inhib != 0x5A)
   {
      ACCPFRM_vidMuxFormatting();
   }
}

/*------------------------------ End of file ---------------------------------*/