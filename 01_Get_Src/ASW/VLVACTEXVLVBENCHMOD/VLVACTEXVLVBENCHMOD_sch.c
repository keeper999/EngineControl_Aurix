/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXVLVBENCHMOD                                     */
/* !Description     : VLVACTEXVLVBENCHMOD component.                          */
/*                                                                            */
/* !Module          : VLVACTEXVLVBENCHMOD                                     */
/* !Description     : EXHAUST VARIABLE VALVE TIMING SETPOINT IN BENCH MODE    */
/*                                                                            */
/* !File            : VLVACTEXVLVBENCHMOD_SCH.C                               */
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
/*   1 / VlvAct_EveRst_ExVlvSpBenchMod                                        */
/*   2 / VlvAct_SdlFast_ExVlvSpBenchMod                                       */
/*                                                                            */
/* !Reference   : V02 NT 09 08224 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXVLVBENCHMOD/VLV$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   28 Mar 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTEXVLVBENCHMOD.h"
#include "VLVACTEXVLVBENCHMOD_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_ExVlvSpBenchMod                              */
/* !Description :  Event Reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXVLVBENCHMOD_vidIniExVlv();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_EveRst_ExVlvSpBenchMod                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_ExVlvSpBenchMod(void)
{
   VLVACTEXVLVBENCHMOD_vidIniExVlv();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExVlvSpBenchMod                             */
/* !Description :  Fast schedule of the valve actuator function               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXVLVBENCHMOD_vidExVlv();                          */
/*  input uint8 VLVACTEXVLVBENCHMOD_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_SdlFast_ExVlvSpBenchMod                                 */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExVlvSpBenchMod(void)
{
   if(VLVACTEXVLVBENCHMOD_u8Inhib != 0x5A)
   {
      VLVACTEXVLVBENCHMOD_vidExVlv();
   }
}