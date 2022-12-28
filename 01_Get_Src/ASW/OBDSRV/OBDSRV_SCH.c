/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OBDSRV                                                  */
/* !Description     : OBDSRV Component                                        */
/*                                                                            */
/* !Module          : OBDSRV                                                  */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : OBDSRV_SCH.c                                            */
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
/*   1 / Srv_EveCrcChkEnd_ObdSrv                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV/OBDSRV_SCH.c_v   $*/
/* $Revision::   1.8      $$Author::   pbakabad       $$Date::   Jul 02 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 02 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/




#include "STD_TYPES.h"
#include "OBDSRV.h"
#include "OBDSRV_L.h"
#include "OBDSRV_im.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveCrcChkEnd_ObdSrv                                    */
/* !Description :  Evènement vérification du CRC Data de l'IET terminée (OK ou*/
/*                 pas OK)                                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_06099_001.01                                     */
/*                 VEMS_E_11_06099_002.01                                     */
/*                 VEMS_E_11_06099_003.01                                     */
/*                 VEMS_E_11_06099_004.01                                     */
/*                 VEMS_E_11_06099_005.01                                     */
/*                 VEMS_E_11_06099_006.01                                     */
/*                 VEMS_E_11_06099_007.01                                     */
/*                 VEMS_E_11_06099_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Srv_SdlFast_RefIdEta();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveCrcChkEnd_ObdSrv                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveCrcChkEnd_ObdSrv(void)
{
   Srv_SdlFast_RefIdEta();
}