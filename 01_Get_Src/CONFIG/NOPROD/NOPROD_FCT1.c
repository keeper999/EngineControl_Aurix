/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : NOPROD                                                  */
/*                                                                            */
/* !Module          : NOPROD                                                  */
/* !Description     : Génération des variables non produites                  */
/*                                                                            */
/* !File            : NOPROD_FCT1.C                                           */
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
/*   1 / NOPROD_vidReset                                                      */
/*   2 / NOPROD_vidUpdate                                                     */
/*   3 / NOPROD_PointeurFonctionNull                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5076350 / 21                                        */
/* !OtherRefs   : VEMS V02 ECU#067902                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/NOPROD/noprod_fct1.c_v     $*/
/* $Revision::   1.30     $$Author::   croche2        $$Date::   08 Jul 2014 $*/
/* $Author::   croche2                                $$Date::   08 Jul 2014 $*/
/******************************************************************************/
/* Code généré automatiquement le <02/01/2014> par Hiro <4.1>                 */
/******************************************************************************/
#include "NOPROD.h"
#include "NOPROD_L.h"
#include "VEMS.h"
#include "STD_TYPES.h"

#include "Krn_asw.h"
#include "MCWDG_Typ.H"
#include "OS.h"
#include "PduR_Types.h"
#include "RTE_TYPE.h"
#include "SAIMMO_L.H"
#include "WDGM.H"
#include "InjSysMgrCrk.h"
#include "InjCutOffMgr.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NOPROD_vidReset                                            */
/* !Description :  initialise  les variables qui ne sont initialisées qu’au   */
/*                 RESET. D’une manière générale il s’agit de variable        */
/*                 bouchonnées qui n’ont pas besoin d’être modifiables par    */
/*                 calibration.                                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Code Généré                                                */
/*                                                                            */
/******************************************************************************/
void NOPROD_vidReset(void)
{
   sint16   aSint16LocalVar1[6] = {0,0,0,0,0,0};
   uint16   aUint16LocalVar2[5] = {0,0,0,0,0};
   sint16   aUint16LocalVar4[4] = {0,0,0,0};
   // uint16   aUint16LocalVar5[6] = {4096,4096,4096,4096,4096,4096};
   uint16   aUint16LocalVar51[6] = {1,1,1,1,1,1};
   uint16   aUint16LocalVar3[4] = {0,0,0,0};
   boolean  abooleanLocalVar6[4] = {0,0,0,0};

   /* YAGO STUB START */
   uint16 Ext_uBatt_A[9] = { 254U, 297U, 339U, 381U, 424U, 466U, 508U, 551U, 593U };

   VEMS_vidSET(Dena_composant_bpm,0);
   VEMS_vidSET(Dena_surcharge_bpm,0);
   VEMS_vidSET(Dft_composant_bpm,0);
   VEMS_vidSET(Dft_surcharge_bpm,0);

   VEMS_vidSET(Diag_elec_ectdrv,0);
   VEMS_vidSET(Acquisition_etat_gmvC,0);
   VEMS_vidSET(Dena_oc_driver_GMV1,0);
   VEMS_vidSET(Dena_oc_driver_GMV2,0);
   VEMS_vidSET(Dena_scg_driver_GMV1,0);
   VEMS_vidSET(Dena_scg_driver_GMV2,0);
   VEMS_vidSET(Dena_scp_driver_GMV1,0);
   VEMS_vidSET(Dena_scp_driver_GMV2,0);
   VEMS_vidSET(Dft_oc_driver_GMV1,0);
   VEMS_vidSET(Dft_oc_driver_GMV2,0);
   VEMS_vidSET(Dft_scg_driver_GMV1,0);
   VEMS_vidSET(Dft_scg_driver_GMV2,0);
   VEMS_vidSET(Dft_scp_driver_GMV1,0);
   VEMS_vidSET(Dft_scp_driver_GMV2,0);

   VEMS_vidSET(Dena_oc_driver_vvt_ech,0);
   VEMS_vidSET(Dena_scg_driver_vvt_ech,0);
   VEMS_vidSET(Dena_scp_driver_vvt_ech,0);
   VEMS_vidSET(Dft_oc_driver_vvt_ech,0);
   VEMS_vidSET(Dft_scg_driver_vvt_ech,0);
   VEMS_vidSET(Dft_scp_driver_vvt_ech,0);
   VEMS_vidSET(Dena_oc_driver_vvt_adm,0);
   VEMS_vidSET(Dena_scg_driver_vvt_adm,0);
   VEMS_vidSET(Dena_scp_driver_vvt_adm,0);
   VEMS_vidSET(Dft_oc_driver_vvt_adm,0);
   VEMS_vidSET(Dft_scg_driver_vvt_adm,0);
   VEMS_vidSET(Dft_scp_driver_vvt_adm,0);
   
   VEMS_vidSET(Dena_oc_cmd_dmtr,0);
   VEMS_vidSET(Dena_scg_cmd_dmtr,0);
   VEMS_vidSET(Dena_scp_cmd_dmtr,0);
   VEMS_vidSET(Dft_oc_cmd_dmtr,0);
   VEMS_vidSET(Dft_scg_cmd_dmtr,0);
   VEMS_vidSET(Dft_scp_cmd_dmtr,0);

   // VEMS_vidSET(Acq_spg_pres_measured,0);
   VEMS_vidSET(Autorise_detection_rbl,0);
   VEMS_vidSET(Debut_fenetre_rumble,0);
   // VEMS_vidSET(Ext_bOilPresProp,0);
   // VEMS_vidSET(Ext_bRawOilPresProp,0);
   // VEMS_vidSET(Ext_pOilMesRaw,0);
   // VEMS_vidSET(Ext_uEngOilLvl,0);
   VEMS_vidSET(Ext_upOilMes,0);
   // VEMS_vidSET(Oil_Pres_alertProp,0);
   VEMS_vidSET1DArray(Detection_rbl,4,abooleanLocalVar6);
   VEMS_vidSET1DArray(KnkMgt_bSuperKnkDet,4,abooleanLocalVar6);
   VEMS_vidSET1DArray(KnkMgt_ctInjCutOffRbl,4,aUint16LocalVar3);
   VEMS_vidSET1DArray(KnkMgt_prm_bInjCutOffRblCyl,4,abooleanLocalVar6);

   // VEMS_vidSET(CTP_bActrTstCmpl,0);
   // VEMS_vidSET(CTP_bDft1dActrTst,0);
   // VEMS_vidSET(CTP_bDft2dActrTst,0);
   VEMS_vidSET(Ext_pFuRailSplMes,0);
   VEMS_vidSET(Ext_pFuMesWRV,0);
   VEMS_vidSET(Ext_pFuRailMes,0);
   VEMS_vidSET(Ext_pFuRailMesRef,0);
   VEMS_vidSET(Ext_upFuMes,0);
   // VEMS_vidSET(Meap_bActrTstCmpl,0);
   // VEMS_vidSET(Meap_bFlapBlockOp,0);
   // VEMS_vidSET(Meap_bFlapFaild,0);
   // VEMS_vidSET(Meap_bFlapStayOp,0);
   VEMS_vidSET(PFuAcq_pFuRailMes,0);
   // VEMS_vidSET(SenAct_tECUAcq,0);
   // VEMS_vidSET(ThMgt_bTrbWaPmpTstCmpl,0);
   // VEMS_vidSET(ThMgt_stPosnFSF,0);

   VEMS_vidSET(Dena_oc_sortielogiquedml,0);
   VEMS_vidSET(Dena_scg_sortielogiquedml,0);
   VEMS_vidSET(Dena_scp_sortielogiquedml,0);
   VEMS_vidSET(Dft_oc_sortielogiquedml,0);
   VEMS_vidSET(Dft_scg_sortielogiquedml,0);
   VEMS_vidSET(Dft_scp_sortielogiquedml,0);
   VEMS_vidSET(Dena_oc_rechauffeurblowby1,0);
   VEMS_vidSET(Dena_oc_rechauffeurblowby2,0);
   VEMS_vidSET(Dena_scg_rechauffeurblowby1,0);
   VEMS_vidSET(Dena_scg_rechauffeurblowby2,0);
   VEMS_vidSET(Dena_scw_rechauffeurblowby1,0);
   VEMS_vidSET(Dena_scw_rechauffeurblowby2,0);
   VEMS_vidSET(Dft_oc_rechauffeurblowby1,0);
   VEMS_vidSET(Dft_oc_rechauffeurblowby2,0);
   VEMS_vidSET(Dft_scg_rechauffeurblowby1,0);
   VEMS_vidSET(Dft_scg_rechauffeurblowby2,0);
   VEMS_vidSET(Dft_scw_rechauffeurblowby1,0);
   VEMS_vidSET(Dft_scw_rechauffeurblowby2,0);

   VEMS_vidSET(Dena_oc_pompe_ess_pwm,0);
   VEMS_vidSET(Dena_scg_pompe_ess_pwm,0);
   VEMS_vidSET(Dena_scp_pompe_ess_pwm,0);
   VEMS_vidSET(Dft_oc_pompe_ess_pwm,0);
   VEMS_vidSET(Dft_scg_pompe_ess_pwm,0);
   VEMS_vidSET(Dft_scp_pompe_ess_pwm,0);

   VEMS_vidSET(Dena_oc_cmdautoredemstt,0);
   VEMS_vidSET(Dena_scg_cmdautoredemstt,0);
   VEMS_vidSET(Dena_scp_cmdautoredemstt,0);
   VEMS_vidSET(Dft_oc_cmdautoredemstt,0);
   VEMS_vidSET(Dft_scg_cmdautoredemstt,0);
   VEMS_vidSET(Dft_scp_cmdautoredemstt,0);
   VEMS_vidSET(Dena_oc_infomoteurtournant,0);
   VEMS_vidSET(Dena_scg_infomoteurtournant,0);
   VEMS_vidSET(Dena_scp_infomoteurtournant,0);
   VEMS_vidSET(Dft_oc_infomoteurtournant,0);
   VEMS_vidSET(Dft_scg_infomoteurtournant,0);
   VEMS_vidSET(Dft_scp_infomoteurtournant,0);
   VEMS_vidSET(AccP_bHdPtSen,0);

   VEMS_vidSET(Bvmp_fco_request,0);
   VEMS_vidSET(Disable_inj_for_anti_flood,0);
   VEMS_vidSET(FuSysM_tFuUsPmp,0);
   VEMS_vidSET(InjSys_bAcvCllRailDcha,0);
   VEMS_vidSET(InjSys_bCanPurgCutOff,0);
   // VEMS_vidSET(InjSys_bInhInjCutOffPFuDcha,0);
   VEMS_vidSET(InjSys_bInjSpNotAccu,0);
   VEMS_vidSET(InjSys_facFuTranCor,0);
   VEMS_vidSET(InjSys_noInjPat,0);
   VEMS_vidSET(InjSys_pFuSp,0);
   // VEMS_vidSET(InjSys_rInj1Sp,0);
   // VEMS_vidSET(InjSys_rInj2Sp,0);
   // VEMS_vidSET(InjSys_rInj3Sp,0);
   // VEMS_vidSET(Inj_bInj1TstCmpl,0);
   // VEMS_vidSET(Inj_bInj2TstCmpl,0);
   // VEMS_vidSET(Inj_bInj3TstCmpl,0);
   // VEMS_vidSET(Inj_bInj4TstCmpl,0);
   VEMS_vidSET(Inj_bInjTestDone,0);
   VEMS_vidSET(InjrSys_mFuInjEstim,0);
   VEMS_vidSET(TrbAct_pUsThrFil,0);
   VEMS_vidSET(AirSys_mfAirThrReqFil,0);
   // VEMS_vidSET(AirSys_pUsThrReq,0);
   VEMS_vidSET(TrbAct_rRCOReq,0);
   VEMS_vidSET(AirSys_bAcvFrzMod,0);
   VEMS_vidSET1DArray(InjrSys_prm_tiInjH1ReqCyl,6,aUint16LocalVar51);
   VEMS_vidSET1DArray(InjrSys_prm_tiInjH2ReqCyl,6,aUint16LocalVar51);
   VEMS_vidSET1DArray(InjrSys_prm_tiInjS1ReqCyl,6,aUint16LocalVar51);
   VEMS_vidSET1DArray(InjrSys_prm_tiInjS2ReqCyl,6,aUint16LocalVar51);

   VEMS_vidSET(Dena_oc_drvrseno2ds,0);
   VEMS_vidSET(Dena_oc_drvrseno2us,0);
   VEMS_vidSET(Dena_oc_relais_puissance,0);
   VEMS_vidSET(Dena_scg_drvrseno2ds,0);
   VEMS_vidSET(Dena_scg_drvrseno2us,0);
   VEMS_vidSET(Dena_scg_relais_puissance,0);
   VEMS_vidSET(Dena_scp_relais_puissance,0);
   VEMS_vidSET(Dena_scw_drvrseno2ds,0);
   VEMS_vidSET(Dena_scw_drvrseno2us,0);
   VEMS_vidSET(Dft_oc_cmd_relais_principal,0);
   VEMS_vidSET(Dft_oc_drvrseno2ds,0);
   VEMS_vidSET(Dft_oc_drvrseno2us,0);
   VEMS_vidSET(Dft_oc_relais_puissance,0);
   VEMS_vidSET(Dft_scg_cmd_relais_principal,0);
   VEMS_vidSET(Dft_scg_drvrseno2ds,0);
   VEMS_vidSET(Dft_scg_drvrseno2us,0);
   VEMS_vidSET(Dft_scg_relais_puissance,0);
   VEMS_vidSET(Dft_scp_cmd_relais_principal,0);
   VEMS_vidSET(Dft_scp_relais_puissance,0);
   VEMS_vidSET(Dft_scw_drvrseno2ds,0);
   VEMS_vidSET(Dft_scw_drvrseno2us,0);

   VEMS_vidSET(Acquis_tension_press_refri,0);
   VEMS_vidSET(Cf_bAcvLnrClimSenAcq,0);
   VEMS_vidSET(Dena_oc_cstrdrv,0);
   VEMS_vidSET(Dena_scg_cstrdrv,0);
   VEMS_vidSET(Dena_scw_cstrdrv,0);
   VEMS_vidSET(Dft_oc_cstrdrv,0);
   VEMS_vidSET(Dft_scg_cstrdrv,0);
   VEMS_vidSET(Dft_scw_cstrdrv,0);
   VEMS_vidSET(Cf_bAcvLnrClimSenAcq,0);
   // VEMS_vidSET(Wg_rAcvWgcCmdAppld,0);
   VEMS_vidSET(PFuCtl_tiBeg2PulseDif,0);
   VEMS_vidSET(PFuCtl_tiPmpCmdDecelReq,0);
   VEMS_vidSET(PFuCtl_tiPmpCmdReq,0);
   VEMS_vidSET(PFuCtl_agPmpCmdReq,0);
   // VEMS_vidSET(Ext_bStoHPPmpActCmd,0);
   // VEMS_vidSET(Wg_bTestTrbTstCmpl,0);
   VEMS_vidSET(ActrTstHPPmp_bActrTstCmpl,0);
   // VEMS_vidSET(DmpVlv_bActrTstCmpl,0);
   VEMS_vidSET(ActrTstHPPmp_bPrailLeak,0);
   // VEMS_vidSET(Wg_bGapActrTst,0);
   // VEMS_vidSET(Wg_bDynActrTst,0);
   VEMS_vidSET(ActrTstHPPmp_bPrailPresIncFail,0);
   // VEMS_vidSET(ActrTstHPPmp_bActrTstInProgs,0);
   VEMS_vidSET(PFuCtl_agPmpCmdEfcReq,0);
   VEMS_vidSET(PFuCtl_NrProfCmd,0);
   // VEMS_vidSET(DmpVlvAct_rDmpVlvOplCmdSp,0);
   VEMS_vidSET(BoostAct_rDuCyReq,0);
   VEMS_vidSET(BoostAct_rDuCyReqWoutSat,0);   
   // VEMS_vidSET(PFuCtl_mFuPmpEstim,0);
   //VEMS_vidSET(PFuCtl_agWdPmpCmdMax_C,0);
   //VEMS_vidSET1DArray(Ext_uBatt_A,9,Ext_uBatt_A_LocVar);
   /* YAGO STUB END */
   VEMS_vidSET(Cipd_phase_calculated_uncertain,FALSE);
   VEMS_vidSET(Flex_alc_rate_diag_run_uavb0,FALSE);
   VEMS_vidSET(IgSys_facTarAgCorGas,256);
   VEMS_vidSET(Egr_relative_needle_pos,0);
   VEMS_vidSET(Lambda_fb_for_saf_diag_thresh,0);
   VEMS_vidSET(Sync_bAcvSyncBUMCamShaft,FALSE);
   VEMS_vidSET(Ext_bGasQly,FALSE);
   VEMS_vidSET(Cipd_phase_terminated,FALSE);
   VEMS_vidSET(Delta_lam_gaz,0);
   VEMS_vidSET(Flev_low_gas_level,FALSE);
   VEMS_vidSET(ActrTstHPPmp_bInjrFlowFail,FALSE);
   VEMS_vidSET(Aux_air_pump_disabled,TRUE);
   VEMS_vidSET(IgSys_facTarAgCorFlex,256);
   VEMS_vidSET(Ext_bInhTqSysOvb,FALSE);
   VEMS_vidSET(Saf_status,SAF_DISABLED_NOT_IN_RUNNING);
   VEMS_vidSET(Delta_sonde_aval_gaz,0);
   VEMS_vidSET(LSA_lamUsMes,0);
   VEMS_vidSET(DmgBelt_noEngStrt,0);
   VEMS_vidSET(Compteur_de_pmh_raw,0);
   VEMS_vidSET(Cipd_bAgDifPha,FALSE);
   VEMS_vidSET(Ecut_ecu_temperature,65);
   VEMS_vidSET(GasMgt_stTranTypIp,0);
   VEMS_vidSET(Ext_iBrutMesOilPmp,0);
   VEMS_vidSET(Saf_diag_request,FALSE);
   VEMS_vidSET(Ext_bAuthInj,FALSE);
   VEMS_vidSET(IgSys_rMinThermoIgEfc,0);
   VEMS_vidSET(AC_bACCluDem,TRUE);
   VEMS_vidSET(Afa_panne_presente_adapt_inj,FALSE);
   VEMS_vidSET(Flex_alc_rate_est_needed_uavb0,FALSE);
   VEMS_vidSET(Ext_bStHaltElPmpGrp,FALSE);
   VEMS_vidSET1DArray(InjSys_InjClsRespCor_prmtiOfsH1,6,aSint16LocalVar1);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NOPROD_vidUpdate                                           */
/* !Description :  la production de variables nécessitant la possibilité      */
/*                 d’être « by-passées » par calibration, ce  qui implique une*/
/*                 mise à jour temporelle.                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Code Généré                                                */
/*                                                                            */
/******************************************************************************/
void NOPROD_vidUpdate(void)
{
   VEMS_vidSET(CoPt_tqAirReqGBx,CoPt_tqAirReqGBx_BypC);
   VEMS_vidSET(CoPt_tqReqGBx,CoPt_tqReqGBx_BypC);
   VEMS_vidSET(FARSp_rMixtSpAntiStall,FARSp_rMixtSpAntiStall_BypC);
   VEMS_vidSET(EngReqH_bInhLrnAFA,EngReqH_bInhLrnAFA_BypC);
   VEMS_vidSET(ISCAN_u8Compteur_RX_26C,ISCAN_u8Compteur_RX_26C_BypC);
   VEMS_vidSET(Ext_rSpdFanPredC,Ext_rSpdFanPredC_BypC);
   VEMS_vidSET(NORIA_bNEngAftsReq,NORIA_bNEngAftsReq_BypC);
   VEMS_vidSET(CoPt_bTarIdlInc,CoPt_bTarIdlInc_BypC);
   VEMS_vidSET(Lbda_step_rich_non_idle_flex,Lbda_step_rich_non_idle_fle_BypC);
   VEMS_vidSET(UCE_bLINComNd,UCE_bLINComNd_BypC);
   VEMS_vidSET(Ext_rSpdFanPredB2,Ext_rSpdFanPredB2_BypC);
   VEMS_vidSET(Ext_bCfDiagBit3StDftOBD,Ext_bCfDiagBit3StDftOBD_BypC);
   VEMS_vidSET(VSCtl_bKdAuthVSLim,VSCtl_bKdAuthVSLim_BypC);
   VEMS_vidSET(PredEs_nFastPred,PredEs_nFastPred_BypC);
   VEMS_vidSET(Ext_bAcvProtBrk,Ext_bAcvProtBrk_BypC);
   VEMS_vidSET(Lbda_maint_att_dly_pond_flex,Lbda_maint_att_dly_pond_fle_BypC);
   VEMS_vidSET(InjSys_facStoichAdpFlex,InjSys_facStoichAdpFlex_BypC);
   VEMS_vidSET(Gear_bRvsFil,Gear_bRvsFil_BypC);
   VEMS_vidSET(Cat_seuil_obd_flex,Cat_seuil_obd_flex_BypC);
   VEMS_vidSET(Ext_stECUMiss,Ext_stECUMiss_BypC);
   VEMS_vidSET(Afts_nTarIdlHybMod,Afts_nTarIdlHybMod_BypC);
   VEMS_vidSET(TqSys_nTarIdlGBxMin,TqSys_nTarIdlGBxMin_BypC);
   VEMS_vidSET(Flex_bInhDiagOBDAlcRate,Flex_bInhDiagOBDAlcRate_BypC);
   VEMS_vidSET(Cl_presence_clim_bsi,Cl_presence_clim_bsi_BypC);
   VEMS_vidSET(PredEs_bVldAgEsPred,PredEs_bVldAgEsPred_BypC);
   VEMS_vidSET(Tde_torque_correction,Tde_torque_correction_BypC);
   VEMS_vidSET(WaPmp_bAcvWaPmp,WaPmp_bAcvWaPmp_BypC);
   VEMS_vidSET(KnkTreat_bInhKnkDet,KnkTreat_bInhKnkDet_BypC);
   VEMS_vidSET(UCE_bCAN2ComNd,UCE_bCAN2ComNd_BypC);
   VEMS_vidSET(CoPTSt_bDgoSftyORngAM,CoPTSt_bDgoSftyORngAM_BypC);
   VEMS_vidSET(TqCmp_pwrAC5Loss,TqCmp_pwrAC5Loss_BypC);
   VEMS_vidSET(EngReqH_bInhCanPurg,EngReqH_bInhCanPurg_BypC);
   VEMS_vidSET(Lbda_lean_attenuation_gain_flex,Lbda_lean_attenuation_gain_BypC);
   VEMS_vidSET(Richesse_maximale_CMG,Richesse_maximale_CMG_BypC);
   VEMS_vidSET(AirSys_effCycFlex,AirSys_effCycFlex_BypC);
   VEMS_vidSET(FEI_bAcvNEngFEIAftsByp,FEI_bAcvNEngFEIAftsByp_BypC);
   VEMS_vidSET(PFlt_bAcvNTarIdlRgnAfts,PFlt_bAcvNTarIdlRgnAfts_BypC);
   VEMS_vidSET(Lffc_r_l_no_idle_dly_neuf_flx,Lffc_r_l_no_idle_dly_neuf_f_BypC);
   VEMS_vidSET(Lbda_lump_lean_non_idle_flex,Lbda_lump_lean_non_idle_fle_BypC);
   VEMS_vidSET(Cat_seuil_obd_pond_flex,Cat_seuil_obd_pond_flex_BypC);
   VEMS_vidSET(InjSys_facAstWupCmpAdpFlex,InjSys_facAstWupCmpAdpFlex_BypC);
   VEMS_vidSET(Lffc_l_r_no_idle_dly_neuf_flx,Lffc_l_r_no_idle_dly_neuf_f_BypC);
   VEMS_vidSET(FEI_nEngFEIAftsReq,FEI_nEngFEIAftsReq_BypC);
   VEMS_vidSET(Lbda_maintien_attenu_delay_flex,Lbda_maintien_attenu_delay_BypC);
   VEMS_vidSET(Flex_bInhDiagOBDBlby,Flex_bInhDiagOBDBlby_BypC);
   VEMS_vidSET(Lbda_lump_non_idle_pond_flex,Lbda_lump_non_idle_pond_fle_BypC);
   VEMS_vidSET(ISCAN_u8N2F50DPM1298,ISCAN_u8N2F50DPM1298_BypC);
   VEMS_vidSET(Ext_bCfDiagBit2StDftOBD,Ext_bCfDiagBit2StDftOBD_BypC);
   VEMS_vidSET(CoHVB_bMILReq,CoHVB_bMILReq_BypC);
   VEMS_vidSET(TqRes_bCdnAC5Res,TqRes_bCdnAC5Res_BypC);
   VEMS_vidSET(PaDyn_rBoostModSpt,PaDyn_rBoostModSpt_BypC);
   VEMS_vidSET(Ext_rCtlAltBSSCycOp,Ext_rCtlAltBSSCycOp_BypC);
   VEMS_vidSET(Lbda_step_non_idle_pond_flex,Lbda_step_non_idle_pond_fle_BypC);
   VEMS_vidSET(PredEs_agUncrtEsPred,PredEs_agUncrtEsPred_BypC);
   VEMS_vidSET(Tra_spdVeh_nEng1000,Tra_spdVeh_nEng1000_BypC);
   VEMS_vidSET(Lbda_attenuation_gain_pond_flex,Lbda_attenuation_gain_pond_BypC);
   VEMS_vidSET(CoCha_tqEfcMSRReq,CoCha_tqEfcMSRReq_BypC);
   VEMS_vidSET(AirSys_effEGRGas,AirSys_effEGRGas_BypC);
   VEMS_vidSET(Ctrl_noTarGear,Ctrl_noTarGear_BypC);
   VEMS_vidSET(Ctrl_bAcv_ECTReq,Ctrl_bAcv_ECTReq_BypC);
   VEMS_vidSET(DrvIf_stLevAuth,DrvIf_stLevAuth_BypC);
   VEMS_vidSET(Lbda_lump_rich_idle_flex,Lbda_lump_rich_idle_flex_BypC);
   VEMS_vidSET(TqSys_bAcvVlvSysOptmVac,TqSys_bAcvVlvSysOptmVac_BypC);
   VEMS_vidSET(Lbda_rich_attenuation_gain_flex,Lbda_rich_attenuation_gain_BypC);
   VEMS_vidSET(Lbda_lg_lump_lean_idle_flex,Lbda_lg_lump_lean_idle_flex_BypC);
   VEMS_vidSET(InjSys_facStrtCorFlex,InjSys_facStrtCorFlex_BypC);
   VEMS_vidSET(Lffc_non_idle_dly_pond_flex,Lffc_non_idle_dly_pond_flex_BypC);
   VEMS_vidSET(EGRVlv_rOpClsEGRVlvBol,EGRVlv_rOpClsEGRVlvBol_BypC);
   VEMS_vidSET(Flex_bInhDiagOBDAlcEst,Flex_bInhDiagOBDAlcEst_BypC);
   VEMS_vidSET(Lffc_l_r_no_idle_dly_emis_flx,Lffc_l_r_no_idle_dly_emis_f_BypC);
   VEMS_vidSET(TqSys_tqAdvAntiBoil,TqSys_tqAdvAntiBoil_BypC);
   VEMS_vidSET(TqSys_nTarIdlStrt,TqSys_nTarIdlStrt_BypC);
   VEMS_vidSET(Ext_stPwrSys2,Ext_stPwrSys2_BypC);
   VEMS_vidSET(Ext_bAcvSpcInjModProtECU,Ext_bAcvSpcInjModProtECU_BypC);
   VEMS_vidSET(Ext_bFlexCf,Ext_bFlexCf_BypC);
   VEMS_vidSET(UCE_bCAN3ComNd,UCE_bCAN3ComNd_BypC);
   VEMS_vidSET(InjSys_facInjResuAdpFlex,InjSys_facInjResuAdpFlex_BypC);
   VEMS_vidSET(TqSys_tqAdvOverSpdProt,TqSys_tqAdvOverSpdProt_BypC);
   VEMS_vidSET(GSI_stDrvTraSys,GSI_stDrvTraSys_BypC);
   VEMS_vidSET(Lbda_lump_lean_idle_flex,Lbda_lump_lean_idle_flex_BypC);
   VEMS_vidSET(Ext_rOpTrbActMesSI,Ext_rOpTrbActMesSI_BypC);
   VEMS_vidSET(Cf_bInhFlex,Cf_bInhFlex_BypC);
   VEMS_vidSET(Srv_bAcvExNormCln,Srv_bAcvExNormCln_BypC);
   VEMS_vidSET(Tpac_measured_current,Tpac_measured_current_BypC);
   VEMS_vidSET(TqSys_tqIniIdlReq,TqSys_tqIniIdlReq_BypC);
   VEMS_vidSET(Toil_power_latch,Toil_power_latch_BypC);
   VEMS_vidSET(PaDyn_pBoostModSpt,PaDyn_pBoostModSpt_BypC);
   VEMS_vidSET(TqSys_bIniIdlReq,TqSys_bIniIdlReq_BypC);
   VEMS_vidSET(Ext_bLiMILReqSCT,Ext_bLiMILReqSCT_BypC);
   VEMS_vidSET(TqSys_tqAirAntiBoil,TqSys_tqAirAntiBoil_BypC);
   VEMS_vidSET(Tpac_request_throttle_duty_cycle,Tpac_request_throttle_duty_BypC);
   VEMS_vidSET(CoPt_nTarIdl,CoPt_nTarIdl_BypC);
   VEMS_vidSET(TqRes_tqAC5Res,TqRes_tqAC5Res_BypC);
   VEMS_vidSET(Ext_tUcapMes,Ext_tUcapMes_BypC);
   VEMS_vidSET(AirSys_effCycGas,AirSys_effCycGas_BypC);
   VEMS_vidSET(EcuSt_bKeyOffForce,EcuSt_bKeyOffForce_BypC);
   VEMS_vidSET(NORIA_nEngAftsSp,NORIA_nEngAftsSp_BypC);
   VEMS_vidSET(Ext_iCurMes,Ext_iCurMes_BypC);
   VEMS_vidSET(TqRes_tqGasModRes,TqRes_tqGasModRes_BypC);
   VEMS_vidSET(Ext_iCtlAltBSSExct,Ext_iCtlAltBSSExct_BypC);
   VEMS_vidSET(Ext_bMILReqCntRstHCU2,Ext_bMILReqCntRstHCU2_BypC);
   VEMS_vidSET(Ext_stFuSpdCorbank2,Ext_stFuSpdCorbank2_BypC);
   VEMS_vidSET(Afts_nBypTarIdl,Afts_nBypTarIdl_BypC);
   VEMS_vidSET(Ext_bPostRunReq,Ext_bPostRunReq_BypC);
   VEMS_vidSET(PredEs_bVldFastNPred,PredEs_bVldFastNPred_BypC);
   VEMS_vidSET(Afts_stBypTarIdl,Afts_stBypTarIdl_BypC);
   VEMS_vidSET(TqCmp_tqLossExtSpc,TqCmp_tqLossExtSpc_BypC);
   VEMS_vidSET(SftyMgt_bDeacIrvVSReg,SftyMgt_bDeacIrvVSReg_BypC);
   VEMS_vidSET(Lbda_step_lean_non_idle_flex,Lbda_step_lean_non_idle_fle_BypC);
   VEMS_vidSET(AirSys_effEGRFlex,AirSys_effEGRFlex_BypC);
   VEMS_vidSET(AirMon_bEnaIdlCtlAftsDiag,AirMon_bEnaIdlCtlAftsDiag_BypC);
   VEMS_vidSET(TqSys_tqAirOverSpdProt,TqSys_tqAirOverSpdProt_BypC);
   VEMS_vidSET(InjSys_facStrtCorGas,InjSys_facStrtCorGas_BypC);
   VEMS_vidSET(Ext_TrbAct_rCtl_CurMes,Ext_TrbAct_rCtl_CurMes_BypC);
   VEMS_vidSET(Ext_bCfDiagBit4StDftOBD,Ext_bCfDiagBit4StDftOBD_BypC);
   VEMS_vidSET(TqSys_bSpcCmbSel,TqSys_bSpcCmbSel_BypC);
   VEMS_vidSET(Ext_bMILReqCntRstTBMU,Ext_bMILReqCntRstTBMU_BypC);
   VEMS_vidSET(Ext_bCfDiagBit7StDftOBD,Ext_bCfDiagBit7StDftOBD_BypC);
   VEMS_vidSET(Flev_low_fuel_level_fil,Flev_low_fuel_level_fil_BypC);
   VEMS_vidSET(Temps_injection_entre_pmh,Temps_injection_entre_pmh_BypC);
   VEMS_vidSET(Ext_bMILReqCntRstAR2S,Ext_bMILReqCntRstAR2S_BypC);
   VEMS_vidSET(Lbda_lg_lump_non_idle_flex,Lbda_lg_lump_non_idle_flex_BypC);
   VEMS_vidSET(Saf_power_latch,Saf_power_latch_BypC);
   VEMS_vidSET(Ext_stSysGas,Ext_stSysGas_BypC);
   VEMS_vidSET(EOM_bInhTqSysRich,EOM_bInhTqSysRich_BypC);
   VEMS_vidSET(Ext_bfMstPtlWkuHldReq,Ext_bfMstPtlWkuHldReq_BypC);
   VEMS_vidSET(PredEs_agEsPred,PredEs_agEsPred_BypC);
   VEMS_vidSET(Ext_bLiMILReqHCU2,Ext_bLiMILReqHCU2_BypC);
   VEMS_vidSET(Afts_bRstMemFirstFillFuEng,Afts_bRstMemFirstFillFuEng_BypC);
   VEMS_vidSET(Afts_bAcvHybMod_nTarIdl,Afts_bAcvHybMod_nTarIdl_BypC);
   VEMS_vidSET(TqSys_nTarIdlGBxMax,TqSys_nTarIdlGBxMax_BypC);
   VEMS_vidSET(Srv_bAcvVlvActNormCln,Srv_bAcvVlvActNormCln_BypC);
   VEMS_vidSET(Ext_rDuCyReqTestMod,Ext_rDuCyReqTestMod_BypC);
   VEMS_vidSET(Ext_bfMstPtlWkuNd,Ext_bfMstPtlWkuNd_BypC);
   VEMS_vidSET(Sync_bBackUpCkSig,Sync_bBackUpCkSig_BypC);
   VEMS_vidSET(Tra_tqReqClu,Tra_tqReqClu_BypC);
   VEMS_vidSET(TqSys_bInjCutProtAC,TqSys_bInjCutProtAC_BypC);
   VEMS_vidSET(PFlt_nTarIdlRgnAftsReq,PFlt_nTarIdlRgnAftsReq_BypC);
   VEMS_vidSET(Ctrl_IS_MAP_CMM_7A8,Ctrl_IS_MAP_CMM_7A8_BypC);
   VEMS_vidSET(Ext_idxCtlAltBSSProvIdf,Ext_idxCtlAltBSSProvIdf_BypC);
   VEMS_vidSET(Lbda_lg_lump_rich_idle_flex,Lbda_lg_lump_rich_idle_flex_BypC);
   VEMS_vidSET(Lffc_r_l_no_idle_dly_emis_flx,Lffc_r_l_no_idle_dly_emis_f_BypC);
   VEMS_vidSET(Ext_stAltClasBSSCf,Ext_stAltClasBSSCf_BypC);
   VEMS_vidSET(UCE_bCAN1ComNd,UCE_bCAN1ComNd_BypC);
   VEMS_vidSET(IdlSys_nSpcTarIdlDyn,IdlSys_nSpcTarIdlDyn_BypC);
   VEMS_vidSET(Ext_noSupvDTC,Ext_noSupvDTC_BypC);
   VEMS_vidSET(Lbda_lump_rich_non_idle_flex,Lbda_lump_rich_non_idle_fle_BypC);
   VEMS_vidSET(TqSys_facTranSpcAirSys,TqSys_facTranSpcAirSys_BypC);
   VEMS_vidSET(AirMon_nEngAftsDiag,AirMon_nEngAftsDiag_BypC);
   VEMS_vidSET(Cf_bRvsFilConf,Cf_bRvsFilConf_BypC);
   VEMS_vidSET1DArray(Srv_prm_nCornEngCyl1_eep,20,Srv_prm_nCornEngCyl1_eep_BypC);
   VEMS_vidSET1DArray(Srv_prm_nCornEngCyl3_eep,20,Srv_prm_nCornEngCyl3_eep_BypC);
   VEMS_vidSET1DArray(Srv_prm_nCornEngCyl2_eep,20,Srv_prm_nCornEngCyl2_eep_BypC);
   VEMS_vidSET1DArray(InjSys_prm_facGasResuCyl,6,InjSys_prm_facGasResuCyl_BypC);
   VEMS_vidSET1DArray(InjSys_prm_facFlexResuCyl,6,InjSys_prm_facFlexResuCyl_BypC);
   VEMS_vidSET1DArray(Ext_prm_idxFuTypCyl,6,Ext_prm_idxFuTypCyl_BypC);
   VEMS_vidSET1DArray(AirSys_prm_effAfrGas,3,AirSys_prm_effAfrGas_BypC);
   VEMS_vidSET1DArray(AirSys_prm_effAfrFlex,3,AirSys_prm_effAfrFlex_BypC);

   /*pour SBON ==> CAN ******/
	VEMS_vidSET(Ctrl_aLgtGearSen, Ctrl_aLgtGearSen_BypC);
	VEMS_vidSET(Ctrl_aVeh, Ctrl_aVeh_BypC);
	VEMS_vidSET(Ctrl_bABSReg, Ctrl_bABSReg_BypC);
	VEMS_vidSET(Ctrl_bAccPTra, Ctrl_bAccPTra_BypC);
	VEMS_vidSET(Ctrl_bAcv_bAcvElCnsReq, Ctrl_bAcv_bAcvElCnsReq_BypC);
	VEMS_vidSET(Ctrl_bAcv_bAcvSftyWarn, Ctrl_bAcv_bAcvSftyWarn_BypC);
	VEMS_vidSET(Ctrl_bAcv_bBrkPark, Ctrl_bAcv_bBrkPark_BypC);
	VEMS_vidSET(Ctrl_bAcv_bDftFctEM, Ctrl_bAcv_bDftFctEM_BypC);
	VEMS_vidSET(Ctrl_bAcv_bLiRegESPASR, Ctrl_bAcv_bLiRegESPASR_BypC);
	VEMS_vidSET(Ctrl_bAcv_bRCDLine, Ctrl_bAcv_bRCDLine_BypC);
	VEMS_vidSET(Ctrl_bAcv_ctClcProc3B8, Ctrl_bAcv_ctClcProc3B8_BypC);
	VEMS_vidSET(Ctrl_bAcv_dstVehTotMesIS552, Ctrl_bAcv_dstVehTotMesIS552_BypC);
	VEMS_vidSET(Ctrl_bAcv_dstVehTotMesIS7F2, Ctrl_bAcv_dstVehTotMesIS7F2_BypC);
	VEMS_vidSET(Ctrl_bAcv_grdNegSlop, Ctrl_bAcv_grdNegSlop_BypC);
	VEMS_vidSET(Ctrl_bAcv_grdPosSlop, Ctrl_bAcv_grdPosSlop_BypC);
	VEMS_vidSET(Ctrl_bAcv_noIdFrame, Ctrl_bAcv_noIdFrame_BypC);
	VEMS_vidSET(Ctrl_bAcv_noJDDKm, Ctrl_bAcv_noJDDKm_BypC);
	VEMS_vidSET(Ctrl_bAcv_noNEngCplm, Ctrl_bAcv_noNEngCplm_BypC);
	VEMS_vidSET(Ctrl_bAcv_noRatDrvReqCplm, Ctrl_bAcv_noRatDrvReqCplm_BypC);
	VEMS_vidSET(Ctrl_bAcv_noTqAirDrvFilCplm, Ctrl_bAcv_noTqAirDrvFilCplm_BypC);
	VEMS_vidSET(Ctrl_bAcv_noTqCkEngRealCplm, Ctrl_bAcv_noTqCkEngRealCplm_BypC);
	VEMS_vidSET(Ctrl_bAcv_noTqDrvFilCplm, Ctrl_bAcv_noTqDrvFilCplm_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVDS1, Ctrl_bAcv_noVDS1_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVDS2, Ctrl_bAcv_noVDS2_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVDS3, Ctrl_bAcv_noVDS3_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVDS4, Ctrl_bAcv_noVDS4_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVDS5, Ctrl_bAcv_noVDS5_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVDS6, Ctrl_bAcv_noVDS6_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS1, Ctrl_bAcv_noVIS1_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS2, Ctrl_bAcv_noVIS2_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS3, Ctrl_bAcv_noVIS3_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS4, Ctrl_bAcv_noVIS4_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS5, Ctrl_bAcv_noVIS5_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS6, Ctrl_bAcv_noVIS6_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS7, Ctrl_bAcv_noVIS7_BypC);
	VEMS_vidSET(Ctrl_bAcv_noVIS8, Ctrl_bAcv_noVIS8_BypC);
	VEMS_vidSET(Ctrl_bAcv_noWMI1, Ctrl_bAcv_noWMI1_BypC);
	VEMS_vidSET(Ctrl_bAcv_noWMI2, Ctrl_bAcv_noWMI2_BypC);
	VEMS_vidSET(Ctrl_bAcv_noWMI3, Ctrl_bAcv_noWMI3_BypC);
	VEMS_vidSET(Ctrl_bagStrWhl, Ctrl_bagStrWhl_BypC);
	VEMS_vidSET(Ctrl_bagvStrWhl, Ctrl_bagvStrWhl_BypC);
	VEMS_vidSET(Ctrl_bASRRegFirst, Ctrl_bASRRegFirst_BypC);
	VEMS_vidSET(Ctrl_bAuthCrawl, Ctrl_bAuthCrawl_BypC);
	VEMS_vidSET(Ctrl_bAuthWupElMgt, Ctrl_bAuthWupElMgt_BypC);
	VEMS_vidSET(Ctrl_bCmpReq, Ctrl_bCmpReq_BypC);
	VEMS_vidSET(Ctrl_bCntMILRst, Ctrl_bCntMILRst_BypC);
	VEMS_vidSET(Ctrl_bctClcProc305, Ctrl_bctClcProc305_BypC);
	VEMS_vidSET(Ctrl_bCtlEfc_tqWhlPt, Ctrl_bCtlEfc_tqWhlPt_BypC);
	VEMS_vidSET(Ctrl_bDelDftReq, Ctrl_bDelDftReq_BypC);
	VEMS_vidSET(Ctrl_bDft_bBrkPedPrss, Ctrl_bDft_bBrkPedPrss_BypC);
	VEMS_vidSET(Ctrl_bDft, Ctrl_bDft_BypC);
	VEMS_vidSET(Ctrl_bDgo_iBattMes, Ctrl_bDgo_iBattMes_BypC);
	VEMS_vidSET(Ctrl_bDgo_tBattMes, Ctrl_bDgo_tBattMes_BypC);
	VEMS_vidSET(Ctrl_bDgo_uBattClc, Ctrl_bDgo_uBattClc_BypC);
	VEMS_vidSET(Ctrl_bDiagMuxOn, Ctrl_bDiagMuxOn_BypC);
	VEMS_vidSET(Ctrl_bDrvCyGlbl, Ctrl_bDrvCyGlbl_BypC);
	VEMS_vidSET(Ctrl_bEHRWaPmpReqRTE, Ctrl_bEHRWaPmpReqRTE_BypC);
	VEMS_vidSET(Ctrl_bElIntgDiagMod, Ctrl_bElIntgDiagMod_BypC);
	VEMS_vidSET(Ctrl_bElIntgDiag, Ctrl_bElIntgDiag_BypC);
	VEMS_vidSET(Ctrl_bEngRStrtReqAsiDir, Ctrl_bEngRStrtReqAsiDir_BypC);
	VEMS_vidSET(Ctrl_bEngRStrtReqGBx, Ctrl_bEngRStrtReqGBx_BypC);
	VEMS_vidSET(Ctrl_bEngStopAuthAsiDir, Ctrl_bEngStopAuthAsiDir_BypC);
	VEMS_vidSET(Ctrl_bEngStopAuthGBx, Ctrl_bEngStopAuthGBx_BypC);
	VEMS_vidSET(Ctrl_bEngStopReq, Ctrl_bEngStopReq_BypC);
	VEMS_vidSET(Ctrl_bESPRegFirst, Ctrl_bESPRegFirst_BypC);
	VEMS_vidSET(Ctrl_bfAcvConstElMgt1, Ctrl_bfAcvConstElMgt1_BypC);
	VEMS_vidSET(Ctrl_bfAcvConstElMgt2, Ctrl_bfAcvConstElMgt2_BypC);
	VEMS_vidSET(Ctrl_bfAcvConstElMgt3, Ctrl_bfAcvConstElMgt3_BypC);
	VEMS_vidSET(Ctrl_bfAcvConstEm1, Ctrl_bfAcvConstEm1_BypC);
	VEMS_vidSET(Ctrl_bfAcvConstEng1, Ctrl_bfAcvConstEng1_BypC);
	VEMS_vidSET(Ctrl_bfAcvConstFrntTra1, Ctrl_bfAcvConstFrntTra1_BypC);
	VEMS_vidSET(Ctrl_bfAcvConstReTra1, Ctrl_bfAcvConstReTra1_BypC);
	VEMS_vidSET(Ctrl_bFlashLiMIL, Ctrl_bFlashLiMIL_BypC);
	VEMS_vidSET(Ctrl_bFrzAC, Ctrl_bFrzAC_BypC);
	VEMS_vidSET(Ctrl_bGBxRdy, Ctrl_bGBxRdy_BypC);
	VEMS_vidSET(Ctrl_bGearCtlFirst, Ctrl_bGearCtlFirst_BypC);
	VEMS_vidSET(Ctrl_bImmoUnlockWkuReq, Ctrl_bImmoUnlockWkuReq_BypC);
	VEMS_vidSET(Ctrl_bInhAcqESCFrnt, Ctrl_bInhAcqESCFrnt_BypC);
	VEMS_vidSET(Ctrl_bInhStrtAMT, Ctrl_bInhStrtAMT_BypC);
	VEMS_vidSET(Ctrl_bInhVSCtl, Ctrl_bInhVSCtl_BypC);
	VEMS_vidSET(Ctrl_bKeyON, Ctrl_bKeyON_BypC);
	VEMS_vidSET(Ctrl_bLevMod, Ctrl_bLevMod_BypC);
	VEMS_vidSET(Ctrl_bLiIMIL, Ctrl_bLiIMIL_BypC);
	VEMS_vidSET(Ctrl_bLiMILReq, Ctrl_bLiMILReq_BypC);
	VEMS_vidSET(Ctrl_bnoCks305, Ctrl_bnoCks305_BypC);
	VEMS_vidSET(Ctrl_bNRegReq, Ctrl_bNRegReq_BypC);
	VEMS_vidSET(Ctrl_bOBDDftOnMIL, Ctrl_bOBDDftOnMIL_BypC);
	VEMS_vidSET(Ctrl_bOilMesReq, Ctrl_bOilMesReq_BypC);
	VEMS_vidSET(Ctrl_bOilWkuReq, Ctrl_bOilWkuReq_BypC);
	VEMS_vidSET(Ctrl_bOpDrvTraReq, Ctrl_bOpDrvTraReq_BypC);
	VEMS_vidSET(Ctrl_bPrepIgEngWkuReq, Ctrl_bPrepIgEngWkuReq_BypC);
	VEMS_vidSET(Ctrl_bPresOilWarn, Ctrl_bPresOilWarn_BypC);
	VEMS_vidSET(Ctrl_bRStrtAuthTra, Ctrl_bRStrtAuthTra_BypC);
	VEMS_vidSET(Ctrl_bRstrtTypAT, Ctrl_bRstrtTypAT_BypC);
	VEMS_vidSET(Ctrl_bSecBrkPedPrssMes, Ctrl_bSecBrkPedPrssMes_BypC);
	VEMS_vidSET(Ctrl_bSIPPrep, Ctrl_bSIPPrep_BypC);
	VEMS_vidSET(Ctrl_bSIP, Ctrl_bSIP_BypC);
	VEMS_vidSET(Ctrl_bSpdFanGBxReq, Ctrl_bSpdFanGBxReq_BypC);
	VEMS_vidSET(Ctrl_bStaProt, Ctrl_bStaProt_BypC);
	VEMS_vidSET(Ctrl_bStopEngCoWkuReq, Ctrl_bStopEngCoWkuReq_BypC);
	VEMS_vidSET(Ctrl_bSTTDft, Ctrl_bSTTDft_BypC);
	VEMS_vidSET(Ctrl_bTqTx, Ctrl_bTqTx_BypC);
	VEMS_vidSET(Ctrl_bTraTqAuthRaw, Ctrl_bTraTqAuthRaw_BypC);
	VEMS_vidSET(Ctrl_bTypMsg, Ctrl_bTypMsg_BypC);
	VEMS_vidSET(Ctrl_bWarn_tCo, Ctrl_bWarn_tCo_BypC);
	VEMS_vidSET(Ctrl_bWUC, Ctrl_bWUC_BypC);
	VEMS_vidSET(Ctrl_ctClcProc329, Ctrl_ctClcProc329_BypC);
	VEMS_vidSET(Ctrl_ctClcProc349, Ctrl_ctClcProc349_BypC);
	VEMS_vidSET(Ctrl_ctClcProc34D, Ctrl_ctClcProc34D_BypC);
	VEMS_vidSET(Ctrl_ctClcProc38D, Ctrl_ctClcProc38D_BypC);
	VEMS_vidSET(Ctrl_ctClcProc3AD, Ctrl_ctClcProc3AD_BypC);
	VEMS_vidSET(Ctrl_ctClcProc3C9, Ctrl_ctClcProc3C9_BypC);
	VEMS_vidSET(Ctrl_ctDayCAN, Ctrl_ctDayCAN_BypC);
	VEMS_vidSET(Ctrl_CtRstCurVehTmr, Ctrl_CtRstCurVehTmr_BypC);
	VEMS_vidSET(Ctrl_ctSecCAN, Ctrl_ctSecCAN_BypC);
	VEMS_vidSET(Ctrl_ctYrCAN, Ctrl_ctYrCAN_BypC);
	VEMS_vidSET(Ctrl_dstCntGearSen, Ctrl_dstCntGearSen_BypC);
	VEMS_vidSET(Ctrl_iBattMaxCkg, Ctrl_iBattMaxCkg_BypC);
	VEMS_vidSET(Ctrl_idxPrfGBxMsg, Ctrl_idxPrfGBxMsg_BypC);
	VEMS_vidSET(Ctrl_idxPtSpt, Ctrl_idxPtSpt_BypC);
	VEMS_vidSET(Ctrl_mfAirMes, Ctrl_mfAirMes_BypC);
	VEMS_vidSET(Ctrl_nAvrFrntWhl, Ctrl_nAvrFrntWhl_BypC);
	VEMS_vidSET(Ctrl_nEngAvr, Ctrl_nEngAvr_BypC);
	VEMS_vidSET(Ctrl_nEngSpdMaxTq, Ctrl_nEngSpdMaxTq_BypC);
	VEMS_vidSET(Ctrl_nEng, Ctrl_nEng_BypC);
	VEMS_vidSET(Ctrl_noCks329, Ctrl_noCks329_BypC);
	VEMS_vidSET(Ctrl_noCks349, Ctrl_noCks349_BypC);
	VEMS_vidSET(Ctrl_noCks38D, Ctrl_noCks38D_BypC);
	VEMS_vidSET(Ctrl_noCks3AD, Ctrl_noCks3AD_BypC);
	VEMS_vidSET(Ctrl_noCks3C9, Ctrl_noCks3C9_BypC);
	VEMS_vidSET(Ctrl_noCMMSeedImmo, Ctrl_noCMMSeedImmo_BypC);
	VEMS_vidSET(Ctrl_noDiag, Ctrl_noDiag_BypC);
	VEMS_vidSET(Ctrl_noEditCal, Ctrl_noEditCal_BypC);
	VEMS_vidSET(Ctrl_noEditSw, Ctrl_noEditSw_BypC);
	VEMS_vidSET(Ctrl_noEgdGearCord, Ctrl_noEgdGearCord_BypC);
	VEMS_vidSET(Ctrl_noEgdGear, Ctrl_noEgdGear_BypC);
	VEMS_vidSET(Ctrl_noGearReqMax, Ctrl_noGearReqMax_BypC);
	VEMS_vidSET(Ctrl_noGearReqMin, Ctrl_noGearReqMin_BypC);
	VEMS_vidSET(Ctrl_noTarGear, Ctrl_noTarGear_BypC);
	VEMS_vidSET(Ctrl_noVersAdp, Ctrl_noVersAdp_BypC);
	VEMS_vidSET(Ctrl_noVersSw, Ctrl_noVersSw_BypC);
	VEMS_vidSET(Ctrl_noVersSysMnth, Ctrl_noVersSysMnth_BypC);
	VEMS_vidSET(Ctrl_noVersSysYr, Ctrl_noVersSysYr_BypC);
	VEMS_vidSET(Ctrl_noVersSys, Ctrl_noVersSys_BypC);
	VEMS_vidSET(Ctrl_noVerSysDay, Ctrl_noVerSysDay_BypC);
	VEMS_vidSET(Ctrl_nTarIdl, Ctrl_nTarIdl_BypC);
	VEMS_vidSET(Ctrl_nTar, Ctrl_nTar_BypC);
	VEMS_vidSET(Ctrl_pAirExtMes, Ctrl_pAirExtMes_BypC);
	VEMS_vidSET(Ctrl_pBrkAsi, Ctrl_pBrkAsi_BypC);
	VEMS_vidSET(Ctrl_pDsEGRVlvMes, Ctrl_pDsEGRVlvMes_BypC);
	VEMS_vidSET(Ctrl_posnATLev, Ctrl_posnATLev_BypC);
	VEMS_vidSET(Ctrl_rBattSoCLoResl, Ctrl_rBattSoCLoResl_BypC);
	VEMS_vidSET(Ctrl_rDrvReq, Ctrl_rDrvReq_BypC);
	VEMS_vidSET(Ctrl_resBattItNorm, Ctrl_resBattItNorm_BypC);
	VEMS_vidSET(Ctrl_rFuTnkPerc, Ctrl_rFuTnkPerc_BypC);
	VEMS_vidSET(Ctrl_rSpdFanAct, Ctrl_rSpdFanAct_BypC);
	VEMS_vidSET(Ctrl_rSpdFanReq, Ctrl_rSpdFanReq_BypC);
	VEMS_vidSET(Ctrl_rtqOBD, Ctrl_rtqOBD_BypC);
	VEMS_vidSET(Ctrl_spdEspVeh, Ctrl_spdEspVeh_BypC);
	VEMS_vidSET(Ctrl_spdFilGearSen, Ctrl_spdFilGearSen_BypC);
	VEMS_vidSET(Ctrl_spdLeFrntWhl, Ctrl_spdLeFrntWhl_BypC);
	VEMS_vidSET(Ctrl_spdLeReWhl, Ctrl_spdLeReWhl_BypC);
	VEMS_vidSET(Ctrl_spdRawGearSen, Ctrl_spdRawGearSen_BypC);
	VEMS_vidSET(Ctrl_spdRiFrntWhl, Ctrl_spdRiFrntWhl_BypC);
	VEMS_vidSET(Ctrl_spdRiReWhl, Ctrl_spdRiReWhl_BypC);
	VEMS_vidSET(Ctrl_spdVehAvrFrntWhl, Ctrl_spdVehAvrFrntWhl_BypC);
	VEMS_vidSET(Ctrl_stBSIKeyImmo, Ctrl_stBSIKeyImmo_BypC);
	VEMS_vidSET(Ctrl_stCMMStImmoReq, Ctrl_stCMMStImmoReq_BypC);
	VEMS_vidSET(Ctrl_stCMMStImmoSnd, Ctrl_stCMMStImmoSnd_BypC);
	VEMS_vidSET(Ctrl_stCnvClu, Ctrl_stCnvClu_BypC);
	VEMS_vidSET(Ctrl_stCpl, Ctrl_stCpl_BypC);
	VEMS_vidSET(Ctrl_stCtlModFSF, Ctrl_stCtlModFSF_BypC);
	VEMS_vidSET(Ctrl_stDftCod, Ctrl_stDftCod_BypC);
	VEMS_vidSET(Ctrl_stDragRed, Ctrl_stDragRed_BypC);
	VEMS_vidSET(Ctrl_stElLvlProd, Ctrl_stElLvlProd_BypC);
	VEMS_vidSET(Ctrl_stEngOpm, Ctrl_stEngOpm_BypC);
	VEMS_vidSET(Ctrl_stEPB, Ctrl_stEPB_BypC);
	VEMS_vidSET(Ctrl_stFuLvlDft, Ctrl_stFuLvlDft_BypC);
	VEMS_vidSET(Ctrl_stFuSlowCorbank1, Ctrl_stFuSlowCorbank1_BypC);
	VEMS_vidSET(Ctrl_stFuSpdCorbank1, Ctrl_stFuSpdCorbank1_BypC);
	VEMS_vidSET(Ctrl_stGBxDft, Ctrl_stGBxDft_BypC);
	VEMS_vidSET(Ctrl_stGearCtlReq, Ctrl_stGearCtlReq_BypC);
	VEMS_vidSET(Ctrl_stGearRat, Ctrl_stGearRat_BypC);
	VEMS_vidSET(Ctrl_stGSTyp, Ctrl_stGSTyp_BypC);
	VEMS_vidSET(Ctrl_stJDDEmi, Ctrl_stJDDEmi_BypC);
	VEMS_vidSET(Ctrl_stNRegTyp, Ctrl_stNRegTyp_BypC);
	VEMS_vidSET(Ctrl_stPosnCoVlvEstim, Ctrl_stPosnCoVlvEstim_BypC);
	VEMS_vidSET(Ctrl_stUCCKeyImmo, Ctrl_stUCCKeyImmo_BypC);
	VEMS_vidSET(Ctrl_stUnBlockAuthImmo, Ctrl_stUnBlockAuthImmo_BypC);
	VEMS_vidSET(Ctrl_stUnBlockReq, Ctrl_stUnBlockReq_BypC);
	VEMS_vidSET(Ctrl_stWkuMain, Ctrl_stWkuMain_BypC);
	VEMS_vidSET(Ctrl_tAirExtMes5B2, Ctrl_tAirExtMes5B2_BypC);
	VEMS_vidSET(Ctrl_tAirExtMes, Ctrl_tAirExtMes_BypC);
	VEMS_vidSET(Ctrl_tBattMes, Ctrl_tBattMes_BypC);
	VEMS_vidSET(Ctrl_tCoMesFineResl, Ctrl_tCoMesFineResl_BypC);
	VEMS_vidSET(Ctrl_tDsThrMes, Ctrl_tDsThrMes_BypC);
	VEMS_vidSET(Ctrl_tiCurVehTmr, Ctrl_tiCurVehTmr_BypC);
	VEMS_vidSET(Ctrl_tiVehCnt, Ctrl_tiVehCnt_BypC);
	VEMS_vidSET(Ctrl_tOilEstim, Ctrl_tOilEstim_BypC);
	VEMS_vidSET(Ctrl_tOilGBx, Ctrl_tOilGBx_BypC);
	VEMS_vidSET(Ctrl_tqAirASRReq, Ctrl_tqAirASRReq_BypC);
	VEMS_vidSET(Ctrl_tqAirDrvFil, Ctrl_tqAirDrvFil_BypC);
	VEMS_vidSET(Ctrl_tqCkCAN, Ctrl_tqCkCAN_BypC);
	VEMS_vidSET(Ctrl_tqCkEngReal, Ctrl_tqCkEngReal_BypC);
	VEMS_vidSET(Ctrl_tqEfcLim, Ctrl_tqEfcLim_BypC);
	VEMS_vidSET(Ctrl_tqMaxGBx, Ctrl_tqMaxGBx_BypC);
	VEMS_vidSET(Ctrl_tqMinGBxMsg, Ctrl_tqMinGBxMsg_BypC);
	VEMS_vidSET(Ctrl_tqMSRReq, Ctrl_tqMSRReq_BypC);
	VEMS_vidSET(Ctrl_tqReqGBx, Ctrl_tqReqGBx_BypC);
	VEMS_vidSET(Ctrl_tqRevAcv, Ctrl_tqRevAcv_BypC);
	VEMS_vidSET(Ctrl_tqSumLossCmp, Ctrl_tqSumLossCmp_BypC);
	VEMS_vidSET(Ctrl_tqWhlPTPotReq, Ctrl_tqWhlPTPotReq_BypC);
	VEMS_vidSET(Ctrl_uBattMinCkg, Ctrl_uBattMinCkg_BypC);
	VEMS_vidSET(Ctrl_uBattRstrt, Ctrl_uBattRstrt_BypC);
	VEMS_vidSET(Ctrl_uEngOilLvl, Ctrl_uEngOilLvl_BypC);
	VEMS_vidSET(Ctrl_uReqProdElec, Ctrl_uReqProdElec_BypC);
	VEMS_vidSET(Ctrl_vLeReWhlMes, Ctrl_vLeReWhlMes_BypC);
	VEMS_vidSET(Ctrl_volFuCnsTot, Ctrl_volFuCnsTot_BypC);
	VEMS_vidSET(Ctrl_vRiReWhlMes, Ctrl_vRiReWhlMes_BypC);
/*Fin SBON***/
   }
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NOPROD_PointeurFonctionNull                                */
/* !Description :  Pointeur de focntion NULL.                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Code Généré                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NOPROD_PointeurFonctionNull(void)  { } /* Use in DCM_MANU\DCM_MANU_Sa_API.c */

/* 
Fonction defini comme vide suite à désintégration du module INJRCHRN. Le soucis, 
c'est que ce dernières sont toujours appelées par le DCM.
Vérifier qu'elles ne sont plus appelées avant de supprimer les définitions 
*/
void Srv_EveErrInjrChrnWr_InjrChrn(void) { } /* Use in DCM_MANU_CARACINJ.c */
void Srv_EveInjrChrn_InjrChrn     (void) { } /* Use in DCM_MANU_CARACINJ.c */

/*CROC Stub Inte Suppr NvmDiag SAIMMO_FCT5.c & ECUST_SCH.c*/
void Srv_EveFirstInitDone_NvmDiag(void) { }

/* Component LBD for HITACHI / MCWDG  */
void MCWDG_vidDisable(void) {}
void MCWDG_vidEnable(void) {}
void MCWDG_vidFunctionalTestExchange(Std_ReturnType stdTestStatus) {}
void MCWDG_vidInit(void) {}
void MCWDG_vidItAcknowledgeByteMcw(void) {}
void MCWDG_vidItTimeoutSpiCom(void) {}
void MCWDG_vidMcwManagement(void) {}
void MCWDG_vidResumeSampleCheck(void) {}
void MCWDG_vidRx(void) {}
void MCWDG_vidStartInhibitState(uint8 u8McwInhPin) {}
void MCWDG_vidStopInhibitState(uint8 u8McwInhPin) {}
void MCWDG_vidSuspendSampleCheck(void) {}
void MCWDG_vidTx(void) {}
void MCWDG_vidWriteMcpFaultState(uint8 bfFaultMask) {}
void MCWDG_vidWritePrepInitStatus(MCWDG_tbfPrepInitStatus bfPrepInitStatus) {}
uint8 MCWDG_bfReadMcwFaultState(void) 
{
   uint8 bLocalRead;
   return(bLocalRead);
}
boolean MCWDG_bMcpIsEnableAuthorized(uint8 u8McpOutput)
{
   boolean bLocalRead;
   return(bLocalRead);
}
boolean MCWDG_bReadInhibitState(uint8 u8McwInhPin)
{
   boolean bLocalRead;
   return(bLocalRead);
}

/* Stub IMMO */
void RE_Immo_001_OIE(void) {}
void RE_Immo_002_OIE(void) {}
void RE_Immo_003_OIE(UInt32 Ext_noImmoCodProgDiag, UInt8 Ext_stCANMatchOptDiag) {}
void RE_Immo_004_OIE(UInt8 Ext_stMatchSrvDiag) {}
void RE_Immo_005_OIE(UInt32 Ext_noKeyCtlUnit, UInt8 Ext_noRcvSrvTypImmo) {}
void RE_Immo_006_OIE(UInt8 Ext_stEndWrImmo) {}
void RE_Immo_008_OIE(UInt32 Ext_noImmoCodTestDiag) {}
void RE_Immo_009_OIE(uint8 *Immo_stProgImmoConf, boolean *Immo_bLockECUConf, uint8 *Immo_stCANOptConf)
{
   *Immo_stProgImmoConf = SAIMMO_GETCONF_PROG_ETUDE;
   *Immo_bLockECUConf = 0x00;
}
void RE_Immo_010_OIE(void) {}

/* Stub for DCM_MANU_Sa_API.c */
void SECUR_vidInit(const uint16 ku16AppliKey, const uint32 ku32bEepromSeedRead, const uint32 ku32pfbEepromSeedWrite) {}

/* Stub for DCM_MANU_ROUTINE_CNTRL_FCT.c */
Std_ReturnType SUPSRV_udtJumpToIdentTest(uint8  *pau8RequestBuffer, uint8 u8RequestSize)
{
   Std_ReturnType bLocalRead;
   return(bLocalRead);
}

/* Stub for Dlt_ReadDataManu_API1.c */
uint16 SUPSRV_u16ReadManufacturingDate(uint8  *pau8Buffer, uint16 u16MaxSize)
{
   uint16 bLocalRead;
   return(bLocalRead);
}

/* Stub for GDEXtInit_FCT1.c */
void SUPSRV_vidRstrtProtectedOutputs(void) {}

/* Stub for INTDRV_I.H */
void set_imask(mask)  {}
void get_imask()      {}

/* Stub for PFCMNG_FCT1.c */
void WdgM_Init( const WdgM_ConfigType* ConfigPtr ) {}
void WdgM_vidTimeoutCheck(void) {}
Std_ReturnType WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID)
{
   Std_ReturnType bLocalRead;
   return(bLocalRead);
}
Std_ReturnType WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType  *Status)
{
   Std_ReturnType bLocalRead;
   return(bLocalRead);
}

/*CROC Inte RTA_OS*/
void Sfty_EveInitCnt_TaskOvrrunCnt(void) {} /* Use in DCM_MANU_ROUTINE_CNTRL_FCT.c */

/*CROC Inte SYNCEXCMDIAG SYNCEXCMDIAG*/
void Sync_SdlSlow_ExCmSts(void) {}
void Sync_SdlSlow_InCmSts(void) {}

/* Use in Com_Cfg.c */
FUNC(boolean, COM_CODE) ISCAN_EveTxF388_Callout ( VAR(PduIdType,AUTOMATIC) Id, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) IpduData) { }
FUNC(void, COM_CODE) FHLIN_EveRxF11_AckClbk  (void) { }
FUNC(void, COM_CODE) FHLIN_EveRxF11_TOutClbk (void) { }
FUNC(void, COM_CODE) FHLIN_EveTxF29_AckClbk  (void) { }
FUNC(void, COM_CODE) FHLIN_EveTxF29_TOutClbk (void) { }

/* STUB of F2 family */
void KNWHAL_vidWriteAntiAliasingFreq(uint16 u16Frequency)
{
   COMPILER_UNUSED_PARAMETER(u16Frequency);
}

/* A voir avec FTOU */
// void Os_Entry_OSTSK_S_SPILL_EVENT         (void ){}
// void Os_Entry_OSTSK_S_SPILL_EVENT_ASW     (void ){}
// void Os_Entry_OSTSK_S_SPILL_EVENT_POST    (void ){}
// void Os_Entry_OSTSK_S_ICLC_EVENT          (void ){}
// void Os_Entry_OSTSK_S_ICLC_EVENT_ASW      (void ){}
// void Os_Entry_OSTSK_S_ICLC_EVENT_POST     (void ){}
void Os_Entry_OSTSK_S_DUMMY_DRE_CORE2     (void ){}
void Os_Entry_OSTSK_S_DUMMY_MSE_CORE2     (void ){}
void Os_Entry_OSTSK_S_FUNCTIONAL_TEST_END (void ){}

// void Os_Entry_OSTSK_S_CJ135_U2450_IRQ (void ){}
// void Os_Entry_OSTSK_S_CJ135_U2450_IRQ (void ){}
// void Os_Entry_OSTSK_S_TLE8718_MSCM_END_SEQ (void ){}

/* Stub of CoFan */
// void CoFan_EveRst_CmdDiagCoFanAcqPwd (void)  { }
// void CoFan_SdlMid_CmdDiagCoFanAcqPwd (void)  { }

/* Redirection of COM_EBDT_MIVIE_im.h */
#define TQSYS_EveSyncFrame38D() RE_TqSys_EveSyncFrame38D_Tra() 
#define TQSYS_EveSyncFrame30D() RE_TqSys_EveSyncFrame30D_Tra()

/* Sutb in COM_MIVIE_im.h */
void Sfty_EveRxn329	                     (void){} 
void Sfty_EveRxn349	                     (void){} 
void IgSys_EveRxn34D	                     (void){}
void SFTY_EveRxn34D	                     (void){} 
void Sfty_EveRxn38D	                     (void){} 
void FuPmp_RxnIdDaRcdDml	               (void){}  
void Rly_EveRxnIdDaRcdDml	               (void){} 
void EcuSt_EveRxn432	                     (void){}
void Rly_EveRxn4c8	                     (void){}  
void CrsCtl_EveRxn50E	                  (void){}  
void ENGST_EveRxn552	                     (void){}
void FuSys_EveRxn552	                     (void){}
void VehSpd_EveRxn7F2	                  (void){}  

/* Sutb in ECUMNG_im.h */
void ISCAN_EveEcuSt_TxFrame788	         (void){}

/* Sutb in CanIf_ModeHandler.c,CanIf_Reception.c, CanSM_Internal.h, LinIf_LinTransportProtocol.c,LinIf_Main.c,PduR_Main.c,PduR_UserIf.c,Can_17_MCanP.c ,Fee.c,Fls_17_Pmu_Ver.c */
/*  Mcu.c ,Mcu_Platform.c  , Spi.c, SpiSlave.c , Wdg_17_Scu.c , Wdg_17_Scu_Safe.c ,  NvM.c */
void Dem_ReportErrorStatus	               (void){}

/* Stub for TST_KRN.c */
void KRN_vidINCAM_DOWN_MODE_BSW_POST	   (void){}
void KRN_vidINCAM_NORMAL_MODE_BSW_POST	   (void){}
void KRN_vidEXCAM_DOWN_MODE_BSW_POST	   (void){}
void KRN_vidEXCAM_NORMAL_MODE_BSW_POST	   (void){}
void KRN_vidCRK_DOWN_MODE_BSW_POST	      (void){}
void KRN_vidCRK_NORMAL_MODE_BSW_POST	   (void){}
void KRN_vidSYNC_FOUND_BSW_PRE	         (void){}
void KRN_vidSYNC_FOUND_BSW_POST	         (void){}

/* Missing inside LBD */
void KRN_vidS_ENG_SPEED_OUTPUT_BSW_PRE              (void) {}
void KRN_vidActivate_OSTSK_S_ENG_SPEED_OUTPUT_ASW   (void) {}
void KRN_vidActivate_OSTSK_S_ENG_SPEED_OUTPUT_POST  (void) {}
void KRN_vidS_ENG_SPEED_OUTPUT_BSW_POST             (void) {}

/* Sutb for CANTXMIXMOD_SCH.c  */
void Can_EveTxn1E8_CanTxMixMod  (void) {}
void Can_EveTxn468_CanTxMixMod  (void) {}

/* Sutb for GDGAR_im.h  */
void Can_EveSendDftLog          (void) {}
void Srv_EveRstDft_NvmDiag(void) {}

/**/
void OILLVHAL_vidEnable  (void) {}
void OILLVHAL_vidDisable  (void) {} 
void OILLVHAL_udtGetConversionResult  (void) {}
 
void AccP_EveRst_MngModSecu (void) {}
void ACCPCALCRPOS_vidEntryReset (void) {}

/*ComM.c*/
FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel) {}
FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel) {}


/* To be remove OS CL */
// void AccP_SdlFast_MngModSecu     (void){}
// void AccP_SdlSfty_AcqPosn        (void){}
// void Inj_EveCkOn_InjCmd          (void){}
// void Inj_EveCkSnOn_InjCmd        (void){}
// void Inj_EveKOn_InjCmd           (void){}
// void Inj_EveRTSt_InjCmd          (void){}
// void VlvAct_SdlMid_ExEndStop     (void){}
// void VlvAct_SdlMid_InEndStop     (void){}

/* Stub OS CL */
void InjSys_EveInj_FacFuTran     (void){}
void Injsys_EveKOn_mFuSpCrk      (void){}

void AltAbsent__nvmini      (void){}
void LinBlocked__nvmini     (void){}
void FrbdF592P421_1__nvmini   (void){}
void FrbdF592P421_2__nvmini   (void){}
void FrbdF592P421_3__nvmini   (void){}
void InvldF592P421_1__nvmini   (void){}
void InvldF592P421_2__nvmini   (void){}
void InvldF592P421_3__nvmini   (void){}
void LIDF592__nvmini   (void){}


// void AFAMgtT_NVRAM_int8_const__nvmini (void){}
// void AFAT_NVRAM_int16_calib__nvmini (void){}
// void AFAT_NVRAM_int32_calib__nvmini (void){}
// void AFAT_NVRAM_int8_calib__nvmini (void){}
// void AFAT_NVRAM_boolean_calib__nvmini (void){}
// void AFAT_NVRAM_int16_const__nvmini (void){}
// void AFAT_NVRAM_int8_const__nvmini (void){}
// void AFAT_NVRAM_boolean_const__nvmini (void){}
// void COEMSTT_NVRAM_int16_const_1__nvmini (void){}
// void COEMSTT_NVRAM_int32_const_1__nvmini (void){}
// void COEMSTT_NVRAM_int8_const_1__nvmini (void){}
// void COSTOPSTART_NVRAM_int16_const_1__nvmini (void){}
// void COSTOPSTART_NVRAM_int8_const_1__nvmini (void){}
// void COSTOPSTART_NVRAM_int8_const_2__nvmini (void){}
// void COSTOPSTART_NVRAM_int8_const_3__nvmini (void){}
// void COSTOPSTART_NVRAM_boolean_const_1__nvmini (void){}
// void COSTOPSTART_NVRAM_boolean_const_2__nvmini (void){}
// void DFWCTL_NVRAM_int16_const__nvmini (void){}
// void EOMGSL_NVRAM_int32_const__nvmini (void){}
// void ExMGslT2_NVRAM_int16_const__nvmini (void){}
// void FISA_NVRAM_int8_const_1__nvmini (void){}
// void MPM_NVRAM_int16_const__nvmini (void){}
// void MPM_NVRAM_int32_const__nvmini (void){}
// void MPM_NVRAM_int32_const_1__nvmini (void){}
// void MPM_NVRAM_int32_const_2__nvmini (void){}
// void PRODELEM_NVRAM_int16_const_1__nvmini (void){}
// void PRODELEM_NVRAM_int16_const_2__nvmini (void){}
// void PRODELEM_NVRAM_int32_const_1__nvmini (void){}
// void PRODELEM_NVRAM_int32_const_2__nvmini (void){}
// void PRODELEM_NVRAM_int32_const_3__nvmini (void){}
// void PRODELEM_NVRAM_int8_const_1__nvmini (void){}
// void PRODELEM_NVRAM_int8_const_2__nvmini (void){}
// void PRODELEM_NVRAM_boolean_const_1__nvmini (void){}
// void PRODELEM_NVRAM_boolean_const_2__nvmini (void){}
// void PRODELENG_NVRAM_int32_const_1__nvmini (void){}
// void STOPSTRTEM_NVRAM_int16_const_3__nvmini (void){}
// void STOPSTRTEM_NVRAM_int32_const_1__nvmini (void){}
// void STOPSTRTEM_NVRAM_int32_const_2__nvmini (void){}
// void THMGT_NVRAM_int8_const__nvmini (void){}
// void THMGT_NVRAM_boolean_const__nvmini (void){}
// void ThrSpT_NVRAM_int32_const__nvmini (void){}
// void TPM_NVRAM_int16_const__nvmini (void){}
// void TQADPCMP_NVRAM_int16_const__nvmini (void){}
// void TQADPCMP_NVRAM_int32_const__nvmini (void){}
// void TQADPCMP_NVRAM_int8_const__nvmini (void){}
// void UsThrMT_NVRAM_int16_calib__nvmini (void){}


void ISCAN_vidTxManagerPrivate (void){}


void InjSys_EveCkSnNtAc_mFuInjSyncIf (void){}


void InjrSys_RstRTSt_InjTiReqIf         (void){}
void InjrSys_RstRTSt_TiFuSpIf           (void){}
void InjrSys_SnStTCrFast_InjTiReqIf     (void){}
void InjrSys_StTCrFast_TiFuSpIf         (void){}
void InjSys_EveInj_stTypElCmdInjr       (void){}
void InjSys_FastCrTR_TauXCorrnIf        (void){}
void InjSys_SdlFast_stTypElCmd          (void){}
void RE_FuSysM_SdlSlow_TFuM             (void){}
void RE_InjCrk_EveClcn1_PreInjTi        (void){}
void RE_InjCrk_EveClcn2_PreInjTi        (void){}
void RE_InjrM_EveClcn_InjrConMdl        (void){}
void RE_InjrM_EveClcn_InjrOfsMdl        (void){}
void RE_InjrSys_RstRTSt_TiFuSp          (void){}
void RE_InjrSys_SnStTCrFast_InjTiReq    (void){}
void RE_InjrSys_StTCrFast_TiFuSp        (void){}
void RE_InjSys_EveFastCrTR_TauXPrm      (void){}
void RE_InjSys_FastCrTR_TauXCorrn       (void){}
void RE_InjSys_SdlFast_FuMFastCorrn     (void){}
void RE_InjSys_SdlFast_TauXCoef         (void){}
void RE_InjSys_SdlFast_TauXMgr          (void){}
void RE_InjSys_SdlMid_TauXCoef          (void){}
void RE_InjSys_SdlMid_TauXMgr           (void){}
void RE_InjSys_SdlSlow_TauXMgr          (void){}



/*------------------------------- end of file --------------------------------*/
