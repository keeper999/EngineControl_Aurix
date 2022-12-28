/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAUTHDFTSTT                                            */
/* !Description     : IFAUTHDFTSTT Component                                  */
/*                                                                            */
/* !Module          : IFAUTHDFTSTT                                            */
/* !Description     : SAFETY TMS: INTERFACE AUTORISATION DEFAUT STT           */
/*                                                                            */
/* !File            : IFAUTHDFTSTT_SCH.C                                      */
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
/*   1 / IFAUTHDFTSTT_vidEntryInit                                            */
/*   2 / SftyMgt_SdlMid_IfSftyMgtSTT                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 01213 / 02                                        */
/* !OtherRefs   : 01460_09_01031 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFAUTHDFTSTT/IFAUTHDFT$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IFAUTHDFTSTT.H"
#include "IFAUTHDFTSTT_L.H"
#include "IFAUTHDFTSTT_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAUTHDFTSTT_vidEntryInit                                  */
/* !Description :  Evenement RESET                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_01213_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAUTHDFTSTT_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IFAUTHDFTSTT_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAUTHDFTSTT_vidEntryInit(void)
{
   IFAUTHDFTSTT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_IfSftyMgtSTT                                */
/* !Description :  Evennement de déclenchement de la  fonction  de            */
/*                 sécurisation  les demandes Démarrage / redémarrage STTd.   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_01213_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAUTHDFTSTT_vidIrfAutrstDftSTT();                       */
/*  input uint8 IFAUTHDFTSTT_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_IfSftyMgtSTT                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_IfSftyMgtSTT(void)
{
   if (IFAUTHDFTSTT_u8Inhib != 0x5A)
   {
      IFAUTHDFTSTT_vidIrfAutrstDftSTT();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*-------------------------------- end of file -------------------------------*/