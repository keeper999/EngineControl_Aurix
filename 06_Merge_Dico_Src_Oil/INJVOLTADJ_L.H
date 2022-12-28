/***************************************************************************
;**
;** FILE NAME      : INJVOLTADJ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJVOLTADJ_L_H
#define INJVOLTADJ_L_H

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

extern const uint8  INJVOLTADJ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean InjSys_bInjVoltAdj;
extern boolean InjSys_bPmpVoltAdj;
extern boolean INJVOLTADJ_bOutputHysteresis;
extern uint32 InjSys_tiTotInjVoltBstReq;
extern uint8 InjSys_NrInjVoltBstReq;
extern uint16 InjSys_facInjVoltBstReq;
extern uint16 InjSys_tiTotPmpCmdReq;
extern uint16 InjSys_uBatInjVoltAdjThd;
extern uint16 InjSys_uBatInjVoltBstReqThd;
extern uint16 INJVOLTADJ_u16PFuCtlCmdReqPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJVOLTADJ_vidInitOutput(void);
void INJVOLTADJ_vidInjCmdVolt(void);
void INJVOLTADJ_vidInjVoltAdj(void);
void INJVOLTADJ_vidPmpCmdVolt(void);


#endif /* INJVOLTADJ_L_H */

/*-------------------------------- end of file -------------------------------*/
