/***************************************************************************
;**
;** FILE NAME      : BATTVOLTREQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BATTVOLTREQ_L_H
#define BATTVOLTREQ_L_H

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

extern const uint8  BATTVOLTREQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean BATTVOLTREQ_bAcvTrbActMax_MPPrev;
extern boolean BATTVOLTREQ_bOutNegHysRqstCond;
extern boolean BoostAct_bAcvTrbActMax;
extern boolean BoostAct_bAcvTrbActMax_MP;
extern uint16 BATTVOLTREQ_u16TOffDlyAuthCnt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BATTVOLTREQ_vidBattVltRqstLowVlt(void);
void BATTVOLTREQ_vidBattVoltRqstCond(void);
void BATTVOLTREQ_vidInit(void);
void BATTVOLTREQ_vidInitOutput(void);
void BATTVOLTREQ_vidWasteMaxClsdCond(void);


#endif /* BATTVOLTREQ_L_H */

/*-------------------------------- end of file -------------------------------*/
