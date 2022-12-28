/***************************************************************************
;**
;** FILE NAME      : THRSTOPCLCN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSTOPCLCN_H
#define THRSTOPCLCN_H

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

extern const boolean  Thr_bInhStopThrLihChk;
extern const boolean  Tpac_closed_filter_manu_inh;
extern const uint8  Tpac_closed_filter_gain_neg;
extern const uint8  Tpac_closed_filter_gain_pos;
extern const uint8  Tpac_closed_thrusts_air_temp_max;
extern const uint8  Tpac_closed_thrusts_air_temp_min;
extern const uint16  Thr_FLrn_posDriftLihMeasThd_C;
extern const uint16  Thr_posnThrCls1_C;
extern const uint16  Thr_posnThrCls2_C;
extern const uint16  Thr_posnThrClsFil1_C;
extern const uint16  Thr_posnThrClsFil2_C;
extern const uint16  Thr_posnThrClsRef1_C;
extern const uint16  Thr_posnThrClsRef2_C;
extern const uint16  Thr_posnThrLih1_C;
extern const uint16  Thr_posnThrLih2_C;
extern const uint16  Thr_posnThrOp1_C;
extern const uint16  Thr_posnThrOp2_C;
extern const uint16  Tpac_1_closed_pos_max;
extern const uint16  Tpac_1_closed_pos_max_rr;
extern const uint16  Tpac_1_closed_pos_min;
extern const uint16  Tpac_1_limp_home_max;
extern const uint16  Tpac_1_limp_home_min;
extern const uint16  Tpac_1_open_pos_max;
extern const uint16  Tpac_1_open_pos_min;
extern const uint16  Tpac_1_open_throttle_pos_cal;
extern const uint16  Tpac_2_closed_pos_max;
extern const uint16  Tpac_2_closed_pos_max_rr;
extern const uint16  Tpac_2_closed_pos_min;
extern const uint16  Tpac_2_limp_home_max;
extern const uint16  Tpac_2_limp_home_min;
extern const uint16  Tpac_2_open_pos_max;
extern const uint16  Tpac_2_open_pos_min;
extern const uint16  Tpac_2_open_throttle_pos_cal;
extern const uint16  Tpac_lhome_to_closed_thrust_cal;
extern const uint16  Tpac_middle_throttle_pos;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_FLrn_bAcv_PwrOn;
extern boolean Tpac_throttle_locked;
extern uint16 Tpac_1_filt_filt_position;
extern uint16 Tpac_2_filt_filt_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveChkLih_MngServo_ThrStopClcn(void);
void Thr_EveClcnServo_StopClcn(void);
void Thr_EveIniLrnLih_StopClcn(void);
void Thr_EveIniStop_MngServo(void);
void Thr_EveRst_StopClcn(void);
void Thr_EveRstThr_stopClcn(void);
void Thr_EveStoreHiStop_MngServo(void);
void Thr_EveStoreLih_StopClcn(void);
void Thr_EveStoreLoStop_MngServo(void);


#endif /* THRSTOPCLCN_H */

/*-------------------------------- end of file -------------------------------*/
