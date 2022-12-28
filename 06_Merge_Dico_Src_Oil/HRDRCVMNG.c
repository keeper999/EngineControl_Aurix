/***************************************************************************
;**
;** FILE NAME      : HRDRCVMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HRDRCVMNG.H"
#include "HRDRCVMNG_L.H"
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
const uint8  HRDRCVMNG_u8Inhib = 0;
const uint16  Fgid_ti_VsctlDiagIni_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Fgid_b_VsctlDiagIni;
boolean FRM_bEnaDeacVSCtlEng;
boolean FRM_bEnaDeacVSCtlTra;
boolean FRM_bEnaDeacVSCtlVeh;
boolean FRM_bEnaDeacVSCtlVSLim;
boolean FRM_bEnaDeacVSCtlVSMax;
boolean FRM_bEnaDeacVSCtlVSReg;
boolean HRDRCVMNG_bTimerInput;
boolean HRDRCVMNG_bTimerOutput;
uint8 HRDRCVMNG_u8TimerCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

