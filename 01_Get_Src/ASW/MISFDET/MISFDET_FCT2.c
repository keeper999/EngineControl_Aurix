/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDET                                                 */
/* !Description     : MISFDET component                                       */
/*                                                                            */
/* !Module          : MISFDET                                                 */
/* !Description     : Algorithmes de détection de misfire                     */
/*                                                                            */
/* !File            : MISFDET_FCT2.C                                          */
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
/*   1 / MISFDET_vidCalcHalfRev                                               */
/*   2 / MISFDET_vidCombDet                                                   */
/*   3 / MISFDET_vidCombAlgoThresh                                            */
/*   4 / MISFDET_vidPfiltDet                                                  */
/*   5 / MISFDET_vidPfiltAlgoThresh                                           */
/*   6 / MISFDET_vidCondGlobalStab                                            */
/*   7 / MISFDET_vidCondStabNormal                                            */
/*   8 / MISFDET_vidCondStabIdle                                              */
/*   9 / MISFDET_vidAlgoConTempo                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5158467 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068493                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDET/MISFDET_FCT2.C_v     $*/
/* $Revision::   1.11     $$Author::   wbouach        $$Date::   27 Mar 2014 $*/
/* $Author::   wbouach                                $$Date::   27 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFDET.h"
#include "MISFDET_L.h"
#include "MISFDET_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidCalcHalfRev                                     */
/* !Description :  Le calcul d’une durée moyenne des 4 derniers demi-tours    */
/*                 moteur pour un moteur 4 cylindres, 3 derniers demitours    */
/*                 moteur pour un moteur 3 cylindres                          */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Periode_moteur;                                              */
/*  input uint16 Mf_duree_demi_tour_n_less_2;                                 */
/*  input uint16 Mf_duree_demi_tour_n_less_1;                                 */
/*  input uint16 Mf_duree_demi_tour_n;                                        */
/*  input uint16 Mf_duree_demi_tour_n_less_3;                                 */
/*  output uint16 Mf_duree_demi_tour_n_less_3;                                */
/*  output uint16 Mf_duree_demi_tour_n_less_2;                                */
/*  output uint16 Mf_duree_demi_tour_n_less_1;                                */
/*  output uint16 Mf_duree_demi_tour_n;                                       */
/*  output uint16 Misf_HalfRevSum;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidCalcHalfRev(void)
{
   uint8  u8LocalExt_noCylEng;
   uint16 u16LocalPeriode_moteur;
   uint32 u32LocalSum;

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);
   Mf_duree_demi_tour_n_less_3 = Mf_duree_demi_tour_n_less_2;
   Mf_duree_demi_tour_n_less_2 = Mf_duree_demi_tour_n_less_1;
   Mf_duree_demi_tour_n_less_1 = Mf_duree_demi_tour_n;
   Mf_duree_demi_tour_n = u16LocalPeriode_moteur;

   switch (u8LocalExt_noCylEng)
   {
      case 1:
      case 2:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
         u32LocalSum = Mf_duree_demi_tour_n
                     + Mf_duree_demi_tour_n_less_1
                     + Mf_duree_demi_tour_n_less_2
                     + Mf_duree_demi_tour_n_less_3;
         break;

      case 3:
         u32LocalSum = Mf_duree_demi_tour_n
                     + Mf_duree_demi_tour_n_less_1
                     + Mf_duree_demi_tour_n_less_2;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         u32LocalSum = 0;
         break;
   }
   Misf_HalfRevSum = (uint16)((u32LocalSum * 16384)
                   /          78125);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidCombDet                                         */
/* !Description :  Calcul de l'indice de confiance en la détection de misfire */
/*                 par l'algorithme combustion                                */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDET_vidCombAlgoThresh();                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_comb_algo_thresh_uavn0;                                   */
/*  input sint16 Mf_comb_algo_out_uavn0;                                      */
/*  output sint16 Mf_comb_algo_trust_uavn0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidCombDet(void)
{
   uint16 u16LocalMf_comb_algo_thresh_uavn;
   sint16 s16LocalMf_comb_algo_trust_uavn0;
   sint32 s32LocalCombAlgoTrust;


   MISFDET_vidCombAlgoThresh();
   VEMS_vidGET(Mf_comb_algo_thresh_uavn0, u16LocalMf_comb_algo_thresh_uavn);
   if (u16LocalMf_comb_algo_thresh_uavn != 0)
   {
      s32LocalCombAlgoTrust = (  (sint32)(Mf_comb_algo_out_uavn0 * 8192)
                              /  u16LocalMf_comb_algo_thresh_uavn);
      s16LocalMf_comb_algo_trust_uavn0 =
         (sint16)MATHSRV_udtCLAMP(s32LocalCombAlgoTrust,
                                  -32768,
                                  32767);
   }
   else
   {
      if (Mf_comb_algo_out_uavn0 >= 0)
      {
         s16LocalMf_comb_algo_trust_uavn0 = 32767;
      }
      else
      {
         s16LocalMf_comb_algo_trust_uavn0 = -32768;
      }
   }
   VEMS_vidSET(Mf_comb_algo_trust_uavn0, s16LocalMf_comb_algo_trust_uavn0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidCombAlgoThresh                                  */
/* !Description :  Calcul du seuil de l’algorithme combustion (dépend du      */
/*                 couple indiqué et du régime)                               */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Gear_engaged;                                                 */
/*  input uint16 Mf_cmi_neut_bkpt_uacn1[7];                                   */
/*  input uint8 Mf_eng_spd_neut_bkpt_uacn1[16];                               */
/*  input uint16 Mf_comb_algo_neut_map_uacn2[7][16];                          */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint16 Mf_comb_algo_thresh_map_uacn2[7][16];                        */
/*  input uint16 Mf_comb_algo_neut;                                           */
/*  input uint16 Mf_comb_algo_thresh;                                         */
/*  input boolean Mf_adap_shrt_no_rlzd_uavb0;                                 */
/*  input boolean Mf_adap_no_rlzd_UT_uavb0;                                   */
/*  input uint8 Mf_gain_thresh_map_uacn1[16];                                 */
/*  input uint8 Mf_gain_thresh_map_UT_uacn1[16];                              */
/*  output uint16 Mf_comb_algo_neut;                                          */
/*  output uint16 Mf_comb_algo_thresh;                                        */
/*  output uint16 Mf_comb_algo_thresh_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidCombAlgoThresh(void)
{
   boolean bLocalMf_adap_shrt_no_rlzd_uavb0;
   boolean bLocalFRM_bLimMisfDetShoWinThd;
   boolean bLocalMf_adap_no_rlzd_UT_uavb0;
   uint8   u8LocalGear_engaged;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalInterp1d;
   uint16  u16LocalIndicatedTorque;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalInterp2d;
   uint16  u16LocalMf_comb_algo_thresh_uavn;
   sint16  s16LocalEngLim_tqIdcEngCur;
   uint32  u32LocalCombAlgoThresh;
   sint32  s32LocalIndicatedTorque;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);

   s32LocalIndicatedTorque = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque,
                                                    0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Mf_cmi_neut_bkpt_uacn1,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Mf_eng_spd_neut_bkpt_uacn1,
                                               u8LocalRegime_moteur_32,
                                               16);
   Mf_comb_algo_neut = MATHSRV_u16Interp2d(&Mf_comb_algo_neut_map_uacn2[0][0],
                                          u16LocalParaX,
                                          u16LocalParaY,
                                          16);

   s32LocalIndicatedTorque = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque,
                                                    0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               16);
   Mf_comb_algo_thresh =
      MATHSRV_u16Interp2d(&Mf_comb_algo_thresh_map_uacn2[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          16);

   if (u8LocalGear_engaged == 0)
   {
      u16LocalInterp2d = Mf_comb_algo_neut;
   }
   else
   {
      u16LocalInterp2d = Mf_comb_algo_thresh;
   }

   VEMS_vidGET(Mf_adap_shrt_no_rlzd_uavb0, bLocalMf_adap_shrt_no_rlzd_uavb0);
   VEMS_vidGET(Mf_adap_no_rlzd_UT_uavb0, bLocalMf_adap_no_rlzd_UT_uavb0);
   bLocalFRM_bLimMisfDetShoWinThd = GDGAR_bGetFRM(FRM_FRM_LIMMISFDETSHOWINTHD);
   if (  (bLocalMf_adap_shrt_no_rlzd_uavb0 != 0)
      || (bLocalFRM_bLimMisfDetShoWinThd != 0))
   {
      if (bLocalMf_adap_no_rlzd_UT_uavb0 != 0)
      {
         u8LocalInterp1d = MATHSRV_u8Interp1d(Mf_gain_thresh_map_uacn1,
                                              u16LocalParaY);
      }
      else
      {
         u8LocalInterp1d = MATHSRV_u8Interp1d(Mf_gain_thresh_map_UT_uacn1,
                                              u16LocalParaY);
      }
      u32LocalCombAlgoThresh = (uint32)( (u8LocalInterp1d * u16LocalInterp2d)
                                       / 64);
      u16LocalMf_comb_algo_thresh_uavn =
         (uint16)MATHSRV_udtMIN(u32LocalCombAlgoThresh, 65535);
   }
   else
   {
      u16LocalMf_comb_algo_thresh_uavn = (uint16)(u16LocalInterp2d / 2);
   }
   VEMS_vidSET(Mf_comb_algo_thresh_uavn0, u16LocalMf_comb_algo_thresh_uavn);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidPfiltDet                                        */
/* !Description :  Calcul de l'indice de confiance en la détection de misfire */
/*                 par l'algorithme P_filte                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDET_vidPfiltAlgoThresh();                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Mf_p_filt_algo_thresh_uavn0;                                 */
/*  input sint16 Mf_p_filt_algo_out_uavn0;                                    */
/*  output sint16 Mf_p_filt_algo_trust_uavn0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidPfiltDet(void)
{
   uint16 u16LocalMf_p_filt_algo_thresh_ua;
   sint16 s16LocalMf_p_filt_algo_trust_uav;
   sint32 s32LocalCombAlgoTrust;


   MISFDET_vidPfiltAlgoThresh();
   VEMS_vidGET(Mf_p_filt_algo_thresh_uavn0, u16LocalMf_p_filt_algo_thresh_ua);
   if (u16LocalMf_p_filt_algo_thresh_ua != 0)
   {
      s32LocalCombAlgoTrust = (  (sint32)(Mf_p_filt_algo_out_uavn0 * 8192)
                              /  u16LocalMf_p_filt_algo_thresh_ua);
      s16LocalMf_p_filt_algo_trust_uav =
         (sint16)MATHSRV_udtCLAMP(s32LocalCombAlgoTrust,
                                  -32768,
                                  32767);
   }
   else
   {
      if (Mf_p_filt_algo_out_uavn0 >= 0)
      {
         s16LocalMf_p_filt_algo_trust_uav = 32767;
      }
      else
      {
         s16LocalMf_p_filt_algo_trust_uav = -32768;
      }
   }
   VEMS_vidSET(Mf_p_filt_algo_trust_uavn0, s16LocalMf_p_filt_algo_trust_uav);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidPfiltAlgoThresh                                 */
/* !Description :  Calcul du seuil de l’algorithme P filtre (dépend du régime */
/*                 et du couple indiqué )                                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Gear_engaged;                                                 */
/*  input uint16 Mf_cmi_neut_bkpt_uacn1[7];                                   */
/*  input uint8 Mf_eng_spd_neut_bkpt_uacn1[16];                               */
/*  input uint16 Mf_p_filt_algo_neut_map_uacn2[7][16];                        */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint16 Mf_p_filt_algo_thresh_map_uacn2[7][16];                      */
/*  input uint16 Mf_p_filt_algo_neut;                                         */
/*  input uint16 Mf_p_filt_algo_thresh;                                       */
/*  input boolean Mf_adap_lw_no_rlzd_uavb0;                                   */
/*  input boolean Mf_adap_no_rlzd_UT_uavb0;                                   */
/*  input uint8 Mf_gain_thresh_map_uacn1[16];                                 */
/*  input uint8 Mf_gain_thresh_map_UT_uacn1[16];                              */
/*  output uint16 Mf_p_filt_algo_neut;                                        */
/*  output uint16 Mf_p_filt_algo_thresh;                                      */
/*  output uint16 Mf_p_filt_algo_thresh_uavn0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidPfiltAlgoThresh(void)
{
   boolean bLocalMf_adap_lw_no_rlzd_uavb0;
   boolean bLocalFRM_bLimMisfDetLongWinThd;
   boolean bLocalMf_adap_no_rlzd_UT_uavb0;
   uint8   u8LocalGear_engaged;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalInterp1d;
   uint16  u16LocalIndicatedTorque;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalInterp2d;
   uint16  u16LocalMf_p_filt_algo_thresh_ua;
   sint16  s16LocalEngLim_tqIdcEngCur;
   uint32  u32LocalProd;
   sint32  s32LocalIndicatedTorque;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);

   s32LocalIndicatedTorque = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque,
                                                    0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Mf_cmi_neut_bkpt_uacn1,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Mf_eng_spd_neut_bkpt_uacn1,
                                               u8LocalRegime_moteur_32,
                                               16);
   Mf_p_filt_algo_neut =
         MATHSRV_u16Interp2d(&Mf_p_filt_algo_neut_map_uacn2[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             16);

   s32LocalIndicatedTorque = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque,
                                                    0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               16);
   Mf_p_filt_algo_thresh =
      MATHSRV_u16Interp2d(&Mf_p_filt_algo_thresh_map_uacn2[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          16);

   if (u8LocalGear_engaged == 0)
   {
      u16LocalInterp2d = Mf_p_filt_algo_neut;
   }
   else
   {
      u16LocalInterp2d = Mf_p_filt_algo_thresh;
   }

   VEMS_vidGET(Mf_adap_lw_no_rlzd_uavb0, bLocalMf_adap_lw_no_rlzd_uavb0);
   VEMS_vidGET(Mf_adap_no_rlzd_UT_uavb0, bLocalMf_adap_no_rlzd_UT_uavb0);
   bLocalFRM_bLimMisfDetLongWinThd =
      GDGAR_bGetFRM(FRM_FRM_LIMMISFDETLONGWINTHD);

   if (  (bLocalMf_adap_lw_no_rlzd_uavb0 != 0)
      || (bLocalFRM_bLimMisfDetLongWinThd != 0))
   {
      if (bLocalMf_adap_no_rlzd_UT_uavb0 != 0)
      {
         u8LocalInterp1d = MATHSRV_u8Interp1d(Mf_gain_thresh_map_uacn1,
                                              u16LocalParaY);
      }
      else
      {
         u8LocalInterp1d = MATHSRV_u8Interp1d(Mf_gain_thresh_map_UT_uacn1,
                                              u16LocalParaY);
      }
      u32LocalProd = (uint32)((u8LocalInterp1d * u16LocalInterp2d) / 32);
      u16LocalMf_p_filt_algo_thresh_ua = (uint16)MATHSRV_udtMIN(u32LocalProd,
                                                                65535);
      VEMS_vidSET(Mf_p_filt_algo_thresh_uavn0,
         u16LocalMf_p_filt_algo_thresh_ua);
   }
   else
   {
      VEMS_vidSET(Mf_p_filt_algo_thresh_uavn0, u16LocalInterp2d);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidCondGlobalStab                                  */
/* !Description :  Ce bloc vérifie si les conditions de fonctionnement        */
/*                 globales sont vérifiées pour que la stratégie de détection */
/*                 puisse être activée.                                       */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  PTS_R_5158467_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean Misf_bAcqWinOK;                                             */
/*  input boolean Cps_clutch_pedal_input;                                     */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Temperature_air;                                              */
/*  input uint32 Ext_dstVehMes;                                               */
/*  input boolean Flex_bInhDiagOBDAlcEst;                                     */
/*  input boolean Flex_bInhDiagOBDBlby;                                       */
/*  input uint16 Flex_tiDiagOBDAlcEst;                                        */
/*  input boolean CoPt_bSIP;                                                  */
/*  input boolean KnkMgt_prm_bInjCutOffRblCyl[4];                             */
/*  input boolean Flex_bInhDiagMisfAlcEst_C;                                  */
/*  input uint16 Flex_tiDiagMisfAlcEst_C;                                     */
/*  input boolean Flex_bInhDiagMisfBlby_C;                                    */
/*  input uint16 Mf_AirInjDistThd_C;                                          */
/*  input boolean Manu_inh_mf_alg_cond_cps;                                   */
/*  input uint16 MF_N_MIN_ACQ;                                                */
/*  input uint8 Mf_min_water_temp_uacn0;                                      */
/*  input uint8 Mf_min_air_temp_uacn0;                                        */
/*  input boolean Misf_bAcvSIPCond;                                           */
/*  output boolean Flex_bEnaDiagMisfAlcEst;                                   */
/*  output boolean Mf_bAcvCondGlobal;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidCondGlobalStab(void)
{
   boolean bLocalMisf_bAcqWinOK;
   boolean bLocalInhMisfDet;
   boolean bLocalCps_clutch_pedal_input;
   boolean bLocalKnkMgt_prm_InjCutOffRblCyl[4];
   /*QAC message (Msg(2:3204)) : no impact*/
   boolean bLocalFlex_bInhDiagOBDAlcEst;
   boolean bLocalFlex_bInhDiagOBDBlby;
   boolean bLocalInhDiagOBDCond;
   boolean bLocalCalc1;
   boolean bLocalOr1;
   boolean bLocalOr2;
   boolean bLocalCoPt_bSIP;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalTemperature_air;
   uint16  u16LocalMisfMinSpeedAcq;
   uint16  u16LocalDiagOBDAlcEst;
   uint32  u32LocalExt_dstVehMes;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Misf_bAcqWinOK, bLocalMisf_bAcqWinOK);
   VEMS_vidGET(Cps_clutch_pedal_input, bLocalCps_clutch_pedal_input);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   VEMS_vidGET(Ext_dstVehMes, u32LocalExt_dstVehMes);
   VEMS_vidGET(Flex_bInhDiagOBDAlcEst, bLocalFlex_bInhDiagOBDAlcEst);
   VEMS_vidGET(Flex_bInhDiagOBDBlby, bLocalFlex_bInhDiagOBDBlby);
   VEMS_vidGET(Flex_tiDiagOBDAlcEst, u16LocalDiagOBDAlcEst);
   VEMS_vidGET(CoPt_bSIP, bLocalCoPt_bSIP);
   VEMS_vidGET1DArray(KnkMgt_prm_bInjCutOffRblCyl,
                      4,
                      bLocalKnkMgt_prm_InjCutOffRblCyl);
   bLocalInhMisfDet = GDGAR_bGetFRM(FRM_FRM_INHMISFDET);

   if (  (bLocalFlex_bInhDiagOBDAlcEst == 0)
      || (Flex_bInhDiagMisfAlcEst_C != 0))
   {
      bLocalOr1 = 1;
      bLocalOr2 = 0;
   }
   else
   {
      bLocalOr1 = 0;
      if (u16LocalDiagOBDAlcEst >= Flex_tiDiagMisfAlcEst_C)
      {
         bLocalOr2 = 1;
      }
      else
      {
         bLocalOr2 = 0;
      }
   }
   VEMS_vidSET(Flex_bEnaDiagMisfAlcEst, bLocalOr2);

   if (  (  (bLocalOr1 != 0)
         || (bLocalOr2 != 0))
      && (  (bLocalFlex_bInhDiagOBDBlby == 0)
         || (Flex_bInhDiagMisfBlby_C != 0)))
   {
      bLocalInhDiagOBDCond = 1;
   }
   else
   {
      bLocalInhDiagOBDCond = 0;
   }

   if (  (  (  (u32LocalExt_dstVehMes >= Mf_AirInjDistThd_C)
            && (bLocalInhMisfDet == 0))
         || (u32LocalExt_dstVehMes < Mf_AirInjDistThd_C))
      && (  (bLocalCps_clutch_pedal_input == 0)
         || (Manu_inh_mf_alg_cond_cps != 0)))
   {
      bLocalCalc1 = 1;
   }
   else
   {
      bLocalCalc1 = 0;
   }

   u16LocalMisfMinSpeedAcq = (uint16)(MF_N_MIN_ACQ / 32);
   if (  (u8LocalRegime_moteur_32 > u16LocalMisfMinSpeedAcq)
      && (bLocalMisf_bAcqWinOK != 0)
      && (bLocalCalc1 != 0)
      && (u8LocalCoPTSt_stEng != Coupe_cale)
      && (u8LocalTemperature_eau > Mf_min_water_temp_uacn0)
      && (u8LocalTemperature_air > Mf_min_air_temp_uacn0)
      && (bLocalKnkMgt_prm_InjCutOffRblCyl[0] == 0)
      && (bLocalKnkMgt_prm_InjCutOffRblCyl[1] == 0)
      && (bLocalKnkMgt_prm_InjCutOffRblCyl[2] == 0)
      && (bLocalKnkMgt_prm_InjCutOffRblCyl[3] == 0)
      && (bLocalInhDiagOBDCond != 0)
      && (  (bLocalCoPt_bSIP == 0)
         || (Misf_bAcvSIPCond == 0))
      )
   {
      Mf_bAcvCondGlobal = 1;
   }
   else
   {
      Mf_bAcvCondGlobal = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidCondStabNormal                                  */
/* !Description :  Ce bloc vérifie si les conditions de fonctionnement        */
/*                 spécifiques pour l’algorithme hors ralenti sont vérifiées  */
/*                 pour que la stratégie de détection puisse être activée.    */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  PTS_R_5158467_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Gear_engaged;                                                 */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint16 Mf_cmi_min_map_uacn1[16];                                    */
/*  input sint16 Mf_cmi_min_hyst_uacn0;                                       */
/*  input boolean MISFDET_bOutMinHyst;                                        */
/*  input uint8 Mf_n_min_algo_cond_uacn0;                                     */
/*  input uint8 Mf_n_max_algo_cond_uacn0;                                     */
/*  input boolean Mf_bAcvCondGlobal;                                          */
/*  output boolean MISFDET_bOutMinHyst;                                       */
/*  output boolean Mf_bAcvCondNormRaw;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidCondStabNormal(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalGear_engaged;
   uint8  u8LocalEngine_running_state;
   uint8  u8LocalVitesse_vehicule;
   uint16 u16LocalPara;
   uint16 u16LocalMinCmi;
   sint16 s16LocalEngLim_tqIdcEngCur;
   sint32 s32LocalTorqLimitInd;
   sint32 s32LocalHystThreshold1;
   sint32 s32LocalHystThreshold2;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                              u8LocalRegime_moteur_32,
                                              16);
   u16LocalMinCmi = MATHSRV_u16Interp1d(Mf_cmi_min_map_uacn1,
                                        u16LocalPara);
   s32LocalTorqLimitInd = (sint32)(u16LocalMinCmi - 32000);
   s32LocalHystThreshold1 = s32LocalTorqLimitInd - Mf_cmi_min_hyst_uacn0;
   s32LocalHystThreshold2 = s32LocalTorqLimitInd + Mf_cmi_min_hyst_uacn0;
   if (MISFDET_bOutMinHyst == 0)
   {
      if (s16LocalEngLim_tqIdcEngCur >= s32LocalHystThreshold2)
      {
         MISFDET_bOutMinHyst = 1;
      }
      else
      {
         MISFDET_bOutMinHyst = 0;
      }
   }
   else
   {
      if (s16LocalEngLim_tqIdcEngCur <= s32LocalHystThreshold1)
      {
         MISFDET_bOutMinHyst = 0;
      }
      else
      {
         MISFDET_bOutMinHyst = 1;
      }
   }
   if (  (u8LocalRegime_moteur_32 > Mf_n_min_algo_cond_uacn0)
      && (u8LocalRegime_moteur_32 < Mf_n_max_algo_cond_uacn0)
      && (MISFDET_bOutMinHyst != 0)
      && (Mf_bAcvCondGlobal != 0)
      && (u8LocalGear_engaged != 0)
      && (u8LocalEngine_running_state != ERUN_ON_IDLE)
      && (u8LocalVitesse_vehicule > 0))
   {
      VEMS_vidSET(Mf_bAcvCondNormRaw, 1);
   }
   else
   {
      VEMS_vidSET(Mf_bAcvCondNormRaw, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidCondStabIdle                                    */
/* !Description :  Ce bloc vérifie si les conditions de fonctionnement        */
/*                 spécifiques pour l’algorithme ralenti sont vérifiées pour  */
/*                 que la stratégie de détection puisse être activée.         */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  PTS_R_5158467_005.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Gear_engaged;                                                 */
/*  input boolean IdlSys_bAcvAntiStall;                                       */
/*  input st07 Engine_running_state;                                          */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Mf_eng_spd_neut_bkpt_uacn1[16];                               */
/*  input uint16 Mf_cmi_min_idle_map_uacn1[16];                               */
/*  input sint16 Mf_cmi_min_idle_hyst_uacn0;                                  */
/*  input boolean MISFDET_bOutMinIdleHyst;                                    */
/*  input boolean Misf_bAcvAlgoEgdIdle_C;                                     */
/*  input boolean Mf_bAcvCondGlobal;                                          */
/*  output boolean MISFDET_bOutMinIdleHyst;                                   */
/*  output boolean Mf_bAcvCondIdleRaw;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidCondStabIdle(void)
{
   boolean bLocalIdlSys_bAcvAntiStall;
   boolean bLocalInhMisfDetCdnClcn;
   boolean bLocalCalc;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalVitesse_vehicule;
   uint8   u8LocalGear_engaged;
   uint8   u8LocalEngine_running_state;
   uint16  u16LocalPara;
   uint16  u16LocalMinCmiIdle;
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint32  s32LocalTorqLimitInd;
   sint32  s32LocalHystThreshold1;
   sint32  s32LocalHystThreshold2;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   VEMS_vidGET(IdlSys_bAcvAntiStall, bLocalIdlSys_bAcvAntiStall);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   bLocalInhMisfDetCdnClcn = GDGAR_bGetFRM(FRM_FRM_INHMISFDETCDNCLCN);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(Mf_eng_spd_neut_bkpt_uacn1,
                                               u8LocalRegime_moteur_32,
                                               16);
   u16LocalMinCmiIdle = MATHSRV_u16Interp1d(Mf_cmi_min_idle_map_uacn1,
                                            u16LocalPara);
   s32LocalTorqLimitInd = (sint32)(u16LocalMinCmiIdle - 32000);
   s32LocalHystThreshold1 = s32LocalTorqLimitInd
                           - Mf_cmi_min_idle_hyst_uacn0;
   s32LocalHystThreshold2 = s32LocalTorqLimitInd
                           + Mf_cmi_min_idle_hyst_uacn0;
   if (MISFDET_bOutMinIdleHyst == 0)
   {
      if (s16LocalEngLim_tqIdcEngCur >= s32LocalHystThreshold2)
      {
         MISFDET_bOutMinIdleHyst = 1;
      }
      else
      {
         MISFDET_bOutMinIdleHyst = 0;
      }
   }
   else
   {
      if (s16LocalEngLim_tqIdcEngCur <= s32LocalHystThreshold1)
      {
         MISFDET_bOutMinIdleHyst = 0;
      }
      else
      {
         MISFDET_bOutMinIdleHyst = 1;
      }
   }
   if (  (u8LocalVitesse_vehicule == 0)
      || (  (bLocalIdlSys_bAcvAntiStall == 0)
         && (  (u8LocalGear_engaged == 0)
            || (Misf_bAcvAlgoEgdIdle_C != 0))))
   {
      bLocalCalc = 1;
   }
   else
   {
      bLocalCalc = 0;
   }

   if (  (Mf_bAcvCondGlobal != 0)
      && (bLocalInhMisfDetCdnClcn == 0)
      && (MISFDET_bOutMinIdleHyst != 0)
      && (u8LocalEngine_running_state == ERUN_ON_IDLE)
      && (bLocalCalc != 0))
   {
      VEMS_vidSET(Mf_bAcvCondIdleRaw, 1);
   }
   else
   {
      VEMS_vidSET(Mf_bAcvCondIdleRaw, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDET_vidAlgoConTempo                                    */
/* !Description :  Ce bloc vérifie si les conditions de stabilité sont        */
/*                 vérifiées pour que la stratégie de détection puisse être   */
/*                 activée.                                                   */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  PTS_R_5158467_006.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Mf_bAcvCondNormRaw;                                         */
/*  input boolean Mf_stability_conditions;                                    */
/*  input boolean Mf_bAcvCondIdleRaw;                                         */
/*  input boolean MISFDET_bAcvCondNormPrev;                                   */
/*  input uint8 Misf_noTDCAcvDet_C;                                           */
/*  input uint8 MISFDET_u8CounternoTDCAcv;                                    */
/*  input boolean MISFDET_bAcvCondIdlePrev;                                   */
/*  input uint8 Misf_noTDCIdleAcvDet_C;                                       */
/*  input uint8 MISFDET_u8CounternoTDCIdleAcv;                                */
/*  input boolean MISFDET_bTimeOut;                                           */
/*  input boolean MISFDET_bTimeOut1;                                          */
/*  output boolean Mf_bAcvCondNorm;                                           */
/*  output boolean Mf_bAcvCondIdle;                                           */
/*  output boolean Mf_algo_cond_ok_temp;                                      */
/*  output uint8 MISFDET_u8CounternoTDCAcv;                                   */
/*  output boolean MISFDET_bTimeOut;                                          */
/*  output uint8 MISFDET_u8CounternoTDCIdleAcv;                               */
/*  output boolean MISFDET_bTimeOut1;                                         */
/*  output boolean MISFDET_bAcvCondNormPrev;                                  */
/*  output boolean MISFDET_bAcvCondIdlePrev;                                  */
/*  output boolean Mf_algo_Norm_cond_ok;                                      */
/*  output boolean Mf_algo_idle_cond_ok;                                      */
/*  output boolean Mf_algo_cond_ok_uavb0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDET_vidAlgoConTempo(void)
{
   boolean bLocalMf_bAcvCondNormRaw;
   boolean bLocalMf_stability_conditions;
   boolean bLocalMf_bAcvCondIdleRaw;
   boolean bLocalMf_bAcvCondNorm;
   boolean bLocalMf_bAcvCondIdle;
   boolean bLocalMf_algo_Norm_cond_ok;
   boolean bLocalMf_algo_idle_cond_ok;
   boolean bLocalMf_algo_cond_ok_uavb0;


   VEMS_vidGET(Mf_bAcvCondNormRaw, bLocalMf_bAcvCondNormRaw);
   VEMS_vidGET(Mf_stability_conditions, bLocalMf_stability_conditions);
   VEMS_vidGET(Mf_bAcvCondIdleRaw, bLocalMf_bAcvCondIdleRaw);
   if (  (bLocalMf_bAcvCondNormRaw != 0)
      && (bLocalMf_stability_conditions != 0))
   {
      bLocalMf_bAcvCondNorm = 1;
   }
   else
   {
      bLocalMf_bAcvCondNorm = 0;
   }
   if (  (bLocalMf_bAcvCondIdleRaw != 0)
      && (bLocalMf_stability_conditions != 0))
   {
      bLocalMf_bAcvCondIdle = 1;
   }
   else
   {
      bLocalMf_bAcvCondIdle = 0;
   }
   VEMS_vidSET(Mf_bAcvCondNorm, bLocalMf_bAcvCondNorm);
   VEMS_vidSET(Mf_bAcvCondIdle, bLocalMf_bAcvCondIdle);
   if (  (bLocalMf_bAcvCondNorm != 0)
      || (bLocalMf_bAcvCondIdle != 0))
   {
      Mf_algo_cond_ok_temp = 1;
   }
   else
   {
      Mf_algo_cond_ok_temp = 0;
   }
   /* Begin Bloc TIMER */
   if (  (MISFDET_bAcvCondNormPrev == 0 )
      && (bLocalMf_bAcvCondNorm != 0))
   {
      MISFDET_u8CounternoTDCAcv = Misf_noTDCAcvDet_C;
      if (MISFDET_u8CounternoTDCAcv == 0 )
      {
         MISFDET_bTimeOut = 1;
      }
      else
      {
         MISFDET_bTimeOut = 0;
      }
   }
   else
   {
      if (MISFDET_u8CounternoTDCAcv > 0)
      {
         MISFDET_u8CounternoTDCAcv = (uint8)(MISFDET_u8CounternoTDCAcv - 1);
         if (MISFDET_u8CounternoTDCAcv == 0)
         {
            MISFDET_bTimeOut = 1;
         }
         else
         {
            MISFDET_bTimeOut = 0;
         }
      }
   }
   /* End Bloc TIMER */
   /* Begin Bloc TIMER1 */
   if (  (MISFDET_bAcvCondIdlePrev == 0 )
      && (bLocalMf_bAcvCondIdle != 0))
   {
      MISFDET_u8CounternoTDCIdleAcv = Misf_noTDCIdleAcvDet_C;
      if (MISFDET_u8CounternoTDCIdleAcv == 0 )
      {
         MISFDET_bTimeOut1 = 1;
      }
      else
      {
         MISFDET_bTimeOut1 = 0;
      }
   }
   else
   {
      if (MISFDET_u8CounternoTDCIdleAcv > 0)
      {
         MISFDET_u8CounternoTDCIdleAcv =
            (uint8)(MISFDET_u8CounternoTDCIdleAcv - 1);
         if (MISFDET_u8CounternoTDCIdleAcv == 0)
         {
            MISFDET_bTimeOut1 = 1;
         }
         else
         {
            MISFDET_bTimeOut1 = 0;
         }
      }
   }
   /* End Bloc TIMER1 */
   MISFDET_bAcvCondNormPrev = bLocalMf_bAcvCondNorm;
   MISFDET_bAcvCondIdlePrev = bLocalMf_bAcvCondIdle;
   if (  (bLocalMf_bAcvCondNorm != 0)
      && (MISFDET_bTimeOut != 0))
   {
      bLocalMf_algo_Norm_cond_ok = 1;
   }
   else
   {
      bLocalMf_algo_Norm_cond_ok = 0;
   }
   if (  (bLocalMf_bAcvCondIdle != 0)
      && (MISFDET_bTimeOut1 != 0))
   {
      bLocalMf_algo_idle_cond_ok = 1;
   }
   else
   {
      bLocalMf_algo_idle_cond_ok = 0;
   }

   if (  (bLocalMf_algo_Norm_cond_ok != 0)
      || (bLocalMf_algo_idle_cond_ok != 0))
   {
      bLocalMf_algo_cond_ok_uavb0 = 1;
   }
   else
   {
      bLocalMf_algo_cond_ok_uavb0 = 0;
   }
   VEMS_vidSET(Mf_algo_Norm_cond_ok, bLocalMf_algo_Norm_cond_ok);
   VEMS_vidSET(Mf_algo_idle_cond_ok, bLocalMf_algo_idle_cond_ok);
   VEMS_vidSET(Mf_algo_cond_ok_uavb0, bLocalMf_algo_cond_ok_uavb0);
}
/*------------------------------- end of file --------------------------------*/