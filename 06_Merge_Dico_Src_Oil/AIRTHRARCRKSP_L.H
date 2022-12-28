/***************************************************************************
;**
;** FILE NAME      : AIRTHRARCRKSP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTHRARCRKSP_L_H
#define AIRTHRARCRKSP_L_H

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

extern const uint8  AIRTHRARCRKSP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 AIRTHRARCRKSP_u8SlewRateOutput;
extern uint8 Dtc_first_crank_offset_delay;
extern uint8 Dtc_first_crank_offset_torque;
extern uint8 Dtc_toil_or_teau;
extern sint16 CrkMgt_tqLoss_ThrArCrkAdp;
extern uint16 Air_density_gain;
extern uint16 Dtc_first_crank_decay_step;
extern uint16 EngSt_rGainSpThrFctPAir;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AIRTHRARCRKSP_vidCalcTqLoss(void);
void AIRTHRARCRKSP_vidCompAirDenGain(void);
void AIRTHRARCRKSP_vidCompDtcFiCraOff(void);
void AIRTHRARCRKSP_vidCompDtcSection(void);
void AIRTHRARCRKSP_vidCompDtcTrCoSurf(void);
void AIRTHRARCRKSP_vidInitDelay(void);
void AIRTHRARCRKSP_vidInitOutput(void);
void AIRTHRARCRKSP_vidTimer(void);


#endif /* AIRTHRARCRKSP_L_H */

/*-------------------------------- end of file -------------------------------*/
