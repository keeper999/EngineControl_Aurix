/******************************************************************************/
/* !Component      : GDGAR                                                    */
/******************************************************************************/
/* !Module         : MEM                                                      */
/* !Description    : Listing of all parameters used in the Freeze Frame       */
/*                   class on the projet EBx_V46.                             */
/* !File           : MEM_conf.h                                               */
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
/*       File generated automatically by pbakabad                                */
/******************************************************************************/
/* generated the 06/06/2013 at 10:24                                          */
/******************************************************************************/


#ifndef MEM_CONF_H
#define MEM_CONF_H

#include "STD_Types.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define NB_PARAM  174

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

extern uint8 u8ValueNull;
extern uint16 Ext_nEng_mem;
extern uint16 Veh_spdVeh_mem;
extern boolean Ext_bMainBrkPedPrssMes_mem;
extern boolean Ext_bCluPedPrss_mem;
extern uint16 Ext_uAccP1SenPwr_mem;
extern uint16 Ext_uAccP2SenPwr_mem;
extern uint8 AccP_rDrvReq_mem;
extern boolean Ext_bAccPHdPt_mem;
extern uint8 CoPt_noEgdGearCord_mem;
extern sint16 Ext_tCoMes_mem;
extern boolean Ext_bRCDLine_mem;
extern sint16 ThMgt_tCoReg_mem;
extern uint16 VlvAct_nEngExCmFil_mem;
extern uint8 Ext_rAltCycOp_mem;
extern sint16 Ext_tDsThrMes_mem;
extern uint8 CoPTSt_stEng_mem;
extern sint16 Ext_tAirExtMes_mem;
extern boolean Ext_bStrtAuth_mem;
extern boolean AC_bACClu_mem;
extern uint8 AC_pwrAC_mem;
extern uint16 Ext_upOilMes_mem;
extern uint16 Ext_uEngOilLvl_mem;
extern uint16 ESLim_tiCntOverNEngMax_mem;
extern uint16 Cl_raw_pressure_mem;
extern sint16 Ext_uBattMes_mem;
extern uint16 Tension_alimentation_1_mem;
extern uint16 Tension_alimentation_2_mem;
extern uint16 Tension_alimentation_3_mem;
extern uint16 Tension_alimentation_4_mem;
extern boolean Actionneurs_mem;
extern uint16 Ext_pOilMesRaw_mem;
extern boolean ThMgt_bCmdHiSpdFan_mem;
extern boolean ThMgt_bCmdLowSpdFan_mem;
extern boolean Ext_bStFanFil_mem;
extern boolean Ext_bNeut_mem;
extern uint16 Cts_range_voltage_mem;
extern uint8 CoPtUH_noGearTmpBeg_mem;
extern uint8 CoPtUH_noGearTmpEnd_mem;
extern uint16 InjSys_pFuSp_mem;
extern uint16 Ext_pFuMesWRV_mem;
extern uint16 Ext_rOpThr_mem;
extern uint16 ThrSys_rOpThrReq_mem;
extern uint16 Ext_nEng_mem;
extern boolean Ext_bSecBrkPedPrssMes_mem;
extern uint16 OilSys_pOilReq_mem;
extern uint16 Ext_pAirExtAcq_mem;
extern uint16 AccP_rAccP_mem;
extern uint16 BatMgt_rBattSoCCor_mem;
extern uint16 Ext_rCluPedPrssMes_mem;
extern uint16 Ext_rCluPedPrssBrutMes_mem;
extern uint16 OilSys_rCtlPmpReq_mem;
extern uint16 FTPCtl_rFlowFuTnkPmp_mem;
extern uint8 Ext_spdVehReqVSReg_mem;
extern uint8 Ext_spdVehReqVSLim_mem;
extern uint32 Ext_ctSecEngStop_mem;
extern uint16 EngSt_tiDlySync_mem;
extern uint16 Ext_pUsThrMesSI_mem;
extern sint16 Ext_tDsThrMes_mem;
extern uint16 Cl_pressure_result_ad_conv_mem;
extern uint16 Ext_upFuMes_mem;
extern uint16 Pression_air_result_ad_conv_mem;
extern uint16 Temperature_air_result_ad_conv_mem;
extern uint16 InM_mfAirThrEstim_mem;
extern uint16 TrbAct_rRCOReq_mem;
extern uint16 AirSys_pUsThrReq_mem;
extern uint16 AirSys_mfAirThrReqFil_mem;
extern uint16 Aps_1_raw_filt_position_mem;
extern uint16 Aps_2_raw_filt_position_mem;
extern sint16 BatMgt_tBattMes_mem;
extern sint32 BatMgt_iBattMes_mem;
extern uint16 CoPtUH_rMaxCluGc_mem;
extern uint16 Ext_nEngCmInMes_mem;
extern uint32 Ext_dstVehTotMes_mem;
extern uint16 SftyMgt_prm_bDftHisAfts1_mem;
extern uint16 SftyMgt_prm_bDftHisAfts2_mem;
extern uint16 SftyMgt_prm_bDftHisAfts3_mem;
extern uint8 ThMgt_stPosnFSFReq_mem;
extern uint16 SftyMgt_prm_bDftHisAfts4_mem;
extern uint16 SftyMgt_prm_bDftHisAfts5_mem;
extern uint16 SftyMgt_prm_bDftHisAfts6_mem;
extern uint8 Ext_rAltCycOp_mem;
extern uint8 LsSys_rLsDsMainOxCHeatPwrReq_mem;
extern uint8 LsSys_rLsUsMainOxCHeatPwrReq_mem;
extern uint8 ACCmd_stReq_mem;
extern uint8 VSCtl_stVSRegExtd_mem;
extern boolean Diag_on_mem;
extern boolean CoPt_stDrvTra_mem;
extern boolean Dnstr_conds_met_mem;
extern uint8 VSCtl_stVSLimExtd_mem;
extern boolean Ext_bAcvSta_mem;
extern boolean Lambda_closed_loop_mem;
extern uint32 Ext_tiCurVehTmr_mem;
extern uint32 InjrSys_prm_tiInjH1ReqCyl_0_mem;
extern uint32 InjrSys_prm_tiInjH1ReqCyl_1_mem;
extern uint32 InjrSys_prm_tiInjH1ReqCyl_2_mem;
extern sint16 TqSys_tqIdcReq_mem;
extern uint16 Tension_sonde_aval_brute_mem;
extern uint16 Tension_sonde_amont_brute_mem;
extern uint16 EcuSt_ctHotRst_Count_mem;
extern sint16 Ext_pDsThrMes_mem;
extern uint16 AirSys_prm_pInMnfReq_0_mem;
extern uint8 Flev_fuel_level_mem;
extern uint16 SftyMgt_prm_bDftHisAfts7_mem;
extern uint16 SftyMgt_prm_bDftHisAfts8_mem;
extern boolean BlowBy1Hw_bReq_mem;
extern boolean ThMgt_bTrbWaPmpReq_mem;
extern uint8 IgSys_agIgBas_mem;
extern sint16 Ext_agCkClsExVlvEstimRef0_mem;
extern uint8 VlvSys_agCkClsExVlvReqRef0_mem;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_0_mem;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_1_mem;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_2_mem;
extern uint8 IgSys_prm_agIgSpCyl_0_mem;
extern uint8 IgSys_prm_agIgSpCyl_1_mem;
extern uint8 IgSys_prm_agIgSpCyl_2_mem;
extern sint16 Ext_agCkOpInVlvEstimRef0_mem;
extern uint8 VlvSys_agCkOpInVlvReqRef0_mem;
extern uint8 IgSys_agIgMaxWiPrevAdpMv_mem;
extern uint8 IgSys_agIgMin_mem;
extern uint8 Rco_applique_purge_mem;
extern uint16 CanPurg_concFuStmEstim_mem;
extern uint8 ThMgt_rPwrECTReq_mem;
extern uint16 DmpVlvAct_rDmpVlvOplCmdSp_mem;
extern uint16 Rco_applique_vvt_echap_mem;
extern uint16 Rco_applique_vvt_adm_mem;
extern boolean Sonde_riche_aval_mem;
extern boolean Vcpe_cam_offsets_are_learned_mem;
extern boolean Vcpi_cam_offsets_are_learned_mem;
extern boolean Sonde_riche_amont_mem;
extern sint16 TqSys_tqCkEfcReq_mem;
extern uint16 Dv_1_app_pos_ped_pc_mem;
extern uint16 Dv_1_app_pos_ped_pl_mem;
extern uint16 Dv_2_app_pos_ped_pc_mem;
extern uint16 Dv_2_app_pos_ped_pl_mem;
extern uint16 Tpac_1_limp_home_pos_mem;
extern uint16 Tpac_1_closed_throttle_pos_mem;
extern uint16 Tpac_2_limp_home_pos_mem;
extern uint16 Tpac_2_closed_throttle_pos_mem;
extern uint16 FARSp_rMixtCylSp_mem;
extern uint16 AirSys_rAirLdReq_mem;
extern uint16 EngM_rAirLdCor_mem;
extern sint8 Av_bmax_corr_appliquee_cyl_0_mem;
extern sint8 Av_bmax_corr_appliquee_cyl_1_mem;
extern sint8 Av_bmax_corr_appliquee_cyl_2_mem;
extern uint16 PFuCtl_agWdPmpCmdReq_mem;
extern uint16 Bruit_moyen_cyl_min_thresh_0_mem;
extern uint16 Bruit_moyen_cyl_min_thresh_1_mem;
extern uint16 Bruit_moyen_cyl_min_thresh_2_mem;
extern boolean VlvAct_bInOfsFrstLrn_mem;
extern boolean VlvAct_bExOfsFrstLrn_mem;
extern uint16 Vcpi_cam_offsets_0_mem;
extern uint16 Vcpi_cam_offsets_1_mem;
extern uint16 Vcpi_cam_offsets_2_mem;
extern uint16 Vcpe_cam_offsets_0_mem;
extern uint16 Vcpe_cam_offsets_1_mem;
extern uint16 Vcpe_cam_offsets_2_mem;
extern uint16 Somme_clq_cyl_mem;
extern boolean CoPtUH_bStPresLo_mem;
extern boolean CoStrtRStrt_bInh_mem;
extern uint32 StaStrtMgt_ctStaAcv_mem;
extern uint8 Veh_stDrvAvl_mem;
extern boolean CoPtUH_bSTTInh_mem;
extern uint8 CoPtUH_stPwt_mem;
extern boolean Ext_bPush_mem;
extern sint16 TqSys_tqCkEngReal_mem;
extern uint8 Ext_pRelBrkAsi_mem;
extern boolean Ext_bStaCmdFctSt_mem;
extern uint32 StaStrtMgt_ctStaStrtAcv_mem;
extern uint8 StaStrtMgt_stStaFbCmd_mem;
extern boolean StaStrtMgt_bStaReq_mem;
extern sint16 CoOptmEl_tqAlt_mem;
extern uint16 BatMgt_uBattMes_mem;

extern const void* GD_apvidListParam[NB_PARAM];
extern const uint8 GD_au8SizeParam[NB_PARAM];
extern const boolean GD_abSignParam[NB_PARAM];

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MEM_vidArrayInit(void);
void MEM_vidClasFrfInit(uint16 u16IdxDft, uint32* au32Frf);

#endif /* MEM_CONF_H */

/*-------------------------------- end of file -------------------------------*/
