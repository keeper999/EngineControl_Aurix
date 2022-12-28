/***************************************************************************
;**
;** FILE NAME      : SPYEMSTT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPYEMSTT_H
#define SPYEMSTT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SPYEMSTT_PRMHISDSTWIN2_COLS            ( 2 )
#define SPYEMSTT_PRMHISDSTWIN3_COLS            ( 2 )
#define SPYEMSTT_u8ARRAY_LENGTH2          2
#define SPYEMSTT_u8ARRAY_LENGTH7          7

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

extern const uint8  SpyEmSTT_noDstWin_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 SpyEmSTT_stNotStopCase;
extern sint32 SpyEmSTT_prmHisDstWin2[SPYEMSTT_PRMHISDSTWIN2_COLS];
extern sint32 SpyEmSTT_prmHisDstWin3[SPYEMSTT_PRMHISDSTWIN3_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void STT_EveRst_SpyEmSTT(void);
void STT_SdlMid_SpyEmSTT(void);


#endif /* SPYEMSTT_H */

/*-------------------------------- end of file -------------------------------*/
