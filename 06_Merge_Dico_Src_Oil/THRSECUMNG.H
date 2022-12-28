/***************************************************************************
;**
;** FILE NAME      : THRSECUMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSECUMNG_H
#define THRSECUMNG_H

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

/* enum st21 */
#define SSM_THROTTLE_POS_NORMAL           1
#define SSM_THROTTLE_POS_SINGLE_1         2
#define SSM_THROTTLE_POS_SINGLE_2         4
#define SSM_THROTTLE_POS_FAILURE          8
/*extern uint8 Ssm_throttle_pos_sensing_status;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Ssm_throt_pos_failure_on_coh_inh;
extern const boolean  Tpac_pos_filt_med_inh;
extern const uint16  Ssm_default_closed_throttle_pos;
extern const uint16  Ssm_default_limp_home_pos;
extern const uint16  Ssm_default_open_throttle_pos;
extern const uint16  Ssm_default_throttle_position;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Ssm_throttle_pos_sensing_status;
extern uint8 Position_papillon;
extern uint16 Ssm_closed_throttle_pos;
extern uint16 Ssm_limp_home_throttle_pos;
extern uint16 Ssm_open_throttle_pos;
extern uint16 Ssm_raw_filt_throttle_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveClcnServo_SecuMng(void);
void Thr_EveFRMUpd_SecuMng(void);
void Thr_EveRst_SecuMng(void);
void Thr_EveStoreLih_SecuMng(void);


#endif /* THRSECUMNG_H */

/*-------------------------------- end of file -------------------------------*/
