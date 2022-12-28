/***************************************************************************
;**
;** FILE NAME      : ACCPFRM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPFRM_H
#define ACCPFRM_H

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

extern const boolean  Accp_bAcvModPedalWotRequest;
extern const boolean  Accp_bInhModPosnPedRel;
extern const boolean  Aps_mux_pl_securise_manu_inh;
extern const boolean  Ssm_mux_dv_pos_pedal_ff_manu_inh;
extern const uint8  Dv_detect_pl_high_thresh_mux;
extern const uint8  Dv_detect_pl_low_thresh_mux;
extern const uint16  AccP_rAccPPHdPt_C;
extern const uint16  Aps_detect_pl_mux_coh_tolerance;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 AccP_rDrvReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AccP_SdlFast_Ftm(void);
void ACCPFRM_vidEntryInit(void);


#endif /* ACCPFRM_H */

/*-------------------------------- end of file -------------------------------*/
