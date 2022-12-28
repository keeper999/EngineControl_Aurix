/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SpgPresSp                                               */
/* !Description     : SpgPresSp component.                                    */
/*                                                                            */
/* !Module          : SpgPresSp                                               */
/* !Description     : BOOST PRESSURE SETPOINT CALCULATION                     */
/*                                                                            */
/* !File            : SPGPRESSP_SCH.C                                         */
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
/*   1 / AirPres_EveRst_SpgPresSp                                             */
/*   2 / AirPres_SdlMid_SpgPresSp                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 08194 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "STD_TYPES.h"
#include "SpgPresSp.h"
#include "SpgPresSp_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_SpgPresSp                                   */
/* !Description :  Event Reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SpgPresSp_vidSpgPresSpIni();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_SpgPresSp                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_SpgPresSp(void)
{
   SpgPresSp_vidSpgPresSpIni();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_SpgPresSp                                   */
/* !Description :  Middle scheduler of the Airpres function                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SpgPresSp_vidMng_CalcSpgPresSpBenchMod();                */
/*  extf argret void SpgPresSp_vidCmuSpgPresSp();                             */
/*  input uint8 SpgPresSp_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_SpgPresSp                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_SpgPresSp(void)
{
   if( SpgPresSp_u8Inhib != 0x5A )
   {
      SpgPresSp_vidMng_CalcSpgPresSpBenchMod();
      SpgPresSp_vidCmuSpgPresSp();
   }
}

/*---------------------------------End Of File--------------------------------*/