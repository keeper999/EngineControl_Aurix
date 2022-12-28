/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COPTST                                                  */
/* !Description     : COPTST Component.                                       */
/*                                                                            */
/* !Module          : COPTST                                                  */
/* !Description     : Définition des variables STT                            */
/*                                                                            */
/* !File            : COPTST_SCH.C                                            */
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
/*   1 / COPTST_vidEntryInit                                                  */
/*   2 / CoPTSt_SdlFast_RStrtSTT                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 05959 / 04                                        */
/* !OtherRefs   : CSMT_CGMT08_3115 / 1.1                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COPTST/COPTST_SCH.C_v $*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "COPTST.h"
#include "COPTST_L.h"
#include "COPTST_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidEntryInit                                        */
/* !Description :  initialisation des sorties.                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COPTST_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : COPTST_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidEntryInit(void)
{
   COPTST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoPTSt_SdlFast_RStrtSTT                                    */
/* !Description :  Scheduler rapide                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COPTST_vidDefinitionVariables();                         */
/*  input uint8 COPTST_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoPTSt_SdlFast_RStrtSTT                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoPTSt_SdlFast_RStrtSTT(void)
{
   if (COPTST_u8Inhib != 0x5A)
   {
      COPTST_vidDefinitionVariables();
   }
}
/*--------------------------------- end of file ------------------------------*/