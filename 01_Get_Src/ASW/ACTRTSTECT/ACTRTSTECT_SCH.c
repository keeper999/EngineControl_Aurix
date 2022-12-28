/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTECT                                              */
/* !Description     : ACTRTSTECT component.                                   */
/*                                                                            */
/* !Module          : ACTRTSTECT                                              */
/* !Description     : Actuator test of Electronically Controlled Thermostat   */
/*                                                                            */
/* !File            : ACTRTSTECT_SCH.C                                        */
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
/*   1 / ThMgt_EveRst_ActrTstECT                                              */
/*   2 / ThMgt_SdlMid_ActrTstECT                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 06916 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#060124                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/COFAN/ACTRTSTECT/ACTRTSTECT_SCH.$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   27 Mar 2012 $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Mar 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "ACTRTSTECT.h"
#include "ACTRTSTECT_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ThMgt_EveRst_ActrTstECT                                    */
/* !Description :  ECU reset event.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Maissa.ABCHA                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTECT_vidInitOutput();                              */
/*  extf argret void ACTRTSTECT_vidECTTst();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ThMgt_EveRst_ActrTstECT                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ThMgt_EveRst_ActrTstECT(void)
{
   ACTRTSTECT_vidInitOutput();
   ACTRTSTECT_vidECTTst();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ThMgt_SdlMid_ActrTstECT                                    */
/* !Description :  Middle monitoring of the function.                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Maissa.ABCHA                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTECT_vidECTTst();                                  */
/*  input uint8 ACTRTSTECT_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ThMgt_SdlMid_ActrTstECT                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ThMgt_SdlMid_ActrTstECT(void)
{
   if (ACTRTSTECT_u8Inhib != 0x5A)
   {
      ACTRTSTECT_vidECTTst();
   }
}

/*---------------------------------End Of File--------------------------------*/