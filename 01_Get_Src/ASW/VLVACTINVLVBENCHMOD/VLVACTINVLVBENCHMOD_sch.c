/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINVLVBENCHMOD                                     */
/* !Description     : VLVACTINVLVBENCHMOD component.                          */
/*                                                                            */
/* !Module          : VLVACTINVLVBENCHMOD                                     */
/* !Description     : INTAKE VARIABLE VALVE TIMING SETPOINT IN BENCH MODE     */
/*                                                                            */
/* !File            : VLVACTINVLVBENCHMOD_SCH.C                               */
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
/*   1 / VlvAct_EveRst_InVlvSpBenchMod                                        */
/*   2 / VlvAct_SdlFast_InVlvSpBenchMod                                       */
/*                                                                            */
/* !Reference   : V02 NT 09 07770 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINVLVBENCHMOD/VLV$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   28 Mar 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTINVLVBENCHMOD_L.h"
#include "VLVACTINVLVBENCHMOD.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_InVlvSpBenchMod                              */
/* !Description :  Event Reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINVLVBENCHMOD_vidIniInVlv();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_EveRst_InVlvSpBenchMod                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_InVlvSpBenchMod(void)
{
   VLVACTINVLVBENCHMOD_vidIniInVlv();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InVlvSpBenchMod                             */
/* !Description :  Fast schedule of the valve actuator function               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINVLVBENCHMOD_vidInVlv();                          */
/*  input uint8 VLVACTINVLVBENCHMOD_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_SdlFast_InVlvSpBenchMod                                 */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InVlvSpBenchMod(void)
{
   if(VLVACTINVLVBENCHMOD_u8Inhib != 0x5A)
   {
      VLVACTINVLVBENCHMOD_vidInVlv();
   }
}