/***************************************************************************
;**
;** FILE NAME      : SPYEMSTT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPYEMSTT_L_H
#define SPYEMSTT_L_H

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

extern const uint8  SPYEMSTT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SPYEMSTT_bHisDstWin1_Prev;
extern boolean SPYEMSTT_bRecNotStop_Prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SPYEMSTT_NVMSRV_vidInit(void);
void SPYEMSTT_vidInitialization(void);
void SPYEMSTT_vidInitOutput(void);
void SPYEMSTT_vidRecHisNotStopCase(void);
void SPYEMSTT_vidRecNotStopCase(void);
void SPYEMSTT_vidRecNotStopCase1(void);


#endif /* SPYEMSTT_L_H */

/*-------------------------------- end of file -------------------------------*/
