/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCEXCMDIAG                                            */
/* !Description     : SYNCEXCMDIAG component                                  */
/*                                                                            */
/* !Module          : SYNCEXCMDIAG                                            */
/* !Description     : STATUT ET DIAGNOSTIC DU SIGNAL ARBRE A CAMES ECHAPPEMENT*/
/*                                                                            */
/* !File            : SYNCEXCMDIAG_SCH.C                                      */
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
/*   1 / Sync_EveRst_ExCmSts                                                  */
/*   2 / Sync_EveExCmToo_ExCmSts                                              */
/*   3 / Sync_EveKOn_ExCmSts                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6884540 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCEXCMDIAG/SYNCEXCMDIAG_SCH$*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SYNCEXCMDIAG.h"
#include "SYNCEXCMDIAG_L.h"
#include "SYNCEXCMDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_ExCmSts                                        */
/* !Description :  Fonction d'accroche au moniteur Sync_EveRst_ExAcq          */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCEXCMDIAG_vidInitOutput();                            */
/*  extf argret void SYNCEXCMDIAG_vidIniDiag();                               */
/*  extf argret void SYNCEXCMDIAG_vidExCmAcqVld();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveRst_ExCmSts                                            */
/* !Trigger  : Sync_EveRst_ExCmSts                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_ExCmSts(void)
{
   SYNCEXCMDIAG_vidInitOutput();
   SYNCEXCMDIAG_vidIniDiag();
   SYNCEXCMDIAG_vidExCmAcqVld();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveExCmToo_ExCmSts                                    */
/* !Description :  Fonction d'accroche au moniteur Sync_EveExCmToo_Acq        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCEXCMDIAG_vidDiag();                                  */
/*  extf argret void SYNCEXCMDIAG_vidExCmAcqVld();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SYNCEXCMDIAG_u8Inhib;                                         */
/*  input boolean Sync_bDgoCoh_ExCm;                                          */
/*  input boolean Sync_bMonRunCoh_ExCm;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveExCmToo_ExCmSts                                        */
/* !Trigger  : Sync_EveExCmToo_ExCmSts                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveExCmToo_ExCmSts(void)
{
   if (SYNCEXCMDIAG_u8Inhib != 0x5A)
   {
      SYNCEXCMDIAG_vidDiag();
      SYNCEXCMDIAG_vidExCmAcqVld();
      GDGAR_vidGdu(GD_DFT_COH_EXCM,
                   Sync_bDgoCoh_ExCm,
                   Sync_bMonRunCoh_ExCm,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveKOn_ExCmSts                                        */
/* !Description :  Fonction d'accroche au moniteur Sync_EveKOn_ExDiag         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCEXCMDIAG_vidIniDiag();                               */
/*  extf argret void SYNCEXCMDIAG_vidExCmAcqVld();                            */
/*  input uint8 SYNCEXCMDIAG_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveKOn_ExCmSts                                            */
/* !Trigger  : Sync_EveKOn_ExCmSts                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveKOn_ExCmSts(void)
{
   if (SYNCEXCMDIAG_u8Inhib != 0x5A)
   {
      SYNCEXCMDIAG_vidIniDiag();
      SYNCEXCMDIAG_vidExCmAcqVld();
   }
}
/*-------------------------- end of file -------------------------------------*/