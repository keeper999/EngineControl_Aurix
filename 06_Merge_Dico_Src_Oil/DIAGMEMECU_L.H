/***************************************************************************
;**
;** FILE NAME      : DIAGMEMECU_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DIAGMEMECU_L_H
#define DIAGMEMECU_L_H

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

extern const uint8  DIAGMEMECU_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean EcuSt_bDftEepromEna;
extern boolean EcuSt_bDgoDftEeprom;
extern boolean EcuSt_bDgoFlashChk;
extern boolean EcuSt_bMonRunDftEeprom;
extern boolean EcuSt_bMonRunFlashChk;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DIAGMEMECU_vidEcuStEepromEna(void);
void DIAGMEMECU_vidEcuStEepromOK(void);
void DIAGMEMECU_vidEcuStFlashChk(void);
void DIAGMEMECU_vidEepromOK(void);


#endif /* DIAGMEMECU_L_H */

/*-------------------------------- end of file -------------------------------*/
