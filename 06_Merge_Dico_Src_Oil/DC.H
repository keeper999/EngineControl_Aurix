/***************************************************************************
;**
;** FILE NAME      : DC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DC_H
#define DC_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DC_AU8DC_EEPROM_LNS                   ( 122 )

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

extern const uint8  DC_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DC_bSyncGlbDC;
extern uint8 DC_au8DC_EEPROM[DC_AU8DC_EEPROM_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DC_RstDC(void);
void DC_RstDftCal(void);
void DC_vidMngEveCDThd(uint16 u16IdxDft);
void DC_vidMngEveCrTR(void);
void DC_vidMngEveCrTst(void);
void DC_vidMngEveKeyODB(void);
void DC_vidMngEveRst(void);
void GD_EveKOf_DC(void);
void GD_EveRstDft_DC(void);
void GD_EveRstDftObd_DC(void);


#endif /* DC_H */

/*-------------------------------- end of file -------------------------------*/
