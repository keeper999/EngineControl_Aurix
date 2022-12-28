/***************************************************************************
;**
;** FILE NAME      : DRVRSENO2US.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DRVRSENO2US.H"
#include "DRVRSENO2US_L.H"
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
const uint8  DRVRSENO2US_u8Inhib = 0;
const uint16  Ichauff_min_SenO2Us = 0;
const uint16  Lshd_max_voltage_diag_thresh = 0;
const uint16  Lshd_min_voltage_diag_thresh = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean DRVRSENO2US_bDiagEnable;
boolean Ext_bDgoHi_DrvrSenO2Us;
boolean Ext_bDgoLo_DrvrSenO2Us;
boolean Ext_bMonRunHi_DrvrSenO2Us;
boolean Ext_bMonRunLo_DrvrSenO2Us;
boolean M_diag_chauffage_amont;
uint8 DRVRSENO2US_u8SdlDiagCall;
uint16 Ext_uEcuUsMes;
uint16 Ichauff_SO2Us;
uint16 LsMon_resLsUsHeat;
uint16 Rchauff_SO2Us;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

