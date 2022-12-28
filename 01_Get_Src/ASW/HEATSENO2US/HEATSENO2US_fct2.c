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
/* !File            : HEATSENO2US_FCT2.C                                      */
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
/*   1 / HEATSENO2US_vidMgrFastTran                                           */
/*   2 / HEATSENO2US_vidMgrMidTran                                            */
/*   3 / HEATSENO2US_vidTranAToCOrAToE                                        */
/*   4 / HEATSENO2US_vidTranCToD                                              */
/*   5 / HEATSENO2US_vidTranCToEOrDToE                                        */
/*   6 / HEATSENO2US_vidTranEToF                                              */
/*   7 / HEATSENO2US_vidMgrSlowTran                                           */
/*   8 / HEATSENO2US_vidTranFToA                                              */
/*   9 / HEATSENO2US_vidLsUsMgrHeatState                                      */
/*   10 / HEATSENO2US_vidOxCHeatReq                                           */
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
/* !Function    :  HEATSENO2US_vidMgrFastTran                                 */
/* !Description :  Lorsqu'une surtension batterie est présente, le chauffage  */
/*                 sonde est placé en mode dégradé et le chauffage est donc   */
/*                 coupé                                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_006.01                                     */
/*                 VEMS_R_12_01117_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean HEATSENO2US_bUBattAcvHeatLih;                               */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 LsSys_uBattAcvHeatLih_C;                                      */
/*  input uint8 LsSys_tiDlyAcvHeatLih_C;                                      */
/*  input uint16 LsSys_tiLsUsDlyAcvHeatLih;                                   */
/*  input boolean HEATSENO2US_bTimeout1;                                      */
/*  output boolean HEATSENO2US_bUBattAcvHeatLih;                              */
/*  output uint16 LsSys_tiLsUsDlyAcvHeatLih;                                  */
/*  output boolean HEATSENO2US_bTimeout1;                                     */
/*  output boolean LsSys_bAcvLsUsMainOxCHeatLih;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidMgrFastTran(void)
{
   boolean bLocalUBattAcvHeatLihPrev;
   boolean bLocalInhLsUsMainOxCHeat;
   uint16  u16LocalLsSystiLsUsDlyAcvHeatLih;
   uint16  u16LocalLsSys_uBattAcvHeatLih;
   sint16  s16LocalExt_uBattMes;


   bLocalUBattAcvHeatLihPrev = HEATSENO2US_bUBattAcvHeatLih;
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   u16LocalLsSys_uBattAcvHeatLih = (uint16)(LsSys_uBattAcvHeatLih_C * 10);
   if (s16LocalExt_uBattMes > (sint16)u16LocalLsSys_uBattAcvHeatLih)
   {
      HEATSENO2US_bUBattAcvHeatLih = 1;
   }
   else
   {
      HEATSENO2US_bUBattAcvHeatLih = 0;
   }
   if (  (HEATSENO2US_bUBattAcvHeatLih != 0)
      && (bLocalUBattAcvHeatLihPrev == 0) )
   {
      LsSys_tiLsUsDlyAcvHeatLih = (uint16)(LsSys_tiDlyAcvHeatLih_C * 4);
      if (LsSys_tiLsUsDlyAcvHeatLih == 0)
      {
         HEATSENO2US_bTimeout1 = 1;
      }
      else
      {
         HEATSENO2US_bTimeout1 = 0;
      }
   }
   else
   {
      if (LsSys_tiLsUsDlyAcvHeatLih > 0)
      {
         u16LocalLsSystiLsUsDlyAcvHeatLih = (uint16)( LsSys_tiLsUsDlyAcvHeatLih
                                                    - 1);
         LsSys_tiLsUsDlyAcvHeatLih =
            (uint16)MATHSRV_udtMIN(u16LocalLsSystiLsUsDlyAcvHeatLih, 1023);
         if (LsSys_tiLsUsDlyAcvHeatLih == 0)
         {
            HEATSENO2US_bTimeout1 = 1;
         }
         else
         {
            HEATSENO2US_bTimeout1 = 0;
         }
      }
   }

   bLocalInhLsUsMainOxCHeat = GDGAR_bGetFRM(FRM_FRM_INHLSUSMAINOXCHEAT);
   if (  (bLocalInhLsUsMainOxCHeat != 0)
      || (  (HEATSENO2US_bTimeout1 != 0)
         && (HEATSENO2US_bUBattAcvHeatLih != 0)))
   {
      VEMS_vidSET(LsSys_bAcvLsUsMainOxCHeatLih, 1);
   }
   else
   {
      VEMS_vidSET(LsSys_bAcvLsUsMainOxCHeatLih, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidMgrMidTran                                  */
/* !Description :  Calcul de toutes les transitions ayant un chauffage non nul*/
/*                 et détermination du délai avant réautorisation du chauffage*/
/*                 maximal                                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_006.01                                     */
/*                 VEMS_R_12_01117_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2US_vidTranAtoBandBtoA();                        */
/*  extf argret void HEATSENO2US_vidTranAToCOrAToE();                         */
/*  extf argret void HEATSENO2US_vidTranEToF();                               */
/*  extf argret void HEATSENO2US_vidTranCToEOrDToE();                         */
/*  extf argret void HEATSENO2US_vidTranCToD();                               */
/*  extf argret void HEATSENO2US_vidTranC1ToC2();                             */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input boolean HEATSENO2US_bTimerInit;                                     */
/*  input uint8 HEATSENO2US_u8MainOxCHeatPrev;                                */
/*  input uint16 LsSys_tiLsUsDlyWaitSecHeatHi_C;                              */
/*  input uint32 LsSys_tiLsUsDlySinceLstHeatHi;                               */
/*  output boolean HEATSENO2US_bTimerInit;                                    */
/*  output uint32 LsSys_tiLsUsDlySinceLstHeatHi;                              */
/*  output boolean LsSys_bLsUsMainOxCAcvHeatHi;                               */
/*  output uint8 HEATSENO2US_u8MainOxCHeatPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidMgrMidTran(void)
{
   boolean bLocalTimerInitPrev;
   uint8   u8LocalLsSys_stLsUsMainOxCHeat;
   uint32  u32LocalLsUsDlySinceLstHeatHi;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
/*00_Tran_AtoB_and_BtoA*/
   if (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_B)
      || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_A))
   {
      HEATSENO2US_vidTranAtoBandBtoA();
   }
   bLocalTimerInitPrev = HEATSENO2US_bTimerInit;
   if (  (u8LocalLsSys_stLsUsMainOxCHeat != LSUSMAINOXCHEAT_PHASE_D)
      && (HEATSENO2US_u8MainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_D))
   {
      HEATSENO2US_bTimerInit = 1;
   }
   else
   {
      HEATSENO2US_bTimerInit = 0;
   }

   /* Timer */
   if (  (HEATSENO2US_bTimerInit != 0)
      && (bLocalTimerInitPrev == 0))
   {
      LsSys_tiLsUsDlySinceLstHeatHi = (uint32)( LsSys_tiLsUsDlyWaitSecHeatHi_C
                                              * 10);
      if (LsSys_tiLsUsDlySinceLstHeatHi == 0)
      {
         LsSys_bLsUsMainOxCAcvHeatHi = 1;
      }
      else
      {
         LsSys_bLsUsMainOxCAcvHeatHi = 0;
      }
   }
   else
   {
      if (LsSys_tiLsUsDlySinceLstHeatHi > 0)
      {
         u32LocalLsUsDlySinceLstHeatHi = LsSys_tiLsUsDlySinceLstHeatHi - 1;
         LsSys_tiLsUsDlySinceLstHeatHi =
            MATHSRV_udtMIN(u32LocalLsUsDlySinceLstHeatHi, 655359);
         if (LsSys_tiLsUsDlySinceLstHeatHi == 0)
         {
            LsSys_bLsUsMainOxCAcvHeatHi = 1;
         }
         else
         {
            LsSys_bLsUsMainOxCAcvHeatHi = 0;
         }
      }
   }
   if (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_A)
   {
      /* 02_Tran_AtoC_or_AtoE */
      HEATSENO2US_vidTranAToCOrAToE();
   }
   else
   {
      if (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_E)
      {
         /* 05_Tran_EtoF */
         HEATSENO2US_vidTranEToF();
      }
      else
      {
         if (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_C1)
            || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_C2)
            || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_D))
         {
            /* 04_Tran_CtoE_or_DtoE */
            HEATSENO2US_vidTranCToEOrDToE();
            if (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_C1)
               || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_C2))
            {
               /* 03_Tran_CtoD */
               HEATSENO2US_vidTranCToD();
            }
            if (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_C1)
            {
               /* 06_Tran_C1toC2 */
               HEATSENO2US_vidTranC1ToC2();
            }
         }
      }
   }
   HEATSENO2US_u8MainOxCHeatPrev = u8LocalLsSys_stLsUsMainOxCHeat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTranAToCOrAToE                              */
/* !Description :  Lorsque le l’automate se trouve en phase de chauffage      */
/*                 coupé, il peut activer le chauffa  ge de protection si la  */
/*                 sonde est considérée froide ou activer le chauffage modulé */
/*                 si la sonde est considérée chaude                          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_010.01                                     */
/*                 VEMS_R_12_01117_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean LsSys_bLsUsMainOxCDewProtReq;                               */
/*  input sint16 LsSys_tCoLsHeat;                                             */
/*  input sint16 LsSys_tCoolHeatHotThd_C;                                     */
/*  output boolean LsSys_bLsUsMainOxCHeatEna;                                 */
/*  output boolean LsSys_bLsUsMainOxCHeatHotEna;                              */
/*  output uint16 LsSys_tiSumLsUsMainOxCHeatNull;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTranAToCOrAToE(void)
{
   boolean bLocalLsSys_bUsMainOxCDewProtReq;
   boolean bLocalLsUsMainOxCHeatHotEna;
   boolean bLocalLsUsMainOxCHeatEna;
   boolean bLocalClef_de_contact;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalCoPTSt_stEng;
   sint16  s16LocalLsSys_tCoLsHeat;


   bLocalLsUsMainOxCHeatEna = 0;
   bLocalLsUsMainOxCHeatHotEna = 0;
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if (  (u8LocalVehicle_active_state == VS_RUNNING)
      && (u8LocalCoPTSt_stEng != Coupe_cale)
      && (bLocalClef_de_contact != 0))
   {
      VEMS_vidGET(LsSys_bLsUsMainOxCDewProtReq,
                  bLocalLsSys_bUsMainOxCDewProtReq);
      VEMS_vidGET(LsSys_tCoLsHeat, s16LocalLsSys_tCoLsHeat);
      if (  (bLocalLsSys_bUsMainOxCDewProtReq != 0)
         || (s16LocalLsSys_tCoLsHeat < LsSys_tCoolHeatHotThd_C))
      {
         bLocalLsUsMainOxCHeatEna = 1;
      }
      else
      {
         bLocalLsUsMainOxCHeatHotEna = 1;
      }
   }
   LsSys_bLsUsMainOxCHeatEna = bLocalLsUsMainOxCHeatEna;
   LsSys_bLsUsMainOxCHeatHotEna = bLocalLsUsMainOxCHeatHotEna;
   LsSys_tiSumLsUsMainOxCHeatNull = 0;

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTranCToD                                    */
/* !Description :  Le passage en chauffage maximal se réalise si on estime que*/
/*                 la sonde a suffisamment été chauffé en phase de            */
/*                 préchauffage, en phase de protection ou dans le dernier    */
/*                 cycle moteur                                               */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean LsSys_bLsUsMainOxCDewProtReq;                               */
/*  input boolean LsSys_bLsUsMainOxCHeatFloEna;                               */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseC;                                */
/*  input uint8 LsSys_tiLsUsDlyDewProtReqFLO_C;                               */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseB;                                */
/*  input uint16 LsSys_tiThdWkuDewProtReqFLO_C;                               */
/*  input boolean LsSys_bHeatWkuLsSysDone;                                    */
/*  output boolean LsSys_bLsUsMainOxCHeatProtEnd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTranCToD(void)
{
   boolean bLocalLsUsMainOxCDewProtReq;
   boolean bLocalLsSysbLsUsMainOxCHeatFloEn;
   boolean blocalLsSys1;
   boolean blocalLsSys2;

   VEMS_vidGET(LsSys_bLsUsMainOxCDewProtReq, bLocalLsUsMainOxCDewProtReq);
   VEMS_vidGET(LsSys_bLsUsMainOxCHeatFloEna, bLocalLsSysbLsUsMainOxCHeatFloEn);

   if (  (LsSys_tiLsUsDlyMainOxCPhaseC > LsSys_tiLsUsDlyDewProtReqFLO_C)
      && (bLocalLsSysbLsUsMainOxCHeatFloEn != 0))
   {
      blocalLsSys1 = 1;
   }
   else
   {
      blocalLsSys1 = 0;
   }
   if (  (bLocalLsSysbLsUsMainOxCHeatFloEn != 0)
      && (  (LsSys_tiLsUsDlyMainOxCPhaseB > LsSys_tiThdWkuDewProtReqFLO_C)
         || (LsSys_bHeatWkuLsSysDone != 0) ))
   {
      blocalLsSys2 = 1;
   }
   else
   {
      blocalLsSys2 = 0;
   }
   if (  (bLocalLsUsMainOxCDewProtReq == 0)
      || (blocalLsSys1 != 0)
      || (blocalLsSys2 != 0))
   {
      LsSys_bLsUsMainOxCHeatProtEnd = 1;
   }
   else
   {
      LsSys_bLsUsMainOxCHeatProtEnd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTranCToEOrDToE                              */
/* !Description :  Conditions de transition vers le chauffage modulé de la    */
/*                 sonde O2 amont                                             */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_013.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint32 Time_since_stall;                                            */
/*  input boolean LsSys_bLsUsMainOxCHeatFloEna;                               */
/*  input uint16 ExM_tExLsUsMainOxCEstim;                                     */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrMan;                                 */
/*  input boolean Lshd_up_stream_lbda_sensor_hot;                             */
/*  input uint16 LsSys_tMaxLsUsHeatHiThd_C;                                   */
/*  input uint16 LsSys_tiPhaseB_tiHeatHiFLO_A[8];                             */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseB;                                */
/*  input uint8 LsSys_tiLsUsDlyHeatHiFLO_M[8];                                */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseD;                                */
/*  input uint8 LsSys_tiLsUsDlyHeatHi_C;                                      */
/*  input uint16 LsSys_tiLsUsDlyWaitSecHeatHi_C;                              */
/*  input boolean LsSys_bLsUsMainOxCDewPtOkLstStrt;                           */
/*  input boolean LsSys_bInhLsUsOxCPtOkLstStrt_C;                             */
/*  input uint16 LsSys_tiSumLsUsMainOxCHeatNull;                              */
/*  input uint16 LsSys_tiSumLsUsOxCHeatNullThd_C;                             */
/*  input boolean LsSys_bLsUsMainOxCAcvHeatHi;                                */
/*  input boolean LsSys_bNotrackPwrLsUsMainOxCHeat;                           */
/*  output uint16 LsSys_tiSumLsUsMainOxCHeatNull;                             */
/*  output boolean LsSys_bNotrackPwrLsUsMainOxCHeat;                          */
/*  output boolean LsSys_bLsUsMainOxCHeatHiEnd;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTranCToEOrDToE(void)
{
   boolean bLocalLsSysbLsUsMainOxCHeatFloEn;
   boolean bLocalCond1;
   boolean bLocalCond2;
   boolean bLocalLshd_up_streamlbdasensorh;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalLsSystiLsUsDlyHeatHiFLO_M;
   uint8   u8LocalLsSysLsUsMainOxCHeatPwMan;
   uint16  u16LocalCalcPara;
   uint16  u16LocalExM_tExLsUsMainOxCEstim;
   uint16  u16LocalLsSys_tMaxLsUsHeatHiThd;
   uint32  u32LocalTime_since_stall;
   uint32  u32LocalLSystiSumLsUsMaOxCHeatNl;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
   VEMS_vidGET(LsSys_bLsUsMainOxCHeatFloEna, bLocalLsSysbLsUsMainOxCHeatFloEn);
   VEMS_vidGET(ExM_tExLsUsMainOxCEstim, u16LocalExM_tExLsUsMainOxCEstim);
   VEMS_vidGET(LsSys_rLsUsMainOxCHeatPwrMan, u8LocalLsSysLsUsMainOxCHeatPwMan);
   VEMS_vidGET(Lshd_up_stream_lbda_sensor_hot, bLocalLshd_up_streamlbdasensorh);
   u16LocalLsSys_tMaxLsUsHeatHiThd = (uint16)(LsSys_tMaxLsUsHeatHiThd_C - 7136);

   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(LsSys_tiPhaseB_tiHeatHiFLO_A,
                                  LsSys_tiLsUsDlyMainOxCPhaseB,
                                  8);
   u8LocalLsSystiLsUsDlyHeatHiFLO_M =
      MATHSRV_u8Interp1d(LsSys_tiLsUsDlyHeatHiFLO_M, u16LocalCalcPara);

   if( (  (bLocalLsSysbLsUsMainOxCHeatFloEn == 0)
       && (LsSys_tiLsUsDlyMainOxCPhaseD > LsSys_tiLsUsDlyHeatHi_C))
     || (  (LsSys_tiLsUsDlyMainOxCPhaseD > u8LocalLsSystiLsUsDlyHeatHiFLO_M)
         && (bLocalLsSysbLsUsMainOxCHeatFloEn != 0)))
   {
      bLocalCond1 = 1;
   }
   else
   {
      bLocalCond1 = 0;
   }
   if(  (u32LocalTime_since_stall < LsSys_tiLsUsDlyWaitSecHeatHi_C)
     && (  (LsSys_bLsUsMainOxCDewPtOkLstStrt != 0)
        || (LsSys_bInhLsUsOxCPtOkLstStrt_C != 0)))
   {
      bLocalCond2 = 1;
   }
   else
   {
      bLocalCond2 = 0;
   }

   if (u8LocalLsSysLsUsMainOxCHeatPwMan == 0)
   {
      u32LocalLSystiSumLsUsMaOxCHeatNl = LsSys_tiSumLsUsMainOxCHeatNull + 1;
      LsSys_tiSumLsUsMainOxCHeatNull =
            (uint16)MATHSRV_udtMIN(u32LocalLSystiSumLsUsMaOxCHeatNl,65535);
   }
   if (LsSys_tiSumLsUsMainOxCHeatNull > LsSys_tiSumLsUsOxCHeatNullThd_C)
   {
      LsSys_bNotrackPwrLsUsMainOxCHeat = 1;
   }
   else
   {
      LsSys_bNotrackPwrLsUsMainOxCHeat = 0;
   }
   if (  (u8LocalCoPTSt_stEng == Stop)
      || (bLocalCond1 != 0)
      || (LsSys_bLsUsMainOxCAcvHeatHi == 0)
      || ( bLocalCond2 != 0)
      || (  (bLocalLshd_up_streamlbdasensorh != 0)
         && (u16LocalExM_tExLsUsMainOxCEstim > u16LocalLsSys_tMaxLsUsHeatHiThd))
      || (LsSys_bNotrackPwrLsUsMainOxCHeat != 0))
   {
      LsSys_bLsUsMainOxCHeatHiEnd = 1;
   }
   else
   {
      LsSys_bLsUsMainOxCHeatHiEnd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTranEToF                                    */
/* !Description :  Conditions de transition vers le chauffage réduit pour la  */
/*                 sonde amont                                                */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean LsSys_bLsUsMainOxCDewProtReq;                               */
/*  input uint16 LsSys_tiLsUsMaxDlyHeatModStop;                               */
/*  input uint16 LsSys_tiLsUsMaxDlyHeatModStop_C;                             */
/*  output uint16 LsSys_tiLsUsMaxDlyHeatModStop;                              */
/*  output boolean LsSys_bAcvLsUsMainOxCHeatLo;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTranEToF(void)
{
   boolean bLocalLsUsMainOxCDewProtReq;
   uint8   u8LocalCoPTSt_stEng;
   sint32  s32Localsubtraction;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(LsSys_bLsUsMainOxCDewProtReq, bLocalLsUsMainOxCDewProtReq);
   if (u8LocalCoPTSt_stEng == Stop)
   {
      s32Localsubtraction =
         (sint32)(LsSys_tiLsUsMaxDlyHeatModStop - 1);
      LsSys_tiLsUsMaxDlyHeatModStop =
         (uint16)MATHSRV_udtCLAMP(s32Localsubtraction, 0, 2559);
      if (  (LsSys_tiLsUsMaxDlyHeatModStop == 0)
         || (bLocalLsUsMainOxCDewProtReq != 0))
      {
         LsSys_bAcvLsUsMainOxCHeatLo = 1;
      }
      else
      {
         LsSys_bAcvLsUsMainOxCHeatLo = 0;
      }
   }
   else
   {
      LsSys_tiLsUsMaxDlyHeatModStop =
         (uint16)MATHSRV_udtMIN(LsSys_tiLsUsMaxDlyHeatModStop_C, 2559);
      LsSys_bAcvLsUsMainOxCHeatLo = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidMgrSlowTran                                 */
/* !Description :  Lorsque l’automate se trouve en chauffage réduit trop      */
/*                 longtemps, le chauffage est coupé pour limiter la          */
/*                 consommation électrique.                                   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2US_vidTranFToA();                               */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input uint8 HEATSENO2US_u8OxCHeatPrevslow;                                */
/*  output uint8 HEATSENO2US_u8OxCHeatPrevslow;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidMgrSlowTran(void)
{
   uint8 u8LocalLsSys_stLsUsMainOxCHeat;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   if (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_F)
      || (HEATSENO2US_u8OxCHeatPrevslow == LSUSMAINOXCHEAT_PHASE_F))
   {
      HEATSENO2US_vidTranFToA();
   }
   HEATSENO2US_u8OxCHeatPrevslow = u8LocalLsSys_stLsUsMainOxCHeat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidTranFToA                                    */
/* !Description :  Transition du chauffage réduit au chauffage coupé de la    */
/*                 sonde amont                                                */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input uint8 HEATSENO2US_u8OxCHeatPrevslow;                                */
/*  input uint16 LsSys_tiLsUsMaxDlyHeatLo_C;                                  */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseF;                                */
/*  output uint16 LsSys_tiLsUsDlyMainOxCPhaseF;                               */
/*  output boolean LsSys_bLsUsMainOxCHeatLoEnd;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidTranFToA(void)
{
   uint8 u8LocalLsSys_stLsUsMainOxCHeat;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   if (  (HEATSENO2US_u8OxCHeatPrevslow != LSUSMAINOXCHEAT_PHASE_F)
      && (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_F))
   {
      LsSys_tiLsUsDlyMainOxCPhaseF = LsSys_tiLsUsMaxDlyHeatLo_C;
      if (LsSys_tiLsUsDlyMainOxCPhaseF == 0)
      {
         LsSys_bLsUsMainOxCHeatLoEnd = 1;
      }
      else
      {
         LsSys_bLsUsMainOxCHeatLoEnd = 0;
      }
   }
   else
   {
      if (LsSys_tiLsUsDlyMainOxCPhaseF > 0)
      {
         LsSys_tiLsUsDlyMainOxCPhaseF =
            (uint16)(LsSys_tiLsUsDlyMainOxCPhaseF - 1);
         if (  (LsSys_tiLsUsDlyMainOxCPhaseF == 0)
            && (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_F))
         {
            LsSys_bLsUsMainOxCHeatLoEnd = 1;
         }
         else
         {
            LsSys_bLsUsMainOxCHeatLoEnd = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidLsUsMgrHeatState                            */
/* !Description :  Automate de gestion des phases de chauffage de la sonde O2 */
/*                 amont                                                      */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_017.01                                     */
/*                 VEMS_R_12_01117_018.01                                     */
/*                 VEMS_R_12_01117_019.01                                     */
/*                 VEMS_R_12_01117_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input boolean LsSys_bAcvLsUsMainOxCHeatLih;                               */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 HEATSENO2US_stEngPrev;                                        */
/*  input boolean LsSys_bLsUsMainOxCHeatEna;                                  */
/*  input boolean LsSys_bLsUsBoostEnd;                                        */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseB;                                */
/*  input boolean LsSys_bLsUsMainOxCHeatHotEna;                               */
/*  input boolean LsSys_bLsUsMainOxCHeatWkuEna;                               */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean LsSys_bLsUsMainOxCHeatWkuEnd;                               */
/*  input boolean LsSys_bLsUsMainOxCHeatProtEnd;                              */
/*  input boolean LsSys_bLsUsMainOxCHeatHiEnd;                                */
/*  input uint8 LsSys_tiLsUsBoostProtReq;                                     */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseC;                                */
/*  input uint16 LsSys_tiLsUsDlyMainOxCPhaseD;                                */
/*  input boolean LsSys_bAcvLsUsMainOxCHeatLo;                                */
/*  input boolean LsSys_bLsUsMainOxCHeatLoEnd;                                */
/*  output st71 LsSys_stLsUsMainOxCHeat;                                      */
/*  output uint16 LsSys_tiLsUsDlyMainOxCPhaseC;                               */
/*  output uint16 LsSys_tiLsUsDlyMainOxCPhaseD;                               */
/*  output uint8 LsSys_tiLsUsBoostProtReq;                                    */
/*  output uint16 LsSys_tiLsUsDlyMainOxCPhaseB;                               */
/*  output boolean LsSys_bHeatWkuLsSysDone;                                   */
/*  output uint8 HEATSENO2US_stEngPrev;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidLsUsMgrHeatState(void)
{
   boolean bLocalAcvLsUsMainOxCHeatLih;
   uint8   u8LocalLsSys_stLsUsMainOxCHeat;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalCalcProtReq;
   uint32  u32LocalCalcPhaseC;
   uint32  u32LocalCalcPhaseD;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   VEMS_vidGET(LsSys_bAcvLsUsMainOxCHeatLih, bLocalAcvLsUsMainOxCHeatLih);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   switch (u8LocalLsSys_stLsUsMainOxCHeat)
   {
      case LSUSMAINOXCHEAT_PHASE_A:
         if (  (u8LocalCoPTSt_stEng != Coupe_cale)
            || (HEATSENO2US_stEngPrev == Coupe_cale))
         {
            if (bLocalAcvLsUsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (LsSys_bLsUsMainOxCHeatEna != 0)
               {
                  if  (  (LsSys_bLsUsBoostEnd == 0)
                      && (LsSys_tiLsUsDlyMainOxCPhaseB == 0))
                  {
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_C1);
                     LsSys_tiLsUsDlyMainOxCPhaseC = 0;
                     LsSys_tiLsUsDlyMainOxCPhaseD = 0;
                     LsSys_tiLsUsBoostProtReq = 0;
                  }
                  else
                  {
                     LsSys_tiLsUsDlyMainOxCPhaseC = 1;
                     LsSys_tiLsUsDlyMainOxCPhaseD = 0;
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_C2);
                  }
               }
               else
               {
                  if (LsSys_bLsUsMainOxCHeatHotEna !=0)
                  {
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_E);
                  }
                  else
                  {
                     if (LsSys_bLsUsMainOxCHeatWkuEna != 0)
                     {
                        VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                    LSUSMAINOXCHEAT_PHASE_B);
                        LsSys_tiLsUsDlyMainOxCPhaseB = 0;
                     }
                  }
               }
            }
         }
         break;

      case LSUSMAINOXCHEAT_PHASE_B:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2US_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsUsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
               if (u8LocalVehicle_active_state == VS_RUNNING)
               {
                  if (  (LsSys_bLsUsBoostEnd == 0)
                     && (LsSys_tiLsUsDlyMainOxCPhaseB == 0))
                  {
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_C1);
                     LsSys_tiLsUsDlyMainOxCPhaseC = 0;
                     LsSys_tiLsUsDlyMainOxCPhaseD = 0;
                     LsSys_tiLsUsBoostProtReq = 0;
                  }
                  else
                  {
                     LsSys_tiLsUsDlyMainOxCPhaseC = 1;
                     LsSys_tiLsUsDlyMainOxCPhaseD = 0;
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_C2);
                  }
               }
               else
               {
                  if (LsSys_bLsUsMainOxCHeatWkuEnd != 0)
                  {
                     LsSys_bHeatWkuLsSysDone = 1;
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_A);
                  }
                  else
                  {
                     if (LsSys_tiLsUsDlyMainOxCPhaseB < 65535)
                     {
                        LsSys_tiLsUsDlyMainOxCPhaseB =
                           (uint16)(LsSys_tiLsUsDlyMainOxCPhaseB + 1);
                     }
                  }
               }
            }
         }
         break;

      case LSUSMAINOXCHEAT_PHASE_C1:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2US_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsUsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Stop)
               {
                  VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_F);
               }
               else
               {
                  if (LsSys_bLsUsMainOxCHeatProtEnd != 0)
                  {
                     if (LsSys_bLsUsMainOxCHeatHiEnd == 0)
                     {
                        VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                    LSUSMAINOXCHEAT_PHASE_D);
                     }
                     else
                     {
                        VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                    LSUSMAINOXCHEAT_PHASE_E);
                     }
                  }
                  else
                  {
                     if (LsSys_bLsUsBoostEnd != 0)
                     {
                        VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                    LSUSMAINOXCHEAT_PHASE_C2);
                     }
                     else
                     {
                        u16LocalCalcProtReq = (uint16)(LsSys_tiLsUsBoostProtReq
                                                      + 1);
                        LsSys_tiLsUsBoostProtReq =
                           (uint8)MATHSRV_udtMIN(u16LocalCalcProtReq,255);
                     }
                     u32LocalCalcPhaseC = (uint32)(LsSys_tiLsUsDlyMainOxCPhaseC
                                                  + 1);
                     LsSys_tiLsUsDlyMainOxCPhaseC =
                        (uint16)MATHSRV_udtMIN(u32LocalCalcPhaseC,65535);
                  }
               }
            }
         }
         break;

      case LSUSMAINOXCHEAT_PHASE_C2:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2US_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsUsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (u8LocalCoPTSt_stEng == Stop)
               {
                  VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_F);
               }
               else
               {
                  if (LsSys_bLsUsMainOxCHeatProtEnd != 0)
                  {
                     if (LsSys_bLsUsMainOxCHeatHiEnd == 0)
                     {
                        VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                    LSUSMAINOXCHEAT_PHASE_D);
                     }
                     else
                     {
                        VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                    LSUSMAINOXCHEAT_PHASE_E);
                     }
                  }
                  else
                  {
                     u32LocalCalcPhaseC = (uint32)(LsSys_tiLsUsDlyMainOxCPhaseC
                                                  + 1);
                     LsSys_tiLsUsDlyMainOxCPhaseC =
                        (uint16)MATHSRV_udtMIN(u32LocalCalcPhaseC,65535);
                  }
               }
            }
         }
         break;

      case LSUSMAINOXCHEAT_PHASE_D:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2US_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsUsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (LsSys_bLsUsMainOxCHeatHiEnd != 0)
               {
                  VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_E);
               }
               else
               {
                  u32LocalCalcPhaseD = (uint32)(LsSys_tiLsUsDlyMainOxCPhaseD
                                               + 1);
                  LsSys_tiLsUsDlyMainOxCPhaseD =
                     (uint16)MATHSRV_udtMIN(u32LocalCalcPhaseD,65535);
               }
            }
         }
         break;

      case LSUSMAINOXCHEAT_PHASE_E:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2US_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsUsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               if (LsSys_bAcvLsUsMainOxCHeatLo != 0)
               {
                  VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_F);
               }
            }
         }
         break;

      case LSUSMAINOXCHEAT_PHASE_F:
         if (  (u8LocalCoPTSt_stEng == Coupe_cale)
            && (HEATSENO2US_stEngPrev != Coupe_cale))
         {
            VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         }
         else
         {
            if (bLocalAcvLsUsMainOxCHeatLih != 0)
            {
               VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_G);
            }
            else
            {
               VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
               if (  (u8LocalVehicle_active_state == VS_RUNNING)
                  && (u8LocalCoPTSt_stEng != Stop))
               {
                  if (  (LsSys_bLsUsBoostEnd == 0)
                     && (LsSys_tiLsUsDlyMainOxCPhaseB == 0))
                  {
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_C1);
                     LsSys_tiLsUsDlyMainOxCPhaseC = 0;
                     LsSys_tiLsUsDlyMainOxCPhaseD = 0;
                     LsSys_tiLsUsBoostProtReq = 0;
                  }
                  else
                  {
                     LsSys_tiLsUsDlyMainOxCPhaseC = 1;
                     LsSys_tiLsUsDlyMainOxCPhaseD = 0;
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_C2);
                  }
               }
               else
               {
                  if (LsSys_bLsUsMainOxCHeatLoEnd != 0)
                  {
                     VEMS_vidSET(LsSys_stLsUsMainOxCHeat,
                                 LSUSMAINOXCHEAT_PHASE_A);
                  }
               }
            }
         }
         break;

      case LSUSMAINOXCHEAT_PHASE_G:
         if (bLocalAcvLsUsMainOxCHeatLih == 0)
         {
            VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(LsSys_stLsUsMainOxCHeat, LSUSMAINOXCHEAT_PHASE_A);
         break;
   }
   HEATSENO2US_stEngPrev = (uint8)MATHSRV_udtMIN(u8LocalCoPTSt_stEng, 15);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2US_vidOxCHeatReq                                  */
/* !Description :  Requête de maintien de la chauffe catalyseur en cas de     */
/*                 stratégie FLO                                              */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean LsSys_bLsUsMainOxCHeatFloEna;                               */
/*  input boolean LsSys_bLsUsMainOxCDewProtReq;                               */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  output boolean LsSys_bLsFloOxCHeatReq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2US_vidOxCHeatReq(void)
{
   boolean bLocalLsUsMainOxCDewProtReq;
   boolean bLocalLsSysbLsUsMainOxCHeatFloEn;
   uint8   u8LocalLsSys_stLsUsMainOxCHeat;


   VEMS_vidGET(LsSys_bLsUsMainOxCHeatFloEna, bLocalLsSysbLsUsMainOxCHeatFloEn);
   VEMS_vidGET(LsSys_bLsUsMainOxCDewProtReq, bLocalLsUsMainOxCDewProtReq);
   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   if (  (bLocalLsSysbLsUsMainOxCHeatFloEn != 0)
      && (bLocalLsUsMainOxCDewProtReq != 0)
      && (  (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_C1)
         || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_C2)
         || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_D)
         || (u8LocalLsSys_stLsUsMainOxCHeat == LSUSMAINOXCHEAT_PHASE_E)))
   {
      VEMS_vidSET(LsSys_bLsFloOxCHeatReq, 1);
   }
   else
   {
      VEMS_vidSET(LsSys_bLsFloOxCHeatReq, 0);
   }

}
/*------------------------------- end of file --------------------------------*/