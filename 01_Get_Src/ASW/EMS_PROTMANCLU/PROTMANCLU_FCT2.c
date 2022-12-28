/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTMANCLU                                              */
/* !Description     : PROTMANCLU Component                                    */
/*                                                                            */
/* !Module          : PROTMANCLU                                              */
/* !Description     : Clutch protection for manual gearbox                    */
/*                                                                            */
/* !File            : PROTMANCLU_FCT2.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / PROTMANCLU_vidCalDelEngPrimshaft                                     */
/*   2 / PROTMANCLU_vidCalcDisPowerLowRat                                     */
/*   3 / PROTMANCLU_vidCalcDelLowMidEnrgy                                     */
/*   4 / PROTMANCLU_vidCalcDelLowHighEngy                                     */
/*   5 / PROTMANCLU_vidCalcCoefConvHeatex                                     */
/*   6 / PROTMANCLU_vidCalcCoefConParm                                        */
/*   7 / PROTMANCLU_vidConvTemperToKelvin                                     */
/*   8 / PROTMANCLU_vidSelectEnergyInject                                     */
/*   9 / PROTMANCLU_vidSelectGearboxRatio                                     */
/*   10 / PROTMANCLU_vidSelectEnergyToInj                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 04687 / 01                                        */
/* !OtherRefs   : 01460_10_03770/1.1                                          */
/* !OtherRefs   : VEMS V02 ECU#056597                                         */
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
#include "PROTMANCLU.h"
#include "PROTMANCLU_l.h"
#include "PROTMANCLU_IM.h"
#include "STD_LIMITS.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalDelEngPrimshaft                           */
/* !Description :  This function calculates the difference of rotation speed  */
/*                 between the primary shaft rotation speed and the engine    */
/*                 rotation speed.                                            */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU8(????);                                   */
/*  extf MATHSRV_u8Interp1d(????);                                            */
/*  input uint16 Ext_nAvrFrntWhl;                                             */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint8 PtLim_noGear_A[7];                                            */
/*  input uint8 PtLim_noGearLo;                                               */
/*  input uint8 PtLim_noGearMid;                                              */
/*  input uint8 PtLim_noGearHi;                                               */
/*  input uint8 PtLim_facRatePtToWhlGear_T[7];                                */
/*  input uint8 PtLim_prm_facRatePtToWhl_MP[3];                               */
/*  output uint8 PtLim_prm_facRatePtToWhl_MP[3];                              */
/*  output uint16 PtLim_nPrimShaftTheLo;                                      */
/*  output uint16 PtLim_nPrimShaftTheMid;                                     */
/*  output uint16 PtLim_nPrimShaftTheHi;                                      */
/*  output uint16 PtLim_nDeltaPrimEngSpdLo;                                   */
/*  output uint16 PtLim_nDeltaPrimEngSpdMid;                                  */
/*  output uint16 PtLim_nDeltaPrimEngSpdHi;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalDelEngPrimshaft(void)
{
   /*F03_01_01_01_Calculation_of_delta_EngPrimshaft_rotation_speed */
   uint8  u8LocalIndex;
   uint16 u16LocalCalcParaX1;
   uint16 u16LocalCalcParaX2;
   uint16 u16LocalCalcParaX3;
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalExt_nAvrFrntWhl;
   uint32 u32LocalDiff1;
   uint32 u32localOut[3];
   /*Msg(2:3132): the array is local, so the size can't be declared as define */


   VEMS_vidGET(Ext_nAvrFrntWhl, u16LocalExt_nAvrFrntWhl);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   /*Production of PtLim_prm_facRatePtToWhl_MP*/

   u16LocalCalcParaX1 = MATHSRV_u16CalcParaIncAryU8(PtLim_noGear_A,
                                                    PtLim_noGearLo,
                                                    7);
   u16LocalCalcParaX2 = MATHSRV_u16CalcParaIncAryU8(PtLim_noGear_A,
                                                    PtLim_noGearMid,
                                                    7);
   u16LocalCalcParaX3 = MATHSRV_u16CalcParaIncAryU8(PtLim_noGear_A,
                                                    PtLim_noGearHi,
                                                    7);
   PtLim_prm_facRatePtToWhl_MP[0] =
      MATHSRV_u8Interp1d(PtLim_facRatePtToWhlGear_T, u16LocalCalcParaX1);
   PtLim_prm_facRatePtToWhl_MP[1] =
      MATHSRV_u8Interp1d(PtLim_facRatePtToWhlGear_T, u16LocalCalcParaX2);
   PtLim_prm_facRatePtToWhl_MP[2] =
      MATHSRV_u8Interp1d(PtLim_facRatePtToWhlGear_T, u16LocalCalcParaX3);

   /* Production of PtLim_nPrimShaftTheLo*/
   for (u8LocalIndex = 0; u8LocalIndex < 3; u8LocalIndex++)
   {
      u32localOut[u8LocalIndex] =
         ( ( (uint32)( u16LocalExt_nAvrFrntWhl
                     * PtLim_prm_facRatePtToWhl_MP[u8LocalIndex])
           + 12)
         / 25);
   }

   PtLim_nPrimShaftTheLo  = (uint16)MATHSRV_udtMIN(u32localOut[0], 32000);
   PtLim_nPrimShaftTheMid = (uint16)MATHSRV_udtMIN(u32localOut[1], 32000);
   PtLim_nPrimShaftTheHi  = (uint16)MATHSRV_udtMIN(u32localOut[2], 32000);

   /* Production of PtLim_nDeltaPrimEngSpdLo*/
   if (u32localOut[0] < (uint32)u16LocalEng_nCkFil)
   {
      u32LocalDiff1 = (uint32)u16LocalEng_nCkFil - u32localOut[0];
      PtLim_nDeltaPrimEngSpdLo = (uint16)MATHSRV_udtMIN(u32LocalDiff1, 32000);
   }
   else
   {
      u32LocalDiff1 = u32localOut[0] - (uint32)u16LocalEng_nCkFil;
      PtLim_nDeltaPrimEngSpdLo = (uint16)MATHSRV_udtMIN(u32LocalDiff1, 32000);
   }

   /* Production of PtLim_nDeltaPrimEngSpdMid*/
   if (u32localOut[1] < (uint32)u16LocalEng_nCkFil)
   {
      u32LocalDiff1 = (uint32)u16LocalEng_nCkFil - u32localOut[1];
      PtLim_nDeltaPrimEngSpdMid = (uint16)MATHSRV_udtMIN(u32LocalDiff1, 32000);
   }
   else
   {
      u32LocalDiff1 = u32localOut[1] - (uint32)u16LocalEng_nCkFil;
      PtLim_nDeltaPrimEngSpdMid = (uint16)MATHSRV_udtMIN(u32LocalDiff1, 32000);
   }

   /* Production of PtLim_nDeltaPrimEngSpdHi*/
   if (u32localOut[2] < (uint32)u16LocalEng_nCkFil)
   {
      u32LocalDiff1 = (uint32)u16LocalEng_nCkFil - u32localOut[2];
      PtLim_nDeltaPrimEngSpdHi = (uint16)MATHSRV_udtMIN(u32LocalDiff1, 32000);
   }
   else
   {
      u32LocalDiff1 = u32localOut[2] - (uint32)u16LocalEng_nCkFil;
      PtLim_nDeltaPrimEngSpdHi = (uint16)MATHSRV_udtMIN(u32LocalDiff1, 32000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalcDisPowerLowRat                           */
/* !Description :  This function calculates the dissipated powers for the     */
/*                 lowest gearbox ratio.                                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PtLim_nDeltaPrimEngSpdLo;                                    */
/*  input uint16 PtLim_tqManCluCf;                                            */
/*  input uint8 PtLim_facEfcClu_C;                                            */
/*  input uint8 PtLim_facEfcWhlClu_C;                                         */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input uint8 PtLim_noGearLo;                                               */
/*  input uint8 PtLim_noGearBX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimBY_A[9];                                  */
/*  input uint16 PtLim_tGearCluEstim;                                         */
/*  input uint16 PtLim_facTqGearB_M[8][9];                                    */
/*  input uint8 PtLim_noGearAX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimAY_A[9];                                  */
/*  input uint16 PtLim_facTqGearA_M[8][9];                                    */
/*  input uint8 PtLim_noGearCX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimCY_A[9];                                  */
/*  input uint8 PtLim_facTqGearC_M[8][9];                                     */
/*  input uint16 PtLim_nPrimShaftTheLo;                                       */
/*  input uint16 PtLim_facTqGearLoA_MP;                                       */
/*  input uint8 PtLim_facTqGearLoC_MP;                                        */
/*  input uint16 PtLim_facTqGearLoB_MP;                                       */
/*  output uint16 PtLim_pwrHeatCluLo;                                         */
/*  output uint16 PtLim_pwrHeatWhlCluLo;                                      */
/*  output uint16 PtLim_facTqGearLoB_MP;                                      */
/*  output uint16 PtLim_facTqGearLoA_MP;                                      */
/*  output uint8 PtLim_facTqGearLoC_MP;                                       */
/*  output uint16 PtLim_pwrHeatGearLo;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalcDisPowerLowRat(void)
{
   /*F03_01_01_02_Calculation_of_dissipated_power_for_the_lowest_ratio */
   uint8  u8LocalPtLim_noGearLo;
   sint8  s8LocalCoPt_noEgdGearCordIt;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;
   uint16 u16LocalMod1;
   uint32 u32LocalMul;
   uint32 u32LocalMul2;
   uint32 u32Localmax;
   uint32 u32LocalMod2;
   uint32 u32LocalSum1;
   uint32 u32LocalSum2;
   sint32 s32LocalMul;


   /*Production of PtLim_pwrHeatCluLo*/
   /* ((PtLim_nDeltaPrimEngSpdLo*PtLim_tqManCluCf)*PtLim_facEfcClu_C)*1047    */
   /*= -----------------------------------------------------------------------*/
                           /*(524288 * 10000)*/
   u32LocalMul = (uint32)(PtLim_nDeltaPrimEngSpdLo * PtLim_tqManCluCf);
   u16LocalMod1 = (uint16)(u32LocalMul % (uint32)256);
   u32LocalMul = u32LocalMul / (uint32)256;
   if (  (PtLim_nDeltaPrimEngSpdLo ==0)
      || (PtLim_tqManCluCf == 0)
      || (PtLim_facEfcClu_C == 0))
   {
      PtLim_pwrHeatCluLo = 0;
   }
   else
   {
      u32LocalMul2 = u32LocalMul * (uint32)PtLim_facEfcClu_C;
      if (u32LocalMul2 > 640943801)
      {
         PtLim_pwrHeatCluLo = 32768;
      }
      else
      {
         if (u32LocalMul2 < 4102165)
         {
            u32LocalMul2 = u32LocalMul2 * 1047;
            u32LocalMod2 = ( (uint32)(u16LocalMod1
                                     * PtLim_facEfcClu_C
                                     * 1047)
                           / (uint32)256);
            PtLim_pwrHeatCluLo =
               (uint16)((u32LocalMul2 + u32LocalMod2 + 10240000) / 20480000);
         }
         else
         {
            u32LocalMod2 = (u16LocalMod1 * PtLim_facEfcClu_C) / 256;
            u32LocalMod2 = ((u32LocalMul2 + u32LocalMod2) % 200);
            u32LocalMul2 = ((u32LocalMul2 + u32LocalMod2) / 200);
            u32LocalMod2 = (u32LocalMod2 * 1047) / 200;
            PtLim_pwrHeatCluLo =
               (uint16)( ((u32LocalMul2 * 1047) + u32LocalMod2  + 51200)
                       / 102400);
         }
      }
   }

   /*Production of PtLim_pwrHeatWhlCluLo*/
   /* ((PtLim_nDeltaPrimEngSpdLo*PtLim_tqManCluCf)*PtLim_facEfcWhlClu_C)*1047 */
   /*= -----------------------------------------------------------------------*/
                           /*(524288 * 10000)*/

   if (  (PtLim_nDeltaPrimEngSpdLo ==0)
      || (PtLim_tqManCluCf == 0)
      || (PtLim_facEfcWhlClu_C == 0))
   {
      PtLim_pwrHeatWhlCluLo = 0;
   }
   else
   {
      u32LocalMul2 = u32LocalMul * PtLim_facEfcWhlClu_C;

      if (u32LocalMul2 > 640943801)
      {
         PtLim_pwrHeatWhlCluLo = 32768;
      }
      else
      {
         if (u32LocalMul2 < 4102165)
         {
            u32LocalMul2 = u32LocalMul2 * 1047;
            u32LocalMod2 = (uint32)( u16LocalMod1
                                   * PtLim_facEfcWhlClu_C
                                   * 1047)
                         / (uint32)256;
            PtLim_pwrHeatWhlCluLo =
               (uint16)((u32LocalMul2 + u32LocalMod2 + 10240000) / 20480000);
         }
         else
         {
            u32LocalMod2 = ( (uint32)( u16LocalMod1
                                   * PtLim_facEfcWhlClu_C)
                           / (uint32) 256);
            u32LocalMod2 = ((u32LocalMul2 + u32LocalMod2) % (uint32)200);
            u32LocalMul2 = ((u32LocalMul2 + u32LocalMod2) / (uint32)200);
            u32LocalMod2 = (u32LocalMod2 * 1047) / 200;
            PtLim_pwrHeatWhlCluLo =
               (uint16)(((u32LocalMul2 * 1047) + u32LocalMod2) / 102400);
         }
      }
   }

   /*Production of PtLim_facTqGearLoB_MP*/
   VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalCoPt_noEgdGearCordIt);
   if (s8LocalCoPt_noEgdGearCordIt == (sint8) 0)
   {
      u8LocalPtLim_noGearLo = 0;
   }
   else
   {
      u8LocalPtLim_noGearLo = (uint8)MATHSRV_udtMIN(PtLim_noGearLo, 7);
   }

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearBX_A,
                                                   u8LocalPtLim_noGearLo,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimBY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&PtLim_facTqGearB_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   PtLim_facTqGearLoB_MP = (uint16)MATHSRV_udtCLAMP(u16LocalInterp2d, 1, 1024);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearAX_A,
                                                   u8LocalPtLim_noGearLo,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimAY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&PtLim_facTqGearA_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   PtLim_facTqGearLoA_MP = (uint16)(u16LocalInterp2d / (uint16)2);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearCX_A,
                                                   u8LocalPtLim_noGearLo,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimCY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   PtLim_facTqGearLoC_MP =
      MATHSRV_u8Interp2d(&PtLim_facTqGearC_M[0][0],
                         u16LocalCalcParaX,
                         u16LocalCalcParaY,
                         9);

   /*Production of PtLim_pwrHeatGearLo*/
   /* num=[(PtLim_nPrimShaftTheLo*1047)/5242880000]*                          */
   /* [(PtLim_nPrimShaftTheLo*PtLim_facTqGearLoB_MP*1047/20000000)            */
   /* +PtLim_tqManCluCf(127-PtLim_facTqGearLoC_MP)+PtLim_facTqGearLoA_MP+1]   */
   if (PtLim_nPrimShaftTheLo == 0)
   {
      PtLim_pwrHeatGearLo = 0;
   }
   else
   {

   /*sum1*/
      u32LocalSum1 = (uint32)(PtLim_facTqGearLoA_MP + 1);
      s32LocalMul  = (sint32)(127 - PtLim_facTqGearLoC_MP);
      s32LocalMul  = (sint32)PtLim_tqManCluCf * s32LocalMul;
      s32LocalMul  = (sint32)u32LocalSum1 + s32LocalMul;
      u32LocalMul2 = (uint32)(PtLim_nPrimShaftTheLo * 1047);

      u16LocalMod1 = (uint16)(u32LocalMul2  % (uint32)64);
      u32LocalMul2 = u32LocalMul2 / (uint32)64;
      u32LocalMul2 = u32LocalMul2 * PtLim_facTqGearLoB_MP;
      u16LocalMod1 =
         (uint16)((uint32)(u16LocalMod1 * PtLim_facTqGearLoB_MP) / (uint32)64);
      u32LocalMul2 = (u32LocalMul2 + u16LocalMod1 + 156250) / 312500;
      s32LocalMul  = s32LocalMul + (sint32)u32LocalMul2;
      u32LocalSum2 = (uint32)MATHSRV_udtABS(s32LocalMul);
      u32Localmax  = UINT32_MAX / (uint32)PtLim_nPrimShaftTheLo;
      if (u32LocalSum2 < u32Localmax)
      {
         u32LocalSum2 = u32LocalSum2 * PtLim_nPrimShaftTheLo;
         u16LocalMod1 = (uint16)(u32LocalSum2 % (uint32)2048);
         u32LocalSum2 = u32LocalSum2 / (uint32)2048;
         u16LocalMod1 = (uint16)((uint32)(u16LocalMod1 * 1047) / (uint32)2048);
         u32LocalSum2 =
            ((u32LocalSum2 * 1047) + u16LocalMod1 + 1280000) / 2560000;
      }
      else
      {
         u16LocalMod1 = (uint16)(u32LocalSum2 % (uint32)8);
         u32LocalSum2 = u32LocalSum2 / (uint32)8;
         u16LocalMod1 = (uint16)((uint32)(u16LocalMod1 * 1047) / (uint32)8);
         u32LocalSum2 = (u32LocalSum2 * 1047) + (uint32)u16LocalMod1;
         u16LocalMod1 = (uint16)(u32LocalSum2 % (uint32)32768);
         u32LocalSum2 = u32LocalSum2 / (uint32)32768;
         u16LocalMod1 =
            (uint16)( (uint32)( u16LocalMod1
                              * PtLim_nPrimShaftTheLo)
                    / (uint32)32768);
         u32LocalSum2 = u32LocalSum2 * PtLim_nPrimShaftTheLo;
         u32LocalSum2 = (u32LocalSum2 + u16LocalMod1 + 10000) / (uint32)20000;
      }

      PtLim_pwrHeatGearLo = (uint16)MATHSRV_udtMIN(u32LocalSum2, 32768);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalcDelLowMidEnrgy                           */
/* !Description :  This function calculates the differences of dissipated     */
/*                 energies between the dissipated energies for the lowest    */
/*                 gearbox ratio and the dissipated energies for the middle   */
/*                 gearbox ratio.                                             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PtLim_nDeltaPrimEngSpdMid;                                   */
/*  input uint16 PtLim_tqManCluCf;                                            */
/*  input uint8 PtLim_facEfcWhlClu_C;                                         */
/*  input uint8 PtLim_facEfcClu_C;                                            */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input uint8 PtLim_noGearMid;                                              */
/*  input uint8 PtLim_noGearBX_A[8];                                          */
/*  input uint8 PROTMANCLU_u8PtLim_noGearMid;                                 */
/*  input uint16 PtLim_tGearCluEstimBY_A[9];                                  */
/*  input uint16 PtLim_tGearCluEstim;                                         */
/*  input uint16 PtLim_facTqGearB_M[8][9];                                    */
/*  input uint8 PtLim_noGearAX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimAY_A[9];                                  */
/*  input uint16 PtLim_facTqGearA_M[8][9];                                    */
/*  input uint8 PtLim_noGearCX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimCY_A[9];                                  */
/*  input uint8 PtLim_facTqGearC_M[8][9];                                     */
/*  input uint16 PtLim_nPrimShaftTheMid;                                      */
/*  input uint16 PtLim_facTqGearMidA_MP;                                      */
/*  input uint8 PtLim_facTqGearMidC_MP;                                       */
/*  input uint16 PtLim_facTqGearMidB_MP;                                      */
/*  input uint16 PtLim_pwrHeatWhlCluLo;                                       */
/*  input uint16 PtLim_pwrHeatCluLo;                                          */
/*  input uint16 PtLim_pwrHeatGearLo;                                         */
/*  output uint8 PROTMANCLU_u8PtLim_noGearMid;                                */
/*  output uint16 PtLim_facTqGearMidB_MP;                                     */
/*  output uint16 PtLim_facTqGearMidA_MP;                                     */
/*  output uint8 PtLim_facTqGearMidC_MP;                                      */
/*  output sint16 PtLim_prm_pwrDeltaLoMid_MP[3];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalcDelLowMidEnrgy(void)
{
   sint8  s8LocalCoPt_noEgdGearCordIt;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;
   uint16 u16LocalMod1;
   uint32 u32LocalMul;
   uint32 u32LocalMu1;
   uint32 u32LocalMul2;
   uint32 u32Localmax;
   uint32 u32LocalMod2;
   uint32 u32LocalOp1;
   uint32 u32LocalOp2;
   uint32 u32LocalOp3;
   uint32 u32LocalSum2;
   sint32 s32LocalMul;
   sint32 s32LocalPwrDeltaLoMid0;
   sint32 s32LocalPwrDeltaLoMid1;
   sint32 s32LocalPwrDeltaLoMid2;


   /*Operation 1*/

   u32LocalMu1  = (uint32)(PtLim_nDeltaPrimEngSpdMid * PtLim_tqManCluCf);
   u16LocalMod1 = (uint16)(u32LocalMu1 % (uint32)256);
   u32LocalMu1  = u32LocalMu1 / (uint32)256;

   if (  (PtLim_nDeltaPrimEngSpdMid ==0)
      || (PtLim_tqManCluCf == 0)
      || (PtLim_facEfcWhlClu_C == 0))
   {
      u32LocalOp1 = 0;
   }
   else
   {
      u32LocalMul = u32LocalMu1 * (uint32)PtLim_facEfcWhlClu_C;
      if (u32LocalMul < 4102165)
      {
         u32LocalMul  = u32LocalMul * 1047;
         u32LocalMod2 = (uint32)( u16LocalMod1
                                * PtLim_facEfcWhlClu_C
                                * 1047)
                      / (uint32)256;
         u32LocalOp1 =
            ((u32LocalMul + u32LocalMod2) + 10240000) / 20480000;
      }
      else
      {
         u32LocalMod2 = (uint32)( u16LocalMod1
                                * PtLim_facEfcWhlClu_C)
                      / (uint32)256;
         u32LocalMod2 = ((u32LocalMul + u32LocalMod2) % 2000);
         u32LocalMul  = ((u32LocalMul + u32LocalMod2) / 2000);
         u32LocalMod2 = (u32LocalMod2 * 1047) / 2000;
         u32LocalOp1 =
            ((u32LocalMul * 1047) + u32LocalMod2  + 5120) / 10240;
      }
   }

   /*Operation 2*/

   if (  (PtLim_nDeltaPrimEngSpdMid ==0)
      || (PtLim_tqManCluCf == 0)
      || (PtLim_facEfcClu_C == 0))
   {
      u32LocalOp2 = 0;
   }
   else
   {
      u32LocalMul = u32LocalMu1 * (uint32)PtLim_facEfcClu_C;
      if (u32LocalMul < 4102165)
      {
         u32LocalMul  = u32LocalMul * 1047;
         u32LocalMod2 = (uint32)( u16LocalMod1
                                * PtLim_facEfcClu_C
                                * 1047)
                      / (uint32) 256;
         u32LocalOp2 =
            ((u32LocalMul + u32LocalMod2) + 10240000) / 20480000;
      }
      else
      {
         u32LocalMod2 = (uint32)( u16LocalMod1
                                * PtLim_facEfcClu_C)
                      / (uint32)256;
         u32LocalMod2 = ((u32LocalMul + u32LocalMod2) % 2000);
         u32LocalMul  = ((u32LocalMul + u32LocalMod2) / 2000);
         u32LocalMod2 = (u32LocalMod2 * 1047) / 2000;
         u32LocalOp2  =
            ((u32LocalMul * 1047) + u32LocalMod2  + 5120) / 10240;
      }
   }
   VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalCoPt_noEgdGearCordIt);
   if(s8LocalCoPt_noEgdGearCordIt == 0)
   {
      PROTMANCLU_u8PtLim_noGearMid = 0;
   }
   else
   {
      PROTMANCLU_u8PtLim_noGearMid = (uint8)MATHSRV_udtMIN(PtLim_noGearMid, 7);
   }

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearBX_A,
                                                   PROTMANCLU_u8PtLim_noGearMid,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimBY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&PtLim_facTqGearB_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   PtLim_facTqGearMidB_MP = (uint16)MATHSRV_udtCLAMP(u16LocalInterp2d, 1, 1024);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearAX_A,
                                                   PROTMANCLU_u8PtLim_noGearMid,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimAY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&PtLim_facTqGearA_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   PtLim_facTqGearMidA_MP = (uint16)(u16LocalInterp2d / 2);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearCX_A,
                                                   PROTMANCLU_u8PtLim_noGearMid,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimCY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   PtLim_facTqGearMidC_MP =
      MATHSRV_u8Interp2d(&PtLim_facTqGearC_M[0][0],
                         u16LocalCalcParaX,
                         u16LocalCalcParaY,
                         9);

   /*Operation 3*/
   if (PtLim_nPrimShaftTheMid == 0)
   {
      u32LocalOp3 = 0;
   }
   else
   {
      u32LocalMul  = (uint32)(PtLim_facTqGearMidA_MP + 1);
      s32LocalMul  = (sint32)(127 - PtLim_facTqGearMidC_MP);
      s32LocalMul  = (sint32)PtLim_tqManCluCf * s32LocalMul;
      s32LocalMul  = (sint32)u32LocalMul + s32LocalMul;
      u32LocalMul2 = (uint32)(PtLim_nPrimShaftTheMid * 1047);

      u16LocalMod1 = (uint16)(u32LocalMul2  % (uint32)64);
      u32LocalMul2 = u32LocalMul2 / (uint32)64;
      u32LocalMul2 = u32LocalMul2 * PtLim_facTqGearMidB_MP;
      u16LocalMod1 =
         (uint16)((uint32)(u16LocalMod1 * PtLim_facTqGearMidB_MP) / (uint32)64);
      u32LocalMul2 = (u32LocalMul2 + u16LocalMod1 + 156250) / 312500;
      s32LocalMul  = s32LocalMul + (sint32)u32LocalMul2;
      u32LocalSum2 = (uint32)MATHSRV_udtABS(s32LocalMul);
      u32Localmax  = (uint32)( SINT32_MAX
                             / (sint32)PtLim_nPrimShaftTheMid);
      if (u32LocalSum2 < u32Localmax)
      {
         u32LocalSum2 = u32LocalSum2 * PtLim_nPrimShaftTheMid;
         u16LocalMod1 = (uint16)(u32LocalSum2 % 2048);
         u32LocalSum2 = u32LocalSum2 / 2048;
         u16LocalMod1 = (uint16)((uint32)(u16LocalMod1 * 1047) / 2048);
         u32LocalOp3  =
            ((u32LocalSum2 * 1047) + u16LocalMod1 + 1280000) / 2560000;
      }
      else
      {
         u16LocalMod1 = (uint16)(u32LocalSum2 % (uint32)8);
         u32LocalSum2 = u32LocalSum2 / (uint32)8;
         u16LocalMod1 = (uint16)((uint32)(u16LocalMod1 * 1047) / (uint32)8);
         u32LocalSum2 = (u32LocalSum2 * 1047) + u16LocalMod1;
         u16LocalMod1 = (uint16)(u32LocalSum2 % (uint32)32768);
         u32LocalSum2 = u32LocalSum2 / (uint32)32768;
         u16LocalMod1 =
            (uint16)((uint32)(u16LocalMod1 * PtLim_nPrimShaftTheMid) / 32768);
         u32LocalSum2 = u32LocalSum2 * PtLim_nPrimShaftTheMid;
         u32LocalOp3  = (u32LocalSum2 + u16LocalMod1 + 10000) / 20000;
      }
   }
   /*Production of PtLim_prm_pwrDeltaLoMid_MP                                 */

   s32LocalPwrDeltaLoMid0 =
      (sint32)(u32LocalOp1 - (uint32)PtLim_pwrHeatWhlCluLo);
   PtLim_prm_pwrDeltaLoMid_MP[0] =
      (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoMid0, -32768, 32767);
   /*Msg(3:3356): This condition is covered in the Unit Test*/
   s32LocalPwrDeltaLoMid1 = (sint32)(u32LocalOp2 - PtLim_pwrHeatCluLo);
   PtLim_prm_pwrDeltaLoMid_MP[1] =
      (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoMid1, -32768, 32767);
   /*Msg(3:3356): This condition is covered in the Unit Test*/
   s32LocalPwrDeltaLoMid2 =(sint32)(u32LocalOp3 - PtLim_pwrHeatGearLo);
   PtLim_prm_pwrDeltaLoMid_MP[2] =
      (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoMid2, -32768, 32767);
   /*Msg(3:3356): This condition is covered in the Unit Test*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalcDelLowHighEngy                           */
/* !Description :  This function calculates the differences of dissipated     */
/*                 energies between the dissipated energies for the lowest    */
/*                 gearbox ratio and the dissipated energies for the highest  */
/*                 gearbox ratio.                                             */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PtLim_nDeltaPrimEngSpdHi;                                    */
/*  input uint16 PtLim_tqManCluCf;                                            */
/*  input uint8 PtLim_facEfcWhlClu_C;                                         */
/*  input uint8 PtLim_facEfcClu_C;                                            */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input uint8 PtLim_noGearMid;                                              */
/*  input uint8 PtLim_noGearBX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimBY_A[9];                                  */
/*  input uint16 PtLim_tGearCluEstim;                                         */
/*  input uint16 PtLim_facTqGearB_M[8][9];                                    */
/*  input uint8 PtLim_noGearAX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimAY_A[9];                                  */
/*  input uint16 PtLim_facTqGearA_M[8][9];                                    */
/*  input uint8 PtLim_noGearCX_A[8];                                          */
/*  input uint16 PtLim_tGearCluEstimCY_A[9];                                  */
/*  input uint8 PtLim_facTqGearC_M[8][9];                                     */
/*  input uint16 PtLim_nPrimShaftTheHi;                                       */
/*  input uint16 PtLim_facTqGearHiA_MP;                                       */
/*  input uint8 PtLim_facTqGearHiC_MP;                                        */
/*  input uint16 PtLim_facTqGearHiB_MP;                                       */
/*  input uint16 PtLim_pwrHeatWhlCluLo;                                       */
/*  input uint16 PtLim_pwrHeatCluLo;                                          */
/*  input uint16 PtLim_pwrHeatGearLo;                                         */
/*  output uint16 PtLim_facTqGearHiB_MP;                                      */
/*  output uint16 PtLim_facTqGearHiA_MP;                                      */
/*  output uint8 PtLim_facTqGearHiC_MP;                                       */
/*  output sint16 PtLim_prm_pwrDeltaLoHi_MP[3];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalcDelLowHighEngy(void)
{
   uint8  u8LocalPtLim_noGearHi;
   sint8  s8LocalCoPt_noEgdGearCordIt;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalInterp2d;
   uint16 u16LocalMod1;
   uint32 u32LocalMul;
   uint32 u32LocalMu1;
   uint32 u32LocalMul2;
   uint32 u32Localmax;
   uint32 u32LocalMod2;
   uint32 u32LocalOp1;
   uint32 u32LocalOp2;
   uint32 u32LocalOp3;
   uint32 u32LocalSum2;
   sint32 s32LocalMul;
   sint32 s32LocalPwrDeltaLoHi0;
   sint32 s32LocalPwrDeltaLoHi1;
   sint32 s32LocalPwrDeltaLoHi2;


   /*Operation 1*/
   u32LocalMu1  = (uint32)(PtLim_nDeltaPrimEngSpdHi * PtLim_tqManCluCf);
   u16LocalMod1 = (uint16)(u32LocalMu1 % (uint32)256);
   u32LocalMu1  = u32LocalMu1 / (uint32)256;

   if (  (PtLim_nDeltaPrimEngSpdHi ==0)
      || (PtLim_tqManCluCf == 0)
      || (PtLim_facEfcWhlClu_C == 0))
   {
      u32LocalOp1 = 0;
   }
   else
   {
      u32LocalMul = u32LocalMu1 * (uint32)PtLim_facEfcWhlClu_C;
      if (u32LocalMul < 4102165)
      {
         u32LocalMul  = u32LocalMul * 1047;
         u32LocalMod2 = (uint32)( u16LocalMod1
                                * PtLim_facEfcWhlClu_C
                                * 1047)
                      / (uint32)256;
         u32LocalOp1 =
            ((u32LocalMul + u32LocalMod2) + 10240000) / 20480000;
      }
      else
      {
         u32LocalMod2 = (uint32)( u16LocalMod1 * PtLim_facEfcWhlClu_C) / 256;
         u32LocalMod2 = ((u32LocalMul + u32LocalMod2) % 2000);
         u32LocalMul  = ((u32LocalMul + u32LocalMod2) / 2000);
         u32LocalMod2 = (u32LocalMod2 * 1047) / 2000;
         u32LocalOp1  =
            ((u32LocalMul * 1047) + u32LocalMod2  + 5120) / 10240;
      }
   }

   /*Operation 2*/

   if (  (PtLim_nDeltaPrimEngSpdHi ==0)
      || (PtLim_tqManCluCf == 0)
      || (PtLim_facEfcClu_C == 0))
   {
      u32LocalOp2 = 0;
   }
   else
   {
      u32LocalMul = u32LocalMu1 * (uint32)PtLim_facEfcClu_C;
      if (u32LocalMul < 4102165)
      {
         u32LocalMul  = u32LocalMul * 1047;
         u32LocalMod2 = (u16LocalMod1 * PtLim_facEfcClu_C * 1047) / 256;
         u32LocalOp2  =
            ((u32LocalMul + u32LocalMod2) + 10240000) / 20480000;
      }
      else
      {
         u32LocalMod2 = (u16LocalMod1 * PtLim_facEfcClu_C) / 256;
         u32LocalMod2 = ((u32LocalMul + u32LocalMod2) % 2000);
         u32LocalMul  = ((u32LocalMul + u32LocalMod2) / 2000);
         u32LocalMod2 = (u32LocalMod2 * 1047) / 2000;
         u32LocalOp2  =
            ((u32LocalMul * 1047) + u32LocalMod2  + 5120) / 10240;
      }
   }

   VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalCoPt_noEgdGearCordIt);
   if (s8LocalCoPt_noEgdGearCordIt == 0)
   {
      u8LocalPtLim_noGearHi = 0;
   }
   else
   {
      u8LocalPtLim_noGearHi = PtLim_noGearMid;
   }

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearBX_A,
                                                   u8LocalPtLim_noGearHi,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimBY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&PtLim_facTqGearB_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   PtLim_facTqGearHiB_MP = (uint16)MATHSRV_udtCLAMP(u16LocalInterp2d, 1, 1024);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearAX_A,
                                                   u8LocalPtLim_noGearHi,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimAY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   u16LocalInterp2d =
      MATHSRV_u16Interp2d(&PtLim_facTqGearA_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   PtLim_facTqGearHiA_MP = (uint16)(u16LocalInterp2d / (uint16)2);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearCX_A,
                                                   u8LocalPtLim_noGearHi,
                                                   8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(PtLim_tGearCluEstimCY_A,
                                                    PtLim_tGearCluEstim,
                                                    9);
   PtLim_facTqGearHiC_MP =
      MATHSRV_u8Interp2d(&PtLim_facTqGearC_M[0][0],
                         u16LocalCalcParaX,
                         u16LocalCalcParaY,
                         9);
   /*Operation 3*/
   if (PtLim_nPrimShaftTheHi == 0)
   {
      u32LocalOp3 = 0;
   }
   else
   {
      u32LocalMul  = (uint32)(PtLim_facTqGearHiA_MP + 1);
      s32LocalMul  = (sint32)(127 - PtLim_facTqGearHiC_MP);
      s32LocalMul  = PtLim_tqManCluCf * s32LocalMul;
      s32LocalMul  = (sint32)u32LocalMul + s32LocalMul;
      u32LocalMul2 = (uint32)(PtLim_nPrimShaftTheHi * 1047);

      u16LocalMod1 = (uint16)(u32LocalMul2  % 64);
      u32LocalMul2 = u32LocalMul2 / 64;
      u32LocalMul2 = u32LocalMul2 * PtLim_facTqGearHiB_MP;
      u16LocalMod1 =
         (uint16)((uint32)(u16LocalMod1 * PtLim_facTqGearHiB_MP) / 64);
      u32LocalMul2 = (u32LocalMul2 + u16LocalMod1 + 156250) / 312500;
      s32LocalMul  = s32LocalMul + (sint32)u32LocalMul2;
      u32LocalSum2 = (uint32)MATHSRV_udtABS(s32LocalMul);
      u32Localmax  = (uint32)(SINT32_MAX / (sint32)PtLim_nPrimShaftTheHi);
      if (u32LocalSum2 < u32Localmax)
      {
         u32LocalSum2 = u32LocalSum2 * PtLim_nPrimShaftTheHi;
         u16LocalMod1 = (uint16)(u32LocalSum2 % 2048);
         u32LocalSum2 = u32LocalSum2 / 2048;
         u16LocalMod1 = (uint16)((uint32)(u16LocalMod1 * 1047) / 2048);
         u32LocalOp3  =
            ((u32LocalSum2 * 1047) + u16LocalMod1 + 1280000) / 2560000;
      }
      else
      {
         u16LocalMod1 = (uint16)(u32LocalSum2 % (uint32)8);
         u32LocalSum2 = u32LocalSum2 / (uint32)8;
         u16LocalMod1 = (uint16)((uint32)(u16LocalMod1 * 1047) / (uint32)8);
         u32LocalSum2 = (u32LocalSum2 * 1047) + u16LocalMod1;
         u16LocalMod1 = (uint16)(u32LocalSum2 % 32768);
         u32LocalSum2 = u32LocalSum2 / 32768;
         u16LocalMod1 =
            (uint16)((uint32)(u16LocalMod1 * PtLim_nPrimShaftTheHi) / 32768);
         u32LocalSum2 = u32LocalSum2 * PtLim_nPrimShaftTheHi;
         u32LocalOp3  = (u32LocalSum2 + u16LocalMod1 + 10000) / 20000;
      }
   }
   /*Production of PtLim_prm_pwrDeltaLoHi_MP                                 */

   s32LocalPwrDeltaLoHi0 = (sint32)(u32LocalOp1 - PtLim_pwrHeatWhlCluLo);
   PtLim_prm_pwrDeltaLoHi_MP[0] =
      (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoHi0, -32768, 32767);
   /*Msg(3:3356): This condition is covered in the Unit Test*/
   s32LocalPwrDeltaLoHi1 = (sint32)(u32LocalOp2 - PtLim_pwrHeatCluLo);
   PtLim_prm_pwrDeltaLoHi_MP[1] =
      (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoHi1, -32768,  32767);
   /*Msg(3:3356): This condition is covered in the Unit Test*/
   s32LocalPwrDeltaLoHi2 =(sint32)(u32LocalOp3 - PtLim_pwrHeatGearLo);
   PtLim_prm_pwrDeltaLoHi_MP[2] =
      (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoHi2, -32768, 32767);
   /*Msg(3:3356): This condition is covered in the Unit Test*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalcCoefConvHeatex                           */
/* !Description :  This function calculates the coefficients of convective    */
/*                 heat exchanges.                                            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PROTMANCLU_vidCalcCoefConParm(argin uint16 u16FirstCalib,*/
/* argin uint16 u16SecondCalib, argin uint8 u8Interp1d)argout uint16 ;        */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 PtLim_nEngSpd_A[7];                                          */
/*  input uint8 PtLim_facThermoExgEngSpd_T[7];                                */
/*  input uint16 PtLim_arWhlCluItAir_C;                                       */
/*  input uint16 PtLim_facTWhlCluItAir_C;                                     */
/*  input uint16 PtLim_facTCluItAir_C;                                        */
/*  input uint16 PtLim_arCluItAir_C;                                          */
/*  input uint16 PtLim_facTCaseItAir_C;                                       */
/*  input uint16 PtLim_arCaseItAir_C;                                         */
/*  input uint16 PtLim_facTGearItAir_C;                                       */
/*  input uint16 PtLim_arGearItAir_C;                                         */
/*  input uint16 PtLim_facTEngItAir_C;                                        */
/*  input uint16 PtLim_arEngItAir_C;                                          */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint16 PtLim_facSpdFanReq_C;                                        */
/*  input uint16 PtLim_spdSpdVehFanReq_A[7];                                  */
/*  input uint16 PROTMANCLU_u16SpdVehFanReq;                                  */
/*  input uint16 PtLim_facTExtAirGear_T[7];                                   */
/*  input uint16 PtLim_facTCaseExtAir_T[7];                                   */
/*  input uint8 PtLim_facTCoMesAirExt_T[7];                                   */
/*  input uint16 PtLim_facTExtAirGear_C;                                      */
/*  input uint16 PtLim_arExtAirGear_C;                                        */
/*  input uint16 PtLim_facTCaseExtAir_C;                                      */
/*  input uint16 PtLim_arCaseExtAir_C;                                        */
/*  input uint16 PtLim_tCoMes;                                                */
/*  input uint16 PtLim_tAirExtMes;                                            */
/*  output uint16 PtLim_facTWhlCluItAir;                                      */
/*  output uint16 PtLim_facTCluItAir;                                         */
/*  output uint16 PtLim_facTCaseItAir;                                        */
/*  output uint16 PtLim_facTGearItAir;                                        */
/*  output uint16 PtLim_facTEngItAir;                                         */
/*  output uint16 PROTMANCLU_u16SpdVehFanReq;                                 */
/*  output uint16 PtLim_facTExtAirGear;                                       */
/*  output uint16 PtLim_facTCaseExtAir;                                       */
/*  output uint16 PtLim_facTCoMesAirExt;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalcCoefConvHeatex(void)
{
   /*F03_01_02_Calculation_of_the_coefficients_of_convective_heat_exchanges */
   uint8  u8localInterp1d;
   uint8  u8LocalThMgt_rSpdFanReq;
   uint8  u8localInterp1dAirExt;
   uint16 u16LocalVeh_spdVeh;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalSum1;
   uint16 u16LocalEng_nCkFil;
   uint16 u16localInterp1dGear;
   uint16 u16localInterp1dExtAir;
   uint16 u16LocalMod1;
   uint32 u32LocalMul;
   uint32 u32LocalSum1;
   sint32 s32LocalDiff;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(PtLim_nEngSpd_A,
                                                    u16LocalEng_nCkFil,
                                                    7);
   u8localInterp1d = MATHSRV_u8Interp1d(PtLim_facThermoExgEngSpd_T,
                                        u16LocalCalcParaX);

   /*Production of PtLim_facTWhlCluItAir*/
   /*PtLim_facThermoExgEngSpd_T*PtLim_arWhlCluItAir_C*PtLim_facTWhlCluItAir_C)*/
   /*=------------------------------------------------------------------------*/
   /*                               65536                                     */
   PtLim_facTWhlCluItAir =
      PROTMANCLU_vidCalcCoefConParm(PtLim_arWhlCluItAir_C,
                                    PtLim_facTWhlCluItAir_C,
                                    u8localInterp1d);

   /*Production of PtLim_facTCluItAir*/
   /*PtLim_facThermoExgEngSpd_T*PtLim_facTCluItAir_C*PtLim_arCluItAir_C)      */
   /*=------------------------------------------------------------------------*/
   /*                               65536                                     */

   PtLim_facTCluItAir =
      PROTMANCLU_vidCalcCoefConParm(PtLim_facTCluItAir_C,
                                    PtLim_arCluItAir_C,
                                    u8localInterp1d);

   /*Production of PtLim_facTCaseItAir*/
   /*PtLim_facThermoExgEngSpd_T*PtLim_facTCaseItAir_C*PtLim_arCaseItAir_C     */
   /*=------------------------------------------------------------------------*/
   /*                               65536                                     */
   PtLim_facTCaseItAir =
      PROTMANCLU_vidCalcCoefConParm(PtLim_facTCaseItAir_C,
                                    PtLim_arCaseItAir_C,
                                    u8localInterp1d);

   /*Production of PtLim_facTGearItAir*/
   /*PtLim_facThermoExgEngSpd_T*PtLim_facTGearItAir_C*PtLim_arGearItAir_C     */
   /*=------------------------------------------------------------------------*/
   /*                               65536                                     */
   PtLim_facTGearItAir =
      PROTMANCLU_vidCalcCoefConParm(PtLim_facTGearItAir_C,
                                    PtLim_arGearItAir_C,
                                    u8localInterp1d);

   /*Production of PtLim_facTEngItAir*/
   /*PtLim_facThermoExgEngSpd_T*PtLim_facTEngItAir_C*PtLim_arEngItAir_C       */
   /*=------------------------------------------------------------------------*/
   /*                               65536                                     */
   PtLim_facTEngItAir =
      PROTMANCLU_vidCalcCoefConParm(PtLim_facTEngItAir_C,
                                    PtLim_arEngItAir_C,
                                    u8localInterp1d);

   VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgt_rSpdFanReq);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u32LocalMul = (uint32)(PtLim_facSpdFanReq_C * u8LocalThMgt_rSpdFanReq);
   u32LocalMul = (u32LocalMul + (uint32)u16LocalVeh_spdVeh) / (uint32)2;

   PROTMANCLU_u16SpdVehFanReq = (uint16)MATHSRV_udtMIN(u32LocalMul, 65535);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(PtLim_spdSpdVehFanReq_A,
                                                    PROTMANCLU_u16SpdVehFanReq,
                                                    7);
   u16localInterp1dGear = MATHSRV_u16Interp1d(PtLim_facTExtAirGear_T,
                                              u16LocalCalcParaX);
   u16localInterp1dExtAir = MATHSRV_u16Interp1d(PtLim_facTCaseExtAir_T,
                                                u16LocalCalcParaX);
   u8localInterp1dAirExt = MATHSRV_u8Interp1d(PtLim_facTCoMesAirExt_T,
                                              u16LocalCalcParaX);

   /*Production of PtLim_facTExtAirGear*/
   /*(PtLim_facTExtAirGear_T+PtLim_facTExtAirGear_C)*PtLim_arExtAirGear_C     */
   /*=------------------------------------------------------------------------*/
   /*                               1024                                      */
   u16LocalSum1 =
      (uint16)((uint32)(u16localInterp1dGear + PtLim_facTExtAirGear_C) / 2);
   u16LocalMod1 =
      (uint16)((uint32)(u16localInterp1dGear + PtLim_facTExtAirGear_C) % 2);
   u32LocalSum1 = (uint32)(u16LocalSum1 * PtLim_arExtAirGear_C);
   u16LocalMod1 = (uint16)((uint32)(u16LocalMod1 * PtLim_arExtAirGear_C) / 2);
   u32LocalSum1 = (u32LocalSum1 + u16LocalMod1 + 256) / 512;
   PtLim_facTExtAirGear = (uint16)MATHSRV_udtMIN(u32LocalSum1, 19200);

   /*Production of PtLim_facTCaseExtAir*/
   /*(PtLim_facTCaseExtAir_T+PtLim_facTCaseExtAir_C)*PtLim_arCaseExtAir_C     */
   /*=------------------------------------------------------------------------*/
   /*                               1024                                      */
   u16LocalSum1 =
      (uint16)((uint32)(u16localInterp1dExtAir + PtLim_facTCaseExtAir_C) / 2);
   u16LocalMod1 =
      (uint16)((uint32)(u16localInterp1dExtAir + PtLim_facTCaseExtAir_C) % 2);
   u32LocalSum1 = (uint32)(u16LocalSum1 * PtLim_arCaseExtAir_C);
   u16LocalMod1 = (uint16)( (uint32)(u16LocalMod1 * PtLim_arCaseExtAir_C) / 2);
   u32LocalSum1 = (u32LocalSum1 + u16LocalMod1 + 256) / 512;
   PtLim_facTCaseExtAir = (uint16)MATHSRV_udtMIN(u32LocalSum1, 19200);

   /*Production of PtLim_facTCoMesAirExt*/
   /* = (128 * PtLim_tAirExtMes   + PtLim_facTCoMesAirExt_T *                 */
   /*(PtLim_tCoMes - PtLim_tAirExtMes)) / 8                                   */

   s32LocalDiff =
      (sint32)((PtLim_tCoMes - PtLim_tAirExtMes) * u8localInterp1dAirExt);
   u32LocalSum1 = (uint32)(128 * PtLim_tAirExtMes );
   s32LocalDiff = ((sint32)u32LocalSum1 + s32LocalDiff) / 8;
   PtLim_facTCoMesAirExt = (uint16)MATHSRV_udtCLAMP(s32LocalDiff, 3568, 20368);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalcCoefConParm                              */
/* !Description :  This generic function calculates the coefficients of       */
/*                 convective heat exchanges.                                 */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
uint16 PROTMANCLU_vidCalcCoefConParm
(
   uint16 u16FirstCalib,
   uint16 u16SecondCalib,
   uint8  u8Interp1d
)
{
   /*F03_01_02_Calculation_of_the_coefficients_of_convective_heat_exchanges */
   uint8  u8LocalMod2;
   uint16 u16LocalMod1;
   uint16 u16LocalOut;
   uint32 u32LocalMul;
   uint32 u32LocalDiv1;

   if (  (u16FirstCalib == 0)
      || (u16SecondCalib == 0)
      || (u8Interp1d == 0))
   {
      u16LocalOut = 0;
   }
   else
   {
      u32LocalMul = (uint32)(u16FirstCalib * u16SecondCalib);
      u32LocalDiv1 = u32LocalMul / 256;
      u16LocalMod1 = (uint16)(u32LocalMul % 256);

      if (u32LocalDiv1 < 4915200)
      {
         u32LocalMul = u32LocalDiv1 * u8Interp1d;
         u8LocalMod2 = (uint8)((uint32)(u16LocalMod1 * u8Interp1d) / 256);
         u32LocalMul = (u32LocalMul + u8LocalMod2 + 128) / 256;
         u16LocalOut = (uint16)MATHSRV_udtMIN(u32LocalMul, 19200);
      }
      else
      {
         u16LocalOut = 19200;

      }
   }
   return u16LocalOut;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidConvTemperToKelvin                           */
/* !Description :  This function  converts the temperatures to Kelvin unit.   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint8 Ext_tAir;                                                     */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_tOilMes;                                                 */
/*  output uint16 PtLim_tAirExtMes;                                           */
/*  output uint16 PtLim_tCoMes;                                               */
/*  output uint16 PtLim_tOilEstim;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidConvTemperToKelvin(void)
{
   /* F03_01_03_Conversion_temperatures_to_Kelvin */
   sint8  s8LocalExt_tAir;
   sint16 s16LocalPtLim_tAirExtMes;
   sint16 s16LocalExt_tCoMes;
   sint16 s16LocalExt_tOilMes;
   sint32 s32LocalPtLim_tOilEstim;
   sint32 s32LocalPtLim_tCoMes;


   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);

   /*Production of PtLim_tAirExtMes*/
   s16LocalPtLim_tAirExtMes = (sint16)(s8LocalExt_tAir + 273);
   PtLim_tAirExtMes = (uint16)MATHSRV_udtMAX(s16LocalPtLim_tAirExtMes, 233);

   /*Production of PtLim_tCoMes*/
   s32LocalPtLim_tCoMes = (sint32)(s16LocalExt_tCoMes + 273);
   PtLim_tCoMes = (uint16)MATHSRV_udtCLAMP(s32LocalPtLim_tCoMes, 233, 487);

   /*Production of PtLim_tOilEstim*/
   s32LocalPtLim_tOilEstim = (sint32)(2 * s16LocalExt_tOilMes) + (sint32)5460;
   s32LocalPtLim_tOilEstim = s32LocalPtLim_tOilEstim / (sint32)5;
   PtLim_tOilEstim =
      (uint16)MATHSRV_udtCLAMP(s32LocalPtLim_tOilEstim, 932, 1948);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidSelectEnergyInject                           */
/* !Description :  This function  selects the energy to inject.               */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidSelectGearboxRatio();                      */
/*  extf argret void PROTMANCLU_vidSelectEnergyToInj();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidSelectEnergyInject(void)
{
   /*F03_02_Selection_of_the_energy_to_inject */

   PROTMANCLU_vidSelectGearboxRatio();
   PROTMANCLU_vidSelectEnergyToInj();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidSelectGearboxRatio                           */
/* !Description :  This function selects a gearbox ratio among three gearbox  */
/*                 ratios.                                                    */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPt_bRvsCord;                                              */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input uint8 PtLim_noGearLo;                                               */
/*  input uint8 PtLim_noGearMid;                                              */
/*  input uint8 PtLim_noGearHi;                                               */
/*  output uint8 PtLim_noCrtSelGear;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidSelectGearboxRatio(void)
{
   /*F03_02_01_Selection_of_a_gearbox_ratio */
   boolean bLocalCoPt_bRvsCord;
   uint8   u8LocalPtLim_noCrtSelGear;
   sint8   s8LocalCoPt_noEgdGearCordIt;


   VEMS_vidGET(CoPt_bRvsCord, bLocalCoPt_bRvsCord);
   VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalCoPt_noEgdGearCordIt);

   if ( (  (bLocalCoPt_bRvsCord == 0)
        && ((sint16)s8LocalCoPt_noEgdGearCordIt == (sint16)PtLim_noGearLo))
      || (bLocalCoPt_bRvsCord != 0))
   {
      u8LocalPtLim_noCrtSelGear = PtLim_noGearLo;
   }
   else
   {
      if ((sint16)s8LocalCoPt_noEgdGearCordIt == (sint16)PtLim_noGearMid)
      {
         u8LocalPtLim_noCrtSelGear = PtLim_noGearMid;
      }
      else
      {
         if ( (  ( (sint16)s8LocalCoPt_noEgdGearCordIt >=
                   (sint16)PtLim_noGearLo)
              && ( (sint16)s8LocalCoPt_noEgdGearCordIt !=
                   (sint16)PtLim_noGearHi))
            || ( (sint16)s8LocalCoPt_noEgdGearCordIt ==
                 (sint16)PtLim_noGearHi))
         {
            u8LocalPtLim_noCrtSelGear = PtLim_noGearHi;
         }
         else
         {
            u8LocalPtLim_noCrtSelGear = PtLim_noGearLo;
         }
      }
   }
   PtLim_noCrtSelGear = (uint8)MATHSRV_udtMIN(u8LocalPtLim_noCrtSelGear, 6);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidSelectEnergyToInj                            */
/* !Description :  This Function selects the dissipated power to inject.      */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 PtLim_stManClu;                                               */
/*  input uint8 PROTMANCLU_u8PtLim_stManCluPrev;                              */
/*  input uint8 PtLim_noGearSel;                                              */
/*  input uint8 PtLim_noSelGlblGearLo_A[3];                                   */
/*  input uint8 PtLim_noCrtSelGear;                                           */
/*  input uint8 PtLim_noGearSelLo_T[3];                                       */
/*  input uint8 PtLim_noSelGlblGearMid_A[3];                                  */
/*  input uint8 PtLim_noGearSelMid_T[3];                                      */
/*  input uint8 PtLim_noSelGlblGearHi_A[3];                                   */
/*  input uint8 PtLim_noGearSelHi_T[3];                                       */
/*  input sint16 PtLim_wDeltaWhlCluLoMid;                                     */
/*  input sint16 PtLim_wDeltaCluLoMid;                                        */
/*  input sint16 PtLim_wDeltaGearLoMid;                                       */
/*  input sint16 PtLim_wDeltaWhlCluLoHi;                                      */
/*  input sint16 PtLim_wDeltaCluLoHi;                                         */
/*  input sint16 PtLim_wDeltaGearLoHi;                                        */
/*  input uint16 PtLim_pwrHeatWhlCluLo;                                       */
/*  input uint16 PtLim_pwrHeatCluLo;                                          */
/*  input uint16 PtLim_pwrHeatGearLo;                                         */
/*  output sint16 PtLim_pwrDeltaWhlCluSel;                                    */
/*  output sint16 PtLim_pwrDeltaCluSel;                                       */
/*  output sint16 PtLim_pwrDeltaGearSel;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidSelectEnergyToInj(void)
{
   /*F03_02_02_Selection_of_energy_to_inject */
   uint8  u8LocalPtLim_pwrDeltaWhlCluSel;
   uint16 u16LocalCalcParaX;


   if (  (PtLim_stManClu == 2)
      && (PROTMANCLU_u8PtLim_stManCluPrev != 2))
   {
      switch(PtLim_noGearSel)
      {
         case 0:
            u16LocalCalcParaX =
               MATHSRV_u16CalcParaIncAryU8(PtLim_noSelGlblGearLo_A,
                                           PtLim_noCrtSelGear,
                                           3);
            u8LocalPtLim_pwrDeltaWhlCluSel =
               MATHSRV_u8Interp1d(PtLim_noGearSelLo_T, u16LocalCalcParaX);
            break;

         case 1:
            u16LocalCalcParaX =
               MATHSRV_u16CalcParaIncAryU8(PtLim_noSelGlblGearMid_A,
                                           PtLim_noCrtSelGear,
                                           3);
            u8LocalPtLim_pwrDeltaWhlCluSel =
               MATHSRV_u8Interp1d(PtLim_noGearSelMid_T, u16LocalCalcParaX);
            break;

         case 2:
            u16LocalCalcParaX =
               MATHSRV_u16CalcParaIncAryU8(PtLim_noSelGlblGearHi_A,
                                           PtLim_noCrtSelGear,
                                           3);
            u8LocalPtLim_pwrDeltaWhlCluSel =
               MATHSRV_u8Interp1d(PtLim_noGearSelHi_T, u16LocalCalcParaX);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            u16LocalCalcParaX =
               MATHSRV_u16CalcParaIncAryU8(PtLim_noSelGlblGearHi_A,
                                           PtLim_noCrtSelGear,
                                           3);
            u8LocalPtLim_pwrDeltaWhlCluSel =
               MATHSRV_u8Interp1d(PtLim_noGearSelHi_T, u16LocalCalcParaX);
         break;
      }

      switch(u8LocalPtLim_pwrDeltaWhlCluSel)
      {
         case 0:
            PtLim_pwrDeltaWhlCluSel = 0;
            PtLim_pwrDeltaCluSel = 0;
            PtLim_pwrDeltaGearSel = 0;
            break;

         case 1:
            PtLim_pwrDeltaWhlCluSel = PtLim_wDeltaWhlCluLoMid;
            PtLim_pwrDeltaCluSel = PtLim_wDeltaCluLoMid;
            PtLim_pwrDeltaGearSel = PtLim_wDeltaGearLoMid;
            break;

         case 2:
            PtLim_pwrDeltaWhlCluSel = PtLim_wDeltaWhlCluLoHi;
            PtLim_pwrDeltaCluSel = PtLim_wDeltaCluLoHi;
            PtLim_pwrDeltaGearSel = PtLim_wDeltaGearLoHi;
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            PtLim_pwrDeltaWhlCluSel = PtLim_wDeltaWhlCluLoHi;
            PtLim_pwrDeltaCluSel = PtLim_wDeltaCluLoHi;
            PtLim_pwrDeltaGearSel = PtLim_wDeltaGearLoHi;
         break;
      }
   }
   else
   {
      PtLim_pwrDeltaWhlCluSel =
         (sint16)MATHSRV_udtMIN(PtLim_pwrHeatWhlCluLo, 32767);
      PtLim_pwrDeltaCluSel =
         (sint16)MATHSRV_udtMIN(PtLim_pwrHeatCluLo, 32767);
      PtLim_pwrDeltaGearSel =
         (sint16)MATHSRV_udtMIN(PtLim_pwrHeatGearLo, 32767);
   }
}

/*---------------------------------End Of File--------------------------------*/