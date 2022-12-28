/***************************************************************************
;**
;** FILE NAME      : TQALTRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQALTRES_L_H
#define TQALTRES_L_H

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

extern const uint8  TQALTRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TQALTRES_bCdnAltRes_prev;
extern boolean TqRes_bCdnAltRes;
extern boolean TqRes_bCdnNEngAltRes_MP;
extern uint32 TQALTRES_u32FiltredCoefFilCCPMem;
extern uint32 TQALTRES_u32FiltredCoefFilGapMem;
extern uint8 TqRes_iAltFil_MP;
extern uint8 TqRes_rAltFil_MP;
extern uint16 TQALTRES_u16tiAltCpt;
extern uint16 TqRes_tqAltResGap;
extern uint16 TqRes_tqAltResSat_MP;
extern uint16 TqRes_tqAltResStd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQALTRES_vidCalculReserveALT(void);
void TQALTRES_vidCalculReserveAltGap(void);
void TQALTRES_vidCalculReserveAltICCP(void);
void TQALTRES_vidConditionReserveALT(void);
void TQALTRES_vidInitOutput(void);
void TQALTRES_vidReserveCoupleALT(void);


#endif /* TQALTRES_L_H */

/*-------------------------------- end of file -------------------------------*/
