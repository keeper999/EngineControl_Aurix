/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKCMMONDIAG                                         */
/* !Description     : SYNCCKCMMONDIAG component.                              */
/*                                                                            */
/* !Module          : SYNCCKCMMONDIAG                                         */
/* !Description     : SURVEILLANCE DES SIGNAUX ARBRE A CAMES ET VILEBREQUIN   */
/*                                                                            */
/* !File            : SYNCCKCMMONDIAG_FCT2.C                                  */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / SYNCCKCMMONDIAG_vidGenrNoSigCk                                       */
/*   2 / SYNCCKCMMONDIAG_vidGenrSigLossCk                                     */
/*   3 / SYNCCKCMMONDIAG_vidGenrNoSigInCm                                     */
/*   4 / SYNCCKCMMONDIAG_vidGenrLossInCm                                      */
/*   5 / SYNCCKCMMONDIAG_vidGenrNoSigExCm                                     */
/*   6 / SYNCCKCMMONDIAG_vidGenrLossExCm                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 04208 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKCMMONDIAG/SYNCCKCMMONDI$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   20 Jan 2012 $*/
/* $Author::   wbouach                                $$Date::   20 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "SYNCCKCMMONDIAG_L.h"
#include "SYNCCKCMMONDIAG_IM.h"
#include "GDGAR.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrNoSigCk                             */
/* !Description :  Function-Call Generator                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidCmnCdnCkDiag();                       */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSgCkMonClcn();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Sync_bDgoNoSigCk;                                           */
/*  input boolean Sync_bMonRunNoSigCk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrNoSigCk(void)
{
   SYNCCKCMMONDIAG_vidCmnCdnCkDiag();
   SYNCCKCMMONDIAG_vidNoSgCkMonClcn();
   GDGAR_vidGdu(GD_DFT_NOSIGCK,
                Sync_bDgoNoSigCk,
                Sync_bMonRunNoSigCk,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrSigLossCk                           */
/* !Description :  Function-Call Generator                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidCmnCdnCkDiag();                       */
/*  extf argret void SYNCCKCMMONDIAG_vidLossCkMonCl();                        */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Sync_bDgoSigLossCk;                                         */
/*  input boolean Sync_bMonRunSigLossCk;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrSigLossCk(void)
{
   SYNCCKCMMONDIAG_vidCmnCdnCkDiag();
   SYNCCKCMMONDIAG_vidLossCkMonCl();
   GDGAR_vidGdu(GD_DFT_SIGLOSSCK,
                Sync_bDgoSigLossCk,
                Sync_bMonRunSigLossCk,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrNoSigInCm                           */
/* !Description :  Function-Call Generator                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidCmnCdnInCmDgo();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSgInCmCl();                         */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Sync_bDgoNoSigInCm;                                         */
/*  input boolean Sync_bMonRunNoSigInCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrNoSigInCm(void)
{
   SYNCCKCMMONDIAG_vidCmnCdnInCmDgo();
   SYNCCKCMMONDIAG_vidNoSgInCmCl();
   GDGAR_vidGdu(GD_DFT_NOSIGINCM,
                Sync_bDgoNoSigInCm,
                Sync_bMonRunNoSigInCm,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrLossInCm                            */
/* !Description :  Function-Call Generator                                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidCmnCdnInCmDgo();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidLossInCmCl();                         */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Sync_bDgoSigLossInCm;                                       */
/*  input boolean Sync_bMonRunSigLossInCm;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrLossInCm(void)
{
   SYNCCKCMMONDIAG_vidCmnCdnInCmDgo();
   SYNCCKCMMONDIAG_vidLossInCmCl();
   GDGAR_vidGdu(GD_DFT_SIGLOSSINCM,
                Sync_bDgoSigLossInCm,
                Sync_bMonRunSigLossInCm,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrNoSigExCm                           */
/* !Description :  Function-Call Generator                                    */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidCmnCdnExCmDgo();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSgExCmMonCl();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Sync_bDgoNoSigExCm;                                         */
/*  input boolean Sync_bMonRunNoSigExCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrNoSigExCm(void)
{
   SYNCCKCMMONDIAG_vidCmnCdnExCmDgo();
   SYNCCKCMMONDIAG_vidNoSgExCmMonCl();
   GDGAR_vidGdu(GD_DFT_NOSIGEXCM,
                Sync_bDgoNoSigExCm,
                Sync_bMonRunNoSigExCm,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrLossExCm                            */
/* !Description :  Function-Call Generator                                    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidCmnCdnExCmDgo();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidLossExCmCl();                         */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Sync_bDgoSigLossExCm;                                       */
/*  input boolean Sync_bMonRunSigLossExCm;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrLossExCm(void)
{
   SYNCCKCMMONDIAG_vidCmnCdnExCmDgo();
   SYNCCKCMMONDIAG_vidLossExCmCl();
   GDGAR_vidGdu(GD_DFT_SIGLOSSEXCM,
                Sync_bDgoSigLossExCm,
                Sync_bMonRunSigLossExCm,
                DIAG_DISPO);
}
/*------------------------------- end of file --------------------------------*/