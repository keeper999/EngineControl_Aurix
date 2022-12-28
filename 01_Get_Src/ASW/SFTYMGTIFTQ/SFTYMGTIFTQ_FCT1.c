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
/* !File            : SFTYMGTIFTQ_FCT1.C                                      */
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
/*   1 / SFTYMGTIFTQ_vidInitOutput                                            */
/*   2 / SFTYMGTIFTQ_vidInitOutput1                                           */
/*   3 / SFTYMGTIFTQ_vidInpIgTqRelzd                                          */
/*   4 / SFTYMGTIFTQ_vidNoProdTqMon                                           */
/*   5 / SFTYMGTIFTQ_vidInhSftylvl2Afts                                       */
/*   6 / SFTYMGTIFTQ_vidEeprom                                                */
/*   7 / SFTYMGTIFTQ_vidSensInpCkSftyLvl2                                     */
/*   8 / SFTYMGTIFTQ_vidAcPInpChkSftyLvl2                                     */
/*   9 / SFTYMGTIFTQ_vidBrkInpChkSftyLvl2                                     */
/*   10 / SFTYMGTIFTQ_vidVehSpdInpSftyLvl2                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5147394 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SFTYMGTIFTQ/SFTYMGTIFTQ_FCT1.C_v  $*/
/* $Revision::   1.6      $$Author::   hmelloul       $$Date::   21 Mar 2011 $*/
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
#include "NVMSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidInitOutput                                  */
/* !Description :  Fonction d'initialisation des sorties du module SFTYMGTIFTQ*/
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SFTYMGTIFTQ_bDgoAlgo_Cpu;                                  */
/*  output boolean SFTYMGTIFTQ_bDgoAlgo_CpuSfty;                              */
/*  output boolean SFTYMGTIFTQ_bDgoClk_Cpu;                                   */
/*  output boolean SFTYMGTIFTQ_bDgoClk_CpuSfty;                               */
/*  output uint16 Sfty_ctrClkCpu;                                             */
/*  output uint16 Sfty_ctrClkCpuSfty;                                         */
/*  output uint16 Sfty_ctrAlgoCpu;                                            */
/*  output uint16 Sfty_ctrAlgoCpuSfty;                                        */
/*  output uint16 Sfty_ctrThrCpu;                                             */
/*  output uint16 Sfty_ctrAccPCpu;                                            */
/*  output boolean SFTYMGTIFTQ_bDgoIrvEMPrev1;                                */
/*  output boolean SFTYMGTIFTQ_bDgoIrvSTTPrev1;                               */
/*  output boolean SFTYMGTIFTQ_bDgoIrvVSCtlPrev1;                             */
/*  output uint8 SFTYMGTIFTQ_u8ctDftLaddPrev1;                                */
/*  output boolean SftyMgt_bDftStuckAccP;                                     */
/*  output uint8 SFTYMGTIFTQ_u8CntFilt_1;                                     */
/*  output uint8 SFTYMGTIFTQ_CtDftSftyStuckAccP;                              */
/*  output uint16 Ext_uOpSecThrMes;                                           */
/*  output uint16 Ext_uOpThrMes;                                              */
/*  output boolean Sfty3_bEngStopReq;                                         */
/*  output boolean SftyMgt_bCluPedPrss;                                       */
/*  output boolean SftyMgt_bDftAutChk;                                        */
/*  output boolean SftyMgt_bDftAutChkIni;                                     */
/*  output boolean SftyMgt_bDgoSenPN;                                         */
/*  output boolean SftyMgt_bDrvStrtReq;                                       */
/*  output boolean SftyMgt_bInhStrtAMT;                                       */
/*  output boolean SftyMgt_bNeut;                                             */
/*  output boolean SftyMgt_bRStrtAuthTra;                                     */
/*  output boolean SftyMgt_bSIPTra;                                           */
/*  output boolean SftyMgt_bTqTx;                                             */
/*  output boolean SftyMgt_bTotCutOff;                                        */
/*  output uint8 SftyMgt_prm_bInjCutOffCyl;                                   */
/*  output boolean SftyMgt_bDgoSwChk;                                         */
/*  output boolean SftyMgt_bDgoCalChk;                                        */
/*  output boolean SftyMgt_bDgoRAMChk;                                        */
/*  output boolean SftyMgt_bDgoRAMChk2;                                       */
/*  output boolean SftyMgt_bDgoALUChk;                                        */
/*  output boolean SftyMgt_bDgoClkChk;                                        */
/*  output boolean SftyMgt_bDgoThrChk;                                        */
/*  output boolean SftyMgt_bDgoAccPChk;                                       */
/*  output boolean Sfty3_bThrReq;                                             */
/*  output boolean SftyMgt_bDgoIrvEMPrev;                                     */
/*  output boolean SftyMgt_bDgoIrvSTTPrev;                                    */
/*  output boolean SftyMgt_bDgoIrvVSCtlPrev;                                  */
/*  output uint8 SftyMgt_ctDftLaddPrev;                                       */
/*  output boolean Sfty3_bEndRcvRun;                                          */
/*  output uint8 SftyMgt_prm_bInjAcvCyl;                                      */
/*  output uint16 SftyMgt_rCluPedPHiFreq;                                     */
/*  output uint16 SftyMgt_rOpTrbActReqTrbAct;                                 */
/*  output uint16 Ext_rOpThr;                                                 */
/*  output uint16 SftyMgt_spdVeh;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidInitOutput(void)
{
   /* Init of internal data */
   SFTYMGTIFTQ_bDgoAlgo_Cpu = 0;
   SFTYMGTIFTQ_bDgoAlgo_CpuSfty = 0;
   SFTYMGTIFTQ_bDgoClk_Cpu = 0;
   SFTYMGTIFTQ_bDgoClk_CpuSfty = 0;
   Sfty_ctrClkCpu = 0;
   Sfty_ctrClkCpuSfty = 0;
   Sfty_ctrAlgoCpu = 0;
   Sfty_ctrAlgoCpuSfty = 0;
   Sfty_ctrThrCpu = 0;
   Sfty_ctrAccPCpu = 0;
   SFTYMGTIFTQ_bDgoIrvEMPrev1 = 0;
   SFTYMGTIFTQ_bDgoIrvSTTPrev1 = 0;
   SFTYMGTIFTQ_bDgoIrvVSCtlPrev1 = 0;
   SFTYMGTIFTQ_u8ctDftLaddPrev1 = 0;
   SftyMgt_bDftStuckAccP = 0;
   SFTYMGTIFTQ_u8CntFilt_1 = 0;
   SFTYMGTIFTQ_CtDftSftyStuckAccP = 0;

   /* Init of output data */
   VEMS_vidSET(Ext_uOpSecThrMes, 0);
   VEMS_vidSET(Ext_uOpThrMes, 0);
   VEMS_vidSET(Sfty3_bEngStopReq, 0);
   VEMS_vidSET(SftyMgt_bCluPedPrss, 0);
   VEMS_vidSET(SftyMgt_bDftAutChk, 0);
   VEMS_vidSET(SftyMgt_bDftAutChkIni, 0);
   VEMS_vidSET(SftyMgt_bDgoSenPN, 0);
   VEMS_vidSET(SftyMgt_bDrvStrtReq, 0);
   VEMS_vidSET(SftyMgt_bInhStrtAMT, 0);
   VEMS_vidSET(SftyMgt_bNeut, 0);
   VEMS_vidSET(SftyMgt_bRStrtAuthTra, 0);
   VEMS_vidSET(SftyMgt_bSIPTra, 0);
   VEMS_vidSET(SftyMgt_bTqTx, 0);
   VEMS_vidSET(SftyMgt_bTotCutOff, 0);
   VEMS_vidSET(SftyMgt_prm_bInjCutOffCyl, 0);
   VEMS_vidSET(SftyMgt_bDgoSwChk, 0);
   VEMS_vidSET(SftyMgt_bDgoCalChk, 0);
   VEMS_vidSET(SftyMgt_bDgoRAMChk, 0);
   VEMS_vidSET(SftyMgt_bDgoRAMChk2, 0);
   VEMS_vidSET(SftyMgt_bDgoALUChk, 0);
   VEMS_vidSET(SftyMgt_bDgoClkChk, 0);
   VEMS_vidSET(SftyMgt_bDgoThrChk, 0);
   VEMS_vidSET(SftyMgt_bDgoAccPChk, 0);
   VEMS_vidSET(Sfty3_bThrReq, 0);
   VEMS_vidSET(SftyMgt_bDgoIrvEMPrev, 0);
   VEMS_vidSET(SftyMgt_bDgoIrvSTTPrev, 0);
   VEMS_vidSET(SftyMgt_bDgoIrvVSCtlPrev, 0);
   VEMS_vidSET(SftyMgt_ctDftLaddPrev, 0);
   VEMS_vidSET(Sfty3_bEndRcvRun, 0);
   VEMS_vidSET(SftyMgt_prm_bInjAcvCyl, 0);
   VEMS_vidSET(SftyMgt_rCluPedPHiFreq, 0);
   VEMS_vidSET(SftyMgt_rOpTrbActReqTrbAct, 0);
   VEMS_vidSET(Ext_rOpThr, 0);
   VEMS_vidSET(SftyMgt_spdVeh, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidInitOutput1                                 */
/* !Description :  Fonction d'initialisation des sorties du module SFTYMGTIFTQ*/
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output sint8 SftyMgt_noEgdGearTra;                                        */
/*  output sint8 SftyMgt_noTarGearTra;                                        */
/*  output uint8 SftyMgt_stTqReqCha;                                          */
/*  output sint16 SftyMgt_tqMSRReqCha;                                        */
/*  output uint16 SftyMgt_rAccP;                                              */
/*  output boolean SftyMgt_bBrkPedPrss;                                       */
/*  output uint16 SftyMgt_nEng;                                               */
/*  output uint16 SftyMgt_pBrkAsi;                                            */
/*  output uint16 SftyMgt_posnThr;                                            */
/*  output boolean Ext_bInhDft;                                               */
/*  output uint8 SftyMgt_F329LocalLength;                                     */
/*  output uint8 SftyMgt_F349LocalLength;                                     */
/*  output uint8 SftyMgt_F38DLocalLength;                                     */
/*  output boolean SftyMgt_bDftSftyStuckAccP;                                 */
/*  output uint16 SftyMgt_rCluPedSen;                                         */
/*  output uint16 SftyMgt_rNeutSen;                                           */
/*  output uint16 SftyMgt_uAccPSen1;                                          */
/*  output uint16 SftyMgt_uAccPSen2;                                          */
/*  output uint16 SftyMgt_uThrRef;                                            */
/*  output uint16 SftyMgt_uThrSen1;                                           */
/*  output uint16 SftyMgt_uThrSen2;                                           */
/*  output boolean SftyMgt_bInpChk;                                           */
/*  output uint8 SftyMgt_F329MsgData[8];                                      */
/*  output uint8 SftyMgt_F349MsgData[8];                                      */
/*  output uint8 SftyMgt_F38DMsgData[8];                                      */
/*  output uint8 SFTYMGTIFTQ_u8AntiBounceCounter;                             */
/*  output boolean SFTYMGTIFTQ_bFilSig_1;                                     */
/*  output boolean SFTYMGTIFTQ_bStuckAccP;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidInitOutput1(void)
{
   uint8 u8LocalIndex;
   uint8 u8LocalIndex1;
   uint8 u8LocalIndex2;


   VEMS_vidSET(SftyMgt_noEgdGearTra, 0);
   VEMS_vidSET(SftyMgt_noTarGearTra, 0);
   VEMS_vidSET(SftyMgt_stTqReqCha, 0);
   VEMS_vidSET(SftyMgt_tqMSRReqCha, 0);
   VEMS_vidSET(SftyMgt_rAccP, 0);
   VEMS_vidSET(SftyMgt_bBrkPedPrss, 0);
   VEMS_vidSET(SftyMgt_nEng, 0);
   VEMS_vidSET(SftyMgt_pBrkAsi, 20);
   VEMS_vidSET(SftyMgt_posnThr, 0);
   VEMS_vidSET(Ext_bInhDft, 0);
   VEMS_vidSET(SftyMgt_F329LocalLength, 0);
   VEMS_vidSET(SftyMgt_F349LocalLength, 0);
   VEMS_vidSET(SftyMgt_F38DLocalLength, 0);
   VEMS_vidSET(SftyMgt_bDftSftyStuckAccP, 0);
   VEMS_vidSET(SftyMgt_rCluPedSen, 0);
   VEMS_vidSET(SftyMgt_rNeutSen, 0);
   VEMS_vidSET(SftyMgt_uAccPSen1, 0);
   VEMS_vidSET(SftyMgt_uAccPSen2, 0);
   VEMS_vidSET(SftyMgt_uThrRef, 0);
   VEMS_vidSET(SftyMgt_uThrSen1, 0);
   VEMS_vidSET(SftyMgt_uThrSen2, 0);
   VEMS_vidSET(SftyMgt_bInpChk, 0);
   for(u8LocalIndex = 0; u8LocalIndex < 8; u8LocalIndex++)
   {
      VEMS_vidSET1DArrayElement(SftyMgt_F329MsgData, u8LocalIndex, 0);
   }
   for(u8LocalIndex1 = 0; u8LocalIndex1 < 8; u8LocalIndex1++)
   {
      VEMS_vidSET1DArrayElement(SftyMgt_F349MsgData, u8LocalIndex1, 0);
   }
   for(u8LocalIndex2 = 0; u8LocalIndex2 < 8; u8LocalIndex2++)
   {
      VEMS_vidSET1DArrayElement(SftyMgt_F38DMsgData, u8LocalIndex2, 0);
   }
   SFTYMGTIFTQ_u8AntiBounceCounter = 0;
   SFTYMGTIFTQ_bFilSig_1 = 0;
   SFTYMGTIFTQ_bStuckAccP = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidInpIgTqRelzd                                */
/* !Description :  Mise a jour de SftyMgt_agIgAdvCur                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_agIgSp;                                                 */
/*  output sint16 SftyMgt_agIgAdvCur;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidInpIgTqRelzd(void)
{
   uint8  u8LocalIgSys_agIgSp;
   sint16 s16LocalSftyMgt_agIgAdvCur;


   VEMS_vidGET(IgSys_agIgSp, u8LocalIgSys_agIgSp);
   s16LocalSftyMgt_agIgAdvCur = (sint16)(u8LocalIgSys_agIgSp - 96);
   VEMS_vidSET(SftyMgt_agIgAdvCur, s16LocalSftyMgt_agIgAdvCur);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidNoProdTqMon                                 */
/* !Description :  Ce block décrit les variables d’entrée d’une TMS non       */
/*                 produites dans un système V.E.E.S                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bInhDft;                                               */
/*  output boolean SftyMgt_bDftEM;                                            */
/*  output boolean Sfty3_bRstHwReq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidNoProdTqMon(void)
{
   VEMS_vidSET(Ext_bInhDft, 0);
   VEMS_vidSET(SftyMgt_bDftEM, 0);
   VEMS_vidSET(Sfty3_bRstHwReq, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidInhSftylvl2Afts                             */
/* !Description :  Inhibition de Safety niveau 2 en mode APV : Si le mode APV */
/*                 est activé, on inhibe la Safty niveau 2.                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Afts_bAcvModAfts;                                           */
/*  output boolean Ext_bInhDft;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidInhSftylvl2Afts(void)
{
   boolean bLocalECUbWkuMain;
   boolean bLocalAftsbAcvModAfts;

   VEMS_vidGET(ECU_bWkuMain, bLocalECUbWkuMain);
   VEMS_vidGET(Afts_bAcvModAfts, bLocalAftsbAcvModAfts);

   if (bLocalECUbWkuMain != 0)
   {
      if (bLocalAftsbAcvModAfts != 0)
      {
         VEMS_vidSET(Ext_bInhDft, 1);
      }
      else
      {
         VEMS_vidSET(Ext_bInhDft, 0);
      }
   }
   else
   {
      VEMS_vidSET(Ext_bInhDft, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidEeprom                                      */
/* !Description :  Eeprom update                                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NVMSRV_bIsOk();                                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input boolean SftyMgt_bEepromStatus;                                      */
/*  input uint8 SftyMgt_ctDftLaddNew;                                         */
/*  input uint16 SftyMgt_ctWrMem;                                             */
/*  input uint32 SftyMgt_prm_bDftHis[4];                                      */
/*  input uint16 SftyMgt_prm_bFrfNew[8];                                      */
/*  input uint8 SftyMgt_ctDftLaddDftConf_C;                                   */
/*  input uint16 SftMgt_ctWrMemDftConf_C;                                     */
/*  input uint32 SftyMgt_prm_bDftHisDftConf_C[4];                             */
/*  input uint16 SftyMgt_prm_bFrfDftConf_C[8];                                */
/*  output boolean SftyMgt_bEepromStatus;                                     */
/*  output uint8 ECU_ctDftLadd;                                               */
/*  output uint16 ECU_ctWrMem;                                                */
/*  output uint32 ECU_prm_bDftHis[4];                                         */
/*  output uint16 ECU_prm_bFrf[8];                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidEeprom(void)
{
   boolean bLocalbIsOk;
   uint8   u8LocalSftyMgt_ctDftLaddNew;
   uint8   u8LocalECU_ctDftLadd;
   uint8   u8LocalInd;
   uint16  u16LocalSftyMgt_ctWrMem;
   uint16  u16LocalECU_ctWrMem;
   uint16  u16LocalSftyMgt_prm_bFrfNew[SFTYMGTIFTQ_u8ARRAY8_LENGTH];
   uint16  u16LocalECU_prm_bFrf[SFTYMGTIFTQ_u8ARRAY8_LENGTH];
   uint32  u32LocalSftyMgt_prm_bDftHis[SFTYMGTIFTQ_u8ARRAY4_LENGTH];
   uint32  u32LocalECU_prm_bDftHis[SFTYMGTIFTQ_u8ARRAY4_LENGTH];


   bLocalbIsOk = NVMSRV_bIsOk();
   if (bLocalbIsOk == SftyMgt_NVMSRV_StatusOK)
   {
      SftyMgt_bEepromStatus = 1;
   }
   else
   {
      SftyMgt_bEepromStatus = 0;
   }

   if (SftyMgt_bEepromStatus != 0)
   {
      VEMS_vidGET(SftyMgt_ctDftLaddNew, u8LocalSftyMgt_ctDftLaddNew);
      VEMS_vidGET(SftyMgt_ctWrMem, u16LocalSftyMgt_ctWrMem);
      VEMS_vidGET1DArray(SftyMgt_prm_bDftHis,
                         SFTYMGTIFTQ_u8ARRAY4_LENGTH,
                         u32LocalSftyMgt_prm_bDftHis);
      VEMS_vidGET1DArray(SftyMgt_prm_bFrfNew,
                         SFTYMGTIFTQ_u8ARRAY8_LENGTH,
                         u16LocalSftyMgt_prm_bFrfNew);

      u8LocalSftyMgt_ctDftLaddNew =
         (uint8)MATHSRV_udtMIN(u8LocalSftyMgt_ctDftLaddNew, 9);
      u16LocalSftyMgt_ctWrMem = (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_ctWrMem,
                                                       65000);
      u32LocalSftyMgt_prm_bDftHis[SFTYMGTIFTQ_u8ARRAY4_LENGTH - 1] =
         ( u32LocalSftyMgt_prm_bDftHis[SFTYMGTIFTQ_u8ARRAY4_LENGTH - 1]
         & 0xFFFFFFF8UL);
      u16LocalSftyMgt_prm_bFrfNew[SFTYMGTIFTQ_u8ARRAY8_LENGTH - 1] =
         (uint16)( u16LocalSftyMgt_prm_bFrfNew[SFTYMGTIFTQ_u8ARRAY8_LENGTH - 1]
                 & 0xFF00);

      VEMS_vidSET(ECU_ctDftLadd, u8LocalSftyMgt_ctDftLaddNew);
      VEMS_vidSET(ECU_ctWrMem, u16LocalSftyMgt_ctWrMem);
      VEMS_vidSET1DArray(ECU_prm_bDftHis,
                         SFTYMGTIFTQ_u8ARRAY4_LENGTH,
                         u32LocalSftyMgt_prm_bDftHis);
      VEMS_vidSET1DArray(ECU_prm_bFrf,
                         SFTYMGTIFTQ_u8ARRAY8_LENGTH,
                         u16LocalSftyMgt_prm_bFrfNew);
   }
   else
   {
      u8LocalECU_ctDftLadd =
         (uint8)MATHSRV_udtMIN(SftyMgt_ctDftLaddDftConf_C, 9);
      u16LocalECU_ctWrMem =
         (uint16)MATHSRV_udtMIN(SftMgt_ctWrMemDftConf_C, 65000);

      for (u8LocalInd = 0;
           u8LocalInd < (SFTYMGTIFTQ_u8ARRAY4_LENGTH - 1);
           u8LocalInd++)
      {
         u32LocalECU_prm_bDftHis[u8LocalInd] =
            SftyMgt_prm_bDftHisDftConf_C[u8LocalInd];
      }
      u32LocalECU_prm_bDftHis[SFTYMGTIFTQ_u8ARRAY4_LENGTH - 1] =
         ( SftyMgt_prm_bDftHisDftConf_C[SFTYMGTIFTQ_u8ARRAY4_LENGTH - 1]
         & 0xFFFFFFF8UL);

      for (u8LocalInd = 0;
           u8LocalInd < (SFTYMGTIFTQ_u8ARRAY8_LENGTH - 1);
           u8LocalInd++)
      {
         u16LocalECU_prm_bFrf[u8LocalInd] =
            SftyMgt_prm_bFrfDftConf_C[u8LocalInd];
      }
      u16LocalECU_prm_bFrf[SFTYMGTIFTQ_u8ARRAY8_LENGTH - 1] =
         (uint16)( SftyMgt_prm_bFrfDftConf_C[SFTYMGTIFTQ_u8ARRAY8_LENGTH - 1]
                 & 0xFF00);

      VEMS_vidSET(ECU_ctDftLadd, u8LocalECU_ctDftLadd);
      VEMS_vidSET(ECU_ctWrMem, u16LocalECU_ctWrMem);
      VEMS_vidSET1DArray(ECU_prm_bDftHis,
                         SFTYMGTIFTQ_u8ARRAY4_LENGTH,
                         u32LocalECU_prm_bDftHis);
      VEMS_vidSET1DArray(ECU_prm_bFrf,
                         SFTYMGTIFTQ_u8ARRAY8_LENGTH,
                         u16LocalECU_prm_bFrf);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidSensInpCkSftyLvl2                           */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes des      */
/*                 capteurs des pédales Accel, Frien et Embrayage, Vitesse    */
/*                 Vehicule, Papillon et Position Point Mort                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidAcPInpChkSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidBrkInpChkSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidVehSpdInpSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidThrInpChkSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidCluInpChkSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidNeutPosnSftyLvl2();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidSensInpCkSftyLvl2(void)
{
   SFTYMGTIFTQ_vidAcPInpChkSftyLvl2();
   SFTYMGTIFTQ_vidBrkInpChkSftyLvl2();
   SFTYMGTIFTQ_vidVehSpdInpSftyLvl2();
   SFTYMGTIFTQ_vidThrInpChkSftyLvl2();
   SFTYMGTIFTQ_vidCluInpChkSftyLvl2();
   SFTYMGTIFTQ_vidNeutPosnSftyLvl2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidAcPInpChkSftyLvl2                           */
/* !Description :  Ce bloc produit le résultat des diagnostics safety level 2 */
/*                 réalisés sur les entrées sécuritaires provenantes des      */
/*                 capteurs de la pédale Accel.                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftSftyStuckAccP;                                  */
/*  input boolean SftyMgt_bDftSftyCoh_AccP;                                   */
/*  output boolean SftyMgt_bInpChkAccP;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidAcPInpChkSftyLvl2(void)
{
   boolean bLocalDftSftyStuckAccP;
   boolean bLocalDftSftyCoh_AccP;
   boolean bLocal_AcvTreatSftyLvl2AccP;


   bLocal_AcvTreatSftyLvl2AccP = GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2ACCP);

   VEMS_vidGET(SftyMgt_bDftSftyStuckAccP, bLocalDftSftyStuckAccP);
   VEMS_vidGET(SftyMgt_bDftSftyCoh_AccP, bLocalDftSftyCoh_AccP);

   if (  (  (bLocalDftSftyStuckAccP != 0)
         && (bLocal_AcvTreatSftyLvl2AccP == 0))
      || (  (bLocalDftSftyCoh_AccP != 0)
         && (bLocal_AcvTreatSftyLvl2AccP == 0)))
   {
      SftyMgt_bInpChkAccP = 1;
   }
   else
   {
      SftyMgt_bInpChkAccP = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidBrkInpChkSftyLvl2                           */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes des      */
/*                 capteurs de la pédale de Frein                             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftSftyInvCoh_BrkPed;                              */
/*  output boolean SftyMgt_bInpChkBrk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidBrkInpChkSftyLvl2(void)
{
   boolean bLocalDftSftyInvCoh_BrkPed;
   boolean bLocal_AcvTreatSftyLvl2Brk;


   bLocal_AcvTreatSftyLvl2Brk = GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2BRK);

   VEMS_vidGET(SftyMgt_bDftSftyInvCoh_BrkPed, bLocalDftSftyInvCoh_BrkPed);

   if (  (bLocalDftSftyInvCoh_BrkPed != 0)
      && (bLocal_AcvTreatSftyLvl2Brk == 0))
   {
      SftyMgt_bInpChkBrk = 1;
   }
   else
   {
      SftyMgt_bInpChkBrk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidVehSpdInpSftyLvl2                           */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes de la    */
/*                 Vitesse Vehicule.                                          */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftSftyCoh_VehSpd;                                 */
/*  output boolean SftyMgt_bInpChkVehSpd;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidVehSpdInpSftyLvl2(void)
{
   boolean bLocalDftSftyCoh_VehSpd;
   boolean bLocal_AcvTreatSftyLvl2VehSpd;


   bLocal_AcvTreatSftyLvl2VehSpd =
      GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2VEHSPD);

   VEMS_vidGET(SftyMgt_bDftSftyCoh_VehSpd, bLocalDftSftyCoh_VehSpd);

   if (  (bLocalDftSftyCoh_VehSpd != 0)
      && (bLocal_AcvTreatSftyLvl2VehSpd == 0))
   {
      SftyMgt_bInpChkVehSpd = 1;
   }
   else
   {
      SftyMgt_bInpChkVehSpd = 0;
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/