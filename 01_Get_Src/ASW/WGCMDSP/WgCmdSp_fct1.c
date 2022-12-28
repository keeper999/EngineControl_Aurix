/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WgCmdSp                                                 */
/* !Description     : WgCmdSp component.                                      */
/*                                                                            */
/* !Module          : WgCmdSp                                                 */
/* !Description     : WASTEGATE SOLENOID VALVE COMMAND SETPOINT               */
/*                                                                            */
/* !File            : WGCMDSP_FCT1.C                                          */
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
/*   1 / WgCmdSp_vidClcPwmWg                                                  */
/*   2 / WgCmdSp_vidWgSysMng                                                  */
/*   3 / WgCmdSp_vidTranDetnClcErr                                            */
/*   4 / WgCmdSp_vidClcPwmOpenLoopCmd                                         */
/*   5 / WgCmdSp_vidClcOfsAlti                                                */
/*   6 / WgCmdSp_vidClcPwmOpenLoop                                            */
/*   7 / WgCmdSp_vidWgServoCdn                                                */
/*   8 / WgCmdSp_vidCdnOpenLoop                                               */
/*   9 / WgCmdSp_vidCdnServoCmd                                               */
/*   10 / WgCmdSp_vidCdnApplAdpv                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5070689 / 02                                        */
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
#include "VEMS.h"
#include "WgCmdSp.h"
#include "WgCmdSp_L.h"
#include "WgCmdSp_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcPwmWg                                        */
/* !Description :  The computation of the PWM setpoint                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidWgSysMng();                                   */
/*  extf argret void WgCmdSp_vidClcPID();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcPwmWg(void)
{
   WgCmdSp_vidWgSysMng();
   WgCmdSp_vidClcPID();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidWgSysMng                                        */
/* !Description :  The computation of the main parameters applying to  the    */
/*                 wastegate regulation                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidTranDetnClcErr();                             */
/*  extf argret void WgCmdSp_vidClcPwmOpenLoopCmd();                          */
/*  extf argret void WgCmdSp_vidWgServoCdn();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidWgSysMng(void)
{
   WgCmdSp_vidTranDetnClcErr();
   WgCmdSp_vidClcPwmOpenLoopCmd();
   WgCmdSp_vidWgServoCdn();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidTranDetnClcErr                                  */
/* !Description :  The pressure feedback error is computed considering the    */
/*                 setpoint and the measure of the supercharging pressure.    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AirSys_pUsThrReqFil;                                         */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 AirPres_pSpgPresSp;                                          */
/*  input uint16 AirPres_pSpgPresRawSp;                                       */
/*  input uint16 Acq_spg_pres_measured;                                       */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input boolean Wg_bWgCmdOplBenchModEna;                                    */
/*  input sint16 Wg_pUsThrErr;                                                */
/*  input sint16 Wg_pSpgThdPresErr_C;                                         */
/*  output sint16 Wg_pUsThrErr;                                               */
/*  output sint16 Wg_pSpgFilPresErr;                                          */
/*  output sint16 Wg_pSpgPresErr;                                             */
/*  output boolean Wg_bStsTranWg;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidTranDetnClcErr(void)
{
   boolean bLocalWg_bWgCmdOplBenchModEna;
   boolean bLocalTrbAct_bBoostPresClCtlAcv;
   uint16  u16LocalAcq_spg_pres_measured;
   uint16  u16LocalAirPres_pSpgPresSp;
   uint16  u16LocalAirPres_pSpgPresRawSp;
   uint16  u16LocalAirSys_pUsThrReqFil;
   uint16  u16LocalTrbAct_pUsThrFil;
   sint16  s16LocalWg_pSpgFilPresErr;
   sint16  s16LocalWg_pSpgPresErr;


   VEMS_vidGET(AirSys_pUsThrReqFil, u16LocalAirSys_pUsThrReqFil);
   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbAct_pUsThrFil);
   Wg_pUsThrErr = (sint16)( ( u16LocalAirSys_pUsThrReqFil
                                - u16LocalTrbAct_pUsThrFil)
                              / 2);

   VEMS_vidGET(AirPres_pSpgPresSp, u16LocalAirPres_pSpgPresSp);
   VEMS_vidGET(AirPres_pSpgPresRawSp, u16LocalAirPres_pSpgPresRawSp);
   VEMS_vidGET(Acq_spg_pres_measured, u16LocalAcq_spg_pres_measured);
   s16LocalWg_pSpgFilPresErr = (sint16)( ( u16LocalAirPres_pSpgPresSp
                                         - u16LocalAcq_spg_pres_measured)
                                       / 2);
   s16LocalWg_pSpgPresErr = (sint16)( ( u16LocalAirPres_pSpgPresRawSp
                                      - u16LocalAcq_spg_pres_measured)
                                    / 2);
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);
   VEMS_vidGET(Wg_bWgCmdOplBenchModEna, bLocalWg_bWgCmdOplBenchModEna);

   if (bLocalTrbAct_bBoostPresClCtlAcv != 0)
   {
      Wg_pSpgFilPresErr = Wg_pUsThrErr;
      Wg_pSpgPresErr    = Wg_pUsThrErr;
   }
   else
   {
      if (bLocalWg_bWgCmdOplBenchModEna == 0)
      {
         Wg_pSpgFilPresErr = s16LocalWg_pSpgFilPresErr;
         Wg_pSpgPresErr = s16LocalWg_pSpgPresErr;
      }
      else
      {
         Wg_pSpgFilPresErr = 0;
         Wg_pSpgPresErr    = 0;
      }
   }

   if (bLocalWg_bWgCmdOplBenchModEna == 0)
   {
      if (s16LocalWg_pSpgPresErr > Wg_pSpgThdPresErr_C)
      {
         Wg_bStsTranWg = 1;
      }
      else
      {
         Wg_bStsTranWg = 0;
      }
   }
   else
   {
      if (Wg_pSpgThdPresErr_C < 0 )
      {
         Wg_bStsTranWg = 1;
      }
      else
      {
         Wg_bStsTranWg = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcPwmOpenLoopCmd                               */
/* !Description :  This module computes the PWM open loop setpoint, which is  */
/*                 also filtered for the Wastegate feedback.                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidClcOfsAlti();                                 */
/*  extf argret void WgCmdSp_vidClcPwmOpenLoop();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcPwmOpenLoopCmd(void)
{
   WgCmdSp_vidClcOfsAlti();
   WgCmdSp_vidClcPwmOpenLoop();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcOfsAlti                                      */
/* !Description :  The pressure offset due to altitude variations concerns the*/
/*                 pressure inputs of the strategy lead to the supercharging  */
/*                 pressure feedback control.                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Atmospheric_pressure;                                        */
/*  input uint16 Wg_pAtmoMean_C;                                              */
/*  input uint8 Wg_CoeffCorrnPresAlti_C;                                      */
/*  input sint8 Wg_pOfsCorrnPresAlti_C;                                       */
/*  output sint8 Wg_pOfsAltiCorrnSpgPres;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcOfsAlti(void)
{
   uint16 u16LocalAtmospheric_pressure;
   sint16 s16LocalSpgPres1;
   sint16 s16LocalSpgPres2;


   VEMS_vidGET(Atmospheric_pressure,u16LocalAtmospheric_pressure);
   s16LocalSpgPres1 = (sint16)(((sint32)(Wg_pAtmoMean_C)
                                         - u16LocalAtmospheric_pressure) / 2);
   s16LocalSpgPres2 = (sint16)(((sint32)(s16LocalSpgPres1)
                                         * Wg_CoeffCorrnPresAlti_C) / 4096);
   Wg_pOfsAltiCorrnSpgPres = (sint8)MATHSRV_udtCLAMP(((sint32)s16LocalSpgPres2
                                                     + Wg_pOfsCorrnPresAlti_C),
                                                     -128, 127);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidClcPwmOpenLoop                                  */
/* !Description :  The open loop PWM setpoint is estimated from a map,        */
/*                 considering the engine speed and the manifold pressure     */
/*                 setpoint adjusted to take in account the variation of      */
/*                 atmospheric pressure.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input uint16 AirSys_pInMnfReq;                                            */
/*  input uint16 Wg_CmdSp_tqIdcAirReq_A[16];                                  */
/*  input uint16 Wg_CmdSp_tqIdcAir_nEng_A[16];                                */
/*  input uint16 Wg_CmdSp_tqIdcAirX_nEngY_M[16][16];                          */
/*  input uint16 Wg_CmdSp_nEng_A[16];                                         */
/*  input sint8 Wg_pOfsAltiCorrnSpgPres;                                      */
/*  input uint8 Wg_pCoeffSpcPwmCorrnPresAlti_C;                               */
/*  input uint16 Wg_CmdSp_pInMnfReqCorrn_A[16];                               */
/*  input uint16 Wg_pInMnfReqCorrn;                                           */
/*  input uint16 Wg_CmdSp_nEngX_pInMnfReqCornY_M[16][16];                     */
/*  input boolean Wg_bStsTranWg;                                              */
/*  input sint16 Wg_rWgCmdThdMaxSp_C;                                         */
/*  input boolean Wg_bOplCmdSp_ETB_C;                                         */
/*  input sint16 Wg_rWgCmdThdMinSp_C;                                         */
/*  output uint16 Wg_pInMnfReqCorrn;                                          */
/*  output sint16 Wg_rWgOplCmd;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidClcPwmOpenLoop(void)
{
   uint16 u16Local_RegimeMoteur;
   uint16 u16Local_AirSys_pInMnfReq;
   uint16 u16Local_TqSys_tqIdcAirReq;
   uint16 u16LocalParaX1;
   uint16 u16LocalParaY1;
   uint16 u16LocalParaX2;
   uint16 u16LocalParaY2;
   uint16 u16LocalInterp1;
   uint16 u16LocalInterp2;
   sint16 s16Local_Wg_rWgOplCmd;
   sint16 s16LocalTemp;
   sint16 s16Local_TqSys_tqIdcAirReq;
   sint32 s32Local_TqSys_tqIdcAirReq;
   sint32 s32LocalSpgPres;


   VEMS_vidGET(Regime_moteur, u16Local_RegimeMoteur);
   VEMS_vidGET(TqSys_tqIdcAirReq, s16Local_TqSys_tqIdcAirReq);
   VEMS_vidGET(AirSys_pInMnfReq, u16Local_AirSys_pInMnfReq);

   s32Local_TqSys_tqIdcAirReq = (sint32)(s16Local_TqSys_tqIdcAirReq + 32000);
   u16Local_TqSys_tqIdcAirReq =
      (uint16)MATHSRV_udtMAX(s32Local_TqSys_tqIdcAirReq, 0);
   u16LocalParaX1 = MATHSRV_u16CalcParaIncAryU16(Wg_CmdSp_tqIdcAirReq_A,
                                                 u16Local_TqSys_tqIdcAirReq,
                                                 16);
   u16LocalParaY1 = MATHSRV_u16CalcParaIncAryU16(Wg_CmdSp_tqIdcAir_nEng_A,
                                                 u16Local_RegimeMoteur,
                                                 16);

   u16LocalInterp1 = MATHSRV_u16Interp2d(&Wg_CmdSp_tqIdcAirX_nEngY_M[0][0],
                                         u16LocalParaX1,
                                         u16LocalParaY1,
                                         16);
   u16LocalParaX2 = MATHSRV_u16CalcParaIncAryU16 (Wg_CmdSp_nEng_A,
                                                  u16Local_RegimeMoteur,
                                                  16);
   s16LocalTemp = (sint16)( ( Wg_pOfsAltiCorrnSpgPres
                            * Wg_pCoeffSpcPwmCorrnPresAlti_C)
                           / 2);

   s32LocalSpgPres = (sint32)(s16LocalTemp + u16Local_AirSys_pInMnfReq);

   Wg_pInMnfReqCorrn = (uint16)MATHSRV_udtCLAMP(s32LocalSpgPres, 0, 65535);

   u16LocalParaY2 = MATHSRV_u16CalcParaIncAryU16(Wg_CmdSp_pInMnfReqCorrn_A,
                                                 Wg_pInMnfReqCorrn,
                                                 16);
   u16LocalInterp2 =
      MATHSRV_u16Interp2d(&Wg_CmdSp_nEngX_pInMnfReqCornY_M[0][0],
                          u16LocalParaX2,
                          u16LocalParaY2,
                          16);
   if (Wg_bStsTranWg != 0)
   {
      Wg_rWgOplCmd = Wg_rWgCmdThdMaxSp_C;
   }
   else
   {
      if (Wg_bOplCmdSp_ETB_C != 0)
      {
         s16Local_Wg_rWgOplCmd = (sint16)(u16LocalInterp1 - 32768);
      }
      else
      {
         s16Local_Wg_rWgOplCmd = (sint16)(u16LocalInterp2 - 32768);
      }
      Wg_rWgOplCmd = (sint16)MATHSRV_udtCLAMP(s16Local_Wg_rWgOplCmd,
                                              Wg_rWgCmdThdMinSp_C,
                                              Wg_rWgCmdThdMaxSp_C);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidWgServoCdn                                      */
/* !Description :  This module check three Wastegate working conditions, used */
/*                 to compute different parts of the PWM command              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidCdnOpenLoop();                                */
/*  extf argret void WgCmdSp_vidCdnServoCmd();                                */
/*  extf argret void WgCmdSp_vidCdnApplAdpv();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidWgServoCdn(void)
{
   WgCmdSp_vidCdnOpenLoop();
   WgCmdSp_vidCdnServoCmd();
   WgCmdSp_vidCdnApplAdpv();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidCdnOpenLoop                                     */
/* !Description :  This module checks the absolutely required conditions to   */
/*                 applying any PWM command (even for open loop command)      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Wg_bWgCmdOplBenchModEna;                                    */
/*  input uint16 AirPres_pSpgPresRawSp;                                       */
/*  input uint8 Wg_pSpgThdOpplCmd_C;                                          */
/*  input sint8 Wg_pOfsAltiCorrnSpgPres;                                      */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Wg_tCoThdOpplCmd_C;                                           */
/*  output boolean Wg_bEnaApplOlpCmd;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidCdnOpenLoop(void)
{
   boolean bLocalWg_bWgCmdOplBenchModEna;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalAirPres_pSpgPresRawSp;
   uint16  u16LocalSpgPrs;


   VEMS_vidGET(Wg_bWgCmdOplBenchModEna,bLocalWg_bWgCmdOplBenchModEna);
   if (bLocalWg_bWgCmdOplBenchModEna == 0)
   {
      VEMS_vidGET(AirPres_pSpgPresRawSp,u16LocalAirPres_pSpgPresRawSp);
      u16LocalSpgPrs = (uint16)((sint16)((Wg_pSpgThdOpplCmd_C * 64) + 10000)
                               - (sint16)(Wg_pOfsAltiCorrnSpgPres * 64));

      VEMS_vidGET(Temperature_eau,u8LocalTemperature_eau);

      if (  (u8LocalTemperature_eau >= Wg_tCoThdOpplCmd_C)
         && (u16LocalAirPres_pSpgPresRawSp >= u16LocalSpgPrs))
      {
         Wg_bEnaApplOlpCmd = 1;
      }
      else
      {
         Wg_bEnaApplOlpCmd = 0;
      }
   }
   else
   {
      Wg_bEnaApplOlpCmd = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidCdnServoCmd                                     */
/* !Description :  This module checks the conditions to satisfy when applying */
/*                 the PWM closed loop part                                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Wg_bStsTranWg;                                              */
/*  input boolean Wg_bEnaApplOlpCmd;                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Wg_CmdSp_nEng_A[16];                                         */
/*  input uint16 Wg_pIniSpgServo_nEngX_T[16];                                 */
/*  input sint8 Wg_pOfsAltiCorrnSpgPres;                                      */
/*  input uint16 Acq_spg_pres_measured;                                       */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  output boolean Wg_bEnaApplServoCmd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidCdnServoCmd(void)
{
   boolean bLocalWg_bEnaApplServoCmd;
   boolean bLocalTrbAct_bBoostPresClCtlAcv;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalAcq_spg_pres_measured;
   uint16  u16LocalPara;
   uint16  u16LocalInterp;
   sint16  s16LocalTemp;
   sint32  s32LocalSpgPres;


   if (  (Wg_bStsTranWg == 0)
      && (Wg_bEnaApplOlpCmd != 0))
   {
      VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
      u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Wg_CmdSp_nEng_A,
                                                  u16LocalRegime_moteur,
                                                  16);
      u16LocalInterp = MATHSRV_u16Interp1d(Wg_pIniSpgServo_nEngX_T,
                                           u16LocalPara);
      s16LocalTemp = (sint16)(Wg_pOfsAltiCorrnSpgPres * 64);
      s32LocalSpgPres = (sint32)(u16LocalInterp - s16LocalTemp);

      VEMS_vidGET(Acq_spg_pres_measured, u16LocalAcq_spg_pres_measured);

      if (s32LocalSpgPres < u16LocalAcq_spg_pres_measured)
      {
         bLocalWg_bEnaApplServoCmd = 1;
      }
      else
      {
         bLocalWg_bEnaApplServoCmd = 0;
      }
   }
   else
   {
      bLocalWg_bEnaApplServoCmd = 0;
   }
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);
   if (  (bLocalTrbAct_bBoostPresClCtlAcv != 0)
      || (bLocalWg_bEnaApplServoCmd != 0))
   {
      Wg_bEnaApplServoCmd = 1;
   }
   else
   {
      Wg_bEnaApplServoCmd = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WgCmdSp_vidCdnApplAdpv                                     */
/* !Description :  This module checks the different conditions required to    */
/*                 apply the adaptive part of the PWM command.                */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Engine_load;                                                 */
/*  input boolean Wg_bStsTranWg;                                              */
/*  input boolean Wg_bEnaApplOlpCmd;                                          */
/*  input uint16 Acq_spg_pres_measured;                                       */
/*  input uint16 Atmospheric_pressure;                                        */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Tension_batterie;                                            */
/*  input uint8 Wg_pSpgThdEnaAdpv_C;                                          */
/*  input sint8 Wg_pOfsAltiCorrnSpgPres;                                      */
/*  input uint16 Wg_rEngineLoadPrev;                                          */
/*  input uint8 Wg_pAtmThdEnaAdpv_C;                                          */
/*  input sint16 Wg_rWgCmdThdMaxSp_C;                                         */
/*  input sint16 Wg_rWgCmdDeltaThdEnaAdpv_C;                                  */
/*  input sint16 Wg_rWgCmdThdMinSp_C;                                         */
/*  input uint16 Wg_facDifChStabyThdEnaAdpv_C;                                */
/*  input uint16 Wg_nEngThdEnaAdpv_C;                                         */
/*  input uint16 Wg_uBattHiThdEnaAdpv_C;                                      */
/*  input uint16 Wg_uBattLoThdEnaAdpv_C;                                      */
/*  input sint16 Wg_rWgCmdSpPrev;                                             */
/*  output boolean Wg_bEnaApplAdpv;                                           */
/*  output uint16 Wg_rEngineLoadPrev;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WgCmdSp_vidCdnApplAdpv(void)
{
   uint16 u16LocalAcq_spg_pres_measured;
   uint16 u16LocalEngine_load;
   uint16 u16LocalAtmospheric_pressure;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalTension_batterie;
   uint16 u16LocalCorrnSpgPres;
   uint16 u16LocalAbsEngineLoad;
   uint16 u16LocalAtmPrs;
   sint32 s32LocalWgCmdMinSp;
   sint32 s32LocalWgCmdMaxSp;


   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   if (  (Wg_bStsTranWg == 0)
      && (Wg_bEnaApplOlpCmd != 0))
   {
      VEMS_vidGET(Acq_spg_pres_measured,u16LocalAcq_spg_pres_measured);
      VEMS_vidGET(Atmospheric_pressure,u16LocalAtmospheric_pressure);
      VEMS_vidGET(Regime_moteur,u16LocalRegime_moteur);
      VEMS_vidGET(Tension_batterie,u16LocalTension_batterie);

      u16LocalCorrnSpgPres = (uint16)((sint16)((Wg_pSpgThdEnaAdpv_C * 64)
                                              + 10000)
                                     - (sint16)(Wg_pOfsAltiCorrnSpgPres * 64));

      u16LocalAbsEngineLoad = (uint16)MATHSRV_udtABS(u16LocalEngine_load
                                                    - Wg_rEngineLoadPrev);

      u16LocalAtmPrs = (uint16)(Wg_pAtmThdEnaAdpv_C * 128);
      s32LocalWgCmdMaxSp =
         (sint32)(Wg_rWgCmdThdMaxSp_C - Wg_rWgCmdDeltaThdEnaAdpv_C);

      s32LocalWgCmdMinSp =
         (sint32)(Wg_rWgCmdThdMinSp_C + Wg_rWgCmdDeltaThdEnaAdpv_C);

      if (  (u16LocalAcq_spg_pres_measured >= u16LocalCorrnSpgPres)
         && (u16LocalAbsEngineLoad <= Wg_facDifChStabyThdEnaAdpv_C)
         && (u16LocalAtmospheric_pressure >= u16LocalAtmPrs)
         && (u16LocalRegime_moteur >= Wg_nEngThdEnaAdpv_C)
         && (u16LocalTension_batterie <= Wg_uBattHiThdEnaAdpv_C)
         && (u16LocalTension_batterie >= Wg_uBattLoThdEnaAdpv_C)
         && (Wg_rWgCmdSpPrev <= s32LocalWgCmdMaxSp)
         && (Wg_rWgCmdSpPrev >= s32LocalWgCmdMinSp))
      {
         Wg_bEnaApplAdpv = 1;
      }
      else
      {
         Wg_bEnaApplAdpv = 0;
      }
   }
   else
   {
      Wg_bEnaApplAdpv = 0;
   }

   Wg_rEngineLoadPrev = u16LocalEngine_load;
}
/*------------------------------- end of file --------------------------------*/