/***************************************************************************
;**
;** FILE NAME      : MISFDETCFM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDETCFM_H
#define MISFDETCFM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_P_FILT_DEC_NEUT_MAP_UACN2_LNS      ( 7 )
#define MF_P_FILT_DEC_NEUT_MAP_UACN2_COLS      ( 16 )
#define MF_P_FILT_DECISION_MAP_UACN2_LNS      ( 7 )
#define MF_P_FILT_DECISION_MAP_UACN2_COLS      ( 16 )

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

extern const uint8  Mf_p_filt_dec_neut_map_uacn2[MF_P_FILT_DEC_NEUT_MAP_UACN2_LNS][MF_P_FILT_DEC_NEUT_MAP_UACN2_COLS];
extern const uint8  Mf_p_filt_decision_map_uacn2[MF_P_FILT_DECISION_MAP_UACN2_LNS][MF_P_FILT_DECISION_MAP_UACN2_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_misfire_detected_uavb0;
extern uint8 Mf_det_single_output_uavn0;
extern sint16 Mf_comb_wght_uavn0;
extern sint16 Mf_p_filt_wght_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfDetCfm(void);
void MISFMISFDETCFM_vidEntryInit(void);


#endif /* MISFDETCFM_H */

/*-------------------------------- end of file -------------------------------*/
