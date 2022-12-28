/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AccP                                                    */
/* !Description     : AccP component.                                         */
/*                                                                            */
/* !Module          : ACCPCALCRPOS                                            */
/* !Description     : Calcul de la position pedale relative a partir des      */
/*                    positions pied à fond et pied leve                      */
/*                                                                            */
/* !File            : ACCPCALCRPOS_SCH.C                                      */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / AccP_EveRst_Clc                                                      */
/*   2 / AccP_SdlFast_Clc                                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_7293537 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPCALCRPOS/AccPCalcRPos_sch$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   wbouach                                $$Date::   22 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACCPCALCRPOS.h"
#include "ACCPCALCRPOS_L.h"
#include "ACCPCALCRPOS_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_Clc                                            */
/* !Description :  Evènement de reset                                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPCALCRPOS_vidInit();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_EveRst_Clc                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_Clc(void)
{
   ACCPCALCRPOS_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_Clc                                           */
/* !Description :  Fonction d'accroche à l'evenement AccP_SdlFast_Clc         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPCALCRPOS_vidDVApp();                                 */
/*  extf argret void ACCPCALCRPOS_vidEtat_pos_aps();                          */
/*  extf argret void ACCPCALCRPOS_vidFinal_state_Pos();                       */
/*  input uint8 ACCPCALCRPOS_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_Clc                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_Clc(void)
{
   if (ACCPCALCRPOS_u8Inhib != 0x5A)
   {
      ACCPCALCRPOS_vidDVApp();
      ACCPCALCRPOS_vidEtat_pos_aps();
      ACCPCALCRPOS_vidFinal_state_Pos();
   }
}
/*------------------------------- end of file --------------------------------*/