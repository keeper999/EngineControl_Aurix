/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : DLT_OBDMode09_API1.c                                    */
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
/*   1 / DLT_GetInfotypeValueData_04                                          */
/*   2 / DLT_GetInfotypeValueData_08                                          */
/*   3 / DLT_GetInfotypeValueData_Stub                                        */
/*   4 / DLT_GetInfotypeValueData_02                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DLT$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Dlt.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_GetInfotypeValueData_04                                */
/* !Description :  Is called from Dcm when OBD mode 09 request is received.   */
/* !Number      :  OBDMode09_API1.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE9_Inftyp_04(argin Dcm_OpStatusType     */
/*  OpStatus, argout uint8 *DataValueBuffer);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_GetInfotypeValueData_04
(
   Dcm_OpStatusType OpStatus,
   uint8* DataValueBuffer
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE9_Inftyp_04( OpStatus, &DataValueBuffer[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_GetInfotypeValueData_08                                */
/* !Description :  Is called from Dcm when OBD mode 09 request is received.   */
/* !Number      :  OBDMode09_API1.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE9_Inftyp_08(argout uint8 *Data);       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_GetInfotypeValueData_08
(
   Dcm_OpStatusType OpStatus,
   uint8* DataValueBuffer
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE9_Inftyp_08( &DataValueBuffer[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_GetInfotypeValueData_Stub                              */
/* !Description :  Is called from Dcm when OBD mode 09 request is received.   */
/* !Number      :  OBDMode09_API1.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_GetInfotypeValueData_Stub
(
   Dcm_OpStatusType OpStatus,
   uint8* DataValueBuffer
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_GetInfotypeValueData_02                                */
/* !Description :  Is called from Dcm when OBD mode 09 request is received.   */
/* !Number      :  OBDMode09_API1.4                                           */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_06099_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE9_Inftyp_02(argout uint8 *Data);       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_GetInfotypeValueData_02
(
   Dcm_OpStatusType OpStatus,
   uint8* DataValueBuffer
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE9_Inftyp_02( &DataValueBuffer[0] );

   return u8LocalReturn;
}