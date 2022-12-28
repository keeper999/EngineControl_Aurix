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
/* !File            : SYNCCKCMMONDIAG_FCT5.C                                  */
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
/*   1 / SYNCCKCMMONDIAG_vidCmnCdnInCmDgo                                     */
/*   2 / SYNCCKCMMONDIAG_vidNoSgInCmIni                                       */
/*   3 / SYNCCKCMMONDIAG_vidNoSgInCmCl                                        */
/*   4 / SYNCCKCMMONDIAG_vidClDgoNoSgInCm                                     */
/*   5 / SYNCCKCMMONDIAG_vidLossInCmIni                                       */
/*   6 / SYNCCKCMMONDIAG_vidLossInCmCl                                        */
/*   7 / SYNCCKCMMONDIAG_vidClDgoLossInCm                                     */
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
#include "MATHSRV.h"
#include "SYNCCKCMMONDIAG.h"
#include "SYNCCKCMMONDIAG_L.h"
#include "SYNCCKCMMONDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidCmnCdnInCmDgo                           */
/* !Description :  Ce  bloc  génère  le  booléen  Sync_bCmnCdnInCmDiag  qui   */
/*                 indique,  lorsqu’il  est  à  ON,  que  les  conditions     */
/*                 communes de test de perte ou d’absence du signal arbre à   */
/*                 cames admissions sont remplies                             */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_crk_eng_run_upvb0;                                      */
/*  input boolean Sync_bCkAcqVld;                                             */
/*  input boolean SYNCCKCMMONDIAG_bAcqCrkEngInPrev;                           */
/*  input uint8 Acq_incam_count_evnt_upcn0;                                   */
/*  input uint8 SYNCCKCMMONDIAG_u8InCmTimerCnt;                               */
/*  input boolean Sync_bMinTimeElpdInCam;                                     */
/*  input boolean Acq_incam_no_sgnl_diag_ena_upcb0;                           */
/*  output uint8 SYNCCKCMMONDIAG_u8InCmTimerCnt;                              */
/*  output boolean Sync_bMinTimeElpdInCam;                                    */
/*  output boolean SYNCCKCMMONDIAG_bAcqCrkEngInPrev;                          */
/*  output boolean Sync_bCmnCdnInCmDiag;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidCmnCdnInCmDgo(void)
{
   boolean bLocalInhNoSigSigLossInCmDiag;
   boolean bLocalAcq_crk_eng_run_upvb0;
   boolean bLocalSync_bCkAcqVld;
   uint8   u8LocalTimerCnt;


   bLocalInhNoSigSigLossInCmDiag =
      GDGAR_bGetFRM(FRM_FRM_INHNOSIGSIGLOSSINCMDIAG);

   VEMS_vidGET(Acq_crk_eng_run_upvb0, bLocalAcq_crk_eng_run_upvb0);
   VEMS_vidGET(Sync_bCkAcqVld, bLocalSync_bCkAcqVld);

   if (  (SYNCCKCMMONDIAG_bAcqCrkEngInPrev == 0)
      && (bLocalAcq_crk_eng_run_upvb0 != 0))
   {
      SYNCCKCMMONDIAG_u8InCmTimerCnt =
         (uint8)MATHSRV_udtMIN(Acq_incam_count_evnt_upcn0, 250);
      if (SYNCCKCMMONDIAG_u8InCmTimerCnt == 0)
      {
         Sync_bMinTimeElpdInCam = 1;
      }
      else
      {
         Sync_bMinTimeElpdInCam = 0;
      }
   }
   else
   {
      if (SYNCCKCMMONDIAG_u8InCmTimerCnt > 0)
      {
         u8LocalTimerCnt = (uint8)(SYNCCKCMMONDIAG_u8InCmTimerCnt - 1);
         SYNCCKCMMONDIAG_u8InCmTimerCnt = (uint8)MATHSRV_udtMIN(u8LocalTimerCnt,
                                                                250);
         if (SYNCCKCMMONDIAG_u8InCmTimerCnt == 0)
         {
            Sync_bMinTimeElpdInCam = 1;
         }
         else
         {
            Sync_bMinTimeElpdInCam = 0;
         }
      }
   }
   SYNCCKCMMONDIAG_bAcqCrkEngInPrev = bLocalAcq_crk_eng_run_upvb0;

   if (  (Sync_bMinTimeElpdInCam != 0)
      && (Acq_incam_no_sgnl_diag_ena_upcb0 != 0)
      && (bLocalSync_bCkAcqVld != 0)
      && (bLocalInhNoSigSigLossInCmDiag == 0))
   {
      Sync_bCmnCdnInCmDiag = 1;
   }
   else
   {
      Sync_bCmnCdnInCmDiag = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidNoSgInCmIni                             */
/* !Description :  Au réveil ECU et à chaque KEY OFF  ON, la panne           */
/*                 élémentaire et les conditions de diagnostics sont remises à*/
/*                 zéro.                                                      */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunNoSigInCm;                                     */
/*  output boolean Sync_bDgoNoSigInCm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidNoSgInCmIni(void)
{
   Sync_bMonRunNoSigInCm = 0;
   Sync_bDgoNoSigInCm = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidNoSgInCmCl                              */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide.                                             */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidClDgoNoSgInCm();                      */
/*  input boolean Sync_bCmnCdnInCmDiag;                                       */
/*  output boolean Sync_bMonRunNoSigInCm;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidNoSgInCmCl(void)
{
   if (Sync_bCmnCdnInCmDiag != 0)
   {
      Sync_bMonRunNoSigInCm = 1;
      SYNCCKCMMONDIAG_vidClDgoNoSgInCm();
   }
   else
   {
      Sync_bMonRunNoSigInCm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClDgoNoSgInCm                           */
/* !Description :  Une panne élémentaire est détectée si les conditions de    */
/*                 diagnostic sont remplies (Sync_bCmnCdnInCmDiag = ON) et    */
/*                 qu’il n’ y a pas de mouvement détecté sur l’arbre à cames  */
/*                 admission (Acq_incam_tooth_det_upvb0 = OFF).               */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_incam_tooth_det_upvb0;                                  */
/*  input boolean Acq_incam_tooth_det_vld_upvb0;                              */
/*  output boolean Sync_bDgoNoSigInCm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClDgoNoSgInCm(void)
{
   boolean bLocalAcq_incam_tooth_det_upvb0;
   boolean bLocalAcq_incam_tooth_det_vld_up;


   VEMS_vidGET(Acq_incam_tooth_det_upvb0, bLocalAcq_incam_tooth_det_upvb0);
   VEMS_vidGET(Acq_incam_tooth_det_vld_upvb0, bLocalAcq_incam_tooth_det_vld_up);

   if (  (bLocalAcq_incam_tooth_det_upvb0 == 0)
      && (bLocalAcq_incam_tooth_det_vld_up != 0))
   {
      Sync_bDgoNoSigInCm = 1;
   }
   else
   {
      Sync_bDgoNoSigInCm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidLossInCmIni                             */
/* !Description :  Au réveil ECU et à chaque KEY OFF   ON, la panne           */
/*                 élémentaire et les conditions de diagnostics sont remises  */
/*                 à zéro.                                                    */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunSigLossInCm;                                   */
/*  output boolean Sync_bDgoSigLossInCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidLossInCmIni(void)
{
   Sync_bMonRunSigLossInCm = 0;
   Sync_bDgoSigLossInCm = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidLossInCmCl                              */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide.                                             */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidClDgoLossInCm();                      */
/*  input boolean Sync_bCmnCdnInCmDiag;                                       */
/*  output boolean Sync_bMonRunSigLossInCm;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidLossInCmCl(void)
{
   if (Sync_bCmnCdnInCmDiag != 0)
   {
      Sync_bMonRunSigLossInCm = 1;
      SYNCCKCMMONDIAG_vidClDgoLossInCm();
   }
   else
   {
      Sync_bMonRunSigLossInCm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClDgoLossInCm                           */
/* !Description :  Une panne élémentaire est détectée si les conditions de    */
/*                 diagnostic sont remplies (Sync_bCmnCdnInCmDiag = ON) et    */
/*                 qu’il n’ y a pas de mouvement détecté sur l’arbre à cames  */
/*                 admission (Acq_incam_tooth_det_upvb0 = OFF).               */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_incam_tooth_det_upvb0;                                  */
/*  input boolean Acq_incam_tooth_det_vld_upvb0;                              */
/*  output boolean Sync_bDgoSigLossInCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClDgoLossInCm(void)
{
   boolean bLocalAcq_incam_tooth_det_upvb0;
   boolean bLocalAcq_incam_tooth_det_vld_up;


   VEMS_vidGET(Acq_incam_tooth_det_upvb0, bLocalAcq_incam_tooth_det_upvb0);
   VEMS_vidGET(Acq_incam_tooth_det_vld_upvb0, bLocalAcq_incam_tooth_det_vld_up);

   if (  (bLocalAcq_incam_tooth_det_upvb0 == 0)
      && (bLocalAcq_incam_tooth_det_vld_up != 0))
   {
      Sync_bDgoSigLossInCm = 1;
   }
   else
   {
      Sync_bDgoSigLossInCm = 0;
   }
}
/*------------------------------- end of file --------------------------------*/