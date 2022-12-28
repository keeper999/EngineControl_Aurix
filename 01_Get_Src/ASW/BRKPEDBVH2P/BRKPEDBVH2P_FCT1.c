/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKPEDBVH2P                                             */
/* !Description     : BRKPEDBVH2P component.                                  */
/*                                                                            */
/* !Module          : BRKPEDBVH2P                                             */
/* !Description     : DIAGNOSTIC BVH2’ SUR L’INFORMATION FREIN FILAIRE        */
/*                                                                            */
/* !File            : BRKPEDBVH2P_FCT1.C                                      */
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
/*   1 / BRKPEDBVH2P_vidInitOutput                                            */
/*   2 / BRKPEDBVH2P_vidEventGeneration                                       */
/*   3 / BRKPEDBVH2P_vidCounter                                               */
/*   4 / BRKPEDBVH2P_vidGearRatioChgEdge                                      */
/*   5 / BRKPEDBVH2P_vidClutchPedalEdge                                       */
/*   6 / BRKPEDBVH2P_vidDiagnostic                                            */
/*   7 / BRKPEDBVH2P_vidDiagnostic_niv2                                       */
/*                                                                            */
/* !Reference   : V02 NT 10 02615 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056811                                         */
/* !OtherRefs   : VEMS V02 ECU#056349                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHIBRK/BRKPEDBVH2P/BRKPEDBVH2P$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   12 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "BRKPEDBVH2P.h"
#include "BRKPEDBVH2P_L.h"
#include "BRKPEDBVH2P_IM.h"
#include "LIBSFTYLVL2.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidInitOutput                                  */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bSecBrkPedPrssFilt;                                     */
/*  input boolean Ext_bMonRunDecelCoh_BrkPedBVH2p;                            */
/*  input boolean Ext_bMonRunAccelCoh_BrkPedBVH2p;                            */
/*  input boolean BRKPEDBVH2P_bRawSigDecel;                                   */
/*  input boolean BRKPEDBVH2P_bRawSigAccel;                                   */
/*  input boolean Ext_bDgoDecelCoh_BrkPedBVH2p;                               */
/*  input boolean Ext_bDgoAccelCoh_BrkPedBVH2p;                               */
/*  output boolean BRKPEDBVH2P_bTraSIP_Prev;                                  */
/*  output boolean BRKPEDBVH2P_bCluPedPrss_Prev;                              */
/*  output boolean Ext_bDftSftyDecelCoh_BrkPedBVH2p;                          */
/*  output boolean Ext_bDftSftyAccelCoh_BrkPedBVH2p;                          */
/*  output uint8 Ext_ctSftyAccelCoh_BrkPedBVH2p;                              */
/*  output uint8 Ext_ctSftyDecelCoh_BrkPedBVH2p;                              */
/*  output boolean Ext_bMonRunDecelCoh_BrkPedBVH2p;                           */
/*  output boolean Ext_bMonRunAccelCoh_BrkPedBVH2p;                           */
/*  output uint8 BRKPEDBVH2P_u8CntFilt_1;                                     */
/*  output uint8 BRKPEDBVH2P_u8CntFilt_2;                                     */
/*  output boolean BRKPEDBVH2P_bRawSigAccel;                                  */
/*  output boolean BRKPEDBVH2P_bRawSigDecel;                                  */
/*  output boolean Ext_bDgoDecelCoh_BrkPedBVH2p;                              */
/*  output boolean Ext_bDgoAccelCoh_BrkPedBVH2p;                              */
/*  output uint16 BRKPEDBVH2P_u16AccelCounter;                                */
/*  output uint16 BRKPEDBVH2P_u16DecelCounter;                                */
/*  output boolean BRKPEDBVH2P_bFilSig_1;                                     */
/*  output boolean BRKPEDBVH2P_bFilSig_2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidInitOutput(void)
{
   boolean  bLocalExt_bSecBrkPedPrssFilt;


   BRKPEDBVH2P_bTraSIP_Prev = 0;
   BRKPEDBVH2P_bCluPedPrss_Prev = 0;
   VEMS_vidSET(Ext_bDftSftyDecelCoh_BrkPedBVH2p, 0);
   VEMS_vidSET(Ext_bDftSftyAccelCoh_BrkPedBVH2p, 0);
   Ext_ctSftyAccelCoh_BrkPedBVH2p = 0;
   Ext_ctSftyDecelCoh_BrkPedBVH2p = 0;
   Ext_bMonRunDecelCoh_BrkPedBVH2p = 0;
   Ext_bMonRunAccelCoh_BrkPedBVH2p = 0;
   BRKPEDBVH2P_u8CntFilt_1 = 0;
   BRKPEDBVH2P_u8CntFilt_2 = 0;
   /* production of RawSig */
   VEMS_vidGET(Ext_bSecBrkPedPrssFilt, bLocalExt_bSecBrkPedPrssFilt);
   if (bLocalExt_bSecBrkPedPrssFilt == 0)
   {
      BRKPEDBVH2P_bRawSigAccel = 0;
      /* QAC Msg(3:3356) and Msg(3:3359): Keep this test to respect
         specification */
      if (Ext_bMonRunDecelCoh_BrkPedBVH2p != 0)
      {
         /* QAC Msg(3:3201): Keep this test to respect specification */
         BRKPEDBVH2P_bRawSigDecel = 1;
      }
      else
      {
         BRKPEDBVH2P_bRawSigDecel = 0;
      }
   }
   else
   {
      BRKPEDBVH2P_bRawSigDecel = 0;
      /* QAC Msg(3:3356) and Msg(3:3359): Keep this test to respect
         specification */
      if (Ext_bMonRunAccelCoh_BrkPedBVH2p != 0)
      {
         /* QAC Msg(3:3201): Keep this test to respect specification */
         BRKPEDBVH2P_bRawSigAccel = 1;
      }
      else
      {
         BRKPEDBVH2P_bRawSigAccel = 0;
      }
   }
   Ext_bDgoDecelCoh_BrkPedBVH2p = BRKPEDBVH2P_bRawSigDecel;
   Ext_bDgoAccelCoh_BrkPedBVH2p = BRKPEDBVH2P_bRawSigAccel;
   BRKPEDBVH2P_u16AccelCounter = 0;
   BRKPEDBVH2P_u16DecelCounter = 0;
   BRKPEDBVH2P_bFilSig_1 = Ext_bDgoDecelCoh_BrkPedBVH2p;
   BRKPEDBVH2P_bFilSig_2 = Ext_bDgoAccelCoh_BrkPedBVH2p;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidEventGeneration                             */
/* !Description :  La fonction diagnostic BVH2’ est inhibée par flux de       */
/*                 contrôle ou quand on est en phase de vie Réveil principal  */
/*                 mode intégration électronique.                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_02615_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BRKPEDBVH2P_vidCounter();                                */
/*  extf argret void BRKPEDBVH2P_vidDiagnostic();                             */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input boolean Cf_bSecBrkPedPrssDiag;                                      */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Cf_bSecBrkPedPrss;                                          */
/*  input boolean Ext_bDgoDecelCoh_BrkPedBVH2p;                               */
/*  input boolean Ext_bMonRunDecelCoh_BrkPedBVH2p;                            */
/*  input boolean Ext_bDgoAccelCoh_BrkPedBVH2p;                               */
/*  input boolean Ext_bMonRunAccelCoh_BrkPedBVH2p;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidEventGeneration(void)
{
   boolean bLocalCf_SecBrkPdPrsDig;
   boolean bLocalDIAGCAN_IntegElect;
   boolean bLocalCf_SecBrkPedPrss;

   VEMS_vidGET(Cf_bSecBrkPedPrssDiag, bLocalCf_SecBrkPdPrsDig);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_IntegElect);
   VEMS_vidGET(Cf_bSecBrkPedPrss, bLocalCf_SecBrkPedPrss);
   if (  (bLocalCf_SecBrkPdPrsDig == 0)
      && (bLocalDIAGCAN_IntegElect == 0)
      && (bLocalCf_SecBrkPedPrss != 0))
   {
      BRKPEDBVH2P_vidCounter();
      BRKPEDBVH2P_vidDiagnostic();
      GDGAR_vidGdu(GD_DFT_DECELCOH_BRKPEDBVH2P,
                   Ext_bDgoDecelCoh_BrkPedBVH2p,
                   Ext_bMonRunDecelCoh_BrkPedBVH2p,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ACCELCOH_BRKPEDBVH2P,
                   Ext_bDgoAccelCoh_BrkPedBVH2p,
                   Ext_bMonRunAccelCoh_BrkPedBVH2p,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidCounter                                     */
/* !Description :  Temporisation sur changement de rapport                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_02615_003.01                                     */
/*                 VEMS_R_10_02615_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BRKPEDBVH2P_vidGearRatioChgEdge();                       */
/*  extf argret void BRKPEDBVH2P_vidClutchPedalEdge();                        */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Tra_bSIP;                                                   */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input boolean BRKPEDBVH2P_bTraSIP_Prev;                                   */
/*  input boolean CoPt_bSIPEnd;                                               */
/*  input uint8 Ext_tiSIP;                                                    */
/*  input boolean BRKPEDBVH2P_bCluPedPrss_Prev;                               */
/*  input boolean Ext_bCluPedPrssEnd;                                         */
/*  input uint8 Ext_tiCluP;                                                   */
/*  input uint8 Brk_tiSIPCoh_C;                                               */
/*  input uint8 Brk_tiCluPCoh_C;                                              */
/*  output uint8 Ext_tiSIP;                                                   */
/*  output uint8 Ext_tiCluP;                                                  */
/*  output boolean Ext_bTiSIP;                                                */
/*  output boolean Ext_bTiCluP;                                               */
/*  output boolean BRKPEDBVH2P_bTraSIP_Prev;                                  */
/*  output boolean BRKPEDBVH2P_bCluPedPrss_Prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidCounter(void)
{
   boolean bLocalTra_bSIP;
   boolean bLocalExt_CluPedPrss;
   uint8   u8LocalExt_stGBxCf;
   uint16  u16LocalSum;
   uint16  u16LocalSum2;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Tra_bSIP, bLocalTra_bSIP);
   VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_CluPedPrss);

   if (bLocalTra_bSIP == 0)
   {
      if (BRKPEDBVH2P_bTraSIP_Prev != 0)
      {
         BRKPEDBVH2P_vidGearRatioChgEdge();
      }
      if (CoPt_bSIPEnd != 0)
      {
         u16LocalSum = (uint16)(Ext_tiSIP + 1);
         Ext_tiSIP = (uint8)MATHSRV_udtMIN(u16LocalSum, 100);
      }
      else
      {
         Ext_tiSIP = 0;
      }
   }
   else
   {
      Ext_tiSIP = 0;
   }
   if (bLocalExt_CluPedPrss == 0)
   {
      if (BRKPEDBVH2P_bCluPedPrss_Prev != 0)
      {
         BRKPEDBVH2P_vidClutchPedalEdge();
      }
      if (Ext_bCluPedPrssEnd != 0)
      {
         u16LocalSum2 = (uint16) (Ext_tiCluP + 1);
         Ext_tiCluP = (uint8)MATHSRV_udtMIN(u16LocalSum2, 100);
      }
      else
      {
         Ext_tiCluP = 0;
      }
   }
   else
   {
      Ext_tiCluP = 0;
   }
   if (  (u8LocalExt_stGBxCf == 1)
      || (u8LocalExt_stGBxCf == 2))
   {
      if (Ext_tiSIP >= Brk_tiSIPCoh_C)
      {
         Ext_bTiSIP = 1;
      }
      else
      {
         Ext_bTiSIP = 0;
      }
   }
   else
   {
      if (Brk_tiSIPCoh_C == 0)
      {
         Ext_bTiSIP = 1;
      }
      else
      {
         Ext_bTiSIP = 0;
      }
   }

   if (u8LocalExt_stGBxCf == 0)
   {
      if (Ext_tiCluP >= Brk_tiCluPCoh_C)
      {
         Ext_bTiCluP = 1;
      }
      else
      {
         Ext_bTiCluP = 0;
      }
   }
   else
   {
      if (Brk_tiCluPCoh_C == 0)
      {
         Ext_bTiCluP = 1;
      }
      else
      {
         Ext_bTiCluP = 0;
      }
   }
   BRKPEDBVH2P_bTraSIP_Prev = bLocalTra_bSIP;
   BRKPEDBVH2P_bCluPedPrss_Prev = bLocalExt_CluPedPrss;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidGearRatioChgEdge                            */
/* !Description :  Ce bloc permet d’initialiser le passage de Tra_bSIP de «   */
/*                 changement en cours » à « pas de changement en cours »     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CoPt_bSIPEnd;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidGearRatioChgEdge(void)
{
   CoPt_bSIPEnd = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidClutchPedalEdge                             */
/* !Description :  Ce bloc permet d’initialiser le passage de Ext_bCluPedPrss */
/*                 de « pédale embrayage appuyée » à « pédale embrayage       */
/*                 relachée »                                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Ext_bCluPedPrssEnd;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidClutchPedalEdge(void)
{
   Ext_bCluPedPrssEnd = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidDiagnostic                                  */
/* !Description :  Ce bloc spécifie les défauts incohérence BVH2’ en          */
/*                 accélération et en décélération                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_02615_004.01                                     */
/*                 VEMS_R_10_02615_005.01                                     */
/*                 VEMS_R_10_02615_006.01                                     */
/*                 VEMS_R_10_02615_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Ext_bBrkPark;                                               */
/*  input boolean Ext_bBrkParkCf;                                             */
/*  input boolean Ext_bReadBrkParkCf;                                         */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 Ext_stBrkIp;                                                  */
/*  input boolean Ext_bEPBCf;                                                 */
/*  input uint8 Acceleration_vehicule;                                        */
/*  input boolean Ext_bABSCf;                                                 */
/*  input boolean Ext_bASRESPCf;                                              */
/*  input boolean Ext_bSecBrkPedPrssFilt;                                     */
/*  input boolean Tra_bSIP;                                                   */
/*  input boolean Ext_bTiSIP;                                                 */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input boolean Ext_bTiCluP;                                                */
/*  input uint8 Brk_aVehDiagDecelCohBVH2_C;                                   */
/*  input uint8 Ext_spdVeh;                                                   */
/*  input uint8 Brk_spdVehBrkCoh_C;                                           */
/*  input uint8 Brk_aVehDiagAccelCohBVH2_C;                                   */
/*  input boolean Ext_bMonRunDecelCoh_BrkPedBVH2p;                            */
/*  input boolean Ext_bMonRunAccelCoh_BrkPedBVH2p;                            */
/*  input boolean BRKPEDBVH2P_bRawSigDecel;                                   */
/*  input boolean Ext_bDgoDecelCoh_BrkPedBVH2p;                               */
/*  input uint16 Brk_noThdDecPedBVH2pDecelCoh_C;                              */
/*  input uint16 Brk_noThdIncPedBVH2pDecelCoh_C;                              */
/*  input uint16 BRKPEDBVH2P_u16DecelCounter;                                 */
/*  input boolean BRKPEDBVH2P_bRawSigAccel;                                   */
/*  input boolean Ext_bDgoAccelCoh_BrkPedBVH2p;                               */
/*  input uint16 Brk_noThdDecPedBVH2pAccelCoh_C;                              */
/*  input uint16 Brk_noThdIncPedBVH2pAccelCoh_C;                              */
/*  input uint16 BRKPEDBVH2P_u16AccelCounter;                                 */
/*  output boolean Ext_bMonRunDecelCoh_BrkPedBVH2p;                           */
/*  output boolean Ext_bMonRunAccelCoh_BrkPedBVH2p;                           */
/*  output boolean BRKPEDBVH2P_bRawSigAccel;                                  */
/*  output boolean BRKPEDBVH2P_bRawSigDecel;                                  */
/*  output uint16 BRKPEDBVH2P_u16DecelCounter;                                */
/*  output boolean Ext_bDgoDecelCoh_BrkPedBVH2p;                              */
/*  output uint16 BRKPEDBVH2P_u16AccelCounter;                                */
/*  output boolean Ext_bDgoAccelCoh_BrkPedBVH2p;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidDiagnostic(void)
{
   boolean bLocalExt_bBrkPark;
   boolean bLocalExt_bBrkParkCf;
   boolean bLocalExt_bReadBrkParkCf;
   boolean bLocalTra_bSIP;
   boolean bLocalExt_CluPedPrss;
   boolean bLocalExt_bEPBCf;
   boolean bLocalFRM_bInhDiag_BrkPedBVH2p;
   boolean bLocalExt_bABSCf;
   boolean bLocalExt_ASRESPCf;
   boolean bLocalExt_bSecBrkPedPrssFilt;
   boolean bLocalCond1;
   boolean bLocalCond2;
   boolean bLocalCond3;
   boolean bLocalCond4;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalExt_stBrkIp;
   uint8   u8LocalExt_spdVeh;
   uint8   u8LocalAcceleration_vehicule;
   uint16  u16LocalTranThd;
   uint16  u16LocalScal;
   uint16  u16LocalScal2;


   VEMS_vidGET(Ext_bBrkPark,bLocalExt_bBrkPark);
   VEMS_vidGET(Ext_bBrkParkCf, bLocalExt_bBrkParkCf);
   VEMS_vidGET(Ext_bReadBrkParkCf, bLocalExt_bReadBrkParkCf);
   VEMS_vidGET(Ext_stGBxCf,u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_stBrkIp,u8LocalExt_stBrkIp);
   VEMS_vidGET(Ext_bEPBCf, bLocalExt_bEPBCf);
   VEMS_vidGET(Acceleration_vehicule,u8LocalAcceleration_vehicule);
   VEMS_vidGET(Ext_bABSCf,bLocalExt_bABSCf);
   VEMS_vidGET(Ext_bASRESPCf,bLocalExt_ASRESPCf);
   VEMS_vidGET(Ext_bSecBrkPedPrssFilt,bLocalExt_bSecBrkPedPrssFilt);

   bLocalFRM_bInhDiag_BrkPedBVH2p = GDGAR_bGetFRM(FRM_FRM_INHDIAG_BRKPEDBVH2P);

   if (  (bLocalExt_bBrkParkCf != 0)
      && (bLocalExt_bReadBrkParkCf != 0 ))
   {
      if (bLocalExt_bBrkPark != 0)
      {
         bLocalCond1 = 0;
      }
      else
      {
         bLocalCond1 = 1;
      }
   }
   else
   {
      bLocalCond1 = 1;
   }
   if (  (u8LocalExt_stGBxCf == 1)
      || (u8LocalExt_stGBxCf == 2))
   {
      VEMS_vidGET(Tra_bSIP, bLocalTra_bSIP);
      if (  (bLocalTra_bSIP == 0)
         && (Ext_bTiSIP != 0))
      {
         bLocalCond2 = 1;
      }
      else
      {
         bLocalCond2 = 0;
      }
   }
   else
   {
      VEMS_vidGET(Ext_bCluPedPrss,bLocalExt_CluPedPrss);
      if (  (bLocalExt_CluPedPrss == 0)
         && (Ext_bTiCluP != 0))
      {
         bLocalCond2 = 1;
      }
      else
      {
         bLocalCond2 = 0;
      }
   }
   u16LocalScal = (uint16)((Brk_aVehDiagDecelCohBVH2_C * 5)/4);
   if (u8LocalAcceleration_vehicule <= u16LocalScal)
   {
      bLocalCond4 = 1;
   }
   else
   {
      bLocalCond4 = 0;
   }
   if (  (bLocalFRM_bInhDiag_BrkPedBVH2p == 0)
      && (bLocalCond1 != 0)
      && (bLocalCond2 != 0)
      && (bLocalCond4 != 0))
   {
      if (  (bLocalExt_bABSCf != 0)
         || ( bLocalExt_ASRESPCf != 0))
      {
         if ( bLocalExt_bEPBCf != 0 )
         {
            VEMS_vidGET(Ext_spdVeh,u8LocalExt_spdVeh);
            if (u8LocalExt_spdVeh > Brk_spdVehBrkCoh_C)
            {
               bLocalCond3 = 1;
            }
            else
            {
               bLocalCond3 = 0;
            }
         }
         else
         {
            bLocalCond3 = 1;
         }
         if (  (  (u8LocalExt_stBrkIp != 2)
               && (u8LocalExt_stBrkIp != 3))
            && (bLocalCond3 != 0))
         {
            Ext_bMonRunDecelCoh_BrkPedBVH2p = 1;
         }
         else
         {
            Ext_bMonRunDecelCoh_BrkPedBVH2p = 0;
         }
      }
      else
      {
         Ext_bMonRunDecelCoh_BrkPedBVH2p = 1;
      }
   }
   else
   {
      Ext_bMonRunDecelCoh_BrkPedBVH2p = 0;
   }

   u16LocalScal2 = (uint16)((Brk_aVehDiagAccelCohBVH2_C * 5) / 4);
   if (  (bLocalFRM_bInhDiag_BrkPedBVH2p == 0)
      && (u8LocalAcceleration_vehicule > u16LocalScal2 ))
   {
      Ext_bMonRunAccelCoh_BrkPedBVH2p = 1;
   }
   else
   {
      Ext_bMonRunAccelCoh_BrkPedBVH2p = 0;
   }
   /* production of RawSig */
   if (bLocalExt_bSecBrkPedPrssFilt == 0)
   {
      BRKPEDBVH2P_bRawSigAccel = 0;
      if (Ext_bMonRunDecelCoh_BrkPedBVH2p != 0)
      {
         BRKPEDBVH2P_bRawSigDecel = 1;
      }
      else
      {
         BRKPEDBVH2P_bRawSigDecel = 0;
      }
   }
   else
   {
      BRKPEDBVH2P_bRawSigDecel = 0;
      if (Ext_bMonRunAccelCoh_BrkPedBVH2p != 0)
      {
         BRKPEDBVH2P_bRawSigAccel = 1;
      }
      else
      {
         BRKPEDBVH2P_bRawSigAccel = 0;
      }
   }

   if (BRKPEDBVH2P_bRawSigDecel != Ext_bDgoDecelCoh_BrkPedBVH2p)
   {
      if (BRKPEDBVH2P_bRawSigDecel == 0)
      {
         u16LocalTranThd = Brk_noThdDecPedBVH2pDecelCoh_C;
      }
      else
      {
         u16LocalTranThd = Brk_noThdIncPedBVH2pDecelCoh_C;
      }
      if (BRKPEDBVH2P_u16DecelCounter < 65535)
      {
         BRKPEDBVH2P_u16DecelCounter =
            (uint16)(BRKPEDBVH2P_u16DecelCounter + 1);
      }
      if (BRKPEDBVH2P_u16DecelCounter > u16LocalTranThd)
      {
         Ext_bDgoDecelCoh_BrkPedBVH2p = BRKPEDBVH2P_bRawSigDecel;
         BRKPEDBVH2P_u16DecelCounter = 0;
      }
   }
   else
   {
      BRKPEDBVH2P_u16DecelCounter = 0;
   }

   if (BRKPEDBVH2P_bRawSigAccel != Ext_bDgoAccelCoh_BrkPedBVH2p)
   {
      if (BRKPEDBVH2P_bRawSigAccel == 0)
      {
         u16LocalTranThd = Brk_noThdDecPedBVH2pAccelCoh_C;
      }
      else
      {
         u16LocalTranThd = Brk_noThdIncPedBVH2pAccelCoh_C;
      }
      if (BRKPEDBVH2P_u16AccelCounter < 65535)
      {
         BRKPEDBVH2P_u16AccelCounter =
            (uint16)(BRKPEDBVH2P_u16AccelCounter + 1);
      }
      if (BRKPEDBVH2P_u16AccelCounter > u16LocalTranThd)
      {
         Ext_bDgoAccelCoh_BrkPedBVH2p = BRKPEDBVH2P_bRawSigAccel;
         BRKPEDBVH2P_u16AccelCounter = 0;
      }
   }
   else
   {
      BRKPEDBVH2P_u16AccelCounter = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidDiagnostic_niv2                             */
/* !Description :  Ce diagnostic niveau est crée à partir d’un défaut detecté */
/*                 par le niveau 2                                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoDecelCoh_BrkPedBVH2p;                               */
/*  input uint8 Brk_nUpTranThd_DecelCohBVH2p_C;                               */
/*  input uint8 Brk_nDownTranThd_DecelCohBVH2p_C;                             */
/*  input uint8 Brk_nInitCpt_DecelCohBVH2p_C;                                 */
/*  input uint8 Brk_nDecCpt_DecelCohBVH2p_C;                                  */
/*  input uint8 BRKPEDBVH2P_u8CntFilt_1;                                      */
/*  input boolean BRKPEDBVH2P_bFilSig_1;                                      */
/*  input uint8 Ext_ctSftyDecelCoh_BrkPedBVH2p;                               */
/*  input boolean BRKPEDBVH2P_Ext_bDftSftyDecelCoh;                           */
/*  input boolean Ext_bDgoAccelCoh_BrkPedBVH2p;                               */
/*  input uint8 Brk_nUpTranThd_AccelCohBVH2p_C;                               */
/*  input uint8 Brk_nDownTranThd_AccelCohBVH2p_C;                             */
/*  input uint8 Brk_nInitCpt_AccelCohBVH2p_C;                                 */
/*  input uint8 Brk_nDecCpt_AccelCohBVH2p_C;                                  */
/*  input uint8 BRKPEDBVH2P_u8CntFilt_2;                                      */
/*  input boolean BRKPEDBVH2P_bFilSig_2;                                      */
/*  input uint8 Ext_ctSftyAccelCoh_BrkPedBVH2p;                               */
/*  input boolean BRKPEDBVH2P_Ext_bDftSftyAccelCoh;                           */
/*  output boolean Ext_bDftSftyDecelCoh_BrkPedBVH2p;                          */
/*  output boolean BRKPEDBVH2P_Ext_bDftSftyDecelCoh;                          */
/*  output boolean Ext_bDftSftyAccelCoh_BrkPedBVH2p;                          */
/*  output boolean BRKPEDBVH2P_Ext_bDftSftyAccelCoh;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidDiagnostic_niv2(void)
{

   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoDecelCoh_BrkPedBVH2p,
                                Brk_nUpTranThd_DecelCohBVH2p_C,
                                Brk_nDownTranThd_DecelCohBVH2p_C,
                                Brk_nInitCpt_DecelCohBVH2p_C,
                                Brk_nDecCpt_DecelCohBVH2p_C,
                                &BRKPEDBVH2P_u8CntFilt_1,
                                &BRKPEDBVH2P_bFilSig_1,
                                &Ext_ctSftyDecelCoh_BrkPedBVH2p,
                                &BRKPEDBVH2P_Ext_bDftSftyDecelCoh);
   VEMS_vidSET(Ext_bDftSftyDecelCoh_BrkPedBVH2p,
               BRKPEDBVH2P_Ext_bDftSftyDecelCoh);

   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoAccelCoh_BrkPedBVH2p,
                                Brk_nUpTranThd_AccelCohBVH2p_C,
                                Brk_nDownTranThd_AccelCohBVH2p_C,
                                Brk_nInitCpt_AccelCohBVH2p_C,
                                Brk_nDecCpt_AccelCohBVH2p_C,
                                &BRKPEDBVH2P_u8CntFilt_2,
                                &BRKPEDBVH2P_bFilSig_2,
                                &Ext_ctSftyAccelCoh_BrkPedBVH2p,
                                &BRKPEDBVH2P_Ext_bDftSftyAccelCoh);
   VEMS_vidSET(Ext_bDftSftyAccelCoh_BrkPedBVH2p,
               BRKPEDBVH2P_Ext_bDftSftyAccelCoh);
}
/*------------------------------- end of file --------------------------------*/