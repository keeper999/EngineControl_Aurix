/***************************************************************************
;**
;** FILE NAME      : IFAIRSYSIGSYS.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IFAIRSYSIGSYS.H"
#include "IFAIRSYSIGSYS_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

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
const boolean  Ext_bAcvByptECUMes_C = 0;
const boolean  Manu_inh_fuel_air_ratio = 0;
const uint8  AirSys_prm_pInMnfReq_If_C = 0;
const uint8  CoPt_noGearCord_Sfty_C = 0;
const uint8  IFAIRSYSIGSYS_u8Inhib = 0;
const uint8  Lfbk_on_enrich_thresh_gas = 0;
const uint8  LsSys_idxSelTEgDsMainOxCEstim_C = 0;
const uint8  LsSys_idxSelTEgUsMainOxCEstim_C = 0;
const uint8  Regime_moteur_8_bkpt_map[REGIME_MOTEUR_8_BKPT_MAP_COLS] = {0};
const sint16  Ext_tECUMes_BypC = 0;
const sint16  Io_map_manifold_press_offset = 0;
const sint16  Lfbk_on_enlean_thresh_gas = 0;
const uint16  EngM_rAirLdCor_2_A[ENGM_RAIRLDCOR_2_A_COLS] = {0};
const uint16  Io_map_manifold_press_gain = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Bps_brake_pedal_input;
boolean Bv_changement_rapport;
boolean Changement_rapport_bvm;
boolean CoCha_bTqReq;
boolean CoTqRStrt_bTraCoplAuthRaw;
boolean Crash_fps_mux;
boolean Ctrl_IS_VIN_VDS_BSI_492;
boolean Ctrl_IS_VIN_VIS_BSI_4B2;
boolean Ctrl_IS_VIN_WMI_BSI_4D2;
boolean EngSt_bCtlEngNOnIdl;
boolean Ext_bDft;
boolean Ext_bDrvCyGlbl;
boolean Ext_bFrstCrk;
boolean IgCmd_bCtlPmpReqTstCmpl;
boolean InjSys_bInhInjAntiFlood;
boolean ISCAN_bF572PM1375;
boolean ISCAN_bN10F4F2P437NotAvl;
boolean KnkMgt_bAcvKnkReg;
boolean LsMon_bEndMonResHeatLsUs;
boolean MonMisf_bDetInstMisf;
boolean OxC_bEndMonORngItrsv;
boolean OxC_bOxCHeatPhaReq;
boolean Rcd_anticipation_adc_mux;
boolean Rcd_mes_huile_moteur_mux;
boolean Rcd_post_ventil_mot_mux;
boolean Rcd_reveil_principal;
boolean StaCtl_bAcvStaReq;
boolean StaCtl_bStaReq;
boolean ThMgt_bPwrHldReq;
boolean ThMgt_bWarn_tCo;
boolean VSCtl_bVSLimReg;
uint32 Eng_nEng;
sint8 InjCtl_rDiagTrim;
uint8 Acceleration_vehicule_mux;
uint8 CoPt_noGearCord_Sfty;
uint8 CoPt_stPhaGearShift;
uint8 CoPTSt_stEngNew;
uint8 Ext_ctTDCTot;
uint8 Ext_iCtlAltLINExct;
uint8 Ext_idxCtlAltLINProvIdf;
uint8 Ext_iRvAltExct;
uint8 Ext_noEgdGearCord;
uint8 Ext_rAltCycOpStd;
uint8 Ext_rCtlAltLINCycOp;
uint8 Ext_rRvAltCycOp;
uint8 Ext_spdVehReqVSLim;
uint8 Ext_spdVehReqVSReg;
uint8 Ext_uLsUsMes;
uint8 Flev_fuel_level_mux;
uint8 GSI_noTarGear;
uint8 IgSys_prm_agIgMaxWiPrevAdpCy[IGSYS_PRM_AGIGMAXWIPREVADPCY_COLS];
uint8 ISCAN_u8N3F34DPM1413;
uint8 ISCAN_u8N8F7F2P301;
uint8 ISCAN_u8N8F7F2V003;
uint8 VlvSys_agCkClsExVlvCorRaw;
uint8 VlvSys_agCkOpInVlvCorRaw;
uint8 VoltCtl_AltPrgChDi_nEng;
uint8 VoltCtl_tiAltPrgCh;
sint16 EngLim_tqEngCur_Sfty;
sint16 Ext_tFuRailMes;
sint16 Ext_tFuUsPmpMes;
sint16 TqSys_tqCkAntiOscCord;
uint16 AFReg_facCorRichPrec;
uint16 Atmospheric_pressure;
uint16 Engine_air_load;
uint16 ExM_tExLsDsMainOxCEstim;
uint16 ExM_tExLsUsMainOxCEstim;
uint16 Ext_nEngLoResl;
uint16 Ext_pFuMes;
uint16 Ext_rAirLd;
uint16 Ext_tiToothLen;
uint16 Ext_uBatt;
uint16 Injector_constant;
uint16 InjSys_prm_facTranCmpCyl[INJSYS_PRM_FACTRANCMPCYL_COLS];
uint16 InM_pDsThr_facVlvOvlp;
uint16 Required_fuel_flow_rate;
uint16 Vitesse_vehicule_ard_mux;
uint16 Vitesse_vehicule_arg_mux;
uint16 Vitesse_vehicule_avd_mux;
uint16 Vitesse_vehicule_avg_mux;
uint16 Vitesse_vehicule_mux;
uint16 VoltCtl_IexctMax;
uint16 VoltCtl_uReqProdElec;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

