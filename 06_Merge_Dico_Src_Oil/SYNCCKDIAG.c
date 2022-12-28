/***************************************************************************
;**
;** FILE NAME      : SYNCCKDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SYNCCKDIAG.H"
#include "SYNCCKDIAG_L.H"
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
const boolean  Acq_crk_no_gap_diag_ena_upcb0 = 0;
const boolean  Acq_crk_tooth_h_diag_ena_upcb0 = 0;
const boolean  Acq_crk_tooth_l_diag_ena_upcb0 = 0;
const boolean  Sync_bAcvBackUpCk_C = 0;
const boolean  Sync_bAcvBchModCk_C = 0;
const uint8  SYNCCKDIAG_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
boolean Acq_crk_long_tooth_nok_upd_upvb0;
boolean Acq_crk_long_tooth_nok_upvb0;
boolean Acq_crk_no_gap_cond_dec_upvb0;
boolean Acq_crk_no_gap_cond_inc_upvb0;
boolean Acq_crk_no_long_tooth_upd_upvb0;
boolean Acq_crk_no_long_tooth_upvb0;
boolean Acq_crk_tooth_less_upd_upvb0;
boolean Acq_crk_tooth_less_upvb0;
boolean Acq_crk_tooth_more_upd_upvb0;
boolean Acq_crk_tooth_more_upvb0;
boolean Sync_bForcDwgMode;
boolean SYNCCKDIAG_bDgoCkSigPrev;
boolean SYNCCKDIAG_bSelectCkMode;
uint8 Sync_stCkMode;
uint8 Sync_stCkModeRead;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

