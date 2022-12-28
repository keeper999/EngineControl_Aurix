/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPLRNPOS                                              */
/* !Description     : ACCPLRNPOS component.                                   */
/*                                                                            */
/* !Module          : ACCPLRNPOS                                              */
/* !Description     : APPRENTISSAGE DES POSITIONS PIED LEVE ET PIED A FOND DE */
/*                    LA PEDALE D’ACCELERATEUR                                */
/*                                                                            */
/* !File            : ACCPLRNPOS_SCH.C                                        */
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
/*   1 / AccP_EveRst_FLrng                                                    */
/*   2 / AccP_SdlSlow_FLrng                                                   */
/*   3 / AccP_EveRstPed_FLrng                                                 */
/*                                                                            */
/* !Reference   : V02 NT 08 03749 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPLRNPOS/ACCPLRNPOS_SCH.C_v$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   hmelloul                               $$Date::   15 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACCPLRNPOS.h"
#include "ACCPLRNPOS_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_FLrng                                          */
/* !Description :  Fonction d'accroche à l'événement AccP_EveRst_FLrng        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPLRNPOS_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : AccP_EveRst_FLrng                                              */
/* !Trigger  : AccP_EveRst_FLrng                                              */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_FLrng(void)
{
   ACCPLRNPOS_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlSlow_FLrng                                         */
/* !Description :  Fonction d'accroche à l'événement AccP_SdlSlow_FLrng       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPLRNPOS_vidFreeLearningMgt();                         */
/*  input uint8 ACCPLRNPOS_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : AccP_SdlSlow_FLrng                                             */
/* !Trigger  : AccP_SdlSlow_FLrng                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlSlow_FLrng(void)
{
   if (ACCPLRNPOS_u8Inhib != 0x5A)
   {
      ACCPLRNPOS_vidFreeLearningMgt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRstPed_FLrng                                       */
/* !Description :  Runnable Demande de reset apprentissage pédale accélérateur*/
/* !Number      :  SCH.3                                                      */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPLRNPOS_vidInitDiagsrv();                             */
/*  input uint8 ACCPLRNPOS_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : AccP_EveRstPed_FLrng                                           */
/* !Trigger  : AccP_EveRstPed_FLrng                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRstPed_FLrng(void)
{
   if (ACCPLRNPOS_u8Inhib != 0x5A)
   {
      ACCPLRNPOS_vidInitDiagsrv();
   }
}

/*------------------------------- end of file --------------------------------*/