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
/* !File            : Dlt_ReadDataADPT_API2.c                                 */
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
/*   1 / DLT_ConditionCheckRead_E00D                                          */
/*   2 / DLT_ReadDataLength_E00D                                              */
/*   3 / DLT_ReadData_E00D                                                    */
/*   4 / DLT_ConditionCheckRead_E050                                          */
/*   5 / DLT_ReadDataLength_E050                                              */
/*   6 / DLT_ReadData_E050                                                    */
/*   7 / DLT_ConditionCheckRead_E051                                          */
/*   8 / DLT_ReadDataLength_E051                                              */
/*   9 / DLT_ReadData_E051                                                    */
/*   10 / DLT_ConditionCheckRead_E052                                         */
/*   11 / DLT_ReadDataLength_E052                                             */
/*   12 / DLT_ReadData_E052                                                   */
/*   13 / DLT_ConditionCheckRead_E053                                         */
/*   14 / DLT_ReadDataLength_E053                                             */
/*   15 / DLT_ReadData_E053                                                   */
/*   16 / DLT_ConditionCheckRead_E01B                                         */
/*   17 / DLT_ReadDataLength_E01B                                             */
/*   18 / DLT_ReadData_E01B                                                   */
/*   19 / DLT_ConditionCheckRead_E03C                                         */
/*   20 / DLT_ReadDataLength_E03C                                             */
/*   21 / DLT_ReadData_E03C                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/Dlt_ReadDataADPT_API2.c_v   $*/
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
/* !Function    :  DLT_ConditionCheckRead_E00D                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAADPT_API2.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_TrbActSys_NVMID01_OP_ConditionCheckRead(argout     */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_E00D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{

   Std_ReturnType uLocalReturn;
   
   uLocalReturn = E_OK;

   //uLocalReturn =
      //Rte_Call_R_DidServices_TrbActSys_NVMID01_ConditionCheckRead(
               //ErrorCode);

   if(uLocalReturn == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return uLocalReturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E00D                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAADPT_API2.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_TrbActSys_NVMID01_OP_ReadDataLength(argout uint16  */
/*  *DataLength);                                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_E00D
(
   uint16* DataLength
)
{

   Std_ReturnType uLocalReturn;
   uint16         u16LocalDataLength;

   uLocalReturn = E_NOT_OK;
      //Rte_Call_R_DidServices_TrbActSys_NVMID01_ReadDataLength(
        //    &u16LocalDataLength);

   if(uLocalReturn == E_OK)
   {
      /* Il faut remonter la taille de la trame en bits */
      *DataLength = (uint16)(((u16LocalDataLength*8)>65535)?65535
                                                      :(u16LocalDataLength*8));
   }

   return uLocalReturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E00D                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAADPT_API2.3                                           */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E00D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{

   Std_ReturnType uLocalReturn;

   uLocalReturn = E_OK;
   //uLocalReturn =
         //Rte_Call_R_DidServices_TrbActSys_NVMID01_ReadData((UInt8 *)Data);

   return uLocalReturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E050                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAADPT_API2.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID01_OP_ConditionCheckRead(argout           */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_E050
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType uLocalReturn;

//   uLocalReturn =
  //       Rte_Call_R_DidServices_MPM_NVMID01_ConditionCheckRead(ErrorCode);

   if(uLocalReturn == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return uLocalReturn;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E050                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAADPT_API2.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID01_OP_ReadDataLength(argout uint16        */
/*  *DataLength);                                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_E050
(
   uint16* DataLength
)
{
   Std_ReturnType u8LocalRetunr;
   uint16         u16LocalDataLength;

 /*  u8LocalRetunr =
      Rte_Call_R_DidServices_MPM_NVMID01_ReadDataLength(&u16LocalDataLength);

   /* Il faut remonter la taille de la trame en bits */
   if(u8LocalRetunr == E_OK)
   {
      *DataLength = (uint16)(((u16LocalDataLength*8)>65535)?65535
                                                      :(u16LocalDataLength*8));
   }

   return u8LocalRetunr;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E050                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAADPT_API2.6                                           */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E050
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   Std_ReturnType u8LocalRetun;

  // u8LocalRetun = Rte_Call_R_DidServices_MPM_NVMID01_ReadData((UInt8 *)Data);

   return u8LocalRetun;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E051                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAADPT_API2.7                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID02_OP_ConditionCheckRead(argout           */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_E051
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType uLocalReturn;

  /* uLocalReturn =
      Rte_Call_R_DidServices_MPM_NVMID02_ConditionCheckRead(ErrorCode);
*/
   if(uLocalReturn == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return uLocalReturn;

}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E051                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAADPT_API2.8                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID02_OP_ReadDataLength(argout uint16        */
/*  *DataLength);                                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_E051
(
   uint16* DataLength
)
{
   Std_ReturnType u8LocalRetunr;
   uint16         u16LocalDataLength;

 /*  u8LocalRetunr =
      Rte_Call_R_DidServices_MPM_NVMID02_ReadDataLength(&u16LocalDataLength);

   /* Il faut remonter la taille de la trame en bits */
   if(u8LocalRetunr == E_OK)
   {
      *DataLength = (uint16)(((u16LocalDataLength*8)>65535)?65535
                                                      :(u16LocalDataLength*8));
   }

   return u8LocalRetunr;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E051                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAADPT_API2.9                                           */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E051
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   Std_ReturnType u8LocalRetun;

  // u8LocalRetun = Rte_Call_R_DidServices_MPM_NVMID02_ReadData((UInt8 *)Data);

   return u8LocalRetun;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E052                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAADPT_API2.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID05_OP_ConditionCheckRead(argout           */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_E052
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType uLocalReturn;

 /*  uLocalReturn =
      Rte_Call_R_DidServices_MPM_NVMID05_ConditionCheckRead(ErrorCode);
*/
   if(uLocalReturn == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return uLocalReturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E052                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAADPT_API2.11                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID05_OP_ReadDataLength(argout uint16        */
/*  *DataLength);                                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_E052
(
   uint16* DataLength
)
{
   Std_ReturnType u8LocalRetunr;
   uint16         u16LocalDataLength;

  /* u8LocalRetunr =
      Rte_Call_R_DidServices_MPM_NVMID05_ReadDataLength(&u16LocalDataLength);

   /* Il faut remonter la taille de la trame en bits */
   if(u8LocalRetunr == E_OK)
   {
      *DataLength = (uint16)(((u16LocalDataLength*8)>65535)?65535
                                                      :(u16LocalDataLength*8));
   }

   return u8LocalRetunr;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E052                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAADPT_API2.12                                          */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E052
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   Std_ReturnType u8LocalRetun;

//   u8LocalRetun = Rte_Call_R_DidServices_MPM_NVMID05_ReadData((UInt8 *)Data);

   return u8LocalRetun;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E053                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAADPT_API2.13                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID06_OP_ConditionCheckRead(argout           */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_E053
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType uLocalReturn;

 /*  uLocalReturn =
      Rte_Call_R_DidServices_MPM_NVMID06_ConditionCheckRead(ErrorCode);
*/
   if(uLocalReturn == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return uLocalReturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E053                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAADPT_API2.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_DidServices_MPM_NVMID06_OP_ReadDataLength(argout uint16        */
/*  *DataLength);                                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_E053
(
   uint16* DataLength
)
{
   Std_ReturnType u8LocalRetunr;
   uint16         u16LocalDataLength;

  /* u8LocalRetunr =
      Rte_Call_R_DidServices_MPM_NVMID06_ReadDataLength(&u16LocalDataLength);

   /* Il faut remonter la taille de la trame en bits */
   if(u8LocalRetunr == E_OK)
   {
      *DataLength = (uint16)(((u16LocalDataLength*8)>65535)?65535
                                                      :(u16LocalDataLength*8));
   }

   return u8LocalRetunr;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E053                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAADPT_API2.15                                          */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E053
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   Std_ReturnType u8LocalRetun;

 //  u8LocalRetun = Rte_Call_R_DidServices_MPM_NVMID06_ReadData((UInt8 *)Data);

   return u8LocalRetun;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E01B                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAADPT_API2.16                                          */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_E01B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
  Std_ReturnType u8LocalRetun;

  /* u8LocalRetun =
      Rte_Call_R_DfwCtl_AftsNvramRead_1_DfwCtl_AftsNvramRead_1(
                                          (UInt8 *)DCM_MANU_Data_DADAPT);
*/
   if(u8LocalRetun == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return u8LocalRetun;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E01B                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAADPT_API2.17                                          */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_E01B
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(DCM_MANU_DATALENGTH_E01B*8);
   return E_OK;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E01B                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAADPT_API2.18                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DCM_MANU_Data_DADAPT[33];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E01B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 index;

   for(index=0; index<DCM_MANU_DATALENGTH_E01B; index++)
   {
      Data[index] = DCM_MANU_Data_DADAPT[index];
   }

   return E_OK;

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E03C                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAADPT_API2.19                                          */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_E03C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType u8LocalRetun;

  /* u8LocalRetun =
      Rte_Call_R_ProdElEm_AftsNvramRead_1_op_ProdElEm_AftsNvramRead_1(
                                                 (UInt8 *)DCM_MANU_Data_DADAPT);
*/
   if(u8LocalRetun == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return u8LocalRetun;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E03C                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAADPT_API2.20                                          */
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
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_E03C
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(DATALENGTH_9*8);
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E03C                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAADPT_API2.20                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DCM_MANU_Data_DADAPT[33];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E03C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 index;

   for(index=0; index<DATALENGTH_9; index++)
   {
      Data[index] = DCM_MANU_Data_DADAPT[index];
   }

   return E_OK;
}