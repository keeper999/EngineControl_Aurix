/*****************************************************************************/
/*                                                                           */
/* !Layer          : VEMS_INTERFACE                                          */
/*                                                                           */
/* !Component      : VEMS_INTERFACE                                          */
/*                                                                           */
/* !Module         : VEMS                                                    */
/* !Description    : Create interface for set the connection between T3      */
/*                   and RTE                                                 */
/* !File           : VEMS_rte.h                                              */
/*                                                                           */
/* !Scope          : Public Component                                        */
/*                                                                           */
/* !Target         : All                                                     */
/*                                                                           */
/* !Vendor         : Valeo                                                   */
/*                                                                           */
/* Coding language : C                                                       */
/*                                                                           */
/* COPYRIGHT 2014 VALEO                                                      */
/* all rights reserved                                                       */
/*                                                                           */
/*****************************************************************************/
/*       File generated automaticaly (EbmivieT3ToRte version 01.00)          */
/*****************************************************************************/
/* PVCS Information                                                          */
/* $Archive::                                                               $*/
/* $Revision::            $$Author::                  $$Date::              $*/
/*****************************************************************************/
/* generation date :  2014 , November 3 at 12:41:55                          */
/*****************************************************************************/

#ifndef VEMS_RTE_AUTOCODE_H
#define VEMS_RTE_AUTOCODE_H

/**********************************************************************************
   Inclusion des header autosar 
 **********************************************************************************/

#if (!defined RTE_CORE)
   #define RTE_CORE              /* define symbol so that only the part of
   * the application header files is included
   * which is relevant for the RTE Core */
   #endif

#include "Rte_VEMS_Interface.h"

/**********************************************************************************
   Create interface for variable ACCmd_nAntiStall
  **********************************************************************************/

#define vidSET_VALUE_ACCmd_nAntiStall(value)
#define vidGET_VALUE_ACCmd_nAntiStall(variable)                                  Rte_Read_R_ACCmd_nAntiStall_ACCmd_nAntiStall(&variable)

/**********************************************************************************
   Create interface for variable ACCmd_stReq
  **********************************************************************************/

#define vidSET_VALUE_ACCmd_stReq(value)
#define vidGET_VALUE_ACCmd_stReq(variable)                                       Rte_Read_R_ACCmd_stReq_ACCmd_stReq(&variable)

/**********************************************************************************
   Create interface for variable AC_bACClu
  **********************************************************************************/

#define vidSET_VALUE_AC_bACClu(value)                                            Rte_Write_P_AC_bACClu_AC_bACClu(value)
#define vidGET_VALUE_AC_bACClu(variable)                                         Rte_Read_R_AC_bACClu_AC_bACClu(&variable)

/**********************************************************************************
   Create interface for variable AC_bOpFSFReq
  **********************************************************************************/

#define vidSET_VALUE_AC_bOpFSFReq(value)                                         Rte_Write_P_AC_bOpFSFReq_AC_bOpFSFReq(value)
#define vidGET_VALUE_AC_bOpFSFReq(variable)                                      Rte_Read_R_AC_bOpFSFReq_AC_bOpFSFReq(&variable)

/**********************************************************************************
   Create interface for variable AC_pwrAC
  **********************************************************************************/

#define vidSET_VALUE_AC_pwrAC(value)                                             Rte_Write_P_AC_pwrAC_AC_pwrAC(value)
#define vidGET_VALUE_AC_pwrAC(variable)                                          Rte_Read_R_AC_pwrAC_AC_pwrAC(&variable)

/**********************************************************************************
   Create interface for variable AC_rSpdFanReq
  **********************************************************************************/

#define vidSET_VALUE_AC_rSpdFanReq(value)                                        Rte_Write_P_AC_rSpdFanReq_AC_rSpdFanReq(value)
#define vidGET_VALUE_AC_rSpdFanReq(variable)                                     Rte_Read_R_AC_rSpdFanReq_AC_rSpdFanReq(&variable)

/**********************************************************************************
   Create interface for variable AFAMgt_bAcvAdpRstDiag
  **********************************************************************************/

#define vidSET_VALUE_AFAMgt_bAcvAdpRstDiag(value)
#define vidGET_VALUE_AFAMgt_bAcvAdpRstDiag(variable)                             Rte_Read_R_AFAMgt_bAcvAdpRstDiag_AFAMgt_bAcvAdpRstDiag(&variable)

/**********************************************************************************
   Create interface for variable AFAMgt_bAuthAdpReq
  **********************************************************************************/

#define vidSET_VALUE_AFAMgt_bAuthAdpReq(value)
#define vidGET_VALUE_AFAMgt_bAuthAdpReq(variable)                                Rte_Read_R_AFAMgt_bAuthAdpReq_AFAMgt_bAuthAdpReq(&variable)

/**********************************************************************************
   Create interface for variable AFA_bAuthClsCanPurg
  **********************************************************************************/

#define vidSET_VALUE_AFA_bAuthClsCanPurg(value)
#define vidGET_VALUE_AFA_bAuthClsCanPurg(variable)                               Rte_Read_R_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg(&variable)

/**********************************************************************************
   Create interface for variable AFA_bClsEGRRef
  **********************************************************************************/

#define vidSET_VALUE_AFA_bClsEGRRef(value)
#define vidGET_VALUE_AFA_bClsEGRRef(variable)                                    Rte_Read_R_AFA_bClsEGRRef_AFA_bClsEGRRef(&variable)

/**********************************************************************************
   Create interface for variable AFA_bEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_AFA_bEngStopAuth(value)
#define vidGET_VALUE_AFA_bEngStopAuth(variable)                                  Rte_Read_R_AFA_bEngStopAuth_AFA_bEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable AFA_bFitClsExVlvBol
  **********************************************************************************/

#define vidSET_VALUE_AFA_bFitClsExVlvBol(value)
#define vidGET_VALUE_AFA_bFitClsExVlvBol(variable)                               Rte_Read_R_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol(&variable)

/**********************************************************************************
   Create interface for variable AFA_bFitOpInVlvBol
  **********************************************************************************/

#define vidSET_VALUE_AFA_bFitOpInVlvBol(value)
#define vidGET_VALUE_AFA_bFitOpInVlvBol(variable)                                Rte_Read_R_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol(&variable)

/**********************************************************************************
   Create interface for variable AFA_bFitPresAirExt
  **********************************************************************************/

#define vidSET_VALUE_AFA_bFitPresAirExt(value)
#define vidGET_VALUE_AFA_bFitPresAirExt(variable)                                Rte_Read_R_AFA_bFitPresAirExt_AFA_bFitPresAirExt(&variable)

/**********************************************************************************
   Create interface for variable AFA_bFitZeroPosnThr
  **********************************************************************************/

#define vidSET_VALUE_AFA_bFitZeroPosnThr(value)
#define vidGET_VALUE_AFA_bFitZeroPosnThr(variable)                               Rte_Read_R_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr(&variable)

/**********************************************************************************
   Create interface for variable AFA_bInnovTestCohDone
  **********************************************************************************/

#define vidSET_VALUE_AFA_bInnovTestCohDone(value)
#define vidGET_VALUE_AFA_bInnovTestCohDone(variable)                             Rte_Read_R_AFA_bInnovTestCohDone_AFA_bInnovTestCohDone(&variable)

/**********************************************************************************
   Create interface for variable AFA_facIvsInjGain
  **********************************************************************************/

#define vidSET_VALUE_AFA_facIvsInjGain(value)
#define vidGET_VALUE_AFA_facIvsInjGain(variable)                                 Rte_Read_R_AFA_facIvsInjGain_AFA_facIvsInjGain(&variable)

/**********************************************************************************
   Create interface for variable AFA_facSlopInjGain
  **********************************************************************************/

#define vidSET_VALUE_AFA_facSlopInjGain(value)
#define vidGET_VALUE_AFA_facSlopInjGain(variable)                                Rte_Read_R_AFA_facSlopInjGain_AFA_facSlopInjGain(&variable)

/**********************************************************************************
   Create interface for variable AFA_noAdpClcRst
  **********************************************************************************/

#define vidSET_VALUE_AFA_noAdpClcRst(value)
#define vidGET_VALUE_AFA_noAdpClcRst(variable)                                   Rte_Read_R_AFA_noAdpClcRst_AFA_noAdpClcRst(&variable)

/**********************************************************************************
   Create interface for variable AFA_noAdpEfcAst
  **********************************************************************************/

#define vidSET_VALUE_AFA_noAdpEfcAst(value)
#define vidGET_VALUE_AFA_noAdpEfcAst(variable)                                   Rte_Read_R_AFA_noAdpEfcAst_AFA_noAdpEfcAst(&variable)

/**********************************************************************************
   Create interface for variable AFA_noRstAdpVal
  **********************************************************************************/

#define vidSET_VALUE_AFA_noRstAdpVal(value)
#define vidGET_VALUE_AFA_noRstAdpVal(variable)                                   Rte_Read_R_AFA_noRstAdpVal_AFA_noRstAdpVal(&variable)

/**********************************************************************************
   Create interface for variable AFA_pDsThrPredFil
  **********************************************************************************/

#define vidSET_VALUE_AFA_pDsThrPredFil(value)
#define vidGET_VALUE_AFA_pDsThrPredFil(variable)                                 Rte_Read_R_AFA_pDsThrPredFil_AFA_pDsThrPredFil(&variable)

/**********************************************************************************
   Create interface for variable AFA_pUsThrCorFil
  **********************************************************************************/

#define vidSET_VALUE_AFA_pUsThrCorFil(value)
#define vidGET_VALUE_AFA_pUsThrCorFil(variable)                                  Rte_Read_R_AFA_pUsThrCorFil_AFA_pUsThrCorFil(&variable)

/**********************************************************************************
   Create interface for array AFA_prm_covErrEstim
  **********************************************************************************/

#define vidSET_ARRAY_AFA_prm_covErrEstim(value,size)
#define vidGET_ARRAY_AFA_prm_covErrEstim(variable,size)                          Rte_Read_R_AFA_prm_covErrEstim_AFA_prm_covErrEstim(&variable)

#define vidSET_ARRAY_ELEMENT_AFA_prm_covErrEstim(variable,pos)
#define vidGET_ARRAY_ELEMENT_AFA_prm_covErrEstim(variable,pos){ \
  if (pos < 8)\
  { \
     DT_AFA_prm_covErrEstim datatemp[8];\
     Rte_Read_R_AFA_prm_covErrEstim_AFA_prm_covErrEstim(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable AFA_rAirLdCorFil
  **********************************************************************************/

#define vidSET_VALUE_AFA_rAirLdCorFil(value)
#define vidGET_VALUE_AFA_rAirLdCorFil(variable)                                  Rte_Read_R_AFA_rAirLdCorFil_AFA_rAirLdCorFil(&variable)

/**********************************************************************************
   Create interface for variable AFA_rAirPresFil
  **********************************************************************************/

#define vidSET_VALUE_AFA_rAirPresFil(value)
#define vidGET_VALUE_AFA_rAirPresFil(variable)                                   Rte_Read_R_AFA_rAirPresFil_AFA_rAirPresFil(&variable)

/**********************************************************************************
   Create interface for variable AFA_tiOffInj
  **********************************************************************************/

#define vidSET_VALUE_AFA_tiOffInj(value)
#define vidGET_VALUE_AFA_tiOffInj(variable)                                      Rte_Read_R_AFA_tiOffInj_AFA_tiOffInj(&variable)

/**********************************************************************************
   Create interface for variable AFReg_bAFRegAcv
  **********************************************************************************/

#define vidSET_VALUE_AFReg_bAFRegAcv(value)                                      Rte_Write_P_AFReg_bAFRegAcv_AFReg_bAFRegAcv(value)
#define vidGET_VALUE_AFReg_bAFRegAcv(variable)                                   Rte_Read_R_AFReg_bAFRegAcv_AFReg_bAFRegAcv(&variable)

/**********************************************************************************
   Create interface for variable AFReg_facCorRich
  **********************************************************************************/

#define vidSET_VALUE_AFReg_facCorRich(value)                                     Rte_Write_P_AFReg_facCorRich_AFReg_facCorRich(value)
#define vidGET_VALUE_AFReg_facCorRich(variable)                                  Rte_Read_R_AFReg_facCorRich_AFReg_facCorRich(&variable)

/**********************************************************************************
   Create interface for variable AFReg_rFbLsclFil
  **********************************************************************************/

#define vidSET_VALUE_AFReg_rFbLsclFil(value)                                     Rte_Write_P_AFReg_rFbLsclFil_AFReg_rFbLsclFil(value)
#define vidGET_VALUE_AFReg_rFbLsclFil(variable)                                  Rte_Read_R_AFReg_rFbLsclFil_AFReg_rFbLsclFil(&variable)

/**********************************************************************************
   Create interface for variable AccP_bAccPMin
  **********************************************************************************/

#define vidSET_VALUE_AccP_bAccPMin(value)                                        Rte_Write_P_AccP_bAccPMin_AccP_bAccPMin(value)
#define vidGET_VALUE_AccP_bAccPMin(variable)                                     Rte_Read_R_AccP_bAccPMin_AccP_bAccPMin(&variable)

/**********************************************************************************
   Create interface for variable AccP_bHdPtMon
  **********************************************************************************/

#define vidSET_VALUE_AccP_bHdPtMon(value)                                        Rte_Write_P_AccP_bHdPtMon_AccP_bHdPtMon(value)
#define vidGET_VALUE_AccP_bHdPtMon(variable)                                     Rte_Read_R_AccP_bHdPtMon_AccP_bHdPtMon(&variable)

/**********************************************************************************
   Create interface for variable AccP_bHdPtSen
  **********************************************************************************/

#define vidSET_VALUE_AccP_bHdPtSen(value)                                        Rte_Write_P_AccP_bHdPtSen_AccP_bHdPtSen(value)
#define vidGET_VALUE_AccP_bHdPtSen(variable)                                     Rte_Read_R_AccP_bHdPtSen_AccP_bHdPtSen(&variable)

/**********************************************************************************
   Create interface for variable AccP_rAccP
  **********************************************************************************/

#define vidSET_VALUE_AccP_rAccP(value)                                           Rte_Write_P_AccP_rAccP_AccP_rAccP(value)
#define vidGET_VALUE_AccP_rAccP(variable)                                        Rte_Read_R_AccP_rAccP_AccP_rAccP(&variable)

/**********************************************************************************
   Create interface for variable Acq_angle_arret_moteur
  **********************************************************************************/

#define vidSET_VALUE_Acq_angle_arret_moteur(value)
#define vidGET_VALUE_Acq_angle_arret_moteur(variable)                            Rte_Read_R_Acq_angle_arret_moteur_Acq_angle_arret_moteur(&variable)

/**********************************************************************************
   Create interface for variable Acq_angle_arret_moteur_redem
  **********************************************************************************/

#define vidSET_VALUE_Acq_angle_arret_moteur_redem(value)
#define vidGET_VALUE_Acq_angle_arret_moteur_redem(variable)                      Rte_Read_R_Acq_angle_arret_moteur_redem_Acq_angle_arret_moteur_redem(&variable)

/**********************************************************************************
   Create interface for variable Acq_angle_moteur
  **********************************************************************************/

#define vidSET_VALUE_Acq_angle_moteur(value)
#define vidGET_VALUE_Acq_angle_moteur(variable)                                  Rte_Read_R_Acq_angle_moteur_Acq_angle_moteur(&variable)

/**********************************************************************************
   Create interface for variable Acq_av_dernie_tps_int_dent_vileb
  **********************************************************************************/

#define vidSET_VALUE_Acq_av_dernie_tps_int_dent_vileb(value)
#define vidGET_VALUE_Acq_av_dernie_tps_int_dent_vileb(variable)                  Rte_Read_R_Acq_av_dernie_tps_int_dent_vileb_Acq_av_dernie_tps_int_dent_vileb(&variable)

/**********************************************************************************
   Create interface for variable Acq_crk_eng_run_status_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_crk_eng_run_status_upvb0(value)
#define vidGET_VALUE_Acq_crk_eng_run_status_upvb0(variable)                      Rte_Read_R_Acq_crk_eng_run_status_upvb0_Acq_crk_eng_run_status_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_crk_eng_run_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_crk_eng_run_upvb0(value)
#define vidGET_VALUE_Acq_crk_eng_run_upvb0(variable)                             Rte_Read_R_Acq_crk_eng_run_upvb0_Acq_crk_eng_run_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_crk_sync_status_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_crk_sync_status_upvb0(value)
#define vidGET_VALUE_Acq_crk_sync_status_upvb0(variable)                         Rte_Read_R_Acq_crk_sync_status_upvb0_Acq_crk_sync_status_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_crk_sync_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_crk_sync_upvb0(value)
#define vidGET_VALUE_Acq_crk_sync_upvb0(variable)                                Rte_Read_R_Acq_crk_sync_upvb0_Acq_crk_sync_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_crk_tooth_det_status_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_crk_tooth_det_status_upvb0(value)
#define vidGET_VALUE_Acq_crk_tooth_det_status_upvb0(variable)                    Rte_Read_R_Acq_crk_tooth_det_status_upvb0_Acq_crk_tooth_det_status_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_crk_tooth_det_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_crk_tooth_det_upvb0(value)
#define vidGET_VALUE_Acq_crk_tooth_det_upvb0(variable)                           Rte_Read_R_Acq_crk_tooth_det_upvb0_Acq_crk_tooth_det_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_dernier_tps_inter_dent_vileb
  **********************************************************************************/

#define vidSET_VALUE_Acq_dernier_tps_inter_dent_vileb(value)
#define vidGET_VALUE_Acq_dernier_tps_inter_dent_vileb(variable)                  Rte_Read_R_Acq_dernier_tps_inter_dent_vileb_Acq_dernier_tps_inter_dent_vileb(&variable)

/**********************************************************************************
   Create interface for variable Acq_excam_sync_status_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_excam_sync_status_upvb0(value)
#define vidGET_VALUE_Acq_excam_sync_status_upvb0(variable)                       Rte_Read_R_Acq_excam_sync_status_upvb0_Acq_excam_sync_status_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_excam_sync_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_excam_sync_upvb0(value)
#define vidGET_VALUE_Acq_excam_sync_upvb0(variable)                              Rte_Read_R_Acq_excam_sync_upvb0_Acq_excam_sync_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_excam_tooth_det_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_excam_tooth_det_upvb0(value)
#define vidGET_VALUE_Acq_excam_tooth_det_upvb0(variable)                         Rte_Read_R_Acq_excam_tooth_det_upvb0_Acq_excam_tooth_det_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_excam_tooth_det_vld_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_excam_tooth_det_vld_upvb0(value)
#define vidGET_VALUE_Acq_excam_tooth_det_vld_upvb0(variable)                     Rte_Read_R_Acq_excam_tooth_det_vld_upvb0_Acq_excam_tooth_det_vld_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_incam_sync_status_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_incam_sync_status_upvb0(value)
#define vidGET_VALUE_Acq_incam_sync_status_upvb0(variable)                       Rte_Read_R_Acq_incam_sync_status_upvb0_Acq_incam_sync_status_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_incam_sync_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_incam_sync_upvb0(value)
#define vidGET_VALUE_Acq_incam_sync_upvb0(variable)                              Rte_Read_R_Acq_incam_sync_upvb0_Acq_incam_sync_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_incam_tooth_det_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_incam_tooth_det_upvb0(value)
#define vidGET_VALUE_Acq_incam_tooth_det_upvb0(variable)                         Rte_Read_R_Acq_incam_tooth_det_upvb0_Acq_incam_tooth_det_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_incam_tooth_det_vld_upvb0
  **********************************************************************************/

#define vidSET_VALUE_Acq_incam_tooth_det_vld_upvb0(value)
#define vidGET_VALUE_Acq_incam_tooth_det_vld_upvb0(variable)                     Rte_Read_R_Acq_incam_tooth_det_vld_upvb0_Acq_incam_tooth_det_vld_upvb0(&variable)

/**********************************************************************************
   Create interface for variable Acq_pos_ang_lors_synchro
  **********************************************************************************/

#define vidSET_VALUE_Acq_pos_ang_lors_synchro(value)
#define vidGET_VALUE_Acq_pos_ang_lors_synchro(variable)                          Rte_Read_R_Acq_pos_ang_lors_synchro_Acq_pos_ang_lors_synchro(&variable)

/**********************************************************************************
   Create interface for variable Acq_pos_ang_moteur_front_aac_adm
  **********************************************************************************/

#define vidSET_VALUE_Acq_pos_ang_moteur_front_aac_adm(value)
#define vidGET_VALUE_Acq_pos_ang_moteur_front_aac_adm(variable)                  Rte_Read_R_Acq_pos_ang_moteur_front_aac_adm_Acq_pos_ang_moteur_front_aac_adm(&variable)

/**********************************************************************************
   Create interface for variable Acq_pos_ang_moteur_front_aac_ech
  **********************************************************************************/

#define vidSET_VALUE_Acq_pos_ang_moteur_front_aac_ech(value)
#define vidGET_VALUE_Acq_pos_ang_moteur_front_aac_ech(variable)                  Rte_Read_R_Acq_pos_ang_moteur_front_aac_ech_Acq_pos_ang_moteur_front_aac_ech(&variable)

/**********************************************************************************
   Create interface for variable Acq_pos_ang_red_mot_frnt_aac_ech
  **********************************************************************************/

#define vidSET_VALUE_Acq_pos_ang_red_mot_frnt_aac_ech(value)
#define vidGET_VALUE_Acq_pos_ang_red_mot_frnt_aac_ech(variable)                  Rte_Read_R_Acq_pos_ang_red_mot_frnt_aac_ech_Acq_pos_ang_red_mot_frnt_aac_ech(&variable)

/**********************************************************************************
   Create interface for variable Acq_pos_ang_red_mot_frt_aac_adm
  **********************************************************************************/

#define vidSET_VALUE_Acq_pos_ang_red_mot_frt_aac_adm(value)
#define vidGET_VALUE_Acq_pos_ang_red_mot_frt_aac_adm(variable)                   Rte_Read_R_Acq_pos_ang_red_mot_frt_aac_adm_Acq_pos_ang_red_mot_frt_aac_adm(&variable)

/**********************************************************************************
   Create interface for variable Acq_position_anglaire_moteur
  **********************************************************************************/

#define vidSET_VALUE_Acq_position_anglaire_moteur(value)
#define vidGET_VALUE_Acq_position_anglaire_moteur(variable)                      Rte_Read_R_Acq_position_anglaire_moteur_Acq_position_anglaire_moteur(&variable)

/**********************************************************************************
   Create interface for variable Acq_sens_rotation_moteur
  **********************************************************************************/

#define vidSET_VALUE_Acq_sens_rotation_moteur(value)
#define vidGET_VALUE_Acq_sens_rotation_moteur(variable)                          Rte_Read_R_Acq_sens_rotation_moteur_Acq_sens_rotation_moteur(&variable)

/**********************************************************************************
   Create interface for variable Acq_statut_pos_angulaire_moteur
  **********************************************************************************/

#define vidSET_VALUE_Acq_statut_pos_angulaire_moteur(value)
#define vidGET_VALUE_Acq_statut_pos_angulaire_moteur(variable)                   Rte_Read_R_Acq_statut_pos_angulaire_moteur_Acq_statut_pos_angulaire_moteur(&variable)

/**********************************************************************************
   Create interface for variable Acq_tension_capt_temp_air
  **********************************************************************************/

#define vidSET_VALUE_Acq_tension_capt_temp_air(value)
#define vidGET_VALUE_Acq_tension_capt_temp_air(variable)                         Rte_Read_R_Acq_tension_capt_temp_air_Acq_tension_capt_temp_air(&variable)

/**********************************************************************************
   Create interface for variable Acq_tension_capt_temp_eau
  **********************************************************************************/

#define vidSET_VALUE_Acq_tension_capt_temp_eau(value)
#define vidGET_VALUE_Acq_tension_capt_temp_eau(variable)                         Rte_Read_R_Acq_tension_capt_temp_eau_Acq_tension_capt_temp_eau(&variable)

/**********************************************************************************
   Create interface for variable Acq_tension_sonde_o2_am
  **********************************************************************************/

#define vidSET_VALUE_Acq_tension_sonde_o2_am(value)
#define vidGET_VALUE_Acq_tension_sonde_o2_am(variable)                           Rte_Read_R_Acq_tension_sonde_o2_am_Acq_tension_sonde_o2_am(&variable)

/**********************************************************************************
   Create interface for variable Acq_tension_sonde_o2_av
  **********************************************************************************/

#define vidSET_VALUE_Acq_tension_sonde_o2_av(value)
#define vidGET_VALUE_Acq_tension_sonde_o2_av(variable)                           Rte_Read_R_Acq_tension_sonde_o2_av_Acq_tension_sonde_o2_av(&variable)

/**********************************************************************************
   Create interface for variable Acq_tooth_compteur
  **********************************************************************************/

#define vidSET_VALUE_Acq_tooth_compteur(value)
#define vidGET_VALUE_Acq_tooth_compteur(variable)                                Rte_Read_R_Acq_tooth_compteur_Acq_tooth_compteur(&variable)

/**********************************************************************************
   Create interface for variable AcquiState_stEngOilLvl
  **********************************************************************************/

#define vidSET_VALUE_AcquiState_stEngOilLvl(value)
#define vidGET_VALUE_AcquiState_stEngOilLvl(variable)                            Rte_Read_R_AcquiState_stEngOilLvl_AcquiState_stEngOilLvl(&variable)

/**********************************************************************************
   Create interface for variable AcquiState_stHPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_AcquiState_stHPPmpActCmd(value)
#define vidGET_VALUE_AcquiState_stHPPmpActCmd(variable)                          Rte_Read_R_AcquiState_stHPPmpActCmd_AcquiState_stHPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Acqui_angle_crankshaft
  **********************************************************************************/

#define vidSET_VALUE_Acqui_angle_crankshaft(value)
#define vidGET_VALUE_Acqui_angle_crankshaft(variable)                            Rte_Read_R_Acqui_angle_crankshaft_Acqui_angle_crankshaft(&variable)

/**********************************************************************************
   Create interface for variable Acqui_compteur_de_pmh
  **********************************************************************************/

#define vidSET_VALUE_Acqui_compteur_de_pmh(value)
#define vidGET_VALUE_Acqui_compteur_de_pmh(variable)                             Rte_Read_R_Acqui_compteur_de_pmh_Acqui_compteur_de_pmh(&variable)

/**********************************************************************************
   Create interface for variable Acqui_diag_pompe_ess_pwd_per
  **********************************************************************************/

#define vidSET_VALUE_Acqui_diag_pompe_ess_pwd_per(value)
#define vidGET_VALUE_Acqui_diag_pompe_ess_pwd_per(variable)                      Rte_Read_R_Acqui_diag_pompe_ess_pwd_per_Acqui_diag_pompe_ess_pwd_per(&variable)

/**********************************************************************************
   Create interface for variable Acqui_diag_pompe_ess_pwd_rco
  **********************************************************************************/

#define vidSET_VALUE_Acqui_diag_pompe_ess_pwd_rco(value)
#define vidGET_VALUE_Acqui_diag_pompe_ess_pwd_rco(variable)                      Rte_Read_R_Acqui_diag_pompe_ess_pwd_rco_Acqui_diag_pompe_ess_pwd_rco(&variable)

/**********************************************************************************
   Create interface for variable Acqui_duree_dent
  **********************************************************************************/

#define vidSET_VALUE_Acqui_duree_dent(value)
#define vidGET_VALUE_Acqui_duree_dent(variable)                                  Rte_Read_R_Acqui_duree_dent_Acqui_duree_dent(&variable)

/**********************************************************************************
   Create interface for variable Acqui_pedale_embrayage_pwd_per
  **********************************************************************************/

#define vidSET_VALUE_Acqui_pedale_embrayage_pwd_per(value)
#define vidGET_VALUE_Acqui_pedale_embrayage_pwd_per(variable)                    Rte_Read_R_Acqui_pedale_embrayage_pwd_per_Acqui_pedale_embrayage_pwd_per(&variable)

/**********************************************************************************
   Create interface for variable Acqui_pedale_embrayage_pwd_rco
  **********************************************************************************/

#define vidSET_VALUE_Acqui_pedale_embrayage_pwd_rco(value)
#define vidGET_VALUE_Acqui_pedale_embrayage_pwd_rco(variable)                    Rte_Read_R_Acqui_pedale_embrayage_pwd_rco_Acqui_pedale_embrayage_pwd_rco(&variable)

/**********************************************************************************
   Create interface for variable Acqui_periode_moteur
  **********************************************************************************/

#define vidSET_VALUE_Acqui_periode_moteur(value)
#define vidGET_VALUE_Acqui_periode_moteur(variable)                              Rte_Read_R_Acqui_periode_moteur_Acqui_periode_moteur(&variable)

/**********************************************************************************
   Create interface for variable Acqui_position_pedale_1
  **********************************************************************************/

#define vidSET_VALUE_Acqui_position_pedale_1(value)
#define vidGET_VALUE_Acqui_position_pedale_1(variable)                           Rte_Read_R_Acqui_position_pedale_1_Acqui_position_pedale_1(&variable)

/**********************************************************************************
   Create interface for variable Acqui_position_pedale_2
  **********************************************************************************/

#define vidSET_VALUE_Acqui_position_pedale_2(value)
#define vidGET_VALUE_Acqui_position_pedale_2(variable)                           Rte_Read_R_Acqui_position_pedale_2_Acqui_position_pedale_2(&variable)

/**********************************************************************************
   Create interface for variable Acqui_tension_contacteur_pt_dur
  **********************************************************************************/

#define vidSET_VALUE_Acqui_tension_contacteur_pt_dur(value)
#define vidGET_VALUE_Acqui_tension_contacteur_pt_dur(variable)                   Rte_Read_R_Acqui_tension_contacteur_pt_dur_Acqui_tension_contacteur_pt_dur(&variable)

/**********************************************************************************
   Create interface for variable Acquis_point_mort_periode
  **********************************************************************************/

#define vidSET_VALUE_Acquis_point_mort_periode(value)
#define vidGET_VALUE_Acquis_point_mort_periode(variable)                         Rte_Read_R_Acquis_point_mort_periode_Acquis_point_mort_periode(&variable)

/**********************************************************************************
   Create interface for variable Acquis_point_mort_rco
  **********************************************************************************/

#define vidSET_VALUE_Acquis_point_mort_rco(value)
#define vidGET_VALUE_Acquis_point_mort_rco(variable)                             Rte_Read_R_Acquis_point_mort_rco_Acquis_point_mort_rco(&variable)

/**********************************************************************************
   Create interface for variable Acquis_tension_press_refri
  **********************************************************************************/

#define vidSET_VALUE_Acquis_tension_press_refri(value)
#define vidGET_VALUE_Acquis_tension_press_refri(variable)                        Rte_Read_R_Acquis_tension_press_refri_Acquis_tension_press_refri(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_angle_vilb_aac_adm
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_angle_vilb_aac_adm(value)
#define vidGET_VALUE_Acquisition_angle_vilb_aac_adm(variable)                    Rte_Read_R_Acquisition_angle_vilb_aac_adm_Acquisition_angle_vilb_aac_adm(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_angle_vilb_aac_ech
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_angle_vilb_aac_ech(value)
#define vidGET_VALUE_Acquisition_angle_vilb_aac_ech(variable)                    Rte_Read_R_Acquisition_angle_vilb_aac_ech_Acquisition_angle_vilb_aac_ech(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_cmde_reveil_rcd_tor
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_cmde_reveil_rcd_tor(value)
#define vidGET_VALUE_Acquisition_cmde_reveil_rcd_tor(variable)                   Rte_Read_R_Acquisition_cmde_reveil_rcd_tor_Acquisition_cmde_reveil_rcd_tor(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_etat_aac_adm
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_etat_aac_adm(value)
#define vidGET_VALUE_Acquisition_etat_aac_adm(variable)                          Rte_Read_R_Acquisition_etat_aac_adm_Acquisition_etat_aac_adm(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_etat_aac_ech
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_etat_aac_ech(value)
#define vidGET_VALUE_Acquisition_etat_aac_ech(variable)                          Rte_Read_R_Acquisition_etat_aac_ech_Acquisition_etat_aac_ech(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_etat_gmvB1_brut
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_etat_gmvB1_brut(value)
#define vidGET_VALUE_Acquisition_etat_gmvB1_brut(variable)                       Rte_Read_R_Acquisition_etat_gmvB1_brut_Acquisition_etat_gmvB1_brut(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_etat_gmvB2_brut
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_etat_gmvB2_brut(value)
#define vidGET_VALUE_Acquisition_etat_gmvB2_brut(variable)                       Rte_Read_R_Acquisition_etat_gmvB2_brut_Acquisition_etat_gmvB2_brut(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_etat_gmvC
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_etat_gmvC(value)
#define vidGET_VALUE_Acquisition_etat_gmvC(variable)                             Rte_Read_R_Acquisition_etat_gmvC_Acquisition_etat_gmvC(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_keypush_tor
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_keypush_tor(value)
#define vidGET_VALUE_Acquisition_keypush_tor(variable)                           Rte_Read_R_Acquisition_keypush_tor_Acquisition_keypush_tor(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_pedale_embrayage_tor
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_pedale_embrayage_tor(value)
#define vidGET_VALUE_Acquisition_pedale_embrayage_tor(variable)                  Rte_Read_R_Acquisition_pedale_embrayage_tor_Acquisition_pedale_embrayage_tor(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_pedale_frein_tor
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_pedale_frein_tor(value)
#define vidGET_VALUE_Acquisition_pedale_frein_tor(variable)                      Rte_Read_R_Acquisition_pedale_frein_tor_Acquisition_pedale_frein_tor(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_position_bpm_cpt1
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_position_bpm_cpt1(value)
#define vidGET_VALUE_Acquisition_position_bpm_cpt1(variable)                     Rte_Read_R_Acquisition_position_bpm_cpt1_Acquisition_position_bpm_cpt1(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_position_bpm_cpt2
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_position_bpm_cpt2(value)
#define vidGET_VALUE_Acquisition_position_bpm_cpt2(variable)                     Rte_Read_R_Acquisition_position_bpm_cpt2_Acquisition_position_bpm_cpt2(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_press_airext
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_press_airext(value)
#define vidGET_VALUE_Acquisition_press_airext(variable)                          Rte_Read_R_Acquisition_press_airext_Acquisition_press_airext(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_press_coll
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_press_coll(value)
#define vidGET_VALUE_Acquisition_press_coll(variable)                            Rte_Read_R_Acquisition_press_coll_Acquisition_press_coll(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_press_mast_abs
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_press_mast_abs(value)
#define vidGET_VALUE_Acquisition_press_mast_abs(variable)                        Rte_Read_R_Acquisition_press_mast_abs_Acquisition_press_mast_abs(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_press_mast_rel
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_press_mast_rel(value)
#define vidGET_VALUE_Acquisition_press_mast_rel(variable)                        Rte_Read_R_Acquisition_press_mast_rel_Acquisition_press_mast_rel(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_pression_huile_tor
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_pression_huile_tor(value)
#define vidGET_VALUE_Acquisition_pression_huile_tor(variable)                    Rte_Read_R_Acquisition_pression_huile_tor_Acquisition_pression_huile_tor(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_startlock_tor
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_startlock_tor(value)
#define vidGET_VALUE_Acquisition_startlock_tor(variable)                         Rte_Read_R_Acquisition_startlock_tor_Acquisition_startlock_tor(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_temps_dents_aac_adm
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_temps_dents_aac_adm(value)
#define vidGET_VALUE_Acquisition_temps_dents_aac_adm(variable)                   Rte_Read_R_Acquisition_temps_dents_aac_adm_Acquisition_temps_dents_aac_adm(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_temps_dents_aac_ech
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_temps_dents_aac_ech(value)
#define vidGET_VALUE_Acquisition_temps_dents_aac_ech(variable)                   Rte_Read_R_Acquisition_temps_dents_aac_ech_Acquisition_temps_dents_aac_ech(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_tension_batterie
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_tension_batterie(value)
#define vidGET_VALUE_Acquisition_tension_batterie(variable)                      Rte_Read_R_Acquisition_tension_batterie_Acquisition_tension_batterie(&variable)

/**********************************************************************************
   Create interface for variable Acquisition_tension_etat_bicd
  **********************************************************************************/

#define vidSET_VALUE_Acquisition_tension_etat_bicd(value)
#define vidGET_VALUE_Acquisition_tension_etat_bicd(variable)                     Rte_Read_R_Acquisition_tension_etat_bicd_Acquisition_tension_etat_bicd(&variable)

/**********************************************************************************
   Create interface for variable AdHeatCmd_bAcvCTP1Drv
  **********************************************************************************/

#define vidSET_VALUE_AdHeatCmd_bAcvCTP1Drv(value)                                Rte_Write_P_AdHeatCmd_bAcvCTP1Drv_AdHeatCmd_bAcvCTP1Drv(value)
#define vidGET_VALUE_AdHeatCmd_bAcvCTP1Drv(variable)                             Rte_Read_R_AdHeatCmd_bAcvCTP1Drv_AdHeatCmd_bAcvCTP1Drv(&variable)

/**********************************************************************************
   Create interface for variable AdHeatCmd_bAcvCTP2Drv
  **********************************************************************************/

#define vidSET_VALUE_AdHeatCmd_bAcvCTP2Drv(value)                                Rte_Write_P_AdHeatCmd_bAcvCTP2Drv_AdHeatCmd_bAcvCTP2Drv(value)
#define vidGET_VALUE_AdHeatCmd_bAcvCTP2Drv(variable)                             Rte_Read_R_AdHeatCmd_bAcvCTP2Drv_AdHeatCmd_bAcvCTP2Drv(&variable)

/**********************************************************************************
   Create interface for variable Afts_bAcvFSF
  **********************************************************************************/

#define vidSET_VALUE_Afts_bAcvFSF(value)                                         Rte_Write_P_Afts_bAcvFSF_Afts_bAcvFSF(value)
#define vidGET_VALUE_Afts_bAcvFSF(variable)                                      Rte_Read_R_Afts_bAcvFSF_Afts_bAcvFSF(&variable)

/**********************************************************************************
   Create interface for variable Afts_bAcvRlamSpTest
  **********************************************************************************/

#define vidSET_VALUE_Afts_bAcvRlamSpTest(value)                                  Rte_Write_P_Afts_bAcvRlamSpTest_Afts_bAcvRlamSpTest(value)
#define vidGET_VALUE_Afts_bAcvRlamSpTest(variable)                               Rte_Read_R_Afts_bAcvRlamSpTest_Afts_bAcvRlamSpTest(&variable)

/**********************************************************************************
   Create interface for variable Afts_bAcvTrbActRatOpReqByp
  **********************************************************************************/

#define vidSET_VALUE_Afts_bAcvTrbActRatOpReqByp(value)                           Rte_Write_P_Afts_bAcvTrbActRatOpReqByp_Afts_bAcvTrbActRatOpReqByp(value)
#define vidGET_VALUE_Afts_bAcvTrbActRatOpReqByp(variable)                        Rte_Read_R_Afts_bAcvTrbActRatOpReqByp_Afts_bAcvTrbActRatOpReqByp(&variable)

/**********************************************************************************
   Create interface for variable Afts_bDiagToolReq
  **********************************************************************************/

#define vidSET_VALUE_Afts_bDiagToolReq(value)                                    Rte_Write_P_Afts_bDiagToolReq_Afts_bDiagToolReq(value)
#define vidGET_VALUE_Afts_bDiagToolReq(variable)                                 Rte_Read_R_Afts_bDiagToolReq_Afts_bDiagToolReq(&variable)

/**********************************************************************************
   Create interface for variable Afts_bInhAnStick
  **********************************************************************************/

#define vidSET_VALUE_Afts_bInhAnStick(value)                                     Rte_Write_P_Afts_bInhAnStick_Afts_bInhAnStick(value)
#define vidGET_VALUE_Afts_bInhAnStick(variable)                                  Rte_Read_R_Afts_bInhAnStick_Afts_bInhAnStick(&variable)

/**********************************************************************************
   Create interface for variable Afts_bInhIniRunReq
  **********************************************************************************/

#define vidSET_VALUE_Afts_bInhIniRunReq(value)                                   Rte_Write_P_Afts_bInhIniRunReq_Afts_bInhIniRunReq(value)
#define vidGET_VALUE_Afts_bInhIniRunReq(variable)                                Rte_Read_R_Afts_bInhIniRunReq_Afts_bInhIniRunReq(&variable)

/**********************************************************************************
   Create interface for variable Afts_bInhStSoCBatt
  **********************************************************************************/

#define vidSET_VALUE_Afts_bInhStSoCBatt(value)                                   Rte_Write_P_Afts_bInhStSoCBatt_Afts_bInhStSoCBatt(value)
#define vidGET_VALUE_Afts_bInhStSoCBatt(variable)                                Rte_Read_R_Afts_bInhStSoCBatt_Afts_bInhStSoCBatt(&variable)

/**********************************************************************************
   Create interface for variable Afts_bLrnRstReq_iElNwStop
  **********************************************************************************/

#define vidSET_VALUE_Afts_bLrnRstReq_iElNwStop(value)                            Rte_Write_P_Afts_bLrnRstReq_iElNwStop_Afts_bLrnRstReq_iElNwStop(value)
#define vidGET_VALUE_Afts_bLrnRstReq_iElNwStop(variable)                         Rte_Read_R_Afts_bLrnRstReq_iElNwStop_Afts_bLrnRstReq_iElNwStop(&variable)

/**********************************************************************************
   Create interface for variable Afts_bLrnRstReq_rOfsSoC
  **********************************************************************************/

#define vidSET_VALUE_Afts_bLrnRstReq_rOfsSoC(value)                              Rte_Write_P_Afts_bLrnRstReq_rOfsSoC_Afts_bLrnRstReq_rOfsSoC(value)
#define vidGET_VALUE_Afts_bLrnRstReq_rOfsSoC(variable)                           Rte_Read_R_Afts_bLrnRstReq_rOfsSoC_Afts_bLrnRstReq_rOfsSoC(&variable)

/**********************************************************************************
   Create interface for variable Afts_bLrnRstReq_uEmPredRstrt
  **********************************************************************************/

#define vidSET_VALUE_Afts_bLrnRstReq_uEmPredRstrt(value)                         Rte_Write_P_Afts_bLrnRstReq_uEmPredRstrt_Afts_bLrnRstReq_uEmPredRstrt(value)
#define vidGET_VALUE_Afts_bLrnRstReq_uEmPredRstrt(variable)                      Rte_Read_R_Afts_bLrnRstReq_uEmPredRstrt_Afts_bLrnRstReq_uEmPredRstrt(&variable)

/**********************************************************************************
   Create interface for variable Afts_bRstDfwChg
  **********************************************************************************/

#define vidSET_VALUE_Afts_bRstDfwChg(value)                                      Rte_Write_P_Afts_bRstDfwChg_Afts_bRstDfwChg(value)
#define vidGET_VALUE_Afts_bRstDfwChg(variable)                                   Rte_Read_R_Afts_bRstDfwChg_Afts_bRstDfwChg(&variable)

/**********************************************************************************
   Create interface for variable Afts_bRstMemCoReqRStrt
  **********************************************************************************/

#define vidSET_VALUE_Afts_bRstMemCoReqRStrt(value)                               Rte_Write_P_Afts_bRstMemCoReqRStrt_Afts_bRstMemCoReqRStrt(value)
#define vidGET_VALUE_Afts_bRstMemCoReqRStrt(variable)                            Rte_Read_R_Afts_bRstMemCoReqRStrt_Afts_bRstMemCoReqRStrt(&variable)

/**********************************************************************************
   Create interface for variable Afts_bRstReqStcBatt
  **********************************************************************************/

#define vidSET_VALUE_Afts_bRstReqStcBatt(value)                                  Rte_Write_P_Afts_bRstReqStcBatt_Afts_bRstReqStcBatt(value)
#define vidGET_VALUE_Afts_bRstReqStcBatt(variable)                               Rte_Read_R_Afts_bRstReqStcBatt_Afts_bRstReqStcBatt(&variable)

/**********************************************************************************
   Create interface for variable Afts_bRstReq_ctStaAcv
  **********************************************************************************/

#define vidSET_VALUE_Afts_bRstReq_ctStaAcv(value)                                Rte_Write_P_Afts_bRstReq_ctStaAcv_Afts_bRstReq_ctStaAcv(value)
#define vidGET_VALUE_Afts_bRstReq_ctStaAcv(variable)                             Rte_Read_R_Afts_bRstReq_ctStaAcv_Afts_bRstReq_ctStaAcv(&variable)

/**********************************************************************************
   Create interface for variable Afts_bRstReq_stSoHBatt
  **********************************************************************************/

#define vidSET_VALUE_Afts_bRstReq_stSoHBatt(value)                               Rte_Write_P_Afts_bRstReq_stSoHBatt_Afts_bRstReq_stSoHBatt(value)
#define vidGET_VALUE_Afts_bRstReq_stSoHBatt(variable)                            Rte_Read_R_Afts_bRstReq_stSoHBatt_Afts_bRstReq_stSoHBatt(&variable)

/**********************************************************************************
   Create interface for variable Afts_rMixtReqRlamSpTest
  **********************************************************************************/

#define vidSET_VALUE_Afts_rMixtReqRlamSpTest(value)                              Rte_Write_P_Afts_rMixtReqRlamSpTest_Afts_rMixtReqRlamSpTest(value)
#define vidGET_VALUE_Afts_rMixtReqRlamSpTest(variable)                           Rte_Read_R_Afts_rMixtReqRlamSpTest_Afts_rMixtReqRlamSpTest(&variable)

/**********************************************************************************
   Create interface for variable Afts_rOpTrbActReq
  **********************************************************************************/

#define vidSET_VALUE_Afts_rOpTrbActReq(value)                                    Rte_Write_P_Afts_rOpTrbActReq_Afts_rOpTrbActReq(value)
#define vidGET_VALUE_Afts_rOpTrbActReq(variable)                                 Rte_Read_R_Afts_rOpTrbActReq_Afts_rOpTrbActReq(&variable)

/**********************************************************************************
   Create interface for variable Afts_stSpcFactSTTReq
  **********************************************************************************/

#define vidSET_VALUE_Afts_stSpcFactSTTReq(value)                                 Rte_Write_P_Afts_stSpcFactSTTReq_Afts_stSpcFactSTTReq(value)
#define vidGET_VALUE_Afts_stSpcFactSTTReq(variable)                              Rte_Read_R_Afts_stSpcFactSTTReq_Afts_stSpcFactSTTReq(&variable)

/**********************************************************************************
   Create interface for variable AfuA_bInvldEthRat
  **********************************************************************************/

#define vidSET_VALUE_AfuA_bInvldEthRat(value)                                    Rte_Write_P_AfuA_bInvldEthRat_AfuA_bInvldEthRat(value)
#define vidGET_VALUE_AfuA_bInvldEthRat(variable)                                 Rte_Read_R_AfuA_bInvldEthRat_AfuA_bInvldEthRat(&variable)

/**********************************************************************************
   Create interface for variable AfuA_rEthStoich
  **********************************************************************************/

#define vidSET_VALUE_AfuA_rEthStoich(value)
#define vidGET_VALUE_AfuA_rEthStoich(variable)                                   Rte_Read_R_AfuA_rEthStoich_AfuA_rEthStoich(&variable)

/**********************************************************************************
   Create interface for variable AirPres_bAcvBrkAsiAcq
  **********************************************************************************/

#define vidSET_VALUE_AirPres_bAcvBrkAsiAcq(value)                                Rte_Write_P_AirPres_bAcvBrkAsiAcq_AirPres_bAcvBrkAsiAcq(value)
#define vidGET_VALUE_AirPres_bAcvBrkAsiAcq(variable)                             Rte_Read_R_AirPres_bAcvBrkAsiAcq_AirPres_bAcvBrkAsiAcq(&variable)

/**********************************************************************************
   Create interface for variable AirSys_arEfcThrReqWoutTqSys
  **********************************************************************************/

#define vidSET_VALUE_AirSys_arEfcThrReqWoutTqSys(value)                          Rte_Write_P_AirSys_arEfcThrReqWoutTqSys_AirSys_arEfcThrReqWoutTqSys(value)
#define vidGET_VALUE_AirSys_arEfcThrReqWoutTqSys(variable)                       Rte_Read_R_AirSys_arEfcThrReqWoutTqSys_AirSys_arEfcThrReqWoutTqSys(&variable)

/**********************************************************************************
   Create interface for variable AirSys_bActStraLimSurge
  **********************************************************************************/

#define vidSET_VALUE_AirSys_bActStraLimSurge(value)
#define vidGET_VALUE_AirSys_bActStraLimSurge(variable)                           Rte_Read_R_AirSys_bActStraLimSurge_AirSys_bActStraLimSurge(&variable)

/**********************************************************************************
   Create interface for variable AirSys_bAcvFrzMod
  **********************************************************************************/

#define vidSET_VALUE_AirSys_bAcvFrzMod(value)
#define vidGET_VALUE_AirSys_bAcvFrzMod(variable)                                 Rte_Read_R_AirSys_bAcvFrzMod_AirSys_bAcvFrzMod(&variable)

/**********************************************************************************
   Create interface for variable AirSys_effAfr
  **********************************************************************************/

#define vidSET_VALUE_AirSys_effAfr(value)                                        Rte_Write_P_AirSys_effAfr_AirSys_effAfr(value)
#define vidGET_VALUE_AirSys_effAfr(variable)                                     Rte_Read_R_AirSys_effAfr_AirSys_effAfr(&variable)

/**********************************************************************************
   Create interface for variable AirSys_effCyc
  **********************************************************************************/

#define vidSET_VALUE_AirSys_effCyc(value)                                        Rte_Write_P_AirSys_effCyc_AirSys_effCyc(value)
#define vidGET_VALUE_AirSys_effCyc(variable)                                     Rte_Read_R_AirSys_effCyc_AirSys_effCyc(&variable)

/**********************************************************************************
   Create interface for variable AirSys_effEGR
  **********************************************************************************/

#define vidSET_VALUE_AirSys_effEGR(value)                                        Rte_Write_P_AirSys_effEGR_AirSys_effEGR(value)
#define vidGET_VALUE_AirSys_effEGR(variable)                                     Rte_Read_R_AirSys_effEGR_AirSys_effEGR(&variable)

/**********************************************************************************
   Create interface for variable AirSys_facTranAir
  **********************************************************************************/

#define vidSET_VALUE_AirSys_facTranAir(value)                                    Rte_Write_P_AirSys_facTranAir_AirSys_facTranAir(value)
#define vidGET_VALUE_AirSys_facTranAir(variable)                                 Rte_Read_R_AirSys_facTranAir_AirSys_facTranAir(&variable)

/**********************************************************************************
   Create interface for variable AirSys_mAirEngCylReq_tqEng
  **********************************************************************************/

#define vidSET_VALUE_AirSys_mAirEngCylReq_tqEng(value)
#define vidGET_VALUE_AirSys_mAirEngCylReq_tqEng(variable)                        Rte_Read_R_AirSys_mAirEngCylReq_tqEng_AirSys_mAirEngCylReq_tqEng(&variable)

/**********************************************************************************
   Create interface for variable AirSys_mfAirMesThrEstim
  **********************************************************************************/

#define vidSET_VALUE_AirSys_mfAirMesThrEstim(value)                              Rte_Write_P_AirSys_mfAirMesThrEstim_AirSys_mfAirMesThrEstim(value)
#define vidGET_VALUE_AirSys_mfAirMesThrEstim(variable)                           Rte_Read_R_AirSys_mfAirMesThrEstim_AirSys_mfAirMesThrEstim(&variable)

/**********************************************************************************
   Create interface for variable AirSys_mfAirMesThrEstim_swc
  **********************************************************************************/

#define vidSET_VALUE_AirSys_mfAirMesThrEstim_swc(value)                          Rte_Write_P_AirSys_mfAirMesThrEstim_swc_AirSys_mfAirMesThrEstim_swc(value)
#define vidGET_VALUE_AirSys_mfAirMesThrEstim_swc(variable)                       Rte_Read_R_AirSys_mfAirMesThrEstim_swc_AirSys_mfAirMesThrEstim_swc(&variable)

/**********************************************************************************
   Create interface for variable AirSys_mfAirThrReqFil
  **********************************************************************************/

#define vidSET_VALUE_AirSys_mfAirThrReqFil(value)
#define vidGET_VALUE_AirSys_mfAirThrReqFil(variable)                             Rte_Read_R_AirSys_mfAirThrReqFil_AirSys_mfAirThrReqFil(&variable)

/**********************************************************************************
   Create interface for array AirSys_prm_mfAirThrReq
  **********************************************************************************/

#define vidSET_ARRAY_AirSys_prm_mfAirThrReq(value,size)
#define vidGET_ARRAY_AirSys_prm_mfAirThrReq(variable,size)                       Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq(&variable)

#define vidSET_ARRAY_ELEMENT_AirSys_prm_mfAirThrReq(variable,pos)
#define vidGET_ARRAY_ELEMENT_AirSys_prm_mfAirThrReq(variable,pos){ \
  if (pos < 2)\
  { \
     DT_AirSys_prm_mfAirThrReq datatemp[2];\
     Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array AirSys_prm_pInMnfReq
  **********************************************************************************/

#define vidSET_ARRAY_AirSys_prm_pInMnfReq(value,size)
#define vidGET_ARRAY_AirSys_prm_pInMnfReq(variable,size)                         Rte_Read_R_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq(&variable)

#define vidSET_ARRAY_ELEMENT_AirSys_prm_pInMnfReq(variable,pos)
#define vidGET_ARRAY_ELEMENT_AirSys_prm_pInMnfReq(variable,pos){ \
  if (pos < 2)\
  { \
     DT_AirSys_prm_pInMnfReq datatemp[2];\
     Rte_Read_R_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable AirSys_rAirLdReq
  **********************************************************************************/

#define vidSET_VALUE_AirSys_rAirLdReq(value)
#define vidGET_VALUE_AirSys_rAirLdReq(variable)                                  Rte_Read_R_AirSys_rAirLdReq_AirSys_rAirLdReq(&variable)

/**********************************************************************************
   Create interface for variable AirSys_rClcLamEfc
  **********************************************************************************/

#define vidSET_VALUE_AirSys_rClcLamEfc(value)                                    Rte_Write_P_AirSys_rClcLamEfc_AirSys_rClcLamEfc(value)
#define vidGET_VALUE_AirSys_rClcLamEfc(variable)                                 Rte_Read_R_AirSys_rClcLamEfc_AirSys_rClcLamEfc(&variable)

/**********************************************************************************
   Create interface for variable AirSys_rFullLdLamEfc
  **********************************************************************************/

#define vidSET_VALUE_AirSys_rFullLdLamEfc(value)                                 Rte_Write_P_AirSys_rFullLdLamEfc_AirSys_rFullLdLamEfc(value)
#define vidGET_VALUE_AirSys_rFullLdLamEfc(variable)                              Rte_Read_R_AirSys_rFullLdLamEfc_AirSys_rFullLdLamEfc(&variable)

/**********************************************************************************
   Create interface for variable Auto_injection
  **********************************************************************************/

#define vidSET_VALUE_Auto_injection(value)                                       Rte_Write_P_Auto_injection_Auto_injection(value)
#define vidGET_VALUE_Auto_injection(variable)                                    Rte_Read_R_Auto_injection_Auto_injection(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_bAntiAgiStraEfcChIdc
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_bAntiAgiStraEfcChIdc(value)
#define vidGET_VALUE_BatMgt_bAntiAgiStraEfcChIdc(variable)                       Rte_Read_R_BatMgt_bAntiAgiStraEfcChIdc_BatMgt_bAntiAgiStraEfcChIdc(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_bAntiAgiStraEndIdc
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_bAntiAgiStraEndIdc(value)
#define vidGET_VALUE_BatMgt_bAntiAgiStraEndIdc(variable)                         Rte_Read_R_BatMgt_bAntiAgiStraEndIdc_BatMgt_bAntiAgiStraEndIdc(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_bBattAntiAgiAcvReq
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_bBattAntiAgiAcvReq(value)
#define vidGET_VALUE_BatMgt_bBattAntiAgiAcvReq(variable)                         Rte_Read_R_BatMgt_bBattAntiAgiAcvReq_BatMgt_bBattAntiAgiAcvReq(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_bBattChProtAcvReq
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_bBattChProtAcvReq(value)
#define vidGET_VALUE_BatMgt_bBattChProtAcvReq(variable)                          Rte_Read_R_BatMgt_bBattChProtAcvReq_BatMgt_bBattChProtAcvReq(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_bBattSoCMinProtAcvReq
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_bBattSoCMinProtAcvReq(value)
#define vidGET_VALUE_BatMgt_bBattSoCMinProtAcvReq(variable)                      Rte_Read_R_BatMgt_bBattSoCMinProtAcvReq_BatMgt_bBattSoCMinProtAcvReq(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_bBattStopPrepAcvReq
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_bBattStopPrepAcvReq(value)
#define vidGET_VALUE_BatMgt_bBattStopPrepAcvReq(variable)                        Rte_Read_R_BatMgt_bBattStopPrepAcvReq_BatMgt_bBattStopPrepAcvReq(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_bBattTProtAcvReq
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_bBattTProtAcvReq(value)
#define vidGET_VALUE_BatMgt_bBattTProtAcvReq(variable)                           Rte_Read_R_BatMgt_bBattTProtAcvReq_BatMgt_bBattTProtAcvReq(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_ctStcAcvAntiAgiStra
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_ctStcAcvAntiAgiStra(value)
#define vidGET_VALUE_BatMgt_ctStcAcvAntiAgiStra(variable)                        Rte_Read_R_BatMgt_ctStcAcvAntiAgiStra_BatMgt_ctStcAcvAntiAgiStra(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_ctStcCnclAntiAgiStra
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_ctStcCnclAntiAgiStra(value)
#define vidGET_VALUE_BatMgt_ctStcCnclAntiAgiStra(variable)                       Rte_Read_R_BatMgt_ctStcCnclAntiAgiStra_BatMgt_ctStcCnclAntiAgiStra(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_grdNegSlopBattAntiAgi
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_grdNegSlopBattAntiAgi(value)
#define vidGET_VALUE_BatMgt_grdNegSlopBattAntiAgi(variable)                      Rte_Read_R_BatMgt_grdNegSlopBattAntiAgi_BatMgt_grdNegSlopBattAntiAgi(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_grdNegSlopBattChProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_grdNegSlopBattChProt(value)
#define vidGET_VALUE_BatMgt_grdNegSlopBattChProt(variable)                       Rte_Read_R_BatMgt_grdNegSlopBattChProt_BatMgt_grdNegSlopBattChProt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_grdNegSlopBattTProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_grdNegSlopBattTProt(value)
#define vidGET_VALUE_BatMgt_grdNegSlopBattTProt(variable)                        Rte_Read_R_BatMgt_grdNegSlopBattTProt_BatMgt_grdNegSlopBattTProt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_grdPosSlopBattAntiAgi
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_grdPosSlopBattAntiAgi(value)
#define vidGET_VALUE_BatMgt_grdPosSlopBattAntiAgi(variable)                      Rte_Read_R_BatMgt_grdPosSlopBattAntiAgi_BatMgt_grdPosSlopBattAntiAgi(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_grdPosSlopBattChProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_grdPosSlopBattChProt(value)
#define vidGET_VALUE_BatMgt_grdPosSlopBattChProt(variable)                       Rte_Read_R_BatMgt_grdPosSlopBattChProt_BatMgt_grdPosSlopBattChProt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_grdPosSlopBattTProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_grdPosSlopBattTProt(value)
#define vidGET_VALUE_BatMgt_grdPosSlopBattTProt(variable)                        Rte_Read_R_BatMgt_grdPosSlopBattTProt_BatMgt_grdPosSlopBattTProt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_iBattMes
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_iBattMes(value)
#define vidGET_VALUE_BatMgt_iBattMes(variable)                                   Rte_Read_R_BatMgt_iBattMes_BatMgt_iBattMes(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_rBattSoCCor
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_rBattSoCCor(value)
#define vidGET_VALUE_BatMgt_rBattSoCCor(variable)                                Rte_Read_R_BatMgt_rBattSoCCor_BatMgt_rBattSoCCor(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_rOfsSoC
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_rOfsSoC(value)
#define vidGET_VALUE_BatMgt_rOfsSoC(variable)                                    Rte_Read_R_BatMgt_rOfsSoC_BatMgt_rOfsSoC(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_rSoCErrEstim
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_rSoCErrEstim(value)
#define vidGET_VALUE_BatMgt_rSoCErrEstim(variable)                               Rte_Read_R_BatMgt_rSoCErrEstim_BatMgt_rSoCErrEstim(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_rStcSoCMax
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_rStcSoCMax(value)
#define vidGET_VALUE_BatMgt_rStcSoCMax(variable)                                 Rte_Read_R_BatMgt_rStcSoCMax_BatMgt_rStcSoCMax(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_rStcSoCMin
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_rStcSoCMin(value)
#define vidGET_VALUE_BatMgt_rStcSoCMin(variable)                                 Rte_Read_R_BatMgt_rStcSoCMin_BatMgt_rStcSoCMin(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_resBattIt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_resBattIt(value)
#define vidGET_VALUE_BatMgt_resBattIt(variable)                                  Rte_Read_R_BatMgt_resBattIt_BatMgt_resBattIt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_resBattItNorm
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_resBattItNorm(value)
#define vidGET_VALUE_BatMgt_resBattItNorm(variable)                              Rte_Read_R_BatMgt_resBattItNorm_BatMgt_resBattItNorm(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_stBattSoC
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_stBattSoC(value)
#define vidGET_VALUE_BatMgt_stBattSoC(variable)                                  Rte_Read_R_BatMgt_stBattSoC_BatMgt_stBattSoC(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_stBattSoH
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_stBattSoH(value)
#define vidGET_VALUE_BatMgt_stBattSoH(variable)                                  Rte_Read_R_BatMgt_stBattSoH_BatMgt_stBattSoH(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_stBattSt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_stBattSt(value)
#define vidGET_VALUE_BatMgt_stBattSt(variable)                                   Rte_Read_R_BatMgt_stBattSt_BatMgt_stBattSt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_tBattMes
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_tBattMes(value)
#define vidGET_VALUE_BatMgt_tBattMes(variable)                                   Rte_Read_R_BatMgt_tBattMes_BatMgt_tBattMes(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_tiStcVoltBattDmg
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_tiStcVoltBattDmg(value)
#define vidGET_VALUE_BatMgt_tiStcVoltBattDmg(variable)                           Rte_Read_R_BatMgt_tiStcVoltBattDmg_BatMgt_tiStcVoltBattDmg(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uBattMes
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uBattMes(value)
#define vidGET_VALUE_BatMgt_uBattMes(variable)                                   Rte_Read_R_BatMgt_uBattMes_BatMgt_uBattMes(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uBattOc
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uBattOc(value)
#define vidGET_VALUE_BatMgt_uBattOc(variable)                                    Rte_Read_R_BatMgt_uBattOc_BatMgt_uBattOc(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uBattRstrt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uBattRstrt(value)
#define vidGET_VALUE_BatMgt_uBattRstrt(variable)                                 Rte_Read_R_BatMgt_uBattRstrt_BatMgt_uBattRstrt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uBattStrt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uBattStrt(value)
#define vidGET_VALUE_BatMgt_uBattStrt(variable)                                  Rte_Read_R_BatMgt_uBattStrt_BatMgt_uBattStrt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uReqEmMaxBattAntiAgi
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uReqEmMaxBattAntiAgi(value)
#define vidGET_VALUE_BatMgt_uReqEmMaxBattAntiAgi(variable)                       Rte_Read_R_BatMgt_uReqEmMaxBattAntiAgi_BatMgt_uReqEmMaxBattAntiAgi(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uReqEmMaxBattChProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uReqEmMaxBattChProt(value)
#define vidGET_VALUE_BatMgt_uReqEmMaxBattChProt(variable)                        Rte_Read_R_BatMgt_uReqEmMaxBattChProt_BatMgt_uReqEmMaxBattChProt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uReqEmMaxBattTProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uReqEmMaxBattTProt(value)
#define vidGET_VALUE_BatMgt_uReqEmMaxBattTProt(variable)                         Rte_Read_R_BatMgt_uReqEmMaxBattTProt_BatMgt_uReqEmMaxBattTProt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uReqEmMinBattAntiAgi
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uReqEmMinBattAntiAgi(value)
#define vidGET_VALUE_BatMgt_uReqEmMinBattAntiAgi(variable)                       Rte_Read_R_BatMgt_uReqEmMinBattAntiAgi_BatMgt_uReqEmMinBattAntiAgi(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uReqEmMinBattChProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uReqEmMinBattChProt(value)
#define vidGET_VALUE_BatMgt_uReqEmMinBattChProt(variable)                        Rte_Read_R_BatMgt_uReqEmMinBattChProt_BatMgt_uReqEmMinBattChProt(&variable)

/**********************************************************************************
   Create interface for variable BatMgt_uReqEmMinBattTProt
  **********************************************************************************/

#define vidSET_VALUE_BatMgt_uReqEmMinBattTProt(value)
#define vidGET_VALUE_BatMgt_uReqEmMinBattTProt(variable)                         Rte_Read_R_BatMgt_uReqEmMinBattTProt_BatMgt_uReqEmMinBattTProt(&variable)

/**********************************************************************************
   Create interface for variable Blby_bIdcWoutBlbyCnd
  **********************************************************************************/

#define vidSET_VALUE_Blby_bIdcWoutBlbyCnd(value)                                 Rte_Write_P_Blby_bIdcWoutBlbyCnd_Blby_bIdcWoutBlbyCnd(value)
#define vidGET_VALUE_Blby_bIdcWoutBlbyCnd(variable)                              Rte_Read_R_Blby_bIdcWoutBlbyCnd_Blby_bIdcWoutBlbyCnd(&variable)

/**********************************************************************************
   Create interface for variable Brk_bBrkDyn
  **********************************************************************************/

#define vidSET_VALUE_Brk_bBrkDyn(value)                                          Rte_Write_P_Brk_bBrkDyn_Brk_bBrkDyn(value)
#define vidGET_VALUE_Brk_bBrkDyn(variable)                                       Rte_Read_R_Brk_bBrkDyn_Brk_bBrkDyn(&variable)

/**********************************************************************************
   Create interface for variable CanPurg_bAcvClsPurgReq
  **********************************************************************************/

#define vidSET_VALUE_CanPurg_bAcvClsPurgReq(value)                               Rte_Write_P_CanPurg_bAcvClsPurgReq_CanPurg_bAcvClsPurgReq(value)
#define vidGET_VALUE_CanPurg_bAcvClsPurgReq(variable)                            Rte_Read_R_CanPurg_bAcvClsPurgReq_CanPurg_bAcvClsPurgReq(&variable)

/**********************************************************************************
   Create interface for variable CanPurg_concFuStmErr
  **********************************************************************************/

#define vidSET_VALUE_CanPurg_concFuStmErr(value)                                 Rte_Write_P_CanPurg_concFuStmErr_CanPurg_concFuStmErr(value)
#define vidGET_VALUE_CanPurg_concFuStmErr(variable)                              Rte_Read_R_CanPurg_concFuStmErr_CanPurg_concFuStmErr(&variable)

/**********************************************************************************
   Create interface for variable CanPurg_concFuStmEstim
  **********************************************************************************/

#define vidSET_VALUE_CanPurg_concFuStmEstim(value)                               Rte_Write_P_CanPurg_concFuStmEstim_CanPurg_concFuStmEstim(value)
#define vidGET_VALUE_CanPurg_concFuStmEstim(variable)                            Rte_Read_R_CanPurg_concFuStmEstim_CanPurg_concFuStmEstim(&variable)

/**********************************************************************************
   Create interface for variable CanPurg_mfFuStmEstim
  **********************************************************************************/

#define vidSET_VALUE_CanPurg_mfFuStmEstim(value)                                 Rte_Write_P_CanPurg_mfFuStmEstim_CanPurg_mfFuStmEstim(value)
#define vidGET_VALUE_CanPurg_mfFuStmEstim(variable)                              Rte_Read_R_CanPurg_mfFuStmEstim_CanPurg_mfFuStmEstim(&variable)

/**********************************************************************************
   Create interface for variable CanPurg_rOpCanPurgReq
  **********************************************************************************/

#define vidSET_VALUE_CanPurg_rOpCanPurgReq(value)                                Rte_Write_P_CanPurg_rOpCanPurgReq_CanPurg_rOpCanPurgReq(value)
#define vidGET_VALUE_CanPurg_rOpCanPurgReq(variable)                             Rte_Read_R_CanPurg_rOpCanPurgReq_CanPurg_rOpCanPurgReq(&variable)

/**********************************************************************************
   Create interface for variable CatMon_bAcvSeqMemORng_Cat
  **********************************************************************************/

#define vidSET_VALUE_CatMon_bAcvSeqMemORng_Cat(value)
#define vidGET_VALUE_CatMon_bAcvSeqMemORng_Cat(variable)                         Rte_Read_R_CatMon_bAcvSeqMemORng_Cat_CatMon_bAcvSeqMemORng_Cat(&variable)

/**********************************************************************************
   Create interface for variable CatMon_bAcvSeqORng_Cat
  **********************************************************************************/

#define vidSET_VALUE_CatMon_bAcvSeqORng_Cat(value)
#define vidGET_VALUE_CatMon_bAcvSeqORng_Cat(variable)                            Rte_Read_R_CatMon_bAcvSeqORng_Cat_CatMon_bAcvSeqORng_Cat(&variable)

/**********************************************************************************
   Create interface for variable CatMon_bDgoORngIntr
  **********************************************************************************/

#define vidSET_VALUE_CatMon_bDgoORngIntr(value)
#define vidGET_VALUE_CatMon_bDgoORngIntr(variable)                               Rte_Read_R_CatMon_bDgoORngIntr_CatMon_bDgoORngIntr(&variable)

/**********************************************************************************
   Create interface for variable CatMon_bMonRunORngIntr
  **********************************************************************************/

#define vidSET_VALUE_CatMon_bMonRunORngIntr(value)
#define vidGET_VALUE_CatMon_bMonRunORngIntr(variable)                            Rte_Read_R_CatMon_bMonRunORngIntr_CatMon_bMonRunORngIntr(&variable)

/**********************************************************************************
   Create interface for variable CatMon_bMonWaitORngIntr
  **********************************************************************************/

#define vidSET_VALUE_CatMon_bMonWaitORngIntr(value)
#define vidGET_VALUE_CatMon_bMonWaitORngIntr(variable)                           Rte_Read_R_CatMon_bMonWaitORngIntr_CatMon_bMonWaitORngIntr(&variable)

/**********************************************************************************
   Create interface for variable CatMon_facMax_Obd6Mod
  **********************************************************************************/

#define vidSET_VALUE_CatMon_facMax_Obd6Mod(value)
#define vidGET_VALUE_CatMon_facMax_Obd6Mod(variable)                             Rte_Read_R_CatMon_facMax_Obd6Mod_CatMon_facMax_Obd6Mod(&variable)

/**********************************************************************************
   Create interface for variable CatMon_facMes_Obd6Mod
  **********************************************************************************/

#define vidSET_VALUE_CatMon_facMes_Obd6Mod(value)
#define vidGET_VALUE_CatMon_facMes_Obd6Mod(variable)                             Rte_Read_R_CatMon_facMes_Obd6Mod_CatMon_facMes_Obd6Mod(&variable)

/**********************************************************************************
   Create interface for variable CatMon_facMin_Obd6Mod
  **********************************************************************************/

#define vidSET_VALUE_CatMon_facMin_Obd6Mod(value)
#define vidGET_VALUE_CatMon_facMin_Obd6Mod(variable)                             Rte_Read_R_CatMon_facMin_Obd6Mod_CatMon_facMin_Obd6Mod(&variable)

/**********************************************************************************
   Create interface for variable Cat_debit_gaz_moy
  **********************************************************************************/

#define vidSET_VALUE_Cat_debit_gaz_moy(value)
#define vidGET_VALUE_Cat_debit_gaz_moy(variable)                                 Rte_Read_R_Cat_debit_gaz_moy_Cat_debit_gaz_moy(&variable)

/**********************************************************************************
   Create interface for variable Cat_light_off_achieved
  **********************************************************************************/

#define vidSET_VALUE_Cat_light_off_achieved(value)                               Rte_Write_P_Cat_light_off_achieved_Cat_light_off_achieved(value)
#define vidGET_VALUE_Cat_light_off_achieved(variable)                            Rte_Read_R_Cat_light_off_achieved_Cat_light_off_achieved(&variable)

/**********************************************************************************
   Create interface for variable Cat_mon_inhibe_fast_tracking
  **********************************************************************************/

#define vidSET_VALUE_Cat_mon_inhibe_fast_tracking(value)
#define vidGET_VALUE_Cat_mon_inhibe_fast_tracking(variable)                      Rte_Read_R_Cat_mon_inhibe_fast_tracking_Cat_mon_inhibe_fast_tracking(&variable)

/**********************************************************************************
   Create interface for variable Cat_seuil_obd_flex
  **********************************************************************************/

#define vidSET_VALUE_Cat_seuil_obd_flex(value)                                   Rte_Write_P_Cat_seuil_obd_flex_Cat_seuil_obd_flex(value)
#define vidGET_VALUE_Cat_seuil_obd_flex(variable)                                Rte_Read_R_Cat_seuil_obd_flex_Cat_seuil_obd_flex(&variable)

/**********************************************************************************
   Create interface for variable Cat_seuil_obd_pond_flex
  **********************************************************************************/

#define vidSET_VALUE_Cat_seuil_obd_pond_flex(value)                              Rte_Write_P_Cat_seuil_obd_pond_flex_Cat_seuil_obd_pond_flex(value)
#define vidGET_VALUE_Cat_seuil_obd_pond_flex(variable)                           Rte_Read_R_Cat_seuil_obd_pond_flex_Cat_seuil_obd_pond_flex(&variable)

/**********************************************************************************
   Create interface for variable Cat_temperature
  **********************************************************************************/

#define vidSET_VALUE_Cat_temperature(value)                                      Rte_Write_P_Cat_temperature_Cat_temperature(value)
#define vidGET_VALUE_Cat_temperature(variable)                                   Rte_Read_R_Cat_temperature_Cat_temperature(&variable)

/**********************************************************************************
   Create interface for variable Cat_temperature_moy
  **********************************************************************************/

#define vidSET_VALUE_Cat_temperature_moy(value)
#define vidGET_VALUE_Cat_temperature_moy(variable)                               Rte_Read_R_Cat_temperature_moy_Cat_temperature_moy(&variable)

/**********************************************************************************
   Create interface for variable Cf_bInhFlex
  **********************************************************************************/

#define vidSET_VALUE_Cf_bInhFlex(value)                                          Rte_Write_P_Cf_bInhFlex_Cf_bInhFlex(value)
#define vidGET_VALUE_Cf_bInhFlex(variable)                                       Rte_Read_R_Cf_bInhFlex_Cf_bInhFlex(&variable)

/**********************************************************************************
   Create interface for variable Cf_bSecBrkPedPrss
  **********************************************************************************/

#define vidSET_VALUE_Cf_bSecBrkPedPrss(value)                                    Rte_Write_P_Cf_bSecBrkPedPrss_Cf_bSecBrkPedPrss(value)
#define vidGET_VALUE_Cf_bSecBrkPedPrss(variable)                                 Rte_Read_R_Cf_bSecBrkPedPrss_Cf_bSecBrkPedPrss(&variable)

/**********************************************************************************
   Create interface for variable Cf_cooling_fan_equipment
  **********************************************************************************/

#define vidSET_VALUE_Cf_cooling_fan_equipment(value)                             Rte_Write_P_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment(value)
#define vidGET_VALUE_Cf_cooling_fan_equipment(variable)                          Rte_Read_R_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment(&variable)

/**********************************************************************************
   Create interface for variable Cha_bABSReg
  **********************************************************************************/

#define vidSET_VALUE_Cha_bABSReg(value)                                          Rte_Write_P_Cha_bABSReg_Cha_bABSReg(value)
#define vidGET_VALUE_Cha_bABSReg(variable)                                       Rte_Read_R_Cha_bABSReg_Cha_bABSReg(&variable)

/**********************************************************************************
   Create interface for variable Cha_stEPB
  **********************************************************************************/

#define vidSET_VALUE_Cha_stEPB(value)                                            Rte_Write_P_Cha_stEPB_Cha_stEPB(value)
#define vidGET_VALUE_Cha_stEPB(variable)                                         Rte_Read_R_Cha_stEPB_Cha_stEPB(&variable)

/**********************************************************************************
   Create interface for variable Cha_stHillAsi
  **********************************************************************************/

#define vidSET_VALUE_Cha_stHillAsi(value)                                        Rte_Write_P_Cha_stHillAsi_Cha_stHillAsi(value)
#define vidGET_VALUE_Cha_stHillAsi(variable)                                     Rte_Read_R_Cha_stHillAsi_Cha_stHillAsi(&variable)

/**********************************************************************************
   Create interface for variable Cha_stTqReq
  **********************************************************************************/

#define vidSET_VALUE_Cha_stTqReq(value)                                          Rte_Write_P_Cha_stTqReq_Cha_stTqReq(value)
#define vidGET_VALUE_Cha_stTqReq(variable)                                       Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&variable)

/**********************************************************************************
   Create interface for variable Cha_tqDynASRReq
  **********************************************************************************/

#define vidSET_VALUE_Cha_tqDynASRReq(value)                                      Rte_Write_P_Cha_tqDynASRReq_Cha_tqDynASRReq(value)
#define vidGET_VALUE_Cha_tqDynASRReq(variable)                                   Rte_Read_R_Cha_tqDynASRReq_Cha_tqDynASRReq(&variable)

/**********************************************************************************
   Create interface for variable Cha_tqMSRReq
  **********************************************************************************/

#define vidSET_VALUE_Cha_tqMSRReq(value)                                         Rte_Write_P_Cha_tqMSRReq_Cha_tqMSRReq(value)
#define vidGET_VALUE_Cha_tqMSRReq(variable)                                      Rte_Read_R_Cha_tqMSRReq_Cha_tqMSRReq(&variable)

/**********************************************************************************
   Create interface for variable Clef_de_contact
  **********************************************************************************/

#define vidSET_VALUE_Clef_de_contact(value)                                      Rte_Write_P_Clef_de_contact_Clef_de_contact(value)
#define vidGET_VALUE_Clef_de_contact(variable)                                   Rte_Read_R_Clef_de_contact_Clef_de_contact(&variable)

/**********************************************************************************
   Create interface for variable Clu_bCluPedEng
  **********************************************************************************/

#define vidSET_VALUE_Clu_bCluPedEng(value)
#define vidGET_VALUE_Clu_bCluPedEng(variable)                                    Rte_Read_R_Clu_bCluPedEng_Clu_bCluPedEng(&variable)

/**********************************************************************************
   Create interface for variable Clu_bCluPedxVV
  **********************************************************************************/

#define vidSET_VALUE_Clu_bCluPedxVV(value)
#define vidGET_VALUE_Clu_bCluPedxVV(variable)                                    Rte_Read_R_Clu_bCluPedxVV_Clu_bCluPedxVV(&variable)

/**********************************************************************************
   Create interface for variable Clu_bDrvTra
  **********************************************************************************/

#define vidSET_VALUE_Clu_bDrvTra(value)
#define vidGET_VALUE_Clu_bDrvTra(variable)                                       Rte_Read_R_Clu_bDrvTra_Clu_bDrvTra(&variable)

/**********************************************************************************
   Create interface for variable Cmde_autorisation_redem_stt_tor
  **********************************************************************************/

#define vidSET_VALUE_Cmde_autorisation_redem_stt_tor(value)                      Rte_Write_P_Cmde_autorisation_redem_stt_tor_Cmde_autorisation_redem_stt_tor(value)
#define vidGET_VALUE_Cmde_autorisation_redem_stt_tor(variable)                   Rte_Read_R_Cmde_autorisation_redem_stt_tor_Cmde_autorisation_redem_stt_tor(&variable)

/**********************************************************************************
   Create interface for variable Cmde_info_moteur_tournant_tor
  **********************************************************************************/

#define vidSET_VALUE_Cmde_info_moteur_tournant_tor(value)                        Rte_Write_P_Cmde_info_moteur_tournant_tor_Cmde_info_moteur_tournant_tor(value)
#define vidGET_VALUE_Cmde_info_moteur_tournant_tor(variable)                     Rte_Read_R_Cmde_info_moteur_tournant_tor_Cmde_info_moteur_tournant_tor(&variable)

/**********************************************************************************
   Create interface for variable Cmde_logique_dml_tor
  **********************************************************************************/

#define vidSET_VALUE_Cmde_logique_dml_tor(value)                                 Rte_Write_P_Cmde_logique_dml_tor_Cmde_logique_dml_tor(value)
#define vidGET_VALUE_Cmde_logique_dml_tor(variable)                              Rte_Read_R_Cmde_logique_dml_tor_Cmde_logique_dml_tor(&variable)

/**********************************************************************************
   Create interface for variable CoBrk_bAcvBrk
  **********************************************************************************/

#define vidSET_VALUE_CoBrk_bAcvBrk(value)
#define vidGET_VALUE_CoBrk_bAcvBrk(variable)                                     Rte_Read_R_CoBrk_bAcvBrk_CoBrk_bAcvBrk(&variable)

/**********************************************************************************
   Create interface for variable CoCha_bASRSecuReq
  **********************************************************************************/

#define vidSET_VALUE_CoCha_bASRSecuReq(value)                                    Rte_Write_P_CoCha_bASRSecuReq_CoCha_bASRSecuReq(value)
#define vidGET_VALUE_CoCha_bASRSecuReq(variable)                                 Rte_Read_R_CoCha_bASRSecuReq_CoCha_bASRSecuReq(&variable)

/**********************************************************************************
   Create interface for variable CoCha_bInhEGRTrv
  **********************************************************************************/

#define vidSET_VALUE_CoCha_bInhEGRTrv(value)
#define vidGET_VALUE_CoCha_bInhEGRTrv(variable)                                  Rte_Read_R_CoCha_bInhEGRTrv_CoCha_bInhEGRTrv(&variable)

/**********************************************************************************
   Create interface for variable CoCha_bTqReqASR
  **********************************************************************************/

#define vidSET_VALUE_CoCha_bTqReqASR(value)
#define vidGET_VALUE_CoCha_bTqReqASR(variable)                                   Rte_Read_R_CoCha_bTqReqASR_CoCha_bTqReqASR(&variable)

/**********************************************************************************
   Create interface for variable CoCha_bTqReqMSR
  **********************************************************************************/

#define vidSET_VALUE_CoCha_bTqReqMSR(value)
#define vidGET_VALUE_CoCha_bTqReqMSR(variable)                                   Rte_Read_R_CoCha_bTqReqMSR_CoCha_bTqReqMSR(&variable)

/**********************************************************************************
   Create interface for variable CoCha_noCylCutAuthIt
  **********************************************************************************/

#define vidSET_VALUE_CoCha_noCylCutAuthIt(value)                                 Rte_Write_P_CoCha_noCylCutAuthIt_CoCha_noCylCutAuthIt(value)
#define vidGET_VALUE_CoCha_noCylCutAuthIt(variable)                              Rte_Read_R_CoCha_noCylCutAuthIt_CoCha_noCylCutAuthIt(&variable)

/**********************************************************************************
   Create interface for variable CoCha_tqEfcLim
  **********************************************************************************/

#define vidSET_VALUE_CoCha_tqEfcLim(value)
#define vidGET_VALUE_CoCha_tqEfcLim(variable)                                    Rte_Read_R_CoCha_tqEfcLim_CoCha_tqEfcLim(&variable)

/**********************************************************************************
   Create interface for variable CoCha_tqEfcLimTqMaxDyn
  **********************************************************************************/

#define vidSET_VALUE_CoCha_tqEfcLimTqMaxDyn(value)
#define vidGET_VALUE_CoCha_tqEfcLimTqMaxDyn(variable)                            Rte_Read_R_CoCha_tqEfcLimTqMaxDyn_CoCha_tqEfcLimTqMaxDyn(&variable)

/**********************************************************************************
   Create interface for variable CoCha_tqEfcReq
  **********************************************************************************/

#define vidSET_VALUE_CoCha_tqEfcReq(value)
#define vidGET_VALUE_CoCha_tqEfcReq(variable)                                    Rte_Read_R_CoCha_tqEfcReq_CoCha_tqEfcReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bDetSlowN
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bDetSlowN(value)
#define vidGET_VALUE_CoEmCkg_bDetSlowN(variable)                                 Rte_Read_R_CoEmCkg_bDetSlowN_CoEmCkg_bDetSlowN(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bInfoCplReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bInfoCplReq(value)
#define vidGET_VALUE_CoEmCkg_bInfoCplReq(variable)                               Rte_Read_R_CoEmCkg_bInfoCplReq_CoEmCkg_bInfoCplReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bInfoCplSt
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bInfoCplSt(value)
#define vidGET_VALUE_CoEmCkg_bInfoCplSt(variable)                                Rte_Read_R_CoEmCkg_bInfoCplSt_CoEmCkg_bInfoCplSt(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bReqAltBoostFil
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bReqAltBoostFil(value)
#define vidGET_VALUE_CoEmCkg_bReqAltBoostFil(variable)                           Rte_Read_R_CoEmCkg_bReqAltBoostFil_CoEmCkg_bReqAltBoostFil(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bRvAltPrepRstrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bRvAltPrepRstrtReq(value)
#define vidGET_VALUE_CoEmCkg_bRvAltPrepRstrtReq(variable)                        Rte_Read_R_CoEmCkg_bRvAltPrepRstrtReq_CoEmCkg_bRvAltPrepRstrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bRvAltRstrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bRvAltRstrtReq(value)
#define vidGET_VALUE_CoEmCkg_bRvAltRstrtReq(variable)                            Rte_Read_R_CoEmCkg_bRvAltRstrtReq_CoEmCkg_bRvAltRstrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bStaRstrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bStaRstrtReq(value)
#define vidGET_VALUE_CoEmCkg_bStaRstrtReq(variable)                              Rte_Read_R_CoEmCkg_bStaRstrtReq_CoEmCkg_bStaRstrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bStaStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bStaStrtReq(value)
#define vidGET_VALUE_CoEmCkg_bStaStrtReq(variable)                               Rte_Read_R_CoEmCkg_bStaStrtReq_CoEmCkg_bStaStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bVldFastN
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bVldFastN(value)
#define vidGET_VALUE_CoEmCkg_bVldFastN(variable)                                 Rte_Read_R_CoEmCkg_bVldFastN_CoEmCkg_bVldFastN(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_bWaitStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_bWaitStrtReq(value)
#define vidGET_VALUE_CoEmCkg_bWaitStrtReq(variable)                              Rte_Read_R_CoEmCkg_bWaitStrtReq_CoEmCkg_bWaitStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_nFast
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_nFast(value)
#define vidGET_VALUE_CoEmCkg_nFast(variable)                                     Rte_Read_R_CoEmCkg_nFast_CoEmCkg_nFast(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_nStaEgdHiThd
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_nStaEgdHiThd(value)
#define vidGET_VALUE_CoEmCkg_nStaEgdHiThd(variable)                              Rte_Read_R_CoEmCkg_nStaEgdHiThd_CoEmCkg_nStaEgdHiThd(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_nStaEgdLoThd
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_nStaEgdLoThd(value)
#define vidGET_VALUE_CoEmCkg_nStaEgdLoThd(variable)                              Rte_Read_R_CoEmCkg_nStaEgdLoThd_CoEmCkg_nStaEgdLoThd(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_stReqAltBoost
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_stReqAltBoost(value)
#define vidGET_VALUE_CoEmCkg_stReqAltBoost(variable)                             Rte_Read_R_CoEmCkg_stReqAltBoost_CoEmCkg_stReqAltBoost(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_stSTTCf
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_stSTTCf(value)
#define vidGET_VALUE_CoEmCkg_stSTTCf(variable)                                   Rte_Read_R_CoEmCkg_stSTTCf_CoEmCkg_stSTTCf(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_stStrtRstrtFbCmd
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_stStrtRstrtFbCmd(value)
#define vidGET_VALUE_CoEmCkg_stStrtRstrtFbCmd(variable)                          Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_tiStaEgdHiThd
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_tiStaEgdHiThd(value)
#define vidGET_VALUE_CoEmCkg_tiStaEgdHiThd(variable)                             Rte_Read_R_CoEmCkg_tiStaEgdHiThd_CoEmCkg_tiStaEgdHiThd(&variable)

/**********************************************************************************
   Create interface for variable CoEmCkg_tiStaEgdLoThd
  **********************************************************************************/

#define vidSET_VALUE_CoEmCkg_tiStaEgdLoThd(value)
#define vidGET_VALUE_CoEmCkg_tiStaEgdLoThd(variable)                             Rte_Read_R_CoEmCkg_tiStaEgdLoThd_CoEmCkg_tiStaEgdLoThd(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bBattPrf
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bBattPrf(value)
#define vidGET_VALUE_CoEmSTT_bBattPrf(variable)                                  Rte_Read_R_CoEmSTT_bBattPrf_CoEmSTT_bBattPrf(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bBattProt
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bBattProt(value)
#define vidGET_VALUE_CoEmSTT_bBattProt(variable)                                 Rte_Read_R_CoEmSTT_bBattProt_CoEmSTT_bBattProt(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bBattUncrtSoC
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bBattUncrtSoC(value)
#define vidGET_VALUE_CoEmSTT_bBattUncrtSoC(variable)                             Rte_Read_R_CoEmSTT_bBattUncrtSoC_CoEmSTT_bBattUncrtSoC(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bOverThdUcapBoost
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bOverThdUcapBoost(value)
#define vidGET_VALUE_CoEmSTT_bOverThdUcapBoost(variable)                         Rte_Read_R_CoEmSTT_bOverThdUcapBoost_CoEmSTT_bOverThdUcapBoost(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bRvAltCritT
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bRvAltCritT(value)
#define vidGET_VALUE_CoEmSTT_bRvAltCritT(variable)                               Rte_Read_R_CoEmSTT_bRvAltCritT_CoEmSTT_bRvAltCritT(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bRvAltEngRstrtAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bRvAltEngRstrtAuth(value)
#define vidGET_VALUE_CoEmSTT_bRvAltEngRstrtAuth(variable)                        Rte_Read_R_CoEmSTT_bRvAltEngRstrtAuth_CoEmSTT_bRvAltEngRstrtAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bRvAltEngRstrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bRvAltEngRstrtReq(value)
#define vidGET_VALUE_CoEmSTT_bRvAltEngRstrtReq(variable)                         Rte_Read_R_CoEmSTT_bRvAltEngRstrtReq_CoEmSTT_bRvAltEngRstrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bRvAltEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bRvAltEngStopAuth(value)
#define vidGET_VALUE_CoEmSTT_bRvAltEngStopAuth(variable)                         Rte_Read_R_CoEmSTT_bRvAltEngStopAuth_CoEmSTT_bRvAltEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bStaProt
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bStaProt(value)
#define vidGET_VALUE_CoEmSTT_bStaProt(variable)                                  Rte_Read_R_CoEmSTT_bStaProt_CoEmSTT_bStaProt(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bUcapDchaAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bUcapDchaAuth(value)
#define vidGET_VALUE_CoEmSTT_bUcapDchaAuth(variable)                             Rte_Read_R_CoEmSTT_bUcapDchaAuth_CoEmSTT_bUcapDchaAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bUcapUndVolt
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bUcapUndVolt(value)
#define vidGET_VALUE_CoEmSTT_bUcapUndVolt(variable)                              Rte_Read_R_CoEmSTT_bUcapUndVolt_CoEmSTT_bUcapUndVolt(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bVSSCtzCrit
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bVSSCtzCrit(value)
#define vidGET_VALUE_CoEmSTT_bVSSCtzCrit(variable)                               Rte_Read_R_CoEmSTT_bVSSCtzCrit_CoEmSTT_bVSSCtzCrit(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bVSSCtzEngRstrtAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bVSSCtzEngRstrtAuth(value)
#define vidGET_VALUE_CoEmSTT_bVSSCtzEngRstrtAuth(variable)                       Rte_Read_R_CoEmSTT_bVSSCtzEngRstrtAuth_CoEmSTT_bVSSCtzEngRstrtAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bVSSCtzEngRstrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bVSSCtzEngRstrtReq(value)
#define vidGET_VALUE_CoEmSTT_bVSSCtzEngRstrtReq(variable)                        Rte_Read_R_CoEmSTT_bVSSCtzEngRstrtReq_CoEmSTT_bVSSCtzEngRstrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bVSSCtzEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bVSSCtzEngStopAuth(value)
#define vidGET_VALUE_CoEmSTT_bVSSCtzEngStopAuth(variable)                        Rte_Read_R_CoEmSTT_bVSSCtzEngStopAuth_CoEmSTT_bVSSCtzEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_bVSSCtzStrtAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_bVSSCtzStrtAuth(value)
#define vidGET_VALUE_CoEmSTT_bVSSCtzStrtAuth(variable)                           Rte_Read_R_CoEmSTT_bVSSCtzStrtAuth_CoEmSTT_bVSSCtzStrtAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_ctRstrtAcvTi
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_ctRstrtAcvTi(value)
#define vidGET_VALUE_CoEmSTT_ctRstrtAcvTi(variable)                              Rte_Read_R_CoEmSTT_ctRstrtAcvTi_CoEmSTT_ctRstrtAcvTi(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_facSen_uEmPredRstrt
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_facSen_uEmPredRstrt(value)
#define vidGET_VALUE_CoEmSTT_facSen_uEmPredRstrt(variable)                       Rte_Read_R_CoEmSTT_facSen_uEmPredRstrt_CoEmSTT_facSen_uEmPredRstrt(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_stBattEngRstrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_stBattEngRstrtReq(value)
#define vidGET_VALUE_CoEmSTT_stBattEngRstrtReq(variable)                         Rte_Read_R_CoEmSTT_stBattEngRstrtReq_CoEmSTT_stBattEngRstrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_stBattEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_stBattEngStopAuth(value)
#define vidGET_VALUE_CoEmSTT_stBattEngStopAuth(variable)                         Rte_Read_R_CoEmSTT_stBattEngStopAuth_CoEmSTT_stBattEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_stEngRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_stEngRStrtReq(value)
#define vidGET_VALUE_CoEmSTT_stEngRStrtReq(variable)                             Rte_Read_R_CoEmSTT_stEngRStrtReq_CoEmSTT_stEngRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_stEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_stEngStopAuth(value)
#define vidGET_VALUE_CoEmSTT_stEngStopAuth(variable)                             Rte_Read_R_CoEmSTT_stEngStopAuth_CoEmSTT_stEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_stTypEmPredRstrt
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_stTypEmPredRstrt(value)
#define vidGET_VALUE_CoEmSTT_stTypEmPredRstrt(variable)                          Rte_Read_R_CoEmSTT_stTypEmPredRstrt_CoEmSTT_stTypEmPredRstrt(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_stUcapChSp
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_stUcapChSp(value)
#define vidGET_VALUE_CoEmSTT_stUcapChSp(variable)                                Rte_Read_R_CoEmSTT_stUcapChSp_CoEmSTT_stUcapChSp(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_uEmPredRstrt
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_uEmPredRstrt(value)
#define vidGET_VALUE_CoEmSTT_uEmPredRstrt(variable)                              Rte_Read_R_CoEmSTT_uEmPredRstrt_CoEmSTT_uEmPredRstrt(&variable)

/**********************************************************************************
   Create interface for variable CoEmSTT_uUcapSp
  **********************************************************************************/

#define vidSET_VALUE_CoEmSTT_uUcapSp(value)
#define vidGET_VALUE_CoEmSTT_uUcapSp(variable)                                   Rte_Read_R_CoEmSTT_uUcapSp_CoEmSTT_uUcapSp(&variable)

/**********************************************************************************
   Create interface for variable CoEs_bAcvIgSysSTTEs
  **********************************************************************************/

#define vidSET_VALUE_CoEs_bAcvIgSysSTTEs(value)                                  Rte_Write_P_CoEs_bAcvIgSysSTTEs_CoEs_bAcvIgSysSTTEs(value)
#define vidGET_VALUE_CoEs_bAcvIgSysSTTEs(variable)                               Rte_Read_R_CoEs_bAcvIgSysSTTEs_CoEs_bAcvIgSysSTTEs(&variable)

/**********************************************************************************
   Create interface for variable CoEs_bAcvInjCutOffSTTEs
  **********************************************************************************/

#define vidSET_VALUE_CoEs_bAcvInjCutOffSTTEs(value)                              Rte_Write_P_CoEs_bAcvInjCutOffSTTEs_CoEs_bAcvInjCutOffSTTEs(value)
#define vidGET_VALUE_CoEs_bAcvInjCutOffSTTEs(variable)                           Rte_Read_R_CoEs_bAcvInjCutOffSTTEs_CoEs_bAcvInjCutOffSTTEs(&variable)

/**********************************************************************************
   Create interface for variable CoEs_bAcvVlvSysLockPosnSTTEs
  **********************************************************************************/

#define vidSET_VALUE_CoEs_bAcvVlvSysLockPosnSTTEs(value)                         Rte_Write_P_CoEs_bAcvVlvSysLockPosnSTTEs_CoEs_bAcvVlvSysLockPosnSTTEs(value)
#define vidGET_VALUE_CoEs_bAcvVlvSysLockPosnSTTEs(variable)                      Rte_Read_R_CoEs_bAcvVlvSysLockPosnSTTEs_CoEs_bAcvVlvSysLockPosnSTTEs(&variable)

/**********************************************************************************
   Create interface for variable CoEs_bIntrSTTEsHiEngSpd
  **********************************************************************************/

#define vidSET_VALUE_CoEs_bIntrSTTEsHiEngSpd(value)                              Rte_Write_P_CoEs_bIntrSTTEsHiEngSpd_CoEs_bIntrSTTEsHiEngSpd(value)
#define vidGET_VALUE_CoEs_bIntrSTTEsHiEngSpd(variable)                           Rte_Read_R_CoEs_bIntrSTTEsHiEngSpd_CoEs_bIntrSTTEsHiEngSpd(&variable)

/**********************************************************************************
   Create interface for variable CoEs_bIntrSTTEsLoEngSpd
  **********************************************************************************/

#define vidSET_VALUE_CoEs_bIntrSTTEsLoEngSpd(value)                              Rte_Write_P_CoEs_bIntrSTTEsLoEngSpd_CoEs_bIntrSTTEsLoEngSpd(value)
#define vidGET_VALUE_CoEs_bIntrSTTEsLoEngSpd(variable)                           Rte_Read_R_CoEs_bIntrSTTEsLoEngSpd_CoEs_bIntrSTTEsLoEngSpd(&variable)

/**********************************************************************************
   Create interface for variable CoHeat_bAcvHeatMgt
  **********************************************************************************/

#define vidSET_VALUE_CoHeat_bAcvHeatMgt(value)                                   Rte_Write_P_CoHeat_bAcvHeatMgt_CoHeat_bAcvHeatMgt(value)
#define vidGET_VALUE_CoHeat_bAcvHeatMgt(variable)                                Rte_Read_R_CoHeat_bAcvHeatMgt_CoHeat_bAcvHeatMgt(&variable)

/**********************************************************************************
   Create interface for variable CoHeat_tCoEstim
  **********************************************************************************/

#define vidSET_VALUE_CoHeat_tCoEstim(value)                                      Rte_Write_P_CoHeat_tCoEstim_CoHeat_tCoEstim(value)
#define vidGET_VALUE_CoHeat_tCoEstim(variable)                                   Rte_Read_R_CoHeat_tCoEstim_CoHeat_tCoEstim(&variable)

/**********************************************************************************
   Create interface for variable CoHeat_tCoEstimStrt
  **********************************************************************************/

#define vidSET_VALUE_CoHeat_tCoEstimStrt(value)                                  Rte_Write_P_CoHeat_tCoEstimStrt_CoHeat_tCoEstimStrt(value)
#define vidGET_VALUE_CoHeat_tCoEstimStrt(variable)                               Rte_Read_R_CoHeat_tCoEstimStrt_CoHeat_tCoEstimStrt(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_bAcvElCnsReq
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_bAcvElCnsReq(value)
#define vidGET_VALUE_CoOptmEl_bAcvElCnsReq(variable)                             Rte_Read_R_CoOptmEl_bAcvElCnsReq_CoOptmEl_bAcvElCnsReq(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_bAuthAntiAgiStra
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_bAuthAntiAgiStra(value)
#define vidGET_VALUE_CoOptmEl_bAuthAntiAgiStra(variable)                         Rte_Read_R_CoOptmEl_bAuthAntiAgiStra_CoOptmEl_bAuthAntiAgiStra(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_bWupAcv
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_bWupAcv(value)
#define vidGET_VALUE_CoOptmEl_bWupAcv(variable)                                  Rte_Read_R_CoOptmEl_bWupAcv_CoOptmEl_bWupAcv(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_bfAcvConstEm1
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_bfAcvConstEm1(value)
#define vidGET_VALUE_CoOptmEl_bfAcvConstEm1(variable)                            Rte_Read_R_CoOptmEl_bfAcvConstEm1_CoOptmEl_bfAcvConstEm1(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_bfAcvConstEm2
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_bfAcvConstEm2(value)
#define vidGET_VALUE_CoOptmEl_bfAcvConstEm2(variable)                            Rte_Read_R_CoOptmEl_bfAcvConstEm2_CoOptmEl_bfAcvConstEm2(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_grdNegSlop
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_grdNegSlop(value)
#define vidGET_VALUE_CoOptmEl_grdNegSlop(variable)                               Rte_Read_R_CoOptmEl_grdNegSlop_CoOptmEl_grdNegSlop(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_grdPosSlop
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_grdPosSlop(value)
#define vidGET_VALUE_CoOptmEl_grdPosSlop(variable)                               Rte_Read_R_CoOptmEl_grdPosSlop_CoOptmEl_grdPosSlop(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_iElNw
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_iElNw(value)
#define vidGET_VALUE_CoOptmEl_iElNw(variable)                                    Rte_Read_R_CoOptmEl_iElNw_CoOptmEl_iElNw(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_iElProdMaxLdBatt
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_iElProdMaxLdBatt(value)
#define vidGET_VALUE_CoOptmEl_iElProdMaxLdBatt(variable)                         Rte_Read_R_CoOptmEl_iElProdMaxLdBatt_CoOptmEl_iElProdMaxLdBatt(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_rBattSoCSp
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_rBattSoCSp(value)
#define vidGET_VALUE_CoOptmEl_rBattSoCSp(variable)                               Rte_Read_R_CoOptmEl_rBattSoCSp_CoOptmEl_rBattSoCSp(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_rElRecup
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_rElRecup(value)
#define vidGET_VALUE_CoOptmEl_rElRecup(variable)                                 Rte_Read_R_CoOptmEl_rElRecup_CoOptmEl_rElRecup(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_rElRest
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_rElRest(value)
#define vidGET_VALUE_CoOptmEl_rElRest(variable)                                  Rte_Read_R_CoOptmEl_rElRest_CoOptmEl_rElRest(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stDetConstNegSlop
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stDetConstNegSlop(value)
#define vidGET_VALUE_CoOptmEl_stDetConstNegSlop(variable)                        Rte_Read_R_CoOptmEl_stDetConstNegSlop_CoOptmEl_stDetConstNegSlop(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stDetConstPosSlop
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stDetConstPosSlop(value)
#define vidGET_VALUE_CoOptmEl_stDetConstPosSlop(variable)                        Rte_Read_R_CoOptmEl_stDetConstPosSlop_CoOptmEl_stDetConstPosSlop(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stDetConstVoltMax
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stDetConstVoltMax(value)
#define vidGET_VALUE_CoOptmEl_stDetConstVoltMax(variable)                        Rte_Read_R_CoOptmEl_stDetConstVoltMax_CoOptmEl_stDetConstVoltMax(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stDetConstVoltMin
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stDetConstVoltMin(value)
#define vidGET_VALUE_CoOptmEl_stDetConstVoltMin(variable)                        Rte_Read_R_CoOptmEl_stDetConstVoltMin_CoOptmEl_stDetConstVoltMin(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stElEProv
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stElEProv(value)
#define vidGET_VALUE_CoOptmEl_stElEProv(variable)                                Rte_Read_R_CoOptmEl_stElEProv_CoOptmEl_stElEProv(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stElLvlProd
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stElLvlProd(value)
#define vidGET_VALUE_CoOptmEl_stElLvlProd(variable)                              Rte_Read_R_CoOptmEl_stElLvlProd_CoOptmEl_stElLvlProd(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stOptmElCf
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stOptmElCf(value)
#define vidGET_VALUE_CoOptmEl_stOptmElCf(variable)                               Rte_Read_R_CoOptmEl_stOptmElCf_CoOptmEl_stOptmElCf(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stOptmElStra
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stOptmElStra(value)
#define vidGET_VALUE_CoOptmEl_stOptmElStra(variable)                             Rte_Read_R_CoOptmEl_stOptmElStra_CoOptmEl_stOptmElStra(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stPrevElProdReq
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stPrevElProdReq(value)
#define vidGET_VALUE_CoOptmEl_stPrevElProdReq(variable)                          Rte_Read_R_CoOptmEl_stPrevElProdReq_CoOptmEl_stPrevElProdReq(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stPrgChReq
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stPrgChReq(value)
#define vidGET_VALUE_CoOptmEl_stPrgChReq(variable)                               Rte_Read_R_CoOptmEl_stPrgChReq_CoOptmEl_stPrgChReq(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_stStraVoltBatt
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_stStraVoltBatt(value)
#define vidGET_VALUE_CoOptmEl_stStraVoltBatt(variable)                           Rte_Read_R_CoOptmEl_stStraVoltBatt_CoOptmEl_stStraVoltBatt(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_tiLdSoCAuthStop
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_tiLdSoCAuthStop(value)
#define vidGET_VALUE_CoOptmEl_tiLdSoCAuthStop(variable)                          Rte_Read_R_CoOptmEl_tiLdSoCAuthStop_CoOptmEl_tiLdSoCAuthStop(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_tqAlt
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_tqAlt(value)
#define vidGET_VALUE_CoOptmEl_tqAlt(variable)                                    Rte_Read_R_CoOptmEl_tqAlt_CoOptmEl_tqAlt(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_uMax
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_uMax(value)
#define vidGET_VALUE_CoOptmEl_uMax(variable)                                     Rte_Read_R_CoOptmEl_uMax_CoOptmEl_uMax(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_uMin
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_uMin(value)
#define vidGET_VALUE_CoOptmEl_uMin(variable)                                     Rte_Read_R_CoOptmEl_uMin_CoOptmEl_uMin(&variable)

/**********************************************************************************
   Create interface for variable CoOptmEl_uMinInc
  **********************************************************************************/

#define vidSET_VALUE_CoOptmEl_uMinInc(value)
#define vidGET_VALUE_CoOptmEl_uMinInc(variable)                                  Rte_Read_R_CoOptmEl_uMinInc_CoOptmEl_uMinInc(&variable)

/**********************************************************************************
   Create interface for variable CoPTStNew_stEng
  **********************************************************************************/

#define vidSET_VALUE_CoPTStNew_stEng(value)
#define vidGET_VALUE_CoPTStNew_stEng(variable)                                   Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&variable)

/**********************************************************************************
   Create interface for variable CoPTStNew_stEngPrec
  **********************************************************************************/

#define vidSET_VALUE_CoPTStNew_stEngPrec(value)
#define vidGET_VALUE_CoPTStNew_stEngPrec(variable)                               Rte_Read_R_CoPTStNew_stEngPrec_CoPTStNew_stEngPrec(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bDgoSftyORngAMT
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bDgoSftyORngAMT(value)
#define vidGET_VALUE_CoPTSt_bDgoSftyORngAMT(variable)                            Rte_Read_R_CoPTSt_bDgoSftyORngAMT_CoPTSt_bDgoSftyORngAMT(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bDgoSftyORngAT
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bDgoSftyORngAT(value)
#define vidGET_VALUE_CoPTSt_bDgoSftyORngAT(variable)                             Rte_Read_R_CoPTSt_bDgoSftyORngAT_CoPTSt_bDgoSftyORngAT(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bEngRun
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bEngRun(value)
#define vidGET_VALUE_CoPTSt_bEngRun(variable)                                    Rte_Read_R_CoPTSt_bEngRun_CoPTSt_bEngRun(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bEngRunSTT
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bEngRunSTT(value)
#define vidGET_VALUE_CoPTSt_bEngRunSTT(variable)                                 Rte_Read_R_CoPTSt_bEngRunSTT_CoPTSt_bEngRunSTT(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bEngStop
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bEngStop(value)
#define vidGET_VALUE_CoPTSt_bEngStop(variable)                                   Rte_Read_R_CoPTSt_bEngStop_CoPTSt_bEngStop(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bMainEngStopReq
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bMainEngStopReq(value)
#define vidGET_VALUE_CoPTSt_bMainEngStopReq(variable)                            Rte_Read_R_CoPTSt_bMainEngStopReq_CoPTSt_bMainEngStopReq(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bMonRunSftyORngAMT
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bMonRunSftyORngAMT(value)
#define vidGET_VALUE_CoPTSt_bMonRunSftyORngAMT(variable)                         Rte_Read_R_CoPTSt_bMonRunSftyORngAMT_CoPTSt_bMonRunSftyORngAMT(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bMonRunSftyORngAT
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bMonRunSftyORngAT(value)
#define vidGET_VALUE_CoPTSt_bMonRunSftyORngAT(variable)                          Rte_Read_R_CoPTSt_bMonRunSftyORngAT_CoPTSt_bMonRunSftyORngAT(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_bRStrtSTT
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_bRStrtSTT(value)                                     Rte_Write_P_CoPTSt_bRStrtSTT_CoPTSt_bRStrtSTT(value)
#define vidGET_VALUE_CoPTSt_bRStrtSTT(variable)                                  Rte_Read_R_CoPTSt_bRStrtSTT_CoPTSt_bRStrtSTT(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_stDrvTra
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_stDrvTra(value)
#define vidGET_VALUE_CoPTSt_stDrvTra(variable)                                   Rte_Read_R_CoPTSt_stDrvTra_CoPTSt_stDrvTra(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_stEng
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_stEng(value)
#define vidGET_VALUE_CoPTSt_stEng(variable)                                      Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&variable)

/**********************************************************************************
   Create interface for variable CoPTSt_tCoMesRStrtSTT
  **********************************************************************************/

#define vidSET_VALUE_CoPTSt_tCoMesRStrtSTT(value)                                Rte_Write_P_CoPTSt_tCoMesRStrtSTT_CoPTSt_tCoMesRStrtSTT(value)
#define vidGET_VALUE_CoPTSt_tCoMesRStrtSTT(variable)                             Rte_Read_R_CoPTSt_tCoMesRStrtSTT_CoPTSt_tCoMesRStrtSTT(&variable)

/**********************************************************************************
   Create interface for variable CoPtASE_bRstrtReqAvl
  **********************************************************************************/

#define vidSET_VALUE_CoPtASE_bRstrtReqAvl(value)
#define vidGET_VALUE_CoPtASE_bRstrtReqAvl(variable)                              Rte_Read_R_CoPtASE_bRstrtReqAvl_CoPtASE_bRstrtReqAvl(&variable)

/**********************************************************************************
   Create interface for variable CoPtFH_bEngCutOffReq
  **********************************************************************************/

#define vidSET_VALUE_CoPtFH_bEngCutOffReq(value)                                 Rte_Write_P_CoPtFH_bEngCutOffReq_CoPtFH_bEngCutOffReq(value)
#define vidGET_VALUE_CoPtFH_bEngCutOffReq(variable)                              Rte_Read_R_CoPtFH_bEngCutOffReq_CoPtFH_bEngCutOffReq(&variable)

/**********************************************************************************
   Create interface for variable CoPtFH_stPwt
  **********************************************************************************/

#define vidSET_VALUE_CoPtFH_stPwt(value)
#define vidGET_VALUE_CoPtFH_stPwt(variable)                                      Rte_Read_R_CoPtFH_stPwt_CoPtFH_stPwt(&variable)

/**********************************************************************************
   Create interface for variable CoPtSynt_bStopIp
  **********************************************************************************/

#define vidSET_VALUE_CoPtSynt_bStopIp(value)
#define vidGET_VALUE_CoPtSynt_bStopIp(variable)                                  Rte_Read_R_CoPtSynt_bStopIp_CoPtSynt_bStopIp(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bAcvGSINeut
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bAcvGSINeut(value)
#define vidGET_VALUE_CoPtUH_bAcvGSINeut(variable)                                Rte_Read_R_CoPtUH_bAcvGSINeut_CoPtUH_bAcvGSINeut(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bAltInh
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bAltInh(value)
#define vidGET_VALUE_CoPtUH_bAltInh(variable)                                    Rte_Read_R_CoPtUH_bAltInh_CoPtUH_bAltInh(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bAltRPosnEngReq
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bAltRPosnEngReq(value)
#define vidGET_VALUE_CoPtUH_bAltRPosnEngReq(variable)                            Rte_Read_R_CoPtUH_bAltRPosnEngReq_CoPtUH_bAltRPosnEngReq(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bAltStallReq
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bAltStallReq(value)
#define vidGET_VALUE_CoPtUH_bAltStallReq(variable)                               Rte_Read_R_CoPtUH_bAltStallReq_CoPtUH_bAltStallReq(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bBltStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bBltStopAuth(value)
#define vidGET_VALUE_CoPtUH_bBltStopAuth(variable)                               Rte_Read_R_CoPtUH_bBltStopAuth_CoPtUH_bBltStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCompTqRStrt
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCompTqRStrt(value)
#define vidGET_VALUE_CoPtUH_bCompTqRStrt(variable)                               Rte_Read_R_CoPtUH_bCompTqRStrt_CoPtUH_bCompTqRStrt(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCtlDmprAuth
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCtlDmprAuth(value)
#define vidGET_VALUE_CoPtUH_bCtlDmprAuth(variable)                               Rte_Read_R_CoPtUH_bCtlDmprAuth_CoPtUH_bCtlDmprAuth(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseAutRStrt
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseAutRStrt(value)
#define vidGET_VALUE_CoPtUH_bCutCaseAutRStrt(variable)                           Rte_Read_R_CoPtUH_bCutCaseAutRStrt_CoPtUH_bCutCaseAutRStrt(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseClsTra
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseClsTra(value)
#define vidGET_VALUE_CoPtUH_bCutCaseClsTra(variable)                             Rte_Read_R_CoPtUH_bCutCaseClsTra_CoPtUH_bCutCaseClsTra(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseDgoBlt
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseDgoBlt(value)
#define vidGET_VALUE_CoPtUH_bCutCaseDgoBlt(variable)                             Rte_Read_R_CoPtUH_bCutCaseDgoBlt_CoPtUH_bCutCaseDgoBlt(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseElMecRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseElMecRStrtReq(value)
#define vidGET_VALUE_CoPtUH_bCutCaseElMecRStrtReq(variable)                      Rte_Read_R_CoPtUH_bCutCaseElMecRStrtReq_CoPtUH_bCutCaseElMecRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseLongGc
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseLongGc(value)
#define vidGET_VALUE_CoPtUH_bCutCaseLongGc(variable)                             Rte_Read_R_CoPtUH_bCutCaseLongGc_CoPtUH_bCutCaseLongGc(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseNotRStrtAuth
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseNotRStrtAuth(value)
#define vidGET_VALUE_CoPtUH_bCutCaseNotRStrtAuth(variable)                       Rte_Read_R_CoPtUH_bCutCaseNotRStrtAuth_CoPtUH_bCutCaseNotRStrtAuth(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseRCfTyp3
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseRCfTyp3(value)
#define vidGET_VALUE_CoPtUH_bCutCaseRCfTyp3(variable)                            Rte_Read_R_CoPtUH_bCutCaseRCfTyp3_CoPtUH_bCutCaseRCfTyp3(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseRStrtReqForc
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseRStrtReqForc(value)
#define vidGET_VALUE_CoPtUH_bCutCaseRStrtReqForc(variable)                       Rte_Read_R_CoPtUH_bCutCaseRStrtReqForc_CoPtUH_bCutCaseRStrtReqForc(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseSpdMax
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseSpdMax(value)
#define vidGET_VALUE_CoPtUH_bCutCaseSpdMax(variable)                             Rte_Read_R_CoPtUH_bCutCaseSpdMax_CoPtUH_bCutCaseSpdMax(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bCutCaseVehRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bCutCaseVehRStrtReq(value)
#define vidGET_VALUE_CoPtUH_bCutCaseVehRStrtReq(variable)                        Rte_Read_R_CoPtUH_bCutCaseVehRStrtReq_CoPtUH_bCutCaseVehRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bDrvTraOp
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bDrvTraOp(value)
#define vidGET_VALUE_CoPtUH_bDrvTraOp(variable)                                  Rte_Read_R_CoPtUH_bDrvTraOp_CoPtUH_bDrvTraOp(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bEngStallReq
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bEngStallReq(value)
#define vidGET_VALUE_CoPtUH_bEngStallReq(variable)                               Rte_Read_R_CoPtUH_bEngStallReq_CoPtUH_bEngStallReq(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bFbSpcFactSTTReq1
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bFbSpcFactSTTReq1(value)
#define vidGET_VALUE_CoPtUH_bFbSpcFactSTTReq1(variable)                          Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bFbSpcFactSTTReq2
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bFbSpcFactSTTReq2(value)
#define vidGET_VALUE_CoPtUH_bFbSpcFactSTTReq2(variable)                          Rte_Read_R_CoPtUH_bFbSpcFactSTTReq2_CoPtUH_bFbSpcFactSTTReq2(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bInfoAcvCluPed
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bInfoAcvCluPed(value)
#define vidGET_VALUE_CoPtUH_bInfoAcvCluPed(variable)                             Rte_Read_R_CoPtUH_bInfoAcvCluPed_CoPtUH_bInfoAcvCluPed(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bInfoRdy
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bInfoRdy(value)
#define vidGET_VALUE_CoPtUH_bInfoRdy(variable)                                   Rte_Read_R_CoPtUH_bInfoRdy_CoPtUH_bInfoRdy(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bLatchDrvCyc
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bLatchDrvCyc(value)
#define vidGET_VALUE_CoPtUH_bLatchDrvCyc(variable)                               Rte_Read_R_CoPtUH_bLatchDrvCyc_CoPtUH_bLatchDrvCyc(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bOpDrvTraReq
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bOpDrvTraReq(value)
#define vidGET_VALUE_CoPtUH_bOpDrvTraReq(variable)                               Rte_Read_R_CoPtUH_bOpDrvTraReq_CoPtUH_bOpDrvTraReq(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bRStrtAnt
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bRStrtAnt(value)
#define vidGET_VALUE_CoPtUH_bRStrtAnt(variable)                                  Rte_Read_R_CoPtUH_bRStrtAnt_CoPtUH_bRStrtAnt(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bRStrtTypAT
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bRStrtTypAT(value)
#define vidGET_VALUE_CoPtUH_bRStrtTypAT(variable)                                Rte_Read_R_CoPtUH_bRStrtTypAT_CoPtUH_bRStrtTypAT(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bRecNotStop
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bRecNotStop(value)
#define vidGET_VALUE_CoPtUH_bRecNotStop(variable)                                Rte_Read_R_CoPtUH_bRecNotStop_CoPtUH_bRecNotStop(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bRstrtCritAuth
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bRstrtCritAuth(value)
#define vidGET_VALUE_CoPtUH_bRstrtCritAuth(variable)                             Rte_Read_R_CoPtUH_bRstrtCritAuth_CoPtUH_bRstrtCritAuth(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bSTTInh
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bSTTInh(value)
#define vidGET_VALUE_CoPtUH_bSTTInh(variable)                                    Rte_Read_R_CoPtUH_bSTTInh_CoPtUH_bSTTInh(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bStPresLo
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bStPresLo(value)
#define vidGET_VALUE_CoPtUH_bStPresLo(variable)                                  Rte_Read_R_CoPtUH_bStPresLo_CoPtUH_bStPresLo(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_bStopAuthSlop
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_bStopAuthSlop(value)
#define vidGET_VALUE_CoPtUH_bStopAuthSlop(variable)                              Rte_Read_R_CoPtUH_bStopAuthSlop_CoPtUH_bStopAuthSlop(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_nEngClc
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_nEngClc(value)
#define vidGET_VALUE_CoPtUH_nEngClc(variable)                                    Rte_Read_R_CoPtUH_nEngClc_CoPtUH_nEngClc(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_noGearTmpBeg
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_noGearTmpBeg(value)
#define vidGET_VALUE_CoPtUH_noGearTmpBeg(variable)                               Rte_Read_R_CoPtUH_noGearTmpBeg_CoPtUH_noGearTmpBeg(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_noGearTmpEnd
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_noGearTmpEnd(value)
#define vidGET_VALUE_CoPtUH_noGearTmpEnd(variable)                               Rte_Read_R_CoPtUH_noGearTmpEnd_CoPtUH_noGearTmpEnd(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_pRelBrkAsi
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_pRelBrkAsi(value)
#define vidGET_VALUE_CoPtUH_pRelBrkAsi(variable)                                 Rte_Read_R_CoPtUH_pRelBrkAsi_CoPtUH_pRelBrkAsi(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_rMaxCluGc
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_rMaxCluGc(value)
#define vidGET_VALUE_CoPtUH_rMaxCluGc(variable)                                  Rte_Read_R_CoPtUH_rMaxCluGc_CoPtUH_rMaxCluGc(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_rMinCluRStrt
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_rMinCluRStrt(value)
#define vidGET_VALUE_CoPtUH_rMinCluRStrt(variable)                               Rte_Read_R_CoPtUH_rMinCluRStrt_CoPtUH_rMinCluRStrt(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stAftsRStrtSuc
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stAftsRStrtSuc(value)
#define vidGET_VALUE_CoPtUH_stAftsRStrtSuc(variable)                             Rte_Read_R_CoPtUH_stAftsRStrtSuc_CoPtUH_stAftsRStrtSuc(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stBfBfLstRStrtFail
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stBfBfLstRStrtFail(value)
#define vidGET_VALUE_CoPtUH_stBfBfLstRStrtFail(variable)                         Rte_Read_R_CoPtUH_stBfBfLstRStrtFail_CoPtUH_stBfBfLstRStrtFail(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stBfLstRStrtFailCase
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stBfLstRStrtFailCase(value)
#define vidGET_VALUE_CoPtUH_stBfLstRStrtFailCase(variable)                       Rte_Read_R_CoPtUH_stBfLstRStrtFailCase_CoPtUH_stBfLstRStrtFailCase(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stFbSpcFactRStrtSuc
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stFbSpcFactRStrtSuc(value)
#define vidGET_VALUE_CoPtUH_stFbSpcFactRStrtSuc(variable)                        Rte_Read_R_CoPtUH_stFbSpcFactRStrtSuc_CoPtUH_stFbSpcFactRStrtSuc(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stLstRStrtFailCase
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stLstRStrtFailCase(value)
#define vidGET_VALUE_CoPtUH_stLstRStrtFailCase(variable)                         Rte_Read_R_CoPtUH_stLstRStrtFailCase_CoPtUH_stLstRStrtFailCase(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stPwt
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stPwt(value)
#define vidGET_VALUE_CoPtUH_stPwt(variable)                                      Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stSTTLightAcv
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stSTTLightAcv(value)
#define vidGET_VALUE_CoPtUH_stSTTLightAcv(variable)                              Rte_Read_R_CoPtUH_stSTTLightAcv_CoPtUH_stSTTLightAcv(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_stTestPosClu
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_stTestPosClu(value)
#define vidGET_VALUE_CoPtUH_stTestPosClu(variable)                               Rte_Read_R_CoPtUH_stTestPosClu_CoPtUH_stTestPosClu(&variable)

/**********************************************************************************
   Create interface for variable CoPtUH_tiNbRstrtFreqLim
  **********************************************************************************/

#define vidSET_VALUE_CoPtUH_tiNbRstrtFreqLim(value)
#define vidGET_VALUE_CoPtUH_tiNbRstrtFreqLim(variable)                           Rte_Read_R_CoPtUH_tiNbRstrtFreqLim_CoPtUH_tiNbRstrtFreqLim(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvAntiStallFil
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvAntiStallFil(value)
#define vidGET_VALUE_CoPt_bAcvAntiStallFil(variable)                             Rte_Read_R_CoPt_bAcvAntiStallFil_CoPt_bAcvAntiStallFil(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvCycMod
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvCycMod(value)
#define vidGET_VALUE_CoPt_bAcvCycMod(variable)                                   Rte_Read_R_CoPt_bAcvCycMod_CoPt_bAcvCycMod(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvDynTqResCrawl
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvDynTqResCrawl(value)
#define vidGET_VALUE_CoPt_bAcvDynTqResCrawl(variable)                            Rte_Read_R_CoPt_bAcvDynTqResCrawl_CoPt_bAcvDynTqResCrawl(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvIdlCrawl
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvIdlCrawl(value)
#define vidGET_VALUE_CoPt_bAcvIdlCrawl(variable)                                 Rte_Read_R_CoPt_bAcvIdlCrawl_CoPt_bAcvIdlCrawl(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvNCross
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvNCross(value)
#define vidGET_VALUE_CoPt_bAcvNCross(variable)                                   Rte_Read_R_CoPt_bAcvNCross_CoPt_bAcvNCross(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvNRegReq
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvNRegReq(value)
#define vidGET_VALUE_CoPt_bAcvNRegReq(variable)                                  Rte_Read_R_CoPt_bAcvNRegReq_CoPt_bAcvNRegReq(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvProtCluP
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvProtCluP(value)                                    Rte_Write_P_CoPt_bAcvProtCluP_CoPt_bAcvProtCluP(value)
#define vidGET_VALUE_CoPt_bAcvProtCluP(variable)                                 Rte_Read_R_CoPt_bAcvProtCluP_CoPt_bAcvProtCluP(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvSptTakeOff
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvSptTakeOff(value)
#define vidGET_VALUE_CoPt_bAcvSptTakeOff(variable)                               Rte_Read_R_CoPt_bAcvSptTakeOff_CoPt_bAcvSptTakeOff(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvStatTqResCrawl
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvStatTqResCrawl(value)
#define vidGET_VALUE_CoPt_bAcvStatTqResCrawl(variable)                           Rte_Read_R_CoPt_bAcvStatTqResCrawl_CoPt_bAcvStatTqResCrawl(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvTqMaxEstim
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvTqMaxEstim(value)                                  Rte_Write_P_CoPt_bAcvTqMaxEstim_CoPt_bAcvTqMaxEstim(value)
#define vidGET_VALUE_CoPt_bAcvTqMaxEstim(variable)                               Rte_Read_R_CoPt_bAcvTqMaxEstim_CoPt_bAcvTqMaxEstim(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvTqNCord
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvTqNCord(value)
#define vidGET_VALUE_CoPt_bAcvTqNCord(variable)                                  Rte_Read_R_CoPt_bAcvTqNCord_CoPt_bAcvTqNCord(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAcvWupMod
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAcvWupMod(value)
#define vidGET_VALUE_CoPt_bAcvWupMod(variable)                                   Rte_Read_R_CoPt_bAcvWupMod_CoPt_bAcvWupMod(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bAuthCrawl
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bAuthCrawl(value)
#define vidGET_VALUE_CoPt_bAuthCrawl(variable)                                   Rte_Read_R_CoPt_bAuthCrawl_CoPt_bAuthCrawl(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bDeacCll
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bDeacCll(value)
#define vidGET_VALUE_CoPt_bDeacCll(variable)                                     Rte_Read_R_CoPt_bDeacCll_CoPt_bDeacCll(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bDiagSIPORng
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bDiagSIPORng(value)
#define vidGET_VALUE_CoPt_bDiagSIPORng(variable)                                 Rte_Read_R_CoPt_bDiagSIPORng_CoPt_bDiagSIPORng(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bEngCrawlAuth
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bEngCrawlAuth(value)
#define vidGET_VALUE_CoPt_bEngCrawlAuth(variable)                                Rte_Read_R_CoPt_bEngCrawlAuth_CoPt_bEngCrawlAuth(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bFrzEGR
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bFrzEGR(value)
#define vidGET_VALUE_CoPt_bFrzEGR(variable)                                      Rte_Read_R_CoPt_bFrzEGR_CoPt_bFrzEGR(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bFrzTrbSt
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bFrzTrbSt(value)
#define vidGET_VALUE_CoPt_bFrzTrbSt(variable)                                    Rte_Read_R_CoPt_bFrzTrbSt_CoPt_bFrzTrbSt(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bInhAC
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bInhAC(value)
#define vidGET_VALUE_CoPt_bInhAC(variable)                                       Rte_Read_R_CoPt_bInhAC_CoPt_bInhAC(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bPrepSIP
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bPrepSIP(value)
#define vidGET_VALUE_CoPt_bPrepSIP(variable)                                     Rte_Read_R_CoPt_bPrepSIP_CoPt_bPrepSIP(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bRvsCord
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bRvsCord(value)
#define vidGET_VALUE_CoPt_bRvsCord(variable)                                     Rte_Read_R_CoPt_bRvsCord_CoPt_bRvsCord(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bSIP
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bSIP(value)
#define vidGET_VALUE_CoPt_bSIP(variable)                                         Rte_Read_R_CoPt_bSIP_CoPt_bSIP(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bSIPBuf
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bSIPBuf(value)
#define vidGET_VALUE_CoPt_bSIPBuf(variable)                                      Rte_Read_R_CoPt_bSIPBuf_CoPt_bSIPBuf(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bSIPCord
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bSIPCord(value)
#define vidGET_VALUE_CoPt_bSIPCord(variable)                                     Rte_Read_R_CoPt_bSIPCord_CoPt_bSIPCord(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bSIPcordAirSys
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bSIPcordAirSys(value)
#define vidGET_VALUE_CoPt_bSIPcordAirSys(variable)                               Rte_Read_R_CoPt_bSIPcordAirSys_CoPt_bSIPcordAirSys(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bSmkFil
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bSmkFil(value)
#define vidGET_VALUE_CoPt_bSmkFil(variable)                                      Rte_Read_R_CoPt_bSmkFil_CoPt_bSmkFil(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bSpdVehLoDet
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bSpdVehLoDet(value)
#define vidGET_VALUE_CoPt_bSpdVehLoDet(variable)                                 Rte_Read_R_CoPt_bSpdVehLoDet_CoPt_bSpdVehLoDet(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bTakeOff
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bTakeOff(value)
#define vidGET_VALUE_CoPt_bTakeOff(variable)                                     Rte_Read_R_CoPt_bTakeOff_CoPt_bTakeOff(&variable)

/**********************************************************************************
   Create interface for variable CoPt_bTqTx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_bTqTx(value)
#define vidGET_VALUE_CoPt_bTqTx(variable)                                        Rte_Read_R_CoPt_bTqTx_CoPt_bTqTx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_idxPrfGBxMsg
  **********************************************************************************/

#define vidSET_VALUE_CoPt_idxPrfGBxMsg(value)
#define vidGET_VALUE_CoPt_idxPrfGBxMsg(variable)                                 Rte_Read_R_CoPt_idxPrfGBxMsg_CoPt_idxPrfGBxMsg(&variable)

/**********************************************************************************
   Create interface for variable CoPt_nMinTqMaxGBxMsg
  **********************************************************************************/

#define vidSET_VALUE_CoPt_nMinTqMaxGBxMsg(value)
#define vidGET_VALUE_CoPt_nMinTqMaxGBxMsg(variable)                              Rte_Read_R_CoPt_nMinTqMaxGBxMsg_CoPt_nMinTqMaxGBxMsg(&variable)

/**********************************************************************************
   Create interface for variable CoPt_noEgdGear
  **********************************************************************************/

#define vidSET_VALUE_CoPt_noEgdGear(value)
#define vidGET_VALUE_CoPt_noEgdGear(variable)                                    Rte_Read_R_CoPt_noEgdGear_CoPt_noEgdGear(&variable)

/**********************************************************************************
   Create interface for variable CoPt_noEgdGearCord
  **********************************************************************************/

#define vidSET_VALUE_CoPt_noEgdGearCord(value)
#define vidGET_VALUE_CoPt_noEgdGearCord(variable)                                Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&variable)

/**********************************************************************************
   Create interface for variable CoPt_noEgdGearCordExtd
  **********************************************************************************/

#define vidSET_VALUE_CoPt_noEgdGearCordExtd(value)
#define vidGET_VALUE_CoPt_noEgdGearCordExtd(variable)                            Rte_Read_R_CoPt_noEgdGearCordExtd_CoPt_noEgdGearCordExtd(&variable)

/**********************************************************************************
   Create interface for variable CoPt_noEgdGearCordIt
  **********************************************************************************/

#define vidSET_VALUE_CoPt_noEgdGearCordIt(value)
#define vidGET_VALUE_CoPt_noEgdGearCordIt(variable)                              Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&variable)

/**********************************************************************************
   Create interface for variable CoPt_noGearCord
  **********************************************************************************/

#define vidSET_VALUE_CoPt_noGearCord(value)
#define vidGET_VALUE_CoPt_noGearCord(variable)                                   Rte_Read_R_CoPt_noGearCord_CoPt_noGearCord(&variable)

/**********************************************************************************
   Create interface for variable CoPt_noGearCordDrivFil
  **********************************************************************************/

#define vidSET_VALUE_CoPt_noGearCordDrivFil(value)
#define vidGET_VALUE_CoPt_noGearCordDrivFil(variable)                            Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&variable)

/**********************************************************************************
   Create interface for variable CoPt_noTarGearCord
  **********************************************************************************/

#define vidSET_VALUE_CoPt_noTarGearCord(value)
#define vidGET_VALUE_CoPt_noTarGearCord(variable)                                Rte_Read_R_CoPt_noTarGearCord_CoPt_noTarGearCord(&variable)

/**********************************************************************************
   Create interface for variable CoPt_rCnvTq
  **********************************************************************************/

#define vidSET_VALUE_CoPt_rCnvTq(value)
#define vidGET_VALUE_CoPt_rCnvTq(variable)                                       Rte_Read_R_CoPt_rCnvTq_CoPt_rCnvTq(&variable)

/**********************************************************************************
   Create interface for variable CoPt_rSpdFanReqProtManClu
  **********************************************************************************/

#define vidSET_VALUE_CoPt_rSpdFanReqProtManClu(value)                            Rte_Write_P_CoPt_rSpdFanReqProtManClu_CoPt_rSpdFanReqProtManClu(value)
#define vidGET_VALUE_CoPt_rSpdFanReqProtManClu(variable)                         Rte_Read_R_CoPt_rSpdFanReqProtManClu_CoPt_rSpdFanReqProtManClu(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stCnvCluFil
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stCnvCluFil(value)
#define vidGET_VALUE_CoPt_stCnvCluFil(variable)                                  Rte_Read_R_CoPt_stCnvCluFil_CoPt_stCnvCluFil(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stCpl
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stCpl(value)
#define vidGET_VALUE_CoPt_stCpl(variable)                                        Rte_Read_R_CoPt_stCpl_CoPt_stCpl(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stCrawl
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stCrawl(value)
#define vidGET_VALUE_CoPt_stCrawl(variable)                                      Rte_Read_R_CoPt_stCrawl_CoPt_stCrawl(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stDragRed
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stDragRed(value)
#define vidGET_VALUE_CoPt_stDragRed(variable)                                    Rte_Read_R_CoPt_stDragRed_CoPt_stDragRed(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stDrvTra
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stDrvTra(value)
#define vidGET_VALUE_CoPt_stDrvTra(variable)                                     Rte_Read_R_CoPt_stDrvTra_CoPt_stDrvTra(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stGBxMod
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stGBxMod(value)
#define vidGET_VALUE_CoPt_stGBxMod(variable)                                     Rte_Read_R_CoPt_stGBxMod_CoPt_stGBxMod(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stGSTyp
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stGSTyp(value)
#define vidGET_VALUE_CoPt_stGSTyp(variable)                                      Rte_Read_R_CoPt_stGSTyp_CoPt_stGSTyp(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stGearRat
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stGearRat(value)
#define vidGET_VALUE_CoPt_stGearRat(variable)                                    Rte_Read_R_CoPt_stGearRat_CoPt_stGearRat(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stProt
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stProt(value)                                          Rte_Write_P_CoPt_stProt_CoPt_stProt(value)
#define vidGET_VALUE_CoPt_stProt(variable)                                       Rte_Read_R_CoPt_stProt_CoPt_stProt(&variable)

/**********************************************************************************
   Create interface for variable CoPt_stVehDirEstim
  **********************************************************************************/

#define vidSET_VALUE_CoPt_stVehDirEstim(value)
#define vidGET_VALUE_CoPt_stVehDirEstim(variable)                                Rte_Read_R_CoPt_stVehDirEstim_CoPt_stVehDirEstim(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tOilGBx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tOilGBx(value)
#define vidGET_VALUE_CoPt_tOilGBx(variable)                                      Rte_Read_R_CoPt_tOilGBx_CoPt_tOilGBx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqAirDrvFil
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqAirDrvFil(value)
#define vidGET_VALUE_CoPt_tqAirDrvFil(variable)                                  Rte_Read_R_CoPt_tqAirDrvFil_CoPt_tqAirDrvFil(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqAirMaxGBx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqAirMaxGBx(value)
#define vidGET_VALUE_CoPt_tqAirMaxGBx(variable)                                  Rte_Read_R_CoPt_tqAirMaxGBx_CoPt_tqAirMaxGBx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqDrvFil
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqDrvFil(value)
#define vidGET_VALUE_CoPt_tqDrvFil(variable)                                     Rte_Read_R_CoPt_tqDrvFil_CoPt_tqDrvFil(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqDrvRaw
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqDrvRaw(value)
#define vidGET_VALUE_CoPt_tqDrvRaw(variable)                                     Rte_Read_R_CoPt_tqDrvRaw_CoPt_tqDrvRaw(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqDrvRawTarGear
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqDrvRawTarGear(value)
#define vidGET_VALUE_CoPt_tqDrvRawTarGear(variable)                              Rte_Read_R_CoPt_tqDrvRawTarGear_CoPt_tqDrvRawTarGear(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqEfcAirCordLimIt_tqGBx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqEfcAirCordLimIt_tqGBx(value)
#define vidGET_VALUE_CoPt_tqEfcAirCordLimIt_tqGBx(variable)                      Rte_Read_R_CoPt_tqEfcAirCordLimIt_tqGBx_CoPt_tqEfcAirCordLimIt_tqGBx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqEfcAirCordLim_tqGBx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqEfcAirCordLim_tqGBx(value)
#define vidGET_VALUE_CoPt_tqEfcAirCordLim_tqGBx(variable)                        Rte_Read_R_CoPt_tqEfcAirCordLim_tqGBx_CoPt_tqEfcAirCordLim_tqGBx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqEfcCordLimIt_tqGBx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqEfcCordLimIt_tqGBx(value)
#define vidGET_VALUE_CoPt_tqEfcCordLimIt_tqGBx(variable)                         Rte_Read_R_CoPt_tqEfcCordLimIt_tqGBx_CoPt_tqEfcCordLimIt_tqGBx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqEfcCordLim_tqGBx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqEfcCordLim_tqGBx(value)
#define vidGET_VALUE_CoPt_tqEfcCordLim_tqGBx(variable)                           Rte_Read_R_CoPt_tqEfcCordLim_tqGBx_CoPt_tqEfcCordLim_tqGBx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqEfcMaxProtDftl
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqEfcMaxProtDftl(value)                                Rte_Write_P_CoPt_tqEfcMaxProtDftl_CoPt_tqEfcMaxProtDftl(value)
#define vidGET_VALUE_CoPt_tqEfcMaxProtDftl(variable)                             Rte_Read_R_CoPt_tqEfcMaxProtDftl_CoPt_tqEfcMaxProtDftl(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqEfcReqCord_nRegReq
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqEfcReqCord_nRegReq(value)
#define vidGET_VALUE_CoPt_tqEfcReqCord_nRegReq(variable)                         Rte_Read_R_CoPt_tqEfcReqCord_nRegReq_CoPt_tqEfcReqCord_nRegReq(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqFfNReg
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqFfNReg(value)
#define vidGET_VALUE_CoPt_tqFfNReg(variable)                                     Rte_Read_R_CoPt_tqFfNReg_CoPt_tqFfNReg(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqIdcAirCord_nCross
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqIdcAirCord_nCross(value)
#define vidGET_VALUE_CoPt_tqIdcAirCord_nCross(variable)                          Rte_Read_R_CoPt_tqIdcAirCord_nCross_CoPt_tqIdcAirCord_nCross(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqIdcAirGslCord_nReg
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqIdcAirGslCord_nReg(value)
#define vidGET_VALUE_CoPt_tqIdcAirGslCord_nReg(variable)                         Rte_Read_R_CoPt_tqIdcAirGslCord_nReg_CoPt_tqIdcAirGslCord_nReg(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqIdcCord_nRegReq
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqIdcCord_nRegReq(value)
#define vidGET_VALUE_CoPt_tqIdcCord_nRegReq(variable)                            Rte_Read_R_CoPt_tqIdcCord_nRegReq_CoPt_tqIdcCord_nRegReq(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqIdcMaxGBx
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqIdcMaxGBx(value)
#define vidGET_VALUE_CoPt_tqIdcMaxGBx(variable)                                  Rte_Read_R_CoPt_tqIdcMaxGBx_CoPt_tqIdcMaxGBx(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqIdcReqCord_nRegReq
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqIdcReqCord_nRegReq(value)
#define vidGET_VALUE_CoPt_tqIdcReqCord_nRegReq(variable)                         Rte_Read_R_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqMaxClu
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqMaxClu(value)
#define vidGET_VALUE_CoPt_tqMaxClu(variable)                                     Rte_Read_R_CoPt_tqMaxClu_CoPt_tqMaxClu(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqMaxGBxAir
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqMaxGBxAir(value)
#define vidGET_VALUE_CoPt_tqMaxGBxAir(variable)                                  Rte_Read_R_CoPt_tqMaxGBxAir_CoPt_tqMaxGBxAir(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqMinGBxMsg
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqMinGBxMsg(value)
#define vidGET_VALUE_CoPt_tqMinGBxMsg(variable)                                  Rte_Read_R_CoPt_tqMinGBxMsg_CoPt_tqMinGBxMsg(&variable)

/**********************************************************************************
   Create interface for variable CoPt_tqReqClu
  **********************************************************************************/

#define vidSET_VALUE_CoPt_tqReqClu(value)
#define vidGET_VALUE_CoPt_tqReqClu(variable)                                     Rte_Read_R_CoPt_tqReqClu_CoPt_tqReqClu(&variable)

/**********************************************************************************
   Create interface for variable CoReqAMT_bEngRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoReqAMT_bEngRStrtReq(value)                                Rte_Write_P_CoReqAMT_bEngRStrtReq_CoReqAMT_bEngRStrtReq(value)
#define vidGET_VALUE_CoReqAMT_bEngRStrtReq(variable)                             Rte_Read_R_CoReqAMT_bEngRStrtReq_CoReqAMT_bEngRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoReqAMT_stEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoReqAMT_stEngStopAuth(value)                               Rte_Write_P_CoReqAMT_stEngStopAuth_CoReqAMT_stEngStopAuth(value)
#define vidGET_VALUE_CoReqAMT_stEngStopAuth(variable)                            Rte_Read_R_CoReqAMT_stEngStopAuth_CoReqAMT_stEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoReqCha_bEngRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoReqCha_bEngRStrtReq(value)                                Rte_Write_P_CoReqCha_bEngRStrtReq_CoReqCha_bEngRStrtReq(value)
#define vidGET_VALUE_CoReqCha_bEngRStrtReq(variable)                             Rte_Read_R_CoReqCha_bEngRStrtReq_CoReqCha_bEngRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoReqCha_bHillAsiRdyEngStop
  **********************************************************************************/

#define vidSET_VALUE_CoReqCha_bHillAsiRdyEngStop(value)                          Rte_Write_P_CoReqCha_bHillAsiRdyEngStop_CoReqCha_bHillAsiRdyEngStop(value)
#define vidGET_VALUE_CoReqCha_bHillAsiRdyEngStop(variable)                       Rte_Read_R_CoReqCha_bHillAsiRdyEngStop_CoReqCha_bHillAsiRdyEngStop(&variable)

/**********************************************************************************
   Create interface for variable CoReqCha_bUncrtSlopStab
  **********************************************************************************/

#define vidSET_VALUE_CoReqCha_bUncrtSlopStab(value)                              Rte_Write_P_CoReqCha_bUncrtSlopStab_CoReqCha_bUncrtSlopStab(value)
#define vidGET_VALUE_CoReqCha_bUncrtSlopStab(variable)                           Rte_Read_R_CoReqCha_bUncrtSlopStab_CoReqCha_bUncrtSlopStab(&variable)

/**********************************************************************************
   Create interface for variable CoReqCha_rSlopStab
  **********************************************************************************/

#define vidSET_VALUE_CoReqCha_rSlopStab(value)                                   Rte_Write_P_CoReqCha_rSlopStab_CoReqCha_rSlopStab(value)
#define vidGET_VALUE_CoReqCha_rSlopStab(variable)                                Rte_Read_R_CoReqCha_rSlopStab_CoReqCha_rSlopStab(&variable)

/**********************************************************************************
   Create interface for variable CoReqCha_stEngRStrtInh
  **********************************************************************************/

#define vidSET_VALUE_CoReqCha_stEngRStrtInh(value)                               Rte_Write_P_CoReqCha_stEngRStrtInh_CoReqCha_stEngRStrtInh(value)
#define vidGET_VALUE_CoReqCha_stEngRStrtInh(variable)                            Rte_Read_R_CoReqCha_stEngRStrtInh_CoReqCha_stEngRStrtInh(&variable)

/**********************************************************************************
   Create interface for variable CoReqCha_stEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoReqCha_stEngStopAuth(value)                               Rte_Write_P_CoReqCha_stEngStopAuth_CoReqCha_stEngStopAuth(value)
#define vidGET_VALUE_CoReqCha_stEngStopAuth(variable)                            Rte_Read_R_CoReqCha_stEngStopAuth_CoReqCha_stEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoReqRStrt_bAuthSA
  **********************************************************************************/

#define vidSET_VALUE_CoReqRStrt_bAuthSA(value)
#define vidGET_VALUE_CoReqRStrt_bAuthSA(variable)                                Rte_Read_R_CoReqRStrt_bAuthSA_CoReqRStrt_bAuthSA(&variable)

/**********************************************************************************
   Create interface for variable CoReqRStrt_bEngRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoReqRStrt_bEngRStrtReq(value)
#define vidGET_VALUE_CoReqRStrt_bEngRStrtReq(variable)                           Rte_Read_R_CoReqRStrt_bEngRStrtReq_CoReqRStrt_bEngRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoReqRStrt_bEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoReqRStrt_bEngStopAuth(value)
#define vidGET_VALUE_CoReqRStrt_bEngStopAuth(variable)                           Rte_Read_R_CoReqRStrt_bEngStopAuth_CoReqRStrt_bEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoReqRStrt_bNotBlsVehReq
  **********************************************************************************/

#define vidSET_VALUE_CoReqRStrt_bNotBlsVehReq(value)
#define vidGET_VALUE_CoReqRStrt_bNotBlsVehReq(variable)                          Rte_Read_R_CoReqRStrt_bNotBlsVehReq_CoReqRStrt_bNotBlsVehReq(&variable)

/**********************************************************************************
   Create interface for variable CoReqRStrt_bRstrtAuth
  **********************************************************************************/

#define vidSET_VALUE_CoReqRStrt_bRstrtAuth(value)
#define vidGET_VALUE_CoReqRStrt_bRstrtAuth(variable)                             Rte_Read_R_CoReqRStrt_bRstrtAuth_CoReqRStrt_bRstrtAuth(&variable)

/**********************************************************************************
   Create interface for variable CoReqStg_bEngRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoReqStg_bEngRStrtReq(value)                                Rte_Write_P_CoReqStg_bEngRStrtReq_CoReqStg_bEngRStrtReq(value)
#define vidGET_VALUE_CoReqStg_bEngRStrtReq(variable)                             Rte_Read_R_CoReqStg_bEngRStrtReq_CoReqStg_bEngRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoReqStg_stEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoReqStg_stEngStopAuth(value)                               Rte_Write_P_CoReqStg_stEngStopAuth_CoReqStg_stEngStopAuth(value)
#define vidGET_VALUE_CoReqStg_stEngStopAuth(variable)                            Rte_Read_R_CoReqStg_stEngStopAuth_CoReqStg_stEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoReqVeh_bEngStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoReqVeh_bEngStrtReq(value)                                 Rte_Write_P_CoReqVeh_bEngStrtReq_CoReqVeh_bEngStrtReq(value)
#define vidGET_VALUE_CoReqVeh_bEngStrtReq(variable)                              Rte_Read_R_CoReqVeh_bEngStrtReq_CoReqVeh_bEngStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoReqVeh_stEngRStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoReqVeh_stEngRStrtReq(value)                               Rte_Write_P_CoReqVeh_stEngRStrtReq_CoReqVeh_stEngRStrtReq(value)
#define vidGET_VALUE_CoReqVeh_stEngRStrtReq(variable)                            Rte_Read_R_CoReqVeh_stEngRStrtReq_CoReqVeh_stEngRStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoReqVeh_stEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_CoReqVeh_stEngStopAuth(value)                               Rte_Write_P_CoReqVeh_stEngStopAuth_CoReqVeh_stEngStopAuth(value)
#define vidGET_VALUE_CoReqVeh_stEngStopAuth(variable)                            Rte_Read_R_CoReqVeh_stEngStopAuth_CoReqVeh_stEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable CoStrtRStrt_bInh
  **********************************************************************************/

#define vidSET_VALUE_CoStrtRStrt_bInh(value)
#define vidGET_VALUE_CoStrtRStrt_bInh(variable)                                  Rte_Read_R_CoStrtRStrt_bInh_CoStrtRStrt_bInh(&variable)

/**********************************************************************************
   Create interface for variable CoStrtRStrt_bVSSNwAcvAuth
  **********************************************************************************/

#define vidSET_VALUE_CoStrtRStrt_bVSSNwAcvAuth(value)
#define vidGET_VALUE_CoStrtRStrt_bVSSNwAcvAuth(variable)                         Rte_Read_R_CoStrtRStrt_bVSSNwAcvAuth_CoStrtRStrt_bVSSNwAcvAuth(&variable)

/**********************************************************************************
   Create interface for variable CoStrtRStrt_stAcvReq
  **********************************************************************************/

#define vidSET_VALUE_CoStrtRStrt_stAcvReq(value)
#define vidGET_VALUE_CoStrtRStrt_stAcvReq(variable)                              Rte_Read_R_CoStrtRStrt_stAcvReq_CoStrtRStrt_stAcvReq(&variable)

/**********************************************************************************
   Create interface for variable CoStrtRStrt_stEngStrtReq
  **********************************************************************************/

#define vidSET_VALUE_CoStrtRStrt_stEngStrtReq(value)
#define vidGET_VALUE_CoStrtRStrt_stEngStrtReq(variable)                          Rte_Read_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq(&variable)

/**********************************************************************************
   Create interface for variable CoStrtRStrt_stStopCutReq
  **********************************************************************************/

#define vidSET_VALUE_CoStrtRStrt_stStopCutReq(value)
#define vidGET_VALUE_CoStrtRStrt_stStopCutReq(variable)                          Rte_Read_R_CoStrtRStrt_stStopCutReq_CoStrtRStrt_stStopCutReq(&variable)

/**********************************************************************************
   Create interface for variable CoSync_bDetNNull
  **********************************************************************************/

#define vidSET_VALUE_CoSync_bDetNNull(value)                                     Rte_Write_P_CoSync_bDetNNull_CoSync_bDetNNull(value)
#define vidGET_VALUE_CoSync_bDetNNull(variable)                                  Rte_Read_R_CoSync_bDetNNull_CoSync_bDetNNull(&variable)

/**********************************************************************************
   Create interface for variable CoSync_bStuckEngStaAcv
  **********************************************************************************/

#define vidSET_VALUE_CoSync_bStuckEngStaAcv(value)                               Rte_Write_P_CoSync_bStuckEngStaAcv_CoSync_bStuckEngStaAcv(value)
#define vidGET_VALUE_CoSync_bStuckEngStaAcv(variable)                            Rte_Read_R_CoSync_bStuckEngStaAcv_CoSync_bStuckEngStaAcv(&variable)

/**********************************************************************************
   Create interface for variable CoSync_stSigCm2Sync
  **********************************************************************************/

#define vidSET_VALUE_CoSync_stSigCm2Sync(value)                                  Rte_Write_P_CoSync_stSigCm2Sync_CoSync_stSigCm2Sync(value)
#define vidGET_VALUE_CoSync_stSigCm2Sync(variable)                               Rte_Read_R_CoSync_stSigCm2Sync_CoSync_stSigCm2Sync(&variable)

/**********************************************************************************
   Create interface for variable CoTqRStrt_bChaTqAvl
  **********************************************************************************/

#define vidSET_VALUE_CoTqRStrt_bChaTqAvl(value)
#define vidGET_VALUE_CoTqRStrt_bChaTqAvl(variable)                               Rte_Read_R_CoTqRStrt_bChaTqAvl_CoTqRStrt_bChaTqAvl(&variable)

/**********************************************************************************
   Create interface for variable CoTqRStrt_bChaTqCrt
  **********************************************************************************/

#define vidSET_VALUE_CoTqRStrt_bChaTqCrt(value)
#define vidGET_VALUE_CoTqRStrt_bChaTqCrt(variable)                               Rte_Read_R_CoTqRStrt_bChaTqCrt_CoTqRStrt_bChaTqCrt(&variable)

/**********************************************************************************
   Create interface for variable CoTqRStrt_bTraCoplAuth
  **********************************************************************************/

#define vidSET_VALUE_CoTqRStrt_bTraCoplAuth(value)
#define vidGET_VALUE_CoTqRStrt_bTraCoplAuth(variable)                            Rte_Read_R_CoTqRStrt_bTraCoplAuth_CoTqRStrt_bTraCoplAuth(&variable)

/**********************************************************************************
   Create interface for variable CoTqRStrt_bTraTqAuthRaw
  **********************************************************************************/

#define vidSET_VALUE_CoTqRStrt_bTraTqAuthRaw(value)
#define vidGET_VALUE_CoTqRStrt_bTraTqAuthRaw(variable)                           Rte_Read_R_CoTqRStrt_bTraTqAuthRaw_CoTqRStrt_bTraTqAuthRaw(&variable)

/**********************************************************************************
   Create interface for variable CoVSCtl_rAccPEng
  **********************************************************************************/

#define vidSET_VALUE_CoVSCtl_rAccPEng(value)
#define vidGET_VALUE_CoVSCtl_rAccPEng(variable)                                  Rte_Read_R_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(&variable)

/**********************************************************************************
   Create interface for variable CoVSCtl_rAccPTra
  **********************************************************************************/

#define vidSET_VALUE_CoVSCtl_rAccPTra(value)
#define vidGET_VALUE_CoVSCtl_rAccPTra(variable)                                  Rte_Read_R_CoVSCtl_rAccPTra_CoVSCtl_rAccPTra(&variable)

/**********************************************************************************
   Create interface for variable CoVSCtl_stAccP
  **********************************************************************************/

#define vidSET_VALUE_CoVSCtl_stAccP(value)
#define vidGET_VALUE_CoVSCtl_stAccP(variable)                                    Rte_Read_R_CoVSCtl_stAccP_CoVSCtl_stAccP(&variable)

/**********************************************************************************
   Create interface for variable CoVSCtl_tqEfcReq
  **********************************************************************************/

#define vidSET_VALUE_CoVSCtl_tqEfcReq(value)
#define vidGET_VALUE_CoVSCtl_tqEfcReq(variable)                                  Rte_Read_R_CoVSCtl_tqEfcReq_CoVSCtl_tqEfcReq(&variable)

/**********************************************************************************
   Create interface for variable Code_test_action
  **********************************************************************************/

#define vidSET_VALUE_Code_test_action(value)                                     Rte_Write_P_Code_test_action_Code_test_action(value)
#define vidGET_VALUE_Code_test_action(variable)                                  Rte_Read_R_Code_test_action_Code_test_action(&variable)

/**********************************************************************************
   Create interface for variable Commande_DmpVlv_pwm_freq
  **********************************************************************************/

#define vidSET_VALUE_Commande_DmpVlv_pwm_freq(value)                             Rte_Write_P_Commande_DmpVlv_pwm_freq_Commande_DmpVlv_pwm_freq(value)
#define vidGET_VALUE_Commande_DmpVlv_pwm_freq(variable)                          Rte_Read_R_Commande_DmpVlv_pwm_freq_Commande_DmpVlv_pwm_freq(&variable)

/**********************************************************************************
   Create interface for variable Commande_DmpVlv_pwm_rco
  **********************************************************************************/

#define vidSET_VALUE_Commande_DmpVlv_pwm_rco(value)                              Rte_Write_P_Commande_DmpVlv_pwm_rco_Commande_DmpVlv_pwm_rco(value)
#define vidGET_VALUE_Commande_DmpVlv_pwm_rco(variable)                           Rte_Read_R_Commande_DmpVlv_pwm_rco_Commande_DmpVlv_pwm_rco(&variable)

/**********************************************************************************
   Create interface for variable Commande_GMV_B1
  **********************************************************************************/

#define vidSET_VALUE_Commande_GMV_B1(value)                                      Rte_Write_P_Commande_GMV_B1_Commande_GMV_B1(value)
#define vidGET_VALUE_Commande_GMV_B1(variable)                                   Rte_Read_R_Commande_GMV_B1_Commande_GMV_B1(&variable)

/**********************************************************************************
   Create interface for variable Commande_GMV_B2
  **********************************************************************************/

#define vidSET_VALUE_Commande_GMV_B2(value)                                      Rte_Write_P_Commande_GMV_B2_Commande_GMV_B2(value)
#define vidGET_VALUE_Commande_GMV_B2(variable)                                   Rte_Read_R_Commande_GMV_B2_Commande_GMV_B2(&variable)

/**********************************************************************************
   Create interface for variable Commande_GMV_C
  **********************************************************************************/

#define vidSET_VALUE_Commande_GMV_C(value)                                       Rte_Write_P_Commande_GMV_C_Commande_GMV_C(value)
#define vidGET_VALUE_Commande_GMV_C(variable)                                    Rte_Read_R_Commande_GMV_C_Commande_GMV_C(&variable)

/**********************************************************************************
   Create interface for variable Commande_bpm_pwm_rco
  **********************************************************************************/

#define vidSET_VALUE_Commande_bpm_pwm_rco(value)                                 Rte_Write_P_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco(value)
#define vidGET_VALUE_Commande_bpm_pwm_rco(variable)                              Rte_Read_R_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco(&variable)

/**********************************************************************************
   Create interface for variable Commande_chauffage_drvrseno2ds
  **********************************************************************************/

#define vidSET_VALUE_Commande_chauffage_drvrseno2ds(value)                       Rte_Write_P_Commande_chauffage_drvrseno2ds_Commande_chauffage_drvrseno2ds(value)
#define vidGET_VALUE_Commande_chauffage_drvrseno2ds(variable)                    Rte_Read_R_Commande_chauffage_drvrseno2ds_Commande_chauffage_drvrseno2ds(&variable)

/**********************************************************************************
   Create interface for variable Commande_chauffage_drvrseno2us
  **********************************************************************************/

#define vidSET_VALUE_Commande_chauffage_drvrseno2us(value)                       Rte_Write_P_Commande_chauffage_drvrseno2us_Commande_chauffage_drvrseno2us(value)
#define vidGET_VALUE_Commande_chauffage_drvrseno2us(variable)                    Rte_Read_R_Commande_chauffage_drvrseno2us_Commande_chauffage_drvrseno2us(&variable)

/**********************************************************************************
   Create interface for variable Commande_ectdrv_pwm_rco
  **********************************************************************************/

#define vidSET_VALUE_Commande_ectdrv_pwm_rco(value)                              Rte_Write_P_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco(value)
#define vidGET_VALUE_Commande_ectdrv_pwm_rco(variable)                           Rte_Read_R_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco(&variable)

/**********************************************************************************
   Create interface for variable Commande_maintien_dmtr_tor
  **********************************************************************************/

#define vidSET_VALUE_Commande_maintien_dmtr_tor(value)                           Rte_Write_P_Commande_maintien_dmtr_tor_Commande_maintien_dmtr_tor(value)
#define vidGET_VALUE_Commande_maintien_dmtr_tor(variable)                        Rte_Read_R_Commande_maintien_dmtr_tor_Commande_maintien_dmtr_tor(&variable)

/**********************************************************************************
   Create interface for variable Commande_pompe_ess_pwm
  **********************************************************************************/

#define vidSET_VALUE_Commande_pompe_ess_pwm(value)                               Rte_Write_P_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm(value)
#define vidGET_VALUE_Commande_pompe_ess_pwm(variable)                            Rte_Read_R_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm(&variable)

/**********************************************************************************
   Create interface for variable Commande_purge_pwm_freq
  **********************************************************************************/

#define vidSET_VALUE_Commande_purge_pwm_freq(value)                              Rte_Write_P_Commande_purge_pwm_freq_Commande_purge_pwm_freq(value)
#define vidGET_VALUE_Commande_purge_pwm_freq(variable)                           Rte_Read_R_Commande_purge_pwm_freq_Commande_purge_pwm_freq(&variable)

/**********************************************************************************
   Create interface for variable Commande_purge_pwm_rco
  **********************************************************************************/

#define vidSET_VALUE_Commande_purge_pwm_rco(value)                               Rte_Write_P_Commande_purge_pwm_rco_Commande_purge_pwm_rco(value)
#define vidGET_VALUE_Commande_purge_pwm_rco(variable)                            Rte_Read_R_Commande_purge_pwm_rco_Commande_purge_pwm_rco(&variable)

/**********************************************************************************
   Create interface for variable Commande_rechauff_blowby1_tor
  **********************************************************************************/

#define vidSET_VALUE_Commande_rechauff_blowby1_tor(value)                        Rte_Write_P_Commande_rechauff_blowby1_tor_Commande_rechauff_blowby1_tor(value)
#define vidGET_VALUE_Commande_rechauff_blowby1_tor(variable)                     Rte_Read_R_Commande_rechauff_blowby1_tor_Commande_rechauff_blowby1_tor(&variable)

/**********************************************************************************
   Create interface for variable Commande_rechauff_blowby2_tor
  **********************************************************************************/

#define vidSET_VALUE_Commande_rechauff_blowby2_tor(value)                        Rte_Write_P_Commande_rechauff_blowby2_tor_Commande_rechauff_blowby2_tor(value)
#define vidGET_VALUE_Commande_rechauff_blowby2_tor(variable)                     Rte_Read_R_Commande_rechauff_blowby2_tor_Commande_rechauff_blowby2_tor(&variable)

/**********************************************************************************
   Create interface for variable Commande_relais_principal
  **********************************************************************************/

#define vidSET_VALUE_Commande_relais_principal(value)                            Rte_Write_P_Commande_relais_principal_Commande_relais_principal(value)
#define vidGET_VALUE_Commande_relais_principal(variable)                         Rte_Read_R_Commande_relais_principal_Commande_relais_principal(&variable)

/**********************************************************************************
   Create interface for variable Commande_relais_puissance
  **********************************************************************************/

#define vidSET_VALUE_Commande_relais_puissance(value)                            Rte_Write_P_Commande_relais_puissance_Commande_relais_puissance(value)
#define vidGET_VALUE_Commande_relais_puissance(variable)                         Rte_Read_R_Commande_relais_puissance_Commande_relais_puissance(&variable)

/**********************************************************************************
   Create interface for variable Commande_vvt_adm_pwm_rco
  **********************************************************************************/

#define vidSET_VALUE_Commande_vvt_adm_pwm_rco(value)                             Rte_Write_P_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco(value)
#define vidGET_VALUE_Commande_vvt_adm_pwm_rco(variable)                          Rte_Read_R_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco(&variable)

/**********************************************************************************
   Create interface for variable Commande_vvt_ech_pwm_rco
  **********************************************************************************/

#define vidSET_VALUE_Commande_vvt_ech_pwm_rco(value)                             Rte_Write_P_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco(value)
#define vidGET_VALUE_Commande_vvt_ech_pwm_rco(variable)                          Rte_Read_R_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco(&variable)

/**********************************************************************************
   Create interface for variable Commande_water_pump_pwm_freq
  **********************************************************************************/

#define vidSET_VALUE_Commande_water_pump_pwm_freq(value)                         Rte_Write_P_Commande_water_pump_pwm_freq_Commande_water_pump_pwm_freq(value)
#define vidGET_VALUE_Commande_water_pump_pwm_freq(variable)                      Rte_Read_R_Commande_water_pump_pwm_freq_Commande_water_pump_pwm_freq(&variable)

/**********************************************************************************
   Create interface for variable Commande_water_pump_pwm_rco
  **********************************************************************************/

#define vidSET_VALUE_Commande_water_pump_pwm_rco(value)                          Rte_Write_P_Commande_water_pump_pwm_rco_Commande_water_pump_pwm_rco(value)
#define vidGET_VALUE_Commande_water_pump_pwm_rco(variable)                       Rte_Read_R_Commande_water_pump_pwm_rco_Commande_water_pump_pwm_rco(&variable)

/**********************************************************************************
   Create interface for variable Coupure_inj_ess_1
  **********************************************************************************/

#define vidSET_VALUE_Coupure_inj_ess_1(value)                                    Rte_Write_P_Coupure_inj_ess_1_Coupure_inj_ess_1(value)
#define vidGET_VALUE_Coupure_inj_ess_1(variable)                                 Rte_Read_R_Coupure_inj_ess_1_Coupure_inj_ess_1(&variable)

/**********************************************************************************
   Create interface for variable Coupure_inj_ess_2
  **********************************************************************************/

#define vidSET_VALUE_Coupure_inj_ess_2(value)                                    Rte_Write_P_Coupure_inj_ess_2_Coupure_inj_ess_2(value)
#define vidGET_VALUE_Coupure_inj_ess_2(variable)                                 Rte_Read_R_Coupure_inj_ess_2_Coupure_inj_ess_2(&variable)

/**********************************************************************************
   Create interface for variable Coupure_inj_ess_3
  **********************************************************************************/

#define vidSET_VALUE_Coupure_inj_ess_3(value)                                    Rte_Write_P_Coupure_inj_ess_3_Coupure_inj_ess_3(value)
#define vidGET_VALUE_Coupure_inj_ess_3(variable)                                 Rte_Read_R_Coupure_inj_ess_3_Coupure_inj_ess_3(&variable)

/**********************************************************************************
   Create interface for variable Coupure_inj_ess_4
  **********************************************************************************/

#define vidSET_VALUE_Coupure_inj_ess_4(value)                                    Rte_Write_P_Coupure_inj_ess_4_Coupure_inj_ess_4(value)
#define vidGET_VALUE_Coupure_inj_ess_4(variable)                                 Rte_Read_R_Coupure_inj_ess_4_Coupure_inj_ess_4(&variable)

/**********************************************************************************
   Create interface for variable Courant_chauf_seno2ds
  **********************************************************************************/

#define vidSET_VALUE_Courant_chauf_seno2ds(value)
#define vidGET_VALUE_Courant_chauf_seno2ds(variable)                             Rte_Read_R_Courant_chauf_seno2ds_Courant_chauf_seno2ds(&variable)

/**********************************************************************************
   Create interface for variable Courant_chauf_seno2us
  **********************************************************************************/

#define vidSET_VALUE_Courant_chauf_seno2us(value)
#define vidGET_VALUE_Courant_chauf_seno2us(variable)                             Rte_Read_R_Courant_chauf_seno2us_Courant_chauf_seno2us(&variable)

/**********************************************************************************
   Create interface for variable CrkMgt_stThr_arThrEff
  **********************************************************************************/

#define vidSET_VALUE_CrkMgt_stThr_arThrEff(value)                                Rte_Write_P_CrkMgt_stThr_arThrEff_CrkMgt_stThr_arThrEff(value)
#define vidGET_VALUE_CrkMgt_stThr_arThrEff(variable)                             Rte_Read_R_CrkMgt_stThr_arThrEff_CrkMgt_stThr_arThrEff(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_ECTReq
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_ECTReq(value)                                     Rte_Write_P_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq(value)
#define vidGET_VALUE_Ctrl_bAcv_ECTReq(variable)                                  Rte_Read_R_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_EngMes
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_EngMes(value)                                     Rte_Write_P_Ctrl_bAcv_EngMes_Ctrl_bAcv_EngMes(value)
#define vidGET_VALUE_Ctrl_bAcv_EngMes(variable)                                  Rte_Read_R_Ctrl_bAcv_EngMes_Ctrl_bAcv_EngMes(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_FuTnkPmp
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_FuTnkPmp(value)                                   Rte_Write_P_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp(value)
#define vidGET_VALUE_Ctrl_bAcv_FuTnkPmp(variable)                                Rte_Read_R_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_HpPmp
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_HpPmp(value)                                      Rte_Write_P_Ctrl_bAcv_HpPmp_Ctrl_bAcv_HpPmp(value)
#define vidGET_VALUE_Ctrl_bAcv_HpPmp(variable)                                   Rte_Read_R_Ctrl_bAcv_HpPmp_Ctrl_bAcv_HpPmp(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_PFuAcq
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_PFuAcq(value)                                     Rte_Write_P_Ctrl_bAcv_PFuAcq_Ctrl_bAcv_PFuAcq(value)
#define vidGET_VALUE_Ctrl_bAcv_PFuAcq(variable)                                  Rte_Read_R_Ctrl_bAcv_PFuAcq_Ctrl_bAcv_PFuAcq(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_TrbCoWaPmp
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_TrbCoWaPmp(value)                                 Rte_Write_P_Ctrl_bAcv_TrbCoWaPmp_Ctrl_bAcv_TrbCoWaPmp(value)
#define vidGET_VALUE_Ctrl_bAcv_TrbCoWaPmp(variable)                              Rte_Read_R_Ctrl_bAcv_TrbCoWaPmp_Ctrl_bAcv_TrbCoWaPmp(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_pAirExtMes
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_pAirExtMes(value)                                 Rte_Write_P_Ctrl_bAcv_pAirExtMes_Ctrl_bAcv_pAirExtMes(value)
#define vidGET_VALUE_Ctrl_bAcv_pAirExtMes(variable)                              Rte_Read_R_Ctrl_bAcv_pAirExtMes_Ctrl_bAcv_pAirExtMes(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_pDsThr
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_pDsThr(value)                                     Rte_Write_P_Ctrl_bAcv_pDsThr_Ctrl_bAcv_pDsThr(value)
#define vidGET_VALUE_Ctrl_bAcv_pDsThr(variable)                                  Rte_Read_R_Ctrl_bAcv_pDsThr_Ctrl_bAcv_pDsThr(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_pRelBrkAsi
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_pRelBrkAsi(value)                                 Rte_Write_P_Ctrl_bAcv_pRelBrkAsi_Ctrl_bAcv_pRelBrkAsi(value)
#define vidGET_VALUE_Ctrl_bAcv_pRelBrkAsi(variable)                              Rte_Read_R_Ctrl_bAcv_pRelBrkAsi_Ctrl_bAcv_pRelBrkAsi(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_pUsThr
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_pUsThr(value)                                     Rte_Write_P_Ctrl_bAcv_pUsThr_Ctrl_bAcv_pUsThr(value)
#define vidGET_VALUE_Ctrl_bAcv_pUsThr(variable)                                  Rte_Read_R_Ctrl_bAcv_pUsThr_Ctrl_bAcv_pUsThr(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcv_uEngOilLvl
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcv_uEngOilLvl(value)                                 Rte_Write_P_Ctrl_bAcv_uEngOilLvl_Ctrl_bAcv_uEngOilLvl(value)
#define vidGET_VALUE_Ctrl_bAcv_uEngOilLvl(variable)                              Rte_Read_R_Ctrl_bAcv_uEngOilLvl_Ctrl_bAcv_uEngOilLvl(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAcvtIGBTAcq
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAcvtIGBTAcq(value)                                    Rte_Write_P_Ctrl_bAcvtIGBTAcq_Ctrl_bAcvtIGBTAcq(value)
#define vidGET_VALUE_Ctrl_bAcvtIGBTAcq(variable)                                 Rte_Read_R_Ctrl_bAcvtIGBTAcq_Ctrl_bAcvtIGBTAcq(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAvc_BlowBy1
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAvc_BlowBy1(value)                                    Rte_Write_P_Ctrl_bAvc_BlowBy1_Ctrl_bAvc_BlowBy1(value)
#define vidGET_VALUE_Ctrl_bAvc_BlowBy1(variable)                                 Rte_Read_R_Ctrl_bAvc_BlowBy1_Ctrl_bAvc_BlowBy1(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bAvc_BlowBy2
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bAvc_BlowBy2(value)                                    Rte_Write_P_Ctrl_bAvc_BlowBy2_Ctrl_bAvc_BlowBy2(value)
#define vidGET_VALUE_Ctrl_bAvc_BlowBy2(variable)                                 Rte_Read_R_Ctrl_bAvc_BlowBy2_Ctrl_bAvc_BlowBy2(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bEngRun
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bEngRun(value)                                         Rte_Write_P_Ctrl_bEngRun_Ctrl_bEngRun(value)
#define vidGET_VALUE_Ctrl_bEngRun(variable)                                      Rte_Read_R_Ctrl_bEngRun_Ctrl_bEngRun(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bEngRunr
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bEngRunr(value)                                        Rte_Write_P_Ctrl_bEngRunr_Ctrl_bEngRunr(value)
#define vidGET_VALUE_Ctrl_bEngRunr(variable)                                     Rte_Read_R_Ctrl_bEngRunr_Ctrl_bEngRunr(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bOilPmpCmd
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bOilPmpCmd(value)                                      Rte_Write_P_Ctrl_bOilPmpCmd_Ctrl_bOilPmpCmd(value)
#define vidGET_VALUE_Ctrl_bOilPmpCmd(variable)                                   Rte_Read_R_Ctrl_bOilPmpCmd_Ctrl_bOilPmpCmd(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bOilPropPresAcq
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bOilPropPresAcq(value)                                 Rte_Write_P_Ctrl_bOilPropPresAcq_Ctrl_bOilPropPresAcq(value)
#define vidGET_VALUE_Ctrl_bOilPropPresAcq(variable)                              Rte_Read_R_Ctrl_bOilPropPresAcq_Ctrl_bOilPropPresAcq(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bTrbAct_rCtl
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bTrbAct_rCtl(value)                                    Rte_Write_P_Ctrl_bTrbAct_rCtl_Ctrl_bTrbAct_rCtl(value)
#define vidGET_VALUE_Ctrl_bTrbAct_rCtl(variable)                                 Rte_Read_R_Ctrl_bTrbAct_rCtl_Ctrl_bTrbAct_rCtl(&variable)

/**********************************************************************************
   Create interface for variable Ctrl_bTreatAdHeatRly
  **********************************************************************************/

#define vidSET_VALUE_Ctrl_bTreatAdHeatRly(value)                                 Rte_Write_P_Ctrl_bTreatAdHeatRly_Ctrl_bTreatAdHeatRly(value)
#define vidGET_VALUE_Ctrl_bTreatAdHeatRly(variable)                              Rte_Read_R_Ctrl_bTreatAdHeatRly_Ctrl_bTreatAdHeatRly(&variable)

/**********************************************************************************
   Create interface for variable DIAGCAN_bIntegratioElectronique
  **********************************************************************************/

#define vidSET_VALUE_DIAGCAN_bIntegratioElectronique(value)                      Rte_Write_P_DIAGCAN_bIntegratioElectronique_DIAGCAN_bIntegratioElectronique(value)
#define vidGET_VALUE_DIAGCAN_bIntegratioElectronique(variable)                   Rte_Read_R_DIAGCAN_bIntegratioElectronique_DIAGCAN_bIntegratioElectronique(&variable)

/**********************************************************************************
   Create interface for variable DZone_tqEfcDifLrnOut
  **********************************************************************************/

#define vidSET_VALUE_DZone_tqEfcDifLrnOut(value)
#define vidGET_VALUE_DZone_tqEfcDifLrnOut(variable)                              Rte_Read_R_DZone_tqEfcDifLrnOut_DZone_tqEfcDifLrnOut(&variable)

/**********************************************************************************
   Create interface for variable Demande_inhibition_hbridge
  **********************************************************************************/

#define vidSET_VALUE_Demande_inhibition_hbridge(value)                           Rte_Write_P_Demande_inhibition_hbridge_Demande_inhibition_hbridge(value)
#define vidGET_VALUE_Demande_inhibition_hbridge(variable)                        Rte_Read_R_Demande_inhibition_hbridge_Demande_inhibition_hbridge(&variable)

/**********************************************************************************
   Create interface for variable Dena_ComSpi_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dena_ComSpi_ASICGDI(value)
#define vidGET_VALUE_Dena_ComSpi_ASICGDI(variable)                               Rte_Read_R_Dena_ComSpi_ASICGDI_Dena_ComSpi_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dena_OverVBat_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dena_OverVBat_ASICGDI(value)
#define vidGET_VALUE_Dena_OverVBat_ASICGDI(variable)                             Rte_Read_R_Dena_OverVBat_ASICGDI_Dena_OverVBat_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dena_OverVBoost_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dena_OverVBoost_ASICGDI(value)
#define vidGET_VALUE_Dena_OverVBoost_ASICGDI(variable)                           Rte_Read_R_Dena_OverVBoost_ASICGDI_Dena_OverVBoost_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dena_UnderVBat_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dena_UnderVBat_ASICGDI(value)
#define vidGET_VALUE_Dena_UnderVBat_ASICGDI(variable)                            Rte_Read_R_Dena_UnderVBat_ASICGDI_Dena_UnderVBat_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dena_UnderVBoost_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dena_UnderVBoost_ASICGDI(value)
#define vidGET_VALUE_Dena_UnderVBoost_ASICGDI(variable)                          Rte_Read_R_Dena_UnderVBoost_ASICGDI_Dena_UnderVBoost_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dena_chr_excamdiag
  **********************************************************************************/

#define vidSET_VALUE_Dena_chr_excamdiag(value)
#define vidGET_VALUE_Dena_chr_excamdiag(variable)                                Rte_Read_R_Dena_chr_excamdiag_Dena_chr_excamdiag(&variable)

/**********************************************************************************
   Create interface for variable Dena_chr_incamdiag
  **********************************************************************************/

#define vidSET_VALUE_Dena_chr_incamdiag(value)
#define vidGET_VALUE_Dena_chr_incamdiag(variable)                                Rte_Read_R_Dena_chr_incamdiag_Dena_chr_incamdiag(&variable)

/**********************************************************************************
   Create interface for variable Dena_composant_bpm
  **********************************************************************************/

#define vidSET_VALUE_Dena_composant_bpm(value)
#define vidGET_VALUE_Dena_composant_bpm(variable)                                Rte_Read_R_Dena_composant_bpm_Dena_composant_bpm(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_CTP1
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_CTP1(value)
#define vidGET_VALUE_Dena_oc_CTP1(variable)                                      Rte_Read_R_Dena_oc_CTP1_Dena_oc_CTP1(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_CTP2
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_CTP2(value)
#define vidGET_VALUE_Dena_oc_CTP2(variable)                                      Rte_Read_R_Dena_oc_CTP2_Dena_oc_CTP2(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_CtlPmpReq
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_CtlPmpReq(value)
#define vidGET_VALUE_Dena_oc_CtlPmpReq(variable)                                 Rte_Read_R_Dena_oc_CtlPmpReq_Dena_oc_CtlPmpReq(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_DmpVlvCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_DmpVlvCmd(value)
#define vidGET_VALUE_Dena_oc_DmpVlvCmd(variable)                                 Rte_Read_R_Dena_oc_DmpVlvCmd_Dena_oc_DmpVlvCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_HPPmpActCmd(value)
#define vidGET_VALUE_Dena_oc_HPPmpActCmd(variable)                               Rte_Read_R_Dena_oc_HPPmpActCmd_Dena_oc_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_Inj1Cmd(value)
#define vidGET_VALUE_Dena_oc_Inj1Cmd(variable)                                   Rte_Read_R_Dena_oc_Inj1Cmd_Dena_oc_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_Inj2Cmd(value)
#define vidGET_VALUE_Dena_oc_Inj2Cmd(variable)                                   Rte_Read_R_Dena_oc_Inj2Cmd_Dena_oc_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_Inj3Cmd(value)
#define vidGET_VALUE_Dena_oc_Inj3Cmd(variable)                                   Rte_Read_R_Dena_oc_Inj3Cmd_Dena_oc_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_Inj4Cmd(value)
#define vidGET_VALUE_Dena_oc_Inj4Cmd(variable)                                   Rte_Read_R_Dena_oc_Inj4Cmd_Dena_oc_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_OilLvlAcq
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_OilLvlAcq(value)
#define vidGET_VALUE_Dena_oc_OilLvlAcq(variable)                                 Rte_Read_R_Dena_oc_OilLvlAcq_Dena_oc_OilLvlAcq(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_TrbWaPmp
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_TrbWaPmp(value)
#define vidGET_VALUE_Dena_oc_TrbWaPmp(variable)                                  Rte_Read_R_Dena_oc_TrbWaPmp_Dena_oc_TrbWaPmp(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_WgcCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_WgcCmd(value)
#define vidGET_VALUE_Dena_oc_WgcCmd(variable)                                    Rte_Read_R_Dena_oc_WgcCmd_Dena_oc_WgcCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_bobine1
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_bobine1(value)
#define vidGET_VALUE_Dena_oc_bobine1(variable)                                   Rte_Read_R_Dena_oc_bobine1_Dena_oc_bobine1(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_bobine2
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_bobine2(value)
#define vidGET_VALUE_Dena_oc_bobine2(variable)                                   Rte_Read_R_Dena_oc_bobine2_Dena_oc_bobine2(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_bobine3
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_bobine3(value)
#define vidGET_VALUE_Dena_oc_bobine3(variable)                                   Rte_Read_R_Dena_oc_bobine3_Dena_oc_bobine3(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_bobine4
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_bobine4(value)
#define vidGET_VALUE_Dena_oc_bobine4(variable)                                   Rte_Read_R_Dena_oc_bobine4_Dena_oc_bobine4(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_cmd_dmtr
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_cmd_dmtr(value)
#define vidGET_VALUE_Dena_oc_cmd_dmtr(variable)                                  Rte_Read_R_Dena_oc_cmd_dmtr_Dena_oc_cmd_dmtr(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_cmdautoredemstt
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_cmdautoredemstt(value)
#define vidGET_VALUE_Dena_oc_cmdautoredemstt(variable)                           Rte_Read_R_Dena_oc_cmdautoredemstt_Dena_oc_cmdautoredemstt(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_cstrdrv
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_cstrdrv(value)
#define vidGET_VALUE_Dena_oc_cstrdrv(variable)                                   Rte_Read_R_Dena_oc_cstrdrv_Dena_oc_cstrdrv(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_driver_GMV1
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_driver_GMV1(value)
#define vidGET_VALUE_Dena_oc_driver_GMV1(variable)                               Rte_Read_R_Dena_oc_driver_GMV1_Dena_oc_driver_GMV1(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_driver_GMV2
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_driver_GMV2(value)
#define vidGET_VALUE_Dena_oc_driver_GMV2(variable)                               Rte_Read_R_Dena_oc_driver_GMV2_Dena_oc_driver_GMV2(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_driver_vvt_adm
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_driver_vvt_adm(value)
#define vidGET_VALUE_Dena_oc_driver_vvt_adm(variable)                            Rte_Read_R_Dena_oc_driver_vvt_adm_Dena_oc_driver_vvt_adm(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_driver_vvt_ech
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_driver_vvt_ech(value)
#define vidGET_VALUE_Dena_oc_driver_vvt_ech(variable)                            Rte_Read_R_Dena_oc_driver_vvt_ech_Dena_oc_driver_vvt_ech(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_drvrseno2ds
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_drvrseno2ds(value)
#define vidGET_VALUE_Dena_oc_drvrseno2ds(variable)                               Rte_Read_R_Dena_oc_drvrseno2ds_Dena_oc_drvrseno2ds(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_drvrseno2us
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_drvrseno2us(value)
#define vidGET_VALUE_Dena_oc_drvrseno2us(variable)                               Rte_Read_R_Dena_oc_drvrseno2us_Dena_oc_drvrseno2us(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_infomoteurtournant
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_infomoteurtournant(value)
#define vidGET_VALUE_Dena_oc_infomoteurtournant(variable)                        Rte_Read_R_Dena_oc_infomoteurtournant_Dena_oc_infomoteurtournant(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_pompe_ess_pwm
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_pompe_ess_pwm(value)
#define vidGET_VALUE_Dena_oc_pompe_ess_pwm(variable)                             Rte_Read_R_Dena_oc_pompe_ess_pwm_Dena_oc_pompe_ess_pwm(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_rechauffeurblowby1
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_rechauffeurblowby1(value)
#define vidGET_VALUE_Dena_oc_rechauffeurblowby1(variable)                        Rte_Read_R_Dena_oc_rechauffeurblowby1_Dena_oc_rechauffeurblowby1(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_rechauffeurblowby2
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_rechauffeurblowby2(value)
#define vidGET_VALUE_Dena_oc_rechauffeurblowby2(variable)                        Rte_Read_R_Dena_oc_rechauffeurblowby2_Dena_oc_rechauffeurblowby2(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_relais_puissance
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_relais_puissance(value)
#define vidGET_VALUE_Dena_oc_relais_puissance(variable)                          Rte_Read_R_Dena_oc_relais_puissance_Dena_oc_relais_puissance(&variable)

/**********************************************************************************
   Create interface for variable Dena_oc_sortielogiquedml
  **********************************************************************************/

#define vidSET_VALUE_Dena_oc_sortielogiquedml(value)
#define vidGET_VALUE_Dena_oc_sortielogiquedml(variable)                          Rte_Read_R_Dena_oc_sortielogiquedml_Dena_oc_sortielogiquedml(&variable)

/**********************************************************************************
   Create interface for variable Dena_ovld_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_ovld_HPPmpActCmd(value)
#define vidGET_VALUE_Dena_ovld_HPPmpActCmd(variable)                             Rte_Read_R_Dena_ovld_HPPmpActCmd_Dena_ovld_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_ovld_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_ovld_Inj1Cmd(value)
#define vidGET_VALUE_Dena_ovld_Inj1Cmd(variable)                                 Rte_Read_R_Dena_ovld_Inj1Cmd_Dena_ovld_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_ovld_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_ovld_Inj2Cmd(value)
#define vidGET_VALUE_Dena_ovld_Inj2Cmd(variable)                                 Rte_Read_R_Dena_ovld_Inj2Cmd_Dena_ovld_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_ovld_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_ovld_Inj3Cmd(value)
#define vidGET_VALUE_Dena_ovld_Inj3Cmd(variable)                                 Rte_Read_R_Dena_ovld_Inj3Cmd_Dena_ovld_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_ovld_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_ovld_Inj4Cmd(value)
#define vidGET_VALUE_Dena_ovld_Inj4Cmd(variable)                                 Rte_Read_R_Dena_ovld_Inj4Cmd_Dena_ovld_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_CTP1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_CTP1(value)
#define vidGET_VALUE_Dena_scg_CTP1(variable)                                     Rte_Read_R_Dena_scg_CTP1_Dena_scg_CTP1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_CTP2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_CTP2(value)
#define vidGET_VALUE_Dena_scg_CTP2(variable)                                     Rte_Read_R_Dena_scg_CTP2_Dena_scg_CTP2(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_CtlPmpReq
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_CtlPmpReq(value)
#define vidGET_VALUE_Dena_scg_CtlPmpReq(variable)                                Rte_Read_R_Dena_scg_CtlPmpReq_Dena_scg_CtlPmpReq(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_DmpVlvCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_DmpVlvCmd(value)
#define vidGET_VALUE_Dena_scg_DmpVlvCmd(variable)                                Rte_Read_R_Dena_scg_DmpVlvCmd_Dena_scg_DmpVlvCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_HPPmpActCmd(value)
#define vidGET_VALUE_Dena_scg_HPPmpActCmd(variable)                              Rte_Read_R_Dena_scg_HPPmpActCmd_Dena_scg_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_Inj1Cmd(value)
#define vidGET_VALUE_Dena_scg_Inj1Cmd(variable)                                  Rte_Read_R_Dena_scg_Inj1Cmd_Dena_scg_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_Inj2Cmd(value)
#define vidGET_VALUE_Dena_scg_Inj2Cmd(variable)                                  Rte_Read_R_Dena_scg_Inj2Cmd_Dena_scg_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_Inj3Cmd(value)
#define vidGET_VALUE_Dena_scg_Inj3Cmd(variable)                                  Rte_Read_R_Dena_scg_Inj3Cmd_Dena_scg_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_Inj4Cmd(value)
#define vidGET_VALUE_Dena_scg_Inj4Cmd(variable)                                  Rte_Read_R_Dena_scg_Inj4Cmd_Dena_scg_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_OilLvlAcq
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_OilLvlAcq(value)
#define vidGET_VALUE_Dena_scg_OilLvlAcq(variable)                                Rte_Read_R_Dena_scg_OilLvlAcq_Dena_scg_OilLvlAcq(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_TrbWaPmp
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_TrbWaPmp(value)
#define vidGET_VALUE_Dena_scg_TrbWaPmp(variable)                                 Rte_Read_R_Dena_scg_TrbWaPmp_Dena_scg_TrbWaPmp(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_WgcCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_WgcCmd(value)
#define vidGET_VALUE_Dena_scg_WgcCmd(variable)                                   Rte_Read_R_Dena_scg_WgcCmd_Dena_scg_WgcCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_bobine1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_bobine1(value)
#define vidGET_VALUE_Dena_scg_bobine1(variable)                                  Rte_Read_R_Dena_scg_bobine1_Dena_scg_bobine1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_bobine2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_bobine2(value)
#define vidGET_VALUE_Dena_scg_bobine2(variable)                                  Rte_Read_R_Dena_scg_bobine2_Dena_scg_bobine2(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_bobine3
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_bobine3(value)
#define vidGET_VALUE_Dena_scg_bobine3(variable)                                  Rte_Read_R_Dena_scg_bobine3_Dena_scg_bobine3(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_bobine4
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_bobine4(value)
#define vidGET_VALUE_Dena_scg_bobine4(variable)                                  Rte_Read_R_Dena_scg_bobine4_Dena_scg_bobine4(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_cmd_dmtr
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_cmd_dmtr(value)
#define vidGET_VALUE_Dena_scg_cmd_dmtr(variable)                                 Rte_Read_R_Dena_scg_cmd_dmtr_Dena_scg_cmd_dmtr(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_cmdautoredemstt
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_cmdautoredemstt(value)
#define vidGET_VALUE_Dena_scg_cmdautoredemstt(variable)                          Rte_Read_R_Dena_scg_cmdautoredemstt_Dena_scg_cmdautoredemstt(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_cstrdrv
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_cstrdrv(value)
#define vidGET_VALUE_Dena_scg_cstrdrv(variable)                                  Rte_Read_R_Dena_scg_cstrdrv_Dena_scg_cstrdrv(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_driver_GMV1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_driver_GMV1(value)
#define vidGET_VALUE_Dena_scg_driver_GMV1(variable)                              Rte_Read_R_Dena_scg_driver_GMV1_Dena_scg_driver_GMV1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_driver_GMV2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_driver_GMV2(value)
#define vidGET_VALUE_Dena_scg_driver_GMV2(variable)                              Rte_Read_R_Dena_scg_driver_GMV2_Dena_scg_driver_GMV2(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_driver_vvt_adm
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_driver_vvt_adm(value)
#define vidGET_VALUE_Dena_scg_driver_vvt_adm(variable)                           Rte_Read_R_Dena_scg_driver_vvt_adm_Dena_scg_driver_vvt_adm(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_driver_vvt_ech
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_driver_vvt_ech(value)
#define vidGET_VALUE_Dena_scg_driver_vvt_ech(variable)                           Rte_Read_R_Dena_scg_driver_vvt_ech_Dena_scg_driver_vvt_ech(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_drvrseno2ds
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_drvrseno2ds(value)
#define vidGET_VALUE_Dena_scg_drvrseno2ds(variable)                              Rte_Read_R_Dena_scg_drvrseno2ds_Dena_scg_drvrseno2ds(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_drvrseno2us
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_drvrseno2us(value)
#define vidGET_VALUE_Dena_scg_drvrseno2us(variable)                              Rte_Read_R_Dena_scg_drvrseno2us_Dena_scg_drvrseno2us(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_infomoteurtournant
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_infomoteurtournant(value)
#define vidGET_VALUE_Dena_scg_infomoteurtournant(variable)                       Rte_Read_R_Dena_scg_infomoteurtournant_Dena_scg_infomoteurtournant(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_pompe_ess_pwm
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_pompe_ess_pwm(value)
#define vidGET_VALUE_Dena_scg_pompe_ess_pwm(variable)                            Rte_Read_R_Dena_scg_pompe_ess_pwm_Dena_scg_pompe_ess_pwm(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_rechauffeurblowby1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_rechauffeurblowby1(value)
#define vidGET_VALUE_Dena_scg_rechauffeurblowby1(variable)                       Rte_Read_R_Dena_scg_rechauffeurblowby1_Dena_scg_rechauffeurblowby1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_rechauffeurblowby2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_rechauffeurblowby2(value)
#define vidGET_VALUE_Dena_scg_rechauffeurblowby2(variable)                       Rte_Read_R_Dena_scg_rechauffeurblowby2_Dena_scg_rechauffeurblowby2(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_relais_puissance
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_relais_puissance(value)
#define vidGET_VALUE_Dena_scg_relais_puissance(variable)                         Rte_Read_R_Dena_scg_relais_puissance_Dena_scg_relais_puissance(&variable)

/**********************************************************************************
   Create interface for variable Dena_scg_sortielogiquedml
  **********************************************************************************/

#define vidSET_VALUE_Dena_scg_sortielogiquedml(value)
#define vidGET_VALUE_Dena_scg_sortielogiquedml(variable)                         Rte_Read_R_Dena_scg_sortielogiquedml_Dena_scg_sortielogiquedml(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_CTP1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_CTP1(value)
#define vidGET_VALUE_Dena_scp_CTP1(variable)                                     Rte_Read_R_Dena_scp_CTP1_Dena_scp_CTP1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_CTP2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_CTP2(value)
#define vidGET_VALUE_Dena_scp_CTP2(variable)                                     Rte_Read_R_Dena_scp_CTP2_Dena_scp_CTP2(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_CtlPmpReq
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_CtlPmpReq(value)
#define vidGET_VALUE_Dena_scp_CtlPmpReq(variable)                                Rte_Read_R_Dena_scp_CtlPmpReq_Dena_scp_CtlPmpReq(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_DmpVlvCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_DmpVlvCmd(value)
#define vidGET_VALUE_Dena_scp_DmpVlvCmd(variable)                                Rte_Read_R_Dena_scp_DmpVlvCmd_Dena_scp_DmpVlvCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_HPPmpActCmd(value)
#define vidGET_VALUE_Dena_scp_HPPmpActCmd(variable)                              Rte_Read_R_Dena_scp_HPPmpActCmd_Dena_scp_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_OilLvlAcq
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_OilLvlAcq(value)
#define vidGET_VALUE_Dena_scp_OilLvlAcq(variable)                                Rte_Read_R_Dena_scp_OilLvlAcq_Dena_scp_OilLvlAcq(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_TrbWaPmp
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_TrbWaPmp(value)
#define vidGET_VALUE_Dena_scp_TrbWaPmp(variable)                                 Rte_Read_R_Dena_scp_TrbWaPmp_Dena_scp_TrbWaPmp(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_WgcCmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_WgcCmd(value)
#define vidGET_VALUE_Dena_scp_WgcCmd(variable)                                   Rte_Read_R_Dena_scp_WgcCmd_Dena_scp_WgcCmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_bobine1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_bobine1(value)
#define vidGET_VALUE_Dena_scp_bobine1(variable)                                  Rte_Read_R_Dena_scp_bobine1_Dena_scp_bobine1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_bobine2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_bobine2(value)
#define vidGET_VALUE_Dena_scp_bobine2(variable)                                  Rte_Read_R_Dena_scp_bobine2_Dena_scp_bobine2(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_bobine3
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_bobine3(value)
#define vidGET_VALUE_Dena_scp_bobine3(variable)                                  Rte_Read_R_Dena_scp_bobine3_Dena_scp_bobine3(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_bobine4
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_bobine4(value)
#define vidGET_VALUE_Dena_scp_bobine4(variable)                                  Rte_Read_R_Dena_scp_bobine4_Dena_scp_bobine4(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_cmd_dmtr
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_cmd_dmtr(value)
#define vidGET_VALUE_Dena_scp_cmd_dmtr(variable)                                 Rte_Read_R_Dena_scp_cmd_dmtr_Dena_scp_cmd_dmtr(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_cmdautoredemstt
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_cmdautoredemstt(value)
#define vidGET_VALUE_Dena_scp_cmdautoredemstt(variable)                          Rte_Read_R_Dena_scp_cmdautoredemstt_Dena_scp_cmdautoredemstt(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_driver_GMV1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_driver_GMV1(value)
#define vidGET_VALUE_Dena_scp_driver_GMV1(variable)                              Rte_Read_R_Dena_scp_driver_GMV1_Dena_scp_driver_GMV1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_driver_GMV2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_driver_GMV2(value)
#define vidGET_VALUE_Dena_scp_driver_GMV2(variable)                              Rte_Read_R_Dena_scp_driver_GMV2_Dena_scp_driver_GMV2(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_driver_vvt_adm
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_driver_vvt_adm(value)
#define vidGET_VALUE_Dena_scp_driver_vvt_adm(variable)                           Rte_Read_R_Dena_scp_driver_vvt_adm_Dena_scp_driver_vvt_adm(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_driver_vvt_ech
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_driver_vvt_ech(value)
#define vidGET_VALUE_Dena_scp_driver_vvt_ech(variable)                           Rte_Read_R_Dena_scp_driver_vvt_ech_Dena_scp_driver_vvt_ech(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_infomoteurtournant
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_infomoteurtournant(value)
#define vidGET_VALUE_Dena_scp_infomoteurtournant(variable)                       Rte_Read_R_Dena_scp_infomoteurtournant_Dena_scp_infomoteurtournant(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_pompe_ess_pwm
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_pompe_ess_pwm(value)
#define vidGET_VALUE_Dena_scp_pompe_ess_pwm(variable)                            Rte_Read_R_Dena_scp_pompe_ess_pwm_Dena_scp_pompe_ess_pwm(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_relais_puissance
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_relais_puissance(value)
#define vidGET_VALUE_Dena_scp_relais_puissance(variable)                         Rte_Read_R_Dena_scp_relais_puissance_Dena_scp_relais_puissance(&variable)

/**********************************************************************************
   Create interface for variable Dena_scp_sortielogiquedml
  **********************************************************************************/

#define vidSET_VALUE_Dena_scp_sortielogiquedml(value)
#define vidGET_VALUE_Dena_scp_sortielogiquedml(variable)                         Rte_Read_R_Dena_scp_sortielogiquedml_Dena_scp_sortielogiquedml(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_Inj1Cmd(value)
#define vidGET_VALUE_Dena_scw_Inj1Cmd(variable)                                  Rte_Read_R_Dena_scw_Inj1Cmd_Dena_scw_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_Inj2Cmd(value)
#define vidGET_VALUE_Dena_scw_Inj2Cmd(variable)                                  Rte_Read_R_Dena_scw_Inj2Cmd_Dena_scw_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_Inj3Cmd(value)
#define vidGET_VALUE_Dena_scw_Inj3Cmd(variable)                                  Rte_Read_R_Dena_scw_Inj3Cmd_Dena_scw_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_Inj4Cmd(value)
#define vidGET_VALUE_Dena_scw_Inj4Cmd(variable)                                  Rte_Read_R_Dena_scw_Inj4Cmd_Dena_scw_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_cstrdrv
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_cstrdrv(value)
#define vidGET_VALUE_Dena_scw_cstrdrv(variable)                                  Rte_Read_R_Dena_scw_cstrdrv_Dena_scw_cstrdrv(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_drvrseno2ds
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_drvrseno2ds(value)
#define vidGET_VALUE_Dena_scw_drvrseno2ds(variable)                              Rte_Read_R_Dena_scw_drvrseno2ds_Dena_scw_drvrseno2ds(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_drvrseno2us
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_drvrseno2us(value)
#define vidGET_VALUE_Dena_scw_drvrseno2us(variable)                              Rte_Read_R_Dena_scw_drvrseno2us_Dena_scw_drvrseno2us(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_rechauffeurblowby1
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_rechauffeurblowby1(value)
#define vidGET_VALUE_Dena_scw_rechauffeurblowby1(variable)                       Rte_Read_R_Dena_scw_rechauffeurblowby1_Dena_scw_rechauffeurblowby1(&variable)

/**********************************************************************************
   Create interface for variable Dena_scw_rechauffeurblowby2
  **********************************************************************************/

#define vidSET_VALUE_Dena_scw_rechauffeurblowby2(value)
#define vidGET_VALUE_Dena_scw_rechauffeurblowby2(variable)                       Rte_Read_R_Dena_scw_rechauffeurblowby2_Dena_scw_rechauffeurblowby2(&variable)

/**********************************************************************************
   Create interface for variable Dena_surcharge_bpm
  **********************************************************************************/

#define vidSET_VALUE_Dena_surcharge_bpm(value)
#define vidGET_VALUE_Dena_surcharge_bpm(variable)                                Rte_Read_R_Dena_surcharge_bpm_Dena_surcharge_bpm(&variable)

/**********************************************************************************
   Create interface for variable Dft_ComSpi_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dft_ComSpi_ASICGDI(value)
#define vidGET_VALUE_Dft_ComSpi_ASICGDI(variable)                                Rte_Read_R_Dft_ComSpi_ASICGDI_Dft_ComSpi_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dft_OverVBat_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dft_OverVBat_ASICGDI(value)
#define vidGET_VALUE_Dft_OverVBat_ASICGDI(variable)                              Rte_Read_R_Dft_OverVBat_ASICGDI_Dft_OverVBat_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dft_OverVBoost_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dft_OverVBoost_ASICGDI(value)
#define vidGET_VALUE_Dft_OverVBoost_ASICGDI(variable)                            Rte_Read_R_Dft_OverVBoost_ASICGDI_Dft_OverVBoost_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dft_UnderVBat_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dft_UnderVBat_ASICGDI(value)
#define vidGET_VALUE_Dft_UnderVBat_ASICGDI(variable)                             Rte_Read_R_Dft_UnderVBat_ASICGDI_Dft_UnderVBat_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dft_UnderVBoost_ASICGDI
  **********************************************************************************/

#define vidSET_VALUE_Dft_UnderVBoost_ASICGDI(value)
#define vidGET_VALUE_Dft_UnderVBoost_ASICGDI(variable)                           Rte_Read_R_Dft_UnderVBoost_ASICGDI_Dft_UnderVBoost_ASICGDI(&variable)

/**********************************************************************************
   Create interface for variable Dft_chr_excamdiag
  **********************************************************************************/

#define vidSET_VALUE_Dft_chr_excamdiag(value)
#define vidGET_VALUE_Dft_chr_excamdiag(variable)                                 Rte_Read_R_Dft_chr_excamdiag_Dft_chr_excamdiag(&variable)

/**********************************************************************************
   Create interface for variable Dft_chr_incamdiag
  **********************************************************************************/

#define vidSET_VALUE_Dft_chr_incamdiag(value)
#define vidGET_VALUE_Dft_chr_incamdiag(variable)                                 Rte_Read_R_Dft_chr_incamdiag_Dft_chr_incamdiag(&variable)

/**********************************************************************************
   Create interface for variable Dft_composant_bpm
  **********************************************************************************/

#define vidSET_VALUE_Dft_composant_bpm(value)
#define vidGET_VALUE_Dft_composant_bpm(variable)                                 Rte_Read_R_Dft_composant_bpm_Dft_composant_bpm(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_CTP1
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_CTP1(value)
#define vidGET_VALUE_Dft_oc_CTP1(variable)                                       Rte_Read_R_Dft_oc_CTP1_Dft_oc_CTP1(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_CTP2
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_CTP2(value)
#define vidGET_VALUE_Dft_oc_CTP2(variable)                                       Rte_Read_R_Dft_oc_CTP2_Dft_oc_CTP2(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_CtlPmpReq
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_CtlPmpReq(value)
#define vidGET_VALUE_Dft_oc_CtlPmpReq(variable)                                  Rte_Read_R_Dft_oc_CtlPmpReq_Dft_oc_CtlPmpReq(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_DmpVlvCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_DmpVlvCmd(value)
#define vidGET_VALUE_Dft_oc_DmpVlvCmd(variable)                                  Rte_Read_R_Dft_oc_DmpVlvCmd_Dft_oc_DmpVlvCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_HPPmpActCmd(value)
#define vidGET_VALUE_Dft_oc_HPPmpActCmd(variable)                                Rte_Read_R_Dft_oc_HPPmpActCmd_Dft_oc_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_Inj1Cmd(value)
#define vidGET_VALUE_Dft_oc_Inj1Cmd(variable)                                    Rte_Read_R_Dft_oc_Inj1Cmd_Dft_oc_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_Inj2Cmd(value)
#define vidGET_VALUE_Dft_oc_Inj2Cmd(variable)                                    Rte_Read_R_Dft_oc_Inj2Cmd_Dft_oc_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_Inj3Cmd(value)
#define vidGET_VALUE_Dft_oc_Inj3Cmd(variable)                                    Rte_Read_R_Dft_oc_Inj3Cmd_Dft_oc_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_Inj4Cmd(value)
#define vidGET_VALUE_Dft_oc_Inj4Cmd(variable)                                    Rte_Read_R_Dft_oc_Inj4Cmd_Dft_oc_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_OilLvlAcq
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_OilLvlAcq(value)
#define vidGET_VALUE_Dft_oc_OilLvlAcq(variable)                                  Rte_Read_R_Dft_oc_OilLvlAcq_Dft_oc_OilLvlAcq(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_TrbWaPmp
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_TrbWaPmp(value)
#define vidGET_VALUE_Dft_oc_TrbWaPmp(variable)                                   Rte_Read_R_Dft_oc_TrbWaPmp_Dft_oc_TrbWaPmp(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_WgcCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_WgcCmd(value)
#define vidGET_VALUE_Dft_oc_WgcCmd(variable)                                     Rte_Read_R_Dft_oc_WgcCmd_Dft_oc_WgcCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_bobine1
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_bobine1(value)
#define vidGET_VALUE_Dft_oc_bobine1(variable)                                    Rte_Read_R_Dft_oc_bobine1_Dft_oc_bobine1(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_bobine2
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_bobine2(value)
#define vidGET_VALUE_Dft_oc_bobine2(variable)                                    Rte_Read_R_Dft_oc_bobine2_Dft_oc_bobine2(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_bobine3
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_bobine3(value)
#define vidGET_VALUE_Dft_oc_bobine3(variable)                                    Rte_Read_R_Dft_oc_bobine3_Dft_oc_bobine3(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_bobine4
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_bobine4(value)
#define vidGET_VALUE_Dft_oc_bobine4(variable)                                    Rte_Read_R_Dft_oc_bobine4_Dft_oc_bobine4(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_cmd_dmtr
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_cmd_dmtr(value)
#define vidGET_VALUE_Dft_oc_cmd_dmtr(variable)                                   Rte_Read_R_Dft_oc_cmd_dmtr_Dft_oc_cmd_dmtr(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_cmd_relais_principal
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_cmd_relais_principal(value)
#define vidGET_VALUE_Dft_oc_cmd_relais_principal(variable)                       Rte_Read_R_Dft_oc_cmd_relais_principal_Dft_oc_cmd_relais_principal(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_cmdautoredemstt
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_cmdautoredemstt(value)
#define vidGET_VALUE_Dft_oc_cmdautoredemstt(variable)                            Rte_Read_R_Dft_oc_cmdautoredemstt_Dft_oc_cmdautoredemstt(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_cstrdrv
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_cstrdrv(value)
#define vidGET_VALUE_Dft_oc_cstrdrv(variable)                                    Rte_Read_R_Dft_oc_cstrdrv_Dft_oc_cstrdrv(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_driver_GMV1
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_driver_GMV1(value)
#define vidGET_VALUE_Dft_oc_driver_GMV1(variable)                                Rte_Read_R_Dft_oc_driver_GMV1_Dft_oc_driver_GMV1(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_driver_GMV2
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_driver_GMV2(value)
#define vidGET_VALUE_Dft_oc_driver_GMV2(variable)                                Rte_Read_R_Dft_oc_driver_GMV2_Dft_oc_driver_GMV2(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_driver_vvt_adm
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_driver_vvt_adm(value)
#define vidGET_VALUE_Dft_oc_driver_vvt_adm(variable)                             Rte_Read_R_Dft_oc_driver_vvt_adm_Dft_oc_driver_vvt_adm(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_driver_vvt_ech
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_driver_vvt_ech(value)
#define vidGET_VALUE_Dft_oc_driver_vvt_ech(variable)                             Rte_Read_R_Dft_oc_driver_vvt_ech_Dft_oc_driver_vvt_ech(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_drvrseno2ds
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_drvrseno2ds(value)
#define vidGET_VALUE_Dft_oc_drvrseno2ds(variable)                                Rte_Read_R_Dft_oc_drvrseno2ds_Dft_oc_drvrseno2ds(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_drvrseno2us
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_drvrseno2us(value)
#define vidGET_VALUE_Dft_oc_drvrseno2us(variable)                                Rte_Read_R_Dft_oc_drvrseno2us_Dft_oc_drvrseno2us(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_infomoteurtournant
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_infomoteurtournant(value)
#define vidGET_VALUE_Dft_oc_infomoteurtournant(variable)                         Rte_Read_R_Dft_oc_infomoteurtournant_Dft_oc_infomoteurtournant(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_pompe_ess_pwm
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_pompe_ess_pwm(value)
#define vidGET_VALUE_Dft_oc_pompe_ess_pwm(variable)                              Rte_Read_R_Dft_oc_pompe_ess_pwm_Dft_oc_pompe_ess_pwm(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_rechauffeurblowby1
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_rechauffeurblowby1(value)
#define vidGET_VALUE_Dft_oc_rechauffeurblowby1(variable)                         Rte_Read_R_Dft_oc_rechauffeurblowby1_Dft_oc_rechauffeurblowby1(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_rechauffeurblowby2
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_rechauffeurblowby2(value)
#define vidGET_VALUE_Dft_oc_rechauffeurblowby2(variable)                         Rte_Read_R_Dft_oc_rechauffeurblowby2_Dft_oc_rechauffeurblowby2(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_relais_puissance
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_relais_puissance(value)
#define vidGET_VALUE_Dft_oc_relais_puissance(variable)                           Rte_Read_R_Dft_oc_relais_puissance_Dft_oc_relais_puissance(&variable)

/**********************************************************************************
   Create interface for variable Dft_oc_sortielogiquedml
  **********************************************************************************/

#define vidSET_VALUE_Dft_oc_sortielogiquedml(value)
#define vidGET_VALUE_Dft_oc_sortielogiquedml(variable)                           Rte_Read_R_Dft_oc_sortielogiquedml_Dft_oc_sortielogiquedml(&variable)

/**********************************************************************************
   Create interface for variable Dft_ovld_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_ovld_HPPmpActCmd(value)
#define vidGET_VALUE_Dft_ovld_HPPmpActCmd(variable)                              Rte_Read_R_Dft_ovld_HPPmpActCmd_Dft_ovld_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_ovld_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_ovld_Inj1Cmd(value)
#define vidGET_VALUE_Dft_ovld_Inj1Cmd(variable)                                  Rte_Read_R_Dft_ovld_Inj1Cmd_Dft_ovld_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_ovld_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_ovld_Inj2Cmd(value)
#define vidGET_VALUE_Dft_ovld_Inj2Cmd(variable)                                  Rte_Read_R_Dft_ovld_Inj2Cmd_Dft_ovld_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_ovld_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_ovld_Inj3Cmd(value)
#define vidGET_VALUE_Dft_ovld_Inj3Cmd(variable)                                  Rte_Read_R_Dft_ovld_Inj3Cmd_Dft_ovld_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_ovld_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_ovld_Inj4Cmd(value)
#define vidGET_VALUE_Dft_ovld_Inj4Cmd(variable)                                  Rte_Read_R_Dft_ovld_Inj4Cmd_Dft_ovld_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_CTP1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_CTP1(value)
#define vidGET_VALUE_Dft_scg_CTP1(variable)                                      Rte_Read_R_Dft_scg_CTP1_Dft_scg_CTP1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_CTP2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_CTP2(value)
#define vidGET_VALUE_Dft_scg_CTP2(variable)                                      Rte_Read_R_Dft_scg_CTP2_Dft_scg_CTP2(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_CtlPmpReq
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_CtlPmpReq(value)
#define vidGET_VALUE_Dft_scg_CtlPmpReq(variable)                                 Rte_Read_R_Dft_scg_CtlPmpReq_Dft_scg_CtlPmpReq(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_DmpVlvCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_DmpVlvCmd(value)
#define vidGET_VALUE_Dft_scg_DmpVlvCmd(variable)                                 Rte_Read_R_Dft_scg_DmpVlvCmd_Dft_scg_DmpVlvCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_HPPmpActCmd(value)
#define vidGET_VALUE_Dft_scg_HPPmpActCmd(variable)                               Rte_Read_R_Dft_scg_HPPmpActCmd_Dft_scg_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_Inj1Cmd(value)
#define vidGET_VALUE_Dft_scg_Inj1Cmd(variable)                                   Rte_Read_R_Dft_scg_Inj1Cmd_Dft_scg_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_Inj2Cmd(value)
#define vidGET_VALUE_Dft_scg_Inj2Cmd(variable)                                   Rte_Read_R_Dft_scg_Inj2Cmd_Dft_scg_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_Inj3Cmd(value)
#define vidGET_VALUE_Dft_scg_Inj3Cmd(variable)                                   Rte_Read_R_Dft_scg_Inj3Cmd_Dft_scg_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_Inj4Cmd(value)
#define vidGET_VALUE_Dft_scg_Inj4Cmd(variable)                                   Rte_Read_R_Dft_scg_Inj4Cmd_Dft_scg_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_OilLvlAcq
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_OilLvlAcq(value)
#define vidGET_VALUE_Dft_scg_OilLvlAcq(variable)                                 Rte_Read_R_Dft_scg_OilLvlAcq_Dft_scg_OilLvlAcq(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_TrbWaPmp
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_TrbWaPmp(value)
#define vidGET_VALUE_Dft_scg_TrbWaPmp(variable)                                  Rte_Read_R_Dft_scg_TrbWaPmp_Dft_scg_TrbWaPmp(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_WgcCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_WgcCmd(value)
#define vidGET_VALUE_Dft_scg_WgcCmd(variable)                                    Rte_Read_R_Dft_scg_WgcCmd_Dft_scg_WgcCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_bobine1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_bobine1(value)
#define vidGET_VALUE_Dft_scg_bobine1(variable)                                   Rte_Read_R_Dft_scg_bobine1_Dft_scg_bobine1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_bobine2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_bobine2(value)
#define vidGET_VALUE_Dft_scg_bobine2(variable)                                   Rte_Read_R_Dft_scg_bobine2_Dft_scg_bobine2(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_bobine3
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_bobine3(value)
#define vidGET_VALUE_Dft_scg_bobine3(variable)                                   Rte_Read_R_Dft_scg_bobine3_Dft_scg_bobine3(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_bobine4
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_bobine4(value)
#define vidGET_VALUE_Dft_scg_bobine4(variable)                                   Rte_Read_R_Dft_scg_bobine4_Dft_scg_bobine4(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_cmd_dmtr
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_cmd_dmtr(value)
#define vidGET_VALUE_Dft_scg_cmd_dmtr(variable)                                  Rte_Read_R_Dft_scg_cmd_dmtr_Dft_scg_cmd_dmtr(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_cmd_relais_principal
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_cmd_relais_principal(value)
#define vidGET_VALUE_Dft_scg_cmd_relais_principal(variable)                      Rte_Read_R_Dft_scg_cmd_relais_principal_Dft_scg_cmd_relais_principal(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_cmdautoredemstt
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_cmdautoredemstt(value)
#define vidGET_VALUE_Dft_scg_cmdautoredemstt(variable)                           Rte_Read_R_Dft_scg_cmdautoredemstt_Dft_scg_cmdautoredemstt(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_cstrdrv
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_cstrdrv(value)
#define vidGET_VALUE_Dft_scg_cstrdrv(variable)                                   Rte_Read_R_Dft_scg_cstrdrv_Dft_scg_cstrdrv(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_driver_GMV1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_driver_GMV1(value)
#define vidGET_VALUE_Dft_scg_driver_GMV1(variable)                               Rte_Read_R_Dft_scg_driver_GMV1_Dft_scg_driver_GMV1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_driver_GMV2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_driver_GMV2(value)
#define vidGET_VALUE_Dft_scg_driver_GMV2(variable)                               Rte_Read_R_Dft_scg_driver_GMV2_Dft_scg_driver_GMV2(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_driver_vvt_adm
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_driver_vvt_adm(value)
#define vidGET_VALUE_Dft_scg_driver_vvt_adm(variable)                            Rte_Read_R_Dft_scg_driver_vvt_adm_Dft_scg_driver_vvt_adm(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_driver_vvt_ech
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_driver_vvt_ech(value)
#define vidGET_VALUE_Dft_scg_driver_vvt_ech(variable)                            Rte_Read_R_Dft_scg_driver_vvt_ech_Dft_scg_driver_vvt_ech(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_drvrseno2ds
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_drvrseno2ds(value)
#define vidGET_VALUE_Dft_scg_drvrseno2ds(variable)                               Rte_Read_R_Dft_scg_drvrseno2ds_Dft_scg_drvrseno2ds(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_drvrseno2us
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_drvrseno2us(value)
#define vidGET_VALUE_Dft_scg_drvrseno2us(variable)                               Rte_Read_R_Dft_scg_drvrseno2us_Dft_scg_drvrseno2us(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_infomoteurtournant
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_infomoteurtournant(value)
#define vidGET_VALUE_Dft_scg_infomoteurtournant(variable)                        Rte_Read_R_Dft_scg_infomoteurtournant_Dft_scg_infomoteurtournant(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_pompe_ess_pwm
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_pompe_ess_pwm(value)
#define vidGET_VALUE_Dft_scg_pompe_ess_pwm(variable)                             Rte_Read_R_Dft_scg_pompe_ess_pwm_Dft_scg_pompe_ess_pwm(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_rechauffeurblowby1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_rechauffeurblowby1(value)
#define vidGET_VALUE_Dft_scg_rechauffeurblowby1(variable)                        Rte_Read_R_Dft_scg_rechauffeurblowby1_Dft_scg_rechauffeurblowby1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_rechauffeurblowby2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_rechauffeurblowby2(value)
#define vidGET_VALUE_Dft_scg_rechauffeurblowby2(variable)                        Rte_Read_R_Dft_scg_rechauffeurblowby2_Dft_scg_rechauffeurblowby2(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_relais_puissance
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_relais_puissance(value)
#define vidGET_VALUE_Dft_scg_relais_puissance(variable)                          Rte_Read_R_Dft_scg_relais_puissance_Dft_scg_relais_puissance(&variable)

/**********************************************************************************
   Create interface for variable Dft_scg_sortielogiquedml
  **********************************************************************************/

#define vidSET_VALUE_Dft_scg_sortielogiquedml(value)
#define vidGET_VALUE_Dft_scg_sortielogiquedml(variable)                          Rte_Read_R_Dft_scg_sortielogiquedml_Dft_scg_sortielogiquedml(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_CTP1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_CTP1(value)
#define vidGET_VALUE_Dft_scp_CTP1(variable)                                      Rte_Read_R_Dft_scp_CTP1_Dft_scp_CTP1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_CTP2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_CTP2(value)
#define vidGET_VALUE_Dft_scp_CTP2(variable)                                      Rte_Read_R_Dft_scp_CTP2_Dft_scp_CTP2(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_CtlPmpReq
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_CtlPmpReq(value)
#define vidGET_VALUE_Dft_scp_CtlPmpReq(variable)                                 Rte_Read_R_Dft_scp_CtlPmpReq_Dft_scp_CtlPmpReq(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_DmpVlvCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_DmpVlvCmd(value)
#define vidGET_VALUE_Dft_scp_DmpVlvCmd(variable)                                 Rte_Read_R_Dft_scp_DmpVlvCmd_Dft_scp_DmpVlvCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_HPPmpActCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_HPPmpActCmd(value)
#define vidGET_VALUE_Dft_scp_HPPmpActCmd(variable)                               Rte_Read_R_Dft_scp_HPPmpActCmd_Dft_scp_HPPmpActCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_OilLvlAcq
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_OilLvlAcq(value)
#define vidGET_VALUE_Dft_scp_OilLvlAcq(variable)                                 Rte_Read_R_Dft_scp_OilLvlAcq_Dft_scp_OilLvlAcq(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_TrbWaPmp
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_TrbWaPmp(value)
#define vidGET_VALUE_Dft_scp_TrbWaPmp(variable)                                  Rte_Read_R_Dft_scp_TrbWaPmp_Dft_scp_TrbWaPmp(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_WgcCmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_WgcCmd(value)
#define vidGET_VALUE_Dft_scp_WgcCmd(variable)                                    Rte_Read_R_Dft_scp_WgcCmd_Dft_scp_WgcCmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_bobine1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_bobine1(value)
#define vidGET_VALUE_Dft_scp_bobine1(variable)                                   Rte_Read_R_Dft_scp_bobine1_Dft_scp_bobine1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_bobine2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_bobine2(value)
#define vidGET_VALUE_Dft_scp_bobine2(variable)                                   Rte_Read_R_Dft_scp_bobine2_Dft_scp_bobine2(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_bobine3
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_bobine3(value)
#define vidGET_VALUE_Dft_scp_bobine3(variable)                                   Rte_Read_R_Dft_scp_bobine3_Dft_scp_bobine3(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_bobine4
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_bobine4(value)
#define vidGET_VALUE_Dft_scp_bobine4(variable)                                   Rte_Read_R_Dft_scp_bobine4_Dft_scp_bobine4(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_cmd_dmtr
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_cmd_dmtr(value)
#define vidGET_VALUE_Dft_scp_cmd_dmtr(variable)                                  Rte_Read_R_Dft_scp_cmd_dmtr_Dft_scp_cmd_dmtr(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_cmd_relais_principal
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_cmd_relais_principal(value)
#define vidGET_VALUE_Dft_scp_cmd_relais_principal(variable)                      Rte_Read_R_Dft_scp_cmd_relais_principal_Dft_scp_cmd_relais_principal(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_cmdautoredemstt
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_cmdautoredemstt(value)
#define vidGET_VALUE_Dft_scp_cmdautoredemstt(variable)                           Rte_Read_R_Dft_scp_cmdautoredemstt_Dft_scp_cmdautoredemstt(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_driver_GMV1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_driver_GMV1(value)
#define vidGET_VALUE_Dft_scp_driver_GMV1(variable)                               Rte_Read_R_Dft_scp_driver_GMV1_Dft_scp_driver_GMV1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_driver_GMV2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_driver_GMV2(value)
#define vidGET_VALUE_Dft_scp_driver_GMV2(variable)                               Rte_Read_R_Dft_scp_driver_GMV2_Dft_scp_driver_GMV2(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_driver_vvt_adm
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_driver_vvt_adm(value)
#define vidGET_VALUE_Dft_scp_driver_vvt_adm(variable)                            Rte_Read_R_Dft_scp_driver_vvt_adm_Dft_scp_driver_vvt_adm(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_driver_vvt_ech
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_driver_vvt_ech(value)
#define vidGET_VALUE_Dft_scp_driver_vvt_ech(variable)                            Rte_Read_R_Dft_scp_driver_vvt_ech_Dft_scp_driver_vvt_ech(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_infomoteurtournant
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_infomoteurtournant(value)
#define vidGET_VALUE_Dft_scp_infomoteurtournant(variable)                        Rte_Read_R_Dft_scp_infomoteurtournant_Dft_scp_infomoteurtournant(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_pompe_ess_pwm
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_pompe_ess_pwm(value)
#define vidGET_VALUE_Dft_scp_pompe_ess_pwm(variable)                             Rte_Read_R_Dft_scp_pompe_ess_pwm_Dft_scp_pompe_ess_pwm(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_relais_puissance
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_relais_puissance(value)
#define vidGET_VALUE_Dft_scp_relais_puissance(variable)                          Rte_Read_R_Dft_scp_relais_puissance_Dft_scp_relais_puissance(&variable)

/**********************************************************************************
   Create interface for variable Dft_scp_sortielogiquedml
  **********************************************************************************/

#define vidSET_VALUE_Dft_scp_sortielogiquedml(value)
#define vidGET_VALUE_Dft_scp_sortielogiquedml(variable)                          Rte_Read_R_Dft_scp_sortielogiquedml_Dft_scp_sortielogiquedml(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_Inj1Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_Inj1Cmd(value)
#define vidGET_VALUE_Dft_scw_Inj1Cmd(variable)                                   Rte_Read_R_Dft_scw_Inj1Cmd_Dft_scw_Inj1Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_Inj2Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_Inj2Cmd(value)
#define vidGET_VALUE_Dft_scw_Inj2Cmd(variable)                                   Rte_Read_R_Dft_scw_Inj2Cmd_Dft_scw_Inj2Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_Inj3Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_Inj3Cmd(value)
#define vidGET_VALUE_Dft_scw_Inj3Cmd(variable)                                   Rte_Read_R_Dft_scw_Inj3Cmd_Dft_scw_Inj3Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_Inj4Cmd
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_Inj4Cmd(value)
#define vidGET_VALUE_Dft_scw_Inj4Cmd(variable)                                   Rte_Read_R_Dft_scw_Inj4Cmd_Dft_scw_Inj4Cmd(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_cstrdrv
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_cstrdrv(value)
#define vidGET_VALUE_Dft_scw_cstrdrv(variable)                                   Rte_Read_R_Dft_scw_cstrdrv_Dft_scw_cstrdrv(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_drvrseno2ds
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_drvrseno2ds(value)
#define vidGET_VALUE_Dft_scw_drvrseno2ds(variable)                               Rte_Read_R_Dft_scw_drvrseno2ds_Dft_scw_drvrseno2ds(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_drvrseno2us
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_drvrseno2us(value)
#define vidGET_VALUE_Dft_scw_drvrseno2us(variable)                               Rte_Read_R_Dft_scw_drvrseno2us_Dft_scw_drvrseno2us(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_rechauffeurblowby1
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_rechauffeurblowby1(value)
#define vidGET_VALUE_Dft_scw_rechauffeurblowby1(variable)                        Rte_Read_R_Dft_scw_rechauffeurblowby1_Dft_scw_rechauffeurblowby1(&variable)

/**********************************************************************************
   Create interface for variable Dft_scw_rechauffeurblowby2
  **********************************************************************************/

#define vidSET_VALUE_Dft_scw_rechauffeurblowby2(value)
#define vidGET_VALUE_Dft_scw_rechauffeurblowby2(variable)                        Rte_Read_R_Dft_scw_rechauffeurblowby2_Dft_scw_rechauffeurblowby2(&variable)

/**********************************************************************************
   Create interface for variable Dft_surcharge_bpm
  **********************************************************************************/

#define vidSET_VALUE_Dft_surcharge_bpm(value)
#define vidGET_VALUE_Dft_surcharge_bpm(variable)                                 Rte_Read_R_Dft_surcharge_bpm_Dft_surcharge_bpm(&variable)

/**********************************************************************************
   Create interface for variable DfwCtl_bInhInjProtDfw
  **********************************************************************************/

#define vidSET_VALUE_DfwCtl_bInhInjProtDfw(value)
#define vidGET_VALUE_DfwCtl_bInhInjProtDfw(variable)                             Rte_Read_R_DfwCtl_bInhInjProtDfw_DfwCtl_bInhInjProtDfw(&variable)

/**********************************************************************************
   Create interface for variable DfwCtl_noOverOscDetProtAcv
  **********************************************************************************/

#define vidSET_VALUE_DfwCtl_noOverOscDetProtAcv(value)
#define vidGET_VALUE_DfwCtl_noOverOscDetProtAcv(variable)                        Rte_Read_R_DfwCtl_noOverOscDetProtAcv_DfwCtl_noOverOscDetProtAcv(&variable)

/**********************************************************************************
   Create interface for variable DfwCtl_noProtAdp
  **********************************************************************************/

#define vidSET_VALUE_DfwCtl_noProtAdp(value)
#define vidGET_VALUE_DfwCtl_noProtAdp(variable)                                  Rte_Read_R_DfwCtl_noProtAdp_DfwCtl_noProtAdp(&variable)

/**********************************************************************************
   Create interface for variable Diag_elec_ectdrv
  **********************************************************************************/

#define vidSET_VALUE_Diag_elec_ectdrv(value)
#define vidGET_VALUE_Diag_elec_ectdrv(variable)                                  Rte_Read_R_Diag_elec_ectdrv_Diag_elec_ectdrv(&variable)

/**********************************************************************************
   Create interface for variable ECU_bAuthVSCtlIni
  **********************************************************************************/

#define vidSET_VALUE_ECU_bAuthVSCtlIni(value)                                    Rte_Write_P_ECU_bAuthVSCtlIni_ECU_bAuthVSCtlIni(value)
#define vidGET_VALUE_ECU_bAuthVSCtlIni(variable)                                 Rte_Read_R_ECU_bAuthVSCtlIni_ECU_bAuthVSCtlIni(&variable)

/**********************************************************************************
   Create interface for variable ECU_bImmoUnlockWkuSt
  **********************************************************************************/

#define vidSET_VALUE_ECU_bImmoUnlockWkuSt(value)                                 Rte_Write_P_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt(value)
#define vidGET_VALUE_ECU_bImmoUnlockWkuSt(variable)                              Rte_Read_R_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt(&variable)

/**********************************************************************************
   Create interface for variable ECU_bWkuChDchaUcap
  **********************************************************************************/

#define vidSET_VALUE_ECU_bWkuChDchaUcap(value)                                   Rte_Write_P_ECU_bWkuChDchaUcap_ECU_bWkuChDchaUcap(value)
#define vidGET_VALUE_ECU_bWkuChDchaUcap(variable)                                Rte_Read_R_ECU_bWkuChDchaUcap_ECU_bWkuChDchaUcap(&variable)

/**********************************************************************************
   Create interface for variable ECU_bWkuMain
  **********************************************************************************/

#define vidSET_VALUE_ECU_bWkuMain(value)                                         Rte_Write_P_ECU_bWkuMain_ECU_bWkuMain(value)
#define vidGET_VALUE_ECU_bWkuMain(variable)                                      Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&variable)

/**********************************************************************************
   Create interface for variable ECU_stPwrECU
  **********************************************************************************/

#define vidSET_VALUE_ECU_stPwrECU(value)                                         Rte_Write_P_ECU_stPwrECU_ECU_stPwrECU(value)
#define vidGET_VALUE_ECU_stPwrECU(variable)                                      Rte_Read_R_ECU_stPwrECU_ECU_stPwrECU(&variable)

/**********************************************************************************
   Create interface for variable EGRSys_rEGRReq
  **********************************************************************************/

#define vidSET_VALUE_EGRSys_rEGRReq(value)                                       Rte_Write_P_EGRSys_rEGRReq_EGRSys_rEGRReq(value)
#define vidGET_VALUE_EGRSys_rEGRReq(variable)                                    Rte_Read_R_EGRSys_rEGRReq_EGRSys_rEGRReq(&variable)

/**********************************************************************************
   Create interface for variable EGRVlv_rOpClsEGRVlvBol
  **********************************************************************************/

#define vidSET_VALUE_EGRVlv_rOpClsEGRVlvBol(value)                               Rte_Write_P_EGRVlv_rOpClsEGRVlvBol_EGRVlv_rOpClsEGRVlvBol(value)
#define vidGET_VALUE_EGRVlv_rOpClsEGRVlvBol(variable)                            Rte_Read_R_EGRVlv_rOpClsEGRVlvBol_EGRVlv_rOpClsEGRVlvBol(&variable)

/**********************************************************************************
   Create interface for variable EOM_bTWCHeatPha
  **********************************************************************************/

#define vidSET_VALUE_EOM_bTWCHeatPha(value)
#define vidGET_VALUE_EOM_bTWCHeatPha(variable)                                   Rte_Read_R_EOM_bTWCHeatPha_EOM_bTWCHeatPha(&variable)

/**********************************************************************************
   Create interface for variable EOM_bTranMod
  **********************************************************************************/

#define vidSET_VALUE_EOM_bTranMod(value)
#define vidGET_VALUE_EOM_bTranMod(variable)                                      Rte_Read_R_EOM_bTranMod_EOM_bTranMod(&variable)

/**********************************************************************************
   Create interface for array EOM_prm_facBasModCur
  **********************************************************************************/

#define vidSET_ARRAY_EOM_prm_facBasModCur(value,size)
#define vidGET_ARRAY_EOM_prm_facBasModCur(variable,size)                         Rte_Read_R_EOM_prm_facBasModCur_EOM_prm_facBasModCur(&variable)

#define vidSET_ARRAY_ELEMENT_EOM_prm_facBasModCur(variable,pos)
#define vidGET_ARRAY_ELEMENT_EOM_prm_facBasModCur(variable,pos){ \
  if (pos < 16)\
  { \
     DT_EOM_prm_facBasModCur datatemp[16];\
     Rte_Read_R_EOM_prm_facBasModCur_EOM_prm_facBasModCur(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EOM_prm_facBasModTar
  **********************************************************************************/

#define vidSET_ARRAY_EOM_prm_facBasModTar(value,size)
#define vidGET_ARRAY_EOM_prm_facBasModTar(variable,size)                         Rte_Read_R_EOM_prm_facBasModTar_EOM_prm_facBasModTar(&variable)

#define vidSET_ARRAY_ELEMENT_EOM_prm_facBasModTar(variable,pos)
#define vidGET_ARRAY_ELEMENT_EOM_prm_facBasModTar(variable,pos){ \
  if (pos < 16)\
  { \
     DT_EOM_prm_facBasModTar datatemp[16];\
     Rte_Read_R_EOM_prm_facBasModTar_EOM_prm_facBasModTar(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EOM_prm_facTranMod
  **********************************************************************************/

#define vidSET_ARRAY_EOM_prm_facTranMod(value,size)
#define vidGET_ARRAY_EOM_prm_facTranMod(variable,size)                           Rte_Read_R_EOM_prm_facTranMod_EOM_prm_facTranMod(&variable)

#define vidSET_ARRAY_ELEMENT_EOM_prm_facTranMod(variable,pos)
#define vidGET_ARRAY_ELEMENT_EOM_prm_facTranMod(variable,pos){ \
  if (pos < 16)\
  { \
     DT_EOM_prm_facTranMod datatemp[16];\
     Rte_Read_R_EOM_prm_facTranMod_EOM_prm_facTranMod(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EOM_prm_idxBas1ModCur
  **********************************************************************************/

#define vidSET_ARRAY_EOM_prm_idxBas1ModCur(value,size)
#define vidGET_ARRAY_EOM_prm_idxBas1ModCur(variable,size)                        Rte_Read_R_EOM_prm_idxBas1ModCur_EOM_prm_idxBas1ModCur(&variable)

#define vidSET_ARRAY_ELEMENT_EOM_prm_idxBas1ModCur(variable,pos)
#define vidGET_ARRAY_ELEMENT_EOM_prm_idxBas1ModCur(variable,pos){ \
  if (pos < 16)\
  { \
     DT_EOM_prm_idxBas1ModCur datatemp[16];\
     Rte_Read_R_EOM_prm_idxBas1ModCur_EOM_prm_idxBas1ModCur(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EOM_prm_idxBas1ModTar
  **********************************************************************************/

#define vidSET_ARRAY_EOM_prm_idxBas1ModTar(value,size)
#define vidGET_ARRAY_EOM_prm_idxBas1ModTar(variable,size)                        Rte_Read_R_EOM_prm_idxBas1ModTar_EOM_prm_idxBas1ModTar(&variable)

#define vidSET_ARRAY_ELEMENT_EOM_prm_idxBas1ModTar(variable,pos)
#define vidGET_ARRAY_ELEMENT_EOM_prm_idxBas1ModTar(variable,pos){ \
  if (pos < 16)\
  { \
     DT_EOM_prm_idxBas1ModTar datatemp[16];\
     Rte_Read_R_EOM_prm_idxBas1ModTar_EOM_prm_idxBas1ModTar(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EOM_prm_idxBas2ModCur
  **********************************************************************************/

#define vidSET_ARRAY_EOM_prm_idxBas2ModCur(value,size)
#define vidGET_ARRAY_EOM_prm_idxBas2ModCur(variable,size)                        Rte_Read_R_EOM_prm_idxBas2ModCur_EOM_prm_idxBas2ModCur(&variable)

#define vidSET_ARRAY_ELEMENT_EOM_prm_idxBas2ModCur(variable,pos)
#define vidGET_ARRAY_ELEMENT_EOM_prm_idxBas2ModCur(variable,pos){ \
  if (pos < 16)\
  { \
     DT_EOM_prm_idxBas2ModCur datatemp[16];\
     Rte_Read_R_EOM_prm_idxBas2ModCur_EOM_prm_idxBas2ModCur(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EOM_prm_idxBas2ModTar
  **********************************************************************************/

#define vidSET_ARRAY_EOM_prm_idxBas2ModTar(value,size)
#define vidGET_ARRAY_EOM_prm_idxBas2ModTar(variable,size)                        Rte_Read_R_EOM_prm_idxBas2ModTar_EOM_prm_idxBas2ModTar(&variable)

#define vidSET_ARRAY_ELEMENT_EOM_prm_idxBas2ModTar(variable,pos)
#define vidGET_ARRAY_ELEMENT_EOM_prm_idxBas2ModTar(variable,pos){ \
  if (pos < 16)\
  { \
     DT_EOM_prm_idxBas2ModTar datatemp[16];\
     Rte_Read_R_EOM_prm_idxBas2ModTar_EOM_prm_idxBas2ModTar(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable EOM_tiEngCrankStrt
  **********************************************************************************/

#define vidSET_VALUE_EOM_tiEngCrankStrt(value)
#define vidGET_VALUE_EOM_tiEngCrankStrt(variable)                                Rte_Read_R_EOM_tiEngCrankStrt_EOM_tiEngCrankStrt(&variable)

/**********************************************************************************
   Create interface for variable EOM_tiEngModStp
  **********************************************************************************/

#define vidSET_VALUE_EOM_tiEngModStp(value)
#define vidGET_VALUE_EOM_tiEngModStp(variable)                                   Rte_Read_R_EOM_tiEngModStp_EOM_tiEngModStp(&variable)

/**********************************************************************************
   Create interface for variable EOM_tiEngRun
  **********************************************************************************/

#define vidSET_VALUE_EOM_tiEngRun(value)
#define vidGET_VALUE_EOM_tiEngRun(variable)                                      Rte_Read_R_EOM_tiEngRun_EOM_tiEngRun(&variable)

/**********************************************************************************
   Create interface for variable EOM_tiEngRunStrt
  **********************************************************************************/

#define vidSET_VALUE_EOM_tiEngRunStrt(value)
#define vidGET_VALUE_EOM_tiEngRunStrt(variable)                                  Rte_Read_R_EOM_tiEngRunStrt_EOM_tiEngRunStrt(&variable)

/**********************************************************************************
   Create interface for variable EOM_tiEngStop
  **********************************************************************************/

#define vidSET_VALUE_EOM_tiEngStop(value)                                        Rte_Write_P_EOM_tiEngStop_EOM_tiEngStop(value)
#define vidGET_VALUE_EOM_tiEngStop(variable)                                     Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&variable)

/**********************************************************************************
   Create interface for variable EOM_tiEngStopRst
  **********************************************************************************/

#define vidSET_VALUE_EOM_tiEngStopRst(value)                                     Rte_Write_P_EOM_tiEngStopRst_EOM_tiEngStopRst(value)
#define vidGET_VALUE_EOM_tiEngStopRst(variable)                                  Rte_Read_R_EOM_tiEngStopRst_EOM_tiEngStopRst(&variable)

/**********************************************************************************
   Create interface for variable ESLim_bAcvEngSpdLim
  **********************************************************************************/

#define vidSET_VALUE_ESLim_bAcvEngSpdLim(value)
#define vidGET_VALUE_ESLim_bAcvEngSpdLim(variable)                               Rte_Read_R_ESLim_bAcvEngSpdLim_ESLim_bAcvEngSpdLim(&variable)

/**********************************************************************************
   Create interface for variable ESLim_bAcvTrqLim
  **********************************************************************************/

#define vidSET_VALUE_ESLim_bAcvTrqLim(value)                                     Rte_Write_P_ESLim_bAcvTrqLim_ESLim_bAcvTrqLim(value)
#define vidGET_VALUE_ESLim_bAcvTrqLim(variable)                                  Rte_Read_R_ESLim_bAcvTrqLim_ESLim_bAcvTrqLim(&variable)

/**********************************************************************************
   Create interface for variable ESLim_nLoFuCutOff
  **********************************************************************************/

#define vidSET_VALUE_ESLim_nLoFuCutOff(value)                                    Rte_Write_P_ESLim_nLoFuCutOff_ESLim_nLoFuCutOff(value)
#define vidGET_VALUE_ESLim_nLoFuCutOff(variable)                                 Rte_Read_R_ESLim_nLoFuCutOff_ESLim_nLoFuCutOff(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvCordT_002_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvCordT_002_DRE(value)                                  Rte_Write_P_EV_AdvCordT_002_DRE_EV_AdvCordT_002_DRE(value)
#define vidGET_VALUE_EV_AdvCordT_002_DRE(variable)                               Rte_Read_R_EV_AdvCordT_002_DRE_EV_AdvCordT_002_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvCordT_005_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvCordT_005_DRE(value)                                  Rte_Write_P_EV_AdvCordT_005_DRE_EV_AdvCordT_005_DRE(value)
#define vidGET_VALUE_EV_AdvCordT_005_DRE(variable)                               Rte_Read_R_EV_AdvCordT_005_DRE_EV_AdvCordT_005_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvCordT_007_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvCordT_007_DRE(value)                                  Rte_Write_P_EV_AdvCordT_007_DRE_EV_AdvCordT_007_DRE(value)
#define vidGET_VALUE_EV_AdvCordT_007_DRE(variable)                               Rte_Read_R_EV_AdvCordT_007_DRE_EV_AdvCordT_007_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvMaxT_002_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvMaxT_002_DRE(value)                                   Rte_Write_P_EV_AdvMaxT_002_DRE_EV_AdvMaxT_002_DRE(value)
#define vidGET_VALUE_EV_AdvMaxT_002_DRE(variable)                                Rte_Read_R_EV_AdvMaxT_002_DRE_EV_AdvMaxT_002_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvMinT_002_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvMinT_002_DRE(value)                                   Rte_Write_P_EV_AdvMinT_002_DRE_EV_AdvMinT_002_DRE(value)
#define vidGET_VALUE_EV_AdvMinT_002_DRE(variable)                                Rte_Read_R_EV_AdvMinT_002_DRE_EV_AdvMinT_002_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvMinT_006_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvMinT_006_DRE(value)                                   Rte_Write_P_EV_AdvMinT_006_DRE_EV_AdvMinT_006_DRE(value)
#define vidGET_VALUE_EV_AdvMinT_006_DRE(variable)                                Rte_Read_R_EV_AdvMinT_006_DRE_EV_AdvMinT_006_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvMinT_008_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvMinT_008_DRE(value)                                   Rte_Write_P_EV_AdvMinT_008_DRE_EV_AdvMinT_008_DRE(value)
#define vidGET_VALUE_EV_AdvMinT_008_DRE(variable)                                Rte_Read_R_EV_AdvMinT_008_DRE_EV_AdvMinT_008_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvOptmT_002_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvOptmT_002_DRE(value)                                  Rte_Write_P_EV_AdvOptmT_002_DRE_EV_AdvOptmT_002_DRE(value)
#define vidGET_VALUE_EV_AdvOptmT_002_DRE(variable)                               Rte_Read_R_EV_AdvOptmT_002_DRE_EV_AdvOptmT_002_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvOptmT_003_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvOptmT_003_DRE(value)                                  Rte_Write_P_EV_AdvOptmT_003_DRE_EV_AdvOptmT_003_DRE(value)
#define vidGET_VALUE_EV_AdvOptmT_003_DRE(variable)                               Rte_Read_R_EV_AdvOptmT_003_DRE_EV_AdvOptmT_003_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvPrevKnkT_002
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvPrevKnkT_002(value)                                   Rte_Write_P_EV_AdvPrevKnkT_002_EV_AdvPrevKnkT_002(value)
#define vidGET_VALUE_EV_AdvPrevKnkT_002(variable)                                Rte_Read_R_EV_AdvPrevKnkT_002_EV_AdvPrevKnkT_002(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvSpT_002_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvSpT_002_DRE(value)                                    Rte_Write_P_EV_AdvSpT_002_DRE_EV_AdvSpT_002_DRE(value)
#define vidGET_VALUE_EV_AdvSpT_002_DRE(variable)                                 Rte_Read_R_EV_AdvSpT_002_DRE_EV_AdvSpT_002_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvSpT_004_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvSpT_004_DRE(value)                                    Rte_Write_P_EV_AdvSpT_004_DRE_EV_AdvSpT_004_DRE(value)
#define vidGET_VALUE_EV_AdvSpT_004_DRE(variable)                                 Rte_Read_R_EV_AdvSpT_004_DRE_EV_AdvSpT_004_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_AdvSpT_006_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_AdvSpT_006_DRE(value)                                    Rte_Write_P_EV_AdvSpT_006_DRE_EV_AdvSpT_006_DRE(value)
#define vidGET_VALUE_EV_AdvSpT_006_DRE(variable)                                 Rte_Read_R_EV_AdvSpT_006_DRE_EV_AdvSpT_006_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_CoTq_011_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_CoTq_011_DRE(value)                                      Rte_Write_P_EV_CoTq_011_DRE_EV_CoTq_011_DRE(value)
#define vidGET_VALUE_EV_CoTq_011_DRE(variable)                                   Rte_Read_R_EV_CoTq_011_DRE_EV_CoTq_011_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_EngLimTqT_002_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_EngLimTqT_002_DRE(value)                                 Rte_Write_P_EV_EngLimTqT_002_DRE_EV_EngLimTqT_002_DRE(value)
#define vidGET_VALUE_EV_EngLimTqT_002_DRE(variable)                              Rte_Read_R_EV_EngLimTqT_002_DRE_EV_EngLimTqT_002_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_EngLimTqT_004_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_EngLimTqT_004_DRE(value)                                 Rte_Write_P_EV_EngLimTqT_004_DRE_EV_EngLimTqT_004_DRE(value)
#define vidGET_VALUE_EV_EngLimTqT_004_DRE(variable)                              Rte_Read_R_EV_EngLimTqT_004_DRE_EV_EngLimTqT_004_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_EngLimTqT_006_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_EngLimTqT_006_DRE(value)                                 Rte_Write_P_EV_EngLimTqT_006_DRE_EV_EngLimTqT_006_DRE(value)
#define vidGET_VALUE_EV_EngLimTqT_006_DRE(variable)                              Rte_Read_R_EV_EngLimTqT_006_DRE_EV_EngLimTqT_006_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_EngLimTqT_008_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_EngLimTqT_008_DRE(value)                                 Rte_Write_P_EV_EngLimTqT_008_DRE_EV_EngLimTqT_008_DRE(value)
#define vidGET_VALUE_EV_EngLimTqT_008_DRE(variable)                              Rte_Read_R_EV_EngLimTqT_008_DRE_EV_EngLimTqT_008_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_EngLimTqT_012_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_EngLimTqT_012_DRE(value)                                 Rte_Write_P_EV_EngLimTqT_012_DRE_EV_EngLimTqT_012_DRE(value)
#define vidGET_VALUE_EV_EngLimTqT_012_DRE(variable)                              Rte_Read_R_EV_EngLimTqT_012_DRE_EV_EngLimTqT_012_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_EngLimTqT_014_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_EngLimTqT_014_DRE(value)                                 Rte_Write_P_EV_EngLimTqT_014_DRE_EV_EngLimTqT_014_DRE(value)
#define vidGET_VALUE_EV_EngLimTqT_014_DRE(variable)                              Rte_Read_R_EV_EngLimTqT_014_DRE_EV_EngLimTqT_014_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_FISA_CrankSync
  **********************************************************************************/

#define vidSET_VALUE_EV_FISA_CrankSync(value)                                    Rte_Write_P_EV_FISA_CrankSync_EV_FISA_CrankSync(value)
#define vidGET_VALUE_EV_FISA_CrankSync(variable)                                 Rte_Read_R_EV_FISA_CrankSync_EV_FISA_CrankSync(&variable)

/**********************************************************************************
   Create interface for variable EV_InMdlT_013_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_InMdlT_013_DRE(value)                                    Rte_Write_P_EV_InMdlT_013_DRE_EV_InMdlT_013_DRE(value)
#define vidGET_VALUE_EV_InMdlT_013_DRE(variable)                                 Rte_Read_R_EV_InMdlT_013_DRE_EV_InMdlT_013_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_InMdlT_015_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_InMdlT_015_DRE(value)                                    Rte_Write_P_EV_InMdlT_015_DRE_EV_InMdlT_015_DRE(value)
#define vidGET_VALUE_EV_InMdlT_015_DRE(variable)                                 Rte_Read_R_EV_InMdlT_015_DRE_EV_InMdlT_015_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_InMdlT_024_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_InMdlT_024_DRE(value)                                    Rte_Write_P_EV_InMdlT_024_DRE_EV_InMdlT_024_DRE(value)
#define vidGET_VALUE_EV_InMdlT_024_DRE(variable)                                 Rte_Read_R_EV_InMdlT_024_DRE_EV_InMdlT_024_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_AOS
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_AOS(value)                                 Rte_Write_P_EV_TqSys_EveSync_AOS_EV_TqSys_EveSync_AOS(value)
#define vidGET_VALUE_EV_TqSys_EveSync_AOS(variable)                              Rte_Read_R_EV_TqSys_EveSync_AOS_EV_TqSys_EveSync_AOS(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_AntiStallReg
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_AntiStallReg(value)                        Rte_Write_P_EV_TqSys_EveSync_AntiStallReg_EV_TqSys_EveSync_AntiStallReg(value)
#define vidGET_VALUE_EV_TqSys_EveSync_AntiStallReg(variable)                     Rte_Read_R_EV_TqSys_EveSync_AntiStallReg_EV_TqSys_EveSync_AntiStallReg(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_CoPtAntiStall
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_CoPtAntiStall(value)                       Rte_Write_P_EV_TqSys_EveSync_CoPtAntiStall_EV_TqSys_EveSync_CoPtAntiStall(value)
#define vidGET_VALUE_EV_TqSys_EveSync_CoPtAntiStall(variable)                    Rte_Read_R_EV_TqSys_EveSync_CoPtAntiStall_EV_TqSys_EveSync_CoPtAntiStall(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_CurCor
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_CurCor(value)                              Rte_Write_P_EV_TqSys_EveSync_CurCor_EV_TqSys_EveSync_CurCor(value)
#define vidGET_VALUE_EV_TqSys_EveSync_CurCor(variable)                           Rte_Read_R_EV_TqSys_EveSync_CurCor_EV_TqSys_EveSync_CurCor(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_CurCord
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_CurCord(value)                             Rte_Write_P_EV_TqSys_EveSync_CurCord_EV_TqSys_EveSync_CurCord(value)
#define vidGET_VALUE_EV_TqSys_EveSync_CurCord(variable)                          Rte_Read_R_EV_TqSys_EveSync_CurCord_EV_TqSys_EveSync_CurCord(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_CurDrivFil
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_CurDrivFil(value)                          Rte_Write_P_EV_TqSys_EveSync_CurDrivFil_EV_TqSys_EveSync_CurDrivFil(value)
#define vidGET_VALUE_EV_TqSys_EveSync_CurDrivFil(variable)                       Rte_Read_R_EV_TqSys_EveSync_CurDrivFil_EV_TqSys_EveSync_CurDrivFil(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_CurStCalc
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_CurStCalc(value)                           Rte_Write_P_EV_TqSys_EveSync_CurStCalc_EV_TqSys_EveSync_CurStCalc(value)
#define vidGET_VALUE_EV_TqSys_EveSync_CurStCalc(variable)                        Rte_Read_R_EV_TqSys_EveSync_CurStCalc_EV_TqSys_EveSync_CurStCalc(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_CutDyn
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_CutDyn(value)                              Rte_Write_P_EV_TqSys_EveSync_CutDyn_EV_TqSys_EveSync_CutDyn(value)
#define vidGET_VALUE_EV_TqSys_EveSync_CutDyn(variable)                           Rte_Read_R_EV_TqSys_EveSync_CutDyn_EV_TqSys_EveSync_CutDyn(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_IdlCordLim
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_IdlCordLim(value)                          Rte_Write_P_EV_TqSys_EveSync_IdlCordLim_EV_TqSys_EveSync_IdlCordLim(value)
#define vidGET_VALUE_EV_TqSys_EveSync_IdlCordLim(variable)                       Rte_Read_R_EV_TqSys_EveSync_IdlCordLim_EV_TqSys_EveSync_IdlCordLim(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_TqCll
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_TqCll(value)                               Rte_Write_P_EV_TqSys_EveSync_TqCll_EV_TqSys_EveSync_TqCll(value)
#define vidGET_VALUE_EV_TqSys_EveSync_TqCll(variable)                            Rte_Read_R_EV_TqSys_EveSync_TqCll_EV_TqSys_EveSync_TqCll(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_TqClrCros
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_TqClrCros(value)                           Rte_Write_P_EV_TqSys_EveSync_TqClrCros_EV_TqSys_EveSync_TqClrCros(value)
#define vidGET_VALUE_EV_TqSys_EveSync_TqClrCros(variable)                        Rte_Read_R_EV_TqSys_EveSync_TqClrCros_EV_TqSys_EveSync_TqClrCros(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_TqCordLim
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_TqCordLim(value)                           Rte_Write_P_EV_TqSys_EveSync_TqCordLim_EV_TqSys_EveSync_TqCordLim(value)
#define vidGET_VALUE_EV_TqSys_EveSync_TqCordLim(variable)                        Rte_Read_R_EV_TqSys_EveSync_TqCordLim_EV_TqSys_EveSync_TqCordLim(&variable)

/**********************************************************************************
   Create interface for variable EV_TqSys_EveSync_VarAntiStall
  **********************************************************************************/

#define vidSET_VALUE_EV_TqSys_EveSync_VarAntiStall(value)                        Rte_Write_P_EV_TqSys_EveSync_VarAntiStall_EV_TqSys_EveSync_VarAntiStall(value)
#define vidGET_VALUE_EV_TqSys_EveSync_VarAntiStall(variable)                     Rte_Read_R_EV_TqSys_EveSync_VarAntiStall_EV_TqSys_EveSync_VarAntiStall(&variable)

/**********************************************************************************
   Create interface for variable EV_UsThrMT_008_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_UsThrMT_008_DRE(value)                                   Rte_Write_P_EV_UsThrMT_008_DRE_EV_UsThrMT_008_DRE(value)
#define vidGET_VALUE_EV_UsThrMT_008_DRE(variable)                                Rte_Read_R_EV_UsThrMT_008_DRE_EV_UsThrMT_008_DRE(&variable)

/**********************************************************************************
   Create interface for variable EV_UsThrMT_009_DRE
  **********************************************************************************/

#define vidSET_VALUE_EV_UsThrMT_009_DRE(value)                                   Rte_Write_P_EV_UsThrMT_009_DRE_EV_UsThrMT_009_DRE(value)
#define vidGET_VALUE_EV_UsThrMT_009_DRE(variable)                                Rte_Read_R_EV_UsThrMT_009_DRE_EV_UsThrMT_009_DRE(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_bAcvCoefFilDftAlt
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_bAcvCoefFilDftAlt(value)
#define vidGET_VALUE_ElProdMgt_bAcvCoefFilDftAlt(variable)                       Rte_Read_R_ElProdMgt_bAcvCoefFilDftAlt_ElProdMgt_bAcvCoefFilDftAlt(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_iAltEstim
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_iAltEstim(value)
#define vidGET_VALUE_ElProdMgt_iAltEstim(variable)                               Rte_Read_R_ElProdMgt_iAltEstim_ElProdMgt_iAltEstim(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_iExctMax
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_iExctMax(value)
#define vidGET_VALUE_ElProdMgt_iExctMax(variable)                                Rte_Read_R_ElProdMgt_iExctMax_ElProdMgt_iExctMax(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_rSoCErrEstim
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_rSoCErrEstim(value)
#define vidGET_VALUE_ElProdMgt_rSoCErrEstim(variable)                            Rte_Read_R_ElProdMgt_rSoCErrEstim_ElProdMgt_rSoCErrEstim(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_stProdPrgCh
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_stProdPrgCh(value)
#define vidGET_VALUE_ElProdMgt_stProdPrgCh(variable)                             Rte_Read_R_ElProdMgt_stProdPrgCh_ElProdMgt_stProdPrgCh(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_stProdPrgChDi_nEng
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_stProdPrgChDi_nEng(value)
#define vidGET_VALUE_ElProdMgt_stProdPrgChDi_nEng(variable)                      Rte_Read_R_ElProdMgt_stProdPrgChDi_nEng_ElProdMgt_stProdPrgChDi_nEng(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_tqAltEstim
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_tqAltEstim(value)
#define vidGET_VALUE_ElProdMgt_tqAltEstim(variable)                              Rte_Read_R_ElProdMgt_tqAltEstim_ElProdMgt_tqAltEstim(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_uBattSp
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_uBattSp(value)
#define vidGET_VALUE_ElProdMgt_uBattSp(variable)                                 Rte_Read_R_ElProdMgt_uBattSp_ElProdMgt_uBattSp(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_uElProdSp
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_uElProdSp(value)
#define vidGET_VALUE_ElProdMgt_uElProdSp(variable)                               Rte_Read_R_ElProdMgt_uElProdSp_ElProdMgt_uElProdSp(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_uOfsLossCor
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_uOfsLossCor(value)
#define vidGET_VALUE_ElProdMgt_uOfsLossCor(variable)                             Rte_Read_R_ElProdMgt_uOfsLossCor_ElProdMgt_uOfsLossCor(&variable)

/**********************************************************************************
   Create interface for variable ElProdMgt_uOfs_uElProdSp
  **********************************************************************************/

#define vidSET_VALUE_ElProdMgt_uOfs_uElProdSp(value)
#define vidGET_VALUE_ElProdMgt_uOfs_uElProdSp(variable)                          Rte_Read_R_ElProdMgt_uOfs_uElProdSp_ElProdMgt_uOfs_uElProdSp(&variable)

/**********************************************************************************
   Create interface for variable ElecMgt_stPrioVoltMax
  **********************************************************************************/

#define vidSET_VALUE_ElecMgt_stPrioVoltMax(value)                                Rte_Write_P_ElecMgt_stPrioVoltMax_ElecMgt_stPrioVoltMax(value)
#define vidGET_VALUE_ElecMgt_stPrioVoltMax(variable)                             Rte_Read_R_ElecMgt_stPrioVoltMax_ElecMgt_stPrioVoltMax(&variable)

/**********************************************************************************
   Create interface for variable ElecMgt_stPrioVoltMin
  **********************************************************************************/

#define vidSET_VALUE_ElecMgt_stPrioVoltMin(value)                                Rte_Write_P_ElecMgt_stPrioVoltMin_ElecMgt_stPrioVoltMin(value)
#define vidGET_VALUE_ElecMgt_stPrioVoltMin(variable)                             Rte_Read_R_ElecMgt_stPrioVoltMin_ElecMgt_stPrioVoltMin(&variable)

/**********************************************************************************
   Create interface for variable ElecMgt_uReqProdMax
  **********************************************************************************/

#define vidSET_VALUE_ElecMgt_uReqProdMax(value)                                  Rte_Write_P_ElecMgt_uReqProdMax_ElecMgt_uReqProdMax(value)
#define vidGET_VALUE_ElecMgt_uReqProdMax(variable)                               Rte_Read_R_ElecMgt_uReqProdMax_ElecMgt_uReqProdMax(&variable)

/**********************************************************************************
   Create interface for variable ElecMgt_uReqProdMin
  **********************************************************************************/

#define vidSET_VALUE_ElecMgt_uReqProdMin(value)                                  Rte_Write_P_ElecMgt_uReqProdMin_ElecMgt_uReqProdMin(value)
#define vidGET_VALUE_ElecMgt_uReqProdMin(variable)                               Rte_Read_R_ElecMgt_uReqProdMin_ElecMgt_uReqProdMin(&variable)

/**********************************************************************************
   Create interface for variable ElecMgt_uReqProdSlope
  **********************************************************************************/

#define vidSET_VALUE_ElecMgt_uReqProdSlope(value)                                Rte_Write_P_ElecMgt_uReqProdSlope_ElecMgt_uReqProdSlope(value)
#define vidGET_VALUE_ElecMgt_uReqProdSlope(variable)                             Rte_Read_R_ElecMgt_uReqProdSlope_ElecMgt_uReqProdSlope(&variable)

/**********************************************************************************
   Create interface for variable EngLim_stLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_stLim(value)
#define vidGET_VALUE_EngLim_stLim(variable)                                      Rte_Read_R_EngLim_stLim_EngLim_stLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkCurDrivFil
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkCurDrivFil(value)
#define vidGET_VALUE_EngLim_tqCkCurDrivFil(variable)                             Rte_Read_R_EngLim_tqCkCurDrivFil_EngLim_tqCkCurDrivFil(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkDrivFil
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkDrivFil(value)                                   Rte_Write_P_EngLim_tqCkDrivFil_EngLim_tqCkDrivFil(value)
#define vidGET_VALUE_EngLim_tqCkDrivFil(variable)                                Rte_Read_R_EngLim_tqCkDrivFil_EngLim_tqCkDrivFil(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcACCmprLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcACCmprLim(value)                              Rte_Write_P_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcACCmprLim(variable)                           Rte_Read_R_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcATLimCordEL2
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcATLimCordEL2(value)                           Rte_Write_P_EngLim_tqCkEfcATLimCordEL2_EngLim_tqCkEfcATLimCordEL2(value)
#define vidGET_VALUE_EngLim_tqCkEfcATLimCordEL2(variable)                        Rte_Read_R_EngLim_tqCkEfcATLimCordEL2_EngLim_tqCkEfcATLimCordEL2(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcAirGBxLimCord
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcAirGBxLimCord(value)                          Rte_Write_P_EngLim_tqCkEfcAirGBxLimCord_EngLim_tqCkEfcAirGBxLimCord(value)
#define vidGET_VALUE_EngLim_tqCkEfcAirGBxLimCord(variable)                       Rte_Read_R_EngLim_tqCkEfcAirGBxLimCord_EngLim_tqCkEfcAirGBxLimCord(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcAirLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcAirLim(value)                                 Rte_Write_P_EngLim_tqCkEfcAirLim_EngLim_tqCkEfcAirLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcAirLim(variable)                              Rte_Read_R_EngLim_tqCkEfcAirLim_EngLim_tqCkEfcAirLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcChaLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcChaLim(value)                                 Rte_Write_P_EngLim_tqCkEfcChaLim_EngLim_tqCkEfcChaLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcChaLim(variable)                              Rte_Read_R_EngLim_tqCkEfcChaLim_EngLim_tqCkEfcChaLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcFLdLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcFLdLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcFLdLim(variable)                              Rte_Read_R_EngLim_tqCkEfcFLdLim_EngLim_tqCkEfcFLdLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcGBxLimCord
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcGBxLimCord(value)                             Rte_Write_P_EngLim_tqCkEfcGBxLimCord_EngLim_tqCkEfcGBxLimCord(value)
#define vidGET_VALUE_EngLim_tqCkEfcGBxLimCord(variable)                          Rte_Read_R_EngLim_tqCkEfcGBxLimCord_EngLim_tqCkEfcGBxLimCord(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcGBxLimCordEL2
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcGBxLimCordEL2(value)                          Rte_Write_P_EngLim_tqCkEfcGBxLimCordEL2_EngLim_tqCkEfcGBxLimCordEL2(value)
#define vidGET_VALUE_EngLim_tqCkEfcGBxLimCordEL2(variable)                       Rte_Read_R_EngLim_tqCkEfcGBxLimCordEL2_EngLim_tqCkEfcGBxLimCordEL2(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcInrtLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcInrtLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcInrtLim(variable)                             Rte_Read_R_EngLim_tqCkEfcInrtLim_EngLim_tqCkEfcInrtLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcLim(variable)                                 Rte_Read_R_EngLim_tqCkEfcLim_EngLim_tqCkEfcLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcSmkLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcSmkLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcSmkLim(variable)                              Rte_Read_R_EngLim_tqCkEfcSmkLim_EngLim_tqCkEfcSmkLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqCkEfcStatLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqCkEfcStatLim(value)
#define vidGET_VALUE_EngLim_tqCkEfcStatLim(variable)                             Rte_Read_R_EngLim_tqCkEfcStatLim_EngLim_tqCkEfcStatLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcCurMinFuCutSel
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcCurMinFuCutSel(value)
#define vidGET_VALUE_EngLim_tqEfcCurMinFuCutSel(variable)                        Rte_Read_R_EngLim_tqEfcCurMinFuCutSel_EngLim_tqEfcCurMinFuCutSel(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcEngCurMax
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcEngCurMax(value)
#define vidGET_VALUE_EngLim_tqEfcEngCurMax(variable)                             Rte_Read_R_EngLim_tqEfcEngCurMax_EngLim_tqEfcEngCurMax(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcEngCurMin
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcEngCurMin(value)
#define vidGET_VALUE_EngLim_tqEfcEngCurMin(variable)                             Rte_Read_R_EngLim_tqEfcEngCurMin_EngLim_tqEfcEngCurMin(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcEngLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcEngLim(value)
#define vidGET_VALUE_EngLim_tqEfcEngLim(variable)                                Rte_Read_R_EngLim_tqEfcEngLim_EngLim_tqEfcEngLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcEngLimCmb
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcEngLimCmb(value)
#define vidGET_VALUE_EngLim_tqEfcEngLimCmb(variable)                             Rte_Read_R_EngLim_tqEfcEngLimCmb_EngLim_tqEfcEngLimCmb(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcEngProt
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcEngProt(value)
#define vidGET_VALUE_EngLim_tqEfcEngProt(variable)                               Rte_Read_R_EngLim_tqEfcEngProt_EngLim_tqEfcEngProt(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcLdAdvMinFuCutSel
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcLdAdvMinFuCutSel(value)
#define vidGET_VALUE_EngLim_tqEfcLdAdvMinFuCutSel(variable)                      Rte_Read_R_EngLim_tqEfcLdAdvMinFuCutSel_EngLim_tqEfcLdAdvMinFuCutSel(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcLdMaxTrbMax
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcLdMaxTrbMax(value)
#define vidGET_VALUE_EngLim_tqEfcLdMaxTrbMax(variable)                           Rte_Read_R_EngLim_tqEfcLdMaxTrbMax_EngLim_tqEfcLdMaxTrbMax(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcLdMaxWoutOvb
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcLdMaxWoutOvb(value)
#define vidGET_VALUE_EngLim_tqEfcLdMaxWoutOvb(variable)                          Rte_Read_R_EngLim_tqEfcLdMaxWoutOvb_EngLim_tqEfcLdMaxWoutOvb(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcLdMinAdvMin
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcLdMinAdvMin(value)
#define vidGET_VALUE_EngLim_tqEfcLdMinAdvMin(variable)                           Rte_Read_R_EngLim_tqEfcLdMinAdvMin_EngLim_tqEfcLdMinAdvMin(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcMaxDynVehSpdCtl
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcMaxDynVehSpdCtl(value)                          Rte_Write_P_EngLim_tqEfcMaxDynVehSpdCtl_EngLim_tqEfcMaxDynVehSpdCtl(value)
#define vidGET_VALUE_EngLim_tqEfcMaxDynVehSpdCtl(variable)                       Rte_Read_R_EngLim_tqEfcMaxDynVehSpdCtl_EngLim_tqEfcMaxDynVehSpdCtl(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcMaxEngLimCmb
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcMaxEngLimCmb(value)
#define vidGET_VALUE_EngLim_tqEfcMaxEngLimCmb(variable)                          Rte_Read_R_EngLim_tqEfcMaxEngLimCmb_EngLim_tqEfcMaxEngLimCmb(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcMaxStatVehSpdCtl
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcMaxStatVehSpdCtl(value)                         Rte_Write_P_EngLim_tqEfcMaxStatVehSpdCtl_EngLim_tqEfcMaxStatVehSpdCtl(value)
#define vidGET_VALUE_EngLim_tqEfcMaxStatVehSpdCtl(variable)                      Rte_Read_R_EngLim_tqEfcMaxStatVehSpdCtl_EngLim_tqEfcMaxStatVehSpdCtl(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcMinEngLimCmb
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcMinEngLimCmb(value)
#define vidGET_VALUE_EngLim_tqEfcMinEngLimCmb(variable)                          Rte_Read_R_EngLim_tqEfcMinEngLimCmb_EngLim_tqEfcMinEngLimCmb(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcNRegTakeOffLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcNRegTakeOffLim(value)                           Rte_Write_P_EngLim_tqEfcNRegTakeOffLim_EngLim_tqEfcNRegTakeOffLim(value)
#define vidGET_VALUE_EngLim_tqEfcNRegTakeOffLim(variable)                        Rte_Read_R_EngLim_tqEfcNRegTakeOffLim_EngLim_tqEfcNRegTakeOffLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcPresUsThrMax
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcPresUsThrMax(value)
#define vidGET_VALUE_EngLim_tqEfcPresUsThrMax(variable)                          Rte_Read_R_EngLim_tqEfcPresUsThrMax_EngLim_tqEfcPresUsThrMax(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcRed
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcRed(value)
#define vidGET_VALUE_EngLim_tqEfcRed(variable)                                   Rte_Read_R_EngLim_tqEfcRed_EngLim_tqEfcRed(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcSfty
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcSfty(value)
#define vidGET_VALUE_EngLim_tqEfcSfty(variable)                                  Rte_Read_R_EngLim_tqEfcSfty_EngLim_tqEfcSfty(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqEfcSyst
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqEfcSyst(value)
#define vidGET_VALUE_EngLim_tqEfcSyst(variable)                                  Rte_Read_R_EngLim_tqEfcSyst_EngLim_tqEfcSyst(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcEngCur
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcEngCur(value)
#define vidGET_VALUE_EngLim_tqIdcEngCur(variable)                                Rte_Read_R_EngLim_tqIdcEngCur_EngLim_tqIdcEngCur(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcEngCurGBx
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcEngCurGBx(value)
#define vidGET_VALUE_EngLim_tqIdcEngCurGBx(variable)                             Rte_Read_R_EngLim_tqIdcEngCurGBx_EngLim_tqIdcEngCurGBx(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcEngCurMax
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcEngCurMax(value)
#define vidGET_VALUE_EngLim_tqIdcEngCurMax(variable)                             Rte_Read_R_EngLim_tqIdcEngCurMax_EngLim_tqIdcEngCurMax(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcFLdLim
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcFLdLim(value)                                   Rte_Write_P_EngLim_tqIdcFLdLim_EngLim_tqIdcFLdLim(value)
#define vidGET_VALUE_EngLim_tqIdcFLdLim(variable)                                Rte_Read_R_EngLim_tqIdcFLdLim_EngLim_tqIdcFLdLim(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcLdMaxTrbMax
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcLdMaxTrbMax(value)
#define vidGET_VALUE_EngLim_tqIdcLdMaxTrbMax(variable)                           Rte_Read_R_EngLim_tqIdcLdMaxTrbMax_EngLim_tqIdcLdMaxTrbMax(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcLdMinAdvMin
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcLdMinAdvMin(value)
#define vidGET_VALUE_EngLim_tqIdcLdMinAdvMin(variable)                           Rte_Read_R_EngLim_tqIdcLdMinAdvMin_EngLim_tqIdcLdMinAdvMin(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcLdMinAdvMinSelc
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcLdMinAdvMinSelc(value)
#define vidGET_VALUE_EngLim_tqIdcLdMinAdvMinSelc(variable)                       Rte_Read_R_EngLim_tqIdcLdMinAdvMinSelc_EngLim_tqIdcLdMinAdvMinSelc(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcPresUsThrMax
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcPresUsThrMax(value)
#define vidGET_VALUE_EngLim_tqIdcPresUsThrMax(variable)                          Rte_Read_R_EngLim_tqIdcPresUsThrMax_EngLim_tqIdcPresUsThrMax(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcRed
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcRed(value)                                      Rte_Write_P_EngLim_tqIdcRed_EngLim_tqIdcRed(value)
#define vidGET_VALUE_EngLim_tqIdcRed(variable)                                   Rte_Read_R_EngLim_tqIdcRed_EngLim_tqIdcRed(&variable)

/**********************************************************************************
   Create interface for variable EngLim_tqIdcSyst
  **********************************************************************************/

#define vidSET_VALUE_EngLim_tqIdcSyst(value)                                     Rte_Write_P_EngLim_tqIdcSyst_EngLim_tqIdcSyst(value)
#define vidGET_VALUE_EngLim_tqIdcSyst(variable)                                  Rte_Read_R_EngLim_tqIdcSyst_EngLim_tqIdcSyst(&variable)

/**********************************************************************************
   Create interface for variable EngMTrb_bAcvProtKnk
  **********************************************************************************/

#define vidSET_VALUE_EngMTrb_bAcvProtKnk(value)
#define vidGET_VALUE_EngMTrb_bAcvProtKnk(variable)                               Rte_Read_R_EngMTrb_bAcvProtKnk_EngMTrb_bAcvProtKnk(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkClsExVlvReqRef1
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkClsExVlvReqRef1(value)
#define vidGET_VALUE_EngM_agCkClsExVlvReqRef1(variable)                          Rte_Read_R_EngM_agCkClsExVlvReqRef1_EngM_agCkClsExVlvReqRef1(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkClsInVlvEstimRef0
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkClsInVlvEstimRef0(value)
#define vidGET_VALUE_EngM_agCkClsInVlvEstimRef0(variable)                        Rte_Read_R_EngM_agCkClsInVlvEstimRef0_EngM_agCkClsInVlvEstimRef0(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkClsInVlvReqRef0
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkClsInVlvReqRef0(value)
#define vidGET_VALUE_EngM_agCkClsInVlvReqRef0(variable)                          Rte_Read_R_EngM_agCkClsInVlvReqRef0_EngM_agCkClsInVlvReqRef0(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkOpExVlvEstimRef0
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkOpExVlvEstimRef0(value)
#define vidGET_VALUE_EngM_agCkOpExVlvEstimRef0(variable)                         Rte_Read_R_EngM_agCkOpExVlvEstimRef0_EngM_agCkOpExVlvEstimRef0(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkOpExVlvEstimRef1
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkOpExVlvEstimRef1(value)
#define vidGET_VALUE_EngM_agCkOpExVlvEstimRef1(variable)                         Rte_Read_R_EngM_agCkOpExVlvEstimRef1_EngM_agCkOpExVlvEstimRef1(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkOpExVlvReqRef0
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkOpExVlvReqRef0(value)
#define vidGET_VALUE_EngM_agCkOpExVlvReqRef0(variable)                           Rte_Read_R_EngM_agCkOpExVlvReqRef0_EngM_agCkOpExVlvReqRef0(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkOpExVlvReqRef1
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkOpExVlvReqRef1(value)
#define vidGET_VALUE_EngM_agCkOpExVlvReqRef1(variable)                           Rte_Read_R_EngM_agCkOpExVlvReqRef1_EngM_agCkOpExVlvReqRef1(&variable)

/**********************************************************************************
   Create interface for variable EngM_agCkOpInVlvReqRef1
  **********************************************************************************/

#define vidSET_VALUE_EngM_agCkOpInVlvReqRef1(value)
#define vidGET_VALUE_EngM_agCkOpInVlvReqRef1(variable)                           Rte_Read_R_EngM_agCkOpInVlvReqRef1_EngM_agCkOpInVlvReqRef1(&variable)

/**********************************************************************************
   Create interface for variable EngM_facAPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_facAPred(value)
#define vidGET_VALUE_EngM_facAPred(variable)                                     Rte_Read_R_EngM_facAPred_EngM_facAPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_facDCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_facDCor(value)
#define vidGET_VALUE_EngM_facDCor(variable)                                      Rte_Read_R_EngM_facDCor_EngM_facDCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_facMassAirScvCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_facMassAirScvCor(value)
#define vidGET_VALUE_EngM_facMassAirScvCor(variable)                             Rte_Read_R_EngM_facMassAirScvCor_EngM_facMassAirScvCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_facMassAirScvReq
  **********************************************************************************/

#define vidSET_VALUE_EngM_facMassAirScvReq(value)
#define vidGET_VALUE_EngM_facMassAirScvReq(variable)                             Rte_Read_R_EngM_facMassAirScvReq_EngM_facMassAirScvReq(&variable)

/**********************************************************************************
   Create interface for variable EngM_facMassFlowLdCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_facMassFlowLdCor(value)
#define vidGET_VALUE_EngM_facMassFlowLdCor(variable)                             Rte_Read_R_EngM_facMassFlowLdCor_EngM_facMassFlowLdCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_facOfsEfcPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_facOfsEfcPred(value)
#define vidGET_VALUE_EngM_facOfsEfcPred(variable)                                Rte_Read_R_EngM_facOfsEfcPred_EngM_facOfsEfcPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_facSlopEfcPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_facSlopEfcPred(value)
#define vidGET_VALUE_EngM_facSlopEfcPred(variable)                               Rte_Read_R_EngM_facSlopEfcPred_EngM_facSlopEfcPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_mAirEngCylMin
  **********************************************************************************/

#define vidSET_VALUE_EngM_mAirEngCylMin(value)
#define vidGET_VALUE_EngM_mAirEngCylMin(variable)                                Rte_Read_R_EngM_mAirEngCylMin_EngM_mAirEngCylMin(&variable)

/**********************************************************************************
   Create interface for variable EngM_mAirPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_mAirPred(value)
#define vidGET_VALUE_EngM_mAirPred(variable)                                     Rte_Read_R_EngM_mAirPred_EngM_mAirPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_mAirPredIn
  **********************************************************************************/

#define vidSET_VALUE_EngM_mAirPredIn(value)
#define vidGET_VALUE_EngM_mAirPredIn(variable)                                   Rte_Read_R_EngM_mAirPredIn_EngM_mAirPredIn(&variable)

/**********************************************************************************
   Create interface for variable EngM_mAirScvCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_mAirScvCor(value)
#define vidGET_VALUE_EngM_mAirScvCor(variable)                                   Rte_Read_R_EngM_mAirScvCor_EngM_mAirScvCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_mTotExPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_mTotExPred(value)
#define vidGET_VALUE_EngM_mTotExPred(variable)                                   Rte_Read_R_EngM_mTotExPred_EngM_mTotExPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_mTotExPredIn
  **********************************************************************************/

#define vidSET_VALUE_EngM_mTotExPredIn(value)
#define vidGET_VALUE_EngM_mTotExPredIn(variable)                                 Rte_Read_R_EngM_mTotExPredIn_EngM_mTotExPredIn(&variable)

/**********************************************************************************
   Create interface for variable EngM_mfAirCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_mfAirCor(value)
#define vidGET_VALUE_EngM_mfAirCor(variable)                                     Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_mfAirPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_mfAirPred(value)
#define vidGET_VALUE_EngM_mfAirPred(variable)                                    Rte_Read_R_EngM_mfAirPred_EngM_mfAirPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_mfAirPredIn
  **********************************************************************************/

#define vidSET_VALUE_EngM_mfAirPredIn(value)
#define vidGET_VALUE_EngM_mfAirPredIn(variable)                                  Rte_Read_R_EngM_mfAirPredIn_EngM_mfAirPredIn(&variable)

/**********************************************************************************
   Create interface for variable EngM_mfTotExCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_mfTotExCor(value)                                      Rte_Write_P_EngM_mfTotExCor_EngM_mfTotExCor(value)
#define vidGET_VALUE_EngM_mfTotExCor(variable)                                   Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_mfTotExPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_mfTotExPred(value)
#define vidGET_VALUE_EngM_mfTotExPred(variable)                                  Rte_Read_R_EngM_mfTotExPred_EngM_mfTotExPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_mfTotExPredIn
  **********************************************************************************/

#define vidSET_VALUE_EngM_mfTotExPredIn(value)
#define vidGET_VALUE_EngM_mfTotExPredIn(variable)                                Rte_Read_R_EngM_mfTotExPredIn_EngM_mfTotExPredIn(&variable)

/**********************************************************************************
   Create interface for variable EngM_pInMnfMinReq
  **********************************************************************************/

#define vidSET_VALUE_EngM_pInMnfMinReq(value)
#define vidGET_VALUE_EngM_pInMnfMinReq(variable)                                 Rte_Read_R_EngM_pInMnfMinReq_EngM_pInMnfMinReq(&variable)

/**********************************************************************************
   Create interface for array EngM_prm_mAirPredInCyl
  **********************************************************************************/

#define vidSET_ARRAY_EngM_prm_mAirPredInCyl(value,size)
#define vidGET_ARRAY_EngM_prm_mAirPredInCyl(variable,size)                       Rte_Read_R_EngM_prm_mAirPredInCyl_EngM_prm_mAirPredInCyl(&variable)

#define vidSET_ARRAY_ELEMENT_EngM_prm_mAirPredInCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_EngM_prm_mAirPredInCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_EngM_prm_mAirPredInCyl datatemp[6];\
     Rte_Read_R_EngM_prm_mAirPredInCyl_EngM_prm_mAirPredInCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EngM_prm_mAirScvCorCyl
  **********************************************************************************/

#define vidSET_ARRAY_EngM_prm_mAirScvCorCyl(value,size)
#define vidGET_ARRAY_EngM_prm_mAirScvCorCyl(variable,size)                       Rte_Read_R_EngM_prm_mAirScvCorCyl_EngM_prm_mAirScvCorCyl(&variable)

#define vidSET_ARRAY_ELEMENT_EngM_prm_mAirScvCorCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_EngM_prm_mAirScvCorCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_EngM_prm_mAirScvCorCyl datatemp[6];\
     Rte_Read_R_EngM_prm_mAirScvCorCyl_EngM_prm_mAirScvCorCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EngM_prm_mfAirPredInCyl
  **********************************************************************************/

#define vidSET_ARRAY_EngM_prm_mfAirPredInCyl(value,size)
#define vidGET_ARRAY_EngM_prm_mfAirPredInCyl(variable,size)                      Rte_Read_R_EngM_prm_mfAirPredInCyl_EngM_prm_mfAirPredInCyl(&variable)

#define vidSET_ARRAY_ELEMENT_EngM_prm_mfAirPredInCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_EngM_prm_mfAirPredInCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_EngM_prm_mfAirPredInCyl datatemp[6];\
     Rte_Read_R_EngM_prm_mfAirPredInCyl_EngM_prm_mfAirPredInCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EngM_prm_mfTotExCorCyl
  **********************************************************************************/

#define vidSET_ARRAY_EngM_prm_mfTotExCorCyl(value,size)
#define vidGET_ARRAY_EngM_prm_mfTotExCorCyl(variable,size)                       Rte_Read_R_EngM_prm_mfTotExCorCyl_EngM_prm_mfTotExCorCyl(&variable)

#define vidSET_ARRAY_ELEMENT_EngM_prm_mfTotExCorCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_EngM_prm_mfTotExCorCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_EngM_prm_mfTotExCorCyl datatemp[6];\
     Rte_Read_R_EngM_prm_mfTotExCorCyl_EngM_prm_mfTotExCorCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EngM_prm_rAirLdPredInCyl
  **********************************************************************************/

#define vidSET_ARRAY_EngM_prm_rAirLdPredInCyl(value,size)
#define vidGET_ARRAY_EngM_prm_rAirLdPredInCyl(variable,size)                     Rte_Read_R_EngM_prm_rAirLdPredInCyl_EngM_prm_rAirLdPredInCyl(&variable)

#define vidSET_ARRAY_ELEMENT_EngM_prm_rAirLdPredInCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_EngM_prm_rAirLdPredInCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_EngM_prm_rAirLdPredInCyl datatemp[6];\
     Rte_Read_R_EngM_prm_rAirLdPredInCyl_EngM_prm_rAirLdPredInCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array EngM_prm_rTotLdExCorCyl
  **********************************************************************************/

#define vidSET_ARRAY_EngM_prm_rTotLdExCorCyl(value,size)
#define vidGET_ARRAY_EngM_prm_rTotLdExCorCyl(variable,size)                      Rte_Read_R_EngM_prm_rTotLdExCorCyl_EngM_prm_rTotLdExCorCyl(&variable)

#define vidSET_ARRAY_ELEMENT_EngM_prm_rTotLdExCorCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_EngM_prm_rTotLdExCorCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_EngM_prm_rTotLdExCorCyl datatemp[6];\
     Rte_Read_R_EngM_prm_rTotLdExCorCyl_EngM_prm_rTotLdExCorCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable EngM_rAirLdCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_rAirLdCor(value)
#define vidGET_VALUE_EngM_rAirLdCor(variable)                                    Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_rAirLdPredIn
  **********************************************************************************/

#define vidSET_VALUE_EngM_rAirLdPredIn(value)
#define vidGET_VALUE_EngM_rAirLdPredIn(variable)                                 Rte_Read_R_EngM_rAirLdPredIn_EngM_rAirLdPredIn(&variable)

/**********************************************************************************
   Create interface for variable EngM_rTotLdExCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_rTotLdExCor(value)
#define vidGET_VALUE_EngM_rTotLdExCor(variable)                                  Rte_Read_R_EngM_rTotLdExCor_EngM_rTotLdExCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_rTotLdExPred
  **********************************************************************************/

#define vidSET_VALUE_EngM_rTotLdExPred(value)
#define vidGET_VALUE_EngM_rTotLdExPred(variable)                                 Rte_Read_R_EngM_rTotLdExPred_EngM_rTotLdExPred(&variable)

/**********************************************************************************
   Create interface for variable EngM_tBurnCylCor
  **********************************************************************************/

#define vidSET_VALUE_EngM_tBurnCylCor(value)
#define vidGET_VALUE_EngM_tBurnCylCor(variable)                                  Rte_Read_R_EngM_tBurnCylCor_EngM_tBurnCylCor(&variable)

/**********************************************************************************
   Create interface for variable EngM_tMixtCylGDICor
  **********************************************************************************/

#define vidSET_VALUE_EngM_tMixtCylGDICor(value)
#define vidGET_VALUE_EngM_tMixtCylGDICor(variable)                               Rte_Read_R_EngM_tMixtCylGDICor_EngM_tMixtCylGDICor(&variable)

/**********************************************************************************
   Create interface for variable EngReqH_bDetPresAirUnfav
  **********************************************************************************/

#define vidSET_VALUE_EngReqH_bDetPresAirUnfav(value)                             Rte_Write_P_EngReqH_bDetPresAirUnfav_EngReqH_bDetPresAirUnfav(value)
#define vidGET_VALUE_EngReqH_bDetPresAirUnfav(variable)                          Rte_Read_R_EngReqH_bDetPresAirUnfav_EngReqH_bDetPresAirUnfav(&variable)

/**********************************************************************************
   Create interface for variable EngReqH_bEngRStrtAutnAvl
  **********************************************************************************/

#define vidSET_VALUE_EngReqH_bEngRStrtAutnAvl(value)                             Rte_Write_P_EngReqH_bEngRStrtAutnAvl_EngReqH_bEngRStrtAutnAvl(value)
#define vidGET_VALUE_EngReqH_bEngRStrtAutnAvl(variable)                          Rte_Read_R_EngReqH_bEngRStrtAutnAvl_EngReqH_bEngRStrtAutnAvl(&variable)

/**********************************************************************************
   Create interface for variable EngReqH_bEngRunReq
  **********************************************************************************/

#define vidSET_VALUE_EngReqH_bEngRunReq(value)                                   Rte_Write_P_EngReqH_bEngRunReq_EngReqH_bEngRunReq(value)
#define vidGET_VALUE_EngReqH_bEngRunReq(variable)                                Rte_Read_R_EngReqH_bEngRunReq_EngReqH_bEngRunReq(&variable)

/**********************************************************************************
   Create interface for variable EngReqH_stEngStopAuth
  **********************************************************************************/

#define vidSET_VALUE_EngReqH_stEngStopAuth(value)                                Rte_Write_P_EngReqH_stEngStopAuth_EngReqH_stEngStopAuth(value)
#define vidGET_VALUE_EngReqH_stEngStopAuth(variable)                             Rte_Read_R_EngReqH_stEngStopAuth_EngReqH_stEngStopAuth(&variable)

/**********************************************************************************
   Create interface for variable EngSt_bAcvAuthStrtSTTAcq
  **********************************************************************************/

#define vidSET_VALUE_EngSt_bAcvAuthStrtSTTAcq(value)                             Rte_Write_P_EngSt_bAcvAuthStrtSTTAcq_EngSt_bAcvAuthStrtSTTAcq(value)
#define vidGET_VALUE_EngSt_bAcvAuthStrtSTTAcq(variable)                          Rte_Read_R_EngSt_bAcvAuthStrtSTTAcq_EngSt_bAcvAuthStrtSTTAcq(&variable)

/**********************************************************************************
   Create interface for variable EngSt_bAcvDftStaCmdAcq
  **********************************************************************************/

#define vidSET_VALUE_EngSt_bAcvDftStaCmdAcq(value)                               Rte_Write_P_EngSt_bAcvDftStaCmdAcq_EngSt_bAcvDftStaCmdAcq(value)
#define vidGET_VALUE_EngSt_bAcvDftStaCmdAcq(variable)                            Rte_Read_R_EngSt_bAcvDftStaCmdAcq_EngSt_bAcvDftStaCmdAcq(&variable)

/**********************************************************************************
   Create interface for variable EngSt_bOscDetStab
  **********************************************************************************/

#define vidSET_VALUE_EngSt_bOscDetStab(value)                                    Rte_Write_P_EngSt_bOscDetStab_EngSt_bOscDetStab(value)
#define vidGET_VALUE_EngSt_bOscDetStab(variable)                                 Rte_Read_R_EngSt_bOscDetStab_EngSt_bOscDetStab(&variable)

/**********************************************************************************
   Create interface for variable Eng_bAcvCllEngReq
  **********************************************************************************/

#define vidSET_VALUE_Eng_bAcvCllEngReq(value)                                    Rte_Write_P_Eng_bAcvCllEngReq_Eng_bAcvCllEngReq(value)
#define vidGET_VALUE_Eng_bAcvCllEngReq(variable)                                 Rte_Read_R_Eng_bAcvCllEngReq_Eng_bAcvCllEngReq(&variable)

/**********************************************************************************
   Create interface for variable Eng_nCkFil
  **********************************************************************************/

#define vidSET_VALUE_Eng_nCkFil(value)
#define vidGET_VALUE_Eng_nCkFil(variable)                                        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&variable)

/**********************************************************************************
   Create interface for variable Eng_noCmbCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noCmbCyl(value)                                         Rte_Write_P_Eng_noCmbCyl_Eng_noCmbCyl(value)
#define vidGET_VALUE_Eng_noCmbCyl(variable)                                      Rte_Read_R_Eng_noCmbCyl_Eng_noCmbCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_noCmprCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noCmprCyl(value)                                        Rte_Write_P_Eng_noCmprCyl_Eng_noCmprCyl(value)
#define vidGET_VALUE_Eng_noCmprCyl(variable)                                     Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_noCmprNxtCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noCmprNxtCyl(value)                                     Rte_Write_P_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl(value)
#define vidGET_VALUE_Eng_noCmprNxtCyl(variable)                                  Rte_Read_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_noExCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noExCyl(value)                                          Rte_Write_P_Eng_noExCyl_Eng_noExCyl(value)
#define vidGET_VALUE_Eng_noExCyl(variable)                                       Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_noExNxtCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noExNxtCyl(value)                                       Rte_Write_P_Eng_noExNxtCyl_Eng_noExNxtCyl(value)
#define vidGET_VALUE_Eng_noExNxtCyl(variable)                                    Rte_Read_R_Eng_noExNxtCyl_Eng_noExNxtCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_noInCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noInCyl(value)                                          Rte_Write_P_Eng_noInCyl_Eng_noInCyl(value)
#define vidGET_VALUE_Eng_noInCyl(variable)                                       Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_noInNxtCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noInNxtCyl(value)                                       Rte_Write_P_Eng_noInNxtCyl_Eng_noInNxtCyl(value)
#define vidGET_VALUE_Eng_noInNxtCyl(variable)                                    Rte_Read_R_Eng_noInNxtCyl_Eng_noInNxtCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_noInNxtNxtCyl
  **********************************************************************************/

#define vidSET_VALUE_Eng_noInNxtNxtCyl(value)                                    Rte_Write_P_Eng_noInNxtNxtCyl_Eng_noInNxtNxtCyl(value)
#define vidGET_VALUE_Eng_noInNxtNxtCyl(variable)                                 Rte_Read_R_Eng_noInNxtNxtCyl_Eng_noInNxtNxtCyl(&variable)

/**********************************************************************************
   Create interface for variable Eng_rAirLd
  **********************************************************************************/

#define vidSET_VALUE_Eng_rAirLd(value)                                           Rte_Write_P_Eng_rAirLd_Eng_rAirLd(value)
#define vidGET_VALUE_Eng_rAirLd(variable)                                        Rte_Read_R_Eng_rAirLd_Eng_rAirLd(&variable)

/**********************************************************************************
   Create interface for variable Eng_stEru
  **********************************************************************************/

#define vidSET_VALUE_Eng_stEru(value)                                            Rte_Write_P_Eng_stEru_Eng_stEru(value)
#define vidGET_VALUE_Eng_stEru(variable)                                         Rte_Read_R_Eng_stEru_Eng_stEru(&variable)

/**********************************************************************************
   Create interface for variable Eng_stRun
  **********************************************************************************/

#define vidSET_VALUE_Eng_stRun(value)                                            Rte_Write_P_Eng_stRun_Eng_stRun(value)
#define vidGET_VALUE_Eng_stRun(variable)                                         Rte_Read_R_Eng_stRun_Eng_stRun(&variable)

/**********************************************************************************
   Create interface for variable Eng_tOilEstim
  **********************************************************************************/

#define vidSET_VALUE_Eng_tOilEstim(value)                                        Rte_Write_P_Eng_tOilEstim_Eng_tOilEstim(value)
#define vidGET_VALUE_Eng_tOilEstim(variable)                                     Rte_Read_R_Eng_tOilEstim_Eng_tOilEstim(&variable)

/**********************************************************************************
   Create interface for variable Engine_load
  **********************************************************************************/

#define vidSET_VALUE_Engine_load(value)                                          Rte_Write_P_Engine_load_Engine_load(value)
#define vidGET_VALUE_Engine_load(variable)                                       Rte_Read_R_Engine_load_Engine_load(&variable)

/**********************************************************************************
   Create interface for variable Engine_running_state_swc
  **********************************************************************************/

#define vidSET_VALUE_Engine_running_state_swc(value)                             Rte_Write_P_Engine_running_state_swc_Engine_running_state_swc(value)
#define vidGET_VALUE_Engine_running_state_swc(variable)                          Rte_Read_R_Engine_running_state_swc_Engine_running_state_swc(&variable)

/**********************************************************************************
   Create interface for variable ExM_facCorProtComp
  **********************************************************************************/

#define vidSET_VALUE_ExM_facCorProtComp(value)
#define vidGET_VALUE_ExM_facCorProtComp(variable)                                Rte_Read_R_ExM_facCorProtComp_ExM_facCorProtComp(&variable)

/**********************************************************************************
   Create interface for variable ExM_mO2StgCur
  **********************************************************************************/

#define vidSET_VALUE_ExM_mO2StgCur(value)                                        Rte_Write_P_ExM_mO2StgCur_ExM_mO2StgCur(value)
#define vidGET_VALUE_ExM_mO2StgCur(variable)                                     Rte_Read_R_ExM_mO2StgCur_ExM_mO2StgCur(&variable)

/**********************************************************************************
   Create interface for variable ExM_mO2StgEngStop
  **********************************************************************************/

#define vidSET_VALUE_ExM_mO2StgEngStop(value)                                    Rte_Write_P_ExM_mO2StgEngStop_ExM_mO2StgEngStop(value)
#define vidGET_VALUE_ExM_mO2StgEngStop(variable)                                 Rte_Read_R_ExM_mO2StgEngStop_ExM_mO2StgEngStop(&variable)

/**********************************************************************************
   Create interface for variable ExM_mfEgTot
  **********************************************************************************/

#define vidSET_VALUE_ExM_mfEgTot(value)
#define vidGET_VALUE_ExM_mfEgTot(variable)                                       Rte_Read_R_ExM_mfEgTot_ExM_mfEgTot(&variable)

/**********************************************************************************
   Create interface for variable ExM_mfWgEstim
  **********************************************************************************/

#define vidSET_VALUE_ExM_mfWgEstim(value)
#define vidGET_VALUE_ExM_mfWgEstim(variable)                                     Rte_Read_R_ExM_mfWgEstim_ExM_mfWgEstim(&variable)

/**********************************************************************************
   Create interface for variable ExM_pExMnfEstim
  **********************************************************************************/

#define vidSET_VALUE_ExM_pExMnfEstim(value)
#define vidGET_VALUE_ExM_pExMnfEstim(variable)                                   Rte_Read_R_ExM_pExMnfEstim_ExM_pExMnfEstim(&variable)

/**********************************************************************************
   Create interface for variable ExM_pUsTrbEstimTqSys
  **********************************************************************************/

#define vidSET_VALUE_ExM_pUsTrbEstimTqSys(value)                                 Rte_Write_P_ExM_pUsTrbEstimTqSys_ExM_pUsTrbEstimTqSys(value)
#define vidGET_VALUE_ExM_pUsTrbEstimTqSys(variable)                              Rte_Read_R_ExM_pUsTrbEstimTqSys_ExM_pUsTrbEstimTqSys(&variable)

/**********************************************************************************
   Create interface for array ExM_prm_pEg
  **********************************************************************************/

#define vidSET_ARRAY_ExM_prm_pEg(value,size)
#define vidGET_ARRAY_ExM_prm_pEg(variable,size)                                  Rte_Read_R_ExM_prm_pEg_ExM_prm_pEg(&variable)

#define vidSET_ARRAY_ELEMENT_ExM_prm_pEg(variable,pos)
#define vidGET_ARRAY_ELEMENT_ExM_prm_pEg(variable,pos){ \
  if (pos < 12)\
  { \
     DT_ExM_prm_pEg datatemp[12];\
     Rte_Read_R_ExM_prm_pEg_ExM_prm_pEg(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array ExM_prm_pEgFlt
  **********************************************************************************/

#define vidSET_ARRAY_ExM_prm_pEgFlt(value,size)
#define vidGET_ARRAY_ExM_prm_pEgFlt(variable,size)                               Rte_Read_R_ExM_prm_pEgFlt_ExM_prm_pEgFlt(&variable)

#define vidSET_ARRAY_ELEMENT_ExM_prm_pEgFlt(variable,pos)
#define vidGET_ARRAY_ELEMENT_ExM_prm_pEgFlt(variable,pos){ \
  if (pos < 12)\
  { \
     DT_ExM_prm_pEgFlt datatemp[12];\
     Rte_Read_R_ExM_prm_pEgFlt_ExM_prm_pEgFlt(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array ExM_prm_pExMnfEstimOvlpCyl
  **********************************************************************************/

#define vidSET_ARRAY_ExM_prm_pExMnfEstimOvlpCyl(value,size)
#define vidGET_ARRAY_ExM_prm_pExMnfEstimOvlpCyl(variable,size)                   Rte_Read_R_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl(&variable)

#define vidSET_ARRAY_ELEMENT_ExM_prm_pExMnfEstimOvlpCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_ExM_prm_pExMnfEstimOvlpCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_ExM_prm_pExMnfEstimOvlpCyl datatemp[6];\
     Rte_Read_R_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array ExM_prm_tEg
  **********************************************************************************/

#define vidSET_ARRAY_ExM_prm_tEg(value,size)
#define vidGET_ARRAY_ExM_prm_tEg(variable,size)                                  Rte_Read_R_ExM_prm_tEg_ExM_prm_tEg(&variable)

#define vidSET_ARRAY_ELEMENT_ExM_prm_tEg(variable,pos)
#define vidGET_ARRAY_ELEMENT_ExM_prm_tEg(variable,pos){ \
  if (pos < 12)\
  { \
     DT_ExM_prm_tEg datatemp[12];\
     Rte_Read_R_ExM_prm_tEg_ExM_prm_tEg(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array ExM_prm_tEgFlt
  **********************************************************************************/

#define vidSET_ARRAY_ExM_prm_tEgFlt(value,size)
#define vidGET_ARRAY_ExM_prm_tEgFlt(variable,size)                               Rte_Read_R_ExM_prm_tEgFlt_ExM_prm_tEgFlt(&variable)

#define vidSET_ARRAY_ELEMENT_ExM_prm_tEgFlt(variable,pos)
#define vidGET_ARRAY_ELEMENT_ExM_prm_tEgFlt(variable,pos){ \
  if (pos < 12)\
  { \
     DT_ExM_prm_tEgFlt datatemp[12];\
     Rte_Read_R_ExM_prm_tEgFlt_ExM_prm_tEgFlt(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable ExM_rPresTrbEstim
  **********************************************************************************/

#define vidSET_VALUE_ExM_rPresTrbEstim(value)
#define vidGET_VALUE_ExM_rPresTrbEstim(variable)                                 Rte_Read_R_ExM_rPresTrbEstim_ExM_rPresTrbEstim(&variable)

/**********************************************************************************
   Create interface for variable ExM_rPresTrbEstimIvs
  **********************************************************************************/

#define vidSET_VALUE_ExM_rPresTrbEstimIvs(value)
#define vidGET_VALUE_ExM_rPresTrbEstimIvs(variable)                              Rte_Read_R_ExM_rPresTrbEstimIvs_ExM_rPresTrbEstimIvs(&variable)

/**********************************************************************************
   Create interface for variable ExM_tExMnfEstim
  **********************************************************************************/

#define vidSET_VALUE_ExM_tExMnfEstim(value)
#define vidGET_VALUE_ExM_tExMnfEstim(variable)                                   Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim(&variable)

/**********************************************************************************
   Create interface for variable ExM_tExOfs
  **********************************************************************************/

#define vidSET_VALUE_ExM_tExOfs(value)                                           Rte_Write_P_ExM_tExOfs_ExM_tExOfs(value)
#define vidGET_VALUE_ExM_tExOfs(variable)                                        Rte_Read_R_ExM_tExOfs_ExM_tExOfs(&variable)

/**********************************************************************************
   Create interface for variable ExM_tExPostOxOfs
  **********************************************************************************/

#define vidSET_VALUE_ExM_tExPostOxOfs(value)
#define vidGET_VALUE_ExM_tExPostOxOfs(variable)                                  Rte_Read_R_ExM_tExPostOxOfs_ExM_tExPostOxOfs(&variable)

/**********************************************************************************
   Create interface for variable ExM_tOxCEstim
  **********************************************************************************/

#define vidSET_VALUE_ExM_tOxCEstim(value)
#define vidGET_VALUE_ExM_tOxCEstim(variable)                                     Rte_Read_R_ExM_tOxCEstim_ExM_tOxCEstim(&variable)

/**********************************************************************************
   Create interface for variable ExM_tPreOxCEstim
  **********************************************************************************/

#define vidSET_VALUE_ExM_tPreOxCEstim(value)
#define vidGET_VALUE_ExM_tPreOxCEstim(variable)                                  Rte_Read_R_ExM_tPreOxCEstim_ExM_tPreOxCEstim(&variable)

/**********************************************************************************
   Create interface for variable Ext_aVehLatEstim
  **********************************************************************************/

#define vidSET_VALUE_Ext_aVehLatEstim(value)                                     Rte_Write_P_Ext_aVehLatEstim_Ext_aVehLatEstim(value)
#define vidGET_VALUE_Ext_aVehLatEstim(variable)                                  Rte_Read_R_Ext_aVehLatEstim_Ext_aVehLatEstim(&variable)

/**********************************************************************************
   Create interface for variable Ext_agCkClsExVlvEstimRef0
  **********************************************************************************/

#define vidSET_VALUE_Ext_agCkClsExVlvEstimRef0(value)                            Rte_Write_P_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0(value)
#define vidGET_VALUE_Ext_agCkClsExVlvEstimRef0(variable)                         Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0(&variable)

/**********************************************************************************
   Create interface for variable Ext_agCkOpInVlvEstimRef0
  **********************************************************************************/

#define vidSET_VALUE_Ext_agCkOpInVlvEstimRef0(value)                             Rte_Write_P_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0(value)
#define vidGET_VALUE_Ext_agCkOpInVlvEstimRef0(variable)                          Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0(&variable)

/**********************************************************************************
   Create interface for variable Ext_agCkPosnCurRef2
  **********************************************************************************/

#define vidSET_VALUE_Ext_agCkPosnCurRef2(value)                                  Rte_Write_P_Ext_agCkPosnCurRef2_Ext_agCkPosnCurRef2(value)
#define vidGET_VALUE_Ext_agCkPosnCurRef2(variable)                               Rte_Read_R_Ext_agCkPosnCurRef2_Ext_agCkPosnCurRef2(&variable)

/**********************************************************************************
   Create interface for variable Ext_bABSCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bABSCf(value)                                           Rte_Write_P_Ext_bABSCf_Ext_bABSCf(value)
#define vidGET_VALUE_Ext_bABSCf(variable)                                        Rte_Read_R_Ext_bABSCf_Ext_bABSCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bABSReg
  **********************************************************************************/

#define vidSET_VALUE_Ext_bABSReg(value)                                          Rte_Write_P_Ext_bABSReg_Ext_bABSReg(value)
#define vidGET_VALUE_Ext_bABSReg(variable)                                       Rte_Read_R_Ext_bABSReg_Ext_bABSReg(&variable)

/**********************************************************************************
   Create interface for variable Ext_bACCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bACCf(value)                                            Rte_Write_P_Ext_bACCf_Ext_bACCf(value)
#define vidGET_VALUE_Ext_bACCf(variable)                                         Rte_Read_R_Ext_bACCf_Ext_bACCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bACCluAuth
  **********************************************************************************/

#define vidSET_VALUE_Ext_bACCluAuth(value)                                       Rte_Write_P_Ext_bACCluAuth_Ext_bACCluAuth(value)
#define vidGET_VALUE_Ext_bACCluAuth(variable)                                    Rte_Read_R_Ext_bACCluAuth_Ext_bACCluAuth(&variable)

/**********************************************************************************
   Create interface for variable Ext_bAPCLine
  **********************************************************************************/

#define vidSET_VALUE_Ext_bAPCLine(value)                                         Rte_Write_P_Ext_bAPCLine_Ext_bAPCLine(value)
#define vidGET_VALUE_Ext_bAPCLine(variable)                                      Rte_Read_R_Ext_bAPCLine_Ext_bAPCLine(&variable)

/**********************************************************************************
   Create interface for variable Ext_bASECf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bASECf(value)                                           Rte_Write_P_Ext_bASECf_Ext_bASECf(value)
#define vidGET_VALUE_Ext_bASECf(variable)                                        Rte_Read_R_Ext_bASECf_Ext_bASECf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bASRESPCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bASRESPCf(value)                                        Rte_Write_P_Ext_bASRESPCf_Ext_bASRESPCf(value)
#define vidGET_VALUE_Ext_bASRESPCf(variable)                                     Rte_Read_R_Ext_bASRESPCf_Ext_bASRESPCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bASRReg
  **********************************************************************************/

#define vidSET_VALUE_Ext_bASRReg(value)                                          Rte_Write_P_Ext_bASRReg_Ext_bASRReg(value)
#define vidGET_VALUE_Ext_bASRReg(variable)                                       Rte_Read_R_Ext_bASRReg_Ext_bASRReg(&variable)

/**********************************************************************************
   Create interface for variable Ext_bATParkNeut
  **********************************************************************************/

#define vidSET_VALUE_Ext_bATParkNeut(value)                                      Rte_Write_P_Ext_bATParkNeut_Ext_bATParkNeut(value)
#define vidGET_VALUE_Ext_bATParkNeut(variable)                                   Rte_Read_R_Ext_bATParkNeut_Ext_bATParkNeut(&variable)

/**********************************************************************************
   Create interface for variable Ext_bAccPHdPt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bAccPHdPt(value)                                        Rte_Write_P_Ext_bAccPHdPt_Ext_bAccPHdPt(value)
#define vidGET_VALUE_Ext_bAccPHdPt(variable)                                     Rte_Read_R_Ext_bAccPHdPt_Ext_bAccPHdPt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bAcvCtlExt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bAcvCtlExt(value)                                       Rte_Write_P_Ext_bAcvCtlExt_Ext_bAcvCtlExt(value)
#define vidGET_VALUE_Ext_bAcvCtlExt(variable)                                    Rte_Read_R_Ext_bAcvCtlExt_Ext_bAcvCtlExt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bAcvInjCutOff
  **********************************************************************************/

#define vidSET_VALUE_Ext_bAcvInjCutOff(value)                                    Rte_Write_P_Ext_bAcvInjCutOff_Ext_bAcvInjCutOff(value)
#define vidGET_VALUE_Ext_bAcvInjCutOff(variable)                                 Rte_Read_R_Ext_bAcvInjCutOff_Ext_bAcvInjCutOff(&variable)

/**********************************************************************************
   Create interface for variable Ext_bAcvSpcInjModProtECU
  **********************************************************************************/

#define vidSET_VALUE_Ext_bAcvSpcInjModProtECU(value)                             Rte_Write_P_Ext_bAcvSpcInjModProtECU_Ext_bAcvSpcInjModProtECU(value)
#define vidGET_VALUE_Ext_bAcvSpcInjModProtECU(variable)                          Rte_Read_R_Ext_bAcvSpcInjModProtECU_Ext_bAcvSpcInjModProtECU(&variable)

/**********************************************************************************
   Create interface for variable Ext_bAcvSta
  **********************************************************************************/

#define vidSET_VALUE_Ext_bAcvSta(value)                                          Rte_Write_P_Ext_bAcvSta_Ext_bAcvSta(value)
#define vidGET_VALUE_Ext_bAcvSta(variable)                                       Rte_Read_R_Ext_bAcvSta_Ext_bAcvSta(&variable)

/**********************************************************************************
   Create interface for variable Ext_bArchiCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bArchiCf(value)                                         Rte_Write_P_Ext_bArchiCf_Ext_bArchiCf(value)
#define vidGET_VALUE_Ext_bArchiCf(variable)                                      Rte_Read_R_Ext_bArchiCf_Ext_bArchiCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bAuthWupElMgt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bAuthWupElMgt(value)                                    Rte_Write_P_Ext_bAuthWupElMgt_Ext_bAuthWupElMgt(value)
#define vidGET_VALUE_Ext_bAuthWupElMgt(variable)                                 Rte_Read_R_Ext_bAuthWupElMgt_Ext_bAuthWupElMgt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bBrkAutoCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bBrkAutoCf(value)                                       Rte_Write_P_Ext_bBrkAutoCf_Ext_bBrkAutoCf(value)
#define vidGET_VALUE_Ext_bBrkAutoCf(variable)                                    Rte_Read_R_Ext_bBrkAutoCf_Ext_bBrkAutoCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bBrkDynCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bBrkDynCf(value)                                        Rte_Write_P_Ext_bBrkDynCf_Ext_bBrkDynCf(value)
#define vidGET_VALUE_Ext_bBrkDynCf(variable)                                     Rte_Read_R_Ext_bBrkDynCf_Ext_bBrkDynCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bBrkPedPrss
  **********************************************************************************/

#define vidSET_VALUE_Ext_bBrkPedPrss(value)                                      Rte_Write_P_Ext_bBrkPedPrss_Ext_bBrkPedPrss(value)
#define vidGET_VALUE_Ext_bBrkPedPrss(variable)                                   Rte_Read_R_Ext_bBrkPedPrss_Ext_bBrkPedPrss(&variable)

/**********************************************************************************
   Create interface for variable Ext_bCluPedPrss
  **********************************************************************************/

#define vidSET_VALUE_Ext_bCluPedPrss(value)                                      Rte_Write_P_Ext_bCluPedPrss_Ext_bCluPedPrss(value)
#define vidGET_VALUE_Ext_bCluPedPrss(variable)                                   Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(&variable)

/**********************************************************************************
   Create interface for variable Ext_bCoReqVehCf_bEngStrtReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bCoReqVehCf_bEngStrtReq(value)                          Rte_Write_P_Ext_bCoReqVehCf_bEngStrtReq_Ext_bCoReqVehCf_bEngStrtReq(value)
#define vidGET_VALUE_Ext_bCoReqVehCf_bEngStrtReq(variable)                       Rte_Read_R_Ext_bCoReqVehCf_bEngStrtReq_Ext_bCoReqVehCf_bEngStrtReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bCtlCmdPTTqCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bCtlCmdPTTqCf(value)                                    Rte_Write_P_Ext_bCtlCmdPTTqCf_Ext_bCtlCmdPTTqCf(value)
#define vidGET_VALUE_Ext_bCtlCmdPTTqCf(variable)                                 Rte_Read_R_Ext_bCtlCmdPTTqCf_Ext_bCtlCmdPTTqCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bDetLoWhlGripCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bDetLoWhlGripCf(value)                                  Rte_Write_P_Ext_bDetLoWhlGripCf_Ext_bDetLoWhlGripCf(value)
#define vidGET_VALUE_Ext_bDetLoWhlGripCf(variable)                               Rte_Read_R_Ext_bDetLoWhlGripCf_Ext_bDetLoWhlGripCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bDgoSenPN
  **********************************************************************************/

#define vidSET_VALUE_Ext_bDgoSenPN(value)                                        Rte_Write_P_Ext_bDgoSenPN_Ext_bDgoSenPN(value)
#define vidGET_VALUE_Ext_bDgoSenPN(variable)                                     Rte_Read_R_Ext_bDgoSenPN_Ext_bDgoSenPN(&variable)

/**********************************************************************************
   Create interface for variable Ext_bDirRotCk
  **********************************************************************************/

#define vidSET_VALUE_Ext_bDirRotCk(value)                                        Rte_Write_P_Ext_bDirRotCk_Ext_bDirRotCk(value)
#define vidGET_VALUE_Ext_bDirRotCk(variable)                                     Rte_Read_R_Ext_bDirRotCk_Ext_bDirRotCk(&variable)

/**********************************************************************************
   Create interface for variable Ext_bDrvStrtReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bDrvStrtReq(value)                                      Rte_Write_P_Ext_bDrvStrtReq_Ext_bDrvStrtReq(value)
#define vidGET_VALUE_Ext_bDrvStrtReq(variable)                                   Rte_Read_R_Ext_bDrvStrtReq_Ext_bDrvStrtReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bDrvTraAMT
  **********************************************************************************/

#define vidSET_VALUE_Ext_bDrvTraAMT(value)                                       Rte_Write_P_Ext_bDrvTraAMT_Ext_bDrvTraAMT(value)
#define vidGET_VALUE_Ext_bDrvTraAMT(variable)                                    Rte_Read_R_Ext_bDrvTraAMT_Ext_bDrvTraAMT(&variable)

/**********************************************************************************
   Create interface for variable Ext_bEPB
  **********************************************************************************/

#define vidSET_VALUE_Ext_bEPB(value)                                             Rte_Write_P_Ext_bEPB_Ext_bEPB(value)
#define vidGET_VALUE_Ext_bEPB(variable)                                          Rte_Read_R_Ext_bEPB_Ext_bEPB(&variable)

/**********************************************************************************
   Create interface for variable Ext_bESPReg
  **********************************************************************************/

#define vidSET_VALUE_Ext_bESPReg(value)                                          Rte_Write_P_Ext_bESPReg_Ext_bESPReg(value)
#define vidGET_VALUE_Ext_bESPReg(variable)                                       Rte_Read_R_Ext_bESPReg_Ext_bESPReg(&variable)

/**********************************************************************************
   Create interface for variable Ext_bEfcBrkPedPrss
  **********************************************************************************/

#define vidSET_VALUE_Ext_bEfcBrkPedPrss(value)                                   Rte_Write_P_Ext_bEfcBrkPedPrss_Ext_bEfcBrkPedPrss(value)
#define vidGET_VALUE_Ext_bEfcBrkPedPrss(variable)                                Rte_Read_R_Ext_bEfcBrkPedPrss_Ext_bEfcBrkPedPrss(&variable)

/**********************************************************************************
   Create interface for variable Ext_bElecItgrReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bElecItgrReq(value)                                     Rte_Write_P_Ext_bElecItgrReq_Ext_bElecItgrReq(value)
#define vidGET_VALUE_Ext_bElecItgrReq(variable)                                  Rte_Read_R_Ext_bElecItgrReq_Ext_bElecItgrReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bEngReStrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bEngReStrt(value)                                       Rte_Write_P_Ext_bEngReStrt_Ext_bEngReStrt(value)
#define vidGET_VALUE_Ext_bEngReStrt(variable)                                    Rte_Read_R_Ext_bEngReStrt_Ext_bEngReStrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bEngStopReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bEngStopReq(value)                                      Rte_Write_P_Ext_bEngStopReq_Ext_bEngStopReq(value)
#define vidGET_VALUE_Ext_bEngStopReq(variable)                                   Rte_Read_R_Ext_bEngStopReq_Ext_bEngStopReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bEngStrtReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bEngStrtReq(value)                                      Rte_Write_P_Ext_bEngStrtReq_Ext_bEngStrtReq(value)
#define vidGET_VALUE_Ext_bEngStrtReq(variable)                                   Rte_Read_R_Ext_bEngStrtReq_Ext_bEngStrtReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bFSFCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bFSFCf(value)                                           Rte_Write_P_Ext_bFSFCf_Ext_bFSFCf(value)
#define vidGET_VALUE_Ext_bFSFCf(variable)                                        Rte_Read_R_Ext_bFSFCf_Ext_bFSFCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bFctHldReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bFctHldReq(value)                                       Rte_Write_P_Ext_bFctHldReq_Ext_bFctHldReq(value)
#define vidGET_VALUE_Ext_bFctHldReq(variable)                                    Rte_Read_R_Ext_bFctHldReq_Ext_bFctHldReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bFirstStrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bFirstStrt(value)                                       Rte_Write_P_Ext_bFirstStrt_Ext_bFirstStrt(value)
#define vidGET_VALUE_Ext_bFirstStrt(variable)                                    Rte_Read_R_Ext_bFirstStrt_Ext_bFirstStrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bIdlAcv
  **********************************************************************************/

#define vidSET_VALUE_Ext_bIdlAcv(value)                                          Rte_Write_P_Ext_bIdlAcv_Ext_bIdlAcv(value)
#define vidGET_VALUE_Ext_bIdlAcv(variable)                                       Rte_Read_R_Ext_bIdlAcv_Ext_bIdlAcv(&variable)

/**********************************************************************************
   Create interface for variable Ext_bInhStrtAMT
  **********************************************************************************/

#define vidSET_VALUE_Ext_bInhStrtAMT(value)                                      Rte_Write_P_Ext_bInhStrtAMT_Ext_bInhStrtAMT(value)
#define vidGET_VALUE_Ext_bInhStrtAMT(variable)                                   Rte_Read_R_Ext_bInhStrtAMT_Ext_bInhStrtAMT(&variable)

/**********************************************************************************
   Create interface for variable Ext_bKeyOff
  **********************************************************************************/

#define vidSET_VALUE_Ext_bKeyOff(value)                                          Rte_Write_P_Ext_bKeyOff_Ext_bKeyOff(value)
#define vidGET_VALUE_Ext_bKeyOff(variable)                                       Rte_Read_R_Ext_bKeyOff_Ext_bKeyOff(&variable)

/**********************************************************************************
   Create interface for variable Ext_bKeyOn
  **********************************************************************************/

#define vidSET_VALUE_Ext_bKeyOn(value)                                           Rte_Write_P_Ext_bKeyOn_Ext_bKeyOn(value)
#define vidGET_VALUE_Ext_bKeyOn(variable)                                        Rte_Read_R_Ext_bKeyOn_Ext_bKeyOn(&variable)

/**********************************************************************************
   Create interface for variable Ext_bModSpt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bModSpt(value)                                          Rte_Write_P_Ext_bModSpt_Ext_bModSpt(value)
#define vidGET_VALUE_Ext_bModSpt(variable)                                       Rte_Read_R_Ext_bModSpt_Ext_bModSpt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNeut
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNeut(value)                                            Rte_Write_P_Ext_bNeut_Ext_bNeut(value)
#define vidGET_VALUE_Ext_bNeut(variable)                                         Rte_Read_R_Ext_bNeut_Ext_bNeut(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_iBattMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_iBattMes(value)                                 Rte_Write_P_Ext_bNotAvl_iBattMes_Ext_bNotAvl_iBattMes(value)
#define vidGET_VALUE_Ext_bNotAvl_iBattMes(variable)                              Rte_Read_R_Ext_bNotAvl_iBattMes_Ext_bNotAvl_iBattMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_rBattSoC
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_rBattSoC(value)                                 Rte_Write_P_Ext_bNotAvl_rBattSoC_Ext_bNotAvl_rBattSoC(value)
#define vidGET_VALUE_Ext_bNotAvl_rBattSoC(variable)                              Rte_Read_R_Ext_bNotAvl_rBattSoC_Ext_bNotAvl_rBattSoC(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_rBattSoCLoResl
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_rBattSoCLoResl(value)                           Rte_Write_P_Ext_bNotAvl_rBattSoCLoResl_Ext_bNotAvl_rBattSoCLoResl(value)
#define vidGET_VALUE_Ext_bNotAvl_rBattSoCLoResl(variable)                        Rte_Read_R_Ext_bNotAvl_rBattSoCLoResl_Ext_bNotAvl_rBattSoCLoResl(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_resBattIt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_resBattIt(value)                                Rte_Write_P_Ext_bNotAvl_resBattIt_Ext_bNotAvl_resBattIt(value)
#define vidGET_VALUE_Ext_bNotAvl_resBattIt(variable)                             Rte_Read_R_Ext_bNotAvl_resBattIt_Ext_bNotAvl_resBattIt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_tBattMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_tBattMes(value)                                 Rte_Write_P_Ext_bNotAvl_tBattMes_Ext_bNotAvl_tBattMes(value)
#define vidGET_VALUE_Ext_bNotAvl_tBattMes(variable)                              Rte_Read_R_Ext_bNotAvl_tBattMes_Ext_bNotAvl_tBattMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_uBattClc
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_uBattClc(value)                                 Rte_Write_P_Ext_bNotAvl_uBattClc_Ext_bNotAvl_uBattClc(value)
#define vidGET_VALUE_Ext_bNotAvl_uBattClc(variable)                              Rte_Read_R_Ext_bNotAvl_uBattClc_Ext_bNotAvl_uBattClc(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_uBattOc
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_uBattOc(value)                                  Rte_Write_P_Ext_bNotAvl_uBattOc_Ext_bNotAvl_uBattOc(value)
#define vidGET_VALUE_Ext_bNotAvl_uBattOc(variable)                               Rte_Read_R_Ext_bNotAvl_uBattOc_Ext_bNotAvl_uBattOc(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_uBattRstrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_uBattRstrt(value)                               Rte_Write_P_Ext_bNotAvl_uBattRstrt_Ext_bNotAvl_uBattRstrt(value)
#define vidGET_VALUE_Ext_bNotAvl_uBattRstrt(variable)                            Rte_Read_R_Ext_bNotAvl_uBattRstrt_Ext_bNotAvl_uBattRstrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bNotAvl_uBattStrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bNotAvl_uBattStrt(value)                                Rte_Write_P_Ext_bNotAvl_uBattStrt_Ext_bNotAvl_uBattStrt(value)
#define vidGET_VALUE_Ext_bNotAvl_uBattStrt(variable)                             Rte_Read_R_Ext_bNotAvl_uBattStrt_Ext_bNotAvl_uBattStrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPosnGBxCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPosnGBxCf(value)                                       Rte_Write_P_Ext_bPosnGBxCf_Ext_bPosnGBxCf(value)
#define vidGET_VALUE_Ext_bPosnGBxCf(variable)                                    Rte_Read_R_Ext_bPosnGBxCf_Ext_bPosnGBxCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPostRunReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPostRunReq(value)                                      Rte_Write_P_Ext_bPostRunReq_Ext_bPostRunReq(value)
#define vidGET_VALUE_Ext_bPostRunReq(variable)                                   Rte_Read_R_Ext_bPostRunReq_Ext_bPostRunReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPresExCmSen
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPresExCmSen(value)                                     Rte_Write_P_Ext_bPresExCmSen_Ext_bPresExCmSen(value)
#define vidGET_VALUE_Ext_bPresExCmSen(variable)                                  Rte_Read_R_Ext_bPresExCmSen_Ext_bPresExCmSen(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPresGaz
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPresGaz(value)                                         Rte_Write_P_Ext_bPresGaz_Ext_bPresGaz(value)
#define vidGET_VALUE_Ext_bPresGaz(variable)                                      Rte_Read_R_Ext_bPresGaz_Ext_bPresGaz(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPresInCmSen
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPresInCmSen(value)                                     Rte_Write_P_Ext_bPresInCmSen_Ext_bPresInCmSen(value)
#define vidGET_VALUE_Ext_bPresInCmSen(variable)                                  Rte_Read_R_Ext_bPresInCmSen_Ext_bPresInCmSen(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPrkBrk
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPrkBrk(value)                                          Rte_Write_P_Ext_bPrkBrk_Ext_bPrkBrk(value)
#define vidGET_VALUE_Ext_bPrkBrk(variable)                                       Rte_Read_R_Ext_bPrkBrk_Ext_bPrkBrk(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPush
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPush(value)                                            Rte_Write_P_Ext_bPush_Ext_bPush(value)
#define vidGET_VALUE_Ext_bPush(variable)                                         Rte_Read_R_Ext_bPush_Ext_bPush(&variable)

/**********************************************************************************
   Create interface for variable Ext_bPwrlAcv
  **********************************************************************************/

#define vidSET_VALUE_Ext_bPwrlAcv(value)                                         Rte_Write_P_Ext_bPwrlAcv_Ext_bPwrlAcv(value)
#define vidGET_VALUE_Ext_bPwrlAcv(variable)                                      Rte_Read_R_Ext_bPwrlAcv_Ext_bPwrlAcv(&variable)

/**********************************************************************************
   Create interface for variable Ext_bRCDLine
  **********************************************************************************/

#define vidSET_VALUE_Ext_bRCDLine(value)                                         Rte_Write_P_Ext_bRCDLine_Ext_bRCDLine(value)
#define vidGET_VALUE_Ext_bRCDLine(variable)                                      Rte_Read_R_Ext_bRCDLine_Ext_bRCDLine(&variable)

/**********************************************************************************
   Create interface for variable Ext_bRStrtAuthTra
  **********************************************************************************/

#define vidSET_VALUE_Ext_bRStrtAuthTra(value)                                    Rte_Write_P_Ext_bRStrtAuthTra_Ext_bRStrtAuthTra(value)
#define vidGET_VALUE_Ext_bRStrtAuthTra(variable)                                 Rte_Read_R_Ext_bRStrtAuthTra_Ext_bRStrtAuthTra(&variable)

/**********************************************************************************
   Create interface for variable Ext_bRatConvTraCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bRatConvTraCf(value)                                    Rte_Write_P_Ext_bRatConvTraCf_Ext_bRatConvTraCf(value)
#define vidGET_VALUE_Ext_bRatConvTraCf(variable)                                 Rte_Read_R_Ext_bRatConvTraCf_Ext_bRatConvTraCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bRotSpdFrntWhlCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bRotSpdFrntWhlCf(value)                                 Rte_Write_P_Ext_bRotSpdFrntWhlCf_Ext_bRotSpdFrntWhlCf(value)
#define vidGET_VALUE_Ext_bRotSpdFrntWhlCf(variable)                              Rte_Read_R_Ext_bRotSpdFrntWhlCf_Ext_bRotSpdFrntWhlCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bRun
  **********************************************************************************/

#define vidSET_VALUE_Ext_bRun(value)                                             Rte_Write_P_Ext_bRun_Ext_bRun(value)
#define vidGET_VALUE_Ext_bRun(variable)                                          Rte_Read_R_Ext_bRun_Ext_bRun(&variable)

/**********************************************************************************
   Create interface for variable Ext_bRvs
  **********************************************************************************/

#define vidSET_VALUE_Ext_bRvs(value)                                             Rte_Write_P_Ext_bRvs_Ext_bRvs(value)
#define vidGET_VALUE_Ext_bRvs(variable)                                          Rte_Read_R_Ext_bRvs_Ext_bRvs(&variable)

/**********************************************************************************
   Create interface for variable Ext_bRvsVld
  **********************************************************************************/

#define vidSET_VALUE_Ext_bRvsVld(value)                                          Rte_Write_P_Ext_bRvsVld_Ext_bRvsVld(value)
#define vidGET_VALUE_Ext_bRvsVld(variable)                                       Rte_Read_R_Ext_bRvsVld_Ext_bRvsVld(&variable)

/**********************************************************************************
   Create interface for variable Ext_bSTTCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bSTTCf(value)                                           Rte_Write_P_Ext_bSTTCf_Ext_bSTTCf(value)
#define vidGET_VALUE_Ext_bSTTCf(variable)                                        Rte_Read_R_Ext_bSTTCf_Ext_bSTTCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bSecBrkPedPrssMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_bSecBrkPedPrssMes(value)                                Rte_Write_P_Ext_bSecBrkPedPrssMes_Ext_bSecBrkPedPrssMes(value)
#define vidGET_VALUE_Ext_bSecBrkPedPrssMes(variable)                             Rte_Read_R_Ext_bSecBrkPedPrssMes_Ext_bSecBrkPedPrssMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_bSpdFrntWhlCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bSpdFrntWhlCf(value)                                    Rte_Write_P_Ext_bSpdFrntWhlCf_Ext_bSpdFrntWhlCf(value)
#define vidGET_VALUE_Ext_bSpdFrntWhlCf(variable)                                 Rte_Read_R_Ext_bSpdFrntWhlCf_Ext_bSpdFrntWhlCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bSpdReWhlCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bSpdReWhlCf(value)                                      Rte_Write_P_Ext_bSpdReWhlCf_Ext_bSpdReWhlCf(value)
#define vidGET_VALUE_Ext_bSpdReWhlCf(variable)                                   Rte_Read_R_Ext_bSpdReWhlCf_Ext_bSpdReWhlCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bStaCmdFctSt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bStaCmdFctSt(value)                                     Rte_Write_P_Ext_bStaCmdFctSt_Ext_bStaCmdFctSt(value)
#define vidGET_VALUE_Ext_bStaCmdFctSt(variable)                                  Rte_Read_R_Ext_bStaCmdFctSt_Ext_bStaCmdFctSt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bStrtEnd
  **********************************************************************************/

#define vidSET_VALUE_Ext_bStrtEnd(value)                                         Rte_Write_P_Ext_bStrtEnd_Ext_bStrtEnd(value)
#define vidGET_VALUE_Ext_bStrtEnd(variable)                                      Rte_Read_R_Ext_bStrtEnd_Ext_bStrtEnd(&variable)

/**********************************************************************************
   Create interface for variable Ext_bSync
  **********************************************************************************/

#define vidSET_VALUE_Ext_bSync(value)                                            Rte_Write_P_Ext_bSync_Ext_bSync(value)
#define vidGET_VALUE_Ext_bSync(variable)                                         Rte_Read_R_Ext_bSync_Ext_bSync(&variable)

/**********************************************************************************
   Create interface for variable Ext_bTOilChk
  **********************************************************************************/

#define vidSET_VALUE_Ext_bTOilChk(value)                                         Rte_Write_P_Ext_bTOilChk_Ext_bTOilChk(value)
#define vidGET_VALUE_Ext_bTOilChk(variable)                                      Rte_Read_R_Ext_bTOilChk_Ext_bTOilChk(&variable)

/**********************************************************************************
   Create interface for variable Ext_bTqWhlBrkCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bTqWhlBrkCf(value)                                      Rte_Write_P_Ext_bTqWhlBrkCf_Ext_bTqWhlBrkCf(value)
#define vidGET_VALUE_Ext_bTqWhlBrkCf(variable)                                   Rte_Read_R_Ext_bTqWhlBrkCf_Ext_bTqWhlBrkCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bTypStrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bTypStrt(value)                                         Rte_Write_P_Ext_bTypStrt_Ext_bTypStrt(value)
#define vidGET_VALUE_Ext_bTypStrt(variable)                                      Rte_Read_R_Ext_bTypStrt_Ext_bTypStrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bTyreWarnCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bTyreWarnCf(value)                                      Rte_Write_P_Ext_bTyreWarnCf_Ext_bTyreWarnCf(value)
#define vidGET_VALUE_Ext_bTyreWarnCf(variable)                                   Rte_Read_R_Ext_bTyreWarnCf_Ext_bTyreWarnCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bVSLimCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bVSLimCf(value)                                         Rte_Write_P_Ext_bVSLimCf_Ext_bVSLimCf(value)
#define vidGET_VALUE_Ext_bVSLimCf(variable)                                      Rte_Read_R_Ext_bVSLimCf_Ext_bVSLimCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bVSMaxfCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bVSMaxfCf(value)                                        Rte_Write_P_Ext_bVSMaxfCf_Ext_bVSMaxfCf(value)
#define vidGET_VALUE_Ext_bVSMaxfCf(variable)                                     Rte_Read_R_Ext_bVSMaxfCf_Ext_bVSMaxfCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bVSMaxpCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bVSMaxpCf(value)                                        Rte_Write_P_Ext_bVSMaxpCf_Ext_bVSMaxpCf(value)
#define vidGET_VALUE_Ext_bVSMaxpCf(variable)                                     Rte_Read_R_Ext_bVSMaxpCf_Ext_bVSMaxpCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bVSMaxsCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_bVSMaxsCf(value)                                        Rte_Write_P_Ext_bVSMaxsCf_Ext_bVSMaxsCf(value)
#define vidGET_VALUE_Ext_bVSMaxsCf(variable)                                     Rte_Read_R_Ext_bVSMaxsCf_Ext_bVSMaxsCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_bVSSNwAcvSt
  **********************************************************************************/

#define vidSET_VALUE_Ext_bVSSNwAcvSt(value)                                      Rte_Write_P_Ext_bVSSNwAcvSt_Ext_bVSSNwAcvSt(value)
#define vidGET_VALUE_Ext_bVSSNwAcvSt(variable)                                   Rte_Read_R_Ext_bVSSNwAcvSt_Ext_bVSSNwAcvSt(&variable)

/**********************************************************************************
   Create interface for variable Ext_bVehCollWarn
  **********************************************************************************/

#define vidSET_VALUE_Ext_bVehCollWarn(value)                                     Rte_Write_P_Ext_bVehCollWarn_Ext_bVehCollWarn(value)
#define vidGET_VALUE_Ext_bVehCollWarn(variable)                                  Rte_Read_R_Ext_bVehCollWarn_Ext_bVehCollWarn(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfAcvConstElMgt1
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfAcvConstElMgt1(value)                                 Rte_Write_P_Ext_bfAcvConstElMgt1_Ext_bfAcvConstElMgt1(value)
#define vidGET_VALUE_Ext_bfAcvConstElMgt1(variable)                              Rte_Read_R_Ext_bfAcvConstElMgt1_Ext_bfAcvConstElMgt1(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfAcvConstElMgt2
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfAcvConstElMgt2(value)                                 Rte_Write_P_Ext_bfAcvConstElMgt2_Ext_bfAcvConstElMgt2(value)
#define vidGET_VALUE_Ext_bfAcvConstElMgt2(variable)                              Rte_Read_R_Ext_bfAcvConstElMgt2_Ext_bfAcvConstElMgt2(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfAcvConstElMgt3
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfAcvConstElMgt3(value)                                 Rte_Write_P_Ext_bfAcvConstElMgt3_Ext_bfAcvConstElMgt3(value)
#define vidGET_VALUE_Ext_bfAcvConstElMgt3(variable)                              Rte_Read_R_Ext_bfAcvConstElMgt3_Ext_bfAcvConstElMgt3(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfAcvConstEng1
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfAcvConstEng1(value)                                   Rte_Write_P_Ext_bfAcvConstEng1_Ext_bfAcvConstEng1(value)
#define vidGET_VALUE_Ext_bfAcvConstEng1(variable)                                Rte_Read_R_Ext_bfAcvConstEng1_Ext_bfAcvConstEng1(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfAcvConstReTra1
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfAcvConstReTra1(value)                                 Rte_Write_P_Ext_bfAcvConstReTra1_Ext_bfAcvConstReTra1(value)
#define vidGET_VALUE_Ext_bfAcvConstReTra1(variable)                              Rte_Read_R_Ext_bfAcvConstReTra1_Ext_bfAcvConstReTra1(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfMstPtlWkuHldReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfMstPtlWkuHldReq(value)                                Rte_Write_P_Ext_bfMstPtlWkuHldReq_Ext_bfMstPtlWkuHldReq(value)
#define vidGET_VALUE_Ext_bfMstPtlWkuHldReq(variable)                             Rte_Read_R_Ext_bfMstPtlWkuHldReq_Ext_bfMstPtlWkuHldReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfMstPtlWkuNd
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfMstPtlWkuNd(value)                                    Rte_Write_P_Ext_bfMstPtlWkuNd_Ext_bfMstPtlWkuNd(value)
#define vidGET_VALUE_Ext_bfMstPtlWkuNd(variable)                                 Rte_Read_R_Ext_bfMstPtlWkuNd_Ext_bfMstPtlWkuNd(&variable)

/**********************************************************************************
   Create interface for variable Ext_bfSlavePtlWkuReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_bfSlavePtlWkuReq(value)                                 Rte_Write_P_Ext_bfSlavePtlWkuReq_Ext_bfSlavePtlWkuReq(value)
#define vidGET_VALUE_Ext_bfSlavePtlWkuReq(variable)                              Rte_Read_R_Ext_bfSlavePtlWkuReq_Ext_bfSlavePtlWkuReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_ctDay
  **********************************************************************************/

#define vidSET_VALUE_Ext_ctDay(value)                                            Rte_Write_P_Ext_ctDay_Ext_ctDay(value)
#define vidGET_VALUE_Ext_ctDay(variable)                                         Rte_Read_R_Ext_ctDay_Ext_ctDay(&variable)

/**********************************************************************************
   Create interface for variable Ext_ctInj
  **********************************************************************************/

#define vidSET_VALUE_Ext_ctInj(value)                                            Rte_Write_P_Ext_ctInj_Ext_ctInj(value)
#define vidGET_VALUE_Ext_ctInj(variable)                                         Rte_Read_R_Ext_ctInj_Ext_ctInj(&variable)

/**********************************************************************************
   Create interface for variable Ext_ctSec
  **********************************************************************************/

#define vidSET_VALUE_Ext_ctSec(value)                                            Rte_Write_P_Ext_ctSec_Ext_ctSec(value)
#define vidGET_VALUE_Ext_ctSec(variable)                                         Rte_Read_R_Ext_ctSec_Ext_ctSec(&variable)

/**********************************************************************************
   Create interface for variable Ext_ctYr
  **********************************************************************************/

#define vidSET_VALUE_Ext_ctYr(value)                                             Rte_Write_P_Ext_ctYr_Ext_ctYr(value)
#define vidGET_VALUE_Ext_ctYr(variable)                                          Rte_Read_R_Ext_ctYr_Ext_ctYr(&variable)

/**********************************************************************************
   Create interface for variable Ext_dstVehMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_dstVehMes(value)                                        Rte_Write_P_Ext_dstVehMes_Ext_dstVehMes(value)
#define vidGET_VALUE_Ext_dstVehMes(variable)                                     Rte_Read_R_Ext_dstVehMes_Ext_dstVehMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_dstVehTotMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_dstVehTotMes(value)                                     Rte_Write_P_Ext_dstVehTotMes_Ext_dstVehTotMes(value)
#define vidGET_VALUE_Ext_dstVehTotMes(variable)                                  Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_facRatTqAltCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_facRatTqAltCf(value)                                    Rte_Write_P_Ext_facRatTqAltCf_Ext_facRatTqAltCf(value)
#define vidGET_VALUE_Ext_facRatTqAltCf(variable)                                 Rte_Read_R_Ext_facRatTqAltCf_Ext_facRatTqAltCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_iAltExct
  **********************************************************************************/

#define vidSET_VALUE_Ext_iAltExct(value)                                         Rte_Write_P_Ext_iAltExct_Ext_iAltExct(value)
#define vidGET_VALUE_Ext_iAltExct(variable)                                      Rte_Read_R_Ext_iAltExct_Ext_iAltExct(&variable)

/**********************************************************************************
   Create interface for variable Ext_iBattMaxCkg
  **********************************************************************************/

#define vidSET_VALUE_Ext_iBattMaxCkg(value)                                      Rte_Write_P_Ext_iBattMaxCkg_Ext_iBattMaxCkg(value)
#define vidGET_VALUE_Ext_iBattMaxCkg(variable)                                   Rte_Read_R_Ext_iBattMaxCkg_Ext_iBattMaxCkg(&variable)

/**********************************************************************************
   Create interface for variable Ext_iBattMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_iBattMes(value)                                         Rte_Write_P_Ext_iBattMes_Ext_iBattMes(value)
#define vidGET_VALUE_Ext_iBattMes(variable)                                      Rte_Read_R_Ext_iBattMes_Ext_iBattMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_idxAltClas
  **********************************************************************************/

#define vidSET_VALUE_Ext_idxAltClas(value)                                       Rte_Write_P_Ext_idxAltClas_Ext_idxAltClas(value)
#define vidGET_VALUE_Ext_idxAltClas(variable)                                    Rte_Read_R_Ext_idxAltClas_Ext_idxAltClas(&variable)

/**********************************************************************************
   Create interface for variable Ext_idxCtlAltProvIdf
  **********************************************************************************/

#define vidSET_VALUE_Ext_idxCtlAltProvIdf(value)                                 Rte_Write_P_Ext_idxCtlAltProvIdf_Ext_idxCtlAltProvIdf(value)
#define vidGET_VALUE_Ext_idxCtlAltProvIdf(variable)                              Rte_Read_R_Ext_idxCtlAltProvIdf_Ext_idxCtlAltProvIdf(&variable)

/**********************************************************************************
   Create interface for variable Ext_nAvrFrntWhlCAN
  **********************************************************************************/

#define vidSET_VALUE_Ext_nAvrFrntWhlCAN(value)                                   Rte_Write_P_Ext_nAvrFrntWhlCAN_Ext_nAvrFrntWhlCAN(value)
#define vidGET_VALUE_Ext_nAvrFrntWhlCAN(variable)                                Rte_Read_R_Ext_nAvrFrntWhlCAN_Ext_nAvrFrntWhlCAN(&variable)

/**********************************************************************************
   Create interface for variable Ext_nEng
  **********************************************************************************/

#define vidSET_VALUE_Ext_nEng(value)                                             Rte_Write_P_Ext_nEng_Ext_nEng(value)
#define vidGET_VALUE_Ext_nEng(variable)                                          Rte_Read_R_Ext_nEng_Ext_nEng(&variable)

/**********************************************************************************
   Create interface for variable Ext_nEngAvr
  **********************************************************************************/

#define vidSET_VALUE_Ext_nEngAvr(value)
#define vidGET_VALUE_Ext_nEngAvr(variable)                                       Rte_Read_R_Ext_nEngAvr_Ext_nEngAvr(&variable)

/**********************************************************************************
   Create interface for variable Ext_nEngClc
  **********************************************************************************/

#define vidSET_VALUE_Ext_nEngClc(value)                                          Rte_Write_P_Ext_nEngClc_Ext_nEngClc(value)
#define vidGET_VALUE_Ext_nEngClc(variable)                                       Rte_Read_R_Ext_nEngClc_Ext_nEngClc(&variable)

/**********************************************************************************
   Create interface for variable Ext_nEngClc0
  **********************************************************************************/

#define vidSET_VALUE_Ext_nEngClc0(value)
#define vidGET_VALUE_Ext_nEngClc0(variable)                                      Rte_Read_R_Ext_nEngClc0_Ext_nEngClc0(&variable)

/**********************************************************************************
   Create interface for variable Ext_nEngGrd
  **********************************************************************************/

#define vidSET_VALUE_Ext_nEngGrd(value)                                          Rte_Write_P_Ext_nEngGrd_Ext_nEngGrd(value)
#define vidGET_VALUE_Ext_nEngGrd(variable)                                       Rte_Read_R_Ext_nEngGrd_Ext_nEngGrd(&variable)

/**********************************************************************************
   Create interface for variable Ext_nFrntWhl
  **********************************************************************************/

#define vidSET_VALUE_Ext_nFrntWhl(value)                                         Rte_Write_P_Ext_nFrntWhl_Ext_nFrntWhl(value)
#define vidGET_VALUE_Ext_nFrntWhl(variable)                                      Rte_Read_R_Ext_nFrntWhl_Ext_nFrntWhl(&variable)

/**********************************************************************************
   Create interface for variable Ext_noCylEng
  **********************************************************************************/

#define vidSET_VALUE_Ext_noCylEng(value)                                         Rte_Write_P_Ext_noCylEng_Ext_noCylEng(value)
#define vidGET_VALUE_Ext_noCylEng(variable)                                      Rte_Read_R_Ext_noCylEng_Ext_noCylEng(&variable)

/**********************************************************************************
   Create interface for variable Ext_pAC
  **********************************************************************************/

#define vidSET_VALUE_Ext_pAC(value)                                              Rte_Write_P_Ext_pAC_Ext_pAC(value)
#define vidGET_VALUE_Ext_pAC(variable)                                           Rte_Read_R_Ext_pAC_Ext_pAC(&variable)

/**********************************************************************************
   Create interface for variable Ext_pAirExtMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_pAirExtMes(value)                                       Rte_Write_P_Ext_pAirExtMes_Ext_pAirExtMes(value)
#define vidGET_VALUE_Ext_pAirExtMes(variable)                                    Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_pAirExtMesSI
  **********************************************************************************/

#define vidSET_VALUE_Ext_pAirExtMesSI(value)                                     Rte_Write_P_Ext_pAirExtMesSI_Ext_pAirExtMesSI(value)
#define vidGET_VALUE_Ext_pAirExtMesSI(variable)                                  Rte_Read_R_Ext_pAirExtMesSI_Ext_pAirExtMesSI(&variable)

/**********************************************************************************
   Create interface for variable Ext_pBrkAsi
  **********************************************************************************/

#define vidSET_VALUE_Ext_pBrkAsi(value)                                          Rte_Write_P_Ext_pBrkAsi_Ext_pBrkAsi(value)
#define vidGET_VALUE_Ext_pBrkAsi(variable)                                       Rte_Read_R_Ext_pBrkAsi_Ext_pBrkAsi(&variable)

/**********************************************************************************
   Create interface for variable Ext_pBrkMCT
  **********************************************************************************/

#define vidSET_VALUE_Ext_pBrkMCT(value)                                          Rte_Write_P_Ext_pBrkMCT_Ext_pBrkMCT(value)
#define vidGET_VALUE_Ext_pBrkMCT(variable)                                       Rte_Read_R_Ext_pBrkMCT_Ext_pBrkMCT(&variable)

/**********************************************************************************
   Create interface for variable Ext_pDsThrMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_pDsThrMes(value)                                        Rte_Write_P_Ext_pDsThrMes_Ext_pDsThrMes(value)
#define vidGET_VALUE_Ext_pDsThrMes(variable)                                     Rte_Read_R_Ext_pDsThrMes_Ext_pDsThrMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_pDsThrMesSI
  **********************************************************************************/

#define vidSET_VALUE_Ext_pDsThrMesSI(value)                                      Rte_Write_P_Ext_pDsThrMesSI_Ext_pDsThrMesSI(value)
#define vidGET_VALUE_Ext_pDsThrMesSI(variable)                                   Rte_Read_R_Ext_pDsThrMesSI_Ext_pDsThrMesSI(&variable)

/**********************************************************************************
   Create interface for variable Ext_pFuMesFineResl
  **********************************************************************************/

#define vidSET_VALUE_Ext_pFuMesFineResl(value)                                   Rte_Write_P_Ext_pFuMesFineResl_Ext_pFuMesFineResl(value)
#define vidGET_VALUE_Ext_pFuMesFineResl(variable)                                Rte_Read_R_Ext_pFuMesFineResl_Ext_pFuMesFineResl(&variable)

/**********************************************************************************
   Create interface for variable Ext_pOilMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_pOilMes(value)                                          Rte_Write_P_Ext_pOilMes_Ext_pOilMes(value)
#define vidGET_VALUE_Ext_pOilMes(variable)                                       Rte_Read_R_Ext_pOilMes_Ext_pOilMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_pOilMesSI
  **********************************************************************************/

#define vidSET_VALUE_Ext_pOilMesSI(value)                                        Rte_Write_P_Ext_pOilMesSI_Ext_pOilMesSI(value)
#define vidGET_VALUE_Ext_pOilMesSI(variable)                                     Rte_Read_R_Ext_pOilMesSI_Ext_pOilMesSI(&variable)

/**********************************************************************************
   Create interface for variable Ext_pRelBrkAsi
  **********************************************************************************/

#define vidSET_VALUE_Ext_pRelBrkAsi(value)                                       Rte_Write_P_Ext_pRelBrkAsi_Ext_pRelBrkAsi(value)
#define vidGET_VALUE_Ext_pRelBrkAsi(variable)                                    Rte_Read_R_Ext_pRelBrkAsi_Ext_pRelBrkAsi(&variable)

/**********************************************************************************
   Create interface for variable Ext_pUsThrMesSI
  **********************************************************************************/

#define vidSET_VALUE_Ext_pUsThrMesSI(value)                                      Rte_Write_P_Ext_pUsThrMesSI_Ext_pUsThrMesSI(value)
#define vidGET_VALUE_Ext_pUsThrMesSI(variable)                                   Rte_Read_R_Ext_pUsThrMesSI_Ext_pUsThrMesSI(&variable)

/**********************************************************************************
   Create interface for variable Ext_posnGBxLev
  **********************************************************************************/

#define vidSET_VALUE_Ext_posnGBxLev(value)                                       Rte_Write_P_Ext_posnGBxLev_Ext_posnGBxLev(value)
#define vidGET_VALUE_Ext_posnGBxLev(variable)                                    Rte_Read_R_Ext_posnGBxLev_Ext_posnGBxLev(&variable)

/**********************************************************************************
   Create interface for variable Ext_rAltCycOp
  **********************************************************************************/

#define vidSET_VALUE_Ext_rAltCycOp(value)                                        Rte_Write_P_Ext_rAltCycOp_Ext_rAltCycOp(value)
#define vidGET_VALUE_Ext_rAltCycOp(variable)                                     Rte_Read_R_Ext_rAltCycOp_Ext_rAltCycOp(&variable)

/**********************************************************************************
   Create interface for variable Ext_rBattSoC
  **********************************************************************************/

#define vidSET_VALUE_Ext_rBattSoC(value)                                         Rte_Write_P_Ext_rBattSoC_Ext_rBattSoC(value)
#define vidGET_VALUE_Ext_rBattSoC(variable)                                      Rte_Read_R_Ext_rBattSoC_Ext_rBattSoC(&variable)

/**********************************************************************************
   Create interface for variable Ext_rBattSoCLoResl
  **********************************************************************************/

#define vidSET_VALUE_Ext_rBattSoCLoResl(value)                                   Rte_Write_P_Ext_rBattSoCLoResl_Ext_rBattSoCLoResl(value)
#define vidGET_VALUE_Ext_rBattSoCLoResl(variable)                                Rte_Read_R_Ext_rBattSoCLoResl_Ext_rBattSoCLoResl(&variable)

/**********************************************************************************
   Create interface for variable Ext_rCluP
  **********************************************************************************/

#define vidSET_VALUE_Ext_rCluP(value)                                            Rte_Write_P_Ext_rCluP_Ext_rCluP(value)
#define vidGET_VALUE_Ext_rCluP(variable)                                         Rte_Read_R_Ext_rCluP_Ext_rCluP(&variable)

/**********************************************************************************
   Create interface for variable Ext_rCluPHiFreq
  **********************************************************************************/

#define vidSET_VALUE_Ext_rCluPHiFreq(value)                                      Rte_Write_P_Ext_rCluPHiFreq_Ext_rCluPHiFreq(value)
#define vidGET_VALUE_Ext_rCluPHiFreq(variable)                                   Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&variable)

/**********************************************************************************
   Create interface for variable Ext_rCtlIntTestMod
  **********************************************************************************/

#define vidSET_VALUE_Ext_rCtlIntTestMod(value)                                   Rte_Write_P_Ext_rCtlIntTestMod_Ext_rCtlIntTestMod(value)
#define vidGET_VALUE_Ext_rCtlIntTestMod(variable)                                Rte_Read_R_Ext_rCtlIntTestMod_Ext_rCtlIntTestMod(&variable)

/**********************************************************************************
   Create interface for variable Ext_rCtlTestMod
  **********************************************************************************/

#define vidSET_VALUE_Ext_rCtlTestMod(value)                                      Rte_Write_P_Ext_rCtlTestMod_Ext_rCtlTestMod(value)
#define vidGET_VALUE_Ext_rCtlTestMod(variable)                                   Rte_Read_R_Ext_rCtlTestMod_Ext_rCtlTestMod(&variable)

/**********************************************************************************
   Create interface for variable Ext_rOpTrbActMesSI
  **********************************************************************************/

#define vidSET_VALUE_Ext_rOpTrbActMesSI(value)                                   Rte_Write_P_Ext_rOpTrbActMesSI_Ext_rOpTrbActMesSI(value)
#define vidGET_VALUE_Ext_rOpTrbActMesSI(variable)                                Rte_Read_R_Ext_rOpTrbActMesSI_Ext_rOpTrbActMesSI(&variable)

/**********************************************************************************
   Create interface for variable Ext_rSpdFanAct
  **********************************************************************************/

#define vidSET_VALUE_Ext_rSpdFanAct(value)                                       Rte_Write_P_Ext_rSpdFanAct_Ext_rSpdFanAct(value)
#define vidGET_VALUE_Ext_rSpdFanAct(variable)                                    Rte_Read_R_Ext_rSpdFanAct_Ext_rSpdFanAct(&variable)

/**********************************************************************************
   Create interface for variable Ext_rTotLd
  **********************************************************************************/

#define vidSET_VALUE_Ext_rTotLd(value)                                           Rte_Write_P_Ext_rTotLd_Ext_rTotLd(value)
#define vidGET_VALUE_Ext_rTotLd(variable)                                        Rte_Read_R_Ext_rTotLd_Ext_rTotLd(&variable)

/**********************************************************************************
   Create interface for variable Ext_resBattIt
  **********************************************************************************/

#define vidSET_VALUE_Ext_resBattIt(value)                                        Rte_Write_P_Ext_resBattIt_Ext_resBattIt(value)
#define vidGET_VALUE_Ext_resBattIt(variable)                                     Rte_Read_R_Ext_resBattIt_Ext_resBattIt(&variable)

/**********************************************************************************
   Create interface for variable Ext_resBattItNorm
  **********************************************************************************/

#define vidSET_VALUE_Ext_resBattItNorm(value)                                    Rte_Write_P_Ext_resBattItNorm_Ext_resBattItNorm(value)
#define vidGET_VALUE_Ext_resBattItNorm(variable)                                 Rte_Read_R_Ext_resBattItNorm_Ext_resBattItNorm(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdFrntWhl
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdFrntWhl(value)                                       Rte_Write_P_Ext_spdFrntWhl_Ext_spdFrntWhl(value)
#define vidGET_VALUE_Ext_spdFrntWhl(variable)                                    Rte_Read_R_Ext_spdFrntWhl_Ext_spdFrntWhl(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdLeReWhl
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdLeReWhl(value)                                       Rte_Write_P_Ext_spdLeReWhl_Ext_spdLeReWhl(value)
#define vidGET_VALUE_Ext_spdLeReWhl(variable)                                    Rte_Read_R_Ext_spdLeReWhl_Ext_spdLeReWhl(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdReWhl
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdReWhl(value)                                         Rte_Write_P_Ext_spdReWhl_Ext_spdReWhl(value)
#define vidGET_VALUE_Ext_spdReWhl(variable)                                      Rte_Read_R_Ext_spdReWhl_Ext_spdReWhl(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdRiReWhl
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdRiReWhl(value)                                       Rte_Write_P_Ext_spdRiReWhl_Ext_spdRiReWhl(value)
#define vidGET_VALUE_Ext_spdRiReWhl(variable)                                    Rte_Read_R_Ext_spdRiReWhl_Ext_spdRiReWhl(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdVeh
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdVeh(value)                                           Rte_Write_P_Ext_spdVeh_Ext_spdVeh(value)
#define vidGET_VALUE_Ext_spdVeh(variable)                                        Rte_Read_R_Ext_spdVeh_Ext_spdVeh(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdVehAvrFrntWhl
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdVehAvrFrntWhl(value)                                 Rte_Write_P_Ext_spdVehAvrFrntWhl_Ext_spdVehAvrFrntWhl(value)
#define vidGET_VALUE_Ext_spdVehAvrFrntWhl(variable)                              Rte_Read_R_Ext_spdVehAvrFrntWhl_Ext_spdVehAvrFrntWhl(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdVehSecu
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdVehSecu(value)                                       Rte_Write_P_Ext_spdVehSecu_Ext_spdVehSecu(value)
#define vidGET_VALUE_Ext_spdVehSecu(variable)                                    Rte_Read_R_Ext_spdVehSecu_Ext_spdVehSecu(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdVehVSLimReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdVehVSLimReq(value)                                   Rte_Write_P_Ext_spdVehVSLimReq_Ext_spdVehVSLimReq(value)
#define vidGET_VALUE_Ext_spdVehVSLimReq(variable)                                Rte_Read_R_Ext_spdVehVSLimReq_Ext_spdVehVSLimReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdVehVSMaxPrmaReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdVehVSMaxPrmaReq(value)                               Rte_Write_P_Ext_spdVehVSMaxPrmaReq_Ext_spdVehVSMaxPrmaReq(value)
#define vidGET_VALUE_Ext_spdVehVSMaxPrmaReq(variable)                            Rte_Read_R_Ext_spdVehVSMaxPrmaReq_Ext_spdVehVSMaxPrmaReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_spdVehVSRegReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_spdVehVSRegReq(value)                                   Rte_Write_P_Ext_spdVehVSRegReq_Ext_spdVehVSRegReq(value)
#define vidGET_VALUE_Ext_spdVehVSRegReq(variable)                                Rte_Read_R_Ext_spdVehVSRegReq_Ext_spdVehVSRegReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_stACTypCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stACTypCf(value)                                        Rte_Write_P_Ext_stACTypCf_Ext_stACTypCf(value)
#define vidGET_VALUE_Ext_stACTypCf(variable)                                     Rte_Read_R_Ext_stACTypCf_Ext_stACTypCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stAcvRegVSCtlReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_stAcvRegVSCtlReq(value)                                 Rte_Write_P_Ext_stAcvRegVSCtlReq_Ext_stAcvRegVSCtlReq(value)
#define vidGET_VALUE_Ext_stAcvRegVSCtlReq(variable)                              Rte_Read_R_Ext_stAcvRegVSCtlReq_Ext_stAcvRegVSCtlReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_stAltClasCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stAltClasCf(value)                                      Rte_Write_P_Ext_stAltClasCf_Ext_stAltClasCf(value)
#define vidGET_VALUE_Ext_stAltClasCf(variable)                                   Rte_Read_R_Ext_stAltClasCf_Ext_stAltClasCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stBattSoC
  **********************************************************************************/

#define vidSET_VALUE_Ext_stBattSoC(value)                                        Rte_Write_P_Ext_stBattSoC_Ext_stBattSoC(value)
#define vidGET_VALUE_Ext_stBattSoC(variable)                                     Rte_Read_R_Ext_stBattSoC_Ext_stBattSoC(&variable)

/**********************************************************************************
   Create interface for variable Ext_stBattTypCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stBattTypCf(value)                                      Rte_Write_P_Ext_stBattTypCf_Ext_stBattTypCf(value)
#define vidGET_VALUE_Ext_stBattTypCf(variable)                                   Rte_Read_R_Ext_stBattTypCf_Ext_stBattTypCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stCtlCmdPTTqPotCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stCtlCmdPTTqPotCf(value)                                Rte_Write_P_Ext_stCtlCmdPTTqPotCf_Ext_stCtlCmdPTTqPotCf(value)
#define vidGET_VALUE_Ext_stCtlCmdPTTqPotCf(variable)                             Rte_Read_R_Ext_stCtlCmdPTTqPotCf_Ext_stCtlCmdPTTqPotCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stDVSRegCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stDVSRegCf(value)                                       Rte_Write_P_Ext_stDVSRegCf_Ext_stDVSRegCf(value)
#define vidGET_VALUE_Ext_stDVSRegCf(variable)                                    Rte_Read_R_Ext_stDVSRegCf_Ext_stDVSRegCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stDirMoveVehCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stDirMoveVehCf(value)                                   Rte_Write_P_Ext_stDirMoveVehCf_Ext_stDirMoveVehCf(value)
#define vidGET_VALUE_Ext_stDirMoveVehCf(variable)                                Rte_Read_R_Ext_stDirMoveVehCf_Ext_stDirMoveVehCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stDirMoveVehReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_stDirMoveVehReq(value)                                  Rte_Write_P_Ext_stDirMoveVehReq_Ext_stDirMoveVehReq(value)
#define vidGET_VALUE_Ext_stDirMoveVehReq(variable)                               Rte_Read_R_Ext_stDirMoveVehReq_Ext_stDirMoveVehReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_stElProdCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stElProdCf(value)                                       Rte_Write_P_Ext_stElProdCf_Ext_stElProdCf(value)
#define vidGET_VALUE_Ext_stElProdCf(variable)                                    Rte_Read_R_Ext_stElProdCf_Ext_stElProdCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stFuTypCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stFuTypCf(value)                                        Rte_Write_P_Ext_stFuTypCf_Ext_stFuTypCf(value)
#define vidGET_VALUE_Ext_stFuTypCf(variable)                                     Rte_Read_R_Ext_stFuTypCf_Ext_stFuTypCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stGBxCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stGBxCf(value)                                          Rte_Write_P_Ext_stGBxCf_Ext_stGBxCf(value)
#define vidGET_VALUE_Ext_stGBxCf(variable)                                       Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stMainWkuReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_stMainWkuReq(value)                                     Rte_Write_P_Ext_stMainWkuReq_Ext_stMainWkuReq(value)
#define vidGET_VALUE_Ext_stMainWkuReq(variable)                                  Rte_Read_R_Ext_stMainWkuReq_Ext_stMainWkuReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_stMeasAuth
  **********************************************************************************/

#define vidSET_VALUE_Ext_stMeasAuth(value)                                       Rte_Write_P_Ext_stMeasAuth_Ext_stMeasAuth(value)
#define vidGET_VALUE_Ext_stMeasAuth(variable)                                    Rte_Read_R_Ext_stMeasAuth_Ext_stMeasAuth(&variable)

/**********************************************************************************
   Create interface for variable Ext_stModRegVSCtlReq
  **********************************************************************************/

#define vidSET_VALUE_Ext_stModRegVSCtlReq(value)                                 Rte_Write_P_Ext_stModRegVSCtlReq_Ext_stModRegVSCtlReq(value)
#define vidGET_VALUE_Ext_stModRegVSCtlReq(variable)                              Rte_Read_R_Ext_stModRegVSCtlReq_Ext_stModRegVSCtlReq(&variable)

/**********************************************************************************
   Create interface for variable Ext_stPTCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stPTCf(value)                                           Rte_Write_P_Ext_stPTCf_Ext_stPTCf(value)
#define vidGET_VALUE_Ext_stPTCf(variable)                                        Rte_Read_R_Ext_stPTCf_Ext_stPTCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stStaCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stStaCf(value)                                          Rte_Write_P_Ext_stStaCf_Ext_stStaCf(value)
#define vidGET_VALUE_Ext_stStaCf(variable)                                       Rte_Read_R_Ext_stStaCf_Ext_stStaCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stStgPmpCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stStgPmpCf(value)                                       Rte_Write_P_Ext_stStgPmpCf_Ext_stStgPmpCf(value)
#define vidGET_VALUE_Ext_stStgPmpCf(variable)                                    Rte_Read_R_Ext_stStgPmpCf_Ext_stStgPmpCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stStrtCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stStrtCf(value)                                         Rte_Write_P_Ext_stStrtCf_Ext_stStrtCf(value)
#define vidGET_VALUE_Ext_stStrtCf(variable)                                      Rte_Read_R_Ext_stStrtCf_Ext_stStrtCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stSysGas
  **********************************************************************************/

#define vidSET_VALUE_Ext_stSysGas(value)                                         Rte_Write_P_Ext_stSysGas_Ext_stSysGas(value)
#define vidGET_VALUE_Ext_stSysGas(variable)                                      Rte_Read_R_Ext_stSysGas_Ext_stSysGas(&variable)

/**********************************************************************************
   Create interface for variable Ext_stTraTypCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stTraTypCf(value)                                       Rte_Write_P_Ext_stTraTypCf_Ext_stTraTypCf(value)
#define vidGET_VALUE_Ext_stTraTypCf(variable)                                    Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stTypInjSysCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stTypInjSysCf(value)                                    Rte_Write_P_Ext_stTypInjSysCf_Ext_stTypInjSysCf(value)
#define vidGET_VALUE_Ext_stTypInjSysCf(variable)                                 Rte_Read_R_Ext_stTypInjSysCf_Ext_stTypInjSysCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stUcapTypCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stUcapTypCf(value)                                      Rte_Write_P_Ext_stUcapTypCf_Ext_stUcapTypCf(value)
#define vidGET_VALUE_Ext_stUcapTypCf(variable)                                   Rte_Read_R_Ext_stUcapTypCf_Ext_stUcapTypCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stVSCtlRegCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stVSCtlRegCf(value)                                     Rte_Write_P_Ext_stVSCtlRegCf_Ext_stVSCtlRegCf(value)
#define vidGET_VALUE_Ext_stVSCtlRegCf(variable)                                  Rte_Read_R_Ext_stVSCtlRegCf_Ext_stVSCtlRegCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_stVSSCf
  **********************************************************************************/

#define vidSET_VALUE_Ext_stVSSCf(value)                                          Rte_Write_P_Ext_stVSSCf_Ext_stVSSCf(value)
#define vidGET_VALUE_Ext_stVSSCf(variable)                                       Rte_Read_R_Ext_stVSSCf_Ext_stVSSCf(&variable)

/**********************************************************************************
   Create interface for variable Ext_tAir
  **********************************************************************************/

#define vidSET_VALUE_Ext_tAir(value)                                             Rte_Write_P_Ext_tAir_Ext_tAir(value)
#define vidGET_VALUE_Ext_tAir(variable)                                          Rte_Read_R_Ext_tAir_Ext_tAir(&variable)

/**********************************************************************************
   Create interface for variable Ext_tAirExtMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tAirExtMes(value)                                       Rte_Write_P_Ext_tAirExtMes_Ext_tAirExtMes(value)
#define vidGET_VALUE_Ext_tAirExtMes(variable)                                    Rte_Read_R_Ext_tAirExtMes_Ext_tAirExtMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tAirUsCmprMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tAirUsCmprMes(value)                                    Rte_Write_P_Ext_tAirUsCmprMes_Ext_tAirUsCmprMes(value)
#define vidGET_VALUE_Ext_tAirUsCmprMes(variable)                                 Rte_Read_R_Ext_tAirUsCmprMes_Ext_tAirUsCmprMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tBattMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tBattMes(value)                                         Rte_Write_P_Ext_tBattMes_Ext_tBattMes(value)
#define vidGET_VALUE_Ext_tBattMes(variable)                                      Rte_Read_R_Ext_tBattMes_Ext_tBattMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tCoMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tCoMes(value)                                           Rte_Write_P_Ext_tCoMes_Ext_tCoMes(value)
#define vidGET_VALUE_Ext_tCoMes(variable)                                        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tCoMesFineResl2
  **********************************************************************************/

#define vidSET_VALUE_Ext_tCoMesFineResl2(value)                                  Rte_Write_P_Ext_tCoMesFineResl2_Ext_tCoMesFineResl2(value)
#define vidGET_VALUE_Ext_tCoMesFineResl2(variable)                               Rte_Read_R_Ext_tCoMesFineResl2_Ext_tCoMesFineResl2(&variable)

/**********************************************************************************
   Create interface for variable Ext_tCoStrtMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tCoStrtMes(value)                                       Rte_Write_P_Ext_tCoStrtMes_Ext_tCoStrtMes(value)
#define vidGET_VALUE_Ext_tCoStrtMes(variable)                                    Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tDsThrMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tDsThrMes(value)                                        Rte_Write_P_Ext_tDsThrMes_Ext_tDsThrMes(value)
#define vidGET_VALUE_Ext_tDsThrMes(variable)                                     Rte_Read_R_Ext_tDsThrMes_Ext_tDsThrMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tECUMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tECUMes(value)                                          Rte_Write_P_Ext_tECUMes_Ext_tECUMes(value)
#define vidGET_VALUE_Ext_tECUMes(variable)                                       Rte_Read_R_Ext_tECUMes_Ext_tECUMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tFuMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tFuMes(value)                                           Rte_Write_P_Ext_tFuMes_Ext_tFuMes(value)
#define vidGET_VALUE_Ext_tFuMes(variable)                                        Rte_Read_R_Ext_tFuMes_Ext_tFuMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tOilGBx
  **********************************************************************************/

#define vidSET_VALUE_Ext_tOilGBx(value)                                          Rte_Write_P_Ext_tOilGBx_Ext_tOilGBx(value)
#define vidGET_VALUE_Ext_tOilGBx(variable)                                       Rte_Read_R_Ext_tOilGBx_Ext_tOilGBx(&variable)

/**********************************************************************************
   Create interface for variable Ext_tOilMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tOilMes(value)                                          Rte_Write_P_Ext_tOilMes_Ext_tOilMes(value)
#define vidGET_VALUE_Ext_tOilMes(variable)                                       Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tOxCEstim
  **********************************************************************************/

#define vidSET_VALUE_Ext_tOxCEstim(value)                                        Rte_Write_P_Ext_tOxCEstim_Ext_tOxCEstim(value)
#define vidGET_VALUE_Ext_tOxCEstim(variable)                                     Rte_Read_R_Ext_tOxCEstim_Ext_tOxCEstim(&variable)

/**********************************************************************************
   Create interface for variable Ext_tUcapMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tUcapMes(value)                                         Rte_Write_P_Ext_tUcapMes_Ext_tUcapMes(value)
#define vidGET_VALUE_Ext_tUcapMes(variable)                                      Rte_Read_R_Ext_tUcapMes_Ext_tUcapMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tUsThrMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_tUsThrMes(value)                                        Rte_Write_P_Ext_tUsThrMes_Ext_tUsThrMes(value)
#define vidGET_VALUE_Ext_tUsThrMes(variable)                                     Rte_Read_R_Ext_tUsThrMes_Ext_tUsThrMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_tiAst
  **********************************************************************************/

#define vidSET_VALUE_Ext_tiAst(value)                                            Rte_Write_P_Ext_tiAst_Ext_tiAst(value)
#define vidGET_VALUE_Ext_tiAst(variable)                                         Rte_Read_R_Ext_tiAst_Ext_tiAst(&variable)

/**********************************************************************************
   Create interface for variable Ext_tiAstTot
  **********************************************************************************/

#define vidSET_VALUE_Ext_tiAstTot(value)                                         Rte_Write_P_Ext_tiAstTot_Ext_tiAstTot(value)
#define vidGET_VALUE_Ext_tiAstTot(variable)                                      Rte_Read_R_Ext_tiAstTot_Ext_tiAstTot(&variable)

/**********************************************************************************
   Create interface for variable Ext_tiHldPerEng
  **********************************************************************************/

#define vidSET_VALUE_Ext_tiHldPerEng(value)                                      Rte_Write_P_Ext_tiHldPerEng_Ext_tiHldPerEng(value)
#define vidGET_VALUE_Ext_tiHldPerEng(variable)                                   Rte_Read_R_Ext_tiHldPerEng_Ext_tiHldPerEng(&variable)

/**********************************************************************************
   Create interface for variable Ext_tiStrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_tiStrt(value)                                           Rte_Write_P_Ext_tiStrt_Ext_tiStrt(value)
#define vidGET_VALUE_Ext_tiStrt(variable)                                        Rte_Read_R_Ext_tiStrt_Ext_tiStrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_tiTDC
  **********************************************************************************/

#define vidSET_VALUE_Ext_tiTDC(value)                                            Rte_Write_P_Ext_tiTDC_Ext_tiTDC(value)
#define vidGET_VALUE_Ext_tiTDC(variable)                                         Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&variable)

/**********************************************************************************
   Create interface for variable Ext_tqAlt
  **********************************************************************************/

#define vidSET_VALUE_Ext_tqAlt(value)                                            Rte_Write_P_Ext_tqAlt_Ext_tqAlt(value)
#define vidGET_VALUE_Ext_tqAlt(variable)                                         Rte_Read_R_Ext_tqAlt_Ext_tqAlt(&variable)

/**********************************************************************************
   Create interface for variable Ext_uBattClc
  **********************************************************************************/

#define vidSET_VALUE_Ext_uBattClc(value)                                         Rte_Write_P_Ext_uBattClc_Ext_uBattClc(value)
#define vidGET_VALUE_Ext_uBattClc(variable)                                      Rte_Read_R_Ext_uBattClc_Ext_uBattClc(&variable)

/**********************************************************************************
   Create interface for variable Ext_uBattMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_uBattMes(value)                                         Rte_Write_P_Ext_uBattMes_Ext_uBattMes(value)
#define vidGET_VALUE_Ext_uBattMes(variable)                                      Rte_Read_R_Ext_uBattMes_Ext_uBattMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_uBattMinCkg
  **********************************************************************************/

#define vidSET_VALUE_Ext_uBattMinCkg(value)                                      Rte_Write_P_Ext_uBattMinCkg_Ext_uBattMinCkg(value)
#define vidGET_VALUE_Ext_uBattMinCkg(variable)                                   Rte_Read_R_Ext_uBattMinCkg_Ext_uBattMinCkg(&variable)

/**********************************************************************************
   Create interface for variable Ext_uBattOc
  **********************************************************************************/

#define vidSET_VALUE_Ext_uBattOc(value)                                          Rte_Write_P_Ext_uBattOc_Ext_uBattOc(value)
#define vidGET_VALUE_Ext_uBattOc(variable)                                       Rte_Read_R_Ext_uBattOc_Ext_uBattOc(&variable)

/**********************************************************************************
   Create interface for variable Ext_uBattRstrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_uBattRstrt(value)                                       Rte_Write_P_Ext_uBattRstrt_Ext_uBattRstrt(value)
#define vidGET_VALUE_Ext_uBattRstrt(variable)                                    Rte_Read_R_Ext_uBattRstrt_Ext_uBattRstrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_uBattStrt
  **********************************************************************************/

#define vidSET_VALUE_Ext_uBattStrt(value)                                        Rte_Write_P_Ext_uBattStrt_Ext_uBattStrt(value)
#define vidGET_VALUE_Ext_uBattStrt(variable)                                     Rte_Read_R_Ext_uBattStrt_Ext_uBattStrt(&variable)

/**********************************************************************************
   Create interface for variable Ext_uLsDsMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_uLsDsMes(value)                                         Rte_Write_P_Ext_uLsDsMes_Ext_uLsDsMes(value)
#define vidGET_VALUE_Ext_uLsDsMes(variable)                                      Rte_Read_R_Ext_uLsDsMes_Ext_uLsDsMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_uSpgPresSenVolt
  **********************************************************************************/

#define vidSET_VALUE_Ext_uSpgPresSenVolt(value)
#define vidGET_VALUE_Ext_uSpgPresSenVolt(variable)                               Rte_Read_R_Ext_uSpgPresSenVolt_Ext_uSpgPresSenVolt(&variable)

/**********************************************************************************
   Create interface for variable Ext_upFuMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_upFuMes(value)
#define vidGET_VALUE_Ext_upFuMes(variable)                                       Rte_Read_R_Ext_upFuMes_Ext_upFuMes(&variable)

/**********************************************************************************
   Create interface for variable Ext_upOilMes
  **********************************************************************************/

#define vidSET_VALUE_Ext_upOilMes(value)
#define vidGET_VALUE_Ext_upOilMes(variable)                                      Rte_Read_R_Ext_upOilMes_Ext_upOilMes(&variable)

/**********************************************************************************
   Create interface for variable FARSp_bDeacAntiStall
  **********************************************************************************/

#define vidSET_VALUE_FARSp_bDeacAntiStall(value)
#define vidGET_VALUE_FARSp_bDeacAntiStall(variable)                              Rte_Read_R_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(&variable)

/**********************************************************************************
   Create interface for variable FARSp_bEnaAntiStall
  **********************************************************************************/

#define vidSET_VALUE_FARSp_bEnaAntiStall(value)
#define vidGET_VALUE_FARSp_bEnaAntiStall(variable)                               Rte_Read_R_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(&variable)

/**********************************************************************************
   Create interface for variable FARSp_bRichMixtAcv
  **********************************************************************************/

#define vidSET_VALUE_FARSp_bRichMixtAcv(value)
#define vidGET_VALUE_FARSp_bRichMixtAcv(variable)                                Rte_Read_R_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(&variable)

/**********************************************************************************
   Create interface for variable FARSp_bSatMinRatMixt
  **********************************************************************************/

#define vidSET_VALUE_FARSp_bSatMinRatMixt(value)
#define vidGET_VALUE_FARSp_bSatMinRatMixt(variable)                              Rte_Read_R_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(&variable)

/**********************************************************************************
   Create interface for variable FARSp_bStiBlbyNotAcv
  **********************************************************************************/

#define vidSET_VALUE_FARSp_bStiBlbyNotAcv(value)
#define vidGET_VALUE_FARSp_bStiBlbyNotAcv(variable)                              Rte_Read_R_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(&variable)

/**********************************************************************************
   Create interface for array FARSp_prm_bRlamSpAcv
  **********************************************************************************/

#define vidSET_ARRAY_FARSp_prm_bRlamSpAcv(value,size)
#define vidGET_ARRAY_FARSp_prm_bRlamSpAcv(variable,size)                         Rte_Read_R_FARSp_prm_bRlamSpAcv_FARSp_prm_bRlamSpAcv(&variable)

#define vidSET_ARRAY_ELEMENT_FARSp_prm_bRlamSpAcv(variable,pos)
#define vidGET_ARRAY_ELEMENT_FARSp_prm_bRlamSpAcv(variable,pos){ \
  if (pos < 20)\
  { \
     DT_FARSp_prm_bRlamSpAcv datatemp[20];\
     Rte_Read_R_FARSp_prm_bRlamSpAcv_FARSp_prm_bRlamSpAcv(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array FARSp_prm_rMixtCylSp
  **********************************************************************************/

#define vidSET_ARRAY_FARSp_prm_rMixtCylSp(value,size)
#define vidGET_ARRAY_FARSp_prm_rMixtCylSp(variable,size)                         Rte_Read_R_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(&variable)

#define vidSET_ARRAY_ELEMENT_FARSp_prm_rMixtCylSp(variable,pos)
#define vidGET_ARRAY_ELEMENT_FARSp_prm_rMixtCylSp(variable,pos){ \
  if (pos < 6)\
  { \
     DT_FARSp_prm_rMixtCylSp datatemp[6];\
     Rte_Read_R_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable FARSp_rMixtCylSp
  **********************************************************************************/

#define vidSET_VALUE_FARSp_rMixtCylSp(value)
#define vidGET_VALUE_FARSp_rMixtCylSp(variable)                                  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&variable)

/**********************************************************************************
   Create interface for variable FARSp_rMixtCylSpWiStiTWC
  **********************************************************************************/

#define vidSET_VALUE_FARSp_rMixtCylSpWiStiTWC(value)
#define vidGET_VALUE_FARSp_rMixtCylSpWiStiTWC(variable)                          Rte_Read_R_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(&variable)

/**********************************************************************************
   Create interface for variable FARSp_rMixtCylSpWoutStiBlby
  **********************************************************************************/

#define vidSET_VALUE_FARSp_rMixtCylSpWoutStiBlby(value)
#define vidGET_VALUE_FARSp_rMixtCylSpWoutStiBlby(variable)                       Rte_Read_R_FARSp_rMixtCylSpWoutStiBlby_FARSp_rMixtCylSpWoutStiBlby(&variable)

/**********************************************************************************
   Create interface for variable FARSp_rMixtFullLdSpRaw
  **********************************************************************************/

#define vidSET_VALUE_FARSp_rMixtFullLdSpRaw(value)
#define vidGET_VALUE_FARSp_rMixtFullLdSpRaw(variable)                            Rte_Read_R_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(&variable)

/**********************************************************************************
   Create interface for variable FISA_bAFRegWin
  **********************************************************************************/

#define vidSET_VALUE_FISA_bAFRegWin(value)
#define vidGET_VALUE_FISA_bAFRegWin(variable)                                    Rte_Read_R_FISA_bAFRegWin_FISA_bAFRegWin(&variable)

/**********************************************************************************
   Create interface for variable FISA_bAuthSave
  **********************************************************************************/

#define vidSET_VALUE_FISA_bAuthSave(value)
#define vidGET_VALUE_FISA_bAuthSave(variable)                                    Rte_Read_R_FISA_bAuthSave_FISA_bAuthSave(&variable)

/**********************************************************************************
   Create interface for variable FISA_bGrdWin
  **********************************************************************************/

#define vidSET_VALUE_FISA_bGrdWin(value)
#define vidGET_VALUE_FISA_bGrdWin(variable)                                      Rte_Read_R_FISA_bGrdWin_FISA_bGrdWin(&variable)

/**********************************************************************************
   Create interface for variable FISA_bInhFISA
  **********************************************************************************/

#define vidSET_VALUE_FISA_bInhFISA(value)                                        Rte_Write_P_FISA_bInhFISA_FISA_bInhFISA(value)
#define vidGET_VALUE_FISA_bInhFISA(variable)                                     Rte_Read_R_FISA_bInhFISA_FISA_bInhFISA(&variable)

/**********************************************************************************
   Create interface for variable FISA_bInhInst
  **********************************************************************************/

#define vidSET_VALUE_FISA_bInhInst(value)                                        Rte_Write_P_FISA_bInhInst_FISA_bInhInst(value)
#define vidGET_VALUE_FISA_bInhInst(variable)                                     Rte_Read_R_FISA_bInhInst_FISA_bInhInst(&variable)

/**********************************************************************************
   Create interface for variable FISA_bInstWin
  **********************************************************************************/

#define vidSET_VALUE_FISA_bInstWin(value)
#define vidGET_VALUE_FISA_bInstWin(variable)                                     Rte_Read_R_FISA_bInstWin_FISA_bInstWin(&variable)

/**********************************************************************************
   Create interface for variable FISA_bPoor
  **********************************************************************************/

#define vidSET_VALUE_FISA_bPoor(value)                                           Rte_Write_P_FISA_bPoor_FISA_bPoor(value)
#define vidGET_VALUE_FISA_bPoor(variable)                                        Rte_Read_R_FISA_bPoor_FISA_bPoor(&variable)

/**********************************************************************************
   Create interface for variable FISA_bRich
  **********************************************************************************/

#define vidSET_VALUE_FISA_bRich(value)                                           Rte_Write_P_FISA_bRich_FISA_bRich(value)
#define vidGET_VALUE_FISA_bRich(variable)                                        Rte_Read_R_FISA_bRich_FISA_bRich(&variable)

/**********************************************************************************
   Create interface for variable FISA_bRstAdpDone
  **********************************************************************************/

#define vidSET_VALUE_FISA_bRstAdpDone(value)
#define vidGET_VALUE_FISA_bRstAdpDone(variable)                                  Rte_Read_R_FISA_bRstAdpDone_FISA_bRstAdpDone(&variable)

/**********************************************************************************
   Create interface for variable FISA_facAdp
  **********************************************************************************/

#define vidSET_VALUE_FISA_facAdp(value)
#define vidGET_VALUE_FISA_facAdp(variable)                                       Rte_Read_R_FISA_facAdp_FISA_facAdp(&variable)

/**********************************************************************************
   Create interface for variable FISA_facRst
  **********************************************************************************/

#define vidSET_VALUE_FISA_facRst(value)                                          Rte_Write_P_FISA_facRst_FISA_facRst(value)
#define vidGET_VALUE_FISA_facRst(variable)                                       Rte_Read_R_FISA_facRst_FISA_facRst(&variable)

/**********************************************************************************
   Create interface for variable FisrtAcqui_uEngOilLvl
  **********************************************************************************/

#define vidSET_VALUE_FisrtAcqui_uEngOilLvl(value)
#define vidGET_VALUE_FisrtAcqui_uEngOilLvl(variable)                             Rte_Read_R_FisrtAcqui_uEngOilLvl_FisrtAcqui_uEngOilLvl(&variable)

/**********************************************************************************
   Create interface for variable Flev_low_fuel_level
  **********************************************************************************/

#define vidSET_VALUE_Flev_low_fuel_level(value)                                  Rte_Write_P_Flev_low_fuel_level_Flev_low_fuel_level(value)
#define vidGET_VALUE_Flev_low_fuel_level(variable)                               Rte_Read_R_Flev_low_fuel_level_Flev_low_fuel_level(&variable)

/**********************************************************************************
   Create interface for variable Flev_low_gas_level
  **********************************************************************************/

#define vidSET_VALUE_Flev_low_gas_level(value)                                   Rte_Write_P_Flev_low_gas_level_Flev_low_gas_level(value)
#define vidGET_VALUE_Flev_low_gas_level(variable)                                Rte_Read_R_Flev_low_gas_level_Flev_low_gas_level(&variable)

/**********************************************************************************
   Create interface for variable Flex_bInhDiagOBDAlcEst
  **********************************************************************************/

#define vidSET_VALUE_Flex_bInhDiagOBDAlcEst(value)                               Rte_Write_P_Flex_bInhDiagOBDAlcEst_Flex_bInhDiagOBDAlcEst(value)
#define vidGET_VALUE_Flex_bInhDiagOBDAlcEst(variable)                            Rte_Read_R_Flex_bInhDiagOBDAlcEst_Flex_bInhDiagOBDAlcEst(&variable)

/**********************************************************************************
   Create interface for variable Flex_bInhDiagOBDAlcRate
  **********************************************************************************/

#define vidSET_VALUE_Flex_bInhDiagOBDAlcRate(value)                              Rte_Write_P_Flex_bInhDiagOBDAlcRate_Flex_bInhDiagOBDAlcRate(value)
#define vidGET_VALUE_Flex_bInhDiagOBDAlcRate(variable)                           Rte_Read_R_Flex_bInhDiagOBDAlcRate_Flex_bInhDiagOBDAlcRate(&variable)

/**********************************************************************************
   Create interface for variable Flex_bInhDiagOBDBlby
  **********************************************************************************/

#define vidSET_VALUE_Flex_bInhDiagOBDBlby(value)                                 Rte_Write_P_Flex_bInhDiagOBDBlby_Flex_bInhDiagOBDBlby(value)
#define vidGET_VALUE_Flex_bInhDiagOBDBlby(variable)                              Rte_Read_R_Flex_bInhDiagOBDBlby_Flex_bInhDiagOBDBlby(&variable)

/**********************************************************************************
   Create interface for variable FlowMng_bCluPropSnsrEna
  **********************************************************************************/

#define vidSET_VALUE_FlowMng_bCluPropSnsrEna(value)                              Rte_Write_P_FlowMng_bCluPropSnsrEna_FlowMng_bCluPropSnsrEna(value)
#define vidGET_VALUE_FlowMng_bCluPropSnsrEna(variable)                           Rte_Read_R_FlowMng_bCluPropSnsrEna_FlowMng_bCluPropSnsrEna(&variable)

/**********************************************************************************
   Create interface for variable FlowMng_bCluSwtEna
  **********************************************************************************/

#define vidSET_VALUE_FlowMng_bCluSwtEna(value)                                   Rte_Write_P_FlowMng_bCluSwtEna_FlowMng_bCluSwtEna(value)
#define vidGET_VALUE_FlowMng_bCluSwtEna(variable)                                Rte_Read_R_FlowMng_bCluSwtEna_FlowMng_bCluSwtEna(&variable)

/**********************************************************************************
   Create interface for variable FuSysM_tFu
  **********************************************************************************/

#define vidSET_VALUE_FuSysM_tFu(value)                                           Rte_Write_P_FuSysM_tFu_FuSysM_tFu(value)
#define vidGET_VALUE_FuSysM_tFu(variable)                                        Rte_Read_R_FuSysM_tFu_FuSysM_tFu(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORngLf_Afl_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORngLf_Afl_swc(value)                         Rte_Write_P_GDU_bEndDiagStORngLf_Afl_swc_GDU_bEndDiagStORngLf_Afl_swc(value)
#define vidGET_VALUE_GDU_bEndDiagStORngLf_Afl_swc(variable)                      Rte_Read_R_GDU_bEndDiagStORngLf_Afl_swc_GDU_bEndDiagStORngLf_Afl_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORngLf_Afr_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORngLf_Afr_swc(value)                         Rte_Write_P_GDU_bEndDiagStORngLf_Afr_swc_GDU_bEndDiagStORngLf_Afr_swc(value)
#define vidGET_VALUE_GDU_bEndDiagStORngLf_Afr_swc(variable)                      Rte_Read_R_GDU_bEndDiagStORngLf_Afr_swc_GDU_bEndDiagStORngLf_Afr_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORng_DsHt_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORng_DsHt_swc(value)                          Rte_Write_P_GDU_bEndDiagStORng_DsHt_swc_GDU_bEndDiagStORng_DsHt_swc(value)
#define vidGET_VALUE_GDU_bEndDiagStORng_DsHt_swc(variable)                       Rte_Read_R_GDU_bEndDiagStORng_DsHt_swc_GDU_bEndDiagStORng_DsHt_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORng_DsPlausFco
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORng_DsPlausFco(value)                        Rte_Write_P_GDU_bEndDiagStORng_DsPlausFco_GDU_bEndDiagStORng_DsPlausFco(value)
#define vidGET_VALUE_GDU_bEndDiagStORng_DsPlausFco(variable)                     Rte_Read_R_GDU_bEndDiagStORng_DsPlausFco_GDU_bEndDiagStORng_DsPlausFco(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORng_OxyApvPerd
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORng_OxyApvPerd(value)                        Rte_Write_P_GDU_bEndDiagStORng_OxyApvPerd_GDU_bEndDiagStORng_OxyApvPerd(value)
#define vidGET_VALUE_GDU_bEndDiagStORng_OxyApvPerd(variable)                     Rte_Read_R_GDU_bEndDiagStORng_OxyApvPerd_GDU_bEndDiagStORng_OxyApvPerd(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORng_OxySensPrd
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORng_OxySensPrd(value)                        Rte_Write_P_GDU_bEndDiagStORng_OxySensPrd_GDU_bEndDiagStORng_OxySensPrd(value)
#define vidGET_VALUE_GDU_bEndDiagStORng_OxySensPrd(variable)                     Rte_Read_R_GDU_bEndDiagStORng_OxySensPrd_GDU_bEndDiagStORng_OxySensPrd(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORng_UsHt_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORng_UsHt_swc(value)                          Rte_Write_P_GDU_bEndDiagStORng_UsHt_swc_GDU_bEndDiagStORng_UsHt_swc(value)
#define vidGET_VALUE_GDU_bEndDiagStORng_UsHt_swc(variable)                       Rte_Read_R_GDU_bEndDiagStORng_UsHt_swc_GDU_bEndDiagStORng_UsHt_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_bEndDiagStORng_UsPlausFco
  **********************************************************************************/

#define vidSET_VALUE_GDU_bEndDiagStORng_UsPlausFco(value)                        Rte_Write_P_GDU_bEndDiagStORng_UsPlausFco_GDU_bEndDiagStORng_UsPlausFco(value)
#define vidGET_VALUE_GDU_bEndDiagStORng_UsPlausFco(variable)                     Rte_Read_R_GDU_bEndDiagStORng_UsPlausFco_GDU_bEndDiagStORng_UsPlausFco(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORngLf_Afl_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORngLf_Afl_swc(value)                              Rte_Write_P_GDU_stDgoORngLf_Afl_swc_GDU_stDgoORngLf_Afl_swc(value)
#define vidGET_VALUE_GDU_stDgoORngLf_Afl_swc(variable)                           Rte_Read_R_GDU_stDgoORngLf_Afl_swc_GDU_stDgoORngLf_Afl_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORngLf_Afr_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORngLf_Afr_swc(value)                              Rte_Write_P_GDU_stDgoORngLf_Afr_swc_GDU_stDgoORngLf_Afr_swc(value)
#define vidGET_VALUE_GDU_stDgoORngLf_Afr_swc(variable)                           Rte_Read_R_GDU_stDgoORngLf_Afr_swc_GDU_stDgoORngLf_Afr_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORng_DsHt_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORng_DsHt_swc(value)                               Rte_Write_P_GDU_stDgoORng_DsHt_swc_GDU_stDgoORng_DsHt_swc(value)
#define vidGET_VALUE_GDU_stDgoORng_DsHt_swc(variable)                            Rte_Read_R_GDU_stDgoORng_DsHt_swc_GDU_stDgoORng_DsHt_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORng_DsPlsFco_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORng_DsPlsFco_swc(value)                           Rte_Write_P_GDU_stDgoORng_DsPlsFco_swc_GDU_stDgoORng_DsPlsFco_swc(value)
#define vidGET_VALUE_GDU_stDgoORng_DsPlsFco_swc(variable)                        Rte_Read_R_GDU_stDgoORng_DsPlsFco_swc_GDU_stDgoORng_DsPlsFco_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORng_OxyApvPrd_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORng_OxyApvPrd_swc(value)                          Rte_Write_P_GDU_stDgoORng_OxyApvPrd_swc_GDU_stDgoORng_OxyApvPrd_swc(value)
#define vidGET_VALUE_GDU_stDgoORng_OxyApvPrd_swc(variable)                       Rte_Read_R_GDU_stDgoORng_OxyApvPrd_swc_GDU_stDgoORng_OxyApvPrd_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORng_OxySenPrd_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORng_OxySenPrd_swc(value)                          Rte_Write_P_GDU_stDgoORng_OxySenPrd_swc_GDU_stDgoORng_OxySenPrd_swc(value)
#define vidGET_VALUE_GDU_stDgoORng_OxySenPrd_swc(variable)                       Rte_Read_R_GDU_stDgoORng_OxySenPrd_swc_GDU_stDgoORng_OxySenPrd_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORng_UsHt_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORng_UsHt_swc(value)                               Rte_Write_P_GDU_stDgoORng_UsHt_swc_GDU_stDgoORng_UsHt_swc(value)
#define vidGET_VALUE_GDU_stDgoORng_UsHt_swc(variable)                            Rte_Read_R_GDU_stDgoORng_UsHt_swc_GDU_stDgoORng_UsHt_swc(&variable)

/**********************************************************************************
   Create interface for variable GDU_stDgoORng_UsPlsFco_swc
  **********************************************************************************/

#define vidSET_VALUE_GDU_stDgoORng_UsPlsFco_swc(value)                           Rte_Write_P_GDU_stDgoORng_UsPlsFco_swc_GDU_stDgoORng_UsPlsFco_swc(value)
#define vidGET_VALUE_GDU_stDgoORng_UsPlsFco_swc(variable)                        Rte_Read_R_GDU_stDgoORng_UsPlsFco_swc_GDU_stDgoORng_UsPlsFco_swc(&variable)

/**********************************************************************************
   Create interface for variable GSI3_noEgdGearCordFilIt
  **********************************************************************************/

#define vidSET_VALUE_GSI3_noEgdGearCordFilIt(value)
#define vidGET_VALUE_GSI3_noEgdGearCordFilIt(variable)                           Rte_Read_R_GSI3_noEgdGearCordFilIt_GSI3_noEgdGearCordFilIt(&variable)

/**********************************************************************************
   Create interface for variable GSI3_noTarGear
  **********************************************************************************/

#define vidSET_VALUE_GSI3_noTarGear(value)
#define vidGET_VALUE_GSI3_noTarGear(variable)                                    Rte_Read_R_GSI3_noTarGear_GSI3_noTarGear(&variable)

/**********************************************************************************
   Create interface for variable GSI3_stGSIEna
  **********************************************************************************/

#define vidSET_VALUE_GSI3_stGSIEna(value)
#define vidGET_VALUE_GSI3_stGSIEna(variable)                                     Rte_Read_R_GSI3_stGSIEna_GSI3_stGSIEna(&variable)

/**********************************************************************************
   Create interface for variable GSI3_stGearShiftReq
  **********************************************************************************/

#define vidSET_VALUE_GSI3_stGearShiftReq(value)
#define vidGET_VALUE_GSI3_stGearShiftReq(variable)                               Rte_Read_R_GSI3_stGearShiftReq_GSI3_stGearShiftReq(&variable)

/**********************************************************************************
   Create interface for variable GSM_bAcvAFAAdp
  **********************************************************************************/

#define vidSET_VALUE_GSM_bAcvAFAAdp(value)                                       Rte_Write_P_GSM_bAcvAFAAdp_GSM_bAcvAFAAdp(value)
#define vidGET_VALUE_GSM_bAcvAFAAdp(variable)                                    Rte_Read_R_GSM_bAcvAFAAdp_GSM_bAcvAFAAdp(&variable)

/**********************************************************************************
   Create interface for variable Gear_bAcvNeutPosnAcq
  **********************************************************************************/

#define vidSET_VALUE_Gear_bAcvNeutPosnAcq(value)                                 Rte_Write_P_Gear_bAcvNeutPosnAcq_Gear_bAcvNeutPosnAcq(value)
#define vidGET_VALUE_Gear_bAcvNeutPosnAcq(variable)                              Rte_Read_R_Gear_bAcvNeutPosnAcq_Gear_bAcvNeutPosnAcq(&variable)

/**********************************************************************************
   Create interface for variable Gear_engaged
  **********************************************************************************/

#define vidSET_VALUE_Gear_engaged(value)                                         Rte_Write_P_Gear_engaged_Gear_engaged(value)
#define vidGET_VALUE_Gear_engaged(variable)                                      Rte_Read_R_Gear_engaged_Gear_engaged(&variable)

/**********************************************************************************
   Create interface for variable IMMO_stEcuLockStTyp
  **********************************************************************************/

#define vidSET_VALUE_IMMO_stEcuLockStTyp(value)                                  Rte_Write_P_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp(value)
#define vidGET_VALUE_IMMO_stEcuLockStTyp(variable)                               Rte_Read_R_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp(&variable)

/**********************************************************************************
   Create interface for variable Icd_ratio_energy
  **********************************************************************************/

#define vidSET_VALUE_Icd_ratio_energy(value)
#define vidGET_VALUE_Icd_ratio_energy(variable)                                  Rte_Read_R_Icd_ratio_energy_Icd_ratio_energy(&variable)

/**********************************************************************************
   Create interface for variable Icd_state
  **********************************************************************************/

#define vidSET_VALUE_Icd_state(value)
#define vidGET_VALUE_Icd_state(variable)                                         Rte_Read_R_Icd_state_Icd_state(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_bAcvAntiStall
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_bAcvAntiStall(value)                                 Rte_Write_P_IdlSys_bAcvAntiStall_IdlSys_bAcvAntiStall(value)
#define vidGET_VALUE_IdlSys_bAcvAntiStall(variable)                              Rte_Read_R_IdlSys_bAcvAntiStall_IdlSys_bAcvAntiStall(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_bAcvCll
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_bAcvCll(value)                                       Rte_Write_P_IdlSys_bAcvCll_IdlSys_bAcvCll(value)
#define vidGET_VALUE_IdlSys_bAcvCll(variable)                                    Rte_Read_R_IdlSys_bAcvCll_IdlSys_bAcvCll(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_bAcvIdlCtl
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_bAcvIdlCtl(value)                                    Rte_Write_P_IdlSys_bAcvIdlCtl_IdlSys_bAcvIdlCtl(value)
#define vidGET_VALUE_IdlSys_bAcvIdlCtl(variable)                                 Rte_Read_R_IdlSys_bAcvIdlCtl_IdlSys_bAcvIdlCtl(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_bAcvIgMinSpc
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_bAcvIgMinSpc(value)                                  Rte_Write_P_IdlSys_bAcvIgMinSpc_IdlSys_bAcvIgMinSpc(value)
#define vidGET_VALUE_IdlSys_bAcvIgMinSpc(variable)                               Rte_Read_R_IdlSys_bAcvIgMinSpc_IdlSys_bAcvIgMinSpc(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_bEnaAntiStall
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_bEnaAntiStall(value)                                 Rte_Write_P_IdlSys_bEnaAntiStall_IdlSys_bEnaAntiStall(value)
#define vidGET_VALUE_IdlSys_bEnaAntiStall(variable)                              Rte_Read_R_IdlSys_bEnaAntiStall_IdlSys_bEnaAntiStall(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_tiTranCll
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_tiTranCll(value)                                     Rte_Write_P_IdlSys_tiTranCll_IdlSys_tiTranCll(value)
#define vidGET_VALUE_IdlSys_tiTranCll(variable)                                  Rte_Read_R_IdlSys_tiTranCll_IdlSys_tiTranCll(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_tqIdcAirIdl
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_tqIdcAirIdl(value)                                   Rte_Write_P_IdlSys_tqIdcAirIdl_IdlSys_tqIdcAirIdl(value)
#define vidGET_VALUE_IdlSys_tqIdcAirIdl(variable)                                Rte_Read_R_IdlSys_tqIdcAirIdl_IdlSys_tqIdcAirIdl(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_tqIdcIdl
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_tqIdcIdl(value)                                      Rte_Write_P_IdlSys_tqIdcIdl_IdlSys_tqIdcIdl(value)
#define vidGET_VALUE_IdlSys_tqIdcIdl(variable)                                   Rte_Read_R_IdlSys_tqIdcIdl_IdlSys_tqIdcIdl(&variable)

/**********************************************************************************
   Create interface for variable IdlSys_tqIncCll
  **********************************************************************************/

#define vidSET_VALUE_IdlSys_tqIncCll(value)                                      Rte_Write_P_IdlSys_tqIncCll_IdlSys_tqIncCll(value)
#define vidGET_VALUE_IdlSys_tqIncCll(variable)                                   Rte_Read_R_IdlSys_tqIncCll_IdlSys_tqIncCll(&variable)

/**********************************************************************************
   Create interface for variable IgCmd_agIgSp
  **********************************************************************************/

#define vidSET_VALUE_IgCmd_agIgSp(value)                                         Rte_Write_P_IgCmd_agIgSp_IgCmd_agIgSp(value)
#define vidGET_VALUE_IgCmd_agIgSp(variable)                                      Rte_Read_R_IgCmd_agIgSp_IgCmd_agIgSp(&variable)

/**********************************************************************************
   Create interface for variable IgCmd_agIgSpNxt
  **********************************************************************************/

#define vidSET_VALUE_IgCmd_agIgSpNxt(value)                                      Rte_Write_P_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt(value)
#define vidGET_VALUE_IgCmd_agIgSpNxt(variable)                                   Rte_Read_R_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt(&variable)

/**********************************************************************************
   Create interface for variable IgCmd_bPwrRlyCmd
  **********************************************************************************/

#define vidSET_VALUE_IgCmd_bPwrRlyCmd(value)                                     Rte_Write_P_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd(value)
#define vidGET_VALUE_IgCmd_bPwrRlyCmd(variable)                                  Rte_Read_R_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgCmbModOfs
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgCmbModOfs(value)                                  Rte_Write_P_IgSys_agIgCmbModOfs_IgSys_agIgCmbModOfs(value)
#define vidGET_VALUE_IgSys_agIgCmbModOfs(variable)                               Rte_Read_R_IgSys_agIgCmbModOfs_IgSys_agIgCmbModOfs(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgCmbModOfsMax
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgCmbModOfsMax(value)                               Rte_Write_P_IgSys_agIgCmbModOfsMax_IgSys_agIgCmbModOfsMax(value)
#define vidGET_VALUE_IgSys_agIgCmbModOfsMax(variable)                            Rte_Read_R_IgSys_agIgCmbModOfsMax_IgSys_agIgCmbModOfsMax(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgCmbModOfsMinCmb
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgCmbModOfsMinCmb(value)                            Rte_Write_P_IgSys_agIgCmbModOfsMinCmb_IgSys_agIgCmbModOfsMinCmb(value)
#define vidGET_VALUE_IgSys_agIgCmbModOfsMinCmb(variable)                         Rte_Read_R_IgSys_agIgCmbModOfsMinCmb_IgSys_agIgCmbModOfsMinCmb(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgDynIgSpEfc
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgDynIgSpEfc(value)
#define vidGET_VALUE_IgSys_agIgDynIgSpEfc(variable)                              Rte_Read_R_IgSys_agIgDynIgSpEfc_IgSys_agIgDynIgSpEfc(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgKnkPrevOfs
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgKnkPrevOfs(value)
#define vidGET_VALUE_IgSys_agIgKnkPrevOfs(variable)                              Rte_Read_R_IgSys_agIgKnkPrevOfs_IgSys_agIgKnkPrevOfs(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgLimKnkMax
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgLimKnkMax(value)
#define vidGET_VALUE_IgSys_agIgLimKnkMax(variable)                               Rte_Read_R_IgSys_agIgLimKnkMax_IgSys_agIgLimKnkMax(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgLimKnkMv
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgLimKnkMv(value)
#define vidGET_VALUE_IgSys_agIgLimKnkMv(variable)                                Rte_Read_R_IgSys_agIgLimKnkMv_IgSys_agIgLimKnkMv(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgLimMinKnk
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgLimMinKnk(value)
#define vidGET_VALUE_IgSys_agIgLimMinKnk(variable)                               Rte_Read_R_IgSys_agIgLimMinKnk_IgSys_agIgLimMinKnk(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgLimMinRef
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgLimMinRef(value)
#define vidGET_VALUE_IgSys_agIgLimMinRef(variable)                               Rte_Read_R_IgSys_agIgLimMinRef_IgSys_agIgLimMinRef(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgMax
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgMax(value)
#define vidGET_VALUE_IgSys_agIgMax(variable)                                     Rte_Read_R_IgSys_agIgMax_IgSys_agIgMax(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgMaxWiPrevAdpMv
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgMaxWiPrevAdpMv(value)
#define vidGET_VALUE_IgSys_agIgMaxWiPrevAdpMv(variable)                          Rte_Read_R_IgSys_agIgMaxWiPrevAdpMv_IgSys_agIgMaxWiPrevAdpMv(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgMaxWiPrevMv
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgMaxWiPrevMv(value)
#define vidGET_VALUE_IgSys_agIgMaxWiPrevMv(variable)                             Rte_Read_R_IgSys_agIgMaxWiPrevMv_IgSys_agIgMaxWiPrevMv(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgOptm
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgOptm(value)
#define vidGET_VALUE_IgSys_agIgOptm(variable)                                    Rte_Read_R_IgSys_agIgOptm_IgSys_agIgOptm(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgSp
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgSp(value)
#define vidGET_VALUE_IgSys_agIgSp(variable)                                      Rte_Read_R_IgSys_agIgSp_IgSys_agIgSp(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgSpNxt
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgSpNxt(value)
#define vidGET_VALUE_IgSys_agIgSpNxt(variable)                                   Rte_Read_R_IgSys_agIgSpNxt_IgSys_agIgSpNxt(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgStrtSp
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgStrtSp(value)                                     Rte_Write_P_IgSys_agIgStrtSp_IgSys_agIgStrtSp(value)
#define vidGET_VALUE_IgSys_agIgStrtSp(variable)                                  Rte_Read_R_IgSys_agIgStrtSp_IgSys_agIgStrtSp(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgStrtSpNxt
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgStrtSpNxt(value)                                  Rte_Write_P_IgSys_agIgStrtSpNxt_IgSys_agIgStrtSpNxt(value)
#define vidGET_VALUE_IgSys_agIgStrtSpNxt(variable)                               Rte_Read_R_IgSys_agIgStrtSpNxt_IgSys_agIgStrtSpNxt(&variable)

/**********************************************************************************
   Create interface for variable IgSys_agIgTarWoutAntiJerk
  **********************************************************************************/

#define vidSET_VALUE_IgSys_agIgTarWoutAntiJerk(value)
#define vidGET_VALUE_IgSys_agIgTarWoutAntiJerk(variable)                         Rte_Read_R_IgSys_agIgTarWoutAntiJerk_IgSys_agIgTarWoutAntiJerk(&variable)

/**********************************************************************************
   Create interface for variable IgSys_bAcvLoTCoRegKnk
  **********************************************************************************/

#define vidSET_VALUE_IgSys_bAcvLoTCoRegKnk(value)                                Rte_Write_P_IgSys_bAcvLoTCoRegKnk_IgSys_bAcvLoTCoRegKnk(value)
#define vidGET_VALUE_IgSys_bAcvLoTCoRegKnk(variable)                             Rte_Read_R_IgSys_bAcvLoTCoRegKnk_IgSys_bAcvLoTCoRegKnk(&variable)

/**********************************************************************************
   Create interface for variable IgSys_bAcvStructAdv
  **********************************************************************************/

#define vidSET_VALUE_IgSys_bAcvStructAdv(value)                                  Rte_Write_P_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv(value)
#define vidGET_VALUE_IgSys_bAcvStructAdv(variable)                               Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv(&variable)

/**********************************************************************************
   Create interface for variable IgSys_bAcvStructAir
  **********************************************************************************/

#define vidSET_VALUE_IgSys_bAcvStructAir(value)                                  Rte_Write_P_IgSys_bAcvStructAir_IgSys_bAcvStructAir(value)
#define vidGET_VALUE_IgSys_bAcvStructAir(variable)                               Rte_Read_R_IgSys_bAcvStructAir_IgSys_bAcvStructAir(&variable)

/**********************************************************************************
   Create interface for variable IgSys_bIgBenchModEna
  **********************************************************************************/

#define vidSET_VALUE_IgSys_bIgBenchModEna(value)                                 Rte_Write_P_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna(value)
#define vidGET_VALUE_IgSys_bIgBenchModEna(variable)                              Rte_Read_R_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna(&variable)

/**********************************************************************************
   Create interface for variable IgSys_facTarAgCor
  **********************************************************************************/

#define vidSET_VALUE_IgSys_facTarAgCor(value)                                    Rte_Write_P_IgSys_facTarAgCor_IgSys_facTarAgCor(value)
#define vidGET_VALUE_IgSys_facTarAgCor(variable)                                 Rte_Read_R_IgSys_facTarAgCor_IgSys_facTarAgCor(&variable)

/**********************************************************************************
   Create interface for variable IgSys_iESpBenchMod
  **********************************************************************************/

#define vidSET_VALUE_IgSys_iESpBenchMod(value)                                   Rte_Write_P_IgSys_iESpBenchMod_IgSys_iESpBenchMod(value)
#define vidGET_VALUE_IgSys_iESpBenchMod(variable)                                Rte_Read_R_IgSys_iESpBenchMod_IgSys_iESpBenchMod(&variable)

/**********************************************************************************
   Create interface for variable IgSys_noCylCutOffTar
  **********************************************************************************/

#define vidSET_VALUE_IgSys_noCylCutOffTar(value)
#define vidGET_VALUE_IgSys_noCylCutOffTar(variable)                              Rte_Read_R_IgSys_noCylCutOffTar_IgSys_noCylCutOffTar(&variable)

/**********************************************************************************
   Create interface for array IgSys_prm_agIgLimKnk
  **********************************************************************************/

#define vidSET_ARRAY_IgSys_prm_agIgLimKnk(value,size)
#define vidGET_ARRAY_IgSys_prm_agIgLimKnk(variable,size)                         Rte_Read_R_IgSys_prm_agIgLimKnk_IgSys_prm_agIgLimKnk(&variable)

#define vidSET_ARRAY_ELEMENT_IgSys_prm_agIgLimKnk(variable,pos)
#define vidGET_ARRAY_ELEMENT_IgSys_prm_agIgLimKnk(variable,pos){ \
  if (pos < 6)\
  { \
     DT_IgSys_prm_agIgLimKnk datatemp[6];\
     Rte_Read_R_IgSys_prm_agIgLimKnk_IgSys_prm_agIgLimKnk(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array IgSys_prm_agIgMaxWiPrevAdpCyl
  **********************************************************************************/

#define vidSET_ARRAY_IgSys_prm_agIgMaxWiPrevAdpCyl(value,size)
#define vidGET_ARRAY_IgSys_prm_agIgMaxWiPrevAdpCyl(variable,size)                Rte_Read_R_IgSys_prm_agIgMaxWiPrevAdpCyl_IgSys_prm_agIgMaxWiPrevAdpCyl(&variable)

#define vidSET_ARRAY_ELEMENT_IgSys_prm_agIgMaxWiPrevAdpCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_IgSys_prm_agIgMaxWiPrevAdpCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_IgSys_prm_agIgMaxWiPrevAdpCyl datatemp[6];\
     Rte_Read_R_IgSys_prm_agIgMaxWiPrevAdpCyl_IgSys_prm_agIgMaxWiPrevAdpCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array IgSys_prm_facFlex
  **********************************************************************************/

#define vidSET_ARRAY_IgSys_prm_facFlex(value,size)
#define vidGET_ARRAY_IgSys_prm_facFlex(variable,size)                            Rte_Read_R_IgSys_prm_facFlex_IgSys_prm_facFlex(&variable)

#define vidSET_ARRAY_ELEMENT_IgSys_prm_facFlex(variable,pos)
#define vidGET_ARRAY_ELEMENT_IgSys_prm_facFlex(variable,pos){ \
  if (pos < 10)\
  { \
     DT_IgSys_prm_facFlex datatemp[10];\
     Rte_Read_R_IgSys_prm_facFlex_IgSys_prm_facFlex(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array IgSys_prm_facGas
  **********************************************************************************/

#define vidSET_ARRAY_IgSys_prm_facGas(value,size)                                Rte_Write_P_IgSys_prm_facGas_IgSys_prm_facGas(&value)
#define vidGET_ARRAY_IgSys_prm_facGas(variable,size)                             Rte_Read_R_IgSys_prm_facGas_IgSys_prm_facGas(&variable)

#define vidSET_ARRAY_ELEMENT_IgSys_prm_facGas(variable,pos) \
{ \
  if (pos < 10)\
  {\
    DT_IgSys_prm_facGas datatemp[10];\
    Rte_Read_R_IgSys_prm_facGas_IgSys_prm_facGas(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_IgSys_prm_facGas_IgSys_prm_facGas(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_IgSys_prm_facGas(variable,pos) \
{ \
  if (pos < 10)\
  { \
     DT_IgSys_prm_facGas datatemp[10];\
     Rte_Read_R_IgSys_prm_facGas_IgSys_prm_facGas(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable IgSys_rDynIgSpEfc
  **********************************************************************************/

#define vidSET_VALUE_IgSys_rDynIgSpEfc(value)
#define vidGET_VALUE_IgSys_rDynIgSpEfc(variable)                                 Rte_Read_R_IgSys_rDynIgSpEfc_IgSys_rDynIgSpEfc(&variable)

/**********************************************************************************
   Create interface for variable IgSys_rMaxIgEfc
  **********************************************************************************/

#define vidSET_VALUE_IgSys_rMaxIgEfc(value)
#define vidGET_VALUE_IgSys_rMaxIgEfc(variable)                                   Rte_Read_R_IgSys_rMaxIgEfc_IgSys_rMaxIgEfc(&variable)

/**********************************************************************************
   Create interface for variable IgSys_rMinIgEfc
  **********************************************************************************/

#define vidSET_VALUE_IgSys_rMinIgEfc(value)
#define vidGET_VALUE_IgSys_rMinIgEfc(variable)                                   Rte_Read_R_IgSys_rMinIgEfc_IgSys_rMinIgEfc(&variable)

/**********************************************************************************
   Create interface for variable IgSys_rStatIgSpEfc
  **********************************************************************************/

#define vidSET_VALUE_IgSys_rStatIgSpEfc(value)
#define vidGET_VALUE_IgSys_rStatIgSpEfc(variable)                                Rte_Read_R_IgSys_rStatIgSpEfc_IgSys_rStatIgSpEfc(&variable)

/**********************************************************************************
   Create interface for variable IgSys_rlamClc
  **********************************************************************************/

#define vidSET_VALUE_IgSys_rlamClc(value)
#define vidGET_VALUE_IgSys_rlamClc(variable)                                     Rte_Read_R_IgSys_rlamClc_IgSys_rlamClc(&variable)

/**********************************************************************************
   Create interface for variable IgSys_tDifTAirUsInVlvEstim
  **********************************************************************************/

#define vidSET_VALUE_IgSys_tDifTAirUsInVlvEstim(value)
#define vidGET_VALUE_IgSys_tDifTAirUsInVlvEstim(variable)                        Rte_Read_R_IgSys_tDifTAirUsInVlvEstim_IgSys_tDifTAirUsInVlvEstim(&variable)

/**********************************************************************************
   Create interface for variable IgSys_tiDwellSpBenchMod
  **********************************************************************************/

#define vidSET_VALUE_IgSys_tiDwellSpBenchMod(value)                              Rte_Write_P_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod(value)
#define vidGET_VALUE_IgSys_tiDwellSpBenchMod(variable)                           Rte_Read_R_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod(&variable)

/**********************************************************************************
   Create interface for variable InM_arEffAdpThr
  **********************************************************************************/

#define vidSET_VALUE_InM_arEffAdpThr(value)
#define vidGET_VALUE_InM_arEffAdpThr(variable)                                   Rte_Read_R_InM_arEffAdpThr_InM_arEffAdpThr(&variable)

/**********************************************************************************
   Create interface for variable InM_bAcceEng
  **********************************************************************************/

#define vidSET_VALUE_InM_bAcceEng(value)
#define vidGET_VALUE_InM_bAcceEng(variable)                                      Rte_Read_R_InM_bAcceEng_InM_bAcceEng(&variable)

/**********************************************************************************
   Create interface for variable InM_concAirPredCor
  **********************************************************************************/

#define vidSET_VALUE_InM_concAirPredCor(value)
#define vidGET_VALUE_InM_concAirPredCor(variable)                                Rte_Read_R_InM_concAirPredCor_InM_concAirPredCor(&variable)

/**********************************************************************************
   Create interface for variable InM_concAirPredInCylCor
  **********************************************************************************/

#define vidSET_VALUE_InM_concAirPredInCylCor(value)
#define vidGET_VALUE_InM_concAirPredInCylCor(variable)                           Rte_Read_R_InM_concAirPredInCylCor_InM_concAirPredInCylCor(&variable)

/**********************************************************************************
   Create interface for variable InM_concFuCor
  **********************************************************************************/

#define vidSET_VALUE_InM_concFuCor(value)
#define vidGET_VALUE_InM_concFuCor(variable)                                     Rte_Read_R_InM_concFuCor_InM_concFuCor(&variable)

/**********************************************************************************
   Create interface for variable InM_concFuPredCor
  **********************************************************************************/

#define vidSET_VALUE_InM_concFuPredCor(value)
#define vidGET_VALUE_InM_concFuPredCor(variable)                                 Rte_Read_R_InM_concFuPredCor_InM_concFuPredCor(&variable)

/**********************************************************************************
   Create interface for variable InM_concFuPredInCylCor
  **********************************************************************************/

#define vidSET_VALUE_InM_concFuPredInCylCor(value)
#define vidGET_VALUE_InM_concFuPredInCylCor(variable)                            Rte_Read_R_InM_concFuPredInCylCor_InM_concFuPredInCylCor(&variable)

/**********************************************************************************
   Create interface for variable InM_facCfeCanPurgCor
  **********************************************************************************/

#define vidSET_VALUE_InM_facCfeCanPurgCor(value)
#define vidGET_VALUE_InM_facCfeCanPurgCor(variable)                              Rte_Read_R_InM_facCfeCanPurgCor_InM_facCfeCanPurgCor(&variable)

/**********************************************************************************
   Create interface for variable InM_facCfeGradThr
  **********************************************************************************/

#define vidSET_VALUE_InM_facCfeGradThr(value)
#define vidGET_VALUE_InM_facCfeGradThr(variable)                                 Rte_Read_R_InM_facCfeGradThr_InM_facCfeGradThr(&variable)

/**********************************************************************************
   Create interface for variable InM_facCoplMassPres
  **********************************************************************************/

#define vidSET_VALUE_InM_facCoplMassPres(value)
#define vidGET_VALUE_InM_facCoplMassPres(variable)                               Rte_Read_R_InM_facCoplMassPres_InM_facCoplMassPres(&variable)

/**********************************************************************************
   Create interface for variable InM_facRelaxCplMassPresEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_facRelaxCplMassPresEstim(value)
#define vidGET_VALUE_InM_facRelaxCplMassPresEstim(variable)                      Rte_Read_R_InM_facRelaxCplMassPresEstim_InM_facRelaxCplMassPresEstim(&variable)

/**********************************************************************************
   Create interface for variable InM_mAirEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_mAirEstim(value)
#define vidGET_VALUE_InM_mAirEstim(variable)                                     Rte_Read_R_InM_mAirEstim_InM_mAirEstim(&variable)

/**********************************************************************************
   Create interface for variable InM_mEGREstimLoResl
  **********************************************************************************/

#define vidSET_VALUE_InM_mEGREstimLoResl(value)
#define vidGET_VALUE_InM_mEGREstimLoResl(variable)                               Rte_Read_R_InM_mEGREstimLoResl_InM_mEGREstimLoResl(&variable)

/**********************************************************************************
   Create interface for variable InM_mfAirDifIn
  **********************************************************************************/

#define vidSET_VALUE_InM_mfAirDifIn(value)
#define vidGET_VALUE_InM_mfAirDifIn(variable)                                    Rte_Read_R_InM_mfAirDifIn_InM_mfAirDifIn(&variable)

/**********************************************************************************
   Create interface for variable InM_mfAirEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_mfAirEstim(value)
#define vidGET_VALUE_InM_mfAirEstim(variable)                                    Rte_Read_R_InM_mfAirEstim_InM_mfAirEstim(&variable)

/**********************************************************************************
   Create interface for variable InM_mfAirThrEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_mfAirThrEstim(value)
#define vidGET_VALUE_InM_mfAirThrEstim(variable)                                 Rte_Read_R_InM_mfAirThrEstim_InM_mfAirThrEstim(&variable)

/**********************************************************************************
   Create interface for variable InM_mfEGRReq_arEGR
  **********************************************************************************/

#define vidSET_VALUE_InM_mfEGRReq_arEGR(value)
#define vidGET_VALUE_InM_mfEGRReq_arEGR(variable)                                Rte_Read_R_InM_mfEGRReq_arEGR_InM_mfEGRReq_arEGR(&variable)

/**********************************************************************************
   Create interface for variable InM_mfTotCanPurgEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_mfTotCanPurgEstim(value)
#define vidGET_VALUE_InM_mfTotCanPurgEstim(variable)                             Rte_Read_R_InM_mfTotCanPurgEstim_InM_mfTotCanPurgEstim(&variable)

/**********************************************************************************
   Create interface for variable InM_nEngCor
  **********************************************************************************/

#define vidSET_VALUE_InM_nEngCor(value)
#define vidGET_VALUE_InM_nEngCor(variable)                                       Rte_Read_R_InM_nEngCor_InM_nEngCor(&variable)

/**********************************************************************************
   Create interface for variable InM_pBackEgPUsEGRVlv
  **********************************************************************************/

#define vidSET_VALUE_InM_pBackEgPUsEGRVlv(value)
#define vidGET_VALUE_InM_pBackEgPUsEGRVlv(variable)                              Rte_Read_R_InM_pBackEgPUsEGRVlv_InM_pBackEgPUsEGRVlv(&variable)

/**********************************************************************************
   Create interface for variable InM_pDsThrCor
  **********************************************************************************/

#define vidSET_VALUE_InM_pDsThrCor(value)
#define vidGET_VALUE_InM_pDsThrCor(variable)                                     Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&variable)

/**********************************************************************************
   Create interface for variable InM_pDsThrPred
  **********************************************************************************/

#define vidSET_VALUE_InM_pDsThrPred(value)
#define vidGET_VALUE_InM_pDsThrPred(variable)                                    Rte_Read_R_InM_pDsThrPred_InM_pDsThrPred(&variable)

/**********************************************************************************
   Create interface for variable InM_pDsThrPredInCyl
  **********************************************************************************/

#define vidSET_VALUE_InM_pDsThrPredInCyl(value)
#define vidGET_VALUE_InM_pDsThrPredInCyl(variable)                               Rte_Read_R_InM_pDsThrPredInCyl_InM_pDsThrPredInCyl(&variable)

/**********************************************************************************
   Create interface for variable InM_pUsEGRVlv
  **********************************************************************************/

#define vidSET_VALUE_InM_pUsEGRVlv(value)
#define vidGET_VALUE_InM_pUsEGRVlv(variable)                                     Rte_Read_R_InM_pUsEGRVlv_InM_pUsEGRVlv(&variable)

/**********************************************************************************
   Create interface for array InM_prm_concFuPredCyl
  **********************************************************************************/

#define vidSET_ARRAY_InM_prm_concFuPredCyl(value,size)
#define vidGET_ARRAY_InM_prm_concFuPredCyl(variable,size)                        Rte_Read_R_InM_prm_concFuPredCyl_InM_prm_concFuPredCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InM_prm_concFuPredCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_InM_prm_concFuPredCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_InM_prm_concFuPredCyl datatemp[6];\
     Rte_Read_R_InM_prm_concFuPredCyl_InM_prm_concFuPredCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InM_prm_pDsThrPredOvlpCyl
  **********************************************************************************/

#define vidSET_ARRAY_InM_prm_pDsThrPredOvlpCyl(value,size)
#define vidGET_ARRAY_InM_prm_pDsThrPredOvlpCyl(variable,size)                    Rte_Read_R_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InM_prm_pDsThrPredOvlpCyl(variable,pos)
#define vidGET_ARRAY_ELEMENT_InM_prm_pDsThrPredOvlpCyl(variable,pos){ \
  if (pos < 6)\
  { \
     DT_InM_prm_pDsThrPredOvlpCyl datatemp[6];\
     Rte_Read_R_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable InM_rAirPres
  **********************************************************************************/

#define vidSET_VALUE_InM_rAirPres(value)
#define vidGET_VALUE_InM_rAirPres(variable)                                      Rte_Read_R_InM_rAirPres_InM_rAirPres(&variable)

/**********************************************************************************
   Create interface for variable InM_rCohMnfMf
  **********************************************************************************/

#define vidSET_VALUE_InM_rCohMnfMf(value)
#define vidGET_VALUE_InM_rCohMnfMf(variable)                                     Rte_Read_R_InM_rCohMnfMf_InM_rCohMnfMf(&variable)

/**********************************************************************************
   Create interface for variable InM_rTotLdExEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_rTotLdExEstim(value)
#define vidGET_VALUE_InM_rTotLdExEstim(variable)                                 Rte_Read_R_InM_rTotLdExEstim_InM_rTotLdExEstim(&variable)

/**********************************************************************************
   Create interface for variable InM_stModeMng
  **********************************************************************************/

#define vidSET_VALUE_InM_stModeMng(value)
#define vidGET_VALUE_InM_stModeMng(variable)                                     Rte_Read_R_InM_stModeMng_InM_stModeMng(&variable)

/**********************************************************************************
   Create interface for variable InM_stTranLd
  **********************************************************************************/

#define vidSET_VALUE_InM_stTranLd(value)
#define vidGET_VALUE_InM_stTranLd(variable)                                      Rte_Read_R_InM_stTranLd_InM_stTranLd(&variable)

/**********************************************************************************
   Create interface for variable InM_tiInvEigVal_mAir
  **********************************************************************************/

#define vidSET_VALUE_InM_tiInvEigVal_mAir(value)
#define vidGET_VALUE_InM_tiInvEigVal_mAir(variable)                              Rte_Read_R_InM_tiInvEigVal_mAir_InM_tiInvEigVal_mAir(&variable)

/**********************************************************************************
   Create interface for variable InM_tiInvEigVal_pDsThr
  **********************************************************************************/

#define vidSET_VALUE_InM_tiInvEigVal_pDsThr(value)
#define vidGET_VALUE_InM_tiInvEigVal_pDsThr(variable)                            Rte_Read_R_InM_tiInvEigVal_pDsThr_InM_tiInvEigVal_pDsThr(&variable)

/**********************************************************************************
   Create interface for variable InM_tiRelax_mTotEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_tiRelax_mTotEstim(value)
#define vidGET_VALUE_InM_tiRelax_mTotEstim(variable)                             Rte_Read_R_InM_tiRelax_mTotEstim_InM_tiRelax_mTotEstim(&variable)

/**********************************************************************************
   Create interface for variable InM_tiRelax_pDsThrEstim
  **********************************************************************************/

#define vidSET_VALUE_InM_tiRelax_pDsThrEstim(value)
#define vidGET_VALUE_InM_tiRelax_pDsThrEstim(variable)                           Rte_Read_R_InM_tiRelax_pDsThrEstim_InM_tiRelax_pDsThrEstim(&variable)

/**********************************************************************************
   Create interface for variable InThM_tAirUsInVlvEstim
  **********************************************************************************/

#define vidSET_VALUE_InThM_tAirUsInVlvEstim(value)
#define vidGET_VALUE_InThM_tAirUsInVlvEstim(variable)                            Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim(&variable)

/**********************************************************************************
   Create interface for variable InjCtl_mfFuReq
  **********************************************************************************/

#define vidSET_VALUE_InjCtl_mfFuReq(value)                                       Rte_Write_P_InjCtl_mfFuReq_InjCtl_mfFuReq(value)
#define vidGET_VALUE_InjCtl_mfFuReq(variable)                                    Rte_Read_R_InjCtl_mfFuReq_InjCtl_mfFuReq(&variable)

/**********************************************************************************
   Create interface for variable InjSys_bAcvAirLdMinSat
  **********************************************************************************/

#define vidSET_VALUE_InjSys_bAcvAirLdMinSat(value)                               Rte_Write_P_InjSys_bAcvAirLdMinSat_InjSys_bAcvAirLdMinSat(value)
#define vidGET_VALUE_InjSys_bAcvAirLdMinSat(variable)                            Rte_Read_R_InjSys_bAcvAirLdMinSat_InjSys_bAcvAirLdMinSat(&variable)

/**********************************************************************************
   Create interface for variable InjSys_bAcvFuCll
  **********************************************************************************/

#define vidSET_VALUE_InjSys_bAcvFuCll(value)                                     Rte_Write_P_InjSys_bAcvFuCll_InjSys_bAcvFuCll(value)
#define vidGET_VALUE_InjSys_bAcvFuCll(variable)                                  Rte_Read_R_InjSys_bAcvFuCll_InjSys_bAcvFuCll(&variable)

/**********************************************************************************
   Create interface for variable InjSys_bAcvSpcInjMod
  **********************************************************************************/

#define vidSET_VALUE_InjSys_bAcvSpcInjMod(value)                                 Rte_Write_P_InjSys_bAcvSpcInjMod_InjSys_bAcvSpcInjMod(value)
#define vidGET_VALUE_InjSys_bAcvSpcInjMod(variable)                              Rte_Read_R_InjSys_bAcvSpcInjMod_InjSys_bAcvSpcInjMod(&variable)

/**********************************************************************************
   Create interface for variable InjSys_bAcvSpcInjModCmdInjr
  **********************************************************************************/

#define vidSET_VALUE_InjSys_bAcvSpcInjModCmdInjr(value)                          Rte_Write_P_InjSys_bAcvSpcInjModCmdInjr_InjSys_bAcvSpcInjModCmdInjr(value)
#define vidGET_VALUE_InjSys_bAcvSpcInjModCmdInjr(variable)                       Rte_Read_R_InjSys_bAcvSpcInjModCmdInjr_InjSys_bAcvSpcInjModCmdInjr(&variable)

/**********************************************************************************
   Create interface for variable InjSys_bAcvSpcInjModOvlp
  **********************************************************************************/

#define vidSET_VALUE_InjSys_bAcvSpcInjModOvlp(value)                             Rte_Write_P_InjSys_bAcvSpcInjModOvlp_InjSys_bAcvSpcInjModOvlp(value)
#define vidGET_VALUE_InjSys_bAcvSpcInjModOvlp(variable)                          Rte_Read_R_InjSys_bAcvSpcInjModOvlp_InjSys_bAcvSpcInjModOvlp(&variable)

/**********************************************************************************
   Create interface for variable InjSys_bFuCutOff
  **********************************************************************************/

#define vidSET_VALUE_InjSys_bFuCutOff(value)                                     Rte_Write_P_InjSys_bFuCutOff_InjSys_bFuCutOff(value)
#define vidGET_VALUE_InjSys_bFuCutOff(variable)                                  Rte_Read_R_InjSys_bFuCutOff_InjSys_bFuCutOff(&variable)

/**********************************************************************************
   Create interface for variable InjSys_bTotCutOff
  **********************************************************************************/

#define vidSET_VALUE_InjSys_bTotCutOff(value)                                    Rte_Write_P_InjSys_bTotCutOff_InjSys_bTotCutOff(value)
#define vidGET_VALUE_InjSys_bTotCutOff(variable)                                 Rte_Read_R_InjSys_bTotCutOff_InjSys_bTotCutOff(&variable)

/**********************************************************************************
   Create interface for variable InjSys_ctNbCmbAst
  **********************************************************************************/

#define vidSET_VALUE_InjSys_ctNbCmbAst(value)                                    Rte_Write_P_InjSys_ctNbCmbAst_InjSys_ctNbCmbAst(value)
#define vidGET_VALUE_InjSys_ctNbCmbAst(variable)                                 Rte_Read_R_InjSys_ctNbCmbAst_InjSys_ctNbCmbAst(&variable)

/**********************************************************************************
   Create interface for variable InjSys_lamFbFil
  **********************************************************************************/

#define vidSET_VALUE_InjSys_lamFbFil(value)                                      Rte_Write_P_InjSys_lamFbFil_InjSys_lamFbFil(value)
#define vidGET_VALUE_InjSys_lamFbFil(variable)                                   Rte_Read_R_InjSys_lamFbFil_InjSys_lamFbFil(&variable)

/**********************************************************************************
   Create interface for variable InjSys_mFuReq
  **********************************************************************************/

#define vidSET_VALUE_InjSys_mFuReq(value)                                        Rte_Write_P_InjSys_mFuReq_InjSys_mFuReq(value)
#define vidGET_VALUE_InjSys_mFuReq(variable)                                     Rte_Read_R_InjSys_mFuReq_InjSys_mFuReq(&variable)

/**********************************************************************************
   Create interface for variable InjSys_noCylCutOff
  **********************************************************************************/

#define vidSET_VALUE_InjSys_noCylCutOff(value)                                   Rte_Write_P_InjSys_noCylCutOff_InjSys_noCylCutOff(value)
#define vidGET_VALUE_InjSys_noCylCutOff(variable)                                Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff(&variable)

/**********************************************************************************
   Create interface for variable InjSys_noTDCDlyLsclFilMod
  **********************************************************************************/

#define vidSET_VALUE_InjSys_noTDCDlyLsclFilMod(value)                            Rte_Write_P_InjSys_noTDCDlyLsclFilMod_InjSys_noTDCDlyLsclFilMod(value)
#define vidGET_VALUE_InjSys_noTDCDlyLsclFilMod(variable)                         Rte_Read_R_InjSys_noTDCDlyLsclFilMod_InjSys_noTDCDlyLsclFilMod(&variable)

/**********************************************************************************
   Create interface for array InjSys_prm_agBegInjH1ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_agBegInjH1ReqCyl(value,size)                     Rte_Write_P_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_agBegInjH1ReqCyl(variable,size)                  Rte_Read_R_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_agBegInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_agBegInjH1ReqCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_agBegInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_agBegInjH1ReqCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_agBegInjH2ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_agBegInjH2ReqCyl(value,size)                     Rte_Write_P_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_agBegInjH2ReqCyl(variable,size)                  Rte_Read_R_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_agBegInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_agBegInjH2ReqCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_agBegInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_agBegInjH2ReqCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_agBegInjS1ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_agBegInjS1ReqCyl(value,size)                     Rte_Write_P_InjSys_prm_agBegInjS1ReqCyl_InjSys_prm_agBegInjS1ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_agBegInjS1ReqCyl(variable,size)                  Rte_Read_R_InjSys_prm_agBegInjS1ReqCyl_InjSys_prm_agBegInjS1ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_agBegInjS1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    uint16 datatemp[6];\
    Rte_Read_R_InjSys_prm_agBegInjS1ReqCyl_InjSys_prm_agBegInjS1ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_agBegInjS1ReqCyl_InjSys_prm_agBegInjS1ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_agBegInjS1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     uint16 datatemp[6];\
     Rte_Read_R_InjSys_prm_agBegInjS1ReqCyl_InjSys_prm_agBegInjS1ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_agBegInjS2ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_agBegInjS2ReqCyl(value,size)                     Rte_Write_P_InjSys_prm_agBegInjS2ReqCyl_InjSys_prm_agBegInjS2ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_agBegInjS2ReqCyl(variable,size)                  Rte_Read_R_InjSys_prm_agBegInjS2ReqCyl_InjSys_prm_agBegInjS2ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_agBegInjS2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    uint16 datatemp[6];\
    Rte_Read_R_InjSys_prm_agBegInjS2ReqCyl_InjSys_prm_agBegInjS2ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_agBegInjS2ReqCyl_InjSys_prm_agBegInjS2ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_agBegInjS2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     uint16 datatemp[6];\
     Rte_Read_R_InjSys_prm_agBegInjS2ReqCyl_InjSys_prm_agBegInjS2ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_agEndInjH1ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_agEndInjH1ReqCyl(value,size)                     Rte_Write_P_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_agEndInjH1ReqCyl(variable,size)                  Rte_Read_R_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_agEndInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_agEndInjH1ReqCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_agEndInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_agEndInjH1ReqCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_agEndInjH2ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_agEndInjH2ReqCyl(value,size)                     Rte_Write_P_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_agEndInjH2ReqCyl(variable,size)                  Rte_Read_R_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_agEndInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_agEndInjH2ReqCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_agEndInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_agEndInjH2ReqCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_bCylCutOff
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_bCylCutOff(value,size)                           Rte_Write_P_InjSys_prm_bCylCutOff_InjSys_prm_bCylCutOff(&value)
#define vidGET_ARRAY_InjSys_prm_bCylCutOff(variable,size)                        Rte_Read_R_InjSys_prm_bCylCutOff_InjSys_prm_bCylCutOff(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_bCylCutOff(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_bCylCutOff datatemp[6];\
    Rte_Read_R_InjSys_prm_bCylCutOff_InjSys_prm_bCylCutOff(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_bCylCutOff_InjSys_prm_bCylCutOff(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_bCylCutOff(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_bCylCutOff datatemp[6];\
     Rte_Read_R_InjSys_prm_bCylCutOff_InjSys_prm_bCylCutOff(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_bInjCutOffCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_bInjCutOffCyl(value,size)                        Rte_Write_P_InjSys_prm_bInjCutOffCyl_InjSys_prm_bInjCutOffCyl(&value)
#define vidGET_ARRAY_InjSys_prm_bInjCutOffCyl(variable,size)                     Rte_Read_R_InjSys_prm_bInjCutOffCyl_InjSys_prm_bInjCutOffCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_bInjCutOffCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_bInjCutOffCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_bInjCutOffCyl_InjSys_prm_bInjCutOffCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_bInjCutOffCyl_InjSys_prm_bInjCutOffCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_bInjCutOffCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_bInjCutOffCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_bInjCutOffCyl_InjSys_prm_bInjCutOffCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_facInjCmpCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_facInjCmpCyl(value,size)                         Rte_Write_P_InjSys_prm_facInjCmpCyl_InjSys_prm_facInjCmpCyl(&value)
#define vidGET_ARRAY_InjSys_prm_facInjCmpCyl(variable,size)                      Rte_Read_R_InjSys_prm_facInjCmpCyl_InjSys_prm_facInjCmpCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_facInjCmpCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_facInjCmpCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_facInjCmpCyl_InjSys_prm_facInjCmpCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_facInjCmpCyl_InjSys_prm_facInjCmpCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_facInjCmpCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_facInjCmpCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_facInjCmpCyl_InjSys_prm_facInjCmpCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_facStrtCorCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_facStrtCorCyl(value,size)                        Rte_Write_P_InjSys_prm_facStrtCorCyl_InjSys_prm_facStrtCorCyl(&value)
#define vidGET_ARRAY_InjSys_prm_facStrtCorCyl(variable,size)                     Rte_Read_R_InjSys_prm_facStrtCorCyl_InjSys_prm_facStrtCorCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_facStrtCorCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_facStrtCorCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_facStrtCorCyl_InjSys_prm_facStrtCorCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_facStrtCorCyl_InjSys_prm_facStrtCorCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_facStrtCorCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_facStrtCorCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_facStrtCorCyl_InjSys_prm_facStrtCorCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_mFuInjH1ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_mFuInjH1ReqCyl(value,size)                       Rte_Write_P_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_mFuInjH1ReqCyl(variable,size)                    Rte_Read_R_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_mFuInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_mFuInjH1ReqCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_mFuInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_mFuInjH1ReqCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjSys_prm_mFuInjH2ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjSys_prm_mFuInjH2ReqCyl(value,size)                       Rte_Write_P_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl(&value)
#define vidGET_ARRAY_InjSys_prm_mFuInjH2ReqCyl(variable,size)                    Rte_Read_R_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjSys_prm_mFuInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_InjSys_prm_mFuInjH2ReqCyl datatemp[6];\
    Rte_Read_R_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjSys_prm_mFuInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_InjSys_prm_mFuInjH2ReqCyl datatemp[6];\
     Rte_Read_R_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable InjSys_stTypElCmdInjrReq
  **********************************************************************************/

#define vidSET_VALUE_InjSys_stTypElCmdInjrReq(value)                             Rte_Write_P_InjSys_stTypElCmdInjrReq_InjSys_stTypElCmdInjrReq(value)
#define vidGET_VALUE_InjSys_stTypElCmdInjrReq(variable)                          Rte_Read_R_InjSys_stTypElCmdInjrReq_InjSys_stTypElCmdInjrReq(&variable)

/**********************************************************************************
   Create interface for variable Inj_bInhInjr1
  **********************************************************************************/

#define vidSET_VALUE_Inj_bInhInjr1(value)
#define vidGET_VALUE_Inj_bInhInjr1(variable)                                     Rte_Read_R_Inj_bInhInjr1_Inj_bInhInjr1(&variable)

/**********************************************************************************
   Create interface for variable Inj_bInhInjr2
  **********************************************************************************/

#define vidSET_VALUE_Inj_bInhInjr2(value)
#define vidGET_VALUE_Inj_bInhInjr2(variable)                                     Rte_Read_R_Inj_bInhInjr2_Inj_bInhInjr2(&variable)

/**********************************************************************************
   Create interface for variable Inj_bInhInjr3
  **********************************************************************************/

#define vidSET_VALUE_Inj_bInhInjr3(value)
#define vidGET_VALUE_Inj_bInhInjr3(variable)                                     Rte_Read_R_Inj_bInhInjr3_Inj_bInhInjr3(&variable)

/**********************************************************************************
   Create interface for variable Inj_bInhInjr4
  **********************************************************************************/

#define vidSET_VALUE_Inj_bInhInjr4(value)
#define vidGET_VALUE_Inj_bInhInjr4(variable)                                     Rte_Read_R_Inj_bInhInjr4_Inj_bInhInjr4(&variable)

/**********************************************************************************
   Create interface for array InjrM_prm_facCorGainLnr
  **********************************************************************************/

#define vidSET_ARRAY_InjrM_prm_facCorGainLnr(value,size)                         Rte_Write_P_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr(&value)
#define vidGET_ARRAY_InjrM_prm_facCorGainLnr(variable,size)                      Rte_Read_R_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr(&variable)

#define vidSET_ARRAY_ELEMENT_InjrM_prm_facCorGainLnr(variable,pos) \
{ \
  if (pos < 4)\
  {\
    DT_InjrM_prm_facCorGainLnr datatemp[4];\
    Rte_Read_R_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrM_prm_facCorGainLnr(variable,pos) \
{ \
  if (pos < 4)\
  { \
     DT_InjrM_prm_facCorGainLnr datatemp[4];\
     Rte_Read_R_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjrM_prm_facGainInj
  **********************************************************************************/

#define vidSET_ARRAY_InjrM_prm_facGainInj(value,size)                            Rte_Write_P_InjrM_prm_facGainInj_InjrM_prm_facGainInj(&value)
#define vidGET_ARRAY_InjrM_prm_facGainInj(variable,size)                         Rte_Read_R_InjrM_prm_facGainInj_InjrM_prm_facGainInj(&variable)

#define vidSET_ARRAY_ELEMENT_InjrM_prm_facGainInj(variable,pos) \
{ \
  if (pos < 4)\
  {\
    DT_InjrM_prm_facGainInj datatemp[4];\
    Rte_Read_R_InjrM_prm_facGainInj_InjrM_prm_facGainInj(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrM_prm_facGainInj_InjrM_prm_facGainInj(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrM_prm_facGainInj(variable,pos) \
{ \
  if (pos < 4)\
  { \
     DT_InjrM_prm_facGainInj datatemp[4];\
     Rte_Read_R_InjrM_prm_facGainInj_InjrM_prm_facGainInj(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjrM_prm_pDifInjr
  **********************************************************************************/

#define vidSET_ARRAY_InjrM_prm_pDifInjr(value,size)                              Rte_Write_P_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr(&value)
#define vidGET_ARRAY_InjrM_prm_pDifInjr(variable,size)                           Rte_Read_R_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr(&variable)

#define vidSET_ARRAY_ELEMENT_InjrM_prm_pDifInjr(variable,pos) \
{ \
  if (pos < 4)\
  {\
    DT_InjrM_prm_pDifInjr datatemp[4];\
    Rte_Read_R_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrM_prm_pDifInjr(variable,pos) \
{ \
  if (pos < 4)\
  { \
     DT_InjrM_prm_pDifInjr datatemp[4];\
     Rte_Read_R_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjrSys_prm_tiInj
  **********************************************************************************/

#define vidSET_ARRAY_InjrSys_prm_tiInj(value,size)                               Rte_Write_P_InjrSys_prm_tiInj_InjrSys_prm_tiInj(&value)
#define vidGET_ARRAY_InjrSys_prm_tiInj(variable,size)                            Rte_Read_R_InjrSys_prm_tiInj_InjrSys_prm_tiInj(&variable)

#define vidSET_ARRAY_ELEMENT_InjrSys_prm_tiInj(variable,pos) \
{ \
  if (pos < 4)\
  {\
    DT_InjrSys_prm_tiInj datatemp[4];\
    Rte_Read_R_InjrSys_prm_tiInj_InjrSys_prm_tiInj(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrSys_prm_tiInj_InjrSys_prm_tiInj(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrSys_prm_tiInj(variable,pos) \
{ \
  if (pos < 4)\
  { \
     DT_InjrSys_prm_tiInj datatemp[4];\
     Rte_Read_R_InjrSys_prm_tiInj_InjrSys_prm_tiInj(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjrSys_prm_tiInjH1ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjrSys_prm_tiInjH1ReqCyl(value,size)                       Rte_Write_P_InjrSys_prm_tiInjH1ReqCyl_InjrSys_prm_tiInjH1ReqCyl(&value)
#define vidGET_ARRAY_InjrSys_prm_tiInjH1ReqCyl(variable,size)                    Rte_Read_R_InjrSys_prm_tiInjH1ReqCyl_InjrSys_prm_tiInjH1ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjrSys_prm_tiInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    uint32 datatemp[6];\
    Rte_Read_R_InjrSys_prm_tiInjH1ReqCyl_InjrSys_prm_tiInjH1ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrSys_prm_tiInjH1ReqCyl_InjrSys_prm_tiInjH1ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrSys_prm_tiInjH1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     uint32 datatemp[6];\
     Rte_Read_R_InjrSys_prm_tiInjH1ReqCyl_InjrSys_prm_tiInjH1ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjrSys_prm_tiInjH2ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjrSys_prm_tiInjH2ReqCyl(value,size)                       Rte_Write_P_InjrSys_prm_tiInjH2ReqCyl_InjrSys_prm_tiInjH2ReqCyl(&value)
#define vidGET_ARRAY_InjrSys_prm_tiInjH2ReqCyl(variable,size)                    Rte_Read_R_InjrSys_prm_tiInjH2ReqCyl_InjrSys_prm_tiInjH2ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjrSys_prm_tiInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    uint32 datatemp[6];\
    Rte_Read_R_InjrSys_prm_tiInjH2ReqCyl_InjrSys_prm_tiInjH2ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrSys_prm_tiInjH2ReqCyl_InjrSys_prm_tiInjH2ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrSys_prm_tiInjH2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     uint32 datatemp[6];\
     Rte_Read_R_InjrSys_prm_tiInjH2ReqCyl_InjrSys_prm_tiInjH2ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjrSys_prm_tiInjS1ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjrSys_prm_tiInjS1ReqCyl(value,size)                       Rte_Write_P_InjrSys_prm_tiInjS1ReqCyl_InjrSys_prm_tiInjS1ReqCyl(&value)
#define vidGET_ARRAY_InjrSys_prm_tiInjS1ReqCyl(variable,size)                    Rte_Read_R_InjrSys_prm_tiInjS1ReqCyl_InjrSys_prm_tiInjS1ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjrSys_prm_tiInjS1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    uint32 datatemp[6];\
    Rte_Read_R_InjrSys_prm_tiInjS1ReqCyl_InjrSys_prm_tiInjS1ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrSys_prm_tiInjS1ReqCyl_InjrSys_prm_tiInjS1ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrSys_prm_tiInjS1ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     uint32 datatemp[6];\
     Rte_Read_R_InjrSys_prm_tiInjS1ReqCyl_InjrSys_prm_tiInjS1ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array InjrSys_prm_tiInjS2ReqCyl
  **********************************************************************************/

#define vidSET_ARRAY_InjrSys_prm_tiInjS2ReqCyl(value,size)                       Rte_Write_P_InjrSys_prm_tiInjS2ReqCyl_InjrSys_prm_tiInjS2ReqCyl(&value)
#define vidGET_ARRAY_InjrSys_prm_tiInjS2ReqCyl(variable,size)                    Rte_Read_R_InjrSys_prm_tiInjS2ReqCyl_InjrSys_prm_tiInjS2ReqCyl(&variable)

#define vidSET_ARRAY_ELEMENT_InjrSys_prm_tiInjS2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    uint32 datatemp[6];\
    Rte_Read_R_InjrSys_prm_tiInjS2ReqCyl_InjrSys_prm_tiInjS2ReqCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_InjrSys_prm_tiInjS2ReqCyl_InjrSys_prm_tiInjS2ReqCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_InjrSys_prm_tiInjS2ReqCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     uint32 datatemp[6];\
     Rte_Read_R_InjrSys_prm_tiInjS2ReqCyl_InjrSys_prm_tiInjS2ReqCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable KnkMgt_agIgOfsKnkDft
  **********************************************************************************/

#define vidSET_VALUE_KnkMgt_agIgOfsKnkDft(value)                                 Rte_Write_P_KnkMgt_agIgOfsKnkDft_KnkMgt_agIgOfsKnkDft(value)
#define vidGET_VALUE_KnkMgt_agIgOfsKnkDft(variable)                              Rte_Read_R_KnkMgt_agIgOfsKnkDft_KnkMgt_agIgOfsKnkDft(&variable)

/**********************************************************************************
   Create interface for variable KnkMgt_bAcvIrvLdLimRblReq
  **********************************************************************************/

#define vidSET_VALUE_KnkMgt_bAcvIrvLdLimRblReq(value)                            Rte_Write_P_KnkMgt_bAcvIrvLdLimRblReq_KnkMgt_bAcvIrvLdLimRblReq(value)
#define vidGET_VALUE_KnkMgt_bAcvIrvLdLimRblReq(variable)                         Rte_Read_R_KnkMgt_bAcvIrvLdLimRblReq_KnkMgt_bAcvIrvLdLimRblReq(&variable)

/**********************************************************************************
   Create interface for variable KnkMgt_bAcvTmpLdLimKnkReq
  **********************************************************************************/

#define vidSET_VALUE_KnkMgt_bAcvTmpLdLimKnkReq(value)                            Rte_Write_P_KnkMgt_bAcvTmpLdLimKnkReq_KnkMgt_bAcvTmpLdLimKnkReq(value)
#define vidGET_VALUE_KnkMgt_bAcvTmpLdLimKnkReq(variable)                         Rte_Read_R_KnkMgt_bAcvTmpLdLimKnkReq_KnkMgt_bAcvTmpLdLimKnkReq(&variable)

/**********************************************************************************
   Create interface for variable KnkMgt_bAcvTmpLdLimRblReq
  **********************************************************************************/

#define vidSET_VALUE_KnkMgt_bAcvTmpLdLimRblReq(value)                            Rte_Write_P_KnkMgt_bAcvTmpLdLimRblReq_KnkMgt_bAcvTmpLdLimRblReq(value)
#define vidGET_VALUE_KnkMgt_bAcvTmpLdLimRblReq(variable)                         Rte_Read_R_KnkMgt_bAcvTmpLdLimRblReq_KnkMgt_bAcvTmpLdLimRblReq(&variable)

/**********************************************************************************
   Create interface for variable KnkMgt_bAcvVlvPosnRblReq
  **********************************************************************************/

#define vidSET_VALUE_KnkMgt_bAcvVlvPosnRblReq(value)                             Rte_Write_P_KnkMgt_bAcvVlvPosnRblReq_KnkMgt_bAcvVlvPosnRblReq(value)
#define vidGET_VALUE_KnkMgt_bAcvVlvPosnRblReq(variable)                          Rte_Read_R_KnkMgt_bAcvVlvPosnRblReq_KnkMgt_bAcvVlvPosnRblReq(&variable)

/**********************************************************************************
   Create interface for array KnkMgt_prm_agIgKnkAdpOfsCyl
  **********************************************************************************/

#define vidSET_ARRAY_KnkMgt_prm_agIgKnkAdpOfsCyl(value,size)                     Rte_Write_P_KnkMgt_prm_agIgKnkAdpOfsCyl_KnkMgt_prm_agIgKnkAdpOfsCyl(&value)
#define vidGET_ARRAY_KnkMgt_prm_agIgKnkAdpOfsCyl(variable,size)                  Rte_Read_R_KnkMgt_prm_agIgKnkAdpOfsCyl_KnkMgt_prm_agIgKnkAdpOfsCyl(&variable)

#define vidSET_ARRAY_ELEMENT_KnkMgt_prm_agIgKnkAdpOfsCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_KnkMgt_prm_agIgKnkAdpOfsCyl datatemp[6];\
    Rte_Read_R_KnkMgt_prm_agIgKnkAdpOfsCyl_KnkMgt_prm_agIgKnkAdpOfsCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_KnkMgt_prm_agIgKnkAdpOfsCyl_KnkMgt_prm_agIgKnkAdpOfsCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_KnkMgt_prm_agIgKnkAdpOfsCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_KnkMgt_prm_agIgKnkAdpOfsCyl datatemp[6];\
     Rte_Read_R_KnkMgt_prm_agIgKnkAdpOfsCyl_KnkMgt_prm_agIgKnkAdpOfsCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array KnkMgt_prm_agIgKnkDetOfsCyl
  **********************************************************************************/

#define vidSET_ARRAY_KnkMgt_prm_agIgKnkDetOfsCyl(value,size)                     Rte_Write_P_KnkMgt_prm_agIgKnkDetOfsCyl_KnkMgt_prm_agIgKnkDetOfsCyl(&value)
#define vidGET_ARRAY_KnkMgt_prm_agIgKnkDetOfsCyl(variable,size)                  Rte_Read_R_KnkMgt_prm_agIgKnkDetOfsCyl_KnkMgt_prm_agIgKnkDetOfsCyl(&variable)

#define vidSET_ARRAY_ELEMENT_KnkMgt_prm_agIgKnkDetOfsCyl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_KnkMgt_prm_agIgKnkDetOfsCyl datatemp[6];\
    Rte_Read_R_KnkMgt_prm_agIgKnkDetOfsCyl_KnkMgt_prm_agIgKnkDetOfsCyl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_KnkMgt_prm_agIgKnkDetOfsCyl_KnkMgt_prm_agIgKnkDetOfsCyl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_KnkMgt_prm_agIgKnkDetOfsCyl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_KnkMgt_prm_agIgKnkDetOfsCyl datatemp[6];\
     Rte_Read_R_KnkMgt_prm_agIgKnkDetOfsCyl_KnkMgt_prm_agIgKnkDetOfsCyl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array KnkMgt_prm_ctRblInjCutOffPtl
  **********************************************************************************/

#define vidSET_ARRAY_KnkMgt_prm_ctRblInjCutOffPtl(value,size)                    Rte_Write_P_KnkMgt_prm_ctRblInjCutOffPtl_KnkMgt_prm_ctRblInjCutOffPtl(&value)
#define vidGET_ARRAY_KnkMgt_prm_ctRblInjCutOffPtl(variable,size)                 Rte_Read_R_KnkMgt_prm_ctRblInjCutOffPtl_KnkMgt_prm_ctRblInjCutOffPtl(&variable)

#define vidSET_ARRAY_ELEMENT_KnkMgt_prm_ctRblInjCutOffPtl(variable,pos) \
{ \
  if (pos < 6)\
  {\
    DT_KnkMgt_prm_ctRblInjCutOffPtl datatemp[6];\
    Rte_Read_R_KnkMgt_prm_ctRblInjCutOffPtl_KnkMgt_prm_ctRblInjCutOffPtl(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_KnkMgt_prm_ctRblInjCutOffPtl_KnkMgt_prm_ctRblInjCutOffPtl(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_KnkMgt_prm_ctRblInjCutOffPtl(variable,pos) \
{ \
  if (pos < 6)\
  { \
     DT_KnkMgt_prm_ctRblInjCutOffPtl datatemp[6];\
     Rte_Read_R_KnkMgt_prm_ctRblInjCutOffPtl_KnkMgt_prm_ctRblInjCutOffPtl(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable LSA_lamUsMes
  **********************************************************************************/

#define vidSET_VALUE_LSA_lamUsMes(value)                                         Rte_Write_P_LSA_lamUsMes_LSA_lamUsMes(value)
#define vidGET_VALUE_LSA_lamUsMes(variable)                                      Rte_Read_R_LSA_lamUsMes_LSA_lamUsMes(&variable)

/**********************************************************************************
   Create interface for variable LsMon_bAcvItrsvSenO2DsDiag
  **********************************************************************************/

#define vidSET_VALUE_LsMon_bAcvItrsvSenO2DsDiag(value)                           Rte_Write_P_LsMon_bAcvItrsvSenO2DsDiag_LsMon_bAcvItrsvSenO2DsDiag(value)
#define vidGET_VALUE_LsMon_bAcvItrsvSenO2DsDiag(variable)                        Rte_Read_R_LsMon_bAcvItrsvSenO2DsDiag_LsMon_bAcvItrsvSenO2DsDiag(&variable)

/**********************************************************************************
   Create interface for variable LsMon_bAcvReqMonItrsv
  **********************************************************************************/

#define vidSET_VALUE_LsMon_bAcvReqMonItrsv(value)                                Rte_Write_P_LsMon_bAcvReqMonItrsv_LsMon_bAcvReqMonItrsv(value)
#define vidGET_VALUE_LsMon_bAcvReqMonItrsv(variable)                             Rte_Read_R_LsMon_bAcvReqMonItrsv_LsMon_bAcvReqMonItrsv(&variable)

/**********************************************************************************
   Create interface for variable LsMon_bCaseItrsvSenO2DsDiag
  **********************************************************************************/

#define vidSET_VALUE_LsMon_bCaseItrsvSenO2DsDiag(value)                          Rte_Write_P_LsMon_bCaseItrsvSenO2DsDiag_LsMon_bCaseItrsvSenO2DsDiag(value)
#define vidGET_VALUE_LsMon_bCaseItrsvSenO2DsDiag(variable)                       Rte_Read_R_LsMon_bCaseItrsvSenO2DsDiag_LsMon_bCaseItrsvSenO2DsDiag(&variable)

/**********************************************************************************
   Create interface for variable LsMon_rMixtReqMonItrsv
  **********************************************************************************/

#define vidSET_VALUE_LsMon_rMixtReqMonItrsv(value)                               Rte_Write_P_LsMon_rMixtReqMonItrsv_LsMon_rMixtReqMonItrsv(value)
#define vidGET_VALUE_LsMon_rMixtReqMonItrsv(variable)                            Rte_Read_R_LsMon_rMixtReqMonItrsv_LsMon_rMixtReqMonItrsv(&variable)

/**********************************************************************************
   Create interface for variable LsMon_stItrsvSenO2DsDiag
  **********************************************************************************/

#define vidSET_VALUE_LsMon_stItrsvSenO2DsDiag(value)
#define vidGET_VALUE_LsMon_stItrsvSenO2DsDiag(variable)                          Rte_Read_R_LsMon_stItrsvSenO2DsDiag_LsMon_stItrsvSenO2DsDiag(&variable)

/**********************************************************************************
   Create interface for variable LsSys_bLsDsMainOxCHeatOk
  **********************************************************************************/

#define vidSET_VALUE_LsSys_bLsDsMainOxCHeatOk(value)                             Rte_Write_P_LsSys_bLsDsMainOxCHeatOk_LsSys_bLsDsMainOxCHeatOk(value)
#define vidGET_VALUE_LsSys_bLsDsMainOxCHeatOk(variable)                          Rte_Read_R_LsSys_bLsDsMainOxCHeatOk_LsSys_bLsDsMainOxCHeatOk(&variable)

/**********************************************************************************
   Create interface for variable LsSys_bLsUsMainOxCDewProtReq
  **********************************************************************************/

#define vidSET_VALUE_LsSys_bLsUsMainOxCDewProtReq(value)                         Rte_Write_P_LsSys_bLsUsMainOxCDewProtReq_LsSys_bLsUsMainOxCDewProtReq(value)
#define vidGET_VALUE_LsSys_bLsUsMainOxCDewProtReq(variable)                      Rte_Read_R_LsSys_bLsUsMainOxCDewProtReq_LsSys_bLsUsMainOxCDewProtReq(&variable)

/**********************************************************************************
   Create interface for variable Lshd_down_strm_lbda_sens_hot
  **********************************************************************************/

#define vidSET_VALUE_Lshd_down_strm_lbda_sens_hot(value)                         Rte_Write_P_Lshd_down_strm_lbda_sens_hot_Lshd_down_strm_lbda_sens_hot(value)
#define vidGET_VALUE_Lshd_down_strm_lbda_sens_hot(variable)                      Rte_Read_R_Lshd_down_strm_lbda_sens_hot_Lshd_down_strm_lbda_sens_hot(&variable)

/**********************************************************************************
   Create interface for variable Lshd_up_strm_lbda_sens_hot
  **********************************************************************************/

#define vidSET_VALUE_Lshd_up_strm_lbda_sens_hot(value)                           Rte_Write_P_Lshd_up_strm_lbda_sens_hot_Lshd_up_strm_lbda_sens_hot(value)
#define vidGET_VALUE_Lshd_up_strm_lbda_sens_hot(variable)                        Rte_Read_R_Lshd_up_strm_lbda_sens_hot_Lshd_up_strm_lbda_sens_hot(&variable)

/**********************************************************************************
   Create interface for variable MPM_EveSync_DmgMSI
  **********************************************************************************/

#define vidSET_VALUE_MPM_EveSync_DmgMSI(value)                                   Rte_Write_P_MPM_EveSync_DmgMSI_MPM_EveSync_DmgMSI(value)
#define vidGET_VALUE_MPM_EveSync_DmgMSI(variable)                                Rte_Read_R_MPM_EveSync_DmgMSI_MPM_EveSync_DmgMSI(&variable)

/**********************************************************************************
   Create interface for variable MPM_EveSync_pCylMax
  **********************************************************************************/

#define vidSET_VALUE_MPM_EveSync_pCylMax(value)                                  Rte_Write_P_MPM_EveSync_pCylMax_MPM_EveSync_pCylMax(value)
#define vidGET_VALUE_MPM_EveSync_pCylMax(variable)                               Rte_Read_R_MPM_EveSync_pCylMax_MPM_EveSync_pCylMax(&variable)

/**********************************************************************************
   Create interface for variable Misfire_cylindre_1
  **********************************************************************************/

#define vidSET_VALUE_Misfire_cylindre_1(value)                                   Rte_Write_P_Misfire_cylindre_1_Misfire_cylindre_1(value)
#define vidGET_VALUE_Misfire_cylindre_1(variable)                                Rte_Read_R_Misfire_cylindre_1_Misfire_cylindre_1(&variable)

/**********************************************************************************
   Create interface for variable Misfire_cylindre_2
  **********************************************************************************/

#define vidSET_VALUE_Misfire_cylindre_2(value)                                   Rte_Write_P_Misfire_cylindre_2_Misfire_cylindre_2(value)
#define vidGET_VALUE_Misfire_cylindre_2(variable)                                Rte_Read_R_Misfire_cylindre_2_Misfire_cylindre_2(&variable)

/**********************************************************************************
   Create interface for variable Misfire_cylindre_3
  **********************************************************************************/

#define vidSET_VALUE_Misfire_cylindre_3(value)                                   Rte_Write_P_Misfire_cylindre_3_Misfire_cylindre_3(value)
#define vidGET_VALUE_Misfire_cylindre_3(variable)                                Rte_Read_R_Misfire_cylindre_3_Misfire_cylindre_3(&variable)

/**********************************************************************************
   Create interface for variable Misfire_cylindre_4
  **********************************************************************************/

#define vidSET_VALUE_Misfire_cylindre_4(value)                                   Rte_Write_P_Misfire_cylindre_4_Misfire_cylindre_4(value)
#define vidGET_VALUE_Misfire_cylindre_4(variable)                                Rte_Read_R_Misfire_cylindre_4_Misfire_cylindre_4(&variable)

/**********************************************************************************
   Create interface for variable Monitor_fdbk_cond_stat_swc
  **********************************************************************************/

#define vidSET_VALUE_Monitor_fdbk_cond_stat_swc(value)                           Rte_Write_P_Monitor_fdbk_cond_stat_swc_Monitor_fdbk_cond_stat_swc(value)
#define vidGET_VALUE_Monitor_fdbk_cond_stat_swc(variable)                        Rte_Read_R_Monitor_fdbk_cond_stat_swc_Monitor_fdbk_cond_stat_swc(&variable)

/**********************************************************************************
   Create interface for variable Moteur_synchronise
  **********************************************************************************/

#define vidSET_VALUE_Moteur_synchronise(value)                                   Rte_Write_P_Moteur_synchronise_Moteur_synchronise(value)
#define vidGET_VALUE_Moteur_synchronise(variable)                                Rte_Read_R_Moteur_synchronise_Moteur_synchronise(&variable)

/**********************************************************************************
   Create interface for variable OilSysHw_frqPmpCmd
  **********************************************************************************/

#define vidSET_VALUE_OilSysHw_frqPmpCmd(value)                                   Rte_Write_P_OilSysHw_frqPmpCmd_OilSysHw_frqPmpCmd(value)
#define vidGET_VALUE_OilSysHw_frqPmpCmd(variable)                                Rte_Read_R_OilSysHw_frqPmpCmd_OilSysHw_frqPmpCmd(&variable)

/**********************************************************************************
   Create interface for variable OilSys_rCtlPmpReq
  **********************************************************************************/

#define vidSET_VALUE_OilSys_rCtlPmpReq(value)
#define vidGET_VALUE_OilSys_rCtlPmpReq(variable)                                 Rte_Read_R_OilSys_rCtlPmpReq_OilSys_rCtlPmpReq(&variable)

/**********************************************************************************
   Create interface for variable Oil_bAcvCkOilPresAcq
  **********************************************************************************/

#define vidSET_VALUE_Oil_bAcvCkOilPresAcq(value)                                 Rte_Write_P_Oil_bAcvCkOilPresAcq_Oil_bAcvCkOilPresAcq(value)
#define vidGET_VALUE_Oil_bAcvCkOilPresAcq(variable)                              Rte_Read_R_Oil_bAcvCkOilPresAcq_Oil_bAcvCkOilPresAcq(&variable)

/**********************************************************************************
   Create interface for variable Oil_rPmpCmdAppl
  **********************************************************************************/

#define vidSET_VALUE_Oil_rPmpCmdAppl(value)                                      Rte_Write_P_Oil_rPmpCmdAppl_Oil_rPmpCmdAppl(value)
#define vidGET_VALUE_Oil_rPmpCmdAppl(variable)                                   Rte_Read_R_Oil_rPmpCmdAppl_Oil_rPmpCmdAppl(&variable)

/**********************************************************************************
   Create interface for variable OxC_bAcvPrioMgt
  **********************************************************************************/

#define vidSET_VALUE_OxC_bAcvPrioMgt(value)                                      Rte_Write_P_OxC_bAcvPrioMgt_OxC_bAcvPrioMgt(value)
#define vidGET_VALUE_OxC_bAcvPrioMgt(variable)                                   Rte_Read_R_OxC_bAcvPrioMgt_OxC_bAcvPrioMgt(&variable)

/**********************************************************************************
   Create interface for variable OxC_bAcvReqMonItrsv
  **********************************************************************************/

#define vidSET_VALUE_OxC_bAcvReqMonItrsv(value)                                  Rte_Write_P_OxC_bAcvReqMonItrsv_OxC_bAcvReqMonItrsv(value)
#define vidGET_VALUE_OxC_bAcvReqMonItrsv(variable)                               Rte_Read_R_OxC_bAcvReqMonItrsv_OxC_bAcvReqMonItrsv(&variable)

/**********************************************************************************
   Create interface for variable OxC_bMonEnaORngIntr
  **********************************************************************************/

#define vidSET_VALUE_OxC_bMonEnaORngIntr(value)
#define vidGET_VALUE_OxC_bMonEnaORngIntr(variable)                               Rte_Read_R_OxC_bMonEnaORngIntr_OxC_bMonEnaORngIntr(&variable)

/**********************************************************************************
   Create interface for variable OxC_bMonEndORngIntr
  **********************************************************************************/

#define vidSET_VALUE_OxC_bMonEndORngIntr(value)
#define vidGET_VALUE_OxC_bMonEndORngIntr(variable)                               Rte_Read_R_OxC_bMonEndORngIntr_OxC_bMonEndORngIntr(&variable)

/**********************************************************************************
   Create interface for variable OxC_bMonORngIntrAcvCdn
  **********************************************************************************/

#define vidSET_VALUE_OxC_bMonORngIntrAcvCdn(value)
#define vidGET_VALUE_OxC_bMonORngIntrAcvCdn(variable)                            Rte_Read_R_OxC_bMonORngIntrAcvCdn_OxC_bMonORngIntrAcvCdn(&variable)

/**********************************************************************************
   Create interface for variable OxC_bMonReqORngIntr
  **********************************************************************************/

#define vidSET_VALUE_OxC_bMonReqORngIntr(value)
#define vidGET_VALUE_OxC_bMonReqORngIntr(variable)                               Rte_Read_R_OxC_bMonReqORngIntr_OxC_bMonReqORngIntr(&variable)

/**********************************************************************************
   Create interface for variable OxC_bMonRunORngIntr
  **********************************************************************************/

#define vidSET_VALUE_OxC_bMonRunORngIntr(value)
#define vidGET_VALUE_OxC_bMonRunORngIntr(variable)                               Rte_Read_R_OxC_bMonRunORngIntr_OxC_bMonRunORngIntr(&variable)

/**********************************************************************************
   Create interface for variable OxC_bOptmEfcldc_tOxCEstim
  **********************************************************************************/

#define vidSET_VALUE_OxC_bOptmEfcldc_tOxCEstim(value)                            Rte_Write_P_OxC_bOptmEfcldc_tOxCEstim_OxC_bOptmEfcldc_tOxCEstim(value)
#define vidGET_VALUE_OxC_bOptmEfcldc_tOxCEstim(variable)                         Rte_Read_R_OxC_bOptmEfcldc_tOxCEstim_OxC_bOptmEfcldc_tOxCEstim(&variable)

/**********************************************************************************
   Create interface for variable OxC_bRlamAdaptFrz
  **********************************************************************************/

#define vidSET_VALUE_OxC_bRlamAdaptFrz(value)                                    Rte_Write_P_OxC_bRlamAdaptFrz_OxC_bRlamAdaptFrz(value)
#define vidGET_VALUE_OxC_bRlamAdaptFrz(variable)                                 Rte_Read_R_OxC_bRlamAdaptFrz_OxC_bRlamAdaptFrz(&variable)

/**********************************************************************************
   Create interface for variable OxC_bRlamAdpReq
  **********************************************************************************/

#define vidSET_VALUE_OxC_bRlamAdpReq(value)
#define vidGET_VALUE_OxC_bRlamAdpReq(variable)                                   Rte_Read_R_OxC_bRlamAdpReq_OxC_bRlamAdpReq(&variable)

/**********************************************************************************
   Create interface for variable OxC_mO2StgMvEstim
  **********************************************************************************/

#define vidSET_VALUE_OxC_mO2StgMvEstim(value)
#define vidGET_VALUE_OxC_mO2StgMvEstim(variable)                                 Rte_Read_R_OxC_mO2StgMvEstim_OxC_mO2StgMvEstim(&variable)

/**********************************************************************************
   Create interface for variable OxC_rMixtReqMonIntr
  **********************************************************************************/

#define vidSET_VALUE_OxC_rMixtReqMonIntr(value)
#define vidGET_VALUE_OxC_rMixtReqMonIntr(variable)                               Rte_Read_R_OxC_rMixtReqMonIntr_OxC_rMixtReqMonIntr(&variable)

/**********************************************************************************
   Create interface for variable OxC_rMixtReqMonItrsv
  **********************************************************************************/

#define vidSET_VALUE_OxC_rMixtReqMonItrsv(value)                                 Rte_Write_P_OxC_rMixtReqMonItrsv_OxC_rMixtReqMonItrsv(value)
#define vidGET_VALUE_OxC_rMixtReqMonItrsv(variable)                              Rte_Read_R_OxC_rMixtReqMonItrsv_OxC_rMixtReqMonItrsv(&variable)

/**********************************************************************************
   Create interface for variable PFuCtl_NrProfCmd
  **********************************************************************************/

#define vidSET_VALUE_PFuCtl_NrProfCmd(value)                                     Rte_Write_P_PFuCtl_NrProfCmd_PFuCtl_NrProfCmd(value)
#define vidGET_VALUE_PFuCtl_NrProfCmd(variable)                                  Rte_Read_R_PFuCtl_NrProfCmd_PFuCtl_NrProfCmd(&variable)

/**********************************************************************************
   Create interface for variable PFuCtl_agPmpCmdReq
  **********************************************************************************/

#define vidSET_VALUE_PFuCtl_agPmpCmdReq(value)                                   Rte_Write_P_PFuCtl_agPmpCmdReq_PFuCtl_agPmpCmdReq(value)
#define vidGET_VALUE_PFuCtl_agPmpCmdReq(variable)                                Rte_Read_R_PFuCtl_agPmpCmdReq_PFuCtl_agPmpCmdReq(&variable)

/**********************************************************************************
   Create interface for variable PFuCtl_bAcvCmdContnsReq
  **********************************************************************************/

#define vidSET_VALUE_PFuCtl_bAcvCmdContnsReq(value)                              Rte_Write_P_PFuCtl_bAcvCmdContnsReq_PFuCtl_bAcvCmdContnsReq(value)
#define vidGET_VALUE_PFuCtl_bAcvCmdContnsReq(variable)                           Rte_Read_R_PFuCtl_bAcvCmdContnsReq_PFuCtl_bAcvCmdContnsReq(&variable)

/**********************************************************************************
   Create interface for variable PFuCtl_tiPeakDurnCmd
  **********************************************************************************/

#define vidSET_VALUE_PFuCtl_tiPeakDurnCmd(value)                                 Rte_Write_P_PFuCtl_tiPeakDurnCmd_PFuCtl_tiPeakDurnCmd(value)
#define vidGET_VALUE_PFuCtl_tiPeakDurnCmd(variable)                              Rte_Read_R_PFuCtl_tiPeakDurnCmd_PFuCtl_tiPeakDurnCmd(&variable)

/**********************************************************************************
   Create interface for variable PFuCtl_tiPmpCmdDecelGap
  **********************************************************************************/

#define vidSET_VALUE_PFuCtl_tiPmpCmdDecelGap(value)                              Rte_Write_P_PFuCtl_tiPmpCmdDecelGap_PFuCtl_tiPmpCmdDecelGap(value)
#define vidGET_VALUE_PFuCtl_tiPmpCmdDecelGap(variable)                           Rte_Read_R_PFuCtl_tiPmpCmdDecelGap_PFuCtl_tiPmpCmdDecelGap(&variable)

/**********************************************************************************
   Create interface for variable PFuCtl_tiPmpCmdDecelReq
  **********************************************************************************/

#define vidSET_VALUE_PFuCtl_tiPmpCmdDecelReq(value)                              Rte_Write_P_PFuCtl_tiPmpCmdDecelReq_PFuCtl_tiPmpCmdDecelReq(value)
#define vidGET_VALUE_PFuCtl_tiPmpCmdDecelReq(variable)                           Rte_Read_R_PFuCtl_tiPmpCmdDecelReq_PFuCtl_tiPmpCmdDecelReq(&variable)

/**********************************************************************************
   Create interface for variable PFuCtl_tiPmpCmdReq
  **********************************************************************************/

#define vidSET_VALUE_PFuCtl_tiPmpCmdReq(value)                                   Rte_Write_P_PFuCtl_tiPmpCmdReq_PFuCtl_tiPmpCmdReq(value)
#define vidGET_VALUE_PFuCtl_tiPmpCmdReq(variable)                                Rte_Read_R_PFuCtl_tiPmpCmdReq_PFuCtl_tiPmpCmdReq(&variable)

/**********************************************************************************
   Create interface for variable PhyMSI_tTrbCaseEstim
  **********************************************************************************/

#define vidSET_VALUE_PhyMSI_tTrbCaseEstim(value)
#define vidGET_VALUE_PhyMSI_tTrbCaseEstim(variable)                              Rte_Read_R_PhyMSI_tTrbCaseEstim_PhyMSI_tTrbCaseEstim(&variable)

/**********************************************************************************
   Create interface for variable PhyM_tTrbCaseEstim
  **********************************************************************************/

#define vidSET_VALUE_PhyM_tTrbCaseEstim(value)                                   Rte_Write_P_PhyM_tTrbCaseEstim_PhyM_tTrbCaseEstim(value)
#define vidGET_VALUE_PhyM_tTrbCaseEstim(variable)                                Rte_Read_R_PhyM_tTrbCaseEstim_PhyM_tTrbCaseEstim(&variable)

/**********************************************************************************
   Create interface for variable PredEs_agEs
  **********************************************************************************/

#define vidSET_VALUE_PredEs_agEs(value)                                          Rte_Write_P_PredEs_agEs_PredEs_agEs(value)
#define vidGET_VALUE_PredEs_agEs(variable)                                       Rte_Read_R_PredEs_agEs_PredEs_agEs(&variable)

/**********************************************************************************
   Create interface for variable PredEs_agUncrtEs
  **********************************************************************************/

#define vidSET_VALUE_PredEs_agUncrtEs(value)                                     Rte_Write_P_PredEs_agUncrtEs_PredEs_agUncrtEs(value)
#define vidGET_VALUE_PredEs_agUncrtEs(variable)                                  Rte_Read_R_PredEs_agUncrtEs_PredEs_agUncrtEs(&variable)

/**********************************************************************************
   Create interface for variable PredEs_bDetSlowN
  **********************************************************************************/

#define vidSET_VALUE_PredEs_bDetSlowN(value)                                     Rte_Write_P_PredEs_bDetSlowN_PredEs_bDetSlowN(value)
#define vidGET_VALUE_PredEs_bDetSlowN(variable)                                  Rte_Read_R_PredEs_bDetSlowN_PredEs_bDetSlowN(&variable)

/**********************************************************************************
   Create interface for variable PredEs_bVldFastN
  **********************************************************************************/

#define vidSET_VALUE_PredEs_bVldFastN(value)                                     Rte_Write_P_PredEs_bVldFastN_PredEs_bVldFastN(value)
#define vidGET_VALUE_PredEs_bVldFastN(variable)                                  Rte_Read_R_PredEs_bVldFastN_PredEs_bVldFastN(&variable)

/**********************************************************************************
   Create interface for variable PredEs_nFast
  **********************************************************************************/

#define vidSET_VALUE_PredEs_nFast(value)                                         Rte_Write_P_PredEs_nFast_PredEs_nFast(value)
#define vidGET_VALUE_PredEs_nFast(variable)                                      Rte_Read_R_PredEs_nFast_PredEs_nFast(&variable)

/**********************************************************************************
   Create interface for variable Presence_bva_pt_dur
  **********************************************************************************/

#define vidSET_VALUE_Presence_bva_pt_dur(value)                                  Rte_Write_P_Presence_bva_pt_dur_Presence_bva_pt_dur(value)
#define vidGET_VALUE_Presence_bva_pt_dur(variable)                               Rte_Read_R_Presence_bva_pt_dur_Presence_bva_pt_dur(&variable)

/**********************************************************************************
   Create interface for variable Presence_bvmp_pt_dur
  **********************************************************************************/

#define vidSET_VALUE_Presence_bvmp_pt_dur(value)                                 Rte_Write_P_Presence_bvmp_pt_dur_Presence_bvmp_pt_dur(value)
#define vidGET_VALUE_Presence_bvmp_pt_dur(variable)                              Rte_Read_R_Presence_bvmp_pt_dur_Presence_bvmp_pt_dur(&variable)

/**********************************************************************************
   Create interface for variable Pwr_bAcvDMTRAcq
  **********************************************************************************/

#define vidSET_VALUE_Pwr_bAcvDMTRAcq(value)                                      Rte_Write_P_Pwr_bAcvDMTRAcq_Pwr_bAcvDMTRAcq(value)
#define vidGET_VALUE_Pwr_bAcvDMTRAcq(variable)                                   Rte_Read_R_Pwr_bAcvDMTRAcq_Pwr_bAcvDMTRAcq(&variable)

/**********************************************************************************
   Create interface for variable RFuDet_bRstAdp
  **********************************************************************************/

#define vidSET_VALUE_RFuDet_bRstAdp(value)                                       Rte_Write_P_RFuDet_bRstAdp_RFuDet_bRstAdp(value)
#define vidGET_VALUE_RFuDet_bRstAdp(variable)                                    Rte_Read_R_RFuDet_bRstAdp_RFuDet_bRstAdp(&variable)

/**********************************************************************************
   Create interface for variable Regime_moteur
  **********************************************************************************/

#define vidSET_VALUE_Regime_moteur(value)                                        Rte_Write_P_Regime_moteur_Regime_moteur(value)
#define vidGET_VALUE_Regime_moteur(variable)                                     Rte_Read_R_Regime_moteur_Regime_moteur(&variable)

/**********************************************************************************
   Create interface for variable Regime_moteur_32
  **********************************************************************************/

#define vidSET_VALUE_Regime_moteur_32(value)                                     Rte_Write_P_Regime_moteur_32_Regime_moteur_32(value)
#define vidGET_VALUE_Regime_moteur_32(variable)                                  Rte_Read_R_Regime_moteur_32_Regime_moteur_32(&variable)

/**********************************************************************************
   Create interface for variable SecondAcqui_uEngOilLvl
  **********************************************************************************/

#define vidSET_VALUE_SecondAcqui_uEngOilLvl(value)
#define vidGET_VALUE_SecondAcqui_uEngOilLvl(variable)                            Rte_Read_R_SecondAcqui_uEngOilLvl_SecondAcqui_uEngOilLvl(&variable)

/**********************************************************************************
   Create interface for variable SenAct_tIGBTAcq
  **********************************************************************************/

#define vidSET_VALUE_SenAct_tIGBTAcq(value)                                      Rte_Write_P_SenAct_tIGBTAcq_SenAct_tIGBTAcq(value)
#define vidGET_VALUE_SenAct_tIGBTAcq(variable)                                   Rte_Read_R_SenAct_tIGBTAcq_SenAct_tIGBTAcq(&variable)

/**********************************************************************************
   Create interface for variable SenAct_utECUMes
  **********************************************************************************/

#define vidSET_VALUE_SenAct_utECUMes(value)
#define vidGET_VALUE_SenAct_utECUMes(variable)                                   Rte_Read_R_SenAct_utECUMes_SenAct_utECUMes(&variable)

/**********************************************************************************
   Create interface for variable SenAct_utIGBTMes
  **********************************************************************************/

#define vidSET_VALUE_SenAct_utIGBTMes(value)
#define vidGET_VALUE_SenAct_utIGBTMes(variable)                                  Rte_Read_R_SenAct_utIGBTMes_SenAct_utIGBTMes(&variable)

/**********************************************************************************
   Create interface for variable SftyMgt_bDeacIrvVSReg
  **********************************************************************************/

#define vidSET_VALUE_SftyMgt_bDeacIrvVSReg(value)                                Rte_Write_P_SftyMgt_bDeacIrvVSReg_SftyMgt_bDeacIrvVSReg(value)
#define vidGET_VALUE_SftyMgt_bDeacIrvVSReg(variable)                             Rte_Read_R_SftyMgt_bDeacIrvVSReg_SftyMgt_bDeacIrvVSReg(&variable)

/**********************************************************************************
   Create interface for variable SftyMgt_bDgoIrvEngStop
  **********************************************************************************/

#define vidSET_VALUE_SftyMgt_bDgoIrvEngStop(value)                               Rte_Write_P_SftyMgt_bDgoIrvEngStop_SftyMgt_bDgoIrvEngStop(value)
#define vidGET_VALUE_SftyMgt_bDgoIrvEngStop(variable)                            Rte_Read_R_SftyMgt_bDgoIrvEngStop_SftyMgt_bDgoIrvEngStop(&variable)

/**********************************************************************************
   Create interface for variable Sfty_bInhDrvTraSfty
  **********************************************************************************/

#define vidSET_VALUE_Sfty_bInhDrvTraSfty(value)                                  Rte_Write_P_Sfty_bInhDrvTraSfty_Sfty_bInhDrvTraSfty(value)
#define vidGET_VALUE_Sfty_bInhDrvTraSfty(variable)                               Rte_Read_R_Sfty_bInhDrvTraSfty_Sfty_bInhDrvTraSfty(&variable)

/**********************************************************************************
   Create interface for variable Sfty_bInhEngStopSTTReq
  **********************************************************************************/

#define vidSET_VALUE_Sfty_bInhEngStopSTTReq(value)                               Rte_Write_P_Sfty_bInhEngStopSTTReq_Sfty_bInhEngStopSTTReq(value)
#define vidGET_VALUE_Sfty_bInhEngStopSTTReq(variable)                            Rte_Read_R_Sfty_bInhEngStopSTTReq_Sfty_bInhEngStopSTTReq(&variable)

/**********************************************************************************
   Create interface for variable ShdFlap_stPosn
  **********************************************************************************/

#define vidSET_VALUE_ShdFlap_stPosn(value)                                       Rte_Write_P_ShdFlap_stPosn_ShdFlap_stPosn(value)
#define vidGET_VALUE_ShdFlap_stPosn(variable)                                    Rte_Read_R_ShdFlap_stPosn_ShdFlap_stPosn(&variable)

/**********************************************************************************
   Create interface for variable ShwRm_bAcvFSF
  **********************************************************************************/

#define vidSET_VALUE_ShwRm_bAcvFSF(value)                                        Rte_Write_P_ShwRm_bAcvFSF_ShwRm_bAcvFSF(value)
#define vidGET_VALUE_ShwRm_bAcvFSF(variable)                                     Rte_Read_R_ShwRm_bAcvFSF_ShwRm_bAcvFSF(&variable)

/**********************************************************************************
   Create interface for variable Sonde_riche_amont
  **********************************************************************************/

#define vidSET_VALUE_Sonde_riche_amont(value)                                    Rte_Write_P_Sonde_riche_amont_Sonde_riche_amont(value)
#define vidGET_VALUE_Sonde_riche_amont(variable)                                 Rte_Read_R_Sonde_riche_amont_Sonde_riche_amont(&variable)

/**********************************************************************************
   Create interface for variable Sonde_riche_aval
  **********************************************************************************/

#define vidSET_VALUE_Sonde_riche_aval(value)                                     Rte_Write_P_Sonde_riche_aval_Sonde_riche_aval(value)
#define vidGET_VALUE_Sonde_riche_aval(variable)                                  Rte_Read_R_Sonde_riche_aval_Sonde_riche_aval(&variable)

/**********************************************************************************
   Create interface for variable Srv_stActrTstStatus
  **********************************************************************************/

#define vidSET_VALUE_Srv_stActrTstStatus(value)                                  Rte_Write_P_Srv_stActrTstStatus_Srv_stActrTstStatus(value)
#define vidGET_VALUE_Srv_stActrTstStatus(variable)                               Rte_Read_R_Srv_stActrTstStatus_Srv_stActrTstStatus(&variable)

/**********************************************************************************
   Create interface for variable StaCtl_bStaAuth
  **********************************************************************************/

#define vidSET_VALUE_StaCtl_bStaAuth(value)
#define vidGET_VALUE_StaCtl_bStaAuth(variable)                                   Rte_Read_R_StaCtl_bStaAuth_StaCtl_bStaAuth(&variable)

/**********************************************************************************
   Create interface for variable StaCtl_bStaProt
  **********************************************************************************/

#define vidSET_VALUE_StaCtl_bStaProt(value)
#define vidGET_VALUE_StaCtl_bStaProt(variable)                                   Rte_Read_R_StaCtl_bStaProt_StaCtl_bStaProt(&variable)

/**********************************************************************************
   Create interface for variable StaCtl_bStaRawAuth
  **********************************************************************************/

#define vidSET_VALUE_StaCtl_bStaRawAuth(value)
#define vidGET_VALUE_StaCtl_bStaRawAuth(variable)                                Rte_Read_R_StaCtl_bStaRawAuth_StaCtl_bStaRawAuth(&variable)

/**********************************************************************************
   Create interface for variable StaCtl_bStaStopReq
  **********************************************************************************/

#define vidSET_VALUE_StaCtl_bStaStopReq(value)
#define vidGET_VALUE_StaCtl_bStaStopReq(variable)                                Rte_Read_R_StaCtl_bStaStopReq_StaCtl_bStaStopReq(&variable)

/**********************************************************************************
   Create interface for variable StaCtl_stStaAuth
  **********************************************************************************/

#define vidSET_VALUE_StaCtl_stStaAuth(value)
#define vidGET_VALUE_StaCtl_stStaAuth(variable)                                  Rte_Read_R_StaCtl_stStaAuth_StaCtl_stStaAuth(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_bDftElCmd
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_bDftElCmd(value)
#define vidGET_VALUE_StaRstrtMgt_bDftElCmd(variable)                             Rte_Read_R_StaRstrtMgt_bDftElCmd_StaRstrtMgt_bDftElCmd(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_bInfoCplReq
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_bInfoCplReq(value)
#define vidGET_VALUE_StaRstrtMgt_bInfoCplReq(variable)                           Rte_Read_R_StaRstrtMgt_bInfoCplReq_StaRstrtMgt_bInfoCplReq(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_bInfoCplSt
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_bInfoCplSt(value)
#define vidGET_VALUE_StaRstrtMgt_bInfoCplSt(variable)                            Rte_Read_R_StaRstrtMgt_bInfoCplSt_StaRstrtMgt_bInfoCplSt(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_bInfoStaRun
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_bInfoStaRun(value)
#define vidGET_VALUE_StaRstrtMgt_bInfoStaRun(variable)                           Rte_Read_R_StaRstrtMgt_bInfoStaRun_StaRstrtMgt_bInfoStaRun(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_bRstrtProt10
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_bRstrtProt10(value)
#define vidGET_VALUE_StaRstrtMgt_bRstrtProt10(variable)                          Rte_Read_R_StaRstrtMgt_bRstrtProt10_StaRstrtMgt_bRstrtProt10(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_bRstrtProt4
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_bRstrtProt4(value)
#define vidGET_VALUE_StaRstrtMgt_bRstrtProt4(variable)                           Rte_Read_R_StaRstrtMgt_bRstrtProt4_StaRstrtMgt_bRstrtProt4(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_bStaReq
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_bStaReq(value)
#define vidGET_VALUE_StaRstrtMgt_bStaReq(variable)                               Rte_Read_R_StaRstrtMgt_bStaReq_StaRstrtMgt_bStaReq(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_nStaEgdHiThd
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_nStaEgdHiThd(value)
#define vidGET_VALUE_StaRstrtMgt_nStaEgdHiThd(variable)                          Rte_Read_R_StaRstrtMgt_nStaEgdHiThd_StaRstrtMgt_nStaEgdHiThd(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_nStaEgdLoThd
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_nStaEgdLoThd(value)
#define vidGET_VALUE_StaRstrtMgt_nStaEgdLoThd(variable)                          Rte_Read_R_StaRstrtMgt_nStaEgdLoThd_StaRstrtMgt_nStaEgdLoThd(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_stStaRstrtFbCmd
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_stStaRstrtFbCmd(value)
#define vidGET_VALUE_StaRstrtMgt_stStaRstrtFbCmd(variable)                       Rte_Read_R_StaRstrtMgt_stStaRstrtFbCmd_StaRstrtMgt_stStaRstrtFbCmd(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_tiStaEgdHiThd
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_tiStaEgdHiThd(value)
#define vidGET_VALUE_StaRstrtMgt_tiStaEgdHiThd(variable)                         Rte_Read_R_StaRstrtMgt_tiStaEgdHiThd_StaRstrtMgt_tiStaEgdHiThd(&variable)

/**********************************************************************************
   Create interface for variable StaRstrtMgt_tiStaEgdLoThd
  **********************************************************************************/

#define vidSET_VALUE_StaRstrtMgt_tiStaEgdLoThd(value)
#define vidGET_VALUE_StaRstrtMgt_tiStaEgdLoThd(variable)                         Rte_Read_R_StaRstrtMgt_tiStaEgdLoThd_StaRstrtMgt_tiStaEgdLoThd(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_bPwrAcvReq
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_bPwrAcvReq(value)
#define vidGET_VALUE_StaStrtMgt_bPwrAcvReq(variable)                             Rte_Read_R_StaStrtMgt_bPwrAcvReq_StaStrtMgt_bPwrAcvReq(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_bStaReq
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_bStaReq(value)
#define vidGET_VALUE_StaStrtMgt_bStaReq(variable)                                Rte_Read_R_StaStrtMgt_bStaReq_StaStrtMgt_bStaReq(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_bStrtProt10
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_bStrtProt10(value)
#define vidGET_VALUE_StaStrtMgt_bStrtProt10(variable)                            Rte_Read_R_StaStrtMgt_bStrtProt10_StaStrtMgt_bStrtProt10(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_ctStaAcv
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_ctStaAcv(value)
#define vidGET_VALUE_StaStrtMgt_ctStaAcv(variable)                               Rte_Read_R_StaStrtMgt_ctStaAcv_StaStrtMgt_ctStaAcv(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_ctStaRstrtAcv
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_ctStaRstrtAcv(value)
#define vidGET_VALUE_StaStrtMgt_ctStaRstrtAcv(variable)                          Rte_Read_R_StaStrtMgt_ctStaRstrtAcv_StaStrtMgt_ctStaRstrtAcv(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_ctStaStrtAcv
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_ctStaStrtAcv(value)
#define vidGET_VALUE_StaStrtMgt_ctStaStrtAcv(variable)                           Rte_Read_R_StaStrtMgt_ctStaStrtAcv_StaStrtMgt_ctStaStrtAcv(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_stStaFbCmd
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_stStaFbCmd(value)
#define vidGET_VALUE_StaStrtMgt_stStaFbCmd(variable)                             Rte_Read_R_StaStrtMgt_stStaFbCmd_StaStrtMgt_stStaFbCmd(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_stStaStrtFbCmd
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_stStaStrtFbCmd(value)
#define vidGET_VALUE_StaStrtMgt_stStaStrtFbCmd(variable)                         Rte_Read_R_StaStrtMgt_stStaStrtFbCmd_StaStrtMgt_stStaStrtFbCmd(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_tiMaxAcv
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_tiMaxAcv(value)
#define vidGET_VALUE_StaStrtMgt_tiMaxAcv(variable)                               Rte_Read_R_StaStrtMgt_tiMaxAcv_StaStrtMgt_tiMaxAcv(&variable)

/**********************************************************************************
   Create interface for variable StaStrtMgt_tiStaAcvCnt
  **********************************************************************************/

#define vidSET_VALUE_StaStrtMgt_tiStaAcvCnt(value)
#define vidGET_VALUE_StaStrtMgt_tiStaAcvCnt(variable)                            Rte_Read_R_StaStrtMgt_tiStaAcvCnt_StaStrtMgt_tiStaAcvCnt(&variable)

/**********************************************************************************
   Create interface for variable Stg_agStrWhl
  **********************************************************************************/

#define vidSET_VALUE_Stg_agStrWhl(value)                                         Rte_Write_P_Stg_agStrWhl_Stg_agStrWhl(value)
#define vidGET_VALUE_Stg_agStrWhl(variable)                                      Rte_Read_R_Stg_agStrWhl_Stg_agStrWhl(&variable)

/**********************************************************************************
   Create interface for variable Stg_agvStrWhl
  **********************************************************************************/

#define vidSET_VALUE_Stg_agvStrWhl(value)                                        Rte_Write_P_Stg_agvStrWhl_Stg_agvStrWhl(value)
#define vidGET_VALUE_Stg_agvStrWhl(variable)                                     Rte_Read_R_Stg_agvStrWhl_Stg_agvStrWhl(&variable)

/**********************************************************************************
   Create interface for variable Stg_bStgPmpThdMes
  **********************************************************************************/

#define vidSET_VALUE_Stg_bStgPmpThdMes(value)                                    Rte_Write_P_Stg_bStgPmpThdMes_Stg_bStgPmpThdMes(value)
#define vidGET_VALUE_Stg_bStgPmpThdMes(variable)                                 Rte_Read_R_Stg_bStgPmpThdMes_Stg_bStgPmpThdMes(&variable)

/**********************************************************************************
   Create interface for variable Stg_pStgPmpLnrMes
  **********************************************************************************/

#define vidSET_VALUE_Stg_pStgPmpLnrMes(value)                                    Rte_Write_P_Stg_pStgPmpLnrMes_Stg_pStgPmpLnrMes(value)
#define vidGET_VALUE_Stg_pStgPmpLnrMes(variable)                                 Rte_Read_R_Stg_pStgPmpLnrMes_Stg_pStgPmpLnrMes(&variable)

/**********************************************************************************
   Create interface for variable Sync_agEng
  **********************************************************************************/

#define vidSET_VALUE_Sync_agEng(value)                                           Rte_Write_P_Sync_agEng_Sync_agEng(value)
#define vidGET_VALUE_Sync_agEng(variable)                                        Rte_Read_R_Sync_agEng_Sync_agEng(&variable)

/**********************************************************************************
   Create interface for variable Sync_bCkAcqVld
  **********************************************************************************/

#define vidSET_VALUE_Sync_bCkAcqVld(value)
#define vidGET_VALUE_Sync_bCkAcqVld(variable)                                    Rte_Read_R_Sync_bCkAcqVld_Sync_bCkAcqVld(&variable)

/**********************************************************************************
   Create interface for variable Sync_bDft_HiToothCoh_CkSts
  **********************************************************************************/

#define vidSET_VALUE_Sync_bDft_HiToothCoh_CkSts(value)
#define vidGET_VALUE_Sync_bDft_HiToothCoh_CkSts(variable)                        Rte_Read_R_Sync_bDft_HiToothCoh_CkSts_Sync_bDft_HiToothCoh_CkSts(&variable)

/**********************************************************************************
   Create interface for variable Sync_bDft_NoGap_CkSts
  **********************************************************************************/

#define vidSET_VALUE_Sync_bDft_NoGap_CkSts(value)
#define vidGET_VALUE_Sync_bDft_NoGap_CkSts(variable)                             Rte_Read_R_Sync_bDft_NoGap_CkSts_Sync_bDft_NoGap_CkSts(&variable)

/**********************************************************************************
   Create interface for variable Sync_bDft_ToothCoh_CkSts
  **********************************************************************************/

#define vidSET_VALUE_Sync_bDft_ToothCoh_CkSts(value)
#define vidGET_VALUE_Sync_bDft_ToothCoh_CkSts(variable)                          Rte_Read_R_Sync_bDft_ToothCoh_CkSts_Sync_bDft_ToothCoh_CkSts(&variable)

/**********************************************************************************
   Create interface for variable Sync_bDgoCkSig
  **********************************************************************************/

#define vidSET_VALUE_Sync_bDgoCkSig(value)                                       Rte_Write_P_Sync_bDgoCkSig_Sync_bDgoCkSig(value)
#define vidGET_VALUE_Sync_bDgoCkSig(variable)                                    Rte_Read_R_Sync_bDgoCkSig_Sync_bDgoCkSig(&variable)

/**********************************************************************************
   Create interface for variable Sync_bEna_HiToothCoh_CkSts
  **********************************************************************************/

#define vidSET_VALUE_Sync_bEna_HiToothCoh_CkSts(value)
#define vidGET_VALUE_Sync_bEna_HiToothCoh_CkSts(variable)                        Rte_Read_R_Sync_bEna_HiToothCoh_CkSts_Sync_bEna_HiToothCoh_CkSts(&variable)

/**********************************************************************************
   Create interface for variable Sync_bEna_NoGap_CkSts
  **********************************************************************************/

#define vidSET_VALUE_Sync_bEna_NoGap_CkSts(value)
#define vidGET_VALUE_Sync_bEna_NoGap_CkSts(variable)                             Rte_Read_R_Sync_bEna_NoGap_CkSts_Sync_bEna_NoGap_CkSts(&variable)

/**********************************************************************************
   Create interface for variable Sync_bEna_ToothCoh_CkSts
  **********************************************************************************/

#define vidSET_VALUE_Sync_bEna_ToothCoh_CkSts(value)
#define vidGET_VALUE_Sync_bEna_ToothCoh_CkSts(variable)                          Rte_Read_R_Sync_bEna_ToothCoh_CkSts_Sync_bEna_ToothCoh_CkSts(&variable)

/**********************************************************************************
   Create interface for variable Sync_bEngSyncAccu
  **********************************************************************************/

#define vidSET_VALUE_Sync_bEngSyncAccu(value)                                    Rte_Write_P_Sync_bEngSyncAccu_Sync_bEngSyncAccu(value)
#define vidGET_VALUE_Sync_bEngSyncAccu(variable)                                 Rte_Read_R_Sync_bEngSyncAccu_Sync_bEngSyncAccu(&variable)

/**********************************************************************************
   Create interface for variable TPM_bAcvRichThermoProt
  **********************************************************************************/

#define vidSET_VALUE_TPM_bAcvRichThermoProt(value)
#define vidGET_VALUE_TPM_bAcvRichThermoProt(variable)                            Rte_Read_R_TPM_bAcvRichThermoProt_TPM_bAcvRichThermoProt(&variable)

/**********************************************************************************
   Create interface for variable TPM_bExThermoProt
  **********************************************************************************/

#define vidSET_VALUE_TPM_bExThermoProt(value)
#define vidGET_VALUE_TPM_bExThermoProt(variable)                                 Rte_Read_R_TPM_bExThermoProt_TPM_bExThermoProt(&variable)

/**********************************************************************************
   Create interface for variable TPM_bInhInjCutOff
  **********************************************************************************/

#define vidSET_VALUE_TPM_bInhInjCutOff(value)
#define vidGET_VALUE_TPM_bInhInjCutOff(variable)                                 Rte_Read_R_TPM_bInhInjCutOff_TPM_bInhInjCutOff(&variable)

/**********************************************************************************
   Create interface for variable TPM_bInhInjSelCutOff
  **********************************************************************************/

#define vidSET_VALUE_TPM_bInhInjSelCutOff(value)
#define vidGET_VALUE_TPM_bInhInjSelCutOff(variable)                              Rte_Read_R_TPM_bInhInjSelCutOff_TPM_bInhInjSelCutOff(&variable)

/**********************************************************************************
   Create interface for variable TPM_mfAirScvLimMaxCor
  **********************************************************************************/

#define vidSET_VALUE_TPM_mfAirScvLimMaxCor(value)
#define vidGET_VALUE_TPM_mfAirScvLimMaxCor(variable)                             Rte_Read_R_TPM_mfAirScvLimMaxCor_TPM_mfAirScvLimMaxCor(&variable)

/**********************************************************************************
   Create interface for variable TPM_tTarAcvThermoProtDev
  **********************************************************************************/

#define vidSET_VALUE_TPM_tTarAcvThermoProtDev(value)
#define vidGET_VALUE_TPM_tTarAcvThermoProtDev(variable)                          Rte_Read_R_TPM_tTarAcvThermoProtDev_TPM_tTarAcvThermoProtDev(&variable)

/**********************************************************************************
   Create interface for variable TWCMgt_bLiOffDone
  **********************************************************************************/

#define vidSET_VALUE_TWCMgt_bLiOffDone(value)                                    Rte_Write_P_TWCMgt_bLiOffDone_TWCMgt_bLiOffDone(value)
#define vidGET_VALUE_TWCMgt_bLiOffDone(variable)                                 Rte_Read_R_TWCMgt_bLiOffDone_TWCMgt_bLiOffDone(&variable)

/**********************************************************************************
   Create interface for variable TWCMgt_stHeatPhaReq
  **********************************************************************************/

#define vidSET_VALUE_TWCMgt_stHeatPhaReq(value)                                  Rte_Write_P_TWCMgt_stHeatPhaReq_TWCMgt_stHeatPhaReq(value)
#define vidGET_VALUE_TWCMgt_stHeatPhaReq(variable)                               Rte_Read_R_TWCMgt_stHeatPhaReq_TWCMgt_stHeatPhaReq(&variable)

/**********************************************************************************
   Create interface for variable TWCMgt_stTrbActPosnReq
  **********************************************************************************/

#define vidSET_VALUE_TWCMgt_stTrbActPosnReq(value)                               Rte_Write_P_TWCMgt_stTrbActPosnReq_TWCMgt_stTrbActPosnReq(value)
#define vidGET_VALUE_TWCMgt_stTrbActPosnReq(variable)                            Rte_Read_R_TWCMgt_stTrbActPosnReq_TWCMgt_stTrbActPosnReq(&variable)

/**********************************************************************************
   Create interface for variable Temperature_air
  **********************************************************************************/

#define vidSET_VALUE_Temperature_air(value)                                      Rte_Write_P_Temperature_air_Temperature_air(value)
#define vidGET_VALUE_Temperature_air(variable)                                   Rte_Read_R_Temperature_air_Temperature_air(&variable)

/**********************************************************************************
   Create interface for variable Temperature_eau
  **********************************************************************************/

#define vidSET_VALUE_Temperature_eau(value)                                      Rte_Write_P_Temperature_eau_Temperature_eau(value)
#define vidGET_VALUE_Temperature_eau(variable)                                   Rte_Read_R_Temperature_eau_Temperature_eau(&variable)

/**********************************************************************************
   Create interface for variable Tension_alimentation_capteur_1
  **********************************************************************************/

#define vidSET_VALUE_Tension_alimentation_capteur_1(value)
#define vidGET_VALUE_Tension_alimentation_capteur_1(variable)                    Rte_Read_R_Tension_alimentation_capteur_1_Tension_alimentation_capteur_1(&variable)

/**********************************************************************************
   Create interface for variable Tension_alimentation_capteur_2
  **********************************************************************************/

#define vidSET_VALUE_Tension_alimentation_capteur_2(value)
#define vidGET_VALUE_Tension_alimentation_capteur_2(variable)                    Rte_Read_R_Tension_alimentation_capteur_2_Tension_alimentation_capteur_2(&variable)

/**********************************************************************************
   Create interface for variable Tension_alimentation_capteur_3
  **********************************************************************************/

#define vidSET_VALUE_Tension_alimentation_capteur_3(value)
#define vidGET_VALUE_Tension_alimentation_capteur_3(variable)                    Rte_Read_R_Tension_alimentation_capteur_3_Tension_alimentation_capteur_3(&variable)

/**********************************************************************************
   Create interface for variable Tension_alimentation_capteur_4
  **********************************************************************************/

#define vidSET_VALUE_Tension_alimentation_capteur_4(value)
#define vidGET_VALUE_Tension_alimentation_capteur_4(variable)                    Rte_Read_R_Tension_alimentation_capteur_4_Tension_alimentation_capteur_4(&variable)

/**********************************************************************************
   Create interface for variable Tension_batterie_filt
  **********************************************************************************/

#define vidSET_VALUE_Tension_batterie_filt(value)                                Rte_Write_P_Tension_batterie_filt_Tension_batterie_filt(value)
#define vidGET_VALUE_Tension_batterie_filt(variable)                             Rte_Read_R_Tension_batterie_filt_Tension_batterie_filt(&variable)

/**********************************************************************************
   Create interface for variable Tension_commande_chauf_seno2ds
  **********************************************************************************/

#define vidSET_VALUE_Tension_commande_chauf_seno2ds(value)
#define vidGET_VALUE_Tension_commande_chauf_seno2ds(variable)                    Rte_Read_R_Tension_commande_chauf_seno2ds_Tension_commande_chauf_seno2ds(&variable)

/**********************************************************************************
   Create interface for variable Tension_commande_chauf_seno2us
  **********************************************************************************/

#define vidSET_VALUE_Tension_commande_chauf_seno2us(value)
#define vidGET_VALUE_Tension_commande_chauf_seno2us(variable)                    Rte_Read_R_Tension_commande_chauf_seno2us_Tension_commande_chauf_seno2us(&variable)

/**********************************************************************************
   Create interface for variable Tension_sonde_aval
  **********************************************************************************/

#define vidSET_VALUE_Tension_sonde_aval(value)                                   Rte_Write_P_Tension_sonde_aval_Tension_sonde_aval(value)
#define vidGET_VALUE_Tension_sonde_aval(variable)                                Rte_Read_R_Tension_sonde_aval_Tension_sonde_aval(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bAdFanReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bAdFanReq(value)
#define vidGET_VALUE_ThMgt_bAdFanReq(variable)                                   Rte_Read_R_ThMgt_bAdFanReq_ThMgt_bAdFanReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bBattFanReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bBattFanReq(value)
#define vidGET_VALUE_ThMgt_bBattFanReq(variable)                                 Rte_Read_R_ThMgt_bBattFanReq_ThMgt_bBattFanReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bECTAftsReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bECTAftsReq(value)
#define vidGET_VALUE_ThMgt_bECTAftsReq(variable)                                 Rte_Read_R_ThMgt_bECTAftsReq_ThMgt_bECTAftsReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bECUFanReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bECUFanReq(value)
#define vidGET_VALUE_ThMgt_bECUFanReq(variable)                                  Rte_Read_R_ThMgt_bECUFanReq_ThMgt_bECUFanReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bEHRHeatReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bEHRHeatReq(value)
#define vidGET_VALUE_ThMgt_bEHRHeatReq(variable)                                 Rte_Read_R_ThMgt_bEHRHeatReq_ThMgt_bEHRHeatReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bEHRWaPmpReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bEHRWaPmpReq(value)
#define vidGET_VALUE_ThMgt_bEHRWaPmpReq(variable)                                Rte_Read_R_ThMgt_bEHRWaPmpReq_ThMgt_bEHRWaPmpReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bEndCtlCoVlv
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bEndCtlCoVlv(value)
#define vidGET_VALUE_ThMgt_bEndCtlCoVlv(variable)                                Rte_Read_R_ThMgt_bEndCtlCoVlv_ThMgt_bEndCtlCoVlv(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bHeatWaPmpReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bHeatWaPmpReq(value)
#define vidGET_VALUE_ThMgt_bHeatWaPmpReq(variable)                               Rte_Read_R_ThMgt_bHeatWaPmpReq_ThMgt_bHeatWaPmpReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bHldPosnCoVlvReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bHldPosnCoVlvReq(value)
#define vidGET_VALUE_ThMgt_bHldPosnCoVlvReq(variable)                            Rte_Read_R_ThMgt_bHldPosnCoVlvReq_ThMgt_bHldPosnCoVlvReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bIncVoltReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bIncVoltReq(value)
#define vidGET_VALUE_ThMgt_bIncVoltReq(variable)                                 Rte_Read_R_ThMgt_bIncVoltReq_ThMgt_bIncVoltReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bMainWaPmpReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bMainWaPmpReq(value)
#define vidGET_VALUE_ThMgt_bMainWaPmpReq(variable)                               Rte_Read_R_ThMgt_bMainWaPmpReq_ThMgt_bMainWaPmpReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bMainWaPmpSt
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bMainWaPmpSt(value)
#define vidGET_VALUE_ThMgt_bMainWaPmpSt(variable)                                Rte_Read_R_ThMgt_bMainWaPmpSt_ThMgt_bMainWaPmpSt(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bPosnFSF
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bPosnFSF(value)
#define vidGET_VALUE_ThMgt_bPosnFSF(variable)                                    Rte_Read_R_ThMgt_bPosnFSF_ThMgt_bPosnFSF(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bPwrHldAdFanReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bPwrHldAdFanReq(value)
#define vidGET_VALUE_ThMgt_bPwrHldAdFanReq(variable)                             Rte_Read_R_ThMgt_bPwrHldAdFanReq_ThMgt_bPwrHldAdFanReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bPwrHldCoVlvReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bPwrHldCoVlvReq(value)
#define vidGET_VALUE_ThMgt_bPwrHldCoVlvReq(variable)                             Rte_Read_R_ThMgt_bPwrHldCoVlvReq_ThMgt_bPwrHldCoVlvReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bPwrHldFSFReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bPwrHldFSFReq(value)
#define vidGET_VALUE_ThMgt_bPwrHldFSFReq(variable)                               Rte_Read_R_ThMgt_bPwrHldFSFReq_ThMgt_bPwrHldFSFReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bPwrHldMainFanReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bPwrHldMainFanReq(value)
#define vidGET_VALUE_ThMgt_bPwrHldMainFanReq(variable)                           Rte_Read_R_ThMgt_bPwrHldMainFanReq_ThMgt_bPwrHldMainFanReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bPwrHldTrbWaPmpReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bPwrHldTrbWaPmpReq(value)
#define vidGET_VALUE_ThMgt_bPwrHldTrbWaPmpReq(variable)                          Rte_Read_R_ThMgt_bPwrHldTrbWaPmpReq_ThMgt_bPwrHldTrbWaPmpReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bRstrtReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bRstrtReq(value)
#define vidGET_VALUE_ThMgt_bRstrtReq(variable)                                   Rte_Read_R_ThMgt_bRstrtReq_ThMgt_bRstrtReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bTCoWarnReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bTCoWarnReq(value)
#define vidGET_VALUE_ThMgt_bTCoWarnReq(variable)                                 Rte_Read_R_ThMgt_bTCoWarnReq_ThMgt_bTCoWarnReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_bTrbWaPmpReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_bTrbWaPmpReq(value)
#define vidGET_VALUE_ThMgt_bTrbWaPmpReq(variable)                                Rte_Read_R_ThMgt_bTrbWaPmpReq_ThMgt_bTrbWaPmpReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_nTarIdlHeatReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_nTarIdlHeatReq(value)
#define vidGET_VALUE_ThMgt_nTarIdlHeatReq(variable)                              Rte_Read_R_ThMgt_nTarIdlHeatReq_ThMgt_nTarIdlHeatReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_rCoHeatReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_rCoHeatReq(value)
#define vidGET_VALUE_ThMgt_rCoHeatReq(variable)                                  Rte_Read_R_ThMgt_rCoHeatReq_ThMgt_rCoHeatReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_rOpBypCoVlvReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_rOpBypCoVlvReq(value)
#define vidGET_VALUE_ThMgt_rOpBypCoVlvReq(variable)                              Rte_Read_R_ThMgt_rOpBypCoVlvReq_ThMgt_rOpBypCoVlvReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_rOpHeatCoVlvReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_rOpHeatCoVlvReq(value)
#define vidGET_VALUE_ThMgt_rOpHeatCoVlvReq(variable)                             Rte_Read_R_ThMgt_rOpHeatCoVlvReq_ThMgt_rOpHeatCoVlvReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_rOpRadCoVlvReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_rOpRadCoVlvReq(value)
#define vidGET_VALUE_ThMgt_rOpRadCoVlvReq(variable)                              Rte_Read_R_ThMgt_rOpRadCoVlvReq_ThMgt_rOpRadCoVlvReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_rPwrECTReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_rPwrECTReq(value)
#define vidGET_VALUE_ThMgt_rPwrECTReq(variable)                                  Rte_Read_R_ThMgt_rPwrECTReq_ThMgt_rPwrECTReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_rSpdFanReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_rSpdFanReq(value)
#define vidGET_VALUE_ThMgt_rSpdFanReq(variable)                                  Rte_Read_R_ThMgt_rSpdFanReq_ThMgt_rSpdFanReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_stPosnCoVlvEstim
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_stPosnCoVlvEstim(value)
#define vidGET_VALUE_ThMgt_stPosnCoVlvEstim(variable)                            Rte_Read_R_ThMgt_stPosnCoVlvEstim_ThMgt_stPosnCoVlvEstim(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_stPosnFSFReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_stPosnFSFReq(value)
#define vidGET_VALUE_ThMgt_stPosnFSFReq(variable)                                Rte_Read_R_ThMgt_stPosnFSFReq_ThMgt_stPosnFSFReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_stSpdCoVlvReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_stSpdCoVlvReq(value)
#define vidGET_VALUE_ThMgt_stSpdCoVlvReq(variable)                               Rte_Read_R_ThMgt_stSpdCoVlvReq_ThMgt_stSpdCoVlvReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_tCoReg
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_tCoReg(value)
#define vidGET_VALUE_ThMgt_tCoReg(variable)                                      Rte_Read_R_ThMgt_tCoReg_ThMgt_tCoReg(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_tECTReq
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_tECTReq(value)
#define vidGET_VALUE_ThMgt_tECTReq(variable)                                     Rte_Read_R_ThMgt_tECTReq_ThMgt_tECTReq(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_tiAcvTrbWaPmpEngStop
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_tiAcvTrbWaPmpEngStop(value)
#define vidGET_VALUE_ThMgt_tiAcvTrbWaPmpEngStop(variable)                        Rte_Read_R_ThMgt_tiAcvTrbWaPmpEngStop_ThMgt_tiAcvTrbWaPmpEngStop(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_tqEfcLimAntiBoilProt
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_tqEfcLimAntiBoilProt(value)
#define vidGET_VALUE_ThMgt_tqEfcLimAntiBoilProt(variable)                        Rte_Read_R_ThMgt_tqEfcLimAntiBoilProt_ThMgt_tqEfcLimAntiBoilProt(&variable)

/**********************************************************************************
   Create interface for variable ThMgt_wThFil
  **********************************************************************************/

#define vidSET_VALUE_ThMgt_wThFil(value)
#define vidGET_VALUE_ThMgt_wThFil(variable)                                      Rte_Read_R_ThMgt_wThFil_ThMgt_wThFil(&variable)

/**********************************************************************************
   Create interface for variable ThrLrn_rOpClsThrBol
  **********************************************************************************/

#define vidSET_VALUE_ThrLrn_rOpClsThrBol(value)                                  Rte_Write_P_ThrLrn_rOpClsThrBol_ThrLrn_rOpClsThrBol(value)
#define vidGET_VALUE_ThrLrn_rOpClsThrBol(variable)                               Rte_Read_R_ThrLrn_rOpClsThrBol_ThrLrn_rOpClsThrBol(&variable)

/**********************************************************************************
   Create interface for variable ThrLrn_rOpSI
  **********************************************************************************/

#define vidSET_VALUE_ThrLrn_rOpSI(value)                                         Rte_Write_P_ThrLrn_rOpSI_ThrLrn_rOpSI(value)
#define vidGET_VALUE_ThrLrn_rOpSI(variable)                                      Rte_Read_R_ThrLrn_rOpSI_ThrLrn_rOpSI(&variable)

/**********************************************************************************
   Create interface for variable ThrSys_rOpThrReq
  **********************************************************************************/

#define vidSET_VALUE_ThrSys_rOpThrReq(value)
#define vidGET_VALUE_ThrSys_rOpThrReq(variable)                                  Rte_Read_R_ThrSys_rOpThrReq_ThrSys_rOpThrReq(&variable)

/**********************************************************************************
   Create interface for variable Thr_bEndTestInh_CpuSfty
  **********************************************************************************/

#define vidSET_VALUE_Thr_bEndTestInh_CpuSfty(value)                              Rte_Write_P_Thr_bEndTestInh_CpuSfty_Thr_bEndTestInh_CpuSfty(value)
#define vidGET_VALUE_Thr_bEndTestInh_CpuSfty(variable)                           Rte_Read_R_Thr_bEndTestInh_CpuSfty_Thr_bEndTestInh_CpuSfty(&variable)

/**********************************************************************************
   Create interface for variable Thr_rOpThrReqMaxThd
  **********************************************************************************/

#define vidSET_VALUE_Thr_rOpThrReqMaxThd(value)                                  Rte_Write_P_Thr_rOpThrReqMaxThd_Thr_rOpThrReqMaxThd(value)
#define vidGET_VALUE_Thr_rOpThrReqMaxThd(variable)                               Rte_Read_R_Thr_rOpThrReqMaxThd_Thr_rOpThrReqMaxThd(&variable)

/**********************************************************************************
   Create interface for variable TqAdp_bInhEngStop
  **********************************************************************************/

#define vidSET_VALUE_TqAdp_bInhEngStop(value)
#define vidGET_VALUE_TqAdp_bInhEngStop(variable)                                 Rte_Read_R_TqAdp_bInhEngStop_TqAdp_bInhEngStop(&variable)

/**********************************************************************************
   Create interface for variable TqAdvMin_bAcvCll
  **********************************************************************************/

#define vidSET_VALUE_TqAdvMin_bAcvCll(value)                                     Rte_Write_P_TqAdvMin_bAcvCll_TqAdvMin_bAcvCll(value)
#define vidGET_VALUE_TqAdvMin_bAcvCll(variable)                                  Rte_Read_R_TqAdvMin_bAcvCll_TqAdvMin_bAcvCll(&variable)

/**********************************************************************************
   Create interface for variable TqAdvMin_tiTranCll
  **********************************************************************************/

#define vidSET_VALUE_TqAdvMin_tiTranCll(value)                                   Rte_Write_P_TqAdvMin_tiTranCll_TqAdvMin_tiTranCll(value)
#define vidGET_VALUE_TqAdvMin_tiTranCll(variable)                                Rte_Read_R_TqAdvMin_tiTranCll_TqAdvMin_tiTranCll(&variable)

/**********************************************************************************
   Create interface for variable TqAdvMin_tqIncCll
  **********************************************************************************/

#define vidSET_VALUE_TqAdvMin_tqIncCll(value)                                    Rte_Write_P_TqAdvMin_tqIncCll_TqAdvMin_tqIncCll(value)
#define vidGET_VALUE_TqAdvMin_tqIncCll(variable)                                 Rte_Read_R_TqAdvMin_tqIncCll_TqAdvMin_tqIncCll(&variable)

/**********************************************************************************
   Create interface for variable TqCha_tqAirTqDecReq
  **********************************************************************************/

#define vidSET_VALUE_TqCha_tqAirTqDecReq(value)                                  Rte_Write_P_TqCha_tqAirTqDecReq_TqCha_tqAirTqDecReq(value)
#define vidGET_VALUE_TqCha_tqAirTqDecReq(variable)                               Rte_Read_R_TqCha_tqAirTqDecReq_TqCha_tqAirTqDecReq(&variable)

/**********************************************************************************
   Create interface for variable TqCha_tqAirTqIncReq
  **********************************************************************************/

#define vidSET_VALUE_TqCha_tqAirTqIncReq(value)                                  Rte_Write_P_TqCha_tqAirTqIncReq_TqCha_tqAirTqIncReq(value)
#define vidGET_VALUE_TqCha_tqAirTqIncReq(variable)                               Rte_Read_R_TqCha_tqAirTqIncReq_TqCha_tqAirTqIncReq(&variable)

/**********************************************************************************
   Create interface for variable TqCll_bAcvCll
  **********************************************************************************/

#define vidSET_VALUE_TqCll_bAcvCll(value)
#define vidGET_VALUE_TqCll_bAcvCll(variable)                                     Rte_Read_R_TqCll_bAcvCll_TqCll_bAcvCll(&variable)

/**********************************************************************************
   Create interface for variable TqCll_bReqCllPtl
  **********************************************************************************/

#define vidSET_VALUE_TqCll_bReqCllPtl(value)
#define vidGET_VALUE_TqCll_bReqCllPtl(variable)                                  Rte_Read_R_TqCll_bReqCllPtl_TqCll_bReqCllPtl(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_bEngStrtReq
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_bEngStrtReq(value)
#define vidGET_VALUE_TqCmp_bEngStrtReq(variable)                                 Rte_Read_R_TqCmp_bEngStrtReq_TqCmp_bEngStrtReq(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_bTAirChk
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_bTAirChk(value)
#define vidGET_VALUE_TqCmp_bTAirChk(variable)                                    Rte_Read_R_TqCmp_bTAirChk_TqCmp_bTAirChk(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tAir
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tAir(value)                                           Rte_Write_P_TqCmp_tAir_TqCmp_tAir(value)
#define vidGET_VALUE_TqCmp_tAir(variable)                                        Rte_Read_R_TqCmp_tAir_TqCmp_tAir(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tAirEstim
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tAirEstim(value)
#define vidGET_VALUE_TqCmp_tAirEstim(variable)                                   Rte_Read_R_TqCmp_tAirEstim_TqCmp_tAirEstim(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tqACLoss
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tqACLoss(value)
#define vidGET_VALUE_TqCmp_tqACLoss(variable)                                    Rte_Read_R_TqCmp_tqACLoss_TqCmp_tqACLoss(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tqAltLoss
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tqAltLoss(value)
#define vidGET_VALUE_TqCmp_tqAltLoss(variable)                                   Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tqAuxLoss
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tqAuxLoss(value)                                      Rte_Write_P_TqCmp_tqAuxLoss_TqCmp_tqAuxLoss(value)
#define vidGET_VALUE_TqCmp_tqAuxLoss(variable)                                   Rte_Read_R_TqCmp_tqAuxLoss_TqCmp_tqAuxLoss(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tqCnvLoss
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tqCnvLoss(value)
#define vidGET_VALUE_TqCmp_tqCnvLoss(variable)                                   Rte_Read_R_TqCmp_tqCnvLoss_TqCmp_tqCnvLoss(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tqStgPmpLoss
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tqStgPmpLoss(value)
#define vidGET_VALUE_TqCmp_tqStgPmpLoss(variable)                                Rte_Read_R_TqCmp_tqStgPmpLoss_TqCmp_tqStgPmpLoss(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tqSumLossCmp
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tqSumLossCmp(value)
#define vidGET_VALUE_TqCmp_tqSumLossCmp(variable)                                Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&variable)

/**********************************************************************************
   Create interface for variable TqCmp_tqSumLossEstim
  **********************************************************************************/

#define vidSET_VALUE_TqCmp_tqSumLossEstim(value)
#define vidGET_VALUE_TqCmp_tqSumLossEstim(variable)                              Rte_Read_R_TqCmp_tqSumLossEstim_TqCmp_tqSumLossEstim(&variable)

/**********************************************************************************
   Create interface for variable TqDem_bAcvNRegTakeOff
  **********************************************************************************/

#define vidSET_VALUE_TqDem_bAcvNRegTakeOff(value)
#define vidGET_VALUE_TqDem_bAcvNRegTakeOff(variable)                             Rte_Read_R_TqDem_bAcvNRegTakeOff_TqDem_bAcvNRegTakeOff(&variable)

/**********************************************************************************
   Create interface for variable TqDem_bModSpt
  **********************************************************************************/

#define vidSET_VALUE_TqDem_bModSpt(value)
#define vidGET_VALUE_TqDem_bModSpt(variable)                                     Rte_Read_R_TqDem_bModSpt_TqDem_bModSpt(&variable)

/**********************************************************************************
   Create interface for variable TqDem_bTqGrdLim
  **********************************************************************************/

#define vidSET_VALUE_TqDem_bTqGrdLim(value)
#define vidGET_VALUE_TqDem_bTqGrdLim(variable)                                   Rte_Read_R_TqDem_bTqGrdLim_TqDem_bTqGrdLim(&variable)

/**********************************************************************************
   Create interface for variable TqDem_nEngReq
  **********************************************************************************/

#define vidSET_VALUE_TqDem_nEngReq(value)
#define vidGET_VALUE_TqDem_nEngReq(variable)                                     Rte_Read_R_TqDem_nEngReq_TqDem_nEngReq(&variable)

/**********************************************************************************
   Create interface for variable TqDem_rAccPSptMod
  **********************************************************************************/

#define vidSET_VALUE_TqDem_rAccPSptMod(value)
#define vidGET_VALUE_TqDem_rAccPSptMod(variable)                                 Rte_Read_R_TqDem_rAccPSptMod_TqDem_rAccPSptMod(&variable)

/**********************************************************************************
   Create interface for variable TqDem_rDrivTakeOff
  **********************************************************************************/

#define vidSET_VALUE_TqDem_rDrivTakeOff(value)
#define vidGET_VALUE_TqDem_rDrivTakeOff(variable)                                Rte_Read_R_TqDem_rDrivTakeOff_TqDem_rDrivTakeOff(&variable)

/**********************************************************************************
   Create interface for variable TqDem_rGearRatAftRng
  **********************************************************************************/

#define vidSET_VALUE_TqDem_rGearRatAftRng(value)
#define vidGET_VALUE_TqDem_rGearRatAftRng(variable)                              Rte_Read_R_TqDem_rGearRatAftRng_TqDem_rGearRatAftRng(&variable)

/**********************************************************************************
   Create interface for variable TqDem_tqCkEfc
  **********************************************************************************/

#define vidSET_VALUE_TqDem_tqCkEfc(value)
#define vidGET_VALUE_TqDem_tqCkEfc(variable)                                     Rte_Read_R_TqDem_tqCkEfc_TqDem_tqCkEfc(&variable)

/**********************************************************************************
   Create interface for variable TqDem_tqCkEfcTrv
  **********************************************************************************/

#define vidSET_VALUE_TqDem_tqCkEfcTrv(value)
#define vidGET_VALUE_TqDem_tqCkEfcTrv(variable)                                  Rte_Read_R_TqDem_tqCkEfcTrv_TqDem_tqCkEfcTrv(&variable)

/**********************************************************************************
   Create interface for variable TqDem_tqCkEfcWoutAntiDB
  **********************************************************************************/

#define vidSET_VALUE_TqDem_tqCkEfcWoutAntiDB(value)
#define vidGET_VALUE_TqDem_tqCkEfcWoutAntiDB(variable)                           Rte_Read_R_TqDem_tqCkEfcWoutAntiDB_TqDem_tqCkEfcWoutAntiDB(&variable)

/**********************************************************************************
   Create interface for variable TqDem_tqCkTakeOffMap
  **********************************************************************************/

#define vidSET_VALUE_TqDem_tqCkTakeOffMap(value)
#define vidGET_VALUE_TqDem_tqCkTakeOffMap(variable)                              Rte_Read_R_TqDem_tqCkTakeOffMap_TqDem_tqCkTakeOffMap(&variable)

/**********************************************************************************
   Create interface for array TqDem_tqEfcNRegTakeOffEco
  **********************************************************************************/

#define vidSET_ARRAY_TqDem_tqEfcNRegTakeOffEco(value,size)
#define vidGET_ARRAY_TqDem_tqEfcNRegTakeOffEco(variable,size)                    Rte_Read_R_TqDem_tqEfcNRegTakeOffEco_TqDem_tqEfcNRegTakeOffEco(&variable)

#define vidSET_ARRAY_ELEMENT_TqDem_tqEfcNRegTakeOffEco(variable,pos)
#define vidGET_ARRAY_ELEMENT_TqDem_tqEfcNRegTakeOffEco(variable,pos){ \
  if (pos < 2)\
  { \
     DT_TqDem_tqEfcNRegTakeOffEco datatemp[2];\
     Rte_Read_R_TqDem_tqEfcNRegTakeOffEco_TqDem_tqEfcNRegTakeOffEco(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array TqDem_tqEfcNRegTakeOffNorm
  **********************************************************************************/

#define vidSET_ARRAY_TqDem_tqEfcNRegTakeOffNorm(value,size)
#define vidGET_ARRAY_TqDem_tqEfcNRegTakeOffNorm(variable,size)                   Rte_Read_R_TqDem_tqEfcNRegTakeOffNorm_TqDem_tqEfcNRegTakeOffNorm(&variable)

#define vidSET_ARRAY_ELEMENT_TqDem_tqEfcNRegTakeOffNorm(variable,pos)
#define vidGET_ARRAY_ELEMENT_TqDem_tqEfcNRegTakeOffNorm(variable,pos){ \
  if (pos < 2)\
  { \
     DT_TqDem_tqEfcNRegTakeOffNorm datatemp[2];\
     Rte_Read_R_TqDem_tqEfcNRegTakeOffNorm_TqDem_tqEfcNRegTakeOffNorm(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable TqDiag_bUncrt_tqCkEngReal
  **********************************************************************************/

#define vidSET_VALUE_TqDiag_bUncrt_tqCkEngReal(value)                            Rte_Write_P_TqDiag_bUncrt_tqCkEngReal_TqDiag_bUncrt_tqCkEngReal(value)
#define vidGET_VALUE_TqDiag_bUncrt_tqCkEngReal(variable)                         Rte_Read_R_TqDiag_bUncrt_tqCkEngReal_TqDiag_bUncrt_tqCkEngReal(&variable)

/**********************************************************************************
   Create interface for variable TqEM_tqEM
  **********************************************************************************/

#define vidSET_VALUE_TqEM_tqEM(value)
#define vidGET_VALUE_TqEM_tqEM(variable)                                         Rte_Read_R_TqEM_tqEM_TqEM_tqEM(&variable)

/**********************************************************************************
   Create interface for variable TqLimEM_tqLimEM
  **********************************************************************************/

#define vidSET_VALUE_TqLimEM_tqLimEM(value)
#define vidGET_VALUE_TqLimEM_tqLimEM(variable)                                   Rte_Read_R_TqLimEM_tqLimEM_TqLimEM_tqLimEM(&variable)

/**********************************************************************************
   Create interface for variable TqLimEM_tqLimEMTrv
  **********************************************************************************/

#define vidSET_VALUE_TqLimEM_tqLimEMTrv(value)
#define vidGET_VALUE_TqLimEM_tqLimEMTrv(variable)                                Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(&variable)

/**********************************************************************************
   Create interface for variable TqLimUH_bReqClsCnv
  **********************************************************************************/

#define vidSET_VALUE_TqLimUH_bReqClsCnv(value)
#define vidGET_VALUE_TqLimUH_bReqClsCnv(variable)                                Rte_Read_R_TqLimUH_bReqClsCnv_TqLimUH_bReqClsCnv(&variable)

/**********************************************************************************
   Create interface for variable TqLimUH_bfAcvConstFrntTra1
  **********************************************************************************/

#define vidSET_VALUE_TqLimUH_bfAcvConstFrntTra1(value)
#define vidGET_VALUE_TqLimUH_bfAcvConstFrntTra1(variable)                        Rte_Read_R_TqLimUH_bfAcvConstFrntTra1_TqLimUH_bfAcvConstFrntTra1(&variable)

/**********************************************************************************
   Create interface for variable TqLimUH_stReqBlsVoltCtl
  **********************************************************************************/

#define vidSET_VALUE_TqLimUH_stReqBlsVoltCtl(value)
#define vidGET_VALUE_TqLimUH_stReqBlsVoltCtl(variable)                           Rte_Read_R_TqLimUH_stReqBlsVoltCtl_TqLimUH_stReqBlsVoltCtl(&variable)

/**********************************************************************************
   Create interface for variable TqRes_bAcvCll
  **********************************************************************************/

#define vidSET_VALUE_TqRes_bAcvCll(value)                                        Rte_Write_P_TqRes_bAcvCll_TqRes_bAcvCll(value)
#define vidGET_VALUE_TqRes_bAcvCll(variable)                                     Rte_Read_R_TqRes_bAcvCll_TqRes_bAcvCll(&variable)

/**********************************************************************************
   Create interface for variable TqRes_bDftACSwtOn
  **********************************************************************************/

#define vidSET_VALUE_TqRes_bDftACSwtOn(value)                                    Rte_Write_P_TqRes_bDftACSwtOn_TqRes_bDftACSwtOn(value)
#define vidGET_VALUE_TqRes_bDftACSwtOn(variable)                                 Rte_Read_R_TqRes_bDftACSwtOn_TqRes_bDftACSwtOn(&variable)

/**********************************************************************************
   Create interface for variable TqRes_bFrzAC
  **********************************************************************************/

#define vidSET_VALUE_TqRes_bFrzAC(value)                                         Rte_Write_P_TqRes_bFrzAC_TqRes_bFrzAC(value)
#define vidGET_VALUE_TqRes_bFrzAC(variable)                                      Rte_Read_R_TqRes_bFrzAC_TqRes_bFrzAC(&variable)

/**********************************************************************************
   Create interface for variable TqRes_tiTranCll
  **********************************************************************************/

#define vidSET_VALUE_TqRes_tiTranCll(value)                                      Rte_Write_P_TqRes_tiTranCll_TqRes_tiTranCll(value)
#define vidGET_VALUE_TqRes_tiTranCll(variable)                                   Rte_Read_R_TqRes_tiTranCll_TqRes_tiTranCll(&variable)

/**********************************************************************************
   Create interface for variable TqRes_tqFanStrtLoss
  **********************************************************************************/

#define vidSET_VALUE_TqRes_tqFanStrtLoss(value)                                  Rte_Write_P_TqRes_tqFanStrtLoss_TqRes_tqFanStrtLoss(value)
#define vidGET_VALUE_TqRes_tqFanStrtLoss(variable)                               Rte_Read_R_TqRes_tqFanStrtLoss_TqRes_tqFanStrtLoss(&variable)

/**********************************************************************************
   Create interface for variable TqRes_tqIncCll
  **********************************************************************************/

#define vidSET_VALUE_TqRes_tqIncCll(value)                                       Rte_Write_P_TqRes_tqIncCll_TqRes_tqIncCll(value)
#define vidGET_VALUE_TqRes_tqIncCll(variable)                                    Rte_Read_R_TqRes_tqIncCll_TqRes_tqIncCll(&variable)

/**********************************************************************************
   Create interface for variable TqRes_tqMaxRes
  **********************************************************************************/

#define vidSET_VALUE_TqRes_tqMaxRes(value)                                       Rte_Write_P_TqRes_tqMaxRes_TqRes_tqMaxRes(value)
#define vidGET_VALUE_TqRes_tqMaxRes(variable)                                    Rte_Read_R_TqRes_tqMaxRes_TqRes_tqMaxRes(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSyncFrame30D_Tra
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSyncFrame30D_Tra(value)                            Rte_Write_P_TqSys_EveSyncFrame30D_Tra_TqSys_EveSyncFrame30D_Tra(value)
#define vidGET_VALUE_TqSys_EveSyncFrame30D_Tra(variable)                         Rte_Read_R_TqSys_EveSyncFrame30D_Tra_TqSys_EveSyncFrame30D_Tra(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSyncFrame38D_Tra
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSyncFrame38D_Tra(value)                            Rte_Write_P_TqSys_EveSyncFrame38D_Tra_TqSys_EveSyncFrame38D_Tra(value)
#define vidGET_VALUE_TqSys_EveSyncFrame38D_Tra(variable)                         Rte_Read_R_TqSys_EveSyncFrame38D_Tra_TqSys_EveSyncFrame38D_Tra(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_ACCmd
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_ACCmd(value)                                  Rte_Write_P_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd(value)
#define vidGET_VALUE_TqSys_EveSync_ACCmd(variable)                               Rte_Read_R_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_CoPtNCross
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_CoPtNCross(value)                             Rte_Write_P_TqSys_EveSync_CoPtNCross_TqSys_EveSync_CoPtNCross(value)
#define vidGET_VALUE_TqSys_EveSync_CoPtNCross(variable)                          Rte_Read_R_TqSys_EveSync_CoPtNCross_TqSys_EveSync_CoPtNCross(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_CoPtNReg
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_CoPtNReg(value)                               Rte_Write_P_TqSys_EveSync_CoPtNReg_TqSys_EveSync_CoPtNReg(value)
#define vidGET_VALUE_TqSys_EveSync_CoPtNReg(variable)                            Rte_Read_R_TqSys_EveSync_CoPtNReg_TqSys_EveSync_CoPtNReg(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_CoPtNRegCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_CoPtNRegCord(value)                           Rte_Write_P_TqSys_EveSync_CoPtNRegCord_TqSys_EveSync_CoPtNRegCord(value)
#define vidGET_VALUE_TqSys_EveSync_CoPtNRegCord(variable)                        Rte_Read_R_TqSys_EveSync_CoPtNRegCord_TqSys_EveSync_CoPtNRegCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_TqEMClc
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_TqEMClc(value)                                Rte_Write_P_TqSys_EveSync_TqEMClc_TqSys_EveSync_TqEMClc(value)
#define vidGET_VALUE_TqSys_EveSync_TqEMClc(variable)                             Rte_Read_R_TqSys_EveSync_TqEMClc_TqSys_EveSync_TqEMClc(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_TqTreatElem
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_TqTreatElem(value)                            Rte_Write_P_TqSys_EveSync_TqTreatElem_TqSys_EveSync_TqTreatElem(value)
#define vidGET_VALUE_TqSys_EveSync_TqTreatElem(variable)                         Rte_Read_R_TqSys_EveSync_TqTreatElem_TqSys_EveSync_TqTreatElem(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_Tra
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_Tra(value)                                    Rte_Write_P_TqSys_EveSync_Tra_TqSys_EveSync_Tra(value)
#define vidGET_VALUE_TqSys_EveSync_Tra(variable)                                 Rte_Read_R_TqSys_EveSync_Tra_TqSys_EveSync_Tra(&variable)

/**********************************************************************************
   Create interface for variable TqSys_EveSync_VarElem
  **********************************************************************************/

#define vidSET_VALUE_TqSys_EveSync_VarElem(value)                                Rte_Write_P_TqSys_EveSync_VarElem_TqSys_EveSync_VarElem(value)
#define vidGET_VALUE_TqSys_EveSync_VarElem(variable)                             Rte_Read_R_TqSys_EveSync_VarElem_TqSys_EveSync_VarElem(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bAOSAcv
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bAOSAcv(value)
#define vidGET_VALUE_TqSys_bAOSAcv(variable)                                     Rte_Read_R_TqSys_bAOSAcv_TqSys_bAOSAcv(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bAcvAntiStallSmk
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bAcvAntiStallSmk(value)
#define vidGET_VALUE_TqSys_bAcvAntiStallSmk(variable)                            Rte_Read_R_TqSys_bAcvAntiStallSmk_TqSys_bAcvAntiStallSmk(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bAcvOvbReq
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bAcvOvbReq(value)                                     Rte_Write_P_TqSys_bAcvOvbReq_TqSys_bAcvOvbReq(value)
#define vidGET_VALUE_TqSys_bAcvOvbReq(variable)                                  Rte_Read_R_TqSys_bAcvOvbReq_TqSys_bAcvOvbReq(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bAcvVehSpdCtlLim
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bAcvVehSpdCtlLim(value)
#define vidGET_VALUE_TqSys_bAcvVehSpdCtlLim(variable)                            Rte_Read_R_TqSys_bAcvVehSpdCtlLim_TqSys_bAcvVehSpdCtlLim(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bAcvVehSpdCtlReg
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bAcvVehSpdCtlReg(value)
#define vidGET_VALUE_TqSys_bAcvVehSpdCtlReg(variable)                            Rte_Read_R_TqSys_bAcvVehSpdCtlReg_TqSys_bAcvVehSpdCtlReg(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bAcvVlvSysOptmVac
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bAcvVlvSysOptmVac(value)                              Rte_Write_P_TqSys_bAcvVlvSysOptmVac_TqSys_bAcvVlvSysOptmVac(value)
#define vidGET_VALUE_TqSys_bAcvVlvSysOptmVac(variable)                           Rte_Read_R_TqSys_bAcvVlvSysOptmVac_TqSys_bAcvVlvSysOptmVac(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bAuthRich
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bAuthRich(value)                                      Rte_Write_P_TqSys_bAuthRich_TqSys_bAuthRich(value)
#define vidGET_VALUE_TqSys_bAuthRich(variable)                                   Rte_Read_R_TqSys_bAuthRich_TqSys_bAuthRich(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bDeceAcv
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bDeceAcv(value)
#define vidGET_VALUE_TqSys_bDeceAcv(variable)                                    Rte_Read_R_TqSys_bDeceAcv_TqSys_bDeceAcv(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bDiDrivFilReq
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bDiDrivFilReq(value)
#define vidGET_VALUE_TqSys_bDiDrivFilReq(variable)                               Rte_Read_R_TqSys_bDiDrivFilReq_TqSys_bDiDrivFilReq(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bEngAsiReqTrv
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bEngAsiReqTrv(value)
#define vidGET_VALUE_TqSys_bEngAsiReqTrv(variable)                               Rte_Read_R_TqSys_bEngAsiReqTrv_TqSys_bEngAsiReqTrv(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bEngNOnIdl
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bEngNOnIdl(value)
#define vidGET_VALUE_TqSys_bEngNOnIdl(variable)                                  Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bFuCutOffReq
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bFuCutOffReq(value)                                   Rte_Write_P_TqSys_bFuCutOffReq_TqSys_bFuCutOffReq(value)
#define vidGET_VALUE_TqSys_bFuCutOffReq(variable)                                Rte_Read_R_TqSys_bFuCutOffReq_TqSys_bFuCutOffReq(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bIdlAcv
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bIdlAcv(value)
#define vidGET_VALUE_TqSys_bIdlAcv(variable)                                     Rte_Read_R_TqSys_bIdlAcv_TqSys_bIdlAcv(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bInhACBrkAsi
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bInhACBrkAsi(value)                                   Rte_Write_P_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi(value)
#define vidGET_VALUE_TqSys_bInhACBrkAsi(variable)                                Rte_Read_R_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bInhEGR
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bInhEGR(value)
#define vidGET_VALUE_TqSys_bInhEGR(variable)                                     Rte_Read_R_TqSys_bInhEGR_TqSys_bInhEGR(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bRlsAltBrkAsi
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bRlsAltBrkAsi(value)                                  Rte_Write_P_TqSys_bRlsAltBrkAsi_TqSys_bRlsAltBrkAsi(value)
#define vidGET_VALUE_TqSys_bRlsAltBrkAsi(variable)                               Rte_Read_R_TqSys_bRlsAltBrkAsi_TqSys_bRlsAltBrkAsi(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bTqSysAcv
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bTqSysAcv(value)                                      Rte_Write_P_TqSys_bTqSysAcv_TqSys_bTqSysAcv(value)
#define vidGET_VALUE_TqSys_bTqSysAcv(variable)                                   Rte_Read_R_TqSys_bTqSysAcv_TqSys_bTqSysAcv(&variable)

/**********************************************************************************
   Create interface for variable TqSys_bTypFu
  **********************************************************************************/

#define vidSET_VALUE_TqSys_bTypFu(value)
#define vidGET_VALUE_TqSys_bTypFu(variable)                                      Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&variable)

/**********************************************************************************
   Create interface for variable TqSys_facAntiStall1
  **********************************************************************************/

#define vidSET_VALUE_TqSys_facAntiStall1(value)
#define vidGET_VALUE_TqSys_facAntiStall1(variable)                               Rte_Read_R_TqSys_facAntiStall1_TqSys_facAntiStall1(&variable)

/**********************************************************************************
   Create interface for variable TqSys_facAntiStall2
  **********************************************************************************/

#define vidSET_VALUE_TqSys_facAntiStall2(value)
#define vidGET_VALUE_TqSys_facAntiStall2(variable)                               Rte_Read_R_TqSys_facAntiStall2_TqSys_facAntiStall2(&variable)

/**********************************************************************************
   Create interface for variable TqSys_facAntiStall3
  **********************************************************************************/

#define vidSET_VALUE_TqSys_facAntiStall3(value)
#define vidGET_VALUE_TqSys_facAntiStall3(variable)                               Rte_Read_R_TqSys_facAntiStall3_TqSys_facAntiStall3(&variable)

/**********************************************************************************
   Create interface for variable TqSys_facTqCkAntiStall
  **********************************************************************************/

#define vidSET_VALUE_TqSys_facTqCkAntiStall(value)
#define vidGET_VALUE_TqSys_facTqCkAntiStall(variable)                            Rte_Read_R_TqSys_facTqCkAntiStall_TqSys_facTqCkAntiStall(&variable)

/**********************************************************************************
   Create interface for variable TqSys_nOfsTotTakeOff
  **********************************************************************************/

#define vidSET_VALUE_TqSys_nOfsTotTakeOff(value)
#define vidGET_VALUE_TqSys_nOfsTotTakeOff(variable)                              Rte_Read_R_TqSys_nOfsTotTakeOff_TqSys_nOfsTotTakeOff(&variable)

/**********************************************************************************
   Create interface for variable TqSys_nTarFFL
  **********************************************************************************/

#define vidSET_VALUE_TqSys_nTarFFL(value)
#define vidGET_VALUE_TqSys_nTarFFL(variable)                                     Rte_Read_R_TqSys_nTarFFL_TqSys_nTarFFL(&variable)

/**********************************************************************************
   Create interface for variable TqSys_nTarIdl
  **********************************************************************************/

#define vidSET_VALUE_TqSys_nTarIdl(value)                                        Rte_Write_P_TqSys_nTarIdl_TqSys_nTarIdl(value)
#define vidGET_VALUE_TqSys_nTarIdl(variable)                                     Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&variable)

/**********************************************************************************
   Create interface for variable TqSys_nTarIdlCVCReq
  **********************************************************************************/

#define vidSET_VALUE_TqSys_nTarIdlCVCReq(value)
#define vidGET_VALUE_TqSys_nTarIdlCVCReq(variable)                               Rte_Read_R_TqSys_nTarIdlCVCReq_TqSys_nTarIdlCVCReq(&variable)

/**********************************************************************************
   Create interface for variable TqSys_nTarIdlFil
  **********************************************************************************/

#define vidSET_VALUE_TqSys_nTarIdlFil(value)                                     Rte_Write_P_TqSys_nTarIdlFil_TqSys_nTarIdlFil(value)
#define vidGET_VALUE_TqSys_nTarIdlFil(variable)                                  Rte_Read_R_TqSys_nTarIdlFil_TqSys_nTarIdlFil(&variable)

/**********************************************************************************
   Create interface for variable TqSys_nTarIdlNeut
  **********************************************************************************/

#define vidSET_VALUE_TqSys_nTarIdlNeut(value)                                    Rte_Write_P_TqSys_nTarIdlNeut_TqSys_nTarIdlNeut(value)
#define vidGET_VALUE_TqSys_nTarIdlNeut(variable)                                 Rte_Read_R_TqSys_nTarIdlNeut_TqSys_nTarIdlNeut(&variable)

/**********************************************************************************
   Create interface for array TqSys_prm_AOSConf3
  **********************************************************************************/

#define vidSET_ARRAY_TqSys_prm_AOSConf3(value,size)
#define vidGET_ARRAY_TqSys_prm_AOSConf3(variable,size)                           Rte_Read_R_TqSys_prm_AOSConf3_TqSys_prm_AOSConf3(&variable)

#define vidSET_ARRAY_ELEMENT_TqSys_prm_AOSConf3(variable,pos)
#define vidGET_ARRAY_ELEMENT_TqSys_prm_AOSConf3(variable,pos){ \
  if (pos < 6)\
  { \
     DT_TqSys_prm_AOSConf3 datatemp[6];\
     Rte_Read_R_TqSys_prm_AOSConf3_TqSys_prm_AOSConf3(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable TqSys_rLdEngRef
  **********************************************************************************/

#define vidSET_VALUE_TqSys_rLdEngRef(value)
#define vidGET_VALUE_TqSys_rLdEngRef(variable)                                   Rte_Read_R_TqSys_rLdEngRef_TqSys_rLdEngRef(&variable)

/**********************************************************************************
   Create interface for variable TqSys_stDrivFilPha
  **********************************************************************************/

#define vidSET_VALUE_TqSys_stDrivFilPha(value)
#define vidGET_VALUE_TqSys_stDrivFilPha(variable)                                Rte_Read_R_TqSys_stDrivFilPha_TqSys_stDrivFilPha(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tiDeacOvbReq
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tiDeacOvbReq(value)                                   Rte_Write_P_TqSys_tiDeacOvbReq_TqSys_tiDeacOvbReq(value)
#define vidGET_VALUE_TqSys_tiDeacOvbReq(variable)                                Rte_Read_R_TqSys_tiDeacOvbReq_TqSys_tiDeacOvbReq(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tiEveSync2
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tiEveSync2(value)                                     Rte_Write_P_TqSys_tiEveSync2_TqSys_tiEveSync2(value)
#define vidGET_VALUE_TqSys_tiEveSync2(variable)                                  Rte_Read_R_TqSys_tiEveSync2_TqSys_tiEveSync2(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkAOSCor
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkAOSCor(value)
#define vidGET_VALUE_TqSys_tqCkAOSCor(variable)                                  Rte_Read_R_TqSys_tqCkAOSCor_TqSys_tqCkAOSCor(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkAOSCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkAOSCord(value)
#define vidGET_VALUE_TqSys_tqCkAOSCord(variable)                                 Rte_Read_R_TqSys_tqCkAOSCord_TqSys_tqCkAOSCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkAntiStall
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkAntiStall(value)
#define vidGET_VALUE_TqSys_tqCkAntiStall(variable)                               Rte_Read_R_TqSys_tqCkAntiStall_TqSys_tqCkAntiStall(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkEfcAirFil
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkEfcAirFil(value)
#define vidGET_VALUE_TqSys_tqCkEfcAirFil(variable)                               Rte_Read_R_TqSys_tqCkEfcAirFil_TqSys_tqCkEfcAirFil(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkEfcFil
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkEfcFil(value)
#define vidGET_VALUE_TqSys_tqCkEfcFil(variable)                                  Rte_Read_R_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkEfcFilTrv
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkEfcFilTrv(value)
#define vidGET_VALUE_TqSys_tqCkEfcFilTrv(variable)                               Rte_Read_R_TqSys_tqCkEfcFilTrv_TqSys_tqCkEfcFilTrv(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkEngLimCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkEngLimCord(value)
#define vidGET_VALUE_TqSys_tqCkEngLimCord(variable)                              Rte_Read_R_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkEngLoss
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkEngLoss(value)
#define vidGET_VALUE_TqSys_tqCkEngLoss(variable)                                 Rte_Read_R_TqSys_tqCkEngLoss_TqSys_tqCkEngLoss(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkEngLossAdp
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkEngLossAdp(value)
#define vidGET_VALUE_TqSys_tqCkEngLossAdp(variable)                              Rte_Read_R_TqSys_tqCkEngLossAdp_TqSys_tqCkEngLossAdp(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkEngReal
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkEngReal(value)
#define vidGET_VALUE_TqSys_tqCkEngReal(variable)                                 Rte_Read_R_TqSys_tqCkEngReal_TqSys_tqCkEngReal(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqCkPumpHiPLoss
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqCkPumpHiPLoss(value)                                Rte_Write_P_TqSys_tqCkPumpHiPLoss_TqSys_tqCkPumpHiPLoss(value)
#define vidGET_VALUE_TqSys_tqCkPumpHiPLoss(variable)                             Rte_Read_R_TqSys_tqCkPumpHiPLoss_TqSys_tqCkPumpHiPLoss(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqEfcEngWoutAOS
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqEfcEngWoutAOS(value)
#define vidGET_VALUE_TqSys_tqEfcEngWoutAOS(variable)                             Rte_Read_R_TqSys_tqEfcEngWoutAOS_TqSys_tqEfcEngWoutAOS(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqEfcIdl
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqEfcIdl(value)
#define vidGET_VALUE_TqSys_tqEfcIdl(variable)                                    Rte_Read_R_TqSys_tqEfcIdl_TqSys_tqEfcIdl(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcAirEngIdlCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcAirEngIdlCord(value)
#define vidGET_VALUE_TqSys_tqIdcAirEngIdlCord(variable)                          Rte_Read_R_TqSys_tqIdcAirEngIdlCord_TqSys_tqIdcAirEngIdlCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcAirEngLimCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcAirEngLimCord(value)
#define vidGET_VALUE_TqSys_tqIdcAirEngLimCord(variable)                          Rte_Read_R_TqSys_tqIdcAirEngLimCord_TqSys_tqIdcAirEngLimCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcAirLim
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcAirLim(value)
#define vidGET_VALUE_TqSys_tqIdcAirLim(variable)                                 Rte_Read_R_TqSys_tqIdcAirLim_TqSys_tqIdcAirLim(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcAirLimCordWoutRes
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcAirLimCordWoutRes(value)
#define vidGET_VALUE_TqSys_tqIdcAirLimCordWoutRes(variable)                      Rte_Read_R_TqSys_tqIdcAirLimCordWoutRes_TqSys_tqIdcAirLimCordWoutRes(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcAirReq
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcAirReq(value)                                    Rte_Write_P_TqSys_tqIdcAirReq_TqSys_tqIdcAirReq(value)
#define vidGET_VALUE_TqSys_tqIdcAirReq(variable)                                 Rte_Read_R_TqSys_tqIdcAirReq_TqSys_tqIdcAirReq(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcAirReqGen
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcAirReqGen(value)                                 Rte_Write_P_TqSys_tqIdcAirReqGen_TqSys_tqIdcAirReqGen(value)
#define vidGET_VALUE_TqSys_tqIdcAirReqGen(variable)                              Rte_Read_R_TqSys_tqIdcAirReqGen_TqSys_tqIdcAirReqGen(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcAirReqUnlim
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcAirReqUnlim(value)
#define vidGET_VALUE_TqSys_tqIdcAirReqUnlim(variable)                            Rte_Read_R_TqSys_tqIdcAirReqUnlim_TqSys_tqIdcAirReqUnlim(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcColdSmkCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcColdSmkCord(value)
#define vidGET_VALUE_TqSys_tqIdcColdSmkCord(variable)                            Rte_Read_R_TqSys_tqIdcColdSmkCord_TqSys_tqIdcColdSmkCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcEngIdlCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcEngIdlCord(value)
#define vidGET_VALUE_TqSys_tqIdcEngIdlCord(variable)                             Rte_Read_R_TqSys_tqIdcEngIdlCord_TqSys_tqIdcEngIdlCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcEngLimCord
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcEngLimCord(value)
#define vidGET_VALUE_TqSys_tqIdcEngLimCord(variable)                             Rte_Read_R_TqSys_tqIdcEngLimCord_TqSys_tqIdcEngLimCord(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcLvlSBPA
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcLvlSBPA(value)                                   Rte_Write_P_TqSys_tqIdcLvlSBPA_TqSys_tqIdcLvlSBPA(value)
#define vidGET_VALUE_TqSys_tqIdcLvlSBPA(variable)                                Rte_Read_R_TqSys_tqIdcLvlSBPA_TqSys_tqIdcLvlSBPA(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcReq
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcReq(value)                                       Rte_Write_P_TqSys_tqIdcReq_TqSys_tqIdcReq(value)
#define vidGET_VALUE_TqSys_tqIdcReq(variable)                                    Rte_Read_R_TqSys_tqIdcReq_TqSys_tqIdcReq(&variable)

/**********************************************************************************
   Create interface for variable TqSys_tqIdcSBPA
  **********************************************************************************/

#define vidSET_VALUE_TqSys_tqIdcSBPA(value)                                      Rte_Write_P_TqSys_tqIdcSBPA_TqSys_tqIdcSBPA(value)
#define vidGET_VALUE_TqSys_tqIdcSBPA(variable)                                   Rte_Read_R_TqSys_tqIdcSBPA_TqSys_tqIdcSBPA(&variable)

/**********************************************************************************
   Create interface for variable Tra_bFrzAC
  **********************************************************************************/

#define vidSET_VALUE_Tra_bFrzAC(value)                                           Rte_Write_P_Tra_bFrzAC_Tra_bFrzAC(value)
#define vidGET_VALUE_Tra_bFrzAC(variable)                                        Rte_Read_R_Tra_bFrzAC_Tra_bFrzAC(&variable)

/**********************************************************************************
   Create interface for variable Tra_bNRegReq
  **********************************************************************************/

#define vidSET_VALUE_Tra_bNRegReq(value)                                         Rte_Write_P_Tra_bNRegReq_Tra_bNRegReq(value)
#define vidGET_VALUE_Tra_bNRegReq(variable)                                      Rte_Read_R_Tra_bNRegReq_Tra_bNRegReq(&variable)

/**********************************************************************************
   Create interface for variable Tra_bSIP
  **********************************************************************************/

#define vidSET_VALUE_Tra_bSIP(value)                                             Rte_Write_P_Tra_bSIP_Tra_bSIP(value)
#define vidGET_VALUE_Tra_bSIP(variable)                                          Rte_Read_R_Tra_bSIP_Tra_bSIP(&variable)

/**********************************************************************************
   Create interface for variable Tra_bSIPPrep
  **********************************************************************************/

#define vidSET_VALUE_Tra_bSIPPrep(value)                                         Rte_Write_P_Tra_bSIPPrep_Tra_bSIPPrep(value)
#define vidGET_VALUE_Tra_bSIPPrep(variable)                                      Rte_Read_R_Tra_bSIPPrep_Tra_bSIPPrep(&variable)

/**********************************************************************************
   Create interface for variable Tra_bTqTx
  **********************************************************************************/

#define vidSET_VALUE_Tra_bTqTx(value)                                            Rte_Write_P_Tra_bTqTx_Tra_bTqTx(value)
#define vidGET_VALUE_Tra_bTqTx(variable)                                         Rte_Read_R_Tra_bTqTx_Tra_bTqTx(&variable)

/**********************************************************************************
   Create interface for variable Tra_idxPtSpt
  **********************************************************************************/

#define vidSET_VALUE_Tra_idxPtSpt(value)                                         Rte_Write_P_Tra_idxPtSpt_Tra_idxPtSpt(value)
#define vidGET_VALUE_Tra_idxPtSpt(variable)                                      Rte_Read_R_Tra_idxPtSpt_Tra_idxPtSpt(&variable)

/**********************************************************************************
   Create interface for variable Tra_nPrimShaft
  **********************************************************************************/

#define vidSET_VALUE_Tra_nPrimShaft(value)                                       Rte_Write_P_Tra_nPrimShaft_Tra_nPrimShaft(value)
#define vidGET_VALUE_Tra_nPrimShaft(variable)                                    Rte_Read_R_Tra_nPrimShaft_Tra_nPrimShaft(&variable)

/**********************************************************************************
   Create interface for variable Tra_nTar
  **********************************************************************************/

#define vidSET_VALUE_Tra_nTar(value)                                             Rte_Write_P_Tra_nTar_Tra_nTar(value)
#define vidGET_VALUE_Tra_nTar(variable)                                          Rte_Read_R_Tra_nTar_Tra_nTar(&variable)

/**********************************************************************************
   Create interface for variable Tra_nTrb
  **********************************************************************************/

#define vidSET_VALUE_Tra_nTrb(value)                                             Rte_Write_P_Tra_nTrb_Tra_nTrb(value)
#define vidGET_VALUE_Tra_nTrb(variable)                                          Rte_Read_R_Tra_nTrb_Tra_nTrb(&variable)

/**********************************************************************************
   Create interface for variable Tra_noEgdGear
  **********************************************************************************/

#define vidSET_VALUE_Tra_noEgdGear(value)                                        Rte_Write_P_Tra_noEgdGear_Tra_noEgdGear(value)
#define vidGET_VALUE_Tra_noEgdGear(variable)                                     Rte_Read_R_Tra_noEgdGear_Tra_noEgdGear(&variable)

/**********************************************************************************
   Create interface for variable Tra_noTarGear
  **********************************************************************************/

#define vidSET_VALUE_Tra_noTarGear(value)                                        Rte_Write_P_Tra_noTarGear_Tra_noTarGear(value)
#define vidGET_VALUE_Tra_noTarGear(variable)                                     Rte_Read_R_Tra_noTarGear_Tra_noTarGear(&variable)

/**********************************************************************************
   Create interface for variable Tra_rCnvTq
  **********************************************************************************/

#define vidSET_VALUE_Tra_rCnvTq(value)                                           Rte_Write_P_Tra_rCnvTq_Tra_rCnvTq(value)
#define vidGET_VALUE_Tra_rCnvTq(variable)                                        Rte_Read_R_Tra_rCnvTq_Tra_rCnvTq(&variable)

/**********************************************************************************
   Create interface for variable Tra_stClu
  **********************************************************************************/

#define vidSET_VALUE_Tra_stClu(value)                                            Rte_Write_P_Tra_stClu_Tra_stClu(value)
#define vidGET_VALUE_Tra_stClu(variable)                                         Rte_Read_R_Tra_stClu_Tra_stClu(&variable)

/**********************************************************************************
   Create interface for variable Tra_stCnvClu
  **********************************************************************************/

#define vidSET_VALUE_Tra_stCnvClu(value)                                         Rte_Write_P_Tra_stCnvClu_Tra_stCnvClu(value)
#define vidGET_VALUE_Tra_stCnvClu(variable)                                      Rte_Read_R_Tra_stCnvClu_Tra_stCnvClu(&variable)

/**********************************************************************************
   Create interface for variable Tra_stCpl
  **********************************************************************************/

#define vidSET_VALUE_Tra_stCpl(value)                                            Rte_Write_P_Tra_stCpl_Tra_stCpl(value)
#define vidGET_VALUE_Tra_stCpl(variable)                                         Rte_Read_R_Tra_stCpl_Tra_stCpl(&variable)

/**********************************************************************************
   Create interface for variable Tra_stCrawl
  **********************************************************************************/

#define vidSET_VALUE_Tra_stCrawl(value)                                          Rte_Write_P_Tra_stCrawl_Tra_stCrawl(value)
#define vidGET_VALUE_Tra_stCrawl(variable)                                       Rte_Read_R_Tra_stCrawl_Tra_stCrawl(&variable)

/**********************************************************************************
   Create interface for variable Tra_stDragRed
  **********************************************************************************/

#define vidSET_VALUE_Tra_stDragRed(value)                                        Rte_Write_P_Tra_stDragRed_Tra_stDragRed(value)
#define vidGET_VALUE_Tra_stDragRed(variable)                                     Rte_Read_R_Tra_stDragRed_Tra_stDragRed(&variable)

/**********************************************************************************
   Create interface for variable Tra_stGBxMod
  **********************************************************************************/

#define vidSET_VALUE_Tra_stGBxMod(value)                                         Rte_Write_P_Tra_stGBxMod_Tra_stGBxMod(value)
#define vidGET_VALUE_Tra_stGBxMod(variable)                                      Rte_Read_R_Tra_stGBxMod_Tra_stGBxMod(&variable)

/**********************************************************************************
   Create interface for variable Tra_stGSTyp
  **********************************************************************************/

#define vidSET_VALUE_Tra_stGSTyp(value)                                          Rte_Write_P_Tra_stGSTyp_Tra_stGSTyp(value)
#define vidGET_VALUE_Tra_stGSTyp(variable)                                       Rte_Read_R_Tra_stGSTyp_Tra_stGSTyp(&variable)

/**********************************************************************************
   Create interface for variable Tra_stGearCtl
  **********************************************************************************/

#define vidSET_VALUE_Tra_stGearCtl(value)                                        Rte_Write_P_Tra_stGearCtl_Tra_stGearCtl(value)
#define vidGET_VALUE_Tra_stGearCtl(variable)                                     Rte_Read_R_Tra_stGearCtl_Tra_stGearCtl(&variable)

/**********************************************************************************
   Create interface for variable Tra_stGearRat
  **********************************************************************************/

#define vidSET_VALUE_Tra_stGearRat(value)                                        Rte_Write_P_Tra_stGearRat_Tra_stGearRat(value)
#define vidGET_VALUE_Tra_stGearRat(variable)                                     Rte_Read_R_Tra_stGearRat_Tra_stGearRat(&variable)

/**********************************************************************************
   Create interface for variable Tra_stPhaGearShift
  **********************************************************************************/

#define vidSET_VALUE_Tra_stPhaGearShift(value)                                   Rte_Write_P_Tra_stPhaGearShift_Tra_stPhaGearShift(value)
#define vidGET_VALUE_Tra_stPhaGearShift(variable)                                Rte_Read_R_Tra_stPhaGearShift_Tra_stPhaGearShift(&variable)

/**********************************************************************************
   Create interface for variable Tra_tqCnvClu
  **********************************************************************************/

#define vidSET_VALUE_Tra_tqCnvClu(value)                                         Rte_Write_P_Tra_tqCnvClu_Tra_tqCnvClu(value)
#define vidGET_VALUE_Tra_tqCnvClu(variable)                                      Rte_Read_R_Tra_tqCnvClu_Tra_tqCnvClu(&variable)

/**********************************************************************************
   Create interface for variable Tra_tqMaxClu
  **********************************************************************************/

#define vidSET_VALUE_Tra_tqMaxClu(value)                                         Rte_Write_P_Tra_tqMaxClu_Tra_tqMaxClu(value)
#define vidGET_VALUE_Tra_tqMaxClu(variable)                                      Rte_Read_R_Tra_tqMaxClu_Tra_tqMaxClu(&variable)

/**********************************************************************************
   Create interface for variable Tra_tqMaxGBx
  **********************************************************************************/

#define vidSET_VALUE_Tra_tqMaxGBx(value)                                         Rte_Write_P_Tra_tqMaxGBx_Tra_tqMaxGBx(value)
#define vidGET_VALUE_Tra_tqMaxGBx(variable)                                      Rte_Read_R_Tra_tqMaxGBx_Tra_tqMaxGBx(&variable)

/**********************************************************************************
   Create interface for variable Tra_tqReqClu
  **********************************************************************************/

#define vidSET_VALUE_Tra_tqReqClu(value)                                         Rte_Write_P_Tra_tqReqClu_Tra_tqReqClu(value)
#define vidGET_VALUE_Tra_tqReqClu(variable)                                      Rte_Read_R_Tra_tqReqClu_Tra_tqReqClu(&variable)

/**********************************************************************************
   Create interface for variable Tra_tqReqGBx
  **********************************************************************************/

#define vidSET_VALUE_Tra_tqReqGBx(value)                                         Rte_Write_P_Tra_tqReqGBx_Tra_tqReqGBx(value)
#define vidGET_VALUE_Tra_tqReqGBx(variable)                                      Rte_Read_R_Tra_tqReqGBx_Tra_tqReqGBx(&variable)

/**********************************************************************************
   Create interface for variable TrbAct_bBoostPresClCtlAcv
  **********************************************************************************/

#define vidSET_VALUE_TrbAct_bBoostPresClCtlAcv(value)
#define vidGET_VALUE_TrbAct_bBoostPresClCtlAcv(variable)                         Rte_Read_R_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv(&variable)

/**********************************************************************************
   Create interface for variable TrbAct_pUsThrFil
  **********************************************************************************/

#define vidSET_VALUE_TrbAct_pUsThrFil(value)
#define vidGET_VALUE_TrbAct_pUsThrFil(variable)                                  Rte_Read_R_TrbAct_pUsThrFil_TrbAct_pUsThrFil(&variable)

/**********************************************************************************
   Create interface for variable TrbAct_rCtl
  **********************************************************************************/

#define vidSET_VALUE_TrbAct_rCtl(value)
#define vidGET_VALUE_TrbAct_rCtl(variable)                                       Rte_Read_R_TrbAct_rCtl_TrbAct_rCtl(&variable)

/**********************************************************************************
   Create interface for variable TrbAct_rOpTrbAct
  **********************************************************************************/

#define vidSET_VALUE_TrbAct_rOpTrbAct(value)
#define vidGET_VALUE_TrbAct_rOpTrbAct(variable)                                  Rte_Read_R_TrbAct_rOpTrbAct_TrbAct_rOpTrbAct(&variable)

/**********************************************************************************
   Create interface for variable TrbAct_rRCOReq
  **********************************************************************************/

#define vidSET_VALUE_TrbAct_rRCOReq(value)
#define vidGET_VALUE_TrbAct_rRCOReq(variable)                                    Rte_Read_R_TrbAct_rRCOReq_TrbAct_rRCOReq(&variable)

/**********************************************************************************
   Create interface for variable TreatTDC_nCkGrd
  **********************************************************************************/

#define vidSET_VALUE_TreatTDC_nCkGrd(value)
#define vidGET_VALUE_TreatTDC_nCkGrd(variable)                                   Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&variable)

/**********************************************************************************
   Create interface for variable TreatTenms_nCkGrdFil
  **********************************************************************************/

#define vidSET_VALUE_TreatTenms_nCkGrdFil(value)
#define vidGET_VALUE_TreatTenms_nCkGrdFil(variable)                              Rte_Read_R_TreatTenms_nCkGrdFil_TreatTenms_nCkGrdFil(&variable)

/**********************************************************************************
   Create interface for variable TreatTenms_nCkTDCDelta
  **********************************************************************************/

#define vidSET_VALUE_TreatTenms_nCkTDCDelta(value)
#define vidGET_VALUE_TreatTenms_nCkTDCDelta(variable)                            Rte_Read_R_TreatTenms_nCkTDCDelta_TreatTenms_nCkTDCDelta(&variable)

/**********************************************************************************
   Create interface for variable UCE_bCAN1ComNd
  **********************************************************************************/

#define vidSET_VALUE_UCE_bCAN1ComNd(value)                                       Rte_Write_P_UCE_bCAN1ComNd_UCE_bCAN1ComNd(value)
#define vidGET_VALUE_UCE_bCAN1ComNd(variable)                                    Rte_Read_R_UCE_bCAN1ComNd_UCE_bCAN1ComNd(&variable)

/**********************************************************************************
   Create interface for variable UCE_bCAN2ComNd
  **********************************************************************************/

#define vidSET_VALUE_UCE_bCAN2ComNd(value)                                       Rte_Write_P_UCE_bCAN2ComNd_UCE_bCAN2ComNd(value)
#define vidGET_VALUE_UCE_bCAN2ComNd(variable)                                    Rte_Read_R_UCE_bCAN2ComNd_UCE_bCAN2ComNd(&variable)

/**********************************************************************************
   Create interface for variable UCE_bCAN3ComNd
  **********************************************************************************/

#define vidSET_VALUE_UCE_bCAN3ComNd(value)                                       Rte_Write_P_UCE_bCAN3ComNd_UCE_bCAN3ComNd(value)
#define vidGET_VALUE_UCE_bCAN3ComNd(variable)                                    Rte_Read_R_UCE_bCAN3ComNd_UCE_bCAN3ComNd(&variable)

/**********************************************************************************
   Create interface for variable UCE_bExtdWkuMain
  **********************************************************************************/

#define vidSET_VALUE_UCE_bExtdWkuMain(value)
#define vidGET_VALUE_UCE_bExtdWkuMain(variable)                                  Rte_Read_R_UCE_bExtdWkuMain_UCE_bExtdWkuMain(&variable)

/**********************************************************************************
   Create interface for variable UCE_bLINComNd
  **********************************************************************************/

#define vidSET_VALUE_UCE_bLINComNd(value)                                        Rte_Write_P_UCE_bLINComNd_UCE_bLINComNd(value)
#define vidGET_VALUE_UCE_bLINComNd(variable)                                     Rte_Read_R_UCE_bLINComNd_UCE_bLINComNd(&variable)

/**********************************************************************************
   Create interface for variable UCE_bLINComReq
  **********************************************************************************/

#define vidSET_VALUE_UCE_bLINComReq(value)
#define vidGET_VALUE_UCE_bLINComReq(variable)                                    Rte_Read_R_UCE_bLINComReq_UCE_bLINComReq(&variable)

/**********************************************************************************
   Create interface for variable UCE_bPwrlAcv
  **********************************************************************************/

#define vidSET_VALUE_UCE_bPwrlAcv(value)
#define vidGET_VALUE_UCE_bPwrlAcv(variable)                                      Rte_Read_R_UCE_bPwrlAcv_UCE_bPwrlAcv(&variable)

/**********************************************************************************
   Create interface for variable UCE_bRCDLineCmd
  **********************************************************************************/

#define vidSET_VALUE_UCE_bRCDLineCmd(value)
#define vidGET_VALUE_UCE_bRCDLineCmd(variable)                                   Rte_Read_R_UCE_bRCDLineCmd_UCE_bRCDLineCmd(&variable)

/**********************************************************************************
   Create interface for variable UCE_bShutDownAuth
  **********************************************************************************/

#define vidSET_VALUE_UCE_bShutDownAuth(value)
#define vidGET_VALUE_UCE_bShutDownAuth(variable)                                 Rte_Read_R_UCE_bShutDownAuth_UCE_bShutDownAuth(&variable)

/**********************************************************************************
   Create interface for variable UCE_bWkuMain
  **********************************************************************************/

#define vidSET_VALUE_UCE_bWkuMain(value)
#define vidGET_VALUE_UCE_bWkuMain(variable)                                      Rte_Read_R_UCE_bWkuMain_UCE_bWkuMain(&variable)

/**********************************************************************************
   Create interface for variable UCE_bfMstPtlWkuReq
  **********************************************************************************/

#define vidSET_VALUE_UCE_bfMstPtlWkuReq(value)
#define vidGET_VALUE_UCE_bfMstPtlWkuReq(variable)                                Rte_Read_R_UCE_bfMstPtlWkuReq_UCE_bfMstPtlWkuReq(&variable)

/**********************************************************************************
   Create interface for variable UCE_bfSlavePtlWkuSt
  **********************************************************************************/

#define vidSET_VALUE_UCE_bfSlavePtlWkuSt(value)
#define vidGET_VALUE_UCE_bfSlavePtlWkuSt(variable)                               Rte_Read_R_UCE_bfSlavePtlWkuSt_UCE_bfSlavePtlWkuSt(&variable)

/**********************************************************************************
   Create interface for variable UCE_stCAN1ComReq
  **********************************************************************************/

#define vidSET_VALUE_UCE_stCAN1ComReq(value)
#define vidGET_VALUE_UCE_stCAN1ComReq(variable)                                  Rte_Read_R_UCE_stCAN1ComReq_UCE_stCAN1ComReq(&variable)

/**********************************************************************************
   Create interface for variable UCE_stCAN2ComReq
  **********************************************************************************/

#define vidSET_VALUE_UCE_stCAN2ComReq(value)
#define vidGET_VALUE_UCE_stCAN2ComReq(variable)                                  Rte_Read_R_UCE_stCAN2ComReq_UCE_stCAN2ComReq(&variable)

/**********************************************************************************
   Create interface for variable UCE_stCAN3ComReq
  **********************************************************************************/

#define vidSET_VALUE_UCE_stCAN3ComReq(value)
#define vidGET_VALUE_UCE_stCAN3ComReq(variable)                                  Rte_Read_R_UCE_stCAN3ComReq_UCE_stCAN3ComReq(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_facPresAltiCor
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_facPresAltiCor(value)
#define vidGET_VALUE_UsThrM_facPresAltiCor(variable)                             Rte_Read_R_UsThrM_facPresAltiCor_UsThrM_facPresAltiCor(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pAirExt
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pAirExt(value)
#define vidGET_VALUE_UsThrM_pAirExt(variable)                                    Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pAirExtEstim
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pAirExtEstim(value)                                  Rte_Write_P_UsThrM_pAirExtEstim_UsThrM_pAirExtEstim(value)
#define vidGET_VALUE_UsThrM_pAirExtEstim(variable)                               Rte_Read_R_UsThrM_pAirExtEstim_UsThrM_pAirExtEstim(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pAirExtMesCor
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pAirExtMesCor(value)
#define vidGET_VALUE_UsThrM_pAirExtMesCor(variable)                              Rte_Read_R_UsThrM_pAirExtMesCor_UsThrM_pAirExtMesCor(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pDsCmpr
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pDsCmpr(value)
#define vidGET_VALUE_UsThrM_pDsCmpr(variable)                                    Rte_Read_R_UsThrM_pDsCmpr_UsThrM_pDsCmpr(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pDsThrAcvAirExtCtlMod
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pDsThrAcvAirExtCtlMod(value)
#define vidGET_VALUE_UsThrM_pDsThrAcvAirExtCtlMod(variable)                      Rte_Read_R_UsThrM_pDsThrAcvAirExtCtlMod_UsThrM_pDsThrAcvAirExtCtlMod(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pLossAirFil
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pLossAirFil(value)
#define vidGET_VALUE_UsThrM_pLossAirFil(variable)                                Rte_Read_R_UsThrM_pLossAirFil_UsThrM_pLossAirFil(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pLossCmpr
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pLossCmpr(value)
#define vidGET_VALUE_UsThrM_pLossCmpr(variable)                                  Rte_Read_R_UsThrM_pLossCmpr_UsThrM_pLossCmpr(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pUsThrCor
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pUsThrCor(value)
#define vidGET_VALUE_UsThrM_pUsThrCor(variable)                                  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pUsThrMesCor
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pUsThrMesCor(value)
#define vidGET_VALUE_UsThrM_pUsThrMesCor(variable)                               Rte_Read_R_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_pUsThrTrbCor
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_pUsThrTrbCor(value)
#define vidGET_VALUE_UsThrM_pUsThrTrbCor(variable)                               Rte_Read_R_UsThrM_pUsThrTrbCor_UsThrM_pUsThrTrbCor(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_tDsThrCorMes
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_tDsThrCorMes(value)                                  Rte_Write_P_UsThrM_tDsThrCorMes_UsThrM_tDsThrCorMes(value)
#define vidGET_VALUE_UsThrM_tDsThrCorMes(variable)                               Rte_Read_R_UsThrM_tDsThrCorMes_UsThrM_tDsThrCorMes(&variable)

/**********************************************************************************
   Create interface for variable UsThrM_tThrMes
  **********************************************************************************/

#define vidSET_VALUE_UsThrM_tThrMes(value)
#define vidGET_VALUE_UsThrM_tThrMes(variable)                                    Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_aVehVSLimReq_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_aVehVSLimReq_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_aVehVSLimReq_DeacVSLim(variable)                      Rte_Read_R_VSCtl_aVehVSLimReq_DeacVSLim_VSCtl_aVehVSLimReq_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_aVehVSMaxReq_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_aVehVSMaxReq_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_aVehVSMaxReq_DeacVSMax(variable)                      Rte_Read_R_VSCtl_aVehVSMaxReq_DeacVSMax_VSCtl_aVehVSMaxReq_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_aVehVSRegReq_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_aVehVSRegReq_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_aVehVSRegReq_DeacVSReg(variable)                      Rte_Read_R_VSCtl_aVehVSRegReq_DeacVSReg_VSCtl_aVehVSRegReq_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_aVeh_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_aVeh_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_aVeh_DeacVSLim(variable)                              Rte_Read_R_VSCtl_aVeh_DeacVSLim_VSCtl_aVeh_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_aVeh_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_aVeh_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_aVeh_DeacVSMax(variable)                              Rte_Read_R_VSCtl_aVeh_DeacVSMax_VSCtl_aVeh_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_aVeh_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_aVeh_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_aVeh_DeacVSReg(variable)                              Rte_Read_R_VSCtl_aVeh_DeacVSReg_VSCtl_aVeh_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_bAcvTqWhlPTMinSat
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_bAcvTqWhlPTMinSat(value)
#define vidGET_VALUE_VSCtl_bAcvTqWhlPTMinSat(variable)                           Rte_Read_R_VSCtl_bAcvTqWhlPTMinSat_VSCtl_bAcvTqWhlPTMinSat(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_bCtlEfc_tqWhlPt
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_bCtlEfc_tqWhlPt(value)
#define vidGET_VALUE_VSCtl_bCtlEfc_tqWhlPt(variable)                             Rte_Read_R_VSCtl_bCtlEfc_tqWhlPt_VSCtl_bCtlEfc_tqWhlPt(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_bDrvOvrdDVSReg_aVeh
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_bDrvOvrdDVSReg_aVeh(value)
#define vidGET_VALUE_VSCtl_bDrvOvrdDVSReg_aVeh(variable)                         Rte_Read_R_VSCtl_bDrvOvrdDVSReg_aVeh_VSCtl_bDrvOvrdDVSReg_aVeh(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_bKdAuth
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_bKdAuth(value)
#define vidGET_VALUE_VSCtl_bKdAuth(variable)                                     Rte_Read_R_VSCtl_bKdAuth_VSCtl_bKdAuth(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_dstVehTotMes_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_dstVehTotMes_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_dstVehTotMes_DeacVSLim(variable)                      Rte_Read_R_VSCtl_dstVehTotMes_DeacVSLim_VSCtl_dstVehTotMes_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_dstVehTotMes_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_dstVehTotMes_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_dstVehTotMes_DeacVSMax(variable)                      Rte_Read_R_VSCtl_dstVehTotMes_DeacVSMax_VSCtl_dstVehTotMes_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_dstVehTotMes_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_dstVehTotMes_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_dstVehTotMes_DeacVSReg(variable)                      Rte_Read_R_VSCtl_dstVehTotMes_DeacVSReg_VSCtl_dstVehTotMes_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_jrkVehReqDeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_jrkVehReqDeacVSLim(value)
#define vidGET_VALUE_VSCtl_jrkVehReqDeacVSLim(variable)                          Rte_Read_R_VSCtl_jrkVehReqDeacVSLim_VSCtl_jrkVehReqDeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_jrkVehReqDeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_jrkVehReqDeacVSMax(value)
#define vidGET_VALUE_VSCtl_jrkVehReqDeacVSMax(variable)                          Rte_Read_R_VSCtl_jrkVehReqDeacVSMax_VSCtl_jrkVehReqDeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_jrkVehReqDeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_jrkVehReqDeacVSReg(value)
#define vidGET_VALUE_VSCtl_jrkVehReqDeacVSReg(variable)                          Rte_Read_R_VSCtl_jrkVehReqDeacVSReg_VSCtl_jrkVehReqDeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_jrkVeh_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_jrkVeh_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_jrkVeh_DeacVSLim(variable)                            Rte_Read_R_VSCtl_jrkVeh_DeacVSLim_VSCtl_jrkVeh_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_jrkVeh_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_jrkVeh_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_jrkVeh_DeacVSMax(variable)                            Rte_Read_R_VSCtl_jrkVeh_DeacVSMax_VSCtl_jrkVeh_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_jrkVeh_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_jrkVeh_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_jrkVeh_DeacVSReg(variable)                            Rte_Read_R_VSCtl_jrkVeh_DeacVSReg_VSCtl_jrkVeh_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_noGearEgd_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_noGearEgd_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_noGearEgd_DeacVSLim(variable)                         Rte_Read_R_VSCtl_noGearEgd_DeacVSLim_VSCtl_noGearEgd_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_noGearEgd_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_noGearEgd_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_noGearEgd_DeacVSMax(variable)                         Rte_Read_R_VSCtl_noGearEgd_DeacVSMax_VSCtl_noGearEgd_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_noGearEgd_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_noGearEgd_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_noGearEgd_DeacVSReg(variable)                         Rte_Read_R_VSCtl_noGearEgd_DeacVSReg_VSCtl_noGearEgd_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_noGearReqMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_noGearReqMax(value)
#define vidGET_VALUE_VSCtl_noGearReqMax(variable)                                Rte_Read_R_VSCtl_noGearReqMax_VSCtl_noGearReqMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_noGearReqMin
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_noGearReqMin(value)
#define vidGET_VALUE_VSCtl_noGearReqMin(variable)                                Rte_Read_R_VSCtl_noGearReqMin_VSCtl_noGearReqMin(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_posnGBxDeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_posnGBxDeacVSLim(value)
#define vidGET_VALUE_VSCtl_posnGBxDeacVSLim(variable)                            Rte_Read_R_VSCtl_posnGBxDeacVSLim_VSCtl_posnGBxDeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_posnGBxDeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_posnGBxDeacVSMax(value)
#define vidGET_VALUE_VSCtl_posnGBxDeacVSMax(variable)                            Rte_Read_R_VSCtl_posnGBxDeacVSMax_VSCtl_posnGBxDeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_posnGBxDeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_posnGBxDeacVSReg(value)
#define vidGET_VALUE_VSCtl_posnGBxDeacVSReg(variable)                            Rte_Read_R_VSCtl_posnGBxDeacVSReg_VSCtl_posnGBxDeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rAccPEngMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rAccPEngMax(value)
#define vidGET_VALUE_VSCtl_rAccPEngMax(variable)                                 Rte_Read_R_VSCtl_rAccPEngMax_VSCtl_rAccPEngMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rAccPEngMin
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rAccPEngMin(value)
#define vidGET_VALUE_VSCtl_rAccPEngMin(variable)                                 Rte_Read_R_VSCtl_rAccPEngMin_VSCtl_rAccPEngMin(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rAccPPTMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rAccPPTMax(value)
#define vidGET_VALUE_VSCtl_rAccPPTMax(variable)                                  Rte_Read_R_VSCtl_rAccPPTMax_VSCtl_rAccPPTMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rAccPPTMin
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rAccPPTMin(value)
#define vidGET_VALUE_VSCtl_rAccPPTMin(variable)                                  Rte_Read_R_VSCtl_rAccPPTMin_VSCtl_rAccPPTMin(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rAccP_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rAccP_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_rAccP_DeacVSLim(variable)                             Rte_Read_R_VSCtl_rAccP_DeacVSLim_VSCtl_rAccP_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rAccP_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rAccP_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_rAccP_DeacVSMax(variable)                             Rte_Read_R_VSCtl_rAccP_DeacVSMax_VSCtl_rAccP_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rAccP_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rAccP_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_rAccP_DeacVSReg(variable)                             Rte_Read_R_VSCtl_rAccP_DeacVSReg_VSCtl_rAccP_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rSlop_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rSlop_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_rSlop_DeacVSLim(variable)                             Rte_Read_R_VSCtl_rSlop_DeacVSLim_VSCtl_rSlop_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rSlop_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rSlop_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_rSlop_DeacVSMax(variable)                             Rte_Read_R_VSCtl_rSlop_DeacVSMax_VSCtl_rSlop_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rSlop_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rSlop_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_rSlop_DeacVSReg(variable)                             Rte_Read_R_VSCtl_rSlop_DeacVSReg_VSCtl_rSlop_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_rTqWhlPTRe
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_rTqWhlPTRe(value)
#define vidGET_VALUE_VSCtl_rTqWhlPTRe(variable)                                  Rte_Read_R_VSCtl_rTqWhlPTRe_VSCtl_rTqWhlPTRe(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_spdVehReqDeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_spdVehReqDeacVSLim(value)
#define vidGET_VALUE_VSCtl_spdVehReqDeacVSLim(variable)                          Rte_Read_R_VSCtl_spdVehReqDeacVSLim_VSCtl_spdVehReqDeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_spdVehReqDeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_spdVehReqDeacVSMax(value)
#define vidGET_VALUE_VSCtl_spdVehReqDeacVSMax(variable)                          Rte_Read_R_VSCtl_spdVehReqDeacVSMax_VSCtl_spdVehReqDeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_spdVehReqDeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_spdVehReqDeacVSReg(value)
#define vidGET_VALUE_VSCtl_spdVehReqDeacVSReg(variable)                          Rte_Read_R_VSCtl_spdVehReqDeacVSReg_VSCtl_spdVehReqDeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_spdVehVSMaxReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_spdVehVSMaxReq(value)
#define vidGET_VALUE_VSCtl_spdVehVSMaxReq(variable)                              Rte_Read_R_VSCtl_spdVehVSMaxReq_VSCtl_spdVehVSMaxReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_spdVeh_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_spdVeh_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_spdVeh_DeacVSLim(variable)                            Rte_Read_R_VSCtl_spdVeh_DeacVSLim_VSCtl_spdVeh_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_spdVeh_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_spdVeh_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_spdVeh_DeacVSMax(variable)                            Rte_Read_R_VSCtl_spdVeh_DeacVSMax_VSCtl_spdVeh_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_spdVeh_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_spdVeh_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_spdVeh_DeacVSReg(variable)                            Rte_Read_R_VSCtl_spdVeh_DeacVSReg_VSCtl_spdVeh_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSLimReq_no1
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSLimReq_no1(value)
#define vidGET_VALUE_VSCtl_stDeacVSLimReq_no1(variable)                          Rte_Read_R_VSCtl_stDeacVSLimReq_no1_VSCtl_stDeacVSLimReq_no1(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSLimReq_no2
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSLimReq_no2(value)
#define vidGET_VALUE_VSCtl_stDeacVSLimReq_no2(variable)                          Rte_Read_R_VSCtl_stDeacVSLimReq_no2_VSCtl_stDeacVSLimReq_no2(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSMaxReq_no1
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSMaxReq_no1(value)
#define vidGET_VALUE_VSCtl_stDeacVSMaxReq_no1(variable)                          Rte_Read_R_VSCtl_stDeacVSMaxReq_no1_VSCtl_stDeacVSMaxReq_no1(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSMaxReq_no2
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSMaxReq_no2(value)
#define vidGET_VALUE_VSCtl_stDeacVSMaxReq_no2(variable)                          Rte_Read_R_VSCtl_stDeacVSMaxReq_no2_VSCtl_stDeacVSMaxReq_no2(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSRegReqHi_no1
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSRegReqHi_no1(value)
#define vidGET_VALUE_VSCtl_stDeacVSRegReqHi_no1(variable)                        Rte_Read_R_VSCtl_stDeacVSRegReqHi_no1_VSCtl_stDeacVSRegReqHi_no1(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSRegReqHi_no2
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSRegReqHi_no2(value)
#define vidGET_VALUE_VSCtl_stDeacVSRegReqHi_no2(variable)                        Rte_Read_R_VSCtl_stDeacVSRegReqHi_no2_VSCtl_stDeacVSRegReqHi_no2(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSRegReqLo_no1
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSRegReqLo_no1(value)
#define vidGET_VALUE_VSCtl_stDeacVSRegReqLo_no1(variable)                        Rte_Read_R_VSCtl_stDeacVSRegReqLo_no1_VSCtl_stDeacVSRegReqLo_no1(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stDeacVSRegReqLo_no2
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stDeacVSRegReqLo_no2(value)
#define vidGET_VALUE_VSCtl_stDeacVSRegReqLo_no2(variable)                        Rte_Read_R_VSCtl_stDeacVSRegReqLo_no2_VSCtl_stDeacVSRegReqLo_no2(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stGearCtlReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stGearCtlReq(value)
#define vidGET_VALUE_VSCtl_stGearCtlReq(variable)                                Rte_Read_R_VSCtl_stGearCtlReq_VSCtl_stGearCtlReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stRec_stDeacVSLimReq1
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stRec_stDeacVSLimReq1(value)
#define vidGET_VALUE_VSCtl_stRec_stDeacVSLimReq1(variable)                       Rte_Read_R_VSCtl_stRec_stDeacVSLimReq1_VSCtl_stRec_stDeacVSLimReq1(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stRec_stDeacVSLimReq2
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stRec_stDeacVSLimReq2(value)
#define vidGET_VALUE_VSCtl_stRec_stDeacVSLimReq2(variable)                       Rte_Read_R_VSCtl_stRec_stDeacVSLimReq2_VSCtl_stRec_stDeacVSLimReq2(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stRec_stDeacVSMaxReq1
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stRec_stDeacVSMaxReq1(value)
#define vidGET_VALUE_VSCtl_stRec_stDeacVSMaxReq1(variable)                       Rte_Read_R_VSCtl_stRec_stDeacVSMaxReq1_VSCtl_stRec_stDeacVSMaxReq1(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stRec_stDeacVSMaxReq2
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stRec_stDeacVSMaxReq2(value)
#define vidGET_VALUE_VSCtl_stRec_stDeacVSMaxReq2(variable)                       Rte_Read_R_VSCtl_stRec_stDeacVSMaxReq2_VSCtl_stRec_stDeacVSMaxReq2(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stRec_stDeacVSRegReq1
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stRec_stDeacVSRegReq1(value)
#define vidGET_VALUE_VSCtl_stRec_stDeacVSRegReq1(variable)                       Rte_Read_R_VSCtl_stRec_stDeacVSRegReq1_VSCtl_stRec_stDeacVSRegReq1(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stRec_stDeacVSRegReq2
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stRec_stDeacVSRegReq2(value)
#define vidGET_VALUE_VSCtl_stRec_stDeacVSRegReq2(variable)                       Rte_Read_R_VSCtl_stRec_stDeacVSRegReq2_VSCtl_stRec_stDeacVSRegReq2(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stTqPTMinCtl
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stTqPTMinCtl(value)
#define vidGET_VALUE_VSCtl_stTqPTMinCtl(variable)                                Rte_Read_R_VSCtl_stTqPTMinCtl_VSCtl_stTqPTMinCtl(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stTqWhlPTPotCtlReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stTqWhlPTPotCtlReq(value)
#define vidGET_VALUE_VSCtl_stTqWhlPTPotCtlReq(variable)                          Rte_Read_R_VSCtl_stTqWhlPTPotCtlReq_VSCtl_stTqWhlPTPotCtlReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSLimExtd
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSLimExtd(value)
#define vidGET_VALUE_VSCtl_stVSLimExtd(variable)                                 Rte_Read_R_VSCtl_stVSLimExtd_VSCtl_stVSLimExtd(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSLimPrev_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSLimPrev_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_stVSLimPrev_DeacVSLim(variable)                       Rte_Read_R_VSCtl_stVSLimPrev_DeacVSLim_VSCtl_stVSLimPrev_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSLim_DeacVSLim
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSLim_DeacVSLim(value)
#define vidGET_VALUE_VSCtl_stVSLim_DeacVSLim(variable)                           Rte_Read_R_VSCtl_stVSLim_DeacVSLim_VSCtl_stVSLim_DeacVSLim(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSMaxExtd
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSMaxExtd(value)
#define vidGET_VALUE_VSCtl_stVSMaxExtd(variable)                                 Rte_Read_R_VSCtl_stVSMaxExtd_VSCtl_stVSMaxExtd(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSMaxPrev_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSMaxPrev_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_stVSMaxPrev_DeacVSMax(variable)                       Rte_Read_R_VSCtl_stVSMaxPrev_DeacVSMax_VSCtl_stVSMaxPrev_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSMax_DeacVSMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSMax_DeacVSMax(value)
#define vidGET_VALUE_VSCtl_stVSMax_DeacVSMax(variable)                           Rte_Read_R_VSCtl_stVSMax_DeacVSMax_VSCtl_stVSMax_DeacVSMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSRegExtd
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSRegExtd(value)
#define vidGET_VALUE_VSCtl_stVSRegExtd(variable)                                 Rte_Read_R_VSCtl_stVSRegExtd_VSCtl_stVSRegExtd(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSRegPrev_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSRegPrev_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_stVSRegPrev_DeacVSReg(variable)                       Rte_Read_R_VSCtl_stVSRegPrev_DeacVSReg_VSCtl_stVSRegPrev_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_stVSReg_DeacVSReg
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_stVSReg_DeacVSReg(value)
#define vidGET_VALUE_VSCtl_stVSReg_DeacVSReg(variable)                           Rte_Read_R_VSCtl_stVSReg_DeacVSReg_VSCtl_stVSReg_DeacVSReg(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tiCfmSdwnReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tiCfmSdwnReq(value)
#define vidGET_VALUE_VSCtl_tiCfmSdwnReq(variable)                                Rte_Read_R_VSCtl_tiCfmSdwnReq_VSCtl_tiCfmSdwnReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tiCfmSupReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tiCfmSupReq(value)
#define vidGET_VALUE_VSCtl_tiCfmSupReq(variable)                                 Rte_Read_R_VSCtl_tiCfmSupReq_VSCtl_tiCfmSupReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqCkEfcMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqCkEfcMax(value)
#define vidGET_VALUE_VSCtl_tqCkEfcMax(variable)                                  Rte_Read_R_VSCtl_tqCkEfcMax_VSCtl_tqCkEfcMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqCkEfcMaxReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqCkEfcMaxReq(value)
#define vidGET_VALUE_VSCtl_tqCkEfcMaxReq(variable)                               Rte_Read_R_VSCtl_tqCkEfcMaxReq_VSCtl_tqCkEfcMaxReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqCkEfcMin
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqCkEfcMin(value)
#define vidGET_VALUE_VSCtl_tqCkEfcMin(variable)                                  Rte_Read_R_VSCtl_tqCkEfcMin_VSCtl_tqCkEfcMin(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqCkEfcMinReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqCkEfcMinReq(value)
#define vidGET_VALUE_VSCtl_tqCkEfcMinReq(variable)                               Rte_Read_R_VSCtl_tqCkEfcMinReq_VSCtl_tqCkEfcMinReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqEfcTarMax
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqEfcTarMax(value)
#define vidGET_VALUE_VSCtl_tqEfcTarMax(variable)                                 Rte_Read_R_VSCtl_tqEfcTarMax_VSCtl_tqEfcTarMax(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqEfcTarMin
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqEfcTarMin(value)
#define vidGET_VALUE_VSCtl_tqEfcTarMin(variable)                                 Rte_Read_R_VSCtl_tqEfcTarMin_VSCtl_tqEfcTarMin(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTAplReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTAplReq(value)
#define vidGET_VALUE_VSCtl_tqWhlPTAplReq(variable)                               Rte_Read_R_VSCtl_tqWhlPTAplReq_VSCtl_tqWhlPTAplReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTMaxReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTMaxReq(value)
#define vidGET_VALUE_VSCtl_tqWhlPTMaxReq(variable)                               Rte_Read_R_VSCtl_tqWhlPTMaxReq_VSCtl_tqWhlPTMaxReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTMinReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTMinReq(value)
#define vidGET_VALUE_VSCtl_tqWhlPTMinReq(variable)                               Rte_Read_R_VSCtl_tqWhlPTMinReq_VSCtl_tqWhlPTMinReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTMinSat
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTMinSat(value)
#define vidGET_VALUE_VSCtl_tqWhlPTMinSat(variable)                               Rte_Read_R_VSCtl_tqWhlPTMinSat_VSCtl_tqWhlPTMinSat(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTPotMaxReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTPotMaxReq(value)
#define vidGET_VALUE_VSCtl_tqWhlPTPotMaxReq(variable)                            Rte_Read_R_VSCtl_tqWhlPTPotMaxReq_VSCtl_tqWhlPTPotMaxReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTPotMinReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTPotMinReq(value)
#define vidGET_VALUE_VSCtl_tqWhlPTPotMinReq(variable)                            Rte_Read_R_VSCtl_tqWhlPTPotMinReq_VSCtl_tqWhlPTPotMinReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTPotReq
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTPotReq(value)
#define vidGET_VALUE_VSCtl_tqWhlPTPotReq(variable)                               Rte_Read_R_VSCtl_tqWhlPTPotReq_VSCtl_tqWhlPTPotReq(&variable)

/**********************************************************************************
   Create interface for variable VSCtl_tqWhlPTReal
  **********************************************************************************/

#define vidSET_VALUE_VSCtl_tqWhlPTReal(value)
#define vidGET_VALUE_VSCtl_tqWhlPTReal(variable)                                 Rte_Read_R_VSCtl_tqWhlPTReal_VSCtl_tqWhlPTReal(&variable)

/**********************************************************************************
   Create interface for array Vcpe_cam_offsets
  **********************************************************************************/

#define vidSET_ARRAY_Vcpe_cam_offsets(value,size)                                Rte_Write_P_Vcpe_cam_offsets_Vcpe_cam_offsets(&value)
#define vidGET_ARRAY_Vcpe_cam_offsets(variable,size)                             Rte_Read_R_Vcpe_cam_offsets_Vcpe_cam_offsets(&variable)

#define vidSET_ARRAY_ELEMENT_Vcpe_cam_offsets(variable,pos) \
{ \
  if (pos < 4)\
  {\
    uint16 datatemp[4];\
    Rte_Read_R_Vcpe_cam_offsets_Vcpe_cam_offsets(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_Vcpe_cam_offsets_Vcpe_cam_offsets(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_Vcpe_cam_offsets(variable,pos) \
{ \
  if (pos < 4)\
  { \
     uint16 datatemp[4];\
     Rte_Read_R_Vcpe_cam_offsets_Vcpe_cam_offsets(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array Vcpi_cam_offsets
  **********************************************************************************/

#define vidSET_ARRAY_Vcpi_cam_offsets(value,size)                                Rte_Write_P_Vcpi_cam_offsets_Vcpi_cam_offsets(&value)
#define vidGET_ARRAY_Vcpi_cam_offsets(variable,size)                             Rte_Read_R_Vcpi_cam_offsets_Vcpi_cam_offsets(&variable)

#define vidSET_ARRAY_ELEMENT_Vcpi_cam_offsets(variable,pos) \
{ \
  if (pos < 4)\
  {\
    uint16 datatemp[4];\
    Rte_Read_R_Vcpi_cam_offsets_Vcpi_cam_offsets(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_Vcpi_cam_offsets_Vcpi_cam_offsets(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_Vcpi_cam_offsets(variable,pos) \
{ \
  if (pos < 4)\
  { \
     uint16 datatemp[4];\
     Rte_Read_R_Vcpi_cam_offsets_Vcpi_cam_offsets(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable Veh_bHeatReq
  **********************************************************************************/

#define vidSET_VALUE_Veh_bHeatReq(value)                                         Rte_Write_P_Veh_bHeatReq_Veh_bHeatReq(value)
#define vidGET_VALUE_Veh_bHeatReq(variable)                                      Rte_Read_R_Veh_bHeatReq_Veh_bHeatReq(&variable)

/**********************************************************************************
   Create interface for variable Veh_bRunVeh
  **********************************************************************************/

#define vidSET_VALUE_Veh_bRunVeh(value)                                          Rte_Write_P_Veh_bRunVeh_Veh_bRunVeh(value)
#define vidGET_VALUE_Veh_bRunVeh(variable)                                       Rte_Read_R_Veh_bRunVeh_Veh_bRunVeh(&variable)

/**********************************************************************************
   Create interface for variable Veh_spdVeh
  **********************************************************************************/

#define vidSET_VALUE_Veh_spdVeh(value)                                           Rte_Write_P_Veh_spdVeh_Veh_spdVeh(value)
#define vidGET_VALUE_Veh_spdVeh(variable)                                        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&variable)

/**********************************************************************************
   Create interface for variable Veh_stDrvAvl
  **********************************************************************************/

#define vidSET_VALUE_Veh_stDrvAvl(value)                                         Rte_Write_P_Veh_stDrvAvl_Veh_stDrvAvl(value)
#define vidGET_VALUE_Veh_stDrvAvl(variable)                                      Rte_Read_R_Veh_stDrvAvl_Veh_stDrvAvl(&variable)

/**********************************************************************************
   Create interface for variable VlvAct_bAcvExServo
  **********************************************************************************/

#define vidSET_VALUE_VlvAct_bAcvExServo(value)                                   Rte_Write_P_VlvAct_bAcvExServo_VlvAct_bAcvExServo(value)
#define vidGET_VALUE_VlvAct_bAcvExServo(variable)                                Rte_Read_R_VlvAct_bAcvExServo_VlvAct_bAcvExServo(&variable)

/**********************************************************************************
   Create interface for variable VlvAct_bAcvInServo
  **********************************************************************************/

#define vidSET_VALUE_VlvAct_bAcvInServo(value)                                   Rte_Write_P_VlvAct_bAcvInServo_VlvAct_bAcvInServo(value)
#define vidGET_VALUE_VlvAct_bAcvInServo(variable)                                Rte_Read_R_VlvAct_bAcvInServo_VlvAct_bAcvInServo(&variable)

/**********************************************************************************
   Create interface for variable VlvAct_bInhDiagPresScav
  **********************************************************************************/

#define vidSET_VALUE_VlvAct_bInhDiagPresScav(value)                              Rte_Write_P_VlvAct_bInhDiagPresScav_VlvAct_bInhDiagPresScav(value)
#define vidGET_VALUE_VlvAct_bInhDiagPresScav(variable)                           Rte_Read_R_VlvAct_bInhDiagPresScav_VlvAct_bInhDiagPresScav(&variable)

/**********************************************************************************
   Create interface for array VlvAct_prm_agCkClsExVlvBol
  **********************************************************************************/

#define vidSET_ARRAY_VlvAct_prm_agCkClsExVlvBol(value,size)                      Rte_Write_P_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol(&value)
#define vidGET_ARRAY_VlvAct_prm_agCkClsExVlvBol(variable,size)                   Rte_Read_R_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol(&variable)

#define vidSET_ARRAY_ELEMENT_VlvAct_prm_agCkClsExVlvBol(variable,pos) \
{ \
  if (pos < 4)\
  {\
    DT_VlvAct_prm_agCkClsExVlvBol datatemp[4];\
    Rte_Read_R_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_VlvAct_prm_agCkClsExVlvBol(variable,pos) \
{ \
  if (pos < 4)\
  { \
     DT_VlvAct_prm_agCkClsExVlvBol datatemp[4];\
     Rte_Read_R_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for array VlvAct_prm_agCkOpInVlvBol
  **********************************************************************************/

#define vidSET_ARRAY_VlvAct_prm_agCkOpInVlvBol(value,size)                       Rte_Write_P_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol(&value)
#define vidGET_ARRAY_VlvAct_prm_agCkOpInVlvBol(variable,size)                    Rte_Read_R_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol(&variable)

#define vidSET_ARRAY_ELEMENT_VlvAct_prm_agCkOpInVlvBol(variable,pos) \
{ \
  if (pos < 4)\
  {\
    DT_VlvAct_prm_agCkOpInVlvBol datatemp[4];\
    Rte_Read_R_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol(&datatemp);\
    datatemp[pos] = variable;\
    Rte_Write_P_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol(&datatemp);\
  } else {\
       SWFAIL_vidSoftwareErrorHook();\
  }\
}

#define vidGET_ARRAY_ELEMENT_VlvAct_prm_agCkOpInVlvBol(variable,pos) \
{ \
  if (pos < 4)\
  { \
     DT_VlvAct_prm_agCkOpInVlvBol datatemp[4];\
     Rte_Read_R_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol(&datatemp);\
     variable = datatemp[pos];\
  } else { \
     SWFAIL_vidSoftwareErrorHook();\
  } \
}


/**********************************************************************************
   Create interface for variable VlvSys_agCkClsExVlvReqRef0
  **********************************************************************************/

#define vidSET_VALUE_VlvSys_agCkClsExVlvReqRef0(value)                           Rte_Write_P_VlvSys_agCkClsExVlvReqRef0_VlvSys_agCkClsExVlvReqRef0(value)
#define vidGET_VALUE_VlvSys_agCkClsExVlvReqRef0(variable)                        Rte_Read_R_VlvSys_agCkClsExVlvReqRef0_VlvSys_agCkClsExVlvReqRef0(&variable)

/**********************************************************************************
   Create interface for variable VlvSys_agCkClsExVlvSatCorReq
  **********************************************************************************/

#define vidSET_VALUE_VlvSys_agCkClsExVlvSatCorReq(value)                         Rte_Write_P_VlvSys_agCkClsExVlvSatCorReq_VlvSys_agCkClsExVlvSatCorReq(value)
#define vidGET_VALUE_VlvSys_agCkClsExVlvSatCorReq(variable)                      Rte_Read_R_VlvSys_agCkClsExVlvSatCorReq_VlvSys_agCkClsExVlvSatCorReq(&variable)

/**********************************************************************************
   Create interface for variable VlvSys_agCkOpInVlvReqRef0
  **********************************************************************************/

#define vidSET_VALUE_VlvSys_agCkOpInVlvReqRef0(value)                            Rte_Write_P_VlvSys_agCkOpInVlvReqRef0_VlvSys_agCkOpInVlvReqRef0(value)
#define vidGET_VALUE_VlvSys_agCkOpInVlvReqRef0(variable)                         Rte_Read_R_VlvSys_agCkOpInVlvReqRef0_VlvSys_agCkOpInVlvReqRef0(&variable)

/**********************************************************************************
   Create interface for variable VlvSys_agCkOpInVlvSatCorReq
  **********************************************************************************/

#define vidSET_VALUE_VlvSys_agCkOpInVlvSatCorReq(value)                          Rte_Write_P_VlvSys_agCkOpInVlvSatCorReq_VlvSys_agCkOpInVlvSatCorReq(value)
#define vidGET_VALUE_VlvSys_agCkOpInVlvSatCorReq(variable)                       Rte_Read_R_VlvSys_agCkOpInVlvSatCorReq_VlvSys_agCkOpInVlvSatCorReq(&variable)

/**********************************************************************************
   Create interface for variable WgCmd_DutyCycTrbAct_rCtl
  **********************************************************************************/

#define vidSET_VALUE_WgCmd_DutyCycTrbAct_rCtl(value)                             Rte_Write_P_WgCmd_DutyCycTrbAct_rCtl_WgCmd_DutyCycTrbAct_rCtl(value)
#define vidGET_VALUE_WgCmd_DutyCycTrbAct_rCtl(variable)                          Rte_Read_R_WgCmd_DutyCycTrbAct_rCtl_WgCmd_DutyCycTrbAct_rCtl(&variable)

/**********************************************************************************
   Create interface for variable WgcCmd_frqTrbAct_rCtl
  **********************************************************************************/

#define vidSET_VALUE_WgcCmd_frqTrbAct_rCtl(value)                                Rte_Write_P_WgcCmd_frqTrbAct_rCtl_WgcCmd_frqTrbAct_rCtl(value)
#define vidGET_VALUE_WgcCmd_frqTrbAct_rCtl(variable)                             Rte_Read_R_WgcCmd_frqTrbAct_rCtl_WgcCmd_frqTrbAct_rCtl(&variable)

/**********************************************************************************
                                   Fin de fichier
 **********************************************************************************/

#endif
