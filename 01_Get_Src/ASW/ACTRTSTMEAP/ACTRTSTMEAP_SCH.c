/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTMEAP                                             */
/* !Description     : ACTRTSTMEAP Component                                   */
/*                                                                            */
/* !Module          : ACTRTSTMEAP                                             */
/* !Description     : ACTUATOR TEST OF DRIVEN FLAP                            */
/*                                                                            */
/* !File            : ACTRTSTMEAP_SCH.C                                       */
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
/*   1 / MEAP_EveRst_ActrTstMEAP                                              */
/*   2 / MEAP_SdlMid_ActrTstMEAP                                              */
/*                                                                            */
/* !Reference   : V02 NT 12 05332 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ACTRTSTMEAP/ACTRTSTMEAP_SCH.C_v $*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   21 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   21 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "ACTRTSTMEAP.h"
#include "ACTRTSTMEAP_L.h"
#include "ACTRTSTMEAP_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEAP_EveRst_ActrTstMEAP                                    */
/* !Description :  ECU reset event                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTMEAP_vidInitOutput();                             */
/*  extf argret void ACTRTSTMEAP_vidRstDft();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MEAP_EveRst_ActrTstMEAP                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEAP_EveRst_ActrTstMEAP(void)
{
   ACTRTSTMEAP_vidInitOutput();
   ACTRTSTMEAP_vidRstDft();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEAP_SdlMid_ActrTstMEAP                                    */
/* !Description :  Middle monitoring of MEAP function                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTMEAP_vidMEAPTst();                                */
/*  input uint8 ACTRTSTMEAP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MEAP_SdlMid_ActrTstMEAP                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEAP_SdlMid_ActrTstMEAP(void)
{
   if (ACTRTSTMEAP_u8Inhib != 0x5A)
   {
      ACTRTSTMEAP_vidMEAPTst();
   }
}
/*------------------------------- end of file --------------------------------*/