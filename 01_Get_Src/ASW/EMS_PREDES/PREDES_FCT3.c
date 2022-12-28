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
/* !File            : PREDES_FCT3.C                                           */
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
/*   1 / PREDES_vidPredictEngineSpeed                                         */
/*   2 / PREDES_vidCoordinatWhileLoopPrt1                                     */
/*   3 / PREDES_vidCalculateIncrementStep                                     */
/*   4 / PREDES_vidCalEngSpdLnkWthWhilInc                                     */
/*   5 / PREDES_vidCalcCrkPosBfrEngDirChg                                     */
/*   6 / PREDES_vidCalculatPredictionTime                                     */
/*   7 / PREDES_vidCoordinatWhileLoopPrt2                                     */
/*   8 / PREDES_vidPredictEngSpdForDefiTi                                     */
/*   9 / PREDES_vidChkEngSpdToEngageStrtr                                     */
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
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidPredictEngineSpeed                               */
/* !Description :  This block calculates with loop the following variables:-  */
/*                 The engine speeds for the current time, - If the engine    */
/*                 speed is ranged from the minimal to the maximal engagement */
/*                 engine speed, - If the predicted engine speed with maximal */
/*                 duration has been made                                     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_024.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidCoordinatWhileLoopPrt1();                      */
/*  extf argret void PREDES_vidCalculateIncrementStep();                      */
/*  extf argret void PREDES_vidCalEngSpdLnkWthWhilInc();                      */
/*  extf argret void PREDES_vidCalcCrkPosBfrEngDirChg();                      */
/*  extf argret void PREDES_vidCalculatPredictionTime();                      */
/*  extf argret void PREDES_vidCoordinatWhileLoopPrt2();                      */
/*  extf argret void PREDES_vidPredictEngSpdForDefiTi();                      */
/*  extf argret void PREDES_vidChkEngSpdToEngageStrtr();                      */
/*  input uint8 PredEs_noIniCnd;                                              */
/*  input boolean PredEs_bCndStop;                                            */
/*  input uint8 PredEs_noTrig;                                                */
/*  input boolean PredEs_bDetChgDir;                                          */
/*  input boolean PredEs_bClcPredN;                                           */
/*  input boolean PredEs_bClcPredNIntl;                                       */
/*  output boolean PredEs_bCndStop;                                           */
/*  output uint8 PredEs_noTrig;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidPredictEngineSpeed(void)
{
   PredEs_bCndStop = 1;
   PredEs_noTrig = PredEs_noIniCnd;
   while ((PredEs_bCndStop != 0) && (PredEs_noTrig != 255))
   {
      PREDES_vidCoordinatWhileLoopPrt1();
      PREDES_vidCalculateIncrementStep();
      PREDES_vidCalEngSpdLnkWthWhilInc();
      if (PredEs_bDetChgDir != 0)
      {
         PREDES_vidCalcCrkPosBfrEngDirChg();
      }
      PREDES_vidCalculatPredictionTime();
      PREDES_vidCoordinatWhileLoopPrt2();
      if (PredEs_bClcPredN != 0)
      {
         PREDES_vidPredictEngSpdForDefiTi();
      }
      if (PredEs_bClcPredNIntl != 0)
      {
         PREDES_vidChkEngSpdToEngageStrtr();
      }
      PredEs_noTrig = (uint8)(PredEs_noTrig + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCoordinatWhileLoopPrt1                           */
/* !Description :  This block creates the flowing information:- The           */
/*                 calculation activation of the predicted variables, - The   */
/*                 called prediction calculation, - The stop condition of the */
/*                 while loop                                                 */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_040.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 PredEs_noTrig;                                                */
/*  output boolean PredEs_bTrigIni;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCoordinatWhileLoopPrt1(void)
{
   /*Production of PredEs_bTrigIni*/
   if (PredEs_noTrig == 1)
   {
      PredEs_bTrigIni = 1;
   }
   else
   {
      PredEs_bTrigIni = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalculateIncrementStep                           */
/* !Description :  This block calculates the teeth number to foresee. Also,   */
/*                 the increment between two call loop is determined.         */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean PredEs_bTrigIni;                                            */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint16 PredEs_prm_nBuf[255];                                        */
/*  input sint16 PredEs_nPredInter;                                           */
/*  input uint8 PredEs_nLim2Inc1_C;                                           */
/*  input uint8 PredEs_noTrigInc;                                             */
/*  input uint8 PredEs_noTrigCor;                                             */
/*  output uint8 PredEs_noTrigInc;                                            */
/*  output uint8 PredEs_noTrigCor;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalculateIncrementStep(void)
{
   uint8  u8LocalPredEs_idxLstBufWr;
   uint16 u16LocalPredEs_nLim2Inc1;
   uint16 u16LocalPredEs_noTrigCor;
   sint32 s32LocalSwitch;


   if (PredEs_bTrigIni != 0)
   {
      if (PredEs_noCaseBuf_C != 0)
      {
         u8LocalPredEs_idxLstBufWr =
            (uint8)(PredEs_idxLstBufWr % PredEs_noCaseBuf_C);
      }
      else
      {
         u8LocalPredEs_idxLstBufWr = 0;
         SWFAIL_vidSoftwareErrorHook();
      }
      s32LocalSwitch = (sint32)PredEs_prm_nBuf[u8LocalPredEs_idxLstBufWr];
   }
   else
   {
      s32LocalSwitch = (sint32)PredEs_nPredInter;
   }

   /*Production of PredEs_noTrigInc*/
   u16LocalPredEs_nLim2Inc1 = (uint16)(PredEs_nLim2Inc1_C * 10);
   if (s32LocalSwitch > u16LocalPredEs_nLim2Inc1)
   {
      u16LocalPredEs_nLim2Inc1 = (uint16)(u16LocalPredEs_nLim2Inc1 * 2);
      if (s32LocalSwitch > u16LocalPredEs_nLim2Inc1)
      {
         PredEs_noTrigInc = 3;
      }
      else
      {
         PredEs_noTrigInc = 2;
      }
   }
   else
   {
      PredEs_noTrigInc = 1;
   }

   /*Production of PredEs_noTrigCor*/
   if (PredEs_bTrigIni != 0)
   {
      u16LocalPredEs_noTrigCor = (uint16)PredEs_noTrigInc;
   }
   else
   {
      u16LocalPredEs_noTrigCor = (uint16)(PredEs_noTrigCor + PredEs_noTrigInc);
   }
   PredEs_noTrigCor = (uint8)(MATHSRV_udtMIN(u16LocalPredEs_noTrigCor, 255));
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalEngSpdLnkWthWhilInc                           */
/* !Description :  This block predicts the square engine speed after          */
/*                 PredEs_noTrigCor crankshaft signal teeth.                  */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 PredEs_noCgtPhaEng_C;                                         */
/*  input uint8 PredEs_noTrigCor;                                             */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint8 PredEs_noCgtPhaEng;                                           */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  input uint16 PredEs_prm_nBuf[255];                                        */
/*  input sint16 PredEs_n2DecE2TDC;                                           */
/*  input sint16 PredEs_n2DecEPred;                                           */
/*  input sint16 PredEs_n2PredInter;                                          */
/*  output uint8 PredEs_noCgtPhaEng;                                          */
/*  output sint16 PredEs_n2DecEPred;                                          */
/*  output sint16 PredEs_n2PredInter;                                         */
/*  output boolean PredEs_bDetChgDir;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalEngSpdLnkWthWhilInc(void)
{
   uint8  u8LocalMod1;
   uint8  u8LocalMod2;
   uint16 u16LocalCalc;
   uint16 u16LocalPredEs_prm_nBuf;
   sint16 s16LocalMod2;
   sint16 s16LocalPredEs_noCgtPhaEng;
   sint16 s16LocalDiff1;
   uint32 u32LocalPredEs_prm_n2Buf;
   sint32 s32LocalPredEs_prm_n2Buf;
   sint32 s32LocalPredEs_n2DecEPred;
   sint32 s32LocalPredEs_n2PredInter;


   /*Production of PredEs_noCgtPhaEng*/
   if (PredEs_noCgtPhaEng_C != 0)
   {
      u8LocalMod1 = (uint8)(PredEs_noTrigCor % PredEs_noCgtPhaEng_C);
   }
   else
   {
      u8LocalMod1 = 0;
   }
   s16LocalPredEs_noCgtPhaEng = (sint16)(PredEs_noCgtPhaEng_C - u8LocalMod1);
   PredEs_noCgtPhaEng =
      (uint8)MATHSRV_udtMAX(s16LocalPredEs_noCgtPhaEng, 0);
   s16LocalDiff1 = (sint16)(PredEs_idxLstBufWr - PredEs_noCgtPhaEng);
   if (PredEs_noCaseBuf_C != 0)
   {
      s16LocalMod2 = (sint16)(s16LocalDiff1 % PredEs_noCaseBuf_C);
   }
   else
   {
      s16LocalMod2 = 0;
      SWFAIL_vidSoftwareErrorHook();
   }
   if (s16LocalMod2 < 0)
   {
      s16LocalMod2 = (sint16)(s16LocalMod2 + PredEs_noCaseBuf_C);
   }
   u8LocalMod2 = (uint8)MATHSRV_udtMAX(s16LocalMod2, 0);
   u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[u8LocalMod2];
   u32LocalPredEs_prm_n2Buf =
      (uint32)(u16LocalPredEs_prm_nBuf * u16LocalPredEs_prm_nBuf);
   s32LocalPredEs_prm_n2Buf = (sint32)((u32LocalPredEs_prm_n2Buf + 16) / 32);

   /*Production of PredEs_n2DecEPred*/
   if (PredEs_noCgtPhaEng_C != 0)
   {
      u16LocalCalc =
         (uint16)( ( PredEs_noTrigCor
                   + PredEs_noCgtPhaEng_C)
                 / PredEs_noCgtPhaEng_C);
   }
   else
   {
      u16LocalCalc = 65535;
   }
   s32LocalPredEs_n2DecEPred = (sint32)(PredEs_n2DecE2TDC * u16LocalCalc);
   PredEs_n2DecEPred =
      (sint16)MATHSRV_udtCLAMP(s32LocalPredEs_n2DecEPred, -31250, 31250);

   /*Production of PredEs_n2PredInter and PredEs_bDetChgDir*/
   s32LocalPredEs_n2PredInter = (s32LocalPredEs_prm_n2Buf - PredEs_n2DecEPred);
   PredEs_n2PredInter =
      (sint16)MATHSRV_udtMIN(s32LocalPredEs_n2PredInter, 31250);
   if (PredEs_n2PredInter <= 0)
   {
      PredEs_bDetChgDir = 1;
   }
   else
   {
      PredEs_bDetChgDir = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcCrkPosBfrEngDirChg                           */
/* !Description :  This block calculates the covered angle between the last   */
/*                 crankshaft edge preceding the first predicted crankshaft   */
/*                 direction change and the first crankshaft direction change.*/
/* !Number      :  FCT3.5                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_028.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 PredEs_noTrigInc;                                             */
/*  input uint8 PredEs_noCgtPhaEng;                                           */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  input uint16 PredEs_prm_nBuf[255];                                        */
/*  input sint16 PredEs_nLstTDCChgDir_MP;                                     */
/*  input sint16 PredEs_n2DecEPred;                                           */
/*  input uint16 PredEs_n2ChgDir_MP;                                          */
/*  input uint16 PredEs_n2CgtLstTDCChgDir_MP;                                 */
/*  output uint8 PredEs_idxLstTDCChgDir_MP;                                   */
/*  output sint16 PredEs_nLstTDCChgDir_MP;                                    */
/*  output uint16 PredEs_n2ChgDir_MP;                                         */
/*  output uint16 PredEs_n2CgtLstTDCChgDir_MP;                                */
/*  output uint8 PredEs_noCgtLstCgtChgDir;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcCrkPosBfrEngDirChg(void)
{
   uint8  u8LocalPredEs_idxLstTDCChgDir_MP;
   uint8  u8LocalPredEs_noCgtLstCgtChgDir;
   uint16 u16LocalPredEs_prm_nBuf;
   sint16 s16LocalMod;
   uint32 u32LocalPredEs_n2ChgDir_MP;
   uint32 u32LocalPredEs_n2CtLtTDChgDir_MP;
   uint32 u32LocalPredEs_noCgtLstCgtChgDir;
   uint32 u32LocalPredEs_prm_nBuf2;
   uint32 u32LocalPredEs_nLstTDCChgDir_MP;
   sint32 s32LocalPredEs_n2ChgDir_MP;
   sint32 s32LocalPredEs_nLstTDCChgDir_MP;


   /*Production of PredEs_idxLstTDCChgDir_MP*/
   s16LocalMod =
      (sint16)(PredEs_idxLstBufWr - (PredEs_noTrigInc + PredEs_noCgtPhaEng));
   if (PredEs_noCaseBuf_C != 0)
   {
      s16LocalMod = (sint16)(s16LocalMod % PredEs_noCaseBuf_C);
   }
   else
   {
      s16LocalMod = 0;
      SWFAIL_vidSoftwareErrorHook();
   }

   if (s16LocalMod < 0)
   {
      s16LocalMod = (sint16)(s16LocalMod + PredEs_noCaseBuf_C);
   }
   PredEs_idxLstTDCChgDir_MP = (uint8)MATHSRV_udtMAX(s16LocalMod, 0);

   /*Production of PredEs_nLstTDCChgDir_MP*/
   u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[PredEs_idxLstTDCChgDir_MP];
   PredEs_nLstTDCChgDir_MP =
      (sint16)MATHSRV_udtMIN(u16LocalPredEs_prm_nBuf, 1000);

   /*Production of PredEs_n2ChgDir_MP*/
   s32LocalPredEs_nLstTDCChgDir_MP =
      (sint32)(PredEs_nLstTDCChgDir_MP * PredEs_nLstTDCChgDir_MP);
   s32LocalPredEs_n2ChgDir_MP =
      (s32LocalPredEs_nLstTDCChgDir_MP - (PredEs_n2DecEPred * 32));
   u32LocalPredEs_n2ChgDir_MP =
      (uint32)MATHSRV_udtABS(s32LocalPredEs_n2ChgDir_MP);
   u32LocalPredEs_n2ChgDir_MP = ((u32LocalPredEs_n2ChgDir_MP + 16) / 32);
   PredEs_n2ChgDir_MP =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_n2ChgDir_MP, 31250);

   /*Production of PredEs_n2CgtLstTDCChgDir_MP*/
   s16LocalMod =
      (sint16)(PredEs_idxLstBufWr - PredEs_noCgtPhaEng);
   if (PredEs_noCaseBuf_C != 0)
   {
      s16LocalMod = (sint16)(s16LocalMod % PredEs_noCaseBuf_C);
   }
   else
   {
      s16LocalMod = 0;
      SWFAIL_vidSoftwareErrorHook();
   }

   if (s16LocalMod < 0)
   {
      s16LocalMod = (sint16)(s16LocalMod + PredEs_noCaseBuf_C);
   }
   u8LocalPredEs_idxLstTDCChgDir_MP = (uint8)MATHSRV_udtMAX(s16LocalMod, 0);

   u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[u8LocalPredEs_idxLstTDCChgDir_MP];
   u32LocalPredEs_prm_nBuf2 =
      (uint32)(u16LocalPredEs_prm_nBuf * u16LocalPredEs_prm_nBuf);

   u32LocalPredEs_nLstTDCChgDir_MP =
      (uint32)MATHSRV_udtMAX(s32LocalPredEs_nLstTDCChgDir_MP, 0);
   if (PredEs_nLstTDCChgDir_MP >= u16LocalPredEs_prm_nBuf)
   {
      u32LocalPredEs_n2CtLtTDChgDir_MP =
         (u32LocalPredEs_nLstTDCChgDir_MP - u32LocalPredEs_prm_nBuf2);
   }
   else
   {
      u32LocalPredEs_n2CtLtTDChgDir_MP =
         (u32LocalPredEs_prm_nBuf2 - u32LocalPredEs_nLstTDCChgDir_MP);
   }
   u32LocalPredEs_n2CtLtTDChgDir_MP =
      (u32LocalPredEs_n2CtLtTDChgDir_MP / 32);
   PredEs_n2CgtLstTDCChgDir_MP =
      (uint16)MATHSRV_udtCLAMP(u32LocalPredEs_n2CtLtTDChgDir_MP, 1, 31250);

   /*Production of PredEs_noCgtLstCgtChgDir*/
   u32LocalPredEs_noCgtLstCgtChgDir =
      (uint32)( ( PredEs_n2ChgDir_MP
                * PredEs_noTrigInc)
              / PredEs_n2CgtLstTDCChgDir_MP);
   u8LocalPredEs_noCgtLstCgtChgDir =
      (uint8)MATHSRV_udtMIN(u32LocalPredEs_noCgtLstCgtChgDir, 255);
   PredEs_noCgtLstCgtChgDir =
      (uint8)MATHSRV_udtMIN(u8LocalPredEs_noCgtLstCgtChgDir, PredEs_noTrigInc);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalculatPredictionTime                           */
/* !Description :  This block evaluates:- The instantaneous engine speed and  */
/*                 the previous one, - The matching prediction durations      */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input sint16 PredEs_n2PredInter;                                          */
/*  input uint16 PREDES_Sqrt_Bkpt[9];                                         */
/*  input uint16 PREDES_Sqrt_Table[9];                                        */
/*  input sint16 PredEs_nPredInter;                                           */
/*  input boolean PredEs_bDetChgDir;                                          */
/*  input sint16 PredEs_nCorPred;                                             */
/*  input boolean PredEs_bTrigIni;                                            */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint16 PredEs_prm_nBuf[255];                                        */
/*  input sint16 PredEs_nPredInterPrev;                                       */
/*  input uint8 PredEs_noCgtLstCgtChgDir;                                     */
/*  input uint8 PredEs_noTrigInc;                                             */
/*  input uint16 PredEs_tiCntPred;                                            */
/*  output sint16 PredEs_nPredInter;                                          */
/*  output sint16 PredEs_nPredInterPrev;                                      */
/*  output uint16 PredEs_tiCntPredPrev;                                       */
/*  output uint16 PredEs_tiCntPred;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalculatPredictionTime(void)
{
   uint8  u8LocalPredEs_idxLstBufWr;
   uint16 u16LocalCalcPara;
   uint16 u16LocalInterp1D;
   uint16 u16LocalSum;
   uint16 u16LocalPredEs_tiCntPredPrev;
   uint16 u16LocalPredEs_n2PredInter;
   uint16 u16LocalPredEs_prm_nBufVal;
   sint16 s16LocalPredEs_nPredInterPrev;
   uint32 u32LocalCalc;
   uint32 u32LocalPredEs_tiCntPred;
   sint32 s32LocalPredEs_nPredInter;
   sint32 s32LocalSum;


   /*Production of PredEs_nPredInter*/
   u16LocalPredEs_n2PredInter = (uint16)MATHSRV_udtABS(PredEs_n2PredInter);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(PREDES_Sqrt_Bkpt,
                                                   u16LocalPredEs_n2PredInter,
                                                   9);
   u16LocalInterp1D = MATHSRV_u16Interp1d(PREDES_Sqrt_Table,
                                          u16LocalCalcPara);

   s16LocalPredEs_nPredInterPrev = PredEs_nPredInter;
   if (PredEs_bDetChgDir != 0)
   {
      s32LocalPredEs_nPredInter = (sint32)PredEs_nCorPred;
   }
   else
   {
      s32LocalPredEs_nPredInter = (sint32)(PredEs_nCorPred + u16LocalInterp1D);
   }
   PredEs_nPredInter =
      (sint16)MATHSRV_udtCLAMP(s32LocalPredEs_nPredInter, -500, 1000);

   /*Production of PredEs_nPredInterPrev*/
   if (PredEs_bTrigIni != 0)
   {
      if (PredEs_noCaseBuf_C != 0)
      {
         u8LocalPredEs_idxLstBufWr =
            (uint8)(PredEs_idxLstBufWr % PredEs_noCaseBuf_C);
      }
      else
      {
         u8LocalPredEs_idxLstBufWr = 0;
         SWFAIL_vidSoftwareErrorHook();
      }
      u16LocalPredEs_prm_nBufVal = PredEs_prm_nBuf[u8LocalPredEs_idxLstBufWr];
      PredEs_nPredInterPrev = (sint16)MATHSRV_udtMIN(u16LocalPredEs_prm_nBufVal,
                                                     1000);
   }
   else
   {
      PredEs_nPredInterPrev =
         (sint16)MATHSRV_udtCLAMP(s16LocalPredEs_nPredInterPrev, -500, 1000);
   }

   s32LocalSum = (sint32)(PredEs_nPredInter + PredEs_nPredInterPrev);
   u16LocalSum = (uint16)MATHSRV_udtMAX(s32LocalSum, 2);

   if (PredEs_bDetChgDir != 0)
   {
      u32LocalCalc = (uint32)( ( PredEs_noCgtLstCgtChgDir
                               * 100000)
                             / u16LocalSum);
   }
   else
   {
      u32LocalCalc = (uint32)((PredEs_noTrigInc * 100000) / u16LocalSum);
   }

   /*Production of PredEs_tiCntPredPrev and PredEs_tiCntPred*/
   if (PredEs_bTrigIni != 0)
   {
      u16LocalPredEs_tiCntPredPrev = 0;
      u32LocalPredEs_tiCntPred = u32LocalCalc;
   }
   else
   {
      u16LocalPredEs_tiCntPredPrev = PredEs_tiCntPred;
      u32LocalPredEs_tiCntPred = (u32LocalCalc + u16LocalPredEs_tiCntPredPrev);
   }
   PredEs_tiCntPredPrev = (uint16)MATHSRV_udtMIN(u16LocalPredEs_tiCntPredPrev,
                                                 65000);
   PredEs_tiCntPred = (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiCntPred, 65000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCoordinatWhileLoopPrt2                           */
/* !Description :  This block creates the flowing information:- The           */
/*                 calculation activation of the predicted variables, - The   */
/*                 called prediction calculation, - The stop condition of the */
/*                 while loop                                                 */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_025.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 PredEs_noNFill;                                               */
/*  input uint8 PredEs_noCgtPhaEng_C;                                         */
/*  input uint16 PredEs_tiCntPred;                                            */
/*  input uint16 PredEs_tiDlyLstClcN;                                         */
/*  input uint16 PredEs_tiStaEgdLoThd;                                        */
/*  input uint16 PredEs_tiStaEgdHiThd;                                        */
/*  input boolean PredEs_bTrigIni;                                            */
/*  input boolean PREDES_bRisingEdgeInPrev1;                                  */
/*  input boolean PREDES_bRisingEdgeInPrev2;                                  */
/*  input boolean PREDES_bRisingEdgeInPrev3;                                  */
/*  input boolean PredEs_bAcvClcPredCurN;                                     */
/*  input boolean PredEs_bAcvClcPredNLo;                                      */
/*  input boolean PredEs_bAcvClcPredNHi;                                      */
/*  input boolean PredEs_bVldOkN2EgdSave;                                     */
/*  input uint8 PredEs_noTrig;                                                */
/*  input uint8 PredEs_noLim2Inc_C;                                           */
/*  input boolean PredEs_bClcPredNHi;                                         */
/*  input boolean PredEs_bDetChgDir;                                          */
/*  output boolean PredEs_bClcPredCurN;                                       */
/*  output boolean PredEs_bClcPredNHi;                                        */
/*  output boolean PredEs_bAcvClcPredCurN;                                    */
/*  output boolean PredEs_bAcvClcPredNLo;                                     */
/*  output boolean PredEs_bAcvClcPredNHi;                                     */
/*  output boolean PredEs_bClcPredN;                                          */
/*  output boolean PredEs_bCndStop;                                           */
/*  output boolean PredEs_bClcPredNIntl;                                      */
/*  output boolean PREDES_bRisingEdgeInPrev1;                                 */
/*  output boolean PREDES_bRisingEdgeInPrev2;                                 */
/*  output boolean PREDES_bRisingEdgeInPrev3;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCoordinatWhileLoopPrt2(void)
{
   boolean bLocalNAND1;
   boolean bLocalNAND2;
   boolean bLocalNAND3;
   boolean bLocalSwitch;
   sint16  s16LocalCalc;


   if (  (PredEs_noNFill <= PredEs_noCgtPhaEng_C)
      || (PredEs_tiCntPred >= PredEs_tiDlyLstClcN))
   {
      bLocalNAND1 = 1;
      PredEs_bClcPredCurN = 1;
   }
   else
   {
      bLocalNAND1 = 0;
      PredEs_bClcPredCurN = 0;
   }

   if (  (PredEs_noNFill <= PredEs_noCgtPhaEng_C)
      || (PredEs_tiCntPred >= PredEs_tiStaEgdLoThd))
   {
      bLocalNAND2 = 1;
   }
   else
   {
      bLocalNAND2 = 0;
   }

   if (  (PredEs_noNFill <= PredEs_noCgtPhaEng_C)
      || (PredEs_tiCntPred >= PredEs_tiStaEgdHiThd))
   {
      bLocalNAND3 = 1;
      PredEs_bClcPredNHi = 1;
   }
   else
   {
      bLocalNAND3 = 0;
      PredEs_bClcPredNHi = 0;
   }

   if (PredEs_bTrigIni != 0)
   {
      if (bLocalNAND1 != 0)
      {
         PredEs_bAcvClcPredCurN = 1;
      }
      else
      {
         PredEs_bAcvClcPredCurN = 0;
      }
      if (bLocalNAND2 != 0)
      {
         PredEs_bAcvClcPredNLo = 1;
      }
      else
      {
         PredEs_bAcvClcPredNLo = 0;
      }

      if (bLocalNAND3 != 0)
      {
         PredEs_bAcvClcPredNHi = 1;
      }
      else
      {
         PredEs_bAcvClcPredNHi = 0;
      }
      if (  (bLocalNAND1 != 0)
         || (bLocalNAND2 != 0)
         || (bLocalNAND3 != 0))
      {
         PredEs_bClcPredN = 1;
      }
      else
      {
         PredEs_bClcPredN = 0;
      }
   }
   else
   {
      if (  (bLocalNAND1 != 0)
         && (PREDES_bRisingEdgeInPrev1 == 0))
      {
         PredEs_bAcvClcPredCurN = 1;
      }
      else
      {
         PredEs_bAcvClcPredCurN = 0;
      }
      if (  (bLocalNAND2 != 0)
         && (PREDES_bRisingEdgeInPrev2 == 0))
      {
         PredEs_bAcvClcPredNLo = 1;
      }
      else
      {
         PredEs_bAcvClcPredNLo = 0;
      }
      if (  (bLocalNAND3 != 0)
         && (PREDES_bRisingEdgeInPrev3 == 0))
      {
         PredEs_bAcvClcPredNHi = 1;
      }
      else
      {
         PredEs_bAcvClcPredNHi = 0;
      }
      if (  (PredEs_bAcvClcPredCurN != 0)
         || (PredEs_bAcvClcPredNLo != 0)
         || (PredEs_bAcvClcPredNHi != 0))
      {
         PredEs_bClcPredN = 1;
      }
      else
      {
         PredEs_bClcPredN = 0;
      }
   }

   if (PredEs_bVldOkN2EgdSave != 0)
   {
      if (PredEs_noTrig < PredEs_noLim2Inc_C)
      {
         bLocalSwitch = 1;
      }
      else
      {
         bLocalSwitch = 0;
      }
   }
   else
   {
      s16LocalCalc = (sint16)(PredEs_noLim2Inc_C - 3);
      if (PredEs_noTrig < s16LocalCalc)
      {
         bLocalSwitch = 1;
      }
      else
      {
         bLocalSwitch = 0;
      }
   }

   /*Production of PredEs_bCndStop*/
   if (  (PredEs_bClcPredNHi == 0)
      && (PredEs_bDetChgDir == 0)
      && (bLocalSwitch != 0))
   {
      PredEs_bCndStop = 1;
   }
   else
   {
      PredEs_bCndStop = 0;
   }

   /*Production of PredEs_bClcPredNIntl*/
   if (  (  (bLocalNAND2 != 0)
         && (PredEs_bClcPredNHi == 0))
      || (PredEs_bAcvClcPredNHi != 0))
   {
      PredEs_bClcPredNIntl = 1;
   }
   else
   {
      PredEs_bClcPredNIntl = 0;
   }
   PREDES_bRisingEdgeInPrev1 = bLocalNAND1;
   PREDES_bRisingEdgeInPrev2 = bLocalNAND2;
   PREDES_bRisingEdgeInPrev3 = bLocalNAND3;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidPredictEngSpdForDefiTi                           */
/* !Description :  This block interpolates 3 times the engine speed with:- The*/
/*                 engine speed predicts for a time smaller than the setpoint */
/*                 duration, - The predicted engine speed for a time higher   */
/*                 than the setpoint duration                                 */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean PredEs_bAcvClcPredCurN;                                     */
/*  input uint16 PredEs_tiDlyLstClcN;                                         */
/*  input uint16 PredEs_tiCntPredPrev;                                        */
/*  input boolean PredEs_bAcvClcPredNLo;                                      */
/*  input uint16 PredEs_tiStaEgdLoThd;                                        */
/*  input uint16 PredEs_tiStaEgdHiThd;                                        */
/*  input uint16 PredEs_tiCntPred;                                            */
/*  input sint16 PredEs_nPredInterPrev;                                       */
/*  input sint16 PredEs_nPredInter;                                           */
/*  input sint16 PredEs_nPredHiRaw;                                           */
/*  input sint16 PredEs_nCurRaw;                                              */
/*  input sint16 PredEs_nPredLoRaw;                                           */
/*  output sint16 PredEs_nPredHiRaw;                                          */
/*  output sint16 PredEs_nCurRaw;                                             */
/*  output sint16 PredEs_nPredLoRaw;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidPredictEngSpdForDefiTi(void)
{
   uint16 u16LocalDiff1Abs;
   uint16 u16LocalPredEs_nPred;
   uint32 u32LocalProduct;
   uint32 u32LocalDiff2;
   sint32 s32LocalDiff1;
   sint32 s32LocalDiff2;
   sint32 s32LocalCalc;
   sint32 s32LocalPredEs_nPred;


   /*Production of PredEs_nPredHiRaw*/
   if (PredEs_bAcvClcPredCurN != 0)
   {
      s32LocalDiff1 = (sint32)(PredEs_tiDlyLstClcN - PredEs_tiCntPredPrev);
   }
   else
   {
      if (PredEs_bAcvClcPredNLo != 0)
      {
         s32LocalDiff1 = (sint32)(PredEs_tiStaEgdLoThd - PredEs_tiCntPredPrev);
      }
      else
      {
         s32LocalDiff1 = (sint32)(PredEs_tiStaEgdHiThd - PredEs_tiCntPredPrev);
      }
   }

   s32LocalDiff2 = (sint32)(PredEs_tiCntPred - PredEs_tiCntPredPrev);
   if (s32LocalDiff2 <= 50)
   {
      PredEs_nPredHiRaw =
         (sint16)MATHSRV_udtCLAMP(PredEs_nPredInterPrev, -500, 1000);
   }
   else
   {
      u16LocalDiff1Abs = (uint16)MATHSRV_udtABS(s32LocalDiff1);
      s32LocalPredEs_nPred =
         (sint32)(PredEs_nPredInter - PredEs_nPredInterPrev);
      u16LocalPredEs_nPred = (uint16)MATHSRV_udtABS(s32LocalPredEs_nPred);
      u32LocalProduct = (uint32)(u16LocalDiff1Abs * u16LocalPredEs_nPred);
      u32LocalDiff2 = (uint32)s32LocalDiff2;
      s32LocalCalc = (sint32)(u32LocalProduct / u32LocalDiff2);
      if (s32LocalDiff1 >= 0)
      {
         if (s32LocalPredEs_nPred >= 0)
         {
            s32LocalCalc = (s32LocalCalc + PredEs_nPredInterPrev);
         }
         else
         {
            s32LocalCalc = (PredEs_nPredInterPrev - s32LocalCalc);
         }
      }
      else
      {
         if (s32LocalPredEs_nPred >= 0)
         {
            s32LocalCalc = (PredEs_nPredInterPrev - s32LocalCalc);
         }
         else
         {
            s32LocalCalc = (s32LocalCalc + PredEs_nPredInterPrev);
         }
      }
      PredEs_nPredHiRaw = (sint16)MATHSRV_udtCLAMP(s32LocalCalc, -500, 1000);
   }

   /*Production of PredEs_nCurRaw*/
   if (PredEs_bAcvClcPredCurN != 0)
   {
      PredEs_nCurRaw = PredEs_nPredHiRaw;
   }
   else
   {
      PredEs_nCurRaw = (sint16)MATHSRV_udtCLAMP(PredEs_nCurRaw, -500, 1000);
   }

   /*Production of PredEs_nPredLoRaw*/
   if (PredEs_bAcvClcPredNLo != 0)
   {
      PredEs_nPredLoRaw = PredEs_nPredHiRaw;
   }
   else
   {
      PredEs_nPredLoRaw =
         (sint16)MATHSRV_udtCLAMP(PredEs_nPredLoRaw, -500, 1000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidChkEngSpdToEngageStrtr                           */
/* !Description :  This block guarantees the engine speed ranges between 2    */
/*                 threshold engine speed (Minimal and maximal engagement     */
/*                 engine speed).                                             */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CoEmCkg_nStaEgdHiThd;                                        */
/*  input boolean PredEs_bAcvClcPredNHi;                                      */
/*  input sint16 PredEs_nPredHiRaw;                                           */
/*  input boolean PredEs_bAcvClcPredNLo;                                      */
/*  input sint16 PredEs_nPredLoRaw;                                           */
/*  input sint16 PredEs_nPredInter;                                           */
/*  input sint16 PredEs_nStaEgdLoThd;                                         */
/*  input boolean PredEs_bOkCndIntl;                                          */
/*  output boolean PredEs_bOkCndIntl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidChkEngSpdToEngageStrtr(void)
{
   uint16 u16LocalCoEmCkg_nStaEgdHiThd;
   sint16 s16LocalSwitch;


   VEMS_vidGET(CoEmCkg_nStaEgdHiThd, u16LocalCoEmCkg_nStaEgdHiThd);
   if (PredEs_bAcvClcPredNHi != 0)
   {
      s16LocalSwitch = PredEs_nPredHiRaw;
   }
   else
   {
      if (PredEs_bAcvClcPredNLo != 0)
      {
         s16LocalSwitch = PredEs_nPredLoRaw;
      }
      else
      {
         s16LocalSwitch = PredEs_nPredInter;
      }
   }

   /*Production of PredEs_bOkCndIntl*/
   if (  (s16LocalSwitch <= u16LocalCoEmCkg_nStaEgdHiThd)
      && (s16LocalSwitch >= PredEs_nStaEgdLoThd)
      && (  (PredEs_bAcvClcPredNLo != 0)
         || (PredEs_bOkCndIntl != 0)))
   {
      PredEs_bOkCndIntl = 1;
   }
   else
   {
      PredEs_bOkCndIntl = 0;
   }
}
/*------------------------------- end of file --------------------------------*/