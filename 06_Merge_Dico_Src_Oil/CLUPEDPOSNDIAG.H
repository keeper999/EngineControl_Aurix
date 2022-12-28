/***************************************************************************
;**
;** FILE NAME      : CLUPEDPOSNDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CLUPEDPOSNDIAG_H
#define CLUPEDPOSNDIAG_H

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

extern const boolean  StaCtl_bMonRunFctCluP_SC;
extern const uint8  StaCtl_noDecDiagCluP_C;
extern const uint8  StaCtl_noHiThdDiagCluP_C;
extern const uint8  StaCtl_noIncDrvCycDiagCluP_C;
extern const uint8  StaCtl_noIncMainDiagCluP_C;
extern const uint8  StaCtl_noLoThdDiagCluP_C;
extern const uint8  StaCtl_noMaxDiagCluP_C;
extern const uint8  StaCtl_tDeltaCoMes_C;
extern const uint8  StaCtl_tiSdlDiagCluP_SC;
extern const sint16  StaCtl_tCoMesDiagCluP_C;
extern const uint16  StaCtl_nEngDiagCluP_C;
extern const uint16  StaCtl_rCluPThdCalHi_C;
extern const uint16  StaCtl_rCluPThdCalLo_C;
extern const uint16  StaCtl_rCluPThdChg_C;
extern const uint16  StaCtl_spdVehDiagCluP_C;
extern const uint16  StaCtl_tiDlyNotGc_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean StaCtl_bDgoFctCluP;
extern boolean StaCtl_bMonRunFctCluP;
extern uint8 StaCtl_ctDiagCluP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CLUPEDPOSNDIAG_vidEntry_100ms(void);
void CLUPEDPOSNDIAG_vidEntryInit(void);


#endif /* CLUPEDPOSNDIAG_H */

/*-------------------------------- end of file -------------------------------*/
