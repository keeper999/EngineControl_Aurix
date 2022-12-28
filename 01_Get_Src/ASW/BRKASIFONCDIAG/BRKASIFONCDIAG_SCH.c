/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKASIFONCDIAG                                          */
/* !Description     : BRKASIFONCDIAG Component.                               */
/*                                                                            */
/* !Module          : BRKASIFONCDIAG                                          */
/* !Description     : Diagnostic fonctionnel du capteur de dépression         */
/*                    Mastervac.                                              */
/*                                                                            */
/* !File            : BRKASIFONCDIAG_SCH.C                                    */
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
/*   1 / BRKASIFONCDIAG_vidEntryInit                                          */
/*   2 / AirPres_SdlFast_MonBrkAsi                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 04714 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BRKASIFONCDIAG/BRKASIFONCDIAG_SCH.$*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   13 May 2011 $*/
/* $Author::   hmelloul                               $$Date::   13 May 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BRKASIFONCDIAG.h"
#include "BRKASIFONCDIAG_L.h"
#include "BRKASIFONCDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIFONCDIAG_vidEntryInit                                */
/* !Description :  Fonction d'accroche au reset.                              */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.HALOUANI                                                 */
/* !Trace_To    :  VEMS_R_09_04714_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKASIFONCDIAG_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_MonBrkAsi                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIFONCDIAG_vidEntryInit(void)
{
   BRKASIFONCDIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_MonBrkAsi                                  */
/* !Description :  Moniteur rapide de la fonction AirPres                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.HALOUANI                                                 */
/* !Trace_To    :  VEMS_R_09_04714_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKASIFONCDIAG_vidRun();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 BRKASIFONCDIAG_u8Inhib;                                       */
/*  input boolean AirPres_bDgoCoh_pBrkAsi;                                    */
/*  input boolean AirPres_bMonRunCoh_pBrkAsi;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_MonBrkAsi                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_MonBrkAsi(void)
{
   if (BRKASIFONCDIAG_u8Inhib != 0x5A)
   {
      BRKASIFONCDIAG_vidRun();
      GDGAR_vidGdu(GD_DFT_COH_PBRKASI,
                   AirPres_bDgoCoh_pBrkAsi,
                   AirPres_bMonRunCoh_pBrkAsi,
                   DIAG_DISPO);
   }
}
/*----------------------------- end of file ----------------------------------*/