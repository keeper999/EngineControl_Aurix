/***************************************************************************
;**
;** FILE NAME      : TQLNCHRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQLNCHRES_L_H
#define TQLNCHRES_L_H

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

extern const uint8  TQLNCHRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TQLNCHRES_bCdnCluLnchResInPrev;
extern boolean TQLNCHRES_bCdnExtrCluPPrev;
extern boolean TQLNCHRES_bCdnNEngLnchResInPrev;
extern boolean TQLNCHRES_bCdnSpdLnchResInPrev;
extern boolean TQLNCHRES_bRateLimiterSwitchPrev;
extern boolean TqRes_bCdnAccLnchRes_MP;
extern boolean TqRes_bCdnCluLnchRes_MP;
extern boolean TqRes_bCdnLnchRes;
extern boolean TqRes_bCdnNEngLnchRes_MP;
extern boolean TqRes_bCdnSpdLnchRes;
extern boolean TqRes_bCdnSpdLnchRes_MP;
extern uint16 TQLNCHRES_u16tiCluTempo;
extern uint16 TQLNCHRES_u16tiLoCkSpdTempo;
extern uint16 TQLNCHRES_u16tiSpdVehTempo;
extern uint16 TqRes_tqLnchResMax_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQLNCHRES_vidAccPedLnchCdn(void);
void TQLNCHRES_vidCalcul_reserve(void);
void TQLNCHRES_vidCluPedLnchCdn(void);
void TQLNCHRES_vidCondition_decollage(void);
void TQLNCHRES_vidCondition_vitesse(void);
void TQLNCHRES_vidEngRunLnchCdn(void);
void TQLNCHRES_vidInitOutput(void);
void TQLNCHRES_vidReserve_decollage(void);
void TQLNCHRES_vidReserveCplDecollage(void);
void TQLNCHRES_vidSpdVehLnchCdn(void);


#endif /* TQLNCHRES_L_H */

/*-------------------------------- end of file -------------------------------*/
