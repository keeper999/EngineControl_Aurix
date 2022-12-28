/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCOMP                                                  */
/* !Description     : TQCOMP component.                                       */
/*                                                                            */
/* !Module          : TQCOMP                                                  */
/* !Description     : safety tms : comparer les couples.                      */
/*                                                                            */
/* !File            : TQCOMP_SCH.C                                            */
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
/*   1 / TQCOMP_vidEntryInit                                                  */
/*   2 / SftyMgt_SdlMid_tqComp                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5050623 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_1862 / 1.3                                      */
/* !OtherRefs   : VEMS V02 ECU#048269                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMP/TQCOMP_SCH.C_v $*/
/* $Revision::   1.5.1.2  $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "TQCOMP.h"
#include "TQCOMP_L.h"
#include "TQCOMP_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMP_vidEntryInit                                        */
/* !Description :  Fonction d'accroche au moniteur Reset                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01255_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMP_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TQCOMP_vidEntryInit                                            */
/* !Trigger  : TQCOMP_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMP_vidEntryInit(void)
{
   TQCOMP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqComp                                      */
/* !Description :  Fonction d'accroche au moniteur 40ms.                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01255_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMP_vidComparer_Couples();                            */
/*  input uint8 TQCOMP_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : SftyMgt_SdlMid_tqComp                                          */
/* !Trigger  : SftyMgt_SdlMid_tqComp                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqComp(void)
{
   if (TQCOMP_u8Inhib != 0x5A)
   {
      TQCOMP_vidComparer_Couples();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/