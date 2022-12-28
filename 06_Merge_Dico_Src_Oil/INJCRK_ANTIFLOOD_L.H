/***************************************************************************
;**
;** FILE NAME      : INJCRK_ANTIFLOOD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJCRK_ANTIFLOOD_L_H
#define INJCRK_ANTIFLOOD_L_H

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

extern const uint8  Anti_flood_pedale_hysteresis;
extern const uint8  Anti_flood_pedale_limit;
extern const uint8  Anti_flood_regime_reinj;
extern const uint8  INJCRK_ANTIFLOOD_u8Inhib;
extern const uint16  Anti_flood_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Function_anti_flood;
extern uint16 Anti_flood_delay_counter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJCRK_ANTIFLOOD_vidConfAntFlood(void);
void INJCRK_ANTIFLOOD_vidCranking(void);
void INJCRK_ANTIFLOOD_vidCrkFuelling(void);
void INJCRK_ANTIFLOOD_vidDetAntiFlood(void);
void INJCRK_ANTIFLOOD_vidEngSpdNok(void);
void INJCRK_ANTIFLOOD_vidEngSpdOk(void);
void INJCRK_ANTIFLOOD_vidIniRunToCrnk(void);
void INJCRK_ANTIFLOOD_vidInitAntiFlood(void);
void INJCRK_ANTIFLOOD_vidInitCrkFlood(void);
void INJCRK_ANTIFLOOD_vidInitOutput(void);
void INJCRK_ANTIFLOOD_vidMngAntiFlood(void);
void INJCRK_ANTIFLOOD_vidNotCranking(void);
void INJCRK_ANTIFLOOD_vidPosPedNok(void);
void INJCRK_ANTIFLOOD_vidPosPedOk(void);
void INJCRK_ANTIFLOOD_vidRestAntFlood(void);


#endif /* INJCRK_ANTIFLOOD_L_H */

/*-------------------------------- end of file -------------------------------*/
