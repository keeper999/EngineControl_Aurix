/***************************************************************************
;**
;** FILE NAME      : WG_CMDBENCHMOD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WG_CMDBENCHMOD_L_H
#define WG_CMDBENCHMOD_L_H

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

extern const uint8  Wg_CmdBenchMod_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Wg_bWgCmdBenchModHystOutput;
extern uint32 Wg_rWgCmdOplSpBenchModMem;
extern uint16 Wg_rWgCmdOplSpRawBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Wg_CmdBenchMod_vidCalcWgCmdOplBenchMod(void);
void Wg_CmdBenchMod_vidIniWgCmdOplSpBenchMod(void);
void Wg_CmdBenchMod_vidWgCmd(void);
void Wg_CmdBenchMod_vidWgCmdCutOff(void);
void Wg_CmdBenchMod_vidWgCmdRaw(void);


#endif /* WG_CMDBENCHMOD_L_H */

/*-------------------------------- end of file -------------------------------*/
