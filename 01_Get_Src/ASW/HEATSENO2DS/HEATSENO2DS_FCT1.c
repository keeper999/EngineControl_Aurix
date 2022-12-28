/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DS                                             */
/* !Description     : HEATSENO2DS Component                                   */
/*                                                                            */
/* !Module          : HEATSENO2DS                                             */
/* !Description     : GESTION CHAUFFAGE SONDE AVAL                            */
/*                                                                            */
/* !File            : HEATSENO2DS_FCT1.C                                      */
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
/*   1 / HEATSENO2DS_vidInitOutput                                            */
/*   2 / HEATSENO2DS_vidLsDsDewPt                                             */
/*   3 / HEATSENO2DS_vidDetDewPtRev                                           */
/*   4 / HEATSENO2DS_vidDetDewPt                                              */
/*   5 / HEATSENO2DS_vidDlyDewPt                                              */
/*   6 / HEATSENO2DS_vidDlyDewTranOkStall                                     */
/*   7 / HEATSENO2DS_vidMgrFastTran                                           */
/*   8 / HEATSENO2DS_vidMgrMidTran                                            */
/*   9 / HEATSENO2DS_vidMgrSlowTran                                           */
/*   10 / HEATSENO2DS_vidLsDsMgrHeatState                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5421274 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#061098                                         */
/* !OtherRefs   : VEMS V02 ECU#064424                                         */
/* !OtherRefs   : VEMS V02 ECU#064562                                         */
/* !OtherRefs   : VEMS V02 ECU#066568                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/HEATSENO2DS/HEATSENO2DS_$*/
/* $Revision::   1.18     $$Author::   wbouach        $$Date::   25 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   25 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2DS.h"
#include "HEATSENO2DS_L.h"
#include "HEATSENO2DS_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidInitOutput                                  */
/* !Description :  Initialisation des variables au reset                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsSys_bAcvLsDsMainOxCHeatLih;                              */
/*  output boolean LsSys_bLsDsMainOxCDewProtReq;                              */
/*  output st70 LsSys_stLsDsMainOxCHeat;                                      */
/*  output uint16 LsSys_tiLsDsDlyMainOxCPhaseC;                               */
/*  output uint16 LsSys_tiLsDsDlyMainOxCPhaseD;                               */
/*  output uint8 LsSys_tiLsDsBoostProtReq;                                    */
/*  output uint8 HEATSENO2DS_stEngPrev;                                       */
/*  output uint16 LsSys_tiLsDsMainOxCDlyDewTranOk;                            */
/*  output uint16 LsSys_tiLsDsDlyAcvHeatLih;                                  */
/*  output uint8 HEATSENO2DS_u8MainOxCHeatPrev;                               */
/*  output uint8 HEATSENO2DS_u8OxCHeatPrevslow;                               */
/*  output boolean HEATSENO2DS_bUBattAcvHeatLih;                              */
/*  output boolean HEATSENO2DS_bTimeout1;                                     */
/*  output boolean LsSys_bLsDsMainOxCAcvHeatHi;                               */
/*  output boolean HEATSENO2DS_bTimerInit;                                    */
/*  output boolean LsSys_bLsDsMainOxCHeatLoEnd;                               */
/*  output boolean LsSys_bLsDsBoostEnd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidInitOutput(void)
{
   /* Outputs Initialization */
   VEMS_vidSET(LsSys_bAcvLsDsMainOxCHeatLih, 0);
   VEMS_vidSET(LsSys_bLsDsMainOxCDewProtReq, 0);
   VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);

   /* Internals initialization */
   LsSys_tiLsDsDlyMainOxCPhaseC = 0;
   LsSys_tiLsDsDlyMainOxCPhaseD = 0;
   LsSys_tiLsDsBoostProtReq = 0;
   HEATSENO2DS_stEngPrev = 0;
   LsSys_tiLsDsMainOxCDlyDewTranOk = 0;
   LsSys_tiLsDsDlyAcvHeatLih = 0;
   HEATSENO2DS_u8MainOxCHeatPrev = 0;
   HEATSENO2DS_u8OxCHeatPrevslow = 0;
   HEATSENO2DS_bUBattAcvHeatLih = 0;
   HEATSENO2DS_bTimeout1 = 0;
   LsSys_bLsDsMainOxCAcvHeatHi = 1;
   HEATSENO2DS_bTimerInit = 0;
   LsSys_bLsDsMainOxCHeatLoEnd = 0;
   LsSys_bLsDsBoostEnd = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidLsDsDewPt                                   */
/* !Description :  Détection du passage du point de rosée pour la sonde aval  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_002.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DS_vidDetDewPtRev();                            */
/*  extf argret void HEATSENO2DS_vidDetDewPt();                               */
/*  extf argret void HEATSENO2DS_vidDlyDewPt();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidLsDsDewPt(void)
{
   HEATSENO2DS_vidDetDewPtRev();
   HEATSENO2DS_vidDetDewPt();
   HEATSENO2DS_vidDlyDewPt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidDetDewPtRev                                 */
/* !Description :  Déterminer si le point de rosée a été franchi à l'envers   */
/*                 depuis la fin du dernie rarrêt moteur                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 LsSys_tiLsDsDlyDewTranOkStall;                               */
/*  input uint16 LsSys_tiLsDsDlyDewTranOkStall_T[8];                          */
/*  input uint16 LsSys_tiLsDsDlyDewTranNotOk_M[8];                            */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean LsSys_bLsDsDetRTStall;                                      */
/*  input uint16 LsSys_tiLsDsDlyDewTranNotOk;                                 */
/*  input uint32 Time_since_stall;                                            */
/*  output boolean LsSys_bLsDsMainOxCDewPtOkLstStrt;                          */
/*  output uint16 LsSys_tiLsDsDlyDewTranNotOk;                                */
/*  output boolean LsSys_bLsDsMainOxCDewPtNOk;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidDetDewPtRev(void)
{
   uint8  u8LocalVehicle_active_state;
   uint16 u16LocalCalcPara;
   uint16 u16LocalTrNotOk;
   uint16 u16LocalTrNotOkCalc;
   uint32 u32LocalTime_since_stall;


   if (LsSys_tiLsDsDlyDewTranOkStall > 0)
   {
      LsSys_bLsDsMainOxCDewPtOkLstStrt = 1;
   }
   else
   {
      LsSys_bLsDsMainOxCDewPtOkLstStrt = 0;
   }
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(LsSys_tiLsDsDlyDewTranOkStall_T,
                                   LsSys_tiLsDsDlyDewTranOkStall,
                                   8);
   u16LocalTrNotOk = MATHSRV_u16Interp1d(LsSys_tiLsDsDlyDewTranNotOk_M,
                                         u16LocalCalcPara);
   LsSys_tiLsDsDlyDewTranNotOk = (uint16)MATHSRV_udtMIN(u16LocalTrNotOk, 65355);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (  (u8LocalVehicle_active_state == VS_STALL)
      && (LsSys_bLsDsDetRTStall != 0))
   {
      u16LocalTrNotOkCalc = (uint16)(LsSys_tiLsDsDlyDewTranNotOk / 10);
      VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
      if (u32LocalTime_since_stall > u16LocalTrNotOkCalc)
      {
         LsSys_bLsDsMainOxCDewPtNOk = 1;
      }
      else
      {
         LsSys_bLsDsMainOxCDewPtNOk = 0;
      }
   }
   else
   {
      LsSys_bLsDsMainOxCDewPtNOk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidDetDewPt                                    */
/* !Description :  Détermination du passage du  du point de rosée en fonction */
/*                 de la durée du chauffage de protection                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoStrtMes;                                              */
/*  input sint16 LsSys_tDsThrLsHeat;                                          */
/*  input uint8 Temperature_water_bkpt_map[16];                               */
/*  input uint8 Temperature_air_bkpt_map[6];                                  */
/*  input uint8 Cat_old_gain;                                                 */
/*  input uint8 Cat_old_gain_bkpt_map[8];                                     */
/*  input uint16 LsSys_tiLsDsDlyDTrOxCHt_M[16][8];                            */
/*  input uint16 LsSys_tiLsDsDlyDTrOxCHtPnt_M[16];                            */
/*  input uint16 LsSys_tiLsDsDlyDTrIntrOxCHt_M[16][6];                        */
/*  input uint16 LsSys_tiLsDsDlyDTrIntrOxCHtPnt_M[16];                        */
/*  input boolean LsSys_bLsDsMainOxCDewPtOkLstStrt;                           */
/*  input uint16 LsSys_tiLsDsDlyDTrOxCHt;                                     */
/*  input uint16 LsSys_tiLsDsDlyDTrIntrOxCHt;                                 */
/*  input uint16 LsSys_tiLsDsDlyDTrOxCHtPnt;                                  */
/*  input uint16 LsSys_tiLsDsDlyDTrIntrOxCHtPnt;                              */
/*  input boolean LsSys_bHeatDoneNotIntr;                                     */
/*  input uint16 LsSys_tiLsDsDlyMainOxCPhaseC;                                */
/*  input boolean LsSys_bLsDsMainOxCDewPtNOk;                                 */
/*  output uint16 LsSys_tiLsDsDlyDTrOxCHt;                                    */
/*  output uint16 LsSys_tiLsDsDlyDTrOxCHtPnt;                                 */
/*  output uint16 LsSys_tiLsDsDlyDTrIntrOxCHt;                                */
/*  output uint16 LsSys_tiLsDsDlyDTrIntrOxCHtPnt;                             */
/*  output boolean LsSys_bLsDsMainOxCDewProtReq;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidDetDewPt(void)
{
   boolean bLocalLsSys_bHeatDoneNotIntr;
   uint8   u8LocalCat_old_gain;
   uint8   u8LocalExttCoStrtMes;
   uint8   u8LocalLsSys_tDsThrLsHeat;
   uint16  u16LocalTempWaterCalcPara;
   uint16  u16LocalTempAirCalcPara;
   uint16  u16LocalCatOldGainCalcPara;
   uint16  u16LocaltiLsDsDlyDTrOxCHt;
   uint16  u16LocaltiLsDsDlyDTrOxCHtPnt;
   uint16  u16LocaltiLsDsDlyDTrIntrOxCHt;
   uint16  u16LocaltiLsDsDlyDTrIntrOxCHtPnt;
   sint16  s16LocalExt_tCoStrtMes;
   sint16  s16LocalLsSys_tDsThrLsHeat;
   uint32  u32LocalSum1;
   uint32  u32LocalSum2;
   sint32  s32LocalExttCoStrtMes;
   sint32  s32LocalLsSys_tDsThrLsHeat;


   VEMS_vidGET(Ext_tCoStrtMes, s16LocalExt_tCoStrtMes);
   VEMS_vidGET(LsSys_tDsThrLsHeat, s16LocalLsSys_tDsThrLsHeat);
   s32LocalExttCoStrtMes = (sint32)(s16LocalExt_tCoStrtMes + 40);
   u8LocalExttCoStrtMes =
      (uint8)MATHSRV_udtCLAMP(s32LocalExttCoStrtMes, 0, 255);
   u16LocalTempWaterCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Temperature_water_bkpt_map,
                                  u8LocalExttCoStrtMes,
                                  16);
   s32LocalLsSys_tDsThrLsHeat = (sint32)(s16LocalLsSys_tDsThrLsHeat + 50);
   u8LocalLsSys_tDsThrLsHeat =
      (uint8)MATHSRV_udtCLAMP(s32LocalLsSys_tDsThrLsHeat, 0, 255);
   u16LocalTempAirCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Temperature_air_bkpt_map,
                                  u8LocalLsSys_tDsThrLsHeat,
                                  6);
   VEMS_vidGET(Cat_old_gain, u8LocalCat_old_gain);
   u16LocalCatOldGainCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Cat_old_gain_bkpt_map,
                                  u8LocalCat_old_gain,
                                  8);
   u16LocaltiLsDsDlyDTrOxCHt =
      MATHSRV_u16Interp2d(&LsSys_tiLsDsDlyDTrOxCHt_M[0][0],
                          u16LocalTempWaterCalcPara,
                          u16LocalCatOldGainCalcPara,
                          8);
   LsSys_tiLsDsDlyDTrOxCHt =
      (uint16)MATHSRV_udtMIN(u16LocaltiLsDsDlyDTrOxCHt, 65355);

   u16LocaltiLsDsDlyDTrOxCHtPnt =
      MATHSRV_u16Interp1d(LsSys_tiLsDsDlyDTrOxCHtPnt_M,
                          u16LocalTempWaterCalcPara);
   LsSys_tiLsDsDlyDTrOxCHtPnt =
      (uint16)MATHSRV_udtMIN(u16LocaltiLsDsDlyDTrOxCHtPnt, 65355);

   u16LocaltiLsDsDlyDTrIntrOxCHt =
      MATHSRV_u16Interp2d(&LsSys_tiLsDsDlyDTrIntrOxCHt_M[0][0],
                          u16LocalTempWaterCalcPara,
                          u16LocalTempAirCalcPara,
                          6);
   LsSys_tiLsDsDlyDTrIntrOxCHt =
      (uint16)MATHSRV_udtMIN(u16LocaltiLsDsDlyDTrIntrOxCHt, 65355);

   u16LocaltiLsDsDlyDTrIntrOxCHtPnt =
      MATHSRV_u16Interp1d(LsSys_tiLsDsDlyDTrIntrOxCHtPnt_M,
                          u16LocalTempWaterCalcPara);
   LsSys_tiLsDsDlyDTrIntrOxCHtPnt =
      (uint16)MATHSRV_udtMIN(u16LocaltiLsDsDlyDTrIntrOxCHtPnt, 65356);

   if (LsSys_bLsDsMainOxCDewPtOkLstStrt != 0)
   {
      u32LocalSum1 = LsSys_tiLsDsDlyDTrOxCHt;
      u32LocalSum2 = LsSys_tiLsDsDlyDTrIntrOxCHt;
   }
   else
   {
      u32LocalSum1 = LsSys_tiLsDsDlyDTrOxCHt + LsSys_tiLsDsDlyDTrOxCHtPnt;
      u32LocalSum2 = ( LsSys_tiLsDsDlyDTrIntrOxCHt
                     + LsSys_tiLsDsDlyDTrIntrOxCHtPnt);
   }

   VEMS_vidGET(LsSys_bHeatDoneNotIntr, bLocalLsSys_bHeatDoneNotIntr);
   if (  (  (  (LsSys_tiLsDsDlyMainOxCPhaseC > u32LocalSum1)
            && (bLocalLsSys_bHeatDoneNotIntr != 0))
         || (  (LsSys_tiLsDsDlyMainOxCPhaseC > u32LocalSum2)
            && (bLocalLsSys_bHeatDoneNotIntr == 0)))
      && ( LsSys_bLsDsMainOxCDewPtNOk == 0 ))
   {
      VEMS_vidSET(LsSys_bLsDsMainOxCDewProtReq, 0);
   }
   else
   {
      VEMS_vidSET(LsSys_bLsDsMainOxCDewProtReq, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidDlyDewPt                                    */
/* !Description :  Lorsque le point de rosée est considéré comme franchi, un  */
/*                 compteur s’active afin de connaître depuis combien de temps*/
/*                 le point de rosée est franchi et est entretenu par les gaz */
/*                 d’échappements                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DS_vidDlyDewTranOkStall();                      */
/*  input boolean LsSys_bLsDsMainOxCDewProtReq;                               */
/*  input uint16 LsSys_tiLsDsMainOxCDlyDewTranOk;                             */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 HEATSENO2DS_stEngPrev;                                        */
/*  output uint16 LsSys_tiLsDsMainOxCDlyDewTranOk;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidDlyDewPt(void)
{
   boolean bLocalLsSys_bDsMainOxCDewProtReq;
   uint8   u8LocalCoPTSt_stEng;
   uint32  u32LocalDlyDewTranOk;


   VEMS_vidGET(LsSys_bLsDsMainOxCDewProtReq, bLocalLsSys_bDsMainOxCDewProtReq);
   if (bLocalLsSys_bDsMainOxCDewProtReq != 0)
   {
      LsSys_tiLsDsMainOxCDlyDewTranOk = 0;
   }
   else
   {
      u32LocalDlyDewTranOk = LsSys_tiLsDsMainOxCDlyDewTranOk + 1;
      LsSys_tiLsDsMainOxCDlyDewTranOk =
         (uint16)MATHSRV_udtMIN(u32LocalDlyDewTranOk, 65355);
   }
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if (  (u8LocalCoPTSt_stEng != Engine_Running)
      && (HEATSENO2DS_stEngPrev == Engine_Running))
   {
      HEATSENO2DS_vidDlyDewTranOkStall();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidDlyDewTranOkStall                           */
/* !Description :  Durée pendant laquelle la sonde à oxygène a été chauffée   */
/*                 par les gaz d’échappements depuis le franchissement du     */
/*                 point de rosée                                             */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 LsSys_tiLsDsMainOxCDlyDewTranOk;                             */
/*  output uint16 LsSys_tiLsDsDlyDewTranOkStall;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidDlyDewTranOkStall(void)
{
   LsSys_tiLsDsDlyDewTranOkStall =
      (uint16)MATHSRV_udtMIN(LsSys_tiLsDsMainOxCDlyDewTranOk, 65355);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidMgrFastTran                                 */
/* !Description :  Cette transition consiste a réfugier le chauffage sonde    */
/*                 dans un mode dégradé dans le  cas d'une surtension         */
/*                 batterie.                                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_003.02                                     */
/*                 VEMS_R_08_03331_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean HEATSENO2DS_bUBattAcvHeatLih;                               */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 LsSys_uBattAcvHeatLih_C;                                      */
/*  input uint8 LsSys_tiDlyAcvHeatLih_C;                                      */
/*  input uint16 LsSys_tiLsDsDlyAcvHeatLih;                                   */
/*  input boolean HEATSENO2DS_bTimeout1;                                      */
/*  output boolean HEATSENO2DS_bUBattAcvHeatLih;                              */
/*  output uint16 LsSys_tiLsDsDlyAcvHeatLih;                                  */
/*  output boolean HEATSENO2DS_bTimeout1;                                     */
/*  output boolean LsSys_bAcvLsDsMainOxCHeatLih;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidMgrFastTran(void)
{
   boolean bLocalUBattAcvHeatLihPrev;
   boolean bLocalInhLsDsMainOxCHeat;
   uint16  u16LocalLsSystiLsDsDlyAcvHeatLih;
   sint16  s16LocalExt_uBattMes;


   bLocalUBattAcvHeatLihPrev = HEATSENO2DS_bUBattAcvHeatLih;
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   if (s16LocalExt_uBattMes > (sint16)(LsSys_uBattAcvHeatLih_C * 10))
   {
      HEATSENO2DS_bUBattAcvHeatLih = 1;
   }
   else
   {
      HEATSENO2DS_bUBattAcvHeatLih = 0;
   }
   if (  (HEATSENO2DS_bUBattAcvHeatLih != 0)
      && (bLocalUBattAcvHeatLihPrev == 0) )
   {
      LsSys_tiLsDsDlyAcvHeatLih = (uint16)(LsSys_tiDlyAcvHeatLih_C * 4);
      if (LsSys_tiLsDsDlyAcvHeatLih == 0)
      {
         HEATSENO2DS_bTimeout1 = 1;
      }
      else
      {
         HEATSENO2DS_bTimeout1 = 0;
      }
   }
   else
   {
      if (LsSys_tiLsDsDlyAcvHeatLih > 0)
      {
         u16LocalLsSystiLsDsDlyAcvHeatLih = (uint16)( LsSys_tiLsDsDlyAcvHeatLih
                                                    - 1);
         LsSys_tiLsDsDlyAcvHeatLih =
            (uint16)MATHSRV_udtMIN(u16LocalLsSystiLsDsDlyAcvHeatLih, 1023);
         if (LsSys_tiLsDsDlyAcvHeatLih == 0)
         {
            HEATSENO2DS_bTimeout1 = 1;
         }
         else
         {
            HEATSENO2DS_bTimeout1 = 0;
         }
      }
   }

   bLocalInhLsDsMainOxCHeat = GDGAR_bGetFRM(FRM_FRM_INHLSDSMAINOXCHEAT);
   if (  (bLocalInhLsDsMainOxCHeat != 0)
      || (  (HEATSENO2DS_bTimeout1 != 0)
         && (HEATSENO2DS_bUBattAcvHeatLih != 0)))
   {
      VEMS_vidSET(LsSys_bAcvLsDsMainOxCHeatLih, 1);
   }
   else
   {
      VEMS_vidSET(LsSys_bAcvLsDsMainOxCHeatLih, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidMgrMidTran                                  */
/* !Description :  Calcul de toutes les transitions ayant un chauffage non nul*/
/*                 et détermination du délai avant réautorisation du chauffage*/
/*                 maximal                                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_003.02                                     */
/*                 VEMS_R_08_03331_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DS_vidTranAToCOrAToE();                         */
/*  extf argret void HEATSENO2DS_vidTranEToF();                               */
/*  extf argret void HEATSENO2DS_vidTranCToEOrDToE();                         */
/*  extf argret void HEATSENO2DS_vidTranCToD();                               */
/*  extf argret void HEATSENO2DS_vidTranC1toC2();                             */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  input boolean HEATSENO2DS_bTimerInit;                                     */
/*  input uint8 HEATSENO2DS_u8MainOxCHeatPrev;                                */
/*  input uint16 LsSys_tiLsDsDlyWaitSecHeatHi_C;                              */
/*  input uint32 LsSys_tiLsDsDlySinceLstHeatHi;                               */
/*  output boolean HEATSENO2DS_bTimerInit;                                    */
/*  output uint32 LsSys_tiLsDsDlySinceLstHeatHi;                              */
/*  output boolean LsSys_bLsDsMainOxCAcvHeatHi;                               */
/*  output uint8 HEATSENO2DS_u8MainOxCHeatPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidMgrMidTran(void)
{
   boolean bLocalTimerInitPrev;
   uint8   u8LocalLsSys_stLsDsMainOxCHeat;
   uint32  u32LocalLsDsDlySinceLstHeatHi;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);

   bLocalTimerInitPrev = HEATSENO2DS_bTimerInit;
   if (  (u8LocalLsSys_stLsDsMainOxCHeat != LSDSMAINOXCHEAT_PHASE_D)
      && (HEATSENO2DS_u8MainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_D))
   {
      HEATSENO2DS_bTimerInit = 1;
   }
   else
   {
      HEATSENO2DS_bTimerInit = 0;
   }

   /* Timer */
   if (  (HEATSENO2DS_bTimerInit != 0)
      && (bLocalTimerInitPrev == 0))
   {
      LsSys_tiLsDsDlySinceLstHeatHi = (uint32)( LsSys_tiLsDsDlyWaitSecHeatHi_C
                                              * 10);
      if (LsSys_tiLsDsDlySinceLstHeatHi == 0)
      {
         LsSys_bLsDsMainOxCAcvHeatHi = 1;
      }
      else
      {
         LsSys_bLsDsMainOxCAcvHeatHi = 0;
      }
   }
   else
   {
      if (LsSys_tiLsDsDlySinceLstHeatHi > 0)
      {
         u32LocalLsDsDlySinceLstHeatHi = LsSys_tiLsDsDlySinceLstHeatHi - 1;
         LsSys_tiLsDsDlySinceLstHeatHi =
            MATHSRV_udtMIN(u32LocalLsDsDlySinceLstHeatHi, 655359);
         if (LsSys_tiLsDsDlySinceLstHeatHi == 0)
         {
            LsSys_bLsDsMainOxCAcvHeatHi = 1;
         }
         else
         {
            LsSys_bLsDsMainOxCAcvHeatHi = 0;
         }
      }
   }

   if (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_A)
   {
      /* 02_Tran_AtoC_or_AtoE */
      HEATSENO2DS_vidTranAToCOrAToE();
   }
   else
   {
      if (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_E)
      {
         /* 05_Tran_EtoF */
         HEATSENO2DS_vidTranEToF();
      }
      else
      {
         if (  (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_C1)
            || (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_C2)
            || (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_D))
         {
            /* 04_Tran_CtoE_or_DtoE */
            HEATSENO2DS_vidTranCToEOrDToE();
            if (  (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_C1)
               || (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_C2))
            {
               /* 03_Tran_CtoD */
               HEATSENO2DS_vidTranCToD();
            }
            if (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_C1)
            {
               /* 06_Tran_C1toC2 */
               HEATSENO2DS_vidTranC1toC2();
            }
         }
      }
   }
   HEATSENO2DS_u8MainOxCHeatPrev = u8LocalLsSys_stLsDsMainOxCHeat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidMgrSlowTran                                 */
/* !Description :  Lorsque le chauffage réduit reste activé trop longtemps, on*/
/*                 passe en chauffage coupé  afin de réduire la consommation  */
/*                 électrique                                                 */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DS_vidTranFToA();                               */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  output uint8 HEATSENO2DS_u8OxCHeatPrevslow;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidMgrSlowTran(void)
{
   uint8 u8LocalLsSys_stLsDsMainOxCHeat;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);
   if (u8LocalLsSys_stLsDsMainOxCHeat == LSDSMAINOXCHEAT_PHASE_F)
   {
      HEATSENO2DS_vidTranFToA();
   }
   HEATSENO2DS_u8OxCHeatPrevslow = u8LocalLsSys_stLsDsMainOxCHeat;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidLsDsMgrHeatState                            */
/* !Description :  Cette fonction contient l’automate de gestion des phases de*/
/*                 chauffage de la sonde O2 aval                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_012.02                                     */
/*                 VEMS_R_08_03331_013.01                                     */
/*                 VEMS_R_08_03331_014.02                                     */
/*                 VEMS_R_08_03331_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  input boolean LsSys_bAcvLsDsMainOxCHeatLih;                               */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 HEATSENO2DS_stEngPrev;                                        */
/*  input boolean LsSys_bLsDsMainOxCHeatEna;                                  */
/*  input boolean LsSys_bLsDsBoostEnd;                                        */
/*  input boolean LsSys_bLsDsMainOxCHeatHotEna;                               */
/*  input boolean LsSys_bLsDsMainOxCHeatProtEnd;                              */
/*  input boolean LsSys_bLsDsMainOxCHeatHiEnd;                                */
/*  input uint16 LsSys_tiLsDsDlyMainOxCPhaseC;                                */
/*  input uint8 LsSys_tiLsDsBoostProtReq;                                     */
/*  input uint16 LsSys_tiLsDsDlyMainOxCPhaseD;                                */
/*  input boolean LsSys_bAcvLsDsMainOxCHeatLo;                                */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean LsSys_bLsDsMainOxCHeatLoEnd;                                */
/*  output st70 LsSys_stLsDsMainOxCHeat;                                      */
/*  output uint16 LsSys_tiLsDsDlyMainOxCPhaseC;                               */
/*  output uint16 LsSys_tiLsDsDlyMainOxCPhaseD;                               */
/*  output uint8 LsSys_tiLsDsBoostProtReq;                                    */
/*  output uint8 HEATSENO2DS_stEngPrev;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidLsDsMgrHeatState(void)
{
   boolean bLocalAcvLsDsMainOxCHeatLih;
   uint8   u8LocalLsSys_stLsDsMainOxCHeat;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalVehicle_active_state;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);
   VEMS_vidGET(LsSys_bAcvLsDsMainOxCHeatLih, bLocalAcvLsDsMainOxCHeatLih);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   switch (u8LocalLsSys_stLsDsMainOxCHeat)
   {
      case LSDSMAINOXCHEAT_PHASE_A:
         if (  (u8LocalCoPTSt_stEng != Coupe_cale)
            || (HEATSENO2DS_stEngPrev == Coupe_cale))
         {
            if (bLocalAcvLsDsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (LsSys_bLsDsMainOxCHeatEna != 0)
               {
                  if (LsSys_bLsDsBoostEnd == 0)
                  {
                     VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                 LSDSMAINOXCHEAT_PHASE_C1);
                     LsSys_tiLsDsDlyMainOxCPhaseC = 0;
                     LsSys_tiLsDsDlyMainOxCPhaseD = 0;
                     LsSys_tiLsDsBoostProtReq = 0;
                  }
                  else
                  {
                     VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                 LSDSMAINOXCHEAT_PHASE_C2);
                     LsSys_tiLsDsDlyMainOxCPhaseC = 1;
                     LsSys_tiLsDsDlyMainOxCPhaseD = 0;
                  }
               }
               else
               {
                  if (LsSys_bLsDsMainOxCHeatHotEna !=0)
                  {
                     VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                 LSDSMAINOXCHEAT_PHASE_E);
                  }
               }
            }
         }
         break;

      case LSDSMAINOXCHEAT_PHASE_C1:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2DS_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsDsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Stop)
               {
                  VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_F);
               }
               else
               {
                  if (LsSys_bLsDsMainOxCHeatProtEnd != 0)
                  {
                     if (LsSys_bLsDsMainOxCHeatHiEnd == 0)
                     {
                        VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                    LSDSMAINOXCHEAT_PHASE_D);
                     }
                     else
                     {
                        VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                    LSDSMAINOXCHEAT_PHASE_E);
                     }
                  }
                  else
                  {
                     if (LsSys_bLsDsBoostEnd != 0)
                     {
                        VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                    LSDSMAINOXCHEAT_PHASE_C2);
                        if (LsSys_tiLsDsDlyMainOxCPhaseC < 65535)
                        {
                           LsSys_tiLsDsDlyMainOxCPhaseC =
                              (uint16)(LsSys_tiLsDsDlyMainOxCPhaseC + 1);
                        }
                     }
                     else
                     {
                        if (LsSys_tiLsDsDlyMainOxCPhaseC < 65535)
                        {
                           LsSys_tiLsDsDlyMainOxCPhaseC =
                              (uint16)(LsSys_tiLsDsDlyMainOxCPhaseC + 1);
                        }
                        if ( LsSys_tiLsDsBoostProtReq < 255)
                        {
                           LsSys_tiLsDsBoostProtReq =
                              (uint8)(LsSys_tiLsDsBoostProtReq + 1);
                        }
                     }
                  }
               }
            }
         }
         break;

      case LSDSMAINOXCHEAT_PHASE_C2:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2DS_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsDsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Stop)
               {
                  VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_F);
               }
               else
               {
                  if (LsSys_bLsDsMainOxCHeatProtEnd != 0)
                  {
                     if (LsSys_bLsDsMainOxCHeatHiEnd == 0)
                     {
                        VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                    LSDSMAINOXCHEAT_PHASE_D);
                     }
                     else
                     {
                        VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                    LSDSMAINOXCHEAT_PHASE_E);
                     }
                  }
                  else
                  {
                     if (LsSys_tiLsDsDlyMainOxCPhaseC < 65535)
                     {
                        LsSys_tiLsDsDlyMainOxCPhaseC =
                           (uint16)(LsSys_tiLsDsDlyMainOxCPhaseC + 1);
                     }
                  }
               }
            }
         }
         break;

      case LSDSMAINOXCHEAT_PHASE_D:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2DS_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsDsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (LsSys_bLsDsMainOxCHeatHiEnd != 0)
               {
                  VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_E);
               }
               else
               {
                  if (LsSys_tiLsDsDlyMainOxCPhaseD < 65535)
                  {
                     LsSys_tiLsDsDlyMainOxCPhaseD =
                        (uint16)(LsSys_tiLsDsDlyMainOxCPhaseD + 1);
                  }
               }
            }
         }
         break;

      case LSDSMAINOXCHEAT_PHASE_E:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2DS_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsDsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (LsSys_bAcvLsDsMainOxCHeatLo != 0)
               {
                  VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_F);
               }
            }
         }
         break;

      case LSDSMAINOXCHEAT_PHASE_F:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2DS_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsDsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
               if (  (u8LocalVehicle_active_state == VS_RUNNING)
                  && (u8LocalCoPTSt_stEng != Stop))
               {
                  if (LsSys_bLsDsBoostEnd == 0)
                  {
                     VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                 LSDSMAINOXCHEAT_PHASE_C1);
                     LsSys_tiLsDsDlyMainOxCPhaseC = 0;
                     LsSys_tiLsDsDlyMainOxCPhaseD = 0;
                     LsSys_tiLsDsBoostProtReq = 0;
                  }
                  else
                  {
                     VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                 LSDSMAINOXCHEAT_PHASE_C2);
                     LsSys_tiLsDsDlyMainOxCPhaseC = 1;
                     LsSys_tiLsDsDlyMainOxCPhaseD = 0;
                  }
               }
               else
               {
                  if (LsSys_bLsDsMainOxCHeatLoEnd != 0)
                  {
                     VEMS_vidSET(LsSys_stLsDsMainOxCHeat,
                                 LSDSMAINOXCHEAT_PHASE_A);
                  }
               }
            }
         }
         break;

      case LSDSMAINOXCHEAT_PHASE_G:
         if (bLocalAcvLsDsMainOxCHeatLih == 0)
         {
            VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(LsSys_stLsDsMainOxCHeat, LSDSMAINOXCHEAT_PHASE_A);
         break;
   }
   HEATSENO2DS_stEngPrev = u8LocalCoPTSt_stEng;
}
/*------------------------------- end of file --------------------------------*/