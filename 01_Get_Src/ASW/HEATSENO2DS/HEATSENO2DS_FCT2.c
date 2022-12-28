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
/* !File            : HEATSENO2DS_FCT2.C                                      */
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
/*   1 / HEATSENO2DS_vidTranAToCOrAToE                                        */
/*   2 / HEATSENO2DS_vidTranCToD                                              */
/*   3 / HEATSENO2DS_vidTranCToEOrDToE                                        */
/*   4 / HEATSENO2DS_vidTranEToF                                              */
/*   5 / HEATSENO2DS_vidTranFToA                                              */
/*   6 / HEATSENO2DS_vidTranC1toC2                                            */
/*   7 / HEATSENO2DS_vidLsDsDetRTStallint                                     */
/*   8 / HEATSENO2DS_vidLsDsDetRTStall                                        */
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
/* $Revision::   1.12     $$Author::   wbouach        $$Date::   25 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   25 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "HEATSENO2DS.H"
#include "HEATSENO2DS_L.H"
#include "HEATSENO2DS_IM.H"
#include "MATHSRV.H"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidTranAToCOrAToE                              */
/* !Description :  Lorsque le l’automate se trouve en phase de chauffage      */
/*                 coupé, il peut activer le chauffa ge de protection si la   */
/*                 sonde est considérée froide ou activer le chauffage modulé */
/*                 si la sonde est considérée chaude                          */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_006.01                                     */
/*                 VEMS_R_08_03331_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean LsSys_bLsDsMainOxCDewProtReq;                               */
/*  input sint16 LsSys_tCoLsHeat;                                             */
/*  input sint16 LsSys_tCoolHeatHotThd_C;                                     */
/*  output boolean LsSys_bLsDsMainOxCHeatEna;                                 */
/*  output boolean LsSys_bLsDsMainOxCHeatHotEna;                              */
/*  output uint16 LsSys_tiSumLsDsMainOxCHeatNull;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidTranAToCOrAToE(void)
{
   boolean bLocalLsSys_bDsMainOxCDewProtReq;
   boolean bLocalLsDsMainOxCHeatHotEna;
   boolean bLocalLsDsMainOxCHeatEna;
   boolean bLocalClef_de_contact;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalCoPTSt_stEng;
   sint16  s16LocalLsSys_tCoLsHeat;


   bLocalLsDsMainOxCHeatEna = 0;
   bLocalLsDsMainOxCHeatHotEna = 0;
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if (  (u8LocalVehicle_active_state == VS_RUNNING)
      && (bLocalClef_de_contact != 0)
      && (u8LocalCoPTSt_stEng != Coupe_cale))
   {
      VEMS_vidGET(LsSys_bLsDsMainOxCDewProtReq,
                  bLocalLsSys_bDsMainOxCDewProtReq);
      VEMS_vidGET(LsSys_tCoLsHeat, s16LocalLsSys_tCoLsHeat);
      if (  (bLocalLsSys_bDsMainOxCDewProtReq != 0)
         || (s16LocalLsSys_tCoLsHeat < LsSys_tCoolHeatHotThd_C))
      {
         bLocalLsDsMainOxCHeatEna = 1;
      }
      else
      {
         bLocalLsDsMainOxCHeatHotEna = 1;
      }
   }
   LsSys_bLsDsMainOxCHeatEna = bLocalLsDsMainOxCHeatEna;
   LsSys_bLsDsMainOxCHeatHotEna = bLocalLsDsMainOxCHeatHotEna;
   LsSys_tiSumLsDsMainOxCHeatNull = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidTranCToD                                    */
/* !Description :  La transition de la phase de chauffage de protection (phase*/
/*                 C) vers la phase de chauffage maximal (phase D) est        */
/*                 autorisée lorsque le chauffage de protection est terminé   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean LsSys_bLsDsMainOxCDewProtReq;                               */
/*  output boolean LsSys_bLsDsMainOxCHeatProtEnd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidTranCToD(void)
{
   boolean bLocalLsSys_bDsMainOxCDewProtReq;


   VEMS_vidGET(LsSys_bLsDsMainOxCDewProtReq, bLocalLsSys_bDsMainOxCDewProtReq);
   LsSys_bLsDsMainOxCHeatProtEnd = !bLocalLsSys_bDsMainOxCDewProtReq;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidTranCToEOrDToE                              */
/* !Description :  Le chauffage modulé consiste à appliquer un chauffage en   */
/*                 fonction du débit de gaz et de la température des gaz      */
/*                 d'échappements                                             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint32 Time_since_stall;                                            */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrMan;                                 */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input uint16 ExM_tExLsDsMainOxCEstim;                                     */
/*  input uint16 LsSys_tiSumLsDsMainOxCHeatNull;                              */
/*  input uint16 LsSys_tiSumLsDsOxCHeatNullThd_C;                             */
/*  input uint16 LsSys_tiLsDsDlyMainOxCPhaseD;                                */
/*  input uint8 LsSys_tiLsDsDlyHeatHi_C;                                      */
/*  input boolean LsSys_bLsDsMainOxCAcvHeatHi;                                */
/*  input uint16 LsSys_tiLsDsDlyWaitSecHeatHi_C;                              */
/*  input boolean LsSys_bLsDsMainOxCDewPtOkLstStrt;                           */
/*  input boolean LsSys_bInhLsDsOxCPtOkLstStrt_C;                             */
/*  input boolean LsSys_bNotrackPwrLsDsMainOxCHeat;                           */
/*  input uint16 LsSys_tMaxLsDsHeatHiThd_C;                                   */
/*  output uint16 LsSys_tiSumLsDsMainOxCHeatNull;                             */
/*  output boolean LsSys_bNotrackPwrLsDsMainOxCHeat;                          */
/*  output boolean LsSys_bLsDsMainOxCHeatHiEnd;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidTranCToEOrDToE(void)
{
   boolean bLocalLshddwnstrmlbdasensrhot;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalRLsDsMainOxCHeatPwrMan;
   uint16  u16LocalExM_tExLsDsMainOxCEstim;
   uint32  u32LocalTime_since_stall;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidGET(LsSys_rLsDsMainOxCHeatPwrMan, u8LocalRLsDsMainOxCHeatPwrMan);
   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot, bLocalLshddwnstrmlbdasensrhot);
   VEMS_vidGET(ExM_tExLsDsMainOxCEstim, u16LocalExM_tExLsDsMainOxCEstim);

   if (u8LocalRLsDsMainOxCHeatPwrMan == 0)
   {
      if (LsSys_tiSumLsDsMainOxCHeatNull < 65535)
      {
         LsSys_tiSumLsDsMainOxCHeatNull =
            (uint16)(LsSys_tiSumLsDsMainOxCHeatNull + 1);
      }
   }

   if (LsSys_tiSumLsDsMainOxCHeatNull > LsSys_tiSumLsDsOxCHeatNullThd_C)
   {
      LsSys_bNotrackPwrLsDsMainOxCHeat = 1;
   }
   else
   {
      LsSys_bNotrackPwrLsDsMainOxCHeat = 0;
   }

   if (  (u8LocalCoPTSt_stEng == Stop)
      || (LsSys_tiLsDsDlyMainOxCPhaseD > LsSys_tiLsDsDlyHeatHi_C)
      || (LsSys_bLsDsMainOxCAcvHeatHi == 0)
      || (  (u32LocalTime_since_stall < LsSys_tiLsDsDlyWaitSecHeatHi_C)
         && (  (LsSys_bLsDsMainOxCDewPtOkLstStrt != 0)
            || (LsSys_bInhLsDsOxCPtOkLstStrt_C != 0)))
      || (LsSys_bNotrackPwrLsDsMainOxCHeat != 0)
      || (  (bLocalLshddwnstrmlbdasensrhot != 0)
         && (u16LocalExM_tExLsDsMainOxCEstim > LsSys_tMaxLsDsHeatHiThd_C)))
   {
      LsSys_bLsDsMainOxCHeatHiEnd = 1;
   }
   else
   {
      LsSys_bLsDsMainOxCHeatHiEnd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidTranEToF                                    */
/* !Description :  Lors d'une phase stop STT on passe de la phase E modulation*/
/*                 de chauffe à la phase F chauffe réduite                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 LsSys_tiLsDsMaxDlyHeatModStop;                               */
/*  input boolean LsSys_bLsDsMainOxCDewProtReq;                               */
/*  input uint16 LsSys_tiLsDsMaxDlyHeatModStop_C;                             */
/*  output uint16 LsSys_tiLsDsMaxDlyHeatModStop;                              */
/*  output boolean LsSys_bAcvLsDsMainOxCHeatLo;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidTranEToF(void)
{
   boolean bLocalLsDsMainOxCDewProtReq;
   uint8   u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   if (u8LocalCoPTSt_stEng == Stop)
   {
      if (LsSys_tiLsDsMaxDlyHeatModStop > 0)
      {
         LsSys_tiLsDsMaxDlyHeatModStop = (uint16)( LsSys_tiLsDsMaxDlyHeatModStop
                                                 - 1);
      }
      LsSys_tiLsDsMaxDlyHeatModStop =
         (uint16)MATHSRV_udtMIN(LsSys_tiLsDsMaxDlyHeatModStop, 2559);
      VEMS_vidGET(LsSys_bLsDsMainOxCDewProtReq, bLocalLsDsMainOxCDewProtReq);
      if (  (bLocalLsDsMainOxCDewProtReq != 0)
         || (LsSys_tiLsDsMaxDlyHeatModStop == 0))
      {
         LsSys_bAcvLsDsMainOxCHeatLo = 1;
      }
      else
      {
         LsSys_bAcvLsDsMainOxCHeatLo = 0;
      }
   }
   else
   {
      LsSys_tiLsDsMaxDlyHeatModStop =
         (uint16)MATHSRV_udtMIN(LsSys_tiLsDsMaxDlyHeatModStop_C, 2559);
      LsSys_bAcvLsDsMainOxCHeatLo = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidTranFToA                                    */
/* !Description :  Lorsque le chauffage réduit reste activé trop longtemps on */
/*                 passe en chauffage coupé afin de réduire la consommation   */
/*                 électrique                                                 */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 HEATSENO2DS_u8OxCHeatPrevslow;                                */
/*  input uint16 LsSys_tiLsDsMaxDlyHeatLo_C;                                  */
/*  input uint16 LsSys_tiLsDsDlyMainOxCPhaseF;                                */
/*  output uint16 LsSys_tiLsDsDlyMainOxCPhaseF;                               */
/*  output boolean LsSys_bLsDsMainOxCHeatLoEnd;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidTranFToA(void)
{
   if (HEATSENO2DS_u8OxCHeatPrevslow != LSDSMAINOXCHEAT_PHASE_F)
   {
      LsSys_tiLsDsDlyMainOxCPhaseF = LsSys_tiLsDsMaxDlyHeatLo_C;
      if (LsSys_tiLsDsDlyMainOxCPhaseF == 0)
      {
         LsSys_bLsDsMainOxCHeatLoEnd = 1;
      }
      else
      {
         LsSys_bLsDsMainOxCHeatLoEnd = 0;
      }
   }
   else
   {
      if (LsSys_tiLsDsDlyMainOxCPhaseF > 0)
      {
         LsSys_tiLsDsDlyMainOxCPhaseF = (uint16)( LsSys_tiLsDsDlyMainOxCPhaseF
                                                - 1);
         if (LsSys_tiLsDsDlyMainOxCPhaseF == 0)
         {
            LsSys_bLsDsMainOxCHeatLoEnd = 1;
         }
         else
         {
            LsSys_bLsDsMainOxCHeatLoEnd = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidTranC1toC2                                  */
/* !Description :  La phase C est composée par la sous phase C1 qui est un    */
/*                 boost de préchauffage de la sonde aval rapidement et la    */
/*                 sous phase C2 qui est un intensif de préchauffage de la    */
/*                 sonde aval maintenu pour la rapidité et la protection du   */
/*                 préchauffage de la sonde aval.                             */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 LsSys_tCoLsHeat;                                             */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input uint16 ExM_tExLsDsMainOxCEstim;                                     */
/*  input uint32 Time_since_stall;                                            */
/*  input uint8 LsSys_tCoLsDsThdBoostProtReq_T[6];                            */
/*  input uint8 LsSys_tiLsDsThdBoostProtReq_M[6];                             */
/*  input uint8 LsSys_tiLsDsBoostProtReq;                                     */
/*  input uint16 LsSys_tiLsDsWaitSecBoost_C;                                  */
/*  input boolean LsSys_bLsDsMainOxCDewPtOkLstStrt;                           */
/*  input boolean LsSys_bInhLsDsOxCNoPtOkLstStrt_C;                           */
/*  input uint16 LsSys_tMaxLsDsHeatBoostThd_C;                                */
/*  output boolean LsSys_bLsDsBoostEnd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidTranC1toC2(void)
{
   boolean bLocalLshddwnstrmlbdasensrhot;
   uint8   u8LocalInp;
   uint8   u8LocalInterp;
   uint16  u16LocalPara;
   uint16  u16LocalExM_tExLsDsMainOxCEstim;
   sint16  s16LocalLsSysTCoLsHeat;
   uint32  u32LocalTime_since_stall;
   sint32  s32LocalInput;


   VEMS_vidGET(LsSys_tCoLsHeat, s16LocalLsSysTCoLsHeat);
   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot, bLocalLshddwnstrmlbdasensrhot);
   VEMS_vidGET(ExM_tExLsDsMainOxCEstim, u16LocalExM_tExLsDsMainOxCEstim);
   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);

   s32LocalInput = (sint32)(s16LocalLsSysTCoLsHeat + 40);
   u8LocalInp = (uint8)MATHSRV_udtCLAMP(s32LocalInput, 0, 254);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(LsSys_tCoLsDsThdBoostProtReq_T,
                                              u8LocalInp,
                                              6);
   u8LocalInterp = MATHSRV_u8Interp1d(LsSys_tiLsDsThdBoostProtReq_M,
                                      u16LocalPara);

   if (  (LsSys_tiLsDsBoostProtReq > u8LocalInterp)
      || (  (u32LocalTime_since_stall < LsSys_tiLsDsWaitSecBoost_C)
         && (  (LsSys_bLsDsMainOxCDewPtOkLstStrt == 0)
            || (LsSys_bInhLsDsOxCNoPtOkLstStrt_C != 0)))
      || (  (bLocalLshddwnstrmlbdasensrhot != 0)
         && (u16LocalExM_tExLsDsMainOxCEstim > LsSys_tMaxLsDsHeatBoostThd_C)))
   {
      LsSys_bLsDsBoostEnd = 1;
   }
   else
   {
      LsSys_bLsDsBoostEnd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidLsDsDetRTStallint                           */
/* !Description :  Lors de la détection d’un passage de l’état moteur stall   */
/*                 vers cranking ou d’état moteur cranking vers running, la   */
/*                 variable est mise à zéro                                   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean LsSys_bLsDsDetRTStall;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidLsDsDetRTStallint(void)
{
   LsSys_bLsDsDetRTStall = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DS_vidLsDsDetRTStall                              */
/* !Description :  Lors de la détection du passage de l’état moteur « Running */
/*                 » vers Stall, la variable est mise à 1                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean LsSys_bLsDsDetRTStall;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DS_vidLsDsDetRTStall(void)
{
   LsSys_bLsDsDetRTStall = 1;
}

/*------------------------------- end of file --------------------------------*/