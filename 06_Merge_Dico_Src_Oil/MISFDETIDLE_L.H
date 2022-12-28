/***************************************************************************
;**
;** FILE NAME      : MISFDETIDLE_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDETIDLE_L_H
#define MISFDETIDLE_L_H

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

extern const uint8  MISFDETIDLE_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 MISFDETIDLE_u32tiDlyWinAdpPrev1;
extern uint32 MISFDETIDLE_u32tiDlyWinAdpPrev2;
extern sint16 Mf_idle_algo_out_uavn0;
extern uint16 MISFDETIDLE_u16ResultPrev3;
extern uint16 MISFDETIDLE_u16ResultPrev4;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFDETIDLE_vidDetAlgoOutIdle(void);
void MISFDETIDLE_vidDetection(void);
void MISFDETIDLE_vidDetIdleAlgo(void);
void MISFDETIDLE_vidInit(void);
void MISFDETIDLE_vidInitOutput(void);
void MISFDETIDLE_vidMisfDetIdleDet(void);


#endif /* MISFDETIDLE_L_H */

/*-------------------------------- end of file -------------------------------*/
