/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FFGEN                                                   */
/* !Description     : FFGEN Component                                         */
/*                                                                            */
/* !Module          : FFGEN                                                   */
/* !Description     : ESTIMER COUPLE REEL                                     */
/*                                                                            */
/* !File            : FFGEN_SCH.C                                             */
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
/*   1 / FFGEN_vidEntryInit                                                   */
/*   2 / SftyMgt_SdlMid_FrfGen                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 01258 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2406 / 1                                        */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/FFGEN/FFGEN_SCH.C_v   $*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   12 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_Types.h"
#include "FFGEN.H"
#include "FFGEN_L.H"
#include "FFGEN_IM.H"

#define TMS_START_SEC_CODE
#include "MemMap.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FFGEN_vidEntryInit                                         */
/* !Description :  L'évènement d'initialisation du module FFGEN.              */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01258_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FFGEN_vidInitOutput();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : FFGEN_vidEntryInit                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FFGEN_vidEntryInit(void)
{
   FFGEN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_FrfGen                                      */
/* !Description :  L'évènement de déclanchement du module.                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01258_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FFGEN_vidConstructionFrf();                              */
/*  input uint8 FFGEN_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : SftyMgt_SdlMid_FrfGen                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_FrfGen(void)
{
   if (FFGEN_u8Inhib != 0x5A)
   {
      FFGEN_vidConstructionFrf();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/******************************* <End_Of_File> ********************************/