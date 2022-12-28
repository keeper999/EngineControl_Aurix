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
/* !File            : Dlt_ReadDataManu_API3.c                                 */
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
/*   1 / DLT_ConditionCheckRead_D633                                          */
/*   2 / DLT_ReadData_D633                                                    */
/*   3 / DLT_ConditionCheckRead_D632                                          */
/*   4 / DLT_ReadData_D632                                                    */
/*   5 / DLT_ConditionCheckRead_D631                                          */
/*   6 / DLT_ReadData_D631                                                    */
/*   7 / DLT_ConditionCheckRead_D62D                                          */
/*   8 / DLT_ReadData_D62D                                                    */
/*   9 / DLT_ConditionCheckRead_D62E                                          */
/*   10 / DLT_ReadData_D62E                                                   */
/*   11 / DLT_ConditionCheckRead_D62B                                         */
/*   12 / DLT_ReadData_D62B                                                   */
/*   13 / DLT_ConditionCheckRead_D62C                                         */
/*   14 / DLT_ReadData_D62C                                                   */
/*   15 / DLT_ConditionCheckRead_D630                                         */
/*   16 / DLT_ReadData_D630                                                   */
/*   17 / DLT_ConditionCheckRead_DADC                                         */
/*   18 / DLT_ReadData_DADC                                                   */
/*   19 / DLT_ConditionCheckRead_D478                                         */
/*   20 / DLT_ReadData_D478                                                   */
/*   21 / DLT_ConditionCheckRead_D49C                                         */
/*   22 / DLT_ReadData_D49C                                                   */
/*   23 / DLT_ConditionCheckRead_D71F                                         */
/*   24 / DLT_ReadData_D71F                                                   */
/*   25 / DLT_ConditionCheckRead_D604                                         */
/*   26 / DLT_ReadData_D604                                                   */
/*   27 / DLT_ConditionCheckRead_D605                                         */
/*   28 / DLT_ReadData_D605                                                   */
/*   29 / DLT_ConditionCheckRead_D606                                         */
/*   30 / DLT_ReadData_D606                                                   */
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
#include "MATHSRV.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D633                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D633
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D633                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_thr;                                    */
/*  input uint16 Tpac_2_closed_throttle_pos;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D633
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationThr;
   uint16 u16LocalTpac2ClosedThrottlePos;
   uint32 u32LocalTemp;
   uint16 u16LocalTemp;

   VEMS_vidGET(Tension_alimentation_thr, u16LocalTensionAlimentationThr);

   VEMS_vidGET(Tpac_2_closed_throttle_pos, u16LocalTpac2ClosedThrottlePos);
   u32LocalTemp = (uint32)( u16LocalTensionAlimentationThr
                          * u16LocalTpac2ClosedThrottlePos);
   u32LocalTemp = ( (u32LocalTemp / 262144) * 3125)
                  + (((u32LocalTemp % 262144) * 3125) / 262144);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u32LocalTemp, 50000);

   Data[0] = (uint8)((u16LocalTemp & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalTemp & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D632                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D632
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D632                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_thr;                                    */
/*  input uint16 Tpac_2_limp_home_pos;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D632
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationThr;
   uint16 u16LocalTpac2LimpHomePos;
   uint32 u32LocalTemp;
   uint16 u16LocalTemp;

   VEMS_vidGET(Tension_alimentation_thr, u16LocalTensionAlimentationThr);

   VEMS_vidGET(Tpac_2_limp_home_pos, u16LocalTpac2LimpHomePos);
   u32LocalTemp = (uint32)( u16LocalTensionAlimentationThr
                          * u16LocalTpac2LimpHomePos);
   u32LocalTemp = ( (u32LocalTemp / 262144) * 3125)
                  + (((u32LocalTemp % 262144) * 3125) / 262144);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u32LocalTemp, 50000);

   Data[0] = (uint8)((u16LocalTemp & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalTemp & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D631                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D631
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D631                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_thr;                                    */
/*  input uint16 Tpac_1_closed_throttle_pos;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D631
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationThr;
   uint16 u16LocalTpac1ClosedThrottlePos;
   uint32 u32LocalTemp;
   uint16 u16LocalTemp;

   /*VEMS_vidGET(Tension_alimentation_thr, u16LocalVar1);
   VEMS_vidGET(Tpac_1_closed_throttle_pos, u16LocalVar2);

   u32LocalVar = u16LocalVar1 * u16LocalVar2;
   if( u32LocalVar <= 5497474UL )
   {
      u16OutputVar = (uint16)((((u32LocalVar * 125)/4)*25)/65536);
   }
   else
   {
      u16OutputVar = 65535;
   }*/
   VEMS_vidGET(Tension_alimentation_thr, u16LocalTensionAlimentationThr);

   VEMS_vidGET(Tpac_1_closed_throttle_pos, u16LocalTpac1ClosedThrottlePos);
   u32LocalTemp = (uint32)( u16LocalTensionAlimentationThr
                          * u16LocalTpac1ClosedThrottlePos);
   u32LocalTemp = ( (u32LocalTemp / 262144) * 3125)
                  + (((u32LocalTemp % 262144) * 3125) / 262144);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u32LocalTemp, 50000);

   Data[0] = (uint8)((u16LocalTemp & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalTemp & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D62D                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.7                                           */
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
Std_ReturnType DLT_ConditionCheckRead_D62D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D62D                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.8                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u32Mul_u32_u32_div_u32(????);                                */
/*  input uint16 Tension_alimentation_aps;                                    */
/*  input uint16 Dv_2_app_pos_ped_pc;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D62D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationAps;
   uint16 u16LocalDv2AppPosPedPc;
   uint32 u32LocalSrvAppPosPed;
   uint16 u16LocalSrvAppPosPed;
   uint32 u32LocalTemp;

   VEMS_vidGET(Tension_alimentation_aps, u16LocalTensionAlimentationAps);
   u32LocalTemp = (uint32)(u16LocalTensionAlimentationAps * 3125);

   VEMS_vidGET(Dv_2_app_pos_ped_pc, u16LocalDv2AppPosPedPc);
   u32LocalSrvAppPosPed =
      MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalDv2AppPosPedPc,
                                     u32LocalTemp,
                                     4194304);
   u16LocalSrvAppPosPed = (uint16)MATHSRV_udtMIN(u32LocalSrvAppPosPed, 50000);

   Data[0] = (uint8)((u16LocalSrvAppPosPed & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalSrvAppPosPed & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D62E                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.9                                           */
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
Std_ReturnType DLT_ConditionCheckRead_D62E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D62E                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u32Mul_u32_u32_div_u32(????);                                */
/*  input uint16 Tension_alimentation_aps;                                    */
/*  input uint16 Dv_2_app_pos_ped_pl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D62E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationAps;
   uint16 u16LocalDv2AppPosPedPl;
   uint32 u32LocalSrvAppPosPed;
   uint32 u32LocalTemp;
   uint16 u16LocalSrvAppPosPed;

   /*VEMS_vidGET(Tension_alimentation_aps, u16LocalVar1);
   VEMS_vidGET(Dv_2_app_pos_ped_pl, u16LocalVar2);

   u32LocalVar = u16LocalVar1 * u16LocalVar2;
   if( u32LocalVar <= 87959588UL )
   {
      u16OutputVar = (uint16)((((((u32LocalVar * 25)/20)*5)/512)*125)/2048);
   }
   else
   {
      u16OutputVar = 65535;
   }*/
   VEMS_vidGET(Tension_alimentation_aps, u16LocalTensionAlimentationAps);
   u32LocalTemp = (uint32)(u16LocalTensionAlimentationAps * 3125);

   VEMS_vidGET(Dv_2_app_pos_ped_pl, u16LocalDv2AppPosPedPl);
   u32LocalSrvAppPosPed =
      MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalDv2AppPosPedPl,
                                     u32LocalTemp,
                                     4194304);
   u16LocalSrvAppPosPed = (uint16)MATHSRV_udtMIN(u32LocalSrvAppPosPed, 50000);

   Data[0] = (uint8)((u16LocalSrvAppPosPed & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalSrvAppPosPed & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D62B                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.11                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D62B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D62B                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u32Mul_u32_u32_div_u32(????);                                */
/*  input uint16 Tension_alimentation_aps;                                    */
/*  input uint16 Dv_1_app_pos_ped_pc;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D62B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationAps;
   uint16 u16LocalDv1AppPosPedPc;
   uint32 u32LocalSrvAppPosPedPc;
   uint32 u32LocalTemp;
   uint16 u16LocalSrvAppPosPedPc;

   VEMS_vidGET(Tension_alimentation_aps, u16LocalTensionAlimentationAps);
   u32LocalTemp = (uint32)(u16LocalTensionAlimentationAps * 3125);

   VEMS_vidGET(Dv_1_app_pos_ped_pc, u16LocalDv1AppPosPedPc);
   u32LocalSrvAppPosPedPc =
      MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalDv1AppPosPedPc,
                                     u32LocalTemp,
                                     4194304);
   u16LocalSrvAppPosPedPc = (uint16)MATHSRV_udtMIN(u32LocalSrvAppPosPedPc, 50000);

   Data[0] = (uint8)((u16LocalSrvAppPosPedPc & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalSrvAppPosPedPc & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D62C                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.13                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D62C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D62C                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u32Mul_u32_u32_div_u32(????);                                */
/*  input uint16 Tension_alimentation_aps;                                    */
/*  input uint16 Dv_1_app_pos_ped_pl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D62C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationAps;
   uint16 u16LocalDv1AppPosPedPl;
   uint32 u32LocalSrvAppPosPed;
   uint32 u32LocalTemp;
   uint16 u16LocalSrvAppPosPed;

   /*VEMS_vidGET(Tension_alimentation_aps, u16LocalVar1);
   VEMS_vidGET(Dv_1_app_pos_ped_pl, u16LocalVar2);

   u32LocalVar = u16LocalVar1 * u16LocalVar2;
   if( u32LocalVar <= 87959588UL )
   {
      u16OutputVar = (uint16)((((((u32LocalVar * 25)/20)*5)/512)*125)/2048);
   }
   else
   {
      u16OutputVar = 65535;
   }*/
   VEMS_vidGET(Tension_alimentation_aps, u16LocalTensionAlimentationAps);
   u32LocalTemp = (uint32)(u16LocalTensionAlimentationAps * 3125);

   VEMS_vidGET(Dv_1_app_pos_ped_pl, u16LocalDv1AppPosPedPl);
   u32LocalSrvAppPosPed =
      MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalDv1AppPosPedPl,
                                     u32LocalTemp,
                                     4194304);
   u16LocalSrvAppPosPed = (uint16)MATHSRV_udtMIN(u32LocalSrvAppPosPed, 50000);

   Data[0] = (uint8)((u16LocalSrvAppPosPed & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalSrvAppPosPed & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D630                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.15                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D630
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D630                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.16                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_thr;                                    */
/*  input uint16 Tpac_1_limp_home_pos;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D630
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalTensionAlimentationThr;
   uint16 u16LocalTpac1LimpHomePos;
   uint32 u32LocalTemp;
   uint16 u16LocalTemp;

   /*VEMS_vidGET(Tension_alimentation_thr, u16LocalVar1);
   VEMS_vidGET(Tpac_1_limp_home_pos, u16LocalVar2);

   u32LocalVar = u16LocalVar1 * u16LocalVar2;
   if( u32LocalVar <= 5497474UL )
   {
      u16OutputVar = (uint16)((((u32LocalVar * 125)/4)*25)/65536);
   }
   else
   {
      u16OutputVar = 65535;
   }*/
   VEMS_vidGET(Tension_alimentation_thr, u16LocalTensionAlimentationThr);

   VEMS_vidGET(Tpac_1_limp_home_pos, u16LocalTpac1LimpHomePos);
   u32LocalTemp = (uint32)( u16LocalTensionAlimentationThr
                          * u16LocalTpac1LimpHomePos);

   u32LocalTemp = ( (u32LocalTemp / 262144) * 3125)
                  + (((u32LocalTemp % 262144) * 3125) / 262144);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u32LocalTemp, 50000);

   Data[0] = (uint8)((u16LocalTemp & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalTemp & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_DADC                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.17                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Srv_EveRdByDidADC();                                     */
/*  input uint8 Srv_stADCRead;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_DADC
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      Srv_EveRdByDidADC();
      u8LocalReturn = E_PENDING;
   }
   else if( DCM_PENDING == OpStatus )
   {
      if( READ_ADC_OK == Srv_stADCRead )
      {
         u8LocalReturn = E_OK;
      }
      else if( READ_ADC_IN_PROGRESS == Srv_stADCRead )
      {
         u8LocalReturn = E_PENDING;
      }
      else if( READ_ADC_IMPOSSIBLE == Srv_stADCRead )
      {
         u8LocalReturn = E_NOT_OK;
         *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      }
      else /* READ_ADC_TIMEOUT == Srv_stADCRead */
      {
         *ErrorCode = DCM_E_BUSYREPEATREQUEST;
         u8LocalReturn = E_NOT_OK;
      }
   }
   else /* DCM_CANCEL == OpStatus */
   {
      u8LocalReturn = E_OK;
   }

   return u8LocalReturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_DADC                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.18                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 SAIMMO_stLockECUReadSt;                                       */
/*  input uint8 SAIMMO_stProgImmoReadSt;                                      */
/*  input uint8 SAIMMO_bfImmoReadStDft;                                       */
/*  input uint8 SAIMMO_stCANMatchOptReadSt;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_DADC
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalVar1;
   uint8 u8LocalVar2;
   uint8 u8LocalVar3;
   uint8 u8LocalVar4;

   VEMS_vidGET(SAIMMO_stLockECUReadSt, u8LocalVar1);
   VEMS_vidGET(SAIMMO_stProgImmoReadSt, u8LocalVar2);
   VEMS_vidGET(SAIMMO_bfImmoReadStDft, u8LocalVar3);
   VEMS_vidGET(SAIMMO_stCANMatchOptReadSt, u8LocalVar4);

   Data[0] = u8LocalVar1;
   Data[1] = u8LocalVar2;
   Data[2] = u8LocalVar3;
   Data[3] = u8LocalVar4;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D478                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.19                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D478
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D478                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.20                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 EngSt_tiDlySync;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D478
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16 u16LocalVar;

   u16LocalVar = EngSt_tiDlySync;

   Data[0] = (uint8)((u16LocalVar & 0xFF00) >> 8);
   Data[1] = (uint8)(u16LocalVar & 0x00FF);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D49C                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.21                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D49C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D49C                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.22                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Ext_dstVehTotMes;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D49C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalExt_dstVehTotMes;

   VEMS_vidGET(Ext_dstVehTotMes,u32LocalExt_dstVehTotMes);
   u32LocalExt_dstVehTotMes =
         (uint32)(u32LocalExt_dstVehTotMes & 0x00FFFFFFUL);

   Data[0] = (uint8)((u32LocalExt_dstVehTotMes & 0xFF000000) >> 24 );
   Data[1] = (uint8)((u32LocalExt_dstVehTotMes & 0x00FF0000) >> 16 );
   Data[2] = (uint8)((u32LocalExt_dstVehTotMes & 0x0000FF00) >> 8   );
   Data[3] = (uint8)(u32LocalExt_dstVehTotMes & 0x000000FF) ;


   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D71F                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.23                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D71F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D71F                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.24                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 StaStrtMgt_ctStaAcv;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D71F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32   u32LocalStaStrtMgt_ctStaAcv;

   VEMS_vidGET(StaStrtMgt_ctStaAcv,u32LocalStaStrtMgt_ctStaAcv);
   u32LocalStaStrtMgt_ctStaAcv =
         (uint32)(u32LocalStaStrtMgt_ctStaAcv & 0x00FFFFFFUL);

   Data[0] = (uint8)((u32LocalStaStrtMgt_ctStaAcv & 0xFF000000) >> 24 );
   Data[1] = (uint8)((u32LocalStaStrtMgt_ctStaAcv & 0x00FF0000) >> 16 );
   Data[2] = (uint8)((u32LocalStaStrtMgt_ctStaAcv & 0x0000FF00) >> 8   );
   Data[3] = (uint8)(u32LocalStaStrtMgt_ctStaAcv & 0x000000FF) ;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D604                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.25                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D604
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D604                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.26                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 KnkMgt_prm_agIgKnkDetOfsCyl[6];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D604
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 ut8LocalVar;

   VEMS_vidGET1DArrayElement( KnkMgt_prm_agIgKnkDetOfsCyl,
                              0,
                              ut8LocalVar );

   Data[0] = ut8LocalVar;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D605                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.27                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D605
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D605                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.28                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 KnkMgt_prm_agIgKnkDetOfsCyl[6];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D605
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 ut8LocalVar;

   VEMS_vidGET1DArrayElement( KnkMgt_prm_agIgKnkDetOfsCyl,
                              1,
                              ut8LocalVar );

   Data[0] = ut8LocalVar;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D606                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API3.29                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D606
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D606                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API3.30                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 KnkMgt_prm_agIgKnkDetOfsCyl[6];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D606
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 ut8LocalVar;

   VEMS_vidGET1DArrayElement( KnkMgt_prm_agIgKnkDetOfsCyl,
                              2,
                              ut8LocalVar );

   Data[0] = ut8LocalVar;

   return E_OK;
}