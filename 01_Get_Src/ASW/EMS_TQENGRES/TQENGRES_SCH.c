/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQENGRES                                                */
/* !Description     : TQENGRES Component.                                     */
/*                                                                            */
/* !Module          : TQENGRES                                                */
/* !Description     : réserve de couple moteur                                */
/*                                                                            */
/* !File            : TQENGRES_SCH.C                                          */
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
/*   1 / TQENGRES_vidEntryInit                                                */
/*   2 / TqRes_Sdl10ms_tqIdlRes                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5135152 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0176 / 2.3                                      */
/* !OtherRefs   : VEMS V02 ECU#065368                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQENGRES/TQENGRES$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "TQENGRES.h"
#include "TQENGRES_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidEntryInit                                      */
/* !Description :  Evénement Reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07504_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQENGRES_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQENGRES_vidEntryInit                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidEntryInit(void)
{
   TQENGRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqRes_Sdl10ms_tqIdlRes                                     */
/* !Description :  Evénement périodique toutes les 10 ms                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07504_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQENGRES_vidReserve_moteur();                            */
/*  input uint8 TQENGRES_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqRes_Sdl10ms_tqIdlRes                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqRes_Sdl10ms_tqIdlRes(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (TQENGRES_u8Inhib != 0x5A)
   {
      TQENGRES_vidReserve_moteur();
   }
}
/*---------------------------------end of file--------------------------------*/