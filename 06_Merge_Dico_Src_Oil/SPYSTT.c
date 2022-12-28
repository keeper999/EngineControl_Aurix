/***************************************************************************
;**
;** FILE NAME      : SPYSTT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SPYSTT.H"
#include "SPYSTT_L.H"
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
const uint8  SpySTT_noDstWin_C = 0;
const uint8  SpySTT_noRStrtFailRec_C = 0;
const uint8  SPYSTT_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean SpySTT_bCutCaseAcvt;
boolean SPYSTT_bRecHisNotStopCase_Prev;
boolean SPYSTT_bRecNotStop_Prev;
uint32 SpySTT_prmHisDstWin2[SPYSTT_PRMHISDSTWIN2_COLS];
uint32 SpySTT_prmHisDstWin3[SPYSTT_PRMHISDSTWIN3_COLS];
uint8 SpySTT_stCutCaseCur;
uint8 SPYSTT_u8CoPtUH_stPwt_Prev;
uint16 SpySTT_stNotStopCase;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

