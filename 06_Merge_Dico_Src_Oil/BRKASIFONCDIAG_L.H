/***************************************************************************
;**
;** FILE NAME      : BRKASIFONCDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BRKASIFONCDIAG_L_H
#define BRKASIFONCDIAG_L_H

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

extern const uint8  BRKASIFONCDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirPres_bDgoCoh_pBrkAsi;
extern boolean AirPres_bMonRunCoh_pBrkAsi;
extern uint16 AirPres_tiCohBrkAsi;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BRKASIFONCDIAG_vidActivateDetect(void);
void BRKASIFONCDIAG_vidInitOutput(void);
void BRKASIFONCDIAG_vidRun(void);


#endif /* BRKASIFONCDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
