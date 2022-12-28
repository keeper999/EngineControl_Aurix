/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSPPOSN                                               */
/* !Description     : THRSPPOSN component.                                    */
/*                                                                            */
/* !Module          : THRSPPOSN                                               */
/* !Description     : CALCUL DE LA CONSIGNE DE POSITION PAPILLON MOTORISE     */
/*                                                                            */
/* !File            : THRSPPOSN_FCT1.C                                        */
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
/*   1 / THRSPPOSN_vidInitOutput                                              */
/*   2 / THRSPPOSN_vidComputeDtcThrPos                                        */
/*   3 / THRSPPOSN_vidComputeDtcThrPosRef                                     */
/*   4 / THRSPPOSN_vidDeadBandLH                                              */
/*   5 / THRSPPOSN_vidInitThrottleRef                                         */
/*   6 / THRSPPOSN_vidSwitchMgtMcut                                           */
/*   7 / THRSPPOSN_vidDiffEstimation                                          */
/*   8 / THRSPPOSN_vidSwitchingTransients                                     */
/*   9 / THRSPPOSN_vidStopEngineCase                                          */
/*   10 / THRSPPOSN_vidCounter                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6095099 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSPPOSN/THRSPPOSN_FCT1.C_v$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   05 May 2014 $*/
/* $Author::   etsasson                               $$Date::   05 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "THRSPPOSN.h"
#include "THRSPPOSN_L.h"
#include "THRSPPOSN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Dtc_throttle_position_max_limit;                             */
/*  output uint8 Dtc_throttle_position_min_limit;                             */
/*  output boolean Dtc_throttle_test_bed_mode_act;                            */
/*  output uint16 Thr_rOpThrReqMaxThd;                                        */
/*  output boolean Throt_pos_ref_freeze_enab_prev;                            */
/*  output uint16 Dtc_diff_pos_ref_overlap;                                   */
/*  output uint16 THRSPPOSN_u16CntTimer;                                      */
/*  output boolean THRSPPOSN_InitTimerPrev;                                   */
/*  output boolean THRSPPOSN_bTimeOut;                                        */
/*  output boolean THRSPPOSN_BypCtAuthCloThr_Prev;                            */
/*  output boolean THRSPPOSN_bTriggerPrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidInitOutput(void)
{
   /* initialisation des sorties */
   VEMS_vidSET(Dtc_throttle_position_max_limit, 0);
   VEMS_vidSET(Dtc_throttle_position_min_limit, 0);
   VEMS_vidSET(Dtc_throttle_test_bed_mode_act, 0);
   VEMS_vidSET(Thr_rOpThrReqMaxThd, 0);

   /*Internal variables initialization*/
   Throt_pos_ref_freeze_enab_prev = 0;
   Dtc_diff_pos_ref_overlap = 0;
   THRSPPOSN_u16CntTimer = 0;
   THRSPPOSN_InitTimerPrev = 0;
   THRSPPOSN_bTimeOut = 0;
   THRSPPOSN_BypCtAuthCloThr_Prev = 0;
   THRSPPOSN_bTriggerPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidComputeDtcThrPos                              */
/* !Description :  Si un défaut de niveau 3 est issu de la sécurité de        */
/*                 fonctionnement, l’objectif de section efficace papillon est*/
/*                 limité, ainsi que sa vitesse d’ouverture, afin de limiter  */
/*                 les performances moteurs.                                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_08_04485_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input boolean Thr_bBypSpEngStopSTT_C;                                     */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input boolean Thr_bAcvTypSpEngStop_Sel1_C;                                */
/*  input uint16 Ssm_limp_home_throttle_pos;                                  */
/*  input uint16 ThrSys_rOpThrReq;                                            */
/*  output uint16 Dtc_throttle_position_raw_ref;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidComputeDtcThrPos(void)
{
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalDv_pos_pedale_relative;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalThrSys_rOpThrReq;
   uint16  u16LocalMax;
   uint16  u16LocalPosPedRelative;
   uint16  u16LocalSsm_limp_hom_thr_pos;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   if (  (u8LocalVehicle_active_state == VS_STALL)
      && ( (bLocalCoPTSt_bRStrtSTT == 0)
         ||(Thr_bBypSpEngStopSTT_C !=0)))
   {
      VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_pos_pedale_relative);
      u16LocalPosPedRelative = (uint16)(u8LocalDv_pos_pedale_relative * 4);
      if (Thr_bAcvTypSpEngStop_Sel1_C != 0)
      {
         Dtc_throttle_position_raw_ref = u16LocalPosPedRelative;
      }
      else
      {
         VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsm_limp_hom_thr_pos);
         u16LocalMax =(uint16)(MATHSRV_udtMAX(u16LocalPosPedRelative,
                                              u16LocalSsm_limp_hom_thr_pos));
         Dtc_throttle_position_raw_ref =
            (uint16)MATHSRV_udtMIN(u16LocalMax, 1024);
      }
   }
   else
   {
      VEMS_vidGET(ThrSys_rOpThrReq, u16LocalThrSys_rOpThrReq);
      Dtc_throttle_position_raw_ref =
         (uint16)MATHSRV_udtMIN(u16LocalThrSys_rOpThrReq, 1024);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidComputeDtcThrPosRef                           */
/* !Description :  En mode banc manuel, l’ouverture du papillon est donnée par*/
/*                 une calibration spécifique, sinon on limite la pente des   */
/*                 modifications en fonction des caractéristiques mécanique du*/
/*                 boîtier papillon.                                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRSPPOSN_vidDeadBandLH();                               */
/*  input boolean Manu_inh_pm;                                                */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input boolean Thr_bTstInProgs;                                            */
/*  input boolean Thr_bAcvSpBenchMod;                                         */
/*  input uint16 Thr_rSpPosActrTst;                                           */
/*  input boolean Dtc_throttle_test_bed_mode;                                 */
/*  input uint16 Dtc_throttle_pos_for_test_bed;                               */
/*  input uint16 Thr_posnSpBenchMod;                                          */
/*  input boolean Thr_bEngStopAuthCloThr;                                     */
/*  input boolean Thr_bAcvThrPosEngStop_C;                                    */
/*  input uint16 Thr_rThrPosEngStop_C;                                        */
/*  input boolean Dtc_throttle_test_bed_mode_manu;                            */
/*  input uint16 Dtc_throt_pos_for_test_bed_manu;                             */
/*  input uint16 Dtc_throttle_position_raw_ref;                               */
/*  input boolean Thr_bEngStopAuthCloSlopeThr;                                */
/*  input uint8 Thr_vThrPosSpRateEngStop_C;                                   */
/*  input uint8 Dtc_throttle_position_rate_limit;                             */
/*  input uint16 Dtc_throttle_position_ref_temp;                              */
/*  input boolean Thr_FSpcReqClCtl_bAcv;                                      */
/*  input uint16 Thr_FSpcReqClCtl_posnSp;                                     */
/*  input boolean Dv_detection_pied_a_fond;                                   */
/*  input uint8 Dtc_throttle_position_max;                                    */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint8 Dtc_throttle_position_max_map[9];                             */
/*  input uint8 Dtc_throttle_position_max_offset;                             */
/*  input uint8 Thr_rThrMinPosEngStop_C;                                      */
/*  input uint8 Dtc_throttle_position_min;                                    */
/*  input uint16 Dtc_throt_position_ref_tmp;                                  */
/*  output boolean Dtc_throttle_test_bed_mode_act;                            */
/*  output uint16 Dtc_throttle_position_ref_temp;                             */
/*  output uint16 Dtc_throttle_position_ref_w_mcut;                           */
/*  output uint16 Thr_rOpThrReqMaxThd;                                        */
/*  output uint8 Dtc_throttle_position_max_limit;                             */
/*  output uint8 Dtc_throttle_position_min_limit;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidComputeDtcThrPosRef(void)
{
   boolean bLocalThr_bTstInProgs;
   boolean bLocalDv_detect_pied_a_fond;
   boolean bLocalThr_FSpcReqClCtl_bAcv;
   boolean bLocalTestBed;
   boolean bLocalThr_bAcvSpBenchMod;
   uint8   u8LocalInterp;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalDv_pos_pedale_relative;
   uint8   u8LocalThrPosMax;
   uint8   u8LocalSwitch;
   uint16  u16LocalDtc_thrott_pos_ref_temp;
   uint16  u16LocalCLAMP1;
   uint16  u16LocalCLAMP2;
   uint16  u16LocalThr_rSpPosActrTst;
   uint16  u16LocalDtc_thr_pos_test_bed;
   uint16  u16LocalSlewFilterThresh_Dec;
   uint16  u16LocalSlewFilterThresh_Inc;
   uint16  u16LocalMIN1;
   uint16  u16LocalRefThrotPos;
   uint16  u16LocalThr_FSpcReqClCtl_posnSp;
   uint16  u16LocalThr_posnSpBenchMod;
   uint16  u16LocalCalcPara;
   uint16  u16LocalThrReqMax;
   uint32  u32LocalThrReqMax;


   if (Manu_inh_pm != 0)
   {
      VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_pos_pedale_relative);
      u16LocalRefThrotPos = (uint16)(u8LocalDv_pos_pedale_relative * 4);
      bLocalTestBed = 0;
   }
   else
   {
      VEMS_vidGET(Thr_bTstInProgs, bLocalThr_bTstInProgs);
      VEMS_vidGET(Thr_bAcvSpBenchMod, bLocalThr_bAcvSpBenchMod);

      if (bLocalThr_bTstInProgs != 0)
      {
         VEMS_vidGET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
         u16LocalRefThrotPos = u16LocalThr_rSpPosActrTst;
      }
      else
      {
         if (Dtc_throttle_test_bed_mode != 0)
         {
            VEMS_vidGET(Dtc_throttle_pos_for_test_bed,
                        u16LocalDtc_thr_pos_test_bed);
            u16LocalRefThrotPos = u16LocalDtc_thr_pos_test_bed;
         }
         else
         {
            if (bLocalThr_bAcvSpBenchMod !=0)
            {
               VEMS_vidGET(Thr_posnSpBenchMod, u16LocalThr_posnSpBenchMod);
               u16LocalRefThrotPos = u16LocalThr_posnSpBenchMod;
            }
            else
            {
               if (  (Thr_bEngStopAuthCloThr!= 0)
                  && (Thr_bAcvThrPosEngStop_C != 0))
               {
                  u16LocalRefThrotPos = Thr_rThrPosEngStop_C;
               }
               else
               {
                  if (Dtc_throttle_test_bed_mode_manu != 0)
                  {
                     u16LocalRefThrotPos = Dtc_throt_pos_for_test_bed_manu;
                  }
                  else
                  {
                     u16LocalRefThrotPos = Dtc_throttle_position_raw_ref;
                  }
               }
            }
         }
      }

      if (  (Dtc_throttle_test_bed_mode != 0)
         || (Dtc_throttle_test_bed_mode_manu != 0)
         || (bLocalThr_bAcvSpBenchMod != 0))
      {
         bLocalTestBed = 1;
      }
      else
      {
         bLocalTestBed = 0;
      }
   }
   VEMS_vidSET(Dtc_throttle_test_bed_mode_act, bLocalTestBed);

   if (Thr_bEngStopAuthCloSlopeThr != 0)
   {
      u16LocalSlewFilterThresh_Dec = (uint16)(Thr_vThrPosSpRateEngStop_C * 4);
   }
   else
   {
      u16LocalSlewFilterThresh_Dec =
         (uint16)(Dtc_throttle_position_rate_limit * 4);
   }
   u16LocalSlewFilterThresh_Inc =
      (uint16)(Dtc_throttle_position_rate_limit * 4);
   u16LocalDtc_thrott_pos_ref_temp =
      MATHSRV_u16SlewFilter(Dtc_throttle_position_ref_temp,
                            u16LocalRefThrotPos,
                            u16LocalSlewFilterThresh_Inc,
                            u16LocalSlewFilterThresh_Dec);
   Dtc_throttle_position_ref_temp =
      (uint16)MATHSRV_udtMIN(u16LocalDtc_thrott_pos_ref_temp, 1024);

   THRSPPOSN_vidDeadBandLH();

   VEMS_vidGET(Thr_FSpcReqClCtl_bAcv, bLocalThr_FSpcReqClCtl_bAcv);
   if (bLocalThr_FSpcReqClCtl_bAcv != 0)
   {
      /* Apprentissage activé --> Consigne de position corrigée du papillon */
      /* forcée à la valeur imposée pour l'apprentissage butées             */
      VEMS_vidGET(Thr_FSpcReqClCtl_posnSp ,u16LocalThr_FSpcReqClCtl_posnSp );
      Dtc_throttle_position_ref_w_mcut =
         (uint16)MATHSRV_udtMIN(u16LocalThr_FSpcReqClCtl_posnSp, 1024);
      VEMS_vidSET(Thr_rOpThrReqMaxThd, 1024);
      VEMS_vidSET(Dtc_throttle_position_max_limit, 255);
      VEMS_vidSET(Dtc_throttle_position_min_limit, 0);
   }
   else
   {
      VEMS_vidGET(Dv_detection_pied_a_fond, bLocalDv_detect_pied_a_fond);
      if (bLocalDv_detect_pied_a_fond != 0)
      {
         u8LocalThrPosMax = Dtc_throttle_position_max;
         u16LocalMIN1 = Dtc_throttle_position_max;
         u16LocalThrReqMax = (uint16)(Dtc_throttle_position_max * 4);
      }
      else
      {
         VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
         u16LocalCalcPara =
            MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                        u8LocalRegime_moteur_32,
                                        9);
         u8LocalInterp = MATHSRV_u8Interp1d(Dtc_throttle_position_max_map,
                                            u16LocalCalcPara);
         u16LocalMIN1 = (uint16)( Dtc_throttle_position_max_offset
                                + u8LocalInterp);
         u32LocalThrReqMax = (uint32)(u16LocalMIN1 * 4);
         u16LocalThrReqMax = (uint16)MATHSRV_udtMIN(u32LocalThrReqMax, 1024);
         u8LocalThrPosMax = (uint8)MATHSRV_udtMIN(u16LocalMIN1, UINT8_MAX);
      }
      /* Pas d'apprentissage --> Consigne de position corrigée du papillon */
      /* calculée pour une position optimale                               */
      if (Thr_bEngStopAuthCloThr != 0)
      {
         u8LocalSwitch = Thr_rThrMinPosEngStop_C;
      }
      else
      {
         u8LocalSwitch = Dtc_throttle_position_min;
      }
      u16LocalCLAMP1 = (uint16)(u8LocalSwitch * 4);
      u16LocalCLAMP2 = (uint16)(u16LocalMIN1 * 4);
      u16LocalCLAMP2 = (uint16)MATHSRV_udtMIN(u16LocalCLAMP2, 1024);
      Dtc_throttle_position_ref_w_mcut =
         (uint16)MATHSRV_udtCLAMP(Dtc_throt_position_ref_tmp,
                                  u16LocalCLAMP1,
                                  u16LocalCLAMP2);
      VEMS_vidSET(Thr_rOpThrReqMaxThd, u16LocalThrReqMax);
      VEMS_vidSET(Dtc_throttle_position_max_limit, u8LocalThrPosMax);
      VEMS_vidSET(Dtc_throttle_position_min_limit, u8LocalSwitch);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidDeadBandLH                                    */
/* !Description :  En cours de fonctionnement, le Limp-home se déplace (en    */
/*                 fonction de la température, Afin de s’affranchir de ses    */
/*                 variations, ce module définit une zone interdite pour la   */
/*                 consigne de position papillon centrée autour de la valeur  */
/*                 apprise du Limp-home.                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_limp_home_throttle_pos;                                  */
/*  input uint8 Tpac_limp_home_variation;                                     */
/*  input uint16 Dtc_throttle_position_ref_raw;                               */
/*  input uint16 Dtc_throttle_position_ref_temp;                              */
/*  output uint16 Dtc_throt_position_ref_tmp;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidDeadBandLH(void)
{
   uint16 u16LocalDtc_thr_pos_ref_raw;
   uint16 u16LocalSsm_limp_home_thr_pos;
   uint16 u16LocalSsmMinusVar;
   uint16 u16LocalSsmPlusVar;
   uint16 u16LocalDtc_throt_pos_ref_tmp;
   uint32 u32LocalMIN;
   sint32 s32LocalMAX;


   VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsm_limp_home_thr_pos);
   u32LocalMIN = u16LocalSsm_limp_home_thr_pos + Tpac_limp_home_variation;
   u16LocalSsmPlusVar =
      (uint16)MATHSRV_udtMIN(u32LocalMIN, 65535);
   s32LocalMAX = u16LocalSsm_limp_home_thr_pos - Tpac_limp_home_variation;
   u16LocalSsmMinusVar =
      (uint16)MATHSRV_udtMAX(s32LocalMAX ,0);

   VEMS_vidGET(Dtc_throttle_position_ref_raw, u16LocalDtc_thr_pos_ref_raw);
   if (u16LocalDtc_thr_pos_ref_raw <= u16LocalSsmMinusVar)
   {
      if (  (Dtc_throttle_position_ref_temp >= u16LocalSsmMinusVar)
         && (Dtc_throttle_position_ref_temp <= u16LocalSsm_limp_home_thr_pos))
      {
         u16LocalDtc_throt_pos_ref_tmp = u16LocalSsmMinusVar;
      }
      else
      {
         if (  (Dtc_throttle_position_ref_temp > u16LocalSsm_limp_home_thr_pos)
            && (Dtc_throttle_position_ref_temp <= u16LocalSsmPlusVar))
         {
            u16LocalDtc_throt_pos_ref_tmp = u16LocalSsmPlusVar;
         }
         else
         {
            u16LocalDtc_throt_pos_ref_tmp = Dtc_throttle_position_ref_temp;
         }
      }
   }
   else
   {
      if (u16LocalDtc_thr_pos_ref_raw >= u16LocalSsmPlusVar)
      {
         if (  (Dtc_throttle_position_ref_temp >= u16LocalSsm_limp_home_thr_pos)
            && (Dtc_throttle_position_ref_temp <= u16LocalSsmPlusVar))
         {
            u16LocalDtc_throt_pos_ref_tmp = u16LocalSsmPlusVar;
         }
         else
         {
            if (  ( Dtc_throttle_position_ref_temp
                  < u16LocalSsm_limp_home_thr_pos)
               && (Dtc_throttle_position_ref_temp >= u16LocalSsmMinusVar))
            {
               u16LocalDtc_throt_pos_ref_tmp = u16LocalSsmMinusVar;
            }
            else
            {
               u16LocalDtc_throt_pos_ref_tmp = Dtc_throttle_position_ref_temp;
            }
         }
      }
      else
      {
         u16LocalDtc_throt_pos_ref_tmp = Dtc_throttle_position_ref_temp;
      }
   }
   Dtc_throt_position_ref_tmp =
      (uint16)MATHSRV_udtMIN(u16LocalDtc_throt_pos_ref_tmp, 1024);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidInitThrottleRef                               */
/* !Description :  Lors d’un reset du calculateur ou d’un passage de la       */
/*                 commande en boucle ouverte à la commande en boucle fermée  */
/*                 (front descendant de Tpac_open_loop_control), la consigne  */
/*                 relative de position papillon est initialisée à la position*/
/*                 mesurée.                                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  output uint16 Dtc_throttle_position_ref_w_mcut;                           */
/*  output uint16 Dtc_throttle_position_ref_temp;                             */
/*  output uint16 Dtc_throttle_position_ref_raw;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidInitThrottleRef(void)
{
   uint16 u16LocalTpac_cor_thr_pos;


   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpac_cor_thr_pos);
   u16LocalTpac_cor_thr_pos = (uint16)MATHSRV_udtMIN(u16LocalTpac_cor_thr_pos,
                                                     1024);
   Dtc_throttle_position_ref_w_mcut = u16LocalTpac_cor_thr_pos;
   Dtc_throttle_position_ref_temp   = u16LocalTpac_cor_thr_pos;
   VEMS_vidSET(Dtc_throttle_position_ref_raw, u16LocalTpac_cor_thr_pos);


}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidSwitchMgtMcut                                 */
/* !Description :  En cas de détection de micro-coupure, la consigne relative */
/*                 de position papillon prend la valeur de la position «      */
/*                 mesurée », si Throttle_pos_ref_freeze_manu_inh = 0, avec   */
/*                 une pente de variation limitée (filtrage de type «         */
/*                 slew-rate ».                                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_08_04485_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRSPPOSN_vidDiffEstimation();                           */
/*  extf argret void THRSPPOSN_vidSwitchingTransients();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Throttle_pos_ref_freeze_enab;                               */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint16 Dtc_throttle_position_ref_w_mcut;                            */
/*  input boolean Throt_pos_ref_freeze_enab_prev;                             */
/*  input uint16 Dtc_throttle_position_ref_raw;                               */
/*  input uint16 Dtc_diff_pos_ref_overlap;                                    */
/*  input uint16 Dtc_switch_mcut_max_rate;                                    */
/*  output uint16 Dtc_throttle_position_ref_raw;                              */
/*  output boolean Throt_pos_ref_freeze_enab_prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidSwitchMgtMcut(void)
{
   uint16  u16LocalDtc_thr_pos_ref_raw;
   uint16  u16LocalSlewInput;
   uint16  u16LocalTpac_cor_thr_pos;
   boolean bLocalThr_pos_ref_frz_enab;


   VEMS_vidGET(Throttle_pos_ref_freeze_enab, bLocalThr_pos_ref_frz_enab);
   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpac_cor_thr_pos);
   if (bLocalThr_pos_ref_frz_enab != 0)
   {
      u16LocalSlewInput = u16LocalTpac_cor_thr_pos;
   }
   else
   {
      u16LocalSlewInput = Dtc_throttle_position_ref_w_mcut;
   }

   if (bLocalThr_pos_ref_frz_enab != Throt_pos_ref_freeze_enab_prev)
   {
      THRSPPOSN_vidDiffEstimation();
   }
   else
   {
      THRSPPOSN_vidSwitchingTransients();
   }

   VEMS_vidGET(Dtc_throttle_position_ref_raw, u16LocalDtc_thr_pos_ref_raw);
   if (Dtc_diff_pos_ref_overlap == 0)
   {
      u16LocalDtc_thr_pos_ref_raw =
         MATHSRV_u16SlewFilter(u16LocalDtc_thr_pos_ref_raw,
                               u16LocalSlewInput,
                               1024,
                               1024);
   }
   else
   {
      u16LocalDtc_thr_pos_ref_raw =
         MATHSRV_u16SlewFilter(u16LocalDtc_thr_pos_ref_raw,
                               u16LocalSlewInput,
                               Dtc_switch_mcut_max_rate,
                               Dtc_switch_mcut_max_rate);
   }
   u16LocalDtc_thr_pos_ref_raw =
      (uint16)MATHSRV_udtMIN(u16LocalDtc_thr_pos_ref_raw, 1024);
   VEMS_vidSET(Dtc_throttle_position_ref_raw, u16LocalDtc_thr_pos_ref_raw);
   Throt_pos_ref_freeze_enab_prev = bLocalThr_pos_ref_frz_enab;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidDiffEstimation                                */
/* !Description :  Ce bloc permet de calculer la valeur absolue de l’écart    */
/*                 entre l’ancienne valeur et la nouvelle, à chaque           */
/*                 transition.                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint16 Dtc_throttle_position_ref_w_mcut;                            */
/*  output uint16 Dtc_diff_pos_ref_overlap;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidDiffEstimation(void)
{
   uint16 u16LocalTpac_cor_thr_pos;
   uint16 u16LocalDtc_diff_pos_ref_overlap;
   sint32 s32LocalDtc_diff_pos_ref_overlap;


   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpac_cor_thr_pos);
   s32LocalDtc_diff_pos_ref_overlap = Dtc_throttle_position_ref_w_mcut
                                    - u16LocalTpac_cor_thr_pos;
   u16LocalDtc_diff_pos_ref_overlap =
      (uint16)MATHSRV_udtABS(s32LocalDtc_diff_pos_ref_overlap);
   Dtc_diff_pos_ref_overlap =
      (uint16)MATHSRV_udtMIN(u16LocalDtc_diff_pos_ref_overlap, 1024);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidSwitchingTransients                           */
/* !Description :  Ce bloc permet de limiter la « fenêtre » d’application du «*/
/*                 slew_rate » sur la valeur utilisée                         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dtc_diff_pos_ref_overlap;                                    */
/*  input uint16 Dtc_diff_switch_mcut_dec;                                    */
/*  output uint16 Dtc_diff_pos_ref_overlap;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidSwitchingTransients(void)
{
   uint16 u16LocalDtc_diff_pos_ref_overlap;


   if (Dtc_diff_pos_ref_overlap > Dtc_diff_switch_mcut_dec)
   {
      u16LocalDtc_diff_pos_ref_overlap = (uint16)( Dtc_diff_pos_ref_overlap
                                                 - Dtc_diff_switch_mcut_dec);
      Dtc_diff_pos_ref_overlap =
         (uint16)MATHSRV_udtMIN(u16LocalDtc_diff_pos_ref_overlap, 1024);
   }
   else
   {
      Dtc_diff_pos_ref_overlap = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidStopEngineCase                                */
/* !Description :  la fonction présente  les conditions pour passer en        */
/*                 fermeture complète du papillon                             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  PTS_R_6095099_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRSPPOSN_vidCounter();                                  */
/*  input boolean Afts_bRstCtAuthCloThr;                                      */
/*  input boolean Srv_bBypCtAuthCloThr;                                       */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input uint8 Temperature_air;                                              */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_uBattMes;                                                */
/*  input boolean CoEs_bAcvThrSysSTTEs;                                       */
/*  input boolean THRSPPOSN_BypCtAuthCloThr_Prev;                             */
/*  input uint16 Srv_ctAuthCloThr;                                            */
/*  input uint16 Thr_ctAuthCloThr;                                            */
/*  input sint16 Thr_tEauHiThdEngStop_C;                                      */
/*  input sint16 Thr_tEauLoThdEngStop_C;                                      */
/*  input uint16 Dtc_throttle_position_ref_temp;                              */
/*  input uint16 Thr_rSpPosCloThdSlopeEngStop_C;                              */
/*  input uint8 Thr_tAirHiThdEngStop_C;                                       */
/*  input uint8 Thr_tAirLoThdEngStop_C;                                       */
/*  input uint16 Thr_uBattHiThdEngStop_C;                                     */
/*  input uint16 Thr_uBattLoThdEngStop_C;                                     */
/*  input uint8 Thr_nEngLoThdEngStop_C;                                       */
/*  input boolean Thr_bAcvCloThrSTTStop_C;                                    */
/*  input uint16 Thr_ctAuthCloThr_C;                                          */
/*  input boolean Thr_bEngStopAuthCloSlopeThr;                                */
/*  input uint16 Thr_rSpPosCloThdEngStop_C;                                   */
/*  input boolean THRSPPOSN_InitTimerPrev;                                    */
/*  input uint16 Thr_tiCloThrDlyEngStop_C;                                    */
/*  input uint16 THRSPPOSN_u16CntTimer;                                       */
/*  input boolean THRSPPOSN_bTimeOut;                                         */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Thr_bEngStopAuthCloThr;                                     */
/*  input boolean THRSPPOSN_bTriggerPrev;                                     */
/*  output uint16 Thr_ctAuthCloThr;                                           */
/*  output boolean Thr_bEngStopAuthCloSlopeThr;                               */
/*  output uint16 THRSPPOSN_u16CntTimer;                                      */
/*  output boolean THRSPPOSN_bTimeOut;                                        */
/*  output boolean Thr_bEngStopAuthCloThr;                                    */
/*  output boolean THRSPPOSN_BypCtAuthCloThr_Prev;                            */
/*  output boolean THRSPPOSN_InitTimerPrev;                                   */
/*  output boolean THRSPPOSN_bTriggerPrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidStopEngineCase(void)
{
   boolean bLocalAfts_bRstCtAuthCloThr;
   boolean bLocalSrv_bBypCtAuthCloThr;
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalINHCLOTHRSTTSTOP;
   boolean bLocalInitTimer;
   boolean bLocalTrigger;
   boolean bLocalCoEs_bAcvThrSysSTTEs;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalTemperature_air;
   uint8   u8Localthrotcontrolstate;
   uint16  u16LocalSrv_ctAuthCloThr;
   uint16  u16LocalThr_ctAuthCloThr;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalThr_EauHiThdEngStop;
   sint16  s16LocalThr_EauLoThdEngStop;
   sint16  s16LocalExt_uBattMes;


   VEMS_vidGET(Afts_bRstCtAuthCloThr, bLocalAfts_bRstCtAuthCloThr);
   VEMS_vidGET(Srv_bBypCtAuthCloThr, bLocalSrv_bBypCtAuthCloThr);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);
   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(CoEs_bAcvThrSysSTTEs, bLocalCoEs_bAcvThrSysSTTEs);
   bLocalINHCLOTHRSTTSTOP = GDGAR_bGetFRM(FRM_FRM_INHCLOTHRSTTSTOP);

   if (bLocalAfts_bRstCtAuthCloThr != 0)
   {
      VEMS_vidSET(Thr_ctAuthCloThr, 0);
   }
   else
   {
      if (  (bLocalSrv_bBypCtAuthCloThr != 0)
         && (THRSPPOSN_BypCtAuthCloThr_Prev == 0))
      {
         VEMS_vidGET(Srv_ctAuthCloThr, u16LocalSrv_ctAuthCloThr);
         VEMS_vidSET(Thr_ctAuthCloThr, u16LocalSrv_ctAuthCloThr);
      }
   }

   VEMS_vidGET(Thr_ctAuthCloThr, u16LocalThr_ctAuthCloThr);
   s16LocalThr_EauHiThdEngStop =
      (sint16)(((Thr_tEauHiThdEngStop_C * 5) + 4) / 8);
   s16LocalThr_EauLoThdEngStop =
      (sint16)(((Thr_tEauLoThdEngStop_C * 5) + 4) / 8);

   if (  (Dtc_throttle_position_ref_temp <=  Thr_rSpPosCloThdSlopeEngStop_C)
      && (bLocalCoEs_bAcvThrSysSTTEs != 0)
      && (  (u8LocalTemperature_air < Thr_tAirHiThdEngStop_C)
         && (u8LocalTemperature_air > Thr_tAirLoThdEngStop_C))
      && (  (s16LocalExt_tCoMes < s16LocalThr_EauHiThdEngStop)
         && (s16LocalExt_tCoMes > s16LocalThr_EauLoThdEngStop))
      && (  (s16LocalExt_uBattMes < Thr_uBattHiThdEngStop_C)
         && (s16LocalExt_uBattMes > Thr_uBattLoThdEngStop_C))
      && (u8LocalRegime_moteur_32 < Thr_nEngLoThdEngStop_C)
      && (bLocalThr_bRstStopsLrnReq == 0)
      && (bLocalINHCLOTHRSTTSTOP == 0)
      && (Thr_bAcvCloThrSTTStop_C != 0)
      && (u16LocalThr_ctAuthCloThr <= Thr_ctAuthCloThr_C))
   {
      Thr_bEngStopAuthCloSlopeThr = 1;
   }
   else
   {
      Thr_bEngStopAuthCloSlopeThr = 0;
   }
   if (  (Thr_bEngStopAuthCloSlopeThr != 0)
      && (Dtc_throttle_position_ref_temp <= Thr_rSpPosCloThdEngStop_C))
   {
      bLocalInitTimer = 1;
   }
   else
   {
      bLocalInitTimer = 0;
   }
      /*** Begin Bloc TIMER ***/
   if (  (THRSPPOSN_InitTimerPrev == 0)
      && (bLocalInitTimer != 0))
   {
      THRSPPOSN_u16CntTimer = Thr_tiCloThrDlyEngStop_C;
      if (THRSPPOSN_u16CntTimer == 0)
      {
         THRSPPOSN_bTimeOut = 1;
      }
      else
      {
         THRSPPOSN_bTimeOut = 0;
      }
   }
   else
   {
      if (THRSPPOSN_u16CntTimer > 0)
      {
         THRSPPOSN_u16CntTimer = (uint16)(THRSPPOSN_u16CntTimer - 1);
         if (THRSPPOSN_u16CntTimer == 0)
         {
            THRSPPOSN_bTimeOut = 1;
         }
         else
         {
            THRSPPOSN_bTimeOut = 0;
         }
      }
   }
   /*** End Bloc TIMER ***/
   if (  (bLocalInitTimer != 0)
      && (THRSPPOSN_bTimeOut == 0))
   {
      Thr_bEngStopAuthCloThr = 1;
   }
   else
   {
      Thr_bEngStopAuthCloThr = 0;
   }

   VEMS_vidGET(Tpac_throttle_control_state, u8Localthrotcontrolstate);
   if (  (u8Localthrotcontrolstate == TPAC_EXIT_LOW_THRUST)
      || (Thr_bEngStopAuthCloThr != 0))
   {
      bLocalTrigger = 1;
   }
   else
   {
      bLocalTrigger = 0;
   }
   if (  (bLocalTrigger != 0)
      && (THRSPPOSN_bTriggerPrev == 0))
   {
      THRSPPOSN_vidCounter();
   }

   THRSPPOSN_BypCtAuthCloThr_Prev = bLocalSrv_bBypCtAuthCloThr;
   THRSPPOSN_InitTimerPrev = bLocalInitTimer;
   THRSPPOSN_bTriggerPrev = bLocalTrigger;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSPPOSN_vidCounter                                       */
/* !Description :  Fonction qui compte le nombre d'autorisation de fermeture  */
/*                 complète du papillon                                       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Thr_ctAuthCloThr;                                            */
/*  output uint16 Thr_ctAuthCloThr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSPPOSN_vidCounter(void)
{
   uint16 u16LocalThr_ctAuthCloThr;


   VEMS_vidGET(Thr_ctAuthCloThr, u16LocalThr_ctAuthCloThr);
   if (u16LocalThr_ctAuthCloThr < 65534)
   {
      u16LocalThr_ctAuthCloThr = (uint16)(u16LocalThr_ctAuthCloThr + 1);
      VEMS_vidSET(Thr_ctAuthCloThr, u16LocalThr_ctAuthCloThr);
   }
}
/*-------------------------------- end of file -------------------------------*/