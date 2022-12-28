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
/* !File            : DLT_OBDMode01_API1.c                                    */
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
/*   1 / DLT_OBDMode01_PID01                                                  */
/*   2 / DLT_OBDMode01_PID03                                                  */
/*   3 / DLT_OBDMode01_PID04                                                  */
/*   4 / DLT_OBDMode01_PID05                                                  */
/*   5 / DLT_OBDMode01_PID06                                                  */
/*   6 / DLT_OBDMode01_PID07                                                  */
/*   7 / DLT_OBDMode01_PID0B                                                  */
/*   8 / DLT_OBDMode01_PID0C                                                  */
/*   9 / DLT_OBDMode01_PID0D                                                  */
/*   10 / DLT_OBDMode01_PID0E                                                 */
/*   11 / DLT_OBDMode01_PID0F                                                 */
/*   12 / DLT_OBDMode01_PID11                                                 */
/*   13 / DLT_OBDMode01_PID13                                                 */
/*   14 / DLT_OBDMode01_PID14                                                 */
/*   15 / DLT_OBDMode01_PID15                                                 */
/*   16 / DLT_OBDMode01_PID1C                                                 */
/*   17 / DLT_OBDMode01_PID1F                                                 */
/*   18 / DLT_OBDMode01_PID21                                                 */
/*   19 / DLT_OBDMode01_PID23                                                 */
/*   20 / DLT_OBDMode01_PID2E                                                 */
/*   21 / DLT_OBDMode01_PID30                                                 */
/*   22 / DLT_OBDMode01_PID31                                                 */
/*   23 / DLT_OBDMode01_PID33                                                 */
/*   24 / DLT_OBDMode01_PID3C                                                 */
/*   25 / DLT_OBDMode01_PID42                                                 */
/*   26 / DLT_OBDMode01_PID44                                                 */
/*   27 / DLT_OBDMode01_PID47                                                 */
/*   28 / DLT_OBDMode01_PID49                                                 */
/*   29 / DLT_OBDMode01_PID4A                                                 */
/*   30 / DLT_OBDMode01_PID4C                                                 */
/*   31 / DLT_OBDMode01_PID4D                                                 */
/*   32 / DLT_OBDMode01_PID4E                                                 */
/*   33 / DLT_OBDMode01_PID4F                                                 */
/*   34 / DLT_OBDMode01_PID50                                                 */
/*   35 / DLT_OBDMode01_PID72_Data1                                           */
/*   36 / DLT_OBDMode01_PID72_Data2                                           */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DLT$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Dlt.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID01                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_DcmReadDataOfPID01(argin uint8 *Data);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID01
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = Dem_DcmReadDataOfPID01( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID03                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_03(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID03
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_03( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID04                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_04(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID04
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_04( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID05                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_05(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID05
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_05( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID06                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_06(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID06
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_06( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID07                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_07(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID07
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_07( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID0B                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.7                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_0B(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID0B
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_0B( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID0C                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.8                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_0C(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID0C
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_0C( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID0D                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.9                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_0D(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID0D
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_0D( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID0E                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_0E(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID0E
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_0E( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID0F                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.11                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_0F(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID0F
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_0F( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID11                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_11(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID11
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_11( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID13                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.13                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_13(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID13
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_13( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID14                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_14(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID14
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_14( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID15                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.15                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_15(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID15
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_15( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID1C                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.16                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_1C(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID1C
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_1C( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID1F                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.17                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_1F(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID1F
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_1F( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID21                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.18                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_21(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID21
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_21( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID23                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.19                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_23(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID23
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_23( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID2E                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.20                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_2E(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID2E
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_2E( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID30                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.21                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_30(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID30
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_30( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID31                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.22                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_31(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID31
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_31( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID33                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.23                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_33(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID33
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_33( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID3C                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.24                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_3C(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID3C
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_3C( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID42                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.25                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_42(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID42
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_42( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID44                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.26                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_44(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID44
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_44( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID47                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.27                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_47(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID47
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_47( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID49                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.28                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_49(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID49
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_49( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID4A                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.29                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_4A(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID4A
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_4A( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID4C                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.30                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_4C(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID4C
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_4C( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID4D                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.31                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_4D(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID4D
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_4D( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID4E                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.32                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_4E(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID4E
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_4E( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID4F                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.33                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_4F(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID4F
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_4F( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID50                                        */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.34                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_50(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID50
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = OBDMODE1_Pid_50( &Data[0] );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID72_Data1                                  */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.35                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_72(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID72_Data1
(
   uint8* Data
)
{
   uint32         u32LocalIndex;
   Std_ReturnType u8LocalReturn;
   uint8          au8Local[5];

   u8LocalReturn = OBDMODE1_Pid_72( &au8Local[0] );

   for( u32LocalIndex = 0 ; u32LocalIndex < 4 ; u32LocalIndex++ )
   {
      Data[u32LocalIndex] = au8Local[u32LocalIndex];
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_OBDMode01_PID72_Data2                                  */
/* !Description :  Is called from Dcm when OBD mode 01 request is received.   */
/* !Number      :  OBDMode01_API1.36                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OBDMODE1_Pid_72(argin uint8 *Data);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_OBDMode01_PID72_Data2
(
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;
   uint8          au8Local[5];

   u8LocalReturn = OBDMODE1_Pid_72( &au8Local[0] );

   Data[0] = au8Local[4];

   return u8LocalReturn;
}