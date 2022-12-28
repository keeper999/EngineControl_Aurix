/***************************************************************************
;**
;** FILE NAME      : FCTDIAGTRBPRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FCTDIAGTRBPRES_H
#define FCTDIAGTRBPRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRPRES_NDIFPUSTHR_A_COLS              ( 8 )
#define AIRPRES_NENG_PAIREXTMES_T_COLS         ( 8 )
#define AIRPRES_PAIREXTMES_A_COLS              ( 8 )
#define AIRPRES_PUSTHRMAXDIAG_T_COLS           ( 8 )
#define AIRPRES_TIDIFPUSTHR_T_COLS             ( 8 )
#define EXT_PAIREXTMESSI_A_COLS                ( 8 )

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

extern const uint8  AirPres_rClsThdThr_C;
extern const uint8  AirPres_tiBoostPresClCtlAcv_C;
extern const uint8  AirPres_tiDifpUsThr_T[AIRPRES_TIDIFPUSTHR_T_COLS];
extern const uint8  AirPres_tiUsThrPlaus_AcvIdlCtl_C;
extern const sint16  AirPres_pUsThrNatOfs_C;
extern const uint16  AirPres_agDeltaVlvPosnThd_C;
extern const uint16  AirPres_nDifpUsThr_A[AIRPRES_NDIFPUSTHR_A_COLS];
extern const uint16  AirPres_nEng_pAirExtMes_T[AIRPRES_NENG_PAIREXTMES_T_COLS];
extern const uint16  AirPres_pAirExtMes_A[AIRPRES_PAIREXTMES_A_COLS];
extern const uint16  AirPres_pAirExtMes_C;
extern const uint16  AirPres_pAirExtMes1_C;
extern const uint16  AirPres_pAirExtMes2_C;
extern const uint16  AirPres_pUsThrBoostPlaus_C;
extern const uint16  AirPres_pUsThrIdlPlaus_C;
extern const uint16  AirPres_pUsThrMaxDiag_T[AIRPRES_PUSTHRMAXDIAG_T_COLS];
extern const uint16  AirPres_pUsThrNegDif1_C;
extern const uint16  AirPres_pUsThrNegDif2_C;
extern const uint16  AirPres_pUsThrNegDifSen_C;
extern const uint16  AirPres_pUsThrNegDifVlvPosn1_C;
extern const uint16  AirPres_pUsThrNegDifVlvPosn2_C;
extern const uint16  AirPres_pUsThrPosDif1_C;
extern const uint16  AirPres_pUsThrPosDif2_C;
extern const uint16  AirPres_pUsThrPosDifSen_C;
extern const uint16  Ext_pAirExtMesSI_A[EXT_PAIREXTMESSI_A_COLS];

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

void AirPres_Eve14TDC_DiagTrbPres(void);
void AirPres_EveRst_FctDiagTrbPres(void);
void AirPres_SdlMid_FctDiagTrbPres(void);


#endif /* FCTDIAGTRBPRES_H */

/*-------------------------------- end of file -------------------------------*/
