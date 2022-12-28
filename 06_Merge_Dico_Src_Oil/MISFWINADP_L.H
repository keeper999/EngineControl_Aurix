/***************************************************************************
;**
;** FILE NAME      : MISFWINADP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFWINADP_L_H
#define MISFWINADP_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MISFWINADP_U16INTERPTAB_COLS           ( 4 )
#define MISFWINADP_u8TabLenth             9

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

extern const uint8  MISFWINADP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 MISFWINADP_u16InterpTab[MISFWINADP_U16INTERPTAB_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFWINADP_vidConditionActiv(void);
void MISFWINADP_vidCorrectedWindow(void);
void MISFWINADP_vidCorrectWin_Calc(void);
void MISFWINADP_vidCorrectWin_Interp(void);
void MISFWINADP_vidInitOutput(void);


#endif /* MISFWINADP_L_H */

/*-------------------------------- end of file -------------------------------*/
