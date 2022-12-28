/***************************************************************************
;**
;** FILE NAME      : ACCPEM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPEM_H
#define ACCPEM_H

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

extern const boolean  AccP_bCycPosPedClc_C;
extern const boolean  AccP_bInhDiagCoh_C;
extern const uint8  AccP_tiInhCohTest_C;
extern const uint16  AccPEM_rPosPedCohThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AccP_bDftElAccP;
extern uint8 AccPEM_rAccP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AccP_EveKOf_AccPEM(void);
void AccP_EveRst_AccPEM(void);
void AccP_SdlFast_AccPEM(void);


#endif /* ACCPEM_H */

/*-------------------------------- end of file -------------------------------*/
