/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SUMRAT                                                  */
/* !Description     : SUMRAT Component                                        */
/*                                                                            */
/* !Module          : SUMRAT                                                  */
/* !Description     : Pre-consolidation modules for IUPR Ratios               */
/*                                                                            */
/* !File            : SUMRAT_SCH.C                                            */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / GD_EveRst_SumRat                                                     */
/*   2 / GD_SdlSlow_SumRat                                                    */
/*                                                                            */
/* !Reference   : V02 NT 10 06202 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/SUMRAT/SumRat_sch.c_v        $*/
/* $Revision::   1.2      $$Author::   alaouni        $$Date::   21 Feb 2012 $*/
/* $Author::   alaouni                                $$Date::   21 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "SUMRAT.h"
#include "SUMRAT_L.h"
#include "SUMRAT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_SumRat                                           */
/* !Description :  ECU reset event                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  RR.RAOUAGI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SUMRAT_vidF01();                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : GD_EveRst_SumRat                                               */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_SumRat(void)
{
   SUMRAT_vidF01();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SdlSlow_SumRat                                          */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  RR.RAOUAGI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SUMRAT_vidF02();                                         */
/*  input uint8 SUMRAT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : GD_SdlSlow_SumRat                                              */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlSlow_SumRat(void)
{
   if(SUMRAT_u8Inhib != 0x5A)
   {
      SUMRAT_vidF02();
   }
}
