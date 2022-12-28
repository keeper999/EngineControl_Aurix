/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDGAR                                                   */
/* !Description     : This is the default manager component                   */
/*                                                                            */
/* !Module          : StatusOfDTC                                             */
/* !Description     : StatusOfDTC module                                      */
/*                                                                            */
/* !File            : STATUSOFDTC_SCH.C                                       */
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
/*   1 / GD_EveRst_StatusOfDTC                                                */
/*   2 / GD_EveRstDft_StatusOfDTC                                             */
/*   3 / GD_RstDftCal                                                         */
/*   4 / GD_EveRstDftObd_StatusOfDTC                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5446103 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/STATUSOFDTC/StatusOfDTC_SCH.c$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "StatusOfDTC.h"
#include "StatusOfDTC_L.h"
#include "StatusOfDTC_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_StatusOfDTC                                      */
/* !Description :  ECU Reset Event                                            */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  PTS_R_5446103_001.01                                       */
/*                 PTS_R_5446103_002.01                                       */
/*                 PTS_R_5446103_003.01                                       */
/*                 PTS_R_5446103_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_EveRst_StatusOfDTC();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_StatusOfDTC                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_StatusOfDTC(void)
{
   SODTC_EveRst_StatusOfDTC();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDft_StatusOfDTC                                   */
/* !Description :  After-sale tool request failures clear                     */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  PTS_R_5446103_001.01                                       */
/*                 PTS_R_5446103_002.01                                       */
/*                 PTS_R_5446103_003.01                                       */
/*                 PTS_R_5446103_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_EveRstDft_StatusOfDTC();                           */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDft_StatusOfDTC                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDft_StatusOfDTC(void)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      SODTC_EveRstDft_StatusOfDTC();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_RstDftCal                                               */
/* !Description :  Manual clear failure request                               */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  PTS_R_5446103_001.01                                       */
/*                 PTS_R_5446103_002.01                                       */
/*                 PTS_R_5446103_003.01                                       */
/*                 PTS_R_5446103_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_EveRstDft_StatusOfDTC();                           */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_RstDftCal                                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_RstDftCal(void)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      SODTC_EveRstDft_StatusOfDTC();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDftObd_StatusOfDTC                                */
/* !Description :  Scan-Tool request OBD failures clear                       */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  PTS_R_5446103_001.01                                       */
/*                 PTS_R_5446103_002.01                                       */
/*                 PTS_R_5446103_003.01                                       */
/*                 PTS_R_5446103_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_EveRstDftObd_StatusOfDTC();                        */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDftObd_StatusOfDTC                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDftObd_StatusOfDTC(void)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      SODTC_EveRstDftObd_StatusOfDTC();
   }
}
/*------------------------------- end of file --------------------------------*/