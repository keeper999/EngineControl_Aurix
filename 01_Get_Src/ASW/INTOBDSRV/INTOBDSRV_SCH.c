/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INTOBDSRV                                               */
/* !Description     : INTOBDSRV component                                     */
/*                                                                            */
/* !Module          : INTOBDSRV                                               */
/* !Description     : Définition des PID supportés pour le diagnostic OBD et  */
/*                    les services constructeurs                              */
/*                                                                            */
/* !File            : INTOBDSRV_SCH.C                                         */
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
/*   1 / Srv_EveRst_ObdSrvPid                                                 */
/*   2 / Srv_SdlMid_ObdSrvPid                                                 */
/*   3 / Srv_SdlFast_ObdSrvPid                                                */
/*   4 / Srv_Eve14TDC_ObdSrvPid                                               */
/*   5 / Srv_EveTDC_ObdSrvPid                                                 */
/*   6 / Srv_EveBDC_ObdSrvPid                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 05149 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#065271                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/INTOBDSRV/INTOBDSRV_SCH.$*/
/* $Revision::   1.3      $$Author::   pbakabad       $$Date::   Mar 14 2013 $*/
/* $Author::   pbakabad                               $$Date::   Mar 14 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "INTOBDSRV.h"
#include "INTOBDSRV_L.h"
#include "INTOBDSRV_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRst_ObdSrvPid                                       */
/* !Description :  Evénement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05149_001.01                                     */
/*                 VEMS_E_11_05149_002.01                                     */
/*                 VEMS_E_11_05149_003.01                                     */
/*                 VEMS_E_11_05149_004.01                                     */
/*                 VEMS_E_11_05149_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTOBDSRV_vidIni_PID4F();                                */
/*  extf argret void INTOBDSRV_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : INTOBDSRV_vidEntryInit                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRst_ObdSrvPid(void)
{
   INTOBDSRV_vidIni_PID4F();
   INTOBDSRV_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlMid_ObdSrvPid                                       */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05149_001.01                                     */
/*                 VEMS_E_11_05149_002.01                                     */
/*                 VEMS_E_11_05149_003.01                                     */
/*                 VEMS_E_11_05149_004.01                                     */
/*                 VEMS_E_11_05149_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTOBDSRV_vidMid_Pid();                                  */
/*  extf argret void INTOBDSRV_vid14PMH_Pid();                                */
/*  extf argret void INTOBDSRV_vidPMH_Pid();                                  */
/*  extf argret void INTOBDSRV_vidPMB_PID();                                  */
/*  input uint8 INTOBDSRV_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_SdlMid_ObdSrvPid                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlMid_ObdSrvPid(void)
{
   if (INTOBDSRV_u8Inhib != 0x5A)
   {
      INTOBDSRV_vidMid_Pid();
      INTOBDSRV_vid14PMH_Pid();
      INTOBDSRV_vidPMH_Pid();
      INTOBDSRV_vidPMB_PID();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlFast_ObdSrvPid                                      */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05149_001.01                                     */
/*                 VEMS_E_11_05149_002.01                                     */
/*                 VEMS_E_11_05149_003.01                                     */
/*                 VEMS_E_11_05149_004.01                                     */
/*                 VEMS_E_11_05149_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTOBDSRV_vidFast_Pid();                                 */
/*  input uint8 INTOBDSRV_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_SdlFast_ObdSrvPid                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlFast_ObdSrvPid(void)
{
   if (INTOBDSRV_u8Inhib != 0x5A)
   {
      INTOBDSRV_vidFast_Pid();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_Eve14TDC_ObdSrvPid                                     */
/* !Description :  Evénement d'appel de tâche "quart de PMH" du CMM           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05149_001.01                                     */
/*                 VEMS_E_11_05149_002.01                                     */
/*                 VEMS_E_11_05149_003.01                                     */
/*                 VEMS_E_11_05149_004.01                                     */
/*                 VEMS_E_11_05149_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTOBDSRV_vid14PMH_Pid();                                */
/*  input uint8 INTOBDSRV_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_Eve14TDC_ObdSrvPid                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_Eve14TDC_ObdSrvPid(void)
{
   if (INTOBDSRV_u8Inhib != 0x5A)
   {
      INTOBDSRV_vid14PMH_Pid();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveTDC_ObdSrvPid                                       */
/* !Description :  Evénement point mort haut                                  */
/* !Number      :  SCH.5                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05149_001.01                                     */
/*                 VEMS_E_11_05149_002.01                                     */
/*                 VEMS_E_11_05149_003.01                                     */
/*                 VEMS_E_11_05149_004.01                                     */
/*                 VEMS_E_11_05149_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTOBDSRV_vidPMH_Pid();                                  */
/*  input uint8 INTOBDSRV_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveTDC_ObdSrvPid                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveTDC_ObdSrvPid(void)
{
   if (INTOBDSRV_u8Inhib != 0x5A)
   {
      INTOBDSRV_vidPMH_Pid();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveBDC_ObdSrvPid                                       */
/* !Description :  Evénement Point mort bas                                   */
/* !Number      :  SCH.6                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_05149_001.01                                     */
/*                 VEMS_E_11_05149_002.01                                     */
/*                 VEMS_E_11_05149_003.01                                     */
/*                 VEMS_E_11_05149_004.01                                     */
/*                 VEMS_E_11_05149_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTOBDSRV_vidPMB_PID();                                  */
/*  input uint8 INTOBDSRV_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveBDC_ObdSrvPid                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveBDC_ObdSrvPid(void)
{
   if (INTOBDSRV_u8Inhib != 0x5A)
   {
      INTOBDSRV_vidPMB_PID();
   }
}
/*------------------------------- end of file --------------------------------*/