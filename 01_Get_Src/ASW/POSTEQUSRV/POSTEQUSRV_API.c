/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : POSTEQUSRV                                              */
/* !Description     : POSTEQUSRV Component                                    */
/*                                                                            */
/* !Module          : POSTEQUSRV                                              */
/* !Description     : COHERENCE CAN INFOS_EOBD_BSI                            */
/*                                                                            */
/* !File            : POSTEQUSRV_API.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Srv_EveErrPostEquWr_PostEquSrv                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5074440 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066576                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "POSTEQUSRV.h"
#include "POSTEQUSRV_L.h"
#include "POSTEQUSRV_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveErrPostEquWr_PostEquSrv                             */
/* !Description :  Evénément mauvaise écriture du Post Equipement en eeprom   */
/* !Number      :  API.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void POSTEQUSRV_vidReInit();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveErrPostEquWr_PostEquSrv(void)
{
   POSTEQUSRV_vidReInit();
}
/*------------------------------- end of file --------------------------------*/