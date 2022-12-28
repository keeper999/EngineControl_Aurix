/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILDSP                                                  */
/* !Description     : OILDSP Component                                        */
/*                                                                            */
/* !Module          : OILDSP                                                  */
/* !Description     :  FUEL DESORPTION FROM OIL                               */
/*                                                                            */
/* !File            : OILDSP_FCT1.C                                           */
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
/*   1 / OILDSP_vidInitOutput                                                 */
/*   2 / OILDSP_vidInit                                                       */
/*   3 / OILDSP_vidAbsorption                                                 */
/*   4 / OILDSP_vidEnaAbsorption                                              */
/*   5 / OILDSP_vidDesorption                                                 */
/*   6 / OILDSP_vidEnaDesorption                                              */
/*   7 / OILDSP_vidDisableAFACanister                                         */
/*   8 / OILDSP_NVMSRV_vidInit                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5377698 / 03                                        */
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
#include "OILDSP.h"
#include "OILDSP_L.h"
#include "OILDSP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_vidInitOutput                                       */
/* !Description :  initialization of internals.                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean OilSys_EnaOilAbs_TCdn;                                     */
/*  output boolean OilSys_EnaOilDsp_TCdn;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_vidInitOutput(void)
{
   OilSys_EnaOilAbs_TCdn = 0;
   OilSys_EnaOilDsp_TCdn = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_vidInit                                             */
/* !Description :  Initialization of internals and outputs.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 OilDsp_mFuInOilEstim;                                        */
/*  output boolean OilDsp_bMonRunIdcBlbyCnd;                                  */
/*  output boolean OilDsp_bDgoIdcBlbyCnd;                                     */
/*  output uint32 OilDsp_mFuInOilEstimPrev;                                   */
/*  output boolean Blby_bIdcWoutBlbyCnd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_vidInit(void)
{
   /* F00_Init */
   OilDsp_bMonRunIdcBlbyCnd = 0;
   OilDsp_bDgoIdcBlbyCnd    = 0;
   OilDsp_mFuInOilEstimPrev = MATHSRV_udtMIN(OilDsp_mFuInOilEstim, 268435455);
   VEMS_vidSET(Blby_bIdcWoutBlbyCnd, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_vidAbsorption                                       */
/* !Description :  The function must detect the beginning and the end of a    */
/*                 significative desorption phase  of fuel in oil.            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  PTS_R_5377698_005.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILDSP_vidEnaAbsorption();                               */
/*  input sint16 OilDsp_tAbsorbPhaMax_C;                                      */
/*  input sint16 OilDsp_tAbsorbPhaMaxThd_C;                                   */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input boolean OilSys_EnaOilAbs_TCdn;                                      */
/*  output boolean OilSys_EnaOilAbs_TCdn;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_vidAbsorption(void)
{
   /* F01_Absorption */
   sint16 s16LocalExt_tCoMes;
   sint32 s32LocalHysHighTreshold;


   s32LocalHysHighTreshold = OilDsp_tAbsorbPhaMax_C + OilDsp_tAbsorbPhaMaxThd_C;
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   /*Begin Hysteresis*/
   if (s16LocalExt_tCoMes > s32LocalHysHighTreshold)
   {
      OilSys_EnaOilAbs_TCdn = 0;
   }
   else
   {
      if (s16LocalExt_tCoMes <= OilDsp_tAbsorbPhaMax_C)
      {
         OilSys_EnaOilAbs_TCdn = 1;
      }
   }
   /*End Hysteresis*/

   if (OilSys_EnaOilAbs_TCdn != 0)
   {
      OILDSP_vidEnaAbsorption();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_vidEnaAbsorption                                    */
/* !Description :  This funtion calculate estimated mass of fuel in oil.      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint8 OilDsp_facAfs_C;                                              */
/*  input uint16 InjrSys_mFuInjEstim;                                         */
/*  input uint16 OilDsp_mFuInjBurn;                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 OilDsp_tCoMes_A[8];                                           */
/*  input uint8 OilDsp_rFuMassInOil_T[8];                                     */
/*  input uint16 OilDsp_mFuResiAfterCmb;                                      */
/*  input uint8 OilDsp_rFuMassInOil;                                          */
/*  input uint32 OilDsp_mFuInOilEstimPrev;                                    */
/*  input uint32 OilDsp_mFuInOilEstim;                                        */
/*  output boolean OilDsp_bMonRunIdcBlbyCnd;                                  */
/*  output uint16 OilDsp_mFuInjBurn;                                          */
/*  output uint16 OilDsp_mFuResiAfterCmb;                                     */
/*  output uint8 OilDsp_rFuMassInOil;                                         */
/*  output uint32 OilDsp_mFuInOilEstim;                                       */
/*  output uint32 OilDsp_mFuInOilEstimPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_vidEnaAbsorption(void)
{
   uint8  u8LocalExt_tiTDC;
   uint8  u8LocalExt_tCoMes;
   uint16 u16LocalInM_mfAirThrEstim;
   uint16 u16LocalInjrSys_mFuInjEstim;
   uint16 u16LocalCalcPara;
   uint16 u16LocalProd1;
   sint16 s16LocalExt_tCoMes;
   uint32 u32LocalProd1;
   uint32 u32LocalDiff;
   sint32 s32LocalDiff;
   sint32 s32LocalExt_tCoMes;


   OilDsp_bMonRunIdcBlbyCnd = 0;

   VEMS_vidGET(InM_mfAirThrEstim, u16LocalInM_mfAirThrEstim);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

   u32LocalProd1 = (u16LocalInM_mfAirThrEstim * u8LocalExt_tiTDC) * 256;
   u32LocalProd1 = (u32LocalProd1 + 12) / 25;
   u32LocalProd1 = (u32LocalProd1 * 2) / (OilDsp_facAfs_C + 1);
   OilDsp_mFuInjBurn = (uint16)MATHSRV_udtMIN(u32LocalProd1, 65535);

   VEMS_vidGET(InjrSys_mFuInjEstim, u16LocalInjrSys_mFuInjEstim);
   s32LocalDiff = (sint32)(u16LocalInjrSys_mFuInjEstim - OilDsp_mFuInjBurn);
   OilDsp_mFuResiAfterCmb = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);

   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   s32LocalExt_tCoMes = s16LocalExt_tCoMes + 40;
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 255);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(OilDsp_tCoMes_A,
                                                  u8LocalExt_tCoMes,
                                                  8);
   OilDsp_rFuMassInOil = MATHSRV_u8Interp1d(OilDsp_rFuMassInOil_T,
                                            u16LocalCalcPara);

   u16LocalProd1 = (uint16)( ( (OilDsp_mFuResiAfterCmb * OilDsp_rFuMassInOil)
                             + 128)
                           / 255);
   u32LocalDiff = (268435455 - (uint32)u16LocalProd1);
   if (OilDsp_mFuInOilEstimPrev >= u32LocalDiff)
   {
      OilDsp_mFuInOilEstim = 268435455;
   }
   else
   {
      OilDsp_mFuInOilEstim = (OilDsp_mFuInOilEstimPrev + u16LocalProd1);
   }
   OilDsp_mFuInOilEstimPrev = OilDsp_mFuInOilEstim;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_vidDesorption                                       */
/* !Description :  The function detect the start and the end of a             */
/*                 significative desorption phase of fuel in oil              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  PTS_R_5377698_006.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILDSP_vidEnaDesorption();                               */
/*  input sint16 OilDsp_tDspPhaMin_C;                                         */
/*  input sint16 OilDsp_tDspPhaMinThd_C;                                      */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input boolean OilSys_EnaOilDsp_TCdn;                                      */
/*  output boolean OilSys_EnaOilDsp_TCdn;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_vidDesorption(void)
{
   /* F02_Desorption  */
   sint16 s16LocalExt_tCoMes;
   sint32 s32LocalHysHighTreshold;


   s32LocalHysHighTreshold = OilDsp_tDspPhaMin_C + OilDsp_tDspPhaMinThd_C;
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   /*Begin Hysteresis*/
   if (s16LocalExt_tCoMes > s32LocalHysHighTreshold)
   {
      OilSys_EnaOilDsp_TCdn = 1;
   }
   else
   {
      if (s16LocalExt_tCoMes <= OilDsp_tDspPhaMin_C)
      {
         OilSys_EnaOilDsp_TCdn = 0;
      }
   }
   /*End Hysteresis*/

   if (OilSys_EnaOilDsp_TCdn != 0)
   {
      OILDSP_vidEnaDesorption();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_vidEnaDesorption                                    */
/* !Description :  this function calculate  the estimated mass of fuel in oil */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input uint16 OilDsp_tOilMes_A[8];                                         */
/*  input uint8 OilDsp_rFuDspInBlbyCnd_T[8];                                  */
/*  input uint16 OilDsp_nEng_A[8];                                            */
/*  input uint16 OilDsp_rAirLd_A[8];                                          */
/*  input uint8 OilDsp_rMassFlowInBlbyCnd_M[8][8];                            */
/*  input uint8 OilDsp_rCrcPresInPresBlbyCnd_T[8];                            */
/*  input uint32 OilDsp_mFuInOilEstimPrev;                                    */
/*  input uint8 OilDsp_rFuDspInBlbyCnd;                                       */
/*  input uint8 OilDsp_rCrcPresInPresBlbyCnd;                                 */
/*  input uint8 OilDsp_rMassFlowInBlbyCnd;                                    */
/*  input uint32 OilDsp_mFuInOilEstim;                                        */
/*  output boolean OilDsp_bMonRunIdcBlbyCnd;                                  */
/*  output uint8 OilDsp_rFuDspInBlbyCnd;                                      */
/*  output uint8 OilDsp_rMassFlowInBlbyCnd;                                   */
/*  output uint8 OilDsp_rCrcPresInPresBlbyCnd;                                */
/*  output uint32 OilDsp_mFuInOilEstim;                                       */
/*  output uint16 OilDsp_mFuDspBlbyCndEstim;                                  */
/*  output uint32 OilDsp_mFuInOilEstimPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_vidEnaDesorption(void)
{
   /*F01_Ena_Desorption */
   uint16 u16LocalExt_tOilMes;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcPara;
   uint16 u16LocalMul;
   sint16 s16LocalExt_tOilMes;
   uint32 u32LocalMod;
   uint32 u32LocalResult;
   uint32 u32LocalDiv;
   uint32 u32LocalMul;
   uint32 u32LocalDiff;
   uint32 u32LocalXDiv;
   uint32 u32LocalXMod;
   uint32 u32LocalMod1;
   uint32 u32LocalProd;
   uint32 u32LocalRest;
   sint32 s32LocalExt_tOilMes;


   OilDsp_bMonRunIdcBlbyCnd = 1;

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
   s32LocalExt_tOilMes = s16LocalExt_tOilMes + 500;
   u16LocalExt_tOilMes = (uint16)MATHSRV_udtMAX(s32LocalExt_tOilMes, 0);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(OilDsp_tOilMes_A,
                                                   u16LocalExt_tOilMes,
                                                   8);
   OilDsp_rFuDspInBlbyCnd = MATHSRV_u8Interp1d(OilDsp_rFuDspInBlbyCnd_T,
                                               u16LocalCalcPara);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(OilDsp_nEng_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(OilDsp_rAirLd_A,
                                                    u16LocalExt_rAirLd,
                                                    8);
   OilDsp_rMassFlowInBlbyCnd =
      MATHSRV_u8Interp2d(&OilDsp_rMassFlowInBlbyCnd_M[0][0],
                         u16LocalCalcParaX,
                         u16LocalCalcParaY,
                         8);
   OilDsp_rCrcPresInPresBlbyCnd =
      MATHSRV_u8Interp1d(OilDsp_rCrcPresInPresBlbyCnd_T,
                         u16LocalCalcParaX);
   if (OilDsp_mFuInOilEstimPrev != 0)
   {
      u32LocalDiv = UINT32_MAX / OilDsp_mFuInOilEstimPrev;
      u16LocalMul =
         (uint16)(OilDsp_rFuDspInBlbyCnd * OilDsp_rCrcPresInPresBlbyCnd);
      u32LocalMul = (uint32)(u16LocalMul * OilSys_SampleTiMid_SC);
      u32LocalDiff = 65025000 - u32LocalMul;
      if (u32LocalDiff <= u32LocalDiv)
      {
         u32LocalResult =(OilDsp_mFuInOilEstimPrev * u32LocalDiff)/65025000;
      }
      else
      {
         u32LocalDiv = OilDsp_mFuInOilEstimPrev / 65025;
         u32LocalMod = OilDsp_mFuInOilEstimPrev % 65025;
         u32LocalXDiv = UINT32_MAX / u32LocalDiff;
         if (u32LocalDiv > u32LocalXDiv)
         {
            u32LocalXDiv = u32LocalDiff / 1000;
            u32LocalXMod = u32LocalDiff % 1000;
            u32LocalResult = ((u32LocalXDiv * u32LocalDiv)
                             +((u32LocalXMod * u32LocalDiv)/1000));
         }
         else
         {
            u32LocalResult = (u32LocalDiv * u32LocalDiff)/1000;
         }
         u32LocalDiv = u32LocalDiff / 65025;
         u32LocalMod1 = u32LocalDiff % 65025;
         u32LocalResult = u32LocalResult +((u32LocalDiv * u32LocalMod)/1000);
         u32LocalResult = u32LocalResult +((u32LocalMod1 * u32LocalMod)
                                           / 65025000);
      }
   }
   else
   {
      u32LocalResult = 0;
   }
   OilDsp_mFuInOilEstim = MATHSRV_udtMIN(u32LocalResult,
                                         268435455);

   if (  (OilDsp_rFuDspInBlbyCnd != 0)
      && (OilDsp_rMassFlowInBlbyCnd != 0)
      && (OilDsp_rCrcPresInPresBlbyCnd != 0))
   {
      u32LocalProd = (uint32)( OilDsp_rFuDspInBlbyCnd
                             * OilDsp_rCrcPresInPresBlbyCnd);
      u32LocalProd = u32LocalProd * OilDsp_rMassFlowInBlbyCnd;
      u32LocalProd = u32LocalProd * OilSys_SampleTiMid_SC;
      u32LocalDiv = UINT32_MAX / u32LocalProd;
      if (OilDsp_mFuInOilEstimPrev <= u32LocalDiv)
      {
         u32LocalResult = ( (OilDsp_mFuInOilEstimPrev * u32LocalProd)
                          / 16581375);
         u32LocalResult = u32LocalResult / 2000;
      }
      else
      {
         u32LocalDiv = OilDsp_mFuInOilEstimPrev / 16581375;
         u32LocalMod = OilDsp_mFuInOilEstimPrev % 16581375;
         u32LocalXDiv = UINT32_MAX / u32LocalProd;
         if (u32LocalDiv > u32LocalXDiv)
         {
            u32LocalXDiv = u32LocalProd / 2000;
            u32LocalXMod = u32LocalProd % 2000;
            u32LocalResult = ( (u32LocalXDiv * u32LocalDiv)
                             + ((u32LocalXMod * u32LocalDiv) / 2000));
         }
         else
         {
            u32LocalResult = (u32LocalDiv * u32LocalProd) / 2000;
         }
         u32LocalDiv = u32LocalProd / 16581375;
         u32LocalMod1 = u32LocalProd % 16581375;
         u32LocalResult = u32LocalResult +((u32LocalDiv * u32LocalMod) / 2000);
         if (u32LocalMod1 > u32LocalMod)
         {
            u32LocalDiv = u32LocalMod1 / 65025;
            u32LocalMod1 = u32LocalMod1 % 65025;
            u32LocalRest= (u32LocalMod1 * u32LocalMod) / 510000;
            u32LocalRest = u32LocalRest / 65025;
            u32LocalResult = ( (u32LocalDiv * u32LocalMod) / 510000)
                             + u32LocalResult
                             + u32LocalRest;
         }
         else
         {
            u32LocalDiv = u32LocalMod / 65025;
            u32LocalMod = u32LocalMod % 65025;
            u32LocalRest= (u32LocalMod * u32LocalMod1) / 510000;
            u32LocalRest = u32LocalRest / 510000;
            u32LocalResult = ((u32LocalDiv * u32LocalMod1) / 510000)
                             + u32LocalResult
                             + u32LocalRest;
         }
      }
   }
   else
   {
      u32LocalResult = 0;
   }

   OilDsp_mFuDspBlbyCndEstim = (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   OilDsp_mFuInOilEstimPrev = OilDsp_mFuInOilEstim;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_vidDisableAFACanister                               */
/* !Description :  This function produced  2 flags to disable the mixture     */
/*                 adaptation when the ratio between the mass of fuel         */
/*                 evaporated and the fuel injected is high.                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  PTS_R_5377698_007.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 InjrSys_mFuInjEstim;                                         */
/*  input uint16 OilDsp_mFuDspBlbyCndEstim;                                   */
/*  input uint8 OilDsp_rFuDspInj_C;                                           */
/*  input uint8 OilDsp_rFuDspInjThd_C;                                        */
/*  input boolean OilDsp_bDgoIdcBlbyCnd;                                      */
/*  output boolean OilDsp_bDgoIdcBlbyCnd;                                     */
/*  output boolean Blby_bIdcWoutBlbyCnd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_vidDisableAFACanister(void)
{
  /* F03_Disable_AFA_Canister */
   uint16 u16LocalInjrSys_mFuInjEstim;
   uint32 u32LocalDiv;
   uint32 u32LocalHysHighTreshold;
   uint32 u32LocalHysLowTreshold;


   VEMS_vidGET(InjrSys_mFuInjEstim, u16LocalInjrSys_mFuInjEstim);
   if (u16LocalInjrSys_mFuInjEstim != 0)
   {
      u32LocalDiv = (OilDsp_mFuDspBlbyCndEstim * 510);
      u32LocalHysHighTreshold =
      (uint32)( (OilDsp_rFuDspInj_C + OilDsp_rFuDspInjThd_C)
              * u16LocalInjrSys_mFuInjEstim);
      u32LocalHysLowTreshold = OilDsp_rFuDspInj_C * u16LocalInjrSys_mFuInjEstim;
   }
   else
   {
      u32LocalDiv = 0;
      u32LocalHysHighTreshold =
      (uint32)(OilDsp_rFuDspInj_C + OilDsp_rFuDspInjThd_C);
      u32LocalHysLowTreshold = (uint32)OilDsp_rFuDspInj_C;
   }

   /*Begin Hysteresis*/

   if (u32LocalDiv > u32LocalHysHighTreshold)
   {
      OilDsp_bDgoIdcBlbyCnd = 1;
   }
   else
   {
      if (u32LocalDiv <= u32LocalHysLowTreshold)
      {
         OilDsp_bDgoIdcBlbyCnd = 0;
      }
   }
   if (OilDsp_bDgoIdcBlbyCnd != 0)
   {
      VEMS_vidSET(Blby_bIdcWoutBlbyCnd, 0);
   }
   else
   {
      VEMS_vidSET(Blby_bIdcWoutBlbyCnd, 1);
   }
   /*End Hysteresis*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILDSP_NVMSRV_vidInit                                      */
/* !Description :  Initialization of OilDsp_mFuInOilEstim to                  */
/*                 OilDsp_mFuInOilEstimInit_C in EEPROM's re-initialization   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 OilDsp_mFuInOilEstimInit_C;                                  */
/*  output uint32 OilDsp_mFuInOilEstim;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILDSP_NVMSRV_vidInit(void)
{
   /*Default value*/
   OilDsp_mFuInOilEstim = MATHSRV_udtMIN(OilDsp_mFuInOilEstimInit_C, 268435455);
}
/*------------------------------- end of file --------------------------------*/