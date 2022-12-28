/***************************************************************************
;**
;** FILE NAME      : KNKSHDCOR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKSHDCOR_L_H
#define KNKSHDCOR_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNK_DEG_DET_COUNT_UAVN1_COLS           ( 4 )
#define KNK_DEG_OBS_WIN_UAVN1_COLS             ( 4 )

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

extern const uint8  KNKSHDCOR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean knk_corr_inc_uavb0;
extern uint8 Knk_deg_app_count_eep;
extern uint8 Knk_deg_cor_av_filt_uavn0;
extern uint8 Knk_deg_det_count_uavn1[KNK_DEG_DET_COUNT_UAVN1_COLS];
extern uint8 Knk_deg_obs_win_uavn1[KNK_DEG_OBS_WIN_UAVN1_COLS];
extern uint16 Knk_deg_cor_tempo_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKSHDCOR_vidComp_corr_dec(void);
void KNKSHDCOR_vidCorr_calculate(void);
void KNKSHDCOR_vidCorr_dec(void);
void KNKSHDCOR_vidCorr_enable(void);
void KNKSHDCOR_vidCorr_inc(void);
void KNKSHDCOR_vidCorr_init(void);
void KNKSHDCOR_vidCorr_manage(void);
void KNKSHDCOR_vidCorr_manager(void);
void KNKSHDCOR_vidCorrect_palliative(void);
void KNKSHDCOR_vidDec_win(void);
void KNKSHDCOR_vidInit(void);
void KNKSHDCOR_vidInit_win(void);
void KNKSHDCOR_vidKnk_count(void);
void KNKSHDCOR_vidKnk_inc_stop(void);
void KNKSHDCOR_vidraz_corr(void);
void KNKSHDCOR_vidReset_win(void);
void KNKSHDCOR_vidWin_manage(void);


#endif /* KNKSHDCOR_L_H */

/*-------------------------------- end of file -------------------------------*/
