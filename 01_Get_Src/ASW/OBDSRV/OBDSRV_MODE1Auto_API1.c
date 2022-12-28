/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OBDSRV                                                  */
/* !Description     : OBDSRV Component                                        */
/*                                                                            */
/* !Module          : OBDSRV                                                  */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : OBDSRV_MODE1Auto_API1.c                                 */
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
/*   1 / OBDMODE1_Pid_07                                                      */
/*   2 / OBDMODE1_Pid_0C                                                      */
/*   3 / OBDMODE1_Pid_0E                                                      */
/*   4 / OBDMODE1_Pid_1F                                                      */
/*   5 / OBDMODE1_Pid_1C                                                      */
/*   6 / OBDMODE1_Pid_3C                                                      */
/*   7 / OBDMODE1_Pid_03                                                      */
/*   8 / OBDMODE1_Pid_05                                                      */
/*   9 / OBDMODE1_Pid_31                                                      */
/*   10 / OBDMODE1_Pid_50                                                     */
/*   11 / OBDMODE1_Pid_14                                                     */
/*   12 / OBDMODE1_Pid_11                                                     */
/*   13 / OBDMODE1_Pid_30                                                     */
/*   14 / OBDMODE1_Pid_33                                                     */
/*   15 / OBDMODE1_Pid_4A                                                     */
/*   16 / OBDMODE1_Pid_0B                                                     */
/*   17 / OBDMODE1_Pid_06                                                     */
/*   18 / OBDMODE1_Pid_4C                                                     */
/*   19 / OBDMODE1_Pid_0D                                                     */
/*   20 / OBDMODE1_Pid_13                                                     */
/*   21 / OBDMODE1_Pid_2E                                                     */
/*   22 / OBDMODE1_Pid_4E                                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV/OBDSRV_MODE1Auto_$*/
/* $Revision::   1.10     $$Author::   pbakabad       $$Date::   Jul 02 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 02 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "OBDSRV.h"
#include "OBDSRV_L.h"
#include "OBDSRV_im.h"
#include "VEMS.h"
#include "RTE.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_07                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_Diag_trim_Pid07;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_07
(
   uint8* Data
)
{
   uint8   u8LocalSrv_Diag_trim_Pid07;

   VEMS_vidGET(Srv_Diag_trim_Pid07,u8LocalSrv_Diag_trim_Pid07);

   Data[0] = u8LocalSrv_Diag_trim_Pid07;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_0C                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_nEng_Pid0C;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_0C
(
   uint8* Data
)
{
   uint16   u16LocalSrv_nEng_Pid0C;

   VEMS_vidGET(Srv_nEng_Pid0C,u16LocalSrv_nEng_Pid0C);

   Data[0] = (uint8)((u16LocalSrv_nEng_Pid0C & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_nEng_Pid0C & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_0E                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_IgCmd_Pid0E;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_0E
(
   uint8* Data
)
{
   uint8   u8LocalSrv_IgCmd_Pid0E;

   VEMS_vidGET(Srv_IgCmd_Pid0E,u8LocalSrv_IgCmd_Pid0E);

   *Data = u8LocalSrv_IgCmd_Pid0E;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_1F                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_AstTot_Pid1F;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_1F
(
   uint8* Data
)
{
   uint16   u16LocalSrv_AstTot_Pid1F;

   VEMS_vidGET(Srv_AstTot_Pid1F,u16LocalSrv_AstTot_Pid1F);

   Data[0] = (uint8)((u16LocalSrv_AstTot_Pid1F & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_AstTot_Pid1F & 0x00FF));
   Data[2] = 0x00;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_1C                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_ObdMod_Pid1C;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_1C
(
   uint8* Data
)
{
   uint8   u8LocalSrv_ObdMod_Pid1C;

   VEMS_vidGET(Srv_ObdMod_Pid1C,u8LocalSrv_ObdMod_Pid1C);

   *Data = u8LocalSrv_ObdMod_Pid1C;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_3C                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_OxCEstim_Pid3C;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_3C
(
   uint8* Data
)
{
   uint16   u16LocalSrv_OxCEstim_Pid3C;

   VEMS_vidGET(Srv_OxCEstim_Pid3C,u16LocalSrv_OxCEstim_Pid3C);

   Data[0] = (uint8)((u16LocalSrv_OxCEstim_Pid3C & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_OxCEstim_Pid3C & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_03                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.7                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_Fuel_System_Pid03;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_03
(
   uint8* Data
)
{
   uint8   u8LocalSrv_Fuel_System_Pid03;

   VEMS_vidGET(Srv_Fuel_System_Pid03,u8LocalSrv_Fuel_System_Pid03);

   Data[0] = u8LocalSrv_Fuel_System_Pid03;
   Data[1] = 0x00;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_05                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.8                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_tCoMes_Pid05;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_05
(
   uint8* Data
)
{
   uint8   u8LocalSrv_tCoMes_Pid05;

   VEMS_vidGET(Srv_tCoMes_Pid05,u8LocalSrv_tCoMes_Pid05);

   *Data = u8LocalSrv_tCoMes_Pid05;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_31                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.9                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_dstKmRstDft_Pid31;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_31
(
   uint8* Data
)
{
   uint16   u16LocalSrv_dstKmRstDft_Pid31;

   VEMS_vidGET(Srv_dstKmRstDft_Pid31,u16LocalSrv_dstKmRstDft_Pid31);

   Data[0] = (uint8)((u16LocalSrv_dstKmRstDft_Pid31 & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_dstKmRstDft_Pid31 & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_50                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_mfAirScvLimMaxCor_Pid50;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_50
(
   uint8* Data
)
{
   uint8   u8LocalSrv_mfAirScvLimMaxCor_Pid50;

   VEMS_vidGET(Srv_mfAirScvLimMaxCor_Pid50,u8LocalSrv_mfAirScvLimMaxCor_Pid50);

   *Data = u8LocalSrv_mfAirScvLimMaxCor_Pid50;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_14                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.11                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_uUpLs_Pid14;                                              */
/*  input uint8 Srv_Lfbk_Pid06;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_14
(
   uint8* Data
)
{
   uint8   u8LocalSrv_uUpLs_Pid14;
   uint8   u8LocalSrv_Lfbk_Pid06;

   VEMS_vidGET(Srv_uUpLs_Pid14,u8LocalSrv_uUpLs_Pid14);
   VEMS_vidGET(Srv_Lfbk_Pid06,u8LocalSrv_Lfbk_Pid06);

   Data[0] = u8LocalSrv_uUpLs_Pid14;
   Data[1] = u8LocalSrv_Lfbk_Pid06;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_11                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API.12                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_Thr_Pos1_Pid11;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_11
(
   uint8* Data
)
{
   uint8   u8LocalSrv_Thr_Pos1_Pid11;

   VEMS_vidGET(Srv_Thr_Pos1_Pid11,u8LocalSrv_Thr_Pos1_Pid11);

   *Data = u8LocalSrv_Thr_Pos1_Pid11;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_30                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_WUCDftClr_Pid30;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_30
(
   uint8* Data
)
{
   uint8   u8LocalSrv_WUCDftClr_Pid30;

   VEMS_vidGET(Srv_WUCDftClr_Pid30,u8LocalSrv_WUCDftClr_Pid30);

   *Data = u8LocalSrv_WUCDftClr_Pid30;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_33                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_pAtm_Pid33;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_33
(
   uint8* Data
)
{
   uint8   u8LocalSrv_pAtm_Pid33;

   VEMS_vidGET(Srv_pAtm_Pid33,u8LocalSrv_pAtm_Pid33);

   *Data = u8LocalSrv_pAtm_Pid33;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_4A                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.15                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_AccP_Pos2_Pid4A;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_4A
(
   uint8* Data
)
{
   uint8   u8LocalSrv_AccP_Pos2_Pid4A;

   VEMS_vidGET(Srv_AccP_Pos2_Pid4A,u8LocalSrv_AccP_Pos2_Pid4A);

   *Data = u8LocalSrv_AccP_Pos2_Pid4A;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_0B                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.16                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_pDsThrMes_Pid0B;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_0B
(
   uint8* Data
)
{
   uint8   u8LocalSrv_pDsThrMes_Pid0B;

   VEMS_vidGET(Srv_pDsThrMes_Pid0B,u8LocalSrv_pDsThrMes_Pid0B);

   *Data = u8LocalSrv_pDsThrMes_Pid0B;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_06                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.17                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_Lfbk_Pid06;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_06
(
   uint8* Data
)
{
   uint8   u8LocalSrv_Lfbk_Pid06;

   VEMS_vidGET(Srv_Lfbk_Pid06,u8LocalSrv_Lfbk_Pid06);

   Data[0] = u8LocalSrv_Lfbk_Pid06;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_4C                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.18                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_OpThr_Pid4C;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_4C
(
   uint8* Data
)
{
   uint8   u8LocalSrv_OpThr_Pid4C;

   VEMS_vidGET(Srv_OpThr_Pid4C,u8LocalSrv_OpThr_Pid4C);

   *Data = u8LocalSrv_OpThr_Pid4C;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_0D                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.19                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_spdVeh_Pid0D;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_0D
(
   uint8* Data
)
{
   uint8   u8LocalSrv_spdVeh_Pid0D;

   VEMS_vidGET(Srv_spdVeh_Pid0D,u8LocalSrv_spdVeh_Pid0D);

   *Data = u8LocalSrv_spdVeh_Pid0D;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_13                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.20                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_SensO2_Pos_Pid13;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_13
(
   uint8* Data
)
{
   uint8   u8LocalSrv_SensO2_Pos_Pid13;

   VEMS_vidGET(Srv_SensO2_Pos_Pid13,u8LocalSrv_SensO2_Pos_Pid13);

   *Data = u8LocalSrv_SensO2_Pos_Pid13;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_2E                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.22                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_Cstr_Pid2E;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_2E
(
   uint8* Data
)
{
   uint8   u8LocalSrv_Cstr_Pid2E;

   VEMS_vidGET(Srv_Cstr_Pid2E,u8LocalSrv_Cstr_Pid2E);

   *Data = u8LocalSrv_Cstr_Pid2E;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_4E                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.23                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_tiMinsEngrunRstDft_Pid4E;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_4E
(
   uint8* Data
)
{
   uint16   u16LocalSrv_tiMinsEngrunRstDft_Pid4E;

   VEMS_vidGET(Srv_tiMinsEngrunRstDft_Pid4E,
                  u16LocalSrv_tiMinsEngrunRstDft_Pid4E);

   Data[0] = (uint8)((u16LocalSrv_tiMinsEngrunRstDft_Pid4E & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_tiMinsEngrunRstDft_Pid4E & 0x00FF));

   return E_OK;
}

