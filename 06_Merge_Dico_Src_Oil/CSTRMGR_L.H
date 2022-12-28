/***************************************************************************
;**
;** FILE NAME      : CSTRMGR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRMGR_L_H
#define CSTRMGR_L_H

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

extern const uint8  CSTRMGR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CSTRMGR_cdn_rco_ctld;
extern boolean CSTRMGR_open_loop_min_purge_req;
extern boolean Demande_purge_dormant_banc;
extern boolean Demande_purge_dormant_nom;
extern boolean Demande_purge_dormant_raw;
extern uint8 Rco_demande_purge_banc;
extern uint8 Rco_demande_purge_ctld;
extern uint8 Rco_demande_purge_nom;
extern uint16 Cpc_control_purge_ratio;
extern uint16 Cpc_purge_ratio_step;
extern uint16 CSTRMGR_u16EffectiveArea;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CSTRMGR_vidCalcRcoDemandPurge(void);
void CSTRMGR_vidCalcRcoPurgeApplique(void);
void CSTRMGR_vidConsolidation(void);
void CSTRMGR_vidFullLoadTrans(void);
void CSTRMGR_vidGsmPurgeClosingTrans(void);
void CSTRMGR_vidInit(void);
void CSTRMGR_vidInitOutput(void);
void CSTRMGR_vidLambdaPurgeClosTrans(void);
void CSTRMGR_vidMgr(void);
void CSTRMGR_vidNormalBoundingTrans(void);
void CSTRMGR_vidOutputInterface(void);
void CSTRMGR_vidPurgeBenchMod(void);
void CSTRMGR_vidPurgeClosedTrans(void);
void CSTRMGR_vidPurgeControlState(void);
void CSTRMGR_vidPurgeHoldingTrans(void);
void CSTRMGR_vidPurgeMinTrans(void);
void CSTRMGR_vidPurgeNormalMod(void);


#endif /* CSTRMGR_L_H */

/*-------------------------------- end of file -------------------------------*/
