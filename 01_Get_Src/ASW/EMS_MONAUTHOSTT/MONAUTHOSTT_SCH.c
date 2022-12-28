/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MONAUTHOSTT                                             */
/* !Description     : MONAUTHOSTT Component                                   */
/*                                                                            */
/* !Module          : MONAUTHOSTT                                             */
/* !Description     : SAFETY TMS : STT Chaine de Traction                     */
/*                                                                            */
/* !File            : MONAUTHOSTT_SCH.C                                       */
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
/*   1 / MONAUTHOSTT_vidEntryInit                                             */
/*   2 / SftyMgt_SdlMid_STTDrvTra                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5199597 / 01                                        */
/* !OtherRefs   : 01460_10_03769 / 1.3                                        */
/* !OtherRefs   : VEMS V02 ECU#047008                                         */
/* !OtherRefs   : VEMS V02 ECU#060257                                         */
/* !OtherRefs   : VEMS V02 ECU#065855                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/MONAUTHOSTT/MONAUTHOST$*/
/* $Revision::   1.4.1.1  $$Author::   mbenfrad       $$Date::   23 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   23 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MONAUTHOSTT.h"
#include "MONAUTHOSTT_L.h"
#include "MONAUTHOSTT_IM.h"
#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidEntryInit                                   */
/* !Description :  Accroche moniteur de la fonction  Reset                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MONAUTHOSTT_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MONAUTHOSTT_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidEntryInit(void)
{
   MONAUTHOSTT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_STTDrvTra                                   */
/* !Description :  Moniteur Moyen du module MONAUTHOSTT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  PTS_R_5199597_001.01                                       */
/*                 VEMS_R_11_01222_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MONAUTHOSTT_vidConfigArchiEEBV();                        */
/*  extf argret void MONAUTHOSTT_vidSTTConfiguration();                       */
/*  extf argret void MONAUTHOSTT_vidSecurisationADML();                       */
/*  extf argret void MONAUTHOSTT_vidSecurisationSTTDA();                      */
/*  extf argret void MONAUTHOSTT_vidMergeSTTConfig();                         */
/*  input uint8 MONAUTHOSTT_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_STTDrvTra                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_STTDrvTra(void)
{
   if (MONAUTHOSTT_u8Inhib != 0x5A)
   {
      MONAUTHOSTT_vidConfigArchiEEBV();
      MONAUTHOSTT_vidSTTConfiguration();
      MONAUTHOSTT_vidSecurisationADML();
      MONAUTHOSTT_vidSecurisationSTTDA();
      MONAUTHOSTT_vidMergeSTTConfig();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------ end of file ---------------------------------*/