/***************************************************************************
;**
;** FILE NAME      : DMPVLVCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DMPVLVCMD_L_H
#define DMPVLVCMD_L_H

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

extern const uint8  DmpVlvCmd_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DmpVlvAct_bDgoHi_DmpVlvCmd;
extern boolean DmpVlvAct_bDgoLo_DmpVlvCmd;
extern boolean DmpVlvAct_bMonRunHi_DmpVlvCmd;
extern boolean DmpVlvAct_bMonRunLo_DmpVlvCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DmpVlvCmd_vidDiagnostic(void);
void DmpVlvCmd_vidDmpVlvCmdAplication(void);
void DmpVlvCmd_vidInitEveRst(void);


#endif /* DMPVLVCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
