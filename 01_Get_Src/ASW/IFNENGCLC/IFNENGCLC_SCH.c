/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFNENGCLC                                               */
/* !Description     : IFNENGCLC component                                     */
/*                                                                            */
/* !Module          : IFNENGCLC                                               */
/* !Description     : Interface modulaire du calcul du régime pour le régime  */
/*                    recentré                                                */
/*                                                                            */
/* !File            : IFNENGCLC_SCH.C                                         */
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
/*   1 / IFNENGCLC_vidEntryInit                                               */
/*   2 / Sync_EveTDC_IfNEngClc                                                */
/*   3 / Sync_EveBDC_IfNEngClc                                                */
/*                                                                            */
/* !Reference   : V02 NT 11 03031 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IFNENGCLC/IFNENGCLC_SCH.C_v       $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   31 Jan 2011 $*/
/* $Author::   wbouach                                $$Date::   31 Jan 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IFNENGCLC.h"
#include "IFNENGCLC_L.h"
#include "IFNENGCLC_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFNENGCLC_vidEntryInit                                     */
/* !Description :  Initialisation du calculateur.                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFNENGCLC_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IFNENGCLC_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFNENGCLC_vidEntryInit(void)
{
   IFNENGCLC_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_IfNEngClc                                      */
/* !Description :  Interruption PMH.                                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFNENGCLC_vidTDCGeneration();                            */
/*  input uint8 IFNENGCLC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_IfNEngClc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_IfNEngClc(void)
{
   if (IFNENGCLC_u8Inhib != 0x5A)
   {
      IFNENGCLC_vidTDCGeneration();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveBDC_IfNEngClc                                      */
/* !Description :  Evénement Point Mort Bas (PMB / BDC).                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFNENGCLC_vidBDCGeneration();                            */
/*  input uint8 IFNENGCLC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveBDC_IfNEngClc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveBDC_IfNEngClc(void)
{
   if (IFNENGCLC_u8Inhib != 0x5A)
   {
      IFNENGCLC_vidBDCGeneration();
   }
}
/*------------------------------- end of file --------------------------------*/