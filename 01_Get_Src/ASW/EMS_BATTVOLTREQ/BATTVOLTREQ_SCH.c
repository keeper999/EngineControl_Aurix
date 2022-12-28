/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BATTVOLTREQ                                             */
/* !Description     : BATTVOLTREQ component.                                  */
/*                                                                            */
/* !Module          : BATTVOLTREQ                                             */
/* !Description     : BATTERY VOLTAGE BOOST REQUEST                           */
/*                                                                            */
/* !File            : BATTVOLTREQ_SCH.C                                       */
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
/*   1 / BoostReq_EveIni_BattVoltReq                                          */
/*   2 / BoostReq_SdlFast_BattVoltReq                                         */
/*                                                                            */
/* !Reference   : V02 NT 11 04680 / 01                                        */
/* !OtherRefs   : 01460_11_00651_2 / 01                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BATTVOLTREQ.h"
#include "BATTVOLTREQ_L.h"
#include "BATTVOLTREQ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BoostReq_EveIni_BattVoltReq                                */
/* !Description :  Evénnement du Reset                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_04668_001.01                                     */
/*                 VEMS_R_11_04668_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BATTVOLTREQ_vidInitOutput();                             */
/*  extf argret void BATTVOLTREQ_vidInit();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BoostReq_EveIni_BattVoltReq                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BoostReq_EveIni_BattVoltReq(void)
{
   BATTVOLTREQ_vidInitOutput();
   BATTVOLTREQ_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BoostReq_SdlFast_BattVoltReq                               */
/* !Description :  Evènement 10 ms.                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_04668_001.01                                     */
/*                 VEMS_R_11_04668_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BATTVOLTREQ_vidBattVltRqstLowVlt();                      */
/*  input uint8 BATTVOLTREQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BoostReq_SdlFast_BattVoltReq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BoostReq_SdlFast_BattVoltReq(void)
{
   if (BATTVOLTREQ_u8Inhib != 0x5A)
   {
      BATTVOLTREQ_vidBattVltRqstLowVlt();
   }
}
/*-------------------------------- end of file -------------------------------*/