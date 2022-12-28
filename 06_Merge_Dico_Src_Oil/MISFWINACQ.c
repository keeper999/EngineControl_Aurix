/***************************************************************************
;**
;** FILE NAME      : MISFWINACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFWINACQ.H"
#include "MISFWINACQ_L.H"
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
const uint8  Misf_win_nbr_c = 0;
const uint8  MISFWINACQ_u8Inhib = 0;
const uint16  MF_N_MIN_ACQ = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Misf_bAcqActive;
boolean Misf_bAcqActive_prev;
boolean Misf_bAcqWinOK;
uint32 Misf_tiDlyBdcWin;
uint32 Misf_tiDlyBdcWinLdb;
uint32 Misf_tiDlyExpWin;
uint32 Misf_tiDlyExpWinLdb;
uint32 Misf_tiDlyLongWin;
uint32 Misf_tiDlyLongWinLdb;
uint32 Misf_tiDlyTDCWin;
uint32 Misf_tiDlyTDCWinLdb;
uint8 Misf_cntWinAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

