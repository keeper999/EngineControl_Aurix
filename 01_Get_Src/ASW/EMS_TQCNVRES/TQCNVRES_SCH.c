/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCNVRES                                                */
/* !Description     : TQCNVRES Component                                      */
/*                                                                            */
/* !Module          : TQCNVRES                                                */
/* !Description     : Réserve de couple BVA                                   */
/*                                                                            */
/* !File            : TQCNVRES_SCH.C                                          */
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
/*   1 / TQCNVRES_vidEntryInit                                                */
/*   2 / TQCNVRES_vidEntry_10ms                                               */
/*                                                                            */
/* !Reference   : V02 NT 10 08543 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0179 / 2.1                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCNVRES/TQCNVRES$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQCNVRES.h"
#include "TQCNVRES_L.h"
#include "TQCNVRES_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCNVRES_vidEntryInit                                      */
/* !Description :  Fonction d'accroche moniteur Reset                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08543_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCNVRES_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCNVRES_vidInitOutput                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCNVRES_vidEntryInit(void)
{
   TQCNVRES_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCNVRES_vidEntry_10ms                                     */
/* !Description :  Fonction d'accroche de réserve de couple BVA               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08543_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCNVRES_vidReserve_Couple_BVA();                        */
/*  input uint8 TQCNVRES_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCNVRES_vidEntry_10ms                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCNVRES_vidEntry_10ms(void)
{
   if (TQCNVRES_u8Inhib != 0x5A)
   {
      TQCNVRES_vidReserve_Couple_BVA();
   }
}
/*------------------------------- end of file --------------------------------*/
