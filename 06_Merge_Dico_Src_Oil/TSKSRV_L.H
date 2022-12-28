/***************************************************************************
;**
;** FILE NAME      : TSKSRV_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TSKSRV_L_H
#define TSKSRV_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TSKSRV_E.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TSKSRV_ABACTIVATIONREQUEST_LNS        ( 30 )
#define TSKSRV_AUDTOSTASKS_LNS                ( 30 )
#define TSKSRV_u8NUMBER_OF_TASKS          30
#define TSKSRV_u8TASK_CAMHAL_EXCAM_EDGE_EVENT  13
#define TSKSRV_u8TASK_CAMHAL_EXCAM_PERIOD_EVENT  14
#define TSKSRV_u8TASK_CAMHAL_FIRST_SYNC_EVENT  20
#define TSKSRV_u8TASK_CAMHAL_INCAM_EDGE_EVENT  15
#define TSKSRV_u8TASK_CAMHAL_INCAM_PERIOD_EVENT  16
#define TSKSRV_u8TASK_CAMHAL_RUN_TO_STALL_EVENT  12
#define TSKSRV_u8TASK_CAMHAL_SIGNAL_DETECTION_EVENT  2
#define TSKSRV_u8TASK_CAMHAL_SIGNAL_LOSS_EVENT  3
#define TSKSRV_u8TASK_CAMHAL_STALL_TO_RUN_EVENT  11
#define TSKSRV_u8TASK_CAMHAL_SYNC_CONTROL_EVENT  19
#define TSKSRV_u8TASK_CAMHAL_SYNC_LOSS_EVENT  27
#define TSKSRV_u8TASK_CRKHAL_CRK_OFF_EVENT  3
#define TSKSRV_u8TASK_CRKHAL_CRK_ON_EVENT  2
#define TSKSRV_u8TASK_CRKHAL_ENG_RUN_EVENT  11
#define TSKSRV_u8TASK_CRKHAL_ENG_STAL_EVENT  12
#define TSKSRV_u8TASK_CRKHAL_LTOO_EVENT   19
#define TSKSRV_u8TASK_CRKHAL_LTOO1_EVENT  20
#define TSKSRV_u8TASK_CRKHAL_N_INV_EVENT  21
#define TSKSRV_u8TASK_CRKHAL_N_INV_OFF_EVENT  22
#define TSKSRV_u8TASK_CRKHAL_TOLO_EVENT   27
#define TSKSRV_u8TASK_CRKHAL_TOOTH_EVENT  28
#define TSKSRV_u8TASK_IGNHAL_DIAG_COIL_A_C_EVENT  6
#define TSKSRV_u8TASK_IGNHAL_DIAG_COIL_A_EVENT  5
#define TSKSRV_u8TASK_IGNHAL_DIAG_COIL_B_D_EVENT  8
#define TSKSRV_u8TASK_IGNHAL_DIAG_COIL_B_EVENT  7
#define TSKSRV_u8TASK_IGNHAL_DIAG_COIL_C_EVENT  9
#define TSKSRV_u8TASK_IGNHAL_DIAG_COIL_D_EVENT  10
#define TSKSRV_u8TASK_INJ_EVENT           17
#define TSKSRV_u8TASK_KNWHAL_KNK_WIN_EVENT  18
#define TSKSRV_u8TASK_OSTSK_S_1_4_TDC     29
#define TSKSRV_u8TASK_OSTSK_S_BDC_1       0
#define TSKSRV_u8TASK_OSTSK_S_BDC_2       1
#define TSKSRV_u8TASK_OSTSK_S_CRK_OFF     3
#define TSKSRV_u8TASK_OSTSK_S_CRK_ON      2
#define TSKSRV_u8TASK_OSTSK_S_DEVAID_COMM_CAN  4
#define TSKSRV_u8TASK_OSTSK_S_DIAG_COIL_A  5
#define TSKSRV_u8TASK_OSTSK_S_DIAG_COIL_A_C  6
#define TSKSRV_u8TASK_OSTSK_S_DIAG_COIL_B  7
#define TSKSRV_u8TASK_OSTSK_S_DIAG_COIL_B_D  8
#define TSKSRV_u8TASK_OSTSK_S_DIAG_COIL_C  9
#define TSKSRV_u8TASK_OSTSK_S_DIAG_COIL_D  10
#define TSKSRV_u8TASK_OSTSK_S_ENG_RUN     11
#define TSKSRV_u8TASK_OSTSK_S_ENG_STAL    12
#define TSKSRV_u8TASK_OSTSK_S_EX_CAM_EDGE  13
#define TSKSRV_u8TASK_OSTSK_S_EX_CAM_PERIOD  14
#define TSKSRV_u8TASK_OSTSK_S_IN_CAM_EDGE  15
#define TSKSRV_u8TASK_OSTSK_S_IN_CAM_PERIOD  16
#define TSKSRV_u8TASK_OSTSK_S_INJ_EVENT   17
#define TSKSRV_u8TASK_OSTSK_S_KNK_WIN     18
#define TSKSRV_u8TASK_OSTSK_S_LTOO        19
#define TSKSRV_u8TASK_OSTSK_S_LTOO1       20
#define TSKSRV_u8TASK_OSTSK_S_N_INV       21
#define TSKSRV_u8TASK_OSTSK_S_N_INV_OFF   22
#define TSKSRV_u8TASK_OSTSK_S_PTMHAL_EVT  23
#define TSKSRV_u8TASK_OSTSK_S_SPILL_EVENT  24
#define TSKSRV_u8TASK_OSTSK_S_TDC_1       25
#define TSKSRV_u8TASK_OSTSK_S_TDC_2       26
#define TSKSRV_u8TASK_OSTSK_S_TOLO        27
#define TSKSRV_u8TASK_OSTSK_S_TOOTH       28
#define TSKSRV_u8TASK_PMPHAL_SPILL_EVENT  24
#define TSKSRV_u8TASK_PTMHAL_EVENT        23
#define TSKSRV_u8TASK_TDCHAL_BDC_1_EVENT  0
#define TSKSRV_u8TASK_TDCHAL_BDC_2_EVENT  1
#define TSKSRV_u8TASK_TDCHAL_TDC_1_EVENT  25
#define TSKSRV_u8TASK_TDCHAL_TDC_2_EVENT  26

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



#endif /* TSKSRV_L_H */

/*-------------------------------- end of file -------------------------------*/
