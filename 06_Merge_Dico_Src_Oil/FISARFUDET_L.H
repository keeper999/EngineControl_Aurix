/***************************************************************************
;**
;** FILE NAME      : FISARFUDET_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FISARFUDET_L_H
#define FISARFUDET_L_H

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

extern const uint8  FISARFUDET_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean FISARFUDET_bExtbRFuDetPrev;
extern boolean FISARFUDET_bFISARstAdpDonePrev;
extern uint8 Ext_volFuNew;
extern uint8 RFuDet_volFuDelta;
extern uint16 Fuel_used_between_tdc;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FISARFUDET_vidArretMoteur(void);
void FISARFUDET_vidCalcCoefLissage(void);
void FISARFUDET_vidCalcConsoDepRempl(void);
void FISARFUDET_vidCalculDelta(void);
void FISARFUDET_vidCalculValeursReset(void);
void FISARFUDET_vidClefOn(void);
void FISARFUDET_vidCndCalcCoefLissage(void);
void FISARFUDET_vidConsomDepuisPlein(void);
void FISARFUDET_vidInit(void);
void FISARFUDET_vidResetCoefEffectue(void);


#endif /* FISARFUDET_L_H */

/*-------------------------------- end of file -------------------------------*/
