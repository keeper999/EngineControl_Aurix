/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGRUNST                                                */
/* !Description     : ENGRUNST component                                      */
/*                                                                            */
/* !Module          : ENGRUNST                                                */
/* !Description     : Etat moteur tournant                                    */
/*                                                                            */
/* !File            : ENGRUNST_FCT1.C                                         */
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
/*   1 / ENGRUNST_vidInitOutput                                               */
/*   2 / ENGRUNST_vidFullLoadEntryDelay                                       */
/*   3 / ENGRUNST_vidFcoMainConditions                                        */
/*   4 / ENGRUNST_vidInit                                                     */
/*   5 / ENGRUNST_vidDelayTimeout                                             */
/*   6 / ENGRUNST_vidCutOffInputMngt                                          */
/*   7 / ENGRUNST_vidEngrunst                                                 */
/*   8 / ENGRUNST_vidOverpeedFcoCondEntry                                     */
/*   9 / ENGRUNST_vidEngrunStInterface                                        */
/*   10 / ENGRUNST_vidKeyOnCalc                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5489080 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/ENGRUNST/ENGRUNST_FCT1.C_v$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   13 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   13 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "ENGRUNST.H"
#include "ENGRUNST_L.H"
#include "ENGRUNST_IM.H"
#include "GDGAR.H"
#include "MATHSRV.H"
#include "SWFAIL.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation des variables produites par la   */
/*                 spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input bool ERUN_NORMAL_RUNNING;                                           */
/*  output boolean Conditions_generales_de_coupure;                           */
/*  output st07 Engine_running_state;                                         */
/*  output bool ERUN_NORMAL_RUNNING;                                          */
/*  output uint8 Engine_running_state_swc;                                    */
/*  output boolean ESLim_bAcvFuCutOff;                                        */
/*  output boolean ESLim_bAcvTrqLim;                                          */
/*  output uint16 ESLim_nLoFuCutOff;                                          */
/*  output uint16 EngSt_ctOverSpdFCO;                                         */
/*  output boolean ENGRUNST_Srv_bByCnOvrNEngMx_prev;                          */
/*  output uint8 Ext_stEngrun;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidInitOutput(void)
{
   VEMS_vidSET(Conditions_generales_de_coupure, 0);
   VEMS_vidSET(Engine_running_state, ERUN_NORMAL_RUNNING);
   VEMS_vidSET(Engine_running_state_swc, 128);
   VEMS_vidSET(ESLim_bAcvFuCutOff, 0);
   VEMS_vidSET(ESLim_bAcvTrqLim, 0);
   VEMS_vidSET(ESLim_nLoFuCutOff, 0);
   EngSt_ctOverSpdFCO = 0;
   ENGRUNST_Srv_bByCnOvrNEngMx_prev = 0;
   VEMS_vidSET(Ext_stEngrun, Ext_stEngrunNorm_SC);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidFullLoadEntryDelay                             */
/* !Description :  Le passage en FULL_LOAD est effectué sur des conditions    */
/*                 évaluées en NORMAL_RUNNING ou en ENGINE_OVERSPEED_FCO, avec*/
/*                 un délai d’entrée géré dans ce module.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Full_load_pedale_map[16];                                     */
/*  input uint8 Full_load_throttle_map[16];                                   */
/*  input uint16 Engs_full_load_after_crank_count;                            */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Engs_fl_eng_speed_low_thres;                                  */
/*  input uint8 Engs_fl_eng_speed_high_thres;                                 */
/*  input uint8 Engs_full_load_water_temp_thres;                              */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input uint8 Full_load_throttle;                                           */
/*  input uint8 Full_load_pedale;                                             */
/*  input boolean Engs_full_load_entry_with_delay;                            */
/*  input uint16 Engs_full_load_entry_delay;                                  */
/*  input uint16 Engs_full_load_entry_count;                                  */
/*  output uint8 Full_load_pedale;                                            */
/*  output uint8 Full_load_throttle;                                          */
/*  output uint16 Engs_full_load_after_crank_count;                           */
/*  output boolean Engs_full_load_entry_with_delay;                           */
/*  output boolean Engs_full_load_entry_delay_cond;                           */
/*  output uint16 Engs_full_load_entry_count;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidFullLoadEntryDelay(void)
{
   boolean bLocalInhEngrunStFullLd;
   boolean bLocalCond;
   uint8   u8LocalCorrectedThrottlePosition;
   uint8   u8LocalDv_positionpedalerelative;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalEngSpeed;
   uint16  u16LocalRegime_moteur;
   uint32  u32LocalRegimeMoteurTemp;
   sint32  s32LocalEngsFullLoadAfterCrankCt;


   bLocalInhEngrunStFullLd = GDGAR_bGetFRM(FRM_FRM_INHENGRUNSTFULLLD);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u32LocalRegimeMoteurTemp = (u16LocalRegime_moteur * 8);
   u16LocalEngSpeed = (uint16)MATHSRV_udtMIN(u32LocalRegimeMoteurTemp, 65535);
   u16LocalEngSpeed = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                   u16LocalEngSpeed,
                                                   16);

   Full_load_pedale = MATHSRV_u8Interp1d(Full_load_pedale_map,
                                         u16LocalEngSpeed);

   Full_load_throttle = MATHSRV_u8Interp1d(Full_load_throttle_map,
                                           u16LocalEngSpeed);
   s32LocalEngsFullLoadAfterCrankCt = (sint32)( Engs_full_load_after_crank_count
                                              - 1);
   Engs_full_load_after_crank_count =
      (uint16)MATHSRV_udtMAX(s32LocalEngsFullLoadAfterCrankCt, 0);

   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   if ( (Engs_full_load_after_crank_count != 0)
         && (u8LocalRegime_moteur_32 >= Engs_fl_eng_speed_low_thres)
         && (u8LocalRegime_moteur_32 < Engs_fl_eng_speed_high_thres)
         && (u8LocalTemperature_eau >= Engs_full_load_water_temp_thres))
   {
      Engs_full_load_entry_with_delay = 1;
   }
   else
   {
      Engs_full_load_entry_with_delay = 0;
   }
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrectedThrottlePosition);
   VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_positionpedalerelative);
   if ( (  (u8LocalCorrectedThrottlePosition < Full_load_throttle)
        && (u8LocalDv_positionpedalerelative < Full_load_pedale))
      || (bLocalInhEngrunStFullLd != 0))
   {
      bLocalCond = 1;
   }
   else
   {
      bLocalCond = 0;
   }

   if (Engs_full_load_entry_with_delay == 0)
   {
      Engs_full_load_entry_delay_cond = 1;
   }
   else
   {
      if (bLocalCond != 0)
      {
         Engs_full_load_entry_count = Engs_full_load_entry_delay;
         Engs_full_load_entry_delay_cond = 0;
      }
      else
      {
         if (Engs_full_load_entry_count == 0)
         {
            Engs_full_load_entry_delay_cond = 1;
            Engs_full_load_entry_count = 0;
         }
         else
         {
            Engs_full_load_entry_delay_cond = 0;
            Engs_full_load_entry_count = (uint16)( Engs_full_load_entry_count
                                                 - 1);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidFcoMainConditions                              */
/* !Description :  Cette condition nécessaire à l'autorisation de la coupure  */
/*                 injection (ERUN_ENGINE_OVERRUN_FCO) quelque soit l'état    */
/*                 d'origine.                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_08_05237_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cat_temperature;                                             */
/*  input boolean Bv_changement_rapport;                                      */
/*  input boolean Presence_bva;                                               */
/*  input boolean OxC_bOxCHeatPhaReq;                                         */
/*  input uint8 Gear_engaged;                                                 */
/*  input boolean Fco_temp_cata_ok;                                           */
/*  input uint16 Fco_cat_temperature_thresh_high;                             */
/*  input uint16 Fco_cat_temperature_thresh_low;                              */
/*  input boolean OxC_bInhCutOffOvern_M[6];                                   */
/*  input boolean EngSt_bAcvCdnGc_C;                                          */
/*  output boolean Fco_temp_cata_ok;                                          */
/*  output boolean Fco_main_conditions_ok;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidFcoMainConditions(void)
{
   boolean bLocalBv_changement_rapport;
   boolean bLocalPresence_bva;
   boolean bLocalOxC_bOxCHeatPhaReq;
   boolean bLocalResult;
   uint8   u8LocalGear_engaged;
   uint16  u16LocalCat_temperature;


   VEMS_vidGET(Cat_temperature, u16LocalCat_temperature);
   VEMS_vidGET(Bv_changement_rapport, bLocalBv_changement_rapport);
   VEMS_vidGET(Presence_bva, bLocalPresence_bva);
   VEMS_vidGET(OxC_bOxCHeatPhaReq, bLocalOxC_bOxCHeatPhaReq);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);

   if (Fco_temp_cata_ok != 0)
   {
      if (u16LocalCat_temperature >= Fco_cat_temperature_thresh_high)
      {
         Fco_temp_cata_ok = 0;
      }
   }
   else
   {
      if (u16LocalCat_temperature <= Fco_cat_temperature_thresh_low)
      {
         Fco_temp_cata_ok = 1;
      }
   }

   u8LocalGear_engaged = (uint8)MATHSRV_udtMIN(u8LocalGear_engaged, 5);
   bLocalResult = OxC_bInhCutOffOvern_M[u8LocalGear_engaged];
   if (  (  (bLocalBv_changement_rapport == 0)
         || (bLocalPresence_bva == 0)
         || (EngSt_bAcvCdnGc_C == 0))
      && (Fco_temp_cata_ok != 0)
      && (  (bLocalResult != 0)
         || (bLocalOxC_bOxCHeatPhaReq == 0)))
   {
      Fco_main_conditions_ok = 1;
   }
   else
   {
      Fco_main_conditions_ok = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidInit                                           */
/* !Description :  Le compteur Esp_cut_off_allowed_count est initialisé à zéro*/
/*                 au reset.                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Esp_cut_off_allowed_count;                                  */
/*  output uint16 EngSt_ctOverSpdFCO;                                         */
/*  output uint16 ESLim_tiCntOverNEngMaxTmp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidInit(void)
{
   Esp_cut_off_allowed_count = 0;
   EngSt_ctOverSpdFCO = 0;
   ESLim_tiCntOverNEngMaxTmp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidDelayTimeout                                   */
/* !Description :  A la transition de l’automate Vehicle_active_state de      */
/*                 l’état CRANKING à RUNNING, on initialise le compteur       */
/*                 Pl_fco_entry_delay_timeout.                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Pl_fco_start_delay;                                          */
/*  input uint16 Engs_full_load_after_crank_delay;                            */
/*  output uint16 Pl_fco_entry_delay_timeout;                                 */
/*  output uint16 Engs_full_load_after_crank_count;                           */
/*  output boolean Engs_full_load_entry_with_delay;                           */
/*  output uint16 Engs_full_load_entry_count;                                 */
/*  output boolean Engs_full_load_entry_delay_cond;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidDelayTimeout(void)
{
   Pl_fco_entry_delay_timeout = Pl_fco_start_delay;
   Engs_full_load_after_crank_count = Engs_full_load_after_crank_delay;
   Engs_full_load_entry_with_delay = 0;
   Engs_full_load_entry_count = 0;
   Engs_full_load_entry_delay_cond = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidCutOffInputMngt                                */
/* !Description :  La coupure d’injection est autorisée qu'au dessus d'un     */
/*                 seuil de température après un délai suivant le démarrage et*/
/*                 lorsqu’un un délai calibré est écoulé suite à une          */
/*                 régulation ESP de type MSR lors d’une coupure d’injection  */
/*                 pied levé.                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Pl_fco_water_temp;                                            */
/*  input uint16 Pl_fco_entry_delay_timeout;                                  */
/*  input boolean Fco_main_conditions_ok;                                     */
/*  input uint16 Esp_cut_off_allowed_count;                                   */
/*  input uint16 Esp_cut_off_allowed_delay;                                   */
/*  output boolean Conditions_generales_de_coupure;                           */
/*  output uint16 Pl_fco_entry_delay_timeout;                                 */
/*  output uint16 Esp_cut_off_allowed_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidCutOffInputMngt(void)
{
   uint8  u8LocalCha_stTqReq;
   uint8  u8LocalTemperature_eau;


   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqReq);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   if (  (u8LocalTemperature_eau >= Pl_fco_water_temp)
      && (Pl_fco_entry_delay_timeout == 0)
      && (Fco_main_conditions_ok != 0)
      && (Esp_cut_off_allowed_count == 0)
      && (u8LocalCha_stTqReq != 6))
   {
      VEMS_vidSET(Conditions_generales_de_coupure, 1);
   }
   else
   {
      VEMS_vidSET(Conditions_generales_de_coupure, 0);
   }
   if (Pl_fco_entry_delay_timeout != 0)
   {
      Pl_fco_entry_delay_timeout = (uint16)(Pl_fco_entry_delay_timeout - 1);
   }
   if (u8LocalCha_stTqReq == 6)
   {
      Esp_cut_off_allowed_count = Esp_cut_off_allowed_delay;
   }
   else
   {
      if (Esp_cut_off_allowed_count != 0)
      {
         Esp_cut_off_allowed_count = (uint16)(Esp_cut_off_allowed_count - 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidEngrunst                                       */
/* !Description :  L'injection de carburant est coupée lors des décélérations */
/*                 et les prises de régime pédale en position pied levé avec  */
/*                 pour objectifs.                                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_08_05237_015.01                                     */
/*                 VEMS_R_08_05237_006.01                                     */
/*                 VEMS_R_08_05237_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void EngSt_EveTOSR_EngrunSt();                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EngSt_EveNTFL_EngrunSt();                                */
/*  extf argret void EngSt_EveEORF_EngrunSt();                                */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean TPM_bAcvRichThermoProt;                                     */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input boolean EngSt_bEntryOVERSPEED_FCO;                                  */
/*  input boolean Fco_temp_cata_ok;                                           */
/*  input bool ERUN_ENGINE_OVERSPEED_FCO;                                     */
/*  input uint8 Full_load_throttle;                                           */
/*  input uint8 Full_load_pedale;                                             */
/*  input boolean Engs_full_load_entry_delay_cond;                            */
/*  input bool ERUN_FULL_LOAD;                                                */
/*  input boolean EngSt_bCtlEngNOnIdl;                                        */
/*  input boolean IdlSys_bInjCutOff;                                          */
/*  input bool ERUN_ON_IDLE;                                                  */
/*  input boolean Conditions_generales_de_coupure;                            */
/*  input bool ERUN_ENGINE_OVERRUN_FCO;                                       */
/*  input bool ERUN_NORMAL_RUNNING;                                           */
/*  input uint8 Full_load_throttle_hysteresis;                                */
/*  input uint8 Full_load_pedale_hysteresis;                                  */
/*  input uint16 Afr_tgt_reinst_time_in_fco_count;                            */
/*  input uint16 EngSt_ctOverSpdFCO;                                          */
/*  input uint16 EngSt_ctDlyOverSpdFCO_C;                                     */
/*  input boolean ESLim_bAcvFuCutOff;                                         */
/*  output st07 Engine_running_state;                                         */
/*  output bool ERUN_ENGINE_OVERSPEED_FCO;                                    */
/*  output boolean ESLim_bAcvTrqLim;                                          */
/*  output bool ERUN_FULL_LOAD;                                               */
/*  output boolean EngSt_bEngNOnIdl;                                          */
/*  output bool ERUN_ON_IDLE;                                                 */
/*  output bool ERUN_ENGINE_OVERRUN_FCO;                                      */
/*  output uint16 Afr_tgt_reinst_time_in_fco_count;                           */
/*  output bool ERUN_NORMAL_RUNNING;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidEngrunst(void)
{
   boolean bLocalInhEngrunStFullLd;
   boolean bLocalIdlSys_bInjCutOff;
   boolean bLocalInhESLimFuCutOff;
   boolean bLocalCondi_generales_de_coupure;
   boolean bLocalESLim_bAcvFuCutOff;
   boolean bLocalEngSt_bCtlEngNOnIdl;
   boolean bLocalTPM_bAcvRichThermoProt;
   uint8   u8LocalCorrectedThrottlePosition;
   uint8   u8LocalDv_positionpedalerelative;
   uint8   u8LocalEngine_running_state;
   uint16  u16LocalAfr_tgt_rins_tim_fco_cnt;
   sint16  s16LocalLoadThrottleDiff;
   sint16  s16LocalLoadPedaleDiff;


   bLocalInhEngrunStFullLd = GDGAR_bGetFRM(FRM_FRM_INHENGRUNSTFULLLD);
   bLocalInhESLimFuCutOff = GDGAR_bGetFRM(FRM_FRM_INHESLIMFUCUTOFF);
   VEMS_vidGET(TPM_bAcvRichThermoProt, bLocalTPM_bAcvRichThermoProt);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrectedThrottlePosition);
   VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_positionpedalerelative);
   switch (u8LocalEngine_running_state)
   {
      case ERUN_NORMAL_RUNNING:
         if (EngSt_bEntryOVERSPEED_FCO != 0)
         {
            if (  (bLocalInhESLimFuCutOff == 0)
               && (Fco_temp_cata_ok != 0))
            {
               /*l'évènement EngSt_EveTOSR_EngrunSt*/
               EngSt_EveTOSR_EngrunSt();
               VEMS_vidSET(Engine_running_state, ERUN_ENGINE_OVERSPEED_FCO);
            }
            else
            {
               if (  (bLocalInhESLimFuCutOff != 0)
                  || (Fco_temp_cata_ok == 0)
                  || (bLocalTPM_bAcvRichThermoProt != 0))
               {
                  VEMS_vidSET(Engine_running_state,
                              ERUN_ENGINE_OVERSPEED_TQLIM);
                  VEMS_vidSET(ESLim_bAcvTrqLim, 1);
               }
            }
         }
         else
         {
            if (  (  (u8LocalCorrectedThrottlePosition >= Full_load_throttle)
                  || (u8LocalDv_positionpedalerelative >= Full_load_pedale))
               && (Engs_full_load_entry_delay_cond != 0)
               && (bLocalInhEngrunStFullLd == 0))
            {
               /*l'évènement EngSt_EveNTFL_EngrunSt*/
               EngSt_EveNTFL_EngrunSt();
               VEMS_vidSET(Engine_running_state, ERUN_FULL_LOAD);
               VEMS_vidSET(ESLim_bAcvTrqLim, 0);
            }
            else
            {
               VEMS_vidGET(EngSt_bCtlEngNOnIdl, bLocalEngSt_bCtlEngNOnIdl);
               VEMS_vidGET(IdlSys_bInjCutOff, bLocalIdlSys_bInjCutOff);
               if (  (bLocalEngSt_bCtlEngNOnIdl != 0)
                  && (bLocalIdlSys_bInjCutOff == 0))
               {
                  VEMS_vidSET(EngSt_bEngNOnIdl, 1);
                  VEMS_vidSET(Engine_running_state, ERUN_ON_IDLE);
               }
               else
               {
                  VEMS_vidGET(IdlSys_bInjCutOff, bLocalIdlSys_bInjCutOff);
                  VEMS_vidGET(Conditions_generales_de_coupure,
                              bLocalCondi_generales_de_coupure);
                  if (  (bLocalIdlSys_bInjCutOff != 0)
                     && (bLocalCondi_generales_de_coupure != 0))
                  {
                     /*l'évènement EngSt_EveTOSR_EngrunSt*/
                     EngSt_EveTOSR_EngrunSt();
                     VEMS_vidSET(Engine_running_state, ERUN_ENGINE_OVERRUN_FCO);
                     VEMS_vidSET(Afr_tgt_reinst_time_in_fco_count, 0);
                  }
               }
            }
         }
         break;

      case ERUN_ENGINE_OVERSPEED_TQLIM:
         if (EngSt_bEntryOVERSPEED_FCO == 0)
         {
            if (  (  (u8LocalCorrectedThrottlePosition < Full_load_throttle)
                  && (u8LocalDv_positionpedalerelative < Full_load_pedale))
               || (bLocalInhEngrunStFullLd != 0))
            {
               VEMS_vidSET(Engine_running_state, ERUN_NORMAL_RUNNING);
            }
            else
            {
               VEMS_vidSET(Engine_running_state, ERUN_FULL_LOAD);
            }
            VEMS_vidSET(ESLim_bAcvTrqLim, 0);
         }
         break;

         case ERUN_FULL_LOAD:
         if (EngSt_bEntryOVERSPEED_FCO != 0)
         {
            if (  (bLocalInhESLimFuCutOff == 0)
               && (Fco_temp_cata_ok != 0))
            {
               /*l'évènement EngSt_EveTOSR_EngrunSt*/
               EngSt_EveTOSR_EngrunSt();
               VEMS_vidSET(Engine_running_state, ERUN_ENGINE_OVERSPEED_FCO);
            }
            else
            {
               if (  (bLocalInhESLimFuCutOff != 0)
                  || (Fco_temp_cata_ok == 0)
                  || (bLocalTPM_bAcvRichThermoProt != 0))
               {
                  VEMS_vidSET(Engine_running_state,
                              ERUN_ENGINE_OVERSPEED_TQLIM);
                  VEMS_vidSET(ESLim_bAcvTrqLim, 1);
               }
            }
         }
         else
         {
            s16LocalLoadThrottleDiff = (sint16)( Full_load_throttle
                                               - Full_load_throttle_hysteresis);
            s16LocalLoadPedaleDiff = (sint16)( Full_load_pedale
                                             - Full_load_pedale_hysteresis);
            if ( (  ( (sint16)u8LocalCorrectedThrottlePosition
                    < s16LocalLoadThrottleDiff)
                 && ( (sint16)u8LocalDv_positionpedalerelative
                    < s16LocalLoadPedaleDiff))
               || (bLocalInhEngrunStFullLd != 0))
            {
               VEMS_vidSET(Engine_running_state, ERUN_NORMAL_RUNNING);
               VEMS_vidSET(ESLim_bAcvTrqLim, 0);
            }
         }
         break;

      case ERUN_ENGINE_OVERRUN_FCO:
         VEMS_vidGET(IdlSys_bInjCutOff, bLocalIdlSys_bInjCutOff);
         VEMS_vidGET(Conditions_generales_de_coupure,
                     bLocalCondi_generales_de_coupure);
         if (  (bLocalIdlSys_bInjCutOff == 0)
            || (bLocalCondi_generales_de_coupure == 0))
         {
            /*L'évènement EngSt_EveEORF_EngrunSt*/
            EngSt_EveEORF_EngrunSt();
            VEMS_vidSET(Engine_running_state, ERUN_NORMAL_RUNNING);
            VEMS_vidSET(ESLim_bAcvTrqLim, 0);
         }
         else
         {
            VEMS_vidGET(Afr_tgt_reinst_time_in_fco_count,
                        u16LocalAfr_tgt_rins_tim_fco_cnt);
            if (u16LocalAfr_tgt_rins_tim_fco_cnt < 65535)
            {
               u16LocalAfr_tgt_rins_tim_fco_cnt =
                  (uint16)(u16LocalAfr_tgt_rins_tim_fco_cnt + 1);
               VEMS_vidSET(Afr_tgt_reinst_time_in_fco_count,
                           u16LocalAfr_tgt_rins_tim_fco_cnt);
            }
         }
         break;

      case ERUN_ON_IDLE:
         VEMS_vidGET(EngSt_bCtlEngNOnIdl, bLocalEngSt_bCtlEngNOnIdl);
         VEMS_vidGET(IdlSys_bInjCutOff, bLocalIdlSys_bInjCutOff);
         if (  (bLocalEngSt_bCtlEngNOnIdl == 0)
            || (bLocalIdlSys_bInjCutOff != 0))
         {
            VEMS_vidSET(EngSt_bEngNOnIdl, 0);
            VEMS_vidSET(Engine_running_state, ERUN_NORMAL_RUNNING);
            VEMS_vidSET(ESLim_bAcvTrqLim, 0);
         }
         break;

      case ERUN_ENGINE_OVERSPEED_FCO:
         if (  (EngSt_bEntryOVERSPEED_FCO != 0)
            && (  (EngSt_ctOverSpdFCO >= EngSt_ctDlyOverSpdFCO_C)
               || (bLocalInhESLimFuCutOff != 0)
               || (Fco_temp_cata_ok == 0)
               || (bLocalTPM_bAcvRichThermoProt != 0)))
         {
            VEMS_vidSET(Engine_running_state, ERUN_ENGINE_OVERSPEED_TQLIM);
            VEMS_vidSET(ESLim_bAcvTrqLim, 1);
         }
         else
         {
            VEMS_vidGET(ESLim_bAcvFuCutOff, bLocalESLim_bAcvFuCutOff);
            if (  (EngSt_bEntryOVERSPEED_FCO == 0)
               || (bLocalESLim_bAcvFuCutOff == 0))
            {
               if (  (  (u8LocalCorrectedThrottlePosition >= Full_load_throttle)
                     || (u8LocalDv_positionpedalerelative >= Full_load_pedale))
                  && (bLocalInhEngrunStFullLd == 0))
               {
                  VEMS_vidSET(Engine_running_state, ERUN_FULL_LOAD);
               }
               else
               {
                  VEMS_vidSET(Engine_running_state, ERUN_NORMAL_RUNNING);
               }
               VEMS_vidSET(ESLim_bAcvTrqLim, 0);
            }
         }
         break;

      default:
         VEMS_vidSET(EngSt_bEngNOnIdl, 0);
         VEMS_vidSET(Engine_running_state, ERUN_NORMAL_RUNNING);
         VEMS_vidSET(ESLim_bAcvTrqLim, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidOverpeedFcoCondEntry                           */
/* !Description :  Le passage à VRAI de FRM_bEngSpdLimHiIntv entraine une     */
/*                 limitation du régime moteur, calibrable en fonction du     */
/*                 rapport de boite filtré. Le passage à VRAI de              */
/*                 FRM_bEngSpdLimLoIntv entraine une limitation sévère du     */
/*                 régime moteur.                                             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_08_05237_012.01                                     */
/*                 VEMS_R_08_05237_001.01                                     */
/*                 VEMS_R_08_05237_002.01                                     */
/*                 VEMS_R_08_05237_003.01                                     */
/*                 VEMS_R_08_05237_004.01                                     */
/*                 VEMS_R_08_05237_005.01                                     */
/*                 VEMS_R_08_05237_013.01                                     */
/*                 VEMS_R_08_05237_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16 u16Index);*/
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPt_noGearCord_Sfty;                                         */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 CoPt_noGearCord_Sfty_AX[8];                                   */
/*  input uint8 EngSt_noEgdGearCord_AX[8];                                    */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 EngSt_EngSpdLimLoThd_T[8];                                    */
/*  input uint8 EngSt_EngSpdLimHiThd_T[8];                                    */
/*  input boolean ESLim_bAcvRedESLimProtMecKOn;                               */
/*  input uint8 EngSt_EngSpdLimHiThdProtMec_M[8][16];                         */
/*  input uint8 EngSt_EngSpdLimHiThd_M[8][16];                                */
/*  input uint16 EngSt_nLoFuCutOffHys_T[8];                                   */
/*  input uint8 EngSt_EngSpdLimThd;                                           */
/*  input uint8 EngSt_EngSpdLimThdHys_T[8];                                   */
/*  input boolean EngSt_bEntryOVERSPEED_FCO;                                  */
/*  input uint16 EngSt_ctOverSpdFCO;                                          */
/*  input uint16 ESLim_tiCntOverNEngMaxTmp;                                   */
/*  input boolean ESLim_bAcvFuCutOff;                                         */
/*  input uint16 ESLim_tiCntOverNEngMax;                                      */
/*  input boolean Afts_bRstESLim;                                             */
/*  input boolean Srv_bBypCntOverNEngMax;                                     */
/*  input boolean ENGRUNST_Srv_bByCnOvrNEngMx_prev;                           */
/*  input uint16 Srv_tiCntOverNEngMax;                                        */
/*  input uint16 ESLim_tiMaxOverNEngMax_C;                                    */
/*  output uint8 EngSt_EngSpdLimThd;                                          */
/*  output uint16 ESLim_nLoFuCutOff;                                          */
/*  output uint16 EngSt_ctOverSpdFCO;                                         */
/*  output uint16 ESLim_tiCntOverNEngMaxTmp;                                  */
/*  output boolean EngSt_bMonRunRedESLim;                                     */
/*  output boolean ESLim_bAcvFuCutOff;                                        */
/*  output uint16 ESLim_tiCntOverNEngMax;                                     */
/*  output boolean ESLim_bAcvRedESLimProtMec;                                 */
/*  output boolean ENGRUNST_Srv_bByCnOvrNEngMx_prev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidOverpeedFcoCondEntry(void)
{
   boolean bLocalEngSpdLimHiIntv;
   boolean bLocalEngSpdLimLoIntv;
   boolean bLocalESLim_bAcvFuCutOff;
   boolean bLocalAfts_bRstESLim;
   boolean bLocalSrv_bBypCntOverNEngMax;
   uint8   u8LocalCoPt_noGearCord_Sfty;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalGDU_stDgoInv_VarCod;
   uint8   u8LocalEngStEngSpdLimThdPara;
   uint16  u16LocalRegimeMoteur32Temp;
   uint16  u16LocalCoPtnoGearCordSfty;
   uint16  u16LocalEngStTemp;
   uint16  u16LocalEngStEngSpdLimThdTemp;
   uint16  u16LocalCoPtnoEgdGearCord;
   uint16  u16LocalESLimFuCutOff;
   uint16  u16LocalTemperatureCalcPara;
   uint16  u16LocalnoEgdGearCordInterp;
   uint16  u16LocalESLim_nLoFuCutOff;
   uint16  u16LocalESLim_tiCntOverNEngMax;
   uint16  u16LocalSrv_tiCntOverNEngMax;
   uint16  u16LocalESLim_tiCntOverNEngMax2;
   uint32  u32LocalESLim_tiCntOverNEngMax;
   uint32  u32LocalSum;


   bLocalEngSpdLimLoIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMLOINTV);
   bLocalEngSpdLimHiIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMHIINTV);
   /* VEMS_vidGET(GUS_stDgoInv_VarCod, u8LocalGUS_stDgoInv_VarCod); */
   u8LocalGDU_stDgoInv_VarCod = GDGAR_tenuGetStDgo(GD_DFT_INV_VARCOD);
   VEMS_vidGET(CoPt_noGearCord_Sfty, u8LocalCoPt_noGearCord_Sfty);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   u16LocalCoPtnoGearCordSfty =
      MATHSRV_u16CalcParaIncAryU8(CoPt_noGearCord_Sfty_AX,
                                  u8LocalCoPt_noGearCord_Sfty,
                                  8);
   u16LocalCoPtnoEgdGearCord =
      MATHSRV_u16CalcParaIncAryU8(EngSt_noEgdGearCord_AX,
                                  u8LocalCoPt_noEgdGearCord,
                                  8);
   u16LocalTemperatureCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                  u8LocalTemperature_eau,
                                  16);

   /* Calculus of EngSt_EngSpdLimThd*/
   if (bLocalEngSpdLimLoIntv != 0)
   {
      EngSt_EngSpdLimThd = MATHSRV_u8Interp1d(EngSt_EngSpdLimLoThd_T,
                                              u16LocalCoPtnoGearCordSfty);
   }
   else
   {
      if (  (bLocalEngSpdLimHiIntv != 0)
         || (u8LocalGDU_stDgoInv_VarCod == GDU_ETAT_PRESENT))
      {
         EngSt_EngSpdLimThd = MATHSRV_u8Interp1d(EngSt_EngSpdLimHiThd_T,
                                                 u16LocalCoPtnoGearCordSfty);
      }
      else
      {
         if (ESLim_bAcvRedESLimProtMecKOn != 0)
         {
            EngSt_EngSpdLimThd =
               MATHSRV_u8Interp2d(&EngSt_EngSpdLimHiThdProtMec_M[0][0],
                                  u16LocalCoPtnoEgdGearCord,
                                  u16LocalTemperatureCalcPara,
                                  16);
         }
         else
         {
            EngSt_EngSpdLimThd =
               MATHSRV_u8Interp2d(&EngSt_EngSpdLimHiThd_M[0][0],
                                  u16LocalCoPtnoEgdGearCord,
                                  u16LocalTemperatureCalcPara,
                                  16);
         }
      }
   }
   /* Caluclus of ESLim_nLoFuCutOff */
   u16LocalnoEgdGearCordInterp = MATHSRV_u16Interp1d(EngSt_nLoFuCutOffHys_T,
                                                     u16LocalCoPtnoEgdGearCord);
   if (u16LocalnoEgdGearCordInterp < (uint16)(EngSt_EngSpdLimThd * 32))
   {
      u16LocalESLim_nLoFuCutOff = (uint16)( (EngSt_EngSpdLimThd * 32)
                                          - u16LocalnoEgdGearCordInterp);
   }
   else
   {
      u16LocalESLim_nLoFuCutOff = 0;
   }
   VEMS_vidSET(ESLim_nLoFuCutOff, u16LocalESLim_nLoFuCutOff);

   /* Production du EngSt_bEntryOVERSPEED_FCO*/
   u16LocalRegimeMoteur32Temp = (uint16)(u8LocalRegime_moteur_32 + 255);
   u8LocalEngStEngSpdLimThdPara =
      MATHSRV_u8Interp1d(EngSt_EngSpdLimThdHys_T, u16LocalCoPtnoEgdGearCord);
   u16LocalEngStTemp =
      (uint16)(( EngSt_EngSpdLimThd - u8LocalEngStEngSpdLimThdPara) + 255);
   u16LocalEngStEngSpdLimThdTemp = (uint16)(EngSt_EngSpdLimThd + 255);
   MATHSRV_vidSchmittTriggerU16(u16LocalRegimeMoteur32Temp,
                                u16LocalEngStTemp,
                                u16LocalEngStEngSpdLimThdTemp,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &EngSt_bEntryOVERSPEED_FCO);

   /*Production du EngSt_ctOverSpdFCO et ESLim_tiCntOverNEngMaxTmp*/
   if (EngSt_bEntryOVERSPEED_FCO != 0)
   {
      u32LocalSum = (uint32)(EngSt_ctOverSpdFCO + 1);
      EngSt_ctOverSpdFCO = (uint16)MATHSRV_udtMIN(u32LocalSum, 65535);

      u32LocalSum = (uint32)(ESLim_tiCntOverNEngMaxTmp + 1);
      ESLim_tiCntOverNEngMaxTmp = (uint16)MATHSRV_udtMIN(u32LocalSum, 500);
   }
   else
   {
      EngSt_ctOverSpdFCO = 0;
   }

   /*Production du EngSt_bMonRunRedESLim*/
   EngSt_bMonRunRedESLim = EngSt_bEntryOVERSPEED_FCO;

   /* Production du ESLim_bAcvFuCutOff */
   u16LocalESLimFuCutOff = (uint16)( EngSt_EngSpdLimThd
                                   + ( ( 8160 - u16LocalnoEgdGearCordInterp)
                                     / 32));
   VEMS_vidGET(ESLim_bAcvFuCutOff, bLocalESLim_bAcvFuCutOff);
   MATHSRV_vidSchmittTriggerU16(u16LocalRegimeMoteur32Temp,
                                u16LocalESLimFuCutOff,
                                u16LocalEngStEngSpdLimThdTemp,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &bLocalESLim_bAcvFuCutOff);
   VEMS_vidSET(ESLim_bAcvFuCutOff, bLocalESLim_bAcvFuCutOff);

   /* Production du ESLim_tiCntOverNEngMaxTmp */
   VEMS_vidGET(ESLim_tiCntOverNEngMax, u16LocalESLim_tiCntOverNEngMax2);
   if (ESLim_tiCntOverNEngMaxTmp >= 500)
   {
      u32LocalESLim_tiCntOverNEngMax =
         (uint32)(u16LocalESLim_tiCntOverNEngMax2 + 1);
      u16LocalESLim_tiCntOverNEngMax2 =
         (uint16)MATHSRV_udtMIN(u32LocalESLim_tiCntOverNEngMax, 65535);
      ESLim_tiCntOverNEngMaxTmp = 0;
   }

   /*Production de ESLim_tiCntOverNEngMax*/
   VEMS_vidGET(Afts_bRstESLim, bLocalAfts_bRstESLim);
   VEMS_vidGET(Srv_bBypCntOverNEngMax, bLocalSrv_bBypCntOverNEngMax);
   if (bLocalAfts_bRstESLim !=0)
   {
      u16LocalESLim_tiCntOverNEngMax = 0;
   }
   else
   {
      if (  (bLocalSrv_bBypCntOverNEngMax != 0)
         && (ENGRUNST_Srv_bByCnOvrNEngMx_prev == 0))
      {
         VEMS_vidGET(Srv_tiCntOverNEngMax, u16LocalSrv_tiCntOverNEngMax);
         u16LocalESLim_tiCntOverNEngMax = u16LocalSrv_tiCntOverNEngMax;
      }
      else
      {
         u16LocalESLim_tiCntOverNEngMax = u16LocalESLim_tiCntOverNEngMax2;
      }
   }
   VEMS_vidSET(ESLim_tiCntOverNEngMax, u16LocalESLim_tiCntOverNEngMax);

   /*Production du ESLim_bAcvRedESLimProtMec*/

   if (u16LocalESLim_tiCntOverNEngMax > ESLim_tiMaxOverNEngMax_C)
   {
      ESLim_bAcvRedESLimProtMec = 1;
   }
   else
   {
      ESLim_bAcvRedESLimProtMec = 0;
   }
   ENGRUNST_Srv_bByCnOvrNEngMx_prev = bLocalSrv_bBypCntOverNEngMax;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidEngrunStInterface                              */
/* !Description :  Cette fonction décrit l'interfaçage des variables          */
/*                 Manage_isc_closed_loop et Ext_bIdlAcv avec le flag moteur  */
/*                 sous contrôle du régulateur et consigne ralenti active,    */
/*                 ainsi que l'interfaçage de Ext_stEngrun avec               */
/*                 Engine_running_state                                       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st07 Engine_running_state;                                          */
/*  input boolean EngSt_bEngNOnIdl;                                           */
/*  input bool ERUN_NORMAL_RUNNING;                                           */
/*  input bool ERUN_FULL_LOAD;                                                */
/*  input bool ERUN_ENGINE_OVERSPEED_FCO;                                     */
/*  input bool ERUN_ON_IDLE;                                                  */
/*  input bool ERUN_ENGINE_OVERRUN_FCO;                                       */
/*  output boolean Manage_isc_closed_loop;                                    */
/*  output boolean Ext_bIdlAcv;                                               */
/*  output uint8 Ext_stEngrun;                                                */
/*  output uint8 Engine_running_state_swc;                                    */
/*  output bool ERUN_NORMAL_RUNNING;                                          */
/*  output bool ERUN_FULL_LOAD;                                               */
/*  output bool ERUN_ENGINE_OVERSPEED_FCO;                                    */
/*  output bool ERUN_ON_IDLE;                                                 */
/*  output bool ERUN_ENGINE_OVERRUN_FCO;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidEngrunStInterface(void)
{
   boolean bLocalEngSt_bEngNOnIdl;
   uint8   u8LocalEngine_running_state;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(EngSt_bEngNOnIdl, bLocalEngSt_bEngNOnIdl);

   VEMS_vidSET(Manage_isc_closed_loop, bLocalEngSt_bEngNOnIdl);
   VEMS_vidSET(Ext_bIdlAcv, bLocalEngSt_bEngNOnIdl);
   switch (u8LocalEngine_running_state)
   {
      case ERUN_NORMAL_RUNNING:
         VEMS_vidSET(Ext_stEngrun, Ext_stEngrunNorm_SC);
         VEMS_vidSET(Engine_running_state_swc, ERUN_NORMAL_RUNNING);
         break;

      case ERUN_FULL_LOAD:
         VEMS_vidSET(Ext_stEngrun, Ext_stEngMaxLd_SC);
         VEMS_vidSET(Engine_running_state_swc, ERUN_FULL_LOAD);
         break;

      case ERUN_ENGINE_OVERSPEED_FCO:
         VEMS_vidSET(Ext_stEngrun, Ext_stEngOverSpd_SC);
         VEMS_vidSET(Engine_running_state_swc, ERUN_ENGINE_OVERSPEED_FCO);
         break;

      case ERUN_ON_IDLE:
         VEMS_vidSET(Ext_stEngrun, Ext_stEngIdl_SC);
         VEMS_vidSET(Engine_running_state_swc, ERUN_ON_IDLE);
         break;

      case ERUN_ENGINE_OVERRUN_FCO:
         VEMS_vidSET(Ext_stEngrun, Ext_stEngOverRun_SC);
         VEMS_vidSET(Engine_running_state_swc, ERUN_ENGINE_OVERRUN_FCO);
         break;
      case ERUN_ENGINE_OVERSPEED_TQLIM:
         VEMS_vidSET(Ext_stEngrun, Ext_stEngOverSpdTqLim_SC);
         VEMS_vidSET(Engine_running_state_swc, ERUN_ENGINE_OVERSPEED_TQLIM);
         break;

      default:
         VEMS_vidSET(Ext_stEngrun, Ext_stEngrunNorm_SC);
         VEMS_vidSET(Engine_running_state_swc, ERUN_NORMAL_RUNNING);
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGRUNST_vidKeyOnCalc                                      */
/* !Description :  Au Key-On on vient lire la valeur du compteur de temps     */
/*                 cumulé passé en sur-régime et on vérifie si il est         */
/*                 supérieur au seuil défini par calibration.                 */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 ESLim_tiCntOverNEngMax;                                      */
/*  input uint16 ESLim_tiMaxOverNEngMax_C;                                    */
/*  output boolean ESLim_bAcvRedESLimProtMecKOn;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGRUNST_vidKeyOnCalc(void)
{
   uint16  u16LocalESLim_tiCntOverNEngMax;


   VEMS_vidGET(ESLim_tiCntOverNEngMax, u16LocalESLim_tiCntOverNEngMax);
   if (u16LocalESLim_tiCntOverNEngMax >= ESLim_tiMaxOverNEngMax_C)
   {
      ESLim_bAcvRedESLimProtMecKOn = 1;
   }
   else
   {
      ESLim_bAcvRedESLimProtMecKOn = 0;
   }
}

/*------------------------------- End of file --------------------------------*/