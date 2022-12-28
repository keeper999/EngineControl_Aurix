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
/* !File            : Dlt_WriteDataManu_API1.c                                */
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
/*   1 / DLT_WriteData_2101                                                   */
/*   2 / DLT_WriteData_D500                                                   */
/*   3 / DLT_WriteData_F196                                                   */
/*   4 / DLT_WriteData_D420                                                   */
/*   5 / DLT_WriteData_2102                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.1      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Dlt.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_WriteTelecodageMngt(argout uint8     */
/*  *Data_in, argin uint16 DataLength_in, argin Dcm_OpStatusType OpStatus_in, */
/*  argout Dcm_NegativeResponseCodeType *ErrorCode_out);                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_WriteData_2101
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType u8localreturn;

   u8localreturn = DCM_MANU_WriteTelecodageMngt( Data,
                                                 DataLength,
                                                 OpStatus,
                                                 ErrorCode );

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_D500                                         */
/* !Description :  The DLT_WriteData_D500 callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAMANU_API1.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_WriteCaracInj(argout uint8 *Data_in, */
/*  argin uint16 DataLength_in, argin Dcm_OpStatusType OpStatus_in, argout    */
/*  Dcm_NegativeResponseCodeType *ErrorCode_out);                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_WriteData_D500
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType u8localreturn;

   u8localreturn = DCM_MANU_WriteCaracInj( Data,
                                           DataLength,
                                           OpStatus,
                                           ErrorCode );

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_F196                                         */
/* !Description :  The DLT_WriteData_F196 callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAMANU_API1.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  REFIDETA_WriteData(argout uint8 *Data, argin  */
/*  uint16 DataLength, argin Dcm_OpStatusType OpStatus, argout                */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_WriteData_F196
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType               u8localreturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;

   u8localreturn = REFIDETA_WriteData( Data,
                                       DataLength,
                                       OpStatus,
                                       &u8LocalErrorCode );

   *ErrorCode = u8LocalErrorCode;

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_D420                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAMANU_API1.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Srv_tiBypCntOverNEngMax;                                     */
/*  output boolean Srv_bBypCntOverNEngMax;                                    */
/*  output uint16 Srv_tiCntOverNEngMax;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_WriteData_D420
(
   uint8* Data,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16 u16LocalSrv_tiCntOverNEngMax;

   Srv_tiBypCntOverNEngMax = 0;

   VEMS_vidSET(Srv_bBypCntOverNEngMax,1);

   u16LocalSrv_tiCntOverNEngMax =
                  (uint16)(((uint16)Data[0] << 8) | (uint16)Data[1]);

   VEMS_vidSET(Srv_tiCntOverNEngMax,u16LocalSrv_tiCntOverNEngMax);

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_WritePostEquipementMngt(argout uint8 */
/*  *Data_in, argin uint16 DataLength_in, argin Dcm_OpStatusType OpStatus_in, */
/*  argout Dcm_NegativeResponseCodeType *ErrorCode_out);                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_2102
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType u8localreturn;

   u8localreturn = DCM_MANU_WritePostEquipementMngt(  Data,
                                                      DataLength,
                                                      OpStatus,
                                                      ErrorCode );

   return u8localreturn;
}