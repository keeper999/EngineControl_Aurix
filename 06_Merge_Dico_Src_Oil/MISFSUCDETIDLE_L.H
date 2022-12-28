/***************************************************************************
;**
;** FILE NAME      : MISFSUCDETIDLE_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFSUCDETIDLE_L_H
#define MISFSUCDETIDLE_L_H

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

extern const uint8  MISFSUCDETIDLE_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean MisfDet_bMisfSucDetEna;
extern boolean MisfDet_bMisfSucDetRaw;
extern boolean MISFSUCDETIDLE_bCondSucEnaPrev;
extern boolean MISFSUCDETIDLE_bMisfSucRawPrev1;
extern boolean MISFSUCDETIDLE_bMisfSucRawPrev2;
extern uint8 Mf_Idl_det_single_out_prev_uavb0;
extern uint8 MISFSUCDETIDLE_u8MfIdlesingPrev1;
extern uint8 MISFSUCDETIDLE_u8MfIdlesingPrev2;
extern sint16 Mf_idle1_algo_trust_uavn0;
extern sint16 Mf_idle2_algo_trust_uavn0;
extern sint16 MisfDet_critAlgoIdleOut1;
extern sint16 MisfDet_critAlgoIdleOut2;
extern uint16 Mf_idle_algo_thresh_2_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFSUCDETIDLE_vidAlgo1trustSuc(void);
void MISFSUCDETIDLE_vidAlgo2trustSuc(void);
void MISFSUCDETIDLE_vidAlgoMfSuc(void);
void MISFSUCDETIDLE_vidAutoDetMfSuc(void);
void MISFSUCDETIDLE_vidDecisionMfSuc(void);
void MISFSUCDETIDLE_vidDetectionMfSuc(void);
void MISFSUCDETIDLE_vidFilter1MfSuc(void);
void MISFSUCDETIDLE_vidFilter2MfSuc(void);
void MISFSUCDETIDLE_vidIni(void);
void MISFSUCDETIDLE_vidInitOutput(void);
void MISFSUCDETIDLE_vidMainMisfSucDet(void);
void MISFSUCDETIDLE_vidMisfire1DetMf(void);
void MISFSUCDETIDLE_vidMisfire2DetMf(void);
void MISFSUCDETIDLE_vidMisfSucDet(void);
void MISFSUCDETIDLE_vidMisfSucDetNot(void);
void MISFSUCDETIDLE_vidNotDetectMfSuc(void);


#endif /* MISFSUCDETIDLE_L_H */

/*-------------------------------- end of file -------------------------------*/
