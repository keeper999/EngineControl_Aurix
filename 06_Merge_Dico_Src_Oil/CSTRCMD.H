/***************************************************************************
;**
;** FILE NAME      : CSTRCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRCMD_H
#define CSTRCMD_H

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

extern const boolean  Ext_bAcv_Cnstr_rCtlBattCor_C;
extern const uint8  Cstr_CtlCstrReq_DrvMax_C;
extern const uint8  Cstr_CtlCstrReq_DrvMin_C;
extern const uint8  rco_second_frequency_max;
extern const uint8  rco_second_frequency_max_hys;
extern const uint8  rco_second_frequency_min;
extern const uint8  rco_second_frequency_min_hys;
extern const uint16  Bsi_pwm_frequency_hi_cpc;
extern const uint16  Bsi_pwm_frequency_lo_cpc;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cstr_EveRst_CstrCmd(void);
void Cstr_SdlFast_CstrCmd(void);
void Cstr_SdlMid_CstrCmd(void);


#endif /* CSTRCMD_H */

/*-------------------------------- end of file -------------------------------*/
