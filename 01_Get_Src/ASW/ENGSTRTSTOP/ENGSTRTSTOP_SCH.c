/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTRTSTOP                                             */
/* !Description     : ENGSTRTSTOP Component                                   */
/*                                                                            */
/* !Module          : ENGSTRTSTOP                                             */
/* !Description     : DEMARRAGE ET ARRET MOTEUR                               */
/*                                                                            */
/* !File            : ENGSTRTSTOP_SCH.C                                       */
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
/*   1 / EngSt_EveRst_EngStrtStop                                             */
/*   2 / EngSt_SdlFast_EngStrtStop                                            */
/*   3 / EngSt_EveKOn_EngStrtStop                                             */
/*   4 / EngSt_EveStTR_EngStrtStop                                            */
/*   5 / EngSt_EveCkSnOn_EngStrtStop                                          */
/*   6 / EngSt_EveKOf_EngStrtStop                                             */
/*   7 / EngSt_EveRxn552_EngStrtStop                                          */
/*   8 / EngSt_EveRTSt_EngStrtStop                                            */
/*   9 / EngSt_SdlSlow_EngStrtStop                                            */
/*   10 / EngSt_EveCkOn_EngStrtStop                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 05182 / 14                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ENGSTRTSTOP/ENGSTRTSTOP_SCH.c_v   $*/
/* $Revision::   1.15     $$Author::   achebino       $$Date::   24 Aug 2012 $*/
/* $Author::   achebino                               $$Date::   24 Aug 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"ENGSTRTSTOP.h"
#include"ENGSTRTSTOP_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_EngStrtStop                                   */
/* !Description :  Evènement RESET du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidInitOutput();                             */
/*  extf argret void ENGSTRTSTOP_vidInitialization();                         */
/*  extf argret void ENGSTRTSTOP_vidCmdCranking();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_EngStrtStop                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_EngStrtStop(void)
{
   ENGSTRTSTOP_vidInitOutput();
   ENGSTRTSTOP_vidInitialization();
   ENGSTRTSTOP_vidCmdCranking();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_EngStrtStop                                  */
/* !Description :  Moniteur rapide pour la fonction EngSt                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidEngStopCond();                            */
/*  extf argret void ENGSTRTSTOP_vidEngStateDmlCalc();                        */
/*  extf argret void ENGSTRTSTOP_vidCmdCranking();                            */
/*  extf argret void ENGSTRTSTOP_vidControlAutoInj();                         */
/*  extf argret void ENGSTRTSTOP_vidTransToCranking();                        */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_EngStrtStop                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidEngStopCond();
      ENGSTRTSTOP_vidEngStateDmlCalc();
      ENGSTRTSTOP_vidCmdCranking();
      ENGSTRTSTOP_vidControlAutoInj();
      ENGSTRTSTOP_vidTransToCranking();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveKOn_EngStrtStop                                   */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidInitAutoInjStlCrk();                      */
/*  extf argret void ENGSTRTSTOP_vidKeyOffOn();                               */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveKOn_EngStrtStop                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveKOn_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidInitAutoInjStlCrk();
      ENGSTRTSTOP_vidKeyOffOn();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveStTR_EngStrtStop                                  */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidInitAutoInjStlCrk();                      */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveStTR_EngStrtStop                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveStTR_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidInitAutoInjStlCrk();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveCkSnOn_EngStrtStop                                */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise.                                        */
/* !Number      :  SCH.5                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidTransEngine();                            */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveCkSnOn_EngStrtStop                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveCkSnOn_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidTransEngine();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveKOf_EngStrtStop                                   */
/* !Description :  Evénement associé au passage de clef ON à clef OFF.        */
/* !Number      :  SCH.6                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidKeyOnOff();                               */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveKOf_EngStrtStop                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveKOf_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidKeyOnOff();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRxn552_EngStrtStop                                */
/* !Description :  Evènement correspondent à la reception de la trame 552h .  */
/* !Number      :  SCH.7                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidComputeCrankRetry();                      */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRxn552_EngStrtStop                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRxn552_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidComputeCrankRetry();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRTSt_EngStrtStop                                  */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.8                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidStallRunning();                           */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRTSt_EngStrtStop                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRTSt_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidStallRunning();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlSlow_EngStrtStop                                  */
/* !Description :  Moniteur lent pour la fonction EngSt.                      */
/* !Number      :  SCH.9                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidFirstCrank();                             */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlSlow_EngStrtStop                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlSlow_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidFirstCrank();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveCkOn_EngStrtStop                                  */
/* !Description :  Evènement Détection rotation moteur                        */
/* !Number      :  SCH.10                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTRTSTOP_vidEveStallRunning();                        */
/*  input uint8 ENGSTRTSTOP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveCkOn_EngStrtStop                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveCkOn_EngStrtStop(void)
{
   if (ENGSTRTSTOP_u8Inhib != 0x5A)
   {
      ENGSTRTSTOP_vidEveStallRunning();
   }
}
/*----------------------------- end of file ----------------------------------*/