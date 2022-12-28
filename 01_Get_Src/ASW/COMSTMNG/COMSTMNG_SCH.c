/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COMSTMNG                                                */
/* !Description     : COMSTMNG component                                      */
/*                                                                            */
/* !Module          : COMSTMNG                                                */
/* !Description     : GESTION DES PHASES DE VIE DE LA COMMUNICATION           */
/*                                                                            */
/* !File            : COMSTMNG_SCH.C                                          */
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
/*   1 / ComStMng_EveRst                                                      */
/*   2 / ComStMng_EveSdlFast                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6832731 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                          $*/
/* $Archive::   P:/EBx_V46/LDA/REF/modules/COMSTMNG/COMSTMNG_SCH.C_v         $*/
/* $Revision::   1.1                                                         $*/
/* $Author::   hmelloul                               $$Date::   06 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "COMSTMNG.h"
#include "COMSTMNG_L.h"
#include "COMSTMNG_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ComStMng_EveRst                                            */
/* !Description :  Evènement de reset logiciel.                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COMSTMNG_vidReset();                                     */
/*  extf argret void COMSTMNG_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : ComStMng_EveRst                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ComStMng_EveRst(void)
{
   COMSTMNG_vidReset();
   COMSTMNG_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ComStMng_EveSdlFast                                        */
/* !Description :  Evènement tâche temporelle rapide.                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COMSTMNG_vidCanIsLifeCyclePhases();                      */
/*  extf argret void COMSTMNG_vidLinLifeCyclePhases();                        */
/*  extf argret void COMSTMNG_vidWakeUp();                                    */
/*  extf argret void COMSTMNG_vidShutDown();                                  */
/*  input uint8 COMSTMNG_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : ComStMng_EveSdlFast                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ComStMng_EveSdlFast(void)
{
   if (COMSTMNG_u8Inhib != 0x5A)
   {
      COMSTMNG_vidCanIsLifeCyclePhases();
      COMSTMNG_vidLinLifeCyclePhases();
      COMSTMNG_vidWakeUp();
      COMSTMNG_vidShutDown();
   }
}
/*------------------------------- end of file --------------------------------*/