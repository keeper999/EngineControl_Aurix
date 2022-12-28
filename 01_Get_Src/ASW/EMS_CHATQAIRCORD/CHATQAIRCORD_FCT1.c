/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CHATQAIRCORD                                            */
/* !Description     : CHATQAIRCORD component.                                 */
/*                                                                            */
/* !Module          : CHATQAIRCORD                                            */
/* !Description     : CALCUL DE LA CONSIGNE D'AIR LORS D'UNE RÉGULATION ASR.  */
/*                                                                            */
/* !File            : CHATQAIRCORD_FCT1.C                                     */
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
/*   1 / CHATQAIRCORD_vidInitOutput                                           */
/*   2 / CHATQAIRCORD_vidCalcConsigRegASR                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5139605 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_1240 / 2.6                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/CHATQAIRCORD/CHAT$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CHATQAIRCORD.h"
#include "CHATQAIRCORD_L.h"
#include "CHATQAIRCORD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHATQAIRCORD_vidInitOutput                                 */
/* !Description :  Initialisation des variables de sortie.                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 TqSys_tqCkEfcFil;                                            */
/*  input sint16 CHATQAIRCORD_s16FilterOutput;                                */
/*  output sint8 CoCha_noCylCutAuthIt;                                        */
/*  output sint16 CoCha_tqEfcASRAirReq;                                       */
/*  output sint16 TqCha_tqAirTqDecReq;                                        */
/*  output sint16 TqCha_tqAirTqIncReq;                                        */
/*  output sint16 CoCha_tqAirFil_MP;                                          */
/*  output sint16 CHATQAIRCORD_s16FilterOutput;                               */
/*  output sint32 CHATQAIRCORD_s32FilterKMem;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHATQAIRCORD_vidInitOutput(void)
{
   sint16  s16LocalTqSys_tqCkEfcFil;


   VEMS_vidGET(TqSys_tqCkEfcFil, s16LocalTqSys_tqCkEfcFil);

   VEMS_vidSET(CoCha_noCylCutAuthIt, 0);
   VEMS_vidSET(CoCha_tqEfcASRAirReq, 0);
   VEMS_vidSET(TqCha_tqAirTqDecReq, 0);
   VEMS_vidSET(TqCha_tqAirTqIncReq, 0);
   CoCha_tqAirFil_MP = 0;
   CHATQAIRCORD_s16FilterOutput = s16LocalTqSys_tqCkEfcFil;
   CHATQAIRCORD_s32FilterKMem = (sint32)(CHATQAIRCORD_s16FilterOutput * 256);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHATQAIRCORD_vidCalcConsigRegASR                           */
/* !Description :  Cette fonction calcule la consigne de couple AIR lors de la*/
/*                 régulation ASR et le nombre de cylindre autorisé à couper  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_06145_001.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TPM_bExThermoProt;                                          */
/*  input boolean CoCha_bTqReqASR;                                            */
/*  input boolean CoCha_bASRSecuReq;                                          */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqCkEfcFil;                                            */
/*  input sint16 EngLim_tqEfcEngCurMin;                                       */
/*  input sint16 Cha_tqDynASRReq;                                             */
/*  input sint16 Cha_tqAirMSRReq;                                             */
/*  input sint16 CoCha_tqEfcMSRReq;                                           */
/*  input sint16 Cha_tqAirASRReq;                                             */
/*  input uint16 CoCha_nEngBkpt_A[12];                                        */
/*  input boolean CoCha_bAcvCutSelASR_C;                                      */
/*  input boolean CoCha_bAcvCutSelSecu_C;                                     */
/*  input uint16 CoCha_rAirLdBkpt_A[12];                                      */
/*  input uint8 CoCha_noCylCutAuth_M[12][12];                                 */
/*  input boolean CoCha_bOfsClcTyp_C;                                         */
/*  input uint16 CoCha_tqDifTqBkpt_A[12];                                     */
/*  input uint16 CHATQAIRCORD_u16CoChaTqDifT;                                 */
/*  input uint16 CoCha_tqOfsDif_M[12][12];                                    */
/*  input uint16 CoCha_tqDeltaASROfs_MP;                                      */
/*  input sint16 CoCha_tqAirFil_MP;                                           */
/*  input sint16 CHATQAIRCORD_s16FilterOutput;                                */
/*  input boolean CoCha_bTypFil_MP;                                           */
/*  input uint8 CoCha_facTauDownThermo_C;                                     */
/*  input uint8 CoCha_facTauDown_T[12];                                       */
/*  input uint8 CoCha_facTauUpThermo_C;                                       */
/*  input uint8 CoCha_facTauUp_C;                                             */
/*  input sint32 CHATQAIRCORD_s32FilterKMem;                                  */
/*  input sint16 CoCha_tqLimMin_C;                                            */
/*  input boolean TqCha_bTqASRSel_C;                                          */
/*  input boolean TqCha_bTqMSRSel_C;                                          */
/*  output sint8 CoCha_noCylCutAuthIt;                                        */
/*  output uint16 CHATQAIRCORD_u16CoChaTqDifT;                                */
/*  output uint16 CoCha_tqDeltaASROfs_MP;                                     */
/*  output boolean CoCha_bTypFil_MP;                                          */
/*  output sint16 CHATQAIRCORD_s16FilterOutput;                               */
/*  output sint32 CHATQAIRCORD_s32FilterKMem;                                 */
/*  output sint16 CoCha_tqAirFil_MP;                                          */
/*  output sint16 CoCha_tqEfcASRAirReq;                                       */
/*  output sint16 TqCha_tqAirTqDecReq;                                        */
/*  output sint16 TqCha_tqAirTqIncReq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHATQAIRCORD_vidCalcConsigRegASR(void)
{
   boolean  bLocalInhESPReq;
   boolean  bLocalCoCha_bTqReqASR;
   boolean  bLocalCoCha_bASRSecuReq;
   boolean  bLocalTPM_bExThermoProt;
   uint8    u8LocalCoCha_noCylCutAuth;
   uint8    u8LocalTqSysGain;
   uint16   u16LocalCalcParaCutAuthX;
   uint16   u16LocalCalcParaY;
   uint16   u16LocalCalParaTqOfsDifX;
   uint16   u16LocalCoChaTqDeltaASROf_MP;
   uint16   u16LocalEngM_rAirLdCor;
   uint16   u16LocalEng_nCkFil;
   sint8    s8LocalCoCha_noCylCutAuth;
   sint16   s16LocalFilterinput;
   sint16   s16LocalCoCha_tqAirFil_MP;
   sint16   s16LocalTqCha_tqAirTqDecReq;
   sint16   s16LocalCha_tqAirASRReq;
   sint16   s16LocalCha_tqAirMSRReq;
   sint16   s16LocalCha_tqDynASRReq;
   sint16   s16LocalTqSys_tqCkEfcFil;
   sint16   s16LocalTqCha_tqAirTqIncReq;
   sint16   s16LocalCoCha_tqEfcASRAirReq;
   sint16   s16LocalCoCha_tqEfcMSRReq;
   sint16   s16LocalEngLim_tqEfcEngCurMin;
   sint16   s16LocalCoCha_noCylCutAuth;
   sint32   s32LocaltqAirFil;
   sint32   s32LocalCoCha_tqDifTq;


   VEMS_vidGET(TPM_bExThermoProt, bLocalTPM_bExThermoProt);
   VEMS_vidGET(CoCha_bTqReqASR, bLocalCoCha_bTqReqASR);
   VEMS_vidGET(CoCha_bASRSecuReq, bLocalCoCha_bASRSecuReq);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqCkEfcFil, s16LocalTqSys_tqCkEfcFil);
   VEMS_vidGET(EngLim_tqEfcEngCurMin, s16LocalEngLim_tqEfcEngCurMin);
   VEMS_vidGET(Cha_tqDynASRReq, s16LocalCha_tqDynASRReq);
   VEMS_vidGET(Cha_tqAirMSRReq, s16LocalCha_tqAirMSRReq);
   VEMS_vidGET(CoCha_tqEfcMSRReq, s16LocalCoCha_tqEfcMSRReq);
   VEMS_vidGET(Cha_tqAirASRReq, s16LocalCha_tqAirASRReq);


   /* Producing variable "CoCha_noCylCutAuthIt" */
   bLocalInhESPReq = GDGAR_bGetFRM(FRM_FRM_INHESPREQ);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(CoCha_nEngBkpt_A, u16LocalEng_nCkFil, 12);
   if (  (bLocalInhESPReq == 0)
      && (  (  (bLocalCoCha_bTqReqASR != 0)
            && (CoCha_bAcvCutSelASR_C != 0))
         || (  (bLocalCoCha_bASRSecuReq != 0)
            && (CoCha_bAcvCutSelSecu_C != 0))))
   {
      u16LocalCalcParaCutAuthX =
         MATHSRV_u16CalcParaIncAryU16(CoCha_rAirLdBkpt_A,
                                      u16LocalEngM_rAirLdCor, 12);
      u8LocalCoCha_noCylCutAuth =
         MATHSRV_u8Interp2d(&CoCha_noCylCutAuth_M[0][0],
                            u16LocalCalcParaCutAuthX,
                            u16LocalCalcParaY,
                            12);
      s16LocalCoCha_noCylCutAuth = (sint16)(u8LocalCoCha_noCylCutAuth - 1);
      s8LocalCoCha_noCylCutAuth =
         (sint8)MATHSRV_udtMIN(s16LocalCoCha_noCylCutAuth, 6);
   }
   else
   {
      s8LocalCoCha_noCylCutAuth = -1;
   }
   VEMS_vidSET(CoCha_noCylCutAuthIt, s8LocalCoCha_noCylCutAuth);

   /* Producing variable "CoCha_tqDeltaASROfs_MP"*/
   if (CoCha_bOfsClcTyp_C != 0)
   {
      s32LocalCoCha_tqDifTq =
         (sint32)(s16LocalCha_tqDynASRReq - s16LocalEngLim_tqEfcEngCurMin);
   }
   else
   {
      s32LocalCoCha_tqDifTq = s16LocalCha_tqDynASRReq;
   }
   s32LocalCoCha_tqDifTq = s32LocalCoCha_tqDifTq + 32000;
   CHATQAIRCORD_u16CoChaTqDifT =
      (uint16)MATHSRV_udtCLAMP(s32LocalCoCha_tqDifTq, 0, 65535);
   u16LocalCalParaTqOfsDifX =
      MATHSRV_u16CalcParaIncAryU16(CoCha_tqDifTqBkpt_A,
                                   CHATQAIRCORD_u16CoChaTqDifT,
                                   12);
   u16LocalCoChaTqDeltaASROf_MP = MATHSRV_u16Interp2d(&CoCha_tqOfsDif_M[0][0],
                                                      u16LocalCalParaTqOfsDifX,
                                                      u16LocalCalcParaY,
                                                      12);
   CoCha_tqDeltaASROfs_MP =
      (uint16)MATHSRV_udtMIN(u16LocalCoChaTqDeltaASROf_MP, 32000);

   /* Producing variable "CoCha_bTypFil_MP"*/
   s32LocaltqAirFil =
      (sint32)(s16LocalCha_tqDynASRReq + CoCha_tqDeltaASROfs_MP);
   if (s32LocaltqAirFil < CoCha_tqAirFil_MP)
   {
      CoCha_bTypFil_MP = 1;
   }
   else
   {
      CoCha_bTypFil_MP = 0;
   }

   /* Producing variable "CoCha_tqEfcASRAirReq"*/
   if (bLocalCoCha_bTqReqASR == 0)
   {
      CHATQAIRCORD_s16FilterOutput = s16LocalTqSys_tqCkEfcFil;
      CHATQAIRCORD_s32FilterKMem = (sint32)(CHATQAIRCORD_s16FilterOutput * 256);
   }
   else
   {
      if (CoCha_bTypFil_MP != 0)
      {
         if (bLocalTPM_bExThermoProt != 0)
         {
            u8LocalTqSysGain = CoCha_facTauDownThermo_C;
         }
         else
         {
            u8LocalTqSysGain = MATHSRV_u8Interp1d(CoCha_facTauDown_T,
                                                  u16LocalCalcParaY);
         }
      }
      else
      {
         if (bLocalTPM_bExThermoProt != 0)
         {
            u8LocalTqSysGain = CoCha_facTauUpThermo_C;
         }
         else
         {
            u8LocalTqSysGain = CoCha_facTauUp_C;
         }
      }
      s16LocalFilterinput = (sint16)MATHSRV_udtMIN(s32LocaltqAirFil, 32767);
      if (u8LocalTqSysGain < 128)
      {
         u8LocalTqSysGain = (uint8)(u8LocalTqSysGain * 2);
         CHATQAIRCORD_s16FilterOutput =
            MATHSRV_s16FirstOrderFilterGu8(u8LocalTqSysGain,
                                           &CHATQAIRCORD_s32FilterKMem,
                                           s16LocalFilterinput);
      }
      else
      {
         CHATQAIRCORD_s16FilterOutput = s16LocalFilterinput;
         CHATQAIRCORD_s32FilterKMem =
            (sint32)(CHATQAIRCORD_s16FilterOutput * 256);
      }
   }
   s16LocalCoCha_tqAirFil_MP =
      (sint16)MATHSRV_udtMIN(CHATQAIRCORD_s16FilterOutput,
                             s16LocalTqSys_tqCkEfcFil);

   /* Producing variable "CoCha_tqAirFil_MP" */
   CoCha_tqAirFil_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalCoCha_tqAirFil_MP, -32000, 32000);

   s16LocalCoCha_tqEfcASRAirReq =
      (sint16)MATHSRV_udtMAX(s16LocalCoCha_tqAirFil_MP, CoCha_tqLimMin_C);
   s16LocalCoCha_tqEfcASRAirReq =
      (sint16)MATHSRV_udtCLAMP(s16LocalCoCha_tqEfcASRAirReq, -32000, 32000);
   VEMS_vidSET(CoCha_tqEfcASRAirReq, s16LocalCoCha_tqEfcASRAirReq);

   /* Producing variable "TqCha_tqAirTqDecReq"*/
   if (bLocalCoCha_bTqReqASR != 0)
   {
      if (TqCha_bTqASRSel_C != 0)
      {
         s16LocalTqCha_tqAirTqDecReq = s16LocalCha_tqAirASRReq;
      }
      else
      {
         s16LocalTqCha_tqAirTqDecReq = s16LocalCoCha_tqEfcASRAirReq;
      }
   }
   else
   {
      s16LocalTqCha_tqAirTqDecReq = s16LocalCha_tqDynASRReq;
   }
   s16LocalTqCha_tqAirTqDecReq =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqCha_tqAirTqDecReq, -32000, 32000);
   VEMS_vidSET(TqCha_tqAirTqDecReq, s16LocalTqCha_tqAirTqDecReq);

   /* Producing variable "TqCha_tqAirTqIncReq" */
   if (TqCha_bTqMSRSel_C != 0)
   {
      s16LocalTqCha_tqAirTqIncReq = s16LocalCha_tqAirMSRReq;
   }
   else
   {
      s16LocalTqCha_tqAirTqIncReq = s16LocalCoCha_tqEfcMSRReq;
   }
   s16LocalTqCha_tqAirTqIncReq =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqCha_tqAirTqIncReq, -32000, 32000);
   VEMS_vidSET(TqCha_tqAirTqIncReq, s16LocalTqCha_tqAirTqIncReq);
}
/*-------------------------------- end of file -------------------------------*/