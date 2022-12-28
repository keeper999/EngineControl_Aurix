/***************************************************************************
;**
;** FILE NAME      : INAIRFLOWDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INAIRFLOWDIAG_H
#define INAIRFLOWDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRSYS_PDSTHRLEAK1_T_COLS              ( 9 )
#define AIRSYS_PDSTHRLEAK2_T_COLS              ( 9 )
#define ENGM_MFTOTEXCOR_A_COLS                 ( 9 )

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

extern const uint8  AirSys_rClsThdThr_C;
extern const uint8  AirSys_rpDsUsThr_C;
extern const sint16  AirSys_tCoMes_C;
extern const uint16  AirSys_nEng_C;
extern const uint16  AirSys_pDsThrLeak1_T[AIRSYS_PDSTHRLEAK1_T_COLS];
extern const uint16  AirSys_pDsThrLeak2_T[AIRSYS_PDSTHRLEAK2_T_COLS];
extern const uint16  AirSys_pDsThrLeak3_C;
extern const uint16  AirSys_pDsThrLeak4_C;
extern const uint16  EngM_mfTotExCor_A[ENGM_MFTOTEXCOR_A_COLS];

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

void AirSys_EveRst_InAirflowDiag(void);
void AirSys_SdlMid_InAirflowDiag(void);


#endif /* INAIRFLOWDIAG_H */

/*-------------------------------- end of file -------------------------------*/
