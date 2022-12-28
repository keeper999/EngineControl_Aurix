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
/* !File            : PREDES_FCT4.C                                           */
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
/*   1 / PREDES_vidFormatInformation                                          */
/*   2 / PREDES_vidEvaluatCorEngSpdValdty                                     */
/*   3 / PREDES_vidEstimatCorrectedEngSpd                                     */
/*   4 / PREDES_vidChkCondToEngagAreFlfld                                     */
/*   5 / PREDES_vidSetRlbleEngagemntAuthr                                     */
/*   6 / PREDES_vidMergThe2Authorizations                                     */
/*   7 / PREDES_vidCorrOutIfCalcDisabled                                      */
/*   8 / PREDES_vidSetRelSecEngAuthorize                                      */
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

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidFormatInformation                                */
/* !Description :  This block calculates several variables:- The current      */
/*                 engine speed, - The current engine speed validity, - The   */
/*                 offset time to compensate the prediction setpoints, - And  */
/*                 mainly, the engagement authorization before the first      */
/*                 engine direction change                                    */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_032.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidEvaluatCorEngSpdValdty();                      */
/*  extf argret void PREDES_vidEstimatCorrectedEngSpd();                      */
/*  extf argret void PREDES_vidChkCondToEngagAreFlfld();                      */
/*  extf argret void PREDES_vidSetRlbleEngagemntAuthr();                      */
/*  extf argret void PREDES_vidSetRelSecEngAuthorize();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidFormatInformation(void)
{
   PREDES_vidEvaluatCorEngSpdValdty();
   PREDES_vidEstimatCorrectedEngSpd();
   PREDES_vidChkCondToEngagAreFlfld();
   PREDES_vidSetRlbleEngagemntAuthr();
   PREDES_vidSetRelSecEngAuthorize();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidEvaluatCorEngSpdValdty                           */
/* !Description :  This block evaluates the current engine speed validity     */
/*                 (with delay correction).                                   */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_033.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 PredEs_noNFill;                                               */
/*  input uint8 PredEs_noCgtPhaEng_C;                                         */
/*  input boolean PredEs_bClcPredCurN;                                        */
/*  input boolean PredEs_bVldTiLstCgt;                                        */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input sint16 PredEs_nCurRaw;                                              */
/*  input sint16 PredEs_nStaEgdLoThd;                                         */
/*  input boolean PredEs_bVldCurNCll_MP;                                      */
/*  input boolean PREDES_bFlipFlopOut3;                                       */
/*  output boolean PredEs_bVldCurNCll_MP;                                     */
/*  output boolean PREDES_bFlipFlopOut3;                                      */
/*  output boolean PredEs_bVldCurNCll;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidEvaluatCorEngSpdValdty(void)
{
   /*Production of PredEs_bVldCurNCll_MP*/
   if (  (PredEs_noNFill > PredEs_noCgtPhaEng_C)
      && (PredEs_bClcPredCurN != 0)
      && (PredEs_bVldTiLstCgt != 0)
      && (PredEs_bFirstClcPredEs == 0))
   {
      PredEs_bVldCurNCll_MP = 1;
   }
   else
   {
      PredEs_bVldCurNCll_MP = 0;
   }

   /*flip flop*/
   if (  (PredEs_nCurRaw < PredEs_nStaEgdLoThd)
      && (PredEs_bVldCurNCll_MP != 0))
   {
      PREDES_bFlipFlopOut3 = 0;
   }
   else
   {
      if (PredEs_bFirstClcPredEs != 0)
      {
         PREDES_bFlipFlopOut3 = 1;
      }
   }

   /*Production of PredEs_bVldCurNCll*/
   if (  (PredEs_bVldCurNCll_MP != 0)
      && (PREDES_bFlipFlopOut3 != 0))
   {
      PredEs_bVldCurNCll = 1;
   }
   else
   {
      PredEs_bVldCurNCll = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidEstimatCorrectedEngSpd                           */
/* !Description :  This block calculates the current engine speed in case of  */
/*                 the current engine speed with delay compensation is        */
/*                 invalid.                                                   */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_034.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 PredEs_idxLstBufTiWr;                                         */
/*  input uint32 BufNEs_prm_tiCgtBuf[12];                                     */
/*  input uint32 PredEs_tiCgtLst_MP;                                          */
/*  input uint32 PredEs_tiCgt_MP;                                             */
/*  input boolean PredEs_bDirRotCk;                                           */
/*  input uint8 PredEs_noNFillTi;                                             */
/*  input sint16 PredEs_nCurCor2;                                             */
/*  input boolean PredEs_bVldCurNCll;                                         */
/*  input sint16 PredEs_nCurRaw;                                              */
/*  input sint16 PredEs_nCurRaw_MP;                                           */
/*  output uint32 PredEs_tiCgt_MP;                                            */
/*  output uint32 PredEs_tiCgtLst_MP;                                         */
/*  output sint16 PredEs_nCurCor2;                                            */
/*  output sint16 PredEs_nCurRaw_MP;                                          */
/*  output sint16 PredEs_nCurCor;                                             */
/*  output boolean PredEs_bVldCurNCor;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidEstimatCorrectedEngSpd(void)
{
   uint8  u8LocalBufNEs_prm_tiCgtBufPos1;
   uint8  u8LocalBufNEs_prm_tiCgtBufPos2;
   sint16 s16LocalBufNEs_prm_tiCgtBufPos;
   sint16 s16LocalPredEs_nCurCor;
   sint16 s16LocalPredEs_nCurCor2;
   uint32 u32LocalPredEs_tiCgt_MP;
   uint32 u32LocalPredEs_tiCgtLst_MP;
   uint32 u32LocalMin;
   uint32 u32LocalMax;


   /*Production of PredEs_tiCgt_MP*/
   u8LocalBufNEs_prm_tiCgtBufPos1 = (uint8)(PredEs_idxLstBufTiWr % 12);
   VEMS_vidGET1DArrayElement(BufNEs_prm_tiCgtBuf,
                             u8LocalBufNEs_prm_tiCgtBufPos1,
                             u32LocalPredEs_tiCgt_MP);
   PredEs_tiCgt_MP = MATHSRV_udtMIN(u32LocalPredEs_tiCgt_MP, 500000);

   /*Production of PredEs_tiCgtLst_MP*/
   s16LocalBufNEs_prm_tiCgtBufPos = (sint16)(PredEs_idxLstBufTiWr - 1);
   s16LocalBufNEs_prm_tiCgtBufPos =
      (sint16)(s16LocalBufNEs_prm_tiCgtBufPos % 12);
   if (s16LocalBufNEs_prm_tiCgtBufPos < 0)
   {
      s16LocalBufNEs_prm_tiCgtBufPos =
         (sint16)(s16LocalBufNEs_prm_tiCgtBufPos + 12);
   }
   u8LocalBufNEs_prm_tiCgtBufPos2 = (uint8)s16LocalBufNEs_prm_tiCgtBufPos;

   VEMS_vidGET1DArrayElement(BufNEs_prm_tiCgtBuf,
                             u8LocalBufNEs_prm_tiCgtBufPos2,
                             u32LocalPredEs_tiCgtLst_MP);
   PredEs_tiCgtLst_MP = MATHSRV_udtMIN(u32LocalPredEs_tiCgtLst_MP, 500000);

   u32LocalMin = MATHSRV_udtMIN(PredEs_tiCgtLst_MP, PredEs_tiCgt_MP);
   u32LocalMax = MATHSRV_udtMAX(u32LocalMin, 1000);

   if (PredEs_bDirRotCk != 0)
   {
      s16LocalPredEs_nCurCor2 = (sint16)(1000000 / u32LocalMax);
   }
   else
   {
      s16LocalPredEs_nCurCor2 = (sint16)(1000000 / u32LocalMax);
      s16LocalPredEs_nCurCor2 = (sint16)((-1) * s16LocalPredEs_nCurCor2);
   }
   PredEs_nCurCor2 =
      (sint16)MATHSRV_udtMAX(s16LocalPredEs_nCurCor2, -500);
   /*Production of PredEs_nCurRaw_MP*/
   if (PredEs_noNFillTi >= 2)
   {
      PredEs_nCurRaw_MP = PredEs_nCurCor2;
   }
   else
   {
      PredEs_nCurRaw_MP = 0;
   }
   /*Production of PredEs_nCurCor*/
   if (PredEs_bVldCurNCll != 0)
   {
      s16LocalPredEs_nCurCor = PredEs_nCurRaw;
   }
   else
   {
      s16LocalPredEs_nCurCor = PredEs_nCurRaw_MP;
   }
   PredEs_nCurCor =
      (sint16)MATHSRV_udtCLAMP(s16LocalPredEs_nCurCor, -500, 1000);

   /*Production of PredEs_bVldCurNCor*/
   if (  (PredEs_bVldCurNCll != 0)
      || (PredEs_noNFillTi >= 2))
   {
      PredEs_bVldCurNCor = 1;
   }
   else
   {
      PredEs_bVldCurNCor = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidChkCondToEngagAreFlfld                           */
/* !Description :  This block informs that the engine speed will have the     */
/*                 aspects to request a starter engagement.                   */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_035.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 PredEs_noNFill;                                               */
/*  input uint8 PredEs_noCgtPhaEng_C;                                         */
/*  input boolean PredEs_bClcPredNHi;                                         */
/*  input boolean PredEs_bVldTiLstCgt;                                        */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input boolean PredEs_bVldOKN2Egd_MP;                                      */
/*  input sint16 PredEs_nPredLoRaw;                                           */
/*  input sint16 PredEs_nStaEgdLoThd;                                         */
/*  input sint16 PredEs_nPredHiRaw;                                           */
/*  input uint8 PredEs_nVldOKN2Egd_C;                                         */
/*  input boolean PredEs_bVldOkN2EgdSave;                                     */
/*  input sint16 PredEs_nCurCor2;                                             */
/*  input uint16 InjCtl_mfFuReq;                                              */
/*  input boolean CoEs_bAcvInjCutOffSTTEs;                                    */
/*  input boolean Ext_bAuthInj;                                               */
/*  input uint8 CoEmCkg_stStrtRstrtFbCmd;                                     */
/*  input boolean PredEs_bOkCndIntl;                                          */
/*  input boolean PREDES_bFlipFlopOut5;                                       */
/*  input boolean PredEs_bChgOKN2EgdChgDir_C;                                 */
/*  input boolean PREDES_bOkN2EgdPrev;                                        */
/*  input boolean PREDES_bFirstClcPredEsPrev;                                 */
/*  input uint8 PREDES_u8IncrCounter;                                         */
/*  output boolean PredEs_bVldOKN2Egd_MP;                                     */
/*  output boolean PredEs_bVldOkN2EgdSave;                                    */
/*  output boolean PREDES_bFlipFlopOut5;                                      */
/*  output boolean PredEs_bOkN2EgdChgDir;                                     */
/*  output boolean PREDES_bOkN2EgdPrev;                                       */
/*  output uint8 PREDES_u8IncrCounter;                                        */
/*  output boolean PredEs_bSecPhaPred;                                        */
/*  output boolean PredEs_bSecPhaSecu;                                        */
/*  output boolean PREDES_bFirstClcPredEsPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidChkCondToEngagAreFlfld(void)
{
   boolean bLocalConditonOR;
   boolean bLocalCoEs_bAcvInjCutOffSTTEs;
   boolean bLocalExt_bAuthInj;
   boolean bLocalCond;
   uint8   u8LocalCoEmCkg_stStrtRstrtFbCmd;
   uint16  u16LocalCounter;
   uint16  u16LocalInjCtl_mfFuReq;
   uint16  u16LocalPredEs_nVldOKN2Egd;


   /*Production of PredEs_bVldOKN2Egd_MP*/
   if (  (PredEs_noNFill > PredEs_noCgtPhaEng_C)
      && (PredEs_bClcPredNHi != 0)
      && (PredEs_bVldTiLstCgt != 0)
      && (PredEs_bFirstClcPredEs == 0))
   {
      PredEs_bVldOKN2Egd_MP = 1;
   }
   else
   {
      PredEs_bVldOKN2Egd_MP = 0;
   }

   /*flip flop 4*/
   if (PredEs_bFirstClcPredEs != 0)
   {
      PredEs_bVldOkN2EgdSave = 0;
   }
   else
   {
      if (PredEs_bVldOKN2Egd_MP != 0)
      {
         PredEs_bVldOkN2EgdSave = 1;
      }
   }

   /*Production of bLocalConditonOR*/
   if (  (PredEs_bVldOKN2Egd_MP == 0)
      || (PredEs_nPredLoRaw < PredEs_nStaEgdLoThd)
      || (PredEs_nPredHiRaw < PredEs_nStaEgdLoThd))
   {
      bLocalConditonOR = 1;
   }
   else
   {
      bLocalConditonOR = 0;
   }

   /*flip flop 5*/
   u16LocalPredEs_nVldOKN2Egd = (uint16)(PredEs_nVldOKN2Egd_C * 10);
   if (  (bLocalConditonOR != 0)
      && (PredEs_bVldOkN2EgdSave != 0)
      && (PredEs_nCurCor2 < u16LocalPredEs_nVldOKN2Egd))
   {
      PREDES_bFlipFlopOut5 = 0;
   }
   else
   {
      if (PredEs_bFirstClcPredEs != 0)
      {
         PREDES_bFlipFlopOut5 = 1;
      }
   }

   /*Production of PredEs_bOkN2EgdChgDir*/
   VEMS_vidGET(InjCtl_mfFuReq, u16LocalInjCtl_mfFuReq);
   VEMS_vidGET(CoEs_bAcvInjCutOffSTTEs, bLocalCoEs_bAcvInjCutOffSTTEs);
   VEMS_vidGET(Ext_bAuthInj, bLocalExt_bAuthInj);
   VEMS_vidGET(CoEmCkg_stStrtRstrtFbCmd, u8LocalCoEmCkg_stStrtRstrtFbCmd);

   if (  (  (u16LocalInjCtl_mfFuReq == 0)
         || (bLocalCoEs_bAcvInjCutOffSTTEs != 0)
         || (bLocalExt_bAuthInj == 0))
      && (PredEs_bOkCndIntl != 0)
      && (u8LocalCoEmCkg_stStrtRstrtFbCmd != 1)
      && (PredEs_bVldOKN2Egd_MP != 0)
      && (PREDES_bFlipFlopOut5 != 0)
      && (PredEs_nCurCor2 < u16LocalPredEs_nVldOKN2Egd))
   {
      bLocalCond = 1;
   }
   else
   {
      bLocalCond = 0;
   }
   if (PredEs_bChgOKN2EgdChgDir_C != 0)
   {
      if (  (bLocalCond != 0)
         && (PREDES_bOkN2EgdPrev == 0))
      {
         PredEs_bOkN2EgdChgDir = 1;
      }
      else
      {
         PredEs_bOkN2EgdChgDir = 0;
      }
   }
   else
   {
      PredEs_bOkN2EgdChgDir = bLocalCond;
   }
   PREDES_bOkN2EgdPrev = bLocalCond;
   /* Begin Bloc Counter */
   if (  (PredEs_bFirstClcPredEs != 0)
      && (PREDES_bFirstClcPredEsPrev == 0) )
   {
      PREDES_u8IncrCounter = 0;
   }
   else
   {
      if (bLocalCond != 0)
      {
         u16LocalCounter = (uint16)(PREDES_u8IncrCounter + 1);
         PREDES_u8IncrCounter = (uint8)MATHSRV_udtMIN(u16LocalCounter, 255);
      }
   }
   if (PREDES_u8IncrCounter >= 1)
   {
      PredEs_bSecPhaPred = 1;
   }
   else
   {
      PredEs_bSecPhaPred = 0;
   }
   if (PREDES_u8IncrCounter >= 2)
   {
      PredEs_bSecPhaSecu = 1;
   }
   else
   {
      PredEs_bSecPhaSecu = 0;
   }

   PREDES_bFirstClcPredEsPrev = PredEs_bFirstClcPredEs;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidSetRlbleEngagemntAuthr                           */
/* !Description :  This block verifies the engagement authorization is        */
/*                 correct.                                                   */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_036.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoEmCkg_tiStaEgdHiThd;                                        */
/*  input boolean PREDES_bTmr1Out;                                            */
/*  input boolean PredEs_bOkN2EgdChgDir;                                      */
/*  input boolean PredEs_bSecPhaSecu;                                         */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input boolean PREDES_bStrtTmrRst1Prev;                                    */
/*  input uint8 PREDES_u8Cnt1;                                                */
/*  input boolean PREDES_bTmr1OutPrev;                                        */
/*  input boolean PredEs_bDirRotCk;                                           */
/*  input sint8 PredEs_tiIncErrOkEgdChgDir_C;                                 */
/*  input uint16 PredEs_tiErrOkN2EgdChgDir;                                   */
/*  input sint16 PredEs_tiErrOkN2EgdInc_MP;                                   */
/*  output boolean PREDES_bTmr1OutPrev;                                       */
/*  output boolean PREDES_bTmr1Out;                                           */
/*  output uint8 PREDES_u8Cnt1;                                               */
/*  output sint16 PredEs_tiErrOkN2EgdInc_MP;                                  */
/*  output uint16 PredEs_tiErrOkN2EgdChgDir_NV;                               */
/*  output uint16 PredEs_tiErrOkN2EgdChgDir;                                  */
/*  output boolean PREDES_bStrtTmrRst1Prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidSetRlbleEngagemntAuthr(void)
{

   boolean bLocalStrtTmrRst1;
   uint8   u8LocalCoEmCkg_tiStaEgdHiThd;
   sint16  s16LocalSommeChgDir2;
   sint32  s32LocalPredEs_DetectSatIn;
   sint32  s32LocalPredEs_DetectSatOut;


   VEMS_vidGET(CoEmCkg_tiStaEgdHiThd, u8LocalCoEmCkg_tiStaEgdHiThd);
   u8LocalCoEmCkg_tiStaEgdHiThd = (uint8)(u8LocalCoEmCkg_tiStaEgdHiThd / 10);

   /*TmrRst1*/
   PREDES_bTmr1OutPrev = PREDES_bTmr1Out;
   if (  (PredEs_bOkN2EgdChgDir != 0)
      && (PredEs_bSecPhaSecu == 0))
   {
      bLocalStrtTmrRst1 = 1;
   }
   else
   {
      bLocalStrtTmrRst1 = 0;
   }
   if (PredEs_bFirstClcPredEs != 0)
   {
      PREDES_bTmr1Out = 0;
      PREDES_u8Cnt1 = 0;
   }
   else
   {
      if (  (bLocalStrtTmrRst1 != 0)
         && (PREDES_bStrtTmrRst1Prev == 0))
      {
         PREDES_u8Cnt1 = u8LocalCoEmCkg_tiStaEgdHiThd;
      }
      else
      {
         if (PREDES_u8Cnt1 > 0)
         {
            PREDES_u8Cnt1 = (uint8)(PREDES_u8Cnt1 - 1);
         }
      }
      if (PREDES_u8Cnt1 > 0)
      {
         PREDES_bTmr1Out = 1;
      }
      else
      {
         PREDES_bTmr1Out = 0;
      }
   }
   if (  (PREDES_bTmr1Out == 0)
      && (PREDES_bTmr1OutPrev != 0)
      && (PredEs_bFirstClcPredEs == 0))
   {
      if (PredEs_bDirRotCk != 0)
      {
         PredEs_tiErrOkN2EgdInc_MP = -10;
      }
      else
      {
         s16LocalSommeChgDir2 =
            (sint16)(PredEs_tiIncErrOkEgdChgDir_C * 10);
         PredEs_tiErrOkN2EgdInc_MP =
           (sint16)MATHSRV_udtCLAMP(s16LocalSommeChgDir2,
                                    -1250,
                                    1250);
      }
   }
   else
   {
      PredEs_tiErrOkN2EgdInc_MP = 0;
   }
   s32LocalPredEs_DetectSatIn =
      (sint32)(PredEs_tiErrOkN2EgdChgDir + PredEs_tiErrOkN2EgdInc_MP);

   /*DetectSat1*/
   if (s32LocalPredEs_DetectSatIn <= 0)
   {
      s32LocalPredEs_DetectSatOut = 0;
   }
   else
   {
      if (s32LocalPredEs_DetectSatIn >= 2500)
      {
         s32LocalPredEs_DetectSatOut = 2500;
      }
      else
      {
         s32LocalPredEs_DetectSatOut = s32LocalPredEs_DetectSatIn;
      }
   }
   PredEs_tiErrOkN2EgdChgDir_NV = (uint16)(s32LocalPredEs_DetectSatOut / 5);
   PredEs_tiErrOkN2EgdChgDir = (uint16)s32LocalPredEs_DetectSatOut;
   PREDES_bStrtTmrRst1Prev = bLocalStrtTmrRst1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidMergThe2Authorizations                           */
/* !Description :  This block merges information:- First one created during   */
/*                 the engine stop before the change of the rotation          */
/*                 direction, - Second one created during the engine stop     */
/*                 after the change of the rotation direction                 */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_037.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean PredEs_bOkOscN;                                             */
/*  input boolean PredEs_bOkN2EgdChgDir;                                      */
/*  output boolean PredEs_bDetSlowNPredRaw;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidMergThe2Authorizations(void)
{
   /*Production of PredEs_bDetSlowNPredRaw*/
   if (  (PredEs_bOkOscN != 0)
      || (PredEs_bOkN2EgdChgDir != 0))
   {
      PredEs_bDetSlowNPredRaw = 1;
   }
   else
   {
      PredEs_bDetSlowNPredRaw = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidCorrOutIfCalcDisabled                            */
/* !Description :  This block disables the engagement authorization if the    */
/*                 engine speed is higher than a threshold.                   */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_038.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean PredEs_bClcPredEs;                                          */
/*  input boolean PredEs_bDetSlowNPredRaw;                                    */
/*  output boolean PredEs_bDetSlowNPred;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidCorrOutIfCalcDisabled(void)
{
   /*Production of PredEs_bDetSlowNPred*/
   if (  (PredEs_bClcPredEs != 0)
      && (PredEs_bDetSlowNPredRaw != 0))
   {
      VEMS_vidSET(PredEs_bDetSlowNPred, 1);
   }
   else
   {
      VEMS_vidSET(PredEs_bDetSlowNPred, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PREDES_vidSetRelSecEngAuthorize                            */
/* !Description :  This function verifies the second engagement authorization */
/*                 is correct.                                                */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_R_11_01167_039.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean PredEs_bOkN2EgdChgDir;                                      */
/*  input boolean PredEs_bSecPhaSecu;                                         */
/*  input boolean PREDES_bStrtTmrRst2Prev;                                    */
/*  input boolean PREDES_bTmrRstOut2;                                         */
/*  input boolean PredEs_bFirstClcPredEs;                                     */
/*  input boolean PREDES_bFallEdgStrtTmrRst2Prev;                             */
/*  input uint8 CoEmCkg_tiStaEgdHiThd;                                        */
/*  input uint16 PredEs_tiDlyStaEgdHiThd_C;                                   */
/*  input uint8 PREDES_u8CntTmrRst2;                                          */
/*  input boolean PredEs_bDirRotCk;                                           */
/*  input sint8 PredEs_tiIncErrOkEgdChgDir_C;                                 */
/*  input uint16 PredEs_tiErrOkN2EgdChgDir2;                                  */
/*  output boolean PREDES_bTmrRstOut2;                                        */
/*  output uint8 PREDES_u8CntTmrRst2;                                         */
/*  output uint16 PredEs_tiErrOkN2EgdChgDir2_NV;                              */
/*  output uint16 PredEs_tiErrOkN2EgdChgDir2;                                 */
/*  output boolean PREDES_bStrtTmrRst2Prev;                                   */
/*  output boolean PREDES_bFallEdgStrtTmrRst2Prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PREDES_vidSetRelSecEngAuthorize(void)
{
   boolean bLocalStrtTmrRst2Tmr;
   boolean bLocalTmr2OutPrev;
   boolean bLocalStrtTmrRst2And;
   uint8   u8LocalCoEmCkg_tiStaEgdHiThd;
   uint8   u8LocalSommeTmrRst2;
   sint16  s16LocalSommeChgDir2;
   sint32  s32LocalPredEs_DetectSatIn;
   sint32  s32LocalPredEs_DetectSatOut;


   /*And operator*/
   if (  (PredEs_bOkN2EgdChgDir != 0)
      && (PredEs_bSecPhaSecu != 0))
   {
      bLocalStrtTmrRst2And = 1;
   }
   else
   {
      bLocalStrtTmrRst2And = 0;
   }
   if (  (bLocalStrtTmrRst2And == 0)
      && (PREDES_bStrtTmrRst2Prev != 0))
   {
      bLocalStrtTmrRst2Tmr = 1;
   }
   else
   {
      bLocalStrtTmrRst2Tmr = 0;
   }
   /*TmrRst1*/
   bLocalTmr2OutPrev = PREDES_bTmrRstOut2;
   if (PredEs_bFirstClcPredEs != 0)
   {
      PREDES_bTmrRstOut2 = 0;
      PREDES_u8CntTmrRst2 = 0;
   }
   else
   {
      if (  (bLocalStrtTmrRst2Tmr != 0)
         && (PREDES_bFallEdgStrtTmrRst2Prev == 0))
      {
         VEMS_vidGET(CoEmCkg_tiStaEgdHiThd, u8LocalCoEmCkg_tiStaEgdHiThd);
         u8LocalSommeTmrRst2 =
            (uint8)( ((uint32)( (50 * u8LocalCoEmCkg_tiStaEgdHiThd)
                              + PredEs_tiDlyStaEgdHiThd_C
                              + 250))
                   / 500);
         PREDES_u8CntTmrRst2 = u8LocalSommeTmrRst2;
      }
      else
      {
         if (PREDES_u8CntTmrRst2 > 0)
         {
            PREDES_u8CntTmrRst2 = (uint8)(PREDES_u8CntTmrRst2 - 1);
         }
      }
      if (PREDES_u8CntTmrRst2 > 0)
      {
         PREDES_bTmrRstOut2 = 1;

      }
      else
      {
         PREDES_bTmrRstOut2 = 0;
      }
   }

   if (  (PREDES_bTmrRstOut2 == 0)
      && (bLocalTmr2OutPrev != 0)
      && (PredEs_bFirstClcPredEs == 0))
   {
      if (PredEs_bDirRotCk != 0)
      {
         s16LocalSommeChgDir2 = -10;
      }
      else
      {
         s16LocalSommeChgDir2 =
            (sint16)(PredEs_tiIncErrOkEgdChgDir_C * 10);
      }
   }
   else
   {
      s16LocalSommeChgDir2 = 0;
   }
   s32LocalPredEs_DetectSatIn =
      (sint32)(PredEs_tiErrOkN2EgdChgDir2 + s16LocalSommeChgDir2);

   /*DetectSat1*/
   s32LocalPredEs_DetectSatOut = MATHSRV_udtCLAMP(s32LocalPredEs_DetectSatIn,
                                                  0,
                                                  2500);
   PredEs_tiErrOkN2EgdChgDir2_NV = (uint16)(s32LocalPredEs_DetectSatOut / 5);
   PredEs_tiErrOkN2EgdChgDir2 = (uint16)s32LocalPredEs_DetectSatOut;

   PREDES_bStrtTmrRst2Prev = bLocalStrtTmrRst2And;
   PREDES_bFallEdgStrtTmrRst2Prev = bLocalStrtTmrRst2Tmr;
}
/*------------------------------- end of file --------------------------------*/