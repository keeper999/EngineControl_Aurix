/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : Wg_CmdBenchMod                                          */
/* !Description     : Wg_CmdBenchMod component.                               */
/*                                                                            */
/* !Module          : Wg_CmdBenchMod                                          */
/* !Description     : WASTEGATE SOLENOID VALVE OPEN LOOP COMMAND SETPOINT IN  */
/*                    BENCH MODE                                              */
/*                                                                            */
/* !File            : WG_CMDBENCHMOD_FCT1.C                                   */
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
/*   1 / Wg_CmdBenchMod_vidIniWgCmdOplSpBenchMod                              */
/*   2 / Wg_CmdBenchMod_vidCalcWgCmdOplBenchMod                               */
/*   3 / Wg_CmdBenchMod_vidWgCmd                                              */
/*   4 / Wg_CmdBenchMod_vidWgCmdRaw                                           */
/*   5 / Wg_CmdBenchMod_vidWgCmdCutOff                                        */
/*                                                                            */
/* !Reference   : V02 NT 09 08184 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/WG/WG_CMDBENCHMOD/Wg_CmdBenchMod$*/
/* $Revision::   1.4      $$Author::   HHAMLAOU       $$Date::   21 Feb 2012 $*/
/* $Author::   HHAMLAOU                               $$Date::   21 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "WG_CMDBENCHMOD.h"
#include "WG_CMDBENCHMOD_L.h"
#include "WG_CMDBENCHMOD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_CmdBenchMod_vidIniWgCmdOplSpBenchMod                    */
/* !Description :  The wastegate solenoid valve open loop command setpoint is */
/*                 initialised by a calibration at reset.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Wg_rWgCmdOplBenchModIniSp_C;                                 */
/*  output uint16 Wg_rWgCmdOplSpBenchMod;                                     */
/*  output uint32 Wg_rWgCmdOplSpBenchModMem;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_CmdBenchMod_vidIniWgCmdOplSpBenchMod(void)
{
   uint16 u16Local_Wg_rWgCmdOplSpBenchMod;

   u16Local_Wg_rWgCmdOplSpBenchMod =
      (uint16)MATHSRV_udtMIN(Wg_rWgCmdOplBenchModIniSp_C, 32768);

   VEMS_vidSET(Wg_rWgCmdOplSpBenchMod, u16Local_Wg_rWgCmdOplSpBenchMod);

   /* Previous values initialization */
   Wg_rWgCmdOplSpBenchModMem = (uint32)(u16Local_Wg_rWgCmdOplSpBenchMod * 256);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_CmdBenchMod_vidCalcWgCmdOplBenchMod                     */
/* !Description :  The computation of the wastegate solenoid valve open loop  */
/*                 command bench mode setpoint can be inhibited by an enable. */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Wg_CmdBenchMod_vidWgCmd();                               */
/*  input boolean Wg_bWgCmdOplBenchModEna_C;                                  */
/*  output boolean Wg_bWgCmdOplBenchModEna;                                   */
/*  output boolean Wg_bWgCmdOplBenchModEna_C;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_CmdBenchMod_vidCalcWgCmdOplBenchMod(void)
{
   VEMS_vidSET(Wg_bWgCmdOplBenchModEna, Wg_bWgCmdOplBenchModEna_C);

   if (Wg_bWgCmdOplBenchModEna_C != 0)
   {
      Wg_CmdBenchMod_vidWgCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_CmdBenchMod_vidWgCmd                                    */
/* !Description :  The wastegate solenoid valve open loop command setpoint in */
/*                 bench mode is computed then filtered for smoothing         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Wg_CmdBenchMod_vidWgCmdRaw();                            */
/*  extf argret void Wg_CmdBenchMod_vidWgCmdCutOff();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_CmdBenchMod_vidWgCmd(void)
{
   Wg_CmdBenchMod_vidWgCmdRaw();
   Wg_CmdBenchMod_vidWgCmdCutOff();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_CmdBenchMod_vidWgCmdRaw                                 */
/* !Description :  There are three methods to compute the wastegate solenoid  */
/*                 valve open loop command setpoint in bench mode             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Wg_noWgCmdOplBenchModSel_C;                                   */
/*  input uint16 Regime_moteur;                                               */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input uint16 Wg_tqIdcAirReq_A[16];                                        */
/*  input uint16 Wg_nEng_A[16];                                               */
/*  input uint16 Wg_rWgCmdOpl_tqIdcAirX_nEngY_M[16][16];                      */
/*  input uint16 Ext_pDsThrMesSI;                                             */
/*  input uint16 Wg_pInMnf_A[16];                                             */
/*  input uint16 Wg_rWgCmdOpl_tqIdcAirX_pInMnfY_M[16][16];                    */
/*  input uint16 Acq_spg_prs_uavn0;                                           */
/*  input uint16 Wg_pBoost_A[16];                                             */
/*  input uint16 Wg_rWgCmdOpl_tqIdcAirX_pBoostY_M[16][16];                    */
/*  output uint16 Wg_rWgCmdOplSpRawBenchMod;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_CmdBenchMod_vidWgCmdRaw(void)
{
   uint16 u16Local_Acq_spg_prs_uavn0;
   uint16 u16Local_Ext_pDsThrMesSI;
   uint16 u16Local_RegimeMoteur;
   uint16 u16Local_TqSys_tqIdcAirReq;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   sint16 s16Local_TqSys_tqIdcAirReq;
   sint32 s32Local_TqSys_tqIdcAirReq;

   switch (Wg_noWgCmdOplBenchModSel_C)
   {
      case 0:
      VEMS_vidGET(Regime_moteur, u16Local_RegimeMoteur);
      VEMS_vidGET(TqSys_tqIdcAirReq, s16Local_TqSys_tqIdcAirReq);

      s32Local_TqSys_tqIdcAirReq = (sint32)(s16Local_TqSys_tqIdcAirReq + 32000);
      u16Local_TqSys_tqIdcAirReq =
             (uint16)MATHSRV_udtMAX(s32Local_TqSys_tqIdcAirReq, 0);
      u16LocalParaX = MATHSRV_u16CalcParaIncAryU16( Wg_tqIdcAirReq_A,
                                                    u16Local_TqSys_tqIdcAirReq,
                                                    16);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU16( Wg_nEng_A,
                                                    u16Local_RegimeMoteur,
                                                    16);
      Wg_rWgCmdOplSpRawBenchMod =
               MATHSRV_u16Interp2d( &Wg_rWgCmdOpl_tqIdcAirX_nEngY_M[0][0],
                                    u16LocalParaX,
                                    u16LocalParaY,
                                    16);
      break;

      case 1:
      VEMS_vidGET(Ext_pDsThrMesSI, u16Local_Ext_pDsThrMesSI);
      VEMS_vidGET(TqSys_tqIdcAirReq, s16Local_TqSys_tqIdcAirReq);

      s32Local_TqSys_tqIdcAirReq = (sint32)(s16Local_TqSys_tqIdcAirReq + 32000);
      u16Local_TqSys_tqIdcAirReq =
             (uint16)MATHSRV_udtMAX(s32Local_TqSys_tqIdcAirReq, 0);
      u16LocalParaX = MATHSRV_u16CalcParaIncAryU16( Wg_tqIdcAirReq_A,
                                                    u16Local_TqSys_tqIdcAirReq,
                                                    16);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU16( Wg_pInMnf_A,
                                                    u16Local_Ext_pDsThrMesSI,
                                                    16);
      Wg_rWgCmdOplSpRawBenchMod =
               MATHSRV_u16Interp2d( &Wg_rWgCmdOpl_tqIdcAirX_pInMnfY_M[0][0],
                                    u16LocalParaX,
                                    u16LocalParaY,
                                    16 );
      break;

      case 2:
      VEMS_vidGET(Acq_spg_prs_uavn0, u16Local_Acq_spg_prs_uavn0);
      VEMS_vidGET(TqSys_tqIdcAirReq, s16Local_TqSys_tqIdcAirReq);

      s32Local_TqSys_tqIdcAirReq = (sint32)(s16Local_TqSys_tqIdcAirReq + 32000);
      u16Local_TqSys_tqIdcAirReq =
             (uint16)MATHSRV_udtMAX(s32Local_TqSys_tqIdcAirReq, 0);
      u16LocalParaX = MATHSRV_u16CalcParaIncAryU16( Wg_tqIdcAirReq_A,
                                                    u16Local_TqSys_tqIdcAirReq,
                                                    16);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU16( Wg_pBoost_A,
                                                    u16Local_Acq_spg_prs_uavn0,
                                                    16);
      Wg_rWgCmdOplSpRawBenchMod =
               MATHSRV_u16Interp2d( &Wg_rWgCmdOpl_tqIdcAirX_pBoostY_M[0][0],
                                    u16LocalParaX,
                                    u16LocalParaY,
                                    16);
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_CmdBenchMod_vidWgCmdCutOff                              */
/* !Description :  The wastegate solenoid valve command setpoint is filtered  */
/*                 for smoothing.                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Wg_bWgCmdOplCutOffSelPres_C;                                */
/*  input uint16 Acq_spg_prs_uavn0;                                           */
/*  input uint16 Ext_pDsThrMesSI;                                             */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Wg_nEng_A[16];                                               */
/*  input uint16 Wg_nEngX_pWgCmdOplCutOffMax_T[16];                           */
/*  input uint16 Wg_pWgCmdOplCutOffMaxHys_C;                                  */
/*  input boolean Wg_bWgCmdBenchModHystOutput;                                */
/*  input uint16 Wg_rWgCmdOplLimPres_C;                                       */
/*  input uint16 Wg_rWgCmdOplSpRawBenchMod;                                   */
/*  input uint8 Wg_rWgCmdOplBenchModFilGain_C;                                */
/*  input uint32 Wg_rWgCmdOplSpBenchModMem;                                   */
/*  output uint32 Wg_rWgCmdOplSpBenchModMem;                                  */
/*  output uint16 Wg_rWgCmdOplSpBenchMod;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_CmdBenchMod_vidWgCmdCutOff(void)
{
   uint16 u16LocalWg_rWgCmdOplSpBenchMod;
   uint16 u16LocalMeasuredValue;
   uint16 u16LocalFilterGain;
   uint16 u16LocalPara;
   uint16 u16LocalHystInput;
   uint8  u8LocalFilterGain;
   uint16 u16LocalHystThrsd1;
   uint16 u16LocalHystThrsd2;
   uint16 u16LocalRegimeMoteur;

   if( Wg_bWgCmdOplCutOffSelPres_C != 0 )
   {
      VEMS_vidGET(Acq_spg_prs_uavn0, u16LocalHystInput);
   }
   else
   {
      VEMS_vidGET(Ext_pDsThrMesSI, u16LocalHystInput);
   }

   VEMS_vidGET(Regime_moteur, u16LocalRegimeMoteur);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU16( Wg_nEng_A,
                                                u16LocalRegimeMoteur,
                                                16);

   u16LocalHystThrsd2 = MATHSRV_u16Interp1d( &Wg_nEngX_pWgCmdOplCutOffMax_T[0],
                                             u16LocalPara);

   u16LocalHystThrsd1 =
      (uint16)MATHSRV_udtMAX((sint32)(u16LocalHystThrsd2
                                      - Wg_pWgCmdOplCutOffMaxHys_C),0);

   MATHSRV_vidSchmittTriggerU16( u16LocalHystInput,
                                 u16LocalHystThrsd1,
                                 u16LocalHystThrsd2,
                                 MATHSRV_RISING_SCHMITT_TRIGGER ,
                                 &Wg_bWgCmdBenchModHystOutput);
   if( Wg_bWgCmdBenchModHystOutput != 0 )
   {
      u16LocalMeasuredValue = Wg_rWgCmdOplLimPres_C;
   }
   else
   {
      u16LocalMeasuredValue = Wg_rWgCmdOplSpRawBenchMod;
   }

   /* Scaling  Wg_rWgCmdOplBenchModFilGain_C has an offset = 1/256 and a
      resolution = 1/256*/
   u16LocalFilterGain = (uint16)(Wg_rWgCmdOplBenchModFilGain_C + 1);
   if (u16LocalFilterGain < 256)
   {
      u8LocalFilterGain = (uint8)u16LocalFilterGain;
      u16LocalWg_rWgCmdOplSpBenchMod =
         MATHSRV_u16FirstOrderFilterGu8 (u8LocalFilterGain,
                                         &Wg_rWgCmdOplSpBenchModMem,
                                         u16LocalMeasuredValue);
   }
   else
   {
      u16LocalWg_rWgCmdOplSpBenchMod = u16LocalMeasuredValue;
      Wg_rWgCmdOplSpBenchModMem =
         (uint32)(u16LocalWg_rWgCmdOplSpBenchMod * 256);
   }
   u16LocalWg_rWgCmdOplSpBenchMod =
           (uint16)MATHSRV_udtMIN(u16LocalWg_rWgCmdOplSpBenchMod, 32768);

   VEMS_vidSET(Wg_rWgCmdOplSpBenchMod, u16LocalWg_rWgCmdOplSpBenchMod);
}