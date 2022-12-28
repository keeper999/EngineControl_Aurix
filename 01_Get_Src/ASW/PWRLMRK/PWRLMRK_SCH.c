/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PWRLMRK                                                 */
/* !Description     : PWRLMRK Component                                       */
/*                                                                            */
/* !Module          : PWRLMRK                                                 */
/* !Description     : Power Latch Marker                                      */
/*                                                                            */
/* !File            : PWRLMRK_SCH.c                                           */
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
/*   1 / Srv_EveRst_PwrlMrk                                                   */
/*   2 / Srv_EveRcReinit_PwrlMrk                                              */
/*   3 / EcuSt_EveFct_PwrlMrk                                                 */
/*   4 / Srv_SdlFast_PwrlMrk                                                  */
/*                                                                            */
/* !Reference   : V02 NT 11 04404 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#059680                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PWRLMRK/PWRLMRK_SCH.c_v         $*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   21 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   21 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PWRLMRK.h"
#include "PWRLMRK_L.h"
#include "PWRLMRK_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRst_PwrlMrk                                         */
/* !Description :  Event Reset for power latch.                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLMRK_vidEveRstPwrlMrk();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveRst_PwrlMrk                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRst_PwrlMrk(void)
{
   PWRLMRK_vidEveRstPwrlMrk();

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRcReinit_PwrlMrk                                    */
/* !Description :  Reset event of the powerlatch marker sent by a diagnostic  */
/*                 tool.                                                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLMRK_vidInitPwrlMrk();                                */
/*  input uint8 PWRLMRK_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveRcReinit_PwrlMrk                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRcReinit_PwrlMrk(void)
{
   if (PWRLMRK_u8Inhib != 0x5A)
   {
      PWRLMRK_vidInitPwrlMrk();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveFct_PwrlMrk                                       */
/* !Description :  Event recurrence to launch the API: AllSaved that checks if*/
/*                 all the  parameters have been saved in the Eeprom writings */
/*                 during the power latch state.                              */
/* !Number      :  SCH.3                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLMRK_vidPwrlMrk();                                    */
/*  input uint8 PWRLMRK_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveFct_PwrlMrk                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveFct_PwrlMrk(void)
{
   if (PWRLMRK_u8Inhib != 0x5A)
   {
      PWRLMRK_vidPwrlMrk();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlFast_PwrlMrk                                        */
/* !Description :  Fast scheduler for Srv.                                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLMRK_vidDiagPwrlMrk();                                */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 PWRLMRK_u8Inhib;                                              */
/*  input boolean Srv_bDgoPwrlMrk;                                            */
/*  input boolean Srv_bMonRunPwrlMrk;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_SdlFast_PwrlMrk                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlFast_PwrlMrk(void)
{
   if (PWRLMRK_u8Inhib != 0x5A)
   {
      PWRLMRK_vidDiagPwrlMrk();
      GDGAR_vidGdu(GD_DFT_PWRLMRK,
                   Srv_bDgoPwrlMrk,
                   Srv_bMonRunPwrlMrk,
                   DIAG_DISPO);
   }
}
/*-----------------------------end of file----------------------------*/