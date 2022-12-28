/***************************************************************************
;**
;** FILE NAME      : KNKSHDCOR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKSHDCOR_H
#define KNKSHDCOR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNK_DEG_COR_DEC_DELAY_UACN1_COLS       ( 16 )
#define KNK_DEG_COR_DELAY_UACN1_COLS           ( 16 )
#define KNK_DEG_OBS_WIN_LENGTH_UACN1_COLS      ( 16 )

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

extern const boolean  Knk_deg_bv_chgt_inh_uacb0;
extern const boolean  Knk_deg_zc_manu_inh_uacb0;
extern const uint8  Knk_deg_cor_dec_uacn0;
extern const uint8  Knk_deg_cor_in_filt_uacn0;
extern const uint8  Knk_deg_cor_inc_uacn0;
extern const uint8  Knk_deg_cor_offset_uacn0;
extern const uint8  Knk_deg_cor_out_filt_uacn0;
extern const uint8  Knk_deg_det_count_thr_uacn0;
extern const uint8  Knk_deg_obs_win_length_uacn1[KNK_DEG_OBS_WIN_LENGTH_UACN1_COLS];
extern const uint16  Knk_deg_cor_dec_delay_uacn1[KNK_DEG_COR_DEC_DELAY_UACN1_COLS];
extern const uint16  Knk_deg_cor_delay_uacn1[KNK_DEG_COR_DELAY_UACN1_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Knk_deg_cor_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgLim_EveBDC_ShdCor(void);
void IgLim_EveCkSnOn_ShdCor(void);
void IgLim_EveRst_ShdCor(void);


#endif /* KNKSHDCOR_H */

/*-------------------------------- end of file -------------------------------*/
