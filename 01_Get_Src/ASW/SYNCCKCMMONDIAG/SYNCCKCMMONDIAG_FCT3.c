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
/* !File            : SYNCCKCMMONDIAG_FCT3.C                                  */
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
/*   1 / SYNCCKCMMONDIAG_vidCmnCdnCkDiag                                      */
/*   2 / SYNCCKCMMONDIAG_vidCkMonRst                                          */
/*   3 / SYNCCKCMMONDIAG_vidClEveCkMonRst                                     */
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
#include "SYNCCKCMMONDIAG.h"
#include "SYNCCKCMMONDIAG_L.h"
#include "SYNCCKCMMONDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidCmnCdnCkDiag                            */
/* !Description :  Ce bloc génère le booléen Sync_bCmnCdnCkDiag qui indique,  */
/*                 lorsqu’il est à ON, que les conditions communes de test de */
/*                 perte ou d’absence du signal vilebrequins sont remplies    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Sync_bInCmAcqVld;                                           */
/*  input boolean Acq_crk_no_sgnl_diag_ena_upcb0;                             */
/*  output boolean Sync_bCmnCdnCkDiag;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidCmnCdnCkDiag(void)
{
   boolean bLocalInhNoSigSigLossCkDiag;
   boolean bLocalSync_bInCmAcqVld;


   bLocalInhNoSigSigLossCkDiag = GDGAR_bGetFRM(FRM_FRM_INHNOSIGSIGLOSSCKDIAG);
   VEMS_vidGET(Sync_bInCmAcqVld, bLocalSync_bInCmAcqVld);

   if (  (bLocalSync_bInCmAcqVld != 0)
      && (Acq_crk_no_sgnl_diag_ena_upcb0 != 0)
      && (bLocalInhNoSigSigLossCkDiag == 0))
   {
      Sync_bCmnCdnCkDiag = 1;
   }
   else
   {
      Sync_bCmnCdnCkDiag = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidCkMonRst                                */
/* !Description :  Lorsqu’il  n’y  a  plus d’évènement  arbre  à  cames       */
/*                 admission,  les  conditions  de  diagnostics de  l’absence */
/*                 et  de perte du signal vilebrequin doivent être remises à  */
/*                 zéro. Cette opération est effectuée à travers l’évènement  */
/*                 CALL_MonRunCkRst.                                          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCCKCMMONDIAG_vidClEveCkMonRst();                      */
/*  input boolean Acq_crk_eng_run_status_upvb0;                               */
/*  input boolean Acq_crk_eng_run_upvb0;                                      */
/*  input boolean Acq_incam_tooth_det_upvb0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidCkMonRst(void)
{
   boolean bLocalAcq_crk_eng_run_status_upv;
   boolean bLocalAcq_crk_eng_run_upvb0;
   boolean bLocalAcq_incam_tooth_det_upvb0;


   VEMS_vidGET(Acq_crk_eng_run_status_upvb0, bLocalAcq_crk_eng_run_status_upv);
   VEMS_vidGET(Acq_crk_eng_run_upvb0, bLocalAcq_crk_eng_run_upvb0);
   VEMS_vidGET(Acq_incam_tooth_det_upvb0, bLocalAcq_incam_tooth_det_upvb0);

   if (  (bLocalAcq_crk_eng_run_upvb0 == 0)
      && (bLocalAcq_crk_eng_run_status_upv != 0)
      && (bLocalAcq_incam_tooth_det_upvb0 == 0))
   {
      SYNCCKCMMONDIAG_vidClEveCkMonRst();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClEveCkMonRst                           */
/* !Description :  Function-Call Generator                                    */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSigCkMonRst();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SYNCCKCMMONDIAG_vidLossCkMonRst();                       */
/*  input boolean Sync_bDgoNoSigCk;                                           */
/*  input boolean Sync_bMonRunNoSigCk;                                        */
/*  input boolean Sync_bDgoSigLossCk;                                         */
/*  input boolean Sync_bMonRunSigLossCk;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClEveCkMonRst(void)
{
   SYNCCKCMMONDIAG_vidNoSigCkMonRst();
   GDGAR_vidGdu(GD_DFT_NOSIGCK,
                Sync_bDgoNoSigCk,
                Sync_bMonRunNoSigCk,
                DIAG_DISPO);
   SYNCCKCMMONDIAG_vidLossCkMonRst();
   GDGAR_vidGdu(GD_DFT_SIGLOSSCK,
                Sync_bDgoSigLossCk,
                Sync_bMonRunSigLossCk,
                DIAG_DISPO);
}
/*------------------------------- end of file --------------------------------*/