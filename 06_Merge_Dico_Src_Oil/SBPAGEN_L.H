/***************************************************************************
;**
;** FILE NAME      : SBPAGEN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SBPAGEN_L_H
#define SBPAGEN_L_H

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

extern const uint8  SBPAGEN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqSys_bAcvChgLvl;
extern boolean TqSys_bLvlSBPA;
extern uint16 SBPAGEN_u16SbpaShiftRegister;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SBPAGEN_vidCalculer_niveau(void);
void SBPAGEN_vidCalculer_SBPA(void);
void SBPAGEN_vidDecaler_registre(void);
void SBPAGEN_vidEffectuer_traitements(void);
void SBPAGEN_vidInitOutput(void);
void SBPAGEN_vidModifier_niveau(void);


#endif /* SBPAGEN_L_H */

/*-------------------------------- end of file -------------------------------*/
