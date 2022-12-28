/***************************************************************************
;**
;** FILE NAME      : KNKNOISEADP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKNOISEADP_L_H
#define KNKNOISEADP_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNK_NOI_AD_H_HIT_UAVB1_COLS            ( 4 )
#define KNK_NOI_AD_HIGH_UAVB1_COLS             ( 4 )
#define KNK_NOI_AD_L_HIT_UAVB1_COLS            ( 4 )
#define KNK_NOI_AD_LOW_UAVB1_COLS              ( 4 )

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

extern const uint8  KNKNOISEADP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Knk_noi_ad_cdn_ok_uavb0;
extern boolean Knk_noi_ad_h_hit_uavb1[KNK_NOI_AD_H_HIT_UAVB1_COLS];
extern boolean Knk_noi_ad_high_uavb1[KNK_NOI_AD_HIGH_UAVB1_COLS];
extern boolean Knk_noi_ad_l_hit_uavb1[KNK_NOI_AD_L_HIT_UAVB1_COLS];
extern boolean Knk_noi_ad_low_uavb1[KNK_NOI_AD_LOW_UAVB1_COLS];
extern boolean KNKNOISEADP_bInitTimerPrev;
extern boolean KnkTreat_bDgoHHit_NoiseAdp;
extern boolean KnkTreat_bDgoHSld_NoiseAdp;
extern boolean KnkTreat_bDgoLHit_NoiseAdp;
extern boolean KnkTreat_bDgoLSld_NoiseAdp;
extern boolean KnkTreat_bMonRun_NoiseAdp;
extern uint16 Knk_noi_ad_diag_tempo_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKNOISEADP_vidActivationCond(void);
void KNKNOISEADP_vidAdaptation(void);
void KNKNOISEADP_vidComputeAdapt(void);
void KNKNOISEADP_vidDiagnostic(void);
void KNKNOISEADP_vidDiagResult(void);
void KNKNOISEADP_vidDiagTimer(void);
void KNKNOISEADP_vidInitialization(void);
void KNKNOISEADP_vidInitOutput(void);


#endif /* KNKNOISEADP_L_H */

/*-------------------------------- end of file -------------------------------*/
