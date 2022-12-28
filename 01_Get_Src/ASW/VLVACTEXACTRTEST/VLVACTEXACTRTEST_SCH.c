/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXACTRTEST                                        */
/* !Description     : VLVACTEXACTRTEST component                              */
/*                                                                            */
/* !Module          : VLVACTEXACTRTEST                                        */
/* !Description     : TEST ACTIONNEUR DE LA VVT ECHAPPEMENT :GENERATION DE LA */
/*                    CONSIGNE ET CALCUL DES CRITERES DE L’ASSERVISSEMENT     */
/*                                                                            */
/* !File            : VLVACTEXACTRTEST_SCH.C                                  */
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
/*   1 / VlvAct_SdlFast_ExActrTest                                            */
/*   2 / VlvAct_EveRst_ExActrTest                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 05825 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXACTRTEST/VLVACT$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   12 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   12 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTEXACTRTEST.h"
#include "VLVACTEXACTRTEST_L.h"
#include "VLVACTEXACTRTEST_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExActrTest                                  */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05825_004.01                                     */
/*                 VEMS_R_09_05825_005.01                                     */
/*                 VEMS_R_09_05825_006.01                                     */
/*                 VEMS_R_09_05825_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACTRTEST_vidCalcSdlFast();                       */
/*  input uint8 VLVACTEXACTRTEST_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExActrTest                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExActrTest(void)
{
   if (VLVACTEXACTRTEST_u8Inhib != 0x5A)
   {
      VLVACTEXACTRTEST_vidCalcSdlFast();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_ExActrTest                                   */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05825_004.01                                     */
/*                 VEMS_R_09_05825_005.01                                     */
/*                 VEMS_R_09_05825_006.01                                     */
/*                 VEMS_R_09_05825_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACTRTEST_vidInitializati();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_ExActrTest                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_ExActrTest(void)
{
   VLVACTEXACTRTEST_vidInitializati();
}
/*------------------------------- end of file --------------------------------*/