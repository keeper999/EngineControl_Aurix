/***************************************************************************
;**
;** FILE NAME      : VEHSPDDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VEHSPDDIAG.H"
#include "VEHSPDDIAG_L.H"
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
const boolean  VehSpd_bInhMonVehSpd_C = 0;
const uint8  VehSpd_nDecCpt_SpdVeh_C = 0;
const uint8  VehSpd_nDownTranThd_SpdVeh_C = 0;
const uint8  VehSpd_nInitCptConf_SpdVeh_C = 0;
const uint8  VehSpd_noEngSpdMaxMesPoint_C = 0;
const uint8  VehSpd_noIdcReqMaxMesPoint_C = 0;
const uint8  VehSpd_nUpTranThd_SpdVeh_C = 0;
const uint8  VehSpd_spdThdDiagCoh_C = 0;
const uint8  VEHSPDDIAG_u8Inhib = 0;
const uint16  VehSpd_nEngThdGrd_C = 0;
const uint16  VehSpd_nEngThdMax_C = 0;
const uint16  VehSpd_nEngThdMin_C = 0;
const uint16  VehSpd_spdVehThdMax_C = 0;
const uint16  VehSpd_tqIdcReqGrd_C = 0;
const uint16  VehSpd_tqIdcReqThdMax_C = 0;
const uint16  VehSpd_tqIdcReqThdMin_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VehSpd_bCnd1Coh_spdVeh;
boolean VehSpd_bCnd2Coh_spdVeh;
boolean VehSpd_bDftSftyORng_spdVeh;
boolean VehSpd_bDgoCoh_spdVeh;
boolean VehSpd_bDgoORng_spdVeh;
boolean VehSpd_bMonRunCoh_spdVeh;
boolean VehSpd_bMonRunORng_spdVeh;
boolean VEHSPDDIAG_bFilSig_1;
boolean VEHSPDDIAG_bORng_spdVeh;
uint8 VehSpd_ctDftSftyORng_spdVeh;
uint8 VehSpd_ctEngSpdMesPoint;
uint8 VehSpd_ctIdcReqMesPoint;
uint8 VEHSPDDIAG_u8CntFilt_1;
sint16 VEHSPDDIAG_TqSys_tqIdcReqPrev;
uint16 VEHSPDDIAG_Regime_moteurPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

