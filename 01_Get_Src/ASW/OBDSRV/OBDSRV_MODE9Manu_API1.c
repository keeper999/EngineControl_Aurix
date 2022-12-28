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
/* !File            : OBDSRV_MODE9Manu_API1.c                                 */
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
/*   1 / OBDMODE9_Inftyp_04                                                   */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV/OBDSRV_MODE9Manu_$*/
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
#include "RTE.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE9_Inftyp_04                                         */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE9Manu_API1.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  REFIDETA_ConditionCheck_ReadData(argin        */
/*  Dcm_OpStatusType OpStatus, argin Dcm_NegativeResponseCodeType *ErrorCode);*/
/*  extf argret Std_ReturnType  REFIDETA_ReadData_Obd(argin Dcm_OpStatusType  */
/* OpStatus, argin uint8 *DataValueBuffer);                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE9_Inftyp_04
(
   Dcm_OpStatusType OpStatus,
   uint8* DataValueBuffer
)
{
   Std_ReturnType                u8LocalReturn;
   Dcm_NegativeResponseCodeType  dcmLocalErrorCode;

   u8LocalReturn =
            REFIDETA_ConditionCheck_ReadData(OpStatus,&dcmLocalErrorCode);

   if(u8LocalReturn == E_OK)
   {
      u8LocalReturn = REFIDETA_ReadData_Obd(OpStatus,DataValueBuffer);
   }

   return u8LocalReturn;
}
