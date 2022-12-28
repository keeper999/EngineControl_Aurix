/***************************************************************************
;**
;** FILE NAME      : VEHSPDDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHSPDDIAG_H
#define VEHSPDDIAG_H

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

extern const boolean  VehSpd_bInhMonVehSpd_C;
extern const uint8  VehSpd_nDecCpt_SpdVeh_C;
extern const uint8  VehSpd_nDownTranThd_SpdVeh_C;
extern const uint8  VehSpd_nInitCptConf_SpdVeh_C;
extern const uint8  VehSpd_noEngSpdMaxMesPoint_C;
extern const uint8  VehSpd_noIdcReqMaxMesPoint_C;
extern const uint8  VehSpd_nUpTranThd_SpdVeh_C;
extern const uint8  VehSpd_spdThdDiagCoh_C;
extern const uint16  VehSpd_nEngThdGrd_C;
extern const uint16  VehSpd_nEngThdMax_C;
extern const uint16  VehSpd_nEngThdMin_C;
extern const uint16  VehSpd_spdVehThdMax_C;
extern const uint16  VehSpd_tqIdcReqGrd_C;
extern const uint16  VehSpd_tqIdcReqThdMax_C;
extern const uint16  VehSpd_tqIdcReqThdMin_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VehSpd_bDftSftyORng_spdVeh;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VehSpd_EveRst_MonVehSpd(void);
void VehSpd_SdlMid_MonVehSpd(void);
void VehSpd_SdlSfty_MonVehSpd(void);
void VEHSPDDIAG_vidSafetyLev2(void);


#endif /* VEHSPDDIAG_H */

/*-------------------------------- end of file -------------------------------*/
