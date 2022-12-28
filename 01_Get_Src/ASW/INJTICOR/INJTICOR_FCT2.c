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
/* !File            : INJTICOR_FCT2.C                                         */
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
/*   1 / INJTICOR_vidResetDelayCount                                          */
/*   2 / INJTICOR_vidResetDiagTempo                                           */
/*   3 / INJTICOR_vidTempoNoFailure                                           */
/*   4 / INJTICOR_vidLfbkMod6NoFailure                                        */
/*   5 / INJTICOR_vidLowFuelTempo                                             */
/*   6 / INJTICOR_vidPerformClampTests                                        */
/*   7 / INJTICOR_vidInitializeCorrection                                     */
/*   8 / INJTICOR_vidFailuresCalculations                                     */
/*   9 / INJTICOR_vidResetCorrection                                          */
/*   10 / INJTICOR_vidOxySensorTPerformed                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5147608 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065914                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJTICOR/INJTICOR_FCT2.C_v        $*/
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
/* !Function    :  INJTICOR_vidResetDelayCount                                */
/* !Description :  Si les conditions d'activation sont perdues ou bien que la */
/*                 régulation de richesse n'est plus en butée, la demande de  */
/*                 diagnostic ainsi que la temporisation sont initialisées.   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint32 Lfbk_settling_delay_gas_c;                                   */
/*  input uint32 Lfbk_settling_delay_c;                                       */
/*  output boolean Lfbk_mon_diag_test_request;                                */
/*  output boolean Lfbk_lean_fuel;                                            */
/*  output boolean Lfbk_rich_fuel;                                            */
/*  output boolean Lfbk_diag_no_failure_completed;                            */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidResetDelayCount(void)
{
   /*02_reinitialization*/
   uint8  u8LocalExt_stSysGas;
   uint32 u32LocalLfbkDelayCount;


   VEMS_vidSET(Lfbk_mon_diag_test_request,0);
   Lfbk_lean_fuel = 0;
   Lfbk_rich_fuel = 0;
   VEMS_vidSET(Lfbk_diag_no_failure_completed, 0);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u32LocalLfbkDelayCount = Lfbk_settling_delay_gas_c;
   }
   else
   {
      u32LocalLfbkDelayCount = Lfbk_settling_delay_c;
   }

   Lfbk_settling_delay_count = MATHSRV_udtMIN(u32LocalLfbkDelayCount, 327679);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidResetDiagTempo                                 */
/* !Description :  si la correction sur la chaîne d'injection est en cours et */
/*                 que les conditions d'activation sont perdues, alors les    */
/*                 variables sont réinitialisées.                             */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Lfbk_settling_delay_c;                                       */
/*  output sint8 Diag_trim;                                                   */
/*  output boolean Lfbk_mon_diag_test_request;                                */
/*  output boolean Lfbk_clamp_tests_aborted;                                  */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*  output boolean Lfbk_diag_completed;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidResetDiagTempo(void)
{
   /*03_Reinitialization*/
   VEMS_vidSET(Diag_trim, 0);
   VEMS_vidSET(Lfbk_mon_diag_test_request,0);
   Lfbk_clamp_tests_aborted = 0;
   Lfbk_settling_delay_count = Lfbk_settling_delay_c;
   Lfbk_diag_completed = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidTempoNoFailure                                 */
/* !Description :  Cette fonction contient la temporisation de validation du  */
/*                 diagnostic sans défaut.                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidLfbkMod6NoFailure();                         */
/*  input boolean Lfbk_diag_no_failure_completed;                             */
/*  input uint16 Lfbk_tempo_no_failure;                                       */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Lfbk_no_failure_delay_gas_c;                                 */
/*  input uint16 Lfbk_no_failure_delay_c;                                     */
/*  output uint16 Lfbk_tempo_no_failure;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidTempoNoFailure(void)
{
   /* 02_tempo_no_failure */
   boolean bLocalLfbkDiagNoFailureCompleted;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalNoFailure;


   VEMS_vidGET(Lfbk_diag_no_failure_completed,
               bLocalLfbkDiagNoFailureCompleted);

   if (  (Lfbk_tempo_no_failure == 0)
      && (bLocalLfbkDiagNoFailureCompleted == 0))
   {
      /*02_Lfbk_mod_6_no_failure*/
      INJTICOR_vidLfbkMod6NoFailure();
   }
   if (  (Lfbk_tempo_no_failure != 0)
      && (bLocalLfbkDiagNoFailureCompleted == 0))
   {
      u16LocalNoFailure = (uint16)(Lfbk_tempo_no_failure - 1);
   }
   else
   {
      VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         u16LocalNoFailure = Lfbk_no_failure_delay_gas_c;
      }
      else
      {
         u16LocalNoFailure = Lfbk_no_failure_delay_c;
      }
   }
   Lfbk_tempo_no_failure = (uint16)MATHSRV_udtMIN(u16LocalNoFailure, 49999);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidLfbkMod6NoFailure                              */
/* !Description :  le système doit renvoyer le dernier résultat des tests de  */
/*                 surveillance de la régulation de  richesse au mode$06 du   */
/*                 scantool.                                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_03211_004.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Lambda_feedback;                                             */
/*  output boolean Lfbk_diag_no_failure_completed;                            */
/*  output sint16 Inj_InjTiCorFacMes_Obd6Mod;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidLfbkMod6NoFailure(void)
{
   /*02_Lfbk_mod_6_no_failure*/
   sint16 s16LocalLambdaFeedback;


   VEMS_vidSET(Lfbk_diag_no_failure_completed, 1);
   VEMS_vidGET(Lambda_feedback, s16LocalLambdaFeedback);
   VEMS_vidSET(Inj_InjTiCorFacMes_Obd6Mod, s16LocalLambdaFeedback);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidLowFuelTempo                                   */
/* !Description :  Lorsque le niveau de carburant minimum est atteint, si la  */
/*                 stratégie détecte un défaut de régulation de richesse en   */
/*                 butée d’enrichissement (système bloqué pauvre), une        */
/*                 temporisation est lancée.                                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lfbk_lean_fuel;                                             */
/*  input uint16 Flev_low_fuel_level_lfbk_count;                              */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Flev_low_gas_level_lfbk_tempo;                               */
/*  input uint16 Flev_low_fuel_level_lfbk_tempo;                              */
/*  output uint16 Flev_low_fuel_level_lfbk_count;                             */
/*  output boolean Flev_low_fuel_level_Afl;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidLowFuelTempo(void)
{
   /*03_low_fuel_tempo*/
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalFuelTimerCount;


   if (Lfbk_lean_fuel != 0)
   {
      if (Flev_low_fuel_level_lfbk_count > 0)
      {
         u16LocalFuelTimerCount = (uint16)(Flev_low_fuel_level_lfbk_count - 1);
      }
      else
      {
         u16LocalFuelTimerCount = 0;
      }
   }
   else
   {
      VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         u16LocalFuelTimerCount = Flev_low_gas_level_lfbk_tempo;
      }
      else
      {
         u16LocalFuelTimerCount = Flev_low_fuel_level_lfbk_tempo;
      }
   }
   Flev_low_fuel_level_lfbk_count =
      (uint16)MATHSRV_udtMIN(u16LocalFuelTimerCount, 30000);

   if (Flev_low_fuel_level_lfbk_count == 0)
   {
      Flev_low_fuel_level_Afl = 0;
   }
   else
   {
      Flev_low_fuel_level_Afl = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidPerformClampTests                              */
/* !Description :  La partie curative du diagnostic de la régulation de       */
/*                 richesse en butée  est active si : Elle n'est pas inhibée  */
/*                 manuellement, la surveillance de régulation de richesse a  */
/*                 remonté une panne ou si la partie curative n'a pas été     */
/*                 réalisée.                                                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void INJTICOR_vidInitializeCorrection();                      */
/*  extf argret void INJTICOR_vidFailuresCalculations();                      */
/*  extf argret void INJTICOR_vidDiagnostic();                                */
/*  extf argret void INJTICOR_vidFailureManager();                            */
/*  extf argret void INJTICOR_vidNoFailure();                                 */
/*  input boolean Lfbk_cor_completed;                                         */
/*  input boolean Lfbk_diag_completed;                                        */
/*  input boolean Lfbk_desired_conditions;                                    */
/*  input boolean Lfbk_diag_trim_enable;                                      */
/*  input boolean Clamp_operated;                                             */
/*  input boolean Lfbk_switch_lean;                                           */
/*  input boolean Lfbk_switch_rich;                                           */
/*  input boolean Lfbk_stuck_lean;                                            */
/*  input boolean Lfbk_stuck_rich;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidPerformClampTests(void)
{
   /* 03_perform_clamp_tests */
   boolean bLocalInhInjTiCor;
   boolean bLocalLimInjTiCor;
   boolean bLocalLfbk_cor_completed;


   VEMS_vidGET(Lfbk_cor_completed, bLocalLfbk_cor_completed);
   bLocalInhInjTiCor = GDGAR_bGetFRM(FRM_FRM_INHINJTICOR);
   bLocalLimInjTiCor = GDGAR_bGetFRM(FRM_FRM_LIMINJTICOR);

   if (  (Lfbk_diag_completed == 0)
      || (bLocalLfbk_cor_completed != 0)
      || (bLocalInhInjTiCor != 0))
   {
      /*01_initialize_correction*/
      INJTICOR_vidInitializeCorrection();
   }
   else
   {
      if (Lfbk_desired_conditions != 0)
      {
         if (Lfbk_diag_trim_enable != 0)
         {
            /*02_failures_calculations*/
            INJTICOR_vidFailuresCalculations();
         }
         else
         {
            /*021_Diagnostic*/
            INJTICOR_vidDiagnostic();
         }
      }
   }

   if (bLocalLimInjTiCor != 0)
   {
      /*03_Failure_Manager*/
      INJTICOR_vidFailureManager();
   }

   if (  (Lfbk_desired_conditions != 0)
      && (bLocalLfbk_cor_completed == 0)
      && (Clamp_operated == 0)
      && (Lfbk_diag_completed != 0)
      && (  (Lfbk_switch_lean == 0)
         && (Lfbk_switch_rich == 0)
         && (Lfbk_stuck_lean == 0)
         && (Lfbk_stuck_rich == 0)))
   {
      /*04_no_failure*/
      INJTICOR_vidNoFailure();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInitializeCorrection                           */
/* !Description :  Cette initialisation signifie que la première étape de la  */
/*                 correction est autorisée par Oxy_sensor_test, la deuxième  */
/*                 partie de la correction Check_fuelling_fault sera autorisée*/
/*                 ou non dans la suite du diagnostic.                        */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Lfbk_clamp_test_time_gas_c;                                  */
/*  input uint16 Lfbk_diag_aborted_delay_gas_c;                               */
/*  input uint16 Lfbk_clamp_test_time_c;                                      */
/*  input uint16 Lfbk_diag_aborted_delay_c;                                   */
/*  output boolean Oxy_sensor_test;                                           */
/*  output boolean Check_fuelling_fault;                                      */
/*  output boolean Lfbk_stuck_lean;                                           */
/*  output boolean Lfbk_stuck_rich;                                           */
/*  output boolean Lfbk_switch_rich;                                          */
/*  output boolean Lfbk_switch_lean;                                          */
/*  output uint16 Lfbk_clamp_corr_count;                                      */
/*  output uint16 Lfbk_diag_aborted_count;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInitializeCorrection(void)
{
   /* 01_initialize_correction */
   uint8 u8LocalExt_stSysGas;


   Oxy_sensor_test = 1;
   Check_fuelling_fault = 0;
   Lfbk_stuck_lean = 0;
   Lfbk_stuck_rich = 0;
   Lfbk_switch_rich = 0;
   Lfbk_switch_lean = 0;

   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Lfbk_clamp_corr_count = (uint16)MATHSRV_udtMIN(Lfbk_clamp_test_time_gas_c,
                                                     324);
      Lfbk_diag_aborted_count =
         (uint16)MATHSRV_udtMIN(Lfbk_diag_aborted_delay_gas_c, 2500);
   }
   else
   {
      Lfbk_clamp_corr_count = (uint16)MATHSRV_udtMIN(Lfbk_clamp_test_time_c,
                                                     324);
      Lfbk_diag_aborted_count =
         (uint16)MATHSRV_udtMIN(Lfbk_diag_aborted_delay_c, 2500);
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidFailuresCalculations                           */
/* !Description :  Lorsque une panne de la surveillance de la régulation de   */
/*                 richesse est remontée, la correction agissant sur la chaîne*/
/*                 d'injection, Diag_trim, est activée.                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidResetCorrection();                           */
/*  extf argret void INJTICOR_vidOxySensorTPerformed();                       */
/*  extf argret void INJTICOR_vidWaitAbortFuelCheck();                        */
/*  input boolean Oxy_sensor_test;                                            */
/*  input boolean Clamp_operated;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidFailuresCalculations(void)
{
   /*02_failures_calculations*/
   if (Oxy_sensor_test != 0)
   {
      if (Clamp_operated == 0)
      {
         /*01_re_initialization*/
         INJTICOR_vidResetCorrection();
      }
      /*02_oxy_sensor_test_performed*/
      INJTICOR_vidOxySensorTPerformed();
   }
   else
   {
      /*03_wait_abort_fuel_check*/
      INJTICOR_vidWaitAbortFuelCheck();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidResetCorrection                                */
/* !Description :  Si la régulation de richesse quitte la butée, la correction*/
/*                 est arrêtée.                                               */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Lfbk_fuelling_clamp_delay_gas_c;                             */
/*  input uint16 Lfbk_fuelling_clamp_delay_c;                                 */
/*  output sint8 Diag_trim;                                                   */
/*  output boolean Oxy_sensor_test;                                           */
/*  output uint16 Lfbk_end_of_delay_period_count;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidResetCorrection(void)
{
   uint8  u8LocalExt_stSysGas;


   /*01_re_initialization*/
   VEMS_vidSET(Diag_trim, 0);
   Oxy_sensor_test = 0;

   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Lfbk_end_of_delay_period_count =
         (uint16)MATHSRV_udtMIN(Lfbk_fuelling_clamp_delay_gas_c, 324);
   }
   else
   {
      Lfbk_end_of_delay_period_count =
         (uint16)MATHSRV_udtMIN(Lfbk_fuelling_clamp_delay_c, 324);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidOxySensorTPerformed                            */
/* !Description :  orsque la partie curative est lancée, la chaîne d'injection*/
/*                 est corrigée par le Diag_trim.                             */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidFuelAdjustment();                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Lfbk_clamp_corr_count;                                       */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Lfbk_clamp_test_time_gas_c;                                  */
/*  input uint16 Lfbk_clamp_test_time_c;                                      */
/*  output uint16 Lfbk_clamp_corr_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidOxySensorTPerformed(void)
{
   /*02_oxy_sensor_test_performed*/
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalClampCorrCount;


   if (Lfbk_clamp_corr_count == 0)
   {
      /*01_fuel_adjustment*/
      INJTICOR_vidFuelAdjustment();

      VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         u16LocalClampCorrCount = Lfbk_clamp_test_time_gas_c;
      }
      else
      {
         u16LocalClampCorrCount = Lfbk_clamp_test_time_c;
      }
   }
   else
   {
      u16LocalClampCorrCount = (uint16)(Lfbk_clamp_corr_count - 1);
   }
   Lfbk_clamp_corr_count = (uint16)MATHSRV_udtMIN(u16LocalClampCorrCount, 324);
}
/*------------------------------- end of file --------------------------------*/