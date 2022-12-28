/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRGENDEN                                              */
/* !Description     : IUPRGENDEN Component                                    */
/*                                                                            */
/* !Module          : IUPRGENDEN                                              */
/* !Description     : IUPRGENDENORISATION DES PARAMETRES DEFAUTS              */
/*                                                                            */
/* !File            : IuprGenDen_sch.c                                        */
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
/*   1 / GD_EveRst_IuprGenDen                                                 */
/*   2 / IUPRGENDEN_vidMngEveSdlSlow                                          */
/*   3 / IUPRGENDEN_vidMngEveSdlFast                                          */
/*   4 / IUPRGENDEN_vidMngEveGlbDCStrt                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5497341 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRGENDEN/IuprGenDen_sch.c_v$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   17 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "IUPRGENDEN.h"
#include "IUPRGENDEN_L.h"
#include "IUPRGENDEN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_IuprGenDen                                       */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_03253_001.02                                     */
/*                 VEMS_R_11_03253_002.01                                     */
/*                 PTS_R_5497341_001.01                                       */
/*                 PTS_R_5497341_002.01                                       */
/*                 PTS_R_5497341_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRGENDEN_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_IuprGenDen                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_IuprGenDen(void)
{
   IUPRGENDEN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidMngEveSdlSlow                                */
/* !Description :  Evenement lent                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_03253_001.02                                     */
/*                 VEMS_R_11_03253_002.01                                     */
/*                 PTS_R_5497341_001.01                                       */
/*                 PTS_R_5497341_002.01                                       */
/*                 PTS_R_5497341_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRGENDEN_vidF03_GenDen();                              */
/*  input uint8 IUPRGENDEN_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IUPRGENDEN_vidMngEveSdlSlow                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidMngEveSdlSlow(void)
{
   if(IUPRGENDEN_u8Inhib != 0x5A)
   {
      IUPRGENDEN_vidF03_GenDen();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidMngEveSdlFast                                */
/* !Description :  Evenement rapide                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_03253_001.02                                     */
/*                 VEMS_R_11_03253_002.01                                     */
/*                 PTS_R_5497341_001.01                                       */
/*                 PTS_R_5497341_002.01                                       */
/*                 PTS_R_5497341_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRGENDEN_vidF02_bObdStrt();                            */
/*  input uint8 IUPRGENDEN_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IUPRGENDEN_vidMngEveSdlFast                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidMngEveSdlFast(void)
{
   if(IUPRGENDEN_u8Inhib != 0x5A)
   {
      IUPRGENDEN_vidF02_bObdStrt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidMngEveGlbDCStrt                              */
/* !Description :  Evenement Global DC Start                                  */
/* !Number      :  SCH.4                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_03253_001.02                                     */
/*                 VEMS_R_11_03253_002.01                                     */
/*                 PTS_R_5497341_001.01                                       */
/*                 PTS_R_5497341_002.01                                       */
/*                 PTS_R_5497341_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRGENDEN_vidF04_ReInitPrm();                           */
/*  input uint8 IUPRGENDEN_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IUPRGENDEN_vidMngEveGlbDCStrt                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidMngEveGlbDCStrt(void)
{
   if(IUPRGENDEN_u8Inhib != 0x5A)
   {
      IUPRGENDEN_vidF04_ReInitPrm();
   }
}
/*------------------------------- end of file --------------------------------*/