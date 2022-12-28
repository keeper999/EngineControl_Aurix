/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKDIAGDIAG                                          */
/* !Description     : SYNCCKDIAGDIAG Component.                               */
/*                                                                            */
/* !Module          : SYNCCKDIAGDIAG                                          */
/* !Description     : Diagnostics du signal vilebrequin                       */
/*                                                                            */
/* !File            : SYNCCKDIAGDIAG_SCH.C                                    */
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
/*   1 / Sync_SdlMid_SyncCkDiagDiag                                           */
/*   2 / Sync_EveCkLTo_SyncCkDiagDiag                                         */
/*   3 / Sync_EveCkSnOf_SyncCkDiagDiag                                        */
/*   4 / Sync_EveCkSnOn_SyncCkDiagDiag                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6977224 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SYNCCKDIAGDIAG/SYNCCKDIAGDIAG_SCH.$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   12 Sep 2014 $*/
/* $Author::   wbouach                                $$Date::   12 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SYNCCKDIAGDIAG.h"
#include "SYNCCKDIAGDIAG_L.h"
#include "SYNCCKDIAGDIAG_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlMid_SyncCkDiagDiag                                 */
/* !Description :  Monitor moyen de la fonction Sync                          */
/* !Number      :  SCH.1                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SYNCCKDIAGDIAG_u8Inhib;                                       */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Sync_bDft_NoGap_CkSts;                                      */
/*  input boolean Sync_bEna_NoGap_CkSts;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlMid_SyncCkDiagDiag                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlMid_SyncCkDiagDiag(void)
{
   boolean bLocalMoteur_synchronise;
   boolean bLocalSync_bDft_NoGap_CkSts;
   boolean bLocalSync_bEna_NoGap_CkSts;


   if (SYNCCKDIAGDIAG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);

      if (bLocalMoteur_synchronise == 0)
      {
         VEMS_vidGET(Sync_bDft_NoGap_CkSts, bLocalSync_bDft_NoGap_CkSts);
         VEMS_vidGET(Sync_bEna_NoGap_CkSts, bLocalSync_bEna_NoGap_CkSts);

         GDGAR_vidGdu(GD_DFT_NOGAP_CKSTS,
                      bLocalSync_bDft_NoGap_CkSts,
                      bLocalSync_bEna_NoGap_CkSts,
                      DIAG_DISPO);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkLTo_SyncCkDiagDiag                               */
/* !Description :  Evénement correspondant au passage de la dent longue       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SYNCCKDIAGDIAG_u8Inhib;                                       */
/*  input boolean Sync_bDft_HiToothCoh_CkSts;                                 */
/*  input boolean Sync_bEna_HiToothCoh_CkSts;                                 */
/*  input boolean Sync_bDft_ToothCoh_CkSts;                                   */
/*  input boolean Sync_bEna_ToothCoh_CkSts;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkLTo_SyncCkDiagDiag                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkLTo_SyncCkDiagDiag(void)
{
   boolean bLocalSync_bDft_HiToothCoh_CkSts;
   boolean bLocalSync_bEna_HiToothCoh_CkSts;
   boolean bLocalSync_bDft_ToothCoh_CkSts;
   boolean bLocalSync_bEna_ToothCoh_CkSts;


   if (SYNCCKDIAGDIAG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Sync_bDft_HiToothCoh_CkSts, bLocalSync_bDft_HiToothCoh_CkSts);
      VEMS_vidGET(Sync_bEna_HiToothCoh_CkSts, bLocalSync_bEna_HiToothCoh_CkSts);
      VEMS_vidGET(Sync_bDft_ToothCoh_CkSts, bLocalSync_bDft_ToothCoh_CkSts);
      VEMS_vidGET(Sync_bEna_ToothCoh_CkSts, bLocalSync_bEna_ToothCoh_CkSts);

      GDGAR_vidGdu(GD_DFT_HITOOTHCOH_CKSTS,
                   bLocalSync_bDft_HiToothCoh_CkSts,
                   bLocalSync_bEna_HiToothCoh_CkSts,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_TOOTHCOH_CKSTS,
                   bLocalSync_bDft_ToothCoh_CkSts,
                   bLocalSync_bEna_ToothCoh_CkSts,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOf_SyncCkDiagDiag                              */
/* !Description :  Evènement détection fin de rotation moteur.                */
/* !Number      :  SCH.3                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SYNCCKDIAGDIAG_u8Inhib;                                       */
/*  input boolean Sync_bDft_HiToothCoh_CkSts;                                 */
/*  input boolean Sync_bEna_HiToothCoh_CkSts;                                 */
/*  input boolean Sync_bDft_ToothCoh_CkSts;                                   */
/*  input boolean Sync_bEna_ToothCoh_CkSts;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOf_SyncCkDiagDiag                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOf_SyncCkDiagDiag(void)
{
   boolean bLocalSync_bDft_HiToothCoh_CkSts;
   boolean bLocalSync_bEna_HiToothCoh_CkSts;
   boolean bLocalSync_bDft_ToothCoh_CkSts;
   boolean bLocalSync_bEna_ToothCoh_CkSts;


   if (SYNCCKDIAGDIAG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Sync_bDft_HiToothCoh_CkSts, bLocalSync_bDft_HiToothCoh_CkSts);
      VEMS_vidGET(Sync_bEna_HiToothCoh_CkSts, bLocalSync_bEna_HiToothCoh_CkSts);
      VEMS_vidGET(Sync_bDft_ToothCoh_CkSts, bLocalSync_bDft_ToothCoh_CkSts);
      VEMS_vidGET(Sync_bEna_ToothCoh_CkSts, bLocalSync_bEna_ToothCoh_CkSts);

      GDGAR_vidGdu(GD_DFT_HITOOTHCOH_CKSTS,
                   bLocalSync_bDft_HiToothCoh_CkSts,
                   bLocalSync_bEna_HiToothCoh_CkSts,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_TOOTHCOH_CKSTS,
                   bLocalSync_bDft_ToothCoh_CkSts,
                   bLocalSync_bEna_ToothCoh_CkSts,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOn_SyncCkDiagDiag                              */
/* !Description :  Evénement d'appel de tâche "synchro perdue" du CMM (à la   */
/*                 perte de synchro  et au calage)                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SYNCCKDIAGDIAG_u8Inhib;                                       */
/*  input boolean Sync_bDft_NoGap_CkSts;                                      */
/*  input boolean Sync_bEna_NoGap_CkSts;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOn_SyncCkDiagDiag                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOn_SyncCkDiagDiag(void)
{
   boolean bLocalSync_bDft_NoGap_CkSts;
   boolean bLocalSync_bEna_NoGap_CkSts;


   if (SYNCCKDIAGDIAG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Sync_bDft_NoGap_CkSts, bLocalSync_bDft_NoGap_CkSts);
      VEMS_vidGET(Sync_bEna_NoGap_CkSts, bLocalSync_bEna_NoGap_CkSts);

      GDGAR_vidGdu(GD_DFT_NOGAP_CKSTS,
                   bLocalSync_bDft_NoGap_CkSts,
                   bLocalSync_bEna_NoGap_CkSts,
                   DIAG_DISPO);
   }
}
/************************************* end of file ****************************/