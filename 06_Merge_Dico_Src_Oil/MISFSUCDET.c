/***************************************************************************
;**
;** FILE NAME      : MISFSUCDET.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFSUCDET.H"
#include "MISFSUCDET_L.H"
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
const uint8  Mf_2_misfire_det_map_uacn2[MF_2_MISFIRE_DET_MAP_UACN2_LNS][MF_2_MISFIRE_DET_MAP_UACN2_COLS] = {0};
const uint8  Mf_misfire_detected_thresh_uacn0 = 0;
const uint8  MISFSUCDET_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Mf_2_misfire_detected_uavb0;
boolean Mf_2_misfire_norm_detected_uavb0;
boolean Mf_misfire1_detected_uavb0;
boolean Mf_misfire2_detected_uavb0;
boolean MISFSUCDET_bEnablePrev;
sint16 Mf_comb1_algo_out_corr_uavn0;
sint16 Mf_comb1_algo_trust_uavn0;
sint16 Mf_comb2_algo_out_corr_uavn0;
sint16 Mf_comb2_algo_trust_uavn0;
sint16 Mf_p_filt1_algo_out_uavn0;
sint16 Mf_p_filt1_algo_trust_uavn0;
sint16 Mf_p_filt2_algo_out_uavn0;
sint16 Mf_p_filt2_algo_trust_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

