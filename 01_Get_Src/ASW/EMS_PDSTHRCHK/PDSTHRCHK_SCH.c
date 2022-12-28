/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PDSTHRCHK                                               */
/* !Description     : PDSTHRCHK Component.                                    */
/*                                                                            */
/* !Module          : PDSTHRCHK                                               */
/* !Description     : Safety TMS : Sécuriser Pression Admission.              */
/*                                                                            */
/* !File            : PDSTHRCHK_SCH.C                                         */
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
/*   1 / PDSTHRCHK_vidEntryInit                                               */
/*   2 / SftyMgt_SdlMid_pDsThrChk                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5050542 / 02                                        */
/* !OtherRefs   : CSCT_CGMT09_2405 / 1.4                                      */
/* !OtherRefs   : VEMS V02 ECU#065902                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/PDSTHRCHK/PDSTHRCHK_SC$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   02 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   02 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "PDSTHRCHK.h"
#include "PDSTHRCHK_L.h"
#include "PDSTHRCHK_IM.h"
#include "STD_TYPES.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PDSTHRCHK_vidEntryInit                                     */
/* !Description :  Evenement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_10_01239_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PDSTHRCHK_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PDSTHRCHK_vidEntryInit                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PDSTHRCHK_vidEntryInit(void)
{
   PDSTHRCHK_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_pDsThrChk                                   */
/* !Description :  Cette fonction est appelée sur l'évènement                 */
/*                 SftyMgt_SdlMid_pDsThrChk                                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_10_01239_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PDSTHRCHK_vidEstimPresAdmission();                       */
/*  extf argret void PDSTHRCHK_vidEstimOffAppSec();                           */
/*  extf argret void PDSTHRCHK_vidSecurPressSensor();                         */
/*  extf argret void PDSTHRCHK_vidCompSecurisation();                         */
/*  input uint8 PDSTHRCHK_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_pDsThrChk                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_pDsThrChk(void)
{
   if (PDSTHRCHK_u8Inhib != 0x5A)
   {
      PDSTHRCHK_vidEstimPresAdmission();
      PDSTHRCHK_vidEstimOffAppSec();
      PDSTHRCHK_vidSecurPressSensor();
      PDSTHRCHK_vidCompSecurisation();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/