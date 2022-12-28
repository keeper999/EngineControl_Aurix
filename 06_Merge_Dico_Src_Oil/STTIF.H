/***************************************************************************
;**
;** FILE NAME      : STTIF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef STTIF_H
#define STTIF_H

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

extern const uint8  CoReqRstrt_Desactivation_C;
extern const uint8  CoReqRstrt_DesactivationHyst_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Ext_nEngToothClc;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void InjCutOff_EveInj_CutOffIf(void);
void InjCutOff_EveRst_CutOffIf(void);
void InjCutOff_SdlFast_CutOffIf(void);
void Sync_EveBDC_CkMngIfIf_2(void);
void Sync_EveCkSnOn_CkMngIfIf_2(void);
void Sync_EveRst_CkMngIfIf_2(void);
void Sync_EveRTSt_CkMngIfIf_2(void);
void Sync_EveTDC_CkMngIfIf_2(void);


#endif /* STTIF_H */

/*-------------------------------- end of file -------------------------------*/
