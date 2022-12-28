/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKDIAG                                              */
/* !Description     : SYNCCKDIAG Component                                    */
/*                                                                            */
/* !Module          : SYNCCKDIAG                                              */
/* !Description     : STATUT ET DIAGNOSTIC DU SIGNAL VILEBREQUIN              */
/*                                                                            */
/* !File            : SYNCCKDIAG_FCT1.C                                       */
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
/*   1 / SYNCCKDIAG_vidInitOutput                                             */
/*   2 / SYNCCKDIAG_vidEventGeneration                                        */
/*   3 / SYNCCKDIAG_vidCrkDgnUpdateInReq                                      */
/*   4 / SYNCCKDIAG_vidCrkLngToothTmpDiag                                     */
/*   5 / SYNCCKDIAG_vidResetDiag                                              */
/*   6 / SYNCCKDIAG_vidCkStsAcq                                               */
/*   7 / SYNCCKDIAG_vidCrkInvalToothDiag                                      */
/*   8 / SYNCCKDIAG_vidCrkInvalTeethDiag                                      */
/*   9 / SYNCCKDIAG_vidCrkLngLtoo1Diag                                        */
/*   10 / SYNCCKDIAG_vidCkAcqVld                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6886036 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKDIAG/SYNCCKDIAG_FCT1.C_$*/
/* $Revision::   1.4      $$Author::   wbouach        $$Date::   29 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   29 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "SYNCCKDIAG.h"
#include "SYNCCKDIAG_L.h"
#include "SYNCCKDIAG_IM.h"
#include "CRKHAL.h"
#include "DGOHAL.h"
#include "SYNCCKDIAG_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidInitOutput                                   */
/* !Description :  fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bCkAcqVld;                                            */
/*  output boolean SYNCCKDIAG_bDgoCkSigPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidInitOutput(void)
{
   VEMS_vidSET(Sync_bCkAcqVld, 0);
   SYNCCKDIAG_bDgoCkSigPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidEventGeneration                              */
/* !Description :  cette fonction  génère les évènements selon quand le moteur*/
/*                 n’est pas synchronisé.                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCCKDIAG_vidCrkDgnUpdateInReq();                       */
/*  extf argret void SYNCCKDIAG_vidCrkLngToothTmpDiag();                      */
/*  input boolean Moteur_synchronise;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidEventGeneration(void)
{
   boolean bLocalMoteur_synchronise;


   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   if (bLocalMoteur_synchronise == 0)
   {
      SYNCCKDIAG_vidCrkDgnUpdateInReq();
      SYNCCKDIAG_vidCrkLngToothTmpDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidCrkDgnUpdateInReq                            */
/* !Description :  Le composant DGO possède quatre voies qui permettent de    */
/*                 diagnostiquer quatre défaillances                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  output boolean Acq_crk_tooth_less_upd_upvb0;                              */
/*  output boolean Acq_crk_tooth_less_upvb0;                                  */
/*  output boolean Acq_crk_tooth_more_upd_upvb0;                              */
/*  output boolean Acq_crk_tooth_more_upvb0;                                  */
/*  output boolean Acq_crk_long_tooth_nok_upd_upvb0;                          */
/*  output boolean Acq_crk_long_tooth_nok_upvb0;                              */
/*  output boolean Acq_crk_no_long_tooth_upd_upvb0;                           */
/*  output boolean Acq_crk_no_long_tooth_upvb0;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidCrkDgnUpdateInReq(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtCRANKSHAFT);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_CRK_TOO_MISS) != 0)
   {
      Acq_crk_tooth_less_upd_upvb0 = 1;

      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CRK_TOO_MISS) != 0)
      {
         Acq_crk_tooth_less_upvb0 = 1;
      }
      else
      {
         Acq_crk_tooth_less_upvb0 = 0;
      }

   }
   else
   {
      Acq_crk_tooth_less_upd_upvb0 = 0;
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_CRK_TOO_EXCESS) != 0)
   {
      Acq_crk_tooth_more_upd_upvb0 = 1;

      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CRK_TOO_EXCESS) != 0)
      {
         Acq_crk_tooth_more_upvb0 = 1;
      }
      else
      {
         Acq_crk_tooth_more_upvb0 = 0;
      }

   }
   else
   {
      Acq_crk_tooth_more_upd_upvb0 = 0;
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_CRK_LTOO) != 0)
   {
      Acq_crk_long_tooth_nok_upd_upvb0 = 1;

      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CRK_LTOO) != 0)
      {
         Acq_crk_long_tooth_nok_upvb0 = 1;
      }
      else
      {
         Acq_crk_long_tooth_nok_upvb0 = 0;
      }

   }
   else
   {
      Acq_crk_long_tooth_nok_upd_upvb0 = 0;
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_CRK_LTOO1) != 0)
   {
      Acq_crk_no_long_tooth_upd_upvb0 = 1;

      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CRK_LTOO1) != 0)
      {
         Acq_crk_no_long_tooth_upvb0 = 1;
      }
      else
      {
         Acq_crk_no_long_tooth_upvb0 = 0;
      }

   }
   else
   {
      Acq_crk_no_long_tooth_upd_upvb0 = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidCrkLngToothTmpDiag                           */
/* !Description :  fonction de la non reconnaissance de la dent longue lors de*/
/*                 la synchronisation moteur, le défaut NoGap et              */
/*                 l’autorisation de diagnostic sont calculés à l’événement   */
/*                 Event_crk_dgn_no_gap_t_det                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Acq_crk_no_gap_diag_ena_upcb0;                              */
/*  input boolean Acq_crk_no_long_tooth_upd_upvb0;                            */
/*  input boolean Acq_crk_no_long_tooth_upvb0;                                */
/*  output boolean Sync_bDft_NoGap_CkSts;                                     */
/*  output boolean Sync_bEna_NoGap_CkSts;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidCrkLngToothTmpDiag(void)
{
   if (  (Acq_crk_no_gap_diag_ena_upcb0 != 0)
      && (Acq_crk_no_long_tooth_upd_upvb0 != 0))
   {
      if (Acq_crk_no_long_tooth_upvb0 != 0)
      {
         VEMS_vidSET(Sync_bDft_NoGap_CkSts, 1);
      }
      else
      {
         VEMS_vidSET(Sync_bDft_NoGap_CkSts, 0);
      }
      VEMS_vidSET(Sync_bEna_NoGap_CkSts, 1);
   }
   else
   {
      VEMS_vidSET(Sync_bEna_NoGap_CkSts, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidResetDiag                                    */
/* !Description :  cette fonction initialise les défauts et les autorisations */
/*                 de diagnostic à 0 au Reset.                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_vidSetMode(argin CRKHAL_tenuMode enuMode);        */
/*  output boolean Sync_bDft_ToothCoh_CkSts;                                  */
/*  output boolean Sync_bEna_ToothCoh_CkSts;                                  */
/*  output boolean Sync_bDft_HiToothCoh_CkSts;                                */
/*  output boolean Sync_bEna_HiToothCoh_CkSts;                                */
/*  output boolean Sync_bDft_NoGap_CkSts;                                     */
/*  output boolean Sync_bEna_NoGap_CkSts;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidResetDiag(void)
{
   VEMS_vidSET(Sync_bDft_ToothCoh_CkSts, 0);
   VEMS_vidSET(Sync_bEna_ToothCoh_CkSts, 0);
   VEMS_vidSET(Sync_bDft_HiToothCoh_CkSts, 0);
   VEMS_vidSET(Sync_bEna_HiToothCoh_CkSts, 0);
   VEMS_vidSET(Sync_bDft_NoGap_CkSts, 0);
   VEMS_vidSET(Sync_bEna_NoGap_CkSts, 0);
   CRKHAL_vidSetMode(CRKHAL_udtNORMAL_MODE);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidCkStsAcq                                     */
/* !Description :  L’appel au service CrkHALRead nous retourne des booléens   */
/*                 pour : le signal vilebrequin détecté,  le passage à moteur */
/*                 tournant via le signal vilebrequin, la synchronisation du  */
/*                 moteur.                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  CRKHAL_udtReadStatus(argin uint8 u8Channel,   */
/*  argout boolean *pbStatus);                                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acq_crk_sync_status_upvb0;                                 */
/*  output boolean Acq_crk_sync_upvb0;                                        */
/*  output boolean Acq_crk_tooth_det_status_upvb0;                            */
/*  output boolean Acq_crk_tooth_det_upvb0;                                   */
/*  output boolean Acq_crk_eng_run_status_upvb0;                              */
/*  output boolean Acq_crk_eng_run_upvb0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidCkStsAcq(void)
{
   boolean bLocalAcq_crk_eng_run_st_upvb0;
   boolean bLocalAcq_crk_eng_run_upvb0;
   boolean bLocalAcq_crk_sync_status_upvb0;
   boolean bLocalAcq_crk_sync_upvb0;
   boolean bLocalAcq_crk_tooth_det_st_upvb0;
   boolean bLocalAcq_crk_tooth_det_upvb0;
   boolean bLocalCRKHALReadStatus;


   bLocalCRKHALReadStatus =
      CRKHAL_udtReadStatus(CRKHAL_u8SYNCHRONISED,
                           &bLocalAcq_crk_sync_upvb0);
   if (bLocalCRKHALReadStatus == E_OK)
   {
      bLocalAcq_crk_sync_status_upvb0 = 1;
   }
   else
   {
      bLocalAcq_crk_sync_status_upvb0 = 0;
   }
   VEMS_vidSET(Acq_crk_sync_status_upvb0,bLocalAcq_crk_sync_status_upvb0);
   VEMS_vidSET(Acq_crk_sync_upvb0,bLocalAcq_crk_sync_upvb0);

   bLocalCRKHALReadStatus =
      CRKHAL_udtReadStatus(CRKHAL_u8DETECTED,
                           &bLocalAcq_crk_tooth_det_upvb0);
   if (bLocalCRKHALReadStatus == E_OK)
   {
      bLocalAcq_crk_tooth_det_st_upvb0 = 1;
   }
   else
   {
      bLocalAcq_crk_tooth_det_st_upvb0 = 0;
   }
   VEMS_vidSET(Acq_crk_tooth_det_status_upvb0,
               bLocalAcq_crk_tooth_det_st_upvb0);
   VEMS_vidSET(Acq_crk_tooth_det_upvb0,
               bLocalAcq_crk_tooth_det_upvb0);

   bLocalCRKHALReadStatus =
      CRKHAL_udtReadStatus(CRKHAL_u8RUNNING,
                           &bLocalAcq_crk_eng_run_upvb0);
   if (bLocalCRKHALReadStatus == E_OK)
   {
      bLocalAcq_crk_eng_run_st_upvb0 = 1;
   }
   else
   {
      bLocalAcq_crk_eng_run_st_upvb0 = 0;
   }
   VEMS_vidSET(Acq_crk_eng_run_status_upvb0,bLocalAcq_crk_eng_run_st_upvb0);
   VEMS_vidSET(Acq_crk_eng_run_upvb0,bLocalAcq_crk_eng_run_upvb0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidCrkInvalToothDiag                            */
/* !Description :  fonction de la non détection d’une dent dans un tour       */
/*                 vilebrequin                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Acq_crk_tooth_l_diag_ena_upcb0;                             */
/*  input boolean Acq_crk_tooth_less_upd_upvb0;                               */
/*  input boolean Acq_crk_tooth_more_upd_upvb0;                               */
/*  input boolean Acq_crk_tooth_more_upvb0;                                   */
/*  input boolean Acq_crk_tooth_less_upvb0;                                   */
/*  output boolean Sync_bEna_ToothCoh_CkSts;                                  */
/*  output boolean Sync_bDft_ToothCoh_CkSts;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidCrkInvalToothDiag(void)
{
   if (  (  Acq_crk_tooth_l_diag_ena_upcb0 != 0)
      && (  (Acq_crk_tooth_less_upd_upvb0 != 0)
         || (Acq_crk_tooth_more_upd_upvb0 != 0)))
   {
      VEMS_vidSET(Sync_bEna_ToothCoh_CkSts, 1);
      if (  (  (Acq_crk_tooth_more_upvb0 != 0)
            && (Acq_crk_tooth_more_upd_upvb0 != 0))
         || (  (Acq_crk_tooth_less_upvb0 != 0)
            && (Acq_crk_tooth_less_upd_upvb0 != 0)))
      {
         VEMS_vidSET(Sync_bDft_ToothCoh_CkSts, 1);
      }
      else
      {
         VEMS_vidSET(Sync_bDft_ToothCoh_CkSts, 0);
      }
   }
   else
   {
      VEMS_vidSET(Sync_bEna_ToothCoh_CkSts, 0);
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidCrkInvalTeethDiag                            */
/* !Description :  fonction de a non détection de la dent longue ou de        */
/*                 plusieurs dents consécutives dans un tour vilebrequin      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Acq_crk_tooth_h_diag_ena_upcb0;                             */
/*  input boolean Acq_crk_long_tooth_nok_upd_upvb0;                           */
/*  input boolean Acq_crk_long_tooth_nok_upvb0;                               */
/*  output boolean Sync_bDft_HiToothCoh_CkSts;                                */
/*  output boolean Sync_bEna_HiToothCoh_CkSts;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidCrkInvalTeethDiag(void)
{
   if (  (Acq_crk_tooth_h_diag_ena_upcb0 != 0)
      && (Acq_crk_long_tooth_nok_upd_upvb0 != 0))
   {
      if (Acq_crk_long_tooth_nok_upvb0 != 0)
      {
         VEMS_vidSET(Sync_bDft_HiToothCoh_CkSts, 1);
      }
      else
      {
         VEMS_vidSET(Sync_bDft_HiToothCoh_CkSts, 0);
      }
      VEMS_vidSET(Sync_bEna_HiToothCoh_CkSts, 1);
   }
   else
   {
      VEMS_vidSET(Sync_bEna_HiToothCoh_CkSts, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidCrkLngLtoo1Diag                              */
/* !Description :  fonction de la non reconnaissance de la dent longue lors de*/
/*                 la synchronisation moteur, le défaut NoGap et              */
/*                 l’autorisation de diagnostic sont calculés à l’événement   */
/*                 Event_crk_dgn_no_gap_det                                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Acq_crk_long_tooth_nok_upd_upvb0;                           */
/*  input boolean Sync_bDft_HiToothCoh_CkSts;                                 */
/*  input boolean Acq_crk_no_gap_diag_ena_upcb0;                              */
/*  input boolean Acq_crk_no_long_tooth_upd_upvb0;                            */
/*  input boolean Acq_crk_no_gap_cond_dec_upvb0;                              */
/*  input boolean Acq_crk_no_gap_cond_inc_upvb0;                              */
/*  input boolean Acq_crk_no_long_tooth_upvb0;                                */
/*  output boolean Acq_crk_no_gap_cond_dec_upvb0;                             */
/*  output boolean Acq_crk_no_gap_cond_inc_upvb0;                             */
/*  output boolean Sync_bEna_NoGap_CkSts;                                     */
/*  output boolean Sync_bDft_NoGap_CkSts;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidCrkLngLtoo1Diag(void)
{
   boolean bLocalSyncbDftHiToothCohCkSts;


   VEMS_vidGET(Sync_bDft_HiToothCoh_CkSts, bLocalSyncbDftHiToothCohCkSts);

   if (  (Acq_crk_long_tooth_nok_upd_upvb0 != 0)
      && (bLocalSyncbDftHiToothCohCkSts == 0))
   {
      Acq_crk_no_gap_cond_dec_upvb0 = 1;
   }
   else
   {
      Acq_crk_no_gap_cond_dec_upvb0 = 0;
   }

   if (  (Acq_crk_no_gap_diag_ena_upcb0 != 0)
      && (Acq_crk_no_long_tooth_upd_upvb0 != 0))
   {
      Acq_crk_no_gap_cond_inc_upvb0 = 1;
      VEMS_vidSET(Sync_bEna_NoGap_CkSts, 1);
   }
   else
   {
      Acq_crk_no_gap_cond_inc_upvb0 = 0;
      if (Acq_crk_no_gap_cond_dec_upvb0 != 0)
      {
         VEMS_vidSET(Sync_bEna_NoGap_CkSts, 1);
      }
      else
      {
         VEMS_vidSET(Sync_bEna_NoGap_CkSts, 0);
      }
   }

   if (  (Acq_crk_no_gap_cond_inc_upvb0 != 0)
      && (Acq_crk_no_gap_cond_dec_upvb0 != 0))
   {
      VEMS_vidSET(Sync_bDft_NoGap_CkSts, 0);
   }
   else
   {
      if (Acq_crk_no_gap_cond_inc_upvb0 != 0)
      {
         if (Acq_crk_no_long_tooth_upvb0 != 0)
         {
            VEMS_vidSET(Sync_bDft_NoGap_CkSts, 1);
         }
         else
         {
            VEMS_vidSET(Sync_bDft_NoGap_CkSts, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidCkAcqVld                                     */
/* !Description :  cette fonction spécifie la validité de l’acquisition du    */
/*                 capteur vilebrequin.                                       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sync_bDft_HiToothCoh_CkSts;                                 */
/*  input boolean Sync_bEna_HiToothCoh_CkSts;                                 */
/*  input boolean Sync_bDft_NoGap_CkSts;                                      */
/*  input boolean Sync_bEna_NoGap_CkSts;                                      */
/*  output boolean Sync_bCkAcqVld;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidCkAcqVld(void)
{
   boolean bLocalSyncbDftHiToothCohCkSts;
   boolean bLocalSyncbEnaHiToothCohCkSts;
   boolean bLocalSync_bDft_NoGap_CkSts;
   boolean bLocalSync_bEna_NoGap_CkSts;


   VEMS_vidGET(Sync_bDft_HiToothCoh_CkSts, bLocalSyncbDftHiToothCohCkSts);
   VEMS_vidGET(Sync_bEna_HiToothCoh_CkSts, bLocalSyncbEnaHiToothCohCkSts);
   VEMS_vidGET(Sync_bDft_NoGap_CkSts, bLocalSync_bDft_NoGap_CkSts);
   VEMS_vidGET(Sync_bEna_NoGap_CkSts, bLocalSync_bEna_NoGap_CkSts);

   if (  (  (bLocalSyncbDftHiToothCohCkSts == 0)
         && (bLocalSyncbEnaHiToothCohCkSts != 0))
      || (  (bLocalSync_bDft_NoGap_CkSts == 0)
         && (bLocalSync_bEna_NoGap_CkSts != 0)))
   {
      VEMS_vidSET(Sync_bCkAcqVld, 1);
   }
   else
   {
      VEMS_vidSET(Sync_bCkAcqVld, 0);
   }
}

/*------------------------------- end of file --------------------------------*/