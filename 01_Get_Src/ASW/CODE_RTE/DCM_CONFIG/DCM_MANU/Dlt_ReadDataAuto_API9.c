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
/* !File            : Dlt_ReadDataAuto_API9.c                                 */
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
/*   1 / DLT_ConditionCheckRead_E038                                          */
/*   2 / DLT_ReadDataLength_E038                                              */
/*   3 / DLT_ReadData_E038                                                    */
/*   4 / DLT_ConditionCheckRead_E035                                          */
/*   5 / DLT_ReadDataLength_E035                                              */
/*   6 / DLT_ReadData_E035                                                    */
/*   7 / DLT_ConditionCheckRead_E034                                          */
/*   8 / DLT_ReadDataLength_E034                                              */
/*   9 / DLT_ReadData_E034                                                    */
/*   10 / DLT_ConditionCheckRead_E037                                         */
/*   11 / DLT_ReadDataLength_E037                                             */
/*   12 / DLT_ReadData_E037                                                   */
/*   13 / DLT_ConditionCheckRead_E036                                         */
/*   14 / DLT_ReadDataLength_E036                                             */
/*   15 / DLT_ReadData_E036                                                   */
/*   16 / DLT_ConditionCheckRead_E031                                         */
/*   17 / DLT_ReadDataLength_E031                                             */
/*   18 / DLT_ReadData_E031                                                   */
/*   19 / DLT_ConditionCheckRead_E03A                                         */
/*   20 / DLT_ReadDataLength_E03A                                             */
/*   21 / DLT_ReadData_E03A                                                   */
/*   22 / DLT_ConditionCheckRead_E033                                         */
/*   23 / DLT_ReadDataLength_E033                                             */
/*   24 / DLT_ReadData_E033                                                   */
/*   25 / DLT_ConditionCheckRead_E032                                         */
/*   26 / DLT_ReadDataLength_E032                                             */
/*   27 / DLT_ReadData_E032                                                   */
/*   28 / DLT_ConditionCheckRead_E039                                         */
/*   29 / DLT_ReadDataLength_E039                                             */
/*   30 / DLT_ReadData_E039                                                   */
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
/* !Function    :  DLT_ConditionCheckRead_E038                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.1                                        */
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
Std_ReturnType DLT_ConditionCheckRead_E038
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E038                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.2                                        */
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
Std_ReturnType DLT_ReadDataLength_E038
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E038                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.3                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus8[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E038
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus8[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus8,11,
                              u8LocalVSCtl_prmLstCrsCtlDeacCaus8);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus8[10];

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E035                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.4                                        */
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
Std_ReturnType DLT_ConditionCheckRead_E035
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E035                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.5                                        */
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
Std_ReturnType DLT_ReadDataLength_E035
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E035                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.6                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus5[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E035
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus5[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus5,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus5);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus5[10];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E034                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.7                                        */
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
Std_ReturnType DLT_ConditionCheckRead_E034
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E034                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.8                                        */
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
Std_ReturnType DLT_ReadDataLength_E034
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E034                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.9                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus4[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E034
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus4[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus4,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus4);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus4[10];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E037                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.10                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E037
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E037                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.11                                       */
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
Std_ReturnType DLT_ReadDataLength_E037
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E037                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.12                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus7[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E037
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus7[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus7,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus7);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus7[10];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E036                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.13                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E036
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E036                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.14                                       */
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
Std_ReturnType DLT_ReadDataLength_E036
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E036                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.15                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus6[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E036
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus6[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus6,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus6);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus6[10];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E031                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.16                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E031
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E031                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.17                                       */
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
Std_ReturnType DLT_ReadDataLength_E031
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E031                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.18                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus1[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E031
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus1[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus1,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus1);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus1[10];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E03A                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.19                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E03A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E03A                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.20                                       */
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
Std_ReturnType DLT_ReadDataLength_E03A
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E03A                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.21                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus10[11];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E03A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus10[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus10,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus10);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus10[10];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E033                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.22                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E033
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E033                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.23                                       */
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
Std_ReturnType DLT_ReadDataLength_E033
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E033                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.24                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus3[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E033
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus3[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus3,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus3);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus3[10];

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E032                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.25                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E032
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E032                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.26                                       */
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
Std_ReturnType DLT_ReadDataLength_E032
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E032                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.27                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus2[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E032
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus2[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus2,11,
                                 u8LocalVSCtl_prmLstCrsCtlDeacCaus2);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus2[10];

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E039                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  ReadDataAuto_API9.28                                       */
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
Std_ReturnType DLT_ConditionCheckRead_E039
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E039                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  ReadDataAuto_API9.29                                       */
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
Std_ReturnType DLT_ReadDataLength_E039
(
   uint16* DataLength
)
{
   *DataLength = (uint16)(8*DATALENGTH_11);
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E039                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  ReadDataAuto_API9.30                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus9[11];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E039
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVSCtl_prmLstCrsCtlDeacCaus9[11];

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus9,11,
                              u8LocalVSCtl_prmLstCrsCtlDeacCaus9);

   Data[0] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[0];
   Data[1] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[1];
   Data[2] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[2];
   Data[3] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[3];
   Data[4] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[4];
   Data[5] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[5];
   Data[6] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[6];
   Data[7] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[7];
   Data[8] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[8];
   Data[9] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[9];
   Data[10] = u8LocalVSCtl_prmLstCrsCtlDeacCaus9[10];

   return E_OK;
}

