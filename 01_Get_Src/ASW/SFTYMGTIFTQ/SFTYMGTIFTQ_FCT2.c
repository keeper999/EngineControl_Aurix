/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMGTIFTQ                                             */
/* !Description     : SFTYMGTIFTQ component.                                  */
/*                                                                            */
/* !Module          : SFTYMGTIFTQ                                             */
/* !Description     : SAFETY TMS: interface avec LDA/LDB de la structure      */
/*                    d'accueil                                               */
/*                                                                            */
/* !File            : SFTYMGTIFTQ_FCT2.C                                      */
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
/*   1 / SFTYMGTIFTQ_vidThrInpChkSftyLvl2                                     */
/*   2 / SFTYMGTIFTQ_vidCluInpChkSftyLvl2                                     */
/*   3 / SFTYMGTIFTQ_vidNeutPosnSftyLvl2                                      */
/*   4 / SFTYMGTIFTQ_vidInpChkLvl2                                            */
/*   5 / SFTYMGTIFTQ_vidDftAutChkIni                                          */
/*   6 / SFTYMGTIFTQ_vidSndDftLvl3                                            */
/*   7 / SFTYMGTIFTQ_vidInpInjTqRelzd                                         */
/*   8 / SFTYMGTIFTQ_vidDiagInpLvl2An                                         */
/*   9 / SFTYMGTIFTQ_vidDiagInpLvl2An_1                                       */
/*   10 / SFTYMGTIFTQ_vidDiagSensAcquiLvl2                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5147394 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SFTYMGTIFTQ/SFTYMGTIFTQ_FCT2.C_v  $*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   21 Mar 2011 $*/
/* $Author::   hmelloul                               $$Date::   21 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SFTYMGTIFTQ.h"
#include "SFTYMGTIFTQ_L.h"
#include "SFTYMGTIFTQ_IM.h"
#include "GDGAR.h"
#include "DGOHAL.h"
#include "MCWDG.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidThrInpChkSftyLvl2                           */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes du       */
/*                 Papillon.                                                  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftSftyCoh_Thr;                                    */
/*  output boolean SftyMgt_bInpChkThr;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidThrInpChkSftyLvl2(void)
{
   boolean bLocalDftSftyCoh_Thr;
   boolean bLocal_AcvTreatSftyLvl2Thr;


   bLocal_AcvTreatSftyLvl2Thr = GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2THR);

   VEMS_vidGET(SftyMgt_bDftSftyCoh_Thr, bLocalDftSftyCoh_Thr);

   if (  (bLocalDftSftyCoh_Thr != 0)
      && (bLocal_AcvTreatSftyLvl2Thr == 0))
   {
      SftyMgt_bInpChkThr = 1;
   }
   else
   {
      SftyMgt_bInpChkThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidCluInpChkSftyLvl2                           */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes des      */
/*                 capteurs de la pédale d’Embrayage.                         */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftSftySc_CluPed;                                  */
/*  output boolean SftyMgt_bInpChkClu;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidCluInpChkSftyLvl2(void)
{
   boolean bLocalDftSftySc_CluPed;
   boolean bLocal_AcvTreatSftyLvl2Clu;


   bLocal_AcvTreatSftyLvl2Clu = GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2CLU);

   VEMS_vidGET(SftyMgt_bDftSftySc_CluPed, bLocalDftSftySc_CluPed);

   if (  (bLocalDftSftySc_CluPed != 0)
      && (bLocal_AcvTreatSftyLvl2Clu == 0))
   {
      SftyMgt_bInpChkClu = 1;
   }
   else
   {
      SftyMgt_bInpChkClu = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidNeutPosnSftyLvl2                            */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes du       */
/*                 capteur de la Position Point Mort                          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftSftySc_Neut;                                    */
/*  output boolean SftyMgt_bInpChkNeutPosn;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidNeutPosnSftyLvl2(void)
{
   boolean bLocalDftSftySc_Neut;
   boolean bLocal_AcvTreatSftyLvl2Gear;


   bLocal_AcvTreatSftyLvl2Gear = GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2GEAR);

   VEMS_vidGET(SftyMgt_bDftSftySc_Neut, bLocalDftSftySc_Neut);

   if (  (bLocalDftSftySc_Neut != 0)
      && (bLocal_AcvTreatSftyLvl2Gear == 0))
   {
      SftyMgt_bInpChkNeutPosn = 1;
   }
   else
   {
      SftyMgt_bInpChkNeutPosn = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidInpChkLvl2                                  */
/* !Description :  Ce bloc décrit la consolidation de tous les résultats des  */
/*                 diagnostics en un booléen : SftyMgt_bInpChk                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bInpChk;                                            */
/*  input boolean SftyMgt_bInpChkAccP;                                        */
/*  input boolean SftyMgt_bInpChkBrk;                                         */
/*  input boolean SftyMgt_bInpChkVehSpd;                                      */
/*  input boolean SftyMgt_bInpChkThr;                                         */
/*  input boolean SftyMgt_bInpChkClu;                                         */
/*  input boolean SftyMgt_bInpChkNeutPosn;                                    */
/*  input boolean SftyMgt_bInpChkF329;                                        */
/*  input boolean SftyMgt_bInpChkF349;                                        */
/*  input boolean SftyMgt_bInpChkF34D;                                        */
/*  input boolean SftyMgt_bInpChkF38D;                                        */
/*  input boolean SFTYMGTIFTQ_bRawSig;                                        */
/*  input uint8 SftyMgt_nInpChkMin_C;                                         */
/*  input uint8 SftyMgt_nInpChkMax_C;                                         */
/*  input uint8 SFTYMGTIFTQ_u8AntiBounceCounter;                              */
/*  output boolean SFTYMGTIFTQ_bRawSig;                                       */
/*  output uint8 SFTYMGTIFTQ_u8AntiBounceCounter;                             */
/*  output boolean SftyMgt_bInpChk;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidInpChkLvl2(void)
{
   boolean bLocalSftyMgt_bInpChk;
   uint8   u8LocalTranThd;


   VEMS_vidGET(SftyMgt_bInpChk, bLocalSftyMgt_bInpChk);

   if (  (SftyMgt_bInpChkAccP != 0)
      || (SftyMgt_bInpChkBrk != 0)
      || (SftyMgt_bInpChkVehSpd != 0)
      || (SftyMgt_bInpChkThr != 0)
      || (SftyMgt_bInpChkClu != 0)
      || (SftyMgt_bInpChkNeutPosn != 0)
      || (SftyMgt_bInpChkF329 != 0)
      || (SftyMgt_bInpChkF349 != 0)
      || (SftyMgt_bInpChkF34D != 0)
      || (SftyMgt_bInpChkF38D != 0))
   {
      SFTYMGTIFTQ_bRawSig = 1;
   }
   else
   {
      SFTYMGTIFTQ_bRawSig = 0;
   }

   if (SFTYMGTIFTQ_bRawSig != bLocalSftyMgt_bInpChk)
   {
      if (SFTYMGTIFTQ_bRawSig == 0)
      {
         u8LocalTranThd = SftyMgt_nInpChkMin_C;
      }
      else
      {
         u8LocalTranThd = SftyMgt_nInpChkMax_C;
      }
      if (SFTYMGTIFTQ_u8AntiBounceCounter < 255)
      {
         SFTYMGTIFTQ_u8AntiBounceCounter =
            (uint8)(SFTYMGTIFTQ_u8AntiBounceCounter + 1);
      }
      if (SFTYMGTIFTQ_u8AntiBounceCounter >= u8LocalTranThd)
      {
         VEMS_vidSET(SftyMgt_bInpChk, SFTYMGTIFTQ_bRawSig);
         SFTYMGTIFTQ_u8AntiBounceCounter = 0;
      }
   }
   else
   {
      SFTYMGTIFTQ_u8AntiBounceCounter = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidDftAutChkIni                                */
/* !Description :  Lecture du défaut init safety par l’intermédiaire d’un API.*/
/* !Number      :  FCT2.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/* udtChannel);                                                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoInhChkInitSfty;                                 */
/*  output boolean SftyMgt_bMonRunInhChkInitSfty;                             */
/*  output boolean SftyMgt_bDgoInhChkInitSfty;                                */
/*  output boolean SftyMgt_bDftAutChkIni;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidDftAutChkIni(void)
{
   boolean          bLocalInhDiagInitSfty;
   boolean          bLocalInhDiag_inhThrCpuSfty;
   DGOHAL_tbfStatus bfLocalFault;


   bLocalInhDiagInitSfty = GDGAR_bGetFRM(FRM_FRM_INHDIAGINITSFTY);
   if (bLocalInhDiagInitSfty != 0)
   {
      SftyMgt_bMonRunInhChkInitSfty = 0;
   }
   else
   {
      SftyMgt_bMonRunInhChkInitSfty = 1;
      bfLocalFault = DGOHAL_bfRead(DGOHAL_udtMCWDG_INIT_SAFETY);
      if (  ( (bfLocalFault
            & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_MCP_RAM_TEST) != 0)
         || ( (bfLocalFault
            & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_MCP_FLASH_CKS) != 0)
         || ( (bfLocalFault
            & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_MCW_COMPUTED_CKS) != 0)
         || ( (bfLocalFault
            & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_MCW_INIT_SAFETY_RESULTS) != 0))
      {
         SftyMgt_bDgoInhChkInitSfty = 1;
      }
      else
      {
         SftyMgt_bDgoInhChkInitSfty = 0;
      }
   }

   bLocalInhDiag_inhThrCpuSfty = GDGAR_bGetFRM(FRM_FRM_INHDIAG_INHTHRCPUSFTY);

   if (  (SftyMgt_bDgoInhChkInitSfty != 0)
      || (bLocalInhDiag_inhThrCpuSfty != 0))
   {
      VEMS_vidSET(SftyMgt_bDftAutChkIni, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDftAutChkIni, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidSndDftLvl3                                  */
/* !Description :  Le Gestionnaire de Diagnostics  ne faisant pas partie de la*/
/*                 TMS, on ne peut transmettre au safety manager (qui est le  */
/*                 Gestionnaire des Actions de Reconfiguration propre à la    */
/*                 TMS) les défaut filtrés et confirmés par ce dernier.       */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sfty_bMonRunClk_Cpu;                                        */
/*  input boolean Sfty_bDgoClk_Cpu;                                           */
/*  input uint16 Sfty_ctrClkCpu;                                              */
/*  input uint16 Sfty_incClkCpu_C;                                            */
/*  input uint16 Sfty_decClkCpu_C;                                            */
/*  input uint16 Sfty_ctrMaxClkCpu_C;                                         */
/*  input boolean Sfty_bMonRunClk_CpuSfty;                                    */
/*  input boolean Sfty_bDgoClk_CpuSfty;                                       */
/*  input uint16 Sfty_ctrClkCpuSfty;                                          */
/*  input uint16 Sfty_incClkCpuSfty_C;                                        */
/*  input uint16 Sfty_decClkCpuSfty_C;                                        */
/*  input uint16 Sfty_ctrMaxClkCpuSfty_C;                                     */
/*  input boolean Sfty_bMonRunAlgo_Cpu;                                       */
/*  input boolean Sfty_bDgoAlgo_Cpu;                                          */
/*  input uint16 Sfty_ctrAlgoCpu;                                             */
/*  input uint16 Sfty_incAlgoCpu_C;                                           */
/*  input uint16 Sfty_decAlgoCpu_C;                                           */
/*  input uint16 Sfty_ctrMaxAlgoCpu_C;                                        */
/*  input boolean Sfty_bMonRunAlgo_CpuSfty;                                   */
/*  input boolean Sfty_bDgoAlgo_CpuSfty;                                      */
/*  input uint16 Sfty_ctrAlgoCpuSfty;                                         */
/*  input uint16 Sfty_incAlgoCpuSfty_C;                                       */
/*  input uint16 Sfty_decAlgoCpuSfty_C;                                       */
/*  input uint16 Sfty_ctrMaxAlgoCpuSfty_C;                                    */
/*  input boolean Sfty_bMonRunThr_Cpu;                                        */
/*  input boolean Sfty_bDgoThr_Cpu;                                           */
/*  input uint16 Sfty_ctrThrCpu;                                              */
/*  input uint16 Sfty_incThrCpu_C;                                            */
/*  input uint16 Sfty_decThrCpu_C;                                            */
/*  input uint16 Sfty_ctrMaxThrCpu_C;                                         */
/*  input boolean Sfty_bMonRunAccP_Cpu;                                       */
/*  input boolean Sfty_bDgoAccP_Cpu;                                          */
/*  input uint16 Sfty_ctrAccPCpu;                                             */
/*  input uint16 Sfty_incAccPCpu_C;                                           */
/*  input uint16 Sfty_decAccPCpu_C;                                           */
/*  input uint16 Sfty_ctrMaxAccPCpu_C;                                        */
/*  input boolean SFTYMGTIFTQ_bDgoClk_Cpu;                                    */
/*  input boolean SFTYMGTIFTQ_bDgoClk_CpuSfty;                                */
/*  input boolean SFTYMGTIFTQ_bDgoAlgo_Cpu;                                   */
/*  input boolean SFTYMGTIFTQ_bDgoAlgo_CpuSfty;                               */
/*  input boolean SftyMgt_bDgoThrChk;                                         */
/*  input boolean SftyMgt_bDgoAccPChk;                                        */
/*  output uint16 Sfty_ctrClkCpu;                                             */
/*  output uint16 Sfty_ctrClkCpuSfty;                                         */
/*  output uint16 Sfty_ctrAlgoCpu;                                            */
/*  output uint16 Sfty_ctrAlgoCpuSfty;                                        */
/*  output uint16 Sfty_ctrThrCpu;                                             */
/*  output uint16 Sfty_ctrAccPCpu;                                            */
/*  output boolean SFTYMGTIFTQ_bDgoClk_Cpu;                                   */
/*  output boolean SFTYMGTIFTQ_bDgoClk_CpuSfty;                               */
/*  output boolean SFTYMGTIFTQ_bDgoAlgo_Cpu;                                  */
/*  output boolean SFTYMGTIFTQ_bDgoAlgo_CpuSfty;                              */
/*  output boolean SftyMgt_bDgoThrChk;                                        */
/*  output boolean SftyMgt_bDgoAccPChk;                                       */
/*  output boolean SftyMgt_bDgoALUChk;                                        */
/*  output boolean SftyMgt_bDgoClkChk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidSndDftLvl3(void)
{
   boolean bLocalSfty_bDgoClk_Cpu;
   boolean bLocalSfty_bMonRunClk_Cpu;
   boolean bLocalSfty_bDgoClk_CpuSfty;
   boolean bLocalSfty_bMonRunClk_CpuSfty;
   boolean bLocalSfty_bDgoAlgo_Cpu;
   boolean bLocalSfty_bMonRunAlgo_Cpu;
   boolean bLocalSfty_bDgoAlgo_CpuSfty;
   boolean bLocalSfty_bMonRunAlgo_CpuSfty;
   boolean bLocalSfty_bMonRunThr_Cpu;
   boolean bLocalSfty_bDgoThr_Cpu;
   boolean bLocalSfty_bMonRunAccP_Cpu;
   boolean bLocalSfty_bDgoAccP_Cpu;
   boolean bLocalSftyMgt_bDgoThrChk;
   boolean bLocalSftyMgt_bDgoAccPChk;
   uint16  u16LocalSfty_ctrClkCpu;
   uint16  u16LocalSfty_ctrClkCpuSfty;
   uint16  u16LocalSfty_ctrAlgoCpu;
   uint16  u16LocalSfty_ctrAlgoCpuSfty;
   uint16  u16LocalSfty_ctrThrCpu;
   uint16  u16LocalSfty_ctrAccPCpu;
   sint32  s32LocalSfty_ctrClkCpu;
   sint32  s32LocalSfty_ctrClkCpuSfty;
   sint32  s32LocalSfty_ctrAlgoCpu;
   sint32  s32LocalSfty_ctrAlgoCpuSfty;
   sint32  s32LocalSfty_ctrThrCpu;
   sint32  s32LocalSfty_ctrAccPCpu;


   /* Calcul de Sfty_ctrClkCpu */
   VEMS_vidGET(Sfty_bMonRunClk_Cpu, bLocalSfty_bMonRunClk_Cpu);

   if (bLocalSfty_bMonRunClk_Cpu != 0)
   {
      VEMS_vidGET(Sfty_bDgoClk_Cpu, bLocalSfty_bDgoClk_Cpu);
      if (bLocalSfty_bDgoClk_Cpu != 0)
      {
         s32LocalSfty_ctrClkCpu = Sfty_ctrClkCpu + Sfty_incClkCpu_C;
      }
      else
      {
         s32LocalSfty_ctrClkCpu = Sfty_ctrClkCpu - Sfty_decClkCpu_C;
      }

      u16LocalSfty_ctrClkCpu = (uint16)MATHSRV_udtCLAMP(s32LocalSfty_ctrClkCpu,
                                                        0,
                                                        Sfty_ctrMaxClkCpu_C);
      Sfty_ctrClkCpu = u16LocalSfty_ctrClkCpu;
   }

   /* Calcul de Sfty_ctrClkCpuSfty */
   VEMS_vidGET(Sfty_bMonRunClk_CpuSfty, bLocalSfty_bMonRunClk_CpuSfty);

   if (bLocalSfty_bMonRunClk_CpuSfty != 0)
   {
      VEMS_vidGET(Sfty_bDgoClk_CpuSfty, bLocalSfty_bDgoClk_CpuSfty);
      if (bLocalSfty_bDgoClk_CpuSfty != 0)
      {
         s32LocalSfty_ctrClkCpuSfty = Sfty_ctrClkCpuSfty + Sfty_incClkCpuSfty_C;
      }
      else
      {
         s32LocalSfty_ctrClkCpuSfty = Sfty_ctrClkCpuSfty - Sfty_decClkCpuSfty_C;
      }

      u16LocalSfty_ctrClkCpuSfty =
         (uint16)MATHSRV_udtCLAMP(s32LocalSfty_ctrClkCpuSfty,
                                  0,
                                  Sfty_ctrMaxClkCpuSfty_C);
      Sfty_ctrClkCpuSfty = u16LocalSfty_ctrClkCpuSfty;
   }

   /* Calcul de Sfty_ctrAlgoCpu */
   VEMS_vidGET(Sfty_bMonRunAlgo_Cpu, bLocalSfty_bMonRunAlgo_Cpu);

   if (bLocalSfty_bMonRunAlgo_Cpu != 0)
   {
      VEMS_vidGET(Sfty_bDgoAlgo_Cpu, bLocalSfty_bDgoAlgo_Cpu);
      if (bLocalSfty_bDgoAlgo_Cpu != 0)
      {
         s32LocalSfty_ctrAlgoCpu = Sfty_ctrAlgoCpu + Sfty_incAlgoCpu_C;
      }
      else
      {
         s32LocalSfty_ctrAlgoCpu = Sfty_ctrAlgoCpu - Sfty_decAlgoCpu_C;
      }

      u16LocalSfty_ctrAlgoCpu =
         (uint16)MATHSRV_udtCLAMP(s32LocalSfty_ctrAlgoCpu,
                                  0,
                                  Sfty_ctrMaxAlgoCpu_C);
      Sfty_ctrAlgoCpu = u16LocalSfty_ctrAlgoCpu;
   }

   /* Calcul de Sfty_ctrAlgoCpuSfty */
   VEMS_vidGET(Sfty_bMonRunAlgo_CpuSfty, bLocalSfty_bMonRunAlgo_CpuSfty);

   if (bLocalSfty_bMonRunAlgo_CpuSfty != 0)
   {
      VEMS_vidGET(Sfty_bDgoAlgo_CpuSfty, bLocalSfty_bDgoAlgo_CpuSfty);
      if (bLocalSfty_bDgoAlgo_CpuSfty != 0)
      {
         s32LocalSfty_ctrAlgoCpuSfty = Sfty_ctrAlgoCpuSfty
                                       + Sfty_incAlgoCpuSfty_C;
      }
      else
      {
         s32LocalSfty_ctrAlgoCpuSfty = Sfty_ctrAlgoCpuSfty
                                       - Sfty_decAlgoCpuSfty_C;
      }

      u16LocalSfty_ctrAlgoCpuSfty =
         (uint16)MATHSRV_udtCLAMP(s32LocalSfty_ctrAlgoCpuSfty,
                                  0,
                                  Sfty_ctrMaxAlgoCpuSfty_C);
      Sfty_ctrAlgoCpuSfty = u16LocalSfty_ctrAlgoCpuSfty;
   }

   /* Calcul de Sfty_ctrThrCpu */
   VEMS_vidGET(Sfty_bMonRunThr_Cpu, bLocalSfty_bMonRunThr_Cpu);

   if (bLocalSfty_bMonRunThr_Cpu != 0)
   {
      VEMS_vidGET(Sfty_bDgoThr_Cpu, bLocalSfty_bDgoThr_Cpu);
      if (bLocalSfty_bDgoThr_Cpu != 0)
      {
         s32LocalSfty_ctrThrCpu = Sfty_ctrThrCpu + Sfty_incThrCpu_C;
      }
      else
      {
         s32LocalSfty_ctrThrCpu = Sfty_ctrThrCpu - Sfty_decThrCpu_C;
      }

      u16LocalSfty_ctrThrCpu =
         (uint16)MATHSRV_udtCLAMP(s32LocalSfty_ctrThrCpu,
                                  0,
                                  Sfty_ctrMaxThrCpu_C);
      Sfty_ctrThrCpu = u16LocalSfty_ctrThrCpu;
   }

   /* Calcul de Sfty_ctrAccPCpu */
   VEMS_vidGET(Sfty_bMonRunAccP_Cpu, bLocalSfty_bMonRunAccP_Cpu);

   if (bLocalSfty_bMonRunAccP_Cpu != 0)
   {
      VEMS_vidGET(Sfty_bDgoAccP_Cpu, bLocalSfty_bDgoAccP_Cpu);
      if (bLocalSfty_bDgoAccP_Cpu != 0)
      {
         s32LocalSfty_ctrAccPCpu = Sfty_ctrAccPCpu + Sfty_incAccPCpu_C;
      }
      else
      {
         s32LocalSfty_ctrAccPCpu = Sfty_ctrAccPCpu - Sfty_decAccPCpu_C;
      }

      u16LocalSfty_ctrAccPCpu =
         (uint16)MATHSRV_udtCLAMP(s32LocalSfty_ctrAccPCpu,
                                  0,
                                  Sfty_ctrMaxAccPCpu_C);
      Sfty_ctrAccPCpu = u16LocalSfty_ctrAccPCpu;
   }

   /* Calcul de NS_bDgoClk_Cpu */
   if (  (Sfty_ctrClkCpu != 0)
      && (  (Sfty_ctrClkCpu == Sfty_ctrMaxClkCpu_C)
         || (SFTYMGTIFTQ_bDgoClk_Cpu != 0)))
   {
      SFTYMGTIFTQ_bDgoClk_Cpu = 1;
   }
   else
   {
      SFTYMGTIFTQ_bDgoClk_Cpu = 0;
   }

   /* Calcul de NS_bDgoClk_CpuSfty */
   if (  (Sfty_ctrClkCpuSfty != 0)
      && (  (Sfty_ctrClkCpuSfty == Sfty_ctrMaxClkCpuSfty_C)
         || (SFTYMGTIFTQ_bDgoClk_CpuSfty != 0)))
   {
      SFTYMGTIFTQ_bDgoClk_CpuSfty = 1;
   }
   else
   {
      SFTYMGTIFTQ_bDgoClk_CpuSfty = 0;
   }

   /* Calcul de NS_bDgoAlgo_Cpu */
   if (  (Sfty_ctrAlgoCpu != 0)
      && (  (Sfty_ctrAlgoCpu == Sfty_ctrMaxAlgoCpu_C)
         || (SFTYMGTIFTQ_bDgoAlgo_Cpu != 0)))
   {
      SFTYMGTIFTQ_bDgoAlgo_Cpu = 1;
   }
   else
   {
      SFTYMGTIFTQ_bDgoAlgo_Cpu = 0;
   }

   /* Calcul de NS_bDgoAlgo_CpuSfty */
   if (  (Sfty_ctrAlgoCpuSfty != 0)
      && (  (Sfty_ctrAlgoCpuSfty == Sfty_ctrMaxAlgoCpuSfty_C)
         || (SFTYMGTIFTQ_bDgoAlgo_CpuSfty != 0)))
   {
      SFTYMGTIFTQ_bDgoAlgo_CpuSfty = 1;
   }
   else
   {
      SFTYMGTIFTQ_bDgoAlgo_CpuSfty = 0;
   }

   /* Calcul de SftyMgt_bDgoThrChk */
   VEMS_vidGET(SftyMgt_bDgoThrChk, bLocalSftyMgt_bDgoThrChk);

   if (  (Sfty_ctrThrCpu != 0)
      && (  (Sfty_ctrThrCpu == Sfty_ctrMaxThrCpu_C)
         || (bLocalSftyMgt_bDgoThrChk != 0)))
   {
      bLocalSftyMgt_bDgoThrChk = 1;
   }
   else
   {
      bLocalSftyMgt_bDgoThrChk = 0;
   }
   VEMS_vidSET(SftyMgt_bDgoThrChk, bLocalSftyMgt_bDgoThrChk);

   /* Calcul de SftyMgt_bDgoAccPChk */
   VEMS_vidGET(SftyMgt_bDgoAccPChk, bLocalSftyMgt_bDgoAccPChk);

   if (  (Sfty_ctrAccPCpu != 0)
      && (  (Sfty_ctrAccPCpu == Sfty_ctrMaxAccPCpu_C)
         || (bLocalSftyMgt_bDgoAccPChk != 0)))
   {
      bLocalSftyMgt_bDgoAccPChk = 1;
   }
   else
   {
      bLocalSftyMgt_bDgoAccPChk = 0;
   }
   VEMS_vidSET(SftyMgt_bDgoAccPChk, bLocalSftyMgt_bDgoAccPChk);

   if (  (SFTYMGTIFTQ_bDgoAlgo_Cpu != 0)
      || (SFTYMGTIFTQ_bDgoAlgo_CpuSfty != 0))
   {
      VEMS_vidSET(SftyMgt_bDgoALUChk, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoALUChk, 0);
   }

   if (  (SFTYMGTIFTQ_bDgoClk_Cpu != 0)
      || (SFTYMGTIFTQ_bDgoClk_CpuSfty != 0))
   {
      VEMS_vidSET(SftyMgt_bDgoClkChk, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoClkChk, 0);
   }
   /* QAC_WARNIG : Msg(2:4700) Metric value out of threshold range:
   SFTYMGTIFTQ_vidSndDftLvl3() : STPTH = 16384. : Due to a long function
   definition that can't be splitted for a better code visibility */
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidInpInjTqRelzd                               */
/* !Description :  Il n’existe pas dans le calculateur la lecture d’une       */
/*                 grandeur physique permettant de donner le status d’un      */
/*                 injecteur (actif ou coupé).                                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Inj_bInhInjr1;                                              */
/*  input boolean Inj_bInhInjr2;                                              */
/*  input boolean Inj_bInhInjr3;                                              */
/*  input boolean Inj_bInhInjr4;                                              */
/*  input uint32 InjrSys_prm_tiInjH1ReqCyl[6];                                */
/*  input uint32 InjrSys_prm_tiInjH2ReqCyl[6];                                */
/*  input uint32 InjrSys_prm_tiInjS1ReqCyl[6];                                */
/*  input uint32 InjrSys_prm_tiInjS2ReqCyl[6];                                */
/*  output uint8 SftyMgt_prm_bInjCutOffCyl;                                   */
/*  output uint8 SftyMgt_prm_bInjAcvCyl;                                      */
/*  output boolean SftyMgt_bTotCutOff;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidInpInjTqRelzd(void)
{
   /*QAC Msg(2:3132) : No impact on the function*/
   /*QAC Msg(2:3204) : No impact on the function*/
   boolean bLocalInj_bInhInjr1;
   boolean bLocalInj_bInhInjr2;
   boolean bLocalInj_bInhInjr3;
   boolean bLocalInj_bInhInjr4;
   boolean bLocaltiInjcond[4];
   boolean bLocalInj_bInhInjr[4];
   uint8   u8LocalSftyMgt_prm_bInjAcvCyl;
   uint8   u8LocalSftyMgt_prm_bInjCutOffCyl;
   uint8   u8LocalInd;
   uint32  u32LocaltiInjH1ReqCyl[6];
   uint32  u32LocaltiInjH2ReqCyl[6];
   uint32  u32LocaltiInjS1ReqCyl[6];
   uint32  u32LocaltiInjS2ReqCyl[6];


   VEMS_vidGET(Inj_bInhInjr1, bLocalInj_bInhInjr1);
   VEMS_vidGET(Inj_bInhInjr2, bLocalInj_bInhInjr2);
   VEMS_vidGET(Inj_bInhInjr3, bLocalInj_bInhInjr3);
   VEMS_vidGET(Inj_bInhInjr4, bLocalInj_bInhInjr4);
   bLocalInj_bInhInjr[0] = bLocalInj_bInhInjr1;
   bLocalInj_bInhInjr[1] = bLocalInj_bInhInjr2;
   bLocalInj_bInhInjr[2] = bLocalInj_bInhInjr3;
   bLocalInj_bInhInjr[3] = bLocalInj_bInhInjr4;

   VEMS_vidGET1DArray(InjrSys_prm_tiInjH1ReqCyl,
                     6,
                     u32LocaltiInjH1ReqCyl);
   VEMS_vidGET1DArray(InjrSys_prm_tiInjH2ReqCyl,
                     6,
                     u32LocaltiInjH2ReqCyl);
   VEMS_vidGET1DArray(InjrSys_prm_tiInjS1ReqCyl,
                     6,
                     u32LocaltiInjS1ReqCyl);
   VEMS_vidGET1DArray(InjrSys_prm_tiInjS2ReqCyl,
                     6,
                     u32LocaltiInjS2ReqCyl);

   for (u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      if (  (u32LocaltiInjH1ReqCyl[u8LocalInd] == 0)
         && (u32LocaltiInjH2ReqCyl[u8LocalInd] == 0)
         && (u32LocaltiInjS1ReqCyl[u8LocalInd] == 0)
         && (u32LocaltiInjS2ReqCyl[u8LocalInd] == 0))
      {
         bLocaltiInjcond[u8LocalInd] = 1;
      }
      else
      {
         if (bLocalInj_bInhInjr[u8LocalInd] != 0)
         {
            bLocaltiInjcond[u8LocalInd] = 1;
         }
         else
         {
            bLocaltiInjcond[u8LocalInd] = 0;
         }
      }
   }

   u8LocalSftyMgt_prm_bInjCutOffCyl = 0x00;
   u8LocalSftyMgt_prm_bInjCutOffCyl =
      (uint8)(u8LocalSftyMgt_prm_bInjCutOffCyl | bLocaltiInjcond[0]);
   u8LocalSftyMgt_prm_bInjCutOffCyl =
      (uint8)(u8LocalSftyMgt_prm_bInjCutOffCyl | (bLocaltiInjcond[1] << 1));
   u8LocalSftyMgt_prm_bInjCutOffCyl =
      (uint8)(u8LocalSftyMgt_prm_bInjCutOffCyl | (bLocaltiInjcond[2] << 2));
   u8LocalSftyMgt_prm_bInjCutOffCyl =
      (uint8)(u8LocalSftyMgt_prm_bInjCutOffCyl | (bLocaltiInjcond[3] << 3));
   VEMS_vidSET(SftyMgt_prm_bInjCutOffCyl, u8LocalSftyMgt_prm_bInjCutOffCyl);

   u8LocalSftyMgt_prm_bInjAcvCyl = (uint8)( 255
                                          - u8LocalSftyMgt_prm_bInjCutOffCyl);
   u8LocalSftyMgt_prm_bInjAcvCyl =
      (uint8)(u8LocalSftyMgt_prm_bInjAcvCyl & 0x0F);
   VEMS_vidSET(SftyMgt_prm_bInjAcvCyl, u8LocalSftyMgt_prm_bInjAcvCyl);

   if (u8LocalSftyMgt_prm_bInjCutOffCyl == 15)
   {
      VEMS_vidSET(SftyMgt_bTotCutOff, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bTotCutOff, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidDiagInpLvl2An                               */
/* !Description :  diagnostique InpLvl2An                                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_thr;                                    */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input sint8 Tra_noTarGear;                                                */
/*  input sint8 Tra_noEgdGear;                                                */
/*  input sint16 Cha_tqMSRReq;                                                */
/*  input uint16 Pos_papillon_1_result_ad_conv;                               */
/*  input uint16 Pos_papillon_2_result_ad_conv;                               */
/*  output uint16 Ext_uOpSecThrMes;                                           */
/*  output uint16 Ext_uOpThrMes;                                              */
/*  output uint16 SftyMgt_uThrRef;                                            */
/*  output sint16 SftyMgt_tqMSRReqCha;                                        */
/*  output uint8 SftyMgt_stTqReqCha;                                          */
/*  output sint8 SftyMgt_noTarGearTra;                                        */
/*  output sint8 SftyMgt_noEgdGearTra;                                        */
/*  output uint16 Ext_rOpThr;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidDiagInpLvl2An(void)
{

   uint8   u8LocalCha_stTqReq;
   sint8   s8LocalTra_noTarGear;
   sint8   s8LocalTra_noEgdGear;
   uint16  u16LocalPos_papillon_1_result_ad;
   uint16  u16LocalPos_papillon_2_result_ad;
   uint16  u16LocalTension_alimentation_thr;
   uint16  u16LocalTpacCorrectThrottPos;
   sint16  s16LocalCha_tqMSRReq;


   VEMS_vidGET(Tension_alimentation_thr, u16LocalTension_alimentation_thr);
   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpacCorrectThrottPos);
   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqReq);
   VEMS_vidGET(Tra_noTarGear, s8LocalTra_noTarGear);
   VEMS_vidGET(Tra_noEgdGear, s8LocalTra_noEgdGear);
   VEMS_vidGET(Cha_tqMSRReq, s16LocalCha_tqMSRReq);
   VEMS_vidGET(Pos_papillon_1_result_ad_conv,
               u16LocalPos_papillon_1_result_ad);
   VEMS_vidGET(Pos_papillon_2_result_ad_conv,
               u16LocalPos_papillon_2_result_ad);

   u16LocalPos_papillon_1_result_ad =
      (uint16)((uint32)((u16LocalPos_papillon_1_result_ad * 125) + 64) / 128);
   u16LocalPos_papillon_1_result_ad =
      (uint16)MATHSRV_udtMIN(u16LocalPos_papillon_1_result_ad, 1000);

   u16LocalPos_papillon_2_result_ad =
      (uint16)((uint32)((u16LocalPos_papillon_2_result_ad * 125) + 64) / 128);
   u16LocalPos_papillon_2_result_ad =
      (uint16)MATHSRV_udtMIN(u16LocalPos_papillon_2_result_ad, 1000);

   u16LocalTpacCorrectThrottPos =
      (uint16)((uint32)((u16LocalTpacCorrectThrottPos * 125) + 64) / 128);
   u16LocalTpacCorrectThrottPos =
      (uint16)MATHSRV_udtMIN(u16LocalTpacCorrectThrottPos, 1000);

   u8LocalCha_stTqReq = (uint8)MATHSRV_udtMIN(u8LocalCha_stTqReq, 7);
   s8LocalTra_noTarGear = (sint8)MATHSRV_udtCLAMP(s8LocalTra_noTarGear, -1, 9);
   s8LocalTra_noEgdGear = (sint8)MATHSRV_udtCLAMP(s8LocalTra_noEgdGear, -1, 9);
   s16LocalCha_tqMSRReq =
      (sint16)MATHSRV_udtCLAMP(s16LocalCha_tqMSRReq, -32000, 32000);

   VEMS_vidSET(Ext_uOpSecThrMes, u16LocalPos_papillon_2_result_ad);
   VEMS_vidSET(Ext_uOpThrMes, u16LocalPos_papillon_1_result_ad);
   VEMS_vidSET(SftyMgt_uThrRef, u16LocalTension_alimentation_thr);
   VEMS_vidSET(SftyMgt_tqMSRReqCha, s16LocalCha_tqMSRReq);
   VEMS_vidSET(SftyMgt_stTqReqCha, u8LocalCha_stTqReq);
   VEMS_vidSET(SftyMgt_noTarGearTra, s8LocalTra_noTarGear);
   VEMS_vidSET(SftyMgt_noEgdGearTra, s8LocalTra_noEgdGear);
   VEMS_vidSET(Ext_rOpThr, u16LocalTpacCorrectThrottPos);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidDiagInpLvl2An_1                             */
/* !Description :  diagnostique InpLvl2An                                     */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cps_clutch_pedal_input;                                     */
/*  input boolean CoPt_bTqTx;                                                 */
/*  input boolean Ext_bDgoSenPN;                                              */
/*  input boolean Ext_bDrvStrtReq;                                            */
/*  input boolean Ext_bInhStrtAMT;                                            */
/*  input boolean Ext_bRStrtAuthTra;                                          */
/*  input boolean Tra_bSIP;                                                   */
/*  input uint16 Wg_rAcvWgcCmdAppld;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_pBrkAsi;                                                 */
/*  input uint16 Ext_spdEspVeh;                                               */
/*  output boolean SftyMgt_bCluPedPrss;                                       */
/*  output boolean SftyMgt_bTqTx;                                             */
/*  output boolean SftyMgt_bDgoSenPN;                                         */
/*  output boolean SftyMgt_bDrvStrtReq;                                       */
/*  output boolean SftyMgt_bInhStrtAMT;                                       */
/*  output boolean SftyMgt_bRStrtAuthTra;                                     */
/*  output boolean SftyMgt_bSIPTra;                                           */
/*  output uint16 SftyMgt_rOpTrbActReqTrbAct;                                 */
/*  output uint16 SftyMgt_nEng;                                               */
/*  output uint16 SftyMgt_pBrkAsi;                                            */
/*  output uint16 SftyMgt_spdVeh;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidDiagInpLvl2An_1(void)
{
   boolean bLocalCps_clutch_pedal_input;
   boolean bLocalCoPt_bTqTx;
   boolean bLocalExt_bDgoSenPN;
   boolean bLocalExt_bDrvStrtReq;
   boolean bLocalExt_bInhStrtAMT;
   boolean bLocalExt_bRStrtAuthTra;
   boolean bLocalTra_bSIP;
   uint16  u16LocalSftyMgt_rpTrbActRqTrbAct;
   uint16  u16LocalWg_rAcvWgcCmdAppld;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalExt_pBrkAsi;
   uint16  u16LocalExt_spdEspVeh;
   uint16  u16LocalSftyMgt_spdVeh;
   uint32  u32LocalSftyMgt_rpTrbActRqTrbAct;
   uint32  u32LocalSftyMgt_spdVeh;


   VEMS_vidGET(Cps_clutch_pedal_input, bLocalCps_clutch_pedal_input);
   VEMS_vidGET(CoPt_bTqTx, bLocalCoPt_bTqTx);
   VEMS_vidGET(Ext_bDgoSenPN, bLocalExt_bDgoSenPN);
   VEMS_vidGET(Ext_bDrvStrtReq, bLocalExt_bDrvStrtReq);
   VEMS_vidGET(Ext_bInhStrtAMT, bLocalExt_bInhStrtAMT);
   VEMS_vidGET(Ext_bRStrtAuthTra, bLocalExt_bRStrtAuthTra);
   VEMS_vidGET(Tra_bSIP, bLocalTra_bSIP);
   VEMS_vidGET(Wg_rAcvWgcCmdAppld, u16LocalWg_rAcvWgcCmdAppld);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_pBrkAsi, u16LocalExt_pBrkAsi);
   VEMS_vidGET(Ext_spdEspVeh, u16LocalExt_spdEspVeh);

   u32LocalSftyMgt_rpTrbActRqTrbAct =
      (uint32)(u16LocalWg_rAcvWgcCmdAppld * 2);
   u16LocalSftyMgt_rpTrbActRqTrbAct =
      (uint16)MATHSRV_udtMIN(u32LocalSftyMgt_rpTrbActRqTrbAct, 65535);
   u16LocalExt_nEng = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 7500);
   u16LocalExt_pBrkAsi = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pBrkAsi, 20,1000);
   u32LocalSftyMgt_spdVeh = ( (uint32)(u16LocalExt_spdEspVeh * 32))
                            / 25;
   u16LocalSftyMgt_spdVeh =
      (uint16)MATHSRV_udtMIN(u32LocalSftyMgt_spdVeh, 64000);

   VEMS_vidSET(SftyMgt_bCluPedPrss, bLocalCps_clutch_pedal_input);
   VEMS_vidSET(SftyMgt_bTqTx, bLocalCoPt_bTqTx);
   VEMS_vidSET(SftyMgt_bDgoSenPN, bLocalExt_bDgoSenPN);
   VEMS_vidSET(SftyMgt_bDrvStrtReq, bLocalExt_bDrvStrtReq);
   VEMS_vidSET(SftyMgt_bInhStrtAMT, bLocalExt_bInhStrtAMT);
   VEMS_vidSET(SftyMgt_bRStrtAuthTra, bLocalExt_bRStrtAuthTra);
   VEMS_vidSET(SftyMgt_bSIPTra, bLocalTra_bSIP);
   VEMS_vidSET(SftyMgt_rOpTrbActReqTrbAct, u16LocalSftyMgt_rpTrbActRqTrbAct);
   VEMS_vidSET(SftyMgt_nEng, u16LocalExt_nEng);
   VEMS_vidSET(SftyMgt_pBrkAsi, u16LocalExt_pBrkAsi);
   VEMS_vidSET(SftyMgt_spdVeh, u16LocalSftyMgt_spdVeh);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidDiagSensAcquiLvl2                           */
/* !Description :  Ce bloc décrit l’acquisition des capteurs pour le Safety   */
/*                 niveau 2                                                   */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SFTYMGTIFTQ_vidAccPAcquiSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidBrkAcquiSftyLvl2();                       */
/*  extf argret void SFTYMGTIFTQ_vidThrAcquiSftyLvl2();                       */
/*  extf argret void SFTYMGTIFTQ_vidCluAcquiSftyLvl2();                       */
/*  extf argret void SFTYMGTIFTQ_vidNeutPosnAqSftLvl2();                      */
/*  input boolean Gear_bAcvNeutPosnAcq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidDiagSensAcquiLvl2(void)
{
   boolean bLocalGear_bAcvNeutPosnAcq;


   VEMS_vidGET(Gear_bAcvNeutPosnAcq, bLocalGear_bAcvNeutPosnAcq);
   SFTYMGTIFTQ_vidAccPAcquiSftyLvl2();
   SFTYMGTIFTQ_vidBrkAcquiSftyLvl2();
   SFTYMGTIFTQ_vidThrAcquiSftyLvl2();
   SFTYMGTIFTQ_vidCluAcquiSftyLvl2();
   if (bLocalGear_bAcvNeutPosnAcq != 0)
   {
      SFTYMGTIFTQ_vidNeutPosnAqSftLvl2();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/