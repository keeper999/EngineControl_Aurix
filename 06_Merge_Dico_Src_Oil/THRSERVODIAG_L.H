/***************************************************************************
;**
;** FILE NAME      : THRSERVODIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSERVODIAG_L_H
#define THRSERVODIAG_L_H

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

extern const uint8  THRSERVODIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Enable_servoing_failure_detect;
extern boolean Thr_bAbsPosnErrORng;
extern boolean Thr_bCtlrIntORng;
extern boolean Thr_bDgoORngServo;
extern boolean Thr_bDgoORngServoDifNeg;
extern boolean Thr_bDgoORngServoDifPos;
extern boolean Thr_bMonRunORngServo;
extern boolean THRSERVODIAG_bAbsPosErrORng_Prev;
extern boolean THRSERVODIAG_bCtlrIntORng_Prev;
extern boolean THRSERVODIAG_bCtlrIntORngTimer;
extern boolean THRSERVODIAG_bCtlrIntORngTimerPr;
extern boolean THRSERVODIAG_bEnaFailDetPrev;
extern boolean THRSERVODIAG_bIntegralFailOut;
extern boolean THRSERVODIAG_bIntegralFailOut2;
extern boolean THRSERVODIAG_bposnMaxErrTimer;
extern boolean THRSERVODIAG_bposnMaxErrTimerPrv;
extern boolean THRSERVODIAG_bServoFailDetecOut2;
extern boolean THRSERVODIAG_bServoFailDetectOut;
extern boolean THRSERVODIAG_bServoFailDiagOut;
extern boolean Tpac_bClCtlErrSignPos;
extern uint32 THRSERVODIAG_u32FiltPosErrorMem;
extern uint8 THRSERVODIAG_u8TpacThrCtrlStPrev;
extern uint16 THRSERVODIAG_u16IntegrFailTemp2;
extern uint16 THRSERVODIAG_u16IntegrFailTempo;
extern uint16 THRSERVODIAG_u16PosnMaxErrThd;
extern uint16 THRSERVODIAG_u16ServFailDetTemp2;
extern uint16 THRSERVODIAG_u16ServFailDetTempo;
extern uint16 THRSERVODIAG_u16ServFailDiagTemp;
extern uint16 Tpac_filtered_position_error_sc;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRSERVODIAG_vidDifThrDgDataCal(void);
void THRSERVODIAG_vidDifThrPoDgFrAfSl(void);
void THRSERVODIAG_vidDifThrPosDiag(void);
void THRSERVODIAG_vidInitOutput(void);
void THRSERVODIAG_vidSerFailDetection(void);


#endif /* THRSERVODIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
