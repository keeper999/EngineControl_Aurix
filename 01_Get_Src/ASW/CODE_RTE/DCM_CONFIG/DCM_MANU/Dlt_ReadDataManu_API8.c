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
/* !File            : Dlt_ReadDataManu_API8.c                                 */
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
/*   1 / DLT_ConditionCheckRead_0D01                                          */
/*   2 / DLT_ReadDataLength_0D01                                              */
/*   3 / DLT_ReadData_0D01                                                    */
/*   4 / DLT_ConditionCheckRead_E040                                          */
/*   5 / DLT_ReadDataLength_E040                                              */
/*   6 / DLT_ReadData_E040                                                    */
/*   7 / DLT_ConditionCheckRead_E041                                          */
/*   8 / DLT_ReadDataLength_E041                                              */
/*   9 / DLT_ReadData_E041                                                    */
/*   10 / DLT_ConditionCheckRead_E042                                         */
/*   11 / DLT_ReadDataLength_E042                                             */
/*   12 / DLT_ReadData_E042                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Dlt.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_0D01                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataMANU_API8.4                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DLT_ConditionCheckRead_F18C(argin             */
/*  Dcm_OpStatusType OpStatus, argout Dcm_NegativeResponseCodeType            */
/*  *ErrorCode);                                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_0D01
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType uLocalReturn;

   uLocalReturn = DLT_ConditionCheckRead_F18C(OpStatus,ErrorCode);

   return uLocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_0D01                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataMANU_API8.5                                        */
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
Std_ReturnType DLT_ReadDataLength_0D01
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(DATALENGTH_1*8);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_0D01                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataMANU_API8.6                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 DCM_MANU_sizeECUIdentification;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_0D01
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{

   *Data = (uint8)(DCM_MANU_sizeECUIdentification & 0x00FF);

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E040                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataMANU_API8.7                                        */
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
Std_ReturnType DLT_ConditionCheckRead_E040
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E040                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataMANU_API8.8                                        */
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
Std_ReturnType DLT_ReadDataLength_E040
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(DATALENGTH_10*8);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E040                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataMANU_API8.9                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint32 SpyEmSTT_prmHisDstWin1[2];                                   */
/*  input uint8 SpyEmSTT_prmHistNotStopCase1[7];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E040
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalSpyEmSTT_prmHisDstWin1;
   uint8    a8LocalSpyEmSTT_prmHistNotStopCase1[DATALENGTH_7];

   VEMS_vidGET1DArrayElement(SpyEmSTT_prmHisDstWin1,0,
                                    u32LocalSpyEmSTT_prmHisDstWin1);
   VEMS_vidGET1DArray(SpyEmSTT_prmHistNotStopCase1,DATALENGTH_7,
                                    a8LocalSpyEmSTT_prmHistNotStopCase1);

   Data[0] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin1 & 0x00FF0000) >> 16);
   Data[1] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin1 & 0x0000FF00) >> 8);
   Data[2] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin1 & 0x000000FF));
   Data[3] = a8LocalSpyEmSTT_prmHistNotStopCase1[0];
   Data[4] = a8LocalSpyEmSTT_prmHistNotStopCase1[1];
   Data[5] = a8LocalSpyEmSTT_prmHistNotStopCase1[2];
   Data[6] = a8LocalSpyEmSTT_prmHistNotStopCase1[3];
   Data[7] = a8LocalSpyEmSTT_prmHistNotStopCase1[4];
   Data[8] = a8LocalSpyEmSTT_prmHistNotStopCase1[5];
   Data[9] = a8LocalSpyEmSTT_prmHistNotStopCase1[6];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E041                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataMANU_API8.10                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E041
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E041                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataMANU_API8.11                                       */
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
Std_ReturnType DLT_ReadDataLength_E041
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(DATALENGTH_10*8);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E041                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataMANU_API8.12                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input sint32 SpyEmSTT_prmHisDstWin2[2];                                   */
/*  input uint8 SpyEmSTT_prmHistNotStopCase2[7];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E041
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalSpyEmSTT_prmHisDstWin2;
   uint8    a8LocalSpyEmSTT_prmHistNotStopCase2[DATALENGTH_7];

   VEMS_vidGET1DArrayElement(SpyEmSTT_prmHisDstWin2,0,
                                    u32LocalSpyEmSTT_prmHisDstWin2);
   VEMS_vidGET1DArray(SpyEmSTT_prmHistNotStopCase2,DATALENGTH_7,
                                    a8LocalSpyEmSTT_prmHistNotStopCase2);

   Data[0] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin2 & 0x00FF0000) >> 16);
   Data[1] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin2 & 0x0000FF00) >> 8);
   Data[2] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin2 & 0x000000FF));
   Data[3] = a8LocalSpyEmSTT_prmHistNotStopCase2[0];
   Data[4] = a8LocalSpyEmSTT_prmHistNotStopCase2[1];
   Data[5] = a8LocalSpyEmSTT_prmHistNotStopCase2[2];
   Data[6] = a8LocalSpyEmSTT_prmHistNotStopCase2[3];
   Data[7] = a8LocalSpyEmSTT_prmHistNotStopCase2[4];
   Data[8] = a8LocalSpyEmSTT_prmHistNotStopCase2[5];
   Data[9] = a8LocalSpyEmSTT_prmHistNotStopCase2[6];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E042                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataMANU_API8.13                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E042
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E042                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataMANU_API8.14                                       */
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
Std_ReturnType DLT_ReadDataLength_E042
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(DATALENGTH_10*8);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E042                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataMANU_API8.15                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input sint32 SpyEmSTT_prmHisDstWin3[2];                                   */
/*  input uint8 SpyEmSTT_prmHistNotStopCase3[7];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E042
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalSpyEmSTT_prmHisDstWin3;
   uint8    a8LocalSpyEmSTT_prmHistNotStopCase3[DATALENGTH_7];

   VEMS_vidGET1DArrayElement(SpyEmSTT_prmHisDstWin3,0,
                                    u32LocalSpyEmSTT_prmHisDstWin3);
   VEMS_vidGET1DArray(SpyEmSTT_prmHistNotStopCase3,DATALENGTH_7,
                                    a8LocalSpyEmSTT_prmHistNotStopCase3);

   Data[0] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin3 & 0x00FF0000) >> 16);
   Data[1] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin3 & 0x0000FF00) >> 8);
   Data[2] = (uint8)((u32LocalSpyEmSTT_prmHisDstWin3 & 0x000000FF));
   Data[3] = a8LocalSpyEmSTT_prmHistNotStopCase3[0];
   Data[4] = a8LocalSpyEmSTT_prmHistNotStopCase3[1];
   Data[5] = a8LocalSpyEmSTT_prmHistNotStopCase3[2];
   Data[6] = a8LocalSpyEmSTT_prmHistNotStopCase3[3];
   Data[7] = a8LocalSpyEmSTT_prmHistNotStopCase3[4];
   Data[8] = a8LocalSpyEmSTT_prmHistNotStopCase3[5];
   Data[9] = a8LocalSpyEmSTT_prmHistNotStopCase3[6];

   return E_OK;
}

