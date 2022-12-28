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
/* !File            : Dlt_WriteDataADPT_API1.c                                */
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
/*   1 / DLT_WriteData_E019                                                   */
/*   2 / DLT_WriteData_E018                                                   */
/*   3 / DLT_WriteData_E017                                                   */
/*   4 / DLT_WriteData_E014                                                   */
/*   5 / DLT_WriteData_E013                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/Dlt_WriteDataADPT_API1.c_v  $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   02 Jul 2014 $*/
/* $Author::   croche2                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Dlt.h"
//#include "Rte_DCM_MANU.h"
#include "Rte_VirtualComponent.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E019                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API1.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E019
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType status;

   if(DataLength == (uint16)(DCM_MANU_DATALENGTH_E019))
   {
      // status = Rte_Call_R_ThMgt_AftsNvramWrite_1_op_ThMgt_AftsNvramWrite_1(
            // (UInt8 *)Data);
   }
   else
   {
      status = E_NOT_OK;
      *ErrorCode = DCM_E_INCORRECTLENGTH;
   }

   return status;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E018                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API1.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E018
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType status;

   if(DataLength == (uint16)(DCM_MANU_DATALENGTH_E018))
   {
      // status =
           // Rte_Call_R_ProdElEng_AftsNvramWrite_1_op_ProdElEng_AftsNvramWrite_1(
            // (UInt8 *)Data);
   }
   else
   {
      status = E_NOT_OK;
      *ErrorCode = DCM_E_INCORRECTLENGTH;
   }

   return status;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E017                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API1.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E017
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType status;

   if(DataLength == (uint16)(DATALENGTH_24))
   {
      // status =
         // Rte_Call_R_StopStrtEm_AftsNvramWrite_1_op_StopStrtEm_AftsNvramWrite_1(
               // (UInt8 *)Data);
   }
   else
   {
      status = E_NOT_OK;
      *ErrorCode = DCM_E_INCORRECTLENGTH;
   }

   return status;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E014                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API1.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E014
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType status;

   if(DataLength == (uint16)(DATALENGTH_16))
   {
      // status = Rte_Call_R_CoEmSTT_AftsNvramWrite_1_op_CoEmSTT_AftsNvramWrite_1(
               // (UInt8 *)Data);
   }
   else
   {
      status = E_NOT_OK;
      *ErrorCode = DCM_E_INCORRECTLENGTH;
   }

   return status;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E013                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API1.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E013
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType status;

   if(DataLength == (uint16)(DATALENGTH_21))
   {
      // status =
         // Rte_Call_R_CoStopStart_AftsNvramWrite_1_CoStopStart_AftsNvramWrite_1(
                  // (UInt8 *)Data);
   }
   else
   {
      status = E_NOT_OK;
      *ErrorCode = DCM_E_INCORRECTLENGTH;
   }

   return status;
}