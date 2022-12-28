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
/* !File            : MISFFAICTR_FCT6.C                                       */
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
/*   1 / MISFFAICTR_vidRoughRdNoDetEmiss                                      */
/*   2 / MISFFAICTR_vidEmissSum                                               */
/*   3 / MISFFAICTR_vidMfDetectedEmiss                                        */
/*   4 / MISFFAICTR_vidMfEmissCyl                                             */
/*   5 / MISFFAICTR_vidMisfireRateEmiss                                       */
/*   6 / MISFFAICTR_vidRoughRoadDetEmiss                                      */
/*   7 / MISFFAICTR_vidInitEmiss                                              */
/*   8 / MISFFAICTR_vidFailDetCatDamage1                                      */
/*   9 / MISFFAICTR_vidEmissRealCount                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_FCT6.C_$*/
/* $Revision::   1.14     $$Author::   wbouach        $$Date::   19 Jun 2012 $*/
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
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidRoughRdNoDetEmiss                            */
/* !Description :  la détection de ratés liés à une émission excessive de     */
/*                 polluant (2000 PMH).                                       */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_007.01                                     */
/*                 VEMS_R_09_00890_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFFAICTR_vidEmissRealCount();                          */
/*  extf argret void MISFFAICTR_vidEmissSum();                                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidMfDetectedEmiss();                         */
/*  extf argret void MISFFAICTR_vidMfEmissCyl();                              */
/*  extf argret void MISFFAICTR_vidMisfireRateEmiss();                        */
/*  input uint8 Coup_decel_progr_inj_emiss;                                   */
/*  input boolean Mf_emiss_det_fail_uavb0;                                    */
/*  output boolean Coup_decel_progr_inj_a_emiss;                              */
/*  output boolean Coup_decel_progr_inj_b_emiss;                              */
/*  output boolean Coup_decel_progr_inj_c_emiss;                              */
/*  output boolean Coup_decel_progr_inj_d_emiss;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidRoughRdNoDetEmiss(void)
{
   boolean bLocalMf_emiss_det_fail_uavb0;


   if ((Coup_decel_progr_inj_emiss & 0x01) == 0x01)
   {
      Coup_decel_progr_inj_a_emiss = 1;
   }
   else
   {
      Coup_decel_progr_inj_a_emiss = 0;
   }

   if ((Coup_decel_progr_inj_emiss & 0x02) == 0x02)
   {
      Coup_decel_progr_inj_b_emiss = 1;
   }
   else
   {
      Coup_decel_progr_inj_b_emiss = 0;
   }

   if ((Coup_decel_progr_inj_emiss & 0x04) == 0x04)
   {
      Coup_decel_progr_inj_c_emiss = 1;
   }
   else
   {
      Coup_decel_progr_inj_c_emiss = 0;
   }

   if ((Coup_decel_progr_inj_emiss & 0x08) == 0x08)
   {
      Coup_decel_progr_inj_d_emiss = 1;
   }
   else
   {
      Coup_decel_progr_inj_d_emiss = 0;
   }
   MISFFAICTR_vidEmissRealCount();
   MISFFAICTR_vidEmissSum();
   VEMS_vidGET(Mf_emiss_det_fail_uavb0, bLocalMf_emiss_det_fail_uavb0);
   if (bLocalMf_emiss_det_fail_uavb0 != 0)
   {
      MISFFAICTR_vidMfDetectedEmiss();
   }
   MISFFAICTR_vidMfEmissCyl();
   MISFFAICTR_vidMisfireRateEmiss();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidEmissSum                                     */
/* !Description :  Cette fonction fait la somme des misfires « émission »     */
/*                 détectés sur l’ensemble des cylindres pour l’horizon «     */
/*                 émission » de 2000.                                        */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_emiss_count_real_uavn1[4];                                */
/*  input uint16 Mf_emiss_count_cyl_uavn1[4];                                 */
/*  input uint16 Mf_emiss_min_thresh_uacn0;                                   */
/*  output uint16 Mf_emiss_count_cyl_uavn1[4];                                */
/*  output uint16 Mf_emiss_sum_uavn0;                                         */
/*  output boolean Mf_emiss_det_fail_uavb0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidEmissSum(void)
{
   uint16 u16LocalMf_emiss_sum_uavn0;
   uint32 u32LocalMfEmissSum;


   Mf_emiss_count_cyl_uavn1[0] = Mf_emiss_count_real_uavn1[0];
   Mf_emiss_count_cyl_uavn1[1] = Mf_emiss_count_real_uavn1[1];
   Mf_emiss_count_cyl_uavn1[2] = Mf_emiss_count_real_uavn1[2];
   Mf_emiss_count_cyl_uavn1[3] = Mf_emiss_count_real_uavn1[3];
   u32LocalMfEmissSum = ( Mf_emiss_count_cyl_uavn1[0]
                        + Mf_emiss_count_cyl_uavn1[1]
                        + Mf_emiss_count_cyl_uavn1[2]
                        + Mf_emiss_count_cyl_uavn1[3]);
   u16LocalMf_emiss_sum_uavn0 =
      (uint16)MATHSRV_udtMIN(u32LocalMfEmissSum, 65535);
   VEMS_vidSET(Mf_emiss_sum_uavn0, u16LocalMf_emiss_sum_uavn0);
   if (u16LocalMf_emiss_sum_uavn0 > Mf_emiss_min_thresh_uacn0)
   {
      VEMS_vidSET(Mf_emiss_det_fail_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Mf_emiss_det_fail_uavb0, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfDetectedEmiss                              */
/* !Description :  Ce bloc effectue ses calculs à récurrence Misfire_task :   */
/*                 Comptage de panne «  émission excessive » dès lors que les */
/*                 conditions d’activations des algorithmes sont vérifiées.   */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_008.01                                     */
/*                 VEMS_R_09_00890_009.01                                     */
/*                 VEMS_R_09_00890_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Mf_emiss_sum_uavn0;                                          */
/*  input uint16 Mf_emiss_thresh_uacn0;                                       */
/*  input uint16 Mf_emiss_count_real_uavn1[4];                                */
/*  output uint8 Mf_emiss_cyl_uavb1[4];                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfDetectedEmiss(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalMfEmissSumUavn0;
   uint32 u32LocalMfEmissThresh;
   uint32 u32LocalEmissCount;


   VEMS_vidGET(Mf_emiss_sum_uavn0, u16LocalMfEmissSumUavn0);
   u32LocalMfEmissThresh = (uint32)( Mf_emiss_thresh_uacn0
                                   * u16LocalMfEmissSumUavn0);

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      u32LocalEmissCount = (uint32)( Mf_emiss_count_real_uavn1[u8LocalIndex]
                                   * 65536);
      if (u32LocalMfEmissThresh <= u32LocalEmissCount)
      {
         Mf_emiss_cyl_uavb1[u8LocalIndex] = 1;
      }
      else
      {
         Mf_emiss_cyl_uavb1[u8LocalIndex] = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfEmissCyl                                   */
/* !Description :  Cette fonction indique permet d'indiquer s'il ya des des   */
/*                 émissions excessives de polluants sont dues par le         */
/*                 cylindre1 en misfire.                                      */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Mf_emiss_det_fail_uavb0;                                    */
/*  input uint8 Mf_emiss_cyl_uavb1[4];                                        */
/*  input boolean Misf_bDgoORngMisfEmi1;                                      */
/*  input boolean Misf_bDgoORngMisfEmi2;                                      */
/*  input boolean Misf_bDgoORngMisfEmi3;                                      */
/*  input boolean Misf_bDgoORngMisfEmi4;                                      */
/*  output boolean Misf_bDgoORngMisfEmi1;                                     */
/*  output boolean Misf_bDgoORngMisfEmi2;                                     */
/*  output boolean Misf_bDgoORngMisfEmi3;                                     */
/*  output boolean Misf_bDgoORngMisfEmi4;                                     */
/*  output boolean Misf_bDgoORngMisfEmiAll;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfEmissCyl(void)
{
   boolean bLocalMf_emiss_det_fail_uavb0;


   VEMS_vidGET(Mf_emiss_det_fail_uavb0, bLocalMf_emiss_det_fail_uavb0);

   if (bLocalMf_emiss_det_fail_uavb0 != 0)
   {
      if (Mf_emiss_cyl_uavb1[0] != 0)
      {
         Misf_bDgoORngMisfEmi1 = 1;
      }
      else
      {
         Misf_bDgoORngMisfEmi1 = 0 ;
      }

      if (Mf_emiss_cyl_uavb1[1] != 0)
      {
         Misf_bDgoORngMisfEmi2 = 1;
      }
      else
      {
         Misf_bDgoORngMisfEmi2 = 0;
      }

      if (Mf_emiss_cyl_uavb1[2] != 0)
      {
         Misf_bDgoORngMisfEmi3 = 1;
      }
      else
      {
         Misf_bDgoORngMisfEmi3 =  0;
      }

      if (Mf_emiss_cyl_uavb1[3] != 0)
      {
         Misf_bDgoORngMisfEmi4 = 1;
      }
      else
      {
         Misf_bDgoORngMisfEmi4 = 0;
      }
      if (  (Misf_bDgoORngMisfEmi1 == 0)
         && (Misf_bDgoORngMisfEmi2 == 0)
         && (Misf_bDgoORngMisfEmi3 == 0)
         && (Misf_bDgoORngMisfEmi4 == 0))
      {
         Misf_bDgoORngMisfEmiAll = 1;
      }
      else
      {
         Misf_bDgoORngMisfEmiAll = 0;
      }
   }
   else
   {
      Misf_bDgoORngMisfEmiAll = 0;
      Misf_bDgoORngMisfEmi1 = 0;
      Misf_bDgoORngMisfEmi2 = 0;
      Misf_bDgoORngMisfEmi3 = 0;
      Misf_bDgoORngMisfEmi4 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMisfireRateEmiss                             */
/* !Description :  Calcul du taux de misfires « émission » pour un bloc «     */
/*                 émission » de 2000 PMH.                                    */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_emiss_sum_uavn0;                                          */
/*  output uint16 MonMisf_rMisfOBD;                                           */
/*  output uint8 Mf_emiss_mf_rate_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMisfireRateEmiss(void)
{
   uint8  u8LocalMf_emiss_mf_rate_uavn0;
   uint16 u16LocalRateUavn0;
   uint16 u16LocalMf_emiss_sum_uavn0;
   uint16 u16LocalMonMisf_rMisfOBD;


   u16LocalRateUavn0 = (uint16)( Ext_noCylEng_SC
                               * ENGINE_CYCLE_IN_EMISS_SAMPLE_L);
   VEMS_vidGET(Mf_emiss_sum_uavn0, u16LocalMf_emiss_sum_uavn0);
   u16LocalRateUavn0 = (uint16)( (uint32)(u16LocalMf_emiss_sum_uavn0 * 256)
                               / u16LocalRateUavn0);

   u8LocalMf_emiss_mf_rate_uavn0 = (uint8)MATHSRV_udtMIN(u16LocalRateUavn0,
                                                         255);
   u16LocalMonMisf_rMisfOBD = (uint16)( (uint32)( (u8LocalMf_emiss_mf_rate_uavn0
                                                  * 1000)
                                        + 128)
                                      / (uint32) 256);
   VEMS_vidSET(MonMisf_rMisfOBD, u16LocalMonMisf_rMisfOBD);
   VEMS_vidSET(Mf_emiss_mf_rate_uavn0, u8LocalMf_emiss_mf_rate_uavn0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidRoughRoadDetEmiss                            */
/* !Description :  Si la mauvaise route est détectée                          */
/*                 (Mf_rough_road_sum_emiss_uavn0 =                           */
/*                 Mf_rough_emiss_thresh_uacn0) alors les variables entrant en*/
/*                 compte dans le comptage de pannes sont réinitialisées à 0. */
/* !Number      :  FCT6.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Mf_rough_road_emiss_sum_uavn0;                              */
/*  output uint16 Mf_emiss_count_1_uavn0;                                     */
/*  output uint16 Mf_emiss_count_2_uavn0;                                     */
/*  output uint16 Mf_emiss_count_3_uavn0;                                     */
/*  output uint16 Mf_emiss_count_4_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidRoughRoadDetEmiss(void)
{
   Mf_rough_road_emiss_sum_uavn0 = 0;
   Mf_emiss_count_1_uavn0 = 0;
   Mf_emiss_count_2_uavn0 = 0;
   Mf_emiss_count_3_uavn0 = 0;
   Mf_emiss_count_4_uavn0 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidInitEmiss                                    */
/* !Description :  Initialisation des variables relatives au comptage des     */
/*                 pannes «émissions » de polluants dès lors que l’horizon «  */
/*                 émission » de 2000 PMH est atteint.                        */
/* !Number      :  FCT6.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Mf_rough_road_emiss_sum_uavn0;                              */
/*  output uint16 Mf_emiss_count_1_uavn0;                                     */
/*  output uint16 Mf_emiss_count_2_uavn0;                                     */
/*  output uint16 Mf_emiss_count_3_uavn0;                                     */
/*  output uint16 Mf_emiss_count_4_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidInitEmiss(void)
{
   Mf_rough_road_emiss_sum_uavn0 = 0;
   Mf_emiss_count_1_uavn0 = 0;
   Mf_emiss_count_2_uavn0 = 0;
   Mf_emiss_count_3_uavn0 = 0;
   Mf_emiss_count_4_uavn0 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidFailDetCatDamage1                            */
/* !Description :  Cette fonction  effectue ses calculs à récurrence          */
/*                 Misf_EveMisf:  Comptage de panne « destruction du          */
/*                 catalyseur » dès lors que les conditions d’activations des */
/*                 algorithmes sont vérifiées.                                */
/* !Number      :  FCT6.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input boolean Misf_bAcvLowFuLvlCatDam;                                    */
/*  input boolean Flev_low_fuel_level_cat_dam;                                */
/*  input boolean Mf_cat_dam_horizon_uavb0;                                   */
/*  input boolean Misf_bMonRunORngDmgCat1;                                    */
/*  input boolean Misf_bMonRunORngDmgCat2;                                    */
/*  input boolean Misf_bMonRunORngDmgCat3;                                    */
/*  input boolean Misf_bMonRunORngDmgCat4;                                    */
/*  output boolean Misf_bMonWaitORngDmgCatDTC1;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTC2;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTC3;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTC4;                               */
/*  output boolean Misf_bMonWaitORngDmgCatDTCAll;                             */
/*  output boolean Misf_bMonRunORngDmgCat1;                                   */
/*  output boolean Misf_bMonRunORngDmgCat2;                                   */
/*  output boolean Misf_bMonRunORngDmgCat3;                                   */
/*  output boolean Misf_bMonRunORngDmgCat4;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidFailDetCatDamage1(void)
{
   boolean bLocalFlev_low_fuel_level;
   uint8   u8LocalCoupure_decel_progr_inj;


   VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   if (  (bLocalFlev_low_fuel_level != 0)
      && (Misf_bAcvLowFuLvlCatDam != 0))
   {
      Misf_bMonWaitORngDmgCatDTC1 = Flev_low_fuel_level_cat_dam;
      Misf_bMonWaitORngDmgCatDTC2 = Flev_low_fuel_level_cat_dam;
      Misf_bMonWaitORngDmgCatDTC3 = Flev_low_fuel_level_cat_dam;
      Misf_bMonWaitORngDmgCatDTC4 = Flev_low_fuel_level_cat_dam;
      Misf_bMonWaitORngDmgCatDTCAll = Flev_low_fuel_level_cat_dam;
   }
   else
   {
      Misf_bMonWaitORngDmgCatDTC1 = DIAG_DISPO;
      Misf_bMonWaitORngDmgCatDTC2 = DIAG_DISPO;
      Misf_bMonWaitORngDmgCatDTC3 = DIAG_DISPO;
      Misf_bMonWaitORngDmgCatDTC4 = DIAG_DISPO;
      Misf_bMonWaitORngDmgCatDTCAll = DIAG_DISPO;
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x01) == 0x01)
   {
      Misf_bMonRunORngDmgCat1 = 0;
   }
   else
   {
      VEMS_vidGET(Mf_cat_dam_horizon_uavb0, Misf_bMonRunORngDmgCat1);
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x02) == 0x02)
   {
      Misf_bMonRunORngDmgCat2 = 0;
   }
   else
   {
      VEMS_vidGET(Mf_cat_dam_horizon_uavb0, Misf_bMonRunORngDmgCat2);
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x04) == 0x04)
   {
      Misf_bMonRunORngDmgCat3 = 0;
   }
   else
   {
      VEMS_vidGET(Mf_cat_dam_horizon_uavb0, Misf_bMonRunORngDmgCat3);
   }

   if ((u8LocalCoupure_decel_progr_inj & 0x08) == 0x08)
   {
      Misf_bMonRunORngDmgCat4 = 0;
   }
   else
   {
      VEMS_vidGET(Mf_cat_dam_horizon_uavb0, Misf_bMonRunORngDmgCat4);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidEmissRealCount                               */
/* !Description :  Les misfires détectés sur des cylindres dont l’injection   */
/*                 est coupée sont écartés afin de ne pas fausser la détection*/
/* !Number      :  FCT6.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Coup_decel_progr_inj_a_emiss;                               */
/*  input uint16 Mf_emiss_count_cyl_uavn1[4];                                 */
/*  input boolean Coup_decel_progr_inj_b_emiss;                               */
/*  input boolean Coup_decel_progr_inj_c_emiss;                               */
/*  input boolean Coup_decel_progr_inj_d_emiss;                               */
/*  output uint16 Mf_emiss_count_real_uavn1[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidEmissRealCount(void)
{
   if (Coup_decel_progr_inj_a_emiss != 0)
   {
      Mf_emiss_count_real_uavn1[0] = 0;
   }
   else
   {
      Mf_emiss_count_real_uavn1[0] = Mf_emiss_count_cyl_uavn1[0];
   }

   if (Coup_decel_progr_inj_b_emiss != 0)
   {
      Mf_emiss_count_real_uavn1[1] = 0;
   }
   else
   {
      Mf_emiss_count_real_uavn1[1] = Mf_emiss_count_cyl_uavn1[1];
   }

   if (Coup_decel_progr_inj_c_emiss != 0)
   {
      Mf_emiss_count_real_uavn1[2] = 0;
   }
   else
   {
      Mf_emiss_count_real_uavn1[2] = Mf_emiss_count_cyl_uavn1[2];
   }

   if (Coup_decel_progr_inj_d_emiss != 0)
   {
      Mf_emiss_count_real_uavn1[3] = 0;
   }
   else
   {
      Mf_emiss_count_real_uavn1[3] = Mf_emiss_count_cyl_uavn1[3];
   }
}
/*------------------------------end of file-----------------------------------*/