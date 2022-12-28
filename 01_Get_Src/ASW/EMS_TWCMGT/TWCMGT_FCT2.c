/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TWCMGT                                                  */
/* !Description     : TWCMGT component.                                       */
/*                                                                            */
/* !Module          : TWCMGT                                                  */
/* !Description     : Three Way Catalyst Heating Manager.                     */
/*                                                                            */
/* !File            : TWCMGT_FCT2.C                                           */
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
/*   1 / TWCMGT_VidMngActivAndDeactivCond                                     */
/*   2 / TWCMGT_VidMng_Progressive_Heat                                       */
/*   3 / TWCMGT_VidEstimAndSaveTimOfPhas1                                     */
/*   4 / TWCMGT_VidEstimate_Phase_Time_1                                      */
/*   5 / TWCMGT_VidSaveAndInitPhaseTime1                                      */
/*   6 / TWCMGT_VidManageThresholdPhase3                                      */
/*   7 / TWCMGT_VidSelect_Phase                                               */
/*   8 / TWCMGT_VidAuthorizeLightOffCompt                                     */
/*   9 / TWCMGT_VidManage_Light_Off                                           */
/*   10 / TWCMGT_VidEstNormCondLightOffTim                                    */
/*                                                                            */
/* !Reference   : V02 NT 11 02024 / 01                                        */
/* !OtherRefs   : 01460_10_02228 / 1                                          */
/* !OtherRefs   : VEMS V02 ECU#054415                                         */
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
#include "TWCMGT.h"
#include "TWCMGT_L.h"
#include "TWCMGT_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
#include "SWFAIL.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidMngActivAndDeactivCond                           */
/* !Description :  This block manages the activation and deactivation         */
/*                 conditions.                                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean LsSys_bLsFloOxCHeatReq;                                     */
/*  input boolean TWCMgt_bDeacHeatPha;                                        */
/*  input boolean TWCMgt_bAcvHeatPha;                                         */
/*  input boolean TWCMGT_bAcvHeatPhaPrev;                                     */
/*  output boolean TWCMgt_bTWCHeatReq;                                        */
/*  output boolean TWCMGT_bAcvHeatPhaPrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidMngActivAndDeactivCond(void)
{
   boolean   blocalLsSys_bLsFloOxCHeatReq;
   boolean   bLocalFRMInhTWCHeat;


   bLocalFRMInhTWCHeat = GDGAR_bGetFRM(FRM_FRM_INHTWCHEAT);
   VEMS_vidGET(LsSys_bLsFloOxCHeatReq, blocalLsSys_bLsFloOxCHeatReq);
   if (  (  (blocalLsSys_bLsFloOxCHeatReq == 0)
         && (TWCMgt_bDeacHeatPha != 0))
      || (bLocalFRMInhTWCHeat != 0))
   {
      TWCMgt_bTWCHeatReq = 0;
   }
   else
   {
      if (  (TWCMgt_bAcvHeatPha != 0)
         && (TWCMGT_bAcvHeatPhaPrev == 0))
      {
         TWCMgt_bTWCHeatReq = 1;
      }
   }
   TWCMGT_bAcvHeatPhaPrev = TWCMgt_bAcvHeatPha;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidMng_Progressive_Heat                             */
/* !Description :  This bloc allows managing the modulation heating strategy  */
/*                 which consists in having different heat phase of catalyst  */
/*                 heating. Each phase is associated to a heat power and has  */
/*                 different duration according to the situation.             */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TWCMGT_VidEstimAndSaveTimOfPhas1();                      */
/*  extf argret void TWCMGT_VidManageThresholdPhase3();                       */
/*  extf argret void TWCMGT_VidSelect_Phase();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidMng_Progressive_Heat(void)
{
   /*F01_Estimate_and_Save_Time_of_Phase_1*/
   TWCMGT_VidEstimAndSaveTimOfPhas1();
   /*F02_Manage_Threshold_Phase_3*/
   TWCMGT_VidManageThresholdPhase3();
   /*F03_Select_Phase*/
   TWCMGT_VidSelect_Phase();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidEstimAndSaveTimOfPhas1                           */
/* !Description :  This bloc is composed of 2 subsystems: The first saves the */
/*                 current value of the estimated time of phase 1 and feed.The*/
/*                 second stimates the value of the phase1 according to       */
/*                 several catalyst ageing factors.                           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TWCMGT_VidEstimate_Phase_Time_1();                       */
/*  extf argret void TWCMGT_VidSaveAndInitPhaseTime1();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidEstimAndSaveTimOfPhas1(void)
{
   /*F01_Estimate_Phase_Time_1*/
   TWCMGT_VidEstimate_Phase_Time_1();
   /*F02_Save_and_Init_Phase_Time_1*/
   TWCMGT_VidSaveAndInitPhaseTime1();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidEstimate_Phase_Time_1                            */
/* !Description :  This bloc allows determining the duration of the phase     */
/*                 (phase corresponding to the maximum heating catalyst)      */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean OxC_bEndMonORngItrsv;                                       */
/*  input boolean MonMisf_bClcMisfOBD;                                        */
/*  input boolean MonMisf_bAcvMonMisfOBD;                                     */
/*  input boolean LsMon_bEndMonResHeatLsUs;                                   */
/*  input uint32 Ext_dstVehTotMes;                                            */
/*  input uint16 OxC_mO2StgMvEstim;                                           */
/*  input uint16 LsMon_noRatEfcLsUsPer;                                       */
/*  input uint16 MonMisf_rMisfOBD;                                            */
/*  input uint16 LsMon_resLsUsHeat;                                           */
/*  input uint16 TWCMgt_dstDftKmOldVeh_C;                                     */
/*  input uint16 TWCMgt_dstVehMesLoResl_MP;                                   */
/*  input uint16 TWCMgt_dstVeh_tiPha1Km_A[12];                                */
/*  input uint16 TWCMGT_u16InputdstVehTiPha1Km;                               */
/*  input uint16 TWCMgt_tiPha1Km_T[12];                                       */
/*  input boolean TWCMGT_bOxCbEndMonORngItrsvPrev;                            */
/*  input uint16 TWCMgt_mO2Stg_tiPha_A[12];                                   */
/*  input uint16 TWCMgt_tiPhaO2Stg_T[12];                                     */
/*  input uint8 TWCMgt_facFilRatEfcLsUsPer_C;                                 */
/*  input uint32 TWCMGT_u32FilterKMem;                                        */
/*  input uint16 TWCMGT_u16OutPassFilterK;                                    */
/*  input uint16 TWCMgt_noRatEfcLsUsPer_A[12];                                */
/*  input uint16 TWCMgt_tiPhaRatEfcLsUsPer_T[12];                             */
/*  input boolean TWCMGT_bMonMisfbClcMisfOBDPrev;                             */
/*  input uint16 TWCMgt_rMisfOBD_tPha1Misf_A[12];                             */
/*  input uint16 TWCMgt_tiPha1Misf_T[12];                                     */
/*  input boolean TWCMGT_bLsMonbEndMonResHeatPrev;                            */
/*  input uint16 TWCMgt_resLsUsHeat_A[12];                                    */
/*  input uint16 TWCMgt_tiResLsUsHeat_T[12];                                  */
/*  output uint16 TWCMgt_dstVehMesLoResl_MP;                                  */
/*  output uint16 TWCMGT_u16InputdstVehTiPha1Km;                              */
/*  output uint16 TWCMgt_tiPha1Km;                                            */
/*  output uint16 TWCMgt_tiPhaO2Stg;                                          */
/*  output uint16 TWCMGT_u16OutPassFilterK;                                   */
/*  output uint32 TWCMGT_u32FilterKMem;                                       */
/*  output uint16 TWCMgt_tiPhaRatEfcLsUsPer;                                  */
/*  output uint16 TWCMgt_tiPha1Misf;                                          */
/*  output uint16 TWCMgt_tiResLsUsHeat;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidEstimate_Phase_Time_1(void)
{
   boolean  bLocalFRM_bAcvHeatPhaMax;
   boolean  bLocalOxC_bEndMonORngItrsv;
   boolean  bLocalMonMisf_bClcMisfOBD;
   boolean  bLocalMonMisf_bAcvMonMisfOBD;
   boolean  bLocalLsMon_bEndMonResHeatLsUs;
   uint8    u8LocaltiFilRatGain;
   uint16   u16LocalOxC_mO2StgMvEstim;
   uint16   u16LocalLsMon_noRatEfcLsUsPer;
   uint16   u16LocalMonMisf_rMisfOBD;
   uint16   u16LocalLsMon_resLsUsHeat;
   uint16   u16LocalInterp1D;
   uint16   u16LocalCalcPara;
   uint32   u32LocalTWCMgtdstVehMesLoReslP;
   uint32   u32LocalExt_dstVehTotMes;


   VEMS_vidGET(OxC_bEndMonORngItrsv, bLocalOxC_bEndMonORngItrsv);
   VEMS_vidGET(MonMisf_bClcMisfOBD, bLocalMonMisf_bClcMisfOBD);
   VEMS_vidGET(MonMisf_bAcvMonMisfOBD, bLocalMonMisf_bAcvMonMisfOBD);
   VEMS_vidGET(LsMon_bEndMonResHeatLsUs, bLocalLsMon_bEndMonResHeatLsUs);
   VEMS_vidGET(Ext_dstVehTotMes, u32LocalExt_dstVehTotMes);
   VEMS_vidGET(OxC_mO2StgMvEstim, u16LocalOxC_mO2StgMvEstim);
   VEMS_vidGET(LsMon_noRatEfcLsUsPer, u16LocalLsMon_noRatEfcLsUsPer);
   VEMS_vidGET(MonMisf_rMisfOBD, u16LocalMonMisf_rMisfOBD);
   VEMS_vidGET(LsMon_resLsUsHeat, u16LocalLsMon_resLsUsHeat);
   bLocalFRM_bAcvHeatPhaMax = GDGAR_bGetFRM(FRM_FRM_ACVHEATPHAMAX);

  /*producing TWCMgt_dstVehMesLoResl_MP */
   u32LocalTWCMgtdstVehMesLoReslP = u32LocalExt_dstVehTotMes / 10;
   TWCMgt_dstVehMesLoResl_MP =
      (uint16)MATHSRV_udtMIN(u32LocalTWCMgtdstVehMesLoReslP, 50000);

  /*producing TWCMgt_tiPha1Km*/
   if (bLocalFRM_bAcvHeatPhaMax != 0)
   {
      TWCMGT_u16InputdstVehTiPha1Km = TWCMgt_dstDftKmOldVeh_C;
   }
   else
   {
      TWCMGT_u16InputdstVehTiPha1Km = TWCMgt_dstVehMesLoResl_MP;
   }
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(TWCMgt_dstVeh_tiPha1Km_A,
                                   TWCMGT_u16InputdstVehTiPha1Km,
                                   12);
   u16LocalInterp1D = MATHSRV_u16Interp1d(TWCMgt_tiPha1Km_T, u16LocalCalcPara);
   TWCMgt_tiPha1Km = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 50000);

   /*producing TWCMgt_tiPhaO2Stg*/
   if (  (bLocalOxC_bEndMonORngItrsv != 0)
      && (TWCMGT_bOxCbEndMonORngItrsvPrev == 0))
   {
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TWCMgt_mO2Stg_tiPha_A,
                                                      u16LocalOxC_mO2StgMvEstim,
                                                      12);
      u16LocalInterp1D =
         MATHSRV_u16Interp1d(TWCMgt_tiPhaO2Stg_T, u16LocalCalcPara);
      TWCMgt_tiPhaO2Stg = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 50000);
   }
   else
   {
      TWCMgt_tiPhaO2Stg = 0;
   }

   /* producing TWCMgt_tiPhaRatEfcLsUsPer*/
   if (TWCMgt_facFilRatEfcLsUsPer_C < 100)
   {
      u8LocaltiFilRatGain = (uint8)((TWCMgt_facFilRatEfcLsUsPer_C * 64) / 25);
      TWCMGT_u16OutPassFilterK =
         MATHSRV_u16FirstOrderFilterGu8(u8LocaltiFilRatGain,
                                        &TWCMGT_u32FilterKMem,
                                        u16LocalLsMon_noRatEfcLsUsPer);
   }
   else
   {
      TWCMGT_u16OutPassFilterK = u16LocalLsMon_noRatEfcLsUsPer;
      TWCMGT_u32FilterKMem = (uint32)(TWCMGT_u16OutPassFilterK * 256);
   }
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TWCMgt_noRatEfcLsUsPer_A,
                                                   TWCMGT_u16OutPassFilterK,
                                                   12);
   u16LocalInterp1D =
      MATHSRV_u16Interp1d(TWCMgt_tiPhaRatEfcLsUsPer_T, u16LocalCalcPara);
   TWCMgt_tiPhaRatEfcLsUsPer = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 50000);

   /* producing TWCMgt_tiPha1Misf*/
   if (  (  (bLocalMonMisf_bClcMisfOBD != 0)
         && (TWCMGT_bMonMisfbClcMisfOBDPrev == 0))
      && (bLocalMonMisf_bAcvMonMisfOBD != 0))
   {
      u16LocalCalcPara =
         MATHSRV_u16CalcParaIncAryU16(TWCMgt_rMisfOBD_tPha1Misf_A,
                                      u16LocalMonMisf_rMisfOBD,
                                      12);
      u16LocalInterp1D =
         MATHSRV_u16Interp1d(TWCMgt_tiPha1Misf_T, u16LocalCalcPara);
      TWCMgt_tiPha1Misf = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 50000);
   }
   else
   {
      TWCMgt_tiPha1Misf = 0;
   }

   /* producing TWCMgt_tiResLsUsHeat*/
   if (  (bLocalLsMon_bEndMonResHeatLsUs == 0)
      && (TWCMGT_bLsMonbEndMonResHeatPrev != 0))
   {
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TWCMgt_resLsUsHeat_A,
                                                      u16LocalLsMon_resLsUsHeat,
                                                      12);
      u16LocalInterp1D =
         MATHSRV_u16Interp1d(TWCMgt_tiResLsUsHeat_T, u16LocalCalcPara);
      TWCMgt_tiResLsUsHeat = (uint16)MATHSRV_udtMIN(u16LocalInterp1D, 50000);
   }
   else
   {
      TWCMgt_tiResLsUsHeat = 0;
   }

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidSaveAndInitPhaseTime1                            */
/* !Description :  Maximum duration of all the estimated phase 1 duration     */
/*                 values (from deterioration factors) becomes the estimated  */
/*                 duration of the phase 1.                                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TWCMgt_bRstETBTiPha1_C;                                     */
/*  input boolean TWCMGT_bRstETBTiPha1Prev;                                   */
/*  input uint16 TWCMgt_tiPha1ETB_C;                                          */
/*  input uint16 TWCMgt_tiHiTWCCurEstim_MP;                                   */
/*  input uint16 TWCMgt_tiOutStg_MP;                                          */
/*  input uint16 TWCMgt_tiPha1Km;                                             */
/*  input uint16 TWCMgt_tiPhaO2Stg;                                           */
/*  input uint16 TWCMgt_tiPhaRatEfcLsUsPer;                                   */
/*  input uint16 TWCMgt_tiPha1Misf;                                           */
/*  input uint16 TWCMgt_tiResLsUsHeat;                                        */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  input boolean TWCMgt_bTWCHeatReqPrev;                                     */
/*  input uint16 TWCMgt_tiHiTWCHiAr;                                          */
/*  output uint16 TWCMgt_tiOutStg_MP;                                         */
/*  output uint16 TWCMgt_tiHiTWCCurEstim_MP;                                  */
/*  output uint16 TWCMgt_tiPha1_NV;                                           */
/*  output uint16 TWCMgt_tiHiTWCHiAr;                                         */
/*  output uint16 TWCMgt_tiHiTWCHiArPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidSaveAndInitPhaseTime1(void)
{
   uint16  u16localtiHiTWCCurEstim_MP;


   /*producing TWCMgt_tiHiTWCCurEstim_MP and TWCMgt_tiOutStg_MP*/
   if (  (TWCMgt_bRstETBTiPha1_C != 0)
      && (TWCMGT_bRstETBTiPha1Prev == 0))
   {
      TWCMgt_tiOutStg_MP = (uint16)MATHSRV_udtMIN(TWCMgt_tiPha1ETB_C, 50000);
   }
   else
   {
      TWCMgt_tiOutStg_MP =
         (uint16)MATHSRV_udtMIN(TWCMgt_tiHiTWCCurEstim_MP, 50000);
   }
   if (TWCMgt_bRstETBTiPha1_C != 0)
   {
      TWCMgt_tiHiTWCCurEstim_MP = TWCMgt_tiOutStg_MP;
   }
   else
   {
      u16localtiHiTWCCurEstim_MP =
         (uint16)MATHSRV_udtMAX(TWCMgt_tiPha1Km, TWCMgt_tiPhaO2Stg);
      u16localtiHiTWCCurEstim_MP =
         (uint16)MATHSRV_udtMAX(u16localtiHiTWCCurEstim_MP,
                                TWCMgt_tiPhaRatEfcLsUsPer);
      u16localtiHiTWCCurEstim_MP =
         (uint16)MATHSRV_udtMAX(u16localtiHiTWCCurEstim_MP, TWCMgt_tiPha1Misf);
      u16localtiHiTWCCurEstim_MP =
         (uint16)MATHSRV_udtMAX(u16localtiHiTWCCurEstim_MP,
                                TWCMgt_tiResLsUsHeat);
      u16localtiHiTWCCurEstim_MP =
         (uint16)MATHSRV_udtMAX(u16localtiHiTWCCurEstim_MP,
                                TWCMgt_tiHiTWCCurEstim_MP);
      TWCMgt_tiHiTWCCurEstim_MP =
         (uint16)MATHSRV_udtMIN(u16localtiHiTWCCurEstim_MP, 50000);
   }
   TWCMgt_tiPha1_NV = TWCMgt_tiHiTWCCurEstim_MP;

   /*producing TWCMgt_tiHiTWCHiAr*/
   if (  (TWCMgt_bTWCHeatReq != 0)
      && (TWCMgt_bTWCHeatReqPrev == 0))
   {
      TWCMgt_tiHiTWCHiAr = TWCMgt_tiHiTWCCurEstim_MP;
   }
   else
   {
      TWCMgt_tiHiTWCHiAr = (uint16)MATHSRV_udtMIN(TWCMgt_tiHiTWCHiAr, 50000);
   }

   TWCMgt_tiHiTWCHiArPrev = TWCMgt_tiHiTWCHiAr;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidManageThresholdPhase3                            */
/* !Description :  The goal of this block is to manage the transition between */
/*                 phase 3 and the precedent heating phase based on a         */
/*                 temperature or duration criteria.                          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 ExM_tOxCEstim;                                               */
/*  input sint16 TWCMgt_tTWCHeatPha3Acv_C;                                    */
/*  input boolean TWCMGT_bIntiDlyPha3TurnOnPrev;                              */
/*  input uint16 TWCMgt_tiDlyPha3_C;                                          */
/*  input uint16 TWCMGT_u16tiDlyPha3Count;                                    */
/*  input uint16 TWCMgt_tiSdlFast_C;                                          */
/*  input uint16 TWCMgt_tiHeatHiAr_A[12];                                     */
/*  input uint16 TWCMgt_tiHiTWCHiAr;                                          */
/*  input uint16 TWCMgt_tiPha3Acv_T[12];                                      */
/*  input uint16 TWCMgt_tiTWC;                                                */
/*  input boolean TWCMGT_bOuttiDlyPha3TurnOnDelay;                            */
/*  output uint16 TWCMGT_u16tiDlyPha3Count;                                   */
/*  output boolean TWCMGT_bOuttiDlyPha3TurnOnDelay;                           */
/*  output boolean TWCMGT_bIntiDlyPha3TurnOnPrev;                             */
/*  output boolean TWCMgt_bTWCHeatPha3Acv;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidManageThresholdPhase3(void)
{
   boolean  bLocaltiTWC;
   boolean  bLocaltiDlyPha3TurnOndelay;
   uint16   u16LocalCalcPara;
   uint16   u16LocalInterp1D;
   sint16   s16LocalExM_tOxCEstim;


   VEMS_vidGET(ExM_tOxCEstim, s16LocalExM_tOxCEstim);
   if (s16LocalExM_tOxCEstim > TWCMgt_tTWCHeatPha3Acv_C)
   {
      bLocaltiDlyPha3TurnOndelay = 1;
   }
   else
   {
      bLocaltiDlyPha3TurnOndelay = 0;
   }
   if (bLocaltiDlyPha3TurnOndelay != 0)
   {
      if (TWCMGT_bIntiDlyPha3TurnOnPrev == 0)
      {
         TWCMGT_u16tiDlyPha3Count = TWCMgt_tiDlyPha3_C;
      }
      else
      {
         if (TWCMGT_u16tiDlyPha3Count >= TWCMgt_tiSdlFast_C)
         {
            TWCMGT_u16tiDlyPha3Count =
               (uint16)(TWCMGT_u16tiDlyPha3Count - TWCMgt_tiSdlFast_C);
         }
         else
         {
            TWCMGT_u16tiDlyPha3Count = 0;
         }
      }
      if (TWCMGT_u16tiDlyPha3Count == 0)
      {
         TWCMGT_bOuttiDlyPha3TurnOnDelay = 1;
      }
      else
      {
         TWCMGT_bOuttiDlyPha3TurnOnDelay = 0;
      }
   }
   else
   {
      TWCMGT_bOuttiDlyPha3TurnOnDelay = 0;
   }
   TWCMGT_bIntiDlyPha3TurnOnPrev = bLocaltiDlyPha3TurnOndelay;

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TWCMgt_tiHeatHiAr_A,
                                                   TWCMgt_tiHiTWCHiAr,
                                                   12);
   u16LocalInterp1D = MATHSRV_u16Interp1d(TWCMgt_tiPha3Acv_T, u16LocalCalcPara);
   if (TWCMgt_tiTWC > u16LocalInterp1D)
   {
      bLocaltiTWC = 1;
   }
   else
   {
      bLocaltiTWC = 0;
   }
   if (  (TWCMGT_bOuttiDlyPha3TurnOnDelay != 0)
      || (bLocaltiTWC != 0))
   {
      TWCMgt_bTWCHeatPha3Acv = 1;
   }
   else
   {
      TWCMgt_bTWCHeatPha3Acv = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidSelect_Phase                                     */
/* !Description :  The goal of this block is to manage the selection of the   */
/*                 different phases: 0 (No heating), 1( Maximum Catalyst ),   */
/*                 2(Normal Catalyst ), 3(Reduced Catalyst) and 4(Maximum     */
/*                 Catalyst Heating phase in cold temperature area)           */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ext_stTypInjSysCf;                                            */
/*  input uint8 TWCMgt_stHeatPhaReqBas;                                       */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  input boolean TWCMgt_bTCoAr;                                              */
/*  input boolean TWCMgt_bTWCHeatPha3Acv;                                     */
/*  input uint16 TWCMgt_tiTWC;                                                */
/*  input uint16 TWCMgt_tiHiTWCHiAr;                                          */
/*  output uint8 TWCMgt_stHeatPhaReqBas;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidSelect_Phase(void)
{
   uint8  u8LocalExt_stTypInjSysCf;


   VEMS_vidGET(Ext_stTypInjSysCf, u8LocalExt_stTypInjSysCf);
   switch (TWCMgt_stHeatPhaReqBas)
   {
      case 0:
         if (TWCMgt_bTWCHeatReq != 0)
         {
            if (TWCMgt_bTCoAr != 0)
            {
               TWCMgt_stHeatPhaReqBas = 1;
            }
            else
            {
               TWCMgt_stHeatPhaReqBas = 4;
            }
         }
         break;

      case 1:
         if (TWCMgt_bTWCHeatReq == 0)
         {
            TWCMgt_stHeatPhaReqBas = 0;
         }
         else
         {
            if (  (TWCMgt_bTWCHeatPha3Acv != 0)
               && (u8LocalExt_stTypInjSysCf == 1))
            {
               TWCMgt_stHeatPhaReqBas = 3;
            }
            else
            {
               if (  (TWCMgt_tiTWC >= TWCMgt_tiHiTWCHiAr)
                  && (  (TWCMgt_bTWCHeatPha3Acv == 0)
                     || (u8LocalExt_stTypInjSysCf == 0)))
               {
                  TWCMgt_stHeatPhaReqBas = 2;
               }
            }
         }
         break;

      case 2:
         if (TWCMgt_bTWCHeatReq == 0)
         {
            TWCMgt_stHeatPhaReqBas = 0;
         }
         else
         {
            if (  (TWCMgt_bTWCHeatPha3Acv != 0)
               && (u8LocalExt_stTypInjSysCf == 1))
            {
               TWCMgt_stHeatPhaReqBas = 3;
            }
         }
         break;

      case 3:
      case 4:
         if (TWCMgt_bTWCHeatReq == 0)
         {
            TWCMgt_stHeatPhaReqBas = 0;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         TWCMgt_stHeatPhaReqBas = 0;
         break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidAuthorizeLightOffCompt                           */
/* !Description :  This block authorizes the computation of the light-off     */
/*                 status and allows that the computation goes on if the      */
/*                 catalyst heating is deactivated.                           */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TWCMgt_bLiOffDonePrev;                                      */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  output boolean TWCMgt_bLiOffClcAuth;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidAuthorizeLightOffCompt(void)
{
   if (TWCMgt_bLiOffDonePrev != 0)
   {
      TWCMgt_bLiOffClcAuth = 0;
   }
   else
   {
      if (TWCMgt_bTWCHeatReq != 0)
      {
         TWCMgt_bLiOffClcAuth = 1;
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidManage_Light_Off                                 */
/* !Description :  The goal of this block is to feed the flag                 */
/*                 “TWCMgt_bLiOffDone”. This one indicates the state of the   */
/*                 catalyst: true when the catalyst is efficient, false in    */
/*                 other case.                                                */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TWCMGT_VidEstNormCondLightOffTim();                      */
/*  extf argret void TWCMGT_VidCount_Light_Off_Time();                        */
/*  extf argret void TWCMGT_VidTWCEstHeatDeactLgOfTim();                      */
/*  extf argret void TWCMGT_VidManageLightOff();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidManage_Light_Off(void)
{
   /*F01_Estimate_Normal_Conditions_Light_Off_Time*/
   TWCMGT_VidEstNormCondLightOffTim();
   /*F02_Count_Light_Off_Time*/
   TWCMGT_VidCount_Light_Off_Time();
   /*F03_TWC_Estimate_Heat_Deactivation_Light_Off_Time*/
   TWCMGT_VidTWCEstHeatDeactLgOfTim();
   /*F04_Manage_Light_Off*/
   TWCMGT_VidManageLightOff();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidEstNormCondLightOffTim                           */
/* !Description :  This block estimates the time of phase 1 for a normal      */
/*                 situation (no three way catalyst heating deactivation      */
/*                 during the running)                                        */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TWCMgt_bTCoAr;                                              */
/*  input uint16 TWCMgt_tiHeatHiAr_A[12];                                     */
/*  input uint16 TWCMgt_tiHiTWCHiAr;                                          */
/*  input uint16 TWCMgt_tiLiOffDone_T[12];                                    */
/*  input uint16 TWCMgt_tiTWCLiOffHeatLoAr_C;                                 */
/*  output uint16 TWCMgt_tiLiOffNormCdn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidEstNormCondLightOffTim(void)
{
   uint16  u16LocalCalcPara;
   uint16  u16LocalTWCMgt_tiLiOffNormCdn;


   if (TWCMgt_bTCoAr != 0)
   {
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TWCMgt_tiHeatHiAr_A,
                                                      TWCMgt_tiHiTWCHiAr,
                                                      12);
      u16LocalTWCMgt_tiLiOffNormCdn =
         MATHSRV_u16Interp1d(TWCMgt_tiLiOffDone_T, u16LocalCalcPara);
   }
   else
   {
      u16LocalTWCMgt_tiLiOffNormCdn = TWCMgt_tiTWCLiOffHeatLoAr_C;
   }
   TWCMgt_tiLiOffNormCdn =
      (uint16)MATHSRV_udtMIN(u16LocalTWCMgt_tiLiOffNormCdn, 50000);
}

/*------------------------------- end of file --------------------------------*/