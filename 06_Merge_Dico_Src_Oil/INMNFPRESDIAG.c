/***************************************************************************
;**
;** FILE NAME      : INMNFPRESDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INMNFPRESDIAG.H"
#include "INMNFPRESDIAG_L.H"
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
const boolean  AirPres_bAcvDftThrCoh_C = 0;
const uint8  AirPres_noGrdDiagPresDsThr_C = 0;
const uint8  AirPres_pDsThrThdDifMax3_C = 0;
const uint8  AirPres_pDsThrThdGrd_C = 0;
const uint8  AirPres_rOpThdDifMax_C = 0;
const uint8  AirPres_rOpThdMax_C = 0;
const uint8  AirPres_rOpThdMin_C = 0;
const uint8  AirPres_rOpThr_T[AIRPRES_ROPTHR_T_COLS] = {0};
const uint8  AirPres_rPresThrBSVThd_C = 0;
const uint8  AirPres_rPresThrMaxThd_C = 0;
const uint8  AirPres_rThrPres_rBSV_A[AIRPRES_RTHRPRES_RBSV_A_COLS] = {0};
const uint8  AirPres_tiDly_CanPurg_C = 0;
const uint8  Crank_to_run_water_temp_thres = 0;
const uint8  Diag_map_bounds_lower_throttle[DIAG_MAP_BOUNDS_LOWER_THROTTLE_COLS] = {0};
const uint8  Diag_map_bounds_upper_throttle[DIAG_MAP_BOUNDS_UPPER_THROTTLE_COLS] = {0};
const uint8  Diag_map_under_threshold = 0;
const uint8  Diag_map_upper_threshold = 0;
const uint8  Diag_press_stall_to_run_delay = 0;
const uint8  Duree_arret_moteur_mini_diag = 0;
const uint8  INMNFPRESDIAG_u8Inhib = 0;
const uint16  AirPres_arThr_rOpThr_A[AIRPRES_ARTHR_ROPTHR_A_COLS] = {0};
const uint16  AirPres_nEngThdMin_C = 0;
const uint16  AirPres_nOpThdMax_nEng_C = 0;
const uint16  AirPres_nOpThdMin_nEng_C = 0;
const uint16  AirPres_pDsThrThdDifMax1_C = 0;
const uint16  AirPres_pDsThrThdORngMax_C = 0;
const uint16  AirPres_pDsThrThdORngMin_C = 0;
const uint16  AirPres_rBSV_T[AIRPRES_RBSV_T_COLS] = {0};
const uint16  AirPres_rBSVCon_C = 0;
const uint16  Diag_map_bounds_lower_pressure = 0;
const uint16  Diag_map_bounds_upper_pressure = 0;
const uint16  Diag_pressure_min_decrease = 0;
const uint16  Pressure_in_full_load_max_thresh = 0;
const uint16  Pressure_in_full_load_min_thresh = 0;
const uint16  Pressure_in_stall_max_threshold = 0;
const uint16  Pressure_in_stall_min_threshold = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirPres_bAuthUpdPres;
boolean AirPres_bCanPurgOk;
boolean AirPres_bDetFirstRun;
boolean AirPres_bDetFirstSt;
boolean AirPres_bDetFirstStTCk;
boolean AirPres_bDgoCrkCoh_pDsThr;
boolean AirPres_bDgoFldCoh_pDsThr;
boolean AirPres_bDgoGrd_pDsThr;
boolean AirPres_bDgoORng_pDsThr;
boolean AirPres_bDgoStabCoh_pDsThr;
boolean AirPres_bDgoStallCoh_pDsThr;
boolean AirPres_bDgoThrCoh_pDsThr;
boolean AirPres_bDiagAftStall;
boolean AirPres_bMonRunCrkCoh_pDsThr;
boolean AirPres_bMonRunFldCoh_pDsThr;
boolean AirPres_bMonRunGrd_pDsThr;
boolean AirPres_bMonRunORng_pDsThr;
boolean AirPres_bMonRunStabCoh_pDsThr;
boolean AirPres_bMonRunStallCoh_pDsThr;
boolean AirPres_bMonRunThrCoh_pDsThr;
boolean AirPres_bMonWaitCrkCoh_pDsThr;
boolean INMNFPRESDIAG_bAirPresDgoStabCoh;
boolean INMNFPRESDIAG_bDetFirstStPrev;
boolean INMNFPRESDIAG_bDiagActIndicator;
boolean INMNFPRESDIAG_bWkuMainPrev;
uint8 AirPres_idxGrdDiagPresDsThr;
uint8 AirPres_pDsThrDif;
uint8 AirPres_pDsThrDif3;
uint8 AirPres_rOpDif;
uint8 AirPres_rOpMem;
uint8 AirPres_rPresThrSat;
uint8 AirPres_tiDly_CanPurg;
uint8 Diag_map_pressure_counter;
uint8 Diag_press_stall_to_run_counter;
uint16 AirPres_Manifold_PresAcq;
uint16 AirPres_pAirExtMem;
uint16 AirPres_pDsThrFldMem;
uint16 AirPres_pDsThrOpMem;
uint16 AirPres_pFrzDsThrDiagGrd;
uint16 AirPres_rBSVClc;
uint16 AirPres_sThrClc;
uint16 Diag_min_pressure_in_crank;
uint16 Ext_pAirExtStrt;
uint16 Ext_pDsThrStrt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

