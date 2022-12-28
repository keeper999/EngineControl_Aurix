/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_SCH8.C                                    */
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
/*   1 / RE_StopStrtEng_023_MSEIf                                             */
/*   2 / Thr_SdlMid_MngServoIf                                                */
/*   3 / InjCtl_SdlFast_IfAirSysIgSys                                         */
/*   4 / CoFan_SdlMid_CmdDiagCoFanIf                                          */
/*   5 / ISCAN_EveRxn7F2_If                                                   */
/*   6 / Sync_EveRTSt_IfAirSysIgSys                                           */
/*   7 / Sync_EveTDC_IfAirSysIgSys                                            */
/*   8 / Sync_EveCkSnOn_IfAirSysIgSys                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
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
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_StopStrtEng_023_MSEIf                                   */
/* !Description :  Evènement d'initialisation de StopStrtEng                  */
/* !Number      :  SCH8.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInterfacCstrIf();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_StopStrtEng_023_MSEIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_StopStrtEng_023_MSEIf(void)
{
   IFAIRSYSIGSYS_vidInterfacCstrIf();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_MngServoIf                                      */
/* !Description :  Moniteur de module d'interface                             */
/* !Number      :  SCH8.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidAFAThrIf();                             */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_MngServoIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_MngServoIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidAFAThrIf();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_SdlFast_IfAirSysIgSys                               */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH8.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInjCtlIf2();                            */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_SdlFast_IfAirSysIgSys                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_SdlFast_IfAirSysIgSys(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidInjCtlIf2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlMid_CmdDiagCoFanIf                                */
/* !Description :  Moniteur moyen de la fonction CoFan                        */
/* !Number      :  SCH8.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidCmdCoFan();                             */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlMid_CmdDiagCoFanIf                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlMid_CmdDiagCoFanIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidCmdCoFan();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISCAN_EveRxn7F2_If                                         */
/* !Description :  Evènement reception trame 7F2                              */
/* !Number      :  SCH8.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidIntfacIsCanIf17();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ISCAN_EveRxn7F2_If                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISCAN_EveRxn7F2_If(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidIntfacIsCanIf17();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRTSt_IfAirSysIgSys                                 */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH8.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidAFAInit();                              */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRTSt_IfAirSysIgSys                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRTSt_IfAirSysIgSys(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidAFAInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_IfAirSysIgSys                                  */
/* !Description :  Interruption PMH                                           */
/* !Number      :  SCH8.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidAFASyncIf();                            */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_IfAirSysIgSys                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_IfAirSysIgSys(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidAFASyncIf();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOn_IfAirSysIgSys                               */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH8.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidAFASyncIf();                            */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOn_IfAirSysIgSys                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOn_IfAirSysIgSys(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidAFASyncIf();
   }
}
/*-------------------------------- end of file -------------------------------*/