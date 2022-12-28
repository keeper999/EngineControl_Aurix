/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TCOREGKNK                                               */
/* !Description     : TCOREGKNK Component                                     */
/*                                                                            */
/* !Module          : TCOREGKNK                                               */
/* !Description     : Cooling Request for Knock Control                       */
/*                                                                            */
/* !File            : TCOREGKNK_SCH.C                                         */
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
/*   1 / TCOREGKNK_vidEntryInit                                               */
/*   2 / IgSys_SdlFast_TCoRegKnk                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 04673 / 01                                        */
/* !OtherRefs   : 01460_11_01153_2 / 1                                        */
/* !OtherRefs   : VEMS V02 ECU#056462                                         */
/* !OtherRefs   : VEMS V02 ECU#056985                                         */
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
#include "TCOREGKNK.h"
#include "TCOREGKNK_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TCOREGKNK_vidEntryInit                                     */
/* !Description :  reset du calculateur                                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04673_001.01                                     */
/*                 VEMS_R_11_04673_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TCOREGKNK_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TCOREGKNK_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TCOREGKNK_vidEntryInit(void)
{
   TCOREGKNK_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_SdlFast_TCoRegKnk                                    */
/* !Description :  Occurrence  d'appel de la  fonction  activation du         */
/*                 refroidissement pour la garde rumble                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04673_001.01                                     */
/*                 VEMS_R_11_04673_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TCOREGKNK_vidFlag_Generation();                          */
/*  extf argret void TCOREGKNK_vidActiv_Condition();                          */
/*  extf argret void TCOREGKNK_vidCool_Req_Coord();                           */
/*  input uint8 TCOREGKNK_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_SdlFast_TCoRegKnk                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_SdlFast_TCoRegKnk(void)
{
   if (TCOREGKNK_u8Inhib != 0x5A)
   {
      TCOREGKNK_vidFlag_Generation();
      TCOREGKNK_vidActiv_Condition();
      TCOREGKNK_vidCool_Req_Coord();
   }
}
/*-------------------------------- end of file -------------------------------*/