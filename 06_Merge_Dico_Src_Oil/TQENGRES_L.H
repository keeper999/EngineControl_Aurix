/***************************************************************************
;**
;** FILE NAME      : TQENGRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQENGRES_L_H
#define TQENGRES_L_H

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

extern const uint8  TQENGRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TQENGRES_bNegHysOut;
extern boolean TqRes_bAcvAntIdl;
extern boolean TqRes_bCdnIdlResDyn;
extern uint32 TQENGRES_u32FiltredResAntIdlMem;
extern uint8 TQENGRES_u8ctCdnResDyn_MP_Prev;
extern uint8 TqRes_ctCdnResDyn_MP;
extern uint16 TQENGRES_u16TqDeltaTqStabLoss;
extern uint16 TqRes_rBasResNotSat_MP;
extern uint16 TqRes_tqAntIdl;
extern uint16 TqRes_tqAntIdlRaw;
extern uint16 TqRes_tqIdlResDyn_MP;
extern uint16 TqRes_tqIdlResStat_MP;
extern uint16 TqRes_tqIdlResStatTAir_MP;
extern uint16 TqRes_tqIdlResStatTCo_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQENGRES_vidActResAnticipRalenti(void);
void TQENGRES_vidCalCplResAntiRalenti(void);
void TQENGRES_vidCond_reserve_dyn(void);
void TQENGRES_vidDegradation_de_base(void);
void TQENGRES_vidFilResAnticipRalenti(void);
void TQENGRES_vidInitOutput(void);
void TQENGRES_vidResAnticipRalenti(void);
void TQENGRES_vidReserve_au_ralenti(void);
void TQENGRES_vidReserve_moteur(void);
void TQENGRES_vidTqResTqIdlResStat(void);


#endif /* TQENGRES_L_H */

/*-------------------------------- end of file -------------------------------*/
