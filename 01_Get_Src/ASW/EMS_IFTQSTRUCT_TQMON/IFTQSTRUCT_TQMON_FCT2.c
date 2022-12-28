/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFTQSTRUCT_TQMON                                        */
/* !Description     : IFTQSTRUCT_TQMON Component                              */
/*                                                                            */
/* !Module          : IFTQSTRUCT_TQMON                                        */
/* !Description     : Safety TMS : Interface TMS                              */
/*                                                                            */
/* !File            : IFTQSTRUCT_TQMON_FCT2.C                                 */
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
/*   1 / IFTQSTRUCT_TQMON_vidGenerInfTran                                     */
/*   2 / IFTQSTRUCT_TQMON_vidGenerInfTole                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5050415 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2536 / 2.11 br1                                 */
/* !OtherRefs   : VEMS V02 ECU#058176                                         */
/* !OtherRefs   : VEMS V02 ECU#059384                                         */
/* !OtherRefs   : VEMS V02 ECU#060678                                         */
/* !OtherRefs   : VEMS V02 ECU#065782                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFTQSTRUCT_TQMON/IFTQS$*/
/* $Revision::   1.17     $$Author::   mbenfrad       $$Date::   15 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   15 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IFTQSTRUCT_TQMON.h"
#include "IFTQSTRUCT_TQMON_L.h"
#include "IFTQSTRUCT_TQMON_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGenerInfTran                           */
/* !Description :  cette fonction permet de générer les informations de       */
/*                 transmission                                               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_10_01265_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bGearTyp_C;                                         */
/*  input boolean SftyMgt_bCluTyp_C;                                          */
/*  input boolean SftyMgt_bCluPedPrss;                                        */
/*  input uint16 SftyMgt_rCluPedPHiFreq;                                      */
/*  input uint8 SftyMgt_rThdOpTraPHiFreq_C;                                   */
/*  input boolean SftyMgt_bNeut;                                              */
/*  input boolean SftyMgt_bTqTx;                                              */
/*  input uint16 SftyMgt_spdVeh;                                              */
/*  input uint16 SftyMgt_nEng;                                                */
/*  input uint16 SftyMgt_facGearRat_C;                                        */
/*  input uint16 SftyMgt_spd1000RatHi_A[8];                                   */
/*  input uint16 IFTQSTRUCT_TQMON_u16SpdVeh;                                  */
/*  input uint16 SftyMgt_spd1000RatCf_T[8];                                   */
/*  input uint16 SftyMgt_spd1000RatCf_MP;                                     */
/*  input uint8 SftyMgt_tiDlyEgdGearSfty_C;                                   */
/*  input uint8 IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr;                             */
/*  input boolean SftyMgt_bCompSpd1000_C;                                     */
/*  output uint16 IFTQSTRUCT_TQMON_u16SpdVeh;                                 */
/*  output uint16 SftyMgt_spd1000RatCf_MP;                                    */
/*  output uint8 IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr;                            */
/*  output sint8 SftyMgt_noEgdGearSfty;                                       */
/*  output boolean SftyMgt_bOpTra;                                            */
/*  output uint8 SftyMgt_stClu;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGenerInfTran(void)
{
   boolean bLocalSftyMgt_bCluTyp;
   boolean bLocalSftyMgt_bGearTyp;
   boolean bLocalSftyMgt_bNeut;
   boolean bLocalCondition2;
   boolean bLocalSftyMgt_bTqTx;
   boolean bLocalSftyMgt_bCompSpd1000;
   uint8   u8LocalMinTurnOnDelaySimple;
   uint8   u8LocalSftyMgt_tiDlyEgdGearSfty;
   sint8   s8LocalSftyMgt_noEgdGearSfty;
   uint16  u16LocalSftyMgt_rCluPedPHiFreq;
   uint16  u16LocalSftyMgt_spdVeh;
   uint16  u16LocalSftyMgt_nEng;
   uint16  u16LocalPara;
   uint16  u16LocalTemp;
   uint16  u16LocalSftyMgt_noEgdGearSfty;
   uint16  u16LocalSftyMgtspd1000RatCf_Prev;
   uint32  u32Localcalc;


   if (SftyMgt_bGearTyp_C != 0)
   {
      if (SftyMgt_bCluTyp_C != 0)
      {
         VEMS_vidGET(SftyMgt_bCluPedPrss, bLocalSftyMgt_bCluTyp);
      }
      else
      {
         VEMS_vidGET(SftyMgt_rCluPedPHiFreq, u16LocalSftyMgt_rCluPedPHiFreq);
         u16LocalTemp = (uint16)(SftyMgt_rThdOpTraPHiFreq_C * 10);
         if (u16LocalSftyMgt_rCluPedPHiFreq > u16LocalTemp)
         {
            bLocalSftyMgt_bCluTyp = 1;
         }
         else
         {
            bLocalSftyMgt_bCluTyp = 0;
         }
      }
      VEMS_vidGET(SftyMgt_bNeut, bLocalSftyMgt_bNeut);
      if (  (bLocalSftyMgt_bNeut != 0)
         || (bLocalSftyMgt_bCluTyp != 0))
      {
         bLocalSftyMgt_bGearTyp = 1;
      }
      else
      {
         bLocalSftyMgt_bGearTyp = 0;
      }
   }
   else
   {
      VEMS_vidGET(SftyMgt_bTqTx, bLocalSftyMgt_bTqTx);
      if (bLocalSftyMgt_bTqTx == 0)
      {
         bLocalSftyMgt_bGearTyp = 1;
      }
      else
      {
         bLocalSftyMgt_bGearTyp = 0;
      }
   }
   /*Interpolation*/
   VEMS_vidGET(SftyMgt_spdVeh, u16LocalSftyMgt_spdVeh);
   VEMS_vidGET(SftyMgt_nEng, u16LocalSftyMgt_nEng);
   if (  (u16LocalSftyMgt_spdVeh == 0)
      || (SftyMgt_facGearRat_C == 0))
   {
      IFTQSTRUCT_TQMON_u16SpdVeh = 0;
   }
   else
   {
      if (u16LocalSftyMgt_nEng == 0)
      {
         IFTQSTRUCT_TQMON_u16SpdVeh = 64000;
      }
      else
      {
         u32Localcalc =
            (uint32)( (u16LocalSftyMgt_spdVeh * SftyMgt_facGearRat_C)
                    / (16 * u16LocalSftyMgt_nEng));
         IFTQSTRUCT_TQMON_u16SpdVeh =
            (uint16)MATHSRV_udtMIN(u32Localcalc, 64000);
      }
   }
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_spd1000RatHi_A,
                                               IFTQSTRUCT_TQMON_u16SpdVeh,
                                               8);
   u16LocalTemp = MATHSRV_u16Interp1d(SftyMgt_spd1000RatCf_T, u16LocalPara);
   u16LocalSftyMgtspd1000RatCf_Prev = SftyMgt_spd1000RatCf_MP;
   SftyMgt_spd1000RatCf_MP = (uint16)MATHSRV_udtMIN(u16LocalTemp, 64000);

   /*Turn on delay Simple*/
   u8LocalSftyMgt_tiDlyEgdGearSfty = (uint8)( (SftyMgt_tiDlyEgdGearSfty_C + 6)
                                            / 4);

   if (SftyMgt_spd1000RatCf_MP != u16LocalSftyMgtspd1000RatCf_Prev)
   {
      IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr = 0;
   }
   else
   {
      u8LocalMinTurnOnDelaySimple =
         (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr,
                               u8LocalSftyMgt_tiDlyEgdGearSfty);
      IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr =
         (uint8)(u8LocalMinTurnOnDelaySimple + 1);
   }
   if (IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr >= u8LocalSftyMgt_tiDlyEgdGearSfty)
   {
      bLocalCondition2 = 1;
   }
   else
   {
      bLocalCondition2 = 0;
   }
   if (bLocalCondition2 != 0)
   {
      u16LocalSftyMgt_noEgdGearSfty = (uint16)(SftyMgt_spd1000RatCf_MP / 128);
      s8LocalSftyMgt_noEgdGearSfty =
         (sint8)MATHSRV_udtMIN(u16LocalSftyMgt_noEgdGearSfty, 9);
   }
   else
   {
      s8LocalSftyMgt_noEgdGearSfty = 0;
   }
   if (SftyMgt_bCompSpd1000_C != 0)
   {
      if (s8LocalSftyMgt_noEgdGearSfty != 0)
      {
         bLocalSftyMgt_bCompSpd1000 = 0;
      }
      else
      {
         bLocalSftyMgt_bCompSpd1000 = 1;
      }
   }
   else
   {
      bLocalSftyMgt_bCompSpd1000 = 1;
   }
   VEMS_vidSET(SftyMgt_noEgdGearSfty, s8LocalSftyMgt_noEgdGearSfty);

   /*Coding "XOR" and "AND" gate: E1 AND(E1 XOR E2) = E1 AND Not(E2)*/
   if (  (bLocalSftyMgt_bGearTyp != 0)
      && (bLocalSftyMgt_bCompSpd1000 == 0))
   {
      VEMS_vidSET(SftyMgt_bOpTra, 1);
      VEMS_vidSET(SftyMgt_stClu, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bOpTra, 0);
      VEMS_vidSET(SftyMgt_stClu, 2);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGenerInfTole                           */
/* !Description :  fonction generer info tolerence                            */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_10_01265_005.06                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 SftyMgt_nEng;                                                */
/*  input boolean TqSys_bTqSysAcv;                                            */
/*  input uint8 SftyMgt_tiDlyStrtExtAcv_C;                                    */
/*  input uint8 IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr;                             */
/*  input uint16 SftyMgt_nStrExtAcvThd_C;                                     */
/*  input uint16 SftyMgt_rAirLdX_A[16];                                       */
/*  input uint16 SftyMgt_nEngY_A[16];                                         */
/*  input uint16 SftyMgt_agCkOpInCal2_M[16][16];                              */
/*  input uint16 SftyMgt_agCkOpInCal_M[16][16];                               */
/*  input uint16 SftyMgt_agCkClsExCal_M[16][16];                              */
/*  input uint16 SftyMgt_agCkClsExCal2_M[16][16];                             */
/*  input boolean SftyMgt_bCkOpInVlvSel_C;                                    */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  input sint8 VlvSys_agCkOpInVlvReq;                                        */
/*  input boolean SftyMgt_bCkClsExVlvSel_C;                                   */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  input sint8 VlvSys_agCkClsExVlvReq;                                       */
/*  input uint16 SftyMgt_agCkOpInCal2_MP;                                     */
/*  input uint16 SftyMgt_agCkOpInUpThd_C;                                     */
/*  input uint16 SftyMgt_agCkOpInDownThd_C;                                   */
/*  input uint16 SftyMgt_agCkOpInCal_MP;                                      */
/*  input uint16 SftyMgt_agCkClsExCal_MP;                                     */
/*  input uint16 SftyMgt_agCkClsExUpThd_C;                                    */
/*  input uint16 SftyMgt_agCkClsExDownThd_C;                                  */
/*  input uint16 SftyMgt_agCkClsExCal2_MP;                                    */
/*  input uint8 EOM_prm_facTranMod[16];                                       */
/*  input uint8 SftyMgt_facTranModThd_C;                                      */
/*  input boolean SftyMgt_bInhModCur_C;                                       */
/*  input uint8 EOM_prm_facBasModCur[16];                                     */
/*  input boolean SftyMgt_bModCurNotEnaOffs_C;                                */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 SftyMgt_nEng_A[16];                                          */
/*  input uint16 SftyMgt_agCkClsExCal_T[16];                                  */
/*  input uint16 SftyMgt_agCkOpInCal_T[16];                                   */
/*  output uint8 IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr;                            */
/*  output uint16 SftyMgt_agCkOpInCal2_MP;                                    */
/*  output uint16 SftyMgt_agCkOpInCal_MP;                                     */
/*  output uint16 SftyMgt_agCkClsExCal_MP;                                    */
/*  output uint16 SftyMgt_agCkClsExCal2_MP;                                   */
/*  output boolean SftyMgt_bTqSysAcvTqSys;                                    */
/*  output boolean SftyMgt_bEnaPresOffsSfty;                                  */
/*  output boolean SftyMgt_bEnaTqOfsSfty;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGenerInfTole(void)
{
   boolean bLocalFRM_bInhMes_pAirExt;
   boolean bLocalcond1;
   boolean bLocalcond2;
   boolean bLocalcond3;
   boolean bLocalcond4;
   boolean bLocalcond5;
   boolean bLocalcond6;
   boolean bLocalTurnOnDlyOut;
   boolean bLocalFRM_bAcvCurPosnRegExVlv;
   boolean bLocalFRM_bAcvCurPosnRegInVlv;
   boolean bLocalFRM_bAcvLockPosnExVlv;
   boolean bLocalFRM_bAcvLockPosnInVlv;
   boolean bLocalTqSysAcv;
   boolean bLocalEnaTqOfsSfty;
   boolean bLocalTqSysAcvTqSys;
   uint8   u8LocalVlvSys_agCkOpInVlvReq;
   uint8   u8LocalVlvSys_agCkClsExVlvReq;
   uint8   u8LocalfacTranModElement;
   uint8   u8LocalfacBasModElement;
   uint8   u8LocalSftyMgt_tiDlyStrtExtAcv;
   uint8   u8LocalMinTurnOnDelaySimple;
   uint8   u8LocalSftyMgt_ModCurNotEnaOffs;
   uint16  u16LocalVlvSys_rAirLdAltiCor;
   uint16  u16LocalSftyMgt_nEng;
   uint16  u16LocalPara_rAirLdX;
   uint16  u16LocalPara_nEngY;
   uint16  u16LocalInterp2d;
   uint16  u16LocalCalcParaEng;
   uint16  u16LocalAgCkClsExCalInterp;
   uint16  u16LocalAgCkOpInCalInterp;
   uint16  u16LocalExtNEng;
   sint8   s8LocalVlvSys_agCkOpInVlvReq;
   sint8   s8LocalVlvSys_agCkClsExVlvReq;
   sint32  s32LocalSftyMgt_CkOpInSus;
   sint32  s32LocalSftyMgt_CkOpInAdd;
   sint32  s32LocalSftyMgt_CkOpIn2Sus;
   sint32  s32LocalSftyMgt_CkOpIn2Add;
   sint32  s32LocalSys_agCkOpExAdd;
   sint32  s32LocalSys_agCkOpExSus;
   sint32  s32LocalSys_agCkOpEx2Add;
   sint32  s32LocalSys_agCkOpEx2Sus;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(SftyMgt_nEng, u16LocalSftyMgt_nEng);
   VEMS_vidGET(TqSys_bTqSysAcv, bLocalTqSysAcv);

   /*Turn on delay Simple*/
   u8LocalSftyMgt_tiDlyStrtExtAcv = (uint8)( (SftyMgt_tiDlyStrtExtAcv_C + 6)
                                           / 4);

   if (bLocalTqSysAcv != 0)
   {
      IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr = 0;
   }
   else
   {
      u8LocalMinTurnOnDelaySimple =
         (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr,
                               u8LocalSftyMgt_tiDlyStrtExtAcv);
      IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr =
         (uint8)(u8LocalMinTurnOnDelaySimple + 1);
   }
   if (IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr >= u8LocalSftyMgt_tiDlyStrtExtAcv)
   {
      bLocalTurnOnDlyOut = 1;
   }
   else
   {
      bLocalTurnOnDlyOut = 0;
   }

   if (  (SftyMgt_nStrExtAcvThd_C >= u16LocalSftyMgt_nEng)
      && (bLocalTurnOnDlyOut != 0))
   {
      bLocalTqSysAcvTqSys = 0;
   }
   else
   {
      bLocalTqSysAcvTqSys = 1;
   }

   u16LocalPara_rAirLdX =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_rAirLdX_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);
   u16LocalPara_nEngY =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_nEngY_A,
                                   u16LocalSftyMgt_nEng,
                                   16);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&SftyMgt_agCkOpInCal2_M[0][0],
                                          u16LocalPara_rAirLdX,
                                          u16LocalPara_nEngY,
                                          16);
   SftyMgt_agCkOpInCal2_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 256);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&SftyMgt_agCkOpInCal_M[0][0],
                                          u16LocalPara_rAirLdX,
                                          u16LocalPara_nEngY,
                                          16);
   SftyMgt_agCkOpInCal_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 256);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&SftyMgt_agCkClsExCal_M[0][0],
                                          u16LocalPara_rAirLdX,
                                          u16LocalPara_nEngY,
                                          16);
   SftyMgt_agCkClsExCal_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 256);
   u16LocalInterp2d = MATHSRV_u16Interp2d(&SftyMgt_agCkClsExCal2_M[0][0],
                                          u16LocalPara_rAirLdX,
                                          u16LocalPara_nEngY,
                                          16);
   SftyMgt_agCkClsExCal2_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp2d, 256);

   if (SftyMgt_bCkOpInVlvSel_C != 0)
   {
      VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReq);
   }
   else
   {
      VEMS_vidGET(VlvSys_agCkOpInVlvReq, s8LocalVlvSys_agCkOpInVlvReq);
      u8LocalVlvSys_agCkOpInVlvReq =
         (uint8)(s8LocalVlvSys_agCkOpInVlvReq + 128);
   }

   if (SftyMgt_bCkClsExVlvSel_C != 0)
   {
      VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSys_agCkClsExVlvReq);
   }
   else
   {
      VEMS_vidGET(VlvSys_agCkClsExVlvReq, s8LocalVlvSys_agCkClsExVlvReq);
      u8LocalVlvSys_agCkClsExVlvReq =
         (uint8)(s8LocalVlvSys_agCkClsExVlvReq + 128);
   }

   s32LocalSftyMgt_CkOpIn2Add = (sint32)( ( SftyMgt_agCkOpInCal2_MP
                                          + SftyMgt_agCkOpInUpThd_C)
                                        - 128);
   s32LocalSftyMgt_CkOpIn2Sus = (sint32)( ( SftyMgt_agCkOpInCal2_MP
                                         - SftyMgt_agCkOpInDownThd_C)
                                        + 128);
   if (  (u8LocalVlvSys_agCkOpInVlvReq > s32LocalSftyMgt_CkOpIn2Add)
      || (u8LocalVlvSys_agCkOpInVlvReq < s32LocalSftyMgt_CkOpIn2Sus))
   {
      bLocalcond1 = 1;
   }
   else
   {
      bLocalcond1 = 0;
   }

   s32LocalSftyMgt_CkOpInAdd = (sint32)( ( SftyMgt_agCkOpInCal_MP
                                         + SftyMgt_agCkOpInUpThd_C)
                                       - 128);
   s32LocalSftyMgt_CkOpInSus = (sint32)( ( SftyMgt_agCkOpInCal_MP
                                         - SftyMgt_agCkOpInDownThd_C)
                                       + 128);
   if (  (u8LocalVlvSys_agCkOpInVlvReq > s32LocalSftyMgt_CkOpInAdd)
      || (u8LocalVlvSys_agCkOpInVlvReq < s32LocalSftyMgt_CkOpInSus))
   {
      bLocalcond2 = 1;
   }
   else
   {
      bLocalcond2 = 0;
   }

   s32LocalSys_agCkOpExAdd = (sint32)( ( SftyMgt_agCkClsExCal_MP
                                       + SftyMgt_agCkClsExUpThd_C)
                                     - 128);
   s32LocalSys_agCkOpExSus = (sint32)( ( SftyMgt_agCkClsExCal_MP
                                       - SftyMgt_agCkClsExDownThd_C)
                                     + 128);
   if (  (u8LocalVlvSys_agCkClsExVlvReq > s32LocalSys_agCkOpExAdd)
      || (u8LocalVlvSys_agCkClsExVlvReq < s32LocalSys_agCkOpExSus))
   {
      bLocalcond3 = 1;
   }
   else
   {
      bLocalcond3 = 0;
   }

   s32LocalSys_agCkOpEx2Add = (sint32)( ( SftyMgt_agCkClsExCal2_MP
                                        + SftyMgt_agCkClsExUpThd_C)
                                      - 128);
   s32LocalSys_agCkOpEx2Sus = (sint32)( ( SftyMgt_agCkClsExCal2_MP
                                        - SftyMgt_agCkClsExDownThd_C)
                                      + 128);
   if (  (u8LocalVlvSys_agCkClsExVlvReq > s32LocalSys_agCkOpEx2Add)
      || (u8LocalVlvSys_agCkClsExVlvReq < s32LocalSys_agCkOpEx2Sus))
   {
      bLocalcond4 = 1;
   }
   else
   {
      bLocalcond4 = 0;
   }

   bLocalFRM_bAcvCurPosnRegExVlv = GDGAR_bGetFRM(FRM_FRM_ACVCURPOSNREGEXVLV);
   bLocalFRM_bAcvCurPosnRegInVlv = GDGAR_bGetFRM(FRM_FRM_ACVCURPOSNREGINVLV);
   bLocalFRM_bAcvLockPosnExVlv = GDGAR_bGetFRM(FRM_FRM_ACVLOCKPOSNEXVLV);
   bLocalFRM_bAcvLockPosnInVlv = GDGAR_bGetFRM(FRM_FRM_ACVLOCKPOSNINVLV);

   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod, 4, u8LocalfacTranModElement);
   if (u8LocalfacTranModElement > SftyMgt_facTranModThd_C)
   {
      bLocalcond5 = 1;
   }
   else
   {
      bLocalcond5 = 0;
   }

   if (SftyMgt_bInhModCur_C != 0)
   {
      bLocalcond6 = 0;
   }
   else
   {
      VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                                4,
                                u8LocalfacBasModElement);

      u8LocalSftyMgt_ModCurNotEnaOffs =
         (uint8)(SftyMgt_bModCurNotEnaOffs_C * 128);
      if (u8LocalfacBasModElement != u8LocalSftyMgt_ModCurNotEnaOffs)
      {
         bLocalcond6 = 1;
      }
      else
      {
         bLocalcond6 = 0;
      }
   }

   if (  (bLocalTqSysAcvTqSys == 0)
      || (  (  (bLocalcond1 != 0)
            || (bLocalcond4 != 0))
         && (  (bLocalcond2 != 0)
            || (bLocalcond3 != 0)))
      || (bLocalFRM_bAcvCurPosnRegExVlv != 0)
      || (bLocalFRM_bAcvCurPosnRegInVlv != 0)
      || (bLocalFRM_bAcvLockPosnExVlv != 0)
      || (bLocalFRM_bAcvLockPosnInVlv != 0)
      || (bLocalcond5 != 0)
      || (bLocalcond6 != 0))
   {
      bLocalEnaTqOfsSfty = 1;
   }
   else
   {
      bLocalEnaTqOfsSfty = 0;
   }

   VEMS_vidSET(SftyMgt_bTqSysAcvTqSys, bLocalTqSysAcvTqSys);

   bLocalFRM_bInhMes_pAirExt = GDGAR_bGetFRM(FRM_FRM_INHMES_PAIREXT);
   VEMS_vidGET(Ext_nEng, u16LocalExtNEng);

   u16LocalCalcParaEng = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nEng_A,
                                                      u16LocalExtNEng,
                                                      16);
   u16LocalAgCkClsExCalInterp = MATHSRV_u16Interp1d(SftyMgt_agCkClsExCal_T,
                                                    u16LocalCalcParaEng);
   u16LocalAgCkOpInCalInterp = MATHSRV_u16Interp1d(SftyMgt_agCkOpInCal_T,
                                                   u16LocalCalcParaEng);

   if (  (bLocalFRM_bInhMes_pAirExt != 0)
      || (  (u16LocalAgCkClsExCalInterp < u8LocalVlvSys_agCkClsExVlvReq)
         && (u16LocalAgCkOpInCalInterp > u8LocalVlvSys_agCkOpInVlvReq))
      || (bLocalEnaTqOfsSfty != 0))
   {
      VEMS_vidSET(SftyMgt_bEnaPresOffsSfty, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bEnaPresOffsSfty, 0);
   }
   VEMS_vidSET(SftyMgt_bEnaTqOfsSfty, bLocalEnaTqOfsSfty);
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/