/***************************************************************************
;**
;** FILE NAME      : MISFDETCFM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFDETCFM.H"
#include "MISFDETCFM_L.H"
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
const uint8  Mf_p_filt_dec_neut_map_uacn2[MF_P_FILT_DEC_NEUT_MAP_UACN2_LNS][MF_P_FILT_DEC_NEUT_MAP_UACN2_COLS] = {0};
const uint8  Mf_p_filt_decision_map_uacn2[MF_P_FILT_DECISION_MAP_UACN2_LNS][MF_P_FILT_DECISION_MAP_UACN2_COLS] = {0};
const uint8  MISFDETCFM_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Mf_misfire_detected_uavb0;
uint8 Mf_det_single_output_uavn0;
sint16 Mf_comb_wght_uavn0;
sint16 Mf_p_filt_wght_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

