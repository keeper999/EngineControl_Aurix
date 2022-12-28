/***************************************************************************
;**
;** FILE NAME      : KNKDET_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKDET_L_H
#define KNKDET_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define FACTEUR_FILTRAGE_CLIQUETIS_COLS        ( 4 )
#define KNK_DET_DYN_FILT_COUNTER_COLS          ( 4 )
#define KNK_DET_FORT_KNK_THRSH_GAIN_COLS       ( 4 )
#define KNK_DET_RIS_KNK_THRSH_GAIN_COLS        ( 4 )
#define KNK_DET_THRESH_CYL_COLS                ( 4 )
#define KNKDET_u32ARRAY_LENGTH            4

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

extern const uint8  KNKDET_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean active_conditions_clq;
extern boolean active_conditions_clq_14;
extern boolean active_conditions_clq_23;
extern boolean Knk_eal_dyn_filt_det_uavb0;
extern boolean Knk_n_dyn_filt_det_uavb0;
extern uint8 Facteur_filtrage_cliquetis[FACTEUR_FILTRAGE_CLIQUETIS_COLS];
extern uint8 Knk_det_dyn_filt_counter[KNK_DET_DYN_FILT_COUNTER_COLS];
extern uint8 Knk_det_ris_knk_thrsh_gain[KNK_DET_RIS_KNK_THRSH_GAIN_COLS];
extern uint16 Ext_rTotLd_cliq_prev;
extern uint16 Knk_det_fort_knk_thrsh_gain[KNK_DET_FORT_KNK_THRSH_GAIN_COLS];
extern uint16 Knk_det_thresh_cyl[KNK_DET_THRESH_CYL_COLS];
extern uint16 KNKDET_u16InhDetKnkAfterCounter;
extern uint16 Regime_moteur_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKDET_vidAverageNoiseCalc(void);
void KNKDET_vidAverageNoiseReset(void);
void KNKDET_vidCy14Detection(void);
void KNKDET_vidCy23Detection(void);
void KNKDET_vidCyclDetection(void);
void KNKDET_vidCylAverageNoiseCalc(void);
void KNKDET_vidCylTreatment(void);
void KNKDET_vidCylUncertainTreatment(void);
void KNKDET_vidDecrDynFilterCounter(void);
void KNKDET_vidFactorFilterCalcFinal(void);
void KNKDET_vidFactorFilterCalcFreq(void);
void KNKDET_vidFactorFilterCalcLoad(void);
void KNKDET_vidFactorFilterCalcN(void);
void KNKDET_vidInhibitionCorrection(void);
void KNKDET_vidInitDynFilterCounter(void);
void KNKDET_vidInitOutput(void);
void KNKDET_vidInitStrategy(void);
void KNKDET_vidPairCylTreatment(void);
void KNKDET_vidReset(void);


#endif /* KNKDET_L_H */

/*-------------------------------- end of file -------------------------------*/
