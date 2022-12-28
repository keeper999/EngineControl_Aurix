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
/* !File            : IFAIRSYSIGSYS_SCH17.C                                   */
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
/*   1 / Can_EveRxn34D_FHCanF34DAVIf                                          */
/*   2 / Can_EveRxn7F2_FHCanF7F2AVIf                                          */
/*   3 / Lin_EveRst_IsLinIf                                                   */
/*   4 / RE_StopStrtEm_004_TEVIf                                              */
/*   5 / RE_AdvMaxT_002_DREIf                                                 */
/*   6 / KnkTreat_EveRbl_KnkMgrCorRblIf                                       */
/*   7 / Can_EveRxn495_FHCanF495If                                            */
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
/* !Function    :  Can_EveRxn34D_FHCanF34DAVIf                                */
/* !Description :  Evénement d'interface (réception de trame 34Dh).           */
/* !Number      :  SCH17.1                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutN3F34DPM1413();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn34D_FHCanF34DAVIf                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn34D_FHCanF34DAVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutN3F34DPM1413();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn7F2_FHCanF7F2AVIf                                */
/* !Description :  Evénement de réception de la trame 7F2h.                   */
/* !Number      :  SCH17.2                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutFHCanF7F2AV();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn7F2_FHCanF7F2AVIf                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn7F2_FHCanF7F2AVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutFHCanF7F2AV();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Lin_EveRst_IsLinIf                                         */
/* !Description :  Evènement reset.                                           */
/* !Number      :  SCH17.3                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInterfISLin();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Lin_EveRst_IsLinIf                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Lin_EveRst_IsLinIf(void)
{
   IFAIRSYSIGSYS_vidInterfISLin();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_StopStrtEm_004_TEVIf                                    */
/* !Description :  Scheduler du module StopStrtEm .                           */
/* !Number      :  SCH17.4                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_bStaReq();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_StopStrtEm_004_TEVIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_StopStrtEm_004_TEVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutput_bStaReq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_AdvMaxT_002_DREIf                                       */
/* !Description :  Interruption PMH.                                          */
/* !Number      :  SCH17.5                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutMaxPrevAdpCy();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_AdvMaxT_002_DREIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_AdvMaxT_002_DREIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutMaxPrevAdpCy();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRbl_KnkMgrCorRblIf                             */
/* !Description :  Tache rumble.                                              */
/* !Number      :  SCH17.6                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutInjCutOffPtl();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRbl_KnkMgrCorRblIf                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRbl_KnkMgrCorRblIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutInjCutOffPtl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn495_FHCanF495If                                  */
/* !Description :  Evénement de réception de la trame 495h.                   */
/* !Number      :  SCH17.7                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutEngStopAuth();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn495_FHCanF495If                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn495_FHCanF495If(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutEngStopAuth();
   }
}
/*-------------------------------- end of file -------------------------------*/