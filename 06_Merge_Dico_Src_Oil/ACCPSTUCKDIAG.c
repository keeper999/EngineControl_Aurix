/***************************************************************************
;**
;** FILE NAME      : ACCPSTUCKDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPSTUCKDIAG.H"
#include "ACCPSTUCKDIAG_L.H"
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
const uint8  ACCPSTUCKDIAG_u8Inhib = 0;
const uint16  Aps_lck_n_hyst = 0;
const uint16  Aps_lck_n_min_thresh = 0;
const uint16  Aps_lck_pdl_pos_delta = 0;
const uint16  Aps_lck_pdl_pos_devalid_delta = 0;
const uint16  Aps_lck_pdl_pos_hyst = 0;
const uint16  Aps_lck_pdl_pos_min_thresh = 0;
const uint16  Aps_lck_vs_hyst = 0;
const uint16  Aps_lck_vs_min_thresh = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 ACCPSTUCKDIAG_stDiag;
boolean AccP_bDgoStuckAccP;
boolean AccP_bMonRunStuckAccP;
boolean ACCPSTUCKDIAG_bRstDgo;
boolean ACCPSTUCKDIAG_bSetDgo;
boolean Aps_lck_brk_pdl_in;
boolean Aps_lck_brk_pdl_in_prev;
uint16 ACCPSTUCKDIAG_u16SsmPrPedPosPrev;
uint16 Aps_lck_pdl_pos_fix;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

