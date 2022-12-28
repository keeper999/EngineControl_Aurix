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
/* !File            : Dlt_ReadDataManu_API5.c                                 */
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
/*   1 / DLT_ConditionCheckRead_D4A0                                          */
/*   2 / DLT_ReadData_D4A0                                                    */
/*   3 / DLT_ConditionCheckRead_D729                                          */
/*   4 / DLT_ReadData_D729                                                    */
/*   5 / DLT_ConditionCheckRead_DADD                                          */
/*   6 / DLT_ReadData_DADD                                                    */
/*   7 / DLT_ConditionCheckRead_D63A                                          */
/*   8 / DLT_ReadData_D63A                                                    */
/*   9 / DLT_ConditionCheckRead_D63C                                          */
/*   10 / DLT_ReadData_D63C                                                   */
/*   11 / DLT_ConditionCheckRead_D4B0                                         */
/*   12 / DLT_ReadData_D4B0                                                   */
/*   13 / DLT_ConditionCheckRead_D638                                         */
/*   14 / DLT_ReadData_D638                                                   */
/*   15 / DLT_ConditionCheckRead_D639                                         */
/*   16 / DLT_ReadData_D639                                                   */
/*   17 / DLT_ConditionCheckRead_D4C0                                         */
/*   18 / DLT_ReadData_D4C0                                                   */
/*   19 / DLT_ConditionCheckRead_D709                                         */
/*   20 / DLT_ReadData_D709                                                   */
/*   21 / DLT_ConditionCheckRead_D4DC                                         */
/*   22 / DLT_ReadData_D4DC                                                   */
/*   23 / DLT_ConditionCheckRead_D4FE                                         */
/*   24 / DLT_ReadData_D4FE                                                   */
/*   25 / DLT_ConditionCheckRead_D4FF                                         */
/*   26 / DLT_ReadData_D4FF                                                   */
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
#include "MATHSRV.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D4A0                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.1                                           */
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
Std_ReturnType DLT_ConditionCheckRead_D4A0
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D4A0                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ThMgt_stPosnFSFReq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D4A0
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalThMgt_stPosnFSFReq;
   VEMS_vidGET(ThMgt_stPosnFSFReq, u8LocalThMgt_stPosnFSFReq);

   Data[0] = u8LocalThMgt_stPosnFSFReq;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D729                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.3                                           */
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
Std_ReturnType DLT_ConditionCheckRead_D729
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D729                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_pRelBrkAsi;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D729
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalExt_pRelBrkAsi;

   VEMS_vidGET(Ext_pRelBrkAsi, u8LocalExt_pRelBrkAsi);

   Data[0] = u8LocalExt_pRelBrkAsi;


   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_DADD                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DLT_ConditionCheckRead_DADC(argin             */
/*  Dcm_OpStatusType OpStatus, argout Dcm_NegativeResponseCodeType            */
/*  *ErrorCode);                                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_DADD
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = DLT_ConditionCheckRead_DADC(OpStatus,ErrorCode);

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_DADD                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 SAIMMO_stLockECUReadSt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_DADD
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalVar;

   VEMS_vidGET(SAIMMO_stLockECUReadSt, u8LocalVar);

   Data[0] = u8LocalVar;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D63A                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.7                                           */
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
Std_ReturnType DLT_ConditionCheckRead_D63A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D63A                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.8                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input sint8 Av_bmax_corr_appliquee_cyl[4];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D63A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   sint8 s8LocalVar;

   VEMS_vidGET1DArrayElement( Av_bmax_corr_appliquee_cyl,
                              2,
                              s8LocalVar );

   Data[0] = (uint8)s8LocalVar;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D63C                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.9                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PFuCtl_agWdPmpCmdMax_C;                                      */
/*  input uint16 PFuCtl_agWdPmpCmdReq;                                        */
/*  output uint8 DCM_MANU_PFuCtl_agWdPmpCmdReq;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D63C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16         u16LocalTemp;
   uint32         u32LocalTemp;
   uint32         u32LocalTemp1;
   uint32         u32LocalTemp2;

   DCM_MANU_PFuCtl_agWdPmpCmdReq = 0;

   if(PFuCtl_agWdPmpCmdMax_C != 0)
   {
      VEMS_vidGET(PFuCtl_agWdPmpCmdReq,u16LocalTemp);

      u32LocalTemp1 = (uint32)((u16LocalTemp/PFuCtl_agWdPmpCmdMax_C)*255);
      u32LocalTemp2 = (uint32)((u16LocalTemp % PFuCtl_agWdPmpCmdMax_C)*255);
      u32LocalTemp2 = (u32LocalTemp2/(uint32)PFuCtl_agWdPmpCmdMax_C);
      u32LocalTemp = u32LocalTemp1 + u32LocalTemp2;

      DCM_MANU_PFuCtl_agWdPmpCmdReq = (uint8)MATHSRV_udtMIN(u32LocalTemp, 255);
   }

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D63C                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DCM_MANU_PFuCtl_agWdPmpCmdReq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D63C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   Data[0] = DCM_MANU_PFuCtl_agWdPmpCmdReq;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D4B0                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.11                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D4B0
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D4B0                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 VSCtl_stVSRegExtd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D4B0
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalVSCtl_stVSRegExtd;

   VEMS_vidGET(VSCtl_stVSRegExtd, u8LocalVSCtl_stVSRegExtd);

   Data[0] = u8LocalVSCtl_stVSRegExtd;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D638                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.13                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D638
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D638                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input sint8 Av_bmax_corr_appliquee_cyl[4];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D638
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   sint8 s8LocalVar;

   VEMS_vidGET1DArrayElement( Av_bmax_corr_appliquee_cyl,
                              0,
                              s8LocalVar );

   Data[0] = (uint8)s8LocalVar;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D639                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.15                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D639
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D639                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.16                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input sint8 Av_bmax_corr_appliquee_cyl[4];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D639
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   sint8 s8LocalVar;

   VEMS_vidGET1DArrayElement( Av_bmax_corr_appliquee_cyl,
                              1,
                              s8LocalVar );

   Data[0] = (uint8)s8LocalVar;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D4C0                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.17                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D4C0
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D4C0                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.18                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 VSCtl_stVSLimExtd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D4C0
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalVSCtl_stVSLimExtd;

   VEMS_vidGET(VSCtl_stVSLimExtd, u8LocalVSCtl_stVSLimExtd);

   Data[0] = u8LocalVSCtl_stVSLimExtd;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D709                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.19                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D709
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D709                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.20                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean EngReqH_bEngRunReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D709
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean bLocalEngReqH_bEngRunReq;

   VEMS_vidGET(EngReqH_bEngRunReq, bLocalEngReqH_bEngRunReq);

   *Data = (uint8)((bLocalEngReqH_bEngRunReq == TRUE) ? 0x01 : 0x00);

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D4DC                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.21                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D4DC
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D4DC                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.22                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Flev_fuel_level;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D4DC
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalFlev_fuel_level;

   VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);

   *Data = u8LocalFlev_fuel_level;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D4FE                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API5.23                                          */
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
Std_ReturnType DLT_ConditionCheckRead_D4FE
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D4FE                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API5.24                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Srv_bInhThr;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D4FE
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean bLocalSrv_bInhThr;

   VEMS_vidGET(Srv_bInhThr,bLocalSrv_bInhThr);

   *Data = (uint8)((bLocalSrv_bInhThr == TRUE) ? 0xFF : 0x00);

   return E_OK;

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
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
Std_ReturnType DLT_ConditionCheckRead_D4FF
(
   Dcm_OpStatusType OpStatus,
   /* Msg(3:3206): The parameter OpStatus is not used for the Mockup */
   Dcm_NegativeResponseCodeType* ErrorCode
   /* Msg(3:3206): The parameter *ErrorCode is not used for the Mockup */
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Srv_bInhSftyLvl2;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_ReadData_D4FF
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean bLocalSrv_bInhSftyLvl2;

   VEMS_vidGET(Srv_bInhSftyLvl2,bLocalSrv_bInhSftyLvl2);

   *Data = (uint8)((bLocalSrv_bInhSftyLvl2 == TRUE) ? 0xFF : 0x00);

   return E_OK;
}


