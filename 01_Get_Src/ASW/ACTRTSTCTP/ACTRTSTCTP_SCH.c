/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTCTP                                              */
/* !Description     : ACTRTSTCTP Component                                    */
/*                                                                            */
/* !Module          : ACTRTSTCTP                                              */
/* !Description     : ACTUATOR TEST OF POSITIVE TEMPERATURE COEFFICIENT       */
/*                                                                            */
/* !File            : ACTRTSTCTP_SCH.C                                        */
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
/*   1 / CTP_EveRst_ActrTstCTP                                                */
/*   2 / CTP_SdlMid_ActrTstCTP                                                */
/*                                                                            */
/* !Reference   : V02 NT 12 05323 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#064193                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ACTRTSTCTP/ACTRTSTCTP_SCH.C_v   $*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   11 Dec 2012 $*/
/* $Author::   HHAMLAOU                               $$Date::   11 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACTRTSTCTP.h"
#include "ACTRTSTCTP_L.h"
#include "ACTRTSTCTP_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTP_EveRst_ActrTstCTP                                      */
/* !Description :  Fonction d'accroche à l'event CTP_EveRst_ActrTstCTP        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTCTP_vidRstDft();                                  */
/*  extf argret void ACTRTSTCTP_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CTP_EveRst_ActrTstCTP                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTP_EveRst_ActrTstCTP(void)
{
   ACTRTSTCTP_vidRstDft();
   ACTRTSTCTP_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTP_SdlMid_ActrTstCTP                                      */
/* !Description :  Fonction d'accroche à l'event CTP_SdlMid_ActrTstCTP        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTCTP_vidCTPTst();                                  */
/*  input uint8 ACTRTSTCTP_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CTP_SdlMid_ActrTstCTP                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTP_SdlMid_ActrTstCTP(void)
{
   if (ACTRTSTCTP_u8Inhib != 0x5A)
   {
      ACTRTSTCTP_vidCTPTst();
   }
}
/*-------------------------------- End of file -------------------------------*/