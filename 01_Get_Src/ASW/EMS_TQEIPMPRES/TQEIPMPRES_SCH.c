/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQEIPMPRES                                              */
/* !Description     : TQEIPMPRES component.                                   */
/*                                                                            */
/* !Module          : TQEIPMPRES                                              */
/* !Description     : Reserve de couple GEP                                   */
/*                                                                            */
/* !File            : TQEIPMPRES_SCH.C                                        */
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
/*   1 / TQEIPMPRES_vidEntryInit                                              */
/*   2 / TQEIPMPRES_vidEntry_10ms                                             */
/*                                                                            */
/* !Reference   : V02 NT 10 05003 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0182 / 2                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQEIPMPRES/TQEIPM$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "TQEIPMPRES.h"
#include "TQEIPMPRES_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQEIPMPRES_vidEntryInit                                    */
/* !Description :  Evénement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05003_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQEIPMPRES_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQEIPMPRES_vidEntryInit                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQEIPMPRES_vidEntryInit(void)
{
   TQEIPMPRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQEIPMPRES_vidEntry_10ms                                   */
/* !Description :  Evènement qui se déclenche chaque 10 ms                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05003_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQEIPMPRES_vidReserve_couple_GEP();                      */
/*  input uint8 TQEIPMPRES_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQEIPMPRES_vidEntry_10ms                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQEIPMPRES_vidEntry_10ms(void)
{
   if (TQEIPMPRES_u8Inhib != 0x5A)
   {
      TQEIPMPRES_vidReserve_couple_GEP();
   }
}
/*------------------------------end of file ----------------------------------*/