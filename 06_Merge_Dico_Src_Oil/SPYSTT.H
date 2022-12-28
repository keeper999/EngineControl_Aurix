/***************************************************************************
;**
;** FILE NAME      : SPYSTT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPYSTT_H
#define SPYSTT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SPYSTT_PRMHISDSTWIN2_COLS              ( 2 )
#define SPYSTT_PRMHISDSTWIN3_COLS              ( 2 )

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

extern const uint8  SpySTT_noDstWin_C;
extern const uint8  SpySTT_noRStrtFailRec_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 SpySTT_prmHisDstWin2[SPYSTT_PRMHISDSTWIN2_COLS];
extern uint32 SpySTT_prmHisDstWin3[SPYSTT_PRMHISDSTWIN3_COLS];
extern uint16 SpySTT_stNotStopCase;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void STT_EveRst_SpySTT(void);
void STT_SdlMid_SpySTT(void);


#endif /* SPYSTT_H */

/*-------------------------------- end of file -------------------------------*/
