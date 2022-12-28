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
/* !File            : PREDES_FCT2.C                                           */
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
/*   1 / PREDES_vidFillInstanEngSpdBuffer                                     */
/*   2 / PREDES_vidSlctTiBtwCrkshftTeeth                                      */
/*   3 / PREDES_vidCrtNumDatToCalcInstSpd                                     */
/*   4 / PREDES_vidCrtLogDatToCalcInstSpd                                     */
/*   5 / PREDES_vidCalcInstEngSpdNFillBfr                                     */
/*   6 / PREDES_vidCalcPredictionSetpts                                       */
/*   7 / PREDES_vidCalcInfEstTiBtwPrdNBfN                                     */
/*   8 / PREDES_vidEstmTibtwPrdEsNBufNEs                                      */
/*   9 / PREDES_vidCalcDlyBtwEngSpdNCrtTi                                     */
/*   10 / PREDES_vidCorrectPredictionTime                                     */
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
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "PREDES.h"
#include "PREDES_L.h"
#include "PREDES_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidFillInstanEngSpdBuffer                           */
/* !Description :  This block creates a buffer of instantaneous engine speed. */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidSlctTiBtwCrkshftTeeth();                       */
/*  extf argret void PREDES_vidCrtNumDatToCalcInstSpd();                      */
/*  extf argret void PREDES_vidCrtLogDatToCalcInstSpd();                      */
/*  extf argret void PREDES_vidCalcInstEngSpdNFillBfr();                      */
/*  input uint8 PredEs_noTrigBufNEs;                                          */
/*  output uint8 PredEs_noTrigBufTi;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidFillInstanEngSpdBuffer(void)
{
   uint16 u16LocalCnt;


   for (u16LocalCnt = 1; u16LocalCnt <= PredEs_noTrigBufNEs; u16LocalCnt++)
   {
      PredEs_noTrigBufTi = (uint8)u16LocalCnt;
      PREDES_vidSlctTiBtwCrkshftTeeth();
      PREDES_vidCrtNumDatToCalcInstSpd();
      PREDES_vidCrtLogDatToCalcInstSpd();
      PREDES_vidCalcInstEngSpdNFillBfr();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidSlctTiBtwCrkshftTeeth                            */
/* !Description :  This block gives: - The 3 last tooth period, - A counter   */
/*                 increasing for every crankshaft signal falling edge        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 PredEs_idxLstBufTiWr;                                         */
/*  input uint8 PredEs_noTrigBufTi;                                           */
/*  input uint8 PredEs_noTrigBufNEs;                                          */
/*  input sint16 PredEs_prm_idxBufTiWr_MP[3];                                 */
/*  input uint32 BufNEs_prm_tiCgtBuf[12];                                     */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input uint32 PredEs_tiCgtCor;                                             */
/*  input uint16 PredEs_tiCntCgt;                                             */
/*  output sint16 PredEs_prm_idxBufTiWr_MP[3];                                */
/*  output uint32 PredEs_tiLst2CgtCor;                                        */
/*  output uint32 PredEs_tiLstCgtCor;                                         */
/*  output uint32 PredEs_tiCgtCor;                                            */
/*  output uint16 PredEs_tiCntCgt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidSlctTiBtwCrkshftTeeth(void)
{
   uint8  u8LocalPredEs_prm_idxBufTir_MP0;
   uint8  u8LocalPredEs_prm_idxBufTir_MP1;
   uint8  u8LocalPredEs_prm_idxBufTir_MP2;
   sint8  s8LocalPredEs_prm_idxBufTir_MP0;
   sint8  s8LocalPredEs_prm_idxBufTir_MP1;
   sint8  s8LocalPredEs_prm_idxBufTir_MP2;
   sint16 s16LocalPredEs_prm_idxBufTiWr0MP;
   sint16 s16LocalPredEs_prm_idxBufTiWr1MP;
   sint16 s16LocalPredEs_prm_idxBufTiWr2MP;
   uint32 u32LocalPredEs_tiCgt;
   uint32 u32LocalPredEs_tiLst2CgtCor;
   uint32 u32LocalPredEs_tiLstCgtCor;
   uint32 u32LocalPredEs_tiCgtCor;


   /*Production of PredEs_prm_idxBufTiWr_MP*/
   s16LocalPredEs_prm_idxBufTiWr2MP = (sint16)( ( PredEs_idxLstBufTiWr
                                                + PredEs_noTrigBufTi)
                                              - PredEs_noTrigBufNEs);
   s16LocalPredEs_prm_idxBufTiWr0MP =
      (sint16)(s16LocalPredEs_prm_idxBufTiWr2MP - 2);

   PredEs_prm_idxBufTiWr_MP[0] =
      (sint16)MATHSRV_udtCLAMP(s16LocalPredEs_prm_idxBufTiWr0MP, -256, 255);

   s16LocalPredEs_prm_idxBufTiWr1MP =
      (sint16)(s16LocalPredEs_prm_idxBufTiWr2MP - 1);

   PredEs_prm_idxBufTiWr_MP[1] =
      (sint16)MATHSRV_udtMIN(s16LocalPredEs_prm_idxBufTiWr1MP, 255);

   PredEs_prm_idxBufTiWr_MP[2] =
      (sint16)MATHSRV_udtMIN(s16LocalPredEs_prm_idxBufTiWr2MP, 255);

   s8LocalPredEs_prm_idxBufTir_MP0 =
      (sint8)(PredEs_prm_idxBufTiWr_MP[0] % 12);
   s8LocalPredEs_prm_idxBufTir_MP1 =
      (sint8)(PredEs_prm_idxBufTiWr_MP[1] % 12);
   s8LocalPredEs_prm_idxBufTir_MP2 =
      (sint8)(PredEs_prm_idxBufTiWr_MP[2] % 12);

   /*Production of PredEs_tiLst2CgtCor*/
   if (s8LocalPredEs_prm_idxBufTir_MP0 < 0)
   {
      u8LocalPredEs_prm_idxBufTir_MP0 = (uint8)( s8LocalPredEs_prm_idxBufTir_MP0
                                               + 12);
   }
   else
   {
      u8LocalPredEs_prm_idxBufTir_MP0 = (uint8)s8LocalPredEs_prm_idxBufTir_MP0;
   }
   VEMS_vidGET1DArrayElement(BufNEs_prm_tiCgtBuf,
                             u8LocalPredEs_prm_idxBufTir_MP0,
                             u32LocalPredEs_tiLst2CgtCor);
   PredEs_tiLst2CgtCor = MATHSRV_udtMIN(u32LocalPredEs_tiLst2CgtCor, 500000);

   /*Production of PredEs_tiLstCgtCor*/
   if (s8LocalPredEs_prm_idxBufTir_MP1 < 0)
   {
      u8LocalPredEs_prm_idxBufTir_MP1 = (uint8)( s8LocalPredEs_prm_idxBufTir_MP1
                                               + 12);
   }
   else
   {
      u8LocalPredEs_prm_idxBufTir_MP1 = (uint8)s8LocalPredEs_prm_idxBufTir_MP1;
   }
   VEMS_vidGET1DArrayElement(BufNEs_prm_tiCgtBuf,
                             u8LocalPredEs_prm_idxBufTir_MP1,
                             u32LocalPredEs_tiLstCgtCor);
   PredEs_tiLstCgtCor = MATHSRV_udtMIN(u32LocalPredEs_tiLstCgtCor, 500000);

   /*Production of PredEs_tiCgtCor*/
   if (s8LocalPredEs_prm_idxBufTir_MP2 < 0)
   {
      u8LocalPredEs_prm_idxBufTir_MP2 = (uint8)( s8LocalPredEs_prm_idxBufTir_MP2
                                               + 12);
   }
   else
   {
      u8LocalPredEs_prm_idxBufTir_MP2 = (uint8)s8LocalPredEs_prm_idxBufTir_MP2;
   }
   VEMS_vidGET1DArrayElement(BufNEs_prm_tiCgtBuf,
                             u8LocalPredEs_prm_idxBufTir_MP2,
                             u32LocalPredEs_tiCgtCor);
   PredEs_tiCgtCor = MATHSRV_udtMIN(u32LocalPredEs_tiCgtCor, 500000);

   /*Production of PredEs_tiCntCgt*/
   if (  (PredEs_noTrigBufTi == 1)
      && (PredEs_bFirstClcPredEs != 0))
   {
      u32LocalPredEs_tiCgt = ((PredEs_tiCgtCor + 10) / 20);
   }
   else
   {
      u32LocalPredEs_tiCgt = ( ( PredEs_tiCgtCor
                               + ( PredEs_tiCntCgt
                                 * 20)
                               + 10)
                             / 20);
   }

   if (u32LocalPredEs_tiCgt >= 50000)
   {
      u32LocalPredEs_tiCgt = (u32LocalPredEs_tiCgt - 50000);
   }
   PredEs_tiCntCgt = (uint16)u32LocalPredEs_tiCgt;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCrtNumDatToCalcInstSpd                           */
/* !Description :  This block gives: - The instantaneous engine speed number  */
/*                 to record in the buffer, - The current crankshaft tooth    */
/*                 type., - The buffer address to record the engine speed.    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 PredEs_agMissCgt_C;                                          */
/*  input uint8 PredEs_agEng;                                                 */
/*  input uint8 PredEs_noTrigBufTi;                                           */
/*  input uint8 PredEs_noTrigBufNEs;                                          */
/*  input uint8 PredEs_agMissCgt360;                                          */
/*  input uint8 PredEs_agEngDly;                                              */
/*  input uint8 PredEs_noCgt;                                                 */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  output uint8 PredEs_agMissCgt360;                                         */
/*  output uint8 PredEs_agEngDly;                                             */
/*  output uint8 PredEs_noTypCgt;                                             */
/*  output uint8 PredEs_noCgt;                                                */
/*  output uint8 PredEs_idxLstBufWr;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCrtNumDatToCalcInstSpd(void)
{
   uint8  u8LocalPredEs_agMissCgt360;
   uint16 u16LocalPredEs_agMissCgt360;
   uint16 u16LocalPredEs_idxLstBufWr;
   sint16 s16LocalPredEs_agEngDly;


   /*Production of PredEs_agMissCgt360*/
   if (PredEs_agMissCgt_C >= 360)
   {
      u16LocalPredEs_agMissCgt360 = (uint16)((PredEs_agMissCgt_C - 357) / 6);
   }
   else
   {
      u16LocalPredEs_agMissCgt360 = (uint16)((PredEs_agMissCgt_C + 3) / 6);
   }
   PredEs_agMissCgt360 =
      (uint8)MATHSRV_udtMIN(u16LocalPredEs_agMissCgt360, 120);

   /*Production of PredEs_agEngDly*/
   s16LocalPredEs_agEngDly =
      (sint16)((PredEs_agEng + PredEs_noTrigBufTi) - PredEs_noTrigBufNEs);
   if (s16LocalPredEs_agEngDly >= 60)
   {
      s16LocalPredEs_agEngDly = (sint16)(s16LocalPredEs_agEngDly - 60);
   }
   PredEs_agEngDly = (uint8)MATHSRV_udtCLAMP(s16LocalPredEs_agEngDly, 0, 120);

   /*Production of PredEs_noTypCgt*/
   u8LocalPredEs_agMissCgt360 = (uint8)(PredEs_agMissCgt360 + 5);
   if (PredEs_agEngDly == u8LocalPredEs_agMissCgt360)
   {
      PredEs_noTypCgt = 1;
   }
   else
   {
      u8LocalPredEs_agMissCgt360 = (uint8)(u8LocalPredEs_agMissCgt360 - 1);
      if (PredEs_agEngDly == u8LocalPredEs_agMissCgt360)
      {
         PredEs_noTypCgt = 2;
      }
      else
      {
         u8LocalPredEs_agMissCgt360 = (uint8)(u8LocalPredEs_agMissCgt360 - 1);
         if (PredEs_agEngDly == u8LocalPredEs_agMissCgt360)
         {
            PredEs_noTypCgt = 3;
         }
         else
         {
            PredEs_noTypCgt = 0;
         }
      }
   }

   /*Production of PredEs_noCgt*/
   u8LocalPredEs_agMissCgt360 = (uint8)(PredEs_agMissCgt360 + 3);
   if (PredEs_agEngDly == u8LocalPredEs_agMissCgt360)
   {
      PredEs_noCgt = 3;
   }
   else
   {
      PredEs_noCgt = 1;
   }

   /*Production of PredEs_idxLstBufWr*/
   u16LocalPredEs_idxLstBufWr = (uint16)(PredEs_noCgt + PredEs_idxLstBufWr);
   if (u16LocalPredEs_idxLstBufWr >= PredEs_noCaseBuf_C)
   {
      u16LocalPredEs_idxLstBufWr =
         (uint16)(u16LocalPredEs_idxLstBufWr - PredEs_noCaseBuf_C);
   }
   PredEs_idxLstBufWr = (uint8)MATHSRV_udtMIN(u16LocalPredEs_idxLstBufWr, 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCrtLogDatToCalcInstSpd                           */
/* !Description :  This block informs if the engine is in the crankshaft      */
/*                 signal tooth.                                              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 PredEs_agMissCgt360;                                          */
/*  input uint8 PredEs_agEngDly;                                              */
/*  input boolean PREDES_bAcvRecBufPrev;                                      */
/*  input boolean PredEs_bAcvRecBuf;                                          */
/*  input uint8 PredEs_noNFill;                                               */
/*  input uint8 PredEs_noCgt;                                                 */
/*  input boolean PREDES_bFlipFlopOut2;                                       */
/*  input boolean PREDES_bFlipFlopOut2Prev;                                   */
/*  input uint8 PredEs_noNFill180_MP;                                         */
/*  input uint8 PredEs_noCgtPhaEng_C;                                         */
/*  output boolean PredEs_bTypCgt;                                            */
/*  output uint8 PredEs_noNFill;                                              */
/*  output boolean PREDES_bFlipFlopOut2Prev;                                  */
/*  output boolean PREDES_bFlipFlopOut2;                                      */
/*  output uint8 PredEs_noNFill180_MP;                                        */
/*  output boolean PredEs_bTypCgt180First;                                    */
/*  output boolean PREDES_bAcvRecBufPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCrtLogDatToCalcInstSpd(void)
{
   uint8  u8LocalPredEs_agMissCgt180;
   uint16 u16LocalCalc36;
   uint16 u16LocalCalc42;
   uint16 u16LocalPredEs_noNFill;
   uint16 u16LocalPredEs_noNFill80_MP;


   /*Production of PredEs_agMissCgt180*/
   if (PredEs_agMissCgt360 < 30)
   {
      u8LocalPredEs_agMissCgt180 = (uint8)(PredEs_agMissCgt360 + 30);
   }
   else
   {
      u8LocalPredEs_agMissCgt180 = (uint8)(PredEs_agMissCgt360 - 30);
   }

   /*Production of PredEs_bTypCgt*/
   u16LocalCalc36 = (uint16)(PredEs_agMissCgt360 + 6);
   if (  (PredEs_agEngDly >= PredEs_agMissCgt360)
      && (PredEs_agEngDly <= u16LocalCalc36))
   {
      PredEs_bTypCgt = 1;
   }
   else
   {
      PredEs_bTypCgt = 0;
   }

   /*Production of PredEs_noNFill*/
   if (  (PREDES_bAcvRecBufPrev != 0)
      && (PredEs_bAcvRecBuf == 0))
   {
      u16LocalPredEs_noNFill = 0;
   }
   else
   {
      if (PredEs_bAcvRecBuf != 0)
      {
         u16LocalPredEs_noNFill = (uint16)(PredEs_noNFill + PredEs_noCgt);
      }
      else
      {
         u16LocalPredEs_noNFill = PredEs_noNFill;
      }
   }
   PredEs_noNFill = (uint8)MATHSRV_udtMIN(u16LocalPredEs_noNFill, 255);

   /*Flip Flop*/
   PREDES_bFlipFlopOut2Prev = PREDES_bFlipFlopOut2;
   u16LocalCalc42 = (uint16)(u8LocalPredEs_agMissCgt180 + 7);
   if (PredEs_bAcvRecBuf == 0)
   {
      PREDES_bFlipFlopOut2 = 0;
   }
   else
   {
      if (  (PredEs_noNFill >= 9)
         && (PredEs_agEngDly == u16LocalCalc42))
      {
         PREDES_bFlipFlopOut2 = 1;
      }
   }

   /*Production of PredEs_noNFill180_MP*/
   if (  (PREDES_bFlipFlopOut2 != 0)
      && (PREDES_bFlipFlopOut2Prev == 0))
   {
      PredEs_noNFill180_MP = (uint8)MATHSRV_udtMIN(PredEs_noNFill, 28);
   }
   else
   {
      if (PREDES_bFlipFlopOut2 != 0)
      {
         u16LocalPredEs_noNFill80_MP =
            (uint16)(PredEs_noNFill180_MP + PredEs_noCgt);
      }
      else
      {
         u16LocalPredEs_noNFill80_MP = 0;
      }
      PredEs_noNFill180_MP =
         (uint8)MATHSRV_udtMIN(u16LocalPredEs_noNFill80_MP, 255);
   }

   /*Production of PredEs_bTypCgt180First*/
   u16LocalCalc36 = (uint16)(u8LocalPredEs_agMissCgt180 + 6);
   if (  (PredEs_noNFill180_MP <= PredEs_noCgtPhaEng_C)
      && (PredEs_agEngDly >= u8LocalPredEs_agMissCgt180)
      && (PredEs_agEngDly <= u16LocalCalc36))
   {
      PredEs_bTypCgt180First = 1;
   }
   else
   {
      PredEs_bTypCgt180First = 0;
   }
   PREDES_bAcvRecBufPrev = PredEs_bAcvRecBuf;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcInstEngSpdNFillBfr                           */
/* !Description :  This block calculates the instantaneous engine speeds (with*/
/*                 a range of18°Ck), before records its.                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_018.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint32 PredEs_tiLst2CgtCor;                                         */
/*  input uint32 PredEs_tiLstCgtCor;                                          */
/*  input uint32 PredEs_tiCgtCor;                                             */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  input uint8 PredEs_noCgt;                                                 */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint8 PredEs_noTypCgt;                                              */
/*  input uint32 PredEs_ti3LstCgtClc_MP;                                      */
/*  input uint8 PredEs_idxLstBufWrDyn_MP;                                     */
/*  input uint8 PredEs_noCgtPhaEng_C;                                         */
/*  input uint16 PredEs_prm_nBuf[255];                                        */
/*  input sint16 PredEs_n2DecE2TDCSave_MP;                                    */
/*  input uint16 PREDES_Sqrt_Bkpt[9];                                         */
/*  input uint16 PREDES_Sqrt_Table[9];                                        */
/*  input uint8 PredEs_noNFill;                                               */
/*  input uint8 PredEs_nThdAcvFct_C;                                          */
/*  input boolean PredEs_bTypCgt;                                             */
/*  input uint16 PredEs_ti3LstCgtCor_MP;                                      */
/*  input boolean PredEs_bBypTi3LstCgtClc_C;                                  */
/*  input boolean PredEs_bTypCgt180First;                                     */
/*  input sint16 PredEs_n2DecE2TDCRaw_MP;                                     */
/*  input sint16 PredEs_n2DecE2TDC;                                           */
/*  input uint8 PredEs_facFilN2Dec_C;                                         */
/*  output uint8 PredEs_idxLstBufWrDyn_MP;                                    */
/*  output uint32 PredEs_ti3LstCgtClc_MP;                                     */
/*  output uint16 PredEs_ti3LstCgtCor_MP;                                     */
/*  output uint16 PredEs_prm_nBuf[255];                                       */
/*  output sint16 PredEs_n2DecE2TDCRaw_MP;                                    */
/*  output sint16 PredEs_n2DecE2TDCSave_MP;                                   */
/*  output sint16 PredEs_n2DecE2TDC;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcInstEngSpdNFillBfr(void)
{
   uint8  u8LocalPredEs_noCaseBuf_C;
   uint8  u8LocalIndexPredEs_nBufDly;
   uint16 u16LocalCnt;
   uint16 u16LocalCnt1;
   uint16 u16LocalDiffABS;
   uint16 u16LocalCalcPara;
   uint16 u16LocalInterp1D;
   uint16 u16LocalPredEs_prm_nBuf;
   uint16 u16LocalPredEs_prm_nBuf1;
   uint16 u16LocalDetectSatMin;
   uint16 u16LocalDetectSatMax;
   sint16 s16LocalIndexPredEs_nBufDly;
   sint16 s16LocalDetectSatOut;
   uint32 u32LocalPredEs_n2DecE2TDCBas;
   uint32 u32LocalPredEs_tiLst2CgtCor;
   uint32 u32LocalPredEs_tiLstCgtCor;
   uint32 u32LocalPredEs_tiCgtCor;
   uint32 u32LocalPredEs_tiCgtCorMin;
   uint32 u32LocalPredEs_tiLstCgtCorMin;
   uint32 u32LocalPredEs_tiLst2CgtCorMin;
   uint32 u32LocalPredEs_ti3LstCgtClc_MP;
   uint32 u32LocalResult;
   uint32 u32LocalDiffABS;
   uint32 u32LocalDiff;
   uint32 u32LocalPredEs_prm_nBuf;
   uint32 u32LocalPredEs_prm_nBuf1;
   sint32 s32LocalCalc;
   sint32 s32LocalDiff;
   sint32 s32LocalPredEs_prm_n2Buf;
   sint32 s32LocalPredEs_n2DecE2TDC;


   u32LocalPredEs_n2DecE2TDCBas = (uint32)(230000 / Ext_noCylEng_SC);
   u16LocalDetectSatMax = (uint16)(12938 / Ext_noCylEng_SC);
   u16LocalDetectSatMin = (uint16)(3594 / Ext_noCylEng_SC);

   u32LocalPredEs_tiLst2CgtCor = MATHSRV_udtMIN(PredEs_tiLst2CgtCor, 2863311);
   u32LocalPredEs_tiLstCgtCor = MATHSRV_udtMIN(PredEs_tiLstCgtCor, 2863311);
   u32LocalPredEs_tiCgtCor = MATHSRV_udtMIN(PredEs_tiCgtCor, 2863311);

   u8LocalPredEs_noCaseBuf_C = PredEs_noCaseBuf_C;
   for (u16LocalCnt = 1; u16LocalCnt <= PredEs_noCgt; u16LocalCnt++)
   {
      if (u8LocalPredEs_noCaseBuf_C != 0)
      {
         s32LocalCalc =
            (sint32)((u16LocalCnt + PredEs_idxLstBufWr) - PredEs_noCgt);
         if (s32LocalCalc < 0)
         {
            PredEs_idxLstBufWrDyn_MP =
               (uint8)( ( s32LocalCalc
                        % u8LocalPredEs_noCaseBuf_C)
                      + u8LocalPredEs_noCaseBuf_C);
         }
         else
         {
            PredEs_idxLstBufWrDyn_MP =
               (uint8)(s32LocalCalc % u8LocalPredEs_noCaseBuf_C);
         }
      }
      else
      {
         PredEs_idxLstBufWrDyn_MP = 0;
         SWFAIL_vidSoftwareErrorHook();
      }

      /*Production of PredEs_ti3LstCgtClc_MP*/
      switch (PredEs_noTypCgt)
      {
      case 0:
         u32LocalPredEs_ti3LstCgtClc_MP =
            ( ( u32LocalPredEs_tiLst2CgtCor
              + u32LocalPredEs_tiLstCgtCor)
            * 33);
         u32LocalPredEs_ti3LstCgtClc_MP =
            ( u32LocalPredEs_ti3LstCgtClc_MP
            + ( u32LocalPredEs_tiCgtCor
              * 34));
         u32LocalPredEs_ti3LstCgtClc_MP =
            ((u32LocalPredEs_ti3LstCgtClc_MP + 50) / 100);
         break;

      case 1:
         u32LocalPredEs_ti3LstCgtClc_MP =
            ( ( u32LocalPredEs_tiLst2CgtCor
              * 83)
            + ( u32LocalPredEs_tiLstCgtCor
              * 250)
            + ( u32LocalPredEs_tiCgtCor
              * 500));
         u32LocalPredEs_ti3LstCgtClc_MP =
            ((u32LocalPredEs_ti3LstCgtClc_MP + 500) / 1000);
         break;

      case 2:
         u32LocalPredEs_ti3LstCgtClc_MP =
            ( ( u32LocalPredEs_tiLstCgtCor
              * 167)
            + ( u32LocalPredEs_tiCgtCor
              * 500));
         u32LocalPredEs_ti3LstCgtClc_MP =
            ((u32LocalPredEs_ti3LstCgtClc_MP + 500) / 1000);
         break;

      case 3:
         u16LocalCnt1 = (uint16)(u16LocalCnt - 1);
         switch (u16LocalCnt1)
         {
         case 0:
            u32LocalPredEs_ti3LstCgtClc_MP =
               ( ( u32LocalPredEs_tiLst2CgtCor
                 * 500)
               + ( u32LocalPredEs_tiLstCgtCor
                 * 250)
               + ( u32LocalPredEs_tiCgtCor
                 * 83));
            u32LocalPredEs_ti3LstCgtClc_MP =
               ((u32LocalPredEs_ti3LstCgtClc_MP + 500) / 1000);
            break;

         case 1:
            u32LocalPredEs_ti3LstCgtClc_MP =
               ( ( u32LocalPredEs_tiLst2CgtCor
                 * 2)
               + ( u32LocalPredEs_tiLstCgtCor
                 * 2)
               + ( u32LocalPredEs_tiCgtCor
                 * 2));
            u32LocalPredEs_ti3LstCgtClc_MP =
               ((u32LocalPredEs_ti3LstCgtClc_MP + 5) / 10);
            break;

         case 2:
            u32LocalPredEs_ti3LstCgtClc_MP =
               ( u32LocalPredEs_tiCgtCor
               * 333);
            u32LocalPredEs_ti3LstCgtClc_MP =
               ((u32LocalPredEs_ti3LstCgtClc_MP + 500) / 1000);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            u32LocalPredEs_ti3LstCgtClc_MP = PredEs_ti3LstCgtClc_MP;
            break;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         u32LocalPredEs_ti3LstCgtClc_MP = PredEs_ti3LstCgtClc_MP;
         break;
      }
      PredEs_ti3LstCgtClc_MP =
         MATHSRV_udtMIN(u32LocalPredEs_ti3LstCgtClc_MP, 500000);

      /*Production of PredEs_ti3LstCgtCor_MP*/
      if (u8LocalPredEs_noCaseBuf_C != 0)
      {
         s16LocalIndexPredEs_nBufDly =
            (sint16)(PredEs_idxLstBufWrDyn_MP - PredEs_noCgtPhaEng_C);
         if (s16LocalIndexPredEs_nBufDly < 0)
         {
            u8LocalIndexPredEs_nBufDly =
               (uint8)( ( s16LocalIndexPredEs_nBufDly
                        % u8LocalPredEs_noCaseBuf_C)
                      + u8LocalPredEs_noCaseBuf_C);
         }
         else
         {
            u8LocalIndexPredEs_nBufDly =
               (uint8)(s16LocalIndexPredEs_nBufDly % u8LocalPredEs_noCaseBuf_C);
         }
      }
      else
      {
         u8LocalIndexPredEs_nBufDly = 0;
         SWFAIL_vidSoftwareErrorHook();
      }

      u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[u8LocalIndexPredEs_nBufDly];
      u16LocalPredEs_prm_nBuf =
         (uint16)MATHSRV_udtMIN(u16LocalPredEs_prm_nBuf, 32767);
      s32LocalPredEs_prm_n2Buf =
         (sint32)(u16LocalPredEs_prm_nBuf * u16LocalPredEs_prm_nBuf);
      s32LocalDiff =
         (s32LocalPredEs_prm_n2Buf - (32 * PredEs_n2DecE2TDCSave_MP));
      u32LocalDiffABS = (uint32)MATHSRV_udtABS(s32LocalDiff);
      u32LocalDiffABS = ((u32LocalDiffABS + 16) / 32);
      u16LocalDiffABS = (uint16)MATHSRV_udtMIN(u32LocalDiffABS, 65535);
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(PREDES_Sqrt_Bkpt,
                                                      u16LocalDiffABS,
                                                      9);
      u16LocalInterp1D = MATHSRV_u16Interp1d(PREDES_Sqrt_Table,
                                             u16LocalCalcPara);
      PredEs_ti3LstCgtCor_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 1000);

      /*Production of PredEs_prm_nBuf*/
      if (PredEs_noNFill == 0)
      {
         u16LocalPredEs_prm_nBuf = (uint16)(PredEs_nThdAcvFct_C * 10);
      }
      else
      {
         if (  (PredEs_bTypCgt != 0)
            && (PredEs_noNFill > PredEs_noCgtPhaEng_C))
         {
            u16LocalPredEs_prm_nBuf = PredEs_ti3LstCgtCor_MP;
         }
         else
         {
            if (  (PredEs_bBypTi3LstCgtClc_C != 0)
               && (PredEs_bTypCgt != 0))
            {
               u32LocalPredEs_tiLst2CgtCorMin =
                  MATHSRV_udtMIN(PredEs_tiLst2CgtCor, PredEs_tiLstCgtCor);
               u32LocalPredEs_tiLstCgtCorMin =
                  MATHSRV_udtMIN(PredEs_tiLstCgtCor, PredEs_tiCgtCor);
               u32LocalPredEs_tiCgtCorMin =
                  ( (u32LocalPredEs_tiLst2CgtCorMin / 2)
                  + (u32LocalPredEs_tiLstCgtCorMin / 2));
            }
            else
            {
               u32LocalPredEs_tiCgtCorMin = PredEs_ti3LstCgtClc_MP;
            }

            u32LocalResult = MATHSRV_udtMAX(u32LocalPredEs_tiCgtCorMin, 1000);
            u16LocalPredEs_prm_nBuf =
               (uint16)(1000000 / u32LocalResult);
         }
      }
      PredEs_prm_nBuf[PredEs_idxLstBufWrDyn_MP] =
         (uint16)MATHSRV_udtMIN(u16LocalPredEs_prm_nBuf, 1000);

      /*Production of PredEs_n2DecE2TDCRaw_MP*/
      if (  (PredEs_bTypCgt != 0)
         || (PredEs_bTypCgt180First != 0))
      {
         PredEs_n2DecE2TDCRaw_MP =
            (sint16)MATHSRV_udtCLAMP(PredEs_n2DecE2TDCSave_MP, -31250, 31250);
      }
      else
      {
         u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[PredEs_idxLstBufWrDyn_MP];
         u16LocalPredEs_prm_nBuf1 = PredEs_prm_nBuf[u8LocalIndexPredEs_nBufDly];
         u32LocalPredEs_prm_nBuf1 =
            (uint32)(u16LocalPredEs_prm_nBuf1 * u16LocalPredEs_prm_nBuf1);
         u32LocalPredEs_prm_nBuf =
            (uint32)(u16LocalPredEs_prm_nBuf * u16LocalPredEs_prm_nBuf);
         if (u16LocalPredEs_prm_nBuf1 < u16LocalPredEs_prm_nBuf)
         {
            u32LocalDiff = (u32LocalPredEs_prm_nBuf - u32LocalPredEs_prm_nBuf1);
            u32LocalDiff = ((u32LocalDiff + 16) / 32);
            PredEs_n2DecE2TDCRaw_MP =
               (sint16)((-1) * u32LocalDiff);
         }
         else
         {
            u32LocalDiff = (u32LocalPredEs_prm_nBuf1 - u32LocalPredEs_prm_nBuf);
            u32LocalDiff = ((u32LocalDiff + 16) / 32);
            PredEs_n2DecE2TDCRaw_MP =
               (sint16)MATHSRV_udtMIN(u32LocalDiff, 31250);
         }
      }

      /*DetectSat*/
      if (PredEs_n2DecE2TDCRaw_MP <= u16LocalDetectSatMin)
      {
         s16LocalDetectSatOut = (sint16)u16LocalDetectSatMin;
      }
      else
      {
         if (PredEs_n2DecE2TDCRaw_MP >= u16LocalDetectSatMax)
         {
            s16LocalDetectSatOut = (sint16)u16LocalDetectSatMax;
         }
         else
         {
            s16LocalDetectSatOut = PredEs_n2DecE2TDCRaw_MP;
         }
      }
      PredEs_n2DecE2TDCSave_MP = s16LocalDetectSatOut;

      /*Production of PredEs_n2DecE2TDC*/
      if (PredEs_noNFill <= PredEs_noCgtPhaEng_C)
      {
         s32LocalPredEs_n2DecE2TDC =
            (sint32)((u32LocalPredEs_n2DecE2TDCBas + 16) / 32);
      }
      else
      {
         if (PredEs_noCgtPhaEng_C != 0)
         {
            s32LocalPredEs_n2DecE2TDC =
               (sint32)( ( PredEs_facFilN2Dec_C
                         * ( s16LocalDetectSatOut
                           - PredEs_n2DecE2TDC))
                       + ( PredEs_n2DecE2TDC
                         * PredEs_noCgtPhaEng_C
                         * 20));
            s32LocalPredEs_n2DecE2TDC =
               (s32LocalPredEs_n2DecE2TDC / PredEs_noCgtPhaEng_C);
            if (s32LocalPredEs_n2DecE2TDC < 0)
            {
               s32LocalPredEs_n2DecE2TDC =
                  ((s32LocalPredEs_n2DecE2TDC - 10) / 20);
            }
            else
            {
               s32LocalPredEs_n2DecE2TDC =
                  ((s32LocalPredEs_n2DecE2TDC + 10) / 20);
            }
         }
         else
         {
            if (s16LocalDetectSatOut >= PredEs_n2DecE2TDC)
            {
               s32LocalPredEs_n2DecE2TDC = SINT32_MAX;
            }
            else
            {
               s32LocalPredEs_n2DecE2TDC = SINT32_MIN;
            }
         }
      }
      PredEs_n2DecE2TDC =
         (sint16)MATHSRV_udtCLAMP(s32LocalPredEs_n2DecE2TDC, -31250, 31250);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcPredictionSetpts                             */
/* !Description :  This block calculates the delay of instantaneous engine    */
/*                 speed, due to: The calculation delay of the instantaneous  */
/*                 engine speed and  the delay between the last crankshaft    */
/*                 signal edge and the engine speed prediction                */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_019.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidCalcInfEstTiBtwPrdNBfN();                      */
/*  extf argret void PREDES_vidCalcDlyBtwEngSpdNCrtTi();                      */
/*  extf argret void PREDES_vidCorrectPredictionTime();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcPredictionSetpts(void)
{
   PREDES_vidCalcInfEstTiBtwPrdNBfN();
   PREDES_vidCalcDlyBtwEngSpdNCrtTi();
   PREDES_vidCorrectPredictionTime();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcInfEstTiBtwPrdNBfN                           */
/* !Description :  The block outputs are used to calculate the delay between  */
/*                 the last crankshaft signal falling edge and the current    */
/*                 function call.                                             */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_020.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input uint16 PredEs_tiCntCgt;                                             */
/*  input uint16 PredEs_tiCntCgtPrev;                                         */
/*  input uint8 PredEs_idxLstBufTiWr;                                         */
/*  input uint8 PREDES_idxLstBufTiWrPrev;                                     */
/*  output sint16 PredEs_tiCntFct2CntCgt;                                     */
/*  output boolean PredEs_bNotCgtLstFct;                                      */
/*  output uint16 PredEs_tiCntCgtPrev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcInfEstTiBtwPrdNBfN(void)
{
   sint32 s32LocalPredEs_tiCntFct2CntCgt;
   sint32 s32LocalPredEs_tiCntCgt;


   /*Production of PredEs_tiCntFct2CntCgt*/
   if (PredEs_bFirstClcPredEs != 0)
   {
      s32LocalPredEs_tiCntFct2CntCgt = 0;
   }
   else
   {
      s32LocalPredEs_tiCntCgt = (sint32)(PredEs_tiCntCgt - PredEs_tiCntCgtPrev);
      if (s32LocalPredEs_tiCntCgt < 0)
      {
         s32LocalPredEs_tiCntFct2CntCgt = (s32LocalPredEs_tiCntCgt + 49500);
      }
      else
      {
         s32LocalPredEs_tiCntFct2CntCgt = (s32LocalPredEs_tiCntCgt - 500);
      }
   }
   PredEs_tiCntFct2CntCgt =
      (sint16)MATHSRV_udtMIN(s32LocalPredEs_tiCntFct2CntCgt, 25000);

   /*Production of PredEs_bNotCgtLstFct*/
   if (  (PredEs_bFirstClcPredEs == 0)
      && (PredEs_idxLstBufTiWr == PREDES_idxLstBufTiWrPrev))
   {
      PredEs_bNotCgtLstFct = 1;
   }
   else
   {
      PredEs_bNotCgtLstFct = 0;
   }
   PredEs_tiCntCgtPrev = (uint16)MATHSRV_udtMIN(PredEs_tiCntCgt, 65000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidEstmTibtwPrdEsNBufNEs                            */
/* !Description :  This block evaluates the duration between the function call*/
/*                 (current time) and the last crankshaft signal falling edge.*/
/* !Number      :  FCT2.8                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 PredEs_tiMaxBufMax;                                          */
/*  input uint8 PredEs_agEng;                                                 */
/*  input sint16 PredEs_nCurCor;                                              */
/*  input uint16 PredEs_agMissCgt_C;                                          */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input boolean PredEs_bEngSyncAccu;                                        */
/*  input boolean PredEs_bVldCurNCor;                                         */
/*  input boolean PredEs_bNotCgtLstFct;                                       */
/*  input boolean PredEs_bVldTiLstCgtRaw_MP;                                  */
/*  input sint16 PredEs_tiCntFct2CntCgt;                                      */
/*  input uint16 PREDES_u16TiMaxBufMaxPrev;                                   */
/*  input uint16 PredEs_tiUncrtTrigFct_C;                                     */
/*  input uint16 PredEs_tiMaxBufMin_MP;                                       */
/*  input uint16 PredEs_tiMaxBufPrevMin_MP;                                   */
/*  input uint16 PredEs_tiMinBufMax_MP;                                       */
/*  input uint16 PredEs_tiMinBufPrevMax_MP;                                   */
/*  input boolean PredEs_bVldTiLstCgtUpd;                                     */
/*  input uint16 PredEs_tiMaxBufMinRaw_MP;                                    */
/*  input uint16 PredEs_tiMinBufMaxRaw_MP;                                    */
/*  output uint16 PREDES_u16TiMaxBufMaxPrev;                                  */
/*  output uint16 PredEs_tiMaxBufMax;                                         */
/*  output boolean PredEs_bVldTiLstCgtRaw_MP;                                 */
/*  output boolean PredEs_bVldTiLstCgtUpd;                                    */
/*  output uint16 PredEs_tiMaxBufPrevMin_MP;                                  */
/*  output uint16 PredEs_tiMaxBufMinRaw_MP;                                   */
/*  output uint16 PredEs_tiMinBufPrevMax_MP;                                  */
/*  output uint16 PredEs_tiMinBufMaxRaw_MP;                                   */
/*  output uint16 PredEs_tiMaxBufMin_MP;                                      */
/*  output uint16 PredEs_tiMinBufMax_MP;                                      */
/*  output uint16 PredEs_tiDlyLstClcNNew;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidEstmTibtwPrdEsNBufNEs(void)
{
   uint16 u16LocalPredEs_tiMinBufMax_MP2;
   uint16 u16LocalPredEs_tiMaxBufMin_MP2;
   uint16 u16LocalPredEs_agEng;
   uint16 u16LocalPredEs_nCurCor;
   uint16 u16LocalPredEs_tiMaxBufMax;
   uint32 u32LocalPredEs_tiMinBufMaxRaw_MP;
   uint32 u32LocalPredEs_tiMaxBufMin_MP1;
   uint32 u32LocalPredEs_tiMaxBufMin_MP;
   uint32 u32LocalPredEs_tiMinBufMax_MP;
   uint32 u32LocalPredEs_tiDlyLstClcNNew;
   sint32 s32LocalPredEs_tiMaxBufMinRaw_MP;
   sint32 s32LocalPredEs_tiMaxBufPrevMinMP;
   sint32 s32LocalPredEs_tiMinBufMax_MP1;
   sint32 s32LocalPredEs_tiMinBufMax_MP;


   /*Production of PredEs_tiMaxBufMax*/
   PREDES_u16TiMaxBufMaxPrev =
      (uint16)MATHSRV_udtMIN(PredEs_tiMaxBufMax, 65000);
   if (PredEs_agEng >= 60)
   {
      u16LocalPredEs_agEng = (uint16)(PredEs_agEng - 60);
   }
   else
   {
      u16LocalPredEs_agEng = (uint16)PredEs_agEng;
   }

   u16LocalPredEs_agEng = (uint16)(u16LocalPredEs_agEng * 6);
   u16LocalPredEs_nCurCor = (uint16)MATHSRV_udtMAX(PredEs_nCurCor, 3);
   if (u16LocalPredEs_agEng == PredEs_agMissCgt_C)
   {
      u16LocalPredEs_tiMaxBufMax = (uint16)(150000 / u16LocalPredEs_nCurCor);
   }
   else
   {
      u16LocalPredEs_tiMaxBufMax = (uint16)(50000 / u16LocalPredEs_nCurCor);
   }
   PredEs_tiMaxBufMax = u16LocalPredEs_tiMaxBufMax;

   /*Production of PredEs_bVldTiLstCgtUpd*/
   if (  (PredEs_bFirstClcPredEs == 0)
      && (PredEs_bEngSyncAccu != 0)
      && (PredEs_bVldCurNCor != 0)
      && (PredEs_nCurCor > 0))
   {
      PredEs_bVldTiLstCgtRaw_MP = 1;
   }
   else
   {
      PredEs_bVldTiLstCgtRaw_MP = 0;
   }

   if (  (PredEs_bFirstClcPredEs != 0)
      || (PredEs_bNotCgtLstFct == 0))
   {
      if (PredEs_bVldTiLstCgtRaw_MP != 0)
      {
         PredEs_bVldTiLstCgtUpd = 1;
      }
      else
      {
         PredEs_bVldTiLstCgtUpd = 0;
      }
   }

   /*Production of PredEs_tiMaxBufPrevMin_MP*/
   s32LocalPredEs_tiMaxBufPrevMinMP =
      (sint32)(PredEs_tiCntFct2CntCgt + PredEs_tiMaxBufMax);
   s32LocalPredEs_tiMaxBufPrevMinMP =
      MATHSRV_udtMIN(s32LocalPredEs_tiMaxBufPrevMinMP,
                     PREDES_u16TiMaxBufMaxPrev);
   PredEs_tiMaxBufPrevMin_MP =
      (uint16)MATHSRV_udtMAX(s32LocalPredEs_tiMaxBufPrevMinMP, 0);

   /*Production of PredEs_tiMaxBufMinRaw_MP*/
   u32LocalPredEs_tiMaxBufMin_MP1 =
      (uint32)((PredEs_tiUncrtTrigFct_C * 5) + PredEs_tiMaxBufMin_MP);
   u16LocalPredEs_tiMaxBufMin_MP2 =
      (uint16)MATHSRV_udtMIN(PredEs_tiMaxBufPrevMin_MP,
                             u32LocalPredEs_tiMaxBufMin_MP1);
   s32LocalPredEs_tiMaxBufMinRaw_MP =
      (sint32)(u16LocalPredEs_tiMaxBufMin_MP2 - PredEs_tiCntFct2CntCgt);
   PredEs_tiMaxBufMinRaw_MP =
      (uint16)MATHSRV_udtMAX(s32LocalPredEs_tiMaxBufMinRaw_MP, 0);

   /*Production of PredEs_tiMinBufPrevMax_MP*/
   PredEs_tiMinBufPrevMax_MP =
      (uint16)MATHSRV_udtMAX(PredEs_tiCntFct2CntCgt, 0);

   /*Production of PredEs_tiMinBufMaxRaw_MP*/
   s32LocalPredEs_tiMinBufMax_MP1 =
      (sint32)(PredEs_tiMinBufMax_MP - (PredEs_tiUncrtTrigFct_C * 5));
   u16LocalPredEs_tiMinBufMax_MP2 =
      (uint16)MATHSRV_udtMAX(s32LocalPredEs_tiMinBufMax_MP1,
                             PredEs_tiMinBufPrevMax_MP);
   u32LocalPredEs_tiMinBufMaxRaw_MP =
      (uint32)(u16LocalPredEs_tiMinBufMax_MP2 - PredEs_tiCntFct2CntCgt);
   /*QAC Msg(3:0291): The result of u32LocalPredEs_tiMinBufMaxRaw_MP is always
                      positif*/

   PredEs_tiMinBufMaxRaw_MP =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiMinBufMaxRaw_MP, 65000);

   /*Production of PredEs_tiMaxBufMin_MP and PredEs_tiMinBufMax_MP*/
   if (PredEs_bVldTiLstCgtUpd != 0)
   {
      if (PredEs_bNotCgtLstFct != 0)
      {
         u32LocalPredEs_tiMaxBufMin_MP = (u32LocalPredEs_tiMaxBufMin_MP1 + 500);
         s32LocalPredEs_tiMinBufMax_MP = (s32LocalPredEs_tiMinBufMax_MP1 + 500);
         u32LocalPredEs_tiMinBufMax_MP =
            (uint32)MATHSRV_udtMAX(s32LocalPredEs_tiMinBufMax_MP, 0);
      }
      else
      {
         u32LocalPredEs_tiMaxBufMin_MP =
            (uint32)MATHSRV_udtMAX(PredEs_tiMaxBufMinRaw_MP,
                                   PredEs_tiMinBufMaxRaw_MP);
         u32LocalPredEs_tiMaxBufMin_MP =
            MATHSRV_udtMIN(u32LocalPredEs_tiMaxBufMin_MP,
                           PredEs_tiMaxBufMax);
         u32LocalPredEs_tiMinBufMax_MP =
            (uint32)MATHSRV_udtMIN(PredEs_tiMaxBufMinRaw_MP,
                                   PredEs_tiMinBufMaxRaw_MP);
      }
   }
   else
   {
      u32LocalPredEs_tiMaxBufMin_MP = (uint32)PredEs_tiMaxBufMax;
      u32LocalPredEs_tiMinBufMax_MP = 0;
   }
   PredEs_tiMaxBufMin_MP =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiMaxBufMin_MP, 65000);
   PredEs_tiMinBufMax_MP =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiMinBufMax_MP, 65000);

   /*Production of PredEs_tiDlyLstClcNNew*/
   u32LocalPredEs_tiDlyLstClcNNew =
      (uint32)(PredEs_tiMaxBufMin_MP + PredEs_tiMinBufMax_MP);
   u32LocalPredEs_tiDlyLstClcNNew = (u32LocalPredEs_tiDlyLstClcNNew / 2);
   PredEs_tiDlyLstClcNNew = (uint16)u32LocalPredEs_tiDlyLstClcNNew;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCalcDlyBtwEngSpdNCrtTi                           */
/* !Description :  This block evaluates the duration between the last         */
/*                 instantaneous engine speed calculation and the current     */
/*                 function call (current time).                              */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean PredEs_bVldTiLstCgtUpd;                                     */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input uint8 PredEs_noNFill;                                               */
/*  input uint16 PredEs_tiDlyLstClcNNew;                                      */
/*  input sint16 PredEs_tiCntFct2CntCgt;                                      */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint16 PredEs_prm_nBuf[255];                                        */
/*  output boolean PredEs_bVldTiLstCgt;                                       */
/*  output uint16 PredEs_tiDlyLstClcN;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCalcDlyBtwEngSpdNCrtTi(void)
{
   uint8  u8LocalPredEs_idxLstBufWr;
   uint16 u16LocalPredEs_prm_nBuf;
   uint32 u32LocalDiff;
   uint32 u32LocalPredEs_prm_nBuf;
   uint32 u32LocalPredEs_tiDlyLstClcN;
   sint32 s32LocalDiff;

   /*Production of PredEs_tiDlyLstClcN and PredEs_bVldTiLstCgt*/
   if (  (PredEs_bVldTiLstCgtUpd != 0)
      && (PredEs_bFirstClcPredEs == 0)
      && (PredEs_noNFill >= 1))
   {
      PredEs_bVldTiLstCgt = 1;
      s32LocalDiff =
         (sint32)(PredEs_tiDlyLstClcNNew - PredEs_tiCntFct2CntCgt);
      u32LocalDiff = (uint32)MATHSRV_udtMAX(s32LocalDiff, 0);
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
      u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[u8LocalPredEs_idxLstBufWr];
      u16LocalPredEs_prm_nBuf =
         (uint16)MATHSRV_udtMAX(u16LocalPredEs_prm_nBuf, 1);
      u32LocalPredEs_prm_nBuf = (uint32)(75000 / u16LocalPredEs_prm_nBuf);
      u32LocalPredEs_tiDlyLstClcN = (u32LocalPredEs_prm_nBuf + u32LocalDiff);
   }
   else
   {
      PredEs_bVldTiLstCgt = 0;
      u32LocalPredEs_tiDlyLstClcN = 0;
   }
   PredEs_tiDlyLstClcN =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiDlyLstClcN, 65000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCorrectPredictionTime                            */
/* !Description :  This block corrects the prediction times and engine speed  */
/*                 values. Also, the engine speed offset is estimated to      */
/*                 correct the engine model.                                  */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_023.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoEmCkg_tiStaEgdLoThd;                                        */
/*  input uint8 CoEmCkg_tiStaEgdHiThd;                                        */
/*  input uint16 CoEmCkg_nStaEgdLoThd;                                        */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input boolean PredEs_bSecPhaPred;                                         */
/*  input uint16 PredEs_tiDlyLstClcN;                                         */
/*  input uint16 PredEs_tiErrOkN2EgdChgDir2;                                  */
/*  input uint16 PredEs_tiDlyStaEgdHiThd_C;                                   */
/*  input uint16 PredEs_tiErrOkN2EgdChgDir;                                   */
/*  input uint8 PredEs_nStaEgdLoThd2_C;                                       */
/*  input uint8 PredEs_idxLstBufWr;                                           */
/*  input uint8 PredEs_noCgtPhaEng_C;                                         */
/*  input uint8 PredEs_noCaseBuf_C;                                           */
/*  input uint16 PredEs_prm_nBuf[255];                                        */
/*  input sint16 PredEs_n2DecE2TDC;                                           */
/*  input sint16 PredEs_n2PredCur_MP;                                         */
/*  input uint16 PREDES_Sqrt_Bkpt[9];                                         */
/*  input uint16 PREDES_Sqrt_Table[9];                                        */
/*  input uint8 PredEs_noNFill;                                               */
/*  input boolean PredEs_bTypCgt180First;                                     */
/*  input uint16 PredEs_nPredCur_MP;                                          */
/*  input sint16 PredEs_nCorPred;                                             */
/*  output uint16 PredEs_tiStaEgdLoThd;                                       */
/*  output uint16 PredEs_tiStaEgdHiThd;                                       */
/*  output sint16 PredEs_nStaEgdLoThd;                                        */
/*  output sint16 PredEs_n2PredCur_MP;                                        */
/*  output uint16 PredEs_nPredCur_MP;                                         */
/*  output sint16 PredEs_nCorPred;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCorrectPredictionTime(void)
{
   boolean bLocalSecPhaPredCor;
   uint8   u8LocalCoEmCkg_tiStaEgdLoThd;
   uint8   u8LocalCoEmCkg_tiStaEgdHiThd;
   uint8   u8LocalIndex;
   uint8   u8LocalPredEs_idxLstBufWr;
   uint16  u16LocalCoEmCkg_nStaEgdLoThd;
   uint16  u16LocalPredEs_n2PredCur_ABS;
   uint16  u16LocalCalcPara;
   uint16  u16LocalInterp1D;
   uint16  u16LocalPredEs_prm_nBuf;
   sint16  s16LocalCalc;
   uint32  u32LocalPredEs_tiStaEgdLoThd;
   uint32  u32LocalPredEs_tiStaEgdHiThd;
   uint32  u32LocalPredEs_prm_n2Buf;
   sint32  s32LocalPredEs_prm_n2Buf;
   sint32  s32LocalPredEs_nStaEgdLoThd;
   sint32  s32LocalPredEs_n2PredCur_MP;
   sint32  s32LocalPredEs_nCorPred;


   VEMS_vidGET(CoEmCkg_tiStaEgdLoThd, u8LocalCoEmCkg_tiStaEgdLoThd);
   VEMS_vidGET(CoEmCkg_tiStaEgdHiThd, u8LocalCoEmCkg_tiStaEgdHiThd);
   VEMS_vidGET(CoEmCkg_nStaEgdLoThd, u16LocalCoEmCkg_nStaEgdLoThd);

   /*Production of  bLocalSecPhaPredCor*/
   if (PredEs_bFirstClcPredEs != 0)
   {
      bLocalSecPhaPredCor = 0;
   }
   else
   {
      bLocalSecPhaPredCor = PredEs_bSecPhaPred;
   }
   /*Production of PredEs_tiStaEgdLoThd and PredEs_tiStaEgdHiThd*/
   u32LocalPredEs_tiStaEgdLoThd =
      (uint32)((u8LocalCoEmCkg_tiStaEgdLoThd * 50) + PredEs_tiDlyLstClcN);
   PredEs_tiStaEgdLoThd =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiStaEgdLoThd, 65000);
   if (bLocalSecPhaPredCor != 0)
   {
      u32LocalPredEs_tiStaEgdHiThd = (uint32)( (u8LocalCoEmCkg_tiStaEgdHiThd
                                               * 50)
                                             + PredEs_tiErrOkN2EgdChgDir2
                                             + PredEs_tiDlyStaEgdHiThd_C
                                             + PredEs_tiDlyLstClcN
                                             + 250);
   }
   else
   {
      u32LocalPredEs_tiStaEgdHiThd = (uint32)( (u8LocalCoEmCkg_tiStaEgdHiThd
                                               * 50)
                                             + PredEs_tiErrOkN2EgdChgDir
                                             + PredEs_tiDlyLstClcN
                                             + 250);
   }
   PredEs_tiStaEgdHiThd =
      (uint16)MATHSRV_udtMIN(u32LocalPredEs_tiStaEgdHiThd, 65000);

   /*Production of PredEs_nStaEgdLoThd*/
   if (bLocalSecPhaPredCor != 0)
   {
      s32LocalPredEs_nStaEgdLoThd =
         (sint32)( ( PredEs_tiErrOkN2EgdChgDir2
                   + (PredEs_nStaEgdLoThd2_C * 100))
                 - ( u16LocalCoEmCkg_nStaEgdLoThd
                   * 10));

   }
   else
   {
      s32LocalPredEs_nStaEgdLoThd =
         (sint32)( ( PredEs_tiErrOkN2EgdChgDir
                   + 200)
                 - ( u16LocalCoEmCkg_nStaEgdLoThd
                   * 10));
   }
   if (s32LocalPredEs_nStaEgdLoThd < 0)
   {
      s32LocalPredEs_nStaEgdLoThd = ((s32LocalPredEs_nStaEgdLoThd - 5) / 10);
   }
   else
   {
      s32LocalPredEs_nStaEgdLoThd = ((s32LocalPredEs_nStaEgdLoThd + 5) / 10);
   }
   PredEs_nStaEgdLoThd =
      (sint16)MATHSRV_udtCLAMP(s32LocalPredEs_nStaEgdLoThd, 0, 500);

   /*Production of PredEs_n2PredCur_MP*/
   s16LocalCalc = (sint16)(PredEs_idxLstBufWr - PredEs_noCgtPhaEng_C);
   if (PredEs_noCaseBuf_C != 0)
   {
      s16LocalCalc = (sint16)(s16LocalCalc % PredEs_noCaseBuf_C);
   }
   else
   {
      s16LocalCalc = 0;
      SWFAIL_vidSoftwareErrorHook();
   }
   if (s16LocalCalc < 0)
   {
      s16LocalCalc = (sint16)(s16LocalCalc + PredEs_noCaseBuf_C);
   }
   u8LocalIndex = (uint8)MATHSRV_udtMAX(s16LocalCalc, 0);
   u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[u8LocalIndex];
   u32LocalPredEs_prm_n2Buf =
      (uint32)(u16LocalPredEs_prm_nBuf * u16LocalPredEs_prm_nBuf);
   s32LocalPredEs_prm_n2Buf = (sint32)((u32LocalPredEs_prm_n2Buf + 16)/ 32);
   s32LocalPredEs_n2PredCur_MP =
      (s32LocalPredEs_prm_n2Buf - PredEs_n2DecE2TDC);
   PredEs_n2PredCur_MP =
      (sint16)MATHSRV_udtCLAMP(s32LocalPredEs_n2PredCur_MP, -31250, 31250);

   /*Production of PredEs_nPredCur_MP*/
   u16LocalPredEs_n2PredCur_ABS = (uint16)MATHSRV_udtABS(PredEs_n2PredCur_MP);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(PREDES_Sqrt_Bkpt,
                                                   u16LocalPredEs_n2PredCur_ABS,
                                                   9);
   u16LocalInterp1D = MATHSRV_u16Interp1d(PREDES_Sqrt_Table,
                                          u16LocalCalcPara);
   PredEs_nPredCur_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 1000);

   /*Production of PredEs_nCorPred*/
   if (  (PredEs_noNFill > PredEs_noCgtPhaEng_C)
      && (PredEs_n2PredCur_MP >= 0)
      && (PredEs_bTypCgt180First == 0))
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
      u16LocalPredEs_prm_nBuf = PredEs_prm_nBuf[u8LocalPredEs_idxLstBufWr];
      s32LocalPredEs_nCorPred =
         (sint32)(u16LocalPredEs_prm_nBuf - PredEs_nPredCur_MP);
   }
   else
   {
      if (PredEs_bFirstClcPredEs != 0)
      {
         s32LocalPredEs_nCorPred = 0;
      }
      else
      {
         s32LocalPredEs_nCorPred = (sint32)PredEs_nCorPred;
      }
   }
   PredEs_nCorPred =
      (sint16)MATHSRV_udtCLAMP(s32LocalPredEs_nCorPred, -500, 1000);

}
/*------------------------------- end of file --------------------------------*/