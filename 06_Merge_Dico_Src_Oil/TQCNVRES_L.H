/***************************************************************************
;**
;** FILE NAME      : TQCNVRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCNVRES_L_H
#define TQCNVRES_L_H

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

extern const uint8  TQCNVRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TQCNVRES_bCdnDragRedPrev;
extern boolean TQCNVRES_bCdnDragRedPrev1;
extern boolean TQCNVRES_bEfcBrkPedPrssPrev;
extern boolean TQCNVRES_bInputRising2Prev;
extern boolean TQCNVRES_bInputRisingPrev;
extern boolean TqRes_bCdnBrkDragRed_MP;
extern boolean TqRes_bCdnDragRedCnvRes;
extern boolean TqRes_bCdnEgdCnvRes;
extern boolean TqRes_bCdnGearEgdCnvRes_MP;
extern boolean TqRes_bCdnSpdEgdCnvRes_MP;
extern boolean TqRes_bCdnStGBxDragRed_MP;
extern boolean TqRes_bCdnStGBxEgdCnvRes_MP;
extern uint8 TQCNVRES_u8DragRedPrev;
extern uint16 TQCNVRES_u16tiCdn1Cpt;
extern uint16 TQCNVRES_u16tiCdn2Cpt;
extern uint16 TqRes_tqCnvResMax_MP;
extern uint16 TqRes_tqCnvResSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCNVRES_vidCalcul_Reserve(void);
void TQCNVRES_vidCondition_Engagement(void);
void TQCNVRES_vidCondition_Sortie_Rdt(void);
void TQCNVRES_vidInitOutput(void);
void TQCNVRES_vidReserve_Couple_BVA(void);


#endif /* TQCNVRES_L_H */

/*-------------------------------- end of file -------------------------------*/
