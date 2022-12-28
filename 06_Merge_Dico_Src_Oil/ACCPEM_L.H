/***************************************************************************
;**
;** FILE NAME      : ACCPEM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPEM_L_H
#define ACCPEM_L_H

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

extern const uint8  ACCPEM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AccP_bDgoCoh_rAccP;
extern boolean AccP_bMonRunCoh_rAccP;
extern boolean ACCPEM_bAcvSaveAccPInvldPrev;
extern boolean ACCPEM_bFRM_InhDiagCohrAccPrev;
extern boolean ACCPEM_bRstHwReqAntPrev;
extern boolean ACCPEM_bRstSwReqAntPrev;
extern uint16 AccP_rAccPFinal;
extern uint16 AccP_rAccPLim;
extern uint16 AccP_rAccPRobust;
extern uint16 ACCPEM_u16AccP_tiInhCohTest;
extern uint16 ACCPEM_u16AccPRAccPSens1Prev;
extern uint16 ACCPEM_u16AccPRAccPSens1Prev2;
extern uint16 ACCPEM_u16AccPRAccPSens2Prev;
extern uint16 ACCPEM_u16AccPRAccPSens2Prev2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACCPEM_vidAccPCohAuth(void);
void ACCPEM_vidAccPCohDiag(void);
void ACCPEM_vidAccPReinfPos(void);
void ACCPEM_vidAccPSatPos(void);
void ACCPEM_vidDiagCoh(void);
void ACCPEM_vidInit(void);
void ACCPEM_vidInitOutput(void);
void ACCPEM_vidPosPedFinale(void);
void ACCPEM_vidPosPedKOff(void);
void ACCPEM_vidPosPedRst(void);
void ACCPEM_vidPosPedValid(void);


#endif /* ACCPEM_L_H */

/*-------------------------------- end of file -------------------------------*/
