/***************************************************************************
;**
;** FILE NAME      : ACPRESACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACPRESACQ.H"
#include "ACPRESACQ_L.H"
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
const boolean  Manu_inh_clim = 0;
const uint8  ACPRESACQ_u8Inhib = 0;
const uint8  Cl_pressure_diag_trk_delay = 0;
const sint16  Cl_voltage_pressure_offset = 0;
const uint16  Ac_cooling_max_ratio_value = 0;
const uint16  Ac_cooling_max_tracker_value = 0;
const uint16  Ac_cooling_min_ratio_value = 0;
const uint16  Cl_coeff_filtre_pression_refri = 0;
const uint16  Cl_default_pressure = 0;
const uint16  Cl_voltage_pressure_slope = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ACPRESACQ_bFilteringInit;
boolean Ext_bDgoGrd_pACMes;
boolean Ext_bDgoHi_pACMes;
boolean Ext_bDgoLo_pACMes;
boolean Ext_bMonRunGrd_pACMes;
boolean Ext_bMonRunGrdSng_pACMes;
boolean Ext_bMonRunHi_pACMes;
boolean Ext_bMonRunLo_pACMes;
uint8 Cl_pressure_diag_trk_count;
uint16 Ac_cooling_pressure_trk_delta;
uint16 AC_pACMes;
uint16 Cl_current_pressure;
uint16 Cl_pressure;
uint16 Cl_pressure_result_ad_conv;
uint16 Cl_pressure_result_ratio;
uint16 Cl_raw_pressure;
uint16 Cl_raw_pressure_prec;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

