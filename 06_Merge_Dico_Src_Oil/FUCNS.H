/***************************************************************************
;**
;** FILE NAME      : FUCNS.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FUCNS_H
#define FUCNS_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXT_PDSTHRMESSI_A_COLS                 ( 16 )
#define FUCNS_MFUREQWOUTPURGEOXC_M_LNS        ( 16 )
#define FUCNS_MFUREQWOUTPURGEOXC_M_COLS        ( 16 )

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

extern const boolean  FuCns_bAcvFuCnsTyp_C;
extern const boolean  FuCns_bRstFuCnsTot_C;
extern const uint8  Conso_carburant_filtre_gain;
extern const uint8  Conso_carburant_inst_filtre_gain;
extern const uint16  Ext_pDsThrMesSI_A[EXT_PDSTHRMESSI_A_COLS];
extern const uint16  FuCns_mFuReqWoutPurgeOxC_M[FUCNS_MFUREQWOUTPURGEOXC_M_LNS][FUCNS_MFUREQWOUTPURGEOXC_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean FuCns_bFuCnsTyp;
extern uint32 FuCns_mFuInjTot;
extern uint8 Consommation_carburant_inst;
extern uint8 FuCns_volFuCnsTot;
extern uint16 Consommation_carburant_horaire;
extern uint16 FuCns_mFuWoutPurgeOxC;
extern uint16 Fuel_used_between_frame;
extern uint16 Fuel_used_not_counted;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Fu_EveInj_FuCns(void);
void Fu_EveRst_FuCns(void);
void Fu_SdlMid_FuCns(void);


#endif /* FUCNS_H */

/*-------------------------------- end of file -------------------------------*/
