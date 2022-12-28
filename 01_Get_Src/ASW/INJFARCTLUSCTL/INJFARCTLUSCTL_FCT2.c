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
/* !File            : INJFARCTLUSCTL_FCT2.c                                   */
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
/*   1 / INJFARCTLUSCTL_vidFuncCalAttGain                                     */
/*   2 / INJFARCTLUSCTL_vidTransDetect                                        */
/*   3 / INJFARCTLUSCTL_vidLbdaTrans                                          */
/*   4 / INJFARCTLUSCTL_vidLbdaNotTrans                                       */
/*   5 / INJFARCTLUSCTL_vidLdbTrGainAttnu                                     */
/*   6 / INJFARCTLUSCTL_vidNotTrGainAttnu                                     */
/*   7 / INJFARCTLUSCTL_vidCounter                                            */
/*   8 / INJFARCTLUSCTL_vidCalcGain                                           */
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
/* !Function    :  INJFARCTLUSCTL_vidFuncCalAttGain                           */
/* !Description :  Pour résoudre le problème de l'EPT A806 n° 602 ,on choisit */
/*                 de diminuer l’influence de la correction de richesse lors  */
/*                 des transitoires de décollage à froid en lui appliquant un */
/*                 gain d’atténuation.                                        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidTransDetect();                         */
/*  extf argret void INJFARCTLUSCTL_vidCounter();                             */
/*  extf argret void INJFARCTLUSCTL_vidCalcGain();                            */
/*  input uint16 Lbda_maintien_attenuation_count;                             */
/*  input boolean Lbda_transitoire_detect;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidFuncCalAttGain(void)
{
   INJFARCTLUSCTL_vidTransDetect();
   if (  (Lbda_maintien_attenuation_count > 0)
      && (Lbda_transitoire_detect == 0))
   {
      INJFARCTLUSCTL_vidCounter();
   }
   INJFARCTLUSCTL_vidCalcGain();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidTransDetect                              */
/* !Description :  La détection de transitoire sur le régime et la charge est */
/*                 faite par le booléen ‘Ldba_transitoire_detect’ sur un      */
/*                 seuil haut. Pour éviter toutes oscillations, ce booléen est*/
/*                 remis à 0 sur un seuil bas                                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidLbdaTrans();                           */
/*  extf argret void INJFARCTLUSCTL_vidLbdaNotTrans();                        */
/*  extf argret void INJFARCTLUSCTL_vidLdbTrGainAttnu();                      */
/*  extf argret void INJFARCTLUSCTL_vidNotTrGainAttnu();                      */
/*  input sint8 Engine_air_load_derivate;                                     */
/*  input sint8 Engine_speed_derivate;                                        */
/*  input uint8 Lbda_transitoire_eal_seuil_haut;                              */
/*  input uint8 Lbda_transitoire_reg_seuil_haut;                              */
/*  input uint8 Lbda_transitoire_eal_seuil_bas;                               */
/*  input uint8 Lbda_transitoire_reg_seuil_bas;                               */
/*  input boolean Lbda_transitoire_detect;                                    */
/*  input boolean Lbda_transitoire_detectPrev;                                */
/*  output boolean Lbda_transitoire_detectPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidTransDetect(void)
{
   uint8 u8LocalEngineair;
   uint8 u8LocalEnginespeed;
   sint8 s8LocalEngine_speed_derivate;


   u8LocalEngineair = (uint8)MATHSRV_udtABS(Engine_air_load_derivate);
   VEMS_vidGET(Engine_speed_derivate, s8LocalEngine_speed_derivate);
   u8LocalEnginespeed = (uint8) MATHSRV_udtABS(s8LocalEngine_speed_derivate);
   if (  (u8LocalEngineair > Lbda_transitoire_eal_seuil_haut)
      || (u8LocalEnginespeed > Lbda_transitoire_reg_seuil_haut))
   {
      INJFARCTLUSCTL_vidLbdaTrans();
   }
   if (  (u8LocalEngineair <= Lbda_transitoire_eal_seuil_bas)
      && (u8LocalEnginespeed <= Lbda_transitoire_reg_seuil_bas))
   {
      INJFARCTLUSCTL_vidLbdaNotTrans();
   }
   if (Lbda_transitoire_detect != 0)
   {
      if (Lbda_transitoire_detectPrev == 0)
      {
         INJFARCTLUSCTL_vidLdbTrGainAttnu();
      }
   }
   else
   {
      if (Lbda_transitoire_detectPrev != 0)
      {
         INJFARCTLUSCTL_vidNotTrGainAttnu();
      }
   }
   Lbda_transitoire_detectPrev = Lbda_transitoire_detect;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLbdaTrans                                */
/* !Description :  La détection de transitoire sur le régime et la charge .   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Lbda_transitoire_detect;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLbdaTrans(void)
{
   Lbda_transitoire_detect = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLbdaNotTrans                             */
/* !Description :  Le booléen ‘Ldba_transitoire_detect’ est remis à 0 sur un  */
/*                 seuil bas pour éviter toutes oscillations.                 */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Lbda_transitoire_detect;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLbdaNotTrans(void)
{
   Lbda_transitoire_detect = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLdbTrGainAttnu                           */
/* !Description :  Appliquer  un gain d’atténuation pour diminuer l’influence */
/*                 de la correction de richesse lors des transitoires  de     */
/*                 décollage à froid .                                        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Lbda_active_gain_attenu_rich;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLdbTrGainAttnu(void)
{
   Lbda_active_gain_attenu_rich = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidNotTrGainAttnu                           */
/* !Description :  Le calcul des gains d’atténuation en fonction de la        */
/*                 température d’eau                                          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean Cf_bInhFlex;                                                */
/*  input uint8 Temperature_eau_InjCtl_bkpt_map[16];                          */
/*  input uint16 Lbda_maintien_attenu_delay_map[16];                          */
/*  input uint16 Lbda_maintien_attenu_delay_flex;                             */
/*  input uint16 Lbda_maint_att_dly_pond_flex;                                */
/*  output uint16 Lbda_maintien_attenuation_count;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidNotTrGainAttnu(void)
{
   boolean bLocalCf_bInhFlex;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalLbdaMaintAtteDlyPndFlx;
   uint16  u16LocalPara;
   uint16  u16LocalRate;
   uint16  u16LocalInterp;
   uint16  u16LocalLbdaMaintAtteDlyFlx;
   sint32  s32LocalCalc;


   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
   u16LocalPara =MATHSRV_u16CalcParaIncAryU8(Temperature_eau_InjCtl_bkpt_map,
                                             u8LocalTemperature_eau,
                                             16);
   u16LocalInterp =
      MATHSRV_u16Interp1d(Lbda_maintien_attenu_delay_map, u16LocalPara);
   if (bLocalCf_bInhFlex != 0)
   {
      Lbda_maintien_attenuation_count =
         (uint16)MATHSRV_udtMIN(u16LocalInterp, 59999);
   }
   else
   {
      VEMS_vidGET(Lbda_maintien_attenu_delay_flex, u16LocalLbdaMaintAtteDlyFlx);
      VEMS_vidGET(Lbda_maint_att_dly_pond_flex, u16LocalLbdaMaintAtteDlyPndFlx);

      /*Barycentre */
      s32LocalCalc = (sint32)(u16LocalLbdaMaintAtteDlyFlx - u16LocalInterp);
      u16LocalRate =
         (uint16)MATHSRV_udtMIN(u16LocalLbdaMaintAtteDlyPndFlx, 256);
      if (s32LocalCalc >= 0)
      {
         s32LocalCalc = ((s32LocalCalc * u16LocalRate) + 128) / 256;
      }
      else
      {
         s32LocalCalc = ((s32LocalCalc * u16LocalRate) - 128) / 256;
      }
      s32LocalCalc = (s32LocalCalc + u16LocalInterp);
      Lbda_maintien_attenuation_count =
         (uint16)MATHSRV_udtMIN(s32LocalCalc, 59999);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCounter                                  */
/* !Description :  Le booléen ‘Lbda_active_gain_attenu_rich’ permet la prise  */
/*                 en compte des gains d’atténuation dans la boucle de        */
/*                 richesse.                                                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Lbda_maintien_attenuation_count;                             */
/*  output uint16 Lbda_maintien_attenuation_count;                            */
/*  output boolean Lbda_active_gain_attenu_rich;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCounter(void)
{
   Lbda_maintien_attenuation_count =
       (uint16)MATHSRV_udtMAX((Lbda_maintien_attenuation_count - 1), 0);
   if ( Lbda_maintien_attenuation_count == 0 )
   {
      Lbda_active_gain_attenu_rich = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidCalcGain                                 */
/* !Description :  Selon que l’on est dans une phase d’enrichissement sur un  */
/*                 step ou un lump, ou sur une phase d’appauvrissement        */
/*                 également sur un step ou un lump, on applique un gain      */
/*                 d’atténuation différent.                                   */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Temperature_eau_InjCtl_bkpt_map[16];                          */
/*  input boolean Lbda_active_gain_attenu_rich;                               */
/*  input boolean Lbda_att_transient_manu_inh;                                */
/*  input boolean Lbda_att_idle_manu_inh;                                     */
/*  input boolean Lbda_att_always_manu_inh;                                   */
/*  input uint8 Lbda_rich_attenuation_gain_map[16];                           */
/*  input uint8 Lbda_lean_attenuation_gain_map[16];                           */
/*  input boolean Cf_bInhFlex;                                                */
/*  input sint8 Lbda_rich_attenuation_gain_flex;                              */
/*  input sint8 Lbda_lean_attenuation_gain_flex;                              */
/*  input uint16 Lbda_attenuation_gain_pond_flex;                             */
/*  input uint8 Lbda_lump_step_ratio;                                         */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_moteur_InjCtl_bkpt_map[9];                             */
/*  input uint8 Lbda_step_attenuation_gain_map[16][9];                        */
/*  input uint8 Lbda_lump_attenuation_gain_map[16][9];                        */
/*  output boolean Lbda_attenuation_condition;                                */
/*  output uint8 Lbda_step_rich_gain;                                         */
/*  output uint8 Lbda_step_lean_gain;                                         */
/*  output uint8 Lbda_lump_rich_gain;                                         */
/*  output uint8 Lbda_lump_lean_gain;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidCalcGain(void)
{
   boolean bLocalCf_bInhFlex;
   uint8   u8Localinterp1;
   uint8   u8Localinterp2;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalinterpStep;
   uint8   u8LocalinterpLump;
   sint8   s8LocalLLbdaRichAttenGainFlex;
   sint8   s8LocalLLbdaLeanAttenGainFlex;
   sint8   s8LocalCalc;
   uint16  u16LocalPara;
   uint16  u16LocalParaY;
   uint16  u16LocalRate;
   uint16  u16LocalCalc;
   uint16  u16LocalLbdaAttenGainPondFlex;
   sint16  s16LocalCalc;
   sint16  s16LocalCalcul;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_InjCtl_bkpt_map,
                                              u8LocalTemperature_eau,
                                              16);
   if (  (  (Lbda_active_gain_attenu_rich != 0)
         && (Lbda_att_transient_manu_inh == 0))
      || (  (u8LocalEngine_running_state == ERUN_ON_IDLE)
         && (Lbda_att_idle_manu_inh == 0))
      || (Lbda_att_always_manu_inh == 0))
   {
      Lbda_attenuation_condition = 1;
      u8Localinterp1 = MATHSRV_u8Interp1d(Lbda_rich_attenuation_gain_map,
                                          u16LocalPara);
      u8Localinterp2 = MATHSRV_u8Interp1d(Lbda_lean_attenuation_gain_map,
                                          u16LocalPara);
      VEMS_vidGET(Cf_bInhFlex, bLocalCf_bInhFlex);
      if (bLocalCf_bInhFlex == 0)
      {
         VEMS_vidGET(Lbda_rich_attenuation_gain_flex,
                     s8LocalLLbdaRichAttenGainFlex);
         VEMS_vidGET(Lbda_lean_attenuation_gain_flex,
                     s8LocalLLbdaLeanAttenGainFlex);
         VEMS_vidGET(Lbda_attenuation_gain_pond_flex,
                     u16LocalLbdaAttenGainPondFlex);
         /*Barycentre 1*/
         s16LocalCalcul =
            (sint16)((s8LocalLLbdaRichAttenGainFlex - u8Localinterp1) + 128);
         u16LocalRate =
            (uint16)MATHSRV_udtMIN(u16LocalLbdaAttenGainPondFlex, 256);
         if (s16LocalCalcul >= 0)
         {
            s16LocalCalcul =
               (sint16)(((s16LocalCalcul * u16LocalRate) + 128) / 256);
         }
         else
         {
            s16LocalCalcul =
               (sint16)(((s16LocalCalcul * u16LocalRate) - 128) / 256);
         }

         u8Localinterp1 = (uint8)(s16LocalCalcul + u8Localinterp1);

         /*Barycentre 2*/
         s16LocalCalcul =
            (sint16)((s8LocalLLbdaLeanAttenGainFlex - u8Localinterp2) + 128);
         if (s16LocalCalcul >= 0)
         {
            s16LocalCalcul =
               (sint16)(((s16LocalCalcul * u16LocalRate) + 128) / 256);
         }
         else
         {
            s16LocalCalcul =
               (sint16)(((s16LocalCalcul * u16LocalRate) - 128) / 256);
         }
         u8Localinterp2 = (uint8)(s16LocalCalcul + u8Localinterp2);
      }
      u16LocalCalc = (uint16)(256 - u8Localinterp1);
      Lbda_step_rich_gain = (uint8)MATHSRV_udtMIN(u16LocalCalc, 255);
      u16LocalCalc = (uint16)(256 - u8Localinterp2);
      Lbda_step_lean_gain = (uint8)MATHSRV_udtMIN(u16LocalCalc, 255);

      s8LocalCalc = (sint8)(u8Localinterp1 - 128);
      if (s8LocalCalc >= 0)
      {
         s16LocalCalc =
            (sint16)(((Lbda_lump_step_ratio * s8LocalCalc) + 128) / 256);
      }
      else
      {
         s16LocalCalc =
            (sint16)(((Lbda_lump_step_ratio * s8LocalCalc) - 128) / 256);
      }
      s16LocalCalc = (sint16)(128 - s16LocalCalc);
      Lbda_lump_rich_gain = (uint8)MATHSRV_udtMIN(s16LocalCalc, 255);

      s8LocalCalc = (sint8)(u8Localinterp2 - 128);
      if (s8LocalCalc >= 0)
      {
         s16LocalCalc =
            (sint16)(((Lbda_lump_step_ratio * s8LocalCalc) + 128) / 256);
      }
      else
      {
         s16LocalCalc =
            (sint16)(((Lbda_lump_step_ratio * s8LocalCalc) - 128) / 256);
      }
      s16LocalCalc = (sint16)(128 - s16LocalCalc);
      Lbda_lump_lean_gain = (uint8)MATHSRV_udtMIN(s16LocalCalc, 255);
   }
   else
   {
      Lbda_attenuation_condition = 0;
      VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_InjCtl_bkpt_map,
                                                  u8LocalRegime_moteur_32,
                                                  9);
      u8LocalinterpStep = MATHSRV_u8Interp2d(Lbda_step_attenuation_gain_map[0],
                                             u16LocalPara,
                                             u16LocalParaY,
                                             9);
      u8LocalinterpLump = MATHSRV_u8Interp2d(Lbda_lump_attenuation_gain_map[0],
                                             u16LocalPara,
                                             u16LocalParaY,
                                             9);
      Lbda_step_rich_gain = (uint8)(u8LocalinterpStep / 2);
      Lbda_step_lean_gain = (uint8)(u8LocalinterpStep / 2);
      Lbda_lump_rich_gain = (uint8)(u8LocalinterpLump / 2);
      Lbda_lump_lean_gain = (uint8)(u8LocalinterpLump / 2);
   }
}
/*------------------------------- end of file --------------------------------*/