/***************************************************************************
;**
;** FILE NAME      : ACCPFRM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPFRM.H"
#include "ACCPFRM_L.H"
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
const boolean  Accp_bAcvModPedalWotRequest = 0;
const boolean  Accp_bInhModPosnPedRel = 0;
const boolean  Aps_mux_pl_securise_manu_inh = 0;
const boolean  Ssm_mux_dv_pos_pedal_ff_manu_inh = 0;
const uint8  ACCPFRM_u8Inhib = 0;
const uint8  Dv_detect_pl_high_thresh_mux = 0;
const uint8  Dv_detect_pl_low_thresh_mux = 0;
const uint16  AccP_rAccPPHdPt_C = 0;
const uint16  Aps_detect_pl_mux_coh_tolerance = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ACCPFRM_bHystPosPedOut;
uint8 AccP_rDrvReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

