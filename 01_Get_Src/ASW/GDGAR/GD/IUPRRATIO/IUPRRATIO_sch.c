/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRRATIO                                               */
/* !Description     : IUPRRATIO Component                                     */
/*                                                                            */
/* !Module          : IUPRRATIO                                               */
/* !Description     : IUPRRATIO CALCUL DES RATIOS IUPR                        */
/*                                                                            */
/* !File            : IUPRRATIO_sch.c                                         */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / IUPRRATIO_vidMngEveSdlSlow                                           */
/*   2 / GD_EveRst_IuprRatio                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5338298 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRRATIO/IUPRRATIO_sch.c_v  $*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   24 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   24 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "IUPRRATIO.H"
#include "IUPRRATIO_L.h"
#include "IUPRRATIO_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRRATIO_vidMngEveSdlSlow                                 */
/* !Description :  Evenement lent                                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06318_001.01                                     */
/*                 VEMS_R_10_06318_002.01                                     */
/*                 VEMS_R_10_06318_003.02                                     */
/*                 VEMS_R_10_06318_004.01                                     */
/*                 VEMS_R_10_06318_005.01                                     */
/*                 VEMS_R_10_06318_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRRATIO_vidF02_CntNumDen();                            */
/*  input uint8 IUPRRATIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IUPRRATIO_vidMngEveSdlSlow                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRRATIO_vidMngEveSdlSlow(void)
{
   if (IUPRRATIO_u8Inhib != 0x5A)
   {
      IUPRRATIO_vidF02_CntNumDen();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_IuprRatio                                        */
/* !Description :  Evenement RESET.                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06318_001.01                                     */
/*                 VEMS_R_10_06318_002.01                                     */
/*                 VEMS_R_10_06318_003.02                                     */
/*                 VEMS_R_10_06318_004.01                                     */
/*                 VEMS_R_10_06318_005.01                                     */
/*                 VEMS_R_10_06318_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRRATIO_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_IuprRatio                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_IuprRatio(void)
{
   IUPRRATIO_vidInitOutput();
}

/* --------------------------------end of file------------------------------- */