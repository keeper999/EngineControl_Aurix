/***************************************************************************
;**
;** FILE NAME      : OILPRESACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILPRESACQ_H
#define OILPRESACQ_H

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

extern const boolean  Hal_dio_inverse_signal_oil_pres;
extern const boolean  Oil_pres_alertTyp_C;
extern const uint8  Ext_noOilPresHiThd_C;
extern const uint8  Ext_noOilPresLoThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bOilPresDetec;
extern boolean Ext_bRawOilPresDetec;
extern boolean Oil_pres_alertDetec;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Oil_EveRst_OilPresAcq(void);
void Oil_SdlMid_OilPresAcq(void);


#endif /* OILPRESACQ_H */

/*-------------------------------- end of file -------------------------------*/
