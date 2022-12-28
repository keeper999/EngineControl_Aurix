/***************************************************************************
;**
;** FILE NAME      : TECUACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TECUACQ_H
#define TECUACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SENACT_TECUACQ_UTECUMES_A_COLS         ( 33 )
#define SENACT_UTECU_T_COLS                    ( 33 )

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

extern const uint8  SenAct_tECUIni_C;
extern const uint8  SenAct_utECU_T[SENACT_UTECU_T_COLS];
extern const uint16  SenAct_tECUAcq_utECUMes_A[SENACT_TECUACQ_UTECUMES_A_COLS];
extern const uint16  SenAct_uDgoScg_tECUAcq_C;
extern const uint16  SenAct_uDgoScp_tECUAcq_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 SenAct_tECUAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SenAct_EveCrTR_tECUAcq(void);
void SenAct_EveRst_tECUAcq(void);
void SenAct_EveRTSt_tECUAcq(void);
void SenAct_SdlMid_tECUAcq(void);


#endif /* TECUACQ_H */

/*-------------------------------- end of file -------------------------------*/
