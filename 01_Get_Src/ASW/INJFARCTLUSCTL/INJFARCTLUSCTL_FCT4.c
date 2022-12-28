/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLUSCTL                                          */
/* !Description     : INJFARCTLUSCTL component                                */
/*                                                                            */
/* !Module          : INJFARCTLUSCTL                                          */
/* !Description     : CALCUL DE LA BOUCLE FERMEE DE LA REGULATION DE RICHESSE */
/*                    AVEC SONDE AMONT                                        */
/*                                                                            */
/* !File            : INJFARCTLUSCTL_FCT4.c                                   */
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
/*   1 / INJFARCTLUSCTL_vidFFastTracking                                      */
/*   2 / INJFARCTLUSCTL_vidMgtFeedCalc                                        */
/*   3 / INJFARCTLUSCTL_vidCalcLump                                           */
/*   4 / INJFARCTLUSCTL_vidLumpOnIdle                                         */
/*   5 / INJFARCTLUSCTL_vidLumpNotOnIdle                                      */
/*   6 / INJFARCTLUSCTL_vidSetlbdFltMdDly                                     */
/*   7 / INJFARCTLUSCTL_vidSetlbdSlwMdDly                                     */
/*   8 / INJFARCTLUSCTL_vidInitFeedCalc                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5215083 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJFARCTLUSCTL/INJFARC$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   18 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   18 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "INJFARCTLUSCTL.H"
#include "INJFARCTLUSCTL_L.H"
#include "INJFARCTLUSCTL_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidFFastTracking                            */
/* !Description :  Indicateur d' enclenchement du Fast Tracking               */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean ;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Cat_mon_inhibe_fast_tracking;                               */
/*  input boolean E_monitor_up_stream_oxy_sensor;                             */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Lambda_slow_mode_delay;                                       */
/*  input uint8 Fast_tracking_water_temp_thresh;                              */
/*  output boolean Fast_traking_ok;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidFFastTracking(void)
{
   boolean bLocalINHINJFARCTLUSCTLFASTTRK;
   boolean bLocalCatMonInhibeFastTracking;
   boolean bLocalEMonitorUpStreamOxySensor;
   uint8   u8LocalTemperature_eau;


   bLocalINHINJFARCTLUSCTLFASTTRK =
      GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLUSCTLFASTTRK);
   VEMS_vidGET(Cat_mon_inhibe_fast_tracking, bLocalCatMonInhibeFastTracking);
   VEMS_vidGET(E_monitor_up_stream_oxy_sensor, bLocalEMonitorUpStreamOxySensor);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   if (  (Lambda_slow_mode_delay == 0)
      && (u8LocalTemperature_eau >= Fast_tracking_water_temp_thresh)
      && (bLocalCatMonInhibeFastTracking == 0)
      && (bLocalEMonitorUpStreamOxySensor == 0)
      && (bLocalINHINJFARCTLUSCTLFASTTRK == 0)
      )
   {
      Fast_traking_ok = 1;
   }
   else
   {
      Fast_traking_ok = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidMgtFeedCalc                              */
/* !Description :  Automate de calcul de la boucle fermée de  richesse .      */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLUSCTL_vidSetlbdSlwMdDly();                      */
/*  extf argret void INJFARCTLUSCTL_vidSetlbdFltMdDly();                      */
/*  extf argret void INJFARCTLUSCTL_vidCalcStep();                            */
/*  extf argret void INJFARCTLUSCTL_vidCalcLump();                            */
/*  extf argret void INJFARCTLUSCTL_vidSetTransfCount();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st26 Feedback_calculations_state;                                   */
/*  input boolean Sonde_riche_amont;                                          */
/*  input uint8 Transfer_count;                                               */
/*  input boolean Lambda_slow_mode;                                           */
/*  input sint16 Lambda_feedback;                                             */
/*  input boolean Fast_traking_ok;                                            */
/*  output st26 Feedback_calculations_state;                                  */
/*  output boolean Lambda_slow_mode;                                          */
/*  output sint16 Lambda_feedback_min;                                        */
/*  output boolean Lambda_feedback_min_calc;                                  */
/*  output boolean InjCtl_bUpdlamMin;                                         */
/*  output sint16 Lambda_feedback_max;                                        */
/*  output boolean Lambda_feedback_max_calc;                                  */
/*  output boolean InjCtl_bUpdlamMax;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidMgtFeedCalc(void)
{
   boolean bLocalLambda_slow_mode;
   boolean bLocalSonde_riche_amont;
   sint16  s16LocalLambda_feedback;
   uint8   u8LocalFeedbackCalculationsState;


   VEMS_vidGET(Feedback_calculations_state, u8LocalFeedbackCalculationsState);
   VEMS_vidGET(Sonde_riche_amont, bLocalSonde_riche_amont);

   switch(u8LocalFeedbackCalculationsState)
   {
      case FEEDBACK_CLOSED_LOOP_INIT:
         if (bLocalSonde_riche_amont == 0)
         {
            VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_LEAN);
         }
         else
         {
            VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_RICH);
         }
         INJFARCTLUSCTL_vidSetlbdSlwMdDly();
         INJFARCTLUSCTL_vidSetlbdFltMdDly();
         break;

      case FEEDBACK_MOVING_LEAN_TO_RICH:
         if (bLocalSonde_riche_amont == 0)
         {
            VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_LEAN);
            INJFARCTLUSCTL_vidCalcStep();
         }
         else
         {
            if (Transfer_count == 0)
            {
               VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_RICH);
               INJFARCTLUSCTL_vidCalcLump();
               VEMS_vidSET(Lambda_slow_mode, 1);
               INJFARCTLUSCTL_vidSetlbdSlwMdDly();
            }
            else
            {
               INJFARCTLUSCTL_vidCalcStep();
            }
         }
         break;

      case FEEDBACK_MOVING_RICH_TO_LEAN:
         if (bLocalSonde_riche_amont != 0)
         {
            VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_RICH);
            INJFARCTLUSCTL_vidCalcStep();
         }
         else
         {
            if (Transfer_count == 0)
            {
               VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_LEAN);
               INJFARCTLUSCTL_vidCalcLump();
               VEMS_vidSET(Lambda_slow_mode, 1);
               INJFARCTLUSCTL_vidSetlbdSlwMdDly();
            }
            else
            {
               INJFARCTLUSCTL_vidCalcStep();
            }
         }
         break;

      case FEEDBACK_SYSTEM_RICH:
         if ( bLocalSonde_riche_amont == 0 )
         {
            VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);
            if ( bLocalLambda_slow_mode != 0 )
            {
               VEMS_vidSET(Feedback_calculations_state,
                           FEEDBACK_MOVING_RICH_TO_LEAN);
               VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
               Lambda_feedback_min = s16LocalLambda_feedback;
               Lambda_feedback_min_calc = 1;
               InjCtl_bUpdlamMin = 1;
               INJFARCTLUSCTL_vidSetTransfCount();
               INJFARCTLUSCTL_vidCalcStep();
            }
            else
            {
               VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_LEAN);
               INJFARCTLUSCTL_vidCalcLump();
               VEMS_vidSET(Lambda_slow_mode, 1);
               INJFARCTLUSCTL_vidSetlbdSlwMdDly();
            }
         }
         else
         {
            if (Fast_traking_ok != 0)
            {
               VEMS_vidSET(Lambda_slow_mode, 0);
            }
            INJFARCTLUSCTL_vidCalcStep();
         }
         break;

      case FEEDBACK_SYSTEM_LEAN:
         VEMS_vidGET(Sonde_riche_amont, bLocalSonde_riche_amont);
         if (bLocalSonde_riche_amont != 0)
         {
            VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);
            if (bLocalLambda_slow_mode != 0)
            {
               VEMS_vidSET(Feedback_calculations_state,
                           FEEDBACK_MOVING_LEAN_TO_RICH);
               VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
               Lambda_feedback_max = s16LocalLambda_feedback;
               Lambda_feedback_max_calc = 1;
               InjCtl_bUpdlamMax = 1;
               INJFARCTLUSCTL_vidSetTransfCount();
               INJFARCTLUSCTL_vidCalcStep();
            }
            else
            {
               VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_RICH);
               INJFARCTLUSCTL_vidCalcLump();
               VEMS_vidSET(Lambda_slow_mode, 1);
               INJFARCTLUSCTL_vidSetlbdSlwMdDly();
            }
         }
         else
         {
            if (Fast_traking_ok != 0)
            {
               VEMS_vidSET(Lambda_slow_mode, 0);
            }
            INJFARCTLUSCTL_vidCalcStep();
         }
         break;

      default:
         VEMS_vidSET(Feedback_calculations_state, FEEDBACK_CLOSED_LOOP_INIT);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalcLump                                 */
/* !Description :  Ce processus calcule les sauts de richesse qui sont        */
/*                 appliqués par le processus Calculer Lambda Feedback. Il est*/
/*                 déclenché par l' automate de gestion de poursuite de       */
/*                 richesse sur certaines transitions.                        */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidLumpOnIdle();                          */
/*  extf argret void INJFARCTLUSCTL_vidLumpNotOnIdle();                       */
/*  input st07 Engine_running_state;                                          */
/*  output boolean Lambda_waiting;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalcLump(void)
{
   uint8 u8LocalEngine_running_state;


   Lambda_waiting = 1;
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if (u8LocalEngine_running_state == ERUN_ON_IDLE)
   {
      INJFARCTLUSCTL_vidLumpOnIdle();
   }
   else
   {
      INJFARCTLUSCTL_vidLumpNotOnIdle();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLumpOnIdle                               */
/* !Description :  L'appel de cette fonction est effectuée si l'etat de       */
/*                 fonctionnement du moteur prend l'etat ralenti de l'        */
/*                 automate Engine_running_state.                             */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Cf_bInhFlex;                                                */
/*  input uint8 Lambda_lump_lean_idle;                                        */
/*  input uint8 Lambda_large_lump_lean_idle;                                  */
/*  input uint8 Lambda_lump_rich_idle;                                        */
/*  input uint8 Lambda_large_lump_rich_idle;                                  */
/*  input uint8 Lbda_lump_lean_idle_flex;                                     */
/*  input uint8 Lbda_lg_lump_lean_idle_flex;                                  */
/*  input uint8 Lbda_lump_rich_idle_flex;                                     */
/*  input uint8 Lbda_lg_lump_rich_idle_flex;                                  */
/*  input st26 Feedback_calculations_state;                                   */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint8 Lbda_lump_lean_gain;                                          */
/*  input uint8 Lbda_lump_rich_gain;                                          */
/*  output uint16 Lambda_feedback_lump;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLumpOnIdle(void)
{
   boolean bLocalLambda_slow_mode;
   boolean bLocalCf_bInhFlex;
   uint8   u8LocalFeedbackCalculationsState;
   uint8   u8LocalMux1;
   uint8   u8LocalMux2;
   uint8   u8LocalMux3;
   uint8   u8LocalMux4;


   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);

   if (bLocalCf_bInhFlex != 0)
   {
      u8LocalMux1 = Lambda_lump_lean_idle;
      u8LocalMux2 = Lambda_large_lump_lean_idle;
      u8LocalMux3 = Lambda_lump_rich_idle;
      u8LocalMux4 = Lambda_large_lump_rich_idle;
   }
   else
   {
      VEMS_vidGET(Lbda_lump_lean_idle_flex, u8LocalMux1);
      VEMS_vidGET(Lbda_lg_lump_lean_idle_flex, u8LocalMux2);
      VEMS_vidGET(Lbda_lump_rich_idle_flex, u8LocalMux3);
      VEMS_vidGET(Lbda_lg_lump_rich_idle_flex, u8LocalMux4);
   }

   VEMS_vidGET(Feedback_calculations_state, u8LocalFeedbackCalculationsState);
   if (u8LocalFeedbackCalculationsState == FEEDBACK_SYSTEM_LEAN)
   {
      VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);
      if (bLocalLambda_slow_mode != 0)
      {
         Lambda_feedback_lump = (uint16)( ( u8LocalMux1
                                          * Lbda_lump_lean_gain)
                                        / 2);
      }
      else
      {
         Lambda_feedback_lump = (uint16) (u8LocalMux2 * 256);
      }
   }
   else
   {
      VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);
      if ( bLocalLambda_slow_mode != 0 )
      {
         Lambda_feedback_lump = (uint16)( ( u8LocalMux3
                                          * Lbda_lump_rich_gain)
                                        / 2);
      }
      else
      {
         Lambda_feedback_lump = (uint16)(u8LocalMux4 * 256);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLumpNotOnIdle                            */
/* !Description :  L'appel de cette fonction est effectuée si l'etat de       */
/*                 fonctionnement du moteur prend un état différent de l'etat */
/*                 ralenti de l' automate Engine_running_state.               */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Engine_load;                                                 */
/*  input uint16 Engine_load_InjCtl_bkpt_map[9];                              */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_moteur_InjCtl_bkpt_map[9];                             */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint16 Lbda_lump_non_idle_pond_flex;                                */
/*  input boolean Cf_bInhFlex;                                                */
/*  input st26 Feedback_calculations_state;                                   */
/*  input uint8 Lambda_lump_lean_non_idle_map[9][9];                          */
/*  input uint8 Lbda_lump_lean_non_idle_flex;                                 */
/*  input uint8 Lbda_lump_lean_gain;                                          */
/*  input uint8 Lambda_lump_rich_non_idle_map[9][9];                          */
/*  input uint8 Lbda_lump_rich_non_idle_flex;                                 */
/*  input uint8 Lbda_lump_rich_gain;                                          */
/*  input uint8 Lambda_large_lump_non_idle_map[9];                            */
/*  input uint8 Lbda_lg_lump_non_idle_flex;                                   */
/*  output uint16 Lambda_feedback_lump;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLumpNotOnIdle(void)
{
   boolean bLocalLambda_slow_mode;
   boolean bLocalCf_bInhFlex;
   uint8   u8Localinterp1;
   uint8   u8Localinterp2;
   uint8   u8Localinterp3;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalFeedbackCalculationsState;
   uint8   u8LocalLbdaLumpLeanNonIdleFlex;
   uint8   u8LocalLbdaLumpRichNonIdleFlex;
   uint8   u8LocalLbdaLgLumpNonIdleFlex;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalEngine_load;
   uint16  u16LocalLbdLumpNonIdlePondFlex;
   uint16  u16LocalRate;
   sint16  s16LocalCalc;
   sint32  s32LocalCalc;


   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Engine_load_InjCtl_bkpt_map,
                                                u16LocalEngine_load,
                                                9 );
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_InjCtl_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);
   VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);
   VEMS_vidGET(Lbda_lump_non_idle_pond_flex,u16LocalLbdLumpNonIdlePondFlex);
   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
   if (bLocalLambda_slow_mode != 0)
   {
      VEMS_vidGET(Feedback_calculations_state,
                  u8LocalFeedbackCalculationsState);
      if (u8LocalFeedbackCalculationsState == FEEDBACK_SYSTEM_LEAN)
      {
         u8Localinterp1 = MATHSRV_u8Interp2d(Lambda_lump_lean_non_idle_map[0],
                                             u16LocalParaX,
                                             u16LocalParaY,
                                             9);

         if (bLocalCf_bInhFlex == 0)
         {
            /*Barycentre 2*/
            VEMS_vidGET(Lbda_lump_lean_non_idle_flex,
                        u8LocalLbdaLumpLeanNonIdleFlex);

            s16LocalCalc =
               (sint16)(u8LocalLbdaLumpLeanNonIdleFlex - u8Localinterp1);
            u16LocalRate =
               (uint16)MATHSRV_udtMIN(u16LocalLbdLumpNonIdlePondFlex, 256);
            if (s16LocalCalc >= 0)
            {
               s32LocalCalc =
                  ((s16LocalCalc * u16LocalRate) + (256 * u8Localinterp1));
               s32LocalCalc = ( (s32LocalCalc * Lbda_lump_lean_gain) + 256)
                              / 512;
            }
            else
            {
               s32LocalCalc =
                  ((s16LocalCalc * u16LocalRate) + (256 * u8Localinterp1));
               s32LocalCalc = ( (s32LocalCalc * Lbda_lump_lean_gain) - 256)
                              / 512;
            }
            Lambda_feedback_lump = (uint16)s32LocalCalc;
         }
         else
         {
            Lambda_feedback_lump =
               (uint16)((u8Localinterp1 * Lbda_lump_lean_gain) / 2);
         }
      }
      else
      {
         u8Localinterp2 = MATHSRV_u8Interp2d(Lambda_lump_rich_non_idle_map[0],
                                             u16LocalParaX,
                                             u16LocalParaY,
                                             9);
         if (bLocalCf_bInhFlex == 0)
         {
         /*Barycentre 1*/
            VEMS_vidGET(Lbda_lump_rich_non_idle_flex,
              u8LocalLbdaLumpRichNonIdleFlex);

            s16LocalCalc =
               (sint16)(u8LocalLbdaLumpRichNonIdleFlex - u8Localinterp2);
            u16LocalRate =
               (uint16)MATHSRV_udtMIN(u16LocalLbdLumpNonIdlePondFlex, 256);
            if (s16LocalCalc >= 0)
            {
               s32LocalCalc =
                  ((s16LocalCalc * u16LocalRate) + (256 * u8Localinterp2));
               s32LocalCalc = ( (s32LocalCalc * Lbda_lump_rich_gain) + 256)
                              / 512;
            }
            else
            {
               s32LocalCalc =
                  ((s16LocalCalc * u16LocalRate) + (256 * u8Localinterp2));
               s32LocalCalc = ( (s32LocalCalc * Lbda_lump_rich_gain) - 256)
                              / 512;
            }
            Lambda_feedback_lump = (uint16)s32LocalCalc;
         }
         else
         {
            Lambda_feedback_lump =
               (uint16)((u8Localinterp2 * Lbda_lump_rich_gain ) / 2);
         }
      }
   }
   else
   {
      u8Localinterp3 =
         MATHSRV_u8Interp1d( Lambda_large_lump_non_idle_map,u16LocalParaY );
      if (bLocalCf_bInhFlex == 0)
      {
      /*Barycentre 3*/
      VEMS_vidGET(Lbda_lg_lump_non_idle_flex, u8LocalLbdaLgLumpNonIdleFlex);

         s16LocalCalc =
            (sint16)(u8LocalLbdaLgLumpNonIdleFlex - u8Localinterp3);
         u16LocalRate =
            (uint16)MATHSRV_udtMIN(u16LocalLbdLumpNonIdlePondFlex, 256);
         s32LocalCalc =
           ((s16LocalCalc * u16LocalRate) + (256 * u8Localinterp3));
         Lambda_feedback_lump = (uint16)s32LocalCalc;
      }
      else
      {
         Lambda_feedback_lump = (uint16)(u8Localinterp3 * 256);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidSetlbdFltMdDly                           */
/* !Description :  Cette fonction permet de déterminer le délai avant filtrage*/
/*                 du Lambda_feedback en mode  rapide.                        */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Lambda_filt_fdbk_mode_delay_idle;                             */
/*  input uint16 Engine_load;                                                 */
/*  input uint16 Engine_load_bkpt_map[16];                                    */
/*  input uint8 Lambda_filt_fdbk_mode_delay_map[16];                          */
/*  output uint8 Lambda_filtered_fdbk_mode_delay;                             */
/*  output uint8 Lambda_filt_fdbk_mode_delay_idle;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidSetlbdFltMdDly(void)
{
   uint8  u8LocalEngine_running_state;
   uint8  u8LocalLambdaFilteredFbModeDelay;
   uint16 u16LocalPara;
   uint16 u16LocalEngine_load;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if (u8LocalEngine_running_state == ERUN_ON_IDLE)
   {
      VEMS_vidSET(Lambda_filtered_fdbk_mode_delay,
                  Lambda_filt_fdbk_mode_delay_idle);
   }
   else
   {
      VEMS_vidGET(Engine_load, u16LocalEngine_load);
      u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Engine_load_bkpt_map,
                                                  u16LocalEngine_load,
                                                  16 );
      u8LocalLambdaFilteredFbModeDelay =
         MATHSRV_u8Interp1d(Lambda_filt_fdbk_mode_delay_map, u16LocalPara );

      VEMS_vidSET(Lambda_filtered_fdbk_mode_delay,
                  u8LocalLambdaFilteredFbModeDelay);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidSetlbdSlwMdDly                           */
/* !Description :  Cette fonction permet de déterminer la durée maximum de la */
/*                 poursuite lente.                                           */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Lambda_slow_mode_delay_idle;                                  */
/*  input uint16 Engine_load;                                                 */
/*  input uint16 Engine_load_bkpt_map[16];                                    */
/*  input uint8 Lambda_slow_mode_delay_map[16];                               */
/*  output uint8 Lambda_slow_mode_delay;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidSetlbdSlwMdDly(void)
{
   uint8  u8LocalEngine_running_state;
   uint16 u16LocalPara;
   uint16 u16LocalEngine_load;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if (u8LocalEngine_running_state == ERUN_ON_IDLE)
   {
      Lambda_slow_mode_delay = Lambda_slow_mode_delay_idle;
   }
   else
   {
      VEMS_vidGET(Engine_load, u16LocalEngine_load);
      u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Engine_load_bkpt_map,
                                                  u16LocalEngine_load,
                                                  16 );
      Lambda_slow_mode_delay = MATHSRV_u8Interp1d(Lambda_slow_mode_delay_map,
                                                  u16LocalPara );
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidInitFeedCalc                             */
/* !Description :  Fonction d'initialisation du calcul du bouclage            */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidSetlbdSlwMdDly();                      */
/*  extf argret void INJFARCTLUSCTL_vidSetlbdFltMdDly();                      */
/*  input boolean Sonde_riche_amont;                                          */
/*  output boolean Lambda_slow_mode;                                          */
/*  output st26 Feedback_calculations_state;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidInitFeedCalc(void)
{
   boolean bLocalSonde_riche_amont;


   VEMS_vidSET(Lambda_slow_mode, 1);
   VEMS_vidGET(Sonde_riche_amont, bLocalSonde_riche_amont);
   if ( bLocalSonde_riche_amont == 0)
   {
      VEMS_vidSET(Feedback_calculations_state,  FEEDBACK_SYSTEM_LEAN);
   }
   else
   {
      VEMS_vidSET(Feedback_calculations_state, FEEDBACK_SYSTEM_RICH);
   }
   INJFARCTLUSCTL_vidSetlbdSlwMdDly();
   INJFARCTLUSCTL_vidSetlbdFltMdDly();
}
/*------------------------------- end of file --------------------------------*/