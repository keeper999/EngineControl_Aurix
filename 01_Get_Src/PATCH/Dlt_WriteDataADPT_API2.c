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
/* !File            : Dlt_WriteDataADPT_API2.c                                */
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
/*   1 / DLT_WriteData_E00D                                                   */
/*   2 / DLT_WriteData_E050                                                   */
/*   3 / DLT_WriteData_E051                                                   */
/*   4 / DLT_WriteData_E052                                                   */
/*   5 / DLT_WriteData_E053                                                   */
/*   6 / DLT_WriteData_E03C                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/Dlt_WriteDataADPT_API2.c_v  $*/
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


/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E00D                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API2.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_TrbActSys_NVMID01_OP_ConditionCheckWrite(argout    */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf Rte_Call_R_DidServices_TrbActSys_NVMID01_OP_WriteData(????);         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E00D
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType u8localreturn;
   
   u8localreturn = E_OK;

   /* Conditions d'écriture */
   //u8localreturn =
     // Rte_Call_R_DidServices_TrbActSys_NVMID01_ConditionCheckWrite(
                    // ErrorCode);

   if(u8localreturn == E_OK)
   {
      //u8localreturn =
        // Rte_Call_R_DidServices_TrbActSys_NVMID01_WriteData(Data, DataLength,
                   //  ErrorCode);
   }

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E050                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API2.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID01_OP_ConditionCheckWrite(argout          */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf Rte_Call_R_DidServices_MPM_NVMID01_OP_WriteData(????);               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E050
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType u8localreturn;

  /* conditions d'écriture */
   // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID01_ConditionCheckWrite(ErrorCode);

   if(u8localreturn == E_OK)
   {
      // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID01_WriteData(Data, DataLength,
                  // ErrorCode);
   }

  return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E051                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API2.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID02_OP_ConditionCheckWrite(argout          */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf Rte_Call_R_DidServices_MPM_NVMID02_OP_WriteData(????);               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E051
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType u8localreturn;

  /* conditions d'écriture */
   // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID02_ConditionCheckWrite(ErrorCode);

   if(u8localreturn == E_OK)
   {
      // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID02_WriteData(Data, DataLength,
                  // ErrorCode);
   }

  return u8localreturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E052                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API2.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID05_OP_ConditionCheckWrite(argout          */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf Rte_Call_R_DidServices_MPM_NVMID05_OP_WriteData(????);               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E052
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType u8localreturn;

  // /* conditions d'écriture */
   // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID05_ConditionCheckWrite(ErrorCode);

   // if(u8localreturn == E_OK)
   // {
      // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID05_WriteData(Data, DataLength,
                  // ErrorCode);
   // }

  return u8localreturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E053                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API2.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID06_OP_ConditionCheckWrite(argout          */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf Rte_Call_R_DidServices_MPM_NVMID06_OP_WriteData(????);               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_WriteData_E053
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType                u8localreturn;

  /* conditions d'écriture */
   // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID06_ConditionCheckWrite(ErrorCode);

   if(u8localreturn == E_OK)
   {
      // u8localreturn =
         // Rte_Call_R_DidServices_MPM_NVMID06_WriteData(Data, DataLength,
                  // ErrorCode);
   }

  return u8localreturn;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_WriteData_E03C                                         */
/* !Description :  The Dcm_WriteData_XXXX callout is used to write data       */
/*                 identified by the parameter memoryAddress and memorySize.  */
/* !Number      :  WDATAADPT_API2.6                                           */
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
Std_ReturnType DLT_WriteData_E03C
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType                u8localreturn;

   if(DataLength == (uint16)(DATALENGTH_9))
   {
      // u8localreturn =
         // Rte_Call_R_ProdElEm_AftsNvramWrite_1_op_CoEmSTT_AftsNvramWrite_1(
                                                                 // (UInt8 *)Data);
   }
   else
   {
      u8localreturn = E_NOT_OK;
      *ErrorCode = DCM_E_INCORRECTLENGTH;
   }

   return u8localreturn;
}