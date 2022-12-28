/***************************************************************************
;**
;** FILE NAME      : MISFDFTLRNOUT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFDFTLRNOUT.H"
#include "MISFDFTLRNOUT_L.H"
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
const uint8  Mfw_adapt_zone_ratio_thresh = 0;
const uint8  MISFDFTLRNOUT_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Mf_adap_lw_corr_count_min[MF_ADAP_LW_CORR_COUNT_MIN_COLS];
uint8 Mf_adap_shrt_corr_count_min[MF_ADAP_SHRT_CORR_COUNT_MIN_COLS];
uint8 Mfw_adapt_current_zone_level;
uint8 Mfw_adapt_zones_ratio;
uint16 Mfw_adapt_current_zone_level_res;
uint16 Mfw_adapt_zones_ratio_res;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

