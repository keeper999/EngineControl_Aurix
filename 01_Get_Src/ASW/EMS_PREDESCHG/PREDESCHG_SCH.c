/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PREDESCHG                                               */
/* !Description     : PREDESCHG Component.                                    */
/*                                                                            */
/* !Module          : PREDESCHG                                               */
/* !Description     : Sélection de variables durant l’arrêt moteur            */
/*                    (PredEsChg).                                            */
/*                                                                            */
/* !File            : PREDESCHG_SCH.C                                         */
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
/*   1 / PREDESCHG_vidEntryInit                                               */
/*   2 / PREDESCHG_vidEntry_10ms                                              */
/*                                                                            */
/* !Reference   : V02 NT 10 02549 / 02                                        */
/* !OtherRefs   : 01460_10_00599 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/PREDESCHG/PREDESCHG_SC$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   29 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   29 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PREDESCHG.h"
#include "PREDESCHG_L.h"
#include "PREDESCHG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDESCHG_vidEntryInit                                     */
/* !Description :  Evènement de Reset                                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02549_001.01                                     */
/*                 VEMS_R_10_02549_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDESCHG_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PREDESCHG_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDESCHG_vidEntryInit(void)
{
   PREDESCHG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDESCHG_vidEntry_10ms                                    */
/* !Description :  Evènement de récurrence du module PREDESCHG                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02549_001.01                                     */
/*                 VEMS_R_10_02549_005.01                                     */
/*                 VEMS_R_10_02549_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDESCHG_vidPredEsChgDraft();                           */
/*  input uint8 PREDESCHG_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PREDESCHG_vidEntry_10ms                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDESCHG_vidEntry_10ms(void)
{
   if (PREDESCHG_u8Inhib != 0x5A)
   {
      PREDESCHG_vidPredEsChgDraft();
   }
}
/*************************** end of file **************************************/