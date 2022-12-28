/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQRESCORD                                               */
/* !Description     : TQRESCORD component.                                    */
/*                                                                            */
/* !Module          : TQRESCORD                                               */
/* !Description     : COORDINATION DES RESERVES.                              */
/*                                                                            */
/* !File            : TQRESCORD_SCH.C                                         */
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
/*   1 / TQRESCORD_vidEntryInit                                               */
/*   2 / TqRes_Sdl10ms_tqMaxRes                                               */
/*                                                                            */
/* !Reference   : V02 NT 11 02659 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0183 / 2.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQRESCORD/TQRESCO$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQRESCORD.h"
#include "TQRESCORD_L.h"
#include "TQRESCORD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQRESCORD_vidEntryInit                                     */
/* !Description :  Fonction d'accroche Reset                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07512_001.01                                     */
/*                 VEMS_R_08_07512_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQRESCORD_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQRESCORD_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQRESCORD_vidEntryInit(void)
{
   TQRESCORD_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqMaxRes                                     */
/* !Description :  Fonction d'accroche au moniteur 10ms                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07512_001.01                                     */
/*                 VEMS_R_08_07512_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQRESCORD_vidCoord_degradations();                       */
/*  extf argret void TQRESCORD_vidCoord_reserves();                           */
/*  input uint8 TQRESCORD_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqRes_Sdl10ms_tqMaxRes                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqMaxRes(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (TQRESCORD_u8Inhib != 0x5A)
   {
      TQRESCORD_vidCoord_degradations();
      TQRESCORD_vidCoord_reserves();
   }
}

/*-------------------------------- End of file -------------------------------*/