/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TELECODAGE                                              */
/* !Description     : TELECODAGE component.                                   */
/*                                                                            */
/* !Module          : TELECODAGE                                              */
/* !Description     : PROCÉDURE DE TÉLÉCODAGE SÉCURISÉ                        */
/*                                                                            */
/* !File            : TELECODAGE_API.C                                        */
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
/*   1 / Srv_EveErrTeleWr_TeleSrv                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5074365 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066577                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TELECODAGE/TELECODAGE_API.C_v   $*/
/* $Revision::   1.7      $$Author::   pbakabad       $$Date::   Jul 29 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 29 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TELECODAGE.h"
#include "TELECODAGE_L.h"
#include "TELECODAGE_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveErrTeleWr_TeleSrv                                   */
/* !Description :  Evénément mauvaise écriture du télécodage en eeprom        */
/* !Number      :  API.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TELECODAGE_vidReInit();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveErrTeleWr_TeleSrv(void)
{
   TELECODAGE_vidReInit();
}

/*------------------------------- end of file --------------------------------*/