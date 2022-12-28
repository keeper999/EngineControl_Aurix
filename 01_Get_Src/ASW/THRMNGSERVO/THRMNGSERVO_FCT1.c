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
/* !File            : THRMNGSERVO_FCT1.C                                      */
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
/*   1 / THRMNGSERVO_vidInitOutput                                            */
/*   2 / THRMNGSERVO_vidPowrLatchCountMng                                     */
/*   3 / THRMNGSERVO_vidManager                                               */
/*   4 / THRMNGSERVO_vidCalTempCleoff                                         */
/*   5 / THRMNGSERVO_vidManagerTransition                                     */
/*   6 / THRMNGSERVO_vidManagerTreatment                                      */
/*   7 / THRMNGSERVO_vidThrServoInh                                           */
/*   8 / THRMNGSERVO_vidCalInhibInjection                                     */
/*   9 / THRMNGSERVO_vidSrvTran                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 04528 / 16                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRMNGSERVO/THRMNGSERVO_FCT1$*/
/* $Revision::   1.5      $$Author::   etsasson       $$Date::   20 Sep 2012 $*/
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
/* !Function    :  THRMNGSERVO_vidInitOutput                                  */
/* !Description :  fonction d'initialisation des variables produites.         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_thrust_search_cleoff_delay;                             */
/*  output boolean Thr_bInhInjMngServo;                                       */
/*  output boolean Thr_bStopsLrnInProgs;                                      */
/*  output boolean Thr_bFClnInProgs;                                          */
/*  output boolean Thr_bPtlWkuOn;                                             */
/*  output boolean Trans_clef_off_on;                                         */
/*  output uint16 Tpac_thrust_search_cleoff_tempo;                            */
/*  output boolean THRMNGSERVO_bExtbDrvCyGlblPrev;                            */
/*  output st01 Tpac_throttle_control_state;                                  */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*  output st113 THRMNGSERVO_stCalcTempoCleoff;                               */
/*  output boolean THRMNGSERVO_bTpacLimpHomeFlag;                             */
/*  output boolean THRMNGSERVO_bCalcCleTempo_on;                              */
/*  output boolean THRMNGSERVO_bSrv_bInhThrPrev;                              */
/*  output boolean Thr_bInhThrFallTran;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidInitOutput(void)
{
   VEMS_vidSET(Thr_bInhInjMngServo, 0);
   VEMS_vidSET(Thr_bStopsLrnInProgs, 0);
   VEMS_vidSET(Thr_bFClnInProgs, 0);
   Thr_bPtlWkuOn = 0;
   Trans_clef_off_on = 0;
   Tpac_thrust_search_cleoff_tempo =
      (uint16)MATHSRV_udtMIN(Tpac_thrust_search_cleoff_delay, 800);
   THRMNGSERVO_bExtbDrvCyGlblPrev = 0;
   VEMS_vidSET(Tpac_throttle_control_state, TPAC_WAIT_FOR_ADC);
   THRMNGSERVO_bTransitionDone = 0;
   THRMNGSERVO_stCalcTempoCleoff = CLEF_ON;
   THRMNGSERVO_bTpacLimpHomeFlag = 0;
   THRMNGSERVO_bCalcCleTempo_on = 1;
   THRMNGSERVO_bSrv_bInhThrPrev = 0;
   Thr_bInhThrFallTran = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidPowrLatchCountMng                           */
/* !Description :  Comptage des passages en Power-Latch de manière à pouvoir  */
/*                 gérer l’espacement entre les apprentissages des butées. Le */
/*                 comptage n’a pas lieu si une demande d’apprentissage des   */
/*                 butées est déjà active ou une demande de nettoyage est en  */
/*                 cours.                                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tpac_thrusts_enable;                                        */
/*  input boolean Ext_bDrvCyGlbl;                                             */
/*  input boolean Tpac_FCln_enable;                                           */
/*  input boolean THRMNGSERVO_bExtbDrvCyGlblPrev;                             */
/*  input uint8 Tpac_thrusts_powerlatch_counter;                              */
/*  input uint8 Tpac_thrusts_powerlatch_cnt_max;                              */
/*  input boolean Thr_bInhStopLrnKeyOff;                                      */
/*  input uint8 Tpac_FCln_powerlatch_counter;                                 */
/*  input uint8 Tpac_FCln_powerlatch_cnt_Thd;                                 */
/*  input boolean Thr_bInhThrCln_C;                                           */
/*  output uint8 Tpac_thrusts_powerlatch_counter;                             */
/*  output boolean Tpac_thrusts_enable;                                       */
/*  output uint8 Tpac_FCln_powerlatch_counter;                                */
/*  output boolean Tpac_FCln_enable;                                          */
/*  output boolean THRMNGSERVO_bExtbDrvCyGlblPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidPowrLatchCountMng(void)
{
   boolean bLocalExt_bDrvCyGlbl;
   boolean bLocalTpac_thrusts_enable;
   boolean bLocalTpac_FCln_enable;
   uint16  u16LocalthrustsCounter;
   uint16  u16LocalTpacthrpowercntmax;
   uint16  u16LocalFClnCounter;


   VEMS_vidGET(Tpac_thrusts_enable, bLocalTpac_thrusts_enable);
   VEMS_vidGET(Ext_bDrvCyGlbl, bLocalExt_bDrvCyGlbl);
   VEMS_vidGET(Tpac_FCln_enable, bLocalTpac_FCln_enable);
   if (  (bLocalExt_bDrvCyGlbl != 0)
      && (THRMNGSERVO_bExtbDrvCyGlblPrev == 0)
      && (  (bLocalTpac_thrusts_enable == 0)
         || (bLocalTpac_FCln_enable == 0)))
   {
      u16LocalthrustsCounter = (uint16)(Tpac_thrusts_powerlatch_counter + 1);
      u16LocalTpacthrpowercntmax =
         (uint16)(Tpac_thrusts_powerlatch_cnt_max + 1);
      if (  (u16LocalthrustsCounter >= u16LocalTpacthrpowercntmax)
         && (Thr_bInhStopLrnKeyOff == 0))
      {
         Tpac_thrusts_powerlatch_counter = 0;
         VEMS_vidSET(Tpac_thrusts_enable, 1);
      }
      else
      {
         Tpac_thrusts_powerlatch_counter =
            (uint8)MATHSRV_udtMIN(u16LocalthrustsCounter, 254);
      }
      u16LocalFClnCounter = (uint16)(Tpac_FCln_powerlatch_counter + 1);
      if (  (u16LocalFClnCounter >= Tpac_FCln_powerlatch_cnt_Thd)
         && (Thr_bInhThrCln_C == 0))
      {
         Tpac_FCln_powerlatch_counter = 0;
         VEMS_vidSET(Tpac_FCln_enable, 1);
      }
      else
      {
         Tpac_FCln_powerlatch_counter =
            (uint8)MATHSRV_udtMIN(u16LocalFClnCounter, 255);
      }
   }
   else
   {
      Tpac_thrusts_powerlatch_counter =
         (uint8)MATHSRV_udtMIN(Tpac_thrusts_powerlatch_counter, 254);
   }
   THRMNGSERVO_bExtbDrvCyGlblPrev = bLocalExt_bDrvCyGlbl;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidManager                                     */
/* !Description :  Gestionnaire des différents modes de                       */
/*                 fonctionnement/asservissement du papillon                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRMNGSERVO_vidCalTempCleoff();                          */
/*  extf argret void THRMNGSERVO_vidManagerTransition();                      */
/*  extf argret void THRMNGSERVO_vidManagerTreatment();                       */
/*  extf argret void THRMNGSERVO_vidThrServoInh();                            */
/*  extf argret void THRMNGSERVO_vidCalInhibInjection();                      */
/*  input boolean THRMNGSERVO_bTransitionDone;                                */
/*  output boolean THRMNGSERVO_bTransitionDone;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidManager(void)
{
      /* Calc_Tempo_Cleoff */
   THRMNGSERVO_vidCalTempCleoff();
      /* Gestion_Servo */
   THRMNGSERVO_vidManagerTransition();
   if (THRMNGSERVO_bTransitionDone != 0)
   {
      THRMNGSERVO_bTransitionDone = 0;
   }
   else
   {
      THRMNGSERVO_vidManagerTreatment();
   }

     /* Calc_Inhibit_Servo_Controle */
   THRMNGSERVO_vidThrServoInh();

     /* Calc_Inhibit_Injection */
   THRMNGSERVO_vidCalInhibInjection();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidCalTempCleoff                               */
/* !Description :  fonction de calcul Tempo_Cleoff                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Clef_de_contact;                                            */
/*  input st113 THRMNGSERVO_stCalcTempoCleoff;                                */
/*  input uint8 Thr_dlyKeyOn_C;                                               */
/*  input boolean THRMNGSERVO_bCalcCleTempo_on;                               */
/*  input uint8 Thr_dlyKeyOn;                                                 */
/*  input boolean Trans_clef_off_on;                                          */
/*  input uint16 Tpac_thrust_search_cleoff_delay;                             */
/*  input uint16 Tpac_thrust_search_cleoff_tempo;                             */
/*  output boolean Trans_clef_off_on;                                         */
/*  output st113 THRMNGSERVO_stCalcTempoCleoff;                               */
/*  output uint8 Thr_dlyKeyOn;                                                */
/*  output boolean THRMNGSERVO_bCalcCleTempo_on;                              */
/*  output uint16 Tpac_thrust_search_cleoff_tempo;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidCalTempCleoff(void)
{
   boolean bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   switch (THRMNGSERVO_stCalcTempoCleoff)
   {
      case CLEF_ON:
         if (bLocalClef_de_contact == 0)
         {
            /* on passe à l'état Clef_off */
            Trans_clef_off_on = 0;
            THRMNGSERVO_stCalcTempoCleoff = CLEF_OFF;
            Thr_dlyKeyOn = (uint8)MATHSRV_udtMIN(Thr_dlyKeyOn_C, 100);
         }
         else
         {
            if (THRMNGSERVO_bCalcCleTempo_on != 0)
            {
               /* tempo_on*/
               if (Thr_dlyKeyOn > 0)
               {
                  /*  on reste à tempo_on */
                  Thr_dlyKeyOn = (uint8)(Thr_dlyKeyOn - 1);
               }
               else
               {
                  /* on passe à tempo_off */
                  Trans_clef_off_on = 1;
                  THRMNGSERVO_bCalcCleTempo_on = 0;
               }
            }
            else
            {
               /* tempo_off*/
               if (Trans_clef_off_on != 0)
               {
                  Trans_clef_off_on = 0;
               }
            }
         }
      break;

      case CLEF_OFF:
         if (bLocalClef_de_contact != 0)
         {
            /* on passe à l'état Clef_on, Tempo_on */
            THRMNGSERVO_stCalcTempoCleoff = CLEF_ON;
            THRMNGSERVO_bCalcCleTempo_on = 1;
            Tpac_thrust_search_cleoff_tempo =
               (uint16)MATHSRV_udtMIN(Tpac_thrust_search_cleoff_delay, 800);
            Thr_dlyKeyOn = (uint8)MATHSRV_udtMIN(Thr_dlyKeyOn_C, 100);
         }
         else
         {
            /* on reste à l'état Clef_off */
            if (Tpac_thrust_search_cleoff_tempo > 0)
            {
               Tpac_thrust_search_cleoff_tempo =
                  (uint16)(Tpac_thrust_search_cleoff_tempo - 1);
            }
         }
      break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         THRMNGSERVO_stCalcTempoCleoff = CLEF_ON;
         THRMNGSERVO_bCalcCleTempo_on = 1;
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidManagerTransition                           */
/* !Description :  Partie de contrôle de l'automate des transitions           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRMNGSERVO_vidTransWaitForAdc();                        */
/*  extf argret void THRMNGSERVO_vidTransMcwInhibTest();                      */
/*  extf argret void THRMNGSERVO_vidTransRestorMobil();                       */
/*  extf argret void THRMNGSERVO_vidTransControl();                           */
/*  extf argret void THRMNGSERVO_vidTransHighThSearch();                      */
/*  extf argret void THRMNGSERVO_vidTransClosingRamp();                       */
/*  extf argret void THRMNGSERVO_vidTransExitLowThrus();                      */
/*  extf argret void THRMNGSERVO_vidTransLimpHome();                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  output st01 Tpac_throttle_control_state;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidManagerTransition(void)
{
   uint8 u8LocalTpacThrottleControlState;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);
   switch(u8LocalTpacThrottleControlState)
   {
      case TPAC_WAIT_FOR_ADC:
         THRMNGSERVO_vidTransWaitForAdc();
         break;

      case TPAC_MCW_INHIBIT_TEST:
         THRMNGSERVO_vidTransMcwInhibTest();
         break;

      case TPAC_RESTOR_MOBILITY:
         THRMNGSERVO_vidTransRestorMobil();
         break;

      case TPAC_CONTROL:
         THRMNGSERVO_vidTransControl();
         break;

      case TPAC_HIGH_THRUST_SEARCH:
         THRMNGSERVO_vidTransHighThSearch();
         break;

      case TPAC_CLOSING_RAMP:
         THRMNGSERVO_vidTransClosingRamp();
         break;

      case TPAC_EXIT_LOW_THRUST:
         THRMNGSERVO_vidTransExitLowThrus();
         break;

      case TPAC_LIMP_HOME:
         THRMNGSERVO_vidTransLimpHome();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_WAIT_FOR_ADC);
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidManagerTreatment                            */
/* !Description :  Partie de contrôle de l'automate des traitements           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRMNGSERVO_vidTreatHighThSearch();                      */
/*  extf argret void THRMNGSERVO_vidTreatClosingRamp();                       */
/*  extf argret void THRMNGSERVO_vidTreatExitLowThrus();                      */
/*  extf argret void THRMNGSERVO_vidTreatLimpHome();                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean THRMNGSERVO_bTpacLimpHomeFlag;                              */
/*  output st01 Tpac_throttle_control_state;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidManagerTreatment(void)
{
   uint8 u8LocalTpacThrottleControlState;


   VEMS_vidGET(Tpac_throttle_control_state,u8LocalTpacThrottleControlState);
   switch(u8LocalTpacThrottleControlState)
   {
      case TPAC_WAIT_FOR_ADC:
      case TPAC_MCW_INHIBIT_TEST:
      case TPAC_RESTOR_MOBILITY:
      case TPAC_CONTROL:
         break;

      case TPAC_HIGH_THRUST_SEARCH:
         THRMNGSERVO_vidTreatHighThSearch();
         break;

      case TPAC_CLOSING_RAMP:
         THRMNGSERVO_vidTreatClosingRamp();
         break;

      case TPAC_EXIT_LOW_THRUST:
         THRMNGSERVO_vidTreatExitLowThrus();
         break;

      case TPAC_LIMP_HOME:
         if (THRMNGSERVO_bTpacLimpHomeFlag !=0)
         {
            THRMNGSERVO_vidTreatLimpHome();
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(Tpac_throttle_control_state, TPAC_WAIT_FOR_ADC);
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidThrServoInh                                 */
/* !Description :  Control: Dans cet état, Thr_bInhMngThrServo est calculé. Il*/
/*                 regroupe FRM_bInhMngThrServo et L’état d’automate de la    */
/*                 position papillon.                                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st21 Ssm_throttle_pos_sensing_status;                               */
/*  output boolean Thr_bInhMngThrServo;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidThrServoInh(void)
{
   boolean bLocalInhMngThrStopLrn;
   boolean bLocalThr_bInhMngThrServo;
   uint8   u8LocalSsmThrottlePosSensingStat;


   bLocalInhMngThrStopLrn = GDGAR_bGetFRM (FRM_FRM_INHMNGTHRSERVO);
   VEMS_vidGET(Ssm_throttle_pos_sensing_status,
               u8LocalSsmThrottlePosSensingStat);
   if (  (bLocalInhMngThrStopLrn != 0)
      || (u8LocalSsmThrottlePosSensingStat == SSM_THROTTLE_POS_FAILURE))
   {
      bLocalThr_bInhMngThrServo = 1;
   }
   else
   {
      bLocalThr_bInhMngThrServo = 0;
   }
   VEMS_vidSET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidCalInhibInjection                           */
/* !Description :  Le manager du Thr a la posibilité d’inhiber l’injection    */
/*                 lors de sa procédure d’apprentissage à l’init.             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bStopsLrnInProgs;                                       */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  output boolean Thr_bInhInjMngServo;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidCalInhibInjection(void)
{
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bStopsLrnInProgs;


   VEMS_vidGET(Thr_bStopsLrnInProgs, bLocalThr_bStopsLrnInProgs);
   VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);

   if (  (bLocalThr_bStopsLrnInProgs != 0)
      && (bLocalThr_bRstStopsLrnReq != 0) )
   {
      VEMS_vidSET(Thr_bInhInjMngServo, 1);
   }
   else
   {
      VEMS_vidSET(Thr_bInhInjMngServo, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRMNGSERVO_vidSrvTran                                     */
/* !Description :  Ce bloc permet de gérer la transition d’inhibition vers    */
/*                 réhabilitation par les routines du  papillon motorisé via  */
/*                 un booléen passant à 1 lors de la descente du flag         */
/*                 d’inhibition si les conditions sont réunies                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Srv_bInhThr;                                                */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean THRMNGSERVO_bSrv_bInhThrPrev;                               */
/*  output boolean Thr_bInhThrFallTran;                                       */
/*  output boolean THRMNGSERVO_bSrv_bInhThrPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMNGSERVO_vidSrvTran(void)
{
   boolean bLocalSrv_bInhThr;
   boolean bLocalThr_bInhMngThrServo;

   VEMS_vidGET(Srv_bInhThr, bLocalSrv_bInhThr);
   VEMS_vidGET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);

   if (  (THRMNGSERVO_bSrv_bInhThrPrev != 0)
      && (bLocalSrv_bInhThr == 0)
      && (bLocalThr_bInhMngThrServo == 0))
   {
      Thr_bInhThrFallTran = 1;
   }
   else
   {
      Thr_bInhThrFallTran = 0;
   }
   THRMNGSERVO_bSrv_bInhThrPrev = bLocalSrv_bInhThr;
}
/*------------------------------- end of file --------------------------------*/
