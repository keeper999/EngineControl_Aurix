/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSYSSPBENCHMOD                                         */
/* !Description     : TQSYSSPBENCHMOD component.                              */
/*                                                                            */
/* !Module          : TQSYSSPBENCHMOD                                         */
/* !Description     : TORQUE SETPOINT CALCULATION IN BENCH MODE               */
/*                                                                            */
/* !File            : TQSYSSPBENCHMOD_sch.c                                   */
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
/*   1 / TqSys_EveRst_SpBenchMod                                              */
/*   2 / TqSys_SdlFast_SpBenchMod                                             */
/*   3 / TqSys_EveTDC_SpBenchMod                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 08176 / 1                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "STD_TYPES.h"
#include "TQSYSSPBENCHMOD.h"
#include "TQSYSSPBENCHMOD_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveRst_SpBenchMod                                    */
/* !Description :  Event Reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam();              */
/*  extf argret void TQSYSSPBENCHMOD_vidInit_TqSpBenchMod();                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_EveRst_SpBenchMod                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveRst_SpBenchMod(void)
{
   TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam();
   TQSYSSPBENCHMOD_vidInit_TqSpBenchMod();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_SdlFast_SpBenchMod                                   */
/* !Description :  Fast scheduler of the torque function in Bench mode        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam();              */
/*  extf argret void TQSYSSPBENCHMOD_vidManage_TqAirSpBenchMod();             */
/*  input uint8 TQSYSSPBENCHMOD_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_SdlFast_SpBenchMod                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_SdlFast_SpBenchMod(void)
{
   if(TQSYSSPBENCHMOD_u8Inhib != 0x5A)
   {
      TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam();
      TQSYSSPBENCHMOD_vidManage_TqAirSpBenchMod();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveTDC_SpBenchMod                                    */
/* !Description :  Event TDC                                                  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSSPBENCHMOD_vidManage_TqIgnSpBenchMod();             */
/*  input uint8 TQSYSSPBENCHMOD_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_EveTDC_SpBenchMod                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveTDC_SpBenchMod(void)
{
   if(TQSYSSPBENCHMOD_u8Inhib != 0x5A)
   {
      TQSYSSPBENCHMOD_vidManage_TqIgnSpBenchMod();
   }
}