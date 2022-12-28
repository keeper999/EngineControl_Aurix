/***************************************************************************
;**
;** FILE NAME      : MISFWINACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFWINACQ_H
#define MISFWINACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  Misf_win_nbr_c;
extern const uint16  MF_N_MIN_ACQ;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Misf_bAcqWinOK;
extern uint32 Misf_tiDlyBdcWin;
extern uint32 Misf_tiDlyExpWin;
extern uint32 Misf_tiDlyLongWin;
extern uint32 Misf_tiDlyTDCWin;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveCkSnOf_MisfWinAcq(void);
void Misf_EveCkSnOn_MisfWinAcq(void);
void Misf_EveMisf_MisfWinAcq(void);
void Misf_EveRst_MisfWinAcq(void);
void Misf_SdlFast_MisfWinAcq(void);


#endif /* MISFWINACQ_H */

/*-------------------------------- end of file -------------------------------*/
