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
/* !File            : IFAIRSYSIGSYS_SCH20.C                                   */
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
/*   1 / RE_ThMgt_001_MSEIf                                                   */
/*   2 / RE_ThMgt_002_TEVIf                                                   */
/*   3 / RE_TraBVx_028_TEVIf                                                  */
/*   4 / TqRes_Sdl10ms_tqAltResIf                                             */
/*   5 / IgLim_EveBDC_CritZoneIf                                              */
/*   6 / IgLim_EveCrTR_CritZoneIf                                             */
/*   7 / IgLim_EveRTCr_CritZoneIf                                             */
/*   8 / IgLim_EveRst_CritZoneIf                                              */
/*   9 / RE_TPM_001_MSEIf                                                     */
/*   10 / RE_TPM_008_TEVIf                                                    */
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
/* !Function    :  RE_ThMgt_001_MSEIf                                         */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH20.1                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutputThMgt();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_ThMgt_001_MSEIf                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_ThMgt_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutputThMgt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_ThMgt_002_TEVIf                                         */
/* !Description :  Moniteur 1s de la fonction TSC.                            */
/* !Number      :  SCH20.2                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutputThMgt();                          */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_ThMgt_002_TEVIf                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_ThMgt_002_TEVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutputThMgt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_TraBVx_028_TEVIf                                        */
/* !Description :  Evènement du module TraBVx .                               */
/* !Number      :  SCH20.3                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidrapEngaMeca349();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_TraBVx_028_TEVIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_TraBVx_028_TEVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidrapEngaMeca349();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqAltResIf                                   */
/* !Description :  Moniteur 10ms.                                             */
/* !Number      :  SCH20.4                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidTqRes();                                */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqRes_Sdl10ms_tqAltResIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqAltResIf(void)
{
   /*QAC Warning(2:4152): Name imposed by specification*/
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidTqRes();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveBDC_CritZoneIf                                    */
/* !Description :  Interruption PMB.                                          */
/* !Number      :  SCH20.5                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidKnk();                                  */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveBDC_CritZoneIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveBDC_CritZoneIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidKnk();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveCrTR_CritZoneIf                                   */
/* !Description :  Evénement CRANKING vers RUNNING.                           */
/* !Number      :  SCH20.6                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidKnk();                                  */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveCrTR_CritZoneIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveCrTR_CritZoneIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidKnk();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRTCr_CritZoneIf                                   */
/* !Description :  Evénement RUNNING vers CRANKING.                           */
/* !Number      :  SCH20.7                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidKnk();                                  */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveRTCr_CritZoneIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRTCr_CritZoneIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidKnk();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRst_CritZoneIf                                    */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH20.8                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidKnk();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgLim_EveRst_CritZoneIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRst_CritZoneIf(void)
{
   IFAIRSYSIGSYS_vidKnk();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_TPM_001_MSEIf                                           */
/* !Description :  evenement Reset.                                           */
/* !Number      :  SCH20.9                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidPhyM();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_TPM_001_MSEIf                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_TPM_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidPhyM();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_TPM_008_TEVIf                                           */
/* !Description :  Scheduler 100ms                                            */
/* !Number      :  SCH20.10                                                   */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidPhyM();                                 */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_TPM_008_TEVIf                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_TPM_008_TEVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidPhyM();
   }
}
/*-------------------------------- end of file -------------------------------*/