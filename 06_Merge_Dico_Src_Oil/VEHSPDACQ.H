/***************************************************************************
;**
;** FILE NAME      : VEHSPDACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHSPDACQ_H
#define VEHSPDACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Dist_fil_sat_SC                   65535000
#define VehSpd_noPlsCalcMean_SC           8

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

extern const boolean  VehSpd_bDeadzone_C;
extern const boolean  VehSpd_bEnaChkBattVolt_C;
extern const uint8  VehSpd_AccMoyIndex_C;
extern const uint8  VehSpd_tiDlyVehStopCmpl_C;
extern const uint16  Acc_AntiRebond_Down_C;
extern const uint16  VehSpd_dstIntlPls_C;
extern const uint16  VehSpd_facAccelFilGain_C;
extern const uint16  VehSpd_facFilterGain_C;
extern const uint16  VehSpd_spdMinForClamp_C;
extern const uint16  VehSpd_spdMinSat_C;
extern const uint16  VehSpd_uBattVoltHiThd_C;
extern const uint16  VehSpd_uBattVoltHysThd_C;
extern const uint16  VehSpd_uBattVoltLoThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Acceleration_filaire;
extern uint16 Distance_parcourue_fil;
extern uint16 Ext_spdVehRaw;
extern uint16 Vitesse_vehicule_fil_precise;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VehSpd_EveRst_AcqVehSpdSen(void);
void VehSpd_EveVSTop_AcqVehSpdSen(void);
void VehSpd_SdlFast_AcqVehSpdSen(void);


#endif /* VEHSPDACQ_H */

/*-------------------------------- end of file -------------------------------*/
