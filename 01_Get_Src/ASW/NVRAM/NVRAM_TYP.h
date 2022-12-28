/******************************************************************************/
/*                                                                            */
/* !Layer          : SRV                                                      */
/*                                                                            */
/* !Component      : NVRAM                                                    */
/*                                                                            */
/* !Module         : NVRAM_TYP                                                */
/* !Description    : Contains types declaration of the NVRAM component        */
/*                                                                            */
/* !File           : NVRAM_TYP.H                                             */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2014 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/NVRAM/NVRAM_TYP.h_v               $*/
/* $Revision::   1.3      $$Author::   wbouach     $$Date::   19 Sep 2014 14:$*/
/******************************************************************************/
/*       THIS FILE IS GENERATED AUTOMATICALY BY GenGlueCfromXLS TOOL          */
/*       Generated date 19/09/14 at 14:21:18                                   */
/******************************************************************************/

#ifndef NVRAM_TYP_H
#define NVRAM_TYP_H

#include "STD_TYPES.H"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

typedef struct
{
   uint16 NVMSRV_u16TestEeprom_1;
} TEST_EEPROM_1_NvMBlockDataStruct;

typedef struct
{
   uint16 NVMSRV_u16TestEeprom_2;
} TEST_EEPROM_2_NvMBlockDataStruct;

typedef struct
{
   uint32 NVMSRV_u32SavedReReadFrameCntr;
} SPI_REREAD_FRAMES_NvMBlockDataStruct;

typedef struct
{
   uint8 EPMSRV_u8TdcCounter;
} EPMSRV_NvMBlockDataStruct;

typedef struct
{
   uint8 Cpt_tel_eep;
} DOWNLOAD_NvMBlockDataStruct;

typedef struct
{
   uint16 Eep_nb_ecr_pages;
   uint32 Eep_nb_total_ecr_pages;
} ECRITURES_EEPROM_NvMBlockDataStruct;

typedef struct
{
   uint16 RSTSRV_u16HotResetCtr;
} RESET_NvMBlockDataStruct;

typedef struct
{
   uint8 ErrorStackIdx_eep;
   uint16 Compteur_defaut_pile_eep;
   uint16 Compteur_defaut_except_eep;
   uint16 Type_de_defaut_eep;
   uint32 ErrorAddress_eep;
} EXCEPTION_REGS_NvMBlockDataStruct;

typedef struct
{
   uint16 NVMSRV_u16TestEeprom_3;
} TEST_EEPROM_3_NvMBlockDataStruct;

typedef struct
{
   uint8 RED_au8Prod1Reserve[11];
   uint8 RED_au8ECUSerial[5];
   uint8 RED_au8RefCIndex[2];
   uint8 RED_au8RefCNum[5];
   uint8 RED_au8RefAIndex[2];
   uint8 RED_au8RefANum[5];
} REDPROD_1_NvMBlockDataStruct;

typedef struct
{
   uint8 RED_au8Prod2Reserve[20];
   uint8 RED_au8FuncProductNum[5];
   uint8 RED_au8FuncSchematicNum[5];
} REDPROD_2_NvMBlockDataStruct;

typedef struct
{
   uint8 RED_au8Prod5Reserve[21];
   uint8 RED_au8InitialMcwRomChecksum[2];
   uint8 RED_au8CieValeoNumIdx[2];
   uint8 RED_au8CieValeoNum[5];
} REDPROD_5_NvMBlockDataStruct;

typedef struct
{
   uint8 RED_au8Prod8Reserve[24];
   sint8 RED_s8TrimGainOutput_CM_3;
   sint8 RED_s8TrimGainOutput_CM_24;
   sint8 RED_s8TrimGainOutput_CM_45;
   sint8 RED_s8TrimGainOutput_CM_66;
   sint8 RED_s8BatTrimOffset;
   sint8 RED_s8BatTrimGain;
} REDPROD_8_NvMBlockDataStruct;

typedef struct
{
   uint8 PROD_au8Prod1Reserve[11];
   uint8 PROD_au8ECUSerial[5];
   uint8 PROD_au8RefCIndex[2];
   uint8 PROD_au8RefCNum[5];
   uint8 PROD_au8RefAIndex[2];
   uint8 PROD_au8RefANum[5];
} PROD_1_VALEOIDENT_NvMBlockDataStruct;

typedef struct
{
   uint8 PROD_au8Prod2Reserve[20];
   uint8 PROD_au8FuncProductNum[5];
   uint8 PROD_au8FuncSchematicNum[5];
} PROD_2_PSAIDENT_NvMBlockDataStruct;

typedef struct
{
   uint8 PROD_au8Prod5Reserve[21];
   uint8 MCWDG_au8InitialMcwRomChecksum[2];
   uint8 PROD_au8CieValeoNumIdx[2];
   uint8 PROD_au8CieValeoNum[5];
} PROD_5_CIENUM_NvMBlockDataStruct;

typedef struct
{
   uint8 PROD_au8Prod8Reserve[24];
   sint8 IGNHAL_s8TrimGainOutput_CM_3;
   sint8 IGNHAL_s8TrimGainOutput_CM_24;
   sint8 IGNHAL_s8TrimGainOutput_CM_45;
   sint8 IGNHAL_s8TrimGainOutput_CM_66;
   sint8 ADCHAL_s8BatTrimOffset;
   sint8 ADCHAL_s8BatTrimGain;
} PROD_8_TRIMS_NvMBlockDataStruct;

typedef struct
{
   uint16 Version_eeprom;
} EEPROM_VERSION_NvMBlockDataStruct;

typedef struct
{
   sint16 Av_bmax_adapt_anti_k_cyl4[15];
   sint16 Av_bmax_adapt_anti_k_cyl3[15];
   sint16 Av_bmax_adapt_anti_k_cyl2[15];
   sint16 Av_bmax_adapt_anti_k_cyl1[15];
} KNKADPCOR_NvMBlockDataStruct;

typedef struct
{
   uint8 Srv_bPostEquDone;
   uint8 Ext_spdVehVSMaxPrmaReq1;
   uint8 Srv_PostEquIndice;
} POSTEQUSRV_NvMBlockDataStruct;

typedef struct
{
   uint8 Tele_program_add_heat;
   uint8 Tele_program_car;
   uint8 Tele_program_press_clim;
   uint8 Id_telecodage_eeprom;
   uint8 Tele_program_gear_box;
   uint8 Tele_program_fric;
   uint8 Tele_program_nb;
   uint16 Tele_program_alternator;
   uint32 Tele_program_uc;
} TELECODAGE_NvMBlockDataStruct;

typedef struct
{
   uint8 AccPEM_bAccPInvld;
} ACCPEM_NvMBlockDataStruct;

typedef struct
{
   uint16 Dv_1_app_pos_ped_pc;
   uint16 Dv_1_app_pos_ped_pl;
   uint16 Dv_2_app_pos_ped_pc;
   uint16 Dv_2_app_pos_ped_pl;
} ACCPLRNPOS_NvMBlockDataStruct;

typedef struct
{
   sint16 Ext_tCoMesPwrl;
} ACQCOT_NvMBlockDataStruct;

typedef struct
{
   uint8 FISA_facOld_nvm;
} CLCNFISAGAIN_NvMBlockDataStruct;

typedef struct
{
   uint8 StaCtl_ctDiagCluP_NV;
} CLUPEDPOSNDIAG_NvMBlockDataStruct;

typedef struct
{
   uint8 Cps_switch_mal_utilise_cpt;
} CLUSWTDIAG_NvMBlockDataStruct;

typedef struct
{
   uint8 CoFan_ctRskCritScFanC;
   uint8 CoFan_ctCritScFanC;
} COFANCMDDIAG_NvMBlockDataStruct;

typedef struct
{
   uint32 Ext_dstVehTotMes;
} FHCANF552_NvMBlockDataStruct;

typedef struct
{
   uint16 Cpc_fuel_vapour_concentration;
} CSTRFUCONCESTIM_NvMBlockDataStruct;

typedef struct
{
   uint8 Afts_stSpcFactSTTReq_eep;
   uint8 Afts_bInhIniRunReq_eep;
   uint8 Afts_bInhStSoCBatt_eep;
} DCM_MANU_NvMBlockDataStruct;

typedef struct
{
   uint16 UsThrM_pAirExtEstimRefOld;
} DIAGAIREXTPRES_NvMBlockDataStruct;

typedef struct
{
   uint16 Tension_sonde_av_max_cycle;
   uint16 Tension_sonde_av_min_cycle;
} DSO2SEN_NvMBlockDataStruct;

typedef struct
{
   uint16 EcuSt_ctHotRst_Count;
} ECUMNG_NvMBlockDataStruct;

typedef struct
{
   uint16 ESLim_tiCntOverNEngMax;
} ENGRUNST_NvMBlockDataStruct;

typedef struct
{
   uint16 Dml_demarrage_count_eep;
   uint8 First_crank;
} DIVERS_EEP_FIXE_NvMBlockDataStruct;

typedef struct
{
   uint16 Ext_volFuCns;
   uint8 Ext_bRFuDet;
   uint8 RFuDet_bRstAdp_nvm;
   uint8 FISA_facRst_nvm;
   uint8 Ext_volFuOld;
} FISARFUDET_NvMBlockDataStruct;

typedef struct
{
   uint32 Ext_ctSecPwrl;
   uint32 Ext_ctVehPwrl;
   uint32 Ext_ctVehPwrl2004;
   uint16 Ext_ctDayPwrl;
   uint8 Ext_ctYrPwrl;
} FLOWMNG_NvMBlockDataStruct;

typedef struct
{
   uint16 FTPCtl_ctFirstCmdFuPmpTmr_NV;
   uint8 FTPCtl_bFirstCmdFuPmp_NV;
} FTPCTL_NvMBlockDataStruct;

typedef struct
{
   uint32 Consommation_carburant_totale;
} FUCNS_NvMBlockDataStruct;

typedef struct
{
   uint8 Flev_fuel_level_in_eep;
} FULVL_NvMBlockDataStruct;

typedef struct
{
   sint16 WUC_tCoRefEep;
   uint8 WUC_ctWupDftClr;
   uint8 WUC_bWupSt;
} WUC_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_prmDtcStatus[734];
} STATUSOFDTC_NvMBlockDataStruct;

typedef struct
{
   uint16 GMIL_dstKmMilOn;
   uint16 GMIL_dstKmRstDft;
   uint16 GMIL_tiMinsEngrunMilOn;
   uint16 GMIL_tiMinsEngrunRstDft;
   uint8 IndicOBD_ctDftObdCf;
} INDICOBD_NvMBlockDataStruct;

typedef struct
{
   uint16 Iupr_gen_denom_count_eep;
   uint16 IUPR_ctObdStrt;
} IUPRGENDEN_NvMBlockDataStruct;

typedef struct
{
   uint16 Rdy_u16ClasRdy_EEPROM;
   uint8 Rdy_au8Rdy_EEPROM[92];
} RC01_NvMBlockDataStruct;

typedef struct
{
   uint8 GOBD_bPresDC[734];
   uint8 GOBD_ctDC[734];
   uint8 GOBD_ctWUC[734];
   uint8 GOBD_bNCfDC[734];
} GOBD_NvMBlockDataStruct;

typedef struct
{
   uint16 IUPR_ctDenRat[100];
   uint16 IUPR_ctNumRat[100];
} IUPRRATIO_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32dstAbsKmNoFrf[40];
} MEM1_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf1NoFrf[40];
} MEM2_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf2NoFrf[40];
} MEM3_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf3NoFrf[40];
} MEM4_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf4NoFrf[40];
} MEM5_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf5NoFrf[40];
} MEM6_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf6NoFrf[40];
} MEM7_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf7NoFrf[40];
} MEM8_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf8NoFrf[40];
} MEM9_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_au32prmClasFrf9NoFrf[40];
} MEM10_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_uBattMes_NoFrf[40];
} MEM11_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16nEngNoFrf[40];
} MEM12_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16idxDftNoFrf[40];
} MEM13_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_spdVeh_NoFrf[40];
} MEM14_NvMBlockDataStruct;

typedef struct
{
   sint16 GD_as16tCoMesNoFrf[40];
} MEM15_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_au8StFrfRecNoFrf[40];
} MEM16_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_au8idxFltToCxtNoFrf[40];
} MEM17_NvMBlockDataStruct;

typedef struct
{
   uint8 Fault_context_eep_eobd[16];
} MEM18_NvMBlockDataStruct;

typedef struct
{
   uint8 Free_context_eobd;
   uint8 GD_ctSngDftMem;
   uint8 GD_bMaxDftMem;
   uint8 GD_au8RnkFrf[734];
} MEM19_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID1[40];
} MEM20_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID2[40];
} MEM21_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID3[40];
} MEM22_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID4[40];
} MEM23_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID5[40];
} MEM24_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID6[40];
} MEM25_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID7[40];
} MEM26_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID8[40];
} MEM27_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_au16prmClasDID9[40];
} MEM28_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_Pid04_NoFrf[40];
} MEM29_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_Pid05_NoFrf[40];
} MEM30_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_Pid0B_NoFrf[40];
} MEM31_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_Pid0C_NoFrf[40];
} MEM32_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_Pid0D_NoFrf[40];
} MEM33_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_Pid03_NoFrf[40];
} MEM34_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_Pid23_NoFrf[40];
} MEM35_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_Pid06_NoFrf[40];
} MEM36_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_Pid42_NoFrf[40];
} MEM37_NvMBlockDataStruct;

typedef struct
{
   uint32 GD_tiCurVehTmr_NoFrf[40];
} MEM38_NvMBlockDataStruct;

typedef struct
{
   uint16 GD_rAccP_NoFrf[40];
} MEM39_NvMBlockDataStruct;

typedef struct
{
   uint8 GD_Pid07_NoFrf[40];
} MEM40_NvMBlockDataStruct;

typedef struct
{
   uint8 GMIL_bDftMilOn;
} GMIL_NvMBlockDataStruct;

typedef struct
{
   uint16 Ldsd_trk_ewma_essence_eep;
   uint16 Ldsd_trk_ewma_gaz_eep;
} HEATSENO2DSDERIDIAG_NvMBlockDataStruct;

typedef struct
{
   uint16 LsSys_tiLsDsDlyDewTranOkStall;
} HEATSENO2DS_NvMBlockDataStruct;

typedef struct
{
   uint16 LsSys_tiLsUsDlyDewTranOkStall;
} HEATSENO2US_NvMBlockDataStruct;

typedef struct
{
   uint16 Eep_UsThrM_pAirExtEstim;
   uint16 temps_fonctionnement_moteur;
   uint16 temps_allumage_ecu;
} IFAIRSYSIGSYS_NvMBlockDataStruct;

typedef struct
{
   sint16 Feedback_correction_Tmp;
} INJFARCTLDSCTL_NvMBlockDataStruct;

typedef struct
{
   uint8 Mf_adap_lw_corr_count_uavn1[9];
   uint8 Mf_adap_shrt_corr_count_uavn1[9];
   sint16 Misf_prm_tiDlyBdcWinLrnCyl1[9];
   sint16 Misf_prm_tiDlyBdcWinLrnCyl2[9];
   sint16 Misf_prm_tiDlyBdcWinLrnCyl3[9];
   sint16 Misf_prm_tiDlyBdcWinLrnCyl4[9];
   sint16 Misf_prm_tiDlyExpWinLrnCyl1[9];
   sint16 Misf_prm_tiDlyExpWinLrnCyl2[9];
   sint16 Misf_prm_tiDlyExpWinLrnCyl3[9];
   sint16 Misf_prm_tiDlyExpWinLrnCyl4[9];
   sint16 Misf_prm_tiDlyLongWinLrnCyl1[9];
   sint16 Misf_prm_tiDlyLongWinLrnCyl2[9];
   sint16 Misf_prm_tiDlyLongWinLrnCyl3[9];
   sint16 Misf_prm_tiDlyLongWinLrnCyl4[9];
   sint16 Misf_prm_tiDlyTDCWinLrnCyl1[9];
   sint16 Misf_prm_tiDlyTDCWinLrnCyl2[9];
   sint16 Misf_prm_tiDlyTDCWinLrnCyl3[9];
   sint16 Misf_prm_tiDlyTDCWinLrnCyl4[9];
   sint16 Mf_adap_lw_delta_applied_uavn1[4];
   sint16 Mf_adap_Exp_delta_applied_uavn1[4];
   sint16 Mf_adap_TDC_delta_applied_uavn1[4];
   sint16 Mf_adap_Bdc_delta_applied_uavn1[4];
   uint8 Mf_adap_lw_no_rlzd_uavb0;
   uint8 Mf_adap_shrt_no_rlzd_uavb0;
} MISFDFTLRN_NvMBlockDataStruct;

typedef struct
{
   uint8 Ext_stTypInjr;
} INJRCHRN_NvMBlockDataStruct;

typedef struct
{
   uint16 CatMon_facMes_Obd6Mod_eep;
   uint16 HeatSenO2_DsFacMes_Obd6Mod_eep;
   uint16 HeatSenO2_UsFacMes_Obd6Mod_eep;
   uint16 MonMisf_ctOccurMfAvg10DCCyl1_eep;
   uint16 MonMisf_ctOccurMfAvg10DCCyl2_eep;
   uint16 MonMisf_ctOccurMfAvg10DCCyl3_eep;
   uint16 MonMisf_ctOccurMfAvg10DCCyl4_eep;
   uint16 MonMisf_ctOccurMfDCCyl1_eep;
   uint16 MonMisf_ctOccurMfDCCyl2_eep;
   uint16 MonMisf_ctOccurMfDCCyl3_eep;
   uint16 MonMisf_ctOccurMfDCCyl4_eep;
   uint16 Oxy_sens_period_var_eep;
   uint16 SenO2Ds_FcoPlausMes_Obd6Mod_eep;
   uint16 SenO2Ds_FldPlausMes_Obd6Mod_eep;
   uint16 SenO2Ds_SigGrdFacMes_Obd6Mod_eep;
   uint16 SenO2Ds_SigGrd_Obd6Mod_eep;
   uint16 SenO2Us_FcoPlausMes_Obd6Mod_eep;
   uint16 SenO2Us_FldPlausMes_Obd6Mod_eep;
   uint16 Tension_sonde_am_max_cycle_eep;
   uint16 Tension_sonde_am_min_cycle_eep;
   uint16 Tension_sonde_av_max_cycle_eep;
   uint16 Tension_sonde_av_min_cycle_eep;
} OBDSRV06_NvMBlockDataStruct;

typedef struct
{
   uint8 Srv_bAntiScanPostEqu;
} POSTEQUSRV_BANTISCANNING_NvMBlockDataStruct;

typedef struct
{
   uint16 PredEs_tiErrOkN2EgdChgDir_NV;
   uint16 PredEs_tiErrOkN2EgdChgDir2_NV;
   uint8 PredEs_ctOkOscN_NV;
} PREDES_NvMBlockDataStruct;

typedef struct
{
   uint32 CoPt_tiEngStopMem_NV;
   uint16 CoPt_prm_tCluEstimMem_NV[5];
} PROTMANCLU_NvMBlockDataStruct;

typedef struct
{
   uint8 EcuSt_SrvPwrlSt;
} ECUSTSRVPWRLST_NvMBlockDataStruct;

typedef struct
{
   uint8 Ref_ident_etal[12];
} REFIDETA_NvMBlockDataStruct;

typedef struct
{
   uint16 RND_u16SeedOldAlea;
   uint16 RND_u16SeedTimer;
} RANDOM_NvMBlockDataStruct;

typedef struct
{
   uint32 SftyMgt_prm_bDftHis[4];
   uint16 SftyMgt_prm_bFrfNew[8];
   uint16 SftyMgt_ctWrMem;
   uint8 SftyMgt_ctDftLaddNew;
} SFTYMNGR_NvMBlockDataStruct;

typedef struct
{
   uint32 SpyEmSTT_prmHisDstWin1[2];
   uint8 SpyEmSTT_prmHistNotStopCase1[7];
   uint8 SpyEmSTT_prmHistNotStopCase2[7];
   uint8 SpyEmSTT_prmHistNotStopCase3[7];
} SPYEMSTT_NvMBlockDataStruct;

typedef struct
{
   uint32 SpySTT_prmHisDstWin1[2];
   uint8 SpySTT_prmHisNotStopCase1[11];
   uint8 SpySTT_prmHisNotStopCase2[11];
   uint8 SpySTT_prmHisNotStopCase3[11];
   uint8 SpySTT_stRStrtFailRec1;
   uint8 SpySTT_stRStrtFailRec2;
   uint8 SpySTT_stRStrtFailRec3;
   uint8 SpySTT_stCutCaseRec;
} SPYSTT_NvMBlockDataStruct;

typedef struct
{
   uint8 Sync_prm_bLrnCorAr[20];
   sint8 Sync_prm_nCornEngCyl1[20];
   sint8 Sync_prm_nCornEngCyl2[20];
   sint8 Sync_prm_nCornEngCyl3[20];
} SYNCENGCLC_NvMBlockDataStruct;

typedef struct
{
   uint8 Srv_bAntiScanning;
} TELE_BANTISCANNING_NvMBlockDataStruct;

typedef struct
{
   uint16 Tpac_1_open_throttle_pos;
   uint16 Tpac_2_open_throttle_pos;
   uint16 Tpac_1_limp_home_pos;
   uint16 Tpac_2_limp_home_pos;
   uint16 Tpac_1_clo_throttle_filt_pos;
   uint16 Tpac_2_clo_throttle_filt_pos;
   uint16 Tpac_1_closed_throttle_ref;
   uint16 Tpac_2_closed_throttle_ref;
   uint16 Tpac_1_closed_throttle_pos;
   uint16 Tpac_2_closed_throttle_pos;
   uint8 Tpac_thrusts_powerlatch_counter;
   uint8 Tpac_thrusts_enable;
   uint8 Thr_bNewThrCpt;
   uint8 Thr_bRstStopsLrnReq;
   uint8 Tpac_FCln_powerlatch_counter;
   uint8 Tpac_FCln_enable;
} PAP_MOT_NvMBlockDataStruct;

typedef struct
{
   uint32 Date_emf_dernier_arret_s;
   uint32 Date_emf_dernier_reveil_s;
   uint32 Date_emf_demarrage_s;
   uint16 Date_emf_dernier_arret_j;
   uint16 Date_emf_dernier_reveil_j;
   uint16 Date_emf_demarrage_j;
   uint8 Date_emf_dernier_arret_a;
   uint8 Date_emf_dernier_reveil_a;
   uint8 Date_emf_demarrage_a;
} TIENGSTOP_NvMBlockDataStruct;

typedef struct
{
   sint16 Eng_tOilEstim_NV;
   sint16 Ext_tCoMes_NV;
   sint8 Ext_tAir_NV;
} TOILEST_NvMBlockDataStruct;

typedef struct
{
   uint16 TWCMgt_tiPha1_NV;
} TWCMGT_NvMBlockDataStruct;

typedef struct
{
   uint16 Tension_sonde_am_max_cycle;
   uint16 Tension_sonde_am_min_cycle;
} UPLSACQ_NvMBlockDataStruct;

typedef struct
{
   uint16 Vcpe_cam_offsets_eep[4];
   uint8 VlvAct_bExOfsFrstLrn_eep;
   uint8 Ext_stAgCmExFrstAdapt_eep;
   uint8 VlvAct_bExOfsFrstLrnWouDft_eep;
} VLVACTEXENDSTOP_NvMBlockDataStruct;

typedef struct
{
   uint16 Vcpi_cam_offsets_eep[4];
   uint8 VlvAct_bInOfsFrstLrn_eep;
   uint8 Ext_stAgCmInFrstAdapt_eep;
   uint8 VlvAct_bInOfsFrstLrnWouDft_eep;
} VLVACTINENDSTOP_NvMBlockDataStruct;

typedef struct
{
   uint8 VSCtl_prmLstCrsCtlDeacCaus1[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus2[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus3[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus4[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus5[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus6[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus7[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus8[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus9[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus10[11];
   uint8 VSCtl_prmLstCrsCtlDeacCaus11[11];
} VSC_NvMBlockDataStruct;


#endif /* NVMRAM_TYP_H */
