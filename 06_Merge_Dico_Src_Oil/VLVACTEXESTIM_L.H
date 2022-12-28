/***************************************************************************
;**
;** FILE NAME      : VLVACTEXESTIM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXESTIM_L_H
#define VLVACTEXESTIM_L_H

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

extern const uint8  VLVACTEXESTIM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 VlvAct_ExPosnEstimGainA;
extern sint16 VlvAct_ExMngStCmdNorm;
extern sint16 VlvAct_ExPosnEstimSpd;
extern uint16 VlvAct_ExPosnEstimGainB;
extern uint16 VlvAct_ExPosnEstimPosn;
extern uint16 VLVACTEXESTIM_u16agCmExEstimPrev;
extern uint16 VLVACTEXESTIM_u16agCmExEstimVar;
extern uint16 VLVACTEXESTIM_u16RelExVvtMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXESTIM_vidDeadZone(void);
void VLVACTEXESTIM_vidEstimGainCmp(void);
void VLVACTEXESTIM_vidExPosnEstimCmp(void);
void VLVACTEXESTIM_vidExPosnEstimUpd(void);
void VLVACTEXESTIM_vidExPosnEstimVar(void);
void VLVACTEXESTIM_vidFilCmp(void);
void VLVACTEXESTIM_vidInitOutput(void);
void VLVACTEXESTIM_vidKalmanFil(void);


#endif /* VLVACTEXESTIM_L_H */

/*-------------------------------- end of file -------------------------------*/
