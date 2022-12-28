/***************************************************************************
;**
;** FILE NAME      : THRSTOPCLCN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSTOPCLCN_L_H
#define THRSTOPCLCN_L_H

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

extern const uint8  THRSTOPCLCN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bDgoClsIdlCtl;
extern boolean Thr_bDgoEndStopReq1;
extern boolean Thr_bDgoEndStopReq2;
extern boolean Thr_bDgoLihReq1;
extern boolean Thr_bDgoLihReq2;
extern boolean Thr_bMonRunClsIdlCtl;
extern boolean Thr_bMonRunEndStopReq1;
extern boolean Thr_bMonRunEndStopReq2;
extern boolean Thr_bMonRunLihReq1;
extern boolean Thr_bMonRunLihReq2;
extern boolean Thr_bMonWaitClsIdlCtl;
extern boolean Thr_bMonWaitEndStopReq1;
extern boolean Thr_bMonWaitEndStopReq2;
extern boolean Thr_bMonWaitLihReq1;
extern boolean Thr_bMonWaitLihReq2;
extern boolean Tpac_1_ChkLih_dft;
extern boolean Tpac_1_closed_pos_dft;
extern boolean Tpac_1_Lih_dft;
extern boolean Tpac_1_open_pos_dft;
extern boolean Tpac_2_ChkLih_dft;
extern boolean Tpac_2_closed_pos_dft;
extern boolean Tpac_2_Lih_dft;
extern boolean Tpac_2_open_pos_dft;
extern uint32 THRSTOPCLCN_u32ThrotFiltPosMem1;
extern uint32 THRSTOPCLCN_u32ThrotFiltPosMem2;
extern uint16 THRSTOPCLCN_u16Tps1RawPosPrev1;
extern uint16 THRSTOPCLCN_u16Tps1RawPosPrev2;
extern uint16 THRSTOPCLCN_u16Tps2RawPosPrev1;
extern uint16 THRSTOPCLCN_u16Tps2RawPosPrev2;
extern uint16 Tpac_1_closed_throttle_pos_prec;
extern uint16 Tpac_1_limp_home_pos_prec;
extern uint16 Tpac_1_limp_home_pos_temp;
extern uint16 Tpac_1_max_measured_position;
extern uint16 Tpac_1_min_measured_position;
extern uint16 Tpac_2_closed_throttle_pos_prec;
extern uint16 Tpac_2_limp_home_pos_prec;
extern uint16 Tpac_2_limp_home_pos_temp;
extern uint16 Tpac_2_max_measured_position;
extern uint16 Tpac_2_min_measured_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void pap_mot_NVMSRV_vidInit(void);
void THRSTOPCLCN_vidCalc_Lih_prec(void);
void THRSTOPCLCN_vidCalcLoThrustLHNeg(void);
void THRSTOPCLCN_vidCheckLimpHome(void);
void THRSTOPCLCN_vidClosedThrusts(void);
void THRSTOPCLCN_vidEndStopDiag(void);
void THRSTOPCLCN_vidFailureCounting(void);
void THRSTOPCLCN_vidFilter(void);
void THRSTOPCLCN_vidInhibTps2LHomeMcw(void);
void THRSTOPCLCN_vidIniLrnLimpHome(void);
void THRSTOPCLCN_vidInitEndStopHiLow(void);
void THRSTOPCLCN_vidInitOutput(void);
void THRSTOPCLCN_vidLihDiag(void);
void THRSTOPCLCN_vidLimpHome(void);
void THRSTOPCLCN_vidNoFilter(void);
void THRSTOPCLCN_vidOpenThrusts(void);
void THRSTOPCLCN_vidPositionFiltering(void);
void THRSTOPCLCN_vidRefLearning(void);
void THRSTOPCLCN_vidReinitSrvDiag(void);
void THRSTOPCLCN_vidReinitThrust(void);
void THRSTOPCLCN_vidStuckThr(void);


#endif /* THRSTOPCLCN_L_H */

/*-------------------------------- end of file -------------------------------*/
