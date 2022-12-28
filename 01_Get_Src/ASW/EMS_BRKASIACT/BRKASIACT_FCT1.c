/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKASIACT                                               */
/* !Description     : BRKASIACT Component.                                    */
/*                                                                            */
/* !Module          : BRKASIACT                                               */
/* !Description     : FONCTION ASSISTANCE DE FREINAGE                         */
/*                                                                            */
/* !File            : BRKASIACT_FCT1.C                                        */
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
/*   1 / BRKASIACT_vidInitOutput                                              */
/*   2 / BRKASIACT_vidActiv_Cond_Veh                                          */
/*   3 / BRKASIACT_vidActiv_Cond_Couple                                       */
/*   4 / BRKASIACT_vidSuperviseur                                             */
/*   5 / BRKASIACT_vidSF_supervise_BrkAsi                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 03258 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#047998                                         */
/* !OtherRefs   : VEMS V02 ECU#060255                                         */
/* !OtherRefs   : 01460_10_00034 / 02                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/BRK/BRKASIACT/BRKASIACT_FC$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "BRKASIACT.h"
#include "BRKASIACT_L.h"
#include "BRKASIACT_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidInitOutput                                    */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output boolean BRKASIACT_bTmrOut;                                         */
/*  output boolean BRKASIACT_bTqSysbDeceAcvPrev;                              */
/*  output uint16 BRKASIACT_u16Cnt;                                           */
/*  output boolean TqSys_bAcvBrkAsiImdtStra;                                  */
/*  output boolean TqSys_bBrkAsiAcv;                                          */
/*  output boolean TqSys_bBrkAsiPres_MP;                                      */
/*  output boolean TqSys_bBrkAsiTq_MP;                                        */
/*  output boolean TqSys_bBrkAsiVeh;                                          */
/*  output boolean TqSys_bTqACCnd;                                            */
/*  output boolean TqSys_bTqAltCnd;                                           */
/*  output uint16 TqSys_tiBrkAsiACMax;                                        */
/*  output uint16 TqSys_tiBrkAsiAltMax;                                       */
/*  output uint16 TqSys_tiInhACBrkAsi;                                        */
/*  output uint16 TqSys_tiInhACWait;                                          */
/*  output uint16 TqSys_tiInhACWaitMax;                                       */
/*  output uint16 TqSys_tiRlsAltBrkAsi;                                       */
/*  output uint16 TqSys_tiRlsAltWait;                                         */
/*  output uint16 TqSys_tiRlsAltWaitMax;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidInitOutput(void)
{
   VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
   VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
   VEMS_vidSET(TqSys_stBrkAsi, 0);
   BRKASIACT_bTmrOut = 0;
   BRKASIACT_bTqSysbDeceAcvPrev = 0;
   BRKASIACT_u16Cnt = 0;
   TqSys_bAcvBrkAsiImdtStra = 0;
   TqSys_bBrkAsiAcv = 0;
   TqSys_bBrkAsiPres_MP = 0;
   TqSys_bBrkAsiTq_MP = 0;
   TqSys_bBrkAsiVeh = 0;
   TqSys_bTqACCnd = 0;
   TqSys_bTqAltCnd = 0;
   TqSys_tiBrkAsiACMax = 0;
   TqSys_tiBrkAsiAltMax = 0;
   TqSys_tiInhACBrkAsi = 0;
   TqSys_tiInhACWait = 0;
   TqSys_tiInhACWaitMax = 0;
   TqSys_tiRlsAltBrkAsi = 0;
   TqSys_tiRlsAltWait = 0;
   TqSys_tiRlsAltWaitMax = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidActiv_Cond_Veh                                */
/* !Description :  On détermine ici les différentes conditions de roulage pour*/
/*                 activer une assistance de freinage.                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_03258_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint16 EOM_tiEngCrankStrt;                                          */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input boolean Stg_bStgPmpThdMes;                                          */
/*  input uint16 Stg_pStgPmpLnrMes;                                           */
/*  input sint8 Ext_tAir;                                                     */
/*  input boolean TqSys_bDeceAcv;                                             */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 TqSys_tAirBrkAsiX_A[6];                                       */
/*  input uint8 TqSys_tOilBrkAsiY_A[6];                                       */
/*  input uint16 TqSys_tiEngStrtBrkAsi_M[6][6];                               */
/*  input boolean BRKASIACT_bTqSysbDeceAcvPrev;                               */
/*  input uint16 BRKASIACT_u16Cnt;                                            */
/*  input uint16 TqSys_tiDeceAcvBrkAsi_C;                                     */
/*  input uint16 TqSys_pStgThdBrkAsi_C;                                       */
/*  input uint8 TqSys_spdVehThdBrkAsi_C;                                      */
/*  input uint16 TqSys_rAccPThdBrkAsi_C;                                      */
/*  input uint16 TqSys_pExtThdBrkAsi_C;                                       */
/*  input boolean BRKASIACT_bTmrOut;                                          */
/*  output uint16 BRKASIACT_u16Cnt;                                           */
/*  output boolean BRKASIACT_bTmrOut;                                         */
/*  output boolean BRKASIACT_bTqSysbDeceAcvPrev;                              */
/*  output boolean TqSys_bBrkAsiVeh;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidActiv_Cond_Veh(void)
{
   boolean bLocalInhBrkAsi;
   boolean bLocalStg_bStgPmpThdMes;
   boolean bLocalTqSys_bDeceAcv;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalExt_tAir;
   uint8   u8LocalExt_tOilEstim;
   uint16  u16LocalAccP_rAccP;
   uint16  u16LocalEOM_tiEngCrankStrt;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalParaExt_tOilMes;
   uint16  u16LocalParaExt_tAir;
   uint16  u16LocalSpdVehThdBrkAsi;
   uint16  u16LocalStg_pStgPmpLnrMes;
   uint16  u16LocalTqSystiEngStrtBrkAsi;
   uint16  u16LocalVeh_spdVeh;
   sint8   s8LocalExt_tAir;
   sint16  s16LocalExt_tOilEstim;
   sint32  s32LocalTqSys_spdVehThdBrkAsi_C;
   sint32  s32LocalStg_pStgPmpLnrMes;


   bLocalInhBrkAsi = GDGAR_bGetFRM(FRM_FRM_INHBRKASI);

   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(EOM_tiEngCrankStrt, u16LocalEOM_tiEngCrankStrt);
   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilEstim);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Stg_bStgPmpThdMes, bLocalStg_bStgPmpThdMes);
   VEMS_vidGET(Stg_pStgPmpLnrMes, u16LocalStg_pStgPmpLnrMes);
   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(TqSys_bDeceAcv, bLocalTqSys_bDeceAcv);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);

   s8LocalExt_tAir = (sint8)MATHSRV_udtMAX(s8LocalExt_tAir, -40);
   u8LocalExt_tAir = (uint8)(s8LocalExt_tAir + 40);
   u16LocalParaExt_tAir = MATHSRV_u16CalcParaIncAryU8(TqSys_tAirBrkAsiX_A,
                                                      u8LocalExt_tAir,
                                                      6);

   s16LocalExt_tOilEstim = (sint16)((s16LocalExt_tOilEstim + 500) / 10);
   u8LocalExt_tOilEstim = (uint8)MATHSRV_udtCLAMP(s16LocalExt_tOilEstim,
                                                  0,
                                                  250);
   u16LocalParaExt_tOilMes =
      MATHSRV_u16CalcParaIncAryU8(TqSys_tOilBrkAsiY_A,
                                  u8LocalExt_tOilEstim,
                                  6);
   u16LocalTqSystiEngStrtBrkAsi =
      MATHSRV_u16Interp2d(&TqSys_tiEngStrtBrkAsi_M[0][0],
                          u16LocalParaExt_tAir,
                          u16LocalParaExt_tOilMes,
                          6);
   /*TmrRst*/
   if (bLocalTqSys_bDeceAcv != 0)
   {
      if (BRKASIACT_bTqSysbDeceAcvPrev != 0)
      {
         if (BRKASIACT_u16Cnt > 0)
         {
            BRKASIACT_u16Cnt = (uint16)(BRKASIACT_u16Cnt - 1);
            if (BRKASIACT_u16Cnt != 0)
            {
               BRKASIACT_bTmrOut = 1;
            }
            else
            {
               BRKASIACT_bTmrOut = 0;
            }
         }
         else
         {
            BRKASIACT_bTmrOut = 0;
         }
      }
      else
      {
         BRKASIACT_u16Cnt = (uint16)MATHSRV_udtMIN(TqSys_tiDeceAcvBrkAsi_C,
                                                   500);
         if (BRKASIACT_u16Cnt != 0)
         {
            BRKASIACT_bTmrOut = 1;
         }
         else
         {
            BRKASIACT_bTmrOut = 0;
         }
      }

   }
   else
   {
      BRKASIACT_bTmrOut = 0;
      BRKASIACT_u16Cnt = 0;
   }
   BRKASIACT_bTqSysbDeceAcvPrev = bLocalTqSys_bDeceAcv;
   s32LocalTqSys_spdVehThdBrkAsi_C = TqSys_pStgThdBrkAsi_C - 1;
   u16LocalSpdVehThdBrkAsi = (uint16)(TqSys_spdVehThdBrkAsi_C * 128);
   s32LocalStg_pStgPmpLnrMes = (sint32) u16LocalStg_pStgPmpLnrMes;

   if (  (  (s32LocalStg_pStgPmpLnrMes > s32LocalTqSys_spdVehThdBrkAsi_C)
         || (bLocalStg_bStgPmpThdMes != 0))
      && (u16LocalVeh_spdVeh < u16LocalSpdVehThdBrkAsi)
      && (u16LocalAccP_rAccP <= TqSys_rAccPThdBrkAsi_C)
      && (u16LocalExt_pAirExtMes < TqSys_pExtThdBrkAsi_C)
      && (  (u16LocalEOM_tiEngCrankStrt > u16LocalTqSystiEngStrtBrkAsi)
         && (u8LocalCoPTSt_stEng == 5))
      && (BRKASIACT_bTmrOut == 0)
      && (u8LocalCoPt_noEgdGearCord > 0)
      && (bLocalInhBrkAsi == 0))
   {
      TqSys_bBrkAsiVeh = 1;
   }
   else
   {
      TqSys_bBrkAsiVeh = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidActiv_Cond_Couple                             */
/* !Description :  On utilise  ici des mesures de pression plénum en  fonction*/
/*                 du couple moteur pour activer une assistance de  freinage. */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 TqCmp_tqACLoss;                                              */
/*  input sint16 TqCmp_tqAltLoss;                                             */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input uint16 TqSys_pExtBrkAsiX_A[5];                                      */
/*  input uint16 TqSys_pDeltaReqBrkAsi_T[5];                                  */
/*  input uint8 TqSys_pDeltaHysBrkAsi_C;                                      */
/*  input uint16 TqSys_tqLossBrkAsiY_A[5];                                    */
/*  input uint16 BRKASIACT_u16TqSumLossCmp;                                   */
/*  input uint16 TqSys_pDeltaBrkAsi_M[5][5];                                  */
/*  input boolean TqSys_bAcvBrkAsi_C;                                         */
/*  input boolean TqSys_bBrkAsiVeh;                                           */
/*  input boolean TqSys_bBrkAsiPres_MP;                                       */
/*  input boolean TqSys_bBrkAsiTq_MP;                                         */
/*  output uint16 BRKASIACT_u16TqSumLossCmp;                                  */
/*  output boolean TqSys_bBrkAsiTq_MP;                                        */
/*  output boolean TqSys_bBrkAsiPres_MP;                                      */
/*  output boolean TqSys_bBrkAsiAcv;                                          */
/*  output boolean TqSys_bTqAltCnd;                                           */
/*  output boolean TqSys_bTqACCnd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidActiv_Cond_Couple(void)
{
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalInterp1;
   uint16 u16LocalInterp2;
   uint16 u16LocalNegHysIn1;
   uint16 u16LocalNegHysIn2;
   uint16 u16LocalNegHysIn3;
   uint16 u16LocalNegHysLow;
   uint16 u16LocalParaExt_pAirExtMes;
   uint16 u16LocalParaTqCmp_tq;
   uint16 u16LocalTqCmp_tq;
   uint16 u16LocalTqCmp_tqACLoss;
   uint32 u32LocalNegHysHigh;
   sint16 s16LocalExt_pDsThrMes;
   sint16 s16LocalTqCmp_tqAltLoss;
   sint16 s16LocalTqCmp_tqSumLossCmp;
   sint32 s32LocalDiffMes;
   sint32 s32LocalTqCmp_tq;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
   VEMS_vidGET(TqCmp_tqACLoss, u16LocalTqCmp_tqACLoss);
   VEMS_vidGET(TqCmp_tqAltLoss, s16LocalTqCmp_tqAltLoss);
   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);

   /* Interp1D */
   u16LocalParaExt_pAirExtMes =
      MATHSRV_u16CalcParaIncAryU16(TqSys_pExtBrkAsiX_A,
                                   u16LocalExt_pAirExtMes,
                                   5);
   u16LocalInterp1 = MATHSRV_u16Interp1d(TqSys_pDeltaReqBrkAsi_T,
                                        u16LocalParaExt_pAirExtMes);
   u16LocalNegHysLow = u16LocalInterp1;
   u32LocalNegHysHigh = (uint32)(u16LocalInterp1 + TqSys_pDeltaHysBrkAsi_C);
   /* Interp2D 1 --> Input : TqCmp_tqSumLossCmp */
   BRKASIACT_u16TqSumLossCmp =
      (uint16)MATHSRV_udtMAX(s16LocalTqCmp_tqSumLossCmp, 0);
   u16LocalParaTqCmp_tq =
      MATHSRV_u16CalcParaIncAryU16(TqSys_tqLossBrkAsiY_A,
                                   BRKASIACT_u16TqSumLossCmp,
                                   5);
   u16LocalInterp2 =
      MATHSRV_u16Interp2d(&TqSys_pDeltaBrkAsi_M[0][0],
                          u16LocalParaExt_pAirExtMes,
                          u16LocalParaTqCmp_tq,
                          5);
   u16LocalNegHysIn1 = u16LocalInterp2;

   /* NegHys */
   if (u16LocalNegHysIn1 <= u16LocalNegHysLow)
   {
      TqSys_bBrkAsiTq_MP = 1;
   }
   else
   {
      if (u16LocalNegHysIn1 >= u32LocalNegHysHigh)
      {
         TqSys_bBrkAsiTq_MP = 0;
      }
   }

   s32LocalDiffMes = (sint32)( (u16LocalExt_pAirExtMes
                               - s16LocalExt_pDsThrMes)
                             + 500);
   if (s32LocalDiffMes < u16LocalInterp1)
   {
      TqSys_bBrkAsiPres_MP = 1;
   }
   else
   {
      TqSys_bBrkAsiPres_MP = 0;
   }

   if (  (TqSys_bAcvBrkAsi_C != 0)
      && (TqSys_bBrkAsiVeh != 0)
      && (  (TqSys_bBrkAsiPres_MP != 0)
         || (TqSys_bBrkAsiTq_MP != 0)))
   {
      TqSys_bBrkAsiAcv = 1;
   }
   else
   {
      TqSys_bBrkAsiAcv = 0;
   }
   /* Interp2D 2 --> Input : (TqCmp_tqSumLossCmp - TqCmp_tqAltLoss) */

   s32LocalTqCmp_tq = (sint32)( s16LocalTqCmp_tqSumLossCmp
                              - s16LocalTqCmp_tqAltLoss);
   u16LocalTqCmp_tq = (uint16)MATHSRV_udtMAX(s32LocalTqCmp_tq, 0);
   u16LocalParaTqCmp_tq =
      MATHSRV_u16CalcParaIncAryU16(TqSys_tqLossBrkAsiY_A,
                                   u16LocalTqCmp_tq,
                                   5);
   u16LocalInterp2 = MATHSRV_u16Interp2d(&TqSys_pDeltaBrkAsi_M[0][0],
                                         u16LocalParaExt_pAirExtMes,
                                         u16LocalParaTqCmp_tq,
                                         5);
   u16LocalNegHysIn2 = u16LocalInterp2;

   /* NegHys1 */
   if (u16LocalNegHysIn2 <= u16LocalNegHysLow)
   {
      TqSys_bTqAltCnd = 1;
   }
   else
   {
      if (u16LocalNegHysIn2 >= u32LocalNegHysHigh)
      {
         TqSys_bTqAltCnd = 0;
      }
   }
   /* Interp2D 3 --> Input : (TqCmp_tqSumLossCmp - TqCmp_tqACLoss) */
   s32LocalTqCmp_tq = (sint32)( s16LocalTqCmp_tqSumLossCmp
                              - u16LocalTqCmp_tqACLoss);
   u16LocalTqCmp_tq = (uint16)MATHSRV_udtMAX(s32LocalTqCmp_tq, 0);

   u16LocalParaTqCmp_tq =
      MATHSRV_u16CalcParaIncAryU16(TqSys_tqLossBrkAsiY_A,
                                   u16LocalTqCmp_tq,
                                   5);
   u16LocalInterp2 = MATHSRV_u16Interp2d(&TqSys_pDeltaBrkAsi_M[0][0],
                                         u16LocalParaExt_pAirExtMes,
                                         u16LocalParaTqCmp_tq,
                                         5);
   u16LocalNegHysIn3 = u16LocalInterp2;

   /* NegHys2 */
   if (u16LocalNegHysIn3 <= u16LocalNegHysLow)
   {
      TqSys_bTqACCnd = 1;
   }
   else
   {
      if (u16LocalNegHysIn3 >= u32LocalNegHysHigh)
      {
         TqSys_bTqACCnd = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidSuperviseur                                   */
/* !Description :  Le superviseur fait la priorité sur les actions en         */
/*                 fonctions de la situation demandée. Les actions            */
/*                 d’assistance vis-à-vis des accessoires sont maintenues     */
/*                 pendant un temps fini calibrable.                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKASIACT_vidSF_supervise_BrkAsi();                      */
/*  input boolean TqSys_bAcvBrkAsiImdtStra_C;                                 */
/*  input uint16 TqSys_tiBrkAsiACMax_C;                                       */
/*  input uint16 TqSys_tiBrkAsiAltMax_C;                                      */
/*  input uint16 TqSys_tiRlsAltWaitMax_C;                                     */
/*  input uint16 TqSys_tiInhACWaitMax_C;                                      */
/*  output boolean TqSys_bAcvBrkAsiImdtStra;                                  */
/*  output uint16 TqSys_tiBrkAsiACMax;                                        */
/*  output uint16 TqSys_tiBrkAsiAltMax;                                       */
/*  output uint16 TqSys_tiRlsAltWaitMax;                                      */
/*  output uint16 TqSys_tiInhACWaitMax;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidSuperviseur(void)
{
   TqSys_bAcvBrkAsiImdtStra = TqSys_bAcvBrkAsiImdtStra_C;
   TqSys_tiBrkAsiACMax = (uint16)MATHSRV_udtMIN(TqSys_tiBrkAsiACMax_C, 1000);
   TqSys_tiBrkAsiAltMax = (uint16)MATHSRV_udtMIN(TqSys_tiBrkAsiAltMax_C, 1000);
   TqSys_tiRlsAltWaitMax = (uint16)MATHSRV_udtMIN(TqSys_tiRlsAltWaitMax_C,
                                                  1000);
   TqSys_tiInhACWaitMax = (uint16)MATHSRV_udtMIN(TqSys_tiInhACWaitMax_C, 1000);

   BRKASIACT_vidSF_supervise_BrkAsi();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidSF_supervise_BrkAsi                           */
/* !Description :  Le superviseur fait la priorité sur les actions en         */
/*                 fonctions de la situation demandée. Les actions            */
/*                 d’assistance vis-à-vis des accessoires sont maintenues     */
/*                 pendant un temps fini calibrable.                          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BRKASIACT_vidAssistOFF();                                */
/*  extf argret void BRKASIACT_vidAssistALT_ON();                             */
/*  extf argret void BRKASIACT_vidAssistAC_ON();                              */
/*  extf argret void BRKASIACT_vidAssistALT_AC_ON();                          */
/*  extf argret void BRKASIACT_vidAssistALT_OFF_AC_ON();                      */
/*  extf argret void BRKASIACT_vidAssistALT_ON_AC_OFF();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 TqSys_stBrkAsi;                                               */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output uint16 TqSys_tiRlsAltWait;                                         */
/*  output uint16 TqSys_tiRlsAltBrkAsi;                                       */
/*  output uint16 TqSys_tiInhACWait;                                          */
/*  output uint16 TqSys_tiInhACBrkAsi;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidSF_supervise_BrkAsi(void)
{
   uint8 u8LocalTqSys_stBrkAsi;


   VEMS_vidGET(TqSys_stBrkAsi, u8LocalTqSys_stBrkAsi);

   switch (u8LocalTqSys_stBrkAsi)
   {
      case 0:
         BRKASIACT_vidAssistOFF();
      break;

      case 1:
         BRKASIACT_vidAssistALT_ON();
      break;

      case 2:
         BRKASIACT_vidAssistAC_ON();
      break;

      case 3:
         BRKASIACT_vidAssistALT_AC_ON();
      break;

      case 4:
         BRKASIACT_vidAssistALT_OFF_AC_ON();
      break;

      case 5:
         BRKASIACT_vidAssistALT_ON_AC_OFF();
      break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
         VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
         VEMS_vidSET(TqSys_stBrkAsi, 0);
         TqSys_tiRlsAltWait = 0 ;
         TqSys_tiRlsAltBrkAsi = 0 ;
         TqSys_tiInhACWait = 0 ;
         TqSys_tiInhACBrkAsi = 0 ;
      break;
   }
}

/*--------------------------------- end of file ------------------------------*/