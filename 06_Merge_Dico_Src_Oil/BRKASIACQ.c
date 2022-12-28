/***************************************************************************
;**
;** FILE NAME      : BRKASIACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "BRKASIACQ.H"
#include "BRKASIACQ_L.H"
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
const uint8  AirPres_nDecCpt_ScgBrkAsi_C = 0;
const uint8  AirPres_nDecCpt_ScpBrkAsi_C = 0;
const uint8  AirPres_nDownTranThd_ScgBrkAsi_C = 0;
const uint8  AirPres_nDownTranThd_ScpBrkAsi_C = 0;
const uint8  AirPres_nInitCptConf_ScgBrkAsi_C = 0;
const uint8  AirPres_nInitCptConf_ScpBrkAsi_C = 0;
const uint8  AirPres_nUpTranThd_ScgBrkAsi_C = 0;
const uint8  AirPres_nUpTranThd_ScpBrkAsi_C = 0;
const uint8  BRKASIACQ_u8Inhib = 0;
const uint8  Ext_tDlyDgoGrd_pBrkAsi_C = 0;
const uint16  Ext_pBrkAsiFault_C = 0;
const uint16  Ext_pBrkAsiGain_C = 0;
const uint16  Ext_pBrkAsiInit_C = 0;
const uint16  Ext_pBrkAsiMaxSat_C = 0;
const uint16  Ext_pBrkAsiMinSat_C = 0;
const uint16  Ext_rBrkAsiInit_C = 0;
const uint16  Ext_rDgoGrd_pBrkAsi_C = 0;
const uint16  Ext_rDgoScg_pBrkAsi_C = 0;
const uint16  Ext_rDgoScp_pBrkAsi_C = 0;
const uint16  Ext_uBrkAsiInit_C = 0;
const uint16  Mvc_pressure_sensor_gain = 0;
const uint16  Mvc_pressure_sensor_offset = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirPres_bDftSftyScg_pBrkAsi;
boolean AirPres_bDftSftyScp_pBrkAsi;
boolean BRKASIACQ_bFilSig_1;
boolean BRKASIACQ_bFilSig_2;
boolean BRKASIACQ_bScgrpBrkAsi;
boolean BRKASIACQ_bScprpBrkAsi;
boolean Ext_bDgoGrd_pBrkAsi;
boolean Ext_bDgoScg_pBrkAsi;
boolean Ext_bDgoScp_pBrkAsi;
boolean Ext_bMonRunGrd_pBrkAsi;
boolean Ext_bMonRunScg_pBrkAsi;
boolean Ext_bMonRunScp_pBrkAsi;
uint32 BRKASIACQ_u32ExtBrkAsiMem;
uint8 AirPres_ctDftSftyScg_pBrkAsi;
uint8 AirPres_ctDftSftyScp_pBrkAsi;
uint8 BRKASIACQ_u8CntFilt_1;
uint8 BRKASIACQ_u8CntFilt_2;
uint8 Ext_tDlyDgoGrd_pBrkAsi;
uint16 BRKASIACQ_u16ExtRBrkAsiPrev;
uint16 Ext_pBrkAsiMes;
uint16 Ext_pBrkAsiRaw;
uint16 Ext_pbrkAsiSat;
uint16 Ext_rBrkAsi;
uint16 Ext_uBrkAsi;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

