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
/* !File            : SYNCCKCMMONDIAG_FCT6.C                                  */
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
/*   1 / SYNCCKCMMONDIAG_vidCmnCdnExCmDgo                                     */
/*   2 / SYNCCKCMMONDIAG_vidNoSgExCmIni                                       */
/*   3 / SYNCCKCMMONDIAG_vidNoSgExCmMonCl                                     */
/*   4 / SYNCCKCMMONDIAG_vidClDgoNoSgExCm                                     */
/*   5 / SYNCCKCMMONDIAG_vidLossExCmIni                                       */
/*   6 / SYNCCKCMMONDIAG_vidLossExCmCl                                        */
/*   7 / SYNCCKCMMONDIAG_vidClDgoLossExCm                                     */
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
/* !Function    :  SYNCCKCMMONDIAG_vidCmnCdnExCmDgo                           */
/* !Description :  Ce  bloc  génère  le  booléen  Sync_bCmnCdnExCmDiag  qui   */
/*                 indique,  lorsqu’il  est  à  ON,  que  les  conditions     */
/*                 communes de test de perte ou d’absence du signal arbre à   */
/*                 cames échappements sont remplies                           */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_crk_eng_run_upvb0;                                      */
/*  input boolean Sync_bCkAcqVld;                                             */
/*  input boolean SYNCCKCMMONDIAG_bAcqCrkEngExPrev;                           */
/*  input uint8 Acq_excam_count_evnt_upcn0;                                   */
/*  input uint8 SYNCCKCMMONDIAG_u8ExCmTimerCnt;                               */
/*  input boolean Sync_bMinTimeElpdExCam;                                     */
/*  input boolean Acq_excam_no_sgnl_diag_ena_upcb0;                           */
/*  output uint8 SYNCCKCMMONDIAG_u8ExCmTimerCnt;                              */
/*  output boolean Sync_bMinTimeElpdExCam;                                    */
/*  output boolean SYNCCKCMMONDIAG_bAcqCrkEngExPrev;                          */
/*  output boolean Sync_bCmnCdnExCmDiag;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidCmnCdnExCmDgo(void)
{
   boolean bLocalInhNoSigSigLossExCmDiag;
   boolean bLocalAcq_crk_eng_run_upvb0;
   boolean bLocalSync_bCkAcqVld;
   uint8   u8LocalTimerCnt;


   bLocalInhNoSigSigLossExCmDiag =
      GDGAR_bGetFRM(FRM_FRM_INHNOSIGSIGLOSSEXCMDIAG);

   VEMS_vidGET(Acq_crk_eng_run_upvb0, bLocalAcq_crk_eng_run_upvb0);
   VEMS_vidGET(Sync_bCkAcqVld, bLocalSync_bCkAcqVld);

   if (  (SYNCCKCMMONDIAG_bAcqCrkEngExPrev == 0)
      && (bLocalAcq_crk_eng_run_upvb0 != 0))
   {
      SYNCCKCMMONDIAG_u8ExCmTimerCnt =
         (uint8)MATHSRV_udtMIN(Acq_excam_count_evnt_upcn0, 250);
      if (SYNCCKCMMONDIAG_u8ExCmTimerCnt == 0)
      {
         Sync_bMinTimeElpdExCam = 1;
      }
      else
      {
         Sync_bMinTimeElpdExCam = 0;
      }
   }
   else
   {
      if (SYNCCKCMMONDIAG_u8ExCmTimerCnt > 0)
      {
         u8LocalTimerCnt = (uint8)(SYNCCKCMMONDIAG_u8ExCmTimerCnt - 1);
         SYNCCKCMMONDIAG_u8ExCmTimerCnt = (uint8)MATHSRV_udtMIN(u8LocalTimerCnt,
                                                                250);
         if (SYNCCKCMMONDIAG_u8ExCmTimerCnt == 0)
         {
            Sync_bMinTimeElpdExCam = 1;
         }
         else
         {
            Sync_bMinTimeElpdExCam = 0;
         }
      }
   }
   SYNCCKCMMONDIAG_bAcqCrkEngExPrev = bLocalAcq_crk_eng_run_upvb0;

   if (  (Sync_bMinTimeElpdExCam != 0)
      && (Acq_excam_no_sgnl_diag_ena_upcb0 != 0)
      && (bLocalSync_bCkAcqVld != 0)
      && (bLocalInhNoSigSigLossExCmDiag == 0))
   {
      Sync_bCmnCdnExCmDiag = 1;
   }
   else
   {
      Sync_bCmnCdnExCmDiag = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidNoSgExCmIni                             */
/* !Description :  Au réveil ECU et à chaque KEY OFF  ON, la panne           */
/*                 élémentaire et les conditions de diagnostics sont remises à*/
/*                 zero                                                       */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunNoSigExCm;                                     */
/*  output boolean Sync_bDgoNoSigExCm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidNoSgExCmIni(void)
{
   Sync_bMonRunNoSigExCm = 0;
   Sync_bDgoNoSigExCm = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidNoSgExCmMonCl                           */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide.                                             */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidClDgoNoSgExCm();                      */
/*  input boolean Sync_bCmnCdnExCmDiag;                                       */
/*  output boolean Sync_bMonRunNoSigExCm;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidNoSgExCmMonCl(void)
{
   if (Sync_bCmnCdnExCmDiag != 0)
   {
      Sync_bMonRunNoSigExCm = 1;
      SYNCCKCMMONDIAG_vidClDgoNoSgExCm();
   }
   else
   {
      Sync_bMonRunNoSigExCm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClDgoNoSgExCm                           */
/* !Description :  Une panne élémentaire est détectée si les conditions de    */
/*                 diagnostic sont remplies (Sync_bCmnCdnExCmDiag = ON) et    */
/*                 qu’il n’ y a pas de mouvement détecté sur l’arbre à cames  */
/*                 échappement (Acq_excam_tooth_det_upvb0 = OFF).             */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_excam_tooth_det_upvb0;                                  */
/*  input boolean Acq_excam_tooth_det_vld_upvb0;                              */
/*  output boolean Sync_bDgoNoSigExCm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClDgoNoSgExCm(void)
{
   boolean bLocalAcq_excam_tooth_det_upvb0;
   boolean bLocalAcq_excam_tooth_det_vld_up;


   VEMS_vidGET(Acq_excam_tooth_det_upvb0, bLocalAcq_excam_tooth_det_upvb0);
   VEMS_vidGET(Acq_excam_tooth_det_vld_upvb0, bLocalAcq_excam_tooth_det_vld_up);

   if (  (bLocalAcq_excam_tooth_det_upvb0 == 0)
      && (bLocalAcq_excam_tooth_det_vld_up != 0))
   {
      Sync_bDgoNoSigExCm = 1;
   }
   else
   {
      Sync_bDgoNoSigExCm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidLossExCmIni                             */
/* !Description :  Au réveil ECU et à chaque KEY OFF  ON, la panne           */
/*                 élémentaire et les conditions de diagnostics sont remises à*/
/*                 zéro.                                                      */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunSigLossExCm;                                   */
/*  output boolean Sync_bDgoSigLossExCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidLossExCmIni(void)
{
   Sync_bMonRunSigLossExCm = 0;
   Sync_bDgoSigLossExCm = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidLossExCmCl                              */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide.                                             */
/* !Number      :  FCT6.6                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidClDgoLossExCm();                      */
/*  input boolean Sync_bCmnCdnExCmDiag;                                       */
/*  output boolean Sync_bMonRunSigLossExCm;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidLossExCmCl(void)
{
   if (Sync_bCmnCdnExCmDiag != 0)
   {
      Sync_bMonRunSigLossExCm = 1;
      SYNCCKCMMONDIAG_vidClDgoLossExCm();
   }
   else
   {
      Sync_bMonRunSigLossExCm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClDgoLossExCm                           */
/* !Description :  Une panne élémentaire est détectée si les conditions de    */
/*                 diagnostic sont remplies (Sync_bCmnCdnExCmDiag = ON) et    */
/*                 qu’il n’ y a pas de mouvement détecté sur l’arbre à cames  */
/*                 échappement (Acq_excam_tooth_det_upvb0 = OFF).             */
/* !Number      :  FCT6.7                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_excam_tooth_det_upvb0;                                  */
/*  input boolean Acq_excam_tooth_det_vld_upvb0;                              */
/*  output boolean Sync_bDgoSigLossExCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClDgoLossExCm(void)
{
   boolean bLocalAcq_excam_tooth_det_upvb0;
   boolean bLocalAcq_excam_tooth_det_vld_up;


   VEMS_vidGET(Acq_excam_tooth_det_upvb0, bLocalAcq_excam_tooth_det_upvb0);
   VEMS_vidGET(Acq_excam_tooth_det_vld_upvb0, bLocalAcq_excam_tooth_det_vld_up);

   if (  (bLocalAcq_excam_tooth_det_upvb0 == 0)
      && (bLocalAcq_excam_tooth_det_vld_up != 0))
   {
      Sync_bDgoSigLossExCm = 1;
   }
   else
   {
      Sync_bDgoSigLossExCm = 0;
   }
}
/*------------------------------- end of file --------------------------------*/