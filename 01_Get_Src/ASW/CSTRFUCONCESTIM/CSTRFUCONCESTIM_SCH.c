/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRFUCONCESTIM                                         */
/* !Description     : CSTRFUCONCESTIM Component.                              */
/*                                                                            */
/* !Module          : CSTRFUCONCESTIM                                         */
/* !Description     : ESTIMATEUR DE LA CONCENTRATION EN VAPEURS D_ESSENCE DES */
/*                    GAZ ISSUS DE LA PURGE CANISTER                          */
/*                                                                            */
/* !File            : CSTRFUCONCESTIM_SCH.C                                   */
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
/*   1 / Cstr_EveCrTR_FuConcEstim                                             */
/*   2 / Cstr_EveRst_FuConcEstim                                              */
/*   3 / Cstr_SdlFast_FuConcEstim                                             */
/*   4 / Cstr_SdlSlow_FuConcEstim                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5066966 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CSTR/CSTRFUCONCESTIM/CSTRFUCONCE$*/
/* $Revision::   1.11     $$Author::   etsasson       $$Date::   28 Apr 2014 $*/
/* $Author::   etsasson                               $$Date::   28 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CSTRFUCONCESTIM.h"
#include "CSTRFUCONCESTIM_L.h"
#include "CSTRFUCONCESTIM_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveCrTR_FuConcEstim                                   */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_E_09_01206_005.02                                     */
/*                 VEMS_E_09_01206_006.01                                     */
/*                 VEMS_E_09_01206_007.01                                     */
/*                 VEMS_R_09_01206_001.02                                     */
/*                 VEMS_R_09_01206_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRFUCONCESTIM_vidCrk2RunIni();                         */
/*  extf argret void CSTRFUCONCESTIM_vidOutIf();                              */
/*  input uint8 CSTRFUCONCESTIM_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveCrTR_FuConcEstim                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveCrTR_FuConcEstim(void)
{
   if (CSTRFUCONCESTIM_u8Inhib != 0x5A)
   {
      CSTRFUCONCESTIM_vidCrk2RunIni();
      CSTRFUCONCESTIM_vidOutIf();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveRst_FuConcEstim                                    */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_E_09_01206_005.02                                     */
/*                 VEMS_E_09_01206_006.01                                     */
/*                 VEMS_E_09_01206_007.01                                     */
/*                 VEMS_R_09_01206_001.02                                     */
/*                 VEMS_R_09_01206_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRFUCONCESTIM_vidInitialization();                     */
/*  extf argret void CSTRFUCONCESTIM_vidOutIf();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveRst_FuConcEstim                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveRst_FuConcEstim(void)
{
   CSTRFUCONCESTIM_vidInitialization();
   CSTRFUCONCESTIM_vidOutIf();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlFast_FuConcEstim                                   */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_E_09_01206_005.02                                     */
/*                 VEMS_E_09_01206_006.01                                     */
/*                 VEMS_E_09_01206_007.01                                     */
/*                 VEMS_R_09_01206_001.02                                     */
/*                 VEMS_R_09_01206_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRFUCONCESTIM_vidEstimMng();                           */
/*  extf argret void CSTRFUCONCESTIM_vidFuEstim();                            */
/*  extf argret void CSTRFUCONCESTIM_vidCllConc();                            */
/*  extf argret void CSTRFUCONCESTIM_vidOutIf();                              */
/*  input uint8 CSTRFUCONCESTIM_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlFast_FuConcEstim                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlFast_FuConcEstim(void)
{
   if (CSTRFUCONCESTIM_u8Inhib != 0x5A)
   {
      CSTRFUCONCESTIM_vidEstimMng();
      CSTRFUCONCESTIM_vidFuEstim();
      CSTRFUCONCESTIM_vidCllConc();
      CSTRFUCONCESTIM_vidOutIf();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlSlow_FuConcEstim                                   */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH.4                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_E_09_01206_005.02                                     */
/*                 VEMS_E_09_01206_006.01                                     */
/*                 VEMS_E_09_01206_007.01                                     */
/*                 VEMS_R_09_01206_001.02                                     */
/*                 VEMS_R_09_01206_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRFUCONCESTIM_vidStallTi();                            */
/*  extf argret void CSTRFUCONCESTIM_vidEstimMng();                           */
/*  extf argret void CSTRFUCONCESTIM_vidOplConc();                            */
/*  extf argret void CSTRFUCONCESTIM_vidOutIf();                              */
/*  input uint8 CSTRFUCONCESTIM_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlSlow_FuConcEstim                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlSlow_FuConcEstim(void)
{
   if (CSTRFUCONCESTIM_u8Inhib != 0x5A)
   {
      CSTRFUCONCESTIM_vidStallTi();
      CSTRFUCONCESTIM_vidEstimMng();
      CSTRFUCONCESTIM_vidOplConc();
      CSTRFUCONCESTIM_vidOutIf();
   }
}
/*------------------------------- end of file --------------------------------*/