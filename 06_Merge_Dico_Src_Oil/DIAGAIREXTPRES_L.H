/***************************************************************************
;**
;** FILE NAME      : DIAGAIREXTPRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DIAGAIREXTPRES_L_H
#define DIAGAIREXTPRES_L_H

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

extern const uint8  DIAGAIREXTPRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirPres_bDgoGrd_pAirExt;
extern boolean AirPres_bDgoGrd_pAirExtOld;
extern boolean AirPres_bDgoMax_pAirExt;
extern boolean AirPres_bDgoMin_pAirExt;
extern boolean AirPres_bEnaClcGrdExtAirPres;
extern boolean AirPres_bMonRunGrd_pAirExt;
extern boolean AirPres_bMonRunGrd_pAirExtOld;
extern boolean AirPres_bMonRunMax_pAirExt;
extern boolean AirPres_bMonRunMin_pAirExt;
extern boolean AirPres_bPresAirExtKOnMem;
extern boolean DIAGAIREXTPRES_bExtKOnMemPrev;
extern boolean DIAGAIREXTPRES_bTimeout;
extern uint16 AirPres_ctTiDlyGrd_pAirExt;
extern uint16 AirPres_pAirExtGrd;
extern uint16 AirPres_pAirExtGrdOld;
extern uint16 AirPres_pAirExtMemDly;
extern uint16 AirPres_pAirExtRefOld;
extern uint16 AirPres_pAirExtStrtPresSens;
extern uint16 DIAGAIREXTPRES_u16OutPutSwitch2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DIAGAIREXTPRES_vidCdnAirPresOld(void);
void DIAGAIREXTPRES_vidCdnChgAirPres(void);
void DIAGAIREXTPRES_vidCdnCohAirPres(void);
void DIAGAIREXTPRES_vidChgCohAirPres(void);
void DIAGAIREXTPRES_vidClcGrdAirPres(void);
void DIAGAIREXTPRES_vidCohAirExtPres(void);
void DIAGAIREXTPRES_vidCohAirPresOld(void);
void DIAGAIREXTPRES_vidDiaAirExtPrsIn(void);
void DIAGAIREXTPRES_vidDiagAirExtPres(void);
void DIAGAIREXTPRES_vidInitOutput(void);
void DIAGAIREXTPRES_vidMemAirExtPres(void);
void DIAGAIREXTPRES_vidMemBeforeWr(void);


#endif /* DIAGAIREXTPRES_L_H */

/*-------------------------------- end of file -------------------------------*/
