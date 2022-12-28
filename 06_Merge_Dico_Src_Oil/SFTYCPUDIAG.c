/***************************************************************************
;**
;** FILE NAME      : SFTYCPUDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SFTYCPUDIAG.H"
#include "SFTYCPUDIAG_L.H"
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
const uint8  SFTYCPUDIAG_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Sfty_bAcvDegMod_CpuSfty;
boolean Sfty_bDgoAccP_Cpu;
boolean Sfty_bDgoAlgo_Cpu;
boolean Sfty_bDgoAlgo_CpuSfty;
boolean Sfty_bDgoCksRom_CpuSfty;
boolean Sfty_bDgoClk_Cpu;
boolean Sfty_bDgoClk_CpuSfty;
boolean Sfty_bDgoComSpi_Cpu;
boolean Sfty_bDgoComSpi_CpuSfty;
boolean Sfty_bDgoComTout_Cpu;
boolean Sfty_bDgoComTout_CpuSfty;
boolean Sfty_bDgoDegMod_CpuSfty;
boolean Sfty_bDgoSyncMon_Cpu;
boolean Sfty_bDgoSyncMon_CpuSfty;
boolean Sfty_bDgoThr_Cpu;
boolean Sfty_bMonRunAccP_Cpu;
boolean Sfty_bMonRunAlgo_Cpu;
boolean Sfty_bMonRunAlgo_CpuSfty;
boolean Sfty_bMonRunCksRom_CpuSfty;
boolean Sfty_bMonRunClk_Cpu;
boolean Sfty_bMonRunClk_CpuSfty;
boolean Sfty_bMonRunComSpi_Cpu;
boolean Sfty_bMonRunComSpi_CpuSfty;
boolean Sfty_bMonRunComTout_Cpu;
boolean Sfty_bMonRunComTout_CpuSfty;
boolean Sfty_bMonRunDegMod_CpuSfty;
boolean Sfty_bMonRunSyncMon_Cpu;
boolean Sfty_bMonRunSyncMon_CpuSfty;
boolean Sfty_bMonRunThr_Cpu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

