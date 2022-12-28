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
/* !File            : HEATSENO2US_FCT1.C                                      */
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
/*   1 / HEATSENO2US_vidInitOutput                                            */
/*   2 / HEATSENO2US_vidTCoLsHeat                                             */
/*   3 / HEATSENO2US_vidOxCHeatAftStrt                                        */
/*   4 / HEATSENO2US_vidLsUsDewPt                                             */
/*   5 / HEATSENO2US_vidDetDewPtRev                                           */
/*   6 / HEATSENO2US_vidDetDewPt                                              */
/*   7 / HEATSENO2US_vidDlyDewPt                                              */
/*   8 / HEATSENO2US_vidDlyDewTranOkStall                                     */
/*   9 / HEATSENO2US_vidFastLightOff                                          */
/*   10 / HEATSENO2US_vidDisableFLO                                           */
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
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidInitOutput                                  */
/* !Description :  Initialisation des variables au reset                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsSys_bAcvLsUsMainOxCHeatLih;                              */
/*  output boolean LsSys_bLsFloOxCHeatReq;                                    */
/*  output boolean LsSys_bLsOxCHeatAftStrt;                                   */
/*  output boolean LsSys_bLsUsMainOxCDewProtReq;                              */
/*  output st71 LsSys_stLsUsMainOxCHeat;                                      */
/*  output sint16 LsSys_tCoLsHeat;                                            */
/*  output boolean LsSys_bLsUsMainOxCHeatFloEna;                              */
/*  output boolean LsSys_bHeatDoneNotIntr;                                    */
/*  output boolean Ext_bAcvHeatWkuLsSys;                                      */
/*  output sint16 LsSys_tDsThrLsHeat;                                         */
/*  output uint16 LsSys_tiLsUsDlyMainOxCPhaseC;                               */
/*  output boolean LsSys_bLsUsMainOxCDiFLO;                                   */
/*  output uint8 HEATSENO2US_stEngPrev;                                       */
/*  output uint8 HEATSENO2US_u8MainOxCHeatPrev;                               */
/*  output uint8 HEATSENO2US_u8OxCHeatPrevslow;                               */
/*  output boolean HEATSENO2US_bUBattAcvHeatLih;                              */
/*  output uint16 LsSys_tiLsUsMainOxCDlyDewTranOk;                            */
/*  output uint16 LsSys_tiLsUsDlyAcvHeatLih;                                  */
/*  output boolean HEATSENO2US_bTimerInit;                                    */
/*  output boolean HEATSENO2US_bTimeout1;                                     */
/*  output boolean LsSys_bLsUsMainOxCAcvHeatHi;                               */
/*  output boolean LsSys_bLsUsMainOxCHeatLoEnd;                               */
/*  output boolean LsSys_bLsUsBoostEnd;                                       */
/*  output boolean LsSys_bLsUsMainOxCHeatWkuEna;                              */
/*  output boolean LsSys_bLsUsMainOxCHeatWkuEnd;                              */
/*  output boolean LsSys_bHeatWkuLsSysDone;                                   */
/*  output uint16 LsSys_tiLsUsDlyMainOxCPhaseB;                               */
/*  output uint16 LsSys_tiLsUsDlyMainOxCPhaseF;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidInitOutput(void)
{
   /* Outputs Initialization */
   VEMS_vidSET(LsSys_bAcvLsUsMainOxCHeatLih, 0);
   VEMS_vidSET(LsSys_bLsFloOxCHeatReq, 0);
   VEMS_vidSET(LsSys_bLsOxCHeatAftStrt, 0);
   VEMS_vidSET(LsSys_bLsUsMainOxCDewProtReq, 0);
   VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
   VEMS_vidSET(LsSys_tCoLsHeat, 0);
   VEMS_vidSET(LsSys_bLsUsMainOxCHeatFloEna, 0);
   VEMS_vidSET(LsSys_bHeatDoneNotIntr, 0);
   VEMS_vidSET(Ext_bAcvHeatWkuLsSys, 0);
   VEMS_vidSET(LsSys_tDsThrLsHeat, 0);

   /* Internals initialization */
   LsSys_tiLsUsDlyMainOxCPhaseC = 0;
   LsSys_bLsUsMainOxCDiFLO = 0;
   HEATSENO2US_stEngPrev = 0;
   HEATSENO2US_u8MainOxCHeatPrev = 0;
   HEATSENO2US_u8OxCHeatPrevslow = 0;
   HEATSENO2US_bUBattAcvHeatLih = 0;
   LsSys_tiLsUsMainOxCDlyDewTranOk = 0;
   LsSys_tiLsUsDlyAcvHeatLih = 0;
   HEATSENO2US_bTimerInit = 0;
   HEATSENO2US_bTimeout1 = 0;
   LsSys_bLsUsMainOxCAcvHeatHi = 1;
   LsSys_bLsUsMainOxCHeatLoEnd = 0;
   LsSys_bLsUsBoostEnd = 0;
   LsSys_bLsUsMainOxCHeatWkuEna = 0;
   LsSys_bLsUsMainOxCHeatWkuEnd = 0;
   LsSys_bHeatWkuLsSysDone = 0;
   LsSys_tiLsUsDlyMainOxCPhaseB = 0;
   LsSys_tiLsUsDlyMainOxCPhaseF = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTCoLsHeat                                   */
/* !Description :  Lorsque l’information température d’eau (Ext_tCoMes) n’est */
/*                 pas valide, celle-ci doit être reconfigurée pour l’ensemble*/
/*                 de la fonction par une valeur de remplacement calibrable   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 LsSys_tCoLihLsHeat_C;                                        */
/*  input sint16 Ext_tCoMes;                                                  */
/*  output sint16 LsSys_tCoLsHeat;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTCoLsHeat(void)
{
   boolean bLocalDftTCo;
   sint16  s16LocalLsSysTCoLsHeat;
   sint16  s16LocalExt_tCoMes;


   bLocalDftTCo = GDGAR_bGetFRM(FRM_FRM_DFT_TCO);
   if (bLocalDftTCo != 0)
   {
      s16LocalLsSysTCoLsHeat = LsSys_tCoLihLsHeat_C;
   }
   else
   {
      VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
      s16LocalLsSysTCoLsHeat = s16LocalExt_tCoMes;
   }
   s16LocalLsSysTCoLsHeat = (sint16)MATHSRV_udtCLAMP(s16LocalLsSysTCoLsHeat,
                                                     -40,
                                                     214);
   VEMS_vidSET(LsSys_tCoLsHeat, s16LocalLsSysTCoLsHeat);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidOxCHeatAftStrt                              */
/* !Description :  Afin de détecter au mieux le passage du point de rosée,    */
/*                 l’état de la chauffe catalyseur doit être pris en compte   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bStrtEnd;                                               */
/*  input boolean OxC_bIntrHeat;                                              */
/*  input boolean OxC_bOxCHeatPhaReq;                                         */
/*  input boolean LsSys_bLsOxCHeatAftStrt;                                    */
/*  output boolean LsSys_bLsOxCHeatAftStrt;                                   */
/*  output boolean LsSys_bHeatDoneNotIntr;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidOxCHeatAftStrt(void)
{
   boolean bLocalExt_bStrtEnd;
   boolean bLocalOxC_bOxCHeatPhaReq;
   boolean bLocalOxC_bIntrHeat;
   boolean bLocalLsSys_bLsOxCHeatAftStrt;


   VEMS_vidGET(Ext_bStrtEnd, bLocalExt_bStrtEnd);
   VEMS_vidGET(OxC_bIntrHeat, bLocalOxC_bIntrHeat);
   VEMS_vidGET(OxC_bOxCHeatPhaReq, bLocalOxC_bOxCHeatPhaReq);
   if (bLocalExt_bStrtEnd == 0)
   {
      VEMS_vidSET(LsSys_bLsOxCHeatAftStrt, 0);
   }
   else
   {
      if (bLocalOxC_bOxCHeatPhaReq != 0)
      {
         VEMS_vidSET(LsSys_bLsOxCHeatAftStrt, 1);
      }
   }

   VEMS_vidGET(LsSys_bLsOxCHeatAftStrt, bLocalLsSys_bLsOxCHeatAftStrt);
   if (  (bLocalOxC_bOxCHeatPhaReq != 0)
      || (  (bLocalOxC_bIntrHeat == 0)
         && (bLocalLsSys_bLsOxCHeatAftStrt != 0)))
   {
      VEMS_vidSET(LsSys_bHeatDoneNotIntr, 1);
   }
   else
   {
      VEMS_vidSET(LsSys_bHeatDoneNotIntr, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidLsUsDewPt                                   */
/* !Description :  Détection du passage du point de rosée pour la sonde O2    */
/*                 amont                                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidDetDewPtRev();                            */
/*  extf argret void HEATSENO2US_vidDetDewPt();                               */
/*  extf argret void HEATSENO2US_vidDlyDewPt();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidLsUsDewPt(void)
{
   HEATSENO2US_vidDetDewPtRev();
   HEATSENO2US_vidDetDewPt();
   HEATSENO2US_vidDlyDewPt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidDetDewPtRev                                 */
/* !Description :  Déterminer au bout de combien de temps la sonde  va        */
/*                 franchir le point de rosée à l’envers                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 LsSys_tiLsUsDlyDewTranOkStall;                               */
/*  input uint16 LsSys_tiLsUsDlyDewTranOkStall_T[8];                          */
/*  input uint16 LsSys_tiLsUsDlyDewTranNotOk_M[8];                            */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean LsSys_bLsUsDetRTStall;                                      */
/*  input uint32 Time_since_stall;                                            */
/*  input uint16 LsSys_tiLsUsDlyDewTranNotOk;                                 */
/*  output boolean LsSys_bLsUsMainOxCDewPtOkLstStrt;                          */
/*  output uint16 LsSys_tiLsUsDlyDewTranNotOk;                                */
/*  output boolean LsSys_bLsUsMainOxCDewPtNOk;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidDetDewPtRev(void)
{
   uint8  u8LocalVehicle_active_state;
   uint16 u16LocalCalcPara;
   uint16 u16LocalTrNotOk;
   uint16 u16LocalTrNotOkCalc;
   uint32 u32LocalTime_since_stall;


   if (LsSys_tiLsUsDlyDewTranOkStall > 0)
   {
      LsSys_bLsUsMainOxCDewPtOkLstStrt = 1;
   }
   else
   {
      LsSys_bLsUsMainOxCDewPtOkLstStrt = 0;
   }
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(LsSys_tiLsUsDlyDewTranOkStall_T,
                                   LsSys_tiLsUsDlyDewTranOkStall,
                                   8);
   u16LocalTrNotOk = MATHSRV_u16Interp1d(LsSys_tiLsUsDlyDewTranNotOk_M,
                                         u16LocalCalcPara);
   LsSys_tiLsUsDlyDewTranNotOk = (uint16)MATHSRV_udtMIN(u16LocalTrNotOk, 65355);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if ((u8LocalVehicle_active_state == VS_STALL) && (LsSys_bLsUsDetRTStall !=0))
   {
      VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
      u16LocalTrNotOkCalc = (uint16)(LsSys_tiLsUsDlyDewTranNotOk / 10);
      if (u32LocalTime_since_stall > u16LocalTrNotOkCalc)
      {
         LsSys_bLsUsMainOxCDewPtNOk = 1;
      }
      else
      {
         LsSys_bLsUsMainOxCDewPtNOk = 0;
      }
   }
   else
   {
      LsSys_bLsUsMainOxCDewPtNOk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidDetDewPt                                    */
/* !Description :  Détermination du passage du  du point de rosée en fonction */
/*                 de la durée du chauffage de protection                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoStrtMes;                                              */
/*  input uint8 Cat_old_gain;                                                 */
/*  input boolean LsSys_bHeatDoneNotIntr;                                     */
/*  input sint16 LsSys_tDsThrLsHeat;                                          */
/*  input uint8 Temperature_water_bkpt_map[16];                               */
/*  input uint8 Cat_old_gain_bkpt_map[8];                                     */
/*  input uint16 LsSys_tiLsUsDlyDTrOxCHt_M[16][8];                            */
/*  input uint16 LsSys_tiLsUsDlyDTrOxCHtPnt_M[16];                            */
/*  input uint8 Temperature_air_bkpt_map[6];                                  */
/*  input uint16 LsSys_tiLsUsDlyDTrIntrOxCHt_M[16][6];                        */
/*  input uint16 LsSys_tiLsUsDlyDTrIntrOxCHtPnt_M[16];                        */
/*  input boolean LsSys_bLsUsMainOxCDewPtOkLstStrt;                           */
/*  input uint16 LsSys_tiLsUsDlyDTrOxCHt;                                     */
/*  input uint16 LsSys_tiLsUsDlyDTrIntrOxCHt;                                 */
/*  input uint16 LsSys_tiLsUsDlyDTrOxCHtPnt;                                  */
/*  input uint16 LsSys_tiLsUsDlyDTrIntrOxCHtPnt;                              */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseC;                                */
/*  input boolean LsSys_bLsUsMainOxCDewPtNOk;                                 */
/*  output uint16 LsSys_tiLsUsDlyDTrOxCHt;                                    */
/*  output uint16 LsSys_tiLsUsDlyDTrOxCHtPnt;                                 */
/*  output uint16 LsSys_tiLsUsDlyDTrIntrOxCHt;                                */
/*  output uint16 LsSys_tiLsUsDlyDTrIntrOxCHtPnt;                             */
/*  output boolean LsSys_bLsUsMainOxCDewProtReq;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidDetDewPt(void)
{
   boolean bLocalLsSys_bHeatDoneNotIntr;
   uint8   u8LocalCat_old_gain;
   uint8   u8LocalExttCoStrtMes;
   uint8   u8LocalLsSystDsThrLsHeat;
   uint16  u16LocalTempWaterCalcPara;
   uint16  u16LocalCatOldGainCalcPara;
   uint16  u16LocalTempAirCalcPara;
   uint16  u16LocalOxCHt;
   uint16  u16LocalOxCHtPnt;
   uint16  u16LocalTrIntrOxCHt;
   uint16  u16LocalIntrOxCHtPnt;
   sint16  s16LocalExt_tCoStrtMes;
   sint16  s16LocalLsSys_tDsThrLsHeat;
   uint32  u32LocalSum1;
   uint32  u32LocalSum2;
   sint32  s32LocalExttCoStrtMes;
   sint32  s32LocalLsSystDsThrLsHeat;


   VEMS_vidGET(Ext_tCoStrtMes, s16LocalExt_tCoStrtMes);
   VEMS_vidGET(Cat_old_gain, u8LocalCat_old_gain);
   VEMS_vidGET(LsSys_bHeatDoneNotIntr, bLocalLsSys_bHeatDoneNotIntr);
   VEMS_vidGET(LsSys_tDsThrLsHeat, s16LocalLsSys_tDsThrLsHeat);

   s32LocalExttCoStrtMes = (sint32)(s16LocalExt_tCoStrtMes + 40);
   u8LocalExttCoStrtMes =
      (uint8)MATHSRV_udtCLAMP(s32LocalExttCoStrtMes, 0, 255);

   u16LocalTempWaterCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Temperature_water_bkpt_map,
                                  u8LocalExttCoStrtMes,
                                  16);

   u16LocalCatOldGainCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Cat_old_gain_bkpt_map,
                                  u8LocalCat_old_gain,
                                  8);
   u16LocalOxCHt =
      MATHSRV_u16Interp2d(&LsSys_tiLsUsDlyDTrOxCHt_M[0][0],
                          u16LocalTempWaterCalcPara,
                          u16LocalCatOldGainCalcPara,
                          8);
   LsSys_tiLsUsDlyDTrOxCHt = (uint16)MATHSRV_udtMIN(u16LocalOxCHt, 65355);

   u16LocalOxCHtPnt =
      MATHSRV_u16Interp1d(LsSys_tiLsUsDlyDTrOxCHtPnt_M,
                          u16LocalTempWaterCalcPara);
   LsSys_tiLsUsDlyDTrOxCHtPnt = (uint16)MATHSRV_udtMIN(u16LocalOxCHtPnt, 65355);

   s32LocalLsSystDsThrLsHeat = (sint32)(s16LocalLsSys_tDsThrLsHeat + 50);
   u8LocalLsSystDsThrLsHeat =
      (uint8)MATHSRV_udtCLAMP(s32LocalLsSystDsThrLsHeat, 0, 255);

   u16LocalTempAirCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Temperature_air_bkpt_map,
                                  u8LocalLsSystDsThrLsHeat,
                                  6);
   u16LocalTrIntrOxCHt =
      MATHSRV_u16Interp2d(&LsSys_tiLsUsDlyDTrIntrOxCHt_M[0][0],
                          u16LocalTempWaterCalcPara,
                          u16LocalTempAirCalcPara,
                          6);
   LsSys_tiLsUsDlyDTrIntrOxCHt = (uint16)MATHSRV_udtMIN(u16LocalTrIntrOxCHt,
                                                        65355);

   u16LocalIntrOxCHtPnt =
      MATHSRV_u16Interp1d(LsSys_tiLsUsDlyDTrIntrOxCHtPnt_M,
                          u16LocalTempWaterCalcPara);
   LsSys_tiLsUsDlyDTrIntrOxCHtPnt = (uint16)MATHSRV_udtMIN(u16LocalIntrOxCHtPnt,
                                                           65356);

   if (LsSys_bLsUsMainOxCDewPtOkLstStrt != 0)
   {
      u32LocalSum1 = LsSys_tiLsUsDlyDTrOxCHt;
      u32LocalSum2 = LsSys_tiLsUsDlyDTrIntrOxCHt;
   }
   else
   {
      u32LocalSum1 = LsSys_tiLsUsDlyDTrOxCHt + LsSys_tiLsUsDlyDTrOxCHtPnt;
      u32LocalSum2 = ( LsSys_tiLsUsDlyDTrIntrOxCHt
                     + LsSys_tiLsUsDlyDTrIntrOxCHtPnt);
   }

   if (  (  (  (LsSys_tiLsUsDlyMainOxCPhaseC > u32LocalSum1)
            && (bLocalLsSys_bHeatDoneNotIntr != 0))
         || (  (LsSys_tiLsUsDlyMainOxCPhaseC > u32LocalSum2)
            && (bLocalLsSys_bHeatDoneNotIntr == 0)))
      && (LsSys_bLsUsMainOxCDewPtNOk == 0))
   {
      VEMS_vidSET(LsSys_bLsUsMainOxCDewProtReq, 0);
   }
   else
   {
      VEMS_vidSET(LsSys_bLsUsMainOxCDewProtReq, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidDlyDewPt                                    */
/* !Description :  Lorsque le point de rosée est considéré comme franchi, un  */
/*                 compteur s’active afin de connaître depuis combien de temps*/
/*                 le point de rosée est franchi et est entretenu par les gaz */
/*                 d’échapements                                              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2US_vidDlyDewTranOkStall();                      */
/*  input boolean LsSys_bLsUsMainOxCDewProtReq;                               */
/*  input uint16 LsSys_tiLsUsMainOxCDlyDewTranOk;                             */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 HEATSENO2US_stEngPrev;                                        */
/*  output uint16 LsSys_tiLsUsMainOxCDlyDewTranOk;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidDlyDewPt(void)
{
   boolean bLocalLsSys_bDsMainOxCDewProtReq;
   uint8   u8LocalCoPTSt_stEng;
   uint32  u32LocalTranOk;


   VEMS_vidGET(LsSys_bLsUsMainOxCDewProtReq, bLocalLsSys_bDsMainOxCDewProtReq);
   if (bLocalLsSys_bDsMainOxCDewProtReq != 0)
   {
      LsSys_tiLsUsMainOxCDlyDewTranOk = 0;
   }
   else
   {
      u32LocalTranOk = (uint32)(LsSys_tiLsUsMainOxCDlyDewTranOk + 1);
      LsSys_tiLsUsMainOxCDlyDewTranOk = (uint16)MATHSRV_udtMIN(u32LocalTranOk,
                                                               65355);
   }
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if (  (u8LocalCoPTSt_stEng != Engine_Running)
      && (HEATSENO2US_stEngPrev == Engine_Running))
   {
      HEATSENO2US_vidDlyDewTranOkStall();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidDlyDewTranOkStall                           */
/* !Description :  Détermination de la durée pendant laquelle la sonde à      */
/*                 oxygène a été chauffée par les gaz d’échappements depuis le*/
/*                 franchissement du point de rosée                           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 LsSys_tiLsUsMainOxCDlyDewTranOk;                             */
/*  output uint16 LsSys_tiLsUsDlyDewTranOkStall;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidDlyDewTranOkStall(void)
{
   LsSys_tiLsUsDlyDewTranOkStall =
      (uint16)MATHSRV_udtMIN(LsSys_tiLsUsMainOxCDlyDewTranOk, 65355);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidFastLightOff                                */
/* !Description :  Condition d'activation du Fast Light Off                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void HEATSENO2US_vidDisableFLO();                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoStrtMes;                                              */
/*  input uint8 LsSys_tCoolFLOEna_T[6];                                       */
/*  input uint8 LsSys_bTCoolFLOEna_M;                                         */
/*  input sint16 Ext_tDsThrStrtMes;                                           */
/*  input uint8 LsSys_tAirFLOEna_T[6];                                        */
/*  input uint8 LsSys_bTAirFLOEna_M;                                          */
/*  input uint32 Ext_dstVehMes;                                               */
/*  input uint16 LsSys_VehDstFLOEna_T[6];                                     */
/*  input uint8 LsSys_bVehDstFLOEna_M;                                        */
/*  input uint32 Time_since_stall;                                            */
/*  input boolean LsSys_bLsUsTCoolFLOEna;                                     */
/*  input boolean LsSys_bLsUsTAirFLOEna;                                      */
/*  input boolean LsSys_bLsUsVehDstFLOEna;                                    */
/*  input boolean LsSys_bLsUsMainOxCDewPtOkLstStrt;                           */
/*  input boolean LsSys_bLsUsMaxDlyStopFLOEna_C;                              */
/*  input uint32 LsSys_tiLsUsMaxDlyStopFLOEna_C;                              */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input uint8 HEATSENO2US_u8MainOxCHeatPrev;                                */
/*  input boolean LsSys_bLsUsMainOxCDiFLO;                                    */
/*  output boolean LsSys_bLsUsTCoolFLOEna;                                    */
/*  output boolean LsSys_bLsUsTAirFLOEna;                                     */
/*  output boolean LsSys_bLsUsVehDstFLOEna;                                   */
/*  output boolean LsSys_bLsUsMainOxcAcvFLO;                                  */
/*  output boolean LsSys_bLsUsMainOxCHeatFloEna;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidFastLightOff(void)
{
   boolean bLocalInhLsUsMainOxCHeatFLO;
   boolean bLocalLsUsMainOxCHeatFloEna;
   uint8   u8LocalLsSys_stLsUsMainOxCHeat;
   uint8   u8LocalIndex;
   uint16  u16LocalCalcPara;
   sint16  s16LocalExt_tCoStrtMes;
   sint16  s16LoacalExt_tDsThrStrtMes;
   uint32  u32LoacalExt_dstVehMes;
   uint32  u32LocalTime_since_stall;
   sint32  s32LocalExt_tCoStrtMes;
   sint32  s32LoacalExt_tDsThrStrtMes;

   VEMS_vidGET(Ext_tCoStrtMes, s16LocalExt_tCoStrtMes);
   s32LocalExt_tCoStrtMes = (sint32)(s16LocalExt_tCoStrtMes + 40);
   s32LocalExt_tCoStrtMes = MATHSRV_udtCLAMP(s32LocalExt_tCoStrtMes, 0, 254);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(LsSys_tCoolFLOEna_T,
                                  (uint8)s32LocalExt_tCoStrtMes,
                                  6);
   u16LocalCalcPara = (uint16)(u16LocalCalcPara / 256);
   u8LocalIndex = (uint8)(u16LocalCalcPara);
   u8LocalIndex = (uint8)(0x01 << u8LocalIndex);
   if ((LsSys_bTCoolFLOEna_M & u8LocalIndex) == u8LocalIndex)
   {
      LsSys_bLsUsTCoolFLOEna = 1;
   }
   else
   {
      LsSys_bLsUsTCoolFLOEna = 0;
   }

   VEMS_vidGET(Ext_tDsThrStrtMes, s16LoacalExt_tDsThrStrtMes);
   s32LoacalExt_tDsThrStrtMes = (sint32)(s16LoacalExt_tDsThrStrtMes + 50);
   s32LoacalExt_tDsThrStrtMes = MATHSRV_udtCLAMP(s32LoacalExt_tDsThrStrtMes,
                                                 0,
                                                 250);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(LsSys_tAirFLOEna_T,
                                  (uint8)s32LoacalExt_tDsThrStrtMes,
                                  6);
   u16LocalCalcPara = (uint16)(u16LocalCalcPara / 256);
   u8LocalIndex = (uint8)(u16LocalCalcPara);
   u8LocalIndex = (uint8)(0x01 << u8LocalIndex);
   if ((LsSys_bTAirFLOEna_M & u8LocalIndex) == u8LocalIndex)
   {
      LsSys_bLsUsTAirFLOEna = 1;
   }
   else
   {
      LsSys_bLsUsTAirFLOEna = 0;
   }

   VEMS_vidGET(Ext_dstVehMes, u32LoacalExt_dstVehMes);
   u32LoacalExt_dstVehMes = u32LoacalExt_dstVehMes / 100;
   u32LoacalExt_dstVehMes = MATHSRV_udtMIN(u32LoacalExt_dstVehMes, 2000);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(LsSys_VehDstFLOEna_T,
                                  (uint16)u32LoacalExt_dstVehMes,
                                  6);
   u16LocalCalcPara = (uint16)(u16LocalCalcPara / 256);
   u8LocalIndex = (uint8)(u16LocalCalcPara);
   u8LocalIndex = (uint8)(0x01 << u8LocalIndex);
   if ((LsSys_bVehDstFLOEna_M & u8LocalIndex) == u8LocalIndex)
   {
      LsSys_bLsUsVehDstFLOEna = 1;
   }
   else
   {
      LsSys_bLsUsVehDstFLOEna = 0;
   }

   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
   bLocalInhLsUsMainOxCHeatFLO = GDGAR_bGetFRM(FRM_FRM_INHLSUSMAINOXCHEATFLO);

   bLocalLsUsMainOxCHeatFloEna = 0;
   if (  (LsSys_bLsUsTCoolFLOEna != 0)
      && (LsSys_bLsUsTAirFLOEna != 0)
      && (LsSys_bLsUsVehDstFLOEna != 0)
      && (LsSys_bLsUsMainOxCDewPtOkLstStrt != 0)
      && (  (LsSys_bLsUsMaxDlyStopFLOEna_C == 0)
         || (u32LocalTime_since_stall < LsSys_tiLsUsMaxDlyStopFLOEna_C))
      && (bLocalInhLsUsMainOxCHeatFLO == 0))
   {
      LsSys_bLsUsMainOxcAcvFLO = 1;
      VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
      if (  (HEATSENO2US_u8MainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_D)
         && (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_E))
      {
         HEATSENO2US_vidDisableFLO();
      }
      if (LsSys_bLsUsMainOxCDiFLO == 0)
      {
         bLocalLsUsMainOxCHeatFloEna = 1;
      }
   }
   else
   {
      LsSys_bLsUsMainOxcAcvFLO = 0;
   }
   VEMS_vidSET(LsSys_bLsUsMainOxCHeatFloEna, bLocalLsUsMainOxCHeatFloEna);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidDisableFLO                                  */
/* !Description :  Lorsque le moteur se trouve dans le phase d’un redémarrage */
/*                 STT, le Fast Light Off n’est plus autorisée et ceci        */
/*                 jusqu’au prochain Driving Cycle                            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean LsSys_bLsUsMainOxCDiFLO;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidDisableFLO(void)
{
   LsSys_bLsUsMainOxCDiFLO = 1;
}
/*------------------------------- end of file --------------------------------*/