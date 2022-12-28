/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJTICOR                                                */
/* !Description     : INJTICOR component                                      */
/*                                                                            */
/* !Module          : INJTICOR                                                */
/* !Description     : CORRECTION DE LA RÉGULATION DE RICHESSE EN BUTÉE        */
/*                                                                            */
/* !File            : INJTICOR_FCT1.C                                         */
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
/*   1 / INJTICOR_vidInitOutput                                               */
/*   2 / INJTICOR_vidInitLfbkMonitoring                                       */
/*   3 / INJTICOR_vidCtrlLfbkMonitoring                                       */
/*   4 / INJTICOR_vidResetDiag                                                */
/*   5 / INJTICOR_vidComputation                                              */
/*   6 / INJTICOR_vidClampTstNotPerformed                                     */
/*   7 / INJTICOR_vidWaitApplyInitAdjust                                      */
/*   8 / INJTICOR_vidDiagTrim                                                 */
/*   9 / INJTICOR_vidLeanFuelCalc                                             */
/*   10 / INJTICOR_vidRichFuelCalc                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5147608 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065914                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJTICOR/INJTICOR_FCT1.C_v        $*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   20 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INJTICOR.h"
#include "INJTICOR_L.h"
#include "INJTICOR_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInitOutput                                     */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Inj_bAcvSeqDftFu_Afl;                                      */
/*  output boolean Inj_bAcvSeqDftFuGas_Afl;                                   */
/*  output boolean Inj_bAcvSeqDftFu_Afr;                                      */
/*  output boolean Inj_bAcvSeqDftFuGas_Afr;                                   */
/*  output boolean Inj_bAcvSeqDftSenO2_Afl;                                   */
/*  output boolean Inj_bAcvSeqDftSenO2Gas_Afl;                                */
/*  output boolean Inj_bAcvSeqDftSenO2_Afr;                                   */
/*  output boolean Inj_bAcvSeqDftSenO2Gas_Afr;                                */
/*  output boolean Inj_bAcvSeqMemDftFu_Afl;                                   */
/*  output boolean Inj_bAcvSeqMemDftFuGas_Afl;                                */
/*  output boolean Inj_bAcvSeqMemDftFu_Afr;                                   */
/*  output boolean Inj_bAcvSeqMemDftFuGas_Afr;                                */
/*  output boolean Inj_bAcvSeqMemDftSenO2_Afl;                                */
/*  output boolean Inj_bAcvSeqMemDftSenO2Gas_Afl;                             */
/*  output boolean Inj_bAcvSeqMemDftSenO2_Afr;                                */
/*  output boolean Inj_bAcvSeqMemDftSenO2Gas_Afr;                             */
/*  output boolean Inj_bAcvSeqMemORngLfbk_Afl;                                */
/*  output boolean Inj_bAcvSeqMemORngLfbkGas_Afl;                             */
/*  output boolean Inj_bAcvSeqMemORngLfbk_Afr;                                */
/*  output boolean Inj_bAcvSeqMemORngLfbkGas_Afr;                             */
/*  output boolean Inj_bAcvSeqORngLfbk_Afl;                                   */
/*  output boolean Inj_bAcvSeqORngLfbkGas_Afl;                                */
/*  output boolean Inj_bAcvSeqORngLfbk_Afr;                                   */
/*  output boolean Inj_bAcvSeqORngLfbkGas_Afr;                                */
/*  output sint16 Inj_InjTiCorFacMax_Obd6Mod;                                 */
/*  output sint16 Inj_InjTiCorFacMes_Obd6Mod;                                 */
/*  output sint16 Inj_InjTiCorFacMin_Obd6Mod;                                 */
/*  output uint16 Flev_low_fuel_level_lfbk_count;                             */
/*  output uint8 INJTICOR_u8Ext_stSysGasPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInitOutput(void)
{
   VEMS_vidSET(Inj_bAcvSeqDftFu_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqDftFu_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftFu_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftFuGas_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftFu_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftFuGas_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftSenO2_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftSenO2Gas_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftSenO2_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqMemDftSenO2Gas_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqMemORngLfbk_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqMemORngLfbkGas_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqMemORngLfbk_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqMemORngLfbkGas_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afl, 0);
   VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afr, 0);
   VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afr, 0);
   VEMS_vidSET(Inj_InjTiCorFacMax_Obd6Mod, 0);
   VEMS_vidSET(Inj_InjTiCorFacMes_Obd6Mod, 0);
   VEMS_vidSET(Inj_InjTiCorFacMin_Obd6Mod, 0);
   Flev_low_fuel_level_lfbk_count = 0;
   INJTICOR_u8Ext_stSysGasPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInitLfbkMonitoring                             */
/* !Description :  Initialisation des variables à l'événement reset.          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Lfbk_switch_lean_delay;                                       */
/*  input uint8 Lfbk_switch_rich_delay;                                       */
/*  input uint8 Lfbk_stuck_lean_delay;                                        */
/*  input uint8 Lfbk_stuck_rich_delay;                                        */
/*  output sint8 Diag_trim;                                                   */
/*  output boolean Lfbk_mon_diag_test_request;                                */
/*  output boolean Lfbk_cor_completed;                                        */
/*  output boolean Lfbk_diag_completed;                                       */
/*  output boolean Lfbk_diag_no_failure_completed;                            */
/*  output boolean Flev_low_fuel_level_Afl;                                   */
/*  output boolean Lfbk_lean_fuel;                                            */
/*  output boolean Lfbk_rich_fuel;                                            */
/*  output uint8 Lfbk_switch_lean_delay_count;                                */
/*  output uint8 Lfbk_switch_rich_delay_count;                                */
/*  output uint8 Lfbk_stuck_lean_delay_count;                                 */
/*  output uint8 Lfbk_stuck_rich_delay_count;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInitLfbkMonitoring(void)
{
   /*01_initialise_lfbk_monitoring*/
   VEMS_vidSET(Diag_trim, 0);
   VEMS_vidSET(Lfbk_mon_diag_test_request, 0);
   VEMS_vidSET(Lfbk_cor_completed, 0);
   Lfbk_diag_completed = 0;
   VEMS_vidSET(Lfbk_diag_no_failure_completed, 0);
   Flev_low_fuel_level_Afl = 0;
   Lfbk_lean_fuel = 0;
   Lfbk_rich_fuel = 0;
   Lfbk_switch_lean_delay_count = Lfbk_switch_lean_delay;
   Lfbk_switch_rich_delay_count = Lfbk_switch_rich_delay;
   Lfbk_stuck_lean_delay_count = Lfbk_stuck_lean_delay;
   Lfbk_stuck_rich_delay_count = Lfbk_stuck_rich_delay;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidCtrlLfbkMonitoring                             */
/* !Description :  la stratégie de surveillance de la régulation de richesse  */
/*                 est active s'il n'y a pas d'inhibition manuelle, via le    */
/*                 FRM, et si le diagnostic dans la totalité n'a pas encore   */
/*                 été réalisé.                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidResetDiag();                                 */
/*  extf argret void INJTICOR_vidComputation();                               */
/*  extf argret void INJTICOR_vidLowFuelTempo();                              */
/*  input boolean Lfbk_cor_completed;                                         */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input boolean Flev_low_gas_level;                                         */
/*  input boolean Lfbk_on_enlean_clamp;                                       */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 INJTICOR_u8Ext_stSysGasPrev;                                  */
/*  input boolean Manu_inh_lfbk_monitoring;                                   */
/*  output boolean Clamp_operated;                                            */
/*  output uint8 INJTICOR_u8Ext_stSysGasPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidCtrlLfbkMonitoring(void)
{
   /*02_control_lfbk_monitoring*/
   boolean bLocalInhInjTiCor;
   boolean bLocalLfbk_cor_completed;
   boolean bLocalFlev_low_fuel_level;
   boolean bLocalFlev_low_gas_level;
   boolean bLocalLfbk_on_enlean_clamp;
   boolean bLocalLfbk_on_enrich_clamp;
   boolean bLocalExt_stSysGas;
   uint8   u8LocalExt_stSysGas;


   bLocalInhInjTiCor = GDGAR_bGetFRM(FRM_FRM_INHINJTICOR);
   VEMS_vidGET(Lfbk_cor_completed, bLocalLfbk_cor_completed);
   VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
   VEMS_vidGET(Flev_low_gas_level, bLocalFlev_low_gas_level);
   VEMS_vidGET(Lfbk_on_enlean_clamp, bLocalLfbk_on_enlean_clamp);
   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbk_on_enrich_clamp);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (  (bLocalLfbk_on_enlean_clamp != 0)
      || (bLocalLfbk_on_enrich_clamp != 0))
   {
      Clamp_operated = 1;
   }
   else
   {
      Clamp_operated = 0;
   }

   if (  (  (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
         && (INJTICOR_u8Ext_stSysGasPrev == Ext_stGslMod_SC))
      || (  (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC)
         && (INJTICOR_u8Ext_stSysGasPrev == Ext_stGasMod_SC)))
   {
      bLocalExt_stSysGas = 1;
   }
   else
   {
      bLocalExt_stSysGas = 0;
   }

   if (  (bLocalInhInjTiCor != 0)
      || (bLocalLfbk_cor_completed != 0)
      || (Manu_inh_lfbk_monitoring != 0)
      || (bLocalExt_stSysGas != 0))
   {
      /* 01_reinitialization */
      INJTICOR_vidResetDiag();
   }
   else
   {
      /* 02_computation */
      INJTICOR_vidComputation();
   }

   if (  (  ( u8LocalExt_stSysGas == Ext_stGasMod_SC)
         && ( bLocalFlev_low_gas_level != 0))
      || (  ( u8LocalExt_stSysGas != Ext_stGasMod_SC)
         && ( bLocalFlev_low_fuel_level != 0)))

   {
      /* 03_low_fuel_tempo */
      INJTICOR_vidLowFuelTempo();
   }
   INJTICOR_u8Ext_stSysGasPrev = u8LocalExt_stSysGas;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidResetDiag                                      */
/* !Description :  Cette fonction permet d'initialiser la correction sur la   */
/*                 chaîne d'injection ainsi que la demande de diagnostic.     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidInitGslMod();                                */
/*  extf argret void INJTICOR_vidInitGasMod();                                */
/*  input uint8 Ext_stSysGas;                                                 */
/*  output sint8 Diag_trim;                                                   */
/*  output boolean Lfbk_mon_diag_test_request;                                */
/*  output boolean Lfbk_rich_fuel;                                            */
/*  output boolean Lfbk_lean_fuel;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidResetDiag(void)
{
   uint8  u8LocalExt_stSysGas;


   /*01_reinitialization*/
   VEMS_vidSET(Diag_trim, 0);
   VEMS_vidSET(Lfbk_mon_diag_test_request, 0);
   Lfbk_rich_fuel = 0;
   Lfbk_lean_fuel = 0;

   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC)
   {
      /* 01_Init_GslMod */
      INJTICOR_vidInitGslMod();
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
      {
         /* 02_Init_GasMod */
         INJTICOR_vidInitGasMod();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidComputation                                    */
/* !Description :  Les diagnostics de surveillance de la régulation de        */
/*                 richesse doivent être activés si la régulation de richesse */
/*                 est en boucle fermée depuis une temporisation calibrable   */
/*                 les diagnostics ne sont pas inhibés et la température      */
/*                 moteur est > à un seuil.                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_03211_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJTICOR_vidClampTstNotPerformed();                      */
/*  input boolean Lambda_closed_loop;                                         */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Ext_bPresGaz;                                               */
/*  input uint16 Lfbk_desired_conditions_dly_g_C;                             */
/*  input uint8 Lfbk_min_temp_gas_c;                                          */
/*  input uint8 Lfbk_on_enrich_thresh_gas;                                    */
/*  input sint16 Lfbk_on_enlean_thresh_gas;                                   */
/*  input uint16 Lfbk_desired_conditions_delay_C;                             */
/*  input uint8 Lfbk_min_temp_c;                                              */
/*  input uint8 Lfbk_on_enrich_thresh;                                        */
/*  input sint16 Lfbk_on_enlean_thresh;                                       */
/*  input uint16 Lfbk_desired_conditions_counter;                             */
/*  input uint16 Inj_tiInhDiag_C;                                             */
/*  input uint16 Inj_tiInhDiag;                                               */
/*  input boolean VlvAct_bInhDiagPresScav;                                    */
/*  input boolean Inj_bInhDiagPresScav_C;                                     */
/*  input boolean Lfbk_diag_completed;                                        */
/*  output sint16 Inj_InjTiCorFacMax_Obd6Mod;                                 */
/*  output sint16 Inj_InjTiCorFacMin_Obd6Mod;                                 */
/*  output uint16 Lfbk_desired_conditions_counter;                            */
/*  output uint16 Inj_tiInhDiag;                                              */
/*  output boolean Lfbk_desired_conditions;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidComputation(void)
{
   /*02_computation*/
   boolean bLocalLambda_closed_loop;
   boolean bLocalSysGazCond;
   boolean bLocalExt_bPresGaz;
   boolean bLocalVlvAct_bInhDiagPresScav;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalSysTransition;
   uint8   u8LocalMinTemperature;
   uint16  u16LocalDesiredCondCnt;
   uint16  u16LocalDesiredCondDelay;
   uint16  u16LocalInjTiInhDiag;
   sint16  s16LocalInjInjTiCorFacMax;
   sint16  s16LocalInjInjTiCorFacMin;
   sint32  s32LocalInjInjTiCorFacMin;


   VEMS_vidGET(Lambda_closed_loop, bLocalLambda_closed_loop);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalDesiredCondDelay = Lfbk_desired_conditions_dly_g_C;
      u8LocalMinTemperature = Lfbk_min_temp_gas_c;
      u8LocalSysTransition = 0;
      s16LocalInjInjTiCorFacMax = (sint16)(Lfbk_on_enrich_thresh_gas * 128);
      VEMS_vidSET(Inj_InjTiCorFacMax_Obd6Mod, s16LocalInjInjTiCorFacMax);
      s32LocalInjInjTiCorFacMin = (sint32)(Lfbk_on_enlean_thresh_gas * 128);
      s16LocalInjInjTiCorFacMin =
      (sint16)MATHSRV_udtCLAMP(s32LocalInjInjTiCorFacMin, -32768, 32767);
      VEMS_vidSET(Inj_InjTiCorFacMin_Obd6Mod, s16LocalInjInjTiCorFacMin);
   }
   else
   {
      u16LocalDesiredCondDelay = Lfbk_desired_conditions_delay_C;
      u8LocalMinTemperature = Lfbk_min_temp_c;
      if (  (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
         || (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC))
      {
         u8LocalSysTransition = 1;
      }
      else
      {
         u8LocalSysTransition = 0;
      }
      s16LocalInjInjTiCorFacMax = (sint16)(Lfbk_on_enrich_thresh * 128);
      VEMS_vidSET(Inj_InjTiCorFacMax_Obd6Mod, s16LocalInjInjTiCorFacMax);
      s32LocalInjInjTiCorFacMin = (sint32)(Lfbk_on_enlean_thresh * 128);
      s16LocalInjInjTiCorFacMin =
      (sint16)MATHSRV_udtCLAMP(s32LocalInjInjTiCorFacMin, -32768, 32767);
      VEMS_vidSET(Inj_InjTiCorFacMin_Obd6Mod, s16LocalInjInjTiCorFacMin);
   }

   if (  (bLocalLambda_closed_loop == 0)
      || (u8LocalSysTransition != 0))
   {
      bLocalSysGazCond = 0;
      u16LocalDesiredCondCnt = u16LocalDesiredCondDelay;
   }
   else
   {
      bLocalSysGazCond = 1;
      if (Lfbk_desired_conditions_counter > 0)
      {
         u16LocalDesiredCondCnt = (uint16)(Lfbk_desired_conditions_counter - 1);
      }
      else
      {
         u16LocalDesiredCondCnt = 0;
      }
   }
   Lfbk_desired_conditions_counter =
      (uint16)MATHSRV_udtMIN(u16LocalDesiredCondCnt, 6499);

   if (u8LocalSysTransition != 0)
   {
      u16LocalInjTiInhDiag = Inj_tiInhDiag_C;
   }
   else
   {
      if (Inj_tiInhDiag > 0)
      {
         u16LocalInjTiInhDiag = (uint16)(Inj_tiInhDiag - 1);
      }
      else
      {
         u16LocalInjTiInhDiag = 0;
      }
   }
   Inj_tiInhDiag = (uint16)MATHSRV_udtMIN(u16LocalInjTiInhDiag, 50000);

   VEMS_vidGET(VlvAct_bInhDiagPresScav, bLocalVlvAct_bInhDiagPresScav);
   if (  (bLocalSysGazCond != 0)
      && (Lfbk_desired_conditions_counter == 0)
      && (u8LocalTemperature_eau > u8LocalMinTemperature)
      && (  (bLocalExt_bPresGaz == 0)
         || (  (u8LocalSysTransition == 0)
            && (Inj_tiInhDiag == 0)))
      && (  (Inj_bInhDiagPresScav_C != 0)
         || (bLocalVlvAct_bInhDiagPresScav == 0)))
   {
      Lfbk_desired_conditions = 1;
   }
   else
   {
      Lfbk_desired_conditions = 0;
   }
   if (Lfbk_diag_completed == 0)
   {
      /*01_clamp_test_not_performed*/
      INJTICOR_vidClampTstNotPerformed();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidClampTstNotPerformed                           */
/* !Description :  Cette fonction permet de détecter la régulation de richesse*/
/*                 en butée. Il est désactivé  si la correction sur la chaîne */
/*                 d'injection est en cours.                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidDiagComputation();                           */
/*  extf argret void INJTICOR_vidResetDelayCount();                           */
/*  input boolean Lfbk_desired_conditions;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidClampTstNotPerformed(void)
{
   /*01_clamp_test_not_performed*/
   if (Lfbk_desired_conditions != 0)
   {
      /*01_diag_computation*/
      INJTICOR_vidDiagComputation();
   }
   else
   {
      /*02_reinitialization*/
      INJTICOR_vidResetDelayCount();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidWaitApplyInitAdjust                            */
/* !Description :  Le booléen Lfbk_mon_diag_test_request  passe à 1 pour      */
/*                 indiquer que la régulation de richesse est en butée et donc*/
/*                 que la temporisation de validation du défaut est en cours. */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidDiagTrim();                                  */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Lfbk_settling_delay_count;                                   */
/*  input boolean Lfbk_diag_completed;                                        */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint32 Lfbk_settling_delay_gas_c;                                   */
/*  input uint32 Lfbk_settling_delay_c;                                       */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidWaitApplyInitAdjust(void)
{
   /*01_wait_apply_initial_adjustment*/
   uint8  u8LocalExt_stSysGas;
   uint32 u32LocalSettlingDelayCount;


   if (Lfbk_settling_delay_count != 0)
   {
      u32LocalSettlingDelayCount = Lfbk_settling_delay_count - 1;
   }
   else
   {
      /*02_diag_trim*/
      INJTICOR_vidDiagTrim();
      if (Lfbk_diag_completed != 0)
      {
         u32LocalSettlingDelayCount = 0;
      }
      else
      {
         VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
         if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
         {
            u32LocalSettlingDelayCount = Lfbk_settling_delay_gas_c;
         }
         else
         {
            u32LocalSettlingDelayCount = Lfbk_settling_delay_c;
         }
      }
   }
   Lfbk_settling_delay_count = MATHSRV_udtMIN(u32LocalSettlingDelayCount,
                                              327679);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidDiagTrim                                       */
/* !Description :  Le booléen Lfbk_diag_completed passe à 1 lorsque la        */
/*                 temporisation de validation du diagnostic de régulation de */
/*                 richesse en butée est arrivée à son terme.                 */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidLeanFuelCalc();                              */
/*  extf argret void INJTICOR_vidRichFuelCalc();                              */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*  output boolean Lfbk_diag_completed;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidDiagTrim(void)
{
   /*02_diag_trim*/
   boolean bLocalLfbk_on_enrich_clamp;


   Lfbk_diag_completed = 1;

   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbk_on_enrich_clamp);

   if (bLocalLfbk_on_enrich_clamp != 0)
   {
      /*02_LeanFuel_calculations*/
      INJTICOR_vidLeanFuelCalc();
   }
   else
   {
      /*01_RichFuel_calculations*/
      INJTICOR_vidRichFuelCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidLeanFuelCalc                                   */
/* !Description :  Cette fonction permet le calcul de Lfbk_mod_6_var en butée */
/*                 d'appauvrissement                                          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Lfbk_enrich_percent_gas_c;                                    */
/*  input uint8 Lfbk_on_enrich_thresh_gas;                                    */
/*  input uint8 Lfbk_enrich_percent_c;                                        */
/*  input uint8 Lfbk_on_enrich_thresh;                                        */
/*  input boolean Lfbk_diag_trim_enable;                                      */
/*  output sint8 Diag_trim;                                                   */
/*  output sint16 Inj_InjTiCorFacMes_Obd6Mod;                                 */
/*  output boolean Lfbk_lean_fuel;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidLeanFuelCalc(void)
{
   /*02_LeanFuel_calculations*/
   uint8  u8LocalExt_stSysGas;
   sint8  s8LocalDiag_trim;
   sint16 s16LocalDiag_trim;
   sint16 s16LocalInjTiCorFacMes_Obd6Mod;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);


   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      s16LocalDiag_trim = (sint16)(Lfbk_enrich_percent_gas_c);
      s16LocalInjTiCorFacMes_Obd6Mod =
         (sint16)(Lfbk_on_enrich_thresh_gas * 128);
   }
   else
   {
      s16LocalDiag_trim = (sint16)(Lfbk_enrich_percent_c);
      s16LocalInjTiCorFacMes_Obd6Mod = (sint16)(Lfbk_on_enrich_thresh * 128);
   }

   if (Lfbk_diag_trim_enable != 0)
   {
      s8LocalDiag_trim = (sint8)MATHSRV_udtMIN(s16LocalDiag_trim, 127);
   }
   else
   {
      s8LocalDiag_trim = 0;
   }
   VEMS_vidSET(Diag_trim, s8LocalDiag_trim);
   VEMS_vidSET(Inj_InjTiCorFacMes_Obd6Mod, s16LocalInjTiCorFacMes_Obd6Mod);

   Lfbk_lean_fuel = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidRichFuelCalc                                   */
/* !Description :  Cette fonction permet le calcul de Lfbk_mod_6_var en butée */
/*                 d'enrichissement.                                          */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Lfbk_enlean_percent_gas_c;                                    */
/*  input sint16 Lfbk_on_enlean_thresh_gas;                                   */
/*  input uint8 Lfbk_enlean_percent_c;                                        */
/*  input sint16 Lfbk_on_enlean_thresh;                                       */
/*  input boolean Lfbk_diag_trim_enable;                                      */
/*  output sint16 Inj_InjTiCorFacMes_Obd6Mod;                                 */
/*  output sint8 Diag_trim;                                                   */
/*  output boolean Lfbk_rich_fuel;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidRichFuelCalc(void)
{
   /*01_RichFuel_calculations*/
   uint8  u8LocalExt_stSysGas;
   sint8  s8LocalDiag_trim;
   sint16 s16LocalDiag_trim;
   sint16 s16LocalInjTiCorFacMes_Obd6Mod;
   sint32 s32LocalInjInjTiCorFacMes;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      s16LocalDiag_trim = (sint16)(Lfbk_enlean_percent_gas_c * (-1));
      s32LocalInjInjTiCorFacMes = (sint32)(Lfbk_on_enlean_thresh_gas * 128);
   }
   else
   {
      s16LocalDiag_trim = (sint16)(Lfbk_enlean_percent_c * (-1));
      s32LocalInjInjTiCorFacMes = (sint32)(Lfbk_on_enlean_thresh * 128);
   }
   s16LocalInjTiCorFacMes_Obd6Mod =
      (sint16)MATHSRV_udtCLAMP(s32LocalInjInjTiCorFacMes, -32768, 32767);
   VEMS_vidSET(Inj_InjTiCorFacMes_Obd6Mod, s16LocalInjTiCorFacMes_Obd6Mod);

   if (Lfbk_diag_trim_enable != 0)
   {
      s8LocalDiag_trim = (sint8)MATHSRV_udtMAX(s16LocalDiag_trim, -128);
   }
   else
   {
      s8LocalDiag_trim = 0;
   }
   VEMS_vidSET(Diag_trim, s8LocalDiag_trim);

   Lfbk_rich_fuel = 1;
}
/*------------------------------- end of file --------------------------------*/