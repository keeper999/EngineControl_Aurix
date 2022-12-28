/***************************************************************************
;**
;** FILE NAME      : GOBD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GOBD_H
#define GOBD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "GD_API.h"
#include "GDFRM.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GOBD_ENUSTDGO_LNS                     ( 972 )
#define GOBD_U8CTDC_LNS                       ( 972 )
#define GOBD_U8CTWUC_LNS                      ( 972 )

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

extern const uint8  GOBD_noWUCClr_C;
extern const uint8  GOBD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GOBD_bKeyOBD;
extern GDFRM_tenuGOBDState GOBD_enustDgo[GOBD_ENUSTDGO_LNS];
extern uint8 GOBD_u8ctDC[GOBD_U8CTDC_LNS];
extern uint8 GOBD_u8ctWUC[GOBD_U8CTWUC_LNS];
extern uint16 GOBD_tiSinceEngStrt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GOBD_vidExitEveStObdClear(uint16 u16IdxDft);
void GOBD_vidExitEveStObdRec(uint16 u16IdxDft);
void GOBD_vidMngEveCDThdUp(uint16 u16IdxDft);
void GOBD_vidMngEveDftUnval(uint16 u16IdxDft);
void GOBD_vidMngEveGlbDCStrt(void);
void GOBD_vidMngEveKOf(void);
void GOBD_vidMngEveKOn(void);
void GOBD_vidMngEveRst(void);
void GOBD_vidMngEveRstDft(void);
void GOBD_vidMngEveRstDftCal(void);
void GOBD_vidMngEveRstDftObd(void);
void GOBD_vidMngEveSldSlow(void);
GDFRM_tenuGOBDState GOBD_tenuGetStDgo(uint16 u16IdxDft);


#endif /* GOBD_H */

/*-------------------------------- end of file -------------------------------*/
