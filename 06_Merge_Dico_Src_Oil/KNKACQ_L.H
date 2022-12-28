/***************************************************************************
;**
;** FILE NAME      : KNKACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKACQ_L_H
#define KNKACQ_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNKACQ_u32ARRAY_LENGTH            4

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

extern const uint8  KNKACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 KNKACQ_u32CliqAvCorAdptKFiltMem;
extern uint8 Cliq_av_corr_prev_adpt_k;
extern uint8 Table_freq_centrale_cyl1_sdl;
extern uint8 Table_freq_centrale_cyl1_win;
extern uint8 Table_freq_centrale_cyl2_sdl;
extern uint8 Table_freq_centrale_cyl2_win;
extern uint8 Table_freq_centrale_cyl3_sdl;
extern uint8 Table_freq_centrale_cyl3_win;
extern uint8 Table_freq_centrale_cyl4_sdl;
extern uint8 Table_freq_centrale_cyl4_win;
extern uint16 Charge_chgt_freq_cliq;
extern uint16 Regime_chgt_freq_cliq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKACQ_vidBandPassFilterParam(void);
void KNKACQ_vidCalcAuthorizeDetection(void);
void KNKACQ_vidCalcParameters(void);
void KNKACQ_vidConfigParameters(void);
void KNKACQ_vidConfigParametersInit(void);
void KNKACQ_vidEndKnoksTaskTreatment(void);
void KNKACQ_vidInitOutput(void);
void KNKACQ_vidObservationWindow(void);
void KNKACQ_vidTBandPassFilterParam(void);
void KNKACQ_vidTCalcAuthorizDetection(void);
void KNKACQ_vidTCalcParameters(void);
void KNKACQ_vidTConfigParameters(void);
void KNKACQ_vidTemporalTreatment(void);
void KNKACQ_vidTObservationWindow(void);


#endif /* KNKACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
