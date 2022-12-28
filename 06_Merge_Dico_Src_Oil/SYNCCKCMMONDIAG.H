/***************************************************************************
;**
;** FILE NAME      : SYNCCKCMMONDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCCKCMMONDIAG_H
#define SYNCCKCMMONDIAG_H

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

extern const boolean  Acq_crk_no_sgnl_diag_ena_upcb0;
extern const boolean  Acq_excam_no_sgnl_diag_ena_upcb0;
extern const boolean  Acq_incam_no_sgnl_diag_ena_upcb0;
extern const uint8  Acq_excam_count_evnt_upcn0;
extern const uint8  Acq_incam_count_evnt_upcn0;
extern const uint8  Sync_CfmTimeStallEng;

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

void Sync_EveInCmToo_CmCkMon(void);
void Sync_EveKOn_CmCkMon(void);
void Sync_EveRst_CmCkMon(void);
void Sync_SdlSlow_CmCkMon(void);


#endif /* SYNCCKCMMONDIAG_H */

/*-------------------------------- end of file -------------------------------*/
