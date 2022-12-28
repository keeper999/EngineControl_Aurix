/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDGAR                                                   */
/* !Description     : GDGAR Component                                         */
/*                                                                            */
/* !Module         : MEM                                                      */
/* !Description    : Listing of all parameters used in the Freeze Frame       */
/*                   class on the projet EBx_V46.                             */
/* !File           : MEM_conf.c                                               */
/*                                                                            */
/* !Scope          : Public Component                                         */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / MEM_vidArrayInit                                                     */
/*   2 / MEM_vidClasFrfInit                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/MEMCONF/mem_conf.c_v         $*/
/* $Revision::   1.15     $$Author::   lthibaud       $$Date::   29 Jan 2014 $*/
/* $Author::   lthibaud                               $$Date::   29 Jan 2014 $*/
/******************************************************************************/
/* generated the 30/05/2013 at 16:53                                          */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GD.h"
#include "GD_A.h"
#include "MATHSRV.h"
#include "MEM_im.h"
#include "MEM_conf_im.h"
#include "MEM_L.h"
#include "MEM.h"
#include "MEM_conf.h"
#include "vems.h"

/* Liste des variables globales*/
uint8 u8ValueNull;
uint16 Ext_nEng_mem;
uint16 Veh_spdVeh_mem;
boolean Ext_bMainBrkPedPrssMes_mem;
boolean Ext_bCluPedPrss_mem;
uint16 Ext_uAccP1SenPwr_mem;
uint16 Ext_uAccP2SenPwr_mem;
uint8 AccP_rDrvReq_mem;
boolean Ext_bAccPHdPt_mem;
uint8 CoPt_noEgdGearCord_mem;
sint16 Ext_tCoMes_mem;
boolean Ext_bRCDLine_mem;
sint16 ThMgt_tCoReg_mem;
uint16 VlvAct_nEngExCmFil_mem;
uint8 Ext_rAltCycOp_mem;
sint16 Ext_tDsThrMes_mem;
uint8 CoPTSt_stEng_mem;
sint16 Ext_tAirExtMes_mem;
boolean Ext_bStrtAuth_mem;
boolean AC_bACClu_mem;
uint8 AC_pwrAC_mem;
uint16 Ext_upOilMes_mem;
uint16 Ext_uEngOilLvl_mem;
uint16 ESLim_tiCntOverNEngMax_mem;
uint16 Cl_raw_pressure_mem;
sint16 Ext_uBattMes_mem;
uint16 Tension_alimentation_1_mem;
uint16 Tension_alimentation_2_mem;
uint16 Tension_alimentation_3_mem;
uint16 Tension_alimentation_4_mem;
boolean Actionneurs_mem;
uint16 Ext_pOilMesRaw_mem;
boolean ThMgt_bCmdHiSpdFan_mem;
boolean ThMgt_bCmdLowSpdFan_mem;
boolean Ext_bStFanFil_mem;
boolean Ext_bNeut_mem;
uint16 Cts_range_voltage_mem;
uint8 CoPtUH_noGearTmpBeg_mem;
uint8 CoPtUH_noGearTmpEnd_mem;
uint16 InjSys_pFuSp_mem;
uint16 Ext_pFuMesWRV_mem;
uint16 Ext_rOpThr_mem;
uint16 ThrSys_rOpThrReq_mem;
uint16 Ext_nEng_mem;
boolean Ext_bSecBrkPedPrssMes_mem;
uint16 OilSys_pOilReq_mem;
uint16 Ext_pAirExtAcq_mem;
uint16 AccP_rAccP_mem;
uint16 BatMgt_rBattSoCCor_mem;
uint16 Ext_rCluPedPrssMes_mem;
uint16 Ext_rCluPedPrssBrutMes_mem;
uint16 OilSys_rCtlPmpReq_mem;
uint16 FTPCtl_rFlowFuTnkPmp_mem;
uint8 Ext_spdVehReqVSReg_mem;
uint8 Ext_spdVehReqVSLim_mem;
uint32 Ext_ctSecEngStop_mem;
uint16 EngSt_tiDlySync_mem;
uint16 Ext_pUsThrMesSI_mem;
sint16 Ext_tDsThrMes_mem;
uint16 Cl_pressure_result_ad_conv_mem;
uint16 Ext_upFuMes_mem;
uint16 Pression_air_result_ad_conv_mem;
uint16 Temperature_air_result_ad_conv_mem;
uint16 InM_mfAirThrEstim_mem;
uint16 TrbAct_rRCOReq_mem;
uint16 AirSys_pUsThrReq_mem;
uint16 AirSys_mfAirThrReqFil_mem;
uint16 Aps_1_raw_filt_position_mem;
uint16 Aps_2_raw_filt_position_mem;
sint16 BatMgt_tBattMes_mem;
sint32 BatMgt_iBattMes_mem;
uint16 CoPtUH_rMaxCluGc_mem;
uint16 Ext_nEngCmInMes_mem;
uint32 Ext_dstVehTotMes_mem;
uint16 SftyMgt_prm_bDftHisAfts1_mem;
uint16 SftyMgt_prm_bDftHisAfts2_mem;
uint16 SftyMgt_prm_bDftHisAfts3_mem;
uint8 ThMgt_stPosnFSFReq_mem;
uint16 SftyMgt_prm_bDftHisAfts4_mem;
uint16 SftyMgt_prm_bDftHisAfts5_mem;
uint16 SftyMgt_prm_bDftHisAfts6_mem;
uint8 Ext_rAltCycOp_mem;
uint8 LsSys_rLsDsMainOxCHeatPwrReq_mem;
uint8 LsSys_rLsUsMainOxCHeatPwrReq_mem;
uint8 ACCmd_stReq_mem;
uint8 VSCtl_stVSRegExtd_mem;
boolean Diag_on_mem;
boolean CoPt_stDrvTra_mem;
boolean Dnstr_conds_met_mem;
uint8 VSCtl_stVSLimExtd_mem;
boolean Ext_bAcvSta_mem;
boolean Lambda_closed_loop_mem;
uint32 Ext_tiCurVehTmr_mem;
uint32 InjrSys_prm_tiInjH1ReqCyl_0_mem;
uint32 InjrSys_prm_tiInjH1ReqCyl_1_mem;
uint32 InjrSys_prm_tiInjH1ReqCyl_2_mem;
sint16 TqSys_tqIdcReq_mem;
uint16 Tension_sonde_aval_brute_mem;
uint16 Tension_sonde_amont_brute_mem;
uint16 EcuSt_ctHotRst_Count_mem;
sint16 Ext_pDsThrMes_mem;
uint16 AirSys_prm_pInMnfReq_0_mem;
uint8 Flev_fuel_level_mem;
uint16 SftyMgt_prm_bDftHisAfts7_mem;
uint16 SftyMgt_prm_bDftHisAfts8_mem;
boolean BlowBy1Hw_bReq_mem;
boolean ThMgt_bTrbWaPmpReq_mem;
uint8 IgSys_agIgBas_mem;
sint16 Ext_agCkClsExVlvEstimRef0_mem;
uint8 VlvSys_agCkClsExVlvReqRef0_mem;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_0_mem;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_1_mem;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_2_mem;
uint8 IgSys_prm_agIgSpCyl_0_mem;
uint8 IgSys_prm_agIgSpCyl_1_mem;
uint8 IgSys_prm_agIgSpCyl_2_mem;
sint16 Ext_agCkOpInVlvEstimRef0_mem;
uint8 VlvSys_agCkOpInVlvReqRef0_mem;
uint8 IgSys_agIgMaxWiPrevAdpMv_mem;
uint8 IgSys_agIgMin_mem;
uint8 Rco_applique_purge_mem;
uint16 CanPurg_concFuStmEstim_mem;
uint8 ThMgt_rPwrECTReq_mem;
uint16 DmpVlvAct_rDmpVlvOplCmdSp_mem;
uint16 Rco_applique_vvt_echap_mem;
uint16 Rco_applique_vvt_adm_mem;
boolean Sonde_riche_aval_mem;
boolean Vcpe_cam_offsets_are_learned_mem;
boolean Vcpi_cam_offsets_are_learned_mem;
boolean Sonde_riche_amont_mem;
sint16 TqSys_tqCkEfcReq_mem;
uint16 Dv_1_app_pos_ped_pc_mem;
uint16 Dv_1_app_pos_ped_pl_mem;
uint16 Dv_2_app_pos_ped_pc_mem;
uint16 Dv_2_app_pos_ped_pl_mem;
uint16 Tpac_1_limp_home_pos_mem;
uint16 Tpac_1_closed_throttle_pos_mem;
uint16 Tpac_2_limp_home_pos_mem;
uint16 Tpac_2_closed_throttle_pos_mem;
uint16 FARSp_rMixtCylSp_mem;
uint16 AirSys_rAirLdReq_mem;
uint16 EngM_rAirLdCor_mem;
sint8 Av_bmax_corr_appliquee_cyl_0_mem;
sint8 Av_bmax_corr_appliquee_cyl_1_mem;
sint8 Av_bmax_corr_appliquee_cyl_2_mem;
uint16 PFuCtl_agWdPmpCmdReq_mem;
uint16 Bruit_moyen_cyl_min_thresh_0_mem;
uint16 Bruit_moyen_cyl_min_thresh_1_mem;
uint16 Bruit_moyen_cyl_min_thresh_2_mem;
boolean VlvAct_bInOfsFrstLrn_mem;
boolean VlvAct_bExOfsFrstLrn_mem;
uint16 Vcpe_cam_offsets_0_mem;
uint16 Vcpe_cam_offsets_1_mem;
uint16 Vcpe_cam_offsets_2_mem;
uint16 Vcpi_cam_offsets_0_mem;
uint16 Vcpi_cam_offsets_1_mem;
uint16 Vcpi_cam_offsets_2_mem;
uint16 Somme_clq_cyl_mem;
boolean CoPtUH_bStPresLo_mem;
boolean CoStrtRStrt_bInh_mem;
uint32 StaStrtMgt_ctStaAcv_mem;
uint8 Veh_stDrvAvl_mem;
boolean CoPtUH_bSTTInh_mem;
uint8 CoPtUH_stPwt_mem;
boolean Ext_bPush_mem;
sint16 TqSys_tqCkEngReal_mem;
uint8 Ext_pRelBrkAsi_mem;
boolean Ext_bStaCmdFctSt_mem;
uint32 StaStrtMgt_ctStaStrtAcv_mem;
uint8 StaStrtMgt_stStaFbCmd_mem;
boolean StaStrtMgt_bStaReq_mem;
sint16 CoOptmEl_tqAlt_mem;
uint16 BatMgt_uBattMes_mem;
uint8 SAIMMO_stLockECUReadSt_mem;


const void* GD_apvidListParam[NB_PARAM] =
{
   &u8ValueNull, /* Aucun paramètre associé (forçage à 0) */
   &Ext_nEng_mem, /* Regime moteur */
   &Veh_spdVeh_mem, /* Vitesse véhicule */
   &Ext_bMainBrkPedPrssMes_mem, /* Information frein */
   &Ext_bCluPedPrss_mem, /* Etat contacteur embrayage */
   &Ext_uAccP1SenPwr_mem, /* Tension pédale accélérateur voie 1 */
   &Ext_uAccP2SenPwr_mem, /*  Tension pédale accélérateur voie 2 */
   &AccP_rDrvReq_mem, /* Volonté constructeur (pédale reconstruite) */
   &Ext_bAccPHdPt_mem, /*  Information point dur */
   &CoPt_noEgdGearCord_mem, /* Rapport de boîte calculé */
   &Ext_tCoMes_mem, /* Température d'eau moteur filtrée */
   &Ext_bRCDLine_mem, /* Etat de la ligne RCD */
   &ThMgt_tCoReg_mem, /* Consigne de température d'eau moteur */
   &VlvAct_nEngExCmFil_mem, /* Régime moteur recalculé à partir de l'information arbre à came échappement moteur */
   &Ext_rAltCycOp_mem, /* Consigne de valeur de charge de l'alternateur */
   &Ext_tDsThrMes_mem, /* Température d'air brute dans le répartiteur d'admission_1 */
   &CoPTSt_stEng_mem, /* Etat moteur */
   &Ext_tAirExtMes_mem, /* Information capteur sans valeur de remplacement de la température d’air extérieur */
   &Ext_bStrtAuth_mem, /* Autorisation de démarrage BV */
   &AC_bACClu_mem, /* Etat de la demande de clim */
   &AC_pwrAC_mem, /* Puissance mécanique consommé par la clim */
   &Ext_upOilMes_mem, /* Tension représentative de la pression d'huile moteur */
   &Ext_uEngOilLvl_mem, /* Tension représentative du niveau d'huile moteur */
   &ESLim_tiCntOverNEngMax_mem, /* Temps passé au-dessus du régime maximum */
   &Cl_raw_pressure_mem, /* Pression fluide réfrigérant */
   &Ext_uBattMes_mem, /* Tension CMM */
   &Tension_alimentation_1_mem, /* Tension régulateur CMM1 */
   &Tension_alimentation_2_mem, /* Tension régulateur CMM2 */
   &Tension_alimentation_3_mem, /* Tension régulateur CMM3 */
   &Tension_alimentation_4_mem, /* Tension régulateur CMM4 */
   &Actionneurs_mem, /* Etat commande relais de puissance */
   &Ext_pOilMesRaw_mem, /* Pression d'huile moteur */
   &ThMgt_bCmdHiSpdFan_mem, /* Etat de la grande vitesse GMV */
   &ThMgt_bCmdLowSpdFan_mem, /* Etat de la petite vitesse GMV */
   &Ext_bStFanFil_mem, /* Etat de commande du GMV */
   &Ext_bNeut_mem, /* Point mort BV */
   &Cts_range_voltage_mem, /* Tension représentative de la température d'eau moteur */
   &CoPtUH_noGearTmpBeg_mem, /* Rapport engagé avant changement de rapport */
   &CoPtUH_noGearTmpEnd_mem, /* Rapport engagé après changement de rapport */
   &InjSys_pFuSp_mem, /* Consigne HP carburant */
   &Ext_pFuMesWRV_mem, /* HP carburant mesurée */
   &Ext_rOpThr_mem, /* Position mesurée recalée du papillon */
   &ThrSys_rOpThrReq_mem, /* Angle de consigne du papillon */
   &Ext_nEng_mem, /* Régime vilebrequin */
   &Ext_bSecBrkPedPrssMes_mem, /* Frein secondaire */
   &OilSys_pOilReq_mem, /* Consigne pression d'huile moteur */
   &Ext_pAirExtAcq_mem, /* Pression Atmosphérique */
   &AccP_rAccP_mem, /* Position pédale d'accélérateur */
   &BatMgt_rBattSoCCor_mem, /* SOC batterie */
   &Ext_rCluPedPrssMes_mem, /* Position pédale d'embrayage */
   &Ext_rCluPedPrssBrutMes_mem, /* RCO du capteur de position de la pédale d'embrayage */
   &OilSys_rCtlPmpReq_mem, /* RCO de commande de la pompe à huile */
   &FTPCtl_rFlowFuTnkPmp_mem, /* RCO de commande de la pompe basse pression de carburant */
   &Ext_spdVehReqVSReg_mem, /* Consigne de régulation de vitesse */
   &Ext_spdVehReqVSLim_mem, /* Consigne de limitation de vitesse */
   &Ext_ctSecEngStop_mem, /* Temps écoulé depuis le dernier arrêt moteur */
   &EngSt_tiDlySync_mem, /* Temps d'activation du démarreur */
   &Ext_pUsThrMesSI_mem, /* Pression de suralimentation brute */
   &Ext_tDsThrMes_mem, /* Température d'air d'admission (T2') */
   &Cl_pressure_result_ad_conv_mem, /* Tension du signal de pression du circuit de climatisation */
   &Ext_upFuMes_mem, /* Tension du signal de pression rail */
   &Pression_air_result_ad_conv_mem, /* Tension représentative de la pression d'air admission */
   &Temperature_air_result_ad_conv_mem, /* Tension représentative de la température d'air admission */
   &InM_mfAirThrEstim_mem, /* Débit d'air estimé */
   &TrbAct_rRCOReq_mem, /* RCO  de commande du turbo */
   &AirSys_pUsThrReq_mem, /* Consigne de la pression d'air admission */
   &AirSys_mfAirThrReqFil_mem, /* Consigne de débit d'air */
   &Aps_1_raw_filt_position_mem, /* Position brute du capteur 1 de la pédale accélerateur_1 */
   &Aps_2_raw_filt_position_mem, /* Position pédale d'accélérateur voie 2 */
   &BatMgt_tBattMes_mem, /* Température batterie brute */
   &BatMgt_iBattMes_mem, /* Courant batterie brut */
   &CoPtUH_rMaxCluGc_mem, /* Position max embrayage pendant changement rapport */
   &Ext_nEngCmInMes_mem, /* Régime moteur recalculé à partir de l'information arbre à came moteur */
   &Ext_dstVehTotMes_mem, /* Kilométrage véhicule */
   &SftyMgt_prm_bDftHisAfts1_mem, /* Contexte safety 1 */
   &SftyMgt_prm_bDftHisAfts2_mem, /* Contexte safety 2 */
   &SftyMgt_prm_bDftHisAfts3_mem, /* Contexte safety 3 */
   &ThMgt_stPosnFSFReq_mem, /* Ouverture des MEAP */
   &SftyMgt_prm_bDftHisAfts4_mem, /* Contexte safety 4 */
   &SftyMgt_prm_bDftHisAfts5_mem, /* Contexte safety 5 */
   &SftyMgt_prm_bDftHisAfts6_mem, /* Contexte safety 6 */
   &Ext_rAltCycOp_mem, /* Charge alternateur */
   &LsSys_rLsDsMainOxCHeatPwrReq_mem, /* RCO de commande de chauffage de la sonde aval */
   &LsSys_rLsUsMainOxCHeatPwrReq_mem, /* RCO de commande de chauffage de la sonde amont */
   &ACCmd_stReq_mem, /* Demande de débrayage immédiat du compresseur de climatisation */
   &VSCtl_stVSRegExtd_mem, /* Etat d'activation du RVV */
   &Diag_on_mem, /* L’information diagnostic réseau en cours (Diag MUX ON) */
   &CoPt_stDrvTra_mem, /* Etat de la chaîne de traction */
   &Dnstr_conds_met_mem, /* Etat de régulation de la sonde aval */
   &VSCtl_stVSLimExtd_mem, /* Etat d'activation du LVV */
   &Ext_bAcvSta_mem, /* Etat de la commande démarreur */
   &Lambda_closed_loop_mem, /* Etat de régulation de la sonde amont */
   &Ext_tiCurVehTmr_mem, /* La datation envoyée par BSI (véhicules avec AEE2010) */
   &InjrSys_prm_tiInjH1ReqCyl_0_mem, /* Temps d’injection cylindre 1 */
   &InjrSys_prm_tiInjH1ReqCyl_1_mem, /* Temps d’injection cylindre 2 */
   &InjrSys_prm_tiInjH1ReqCyl_2_mem, /* Temps d’injection cylindre 3 */
   &TqSys_tqIdcReq_mem, /* Couple Moteur indiqué (CMI) */
   &Tension_sonde_aval_brute_mem, /* Tension brute de l'info sonde lambda aval */
   &Tension_sonde_amont_brute_mem, /* Tension brute de l'info sonde lambda amont */
   &EcuSt_ctHotRst_Count_mem, /* Nombre de resets calculateur depuis le dernier effacement de l’EEPROM */
   &Ext_pDsThrMes_mem, /* Pression d'admission mesurée */
   &AirSys_prm_pInMnfReq_0_mem, /* Pression d'admission de consigne */
   &Flev_fuel_level_mem, /* Niveau de carburant */
   &SftyMgt_prm_bDftHisAfts7_mem, /* Contexte safety 7 */
   &SftyMgt_prm_bDftHisAfts8_mem, /* Contexte safety 8 */
   &BlowBy1Hw_bReq_mem, /* Consigne du rechauffeur de blow by */
   &ThMgt_bTrbWaPmpReq_mem, /* L’état de la commande de la pompe à eau additionnelle turbo */
   &IgSys_agIgBas_mem, /* Avance de consigne de base */
   &Ext_agCkClsExVlvEstimRef0_mem, /* Mesure de position du déphaseur AAC échappement */
   &VlvSys_agCkClsExVlvReqRef0_mem, /* Consigne de position du déphaseur AAC échappement */
   &KnkMgt_prm_agIgKnkDetOfsCyl_0_mem, /* Retraits d’avance du au cliquetis appliqués au cylindre 1 */
   &KnkMgt_prm_agIgKnkDetOfsCyl_1_mem, /* Retraits d’avance du au cliquetis appliqués au cylindre 2 */
   &KnkMgt_prm_agIgKnkDetOfsCyl_2_mem, /* Retraits d’avance du au cliquetis appliqués au cylindre 3 */
   &IgSys_prm_agIgSpCyl_0_mem, /* Avances appliquée au cylindre 1 */
   &IgSys_prm_agIgSpCyl_1_mem, /* Avances appliquée au cylindre 2 */
   &IgSys_prm_agIgSpCyl_2_mem, /* Avances appliquée au cylindre 3 */
   &Ext_agCkOpInVlvEstimRef0_mem, /* Mesure de position du déphaseur AAC admission */
   &VlvSys_agCkOpInVlvReqRef0_mem, /* Consigne de position du déphaseur AAC admission */
   &IgSys_agIgMaxWiPrevAdpMv_mem, /* Avance à l'allumage  maxi */
   &IgSys_agIgMin_mem, /* Avance à l'allumage mini */
   &Rco_applique_purge_mem, /* RCO de commande de l’électrovanne de canister */
   &CanPurg_concFuStmEstim_mem, /* Charge estimée du canister */
   &ThMgt_rPwrECTReq_mem, /* RCO de commande du thermostat piloté */
   &DmpVlvAct_rDmpVlvOplCmdSp_mem, /* RCO de commande de l’électrovanne de dump-valve */
   &Rco_applique_vvt_echap_mem, /* RCO de commande de l’électrovanne du déphaseur AAC échappement */
   &Rco_applique_vvt_adm_mem, /* RCO de commande de l’électrovanne du déphaseur AAC admission */
   &Sonde_riche_aval_mem, /* Etat des sondes aval (riche/pauvre) */
   &Vcpe_cam_offsets_are_learned_mem, /* Etat d’apprentissage du déphaseur AAC échappement */
   &Vcpi_cam_offsets_are_learned_mem, /* Etat d’apprentissage du déphaseur AAC admission */
   &Sonde_riche_amont_mem, /* Etat des sondes On/Off amont (riche/pauvre) */
   &TqSys_tqCkEfcReq_mem, /* Couple moteur effectif objectif par l’avance */
   &Dv_1_app_pos_ped_pc_mem, /* Les valeurs des apprentissages de la position maxi de la pédale d’accélérateur piste 1 */
   &Dv_1_app_pos_ped_pl_mem, /* Les valeurs des apprentissages de la position mini de la pédale d’accélérateur piste 1 */
   &Dv_2_app_pos_ped_pc_mem, /* Les valeurs des apprentissages de la position maxi de la pédale d’accélérateur piste 2 */
   &Dv_2_app_pos_ped_pl_mem, /* Les valeurs des apprentissages de la position mini de la pédale d’accélérateur piste 2 */
   &Tpac_1_limp_home_pos_mem, /* Apprentissages de la position Limp-Home piste 1 */
   &Tpac_1_closed_throttle_pos_mem, /* Apprentissages de la butée mini papillon Piste 1 */
   &Tpac_2_limp_home_pos_mem, /* Apprentissages de la position Limp-Home piste 2 */
   &Tpac_2_closed_throttle_pos_mem, /* Apprentissages de la butée mini papillon Piste 2 */
   &FARSp_rMixtCylSp_mem, /* Consigne de richesse (dans la chambre de combustion) */
   &AirSys_rAirLdReq_mem, /* Remplissage d'air de consigne système */
   &EngM_rAirLdCor_mem, /* Remplissage mesuré système */
   &Av_bmax_corr_appliquee_cyl_0_mem, /* Valeurs des adaptatifs anti-cliquetis du cylindre 1 */
   &Av_bmax_corr_appliquee_cyl_1_mem, /* Valeurs des adaptatifs anti-cliquetis du cylindre 2 */
   &Av_bmax_corr_appliquee_cyl_2_mem, /* Valeurs des adaptatifs anti-cliquetis du cylindre 3 */
   &PFuCtl_agWdPmpCmdReq_mem, /* La commande du régulateur de pression HP */
   &Bruit_moyen_cyl_min_thresh_0_mem, /* Seuil de détection cliquetis du cylindre 1 */
   &Bruit_moyen_cyl_min_thresh_1_mem, /* Seuil de détection cliquetis du cylindre 2 */
   &Bruit_moyen_cyl_min_thresh_2_mem, /* Seuil de détection cliquetis du cylindre 3 */
   &VlvAct_bInOfsFrstLrn_mem, /* Premier apprentissage du déphaseur AàC d'admission effectué */
   &VlvAct_bExOfsFrstLrn_mem, /* Premier apprentissage du déphaseur AàC échappement effectué */
   &Vcpe_cam_offsets_0_mem, /* Apprentissage de la butée basse Déphaseur Echappement cyl1 */
   &Vcpe_cam_offsets_1_mem, /* Apprentissage de la butée basse Déphaseur Echappement cyl2 */
   &Vcpe_cam_offsets_2_mem, /* Apprentissage de la butée basse Déphaseur Echappement cyl3 */
   &Vcpi_cam_offsets_0_mem, /* Apprentissage de la butée basse Déphaseur Admission cyl1 */
   &Vcpi_cam_offsets_1_mem, /* Apprentissage de la butée basse Déphaseur Admission cyl2 */
   &Vcpi_cam_offsets_2_mem, /* Apprentissage de la butée basse Déphaseur Admission cyl3 */
   &Somme_clq_cyl_mem, /* Valeur du bruit mesuré par le capteur cliquetis */
   &CoPtUH_bStPresLo_mem, /* Etat du besoin de vide pour le freinage */
   &CoStrtRStrt_bInh_mem, /* Inhibition démarrage ou redémarrage par le CMM */
   &StaStrtMgt_ctStaAcv_mem, /* Nombre d'activation du démarreur */
   &Veh_stDrvAvl_mem, /* Présence conducteur */
   &CoPtUH_bSTTInh_mem, /* Etat d'inhibition du mode Eco */
   &CoPtUH_stPwt_mem, /* Etat UH */
   &Ext_bPush_mem, /* Push STT */
   &TqSys_tqCkEngReal_mem, /* Couple réel */
   &Ext_pRelBrkAsi_mem, /* Valeur brute de la dépression de l'assistance de freinage */
   &Ext_bStaCmdFctSt_mem, /* Retour du diagnostic BICD */
   &StaStrtMgt_ctStaStrtAcv_mem, /* Nombre d'activations du démarreur lors des premiers démarrages */
   &StaStrtMgt_stStaFbCmd_mem, /* Retour de commande démarrage et redémarrage du démarreur */
   &StaStrtMgt_bStaReq_mem, /* Autorisation filaire de démarrage */
   &CoOptmEl_tqAlt_mem, /* Couple réel prélevé par la machine */
   &BatMgt_uBattMes_mem, /* Tension batterie à ses bornes */
   &SAIMMO_stLockECUReadSt_mem /* Etat de verrouillage ADC/ImmobiliserLockingState */
};


const uint8 GD_au8SizeParam[NB_PARAM] =
{
   1, /* Taille de la variable u8ValueNull : uint8 */
   2, /* Taille de la variable Ext_nEng : uint16 */
   2, /* Taille de la variable Veh_spdVeh : uint16 */
   1, /* Taille de la variable Ext_bMainBrkPedPrssMes : boolean */
   1, /* Taille de la variable Ext_bCluPedPrss : boolean */
   2, /* Taille de la variable Ext_uAccP1SenPwr : uint16 */
   2, /* Taille de la variable Ext_uAccP2SenPwr : uint16 */
   1, /* Taille de la variable AccP_rDrvReq : uint8 */
   1, /* Taille de la variable Ext_bAccPHdPt : boolean */
   1, /* Taille de la variable CoPt_noEgdGearCord : uint8 */
   2, /* Taille de la variable Ext_tCoMes : sint16 */
   1, /* Taille de la variable Ext_bRCDLine : boolean */
   2, /* Taille de la variable ThMgt_tCoReg : sint16 */
   2, /* Taille de la variable VlvAct_nEngExCmFil : uint16 */
   1, /* Taille de la variable Ext_rAltCycOp : uint8 */
   2, /* Taille de la variable Ext_tDsThrMes : sint16 */
   1, /* Taille de la variable CoPTSt_stEng : uint8 */
   2, /* Taille de la variable Ext_tAirExtMes : sint16 */
   1, /* Taille de la variable Ext_bStrtAuth : boolean */
   1, /* Taille de la variable AC_bACClu : boolean */
   1, /* Taille de la variable AC_pwrAC : uint8 */
   2, /* Taille de la variable Ext_upOilMes : uint16 */
   2, /* Taille de la variable Ext_uEngOilLvl : uint16 */
   2, /* Taille de la variable ESLim_tiCntOverNEngMax : uint16 */
   2, /* Taille de la variable Cl_raw_pressure : uint16 */
   2, /* Taille de la variable Ext_uBattMes : sint16 */
   2, /* Taille de la variable Tension_alimentation_1 : uint16 */
   2, /* Taille de la variable Tension_alimentation_2 : uint16 */
   2, /* Taille de la variable Tension_alimentation_3 : uint16 */
   2, /* Taille de la variable Tension_alimentation_4 : uint16 */
   1, /* Taille de la variable Actionneurs : boolean */
   2, /* Taille de la variable Ext_pOilMesRaw : uint16 */
   1, /* Taille de la variable ThMgt_bCmdHiSpdFan : boolean */
   1, /* Taille de la variable ThMgt_bCmdLowSpdFan : boolean */
   1, /* Taille de la variable Ext_bStFanFil : boolean */
   1, /* Taille de la variable Ext_bNeut : boolean */
   2, /* Taille de la variable Cts_range_voltage : uint16 */
   1, /* Taille de la variable CoPtUH_noGearTmpBeg : uint8 */
   1, /* Taille de la variable CoPtUH_noGearTmpEnd : uint8 */
   2, /* Taille de la variable InjSys_pFuSp : uint16 */
   2, /* Taille de la variable Ext_pFuMesWRV : uint16 */
   2, /* Taille de la variable Ext_rOpThr : uint16 */
   2, /* Taille de la variable ThrSys_rOpThrReq : uint16 */
   2, /* Taille de la variable Ext_nEng : uint16 */
   1, /* Taille de la variable Ext_bSecBrkPedPrssMes : boolean */
   2, /* Taille de la variable OilSys_pOilReq : uint16 */
   2, /* Taille de la variable Ext_pAirExtAcq : uint16 */
   2, /* Taille de la variable AccP_rAccP : uint16 */
   2, /* Taille de la variable BatMgt_rBattSoCCor : uint16 */
   2, /* Taille de la variable Ext_rCluPedPrssMes : uint16 */
   2, /* Taille de la variable Ext_rCluPedPrssBrutMes : uint16 */
   2, /* Taille de la variable OilSys_rCtlPmpReq : uint16 */
   2, /* Taille de la variable FTPCtl_rFlowFuTnkPmp : uint16 */
   1, /* Taille de la variable Ext_spdVehReqVSReg : uint8 */
   1, /* Taille de la variable Ext_spdVehReqVSLim : uint8 */
   4, /* Taille de la variable Ext_ctSecEngStop : uint32 */
   2, /* Taille de la variable EngSt_tiDlySync : uint16 */
   2, /* Taille de la variable Ext_pUsThrMesSI : uint16 */
   2, /* Taille de la variable Ext_tDsThrMes : sint16 */
   2, /* Taille de la variable Cl_pressure_result_ad_conv : uint16 */
   2, /* Taille de la variable Ext_upFuMes : uint16 */
   2, /* Taille de la variable Pression_air_result_ad_conv : uint16 */
   2, /* Taille de la variable Temperature_air_result_ad_conv : uint16 */
   2, /* Taille de la variable InM_mfAirThrEstim : uint16 */
   2, /* Taille de la variable TrbAct_rRCOReq : uint16 */
   2, /* Taille de la variable AirSys_pUsThrReq : uint16 */
   2, /* Taille de la variable AirSys_mfAirThrReqFil : uint16 */
   2, /* Taille de la variable Aps_1_raw_filt_position : uint16 */
   2, /* Taille de la variable Aps_2_raw_filt_position : uint16 */
   2, /* Taille de la variable BatMgt_tBattMes : sint16 */
   4, /* Taille de la variable BatMgt_iBattMes : sint32 */
   2, /* Taille de la variable CoPtUH_rMaxCluGc : uint16 */
   2, /* Taille de la variable Ext_nEngCmInMes : uint16 */
   4, /* Taille de la variable Ext_dstVehTotMes : uint32 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts1 : uint16 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts2 : uint16 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts3 : uint16 */
   1, /* Taille de la variable ThMgt_stPosnFSFReq : uint8 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts4 : uint16 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts5 : uint16 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts6 : uint16 */
   1, /* Taille de la variable Ext_rAltCycOp : uint8 */
   1, /* Taille de la variable LsSys_rLsDsMainOxCHeatPwrReq : uint8 */
   1, /* Taille de la variable LsSys_rLsUsMainOxCHeatPwrReq : uint8 */
   1, /* Taille de la variable ACCmd_stReq : uint8 */
   1, /* Taille de la variable VSCtl_stVSRegExtd : uint8 */
   1, /* Taille de la variable Diag_on : boolean */
   1, /* Taille de la variable CoPt_stDrvTra : boolean */
   1, /* Taille de la variable Dnstr_conds_met : boolean */
   1, /* Taille de la variable VSCtl_stVSLimExtd : uint8 */
   1, /* Taille de la variable Ext_bAcvSta : boolean */
   1, /* Taille de la variable Lambda_closed_loop : boolean */
   4, /* Taille de la variable Ext_tiCurVehTmr : uint32 */
   4, /* Taille de la variable InjrSys_prm_tiInjH1ReqCyl : uint32 */
   4, /* Taille de la variable InjrSys_prm_tiInjH1ReqCyl : uint32 */
   4, /* Taille de la variable InjrSys_prm_tiInjH1ReqCyl : uint32 */
   2, /* Taille de la variable TqSys_tqIdcReq : sint16 */
   2, /* Taille de la variable Tension_sonde_aval_brute : uint16 */
   2, /* Taille de la variable Tension_sonde_amont_brute : uint16 */
   2, /* Taille de la variable EcuSt_ctHotRst_Count : uint16 */
   2, /* Taille de la variable Ext_pDsThrMes : sint16 */
   2, /* Taille de la variable AirSys_prm_pInMnfReq : uint16 */
   1, /* Taille de la variable Flev_fuel_level : uint8 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts7 : uint16 */
   2, /* Taille de la variable SftyMgt_prm_bDftHisAfts8 : uint16 */
   1, /* Taille de la variable BlowBy1Hw_bReq : boolean */
   1, /* Taille de la variable ThMgt_bTrbWaPmpReq : boolean */
   1, /* Taille de la variable IgSys_agIgBas : uint8 */
   2, /* Taille de la variable Ext_agCkClsExVlvEstimRef0 : sint16 */
   1, /* Taille de la variable VlvSys_agCkClsExVlvReqRef0 : uint8 */
   1, /* Taille de la variable KnkMgt_prm_agIgKnkDetOfsCyl : uint8 */
   1, /* Taille de la variable KnkMgt_prm_agIgKnkDetOfsCyl : uint8 */
   1, /* Taille de la variable KnkMgt_prm_agIgKnkDetOfsCyl : uint8 */
   1, /* Taille de la variable IgSys_prm_agIgSpCyl : uint8 */
   1, /* Taille de la variable IgSys_prm_agIgSpCyl : uint8 */
   1, /* Taille de la variable IgSys_prm_agIgSpCyl : uint8 */
   2, /* Taille de la variable Ext_agCkOpInVlvEstimRef0 : sint16 */
   1, /* Taille de la variable VlvSys_agCkOpInVlvReqRef0 : uint8 */
   1, /* Taille de la variable IgSys_agIgMaxWiPrevAdpMv : uint8 */
   1, /* Taille de la variable IgSys_agIgMin : uint8 */
   1, /* Taille de la variable Rco_applique_purge : uint8 */
   2, /* Taille de la variable CanPurg_concFuStmEstim : uint16 */
   1, /* Taille de la variable ThMgt_rPwrECTReq : uint8 */
   2, /* Taille de la variable DmpVlvAct_rDmpVlvOplCmdSp : uint16 */
   2, /* Taille de la variable Rco_applique_vvt_echap : uint16 */
   2, /* Taille de la variable Rco_applique_vvt_adm : uint16 */
   1, /* Taille de la variable Sonde_riche_aval : boolean */
   1, /* Taille de la variable Vcpe_cam_offsets_are_learned : boolean */
   1, /* Taille de la variable Vcpi_cam_offsets_are_learned : boolean */
   1, /* Taille de la variable Sonde_riche_amont : boolean */
   2, /* Taille de la variable TqSys_tqCkEfcReq : sint16 */
   2, /* Taille de la variable Dv_1_app_pos_ped_pc : uint16 */
   2, /* Taille de la variable Dv_1_app_pos_ped_pl : uint16 */
   2, /* Taille de la variable Dv_2_app_pos_ped_pc : uint16 */
   2, /* Taille de la variable Dv_2_app_pos_ped_pl : uint16 */
   2, /* Taille de la variable Tpac_1_limp_home_pos : uint16 */
   2, /* Taille de la variable Tpac_1_closed_throttle_pos : uint16 */
   2, /* Taille de la variable Tpac_2_limp_home_pos : uint16 */
   2, /* Taille de la variable Tpac_2_closed_throttle_pos : uint16 */
   2, /* Taille de la variable FARSp_rMixtCylSp : uint16 */
   2, /* Taille de la variable AirSys_rAirLdReq : uint16 */
   2, /* Taille de la variable EngM_rAirLdCor : uint16 */
   1, /* Taille de la variable Av_bmax_corr_appliquee_cyl : sint8 */
   1, /* Taille de la variable Av_bmax_corr_appliquee_cyl : sint8 */
   1, /* Taille de la variable Av_bmax_corr_appliquee_cyl : sint8 */
   2, /* Taille de la variable PFuCtl_agWdPmpCmdReq : uint16 */
   2, /* Taille de la variable Bruit_moyen_cyl_min_thresh : uint16 */
   2, /* Taille de la variable Bruit_moyen_cyl_min_thresh : uint16 */
   2, /* Taille de la variable Bruit_moyen_cyl_min_thresh : uint16 */
   1, /* Taille de la variable VlvAct_bInOfsFrstLrn : boolean */
   1, /* Taille de la variable VlvAct_bExOfsFrstLrn : boolean */
   2, /* Taille de la variable Vcpe_cam_offsets : uint16 */
   2, /* Taille de la variable Vcpe_cam_offsets : uint16 */
   2, /* Taille de la variable Vcpe_cam_offsets : uint16 */
   2, /* Taille de la variable Vcpi_cam_offsets : uint16 */
   2, /* Taille de la variable Vcpi_cam_offsets : uint16 */
   2, /* Taille de la variable Vcpi_cam_offsets : uint16 */
   2, /* Taille de la variable Somme_clq_cyl : uint16 */
   1, /* Taille de la variable CoPtUH_bStPresLo : boolean */
   1, /* Taille de la variable CoStrtRStrt_bInh : boolean */
   4, /* Taille de la variable StaStrtMgt_ctStaAcv : uint32 */
   1, /* Taille de la variable Veh_stDrvAvl : uint8 */
   1, /* Taille de la variable CoPtUH_bSTTInh : boolean */
   1, /* Taille de la variable CoPtUH_stPwt : uint8 */
   1, /* Taille de la variable Ext_bPush : boolean */
   2, /* Taille de la variable TqSys_tqCkEngReal : sint16 */
   1, /* Taille de la variable Ext_pRelBrkAsi : uint8 */
   1, /* Taille de la variable Ext_bStaCmdFctSt : boolean */
   4, /* Taille de la variable StaStrtMgt_ctStaStrtAcv : uint32 */
   1, /* Taille de la variable StaStrtMgt_stStaFbCmd : uint8 */
   1, /* Taille de la variable StaStrtMgt_bStaReq : boolean */
   2, /* Taille de la variable CoOptmEl_tqAlt : sint16 */
   2, /* Taille de la variable BatMgt_uBattMes : uint16 */
   1  /* Taille de la variable SAIMMO_stLockECUReadSt : uint8 */
};


const boolean GD_abSignParam[NB_PARAM] =
{
   0, /* Signe de la variable u8ValueNull : uint8 */
   0, /* Signe de la variable Ext_nEng : uint16 */
   0, /* Signe de la variable Veh_spdVeh : uint16 */
   0, /* Signe de la variable Ext_bMainBrkPedPrssMes : boolean */
   0, /* Signe de la variable Ext_bCluPedPrss : boolean */
   0, /* Signe de la variable Ext_uAccP1SenPwr : uint16 */
   0, /* Signe de la variable Ext_uAccP2SenPwr : uint16 */
   0, /* Signe de la variable AccP_rDrvReq : uint8 */
   0, /* Signe de la variable Ext_bAccPHdPt : boolean */
   0, /* Signe de la variable CoPt_noEgdGearCord : uint8 */
   1, /* Signe de la variable Ext_tCoMes : sint16 */
   0, /* Signe de la variable Ext_bRCDLine : boolean */
   1, /* Signe de la variable ThMgt_tCoReg : sint16 */
   0, /* Signe de la variable VlvAct_nEngExCmFil : uint16 */
   0, /* Signe de la variable Ext_rAltCycOp : uint8 */
   1, /* Signe de la variable Ext_tDsThrMes : sint16 */
   0, /* Signe de la variable CoPTSt_stEng : uint8 */
   1, /* Signe de la variable Ext_tAirExtMes : sint16 */
   0, /* Signe de la variable Ext_bStrtAuth : boolean */
   0, /* Signe de la variable AC_bACClu : boolean */
   0, /* Signe de la variable AC_pwrAC : uint8 */
   0, /* Signe de la variable Ext_upOilMes : uint16 */
   0, /* Signe de la variable Ext_uEngOilLvl : uint16 */
   0, /* Signe de la variable ESLim_tiCntOverNEngMax : uint16 */
   0, /* Signe de la variable Cl_raw_pressure : uint16 */
   1, /* Signe de la variable Ext_uBattMes : sint16 */
   0, /* Signe de la variable Tension_alimentation_1 : uint16 */
   0, /* Signe de la variable Tension_alimentation_2 : uint16 */
   0, /* Signe de la variable Tension_alimentation_3 : uint16 */
   0, /* Signe de la variable Tension_alimentation_4 : uint16 */
   0, /* Signe de la variable Actionneurs : boolean */
   0, /* Signe de la variable Ext_pOilMesRaw : uint16 */
   0, /* Signe de la variable ThMgt_bCmdHiSpdFan : boolean */
   0, /* Signe de la variable ThMgt_bCmdLowSpdFan : boolean */
   0, /* Signe de la variable Ext_bStFanFil : boolean */
   0, /* Signe de la variable Ext_bNeut : boolean */
   0, /* Signe de la variable Cts_range_voltage : uint16 */
   0, /* Signe de la variable CoPtUH_noGearTmpBeg : uint8 */
   0, /* Signe de la variable CoPtUH_noGearTmpEnd : uint8 */
   0, /* Signe de la variable InjSys_pFuSp : uint16 */
   0, /* Signe de la variable Ext_pFuMesWRV : uint16 */
   0, /* Signe de la variable Ext_rOpThr : uint16 */
   0, /* Signe de la variable ThrSys_rOpThrReq : uint16 */
   0, /* Signe de la variable Ext_nEng : uint16 */
   0, /* Signe de la variable Ext_bSecBrkPedPrssMes : boolean */
   0, /* Signe de la variable OilSys_pOilReq : uint16 */
   0, /* Signe de la variable Ext_pAirExtAcq : uint16 */
   0, /* Signe de la variable AccP_rAccP : uint16 */
   0, /* Signe de la variable BatMgt_rBattSoCCor : uint16 */
   0, /* Signe de la variable Ext_rCluPedPrssMes : uint16 */
   0, /* Signe de la variable Ext_rCluPedPrssBrutMes : uint16 */
   0, /* Signe de la variable OilSys_rCtlPmpReq : uint16 */
   0, /* Signe de la variable FTPCtl_rFlowFuTnkPmp : uint16 */
   0, /* Signe de la variable Ext_spdVehReqVSReg : uint8 */
   0, /* Signe de la variable Ext_spdVehReqVSLim : uint8 */
   0, /* Signe de la variable Ext_ctSecEngStop : uint32 */
   0, /* Signe de la variable EngSt_tiDlySync : uint16 */
   0, /* Signe de la variable Ext_pUsThrMesSI : uint16 */
   1, /* Signe de la variable Ext_tDsThrMes : sint16 */
   0, /* Signe de la variable Cl_pressure_result_ad_conv : uint16 */
   0, /* Signe de la variable Ext_upFuMes : uint16 */
   0, /* Signe de la variable Pression_air_result_ad_conv : uint16 */
   0, /* Signe de la variable Temperature_air_result_ad_conv : uint16 */
   0, /* Signe de la variable InM_mfAirThrEstim : uint16 */
   0, /* Signe de la variable TrbAct_rRCOReq : uint16 */
   0, /* Signe de la variable AirSys_pUsThrReq : uint16 */
   0, /* Signe de la variable AirSys_mfAirThrReqFil : uint16 */
   0, /* Signe de la variable Aps_1_raw_filt_position : uint16 */
   0, /* Signe de la variable Aps_2_raw_filt_position : uint16 */
   1, /* Signe de la variable BatMgt_tBattMes : sint16 */
   1, /* Signe de la variable BatMgt_iBattMes : sint32 */
   0, /* Signe de la variable CoPtUH_rMaxCluGc : uint16 */
   0, /* Signe de la variable Ext_nEngCmInMes : uint16 */
   0, /* Signe de la variable Ext_dstVehTotMes : uint32 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts1 : uint16 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts2 : uint16 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts3 : uint16 */
   0, /* Signe de la variable ThMgt_stPosnFSFReq : uint8 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts4 : uint16 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts5 : uint16 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts6 : uint16 */
   0, /* Signe de la variable Ext_rAltCycOp : uint8 */
   0, /* Signe de la variable LsSys_rLsDsMainOxCHeatPwrReq : uint8 */
   0, /* Signe de la variable LsSys_rLsUsMainOxCHeatPwrReq : uint8 */
   0, /* Signe de la variable ACCmd_stReq : uint8 */
   0, /* Signe de la variable VSCtl_stVSRegExtd : uint8 */
   0, /* Signe de la variable Diag_on : boolean */
   0, /* Signe de la variable CoPt_stDrvTra : boolean */
   0, /* Signe de la variable Dnstr_conds_met : boolean */
   0, /* Signe de la variable VSCtl_stVSLimExtd : uint8 */
   0, /* Signe de la variable Ext_bAcvSta : boolean */
   0, /* Signe de la variable Lambda_closed_loop : boolean */
   0, /* Signe de la variable Ext_tiCurVehTmr : uint32 */
   0, /* Signe de la variable InjrSys_prm_tiInjH1ReqCyl : uint32 */
   0, /* Signe de la variable InjrSys_prm_tiInjH1ReqCyl : uint32 */
   0, /* Signe de la variable InjrSys_prm_tiInjH1ReqCyl : uint32 */
   1, /* Signe de la variable TqSys_tqIdcReq : sint16 */
   0, /* Signe de la variable Tension_sonde_aval_brute : uint16 */
   0, /* Signe de la variable Tension_sonde_amont_brute : uint16 */
   0, /* Signe de la variable EcuSt_ctHotRst_Count : uint16 */
   1, /* Signe de la variable Ext_pDsThrMes : sint16 */
   0, /* Signe de la variable AirSys_prm_pInMnfReq : uint16 */
   0, /* Signe de la variable Flev_fuel_level : uint8 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts7 : uint16 */
   0, /* Signe de la variable SftyMgt_prm_bDftHisAfts8 : uint16 */
   0, /* Signe de la variable BlowBy1Hw_bReq : boolean */
   0, /* Signe de la variable ThMgt_bTrbWaPmpReq : boolean */
   0, /* Signe de la variable IgSys_agIgBas : uint8 */
   1, /* Signe de la variable Ext_agCkClsExVlvEstimRef0 : sint16 */
   0, /* Signe de la variable VlvSys_agCkClsExVlvReqRef0 : uint8 */
   0, /* Signe de la variable KnkMgt_prm_agIgKnkDetOfsCyl : uint8 */
   0, /* Signe de la variable KnkMgt_prm_agIgKnkDetOfsCyl : uint8 */
   0, /* Signe de la variable KnkMgt_prm_agIgKnkDetOfsCyl : uint8 */
   0, /* Signe de la variable IgSys_prm_agIgSpCyl : uint8 */
   0, /* Signe de la variable IgSys_prm_agIgSpCyl : uint8 */
   0, /* Signe de la variable IgSys_prm_agIgSpCyl : uint8 */
   1, /* Signe de la variable Ext_agCkOpInVlvEstimRef0 : sint16 */
   0, /* Signe de la variable VlvSys_agCkOpInVlvReqRef0 : uint8 */
   0, /* Signe de la variable IgSys_agIgMaxWiPrevAdpMv : uint8 */
   0, /* Signe de la variable IgSys_agIgMin : uint8 */
   0, /* Signe de la variable Rco_applique_purge : uint8 */
   0, /* Signe de la variable CanPurg_concFuStmEstim : uint16 */
   0, /* Signe de la variable ThMgt_rPwrECTReq : uint8 */
   0, /* Signe de la variable DmpVlvAct_rDmpVlvOplCmdSp : uint16 */
   0, /* Signe de la variable Rco_applique_vvt_echap : uint16 */
   0, /* Signe de la variable Rco_applique_vvt_adm : uint16 */
   0, /* Signe de la variable Sonde_riche_aval : boolean */
   0, /* Signe de la variable Vcpe_cam_offsets_are_learned : boolean */
   0, /* Signe de la variable Vcpi_cam_offsets_are_learned : boolean */
   0, /* Signe de la variable Sonde_riche_amont : boolean */
   1, /* Signe de la variable TqSys_tqCkEfcReq : sint16 */
   0, /* Signe de la variable Dv_1_app_pos_ped_pc : uint16 */
   0, /* Signe de la variable Dv_1_app_pos_ped_pl : uint16 */
   0, /* Signe de la variable Dv_2_app_pos_ped_pc : uint16 */
   0, /* Signe de la variable Dv_2_app_pos_ped_pl : uint16 */
   0, /* Signe de la variable Tpac_1_limp_home_pos : uint16 */
   0, /* Signe de la variable Tpac_1_closed_throttle_pos : uint16 */
   0, /* Signe de la variable Tpac_2_limp_home_pos : uint16 */
   0, /* Signe de la variable Tpac_2_closed_throttle_pos : uint16 */
   0, /* Signe de la variable FARSp_rMixtCylSp : uint16 */
   0, /* Signe de la variable AirSys_rAirLdReq : uint16 */
   0, /* Signe de la variable EngM_rAirLdCor : uint16 */
   1, /* Signe de la variable Av_bmax_corr_appliquee_cyl : sint8 */
   1, /* Signe de la variable Av_bmax_corr_appliquee_cyl : sint8 */
   1, /* Signe de la variable Av_bmax_corr_appliquee_cyl : sint8 */
   0, /* Signe de la variable PFuCtl_agWdPmpCmdReq : uint16 */
   0, /* Signe de la variable Bruit_moyen_cyl_min_thresh : uint16 */
   0, /* Signe de la variable Bruit_moyen_cyl_min_thresh : uint16 */
   0, /* Signe de la variable Bruit_moyen_cyl_min_thresh : uint16 */
   0, /* Signe de la variable VlvAct_bInOfsFrstLrn : boolean */
   0, /* Signe de la variable VlvAct_bExOfsFrstLrn : boolean */
   0, /* Signe de la variable Vcpe_cam_offsets : uint16 */
   0, /* Signe de la variable Vcpe_cam_offsets : uint16 */
   0, /* Signe de la variable Vcpe_cam_offsets : uint16 */
   0, /* Signe de la variable Vcpi_cam_offsets : uint16 */
   0, /* Signe de la variable Vcpi_cam_offsets : uint16 */
   0, /* Signe de la variable Vcpi_cam_offsets : uint16 */
   0, /* Signe de la variable Somme_clq_cyl : uint16 */
   0, /* Signe de la variable CoPtUH_bStPresLo : boolean */
   0, /* Signe de la variable CoStrtRStrt_bInh : boolean */
   0, /* Signe de la variable StaStrtMgt_ctStaAcv : uint32 */
   0, /* Signe de la variable Veh_stDrvAvl : uint8 */
   0, /* Signe de la variable CoPtUH_bSTTInh : boolean */
   0, /* Signe de la variable CoPtUH_stPwt : uint8 */
   0, /* Signe de la variable Ext_bPush : boolean */
   1, /* Signe de la variable TqSys_tqCkEngReal : sint16 */
   0, /* Signe de la variable Ext_pRelBrkAsi : uint8 */
   0, /* Signe de la variable Ext_bStaCmdFctSt : boolean */
   0, /* Signe de la variable StaStrtMgt_ctStaStrtAcv : uint32 */
   0, /* Signe de la variable StaStrtMgt_stStaFbCmd : uint8 */
   0, /* Signe de la variable StaStrtMgt_bStaReq : boolean */
   1, /* Signe de la variable CoOptmEl_tqAlt : sint16 */
   0, /* Signe de la variable BatMgt_uBattMes : uint16 */
   0  /* Signe de la variable SAIMMO_stLockECUReadSt : uint8 */
};


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Recupération des variables                                  */
/* !Number      : FCT1.01                                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : MEM_vidArrayInit                                               */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidArrayInit(void)
{
   boolean bLocalCalc;
   uint8   u8LocalCalc;
   uint16  u16LocalCalc;
   uint16  u16LocalCalc2;
   uint16  u16Localmod;
   uint32  u32LocalCalc;
   uint32  u32LocalNum;
   uint32  u32LocalDen;


   VEMS_vidGET(Ext_nEng, Ext_nEng_mem);
   VEMS_vidGET(Veh_spdVeh, Veh_spdVeh_mem);
   VEMS_vidGET(Ext_bMainBrkPedPrssMes, Ext_bMainBrkPedPrssMes_mem);
   VEMS_vidGET(Ext_bCluPedPrss, Ext_bCluPedPrss_mem);
   VEMS_vidGET(Ext_uAccP1SenPwr, Ext_uAccP1SenPwr_mem);
   VEMS_vidGET(Ext_uAccP2SenPwr, Ext_uAccP2SenPwr_mem);
   VEMS_vidGET(AccP_rDrvReq, AccP_rDrvReq_mem);
   VEMS_vidGET(Ext_bAccPHdPt, Ext_bAccPHdPt_mem);
   VEMS_vidGET(CoPt_noEgdGearCord, CoPt_noEgdGearCord_mem);
   VEMS_vidGET(Ext_tCoMes, Ext_tCoMes_mem);
   VEMS_vidGET(Ext_bRCDLine, Ext_bRCDLine_mem);
   VEMS_vidGET(ThMgt_tCoReg, ThMgt_tCoReg_mem);
   VEMS_vidGET(VlvAct_nEngExCmFil, VlvAct_nEngExCmFil_mem);
   VEMS_vidGET(Ext_rAltCycOp, Ext_rAltCycOp_mem);
   VEMS_vidGET(Ext_tDsThrMes, Ext_tDsThrMes_mem);
   VEMS_vidGET(CoPTSt_stEng, CoPTSt_stEng_mem);
   VEMS_vidGET(Ext_tAirExtMes, Ext_tAirExtMes_mem);
   VEMS_vidGET(Ext_bStrtAuth, bLocalCalc);
   Ext_bStrtAuth_mem = !(bLocalCalc);
   
   VEMS_vidGET(AC_bACClu, AC_bACClu_mem);
   VEMS_vidGET(AC_pwrAC, AC_pwrAC_mem);
   VEMS_vidGET(Ext_upOilMes, Ext_upOilMes_mem);
   VEMS_vidGET(Ext_uEngOilLvl, Ext_uEngOilLvl_mem);
   VEMS_vidGET(ESLim_tiCntOverNEngMax, ESLim_tiCntOverNEngMax_mem);
   VEMS_vidGET(Cl_raw_pressure, Cl_raw_pressure_mem);
   VEMS_vidGET(Ext_uBattMes, Ext_uBattMes_mem);
   VEMS_vidGET(Tension_alimentation_1, Tension_alimentation_1_mem);
   VEMS_vidGET(Tension_alimentation_2, Tension_alimentation_2_mem);
   VEMS_vidGET(Tension_alimentation_3, Tension_alimentation_3_mem);
   VEMS_vidGET(Tension_alimentation_4, Tension_alimentation_4_mem);
   VEMS_vidGET(Actionneurs, Actionneurs_mem);
   VEMS_vidGET(Ext_pOilMesRaw, Ext_pOilMesRaw_mem);
   VEMS_vidGET(ThMgt_bCmdHiSpdFan, ThMgt_bCmdHiSpdFan_mem);
   VEMS_vidGET(ThMgt_bCmdLowSpdFan, ThMgt_bCmdLowSpdFan_mem);
   VEMS_vidGET(Ext_bStFanFil, Ext_bStFanFil_mem);
   VEMS_vidGET(Ext_bNeut, Ext_bNeut_mem);
   VEMS_vidGET(Cts_range_voltage, Cts_range_voltage_mem);
   VEMS_vidGET(CoPtUH_noGearTmpBeg, CoPtUH_noGearTmpBeg_mem);
   VEMS_vidGET(CoPtUH_noGearTmpEnd, CoPtUH_noGearTmpEnd_mem);
   VEMS_vidGET(InjSys_pFuSp, InjSys_pFuSp_mem);
   VEMS_vidGET(Ext_pFuMesWRV, Ext_pFuMesWRV_mem);
   VEMS_vidGET(Ext_rOpThr, Ext_rOpThr_mem);
   VEMS_vidGET(ThrSys_rOpThrReq, ThrSys_rOpThrReq_mem);
   VEMS_vidGET(Ext_nEng, Ext_nEng_mem);
   VEMS_vidGET(Ext_bSecBrkPedPrssMes, Ext_bSecBrkPedPrssMes_mem);
   VEMS_vidGET(OilSys_pOilReq, OilSys_pOilReq_mem);
   VEMS_vidGET(Ext_pAirExtAcq, Ext_pAirExtAcq_mem);
   VEMS_vidGET(AccP_rAccP, AccP_rAccP_mem);
   VEMS_vidGET(BatMgt_rBattSoCCor, BatMgt_rBattSoCCor_mem);
   VEMS_vidGET(Ext_rCluPedPrssMes, Ext_rCluPedPrssMes_mem);
   VEMS_vidGET(Ext_rCluPedPrssBrutMes, Ext_rCluPedPrssBrutMes_mem);
   VEMS_vidGET(OilSys_rCtlPmpReq, OilSys_rCtlPmpReq_mem);
   VEMS_vidGET(FTPCtl_rFlowFuTnkPmp, FTPCtl_rFlowFuTnkPmp_mem);
   VEMS_vidGET(Ext_spdVehReqVSReg, Ext_spdVehReqVSReg_mem);
   VEMS_vidGET(Ext_spdVehReqVSLim, Ext_spdVehReqVSLim_mem);
   VEMS_vidGET(Ext_ctSecEngStop, Ext_ctSecEngStop_mem);
   VEMS_vidGET(EngSt_tiDlySync, EngSt_tiDlySync_mem);
   VEMS_vidGET(Ext_pUsThrMesSI, Ext_pUsThrMesSI_mem);
   VEMS_vidGET(Ext_tDsThrMes, Ext_tDsThrMes_mem);
   VEMS_vidGET(Cl_pressure_result_ad_conv, Cl_pressure_result_ad_conv_mem);
   VEMS_vidGET(Ext_upFuMes, Ext_upFuMes_mem);
   VEMS_vidGET(Pression_air_result_ad_conv, Pression_air_result_ad_conv_mem);
   VEMS_vidGET(Temperature_air_result_ad_conv, Temperature_air_result_ad_conv_mem);
   VEMS_vidGET(InM_mfAirThrEstim, InM_mfAirThrEstim_mem);
   VEMS_vidGET(TrbAct_rRCOReq, TrbAct_rRCOReq_mem);
   VEMS_vidGET(AirSys_pUsThrReq, AirSys_pUsThrReq_mem);
   VEMS_vidGET(AirSys_mfAirThrReqFil, AirSys_mfAirThrReqFil_mem);
   VEMS_vidGET(Aps_1_raw_filt_position, Aps_1_raw_filt_position_mem);
   VEMS_vidGET(Aps_2_raw_filt_position, Aps_2_raw_filt_position_mem);
   VEMS_vidGET(BatMgt_tBattMes, BatMgt_tBattMes_mem);
   VEMS_vidGET(BatMgt_iBattMes, BatMgt_iBattMes_mem);
   VEMS_vidGET(CoPtUH_rMaxCluGc, CoPtUH_rMaxCluGc_mem);
   VEMS_vidGET(Ext_nEngCmInMes, Ext_nEngCmInMes_mem);
   VEMS_vidGET(Ext_dstVehTotMes, Ext_dstVehTotMes_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts1, SftyMgt_prm_bDftHisAfts1_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts2, SftyMgt_prm_bDftHisAfts2_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts3, SftyMgt_prm_bDftHisAfts3_mem);
   VEMS_vidGET(ThMgt_stPosnFSFReq, ThMgt_stPosnFSFReq_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts4, SftyMgt_prm_bDftHisAfts4_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts5, SftyMgt_prm_bDftHisAfts5_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts6, SftyMgt_prm_bDftHisAfts6_mem);
   VEMS_vidGET(Ext_rAltCycOp, Ext_rAltCycOp_mem);
   VEMS_vidGET(LsSys_rLsDsMainOxCHeatPwrReq, LsSys_rLsDsMainOxCHeatPwrReq_mem);
   VEMS_vidGET(LsSys_rLsUsMainOxCHeatPwrReq, LsSys_rLsUsMainOxCHeatPwrReq_mem);
   VEMS_vidGET(ACCmd_stReq, ACCmd_stReq_mem);
   VEMS_vidGET(VSCtl_stVSRegExtd, VSCtl_stVSRegExtd_mem);
   VEMS_vidGET(Diag_on, Diag_on_mem);
   VEMS_vidGET(CoPt_stDrvTra, CoPt_stDrvTra_mem);
   VEMS_vidGET(Dnstr_conds_met, Dnstr_conds_met_mem);
   VEMS_vidGET(VSCtl_stVSLimExtd, VSCtl_stVSLimExtd_mem);
   VEMS_vidGET(Ext_bAcvSta, Ext_bAcvSta_mem);
   VEMS_vidGET(Lambda_closed_loop, Lambda_closed_loop_mem);
   VEMS_vidGET(Ext_tiCurVehTmr, Ext_tiCurVehTmr_mem);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl, 0, InjrSys_prm_tiInjH1ReqCyl_0_mem);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl, 1, InjrSys_prm_tiInjH1ReqCyl_1_mem);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl, 2, InjrSys_prm_tiInjH1ReqCyl_2_mem);
   VEMS_vidGET(TqSys_tqIdcReq, TqSys_tqIdcReq_mem);
   VEMS_vidGET(Tension_sonde_aval_brute, Tension_sonde_aval_brute_mem);
   VEMS_vidGET(Tension_sonde_amont_brute, Tension_sonde_amont_brute_mem);
   VEMS_vidGET(EcuSt_ctHotRst_Count, EcuSt_ctHotRst_Count_mem);
   VEMS_vidGET(Ext_pDsThrMes, Ext_pDsThrMes_mem);
   VEMS_vidGET1DArrayElement(AirSys_prm_pInMnfReq, 0, AirSys_prm_pInMnfReq_0_mem);
   VEMS_vidGET(Flev_fuel_level, Flev_fuel_level_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts7, SftyMgt_prm_bDftHisAfts7_mem);
   VEMS_vidGET(SftyMgt_prm_bDftHisAfts8, SftyMgt_prm_bDftHisAfts8_mem);
   VEMS_vidGET(BlowBy1Hw_bReq, BlowBy1Hw_bReq_mem);
   VEMS_vidGET(ThMgt_bTrbWaPmpReq, ThMgt_bTrbWaPmpReq_mem);
   VEMS_vidGET(IgSys_agIgBas, IgSys_agIgBas_mem);
   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, Ext_agCkClsExVlvEstimRef0_mem);
   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, VlvSys_agCkClsExVlvReqRef0_mem);
   VEMS_vidGET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl, 0, KnkMgt_prm_agIgKnkDetOfsCyl_0_mem);
   VEMS_vidGET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl, 1, KnkMgt_prm_agIgKnkDetOfsCyl_1_mem);
   VEMS_vidGET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl, 2, KnkMgt_prm_agIgKnkDetOfsCyl_2_mem);
   VEMS_vidGET1DArrayElement(IgSys_prm_agIgSpCyl, 0, IgSys_prm_agIgSpCyl_0_mem);
   VEMS_vidGET1DArrayElement(IgSys_prm_agIgSpCyl, 1, IgSys_prm_agIgSpCyl_1_mem);
   VEMS_vidGET1DArrayElement(IgSys_prm_agIgSpCyl, 2, IgSys_prm_agIgSpCyl_2_mem);
   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, Ext_agCkOpInVlvEstimRef0_mem);
   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, VlvSys_agCkOpInVlvReqRef0_mem);
   VEMS_vidGET(IgSys_agIgMaxWiPrevAdpMv, IgSys_agIgMaxWiPrevAdpMv_mem);
   VEMS_vidGET(IgSys_agIgMin, IgSys_agIgMin_mem);
   VEMS_vidGET(Rco_applique_purge, Rco_applique_purge_mem);
   VEMS_vidGET(CanPurg_concFuStmEstim, CanPurg_concFuStmEstim_mem);
   VEMS_vidGET(ThMgt_rPwrECTReq, ThMgt_rPwrECTReq_mem);
   VEMS_vidGET(DmpVlvAct_rDmpVlvOplCmdSp, DmpVlvAct_rDmpVlvOplCmdSp_mem);
   VEMS_vidGET(Rco_applique_vvt_echap, Rco_applique_vvt_echap_mem);
   VEMS_vidGET(Rco_applique_vvt_adm, Rco_applique_vvt_adm_mem);
   VEMS_vidGET(Sonde_riche_aval, Sonde_riche_aval_mem);
   VEMS_vidGET(Vcpe_cam_offsets_are_learned, Vcpe_cam_offsets_are_learned_mem);
   VEMS_vidGET(Vcpi_cam_offsets_are_learned, Vcpi_cam_offsets_are_learned_mem);
   VEMS_vidGET(Sonde_riche_amont, Sonde_riche_amont_mem);
   VEMS_vidGET(TqSys_tqCkEfcReq, TqSys_tqCkEfcReq_mem);
   VEMS_vidGET(Tension_alimentation_aps, u16LocalCalc);
   u32LocalCalc = (uint32)(u16LocalCalc * 3125);
   VEMS_vidGET(Dv_1_app_pos_ped_pc, u16LocalCalc2);
   u32LocalNum = MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalCalc2,
                                                u32LocalCalc,
                                                4194304);
   Dv_1_app_pos_ped_pc_mem = (uint16)MATHSRV_udtMIN(u32LocalNum, 50000);

   VEMS_vidGET(Tension_alimentation_aps, u16LocalCalc);
   u32LocalCalc = (uint32)(u16LocalCalc * 3125);
   VEMS_vidGET(Dv_1_app_pos_ped_pl, u16LocalCalc2);
   u32LocalNum = MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalCalc2,
                                                u32LocalCalc,
                                                4194304);
   Dv_1_app_pos_ped_pl_mem = (uint16)MATHSRV_udtMIN(u32LocalNum, 50000);
   VEMS_vidGET(Tension_alimentation_aps, u16LocalCalc);
   u32LocalCalc = (uint32)(u16LocalCalc * 3125);
   VEMS_vidGET(Dv_2_app_pos_ped_pc, u16LocalCalc2);
   u32LocalNum = MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalCalc2,
                                                u32LocalCalc,
                                                4194304);
   Dv_2_app_pos_ped_pc_mem = (uint16)MATHSRV_udtMIN(u32LocalNum, 50000);
   VEMS_vidGET(Tension_alimentation_aps, u16LocalCalc);
   u32LocalCalc = (uint32)(u16LocalCalc * 3125);
   VEMS_vidGET(Dv_2_app_pos_ped_pl, u16LocalCalc2);
   u32LocalNum = MATHSRV_u32Mul_u32_u32_div_u32((uint32)u16LocalCalc2,
                                                u32LocalCalc,
                                                4194304);
   Dv_2_app_pos_ped_pl_mem = (uint16)MATHSRV_udtMIN(u32LocalNum, 50000);
   VEMS_vidGET(Tension_alimentation_thr, u16LocalCalc);
   VEMS_vidGET(Tpac_1_limp_home_pos, u16LocalCalc2);
   u32LocalCalc = (uint32)( u16LocalCalc
                          * u16LocalCalc2);
   u32LocalCalc = ( (u32LocalCalc / 262144) * 3125)
                  + (((u32LocalCalc % 262144) * 3125) / 262144);
   Tpac_1_limp_home_pos_mem = (uint16)MATHSRV_udtMIN(u32LocalCalc, 50000);
   VEMS_vidGET(Tension_alimentation_thr, u16LocalCalc);
   VEMS_vidGET(Tpac_1_closed_throttle_pos, u16LocalCalc2);
   u32LocalCalc = (uint32)( u16LocalCalc
                          * u16LocalCalc2);
   u32LocalCalc = ( (u32LocalCalc / 262144) * 3125)
                  + (((u32LocalCalc % 262144) * 3125) / 262144);
   Tpac_1_closed_throttle_pos_mem = (uint16)MATHSRV_udtMIN(u32LocalCalc, 50000);
   VEMS_vidGET(Tension_alimentation_thr, u16LocalCalc);
   VEMS_vidGET(Tpac_2_limp_home_pos, u16LocalCalc2);
   u32LocalCalc = (uint32)( u16LocalCalc
                          * u16LocalCalc2);
   u32LocalCalc = ( (u32LocalCalc / 262144) * 3125)
                  + (((u32LocalCalc % 262144) * 3125) / 262144);
   Tpac_2_limp_home_pos_mem = (uint16)MATHSRV_udtMIN(u32LocalCalc, 50000);
   VEMS_vidGET(Tension_alimentation_thr, u16LocalCalc);
   VEMS_vidGET(Tpac_2_closed_throttle_pos, u16LocalCalc2);
   u32LocalCalc = (uint32)( u16LocalCalc
                          * u16LocalCalc2);
   u32LocalCalc = ( (u32LocalCalc / 262144) * 3125)
                  + (((u32LocalCalc % 262144) * 3125) / 262144);
   Tpac_2_closed_throttle_pos_mem = (uint16)MATHSRV_udtMIN(u32LocalCalc, 50000);
   VEMS_vidGET(FARSp_rMixtCylSp, FARSp_rMixtCylSp_mem);
   VEMS_vidGET(AirSys_rAirLdReq, AirSys_rAirLdReq_mem);
   VEMS_vidGET(EngM_rAirLdCor, EngM_rAirLdCor_mem);
   VEMS_vidGET1DArrayElement(Av_bmax_corr_appliquee_cyl, 0, Av_bmax_corr_appliquee_cyl_0_mem);
   VEMS_vidGET1DArrayElement(Av_bmax_corr_appliquee_cyl, 1, Av_bmax_corr_appliquee_cyl_1_mem);
   VEMS_vidGET1DArrayElement(Av_bmax_corr_appliquee_cyl, 2, Av_bmax_corr_appliquee_cyl_2_mem);
   if (PFuCtl_agWdPmpCmdMax_C != 0)
   {
      VEMS_vidGET(PFuCtl_agWdPmpCmdReq, u16LocalCalc);

      u32LocalCalc = (uint32)((u16LocalCalc/PFuCtl_agWdPmpCmdMax_C)*255);
      u32LocalNum = (uint32)((u16LocalCalc % PFuCtl_agWdPmpCmdMax_C)*255);
      u32LocalNum = (u32LocalNum/(uint32)PFuCtl_agWdPmpCmdMax_C);
      u32LocalCalc = u32LocalCalc + u32LocalNum;

      PFuCtl_agWdPmpCmdReq_mem = (uint8)MATHSRV_udtMIN(u32LocalCalc, 255);
   }
   else
   {
      PFuCtl_agWdPmpCmdReq_mem = 0;
   }
   Bruit_moyen_cyl_min_thresh_0_mem = Bruit_moyen_cyl_min_thresh[0];
   Bruit_moyen_cyl_min_thresh_1_mem = Bruit_moyen_cyl_min_thresh[1];
   Bruit_moyen_cyl_min_thresh_2_mem = Bruit_moyen_cyl_min_thresh[2];
   VEMS_vidGET(VlvAct_bInOfsFrstLrn, VlvAct_bInOfsFrstLrn_mem);
   VEMS_vidGET(VlvAct_bExOfsFrstLrn, VlvAct_bExOfsFrstLrn_mem);
   VEMS_vidGET1DArrayElement(Vcpi_cam_offsets, 0, Vcpi_cam_offsets_0_mem);
   VEMS_vidGET1DArrayElement(Vcpi_cam_offsets, 1, Vcpi_cam_offsets_1_mem);
   VEMS_vidGET1DArrayElement(Vcpi_cam_offsets, 2, Vcpi_cam_offsets_2_mem);
   VEMS_vidGET1DArrayElement(Vcpe_cam_offsets, 0, Vcpe_cam_offsets_0_mem);
   VEMS_vidGET1DArrayElement(Vcpe_cam_offsets, 1, Vcpe_cam_offsets_1_mem);
   VEMS_vidGET1DArrayElement(Vcpe_cam_offsets, 2, Vcpe_cam_offsets_2_mem);
   VEMS_vidGET(Knk_noCyl, u8LocalCalc);
   VEMS_vidGET1DArrayElement(Somme_clq_cyl, u8LocalCalc, Somme_clq_cyl_mem);
   VEMS_vidGET(CoPtUH_bStPresLo, CoPtUH_bStPresLo_mem);
   VEMS_vidGET(CoStrtRStrt_bInh, CoStrtRStrt_bInh_mem);
   VEMS_vidGET(StaStrtMgt_ctStaAcv, StaStrtMgt_ctStaAcv_mem);
   VEMS_vidGET(Veh_stDrvAvl, Veh_stDrvAvl_mem);
   VEMS_vidGET(CoPtUH_bSTTInh, CoPtUH_bSTTInh_mem);
   VEMS_vidGET(CoPtUH_stPwt, CoPtUH_stPwt_mem);
   VEMS_vidGET(Ext_bPush, Ext_bPush_mem);
   VEMS_vidGET(TqSys_tqCkEngReal, TqSys_tqCkEngReal_mem);
   VEMS_vidGET(Ext_pRelBrkAsi, Ext_pRelBrkAsi_mem);
   VEMS_vidGET(Ext_bStaCmdFctSt, Ext_bStaCmdFctSt_mem);
   VEMS_vidGET(StaStrtMgt_ctStaStrtAcv, StaStrtMgt_ctStaStrtAcv_mem);
   VEMS_vidGET(StaStrtMgt_stStaFbCmd, StaStrtMgt_stStaFbCmd_mem);
   VEMS_vidGET(StaStrtMgt_bStaReq, StaStrtMgt_bStaReq_mem);
   VEMS_vidGET(CoOptmEl_tqAlt, CoOptmEl_tqAlt_mem);
   VEMS_vidGET(BatMgt_uBattMes, BatMgt_uBattMes_mem);
   VEMS_vidGET(SAIMMO_stLockECUReadSt, SAIMMO_stLockECUReadSt_mem);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Affectation des paramètres                                  */
/* !Number      : FCT1.02                                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : MEM_vidClasFrfInit                                             */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidClasFrfInit(uint16 u16IdxDft, uint32* au32Frf)
{
   uint8 u8LocalIdxClass;
   uint8 u8LocalArrayPos1;
   uint8 u8LocalArrayPos2;
   uint8 u8LocalArrayPos3;
   uint8 u8LocalArrayPos4;
   uint8 u8LocalArrayPos5;
   uint8 u8LocalArrayPos6;
   uint8 u8LocalArrayPos7;
   uint8 u8LocalArrayPos8;
   uint8 u8LocalArrayPos9;

   /* Initialisation de u8ValueNull */
   u8ValueNull = 0;

   /* Recupération de la valeur des donnees */
   MEM_vidArrayInit();

   /* Récupération de l'index de class */
   u8LocalIdxClass = GD_au8IdxClasFrf[u16IdxDft];

   /* Récupération de la position de la variable de chaque paramètre */
   u8LocalArrayPos1 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam1;
   u8LocalArrayPos2 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam2;
   u8LocalArrayPos3 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam3;
   u8LocalArrayPos4 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam4;
   u8LocalArrayPos5 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam5;
   u8LocalArrayPos6 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam6;
   u8LocalArrayPos7 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam7;
   u8LocalArrayPos8 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam8;
   u8LocalArrayPos9 = GD_astrClasFrf[u8LocalIdxClass].u8ClasFrfParam9;


   /* Récupération de la valeur de la variable du paramètre 1 */
   if(GD_au8SizeParam[u8LocalArrayPos1] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos1] == 0)
      {
         au32Frf[0] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos1]));
      }
      else
      {
         au32Frf[0] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos1])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos1] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos1] == 0)
         {
            au32Frf[0] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos1]));
         }
         else
         {
            au32Frf[0] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos1])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos1] == 0)
         {
            au32Frf[0] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos1]));
         }
         else
         {
            au32Frf[0] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos1])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 2 */
   if(GD_au8SizeParam[u8LocalArrayPos2] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos2] == 0)
      {
         au32Frf[1] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos2]));
      }
      else
      {
         au32Frf[1] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos2])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos2] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos2] == 0)
         {
            au32Frf[1] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos2]));
         }
         else
         {
            au32Frf[1] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos2])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos2] == 0)
         {
            au32Frf[1] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos2]));
         }
         else
         {
            au32Frf[1] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos2])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 3 */
   if(GD_au8SizeParam[u8LocalArrayPos3] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos3] == 0)
      {
         au32Frf[2] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos3]));
      }
      else
      {
         au32Frf[2] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos3])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos3] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos3] == 0)
         {
            au32Frf[2] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos3]));
         }
         else
         {
            au32Frf[2] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos3])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos3] == 0)
         {
            au32Frf[2] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos3]));
         }
         else
         {
            au32Frf[2] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos3])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 4 */
   if(GD_au8SizeParam[u8LocalArrayPos4] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos4] == 0)
      {
         au32Frf[3] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos4]));
      }
      else
      {
         au32Frf[3] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos4])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos4] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos4] == 0)
         {
            au32Frf[3] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos4]));
         }
         else
         {
            au32Frf[3] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos4])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos4] == 0)
         {
            au32Frf[3] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos4]));
         }
         else
         {
            au32Frf[3] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos4])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 5 */
   if(GD_au8SizeParam[u8LocalArrayPos5] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos5] == 0)
      {
         au32Frf[4] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos5]));
      }
      else
      {
         au32Frf[4] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos5])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos5] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos5] == 0)
         {
            au32Frf[4] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos5]));
         }
         else
         {
            au32Frf[4] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos5])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos5] == 0)
         {
            au32Frf[4] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos5]));
         }
         else
         {
            au32Frf[4] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos5])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 6 */
   if(GD_au8SizeParam[u8LocalArrayPos6] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos6] == 0)
      {
         au32Frf[5] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos6]));
      }
      else
      {
         au32Frf[5] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos6])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos6] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos6] == 0)
         {
            au32Frf[5] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos6]));
         }
         else
         {
            au32Frf[5] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos6])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos6] == 0)
         {
            au32Frf[5] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos6]));
         }
         else
         {
            au32Frf[5] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos6])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 7 */
   if(GD_au8SizeParam[u8LocalArrayPos7] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos7] == 0)
      {
         au32Frf[6] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos7]));
      }
      else
      {
         au32Frf[6] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos7])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos7] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos7] == 0)
         {
            au32Frf[6] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos7]));
         }
         else
         {
            au32Frf[6] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos7])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos7] == 0)
         {
            au32Frf[6] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos7]));
         }
         else
         {
            au32Frf[6] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos7])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 8 */
   if(GD_au8SizeParam[u8LocalArrayPos8] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos8] == 0)
      {
         au32Frf[7] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos8]));
      }
      else
      {
         au32Frf[7] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos8])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos8] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos8] == 0)
         {
            au32Frf[7] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos8]));
         }
         else
         {
            au32Frf[7] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos8])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos8] == 0)
         {
            au32Frf[7] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos8]));
         }
         else
         {
            au32Frf[7] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos8])));
         }
      }
   }


   /* Récupération de la valeur de la variable du paramètre 9 */
   if(GD_au8SizeParam[u8LocalArrayPos9] == 1)
   {
      if(GD_abSignParam[u8LocalArrayPos9] == 0)
      {
         au32Frf[8] = *((uint8*)(GD_apvidListParam[u8LocalArrayPos9]));
      }
      else
      {
         au32Frf[8] = (uint8)(*((uint8*)(GD_apvidListParam[u8LocalArrayPos9])));
      }
   }
   else
   {
      if(GD_au8SizeParam[u8LocalArrayPos9] == 2)
      {
         if(GD_abSignParam[u8LocalArrayPos9] == 0)
         {
            au32Frf[8] = *((uint16*)(GD_apvidListParam[u8LocalArrayPos9]));
         }
         else
         {
            au32Frf[8] = (uint16)(*((uint16*)(GD_apvidListParam[u8LocalArrayPos9])));
         }
      }
      else
      {
         if(GD_abSignParam[u8LocalArrayPos9] == 0)
         {
            au32Frf[8] = *((uint32*)(GD_apvidListParam[u8LocalArrayPos9]));
         }
         else
         {
            au32Frf[8] = (uint32)(*((uint32*)(GD_apvidListParam[u8LocalArrayPos9])));
         }
      }
   }
}
