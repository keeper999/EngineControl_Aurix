/***************************************************************************
;**
;** FILE NAME      : JDDISCANIF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef JDDISCANIF_H
#define JDDISCANIF_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Jbsi_IscanBufferPos1;
extern uint8 Jbsi_IscanBufferPos2;
extern uint8 Jbsi_IscanBufferPos3;
extern uint8 Jbsi_IscanBufferPos4;
extern uint8 Jbsi_IscanBufferPos5;
extern uint8 Jbsi_IscanBufferPos6;
extern uint8 Jbsi_IscanBufferPos7;
extern uint8 Jbsi_IscanBufferPos8;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveRst_DftLogTx(void);
void JDDISCANIF_PrepaDataIscanBuffer(void);


#endif /* JDDISCANIF_H */

/*-------------------------------- end of file -------------------------------*/
