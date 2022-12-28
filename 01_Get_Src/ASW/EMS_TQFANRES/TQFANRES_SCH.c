/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQFANRES                                                */
/* !Description     : TQFANRES component                                      */
/*                                                                            */
/* !Module          : TQFANRES                                                */
/* !Description     : RESERVE DE COUPLE GMV                                   */
/*                                                                            */
/* !File            : TQFANRES_SCH.C                                          */
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
/*   1 / TQFANRES_vidEntryInit                                                */
/*   2 / TQFANRES_vidEntry_10ms                                               */
/*                                                                            */
/* !Reference   : V02 NT 10 05001 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0180 / 2.1                                      */
/* !OtherRefs   : VEMS V02 ECU#050195                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQFANRES/TQFANRES$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "TQFANRES.h"
#include "TQFANRES_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidEntryInit                                      */
/* !Description :  Evènement de Reset.                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07509_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQFANRES_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQFANRES_vidEntryInit                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidEntryInit(void)
{
   TQFANRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidEntry_10ms                                     */
/* !Description :  Evènement 10 ms.                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07509_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQFANRES_vidReserveGMV();                                */
/*  input uint8 TQFANRES_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQFANRES_vidEntry_10ms                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidEntry_10ms(void)
{
   if ( TQFANRES_u8Inhib != 0x5A )
   {
      TQFANRES_vidReserveGMV();
   }
}
/*---------------------------------End Of File--------------------------------*/