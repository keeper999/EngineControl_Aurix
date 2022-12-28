/***************************************************************************
;**
;** FILE NAME      : TQEIPMPRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQEIPMPRES_L_H
#define TQEIPMPRES_L_H

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

extern const uint8  TQEIPMPRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bStHaltElPmpGrp_Prev;
extern boolean TQEIPMPRES_bCdnElPmpResMPPrev;
extern boolean TqRes_bCdnElPmpRes_MP;
extern boolean TqRes_bCdnSpdElPmpGrpRes_MP;
extern boolean TqRes_bCdnStElPmpGrpRes_MP;
extern uint16 TQEIPMPRES_u16ElPmpGrpTempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQEIPMPRES_vidInitOutput(void);
void TQEIPMPRES_vidPmpGrpDelay(void);
void TQEIPMPRES_vidReserve_couple_GEP(void);


#endif /* TQEIPMPRES_L_H */

/*-------------------------------- end of file -------------------------------*/
