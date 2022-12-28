/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQIDLCHK                                                */
/* !Description     : TQIDLCHK Component                                      */
/*                                                                            */
/* !Module          : TQIDLCHK                                                */
/* !Description     : VALIDER REGULATION RALENTI                              */
/*                                                                            */
/* !File            : TQIDLCHK_SCH.C                                          */
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
/*   1 / TQIDLCHK_vidEntryInit                                                */
/*   2 / SftyMgt_SdlMid_nOfsIdlTakeOff                                        */
/*   3 / SftyMgt_SdlMid_tqIdl                                                 */
/*   4 / SftyMgt_SdlMid_IdlChk                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 01242 / 02                                        */
/* !OtherRefs   : CSCT_CGMT09_2400 / 1.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDLCHK/TQIDLCHK_SCH.$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQIDLCHK.h"
#include "TQIDLCHK_l.h"
#include "TQIDLCHK_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDLCHK_vidEntryInit                                      */
/* !Description :  evenement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDLCHK_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQIDLCHK_vidEntryInit                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDLCHK_vidEntryInit(void)
{
   TQIDLCHK_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_nOfsIdlTakeOff                              */
/* !Description :  Fonction d'accroche à l'evenement                          */
/*                 SftyMgt_SdlMid_nOfsIdlTakeOff                              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01242_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDLCHK_vidValRalentiDecollage();                       */
/*  input uint8 TQIDLCHK_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_nOfsIdlTakeOff                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_nOfsIdlTakeOff(void)
{
   if (TQIDLCHK_u8Inhib != 0x5A)
   {
      TQIDLCHK_vidValRalentiDecollage();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqIdl                                       */
/* !Description :  Fonction d'accroche à l'evenement SftyMgt_SdlMid_tqIdl     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01242_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDLCHK_vidValidRegulRalenti();                         */
/*  input uint8 TQIDLCHK_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqIdl                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqIdl(void)
{
   if (TQIDLCHK_u8Inhib != 0x5A)
   {
      TQIDLCHK_vidValidRegulRalenti();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_IdlChk                                      */
/* !Description :  Fonction d'accroche à l'evenement SftyMgt_SdlMid_IdlChk    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01242_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQIDLCHK_vidValidGlobaleRalenti();                       */
/*  input uint8 TQIDLCHK_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_IdlChk                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_IdlChk(void)
{
   if (TQIDLCHK_u8Inhib != 0x5A)
   {
      TQIDLCHK_vidValidGlobaleRalenti();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/