/***************************************************************************
;**
;** FILE NAME      : RBLCRITZONE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RBLCRITZONE_H
#define RBLCRITZONE_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNKTREAT_RAIRLDACVRBLDET_M_LNS        ( 16 )
#define KNKTREAT_RAIRLDACVRBLDET_M_COLS        ( 9 )

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

extern const uint8  KnkTreat_rAirLdAcvRblDet_M[KNKTREAT_RAIRLDACVRBLDET_M_LNS][KNKTREAT_RAIRLDACVRBLDET_M_COLS];
extern const sint16  KnkTreat_tCoAcvRblDet_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Zone_critique_Rbl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveBDC_RblCritZone(void);
void KnkTreat_EveCrTR_RblCritZone(void);
void KnkTreat_EveRst_RblCritZone(void);
void KnkTreat_EveRTCr_RblCritZone(void);


#endif /* RBLCRITZONE_H */

/*-------------------------------- end of file -------------------------------*/
