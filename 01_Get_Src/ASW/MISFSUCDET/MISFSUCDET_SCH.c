/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFSUCDET                                              */
/* !Description     : MISFSUCDET Component                                    */
/*                                                                            */
/* !Module          : MISFSUCDET                                              */
/* !Description     : ALGORITHMES DE DÉTECTION DE 2 MISFIRES SUCCESSIFS       */
/*                                                                            */
/* !File            : MISFSUCDET_SCH.C                                        */
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
/*   1 / MISFSUCDET_vidEntryInit                                              */
/*   2 / Misf_EveMisf_MisfSucDet                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5198660 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFSUCDET/MISFSUCDET_SCH.C_v$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Jan 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MISFSUCDET.h"
#include "MISFSUCDET_L.h"
#include "MISFSUCDET_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidEntryInit                                    */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidEntryInit(void)
{
   MISFSUCDET_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfSucDet                                    */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidSucMisfDetectMain();                       */
/*  input uint8 MISFSUCDET_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfSucDet(void)
{
   if (MISFSUCDET_u8Inhib != 0x5A)
   {
      MISFSUCDET_vidSucMisfDetectMain();
   }
}
/*------------------------------- end of file --------------------------------*/