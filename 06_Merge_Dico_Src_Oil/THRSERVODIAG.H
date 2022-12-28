/***************************************************************************
;**
;** FILE NAME      : THRSERVODIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSERVODIAG_H
#define THRSERVODIAG_H

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

extern const uint8  Thr_VehSpdThdHi_C;
extern const uint8  Thr_VehSpdThdHiDifNeg_C;
extern const uint8  Thr_VehSpdThdHiDifPos_C;
extern const uint8  Thr_VehSpdThdLo_C;
extern const uint8  Thr_VehSpdThdLoDifNeg_C;
extern const uint8  Thr_VehSpdThdLoDifPos_C;
extern const uint8  Tpac_position_error_filter_gain;
extern const uint16  Thr_posnMaxErrHi_C;
extern const uint16  Thr_posnMaxErrHiDifNeg_C;
extern const uint16  Thr_posnMaxErrHiDifPos_C;
extern const uint16  Thr_posnMaxErrLo_C;
extern const uint16  Thr_posnMaxErrLoDifNeg_C;
extern const uint16  Thr_posnMaxErrLoDifPos_C;
extern const uint16  Tpac_integral_Dft_jc_Thd_DifNeg;
extern const uint16  Tpac_integral_Dft_jc_Thd_DifPos;
extern const uint16  Tpac_integral_failure_delay;
extern const uint16  Tpac_integral_failure_Dly_DifNeg;
extern const uint16  Tpac_integral_failure_Dly_DifPos;
extern const uint16  Tpac_integral_failure_jc_thresh;
extern const uint16  Tpac_servo_Dft_detect_Dly_DifNeg;
extern const uint16  Tpac_servo_Dft_detect_Dly_DifPos;
extern const uint16  Tpac_servo_failure_detect_delay;
extern const uint16  Tpac_servo_failure_diag_delay;

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

void Thr_EveClcnServo_Diag(void);
void THRSERVODIAG_vidEntryInit(void);


#endif /* THRSERVODIAG_H */

/*-------------------------------- end of file -------------------------------*/
