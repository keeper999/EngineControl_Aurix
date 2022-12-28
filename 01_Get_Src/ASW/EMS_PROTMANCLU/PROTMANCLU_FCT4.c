/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTMANCLU                                              */
/* !Description     : PROTMANCLU Component                                    */
/*                                                                            */
/* !Module          : PROTMANCLU                                              */
/* !Description     : Clutch protection for manual gearbox                    */
/*                                                                            */
/* !File            : PROTMANCLU_FCT4.C                                       */
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
/*   1 / PROTMANCLU_vidCalculationOffsets                                     */
/*   2 / PROTMANCLU_vidDeactvEngRotSpdctr                                     */
/*   3 / PROTMANCLU_vidActivProtections                                       */
/*   4 / PROTMANCLU_vidActivOfProtection                                      */
/*   5 / PROTMANCLU_vidReconfigProtActiv                                      */
/*   6 / PROTMANCLU_vidOutput_managment                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 04687 / 01                                        */
/* !OtherRefs   : 01460_10_03770/1.1                                          */
/* !OtherRefs   : VEMS V02 ECU#056597                                         */
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
#include "PROTMANCLU.h"
#include "PROTMANCLU_l.h"
#include "PROTMANCLU_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidCalculationOffsets                           */
/* !Description :  This function calculates 3 negative temperature offsets.   */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 PtLim_tGrdDynCluT;                                           */
/*  input uint16 PtLim_tTGrdFanProtCluLo_A[4];                                */
/*  input uint8 PtLim_tOfsCluFanProtLoT_T[4];                                 */
/*  input uint16 PtLim_tTGrdFanProtCluHi_A[4];                                */
/*  input uint8 PtLim_tOfsCluFanProtHiT_T[4];                                 */
/*  input uint16 PtLim_tTGrdNRegClu_A[4];                                     */
/*  input uint8 PtLim_tOfsCluNRegT_T[4];                                      */
/*  input uint16 PtLim_tTGrdStopWarnClu_A[4];                                 */
/*  input uint8 PtLim_tOfsCluStopWarnT_T[4];                                  */
/*  output sint8 PtLim_tOfsCluFanProtLoT;                                     */
/*  output sint8 PtLim_tOfsCluFanProtHiT;                                     */
/*  output sint8 PtLim_tOfsCluNRegT;                                          */
/*  output sint8 PtLim_tOfsCluStopWarnT;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidCalculationOffsets(void)
{
   /* F04_02_Calculation_of_4_offsets */
   uint8  u8LocalInterp1d;
   sint16 s16LocalPtLim;
   uint16 u16LocalPtLim_tGrdDynCluT;
   uint16 u16LocalCalcParaX;


   u16LocalPtLim_tGrdDynCluT = (uint16)MATHSRV_udtMAX(PtLim_tGrdDynCluT, 0);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(PtLim_tTGrdFanProtCluLo_A,
                                                    u16LocalPtLim_tGrdDynCluT,
                                                    4);
   u8LocalInterp1d =
      MATHSRV_u8Interp1d(PtLim_tOfsCluFanProtLoT_T, u16LocalCalcParaX);
   s16LocalPtLim = (sint16)(u8LocalInterp1d - 100);
   PtLim_tOfsCluFanProtLoT = (sint8)MATHSRV_udtMIN(s16LocalPtLim, 0);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(PtLim_tTGrdFanProtCluHi_A,
                                                    u16LocalPtLim_tGrdDynCluT,
                                                    4);
   u8LocalInterp1d =
      MATHSRV_u8Interp1d(PtLim_tOfsCluFanProtHiT_T, u16LocalCalcParaX);
   s16LocalPtLim = (sint16)(u8LocalInterp1d - 100);
   PtLim_tOfsCluFanProtHiT = (sint8)MATHSRV_udtMIN(s16LocalPtLim, 0);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(PtLim_tTGrdNRegClu_A,
                                                    u16LocalPtLim_tGrdDynCluT,
                                                    4);
   u8LocalInterp1d =
      MATHSRV_u8Interp1d(PtLim_tOfsCluNRegT_T, u16LocalCalcParaX);
   s16LocalPtLim = (sint16)(u8LocalInterp1d - 100);
   PtLim_tOfsCluNRegT = (sint8)MATHSRV_udtMIN(s16LocalPtLim, 0);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(PtLim_tTGrdStopWarnClu_A,
                                                    u16LocalPtLim_tGrdDynCluT,
                                                    4);
   u8LocalInterp1d =
      MATHSRV_u8Interp1d(PtLim_tOfsCluStopWarnT_T, u16LocalCalcParaX);
   s16LocalPtLim = (sint16)(u8LocalInterp1d - 100);
   PtLim_tOfsCluStopWarnT = (sint8)MATHSRV_udtMIN(s16LocalPtLim, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidDeactvEngRotSpdctr                           */
/* !Description :  This function disables the protection by regulation of the */
/*                 engine rotation speed in two cases: if the ASR controls the*/
/*                 engine rotation speed or if the chassis functions controls */
/*                 the engine rotation speed.                                 */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input boolean Ext_bASRReg;                                                */
/*  input boolean PROTMANCLU_bTurnOffDelayInPrev;                             */
/*  input uint8 PtLim_tiDlyTmp_C;                                             */
/*  input uint16 PROTMANCLU_u16TurnOffDelayCount;                             */
/*  output boolean PtLim_bDeacManCluProtReg;                                  */
/*  output uint16 PROTMANCLU_u16TurnOffDelayCount;                            */
/*  output boolean PROTMANCLU_bTurnOffDelayInPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidDeactvEngRotSpdctr(void)
{
   /*F04_03_Deactivation_the_engine_rotation_speed_control*/
   boolean bLocalExt_bASRReg;
   boolean bLocalTurnOffDelayIn;
   uint8   u8LocalCha_stTqReq;


   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqReq);
   VEMS_vidGET(Ext_bASRReg, bLocalExt_bASRReg);
   if (  (u8LocalCha_stTqReq == 5)
      || (bLocalExt_bASRReg != 0))
   {
      bLocalTurnOffDelayIn = 1;
   }
   else
   {
      bLocalTurnOffDelayIn = 0;
   }

   if (bLocalTurnOffDelayIn != 0)
   {
      PtLim_bDeacManCluProtReg = 1;
   }
   else
   {
      if (PROTMANCLU_bTurnOffDelayInPrev != 0)
      {
         PROTMANCLU_u16TurnOffDelayCount =
            (uint16)(((PtLim_tiDlyTmp_C * 25) + 8) / 16);
      }
      else
      {
         if (PROTMANCLU_u16TurnOffDelayCount > 0)
         {
            PROTMANCLU_u16TurnOffDelayCount =
               (uint16)(PROTMANCLU_u16TurnOffDelayCount - 1);
         }
      }
      if (PROTMANCLU_u16TurnOffDelayCount == 0)
      {
         PtLim_bDeacManCluProtReg = 0;
      }
      else
      {
         PtLim_bDeacManCluProtReg = 1;
      }
   }
   PROTMANCLU_bTurnOffDelayInPrev = bLocalTurnOffDelayIn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidActivProtections                             */
/* !Description :  This function enables 3 clutch protections and a diagnostic*/
/*                 code.                                                      */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidActivOfProtection();                       */
/*  extf argret void PROTMANCLU_vidReconfigProtActiv();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidActivProtections(void)
{
   /*F04_04_Activation_of_protections*/
   PROTMANCLU_vidActivOfProtection();
   PROTMANCLU_vidReconfigProtActiv();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidActivOfProtection                            */
/* !Description :  This function enables 4 clutch protections.                */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 PtLim_tThdAcvProtStopWarn_C;                                  */
/*  input sint8 PtLim_tOfsCluStopWarnT;                                       */
/*  input uint8 PtLim_tOfsConT_C;                                             */
/*  input sint16 CoPt_tManCluEstimBfCord;                                     */
/*  input uint8 PtLim_tThdAcvProtNReg_C;                                      */
/*  input sint8 PtLim_tOfsCluNRegT;                                           */
/*  input uint8 PtLim_tThdAcvProtFanHi_C;                                     */
/*  input sint8 PtLim_tOfsCluFanProtHiT;                                      */
/*  input uint8 PtLim_tThdAcvProtFanLo_C;                                     */
/*  input sint8 PtLim_tOfsCluFanProtLoT;                                      */
/*  input boolean PROTMANCLU_bOutHysPos1;                                     */
/*  input boolean PROTMANCLU_bOutHysPos2;                                     */
/*  input boolean PtLim_bDeacManCluProtReg;                                   */
/*  input boolean PROTMANCLU_bOutHysPos3;                                     */
/*  input boolean PROTMANCLU_bOutHysPos4;                                     */
/*  output boolean PROTMANCLU_bOutHysPos1;                                    */
/*  output boolean PROTMANCLU_bOutHysPos2;                                    */
/*  output boolean PROTMANCLU_bOutHysPos3;                                    */
/*  output boolean PROTMANCLU_bOutHysPos4;                                    */
/*  output uint8 PtLim_noProtManClu;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidActivOfProtection(void)
{
   /*F04_04_01_Activation_of_protections */
   uint16  u16LocalMul;
   sint16  s16LocalCoPt_tManCluEstimBfHi;
   sint32  s32LocalCoPt_tManCluEstimBfLo;


   /*HysPos1*/
   s16LocalCoPt_tManCluEstimBfHi =
      (sint16)(  (  (PtLim_tThdAcvProtStopWarn_C * 2)
                 +  PtLim_tOfsCluStopWarnT)
              *  16);
   u16LocalMul = (uint16)(PtLim_tOfsConT_C * 16);
   s32LocalCoPt_tManCluEstimBfLo =
      (sint32)(s16LocalCoPt_tManCluEstimBfHi - (sint16)u16LocalMul);
   if ((sint32)CoPt_tManCluEstimBfCord <= s32LocalCoPt_tManCluEstimBfLo)
   {
      PROTMANCLU_bOutHysPos1 = 0;
   }
   else
   {
      if (CoPt_tManCluEstimBfCord >= s16LocalCoPt_tManCluEstimBfHi)
      {
         PROTMANCLU_bOutHysPos1 = 1;
      }
   }
   /*HysPos2*/
   s16LocalCoPt_tManCluEstimBfHi =
      (sint16)(((PtLim_tThdAcvProtNReg_C * 2) + PtLim_tOfsCluNRegT) * 16);
   s32LocalCoPt_tManCluEstimBfLo =
      (sint32)(s16LocalCoPt_tManCluEstimBfHi - (PtLim_tOfsConT_C * 16));
   if ((sint32)CoPt_tManCluEstimBfCord <= s32LocalCoPt_tManCluEstimBfLo)
   {
      PROTMANCLU_bOutHysPos2 = 0;
   }
   else
   {
      if (CoPt_tManCluEstimBfCord >= s16LocalCoPt_tManCluEstimBfHi)
      {
         PROTMANCLU_bOutHysPos2 = 1;
      }
   }
   /*HysPos3*/
   s16LocalCoPt_tManCluEstimBfHi =
      (sint16)(((PtLim_tThdAcvProtFanHi_C * 2) + PtLim_tOfsCluFanProtHiT) * 16);
   s32LocalCoPt_tManCluEstimBfLo =
      (sint32)(s16LocalCoPt_tManCluEstimBfHi - (PtLim_tOfsConT_C * 16));
   if ((sint32)CoPt_tManCluEstimBfCord <= s32LocalCoPt_tManCluEstimBfLo)
   {
      PROTMANCLU_bOutHysPos3 = 0;
   }
   else
   {
      if (CoPt_tManCluEstimBfCord >= s16LocalCoPt_tManCluEstimBfHi)
      {
         PROTMANCLU_bOutHysPos3 = 1;
      }
   }
   /*HysPos4*/
   s16LocalCoPt_tManCluEstimBfHi =
      (sint16)(((PtLim_tThdAcvProtFanLo_C * 2) + PtLim_tOfsCluFanProtLoT) * 16);
   s32LocalCoPt_tManCluEstimBfLo =
      (sint32)(s16LocalCoPt_tManCluEstimBfHi - (PtLim_tOfsConT_C * 16));
   if ((sint32)CoPt_tManCluEstimBfCord <= s32LocalCoPt_tManCluEstimBfLo)
   {
      PROTMANCLU_bOutHysPos4 = 0;
   }
   else
   {
      if (CoPt_tManCluEstimBfCord >= s16LocalCoPt_tManCluEstimBfHi)
      {
         PROTMANCLU_bOutHysPos4 = 1;
      }
   }

   if (PROTMANCLU_bOutHysPos1 == 0)
   {
      if (  (  (PROTMANCLU_bOutHysPos2 == 0)
            && (PtLim_bDeacManCluProtReg == 0))
         || (PtLim_bDeacManCluProtReg != 0))
      {
         if (PROTMANCLU_bOutHysPos3 == 0)
         {
            if (PROTMANCLU_bOutHysPos4 == 0)
            {
               PtLim_noProtManClu = 0;
            }
            else
            {
               PtLim_noProtManClu = 1;
            }
         }
         else
         {
            PtLim_noProtManClu = 2;
         }
      }
      else
      {
         PtLim_noProtManClu = 3;
      }
   }
   else
   {
      PtLim_noProtManClu = 4;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidReconfigProtActiv                            */
/* !Description :  This function reconfigures 4 clutch protections. It also   */
/*                 activates: a boolean giving the damaging diagnostic and a  */
/*                 boolean for monitoring activation.                         */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 PtLim_spdThdLoDeacProtReg_C;                                  */
/*  input uint8 PtLim_spdThdHiDeacProtReg_C;                                  */
/*  input uint8 PtLim_noProtManClu;                                           */
/*  input boolean PROTMANCLU_bOutHysPos;                                      */
/*  input uint8 PtLim_rSpdFanReqProtManCluLo_C;                               */
/*  input boolean PROTMANCLU_bBasculeRS;                                      */
/*  input uint8 PtLim_rSpdFanReqProtManCluHi_C;                               */
/*  output boolean CoPt_bMonRunCluDmgAftsBfCord;                              */
/*  output boolean PROTMANCLU_bOutHysPos;                                     */
/*  output boolean PROTMANCLU_bBasculeRS;                                     */
/*  output boolean CoPt_bAcvProtCluBfCord;                                    */
/*  output boolean CoPt_bWarnProtCluBfCord;                                   */
/*  output boolean CoPt_bDgoCluDmgAftsBfCord;                                 */
/*  output uint8 CoPt_rSpdFanReqProtCluBfCord;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidReconfigProtActiv(void)
{
   /* F04_04_02_Reconfiguration_of_protection_activations */
   boolean bLocalInhManCluProt;
   uint8   u8LocalSpdFanReqProtCluBfCord;
   uint8   u8LocalSpdFanReqProtCluBfCord1;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalComp;


   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   bLocalInhManCluProt = GDGAR_bGetFRM(FRM_FRM_INHMANCLUPROT);
   CoPt_bMonRunCluDmgAftsBfCord = 1;

   /*HysPos*/
   u16LocalComp = (uint16)(PtLim_spdThdLoDeacProtReg_C * 128);
   if (u16LocalVeh_spdVeh <= u16LocalComp)
   {
      PROTMANCLU_bOutHysPos = 0;
   }
   else
   {
      u16LocalComp = (uint16)(PtLim_spdThdHiDeacProtReg_C * 128);
      if (u16LocalVeh_spdVeh >= u16LocalComp)
      {
         PROTMANCLU_bOutHysPos = 1;
      }
   }

   /*Bascule RS*/
   if (  (PtLim_noProtManClu == 3)
      || (PtLim_noProtManClu == 4))
   {
      if (PROTMANCLU_bOutHysPos == 0)
      {
         PROTMANCLU_bBasculeRS = 1;
      }
   }
   else
   {
      PROTMANCLU_bBasculeRS = 0;
   }

   if (bLocalInhManCluProt != 0)
   {
      CoPt_bAcvProtCluBfCord = 1;
      u8LocalSpdFanReqProtCluBfCord1 = PtLim_rSpdFanReqProtManCluLo_C;

      CoPt_bWarnProtCluBfCord = 0;
      CoPt_bDgoCluDmgAftsBfCord = 0;
   }
   else
   {
      CoPt_bAcvProtCluBfCord = PROTMANCLU_bBasculeRS;
      if (PtLim_noProtManClu == 4)
      {
         u8LocalSpdFanReqProtCluBfCord1 = PtLim_rSpdFanReqProtManCluLo_C;
         CoPt_bWarnProtCluBfCord = 1;
         CoPt_bDgoCluDmgAftsBfCord = 1;
      }
      else
      {
         CoPt_bWarnProtCluBfCord = 0;
         CoPt_bDgoCluDmgAftsBfCord = 0;
         if (PtLim_noProtManClu != 0)
         {
            u8LocalSpdFanReqProtCluBfCord1 = PtLim_rSpdFanReqProtManCluLo_C;
         }
         else
         {
            u8LocalSpdFanReqProtCluBfCord1 = 0;
         }
      }
   }

   if (PtLim_noProtManClu >= 2)
   {
      u8LocalSpdFanReqProtCluBfCord = PtLim_rSpdFanReqProtManCluHi_C;
   }
   else
   {
      u8LocalSpdFanReqProtCluBfCord = u8LocalSpdFanReqProtCluBfCord1;
   }

   CoPt_rSpdFanReqProtCluBfCord =
      (uint8)MATHSRV_udtMIN(u8LocalSpdFanReqProtCluBfCord, 110);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidOutput_managment                             */
/* !Description :  This function manages outputs.                             */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_035.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean PtLim_bAcvProtManClu_C;                                     */
/*  input boolean CoPt_bWarnProtCluBfCord;                                    */
/*  input boolean CoPt_bAcvProtCluBfCord;                                     */
/*  input boolean CoPt_bDgoCluDmgAftsBfCord;                                  */
/*  input boolean CoPt_bMonRunCluDmgAftsBfCord;                               */
/*  input sint16 CoPt_tManCluEstimBfCord;                                     */
/*  input uint8 CoPt_rSpdFanReqProtCluBfCord;                                 */
/*  output boolean CoPt_bWarnProtClu;                                         */
/*  output boolean CoPt_bAcvProtCluP;                                         */
/*  output boolean CoPt_bDgoCluDmgAfts;                                       */
/*  output boolean CoPt_bMonRunCluDmgAfts;                                    */
/*  output sint16 CoPt_tManCluEstim;                                          */
/*  output uint8 CoPt_rSpdFanReqProtManClu;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidOutput_managment(void)
{
   /*F05_Output_managment*/
   boolean  bLocalCoPt_bWarnProtClu;
   boolean  bLocalCoPt_bAcvProtCluP;
   boolean  bLocalCoPt_bDgoCluDmgAfts;
   boolean  bLocalCoPt_bMonRunCluDmgAfts;
   uint8    u8LocalExt_stGBxCf;
   uint8    u8LocalCoPt_rSpdFanReqProtManClu;
   sint16   s16LocalCoPt_tManCluEstim;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (  (u8LocalExt_stGBxCf == 0)
      && (PtLim_bAcvProtManClu_C != 0))
   {
      bLocalCoPt_bWarnProtClu = CoPt_bWarnProtCluBfCord;
      bLocalCoPt_bAcvProtCluP = CoPt_bAcvProtCluBfCord;
      bLocalCoPt_bDgoCluDmgAfts = CoPt_bDgoCluDmgAftsBfCord;
      bLocalCoPt_bMonRunCluDmgAfts = CoPt_bMonRunCluDmgAftsBfCord;
      s16LocalCoPt_tManCluEstim = CoPt_tManCluEstimBfCord;
      u8LocalCoPt_rSpdFanReqProtManClu = CoPt_rSpdFanReqProtCluBfCord;
   }
   else
   {
      bLocalCoPt_bWarnProtClu = 0;
      bLocalCoPt_bAcvProtCluP = 0;
      bLocalCoPt_bDgoCluDmgAfts = 0;
      bLocalCoPt_bMonRunCluDmgAfts = 0;
      s16LocalCoPt_tManCluEstim = 320;
      u8LocalCoPt_rSpdFanReqProtManClu = 0;
   }
   VEMS_vidSET(CoPt_bWarnProtClu, bLocalCoPt_bWarnProtClu);
   VEMS_vidSET(CoPt_bAcvProtCluP, bLocalCoPt_bAcvProtCluP);
   VEMS_vidSET(CoPt_bDgoCluDmgAfts, bLocalCoPt_bDgoCluDmgAfts);
   VEMS_vidSET(CoPt_bMonRunCluDmgAfts, bLocalCoPt_bMonRunCluDmgAfts);

   s16LocalCoPt_tManCluEstim =
      (sint16)MATHSRV_udtCLAMP(s16LocalCoPt_tManCluEstim, -800, 16000);
   VEMS_vidSET(CoPt_tManCluEstim, s16LocalCoPt_tManCluEstim);
   u8LocalCoPt_rSpdFanReqProtManClu =
      (uint8)MATHSRV_udtMIN(u8LocalCoPt_rSpdFanReqProtManClu, 110);
   VEMS_vidSET(CoPt_rSpdFanReqProtManClu, u8LocalCoPt_rSpdFanReqProtManClu);
}

/*---------------------------------End Of File--------------------------------*/