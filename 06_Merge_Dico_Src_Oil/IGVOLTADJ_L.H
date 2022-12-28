/***************************************************************************
;**
;** FILE NAME      : IGVOLTADJ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGVOLTADJ_L_H
#define IGVOLTADJ_L_H

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

extern const uint8  IGVOLTADJ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IGVOLTADJ_bOutputHysteresis;
extern boolean IGVOLTADJ_bOutputTrndly;
extern boolean IGVOLTADJ_bResultComp_prev;
extern boolean IGVOLTADJ_bVltAdjZnFlipFlopOut;
extern boolean IgVoltAdj_bVoltAdjOpp;
extern boolean IgVoltAdj_bVoltAdjReq;
extern boolean IgVoltAdjReq_bVoltAdj;
extern uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1;
extern uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGVOLTADJ_vidIgVoltAdj(void);
void IGVOLTADJ_vidInitOutput(void);
void IGVOLTADJ_vidVoltAdjZone(void);


#endif /* IGVOLTADJ_L_H */

/*-------------------------------- end of file -------------------------------*/
