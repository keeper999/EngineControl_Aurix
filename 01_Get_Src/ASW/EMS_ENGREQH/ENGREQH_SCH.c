/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGREQH                                                 */
/* !Description     : ENGREQH component.                                      */
/*                                                                            */
/* !Module          : ENGREQH                                                 */
/* !Description     : ERH                                                     */
/*                                                                            */
/* !File            : ENGREQH_SCH.C                                           */
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
/*   1 / ENGREQH_vidEntryInit                                                 */
/*   2 / EngReqH_SdlMid_EngReqH                                               */
/*   3 / EngReqH_SdlFast_EngReqH                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 05960 / 08                                        */
/* !OtherRefs   : CSMT_CGMT08_2303 / 2.6                                      */
/* !OtherRefs   : VEMS V02 ECU#058179                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/ENGREQH/ENGREQH_SCH.C_$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ENGREQH.h"
#include "ENGREQH_L.h"
#include "ENGREQH_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidEntryInit                                       */
/* !Description :  Fonction d'accroche Reset.                                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_001.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ENGREQH_vidEntryInit                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidEntryInit(void)
{
   ENGREQH_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngReqH_SdlMid_EngReqH                                     */
/* !Description :  Scheduler intermédiaire                                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_001.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidCondTempEauAutoriStop();                      */
/*  extf argret void ENGREQH_vidCondTempHuileAutoStop();                      */
/*  extf argret void ENGREQH_vidTempoDemarrageAutStop();                      */
/*  extf argret void ENGREQH_vidCondTemperAirAutoStop();                      */
/*  extf argret void ENGREQH_vidCondTempCatalyAutStop();                      */
/*  extf argret void ENGREQH_vidCondPresHuileAutoStop();                      */
/*  extf argret void ENGREQH_vidDemandeRedemarrage();                         */
/*  extf argret void ENGREQH_vidCriticPresAtmospheriq();                      */
/*  input uint8 EngReqH_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngReqH_SdlMid_EngReqH                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngReqH_SdlMid_EngReqH(void)
{
   if (EngReqH_u8Inhib != 0x5A)
   {
      ENGREQH_vidCondTempEauAutoriStop();
      ENGREQH_vidCondTempHuileAutoStop();
      ENGREQH_vidTempoDemarrageAutStop();
      ENGREQH_vidCondTemperAirAutoStop();
      ENGREQH_vidCondTempCatalyAutStop();
      ENGREQH_vidCondPresHuileAutoStop();
      ENGREQH_vidDemandeRedemarrage();
      ENGREQH_vidCriticPresAtmospheriq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngReqH_SdlFast_EngReqH                                    */
/* !Description :  Fonction d'accroche au moniteur 10ms                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_001.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidCondSondLambdaAutStop();                      */
/*  extf argret void ENGREQH_vidConTempCarTurbAutStop();                      */
/*  extf argret void ENGREQH_vidSelectActivFonctions();                       */
/*  extf argret void ENGREQH_vidAutorisMoteurSTOP();                          */
/*  extf argret void ENGREQH_vidCondRedemaAutonomeSTT();                      */
/*  input uint8 EngReqH_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngReqH_SdlFast_EngReqH                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngReqH_SdlFast_EngReqH(void)
{
   if (EngReqH_u8Inhib != 0x5A)
   {
      ENGREQH_vidCondSondLambdaAutStop();
      ENGREQH_vidConTempCarTurbAutStop();
      ENGREQH_vidSelectActivFonctions();
      ENGREQH_vidAutorisMoteurSTOP();
      ENGREQH_vidCondRedemaAutonomeSTT();
   }
}
/*-------------------------------- end of file -------------------------------*/