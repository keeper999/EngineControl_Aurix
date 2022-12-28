/***************************************************************************
;**
;** FILE NAME      : MISFDET_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDET_L_H
#define MISFDET_L_H

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

extern const uint8  MISFDET_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_algo_cond_ok_temp;
extern boolean Mf_bAcvCondGlobal;
extern boolean MISFDET_bAcvCondIdlePrev;
extern boolean MISFDET_bAcvCondNormPrev;
extern boolean MISFDET_bOutMinHyst;
extern boolean MISFDET_bOutMinIdleHyst;
extern boolean MISFDET_bTimeOut;
extern boolean MISFDET_bTimeOut1;
extern uint32 Misf_tiDlyLongWinAdpPrev;
extern uint8 MISFDET_u8CounternoTDCAcv;
extern uint8 MISFDET_u8CounternoTDCIdleAcv;
extern sint16 Mf_comb_algo_out_uavn0;
extern sint16 Mf_p_filt_algo_out_uavn0;
extern uint16 Mf_comb_algo_neut;
extern uint16 Mf_comb_algo_thresh;
extern uint16 Mf_duree_demi_tour_n;
extern uint16 Mf_duree_demi_tour_n_less_1;
extern uint16 Mf_duree_demi_tour_n_less_2;
extern uint16 Mf_duree_demi_tour_n_less_3;
extern uint16 Mf_p_filt_algo_neut;
extern uint16 Mf_p_filt_algo_thresh;
extern uint16 Misf_HalfRevSum;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFDET_vidAlgoConTempo(void);
void MISFDET_vidAlgoDetCalc(void);
void MISFDET_vidAlgoOutput(void);
void MISFDET_vidCalcHalfRev(void);
void MISFDET_vidCombAlgo(void);
void MISFDET_vidCombAlgoThresh(void);
void MISFDET_vidCombDet(void);
void MISFDET_vidCondGlobalStab(void);
void MISFDET_vidCondStabIdle(void);
void MISFDET_vidCondStabNormal(void);
void MISFDET_vidInitOutput(void);
void MISFDET_vidMisfDet(void);
void MISFDET_vidMisfStabCond(void);
void MISFDET_vidPfiltAlgo(void);
void MISFDET_vidPfiltAlgoThresh(void);
void MISFDET_vidPfiltDet(void);


#endif /* MISFDET_L_H */

/*-------------------------------- end of file -------------------------------*/
