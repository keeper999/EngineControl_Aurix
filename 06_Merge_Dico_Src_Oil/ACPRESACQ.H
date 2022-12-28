/***************************************************************************
;**
;** FILE NAME      : ACPRESACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACPRESACQ_H
#define ACPRESACQ_H

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

extern const boolean  Manu_inh_clim;
extern const uint8  Cl_pressure_diag_trk_delay;
extern const sint16  Cl_voltage_pressure_offset;
extern const uint16  Ac_cooling_max_ratio_value;
extern const uint16  Ac_cooling_max_tracker_value;
extern const uint16  Ac_cooling_min_ratio_value;
extern const uint16  Cl_coeff_filtre_pression_refri;
extern const uint16  Cl_default_pressure;
extern const uint16  Cl_voltage_pressure_slope;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 AC_pACMes;
extern uint16 Cl_pressure;
extern uint16 Cl_pressure_result_ad_conv;
extern uint16 Cl_raw_pressure;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AC_EveRst_ACPresAcq(void);
void AC_SdlFast_ACPresAcq(void);
void AC_SdlMid_ACPresAcq(void);


#endif /* ACPRESACQ_H */

/*-------------------------------- end of file -------------------------------*/
