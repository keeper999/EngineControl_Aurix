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
/* !File            : INJFARCTLUSCTL_FCT5.c                                   */
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
/*   1 / INJFARCTLUSCTL_vidCalcStep                                           */
/*   2 / INJFARCTLUSCTL_vidStepOnIdle                                         */
/*   3 / INJFARCTLUSCTL_vidStepNotOnIdle                                      */
/*   4 / INJFARCTLUSCTL_vidSetTransfCount                                     */
/*   5 / INJFARCTLUSCTL_vidTrsfCtOnIdle                                       */
/*   6 / INJFARCTLUSCTL_vidTrsfCtNtOnIdle                                     */
/*   7 / INJFARCTLUSCTL_vidTrsfCttimescal                                     */
/*   8 / INJFARCTLUSCTL_vidFuncCtlFdInjAc                                     */
/*   9 / INJFARCTLUSCTL_vidControlEna                                         */
/*   10 / INJFARCTLUSCTL_vidDecCounter                                        */
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
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalcStep                                 */
/* !Description :  La régulation de richesse fonctionne suivant 2 modes de    */
/*                 poursuite, lent et rapide. Ce mode de poursuite est donné  */
/*                 par l' automate Feedback_calculations_state.               */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidStepOnIdle();                          */
/*  extf argret void INJFARCTLUSCTL_vidStepNotOnIdle();                       */
/*  input st07 Engine_running_state;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalcStep(void)
{
   uint8 u8LocalEngine_running_state;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if (u8LocalEngine_running_state == ERUN_ON_IDLE)
   {
      INJFARCTLUSCTL_vidStepOnIdle();
   }
   else
   {
      INJFARCTLUSCTL_vidStepNotOnIdle();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidStepOnIdle                               */
/* !Description :  L'appel de cette fonction est effectuée si l'etat de       */
/*                 fonctionnement du moteur prend l'etat ralenti de l'        */
/*                 automate Engine_running_state.                             */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st26 Feedback_calculations_state;                                   */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint8 Lambda_step_lean_idle;                                        */
/*  input uint8 Lbda_step_lean_gain;                                          */
/*  input uint8 Lambda_large_step_lean_idle;                                  */
/*  input uint8 Lambda_step_rich_idle;                                        */
/*  input uint8 Lbda_step_rich_gain;                                          */
/*  input uint8 Lambda_large_step_rich_idle;                                  */
/*  output uint16 Lambda_feedback_step;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidStepOnIdle(void)
{
   boolean bLocalLambda_slow_mode;
   uint8   u8LocalFeedbackCalculationsState;


   VEMS_vidGET(Feedback_calculations_state, u8LocalFeedbackCalculationsState);
   if (  (u8LocalFeedbackCalculationsState == FEEDBACK_SYSTEM_LEAN)
      || (u8LocalFeedbackCalculationsState == FEEDBACK_MOVING_LEAN_TO_RICH))
   {
      VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);
      if (bLocalLambda_slow_mode != 0)
      {
         Lambda_feedback_step = (uint16)( ( 2 * Lambda_step_lean_idle
                                          * Lbda_step_lean_gain)
                                        / 125);
      }
      else
      {
         Lambda_feedback_step = (uint16)(Lambda_large_step_lean_idle * 8);
      }
   }
   else
   {
      VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);
      if (bLocalLambda_slow_mode != 0)
      {
         Lambda_feedback_step = (uint16)( ( 2 * Lambda_step_rich_idle
                                          * Lbda_step_rich_gain)
                                        / 125);
      }
      else
      {
         Lambda_feedback_step = (uint16)(Lambda_large_step_rich_idle * 8);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidStepNotOnIdle                            */
/* !Description :  L'appel de cette fonction est effectuée si l'etat de       */
/*                 fonctionnement du moteur prend un état différent de l'etat */
/*                 ralenti de l' automate Engine_running_state.               */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Engine_load;                                                 */
/*  input uint16 Engine_load_InjCtl_bkpt_map[9];                              */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_moteur_InjCtl_bkpt_map[9];                             */
/*  input st26 Feedback_calculations_state;                                   */
/*  input uint16 Lbda_step_non_idle_pond_flex;                                */
/*  input boolean Cf_bInhFlex;                                                */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint8 Lambda_step_lean_non_idle_map[9][9];                          */
/*  input uint8 Lbda_step_lean_non_idle_flex;                                 */
/*  input uint8 Lbda_step_lean_gain;                                          */
/*  input uint8 Lambda_l_step_lean_non_idle_map[9];                           */
/*  input uint8 Lambda_step_rich_non_idle_map[9][9];                          */
/*  input uint8 Lbda_step_rich_non_idle_flex;                                 */
/*  input uint8 Lbda_step_rich_gain;                                          */
/*  input uint8 Lambda_l_step_rich_non_idle_map[9];                           */
/*  output uint16 Lambda_feedback_step;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidStepNotOnIdle(void)
{
   boolean bLocalLambda_slow_mode;
   boolean bLocalCf_bInhFlex;
   uint8   u8Localinterp1;
   uint8   u8Localinterp2;
   uint8   u8Localinterp3;
   uint8   u8Localinterp4;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalFeedbackCalculationsState;
   uint8   u8LocalLbdaStepRichNonIdleFlex;
   uint8   u8LocalLbdaStepLeanNonIdleFlex;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalEngine_load;
   uint16  u16LocalRate;
   uint16  u16LocalLbdaStepNonIdlePondFlex;
   uint32  u32LocalCalc;
   sint32  s32LocalCalc;


   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Engine_load_InjCtl_bkpt_map,
                                                u16LocalEngine_load,
                                                9);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_InjCtl_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);
   VEMS_vidGET(Feedback_calculations_state, u8LocalFeedbackCalculationsState);
   VEMS_vidGET(Lbda_step_non_idle_pond_flex, u16LocalLbdaStepNonIdlePondFlex);
   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
   VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);

   if (  (u8LocalFeedbackCalculationsState == FEEDBACK_SYSTEM_LEAN )
      || (u8LocalFeedbackCalculationsState == FEEDBACK_MOVING_LEAN_TO_RICH))
   {
      if (bLocalLambda_slow_mode != 0)
      {
         u8Localinterp1 =
            MATHSRV_u8Interp2d(Lambda_step_lean_non_idle_map[0],
                               u16LocalParaX,
                               u16LocalParaY,
                               9);

         if (bLocalCf_bInhFlex == 0)
         {
            /*Barycentre 2*/
            VEMS_vidGET(Lbda_step_lean_non_idle_flex,
               u8LocalLbdaStepLeanNonIdleFlex);

            s32LocalCalc =
               (sint32)(u8LocalLbdaStepLeanNonIdleFlex - u8Localinterp1);
            u16LocalRate =
               (uint16)MATHSRV_udtMIN(u16LocalLbdaStepNonIdlePondFlex, 256);
            if (s32LocalCalc >= 0)
            {
               s32LocalCalc = ((s32LocalCalc * u16LocalRate) + 128) / 256;
            }
            else
            {
               s32LocalCalc = ((s32LocalCalc * u16LocalRate) - 128) / 256;
            }
            u8Localinterp1 = (uint8)(s32LocalCalc + u8Localinterp1);
         }
         u32LocalCalc = (uint32)(2 * u8Localinterp1 * Lbda_step_lean_gain);
         Lambda_feedback_step = (uint16)(u32LocalCalc / 125);
      }
      else
      {
         u8Localinterp2 = MATHSRV_u8Interp1d(Lambda_l_step_lean_non_idle_map,
                                             u16LocalParaY );
         Lambda_feedback_step = (uint16)(u8Localinterp2 * 8);
      }
   }
   else
   {
      if (bLocalLambda_slow_mode != 0)
      {
         u8Localinterp3 = MATHSRV_u8Interp2d(Lambda_step_rich_non_idle_map[0],
                                             u16LocalParaX,
                                             u16LocalParaY,
                                             9);

         if (bLocalCf_bInhFlex == 0)
         {
            /*Barycentre 1*/
            VEMS_vidGET(Lbda_step_rich_non_idle_flex,
                        u8LocalLbdaStepRichNonIdleFlex);

            s32LocalCalc =
               (sint32)(u8LocalLbdaStepRichNonIdleFlex - u8Localinterp3);
            u16LocalRate =
               (uint16)MATHSRV_udtMIN(u16LocalLbdaStepNonIdlePondFlex, 256);
            if (s32LocalCalc >= 0)
            {
               s32LocalCalc = ((s32LocalCalc * u16LocalRate) + 128) / 256;
            }
            else
            {
               s32LocalCalc = ((s32LocalCalc * u16LocalRate) - 128) / 256;
            }
            u8Localinterp3 = (uint8)(s32LocalCalc + u8Localinterp3);
         }
         u32LocalCalc = (uint32)(2 * u8Localinterp3 * Lbda_step_rich_gain);
         Lambda_feedback_step = (uint16)(u32LocalCalc / 125);
      }
      else
      {
         u8Localinterp4 = MATHSRV_u8Interp1d(Lambda_l_step_rich_non_idle_map,
                                             u16LocalParaY);
         Lambda_feedback_step = (uint16)(u8Localinterp4 * 8);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidSetTransfCount                           */
/* !Description :  Optimisation de la fonction régulation richesse en fonction*/
/*                 du vieillissement.                                         */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05829_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidTrsfCtOnIdle();                        */
/*  extf argret void INJFARCTLUSCTL_vidTrsfCtNtOnIdle();                      */
/*  extf argret void INJFARCTLUSCTL_vidTrsfCttimescal();                      */
/*  input st07 Engine_running_state;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidSetTransfCount(void)
{
   uint8 u8LocalEngine_running_state;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if (u8LocalEngine_running_state == ERUN_ON_IDLE)
   {
      INJFARCTLUSCTL_vidTrsfCtOnIdle();
   }
   else
   {
      INJFARCTLUSCTL_vidTrsfCtNtOnIdle();
   }

   INJFARCTLUSCTL_vidTrsfCttimescal();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidTrsfCtOnIdle                             */
/* !Description :  L'appel de cette fonction est effectuée si l'etat de       */
/*                 fonctionnement du moteur prend l'etat ralenti de l'        */
/*                 automate Engine_running_state.                             */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st26 Feedback_calculations_state;                                   */
/*  input sint16 Delta_lam_gaz;                                               */
/*  input uint8 Dnstr_add_pmh_modifier;                                       */
/*  input boolean Test_bed_transfer_count_l_to_r;                             */
/*  input uint8 Transfer_count_l_to_r_c;                                      */
/*  input uint16 Dnstr_retard_purge_riche;                                    */
/*  input uint8 Lffc_lean_to_rich_idle_delay;                                 */
/*  input uint8 Delta_PMH_gaz;                                                */
/*  input uint8 Dnstr_substract_pmh_modifier;                                 */
/*  input boolean Test_bed_transfer_count_r_to_l;                             */
/*  input uint8 Transfer_count_r_to_l_c;                                      */
/*  input uint16 Dnstr_retard_purge_pauvre;                                   */
/*  input uint8 Lffc_rich_to_lean_idle_delay;                                 */
/*  output uint8 Transfer_count;                                              */
/*  output uint8 Dnstr_modifier_sampled;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidTrsfCtOnIdle(void)
{
   uint8  u8LocalDnstr_add_pmh_modifier;
   uint8  u8LocalDnstrSubstractPmhModifier;
   uint8  u8LocalFeedbackCalculationsState;
   uint16 u16LocalSum;
   uint16 u16LocalDnstrRetardPurgePauvre;
   uint16 u16LocalDnstRetardPurgeRiche;
   sint16 s16LocalDeltaLamGaz;


   VEMS_vidGET(Feedback_calculations_state, u8LocalFeedbackCalculationsState);
   VEMS_vidGET(Delta_lam_gaz, s16LocalDeltaLamGaz);
   if ( u8LocalFeedbackCalculationsState == FEEDBACK_MOVING_LEAN_TO_RICH )
   {
      VEMS_vidGET(Dnstr_add_pmh_modifier, u8LocalDnstr_add_pmh_modifier);
      if ( Test_bed_transfer_count_l_to_r != 0)
      {
         Transfer_count = Transfer_count_l_to_r_c;
      }
      else
      {
         VEMS_vidGET(Dnstr_retard_purge_riche, u16LocalDnstRetardPurgeRiche);
         u16LocalSum = (uint16)( Lffc_lean_to_rich_idle_delay
                               + u8LocalDnstr_add_pmh_modifier
                               + (u16LocalDnstRetardPurgeRiche / 256));
         if ( s16LocalDeltaLamGaz > 0 )
         {
            u16LocalSum = (uint16)(u16LocalSum + Delta_PMH_gaz);
         }
         Transfer_count = (uint8)MATHSRV_udtMIN(u16LocalSum, 255);
      }
      Dnstr_modifier_sampled = u8LocalDnstr_add_pmh_modifier;
   }
   else
   {
      VEMS_vidGET(Dnstr_substract_pmh_modifier,
                  u8LocalDnstrSubstractPmhModifier);
      if ( Test_bed_transfer_count_r_to_l != 0 )
      {
         Transfer_count = Transfer_count_r_to_l_c;
      }
      else
      {
         VEMS_vidGET(Dnstr_retard_purge_pauvre, u16LocalDnstrRetardPurgePauvre);
         u16LocalSum = (uint16)( Lffc_rich_to_lean_idle_delay
                               + u8LocalDnstrSubstractPmhModifier
                               + (u16LocalDnstrRetardPurgePauvre / 256));
         if ( s16LocalDeltaLamGaz < 0 )
         {
            u16LocalSum = (uint16)(u16LocalSum + Delta_PMH_gaz);
         }
         Transfer_count = (uint8)MATHSRV_udtMIN(u16LocalSum, 255);
      }
      Dnstr_modifier_sampled = u8LocalDnstrSubstractPmhModifier;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidTrsfCtNtOnIdle                           */
/* !Description :  L'appel de cette fonction est effectuée si l'etat de       */
/*                 fonctionnement du moteur prend un état différent de l'etat */
/*                 ralenti de l' automate Engine_running_state.               */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Engine_load;                                                 */
/*  input boolean Cf_bInhFlex;                                                */
/*  input uint16 Engine_load_InjCtl_bkpt_map[9];                              */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_moteur_InjCtl_bkpt_map[9];                             */
/*  input st26 Feedback_calculations_state;                                   */
/*  input sint16 Delta_lam_gaz;                                               */
/*  input uint8 Dnstr_add_pmh_modifier;                                       */
/*  input boolean Test_bed_transfer_count_l_to_r;                             */
/*  input uint8 Transfer_count_l_to_r_c;                                      */
/*  input uint8 Cat_old_gain;                                                 */
/*  input uint16 Dnstr_retard_purge_riche;                                    */
/*  input uint8 Lffc_l_r_non_idle_delay_emis_map[9][9];                       */
/*  input uint8 Lffc_l_r_non_idle_delay_neuf_map[9][9];                       */
/*  input uint8 Lffc_l_r_no_idle_dly_emis_flx;                                */
/*  input uint8 Lffc_l_r_no_idle_dly_neuf_flx;                                */
/*  input uint16 Lffc_non_idle_dly_pond_flex;                                 */
/*  input uint8 Delta_PMH_gaz;                                                */
/*  input uint8 Dnstr_substract_pmh_modifier;                                 */
/*  input boolean Test_bed_transfer_count_r_to_l;                             */
/*  input uint8 Transfer_count_r_to_l_c;                                      */
/*  input uint16 Dnstr_retard_purge_pauvre;                                   */
/*  input uint8 Lffc_r_l_non_idle_delay_emis_map[9][9];                       */
/*  input uint8 Lffc_r_l_non_idle_delay_neuf_map[9][9];                       */
/*  input uint8 Lffc_r_l_no_idle_dly_emis_flx;                                */
/*  input uint8 Lffc_r_l_no_idle_dly_neuf_flx;                                */
/*  output uint8 Transfer_count;                                              */
/*  output uint8 Dnstr_modifier_sampled;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidTrsfCtNtOnIdle(void)
{
   boolean bLocalCf_bInhFlex;
   uint8   u8Localinterp1;
   uint8   u8Localinterp2;
   uint8   u8Localinterp3;
   uint8   u8Localinterp4;
   uint8   u8LocalCat_old_gain;
   uint8   u8LocalDnstr_add_pmh_modifier;
   uint8   u8LocalDnstrSubstractPmhModifier;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalFeedbackCalculationsState;
   uint8   u8LocalLffcLrNoIdleDlyEmisFlx;
   uint8   u8LocalLffcLrNoIdleDlyNeufFlx;
   uint8   u8LocalLffcRLNoIdleDlyEmisFlx;
   uint8   u8LocalLffcRLNoIdleDlyNeufFlx;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalRate;
   uint16  u16LocalDnstrRetardPurgePauvre;
   uint16  u16LocalDnstRetardPurgeRiche;
   uint16  u16LocalEngine_load;
   uint16  u16LocalLffcNonIdleDlyPondFlex;
   sint16  s16LocalDeltaLamGaz;
   sint16  s16LocalLn1;
   sint16  s16LocalLn2;
   sint32  s32LocalSum;


   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Engine_load_InjCtl_bkpt_map,
                                                u16LocalEngine_load,
                                                9);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_InjCtl_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);
   VEMS_vidGET(Feedback_calculations_state, u8LocalFeedbackCalculationsState);
   VEMS_vidGET(Delta_lam_gaz, s16LocalDeltaLamGaz);
   if (u8LocalFeedbackCalculationsState == FEEDBACK_MOVING_LEAN_TO_RICH)
   {
      VEMS_vidGET(Delta_lam_gaz, s16LocalDeltaLamGaz);
      VEMS_vidGET(Dnstr_add_pmh_modifier, u8LocalDnstr_add_pmh_modifier);
      if (Test_bed_transfer_count_l_to_r != 0)
      {
         Transfer_count = Transfer_count_l_to_r_c;
      }
      else
      {
         VEMS_vidGET(Cat_old_gain, u8LocalCat_old_gain);
         VEMS_vidGET(Dnstr_retard_purge_riche, u16LocalDnstRetardPurgeRiche);
         u8Localinterp1 =
            MATHSRV_u8Interp2d(Lffc_l_r_non_idle_delay_emis_map[0],
                               u16LocalParaX,
                               u16LocalParaY,
                               9);
         u8Localinterp2 =
            MATHSRV_u8Interp2d(Lffc_l_r_non_idle_delay_neuf_map[0],
                               u16LocalParaX,
                               u16LocalParaY,
                               9);
         s16LocalLn2 = (sint16)( u8Localinterp1
                               + ( ( u8LocalCat_old_gain
                                   * (u8Localinterp2 -  u8Localinterp1))
                                 / 256));
         if (bLocalCf_bInhFlex != 0)
         {
            s32LocalSum = (sint32)(s16LocalLn2);
         }
         else
         {
            VEMS_vidGET(Lffc_l_r_no_idle_dly_emis_flx,
                        u8LocalLffcLrNoIdleDlyEmisFlx);
            VEMS_vidGET(Lffc_l_r_no_idle_dly_neuf_flx,
                        u8LocalLffcLrNoIdleDlyNeufFlx);
            s16LocalLn1 = (sint16)( u8LocalLffcLrNoIdleDlyEmisFlx
                                  + ( ( u8LocalCat_old_gain
                                      * ( u8LocalLffcLrNoIdleDlyNeufFlx
                                        - u8LocalLffcLrNoIdleDlyEmisFlx))
                                    / 256));
            /*Barycentre 2*/
            VEMS_vidGET(Lffc_non_idle_dly_pond_flex,
                        u16LocalLffcNonIdleDlyPondFlex);

            s32LocalSum =(sint32)(s16LocalLn1 - s16LocalLn2);
            u16LocalRate =
               (uint16)MATHSRV_udtMIN(u16LocalLffcNonIdleDlyPondFlex, 256);
            if (s32LocalSum >= 0)
            {
               s32LocalSum = ((s32LocalSum * u16LocalRate) + 128) / 256;
            }
            else
            {
               s32LocalSum = ((s32LocalSum * u16LocalRate) - 128) / 256;
            }
            s32LocalSum = ( s32LocalSum + s16LocalLn2);
         }
         s32LocalSum = ( s32LocalSum
                       + u8LocalDnstr_add_pmh_modifier
                       + (u16LocalDnstRetardPurgeRiche / 256));
         if (s16LocalDeltaLamGaz > 0)
         {
            s32LocalSum = s32LocalSum + Delta_PMH_gaz;
         }
         Transfer_count = (uint8)MATHSRV_udtMIN(s32LocalSum, 255);
      }
      Dnstr_modifier_sampled = u8LocalDnstr_add_pmh_modifier;
   }
   else
   {
      VEMS_vidGET(Dnstr_substract_pmh_modifier,
                  u8LocalDnstrSubstractPmhModifier);
      if (Test_bed_transfer_count_r_to_l != 0)
      {
         Transfer_count = Transfer_count_r_to_l_c;
      }
      else
      {
         VEMS_vidGET(Cat_old_gain, u8LocalCat_old_gain);
         VEMS_vidGET(Dnstr_retard_purge_pauvre, u16LocalDnstrRetardPurgePauvre);
         u8Localinterp3 =
            MATHSRV_u8Interp2d(Lffc_r_l_non_idle_delay_emis_map[0],
                               u16LocalParaX,
                               u16LocalParaY,
                               9);
         u8Localinterp4 =
            MATHSRV_u8Interp2d(Lffc_r_l_non_idle_delay_neuf_map[0],
                               u16LocalParaX,
                               u16LocalParaY,
                               9);
         s16LocalLn2 = (sint16)( u8Localinterp3
                               + ( ( u8LocalCat_old_gain
                                   * ( u8Localinterp4
                                     - u8Localinterp3))
                                 / 256));
         if (bLocalCf_bInhFlex != 0)
         {
            s32LocalSum = (sint32)(s16LocalLn2);
         }
         else
         {
            VEMS_vidGET(Lffc_r_l_no_idle_dly_emis_flx,
                        u8LocalLffcRLNoIdleDlyEmisFlx);
            VEMS_vidGET(Lffc_r_l_no_idle_dly_neuf_flx,
                        u8LocalLffcRLNoIdleDlyNeufFlx);
            s16LocalLn1 = (sint16)( u8LocalLffcRLNoIdleDlyEmisFlx
                                  + ( ( u8LocalCat_old_gain
                                      * ( u8LocalLffcRLNoIdleDlyNeufFlx
                                        - u8LocalLffcRLNoIdleDlyEmisFlx))
                                    / 256));
            /*Barycentre 1*/
            VEMS_vidGET(Lffc_non_idle_dly_pond_flex,
                        u16LocalLffcNonIdleDlyPondFlex);

            s32LocalSum =(sint32)(s16LocalLn1 - s16LocalLn2);
            u16LocalRate =
               (uint16)MATHSRV_udtMIN(u16LocalLffcNonIdleDlyPondFlex, 256);
            if (s32LocalSum >= 0)
            {
               s32LocalSum = ((s32LocalSum * u16LocalRate) + 128) / 256;
            }
            else
            {
               s32LocalSum = ((s32LocalSum * u16LocalRate) - 128) / 256;
            }
            s32LocalSum = ( s32LocalSum + s16LocalLn2);
         }
         s32LocalSum = ( s32LocalSum
                       + u8LocalDnstrSubstractPmhModifier
                       + (u16LocalDnstrRetardPurgePauvre / 256));
         if (s16LocalDeltaLamGaz < 0)
         {
            s32LocalSum = s32LocalSum + Delta_PMH_gaz;
         }
         Transfer_count = (uint8)MATHSRV_udtMIN(s32LocalSum , 255);
      }
      Dnstr_modifier_sampled = u8LocalDnstrSubstractPmhModifier;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidTrsfCttimescal                           */
/* !Description :  calcul du terme correctif des paramètres de régulation de  */
/*                 richesse                                                   */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Periode_moteur;                                              */
/*  input uint8 Dnstr_modifier_sampled;                                       */
/*  output uint16 Dnstr_modifier_time_scale;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidTrsfCttimescal(void)
{
   uint16 u16LocalPeriode_moteur;
   uint16 u16LocalDnstrmodifiertimescale;


   VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);
   u16LocalDnstrmodifiertimescale =
      (uint16)(((Dnstr_modifier_sampled * u16LocalPeriode_moteur * 32) + 50000)
               / 100000);
   VEMS_vidSET(Dnstr_modifier_time_scale, u16LocalDnstrmodifiertimescale);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidFuncCtlFdInjAc                           */
/* !Description :  Le calcul de Lambda_feedback est effectué tous les TDC de  */
/*                 manière asynchrone avec l' automate de  détermination des  */
/*                 pas et sauts de richesse                                   */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidControlEna();                          */
/*  input st23 Vehicle_active_state;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidFuncCtlFdInjAc(void)
{
   uint8 u8LocalVehicle_active_state;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_RUNNING)
   {
      INJFARCTLUSCTL_vidControlEna();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidControlEna                               */
/* !Description :  Le calcul de Lambda_feedback est effectué tous les TDC de  */
/*                 manière asynchrone avec l' automate de  détermination des  */
/*                 pas et sauts de richesse. Pour cette raison, un indicateur */
/*                 Lambda_waiting est utilisé pour  prendre en compte les     */
/*                 sauts de richesse.                                         */
/* !Number      :  FCT5.9                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidDecCounter();                          */
/*  extf argret void INJFARCTLUSCTL_vidCalcLFB();                             */
/*  extf argret void INJFARCTLUSCTL_vidCalcLFBFilt();                         */
/*  input boolean Lambda_waiting;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidControlEna(void)
{
   INJFARCTLUSCTL_vidDecCounter();
   INJFARCTLUSCTL_vidCalcLFB();
   if (Lambda_waiting != 0)
   {
      INJFARCTLUSCTL_vidCalcLFBFilt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidDecCounter                               */
/* !Description :  Cette fonction permet la décrementation du Compteur du     */
/*                 temps de transition entre riche et pauvre ,la durée maximum*/
/*                 de la poursuite lente ainsi que le délai avant filtrage du */
/*                 Lambda_feedback en mode rapide.                            */
/* !Number      :  FCT5.10                                                    */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Transfer_count;                                               */
/*  input uint8 Lambda_slow_mode_delay;                                       */
/*  input uint8 Lambda_filtered_fdbk_mode_delay;                              */
/*  output uint8 Transfer_count;                                              */
/*  output uint8 Lambda_slow_mode_delay;                                      */
/*  output uint8 Lambda_filtered_fdbk_mode_delay;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidDecCounter(void)
{
   uint8 u8LocalLambdaFilteredFbModeDelay;


   Transfer_count = (uint8)MATHSRV_udtMAX((Transfer_count - 1), 0);
   Lambda_slow_mode_delay = (uint8) MATHSRV_udtMAX((Lambda_slow_mode_delay - 1),
                                                   0);
   VEMS_vidGET(Lambda_filtered_fdbk_mode_delay,
               u8LocalLambdaFilteredFbModeDelay);

   u8LocalLambdaFilteredFbModeDelay =
      (uint8)MATHSRV_udtMAX((u8LocalLambdaFilteredFbModeDelay - 1), 0);

   VEMS_vidSET(Lambda_filtered_fdbk_mode_delay,
               u8LocalLambdaFilteredFbModeDelay);
}
/*------------------------------- end of file --------------------------------*/