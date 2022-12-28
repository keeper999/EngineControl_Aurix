/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DFTMGT                                                  */
/* !Description     : DFTMGT Component.                                       */
/*                                                                            */
/* !Module          : DFTMGT                                                  */
/* !Description     : Safety TMS : INTERFACE DEFAUTS SFTYMGR.                 */
/*                                                                            */
/* !File            : DFTMGT_SCH.C                                            */
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
/*   1 / DFTMGT_vidEntryInit                                                  */
/*   2 / SftyMgt_SdlMid_DftMgt                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5402500 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2404 / 1.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/DFTMGT/DFTMGT_SCH.C_v $*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   19 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   19 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "DFTMGT.h"
#include "DFTMGT_L.h"
#include "DFTMGT_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTMGT_vidEntryInit                                        */
/* !Description :  Evenement reset calculateur                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DFTMGT_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : DFTMGT_vidEntryInit                                            */
/* !Trigger  : DFTMGT_vidEntryInit                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTMGT_vidEntryInit(void)
{
   DFTMGT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_DftMgt                                      */
/* !Description :  déclancher l'evenement SftyMgt_SdlMid_DftMgt               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DFTMGT_vidInterfaceDftSftyMgt();                         */
/*  input uint8 DFTMGT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : SftyMgt_SdlMid_DftMgt                                          */
/* !Trigger  : SftyMgt_SdlMid_DftMgt                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_DftMgt(void)
{
   if (DFTMGT_u8Inhib != 0x5A)
   {
      DFTMGT_vidInterfaceDftSftyMgt();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/