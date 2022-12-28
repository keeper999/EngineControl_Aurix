/***************************************************************************
;**
;** FILE NAME      : TUNCFG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TUNCFG_H
#define TUNCFG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ALT_CLASS_LIN_12                  4
#define ALT_CLASS_LIN_15                  6
#define ALT_CLASS_LIN_18                  5
#define ALT_CLASS_LIN_22                  7
#define ALT_CLASS_LIN_7                   0
#define ALT_CLASS_LIN_8p                  1
#define ALT_CLASSE_12                     65503
#define ALT_CLASSE_15                     65471
#define ALT_CLASSE_8p                     65527
#define ALTERNATEUR_12                    4
#define ALTERNATEUR_15                    5
#define ALTERNATEUR_18                    6
#define ALTERNATEUR_22                    7
#define ALTERNATEUR_7                     0
#define ALTERNATEUR_8p                    2
#define BVA_AT6                           1
#define BVA_DCT                           3
#define BVM_BE                            7
#define BVM_MCM                           7
#define BVMP_BE                           0
#define BVMP_MCP                          4
#define CALIBRATION_GESTION_COLS               ( 5 )
#define CALIBRATION_REFERENCE_COLS             ( 4 )
#define CAR0                              0
#define CAR1                              1
#define CAR2                              2
#define CAR3                              3
#define CAR4                              4
#define CAR5                              5
#define CAR6                              6
#define CAR7                              7
#define CHA0                              0
#define CHA1                              1
#define CHA2                              2
#define CHA3                              3
#define CHA4                              4
#define CHA5                              5
#define CHA6                              6
#define CHA7                              7
#define EQUIPMENT_A                       7
#define EQUIPMENT_B1                      32
#define EQUIPMENT_B2                      64
#define EQUIPMENT_C                       16
#define FRIC_EQUIPMENT_A                  253
#define FRIC_EQUIPMENT_B1                 247
#define FRIC_EQUIPMENT_B2                 239
#define FRIC_EQUIPMENT_C                  127
#define PRESENCE_BV_AT6                   247
#define PRESENCE_BV_BE                    254
#define PRESENCE_BV_DCT                   239
#define PRESENCE_BV_MCM                   253
#define PRESENCE_BV_MCP                   251
#define PRESENCE_CAR0                     254
#define PRESENCE_CAR1                     253
#define PRESENCE_CAR2                     251
#define PRESENCE_CAR3                     247
#define PRESENCE_CAR4                     239
#define PRESENCE_CAR5                     223
#define PRESENCE_CAR6                     191
#define PRESENCE_CAR7                     127
#define PRESENCE_CHA0                     254
#define PRESENCE_CHA1                     253
#define PRESENCE_CHA2                     251
#define PRESENCE_CHA3                     247
#define PRESENCE_CHA4                     239
#define PRESENCE_CHA5                     223
#define PRESENCE_CHA6                     191
#define PRESENCE_CHA7                     127
#define PRESS_CLIM_CONFIG_0               254
#define PRESS_CLIM_CONFIG_3               247
#define TUNCFG_ALTCLAS_12_CF              4
#define TUNCFG_ALTCLAS_15_CF              5
#define TUNCFG_ALTCLAS_7_CF               7
#define TUNCFG_ALTCLAS_8_CF               2

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

extern const boolean  Cf_bPresPAirExtSens_C;
extern const boolean  Cf_bSecBrkPedPrss_C;
extern const boolean  Cf_bSecBrkPedPrssDiag_C;
extern const boolean  Ctrl_bSelWgCmdSpCf_C;
extern const boolean  Ctrl_bTraNoTarGear_C;
extern const boolean  EcuSt_bAcvRcdMod_EcuMng_C;
extern const boolean  Ext_bACCf_C;
extern const boolean  Ext_bArchiCf_C;
extern const boolean  Ext_bASECf_C;
extern const boolean  Ext_bBrkAutoCf_C;
extern const boolean  Ext_bBrkDiagRelbCf_C;
extern const boolean  Ext_bBrkMainInfoCf_C;
extern const boolean  Ext_bCabHeatDCT_C;
extern const boolean  Ext_bCf_nAvrFrntWhl_C;
extern const boolean  Ext_bCoReqVehCf_bEngStrtReq_C;
extern const boolean  Ext_bCtlCmdPTTqCf_C;
extern const boolean  Ext_bDAE_DAEHCf_C;
extern const boolean  Ext_bDetLoWhlGripCf_C;
extern const boolean  Ext_bDftLogCf_C;
extern const boolean  Ext_bEgrCf_C;
extern const boolean  Ext_bElASRESPCf_C;
extern const boolean  Ext_bEngTrbMode_C;
extern const boolean  Ext_bFanDiagCf_C;
extern const boolean  Ext_bFilCf_spdVehAvrFrntWhl_C;
extern const boolean  Ext_bG3G4Cf_C;
extern const boolean  Ext_bLowFuelLevelSel_C;
extern const boolean  Ext_bOilLvlCf_C;
extern const boolean  Ext_bPACKDYNCf_C;
extern const boolean  Ext_bPresEGRVlv_C;
extern const boolean  Ext_bPresExCmSen_C;
extern const boolean  Ext_bPresGaz_C;
extern const boolean  Ext_bPresInCmSen_C;
extern const boolean  Ext_bReadBrkParkCf_C;
extern const boolean  Ext_bSpdCf_C;
extern const boolean  Ext_bStrtDrvIfTypCf_C;
extern const boolean  Ext_bSTTCf_C;
extern const boolean  Ext_bTqWhlBrkCf_C;
extern const boolean  Ext_bTTCf_C;
extern const boolean  Ext_bTyreWarnCf_C;
extern const boolean  Ext_bVSMaxfCf_C;
extern const boolean  Ext_bVSMaxsCf_C;
extern const boolean  Ext_stDirMoveVehCf_C;
extern const boolean  TunCfg_bva_kickdown_C;
extern const boolean  TunCfg_bvmp_kickdown_C;
extern const uint8  Calibration_gestion[CALIBRATION_GESTION_COLS];
extern const uint8  Calibration_reference[CALIBRATION_REFERENCE_COLS];
extern const uint8  Ext_stBattTypCf_C;
extern const uint8  Ext_stCtlCmdPTTqPot_C;
extern const uint8  Ext_stDrivAltMgt_Cf_C;
extern const uint8  Ext_stECUTypCf_C;
extern const uint8  Ext_stElEMgtCf_C;
extern const uint8  Ext_stEOBDCf_C;
extern const uint8  Ext_stFuTypCf_C;
extern const uint8  Ext_stOilPresCf_C;
extern const uint8  Ext_stOilTCf_C;
extern const uint8  Ext_stPTCf_C;
extern const uint8  Ext_stStaCf_C;
extern const uint8  Ext_stStgPmpCf_C;
extern const uint8  Ext_stStrtRstrtDevCf_C;
extern const uint8  Ext_stTypInjSysCf_C;
extern const uint8  Ext_stUcapTypCf_C;
extern const uint8  Ext_stVSCtlRegCf_C;
extern const uint8  Ext_stVSSCf_C;
extern const uint16  Ext_facRatTqAltCf_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Abs_mux;
extern boolean Amvar_present;
extern boolean Cf_bPresPAirExtSens;
extern boolean Cf_bSecBrkPedPrssDiag;
extern boolean Cl_config_pression_refri_0;
extern boolean Cl_config_pression_refri_3;
extern boolean CoSTT_bAcv;
extern boolean Ctrl_bSelWgCmdSpCf;
extern boolean Ctrl_bTraNoTarGear;
extern boolean Da_present;
extern boolean EcuSt_bAcvRcdMod_EcuMng;
extern boolean Esp_present;
extern boolean Ext_bBlowBy1Cf;
extern boolean Ext_bBPGACf;
extern boolean Ext_bBrkDiagRelbCf;
extern boolean Ext_bBrkMainInfoCf;
extern boolean Ext_bBrkParkCf;
extern boolean Ext_bCf_nAvrFrntWhl;
extern boolean Ext_bDAE_DAEHCf;
extern boolean Ext_bDftLogCf;
extern boolean Ext_bEasyMoveCf;
extern boolean Ext_bEgrCf;
extern boolean Ext_bElASRESPCf;
extern boolean Ext_bEngTrbMode;
extern boolean Ext_bEPBCf;
extern boolean Ext_bFanDiagCf;
extern boolean Ext_bFilCf_spdVehAvrFrntWhl;
extern boolean Ext_bG3G4Cf;
extern boolean Ext_bLowFuelLevelSel;
extern boolean Ext_bOilLvlCf;
extern boolean Ext_bPACKDYNCf;
extern boolean Ext_bPresEGRVlv;
extern boolean Ext_bReadBrkParkCf;
extern boolean Ext_bSpdCf;
extern boolean Ext_bStrtDrvIfCf;
extern boolean Ext_bStrtDrvIfTypCf;
extern boolean Ext_bTTCf;
extern boolean Ext_bVSRegCf;
extern boolean Presence_bva;
extern boolean Presence_bvmp;
extern uint8 Ext_stAltClasVarCf;
extern uint8 Ext_stBodyCf;
extern uint8 Ext_stCabHeatCf;
extern uint8 Ext_stCabHeatVarCf;
extern uint8 Ext_stCfFan;
extern uint8 Ext_stDrivAltMgt_Cf;
extern uint8 Ext_stECUTypCf;
extern uint8 Ext_stElEMgtCf;
extern uint8 Ext_stEOBDCf;
extern uint8 Ext_stOilPresCf;
extern uint8 Ext_stOilTCf;
extern uint8 Ext_stStrtRstrtDevCf;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cf_EveRst_TunCfg(void);
void Cf_EveTele_TunCfg(void);
void Cf_SdlSlow_TunCfg(void);


#endif /* TUNCFG_H */

/*-------------------------------- end of file -------------------------------*/
