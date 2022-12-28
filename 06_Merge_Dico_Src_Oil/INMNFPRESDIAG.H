/***************************************************************************
;**
;** FILE NAME      : INMNFPRESDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INMNFPRESDIAG_H
#define INMNFPRESDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRPRES_ARTHR_ROPTHR_A_COLS            ( 16 )
#define AIRPRES_RBSV_T_COLS                    ( 13 )
#define AIRPRES_ROPTHR_T_COLS                  ( 16 )
#define AIRPRES_RTHRPRES_RBSV_A_COLS           ( 13 )
#define DIAG_MAP_BOUNDS_LOWER_THROTTLE_COLS    ( 16 )
#define DIAG_MAP_BOUNDS_UPPER_THROTTLE_COLS    ( 16 )

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

extern const boolean  AirPres_bAcvDftThrCoh_C;
extern const uint8  AirPres_noGrdDiagPresDsThr_C;
extern const uint8  AirPres_pDsThrThdDifMax3_C;
extern const uint8  AirPres_pDsThrThdGrd_C;
extern const uint8  AirPres_rOpThdDifMax_C;
extern const uint8  AirPres_rOpThdMax_C;
extern const uint8  AirPres_rOpThdMin_C;
extern const uint8  AirPres_rOpThr_T[AIRPRES_ROPTHR_T_COLS];
extern const uint8  AirPres_rPresThrBSVThd_C;
extern const uint8  AirPres_rPresThrMaxThd_C;
extern const uint8  AirPres_rThrPres_rBSV_A[AIRPRES_RTHRPRES_RBSV_A_COLS];
extern const uint8  AirPres_tiDly_CanPurg_C;
extern const uint8  Crank_to_run_water_temp_thres;
extern const uint8  Diag_map_bounds_lower_throttle[DIAG_MAP_BOUNDS_LOWER_THROTTLE_COLS];
extern const uint8  Diag_map_bounds_upper_throttle[DIAG_MAP_BOUNDS_UPPER_THROTTLE_COLS];
extern const uint8  Diag_map_under_threshold;
extern const uint8  Diag_map_upper_threshold;
extern const uint8  Diag_press_stall_to_run_delay;
extern const uint8  Duree_arret_moteur_mini_diag;
extern const uint16  AirPres_arThr_rOpThr_A[AIRPRES_ARTHR_ROPTHR_A_COLS];
extern const uint16  AirPres_nEngThdMin_C;
extern const uint16  AirPres_nOpThdMax_nEng_C;
extern const uint16  AirPres_nOpThdMin_nEng_C;
extern const uint16  AirPres_pDsThrThdDifMax1_C;
extern const uint16  AirPres_pDsThrThdORngMax_C;
extern const uint16  AirPres_pDsThrThdORngMin_C;
extern const uint16  AirPres_rBSV_T[AIRPRES_RBSV_T_COLS];
extern const uint16  AirPres_rBSVCon_C;
extern const uint16  Diag_map_bounds_lower_pressure;
extern const uint16  Diag_map_bounds_upper_pressure;
extern const uint16  Diag_pressure_min_decrease;
extern const uint16  Pressure_in_full_load_max_thresh;
extern const uint16  Pressure_in_full_load_min_thresh;
extern const uint16  Pressure_in_stall_max_threshold;
extern const uint16  Pressure_in_stall_min_threshold;

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

void AirPres_EveCrTSt_InMnfPresDiag(void);
void AirPres_EveRst_InMnfPresDiag(void);
void AirPres_SdlFast_InMnfPresDiag(void);
void AirPres_SdlMid_InMnfPresDiag(void);


#endif /* INMNFPRESDIAG_H */

/*-------------------------------- end of file -------------------------------*/
