/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : NOPROD                                                  */
/*                                                                            */
/* !Module          : NOPROD                                                  */
/* !Description     : Génération des variables non produites                  */
/*                                                                            */
/* !File            : NOPROD_SCH.C                                            */
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
/*   1 / Cf_EveRst_NoProd                                                     */
/*   2 / Cf_SdlSlow_NoProd                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5076350 / 21                                        */
/* !OtherRefs   : VEMS V02 ECU#067902                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/NOPROD/NOPROD_SCH.C_v      $*/
/* $Revision::   1.0      $$Author::   fsanchez2      $$Date::   04 Mar 2014 $*/
/* $Author::   fsanchez2                              $$Date::   04 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "NOPROD.H"
#include "NOPROD_L.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_NoProd                                           */
/* !Description :  Evénement RESET pour l' initialisation des  variables non  */
/*                 produites                                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NOPROD_vidReset();                                       */
/*  extf argret void NOPROD_vidUpdate();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_NoProd                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_NoProd(void)
{
   NOPROD_vidReset();
   NOPROD_vidUpdate();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlSlow_NoProd                                          */
/* !Description :  Evénement lent de mise à jour des variables non produites .*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NOPROD_vidUpdate();                                      */
/*  input uint8 NOPROD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlSlow_NoProd                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlSlow_NoProd(void)
{
   if (NOPROD_u8Inhib != 0x5A)
   {
      NOPROD_vidUpdate();
   }
}
/*------------------------------- end of file --------------------------------*/
