/***************************************************************************
;**
;** FILE NAME      : IDLCMDMOD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLCMDMOD_H
#define IDLCMDMOD_H

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

extern const boolean  TqSys_bCfNTarIdlCmbMod_C;
extern const sint16  TqSys_nDecTarIdlCmbMod1_C;
extern const sint16  TqSys_nDecTarIdlCmbMod2_C;
extern const sint16  TqSys_nDecTarIdlCmbMod3_C;
extern const sint16  TqSys_nDecTarIdlCmbMod4_C;
extern const sint16  TqSys_nDecTarIdlCmbMod5_C;
extern const sint16  TqSys_nDecTarIdlCmbMod6_C;
extern const uint16  TqSys_nIncTarIdlCmbMod1_C;
extern const uint16  TqSys_nIncTarIdlCmbMod2_C;
extern const uint16  TqSys_nIncTarIdlCmbMod3_C;
extern const uint16  TqSys_nIncTarIdlCmbMod4_C;
extern const uint16  TqSys_nIncTarIdlCmbMod5_C;
extern const uint16  TqSys_nIncTarIdlCmbMod6_C;
extern const uint16  TqSys_nTarIdlCmbMod1Egd_C;
extern const uint16  TqSys_nTarIdlCmbMod1Neut_C;
extern const uint16  TqSys_nTarIdlCmbMod2Egd_C;
extern const uint16  TqSys_nTarIdlCmbMod2Neut_C;
extern const uint16  TqSys_nTarIdlCmbMod3Egd_C;
extern const uint16  TqSys_nTarIdlCmbMod3Neut_C;
extern const uint16  TqSys_nTarIdlCmbMod4Egd_C;
extern const uint16  TqSys_nTarIdlCmbMod4Neut_C;
extern const uint16  TqSys_nTarIdlCmbMod5Egd_C;
extern const uint16  TqSys_nTarIdlCmbMod5Neut_C;
extern const uint16  TqSys_nTarIdlCmbMod6Egd_C;
extern const uint16  TqSys_nTarIdlCmbMod6Neut_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqSys_nTarIdlCmbMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IDLCMDMOD_vidEntryInit(void);
void TqSys_Sdl10ms_nTarIdlCmbMod(void);


#endif /* IDLCMDMOD_H */

/*-------------------------------- end of file -------------------------------*/
