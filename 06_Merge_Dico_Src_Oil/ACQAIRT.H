/***************************************************************************
;**
;** FILE NAME      : ACQAIRT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQAIRT_H
#define ACQAIRT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AirT_SampleTiMid_SC               100
#define TABLE_TEMPERATURE_AIR_LINEARISEE_COLS  ( 33 )
#define TEMP_AIR_RESULT_AD_CONV_BKPT_MAP_COLS  ( 33 )

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

extern const uint8  Temp_air_diag_grad_delay;
extern const uint8  Temp_air_grad_thresh;
extern const uint8  Temp_air_par_defaut;
extern const uint8  Temperature_air_slew_rate;
extern const uint16  Table_temperature_air_linearisee[TABLE_TEMPERATURE_AIR_LINEARISEE_COLS];
extern const uint16  Temp_air_result_ad_conv_bkpt_map[TEMP_AIR_RESULT_AD_CONV_BKPT_MAP_COLS];
extern const uint16  Tension_air_seuil_cc0;
extern const uint16  Tension_air_seuil_cc1;
extern const uint16  Tension_air_seuil_co;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Temperature_air_mesuree;
extern sint16 Ext_tDsThrStrtMes;
extern uint16 Temperature_air_result_ad_conv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirT_EveCrTR_AcqAirT(void);
void AirT_EveRst_AcqAirT(void);
void AirT_SdlMid_AcqAirT(void);


#endif /* ACQAIRT_H */

/*-------------------------------- end of file -------------------------------*/
