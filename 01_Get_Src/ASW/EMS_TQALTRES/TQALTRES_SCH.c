/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQALTRES                                                */
/* !Description     : TQALTRES component                                      */
/*                                                                            */
/* !Module          : TQALTRES                                                */
/* !Description     : RÉSERVE DE COUPLE ALTERNATEUR                           */
/*                                                                            */
/* !File            : TQALTRES_SCH.C                                          */
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
/*   1 / TQALTRES_vidEntryInit                                                */
/*   2 / TqRes_Sdl10ms_tqAltRes                                               */
/*                                                                            */
/* !Reference   : V02 NT 11 02660 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0177 / 2.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQALTRES/TQALTRES$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "TQALTRES.h"
#include "TQALTRES_l.h"
#include "TQALTRES_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQALTRES_vidEntryInit                                      */
/* !Description :  Scheduler Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02660_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQALTRES_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQALTRES_vidEntryInit                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQALTRES_vidEntryInit(void)
{
   TQALTRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqAltRes                                     */
/* !Description :  Scheduler 10 ms                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02660_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQALTRES_vidReserveCoupleALT();                          */
/*  input uint8 TQALTRES_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqRes_Sdl10ms_tqAltRes                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqAltRes(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (TQALTRES_u8Inhib != 0x5A)
   {
      TQALTRES_vidReserveCoupleALT();
   }
}
/*---------------------------------End Of File--------------------------------*/