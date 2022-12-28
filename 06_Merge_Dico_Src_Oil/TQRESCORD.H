/***************************************************************************
;**
;** FILE NAME      : TQRESCORD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQRESCORD_H
#define TQRESCORD_H

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

extern const sint16  TqRes_tqDecMaxCanPurgRes_C;
extern const uint16  TqRes_idxTqResAcvCll_C;
extern const uint16  TqRes_tiValTranCll_C;
extern const uint16  TqRes_tqIncMaxCanPurgRes_C;
extern const uint16  TqRes_tqSatMaxRes_C;
extern const uint16  TqRes_tqThrHiMaxRes_C;
extern const uint16  TqRes_tqThrLoMaxRes_C;
extern const uint16  TqRes_tqValIncCll_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint16 TqRes_tqMaxResnoSat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TqRes_Sdl10ms_tqMaxRes(void);
void TQRESCORD_vidEntryInit(void);


#endif /* TQRESCORD_H */

/*-------------------------------- end of file -------------------------------*/
