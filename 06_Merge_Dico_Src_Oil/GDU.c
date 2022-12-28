/***************************************************************************
;**
;** FILE NAME      : GDU.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "GDU.H"
#include "GDU_L.H"
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
const boolean  GDU_bRstDftCal_C = 0;
const uint16  GDU_au16CtDec[GDU_AU16CTDEC_COLS] = {0};
const uint16  GDU_au16CtInc[GDU_AU16CTINC_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean GD_abctDetPrev[GD_ABCTDETPREV_LNS];
boolean GD_abThdDown[GD_ABTHDDOWN_LNS];
boolean GD_abThdDownPrev[GD_ABTHDDOWNPREV_LNS];
boolean GD_abThdUp[GD_ABTHDUP_LNS];
boolean GD_abThdUpPrev[GD_ABTHDUPPREV_LNS];
boolean GDU_bMemRstDftCal;
GD_tstrDftEep GD_astrDftEep[GD_ASTRDFTEEP_LNS];
GDU_tstrDft GDU_astrDftUnit[GDU_ASTRDFTUNIT_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

