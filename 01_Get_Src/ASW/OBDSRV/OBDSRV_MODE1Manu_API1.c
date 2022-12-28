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
/* !File            : OBDSRV_MODE1Manu_API1.c                                 */
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
/*   1 / OBDMODE1_Pid_72                                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV/OBDSRV_MODE1Manu_$*/
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
/* !Function    :  OBDMODE1_Pid_72                                            */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE1Manu_API1.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_prmByteAPid72_C;                                          */
/*  input uint8 BoostActStl_rDuCyReqCplm;                                     */
/*  input uint8 TrbActStl_rOpTrbAct;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE1_Pid_72
(
   uint8* Data
)
{
   uint8 u8LocalValueCopy;

   /*VEMS_vidGET(Srv_prmByteAPid72_C,u8LocalValueCopy);*/ 
   Data[0] = Srv_prmByteAPid72_C;

   VEMS_vidGET(BoostActStl_rDuCyReqCplm,u8LocalValueCopy);
   Data[1] = u8LocalValueCopy;

   VEMS_vidGET(TrbActStl_rOpTrbAct,u8LocalValueCopy);
   Data[2] = u8LocalValueCopy;

   Data[3] = 0x00;
   Data[4] = 0x00;

   return E_OK;
}

