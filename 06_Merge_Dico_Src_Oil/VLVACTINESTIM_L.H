/***************************************************************************
;**
;** FILE NAME      : VLVACTINESTIM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINESTIM_L_H
#define VLVACTINESTIM_L_H

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

extern const uint8  VLVACTINESTIM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 VlvAct_InPosnEstimGainA;
extern sint16 VlvAct_InMngStCmdNorm;
extern sint16 VlvAct_InPosnEstimSpd;
extern uint16 VlvAct_InPosnEstimGainB;
extern uint16 VlvAct_InPosnEstimPosn;
extern uint16 VLVACTINESTIM_u16agCmInEstimPrev;
extern uint16 VLVACTINESTIM_u16agCmInEstimVar;
extern uint16 VLVACTINESTIM_u16RelInVvtMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINESTIM_vidDeadZone(void);
void VLVACTINESTIM_vidEstimGainCmp(void);
void VLVACTINESTIM_vidFilCmp(void);
void VLVACTINESTIM_vidInitOutput(void);
void VLVACTINESTIM_vidInPosnEstimCmp(void);
void VLVACTINESTIM_vidInPosnEstimUpd(void);
void VLVACTINESTIM_vidInPosnEstimVar(void);
void VLVACTINESTIM_vidKalmanFil(void);


#endif /* VLVACTINESTIM_L_H */

/*-------------------------------- end of file -------------------------------*/
