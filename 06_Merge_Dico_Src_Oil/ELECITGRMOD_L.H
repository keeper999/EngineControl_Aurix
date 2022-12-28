/***************************************************************************
;**
;** FILE NAME      : ELECITGRMOD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ELECITGRMOD_L_H
#define ELECITGRMOD_L_H

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

extern const uint8  ELECITGRMOD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DIAGCAN_bInhibition_defauts;
extern uint8 DIAGCAN_tiF092Out_ClearDTC;
extern uint8 DIAGCAN_tiF092Out_InteElec;
extern uint8 DIAGCAN_u8Command_InteElec_prev;
extern uint8 DIAGCAN_u8IntElecAftrRstWaitCnt;
extern uint8 DIAGCAN_u8Nb_trame_ClearDTC_rec;
extern uint8 DIAGCAN_u8Nb_trame_InteElec_rec;
extern uint8 Ext_tiHldIntModeExitMainWku;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ELECITGRMOD_vidEntryIntElec(void);
void ELECITGRMOD_vidExitIntElec(void);
void ELECITGRMOD_vidIntegElectronic(void);
void ELECITGRMOD_vidIntElecCondCheck(void);
void ELECITGRMOD_vidIntElecInit(void);


#endif /* ELECITGRMOD_L_H */

/*-------------------------------- end of file -------------------------------*/
