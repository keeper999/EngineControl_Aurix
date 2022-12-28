/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJACTEST                                               */
/* !Description     : INJACTEST Component                                     */
/*                                                                            */
/* !Module          : INJACTEST                                               */
/* !Description     : TESTS ACTIONNEURS DES INJECTEURS                        */
/*                                                                            */
/* !File            : INJACTEST_SCH.C                                         */
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
/*   1 / Inj_EveRst_ActrTstInj                                                */
/*   2 / Inj_SdlFast_ActrTstInj                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5135792 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065909                                         */
/* !OtherRefs   : VEMS V02 ECU#065504                                         */
/* !OtherRefs   : VEMS V02 ECU#065669                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJACTEST/INJACTEST_SCH.C_$*/
/* $Revision::   1.4      $$Author::   HHAMLAOU       $$Date::   06 Sep 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   06 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "std_types.h"
#include "INJACTEST.h"
#include "INJACTEST_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveRst_ActrTstInj                                      */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_11_05410_001.01                                     */
/*                 VEMS_E_11_05410_002.01                                     */
/*                 VEMS_E_11_05410_003.01                                     */
/*                 VEMS_E_11_05410_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJACTEST_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveRst_ActrTstInj                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveRst_ActrTstInj(void)
{
   INJACTEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_SdlFast_ActrTstInj                                     */
/* !Description :  Moniteur rapide de la fonction Inj                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_E_11_05410_001.01                                     */
/*                 VEMS_E_11_05410_002.01                                     */
/*                 VEMS_E_11_05410_003.01                                     */
/*                 VEMS_E_11_05410_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJACTEST_vidTimeToInj();                                */
/*  extf argret void INJACTEST_vidEntryMode();                                */
/*  extf argret void INJACTEST_vidTestMode();                                 */
/*  extf argret void INJACTEST_vidTestEnd();                                  */
/*  extf argret void INJACTEST_vidTestFrLstRun();                             */
/*  input uint8 INJACTEST_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_SdlFast_ActrTstInj                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_SdlFast_ActrTstInj(void)
{
   if (INJACTEST_u8Inhib != 0x5A)
   {
      INJACTEST_vidTimeToInj();
      INJACTEST_vidEntryMode();
      INJACTEST_vidTestMode();
      INJACTEST_vidTestEnd();
      INJACTEST_vidTestFrLstRun();
   }
}

/*----------------------------- end of file ----------------------------------*/