/***************************************************************************
;**
;** FILE NAME      : CONFIGLIN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CONFIGLIN_L_H
#define CONFIGLIN_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CONFIGLIN_u8C_MAX                 255
#define CONFIGLIN_U8CNT_PREV_COLS              ( 3 )
#define CONFIGLIN_u8RX_BUFFER_LENGTH      2

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

extern const uint8  CONFIGLIN_u8DecAlt1Absent;
extern const uint8  CONFIGLIN_u8DecAlt2Absent;
extern const uint8  CONFIGLIN_u8DecAltAbsent;
extern const uint8  CONFIGLIN_u8DecEcmMute;
extern const uint8  CONFIGLIN_u8IncAlt1Absent;
extern const uint8  CONFIGLIN_u8IncAlt2Absent;
extern const uint8  CONFIGLIN_u8IncAltAbsent;
extern const uint8  CONFIGLIN_u8IncEcmMute;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CONFIGLIN_bDgoAltAbsent;
extern boolean CONFIGLIN_bDgoLinBlocked;
extern boolean CONFIGLIN_bMonRun;
extern uint8 CONFIGLIN_u8AltCnt_prev;
extern uint8 CONFIGLIN_u8AltEcuCnt_prev;
extern uint8 CONFIGLIN_u8Cnt_prev[CONFIGLIN_U8CNT_PREV_COLS];
extern uint8 CONFIGLIN_u8Compteur;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CONFIGLIN_vidDiagAltAbsent(void);
void CONFIGLIN_vidDiagFrame(uint8 u8NodeIndex, uint16 u16DefaultIndex);
void CONFIGLIN_vidDiagLinBlocked(void);
void CONFIGLIN_vidInit(void);
void CONFIGLIN_vidLinScheduler(void);
void CONFIGLIN_vidReInitCondCheck(void);


#endif /* CONFIGLIN_L_H */

/*-------------------------------- end of file -------------------------------*/
