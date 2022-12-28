/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STRTLOCKACQ                                             */
/* !Description     : STRTLOCKACQ component.                                  */
/*                                                                            */
/* !Module          : STRTLOCKACQ                                             */
/* !Description     : ACQUISITION DE L’INFORMATION START LOCK BV .            */
/*                                                                            */
/* !File            : STRTLOCKACQ_FCT1.C                                      */
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
/*   1 / STRTLOCKACQ_vidInitialisation                                        */
/*   2 / STRTLOCKACQ_vidOS                                                    */
/*   3 / STRTLOCKACQ_vidStrtLockAcq                                           */
/*   4 / STRTLOCKACQ_vidDiagnostic                                            */
/*   5 / STRTLOCKACQ_vidDefautStrtLock                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6530087 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/STRTLOCKACQ/STRTLOCKACQ_FCT1.C_v  $*/
/* $Revision::   1.6      $$Author::   achebino       $$Date::   27 May 2014 $*/
/* $Author::   achebino                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "STRTLOCKACQ.h"
#include "STRTLOCKACQ_L.h"
#include "STRTLOCKACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTLOCKACQ_vidInitialisation                              */
/* !Description :  Au réveil calculateur, on interdit le démarrage.           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_09_04489_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bStrtAuth;                                             */
/*  output boolean Ext_bStrtLockAcqRaw;                                       */
/*  output boolean Ext_bDrvTraAMT;                                            */
/*  output boolean Ext_bATParkNeut;                                           */
/*  output boolean STRTLOCKACQ_bDebouncingFilSig;                             */
/*  output uint8 STRTLOCKACQ_u8DebouncingFiltCnt;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTLOCKACQ_vidInitialisation(void)
{
   VEMS_vidSET(Ext_bStrtAuth, 0);
   VEMS_vidSET(Ext_bStrtLockAcqRaw, 1);
   VEMS_vidSET(Ext_bDrvTraAMT, 0);
   VEMS_vidSET(Ext_bATParkNeut, 0);

   /* Initialization of the debouncing filtre parameters */
   STRTLOCKACQ_bDebouncingFilSig = 1;
   STRTLOCKACQ_u8DebouncingFiltCnt = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTLOCKACQ_vidOS                                          */
/* !Description :  Ce bloc génère les évènements permettant le calcul de      */
/*                 l’information du capteur Start-Lock uniquement dans le cas */
/*                 d’une boite de vitesse automatique ou d’une boite de       */
/*                 vitesse manuelle pilotée.                                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void STRTLOCKACQ_vidStrtLockAcq();                            */
/*  extf argret void STRTLOCKACQ_vidDiagnostic();                             */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean  bDgo, boolean    */
/* bMonRun,   boolean  bDiagStWait);                                          */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Ext_bDgoCoh_StrtLock;                                       */
/*  input boolean Ext_bMonRunCoh_StrtLock;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTLOCKACQ_vidOS(void)
{
   uint8 u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (  (u8LocalExt_stGBxCf == 1)
      || (u8LocalExt_stGBxCf == 2))
   {
      STRTLOCKACQ_vidStrtLockAcq();
      STRTLOCKACQ_vidDiagnostic();
      GDGAR_vidGdu(GD_DFT_COH_STRTLOCK,
                   Ext_bDgoCoh_StrtLock,
                   Ext_bMonRunCoh_StrtLock,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTLOCKACQ_vidStrtLockAcq                                 */
/* !Description :  Ce bloc calcule la valeur physique de la variable          */
/*                 Ext_bStrtLockAcq. Quand Ext_bStrtLockAcq =1, il n’y a pas  */
/*                 de démarrage possible. Le signal du capteur passe par un   */
/*                 filtrage anti rebond avec seuils calibrables.              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_09_04489_002.01                                     */
/*                 VEMS_R_09_04489_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Acquisition_startlock_tor;                                  */
/*  input boolean STRTLOCKACQ_bDebouncingFilSig;                              */
/*  input uint8 StrtLock_ThdHi_C;                                             */
/*  input uint8 StrtLock_ThdLo_C;                                             */
/*  input uint8 STRTLOCKACQ_u8DebouncingFiltCnt;                              */
/*  input boolean Inv_bStrtLock_C;                                            */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Ext_bArchiCf;                                               */
/*  output boolean STRTLOCKACQ_bDebouncingFilSig;                             */
/*  output uint8 STRTLOCKACQ_u8DebouncingFiltCnt;                             */
/*  output boolean Ext_bStrtLockAcqRaw;                                       */
/*  output boolean Ext_bStrtAuth;                                             */
/*  output boolean Ext_bATParkNeut;                                           */
/*  output boolean Ext_bDrvTraAMT;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTLOCKACQ_vidStrtLockAcq(void)
{
   boolean bLocalExt_bStrtLockAcqRaw;
   boolean bLocalExt_bATParkNeut;
   boolean bLocalExt_bDrvTraAMT;
   boolean bLocalExt_bStrtAuth;
   boolean bLocalExt_bArchiCf;
   uint8   u8LocalCnt;
   uint8   u8LocalTranThd;
   uint8   u8LocalExt_stGBxCf;
   uint16  u16LocalCnt;


   VEMS_vidGET(Acquisition_startlock_tor, bLocalExt_bStrtLockAcqRaw);
   if (bLocalExt_bStrtLockAcqRaw != STRTLOCKACQ_bDebouncingFilSig)
   {
      if (bLocalExt_bStrtLockAcqRaw != 0)
      {
         u8LocalTranThd = StrtLock_ThdHi_C;
      }
      else
      {
         u8LocalTranThd = StrtLock_ThdLo_C;
      }
      u16LocalCnt = (uint16)(STRTLOCKACQ_u8DebouncingFiltCnt + 1);
      u8LocalCnt = (uint8)MATHSRV_udtMIN(u16LocalCnt, 255);
      if (u8LocalCnt >= u8LocalTranThd)
      {
         STRTLOCKACQ_bDebouncingFilSig = bLocalExt_bStrtLockAcqRaw;
         u8LocalCnt = 0;
      }
      STRTLOCKACQ_u8DebouncingFiltCnt = u8LocalCnt;
   }
   else
   {
      STRTLOCKACQ_u8DebouncingFiltCnt = 0;
   }

   if (Inv_bStrtLock_C != 0)
   {
      if (STRTLOCKACQ_bDebouncingFilSig == 0)
      {
         bLocalExt_bStrtAuth = 1;
      }
      else
      {
         bLocalExt_bStrtAuth = 0;
      }
   }
   else
   {
      bLocalExt_bStrtAuth = STRTLOCKACQ_bDebouncingFilSig;
   }
   VEMS_vidSET(Ext_bStrtLockAcqRaw, bLocalExt_bStrtLockAcqRaw);
   VEMS_vidSET(Ext_bStrtAuth, bLocalExt_bStrtAuth);

   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (bLocalExt_bArchiCf != 0)
   {
      if (u8LocalExt_stGBxCf == 1)
      {
         bLocalExt_bDrvTraAMT = 0;
         if (bLocalExt_bStrtAuth != 0)
         {
            bLocalExt_bATParkNeut = 1;
         }
         else
         {
            bLocalExt_bATParkNeut = 0;
         }
      }
      else
      {
         if (u8LocalExt_stGBxCf == 2)
         {
            bLocalExt_bATParkNeut = 0;
            if (bLocalExt_bStrtAuth != 0)
            {
               bLocalExt_bDrvTraAMT = 1;
            }
            else
            {
               bLocalExt_bDrvTraAMT = 0;
            }
         }
         else
         {
            bLocalExt_bATParkNeut = 0;
            bLocalExt_bDrvTraAMT = 0;
         }
      }
   }
   else
   {
      bLocalExt_bATParkNeut = 0;
      bLocalExt_bDrvTraAMT = 0;
   }
   VEMS_vidSET(Ext_bATParkNeut, bLocalExt_bATParkNeut);
   VEMS_vidSET(Ext_bDrvTraAMT, bLocalExt_bDrvTraAMT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTLOCKACQ_vidDiagnostic                                  */
/* !Description :  Si le signal du capteur Start Lock n’est pas cohérent avec */
/*                 le paramètre CAN associé alors un défaut de type cohérence */
/*                 apparaît.                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void STRTLOCKACQ_vidDefautStrtLock();                         */
/*  input boolean Diag_on;                                                    */
/*  output boolean Ext_bMonRunCoh_StrtLock;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTLOCKACQ_vidDiagnostic(void)
{
   boolean bLocalInhDiag_StrtLock;
   boolean bLocalDiag_on;


   bLocalInhDiag_StrtLock = GDGAR_bGetFRM(FRM_FRM_INHDIAG_STRTLOCK);
   VEMS_vidGET(Diag_on, bLocalDiag_on);

   if (  (bLocalInhDiag_StrtLock == 0)
      && (bLocalDiag_on != 0))
   {
      Ext_bMonRunCoh_StrtLock = 1;
      STRTLOCKACQ_vidDefautStrtLock();
   }
   else
   {
      Ext_bMonRunCoh_StrtLock = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTLOCKACQ_vidDefautStrtLock                              */
/* !Description :  Fonction de production de Ext_bDgoCoh_StrtLock.            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_09_04489_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bStrtAuth;                                              */
/*  input boolean Ext_bDgoSenPN;                                              */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Ext_bInhStrtAMT;                                            */
/*  output boolean Ext_bDgoCoh_StrtLock;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTLOCKACQ_vidDefautStrtLock(void)
{
   boolean bLocalExt_bStrtAuth;
   boolean bLocalExt_bDgoSenPN;
   boolean bLocalExt_bInhStrtAMT;
   boolean bLocal;
   uint8   u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_bStrtAuth, bLocalExt_bStrtAuth);
   VEMS_vidGET(Ext_bDgoSenPN, bLocalExt_bDgoSenPN);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_bInhStrtAMT, bLocalExt_bInhStrtAMT);

   if (u8LocalExt_stGBxCf == 1)
   {
      bLocal = bLocalExt_bDgoSenPN;
   }
   else
   {
      if (u8LocalExt_stGBxCf == 2)
      {
         bLocal = bLocalExt_bInhStrtAMT;
      }
      else
      {
         bLocal = 1;
      }
   }

   if (bLocalExt_bStrtAuth == bLocal)
   {
      Ext_bDgoCoh_StrtLock = 1;
   }
   else
   {
      Ext_bDgoCoh_StrtLock = 0;
   }
}
/*****************************end of file**************************************/