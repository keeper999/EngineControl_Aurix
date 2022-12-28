/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRFRZ                                                 */
/* !Description     : IUPRFRZ component.                                      */
/*                                                                            */
/* !Module          : IUPRFRZ                                                 */
/* !Description     : IUPR DEACTIVATION                                       */
/*                                                                            */
/* !File            : IUPRFRZ_SCH.C                                           */
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
/*   1 / GD_EveRst_IuprFrz                                                    */
/*   2 / GD_SdlSlow_IuprFrz                                                   */
/*                                                                            */
/* !Reference   : V02 NT 11 03256 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRFRZ/IUPRFRZ_SCH.C_v      $*/
/* $Revision::   1.0      $$Author::   ALAOUNI        $$Date::   09 Jul 2011 $*/
/* $Author::   ALAOUNI                                $$Date::   09 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "IUPRFRZ.h"
#include "IUPRFRZ_L.h"
#include "IUPRFRZ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_IuprFrz                                          */
/* !Description :  ECU reset event                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.Jlizi                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRFRZ_vidDeactivation();                               */
/*  input uint8 IUPRFRZ_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_IuprFrz                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_IuprFrz(void)
{
   if (IUPRFRZ_u8Inhib != 0x5A)
   {
      IUPRFRZ_vidDeactivation();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SdlSlow_IuprFrz                                         */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.Jlizi                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRFRZ_vidDeactivation();                               */
/*  input uint8 IUPRFRZ_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_SdlSlow_IuprFrz                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlSlow_IuprFrz(void)
{
   if (IUPRFRZ_u8Inhib != 0x5A)
   {
      IUPRFRZ_vidDeactivation();
   }
}
/*------------------------------end-of-file-----------------------------------*/