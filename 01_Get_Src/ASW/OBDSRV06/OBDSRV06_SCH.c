/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OBDSRV06                                                */
/* !Description     : OBDSRV06 Component                                      */
/*                                                                            */
/* !Module          : OBDSRV06                                                */
/* !Description     : Definition des Trames EOBD pour le Mode06               */
/*                                                                            */
/* !File            : OBDSRV06_SCH.c                                          */
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
/*   1 / Srv_EvePwrl_ObdSrv06                                                 */
/*   2 / Srv_EveRstDftObd_ObdSrv06                                            */
/*   3 / Srv_EveRstDft_ObdSrv06                                               */
/*   4 / Srv_EveRst_ObdSrv06                                                  */
/*   5 / Srv_SdlMid_ObdSrv06                                                  */
/*   6 / OBDSRV06_NVMSRV_vidInit                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 04787 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#061812                                         */
/* !OtherRefs   : VEMS V02 ECU#062507                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV06/OBDSRV06_SCH.c_$*/
/* $Revision::   1.9      $$Author::   pbakabad       $$Date::   Jul 05 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 05 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "OBDSRV06_im.h"
#include "OBDSRV06.h"
#include "OBDSRV06_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EvePwrl_ObdSrv06                                       */
/* !Description :  Evènement d'écriture au powerlatch                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_04787_001.01                                     */
/*                 VEMS_R_11_04787_002.01                                     */
/*                 VEMS_R_11_04787_003.01                                     */
/*                 VEMS_R_11_04787_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OBDSRV06_pwrl();                                         */
/*  input uint8 OBDSRV06_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Srv_EvePwrl_ObdSrv06                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EvePwrl_ObdSrv06(void)
{
   if(OBDSRV06_u8Inhib != 0x5A)
   {
      OBDSRV06_pwrl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRstDftObd_ObdSrv06                                  */
/* !Description :  Evènement d'effacement des pannes OBD                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_04787_001.01                                     */
/*                 VEMS_R_11_04787_002.01                                     */
/*                 VEMS_R_11_04787_003.01                                     */
/*                 VEMS_R_11_04787_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OBDSRV06_EveRstDft();                                    */
/*  input uint8 OBDSRV06_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Srv_EveRstDftObd_ObdSrv06                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRstDftObd_ObdSrv06(void)
{
   if(OBDSRV06_u8Inhib != 0x5A)
   {
      OBDSRV06_EveRstDft();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRstDft_ObdSrv06                                     */
/* !Description :  Evènement indiquant la demande d'effacement des défauts par*/
/*                 l'outil APV                                                */
/* !Number      :  SCH.3                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_04787_001.01                                     */
/*                 VEMS_R_11_04787_002.01                                     */
/*                 VEMS_R_11_04787_003.01                                     */
/*                 VEMS_R_11_04787_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OBDSRV06_EveRstDft();                                    */
/*  input uint8 OBDSRV06_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Srv_EveRstDft_ObdSrv06                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRstDft_ObdSrv06(void)
{
   if(OBDSRV06_u8Inhib != 0x5A)
   {
      OBDSRV06_EveRstDft();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRst_ObdSrv06                                        */
/* !Description :  Evénement reset de la fonction                             */
/* !Number      :  SCH.4                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_04787_001.01                                     */
/*                 VEMS_R_11_04787_002.01                                     */
/*                 VEMS_R_11_04787_003.01                                     */
/*                 VEMS_R_11_04787_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OBDSRV06_EveRst();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Srv_EveRst_ObdSrv06                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRst_ObdSrv06(void)
{
   OBDSRV06_EveRst();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlMid_ObdSrv06                                        */
/* !Description :  Cheduler moyen de la fonction                              */
/* !Number      :  SCH.5                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_04787_001.01                                     */
/*                 VEMS_R_11_04787_002.01                                     */
/*                 VEMS_R_11_04787_003.01                                     */
/*                 VEMS_R_11_04787_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OBDSRV06_SdlMid();                                       */
/*  input uint8 OBDSRV06_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Srv_SdlMid_ObdSrv06                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlMid_ObdSrv06(void)
{
   if(OBDSRV06_u8Inhib != 0x5A)
   {
      OBDSRV06_SdlMid();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDSRV06_NVMSRV_vidInit                                    */
/* !Description :  Evénement init de l'EEPROM de la fonction                  */
/* !Number      :  SCH.6                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OBDSRV06_EveRstDft();                                    */
/*  input uint8 OBDSRV06_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OBDSRV06_NVMSRV_vidInit(void)
{
   if(OBDSRV06_u8Inhib != 0x5A)
   {
      OBDSRV06_EveRstDft();
   }
}