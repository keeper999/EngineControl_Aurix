/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCINCMDIAG                                            */
/* !Description     : SYNCINCMDIAG component.                                 */
/*                                                                            */
/* !Module          : SYNCINCMDIAG                                            */
/* !Description     : STATUT ET DIAGNOSTIC DU SIGNAL ARBRE A CAMES ADMISSION. */
/*                                                                            */
/* !File            : SYNCINCMDIAG_SCH.C                                      */
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
/*   1 / Sync_EveRst_InCmSts                                                  */
/*   2 / Sync_EveInCmToo_InCmSts                                              */
/*   3 / Sync_EveKOn_InCmSts                                                  */
/*   4 / Sync_EveRTSt_InCmSts                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6884534 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCINCMDIAG/SYNCINCMDIAG_SCH$*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SYNCINCMDIAG_L.h"
#include "SYNCINCMDIAG.h"
#include "SYNCINCMDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_InCmSts                                        */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCINCMDIAG_vidInitOutput();                            */
/*  extf argret void SYNCINCMDIAG_vidIniDiag();                               */
/*  extf argret void SYNCINCMDIAG_vidInCmAcqVld();                            */
/*  extf argret void SYNCINCMDIAG_vidStopEng();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_InCmSts                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_InCmSts(void)
{
   SYNCINCMDIAG_vidInitOutput();
   SYNCINCMDIAG_vidIniDiag();
   SYNCINCMDIAG_vidInCmAcqVld();
   SYNCINCMDIAG_vidStopEng();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveInCmToo_InCmSts                                    */
/* !Description :  Evènement arbre à cames admission                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCINCMDIAG_vidDiag();                                  */
/*  extf argret void SYNCINCMDIAG_vidInCmAcqVld();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  extf argret void SYNCINCMDIAG_vidInCmCntFrnt();                           */
/*  input uint8 SYNCINCMDIAG_u8Inhib;                                         */
/*  input boolean Sync_bDgoCoh_InCm;                                          */
/*  input boolean Sync_bMonRunCoh_InCm;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveInCmToo_InCmSts                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveInCmToo_InCmSts(void)
{
   if (SYNCINCMDIAG_u8Inhib != 0x5A)
   {
      SYNCINCMDIAG_vidDiag();
      SYNCINCMDIAG_vidInCmAcqVld();
      GDGAR_vidGdu(GD_DFT_COH_INCM,
                   Sync_bDgoCoh_InCm,
                   Sync_bMonRunCoh_InCm,
                   DIAG_DISPO);
      SYNCINCMDIAG_vidInCmCntFrnt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveKOn_InCmSts                                        */
/* !Description :  Evènement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCINCMDIAG_vidIniDiag();                               */
/*  extf argret void SYNCINCMDIAG_vidInCmAcqVld();                            */
/*  input uint8 SYNCINCMDIAG_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveKOn_InCmSts                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveKOn_InCmSts(void)
{
   if (SYNCINCMDIAG_u8Inhib != 0x5A)
   {
      SYNCINCMDIAG_vidIniDiag();
      SYNCINCMDIAG_vidInCmAcqVld();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRTSt_InCmSts                                       */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCINCMDIAG_vidStopEng();                               */
/*  input uint8 SYNCINCMDIAG_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRTSt_InCmSts                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRTSt_InCmSts(void)
{
   if (SYNCINCMDIAG_u8Inhib != 0x5A)
   {
      SYNCINCMDIAG_vidStopEng();
   }
}
/*------------------------------- end of file --------------------------------*/