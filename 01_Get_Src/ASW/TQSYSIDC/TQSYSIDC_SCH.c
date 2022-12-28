/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSYSIDC                                                */
/* !Description     : TQSYSIDC Component.                                     */
/*                                                                            */
/* !Module          : TQSYSIDC                                                */
/* !Description     : GESTION DES CONSIGNES DE COUPLE .                       */
/*                                                                            */
/* !File            : TQSYSIDC_SCH.C                                          */
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
/*   1 / TqSys_EveRst_TqSysIdc                                                */
/*   2 / TqSys_SdlFast_TqSysIdc                                               */
/*   3 / TqSys_EveTDC_TqSysIdc                                                */
/*                                                                            */
/* !Reference   : V02 NT 08 05347 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "TQSYSIDC.h"
#include "TQSYSIDC_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveRst_TqSysIdc                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSIDC_vidTqSysSlow();                                 */
/*  extf argret void TQSYSIDC_vidTqSysFast();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger : TqSys_EveRst_TqSysIdc                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveRst_TqSysIdc(void)
{
   TQSYSIDC_vidTqSysSlow();
   TQSYSIDC_vidTqSysFast();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_SdlFast_TqSysIdc                                     */
/* !Description :  Moniteur rapide pour la fonction TqSys                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSIDC_vidTqSysSlow();                                 */
/*  input uint8 TQSYSIDC_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger : TqSys_SdlFast_TqSysIdc                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_SdlFast_TqSysIdc(void)
{
   if (TQSYSIDC_u8Inhib != 0x5A)
   {
      TQSYSIDC_vidTqSysSlow();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveTDC_TqSysIdc                                      */
/* !Description :  Interruption PMH                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSIDC_vidTqSysFast();                                 */
/*  input uint8 TQSYSIDC_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger : TqSys_EveTDC_TqSysIdc                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveTDC_TqSysIdc(void)
{
   if (TQSYSIDC_u8Inhib != 0x5A)
   {
      TQSYSIDC_vidTqSysFast();
   }
}
/*----------------------------- end of file ----------------------------------*/