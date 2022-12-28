/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSTGPMPRES                                             */
/* !Description     : TQSTGPMPRES component                                   */
/*                                                                            */
/* !Module          : TQSTGPMPRES                                             */
/* !Description     : RÉSERVE DE COUPLE DIRECTION ASSISTÉE                    */
/*                                                                            */
/* !File            : TQSTGPMPRES_SCH.C                                       */
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
/*   1 / TQSTGPMPRES_vidEntryInit                                             */
/*   2 / TQSTGPMPRES_vidEntry_10ms                                            */
/*                                                                            */
/* !Reference   : V02 NT 10 04991 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0178 / 2                                        */
/* !OtherRefs   : VEMS V02 ECU#052696                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQSTGPMPRES/TQSTG$*/
/* $Revision::   1.6      $$Author::   etsasson       $$Date::   28 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQSTGPMPRES.h"
#include "TQSTGPMPRES_IM.h"
#include "TQSTGPMPRES_l.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidEntryInit                                   */
/* !Description :  Scheduler reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04991_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSTGPMPRES_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQSTGPMPRES_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidEntryInit(void)
{
   TQSTGPMPRES_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidEntry_10ms                                  */
/* !Description :  Scheduler 10 ms                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04991_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSTGPMPRES_vidReserveDeCoupleDA();                      */
/*  input uint8 TQSTGPMPRES_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQSTGPMPRES_vidEntry_10ms                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidEntry_10ms(void)
{
   if (TQSTGPMPRES_u8Inhib != 0x5A)
   {
      TQSTGPMPRES_vidReserveDeCoupleDA();
   }
}
/*---------------------------------End Of File--------------------------------*/