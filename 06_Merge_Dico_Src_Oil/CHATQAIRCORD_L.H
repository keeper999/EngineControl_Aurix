/***************************************************************************
;**
;** FILE NAME      : CHATQAIRCORD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CHATQAIRCORD_L_H
#define CHATQAIRCORD_L_H

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

extern const uint8  CHATQAIRCORD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoCha_bTypFil_MP;
extern sint16 CHATQAIRCORD_s16FilterOutput;
extern sint16 CoCha_tqAirFil_MP;
extern uint16 CHATQAIRCORD_u16CoChaTqDifT;
extern uint16 CoCha_tqDeltaASROfs_MP;
extern sint32 CHATQAIRCORD_s32FilterKMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CHATQAIRCORD_vidCalcConsigRegASR(void);
void CHATQAIRCORD_vidInitOutput(void);


#endif /* CHATQAIRCORD_L_H */

/*-------------------------------- end of file -------------------------------*/
