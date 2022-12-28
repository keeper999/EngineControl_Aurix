/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : JDDISCANIF                                              */
/* !Description     : JDDISCANIF Component                                    */
/*                                                                            */
/* !Module          : JDDISCANIF                                              */
/* !Description     : SPECIFICATION D'INTERFACE ENTRE LE JDD ET L'ISCAN       */
/*                                                                            */
/* !File            : JDDISCANIF_SCH.C                                        */
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
/*   1 / GD_EveRst_DftLogTx                                                   */
/*   2 / JDDISCANIF_PrepaDataIscanBuffer                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 02911 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#054516                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/JDDISCANIF/JDDISCANIF_SCH.C_v   $*/
/* $Revision::   1.0      $$Author::   fguillon       $$Date::   14 Jun 2011 $*/
/* $Author::   fguillon                               $$Date::   14 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "JDDISCANIF.h"
#include "JDDISCANIF_l.h"
#include "JDDISCANIF_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_DftLogTx                                         */
/* !Description :  Evènement reset ECU de la fonction GD                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDDISCANIF_vidInit();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : GD_EveRst_DftLogTx                                             */
/* !Trigger  : GD_EveRst_DftLogTx                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_DftLogTx(void)
{
   JDDISCANIF_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_PrepaDataIscanBuffer                            */
/* !Description :  Demande de préparation par le manager de la trame JDD      */
/*                 (768h) à émettre                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDDISCANIF_vidPrepaDataISCAN();                          */
/*  extf argret void GD_EveSendDftLog_DftLogTx();                             */
/*  input uint8 JDDISCANIF_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : JDDISCANIF_PrepaDataIscanBuffer                                */
/* !Trigger  : JDDISCANIF_PrepaDataIscanBuffer                                */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_PrepaDataIscanBuffer(void)
{
   if (JDDISCANIF_u8Inhib != 0x5A)
   {
      JDDISCANIF_vidPrepaDataISCAN();
      GD_EveSendDftLog_DftLogTx();
   }
}

/*------------------------------- end of file --------------------------------*/