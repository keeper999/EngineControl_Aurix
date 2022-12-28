/***************************************************************************
;**
;** FILE NAME      : KNKSHDDET.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKSHDDET_H
#define KNKSHDDET_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNK_DEG_DET_CUR_UAVB1_COLS             ( 4 )
#define KNK_DEG_DET_LOAD_BKPT_UACN1_COLS       ( 12 )
#define KNK_DEG_DET_N_BKPT_UACN1_COLS          ( 9 )
#define KNK_DEG_DET_THR_CYL1_UACN2_LNS        ( 12 )
#define KNK_DEG_DET_THR_CYL1_UACN2_COLS        ( 9 )
#define KNK_DEG_DET_THR_CYL2_UACN2_LNS        ( 12 )
#define KNK_DEG_DET_THR_CYL2_UACN2_COLS        ( 9 )
#define KNK_DEG_DET_THR_CYL3_UACN2_LNS        ( 12 )
#define KNK_DEG_DET_THR_CYL3_UACN2_COLS        ( 9 )
#define KNK_DEG_DET_THR_CYL4_UACN2_LNS        ( 12 )
#define KNK_DEG_DET_THR_CYL4_UACN2_COLS        ( 9 )
#define KNK_DEG_DET_UAVB1_COLS                 ( 4 )

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

extern const boolean  Knk_deg_det_cur_manu_inh_uacb0;
extern const boolean  Knk_deg_manu_inh_uacb0;
extern const uint8  Knk_deg_det_seuil_temp_eau_uacn0;
extern const uint16  Knk_deg_det_load_bkpt_uacn1[KNK_DEG_DET_LOAD_BKPT_UACN1_COLS];
extern const uint16  Knk_deg_det_n_bkpt_uacn1[KNK_DEG_DET_N_BKPT_UACN1_COLS];
extern const uint16  Knk_deg_det_thr_cyl1_uacn2[KNK_DEG_DET_THR_CYL1_UACN2_LNS][KNK_DEG_DET_THR_CYL1_UACN2_COLS];
extern const uint16  Knk_deg_det_thr_cyl2_uacn2[KNK_DEG_DET_THR_CYL2_UACN2_LNS][KNK_DEG_DET_THR_CYL2_UACN2_COLS];
extern const uint16  Knk_deg_det_thr_cyl3_uacn2[KNK_DEG_DET_THR_CYL3_UACN2_LNS][KNK_DEG_DET_THR_CYL3_UACN2_COLS];
extern const uint16  Knk_deg_det_thr_cyl4_uacn2[KNK_DEG_DET_THR_CYL4_UACN2_LNS][KNK_DEG_DET_THR_CYL4_UACN2_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Knk_deg_det_cur_uavb1[KNK_DEG_DET_CUR_UAVB1_COLS];
extern boolean Knk_deg_det_uavb1[KNK_DEG_DET_UAVB1_COLS];
extern boolean Knk_deg_manu_inh_Acv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveCkSnOn_ShdDet(void);
void KnkTreat_EveKnk_ShdDet(void);
void KnkTreat_EveRst_ShdDet(void);


#endif /* KNKSHDDET_H */

/*-------------------------------- end of file -------------------------------*/
