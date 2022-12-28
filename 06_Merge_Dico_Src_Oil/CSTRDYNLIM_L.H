/***************************************************************************
;**
;** FILE NAME      : CSTRDYNLIM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRDYNLIM_L_H
#define CSTRDYNLIM_L_H

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

extern const uint8  CSTRDYNLIM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CSTRDYNLIM_bGsmPurgeClosingEntry;
extern uint8 Cpc_fuel_constraint_max;
extern uint8 Cpc_purge_fuel_ratio;
extern uint8 CSTRDYNLIM_u8CpcPurgCtrlStatPrev;
extern uint16 Cpc_air_constraint_max_mfr;
extern uint16 Cpc_fpw_constraint_max_mfr;
extern uint16 Cpc_fuel_constraint_max_mfr;
extern uint16 Cpc_lambda_constraint_max_mfr;
extern uint16 Cpc_max_air_mfr;
extern uint16 Cpc_max_purge_ratio;
extern uint16 Cpc_min_inj_time_fuel_flow_rate;
extern uint16 Cpc_purge_rate_gain;
extern uint16 Cpc_purge_rate_gain_stt;
extern uint16 Required_fuel_flow_rate_si;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CSTRDYNLIM_vidAirMaxCta(void);
void CSTRDYNLIM_vidCurPurgeRat(void);
void CSTRDYNLIM_vidCurRat(void);
void CSTRDYNLIM_vidDynLimClc(void);
void CSTRDYNLIM_vidFuMaxCta(void);
void CSTRDYNLIM_vidInitOutput(void);
void CSTRDYNLIM_vidInjMinCta(void);
void CSTRDYNLIM_vidLsclCta(void);
void CSTRDYNLIM_vidNullRat(void);
void CSTRDYNLIM_vidPrgDecRat(void);
void CSTRDYNLIM_vidPrgIncRat(void);
void CSTRDYNLIM_vidPurgeGblCta(void);


#endif /* CSTRDYNLIM_L_H */

/*-------------------------------- end of file -------------------------------*/
