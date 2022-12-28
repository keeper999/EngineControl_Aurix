/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDIAGSTABCDN                                         */
/* !Description     : MISFDIAGSTABCDN component.                              */
/*                                                                            */
/* !Module          : MISFDIAGSTABCDN                                         */
/* !Description     : Conditions de stabilité pour diagnostic misfire         */
/*                                                                            */
/* !File            : MISFDIAGSTABCDN_SCH.C                                   */
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
/*   1 / Misf_EveRst_MisfDiagStabCdn                                          */
/*   2 / Misf_SdlMid_MisfDiagStabCdn                                          */
/*   3 / Misf_EveMisf_MisfDiagStabCdn                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5577717 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066973                                         */
/* !OtherRefs   : VEMS V02 ECU#068484                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDIAGSTABCDN/MISFDIAGSTABC$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   15 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   15 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MISFDIAGSTABCDN.h"
#include "MISFDIAGSTABCDN_L.h"
#include "MISFDIAGSTABCDN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRst_MisfDiagStabCdn                                */
/* !Description :  Evènement lié au reset du calculateur                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidInitEngineCnd();                      */
/*  extf argret void MISFDIAGSTABCDN_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveRst_MisfDiagStabCdn                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRst_MisfDiagStabCdn(void)
{
   MISFDIAGSTABCDN_vidInitEngineCnd();
   MISFDIAGSTABCDN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_SdlMid_MisfDiagStabCdn                                */
/* !Description :  Moniteur moyen pour la fonction misfire                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidDiagStabCdn();                        */
/*  input uint8 MISFDIAGSTABCDN_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_SdlMid_MisfDiagStabCdn                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_SdlMid_MisfDiagStabCdn(void)
{
   if (MISFDIAGSTABCDN_u8Inhib != 0x5A)
   {
      MISFDIAGSTABCDN_vidDiagStabCdn();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfDiagStabCdn                               */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire                        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidMisfIgAdvClcn();                      */
/*  extf argret void MISFDIAGSTABCDN_vidMisfdvStabChk();                      */
/*  extf argret void MISFDIAGSTABCDN_vidMisfStbCdLost();                      */
/*  input uint8 MISFDIAGSTABCDN_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfDiagStabCdn                                   */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfDiagStabCdn(void)
{
   if (MISFDIAGSTABCDN_u8Inhib != 0x5A)
   {
      MISFDIAGSTABCDN_vidMisfIgAdvClcn();
      MISFDIAGSTABCDN_vidMisfdvStabChk();
      MISFDIAGSTABCDN_vidMisfStbCdLost();
   }
}
/*------------------------------- end of file --------------------------------*/