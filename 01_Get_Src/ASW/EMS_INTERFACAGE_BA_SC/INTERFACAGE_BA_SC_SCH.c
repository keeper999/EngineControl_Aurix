/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INTERFACAGE_BA_SC                                       */
/* !Description     : INTERFACAGE_BA_SC Component                             */
/*                                                                            */
/* !Module          : INTERFACAGE_BA_SC                                       */
/* !Description     : Interfaçage Boucle Air / Structure Couple               */
/*                                                                            */
/* !File            : INTERFACAGE_BA_SC_SCH.C                                 */
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
/*   1 / INTERFACAGE_BA_SC_vidEntryInit                                       */
/*   2 / AirSys_SdlFast_InterfAirSysSC                                        */
/*   3 / EngM_SdlMid_InterfEngMSC                                             */
/*   4 / ExM_SdlFast_InterfExMSC                                              */
/*   5 / EngM_SdlMid_InterfUsThrMSC                                           */
/*                                                                            */
/* !Reference   : V02 NT 10 07792 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_2661_2 / 1.2                                    */
/* !OtherRefs   : VEMS V02 ECU#058226                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/Air/INTERFACAGE_BA_SC/INTE$*/
/* $Revision::   1.5.1.1  $$Author::   etsasson       $$Date::   04 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   04 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "INTERFACAGE_BA_SC.h"
#include "INTERFACAGE_BA_SC_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTERFACAGE_BA_SC_vidEntryInit                             */
/* !Description :  reset du calculateur                                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTERFACAGE_BA_SC_vidInitOutput();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : INTERFACAGE_BA_SC_vidEntryInit                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTERFACAGE_BA_SC_vidEntryInit(void)
{
   INTERFACAGE_BA_SC_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirSys_SdlFast_InterfAirSysSC                              */
/* !Description :  Scheduleur rapide de l'interfaçage du module AirSys        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTERFACAGE_BA_SC_vidIntAirSysSC();                      */
/*  input uint8 INTERFACAGE_BA_SC_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirSys_SdlFast_InterfAirSysSC                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirSys_SdlFast_InterfAirSysSC(void)
{
   if (INTERFACAGE_BA_SC_u8Inhib != 0x5A)
   {
      INTERFACAGE_BA_SC_vidIntAirSysSC();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngM_SdlMid_InterfEngMSC                                   */
/* !Description :  Scheduleur moyen de l'interfaçage du module EngM           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTERFACAGE_BA_SC_vidIntEngMSC();                        */
/*  input uint8 INTERFACAGE_BA_SC_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngM_SdlMid_InterfEngMSC                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngM_SdlMid_InterfEngMSC(void)
{
   if (INTERFACAGE_BA_SC_u8Inhib != 0x5A)
   {
      INTERFACAGE_BA_SC_vidIntEngMSC();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ExM_SdlFast_InterfExMSC                                    */
/* !Description :  Scheduleur rapide de l'interfaçage du module ExM           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTERFACAGE_BA_SC_vidInterfExMSC();                      */
/*  input uint8 INTERFACAGE_BA_SC_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ExM_SdlFast_InterfExMSC                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ExM_SdlFast_InterfExMSC(void)
{
   if (INTERFACAGE_BA_SC_u8Inhib != 0x5A)
   {
      INTERFACAGE_BA_SC_vidInterfExMSC();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngM_SdlMid_InterfUsThrMSC                                 */
/* !Description :  Scheduleur moyen de l'interfaçage du module UsThrM         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTERFACAGE_BA_SC_vidIntrfUsThrM();                      */
/*  input uint8 INTERFACAGE_BA_SC_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngM_SdlMid_InterfUsThrMSC                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngM_SdlMid_InterfUsThrMSC(void)
{
   if (INTERFACAGE_BA_SC_u8Inhib != 0x5A)
   {
      INTERFACAGE_BA_SC_vidIntrfUsThrM();
   }
}
/*-------------------------------- end of file -------------------------------*/