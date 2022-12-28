/*
 * This is Ioc.h, auto-generated for:
 *   Project: P2017_ASW
 *   Target:  TriCoreHighTec
 *   Variant: TC29x
 *   Version: 5.0.2
 *   [$UKS 1359] [$UKS 1334] [$UKS 1454]
 */
#ifndef OS_IOC_H
#define OS_IOC_H
/* [MISRA 2004 Rule 19.7] */ /*lint -estring(961, IocRead* ,IocWrite* ,IocSend* ,IocRec*) */
#include "Rte_Os_Type.h"

#define IOC_E_OK        RTE_E_OK         /* [$UKS 1360] */
#define IOC_E_NOK       RTE_E_NOK        /* [$UKS 1361] */
#define IOC_E_LIMIT     RTE_E_LIMIT      /* [$UKS 1362] */
#define IOC_E_LOST_DATA RTE_E_LOST_DATA  /* [$UKS 1363] */
#define IOC_E_NO_DATA   RTE_E_NO_DATA    /* [$UKS 1364] */

  
/* IOC internal data */
typedef struct {
  dt_Commande_GMV_C Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_GMV_C_Commande_GMV_C;
  dt_Commande_bpm_pwm_rco Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco;
  dt_Commande_ectdrv_pwm_rco Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco;
  dt_Commande_pompe_ess_pwm Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm;
  dt_Commande_purge_pwm_freq Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_freq_Commande_purge_pwm_freq;
  dt_Commande_purge_pwm_rco Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_rco_Commande_purge_pwm_rco;
  dt_Commande_vvt_adm_pwm_rco Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco;
  dt_Commande_vvt_ech_pwm_rco Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco;
  dt_Ext_rTotLd Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_rTotLd_Ext_rTotLd;
  dt_IMMO_stEcuLockStTyp Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp;
  dt_IgSys_iESpBenchMod Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_iESpBenchMod_IgSys_iESpBenchMod;
  dt_IgSys_tiDwellSpBenchMod Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod;
  dt_Tension_batterie_filt Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Tension_batterie_filt_Tension_batterie_filt;
  uint8 Os_Ioc_Rte_State_Application_Core0_0;
  uint8 Os_Ioc_Rte_State_Application_Core0_1;
  uint8 Os_Ioc_Rte_State_Application_Core1_0;
  uint8 Os_Ioc_Rte_State_Application_Core1_1;
  uint8 Os_Ioc_Rte_State_Application_Core2_0;
  uint8 Os_Ioc_Rte_State_Application_Core2_1;
  dt_Cf_cooling_fan_equipment Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment;
  dt_Ctrl_bAcv_ECTReq Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq;
  dt_Ctrl_bAcv_FuTnkPmp Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp;
  dt_Demande_inhibition_hbridge Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Demande_inhibition_hbridge_Demande_inhibition_hbridge;
  dt_ECU_bImmoUnlockWkuSt Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt;
  dt_Clef_de_contact Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Clef_de_contact_Clef_de_contact;
  dt_Code_test_action Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Code_test_action_Code_test_action;
  dt_IgCmd_agIgSpNxt Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt;
  dt_IgCmd_agIgSp Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSp_IgCmd_agIgSp;
  dt_IgCmd_bPwrRlyCmd Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd;
  dt_IgSys_bIgBenchModEna Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna;
  dt_Misfire_cylindre_1 Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_1_Misfire_cylindre_1;
  dt_Misfire_cylindre_2 Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_2_Misfire_cylindre_2;
  dt_Misfire_cylindre_3 Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_3_Misfire_cylindre_3;
  dt_Misfire_cylindre_4 Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_4_Misfire_cylindre_4;
  dt_SenAct_tIGBTAcq Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_SenAct_tIGBTAcq_SenAct_tIGBTAcq;
  dt_Srv_stActrTstStatus Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Srv_stActrTstStatus_Srv_stActrTstStatus;
  dt_Sync_bEngSyncAccu Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Sync_bEngSyncAccu_Sync_bEngSyncAccu;
  dt_Dena_oc_bobine1 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine1_Dena_oc_bobine1;
  dt_Dena_oc_bobine2 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine2_Dena_oc_bobine2;
  dt_Dena_oc_bobine3 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine3_Dena_oc_bobine3;
  dt_Dena_oc_bobine4 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine4_Dena_oc_bobine4;
  dt_Dena_scg_bobine1 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine1_Dena_scg_bobine1;
  dt_Dena_scg_bobine2 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine2_Dena_scg_bobine2;
  dt_Dena_scg_bobine3 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine3_Dena_scg_bobine3;
  dt_Dena_scg_bobine4 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine4_Dena_scg_bobine4;
  dt_Dena_scp_bobine1 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine1_Dena_scp_bobine1;
  dt_Dena_scp_bobine2 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine2_Dena_scp_bobine2;
  dt_Dena_scp_bobine3 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine3_Dena_scp_bobine3;
  dt_Dena_scp_bobine4 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine4_Dena_scp_bobine4;
  dt_Dft_oc_bobine1 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine1_Dft_oc_bobine1;
  dt_Dft_oc_bobine2 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine2_Dft_oc_bobine2;
  dt_Dft_oc_bobine3 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine3_Dft_oc_bobine3;
  dt_Dft_oc_bobine4 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine4_Dft_oc_bobine4;
  dt_Dft_scg_bobine1 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine1_Dft_scg_bobine1;
  dt_Dft_scg_bobine2 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine2_Dft_scg_bobine2;
  dt_Dft_scg_bobine3 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine3_Dft_scg_bobine3;
  dt_Dft_scg_bobine4 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine4_Dft_scg_bobine4;
  dt_Dft_scp_bobine1 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine1_Dft_scp_bobine1;
  dt_Dft_scp_bobine2 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine2_Dft_scp_bobine2;
  dt_Dft_scp_bobine3 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine3_Dft_scp_bobine3;
  dt_Dft_scp_bobine4 Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine4_Dft_scp_bobine4;
  dt_Icd_ratio_energy Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_ratio_energy_Icd_ratio_energy;
  dt_Icd_state Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_state_Icd_state;
  DT_ECU_bWkuMain Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bWkuMain_ECU_bWkuMain;
  DT_UCE_bPwrlAcv Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_UCE_bPwrlAcv_UCE_bPwrlAcv;
  DT_Eng_noCmprCyl Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprCyl_Eng_noCmprCyl;
  DT_Eng_noCmprNxtCyl Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl;
  DT_Ext_bDirRotCk Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_bDirRotCk_Ext_bDirRotCk;
  DT_Ext_noCylEng Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_noCylEng_Ext_noCylEng;
  UInt8 Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_32_Regime_moteur_32;
  UInt16 Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_Regime_moteur;
  UInt8 Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Temperature_eau_Temperature_eau;
} Os_IocDataType;




/* ------------------------------------------------- */
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_START_SEC_CODE_LIB
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */
/* Communication: Rte_State_Application_Core0_0 */
#define IocWrite_Rte_State_Application_Core0_0(value) (Os_IocData.Os_Ioc_Rte_State_Application_Core0_0 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core0' on core 0 */
#define IocRead_Rte_State_Application_Core0_0(value) (*value = Os_IocData.Os_Ioc_Rte_State_Application_Core0_0, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_State_Application_Core0_1 */
#define IocWrite_Rte_State_Application_Core0_1(value) (Os_IocData.Os_Ioc_Rte_State_Application_Core0_1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core0' on core 0 */
#define IocRead_Rte_State_Application_Core0_1(value) (*value = Os_IocData.Os_Ioc_Rte_State_Application_Core0_1, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_State_Application_Core1_0 */
#define IocWrite_Rte_State_Application_Core1_0(value) (Os_IocData.Os_Ioc_Rte_State_Application_Core1_0 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_State_Application_Core1_0(value) (*value = Os_IocData.Os_Ioc_Rte_State_Application_Core1_0, IOC_E_OK) /* Only callable from trusted 'Application_Core0' on core 0 */
 
/* Communication: Rte_State_Application_Core1_1 */
#define IocWrite_Rte_State_Application_Core1_1(value) (Os_IocData.Os_Ioc_Rte_State_Application_Core1_1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_State_Application_Core1_1(value) (*value = Os_IocData.Os_Ioc_Rte_State_Application_Core1_1, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_State_Application_Core2_0 */
#define IocWrite_Rte_State_Application_Core2_0(value) (Os_IocData.Os_Ioc_Rte_State_Application_Core2_0 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_State_Application_Core2_0(value) (*value = Os_IocData.Os_Ioc_Rte_State_Application_Core2_0, IOC_E_OK) /* Only callable from trusted 'Application_Core0' on core 0 */
 
/* Communication: Rte_State_Application_Core2_1 */
#define IocWrite_Rte_State_Application_Core2_1(value) (Os_IocData.Os_Ioc_Rte_State_Application_Core2_1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_State_Application_Core2_1(value) (*value = Os_IocData.Os_Ioc_Rte_State_Application_Core2_1, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Cf_cooling_fan_equipment_Cf_cooling_fan_equipment, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_GMV_C_Commande_GMV_C */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_GMV_C_Commande_GMV_C(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_GMV_C_Commande_GMV_C = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_GMV_C_Commande_GMV_C(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_GMV_C_Commande_GMV_C, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_bpm_pwm_rco_Commande_bpm_pwm_rco, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_ectdrv_pwm_rco_Commande_ectdrv_pwm_rco, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_pompe_ess_pwm_Commande_pompe_ess_pwm, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_freq_Commande_purge_pwm_freq */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_freq_Commande_purge_pwm_freq(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_freq_Commande_purge_pwm_freq = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_freq_Commande_purge_pwm_freq(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_freq_Commande_purge_pwm_freq, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_rco_Commande_purge_pwm_rco */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_rco_Commande_purge_pwm_rco(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_rco_Commande_purge_pwm_rco = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_rco_Commande_purge_pwm_rco(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_purge_pwm_rco_Commande_purge_pwm_rco, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_adm_pwm_rco_Commande_vvt_adm_pwm_rco, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Commande_vvt_ech_pwm_rco_Commande_vvt_ech_pwm_rco, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_ECTReq_Ctrl_bAcv_ECTReq, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Ctrl_bAcv_FuTnkPmp_Ctrl_bAcv_FuTnkPmp, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_Demande_inhibition_hbridge_Demande_inhibition_hbridge */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_Demande_inhibition_hbridge_Demande_inhibition_hbridge(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Demande_inhibition_hbridge_Demande_inhibition_hbridge = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_Demande_inhibition_hbridge_Demande_inhibition_hbridge(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_Demande_inhibition_hbridge_Demande_inhibition_hbridge, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bImmoUnlockWkuSt_ECU_bImmoUnlockWkuSt, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bWkuMain_ECU_bWkuMain */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bWkuMain_ECU_bWkuMain(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bWkuMain_ECU_bWkuMain = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bWkuMain_ECU_bWkuMain(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_ECU_bWkuMain_ECU_bWkuMain, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_CMDPWM_R_UCE_bPwrlAcv_UCE_bPwrlAcv */
#define IocWrite_Rte_inst_TopLevelComposition_CMDPWM_R_UCE_bPwrlAcv_UCE_bPwrlAcv(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_UCE_bPwrlAcv_UCE_bPwrlAcv = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_CMDPWM_R_UCE_bPwrlAcv_UCE_bPwrlAcv(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_CMDPWM_R_UCE_bPwrlAcv_UCE_bPwrlAcv, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Clef_de_contact_Clef_de_contact */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Clef_de_contact_Clef_de_contact(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Clef_de_contact_Clef_de_contact = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Clef_de_contact_Clef_de_contact(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Clef_de_contact_Clef_de_contact, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Code_test_action_Code_test_action */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Code_test_action_Code_test_action(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Code_test_action_Code_test_action = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Code_test_action_Code_test_action(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Code_test_action_Code_test_action, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprCyl_Eng_noCmprCyl */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprCyl_Eng_noCmprCyl(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprCyl_Eng_noCmprCyl = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprCyl_Eng_noCmprCyl(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprCyl_Eng_noCmprCyl, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_bDirRotCk_Ext_bDirRotCk */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_bDirRotCk_Ext_bDirRotCk(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_bDirRotCk_Ext_bDirRotCk = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_bDirRotCk_Ext_bDirRotCk(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_bDirRotCk_Ext_bDirRotCk, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_noCylEng_Ext_noCylEng */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_noCylEng_Ext_noCylEng(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_noCylEng_Ext_noCylEng = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_noCylEng_Ext_noCylEng(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_noCylEng_Ext_noCylEng, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_rTotLd_Ext_rTotLd */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_rTotLd_Ext_rTotLd(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_rTotLd_Ext_rTotLd = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_rTotLd_Ext_rTotLd(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Ext_rTotLd_Ext_rTotLd, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IMMO_stEcuLockStTyp_IMMO_stEcuLockStTyp, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSpNxt_IgCmd_agIgSpNxt, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSp_IgCmd_agIgSp */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSp_IgCmd_agIgSp(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSp_IgCmd_agIgSp = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSp_IgCmd_agIgSp(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_agIgSp_IgCmd_agIgSp, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgCmd_bPwrRlyCmd_IgCmd_bPwrRlyCmd, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_bIgBenchModEna_IgSys_bIgBenchModEna, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_iESpBenchMod_IgSys_iESpBenchMod */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_iESpBenchMod_IgSys_iESpBenchMod(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_iESpBenchMod_IgSys_iESpBenchMod = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_iESpBenchMod_IgSys_iESpBenchMod(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_iESpBenchMod_IgSys_iESpBenchMod, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_IgSys_tiDwellSpBenchMod_IgSys_tiDwellSpBenchMod, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_1_Misfire_cylindre_1 */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_1_Misfire_cylindre_1(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_1_Misfire_cylindre_1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_1_Misfire_cylindre_1(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_1_Misfire_cylindre_1, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_2_Misfire_cylindre_2 */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_2_Misfire_cylindre_2(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_2_Misfire_cylindre_2 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_2_Misfire_cylindre_2(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_2_Misfire_cylindre_2, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_3_Misfire_cylindre_3 */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_3_Misfire_cylindre_3(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_3_Misfire_cylindre_3 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_3_Misfire_cylindre_3(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_3_Misfire_cylindre_3, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_4_Misfire_cylindre_4 */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_4_Misfire_cylindre_4(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_4_Misfire_cylindre_4 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_4_Misfire_cylindre_4(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Misfire_cylindre_4_Misfire_cylindre_4, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_32_Regime_moteur_32 */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_32_Regime_moteur_32(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_32_Regime_moteur_32 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_32_Regime_moteur_32(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_32_Regime_moteur_32, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_Regime_moteur */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_Regime_moteur(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_Regime_moteur = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_Regime_moteur(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Regime_moteur_Regime_moteur, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_SenAct_tIGBTAcq_SenAct_tIGBTAcq */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_SenAct_tIGBTAcq_SenAct_tIGBTAcq(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_SenAct_tIGBTAcq_SenAct_tIGBTAcq = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_SenAct_tIGBTAcq_SenAct_tIGBTAcq(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_SenAct_tIGBTAcq_SenAct_tIGBTAcq, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Srv_stActrTstStatus_Srv_stActrTstStatus */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Srv_stActrTstStatus_Srv_stActrTstStatus(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Srv_stActrTstStatus_Srv_stActrTstStatus = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Srv_stActrTstStatus_Srv_stActrTstStatus(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Srv_stActrTstStatus_Srv_stActrTstStatus, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Sync_bEngSyncAccu_Sync_bEngSyncAccu */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Sync_bEngSyncAccu_Sync_bEngSyncAccu(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Sync_bEngSyncAccu_Sync_bEngSyncAccu = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Sync_bEngSyncAccu_Sync_bEngSyncAccu(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Sync_bEngSyncAccu_Sync_bEngSyncAccu, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Temperature_eau_Temperature_eau */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Temperature_eau_Temperature_eau(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Temperature_eau_Temperature_eau = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Temperature_eau_Temperature_eau(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Temperature_eau_Temperature_eau, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_IGCOILMNG_R_Tension_batterie_filt_Tension_batterie_filt */
#define IocWrite_Rte_inst_TopLevelComposition_IGCOILMNG_R_Tension_batterie_filt_Tension_batterie_filt(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Tension_batterie_filt_Tension_batterie_filt = value, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
#define IocRead_Rte_inst_TopLevelComposition_IGCOILMNG_R_Tension_batterie_filt_Tension_batterie_filt(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_IGCOILMNG_R_Tension_batterie_filt_Tension_batterie_filt, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine1_Dena_oc_bobine1 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine1_Dena_oc_bobine1(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine1_Dena_oc_bobine1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine1_Dena_oc_bobine1(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine1_Dena_oc_bobine1, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine2_Dena_oc_bobine2 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine2_Dena_oc_bobine2(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine2_Dena_oc_bobine2 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine2_Dena_oc_bobine2(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine2_Dena_oc_bobine2, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine3_Dena_oc_bobine3 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine3_Dena_oc_bobine3(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine3_Dena_oc_bobine3 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine3_Dena_oc_bobine3(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine3_Dena_oc_bobine3, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine4_Dena_oc_bobine4 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine4_Dena_oc_bobine4(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine4_Dena_oc_bobine4 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine4_Dena_oc_bobine4(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_oc_bobine4_Dena_oc_bobine4, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine1_Dena_scg_bobine1 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine1_Dena_scg_bobine1(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine1_Dena_scg_bobine1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine1_Dena_scg_bobine1(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine1_Dena_scg_bobine1, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine2_Dena_scg_bobine2 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine2_Dena_scg_bobine2(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine2_Dena_scg_bobine2 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine2_Dena_scg_bobine2(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine2_Dena_scg_bobine2, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine3_Dena_scg_bobine3 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine3_Dena_scg_bobine3(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine3_Dena_scg_bobine3 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine3_Dena_scg_bobine3(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine3_Dena_scg_bobine3, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine4_Dena_scg_bobine4 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine4_Dena_scg_bobine4(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine4_Dena_scg_bobine4 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine4_Dena_scg_bobine4(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scg_bobine4_Dena_scg_bobine4, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine1_Dena_scp_bobine1 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine1_Dena_scp_bobine1(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine1_Dena_scp_bobine1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine1_Dena_scp_bobine1(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine1_Dena_scp_bobine1, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine2_Dena_scp_bobine2 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine2_Dena_scp_bobine2(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine2_Dena_scp_bobine2 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine2_Dena_scp_bobine2(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine2_Dena_scp_bobine2, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine3_Dena_scp_bobine3 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine3_Dena_scp_bobine3(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine3_Dena_scp_bobine3 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine3_Dena_scp_bobine3(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine3_Dena_scp_bobine3, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine4_Dena_scp_bobine4 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine4_Dena_scp_bobine4(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine4_Dena_scp_bobine4 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine4_Dena_scp_bobine4(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dena_scp_bobine4_Dena_scp_bobine4, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine1_Dft_oc_bobine1 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine1_Dft_oc_bobine1(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine1_Dft_oc_bobine1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine1_Dft_oc_bobine1(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine1_Dft_oc_bobine1, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine2_Dft_oc_bobine2 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine2_Dft_oc_bobine2(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine2_Dft_oc_bobine2 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine2_Dft_oc_bobine2(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine2_Dft_oc_bobine2, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine3_Dft_oc_bobine3 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine3_Dft_oc_bobine3(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine3_Dft_oc_bobine3 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine3_Dft_oc_bobine3(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine3_Dft_oc_bobine3, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine4_Dft_oc_bobine4 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine4_Dft_oc_bobine4(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine4_Dft_oc_bobine4 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine4_Dft_oc_bobine4(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_oc_bobine4_Dft_oc_bobine4, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine1_Dft_scg_bobine1 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine1_Dft_scg_bobine1(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine1_Dft_scg_bobine1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine1_Dft_scg_bobine1(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine1_Dft_scg_bobine1, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine2_Dft_scg_bobine2 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine2_Dft_scg_bobine2(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine2_Dft_scg_bobine2 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine2_Dft_scg_bobine2(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine2_Dft_scg_bobine2, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine3_Dft_scg_bobine3 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine3_Dft_scg_bobine3(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine3_Dft_scg_bobine3 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine3_Dft_scg_bobine3(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine3_Dft_scg_bobine3, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine4_Dft_scg_bobine4 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine4_Dft_scg_bobine4(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine4_Dft_scg_bobine4 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine4_Dft_scg_bobine4(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scg_bobine4_Dft_scg_bobine4, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine1_Dft_scp_bobine1 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine1_Dft_scp_bobine1(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine1_Dft_scp_bobine1 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine1_Dft_scp_bobine1(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine1_Dft_scp_bobine1, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine2_Dft_scp_bobine2 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine2_Dft_scp_bobine2(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine2_Dft_scp_bobine2 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine2_Dft_scp_bobine2(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine2_Dft_scp_bobine2, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine3_Dft_scp_bobine3 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine3_Dft_scp_bobine3(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine3_Dft_scp_bobine3 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine3_Dft_scp_bobine3(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine3_Dft_scp_bobine3, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine4_Dft_scp_bobine4 */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine4_Dft_scp_bobine4(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine4_Dft_scp_bobine4 = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine4_Dft_scp_bobine4(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Dft_scp_bobine4_Dft_scp_bobine4, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_ratio_energy_Icd_ratio_energy */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_ratio_energy_Icd_ratio_energy(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_ratio_energy_Icd_ratio_energy = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_ratio_energy_Icd_ratio_energy(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_ratio_energy_Icd_ratio_energy, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* Communication: Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_state_Icd_state */
#define IocWrite_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_state_Icd_state(value) (Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_state_Icd_state = value, IOC_E_OK) /* Only callable from trusted 'Application_Core2' on core 2 */
#define IocRead_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_state_Icd_state(value) (*value = Os_IocData.Os_Ioc_Rte_inst_TopLevelComposition_VirtualComponent_R_Icd_state_Icd_state, IOC_E_OK) /* Only callable from trusted 'Application_Core1' on core 1 */
 
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_STOP_SEC_CODE_LIB
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */

/* ------------------------------------------------- */
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */
extern VAR(Os_IocDataType, OS_VAR_NOINIT) Os_IocData;
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */

/* ------------------------------------------------- */
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */
extern OS_VOLATILE VAR(Os_Lockable, OS_VAR_POWER_ON_INIT) Os_lock_iocaccess;
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */


#endif /* OS_IOC_H */
