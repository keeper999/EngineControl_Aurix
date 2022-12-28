/***************************************************************************
;**
;** FILE NAME      : CMDPWM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CMDPWM_H
#define CMDPWM_H

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

extern const boolean  Tpac_thr_pwm_typ_select;
extern const uint16  ECTReq_ECTReqFreq_C;
extern const uint16  Frequency_vvt_adm_cal;
extern const uint16  Frequency_vvt_echap_cal;
extern const uint16  FuPmp_frqStPropFuPmp_C;
extern const uint16  Tpac_thr_pwm_frq;

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

void CoFan_SdlMid_CmdPwmCoFan(void);
void CoFan_SdlSlow_CmdPmwECTCmd(void);
void Cstr_EveRst_CmdPwmCstr(void);
void Cstr_SdlMid_CmdPwmCstr(void);
void Ext_EveRst_CmdPwm(void);
void FuPmp_SdlFast_CmdPwmPropFuPmp(void);
void Thr_EveClcnServo_CmdPwmThrCmd(void);
void Thr_EveRst_CmdPwmThrCmd(void);
void Thr_SdlMid_CmdPwmThrCmd(void);
void VlvAct_SdlFast_CmdPwmVlvActEx(void);
void VlvAct_SdlFast_CmdPwmVlvActIn(void);


#endif /* CMDPWM_H */

/*-------------------------------- end of file -------------------------------*/
