/***************************************************************************
;**
;** FILE NAME      : DIAGTAB_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DIAGTAB_L_H
#define DIAGTAB_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GD_TABLE_PANNE_EVENT_LNS              ( 30 )
#define GD_TABLE_PANNE_STATE_LNS              ( 30 )

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

extern const uint8  DIAGTAB_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 GD_table_panne_state[GD_TABLE_PANNE_STATE_LNS];
extern uint16 GD_table_panne_event[GD_TABLE_PANNE_EVENT_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DIAGTAB_vidFillingFailuresBuffer(void);
void DIAGTAB_vidInitFailuresBuffer(void);


#endif /* DIAGTAB_L_H */

/*-------------------------------- end of file -------------------------------*/
