/***************************************************************************
;**
;** FILE NAME      : THRSERVODIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRSERVODIAG.H"
#include "THRSERVODIAG_L.H"
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
const uint8  Thr_VehSpdThdHi_C = 0;
const uint8  Thr_VehSpdThdHiDifNeg_C = 0;
const uint8  Thr_VehSpdThdHiDifPos_C = 0;
const uint8  Thr_VehSpdThdLo_C = 0;
const uint8  Thr_VehSpdThdLoDifNeg_C = 0;
const uint8  Thr_VehSpdThdLoDifPos_C = 0;
const uint8  THRSERVODIAG_u8Inhib = 0;
const uint8  Tpac_position_error_filter_gain = 0;
const uint16  Thr_posnMaxErrHi_C = 0;
const uint16  Thr_posnMaxErrHiDifNeg_C = 0;
const uint16  Thr_posnMaxErrHiDifPos_C = 0;
const uint16  Thr_posnMaxErrLo_C = 0;
const uint16  Thr_posnMaxErrLoDifNeg_C = 0;
const uint16  Thr_posnMaxErrLoDifPos_C = 0;
const uint16  Tpac_integral_Dft_jc_Thd_DifNeg = 0;
const uint16  Tpac_integral_Dft_jc_Thd_DifPos = 0;
const uint16  Tpac_integral_failure_delay = 0;
const uint16  Tpac_integral_failure_Dly_DifNeg = 0;
const uint16  Tpac_integral_failure_Dly_DifPos = 0;
const uint16  Tpac_integral_failure_jc_thresh = 0;
const uint16  Tpac_servo_Dft_detect_Dly_DifNeg = 0;
const uint16  Tpac_servo_Dft_detect_Dly_DifPos = 0;
const uint16  Tpac_servo_failure_detect_delay = 0;
const uint16  Tpac_servo_failure_diag_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Enable_servoing_failure_detect;
boolean Thr_bAbsPosnErrORng;
boolean Thr_bCtlrIntORng;
boolean Thr_bDgoORngServo;
boolean Thr_bDgoORngServoDifNeg;
boolean Thr_bDgoORngServoDifPos;
boolean Thr_bMonRunORngServo;
boolean THRSERVODIAG_bAbsPosErrORng_Prev;
boolean THRSERVODIAG_bCtlrIntORng_Prev;
boolean THRSERVODIAG_bCtlrIntORngTimer;
boolean THRSERVODIAG_bCtlrIntORngTimerPr;
boolean THRSERVODIAG_bEnaFailDetPrev;
boolean THRSERVODIAG_bIntegralFailOut;
boolean THRSERVODIAG_bIntegralFailOut2;
boolean THRSERVODIAG_bposnMaxErrTimer;
boolean THRSERVODIAG_bposnMaxErrTimerPrv;
boolean THRSERVODIAG_bServoFailDetecOut2;
boolean THRSERVODIAG_bServoFailDetectOut;
boolean THRSERVODIAG_bServoFailDiagOut;
boolean Tpac_bClCtlErrSignPos;
uint32 THRSERVODIAG_u32FiltPosErrorMem;
uint8 THRSERVODIAG_u8TpacThrCtrlStPrev;
uint16 THRSERVODIAG_u16IntegrFailTemp2;
uint16 THRSERVODIAG_u16IntegrFailTempo;
uint16 THRSERVODIAG_u16PosnMaxErrThd;
uint16 THRSERVODIAG_u16ServFailDetTemp2;
uint16 THRSERVODIAG_u16ServFailDetTempo;
uint16 THRSERVODIAG_u16ServFailDiagTemp;
uint16 Tpac_filtered_position_error_sc;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

