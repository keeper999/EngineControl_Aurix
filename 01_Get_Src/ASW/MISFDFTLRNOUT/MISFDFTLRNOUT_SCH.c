/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDFTLRNOUT                                           */
/* !Description     : MISFDFTLRNOUT component.                                */
/*                                                                            */
/* !Module          : MISFDFTLRNOUT                                           */
/* !Description     : GENERATION DE L'ETAT D'APPRENTISSAGE DES DEFAUTS        */
/*                    MISFIRE.                                                */
/*                                                                            */
/* !File            : MISFDFTLRNOUT_SCH.C                                     */
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
/*   1 / MISFDFTLRNOUT_vidEntryInit                                           */
/*   2 / Misf_SdlSlow_MisfDftLrnOut                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 00762 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRNOUT/MISFDFTLRNOUT_S$*/
/* $Revision::   1.0      $$Author::   fsanchez2      $$Date::   22 Oct 2009 $*/
/* $Author::   fsanchez2                              $$Date::   22 Oct 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "MISFDFTLRNOUT.h"
#include "MISFDFTLRNOUT_L.h"
#include "MISFDFTLRNOUT_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRNOUT_vidEntryInit                                 */
/* !Description :  Fonction d'accroche au RESET.                              */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRNOUT_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : MISFDFTLRNOUT_vidEntryInit                                     */
/* !Trigger  : MISFDFTLRNOUT_vidEntryInit                                     */
/*                                                                            */
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRNOUT_vidEntryInit(void)
{
   MISFDFTLRNOUT_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_SdlSlow_MisfDftLrnOut                                 */
/* !Description :  Fonction d'accroche au moniteur lent de la fonction Misf.  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRNOUT_vidMfwAdaptCntMin();                       */
/*  extf argret void MISFDFTLRNOUT_vidMfwAdaptCZonLev();                      */
/*  extf argret void MISFDFTLRNOUT_vidMfwAdaptZRatio();                       */
/*  input uint8 MISFDFTLRNOUT_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Misf_SdlSlow_MisfDftLrnOut                                     */
/* !Trigger  : Misf_SdlSlow_MisfDftLrnOut                                     */
/*                                                                            */
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_SdlSlow_MisfDftLrnOut(void)
{
   if (MISFDFTLRNOUT_u8Inhib != 0x5A)
   {
      MISFDFTLRNOUT_vidMfwAdaptCntMin();
      MISFDFTLRNOUT_vidMfwAdaptCZonLev();
      MISFDFTLRNOUT_vidMfwAdaptZRatio();
   }
}

/*---------------------------- end of file -----------------------------------*/