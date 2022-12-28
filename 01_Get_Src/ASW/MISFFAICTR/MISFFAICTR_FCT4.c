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
/* !File            : MISFFAICTR_FCT4.C                                       */
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
/*   1 / MISFFAICTR_vidCatDamCylCalc                                          */
/*   2 / MISFFAICTR_vidMisfireRateCatDam                                      */
/*   3 / MISFFAICTR_vidRoughRoadDetCatDam                                     */
/*   4 / MISFFAICTR_vidInitCatDam                                             */
/*   5 / MISFFAICTR_vidFailDetEmiss                                           */
/*   6 / MISFFAICTR_vidFailDetEmission                                        */
/*   7 / MISFFAICTR_vidHorizonsCalcEmiss                                      */
/*   8 / MISFFAICTR_vidCataRoughRdEmisCnt                                     */
/*   9 / MISFFAICTR_vidMisfireTotal                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_FCT4.C_$*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   23 Oct 2012 $*/
/* $Author::   achebino                               $$Date::   23 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MISFFAICTR.h"
#include "MISFFAICTR_L.h"
#include "MISFFAICTR_IM.h"
#include "MATHSRV.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidCatDamCylCalc                                */
/* !Description :  En 4 cylindres, il est interdit de couper 2 cylindres      */
/*                 consécutifs en cas de panne Dephia ou AAC. Si cela se      */
/*                 produit les booléens de défaut dommages catalyseurs sont   */
/*                 remis à zéros.                                             */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 index)boolean;                */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Mf_cat_dam_cyl_uavb0[4];                                      */
/*  input boolean Mf_cat_dam_wgth_sum_diag_ena;                               */
/*  input uint16 Mf_cat_dam_sum1_uavn0;                                       */
/*  input uint8 Mf_cat_dam_sum_cyl_cutoff_uacn0;                              */
/*  input uint16 Mf_cat_dam_sum2_uavn0;                                       */
/*  input uint16 Mf_cat_dam_sum3_uavn0;                                       */
/*  input uint16 Mf_cat_dam_sum4_uavn0;                                       */
/*  input boolean Misf_bDgoORngDmgCat1;                                       */
/*  input boolean Misf_bDgoORngDmgCat2;                                       */
/*  input boolean Misf_bDgoORngDmgCat3;                                       */
/*  input boolean Misf_bDgoORngDmgCat4;                                       */
/*  output boolean Misf_bDgoORngDmgCat1;                                      */
/*  output boolean Misf_bDgoORngDmgCat2;                                      */
/*  output boolean Misf_bDgoORngDmgCat3;                                      */
/*  output boolean Misf_bDgoORngDmgCat4;                                      */
/*  output boolean Misf_bDgoORngDmgCatMDAll;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCatDamCylCalc(void)
{
   boolean bLocalMfCatDamCyl;
   boolean bLocalinhmisffaictrnbcylcutclcn;
   boolean bLocalMisfbDgoORngDmgCat1;
   boolean bLocalMisfbDgoORngDmgCat2;
   boolean bLocalMisfbDgoORngDmgCat3;
   boolean bLocalMisfbDgoORngDmgCat4;
   uint8   u8LocalExt_noCylEng;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   bLocalinhmisffaictrnbcylcutclcn =
      GDGAR_bGetFRM(FRM_FRM_INHMISFFAICTRNBCYLCUTCLCN);

   if (  (  (Mf_cat_dam_cyl_uavb0[0] != 0)
         && (Mf_cat_dam_cyl_uavb0[2] != 0))
      || (  (Mf_cat_dam_cyl_uavb0[2] != 0)
         && (Mf_cat_dam_cyl_uavb0[3] != 0))
      || (  (Mf_cat_dam_cyl_uavb0[3] != 0)
         && (Mf_cat_dam_cyl_uavb0[1] != 0))
      || (  (Mf_cat_dam_cyl_uavb0[1] != 0)
         && (Mf_cat_dam_cyl_uavb0[0] != 0)))
   {
      bLocalMfCatDamCyl = 1;
   }
   else
   {
      bLocalMfCatDamCyl = 0;
   }

   if (  (  (bLocalMfCatDamCyl != 0)
         && (bLocalinhmisffaictrnbcylcutclcn != 0)
         && (u8LocalExt_noCylEng == 4))
      || (Mf_cat_dam_wgth_sum_diag_ena == 0))
   {
      bLocalMisfbDgoORngDmgCat1 = 0;
      bLocalMisfbDgoORngDmgCat2 = 0;
      bLocalMisfbDgoORngDmgCat3 = 0;
      bLocalMisfbDgoORngDmgCat4 = 0;
   }
   else
   {
      if (Mf_cat_dam_cyl_uavb0[0] != 0)
      {
         bLocalMisfbDgoORngDmgCat1 = 1;
      }
      else
      {
         bLocalMisfbDgoORngDmgCat1 = 0;
      }
      if (Mf_cat_dam_cyl_uavb0[1] != 0)
      {
         bLocalMisfbDgoORngDmgCat2 = 1;
      }
      else
      {
         bLocalMisfbDgoORngDmgCat2 = 0;
      }
      if (Mf_cat_dam_cyl_uavb0[2] != 0)
      {
         bLocalMisfbDgoORngDmgCat3 = 1;
      }
      else
      {
         bLocalMisfbDgoORngDmgCat3 = 0;
      }
      if (Mf_cat_dam_cyl_uavb0[3] != 0)
      {
         bLocalMisfbDgoORngDmgCat4 = 1;
      }
      else
      {
         bLocalMisfbDgoORngDmgCat4 = 0;
      }
   }

   if (  (Mf_cat_dam_sum1_uavn0 >= (uint16)Mf_cat_dam_sum_cyl_cutoff_uacn0)
      || (bLocalMisfbDgoORngDmgCat1 != 0))
   {
      Misf_bDgoORngDmgCat1 = 1;
   }
   else
   {
      Misf_bDgoORngDmgCat1 = 0;
   }
   if (  (Mf_cat_dam_sum2_uavn0 >= (uint16)Mf_cat_dam_sum_cyl_cutoff_uacn0)
      || (bLocalMisfbDgoORngDmgCat2 != 0))
   {
      Misf_bDgoORngDmgCat2 = 1;
   }
   else
   {
      Misf_bDgoORngDmgCat2 = 0;
   }
   if (  (Mf_cat_dam_sum3_uavn0 >= (uint16)Mf_cat_dam_sum_cyl_cutoff_uacn0)
      || (bLocalMisfbDgoORngDmgCat3 != 0))
   {
      Misf_bDgoORngDmgCat3 = 1;
   }
   else
   {
      Misf_bDgoORngDmgCat3 = 0;
   }
   if (  (Mf_cat_dam_sum4_uavn0 >= (uint16)Mf_cat_dam_sum_cyl_cutoff_uacn0)
      || (bLocalMisfbDgoORngDmgCat4 != 0))
   {
      Misf_bDgoORngDmgCat4 = 1;
   }
   else
   {
      Misf_bDgoORngDmgCat4 = 0;
   }

   if (  (Misf_bDgoORngDmgCat1 == 0)
      && (Misf_bDgoORngDmgCat2 == 0)
      && (Misf_bDgoORngDmgCat3 == 0)
      && (Misf_bDgoORngDmgCat4 == 0)
      && (Mf_cat_dam_wgth_sum_diag_ena != 0))
   {
      Misf_bDgoORngDmgCatMDAll = 1;
   }
   else
   {
      Misf_bDgoORngDmgCatMDAll = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMisfireRateCatDam                            */
/* !Description :  Cette fonction calcule le taux de misfire  « dommage       */
/*                 catalyseur » qui se sont produits sur l’ensemble des       */
/*                 cylindres sur l’horizon « dommage catalyseur » de 400 PMH. */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_cat_dam_sum_real_uavn0;                                   */
/*  output uint8 Mf_cat_dam_mf_rate_uavn0;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMisfireRateCatDam(void)
{
   uint8  u8LocalCatDAmRate;
   uint16 u16LocalDamMfRat;


   u16LocalDamMfRat = (uint16)( Ext_noCylEng_SC
                              * ENGINE_CYCLE_IN_CAT_DAM_SAMPLE_L);
   u16LocalDamMfRat = (uint16)( (uint32)(Mf_cat_dam_sum_real_uavn0 * 256)
                              / u16LocalDamMfRat);

   u8LocalCatDAmRate = (uint8)MATHSRV_udtMIN(u16LocalDamMfRat, 255);
   VEMS_vidSET(Mf_cat_dam_mf_rate_uavn0,u8LocalCatDAmRate);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidRoughRoadDetCatDam                           */
/* !Description :  Si la mauvaise route est détectée                          */
/*                 (Mf_rough_road_cat_sum_uavn0 =                             */
/*                 mf_rough_road_cat_thresh_uacn0) alors les variables entrant*/
/*                 en compte dans le comptage de pannes sont réinitialisées à */
/*                 0.                                                         */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Mf_rough_road_cat_sum_uavn0;                                */
/*  output uint16 Mf_cat_dam_wght_count_1_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_2_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_3_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_4_uavn0;                              */
/*  output uint16 Mf_cat_dam_sum_real_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidRoughRoadDetCatDam(void)
{
   Mf_rough_road_cat_sum_uavn0 = 0;
   Mf_cat_dam_wght_count_1_uavn0 = 0;
   Mf_cat_dam_wght_count_2_uavn0 = 0;
   Mf_cat_dam_wght_count_3_uavn0 = 0;
   Mf_cat_dam_wght_count_4_uavn0 = 0;
   Mf_cat_dam_sum_real_uavn0 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidInitCatDam                                   */
/* !Description :  Initialisation des variables relatives au comptage des     */
/*                 pannes «dommages catalyseur » dès lors que l’horizon «     */
/*                 dommages catalyseur » de 400 PMH est atteint.              */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Mf_cat_dam_sum_real_uavn0;                                  */
/*  output uint16 Mf_cat_dam_wght_count_1_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_2_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_3_uavn0;                              */
/*  output uint16 Mf_cat_dam_wght_count_4_uavn0;                              */
/*  output uint16 Mf_rough_road_cat_sum_uavn0;                                */
/*  output uint16 Mf_cat_dam_sum1_uavn0;                                      */
/*  output uint16 Mf_cat_dam_sum2_uavn0;                                      */
/*  output uint16 Mf_cat_dam_sum3_uavn0;                                      */
/*  output uint16 Mf_cat_dam_sum4_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidInitCatDam(void)
{
   Mf_cat_dam_sum_real_uavn0 = 0;
   Mf_cat_dam_wght_count_1_uavn0 = 0;
   Mf_cat_dam_wght_count_2_uavn0 = 0;
   Mf_cat_dam_wght_count_3_uavn0 = 0;
   Mf_cat_dam_wght_count_4_uavn0 = 0;
   Mf_rough_road_cat_sum_uavn0 = 0;
   Mf_cat_dam_sum1_uavn0 = 0;
   Mf_cat_dam_sum2_uavn0 = 0;
   Mf_cat_dam_sum3_uavn0 = 0;
   Mf_cat_dam_sum4_uavn0 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidFailDetEmiss                                 */
/* !Description :  Cette fonction effectue ses calculs à récurrence           */
/*                 Misf_EveMisf.                                              */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void MISFFAICTR_vidFailDetEmission();                         */
/*  input boolean Misf_bAcvRoughnsRoadMod;                                    */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input boolean Mf_algo_cond_ok_uavb0;                                      */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint32 Ext_dstVehMes;                                               */
/*  input boolean EngSt_bOscDetStab;                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 Mf_det_emiss_n_max_uacn0;                                     */
/*  input boolean Misf_bTypRoughnsRoadSel_C;                                  */
/*  input uint16 Mf_AirInjDistThd_C;                                          */
/*  output boolean MonMisf_bAcvMonMisfOBD;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidFailDetEmiss(void)
{
   boolean bLocalFlev_low_fuel_level;
   boolean bLocalMf_algo_cond_ok_uavb0;
   boolean bLocalMisf_bAcvRoughnsRoadMod;
   boolean bLocalEngSt_bOscDetStab;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalCoPTSt_stEng;
   uint32  u32LocalExt_dstVehMes;


   VEMS_vidGET(Misf_bAcvRoughnsRoadMod, bLocalMisf_bAcvRoughnsRoadMod);
   VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
   VEMS_vidGET(Mf_algo_cond_ok_uavb0, bLocalMf_algo_cond_ok_uavb0);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Ext_dstVehMes, u32LocalExt_dstVehMes);
   VEMS_vidGET(EngSt_bOscDetStab, bLocalEngSt_bOscDetStab);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   if (  (bLocalMf_algo_cond_ok_uavb0 != 0)
      && (bLocalFlev_low_fuel_level == 0)
      && (u8LocalRegime_moteur_32 <= Mf_det_emiss_n_max_uacn0)
      && (  (Misf_bTypRoughnsRoadSel_C == 0)
         || (bLocalMisf_bAcvRoughnsRoadMod == 0))
      && (u8LocalCoPTSt_stEng != Coupe_cale)
      && (bLocalEngSt_bOscDetStab != 0)
      && (u32LocalExt_dstVehMes >= Mf_AirInjDistThd_C))
   {
      VEMS_vidSET(MonMisf_bAcvMonMisfOBD, 1);
      MISFFAICTR_vidFailDetEmission();
   }
   else
   {
      VEMS_vidSET(MonMisf_bAcvMonMisfOBD, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidFailDetEmission                              */
/* !Description :  Cette fonction effectue ses calculs à récurrence           */
/*                 Misfire_task.                                              */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_005.01                                     */
/*                 VEMS_R_09_00890_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidHorizonsCalcEmiss();                       */
/*  extf argret void MISFFAICTR_vidCataRoughRdEmisCnt();                      */
/*  extf argret void MISFFAICTR_vidCataEmissPerCyl();                         */
/*  extf argret void MISFFAICTR_vidEmission();                                */
/*  extf argret void MISFFAICTR_vidInitEmiss();                               */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input boolean Mf_emiss_horizon_uavb0;                                     */
/*  input boolean Misf_bInhDetNoMisf;                                         */
/*  input boolean MISFFAICTR_bEmissHorizonPrev;                               */
/*  output boolean Misf_bMonRunORngMisfEmi1;                                  */
/*  output boolean Misf_bMonRunORngMisfEmi2;                                  */
/*  output boolean Misf_bMonRunORngMisfEmi3;                                  */
/*  output boolean Misf_bMonRunORngMisfEmi4;                                  */
/*  output boolean MISFFAICTR_bEmissHorizonPrev;                              */
/*  output uint8 MISFFAICTR_u8CoupDecProgrInjprev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidFailDetEmission(void)
{
   boolean bLocalMf_emiss_horizon_uavb0;
   uint8   u8LocalCoupure_decel_progr_inj;


   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   MISFFAICTR_vidHorizonsCalcEmiss();
   VEMS_vidGET(Mf_emiss_horizon_uavb0, bLocalMf_emiss_horizon_uavb0);

   if (Misf_bInhDetNoMisf == 0)
   {
      MISFFAICTR_vidCataRoughRdEmisCnt();
      MISFFAICTR_vidCataEmissPerCyl();
   }

   if (bLocalMf_emiss_horizon_uavb0 != 0)
   {
      if (  (MISFFAICTR_bEmissHorizonPrev == 0)
         && (Misf_bInhDetNoMisf == 0))
      {
         MISFFAICTR_vidEmission();
      }
   }
   else
   {
      if (MISFFAICTR_bEmissHorizonPrev != 0)
      {
         MISFFAICTR_vidInitEmiss();
      }
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x01) == 0x01)
   {
      Misf_bMonRunORngMisfEmi1 = 0;
   }
   else
   {
      Misf_bMonRunORngMisfEmi1 = bLocalMf_emiss_horizon_uavb0;
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x02) == 0x02)
   {
      Misf_bMonRunORngMisfEmi2 = 0;
   }
   else
   {
      Misf_bMonRunORngMisfEmi2 = bLocalMf_emiss_horizon_uavb0;
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x04) == 0x04)
   {
      Misf_bMonRunORngMisfEmi3 = 0;
   }
   else
   {
      Misf_bMonRunORngMisfEmi3 = bLocalMf_emiss_horizon_uavb0;
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x08) == 0x08)
   {
      Misf_bMonRunORngMisfEmi4 = 0;
   }
   else
   {
      Misf_bMonRunORngMisfEmi4 = bLocalMf_emiss_horizon_uavb0;
   }

   MISFFAICTR_bEmissHorizonPrev = bLocalMf_emiss_horizon_uavb0;
   MISFFAICTR_u8CoupDecProgrInjprev =
      (uint8)MATHSRV_udtMIN(u8LocalCoupure_decel_progr_inj, 15);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidHorizonsCalcEmiss                            */
/* !Description :  Cette fonction permet de mettre 1 booléen à 1 dès lors que */
/*                 les horizons définis pour les stratégies «émission »       */
/*                 excessive de polluant (2000 PMH) sont atteints.            */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_emiss_count_uavn0;                                        */
/*  output boolean Mf_emiss_horizon_uavb0;                                    */
/*  output boolean Misf_bMonRunORngMisfEmiAll;                                */
/*  output boolean MonMisf_bClcMisfOBD;                                       */
/*  output uint16 Mf_emiss_count_uavn0;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidHorizonsCalcEmiss(void)
{
   if (Mf_emiss_count_uavn0 <= 1)
   {
      VEMS_vidSET(Mf_emiss_horizon_uavb0, 1);
      Misf_bMonRunORngMisfEmiAll = 1;
      VEMS_vidSET(MonMisf_bClcMisfOBD, 1);
      Mf_emiss_count_uavn0 = (uint16)( Ext_noCylEng_SC
                                     * ENGINE_CYCLE_IN_EMISS_SAMPLE_L);
   }
   else
   {
      VEMS_vidSET(Mf_emiss_horizon_uavb0, 0);
      Misf_bMonRunORngMisfEmiAll = 0;
      VEMS_vidSET(MonMisf_bClcMisfOBD, 0);
      Mf_emiss_count_uavn0 = (uint16)(Mf_emiss_count_uavn0 - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidCataRoughRdEmisCnt                           */
/* !Description :  Cette fonction somme le pic lié à la mauvaise route pour la*/
/*                 stratégie émission excessive de polluant.                  */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 MISFFAICTR_u8MfRoughEmiUavn0;                                 */
/*  input boolean Mf_rough_road_uavb0;                                        */
/*  input boolean Mf_2_misfire_detected_uavb0;                                */
/*  input uint8 Mf_rough_road_sum_2mf_emi_uavn0;                              */
/*  input uint16 Mf_rough_road_emiss_sum_uavn0;                               */
/*  output uint8 MISFFAICTR_u8MfRoughEmiUavn0;                                */
/*  output uint8 Mf_rough_road_sum_2mf_emi_uavn0;                             */
/*  output uint16 Mf_rough_road_emiss_sum_uavn0;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCataRoughRdEmisCnt(void)
{
   boolean bLocalMf_2_misfire_det_uavb0;
   boolean bLocalMf_rough_road_uavb0;
   uint8   u8LocalMfRoughEmiUavn0Prev;
   uint16  u16LocalSumCat;
   sint32  s32LocalMfRoughEmiSumUavn0;


   u8LocalMfRoughEmiUavn0Prev = MISFFAICTR_u8MfRoughEmiUavn0;
   VEMS_vidGET(Mf_rough_road_uavb0, bLocalMf_rough_road_uavb0);
   if (bLocalMf_rough_road_uavb0 != 0)
   {
      MISFFAICTR_u8MfRoughEmiUavn0 = 1;
   }
   else
   {
      MISFFAICTR_u8MfRoughEmiUavn0 = 0;
   }
   u16LocalSumCat = (uint16)( u8LocalMfRoughEmiUavn0Prev
                            + MISFFAICTR_u8MfRoughEmiUavn0);
   Mf_rough_road_sum_2mf_emi_uavn0 = (uint8)MATHSRV_udtMIN(u16LocalSumCat, 2);
   VEMS_vidGET(Mf_2_misfire_detected_uavb0, bLocalMf_2_misfire_det_uavb0);
   if (bLocalMf_2_misfire_det_uavb0 != 0)
   {
      s32LocalMfRoughEmiSumUavn0 =
         (sint32)( Mf_rough_road_emiss_sum_uavn0
                 + ( MISFFAICTR_u8MfRoughEmiUavn0
                   - Mf_rough_road_sum_2mf_emi_uavn0));
   }
   else
   {
      s32LocalMfRoughEmiSumUavn0 = (sint32)( Mf_rough_road_emiss_sum_uavn0
                                           + MISFFAICTR_u8MfRoughEmiUavn0);
   }
   Mf_rough_road_emiss_sum_uavn0 =
      (uint16)MATHSRV_udtCLAMP(s32LocalMfRoughEmiSumUavn0, 0, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMisfireTotal                                 */
/* !Description :  Ce bloc détermine, pour les 4 cylindres, un défaut misfire */
/*                 dû à un injecteur ou une bougie défaillante.               */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_cat_dam_sum1_uavn0;                                       */
/*  input uint16 Misf_TotalMisf_C;                                            */
/*  input uint16 Mf_cat_dam_sum2_uavn0;                                       */
/*  input uint16 Mf_cat_dam_sum3_uavn0;                                       */
/*  input uint16 Mf_cat_dam_sum4_uavn0;                                       */
/*  output boolean Misf_Defaut_TotalMisf_perCy1;                              */
/*  output boolean Misf_Defaut_TotalMisf_perCy2;                              */
/*  output boolean Misf_Defaut_TotalMisf_perCy3;                              */
/*  output boolean Misf_Defaut_TotalMisf_perCy4;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMisfireTotal(void)
{
   if (Mf_cat_dam_sum1_uavn0 >= Misf_TotalMisf_C)
   {
      Misf_Defaut_TotalMisf_perCy1 = 1;
   }
   else
   {
      Misf_Defaut_TotalMisf_perCy1 = 0;
   }

   if (Mf_cat_dam_sum2_uavn0 >= Misf_TotalMisf_C)
   {
      Misf_Defaut_TotalMisf_perCy2 = 1;
   }
   else
   {
      Misf_Defaut_TotalMisf_perCy2 = 0;
   }

   if (Mf_cat_dam_sum3_uavn0 >= Misf_TotalMisf_C)
   {
      Misf_Defaut_TotalMisf_perCy3 = 1;
   }
   else
   {
      Misf_Defaut_TotalMisf_perCy3 = 0;
   }

   if (Mf_cat_dam_sum4_uavn0 >= Misf_TotalMisf_C)
   {
      Misf_Defaut_TotalMisf_perCy4 = 1;
   }
   else
   {
      Misf_Defaut_TotalMisf_perCy4 = 0;
   }
}
/*------------------------------end of file-----------------------------------*/