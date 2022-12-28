/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTQEFF                                                */
/* !Description     : AIRTQEFF component                                      */
/*                                                                            */
/* !Module          : AIRTQEFF                                                */
/* !Description     : Calcul du rendement pour la transformation couple /     */
/*                    masse d_air                                             */
/*                                                                            */
/* !File            : AIRTQEFF_SCH.C                                          */
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
/*   1 / AirSys_EveIni_AirTqEff                                               */
/*   2 / AirSys_SdlFast_AirTqEff                                              */
/*                                                                            */
/* !Reference   : V02 NT 10 07791 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_0475_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#051747                                         */
/* !OtherRefs   : VEMS V02 ECU#058235                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/AIR/AIRTQEFF/AIRTQEFF_SCH.$*/
/* $Revision::   1.3.1.1  $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "AIRTQEFF.h"
#include "AIRTQEFF_L.h"
#include "AIRTQEFF_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirSys_EveIni_AirTqEff                                     */
/* !Description :  Evenement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_001.01                                     */
/*                 VEMS_R_10_07791_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidInit_rendement();                            */
/*  extf argret void AIRTQEFF_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirSys_EveIni_AirTqEff                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirSys_EveIni_AirTqEff(void)
{
   AIRTQEFF_vidInit_rendement();
   AIRTQEFF_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirSys_SdlFast_AirTqEff                                    */
/* !Description :  Scheduler rapide de la fonction AirTqEff                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_001.01                                     */
/*                 VEMS_R_10_07791_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidCalc_rendement();                            */
/*  input uint8 AIRTQEFF_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirSys_SdlFast_AirTqEff                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirSys_SdlFast_AirTqEff(void)
{
   if (AIRTQEFF_u8Inhib != 0x5A)
   {
      AIRTQEFF_vidCalc_rendement();
   }
}
/*---------------------------------end of file--------------------------------*/