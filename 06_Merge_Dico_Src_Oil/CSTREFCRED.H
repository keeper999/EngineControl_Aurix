/***************************************************************************
;**
;** FILE NAME      : CSTREFCRED.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTREFCRED_H
#define CSTREFCRED_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AV_DR_RALENTI_PURGE_BKPT_MAP_COLS      ( 9 )
#define AV_DR_RALENTI_PURGE_MAP_COLS           ( 9 )
#define CANPURG_CONCHICANLDENGSTOPALLW_T_COLS  ( 5 )
#define CANPURG_CONCLOCANLDENGSTOPALLW_T_COLS  ( 5 )
#define CANPURG_TAIRAMBX_A_COLS                ( 5 )

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

extern const boolean  Cpc_ena_conc_corrn;
extern const uint8  Av_dr_ralenti_purge_bkpt_map[AV_DR_RALENTI_PURGE_BKPT_MAP_COLS];
extern const uint8  CanPurg_tAirAmbX_A[CANPURG_TAIRAMBX_A_COLS];
extern const uint16  Av_dr_ralenti_purge_inc_dec;
extern const uint16  Av_dr_ralenti_purge_map[AV_DR_RALENTI_PURGE_MAP_COLS];
extern const uint16  CanPurg_ConcHiCanLdEngStopAllw_T[CANPURG_CONCHICANLDENGSTOPALLW_T_COLS];
extern const uint16  CanPurg_ConcLoCanLdEngStopAllw_T[CANPURG_CONCLOCANLDENGSTOPALLW_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CanPurg_bEngStopAuth;
extern boolean CanPurg_bTarIdlCanPurg;
extern uint8 Av_dr_ralenti_purge;
extern uint8 CanPurg_facTarIdlCanPurg;
extern uint16 CanPurg_rCanRes;
extern uint16 CanPurg_tqCanRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cstr_EveCrTR_CstrEfcRed(void);
void Cstr_EveRst_CstrEfcRed(void);
void Cstr_SdlFast_CstrEfcRed(void);
void Cstr_SdlSlow_CstrEfcRed(void);


#endif /* CSTREFCRED_H */

/*-------------------------------- end of file -------------------------------*/
