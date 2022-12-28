/***************************************************************************
;**
;** FILE NAME      : SFTYCPUDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SFTYCPUDIAG_L_H
#define SFTYCPUDIAG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MCWDG_ALU                         16
#define MCWDG_CLOCK                       8
#define MCWDG_COMSPI                      1
#define MCWDG_DEG_MOD                     128
#define MCWDG_MCP_ADC_VAL                 32
#define MCWDG_MONIT                       4
#define MCWDG_TIMEOUT                     2

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

extern const uint8  SFTYCPUDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sfty_bAcvDegMod_CpuSfty;
extern boolean Sfty_bDgoCksRom_CpuSfty;
extern boolean Sfty_bDgoDegMod_CpuSfty;
extern boolean Sfty_bMonRunCksRom_CpuSfty;
extern boolean Sfty_bMonRunDegMod_CpuSfty;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SFTYCPUDIAG_vidDiagRomChecksum(void);
void SFTYCPUDIAG_vidInitOutput(void);
void SFTYCPUDIAG_vidMcwdgDiagnosesMCP(void);
void SFTYCPUDIAG_vidMcwdgReadMCWFltSt(void);
void SFTYCPUDIAG_vidMcwdgSampleCheck(void);
void SFTYCPUDIAG_vidMcwdgWritMCPFltSt(void);


#endif /* SFTYCPUDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
