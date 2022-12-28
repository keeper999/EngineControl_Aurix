/***************************************************************************
;**
;** FILE NAME      : TCOREGKNK.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TCOREGKNK_H
#define TCOREGKNK_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_FACFILDELTAAGIG_T_COLS           ( 6 )
#define IGSYS_NENG_IGSYSTCOCOLDREQ_A_COLS      ( 6 )

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

extern const boolean  IgSys_bInhIgSysTCoColdReq_C;
extern const sint8  IgSys_agIgDeltaAcvEngColdReq_C;
extern const sint8  IgSys_agIgDeltaInhEngColdReq_C;
extern const uint8  IgSys_facFilDeltaAgIg_T[IGSYS_FACFILDELTAAGIG_T_COLS];
extern const uint16  IgSys_nEng_IgSysTCoColdReq_A[IGSYS_NENG_IGSYSTCOCOLDREQ_A_COLS];
extern const uint16  IgSys_tiEngColdReq_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgSys_SdlFast_TCoRegKnk(void);
void TCOREGKNK_vidEntryInit(void);


#endif /* TCOREGKNK_H */

/*-------------------------------- end of file -------------------------------*/
