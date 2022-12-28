/***************************************************************************
;**
;** FILE NAME      : CSTREFCRED_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTREFCRED_L_H
#define CSTREFCRED_L_H

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

extern const uint8  CSTREFCRED_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CanPurg_bEngStopInh;
extern uint16 Av_dr_ralenti_purge_raw;
extern uint16 Av_dr_ralenti_purge_sp;
extern uint16 CanPurg_ConcHiCanLdEngStopAllw;
extern uint16 CanPurg_ConcLoCanLdEngStopAllw;
extern uint16 Cpc_fuel_vapour_conc_corrd;
extern uint16 Cpc_fuel_vapour_conc_finale;
extern uint16 CSTREFCRED_u16FilterSlewRate;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CSTREFCRED_vidClcn(void);
void CSTREFCRED_vidClcnIdlReq(void);
void CSTREFCRED_vidEfcRedClcn(void);
void CSTREFCRED_vidInhApplySlewRate(void);
void CSTREFCRED_vidIni(void);
void CSTREFCRED_vidIniIdlReq(void);
void CSTREFCRED_vidTarClcn(void);


#endif /* CSTREFCRED_L_H */

/*-------------------------------- end of file -------------------------------*/
