/***************************************************************************
;**
;** FILE NAME      : KEYPUSHINFO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KEYPUSHINFO_L_H
#define KEYPUSHINFO_L_H

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

extern const uint8  KEYPUSHINFO_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bKeyLine;
extern boolean Ext_bPushLine;
extern uint8 Ext_ctSdl;
extern uint8 KEYPUSHINFO_u8AntiBounceCntKey;
extern uint8 KEYPUSHINFO_u8AntiBounceCntPush;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KEYPUSHINFO_vidEventSelc(void);
void KEYPUSHINFO_vidInit(void);
void KEYPUSHINFO_vidInitOutput(void);
void KEYPUSHINFO_vidKeyFunct(void);
void KEYPUSHINFO_vidKeyPushAcq(void);
void KEYPUSHINFO_vidKeyPushTreat(void);
void KEYPUSHINFO_vidPushFunct(void);


#endif /* KEYPUSHINFO_L_H */

/*-------------------------------- end of file -------------------------------*/
