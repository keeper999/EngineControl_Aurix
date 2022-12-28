/***************************************************************************
;**
;** FILE NAME      : IGARB_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGARB_L_H
#define IGARB_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_AGIGTESTCYL_COLS                 ( 3 )

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
extern boolean IGARB_bAcvBenchModCmpnIgPrev;
extern uint8 IgSys_agIgSpBenchMod;
extern uint8 IgSys_agIgSpNxtBenchMod;
extern uint8 IgSys_agigTestCyl[IGSYS_AGIGTESTCYL_COLS];
extern uint8 IgSys_CtrCylCmpn;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgArb_vidDwellEnergyBenchMode(void);
void IgArb_vidIgArbInit(void);
void IgArb_vidIgnitionArbitration(void);
void IgArb_vidIgnitionClcBenchMod(void);
void IgArb_vidIgnitionTimingBenchMode(void);
void IGARB_vidInitOutput(void);
void IgArb_vidMngBenchMod(void);


#endif /* IGARB_L_H */

/*-------------------------------- end of file -------------------------------*/
