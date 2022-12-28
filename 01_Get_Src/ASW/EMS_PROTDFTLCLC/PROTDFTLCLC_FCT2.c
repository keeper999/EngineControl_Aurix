/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTDFTLCLC                                             */
/* !Description     : PROTDFTLCLC component.                                  */
/*                                                                            */
/* !Module          : PROTDFTLCLC                                             */
/* !Description     : Protection Differentiel et Surchauffe Frein             */
/*                                                                            */
/* !File            : PROTDFTLCLC_FCT2.C                                      */
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
/*   1 / PROTDFTLCLC_vidDetCoupleLimitRou                                     */
/*   2 / PROTDFTLCLC_vidDetCoupleLimitMot                                     */
/*   3 / PROTDFTLCLC_vidDetCouplProtFrein                                     */
/*   4 / PROTDFTLCLC_vidCoordCouplLimit                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 04686 / 01                                        */
/* !OtherRefs   : 01460_10_02301 / 1.2                                        */
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
#include "PROTDFTLCLC.h"
#include "PROTDFTLCLC_L.h"
#include "PROTDFTLCLC_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetCoupleLimitRou                           */
/* !Description :  Ce bloc détermine le couple roue de limitation à partir du */
/*                 régime différentiel des roues motrices et du taux de       */
/*                 sollicitation énergétique du différentiel.                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 CoPt_nDftlWhl;                                               */
/*  input uint16 CoPt_nDftlMinProtDftl_A[10];                                 */
/*  input uint16 CoPt_tqWhlMinProtDftl_T[10];                                 */
/*  input uint16 CoPt_nDftlMaxProtDftl_A[10];                                 */
/*  input uint16 CoPt_tqWhlMaxProtDftl_T[10];                                 */
/*  input uint8 CoPt_rEProtDftl;                                              */
/*  output uint16 CoPt_tqWhlMaxProtDftl;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetCoupleLimitRou(void)
{
   uint16 u16LocalInterp1dMin;
   uint16 u16LocalInterp1dMax;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16Local_CoPtNDftlWhl;
   sint32 s32LocalMaxProtDftl;


   u16Local_CoPtNDftlWhl = (uint16)(CoPt_nDftlWhl / 4);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(CoPt_nDftlMinProtDftl_A,
                                                    u16Local_CoPtNDftlWhl,
                                                    10);
   u16LocalInterp1dMin = MATHSRV_u16Interp1d(CoPt_tqWhlMinProtDftl_T,
                                             u16LocalCalcParaX);

   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(CoPt_nDftlMaxProtDftl_A,
                                                    u16Local_CoPtNDftlWhl,
                                                    10);
   u16LocalInterp1dMax = MATHSRV_u16Interp1d(CoPt_tqWhlMaxProtDftl_T,
                                             u16LocalCalcParaY);
   s32LocalMaxProtDftl = (sint32)(u16LocalInterp1dMax - u16LocalInterp1dMin);
   s32LocalMaxProtDftl = ((s32LocalMaxProtDftl * CoPt_rEProtDftl) / 64);
   s32LocalMaxProtDftl = ((u16LocalInterp1dMin * 2) + s32LocalMaxProtDftl);
   CoPt_tqWhlMaxProtDftl =
      (uint16)MATHSRV_udtCLAMP(s32LocalMaxProtDftl, 0, 44000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetCoupleLimitMot                           */
/* !Description :  Ce bloc détermine la limitation de couple moteur pour la   */
/*                 protection du différentiel. Il est calculé à partir du     */
/*                 couple roue de limitation et du taux de conversion de      */
/*                 couple.                                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CoPt_rCnvTq;                                                 */
/*  input uint16 PROTDFTLCLC_u16CoPtDftlWhl;                                  */
/*  input uint8 CoPt_facGainFilNProtDftl_C;                                   */
/*  input uint16 CoPt_nDftlWhl;                                               */
/*  input uint32 PROTDFTLCLC_u32rFilDftlWhlMem;                               */
/*  input uint8 CoPt_facGainFilFastProtDftl_C;                                */
/*  input uint8 CoPt_facGainFilSlowProtDftl_C;                                */
/*  input uint16 CoPt_tqWhlMaxProtDftl;                                       */
/*  input uint16 PROTDFTLCLC_u16WhlMaxProtDftl;                               */
/*  input uint32 PROTDFTLCLC_u32rFilMaxProtMem;                               */
/*  input boolean CoPt_bProtDftlAcv;                                          */
/*  input uint8 CoPt_tiAcvTqProtDftl_C;                                       */
/*  input uint8 CoPt_tiDeacTqProtDftl_C;                                      */
/*  input uint8 PROTDFTLCLC_u8ProtAcvSelPrev;                                 */
/*  input uint8 PROTDFTLCLC_u8ProtAcvSelOld;                                  */
/*  input sint16 CoPt_tqMaxProtDftlBfCord_MP;                                 */
/*  input uint8 PROTDFTLCLC_u8AcvDeacTr;                                      */
/*  input boolean PROTDFTLCLC_bActivationMem;                                 */
/*  input uint8 PROTDFTLCLC_u8AcvDeacTrDly;                                   */
/*  input boolean PROTDFTLCLC_bEtatTmr;                                       */
/*  input uint8 PROTDFTLCLC_u8Counter;                                        */
/*  input sint16 PROTDFTLCLC_s16MaxProtBfCord;                                */
/*  output uint16 PROTDFTLCLC_u16CoPtDftlWhl;                                 */
/*  output uint32 PROTDFTLCLC_u32rFilDftlWhlMem;                              */
/*  output sint8 CoPt_facSignNDftlWhl_MP;                                     */
/*  output uint16 PROTDFTLCLC_u16WhlMaxProtDftl;                              */
/*  output uint32 PROTDFTLCLC_u32rFilMaxProtMem;                              */
/*  output sint16 CoPt_tqMaxProtDftlBfCord_MP;                                */
/*  output uint8 PROTDFTLCLC_u8AcvDeacTr;                                     */
/*  output uint8 PROTDFTLCLC_u8ProtAcvSelOld;                                 */
/*  output boolean PROTDFTLCLC_bActivationMem;                                */
/*  output uint8 PROTDFTLCLC_u8Counter;                                       */
/*  output boolean PROTDFTLCLC_bEtatTmr;                                      */
/*  output sint16 CoPt_tqEfcMaxProtDftlBfCord;                                */
/*  output sint16 PROTDFTLCLC_s16MaxProtBfCord;                               */
/*  output uint8 PROTDFTLCLC_u8ProtAcvSelPrev;                                */
/*  output uint8 PROTDFTLCLC_u8AcvDeacTrDly;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetCoupleLimitMot(void)
{
   boolean  bLocalSelChg;
   boolean  bLocalEtatTmrPrev;
   boolean  bLocalActivationMemPrev;
   uint8    u8LocalfacGainFilDftl;
   uint8    u8LocalfacGainFilProtDftl;
   uint8    u8LocalfacGainFil;
   uint8    u8LocalNewSel;
   uint8    u8LocalTrSat;
   uint8    u8LocalNTr;
   uint8    u8LocalProtAcvSelOld;
   uint16   u16LocalCoPtDftlWhl;
   uint16   u16LocalCoPtNDftlWhl;
   uint16   u16LocalWhlMaxProtDftl;
   uint16   u16LocalCoPtCnvTq;
   uint32   u32LocalMaxProtDftlBfCord;
   sint16   s16LocalSwRmpTranInI;
   sint16   s16LocalSwRmpTranInJ;
   sint16   s16LocalNTr;
   sint32   s32LocalMaxProtBfCord;
   sint32   s32LocalMaxProtDftlBfCord;


   VEMS_vidGET(CoPt_rCnvTq, u16LocalCoPtCnvTq);

   u16LocalCoPtNDftlWhl = PROTDFTLCLC_u16CoPtDftlWhl;
   if (CoPt_facGainFilNProtDftl_C >= 128)
   {
      PROTDFTLCLC_u16CoPtDftlWhl = (uint16)MATHSRV_udtMIN(CoPt_nDftlWhl, 32000);
      PROTDFTLCLC_u32rFilDftlWhlMem =
         (uint32)(PROTDFTLCLC_u16CoPtDftlWhl * 256);
   }
   else
   {
      u8LocalfacGainFilDftl = (uint8)(CoPt_facGainFilNProtDftl_C * 2);
      u16LocalCoPtDftlWhl =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalfacGainFilDftl,
                                        &PROTDFTLCLC_u32rFilDftlWhlMem,
                                        CoPt_nDftlWhl);
      PROTDFTLCLC_u16CoPtDftlWhl =
         (uint16)MATHSRV_udtMIN(u16LocalCoPtDftlWhl, 32000);
   }

   if (PROTDFTLCLC_u16CoPtDftlWhl > u16LocalCoPtNDftlWhl)
   {
      CoPt_facSignNDftlWhl_MP = 1;
      u8LocalfacGainFilProtDftl = CoPt_facGainFilFastProtDftl_C;
   }
   else
   {
      u8LocalfacGainFilProtDftl = CoPt_facGainFilSlowProtDftl_C;
      if (PROTDFTLCLC_u16CoPtDftlWhl < u16LocalCoPtNDftlWhl)
      {
         CoPt_facSignNDftlWhl_MP = -1;
      }
      else
      {
         CoPt_facSignNDftlWhl_MP = 0;
      }
   }

   if (u8LocalfacGainFilProtDftl >= 128)
   {
      PROTDFTLCLC_u16WhlMaxProtDftl =
         (uint16)MATHSRV_udtMIN(CoPt_tqWhlMaxProtDftl, 44000);
      PROTDFTLCLC_u32rFilMaxProtMem =
         (uint32)(PROTDFTLCLC_u16WhlMaxProtDftl * 256);
   }
   else
   {
      u8LocalfacGainFil = (uint8)(u8LocalfacGainFilProtDftl * 2);
      u16LocalWhlMaxProtDftl =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalfacGainFil,
                                        &PROTDFTLCLC_u32rFilMaxProtMem,
                                        CoPt_tqWhlMaxProtDftl);
      PROTDFTLCLC_u16WhlMaxProtDftl =
         (uint16)MATHSRV_udtMIN(u16LocalWhlMaxProtDftl, 44000);
   }

   if (u16LocalCoPtCnvTq != 0)
   {
      u32LocalMaxProtDftlBfCord =
         (uint32)((PROTDFTLCLC_u16WhlMaxProtDftl * 512) / u16LocalCoPtCnvTq);
      CoPt_tqMaxProtDftlBfCord_MP =
         (sint16)MATHSRV_udtMIN(u32LocalMaxProtDftlBfCord, 32000);
   }
   else
   {
      CoPt_tqMaxProtDftlBfCord_MP = 32000;
   }
   /*Block: ContMltpSwRmpTran*/
   if (CoPt_bProtDftlAcv != 0)
   {
      PROTDFTLCLC_u8AcvDeacTr = CoPt_tiAcvTqProtDftl_C;
      u8LocalNewSel = 1;
   }
   else
   {
      PROTDFTLCLC_u8AcvDeacTr = CoPt_tiDeacTqProtDftl_C;
      u8LocalNewSel = 2;
   }

   /*1- Sub-block: MSW_Sel*/
   if (u8LocalNewSel != PROTDFTLCLC_u8ProtAcvSelPrev)
   {
      bLocalSelChg = 1;
      u8LocalProtAcvSelOld = PROTDFTLCLC_u8ProtAcvSelPrev;
   }
   else
   {
      bLocalSelChg = 0;
      u8LocalProtAcvSelOld = PROTDFTLCLC_u8ProtAcvSelOld;
   }

   PROTDFTLCLC_u8ProtAcvSelOld =
      (uint8)MATHSRV_udtCLAMP(u8LocalProtAcvSelOld, 1, 2);

   if (PROTDFTLCLC_u8ProtAcvSelOld == 1)
   {
      s16LocalSwRmpTranInI = CoPt_tqMaxProtDftlBfCord_MP;
   }
   else
   {
      s16LocalSwRmpTranInI = 32000;
   }

   if (u8LocalNewSel == 1)
   {
      s16LocalSwRmpTranInJ = CoPt_tqMaxProtDftlBfCord_MP;
   }
   else
   {
      s16LocalSwRmpTranInJ = 32000;
   }

   /*2- Sub-block: MSW*/
   u8LocalTrSat = (uint8)((PROTDFTLCLC_u8AcvDeacTr * 25) / 32);
   u8LocalTrSat = (uint8)MATHSRV_udtMAX(u8LocalTrSat, 1);
   bLocalActivationMemPrev = PROTDFTLCLC_bActivationMem;

   if (  (bLocalSelChg != 0)
      || (  (u8LocalTrSat != PROTDFTLCLC_u8AcvDeacTrDly)
         && (PROTDFTLCLC_bEtatTmr != 0)))
   {
      PROTDFTLCLC_bActivationMem = 1;
   }
   else
   {
      PROTDFTLCLC_bActivationMem = 0;
   }

   /*3- Sub-block: Tr Calculation*/
   if (PROTDFTLCLC_bActivationMem != 0)
   {
      if (bLocalSelChg != 0)
      {
         u8LocalNTr = u8LocalTrSat;
      }
      else
      {
         s16LocalNTr = (sint16)( (u8LocalTrSat - PROTDFTLCLC_u8AcvDeacTrDly)
                               + (PROTDFTLCLC_u8Counter - 1));
         u8LocalNTr = (uint8)MATHSRV_udtCLAMP(s16LocalNTr, 0, 255);
      }
   }
   else
   {
      u8LocalNTr = u8LocalTrSat;
   }

   /*4- Sub-block: TmrRst*/
   if (  (PROTDFTLCLC_bActivationMem != 0)
      && (bLocalActivationMemPrev == 0))
   {
      PROTDFTLCLC_u8Counter = u8LocalNTr;
   }
   else
   {
      if (PROTDFTLCLC_u8Counter > 0)
      {
         PROTDFTLCLC_u8Counter = (uint8)(PROTDFTLCLC_u8Counter - 1);
      }
   }

   bLocalEtatTmrPrev = PROTDFTLCLC_bEtatTmr;
   if (PROTDFTLCLC_u8Counter == 0)
   {
      PROTDFTLCLC_bEtatTmr = 0;
   }
   else
   {
      PROTDFTLCLC_bEtatTmr = 1;
   }

   if (PROTDFTLCLC_bEtatTmr != 0)
   {
      s32LocalMaxProtDftlBfCord = PROTDFTLCLC_s16MaxProtBfCord;
      s32LocalMaxProtBfCord =
         (sint32)( PROTDFTLCLC_s16MaxProtBfCord
                 + ( (s16LocalSwRmpTranInJ - PROTDFTLCLC_s16MaxProtBfCord)
                   / PROTDFTLCLC_u8Counter));
      /*QAC Msg(4:0585): PROTDFTLCLC_u8Counter is different from zero where
                         PROTDFTLCLC_bEtatTmr = 1*/
   }
   else
   {
      s32LocalMaxProtBfCord = PROTDFTLCLC_s16MaxProtBfCord;
      s32LocalMaxProtDftlBfCord = s16LocalSwRmpTranInJ;
   }

   CoPt_tqEfcMaxProtDftlBfCord =
      (sint16)MATHSRV_udtCLAMP(s32LocalMaxProtDftlBfCord, -32000, 32000);

   PROTDFTLCLC_s16MaxProtBfCord =
      (sint16)MATHSRV_udtCLAMP(s32LocalMaxProtBfCord, -32000, 32000);

   /*Updating previous variables*/
   PROTDFTLCLC_u8ProtAcvSelPrev = u8LocalNewSel;
   PROTDFTLCLC_u8AcvDeacTrDly = u8LocalTrSat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetCouplProtFrein                           */
/* !Description :  Ce bloc détermine le couple de protection contre la        */
/*                 surchauffe freins. Ce couple est fonction du régime moteur */
/*                 et du rapport de boite engagé. Il est filtré et prend la   */
/*                 valeur de 2000 Nm lorsque la protection des freins est     */
/*                 inactive.                                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input boolean Ext_bAcvProtBrk;                                            */
/*  input uint16 CoPt_nEngProtBrkX_A[16];                                     */
/*  input uint8 CoPt_noGearProtBrkY_A[10];                                    */
/*  input uint16 CoPt_tqEfcMaxProtBrk_M[16][10];                              */
/*  input uint8 CoPt_facFilProtBrk_C;                                         */
/*  input sint16 CoPt_tqEfcMaxProtBrk_MP;                                     */
/*  input sint32 PROTDFTLCLC_s32rFilMaxProtBrkMem;                            */
/*  input uint8 CoPt_tiAcvTqProtBrk_C;                                        */
/*  input uint8 CoPt_tiDeacTqProtBrk_C;                                       */
/*  input uint8 PROTDFTLCLC_u8AcvBrkSelPrev;                                  */
/*  input uint8 PROTDFTLCLC_u8ProtAcvBrkSelOld;                               */
/*  input uint8 PROTDFTLCLC_u8AcvDeacBrkTr;                                   */
/*  input boolean PROTDFTLCLC_bActivationMemBrk;                              */
/*  input uint8 PROTDFTLCLC_u8AcvDeacBrkTrDly;                                */
/*  input boolean PROTDFTLCLC_bEtatTmrBrk;                                    */
/*  input uint8 PROTDFTLCLC_u8CounterBrk;                                     */
/*  input sint16 PROTDFTLCLC_s16MaxProtBrk;                                   */
/*  output sint16 CoPt_tqEfcMaxProtBrk_MP;                                    */
/*  output sint32 PROTDFTLCLC_s32rFilMaxProtBrkMem;                           */
/*  output uint8 PROTDFTLCLC_u8AcvDeacBrkTr;                                  */
/*  output uint8 PROTDFTLCLC_u8ProtAcvBrkSelOld;                              */
/*  output boolean PROTDFTLCLC_bActivationMemBrk;                             */
/*  output uint8 PROTDFTLCLC_u8CounterBrk;                                    */
/*  output boolean PROTDFTLCLC_bEtatTmrBrk;                                   */
/*  output sint16 CoPt_tqEfcMaxProtBrk;                                       */
/*  output sint16 PROTDFTLCLC_s16MaxProtBrk;                                  */
/*  output uint8 PROTDFTLCLC_u8AcvBrkSelPrev;                                 */
/*  output uint8 PROTDFTLCLC_u8AcvDeacBrkTrDly;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetCouplProtFrein(void)
{
   boolean bLocalExt_bAcvProtBrk;
   boolean bLocalEtatTmrPrev;
   boolean bLocalSelChg;
   boolean bLocalActBrkMemPrev;
   uint8   u8LocalCoPtEgdGearCordIt;
   uint8   u8LocalCoPtFilProtBrk;
   uint8   u8LocalExtAcvBrkSel;
   uint8   u8LocalTrSat;
   uint8   u8LocalNTr;
   uint8   u8LocalProtAcvBrkSelOld;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalCoPtEfcMaxBrk;
   sint8   s8LocalEgdGearCordIt;
   sint16  s16LocalEfcMaxProtBrkMP;
   sint16  s16LocalEfcMaxProtBrk;
   sint16  s16LocalSwRmpTranInI;
   sint16  s16LocalSwRmpTranInJ;
   sint16  s16LocalNTr;
   sint32  s32LocalEfcMaxProtBrk;
   sint32  s32LocalCoEfcMaxProtBrk;
   sint32  s32LocalMaxProtBfCord;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalEgdGearCordIt);
   VEMS_vidGET(Ext_bAcvProtBrk, bLocalExt_bAcvProtBrk);

   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(CoPt_nEngProtBrkX_A,
                                                    u16LocalEng_nCkFil,
                                                    16);
   s8LocalEgdGearCordIt = (sint8)MATHSRV_udtMAX(s8LocalEgdGearCordIt, -1);
   u8LocalCoPtEgdGearCordIt = (uint8)(s8LocalEgdGearCordIt + 1);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(CoPt_noGearProtBrkY_A,
                                                   u8LocalCoPtEgdGearCordIt,
                                                   10);

   u16LocalCoPtEfcMaxBrk =
      MATHSRV_u16Interp2d(&CoPt_tqEfcMaxProtBrk_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          10);

   s32LocalCoEfcMaxProtBrk = (sint32)(u16LocalCoPtEfcMaxBrk - 32000);
   s16LocalEfcMaxProtBrk =
      (sint16)MATHSRV_udtMIN(s32LocalCoEfcMaxProtBrk, 32767);
   if (CoPt_facFilProtBrk_C >= 128)
   {

      CoPt_tqEfcMaxProtBrk_MP =
         (sint16)MATHSRV_udtMIN(s16LocalEfcMaxProtBrk, 32000);
      PROTDFTLCLC_s32rFilMaxProtBrkMem = (sint32)(CoPt_tqEfcMaxProtBrk_MP
                                                 * 256);
   }
   else
   {
      u8LocalCoPtFilProtBrk = (uint8)(CoPt_facFilProtBrk_C * 2);
      s16LocalEfcMaxProtBrkMP =
         MATHSRV_s16FirstOrderFilterGu8(u8LocalCoPtFilProtBrk,
                                        &PROTDFTLCLC_s32rFilMaxProtBrkMem,
                                        s16LocalEfcMaxProtBrk);
      CoPt_tqEfcMaxProtBrk_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalEfcMaxProtBrkMP, -32000, 32000);
   }

   /*Block: ContMltpSwRmpTran*/
   if (bLocalExt_bAcvProtBrk != 0)
   {
      PROTDFTLCLC_u8AcvDeacBrkTr = CoPt_tiAcvTqProtBrk_C;
      u8LocalExtAcvBrkSel = 1;
   }
   else
   {
      PROTDFTLCLC_u8AcvDeacBrkTr = CoPt_tiDeacTqProtBrk_C;
      u8LocalExtAcvBrkSel = 2;
   }

   /*1- Sub-block: MSW_Sel*/
   if (u8LocalExtAcvBrkSel != PROTDFTLCLC_u8AcvBrkSelPrev)
   {
      bLocalSelChg = 1;
      u8LocalProtAcvBrkSelOld = PROTDFTLCLC_u8AcvBrkSelPrev;
   }
   else
   {
      bLocalSelChg = 0;
      u8LocalProtAcvBrkSelOld = PROTDFTLCLC_u8ProtAcvBrkSelOld;
   }

   PROTDFTLCLC_u8ProtAcvBrkSelOld =
      (uint8)MATHSRV_udtCLAMP(u8LocalProtAcvBrkSelOld, 1, 2);
   if (PROTDFTLCLC_u8ProtAcvBrkSelOld == 1)
   {
      s16LocalSwRmpTranInI = CoPt_tqEfcMaxProtBrk_MP;
   }
   else
   {
      s16LocalSwRmpTranInI = 32000;
   }

   if (u8LocalExtAcvBrkSel == 1)
   {
      s16LocalSwRmpTranInJ = CoPt_tqEfcMaxProtBrk_MP;
   }
   else
   {
      s16LocalSwRmpTranInJ = 32000;
   }

   /*2- Sub-block: MSW*/
   u8LocalTrSat = (uint8)((PROTDFTLCLC_u8AcvDeacBrkTr * 25) / 32);
   u8LocalTrSat = (uint8)MATHSRV_udtMAX(u8LocalTrSat, 1);
   bLocalActBrkMemPrev = PROTDFTLCLC_bActivationMemBrk;

   if (  (bLocalSelChg != 0)
      || (  (u8LocalTrSat != PROTDFTLCLC_u8AcvDeacBrkTrDly)
         && (PROTDFTLCLC_bEtatTmrBrk != 0)))
   {
      PROTDFTLCLC_bActivationMemBrk = 1;
   }
   else
   {
      PROTDFTLCLC_bActivationMemBrk = 0;
   }

   /*3- Sub-block: Tr Calculation*/
   if (PROTDFTLCLC_bActivationMemBrk != 0)
   {
      if (bLocalSelChg != 0)
      {
         u8LocalNTr = u8LocalTrSat;
      }
      else
      {
         s16LocalNTr = (sint16)( (u8LocalTrSat - PROTDFTLCLC_u8AcvDeacBrkTrDly)
                               + (PROTDFTLCLC_u8CounterBrk - 1));
         u8LocalNTr = (uint8)MATHSRV_udtCLAMP(s16LocalNTr, 0, 255);
      }
   }
   else
   {
      u8LocalNTr = u8LocalTrSat;
   }

   /*4- Sub-block: TmrRst*/
   if (  (PROTDFTLCLC_bActivationMemBrk != 0)
      && (bLocalActBrkMemPrev == 0))
   {
      PROTDFTLCLC_u8CounterBrk = u8LocalNTr;
   }
   else
   {
      if (PROTDFTLCLC_u8CounterBrk > 0)
      {
         PROTDFTLCLC_u8CounterBrk = (uint8)(PROTDFTLCLC_u8CounterBrk - 1);
      }
   }

   bLocalEtatTmrPrev = PROTDFTLCLC_bEtatTmrBrk;
   if (PROTDFTLCLC_u8CounterBrk == 0)
   {
      PROTDFTLCLC_bEtatTmrBrk = 0;
   }
   else
   {
      PROTDFTLCLC_bEtatTmrBrk = 1;
   }

   if (PROTDFTLCLC_bEtatTmrBrk != 0)
   {
      s32LocalEfcMaxProtBrk = PROTDFTLCLC_s16MaxProtBrk;
      s32LocalMaxProtBfCord =
         (sint32)( PROTDFTLCLC_s16MaxProtBrk
                 + ( (s16LocalSwRmpTranInJ - PROTDFTLCLC_s16MaxProtBrk)
                   / PROTDFTLCLC_u8CounterBrk));
      /*QAC Msg(4:0585): PROTDFTLCLC_u8CounterBrk is different from zero where
                         PROTDFTLCLC_bEtatTmrBrk = 1*/
   }
   else
   {
      s32LocalMaxProtBfCord = PROTDFTLCLC_s16MaxProtBrk;
      s32LocalEfcMaxProtBrk = s16LocalSwRmpTranInJ;
   }

   CoPt_tqEfcMaxProtBrk =
      (sint16)MATHSRV_udtCLAMP(s32LocalEfcMaxProtBrk, -32000, 32000);

   PROTDFTLCLC_s16MaxProtBrk =
      (sint16)MATHSRV_udtCLAMP(s32LocalMaxProtBfCord, -32000, 32000);

   /*Updating previous variables*/
   PROTDFTLCLC_u8AcvBrkSelPrev = u8LocalExtAcvBrkSel;
   PROTDFTLCLC_u8AcvDeacBrkTrDly = u8LocalTrSat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidCoordCouplLimit                             */
/* !Description :  Ce bloc coordonne les limitations. Le couple               */
/*                 CoPt_tqEfcMaxProtDftl de sortie de la spécification répond */
/*                 au besoin de protection du différentiel et au besoin de    */
/*                 protection contre la surchauffe des freins.                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 TqSys_tqCkEngReal;                                           */
/*  input sint16 CoPt_tqEfcMaxProtDftlBfCord;                                 */
/*  input sint16 CoPt_tqEfcMaxProtBrk;                                        */
/*  input boolean CoPt_bTqStProt_C;                                           */
/*  input sint16 CoPt_tqOfsStProt_C;                                          */
/*  output sint16 CoPt_tqEfcMaxProtDftl;                                      */
/*  output uint8 CoPt_stProt;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidCoordCouplLimit(void)
{
   uint8  u8LocalCoPt_stProt;
   sint16 s16LocalEfcMaxProtDftl;
   sint16 s16LocalTqSys_tqCkEngReal;
   sint32 s32LocalCkEngRealProt;


   VEMS_vidGET(TqSys_tqCkEngReal, s16LocalTqSys_tqCkEngReal);

   s16LocalEfcMaxProtDftl =
      (sint16)MATHSRV_udtMIN(CoPt_tqEfcMaxProtDftlBfCord, CoPt_tqEfcMaxProtBrk);
   s16LocalEfcMaxProtDftl =
      (sint16)MATHSRV_udtCLAMP(s16LocalEfcMaxProtDftl, -32000, 32000);
   VEMS_vidSET(CoPt_tqEfcMaxProtDftl, s16LocalEfcMaxProtDftl);

   if (CoPt_bTqStProt_C != 0)
   {
      s32LocalCkEngRealProt = 2000;
   }
   else
   {
      s32LocalCkEngRealProt =
         (sint32)(s16LocalTqSys_tqCkEngReal + CoPt_tqOfsStProt_C);
   }

   if (s16LocalEfcMaxProtDftl >= s32LocalCkEngRealProt)
   {
      u8LocalCoPt_stProt = 0;
   }
   else
   {
      if (CoPt_tqEfcMaxProtBrk >= CoPt_tqEfcMaxProtDftlBfCord)
      {
         u8LocalCoPt_stProt = 1;
      }
      else
      {
         u8LocalCoPt_stProt = 2;
      }
   }
   VEMS_vidSET(CoPt_stProt, u8LocalCoPt_stProt);
}

/*---------------------------------end of file--------------------------------*/