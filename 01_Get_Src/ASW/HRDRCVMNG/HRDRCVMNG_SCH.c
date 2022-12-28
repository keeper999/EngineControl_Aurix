/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HRDRCVMNG                                               */
/* !Description     : HRDRCVMNG component.                                    */
/*                                                                            */
/* !Module          : HRDRCVMNG                                               */
/* !Description     : GESTIONNAIRE DES RECONFIGURATIONS NON CALIBRABLES .     */
/*                                                                            */
/* !File            : HRDRCVMNG_SCH.C                                         */
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
/*   1 / GD_EveRst_HrdRcvMng                                                  */
/*   2 / GD_SdlMid_HrdRcvMng                                                  */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/GDGAR/HRDRCVMNG/HRDRCVMNG_SCH.C_v $*/
/* $Revision::   1.0      $$Author::   acabresp       $$Date::   22 Jun 2009 $*/
/******************************************************************************/

#include "STD_TYPES.h"
#include "HRDRCVMNG.h"
#include "HRDRCVMNG_L.h"
#include "HRDRCVMNG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Fonction d'accroche à l'événement GD_EveRst_HrdRcvMng       */
/* !Number      : SCH.1                                                       */
/* !Reference   : V02 NT 09 03395 / 1                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void HRDRCVMNG_vidInitialization();                          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : GD_EveRst_HrdRcvMng                                            */
/* !Trigger  : GD_EveRst_HrdRcvMng                                            */
/*                                                                            */
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_HrdRcvMng(void)
{
   HRDRCVMNG_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Fonction d'accroche à l'événement GD_SdlMid_HrdRcvMng       */
/* !Number      : SCH.2                                                       */
/* !Reference   : V02 NT 09 03395 / 1                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void HRDRCVMNG_vidXvv();                                     */
/*                                                                            */
/*   input uint8 HRDRCVMNG_u8Inhib;                                           */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : GD_SdlMid_HrdRcvMng                                            */
/* !Trigger  : GD_SdlMid_HrdRcvMng                                            */
/*                                                                            */
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlMid_HrdRcvMng(void)
{
   if (HRDRCVMNG_u8Inhib != 0x5A)
   {
      HRDRCVMNG_vidXvv();
   }
}
/*------------------------------- end of file --------------------------------*/