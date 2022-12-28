/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PREDES                                                  */
/* !Description     : PREDES Component.                                       */
/*                                                                            */
/* !Module          : PREDES                                                  */
/* !Description     : Engine speed prediction during the engine stop          */
/*                                                                            */
/* !File            : PREDES_FCT1.C                                           */
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
/*   1 / PREDES_vidInitOutput                                                 */
/*   2 / PREDES_vidGlobalView                                                 */
/*   3 / PREDES_vidActCalStrtEngaAuthrEng                                     */
/*   4 / PREDES_vidCalcStrtEngaAuthrEng                                       */
/*   5 / PREDES_vidCreatLvlBtw6DgrVarNFct                                     */
/*   6 / PREDES_vidCalcStrtrEngaAfrEngDir                                     */
/*   7 / PREDES_vidDetectSmallEngSpdOsc                                       */
/*   8 / PREDES_vidSetSmallEngSpdOscDtct                                      */
/*   9 / PREDES_vidCalcStrtrEngaBfrEngDir                                     */
/*   10 / PREDES_vidChkIfCndToFilbfrRFlfld                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5141019 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_3146 / 2.3                                      */
/* !OtherRefs   : VEMS V02 ECU#053617                                         */
/* !OtherRefs   : VEMS V02 ECU#062167                                         */
/* !OtherRefs   : VEMS V02 ECU#064286                                         */
/* !OtherRefs   : VEMS V02 ECU#065488                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PREDES.h"
#include "PREDES_L.h"
#include "PREDES_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidInitOutput                                       */
/* !Description :  Fonction initialisation.                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 PredEs_ctOkOscN_NV;                                           */
/*  input uint16 PredEs_tiErrOkN2EgdChgDir_NV;                                */
/*  input uint16 PredEs_tiErrOkN2EgdChgDir2_NV;                               */
/*  output uint8 PredEs_noOkOscN_MP;                                          */
/*  output uint16 PredEs_tiErrOkN2EgdChgDir;                                  */
/*  output boolean PredEs_bFirstClcPredEs;                                    */
/*  output uint8 PREDES_idxLstBufTiWrPrev;                                    */
/*  output boolean PREDES_bOkOscNRawPrev;                                     */
/*  output boolean PREDES_bInfoCplStPrev;                                     */
/*  output boolean PREDES_bRisingEdgeInPrev1;                                 */
/*  output boolean PREDES_bRisingEdgeInPrev2;                                 */
/*  output boolean PREDES_bRisingEdgeInPrev3;                                 */
/*  output boolean PredEs_bDirRotCk;                                          */
/*  output boolean PREDES_bFlipFlopNotOut1;                                   */
/*  output uint16 PredEs_nMaxOsc_MP;                                          */
/*  output uint8 PredEs_noTrigBufTi;                                          */
/*  output boolean PREDES_bTmrOut;                                            */
/*  output boolean PREDES_bTmrOutPrev;                                        */
/*  output uint8 PREDES_u8Cnt;                                                */
/*  output uint16 PredEs_tiCntCgtPrev;                                        */
/*  output boolean PREDES_bFlipFlopOut2;                                      */
/*  output boolean PREDES_bFlipFlopOut2Prev;                                  */
/*  output uint8 PredEs_noNFill180_MP;                                        */
/*  output uint8 PredEs_noNFill;                                              */
/*  output boolean PredEs_bVldTiLstCgtUpd;                                    */
/*  output uint16 PredEs_tiMaxBufMin_MP;                                      */
/*  output uint16 PredEs_tiMinBufMax_MP;                                      */
/*  output boolean PREDES_bFlipFlopOut3;                                      */
/*  output boolean PREDES_bFlipFlopOut5;                                      */
/*  output boolean PredEs_bVldOkN2EgdSave;                                    */
/*  output boolean PredEs_bOkN2EgdChgDir;                                     */
/*  output boolean PREDES_bTmr1Out;                                           */
/*  output boolean PREDES_bTmr1OutPrev;                                       */
/*  output uint8 PREDES_u8Cnt1;                                               */
/*  output boolean PREDES_bTmrRstOut2;                                        */
/*  output sint16 PredEs_nPredLoRaw;                                          */
/*  output sint16 PredEs_nCurRaw;                                             */
/*  output sint16 PredEs_nPredInter;                                          */
/*  output sint16 PredEs_nCorPred;                                            */
/*  output uint8 PredEs_idxLstBufWr;                                          */
/*  output uint8 PredEs_idxLstBufWrDyn_MP;                                    */
/*  output uint16 PredEs_tiCntPred;                                           */
/*  output uint8 PredEs_noTrigCor;                                            */
/*  output sint16 PredEs_n2DecE2TDC;                                          */
/*  output uint8 PredEs_agEng;                                                */
/*  output uint8 PredEs_agEngDly;                                             */
/*  output uint8 PredEs_agMissCgt360;                                         */
/*  output boolean PredEs_bAcvClcPredCurN;                                    */
/*  output boolean PredEs_bAcvClcPredNHi;                                     */
/*  output boolean PredEs_bAcvClcPredNLo;                                     */
/*  output boolean PredEs_bAcvRecBuf;                                         */
/*  output boolean PredEs_bAcvRecBuf0_MP;                                     */
/*  output boolean PredEs_bClcPredCurN;                                       */
/*  output boolean PredEs_bClcPredEs;                                         */
/*  output boolean PredEs_bClcPredN;                                          */
/*  output boolean PredEs_bClcPredNHi;                                        */
/*  output boolean PredEs_bClcPredNIntl;                                      */
/*  output boolean PredEs_bCndStop;                                           */
/*  output boolean PredEs_bDetChgDir;                                         */
/*  output boolean PredEs_bDetSlowNPredRaw;                                   */
/*  output boolean PredEs_bEngSyncAccu;                                       */
/*  output boolean PredEs_bNotCgtLstFct;                                      */
/*  output boolean PredEs_bOkCndIntl;                                         */
/*  output boolean PredEs_bOkOscN;                                            */
/*  output boolean PredEs_bOkOscNRaw;                                         */
/*  output boolean PredEs_bTrigIni;                                           */
/*  output boolean PredEs_bTypCgt;                                            */
/*  output boolean PredEs_bTypCgt180First;                                    */
/*  output boolean PredEs_bVldCurNCll;                                        */
/*  output boolean PredEs_bVldCurNCll_MP;                                     */
/*  output boolean PredEs_bVldCurNCor;                                        */
/*  output boolean PredEs_bVldOKN2Egd_MP;                                     */
/*  output boolean PredEs_bVldTiLstCgt;                                       */
/*  output boolean PredEs_bVldTiLstCgtRaw_MP;                                 */
/*  output boolean PREDES_bFirstClcPredEsPrev;                                */
/*  output uint8 PredEs_idxLstBufTiWr;                                        */
/*  output uint8 PredEs_idxLstTDCChgDir_MP;                                   */
/*  output uint16 PredEs_n2CgtLstTDCChgDir_MP;                                */
/*  output uint16 PredEs_n2ChgDir_MP;                                         */
/*  output sint16 PredEs_n2DecE2TDCRaw_MP;                                    */
/*  output sint16 PredEs_n2DecE2TDCSave_MP;                                   */
/*  output sint16 PredEs_n2DecEPred;                                          */
/*  output sint16 PredEs_n2PredCur_MP;                                        */
/*  output sint16 PredEs_n2PredInter;                                         */
/*  output sint16 PredEs_nCurCor;                                             */
/*  output sint16 PredEs_nCurRaw_MP;                                          */
/*  output sint16 PredEs_nLstTDCChgDir_MP;                                    */
/*  output uint16 PredEs_nPredCur_MP;                                         */
/*  output sint16 PredEs_nPredHiRaw;                                          */
/*  output sint16 PredEs_nPredInterPrev;                                      */
/*  output sint16 PredEs_nStaEgdLoThd;                                        */
/*  output uint8 PredEs_noCgt;                                                */
/*  output uint8 PredEs_noCgtLstCgtChgDir;                                    */
/*  output uint8 PredEs_noCgtPhaEng;                                          */
/*  output uint8 PredEs_noIniCnd;                                             */
/*  output uint8 PredEs_noNFillTi;                                            */
/*  output uint8 PredEs_noTrig;                                               */
/*  output uint8 PredEs_noTrigBufNEs;                                         */
/*  output uint8 PredEs_noTrigBufNEs_MP;                                      */
/*  output uint8 PredEs_noTrigInc;                                            */
/*  output uint8 PredEs_noTypCgt;                                             */
/*  output uint32 PredEs_ti3LstCgtClc_MP;                                     */
/*  output uint16 PredEs_ti3LstCgtCor_MP;                                     */
/*  output uint32 PredEs_tiCgtCor;                                            */
/*  output uint32 PredEs_tiCgtLst_MP;                                         */
/*  output uint32 PredEs_tiCgt_MP;                                            */
/*  output uint16 PredEs_tiCntCgt;                                            */
/*  output sint16 PredEs_tiCntFct2CntCgt;                                     */
/*  output uint16 PredEs_tiCntPredPrev;                                       */
/*  output uint16 PredEs_tiDlyLstClcN;                                        */
/*  output uint16 PredEs_tiDlyLstClcNNew;                                     */
/*  output sint16 PredEs_tiErrOkN2EgdInc_MP;                                  */
/*  output uint32 PredEs_tiLst2CgtCor;                                        */
/*  output uint32 PredEs_tiLstCgtCor;                                         */
/*  output uint16 PredEs_tiMaxBufMax;                                         */
/*  output uint16 PredEs_tiMaxBufMinRaw_MP;                                   */
/*  output uint16 PredEs_tiMaxBufPrevMin_MP;                                  */
/*  output uint16 PredEs_tiMinBufMaxRaw_MP;                                   */
/*  output uint16 PredEs_tiMinBufPrevMax_MP;                                  */
/*  output uint16 PredEs_tiStaEgdHiThd;                                       */
/*  output boolean PREDES_bOkOscPrev;                                         */
/*  output boolean PREDES_bOkN2EgdPrev;                                       */
/*  output sint16 PredEs_prm_idxBufTiWr_MP[3];                                */
/*  output uint16 PredEs_prm_nBuf[255];                                       */
/*  output boolean PredEs_bDetSlowNPred;                                      */
/*  output boolean PredEs_bSecPhaPred;                                        */
/*  output boolean PredEs_bSecPhaSecu;                                        */
/*  output sint16 PredEs_nCurCor2;                                            */
/*  output uint16 PredEs_tiErrOkN2EgdChgDir2;                                 */
/*  output boolean PREDES_bStrtTmrRst2Prev;                                   */
/*  output boolean PREDES_bFallEdgStrtTmrRst2Prev;                            */
/*  output boolean PREDES_bStrtTmrRst1Prev;                                   */
/*  output uint8 PREDES_u8IncrCounter;                                        */
/*  output uint8 PREDES_u8CntTmrRst2;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidInitOutput(void)
{
   uint8  u8LocalCnt;
   uint32 u32LocalErrOkN2EgdChgDir_NV;
   uint32 u32LocalPredEs_tiErrOkN2Dir2_NV;


   PredEs_noOkOscN_MP = PredEs_ctOkOscN_NV;
   u32LocalErrOkN2EgdChgDir_NV =
      (uint32)(PredEs_tiErrOkN2EgdChgDir_NV * 5);
   PredEs_tiErrOkN2EgdChgDir =
      (uint16)MATHSRV_udtMIN(u32LocalErrOkN2EgdChgDir_NV, 65000);

   PredEs_bFirstClcPredEs = 0;
   PREDES_idxLstBufTiWrPrev = 0;
   PREDES_bOkOscNRawPrev = 0;
   PREDES_bInfoCplStPrev = 0;
   PREDES_bRisingEdgeInPrev1 = 0;
   PREDES_bRisingEdgeInPrev2 = 0;
   PREDES_bRisingEdgeInPrev3 = 0;
   PredEs_bDirRotCk = 1;
   PREDES_bFlipFlopNotOut1 = 1;
   PredEs_nMaxOsc_MP = 0;
   PredEs_noTrigBufTi = 0;
   PREDES_bTmrOut = 0;
   PREDES_bTmrOutPrev = 0;
   PREDES_u8Cnt = 0;
   PredEs_tiCntCgtPrev = 0;
   PREDES_bFlipFlopOut2 = 0;
   PREDES_bFlipFlopOut2Prev = 0;
   PredEs_noNFill180_MP = 0;
   PredEs_noNFill = 0;
   PredEs_bVldTiLstCgtUpd = 0;
   PredEs_tiMaxBufMin_MP = 50000;
   PredEs_tiMinBufMax_MP = 0;
   PREDES_bFlipFlopOut3 = 1;
   PREDES_bFlipFlopOut5 = 1;
   PredEs_bVldOkN2EgdSave = 0;
   PredEs_bOkN2EgdChgDir = 0;
   PREDES_bTmr1Out = 0;
   PREDES_bTmr1OutPrev = 0;
   PREDES_u8Cnt1 = 0;
   PREDES_bTmrRstOut2 = 0;
   PredEs_nPredLoRaw = 0;
   PredEs_nCurRaw = 0;
   PredEs_nPredInter = 0;
   PredEs_nCorPred = 0;
   PredEs_idxLstBufWr = 0;
   PredEs_idxLstBufWrDyn_MP = 0;
   PredEs_tiCntPred = 0;
   PredEs_noTrigCor = 0;
   PredEs_n2DecE2TDC = 1953;
   PredEs_agEng = 0;
   PredEs_agEngDly = 0;
   PredEs_agMissCgt360 = 0;
   PredEs_bAcvClcPredCurN = 0;
   PredEs_bAcvClcPredNHi = 0;
   PredEs_bAcvClcPredNLo = 0;
   PredEs_bAcvRecBuf = 0;
   PredEs_bAcvRecBuf0_MP = 0;
   PredEs_bClcPredCurN = 0;
   PredEs_bClcPredEs = 0;
   PredEs_bClcPredN = 0;
   PredEs_bClcPredNHi = 0;
   PredEs_bClcPredNIntl = 0;
   PredEs_bCndStop = 0;
   PredEs_bDetChgDir = 0;
   PredEs_bDetSlowNPredRaw = 0;
   PredEs_bEngSyncAccu = 0;
   PredEs_bNotCgtLstFct = 0;
   PredEs_bOkCndIntl = 0;
   PredEs_bOkOscN = 0;
   PredEs_bOkOscNRaw = 0;
   PredEs_bTrigIni = 0;
   PredEs_bTypCgt = 0;
   PredEs_bTypCgt180First = 0;
   PredEs_bVldCurNCll = 0;
   PredEs_bVldCurNCll_MP = 0;
   PredEs_bVldCurNCor = 0;
   PredEs_bVldOKN2Egd_MP = 0;
   PredEs_bVldTiLstCgt = 0;
   PredEs_bVldTiLstCgtRaw_MP = 0;
   PREDES_bFirstClcPredEsPrev = 0;
   PredEs_idxLstBufTiWr = 0;
   PredEs_idxLstTDCChgDir_MP = 0;
   PredEs_n2CgtLstTDCChgDir_MP = 1953;
   PredEs_n2ChgDir_MP = 1953;
   PredEs_n2DecE2TDCRaw_MP = 1953;
   PredEs_n2DecE2TDCSave_MP = (sint16)(7188 / Ext_noCylEng_SC);
   PredEs_n2DecEPred = 1953;
   PredEs_n2PredCur_MP = 1953;
   PredEs_n2PredInter = 1953;
   PredEs_nCurCor = 0;
   PredEs_nCurRaw_MP = 0;
   PredEs_nLstTDCChgDir_MP = 0;
   PredEs_nPredCur_MP = 0;
   PredEs_nPredHiRaw = 0;
   PredEs_nPredInterPrev = 0;
   PredEs_nStaEgdLoThd = 0;
   PredEs_noCgt = 0;
   PredEs_noCgtLstCgtChgDir = 0;
   PredEs_noCgtPhaEng = 0;
   PredEs_noIniCnd = 0;
   PredEs_noNFillTi = 0;
   PredEs_noTrig = 0;
   PredEs_noTrigBufNEs = 0;
   PredEs_noTrigBufNEs_MP = 0;
   PredEs_noTrigInc = 0;
   PredEs_noTypCgt = 0;
   PredEs_ti3LstCgtClc_MP = 500000;
   PredEs_ti3LstCgtCor_MP = 0;
   PredEs_tiCgtCor = 500000;
   PredEs_tiCgtLst_MP = 500000;
   PredEs_tiCgt_MP = 500000;
   PredEs_tiCntCgt = 0;
   PredEs_tiCntFct2CntCgt = 0;
   PredEs_tiCntPredPrev = 0;
   PredEs_tiDlyLstClcN = 0;
   PredEs_tiDlyLstClcNNew = 0;
   PredEs_tiErrOkN2EgdInc_MP = 0;
   PredEs_tiLst2CgtCor = 500000;
   PredEs_tiLstCgtCor = 500000;
   PredEs_tiMaxBufMax = 25000;
   PredEs_tiMaxBufMinRaw_MP = 0;
   PredEs_tiMaxBufPrevMin_MP = 0;
   PredEs_tiMinBufMaxRaw_MP = 0;
   PredEs_tiMinBufPrevMax_MP = 0;
   PredEs_tiStaEgdHiThd = 0;
   PREDES_bOkOscPrev = 0;
   PREDES_bOkN2EgdPrev = 0;
   PredEs_prm_idxBufTiWr_MP[0] = 0;
   PredEs_prm_idxBufTiWr_MP[1] = 0;
   PredEs_prm_idxBufTiWr_MP[2] = 0;
   for (u8LocalCnt = 0; u8LocalCnt < 255; u8LocalCnt++)
   {
      PredEs_prm_nBuf[u8LocalCnt] = 0;
   }

   VEMS_vidSET(PredEs_bDetSlowNPred, 0);
   PredEs_bSecPhaPred = 0;
   PredEs_bSecPhaSecu = 0;
   PredEs_nCurCor2 = 0;
   u32LocalPredEs_tiErrOkN2Dir2_NV = (PredEs_tiErrOkN2EgdChgDir2_NV * 5);
   PredEs_tiErrOkN2EgdChgDir2 =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiErrOkN2Dir2_NV, 65000);
   PREDES_bStrtTmrRst2Prev = 0;
   PREDES_bFallEdgStrtTmrRst2Prev = 0;
   PREDES_bStrtTmrRst1Prev = 0;
   PREDES_u8IncrCounter = 0;
   PREDES_u8CntTmrRst2 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidGlobalView                                       */
/* !Description :  This block indicates if a starter engagement could be      */
/*                 requested.                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidActCalStrtEngaAuthrEng();                      */
/*  extf argret void PREDES_vidCalcStrtEngaAuthrEng();                        */
/*  extf argret void PREDES_vidCorrOutIfCalcDisabled();                       */
/*  input boolean PredEs_bClcPredEs;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidGlobalView(void)
{
   PREDES_vidActCalStrtEngaAuthrEng();
   if (PredEs_bClcPredEs != 0)
   {
      PREDES_vidCalcStrtEngaAuthrEng();
   }
   PREDES_vidCorrOutIfCalcDisabled();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidActCalStrtEngaAuthrEng                           */
/* !Description :  This block disables the function calculation, if the engine*/
/*                 speed is higher than a threshold.                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 PredEs_nThdAcvFct_C;                                          */
/*  input boolean PredEs_bClcPredEs;                                          */
/*  output boolean PredEs_bClcPredEs;                                         */
/*  output boolean PredEs_bFirstClcPredEs;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidActCalStrtEngaAuthrEng(void)
{
   boolean bLocalPredEs_bClcPredEs;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalPredEs_nThdAcvFct;


   /*Production of PredEs_bClcPredEs*/
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalPredEs_nThdAcvFct = (uint16)(PredEs_nThdAcvFct_C * 10);
   bLocalPredEs_bClcPredEs = PredEs_bClcPredEs;
   if (u16LocalExt_nEng < u16LocalPredEs_nThdAcvFct)
   {
      PredEs_bClcPredEs = 1;
   }
   else
   {
      PredEs_bClcPredEs = 0;
   }

   /*Production of PredEs_bFirstClcPredEs*/
   if (  (PredEs_bClcPredEs != 0)
      && (bLocalPredEs_bClcPredEs == 0))
   {
      PredEs_bFirstClcPredEs = 1;
   }
   else
   {
      PredEs_bFirstClcPredEs = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcStrtEngaAuthrEng                             */
/* !Description :  This bloc calculates the starter engagement authorization. */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidCreatLvlBtw6DgrVarNFct();                      */
/*  extf argret void PREDES_vidCalcStrtrEngaAfrEngDir();                      */
/*  extf argret void PREDES_vidCalcStrtrEngaBfrEngDir();                      */
/*  extf argret void PREDES_vidMergThe2Authorizations();                      */
/*  input boolean PredEs_bAcvOKOscN_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcStrtEngaAuthrEng(void)
{
   PREDES_vidCreatLvlBtw6DgrVarNFct();
   if (PredEs_bAcvOKOscN_C != 0)
   {
      PREDES_vidCalcStrtrEngaAfrEngDir();
   }
   PREDES_vidCalcStrtrEngaBfrEngDir();
   PREDES_vidMergThe2Authorizations();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCreatLvlBtw6DgrVarNFct                           */
/* !Description :  This block is a layer to check value of the variables      */
/*                 updated every crankshaft signal falling edge (With software*/
/*                 like INCA).                                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_008.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 BufNEs_idxLstBufWr;                                           */
/*  input uint8 PredEs_idxLstBufTiWr;                                         */
/*  input uint8 PREDES_idxLstBufTiWrPrev;                                     */
/*  input boolean PredEs_bTrigBufNEsSet_C;                                    */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input uint8 PredEs_noFirstTrigBufNEs_C;                                   */
/*  input uint8 PredEs_noTrigBufNEs_MP;                                       */
/*  input boolean Ext_bDirRotCk;                                              */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*  input uint8 Sync_agEng;                                                   */
/*  input uint8 BufNEs_noNFillTi;                                             */
/*  input boolean PredEs_bDirRotCk;                                           */
/*  output uint8 PREDES_idxLstBufTiWrPrev;                                    */
/*  output uint8 PredEs_idxLstBufTiWr;                                        */
/*  output uint8 PredEs_noTrigBufNEs_MP;                                      */
/*  output uint8 PredEs_noTrigBufNEs;                                         */
/*  output boolean PREDES_bDirRotCkPrev;                                      */
/*  output boolean PredEs_bDirRotCk;                                          */
/*  output boolean PredEs_bEngSyncAccu;                                       */
/*  output uint8 PredEs_agEng;                                                */
/*  output uint8 PredEs_noNFillTi;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCreatLvlBtw6DgrVarNFct(void)
{
   boolean bLocalExt_bDirRotCk;
   boolean bLocalSync_bEngSyncAccu;
   uint8   u8LocalBufNEs_idxLstBufWr;
   uint8   u8LocalBufNEs_noNFillTi;
   uint8   u8LocalSync_agEng;
   sint16  s16LocalPredEs_noTrigBufNEs_MP;


   /*Production of PredEs_noTrigBufNEs_MP*/
   VEMS_vidGET(BufNEs_idxLstBufWr, u8LocalBufNEs_idxLstBufWr);
   PREDES_idxLstBufTiWrPrev = PredEs_idxLstBufTiWr;
   PredEs_idxLstBufTiWr = u8LocalBufNEs_idxLstBufWr;
   if (u8LocalBufNEs_idxLstBufWr < PREDES_idxLstBufTiWrPrev)
   {
      s16LocalPredEs_noTrigBufNEs_MP = (sint16)( ( u8LocalBufNEs_idxLstBufWr
                                                 - PREDES_idxLstBufTiWrPrev)
                                               + 12);
   }
   else
   {
      s16LocalPredEs_noTrigBufNEs_MP = (sint16)( u8LocalBufNEs_idxLstBufWr
                                               - PREDES_idxLstBufTiWrPrev);
   }
   PredEs_noTrigBufNEs_MP =
      (uint8)MATHSRV_udtMAX(s16LocalPredEs_noTrigBufNEs_MP, 0);

   /*Production of PredEs_noTrigBufNEs*/
   if (PredEs_bTrigBufNEsSet_C != 0)
   {
      PredEs_noTrigBufNEs = 1;
   }
   else
   {
      if (PredEs_bFirstClcPredEs != 0)
      {
         PredEs_noTrigBufNEs = PredEs_noFirstTrigBufNEs_C;
      }
      else
      {
         PredEs_noTrigBufNEs = PredEs_noTrigBufNEs_MP;
      }
   }

   VEMS_vidGET(Ext_bDirRotCk, bLocalExt_bDirRotCk);
   VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
   VEMS_vidGET(Sync_agEng, u8LocalSync_agEng);
   VEMS_vidGET(BufNEs_noNFillTi, u8LocalBufNEs_noNFillTi);

   /*Production of PredEs_bDirRotCk*/
   PREDES_bDirRotCkPrev = PredEs_bDirRotCk;
   if (bLocalExt_bDirRotCk != 0)
   {
      PredEs_bDirRotCk = 1;
   }
   else
   {
      PredEs_bDirRotCk = 0;
   }

   /*Production of PredEs_bEngSyncAccu*/
   if (bLocalSync_bEngSyncAccu != 0)
   {
      PredEs_bEngSyncAccu = 1;
   }
   else
   {
      PredEs_bEngSyncAccu = 0;
   }
   PredEs_agEng = (uint8)MATHSRV_udtMIN(u8LocalSync_agEng, 120);
   PredEs_noNFillTi = u8LocalBufNEs_noNFillTi;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcStrtrEngaAfrEngDir                           */
/* !Description :  This block checks if the engine speed is good to request an*/
/*                 engagement during oscillations engine (before final engine */
/*                 stop).                                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidDetectSmallEngSpdOsc();                        */
/*  extf argret void PREDES_vidSetSmallEngSpdOscDtct();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcStrtrEngaAfrEngDir(void)
{
   PREDES_vidDetectSmallEngSpdOsc();
   PREDES_vidSetSmallEngSpdOscDtct();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidDetectSmallEngSpdOsc                             */
/* !Description :  The maximal engine speed is recorded during the negative   */
/*                 oscillations. If the recorded maximal engine speed is      */
/*                 slower than maximal engagement engine speed, then an       */
/*                 engagement request authorization is valid.                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input boolean PredEs_bDirRotCk;                                           */
/*  input boolean PREDES_bDirRotCkPrev;                                       */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input uint8 PredEs_idxLstBufTiWr;                                         */
/*  input uint8 PREDES_idxLstBufTiWrPrev;                                     */
/*  input boolean Sync_bBackUpCkSig;                                          */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input uint16 CoEmCkg_nStaEgdHiThd;                                        */
/*  input uint16 PredEs_nMaxOsc_MP;                                           */
/*  input uint8 PredEs_noNFillTi;                                             */
/*  input boolean PREDES_bFlipFlopNotOut1;                                    */
/*  input uint32 BufNEs_prm_tiCgtBuf[12];                                     */
/*  input boolean PREDES_bOkOscPrev;                                          */
/*  output boolean PREDES_bFlipFlopNotOut1;                                   */
/*  output uint16 PredEs_nMaxOsc_MP;                                          */
/*  output boolean PredEs_bOkOscNRaw;                                         */
/*  output boolean PREDES_bOkOscPrev;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidDetectSmallEngSpdOsc(void)
{
   boolean bLocalSync_bBackUpCkSig;
   boolean bLocalFRM_bAcvCoSyncDftCk;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalCond;
   uint8   u8LocalPredEs_idxLstBufTiWr;
   uint16  u16LocalCoEmCkg_nStaEgdHiThd;
   uint16  u16LocalPredEs_nMaxOsc_MP;
   uint32  u32LocalPrm_tiCgtBuf;
   uint32  u32LocalCalc;

   /*Flip flop*/
   if (  (PredEs_bDirRotCk != PREDES_bDirRotCkPrev)
      && (PredEs_bFirstClcPredEs == 0))
   {
      PREDES_bFlipFlopNotOut1 = 1;
   }
   else
   {
      if (  (PredEs_idxLstBufTiWr != PREDES_idxLstBufTiWrPrev)
         || (PredEs_bFirstClcPredEs != 0))
      {
         PREDES_bFlipFlopNotOut1 = 0;
      }
   }

   /*Production of PredEs_nMaxOsc_MP*/
   VEMS_vidGET(Sync_bBackUpCkSig, bLocalSync_bBackUpCkSig);
   bLocalFRM_bAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(CoEmCkg_nStaEgdHiThd, u16LocalCoEmCkg_nStaEgdHiThd);

   u16LocalPredEs_nMaxOsc_MP = PredEs_nMaxOsc_MP;
   if (  (bLocalSync_bBackUpCkSig != 0)
      || (bLocalFRM_bAcvCoSyncDftCk != 0)
      || (bLocalSync_bDgoCkSig != 0)
      || (PredEs_bFirstClcPredEs != 0)
      || (PredEs_noNFillTi < 1))
   {
      u16LocalPredEs_nMaxOsc_MP = 500;
   }
   else
   {
      if (  (PredEs_bDirRotCk == 0)
         && (PREDES_bFlipFlopNotOut1 != 0))
      {
         u16LocalPredEs_nMaxOsc_MP = 0;
      }
   }

   if (PredEs_bDirRotCk != 0)
   {
      PredEs_nMaxOsc_MP =
         (uint16)MATHSRV_udtMIN(u16LocalPredEs_nMaxOsc_MP, 1000);
   }
   else
   {
      u8LocalPredEs_idxLstBufTiWr = (uint8)(PredEs_idxLstBufTiWr % 12);
      VEMS_vidGET1DArrayElement( BufNEs_prm_tiCgtBuf,
                                 u8LocalPredEs_idxLstBufTiWr,
                                 u32LocalPrm_tiCgtBuf);
      u32LocalPrm_tiCgtBuf = MATHSRV_udtMAX(u32LocalPrm_tiCgtBuf, 1000);
      u32LocalCalc = (1000000 / u32LocalPrm_tiCgtBuf);
      u16LocalPredEs_nMaxOsc_MP =
         (uint16)MATHSRV_udtMAX(u32LocalCalc, u16LocalPredEs_nMaxOsc_MP);
      PredEs_nMaxOsc_MP =
         (uint16)MATHSRV_udtMIN(u16LocalPredEs_nMaxOsc_MP, 1000);
   }

   /*Production of PredEs_bOkOscNRaw*/
   if (  (PREDES_bFlipFlopNotOut1 != 0)
      && (PredEs_bDirRotCk != 0)
      && (PredEs_nMaxOsc_MP < u16LocalCoEmCkg_nStaEgdHiThd))
   {
      bLocalCond = 1;
   }
   else
   {
      bLocalCond = 0;
   }

   if (  (bLocalCond != 0)
      && (PREDES_bOkOscPrev == 0))
   {
      PredEs_bOkOscNRaw = 1;
   }
   else
   {
      PredEs_bOkOscNRaw = 0;
   }
   PREDES_bOkOscPrev = bLocalCond;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidSetSmallEngSpdOscDtct                            */
/* !Description :  This block checks, if the previous block request is valid. */
/*                 If errors occur, then this starter engagement request      */
/*                 during engine oscillations is disabled.                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoEmCkg_tiStaEgdHiThd;                                        */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input boolean PredEs_bOkOscNRaw;                                          */
/*  input boolean PREDES_bOkOscNRawPrev;                                      */
/*  input uint8 PREDES_u8Cnt;                                                 */
/*  input boolean PREDES_bTmrOut;                                             */
/*  input boolean PREDES_bTmrOutPrev;                                         */
/*  input boolean PredEs_bDirRotCk;                                           */
/*  input uint8 PredEs_noOkOscN_MP;                                           */
/*  output boolean PREDES_bTmrOut;                                            */
/*  output uint8 PREDES_u8Cnt;                                                */
/*  output boolean PREDES_bOkOscNRawPrev;                                     */
/*  output uint8 PredEs_noOkOscN_MP;                                          */
/*  output uint8 PredEs_ctOkOscN_NV;                                          */
/*  output boolean PredEs_bOkOscN;                                            */
/*  output boolean PREDES_bTmrOutPrev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidSetSmallEngSpdOscDtct(void)
{
   uint8  u8LocalCoEmCkg_tiStaEgdHiThd;
   sint16 s16LocalPredEs_noOkOscN_MP;


   VEMS_vidGET(CoEmCkg_tiStaEgdHiThd, u8LocalCoEmCkg_tiStaEgdHiThd);
   u8LocalCoEmCkg_tiStaEgdHiThd = (uint8)(u8LocalCoEmCkg_tiStaEgdHiThd / 10);

   /*TmrRst*/
   if (PredEs_bFirstClcPredEs != 0)
   {
      PREDES_bTmrOut = 0;
      PREDES_u8Cnt = 0;
   }
   else
   {
      if (  (PredEs_bOkOscNRaw != 0)
         && (PREDES_bOkOscNRawPrev == 0))
      {
         PREDES_u8Cnt = u8LocalCoEmCkg_tiStaEgdHiThd;
         if (PREDES_u8Cnt != 0)
         {
            PREDES_bTmrOut = 1;
         }
         else
         {
            PREDES_bTmrOut = 0;
         }
      }
      else
      {
         if (PREDES_u8Cnt > 0)
         {
            PREDES_u8Cnt = (uint8)(PREDES_u8Cnt - 1);
            if (PREDES_u8Cnt != 0)
            {
               PREDES_bTmrOut = 1;
            }
            else
            {
               PREDES_bTmrOut = 0;
            }
         }
         else
         {
            PREDES_bTmrOut = 0;
         }
      }
   }
   PREDES_bOkOscNRawPrev = PredEs_bOkOscNRaw;

   if (  (PredEs_bFirstClcPredEs == 0)
      && (PREDES_bTmrOut == 0)
      && (PREDES_bTmrOutPrev != 0))
   {
      if (PredEs_bDirRotCk != 0)
      {
         s16LocalPredEs_noOkOscN_MP = (sint16)(PredEs_noOkOscN_MP - 1);
      }
      else
      {
         s16LocalPredEs_noOkOscN_MP = (sint16)(PredEs_noOkOscN_MP + 10);
      }
   }
   else
   {
      s16LocalPredEs_noOkOscN_MP = (sint16)PredEs_noOkOscN_MP;
   }

   /*detectSat*/
   if (s16LocalPredEs_noOkOscN_MP <= 0)
   {
      PredEs_noOkOscN_MP = 0;
   }
   else
   {
      if (s16LocalPredEs_noOkOscN_MP >= 100)
      {
         PredEs_noOkOscN_MP = 100;
      }
      else
      {
         PredEs_noOkOscN_MP = (uint8)s16LocalPredEs_noOkOscN_MP;
      }
   }
   PredEs_ctOkOscN_NV = PredEs_noOkOscN_MP;

   /*Production of PredEs_bOkOscN*/
   if (  (PredEs_noOkOscN_MP < 30)
      && (PredEs_bOkOscNRaw != 0))
   {
      PredEs_bOkOscN = 1;
   }
   else
   {
      PredEs_bOkOscN = 0;
   }
   PREDES_bTmrOutPrev = PREDES_bTmrOut;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcStrtrEngaBfrEngDir                           */
/* !Description :  This block checks during deceleration phase (Before engine */
/*                 direction change), if the engine speed is good to request  */
/*                 an engagement.                                             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_012.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidChkIfCndToFilbfrRFlfld();                      */
/*  extf argret void PREDES_vidFillInstanEngSpdBuffer();                      */
/*  extf argret void PREDES_vidCalcPredictionSetpts();                        */
/*  extf argret void PREDES_vidPredictEngineSpeed();                          */
/*  extf argret void PREDES_vidFormatInformation();                           */
/*  extf argret void PREDES_vidEstmTibtwPrdEsNBufNEs();                       */
/*  output uint8 PredEs_noIniCnd;                                             */
/*  output uint16 PREDES_Sqrt_Bkpt[9];                                        */
/*  output uint16 PREDES_Sqrt_Table[9];                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcStrtrEngaBfrEngDir(void)
{
   PredEs_noIniCnd = 1;

   PREDES_Sqrt_Bkpt[0] = 0;
   PREDES_Sqrt_Bkpt[1] = 8;
   PREDES_Sqrt_Bkpt[2] = 122;
   PREDES_Sqrt_Bkpt[3] = 618;
   PREDES_Sqrt_Bkpt[4] = 1953;
   PREDES_Sqrt_Bkpt[5] = 4768;
   PREDES_Sqrt_Bkpt[6] = 9888;
   PREDES_Sqrt_Bkpt[7] = 18318;
   PREDES_Sqrt_Bkpt[8] = 31250;
   PREDES_Sqrt_Table[0] = 0;
   PREDES_Sqrt_Table[1] = 20;
   PREDES_Sqrt_Table[2] = 66;
   PREDES_Sqrt_Table[3] = 145;
   PREDES_Sqrt_Table[4] = 254;
   PREDES_Sqrt_Table[5] = 395;
   PREDES_Sqrt_Table[6] = 567;
   PREDES_Sqrt_Table[7] = 770;
   PREDES_Sqrt_Table[8] = 1000;

   PREDES_vidChkIfCndToFilbfrRFlfld();
   PREDES_vidFillInstanEngSpdBuffer();
   PREDES_vidCalcPredictionSetpts();
   PREDES_vidPredictEngineSpeed();
   PREDES_vidFormatInformation();
   PREDES_vidEstmTibtwPrdEsNBufNEs();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidChkIfCndToFilbfrRFlfld                           */
/* !Description :  This block checks if the conditions are present to fill the*/
/*                 instantaneous engine speed buffer (mainly during a stop    */
/*                 engine STT request).                                       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_013.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoEmCkg_bInfoCplSt;                                         */
/*  input boolean CoEmCkg_bInfoCplReq;                                        */
/*  input uint8 CoEmCkg_stStrtRstrtFbCmd;                                     */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean Sync_bBackUpCkSig;                                          */
/*  input uint8 CoEmCkg_stSTTCf;                                              */
/*  input boolean CoPtUH_bDrvTraOp;                                           */
/*  input uint8 PredEs_bAcvInfoCpl_C;                                         */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input boolean PredEs_bAcvRecBuf0_MP;                                      */
/*  input boolean PredEs_bDirRotCk;                                           */
/*  input boolean PredEs_bEngSyncAccu;                                        */
/*  input uint8 PredEs_noNFillTi;                                             */
/*  input boolean PREDES_bInfoCplStPrev;                                      */
/*  input boolean PredEs_bForcAcvRecBuf_C;                                    */
/*  output boolean PredEs_bAcvRecBuf0_MP;                                     */
/*  output boolean PredEs_bAcvRecBuf;                                         */
/*  output boolean PREDES_bInfoCplStPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidChkIfCndToFilbfrRFlfld(void)
{
   boolean bLocalCoEmCkg_bInfoCplSt;
   boolean bLocalCoEmCkg_bInfoCplReq;
   boolean bLocalFRM_bAcvCoSyncDftCk;
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalSync_bBackUpCkSig;
   boolean bLocalCoPtUH_bDrvTraOp;
   uint8   u8LocalCoEmCkg_stStrtRstrtFbCmd;
   uint8   u8LocalCoEmCkg_stSTTCf;


   /*Production of PredEs_bAcvRecBuf0_MP*/
   bLocalFRM_bAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);
   VEMS_vidGET(CoEmCkg_bInfoCplSt, bLocalCoEmCkg_bInfoCplSt);
   VEMS_vidGET(CoEmCkg_bInfoCplReq, bLocalCoEmCkg_bInfoCplReq);
   VEMS_vidGET(CoEmCkg_stStrtRstrtFbCmd, u8LocalCoEmCkg_stStrtRstrtFbCmd);
   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(Sync_bBackUpCkSig, bLocalSync_bBackUpCkSig);
   VEMS_vidGET(CoEmCkg_stSTTCf, u8LocalCoEmCkg_stSTTCf);
   VEMS_vidGET(CoPtUH_bDrvTraOp, bLocalCoPtUH_bDrvTraOp);

   if (  (  (PredEs_bAcvInfoCpl_C != 0)
         && (  (  (bLocalCoEmCkg_bInfoCplSt != 0)
               && (bLocalCoEmCkg_bInfoCplReq == 0))
            || (  (bLocalCoEmCkg_bInfoCplSt == 0)
               && (bLocalCoEmCkg_bInfoCplReq != 0))))
      || (bLocalFRM_bAcvCoSyncDftCk != 0)
      || (u8LocalCoEmCkg_stStrtRstrtFbCmd == 1)
      || (PredEs_bFirstClcPredEs != 0)
      || (bLocalSync_bDgoCkSig != 0)
      || (bLocalSync_bBackUpCkSig != 0))
   {
      PredEs_bAcvRecBuf0_MP = 0;
   }
   else
   {
      PredEs_bAcvRecBuf0_MP = 1;
   }

   /*Production of PredEs_bAcvRecBuf*/
   if (  (PredEs_bAcvRecBuf0_MP != 0)
      && (u8LocalCoEmCkg_stSTTCf == 1)
      && (PredEs_bDirRotCk != 0)
      && (PredEs_bEngSyncAccu != 0)
      && (bLocalCoPtUH_bDrvTraOp != 0)
      && (PredEs_noNFillTi >= 3)
      && (bLocalCoEmCkg_bInfoCplSt == PREDES_bInfoCplStPrev))
   {
      PredEs_bAcvRecBuf = 1;
   }
   else
   {
      if (PredEs_bForcAcvRecBuf_C != 0)
      {
         PredEs_bAcvRecBuf = 1;
      }
      else
      {
         PredEs_bAcvRecBuf = 0;
      }
   }
   PREDES_bInfoCplStPrev = bLocalCoEmCkg_bInfoCplSt;
}
/*------------------------------- end of file --------------------------------*/