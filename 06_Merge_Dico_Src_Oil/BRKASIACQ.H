/***************************************************************************
;**
;** FILE NAME      : BRKASIACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BRKASIACQ_H
#define BRKASIACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  AirPres_nDecCpt_ScgBrkAsi_C;
extern const uint8  AirPres_nDecCpt_ScpBrkAsi_C;
extern const uint8  AirPres_nDownTranThd_ScgBrkAsi_C;
extern const uint8  AirPres_nDownTranThd_ScpBrkAsi_C;
extern const uint8  AirPres_nInitCptConf_ScgBrkAsi_C;
extern const uint8  AirPres_nInitCptConf_ScpBrkAsi_C;
extern const uint8  AirPres_nUpTranThd_ScgBrkAsi_C;
extern const uint8  AirPres_nUpTranThd_ScpBrkAsi_C;
extern const uint8  Ext_tDlyDgoGrd_pBrkAsi_C;
extern const uint16  Ext_pBrkAsiFault_C;
extern const uint16  Ext_pBrkAsiGain_C;
extern const uint16  Ext_pBrkAsiInit_C;
extern const uint16  Ext_pBrkAsiMaxSat_C;
extern const uint16  Ext_pBrkAsiMinSat_C;
extern const uint16  Ext_rBrkAsiInit_C;
extern const uint16  Ext_rDgoGrd_pBrkAsi_C;
extern const uint16  Ext_rDgoScg_pBrkAsi_C;
extern const uint16  Ext_rDgoScp_pBrkAsi_C;
extern const uint16  Ext_uBrkAsiInit_C;
extern const uint16  Mvc_pressure_sensor_gain;
extern const uint16  Mvc_pressure_sensor_offset;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirPres_bDftSftyScg_pBrkAsi;
extern boolean AirPres_bDftSftyScp_pBrkAsi;
extern uint16 Ext_pBrkAsiMes;
extern uint16 Ext_rBrkAsi;
extern uint16 Ext_uBrkAsi;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirPres_EveRst_BrkAsiAcq(void);
void AirPres_SdlFast_BrkAsiAcq(void);
void AirPres_SdlSfty_BrkAsiAcq(void);


#endif /* BRKASIACQ_H */

/*-------------------------------- end of file -------------------------------*/
