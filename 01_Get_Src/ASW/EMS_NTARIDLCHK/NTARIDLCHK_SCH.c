/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : NTARIDLCHK                                              */
/* !Description     : NTARIDLCHK component.                                   */
/*                                                                            */
/* !Module          : NTARIDLCHK                                              */
/* !Description     : Safety TMS : Valider consigne de Ralenti.               */
/*                                                                            */
/* !File            : NTARIDLCHK_SCH.C                                        */
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
/*   1 / NTARIDLCHK_vidEntryInit                                              */
/*   2 / SftyMgt_SdlMid_nTarIdlChk                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5049983 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_1792 / 1.6Br1                                   */
/* !OtherRefs   : VEMS V02 ECU#065161                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/NTARIDLCHK/NTARIDLCHK_$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "NTARIDLCHK.h"
#include "NTARIDLCHK_L.h"
#include "NTARIDLCHK_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NTARIDLCHK_vidEntryInit                                    */
/* !Description :  Fonction de reset                                          */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01232_001.04                                     */
/*                 VEMS_R_10_01232_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NTARIDLCHK_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : NTARIDLCHK_vidEntryInit                                        */
/* !Trigger  : NTARIDLCHK_vidEntryInit                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NTARIDLCHK_vidEntryInit(void)
{
   NTARIDLCHK_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_nTarIdlChk                                  */
/* !Description :  Fonction d'accroche au moniteur SftyMgt_SdlMid_nTarIdlChk  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01232_001.04                                     */
/*                 VEMS_R_10_01232_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NTARIDLCHK_vidValConsigneRalenti();                      */
/*  input uint8 NTARIDLCHK_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : SftyMgt_SdlMid_nTarIdlChk                                      */
/* !Trigger  : SftyMgt_SdlMid_nTarIdlChk                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_nTarIdlChk(void)
{
   if (NTARIDLCHK_u8Inhib != 0x5A)
   {
      NTARIDLCHK_vidValConsigneRalenti();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/