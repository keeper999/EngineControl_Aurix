/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MUXDIAGON                                               */
/* !Description     : MUXDIAGON component.                                    */
/*                                                                            */
/* !Module          : MUXDIAGON                                               */
/* !Description     : GENERATION DU DIAG ON .                                 */
/*                                                                            */
/* !File            : MUXDIAGON_SCH.C                                         */
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
/*   1 / Mux_EveRst_MuxDiagOn                                                 */
/*   2 / Mux_SdlMid_MuxDiagOn                                                 */
/*                                                                            */
/* !Reference   : V02 NT 08 05997 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/MUXDIAGON/MUXDIAGON_SCH.C_v       $*/
/* $Revision::   1.1      $$Author::   fgravez        $$Date::   21 Jan 2010 $*/
/* $Author::   fgravez                                $$Date::   21 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MUXDIAGON.h"
#include "MUXDIAGON_l.h"
#include "MUXDIAGON_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Mux_EveRst_MuxDiagOn                                       */
/* !Description :  Reset event handler                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ	                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MUXDIAGON_Vid_Init();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Mux_EveRst_MuxDiagOn                                           */
/* !Trigger  : Mux_EveRst_MuxDiagOn                                           */
/*                                                                            */
/* !LastAuthor  : B.Safi                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Mux_EveRst_MuxDiagOn(void)
{
   MUXDIAGON_Vid_Init();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Mux_SdlMid_MuxDiagOn                                       */
/* !Description :  Mux_SdlMid_MuxDiagOn event handler                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ	                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MUXDIAGON_Vid_RunDiagOn();                               */
/*  input uint8 MUXDIAGON_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Mux_SdlMid_MuxDiagOn                                           */
/* !Trigger  : Mux_SdlMid_MuxDiagOn                                           */
/*                                                                            */
/* !LastAuthor  : B.Safi                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Mux_SdlMid_MuxDiagOn(void)
{
   if (MUXDIAGON_u8Inhib != 0x5A)
   {
      MUXDIAGON_Vid_RunDiagOn();
   }
}
/*------------------------------- end of file --------------------------------*/