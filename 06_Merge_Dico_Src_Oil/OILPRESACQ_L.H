/***************************************************************************
;**
;** FILE NAME      : OILPRESACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILPRESACQ_L_H
#define OILPRESACQ_L_H

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

extern const uint8  OILPRESACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Oil_pres_alert_fil;
extern boolean OILPRESACQ_bRawSig;
extern uint8 OILPRESACQ_u8AntiBounceCounter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OILPRESACQ_vidAcqFil(void);
void OILPRESACQ_vidInitialization(void);
void OILPRESACQ_vidInitOutput(void);
void OILPRESACQ_vidOilPresInfoAcq(void);


#endif /* OILPRESACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
