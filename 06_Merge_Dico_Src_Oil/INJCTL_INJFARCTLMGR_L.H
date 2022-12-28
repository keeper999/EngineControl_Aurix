/***************************************************************************
;**
;** FILE NAME      : INJCTL_INJFARCTLMGR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJCTL_INJFARCTLMGR_L_H
#define INJCTL_INJFARCTLMGR_L_H

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

extern const uint8  INJCTL_INJFARCTLMGR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean InjCtl_bAcvLbCll;
extern uint8 Lambda_enable_temp_thresh;
extern uint8 Lbda_fdbk_enable_adapt_count;
extern uint16 Initial_fco_count;
extern uint16 InjCtl_ctLbDiRMixtSenO2Calc;
extern uint16 Lambda_disable_counter;
extern uint16 Lambda_disable_knk_counter;
extern uint16 Lambda_disable_stt_counter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJCTL_INJFARCTLMGR_vidDecDelay(void);
void INJCTL_INJFARCTLMGR_vidDiagCata(void);
void INJCTL_INJFARCTLMGR_vidFdRegCnd(void);
void INJCTL_INJFARCTLMGR_vidFdRichCnd(void);
void INJCTL_INJFARCTLMGR_vidFSM(void);
void INJCTL_INJFARCTLMGR_vidGlobalCnd(void);
void INJCTL_INJFARCTLMGR_vidInit(void);
void INJCTL_INJFARCTLMGR_vidInitDelay(void);
void INJCTL_INJFARCTLMGR_vidInitFdbk(void);
void INJCTL_INJFARCTLMGR_vidMontrCond(void);
void INJCTL_INJFARCTLMGR_vidResetCond(void);
void INJCTL_INJFARCTLMGR_vidSetThresh(void);


#endif /* INJCTL_INJFARCTLMGR_L_H */

/*-------------------------------- end of file -------------------------------*/
