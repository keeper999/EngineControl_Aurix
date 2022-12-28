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
/* !File            : Dlt_ReadDataAuto_API5.c                                 */
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
/*   1 / DLT_ConditionCheckRead_D726                                          */
/*   2 / DLT_ReadData_D726                                                    */
/*   3 / DLT_ConditionCheckRead_0E00                                          */
/*   4 / DLT_ReadData_0E00                                                    */
/*   5 / DLT_ConditionCheckRead_D723                                          */
/*   6 / DLT_ReadData_D723                                                    */
/*   7 / DLT_ConditionCheckRead_D724                                          */
/*   8 / DLT_ReadData_D724                                                    */
/*   9 / DLT_ConditionCheckRead_D727                                          */
/*   10 / DLT_ReadData_D727                                                   */
/*   11 / DLT_ConditionCheckRead_D728                                         */
/*   12 / DLT_ReadData_D728                                                   */
/*   13 / DLT_ConditionCheckRead_D489                                         */
/*   14 / DLT_ReadData_D489                                                   */
/*   15 / DLT_ConditionCheckRead_D48E                                         */
/*   16 / DLT_ReadData_D48E                                                   */
/*   17 / DLT_ConditionCheckRead_D48D                                         */
/*   18 / DLT_ReadData_D48D                                                   */
/*   19 / DLT_ConditionCheckRead_D405                                         */
/*   20 / DLT_ReadData_D405                                                   */
/*   21 / DLT_ConditionCheckRead_D404                                         */
/*   22 / DLT_ReadData_D404                                                   */
/*   23 / DLT_ConditionCheckRead_D407                                         */
/*   24 / DLT_ReadData_D407                                                   */
/*   25 / DLT_ConditionCheckRead_D406                                         */
/*   26 / DLT_ReadData_D406                                                   */
/*   27 / DLT_ConditionCheckRead_D400                                         */
/*   28 / DLT_ReadData_D400                                                   */
/*   29 / DLT_ConditionCheckRead_D403                                         */
/*   30 / DLT_ReadData_D403                                                   */
/*   31 / DLT_ConditionCheckRead_D402                                         */
/*   32 / DLT_ReadData_D402                                                   */
/*   33 / DLT_ConditionCheckRead_D484                                         */
/*   34 / DLT_ReadData_D484                                                   */
/*   35 / DLT_ConditionCheckRead_D485                                         */
/*   36 / DLT_ReadData_D485                                                   */
/*   37 / DLT_ConditionCheckRead_D409                                         */
/*   38 / DLT_ReadData_D409                                                   */
/*   39 / DLT_ConditionCheckRead_D482                                         */
/*   40 / DLT_ReadData_D482                                                   */
/*   41 / DLT_ConditionCheckRead_D408                                         */
/*   42 / DLT_ReadData_D408                                                   */
/*   43 / DLT_ConditionCheckRead_D483                                         */
/*   44 / DLT_ReadData_D483                                                   */
/*   45 / DLT_ConditionCheckRead_D481                                         */
/*   46 / DLT_ReadData_D481                                                   */
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
/* !Function    :  DLT_ConditionCheckRead_D726                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D726
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D726                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bPush;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D726
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean   bExt_bPush;

   VEMS_vidGET(Ext_bPush,bExt_bPush);

   *Data = (uint8)((TRUE == bExt_bPush) ? 0x01 : 0x00);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_0E00                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_0E00
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_0E00                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Sfty_Count_TaskOvrrunCnt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_0E00
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalSfty_Count_TaskOvrrunCnt;

   VEMS_vidGET(Sfty_Count_TaskOvrrunCnt,u16LocalSfty_Count_TaskOvrrunCnt);

   Data[0] = (uint8)((u16LocalSfty_Count_TaskOvrrunCnt & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSfty_Count_TaskOvrrunCnt & 0x00FF));

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D723                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D723
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D723                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Veh_stDrvAvl;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D723
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalVeh_stDrvAvl;

   VEMS_vidGET(Veh_stDrvAvl,u8LocalVeh_stDrvAvl);

   *Data = u8LocalVeh_stDrvAvl;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D724                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.7                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D724
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D724                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.8                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPtUH_bSTTInh;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D724
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean   bCoPtUH_bSTTInh;

   VEMS_vidGET(CoPtUH_bSTTInh,bCoPtUH_bSTTInh);

   *Data = (uint8)((TRUE == bCoPtUH_bSTTInh) ? 0x01 : 0x00);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D727                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.9                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D727
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D727                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoEmCkg_stSTTCf;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D727
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalCoEmCkg_stSTTCf;

   VEMS_vidGET(CoEmCkg_stSTTCf,u8LocalCoEmCkg_stSTTCf);

   *Data = u8LocalCoEmCkg_stSTTCf;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D728                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.11                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D728
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D728                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TqSys_tqCkEngReal;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D728
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   sint16   s16LocalTqSys_tqCkEngReal;

   VEMS_vidGET(TqSys_tqCkEngReal,s16LocalTqSys_tqCkEngReal);

   Data[0] = (uint8)((s16LocalTqSys_tqCkEngReal & 0xFF00) >> 8);
   Data[1] = (uint8)((s16LocalTqSys_tqCkEngReal & 0x00FF));

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D489                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.13                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D489
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D489                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D489
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalInM_mfAirThrEstim;

   VEMS_vidGET(InM_mfAirThrEstim,u16LocalInM_mfAirThrEstim);

   Data[0] = (uint8)((u16LocalInM_mfAirThrEstim & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalInM_mfAirThrEstim & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D48E                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.15                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D48E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D48E                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.16                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AirSys_mfAirThrReqFil;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D48E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalAirSys_mfAirThrReqFil;

   VEMS_vidGET(AirSys_mfAirThrReqFil,u16LocalAirSys_mfAirThrReqFil);

   Data[0] = (uint8)((u16LocalAirSys_mfAirThrReqFil & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalAirSys_mfAirThrReqFil & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D48D                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.17                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D48D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D48D                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.18                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AirSys_pUsThrReq;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D48D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalAirSys_pUsThrReq;

   VEMS_vidGET(AirSys_pUsThrReq,u16LocalAirSys_pUsThrReq);

   Data[0] = (uint8)((u16LocalAirSys_pUsThrReq & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalAirSys_pUsThrReq & 0x00FF));

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D405                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.19                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D405
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D405                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.20                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_uAccP1SenPwr;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D405
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalExt_uAccP1SenPwr;

   VEMS_vidGET(Ext_uAccP1SenPwr,u16LocalExt_uAccP1SenPwr);

   Data[0] = (uint8)((u16LocalExt_uAccP1SenPwr & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalExt_uAccP1SenPwr & 0x00FF));

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D404                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.21                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D404
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D404                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.22                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bCluPedPrss;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D404
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean   bExt_bCluPedPrss;

   VEMS_vidGET(Ext_bCluPedPrss,bExt_bCluPedPrss);

   *Data = (uint8)((TRUE == bExt_bCluPedPrss) ? 0x01 : 0x00);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D407                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.23                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D407
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D407                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.24                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 AccP_rDrvReq;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D407
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalAccP_rDrvReq;

   VEMS_vidGET(AccP_rDrvReq,u8LocalAccP_rDrvReq);

   *Data = u8LocalAccP_rDrvReq;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D406                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.25                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D406
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D406                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.26                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_uAccP2SenPwr;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D406
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalExt_uAccP2SenPwr;

   VEMS_vidGET(Ext_uAccP2SenPwr,u16LocalExt_uAccP2SenPwr);

   Data[0] = (uint8)((u16LocalExt_uAccP2SenPwr & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalExt_uAccP2SenPwr & 0x00FF));

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D400                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.27                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D400
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D400                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.28                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D400
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalExt_nEng;

   VEMS_vidGET(Ext_nEng,u16LocalExt_nEng);

   Data[0] = (uint8)((u16LocalExt_nEng & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalExt_nEng & 0x00FF));

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D403                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.29                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D403
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D403                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.30                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bMainBrkPedPrssMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D403
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean   bExt_bMainBrkPedPrssMes;

   VEMS_vidGET(Ext_bMainBrkPedPrssMes,bExt_bMainBrkPedPrssMes);

   *Data = (uint8)((TRUE == bExt_bMainBrkPedPrssMes) ? 0x01 : 0x00);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D402                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.31                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D402
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D402                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.32                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D402
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalVeh_spdVeh;

   VEMS_vidGET(Veh_spdVeh,u16LocalVeh_spdVeh);

   Data[0] = (uint8)((u16LocalVeh_spdVeh & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalVeh_spdVeh & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D484                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.33                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D484
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D484                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.34                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Pression_air_result_ad_conv;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D484
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalPression_air_result_ad_conv;

   VEMS_vidGET(Pression_air_result_ad_conv,u16LocalPression_air_result_ad_conv);

   Data[0] = (uint8)((u16LocalPression_air_result_ad_conv & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalPression_air_result_ad_conv & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D485                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.35                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D485
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D485                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.36                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Temperature_air_result_ad_conv;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D485
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalTemperature_air_result_ad_conv;

   VEMS_vidGET(Temperature_air_result_ad_conv,
                  u16LocalTemperature_air_result_ad_conv);

   Data[0] = (uint8)((u16LocalTemperature_air_result_ad_conv & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalTemperature_air_result_ad_conv & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D409                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.37                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D409
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D409                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.38                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D409
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8   u8LocalCoPt_noEgdGearCord;

   VEMS_vidGET(CoPt_noEgdGearCord,u8LocalCoPt_noEgdGearCord);

   *Data = u8LocalCoPt_noEgdGearCord;

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D482                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.39                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D482
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D482                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.40                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_upFuMes;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D482
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalExt_upFuMes;

   VEMS_vidGET(Ext_upFuMes,u16LocalExt_upFuMes);

   Data[0] = (uint8)((u16LocalExt_upFuMes & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalExt_upFuMes & 0x00FF));

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D408                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.41                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D408
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D408                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.42                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bAccPHdPt;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D408
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   boolean   bExt_bAccPHdPt;

   VEMS_vidGET(Ext_bAccPHdPt,bExt_bAccPHdPt);

   *Data = (uint8)((TRUE == bExt_bAccPHdPt) ? 0x01 : 0x00);

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D483                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.43                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D483
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D483                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.44                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AirExtPresAcq_upAirMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D483
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalAirExtPresAcq_upAirMes;

   VEMS_vidGET(AirExtPresAcq_upAirMes,u16LocalAirExtPresAcq_upAirMes);

   Data[0] = (uint8)((u16LocalAirExtPresAcq_upAirMes & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalAirExtPresAcq_upAirMes & 0x00FF));

   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D481                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAAUTO_API5.45                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D481
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D481                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAAUTO_API5.46                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cl_pressure_result_ad_conv;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D481
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint16   u16LocalCl_pressure_result_ad_conv;

   VEMS_vidGET(Cl_pressure_result_ad_conv,u16LocalCl_pressure_result_ad_conv);

   Data[0] = (uint8)((u16LocalCl_pressure_result_ad_conv & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalCl_pressure_result_ad_conv & 0x00FF));

   return E_OK;
}
