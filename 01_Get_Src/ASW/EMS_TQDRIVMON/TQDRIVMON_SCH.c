/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQDRIVMON                                               */
/* !Description     : TQDRIVMON Component.                                    */
/*                                                                            */
/* !Module          : TQDRIVMON                                               */
/* !Description     : Valider couple conducteur.                              */
/*                                                                            */
/* !File            : TQDRIVMON_SCH.C                                         */
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
/*   1 / TQDRIVMON_vidEntryInit                                               */
/*   2 / SftyMgt_Sdl40ms_tqCkEfc                                              */
/*                                                                            */
/* !Reference   : V02 NT 10 01230 / 04                                        */
/* !OtherRefs   : CSCT_CGMT09_1790 / 2.3                                      */
/* !OtherRefs   : VEMS V02 ECU#047137                                         */
/* !OtherRefs   : VEMS V02 ECU#057585                                         */
/* !OtherRefs   : VEMS V02 ECU#060258                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQDRIVMON/TQDRIVMON_SC$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQDRIVMON.h"
#include "TQDRIVMON_L.h"
#include "TQDRIVMON_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidEntryInit                                     */
/* !Description :  Fonction d'accroche au moniteur Reset                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQDRIVMON_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQDRIVMON_vidEntryInit                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidEntryInit(void)
{
   TQDRIVMON_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_Sdl40ms_tqCkEfc                                    */
/* !Description :  Fonction d'accroche au moniteur moyen                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQDRIVMON_vidEnveloppeCoupleMaxi();                      */
/*  extf argret void TQDRIVMON_vidGenererrDrivTakeOff();                      */
/*  extf argret void TQDRIVMON_vidCalcCoupleSorIVC1();                        */
/*  extf argret void TQDRIVMON_vidValCoupleNivAppli();                        */
/*  extf argret void TQDRIVMON_vidValAntiCourseMorte();                       */
/*  extf argret void TQDRIVMON_vidValAideDecollage();                         */
/*  input uint8 TQDRIVMON_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_Sdl40ms_tqCkEfc                                        */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_Sdl40ms_tqCkEfc(void)
{
   if(TQDRIVMON_u8Inhib != 0x5A)
   {
      TQDRIVMON_vidEnveloppeCoupleMaxi();
      TQDRIVMON_vidGenererrDrivTakeOff();
      TQDRIVMON_vidCalcCoupleSorIVC1();
      TQDRIVMON_vidValCoupleNivAppli();
      TQDRIVMON_vidValAntiCourseMorte();
      TQDRIVMON_vidValAideDecollage();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*----------------------------- end of file ----------------------------------*/