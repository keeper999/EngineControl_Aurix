/***************************************************************************
;**
;** FILE NAME      : CSTRCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CSTRCMD.H"
#include "CSTRCMD_L.H"
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
const boolean  Ext_bAcv_Cnstr_rCtlBattCor_C = 0;
const uint8  Cstr_CtlCstrReq_DrvMax_C = 0;
const uint8  Cstr_CtlCstrReq_DrvMin_C = 0;
const uint8  CSTRCMD_u8Inhib = 0;
const uint8  rco_second_frequency_max = 0;
const uint8  rco_second_frequency_max_hys = 0;
const uint8  rco_second_frequency_min = 0;
const uint8  rco_second_frequency_min_hys = 0;
const uint16  Bsi_pwm_frequency_hi_cpc = 0;
const uint16  Bsi_pwm_frequency_lo_cpc = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Cstr_bDgoHiCstrDrv;
boolean Cstr_bDgoLoCstrDrv;
boolean Cstr_bMonRunHiCstrDrv;
boolean Cstr_bMonRunLoCstrDrv;
boolean CSTRCMD_bMaxHysOut;
boolean CSTRCMD_bMinHysOut;
uint8 Rco_applique_purge_corr;
uint8 Rco_applique_purge_final;
sint16 CSTRCMD_s16ExtuBattMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

