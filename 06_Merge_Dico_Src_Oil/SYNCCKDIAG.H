/***************************************************************************
;**
;** FILE NAME      : SYNCCKDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCCKDIAG_H
#define SYNCCKDIAG_H

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

extern const boolean  Acq_crk_no_gap_diag_ena_upcb0;
extern const boolean  Acq_crk_tooth_h_diag_ena_upcb0;
extern const boolean  Acq_crk_tooth_l_diag_ena_upcb0;
extern const boolean  Sync_bAcvBackUpCk_C;
extern const boolean  Sync_bAcvBchModCk_C;

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

void Sync_EveCkLTo_CkDiagSts(void);
void Sync_EveCkOf_CkDiagSts(void);
void Sync_EveCkSnOf_CkDiagSts(void);
void Sync_EveCkSnOn_CkDiagSts(void);
void Sync_EveCrTSt_CkDiagSts(void);
void Sync_EveKOn_CkDiagSts(void);
void Sync_EveRst_CkDiagSts(void);
void Sync_EveRTCr_CkDiagSts(void);
void Sync_EveStTCr_CkDiagSts(void);
void Sync_EveStTR_CkDiagSts(void);
void Sync_SdlFast_CkDiagSts(void);
void Sync_SdlMid_CkDiagSts(void);
void Sync_SdlSlow_CkDiagSts(void);


#endif /* SYNCCKDIAG_H */

/*-------------------------------- end of file -------------------------------*/
