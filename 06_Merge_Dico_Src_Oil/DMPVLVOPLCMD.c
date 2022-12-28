/***************************************************************************
;**
;** FILE NAME      : DMPVLVOPLCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DMPVLVOPLCMD.H"
#include "DMPVLVOPLCMD_L.H"
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
const boolean  DmpVlvAct_bDmpVlvOplCmdEna_C = 0;
const boolean  DmpVlvAct_bOplCmdMapSel_C = 0;
const uint8  DmpVlvOplCmd_u8Inhib = 0;
const uint16  DmpVlvAct_max_pres_slew_C = 0;
const uint16  DmpVlvAct_min_pres_slew_C = 0;
const uint16  DmpVlvAct_rDmpVlvOplCmdSpIni_C = 0;
const uint16  DmpVlvAct_rOplCmd_nEng_A[DMPVLVACT_ROPLCMD_NENG_A_COLS] = {0};
const uint16  DmpVlvAct_rOplCmd_pErrSpg_A[DMPVLVACT_ROPLCMD_PERRSPG_A_COLS] = {0};
const uint16  DmpVlvAct_rOplCmd_pErrSpg_nEng_M[DMPVLVACT_ROPLCMD_PERRSPG_NENG_M_LNS][DMPVLVACT_ROPLCMD_PERRSPG_NENG_M_COLS] = {0};
const uint16  DmpVlvAct_rOplCmdSp_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean DmpVlvAct_bDmpVlvOplCmdEna;
sint16 DmpVlvAct_ErrSpgPress;
uint16 DmpVlvAct_rDmpVlvOplCmdSp;
uint16 DmpVlvAct_rDmpVlvOplCmdSp_Prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

