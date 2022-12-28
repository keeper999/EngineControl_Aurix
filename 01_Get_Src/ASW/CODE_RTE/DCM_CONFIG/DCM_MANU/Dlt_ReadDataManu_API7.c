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
/* !File            : Dlt_ReadDataManu_API7.c                                 */
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
/*   1 / DLT_ConditionCheckRead_E043                                          */
/*   2 / DLT_ReadDataLength_E043                                              */
/*   3 / DLT_ReadData_E043                                                    */
/*   4 / DLT_ConditionCheckRead_E044                                          */
/*   5 / DLT_ReadDataLength_E044                                              */
/*   6 / DLT_ReadData_E044                                                    */
/*   7 / DLT_ConditionCheckRead_E045                                          */
/*   8 / DLT_ReadDataLength_E045                                              */
/*   9 / DLT_ReadData_E045                                                    */
/*   10 / DLT_ConditionCheckRead_F18C                                         */
/*   11 / DLT_ReadDataLength_F18C                                             */
/*   12 / DLT_ReadData_F18C                                                   */
/*   13 / DLT_ConditionCheckRead_D420                                         */
/*   14 / DLT_ReadData_D420                                                   */
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

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E043                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API7.1                                           */
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
Std_ReturnType DLT_ConditionCheckRead_E043
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E043                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API7.2                                           */
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
Std_ReturnType DLT_ReadDataLength_E043
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(14*8);
   return E_OK;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E043                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API7.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint32 SpySTT_prmHisDstWin1[2];                                     */
/*  input uint8 SpySTT_prmHisNotStopCase1[11];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E043
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalSpySTT_prmHisDstWin1;
   uint8    a8LocalSpySTT_prmHisNotStopCase1[11];

   VEMS_vidGET1DArrayElement(SpySTT_prmHisDstWin1,0,
                              u32LocalSpySTT_prmHisDstWin1);
   VEMS_vidGET1DArray(SpySTT_prmHisNotStopCase1,11,
                              a8LocalSpySTT_prmHisNotStopCase1);

   Data[0] = (uint8)((u32LocalSpySTT_prmHisDstWin1 & 0x00FF0000) >> 16);
   Data[1] = (uint8)((u32LocalSpySTT_prmHisDstWin1 & 0x0000FF00) >> 8);
   Data[2] = (uint8)((u32LocalSpySTT_prmHisDstWin1 & 0x000000FF));
   Data[3] = a8LocalSpySTT_prmHisNotStopCase1[0];
   Data[4] = a8LocalSpySTT_prmHisNotStopCase1[1];
   Data[5] = a8LocalSpySTT_prmHisNotStopCase1[2];
   Data[6] = a8LocalSpySTT_prmHisNotStopCase1[3];
   Data[7] = a8LocalSpySTT_prmHisNotStopCase1[4];
   Data[8] = a8LocalSpySTT_prmHisNotStopCase1[5];
   Data[9] = a8LocalSpySTT_prmHisNotStopCase1[6];
   Data[10] = a8LocalSpySTT_prmHisNotStopCase1[7];
   Data[11] = a8LocalSpySTT_prmHisNotStopCase1[8];
   Data[12] = a8LocalSpySTT_prmHisNotStopCase1[9];
   Data[13] = a8LocalSpySTT_prmHisNotStopCase1[10];

   return E_OK;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E044                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API7.4                                           */
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
Std_ReturnType DLT_ConditionCheckRead_E044
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E044                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API7.5                                           */
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
Std_ReturnType DLT_ReadDataLength_E044
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(14*8);
   return E_OK;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E044                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API7.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint32 SpySTT_prmHisDstWin2[2];                                     */
/*  input uint8 SpySTT_prmHisNotStopCase2[11];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E044
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalSpySTT_prmHisDstWin2;
   uint8    a8LocalSpySTT_prmHisNotStopCase2[11];

   VEMS_vidGET1DArrayElement(SpySTT_prmHisDstWin2,0,
                              u32LocalSpySTT_prmHisDstWin2);
   VEMS_vidGET1DArray(SpySTT_prmHisNotStopCase2,11,
                              a8LocalSpySTT_prmHisNotStopCase2);

   Data[0] = (uint8)((u32LocalSpySTT_prmHisDstWin2 & 0x00FF0000) >> 16);
   Data[1] = (uint8)((u32LocalSpySTT_prmHisDstWin2 & 0x0000FF00) >> 8);
   Data[2] = (uint8)((u32LocalSpySTT_prmHisDstWin2 & 0x000000FF));
   Data[3] = a8LocalSpySTT_prmHisNotStopCase2[0];
   Data[4] = a8LocalSpySTT_prmHisNotStopCase2[1];
   Data[5] = a8LocalSpySTT_prmHisNotStopCase2[2];
   Data[6] = a8LocalSpySTT_prmHisNotStopCase2[3];
   Data[7] = a8LocalSpySTT_prmHisNotStopCase2[4];
   Data[8] = a8LocalSpySTT_prmHisNotStopCase2[5];
   Data[9] = a8LocalSpySTT_prmHisNotStopCase2[6];
   Data[10] = a8LocalSpySTT_prmHisNotStopCase2[7];
   Data[11] = a8LocalSpySTT_prmHisNotStopCase2[8];
   Data[12] = a8LocalSpySTT_prmHisNotStopCase2[9];
   Data[13] = a8LocalSpySTT_prmHisNotStopCase2[10];

   return E_OK;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_E045                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API7.7                                           */
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
Std_ReturnType DLT_ConditionCheckRead_E045
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;

}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_E045                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API7.8                                           */
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
Std_ReturnType DLT_ReadDataLength_E045
(
   uint16* DataLength
)
{
  /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(14*8);
   return E_OK;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_E045                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API7.9                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint32 SpySTT_prmHisDstWin3[2];                                     */
/*  input uint8 SpySTT_prmHisNotStopCase3[11];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_E045
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalSpySTT_prmHisDstWin3;
   uint8    a8LocalSpySTT_prmHisNotStopCase3[11];

   VEMS_vidGET1DArrayElement(SpySTT_prmHisDstWin3,0,
                              u32LocalSpySTT_prmHisDstWin3);
   VEMS_vidGET1DArray(SpySTT_prmHisNotStopCase3,11,
                              a8LocalSpySTT_prmHisNotStopCase3);

   Data[0] = (uint8)((u32LocalSpySTT_prmHisDstWin3 & 0x00FF0000) >> 16);
   Data[1] = (uint8)((u32LocalSpySTT_prmHisDstWin3 & 0x0000FF00) >> 8);
   Data[2] = (uint8)((u32LocalSpySTT_prmHisDstWin3 & 0x000000FF));
   Data[3] = a8LocalSpySTT_prmHisNotStopCase3[0];
   Data[4] = a8LocalSpySTT_prmHisNotStopCase3[1];
   Data[5] = a8LocalSpySTT_prmHisNotStopCase3[2];
   Data[6] = a8LocalSpySTT_prmHisNotStopCase3[3];
   Data[7] = a8LocalSpySTT_prmHisNotStopCase3[4];
   Data[8] = a8LocalSpySTT_prmHisNotStopCase3[5];
   Data[9] = a8LocalSpySTT_prmHisNotStopCase3[6];
   Data[10] = a8LocalSpySTT_prmHisNotStopCase3[7];
   Data[11] = a8LocalSpySTT_prmHisNotStopCase3[8];
   Data[12] = a8LocalSpySTT_prmHisNotStopCase3[9];
   Data[13] = a8LocalSpySTT_prmHisNotStopCase3[10];

   return E_OK;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_F18C                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API7.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint16  SUPSRV_u16ECUIdentification(argio uint8 *pau8Buffer,  */
/*  argin uint16 u16MaxSize);                                                 */
/*  input uint8 DataBuffer[24];                                               */
/*  input uint16 DCM_MANU_sizeECUIdentification;                              */
/*  output uint16 DCM_MANU_sizeECUIdentification;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_F18C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType uLocalReturn;

   uLocalReturn = E_OK;

   DCM_MANU_sizeECUIdentification = SUPSRV_u16ECUIdentification(DataBuffer,
            BUF_SIZE);

   if((DCM_MANU_sizeECUIdentification == 0)
      || (DCM_MANU_sizeECUIdentification > BUF_SIZE))
   {
      uLocalReturn = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return uLocalReturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_F18C                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API7.11                                          */
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
Std_ReturnType DLT_ReadDataLength_F18C
(
   uint16* DataLength
)
{
    /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(((DCM_MANU_sizeECUIdentification*8)>65535)?65535:
                                          (DCM_MANU_sizeECUIdentification*8));
   return E_OK;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_F18C                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API7.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 DCM_MANU_sizeECUIdentification;                              */
/*  input uint8 DataBuffer[24];                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_F18C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 index;

   for(index = 0; index < DCM_MANU_sizeECUIdentification; index++)
   {
      Data[index] = DataBuffer[index];
   }

   return E_OK;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D420                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API7.13                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D420
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D420                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API7.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 ESLim_tiCntOverNEngMax;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D420
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalESLim_tiCntOverNEngMax;

   VEMS_vidGET(ESLim_tiCntOverNEngMax,u16LocalESLim_tiCntOverNEngMax);

   Data[0] = (uint8)((u16LocalESLim_tiCntOverNEngMax & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalESLim_tiCntOverNEngMax & 0x00FF));

   return E_OK;
}