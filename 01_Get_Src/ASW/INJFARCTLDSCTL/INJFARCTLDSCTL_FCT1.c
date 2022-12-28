/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLDSCTL                                          */
/* !Description     : INJFARCTLDSCTL Component                                */
/*                                                                            */
/* !Module          : INJFARCTLDSCTL                                          */
/* !Description     : REGULATION DE RICHESSE PAR LA SONDE A OXYGENE AVAL      */
/*                    (DOUBLE BOUCLE)                                         */
/*                                                                            */
/* !File            : INJFARCTLDSCTL_FCT1.C                                   */
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
/*   1 / INJFARCTLDSCTL_vidInitOutput                                         */
/*   2 / INJFARCTLDSCTL_vidManager                                            */
/*   3 / INJFARCTLDSCTL_vidDecrEntryDly                                       */
/*   4 / INJFARCTLDSCTL_vidCalcModifiers                                      */
/*   5 / INJFARCTLDSCTL_vidDecSettlingDly                                     */
/*   6 / INJFARCTLDSCTL_vidDownstreamCond                                     */
/*   7 / INJFARCTLDSCTL_InitCtrlTrans                                         */
/*   8 / INJFARCTLDSCTL_WaitGnrlCondTrans                                     */
/*   9 / INJFARCTLDSCTL_vidCalculationMod                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 05886 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJ/INJCTL/INJFARCTLDSCTL/INJFARCT$*/
/* $Revision::   1.8      $$Author::   ACHEBINO       $$Date::   16 Jan 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   16 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "INJFARCTLDSCTL.h"
#include "INJFARCTLDSCTL_L.h"
#include "INJFARCTLDSCTL_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidInitOutput                               */
/* !Description :  initializing inputs                                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLDSCTL_vidInitParam();                           */
/*  output boolean INJFARCTLDSCTL_bHystOutputLow;                             */
/*  output boolean INJFARCTLDSCTL_bHystOutputRich;                            */
/*  output uint16 Dnstr_err_tension_prec;                                     */
/*  output st49 Current_dnstr_correction_state;                               */
/*  output boolean Dnstr_purge_cata_low;                                      */
/*  output boolean Dnstr_purge_cata_rich;                                     */
/*  output uint16 Dnstr_add_s_modifier;                                       */
/*  output uint16 Dnstr_substract_s_modifier;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidInitOutput(void)
{
   INJFARCTLDSCTL_bHystOutputLow = 0;
   INJFARCTLDSCTL_bHystOutputRich = 0;
   Dnstr_err_tension_prec = 1024;
   VEMS_vidSET(Current_dnstr_correction_state, INIT_CTRL_DNSTR_CORRECTION);
   VEMS_vidSET(Dnstr_purge_cata_low, 0);
   VEMS_vidSET(Dnstr_purge_cata_rich, 0);
   VEMS_vidSET(Dnstr_add_s_modifier, 0);
   VEMS_vidSET(Dnstr_substract_s_modifier, 0);
   /*InjCtl_EveIniPrm_FarCtlDsCtl*/
   INJFARCTLDSCTL_vidInitParam();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidManager                                  */
/* !Description :  La stratégie de régulation double boucle                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLDSCTL_InitCtrlTrans();                          */
/*  extf argret void INJFARCTLDSCTL_WaitGnrlCondTrans();                      */
/*  extf argret void INJFARCTLDSCTL_WaitCtrlCondTrans();                      */
/*  extf argret void INJFARCTLDSCTL_WaitOffDlyTrans();                        */
/*  extf argret void INJFARCTLDSCTL_DownStrmSenTrans();                       */
/*  extf argret void INJFARCTLDSCTL_PurgeCataTrans();                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLDSCTL_vidInitParam();                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st49 Current_dnstr_correction_state;                                */
/*  output st49 Current_dnstr_correction_state;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidManager(void)
{
   uint8 u8LocalCurrent_dnstr_corr_state;


   VEMS_vidGET(Current_dnstr_correction_state, u8LocalCurrent_dnstr_corr_state);
   switch (u8LocalCurrent_dnstr_corr_state)
   {
      case INIT_CTRL_DNSTR_CORRECTION:
         INJFARCTLDSCTL_InitCtrlTrans();
         break;

      case WAITING_DNSTR_GENERAL_CONDS:
         INJFARCTLDSCTL_WaitGnrlCondTrans();
         break;

      case WAITING_FOR_DNSTR_CTRL_CONDS:
         INJFARCTLDSCTL_WaitCtrlCondTrans();
         break;

      case WAITING_FOR_OFFSET_DELAY:
         INJFARCTLDSCTL_WaitOffDlyTrans();
         break;

      case DOWNSTREAM_SENSOR_CTRL:
         INJFARCTLDSCTL_DownStrmSenTrans();
         break;

      case DNSTR_PURGE_CATA:
         INJFARCTLDSCTL_PurgeCataTrans();
         break;

      default:
         VEMS_vidSET(Current_dnstr_correction_state,
                     INIT_CTRL_DNSTR_CORRECTION);
         INJFARCTLDSCTL_vidInitParam();
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidDecrEntryDly                             */
/* !Description :  Décrémentation du délai d'entrée                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dnstr_conds_met;                                            */
/*  input uint16 Dnstr_entry_delay;                                           */
/*  input uint16 Dnstr_entry_delay_c;                                         */
/*  output uint16 Dnstr_entry_delay;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidDecrEntryDly(void)
{
   boolean bLocalDnstr_conds_met;


   VEMS_vidGET(Dnstr_conds_met, bLocalDnstr_conds_met);
   if (bLocalDnstr_conds_met != 0)
   {
      if (Dnstr_entry_delay > 0)
      {
         Dnstr_entry_delay = (uint16)(Dnstr_entry_delay - 1);
      }
   }
   else
   {
      Dnstr_entry_delay = Dnstr_entry_delay_c;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidCalcModifiers                            */
/* !Description :  mécanisme d’adaptation pour affiner  Feedback_correction   */
/*                 pendant le fonctionnement du moteur.                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Periode_moteur;                                              */
/*  input sint16 Feedback_correction;                                         */
/*  output uint8 Dnstr_add_pmh_modifier;                                      */
/*  output uint16 Dnstr_substract_s_modifier;                                 */
/*  output uint8 Dnstr_substract_pmh_modifier;                                */
/*  output uint16 Dnstr_add_s_modifier;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidCalcModifiers(void)
{
   uint8  u8LocalDnstrAddPmhModifier;
   uint8  u8LocalDnstrSubstractPmhModifier;
   uint16 u16LocalPeriodeMoteur;
   uint16 u16LocalDnstraddsmodifier;
   uint16 u16LocalDnstrsubstractsmodifier;
   sint16 s16LocalDnstrsubPmh;
   sint16 s16LocalFeedbackcorrection ;


   VEMS_vidGET(Periode_moteur, u16LocalPeriodeMoteur);
   VEMS_vidGET(Feedback_correction, s16LocalFeedbackcorrection);
   if (s16LocalFeedbackcorrection > 0)
   {
      u8LocalDnstrAddPmhModifier = (uint8)(s16LocalFeedbackcorrection / 256);
      VEMS_vidSET(Dnstr_add_pmh_modifier,u8LocalDnstrAddPmhModifier);
      VEMS_vidSET(Dnstr_substract_s_modifier, 0);
      VEMS_vidSET(Dnstr_substract_pmh_modifier, 0);

      u16LocalDnstraddsmodifier = (uint16)((uint32)( u16LocalPeriodeMoteur
                                                   * s16LocalFeedbackcorrection)
                                          / 800000);
      VEMS_vidSET(Dnstr_add_s_modifier, u16LocalDnstraddsmodifier);
   }
   else
   {
      VEMS_vidSET(Dnstr_add_pmh_modifier, 0);
      VEMS_vidSET(Dnstr_add_s_modifier, 0);
      s16LocalDnstrsubPmh = (sint16)((-s16LocalFeedbackcorrection) / 256);
      u8LocalDnstrSubstractPmhModifier =
            (uint8)MATHSRV_udtMAX(s16LocalDnstrsubPmh, 0);
      VEMS_vidSET(Dnstr_substract_pmh_modifier,
                 u8LocalDnstrSubstractPmhModifier);

      if (s16LocalFeedbackcorrection == 0)
      {
         VEMS_vidSET(Dnstr_substract_s_modifier, 0);
      }
      else
      {
         u16LocalDnstrsubstractsmodifier
            = (uint16)((uint32)( u16LocalPeriodeMoteur
                               * (-s16LocalFeedbackcorrection))
                      / 800000);
         VEMS_vidSET(Dnstr_substract_s_modifier,
                    u16LocalDnstrsubstractsmodifier);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidDecSettlingDly                           */
/* !Description :  Décrémentation du délai de prise en compte de l’offset de  */
/*                 la valeur du pas InjCtl_SampleTiFast_SC                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dnstr_settling_delay;                                        */
/*  output uint16 Dnstr_settling_delay;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidDecSettlingDly(void)
{
   if (Dnstr_settling_delay > 0)
   {
      Dnstr_settling_delay = (uint16)(Dnstr_settling_delay - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidDownstreamCond                           */
/* !Description :  Ce module permet d’évaluer si les conditions d’adaptation  */
/*                 sont remplies en agissant sur le booléen Dnstr_conds_met.  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Conditions_for_feedback;                                    */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint16 Engine_load;                                                 */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Dnstr_lambda_load_max_thresh_c;                              */
/*  input uint16 Dnstr_lambda_load_min_thresh_c;                              */
/*  input uint16 Dnstr_lambda_speed_max_thresh_c;                             */
/*  input uint16 Dnstr_lambda_speed_min_thresh_c;                             */
/*  output boolean Dnstr_conds_met;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidDownstreamCond(void)
{
   boolean bLocalConditionsForFeedback;
   boolean bLocalLambdaSlowMode;
   uint16  u16LocalEngineLoad;
   uint16  u16LocalRegimeMoteur;


   VEMS_vidGET(Conditions_for_feedback, bLocalConditionsForFeedback);
   VEMS_vidGET(Lambda_slow_mode, bLocalLambdaSlowMode);
   VEMS_vidGET(Engine_load, u16LocalEngineLoad);
   VEMS_vidGET(Regime_moteur, u16LocalRegimeMoteur);
   if (  (bLocalConditionsForFeedback != 0)
      && (bLocalLambdaSlowMode != 0)
      && (Dnstr_lambda_load_max_thresh_c > u16LocalEngineLoad)
      && (u16LocalEngineLoad > Dnstr_lambda_load_min_thresh_c)
      && (Dnstr_lambda_speed_max_thresh_c > u16LocalRegimeMoteur)
      && (u16LocalRegimeMoteur > Dnstr_lambda_speed_min_thresh_c))
   {
      VEMS_vidSET(Dnstr_conds_met, 1);
   }
   else
   {
      VEMS_vidSET(Dnstr_conds_met, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_InitCtrlTrans                               */
/* !Description :  Transition de INIT_CTRL_DNSTR_CORRECTION  vers             */
/*                 WAITING_DNSTR_GENERAL_CONDS                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st49 Current_dnstr_correction_state;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_InitCtrlTrans(void)
{
   VEMS_vidSET(Current_dnstr_correction_state, WAITING_DNSTR_GENERAL_CONDS);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_WaitGnrlCondTrans                           */
/* !Description :  Transition WAITING_DNSTR_GENERAL_CONDS vers                */
/*                 WAITING_FOR_DNSTR_CTRL_CONDS                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJFARCTLDSCTL_vidInitEntryDly();                        */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Dnstr_lambda_water_temp_thresh_c;                             */
/*  input boolean Manu_inh_lambda_feedback;                                   */
/*  output st49 Current_dnstr_correction_state;                               */
/*  output boolean INJFARCTLDSCTL_bEnableCalcModif;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_WaitGnrlCondTrans(void)
{
   boolean bLocalINHINJFARCTLDSCTLDBLLOOP;
   boolean bLocalLshdDownStrmLbdaSensorHot;
   uint8   u8LocalTemperatureEau;


   bLocalINHINJFARCTLDSCTLDBLLOOP =
      GDGAR_bGetFRM(FRM_FRM_INHINJFARCTLDSCTLDBLLOOP);

   VEMS_vidGET(Lshd_down_stream_lbda_sensor_hot,
               bLocalLshdDownStrmLbdaSensorHot);
   VEMS_vidGET(Temperature_eau, u8LocalTemperatureEau);
   if (  (u8LocalTemperatureEau > Dnstr_lambda_water_temp_thresh_c)
      && (bLocalINHINJFARCTLDSCTLDBLLOOP == 0)
      && (Manu_inh_lambda_feedback == 0)
      && (bLocalLshdDownStrmLbdaSensorHot != 0))
   {
      VEMS_vidSET(Current_dnstr_correction_state, WAITING_FOR_DNSTR_CTRL_CONDS);
      /*InjCtl_EveEntryDly_FarCtlDsCtl*/
      INJFARCTLDSCTL_vidInitEntryDly();
      INJFARCTLDSCTL_bEnableCalcModif = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidCalculationMod                           */
/* !Description :  Fonction qui assure l'appel de 01_Calculation_modifiers    */
/*                 (INJFARCTLDSCTL_vidCalcModifiers)                          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLDSCTL_vidCalcModifiers();                       */
/*  input boolean INJFARCTLDSCTL_bEnableCalcModif;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidCalculationMod(void)
{
   if (INJFARCTLDSCTL_bEnableCalcModif != 0)
   {
      INJFARCTLDSCTL_vidCalcModifiers();
   }
}
/*------------------------------- end of file --------------------------------*/