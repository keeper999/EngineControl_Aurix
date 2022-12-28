/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WGACTRTEST                                              */
/* !Description     : WGACTRTEST component.                                   */
/*                                                                            */
/* !Module          : WGACTRTEST                                              */
/* !Description     : WASTE GATE ACTUATOR TEST                                */
/*                                                                            */
/* !File            : WGACTRTEST_SCH.C                                        */
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
/*   1 / Wg_EveRst_WgActrTest                                                 */
/*   2 / Wg_SdlSlow_WgActrTest                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5621841 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/WG/WGACTRTEST/WGACTRTEST_SCH.C_v$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   14 Oct 2013 $*/
/* $Author::   etsasson                               $$Date::   14 Oct 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "WGACTRTEST.h"
#include "WGACTRTEST_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_EveRst_WgActrTest                                       */
/* !Description :  Evenement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_05642_001.01                                     */
/*                 VEMS_E_11_05642_002.01                                     */
/*                 VEMS_E_11_05642_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WGACTRTEST_vidInitOutput();                              */
/*  extf argret void WGACTRTEST_vidWgActrTest();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_EveRst_WgActrTest                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_EveRst_WgActrTest(void)
{
   WGACTRTEST_vidInitOutput();
   WGACTRTEST_vidWgActrTest();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlSlow_WgActrTest                                      */
/* !Description :  SdlSlow pour WgActrTest                                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WGACTRTEST_vidWgActrTest();                              */
/*  input uint8 WGACTRTEST_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_SdlMid_WgActrTest                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlSlow_WgActrTest(void)
{
   if (WGACTRTEST_u8Inhib != 0x5A)
   {
      WGACTRTEST_vidWgActrTest();
   }
}

/*---------------------------------End Of File--------------------------------*/