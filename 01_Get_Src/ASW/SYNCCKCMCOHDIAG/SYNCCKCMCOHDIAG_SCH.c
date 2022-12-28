/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKCMCOHDIAG                                         */
/* !Description     : SYNCCKCMCOHDIAG component.                              */
/*                                                                            */
/* !Module          : SYNCCKCMCOHDIAG                                         */
/* !Description     : Cohérence de synchronisation des régimes Arbres à Cames */
/*                    et Vilebrequin                                          */
/*                                                                            */
/* !File            : SYNCCKCMCOHDIAG_SCH.C                                   */
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
/*   1 / SYNCCKCMCOHDIAG_vidEntryInit                                         */
/*   2 / Sync_SdlSlow_MonEngSpd                                               */
/*                                                                            */
/* !Reference   : V02 NT 09 04172 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKCMCOHDIAG/SYNCCKCMCOHDI$*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   26 May 2010 $*/
/* $Author::   hmelloul                               $$Date::   26 May 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "SYNCCKCMCOHDIAG.h"
#include "SYNCCKCMCOHDIAG_L.h"
#include "SYNCCKCMCOHDIAG_IM.h"
#include "GDGAR.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMCOHDIAG_vidEntryInit                               */
/* !Description :  Fonction Reset du calculateur                              */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B.KBOUBI                                                   */
/* !Trace_To    :  VEMS_R_09_04172_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMCOHDIAG_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : MONENGSPD_vidEntryInit                                         */
/* !Trigger  : Event Reset                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMCOHDIAG_vidEntryInit(void)
{
   SYNCCKCMCOHDIAG_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlSlow_MonEngSpd                                     */
/* !Description :  Moniteur lent du diagnostic de cohérence des régimes       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B.KBOUBI                                                   */
/* !Trace_To    :  VEMS_R_09_04172_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMCOHDIAG_vidMonEngSpd();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SYNCCKCMCOHDIAG_u8Inhib;                                      */
/*  input boolean Sync_bDgoEngSpdCohCk;                                       */
/*  input boolean Sync_bMonRunEngSpdCohCk;                                    */
/*  input boolean Sync_bDgoEngSpdCohInCm;                                     */
/*  input boolean Sync_bMonRunEngSpdCohInCm;                                  */
/*  input boolean Sync_bDgoEngSpdCohExCm;                                     */
/*  input boolean Sync_bMonRunEngSpdCohExCm;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_SdlSlow_MonEngSpd                                         */
/* !Trigger  : Sync_SdlSlow_MonEngSpd                                         */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlSlow_MonEngSpd(void)
{
   if (SYNCCKCMCOHDIAG_u8Inhib != 0x5A)
   {
      SYNCCKCMCOHDIAG_vidMonEngSpd();
      GDGAR_vidGdu(GD_DFT_ENGSPDCOHCK,
                   Sync_bDgoEngSpdCohCk,
                   Sync_bMonRunEngSpdCohCk,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ENGSPDCOHINCM,
                   Sync_bDgoEngSpdCohInCm,
                   Sync_bMonRunEngSpdCohInCm,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ENGSPDCOHEXCM,
                   Sync_bDgoEngSpdCohExCm,
                   Sync_bMonRunEngSpdCohExCm,
                   DIAG_DISPO);
   }
}
/*-------------------------------- end of file -------------------------------*/