/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RICHBOOST                                               */
/* !Description     : RICHBOOST component                                     */
/*                                                                            */
/* !Module          : RICHBOOST                                               */
/* !Description     : Synthese des Besoins Enrichissement Perfo GMP           */
/*                                                                            */
/* !File            : RICHBOOST_SCH.C                                         */
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
/*   1 / RICHBOOST_vidEntryInit                                               */
/*   2 / RICHBOOST_vidEntry_10ms                                              */
/*                                                                            */
/* !Reference   : V02 NT 10 06088 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0929/2                                          */
/* !OtherRefs   : VEMS V02 ECU#050139                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/RICHBOOST/RICHBOO$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "RICHBOOST.H"
#include "RICHBOOST_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidEntryInit                                     */
/* !Description :  Fonction d'accroche au moniteur Reset.                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RICHBOOST_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RICHBOOST_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidEntryInit(void)
{
   RICHBOOST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidEntry_10ms                                    */
/* !Description :  Schéduling de la fonction (10ms).                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RICHBOOST_vidDemandePerfoOverbst();                      */
/*  input uint8 RICHBOOST_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RICHBOOST_vidEntry_10ms                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidEntry_10ms(void)
{
   if (RICHBOOST_u8Inhib != 0x5A)
   {
      RICHBOOST_vidDemandePerfoOverbst();
   }
}
/*-------------------------------- end of file -------------------------------*/
