/***************************************************************************
;**
;** FILE NAME      : THRMCUT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRMCUT_L_H
#define THRMCUT_L_H

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

extern const uint8  THRMCUT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean THRMCUT_bMcutDetectflag;
extern boolean THRMCUT_bMcutDetectflagTimeOut;
extern boolean Tps_1_overlap_demand_Prev;
extern boolean Tps_2_overlap_demand_Prev;
extern boolean Tps_ratio_meas_position_enab;
extern boolean Tps_ratio_meas_position_enab_prev;
extern uint32 THRMCUT_u32RatioMeasPosFiltMem;
extern uint16 THRMCUT_u16FiltredPosition;
extern uint16 THRMCUT_u16McutDetectflagTimer;
extern uint16 Tps_1_diff_ratio_meas_overlap;
extern uint16 Tps_1_ratio_meas_pos_overlap;
extern uint16 Tps_1_ratio_meas_pos_prec_0;
extern uint16 Tps_1_ratio_meas_pos_prec_1;
extern uint16 Tps_1_ratio_meas_pos_prec_2;
extern uint16 Tps_1_ratio_meas_pos_prec_3;
extern uint16 Tps_1_switch_step;
extern uint16 Tps_2_diff_ratio_meas_overlap;
extern uint16 Tps_2_ratio_meas_pos_overlap;
extern uint16 Tps_2_ratio_meas_pos_prec_0;
extern uint16 Tps_2_ratio_meas_pos_prec_1;
extern uint16 Tps_2_ratio_meas_pos_prec_2;
extern uint16 Tps_2_ratio_meas_pos_prec_3;
extern uint16 Tps_2_switch_step;
extern sint32 THRMCUT_s32FilterPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRMCUT_vidDetection(void);
void THRMCUT_vidInit(void);
void THRMCUT_vidManager(void);
void THRMCUT_vidMicroCutBmpFuncInhib(void);
void THRMCUT_vidPiste1Mng(void);
void THRMCUT_vidPiste2Mng(void);
void THRMCUT_vidSwitchManagementPiste1(void);
void THRMCUT_vidSwitchManagementPiste2(void);
void THRMCUT_vidThrSpLrnDeac(void);
void THRMCUT_vidThrSpLrnDeacEna(void);
void THRMCUT_vidTpsRatioMeasPosEnab(void);


#endif /* THRMCUT_L_H */

/*-------------------------------- end of file -------------------------------*/
