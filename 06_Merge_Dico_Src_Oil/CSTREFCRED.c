/***************************************************************************
;**
;** FILE NAME      : CSTREFCRED.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CSTREFCRED.H"
#include "CSTREFCRED_L.H"
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
const boolean  Cpc_ena_conc_corrn = 0;
const uint8  Av_dr_ralenti_purge_bkpt_map[AV_DR_RALENTI_PURGE_BKPT_MAP_COLS] = {0};
const uint8  CanPurg_tAirAmbX_A[CANPURG_TAIRAMBX_A_COLS] = {0};
const uint8  CSTREFCRED_u8Inhib = 0;
const uint16  Av_dr_ralenti_purge_inc_dec = 0;
const uint16  Av_dr_ralenti_purge_map[AV_DR_RALENTI_PURGE_MAP_COLS] = {0};
const uint16  CanPurg_ConcHiCanLdEngStopAllw_T[CANPURG_CONCHICANLDENGSTOPALLW_T_COLS] = {0};
const uint16  CanPurg_ConcLoCanLdEngStopAllw_T[CANPURG_CONCLOCANLDENGSTOPALLW_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CanPurg_bEngStopAuth;
boolean CanPurg_bEngStopInh;
boolean CanPurg_bTarIdlCanPurg;
uint8 Av_dr_ralenti_purge;
uint8 CanPurg_facTarIdlCanPurg;
uint16 Av_dr_ralenti_purge_raw;
uint16 Av_dr_ralenti_purge_sp;
uint16 CanPurg_ConcHiCanLdEngStopAllw;
uint16 CanPurg_ConcLoCanLdEngStopAllw;
uint16 CanPurg_rCanRes;
uint16 CanPurg_tqCanRes;
uint16 Cpc_fuel_vapour_conc_corrd;
uint16 Cpc_fuel_vapour_conc_finale;
uint16 CSTREFCRED_u16FilterSlewRate;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

