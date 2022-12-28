/***************************************************************************
;**
;** FILE NAME      : TUNCFG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TUNCFG.H"
#include "TUNCFG_L.H"
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
const boolean  Cf_bPresPAirExtSens_C = 0;
const boolean  Cf_bSecBrkPedPrss_C = 0;
const boolean  Cf_bSecBrkPedPrssDiag_C = 0;
const boolean  Ctrl_bSelWgCmdSpCf_C = 0;
const boolean  Ctrl_bTraNoTarGear_C = 0;
const boolean  EcuSt_bAcvRcdMod_EcuMng_C = 0;
const boolean  Ext_bACCf_C = 0;
const boolean  Ext_bArchiCf_C = 0;
const boolean  Ext_bASECf_C = 0;
const boolean  Ext_bBrkAutoCf_C = 0;
const boolean  Ext_bBrkDiagRelbCf_C = 0;
const boolean  Ext_bBrkMainInfoCf_C = 0;
const boolean  Ext_bCabHeatDCT_C = 0;
const boolean  Ext_bCf_nAvrFrntWhl_C = 0;
const boolean  Ext_bCoReqVehCf_bEngStrtReq_C = 0;
const boolean  Ext_bCtlCmdPTTqCf_C = 0;
const boolean  Ext_bDAE_DAEHCf_C = 0;
const boolean  Ext_bDetLoWhlGripCf_C = 0;
const boolean  Ext_bDftLogCf_C = 0;
const boolean  Ext_bEgrCf_C = 0;
const boolean  Ext_bElASRESPCf_C = 0;
const boolean  Ext_bEngTrbMode_C = 0;
const boolean  Ext_bFanDiagCf_C = 0;
const boolean  Ext_bFilCf_spdVehAvrFrntWhl_C = 0;
const boolean  Ext_bG3G4Cf_C = 0;
const boolean  Ext_bLowFuelLevelSel_C = 0;
const boolean  Ext_bOilLvlCf_C = 0;
const boolean  Ext_bPACKDYNCf_C = 0;
const boolean  Ext_bPresEGRVlv_C = 0;
const boolean  Ext_bPresExCmSen_C = 0;
const boolean  Ext_bPresGaz_C = 0;
const boolean  Ext_bPresInCmSen_C = 0;
const boolean  Ext_bReadBrkParkCf_C = 0;
const boolean  Ext_bSpdCf_C = 0;
const boolean  Ext_bStrtDrvIfTypCf_C = 0;
const boolean  Ext_bSTTCf_C = 0;
const boolean  Ext_bTqWhlBrkCf_C = 0;
const boolean  Ext_bTTCf_C = 0;
const boolean  Ext_bTyreWarnCf_C = 0;
const boolean  Ext_bVSMaxfCf_C = 0;
const boolean  Ext_bVSMaxsCf_C = 0;
const boolean  Ext_stDirMoveVehCf_C = 0;
const boolean  TunCfg_bva_kickdown_C = 0;
const boolean  TunCfg_bvmp_kickdown_C = 0;
const uint8  Calibration_gestion[CALIBRATION_GESTION_COLS] = {0};
const uint8  Calibration_reference[CALIBRATION_REFERENCE_COLS] = {0};
const uint8  Ext_stBattTypCf_C = 0;
const uint8  Ext_stCtlCmdPTTqPot_C = 0;
const uint8  Ext_stDrivAltMgt_Cf_C = 0;
const uint8  Ext_stECUTypCf_C = 0;
const uint8  Ext_stElEMgtCf_C = 0;
const uint8  Ext_stEOBDCf_C = 0;
const uint8  Ext_stFuTypCf_C = 0;
const uint8  Ext_stOilPresCf_C = 0;
const uint8  Ext_stOilTCf_C = 0;
const uint8  Ext_stPTCf_C = 0;
const uint8  Ext_stStaCf_C = 0;
const uint8  Ext_stStgPmpCf_C = 0;
const uint8  Ext_stStrtRstrtDevCf_C = 0;
const uint8  Ext_stTypInjSysCf_C = 0;
const uint8  Ext_stUcapTypCf_C = 0;
const uint8  Ext_stVSCtlRegCf_C = 0;
const uint8  Ext_stVSSCf_C = 0;
const uint8  TUNCFG_u8Inhib = 0;
const uint16  Ext_facRatTqAltCf_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Abs_mux;
boolean Amvar_present;
boolean Cf_bPresPAirExtSens;
boolean Cf_bSecBrkPedPrssDiag;
boolean Cl_config_pression_refri_0;
boolean Cl_config_pression_refri_3;
boolean CoSTT_bAcv;
boolean Ctrl_bSelWgCmdSpCf;
boolean Ctrl_bTraNoTarGear;
boolean Da_present;
boolean EcuSt_bAcvRcdMod_EcuMng;
boolean Esp_present;
boolean Ext_bBlowBy1Cf;
boolean Ext_bBPGACf;
boolean Ext_bBrkDiagRelbCf;
boolean Ext_bBrkMainInfoCf;
boolean Ext_bBrkParkCf;
boolean Ext_bCf_nAvrFrntWhl;
boolean Ext_bDAE_DAEHCf;
boolean Ext_bDftLogCf;
boolean Ext_bEasyMoveCf;
boolean Ext_bEgrCf;
boolean Ext_bElASRESPCf;
boolean Ext_bEngTrbMode;
boolean Ext_bEPBCf;
boolean Ext_bFanDiagCf;
boolean Ext_bFilCf_spdVehAvrFrntWhl;
boolean Ext_bG3G4Cf;
boolean Ext_bLowFuelLevelSel;
boolean Ext_bOilLvlCf;
boolean Ext_bPACKDYNCf;
boolean Ext_bPresEGRVlv;
boolean Ext_bReadBrkParkCf;
boolean Ext_bSpdCf;
boolean Ext_bStrtDrvIfCf;
boolean Ext_bStrtDrvIfTypCf;
boolean Ext_bTTCf;
boolean Ext_bVSRegCf;
boolean Presence_bva;
boolean Presence_bvmp;
uint8 Ext_stAltClasVarCf;
uint8 Ext_stBodyCf;
uint8 Ext_stCabHeatCf;
uint8 Ext_stCabHeatVarCf;
uint8 Ext_stCfFan;
uint8 Ext_stDrivAltMgt_Cf;
uint8 Ext_stECUTypCf;
uint8 Ext_stElEMgtCf;
uint8 Ext_stEOBDCf;
uint8 Ext_stOilPresCf;
uint8 Ext_stOilTCf;
uint8 Ext_stStrtRstrtDevCf;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

