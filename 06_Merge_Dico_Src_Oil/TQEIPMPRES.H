/***************************************************************************
;**
;** FILE NAME      : TQEIPMPRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQEIPMPRES_H
#define TQEIPMPRES_H

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

extern const boolean  TqRes_bAcvElPmpGrpRes_C;
extern const uint8  TqRes_spdThrElPmpGrpRes_C;
extern const uint8  TqRes_tiCdnElPmpGrpRes_C;
extern const sint16  TqRes_tqDecMaxElPmpGrpRes_C;
extern const uint16  TqRes_tqElPmpGrpRes_C;
extern const uint16  TqRes_tqIncMaxElPmpGrpRes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqElPmpGrpRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQEIPMPRES_vidEntry_10ms(void);
void TQEIPMPRES_vidEntryInit(void);


#endif /* TQEIPMPRES_H */

/*-------------------------------- end of file -------------------------------*/
