/***************************************************************************
;**
;** FILE NAME      : MISFDFTLRNOUT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDFTLRNOUT_L_H
#define MISFDFTLRNOUT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_ADAP_LW_CORR_COUNT_MIN_COLS         ( 9 )
#define MF_ADAP_SHRT_CORR_COUNT_MIN_COLS       ( 9 )

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

extern const uint8  MISFDFTLRNOUT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Mf_adap_lw_corr_count_min[MF_ADAP_LW_CORR_COUNT_MIN_COLS];
extern uint8 Mf_adap_shrt_corr_count_min[MF_ADAP_SHRT_CORR_COUNT_MIN_COLS];
extern uint16 Mfw_adapt_current_zone_level_res;
extern uint16 Mfw_adapt_zones_ratio_res;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFDFTLRNOUT_vidInitOutput(void);
void MISFDFTLRNOUT_vidMfwAdaptCntMin(void);
void MISFDFTLRNOUT_vidMfwAdaptCZonLev(void);
void MISFDFTLRNOUT_vidMfwAdaptZRatio(void);


#endif /* MISFDFTLRNOUT_L_H */

/*-------------------------------- end of file -------------------------------*/
