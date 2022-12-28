/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKADPCOR                                               */
/* !Description     : KNKADPCOR component.                                    */
/*                                                                            */
/* !Module          : KNKADPCOR                                               */
/* !Description     : CORRECTION AUTO-ADAPTATIVE DU CLIQUETIS.                */
/*                                                                            */
/* !File            : KNKADPCOR_FCT1.C                                        */
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
/*   1 / KNKADPCOR_vidInitOutput                                              */
/*   2 / KNKADPCOR_vidInitMaxAdvance                                          */
/*   3 / KNKADPCOR_vidLowTemperature                                          */
/*   4 / KNKADPCOR_vidHighTemperature                                         */
/*   5 / KNKADPCOR_vidEngSpdEngLoadSaving                                     */
/*   6 / KNKADPCOR_vidEngSpdStable                                            */
/*   7 / KNKADPCOR_vidEngLoadStable                                           */
/*   8 / KNKADPCOR_vidAdaptWriteCond                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5154831 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKADPCOR/KNKADPCOR_FCT1.C_v$*/
/* $Revision::   1.16     $$Author::   wbouach        $$Date::   09 May 2012 $*/
/* $Author::   wbouach                                $$Date::   09 May 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKADPCOR.h"
#include "KNKADPCOR_L.h"
#include "KNKADPCOR_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des variables produites par la   */
/*                 spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output boolean Av_bmax_autorise_adaptation;                               */
/*  output boolean KNKADPCOR_bZone_critiquePrev;                              */
/*  output boolean KNKADPCOR_bRFuDetRstAdpPrev;                               */
/*  output uint16 KNKADPCOR_u16Ext_rAirLdPrev;                                */
/*  output uint16 KNKADPCOR_u16Regime_moteurPrev;                             */
/*  output uint8 KNKADPCOR_u8adapt_zone_fctPrev;                              */
/*  output boolean KNKADPCOR_bBvmp_inh_cliqacqPrev;                           */
/*  output boolean Knk_adapt_engine_stable;                                   */
/*  output boolean Knk_adapt_n_stable;                                        */
/*  output uint16 Knk_adapt_stable_counter;                                   */
/*  output boolean KNKADPCOR_boutputHysteresis1;                              */
/*  output boolean KNKADPCOR_boutputHysteresis2;                              */
/*  output boolean KNKADPCOR_boutputHysteresis3;                              */
/*  output boolean KNKADPCOR_boutputHysteresis4;                              */
/*  output sint8 Av_bmax_corr_adapt_anti_k[15];                               */
/*  output sint16 Av_bmax_adapt_anti_k_zone_cyl[4];                           */
/*  output uint8 KNKADPCOR_u8KnkAdaptZoneCylPrev[4];                          */
/*  output sint16 KnkMgt_agIgKnkAdpOfsCylFineRsl[4];                          */
/*  output boolean KnkAdpCor_bTreatZoneTran[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidInitOutput(void)
{
   uint8  u8LocalIndex;


   Av_bmax_autorise_adaptation = 0;
   KNKADPCOR_bZone_critiquePrev = 0;
   KNKADPCOR_bRFuDetRstAdpPrev = 0;
   KNKADPCOR_u16Ext_rAirLdPrev = 0;
   KNKADPCOR_u16Regime_moteurPrev = 0;
   KNKADPCOR_u8adapt_zone_fctPrev = 0;
   KNKADPCOR_bBvmp_inh_cliqacqPrev = 0;
   Knk_adapt_engine_stable = 0;
   Knk_adapt_n_stable = 0;
   Knk_adapt_stable_counter = 0;
   KNKADPCOR_boutputHysteresis1 = 0;
   KNKADPCOR_boutputHysteresis2 = 0;
   KNKADPCOR_boutputHysteresis3 = 0;
   KNKADPCOR_boutputHysteresis4 = 0;
   /*5_lecture_adaptatifs*/

   for (u8LocalIndex = 0; u8LocalIndex < 15; u8LocalIndex ++)
   {
      VEMS_vidSET1DArrayElement(Av_bmax_corr_adapt_anti_k, u8LocalIndex, 0);
   }
   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex ++)
   {
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl, u8LocalIndex, 0);
      KNKADPCOR_u8KnkAdaptZoneCylPrev[u8LocalIndex] = 0;
      KnkMgt_agIgKnkAdpOfsCylFineRsl[u8LocalIndex] = 0;
      KnkAdpCor_bTreatZoneTran[u8LocalIndex] = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidInitMaxAdvance                                */
/* !Description :  Les adaptatifs sont mémorisés en EEPROM à la coupure de    */
/*                 contact durant le power latch. Ils ne sont restitués au    */
/*                 reset que si le moteur est encore chaud.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void KNKADPCOR_vidLowTemperature();                           */
/*  extf argret void KNKADPCOR_vidHighTemperature();                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Temperature_eau;                                              */
/*  input uint16 Engine_load_5_bkpt_map[4];                                   */
/*  input uint8 Regime_moteur_6_bkpt_map[6];                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Av_bmax_retard_delai_map[16];                                */
/*  input uint16 Av_bmax_decrem_delai_map[16];                                */
/*  input uint16 Knk_adapt_n_max;                                             */
/*  input uint8 Av_bmax_adapt_anti_k_teau_seuil;                              */
/*  output uint16 Knk_adapt_load_min;                                         */
/*  output uint16 Knk_adapt_load_max;                                         */
/*  output uint16 Knk_adapt_n_min;                                            */
/*  output uint16 Knk_adapt_n_max;                                            */
/*  output uint8 Knk_adapt_nb_n_zone;                                         */
/*  output uint8 Knk_adapt_n_zone;                                            */
/*  output uint8 Knk_adapt_load_zone;                                         */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl1[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl2[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl3[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl4[15];                          */
/*  output sint8 Av_bmax_cor_adpt_anti_k_raw_cyl[4];                          */
/*  output uint8 Knk_adapt_zone_fct_cyl[4];                                   */
/*  output sint16 Av_bmax_adapt_avant_moy_cyl[4];                             */
/*  output sint16 Av_bmax_adap_avt_slew_rate_cyl[4];                          */
/*  output sint8 Av_bmax_corr_appliquee_cyl[4];                               */
/*  output uint16 Av_bmax_retard_cptr_cyl[4];                                 */
/*  output uint16 Av_bmax_decrem_cptr_cyl[4];                                 */
/*  output uint8 KnkMgt_prm_agIgKnkAdpOfsCyl[6];                              */
/*  output boolean Av_bmax_ena_temperature_basse;                             */
/*  output boolean Av_bmax_ena_temperature_haute;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidInitMaxAdvance(void)
{
   /* 0_init_max_advance */
   uint8  u8LocalIndex;
   uint8  u8LocalTemperature_eau;
   uint8  u8LocalKnk_adapt_n_max;
   uint16 u16LocalCalcPara;
   uint16 u16LocalVarRegime;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalAv_bmax_retard;
   uint16 u16LocalAv_bmax_decrem;
   uint32 u32LocalVarRegime;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   Knk_adapt_load_min = Engine_load_5_bkpt_map[0];
   Knk_adapt_load_max = Engine_load_5_bkpt_map[3];
   Knk_adapt_n_min = (uint16)(32 * Regime_moteur_6_bkpt_map[0]);
   Knk_adapt_n_max = (uint16)(32 * Regime_moteur_6_bkpt_map[5]);
   u32LocalVarRegime = (uint32)(u16LocalRegime_moteur * 8);
   u16LocalVarRegime = (uint16)MATHSRV_udtMIN(u32LocalVarRegime ,65535);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                   u16LocalVarRegime,
                                                   16);
   u16LocalAv_bmax_retard =
      MATHSRV_u16Interp1d(Av_bmax_retard_delai_map, u16LocalCalcPara);
   u16LocalAv_bmax_decrem =
      MATHSRV_u16Interp1d(Av_bmax_decrem_delai_map, u16LocalCalcPara);
   u8LocalKnk_adapt_n_max = (uint8)(Knk_adapt_n_max / 32);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_6_bkpt_map,
                                                  u8LocalKnk_adapt_n_max,
                                                  6);
   Knk_adapt_nb_n_zone = (uint8)(u16LocalCalcPara >> 8);
   Knk_adapt_n_zone = 0;
   Knk_adapt_load_zone = 0;
   for (u8LocalIndex = 0; u8LocalIndex < 15; u8LocalIndex ++)
   {
      Av_bmax_corr_adapt_anti_k_cyl1[u8LocalIndex] = 0;
      Av_bmax_corr_adapt_anti_k_cyl2[u8LocalIndex] = 0;
      Av_bmax_corr_adapt_anti_k_cyl3[u8LocalIndex] = 0;
      Av_bmax_corr_adapt_anti_k_cyl4[u8LocalIndex] = 0;
      if (u8LocalIndex < 4)
      {
         Av_bmax_cor_adpt_anti_k_raw_cyl[u8LocalIndex] = 0;
         Knk_adapt_zone_fct_cyl[u8LocalIndex] = 0;
         Av_bmax_adapt_avant_moy_cyl[u8LocalIndex] = 0;
         Av_bmax_adap_avt_slew_rate_cyl[u8LocalIndex] = 0;
         VEMS_vidSET1DArrayElement(Av_bmax_corr_appliquee_cyl, u8LocalIndex, 0);
         Av_bmax_retard_cptr_cyl[u8LocalIndex] = u16LocalAv_bmax_retard;
         Av_bmax_decrem_cptr_cyl[u8LocalIndex] = u16LocalAv_bmax_decrem;
      }
      if (u8LocalIndex < 6)
      {
         VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkAdpOfsCyl,
                                   u8LocalIndex,
                                   96);
      }
   }
   if (u8LocalTemperature_eau <= Av_bmax_adapt_anti_k_teau_seuil)
   {
      Av_bmax_ena_temperature_basse = 1;
      Av_bmax_ena_temperature_haute = 0;
      /* 0_temperature_basse */
      KNKADPCOR_vidLowTemperature();
   }
   else
   {
      Av_bmax_ena_temperature_haute = 1;
      Av_bmax_ena_temperature_basse = 0;
      /* 1_temperature_haute */
      KNKADPCOR_vidHighTemperature();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidLowTemperature                                */
/* !Description :  Les adaptatifs sont mémorisés en EEPROM à la coupure de    */
/*                 contact durant le power latch. Ils ne sont restitués au    */
/*                 reset que si le moteur est encore chaud.                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output sint16 Av_bmax_adapt_anti_k_cyl1[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl2[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl3[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl4[15];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidLowTemperature(void)
{
   /* 0_temperature_basse */
   uint8  u8LocalIndex;


   for (u8LocalIndex = 0; u8LocalIndex < 15; u8LocalIndex ++)
   {
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl1, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl2, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl3, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl4, u8LocalIndex, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidHighTemperature                               */
/* !Description :  Les adaptatifs sont mémorisés en EEPROM à la coupure de    */
/*                 contact durant le power latch. Ils ne sont restitués au    */
/*                 reset que si le moteur est encore chaud.                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input sint16 Av_bmax_adapt_anti_k_cyl1[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl2[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl3[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl4[15];                               */
/*  input uint8 Av_bmax_adapt_anti_k_gain;                                    */
/*  output sint16 Av_bmax_adapt_anti_k_cyl1[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl2[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl3[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl4[15];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidHighTemperature(void)
{
   /* 1_temperature_haute */
   uint8  u8LocalIndex;
   sint16 s16LocalAv_bmax_anti_k_cyl_1;
   sint16 s16LocalAv_bmax_anti_k_cyl_2;
   sint16 s16LocalAv_bmax_anti_k_cyl_3;
   sint16 s16LocalAv_bmax_anti_k_cyl_4;


   for (u8LocalIndex = 0; u8LocalIndex < 15; u8LocalIndex ++)
   {
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl1,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_1);
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl2,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_2);
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl3,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_3);
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl4,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_4);

      s16LocalAv_bmax_anti_k_cyl_1 =
         (sint16)( (sint32)( s16LocalAv_bmax_anti_k_cyl_1
                           * Av_bmax_adapt_anti_k_gain) / 256);
      s16LocalAv_bmax_anti_k_cyl_2 =
         (sint16)( (sint32)( s16LocalAv_bmax_anti_k_cyl_2
                           * Av_bmax_adapt_anti_k_gain) / 256);
      s16LocalAv_bmax_anti_k_cyl_3 =
         (sint16)( (sint32)( s16LocalAv_bmax_anti_k_cyl_3
                           * Av_bmax_adapt_anti_k_gain) / 256);
      s16LocalAv_bmax_anti_k_cyl_4 =
         (sint16)( (sint32)( s16LocalAv_bmax_anti_k_cyl_4
                           * Av_bmax_adapt_anti_k_gain) / 256);

      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl1,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_1);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl2,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_2);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl3,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_3);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl4,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_4);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidEngSpdEngLoadSaving                           */
/* !Description :  Au PMB admission d’un cylindre, sont calculées l’avance à  */
/*                 l’allumage pour ce cylindre et l’avance pour le cylindre   */
/*                 suivant. Les corrections d’avance anti-cliquetis doivent   */
/*                 donc être mises à jour 2 PMB admission avant le PMH        */
/*                 combustion.                                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Ext_rAirLd;                                                  */
/*  output uint16 Knk_regime_moteur_cyl[4];                                   */
/*  output uint16 Knk_engine_air_load_cyl[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidEngSpdEngLoadSaving(void)
{
   /* 11_memo_regime_charge */
   uint8  u8LocalEng_noCmbCyl;
   uint16 u16LocalExtrAirLd;
   uint16 u16LocalEngineSpeed;


   VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
   switch (u8LocalEng_noCmbCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         VEMS_vidGET(Regime_moteur, u16LocalEngineSpeed);
         Knk_regime_moteur_cyl[u8LocalEng_noCmbCyl - 1] =
         (uint16)MATHSRV_udtMIN(u16LocalEngineSpeed, 8191);

         VEMS_vidGET(Ext_rAirLd, u16LocalExtrAirLd);
         Knk_engine_air_load_cyl[u8LocalEng_noCmbCyl - 1] = u16LocalExtrAirLd;
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidEngSpdStable                                  */
/* !Description :  Au PMB admission d’un cylindre, sont calculées l’avance à  */
/*                 l’allumage pour ce cylindre (Avance_finale) et l’avance    */
/*                 pour le cylindre suivant Les corrections d’avance          */
/*                 anti-cliquetis doivent donc être mises à jour 2 PMB        */
/*                 admission avant le PMH combustion.                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 KNKADPCOR_u16Regime_moteurPrev;                              */
/*  input uint16 Knk_adapt_n_stab_thresh;                                     */
/*  output boolean Knk_adapt_n_stable;                                        */
/*  output uint16 KNKADPCOR_u16Regime_moteurPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidEngSpdStable(void)
{
   /* 1_n_stable */
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalCalcRegime_moteur;
   sint32 s32LocalRegime_moteur;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   s32LocalRegime_moteur = (sint32)( u16LocalRegime_moteur
                                   - KNKADPCOR_u16Regime_moteurPrev);
   u16LocalCalcRegime_moteur = (uint16)MATHSRV_udtABS(s32LocalRegime_moteur);
   if (u16LocalCalcRegime_moteur <= Knk_adapt_n_stab_thresh)
   {
      Knk_adapt_n_stable = 1;
   }
   else
   {
      Knk_adapt_n_stable = 0;
   }
   KNKADPCOR_u16Regime_moteurPrev =
      (uint16)MATHSRV_udtMIN(u16LocalRegime_moteur, 8191);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidEngLoadStable                                 */
/* !Description :  Le booléen Knk_adapt_n_stable passe à 1 lorsque le régime  */
/*                 moteur est considéré stable, c'est-à-dire lorsque ses      */
/*                 variations sont inférieures au critère                     */
/*                 Knk_adapt_n_stab_thresh.                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 KNKADPCOR_u16Ext_rAirLdPrev;                                 */
/*  input uint16 Knk_adapt_load_stab_thresh;                                  */
/*  input boolean Knk_adapt_load_stable;                                      */
/*  input boolean Knk_adapt_n_stable;                                         */
/*  input uint16 Knk_adapt_stable_counter;                                    */
/*  input uint16 Knk_adapt_stable_delay;                                      */
/*  output uint16 KNKADPCOR_u16Ext_rAirLdPrev;                                */
/*  output boolean Knk_adapt_load_stable;                                     */
/*  output uint16 Knk_adapt_stable_counter;                                   */
/*  output boolean Knk_adapt_engine_stable;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidEngLoadStable(void)
{
   /* 2_load_stable */
   uint16 u16LocalAbs;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalKnk_adapt_stable_counter;
   sint32 s32LocalExt_rAirLd;


   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   s32LocalExt_rAirLd = (sint32)( u16LocalExt_rAirLd
                                - KNKADPCOR_u16Ext_rAirLdPrev);
   u16LocalAbs = (uint16)MATHSRV_udtABS(s32LocalExt_rAirLd);
   KNKADPCOR_u16Ext_rAirLdPrev = u16LocalExt_rAirLd;
   if (u16LocalAbs <= Knk_adapt_load_stab_thresh)
   {
      Knk_adapt_load_stable = 1;
   }
   else
   {
      Knk_adapt_load_stable = 0;
   }
   if (  (Knk_adapt_load_stable != 0)
      && (Knk_adapt_n_stable != 0))
   {
      if (Knk_adapt_stable_counter > 0)
      {
         u16LocalKnk_adapt_stable_counter = (uint16)( Knk_adapt_stable_counter
                                                    - 1);
      }
      else
      {
         u16LocalKnk_adapt_stable_counter = 0;
      }
   }
   else
   {
      u16LocalKnk_adapt_stable_counter  = Knk_adapt_stable_delay;
   }
   Knk_adapt_stable_counter =
      (uint16)MATHSRV_udtMIN(u16LocalKnk_adapt_stable_counter, 499);
   if (Knk_adapt_stable_counter == 0)
   {
      Knk_adapt_engine_stable = 1;
   }
   else
   {
      Knk_adapt_engine_stable = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidAdaptWriteCond                                */
/* !Description :  La décrémentation ou l'incrémentation des adaptatifs est   */
/*                 figée si : une panne anti-cliquetis apparaît, un changement*/
/*                 de rapport effectué en BVA et BVMP, le point de            */
/*                 fonctonnement n'est pas en zone critique, le régime et la  */
/*                 charge sont en transitoire.                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Bv_changement_rapport;                                      */
/*  input boolean Bvmp_inh_cliq_acquisition;                                  */
/*  input uint8 Ids_decoll_inhib_cliq_counter;                                */
/*  input boolean Presence_bva;                                               */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Zone_critique;                                              */
/*  input uint8 Av_bmax_regime_moteur_seuil;                                  */
/*  input boolean Knk_adapt_engine_stable;                                    */
/*  output boolean Av_bmax_autorise_adaptation;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidAdaptWriteCond(void)
{
   /* 3_cond_ecriture_adapt */
   boolean bLocalFRM_bInhAutAdp;
   boolean bLocalBv_changement_rapport;
   boolean bLocalBvmp_inh_cliq_acquisition;
   boolean bLocalPresence_bva;
   boolean bLocalZone_critique;
   uint8   u8LocalIds_decoll_inh_cliq_cntr;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Bv_changement_rapport, bLocalBv_changement_rapport);
   VEMS_vidGET(Bvmp_inh_cliq_acquisition, bLocalBvmp_inh_cliq_acquisition);
   VEMS_vidGET(Ids_decoll_inhib_cliq_counter, u8LocalIds_decoll_inh_cliq_cntr);
   VEMS_vidGET(Presence_bva, bLocalPresence_bva);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Zone_critique, bLocalZone_critique);
   bLocalFRM_bInhAutAdp = GDGAR_bGetFRM(FRM_FRM_INHAUTADP);
   if (  (bLocalBvmp_inh_cliq_acquisition == 0)
      && (bLocalZone_critique != 0)
      && (u8LocalIds_decoll_inh_cliq_cntr == 0)
      && (  (bLocalBv_changement_rapport == 0)
         || (bLocalPresence_bva == 0))
      && (u16LocalRegime_moteur >= (uint16)( Av_bmax_regime_moteur_seuil * 32))
      && (bLocalFRM_bInhAutAdp == 0)
      && (Knk_adapt_engine_stable != 0))
   {
      Av_bmax_autorise_adaptation = 1;
   }
   else
   {
      Av_bmax_autorise_adaptation = 0;
   }
}
/*---------------------------- end of file -----------------------------------*/