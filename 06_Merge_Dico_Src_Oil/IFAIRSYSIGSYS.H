/***************************************************************************
;**
;** FILE NAME      : IFAIRSYSIGSYS.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IFAIRSYSIGSYS_H
#define IFAIRSYSIGSYS_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ADC_ETAT_PROG_1                   3
#define ADC_ETAT_PROG_2                   4
#define ADC_ETAT_PROG_3                   5
#define ADC_ETAT_PROG_ETUDE               1
#define ADC_ETAT_PROG_LIVRAISON           2
#define ADC_ETAT_UC_APPAIRE_4             8
#define CoPTSt_stEndStall_SC              9
#define CoPTSt_stEngRun_SC                5
#define CoPTSt_stFirstStrt_SC             3
#define CoPTSt_stResv_SC                  0
#define CoPTSt_stResvPrec_SC              0
#define CoPTSt_stRstrt_SC                 7
#define CoPTSt_stStall_SC                 8
#define CoPTSt_stStop_SC                  1
#define CoPTSt_stStopSTT_SC               6
#define ECM_MUTE                          32
#define ENGM_RAIRLDCOR_2_A_COLS                ( 9 )
#define Ext_stTypGslGdi_SC                1
#define F30D_NODE                         10
#define F349_NODE                         11
#define F34D_NODE                         12
#define F38D_NODE                         13
#define F3CD_NODE                         14
#define F412_NODE                         15
#define F44D_NODE                         16
#define F489_NODE                         17
#define F4F2_NODE                         18
#define F50D_NODE                         19
#define F50E_NODE                         20
#define F552_NODE                         22
#define F592_NODE                         23
#define F5B2_NODE                         24
#define F612_NODE                         24
#define F7F2_NODE                         25
#define GasMgt_stTranGasGslIp_SC          2
#define GasMgt_stTranGslGasIp_SC          1
#define GUS_ST_PRESENT                    3
#define IFAIRSYSIGSYS_u8CovErr_LENGTH     8
#define IFAIRSYSIGSYS_u8CYL_LENGTH        6
#define IGNHAL_udtMODE_TEST               4
#define IGSYS_PRM_AGIGMAXWIPREVADPCY_COLS      ( 6 )
#define INJSYS_PRM_FACTRANCMPCYL_COLS          ( 6 )
#define KNKMGT_PRM_CTRBLINJCUTOFFPTL_COLS      ( 6 )
#define N_BUSOFF                          3
#define REGIME_MOTEUR_8_BKPT_MAP_COLS          ( 9 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Ext_bAcvByptECUMes_C;
extern const boolean  Manu_inh_fuel_air_ratio;
extern const uint8  AirSys_prm_pInMnfReq_If_C;
extern const uint8  CoPt_noGearCord_Sfty_C;
extern const uint8  Lfbk_on_enrich_thresh_gas;
extern const uint8  LsSys_idxSelTEgDsMainOxCEstim_C;
extern const uint8  LsSys_idxSelTEgUsMainOxCEstim_C;
extern const uint8  Regime_moteur_8_bkpt_map[REGIME_MOTEUR_8_BKPT_MAP_COLS];
extern const sint16  Ext_tECUMes_BypC;
extern const sint16  Io_map_manifold_press_offset;
extern const sint16  Lfbk_on_enlean_thresh_gas;
extern const uint16  EngM_rAirLdCor_2_A[ENGM_RAIRLDCOR_2_A_COLS];
extern const uint16  Io_map_manifold_press_gain;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Bps_brake_pedal_input;
extern boolean Bv_changement_rapport;
extern boolean Changement_rapport_bvm;
extern boolean CoCha_bTqReq;
extern boolean CoTqRStrt_bTraCoplAuthRaw;
extern boolean Crash_fps_mux;
extern boolean Ctrl_IS_VIN_VDS_BSI_492;
extern boolean Ctrl_IS_VIN_VIS_BSI_4B2;
extern boolean Ctrl_IS_VIN_WMI_BSI_4D2;
extern boolean EngSt_bCtlEngNOnIdl;
extern boolean Ext_bDft;
extern boolean Ext_bDrvCyGlbl;
extern boolean Ext_bFrstCrk;
extern boolean IgCmd_bCtlPmpReqTstCmpl;
extern boolean InjSys_bInhInjAntiFlood;
extern boolean ISCAN_bF572PM1375;
extern boolean ISCAN_bN10F4F2P437NotAvl;
extern boolean KnkMgt_bAcvKnkReg;
extern boolean LsMon_bEndMonResHeatLsUs;
extern boolean MonMisf_bDetInstMisf;
extern boolean OxC_bEndMonORngItrsv;
extern boolean OxC_bOxCHeatPhaReq;
extern boolean Rcd_anticipation_adc_mux;
extern boolean Rcd_mes_huile_moteur_mux;
extern boolean Rcd_post_ventil_mot_mux;
extern boolean Rcd_reveil_principal;
extern boolean StaCtl_bAcvStaReq;
extern boolean StaCtl_bStaReq;
extern boolean ThMgt_bPwrHldReq;
extern boolean ThMgt_bWarn_tCo;
extern boolean VSCtl_bVSLimReg;
extern uint32 Eng_nEng;
extern sint8 InjCtl_rDiagTrim;
extern uint8 Acceleration_vehicule_mux;
extern uint8 CoPt_noGearCord_Sfty;
extern uint8 CoPt_stPhaGearShift;
extern uint8 CoPTSt_stEngNew;
extern uint8 Ext_ctTDCTot;
extern uint8 Ext_iCtlAltLINExct;
extern uint8 Ext_idxCtlAltLINProvIdf;
extern uint8 Ext_iRvAltExct;
extern uint8 Ext_noEgdGearCord;
extern uint8 Ext_rAltCycOpStd;
extern uint8 Ext_rCtlAltLINCycOp;
extern uint8 Ext_rRvAltCycOp;
extern uint8 Ext_spdVehReqVSLim;
extern uint8 Ext_spdVehReqVSReg;
extern uint8 Ext_uLsUsMes;
extern uint8 Flev_fuel_level_mux;
extern uint8 GSI_noTarGear;
extern uint8 IgSys_prm_agIgMaxWiPrevAdpCy[IGSYS_PRM_AGIGMAXWIPREVADPCY_COLS];
extern uint8 ISCAN_u8N3F34DPM1413;
extern uint8 ISCAN_u8N8F7F2P301;
extern uint8 ISCAN_u8N8F7F2V003;
extern uint8 VlvSys_agCkClsExVlvCorRaw;
extern uint8 VlvSys_agCkOpInVlvCorRaw;
extern uint8 VoltCtl_AltPrgChDi_nEng;
extern uint8 VoltCtl_tiAltPrgCh;
extern sint16 EngLim_tqEngCur_Sfty;
extern sint16 Ext_tFuRailMes;
extern sint16 Ext_tFuUsPmpMes;
extern sint16 TqSys_tqCkAntiOscCord;
extern uint16 AFReg_facCorRichPrec;
extern uint16 Atmospheric_pressure;
extern uint16 Engine_air_load;
extern uint16 ExM_tExLsDsMainOxCEstim;
extern uint16 ExM_tExLsUsMainOxCEstim;
extern uint16 Ext_nEngLoResl;
extern uint16 Ext_pFuMes;
extern uint16 Ext_rAirLd;
extern uint16 Ext_tiToothLen;
extern uint16 Ext_uBatt;
extern uint16 Injector_constant;
extern uint16 InjSys_prm_facTranCmpCyl[INJSYS_PRM_FACTRANCMPCYL_COLS];
extern uint16 InM_pDsThr_facVlvOvlp;
extern uint16 Required_fuel_flow_rate;
extern uint16 Vitesse_vehicule_ard_mux;
extern uint16 Vitesse_vehicule_arg_mux;
extern uint16 Vitesse_vehicule_avd_mux;
extern uint16 Vitesse_vehicule_avg_mux;
extern uint16 Vitesse_vehicule_mux;
extern uint16 VoltCtl_IexctMax;
extern uint16 VoltCtl_uReqProdElec;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AC_EveRst_ACPresAcqIf(void);
void AC_SdlFast_ACPresAcqIf(void);
void AirPres_EveRst_AirExtPresAcqIf(void);
void AirPres_SdlFast_AirExtPresAcqIf(void);
void AirPres_SdlSlow_AirExtPresAcqIf(void);
void AirT_EveRst_AcqAirTIf(void);
void AirT_SdlMid_AcqAirTIf(void);
void Can_EveRst_FHCanF349If_2(void);
void Can_EveRst_FHCanF3C9If(void);
void Can_EveRst_FHCanF432If(void);
void Can_EveRst_FHCanF495If(void);
void Can_EveRst_FHCanF50EIf2(void);
void Can_EveRst_FHCanF592If(void);
void Can_EveRst_FHCanF612If(void);
void Can_EveRxn30D_FHCanF30DIf(void);
void Can_EveRxn349_FHCanF349If_2(void);
void Can_EveRxn34D_FHCanF34DAVIf(void);
void Can_EveRxn34D_FHCanF34DIf2(void);
void Can_EveRxn38D_FHCanF38DIf(void);
void Can_EveRxn3C9_FHCanF3C9If(void);
void Can_EveRxn432_FHCanF432If(void);
void Can_EveRxn495_FHCanF495If(void);
void Can_EveRxn4F2_FHCanF4F2AVIf(void);
void Can_EveRxn50E_FHCanF50EIf2(void);
void Can_EveRxn592_FHCanF592If(void);
void Can_EveRxn612_FHCanF612If(void);
void Can_EveRxn7F2_FHCanF7F2AVIf(void);
void Can_SdlSlow_FHCanF349If_2(void);
void Can_SdlSlow_FHCanF38DIf(void);
void Can_SdlSlow_FHCanF3C9If(void);
void Can_SdlSlow_FHCanF432If(void);
void Can_SdlSlow_FHCanF495If(void);
void Can_SdlSlow_FHCanF592If(void);
void Can_SdlSlow_FHCanF612If(void);
void CatMon_EveRst_CatAcvDiagIf(void);
void CatMon_SdlFast_CatAcvDiagIf(void);
void Cf_EveRst_CtrlCfgIf(void);
void Cf_EveRst_FlowMngIf(void);
void Cf_EveTele_TunCfgIf(void);
void Cf_SdlFast_CtrlCfgIf(void);
void Cf_SdlFast_FlowMngIf(void);
void Cf_SdlMid_FlowMngIf(void);
void Cf_SdlSlow_IfAirSys(void);
void CoFan_EveRst_CmdDiagCoFanIf(void);
void CoFan_SdlMid_CmdDiagCoFanIf(void);
void CrkMgt_SdlFast_IfTqSysIf(void);
void CrsCtl_SdlFast_CrsCtlOutTreatIf(void);
void DIAGCAN_EveRst_If(void);
void DIAGCAN_EveRxn092_If(void);
void EcuSt_EveRst_EcuMngIf(void);
void EcuSt_SdlMid_EcuMngIf(void);
void Eng_EveIni_tOilEstimIf(void);
void Eng_Sdl100ms_tOilEstimIf(void);
void EngLimTq_EveBDC_IgAdvTq3If(void);
void EngM_SdlMid_intkLoaEstimnIf(void);
void EngSt_EveRst_EngStrtStopIf(void);
void EngSt_SdlSlow_EngStrtStopIf(void);
void FuAcq_EveSpl_PFuAcqIf(void);
void FuAcq_SdlFast_PFuAcqIf(void);
void FuSysM_EveRst_tFuMIf(void);
void FuSysM_SdlSlow_tFuMIf(void);
void GD_EveCrTR_DCIf(void);
void GD_EveKOf_DCIf(void);
void GD_EveRst_GJDDIf(void);
void GD_SdlFast_GJDDIf(void);
void HeatSenO2_SdlFast_HeatSenO2MonIf(void);
void IFAIRSYSIGSYS_vidEntryInit(void);
void IgLim_EveBDC_CritZoneIf(void);
void IgLim_EveCrTR_CritZoneIf(void);
void IgLim_EveRst_CritZoneIf(void);
void IgLim_EveRTCr_CritZoneIf(void);
void Inj_EveRst_InjTiCorIf(void);
void Inj_SdlFast_InjTiCorIf(void);
void InjCrk_EveKOn_AntiFloodIf(void);
void InjCrk_EveRTCr_AntiFloodIf(void);
void InjCrk_EveStTCr_AntiFloodIf(void);
void InjCrk_SdlFast_AntiFloodIf(void);
void InjCtl_EveRst_IfAirSysIgSys(void);
void InjCtl_EveRTSt_IfAirSysIgSys(void);
void InjCtl_EveTDC_FarCtlUsCtlIf(void);
void InjCtl_SdlFast_IfAirSysIgSys(void);
void InjrM_EveCkSnOn_InjrMdlIf(void);
void InjrM_EveInj_InjrMdlIf(void);
void InjrM_EveRst_InjrMdlIf(void);
void InjrM_EveSpl_InjrMdlIf(void);
void InjrM_SdlFast_InjrMdlIf(void);
void InjSys_EveInj_facFuTranIf(void);
void InjSys_EveInj_mFuInjIf(void);
void InjSys_EveRst_facFuTranIf(void);
void InjSys_EveRst_mFuInjIf(void);
void InjSys_SdlFast_facFuTranIf(void);
void InjSys_SdlFast_mFuSpIf(void);
void ISCAN_EveRxn4C8_If(void);
void ISCAN_EveRxn572_If(void);
void ISCAN_EveRxn7F2_If(void);
void KnkTreat_EveRbl_KnkMgrCorRblIf(void);
void KnkTreat_EveRst_KnkMgrCorRblIf(void);
void Lin_EveRst_IsLinIf(void);
void Lin_SdlFast_IsLinIf(void);
void Misf_EveMisf_MisfDetCfmIf(void);
void Oil_EveRst_ActrTstCtlPmpIf(void);
void Oil_SdlMid_ActrTstCtlPmpIf(void);
void Pwr_EveRst_BattVoltAcqIf(void);
void Pwr_EveRst_FuSysBattVoltAcqIf(void);
void Pwr_SdlFast_BattVoltAcqIf(void);
void RE_AdvMaxT_001_MSEIf(void);
void RE_AdvMaxT_002_DREIf(void);
void RE_AirSysAir_001_MSEIf(void);
void RE_AirSysAir_005_TEVIf(void);
void RE_CoClLASl_001_MSEIf(void);
void RE_CoGBx_001_MSEIf(void);
void RE_EngM_initIf(void);
void RE_ExMGslT2_001_MSEIf(void);
void RE_ExMGslT2_006_TEVIf(void);
void RE_InMdlT_020_TEVIf(void);
void RE_InMdlT_043_MSEIf(void);
void RE_OEMGsl_001_MSEIf(void);
void RE_OEMGsl_003_TEVIf(void);
void RE_ProdElEm_005_MSEIf(void);
void RE_ProdElEm_006_TEVIf(void);
void RE_StopStrtEm_003_MSEIf(void);
void RE_StopStrtEm_004_TEVIf(void);
void RE_StopStrtEng_013_MSEIf(void);
void RE_StopStrtEng_014_TEVIf(void);
void RE_StopStrtEng_023_MSEIf(void);
void RE_StopStrtEng_024_TEVIf(void);
void RE_ThMgt_001_MSEIf(void);
void RE_ThMgt_002_TEVIf(void);
void RE_TPM_001_MSEIf(void);
void RE_TPM_008_TEVIf(void);
void RE_TqSys_EveSync_CurCorIf(void);
void RE_TqSys_EveSync_IdlCordLimIf(void);
void RE_TqSys_Sdl10ms_CoPtGearCordIf(void);
void RE_TqTreat_003_MSEIf(void);
void RE_TqTreat_004_TEVIf(void);
void RE_TraBVx_001_MSEIf(void);
void RE_TraBVx_028_TEVIf(void);
void SenAct_EveCrTR_tECUAcqIf(void);
void SenAct_EveRst_tECUAcqIf(void);
void SenAct_EveRTSt_tECUAcqIf(void);
void SenAct_SdlMid_tECUAcqIf(void);
void SenO2Ds_SdlFast_DsLsAcqIf(void);
void SenO2Us_SdlFast_UpLsAcqIf(void);
void Sync_EveCkSnOn_CkMngIfIf(void);
void Sync_EveCkSnOn_FuSysCkMngIf(void);
void Sync_EveCkSnOn_IfAirSysIgSys(void);
void Sync_EveRst_CkMngIfIf(void);
void Sync_EveRst_FuSysCkMngIf(void);
void Sync_EveRst_IfAirSysIgSys(void);
void Sync_EveRTSt_CkMngIfIf(void);
void Sync_EveRTSt_FuSysCkMngIf(void);
void Sync_EveRTSt_IfAirSysIgSys(void);
void Sync_EveStTR_FuSysCkMngIf(void);
void Sync_EveTDC_CkMngIfIf(void);
void Sync_EveTDC_FuSysCkMngIf(void);
void Sync_EveTDC_IfAirSysIgSys(void);
void Thr_EveFRMUpd_ThrSecuMngIf(void);
void Thr_SdlMid_MngServoIf(void);
void TqRes_Sdl10ms_tqAltResIf(void);
void TqSys_EveRst_tqLimSftyIf(void);
void TqSys_SdlFast_tqLimSftyIf(void);
void UsThrM_EvePwrl_AmbPEstimnIf(void);
void VlvSys_EveIni_VlvExIf(void);
void VlvSys_EveIni_VlvInIf(void);
void VlvSys_SdlFast_VlvExIf(void);
void VlvSys_SdlFast_VlvInIf(void);


#endif /* IFAIRSYSIGSYS_H */

/*-------------------------------- end of file -------------------------------*/
