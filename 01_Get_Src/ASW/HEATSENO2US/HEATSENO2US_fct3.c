/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2US                                             */
/* !Description     : HEATSENO2US Component                                   */
/*                                                                            */
/* !Module          : HEATSENO2US                                             */
/* !Description     : GESTION CHAUFFAGE SONDE AMONT                           */
/*                                                                            */
/* !File            : HEATSENO2US_FCT3.C                                      */
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
/*   1 / HEATSENO2US_vidTranC1ToC2                                            */
/*   2 / HEATSENO2US_vidAcvHeatWku                                            */
/*   3 / HEATSENO2US_vidTranAtoBandBtoA                                       */
/*   4 / HEATSENO2US_vidTReCoLsHeat                                           */
/*   5 / HEATSENO2US_vidTDsThrLsHeat                                          */
/*   6 / HEATSENO2US_vidLsUsDetRTStallint                                     */
/*   7 / HEATSENO2US_vidLsUsDetRTStall                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5211932 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#061098                                         */
/* !OtherRefs   : VEMS V02 ECU#066573                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/HEATSENO2US/HEATSENO2U$*/
/* $Revision::   1.6      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2US.h"
#include "HEATSENO2US_L.h"
#include "HEATSENO2US_IM.h"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTranC1ToC2                                  */
/* !Description :  Cette fonction autorise la transition de la phase C1 à C2  */
/*                 lorsqu’un temps passé LsSys_tiLsUsBoostProtReq en phase C1 */
/*                 dépasse un seuil calibrable dépendant de la température    */
/*                 d’eau.                                                     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 LsSys_tCoLsHeat;                                             */
/*  input uint16 ExM_tExLsUsMainOxCEstim;                                     */
/*  input boolean Lshd_up_stream_lbda_sensor_hot;                             */
/*  input uint32 Time_since_stall;                                            */
/*  input uint16 LsSys_tMaxLsUsHeatBoostThd_C;                                */
/*  input uint8 LsSys_tCoLsUsThdBoostProtReq_T[6];                            */
/*  input uint8 LsSys_tiLsUsThdBoostProtReq_M[6];                             */
/*  input uint8 LsSys_tiLsUsBoostProtReq;                                     */
/*  input uint16 LsSys_tiLsUsWaitSecBoost_C;                                  */
/*  input boolean LsSys_bLsUsMainOxCDewPtOkLstStrt;                           */
/*  input boolean LsSys_bInhLsUsOxCNoPtOkLstStrt_C;                           */
/*  output boolean LsSys_bLsUsBoostEnd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTranC1ToC2(void)
{
   boolean bLocalLshdupstreamlbdasensorhot;
   uint8   u8Local_LsSystiLsUsThdBoostPrtRq;
   uint8   u8LocalSitInterpolation;
   uint16  u16LocalCalcPara;
   uint16  u16LocalExM_tExLsUsMainOxCEstim;
   uint16  u16LocalLsSysMaxLsUsHeatBootThd;
   uint32  u32LocalTime_since_stall;
   sint16  s16Local_LsSystCoLsHeat;
   sint32  s32Local_LsSystCoLsHeat;


   VEMS_vidGET(LsSys_tCoLsHeat, s16Local_LsSystCoLsHeat);
   VEMS_vidGET(ExM_tExLsUsMainOxCEstim, u16LocalExM_tExLsUsMainOxCEstim);
   VEMS_vidGET(Lshd_up_stream_lbda_sensor_hot, bLocalLshdupstreamlbdasensorhot);
   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);

   u16LocalLsSysMaxLsUsHeatBootThd =
      (uint16)(LsSys_tMaxLsUsHeatBoostThd_C - 7136);
   s32Local_LsSystCoLsHeat = (sint32)(s16Local_LsSystCoLsHeat + 40);
   u8LocalSitInterpolation =
      (uint8)MATHSRV_udtCLAMP(s32Local_LsSystCoLsHeat, 0, 254);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(LsSys_tCoLsUsThdBoostProtReq_T,
                                  u8LocalSitInterpolation,
                                  6);
   u8Local_LsSystiLsUsThdBoostPrtRq =
      MATHSRV_u8Interp1d(LsSys_tiLsUsThdBoostProtReq_M, u16LocalCalcPara);

   if (  (LsSys_tiLsUsBoostProtReq > u8Local_LsSystiLsUsThdBoostPrtRq)
      || (  (u32LocalTime_since_stall < LsSys_tiLsUsWaitSecBoost_C)
         && (  (LsSys_bLsUsMainOxCDewPtOkLstStrt == 0)
            || (LsSys_bInhLsUsOxCNoPtOkLstStrt_C != 0)))
      || (  (bLocalLshdupstreamlbdasensorhot != 0)
         && (u16LocalExM_tExLsUsMainOxCEstim
            > u16LocalLsSysMaxLsUsHeatBootThd)))
   {
      LsSys_bLsUsBoostEnd = 1;
   }
   else
   {
      LsSys_bLsUsBoostEnd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidAcvHeatWku                                  */
/* !Description :  La fonction chauffage sonde doit être active au réveil     */
/*                 partiel, notamment pour pouvoir réaliser le préchauffage   */
/*                 sonde                                                      */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st09 Rcd_power_state;                                               */
/*  input boolean Rcd_mode_active;                                            */
/*  output boolean Ext_bAcvHeatWkuLsSys;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidAcvHeatWku(void)
{
   uint8 u8Local_Rcd_power_state;


   VEMS_vidGET(Rcd_power_state, u8Local_Rcd_power_state);
   if (  (Rcd_mode_active != 0)
      && (u8Local_Rcd_power_state == RCD_ANTICIPATION))
   {
      VEMS_vidSET(Ext_bAcvHeatWkuLsSys, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcvHeatWkuLsSys, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTranAtoBandBtoA                             */
/* !Description :  Pour activer le préchauffage il faut notamment une tension */
/*                 batterie suffisamment élevée, les conditions de fast light */
/*                 off réunies, que le préchauffage n’ait pas déjà été        */
/*                 effectué.                                                  */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bAcvHeatWkuLsSys;                                       */
/*  input sint16 Ext_uBattMes;                                                */
/*  input boolean LsSys_bLsUsMainOxCHeatFloEna;                               */
/*  input uint8 LsSys_uHeatWkuEna_C;                                          */
/*  input boolean LsSys_bHeatWkuLsSysDone;                                    */
/*  input boolean LsSys_bHeatWkuEna_C;                                        */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseB;                                */
/*  input uint16 LsSys_tiDlyHeatWkuEna_C;                                     */
/*  output boolean LsSys_bLsUsMainOxCHeatWkuEna;                              */
/*  output boolean LsSys_bLsUsMainOxCHeatWkuEnd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTranAtoBandBtoA(void)
{
   boolean bLocalExt_bAcvHeatWkuLsSys;
   boolean bLocalLsSysbLsUsMainOxCHeatFloEn;
   boolean bLocalLsSys;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalLsSysUHeatWkuEna;
   sint16  s16LocalExt_uBattMes;

   VEMS_vidGET(Ext_bAcvHeatWkuLsSys, bLocalExt_bAcvHeatWkuLsSys);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(LsSys_bLsUsMainOxCHeatFloEna, bLocalLsSysbLsUsMainOxCHeatFloEn);
   u16LocalLsSysUHeatWkuEna = (uint16)(LsSys_uHeatWkuEna_C * 10);

   if (  (bLocalExt_bAcvHeatWkuLsSys != 0)
      && (LsSys_bHeatWkuLsSysDone == 0)
      && (s16LocalExt_uBattMes >= (sint16)u16LocalLsSysUHeatWkuEna)
      && (LsSys_bHeatWkuEna_C != 0)
      && (bLocalLsSysbLsUsMainOxCHeatFloEn != 0) )
   {
      LsSys_bLsUsMainOxCHeatWkuEna = 1;
   }
   else
   {
      LsSys_bLsUsMainOxCHeatWkuEna = 0;
   }
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if (  (LsSys_tiLsUsDlyMainOxCPhaseB > LsSys_tiDlyHeatWkuEna_C)
      && (  (Preparation != u8LocalCoPTSt_stEng)
         && (Driven_Start != u8LocalCoPTSt_stEng)))
   {
      bLocalLsSys = 1;
   }
   else
   {
      bLocalLsSys = 0;
   }
   if (  (bLocalLsSys != 0)
      || (LsSys_bHeatWkuEna_C == 0)
      || (s16LocalExt_uBattMes < (sint16)u16LocalLsSysUHeatWkuEna)
      || (LsSys_bHeatWkuLsSysDone != 0) )
   {
      LsSys_bLsUsMainOxCHeatWkuEnd = 1;
   }
   else
   {
      LsSys_bLsUsMainOxCHeatWkuEnd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTReCoLsHeat                                 */
/* !Description :  Reconfiguration de l'ensemble des informations Température */
/*                 d'eau et Température d'air eronnés par une valeur de       */
/*                 remplacement calibrable.                                   */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_003.01                                     */
/*                 VEMS_R_12_01117_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidTCoLsHeat();                              */
/*  extf argret void HEATSENO2US_vidTDsThrLsHeat();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTReCoLsHeat(void)
{
   HEATSENO2US_vidTCoLsHeat();
   HEATSENO2US_vidTDsThrLsHeat();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTDsThrLsHeat                                */
/* !Description :  Lorsque l'information température air (Ext_tDsThrStrtMes)  */
/*                 n'est pas valide, celle-ci doit être reconfigurée pour     */
/*                 l'ensemble de la  fonction par une valeur de remplacement  */
/*                 calibrable.                                                */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 LsSys_tDsThrLihLsHeat_C;                                     */
/*  input sint16 Ext_tDsThrStrtMes;                                           */
/*  output sint16 LsSys_tDsThrLsHeat;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTDsThrLsHeat(void)
{
   boolean bLocalAcvMod_tAirMes;
   sint16  s16LocalLsSys_tDsThrLsHeat;
   sint16  s16LocalExt_tDsThrStrtMes;


   bLocalAcvMod_tAirMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TAIRMES);

   if (bLocalAcvMod_tAirMes != 0)
   {
      s16LocalLsSys_tDsThrLsHeat = LsSys_tDsThrLihLsHeat_C;
   }
   else
   {
      VEMS_vidGET(Ext_tDsThrStrtMes, s16LocalExt_tDsThrStrtMes);
      s16LocalLsSys_tDsThrLsHeat = s16LocalExt_tDsThrStrtMes;
   }
   s16LocalLsSys_tDsThrLsHeat =
      (sint16)MATHSRV_udtCLAMP(s16LocalLsSys_tDsThrLsHeat, -50, 200);

   VEMS_vidSET(LsSys_tDsThrLsHeat, s16LocalLsSys_tDsThrLsHeat);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidLsUsDetRTStallint                           */
/* !Description :  Lors de la détection d’un passage de l’état moteur stall   */
/*                 vers cranking ou d’état moteur cranking vers running, la   */
/*                 variable est mise à zéro.                                  */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean LsSys_bLsUsDetRTStall;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidLsUsDetRTStallint(void)
{
   LsSys_bLsUsDetRTStall = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidLsUsDetRTStall                              */
/* !Description :  Lors de la détection du passage de l’état moteur « Running */
/*                 » vers Stall, la variable est mise à 1.                    */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean LsSys_bLsUsDetRTStall;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidLsUsDetRTStall(void)
{
   LsSys_bLsUsDetRTStall = 1;
}
/*------------------------------- end of file --------------------------------*/