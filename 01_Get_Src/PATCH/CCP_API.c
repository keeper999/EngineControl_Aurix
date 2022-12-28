/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* !Layer           : APPLI                                                   */
/* !Component       : CCP                                                     */
/* !Description     : CCP Layer                                               */
/* !File            : CCP_API.c                                               */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CcpDaqListSetEvent_Fast                                              */
/*   2 / CcpDaqListSetEvent_Slow                                              */
/*   3 / CcpDaqListSetEvent_Angular                                           */
/*   4 / CcpDaqListSetEvent_Medium                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_XXXX / 01                                           */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/CCP_API.c_v                 $*/
/* $Revision::   1.2      $$Author::   croche2        $$Date::   03 Sep 2014 $*/
/* $Author::   croche2                                $$Date::   03 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "CCP.h"
#include "CCP_CFG.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CcpDaqListSetEvent_Fast                                    */
/* !Description :  Function to configure the DAQ list periodicity at FAST     */
/* !Number      :  API.1                                                      */
/* !Author      :  pbakabad                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CcpDaqListSetEvent(CcpEventType eventChannel);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CcpDaqListSetEvent_Fast(void)
{
   CCP_vidDaqListSetEvent(CCP_u8DAQ_EVT_EVENT_10MS);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CcpDaqListSetEvent_Medium                                  */
/* !Description :  Function to configure the DAQ list periodicity at SLOW     */
/* !Number      :  API.2                                                      */
/* !Author      :  pbakabad                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CcpDaqListSetEvent(CcpEventType eventChannel);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CcpDaqListSetEvent_Medium(void)
{
   CCP_vidDaqListSetEvent(CCP_u8DAQ_EVT_EVENT_100MS);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CcpDaqListSetEvent_Slow                                    */
/* !Description :  Function to configure the DAQ list periodicity at SLOW     */
/* !Number      :  API.2                                                      */
/* !Author      :  pbakabad                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CcpDaqListSetEvent(CcpEventType eventChannel);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CcpDaqListSetEvent_Slow(void)
{
   CCP_vidDaqListSetEvent(CCP_u8DAQ_EVT_EVENT_1000MS);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CcpDaqListSetEvent_Angular                                 */
/* !Description :  Function to configure the DAQ list periodicity at ANGULAR  */
/* !Number      :  API.3                                                      */
/* !Author      :  pbakabad                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CcpDaqListSetEvent(CcpEventType eventChannel);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CcpDaqListSetEvent_Angular(void)
{
   CCP_vidDaqListSetEvent(CCP_u8DAQ_EVT_EVENT_PMH);
}