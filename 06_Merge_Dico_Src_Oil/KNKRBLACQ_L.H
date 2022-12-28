/***************************************************************************
;**
;** FILE NAME      : KNKRBLACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKRBLACQ_L_H
#define KNKRBLACQ_L_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 KNKRBLACQ_u32FilterOutputMem;
extern uint8 KNKRBLACQ_u8RblFilterInput;
extern uint8 KNKRBLACQ_u8SdlFilterInput;
extern uint8 Rbl_av_corr_prev_adpt_k;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKRBLACQ_vidInitConfigParam(void);
void KNKRBLACQ_vidInitOutput(void);
void KNKRBLACQ_vidRblAcqWinLength(void);
void KNKRBLACQ_vidRblCalcDetectAuthrz(void);
void KNKRBLACQ_vidRblCalcParameters(void);
void KNKRBLACQ_vidRblConfigParameters(void);
void KNKRBLACQ_vidRblObservtnWindow(void);
void KNKRBLACQ_vidRblTaskEndTreatment(void);
void KNKRBLACQ_vidRblTaskTreatment(void);
void KNKRBLACQ_vidSdlAcqWinLength(void);
void KNKRBLACQ_vidSdlCalcDetectAuthrz(void);
void KNKRBLACQ_vidSdlCalcParameters(void);
void KNKRBLACQ_vidSdlConfigParameters(void);
void KNKRBLACQ_vidSdlObservtnWindow(void);
void KNKRBLACQ_vidSdlTaskTreatment(void);
void KNKRBLACQ_vidTemporalTreatment(void);


#endif /* KNKRBLACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
