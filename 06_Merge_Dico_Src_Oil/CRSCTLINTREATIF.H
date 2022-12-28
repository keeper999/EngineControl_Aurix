/***************************************************************************
;**
;** FILE NAME      : CRSCTLINTREATIF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CRSCTLINTREATIF_H
#define CRSCTLINTREATIF_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CrsCtl_SampleTiFast_SC            10

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

extern const uint8  Ext_SpdVehBVVMax_C;
extern const uint8  Ext_SpdVehBVVMin_C;
extern const uint16  CrsCtl_tempo_init_diag_xVV_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bClu;
extern uint8 Ext_noGearEgd;
extern uint16 Ext_nAvrFrntWhl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CrsCtl_EveRst_CrsCtlInTreatIf(void);
void CrsCtl_SdlFast_CrsCtlInTreatIf(void);
void CrsCtl_SdlSlow_CrsCtlInTreatIf(void);


#endif /* CRSCTLINTREATIF_H */

/*-------------------------------- end of file -------------------------------*/
