/***************************************************************************
;**
;** FILE NAME      : PRESDIAGCOH.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PRESDIAGCOH_H
#define PRESDIAGCOH_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DGSEN_TIENGMODSTPTHD_T_COLS            ( 8 )
#define DGSEN_TOIL_A_COLS                      ( 8 )
#define MOTEUR_ARRETE                     1

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

extern const uint16  DgSen_pDifMaxAirExtOilThd_C;
extern const uint16  DgSen_pDifMaxAirExtUsThrThd_C;
extern const uint16  DgSen_pDifMaxOilAirExtThd_C;
extern const uint16  DgSen_pDifMaxOilUsThrThd_C;
extern const uint16  DgSen_pDifMaxUsThrAirExtThd_C;
extern const uint16  DgSen_pDifMaxUsThrOilThd_C;
extern const uint16  DgSen_tiEngModStpThd_T[DGSEN_TIENGMODSTPTHD_T_COLS];
extern const uint16  DgSen_tOil_A[DGSEN_TOIL_A_COLS];
extern const uint16  Oil_tiDlyDriftNeg_pAirExtThd_C;
extern const uint16  Oil_tiDlyDriftNeg_pOilThd_C;
extern const uint16  Oil_tiDlyDriftNeg_pUsThrFilThd_C;
extern const uint16  Oil_tiDlyDriftPos_pAirExtThd_C;
extern const uint16  Oil_tiDlyDriftPos_pOilThd_C;
extern const uint16  Oil_tiDlyDriftPos_pUsThrFilThd_C;

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

void Oil_EveKOn_PresDiagCoh(void);
void Oil_EveRst_PresDiagCoh(void);
void Oil_SdlFast_PresDiagCoh(void);


#endif /* PRESDIAGCOH_H */

/*-------------------------------- end of file -------------------------------*/
