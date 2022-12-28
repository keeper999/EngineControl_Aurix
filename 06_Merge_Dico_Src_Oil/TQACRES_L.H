/***************************************************************************
;**
;** FILE NAME      : TQACRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQACRES_L_H
#define TQACRES_L_H

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

/* enum st18 */
#define HORS_RESERVE                      1
#define ATTENTE_EMBRAYAGE                 2
#define DEFAUT_SEQUENCE_EMBRAYAGE         4
#define ATTENTE_DEBRAYAGE                 8
#define MAINTIEN_RESERVE                  16
/*extern uint8 TQACRES_StActual_Status;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  TQACRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 TQACRES_StActual_Status;
extern boolean Ext_bACCluAuth_prev;
extern boolean TQACRES_bTqRes_bCdnACRes_Prev;
extern boolean TqRes_bAcvOptmTqACRes;
extern boolean TqRes_bCdnAC3CluAuth_MP;
extern boolean TqRes_bCdnAC3Res;
extern boolean TqRes_bCdnAC4Res;
extern boolean TqRes_bCdnACRes;
extern boolean TqRes_bCdnNEngFrzAC_MP;
extern boolean TqRes_bCdnPwrFrzAC_MP;
extern boolean TqRes_bDftAC4SwtOn;
extern uint16 TQACRES_u16tiResAC3;
extern uint16 TqRes_tiAC4Res;
extern uint16 TqRes_tiAC4ResTmpMax;
extern uint16 TqRes_tiAcvAC4Res_MP;
extern uint16 TqRes_tiCplAC4Res_MP;
extern uint16 TqRes_tqAC3Res;
extern uint16 TqRes_tqAC4Raw_MP;
extern uint16 TqRes_tqAC4Res;
extern uint16 TqRes_tqACResRaw;
extern uint16 TqRes_tqACResSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQACRES_vidAC3(void);
void TQACRES_vidAC4(void);
void TQACRES_vidActivation_Calcul(void);
void TQACRES_vidCalcul_Reserve(void);
void TQACRES_vidCondition_reserve_AC3(void);
void TQACRES_vidCondition_reserve_AC4(void);
void TQACRES_vidGestion_Type_Clim(void);
void TQACRES_vidInitOutput(void);
void TQACRES_vidPriorite_Fan(void);
void TQACRES_vidReserveCoupleClim(void);
void TQACRES_vidTransAttDebrayage(void);
void TQACRES_vidTransAttEmbrayage(void);
void TQACRES_vidTransDefSeqEmbrayage(void);
void TQACRES_vidTransHorsRes(void);
void TQACRES_vidTransMaintReserve(void);
void TQACRES_vidValeur_reserve_AC3(void);
void TQACRES_vidValeur_reserve_AC4(void);


#endif /* TQACRES_L_H */

/*-------------------------------- end of file -------------------------------*/
