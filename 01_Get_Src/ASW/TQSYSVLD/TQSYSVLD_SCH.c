/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSYSVLD                                                */
/* !Description     : TQSYSVLD component.                                     */
/*                                                                            */
/* !Module          : TQSYSVLD                                                */
/* !Description     : VALIDITE DES INFORMATIONS COUPLE.                       */
/*                                                                            */
/* !File            : TQSYSVLD_SCH.C                                          */
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
/*   1 / TqSys_EveRst_TqSysVld                                                */
/*   2 / TqSys_SdlFast_TqSysVld                                               */
/*   3 / TqSys_EveBDC_TqSysVld                                                */
/*                                                                            */
/* !Reference   : V02 NT 09 04105 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/TQSYSVLD/TQSYSVLD_SCH.C_v         $*/
/* $Revision::   1.1      $$Author::   pcabariq       $$Date::   15 Dec 2009 $*/
/* $Author::   pcabariq                               $$Date::   15 Dec 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQSYSVLD.h"
#include "TQSYSVLD_L.h"
#include "TQSYSVLD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveRst_TqSysVld                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSVLD_vidInit();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_EveRst_TqSysVld                                          */
/* !Trigger  : TqSys_EveRst_TqSysVld                                          */
/*                                                                            */
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveRst_TqSysVld(void)
{
   TQSYSVLD_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_SdlFast_TqSysVld                                     */
/* !Description :  Moniteur rapide pour la fonction TqSys                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSVLD_vidDiagMisfire();                               */
/*  extf argret void TQSYSVLD_vidNoWght();                                    */
/*  extf argret void TQSYSVLD_vidTqEM();                                      */
/*  extf argret void TQSYSVLD_vidStDiagESPReq();                              */
/*  input uint8 TQSYSVLD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_SdlFast_TqSysVld                                         */
/* !Trigger  : TqSys_SdlFast_TqSysVld                                         */
/*                                                                            */
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_SdlFast_TqSysVld(void)
{
   if (TQSYSVLD_u8Inhib != 0x5A)
   {
      TQSYSVLD_vidDiagMisfire();
      TQSYSVLD_vidNoWght();
      TQSYSVLD_vidTqEM();
      TQSYSVLD_vidStDiagESPReq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveBDC_TqSysVld                                      */
/* !Description :  Interruption PMB                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSVLD_vidTqCkEngReal();                               */
/*  input uint8 TQSYSVLD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_EveBDC_TqSysVld                                          */
/* !Trigger  : TqSys_EveBDC_TqSysVld                                          */
/*                                                                            */
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveBDC_TqSysVld(void)
{
   if (TQSYSVLD_u8Inhib != 0x5A)
   {
      TQSYSVLD_vidTqCkEngReal();
   }
}

/*------------------------------- end of file --------------------------------*/