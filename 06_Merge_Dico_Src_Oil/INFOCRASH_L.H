/***************************************************************************
;**
;** FILE NAME      : INFOCRASH_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INFOCRASH_L_H
#define INFOCRASH_L_H

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

extern const uint8  INFOCRASH_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoDft_Info_Crash;
extern boolean Ext_bMonRunDft_Info_Crash;
extern boolean INFOCRASH_bCrashMuxPrev;
extern uint8 Confirm_crash_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INFOCRASH_vidConfirmInfoCrash(void);
void INFOCRASH_vidEndConfirmCrash(void);
void INFOCRASH_vidInhOrAuthInfoCrash(void);
void INFOCRASH_vidInit(void);
void INFOCRASH_vidInitOutput(void);


#endif /* INFOCRASH_L_H */

/*-------------------------------- end of file -------------------------------*/
