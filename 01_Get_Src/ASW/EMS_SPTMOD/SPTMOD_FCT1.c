/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPTMOD                                                  */
/* !Description     : SPTMOD Component.                                       */
/*                                                                            */
/* !Module          : SPTMOD                                                  */
/* !Description     : Sport Mode Supervisor                                   */
/*                                                                            */
/* !File            : SPTMOD_FCT1.C                                           */
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
/*   1 / SPTMOD_vidInitOutputs                                                */
/*   2 / SPTMOD_vidSuperviseurModeSport                                       */
/*   3 / SPTMOD_vidTorque_Selection                                           */
/*   4 / SPTMOD_vidTrqLimitationFiltering                                     */
/*   5 / SPTMOD_vidRatio_Calculation                                          */
/*   6 / SPTMOD_vidSportMode_State                                            */
/*   7 / SPTMOD_vidEng_State_Treatment                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 04668 / 01                                        */
/* !OtherRefs   : 01460_11_00109 / 01                                         */
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
#include "SPTMOD.h"
#include "SPTMOD_L.h"
#include "SPTMOD_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidInitOutputs                                      */
/* !Description :  Fonction initialisation.                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint8 TqSys_noGearModSpt_A[8];                                      */
/*  input uint16 TqSys_tqEfcMaxGBxModSpt_T[8];                                */
/*  input uint16 TqSys_nEngModSpt_A[16];                                      */
/*  input uint16 TqSys_pExtModSptY_A[5];                                      */
/*  input uint16 TqSys_tqEfcMaxNomModSpt_M[16][5];                            */
/*  input sint16 TqSys_tqEfcModSpt;                                           */
/*  input sint16 TqSys_tqEfcMaxNomModSpt;                                     */
/*  output sint16 TqSys_tqEfcMaxNomModSpt;                                    */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi1Prev1;                           */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi1Prev2;                           */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi2Prev1;                           */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi2Prev2;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi1Rest1;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi1Rest2;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi2Rest1;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi2Rest2;                           */
/*  output sint16 TqDem_tqEfcLimModSptFil1;                                   */
/*  output sint16 TqDem_tqEfcLimModSptFil2;                                   */
/*  output boolean SPTMOD_bHystOutput1;                                       */
/*  output boolean SPTMOD_bHystOutput2;                                       */
/*  output boolean SPTMOD_bExt_ModSptSwitch;                                  */
/*  output boolean Ext_bModSpt;                                               */
/*  output uint16 TqSys_pBoostSndModSpt;                                      */
/*  output uint16 TqSys_pwrEngSndModSpt;                                      */
/*  output uint8 TqSys_rBoostPresSndModSpt;                                   */
/*  output uint8 TqSys_rPwrEngSndModSpt;                                      */
/*  output uint8 TqSys_rTqEfcSndModSpt;                                       */
/*  output uint8 TqSys_stModSpt;                                              */
/*  output uint16 TqSys_tqEfcSndModSpt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidInitOutputs(void)
{
   uint8  u8LocalCoPt_noEgdGearCord;
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalCalcPara;
   uint16 u16LocalTqSys_tqEfcMaxGBxModSpt;
   uint16 u16LocalCalcPara_X;
   uint16 u16LocalCalcPara_Y;
   uint16 u16LocalTqSys_tqEfcMaxNomModSpt;
   uint32 u32LocalMin;
   sint16 s16LocalTqSys_tqEfcLimModSpt;


   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(TqSys_noGearModSpt_A,
                                                  u8LocalCoPt_noEgdGearCord,
                                                  8);
   u16LocalTqSys_tqEfcMaxGBxModSpt =
      MATHSRV_u16Interp1d(TqSys_tqEfcMaxGBxModSpt_T, u16LocalCalcPara);

   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcPara_X = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngModSpt_A,
                                                     u16LocalEng_nCkFil,
                                                     16);
   u16LocalCalcPara_Y = MATHSRV_u16CalcParaIncAryU16(TqSys_pExtModSptY_A,
                                                     u16LocalExt_pAirExtMes,
                                                     5);
   u16LocalTqSys_tqEfcMaxNomModSpt =
      MATHSRV_u16Interp2d(&TqSys_tqEfcMaxNomModSpt_M[0][0],
                          u16LocalCalcPara_X,
                          u16LocalCalcPara_Y,
                          5);

   u32LocalMin = (uint32)MATHSRV_udtMIN(u16LocalTqSys_tqEfcMaxGBxModSpt,
                                        u16LocalTqSys_tqEfcMaxNomModSpt);
   u32LocalMin = (u32LocalMin * 16);
   TqSys_tqEfcMaxNomModSpt = (sint16)MATHSRV_udtMIN(u32LocalMin, 32000);
   s16LocalTqSys_tqEfcLimModSpt =
      (sint16)MATHSRV_udtMIN(TqSys_tqEfcModSpt, TqSys_tqEfcMaxNomModSpt);

   SPTMOD_s32TqEfcLimModSptFi1Prev1 = (sint32)s16LocalTqSys_tqEfcLimModSpt;
   SPTMOD_s32TqEfcLimModSptFi1Prev2 = (sint32)s16LocalTqSys_tqEfcLimModSpt;
   SPTMOD_s32TqEfcLimModSptFi2Prev1 = (sint32)s16LocalTqSys_tqEfcLimModSpt;
   SPTMOD_s32TqEfcLimModSptFi2Prev2 = (sint32)s16LocalTqSys_tqEfcLimModSpt;
   SPTMOD_u32TqEfcLimModSptFi1Rest1 = 0;
   SPTMOD_u32TqEfcLimModSptFi1Rest2 = 0;
   SPTMOD_u32TqEfcLimModSptFi2Rest1 = 0;
   SPTMOD_u32TqEfcLimModSptFi2Rest2 = 0;

   TqDem_tqEfcLimModSptFil1 =
      (sint16)MATHSRV_udtMAX(s16LocalTqSys_tqEfcLimModSpt, -32000);
   TqDem_tqEfcLimModSptFil2 =
      (sint16)MATHSRV_udtMAX(s16LocalTqSys_tqEfcLimModSpt, -32000);

   SPTMOD_bHystOutput1 = 0;
   SPTMOD_bHystOutput2 = 0;
   SPTMOD_bExt_ModSptSwitch = 0;
   VEMS_vidSET(Ext_bModSpt, 0);
   VEMS_vidSET(TqSys_pBoostSndModSpt, 0);
   VEMS_vidSET(TqSys_pwrEngSndModSpt, 0);
   VEMS_vidSET(TqSys_rBoostPresSndModSpt, 0);
   VEMS_vidSET(TqSys_rPwrEngSndModSpt, 0);
   VEMS_vidSET(TqSys_rTqEfcSndModSpt, 0);
   VEMS_vidSET(TqSys_stModSpt, 0);
   VEMS_vidSET(TqSys_tqEfcSndModSpt, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidSuperviseurModeSport                             */
/* !Description :  The function supervisor of the sport mode discusses the    */
/*                 requests coming from the BSI to activate the dynamic mode. */
/*                 It calculates also interfaces: power, torque and boost     */
/*                 pressure to inform the driver.                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPTMOD_vidTorque_Selection();                            */
/*  extf argret void SPTMOD_vidTrqLimitationFiltering();                      */
/*  extf argret void SPTMOD_vidRatio_Calculation();                           */
/*  extf argret void SPTMOD_vidSportMode_State();                             */
/*  extf argret void SPTMOD_vidEng_State_Treatment();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidSuperviseurModeSport(void)
{
   SPTMOD_vidTorque_Selection();
   SPTMOD_vidTrqLimitationFiltering();
   SPTMOD_vidRatio_Calculation();
   SPTMOD_vidSportMode_State();
   SPTMOD_vidEng_State_Treatment();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidTorque_Selection                                 */
/* !Description :  The basic driver torque used for calculations of interfaces*/
/*                 to inform the driver can be selected in different manner.  */
/*                 It dissociates the coordination of xVV, or LVV or idle     */
/*                 governor.                                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input sint16 TqDem_tqCkEfc;                                               */
/*  input sint16 CoVSCtl_tqEfcReq;                                            */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean CoPt_stDrvTra;                                              */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input sint16 TqSys_tqEfcIdl;                                              */
/*  input uint8 TqSys_idxTqEfcModSptSel_C;                                    */
/*  input uint16 TqSys_spdThdIdlModSpt_C;                                     */
/*  input uint8 TqSys_spdHystIdlModSpt_C;                                     */
/*  input boolean SPTMOD_bHystOutput1;                                        */
/*  output boolean SPTMOD_bHystOutput1;                                       */
/*  output sint16 TqSys_tqEfcModSpt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidTorque_Selection(void)
{
   boolean bLocalTqSys_bEngNOnIdl;
   boolean bLocalCoPt_stDrvTra;
   uint16  u16LocalVeh_spdVeh;
   sint16  s16LocalTqDem_tqCkEfc;
   sint16  s16LocalCoVSCtl_tqEfcReq;
   sint16  s16LocalTqSys_tqEfcModSpt1;
   sint16  s16LocalTqSys_tqEfcModSpt2;
   sint16  s16LocalTqSys_tqEfcIdl;
   sint16  s16LocalTqSys_tqEfcMod;
   uint32  u32LocalHysPosHigh;
   sint32  s32LocalHysPosLow;


   VEMS_vidGET(TqDem_tqCkEfc, s16LocalTqDem_tqCkEfc);
   VEMS_vidGET(CoVSCtl_tqEfcReq, s16LocalCoVSCtl_tqEfcReq);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidGET(CoPt_stDrvTra, bLocalCoPt_stDrvTra);
   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);
   VEMS_vidGET(TqSys_tqEfcIdl, s16LocalTqSys_tqEfcIdl);

   switch (TqSys_idxTqEfcModSptSel_C)
   {
   case 0:
      s16LocalTqSys_tqEfcModSpt1 = s16LocalTqDem_tqCkEfc;
      break;

   case 1:
      s16LocalTqSys_tqEfcModSpt1 =
         (sint16)MATHSRV_udtMIN(s16LocalTqDem_tqCkEfc,
                                s16LocalCoVSCtl_tqEfcReq);
      break;

   case 2:
      s16LocalTqSys_tqEfcModSpt1 = s16LocalCoVSCtl_tqEfcReq;
      break;

   default:
      SWFAIL_vidSoftwareErrorHook();
      s16LocalTqSys_tqEfcModSpt1 = s16LocalCoVSCtl_tqEfcReq;
      break;
   }

   u32LocalHysPosHigh = (uint32)(TqSys_spdThdIdlModSpt_C * 8);
   s32LocalHysPosLow =
      (sint32)(TqSys_spdThdIdlModSpt_C - TqSys_spdHystIdlModSpt_C);
   s32LocalHysPosLow = (s32LocalHysPosLow * 8);
   if (u16LocalVeh_spdVeh <= s32LocalHysPosLow)
   {
      SPTMOD_bHystOutput1 = 0;
   }
   else
   {
      if (u16LocalVeh_spdVeh >= u32LocalHysPosHigh)
      {
         SPTMOD_bHystOutput1 = 1;
      }
   }

   if (  (bLocalCoPt_stDrvTra != 0)
      && (SPTMOD_bHystOutput1 != 0)
      && (bLocalTqSys_bEngNOnIdl != 0))
   {
      s16LocalTqSys_tqEfcModSpt2 = s16LocalTqSys_tqEfcIdl;
   }
   else
   {
      s16LocalTqSys_tqEfcModSpt2 = 0;
   }

   s16LocalTqSys_tqEfcMod = (sint16)MATHSRV_udtMAX(s16LocalTqSys_tqEfcModSpt1,
                                                   s16LocalTqSys_tqEfcModSpt2);
   TqSys_tqEfcModSpt = (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqEfcMod,
                                                -32000,
                                                32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidTrqLimitationFiltering                           */
/* !Description :  Interfaces (torque, power, and boost pressure) for posting */
/*                 are calculated with  the driver torque selected and  the   */
/*                 maximum power delivered by the engine.These calculated     */
/*                 informations are filtered to reproduce the response of the */
/*                 engine.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 CoVSCtl_rAccPEng;                                            */
/*  input uint8 TqSys_noGearModSpt_A[8];                                      */
/*  input uint16 TqSys_tqEfcMaxGBxModSpt_T[8];                                */
/*  input uint16 TqSys_nEngModSpt_A[16];                                      */
/*  input uint16 TqSys_pExtModSptY_A[5];                                      */
/*  input uint16 TqSys_tqEfcMaxNomModSpt_M[16][5];                            */
/*  input sint16 TqSys_tqEfcModSpt;                                           */
/*  input sint16 TqSys_tqEfcMaxNomModSpt;                                     */
/*  input uint8 TqSys_tiFilTqEfcModSpt_M[16][5];                              */
/*  input uint8 TqSys_tiFilTqEfcFilModSpt_M[16][5];                           */
/*  input uint16 TqSys_rAccPFootOffModSpt_C;                                  */
/*  input uint8 TqSys_tiDeltaFootOffModSpt_C;                                 */
/*  input uint8 TqSys_tiDeltaFootOffFilModSpt_C;                              */
/*  input sint32 SPTMOD_s32TqEfcLimModSptFi1Prev1;                            */
/*  input uint32 SPTMOD_u32TqEfcLimModSptFi1Rest1;                            */
/*  input sint32 SPTMOD_s32TqEfcLimModSptFi1Prev2;                            */
/*  input uint32 SPTMOD_u32TqEfcLimModSptFi1Rest2;                            */
/*  input uint8 TqSys_facAntiOscModSpt_C;                                     */
/*  input sint32 SPTMOD_s32TqEfcLimModSptFi2Prev1;                            */
/*  input uint32 SPTMOD_u32TqEfcLimModSptFi2Rest1;                            */
/*  input sint32 SPTMOD_s32TqEfcLimModSptFi2Prev2;                            */
/*  input uint32 SPTMOD_u32TqEfcLimModSptFi2Rest2;                            */
/*  input uint8 TqSys_facAntiOscFilModSpt_C;                                  */
/*  output sint16 TqSys_tqEfcMaxNomModSpt;                                    */
/*  output sint16 TqDem_tqEfcLimModSptFil1;                                   */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi1Prev2;                           */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi1Prev1;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi1Rest2;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi1Rest1;                           */
/*  output sint16 TqDem_tqEfcLimModSptFil2;                                   */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi2Prev2;                           */
/*  output sint32 SPTMOD_s32TqEfcLimModSptFi2Prev1;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi2Rest2;                           */
/*  output uint32 SPTMOD_u32TqEfcLimModSptFi2Rest1;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidTrqLimitationFiltering(void)
{
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalTqSys_tiFilTqEfcModSpt;
   uint8   u8LocalTqSys_tiFilTqEfcFilModSpt;
   uint16  u16LocalDScndOrderFilter2_Top;
   uint16  u16LocalCalcPara;
   uint16  u16LocalCalcPara_X;
   uint16  u16LocalCalcPara_Y;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalTqSys_tqEfcMaxGBxModSpt;
   uint16  u16LocalTqSys_tqEfcMaxNomModSpt;
   uint16  u16LocalCoVSCtl_rAccPEng;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalDScndOrderFilter1_Top;
   sint16  s16LocalTqSys_tqEfcLimModSpt;
   sint16  s16LocalDScndOrderFilter2_Top;
   uint32  u32LocalMin;
   uint32  u32LocalTqEfcLimModSptFilRest;
   sint32  s32localTqDem_tqEfcLimModSptFil;
   float32 f32Localparam1;
   float32 f32Localparam2;
   float32 f32Localparam3;
   float32 f32LocalTqDem_tqEfcLimModSptFil;
   float32 f32LocalDScndOrderFilter_Mem1;
   float32 f32LocalDScndOrderFilter_Mem2;
   float32 f32LocalDScndOrderFilter_Denom;
   float32 f32LocalTqEfcLimModSptFilRest;


   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(CoVSCtl_rAccPEng, u16LocalCoVSCtl_rAccPEng);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(TqSys_noGearModSpt_A,
                                                  u8LocalCoPt_noEgdGearCord,
                                                  8);
   u16LocalTqSys_tqEfcMaxGBxModSpt =
      MATHSRV_u16Interp1d(TqSys_tqEfcMaxGBxModSpt_T, u16LocalCalcPara);

   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcPara_X = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngModSpt_A,
                                                     u16LocalEng_nCkFil,
                                                     16);
   u16LocalCalcPara_Y = MATHSRV_u16CalcParaIncAryU16(TqSys_pExtModSptY_A,
                                                     u16LocalExt_pAirExtMes,
                                                     5);
   u16LocalTqSys_tqEfcMaxNomModSpt =
      MATHSRV_u16Interp2d(&TqSys_tqEfcMaxNomModSpt_M[0][0],
                          u16LocalCalcPara_X,
                          u16LocalCalcPara_Y,
                          5);

   u32LocalMin = (uint32)MATHSRV_udtMIN(u16LocalTqSys_tqEfcMaxGBxModSpt,
                                        u16LocalTqSys_tqEfcMaxNomModSpt);
   u32LocalMin = (u32LocalMin * 16);
   TqSys_tqEfcMaxNomModSpt = (sint16)MATHSRV_udtMIN(u32LocalMin, 32000);
   s16LocalTqSys_tqEfcLimModSpt =
      (sint16)MATHSRV_udtMIN(TqSys_tqEfcModSpt, TqSys_tqEfcMaxNomModSpt);

   u8LocalTqSys_tiFilTqEfcModSpt =
      MATHSRV_u8Interp2d(&TqSys_tiFilTqEfcModSpt_M[0][0],
                         u16LocalCalcPara_X,
                         u16LocalCalcPara_Y,
                         5);

   u8LocalTqSys_tiFilTqEfcFilModSpt =
      MATHSRV_u8Interp2d(&TqSys_tiFilTqEfcFilModSpt_M[0][0],
                         u16LocalCalcPara_X,
                         u16LocalCalcPara_Y,
                         5);

   if (u16LocalCoVSCtl_rAccPEng >= TqSys_rAccPFootOffModSpt_C)
   {
      u16LocalDScndOrderFilter1_Top = (uint16)u8LocalTqSys_tiFilTqEfcModSpt;
      s16LocalDScndOrderFilter2_Top = (sint16)u8LocalTqSys_tiFilTqEfcFilModSpt;
   }
   else
   {
      u16LocalDScndOrderFilter1_Top = (uint16)( u8LocalTqSys_tiFilTqEfcModSpt
                                              + TqSys_tiDeltaFootOffModSpt_C);
      s16LocalDScndOrderFilter2_Top =
         (sint16)( u8LocalTqSys_tiFilTqEfcFilModSpt
                 - TqSys_tiDeltaFootOffFilModSpt_C);
   }
   u16LocalDScndOrderFilter2_Top =
      (uint16)MATHSRV_udtMAX(s16LocalDScndOrderFilter2_Top, 0);

   /*Calculation of DSecondOrderFilter*/
   if (SPTMOD_s32TqEfcLimModSptFi1Prev1 >= 0)
   {
      f32LocalDScndOrderFilter_Mem1 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi1Prev1
         + ( (float32)SPTMOD_u32TqEfcLimModSptFi1Rest1
           / (float32)1000000000UL));
   }
   else
   {
      f32LocalDScndOrderFilter_Mem1 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi1Prev1
         - ( (float32)SPTMOD_u32TqEfcLimModSptFi1Rest1
           / (float32)1000000000UL));
   }

   if (SPTMOD_s32TqEfcLimModSptFi1Prev2 >= 0)
   {
      f32LocalDScndOrderFilter_Mem2 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi1Prev2
         + ( (float32)SPTMOD_u32TqEfcLimModSptFi1Rest2
           / (float32)1000000000UL));
   }
   else
   {
      f32LocalDScndOrderFilter_Mem2 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi1Prev2
         - ( (float32)SPTMOD_u32TqEfcLimModSptFi1Rest2
           / (float32)1000000000UL));
   }

   /*Calculation of Denominator*/
   f32LocalDScndOrderFilter_Denom = ( (float32)u16LocalDScndOrderFilter1_Top
                                    * (float32)u16LocalDScndOrderFilter1_Top);
   f32LocalDScndOrderFilter_Denom = ( f32LocalDScndOrderFilter_Denom
                                    * (float32)64);
   f32LocalDScndOrderFilter_Denom = ( f32LocalDScndOrderFilter_Denom
                                    + (float32)( ( u16LocalDScndOrderFilter1_Top
                                                 * TqSys_facAntiOscModSpt_C)
                                               + 64));

   /*Calculation of Term1*/
   f32Localparam1 = ( (float32)TqSys_facAntiOscModSpt_C
                    + ( (float32)u16LocalDScndOrderFilter1_Top
                      * (float32)128));

   f32Localparam1 = (f32Localparam1 * (float32)u16LocalDScndOrderFilter1_Top);
   f32Localparam1 = (f32Localparam1 * f32LocalDScndOrderFilter_Mem1);

   /*Calculation of Term2*/
   f32Localparam2 = ( (float32)u16LocalDScndOrderFilter1_Top
                    * (float32)u16LocalDScndOrderFilter1_Top);
   f32Localparam2 = (f32Localparam2 * (float32)64);
   f32Localparam2 = (f32Localparam2 * f32LocalDScndOrderFilter_Mem2);

   /*Calculation of Term3*/
   f32Localparam3 = ((float32)s16LocalTqSys_tqEfcLimModSpt * (float32)64);

   /*Calculation of filter output*/
   f32LocalTqDem_tqEfcLimModSptFil = ( ( f32Localparam1
                                       + ( f32Localparam3
                                         - f32Localparam2))
                                     / f32LocalDScndOrderFilter_Denom);

   s32localTqDem_tqEfcLimModSptFil = (sint32)f32LocalTqDem_tqEfcLimModSptFil;
   f32LocalTqEfcLimModSptFilRest = ( f32LocalTqDem_tqEfcLimModSptFil
                                   - (float32)s32localTqDem_tqEfcLimModSptFil);
   f32LocalTqEfcLimModSptFilRest = ( f32LocalTqEfcLimModSptFilRest
                                   * (float32)1000000000UL);
   if (f32LocalTqEfcLimModSptFilRest >= (float32)0)
   {
      u32LocalTqEfcLimModSptFilRest = (uint32)f32LocalTqEfcLimModSptFilRest;
   }
   else
   {
      f32LocalTqEfcLimModSptFilRest = ( f32LocalTqEfcLimModSptFilRest
                                      * (float32)(-1));
      u32LocalTqEfcLimModSptFilRest = (uint32)f32LocalTqEfcLimModSptFilRest;
   }

   TqDem_tqEfcLimModSptFil1 =
      (sint16)MATHSRV_udtCLAMP(s32localTqDem_tqEfcLimModSptFil, -32000, 32000);
   /*QAC Msg(3:3356): This statement is covered in unit test*/

   SPTMOD_s32TqEfcLimModSptFi1Prev2 = SPTMOD_s32TqEfcLimModSptFi1Prev1;
   SPTMOD_s32TqEfcLimModSptFi1Prev1 = s32localTqDem_tqEfcLimModSptFil;
   SPTMOD_u32TqEfcLimModSptFi1Rest2 = SPTMOD_u32TqEfcLimModSptFi1Rest1;
   SPTMOD_u32TqEfcLimModSptFi1Rest1 = u32LocalTqEfcLimModSptFilRest;

   /*Calculation of DSecondOrderFilter1*/
   if (SPTMOD_s32TqEfcLimModSptFi2Prev1 >= 0)
   {
      f32LocalDScndOrderFilter_Mem1 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi2Prev1
         + ( (float32)SPTMOD_u32TqEfcLimModSptFi2Rest1
           / (float32)1000000000UL));
   }
   else
   {
      f32LocalDScndOrderFilter_Mem1 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi2Prev1
         - ( (float32)SPTMOD_u32TqEfcLimModSptFi2Rest1
           / (float32)1000000000UL));
   }

   if (SPTMOD_s32TqEfcLimModSptFi2Prev2 >= 0)
   {
      f32LocalDScndOrderFilter_Mem2 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi2Prev2
         + ( (float32)SPTMOD_u32TqEfcLimModSptFi2Rest2
           / (float32)1000000000UL));
   }
   else
   {
      f32LocalDScndOrderFilter_Mem2 =
         ( (float32)SPTMOD_s32TqEfcLimModSptFi2Prev2
         - ( (float32)SPTMOD_u32TqEfcLimModSptFi2Rest2
           / (float32)1000000000UL));
   }

   /*Calculation of Denominator*/
   f32LocalDScndOrderFilter_Denom = ( (float32)u16LocalDScndOrderFilter2_Top
                                    * (float32)u16LocalDScndOrderFilter2_Top);
   f32LocalDScndOrderFilter_Denom = ( f32LocalDScndOrderFilter_Denom
                                    * (float32)64);
   f32LocalDScndOrderFilter_Denom = ( f32LocalDScndOrderFilter_Denom
                                    + (float32)( ( u16LocalDScndOrderFilter2_Top
                                                 * TqSys_facAntiOscFilModSpt_C)
                                               + 64));

   /*Calculation of Term1*/
   f32Localparam1 = ( (float32)TqSys_facAntiOscFilModSpt_C
                    + ( (float32)u16LocalDScndOrderFilter2_Top
                      * (float32)128));

   f32Localparam1 = (f32Localparam1 * (float32)u16LocalDScndOrderFilter2_Top);
   f32Localparam1 = (f32Localparam1 * f32LocalDScndOrderFilter_Mem1);

   /*Calculation of Term2*/
   f32Localparam2 = ( (float32)u16LocalDScndOrderFilter2_Top
                    * (float32)u16LocalDScndOrderFilter2_Top);
   f32Localparam2 = (f32Localparam2 * (float32)64);
   f32Localparam2 = (f32Localparam2 * f32LocalDScndOrderFilter_Mem2);

   /*Calculation of Term3*/
   f32Localparam3 = ((float32)s16LocalTqSys_tqEfcLimModSpt * (float32)64);

   /*Calculation of filter output*/
   f32LocalTqDem_tqEfcLimModSptFil = ( ( f32Localparam1
                                       + ( f32Localparam3
                                         - f32Localparam2))
                                     / f32LocalDScndOrderFilter_Denom);

   s32localTqDem_tqEfcLimModSptFil = (sint32)f32LocalTqDem_tqEfcLimModSptFil;
   f32LocalTqEfcLimModSptFilRest = ( f32LocalTqDem_tqEfcLimModSptFil
                                   - (float32)s32localTqDem_tqEfcLimModSptFil);
   f32LocalTqEfcLimModSptFilRest = ( f32LocalTqEfcLimModSptFilRest
                                   * (float32)1000000000UL);
   if (f32LocalTqEfcLimModSptFilRest >= (float32)0)
   {
      u32LocalTqEfcLimModSptFilRest = (uint32)f32LocalTqEfcLimModSptFilRest;
   }
   else
   {
      f32LocalTqEfcLimModSptFilRest = ( f32LocalTqEfcLimModSptFilRest
                                      * (float32)(-1));
      u32LocalTqEfcLimModSptFilRest = (uint32)f32LocalTqEfcLimModSptFilRest;
   }

   TqDem_tqEfcLimModSptFil2 =
      (sint16)MATHSRV_udtCLAMP(s32localTqDem_tqEfcLimModSptFil, -32000, 32000);
   /*QAC Msg(3:3356): This statement is covered in unit test*/

   SPTMOD_s32TqEfcLimModSptFi2Prev2 = SPTMOD_s32TqEfcLimModSptFi2Prev1;
   SPTMOD_s32TqEfcLimModSptFi2Prev1 = s32localTqDem_tqEfcLimModSptFil;
   SPTMOD_u32TqEfcLimModSptFi2Rest2 = SPTMOD_u32TqEfcLimModSptFi2Rest1;
   SPTMOD_u32TqEfcLimModSptFi2Rest1 = u32LocalTqEfcLimModSptFilRest;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidRatio_Calculation                                */
/* !Description :  Each information for posting are calculated twice, one in  */
/*                 percentage and one in absolute value. The calculation of   */
/*                 the boost pressure takes in consideration the maximum      */
/*                 torque without turbine effect.                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 TqSys_pExtModSptY_A[5];                                      */
/*  input uint16 TqSys_tqEfcMaxModSpt_T[5];                                   */
/*  input sint16 TqDem_tqEfcLimModSptFil2;                                    */
/*  input uint16 TqSys_pwrMaxModSpt_T[5];                                     */
/*  input boolean TqSys_bBoostPresSelModSpt_C;                                */
/*  input uint16 PaDyn_pBoostModSpt;                                          */
/*  input uint8 PaDyn_rBoostModSpt;                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqSys_nEngModSpt_A[16];                                      */
/*  input uint16 TqSys_tqEfcMaxTrbOff_T[16];                                  */
/*  input sint16 TqDem_tqEfcLimModSptFil1;                                    */
/*  input uint16 TqSys_pBoostMaxModSpt_T[5];                                  */
/*  output uint16 TqSys_tqEfcClcModSpt;                                       */
/*  output uint8 TqSys_rTqEfcClcModSpt;                                       */
/*  output uint8 TqSys_rPwrEngClcModSpt;                                      */
/*  output uint16 TqSys_pwrEngClcModSpt;                                      */
/*  output uint16 TqSys_pBoostClcModSpt;                                      */
/*  output uint8 TqSys_rBoostPresClcModSpt;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidRatio_Calculation(void)
{
   uint8  u8LocalPaDyn_rBoostModSpt;
   uint8  u8LocalTqSys_rBoostPresClcModSpt;
   sint8  s8LocalSign;
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalCalcPara;
   uint16 u16LocalTqSys_tqEfcMaxModSpt;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTqSys_pwrMaxModSpt;
   uint16 u16LocalPaDyn_pBoostModSpt;
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalCalcPara1;
   uint16 u16LocalTqSys_pBoostMaxModSpt;
   uint16 u16LocalTqSys_tqEfcMaxTrbOff;
   uint32 u32LocalCalc;
   uint32 u32LocalDiv;
   uint32 u32LocalMod;
   uint32 u32LocalTqSys_rPwrEngClcModSpt;
   uint32 u32LocalTqSys_pwrEngClcModSpt;
   uint32 u32LocalTqSys_pBoostClcModSpt;
   uint32 u32LocalDenABS;
   uint32 u32LocalNumABS;
   uint32 u32LocalTqSys_pwrMaxModSpt;
   sint32 s32LocalTqSys_tqEfcMaxModSpt;
   sint32 s32LocalProduct1;
   sint32 s32LocalProduct5;
   sint32 s32LocalDenom;
   sint32 s32LocalNum;
   sint32 s32LocalDen;
   sint32 s32LocalProduct2;
   sint32 s32LocalProduct3;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TqSys_pExtModSptY_A,
                                                   u16LocalExt_pAirExtMes,
                                                   5);
   u16LocalTqSys_tqEfcMaxModSpt = MATHSRV_u16Interp1d(TqSys_tqEfcMaxModSpt_T,
                                                      u16LocalCalcPara);

   /*Production of TqSys_tqEfcClcModSpt*/
   if (TqDem_tqEfcLimModSptFil2 < 0)
   {
      s32LocalProduct5 = 0;
   }
   else
   {
      s32LocalTqSys_tqEfcMaxModSpt = (sint32)( u16LocalTqSys_tqEfcMaxModSpt
                                             * 16);
      if (TqDem_tqEfcLimModSptFil2 > s32LocalTqSys_tqEfcMaxModSpt)
      {
         s32LocalProduct5 = (sint32)u16LocalTqSys_tqEfcMaxModSpt;
      }
      else
      {
         s32LocalProduct5 = (sint32)((TqDem_tqEfcLimModSptFil2 + 8) / 16);
      }
   }
   TqSys_tqEfcClcModSpt = (uint16)MATHSRV_udtMIN(s32LocalProduct5, 2000);

   /*Production of TqSys_rTqEfcClcModSpt*/
   if (u16LocalTqSys_tqEfcMaxModSpt != 0)
   {
      s32LocalProduct1 = (sint32)(TqDem_tqEfcLimModSptFil2 * 25);
      s32LocalDenom = (sint32)(u16LocalTqSys_tqEfcMaxModSpt * 2);
      if (s32LocalProduct1 < 0)
      {
         s32LocalProduct1 = (s32LocalProduct1 - (s32LocalDenom / 2));
      }
      else
      {
         s32LocalProduct1 = (s32LocalProduct1 + (s32LocalDenom / 2));
      }
      s32LocalProduct1 = (s32LocalProduct1 / s32LocalDenom);

      /*DetectSat*/
      if (s32LocalProduct1 < 0)
      {
         s32LocalProduct1 = 0;
      }
      else
      {
         if (s32LocalProduct1 > 200)
         {
            s32LocalProduct1 = 200;
         }
      }
   }
   else
   {
      if (TqDem_tqEfcLimModSptFil2 >= 0)
      {
         s32LocalProduct1 = 200;
      }
      else
      {
         s32LocalProduct1 = 0;
      }
   }
   TqSys_rTqEfcClcModSpt = (uint8)s32LocalProduct1;

   /*Production of TqSys_rPwrEngClcModSpt and TqSys_pwrEngClcModSpt*/
   u16LocalTqSys_pwrMaxModSpt = MATHSRV_u16Interp1d(TqSys_pwrMaxModSpt_T,
                                                    u16LocalCalcPara);
   if (u16LocalTqSys_pwrMaxModSpt != 0)
   {
      if (TqDem_tqEfcLimModSptFil2 > 0)
      {
         /*Production of TqSys_rPwrEngClcModSpt*/
         u32LocalCalc = (uint32)( (uint16)TqDem_tqEfcLimModSptFil2
                                  * u16LocalExt_nEng);
         u32LocalDiv = (u32LocalCalc / u16LocalTqSys_pwrMaxModSpt);
         u32LocalMod = (u32LocalCalc % u16LocalTqSys_pwrMaxModSpt);
         /*3558382 = MAX_U32 / 1207*/
         if (u32LocalDiv > 3558382UL)
         {
            u32LocalDiv = (u32LocalDiv / 1000);
            u32LocalDiv = (u32LocalDiv * 1207);
            u32LocalMod = (u32LocalMod * 1207);
            u32LocalMod = (u32LocalMod / 1000);
            u32LocalMod = (u32LocalMod / u16LocalTqSys_pwrMaxModSpt);
            u32LocalTqSys_rPwrEngClcModSpt = (u32LocalDiv + u32LocalMod);
            u32LocalTqSys_rPwrEngClcModSpt = ( ( u32LocalTqSys_rPwrEngClcModSpt
                                               + 339)
                                             / 678);
         }
         else
         {
            u32LocalDiv = (u32LocalDiv * 1207);
            u32LocalMod = (u32LocalMod * 1207);
            u32LocalMod = (u32LocalMod / u16LocalTqSys_pwrMaxModSpt);
            u32LocalTqSys_rPwrEngClcModSpt = (u32LocalDiv + u32LocalMod);
            u32LocalTqSys_rPwrEngClcModSpt = ( ( u32LocalTqSys_rPwrEngClcModSpt
                                               + 339000)
                                             / 678000);
         }
         if (u32LocalTqSys_rPwrEngClcModSpt > 200)
         {
            u32LocalTqSys_rPwrEngClcModSpt = 200;
         }

         /*Production of TqSys_pwrEngClcModSpt*/
         if (u32LocalCalc > 3558382UL)
         {
            u32LocalDiv = (u32LocalCalc / 100000UL);
            u32LocalMod = (u32LocalCalc % 100000UL);
            u32LocalTqSys_pwrEngClcModSpt = (u32LocalMod * 1207);
            u32LocalTqSys_pwrEngClcModSpt = ( ( u32LocalTqSys_pwrEngClcModSpt
                                              + 50000)
                                            / 100000UL);
            u32LocalTqSys_pwrEngClcModSpt = ( u32LocalTqSys_pwrEngClcModSpt
                                            + (u32LocalDiv * 1207));
            u32LocalTqSys_pwrEngClcModSpt = ( ( u32LocalTqSys_pwrEngClcModSpt
                                              + 339)
                                            / 678);
         }
         else
         {
            u32LocalTqSys_pwrEngClcModSpt = (u32LocalCalc * 1207);
            u32LocalTqSys_pwrEngClcModSpt = ( ( u32LocalTqSys_pwrEngClcModSpt
                                              + 339)
                                            / 678);
            u32LocalTqSys_pwrEngClcModSpt = ( ( u32LocalTqSys_pwrEngClcModSpt
                                              + 50000)
                                            / 100000UL);
         }
         u32LocalTqSys_pwrMaxModSpt = (uint32)(u16LocalTqSys_pwrMaxModSpt * 2);
         if (u32LocalTqSys_pwrEngClcModSpt > u32LocalTqSys_pwrMaxModSpt)
         {
            u32LocalTqSys_pwrEngClcModSpt = (uint32)( u16LocalTqSys_pwrMaxModSpt
                                                    * 2);
         }
      }
      else
      {
         u32LocalTqSys_rPwrEngClcModSpt = 0;
         u32LocalTqSys_pwrEngClcModSpt = 0;
      }
   }
   else
   {
      u32LocalTqSys_pwrEngClcModSpt = 0;
      if (TqDem_tqEfcLimModSptFil2 > 0)
      {
         u32LocalTqSys_rPwrEngClcModSpt = 200;
      }
      else
      {
         u32LocalTqSys_rPwrEngClcModSpt = 0;
      }
   }
   TqSys_rPwrEngClcModSpt = (uint8)u32LocalTqSys_rPwrEngClcModSpt;
   TqSys_pwrEngClcModSpt = (uint16)MATHSRV_udtMIN(u32LocalTqSys_pwrEngClcModSpt,
                                                  800);

   /*Production of TqSys_pBoostClcModSpt and TqSys_rBoostPresClcModSpt*/
   if (TqSys_bBoostPresSelModSpt_C != 0)
   {
      VEMS_vidGET(PaDyn_pBoostModSpt, u16LocalPaDyn_pBoostModSpt);
      u32LocalTqSys_pBoostClcModSpt = (uint32)u16LocalPaDyn_pBoostModSpt;
      VEMS_vidGET(PaDyn_rBoostModSpt, u8LocalPaDyn_rBoostModSpt);
      u8LocalTqSys_rBoostPresClcModSpt = u8LocalPaDyn_rBoostModSpt;
   }
   else
   {
      VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
      u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
      u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngModSpt_A,
                                                       u16LocalEng_nCkFil,
                                                       16);
      u16LocalTqSys_tqEfcMaxTrbOff = MATHSRV_u16Interp1d(TqSys_tqEfcMaxTrbOff_T,
                                                         u16LocalCalcPara1);
      s32LocalDen = (sint32)( u16LocalTqSys_tqEfcMaxModSpt
                            - u16LocalTqSys_tqEfcMaxTrbOff);
      s32LocalDenom = (s32LocalDen * 16);

      s32LocalNum = (sint32)( TqDem_tqEfcLimModSptFil1
                            - ( u16LocalTqSys_tqEfcMaxTrbOff
                              * 16));
      u16LocalTqSys_pBoostMaxModSpt =
         MATHSRV_u16Interp1d(TqSys_pBoostMaxModSpt_T, u16LocalCalcPara);

      if (s32LocalDenom != 0)
      {
         /*Sign calculation*/
         if (s32LocalNum >= 0)
         {
            s8LocalSign = 1;
         }
         else
         {
            s8LocalSign = -1;
         }
         if (s32LocalDenom < 0)
         {
            s8LocalSign = (sint8)(s8LocalSign * (-1));
         }

         if (s8LocalSign < 0)
         {
            u32LocalTqSys_pBoostClcModSpt = 0;
            u8LocalTqSys_rBoostPresClcModSpt = 0;
         }
         else
         {
            s32LocalProduct2 = (s32LocalDen * 2);
            s32LocalProduct3 = (s32LocalNum * 25);
            s32LocalProduct3 = (s32LocalProduct3 / s32LocalProduct2);
            /*QAC Msg(2:0584): s32LocalProduct2 never take zero following
            this case*/
            if (s32LocalProduct3 > 200)
            {
               u8LocalTqSys_rBoostPresClcModSpt = 200;
            }
            else
            {
               u8LocalTqSys_rBoostPresClcModSpt = (uint8)s32LocalProduct3;
            }

            u32LocalDenABS = (uint32)MATHSRV_udtABS(s32LocalDenom);
            u32LocalNumABS = (uint32)MATHSRV_udtABS(s32LocalNum);
            if (u16LocalTqSys_pBoostMaxModSpt != 0)
            {
               u32LocalCalc = ( 4294967295UL
                              / (uint32)u16LocalTqSys_pBoostMaxModSpt);
               if (u32LocalNumABS < u32LocalCalc)
               {
                  u32LocalTqSys_pBoostClcModSpt =
                     (u32LocalNumABS * u16LocalTqSys_pBoostMaxModSpt);
                  u32LocalTqSys_pBoostClcModSpt =
                     (u32LocalTqSys_pBoostClcModSpt / u32LocalDenABS);
               }
               else
               {
                  u32LocalDiv = (u32LocalNumABS / u32LocalDenABS);
                  u32LocalMod = (u32LocalNumABS % u32LocalDenABS);
                  if (u32LocalMod < u32LocalCalc)
                  {
                     u32LocalCalc = ( u32LocalMod
                                    * u16LocalTqSys_pBoostMaxModSpt);
                     u32LocalCalc = (u32LocalCalc / u32LocalDenABS);
                     u32LocalTqSys_pBoostClcModSpt =
                        ( u32LocalCalc
                        + ( u32LocalDiv
                          * u16LocalTqSys_pBoostMaxModSpt));
                  }
                  else
                  {
                     u32LocalCalc = (u32LocalMod / 16);
                     u32LocalCalc = ( u32LocalCalc
                                    * u16LocalTqSys_pBoostMaxModSpt);
                     u32LocalCalc = (u32LocalCalc / u32LocalDenABS);
                     u32LocalCalc = (u32LocalCalc * 16);
                     u32LocalTqSys_pBoostClcModSpt = ( u32LocalDiv
                                                     + u32LocalCalc);
                  }
               }
            }
            else
            {
               u32LocalTqSys_pBoostClcModSpt = 0;
            }
            if (u32LocalTqSys_pBoostClcModSpt > u16LocalTqSys_pBoostMaxModSpt)
            {
               u32LocalTqSys_pBoostClcModSpt =
                  (uint32)u16LocalTqSys_pBoostMaxModSpt;
            }
         }
      }
      else
      {
         if (s32LocalNum > 0)
         {
            u32LocalTqSys_pBoostClcModSpt =
               (uint32)u16LocalTqSys_pBoostMaxModSpt;
            u8LocalTqSys_rBoostPresClcModSpt = 200;
         }
         else
         {
            u32LocalTqSys_pBoostClcModSpt = 0;
            u8LocalTqSys_rBoostPresClcModSpt = 0;
         }
      }
   }
   TqSys_pBoostClcModSpt =
      (uint16)MATHSRV_udtMIN(u32LocalTqSys_pBoostClcModSpt, 3000);
   TqSys_rBoostPresClcModSpt =
      (uint8)MATHSRV_udtMIN(u8LocalTqSys_rBoostPresClcModSpt, 200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidSportMode_State                                  */
/* !Description :  The overall activation of the sport mode depends on several*/
/*                 parameters, the request coming from the BSI and its        */
/*                 diagnostic associated are taken into account.              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqCkEfcModSptLim;                                     */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input boolean CoCha_bTqReqASR;                                            */
/*  input boolean CoCha_bTqReqMSR;                                            */
/*  input boolean Ext_bModSptReq;                                             */
/*  input sint16 TqSys_tqEfcMaxNomModSpt;                                     */
/*  input uint16 TqSys_nEngModSpt_A[16];                                      */
/*  input uint8 TqSys_rPrfNomModSpt_T[16];                                    */
/*  input uint8 TqSys_rHystPrfNomModSpt_C;                                    */
/*  input boolean TqSys_bChaRegSelModSpt_C;                                   */
/*  input boolean SPTMOD_bHystOutput2;                                        */
/*  input boolean SPTMOD_bExt_ModSptSwitch;                                   */
/*  output boolean SPTMOD_bHystOutput2;                                       */
/*  output boolean SPTMOD_bExt_ModSptSwitch;                                  */
/*  output boolean Ext_bModSpt;                                               */
/*  output uint8 TqSys_stModSpt;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidSportMode_State(void)
{
   boolean bLocalCoCha_bTqReqASR;
   boolean bLocalCoCha_bTqReqMSR;
   boolean bLocalExt_bModSptReq;
   boolean bLocalFRM_bInhModSptReq;
   boolean bLocalExt_bModSpt;
   uint8   u8LocalTqSys_rPrfNomModSpt;
   uint8   u8LocalTqSys_stModSpt;
   uint8   u8LocalRatioCalculation;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalCalcPara;
   sint16  s16LocalHysPosLow;
   sint16  s16LocalEngLim_tqCkEfcModSptLim;
   sint32  s32LocalRatioCalculation;


   VEMS_vidGET(EngLim_tqCkEfcModSptLim, s16LocalEngLim_tqCkEfcModSptLim);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(CoCha_bTqReqASR, bLocalCoCha_bTqReqASR);
   VEMS_vidGET(CoCha_bTqReqMSR, bLocalCoCha_bTqReqMSR);
   VEMS_vidGET(Ext_bModSptReq, bLocalExt_bModSptReq);

   /*DetectSat*/
   if (TqSys_tqEfcMaxNomModSpt != 0)
   {
      s32LocalRatioCalculation =
         (sint32)(s16LocalEngLim_tqCkEfcModSptLim * 128);
      s32LocalRatioCalculation = ( s32LocalRatioCalculation
                                 / TqSys_tqEfcMaxNomModSpt);
      u8LocalRatioCalculation =
         (uint8)MATHSRV_udtCLAMP(s32LocalRatioCalculation, 0, 128);
      /*QAC Msg(3:3356): This statement is covered in unit test*/
   }
   else
   {
      if (s16LocalEngLim_tqCkEfcModSptLim >= 0)
      {
         u8LocalRatioCalculation = 128;
      }
      else
      {
         u8LocalRatioCalculation = 0;
      }
   }

   /*Interpolation1D*/
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngModSpt_A,
                                                   u16LocalEng_nCkFil,
                                                   16);
   u8LocalTqSys_rPrfNomModSpt = MATHSRV_u8Interp1d(TqSys_rPrfNomModSpt_T,
                                                   u16LocalCalcPara);
   s16LocalHysPosLow = (sint16)( u8LocalTqSys_rPrfNomModSpt
                               - TqSys_rHystPrfNomModSpt_C);

   /*HysPos*/
   if ((sint16)u8LocalRatioCalculation <= s16LocalHysPosLow)
   {
      SPTMOD_bHystOutput2 = 0;
   }
   else
   {
      if (u8LocalRatioCalculation >= u8LocalTqSys_rPrfNomModSpt)
      {
         SPTMOD_bHystOutput2 = 1;
      }
   }

   if (  (TqSys_bChaRegSelModSpt_C == 0)
      || (  (bLocalCoCha_bTqReqASR == 0)
         && (bLocalCoCha_bTqReqMSR == 0)))
   {
      SPTMOD_bExt_ModSptSwitch = SPTMOD_bHystOutput2;
   }

   /*Production of Ext_bModSpt and TqSys_stModSpt*/
   bLocalFRM_bInhModSptReq = GDGAR_bGetFRM(FRM_FRM_INHMODSPTREQ);
   if (bLocalFRM_bInhModSptReq != 0)
   {
      bLocalExt_bModSpt = 0;
      u8LocalTqSys_stModSpt = 3;
   }
   else
   {
      if (  (SPTMOD_bExt_ModSptSwitch != 0)
         && (bLocalExt_bModSptReq != 0))
      {
         bLocalExt_bModSpt = 1;
         u8LocalTqSys_stModSpt = 1;
      }
      else
      {
         bLocalExt_bModSpt = 0;
         u8LocalTqSys_stModSpt = 0;
      }
   }

   VEMS_vidSET(Ext_bModSpt, bLocalExt_bModSpt);
   VEMS_vidSET(TqSys_stModSpt, u8LocalTqSys_stModSpt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidEng_State_Treatment                              */
/* !Description :  The interfaces torque, power and boost pressure are only   */
/*                 calculated during the engine running state, otherwise they */
/*                 are forced to zero.                                        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bModSpt;                                                */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 TqSys_pwrEngClcModSpt;                                       */
/*  input uint8 TqSys_rPwrEngClcModSpt;                                       */
/*  input uint16 TqSys_tqEfcClcModSpt;                                        */
/*  input uint8 TqSys_rTqEfcClcModSpt;                                        */
/*  input uint16 TqSys_pBoostClcModSpt;                                       */
/*  input uint8 TqSys_rBoostPresClcModSpt;                                    */
/*  output uint16 TqSys_pwrEngSndModSpt;                                      */
/*  output uint8 TqSys_rPwrEngSndModSpt;                                      */
/*  output uint16 TqSys_tqEfcSndModSpt;                                       */
/*  output uint8 TqSys_rTqEfcSndModSpt;                                       */
/*  output uint16 TqSys_pBoostSndModSpt;                                      */
/*  output uint8 TqSys_rBoostPresSndModSpt;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidEng_State_Treatment(void)
{
   boolean bLocalExt_bModSpt;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalTqSys_rPwrEngSndModSpt;
   uint8   u8LocalTqSys_rTqEfcSndModSpt;
   uint8   u8LocalTqSys_rBoostPresSndModSpt;
   uint16  u16LocalTqSys_pwrEngSndModSpt;
   uint16  u16LocalTqSys_tqEfcSndModSpt;
   uint16  u16LocalTqSys_pBoostSndModSpt;


   VEMS_vidGET(Ext_bModSpt, bLocalExt_bModSpt);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   if (  (bLocalExt_bModSpt != 0)
      && (u8LocalCoPTSt_stEng == 5))
   {
      u16LocalTqSys_pwrEngSndModSpt = TqSys_pwrEngClcModSpt;
      u8LocalTqSys_rPwrEngSndModSpt = TqSys_rPwrEngClcModSpt;
      u16LocalTqSys_tqEfcSndModSpt = TqSys_tqEfcClcModSpt;
      u8LocalTqSys_rTqEfcSndModSpt = TqSys_rTqEfcClcModSpt;
      u16LocalTqSys_pBoostSndModSpt = TqSys_pBoostClcModSpt;
      u8LocalTqSys_rBoostPresSndModSpt = TqSys_rBoostPresClcModSpt;
   }
   else
   {
      u16LocalTqSys_pwrEngSndModSpt = 0;
      u8LocalTqSys_rPwrEngSndModSpt = 0;
      u16LocalTqSys_tqEfcSndModSpt = 0;
      u8LocalTqSys_rTqEfcSndModSpt = 0;
      u16LocalTqSys_pBoostSndModSpt = 0;
      u8LocalTqSys_rBoostPresSndModSpt = 0;
   }

   u16LocalTqSys_pwrEngSndModSpt =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_pwrEngSndModSpt, 800);
   u8LocalTqSys_rPwrEngSndModSpt =
      (uint8)MATHSRV_udtMIN(u8LocalTqSys_rPwrEngSndModSpt, 200);
   u16LocalTqSys_tqEfcSndModSpt =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_tqEfcSndModSpt, 2000);
   u8LocalTqSys_rTqEfcSndModSpt =
      (uint8)MATHSRV_udtMIN(u8LocalTqSys_rTqEfcSndModSpt, 200);
   u16LocalTqSys_pBoostSndModSpt =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_pBoostSndModSpt, 3000);
   u8LocalTqSys_rBoostPresSndModSpt =
      (uint8)MATHSRV_udtMIN(u8LocalTqSys_rBoostPresSndModSpt, 200);

   VEMS_vidSET(TqSys_pwrEngSndModSpt, u16LocalTqSys_pwrEngSndModSpt);
   VEMS_vidSET(TqSys_rPwrEngSndModSpt, u8LocalTqSys_rPwrEngSndModSpt);
   VEMS_vidSET(TqSys_tqEfcSndModSpt, u16LocalTqSys_tqEfcSndModSpt);
   VEMS_vidSET(TqSys_rTqEfcSndModSpt, u8LocalTqSys_rTqEfcSndModSpt);
   VEMS_vidSET(TqSys_pBoostSndModSpt, u16LocalTqSys_pBoostSndModSpt);
   VEMS_vidSET(TqSys_rBoostPresSndModSpt, u8LocalTqSys_rBoostPresSndModSpt);
}
/*------------------------------- end of file --------------------------------*/