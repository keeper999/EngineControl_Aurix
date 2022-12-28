/***************************************************************************
;**
;** FILE NAME      : PWRRLYCMDDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PWRRLYCMDDIAG_L_H
#define PWRRLYCMDDIAG_L_H

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

extern const uint8  PWRRLYCMDDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean PwrRlyHw_bDgoDef;
extern boolean PwrRlyHw_bDgoOc_PwrRly;
extern boolean PwrRlyHw_bDgoScg_PwrRly;
extern boolean PwrRlyHw_bDgoScp_PwrRly;
extern boolean PwrRlyHw_bDgoStuck_PwrRly;
extern boolean PwrRlyHw_bMonRunOc_PwrRly;
extern boolean PwrRlyHw_bMonRunScg_PwrRly;
extern boolean PwrRlyHw_bMonRunScp_PwrRly;
extern boolean PwrRlyHw_bMonRunStuck_PwrRly;
extern uint16 Diag_relais_bsm_wait_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PWRRLYCMDDIAG_ActExternalDiag(void);
void PWRRLYCMDDIAG_InitCountRelay(void);
void PWRRLYCMDDIAG_vidCmd(void);
void PWRRLYCMDDIAG_vidDiagAct(void);
void PWRRLYCMDDIAG_vidDiagExt(void);
void PWRRLYCMDDIAG_vidElDiagAcv(void);
void PWRRLYCMDDIAG_vidElDiagInh(void);
void PWRRLYCMDDIAG_vidInitOutput(void);


#endif /* PWRRLYCMDDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
