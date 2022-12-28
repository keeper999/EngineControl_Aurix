/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPMNGMODSECU                                          */
/* !Description     : ACCPMNGMODSECU Component.                               */
/*                                                                            */
/* !Module          : ACCPMNGMODSECU                                          */
/* !Description     : Security modes management for the gas pedal             */
/*                                                                            */
/* !File            : ACCPMNGMODSECU_SCH.C                                    */
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
/*   1 / AccP_EveRst_AccPMngModSec                                            */
/*   2 / AccP_SdlFast_AccPMngModSec                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_7317422 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#069330                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/REF/modules/ACCPMNGMODSECU/ACCPMNGMODSECU_S$*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   03 Oct 2014 $*/
/* $Author::   achebino                               $$Date::   03 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACCPMNGMODSECU.h"
#include "ACCPMNGMODSECU_L.h"
#include "ACCPMNGMODSECU_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_AccPMngModSec                                  */
/* !Description :  ECU reset                                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  LDHI                                                       */
/* !Trace_To    :  PTS_R_7317422_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPMNGMODSECU_vidInit();                                */
/*  extf argret void ACCPMNGMODSECU_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_EveRst_AccPMngModSec                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_AccPMngModSec(void)
{
   ACCPMNGMODSECU_vidInit();
   ACCPMNGMODSECU_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_AccPMngModSec                                 */
/* !Description :  Fast scheduler                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  LDHI                                                       */
/* !Trace_To    :  PTS_R_7317422_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPMNGMODSECU_vidComputeAccPMng();                      */
/*  input uint8 ACCPMNGMODSECU_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_AccPMngModSec                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_AccPMngModSec(void)
{
   if (ACCPMNGMODSECU_u8Inhib != 0x5A)
   {
      ACCPMNGMODSECU_vidComputeAccPMng();
   }
}
/*-------------------------------End Of File----------------------------------*/