/***************************************************************************
;**
;** FILE NAME      : TQSTGPMPRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQSTGPMPRES_L_H
#define TQSTGPMPRES_L_H

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

extern const uint8  TQSTGPMPRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqRes_bCdnAgWhlStgPmpRes;
extern boolean TqRes_bCdnEngRunStgPmpRes_MP;
extern boolean TqRes_bCdnSpdStgPmpRes_MP;
extern boolean TqRes_bCdnStgPmpRes;
extern boolean TqRes_bCdnStgPmpStgPmpRes;
extern boolean TqRes_bCdnTCoStgPmpRes_MP;
extern boolean TQSTGPMPRES_bRateLimiterPrevEna;
extern boolean TQSTGPMPRES_bTurnOffDelayIn;
extern boolean TQSTGPMPRES_bTurnOffDelayInPrev;
extern uint32 TQSTGPMPRES_u32FiltredCoefFilMem;
extern uint8 TqRes_agvStrWhlFilStgPmpRes_MP;
extern sint16 TqRes_agStrWhlFilStgPmpRes_MP;
extern uint16 TqRes_tqStgPmpResMax_MP;
extern uint16 TqRes_tqStgPmpResSat_MP;
extern uint16 TQSTGPMPRES_u16tiStgPmpThrCpt;
extern uint16 TQSTGPMPRES_u16tiStgPmpThrCpt1;
extern sint32 TQSTGPMPRES_s32FiltredCoefFilMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQSTGPMPRES_vidCalculReserve(void);
void TQSTGPMPRES_vidConditionDA(void);
void TQSTGPMPRES_vidConditionReserve(void);
void TQSTGPMPRES_vidConditionVolant(void);
void TQSTGPMPRES_vidInitOutput(void);
void TQSTGPMPRES_vidReserveDeCoupleDA(void);


#endif /* TQSTGPMPRES_L_H */

/*-------------------------------- end of file -------------------------------*/
