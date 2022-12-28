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
/* !File            : MISFFAICTR_FCT3.C                                       */
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
/*   1 / MISFFAICTR_vidCataDamage                                             */
/*   2 / MISFFAICTR_vidRoughRdNoDetCatDam                                     */
/*   3 / MISFFAICTR_vidCatDamWghtRealCnt                                      */
/*   4 / MISFFAICTR_vidCataDamageSum                                          */
/*   5 / MISFFAICTR_vidMfCatDamRealSum                                        */
/*   6 / MISFFAICTR_vidMfDetectedCatDam                                       */
/*   7 / MISFFAICTR_vidMfDetected3Cyl                                         */
/*   8 / MISFFAICTR_vidMfDetected4Cyl                                         */
/*   9 / MISFFAICTR_vidMfDet4Cyl                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_FCT3.C_$*/
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
/* !Function    :  MISFFAICTR_vidCataDamage                                   */
/* !Description :  Ce bloc permet si de la mauvaise route est                 */
/*                 détectée(Mf_rough_road_cat_sum_uavn0 >                     */
/*                 Mf_rough_road_cat_thresh_uacn0) .                          */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void MISFFAICTR_vidRoughRoadDetCatDam();                      */
/*  extf argret void MISFFAICTR_vidRoughRdNoDetCatDam();                      */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input uint8 Coupure_decel_progr_inj_prev;                                 */
/*  input uint32 Ext_dstVehMes;                                               */
/*  input uint16 Mf_AirInjDistThd_C;                                          */
/*  input uint16 Mf_rough_road_cat_sum_uavn0;                                 */
/*  input uint16 Mf_rough_road_cat_thresh_uacn0;                              */
/*  output uint8 Coup_decel_progr_inj_cat_dam;                                */
/*  output boolean Mf_bInhTotDef;                                             */
/*  output boolean Mf_cat_dam_test_achi_uavb0;                                */
/*  output uint8 Coupure_decel_progr_inj_prev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCataDamage(void)
{
   uint8  u8LocalCoupure_decel_progr_inj;
   uint32 u32LocalExt_dstVehMes;


   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   Coup_decel_progr_inj_cat_dam =
      (uint8)(u8LocalCoupure_decel_progr_inj | Coupure_decel_progr_inj_prev);

   VEMS_vidGET(Ext_dstVehMes, u32LocalExt_dstVehMes);
   if (u32LocalExt_dstVehMes >= Mf_AirInjDistThd_C)
   {
      Mf_bInhTotDef = 1;
   }
   else
   {
      Mf_bInhTotDef = 0;
   }

   if (Mf_rough_road_cat_sum_uavn0 >= Mf_rough_road_cat_thresh_uacn0)
   {
      VEMS_vidSET(Mf_cat_dam_test_achi_uavb0, 0);
      MISFFAICTR_vidRoughRoadDetCatDam();
   }
   else
   {
      VEMS_vidSET(Mf_cat_dam_test_achi_uavb0, 1);
      MISFFAICTR_vidRoughRdNoDetCatDam();
   }
   Coupure_decel_progr_inj_prev =
      (uint8)MATHSRV_udtMIN(u8LocalCoupure_decel_progr_inj, 15);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidRoughRdNoDetCatDam                           */
/* !Description :  Cette fonction permet d'Additionner des dommages causés au */
/*                 catalyseur par tous les misfires détectés sur l’ensemble   */
/*                 des cylindres.                                             */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFFAICTR_vidCatDamWghtRealCnt();                       */
/*  extf argret void MISFFAICTR_vidMfCatDamRealSum();                         */
/*  extf argret void MISFFAICTR_vidCataDamageSum();                           */
/*  extf argret void MISFFAICTR_vidMfDetectedCatDam();                        */
/*  extf argret void MISFFAICTR_vidCatDamCylCalc();                           */
/*  extf argret void MISFFAICTR_vidMisfireRateCatDam();                       */
/*  input uint8 Coup_decel_progr_inj_cat_dam;                                 */
/*  input boolean Mf_cat_dam_wgth_sum_diag_ena;                               */
/*  output boolean Coup_decel_progr_inj_a_catdam;                             */
/*  output boolean Coup_decel_progr_inj_b_catdam;                             */
/*  output boolean Coup_decel_progr_inj_c_catdam;                             */
/*  output boolean Coup_decel_progr_inj_d_catdam;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidRoughRdNoDetCatDam(void)
{
   if ((Coup_decel_progr_inj_cat_dam & 0x01) == 0x01)
   {
      Coup_decel_progr_inj_a_catdam = 1;
   }
   else
   {
      Coup_decel_progr_inj_a_catdam = 0;
   }
   if ((Coup_decel_progr_inj_cat_dam & 0x02) == 0x02)
   {
      Coup_decel_progr_inj_b_catdam = 1;
   }
   else
   {
      Coup_decel_progr_inj_b_catdam = 0;
   }
   if ((Coup_decel_progr_inj_cat_dam & 0x04) == 0x04)
   {
      Coup_decel_progr_inj_c_catdam = 1;
   }
   else
   {
      Coup_decel_progr_inj_c_catdam = 0;
   }
   if ((Coup_decel_progr_inj_cat_dam & 0x08) == 0x08)
   {
      Coup_decel_progr_inj_d_catdam = 1;
   }
   else
   {
      Coup_decel_progr_inj_d_catdam = 0;
   }
   MISFFAICTR_vidCatDamWghtRealCnt();
   MISFFAICTR_vidMfCatDamRealSum();
   MISFFAICTR_vidCataDamageSum();

   if (Mf_cat_dam_wgth_sum_diag_ena != 0)
   {
      MISFFAICTR_vidMfDetectedCatDam();
   }
   MISFFAICTR_vidCatDamCylCalc();
   MISFFAICTR_vidMisfireRateCatDam();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidCatDamWghtRealCnt                            */
/* !Description :  Dans cette fonction  est réalisée le vecteur somme des     */
/*                 poids des misfires réels.                                  */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Coup_decel_progr_inj_a_catdam;                              */
/*  input uint16 Mf_cat_dam_wght_count_cyl_uavn1[4];                          */
/*  input boolean Coup_decel_progr_inj_b_catdam;                              */
/*  input boolean Coup_decel_progr_inj_c_catdam;                              */
/*  input boolean Coup_decel_progr_inj_d_catdam;                              */
/*  output uint16 Mf_cat_dam_wght_count_real_uavn1[4];                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCatDamWghtRealCnt(void)
{
   if (Coup_decel_progr_inj_a_catdam != 0)
   {
      Mf_cat_dam_wght_count_real_uavn1[0] = 0;
   }
   else
   {
      Mf_cat_dam_wght_count_real_uavn1[0] = Mf_cat_dam_wght_count_cyl_uavn1[0];
   }
   if (Coup_decel_progr_inj_b_catdam != 0)
   {
      Mf_cat_dam_wght_count_real_uavn1[1] = 0;
   }
   else
   {
      Mf_cat_dam_wght_count_real_uavn1[1] = Mf_cat_dam_wght_count_cyl_uavn1[1];
   }
   if (Coup_decel_progr_inj_c_catdam != 0)
   {
      Mf_cat_dam_wght_count_real_uavn1[2] = 0;
   }
   else
   {
      Mf_cat_dam_wght_count_real_uavn1[2] = Mf_cat_dam_wght_count_cyl_uavn1[2];
   }
   if (Coup_decel_progr_inj_d_catdam != 0)
   {
      Mf_cat_dam_wght_count_real_uavn1[3] = 0;
   }
   else
   {
      Mf_cat_dam_wght_count_real_uavn1[3] = Mf_cat_dam_wght_count_cyl_uavn1[3];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidCataDamageSum                                */
/* !Description :  Cette fonction additionne les dommages causés au catalyseur*/
/*                 par tous les misfires détectés (sauf en cas de coupure     */
/*                 d’injection) sur l’ensemble des cylindres.                 */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 index)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_cat_dam_wght_count_real_uavn1[4];                         */
/*  input uint16 Mf_cat_dam_wght_sum_thd_tq_lim;                              */
/*  input uint16 Mf_sum_min_thresh_tq_lim_uacn0;                              */
/*  input uint16 Mf_cat_dam_wght_sum_thresh;                                  */
/*  input uint16 Mf_sum_min_thresh_uacn0;                                     */
/*  input boolean Mf_cat_dam_wgth_sum_diag_ena;                               */
/*  input uint16 Mf_cat_dam_sum_real_uavn0;                                   */
/*  output uint16 Mf_cat_dam_wgth_sum_uavn0;                                  */
/*  output boolean Mf_cat_dam_wgth_sum_diag_ena;                              */
/*  output boolean Mf_cat_dam_det_uavb0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCataDamageSum(void)
{
   boolean bLocalEngTqLimORngDmgMDAll;
   uint16  u16LocalMfCatDamWgthSumDiagEna;
   uint16  u16LocalMfCatDamDetUavb0;
   uint32  u32LocalMfCatDamWgthSumUavn0;
   uint32  u32LocalMfCatDamWgthSumDiag;


   bLocalEngTqLimORngDmgMDAll = GDGAR_bGetFRM(FRM_FRM_ENGTQLIMORNGDMGCATMDALL);
   u32LocalMfCatDamWgthSumUavn0 = ( Mf_cat_dam_wght_count_real_uavn1[0]
                                  + Mf_cat_dam_wght_count_real_uavn1[1]
                                  + Mf_cat_dam_wght_count_real_uavn1[2]
                                  + Mf_cat_dam_wght_count_real_uavn1[3]);
   Mf_cat_dam_wgth_sum_uavn0 = (uint16)((u32LocalMfCatDamWgthSumUavn0 + 2) / 4);

   if (bLocalEngTqLimORngDmgMDAll != 0)
   {
      u16LocalMfCatDamWgthSumDiagEna = Mf_cat_dam_wght_sum_thd_tq_lim;
      u16LocalMfCatDamDetUavb0 = Mf_sum_min_thresh_tq_lim_uacn0;
   }
   else
   {
      u16LocalMfCatDamWgthSumDiagEna = Mf_cat_dam_wght_sum_thresh;
      u16LocalMfCatDamDetUavb0 = Mf_sum_min_thresh_uacn0;
   }
   u32LocalMfCatDamWgthSumDiag = (uint32)(u16LocalMfCatDamWgthSumDiagEna * 4);

   if (u32LocalMfCatDamWgthSumUavn0 > u32LocalMfCatDamWgthSumDiag)
   {
      Mf_cat_dam_wgth_sum_diag_ena = 1;
   }
   else
   {
      Mf_cat_dam_wgth_sum_diag_ena = 0;
   }

   if (  (Mf_cat_dam_wgth_sum_diag_ena != 0)
      && (Mf_cat_dam_sum_real_uavn0 > u16LocalMfCatDamDetUavb0))
   {
      VEMS_vidSET(Mf_cat_dam_det_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Mf_cat_dam_det_uavb0, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCatDamRealSum                              */
/* !Description :  Dans cette fonction on réalise la somme des misfires réels */
/*                 sur les PMH relatifs à la stratégie.                       */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Coup_decel_progr_inj_a_catdam;                              */
/*  input uint16 Mf_cat_dam_sum1_uavn0;                                       */
/*  input boolean Coup_decel_progr_inj_b_catdam;                              */
/*  input uint16 Mf_cat_dam_sum2_uavn0;                                       */
/*  input boolean Coup_decel_progr_inj_c_catdam;                              */
/*  input uint16 Mf_cat_dam_sum3_uavn0;                                       */
/*  input boolean Coup_decel_progr_inj_d_catdam;                              */
/*  input uint16 Mf_cat_dam_sum4_uavn0;                                       */
/*  output uint16 Mf_cat_dam_sum_real_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCatDamRealSum(void)
{
   uint32 u32LocalMfCatDamSumRealUavn0;


   u32LocalMfCatDamSumRealUavn0 = 0;
   if (Coup_decel_progr_inj_a_catdam == 0)
   {
      u32LocalMfCatDamSumRealUavn0 = u32LocalMfCatDamSumRealUavn0
                                     + Mf_cat_dam_sum1_uavn0;
   }
   if (Coup_decel_progr_inj_b_catdam == 0)
   {
      u32LocalMfCatDamSumRealUavn0 = u32LocalMfCatDamSumRealUavn0
                                     + Mf_cat_dam_sum2_uavn0;
   }
   if (Coup_decel_progr_inj_c_catdam == 0)
   {
      u32LocalMfCatDamSumRealUavn0 = u32LocalMfCatDamSumRealUavn0
                                     + Mf_cat_dam_sum3_uavn0;
   }
   if (Coup_decel_progr_inj_d_catdam == 0)
   {
      u32LocalMfCatDamSumRealUavn0 = u32LocalMfCatDamSumRealUavn0
                                     + Mf_cat_dam_sum4_uavn0;
   }
   Mf_cat_dam_sum_real_uavn0 =
      (uint16)MATHSRV_udtMIN(u32LocalMfCatDamSumRealUavn0, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfDetectedCatDam                             */
/* !Description :  Ce bloc permet de déterminer si les misfires « dommage     */
/*                 catalyseur » ont lieu préférentiellement sur un cylindre ou*/
/*                 si tous les cylindres sont affectés.                       */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_018.01                                     */
/*                 VEMS_R_09_00890_019.01                                     */
/*                 VEMS_R_09_00890_021.01                                     */
/*                 VEMS_R_09_00890_027.01                                     */
/*                 VEMS_R_09_00890_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidMisfireTotal();                            */
/*  extf argret void MISFFAICTR_vidMfDetected3Cyl();                          */
/*  extf argret void MISFFAICTR_vidMfDetected4Cyl();                          */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Mf_cat_dam_wght_count_real_uavn1[4];                         */
/*  input boolean Mf_cat_dam_3cyl1_uavb0;                                     */
/*  input boolean Mf_cat_dam_3cyl2_uavb0;                                     */
/*  input boolean Mf_cat_dam_3cyl3_uavb0;                                     */
/*  input boolean Mf_cat_dam_4cyl1_uavb0;                                     */
/*  input boolean Mf_cat_dam_4cyl2_uavb0;                                     */
/*  input boolean Mf_cat_dam_4cyl3_uavb0;                                     */
/*  input boolean Mf_cat_dam_4cyl4_uavb0;                                     */
/*  output uint16 Mf_cat_dam_wght_count_max_uavn;                             */
/*  output uint8 Mf_cat_dam_cyl_uavb0[4];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfDetectedCatDam(void)
{
   uint8  u8LocalExt_noCylEng;
   uint16 u16LocalCatDamWghtCountReal;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   u16LocalCatDamWghtCountReal =
      (uint16)MATHSRV_udtMAX(Mf_cat_dam_wght_count_real_uavn1[0],
                             Mf_cat_dam_wght_count_real_uavn1[1]);
   u16LocalCatDamWghtCountReal =
      (uint16)MATHSRV_udtMAX(u16LocalCatDamWghtCountReal,
                             Mf_cat_dam_wght_count_real_uavn1[2]);
   Mf_cat_dam_wght_count_max_uavn =
      (uint16)MATHSRV_udtMAX(u16LocalCatDamWghtCountReal,
                             Mf_cat_dam_wght_count_real_uavn1[3]);

   MISFFAICTR_vidMisfireTotal();
   MISFFAICTR_vidMfDetected3Cyl();

   if (u8LocalExt_noCylEng == 3)
   {
      if (Mf_cat_dam_3cyl1_uavb0 != 0)
      {
         Mf_cat_dam_cyl_uavb0[0] = 1;
      }
      else
      {
         Mf_cat_dam_cyl_uavb0[0] = 0;
      }

      if (Mf_cat_dam_3cyl2_uavb0 != 0)
      {
         Mf_cat_dam_cyl_uavb0[1] = 1;
      }
      else
      {
         Mf_cat_dam_cyl_uavb0[1] = 0;
      }

      if (Mf_cat_dam_3cyl3_uavb0 != 0)
      {
         Mf_cat_dam_cyl_uavb0[2] = 1;
      }
      else
      {
         Mf_cat_dam_cyl_uavb0[2] = 0;
      }
      Mf_cat_dam_cyl_uavb0[3] = 0;
   }
   else
   {
      if (u8LocalExt_noCylEng == 4)
      {
         MISFFAICTR_vidMfDetected4Cyl();

         if (Mf_cat_dam_4cyl1_uavb0 != 0)
         {
            Mf_cat_dam_cyl_uavb0[0] = 1;
         }
         else
         {
            Mf_cat_dam_cyl_uavb0[0] = 0;
         }

         if (Mf_cat_dam_4cyl2_uavb0 != 0)
         {
            Mf_cat_dam_cyl_uavb0[1] = 1;
         }
         else
         {
            Mf_cat_dam_cyl_uavb0[1] = 0;
         }

         if (Mf_cat_dam_4cyl3_uavb0 != 0)
         {
            Mf_cat_dam_cyl_uavb0[2] = 1;
         }
         else
         {
            Mf_cat_dam_cyl_uavb0[2] = 0;
         }

         if (Mf_cat_dam_4cyl4_uavb0 != 0)
         {
            Mf_cat_dam_cyl_uavb0[3] = 1;
         }
         else
         {
            Mf_cat_dam_cyl_uavb0[3] = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfDetected3Cyl                               */
/* !Description :  Cette fonction détermine les cylindres en misfire          */
/*                 destruction de catalyseur, pour un fonctionnement en trois */
/*                 cylindres.Ainsi en trois cylindre seul un défaut cylindre  */
/*                 identifiés peut être mémorisé.                             */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_cat_dam_wght_count_real_uavn1[4];                         */
/*  input uint16 Mf_cat_dam_wght_count_max_uavn;                              */
/*  input boolean Mf_bInhTotDef;                                              */
/*  input uint16 Mf_cat_dam_wgth_sum_uavn0;                                   */
/*  input uint16 Mf_cat_dam_wght_thresh_uacn0;                                */
/*  input boolean Misf_Defaut_TotalMisf_perCy1;                               */
/*  input boolean Misf_Defaut_TotalMisf_perCy2;                               */
/*  input boolean Misf_Defaut_TotalMisf_perCy3;                               */
/*  input uint8 Mf_cat_dam_nb_cyl_max_uavn1;                                  */
/*  input uint8 Mf_cat_dam_nb_cyl_max_uavn2;                                  */
/*  input uint8 Mf_cat_dam_nb_cyl_max_uavn3;                                  */
/*  input uint8 Mf_cat_dam_nb_cyl_max_uavn4;                                  */
/*  output boolean Mf_cat_dam_3cyl1_uavb0;                                    */
/*  output boolean Mf_cat_dam_3cyl2_uavb0;                                    */
/*  output boolean Mf_cat_dam_3cyl3_uavb0;                                    */
/*  output uint8 Mf_cat_dam_nb_cyl_max_uavn1;                                 */
/*  output uint8 Mf_cat_dam_nb_cyl_max_uavn2;                                 */
/*  output uint8 Mf_cat_dam_nb_cyl_max_uavn3;                                 */
/*  output uint8 Mf_cat_dam_nb_cyl_max_uavn4;                                 */
/*  output uint16 Mf_cat_dam_no_cyl_max1_uavn;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfDetected3Cyl(void)
{
   uint8   au8LocalMfNbCylMaxUavn[MISFFAICTR_u8CYL_LENGTH];
   uint8   u8LocalIndex;
   uint8   u8LocalCatDamNoCylMax1;
   uint32  u32LocalCatDamWgthSum;
   uint32  au32LocalMfCatCountMax[MISFFAICTR_u8CYL_LENGTH];


   for (u8LocalIndex = 0; u8LocalIndex < 3; u8LocalIndex++)
   {
      if (Mf_cat_dam_wght_count_real_uavn1[u8LocalIndex]
         != Mf_cat_dam_wght_count_max_uavn)
      {
         au8LocalMfNbCylMaxUavn[u8LocalIndex] = 0;
         au32LocalMfCatCountMax[u8LocalIndex] = 0;
      }
      else
      {
         au8LocalMfNbCylMaxUavn[u8LocalIndex] = (uint8)(u8LocalIndex + 1);
         au32LocalMfCatCountMax[u8LocalIndex] =
            (uint32)( Mf_cat_dam_wght_count_max_uavn * 16384);
      }
   }

   if (Mf_bInhTotDef != 0)
   {
      u32LocalCatDamWgthSum = (uint32)( Mf_cat_dam_wgth_sum_uavn0
                                      * Mf_cat_dam_wght_thresh_uacn0);

      if (u32LocalCatDamWgthSum <= au32LocalMfCatCountMax[0])
      {
         Mf_cat_dam_3cyl1_uavb0 = 1;
      }
      else
      {
         Mf_cat_dam_3cyl1_uavb0 = 0;
      }
      if (u32LocalCatDamWgthSum <= au32LocalMfCatCountMax[1])
      {
         Mf_cat_dam_3cyl2_uavb0 = 1;
      }
      else
      {
         Mf_cat_dam_3cyl2_uavb0 = 0;
      }
      if (u32LocalCatDamWgthSum <= au32LocalMfCatCountMax[2])

      {
         Mf_cat_dam_3cyl3_uavb0 = 1;
      }
      else
      {
         Mf_cat_dam_3cyl3_uavb0 = 0;
      }
   }
   else
   {
      Mf_cat_dam_3cyl1_uavb0 = Misf_Defaut_TotalMisf_perCy1;
      Mf_cat_dam_3cyl2_uavb0 = Misf_Defaut_TotalMisf_perCy2;
      Mf_cat_dam_3cyl3_uavb0 = Misf_Defaut_TotalMisf_perCy3;
   }
   if (Mf_cat_dam_wght_count_real_uavn1[3] != Mf_cat_dam_wght_count_max_uavn)
   {
      au8LocalMfNbCylMaxUavn[3] = 0;
   }
   else
   {
      au8LocalMfNbCylMaxUavn[3] = 4;
   }
   Mf_cat_dam_nb_cyl_max_uavn1 = au8LocalMfNbCylMaxUavn[0];
   Mf_cat_dam_nb_cyl_max_uavn2 = au8LocalMfNbCylMaxUavn[1];
   Mf_cat_dam_nb_cyl_max_uavn3 = au8LocalMfNbCylMaxUavn[2];
   Mf_cat_dam_nb_cyl_max_uavn4 = au8LocalMfNbCylMaxUavn[3];

   u8LocalCatDamNoCylMax1 = (uint8)MATHSRV_udtMAX(Mf_cat_dam_nb_cyl_max_uavn1,
                                                  Mf_cat_dam_nb_cyl_max_uavn2);
   u8LocalCatDamNoCylMax1 = (uint8)MATHSRV_udtMAX(u8LocalCatDamNoCylMax1,
                                                  Mf_cat_dam_nb_cyl_max_uavn3);
   u8LocalCatDamNoCylMax1 = (uint8)MATHSRV_udtMAX(u8LocalCatDamNoCylMax1,
                                                  Mf_cat_dam_nb_cyl_max_uavn4);
   Mf_cat_dam_no_cyl_max1_uavn = (uint16)(u8LocalCatDamNoCylMax1 * 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfDetected4Cyl                               */
/* !Description :  Cette fonction détermine les cylindres en misfire          */
/*                 destruction de catalyseur, pour un fonctionnement en quatre*/
/*                   cylindres. Ainsi en quatre cylindres seul deux défauts   */
/*                 cylindre identifié peut être mémorisé.                     */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void MISFFAICTR_vidMfDet4Cyl();                               */
/*  input uint16 Mf_cat_dam_wght_count_real_uavn1[4];                         */
/*  input uint16 Mf_cat_dam_wght_count_max_uavn;                              */
/*  input uint16 Mf_cat_dam_wght_count_real_red[4];                           */
/*  input uint16 Mf_cat_dam_wght_count_max2_uavn;                             */
/*  input uint16 Mf_cat_dam_no_cyl_max1_uavn;                                 */
/*  output uint16 Mf_cat_dam_wght_count_real_red[4];                          */
/*  output uint16 Mf_cat_dam_wght_count_max2_uavn;                            */
/*  output uint16 Mf_cat_dam_no_cyl_max2_uavn;                                */
/*  output uint16 Mf_cat_dam_4cyl1_int;                                       */
/*  output uint16 Mf_cat_dam_4cyl2_int;                                       */
/*  output uint16 Mf_cat_dam_4cyl3_int;                                       */
/*  output uint16 Mf_cat_dam_4cyl4_int;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfDetected4Cyl(void)
{
   uint8   u8LocalIndex;
   uint16  u16LocalWghtCountMax2;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      if (Mf_cat_dam_wght_count_real_uavn1[u8LocalIndex]
         != Mf_cat_dam_wght_count_max_uavn)
      {
         Mf_cat_dam_wght_count_real_red[u8LocalIndex] =
            Mf_cat_dam_wght_count_real_uavn1[u8LocalIndex];
      }
      else
      {
         Mf_cat_dam_wght_count_real_red[u8LocalIndex] = 0;
      }
   }

   u16LocalWghtCountMax2 =
      (uint16)MATHSRV_udtMAX(Mf_cat_dam_wght_count_real_red[0],
                             Mf_cat_dam_wght_count_real_red[1]);
   u16LocalWghtCountMax2 =
      (uint16)MATHSRV_udtMAX(u16LocalWghtCountMax2,
                             Mf_cat_dam_wght_count_real_red[2]);
   Mf_cat_dam_wght_count_max2_uavn =
      (uint16)MATHSRV_udtMAX(u16LocalWghtCountMax2,
                             Mf_cat_dam_wght_count_real_red[3]);

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      if (Mf_cat_dam_wght_count_real_red[u8LocalIndex]
         == Mf_cat_dam_wght_count_max2_uavn)
      {
         Mf_cat_dam_no_cyl_max2_uavn = (uint16)((u8LocalIndex + 1) * 4);
      }
   }
   switch(Mf_cat_dam_no_cyl_max1_uavn)
   {
      case 4 :
         Mf_cat_dam_4cyl1_int = Mf_cat_dam_wght_count_max_uavn;
         Mf_cat_dam_4cyl2_int = 0;
         Mf_cat_dam_4cyl3_int = 0;
         Mf_cat_dam_4cyl4_int = 0;
      break;
      case 8 :
         Mf_cat_dam_4cyl1_int = 0;
         Mf_cat_dam_4cyl2_int = Mf_cat_dam_wght_count_max_uavn;
         Mf_cat_dam_4cyl3_int = 0;
         Mf_cat_dam_4cyl4_int = 0;
      break;
      case 12 :
         Mf_cat_dam_4cyl1_int = 0;
         Mf_cat_dam_4cyl2_int = 0;
         Mf_cat_dam_4cyl3_int = Mf_cat_dam_wght_count_max_uavn;
         Mf_cat_dam_4cyl4_int = 0;
      break;
      case 16 :
         Mf_cat_dam_4cyl1_int = 0;
         Mf_cat_dam_4cyl2_int = 0;
         Mf_cat_dam_4cyl3_int = 0;
         Mf_cat_dam_4cyl4_int = Mf_cat_dam_wght_count_max_uavn;
      break;
      default :
         SWFAIL_vidSoftwareErrorHook();
      break;
   }
   MISFFAICTR_vidMfDet4Cyl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfDet4Cyl                                    */
/* !Description :  Cette fonction détermine les cylindres en misfire          */
/*                 destruction de catalyseur, pour un fonctionnement en quatre*/
/*                   cylindres. Ainsi en quatre cylindres seul deux défauts   */
/*                 cylindre identifié peut être mémorisé.                     */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Mf_bInhTotDef;                                              */
/*  input uint16 Mf_cat_dam_wgth_sum_uavn0;                                   */
/*  input uint16 Mf_cat_dam_wght_thresh_uacn0;                                */
/*  input uint16 Mf_cat_dam_wght_count_max2_uavn;                             */
/*  input uint16 Mf_cat_dam_4cyl1_int;                                        */
/*  input uint16 Mf_cat_dam_4cyl2_int;                                        */
/*  input uint16 Mf_cat_dam_4cyl3_int;                                        */
/*  input uint16 Mf_cat_dam_4cyl4_int;                                        */
/*  input uint16 Mf_cat_dam_no_cyl_max2_uavn;                                 */
/*  input boolean Mf_cat_dam_4cyl1_uavb0;                                     */
/*  input boolean Mf_cat_dam_4cyl2_uavb0;                                     */
/*  input boolean Mf_cat_dam_4cyl3_uavb0;                                     */
/*  input boolean Mf_cat_dam_4cyl4_uavb0;                                     */
/*  input boolean Misf_Defaut_TotalMisf_perCy1;                               */
/*  input boolean Misf_Defaut_TotalMisf_perCy2;                               */
/*  input boolean Misf_Defaut_TotalMisf_perCy3;                               */
/*  input boolean Misf_Defaut_TotalMisf_perCy4;                               */
/*  output boolean Mf_cat_dam_4cyl1_uavb0;                                    */
/*  output boolean Mf_cat_dam_4cyl2_uavb0;                                    */
/*  output boolean Mf_cat_dam_4cyl3_uavb0;                                    */
/*  output boolean Mf_cat_dam_4cyl4_uavb0;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfDet4Cyl(void)
{
   uint8   u8LocalIndex;
   uint8   au8LocalMfCatDam4cylUavb1[MISFFAICTR_u8CYL_LENGTH];
   uint16  au16LocalMfCatDam4cylInt[MISFFAICTR_u8CYL_LENGTH];
   uint32  u32LocalCatDamWgthSum;
   uint32  u32Local4Cyl;


   if (Mf_bInhTotDef != 0)
   {
      u32LocalCatDamWgthSum = (uint32)( Mf_cat_dam_wgth_sum_uavn0
                                      * Mf_cat_dam_wght_thresh_uacn0);

      if (Mf_cat_dam_wght_count_max2_uavn == 0)
      {
         au16LocalMfCatDam4cylInt[0] = Mf_cat_dam_4cyl1_int;
         au16LocalMfCatDam4cylInt[1] = Mf_cat_dam_4cyl2_int;
         au16LocalMfCatDam4cylInt[2] = Mf_cat_dam_4cyl3_int;
         au16LocalMfCatDam4cylInt[3] = Mf_cat_dam_4cyl4_int;
         for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
         {
            u32Local4Cyl = (uint32)( au16LocalMfCatDam4cylInt[u8LocalIndex]
                                   * 16384);
            if (u32LocalCatDamWgthSum <= u32Local4Cyl)
            {
               au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 1;
            }
            else
            {
               au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 0;
            }
         }
      }
      else
      {
         switch(Mf_cat_dam_no_cyl_max2_uavn)
         {
            case 4 :
               au16LocalMfCatDam4cylInt[0] = Mf_cat_dam_wght_count_max2_uavn;
               au16LocalMfCatDam4cylInt[1] = Mf_cat_dam_4cyl2_int;
               au16LocalMfCatDam4cylInt[2] = Mf_cat_dam_4cyl3_int;
               au16LocalMfCatDam4cylInt[3] = Mf_cat_dam_4cyl4_int;

               for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
               {
                  u32Local4Cyl =
                     (uint32)(au16LocalMfCatDam4cylInt[u8LocalIndex] * 16384);
                  if (u32LocalCatDamWgthSum <= u32Local4Cyl)
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 1;
                  }
                  else
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 0;
                  }
               }
               break;

            case 8 :
               au16LocalMfCatDam4cylInt[0] = Mf_cat_dam_4cyl1_int;
               au16LocalMfCatDam4cylInt[1] = Mf_cat_dam_wght_count_max2_uavn;
               au16LocalMfCatDam4cylInt[2] = Mf_cat_dam_4cyl3_int;
               au16LocalMfCatDam4cylInt[3] = Mf_cat_dam_4cyl4_int;
               for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
               {
                  u32Local4Cyl =
                     (uint32)(au16LocalMfCatDam4cylInt[u8LocalIndex] * 16384);
                  if (u32LocalCatDamWgthSum <= u32Local4Cyl)
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 1;
                  }
                  else
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 0;
                  }
               }
               break;

            case 12 :
               au16LocalMfCatDam4cylInt[0] = Mf_cat_dam_4cyl1_int;
               au16LocalMfCatDam4cylInt[1] = Mf_cat_dam_4cyl2_int;
               au16LocalMfCatDam4cylInt[2] = Mf_cat_dam_wght_count_max2_uavn;
               au16LocalMfCatDam4cylInt[3] = Mf_cat_dam_4cyl4_int;
               for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
               {
                  u32Local4Cyl =
                     (uint32)(au16LocalMfCatDam4cylInt[u8LocalIndex] * 16384);
                  if (u32LocalCatDamWgthSum <= u32Local4Cyl)
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 1;
                  }
                  else
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 0;
                  }
               }
               break;

            case 16 :
               au16LocalMfCatDam4cylInt[0] = Mf_cat_dam_4cyl1_int;
               au16LocalMfCatDam4cylInt[1] = Mf_cat_dam_4cyl2_int;
               au16LocalMfCatDam4cylInt[2] = Mf_cat_dam_4cyl3_int;
               au16LocalMfCatDam4cylInt[3] = Mf_cat_dam_wght_count_max2_uavn;
               for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
               {
                  u32Local4Cyl =
                     (uint32)(au16LocalMfCatDam4cylInt[u8LocalIndex] * 16384);
                  if (u32LocalCatDamWgthSum <= u32Local4Cyl)
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 1;
                  }
                  else
                  {
                     au8LocalMfCatDam4cylUavb1[u8LocalIndex] = 0;
                  }
               }
               break;

            default :
               if (Mf_cat_dam_4cyl1_uavb0 != 0)
               {
                  au8LocalMfCatDam4cylUavb1[0] = 1;
               }
               else
               {
                  au8LocalMfCatDam4cylUavb1[0] = 0;
               }
               if (Mf_cat_dam_4cyl2_uavb0 != 0)
               {
                  au8LocalMfCatDam4cylUavb1[1] = 1;
               }
               else
               {
                  au8LocalMfCatDam4cylUavb1[1] = 0;
               }
               if (Mf_cat_dam_4cyl3_uavb0 != 0)
               {
                  au8LocalMfCatDam4cylUavb1[2] = 1;
               }
               else
               {
                  au8LocalMfCatDam4cylUavb1[2] = 0;
               }
               if (Mf_cat_dam_4cyl4_uavb0 != 0)
               {
                  au8LocalMfCatDam4cylUavb1[3] = 1;
               }
               else
               {
                  au8LocalMfCatDam4cylUavb1[3] = 0;
               }
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
      }
      if (au8LocalMfCatDam4cylUavb1[0] != 0)
      {
         Mf_cat_dam_4cyl1_uavb0 = 1;
      }
      else
      {
         Mf_cat_dam_4cyl1_uavb0 = 0;
      }
      if (au8LocalMfCatDam4cylUavb1[1] != 0)
      {
         Mf_cat_dam_4cyl2_uavb0 = 1;
      }
      else
      {
         Mf_cat_dam_4cyl2_uavb0 = 0;
      }
      if (au8LocalMfCatDam4cylUavb1[2] != 0)
      {
         Mf_cat_dam_4cyl3_uavb0 = 1;
      }
      else
      {
         Mf_cat_dam_4cyl3_uavb0 = 0;
      }
      if (au8LocalMfCatDam4cylUavb1[3] != 0)
      {
         Mf_cat_dam_4cyl4_uavb0 = 1;
      }
      else
      {
         Mf_cat_dam_4cyl4_uavb0 = 0;
      }
   }
   else
   {
      Mf_cat_dam_4cyl1_uavb0 = Misf_Defaut_TotalMisf_perCy1;
      Mf_cat_dam_4cyl2_uavb0 = Misf_Defaut_TotalMisf_perCy2;
      Mf_cat_dam_4cyl3_uavb0 = Misf_Defaut_TotalMisf_perCy3;
      Mf_cat_dam_4cyl4_uavb0 = Misf_Defaut_TotalMisf_perCy4;
   }
}
/*------------------------------end of file-----------------------------------*/