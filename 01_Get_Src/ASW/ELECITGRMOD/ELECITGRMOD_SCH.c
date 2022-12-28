/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ELECITGRMOD                                             */
/* !Description     : ELECITGRMOD component                                   */
/*                                                                            */
/* !Module          : ELECITGRMOD                                             */
/* !Description     : IMPLÉMENTATION DU MODE INTEGRATION ELECTRONIQUE         */
/*                                                                            */
/* !File            : ELECITGRMOD_SCH.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DIAGCAN_EveRst                                                       */
/*   2 / DIAGCAN_Eve50ms                                                      */
/*   3 / DIAGCAN_EveRxn092IntElec                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6873723 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                          $*/
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ELECITGRMOD/ELECITGRMOD_SCH.c_v   $*/
/* $Revision::   1.0                                                         $*/
/* $Author::   hmelloul                               $$Date::   19 Aug 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "ELECITGRMOD.h"
#include "ELECITGRMOD_L.h"
#include "ELECITGRMOD_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGCAN_EveRst                                             */
/* !Description :  Fonction d'accroche pour l'événement EveRst                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ELECITGRMOD_vidIntElecInit();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : DIAGCAN_EveRst                                                 */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGCAN_EveRst(void)
{
   ELECITGRMOD_vidIntElecInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGCAN_Eve50ms                                            */
/* !Description :  Evénement toutes les 50ms du Diagnostic Can                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ELECITGRMOD_vidIntElecCondCheck();                       */
/*  input uint8 ELECITGRMOD_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : DIAGCAN_Eve50ms                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGCAN_Eve50ms(void)
{
   if (ELECITGRMOD_u8Inhib != 0x5A)
   {
      ELECITGRMOD_vidIntElecCondCheck();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGCAN_EveRxn092IntElec                                   */
/* !Description :  Fonction appelée sur réception de la trame CAN 0x092       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ELECITGRMOD_vidIntegElectronic();                        */
/*  input uint8 ELECITGRMOD_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : DIAGCAN_EveRxn092IntElec                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGCAN_EveRxn092IntElec(void)
{
   if (ELECITGRMOD_u8Inhib != 0x5A)
   {
      ELECITGRMOD_vidIntegElectronic();
   }
}

/*------------------------------- end of file --------------------------------*/