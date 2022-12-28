/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : REFIDETA                                                */
/* !Description     : REFIDETA component                                      */
/*                                                                            */
/* !Module          : REFIDETA                                                */
/* !Description     : Gestion de la reference d'identification etalonnage     */
/*                                                                            */
/* !File            : REFIDETA_Sch.c                                          */
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
/*   1 / Srv_EveRst_RefIdEta                                                  */
/*   2 / Srv_SdlFast_RefIdEta                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 00995 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#056261                                         */
/* !OtherRefs   : VEMS V02 ECU#065790                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/REFIDETA/REFIDETA_Sch.c_v       $*/
/* $Revision::   1.3      $$Author::   pbakabad       $$Date::   Jun 11 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 11 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "REFIDETA_im.h"
#include "REFIDETA.h"
#include "REFIDETA_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRst_RefIdEta                                        */
/* !Description :  Function called at the initialisation                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void REFIDETA_Init();                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveRst_RefIdEta                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRst_RefIdEta(void)
{
   REFIDETA_Init();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlFast_RefIdEta                                       */
/* !Description :  fonction call at the Fast KRN event                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void REFIDETA_sdlFast();                                      */
/*  input uint8 REFIDETA_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_SdlFast_RefIdEta                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlFast_RefIdEta(void)
{
   if(REFIDETA_u8Inhib != 0x5A)
   {
      REFIDETA_sdlFast();
   }
}