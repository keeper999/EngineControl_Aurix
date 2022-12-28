/***************************************************************************
;**
;** FILE NAME      : TQCNVRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQCNVRES.H"
#include "TQCNVRES_L.H"
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
const uint8  TQCNVRES_u8Inhib = 0;
const uint8  TqRes_spdThrEgdCnvRes_C = 0;
const uint8  TqRes_tiCdnDragRedCnvRes_C = 0;
const uint8  TqRes_tiCdnEgdCnvRes_C = 0;
const uint8  TqRes_tOilGBx_A[TQRES_TOILGBX_A_COLS] = {0};
const sint16  TqRes_tqDecMaxCnvRes_C = 0;
const uint16  TqRes_tqDftValCnvRes_C = 0;
const uint16  TqRes_tqDragRedCnvRes_T[TQRES_TQDRAGREDCNVRES_T_COLS] = {0};
const uint16  TqRes_tqEgdCnvRes_T[TQRES_TQEGDCNVRES_T_COLS] = {0};
const uint16  TqRes_tqIncMaxCnvRes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TQCNVRES_bCdnDragRedPrev;
boolean TQCNVRES_bCdnDragRedPrev1;
boolean TQCNVRES_bEfcBrkPedPrssPrev;
boolean TQCNVRES_bInputRising2Prev;
boolean TQCNVRES_bInputRisingPrev;
boolean TqRes_bCdnBrkDragRed_MP;
boolean TqRes_bCdnDragRedCnvRes;
boolean TqRes_bCdnEgdCnvRes;
boolean TqRes_bCdnGearEgdCnvRes_MP;
boolean TqRes_bCdnSpdEgdCnvRes_MP;
boolean TqRes_bCdnStGBxDragRed_MP;
boolean TqRes_bCdnStGBxEgdCnvRes_MP;
uint8 TQCNVRES_u8DragRedPrev;
uint16 TQCNVRES_u16tiCdn1Cpt;
uint16 TQCNVRES_u16tiCdn2Cpt;
uint16 TqRes_tqCnvRes;
uint16 TqRes_tqCnvResMax_MP;
uint16 TqRes_tqCnvResSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

