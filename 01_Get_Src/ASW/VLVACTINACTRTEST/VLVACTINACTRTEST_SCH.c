/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINACTRTEST                                        */
/* !Description     : VLVACTINACTRTEST component                              */
/*                                                                            */
/* !Module          : VLVACTINACTRTEST                                        */
/* !Description     : TEST ACTIONNEUR DE LA VVT ADMISSION :GENERATION DE LA   */
/*                    CONSIGNE ET CALCUL DES CRITERES DE L’ASSERVISSEMENT     */
/*                                                                            */
/* !File            : VLVACTINACTRTEST_SCH.C                                  */
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
/*   1 / VlvAct_SdlFast_InActrTest                                            */
/*   2 / VlvAct_EveRst_InActrTest                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 05822 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINACTRTEST/VLVACT$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   12 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   12 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINACTRTEST.h"
#include "VLVACTINACTRTEST_L.h"
#include "VLVACTINACTRTEST_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InActrTest                                  */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05822_004.01                                     */
/*                 VEMS_R_09_05822_005.01                                     */
/*                 VEMS_R_09_05822_006.01                                     */
/*                 VEMS_R_09_05822_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACTRTEST_vidCalcSdlFast();                       */
/*  input uint8 VLVACTINACTRTEST_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InActrTest                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InActrTest(void)
{
   if (VLVACTINACTRTEST_u8Inhib != 0x5A)
   {
      VLVACTINACTRTEST_vidCalcSdlFast();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_InActrTest                                   */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05822_004.01                                     */
/*                 VEMS_R_09_05822_005.01                                     */
/*                 VEMS_R_09_05822_006.01                                     */
/*                 VEMS_R_09_05822_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACTRTEST_vidInitializati();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_InActrTest                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_InActrTest(void)
{
   VLVACTINACTRTEST_vidInitializati();
}
/*------------------------------- end of file --------------------------------*/