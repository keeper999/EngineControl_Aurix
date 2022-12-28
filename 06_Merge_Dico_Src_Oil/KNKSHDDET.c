/***************************************************************************
;**
;** FILE NAME      : KNKSHDDET.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKSHDDET.H"
#include "KNKSHDDET_L.H"
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
const boolean  Knk_deg_det_cur_manu_inh_uacb0 = 0;
const boolean  Knk_deg_manu_inh_uacb0 = 0;
const uint8  Knk_deg_det_seuil_temp_eau_uacn0 = 0;
const uint8  KNKSHDDET_u8Inhib = 0;
const uint16  Knk_deg_det_load_bkpt_uacn1[KNK_DEG_DET_LOAD_BKPT_UACN1_COLS] = {0};
const uint16  Knk_deg_det_n_bkpt_uacn1[KNK_DEG_DET_N_BKPT_UACN1_COLS] = {0};
const uint16  Knk_deg_det_thr_cyl1_uacn2[KNK_DEG_DET_THR_CYL1_UACN2_LNS][KNK_DEG_DET_THR_CYL1_UACN2_COLS] = {0};
const uint16  Knk_deg_det_thr_cyl2_uacn2[KNK_DEG_DET_THR_CYL2_UACN2_LNS][KNK_DEG_DET_THR_CYL2_UACN2_COLS] = {0};
const uint16  Knk_deg_det_thr_cyl3_uacn2[KNK_DEG_DET_THR_CYL3_UACN2_LNS][KNK_DEG_DET_THR_CYL3_UACN2_COLS] = {0};
const uint16  Knk_deg_det_thr_cyl4_uacn2[KNK_DEG_DET_THR_CYL4_UACN2_LNS][KNK_DEG_DET_THR_CYL4_UACN2_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Knk_deg_det_cur_uavb1[KNK_DEG_DET_CUR_UAVB1_COLS];
boolean Knk_deg_det_uavb1[KNK_DEG_DET_UAVB1_COLS];
boolean Knk_deg_manu_inh_Acv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

