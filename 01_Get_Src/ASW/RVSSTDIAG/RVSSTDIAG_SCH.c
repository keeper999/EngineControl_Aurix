/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RVSSTDIAG                                               */
/* !Description     : RVSSTDIAG component.                                    */
/*                                                                            */
/* !Module          : RVSSTDIAG                                               */
/* !Description     : Diagnostic fonctionnel de l’information marche arrière: */
/*                    détection du défaut et info MA.                         */
/*                                                                            */
/* !File            : RVSSTDIAG_SCH.C                                         */
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
/*   1 / RVSSTDIAG_vidEntryInit                                               */
/*   2 / Gear_SdlMid_FctDiagRvsSt                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 01180 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RVSSTDIAG/RVSSTDIAG_SCH.C_v       $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   23 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   23 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "RVSSTDIAG.h"
#include "RVSSTDIAG_L.h"
#include "RVSSTDIAG_IM.h"
#include "GDGAR.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RVSSTDIAG_vidEntryInit                                     */
/* !Description :  Acroche moniteur pour l'initailisation des sorties         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RVSSTDIAG_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RVSSTDIAG_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RVSSTDIAG_vidEntryInit(void)
{
   RVSSTDIAG_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_SdlMid_FctDiagRvsSt                                   */
/* !Description :  Moniteur moyen.                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_09_01180_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RVSSTDIAG_vidDiagMng();                                  */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 RVSSTDIAG_u8Inhib;                                            */
/*  input boolean Gear_bDgoRvsGear;                                           */
/*  input boolean Gear_bMonRunRvsGear;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Gear_SdlMid_FctDiagRvsSt                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_SdlMid_FctDiagRvsSt(void)
{
   if (RVSSTDIAG_u8Inhib != 0x5A)
   {
      RVSSTDIAG_vidDiagMng();
      GDGAR_vidGdu( GD_DFT_RVSGEAR,
                    Gear_bDgoRvsGear,
                    Gear_bMonRunRvsGear,
                    DIAG_DISPO);
   }
}
/*------------------------------ end of file ---------------------------------*/