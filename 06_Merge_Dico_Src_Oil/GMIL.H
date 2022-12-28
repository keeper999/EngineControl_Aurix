/***************************************************************************
;**
;** FILE NAME      : GMIL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GMIL_H
#define GMIL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GMIL_KM_HECT                      10
#define GMIL_MIN_SEC                      60
#define UINT16_MAX_VALUE                  65535

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st81 */
#define MIL_OFF                           0
#define MIL_ON                            1
#define MIL_BLINK                         2
/*extern uint8 GMIL_stMILReq;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  GMIL_bInhMilRst_C;
extern const uint8  GMIL_tiMilOnMin_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 GMIL_stMILReq;
extern boolean GMIL_bDftMilBlink;
extern boolean GMIL_bMilBlink;
extern boolean GMIL_bMilDftPres;
extern boolean GMIL_bMilOn;
extern boolean GMIL_bWarnSt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GMIL_vidMngEveKeyOBD(void);
void GMIL_vidMngEveRst(void);
void GMIL_vidMngEveSldSlow(void);


#endif /* GMIL_H */

/*-------------------------------- end of file -------------------------------*/
