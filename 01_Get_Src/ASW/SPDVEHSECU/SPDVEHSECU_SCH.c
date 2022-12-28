/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPDVEHSECU                                              */
/* !Description     : SPDVEHSECU component.                                   */
/*                                                                            */
/* !Module          : SPDVEHSECU                                              */
/* !Description     : Calculation of a secured speed for the STT function     */
/*                                                                            */
/* !File            : SPDVEHSECU_SCH.C                                        */
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
/*   1 / SftyMgt_EveRst_SpdVehSecu                                            */
/*   2 / SftyMgt_SdlFast_SpdVehSecu                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5664717 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SPDVEHSECU/SPDVEHSECU_SCH.c_v     $*/
/* $Revision::   1.1      $$Author::   ACHEBINO       $$Date::   09 May 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   09 May 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SPDVEHSECU.h"
#include "SPDVEHSECU_L.h"
#include "SPDVEHSECU_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRst_SpdVehSecu                                  */
/* !Description :  Evenement d'initialisation.                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  LDHI                                                       */
/* !Trace_To    :  VEMS_R_11_04770_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPDVEHSECU_vidIni();                                     */
/*  extf argret void SPDVEHSECU_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRst_SpdVehSecu                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRst_SpdVehSecu(void)
{

   SPDVEHSECU_vidIni();
   SPDVEHSECU_vidInitOutput();

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlFast_SpdVehSecu                                 */
/* !Description :  Moniteur rapide de la fonction SftyMgt.                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  LDHI                                                       */
/* !Trace_To    :  VEMS_R_11_04770_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPDVEHSECU_vidSecuredSpeedInfo();                        */
/*  input uint8 SPDVEHSECU_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlFast_SpdVehSecu                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlFast_SpdVehSecu(void)
{

   if(SPDVEHSECU_u8Inhib != 0x5A)
   {
      SPDVEHSECU_vidSecuredSpeedInfo();
   }

}
/*------------------------------- end of file --------------------------------*/