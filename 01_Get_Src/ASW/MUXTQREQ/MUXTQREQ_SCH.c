/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MUXTQREQ                                                */
/* !Description     : MUXTQREQ Component                                      */
/*                                                                            */
/* !Module          : MUXTQREQ                                                */
/* !Description     : GESTION DES CONSIGNES DE COUPLE POUR L'INTER-SYSTEMES EN*/
/*                    MODE DEGRADE MOTEUR                                     */
/*                                                                            */
/* !File            : MUXTQREQ_SCH.C                                          */
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
/*   1 / TqSys_EveRst_MuxTqReq                                                */
/*   2 / TqSys_SdlMid_MuxTqReq                                                */
/*                                                                            */
/* !Reference   : V02 NT 11 08258 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/MUXTQREQ/MUXTQREQ_SCH.C_v         $*/
/* $Revision::   1.0      $$Author::   bbris          $$Date::   17 Feb 2012 $*/
/* $Author::   bbris                                  $$Date::   17 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MUXTQREQ.h"
#include "MUXTQREQ_L.h"
#include "MUXTQREQ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveRst_MuxTqReq                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_11_08258_001.01                                     */
/*                 VEMS_R_11_08258_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MUXTQREQ_vidInit();                                      */
/*  extf argret void MUXTQREQ_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  TqSys_EveRst_MuxTqReq                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveRst_MuxTqReq(void)
{
   MUXTQREQ_vidInit();
   MUXTQREQ_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_SdlMid_MuxTqReq                                      */
/* !Description :  Moniteur rapide de la fonction                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_11_08258_001.01                                     */
/*                 VEMS_R_11_08258_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MUXTQREQ_vidEngStOpm();                                  */
/*  input uint8 MUXTQREQ_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  TqSys_SdlMid_MuxTqReq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_SdlMid_MuxTqReq(void)
{
   if (MUXTQREQ_u8Inhib != 0x5A)
   {
      MUXTQREQ_vidEngStOpm();
   }
}
/******************************* end of file **********************************/