/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : JDD                                                     */
/* !Description     : JDD Component                                           */
/*                                                                            */
/* !Module          : JDD                                                     */
/* !Description     : Gestionnaire du Journal Des Défauts                     */
/*                                                                            */
/* !File            : JDD_SCH.C                                               */
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
/*   1 / GD_EveRst_GJDD                                                       */
/*   2 / GD_SdlFast_GJDD                                                      */
/*   3 / GD_EveRxn772_GJDD                                                    */
/*   4 / GD_EveRxn55F_GJDD                                                    */
/*   5 / GD_EveRstDft_GJDD                                                    */
/*   6 / JDD_RstDftCal                                                        */
/*   7 / JDD_DftInPres                                                        */
/*   8 / JDD_DftExitUnval                                                     */
/*   9 / JDD_CxtFrfRec                                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5447356 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/JDD/JDD_SCH.C_v              $*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "JDD.h"
#include "JDD_L.h"
#include "JDD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_GJDD                                             */
/* !Description :  Evènement Reset CMM                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidInitOutput();                                     */
/*  extf argret void JDD_vidIni();                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_GJDD                                                 */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_GJDD(void)
{
   JDD_vidInitOutput();
   JDD_vidIni();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SdlFast_GJDD                                            */
/* !Description :  Moniteur rapide de la fonction GD.                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidTimeCounterBeforeSynchro();                       */
/*  extf argret void JDD_vidTransmissionFramesMngr();                         */
/*  input uint8 JDD_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_SdlFast_GJDD                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlFast_GJDD(void)
{
   if (JDD_u8Inhib != 0x5A)
   {
      JDD_vidTimeCounterBeforeSynchro();
      JDD_vidTransmissionFramesMngr();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRxn772_GJDD                                          */
/* !Description :  Evènement de réception de la trame 772                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidAcqFrame772();                                    */
/*  input uint8 JDD_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRxn772_GJDD                                              */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRxn772_GJDD(void)
{
   if (JDD_u8Inhib != 0x5A)
   {
      JDD_vidAcqFrame772();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRxn55F_GJDD                                          */
/* !Description :  Evènement de réception de la trame 55F                     */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidAcqFrame55F();                                    */
/*  input uint8 JDD_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRxn55F_GJDD                                              */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRxn55F_GJDD(void)
{
   if (JDD_u8Inhib != 0x5A)
   {
      JDD_vidAcqFrame55F();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDft_GJDD                                          */
/* !Description :  Requête d'effacement des défauts avec l'outil APV.         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidReqClrDft();                                      */
/*  input uint8 JDD_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDft_GJDD                                              */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDft_GJDD(void)
{
   if (JDD_u8Inhib != 0x5A)
   {
      JDD_vidReqClrDft();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_RstDftCal                                              */
/* !Description :  Demande d'effacement Manuel des défauts.                   */
/* !Number      :  SCH.6                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidReqClrDft();                                      */
/*  input uint8 JDD_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : JDD_RstDftCal                                                  */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_RstDftCal(void)
{
   if (JDD_u8Inhib != 0x5A)
   {
      JDD_vidReqClrDft();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_DftInPres                                              */
/* !Description :  Evènement défauts pannes apparus                           */
/* !Number      :  SCH.7                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidSetStateDtcPresent(argin uint16 u16IdxDft);       */
/*  extf argret void JDD_vidFillBufferContextFailure(argin uint16 u16IdxDft); */
/*  input uint8 JDD_u8Inhib;                                                  */
/*  input boolean Jbsi_bInh_C[350];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_DftInPres
(
   uint16 u16IdxDft
)
{
   if (JDD_u8Inhib != 0x5A)
   {
      if (Jbsi_bInh_C[u16IdxDft] == 0)
      {
         JDD_vidSetStateDtcPresent(u16IdxDft);
         JDD_vidFillBufferContextFailure(u16IdxDft);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_DftExitUnval                                           */
/* !Description :  Evènement défauts pannes disparus                          */
/* !Number      :  SCH.8                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidCaptureData(argin uint16 u16IdxDft);              */
/*  extf argret void JDD_vidSetStateDtcFugitf(argin uint16 u16IdxDft);        */
/*  extf argret void JDD_vidFillBufferContextFailure(argin uint16 u16IdxDft); */
/*  input uint8 JDD_u8Inhib;                                                  */
/*  input boolean Jbsi_bInh_C[350];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_DftExitUnval
(
   uint16 u16IdxDft
)
{
   if (JDD_u8Inhib != 0x5A)
   {
      if (Jbsi_bInh_C[u16IdxDft] == 0)
      {
         JDD_vidCaptureData(u16IdxDft);
         JDD_vidSetStateDtcFugitf(u16IdxDft);
         JDD_vidFillBufferContextFailure(u16IdxDft);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDD_CxtFrfRec                                              */
/* !Description :  Evènement défauts                                          */
/* !Number      :  SCH.9                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5447356_001.01                                       */
/*                 PTS_R_5447356_002.01                                       */
/*                 PTS_R_5447356_003.01                                       */
/*                 VEMS_R_10_08914_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_vidCaptureData(argin uint16 u16IdxDft);              */
/*  input uint8 JDD_u8Inhib;                                                  */
/*  input boolean Jbsi_bInh_C[350];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDD_CxtFrfRec
(
   uint16 u16IdxDft
)
{
   if (JDD_u8Inhib != 0x5A)
   {
      if (Jbsi_bInh_C[u16IdxDft] == 0)
      {
         JDD_vidCaptureData(u16IdxDft);
      }
   }
}
/*------------------------------- end of file --------------------------------*/