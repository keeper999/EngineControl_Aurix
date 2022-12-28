/***************************************************************************
;**
;** FILE NAME      : THRSTOPCLCN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRSTOPCLCN.H"
#include "THRSTOPCLCN_L.H"
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
const boolean  Thr_bInhStopThrLihChk = 0;
const boolean  Tpac_closed_filter_manu_inh = 0;
const uint8  THRSTOPCLCN_u8Inhib = 0;
const uint8  Tpac_closed_filter_gain_neg = 0;
const uint8  Tpac_closed_filter_gain_pos = 0;
const uint8  Tpac_closed_thrusts_air_temp_max = 0;
const uint8  Tpac_closed_thrusts_air_temp_min = 0;
const uint16  Thr_FLrn_posDriftLihMeasThd_C = 0;
const uint16  Thr_posnThrCls1_C = 0;
const uint16  Thr_posnThrCls2_C = 0;
const uint16  Thr_posnThrClsFil1_C = 0;
const uint16  Thr_posnThrClsFil2_C = 0;
const uint16  Thr_posnThrClsRef1_C = 0;
const uint16  Thr_posnThrClsRef2_C = 0;
const uint16  Thr_posnThrLih1_C = 0;
const uint16  Thr_posnThrLih2_C = 0;
const uint16  Thr_posnThrOp1_C = 0;
const uint16  Thr_posnThrOp2_C = 0;
const uint16  Tpac_1_closed_pos_max = 0;
const uint16  Tpac_1_closed_pos_max_rr = 0;
const uint16  Tpac_1_closed_pos_min = 0;
const uint16  Tpac_1_limp_home_max = 0;
const uint16  Tpac_1_limp_home_min = 0;
const uint16  Tpac_1_open_pos_max = 0;
const uint16  Tpac_1_open_pos_min = 0;
const uint16  Tpac_1_open_throttle_pos_cal = 0;
const uint16  Tpac_2_closed_pos_max = 0;
const uint16  Tpac_2_closed_pos_max_rr = 0;
const uint16  Tpac_2_closed_pos_min = 0;
const uint16  Tpac_2_limp_home_max = 0;
const uint16  Tpac_2_limp_home_min = 0;
const uint16  Tpac_2_open_pos_max = 0;
const uint16  Tpac_2_open_pos_min = 0;
const uint16  Tpac_2_open_throttle_pos_cal = 0;
const uint16  Tpac_lhome_to_closed_thrust_cal = 0;
const uint16  Tpac_middle_throttle_pos = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Thr_bDgoClsIdlCtl;
boolean Thr_bDgoEndStopReq1;
boolean Thr_bDgoEndStopReq2;
boolean Thr_bDgoLihReq1;
boolean Thr_bDgoLihReq2;
boolean Thr_bMonRunClsIdlCtl;
boolean Thr_bMonRunEndStopReq1;
boolean Thr_bMonRunEndStopReq2;
boolean Thr_bMonRunLihReq1;
boolean Thr_bMonRunLihReq2;
boolean Thr_bMonWaitClsIdlCtl;
boolean Thr_bMonWaitEndStopReq1;
boolean Thr_bMonWaitEndStopReq2;
boolean Thr_bMonWaitLihReq1;
boolean Thr_bMonWaitLihReq2;
boolean Thr_FLrn_bAcv_PwrOn;
boolean Tpac_1_ChkLih_dft;
boolean Tpac_1_closed_pos_dft;
boolean Tpac_1_Lih_dft;
boolean Tpac_1_open_pos_dft;
boolean Tpac_2_ChkLih_dft;
boolean Tpac_2_closed_pos_dft;
boolean Tpac_2_Lih_dft;
boolean Tpac_2_open_pos_dft;
boolean Tpac_throttle_locked;
uint32 THRSTOPCLCN_u32ThrotFiltPosMem1;
uint32 THRSTOPCLCN_u32ThrotFiltPosMem2;
uint16 THRSTOPCLCN_u16Tps1RawPosPrev1;
uint16 THRSTOPCLCN_u16Tps1RawPosPrev2;
uint16 THRSTOPCLCN_u16Tps2RawPosPrev1;
uint16 THRSTOPCLCN_u16Tps2RawPosPrev2;
uint16 Tpac_1_closed_throttle_pos_prec;
uint16 Tpac_1_filt_filt_position;
uint16 Tpac_1_limp_home_pos_prec;
uint16 Tpac_1_limp_home_pos_temp;
uint16 Tpac_1_max_measured_position;
uint16 Tpac_1_min_measured_position;
uint16 Tpac_2_closed_throttle_pos_prec;
uint16 Tpac_2_filt_filt_position;
uint16 Tpac_2_limp_home_pos_prec;
uint16 Tpac_2_limp_home_pos_temp;
uint16 Tpac_2_max_measured_position;
uint16 Tpac_2_min_measured_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

