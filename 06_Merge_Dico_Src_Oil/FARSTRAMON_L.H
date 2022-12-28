/***************************************************************************
;**
;** FILE NAME      : FARSTRAMON_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FARSTRAMON_L_H
#define FARSTRAMON_L_H

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

/* enum st40 */
#define EGR_INIT                          0
#define EGR_RESET                         1
#define EGR_COUNTER_DEC                   2
#define EGR_REINIT_COUNTER                4
#define GSM_EGR_AUTORISATION              8
#define GSM_NON_EFFECT_EGR                32
/*extern uint8 FARSTRAMON_stEGREffect;*/

/* enum st41 */
#define PURGE_INIT                        0
#define GSM_PURGE_CANISTER_RESET          2
#define PURGE_COUNTER_DEC                 4
#define GSM_PURGE_AUTORISATION            8
#define SLOW_CLOSING_DELAY                16
#define FAST_CLOSING_DELAY                32
/*extern uint8 FARSTRAMON_stPurge;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  FARSTRAMON_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 FARSTRAMON_stEGREffect;
extern uint8 FARSTRAMON_stPurge;
extern boolean Cstr_bDmdClosePurgImdtTurbMod;
extern boolean Cstr_bDmdClosePurgTurbMod;
extern boolean Cstr_bEnaPurgEngStrtRstrt;
extern boolean CstrMgr_bInhCstrTranGasMod;
extern boolean FARSTRAMON_bCounter_On_Off;
extern boolean GMS_bAuthDiagEGR;
extern boolean GMS_bAuthDiagEGRHys;
extern boolean Gsm_cpc_no_effect;
extern boolean Gsm_egr_no_effect;
extern boolean GSM_Misf_OBD_fail;
extern uint8 Cstr_ctTiEnaPurgEng;
extern uint8 Cstr_ctTiEnaPurgEngPrev;
extern uint8 StraMon_tiDlyAftDiagItrsv;
extern uint16 FARSTRAMON_u16AntiRebFilterCnt;
extern uint16 Gsm_cpc_no_effect_count;
extern uint16 Gsm_egr_no_effect_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FARSTRAMON_vidAuthdiagEGR(void);
void FARSTRAMON_vidEGREffect(void);
void FARSTRAMON_vidEnableManagement(void);
void FARSTRAMON_vidFiltration(void);
void FARSTRAMON_vidInhCstrTranGasMod(void);
void FARSTRAMON_vidIninTmrEnaPurgEng(void);
void FARSTRAMON_vidInitOutput(void);
void FARSTRAMON_vidMngClsPurge(void);
void FARSTRAMON_vidPurgCloseNoTurbMod(void);
void FARSTRAMON_vidPurgeCloseTurbMod(void);
void FARSTRAMON_vidPurgeTurbGasMod(void);
void FARSTRAMON_vidReqClsPurg(void);
void FARSTRAMON_vidTmrEnaPurgEng(void);


#endif /* FARSTRAMON_L_H */

/*-------------------------------- end of file -------------------------------*/
