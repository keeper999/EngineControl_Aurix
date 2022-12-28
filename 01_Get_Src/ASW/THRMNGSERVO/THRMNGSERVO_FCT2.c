/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRMNGSERVO                                             */
/* !Description     : THRMNGSERVO Component                                   */
/*                                                                            */
/* !Module          : THRMNGSERVO                                             */
/* !Description     : Gestion de l’asservissement du papillon motorise        */
/*                                                                            */
/* !File            : THRMNGSERVO_FCT2.C                                      */
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
/*   1 / THRMNGSERVO_vidTransWaitForAdc                                       */
/*   2 / THRMNGSERVO_vidEntryNodeInitSdf                                      */
/*   3 / THRMNGSERVO_vidTransMcwInhibTest                                     */
/*   4 / THRMNGSERVO_vidTransControl                                          */
/*   5 / THRMNGSERVO_vidTransHighThSearch                                     */
/*   6 / THRMNGSERVO_vidTransClosingRamp                                      */
/*   7 / THRMNGSERVO_vidTransExitLowThrus                                     */
/*   8 / THRMNGSERVO_vidTransLimpHome                                         */
/*   9 / THRMNGSERVO_LearningStopsAndStop                                     */
/*   10 / THRMNGSERVO_vidTransRestorMobil                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 04528 / 16                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRMNGSERVO/THRMNGSERVO_FCT2$*/
/* $Revision::   1.7      $$Author::   etsasson       $$Date::   20 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   20 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRMNGSERVO.h"
#include "THRMNGSERVO_L.h"
#include "THRMNGSERVO_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransWaitForAdc                             */
/* !Description :  Condition de transition de l'etat TPAC_WAIT_FOR_ADC        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRMNGSERVO_vidEntryNodeInitSdf();                       */
/*  input st08 Power_conditions_state;                                        */
/*  input boolean Thr_bCdnAcvCll;                                             */
/*  input boolean Thr_bTestStart_ThrSftyMng;                                  */
/*  input boolean Thr_bAcvPtlWku_C;                                           */
/*  input uint8 Cal_pres_chk;                                                 */
/*  input boolean Thr_bInhCdnAcvCll_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransWaitForAdc(void)
{
   boolean bLocalThr_bCdnAcvCll;
   uint8   u8LocalPower_conditions_state;
   boolean bLocalThr_bTestStart_ThrSftyMng;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   VEMS_vidGET(Thr_bCdnAcvCll, bLocalThr_bCdnAcvCll);
   VEMS_vidGET(Thr_bTestStart_ThrSftyMng, bLocalThr_bTestStart_ThrSftyMng);
   if ( (u8LocalPower_conditions_state == POWER_ON) || (Thr_bAcvPtlWku_C != 0))
   {
      if (  (Cal_pres_chk != 0x55)
         && (bLocalThr_bTestStart_ThrSftyMng != 0)
         && (  (bLocalThr_bCdnAcvCll != 0)
            || (Thr_bInhCdnAcvCll_C != 0)))
      {
         THRMNGSERVO_vidEntryNodeInitSdf();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidEntryNodeInitSdf                            */
/* !Description :  Condition de transition du noeud NodInitSdf                */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRMNGSERVO_LearningStopsAndStop();                      */
/*  input boolean Thr_bPtlWkuOn;                                              */
/*  input st08 Power_conditions_state;                                        */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input uint8 Temperature_air;                                              */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint8 Thr_tAirMaxAuthStopLrn_C;                                     */
/*  input uint8 Thr_tAirMinAuthStopLrn_C;                                     */
/*  input uint16 Thr_uMinBattAuthStopLrn_C;                                   */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidEntryNodeInitSdf(void)
{
   boolean bLocalThr_bRstStopsLrnReq;
   uint8   u8LocalTemperature_air;
   uint8   u8LocalPower_conditions_state;
   uint16  u16LocalTension_batterie_brute;


   if (Thr_bPtlWkuOn == 0)
   {
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_MCW_INHIBIT_TEST);
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
      if ( u8LocalPower_conditions_state == POWER_ON)
      {
         VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);
         VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
         VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
         if (  (bLocalThr_bRstStopsLrnReq != 0)
            && (Tpac_thrusts_search_diag_inh == 0)
            && ( u8LocalTemperature_air < Thr_tAirMaxAuthStopLrn_C)
            && ( u8LocalTemperature_air > Thr_tAirMinAuthStopLrn_C)
            && ( u16LocalTension_batterie_brute > Thr_uMinBattAuthStopLrn_C))
         {
            VEMS_vidSET(Thr_bStopsLrnInProgs, 1);
            THRMNGSERVO_LearningStopsAndStop();
         }
         else
         {
            VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
            THRMNGSERVO_bTransitionDone = 1;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransMcwInhibTest                           */
/* !Description :  Condition de transition de l'etat TPAC_MCW_INHIBIT_TEST    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRMNGSERVO_LearningStopsAndStop();                      */
/*  input boolean Thr_bEndTestInh_CpuSfty;                                    */
/*  input boolean Thr_bTestAbort_ThrSftyMng;                                  */
/*  input boolean Thr_bAcvTestAbortSfty_C;                                    */
/*  input boolean Thr_bMblRstorAcv;                                           */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input uint8 Temperature_air;                                              */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint8 Thr_tAirMaxAuthStopLrn_C;                                     */
/*  input uint8 Thr_tAirMinAuthStopLrn_C;                                     */
/*  input uint16 Thr_uMinBattAuthStopLrn_C;                                   */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output boolean Thr_bPtlWkuOn;                                             */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransMcwInhibTest(void)
{
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bEndTestInh_CpuSfty;
   boolean bLocalThr_bMblRstorAcv;
   boolean bLocalThr_bTestAbort_ThrSftyMng;
   uint8   u8LocalTemperature_air;
   uint16  u16LocalTension_batterie_brute;


   VEMS_vidGET(Thr_bEndTestInh_CpuSfty, bLocalThr_bEndTestInh_CpuSfty);
   VEMS_vidGET(Thr_bTestAbort_ThrSftyMng, bLocalThr_bTestAbort_ThrSftyMng);

   if (  (bLocalThr_bTestAbort_ThrSftyMng != 0)
      && (Thr_bAcvTestAbortSfty_C != 0))
   {
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_WAIT_FOR_ADC);
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      if (bLocalThr_bEndTestInh_CpuSfty != 0)
      {
         Thr_bPtlWkuOn = 1;
         VEMS_vidGET(Thr_bMblRstorAcv, bLocalThr_bMblRstorAcv);
         if (bLocalThr_bMblRstorAcv != 0)
         {
            VEMS_vidSET(Tpac_throttle_control_state, TPAC_RESTOR_MOBILITY);
            THRMNGSERVO_bTransitionDone = 1;
         }
         else
         {
            VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
            VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);
            VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
            if (  (bLocalThr_bRstStopsLrnReq != 0)
            && (Tpac_thrusts_search_diag_inh == 0)
            && ( u8LocalTemperature_air < Thr_tAirMaxAuthStopLrn_C)
            && ( u8LocalTemperature_air > Thr_tAirMinAuthStopLrn_C)
            && ( u16LocalTension_batterie_brute > Thr_uMinBattAuthStopLrn_C))
            {
               VEMS_vidSET(Thr_bStopsLrnInProgs, 1);
               THRMNGSERVO_LearningStopsAndStop();
            }
            else
            {
               VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
               THRMNGSERVO_bTransitionDone = 1;
            }
         }
      }
      else
      {
         /* on reste à l'état TPAC_MCW_INHIBIT_TEST */
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransControl                                */
/* !Description :  Condition de transition de l'etat TPAC_CONTROL             */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void THRMNGSERVO_LearningStopsAndStop();                      */
/*  extf argret void Thr_EveIniLrnLih_StopClcn();                             */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean Srv_bInhThr;                                                */
/*  input boolean Moteur_tournant;                                            */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Tpac_thrust_search_cleoff_tempo;                             */
/*  input uint8 Temperature_eau;                                              */
/*  input uint16 Ext_tiStrt;                                                  */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input boolean Tpac_FCln_enable;                                           */
/*  input uint8 Tpac_FCln_water_temp_mini;                                    */
/*  input uint16 Thr_uBattMinStopsCln_C;                                      */
/*  input uint16 Thr_uBattMaxStopsCln_C;                                      */
/*  input uint16 Thr_tiStrtMinStopsCln_C;                                     */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Tpac_thrusts_water_temp_mini;                                 */
/*  input uint8 Tpac_thrusts_water_temp_maxi;                                 */
/*  input uint8 Tpac_thrusts_air_temp_mini;                                   */
/*  input uint8 Tpac_thrusts_air_temp_maxi;                                   */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint16 Thr_uBattMinStopsLrn_C;                                      */
/*  input uint16 Thr_uBattMaxStopsLrn_C;                                      */
/*  input boolean Tpac_thrusts_enable;                                        */
/*  input uint16 Tpac_store_limp_home_delay;                                  */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*  output boolean Thr_bFClnInProgs;                                          */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTpacLimpHomeFlag;                             */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output uint16 Tpac_store_limp_home_tempo;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransControl(void)
{
   boolean  bLocalTemperature;
   boolean  bLocalMoteur_tournant;
   boolean  bLocalTpac_thrusts_enable;
   boolean  bLocalInhFThrCln;
   boolean  bLocalTpac_FCln_enable;
   boolean  bLocalThr_bInhMngThrServo;
   boolean  bLocalSrv_bInhThr;
   uint8    u8LocalPower_conditions_state;
   uint8    u8LocalTemperature_air;
   uint8    u8LocalTemperature_eau;
   uint16   u16LocalTension_batterie_brute;
   uint16   u16LocalExt_tiStrt;

   VEMS_vidGET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);
   VEMS_vidGET(Srv_bInhThr, bLocalSrv_bInhThr);
   if (  (bLocalThr_bInhMngThrServo != 0)
      || (bLocalSrv_bInhThr != 0))
   {
      VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
      VEMS_vidSET(Thr_bFClnInProgs, 0);
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
      THRMNGSERVO_bTpacLimpHomeFlag = 0;
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
      VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
      if(  (bLocalMoteur_tournant == 0)
        && (u8LocalPower_conditions_state == WAITING_FOR_POWER_LATCH_DELAY)
        && (Tpac_thrust_search_cleoff_tempo == 0))
      {
         VEMS_vidGET(Temperature_eau,u8LocalTemperature_eau);
         VEMS_vidGET(Ext_tiStrt, u16LocalExt_tiStrt);
         VEMS_vidGET(Tension_batterie_brute,u16LocalTension_batterie_brute);
         VEMS_vidGET(Tpac_FCln_enable, bLocalTpac_FCln_enable);
         bLocalInhFThrCln = GDGAR_bGetFRM (FRM_FRM_INHFTHRCLN);
         if (  (u8LocalTemperature_eau > Tpac_FCln_water_temp_mini)
            && (u16LocalTension_batterie_brute > Thr_uBattMinStopsCln_C)
            && (u16LocalTension_batterie_brute < Thr_uBattMaxStopsCln_C)
            && (bLocalInhFThrCln == 0)
            && (u16LocalExt_tiStrt >= Thr_tiStrtMinStopsCln_C)
            && (bLocalTpac_FCln_enable != 0))
         {
            VEMS_vidSET(Thr_bFClnInProgs, 1);
            THRMNGSERVO_LearningStopsAndStop();
         }
         else
         {
            VEMS_vidGET(Temperature_air,u8LocalTemperature_air);

            if (  (u8LocalTemperature_eau < Tpac_thrusts_water_temp_mini)
               || (u8LocalTemperature_eau > Tpac_thrusts_water_temp_maxi)
               || (u8LocalTemperature_air < Tpac_thrusts_air_temp_mini)
               || (u8LocalTemperature_air > Tpac_thrusts_air_temp_maxi))
            {
               bLocalTemperature = 1;
            }
            else
            {
               bLocalTemperature = 0;
            }
            if (  (Tpac_thrusts_search_diag_inh !=0)
               || (bLocalTemperature != 0)
               || (u16LocalTension_batterie_brute < Thr_uBattMinStopsLrn_C)
               || (u16LocalTension_batterie_brute > Thr_uBattMaxStopsLrn_C))
            {
               VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
               VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
               VEMS_vidSET(Thr_bFClnInProgs, 0);
               THRMNGSERVO_bTpacLimpHomeFlag = 0;
               THRMNGSERVO_bTransitionDone = 1;
            }
            else
            {
               VEMS_vidGET(Tpac_thrusts_enable, bLocalTpac_thrusts_enable);
               if (bLocalTpac_thrusts_enable == 0)
               {
                  Thr_EveIniLrnLih_StopClcn();
                  VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
                  Tpac_store_limp_home_tempo =
                     (uint16)MATHSRV_udtMIN(Tpac_store_limp_home_delay, 800);
                  THRMNGSERVO_bTpacLimpHomeFlag = 1;
                  THRMNGSERVO_bTransitionDone = 1;
               }
               else
               {
                  VEMS_vidSET(Thr_bStopsLrnInProgs, 1);
                  THRMNGSERVO_LearningStopsAndStop();
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransHighThSearch                           */
/* !Description :  Condition de transition de l'etat TPAC_HIGH_THRUST_SEARCH  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Thr_EveStoreHiStop_MngServo();                           */
/*  extf argret void Thr_EveIniStop_MngServo();                               */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Thr_bDeacThrStopLrn;                                        */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint16 Thr_nMaxAuthStopLrn_C;                                       */
/*  input uint16 Tpac_thrust_search_tempo;                                    */
/*  input boolean Thr_bFClnInProgs;                                           */
/*  input uint16 Tpac_closing_ramp_delay;                                     */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*  output boolean Thr_bFClnInProgs;                                          */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output boolean THRMNGSERVO_bTpacLimpHomeFlag;                             */
/*  output uint16 Tpac_thrust_search_tempo;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransHighThSearch(void)
{
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bDeacThrStopLrn;
   boolean bLocalThr_bFClnInProgs;
   boolean bLocalThr_bInhMngThrServo;
   uint8   u8LocalPower_conditions_state;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Thr_bDeacThrStopLrn, bLocalThr_bDeacThrStopLrn);
   VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);
   VEMS_vidGET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);
   if (  (u8LocalPower_conditions_state == POWER_ON)
      && (bLocalThr_bInhMngThrServo == 0)
      && (  (bLocalThr_bRstStopsLrnReq == 0)
         || (Tpac_thrusts_search_diag_inh != 0)
         || (bLocalThr_bDeacThrStopLrn != 0)
         || (u16LocalRegime_moteur > Thr_nMaxAuthStopLrn_C)))
   {
      VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
      VEMS_vidSET(Thr_bFClnInProgs, 0);
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      if (  (bLocalThr_bInhMngThrServo != 0)
         || (bLocalThr_bDeacThrStopLrn != 0))
      {
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
         VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
         VEMS_vidSET(Thr_bFClnInProgs, 0);
         THRMNGSERVO_bTpacLimpHomeFlag = 0;
         THRMNGSERVO_bTransitionDone = 1;
      }
      else
      {
         if (Tpac_thrust_search_tempo == 0)
         {
            VEMS_vidGET(Thr_bFClnInProgs, bLocalThr_bFClnInProgs);
            if(bLocalThr_bFClnInProgs == 0)
            {
               Thr_EveStoreHiStop_MngServo();
            }
            Thr_EveIniStop_MngServo();
            VEMS_vidSET(Tpac_throttle_control_state, TPAC_CLOSING_RAMP);
            Tpac_thrust_search_tempo =
               (uint16)MATHSRV_udtMIN(Tpac_closing_ramp_delay, 800);
            THRMNGSERVO_bTransitionDone = 1;
         }
         else
         {
          /* On reste en TPAC_HIGH_THRUST_SEARCH */
         }
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransClosingRamp                            */
/* !Description :  Condition de transition de l'etat TPAC_CLOSING_RAMP        */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRMNGSERVO_vidDownThrustEnable();                       */
/*  extf argret void Thr_EveStoreLoStop_MngServo();                           */
/*  extf argret void Thr_EveIniLrnLih_StopClcn();                             */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Thr_bDeacThrStopLrn;                                        */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint16 Thr_nMaxAuthStopLrn_C;                                       */
/*  input uint16 Tpac_thrust_search_tempo;                                    */
/*  input boolean Tpac_throttle_lh_pos;                                       */
/*  input boolean Thr_bFClnInProgs;                                           */
/*  input uint16 Tpac_exit_low_thrust_delay;                                  */
/*  input uint16 Tpac_store_limp_home_delay;                                  */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*  output boolean Thr_bFClnInProgs;                                          */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output boolean THRMNGSERVO_bTpacLimpHomeFlag;                             */
/*  output uint16 Tpac_thrust_search_tempo;                                   */
/*  output uint16 Tpac_store_limp_home_tempo;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransClosingRamp(void)
{
   boolean bLocalThr_bDeacThrStopLrn;
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bFClnInProgs;
   boolean bLocalThr_bInhMngThrServo;
   uint8   u8LocalPower_conditions_state;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Thr_bDeacThrStopLrn, bLocalThr_bDeacThrStopLrn);
   VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);
   VEMS_vidGET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);

   if (  (u8LocalPower_conditions_state == POWER_ON)
      && (bLocalThr_bInhMngThrServo == 0)
      && (  (bLocalThr_bRstStopsLrnReq == 0)
         || (Tpac_thrusts_search_diag_inh != 0)
         || (bLocalThr_bDeacThrStopLrn != 0)
         || (u16LocalRegime_moteur > Thr_nMaxAuthStopLrn_C)))
   {
      VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
      VEMS_vidSET(Thr_bFClnInProgs, 0);
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      if (  (bLocalThr_bInhMngThrServo != 0)
         || (bLocalThr_bDeacThrStopLrn != 0))
      {
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
         VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
         VEMS_vidSET(Thr_bFClnInProgs, 0);
         THRMNGSERVO_bTpacLimpHomeFlag = 0;
         THRMNGSERVO_bTransitionDone = 1;
      }
      else
      {
         if (Tpac_thrust_search_tempo == 0)
         {
            if (Tpac_throttle_lh_pos != 0)
            {
               VEMS_vidGET(Thr_bFClnInProgs, bLocalThr_bFClnInProgs);
                /* 04_Down_thrust_enable */
               if (bLocalThr_bFClnInProgs == 0)
               {
                  THRMNGSERVO_vidDownThrustEnable();
                  Thr_EveStoreLoStop_MngServo();
               }

               VEMS_vidSET(Tpac_throttle_control_state, TPAC_EXIT_LOW_THRUST);
               Tpac_thrust_search_tempo =
                  (uint16)MATHSRV_udtMIN(Tpac_exit_low_thrust_delay, 800);
               THRMNGSERVO_bTransitionDone = 1;
            }
            else
            {
               Thr_EveIniLrnLih_StopClcn();
               VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
               Tpac_store_limp_home_tempo =
                  (uint16)MATHSRV_udtMIN(Tpac_store_limp_home_delay, 800);
               THRMNGSERVO_bTpacLimpHomeFlag = 1;
               THRMNGSERVO_bTransitionDone = 1;
            }
         }
         else
         {
               /* On reste en TPAC_CLOSING_RAMP */
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransExitLowThrus                           */
/* !Description :  Condition de transition de l'etat TPAC_EXIT_LOW_THRUST     */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Thr_EveIniLrnLih_StopClcn();                             */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Thr_bDeacThrStopLrn;                                        */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint16 Thr_nMaxAuthStopLrn_C;                                       */
/*  input uint16 Tpac_thrust_search_tempo;                                    */
/*  input uint16 Tpac_store_limp_home_delay;                                  */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*  output boolean Thr_bFClnInProgs;                                          */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output boolean THRMNGSERVO_bTpacLimpHomeFlag;                             */
/*  output uint16 Tpac_store_limp_home_tempo;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransExitLowThrus(void)
{
   boolean bLocalThr_bDeacThrStopLrn;
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bInhMngThrServo;
   uint8   u8LocalPower_conditions_state;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Thr_bDeacThrStopLrn, bLocalThr_bDeacThrStopLrn);
   VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);
   VEMS_vidGET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);

   if (  (u8LocalPower_conditions_state == POWER_ON)
      && (bLocalThr_bInhMngThrServo == 0)
      && (  (bLocalThr_bRstStopsLrnReq == 0)
         || (Tpac_thrusts_search_diag_inh != 0)
         || (bLocalThr_bDeacThrStopLrn != 0)
         || (u16LocalRegime_moteur > Thr_nMaxAuthStopLrn_C)))
   {
      VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
      VEMS_vidSET(Thr_bFClnInProgs, 0);
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      if (  (bLocalThr_bInhMngThrServo != 0)
         || (bLocalThr_bDeacThrStopLrn != 0))
      {
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
         VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
         VEMS_vidSET(Thr_bFClnInProgs, 0);
         THRMNGSERVO_bTpacLimpHomeFlag = 0;
         THRMNGSERVO_bTransitionDone = 1;
      }
      else
      {
         if (Tpac_thrust_search_tempo == 0)
         {
            Thr_EveIniLrnLih_StopClcn();
            VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
            Tpac_store_limp_home_tempo =
               (uint16)MATHSRV_udtMIN(Tpac_store_limp_home_delay, 800);
            THRMNGSERVO_bTpacLimpHomeFlag = 1;
            THRMNGSERVO_bTransitionDone = 1;
         }
         else
         {
               /* On reste en TPAC_EXIT_LOW_THRUST */
         }
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransLimpHome                               */
/* !Description :  Condition de transition de l'etat TPAC_LIMP_HOME           */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRMNGSERVO_LearningStopsAndStop();                      */
/*  extf argret void THRMNGSERVO_vidThrIniAftsStopCln();                      */
/*  extf argret void Thr_EveStoreLih_StopClcn();                              */
/*  extf argret void Thr_EveStoreLih_SecuMng();                               */
/*  extf argret void THRMNGSERVO_vidEndThrLrn();                              */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Thr_bDeacThrStopLrn;                                        */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint16 Thr_nMaxAuthStopLrn_C;                                       */
/*  input boolean THRMNGSERVO_bTpacLimpHomeFlag;                              */
/*  input boolean Trans_clef_off_on;                                          */
/*  input boolean Thr_bInhThrFallTran;                                        */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Thr_tAirMaxAuthStopLrn_C;                                     */
/*  input uint8 Thr_tAirMinAuthStopLrn_C;                                     */
/*  input uint16 Thr_uMinBattAuthStopLrn_C;                                   */
/*  input uint16 Tpac_store_limp_home_tempo;                                  */
/*  input boolean Thr_bFClnInProgs;                                           */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*  output boolean Thr_bFClnInProgs;                                          */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output boolean THRMNGSERVO_bTpacLimpHomeFlag;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransLimpHome(void)
{
   boolean bLocalThr_bDeacThrStopLrn;
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bFClnInProgs;
   boolean bLocalThr_bInhMngThrServo;
   uint8   u8LocalPower_conditions_state;
   uint8   u8LocalTemperature_air;
   uint16  u16LocalTension_batterie_brute;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Thr_bDeacThrStopLrn, bLocalThr_bDeacThrStopLrn);
   VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);
   VEMS_vidGET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);

   if (  (u8LocalPower_conditions_state == POWER_ON)
      && (bLocalThr_bInhMngThrServo == 0)
      && (  (bLocalThr_bRstStopsLrnReq == 0)
         || (Tpac_thrusts_search_diag_inh != 0)
         || (bLocalThr_bDeacThrStopLrn != 0)
         || (u16LocalRegime_moteur > Thr_nMaxAuthStopLrn_C)))
   {
      VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
      VEMS_vidSET(Thr_bFClnInProgs, 0);
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      if (THRMNGSERVO_bTpacLimpHomeFlag == 0)
      {
         if (  (  (Trans_clef_off_on != 0)
               && (bLocalThr_bInhMngThrServo == 0 )
               && (bLocalThr_bRstStopsLrnReq != 0 ))
            || (Thr_bInhThrFallTran != 0))
         {
            VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
            VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
            if (  (Tpac_thrusts_search_diag_inh == 0)
               && (u8LocalTemperature_air < Thr_tAirMaxAuthStopLrn_C)
               && (u8LocalTemperature_air > Thr_tAirMinAuthStopLrn_C)
               && (u16LocalTension_batterie_brute > Thr_uMinBattAuthStopLrn_C))
            {
               VEMS_vidSET(Thr_bStopsLrnInProgs, 1);
               THRMNGSERVO_LearningStopsAndStop();
            }
            else
            {
               VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
               THRMNGSERVO_bTransitionDone = 1;
            }
         }
         else
         {
           /* On reste en TPAC_LIMP_HOME */
         }
      }
      else
      {
         if (Tpac_store_limp_home_tempo == 0)
         {
            THRMNGSERVO_vidThrIniAftsStopCln();
            VEMS_vidGET(Thr_bFClnInProgs, bLocalThr_bFClnInProgs);
            if (bLocalThr_bFClnInProgs == 0)
            {
               Thr_EveStoreLih_StopClcn();
               Thr_EveStoreLih_SecuMng();
               THRMNGSERVO_vidEndThrLrn();
            }
            THRMNGSERVO_bTpacLimpHomeFlag = 0;
            VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
            VEMS_vidSET(Thr_bFClnInProgs, 0);
            /* On reste en TPAC_LIMP_HOME */
         }
         else
         {
            /* On reste en TPAC_LIMP_HOME */
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_LearningStopsAndStop                           */
/* !Description :  focntion d'apprentissage butées et arret                   */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Thr_EveIniStop_MngServo();                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Thr_EveStoreHiStop_MngServo();                           */
/*  extf argret void Thr_EveIniLrnLih_StopClcn();                             */
/*  input boolean Thr_bStopsLrnInProgs;                                       */
/*  input boolean Thr_bFClnInProgs;                                           */
/*  input boolean Tpac_open_thrust_search_inh;                                */
/*  input boolean Thr_bInhFClnHiStop_C;                                       */
/*  input uint16 Tpac_thrust_search_delay;                                    */
/*  input boolean Tpac_throttle_lh_pos;                                       */
/*  input uint16 Tpac_closing_ramp_delay;                                     */
/*  input uint16 Tpac_store_limp_home_delay;                                  */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output uint16 Tpac_thrust_search_tempo;                                   */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output uint16 Tpac_store_limp_home_tempo;                                 */
/*  output boolean THRMNGSERVO_bTpacLimpHomeFlag;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_LearningStopsAndStop(void)
{
   boolean bLocalThr_bStopsLrnInProgs;
   boolean bLocalThr_bFClnInProgs;


   VEMS_vidGET(Thr_bStopsLrnInProgs, bLocalThr_bStopsLrnInProgs);
   VEMS_vidGET(Thr_bFClnInProgs, bLocalThr_bFClnInProgs);
   if (  (  (bLocalThr_bStopsLrnInProgs != 0)
         && (Tpac_open_thrust_search_inh == 0))
      || (  (bLocalThr_bFClnInProgs != 0)
         && (Thr_bInhFClnHiStop_C == 0)))
   {
      Thr_EveIniStop_MngServo();
      VEMS_vidSET(Tpac_throttle_control_state, TPAC_HIGH_THRUST_SEARCH);
      Tpac_thrust_search_tempo =
         (uint16)MATHSRV_udtMIN(Tpac_thrust_search_delay, 800);
      THRMNGSERVO_bTransitionDone = 1;
   }
   else
   {
      if (bLocalThr_bFClnInProgs == 0)
      {
         Thr_EveStoreHiStop_MngServo();
      }
      if (Tpac_throttle_lh_pos != 0)
      {
         Thr_EveIniStop_MngServo();
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_CLOSING_RAMP);
         Tpac_thrust_search_tempo =
            (uint16)MATHSRV_udtMIN(Tpac_closing_ramp_delay, 800);
         THRMNGSERVO_bTransitionDone = 1;
      }
      else
      {
         Thr_EveIniLrnLih_StopClcn();
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_LIMP_HOME);
         Tpac_store_limp_home_tempo =
            (uint16)MATHSRV_udtMIN(Tpac_store_limp_home_delay, 800);
         THRMNGSERVO_bTpacLimpHomeFlag = 1;
         THRMNGSERVO_bTransitionDone = 1;
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidTransRestorMobil                            */
/* !Description :  Condition de transition de l'etat TPAC_RESTOR_MOBILITY.    */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRMNGSERVO_LearningStopsAndStop();                      */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input uint8 Temperature_air;                                              */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input boolean Tpac_thrusts_search_diag_inh;                               */
/*  input uint8 Thr_tAirMaxAuthStopLrn_C;                                     */
/*  input uint8 Thr_tAirMinAuthStopLrn_C;                                     */
/*  input uint16 Thr_uMinBattAuthStopLrn_C;                                   */
/*  input boolean Thr_bMblRstorInProgs;                                       */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidTransRestorMobil(void)
{
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bMblRstorInProgs;
   uint8   u8LocalPower_conditions_state;
   uint8   u8LocalTemperature_air;
   uint16  u16LocalTension_batterie_brute;

   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   if (u8LocalPower_conditions_state == POWER_ON)
   {
      VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
      VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
      VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);

      if (  (bLocalThr_bRstStopsLrnReq != 0)
         && (Tpac_thrusts_search_diag_inh == 0)
         && ( u8LocalTemperature_air < Thr_tAirMaxAuthStopLrn_C)
         && ( u8LocalTemperature_air > Thr_tAirMinAuthStopLrn_C)
         && ( u16LocalTension_batterie_brute > Thr_uMinBattAuthStopLrn_C))
      {
         VEMS_vidSET(Thr_bStopsLrnInProgs, 1);
         THRMNGSERVO_LearningStopsAndStop();
      }
      else
      {
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_CONTROL);
         THRMNGSERVO_bTransitionDone = 1;
      }
   }
   else
   {
      VEMS_vidGET(Thr_bMblRstorInProgs, bLocalThr_bMblRstorInProgs);
      if(bLocalThr_bMblRstorInProgs == 0)
      {
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_WAIT_FOR_ADC);
         THRMNGSERVO_bTransitionDone = 1;
      }
   }
}

/*------------------------------- end of file --------------------------------*/