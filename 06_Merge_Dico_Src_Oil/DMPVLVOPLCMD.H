/***************************************************************************
;**
;** FILE NAME      : DMPVLVOPLCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DMPVLVOPLCMD_H
#define DMPVLVOPLCMD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DMPVLVACT_ROPLCMD_NENG_A_COLS          ( 16 )
#define DMPVLVACT_ROPLCMD_PERRSPG_A_COLS       ( 16 )
#define DMPVLVACT_ROPLCMD_PERRSPG_NENG_M_LNS  ( 16 )
#define DMPVLVACT_ROPLCMD_PERRSPG_NENG_M_COLS  ( 16 )

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

extern const boolean  DmpVlvAct_bDmpVlvOplCmdEna_C;
extern const boolean  DmpVlvAct_bOplCmdMapSel_C;
extern const uint8  DmpVlvOplCmd_u8Inhib;
extern const uint16  DmpVlvAct_max_pres_slew_C;
extern const uint16  DmpVlvAct_min_pres_slew_C;
extern const uint16  DmpVlvAct_rDmpVlvOplCmdSpIni_C;
extern const uint16  DmpVlvAct_rOplCmd_nEng_A[DMPVLVACT_ROPLCMD_NENG_A_COLS];
extern const uint16  DmpVlvAct_rOplCmd_pErrSpg_A[DMPVLVACT_ROPLCMD_PERRSPG_A_COLS];
extern const uint16  DmpVlvAct_rOplCmd_pErrSpg_nEng_M[DMPVLVACT_ROPLCMD_PERRSPG_NENG_M_LNS][DMPVLVACT_ROPLCMD_PERRSPG_NENG_M_COLS];
extern const uint16  DmpVlvAct_rOplCmdSp_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DmpVlvAct_bDmpVlvOplCmdEna;
extern uint16 DmpVlvAct_rDmpVlvOplCmdSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DmpVlvAct_EveRst_DmpVlvOplCmd(void);
void DmpVlvAct_SdlMid_DmpVlvOplCmd(void);


#endif /* DMPVLVOPLCMD_H */

/*-------------------------------- end of file -------------------------------*/
