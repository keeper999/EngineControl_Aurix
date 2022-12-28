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
/* !File            : OBDSRV_MODE1Auto_API2.c                                 */
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
/*   1 / OBDMODE1_Pid_4D                                                      */
/*   2 / OBDMODE1_Pid_0F                                                      */
/*   3 / OBDMODE1_Pid_4F                                                      */
/*   4 / OBDMODE1_Pid_04                                                      */
/*   5 / OBDMODE1_Pid_42                                                      */
/*   6 / OBDMODE1_Pid_15                                                      */
/*   7 / OBDMODE1_Pid_21                                                      */
/*   8 / OBDMODE1_Pid_49                                                      */
/*   9 / OBDMODE1_Pid_23                                                      */
/*   10 / OBDMODE1_Pid_44                                                     */
/*   11 / OBDMODE1_Pid_47                                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV/OBDSRV_MODE1Auto_$*/
/* $Revision::   1.9      $$Author::   pbakabad       $$Date::   Jul 02 2013 $*/
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
/* !Function    :  OBDMODE1_Pid_4D                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API1.24                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_EngRunMilOn_Pid4D;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_4D
(
   uint8* Data
)
{
   uint16   u16LocalSrv_EngRunMilOn_Pid4D;

   VEMS_vidGET(Srv_EngRunMilOn_Pid4D,u16LocalSrv_EngRunMilOn_Pid4D);

   Data[0] = (uint8)((u16LocalSrv_EngRunMilOn_Pid4D & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_EngRunMilOn_Pid4D & 0x00FF));
   Data[2] = 0x00;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_0F                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_tAirMes_Pid0F;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_0F
(
   uint8* Data
)
{
   uint8   u8LocalSrv_tAirMes_Pid0F;

   VEMS_vidGET(Srv_tAirMes_Pid0F,u8LocalSrv_tAirMes_Pid0F);

   *Data = u8LocalSrv_tAirMes_Pid0F;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_4F                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Srv_MaxValEqRatio_Pid4F;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_4F
(
   uint8* Data
)
{
   uint32   u32LocalSrv_MaxValEqRatio_Pid4F;

   VEMS_vidGET(Srv_MaxValEqRatio_Pid4F,u32LocalSrv_MaxValEqRatio_Pid4F);

   Data[0] = (uint8)((u32LocalSrv_MaxValEqRatio_Pid4F & 0xFF000000UL) >> 24);
   Data[1] = (uint8)((u32LocalSrv_MaxValEqRatio_Pid4F & 0x00FF0000UL) >> 16);
   Data[2] = (uint8)((u32LocalSrv_MaxValEqRatio_Pid4F & 0x0000FF00UL) >> 8);
   Data[3] = (uint8)((u32LocalSrv_MaxValEqRatio_Pid4F & 0x000000FFUL));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_04                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_Engine_load_Pid04;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_04
(
   uint8* Data
)
{
   uint8   u8LocalSrv_Engine_load_Pid04;

   VEMS_vidGET(Srv_Engine_load_Pid04,u8LocalSrv_Engine_load_Pid04);

   *Data = u8LocalSrv_Engine_load_Pid04;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_42                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_uBattMes_Pid42;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_42
(
   uint8* Data
)
{
   uint16   u16LocalSrv_uBattMes_Pid42;

   VEMS_vidGET(Srv_uBattMes_Pid42,u16LocalSrv_uBattMes_Pid42);

   Data[0] = (uint8)((u16LocalSrv_uBattMes_Pid42 & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_uBattMes_Pid42 & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_15                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.7                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_uDsLs_Pid15;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_15
(
   uint8* Data
)
{
   uint8   u8LocalSrv_uDsLs_Pid15;

   VEMS_vidGET(Srv_uDsLs_Pid15,u8LocalSrv_uDsLs_Pid15);

   Data[0] = u8LocalSrv_uDsLs_Pid15;
   Data[1] = 0xFF;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_21                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.9                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_dstKmMilOn_Pid21;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_21
(
   uint8* Data
)
{
   uint16   u16LocalSrv_dstKmMilOn_Pid21;

   VEMS_vidGET(Srv_dstKmMilOn_Pid21,u16LocalSrv_dstKmMilOn_Pid21);

   Data[0] = (uint8)((u16LocalSrv_dstKmMilOn_Pid21 & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_dstKmMilOn_Pid21 & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_49                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_AccP_Pos1_Pid49;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_49
(
   uint8* Data
)
{
   uint8   u8LocalSrv_AccP_Pos1_Pid49;

   VEMS_vidGET(Srv_AccP_Pos1_Pid49,u8LocalSrv_AccP_Pos1_Pid49);

   *Data = u8LocalSrv_AccP_Pos1_Pid49;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_23                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.11                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Srv_pFuMes_Pid23;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_23
(
   uint8* Data
)
{
   uint16   u16LocalSrv_pFuMes_Pid23;

   VEMS_vidGET(Srv_pFuMes_Pid23,u16LocalSrv_pFuMes_Pid23);

   Data[0] = (uint8)((u16LocalSrv_pFuMes_Pid23 & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalSrv_pFuMes_Pid23 & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_44                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 FARSpStl_lamSp;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_44
(
   uint8* Data
)
{
   uint16   u16LocalFARSpStl_lamSp;

   VEMS_vidGET(FARSpStl_lamSp,u16LocalFARSpStl_lamSp);

   Data[0] = (uint8)((u16LocalFARSpStl_lamSp & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalFARSpStl_lamSp & 0x00FF));

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE1_Pid_47                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Auto_API2.13                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_Thr_Pos2_Pid47;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_47
(
   uint8* Data
)
{
   uint8   u8LocalSrv_Thr_Pos2_Pid47;

   VEMS_vidGET(Srv_Thr_Pos2_Pid47,u8LocalSrv_Thr_Pos2_Pid47);

   *Data = u8LocalSrv_Thr_Pos2_Pid47;

   return E_OK;
}

