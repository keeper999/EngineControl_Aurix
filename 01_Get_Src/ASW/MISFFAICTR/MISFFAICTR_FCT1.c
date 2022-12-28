/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFFAICTR                                              */
/* !Description     : MISFFAICTR component.                                   */
/*                                                                            */
/* !Module          : MISFFAICTR                                              */
/* !Description     : Comptage Des Misfires Pour Les Emissions De Polluants Et*/
/*                    La Protection Composants .                              */
/*                                                                            */
/* !File            : MISFFAICTR_FCT1.C                                       */
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
/*   1 / MISFFAICTR_vidInit                                                   */
/*   2 / MISFFAICTR_vidInitOutput                                             */
/*   3 / MISFFAICTR_vidFailDetCatDam                                          */
/*   4 / MISFFAICTR_vidCatDmgCylCutMgt                                        */
/*   5 / MISFFAICTR_vidFailDetCatDamage                                       */
/*   6 / MISFFAICTR_vidHorizonCalcCatDam                                      */
/*   7 / MISFFAICTR_vidCataRoughRoadCnt                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_FCT1.C_$*/
/* $Revision::   1.16     $$Author::   wbouach        $$Date::   19 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFFAICTR.h"
#include "MISFFAICTR_L.h"
#include "MISFFAICTR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidInit                                         */
/* !Description :  Fonction d'initialisation.                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Mf_emiss_count_1_uavn0;                                     */
/*  output uint16 Mf_emiss_count_2_uavn0;                                     */
/*  output uint16 Mf_emiss_count_3_uavn0;                                     */
/*  output uint16 Mf_emiss_count_4_uavn0;                                     */
/*  output uint16 Mf_emiss_count_uavn0;                                       */
/*  output uint16 Mf_cat_dam_sum_real_uavn0;                                  */
/*  output uint16 Mf_cat_dam_wght_count_1_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_2_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_3_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_4_uavn0;                              */
/*  output uint16 Mf_cat_dam_count_uavn0;                                     */
/*  output boolean Misf_bMonWaitORngDmgCatDTC1;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTC2;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTC3;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTC4;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTCAll;                             */
/*  output boolean Flev_low_fuel_level_cat_dam;                               */
/*  output boolean Misf_bInhDetNoMisf;                                        */
/*  output boolean Misf_bAcvDetDmgCat;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidInit(void)
{
   Mf_emiss_count_1_uavn0 = 0;
   Mf_emiss_count_2_uavn0 = 0;
   Mf_emiss_count_3_uavn0 = 0;
   Mf_emiss_count_4_uavn0 = 0;
   Mf_emiss_count_uavn0 = (uint16)( Ext_noCylEng_SC
                                  * ENGINE_CYCLE_IN_EMISS_SAMPLE_L);

   Mf_cat_dam_sum_real_uavn0 = 0;
   Mf_cat_dam_wght_count_1_uavn0 = 0;
   Mf_cat_dam_wght_count_2_uavn0 = 0;
   Mf_cat_dam_wght_count_3_uavn0 = 0;
   Mf_cat_dam_wght_count_4_uavn0 = 0;
   Mf_cat_dam_count_uavn0 =(uint16)( Ext_noCylEng_SC
                                   * ENGINE_CYCLE_IN_CAT_DAM_SAMPLE_L);

   Misf_bMonWaitORngDmgCatDTC1 = 1;
   Misf_bMonWaitORngDmgCatDTC2 = 1;
   Misf_bMonWaitORngDmgCatDTC3 = 1;
   Misf_bMonWaitORngDmgCatDTC4 = 1;
   Misf_bMonWaitORngDmgCatDTCAll = 1;
   Flev_low_fuel_level_cat_dam = 1;
   Misf_bInhDetNoMisf = 1;
   Misf_bAcvDetDmgCat = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_cat_dam_det_uavb0;                                      */
/*  output boolean Mf_cat_dam_horizon_uavb0;                                  */
/*  output uint8 Mf_cat_dam_mf_rate_uavn0;                                    */
/*  output boolean Mf_cat_dam_test_achi_uavb0;                                */
/*  output boolean Mf_emiss_test_achi_uavb0;                                  */
/*  output uint16 Mf_emiss_sum_uavn0;                                         */
/*  output uint8 Mf_emiss_mf_rate_uavn0;                                      */
/*  output boolean Mf_emiss_horizon_uavb0;                                    */
/*  output boolean Mf_emiss_det_fail_uavb0;                                   */
/*  output boolean MonMisf_bClcMisfOBD;                                       */
/*  output boolean MonMisf_bAcvMonMisfOBD;                                    */
/*  output uint16 MonMisf_rMisfOBD;                                           */
/*  output uint8 Coupure_decel_progr_inj_prev;                                */
/*  output boolean MISFFAICTR_bLowFuelLevelPrev;                              */
/*  output uint8 MISFFAICTR_u8MfRoughEmiUavn0;                                */
/*  output boolean MISFFAICTR_bMfCatDamHorizonPrev;                           */
/*  output boolean MISFFAICTR_bEmissHorizonPrev;                              */
/*  output uint8 MISFFAICTR_u8MfRoughCatUavn0;                                */
/*  output uint16 Flev_low_fuel_level_count;                                  */
/*  output uint8 MISFFAICTR_u8CoupDecProgrInjprev;                            */
/*  output uint8 MISFFAICTR_u8MfCylCatDamUavbprev;                            */
/*  output uint8 MISFFAICTR_u8MfCylEmisUavb0prev;                             */
/*  output uint8 Mf_cyl_cat_dam_uavb0;                                        */
/*  output uint8 Mf_cyl_emis_uavb0;                                           */
/*  output boolean MISFFAICTR_bFuelLevelTimeOut;                              */
/*  output boolean MISFFAICTR_bMfMisfDetectedPrev;                            */
/*  output boolean MISFFAICTR_bMisfAcvDetDmgCatPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidInitOutput(void)
{
   /*initialiser les sorties */
   VEMS_vidSET(Mf_cat_dam_det_uavb0, 0);
   VEMS_vidSET(Mf_cat_dam_horizon_uavb0, 0);
   VEMS_vidSET(Mf_cat_dam_mf_rate_uavn0, 0);
   VEMS_vidSET(Mf_cat_dam_test_achi_uavb0, 0);
   VEMS_vidSET(Mf_emiss_test_achi_uavb0, 0);
   VEMS_vidSET(Mf_emiss_sum_uavn0, 0);
   VEMS_vidSET(Mf_emiss_mf_rate_uavn0, 0);
   VEMS_vidSET(Mf_emiss_horizon_uavb0, 0);
   VEMS_vidSET(Mf_emiss_det_fail_uavb0, 0);
   VEMS_vidSET(MonMisf_bClcMisfOBD, 0);
   VEMS_vidSET(MonMisf_bAcvMonMisfOBD, 0);
   VEMS_vidSET(MonMisf_rMisfOBD, 0);

   /*initialiser les variables internes */
   Coupure_decel_progr_inj_prev = 0;
   MISFFAICTR_bLowFuelLevelPrev = 0;
   MISFFAICTR_u8MfRoughEmiUavn0 = 0;
   MISFFAICTR_bMfCatDamHorizonPrev = 0;
   MISFFAICTR_bEmissHorizonPrev = 0;
   MISFFAICTR_u8MfRoughCatUavn0 =0;
   Flev_low_fuel_level_count = 0;
   MISFFAICTR_u8CoupDecProgrInjprev = 0;
   MISFFAICTR_u8MfCylCatDamUavbprev = 1;
   MISFFAICTR_u8MfCylEmisUavb0prev = 1;
   Mf_cyl_cat_dam_uavb0 = 1;
   Mf_cyl_emis_uavb0 = 1;
   MISFFAICTR_bFuelLevelTimeOut = 0;
   MISFFAICTR_bMfMisfDetectedPrev = 0;
   MISFFAICTR_bMisfAcvDetDmgCatPrev = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidFailDetCatDam                                */
/* !Description :  cette fonction effectue ses calculs à récurrence           */
/*                 Misf_EveMisf.                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_017.01                                     */
/*                 VEMS_R_09_00890_033.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidCatDmgCylCutMgt();                         */
/*  extf argret void MISFFAICTR_vidFailDetCatDamage();                        */
/*  input boolean Misf_bAcvRoughnsRoadMod;                                    */
/*  input boolean Mf_algo_cond_ok_uavb0;                                      */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean EngSt_bOscDetStab;                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean Misf_bAcvDetDmgCat;                                         */
/*  input uint8 Mf_det_cat_dam_n_max_uacn0;                                   */
/*  input boolean Misf_bTypRoughnsRoadSel_C;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidFailDetCatDam(void)
{
   boolean bLocalMf_algo_cond_ok_uavb0;
   boolean bLocalMisf_bAcvRoughnsRoadMod;
   boolean bLocalEngSt_bOscDetStab;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalCoPTSt_stEng;


   VEMS_vidGET(Misf_bAcvRoughnsRoadMod, bLocalMisf_bAcvRoughnsRoadMod);
   VEMS_vidGET(Mf_algo_cond_ok_uavb0, bLocalMf_algo_cond_ok_uavb0);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(EngSt_bOscDetStab, bLocalEngSt_bOscDetStab);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   MISFFAICTR_vidCatDmgCylCutMgt();
   if (  (Misf_bAcvDetDmgCat != 0)
      && (bLocalMf_algo_cond_ok_uavb0 != 0)
      && (u8LocalRegime_moteur_32 <= Mf_det_cat_dam_n_max_uacn0)
      && (  (Misf_bTypRoughnsRoadSel_C == 0)
         || (bLocalMisf_bAcvRoughnsRoadMod == 0))
      && (u8LocalCoPTSt_stEng != Coupe_cale)
      && (bLocalEngSt_bOscDetStab != 0))
   {
      MISFFAICTR_vidFailDetCatDamage();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidCatDmgCylCutMgt                              */
/* !Description :  Cette fonction effectue la production de Misf_bAcvDetDmgCat*/
/*                 qui active le comptage des défauts émissions excessives de */
/*                 polluants.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 index)boolean;                */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input boolean MISFFAICTR_bMisfAcvDetDmgCatPrev;                           */
/*  input uint8 Misf_noAuthCutDmgCat3Cyl_C;                                   */
/*  input uint8 Misf_noAuthCutDmgCat4Cyl_C;                                   */
/*  output boolean Misf_bAcvDetDmgCat;                                        */
/*  output boolean MISFFAICTR_bMisfAcvDetDmgCatPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCatDmgCylCutMgt(void)
{
   boolean bLocalAcvInjCutOffCy1;
   boolean bLocalAcvInjCutOffCy2;
   boolean bLocalAcvInjCutOffCy3;
   boolean bLocalAcvInjCutOffCy4;
   uint8   u8LocalExt_noCylEng;
   uint8   u8LocalSum;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   bLocalAcvInjCutOffCy1 = GDGAR_bGetFRM(FRM_FRM_ACVINJCUTOFFCYL1);
   bLocalAcvInjCutOffCy2 = GDGAR_bGetFRM(FRM_FRM_ACVINJCUTOFFCYL2);
   bLocalAcvInjCutOffCy3 = GDGAR_bGetFRM(FRM_FRM_ACVINJCUTOFFCYL3);
   bLocalAcvInjCutOffCy4 = GDGAR_bGetFRM(FRM_FRM_ACVINJCUTOFFCYL4);

   u8LocalSum = (uint8)( bLocalAcvInjCutOffCy1
                       + bLocalAcvInjCutOffCy2
                       + bLocalAcvInjCutOffCy3
                       + bLocalAcvInjCutOffCy4);
   Misf_bAcvDetDmgCat = MISFFAICTR_bMisfAcvDetDmgCatPrev;
   if (u8LocalExt_noCylEng == 3)
   {
      if (u8LocalSum <= Misf_noAuthCutDmgCat3Cyl_C)
      {
         MISFFAICTR_bMisfAcvDetDmgCatPrev = 1;
      }
      else
      {
         MISFFAICTR_bMisfAcvDetDmgCatPrev = 0;
      }
   }
   else
   {
      if (u8LocalSum <= Misf_noAuthCutDmgCat4Cyl_C)
      {
         MISFFAICTR_bMisfAcvDetDmgCatPrev = 1;
      }
      else
      {
         MISFFAICTR_bMisfAcvDetDmgCatPrev = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidFailDetCatDamage                             */
/* !Description :  Cette fonction  effectue ses calculs à récurrence          */
/*                 Misf_EveMisf:  Comptage de panne « destruction du          */
/*                 catalyseur » dès lors que les conditions d’activations des */
/*                 algorithmes sont vérifiées.                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFFAICTR_vidHorizonCalcCatDam();                       */
/*  extf argret void MISFFAICTR_vidCataRoughRoadCnt();                        */
/*  extf argret void MISFFAICTR_vidCataDamagePerCyl();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidCataDamage();                              */
/*  extf argret void MISFFAICTR_vidInitCatDam();                              */
/*  extf argret void MISFFAICTR_vidFailDetCatDamage1();                       */
/*  input boolean Misf_bInhDetNoMisf;                                         */
/*  input boolean Misf_bAcvDetDmgCat;                                         */
/*  input boolean Mf_cat_dam_horizon_uavb0;                                   */
/*  input boolean MISFFAICTR_bMfCatDamHorizonPrev;                            */
/*  output boolean MISFFAICTR_bMfCatDamHorizonPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidFailDetCatDamage(void)
{
   boolean bLocalMf_cat_dam_horizon_uavb0;


   MISFFAICTR_vidHorizonCalcCatDam();
   if (Misf_bInhDetNoMisf == 0)
   {
      MISFFAICTR_vidCataRoughRoadCnt();
      if (Misf_bAcvDetDmgCat != 0)
      {
         MISFFAICTR_vidCataDamagePerCyl();
      }
   }
   VEMS_vidGET(Mf_cat_dam_horizon_uavb0, bLocalMf_cat_dam_horizon_uavb0);
   if (bLocalMf_cat_dam_horizon_uavb0 != 0)
   {
      if (  (MISFFAICTR_bMfCatDamHorizonPrev == 0)
         && (Misf_bInhDetNoMisf == 0))
      {
         MISFFAICTR_vidCataDamage();
      }
   }
   else
   {
      if (MISFFAICTR_bMfCatDamHorizonPrev != 0)
      {
         MISFFAICTR_vidInitCatDam();
      }
   }

   MISFFAICTR_vidFailDetCatDamage1();

   MISFFAICTR_bMfCatDamHorizonPrev = bLocalMf_cat_dam_horizon_uavb0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidHorizonCalcCatDam                            */
/* !Description :  Cette fonction permet de mettre 1 booléen à 1 dès lors que */
/*                 les horizons définis pour les stratégies « dommages        */
/*                 catalyseur » (400 PMH) est atteint.                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_cat_dam_count_uavn0;                                      */
/*  output boolean Mf_cat_dam_horizon_uavb0;                                  */
/*  output boolean Misf_bMonRunORngDmgCatMDAll;                               */
/*  output uint16 Mf_cat_dam_count_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidHorizonCalcCatDam(void)
{
   if (Mf_cat_dam_count_uavn0 <= 1)
   {
      VEMS_vidSET(Mf_cat_dam_horizon_uavb0, 1);
      Misf_bMonRunORngDmgCatMDAll = 1;
      Mf_cat_dam_count_uavn0 = (uint16)( Ext_noCylEng_SC
                                       * ENGINE_CYCLE_IN_CAT_DAM_SAMPLE_L);
   }
   else
   {
      VEMS_vidSET(Mf_cat_dam_horizon_uavb0, 0);
      Misf_bMonRunORngDmgCatMDAll = 0;
      Mf_cat_dam_count_uavn0 = (uint16)(Mf_cat_dam_count_uavn0 - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidCataRoughRoadCnt                             */
/* !Description :  Cette fonction somme le pic lié à la mauvaise route pour la*/
/*                 stratégie dommage catalyseur.                              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 MISFFAICTR_u8MfRoughCatUavn0;                                 */
/*  input boolean Mf_rough_road_uavb0;                                        */
/*  input boolean Mf_2_misfire_detected_uavb0;                                */
/*  input uint8 Mf_rough_road_sum_2mf_cat_uavn0;                              */
/*  input uint16 Mf_rough_road_cat_sum_uavn0;                                 */
/*  output uint8 MISFFAICTR_u8MfRoughCatUavn0;                                */
/*  output uint8 Mf_rough_road_sum_2mf_cat_uavn0;                             */
/*  output uint16 Mf_rough_road_cat_sum_uavn0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCataRoughRoadCnt(void)
{
   boolean bLocalMf_2_misf_detected_uavb0;
   boolean bLocalMf_rough_road_uavb0;
   uint8   u8LocalMfRoughSumCatUavn0;
   uint16  u16LocalSumCat;
   sint32  s32LocalMfRoughCatSumUavn0;


   u8LocalMfRoughSumCatUavn0 = MISFFAICTR_u8MfRoughCatUavn0;
   VEMS_vidGET(Mf_rough_road_uavb0, bLocalMf_rough_road_uavb0);
   if (bLocalMf_rough_road_uavb0 != 0)
   {
      MISFFAICTR_u8MfRoughCatUavn0 = 1;
   }
   else
   {
      MISFFAICTR_u8MfRoughCatUavn0 = 0;
   }
   u16LocalSumCat = (uint16)( u8LocalMfRoughSumCatUavn0
                            + MISFFAICTR_u8MfRoughCatUavn0);
   Mf_rough_road_sum_2mf_cat_uavn0 = (uint8)MATHSRV_udtMIN(u16LocalSumCat, 2);
   VEMS_vidGET(Mf_2_misfire_detected_uavb0, bLocalMf_2_misf_detected_uavb0);
   if (bLocalMf_2_misf_detected_uavb0 != 0)
   {
      s32LocalMfRoughCatSumUavn0 =
         (sint32)( Mf_rough_road_cat_sum_uavn0
                 + ( MISFFAICTR_u8MfRoughCatUavn0
                   - Mf_rough_road_sum_2mf_cat_uavn0));
   }
   else
   {
      s32LocalMfRoughCatSumUavn0 = (sint32)( Mf_rough_road_cat_sum_uavn0
                                           + MISFFAICTR_u8MfRoughCatUavn0);
   }
   Mf_rough_road_cat_sum_uavn0 =
      (uint16)MATHSRV_udtCLAMP(s32LocalMfRoughCatSumUavn0, 0, 65535);
}
/*------------------------------end of file-----------------------------------*/