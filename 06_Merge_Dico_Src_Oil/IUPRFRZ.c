/***************************************************************************
;**
;** FILE NAME      : IUPRFRZ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IUPRFRZ.H"
#include "IUPRFRZ_L.H"
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
const uint8  IUPRFRZ_u8Inhib = 0;
const uint16  Iupr_idxFrzCntObdStrt_T[IUPR_IDXFRZCNTOBDSTRT_T_COLS] = {0};
const uint16  Iupr_idxFrzGenDen_T[IUPR_IDXFRZGENDEN_T_COLS] = {0};
const uint16  Iupr_idxFrzRat_T[IUPR_IDXFRZRAT_T_LNS][IUPR_IDXFRZRAT_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Iupr_bFrzCntObdStrt;
boolean Iupr_bFrzGenDen;
boolean Iupr_bFrzRat[IUPR_BFRZRAT_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

