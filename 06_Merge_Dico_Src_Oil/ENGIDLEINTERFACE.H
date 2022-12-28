/***************************************************************************
;**
;** FILE NAME      : ENGIDLEINTERFACE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGIDLEINTERFACE_H
#define ENGIDLEINTERFACE_H

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

extern const boolean  IdlSys_bTqMinSel_C;
extern const sint16  IdlSys_tqSatIdlMin_C;
extern const uint16  IdlSys_tqOfsIdlMax_C;
extern const uint16  IdlSys_tqOfsIdlMin_C;
extern const uint16  IdlSys_tqSatIdlMax_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IdlSys_bAcvStrtTqSys;
extern uint8 IdlSys_idxIdlCtlMod;
extern sint16 IdlSys_tqIdcIdlMax;
extern sint16 IdlSys_tqIdcIdlMin;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ENGIDLEINTERFACE_vidEntryInit(void);
void IdlSys_EveSync_GslIdlCtl(void);


#endif /* ENGIDLEINTERFACE_H */

/*-------------------------------- end of file -------------------------------*/
