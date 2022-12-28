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
/* !File            : Dlt_ReadDataManu_API6.c                                 */
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
/*   1 / DLT_ConditionCheckRead_D63E                                          */
/*   2 / DLT_ReadData_D63E                                                    */
/*   3 / DLT_ConditionCheckRead_D63F                                          */
/*   4 / DLT_ReadData_D63F                                                    */
/*   5 / DLT_ConditionCheckRead_D63D                                          */
/*   6 / DLT_ReadData_D63D                                                    */
/*   7 / DLT_ConditionCheckRead_2102                                          */
/*   8 / DLT_ReadDataLength_2102                                              */
/*   9 / DLT_ReadData_2102                                                    */
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
/* !Function    :  DLT_ConditionCheckRead_D63E                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API6.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D63E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D63E                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API6.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Bruit_moyen_cyl_min_thresh[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D63E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{

   uint16 u16LocalVar;

   //VEMS_vidGET1DArrayElement( Bruit_moyen_cyl_min_thresh, 1, u16LocalVar );
   u16LocalVar = Bruit_moyen_cyl_min_thresh[1];

   Data[0] = (uint8)((u16LocalVar & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalVar & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D63F                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API6.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D63F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D63F                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API6.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Bruit_moyen_cyl_min_thresh[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D63F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{

   uint16 u16LocalVar;

   u16LocalVar = Bruit_moyen_cyl_min_thresh[2];

   Data[0] = (uint8)((u16LocalVar & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalVar & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D63D                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API6.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D63D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D63D                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API6.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Bruit_moyen_cyl_min_thresh[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D63D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{

   uint16 u16LocalVar;

   u16LocalVar = Bruit_moyen_cyl_min_thresh[0];

   Data[0] = (uint8)((u16LocalVar & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalVar & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_2102                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API6.6                                           */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_02667_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_2102
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_2102                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API6.7                                           */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_02667_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Srv_PostEquDataSize_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_2102
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(Srv_PostEquDataSize_C * 8);
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_2102                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API6.8                                           */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_02667_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_PostEquIndice;                                            */
/*  input uint8 Ext_spdVehVSMaxPrmaReq1;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_2102
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalSrv_PostEquIndice;
   uint8 u8LocalExt_spdVehVSMaxPrmaReq1;
   
   VEMS_vidGET(Srv_PostEquIndice,u8LocalSrv_PostEquIndice);
   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq1,u8LocalExt_spdVehVSMaxPrmaReq1);

   Data[0] = u8LocalSrv_PostEquIndice;
   Data[1] = u8LocalExt_spdVehVSMaxPrmaReq1;
   
   return E_OK;
}

