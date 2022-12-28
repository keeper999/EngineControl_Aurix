/***************************************************************************
;**
;** FILE NAME      : TQCNVRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCNVRES_H
#define TQCNVRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_TOILGBX_A_COLS                   ( 8 )
#define TQRES_TQDRAGREDCNVRES_T_COLS           ( 8 )
#define TQRES_TQEGDCNVRES_T_COLS               ( 8 )

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

extern const uint8  TqRes_spdThrEgdCnvRes_C;
extern const uint8  TqRes_tiCdnDragRedCnvRes_C;
extern const uint8  TqRes_tiCdnEgdCnvRes_C;
extern const uint8  TqRes_tOilGBx_A[TQRES_TOILGBX_A_COLS];
extern const sint16  TqRes_tqDecMaxCnvRes_C;
extern const uint16  TqRes_tqDftValCnvRes_C;
extern const uint16  TqRes_tqDragRedCnvRes_T[TQRES_TQDRAGREDCNVRES_T_COLS];
extern const uint16  TqRes_tqEgdCnvRes_T[TQRES_TQEGDCNVRES_T_COLS];
extern const uint16  TqRes_tqIncMaxCnvRes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqCnvRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCNVRES_vidEntry_10ms(void);
void TQCNVRES_vidEntryInit(void);


#endif /* TQCNVRES_H */

/*-------------------------------- end of file -------------------------------*/
