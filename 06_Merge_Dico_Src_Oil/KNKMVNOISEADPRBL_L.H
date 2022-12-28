/***************************************************************************
;**
;** FILE NAME      : KNKMVNOISEADPRBL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKMVNOISEADPRBL_L_H
#define KNKMVNOISEADPRBL_L_H

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

extern const uint8  KnkMvNoiseAdpRbl_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Knk_rbl_noi_ad_cdn_ok_uavb0;
extern boolean Knk_rbl_noi_ad_h_hit_uavb0;
extern boolean Knk_rbl_noi_ad_l_hit_uavb0;
extern uint16 Knk_rbl_noi_ad_gain_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkMvNoiseAdpRbl_vidActivation_condition(void);
void KnkMvNoiseAdpRbl_vidAdaptation(void);
void KnkMvNoiseAdpRbl_vidCylindre_noi_ad_gain(void);
void KnkMvNoiseAdpRbl_vidEnable_Adaptation(void);
void KnkMvNoiseAdpRbl_vidInit_adaptation_knk(void);


#endif /* KNKMVNOISEADPRBL_L_H */

/*-------------------------------- end of file -------------------------------*/
