/***************************************************************************
;**
;** FILE NAME      : ACQDGOHAL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQDGOHAL_H
#define ACQDGOHAL_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean Dena_scg_cmdautoredemst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CoFan_SdlMid_CmdDiagGMV1GMV2(void);
void CoFan_SdlSlow_CmdDiagECTReq(void);
void Cstr_SdlFast_CmdDiagCstr(void);
void EngSt_SdlFast_CmdDiagAuthStrtSTT(void);
void EngSt_SdlFast_CmdDiagEngStOutIdc(void);
void EngSt_SdlMid_CmdDiagStrtr(void);
void Ext_EveRst_OutPutCmdDiag(void);
void FuPmp_SdlFast_CmdDiagPropFuPmp(void);
void HeatSenO2_SdlFast_CmdDiagDrvO2Ds(void);
void HeatSenO2_SdlFast_CmdDiagDrvO2Us(void);
void Oil_SdlSlow_CmdDiagBlowBy1(void);
void Oil_SdlSlow_CmdDiagBlowBy2(void);
void Pwr_SdlMid_CmdDiagDmtr(void);
void Rly_SdlFast_CmdDiagRly(void);
void Thr_EveClcnServo_CmdDiagThrCmd(void);
void VlvAct_SdlFast_CmdDiagVlvActEx(void);
void VlvAct_SdlFast_CmdDiagVlvActIn(void);


#endif /* ACQDGOHAL_H */

/*-------------------------------- end of file -------------------------------*/
