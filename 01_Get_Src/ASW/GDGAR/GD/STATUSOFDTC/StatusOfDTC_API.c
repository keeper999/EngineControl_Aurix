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
/* !File            : STATUSOFDTC_API.C                                       */
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
/*   1 / StatusOfDtc_StGDU                                                    */
/*   2 / StatusOfDtc_StGOBD                                                   */
/*   3 / GD_CDThd                                                             */
/*   4 / GD_GlbDCStrt                                                         */
/*   5 / GD_DftClr                                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5446103 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/STATUSOFDTC/StatusOfDTC_API.c$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
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
/* !Function    :  StatusOfDtc_StGDU                                          */
/* !Description :  Event indicating a changing state for the considered single*/
/*                 failure                                                    */
/* !Number      :  API.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_StGDU(argin uint16 u16DftIdx);                     */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void StatusOfDtc_StGDU
(
   uint16 u16DftIdx
)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      if (u16DftIdx < GD_DFT_NB)
      {
         SODTC_StGDU(u16DftIdx);
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  StatusOfDtc_StGOBD                                         */
/* !Description :  Event indicating a changing OBD state for the considered   */
/*                 single failure                                             */
/* !Number      :  API.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_StGOBD(argin uint16 u16DftIdx);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void StatusOfDtc_StGOBD
(
   uint16 u16DftIDx
)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      if (u16DftIDx < GD_DFT_NB)
      {
         SODTC_StGOBD(u16DftIDx);
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
}/* mettre a jour STATUSOFDTC_macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_CDThd                                                   */
/* !Description :  The single failure detection counter has reached one of its*/
/*                 threshold                                                  */
/* !Number      :  API.3                                                      */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_CDThd(argin uint16 u16DftIdx);                     */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_CDThd
(
   uint16 u16DftIdx
)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      if (u16DftIdx < GD_DFT_NB)
      {
         SODTC_CDThd(u16DftIdx);
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
}/* mettre a jour STATUSOFDTC_macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_GlbDCStrt                                               */
/* !Description :  Start-up of a new Global Driving Cycle                     */
/* !Number      :  API.4                                                      */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_GlbDCStrt();                                       */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_GlbDCStrt(void)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      SODTC_GlbDCStrt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_DftClr                                                  */
/* !Description :  Update StatusOfDTC when the counter of WarmUpCycle is equal*/
/*                 to 0                                                       */
/* !Number      :  API.5                                                      */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SODTC_DftClr(argin uint16 u16DftIdx);                    */
/*  input uint8 StatusOfDTC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_DftClr
(
   uint16 u16DftIdx
)
{
   if (StatusOfDTC_u8Inhib != 0x5A)
   {
      SODTC_DftClr(u16DftIdx);
   }
}
/*------------------------------- end of file --------------------------------*/