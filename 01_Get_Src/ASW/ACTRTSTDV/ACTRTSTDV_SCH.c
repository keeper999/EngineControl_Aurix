/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTDV                                               */
/* !Description     : ACTRTSTDV Component                                     */
/*                                                                            */
/* !Module          : ACTRTSTDV                                               */
/* !Description     : Dump Valve Actuator Test                                */
/*                                                                            */
/* !File            : ACTRTSTDV_SCH.C                                         */
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
/*   1 / DmpVlv_EveRst_ActrTstDV                                              */
/*   2 / DmpVlv_SdlFast_ActrTstDV                                             */
/*                                                                            */
/* !Reference   : V02 NT 11 02175 / 01                                        */
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
#include "ACTRTSTDV.h"
#include "ACTRTSTDV_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlv_EveRst_ActrTstDV                                    */
/* !Description :  Fonction d'accroche à l'event DmpVlv_EveRst_ActrTstDV      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTDV_vidInitOutput();                               */
/*  extf argret void ACTRTSTDV_vidDVTST();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlv_EveRst_ActrTstDV                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlv_EveRst_ActrTstDV(void)
{
   ACTRTSTDV_vidInitOutput();
   ACTRTSTDV_vidDVTST();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlv_SdlFast_ActrTstDV                                   */
/* !Description :  Fonction d'accroche à l'event DmpVlv_SdlFast_ActrTstDV     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTDV_vidDVTST();                                    */
/*  input uint8 ACTRTSTDV_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlv_SdlFast_ActrTstDV                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlv_SdlFast_ActrTstDV(void)
{
   if (ACTRTSTDV_u8Inhib != 0x5A)
   {
      ACTRTSTDV_vidDVTST();
   }
}
/*-------------------------------- End of file -------------------------------*/