/***************************************************************************
;**
;** FILE NAME      : SFTYCPUDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SFTYCPUDIAG_H
#define SFTYCPUDIAG_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sfty_bDgoAccP_Cpu;
extern boolean Sfty_bDgoAlgo_Cpu;
extern boolean Sfty_bDgoAlgo_CpuSfty;
extern boolean Sfty_bDgoClk_Cpu;
extern boolean Sfty_bDgoClk_CpuSfty;
extern boolean Sfty_bDgoComSpi_Cpu;
extern boolean Sfty_bDgoComSpi_CpuSfty;
extern boolean Sfty_bDgoComTout_Cpu;
extern boolean Sfty_bDgoComTout_CpuSfty;
extern boolean Sfty_bDgoSyncMon_Cpu;
extern boolean Sfty_bDgoSyncMon_CpuSfty;
extern boolean Sfty_bDgoThr_Cpu;
extern boolean Sfty_bMonRunAccP_Cpu;
extern boolean Sfty_bMonRunAlgo_Cpu;
extern boolean Sfty_bMonRunAlgo_CpuSfty;
extern boolean Sfty_bMonRunClk_Cpu;
extern boolean Sfty_bMonRunClk_CpuSfty;
extern boolean Sfty_bMonRunComSpi_Cpu;
extern boolean Sfty_bMonRunComSpi_CpuSfty;
extern boolean Sfty_bMonRunComTout_Cpu;
extern boolean Sfty_bMonRunComTout_CpuSfty;
extern boolean Sfty_bMonRunSyncMon_Cpu;
extern boolean Sfty_bMonRunSyncMon_CpuSfty;
extern boolean Sfty_bMonRunThr_Cpu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Sfty_EveRst_DiagCpuSfty(void);
void Sfty_SdlFast_DiagCpuSfty(void);
void Sfty_SdlSlow_DiagCpuSfty(void);


#endif /* SFTYCPUDIAG_H */

/*-------------------------------- end of file -------------------------------*/
