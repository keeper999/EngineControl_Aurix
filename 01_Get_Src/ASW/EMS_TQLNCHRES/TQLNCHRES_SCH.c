/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLNCHRES                                               */
/* !Description     : TQLNCHRES Component.                                    */
/*                                                                            */
/* !Module          : TQLNCHRES                                               */
/* !Description     : Réserve de couple décollage                             */
/*                                                                            */
/* !File            : TQLNCHRES_SCH.C                                         */
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
/*   1 / TQLNCHRES_vidEntryInit                                               */
/*   2 / TQLNCHRES_vidEntry_10ms                                              */
/*                                                                            */
/* !Reference   : V02 NT 10 04984 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0175 / 2                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQLNCHRES/TQLNCHR$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQLNCHRES.h"
#include "TQLNCHRES_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidEntryInit                                     */
/* !Description :  Fonction d'accroche au moniteur Reset.                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04984_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLNCHRES_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQLNCHRES_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidEntryInit(void)
{
   TQLNCHRES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidEntry_10ms                                    */
/* !Description :  Fonction d'accroche au moniteur 10ms.                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04984_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLNCHRES_vidReserveCplDecollage();                      */
/*  input uint8 TQLNCHRES_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQLNCHRES_vidEntry_10ms                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidEntry_10ms(void)
{
   if (TQLNCHRES_u8Inhib != 0x5A)
   {
      TQLNCHRES_vidReserveCplDecollage();
   }
}

/*------------------------------ end of file ---------------------------------*/